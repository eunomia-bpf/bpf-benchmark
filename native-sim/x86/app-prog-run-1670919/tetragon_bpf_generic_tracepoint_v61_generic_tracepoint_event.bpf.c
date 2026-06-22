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

static __noinline __u64 tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_event_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 24ULL: goto x86_l_18;
	case 29ULL: goto x86_l_1d;
	case 36ULL: goto x86_l_24;
	case 44ULL: goto x86_l_2c;
	case 46ULL: goto x86_l_2e;
	case 49ULL: goto x86_l_31;
	case 55ULL: goto x86_l_37;
	case 58ULL: goto x86_l_3a;
	case 63ULL: goto x86_l_3f;
	case 70ULL: goto x86_l_46;
	case 78ULL: goto x86_l_4e;
	case 80ULL: goto x86_l_50;
	case 83ULL: goto x86_l_53;
	case 89ULL: goto x86_l_59;
	case 92ULL: goto x86_l_5c;
	case 95ULL: goto x86_l_5f;
	case 99ULL: goto x86_l_63;
	case 101ULL: goto x86_l_65;
	case 107ULL: goto x86_l_6b;
	case 112ULL: goto x86_l_70;
	case 119ULL: goto x86_l_77;
	case 124ULL: goto x86_l_7c;
	case 126ULL: goto x86_l_7e;
	case 129ULL: goto x86_l_81;
	case 135ULL: goto x86_l_87;
	case 138ULL: goto x86_l_8a;
	case 149ULL: goto x86_l_95;
	case 154ULL: goto x86_l_9a;
	case 161ULL: goto x86_l_a1;
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
	case 259ULL: goto x86_l_103;
	case 265ULL: goto x86_l_109;
	case 267ULL: goto x86_l_10b;
	case 270ULL: goto x86_l_10e;
	case 272ULL: goto x86_l_110;
	case 274ULL: goto x86_l_112;
	case 279ULL: goto x86_l_117;
	case 283ULL: goto x86_l_11b;
	case 288ULL: goto x86_l_120;
	case 293ULL: goto x86_l_125;
	case 298ULL: goto x86_l_12a;
	case 300ULL: goto x86_l_12c;
	case 306ULL: goto x86_l_132;
	case 308ULL: goto x86_l_134;
	case 313ULL: goto x86_l_139;
	case 318ULL: goto x86_l_13e;
	case 323ULL: goto x86_l_143;
	case 328ULL: goto x86_l_148;
	case 330ULL: goto x86_l_14a;
	case 335ULL: goto x86_l_14f;
	case 338ULL: goto x86_l_152;
	case 344ULL: goto x86_l_158;
	case 353ULL: goto x86_l_161;
	case 360ULL: goto x86_l_168;
	case 365ULL: goto x86_l_16d;
	case 370ULL: goto x86_l_172;
	case 375ULL: goto x86_l_177;
	case 377ULL: goto x86_l_179;
	case 382ULL: goto x86_l_17e;
	case 391ULL: goto x86_l_187;
	case 394ULL: goto x86_l_18a;
	case 396ULL: goto x86_l_18c;
	case 400ULL: goto x86_l_190;
	case 405ULL: goto x86_l_195;
	case 410ULL: goto x86_l_19a;
	case 415ULL: goto x86_l_19f;
	case 417ULL: goto x86_l_1a1;
	case 422ULL: goto x86_l_1a6;
	case 427ULL: goto x86_l_1ab;
	case 430ULL: goto x86_l_1ae;
	case 432ULL: goto x86_l_1b0;
	case 437ULL: goto x86_l_1b5;
	case 439ULL: goto x86_l_1b7;
	case 444ULL: goto x86_l_1bc;
	case 447ULL: goto x86_l_1bf;
	case 453ULL: goto x86_l_1c5;
	case 458ULL: goto x86_l_1ca;
	case 463ULL: goto x86_l_1cf;
	case 470ULL: goto x86_l_1d6;
	case 475ULL: goto x86_l_1db;
	case 477ULL: goto x86_l_1dd;
	case 480ULL: goto x86_l_1e0;
	case 482ULL: goto x86_l_1e2;
	case 485ULL: goto x86_l_1e5;
	case 490ULL: goto x86_l_1ea;
	case 493ULL: goto x86_l_1ed;
	case 495ULL: goto x86_l_1ef;
	case 500ULL: goto x86_l_1f4;
	case 502ULL: goto x86_l_1f6;
	case 511ULL: goto x86_l_1ff;
	case 516ULL: goto x86_l_204;
	case 521ULL: goto x86_l_209;
	case 524ULL: goto x86_l_20c;
	case 526ULL: goto x86_l_20e;
	case 529ULL: goto x86_l_211;
	case 535ULL: goto x86_l_217;
	case 546ULL: goto x86_l_222;
	case 549ULL: goto x86_l_225;
	case 553ULL: goto x86_l_229;
	case 561ULL: goto x86_l_231;
	case 566ULL: goto x86_l_236;
	case 570ULL: goto x86_l_23a;
	case 573ULL: goto x86_l_23d;
	case 576ULL: goto x86_l_240;
	case 580ULL: goto x86_l_244;
	case 582ULL: goto x86_l_246;
	case 586ULL: goto x86_l_24a;
	case 592ULL: goto x86_l_250;
	case 596ULL: goto x86_l_254;
	case 602ULL: goto x86_l_25a;
	case 606ULL: goto x86_l_25e;
	case 612ULL: goto x86_l_264;
	case 616ULL: goto x86_l_268;
	case 622ULL: goto x86_l_26e;
	case 626ULL: goto x86_l_272;
	case 632ULL: goto x86_l_278;
	case 637ULL: goto x86_l_27d;
	case 641ULL: goto x86_l_281;
	case 647ULL: goto x86_l_287;
	case 651ULL: goto x86_l_28b;
	case 657ULL: goto x86_l_291;
	case 661ULL: goto x86_l_295;
	case 667ULL: goto x86_l_29b;
	case 671ULL: goto x86_l_29f;
	case 677ULL: goto x86_l_2a5;
	case 681ULL: goto x86_l_2a9;
	case 687ULL: goto x86_l_2af;
	case 692ULL: goto x86_l_2b4;
	case 697ULL: goto x86_l_2b9;
	case 702ULL: goto x86_l_2be;
	case 704ULL: goto x86_l_2c0;
	case 707ULL: goto x86_l_2c3;
	case 713ULL: goto x86_l_2c9;
	case 715ULL: goto x86_l_2cb;
	case 720ULL: goto x86_l_2d0;
	case 727ULL: goto x86_l_2d7;
	case 737ULL: goto x86_l_2e1;
	case 742ULL: goto x86_l_2e6;
	case 747ULL: goto x86_l_2eb;
	case 754ULL: goto x86_l_2f2;
	case 759ULL: goto x86_l_2f7;
	case 761ULL: goto x86_l_2f9;
	case 764ULL: goto x86_l_2fc;
	case 770ULL: goto x86_l_302;
	case 772ULL: goto x86_l_304;
	case 777ULL: goto x86_l_309;
	case 781ULL: goto x86_l_30d;
	case 787ULL: goto x86_l_313;
	case 791ULL: goto x86_l_317;
	case 794ULL: goto x86_l_31a;
	case 800ULL: goto x86_l_320;
	case 804ULL: goto x86_l_324;
	case 810ULL: goto x86_l_32a;
	case 815ULL: goto x86_l_32f;
	case 820ULL: goto x86_l_334;
	case 825ULL: goto x86_l_339;
	case 827ULL: goto x86_l_33b;
	case 830ULL: goto x86_l_33e;
	case 836ULL: goto x86_l_344;
	case 838ULL: goto x86_l_346;
	case 843ULL: goto x86_l_34b;
	case 850ULL: goto x86_l_352;
	case 860ULL: goto x86_l_35c;
	case 865ULL: goto x86_l_361;
	case 870ULL: goto x86_l_366;
	case 877ULL: goto x86_l_36d;
	case 882ULL: goto x86_l_372;
	case 884ULL: goto x86_l_374;
	case 887ULL: goto x86_l_377;
	case 893ULL: goto x86_l_37d;
	case 901ULL: goto x86_l_385;
	case 906ULL: goto x86_l_38a;
	case 911ULL: goto x86_l_38f;
	case 915ULL: goto x86_l_393;
	case 921ULL: goto x86_l_399;
	case 925ULL: goto x86_l_39d;
	case 931ULL: goto x86_l_3a3;
	case 935ULL: goto x86_l_3a7;
	case 941ULL: goto x86_l_3ad;
	case 945ULL: goto x86_l_3b1;
	case 951ULL: goto x86_l_3b7;
	case 956ULL: goto x86_l_3bc;
	case 961ULL: goto x86_l_3c1;
	case 966ULL: goto x86_l_3c6;
	case 968ULL: goto x86_l_3c8;
	case 971ULL: goto x86_l_3cb;
	case 977ULL: goto x86_l_3d1;
	case 979ULL: goto x86_l_3d3;
	case 984ULL: goto x86_l_3d8;
	case 991ULL: goto x86_l_3df;
	case 1001ULL: goto x86_l_3e9;
	case 1006ULL: goto x86_l_3ee;
	case 1011ULL: goto x86_l_3f3;
	case 1018ULL: goto x86_l_3fa;
	case 1023ULL: goto x86_l_3ff;
	case 1025ULL: goto x86_l_401;
	case 1028ULL: goto x86_l_404;
	case 1034ULL: goto x86_l_40a;
	case 1036ULL: goto x86_l_40c;
	case 1042ULL: goto x86_l_412;
	case 1047ULL: goto x86_l_417;
	case 1056ULL: goto x86_l_420;
	case 1061ULL: goto x86_l_425;
	case 1066ULL: goto x86_l_42a;
	case 1069ULL: goto x86_l_42d;
	case 1071ULL: goto x86_l_42f;
	case 1074ULL: goto x86_l_432;
	case 1080ULL: goto x86_l_438;
	case 1088ULL: goto x86_l_440;
	case 1093ULL: goto x86_l_445;
	case 1100ULL: goto x86_l_44c;
	case 1105ULL: goto x86_l_451;
	case 1107ULL: goto x86_l_453;
	case 1110ULL: goto x86_l_456;
	case 1116ULL: goto x86_l_45c;
	case 1121ULL: goto x86_l_461;
	case 1126ULL: goto x86_l_466;
	case 1129ULL: goto x86_l_469;
	case 1131ULL: goto x86_l_46b;
	case 1134ULL: goto x86_l_46e;
	case 1140ULL: goto x86_l_474;
	case 1145ULL: goto x86_l_479;
	case 1149ULL: goto x86_l_47d;
	case 1152ULL: goto x86_l_480;
	case 1158ULL: goto x86_l_486;
	case 1163ULL: goto x86_l_48b;
	case 1168ULL: goto x86_l_490;
	case 1173ULL: goto x86_l_495;
	case 1175ULL: goto x86_l_497;
	case 1178ULL: goto x86_l_49a;
	case 1184ULL: goto x86_l_4a0;
	case 1186ULL: goto x86_l_4a2;
	case 1191ULL: goto x86_l_4a7;
	case 1198ULL: goto x86_l_4ae;
	case 1208ULL: goto x86_l_4b8;
	case 1213ULL: goto x86_l_4bd;
	case 1218ULL: goto x86_l_4c2;
	case 1225ULL: goto x86_l_4c9;
	case 1230ULL: goto x86_l_4ce;
	case 1232ULL: goto x86_l_4d0;
	case 1235ULL: goto x86_l_4d3;
	case 1241ULL: goto x86_l_4d9;
	case 1243ULL: goto x86_l_4db;
	case 1248ULL: goto x86_l_4e0;
	case 1252ULL: goto x86_l_4e4;
	case 1258ULL: goto x86_l_4ea;
	case 1262ULL: goto x86_l_4ee;
	case 1268ULL: goto x86_l_4f4;
	case 1272ULL: goto x86_l_4f8;
	case 1278ULL: goto x86_l_4fe;
	case 1283ULL: goto x86_l_503;
	case 1288ULL: goto x86_l_508;
	case 1293ULL: goto x86_l_50d;
	case 1295ULL: goto x86_l_50f;
	case 1298ULL: goto x86_l_512;
	case 1304ULL: goto x86_l_518;
	case 1306ULL: goto x86_l_51a;
	case 1311ULL: goto x86_l_51f;
	case 1318ULL: goto x86_l_526;
	case 1328ULL: goto x86_l_530;
	case 1333ULL: goto x86_l_535;
	case 1338ULL: goto x86_l_53a;
	case 1345ULL: goto x86_l_541;
	case 1350ULL: goto x86_l_546;
	case 1352ULL: goto x86_l_548;
	case 1355ULL: goto x86_l_54b;
	case 1361ULL: goto x86_l_551;
	case 1369ULL: goto x86_l_559;
	case 1374ULL: goto x86_l_55e;
	case 1379ULL: goto x86_l_563;
	case 1383ULL: goto x86_l_567;
	case 1389ULL: goto x86_l_56d;
	case 1393ULL: goto x86_l_571;
	case 1395ULL: goto x86_l_573;
	case 1400ULL: goto x86_l_578;
	case 1404ULL: goto x86_l_57c;
	case 1406ULL: goto x86_l_57e;
	case 1410ULL: goto x86_l_582;
	case 1416ULL: goto x86_l_588;
	case 1421ULL: goto x86_l_58d;
	case 1426ULL: goto x86_l_592;
	case 1431ULL: goto x86_l_597;
	case 1433ULL: goto x86_l_599;
	case 1436ULL: goto x86_l_59c;
	case 1442ULL: goto x86_l_5a2;
	case 1444ULL: goto x86_l_5a4;
	case 1449ULL: goto x86_l_5a9;
	case 1456ULL: goto x86_l_5b0;
	case 1466ULL: goto x86_l_5ba;
	case 1471ULL: goto x86_l_5bf;
	case 1476ULL: goto x86_l_5c4;
	case 1483ULL: goto x86_l_5cb;
	case 1488ULL: goto x86_l_5d0;
	case 1490ULL: goto x86_l_5d2;
	case 1493ULL: goto x86_l_5d5;
	case 1499ULL: goto x86_l_5db;
	case 1507ULL: goto x86_l_5e3;
	case 1512ULL: goto x86_l_5e8;
	case 1517ULL: goto x86_l_5ed;
	case 1522ULL: goto x86_l_5f2;
	case 1527ULL: goto x86_l_5f7;
	case 1532ULL: goto x86_l_5fc;
	case 1534ULL: goto x86_l_5fe;
	case 1537ULL: goto x86_l_601;
	case 1543ULL: goto x86_l_607;
	case 1545ULL: goto x86_l_609;
	case 1550ULL: goto x86_l_60e;
	case 1557ULL: goto x86_l_615;
	case 1567ULL: goto x86_l_61f;
	case 1572ULL: goto x86_l_624;
	case 1577ULL: goto x86_l_629;
	case 1584ULL: goto x86_l_630;
	case 1589ULL: goto x86_l_635;
	case 1591ULL: goto x86_l_637;
	case 1594ULL: goto x86_l_63a;
	case 1600ULL: goto x86_l_640;
	case 1602ULL: goto x86_l_642;
	case 1607ULL: goto x86_l_647;
	case 1612ULL: goto x86_l_64c;
	case 1620ULL: goto x86_l_654;
	case 1625ULL: goto x86_l_659;
	case 1632ULL: goto x86_l_660;
	case 1637ULL: goto x86_l_665;
	case 1642ULL: goto x86_l_66a;
	case 1644ULL: goto x86_l_66c;
	case 1646ULL: goto x86_l_66e;
	case 1651ULL: goto x86_l_673;
	case 1655ULL: goto x86_l_677;
	case 1661ULL: goto x86_l_67d;
	case 1666ULL: goto x86_l_682;
	case 1668ULL: goto x86_l_684;
	case 1672ULL: goto x86_l_688;
	case 1677ULL: goto x86_l_68d;
	case 1682ULL: goto x86_l_692;
	case 1687ULL: goto x86_l_697;
	case 1689ULL: goto x86_l_699;
	case 1693ULL: goto x86_l_69d;
	case 1696ULL: goto x86_l_6a0;
	case 1699ULL: goto x86_l_6a3;
	case 1702ULL: goto x86_l_6a6;
	case 1707ULL: goto x86_l_6ab;
	case 1711ULL: goto x86_l_6af;
	case 1717ULL: goto x86_l_6b5;
	case 1722ULL: goto x86_l_6ba;
	case 1727ULL: goto x86_l_6bf;
	case 1732ULL: goto x86_l_6c4;
	case 1734ULL: goto x86_l_6c6;
	case 1737ULL: goto x86_l_6c9;
	case 1743ULL: goto x86_l_6cf;
	case 1745ULL: goto x86_l_6d1;
	case 1750ULL: goto x86_l_6d6;
	case 1757ULL: goto x86_l_6dd;
	case 1767ULL: goto x86_l_6e7;
	case 1772ULL: goto x86_l_6ec;
	case 1777ULL: goto x86_l_6f1;
	case 1784ULL: goto x86_l_6f8;
	case 1789ULL: goto x86_l_6fd;
	case 1791ULL: goto x86_l_6ff;
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
	/* 0x18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d:
	/* 0x1d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_24:
	/* 0x24: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2c:
	/* 0x2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e:
	/* 0x2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: je     2da8 <generic_tracepoint_event+0x2da8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11688ULL;
	}
x86_l_37:
	/* 0x37: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3f:
	/* 0x3f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_46:
	/* 0x46: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4e:
	/* 0x4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50:
	/* 0x50: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_53:
	/* 0x53: je     2da8 <generic_tracepoint_event+0x2da8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11688ULL;
	}
x86_l_59:
	/* 0x59: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_5c:
	/* 0x5c: mov    eax,DWORD PTR [rax+0x64] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_5f:
	/* 0x5f: mov    DWORD PTR [rsp+0x74],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_63:
	/* 0x63: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_65:
	/* 0x65: je     217 <generic_tracepoint_event+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_217;
	}
x86_l_6b:
	/* 0x6b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_70:
	/* 0x70: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_filter_maps)));
x86_l_77:
	/* 0x77: lea    rsi,[rsp+0x74] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_7c:
	/* 0x7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e:
	/* 0x7e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_81:
	/* 0x81: je     2da8 <generic_tracepoint_event+0x2da8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11688ULL;
	}
x86_l_87:
	/* 0x87: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_8a:
	/* 0x8a: mov    DWORD PTR [rsp+0x84],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_95:
	/* 0x95: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9a:
	/* 0x9a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_a1:
	/* 0xa1: lea    rsi,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
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
	/* 0xc9: jne    1c5 <generic_tracepoint_event+0x1c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c5;
	}
x86_l_cf:
	/* 0xcf: jmp    2da8 <generic_tracepoint_event+0x2da8> */
	return 11688ULL;
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
	/* 0xf2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f7:
	/* 0xf7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fc:
	/* 0xfc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_101:
	/* 0x101: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_103:
	/* 0x103: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_109:
	/* 0x109: je     14a <generic_tracepoint_event+0x14a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14a;
	}
x86_l_10b:
	/* 0x10b: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_10e:
	/* 0x10e: ja     14a <generic_tracepoint_event+0x14a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_14a;
	}
x86_l_110:
	/* 0x110: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_112:
	/* 0x112: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_117:
	/* 0x117: shl    rdx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHL, 3ULL);
x86_l_11b:
	/* 0x11b: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_120:
	/* 0x120: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_125:
	/* 0x125: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12a:
	/* 0x12a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12c:
	/* 0x12c: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_132:
	/* 0x132: je     14a <generic_tracepoint_event+0x14a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14a;
	}
x86_l_134:
	/* 0x134: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_139:
	/* 0x139: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13e:
	/* 0x13e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_143:
	/* 0x143: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_148:
	/* 0x148: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14a:
	/* 0x14a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14f:
	/* 0x14f: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_152:
	/* 0x152: je     2da8 <generic_tracepoint_event+0x2da8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11688ULL;
	}
x86_l_158:
	/* 0x158: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_161:
	/* 0x161: add    rdx,0x100 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 256ULL);
x86_l_168:
	/* 0x168: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16d:
	/* 0x16d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_172:
	/* 0x172: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_177:
	/* 0x177: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_179:
	/* 0x179: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17e:
	/* 0x17e: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_187:
	/* 0x187: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_18a:
	/* 0x18a: je     1b5 <generic_tracepoint_event+0x1b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b5;
	}
x86_l_18c:
	/* 0x18c: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_190:
	/* 0x190: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_195:
	/* 0x195: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19a:
	/* 0x19a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19f:
	/* 0x19f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a1:
	/* 0x1a1: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a6:
	/* 0x1a6: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1ab:
	/* 0x1ab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ae:
	/* 0x1ae: jne    1c5 <generic_tracepoint_event+0x1c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c5;
	}
x86_l_1b0:
	/* 0x1b0: jmp    2da8 <generic_tracepoint_event+0x2da8> */
	return 11688ULL;
x86_l_1b5:
	/* 0x1b5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b7:
	/* 0x1b7: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1bc:
	/* 0x1bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bf:
	/* 0x1bf: je     2da8 <generic_tracepoint_event+0x2da8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11688ULL;
	}
x86_l_1c5:
	/* 0x1c5: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ca:
	/* 0x1ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cf:
	/* 0x1cf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_cgtracker_map)));
x86_l_1d6:
	/* 0x1d6: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1db:
	/* 0x1db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd:
	/* 0x1dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e0:
	/* 0x1e0: je     1f6 <generic_tracepoint_event+0x1f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f6;
	}
x86_l_1e2:
	/* 0x1e2: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e5:
	/* 0x1e5: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1ea:
	/* 0x1ea: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ed:
	/* 0x1ed: je     1ff <generic_tracepoint_event+0x1ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ff;
	}
x86_l_1ef:
	/* 0x1ef: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1f4:
	/* 0x1f4: jmp    1ff <generic_tracepoint_event+0x1ff> */
	goto x86_l_1ff;
x86_l_1f6:
	/* 0x1f6: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_1ff:
	/* 0x1ff: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_204:
	/* 0x204: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_209:
	/* 0x209: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_20c:
	/* 0x20c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20e:
	/* 0x20e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_211:
	/* 0x211: je     417 <generic_tracepoint_event+0x417> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_417;
	}
x86_l_217:
	/* 0x217: mov    DWORD PTR [r14+0x5ef8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104419244900352ULL);
x86_l_222:
	/* 0x222: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_225:
	/* 0x225: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_229:
	/* 0x229: mov    QWORD PTR [r14+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_231:
	/* 0x231: movzx  edx,WORD PTR [r15+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 44ULL);
x86_l_236:
	/* 0x236: mov    r13d,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_23a:
	/* 0x23a: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23d:
	/* 0x23d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_240:
	/* 0x240: cmp    r13d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 11ULL);
x86_l_244:
	/* 0x244: jg     27d <generic_tracepoint_event+0x27d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_27d;
	}
x86_l_246:
	/* 0x246: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_24a:
	/* 0x24a: jle    309 <generic_tracepoint_event+0x309> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_309;
	}
x86_l_250:
	/* 0x250: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_254:
	/* 0x254: jg     479 <generic_tracepoint_event+0x479> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_479;
	}
x86_l_25a:
	/* 0x25a: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_25e:
	/* 0x25e: je     848 <generic_tracepoint_event+0x848> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2120ULL;
	}
x86_l_264:
	/* 0x264: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_268:
	/* 0x268: je     722 <generic_tracepoint_event+0x722> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1826ULL;
	}
x86_l_26e:
	/* 0x26e: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_272:
	/* 0x272: je     32a <generic_tracepoint_event+0x32a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32a;
	}
x86_l_278:
	/* 0x278: jmp    a8b <generic_tracepoint_event+0xa8b> */
	return 2699ULL;
x86_l_27d:
	/* 0x27d: cmp    r13d,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 29ULL);
x86_l_281:
	/* 0x281: jle    38f <generic_tracepoint_event+0x38f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_38f;
	}
x86_l_287:
	/* 0x287: cmp    r13d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 37ULL);
x86_l_28b:
	/* 0x28b: jg     4e0 <generic_tracepoint_event+0x4e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4e0;
	}
x86_l_291:
	/* 0x291: cmp    r13d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 30ULL);
x86_l_295:
	/* 0x295: je     8a2 <generic_tracepoint_event+0x8a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2210ULL;
	}
x86_l_29b:
	/* 0x29b: cmp    r13d,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 31ULL);
x86_l_29f:
	/* 0x29f: je     787 <generic_tracepoint_event+0x787> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1927ULL;
	}
x86_l_2a5:
	/* 0x2a5: cmp    r13d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 32ULL);
x86_l_2a9:
	/* 0x2a9: jne    a8b <generic_tracepoint_event+0xa8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2699ULL;
	}
x86_l_2af:
	/* 0x2af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b4:
	/* 0x2b4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b9:
	/* 0x2b9: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_2be:
	/* 0x2be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c0:
	/* 0x2c0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c3:
	/* 0x2c3: je     a09 <generic_tracepoint_event+0xa09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2569ULL;
	}
x86_l_2c9:
	/* 0x2c9: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2cb:
	/* 0x2cb: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d0:
	/* 0x2d0: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2d7:
	/* 0x2d7: movabs rax,0x400000073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869299ULL);
x86_l_2e1:
	/* 0x2e1: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2e6:
	/* 0x2e6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2eb:
	/* 0x2eb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2f2:
	/* 0x2f2: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f7:
	/* 0x2f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f9:
	/* 0x2f9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2fc:
	/* 0x2fc: je     9e7 <generic_tracepoint_event+0x9e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2535ULL;
	}
x86_l_302:
	/* 0x302: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_304:
	/* 0x304: jmp    a09 <generic_tracepoint_event+0xa09> */
	return 2569ULL;
x86_l_309:
	/* 0x309: cmp    r13d,0xfffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967284ULL);
x86_l_30d:
	/* 0x30d: jle    563 <generic_tracepoint_event+0x563> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_563;
	}
x86_l_313:
	/* 0x313: lea    eax,[r13+0xb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_317:
	/* 0x317: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_31a:
	/* 0x31a: jb     486 <generic_tracepoint_event+0x486> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_486;
	}
x86_l_320:
	/* 0x320: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_324:
	/* 0x324: jne    a8b <generic_tracepoint_event+0xa8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2699ULL;
	}
x86_l_32a:
	/* 0x32a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32f:
	/* 0x32f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_334:
	/* 0x334: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_339:
	/* 0x339: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33b:
	/* 0x33b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33e:
	/* 0x33e: je     a33 <generic_tracepoint_event+0xa33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2611ULL;
	}
x86_l_344:
	/* 0x344: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_346:
	/* 0x346: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34b:
	/* 0x34b: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_352:
	/* 0x352: movabs rax,0x400000081 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869313ULL);
x86_l_35c:
	/* 0x35c: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_361:
	/* 0x361: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_366:
	/* 0x366: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_36d:
	/* 0x36d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_372:
	/* 0x372: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_374:
	/* 0x374: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_377:
	/* 0x377: jne    89b <generic_tracepoint_event+0x89b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2203ULL;
	}
x86_l_37d:
	/* 0x37d: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_385:
	/* 0x385: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_38a:
	/* 0x38a: jmp    a1e <generic_tracepoint_event+0xa1e> */
	return 2590ULL;
x86_l_38f:
	/* 0x38f: cmp    r13d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 17ULL);
x86_l_393:
	/* 0x393: jle    578 <generic_tracepoint_event+0x578> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_578;
	}
x86_l_399:
	/* 0x399: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_39d:
	/* 0x39d: je     71a <generic_tracepoint_event+0x71a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1818ULL;
	}
x86_l_3a3:
	/* 0x3a3: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_3a7:
	/* 0x3a7: je     486 <generic_tracepoint_event+0x486> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_486;
	}
x86_l_3ad:
	/* 0x3ad: cmp    r13d,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 29ULL);
x86_l_3b1:
	/* 0x3b1: jne    a8b <generic_tracepoint_event+0xa8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2699ULL;
	}
x86_l_3b7:
	/* 0x3b7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3bc:
	/* 0x3bc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c1:
	/* 0x3c1: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3c6:
	/* 0x3c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c8:
	/* 0x3c8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3cb:
	/* 0x3cb: je     9af <generic_tracepoint_event+0x9af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2479ULL;
	}
x86_l_3d1:
	/* 0x3d1: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_3d3:
	/* 0x3d3: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3d8:
	/* 0x3d8: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_3df:
	/* 0x3df: movabs rax,0x40000006c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869292ULL);
x86_l_3e9:
	/* 0x3e9: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3ee:
	/* 0x3ee: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3f3:
	/* 0x3f3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_3fa:
	/* 0x3fa: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3ff:
	/* 0x3ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_401:
	/* 0x401: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_404:
	/* 0x404: je     98d <generic_tracepoint_event+0x98d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2445ULL;
	}
x86_l_40a:
	/* 0x40a: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_40c:
	/* 0x40c: movsx  r12,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_412:
	/* 0x412: jmp    a8b <generic_tracepoint_event+0xa8b> */
	return 2699ULL;
x86_l_417:
	/* 0x417: mov    QWORD PTR [rsp+0x78],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 519691042815ULL);
x86_l_420:
	/* 0x420: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_425:
	/* 0x425: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_42a:
	/* 0x42a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_42d:
	/* 0x42d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42f:
	/* 0x42f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_432:
	/* 0x432: je     2da8 <generic_tracepoint_event+0x2da8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11688ULL;
	}
x86_l_438:
	/* 0x438: mov    DWORD PTR [rsp+0x74],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 498216206337ULL);
x86_l_440:
	/* 0x440: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_445:
	/* 0x445: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_filter_maps)));
x86_l_44c:
	/* 0x44c: lea    rsi,[rsp+0x74] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_451:
	/* 0x451: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_453:
	/* 0x453: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_456:
	/* 0x456: je     2da8 <generic_tracepoint_event+0x2da8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11688ULL;
	}
x86_l_45c:
	/* 0x45c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_461:
	/* 0x461: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_466:
	/* 0x466: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_469:
	/* 0x469: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_46b:
	/* 0x46b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_46e:
	/* 0x46e: jne    2da8 <generic_tracepoint_event+0x2da8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11688ULL;
	}
x86_l_474:
	/* 0x474: jmp    217 <generic_tracepoint_event+0x217> */
	goto x86_l_217;
x86_l_479:
	/* 0x479: lea    eax,[r13-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_47d:
	/* 0x47d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_480:
	/* 0x480: jae    6ab <generic_tracepoint_event+0x6ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_6ab;
	}
x86_l_486:
	/* 0x486: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_48b:
	/* 0x48b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_490:
	/* 0x490: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_495:
	/* 0x495: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_497:
	/* 0x497: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_49a:
	/* 0x49a: je     66e <generic_tracepoint_event+0x66e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_66e;
	}
x86_l_4a0:
	/* 0x4a0: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_4a2:
	/* 0x4a2: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4a7:
	/* 0x4a7: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_4ae:
	/* 0x4ae: movabs rax,0x400000045 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869253ULL);
x86_l_4b8:
	/* 0x4b8: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4bd:
	/* 0x4bd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4c2:
	/* 0x4c2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_4c9:
	/* 0x4c9: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ce:
	/* 0x4ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d0:
	/* 0x4d0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4d3:
	/* 0x4d3: je     64c <generic_tracepoint_event+0x64c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_64c;
	}
x86_l_4d9:
	/* 0x4d9: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4db:
	/* 0x4db: jmp    66e <generic_tracepoint_event+0x66e> */
	goto x86_l_66e;
x86_l_4e0:
	/* 0x4e0: cmp    r13d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 38ULL);
x86_l_4e4:
	/* 0x4e4: je     902 <generic_tracepoint_event+0x902> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2306ULL;
	}
x86_l_4ea:
	/* 0x4ea: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_4ee:
	/* 0x4ee: je     7e7 <generic_tracepoint_event+0x7e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2023ULL;
	}
x86_l_4f4:
	/* 0x4f4: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_4f8:
	/* 0x4f8: jne    a8b <generic_tracepoint_event+0xa8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2699ULL;
	}
x86_l_4fe:
	/* 0x4fe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_503:
	/* 0x503: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_508:
	/* 0x508: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50d:
	/* 0x50d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50f:
	/* 0x50f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_512:
	/* 0x512: je     a33 <generic_tracepoint_event+0xa33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2611ULL;
	}
x86_l_518:
	/* 0x518: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_51a:
	/* 0x51a: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_51f:
	/* 0x51f: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_526:
	/* 0x526: movabs rax,0x4000000a8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869352ULL);
x86_l_530:
	/* 0x530: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_535:
	/* 0x535: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_53a:
	/* 0x53a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_541:
	/* 0x541: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_546:
	/* 0x546: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_548:
	/* 0x548: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_54b:
	/* 0x54b: jne    89b <generic_tracepoint_event+0x89b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2203ULL;
	}
x86_l_551:
	/* 0x551: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_559:
	/* 0x559: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_55e:
	/* 0x55e: jmp    a1e <generic_tracepoint_event+0xa1e> */
	return 2590ULL;
x86_l_563:
	/* 0x563: cmp    r13d,0xfffffff3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967283ULL);
x86_l_567:
	/* 0x567: je     5ed <generic_tracepoint_event+0x5ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ed;
	}
x86_l_56d:
	/* 0x56d: cmp    r13d,0xfffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967284ULL);
x86_l_571:
	/* 0x571: je     588 <generic_tracepoint_event+0x588> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_588;
	}
x86_l_573:
	/* 0x573: jmp    a8b <generic_tracepoint_event+0xa8b> */
	return 2699ULL;
x86_l_578:
	/* 0x578: cmp    r13d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 12ULL);
x86_l_57c:
	/* 0x57c: je     5ed <generic_tracepoint_event+0x5ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ed;
	}
x86_l_57e:
	/* 0x57e: cmp    r13d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 13ULL);
x86_l_582:
	/* 0x582: jne    a8b <generic_tracepoint_event+0xa8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2699ULL;
	}
x86_l_588:
	/* 0x588: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_58d:
	/* 0x58d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_592:
	/* 0x592: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_597:
	/* 0x597: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_599:
	/* 0x599: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_59c:
	/* 0x59c: je     a86 <generic_tracepoint_event+0xa86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2694ULL;
	}
x86_l_5a2:
	/* 0x5a2: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_5a4:
	/* 0x5a4: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5a9:
	/* 0x5a9: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_5b0:
	/* 0x5b0: movabs rax,0x40000005e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869278ULL);
x86_l_5ba:
	/* 0x5ba: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5bf:
	/* 0x5bf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5c4:
	/* 0x5c4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_5cb:
	/* 0x5cb: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5d0:
	/* 0x5d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d2:
	/* 0x5d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5d5:
	/* 0x5d5: jne    955 <generic_tracepoint_event+0x955> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2389ULL;
	}
x86_l_5db:
	/* 0x5db: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_5e3:
	/* 0x5e3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5e8:
	/* 0x5e8: jmp    a71 <generic_tracepoint_event+0xa71> */
	return 2673ULL;
x86_l_5ed:
	/* 0x5ed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5f2:
	/* 0x5f2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f7:
	/* 0x5f7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5fc:
	/* 0x5fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fe:
	/* 0x5fe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_601:
	/* 0x601: je     983 <generic_tracepoint_event+0x983> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2435ULL;
	}
x86_l_607:
	/* 0x607: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_609:
	/* 0x609: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_60e:
	/* 0x60e: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_615:
	/* 0x615: movabs rax,0x400000056 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869270ULL);
x86_l_61f:
	/* 0x61f: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_624:
	/* 0x624: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_629:
	/* 0x629: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_630:
	/* 0x630: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_635:
	/* 0x635: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_637:
	/* 0x637: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_63a:
	/* 0x63a: je     961 <generic_tracepoint_event+0x961> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2401ULL;
	}
x86_l_640:
	/* 0x640: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_642:
	/* 0x642: movsxd r12,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_647:
	/* 0x647: jmp    a8b <generic_tracepoint_event+0xa8b> */
	return 2699ULL;
x86_l_64c:
	/* 0x64c: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_654:
	/* 0x654: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_659:
	/* 0x659: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_660:
	/* 0x660: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_665:
	/* 0x665: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_66a:
	/* 0x66a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_66c:
	/* 0x66c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66e:
	/* 0x66e: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_673:
	/* 0x673: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_677:
	/* 0x677: jne    a8b <generic_tracepoint_event+0xa8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2699ULL;
	}
x86_l_67d:
	/* 0x67d: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_682:
	/* 0x682: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_684:
	/* 0x684: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_688:
	/* 0x688: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_68d:
	/* 0x68d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_692:
	/* 0x692: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_697:
	/* 0x697: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_699:
	/* 0x699: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_69d:
	/* 0x69d: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_6a0:
	/* 0x6a0: shl    eax,0x1e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 30ULL);
x86_l_6a3:
	/* 0x6a3: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_6a6:
	/* 0x6a6: jmp    a8b <generic_tracepoint_event+0xa8b> */
	return 2699ULL;
x86_l_6ab:
	/* 0x6ab: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_6af:
	/* 0x6af: jne    a8b <generic_tracepoint_event+0xa8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2699ULL;
	}
x86_l_6b5:
	/* 0x6b5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6ba:
	/* 0x6ba: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6bf:
	/* 0x6bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6c4:
	/* 0x6c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c6:
	/* 0x6c6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6c9:
	/* 0x6c9: je     a33 <generic_tracepoint_event+0xa33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2611ULL;
	}
x86_l_6cf:
	/* 0x6cf: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_6d1:
	/* 0x6d1: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6d6:
	/* 0x6d6: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_6dd:
	/* 0x6dd: movabs rax,0x40000009a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869338ULL);
x86_l_6e7:
	/* 0x6e7: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6ec:
	/* 0x6ec: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6f1:
	/* 0x6f1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_6f8:
	/* 0x6f8: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6fd:
	/* 0x6fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ff:
	/* 0x6ff: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
	return 1794ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1794ULL: goto x86_l_702;
	case 1800ULL: goto x86_l_708;
	case 1808ULL: goto x86_l_710;
	case 1813ULL: goto x86_l_715;
	case 1818ULL: goto x86_l_71a;
	case 1821ULL: goto x86_l_71d;
	case 1826ULL: goto x86_l_722;
	case 1831ULL: goto x86_l_727;
	case 1836ULL: goto x86_l_72c;
	case 1841ULL: goto x86_l_731;
	case 1843ULL: goto x86_l_733;
	case 1846ULL: goto x86_l_736;
	case 1852ULL: goto x86_l_73c;
	case 1854ULL: goto x86_l_73e;
	case 1859ULL: goto x86_l_743;
	case 1866ULL: goto x86_l_74a;
	case 1876ULL: goto x86_l_754;
	case 1881ULL: goto x86_l_759;
	case 1886ULL: goto x86_l_75e;
	case 1893ULL: goto x86_l_765;
	case 1898ULL: goto x86_l_76a;
	case 1900ULL: goto x86_l_76c;
	case 1903ULL: goto x86_l_76f;
	case 1909ULL: goto x86_l_775;
	case 1917ULL: goto x86_l_77d;
	case 1922ULL: goto x86_l_782;
	case 1927ULL: goto x86_l_787;
	case 1932ULL: goto x86_l_78c;
	case 1937ULL: goto x86_l_791;
	case 1942ULL: goto x86_l_796;
	case 1944ULL: goto x86_l_798;
	case 1947ULL: goto x86_l_79b;
	case 1953ULL: goto x86_l_7a1;
	case 1955ULL: goto x86_l_7a3;
	case 1960ULL: goto x86_l_7a8;
	case 1967ULL: goto x86_l_7af;
	case 1977ULL: goto x86_l_7b9;
	case 1982ULL: goto x86_l_7be;
	case 1987ULL: goto x86_l_7c3;
	case 1994ULL: goto x86_l_7ca;
	case 1999ULL: goto x86_l_7cf;
	case 2001ULL: goto x86_l_7d1;
	case 2004ULL: goto x86_l_7d4;
	case 2010ULL: goto x86_l_7da;
	case 2012ULL: goto x86_l_7dc;
	case 2018ULL: goto x86_l_7e2;
	case 2023ULL: goto x86_l_7e7;
	case 2028ULL: goto x86_l_7ec;
	case 2033ULL: goto x86_l_7f1;
	case 2038ULL: goto x86_l_7f6;
	case 2040ULL: goto x86_l_7f8;
	case 2043ULL: goto x86_l_7fb;
	case 2049ULL: goto x86_l_801;
	case 2051ULL: goto x86_l_803;
	case 2056ULL: goto x86_l_808;
	case 2063ULL: goto x86_l_80f;
	case 2073ULL: goto x86_l_819;
	case 2078ULL: goto x86_l_81e;
	case 2083ULL: goto x86_l_823;
	case 2090ULL: goto x86_l_82a;
	case 2095ULL: goto x86_l_82f;
	case 2097ULL: goto x86_l_831;
	case 2100ULL: goto x86_l_834;
	case 2102ULL: goto x86_l_836;
	case 2110ULL: goto x86_l_83e;
	case 2115ULL: goto x86_l_843;
	case 2120ULL: goto x86_l_848;
	case 2125ULL: goto x86_l_84d;
	case 2130ULL: goto x86_l_852;
	case 2135ULL: goto x86_l_857;
	case 2137ULL: goto x86_l_859;
	case 2140ULL: goto x86_l_85c;
	case 2146ULL: goto x86_l_862;
	case 2148ULL: goto x86_l_864;
	case 2153ULL: goto x86_l_869;
	case 2160ULL: goto x86_l_870;
	case 2170ULL: goto x86_l_87a;
	case 2175ULL: goto x86_l_87f;
	case 2180ULL: goto x86_l_884;
	case 2187ULL: goto x86_l_88b;
	case 2192ULL: goto x86_l_890;
	case 2194ULL: goto x86_l_892;
	case 2197ULL: goto x86_l_895;
	case 2203ULL: goto x86_l_89b;
	case 2205ULL: goto x86_l_89d;
	case 2210ULL: goto x86_l_8a2;
	case 2215ULL: goto x86_l_8a7;
	case 2220ULL: goto x86_l_8ac;
	case 2225ULL: goto x86_l_8b1;
	case 2227ULL: goto x86_l_8b3;
	case 2230ULL: goto x86_l_8b6;
	case 2236ULL: goto x86_l_8bc;
	case 2238ULL: goto x86_l_8be;
	case 2243ULL: goto x86_l_8c3;
	case 2250ULL: goto x86_l_8ca;
	case 2260ULL: goto x86_l_8d4;
	case 2265ULL: goto x86_l_8d9;
	case 2270ULL: goto x86_l_8de;
	case 2277ULL: goto x86_l_8e5;
	case 2282ULL: goto x86_l_8ea;
	case 2284ULL: goto x86_l_8ec;
	case 2287ULL: goto x86_l_8ef;
	case 2293ULL: goto x86_l_8f5;
	case 2295ULL: goto x86_l_8f7;
	case 2301ULL: goto x86_l_8fd;
	case 2306ULL: goto x86_l_902;
	case 2311ULL: goto x86_l_907;
	case 2316ULL: goto x86_l_90c;
	case 2321ULL: goto x86_l_911;
	case 2323ULL: goto x86_l_913;
	case 2326ULL: goto x86_l_916;
	case 2332ULL: goto x86_l_91c;
	case 2334ULL: goto x86_l_91e;
	case 2339ULL: goto x86_l_923;
	case 2346ULL: goto x86_l_92a;
	case 2356ULL: goto x86_l_934;
	case 2361ULL: goto x86_l_939;
	case 2366ULL: goto x86_l_93e;
	case 2373ULL: goto x86_l_945;
	case 2378ULL: goto x86_l_94a;
	case 2380ULL: goto x86_l_94c;
	case 2383ULL: goto x86_l_94f;
	case 2389ULL: goto x86_l_955;
	case 2391ULL: goto x86_l_957;
	case 2396ULL: goto x86_l_95c;
	case 2401ULL: goto x86_l_961;
	case 2409ULL: goto x86_l_969;
	case 2414ULL: goto x86_l_96e;
	case 2421ULL: goto x86_l_975;
	case 2426ULL: goto x86_l_97a;
	case 2431ULL: goto x86_l_97f;
	case 2433ULL: goto x86_l_981;
	case 2435ULL: goto x86_l_983;
	case 2440ULL: goto x86_l_988;
	case 2445ULL: goto x86_l_98d;
	case 2453ULL: goto x86_l_995;
	case 2458ULL: goto x86_l_99a;
	case 2465ULL: goto x86_l_9a1;
	case 2470ULL: goto x86_l_9a6;
	case 2475ULL: goto x86_l_9ab;
	case 2477ULL: goto x86_l_9ad;
	case 2479ULL: goto x86_l_9af;
	case 2485ULL: goto x86_l_9b5;
	case 2490ULL: goto x86_l_9ba;
	case 2498ULL: goto x86_l_9c2;
	case 2503ULL: goto x86_l_9c7;
	case 2510ULL: goto x86_l_9ce;
	case 2515ULL: goto x86_l_9d3;
	case 2520ULL: goto x86_l_9d8;
	case 2522ULL: goto x86_l_9da;
	case 2524ULL: goto x86_l_9dc;
	case 2530ULL: goto x86_l_9e2;
	case 2535ULL: goto x86_l_9e7;
	case 2543ULL: goto x86_l_9ef;
	case 2548ULL: goto x86_l_9f4;
	case 2555ULL: goto x86_l_9fb;
	case 2560ULL: goto x86_l_a00;
	case 2565ULL: goto x86_l_a05;
	case 2567ULL: goto x86_l_a07;
	case 2569ULL: goto x86_l_a09;
	case 2575ULL: goto x86_l_a0f;
	case 2577ULL: goto x86_l_a11;
	case 2585ULL: goto x86_l_a19;
	case 2590ULL: goto x86_l_a1e;
	case 2597ULL: goto x86_l_a25;
	case 2602ULL: goto x86_l_a2a;
	case 2607ULL: goto x86_l_a2f;
	case 2609ULL: goto x86_l_a31;
	case 2611ULL: goto x86_l_a33;
	case 2616ULL: goto x86_l_a38;
	case 2618ULL: goto x86_l_a3a;
	case 2626ULL: goto x86_l_a42;
	case 2631ULL: goto x86_l_a47;
	case 2638ULL: goto x86_l_a4e;
	case 2643ULL: goto x86_l_a53;
	case 2648ULL: goto x86_l_a58;
	case 2650ULL: goto x86_l_a5a;
	case 2652ULL: goto x86_l_a5c;
	case 2658ULL: goto x86_l_a62;
	case 2660ULL: goto x86_l_a64;
	case 2668ULL: goto x86_l_a6c;
	case 2673ULL: goto x86_l_a71;
	case 2680ULL: goto x86_l_a78;
	case 2685ULL: goto x86_l_a7d;
	case 2690ULL: goto x86_l_a82;
	case 2692ULL: goto x86_l_a84;
	case 2694ULL: goto x86_l_a86;
	case 2699ULL: goto x86_l_a8b;
	case 2706ULL: goto x86_l_a92;
	case 2711ULL: goto x86_l_a97;
	case 2715ULL: goto x86_l_a9b;
	case 2718ULL: goto x86_l_a9e;
	case 2721ULL: goto x86_l_aa1;
	case 2725ULL: goto x86_l_aa5;
	case 2727ULL: goto x86_l_aa7;
	case 2731ULL: goto x86_l_aab;
	case 2737ULL: goto x86_l_ab1;
	case 2741ULL: goto x86_l_ab5;
	case 2747ULL: goto x86_l_abb;
	case 2751ULL: goto x86_l_abf;
	case 2757ULL: goto x86_l_ac5;
	case 2761ULL: goto x86_l_ac9;
	case 2767ULL: goto x86_l_acf;
	case 2771ULL: goto x86_l_ad3;
	case 2777ULL: goto x86_l_ad9;
	case 2782ULL: goto x86_l_ade;
	case 2786ULL: goto x86_l_ae2;
	case 2792ULL: goto x86_l_ae8;
	case 2796ULL: goto x86_l_aec;
	case 2802ULL: goto x86_l_af2;
	case 2806ULL: goto x86_l_af6;
	case 2812ULL: goto x86_l_afc;
	case 2816ULL: goto x86_l_b00;
	case 2822ULL: goto x86_l_b06;
	case 2826ULL: goto x86_l_b0a;
	case 2832ULL: goto x86_l_b10;
	case 2837ULL: goto x86_l_b15;
	case 2842ULL: goto x86_l_b1a;
	case 2847ULL: goto x86_l_b1f;
	case 2849ULL: goto x86_l_b21;
	case 2852ULL: goto x86_l_b24;
	case 2858ULL: goto x86_l_b2a;
	case 2860ULL: goto x86_l_b2c;
	case 2865ULL: goto x86_l_b31;
	case 2872ULL: goto x86_l_b38;
	case 2882ULL: goto x86_l_b42;
	case 2887ULL: goto x86_l_b47;
	case 2892ULL: goto x86_l_b4c;
	case 2899ULL: goto x86_l_b53;
	case 2904ULL: goto x86_l_b58;
	case 2906ULL: goto x86_l_b5a;
	case 2909ULL: goto x86_l_b5d;
	case 2915ULL: goto x86_l_b63;
	case 2917ULL: goto x86_l_b65;
	case 2923ULL: goto x86_l_b6b;
	case 2928ULL: goto x86_l_b70;
	case 2932ULL: goto x86_l_b74;
	case 2938ULL: goto x86_l_b7a;
	case 2942ULL: goto x86_l_b7e;
	case 2945ULL: goto x86_l_b81;
	case 2951ULL: goto x86_l_b87;
	case 2955ULL: goto x86_l_b8b;
	case 2961ULL: goto x86_l_b91;
	case 2966ULL: goto x86_l_b96;
	case 2971ULL: goto x86_l_b9b;
	case 2976ULL: goto x86_l_ba0;
	case 2978ULL: goto x86_l_ba2;
	case 2981ULL: goto x86_l_ba5;
	case 2987ULL: goto x86_l_bab;
	case 2989ULL: goto x86_l_bad;
	case 2994ULL: goto x86_l_bb2;
	case 3001ULL: goto x86_l_bb9;
	case 3011ULL: goto x86_l_bc3;
	case 3016ULL: goto x86_l_bc8;
	case 3021ULL: goto x86_l_bcd;
	case 3028ULL: goto x86_l_bd4;
	case 3033ULL: goto x86_l_bd9;
	case 3035ULL: goto x86_l_bdb;
	case 3038ULL: goto x86_l_bde;
	case 3044ULL: goto x86_l_be4;
	case 3052ULL: goto x86_l_bec;
	case 3057ULL: goto x86_l_bf1;
	case 3062ULL: goto x86_l_bf6;
	case 3066ULL: goto x86_l_bfa;
	case 3072ULL: goto x86_l_c00;
	case 3076ULL: goto x86_l_c04;
	case 3082ULL: goto x86_l_c0a;
	case 3086ULL: goto x86_l_c0e;
	case 3088ULL: goto x86_l_c10;
	case 3092ULL: goto x86_l_c14;
	case 3098ULL: goto x86_l_c1a;
	case 3103ULL: goto x86_l_c1f;
	case 3108ULL: goto x86_l_c24;
	case 3113ULL: goto x86_l_c29;
	case 3115ULL: goto x86_l_c2b;
	case 3118ULL: goto x86_l_c2e;
	case 3124ULL: goto x86_l_c34;
	case 3126ULL: goto x86_l_c36;
	case 3131ULL: goto x86_l_c3b;
	case 3138ULL: goto x86_l_c42;
	case 3148ULL: goto x86_l_c4c;
	case 3153ULL: goto x86_l_c51;
	case 3158ULL: goto x86_l_c56;
	case 3165ULL: goto x86_l_c5d;
	case 3170ULL: goto x86_l_c62;
	case 3172ULL: goto x86_l_c64;
	case 3175ULL: goto x86_l_c67;
	case 3181ULL: goto x86_l_c6d;
	case 3183ULL: goto x86_l_c6f;
	case 3189ULL: goto x86_l_c75;
	case 3194ULL: goto x86_l_c7a;
	case 3198ULL: goto x86_l_c7e;
	case 3201ULL: goto x86_l_c81;
	case 3207ULL: goto x86_l_c87;
	case 3212ULL: goto x86_l_c8c;
	case 3217ULL: goto x86_l_c91;
	case 3222ULL: goto x86_l_c96;
	case 3224ULL: goto x86_l_c98;
	case 3227ULL: goto x86_l_c9b;
	case 3233ULL: goto x86_l_ca1;
	case 3235ULL: goto x86_l_ca3;
	case 3240ULL: goto x86_l_ca8;
	case 3247ULL: goto x86_l_caf;
	case 3257ULL: goto x86_l_cb9;
	case 3262ULL: goto x86_l_cbe;
	case 3267ULL: goto x86_l_cc3;
	case 3274ULL: goto x86_l_cca;
	case 3279ULL: goto x86_l_ccf;
	case 3281ULL: goto x86_l_cd1;
	case 3284ULL: goto x86_l_cd4;
	case 3290ULL: goto x86_l_cda;
	case 3292ULL: goto x86_l_cdc;
	case 3297ULL: goto x86_l_ce1;
	case 3301ULL: goto x86_l_ce5;
	case 3307ULL: goto x86_l_ceb;
	case 3311ULL: goto x86_l_cef;
	case 3317ULL: goto x86_l_cf5;
	case 3321ULL: goto x86_l_cf9;
	case 3327ULL: goto x86_l_cff;
	case 3332ULL: goto x86_l_d04;
	case 3337ULL: goto x86_l_d09;
	case 3342ULL: goto x86_l_d0e;
	case 3344ULL: goto x86_l_d10;
	case 3347ULL: goto x86_l_d13;
	case 3353ULL: goto x86_l_d19;
	case 3355ULL: goto x86_l_d1b;
	case 3360ULL: goto x86_l_d20;
	case 3367ULL: goto x86_l_d27;
	case 3377ULL: goto x86_l_d31;
	case 3382ULL: goto x86_l_d36;
	case 3387ULL: goto x86_l_d3b;
	case 3394ULL: goto x86_l_d42;
	case 3399ULL: goto x86_l_d47;
	case 3401ULL: goto x86_l_d49;
	case 3404ULL: goto x86_l_d4c;
	case 3410ULL: goto x86_l_d52;
	case 3418ULL: goto x86_l_d5a;
	case 3423ULL: goto x86_l_d5f;
	case 3428ULL: goto x86_l_d64;
	case 3432ULL: goto x86_l_d68;
	case 3438ULL: goto x86_l_d6e;
	case 3442ULL: goto x86_l_d72;
	case 3444ULL: goto x86_l_d74;
	case 3449ULL: goto x86_l_d79;
	case 3453ULL: goto x86_l_d7d;
	case 3455ULL: goto x86_l_d7f;
	case 3459ULL: goto x86_l_d83;
	case 3465ULL: goto x86_l_d89;
	case 3470ULL: goto x86_l_d8e;
	case 3475ULL: goto x86_l_d93;
	case 3480ULL: goto x86_l_d98;
	case 3482ULL: goto x86_l_d9a;
	case 3485ULL: goto x86_l_d9d;
	case 3491ULL: goto x86_l_da3;
	case 3493ULL: goto x86_l_da5;
	case 3498ULL: goto x86_l_daa;
	case 3505ULL: goto x86_l_db1;
	case 3515ULL: goto x86_l_dbb;
	case 3520ULL: goto x86_l_dc0;
	case 3525ULL: goto x86_l_dc5;
	case 3532ULL: goto x86_l_dcc;
	case 3537ULL: goto x86_l_dd1;
	case 3539ULL: goto x86_l_dd3;
	case 3542ULL: goto x86_l_dd6;
	case 3548ULL: goto x86_l_ddc;
	case 3556ULL: goto x86_l_de4;
	case 3561ULL: goto x86_l_de9;
	case 3566ULL: goto x86_l_dee;
	case 3571ULL: goto x86_l_df3;
	case 3576ULL: goto x86_l_df8;
	case 3581ULL: goto x86_l_dfd;
	case 3583ULL: goto x86_l_dff;
	case 3586ULL: goto x86_l_e02;
	case 3592ULL: goto x86_l_e08;
	case 3594ULL: goto x86_l_e0a;
	case 3599ULL: goto x86_l_e0f;
	case 3606ULL: goto x86_l_e16;
	case 3616ULL: goto x86_l_e20;
	case 3621ULL: goto x86_l_e25;
	case 3626ULL: goto x86_l_e2a;
	case 3633ULL: goto x86_l_e31;
	case 3638ULL: goto x86_l_e36;
	case 3640ULL: goto x86_l_e38;
	case 3643ULL: goto x86_l_e3b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_702:
	/* 0x702: jne    89b <generic_tracepoint_event+0x89b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_89b;
	}
x86_l_708:
	/* 0x708: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_710:
	/* 0x710: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_715:
	/* 0x715: jmp    a1e <generic_tracepoint_event+0xa1e> */
	goto x86_l_a1e;
x86_l_71a:
	/* 0x71a: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_71d:
	/* 0x71d: jmp    a8b <generic_tracepoint_event+0xa8b> */
	goto x86_l_a8b;
x86_l_722:
	/* 0x722: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_727:
	/* 0x727: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_72c:
	/* 0x72c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_731:
	/* 0x731: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_733:
	/* 0x733: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_736:
	/* 0x736: je     a33 <generic_tracepoint_event+0xa33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a33;
	}
x86_l_73c:
	/* 0x73c: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_73e:
	/* 0x73e: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_743:
	/* 0x743: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_74a:
	/* 0x74a: movabs rax,0x400000093 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869331ULL);
x86_l_754:
	/* 0x754: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_759:
	/* 0x759: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_75e:
	/* 0x75e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_765:
	/* 0x765: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_76a:
	/* 0x76a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76c:
	/* 0x76c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_76f:
	/* 0x76f: jne    89b <generic_tracepoint_event+0x89b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_89b;
	}
x86_l_775:
	/* 0x775: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_77d:
	/* 0x77d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_782:
	/* 0x782: jmp    a1e <generic_tracepoint_event+0xa1e> */
	goto x86_l_a1e;
x86_l_787:
	/* 0x787: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_78c:
	/* 0x78c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_791:
	/* 0x791: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_796:
	/* 0x796: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_798:
	/* 0x798: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_79b:
	/* 0x79b: je     9dc <generic_tracepoint_event+0x9dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9dc;
	}
x86_l_7a1:
	/* 0x7a1: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_7a3:
	/* 0x7a3: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7a8:
	/* 0x7a8: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_7af:
	/* 0x7af: movabs rax,0x40000007a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869306ULL);
x86_l_7b9:
	/* 0x7b9: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_7be:
	/* 0x7be: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7c3:
	/* 0x7c3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_7ca:
	/* 0x7ca: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7cf:
	/* 0x7cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7d1:
	/* 0x7d1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7d4:
	/* 0x7d4: je     9ba <generic_tracepoint_event+0x9ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9ba;
	}
x86_l_7da:
	/* 0x7da: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_7dc:
	/* 0x7dc: movsx  r12,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_7e2:
	/* 0x7e2: jmp    a8b <generic_tracepoint_event+0xa8b> */
	goto x86_l_a8b;
x86_l_7e7:
	/* 0x7e7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7ec:
	/* 0x7ec: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7f1:
	/* 0x7f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7f6:
	/* 0x7f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f8:
	/* 0x7f8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7fb:
	/* 0x7fb: je     a33 <generic_tracepoint_event+0xa33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a33;
	}
x86_l_801:
	/* 0x801: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_803:
	/* 0x803: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_808:
	/* 0x808: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_80f:
	/* 0x80f: movabs rax,0x4000000a1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869345ULL);
x86_l_819:
	/* 0x819: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_81e:
	/* 0x81e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_823:
	/* 0x823: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_82a:
	/* 0x82a: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_82f:
	/* 0x82f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_831:
	/* 0x831: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_834:
	/* 0x834: jne    89b <generic_tracepoint_event+0x89b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_89b;
	}
x86_l_836:
	/* 0x836: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_83e:
	/* 0x83e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_843:
	/* 0x843: jmp    a1e <generic_tracepoint_event+0xa1e> */
	goto x86_l_a1e;
x86_l_848:
	/* 0x848: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_84d:
	/* 0x84d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_852:
	/* 0x852: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_857:
	/* 0x857: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_859:
	/* 0x859: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_85c:
	/* 0x85c: je     a33 <generic_tracepoint_event+0xa33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a33;
	}
x86_l_862:
	/* 0x862: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_864:
	/* 0x864: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_869:
	/* 0x869: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_870:
	/* 0x870: movabs rax,0x40000004e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869262ULL);
x86_l_87a:
	/* 0x87a: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_87f:
	/* 0x87f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_884:
	/* 0x884: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_88b:
	/* 0x88b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_890:
	/* 0x890: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_892:
	/* 0x892: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_895:
	/* 0x895: je     a11 <generic_tracepoint_event+0xa11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a11;
	}
x86_l_89b:
	/* 0x89b: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_89d:
	/* 0x89d: jmp    a33 <generic_tracepoint_event+0xa33> */
	goto x86_l_a33;
x86_l_8a2:
	/* 0x8a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8a7:
	/* 0x8a7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8ac:
	/* 0x8ac: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_8b1:
	/* 0x8b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b3:
	/* 0x8b3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8b6:
	/* 0x8b6: je     a5c <generic_tracepoint_event+0xa5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a5c;
	}
x86_l_8bc:
	/* 0x8bc: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_8be:
	/* 0x8be: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8c3:
	/* 0x8c3: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_8ca:
	/* 0x8ca: movabs rax,0x400000065 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869285ULL);
x86_l_8d4:
	/* 0x8d4: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_8d9:
	/* 0x8d9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8de:
	/* 0x8de: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_8e5:
	/* 0x8e5: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8ea:
	/* 0x8ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ec:
	/* 0x8ec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8ef:
	/* 0x8ef: je     a3a <generic_tracepoint_event+0xa3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a3a;
	}
x86_l_8f5:
	/* 0x8f5: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_8f7:
	/* 0x8f7: movzx  r12d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_8fd:
	/* 0x8fd: jmp    a8b <generic_tracepoint_event+0xa8b> */
	goto x86_l_a8b;
x86_l_902:
	/* 0x902: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_907:
	/* 0x907: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_90c:
	/* 0x90c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_911:
	/* 0x911: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_913:
	/* 0x913: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_916:
	/* 0x916: je     a86 <generic_tracepoint_event+0xa86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a86;
	}
x86_l_91c:
	/* 0x91c: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_91e:
	/* 0x91e: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_923:
	/* 0x923: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_92a:
	/* 0x92a: movabs rax,0x400000088 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869320ULL);
x86_l_934:
	/* 0x934: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_939:
	/* 0x939: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_93e:
	/* 0x93e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_945:
	/* 0x945: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_94a:
	/* 0x94a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94c:
	/* 0x94c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_94f:
	/* 0x94f: je     a64 <generic_tracepoint_event+0xa64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a64;
	}
x86_l_955:
	/* 0x955: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_957:
	/* 0x957: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_95c:
	/* 0x95c: jmp    a8b <generic_tracepoint_event+0xa8b> */
	goto x86_l_a8b;
x86_l_961:
	/* 0x961: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_969:
	/* 0x969: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_96e:
	/* 0x96e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_975:
	/* 0x975: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_97a:
	/* 0x97a: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_97f:
	/* 0x97f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_981:
	/* 0x981: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_983:
	/* 0x983: movsxd r12,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_988:
	/* 0x988: jmp    a8b <generic_tracepoint_event+0xa8b> */
	goto x86_l_a8b;
x86_l_98d:
	/* 0x98d: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_995:
	/* 0x995: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_99a:
	/* 0x99a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_9a1:
	/* 0x9a1: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9a6:
	/* 0x9a6: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9ab:
	/* 0x9ab: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9ad:
	/* 0x9ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9af:
	/* 0x9af: movsx  r12,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_9b5:
	/* 0x9b5: jmp    a8b <generic_tracepoint_event+0xa8b> */
	goto x86_l_a8b;
x86_l_9ba:
	/* 0x9ba: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_9c2:
	/* 0x9c2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9c7:
	/* 0x9c7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_9ce:
	/* 0x9ce: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9d3:
	/* 0x9d3: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9d8:
	/* 0x9d8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9da:
	/* 0x9da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9dc:
	/* 0x9dc: movsx  r12,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_9e2:
	/* 0x9e2: jmp    a8b <generic_tracepoint_event+0xa8b> */
	goto x86_l_a8b;
x86_l_9e7:
	/* 0x9e7: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_9ef:
	/* 0x9ef: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9f4:
	/* 0x9f4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_9fb:
	/* 0x9fb: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a00:
	/* 0xa00: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a05:
	/* 0xa05: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a07:
	/* 0xa07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a09:
	/* 0xa09: movzx  r12d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_a0f:
	/* 0xa0f: jmp    a8b <generic_tracepoint_event+0xa8b> */
	goto x86_l_a8b;
x86_l_a11:
	/* 0xa11: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_a19:
	/* 0xa19: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a1e:
	/* 0xa1e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_a25:
	/* 0xa25: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a2a:
	/* 0xa2a: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a2f:
	/* 0xa2f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a31:
	/* 0xa31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a33:
	/* 0xa33: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a38:
	/* 0xa38: jmp    a8b <generic_tracepoint_event+0xa8b> */
	goto x86_l_a8b;
x86_l_a3a:
	/* 0xa3a: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_a42:
	/* 0xa42: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a47:
	/* 0xa47: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_a4e:
	/* 0xa4e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a53:
	/* 0xa53: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a58:
	/* 0xa58: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a5a:
	/* 0xa5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a5c:
	/* 0xa5c: movzx  r12d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_a62:
	/* 0xa62: jmp    a8b <generic_tracepoint_event+0xa8b> */
	goto x86_l_a8b;
x86_l_a64:
	/* 0xa64: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_a6c:
	/* 0xa6c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a71:
	/* 0xa71: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_a78:
	/* 0xa78: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a7d:
	/* 0xa7d: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a82:
	/* 0xa82: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a84:
	/* 0xa84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a86:
	/* 0xa86: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a8b:
	/* 0xa8b: mov    QWORD PTR [r14+0x5e50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24144ULL);
x86_l_a92:
	/* 0xa92: movzx  edx,WORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_a97:
	/* 0xa97: mov    r13d,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a9b:
	/* 0xa9b: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a9e:
	/* 0xa9e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aa1:
	/* 0xaa1: cmp    r13d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 11ULL);
x86_l_aa5:
	/* 0xaa5: jg     ade <generic_tracepoint_event+0xade> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_ade;
	}
x86_l_aa7:
	/* 0xaa7: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_aab:
	/* 0xaab: jle    b70 <generic_tracepoint_event+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_b70;
	}
x86_l_ab1:
	/* 0xab1: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_ab5:
	/* 0xab5: jg     c7a <generic_tracepoint_event+0xc7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_c7a;
	}
x86_l_abb:
	/* 0xabb: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_abf:
	/* 0xabf: je     1049 <generic_tracepoint_event+0x1049> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4169ULL;
	}
x86_l_ac5:
	/* 0xac5: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_ac9:
	/* 0xac9: je     f23 <generic_tracepoint_event+0xf23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3875ULL;
	}
x86_l_acf:
	/* 0xacf: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_ad3:
	/* 0xad3: je     b91 <generic_tracepoint_event+0xb91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b91;
	}
x86_l_ad9:
	/* 0xad9: jmp    128c <generic_tracepoint_event+0x128c> */
	return 4748ULL;
x86_l_ade:
	/* 0xade: cmp    r13d,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 29ULL);
x86_l_ae2:
	/* 0xae2: jle    bf6 <generic_tracepoint_event+0xbf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_bf6;
	}
x86_l_ae8:
	/* 0xae8: cmp    r13d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 37ULL);
x86_l_aec:
	/* 0xaec: jg     ce1 <generic_tracepoint_event+0xce1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_ce1;
	}
x86_l_af2:
	/* 0xaf2: cmp    r13d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 30ULL);
x86_l_af6:
	/* 0xaf6: je     10a3 <generic_tracepoint_event+0x10a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4259ULL;
	}
x86_l_afc:
	/* 0xafc: cmp    r13d,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 31ULL);
x86_l_b00:
	/* 0xb00: je     f88 <generic_tracepoint_event+0xf88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3976ULL;
	}
x86_l_b06:
	/* 0xb06: cmp    r13d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 32ULL);
x86_l_b0a:
	/* 0xb0a: jne    128c <generic_tracepoint_event+0x128c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4748ULL;
	}
x86_l_b10:
	/* 0xb10: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b15:
	/* 0xb15: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b1a:
	/* 0xb1a: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_b1f:
	/* 0xb1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b21:
	/* 0xb21: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b24:
	/* 0xb24: je     120a <generic_tracepoint_event+0x120a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4618ULL;
	}
x86_l_b2a:
	/* 0xb2a: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_b2c:
	/* 0xb2c: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b31:
	/* 0xb31: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_b38:
	/* 0xb38: movabs rax,0x400000073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869299ULL);
x86_l_b42:
	/* 0xb42: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_b47:
	/* 0xb47: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b4c:
	/* 0xb4c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_b53:
	/* 0xb53: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b58:
	/* 0xb58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b5a:
	/* 0xb5a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b5d:
	/* 0xb5d: je     11e8 <generic_tracepoint_event+0x11e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4584ULL;
	}
x86_l_b63:
	/* 0xb63: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_b65:
	/* 0xb65: movzx  r12d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_b6b:
	/* 0xb6b: jmp    128c <generic_tracepoint_event+0x128c> */
	return 4748ULL;
x86_l_b70:
	/* 0xb70: cmp    r13d,0xfffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967284ULL);
x86_l_b74:
	/* 0xb74: jle    d64 <generic_tracepoint_event+0xd64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_d64;
	}
x86_l_b7a:
	/* 0xb7a: lea    eax,[r13+0xb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_b7e:
	/* 0xb7e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b81:
	/* 0xb81: jb     c87 <generic_tracepoint_event+0xc87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c87;
	}
x86_l_b87:
	/* 0xb87: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_b8b:
	/* 0xb8b: jne    128c <generic_tracepoint_event+0x128c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4748ULL;
	}
x86_l_b91:
	/* 0xb91: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b96:
	/* 0xb96: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b9b:
	/* 0xb9b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ba0:
	/* 0xba0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ba2:
	/* 0xba2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ba5:
	/* 0xba5: je     1234 <generic_tracepoint_event+0x1234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4660ULL;
	}
x86_l_bab:
	/* 0xbab: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_bad:
	/* 0xbad: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bb2:
	/* 0xbb2: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_bb9:
	/* 0xbb9: movabs rax,0x400000081 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869313ULL);
x86_l_bc3:
	/* 0xbc3: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_bc8:
	/* 0xbc8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bcd:
	/* 0xbcd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_bd4:
	/* 0xbd4: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bd9:
	/* 0xbd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bdb:
	/* 0xbdb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bde:
	/* 0xbde: jne    109c <generic_tracepoint_event+0x109c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4252ULL;
	}
x86_l_be4:
	/* 0xbe4: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_bec:
	/* 0xbec: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_bf1:
	/* 0xbf1: jmp    121f <generic_tracepoint_event+0x121f> */
	return 4639ULL;
x86_l_bf6:
	/* 0xbf6: cmp    r13d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 17ULL);
x86_l_bfa:
	/* 0xbfa: jle    d79 <generic_tracepoint_event+0xd79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_d79;
	}
x86_l_c00:
	/* 0xc00: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_c04:
	/* 0xc04: je     f1b <generic_tracepoint_event+0xf1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3867ULL;
	}
x86_l_c0a:
	/* 0xc0a: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_c0e:
	/* 0xc0e: je     c87 <generic_tracepoint_event+0xc87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c87;
	}
x86_l_c10:
	/* 0xc10: cmp    r13d,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 29ULL);
x86_l_c14:
	/* 0xc14: jne    128c <generic_tracepoint_event+0x128c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4748ULL;
	}
x86_l_c1a:
	/* 0xc1a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c1f:
	/* 0xc1f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c24:
	/* 0xc24: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c29:
	/* 0xc29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2b:
	/* 0xc2b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c2e:
	/* 0xc2e: je     11b0 <generic_tracepoint_event+0x11b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4528ULL;
	}
x86_l_c34:
	/* 0xc34: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_c36:
	/* 0xc36: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c3b:
	/* 0xc3b: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_c42:
	/* 0xc42: movabs rax,0x40000006c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869292ULL);
x86_l_c4c:
	/* 0xc4c: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_c51:
	/* 0xc51: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c56:
	/* 0xc56: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_c5d:
	/* 0xc5d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c62:
	/* 0xc62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c64:
	/* 0xc64: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c67:
	/* 0xc67: je     118e <generic_tracepoint_event+0x118e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4494ULL;
	}
x86_l_c6d:
	/* 0xc6d: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_c6f:
	/* 0xc6f: movsx  r12,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_c75:
	/* 0xc75: jmp    128c <generic_tracepoint_event+0x128c> */
	return 4748ULL;
x86_l_c7a:
	/* 0xc7a: lea    eax,[r13-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_c7e:
	/* 0xc7e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c81:
	/* 0xc81: jae    eac <generic_tracepoint_event+0xeac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3756ULL;
	}
x86_l_c87:
	/* 0xc87: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c8c:
	/* 0xc8c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c91:
	/* 0xc91: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c96:
	/* 0xc96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c98:
	/* 0xc98: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c9b:
	/* 0xc9b: je     e6f <generic_tracepoint_event+0xe6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3695ULL;
	}
x86_l_ca1:
	/* 0xca1: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_ca3:
	/* 0xca3: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ca8:
	/* 0xca8: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_caf:
	/* 0xcaf: movabs rax,0x400000045 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869253ULL);
x86_l_cb9:
	/* 0xcb9: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_cbe:
	/* 0xcbe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cc3:
	/* 0xcc3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_cca:
	/* 0xcca: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ccf:
	/* 0xccf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd1:
	/* 0xcd1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cd4:
	/* 0xcd4: je     e4d <generic_tracepoint_event+0xe4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3661ULL;
	}
x86_l_cda:
	/* 0xcda: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_cdc:
	/* 0xcdc: jmp    e6f <generic_tracepoint_event+0xe6f> */
	return 3695ULL;
x86_l_ce1:
	/* 0xce1: cmp    r13d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 38ULL);
x86_l_ce5:
	/* 0xce5: je     1103 <generic_tracepoint_event+0x1103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4355ULL;
	}
x86_l_ceb:
	/* 0xceb: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_cef:
	/* 0xcef: je     fe8 <generic_tracepoint_event+0xfe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4072ULL;
	}
x86_l_cf5:
	/* 0xcf5: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_cf9:
	/* 0xcf9: jne    128c <generic_tracepoint_event+0x128c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4748ULL;
	}
x86_l_cff:
	/* 0xcff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d04:
	/* 0xd04: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d09:
	/* 0xd09: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d0e:
	/* 0xd0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d10:
	/* 0xd10: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d13:
	/* 0xd13: je     1234 <generic_tracepoint_event+0x1234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4660ULL;
	}
x86_l_d19:
	/* 0xd19: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_d1b:
	/* 0xd1b: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d20:
	/* 0xd20: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_d27:
	/* 0xd27: movabs rax,0x4000000a8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869352ULL);
x86_l_d31:
	/* 0xd31: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_d36:
	/* 0xd36: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d3b:
	/* 0xd3b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_d42:
	/* 0xd42: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d47:
	/* 0xd47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d49:
	/* 0xd49: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d4c:
	/* 0xd4c: jne    109c <generic_tracepoint_event+0x109c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4252ULL;
	}
x86_l_d52:
	/* 0xd52: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_d5a:
	/* 0xd5a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d5f:
	/* 0xd5f: jmp    121f <generic_tracepoint_event+0x121f> */
	return 4639ULL;
x86_l_d64:
	/* 0xd64: cmp    r13d,0xfffffff3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967283ULL);
x86_l_d68:
	/* 0xd68: je     dee <generic_tracepoint_event+0xdee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dee;
	}
x86_l_d6e:
	/* 0xd6e: cmp    r13d,0xfffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967284ULL);
x86_l_d72:
	/* 0xd72: je     d89 <generic_tracepoint_event+0xd89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d89;
	}
x86_l_d74:
	/* 0xd74: jmp    128c <generic_tracepoint_event+0x128c> */
	return 4748ULL;
x86_l_d79:
	/* 0xd79: cmp    r13d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 12ULL);
x86_l_d7d:
	/* 0xd7d: je     dee <generic_tracepoint_event+0xdee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dee;
	}
x86_l_d7f:
	/* 0xd7f: cmp    r13d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 13ULL);
x86_l_d83:
	/* 0xd83: jne    128c <generic_tracepoint_event+0x128c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4748ULL;
	}
x86_l_d89:
	/* 0xd89: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d8e:
	/* 0xd8e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d93:
	/* 0xd93: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d98:
	/* 0xd98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d9a:
	/* 0xd9a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d9d:
	/* 0xd9d: je     1287 <generic_tracepoint_event+0x1287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4743ULL;
	}
x86_l_da3:
	/* 0xda3: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_da5:
	/* 0xda5: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_daa:
	/* 0xdaa: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_db1:
	/* 0xdb1: movabs rax,0x40000005e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869278ULL);
x86_l_dbb:
	/* 0xdbb: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_dc0:
	/* 0xdc0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dc5:
	/* 0xdc5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_dcc:
	/* 0xdcc: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dd1:
	/* 0xdd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dd3:
	/* 0xdd3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dd6:
	/* 0xdd6: jne    1156 <generic_tracepoint_event+0x1156> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4438ULL;
	}
x86_l_ddc:
	/* 0xddc: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_de4:
	/* 0xde4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_de9:
	/* 0xde9: jmp    1272 <generic_tracepoint_event+0x1272> */
	return 4722ULL;
x86_l_dee:
	/* 0xdee: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_df3:
	/* 0xdf3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_df8:
	/* 0xdf8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_dfd:
	/* 0xdfd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dff:
	/* 0xdff: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e02:
	/* 0xe02: je     1184 <generic_tracepoint_event+0x1184> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4484ULL;
	}
x86_l_e08:
	/* 0xe08: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_e0a:
	/* 0xe0a: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e0f:
	/* 0xe0f: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_e16:
	/* 0xe16: movabs rax,0x400000056 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869270ULL);
x86_l_e20:
	/* 0xe20: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e25:
	/* 0xe25: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e2a:
	/* 0xe2a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_e31:
	/* 0xe31: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e36:
	/* 0xe36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e38:
	/* 0xe38: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e3b:
	/* 0xe3b: je     1162 <generic_tracepoint_event+0x1162> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4450ULL;
	}
	return 3649ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3649ULL: goto x86_l_e41;
	case 3651ULL: goto x86_l_e43;
	case 3656ULL: goto x86_l_e48;
	case 3661ULL: goto x86_l_e4d;
	case 3669ULL: goto x86_l_e55;
	case 3674ULL: goto x86_l_e5a;
	case 3681ULL: goto x86_l_e61;
	case 3686ULL: goto x86_l_e66;
	case 3691ULL: goto x86_l_e6b;
	case 3693ULL: goto x86_l_e6d;
	case 3695ULL: goto x86_l_e6f;
	case 3700ULL: goto x86_l_e74;
	case 3704ULL: goto x86_l_e78;
	case 3710ULL: goto x86_l_e7e;
	case 3715ULL: goto x86_l_e83;
	case 3717ULL: goto x86_l_e85;
	case 3721ULL: goto x86_l_e89;
	case 3726ULL: goto x86_l_e8e;
	case 3731ULL: goto x86_l_e93;
	case 3736ULL: goto x86_l_e98;
	case 3738ULL: goto x86_l_e9a;
	case 3742ULL: goto x86_l_e9e;
	case 3745ULL: goto x86_l_ea1;
	case 3748ULL: goto x86_l_ea4;
	case 3751ULL: goto x86_l_ea7;
	case 3756ULL: goto x86_l_eac;
	case 3760ULL: goto x86_l_eb0;
	case 3766ULL: goto x86_l_eb6;
	case 3771ULL: goto x86_l_ebb;
	case 3776ULL: goto x86_l_ec0;
	case 3781ULL: goto x86_l_ec5;
	case 3783ULL: goto x86_l_ec7;
	case 3786ULL: goto x86_l_eca;
	case 3792ULL: goto x86_l_ed0;
	case 3794ULL: goto x86_l_ed2;
	case 3799ULL: goto x86_l_ed7;
	case 3806ULL: goto x86_l_ede;
	case 3816ULL: goto x86_l_ee8;
	case 3821ULL: goto x86_l_eed;
	case 3826ULL: goto x86_l_ef2;
	case 3833ULL: goto x86_l_ef9;
	case 3838ULL: goto x86_l_efe;
	case 3840ULL: goto x86_l_f00;
	case 3843ULL: goto x86_l_f03;
	case 3849ULL: goto x86_l_f09;
	case 3857ULL: goto x86_l_f11;
	case 3862ULL: goto x86_l_f16;
	case 3867ULL: goto x86_l_f1b;
	case 3870ULL: goto x86_l_f1e;
	case 3875ULL: goto x86_l_f23;
	case 3880ULL: goto x86_l_f28;
	case 3885ULL: goto x86_l_f2d;
	case 3890ULL: goto x86_l_f32;
	case 3892ULL: goto x86_l_f34;
	case 3895ULL: goto x86_l_f37;
	case 3901ULL: goto x86_l_f3d;
	case 3903ULL: goto x86_l_f3f;
	case 3908ULL: goto x86_l_f44;
	case 3915ULL: goto x86_l_f4b;
	case 3925ULL: goto x86_l_f55;
	case 3930ULL: goto x86_l_f5a;
	case 3935ULL: goto x86_l_f5f;
	case 3942ULL: goto x86_l_f66;
	case 3947ULL: goto x86_l_f6b;
	case 3949ULL: goto x86_l_f6d;
	case 3952ULL: goto x86_l_f70;
	case 3958ULL: goto x86_l_f76;
	case 3966ULL: goto x86_l_f7e;
	case 3971ULL: goto x86_l_f83;
	case 3976ULL: goto x86_l_f88;
	case 3981ULL: goto x86_l_f8d;
	case 3986ULL: goto x86_l_f92;
	case 3991ULL: goto x86_l_f97;
	case 3993ULL: goto x86_l_f99;
	case 3996ULL: goto x86_l_f9c;
	case 4002ULL: goto x86_l_fa2;
	case 4004ULL: goto x86_l_fa4;
	case 4009ULL: goto x86_l_fa9;
	case 4016ULL: goto x86_l_fb0;
	case 4026ULL: goto x86_l_fba;
	case 4031ULL: goto x86_l_fbf;
	case 4036ULL: goto x86_l_fc4;
	case 4043ULL: goto x86_l_fcb;
	case 4048ULL: goto x86_l_fd0;
	case 4050ULL: goto x86_l_fd2;
	case 4053ULL: goto x86_l_fd5;
	case 4059ULL: goto x86_l_fdb;
	case 4061ULL: goto x86_l_fdd;
	case 4067ULL: goto x86_l_fe3;
	case 4072ULL: goto x86_l_fe8;
	case 4077ULL: goto x86_l_fed;
	case 4082ULL: goto x86_l_ff2;
	case 4087ULL: goto x86_l_ff7;
	case 4089ULL: goto x86_l_ff9;
	case 4092ULL: goto x86_l_ffc;
	case 4098ULL: goto x86_l_1002;
	case 4100ULL: goto x86_l_1004;
	case 4105ULL: goto x86_l_1009;
	case 4112ULL: goto x86_l_1010;
	case 4122ULL: goto x86_l_101a;
	case 4127ULL: goto x86_l_101f;
	case 4132ULL: goto x86_l_1024;
	case 4139ULL: goto x86_l_102b;
	case 4144ULL: goto x86_l_1030;
	case 4146ULL: goto x86_l_1032;
	case 4149ULL: goto x86_l_1035;
	case 4151ULL: goto x86_l_1037;
	case 4159ULL: goto x86_l_103f;
	case 4164ULL: goto x86_l_1044;
	case 4169ULL: goto x86_l_1049;
	case 4174ULL: goto x86_l_104e;
	case 4179ULL: goto x86_l_1053;
	case 4184ULL: goto x86_l_1058;
	case 4186ULL: goto x86_l_105a;
	case 4189ULL: goto x86_l_105d;
	case 4195ULL: goto x86_l_1063;
	case 4197ULL: goto x86_l_1065;
	case 4202ULL: goto x86_l_106a;
	case 4209ULL: goto x86_l_1071;
	case 4219ULL: goto x86_l_107b;
	case 4224ULL: goto x86_l_1080;
	case 4229ULL: goto x86_l_1085;
	case 4236ULL: goto x86_l_108c;
	case 4241ULL: goto x86_l_1091;
	case 4243ULL: goto x86_l_1093;
	case 4246ULL: goto x86_l_1096;
	case 4252ULL: goto x86_l_109c;
	case 4254ULL: goto x86_l_109e;
	case 4259ULL: goto x86_l_10a3;
	case 4264ULL: goto x86_l_10a8;
	case 4269ULL: goto x86_l_10ad;
	case 4274ULL: goto x86_l_10b2;
	case 4276ULL: goto x86_l_10b4;
	case 4279ULL: goto x86_l_10b7;
	case 4285ULL: goto x86_l_10bd;
	case 4287ULL: goto x86_l_10bf;
	case 4292ULL: goto x86_l_10c4;
	case 4299ULL: goto x86_l_10cb;
	case 4309ULL: goto x86_l_10d5;
	case 4314ULL: goto x86_l_10da;
	case 4319ULL: goto x86_l_10df;
	case 4326ULL: goto x86_l_10e6;
	case 4331ULL: goto x86_l_10eb;
	case 4333ULL: goto x86_l_10ed;
	case 4336ULL: goto x86_l_10f0;
	case 4342ULL: goto x86_l_10f6;
	case 4344ULL: goto x86_l_10f8;
	case 4350ULL: goto x86_l_10fe;
	case 4355ULL: goto x86_l_1103;
	case 4360ULL: goto x86_l_1108;
	case 4365ULL: goto x86_l_110d;
	case 4370ULL: goto x86_l_1112;
	case 4372ULL: goto x86_l_1114;
	case 4375ULL: goto x86_l_1117;
	case 4381ULL: goto x86_l_111d;
	case 4383ULL: goto x86_l_111f;
	case 4388ULL: goto x86_l_1124;
	case 4395ULL: goto x86_l_112b;
	case 4405ULL: goto x86_l_1135;
	case 4410ULL: goto x86_l_113a;
	case 4415ULL: goto x86_l_113f;
	case 4422ULL: goto x86_l_1146;
	case 4427ULL: goto x86_l_114b;
	case 4429ULL: goto x86_l_114d;
	case 4432ULL: goto x86_l_1150;
	case 4438ULL: goto x86_l_1156;
	case 4440ULL: goto x86_l_1158;
	case 4445ULL: goto x86_l_115d;
	case 4450ULL: goto x86_l_1162;
	case 4458ULL: goto x86_l_116a;
	case 4463ULL: goto x86_l_116f;
	case 4470ULL: goto x86_l_1176;
	case 4475ULL: goto x86_l_117b;
	case 4480ULL: goto x86_l_1180;
	case 4482ULL: goto x86_l_1182;
	case 4484ULL: goto x86_l_1184;
	case 4489ULL: goto x86_l_1189;
	case 4494ULL: goto x86_l_118e;
	case 4502ULL: goto x86_l_1196;
	case 4507ULL: goto x86_l_119b;
	case 4514ULL: goto x86_l_11a2;
	case 4519ULL: goto x86_l_11a7;
	case 4524ULL: goto x86_l_11ac;
	case 4526ULL: goto x86_l_11ae;
	case 4528ULL: goto x86_l_11b0;
	case 4534ULL: goto x86_l_11b6;
	case 4539ULL: goto x86_l_11bb;
	case 4547ULL: goto x86_l_11c3;
	case 4552ULL: goto x86_l_11c8;
	case 4559ULL: goto x86_l_11cf;
	case 4564ULL: goto x86_l_11d4;
	case 4569ULL: goto x86_l_11d9;
	case 4571ULL: goto x86_l_11db;
	case 4573ULL: goto x86_l_11dd;
	case 4579ULL: goto x86_l_11e3;
	case 4584ULL: goto x86_l_11e8;
	case 4592ULL: goto x86_l_11f0;
	case 4597ULL: goto x86_l_11f5;
	case 4604ULL: goto x86_l_11fc;
	case 4609ULL: goto x86_l_1201;
	case 4614ULL: goto x86_l_1206;
	case 4616ULL: goto x86_l_1208;
	case 4618ULL: goto x86_l_120a;
	case 4624ULL: goto x86_l_1210;
	case 4626ULL: goto x86_l_1212;
	case 4634ULL: goto x86_l_121a;
	case 4639ULL: goto x86_l_121f;
	case 4646ULL: goto x86_l_1226;
	case 4651ULL: goto x86_l_122b;
	case 4656ULL: goto x86_l_1230;
	case 4658ULL: goto x86_l_1232;
	case 4660ULL: goto x86_l_1234;
	case 4665ULL: goto x86_l_1239;
	case 4667ULL: goto x86_l_123b;
	case 4675ULL: goto x86_l_1243;
	case 4680ULL: goto x86_l_1248;
	case 4687ULL: goto x86_l_124f;
	case 4692ULL: goto x86_l_1254;
	case 4697ULL: goto x86_l_1259;
	case 4699ULL: goto x86_l_125b;
	case 4701ULL: goto x86_l_125d;
	case 4707ULL: goto x86_l_1263;
	case 4709ULL: goto x86_l_1265;
	case 4717ULL: goto x86_l_126d;
	case 4722ULL: goto x86_l_1272;
	case 4729ULL: goto x86_l_1279;
	case 4734ULL: goto x86_l_127e;
	case 4739ULL: goto x86_l_1283;
	case 4741ULL: goto x86_l_1285;
	case 4743ULL: goto x86_l_1287;
	case 4748ULL: goto x86_l_128c;
	case 4755ULL: goto x86_l_1293;
	case 4760ULL: goto x86_l_1298;
	case 4764ULL: goto x86_l_129c;
	case 4767ULL: goto x86_l_129f;
	case 4770ULL: goto x86_l_12a2;
	case 4774ULL: goto x86_l_12a6;
	case 4776ULL: goto x86_l_12a8;
	case 4780ULL: goto x86_l_12ac;
	case 4786ULL: goto x86_l_12b2;
	case 4790ULL: goto x86_l_12b6;
	case 4796ULL: goto x86_l_12bc;
	case 4800ULL: goto x86_l_12c0;
	case 4806ULL: goto x86_l_12c6;
	case 4810ULL: goto x86_l_12ca;
	case 4816ULL: goto x86_l_12d0;
	case 4820ULL: goto x86_l_12d4;
	case 4826ULL: goto x86_l_12da;
	case 4831ULL: goto x86_l_12df;
	case 4835ULL: goto x86_l_12e3;
	case 4841ULL: goto x86_l_12e9;
	case 4845ULL: goto x86_l_12ed;
	case 4851ULL: goto x86_l_12f3;
	case 4855ULL: goto x86_l_12f7;
	case 4861ULL: goto x86_l_12fd;
	case 4865ULL: goto x86_l_1301;
	case 4871ULL: goto x86_l_1307;
	case 4875ULL: goto x86_l_130b;
	case 4881ULL: goto x86_l_1311;
	case 4886ULL: goto x86_l_1316;
	case 4891ULL: goto x86_l_131b;
	case 4896ULL: goto x86_l_1320;
	case 4898ULL: goto x86_l_1322;
	case 4901ULL: goto x86_l_1325;
	case 4907ULL: goto x86_l_132b;
	case 4909ULL: goto x86_l_132d;
	case 4914ULL: goto x86_l_1332;
	case 4921ULL: goto x86_l_1339;
	case 4931ULL: goto x86_l_1343;
	case 4936ULL: goto x86_l_1348;
	case 4941ULL: goto x86_l_134d;
	case 4948ULL: goto x86_l_1354;
	case 4953ULL: goto x86_l_1359;
	case 4955ULL: goto x86_l_135b;
	case 4958ULL: goto x86_l_135e;
	case 4964ULL: goto x86_l_1364;
	case 4966ULL: goto x86_l_1366;
	case 4972ULL: goto x86_l_136c;
	case 4977ULL: goto x86_l_1371;
	case 4981ULL: goto x86_l_1375;
	case 4987ULL: goto x86_l_137b;
	case 4991ULL: goto x86_l_137f;
	case 4994ULL: goto x86_l_1382;
	case 5000ULL: goto x86_l_1388;
	case 5004ULL: goto x86_l_138c;
	case 5010ULL: goto x86_l_1392;
	case 5015ULL: goto x86_l_1397;
	case 5020ULL: goto x86_l_139c;
	case 5025ULL: goto x86_l_13a1;
	case 5027ULL: goto x86_l_13a3;
	case 5030ULL: goto x86_l_13a6;
	case 5036ULL: goto x86_l_13ac;
	case 5038ULL: goto x86_l_13ae;
	case 5043ULL: goto x86_l_13b3;
	case 5050ULL: goto x86_l_13ba;
	case 5060ULL: goto x86_l_13c4;
	case 5065ULL: goto x86_l_13c9;
	case 5070ULL: goto x86_l_13ce;
	case 5077ULL: goto x86_l_13d5;
	case 5082ULL: goto x86_l_13da;
	case 5084ULL: goto x86_l_13dc;
	case 5087ULL: goto x86_l_13df;
	case 5093ULL: goto x86_l_13e5;
	case 5101ULL: goto x86_l_13ed;
	case 5106ULL: goto x86_l_13f2;
	case 5111ULL: goto x86_l_13f7;
	case 5115ULL: goto x86_l_13fb;
	case 5121ULL: goto x86_l_1401;
	case 5125ULL: goto x86_l_1405;
	case 5131ULL: goto x86_l_140b;
	case 5135ULL: goto x86_l_140f;
	case 5137ULL: goto x86_l_1411;
	case 5141ULL: goto x86_l_1415;
	case 5147ULL: goto x86_l_141b;
	case 5152ULL: goto x86_l_1420;
	case 5157ULL: goto x86_l_1425;
	case 5162ULL: goto x86_l_142a;
	case 5164ULL: goto x86_l_142c;
	case 5167ULL: goto x86_l_142f;
	case 5173ULL: goto x86_l_1435;
	case 5175ULL: goto x86_l_1437;
	case 5180ULL: goto x86_l_143c;
	case 5187ULL: goto x86_l_1443;
	case 5197ULL: goto x86_l_144d;
	case 5202ULL: goto x86_l_1452;
	case 5207ULL: goto x86_l_1457;
	case 5214ULL: goto x86_l_145e;
	case 5219ULL: goto x86_l_1463;
	case 5221ULL: goto x86_l_1465;
	case 5224ULL: goto x86_l_1468;
	case 5230ULL: goto x86_l_146e;
	case 5232ULL: goto x86_l_1470;
	case 5238ULL: goto x86_l_1476;
	case 5243ULL: goto x86_l_147b;
	case 5247ULL: goto x86_l_147f;
	case 5250ULL: goto x86_l_1482;
	case 5256ULL: goto x86_l_1488;
	case 5261ULL: goto x86_l_148d;
	case 5266ULL: goto x86_l_1492;
	case 5271ULL: goto x86_l_1497;
	case 5273ULL: goto x86_l_1499;
	case 5276ULL: goto x86_l_149c;
	case 5282ULL: goto x86_l_14a2;
	case 5284ULL: goto x86_l_14a4;
	case 5289ULL: goto x86_l_14a9;
	case 5296ULL: goto x86_l_14b0;
	case 5306ULL: goto x86_l_14ba;
	case 5311ULL: goto x86_l_14bf;
	case 5316ULL: goto x86_l_14c4;
	case 5323ULL: goto x86_l_14cb;
	case 5328ULL: goto x86_l_14d0;
	case 5330ULL: goto x86_l_14d2;
	case 5333ULL: goto x86_l_14d5;
	case 5339ULL: goto x86_l_14db;
	case 5341ULL: goto x86_l_14dd;
	case 5346ULL: goto x86_l_14e2;
	case 5350ULL: goto x86_l_14e6;
	case 5356ULL: goto x86_l_14ec;
	case 5360ULL: goto x86_l_14f0;
	case 5366ULL: goto x86_l_14f6;
	case 5370ULL: goto x86_l_14fa;
	case 5376ULL: goto x86_l_1500;
	case 5381ULL: goto x86_l_1505;
	case 5386ULL: goto x86_l_150a;
	case 5391ULL: goto x86_l_150f;
	case 5393ULL: goto x86_l_1511;
	case 5396ULL: goto x86_l_1514;
	case 5402ULL: goto x86_l_151a;
	case 5404ULL: goto x86_l_151c;
	case 5409ULL: goto x86_l_1521;
	case 5416ULL: goto x86_l_1528;
	case 5426ULL: goto x86_l_1532;
	case 5431ULL: goto x86_l_1537;
	case 5436ULL: goto x86_l_153c;
	case 5443ULL: goto x86_l_1543;
	case 5448ULL: goto x86_l_1548;
	case 5450ULL: goto x86_l_154a;
	case 5453ULL: goto x86_l_154d;
	case 5459ULL: goto x86_l_1553;
	case 5467ULL: goto x86_l_155b;
	case 5472ULL: goto x86_l_1560;
	case 5477ULL: goto x86_l_1565;
	case 5481ULL: goto x86_l_1569;
	case 5487ULL: goto x86_l_156f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e41:
	/* 0xe41: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_e43:
	/* 0xe43: movsxd r12,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_e48:
	/* 0xe48: jmp    128c <generic_tracepoint_event+0x128c> */
	goto x86_l_128c;
x86_l_e4d:
	/* 0xe4d: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_e55:
	/* 0xe55: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e5a:
	/* 0xe5a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_e61:
	/* 0xe61: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e66:
	/* 0xe66: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e6b:
	/* 0xe6b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e6d:
	/* 0xe6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e6f:
	/* 0xe6f: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e74:
	/* 0xe74: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_e78:
	/* 0xe78: jne    128c <generic_tracepoint_event+0x128c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_128c;
	}
x86_l_e7e:
	/* 0xe7e: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_e83:
	/* 0xe83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e85:
	/* 0xe85: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e89:
	/* 0xe89: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e8e:
	/* 0xe8e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e93:
	/* 0xe93: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e98:
	/* 0xe98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e9a:
	/* 0xe9a: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e9e:
	/* 0xe9e: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_ea1:
	/* 0xea1: shl    eax,0x1e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 30ULL);
x86_l_ea4:
	/* 0xea4: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_ea7:
	/* 0xea7: jmp    128c <generic_tracepoint_event+0x128c> */
	goto x86_l_128c;
x86_l_eac:
	/* 0xeac: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_eb0:
	/* 0xeb0: jne    128c <generic_tracepoint_event+0x128c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_128c;
	}
x86_l_eb6:
	/* 0xeb6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ebb:
	/* 0xebb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ec0:
	/* 0xec0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ec5:
	/* 0xec5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ec7:
	/* 0xec7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_eca:
	/* 0xeca: je     1234 <generic_tracepoint_event+0x1234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1234;
	}
x86_l_ed0:
	/* 0xed0: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_ed2:
	/* 0xed2: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ed7:
	/* 0xed7: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_ede:
	/* 0xede: movabs rax,0x40000009a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869338ULL);
x86_l_ee8:
	/* 0xee8: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_eed:
	/* 0xeed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ef2:
	/* 0xef2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_ef9:
	/* 0xef9: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_efe:
	/* 0xefe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f00:
	/* 0xf00: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f03:
	/* 0xf03: jne    109c <generic_tracepoint_event+0x109c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_109c;
	}
x86_l_f09:
	/* 0xf09: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_f11:
	/* 0xf11: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f16:
	/* 0xf16: jmp    121f <generic_tracepoint_event+0x121f> */
	goto x86_l_121f;
x86_l_f1b:
	/* 0xf1b: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_f1e:
	/* 0xf1e: jmp    128c <generic_tracepoint_event+0x128c> */
	goto x86_l_128c;
x86_l_f23:
	/* 0xf23: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f28:
	/* 0xf28: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f2d:
	/* 0xf2d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f32:
	/* 0xf32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f34:
	/* 0xf34: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f37:
	/* 0xf37: je     1234 <generic_tracepoint_event+0x1234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1234;
	}
x86_l_f3d:
	/* 0xf3d: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_f3f:
	/* 0xf3f: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f44:
	/* 0xf44: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_f4b:
	/* 0xf4b: movabs rax,0x400000093 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869331ULL);
x86_l_f55:
	/* 0xf55: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f5a:
	/* 0xf5a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f5f:
	/* 0xf5f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_f66:
	/* 0xf66: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f6b:
	/* 0xf6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f6d:
	/* 0xf6d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f70:
	/* 0xf70: jne    109c <generic_tracepoint_event+0x109c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_109c;
	}
x86_l_f76:
	/* 0xf76: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_f7e:
	/* 0xf7e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f83:
	/* 0xf83: jmp    121f <generic_tracepoint_event+0x121f> */
	goto x86_l_121f;
x86_l_f88:
	/* 0xf88: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f8d:
	/* 0xf8d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f92:
	/* 0xf92: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_f97:
	/* 0xf97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f99:
	/* 0xf99: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f9c:
	/* 0xf9c: je     11dd <generic_tracepoint_event+0x11dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11dd;
	}
x86_l_fa2:
	/* 0xfa2: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_fa4:
	/* 0xfa4: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fa9:
	/* 0xfa9: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_fb0:
	/* 0xfb0: movabs rax,0x40000007a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869306ULL);
x86_l_fba:
	/* 0xfba: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_fbf:
	/* 0xfbf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fc4:
	/* 0xfc4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_fcb:
	/* 0xfcb: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fd0:
	/* 0xfd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fd2:
	/* 0xfd2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fd5:
	/* 0xfd5: je     11bb <generic_tracepoint_event+0x11bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11bb;
	}
x86_l_fdb:
	/* 0xfdb: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_fdd:
	/* 0xfdd: movsx  r12,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_fe3:
	/* 0xfe3: jmp    128c <generic_tracepoint_event+0x128c> */
	goto x86_l_128c;
x86_l_fe8:
	/* 0xfe8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fed:
	/* 0xfed: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ff2:
	/* 0xff2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ff7:
	/* 0xff7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff9:
	/* 0xff9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ffc:
	/* 0xffc: je     1234 <generic_tracepoint_event+0x1234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1234;
	}
x86_l_1002:
	/* 0x1002: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1004:
	/* 0x1004: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1009:
	/* 0x1009: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1010:
	/* 0x1010: movabs rax,0x4000000a1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869345ULL);
x86_l_101a:
	/* 0x101a: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_101f:
	/* 0x101f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1024:
	/* 0x1024: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_102b:
	/* 0x102b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1030:
	/* 0x1030: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1032:
	/* 0x1032: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1035:
	/* 0x1035: jne    109c <generic_tracepoint_event+0x109c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_109c;
	}
x86_l_1037:
	/* 0x1037: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_103f:
	/* 0x103f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1044:
	/* 0x1044: jmp    121f <generic_tracepoint_event+0x121f> */
	goto x86_l_121f;
x86_l_1049:
	/* 0x1049: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_104e:
	/* 0x104e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1053:
	/* 0x1053: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1058:
	/* 0x1058: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_105a:
	/* 0x105a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_105d:
	/* 0x105d: je     1234 <generic_tracepoint_event+0x1234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1234;
	}
x86_l_1063:
	/* 0x1063: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1065:
	/* 0x1065: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_106a:
	/* 0x106a: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1071:
	/* 0x1071: movabs rax,0x40000004e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869262ULL);
x86_l_107b:
	/* 0x107b: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1080:
	/* 0x1080: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1085:
	/* 0x1085: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_108c:
	/* 0x108c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1091:
	/* 0x1091: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1093:
	/* 0x1093: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1096:
	/* 0x1096: je     1212 <generic_tracepoint_event+0x1212> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1212;
	}
x86_l_109c:
	/* 0x109c: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_109e:
	/* 0x109e: jmp    1234 <generic_tracepoint_event+0x1234> */
	goto x86_l_1234;
x86_l_10a3:
	/* 0x10a3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10a8:
	/* 0x10a8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10ad:
	/* 0x10ad: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_10b2:
	/* 0x10b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b4:
	/* 0x10b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10b7:
	/* 0x10b7: je     125d <generic_tracepoint_event+0x125d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_125d;
	}
x86_l_10bd:
	/* 0x10bd: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_10bf:
	/* 0x10bf: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10c4:
	/* 0x10c4: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_10cb:
	/* 0x10cb: movabs rax,0x400000065 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869285ULL);
x86_l_10d5:
	/* 0x10d5: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_10da:
	/* 0x10da: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10df:
	/* 0x10df: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_10e6:
	/* 0x10e6: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10eb:
	/* 0x10eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ed:
	/* 0x10ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10f0:
	/* 0x10f0: je     123b <generic_tracepoint_event+0x123b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_123b;
	}
x86_l_10f6:
	/* 0x10f6: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_10f8:
	/* 0x10f8: movzx  r12d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_10fe:
	/* 0x10fe: jmp    128c <generic_tracepoint_event+0x128c> */
	goto x86_l_128c;
x86_l_1103:
	/* 0x1103: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1108:
	/* 0x1108: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_110d:
	/* 0x110d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1112:
	/* 0x1112: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1114:
	/* 0x1114: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1117:
	/* 0x1117: je     1287 <generic_tracepoint_event+0x1287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1287;
	}
x86_l_111d:
	/* 0x111d: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_111f:
	/* 0x111f: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1124:
	/* 0x1124: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_112b:
	/* 0x112b: movabs rax,0x400000088 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869320ULL);
x86_l_1135:
	/* 0x1135: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_113a:
	/* 0x113a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_113f:
	/* 0x113f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1146:
	/* 0x1146: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_114b:
	/* 0x114b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_114d:
	/* 0x114d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1150:
	/* 0x1150: je     1265 <generic_tracepoint_event+0x1265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1265;
	}
x86_l_1156:
	/* 0x1156: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1158:
	/* 0x1158: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_115d:
	/* 0x115d: jmp    128c <generic_tracepoint_event+0x128c> */
	goto x86_l_128c;
x86_l_1162:
	/* 0x1162: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_116a:
	/* 0x116a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_116f:
	/* 0x116f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1176:
	/* 0x1176: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_117b:
	/* 0x117b: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1180:
	/* 0x1180: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1182:
	/* 0x1182: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1184:
	/* 0x1184: movsxd r12,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1189:
	/* 0x1189: jmp    128c <generic_tracepoint_event+0x128c> */
	goto x86_l_128c;
x86_l_118e:
	/* 0x118e: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1196:
	/* 0x1196: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_119b:
	/* 0x119b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_11a2:
	/* 0x11a2: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11a7:
	/* 0x11a7: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11ac:
	/* 0x11ac: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11ae:
	/* 0x11ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11b0:
	/* 0x11b0: movsx  r12,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_11b6:
	/* 0x11b6: jmp    128c <generic_tracepoint_event+0x128c> */
	goto x86_l_128c;
x86_l_11bb:
	/* 0x11bb: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_11c3:
	/* 0x11c3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_11c8:
	/* 0x11c8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_11cf:
	/* 0x11cf: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11d4:
	/* 0x11d4: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11d9:
	/* 0x11d9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11db:
	/* 0x11db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11dd:
	/* 0x11dd: movsx  r12,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_11e3:
	/* 0x11e3: jmp    128c <generic_tracepoint_event+0x128c> */
	goto x86_l_128c;
x86_l_11e8:
	/* 0x11e8: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_11f0:
	/* 0x11f0: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_11f5:
	/* 0x11f5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_11fc:
	/* 0x11fc: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1201:
	/* 0x1201: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1206:
	/* 0x1206: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1208:
	/* 0x1208: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_120a:
	/* 0x120a: movzx  r12d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1210:
	/* 0x1210: jmp    128c <generic_tracepoint_event+0x128c> */
	goto x86_l_128c;
x86_l_1212:
	/* 0x1212: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_121a:
	/* 0x121a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_121f:
	/* 0x121f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1226:
	/* 0x1226: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_122b:
	/* 0x122b: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1230:
	/* 0x1230: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1232:
	/* 0x1232: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1234:
	/* 0x1234: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1239:
	/* 0x1239: jmp    128c <generic_tracepoint_event+0x128c> */
	goto x86_l_128c;
x86_l_123b:
	/* 0x123b: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1243:
	/* 0x1243: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1248:
	/* 0x1248: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_124f:
	/* 0x124f: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1254:
	/* 0x1254: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1259:
	/* 0x1259: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_125b:
	/* 0x125b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_125d:
	/* 0x125d: movzx  r12d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1263:
	/* 0x1263: jmp    128c <generic_tracepoint_event+0x128c> */
	goto x86_l_128c;
x86_l_1265:
	/* 0x1265: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_126d:
	/* 0x126d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1272:
	/* 0x1272: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1279:
	/* 0x1279: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_127e:
	/* 0x127e: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1283:
	/* 0x1283: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1285:
	/* 0x1285: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1287:
	/* 0x1287: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_128c:
	/* 0x128c: mov    QWORD PTR [r14+0x5e58],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24152ULL);
x86_l_1293:
	/* 0x1293: movzx  edx,WORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 52ULL);
x86_l_1298:
	/* 0x1298: mov    r13d,DWORD PTR [r15+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_129c:
	/* 0x129c: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_129f:
	/* 0x129f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12a2:
	/* 0x12a2: cmp    r13d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 11ULL);
x86_l_12a6:
	/* 0x12a6: jg     12df <generic_tracepoint_event+0x12df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_12df;
	}
x86_l_12a8:
	/* 0x12a8: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_12ac:
	/* 0x12ac: jle    1371 <generic_tracepoint_event+0x1371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1371;
	}
x86_l_12b2:
	/* 0x12b2: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_12b6:
	/* 0x12b6: jg     147b <generic_tracepoint_event+0x147b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_147b;
	}
x86_l_12bc:
	/* 0x12bc: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_12c0:
	/* 0x12c0: je     184a <generic_tracepoint_event+0x184a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6218ULL;
	}
x86_l_12c6:
	/* 0x12c6: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_12ca:
	/* 0x12ca: je     1724 <generic_tracepoint_event+0x1724> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5924ULL;
	}
x86_l_12d0:
	/* 0x12d0: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_12d4:
	/* 0x12d4: je     1392 <generic_tracepoint_event+0x1392> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1392;
	}
x86_l_12da:
	/* 0x12da: jmp    1a8d <generic_tracepoint_event+0x1a8d> */
	return 6797ULL;
x86_l_12df:
	/* 0x12df: cmp    r13d,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 29ULL);
x86_l_12e3:
	/* 0x12e3: jle    13f7 <generic_tracepoint_event+0x13f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_13f7;
	}
x86_l_12e9:
	/* 0x12e9: cmp    r13d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 37ULL);
x86_l_12ed:
	/* 0x12ed: jg     14e2 <generic_tracepoint_event+0x14e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_14e2;
	}
x86_l_12f3:
	/* 0x12f3: cmp    r13d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 30ULL);
x86_l_12f7:
	/* 0x12f7: je     18a4 <generic_tracepoint_event+0x18a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6308ULL;
	}
x86_l_12fd:
	/* 0x12fd: cmp    r13d,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 31ULL);
x86_l_1301:
	/* 0x1301: je     1789 <generic_tracepoint_event+0x1789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6025ULL;
	}
x86_l_1307:
	/* 0x1307: cmp    r13d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 32ULL);
x86_l_130b:
	/* 0x130b: jne    1a8d <generic_tracepoint_event+0x1a8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6797ULL;
	}
x86_l_1311:
	/* 0x1311: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1316:
	/* 0x1316: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_131b:
	/* 0x131b: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1320:
	/* 0x1320: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1322:
	/* 0x1322: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1325:
	/* 0x1325: je     1a0b <generic_tracepoint_event+0x1a0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6667ULL;
	}
x86_l_132b:
	/* 0x132b: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_132d:
	/* 0x132d: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1332:
	/* 0x1332: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1339:
	/* 0x1339: movabs rax,0x400000073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869299ULL);
x86_l_1343:
	/* 0x1343: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1348:
	/* 0x1348: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_134d:
	/* 0x134d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1354:
	/* 0x1354: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1359:
	/* 0x1359: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_135b:
	/* 0x135b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_135e:
	/* 0x135e: je     19e9 <generic_tracepoint_event+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1364:
	/* 0x1364: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1366:
	/* 0x1366: movzx  r12d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_136c:
	/* 0x136c: jmp    1a8d <generic_tracepoint_event+0x1a8d> */
	return 6797ULL;
x86_l_1371:
	/* 0x1371: cmp    r13d,0xfffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967284ULL);
x86_l_1375:
	/* 0x1375: jle    1565 <generic_tracepoint_event+0x1565> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1565;
	}
x86_l_137b:
	/* 0x137b: lea    eax,[r13+0xb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_137f:
	/* 0x137f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1382:
	/* 0x1382: jb     1488 <generic_tracepoint_event+0x1488> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1488;
	}
x86_l_1388:
	/* 0x1388: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_138c:
	/* 0x138c: jne    1a8d <generic_tracepoint_event+0x1a8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6797ULL;
	}
x86_l_1392:
	/* 0x1392: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1397:
	/* 0x1397: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_139c:
	/* 0x139c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13a1:
	/* 0x13a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a3:
	/* 0x13a3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13a6:
	/* 0x13a6: je     1a35 <generic_tracepoint_event+0x1a35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6709ULL;
	}
x86_l_13ac:
	/* 0x13ac: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_13ae:
	/* 0x13ae: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13b3:
	/* 0x13b3: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_13ba:
	/* 0x13ba: movabs rax,0x400000081 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869313ULL);
x86_l_13c4:
	/* 0x13c4: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_13c9:
	/* 0x13c9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13ce:
	/* 0x13ce: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_13d5:
	/* 0x13d5: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13da:
	/* 0x13da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13dc:
	/* 0x13dc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13df:
	/* 0x13df: jne    189d <generic_tracepoint_event+0x189d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6301ULL;
	}
x86_l_13e5:
	/* 0x13e5: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_13ed:
	/* 0x13ed: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13f2:
	/* 0x13f2: jmp    1a20 <generic_tracepoint_event+0x1a20> */
	return 6688ULL;
x86_l_13f7:
	/* 0x13f7: cmp    r13d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 17ULL);
x86_l_13fb:
	/* 0x13fb: jle    157a <generic_tracepoint_event+0x157a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5498ULL;
	}
x86_l_1401:
	/* 0x1401: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_1405:
	/* 0x1405: je     171c <generic_tracepoint_event+0x171c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5916ULL;
	}
x86_l_140b:
	/* 0x140b: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_140f:
	/* 0x140f: je     1488 <generic_tracepoint_event+0x1488> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1488;
	}
x86_l_1411:
	/* 0x1411: cmp    r13d,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 29ULL);
x86_l_1415:
	/* 0x1415: jne    1a8d <generic_tracepoint_event+0x1a8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6797ULL;
	}
x86_l_141b:
	/* 0x141b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1420:
	/* 0x1420: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1425:
	/* 0x1425: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_142a:
	/* 0x142a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_142c:
	/* 0x142c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_142f:
	/* 0x142f: je     19b1 <generic_tracepoint_event+0x19b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6577ULL;
	}
x86_l_1435:
	/* 0x1435: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1437:
	/* 0x1437: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_143c:
	/* 0x143c: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1443:
	/* 0x1443: movabs rax,0x40000006c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869292ULL);
x86_l_144d:
	/* 0x144d: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1452:
	/* 0x1452: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1457:
	/* 0x1457: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_145e:
	/* 0x145e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1463:
	/* 0x1463: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1465:
	/* 0x1465: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1468:
	/* 0x1468: je     198f <generic_tracepoint_event+0x198f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6543ULL;
	}
x86_l_146e:
	/* 0x146e: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1470:
	/* 0x1470: movsx  r12,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1476:
	/* 0x1476: jmp    1a8d <generic_tracepoint_event+0x1a8d> */
	return 6797ULL;
x86_l_147b:
	/* 0x147b: lea    eax,[r13-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_147f:
	/* 0x147f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1482:
	/* 0x1482: jae    16ad <generic_tracepoint_event+0x16ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5805ULL;
	}
x86_l_1488:
	/* 0x1488: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_148d:
	/* 0x148d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1492:
	/* 0x1492: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1497:
	/* 0x1497: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1499:
	/* 0x1499: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_149c:
	/* 0x149c: je     1670 <generic_tracepoint_event+0x1670> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5744ULL;
	}
x86_l_14a2:
	/* 0x14a2: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_14a4:
	/* 0x14a4: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14a9:
	/* 0x14a9: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_14b0:
	/* 0x14b0: movabs rax,0x400000045 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869253ULL);
x86_l_14ba:
	/* 0x14ba: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_14bf:
	/* 0x14bf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14c4:
	/* 0x14c4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_14cb:
	/* 0x14cb: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14d0:
	/* 0x14d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d2:
	/* 0x14d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14d5:
	/* 0x14d5: je     164e <generic_tracepoint_event+0x164e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5710ULL;
	}
x86_l_14db:
	/* 0x14db: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_14dd:
	/* 0x14dd: jmp    1670 <generic_tracepoint_event+0x1670> */
	return 5744ULL;
x86_l_14e2:
	/* 0x14e2: cmp    r13d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 38ULL);
x86_l_14e6:
	/* 0x14e6: je     1904 <generic_tracepoint_event+0x1904> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6404ULL;
	}
x86_l_14ec:
	/* 0x14ec: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_14f0:
	/* 0x14f0: je     17e9 <generic_tracepoint_event+0x17e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6121ULL;
	}
x86_l_14f6:
	/* 0x14f6: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_14fa:
	/* 0x14fa: jne    1a8d <generic_tracepoint_event+0x1a8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6797ULL;
	}
x86_l_1500:
	/* 0x1500: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1505:
	/* 0x1505: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_150a:
	/* 0x150a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_150f:
	/* 0x150f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1511:
	/* 0x1511: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1514:
	/* 0x1514: je     1a35 <generic_tracepoint_event+0x1a35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6709ULL;
	}
x86_l_151a:
	/* 0x151a: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_151c:
	/* 0x151c: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1521:
	/* 0x1521: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1528:
	/* 0x1528: movabs rax,0x4000000a8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869352ULL);
x86_l_1532:
	/* 0x1532: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1537:
	/* 0x1537: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_153c:
	/* 0x153c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1543:
	/* 0x1543: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1548:
	/* 0x1548: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_154a:
	/* 0x154a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_154d:
	/* 0x154d: jne    189d <generic_tracepoint_event+0x189d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6301ULL;
	}
x86_l_1553:
	/* 0x1553: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_155b:
	/* 0x155b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1560:
	/* 0x1560: jmp    1a20 <generic_tracepoint_event+0x1a20> */
	return 6688ULL;
x86_l_1565:
	/* 0x1565: cmp    r13d,0xfffffff3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967283ULL);
x86_l_1569:
	/* 0x1569: je     15ef <generic_tracepoint_event+0x15ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5615ULL;
	}
x86_l_156f:
	/* 0x156f: cmp    r13d,0xfffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967284ULL);
	return 5491ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5491ULL: goto x86_l_1573;
	case 5493ULL: goto x86_l_1575;
	case 5498ULL: goto x86_l_157a;
	case 5502ULL: goto x86_l_157e;
	case 5504ULL: goto x86_l_1580;
	case 5508ULL: goto x86_l_1584;
	case 5514ULL: goto x86_l_158a;
	case 5519ULL: goto x86_l_158f;
	case 5524ULL: goto x86_l_1594;
	case 5529ULL: goto x86_l_1599;
	case 5531ULL: goto x86_l_159b;
	case 5534ULL: goto x86_l_159e;
	case 5540ULL: goto x86_l_15a4;
	case 5542ULL: goto x86_l_15a6;
	case 5547ULL: goto x86_l_15ab;
	case 5554ULL: goto x86_l_15b2;
	case 5564ULL: goto x86_l_15bc;
	case 5569ULL: goto x86_l_15c1;
	case 5574ULL: goto x86_l_15c6;
	case 5581ULL: goto x86_l_15cd;
	case 5586ULL: goto x86_l_15d2;
	case 5588ULL: goto x86_l_15d4;
	case 5591ULL: goto x86_l_15d7;
	case 5597ULL: goto x86_l_15dd;
	case 5605ULL: goto x86_l_15e5;
	case 5610ULL: goto x86_l_15ea;
	case 5615ULL: goto x86_l_15ef;
	case 5620ULL: goto x86_l_15f4;
	case 5625ULL: goto x86_l_15f9;
	case 5630ULL: goto x86_l_15fe;
	case 5632ULL: goto x86_l_1600;
	case 5635ULL: goto x86_l_1603;
	case 5641ULL: goto x86_l_1609;
	case 5643ULL: goto x86_l_160b;
	case 5648ULL: goto x86_l_1610;
	case 5655ULL: goto x86_l_1617;
	case 5665ULL: goto x86_l_1621;
	case 5670ULL: goto x86_l_1626;
	case 5675ULL: goto x86_l_162b;
	case 5682ULL: goto x86_l_1632;
	case 5687ULL: goto x86_l_1637;
	case 5689ULL: goto x86_l_1639;
	case 5692ULL: goto x86_l_163c;
	case 5698ULL: goto x86_l_1642;
	case 5700ULL: goto x86_l_1644;
	case 5705ULL: goto x86_l_1649;
	case 5710ULL: goto x86_l_164e;
	case 5718ULL: goto x86_l_1656;
	case 5723ULL: goto x86_l_165b;
	case 5730ULL: goto x86_l_1662;
	case 5735ULL: goto x86_l_1667;
	case 5740ULL: goto x86_l_166c;
	case 5742ULL: goto x86_l_166e;
	case 5744ULL: goto x86_l_1670;
	case 5749ULL: goto x86_l_1675;
	case 5753ULL: goto x86_l_1679;
	case 5759ULL: goto x86_l_167f;
	case 5764ULL: goto x86_l_1684;
	case 5766ULL: goto x86_l_1686;
	case 5770ULL: goto x86_l_168a;
	case 5775ULL: goto x86_l_168f;
	case 5780ULL: goto x86_l_1694;
	case 5785ULL: goto x86_l_1699;
	case 5787ULL: goto x86_l_169b;
	case 5791ULL: goto x86_l_169f;
	case 5794ULL: goto x86_l_16a2;
	case 5797ULL: goto x86_l_16a5;
	case 5800ULL: goto x86_l_16a8;
	case 5805ULL: goto x86_l_16ad;
	case 5809ULL: goto x86_l_16b1;
	case 5815ULL: goto x86_l_16b7;
	case 5820ULL: goto x86_l_16bc;
	case 5825ULL: goto x86_l_16c1;
	case 5830ULL: goto x86_l_16c6;
	case 5832ULL: goto x86_l_16c8;
	case 5835ULL: goto x86_l_16cb;
	case 5841ULL: goto x86_l_16d1;
	case 5843ULL: goto x86_l_16d3;
	case 5848ULL: goto x86_l_16d8;
	case 5855ULL: goto x86_l_16df;
	case 5865ULL: goto x86_l_16e9;
	case 5870ULL: goto x86_l_16ee;
	case 5875ULL: goto x86_l_16f3;
	case 5882ULL: goto x86_l_16fa;
	case 5887ULL: goto x86_l_16ff;
	case 5889ULL: goto x86_l_1701;
	case 5892ULL: goto x86_l_1704;
	case 5898ULL: goto x86_l_170a;
	case 5906ULL: goto x86_l_1712;
	case 5911ULL: goto x86_l_1717;
	case 5916ULL: goto x86_l_171c;
	case 5919ULL: goto x86_l_171f;
	case 5924ULL: goto x86_l_1724;
	case 5929ULL: goto x86_l_1729;
	case 5934ULL: goto x86_l_172e;
	case 5939ULL: goto x86_l_1733;
	case 5941ULL: goto x86_l_1735;
	case 5944ULL: goto x86_l_1738;
	case 5950ULL: goto x86_l_173e;
	case 5952ULL: goto x86_l_1740;
	case 5957ULL: goto x86_l_1745;
	case 5964ULL: goto x86_l_174c;
	case 5974ULL: goto x86_l_1756;
	case 5979ULL: goto x86_l_175b;
	case 5984ULL: goto x86_l_1760;
	case 5991ULL: goto x86_l_1767;
	case 5996ULL: goto x86_l_176c;
	case 5998ULL: goto x86_l_176e;
	case 6001ULL: goto x86_l_1771;
	case 6007ULL: goto x86_l_1777;
	case 6015ULL: goto x86_l_177f;
	case 6020ULL: goto x86_l_1784;
	case 6025ULL: goto x86_l_1789;
	case 6030ULL: goto x86_l_178e;
	case 6035ULL: goto x86_l_1793;
	case 6040ULL: goto x86_l_1798;
	case 6042ULL: goto x86_l_179a;
	case 6045ULL: goto x86_l_179d;
	case 6051ULL: goto x86_l_17a3;
	case 6053ULL: goto x86_l_17a5;
	case 6058ULL: goto x86_l_17aa;
	case 6065ULL: goto x86_l_17b1;
	case 6075ULL: goto x86_l_17bb;
	case 6080ULL: goto x86_l_17c0;
	case 6085ULL: goto x86_l_17c5;
	case 6092ULL: goto x86_l_17cc;
	case 6097ULL: goto x86_l_17d1;
	case 6099ULL: goto x86_l_17d3;
	case 6102ULL: goto x86_l_17d6;
	case 6108ULL: goto x86_l_17dc;
	case 6110ULL: goto x86_l_17de;
	case 6116ULL: goto x86_l_17e4;
	case 6121ULL: goto x86_l_17e9;
	case 6126ULL: goto x86_l_17ee;
	case 6131ULL: goto x86_l_17f3;
	case 6136ULL: goto x86_l_17f8;
	case 6138ULL: goto x86_l_17fa;
	case 6141ULL: goto x86_l_17fd;
	case 6147ULL: goto x86_l_1803;
	case 6149ULL: goto x86_l_1805;
	case 6154ULL: goto x86_l_180a;
	case 6161ULL: goto x86_l_1811;
	case 6171ULL: goto x86_l_181b;
	case 6176ULL: goto x86_l_1820;
	case 6181ULL: goto x86_l_1825;
	case 6188ULL: goto x86_l_182c;
	case 6193ULL: goto x86_l_1831;
	case 6195ULL: goto x86_l_1833;
	case 6198ULL: goto x86_l_1836;
	case 6200ULL: goto x86_l_1838;
	case 6208ULL: goto x86_l_1840;
	case 6213ULL: goto x86_l_1845;
	case 6218ULL: goto x86_l_184a;
	case 6223ULL: goto x86_l_184f;
	case 6228ULL: goto x86_l_1854;
	case 6233ULL: goto x86_l_1859;
	case 6235ULL: goto x86_l_185b;
	case 6238ULL: goto x86_l_185e;
	case 6244ULL: goto x86_l_1864;
	case 6246ULL: goto x86_l_1866;
	case 6251ULL: goto x86_l_186b;
	case 6258ULL: goto x86_l_1872;
	case 6268ULL: goto x86_l_187c;
	case 6273ULL: goto x86_l_1881;
	case 6278ULL: goto x86_l_1886;
	case 6285ULL: goto x86_l_188d;
	case 6290ULL: goto x86_l_1892;
	case 6292ULL: goto x86_l_1894;
	case 6295ULL: goto x86_l_1897;
	case 6301ULL: goto x86_l_189d;
	case 6303ULL: goto x86_l_189f;
	case 6308ULL: goto x86_l_18a4;
	case 6313ULL: goto x86_l_18a9;
	case 6318ULL: goto x86_l_18ae;
	case 6323ULL: goto x86_l_18b3;
	case 6325ULL: goto x86_l_18b5;
	case 6328ULL: goto x86_l_18b8;
	case 6334ULL: goto x86_l_18be;
	case 6336ULL: goto x86_l_18c0;
	case 6341ULL: goto x86_l_18c5;
	case 6348ULL: goto x86_l_18cc;
	case 6358ULL: goto x86_l_18d6;
	case 6363ULL: goto x86_l_18db;
	case 6368ULL: goto x86_l_18e0;
	case 6375ULL: goto x86_l_18e7;
	case 6380ULL: goto x86_l_18ec;
	case 6382ULL: goto x86_l_18ee;
	case 6385ULL: goto x86_l_18f1;
	case 6391ULL: goto x86_l_18f7;
	case 6393ULL: goto x86_l_18f9;
	case 6399ULL: goto x86_l_18ff;
	case 6404ULL: goto x86_l_1904;
	case 6409ULL: goto x86_l_1909;
	case 6414ULL: goto x86_l_190e;
	case 6419ULL: goto x86_l_1913;
	case 6421ULL: goto x86_l_1915;
	case 6424ULL: goto x86_l_1918;
	case 6430ULL: goto x86_l_191e;
	case 6432ULL: goto x86_l_1920;
	case 6437ULL: goto x86_l_1925;
	case 6444ULL: goto x86_l_192c;
	case 6454ULL: goto x86_l_1936;
	case 6459ULL: goto x86_l_193b;
	case 6464ULL: goto x86_l_1940;
	case 6471ULL: goto x86_l_1947;
	case 6476ULL: goto x86_l_194c;
	case 6478ULL: goto x86_l_194e;
	case 6481ULL: goto x86_l_1951;
	case 6487ULL: goto x86_l_1957;
	case 6489ULL: goto x86_l_1959;
	case 6494ULL: goto x86_l_195e;
	case 6499ULL: goto x86_l_1963;
	case 6507ULL: goto x86_l_196b;
	case 6512ULL: goto x86_l_1970;
	case 6519ULL: goto x86_l_1977;
	case 6524ULL: goto x86_l_197c;
	case 6529ULL: goto x86_l_1981;
	case 6531ULL: goto x86_l_1983;
	case 6533ULL: goto x86_l_1985;
	case 6538ULL: goto x86_l_198a;
	case 6543ULL: goto x86_l_198f;
	case 6551ULL: goto x86_l_1997;
	case 6556ULL: goto x86_l_199c;
	case 6563ULL: goto x86_l_19a3;
	case 6568ULL: goto x86_l_19a8;
	case 6573ULL: goto x86_l_19ad;
	case 6575ULL: goto x86_l_19af;
	case 6577ULL: goto x86_l_19b1;
	case 6583ULL: goto x86_l_19b7;
	case 6588ULL: goto x86_l_19bc;
	case 6596ULL: goto x86_l_19c4;
	case 6601ULL: goto x86_l_19c9;
	case 6608ULL: goto x86_l_19d0;
	case 6613ULL: goto x86_l_19d5;
	case 6618ULL: goto x86_l_19da;
	case 6620ULL: goto x86_l_19dc;
	case 6622ULL: goto x86_l_19de;
	case 6628ULL: goto x86_l_19e4;
	case 6633ULL: goto x86_l_19e9;
	case 6641ULL: goto x86_l_19f1;
	case 6646ULL: goto x86_l_19f6;
	case 6653ULL: goto x86_l_19fd;
	case 6658ULL: goto x86_l_1a02;
	case 6663ULL: goto x86_l_1a07;
	case 6665ULL: goto x86_l_1a09;
	case 6667ULL: goto x86_l_1a0b;
	case 6673ULL: goto x86_l_1a11;
	case 6675ULL: goto x86_l_1a13;
	case 6683ULL: goto x86_l_1a1b;
	case 6688ULL: goto x86_l_1a20;
	case 6695ULL: goto x86_l_1a27;
	case 6700ULL: goto x86_l_1a2c;
	case 6705ULL: goto x86_l_1a31;
	case 6707ULL: goto x86_l_1a33;
	case 6709ULL: goto x86_l_1a35;
	case 6714ULL: goto x86_l_1a3a;
	case 6716ULL: goto x86_l_1a3c;
	case 6724ULL: goto x86_l_1a44;
	case 6729ULL: goto x86_l_1a49;
	case 6736ULL: goto x86_l_1a50;
	case 6741ULL: goto x86_l_1a55;
	case 6746ULL: goto x86_l_1a5a;
	case 6748ULL: goto x86_l_1a5c;
	case 6750ULL: goto x86_l_1a5e;
	case 6756ULL: goto x86_l_1a64;
	case 6758ULL: goto x86_l_1a66;
	case 6766ULL: goto x86_l_1a6e;
	case 6771ULL: goto x86_l_1a73;
	case 6778ULL: goto x86_l_1a7a;
	case 6783ULL: goto x86_l_1a7f;
	case 6788ULL: goto x86_l_1a84;
	case 6790ULL: goto x86_l_1a86;
	case 6792ULL: goto x86_l_1a88;
	case 6797ULL: goto x86_l_1a8d;
	case 6804ULL: goto x86_l_1a94;
	case 6809ULL: goto x86_l_1a99;
	case 6813ULL: goto x86_l_1a9d;
	case 6816ULL: goto x86_l_1aa0;
	case 6819ULL: goto x86_l_1aa3;
	case 6823ULL: goto x86_l_1aa7;
	case 6825ULL: goto x86_l_1aa9;
	case 6829ULL: goto x86_l_1aad;
	case 6835ULL: goto x86_l_1ab3;
	case 6839ULL: goto x86_l_1ab7;
	case 6845ULL: goto x86_l_1abd;
	case 6849ULL: goto x86_l_1ac1;
	case 6855ULL: goto x86_l_1ac7;
	case 6859ULL: goto x86_l_1acb;
	case 6865ULL: goto x86_l_1ad1;
	case 6869ULL: goto x86_l_1ad5;
	case 6875ULL: goto x86_l_1adb;
	case 6880ULL: goto x86_l_1ae0;
	case 6884ULL: goto x86_l_1ae4;
	case 6890ULL: goto x86_l_1aea;
	case 6894ULL: goto x86_l_1aee;
	case 6900ULL: goto x86_l_1af4;
	case 6904ULL: goto x86_l_1af8;
	case 6910ULL: goto x86_l_1afe;
	case 6914ULL: goto x86_l_1b02;
	case 6920ULL: goto x86_l_1b08;
	case 6924ULL: goto x86_l_1b0c;
	case 6930ULL: goto x86_l_1b12;
	case 6935ULL: goto x86_l_1b17;
	case 6940ULL: goto x86_l_1b1c;
	case 6945ULL: goto x86_l_1b21;
	case 6947ULL: goto x86_l_1b23;
	case 6950ULL: goto x86_l_1b26;
	case 6956ULL: goto x86_l_1b2c;
	case 6958ULL: goto x86_l_1b2e;
	case 6963ULL: goto x86_l_1b33;
	case 6970ULL: goto x86_l_1b3a;
	case 6980ULL: goto x86_l_1b44;
	case 6985ULL: goto x86_l_1b49;
	case 6990ULL: goto x86_l_1b4e;
	case 6997ULL: goto x86_l_1b55;
	case 7002ULL: goto x86_l_1b5a;
	case 7004ULL: goto x86_l_1b5c;
	case 7007ULL: goto x86_l_1b5f;
	case 7013ULL: goto x86_l_1b65;
	case 7015ULL: goto x86_l_1b67;
	case 7021ULL: goto x86_l_1b6d;
	case 7026ULL: goto x86_l_1b72;
	case 7030ULL: goto x86_l_1b76;
	case 7036ULL: goto x86_l_1b7c;
	case 7040ULL: goto x86_l_1b80;
	case 7043ULL: goto x86_l_1b83;
	case 7049ULL: goto x86_l_1b89;
	case 7053ULL: goto x86_l_1b8d;
	case 7059ULL: goto x86_l_1b93;
	case 7064ULL: goto x86_l_1b98;
	case 7069ULL: goto x86_l_1b9d;
	case 7074ULL: goto x86_l_1ba2;
	case 7076ULL: goto x86_l_1ba4;
	case 7079ULL: goto x86_l_1ba7;
	case 7085ULL: goto x86_l_1bad;
	case 7087ULL: goto x86_l_1baf;
	case 7092ULL: goto x86_l_1bb4;
	case 7099ULL: goto x86_l_1bbb;
	case 7109ULL: goto x86_l_1bc5;
	case 7114ULL: goto x86_l_1bca;
	case 7119ULL: goto x86_l_1bcf;
	case 7126ULL: goto x86_l_1bd6;
	case 7131ULL: goto x86_l_1bdb;
	case 7133ULL: goto x86_l_1bdd;
	case 7136ULL: goto x86_l_1be0;
	case 7142ULL: goto x86_l_1be6;
	case 7150ULL: goto x86_l_1bee;
	case 7155ULL: goto x86_l_1bf3;
	case 7160ULL: goto x86_l_1bf8;
	case 7164ULL: goto x86_l_1bfc;
	case 7170ULL: goto x86_l_1c02;
	case 7174ULL: goto x86_l_1c06;
	case 7180ULL: goto x86_l_1c0c;
	case 7184ULL: goto x86_l_1c10;
	case 7186ULL: goto x86_l_1c12;
	case 7190ULL: goto x86_l_1c16;
	case 7196ULL: goto x86_l_1c1c;
	case 7201ULL: goto x86_l_1c21;
	case 7206ULL: goto x86_l_1c26;
	case 7211ULL: goto x86_l_1c2b;
	case 7213ULL: goto x86_l_1c2d;
	case 7216ULL: goto x86_l_1c30;
	case 7222ULL: goto x86_l_1c36;
	case 7224ULL: goto x86_l_1c38;
	case 7229ULL: goto x86_l_1c3d;
	case 7236ULL: goto x86_l_1c44;
	case 7246ULL: goto x86_l_1c4e;
	case 7251ULL: goto x86_l_1c53;
	case 7256ULL: goto x86_l_1c58;
	case 7263ULL: goto x86_l_1c5f;
	case 7268ULL: goto x86_l_1c64;
	case 7270ULL: goto x86_l_1c66;
	case 7273ULL: goto x86_l_1c69;
	case 7279ULL: goto x86_l_1c6f;
	case 7281ULL: goto x86_l_1c71;
	case 7287ULL: goto x86_l_1c77;
	case 7292ULL: goto x86_l_1c7c;
	case 7296ULL: goto x86_l_1c80;
	case 7299ULL: goto x86_l_1c83;
	case 7305ULL: goto x86_l_1c89;
	case 7310ULL: goto x86_l_1c8e;
	case 7315ULL: goto x86_l_1c93;
	case 7320ULL: goto x86_l_1c98;
	case 7322ULL: goto x86_l_1c9a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1573:
	/* 0x1573: je     158a <generic_tracepoint_event+0x158a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_158a;
	}
x86_l_1575:
	/* 0x1575: jmp    1a8d <generic_tracepoint_event+0x1a8d> */
	goto x86_l_1a8d;
x86_l_157a:
	/* 0x157a: cmp    r13d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 12ULL);
x86_l_157e:
	/* 0x157e: je     15ef <generic_tracepoint_event+0x15ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15ef;
	}
x86_l_1580:
	/* 0x1580: cmp    r13d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 13ULL);
x86_l_1584:
	/* 0x1584: jne    1a8d <generic_tracepoint_event+0x1a8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a8d;
	}
x86_l_158a:
	/* 0x158a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_158f:
	/* 0x158f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1594:
	/* 0x1594: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1599:
	/* 0x1599: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_159b:
	/* 0x159b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_159e:
	/* 0x159e: je     1a88 <generic_tracepoint_event+0x1a88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a88;
	}
x86_l_15a4:
	/* 0x15a4: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_15a6:
	/* 0x15a6: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15ab:
	/* 0x15ab: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_15b2:
	/* 0x15b2: movabs rax,0x40000005e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869278ULL);
x86_l_15bc:
	/* 0x15bc: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_15c1:
	/* 0x15c1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15c6:
	/* 0x15c6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_15cd:
	/* 0x15cd: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15d2:
	/* 0x15d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d4:
	/* 0x15d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15d7:
	/* 0x15d7: jne    1957 <generic_tracepoint_event+0x1957> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1957;
	}
x86_l_15dd:
	/* 0x15dd: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_15e5:
	/* 0x15e5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15ea:
	/* 0x15ea: jmp    1a73 <generic_tracepoint_event+0x1a73> */
	goto x86_l_1a73;
x86_l_15ef:
	/* 0x15ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15f4:
	/* 0x15f4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15f9:
	/* 0x15f9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15fe:
	/* 0x15fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1600:
	/* 0x1600: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1603:
	/* 0x1603: je     1985 <generic_tracepoint_event+0x1985> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1985;
	}
x86_l_1609:
	/* 0x1609: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_160b:
	/* 0x160b: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1610:
	/* 0x1610: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1617:
	/* 0x1617: movabs rax,0x400000056 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869270ULL);
x86_l_1621:
	/* 0x1621: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1626:
	/* 0x1626: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_162b:
	/* 0x162b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1632:
	/* 0x1632: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1637:
	/* 0x1637: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1639:
	/* 0x1639: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_163c:
	/* 0x163c: je     1963 <generic_tracepoint_event+0x1963> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1963;
	}
x86_l_1642:
	/* 0x1642: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1644:
	/* 0x1644: movsxd r12,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1649:
	/* 0x1649: jmp    1a8d <generic_tracepoint_event+0x1a8d> */
	goto x86_l_1a8d;
x86_l_164e:
	/* 0x164e: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1656:
	/* 0x1656: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_165b:
	/* 0x165b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1662:
	/* 0x1662: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1667:
	/* 0x1667: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_166c:
	/* 0x166c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_166e:
	/* 0x166e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1670:
	/* 0x1670: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1675:
	/* 0x1675: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_1679:
	/* 0x1679: jne    1a8d <generic_tracepoint_event+0x1a8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a8d;
	}
x86_l_167f:
	/* 0x167f: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_1684:
	/* 0x1684: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1686:
	/* 0x1686: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_168a:
	/* 0x168a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_168f:
	/* 0x168f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1694:
	/* 0x1694: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1699:
	/* 0x1699: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_169b:
	/* 0x169b: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_169f:
	/* 0x169f: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_16a2:
	/* 0x16a2: shl    eax,0x1e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 30ULL);
x86_l_16a5:
	/* 0x16a5: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_16a8:
	/* 0x16a8: jmp    1a8d <generic_tracepoint_event+0x1a8d> */
	goto x86_l_1a8d;
x86_l_16ad:
	/* 0x16ad: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_16b1:
	/* 0x16b1: jne    1a8d <generic_tracepoint_event+0x1a8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a8d;
	}
x86_l_16b7:
	/* 0x16b7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16bc:
	/* 0x16bc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16c1:
	/* 0x16c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16c6:
	/* 0x16c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c8:
	/* 0x16c8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16cb:
	/* 0x16cb: je     1a35 <generic_tracepoint_event+0x1a35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a35;
	}
x86_l_16d1:
	/* 0x16d1: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_16d3:
	/* 0x16d3: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16d8:
	/* 0x16d8: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_16df:
	/* 0x16df: movabs rax,0x40000009a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869338ULL);
x86_l_16e9:
	/* 0x16e9: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_16ee:
	/* 0x16ee: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16f3:
	/* 0x16f3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_16fa:
	/* 0x16fa: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16ff:
	/* 0x16ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1701:
	/* 0x1701: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1704:
	/* 0x1704: jne    189d <generic_tracepoint_event+0x189d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_189d;
	}
x86_l_170a:
	/* 0x170a: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1712:
	/* 0x1712: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1717:
	/* 0x1717: jmp    1a20 <generic_tracepoint_event+0x1a20> */
	goto x86_l_1a20;
x86_l_171c:
	/* 0x171c: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_171f:
	/* 0x171f: jmp    1a8d <generic_tracepoint_event+0x1a8d> */
	goto x86_l_1a8d;
x86_l_1724:
	/* 0x1724: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1729:
	/* 0x1729: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_172e:
	/* 0x172e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1733:
	/* 0x1733: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1735:
	/* 0x1735: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1738:
	/* 0x1738: je     1a35 <generic_tracepoint_event+0x1a35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a35;
	}
x86_l_173e:
	/* 0x173e: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1740:
	/* 0x1740: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1745:
	/* 0x1745: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_174c:
	/* 0x174c: movabs rax,0x400000093 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869331ULL);
x86_l_1756:
	/* 0x1756: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_175b:
	/* 0x175b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1760:
	/* 0x1760: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1767:
	/* 0x1767: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_176c:
	/* 0x176c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_176e:
	/* 0x176e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1771:
	/* 0x1771: jne    189d <generic_tracepoint_event+0x189d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_189d;
	}
x86_l_1777:
	/* 0x1777: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_177f:
	/* 0x177f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1784:
	/* 0x1784: jmp    1a20 <generic_tracepoint_event+0x1a20> */
	goto x86_l_1a20;
x86_l_1789:
	/* 0x1789: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_178e:
	/* 0x178e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1793:
	/* 0x1793: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1798:
	/* 0x1798: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_179a:
	/* 0x179a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_179d:
	/* 0x179d: je     19de <generic_tracepoint_event+0x19de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19de;
	}
x86_l_17a3:
	/* 0x17a3: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_17a5:
	/* 0x17a5: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17aa:
	/* 0x17aa: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_17b1:
	/* 0x17b1: movabs rax,0x40000007a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869306ULL);
x86_l_17bb:
	/* 0x17bb: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_17c0:
	/* 0x17c0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17c5:
	/* 0x17c5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_17cc:
	/* 0x17cc: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17d1:
	/* 0x17d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17d3:
	/* 0x17d3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17d6:
	/* 0x17d6: je     19bc <generic_tracepoint_event+0x19bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19bc;
	}
x86_l_17dc:
	/* 0x17dc: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_17de:
	/* 0x17de: movsx  r12,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_17e4:
	/* 0x17e4: jmp    1a8d <generic_tracepoint_event+0x1a8d> */
	goto x86_l_1a8d;
x86_l_17e9:
	/* 0x17e9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17ee:
	/* 0x17ee: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17f3:
	/* 0x17f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17f8:
	/* 0x17f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17fa:
	/* 0x17fa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17fd:
	/* 0x17fd: je     1a35 <generic_tracepoint_event+0x1a35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a35;
	}
x86_l_1803:
	/* 0x1803: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1805:
	/* 0x1805: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_180a:
	/* 0x180a: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1811:
	/* 0x1811: movabs rax,0x4000000a1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869345ULL);
x86_l_181b:
	/* 0x181b: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1820:
	/* 0x1820: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1825:
	/* 0x1825: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_182c:
	/* 0x182c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1831:
	/* 0x1831: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1833:
	/* 0x1833: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1836:
	/* 0x1836: jne    189d <generic_tracepoint_event+0x189d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_189d;
	}
x86_l_1838:
	/* 0x1838: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1840:
	/* 0x1840: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1845:
	/* 0x1845: jmp    1a20 <generic_tracepoint_event+0x1a20> */
	goto x86_l_1a20;
x86_l_184a:
	/* 0x184a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_184f:
	/* 0x184f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1854:
	/* 0x1854: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1859:
	/* 0x1859: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_185b:
	/* 0x185b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_185e:
	/* 0x185e: je     1a35 <generic_tracepoint_event+0x1a35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a35;
	}
x86_l_1864:
	/* 0x1864: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1866:
	/* 0x1866: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_186b:
	/* 0x186b: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1872:
	/* 0x1872: movabs rax,0x40000004e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869262ULL);
x86_l_187c:
	/* 0x187c: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1881:
	/* 0x1881: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1886:
	/* 0x1886: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_188d:
	/* 0x188d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1892:
	/* 0x1892: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1894:
	/* 0x1894: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1897:
	/* 0x1897: je     1a13 <generic_tracepoint_event+0x1a13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a13;
	}
x86_l_189d:
	/* 0x189d: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_189f:
	/* 0x189f: jmp    1a35 <generic_tracepoint_event+0x1a35> */
	goto x86_l_1a35;
x86_l_18a4:
	/* 0x18a4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18a9:
	/* 0x18a9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18ae:
	/* 0x18ae: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_18b3:
	/* 0x18b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b5:
	/* 0x18b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18b8:
	/* 0x18b8: je     1a5e <generic_tracepoint_event+0x1a5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a5e;
	}
x86_l_18be:
	/* 0x18be: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_18c0:
	/* 0x18c0: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18c5:
	/* 0x18c5: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_18cc:
	/* 0x18cc: movabs rax,0x400000065 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869285ULL);
x86_l_18d6:
	/* 0x18d6: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_18db:
	/* 0x18db: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18e0:
	/* 0x18e0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_18e7:
	/* 0x18e7: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18ec:
	/* 0x18ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ee:
	/* 0x18ee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18f1:
	/* 0x18f1: je     1a3c <generic_tracepoint_event+0x1a3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a3c;
	}
x86_l_18f7:
	/* 0x18f7: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_18f9:
	/* 0x18f9: movzx  r12d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_18ff:
	/* 0x18ff: jmp    1a8d <generic_tracepoint_event+0x1a8d> */
	goto x86_l_1a8d;
x86_l_1904:
	/* 0x1904: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1909:
	/* 0x1909: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_190e:
	/* 0x190e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1913:
	/* 0x1913: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1915:
	/* 0x1915: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1918:
	/* 0x1918: je     1a88 <generic_tracepoint_event+0x1a88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a88;
	}
x86_l_191e:
	/* 0x191e: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1920:
	/* 0x1920: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1925:
	/* 0x1925: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_192c:
	/* 0x192c: movabs rax,0x400000088 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869320ULL);
x86_l_1936:
	/* 0x1936: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_193b:
	/* 0x193b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1940:
	/* 0x1940: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1947:
	/* 0x1947: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_194c:
	/* 0x194c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_194e:
	/* 0x194e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1951:
	/* 0x1951: je     1a66 <generic_tracepoint_event+0x1a66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a66;
	}
x86_l_1957:
	/* 0x1957: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1959:
	/* 0x1959: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_195e:
	/* 0x195e: jmp    1a8d <generic_tracepoint_event+0x1a8d> */
	goto x86_l_1a8d;
x86_l_1963:
	/* 0x1963: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_196b:
	/* 0x196b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1970:
	/* 0x1970: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1977:
	/* 0x1977: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_197c:
	/* 0x197c: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1981:
	/* 0x1981: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1983:
	/* 0x1983: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1985:
	/* 0x1985: movsxd r12,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_198a:
	/* 0x198a: jmp    1a8d <generic_tracepoint_event+0x1a8d> */
	goto x86_l_1a8d;
x86_l_198f:
	/* 0x198f: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1997:
	/* 0x1997: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_199c:
	/* 0x199c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_19a3:
	/* 0x19a3: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19a8:
	/* 0x19a8: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19ad:
	/* 0x19ad: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19af:
	/* 0x19af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b1:
	/* 0x19b1: movsx  r12,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_19b7:
	/* 0x19b7: jmp    1a8d <generic_tracepoint_event+0x1a8d> */
	goto x86_l_1a8d;
x86_l_19bc:
	/* 0x19bc: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_19c4:
	/* 0x19c4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_19c9:
	/* 0x19c9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_19d0:
	/* 0x19d0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19d5:
	/* 0x19d5: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19da:
	/* 0x19da: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19dc:
	/* 0x19dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19de:
	/* 0x19de: movsx  r12,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_19e4:
	/* 0x19e4: jmp    1a8d <generic_tracepoint_event+0x1a8d> */
	goto x86_l_1a8d;
x86_l_19e9:
	/* 0x19e9: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_19f1:
	/* 0x19f1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_19f6:
	/* 0x19f6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_19fd:
	/* 0x19fd: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a02:
	/* 0x1a02: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a07:
	/* 0x1a07: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a09:
	/* 0x1a09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a0b:
	/* 0x1a0b: movzx  r12d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1a11:
	/* 0x1a11: jmp    1a8d <generic_tracepoint_event+0x1a8d> */
	goto x86_l_1a8d;
x86_l_1a13:
	/* 0x1a13: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1a1b:
	/* 0x1a1b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a20:
	/* 0x1a20: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1a27:
	/* 0x1a27: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a2c:
	/* 0x1a2c: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a31:
	/* 0x1a31: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a33:
	/* 0x1a33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a35:
	/* 0x1a35: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a3a:
	/* 0x1a3a: jmp    1a8d <generic_tracepoint_event+0x1a8d> */
	goto x86_l_1a8d;
x86_l_1a3c:
	/* 0x1a3c: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1a44:
	/* 0x1a44: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a49:
	/* 0x1a49: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1a50:
	/* 0x1a50: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a55:
	/* 0x1a55: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a5a:
	/* 0x1a5a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a5c:
	/* 0x1a5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a5e:
	/* 0x1a5e: movzx  r12d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1a64:
	/* 0x1a64: jmp    1a8d <generic_tracepoint_event+0x1a8d> */
	goto x86_l_1a8d;
x86_l_1a66:
	/* 0x1a66: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1a6e:
	/* 0x1a6e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a73:
	/* 0x1a73: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1a7a:
	/* 0x1a7a: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a7f:
	/* 0x1a7f: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a84:
	/* 0x1a84: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a86:
	/* 0x1a86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a88:
	/* 0x1a88: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a8d:
	/* 0x1a8d: mov    QWORD PTR [r14+0x5e60],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24160ULL);
x86_l_1a94:
	/* 0x1a94: movzx  edx,WORD PTR [r15+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1a99:
	/* 0x1a99: mov    r13d,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a9d:
	/* 0x1a9d: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1aa0:
	/* 0x1aa0: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1aa3:
	/* 0x1aa3: cmp    r13d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 11ULL);
x86_l_1aa7:
	/* 0x1aa7: jg     1ae0 <generic_tracepoint_event+0x1ae0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1ae0;
	}
x86_l_1aa9:
	/* 0x1aa9: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_1aad:
	/* 0x1aad: jle    1b72 <generic_tracepoint_event+0x1b72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1b72;
	}
x86_l_1ab3:
	/* 0x1ab3: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_1ab7:
	/* 0x1ab7: jg     1c7c <generic_tracepoint_event+0x1c7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1c7c;
	}
x86_l_1abd:
	/* 0x1abd: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1ac1:
	/* 0x1ac1: je     204b <generic_tracepoint_event+0x204b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8267ULL;
	}
x86_l_1ac7:
	/* 0x1ac7: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_1acb:
	/* 0x1acb: je     1f25 <generic_tracepoint_event+0x1f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7973ULL;
	}
x86_l_1ad1:
	/* 0x1ad1: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_1ad5:
	/* 0x1ad5: je     1b93 <generic_tracepoint_event+0x1b93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b93;
	}
x86_l_1adb:
	/* 0x1adb: jmp    228e <generic_tracepoint_event+0x228e> */
	return 8846ULL;
x86_l_1ae0:
	/* 0x1ae0: cmp    r13d,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 29ULL);
x86_l_1ae4:
	/* 0x1ae4: jle    1bf8 <generic_tracepoint_event+0x1bf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1bf8;
	}
x86_l_1aea:
	/* 0x1aea: cmp    r13d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 37ULL);
x86_l_1aee:
	/* 0x1aee: jg     1ce3 <generic_tracepoint_event+0x1ce3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7395ULL;
	}
x86_l_1af4:
	/* 0x1af4: cmp    r13d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 30ULL);
x86_l_1af8:
	/* 0x1af8: je     20a5 <generic_tracepoint_event+0x20a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8357ULL;
	}
x86_l_1afe:
	/* 0x1afe: cmp    r13d,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 31ULL);
x86_l_1b02:
	/* 0x1b02: je     1f8a <generic_tracepoint_event+0x1f8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8074ULL;
	}
x86_l_1b08:
	/* 0x1b08: cmp    r13d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 32ULL);
x86_l_1b0c:
	/* 0x1b0c: jne    228e <generic_tracepoint_event+0x228e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8846ULL;
	}
x86_l_1b12:
	/* 0x1b12: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b17:
	/* 0x1b17: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b1c:
	/* 0x1b1c: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1b21:
	/* 0x1b21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b23:
	/* 0x1b23: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b26:
	/* 0x1b26: je     220c <generic_tracepoint_event+0x220c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8716ULL;
	}
x86_l_1b2c:
	/* 0x1b2c: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1b2e:
	/* 0x1b2e: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b33:
	/* 0x1b33: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1b3a:
	/* 0x1b3a: movabs rax,0x400000073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869299ULL);
x86_l_1b44:
	/* 0x1b44: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1b49:
	/* 0x1b49: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b4e:
	/* 0x1b4e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1b55:
	/* 0x1b55: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b5a:
	/* 0x1b5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b5c:
	/* 0x1b5c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b5f:
	/* 0x1b5f: je     21ea <generic_tracepoint_event+0x21ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8682ULL;
	}
x86_l_1b65:
	/* 0x1b65: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1b67:
	/* 0x1b67: movzx  r12d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1b6d:
	/* 0x1b6d: jmp    228e <generic_tracepoint_event+0x228e> */
	return 8846ULL;
x86_l_1b72:
	/* 0x1b72: cmp    r13d,0xfffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967284ULL);
x86_l_1b76:
	/* 0x1b76: jle    1d66 <generic_tracepoint_event+0x1d66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 7526ULL;
	}
x86_l_1b7c:
	/* 0x1b7c: lea    eax,[r13+0xb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_1b80:
	/* 0x1b80: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b83:
	/* 0x1b83: jb     1c89 <generic_tracepoint_event+0x1c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1c89;
	}
x86_l_1b89:
	/* 0x1b89: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_1b8d:
	/* 0x1b8d: jne    228e <generic_tracepoint_event+0x228e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8846ULL;
	}
x86_l_1b93:
	/* 0x1b93: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b98:
	/* 0x1b98: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b9d:
	/* 0x1b9d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ba2:
	/* 0x1ba2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ba4:
	/* 0x1ba4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ba7:
	/* 0x1ba7: je     2236 <generic_tracepoint_event+0x2236> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8758ULL;
	}
x86_l_1bad:
	/* 0x1bad: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1baf:
	/* 0x1baf: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bb4:
	/* 0x1bb4: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1bbb:
	/* 0x1bbb: movabs rax,0x400000081 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869313ULL);
x86_l_1bc5:
	/* 0x1bc5: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1bca:
	/* 0x1bca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1bcf:
	/* 0x1bcf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1bd6:
	/* 0x1bd6: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bdb:
	/* 0x1bdb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bdd:
	/* 0x1bdd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1be0:
	/* 0x1be0: jne    209e <generic_tracepoint_event+0x209e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8350ULL;
	}
x86_l_1be6:
	/* 0x1be6: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1bee:
	/* 0x1bee: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1bf3:
	/* 0x1bf3: jmp    2221 <generic_tracepoint_event+0x2221> */
	return 8737ULL;
x86_l_1bf8:
	/* 0x1bf8: cmp    r13d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 17ULL);
x86_l_1bfc:
	/* 0x1bfc: jle    1d7b <generic_tracepoint_event+0x1d7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 7547ULL;
	}
x86_l_1c02:
	/* 0x1c02: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_1c06:
	/* 0x1c06: je     1f1d <generic_tracepoint_event+0x1f1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7965ULL;
	}
x86_l_1c0c:
	/* 0x1c0c: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_1c10:
	/* 0x1c10: je     1c89 <generic_tracepoint_event+0x1c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c89;
	}
x86_l_1c12:
	/* 0x1c12: cmp    r13d,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 29ULL);
x86_l_1c16:
	/* 0x1c16: jne    228e <generic_tracepoint_event+0x228e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8846ULL;
	}
x86_l_1c1c:
	/* 0x1c1c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c21:
	/* 0x1c21: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c26:
	/* 0x1c26: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1c2b:
	/* 0x1c2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c2d:
	/* 0x1c2d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c30:
	/* 0x1c30: je     21b2 <generic_tracepoint_event+0x21b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8626ULL;
	}
x86_l_1c36:
	/* 0x1c36: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1c38:
	/* 0x1c38: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c3d:
	/* 0x1c3d: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1c44:
	/* 0x1c44: movabs rax,0x40000006c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869292ULL);
x86_l_1c4e:
	/* 0x1c4e: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1c53:
	/* 0x1c53: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c58:
	/* 0x1c58: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1c5f:
	/* 0x1c5f: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c64:
	/* 0x1c64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c66:
	/* 0x1c66: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c69:
	/* 0x1c69: je     2190 <generic_tracepoint_event+0x2190> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8592ULL;
	}
x86_l_1c6f:
	/* 0x1c6f: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1c71:
	/* 0x1c71: movsx  r12,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1c77:
	/* 0x1c77: jmp    228e <generic_tracepoint_event+0x228e> */
	return 8846ULL;
x86_l_1c7c:
	/* 0x1c7c: lea    eax,[r13-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_1c80:
	/* 0x1c80: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c83:
	/* 0x1c83: jae    1eae <generic_tracepoint_event+0x1eae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7854ULL;
	}
x86_l_1c89:
	/* 0x1c89: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c8e:
	/* 0x1c8e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c93:
	/* 0x1c93: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c98:
	/* 0x1c98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c9a:
	/* 0x1c9a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
	return 7325ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7325ULL: goto x86_l_1c9d;
	case 7331ULL: goto x86_l_1ca3;
	case 7333ULL: goto x86_l_1ca5;
	case 7338ULL: goto x86_l_1caa;
	case 7345ULL: goto x86_l_1cb1;
	case 7355ULL: goto x86_l_1cbb;
	case 7360ULL: goto x86_l_1cc0;
	case 7365ULL: goto x86_l_1cc5;
	case 7372ULL: goto x86_l_1ccc;
	case 7377ULL: goto x86_l_1cd1;
	case 7379ULL: goto x86_l_1cd3;
	case 7382ULL: goto x86_l_1cd6;
	case 7388ULL: goto x86_l_1cdc;
	case 7390ULL: goto x86_l_1cde;
	case 7395ULL: goto x86_l_1ce3;
	case 7399ULL: goto x86_l_1ce7;
	case 7405ULL: goto x86_l_1ced;
	case 7409ULL: goto x86_l_1cf1;
	case 7415ULL: goto x86_l_1cf7;
	case 7419ULL: goto x86_l_1cfb;
	case 7425ULL: goto x86_l_1d01;
	case 7430ULL: goto x86_l_1d06;
	case 7435ULL: goto x86_l_1d0b;
	case 7440ULL: goto x86_l_1d10;
	case 7442ULL: goto x86_l_1d12;
	case 7445ULL: goto x86_l_1d15;
	case 7451ULL: goto x86_l_1d1b;
	case 7453ULL: goto x86_l_1d1d;
	case 7458ULL: goto x86_l_1d22;
	case 7465ULL: goto x86_l_1d29;
	case 7475ULL: goto x86_l_1d33;
	case 7480ULL: goto x86_l_1d38;
	case 7485ULL: goto x86_l_1d3d;
	case 7492ULL: goto x86_l_1d44;
	case 7497ULL: goto x86_l_1d49;
	case 7499ULL: goto x86_l_1d4b;
	case 7502ULL: goto x86_l_1d4e;
	case 7508ULL: goto x86_l_1d54;
	case 7516ULL: goto x86_l_1d5c;
	case 7521ULL: goto x86_l_1d61;
	case 7526ULL: goto x86_l_1d66;
	case 7530ULL: goto x86_l_1d6a;
	case 7536ULL: goto x86_l_1d70;
	case 7540ULL: goto x86_l_1d74;
	case 7542ULL: goto x86_l_1d76;
	case 7547ULL: goto x86_l_1d7b;
	case 7551ULL: goto x86_l_1d7f;
	case 7553ULL: goto x86_l_1d81;
	case 7557ULL: goto x86_l_1d85;
	case 7563ULL: goto x86_l_1d8b;
	case 7568ULL: goto x86_l_1d90;
	case 7573ULL: goto x86_l_1d95;
	case 7578ULL: goto x86_l_1d9a;
	case 7580ULL: goto x86_l_1d9c;
	case 7583ULL: goto x86_l_1d9f;
	case 7589ULL: goto x86_l_1da5;
	case 7591ULL: goto x86_l_1da7;
	case 7596ULL: goto x86_l_1dac;
	case 7603ULL: goto x86_l_1db3;
	case 7613ULL: goto x86_l_1dbd;
	case 7618ULL: goto x86_l_1dc2;
	case 7623ULL: goto x86_l_1dc7;
	case 7630ULL: goto x86_l_1dce;
	case 7635ULL: goto x86_l_1dd3;
	case 7637ULL: goto x86_l_1dd5;
	case 7640ULL: goto x86_l_1dd8;
	case 7646ULL: goto x86_l_1dde;
	case 7654ULL: goto x86_l_1de6;
	case 7659ULL: goto x86_l_1deb;
	case 7664ULL: goto x86_l_1df0;
	case 7669ULL: goto x86_l_1df5;
	case 7674ULL: goto x86_l_1dfa;
	case 7679ULL: goto x86_l_1dff;
	case 7681ULL: goto x86_l_1e01;
	case 7684ULL: goto x86_l_1e04;
	case 7690ULL: goto x86_l_1e0a;
	case 7692ULL: goto x86_l_1e0c;
	case 7697ULL: goto x86_l_1e11;
	case 7704ULL: goto x86_l_1e18;
	case 7714ULL: goto x86_l_1e22;
	case 7719ULL: goto x86_l_1e27;
	case 7724ULL: goto x86_l_1e2c;
	case 7731ULL: goto x86_l_1e33;
	case 7736ULL: goto x86_l_1e38;
	case 7738ULL: goto x86_l_1e3a;
	case 7741ULL: goto x86_l_1e3d;
	case 7747ULL: goto x86_l_1e43;
	case 7749ULL: goto x86_l_1e45;
	case 7754ULL: goto x86_l_1e4a;
	case 7759ULL: goto x86_l_1e4f;
	case 7767ULL: goto x86_l_1e57;
	case 7772ULL: goto x86_l_1e5c;
	case 7779ULL: goto x86_l_1e63;
	case 7784ULL: goto x86_l_1e68;
	case 7789ULL: goto x86_l_1e6d;
	case 7791ULL: goto x86_l_1e6f;
	case 7793ULL: goto x86_l_1e71;
	case 7798ULL: goto x86_l_1e76;
	case 7802ULL: goto x86_l_1e7a;
	case 7808ULL: goto x86_l_1e80;
	case 7813ULL: goto x86_l_1e85;
	case 7815ULL: goto x86_l_1e87;
	case 7819ULL: goto x86_l_1e8b;
	case 7824ULL: goto x86_l_1e90;
	case 7829ULL: goto x86_l_1e95;
	case 7834ULL: goto x86_l_1e9a;
	case 7836ULL: goto x86_l_1e9c;
	case 7840ULL: goto x86_l_1ea0;
	case 7843ULL: goto x86_l_1ea3;
	case 7846ULL: goto x86_l_1ea6;
	case 7849ULL: goto x86_l_1ea9;
	case 7854ULL: goto x86_l_1eae;
	case 7858ULL: goto x86_l_1eb2;
	case 7864ULL: goto x86_l_1eb8;
	case 7869ULL: goto x86_l_1ebd;
	case 7874ULL: goto x86_l_1ec2;
	case 7879ULL: goto x86_l_1ec7;
	case 7881ULL: goto x86_l_1ec9;
	case 7884ULL: goto x86_l_1ecc;
	case 7890ULL: goto x86_l_1ed2;
	case 7892ULL: goto x86_l_1ed4;
	case 7897ULL: goto x86_l_1ed9;
	case 7904ULL: goto x86_l_1ee0;
	case 7914ULL: goto x86_l_1eea;
	case 7919ULL: goto x86_l_1eef;
	case 7924ULL: goto x86_l_1ef4;
	case 7931ULL: goto x86_l_1efb;
	case 7936ULL: goto x86_l_1f00;
	case 7938ULL: goto x86_l_1f02;
	case 7941ULL: goto x86_l_1f05;
	case 7947ULL: goto x86_l_1f0b;
	case 7955ULL: goto x86_l_1f13;
	case 7960ULL: goto x86_l_1f18;
	case 7965ULL: goto x86_l_1f1d;
	case 7968ULL: goto x86_l_1f20;
	case 7973ULL: goto x86_l_1f25;
	case 7978ULL: goto x86_l_1f2a;
	case 7983ULL: goto x86_l_1f2f;
	case 7988ULL: goto x86_l_1f34;
	case 7990ULL: goto x86_l_1f36;
	case 7993ULL: goto x86_l_1f39;
	case 7999ULL: goto x86_l_1f3f;
	case 8001ULL: goto x86_l_1f41;
	case 8006ULL: goto x86_l_1f46;
	case 8013ULL: goto x86_l_1f4d;
	case 8023ULL: goto x86_l_1f57;
	case 8028ULL: goto x86_l_1f5c;
	case 8033ULL: goto x86_l_1f61;
	case 8040ULL: goto x86_l_1f68;
	case 8045ULL: goto x86_l_1f6d;
	case 8047ULL: goto x86_l_1f6f;
	case 8050ULL: goto x86_l_1f72;
	case 8056ULL: goto x86_l_1f78;
	case 8064ULL: goto x86_l_1f80;
	case 8069ULL: goto x86_l_1f85;
	case 8074ULL: goto x86_l_1f8a;
	case 8079ULL: goto x86_l_1f8f;
	case 8084ULL: goto x86_l_1f94;
	case 8089ULL: goto x86_l_1f99;
	case 8091ULL: goto x86_l_1f9b;
	case 8094ULL: goto x86_l_1f9e;
	case 8100ULL: goto x86_l_1fa4;
	case 8102ULL: goto x86_l_1fa6;
	case 8107ULL: goto x86_l_1fab;
	case 8114ULL: goto x86_l_1fb2;
	case 8124ULL: goto x86_l_1fbc;
	case 8129ULL: goto x86_l_1fc1;
	case 8134ULL: goto x86_l_1fc6;
	case 8141ULL: goto x86_l_1fcd;
	case 8146ULL: goto x86_l_1fd2;
	case 8148ULL: goto x86_l_1fd4;
	case 8151ULL: goto x86_l_1fd7;
	case 8157ULL: goto x86_l_1fdd;
	case 8159ULL: goto x86_l_1fdf;
	case 8165ULL: goto x86_l_1fe5;
	case 8170ULL: goto x86_l_1fea;
	case 8175ULL: goto x86_l_1fef;
	case 8180ULL: goto x86_l_1ff4;
	case 8185ULL: goto x86_l_1ff9;
	case 8187ULL: goto x86_l_1ffb;
	case 8190ULL: goto x86_l_1ffe;
	case 8196ULL: goto x86_l_2004;
	case 8198ULL: goto x86_l_2006;
	case 8203ULL: goto x86_l_200b;
	case 8210ULL: goto x86_l_2012;
	case 8220ULL: goto x86_l_201c;
	case 8225ULL: goto x86_l_2021;
	case 8230ULL: goto x86_l_2026;
	case 8237ULL: goto x86_l_202d;
	case 8242ULL: goto x86_l_2032;
	case 8244ULL: goto x86_l_2034;
	case 8247ULL: goto x86_l_2037;
	case 8249ULL: goto x86_l_2039;
	case 8257ULL: goto x86_l_2041;
	case 8262ULL: goto x86_l_2046;
	case 8267ULL: goto x86_l_204b;
	case 8272ULL: goto x86_l_2050;
	case 8277ULL: goto x86_l_2055;
	case 8282ULL: goto x86_l_205a;
	case 8284ULL: goto x86_l_205c;
	case 8287ULL: goto x86_l_205f;
	case 8293ULL: goto x86_l_2065;
	case 8295ULL: goto x86_l_2067;
	case 8300ULL: goto x86_l_206c;
	case 8307ULL: goto x86_l_2073;
	case 8317ULL: goto x86_l_207d;
	case 8322ULL: goto x86_l_2082;
	case 8327ULL: goto x86_l_2087;
	case 8334ULL: goto x86_l_208e;
	case 8339ULL: goto x86_l_2093;
	case 8341ULL: goto x86_l_2095;
	case 8344ULL: goto x86_l_2098;
	case 8350ULL: goto x86_l_209e;
	case 8352ULL: goto x86_l_20a0;
	case 8357ULL: goto x86_l_20a5;
	case 8362ULL: goto x86_l_20aa;
	case 8367ULL: goto x86_l_20af;
	case 8372ULL: goto x86_l_20b4;
	case 8374ULL: goto x86_l_20b6;
	case 8377ULL: goto x86_l_20b9;
	case 8383ULL: goto x86_l_20bf;
	case 8385ULL: goto x86_l_20c1;
	case 8390ULL: goto x86_l_20c6;
	case 8397ULL: goto x86_l_20cd;
	case 8407ULL: goto x86_l_20d7;
	case 8412ULL: goto x86_l_20dc;
	case 8417ULL: goto x86_l_20e1;
	case 8424ULL: goto x86_l_20e8;
	case 8429ULL: goto x86_l_20ed;
	case 8431ULL: goto x86_l_20ef;
	case 8434ULL: goto x86_l_20f2;
	case 8440ULL: goto x86_l_20f8;
	case 8442ULL: goto x86_l_20fa;
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
	case 8513ULL: goto x86_l_2141;
	case 8520ULL: goto x86_l_2148;
	case 8525ULL: goto x86_l_214d;
	case 8527ULL: goto x86_l_214f;
	case 8530ULL: goto x86_l_2152;
	case 8536ULL: goto x86_l_2158;
	case 8538ULL: goto x86_l_215a;
	case 8543ULL: goto x86_l_215f;
	case 8548ULL: goto x86_l_2164;
	case 8556ULL: goto x86_l_216c;
	case 8561ULL: goto x86_l_2171;
	case 8568ULL: goto x86_l_2178;
	case 8573ULL: goto x86_l_217d;
	case 8578ULL: goto x86_l_2182;
	case 8580ULL: goto x86_l_2184;
	case 8582ULL: goto x86_l_2186;
	case 8587ULL: goto x86_l_218b;
	case 8592ULL: goto x86_l_2190;
	case 8600ULL: goto x86_l_2198;
	case 8605ULL: goto x86_l_219d;
	case 8612ULL: goto x86_l_21a4;
	case 8617ULL: goto x86_l_21a9;
	case 8622ULL: goto x86_l_21ae;
	case 8624ULL: goto x86_l_21b0;
	case 8626ULL: goto x86_l_21b2;
	case 8632ULL: goto x86_l_21b8;
	case 8637ULL: goto x86_l_21bd;
	case 8645ULL: goto x86_l_21c5;
	case 8650ULL: goto x86_l_21ca;
	case 8657ULL: goto x86_l_21d1;
	case 8662ULL: goto x86_l_21d6;
	case 8667ULL: goto x86_l_21db;
	case 8669ULL: goto x86_l_21dd;
	case 8671ULL: goto x86_l_21df;
	case 8677ULL: goto x86_l_21e5;
	case 8682ULL: goto x86_l_21ea;
	case 8690ULL: goto x86_l_21f2;
	case 8695ULL: goto x86_l_21f7;
	case 8702ULL: goto x86_l_21fe;
	case 8707ULL: goto x86_l_2203;
	case 8712ULL: goto x86_l_2208;
	case 8714ULL: goto x86_l_220a;
	case 8716ULL: goto x86_l_220c;
	case 8722ULL: goto x86_l_2212;
	case 8724ULL: goto x86_l_2214;
	case 8732ULL: goto x86_l_221c;
	case 8737ULL: goto x86_l_2221;
	case 8744ULL: goto x86_l_2228;
	case 8749ULL: goto x86_l_222d;
	case 8754ULL: goto x86_l_2232;
	case 8756ULL: goto x86_l_2234;
	case 8758ULL: goto x86_l_2236;
	case 8763ULL: goto x86_l_223b;
	case 8765ULL: goto x86_l_223d;
	case 8773ULL: goto x86_l_2245;
	case 8778ULL: goto x86_l_224a;
	case 8785ULL: goto x86_l_2251;
	case 8790ULL: goto x86_l_2256;
	case 8795ULL: goto x86_l_225b;
	case 8797ULL: goto x86_l_225d;
	case 8799ULL: goto x86_l_225f;
	case 8805ULL: goto x86_l_2265;
	case 8807ULL: goto x86_l_2267;
	case 8815ULL: goto x86_l_226f;
	case 8820ULL: goto x86_l_2274;
	case 8827ULL: goto x86_l_227b;
	case 8832ULL: goto x86_l_2280;
	case 8837ULL: goto x86_l_2285;
	case 8839ULL: goto x86_l_2287;
	case 8841ULL: goto x86_l_2289;
	case 8846ULL: goto x86_l_228e;
	case 8853ULL: goto x86_l_2295;
	case 8858ULL: goto x86_l_229a;
	case 8862ULL: goto x86_l_229e;
	case 8865ULL: goto x86_l_22a1;
	case 8868ULL: goto x86_l_22a4;
	case 8872ULL: goto x86_l_22a8;
	case 8874ULL: goto x86_l_22aa;
	case 8878ULL: goto x86_l_22ae;
	case 8884ULL: goto x86_l_22b4;
	case 8888ULL: goto x86_l_22b8;
	case 8894ULL: goto x86_l_22be;
	case 8898ULL: goto x86_l_22c2;
	case 8904ULL: goto x86_l_22c8;
	case 8908ULL: goto x86_l_22cc;
	case 8914ULL: goto x86_l_22d2;
	case 8918ULL: goto x86_l_22d6;
	case 8924ULL: goto x86_l_22dc;
	case 8929ULL: goto x86_l_22e1;
	case 8933ULL: goto x86_l_22e5;
	case 8939ULL: goto x86_l_22eb;
	case 8943ULL: goto x86_l_22ef;
	case 8949ULL: goto x86_l_22f5;
	case 8953ULL: goto x86_l_22f9;
	case 8959ULL: goto x86_l_22ff;
	case 8963ULL: goto x86_l_2303;
	case 8969ULL: goto x86_l_2309;
	case 8973ULL: goto x86_l_230d;
	case 8979ULL: goto x86_l_2313;
	case 8984ULL: goto x86_l_2318;
	case 8989ULL: goto x86_l_231d;
	case 8994ULL: goto x86_l_2322;
	case 8996ULL: goto x86_l_2324;
	case 8999ULL: goto x86_l_2327;
	case 9005ULL: goto x86_l_232d;
	case 9007ULL: goto x86_l_232f;
	case 9012ULL: goto x86_l_2334;
	case 9019ULL: goto x86_l_233b;
	case 9029ULL: goto x86_l_2345;
	case 9034ULL: goto x86_l_234a;
	case 9039ULL: goto x86_l_234f;
	case 9046ULL: goto x86_l_2356;
	case 9051ULL: goto x86_l_235b;
	case 9053ULL: goto x86_l_235d;
	case 9056ULL: goto x86_l_2360;
	case 9062ULL: goto x86_l_2366;
	case 9064ULL: goto x86_l_2368;
	case 9070ULL: goto x86_l_236e;
	case 9075ULL: goto x86_l_2373;
	case 9079ULL: goto x86_l_2377;
	case 9085ULL: goto x86_l_237d;
	case 9090ULL: goto x86_l_2382;
	case 9093ULL: goto x86_l_2385;
	case 9099ULL: goto x86_l_238b;
	case 9103ULL: goto x86_l_238f;
	case 9109ULL: goto x86_l_2395;
	case 9114ULL: goto x86_l_239a;
	case 9119ULL: goto x86_l_239f;
	case 9124ULL: goto x86_l_23a4;
	case 9126ULL: goto x86_l_23a6;
	case 9129ULL: goto x86_l_23a9;
	case 9135ULL: goto x86_l_23af;
	case 9137ULL: goto x86_l_23b1;
	case 9142ULL: goto x86_l_23b6;
	case 9149ULL: goto x86_l_23bd;
	case 9159ULL: goto x86_l_23c7;
	case 9164ULL: goto x86_l_23cc;
	case 9169ULL: goto x86_l_23d1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c9d:
	/* 0x1c9d: je     1e71 <generic_tracepoint_event+0x1e71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e71;
	}
x86_l_1ca3:
	/* 0x1ca3: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1ca5:
	/* 0x1ca5: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1caa:
	/* 0x1caa: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1cb1:
	/* 0x1cb1: movabs rax,0x400000045 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869253ULL);
x86_l_1cbb:
	/* 0x1cbb: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1cc0:
	/* 0x1cc0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cc5:
	/* 0x1cc5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1ccc:
	/* 0x1ccc: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cd1:
	/* 0x1cd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd3:
	/* 0x1cd3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cd6:
	/* 0x1cd6: je     1e4f <generic_tracepoint_event+0x1e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e4f;
	}
x86_l_1cdc:
	/* 0x1cdc: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1cde:
	/* 0x1cde: jmp    1e71 <generic_tracepoint_event+0x1e71> */
	goto x86_l_1e71;
x86_l_1ce3:
	/* 0x1ce3: cmp    r13d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 38ULL);
x86_l_1ce7:
	/* 0x1ce7: je     2105 <generic_tracepoint_event+0x2105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2105;
	}
x86_l_1ced:
	/* 0x1ced: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_1cf1:
	/* 0x1cf1: je     1fea <generic_tracepoint_event+0x1fea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fea;
	}
x86_l_1cf7:
	/* 0x1cf7: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_1cfb:
	/* 0x1cfb: jne    228e <generic_tracepoint_event+0x228e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_228e;
	}
x86_l_1d01:
	/* 0x1d01: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d06:
	/* 0x1d06: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d0b:
	/* 0x1d0b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d10:
	/* 0x1d10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d12:
	/* 0x1d12: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d15:
	/* 0x1d15: je     2236 <generic_tracepoint_event+0x2236> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2236;
	}
x86_l_1d1b:
	/* 0x1d1b: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1d1d:
	/* 0x1d1d: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d22:
	/* 0x1d22: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1d29:
	/* 0x1d29: movabs rax,0x4000000a8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869352ULL);
x86_l_1d33:
	/* 0x1d33: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1d38:
	/* 0x1d38: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d3d:
	/* 0x1d3d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1d44:
	/* 0x1d44: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d49:
	/* 0x1d49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d4b:
	/* 0x1d4b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d4e:
	/* 0x1d4e: jne    209e <generic_tracepoint_event+0x209e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_209e;
	}
x86_l_1d54:
	/* 0x1d54: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1d5c:
	/* 0x1d5c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1d61:
	/* 0x1d61: jmp    2221 <generic_tracepoint_event+0x2221> */
	goto x86_l_2221;
x86_l_1d66:
	/* 0x1d66: cmp    r13d,0xfffffff3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967283ULL);
x86_l_1d6a:
	/* 0x1d6a: je     1df0 <generic_tracepoint_event+0x1df0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1df0;
	}
x86_l_1d70:
	/* 0x1d70: cmp    r13d,0xfffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967284ULL);
x86_l_1d74:
	/* 0x1d74: je     1d8b <generic_tracepoint_event+0x1d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d8b;
	}
x86_l_1d76:
	/* 0x1d76: jmp    228e <generic_tracepoint_event+0x228e> */
	goto x86_l_228e;
x86_l_1d7b:
	/* 0x1d7b: cmp    r13d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 12ULL);
x86_l_1d7f:
	/* 0x1d7f: je     1df0 <generic_tracepoint_event+0x1df0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1df0;
	}
x86_l_1d81:
	/* 0x1d81: cmp    r13d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 13ULL);
x86_l_1d85:
	/* 0x1d85: jne    228e <generic_tracepoint_event+0x228e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_228e;
	}
x86_l_1d8b:
	/* 0x1d8b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d90:
	/* 0x1d90: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d95:
	/* 0x1d95: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d9a:
	/* 0x1d9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d9c:
	/* 0x1d9c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d9f:
	/* 0x1d9f: je     2289 <generic_tracepoint_event+0x2289> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2289;
	}
x86_l_1da5:
	/* 0x1da5: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1da7:
	/* 0x1da7: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dac:
	/* 0x1dac: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1db3:
	/* 0x1db3: movabs rax,0x40000005e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869278ULL);
x86_l_1dbd:
	/* 0x1dbd: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1dc2:
	/* 0x1dc2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dc7:
	/* 0x1dc7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1dce:
	/* 0x1dce: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dd3:
	/* 0x1dd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd5:
	/* 0x1dd5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dd8:
	/* 0x1dd8: jne    2158 <generic_tracepoint_event+0x2158> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2158;
	}
x86_l_1dde:
	/* 0x1dde: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1de6:
	/* 0x1de6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1deb:
	/* 0x1deb: jmp    2274 <generic_tracepoint_event+0x2274> */
	goto x86_l_2274;
x86_l_1df0:
	/* 0x1df0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1df5:
	/* 0x1df5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dfa:
	/* 0x1dfa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1dff:
	/* 0x1dff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e01:
	/* 0x1e01: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e04:
	/* 0x1e04: je     2186 <generic_tracepoint_event+0x2186> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2186;
	}
x86_l_1e0a:
	/* 0x1e0a: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1e0c:
	/* 0x1e0c: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e11:
	/* 0x1e11: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1e18:
	/* 0x1e18: movabs rax,0x400000056 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869270ULL);
x86_l_1e22:
	/* 0x1e22: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1e27:
	/* 0x1e27: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e2c:
	/* 0x1e2c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1e33:
	/* 0x1e33: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e38:
	/* 0x1e38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e3a:
	/* 0x1e3a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e3d:
	/* 0x1e3d: je     2164 <generic_tracepoint_event+0x2164> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2164;
	}
x86_l_1e43:
	/* 0x1e43: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1e45:
	/* 0x1e45: movsxd r12,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1e4a:
	/* 0x1e4a: jmp    228e <generic_tracepoint_event+0x228e> */
	goto x86_l_228e;
x86_l_1e4f:
	/* 0x1e4f: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1e57:
	/* 0x1e57: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e5c:
	/* 0x1e5c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1e63:
	/* 0x1e63: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e68:
	/* 0x1e68: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e6d:
	/* 0x1e6d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e6f:
	/* 0x1e6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e71:
	/* 0x1e71: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e76:
	/* 0x1e76: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_1e7a:
	/* 0x1e7a: jne    228e <generic_tracepoint_event+0x228e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_228e;
	}
x86_l_1e80:
	/* 0x1e80: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_1e85:
	/* 0x1e85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e87:
	/* 0x1e87: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e8b:
	/* 0x1e8b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e90:
	/* 0x1e90: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e95:
	/* 0x1e95: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e9a:
	/* 0x1e9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e9c:
	/* 0x1e9c: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ea0:
	/* 0x1ea0: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_1ea3:
	/* 0x1ea3: shl    eax,0x1e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 30ULL);
x86_l_1ea6:
	/* 0x1ea6: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1ea9:
	/* 0x1ea9: jmp    228e <generic_tracepoint_event+0x228e> */
	goto x86_l_228e;
x86_l_1eae:
	/* 0x1eae: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_1eb2:
	/* 0x1eb2: jne    228e <generic_tracepoint_event+0x228e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_228e;
	}
x86_l_1eb8:
	/* 0x1eb8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ebd:
	/* 0x1ebd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ec2:
	/* 0x1ec2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ec7:
	/* 0x1ec7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ec9:
	/* 0x1ec9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ecc:
	/* 0x1ecc: je     2236 <generic_tracepoint_event+0x2236> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2236;
	}
x86_l_1ed2:
	/* 0x1ed2: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1ed4:
	/* 0x1ed4: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ed9:
	/* 0x1ed9: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1ee0:
	/* 0x1ee0: movabs rax,0x40000009a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869338ULL);
x86_l_1eea:
	/* 0x1eea: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1eef:
	/* 0x1eef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ef4:
	/* 0x1ef4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1efb:
	/* 0x1efb: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f00:
	/* 0x1f00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f02:
	/* 0x1f02: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f05:
	/* 0x1f05: jne    209e <generic_tracepoint_event+0x209e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_209e;
	}
x86_l_1f0b:
	/* 0x1f0b: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1f13:
	/* 0x1f13: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1f18:
	/* 0x1f18: jmp    2221 <generic_tracepoint_event+0x2221> */
	goto x86_l_2221;
x86_l_1f1d:
	/* 0x1f1d: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_1f20:
	/* 0x1f20: jmp    228e <generic_tracepoint_event+0x228e> */
	goto x86_l_228e;
x86_l_1f25:
	/* 0x1f25: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f2a:
	/* 0x1f2a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f2f:
	/* 0x1f2f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f34:
	/* 0x1f34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f36:
	/* 0x1f36: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f39:
	/* 0x1f39: je     2236 <generic_tracepoint_event+0x2236> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2236;
	}
x86_l_1f3f:
	/* 0x1f3f: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1f41:
	/* 0x1f41: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f46:
	/* 0x1f46: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1f4d:
	/* 0x1f4d: movabs rax,0x400000093 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869331ULL);
x86_l_1f57:
	/* 0x1f57: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1f5c:
	/* 0x1f5c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f61:
	/* 0x1f61: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1f68:
	/* 0x1f68: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f6d:
	/* 0x1f6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f6f:
	/* 0x1f6f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f72:
	/* 0x1f72: jne    209e <generic_tracepoint_event+0x209e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_209e;
	}
x86_l_1f78:
	/* 0x1f78: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1f80:
	/* 0x1f80: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1f85:
	/* 0x1f85: jmp    2221 <generic_tracepoint_event+0x2221> */
	goto x86_l_2221;
x86_l_1f8a:
	/* 0x1f8a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f8f:
	/* 0x1f8f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f94:
	/* 0x1f94: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1f99:
	/* 0x1f99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f9b:
	/* 0x1f9b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f9e:
	/* 0x1f9e: je     21df <generic_tracepoint_event+0x21df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21df;
	}
x86_l_1fa4:
	/* 0x1fa4: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1fa6:
	/* 0x1fa6: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fab:
	/* 0x1fab: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_1fb2:
	/* 0x1fb2: movabs rax,0x40000007a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869306ULL);
x86_l_1fbc:
	/* 0x1fbc: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1fc1:
	/* 0x1fc1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fc6:
	/* 0x1fc6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1fcd:
	/* 0x1fcd: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fd2:
	/* 0x1fd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fd4:
	/* 0x1fd4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fd7:
	/* 0x1fd7: je     21bd <generic_tracepoint_event+0x21bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21bd;
	}
x86_l_1fdd:
	/* 0x1fdd: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1fdf:
	/* 0x1fdf: movsx  r12,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1fe5:
	/* 0x1fe5: jmp    228e <generic_tracepoint_event+0x228e> */
	goto x86_l_228e;
x86_l_1fea:
	/* 0x1fea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fef:
	/* 0x1fef: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ff4:
	/* 0x1ff4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ff9:
	/* 0x1ff9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ffb:
	/* 0x1ffb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ffe:
	/* 0x1ffe: je     2236 <generic_tracepoint_event+0x2236> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2236;
	}
x86_l_2004:
	/* 0x2004: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2006:
	/* 0x2006: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_200b:
	/* 0x200b: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2012:
	/* 0x2012: movabs rax,0x4000000a1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869345ULL);
x86_l_201c:
	/* 0x201c: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2021:
	/* 0x2021: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2026:
	/* 0x2026: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_202d:
	/* 0x202d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2032:
	/* 0x2032: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2034:
	/* 0x2034: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2037:
	/* 0x2037: jne    209e <generic_tracepoint_event+0x209e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_209e;
	}
x86_l_2039:
	/* 0x2039: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2041:
	/* 0x2041: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2046:
	/* 0x2046: jmp    2221 <generic_tracepoint_event+0x2221> */
	goto x86_l_2221;
x86_l_204b:
	/* 0x204b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2050:
	/* 0x2050: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2055:
	/* 0x2055: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_205a:
	/* 0x205a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_205c:
	/* 0x205c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_205f:
	/* 0x205f: je     2236 <generic_tracepoint_event+0x2236> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2236;
	}
x86_l_2065:
	/* 0x2065: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2067:
	/* 0x2067: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_206c:
	/* 0x206c: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2073:
	/* 0x2073: movabs rax,0x40000004e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869262ULL);
x86_l_207d:
	/* 0x207d: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2082:
	/* 0x2082: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2087:
	/* 0x2087: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_208e:
	/* 0x208e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2093:
	/* 0x2093: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2095:
	/* 0x2095: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2098:
	/* 0x2098: je     2214 <generic_tracepoint_event+0x2214> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2214;
	}
x86_l_209e:
	/* 0x209e: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_20a0:
	/* 0x20a0: jmp    2236 <generic_tracepoint_event+0x2236> */
	goto x86_l_2236;
x86_l_20a5:
	/* 0x20a5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20aa:
	/* 0x20aa: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20af:
	/* 0x20af: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_20b4:
	/* 0x20b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20b6:
	/* 0x20b6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20b9:
	/* 0x20b9: je     225f <generic_tracepoint_event+0x225f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_225f;
	}
x86_l_20bf:
	/* 0x20bf: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_20c1:
	/* 0x20c1: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20c6:
	/* 0x20c6: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_20cd:
	/* 0x20cd: movabs rax,0x400000065 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869285ULL);
x86_l_20d7:
	/* 0x20d7: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_20dc:
	/* 0x20dc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20e1:
	/* 0x20e1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_20e8:
	/* 0x20e8: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20ed:
	/* 0x20ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ef:
	/* 0x20ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20f2:
	/* 0x20f2: je     223d <generic_tracepoint_event+0x223d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_223d;
	}
x86_l_20f8:
	/* 0x20f8: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_20fa:
	/* 0x20fa: movzx  r12d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2100:
	/* 0x2100: jmp    228e <generic_tracepoint_event+0x228e> */
	goto x86_l_228e;
x86_l_2105:
	/* 0x2105: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_210a:
	/* 0x210a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
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
	/* 0x2119: je     2289 <generic_tracepoint_event+0x2289> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2289;
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
	/* 0x212d: movabs rax,0x400000088 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869320ULL);
x86_l_2137:
	/* 0x2137: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_213c:
	/* 0x213c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2141:
	/* 0x2141: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2148:
	/* 0x2148: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_214d:
	/* 0x214d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_214f:
	/* 0x214f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2152:
	/* 0x2152: je     2267 <generic_tracepoint_event+0x2267> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2267;
	}
x86_l_2158:
	/* 0x2158: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_215a:
	/* 0x215a: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_215f:
	/* 0x215f: jmp    228e <generic_tracepoint_event+0x228e> */
	goto x86_l_228e;
x86_l_2164:
	/* 0x2164: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_216c:
	/* 0x216c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2171:
	/* 0x2171: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2178:
	/* 0x2178: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_217d:
	/* 0x217d: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2182:
	/* 0x2182: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2184:
	/* 0x2184: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2186:
	/* 0x2186: movsxd r12,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_218b:
	/* 0x218b: jmp    228e <generic_tracepoint_event+0x228e> */
	goto x86_l_228e;
x86_l_2190:
	/* 0x2190: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_2198:
	/* 0x2198: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_219d:
	/* 0x219d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_21a4:
	/* 0x21a4: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21a9:
	/* 0x21a9: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21ae:
	/* 0x21ae: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21b0:
	/* 0x21b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21b2:
	/* 0x21b2: movsx  r12,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_21b8:
	/* 0x21b8: jmp    228e <generic_tracepoint_event+0x228e> */
	goto x86_l_228e;
x86_l_21bd:
	/* 0x21bd: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_21c5:
	/* 0x21c5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_21ca:
	/* 0x21ca: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_21d1:
	/* 0x21d1: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21d6:
	/* 0x21d6: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21db:
	/* 0x21db: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21dd:
	/* 0x21dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21df:
	/* 0x21df: movsx  r12,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_21e5:
	/* 0x21e5: jmp    228e <generic_tracepoint_event+0x228e> */
	goto x86_l_228e;
x86_l_21ea:
	/* 0x21ea: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_21f2:
	/* 0x21f2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_21f7:
	/* 0x21f7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_21fe:
	/* 0x21fe: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2203:
	/* 0x2203: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2208:
	/* 0x2208: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_220a:
	/* 0x220a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_220c:
	/* 0x220c: movzx  r12d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_2212:
	/* 0x2212: jmp    228e <generic_tracepoint_event+0x228e> */
	goto x86_l_228e;
x86_l_2214:
	/* 0x2214: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_221c:
	/* 0x221c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2221:
	/* 0x2221: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2228:
	/* 0x2228: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_222d:
	/* 0x222d: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2232:
	/* 0x2232: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2234:
	/* 0x2234: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2236:
	/* 0x2236: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_223b:
	/* 0x223b: jmp    228e <generic_tracepoint_event+0x228e> */
	goto x86_l_228e;
x86_l_223d:
	/* 0x223d: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_2245:
	/* 0x2245: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_224a:
	/* 0x224a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2251:
	/* 0x2251: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2256:
	/* 0x2256: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_225b:
	/* 0x225b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_225d:
	/* 0x225d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_225f:
	/* 0x225f: movzx  r12d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2265:
	/* 0x2265: jmp    228e <generic_tracepoint_event+0x228e> */
	goto x86_l_228e;
x86_l_2267:
	/* 0x2267: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_226f:
	/* 0x226f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2274:
	/* 0x2274: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_227b:
	/* 0x227b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2280:
	/* 0x2280: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2285:
	/* 0x2285: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2287:
	/* 0x2287: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2289:
	/* 0x2289: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_228e:
	/* 0x228e: mov    QWORD PTR [r14+0x5e68],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24168ULL);
x86_l_2295:
	/* 0x2295: movzx  edx,WORD PTR [r15+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 60ULL);
x86_l_229a:
	/* 0x229a: mov    r12d,DWORD PTR [r15+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_229e:
	/* 0x229e: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_22a1:
	/* 0x22a1: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22a4:
	/* 0x22a4: cmp    r12d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 11ULL);
x86_l_22a8:
	/* 0x22a8: jg     22e1 <generic_tracepoint_event+0x22e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_22e1;
	}
x86_l_22aa:
	/* 0x22aa: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_22ae:
	/* 0x22ae: jle    2373 <generic_tracepoint_event+0x2373> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2373;
	}
x86_l_22b4:
	/* 0x22b4: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_22b8:
	/* 0x22b8: jg     247e <generic_tracepoint_event+0x247e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9342ULL;
	}
x86_l_22be:
	/* 0x22be: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_22c2:
	/* 0x22c2: je     284e <generic_tracepoint_event+0x284e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10318ULL;
	}
x86_l_22c8:
	/* 0x22c8: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_22cc:
	/* 0x22cc: je     2728 <generic_tracepoint_event+0x2728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10024ULL;
	}
x86_l_22d2:
	/* 0x22d2: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_22d6:
	/* 0x22d6: je     2395 <generic_tracepoint_event+0x2395> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2395;
	}
x86_l_22dc:
	/* 0x22dc: jmp    2a91 <generic_tracepoint_event+0x2a91> */
	return 10897ULL;
x86_l_22e1:
	/* 0x22e1: cmp    r12d,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 29ULL);
x86_l_22e5:
	/* 0x22e5: jle    23fa <generic_tracepoint_event+0x23fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 9210ULL;
	}
x86_l_22eb:
	/* 0x22eb: cmp    r12d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 37ULL);
x86_l_22ef:
	/* 0x22ef: jg     24e6 <generic_tracepoint_event+0x24e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9446ULL;
	}
x86_l_22f5:
	/* 0x22f5: cmp    r12d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 30ULL);
x86_l_22f9:
	/* 0x22f9: je     28a8 <generic_tracepoint_event+0x28a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10408ULL;
	}
x86_l_22ff:
	/* 0x22ff: cmp    r12d,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 31ULL);
x86_l_2303:
	/* 0x2303: je     278d <generic_tracepoint_event+0x278d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10125ULL;
	}
x86_l_2309:
	/* 0x2309: cmp    r12d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 32ULL);
x86_l_230d:
	/* 0x230d: jne    2a91 <generic_tracepoint_event+0x2a91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10897ULL;
	}
x86_l_2313:
	/* 0x2313: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2318:
	/* 0x2318: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_231d:
	/* 0x231d: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_2322:
	/* 0x2322: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2324:
	/* 0x2324: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2327:
	/* 0x2327: je     2a0f <generic_tracepoint_event+0x2a0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10767ULL;
	}
x86_l_232d:
	/* 0x232d: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_232f:
	/* 0x232f: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2334:
	/* 0x2334: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_233b:
	/* 0x233b: movabs rax,0x400000073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869299ULL);
x86_l_2345:
	/* 0x2345: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_234a:
	/* 0x234a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_234f:
	/* 0x234f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2356:
	/* 0x2356: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_235b:
	/* 0x235b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_235d:
	/* 0x235d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2360:
	/* 0x2360: je     29ed <generic_tracepoint_event+0x29ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10733ULL;
	}
x86_l_2366:
	/* 0x2366: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2368:
	/* 0x2368: movzx  r15d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_236e:
	/* 0x236e: jmp    2a91 <generic_tracepoint_event+0x2a91> */
	return 10897ULL;
x86_l_2373:
	/* 0x2373: cmp    r12d,0xfffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967284ULL);
x86_l_2377:
	/* 0x2377: jle    2569 <generic_tracepoint_event+0x2569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 9577ULL;
	}
x86_l_237d:
	/* 0x237d: lea    eax,[r12+0xb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_2382:
	/* 0x2382: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2385:
	/* 0x2385: jb     248c <generic_tracepoint_event+0x248c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9356ULL;
	}
x86_l_238b:
	/* 0x238b: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_238f:
	/* 0x238f: jne    2a91 <generic_tracepoint_event+0x2a91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10897ULL;
	}
x86_l_2395:
	/* 0x2395: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_239a:
	/* 0x239a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_239f:
	/* 0x239f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23a4:
	/* 0x23a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23a6:
	/* 0x23a6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23a9:
	/* 0x23a9: je     2a39 <generic_tracepoint_event+0x2a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10809ULL;
	}
x86_l_23af:
	/* 0x23af: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_23b1:
	/* 0x23b1: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23b6:
	/* 0x23b6: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_23bd:
	/* 0x23bd: movabs rax,0x400000081 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869313ULL);
x86_l_23c7:
	/* 0x23c7: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_23cc:
	/* 0x23cc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23d1:
	/* 0x23d1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
	return 9176ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9176ULL: goto x86_l_23d8;
	case 9181ULL: goto x86_l_23dd;
	case 9183ULL: goto x86_l_23df;
	case 9186ULL: goto x86_l_23e2;
	case 9192ULL: goto x86_l_23e8;
	case 9200ULL: goto x86_l_23f0;
	case 9205ULL: goto x86_l_23f5;
	case 9210ULL: goto x86_l_23fa;
	case 9214ULL: goto x86_l_23fe;
	case 9220ULL: goto x86_l_2404;
	case 9224ULL: goto x86_l_2408;
	case 9230ULL: goto x86_l_240e;
	case 9234ULL: goto x86_l_2412;
	case 9236ULL: goto x86_l_2414;
	case 9240ULL: goto x86_l_2418;
	case 9246ULL: goto x86_l_241e;
	case 9251ULL: goto x86_l_2423;
	case 9256ULL: goto x86_l_2428;
	case 9261ULL: goto x86_l_242d;
	case 9263ULL: goto x86_l_242f;
	case 9266ULL: goto x86_l_2432;
	case 9272ULL: goto x86_l_2438;
	case 9274ULL: goto x86_l_243a;
	case 9279ULL: goto x86_l_243f;
	case 9286ULL: goto x86_l_2446;
	case 9296ULL: goto x86_l_2450;
	case 9301ULL: goto x86_l_2455;
	case 9306ULL: goto x86_l_245a;
	case 9313ULL: goto x86_l_2461;
	case 9318ULL: goto x86_l_2466;
	case 9320ULL: goto x86_l_2468;
	case 9323ULL: goto x86_l_246b;
	case 9329ULL: goto x86_l_2471;
	case 9331ULL: goto x86_l_2473;
	case 9337ULL: goto x86_l_2479;
	case 9342ULL: goto x86_l_247e;
	case 9347ULL: goto x86_l_2483;
	case 9350ULL: goto x86_l_2486;
	case 9356ULL: goto x86_l_248c;
	case 9361ULL: goto x86_l_2491;
	case 9366ULL: goto x86_l_2496;
	case 9371ULL: goto x86_l_249b;
	case 9373ULL: goto x86_l_249d;
	case 9376ULL: goto x86_l_24a0;
	case 9382ULL: goto x86_l_24a6;
	case 9384ULL: goto x86_l_24a8;
	case 9389ULL: goto x86_l_24ad;
	case 9396ULL: goto x86_l_24b4;
	case 9406ULL: goto x86_l_24be;
	case 9411ULL: goto x86_l_24c3;
	case 9416ULL: goto x86_l_24c8;
	case 9423ULL: goto x86_l_24cf;
	case 9428ULL: goto x86_l_24d4;
	case 9430ULL: goto x86_l_24d6;
	case 9433ULL: goto x86_l_24d9;
	case 9439ULL: goto x86_l_24df;
	case 9441ULL: goto x86_l_24e1;
	case 9446ULL: goto x86_l_24e6;
	case 9450ULL: goto x86_l_24ea;
	case 9456ULL: goto x86_l_24f0;
	case 9460ULL: goto x86_l_24f4;
	case 9466ULL: goto x86_l_24fa;
	case 9470ULL: goto x86_l_24fe;
	case 9476ULL: goto x86_l_2504;
	case 9481ULL: goto x86_l_2509;
	case 9486ULL: goto x86_l_250e;
	case 9491ULL: goto x86_l_2513;
	case 9493ULL: goto x86_l_2515;
	case 9496ULL: goto x86_l_2518;
	case 9502ULL: goto x86_l_251e;
	case 9504ULL: goto x86_l_2520;
	case 9509ULL: goto x86_l_2525;
	case 9516ULL: goto x86_l_252c;
	case 9526ULL: goto x86_l_2536;
	case 9531ULL: goto x86_l_253b;
	case 9536ULL: goto x86_l_2540;
	case 9543ULL: goto x86_l_2547;
	case 9548ULL: goto x86_l_254c;
	case 9550ULL: goto x86_l_254e;
	case 9553ULL: goto x86_l_2551;
	case 9559ULL: goto x86_l_2557;
	case 9567ULL: goto x86_l_255f;
	case 9572ULL: goto x86_l_2564;
	case 9577ULL: goto x86_l_2569;
	case 9581ULL: goto x86_l_256d;
	case 9587ULL: goto x86_l_2573;
	case 9591ULL: goto x86_l_2577;
	case 9593ULL: goto x86_l_2579;
	case 9598ULL: goto x86_l_257e;
	case 9602ULL: goto x86_l_2582;
	case 9604ULL: goto x86_l_2584;
	case 9608ULL: goto x86_l_2588;
	case 9614ULL: goto x86_l_258e;
	case 9619ULL: goto x86_l_2593;
	case 9624ULL: goto x86_l_2598;
	case 9629ULL: goto x86_l_259d;
	case 9631ULL: goto x86_l_259f;
	case 9634ULL: goto x86_l_25a2;
	case 9640ULL: goto x86_l_25a8;
	case 9642ULL: goto x86_l_25aa;
	case 9647ULL: goto x86_l_25af;
	case 9654ULL: goto x86_l_25b6;
	case 9664ULL: goto x86_l_25c0;
	case 9669ULL: goto x86_l_25c5;
	case 9674ULL: goto x86_l_25ca;
	case 9681ULL: goto x86_l_25d1;
	case 9686ULL: goto x86_l_25d6;
	case 9688ULL: goto x86_l_25d8;
	case 9691ULL: goto x86_l_25db;
	case 9697ULL: goto x86_l_25e1;
	case 9705ULL: goto x86_l_25e9;
	case 9710ULL: goto x86_l_25ee;
	case 9715ULL: goto x86_l_25f3;
	case 9720ULL: goto x86_l_25f8;
	case 9725ULL: goto x86_l_25fd;
	case 9730ULL: goto x86_l_2602;
	case 9732ULL: goto x86_l_2604;
	case 9735ULL: goto x86_l_2607;
	case 9741ULL: goto x86_l_260d;
	case 9743ULL: goto x86_l_260f;
	case 9748ULL: goto x86_l_2614;
	case 9755ULL: goto x86_l_261b;
	case 9765ULL: goto x86_l_2625;
	case 9770ULL: goto x86_l_262a;
	case 9775ULL: goto x86_l_262f;
	case 9782ULL: goto x86_l_2636;
	case 9787ULL: goto x86_l_263b;
	case 9789ULL: goto x86_l_263d;
	case 9792ULL: goto x86_l_2640;
	case 9798ULL: goto x86_l_2646;
	case 9800ULL: goto x86_l_2648;
	case 9805ULL: goto x86_l_264d;
	case 9810ULL: goto x86_l_2652;
	case 9818ULL: goto x86_l_265a;
	case 9823ULL: goto x86_l_265f;
	case 9830ULL: goto x86_l_2666;
	case 9835ULL: goto x86_l_266b;
	case 9840ULL: goto x86_l_2670;
	case 9842ULL: goto x86_l_2672;
	case 9844ULL: goto x86_l_2674;
	case 9849ULL: goto x86_l_2679;
	case 9853ULL: goto x86_l_267d;
	case 9859ULL: goto x86_l_2683;
	case 9864ULL: goto x86_l_2688;
	case 9866ULL: goto x86_l_268a;
	case 9870ULL: goto x86_l_268e;
	case 9875ULL: goto x86_l_2693;
	case 9880ULL: goto x86_l_2698;
	case 9885ULL: goto x86_l_269d;
	case 9887ULL: goto x86_l_269f;
	case 9891ULL: goto x86_l_26a3;
	case 9894ULL: goto x86_l_26a6;
	case 9897ULL: goto x86_l_26a9;
	case 9900ULL: goto x86_l_26ac;
	case 9905ULL: goto x86_l_26b1;
	case 9909ULL: goto x86_l_26b5;
	case 9915ULL: goto x86_l_26bb;
	case 9920ULL: goto x86_l_26c0;
	case 9925ULL: goto x86_l_26c5;
	case 9930ULL: goto x86_l_26ca;
	case 9932ULL: goto x86_l_26cc;
	case 9935ULL: goto x86_l_26cf;
	case 9941ULL: goto x86_l_26d5;
	case 9943ULL: goto x86_l_26d7;
	case 9948ULL: goto x86_l_26dc;
	case 9955ULL: goto x86_l_26e3;
	case 9965ULL: goto x86_l_26ed;
	case 9970ULL: goto x86_l_26f2;
	case 9975ULL: goto x86_l_26f7;
	case 9982ULL: goto x86_l_26fe;
	case 9987ULL: goto x86_l_2703;
	case 9989ULL: goto x86_l_2705;
	case 9992ULL: goto x86_l_2708;
	case 9998ULL: goto x86_l_270e;
	case 10006ULL: goto x86_l_2716;
	case 10011ULL: goto x86_l_271b;
	case 10016ULL: goto x86_l_2720;
	case 10019ULL: goto x86_l_2723;
	case 10024ULL: goto x86_l_2728;
	case 10029ULL: goto x86_l_272d;
	case 10034ULL: goto x86_l_2732;
	case 10039ULL: goto x86_l_2737;
	case 10041ULL: goto x86_l_2739;
	case 10044ULL: goto x86_l_273c;
	case 10050ULL: goto x86_l_2742;
	case 10052ULL: goto x86_l_2744;
	case 10057ULL: goto x86_l_2749;
	case 10064ULL: goto x86_l_2750;
	case 10074ULL: goto x86_l_275a;
	case 10079ULL: goto x86_l_275f;
	case 10084ULL: goto x86_l_2764;
	case 10091ULL: goto x86_l_276b;
	case 10096ULL: goto x86_l_2770;
	case 10098ULL: goto x86_l_2772;
	case 10101ULL: goto x86_l_2775;
	case 10107ULL: goto x86_l_277b;
	case 10115ULL: goto x86_l_2783;
	case 10120ULL: goto x86_l_2788;
	case 10125ULL: goto x86_l_278d;
	case 10130ULL: goto x86_l_2792;
	case 10135ULL: goto x86_l_2797;
	case 10140ULL: goto x86_l_279c;
	case 10142ULL: goto x86_l_279e;
	case 10145ULL: goto x86_l_27a1;
	case 10151ULL: goto x86_l_27a7;
	case 10153ULL: goto x86_l_27a9;
	case 10158ULL: goto x86_l_27ae;
	case 10165ULL: goto x86_l_27b5;
	case 10175ULL: goto x86_l_27bf;
	case 10180ULL: goto x86_l_27c4;
	case 10185ULL: goto x86_l_27c9;
	case 10192ULL: goto x86_l_27d0;
	case 10197ULL: goto x86_l_27d5;
	case 10199ULL: goto x86_l_27d7;
	case 10202ULL: goto x86_l_27da;
	case 10208ULL: goto x86_l_27e0;
	case 10210ULL: goto x86_l_27e2;
	case 10216ULL: goto x86_l_27e8;
	case 10221ULL: goto x86_l_27ed;
	case 10226ULL: goto x86_l_27f2;
	case 10231ULL: goto x86_l_27f7;
	case 10236ULL: goto x86_l_27fc;
	case 10238ULL: goto x86_l_27fe;
	case 10241ULL: goto x86_l_2801;
	case 10247ULL: goto x86_l_2807;
	case 10249ULL: goto x86_l_2809;
	case 10254ULL: goto x86_l_280e;
	case 10261ULL: goto x86_l_2815;
	case 10271ULL: goto x86_l_281f;
	case 10276ULL: goto x86_l_2824;
	case 10281ULL: goto x86_l_2829;
	case 10288ULL: goto x86_l_2830;
	case 10293ULL: goto x86_l_2835;
	case 10295ULL: goto x86_l_2837;
	case 10298ULL: goto x86_l_283a;
	case 10300ULL: goto x86_l_283c;
	case 10308ULL: goto x86_l_2844;
	case 10313ULL: goto x86_l_2849;
	case 10318ULL: goto x86_l_284e;
	case 10323ULL: goto x86_l_2853;
	case 10328ULL: goto x86_l_2858;
	case 10333ULL: goto x86_l_285d;
	case 10335ULL: goto x86_l_285f;
	case 10338ULL: goto x86_l_2862;
	case 10344ULL: goto x86_l_2868;
	case 10346ULL: goto x86_l_286a;
	case 10351ULL: goto x86_l_286f;
	case 10358ULL: goto x86_l_2876;
	case 10368ULL: goto x86_l_2880;
	case 10373ULL: goto x86_l_2885;
	case 10378ULL: goto x86_l_288a;
	case 10385ULL: goto x86_l_2891;
	case 10390ULL: goto x86_l_2896;
	case 10392ULL: goto x86_l_2898;
	case 10395ULL: goto x86_l_289b;
	case 10401ULL: goto x86_l_28a1;
	case 10403ULL: goto x86_l_28a3;
	case 10408ULL: goto x86_l_28a8;
	case 10413ULL: goto x86_l_28ad;
	case 10418ULL: goto x86_l_28b2;
	case 10423ULL: goto x86_l_28b7;
	case 10425ULL: goto x86_l_28b9;
	case 10428ULL: goto x86_l_28bc;
	case 10434ULL: goto x86_l_28c2;
	case 10436ULL: goto x86_l_28c4;
	case 10441ULL: goto x86_l_28c9;
	case 10448ULL: goto x86_l_28d0;
	case 10458ULL: goto x86_l_28da;
	case 10463ULL: goto x86_l_28df;
	case 10468ULL: goto x86_l_28e4;
	case 10475ULL: goto x86_l_28eb;
	case 10480ULL: goto x86_l_28f0;
	case 10482ULL: goto x86_l_28f2;
	case 10485ULL: goto x86_l_28f5;
	case 10491ULL: goto x86_l_28fb;
	case 10493ULL: goto x86_l_28fd;
	case 10499ULL: goto x86_l_2903;
	case 10504ULL: goto x86_l_2908;
	case 10509ULL: goto x86_l_290d;
	case 10514ULL: goto x86_l_2912;
	case 10519ULL: goto x86_l_2917;
	case 10521ULL: goto x86_l_2919;
	case 10524ULL: goto x86_l_291c;
	case 10530ULL: goto x86_l_2922;
	case 10532ULL: goto x86_l_2924;
	case 10537ULL: goto x86_l_2929;
	case 10544ULL: goto x86_l_2930;
	case 10554ULL: goto x86_l_293a;
	case 10559ULL: goto x86_l_293f;
	case 10564ULL: goto x86_l_2944;
	case 10571ULL: goto x86_l_294b;
	case 10576ULL: goto x86_l_2950;
	case 10578ULL: goto x86_l_2952;
	case 10581ULL: goto x86_l_2955;
	case 10587ULL: goto x86_l_295b;
	case 10589ULL: goto x86_l_295d;
	case 10594ULL: goto x86_l_2962;
	case 10599ULL: goto x86_l_2967;
	case 10607ULL: goto x86_l_296f;
	case 10612ULL: goto x86_l_2974;
	case 10619ULL: goto x86_l_297b;
	case 10624ULL: goto x86_l_2980;
	case 10629ULL: goto x86_l_2985;
	case 10631ULL: goto x86_l_2987;
	case 10633ULL: goto x86_l_2989;
	case 10638ULL: goto x86_l_298e;
	case 10643ULL: goto x86_l_2993;
	case 10651ULL: goto x86_l_299b;
	case 10656ULL: goto x86_l_29a0;
	case 10663ULL: goto x86_l_29a7;
	case 10668ULL: goto x86_l_29ac;
	case 10673ULL: goto x86_l_29b1;
	case 10675ULL: goto x86_l_29b3;
	case 10677ULL: goto x86_l_29b5;
	case 10683ULL: goto x86_l_29bb;
	case 10688ULL: goto x86_l_29c0;
	case 10696ULL: goto x86_l_29c8;
	case 10701ULL: goto x86_l_29cd;
	case 10708ULL: goto x86_l_29d4;
	case 10713ULL: goto x86_l_29d9;
	case 10718ULL: goto x86_l_29de;
	case 10720ULL: goto x86_l_29e0;
	case 10722ULL: goto x86_l_29e2;
	case 10728ULL: goto x86_l_29e8;
	case 10733ULL: goto x86_l_29ed;
	case 10741ULL: goto x86_l_29f5;
	case 10746ULL: goto x86_l_29fa;
	case 10753ULL: goto x86_l_2a01;
	case 10758ULL: goto x86_l_2a06;
	case 10763ULL: goto x86_l_2a0b;
	case 10765ULL: goto x86_l_2a0d;
	case 10767ULL: goto x86_l_2a0f;
	case 10773ULL: goto x86_l_2a15;
	case 10775ULL: goto x86_l_2a17;
	case 10783ULL: goto x86_l_2a1f;
	case 10788ULL: goto x86_l_2a24;
	case 10795ULL: goto x86_l_2a2b;
	case 10800ULL: goto x86_l_2a30;
	case 10805ULL: goto x86_l_2a35;
	case 10807ULL: goto x86_l_2a37;
	case 10809ULL: goto x86_l_2a39;
	case 10814ULL: goto x86_l_2a3e;
	case 10816ULL: goto x86_l_2a40;
	case 10824ULL: goto x86_l_2a48;
	case 10829ULL: goto x86_l_2a4d;
	case 10836ULL: goto x86_l_2a54;
	case 10841ULL: goto x86_l_2a59;
	case 10846ULL: goto x86_l_2a5e;
	case 10848ULL: goto x86_l_2a60;
	case 10850ULL: goto x86_l_2a62;
	case 10856ULL: goto x86_l_2a68;
	case 10858ULL: goto x86_l_2a6a;
	case 10866ULL: goto x86_l_2a72;
	case 10871ULL: goto x86_l_2a77;
	case 10878ULL: goto x86_l_2a7e;
	case 10883ULL: goto x86_l_2a83;
	case 10888ULL: goto x86_l_2a88;
	case 10890ULL: goto x86_l_2a8a;
	case 10892ULL: goto x86_l_2a8c;
	case 10897ULL: goto x86_l_2a91;
	case 10904ULL: goto x86_l_2a98;
	case 10908ULL: goto x86_l_2a9c;
	case 10915ULL: goto x86_l_2aa3;
	case 10923ULL: goto x86_l_2aab;
	case 10928ULL: goto x86_l_2ab0;
	case 10930ULL: goto x86_l_2ab2;
	case 10934ULL: goto x86_l_2ab6;
	case 10942ULL: goto x86_l_2abe;
	case 10950ULL: goto x86_l_2ac6;
	case 10955ULL: goto x86_l_2acb;
	case 10957ULL: goto x86_l_2acd;
	case 10961ULL: goto x86_l_2ad1;
	case 10965ULL: goto x86_l_2ad5;
	case 10976ULL: goto x86_l_2ae0;
	case 10987ULL: goto x86_l_2aeb;
	case 10998ULL: goto x86_l_2af6;
	case 11009ULL: goto x86_l_2b01;
	case 11020ULL: goto x86_l_2b0c;
	case 11031ULL: goto x86_l_2b17;
	case 11039ULL: goto x86_l_2b1f;
	case 11044ULL: goto x86_l_2b24;
	case 11046ULL: goto x86_l_2b26;
	case 11049ULL: goto x86_l_2b29;
	case 11053ULL: goto x86_l_2b2d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_23d8:
	/* 0x23d8: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23dd:
	/* 0x23dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23df:
	/* 0x23df: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23e2:
	/* 0x23e2: jne    28a1 <generic_tracepoint_event+0x28a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28a1;
	}
x86_l_23e8:
	/* 0x23e8: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_23f0:
	/* 0x23f0: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_23f5:
	/* 0x23f5: jmp    2a24 <generic_tracepoint_event+0x2a24> */
	goto x86_l_2a24;
x86_l_23fa:
	/* 0x23fa: cmp    r12d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 17ULL);
x86_l_23fe:
	/* 0x23fe: jle    257e <generic_tracepoint_event+0x257e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_257e;
	}
x86_l_2404:
	/* 0x2404: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_2408:
	/* 0x2408: je     2720 <generic_tracepoint_event+0x2720> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2720;
	}
x86_l_240e:
	/* 0x240e: cmp    r12d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 28ULL);
x86_l_2412:
	/* 0x2412: je     248c <generic_tracepoint_event+0x248c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_248c;
	}
x86_l_2414:
	/* 0x2414: cmp    r12d,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 29ULL);
x86_l_2418:
	/* 0x2418: jne    2a91 <generic_tracepoint_event+0x2a91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a91;
	}
x86_l_241e:
	/* 0x241e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2423:
	/* 0x2423: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2428:
	/* 0x2428: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_242d:
	/* 0x242d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_242f:
	/* 0x242f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2432:
	/* 0x2432: je     29b5 <generic_tracepoint_event+0x29b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29b5;
	}
x86_l_2438:
	/* 0x2438: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_243a:
	/* 0x243a: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_243f:
	/* 0x243f: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2446:
	/* 0x2446: movabs rax,0x40000006c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869292ULL);
x86_l_2450:
	/* 0x2450: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2455:
	/* 0x2455: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_245a:
	/* 0x245a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2461:
	/* 0x2461: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2466:
	/* 0x2466: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2468:
	/* 0x2468: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_246b:
	/* 0x246b: je     2993 <generic_tracepoint_event+0x2993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2993;
	}
x86_l_2471:
	/* 0x2471: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2473:
	/* 0x2473: movsx  r15,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2479:
	/* 0x2479: jmp    2a91 <generic_tracepoint_event+0x2a91> */
	goto x86_l_2a91;
x86_l_247e:
	/* 0x247e: lea    eax,[r12-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_2483:
	/* 0x2483: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2486:
	/* 0x2486: jae    26b1 <generic_tracepoint_event+0x26b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_26b1;
	}
x86_l_248c:
	/* 0x248c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2491:
	/* 0x2491: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2496:
	/* 0x2496: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_249b:
	/* 0x249b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_249d:
	/* 0x249d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24a0:
	/* 0x24a0: je     2674 <generic_tracepoint_event+0x2674> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2674;
	}
x86_l_24a6:
	/* 0x24a6: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_24a8:
	/* 0x24a8: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24ad:
	/* 0x24ad: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_24b4:
	/* 0x24b4: movabs rax,0x400000045 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869253ULL);
x86_l_24be:
	/* 0x24be: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_24c3:
	/* 0x24c3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24c8:
	/* 0x24c8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_24cf:
	/* 0x24cf: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24d4:
	/* 0x24d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24d6:
	/* 0x24d6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24d9:
	/* 0x24d9: je     2652 <generic_tracepoint_event+0x2652> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2652;
	}
x86_l_24df:
	/* 0x24df: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_24e1:
	/* 0x24e1: jmp    2674 <generic_tracepoint_event+0x2674> */
	goto x86_l_2674;
x86_l_24e6:
	/* 0x24e6: cmp    r12d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 38ULL);
x86_l_24ea:
	/* 0x24ea: je     2908 <generic_tracepoint_event+0x2908> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2908;
	}
x86_l_24f0:
	/* 0x24f0: cmp    r12d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 40ULL);
x86_l_24f4:
	/* 0x24f4: je     27ed <generic_tracepoint_event+0x27ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27ed;
	}
x86_l_24fa:
	/* 0x24fa: cmp    r12d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 41ULL);
x86_l_24fe:
	/* 0x24fe: jne    2a91 <generic_tracepoint_event+0x2a91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a91;
	}
x86_l_2504:
	/* 0x2504: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2509:
	/* 0x2509: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_250e:
	/* 0x250e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2513:
	/* 0x2513: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2515:
	/* 0x2515: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2518:
	/* 0x2518: je     2a39 <generic_tracepoint_event+0x2a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a39;
	}
x86_l_251e:
	/* 0x251e: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2520:
	/* 0x2520: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2525:
	/* 0x2525: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_252c:
	/* 0x252c: movabs rax,0x4000000a8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869352ULL);
x86_l_2536:
	/* 0x2536: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_253b:
	/* 0x253b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2540:
	/* 0x2540: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2547:
	/* 0x2547: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_254c:
	/* 0x254c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_254e:
	/* 0x254e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2551:
	/* 0x2551: jne    28a1 <generic_tracepoint_event+0x28a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28a1;
	}
x86_l_2557:
	/* 0x2557: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_255f:
	/* 0x255f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2564:
	/* 0x2564: jmp    2a24 <generic_tracepoint_event+0x2a24> */
	goto x86_l_2a24;
x86_l_2569:
	/* 0x2569: cmp    r12d,0xfffffff3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967283ULL);
x86_l_256d:
	/* 0x256d: je     25f3 <generic_tracepoint_event+0x25f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25f3;
	}
x86_l_2573:
	/* 0x2573: cmp    r12d,0xfffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967284ULL);
x86_l_2577:
	/* 0x2577: je     258e <generic_tracepoint_event+0x258e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_258e;
	}
x86_l_2579:
	/* 0x2579: jmp    2a91 <generic_tracepoint_event+0x2a91> */
	goto x86_l_2a91;
x86_l_257e:
	/* 0x257e: cmp    r12d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 12ULL);
x86_l_2582:
	/* 0x2582: je     25f3 <generic_tracepoint_event+0x25f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25f3;
	}
x86_l_2584:
	/* 0x2584: cmp    r12d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 13ULL);
x86_l_2588:
	/* 0x2588: jne    2a91 <generic_tracepoint_event+0x2a91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a91;
	}
x86_l_258e:
	/* 0x258e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2593:
	/* 0x2593: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2598:
	/* 0x2598: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_259d:
	/* 0x259d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_259f:
	/* 0x259f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25a2:
	/* 0x25a2: je     2a8c <generic_tracepoint_event+0x2a8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a8c;
	}
x86_l_25a8:
	/* 0x25a8: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_25aa:
	/* 0x25aa: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25af:
	/* 0x25af: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_25b6:
	/* 0x25b6: movabs rax,0x40000005e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869278ULL);
x86_l_25c0:
	/* 0x25c0: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_25c5:
	/* 0x25c5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_25ca:
	/* 0x25ca: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_25d1:
	/* 0x25d1: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25d6:
	/* 0x25d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25d8:
	/* 0x25d8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25db:
	/* 0x25db: jne    295b <generic_tracepoint_event+0x295b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_295b;
	}
x86_l_25e1:
	/* 0x25e1: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_25e9:
	/* 0x25e9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_25ee:
	/* 0x25ee: jmp    2a77 <generic_tracepoint_event+0x2a77> */
	goto x86_l_2a77;
x86_l_25f3:
	/* 0x25f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25f8:
	/* 0x25f8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25fd:
	/* 0x25fd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2602:
	/* 0x2602: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2604:
	/* 0x2604: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2607:
	/* 0x2607: je     2989 <generic_tracepoint_event+0x2989> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2989;
	}
x86_l_260d:
	/* 0x260d: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_260f:
	/* 0x260f: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2614:
	/* 0x2614: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_261b:
	/* 0x261b: movabs rax,0x400000056 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869270ULL);
x86_l_2625:
	/* 0x2625: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_262a:
	/* 0x262a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_262f:
	/* 0x262f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2636:
	/* 0x2636: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_263b:
	/* 0x263b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_263d:
	/* 0x263d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2640:
	/* 0x2640: je     2967 <generic_tracepoint_event+0x2967> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2967;
	}
x86_l_2646:
	/* 0x2646: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2648:
	/* 0x2648: movsxd r15,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_264d:
	/* 0x264d: jmp    2a91 <generic_tracepoint_event+0x2a91> */
	goto x86_l_2a91;
x86_l_2652:
	/* 0x2652: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_265a:
	/* 0x265a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_265f:
	/* 0x265f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2666:
	/* 0x2666: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_266b:
	/* 0x266b: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2670:
	/* 0x2670: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2672:
	/* 0x2672: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2674:
	/* 0x2674: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2679:
	/* 0x2679: cmp    r12d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 28ULL);
x86_l_267d:
	/* 0x267d: jne    2a91 <generic_tracepoint_event+0x2a91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a91;
	}
x86_l_2683:
	/* 0x2683: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_2688:
	/* 0x2688: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_268a:
	/* 0x268a: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_268e:
	/* 0x268e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2693:
	/* 0x2693: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2698:
	/* 0x2698: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_269d:
	/* 0x269d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_269f:
	/* 0x269f: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26a3:
	/* 0x26a3: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_26a6:
	/* 0x26a6: shl    eax,0x1e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 30ULL);
x86_l_26a9:
	/* 0x26a9: or     r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_26ac:
	/* 0x26ac: jmp    2a91 <generic_tracepoint_event+0x2a91> */
	goto x86_l_2a91;
x86_l_26b1:
	/* 0x26b1: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_26b5:
	/* 0x26b5: jne    2a91 <generic_tracepoint_event+0x2a91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a91;
	}
x86_l_26bb:
	/* 0x26bb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26c0:
	/* 0x26c0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26c5:
	/* 0x26c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26ca:
	/* 0x26ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26cc:
	/* 0x26cc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26cf:
	/* 0x26cf: je     2a39 <generic_tracepoint_event+0x2a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a39;
	}
x86_l_26d5:
	/* 0x26d5: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_26d7:
	/* 0x26d7: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26dc:
	/* 0x26dc: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_26e3:
	/* 0x26e3: movabs rax,0x40000009a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869338ULL);
x86_l_26ed:
	/* 0x26ed: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_26f2:
	/* 0x26f2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26f7:
	/* 0x26f7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_26fe:
	/* 0x26fe: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2703:
	/* 0x2703: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2705:
	/* 0x2705: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2708:
	/* 0x2708: jne    28a1 <generic_tracepoint_event+0x28a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28a1;
	}
x86_l_270e:
	/* 0x270e: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2716:
	/* 0x2716: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_271b:
	/* 0x271b: jmp    2a24 <generic_tracepoint_event+0x2a24> */
	goto x86_l_2a24;
x86_l_2720:
	/* 0x2720: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_2723:
	/* 0x2723: jmp    2a91 <generic_tracepoint_event+0x2a91> */
	goto x86_l_2a91;
x86_l_2728:
	/* 0x2728: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_272d:
	/* 0x272d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2732:
	/* 0x2732: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2737:
	/* 0x2737: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2739:
	/* 0x2739: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_273c:
	/* 0x273c: je     2a39 <generic_tracepoint_event+0x2a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a39;
	}
x86_l_2742:
	/* 0x2742: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2744:
	/* 0x2744: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2749:
	/* 0x2749: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2750:
	/* 0x2750: movabs rax,0x400000093 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869331ULL);
x86_l_275a:
	/* 0x275a: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_275f:
	/* 0x275f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2764:
	/* 0x2764: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_276b:
	/* 0x276b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2770:
	/* 0x2770: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2772:
	/* 0x2772: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2775:
	/* 0x2775: jne    28a1 <generic_tracepoint_event+0x28a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28a1;
	}
x86_l_277b:
	/* 0x277b: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2783:
	/* 0x2783: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2788:
	/* 0x2788: jmp    2a24 <generic_tracepoint_event+0x2a24> */
	goto x86_l_2a24;
x86_l_278d:
	/* 0x278d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2792:
	/* 0x2792: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2797:
	/* 0x2797: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_279c:
	/* 0x279c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_279e:
	/* 0x279e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27a1:
	/* 0x27a1: je     29e2 <generic_tracepoint_event+0x29e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29e2;
	}
x86_l_27a7:
	/* 0x27a7: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_27a9:
	/* 0x27a9: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27ae:
	/* 0x27ae: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_27b5:
	/* 0x27b5: movabs rax,0x40000007a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869306ULL);
x86_l_27bf:
	/* 0x27bf: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_27c4:
	/* 0x27c4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27c9:
	/* 0x27c9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_27d0:
	/* 0x27d0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27d5:
	/* 0x27d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27d7:
	/* 0x27d7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27da:
	/* 0x27da: je     29c0 <generic_tracepoint_event+0x29c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29c0;
	}
x86_l_27e0:
	/* 0x27e0: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_27e2:
	/* 0x27e2: movsx  r15,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_27e8:
	/* 0x27e8: jmp    2a91 <generic_tracepoint_event+0x2a91> */
	goto x86_l_2a91;
x86_l_27ed:
	/* 0x27ed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27f2:
	/* 0x27f2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27f7:
	/* 0x27f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27fc:
	/* 0x27fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27fe:
	/* 0x27fe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2801:
	/* 0x2801: je     2a39 <generic_tracepoint_event+0x2a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a39;
	}
x86_l_2807:
	/* 0x2807: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2809:
	/* 0x2809: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_280e:
	/* 0x280e: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2815:
	/* 0x2815: movabs rax,0x4000000a1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869345ULL);
x86_l_281f:
	/* 0x281f: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2824:
	/* 0x2824: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2829:
	/* 0x2829: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2830:
	/* 0x2830: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2835:
	/* 0x2835: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2837:
	/* 0x2837: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_283a:
	/* 0x283a: jne    28a1 <generic_tracepoint_event+0x28a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28a1;
	}
x86_l_283c:
	/* 0x283c: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2844:
	/* 0x2844: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2849:
	/* 0x2849: jmp    2a24 <generic_tracepoint_event+0x2a24> */
	goto x86_l_2a24;
x86_l_284e:
	/* 0x284e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2853:
	/* 0x2853: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2858:
	/* 0x2858: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_285d:
	/* 0x285d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_285f:
	/* 0x285f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2862:
	/* 0x2862: je     2a39 <generic_tracepoint_event+0x2a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a39;
	}
x86_l_2868:
	/* 0x2868: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_286a:
	/* 0x286a: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_286f:
	/* 0x286f: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2876:
	/* 0x2876: movabs rax,0x40000004e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869262ULL);
x86_l_2880:
	/* 0x2880: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2885:
	/* 0x2885: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_288a:
	/* 0x288a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2891:
	/* 0x2891: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2896:
	/* 0x2896: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2898:
	/* 0x2898: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_289b:
	/* 0x289b: je     2a17 <generic_tracepoint_event+0x2a17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a17;
	}
x86_l_28a1:
	/* 0x28a1: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_28a3:
	/* 0x28a3: jmp    2a39 <generic_tracepoint_event+0x2a39> */
	goto x86_l_2a39;
x86_l_28a8:
	/* 0x28a8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28ad:
	/* 0x28ad: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28b2:
	/* 0x28b2: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_28b7:
	/* 0x28b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28b9:
	/* 0x28b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28bc:
	/* 0x28bc: je     2a62 <generic_tracepoint_event+0x2a62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a62;
	}
x86_l_28c2:
	/* 0x28c2: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_28c4:
	/* 0x28c4: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28c9:
	/* 0x28c9: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_28d0:
	/* 0x28d0: movabs rax,0x400000065 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869285ULL);
x86_l_28da:
	/* 0x28da: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_28df:
	/* 0x28df: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28e4:
	/* 0x28e4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_28eb:
	/* 0x28eb: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28f0:
	/* 0x28f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28f2:
	/* 0x28f2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28f5:
	/* 0x28f5: je     2a40 <generic_tracepoint_event+0x2a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a40;
	}
x86_l_28fb:
	/* 0x28fb: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_28fd:
	/* 0x28fd: movzx  r15d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2903:
	/* 0x2903: jmp    2a91 <generic_tracepoint_event+0x2a91> */
	goto x86_l_2a91;
x86_l_2908:
	/* 0x2908: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_290d:
	/* 0x290d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2912:
	/* 0x2912: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2917:
	/* 0x2917: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2919:
	/* 0x2919: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_291c:
	/* 0x291c: je     2a8c <generic_tracepoint_event+0x2a8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a8c;
	}
x86_l_2922:
	/* 0x2922: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2924:
	/* 0x2924: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2929:
	/* 0x2929: mov    WORD PTR [rsp+0x22],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888071ULL);
x86_l_2930:
	/* 0x2930: movabs rax,0x400000088 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869320ULL);
x86_l_293a:
	/* 0x293a: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_293f:
	/* 0x293f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2944:
	/* 0x2944: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_294b:
	/* 0x294b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2950:
	/* 0x2950: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2952:
	/* 0x2952: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2955:
	/* 0x2955: je     2a6a <generic_tracepoint_event+0x2a6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a6a;
	}
x86_l_295b:
	/* 0x295b: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_295d:
	/* 0x295d: mov    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2962:
	/* 0x2962: jmp    2a91 <generic_tracepoint_event+0x2a91> */
	goto x86_l_2a91;
x86_l_2967:
	/* 0x2967: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_296f:
	/* 0x296f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2974:
	/* 0x2974: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_297b:
	/* 0x297b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2980:
	/* 0x2980: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2985:
	/* 0x2985: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2987:
	/* 0x2987: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2989:
	/* 0x2989: movsxd r15,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_298e:
	/* 0x298e: jmp    2a91 <generic_tracepoint_event+0x2a91> */
	goto x86_l_2a91;
x86_l_2993:
	/* 0x2993: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_299b:
	/* 0x299b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_29a0:
	/* 0x29a0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_29a7:
	/* 0x29a7: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29ac:
	/* 0x29ac: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29b1:
	/* 0x29b1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29b3:
	/* 0x29b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29b5:
	/* 0x29b5: movsx  r15,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_29bb:
	/* 0x29bb: jmp    2a91 <generic_tracepoint_event+0x2a91> */
	goto x86_l_2a91;
x86_l_29c0:
	/* 0x29c0: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_29c8:
	/* 0x29c8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_29cd:
	/* 0x29cd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_29d4:
	/* 0x29d4: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29d9:
	/* 0x29d9: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29de:
	/* 0x29de: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29e0:
	/* 0x29e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29e2:
	/* 0x29e2: movsx  r15,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_29e8:
	/* 0x29e8: jmp    2a91 <generic_tracepoint_event+0x2a91> */
	goto x86_l_2a91;
x86_l_29ed:
	/* 0x29ed: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_29f5:
	/* 0x29f5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_29fa:
	/* 0x29fa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2a01:
	/* 0x2a01: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a06:
	/* 0x2a06: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a0b:
	/* 0x2a0b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a0d:
	/* 0x2a0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a0f:
	/* 0x2a0f: movzx  r15d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_2a15:
	/* 0x2a15: jmp    2a91 <generic_tracepoint_event+0x2a91> */
	goto x86_l_2a91;
x86_l_2a17:
	/* 0x2a17: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2a1f:
	/* 0x2a1f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a24:
	/* 0x2a24: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2a2b:
	/* 0x2a2b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a30:
	/* 0x2a30: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a35:
	/* 0x2a35: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a37:
	/* 0x2a37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a39:
	/* 0x2a39: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a3e:
	/* 0x2a3e: jmp    2a91 <generic_tracepoint_event+0x2a91> */
	goto x86_l_2a91;
x86_l_2a40:
	/* 0x2a40: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_2a48:
	/* 0x2a48: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a4d:
	/* 0x2a4d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2a54:
	/* 0x2a54: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a59:
	/* 0x2a59: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a5e:
	/* 0x2a5e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a60:
	/* 0x2a60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a62:
	/* 0x2a62: movzx  r15d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2a68:
	/* 0x2a68: jmp    2a91 <generic_tracepoint_event+0x2a91> */
	goto x86_l_2a91;
x86_l_2a6a:
	/* 0x2a6a: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_2a72:
	/* 0x2a72: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a77:
	/* 0x2a77: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2a7e:
	/* 0x2a7e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a83:
	/* 0x2a83: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a88:
	/* 0x2a88: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a8a:
	/* 0x2a8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a8c:
	/* 0x2a8c: mov    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a91:
	/* 0x2a91: mov    QWORD PTR [r14+0x5e70],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24176ULL);
x86_l_2a98:
	/* 0x2a98: mov    BYTE PTR [r14],0xe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_2a9c:
	/* 0x2a9c: mov    WORD PTR [r14+0x2],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934592ULL);
x86_l_2aa3:
	/* 0x2aa3: mov    DWORD PTR [r14+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_2aab:
	/* 0x2aab: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_2ab0:
	/* 0x2ab0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ab2:
	/* 0x2ab2: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ab6:
	/* 0x2ab6: mov    QWORD PTR [r14+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_2abe:
	/* 0x2abe: mov    DWORD PTR [r14+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2ac6:
	/* 0x2ac6: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2acb:
	/* 0x2acb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2acd:
	/* 0x2acd: mov    DWORD PTR [r14+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2ad1:
	/* 0x2ad1: mov    BYTE PTR [r14],0xe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_2ad5:
	/* 0x2ad5: mov    QWORD PTR [r14+0x5efc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104436424769536ULL);
x86_l_2ae0:
	/* 0x2ae0: mov    QWORD PTR [r14+0x5eb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104144366993408ULL);
x86_l_2aeb:
	/* 0x2aeb: mov    QWORD PTR [r14+0x5ec0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731776ULL);
x86_l_2af6:
	/* 0x2af6: mov    QWORD PTR [r14+0x5ec8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104213086470144ULL);
x86_l_2b01:
	/* 0x2b01: mov    QWORD PTR [r14+0x5ed0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104247446208512ULL);
x86_l_2b0c:
	/* 0x2b0c: mov    QWORD PTR [r14+0x5ed8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104281805946880ULL);
x86_l_2b17:
	/* 0x2b17: mov    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_2b1f:
	/* 0x2b1f: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_2b24:
	/* 0x2b24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b26:
	/* 0x2b26: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2b29:
	/* 0x2b29: lea    r12,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b2d:
	/* 0x2b2d: lea    rdx,[rax+0xd48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3400ULL);
	return 11060ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11060ULL: goto x86_l_2b34;
	case 11065ULL: goto x86_l_2b39;
	case 11070ULL: goto x86_l_2b3e;
	case 11075ULL: goto x86_l_2b43;
	case 11077ULL: goto x86_l_2b45;
	case 11082ULL: goto x86_l_2b4a;
	case 11087ULL: goto x86_l_2b4f;
	case 11092ULL: goto x86_l_2b54;
	case 11097ULL: goto x86_l_2b59;
	case 11099ULL: goto x86_l_2b5b;
	case 11104ULL: goto x86_l_2b60;
	case 11109ULL: goto x86_l_2b65;
	case 11114ULL: goto x86_l_2b6a;
	case 11117ULL: goto x86_l_2b6d;
	case 11122ULL: goto x86_l_2b72;
	case 11124ULL: goto x86_l_2b74;
	case 11128ULL: goto x86_l_2b78;
	case 11133ULL: goto x86_l_2b7d;
	case 11138ULL: goto x86_l_2b82;
	case 11143ULL: goto x86_l_2b87;
	case 11148ULL: goto x86_l_2b8c;
	case 11150ULL: goto x86_l_2b8e;
	case 11154ULL: goto x86_l_2b92;
	case 11159ULL: goto x86_l_2b97;
	case 11164ULL: goto x86_l_2b9c;
	case 11168ULL: goto x86_l_2ba0;
	case 11173ULL: goto x86_l_2ba5;
	case 11175ULL: goto x86_l_2ba7;
	case 11184ULL: goto x86_l_2bb0;
	case 11191ULL: goto x86_l_2bb7;
	case 11196ULL: goto x86_l_2bbc;
	case 11201ULL: goto x86_l_2bc1;
	case 11206ULL: goto x86_l_2bc6;
	case 11208ULL: goto x86_l_2bc8;
	case 11214ULL: goto x86_l_2bce;
	case 11216ULL: goto x86_l_2bd0;
	case 11224ULL: goto x86_l_2bd8;
	case 11229ULL: goto x86_l_2bdd;
	case 11234ULL: goto x86_l_2be2;
	case 11238ULL: goto x86_l_2be6;
	case 11243ULL: goto x86_l_2beb;
	case 11248ULL: goto x86_l_2bf0;
	case 11250ULL: goto x86_l_2bf2;
	case 11255ULL: goto x86_l_2bf7;
	case 11260ULL: goto x86_l_2bfc;
	case 11265ULL: goto x86_l_2c01;
	case 11269ULL: goto x86_l_2c05;
	case 11272ULL: goto x86_l_2c08;
	case 11279ULL: goto x86_l_2c0f;
	case 11284ULL: goto x86_l_2c14;
	case 11289ULL: goto x86_l_2c19;
	case 11291ULL: goto x86_l_2c1b;
	case 11295ULL: goto x86_l_2c1f;
	case 11300ULL: goto x86_l_2c24;
	case 11305ULL: goto x86_l_2c29;
	case 11309ULL: goto x86_l_2c2d;
	case 11314ULL: goto x86_l_2c32;
	case 11316ULL: goto x86_l_2c34;
	case 11318ULL: goto x86_l_2c36;
	case 11326ULL: goto x86_l_2c3e;
	case 11330ULL: goto x86_l_2c42;
	case 11335ULL: goto x86_l_2c47;
	case 11340ULL: goto x86_l_2c4c;
	case 11344ULL: goto x86_l_2c50;
	case 11349ULL: goto x86_l_2c55;
	case 11351ULL: goto x86_l_2c57;
	case 11355ULL: goto x86_l_2c5b;
	case 11360ULL: goto x86_l_2c60;
	case 11365ULL: goto x86_l_2c65;
	case 11370ULL: goto x86_l_2c6a;
	case 11375ULL: goto x86_l_2c6f;
	case 11377ULL: goto x86_l_2c71;
	case 11381ULL: goto x86_l_2c75;
	case 11386ULL: goto x86_l_2c7a;
	case 11391ULL: goto x86_l_2c7f;
	case 11395ULL: goto x86_l_2c83;
	case 11400ULL: goto x86_l_2c88;
	case 11402ULL: goto x86_l_2c8a;
	case 11406ULL: goto x86_l_2c8e;
	case 11411ULL: goto x86_l_2c93;
	case 11416ULL: goto x86_l_2c98;
	case 11420ULL: goto x86_l_2c9c;
	case 11425ULL: goto x86_l_2ca1;
	case 11427ULL: goto x86_l_2ca3;
	case 11431ULL: goto x86_l_2ca7;
	case 11436ULL: goto x86_l_2cac;
	case 11441ULL: goto x86_l_2cb1;
	case 11445ULL: goto x86_l_2cb5;
	case 11450ULL: goto x86_l_2cba;
	case 11452ULL: goto x86_l_2cbc;
	case 11461ULL: goto x86_l_2cc5;
	case 11468ULL: goto x86_l_2ccc;
	case 11473ULL: goto x86_l_2cd1;
	case 11478ULL: goto x86_l_2cd6;
	case 11483ULL: goto x86_l_2cdb;
	case 11485ULL: goto x86_l_2cdd;
	case 11490ULL: goto x86_l_2ce2;
	case 11495ULL: goto x86_l_2ce7;
	case 11500ULL: goto x86_l_2cec;
	case 11505ULL: goto x86_l_2cf1;
	case 11510ULL: goto x86_l_2cf6;
	case 11512ULL: goto x86_l_2cf8;
	case 11516ULL: goto x86_l_2cfc;
	case 11521ULL: goto x86_l_2d01;
	case 11526ULL: goto x86_l_2d06;
	case 11531ULL: goto x86_l_2d0b;
	case 11536ULL: goto x86_l_2d10;
	case 11538ULL: goto x86_l_2d12;
	case 11542ULL: goto x86_l_2d16;
	case 11549ULL: goto x86_l_2d1d;
	case 11554ULL: goto x86_l_2d22;
	case 11559ULL: goto x86_l_2d27;
	case 11564ULL: goto x86_l_2d2c;
	case 11567ULL: goto x86_l_2d2f;
	case 11569ULL: goto x86_l_2d31;
	case 11574ULL: goto x86_l_2d36;
	case 11578ULL: goto x86_l_2d3a;
	case 11582ULL: goto x86_l_2d3e;
	case 11587ULL: goto x86_l_2d43;
	case 11592ULL: goto x86_l_2d48;
	case 11594ULL: goto x86_l_2d4a;
	case 11597ULL: goto x86_l_2d4d;
	case 11601ULL: goto x86_l_2d51;
	case 11605ULL: goto x86_l_2d55;
	case 11610ULL: goto x86_l_2d5a;
	case 11615ULL: goto x86_l_2d5f;
	case 11617ULL: goto x86_l_2d61;
	case 11621ULL: goto x86_l_2d65;
	case 11626ULL: goto x86_l_2d6a;
	case 11629ULL: goto x86_l_2d6d;
	case 11634ULL: goto x86_l_2d72;
	case 11637ULL: goto x86_l_2d75;
	case 11639ULL: goto x86_l_2d77;
	case 11644ULL: goto x86_l_2d7c;
	case 11655ULL: goto x86_l_2d87;
	case 11666ULL: goto x86_l_2d92;
	case 11671ULL: goto x86_l_2d97;
	case 11678ULL: goto x86_l_2d9e;
	case 11681ULL: goto x86_l_2da1;
	case 11686ULL: goto x86_l_2da6;
	case 11688ULL: goto x86_l_2da8;
	case 11690ULL: goto x86_l_2daa;
	case 11697ULL: goto x86_l_2db1;
	case 11699ULL: goto x86_l_2db3;
	case 11700ULL: goto x86_l_2db4;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2b34:
	/* 0x2b34: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b39:
	/* 0x2b39: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b3e:
	/* 0x2b3e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b43:
	/* 0x2b43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b45:
	/* 0x2b45: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b4a:
	/* 0x2b4a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b4f:
	/* 0x2b4f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b54:
	/* 0x2b54: mov    esi,0x48 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 72ULL);
x86_l_2b59:
	/* 0x2b59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b5b:
	/* 0x2b5b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b60:
	/* 0x2b60: mov    edx,0x1a8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 424ULL);
x86_l_2b65:
	/* 0x2b65: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_2b6a:
	/* 0x2b6a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2b6d:
	/* 0x2b6d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b72:
	/* 0x2b72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b74:
	/* 0x2b74: lea    rdi,[r14+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2b78:
	/* 0x2b78: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b7d:
	/* 0x2b7d: mov    edx,0x470 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1136ULL);
x86_l_2b82:
	/* 0x2b82: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_2b87:
	/* 0x2b87: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b8c:
	/* 0x2b8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b8e:
	/* 0x2b8e: lea    rdi,[r14+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b92:
	/* 0x2b92: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b97:
	/* 0x2b97: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b9c:
	/* 0x2b9c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2ba0:
	/* 0x2ba0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ba5:
	/* 0x2ba5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ba7:
	/* 0x2ba7: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_2bb0:
	/* 0x2bb0: lea    rdx,[r15+0xb38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2872ULL);
x86_l_2bb7:
	/* 0x2bb7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bbc:
	/* 0x2bbc: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2bc1:
	/* 0x2bc1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bc6:
	/* 0x2bc6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bc8:
	/* 0x2bc8: cmp    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_2bce:
	/* 0x2bce: je     2c36 <generic_tracepoint_event+0x2c36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c36;
	}
x86_l_2bd0:
	/* 0x2bd0: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_2bd8:
	/* 0x2bd8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bdd:
	/* 0x2bdd: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2be2:
	/* 0x2be2: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2be6:
	/* 0x2be6: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2beb:
	/* 0x2beb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2bf0:
	/* 0x2bf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf2:
	/* 0x2bf2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bf7:
	/* 0x2bf7: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2bfc:
	/* 0x2bfc: movsxd rdx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 120ULL);
x86_l_2c01:
	/* 0x2c01: shl    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2c05:
	/* 0x2c05: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c08:
	/* 0x2c08: add    rdx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_2c0f:
	/* 0x2c0f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c14:
	/* 0x2c14: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2c19:
	/* 0x2c19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c1b:
	/* 0x2c1b: lea    rdi,[r14+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2c1f:
	/* 0x2c1f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c24:
	/* 0x2c24: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c29:
	/* 0x2c29: sub    rdx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_2c2d:
	/* 0x2c2d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c32:
	/* 0x2c32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c34:
	/* 0x2c34: jmp    2c3e <generic_tracepoint_event+0x2c3e> */
	goto x86_l_2c3e;
x86_l_2c36:
	/* 0x2c36: mov    DWORD PTR [r14+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_2c3e:
	/* 0x2c3e: lea    rdi,[r14+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c42:
	/* 0x2c42: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c47:
	/* 0x2c47: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c4c:
	/* 0x2c4c: sub    rdx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_2c50:
	/* 0x2c50: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c55:
	/* 0x2c55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c57:
	/* 0x2c57: lea    rdi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2c5b:
	/* 0x2c5b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c60:
	/* 0x2c60: mov    edx,0xa8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 168ULL);
x86_l_2c65:
	/* 0x2c65: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_2c6a:
	/* 0x2c6a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c6f:
	/* 0x2c6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c71:
	/* 0x2c71: lea    rdi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2c75:
	/* 0x2c75: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c7a:
	/* 0x2c7a: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c7f:
	/* 0x2c7f: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2c83:
	/* 0x2c83: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c88:
	/* 0x2c88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c8a:
	/* 0x2c8a: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2c8e:
	/* 0x2c8e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c93:
	/* 0x2c93: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2c98:
	/* 0x2c98: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2c9c:
	/* 0x2c9c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ca1:
	/* 0x2ca1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ca3:
	/* 0x2ca3: lea    rdi,[r14+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ca7:
	/* 0x2ca7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cac:
	/* 0x2cac: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2cb1:
	/* 0x2cb1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2cb5:
	/* 0x2cb5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2cba:
	/* 0x2cba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cbc:
	/* 0x2cbc: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2cc5:
	/* 0x2cc5: lea    rdx,[r15+0xa50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2640ULL);
x86_l_2ccc:
	/* 0x2ccc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cd1:
	/* 0x2cd1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cd6:
	/* 0x2cd6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cdb:
	/* 0x2cdb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cdd:
	/* 0x2cdd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ce2:
	/* 0x2ce2: mov    edx,0x4a0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1184ULL);
x86_l_2ce7:
	/* 0x2ce7: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2cec:
	/* 0x2cec: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2cf1:
	/* 0x2cf1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cf6:
	/* 0x2cf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cf8:
	/* 0x2cf8: lea    rdi,[r14+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_2cfc:
	/* 0x2cfc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d01:
	/* 0x2d01: mov    edx,0xe8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 232ULL);
x86_l_2d06:
	/* 0x2d06: add    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 104ULL);
x86_l_2d0b:
	/* 0x2d0b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d10:
	/* 0x2d10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d12:
	/* 0x2d12: lea    r12,[r14+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2d16:
	/* 0x2d16: add    r15,0xce0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3296ULL);
x86_l_2d1d:
	/* 0x2d1d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d22:
	/* 0x2d22: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d27:
	/* 0x2d27: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d2c:
	/* 0x2d2c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2d2f:
	/* 0x2d2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d31:
	/* 0x2d31: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d36:
	/* 0x2d36: lea    rdi,[r14+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2d3a:
	/* 0x2d3a: lea    rdx,[r15+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d3e:
	/* 0x2d3e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d43:
	/* 0x2d43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d48:
	/* 0x2d48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d4a:
	/* 0x2d4a: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2d4d:
	/* 0x2d4d: add    rdi,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_2d51:
	/* 0x2d51: lea    rdx,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d55:
	/* 0x2d55: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d5a:
	/* 0x2d5a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d5f:
	/* 0x2d5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d61:
	/* 0x2d61: add    r15,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_2d65:
	/* 0x2d65: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d6a:
	/* 0x2d6a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2d6d:
	/* 0x2d6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d72:
	/* 0x2d72: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2d75:
	/* 0x2d75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d77:
	/* 0x2d77: mov    BYTE PTR [r14+0x1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4294967296ULL);
x86_l_2d7c:
	/* 0x2d7c: mov    QWORD PTR [r14+0x5ee8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104350525423616ULL);
x86_l_2d87:
	/* 0x2d87: mov    QWORD PTR [r14+0x5ef0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104384885161984ULL);
x86_l_2d92:
	/* 0x2d92: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2d97:
	/* 0x2d97: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tp_calls)));
x86_l_2d9e:
	/* 0x2d9e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2da1:
	/* 0x2da1: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2da6:
	/* 0x2da6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2da8:
	/* 0x2da8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2daa:
	/* 0x2daa: add    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_2db1:
	/* 0x2db1: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2db3:
	/* 0x2db3: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2db4:
	/* 0x2db4: jmp    2db9 <generic_tracepoint_event+0x2db9> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_event_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 9796U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1791ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1794ULL && __x86_pc <= 3643ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3649ULL && __x86_pc <= 5487ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5491ULL && __x86_pc <= 7322ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7325ULL && __x86_pc <= 9169ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9176ULL && __x86_pc <= 11053ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 11060ULL && __x86_pc <= 11700ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_event_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

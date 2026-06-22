extern char execve_map;
extern char filter_map;
extern char process_call_heap;
extern char tg_mb_paths;
extern char tg_mb_sel_opts;
extern char tp_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_tracepoint_generic_tracepoint_filter_x86_chunk_0(
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
	case 61ULL: goto x86_l_3d;
	case 63ULL: goto x86_l_3f;
	case 66ULL: goto x86_l_42;
	case 71ULL: goto x86_l_47;
	case 78ULL: goto x86_l_4e;
	case 83ULL: goto x86_l_53;
	case 88ULL: goto x86_l_58;
	case 93ULL: goto x86_l_5d;
	case 98ULL: goto x86_l_62;
	case 103ULL: goto x86_l_67;
	case 108ULL: goto x86_l_6c;
	case 110ULL: goto x86_l_6e;
	case 114ULL: goto x86_l_72;
	case 118ULL: goto x86_l_76;
	case 125ULL: goto x86_l_7d;
	case 130ULL: goto x86_l_82;
	case 135ULL: goto x86_l_87;
	case 137ULL: goto x86_l_89;
	case 140ULL: goto x86_l_8c;
	case 142ULL: goto x86_l_8e;
	case 147ULL: goto x86_l_93;
	case 153ULL: goto x86_l_99;
	case 158ULL: goto x86_l_9e;
	case 163ULL: goto x86_l_a3;
	case 166ULL: goto x86_l_a6;
	case 171ULL: goto x86_l_ab;
	case 176ULL: goto x86_l_b0;
	case 181ULL: goto x86_l_b5;
	case 186ULL: goto x86_l_ba;
	case 191ULL: goto x86_l_bf;
	case 193ULL: goto x86_l_c1;
	case 198ULL: goto x86_l_c6;
	case 201ULL: goto x86_l_c9;
	case 207ULL: goto x86_l_cf;
	case 214ULL: goto x86_l_d6;
	case 219ULL: goto x86_l_db;
	case 224ULL: goto x86_l_e0;
	case 229ULL: goto x86_l_e5;
	case 234ULL: goto x86_l_ea;
	case 239ULL: goto x86_l_ef;
	case 244ULL: goto x86_l_f4;
	case 246ULL: goto x86_l_f6;
	case 250ULL: goto x86_l_fa;
	case 254ULL: goto x86_l_fe;
	case 261ULL: goto x86_l_105;
	case 266ULL: goto x86_l_10a;
	case 271ULL: goto x86_l_10f;
	case 273ULL: goto x86_l_111;
	case 276ULL: goto x86_l_114;
	case 278ULL: goto x86_l_116;
	case 283ULL: goto x86_l_11b;
	case 289ULL: goto x86_l_121;
	case 294ULL: goto x86_l_126;
	case 299ULL: goto x86_l_12b;
	case 302ULL: goto x86_l_12e;
	case 307ULL: goto x86_l_133;
	case 312ULL: goto x86_l_138;
	case 317ULL: goto x86_l_13d;
	case 322ULL: goto x86_l_142;
	case 327ULL: goto x86_l_147;
	case 329ULL: goto x86_l_149;
	case 334ULL: goto x86_l_14e;
	case 337ULL: goto x86_l_151;
	case 343ULL: goto x86_l_157;
	case 350ULL: goto x86_l_15e;
	case 355ULL: goto x86_l_163;
	case 360ULL: goto x86_l_168;
	case 365ULL: goto x86_l_16d;
	case 370ULL: goto x86_l_172;
	case 375ULL: goto x86_l_177;
	case 380ULL: goto x86_l_17c;
	case 382ULL: goto x86_l_17e;
	case 386ULL: goto x86_l_182;
	case 390ULL: goto x86_l_186;
	case 397ULL: goto x86_l_18d;
	case 402ULL: goto x86_l_192;
	case 407ULL: goto x86_l_197;
	case 409ULL: goto x86_l_199;
	case 412ULL: goto x86_l_19c;
	case 414ULL: goto x86_l_19e;
	case 419ULL: goto x86_l_1a3;
	case 425ULL: goto x86_l_1a9;
	case 430ULL: goto x86_l_1ae;
	case 435ULL: goto x86_l_1b3;
	case 438ULL: goto x86_l_1b6;
	case 443ULL: goto x86_l_1bb;
	case 448ULL: goto x86_l_1c0;
	case 453ULL: goto x86_l_1c5;
	case 458ULL: goto x86_l_1ca;
	case 463ULL: goto x86_l_1cf;
	case 465ULL: goto x86_l_1d1;
	case 470ULL: goto x86_l_1d6;
	case 473ULL: goto x86_l_1d9;
	case 479ULL: goto x86_l_1df;
	case 486ULL: goto x86_l_1e6;
	case 491ULL: goto x86_l_1eb;
	case 496ULL: goto x86_l_1f0;
	case 501ULL: goto x86_l_1f5;
	case 506ULL: goto x86_l_1fa;
	case 511ULL: goto x86_l_1ff;
	case 516ULL: goto x86_l_204;
	case 518ULL: goto x86_l_206;
	case 522ULL: goto x86_l_20a;
	case 526ULL: goto x86_l_20e;
	case 533ULL: goto x86_l_215;
	case 538ULL: goto x86_l_21a;
	case 543ULL: goto x86_l_21f;
	case 545ULL: goto x86_l_221;
	case 548ULL: goto x86_l_224;
	case 554ULL: goto x86_l_22a;
	case 559ULL: goto x86_l_22f;
	case 565ULL: goto x86_l_235;
	case 568ULL: goto x86_l_238;
	case 575ULL: goto x86_l_23f;
	case 582ULL: goto x86_l_246;
	case 587ULL: goto x86_l_24b;
	case 589ULL: goto x86_l_24d;
	case 592ULL: goto x86_l_250;
	case 598ULL: goto x86_l_256;
	case 605ULL: goto x86_l_25d;
	case 609ULL: goto x86_l_261;
	case 611ULL: goto x86_l_263;
	case 615ULL: goto x86_l_267;
	case 619ULL: goto x86_l_26b;
	case 623ULL: goto x86_l_26f;
	case 627ULL: goto x86_l_273;
	case 635ULL: goto x86_l_27b;
	case 641ULL: goto x86_l_281;
	case 646ULL: goto x86_l_286;
	case 649ULL: goto x86_l_289;
	case 652ULL: goto x86_l_28c;
	case 655ULL: goto x86_l_28f;
	case 661ULL: goto x86_l_295;
	case 664ULL: goto x86_l_298;
	case 670ULL: goto x86_l_29e;
	case 675ULL: goto x86_l_2a3;
	case 680ULL: goto x86_l_2a8;
	case 687ULL: goto x86_l_2af;
	case 692ULL: goto x86_l_2b4;
	case 697ULL: goto x86_l_2b9;
	case 699ULL: goto x86_l_2bb;
	case 702ULL: goto x86_l_2be;
	case 708ULL: goto x86_l_2c4;
	case 710ULL: goto x86_l_2c6;
	case 712ULL: goto x86_l_2c8;
	case 718ULL: goto x86_l_2ce;
	case 721ULL: goto x86_l_2d1;
	case 724ULL: goto x86_l_2d4;
	case 727ULL: goto x86_l_2d7;
	case 733ULL: goto x86_l_2dd;
	case 737ULL: goto x86_l_2e1;
	case 743ULL: goto x86_l_2e7;
	case 746ULL: goto x86_l_2ea;
	case 751ULL: goto x86_l_2ef;
	case 754ULL: goto x86_l_2f2;
	case 756ULL: goto x86_l_2f4;
	case 763ULL: goto x86_l_2fb;
	case 766ULL: goto x86_l_2fe;
	case 770ULL: goto x86_l_302;
	case 772ULL: goto x86_l_304;
	case 779ULL: goto x86_l_30b;
	case 784ULL: goto x86_l_310;
	case 787ULL: goto x86_l_313;
	case 792ULL: goto x86_l_318;
	case 794ULL: goto x86_l_31a;
	case 797ULL: goto x86_l_31d;
	case 800ULL: goto x86_l_320;
	case 806ULL: goto x86_l_326;
	case 809ULL: goto x86_l_329;
	case 813ULL: goto x86_l_32d;
	case 818ULL: goto x86_l_332;
	case 820ULL: goto x86_l_334;
	case 823ULL: goto x86_l_337;
	case 826ULL: goto x86_l_33a;
	case 830ULL: goto x86_l_33e;
	case 833ULL: goto x86_l_341;
	case 836ULL: goto x86_l_344;
	case 842ULL: goto x86_l_34a;
	case 844ULL: goto x86_l_34c;
	case 854ULL: goto x86_l_356;
	case 858ULL: goto x86_l_35a;
	case 864ULL: goto x86_l_360;
	case 867ULL: goto x86_l_363;
	case 872ULL: goto x86_l_368;
	case 874ULL: goto x86_l_36a;
	case 879ULL: goto x86_l_36f;
	case 887ULL: goto x86_l_377;
	case 889ULL: goto x86_l_379;
	case 893ULL: goto x86_l_37d;
	case 897ULL: goto x86_l_381;
	case 901ULL: goto x86_l_385;
	case 906ULL: goto x86_l_38a;
	case 909ULL: goto x86_l_38d;
	case 914ULL: goto x86_l_392;
	case 917ULL: goto x86_l_395;
	case 925ULL: goto x86_l_39d;
	case 929ULL: goto x86_l_3a1;
	case 932ULL: goto x86_l_3a4;
	case 938ULL: goto x86_l_3aa;
	case 940ULL: goto x86_l_3ac;
	case 943ULL: goto x86_l_3af;
	case 949ULL: goto x86_l_3b5;
	case 953ULL: goto x86_l_3b9;
	case 957ULL: goto x86_l_3bd;
	case 963ULL: goto x86_l_3c3;
	case 967ULL: goto x86_l_3c7;
	case 971ULL: goto x86_l_3cb;
	case 976ULL: goto x86_l_3d0;
	case 981ULL: goto x86_l_3d5;
	case 983ULL: goto x86_l_3d7;
	case 987ULL: goto x86_l_3db;
	case 991ULL: goto x86_l_3df;
	case 994ULL: goto x86_l_3e2;
	case 996ULL: goto x86_l_3e4;
	case 1000ULL: goto x86_l_3e8;
	case 1003ULL: goto x86_l_3eb;
	case 1007ULL: goto x86_l_3ef;
	case 1012ULL: goto x86_l_3f4;
	case 1015ULL: goto x86_l_3f7;
	case 1019ULL: goto x86_l_3fb;
	case 1025ULL: goto x86_l_401;
	case 1027ULL: goto x86_l_403;
	case 1029ULL: goto x86_l_405;
	case 1031ULL: goto x86_l_407;
	case 1036ULL: goto x86_l_40c;
	case 1041ULL: goto x86_l_411;
	case 1044ULL: goto x86_l_414;
	case 1049ULL: goto x86_l_419;
	case 1054ULL: goto x86_l_41e;
	case 1059ULL: goto x86_l_423;
	case 1064ULL: goto x86_l_428;
	case 1069ULL: goto x86_l_42d;
	case 1071ULL: goto x86_l_42f;
	case 1076ULL: goto x86_l_434;
	case 1079ULL: goto x86_l_437;
	case 1082ULL: goto x86_l_43a;
	case 1088ULL: goto x86_l_440;
	case 1091ULL: goto x86_l_443;
	case 1097ULL: goto x86_l_449;
	case 1100ULL: goto x86_l_44c;
	case 1102ULL: goto x86_l_44e;
	case 1105ULL: goto x86_l_451;
	case 1108ULL: goto x86_l_454;
	case 1113ULL: goto x86_l_459;
	case 1116ULL: goto x86_l_45c;
	case 1121ULL: goto x86_l_461;
	case 1124ULL: goto x86_l_464;
	case 1127ULL: goto x86_l_467;
	case 1130ULL: goto x86_l_46a;
	case 1134ULL: goto x86_l_46e;
	case 1136ULL: goto x86_l_470;
	case 1138ULL: goto x86_l_472;
	case 1142ULL: goto x86_l_476;
	case 1144ULL: goto x86_l_478;
	case 1147ULL: goto x86_l_47b;
	case 1153ULL: goto x86_l_481;
	case 1156ULL: goto x86_l_484;
	case 1159ULL: goto x86_l_487;
	case 1163ULL: goto x86_l_48b;
	case 1167ULL: goto x86_l_48f;
	case 1172ULL: goto x86_l_494;
	case 1178ULL: goto x86_l_49a;
	case 1184ULL: goto x86_l_4a0;
	case 1186ULL: goto x86_l_4a2;
	case 1189ULL: goto x86_l_4a5;
	case 1192ULL: goto x86_l_4a8;
	case 1198ULL: goto x86_l_4ae;
	case 1201ULL: goto x86_l_4b1;
	case 1204ULL: goto x86_l_4b4;
	case 1210ULL: goto x86_l_4ba;
	case 1215ULL: goto x86_l_4bf;
	case 1220ULL: goto x86_l_4c4;
	case 1225ULL: goto x86_l_4c9;
	case 1230ULL: goto x86_l_4ce;
	case 1235ULL: goto x86_l_4d3;
	case 1239ULL: goto x86_l_4d7;
	case 1246ULL: goto x86_l_4de;
	case 1251ULL: goto x86_l_4e3;
	case 1253ULL: goto x86_l_4e5;
	case 1256ULL: goto x86_l_4e8;
	case 1262ULL: goto x86_l_4ee;
	case 1265ULL: goto x86_l_4f1;
	case 1267ULL: goto x86_l_4f3;
	case 1272ULL: goto x86_l_4f8;
	case 1275ULL: goto x86_l_4fb;
	case 1281ULL: goto x86_l_501;
	case 1284ULL: goto x86_l_504;
	case 1287ULL: goto x86_l_507;
	case 1293ULL: goto x86_l_50d;
	case 1297ULL: goto x86_l_511;
	case 1304ULL: goto x86_l_518;
	case 1309ULL: goto x86_l_51d;
	case 1311ULL: goto x86_l_51f;
	case 1314ULL: goto x86_l_522;
	case 1320ULL: goto x86_l_528;
	case 1323ULL: goto x86_l_52b;
	case 1325ULL: goto x86_l_52d;
	case 1330ULL: goto x86_l_532;
	case 1333ULL: goto x86_l_535;
	case 1339ULL: goto x86_l_53b;
	case 1342ULL: goto x86_l_53e;
	case 1345ULL: goto x86_l_541;
	case 1351ULL: goto x86_l_547;
	case 1355ULL: goto x86_l_54b;
	case 1362ULL: goto x86_l_552;
	case 1367ULL: goto x86_l_557;
	case 1369ULL: goto x86_l_559;
	case 1372ULL: goto x86_l_55c;
	case 1378ULL: goto x86_l_562;
	case 1381ULL: goto x86_l_565;
	case 1383ULL: goto x86_l_567;
	case 1388ULL: goto x86_l_56c;
	case 1394ULL: goto x86_l_572;
	case 1397ULL: goto x86_l_575;
	case 1402ULL: goto x86_l_57a;
	case 1408ULL: goto x86_l_580;
	case 1412ULL: goto x86_l_584;
	case 1419ULL: goto x86_l_58b;
	case 1424ULL: goto x86_l_590;
	case 1426ULL: goto x86_l_592;
	case 1429ULL: goto x86_l_595;
	case 1435ULL: goto x86_l_59b;
	case 1438ULL: goto x86_l_59e;
	case 1440ULL: goto x86_l_5a0;
	case 1445ULL: goto x86_l_5a5;
	case 1451ULL: goto x86_l_5ab;
	case 1454ULL: goto x86_l_5ae;
	case 1459ULL: goto x86_l_5b3;
	case 1465ULL: goto x86_l_5b9;
	case 1469ULL: goto x86_l_5bd;
	case 1476ULL: goto x86_l_5c4;
	case 1481ULL: goto x86_l_5c9;
	case 1483ULL: goto x86_l_5cb;
	case 1486ULL: goto x86_l_5ce;
	case 1492ULL: goto x86_l_5d4;
	case 1495ULL: goto x86_l_5d7;
	case 1497ULL: goto x86_l_5d9;
	case 1502ULL: goto x86_l_5de;
	case 1508ULL: goto x86_l_5e4;
	case 1511ULL: goto x86_l_5e7;
	case 1516ULL: goto x86_l_5ec;
	case 1522ULL: goto x86_l_5f2;
	case 1526ULL: goto x86_l_5f6;
	case 1533ULL: goto x86_l_5fd;
	case 1538ULL: goto x86_l_602;
	case 1540ULL: goto x86_l_604;
	case 1543ULL: goto x86_l_607;
	case 1549ULL: goto x86_l_60d;
	case 1552ULL: goto x86_l_610;
	case 1554ULL: goto x86_l_612;
	case 1559ULL: goto x86_l_617;
	case 1565ULL: goto x86_l_61d;
	case 1568ULL: goto x86_l_620;
	case 1573ULL: goto x86_l_625;
	case 1579ULL: goto x86_l_62b;
	case 1583ULL: goto x86_l_62f;
	case 1590ULL: goto x86_l_636;
	case 1595ULL: goto x86_l_63b;
	case 1597ULL: goto x86_l_63d;
	case 1600ULL: goto x86_l_640;
	case 1606ULL: goto x86_l_646;
	case 1609ULL: goto x86_l_649;
	case 1611ULL: goto x86_l_64b;
	case 1616ULL: goto x86_l_650;
	case 1622ULL: goto x86_l_656;
	case 1625ULL: goto x86_l_659;
	case 1630ULL: goto x86_l_65e;
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
	/* 0xa: sub    rsp,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 88ULL);
x86_l_e:
	/* 0xe: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_11:
	/* 0x11: mov    DWORD PTR [rsp+0x54],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_19:
	/* 0x19: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_20:
	/* 0x20: lea    rsi,[rsp+0x54] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
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
	/* 0x2f: je     2064 <generic_tracepoint_filter+0x2064> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8292ULL;
	}
x86_l_35:
	/* 0x35: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_38:
	/* 0x38: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_3d:
	/* 0x3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f:
	/* 0x3f: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_42:
	/* 0x42: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_47:
	/* 0x47: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_4e:
	/* 0x4e: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_53:
	/* 0x53: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_58:
	/* 0x58: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d:
	/* 0x5d: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_62:
	/* 0x62: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_67:
	/* 0x67: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6c:
	/* 0x6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e:
	/* 0x6e: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_72:
	/* 0x72: mov    DWORD PTR [rsp+0x44],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_76:
	/* 0x76: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_7d:
	/* 0x7d: lea    rsi,[rsp+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_82:
	/* 0x82: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_87:
	/* 0x87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_89:
	/* 0x89: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8c:
	/* 0x8c: je     99 <generic_tracepoint_filter+0x99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_99;
	}
x86_l_8e:
	/* 0x8e: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_93:
	/* 0x93: jne    235 <generic_tracepoint_filter+0x235> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_235;
	}
x86_l_99:
	/* 0x99: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_9e:
	/* 0x9e: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a3:
	/* 0xa3: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a6:
	/* 0xa6: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ab:
	/* 0xab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b0:
	/* 0xb0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b5:
	/* 0xb5: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_ba:
	/* 0xba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bf:
	/* 0xbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c1:
	/* 0xc1: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c6:
	/* 0xc6: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_c9:
	/* 0xc9: je     2064 <generic_tracepoint_filter+0x2064> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8292ULL;
	}
x86_l_cf:
	/* 0xcf: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_d6:
	/* 0xd6: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_db:
	/* 0xdb: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_e0:
	/* 0xe0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e5:
	/* 0xe5: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_ea:
	/* 0xea: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_ef:
	/* 0xef: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f4:
	/* 0xf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f6:
	/* 0xf6: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_fa:
	/* 0xfa: mov    DWORD PTR [rsp+0x44],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_fe:
	/* 0xfe: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_105:
	/* 0x105: lea    rsi,[rsp+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_10a:
	/* 0x10a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10f:
	/* 0x10f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_111:
	/* 0x111: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_114:
	/* 0x114: je     121 <generic_tracepoint_filter+0x121> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_121;
	}
x86_l_116:
	/* 0x116: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_11b:
	/* 0x11b: jne    235 <generic_tracepoint_filter+0x235> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_235;
	}
x86_l_121:
	/* 0x121: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_126:
	/* 0x126: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_12b:
	/* 0x12b: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_12e:
	/* 0x12e: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_133:
	/* 0x133: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_138:
	/* 0x138: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13d:
	/* 0x13d: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_142:
	/* 0x142: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_147:
	/* 0x147: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_149:
	/* 0x149: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14e:
	/* 0x14e: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_151:
	/* 0x151: je     2064 <generic_tracepoint_filter+0x2064> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8292ULL;
	}
x86_l_157:
	/* 0x157: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_15e:
	/* 0x15e: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_163:
	/* 0x163: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_168:
	/* 0x168: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16d:
	/* 0x16d: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_172:
	/* 0x172: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_177:
	/* 0x177: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17c:
	/* 0x17c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17e:
	/* 0x17e: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_182:
	/* 0x182: mov    DWORD PTR [rsp+0x44],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_186:
	/* 0x186: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_18d:
	/* 0x18d: lea    rsi,[rsp+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_192:
	/* 0x192: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_197:
	/* 0x197: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_199:
	/* 0x199: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19c:
	/* 0x19c: je     1a9 <generic_tracepoint_filter+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a9;
	}
x86_l_19e:
	/* 0x19e: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1a3:
	/* 0x1a3: jne    235 <generic_tracepoint_filter+0x235> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_235;
	}
x86_l_1a9:
	/* 0x1a9: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_1ae:
	/* 0x1ae: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b3:
	/* 0x1b3: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b6:
	/* 0x1b6: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1bb:
	/* 0x1bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c0:
	/* 0x1c0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c5:
	/* 0x1c5: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_1ca:
	/* 0x1ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cf:
	/* 0x1cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d1:
	/* 0x1d1: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d6:
	/* 0x1d6: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1d9:
	/* 0x1d9: je     2064 <generic_tracepoint_filter+0x2064> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8292ULL;
	}
x86_l_1df:
	/* 0x1df: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_1e6:
	/* 0x1e6: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1eb:
	/* 0x1eb: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1f0:
	/* 0x1f0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f5:
	/* 0x1f5: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_1fa:
	/* 0x1fa: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_1ff:
	/* 0x1ff: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_204:
	/* 0x204: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_206:
	/* 0x206: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_20a:
	/* 0x20a: mov    DWORD PTR [rsp+0x44],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_20e:
	/* 0x20e: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_215:
	/* 0x215: lea    rsi,[rsp+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_21a:
	/* 0x21a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21f:
	/* 0x21f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_221:
	/* 0x221: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_224:
	/* 0x224: je     407 <generic_tracepoint_filter+0x407> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_407;
	}
x86_l_22a:
	/* 0x22a: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_22f:
	/* 0x22f: je     407 <generic_tracepoint_filter+0x407> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_407;
	}
x86_l_235:
	/* 0x235: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_238:
	/* 0x238: lea    rsi,[r14+0x5ee8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24296ULL);
x86_l_23f:
	/* 0x23f: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_246:
	/* 0x246: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24b:
	/* 0x24b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24d:
	/* 0x24d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_250:
	/* 0x250: je     2064 <generic_tracepoint_filter+0x2064> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8292ULL;
	}
x86_l_256:
	/* 0x256: mov    r12,QWORD PTR [r14+0x5eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24248ULL);
x86_l_25d:
	/* 0x25d: cmp    r12,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 6ULL);
x86_l_261:
	/* 0x261: jb     286 <generic_tracepoint_filter+0x286> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_286;
	}
x86_l_263:
	/* 0x263: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_267:
	/* 0x267: mov    DWORD PTR [r14+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26b:
	/* 0x26b: mov    rax,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26f:
	/* 0x26f: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_273:
	/* 0x273: cmp    BYTE PTR [r14+0x5ec0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731776ULL);
x86_l_27b:
	/* 0x27b: jne    2049 <generic_tracepoint_filter+0x2049> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8265ULL;
	}
x86_l_281:
	/* 0x281: jmp    2064 <generic_tracepoint_filter+0x2064> */
	return 8292ULL;
x86_l_286:
	/* 0x286: movsxd r15,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_289:
	/* 0x289: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_28c:
	/* 0x28c: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_28f:
	/* 0x28f: je     36f <generic_tracepoint_filter+0x36f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36f;
	}
x86_l_295:
	/* 0x295: cmp    r12,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R15, X86_WIDTH_64);
x86_l_298:
	/* 0x298: jae    2031 <generic_tracepoint_filter+0x2031> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8241ULL;
	}
x86_l_29e:
	/* 0x29e: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a3:
	/* 0x2a3: mov    DWORD PTR [rsp+0x38],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2a8:
	/* 0x2a8: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mb_sel_opts)));
x86_l_2af:
	/* 0x2af: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b4:
	/* 0x2b4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b9:
	/* 0x2b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bb:
	/* 0x2bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2be:
	/* 0x2be: je     38a <generic_tracepoint_filter+0x38a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38a;
	}
x86_l_2c4:
	/* 0x2c4: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c6:
	/* 0x2c6: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2c8:
	/* 0x2c8: je     38a <generic_tracepoint_filter+0x38a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38a;
	}
x86_l_2ce:
	/* 0x2ce: lea    ecx,[rdx-0x5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551611ULL);
x86_l_2d1:
	/* 0x2d1: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2d4:
	/* 0x2d4: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_2d7:
	/* 0x2d7: ja     201b <generic_tracepoint_filter+0x201b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8219ULL;
	}
x86_l_2dd:
	/* 0x2dd: cmp    DWORD PTR [rcx+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_2e1:
	/* 0x2e1: js     201b <generic_tracepoint_filter+0x201b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8219ULL;
	}
x86_l_2e7:
	/* 0x2e7: mov    edi,DWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ea:
	/* 0x2ea: mov    esi,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967295ULL);
x86_l_2ef:
	/* 0x2ef: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_2f2:
	/* 0x2f2: je     304 <generic_tracepoint_filter+0x304> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_304;
	}
x86_l_2f4:
	/* 0x2f4: mov    r8,QWORD PTR [rcx+0x370] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 880ULL);
x86_l_2fb:
	/* 0x2fb: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_2fe:
	/* 0x2fe: bt     r8,rdi */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RDI, X86_WIDTH_64);
x86_l_302:
	/* 0x302: jb     341 <generic_tracepoint_filter+0x341> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_341;
	}
x86_l_304:
	/* 0x304: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mb_paths)));
x86_l_30b:
	/* 0x30b: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_310:
	/* 0x310: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_313:
	/* 0x313: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_318:
	/* 0x318: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31a:
	/* 0x31a: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_31d:
	/* 0x31d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_320:
	/* 0x320: je     201b <generic_tracepoint_filter+0x201b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8219ULL;
	}
x86_l_326:
	/* 0x326: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_329:
	/* 0x329: lea    rsi,[rcx+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_32d:
	/* 0x32d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_332:
	/* 0x332: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_334:
	/* 0x334: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_337:
	/* 0x337: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33a:
	/* 0x33a: setne  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_NE);
x86_l_33e:
	/* 0x33e: mov    edx,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_341:
	/* 0x341: cmp    edx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 37ULL);
x86_l_344:
	/* 0x344: ja     885 <generic_tracepoint_filter+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2181ULL;
	}
x86_l_34a:
	/* 0x34a: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_34c:
	/* 0x34c: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_356:
	/* 0x356: bt     rdx,rax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_35a:
	/* 0x35a: jae    885 <generic_tracepoint_filter+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2181ULL;
	}
x86_l_360:
	/* 0x360: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_363:
	/* 0x363: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_368:
	/* 0x368: je     392 <generic_tracepoint_filter+0x392> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_392;
	}
x86_l_36a:
	/* 0x36a: jmp    201b <generic_tracepoint_filter+0x201b> */
	return 8219ULL;
x86_l_36f:
	/* 0x36f: mov    BYTE PTR [r14+0x5ec0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731777ULL);
x86_l_377:
	/* 0x377: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_379:
	/* 0x379: mov    DWORD PTR [r14+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37d:
	/* 0x37d: mov    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_381:
	/* 0x381: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_385:
	/* 0x385: jmp    2049 <generic_tracepoint_filter+0x2049> */
	return 8265ULL;
x86_l_38a:
	/* 0x38a: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_38d:
	/* 0x38d: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_392:
	/* 0x392: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_395:
	/* 0x395: lea    rsi,[rdx*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 2), 4ULL);
x86_l_39d:
	/* 0x39d: mov    edx,DWORD PTR [rax+rdx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 4ULL);
x86_l_3a1:
	/* 0x3a1: lea    ebp,[rdx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_3a4:
	/* 0x3a4: and    ebp,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_3aa:
	/* 0x3aa: add    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3ac:
	/* 0x3ac: add    edx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3af:
	/* 0x3af: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_3b5:
	/* 0x3b5: lea    r11,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b9:
	/* 0x3b9: cmp    DWORD PTR [rdx+rax*1],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 5ULL);
x86_l_3bd:
	/* 0x3bd: jb     17b5 <generic_tracepoint_filter+0x17b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6069ULL;
	}
x86_l_3c3:
	/* 0x3c3: lea    r8d,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3c7:
	/* 0x3c7: mov    r9d,DWORD PTR [r11+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3cb:
	/* 0x3cb: mov    r10d,DWORD PTR [r11+rax*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_3d0:
	/* 0x3d0: mov    edx,DWORD PTR [r11+rax*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 8ULL);
x86_l_3d5:
	/* 0x3d5: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3d7:
	/* 0x3d7: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_3db:
	/* 0x3db: sete   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_E);
x86_l_3df:
	/* 0x3df: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3e2:
	/* 0x3e2: jbe    434 <generic_tracepoint_filter+0x434> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_434;
	}
x86_l_3e4:
	/* 0x3e4: lea    rdx,[rcx+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3e8:
	/* 0x3e8: mov    rsi,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R10, X86_WIDTH_64);
x86_l_3eb:
	/* 0x3eb: and    rsi,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_AND, 1ULL);
x86_l_3ef:
	/* 0x3ef: mov    QWORD PTR [rsp+0x48],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3f4:
	/* 0x3f4: mov    rsi,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3f7:
	/* 0x3f7: cmove  rsi,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_3fb:
	/* 0x3fb: cmp    ebp,0x3d4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 980ULL);
x86_l_401:
	/* 0x401: jbe    461 <generic_tracepoint_filter+0x461> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_461;
	}
x86_l_403:
	/* 0x403: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_405:
	/* 0x405: jmp    46a <generic_tracepoint_filter+0x46a> */
	goto x86_l_46a;
x86_l_407:
	/* 0x407: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_40c:
	/* 0x40c: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_411:
	/* 0x411: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_414:
	/* 0x414: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_419:
	/* 0x419: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41e:
	/* 0x41e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_423:
	/* 0x423: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_428:
	/* 0x428: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42d:
	/* 0x42d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42f:
	/* 0x42f: jmp    2064 <generic_tracepoint_filter+0x2064> */
	return 8292ULL;
x86_l_434:
	/* 0x434: mov    dil,sil */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_8);
x86_l_437:
	/* 0x437: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_43a:
	/* 0x43a: je     86b <generic_tracepoint_filter+0x86b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2155ULL;
	}
x86_l_440:
	/* 0x440: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_443:
	/* 0x443: je     854 <generic_tracepoint_filter+0x854> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2132ULL;
	}
x86_l_449:
	/* 0x449: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_44c:
	/* 0x44c: jne    3e4 <generic_tracepoint_filter+0x3e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3e4;
	}
x86_l_44e:
	/* 0x44e: mov    edx,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R10, X86_WIDTH_32);
x86_l_451:
	/* 0x451: and    edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_454:
	/* 0x454: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_459:
	/* 0x459: mov    ebp,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_32);
x86_l_45c:
	/* 0x45c: jmp    92b <generic_tracepoint_filter+0x92b> */
	return 2347ULL;
x86_l_461:
	/* 0x461: mov    edi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R8, X86_WIDTH_32);
x86_l_464:
	/* 0x464: and    edi,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_467:
	/* 0x467: mov    edi,DWORD PTR [rax+rdi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_46a:
	/* 0x46a: test   r10b,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R10, X86_WIDTH_8, 2ULL);
x86_l_46e:
	/* 0x46e: jne    494 <generic_tracepoint_filter+0x494> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_494;
	}
x86_l_470:
	/* 0x470: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_472:
	/* 0x472: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_476:
	/* 0x476: jne    481 <generic_tracepoint_filter+0x481> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_481;
	}
x86_l_478:
	/* 0x478: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_47b:
	/* 0x47b: jne    84c <generic_tracepoint_filter+0x84c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2124ULL;
	}
x86_l_481:
	/* 0x481: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_484:
	/* 0x484: setne  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_NE);
x86_l_487:
	/* 0x487: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_48b:
	/* 0x48b: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_48f:
	/* 0x48f: jmp    921 <generic_tracepoint_filter+0x921> */
	return 2337ULL;
x86_l_494:
	/* 0x494: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_49a:
	/* 0x49a: jne    6ce <generic_tracepoint_filter+0x6ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1742ULL;
	}
x86_l_4a0:
	/* 0x4a0: mov    edx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a2:
	/* 0x4a2: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_4a5:
	/* 0x4a5: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_4a8:
	/* 0x4a8: je     916 <generic_tracepoint_filter+0x916> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2326ULL;
	}
x86_l_4ae:
	/* 0x4ae: mov    edx,DWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b1:
	/* 0x4b1: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_4b4:
	/* 0x4b4: je     916 <generic_tracepoint_filter+0x916> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2326ULL;
	}
x86_l_4ba:
	/* 0x4ba: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4bf:
	/* 0x4bf: mov    QWORD PTR [rsp+0x30],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4c4:
	/* 0x4c4: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c9:
	/* 0x4c9: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ce:
	/* 0x4ce: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4d3:
	/* 0x4d3: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d7:
	/* 0x4d7: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_4de:
	/* 0x4de: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e3:
	/* 0x4e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e5:
	/* 0x4e5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e8:
	/* 0x4e8: je     8f1 <generic_tracepoint_filter+0x8f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2289ULL;
	}
x86_l_4ee:
	/* 0x4ee: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_4f1:
	/* 0x4f1: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f3:
	/* 0x4f3: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4f8:
	/* 0x4f8: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_4fb:
	/* 0x4fb: je     82b <generic_tracepoint_filter+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2091ULL;
	}
x86_l_501:
	/* 0x501: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_504:
	/* 0x504: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_507:
	/* 0x507: je     82b <generic_tracepoint_filter+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2091ULL;
	}
x86_l_50d:
	/* 0x50d: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_511:
	/* 0x511: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_518:
	/* 0x518: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_51d:
	/* 0x51d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51f:
	/* 0x51f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_522:
	/* 0x522: je     8f1 <generic_tracepoint_filter+0x8f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2289ULL;
	}
x86_l_528:
	/* 0x528: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_52b:
	/* 0x52b: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52d:
	/* 0x52d: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_532:
	/* 0x532: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_535:
	/* 0x535: je     82b <generic_tracepoint_filter+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2091ULL;
	}
x86_l_53b:
	/* 0x53b: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53e:
	/* 0x53e: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_541:
	/* 0x541: je     82b <generic_tracepoint_filter+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2091ULL;
	}
x86_l_547:
	/* 0x547: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_54b:
	/* 0x54b: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_552:
	/* 0x552: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_557:
	/* 0x557: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_559:
	/* 0x559: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_55c:
	/* 0x55c: je     8f1 <generic_tracepoint_filter+0x8f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2289ULL;
	}
x86_l_562:
	/* 0x562: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_565:
	/* 0x565: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_567:
	/* 0x567: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_56c:
	/* 0x56c: je     82b <generic_tracepoint_filter+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2091ULL;
	}
x86_l_572:
	/* 0x572: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_575:
	/* 0x575: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_57a:
	/* 0x57a: je     82b <generic_tracepoint_filter+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2091ULL;
	}
x86_l_580:
	/* 0x580: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_584:
	/* 0x584: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_58b:
	/* 0x58b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_590:
	/* 0x590: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_592:
	/* 0x592: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_595:
	/* 0x595: je     8f1 <generic_tracepoint_filter+0x8f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2289ULL;
	}
x86_l_59b:
	/* 0x59b: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_59e:
	/* 0x59e: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a0:
	/* 0x5a0: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5a5:
	/* 0x5a5: je     82b <generic_tracepoint_filter+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2091ULL;
	}
x86_l_5ab:
	/* 0x5ab: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ae:
	/* 0x5ae: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5b3:
	/* 0x5b3: je     82b <generic_tracepoint_filter+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2091ULL;
	}
x86_l_5b9:
	/* 0x5b9: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5bd:
	/* 0x5bd: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_5c4:
	/* 0x5c4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5c9:
	/* 0x5c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cb:
	/* 0x5cb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5ce:
	/* 0x5ce: je     8f1 <generic_tracepoint_filter+0x8f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2289ULL;
	}
x86_l_5d4:
	/* 0x5d4: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_5d7:
	/* 0x5d7: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d9:
	/* 0x5d9: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5de:
	/* 0x5de: je     82b <generic_tracepoint_filter+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2091ULL;
	}
x86_l_5e4:
	/* 0x5e4: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e7:
	/* 0x5e7: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5ec:
	/* 0x5ec: je     82b <generic_tracepoint_filter+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2091ULL;
	}
x86_l_5f2:
	/* 0x5f2: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5f6:
	/* 0x5f6: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_5fd:
	/* 0x5fd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_602:
	/* 0x602: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_604:
	/* 0x604: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_607:
	/* 0x607: je     8f1 <generic_tracepoint_filter+0x8f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2289ULL;
	}
x86_l_60d:
	/* 0x60d: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_610:
	/* 0x610: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_612:
	/* 0x612: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_617:
	/* 0x617: je     82b <generic_tracepoint_filter+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2091ULL;
	}
x86_l_61d:
	/* 0x61d: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_620:
	/* 0x620: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_625:
	/* 0x625: je     82b <generic_tracepoint_filter+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2091ULL;
	}
x86_l_62b:
	/* 0x62b: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_62f:
	/* 0x62f: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_636:
	/* 0x636: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_63b:
	/* 0x63b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63d:
	/* 0x63d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_640:
	/* 0x640: je     8f1 <generic_tracepoint_filter+0x8f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2289ULL;
	}
x86_l_646:
	/* 0x646: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_649:
	/* 0x649: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_64b:
	/* 0x64b: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_650:
	/* 0x650: je     82b <generic_tracepoint_filter+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2091ULL;
	}
x86_l_656:
	/* 0x656: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_659:
	/* 0x659: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_65e:
	/* 0x65e: je     82b <generic_tracepoint_filter+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2091ULL;
	}
	return 1636ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_generic_tracepoint_filter_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1636ULL: goto x86_l_664;
	case 1640ULL: goto x86_l_668;
	case 1647ULL: goto x86_l_66f;
	case 1652ULL: goto x86_l_674;
	case 1654ULL: goto x86_l_676;
	case 1657ULL: goto x86_l_679;
	case 1663ULL: goto x86_l_67f;
	case 1666ULL: goto x86_l_682;
	case 1668ULL: goto x86_l_684;
	case 1673ULL: goto x86_l_689;
	case 1679ULL: goto x86_l_68f;
	case 1682ULL: goto x86_l_692;
	case 1687ULL: goto x86_l_697;
	case 1690ULL: goto x86_l_69a;
	case 1695ULL: goto x86_l_69f;
	case 1700ULL: goto x86_l_6a4;
	case 1705ULL: goto x86_l_6a9;
	case 1710ULL: goto x86_l_6ae;
	case 1715ULL: goto x86_l_6b3;
	case 1721ULL: goto x86_l_6b9;
	case 1725ULL: goto x86_l_6bd;
	case 1732ULL: goto x86_l_6c4;
	case 1737ULL: goto x86_l_6c9;
	case 1742ULL: goto x86_l_6ce;
	case 1744ULL: goto x86_l_6d0;
	case 1747ULL: goto x86_l_6d3;
	case 1753ULL: goto x86_l_6d9;
	case 1756ULL: goto x86_l_6dc;
	case 1759ULL: goto x86_l_6df;
	case 1765ULL: goto x86_l_6e5;
	case 1768ULL: goto x86_l_6e8;
	case 1774ULL: goto x86_l_6ee;
	case 1779ULL: goto x86_l_6f3;
	case 1784ULL: goto x86_l_6f8;
	case 1789ULL: goto x86_l_6fd;
	case 1794ULL: goto x86_l_702;
	case 1799ULL: goto x86_l_707;
	case 1803ULL: goto x86_l_70b;
	case 1810ULL: goto x86_l_712;
	case 1815ULL: goto x86_l_717;
	case 1817ULL: goto x86_l_719;
	case 1820ULL: goto x86_l_71c;
	case 1826ULL: goto x86_l_722;
	case 1829ULL: goto x86_l_725;
	case 1832ULL: goto x86_l_728;
	case 1837ULL: goto x86_l_72d;
	case 1843ULL: goto x86_l_733;
	case 1847ULL: goto x86_l_737;
	case 1854ULL: goto x86_l_73e;
	case 1859ULL: goto x86_l_743;
	case 1861ULL: goto x86_l_745;
	case 1864ULL: goto x86_l_748;
	case 1870ULL: goto x86_l_74e;
	case 1873ULL: goto x86_l_751;
	case 1876ULL: goto x86_l_754;
	case 1881ULL: goto x86_l_759;
	case 1887ULL: goto x86_l_75f;
	case 1891ULL: goto x86_l_763;
	case 1898ULL: goto x86_l_76a;
	case 1903ULL: goto x86_l_76f;
	case 1905ULL: goto x86_l_771;
	case 1908ULL: goto x86_l_774;
	case 1914ULL: goto x86_l_77a;
	case 1917ULL: goto x86_l_77d;
	case 1920ULL: goto x86_l_780;
	case 1925ULL: goto x86_l_785;
	case 1931ULL: goto x86_l_78b;
	case 1935ULL: goto x86_l_78f;
	case 1942ULL: goto x86_l_796;
	case 1947ULL: goto x86_l_79b;
	case 1949ULL: goto x86_l_79d;
	case 1952ULL: goto x86_l_7a0;
	case 1958ULL: goto x86_l_7a6;
	case 1961ULL: goto x86_l_7a9;
	case 1964ULL: goto x86_l_7ac;
	case 1969ULL: goto x86_l_7b1;
	case 1971ULL: goto x86_l_7b3;
	case 1975ULL: goto x86_l_7b7;
	case 1982ULL: goto x86_l_7be;
	case 1987ULL: goto x86_l_7c3;
	case 1989ULL: goto x86_l_7c5;
	case 1992ULL: goto x86_l_7c8;
	case 1998ULL: goto x86_l_7ce;
	case 2001ULL: goto x86_l_7d1;
	case 2004ULL: goto x86_l_7d4;
	case 2009ULL: goto x86_l_7d9;
	case 2011ULL: goto x86_l_7db;
	case 2015ULL: goto x86_l_7df;
	case 2022ULL: goto x86_l_7e6;
	case 2027ULL: goto x86_l_7eb;
	case 2029ULL: goto x86_l_7ed;
	case 2032ULL: goto x86_l_7f0;
	case 2038ULL: goto x86_l_7f6;
	case 2041ULL: goto x86_l_7f9;
	case 2044ULL: goto x86_l_7fc;
	case 2049ULL: goto x86_l_801;
	case 2051ULL: goto x86_l_803;
	case 2055ULL: goto x86_l_807;
	case 2062ULL: goto x86_l_80e;
	case 2067ULL: goto x86_l_813;
	case 2069ULL: goto x86_l_815;
	case 2072ULL: goto x86_l_818;
	case 2078ULL: goto x86_l_81e;
	case 2081ULL: goto x86_l_821;
	case 2084ULL: goto x86_l_824;
	case 2089ULL: goto x86_l_829;
	case 2091ULL: goto x86_l_82b;
	case 2094ULL: goto x86_l_82e;
	case 2099ULL: goto x86_l_833;
	case 2104ULL: goto x86_l_838;
	case 2109ULL: goto x86_l_83d;
	case 2114ULL: goto x86_l_842;
	case 2119ULL: goto x86_l_847;
	case 2124ULL: goto x86_l_84c;
	case 2127ULL: goto x86_l_84f;
	case 2132ULL: goto x86_l_854;
	case 2135ULL: goto x86_l_857;
	case 2138ULL: goto x86_l_85a;
	case 2143ULL: goto x86_l_85f;
	case 2147ULL: goto x86_l_863;
	case 2150ULL: goto x86_l_866;
	case 2155ULL: goto x86_l_86b;
	case 2158ULL: goto x86_l_86e;
	case 2161ULL: goto x86_l_871;
	case 2166ULL: goto x86_l_876;
	case 2169ULL: goto x86_l_879;
	case 2173ULL: goto x86_l_87d;
	case 2176ULL: goto x86_l_880;
	case 2181ULL: goto x86_l_885;
	case 2184ULL: goto x86_l_888;
	case 2189ULL: goto x86_l_88d;
	case 2195ULL: goto x86_l_893;
	case 2200ULL: goto x86_l_898;
	case 2204ULL: goto x86_l_89c;
	case 2211ULL: goto x86_l_8a3;
	case 2216ULL: goto x86_l_8a8;
	case 2218ULL: goto x86_l_8aa;
	case 2221ULL: goto x86_l_8ad;
	case 2223ULL: goto x86_l_8af;
	case 2226ULL: goto x86_l_8b2;
	case 2229ULL: goto x86_l_8b5;
	case 2234ULL: goto x86_l_8ba;
	case 2237ULL: goto x86_l_8bd;
	case 2242ULL: goto x86_l_8c2;
	case 2247ULL: goto x86_l_8c7;
	case 2252ULL: goto x86_l_8cc;
	case 2257ULL: goto x86_l_8d1;
	case 2262ULL: goto x86_l_8d6;
	case 2264ULL: goto x86_l_8d8;
	case 2268ULL: goto x86_l_8dc;
	case 2275ULL: goto x86_l_8e3;
	case 2280ULL: goto x86_l_8e8;
	case 2287ULL: goto x86_l_8ef;
	case 2289ULL: goto x86_l_8f1;
	case 2292ULL: goto x86_l_8f4;
	case 2297ULL: goto x86_l_8f9;
	case 2301ULL: goto x86_l_8fd;
	case 2304ULL: goto x86_l_900;
	case 2309ULL: goto x86_l_905;
	case 2314ULL: goto x86_l_90a;
	case 2319ULL: goto x86_l_90f;
	case 2324ULL: goto x86_l_914;
	case 2326ULL: goto x86_l_916;
	case 2330ULL: goto x86_l_91a;
	case 2333ULL: goto x86_l_91d;
	case 2337ULL: goto x86_l_921;
	case 2340ULL: goto x86_l_924;
	case 2344ULL: goto x86_l_928;
	case 2347ULL: goto x86_l_92b;
	case 2351ULL: goto x86_l_92f;
	case 2357ULL: goto x86_l_935;
	case 2360ULL: goto x86_l_938;
	case 2364ULL: goto x86_l_93c;
	case 2370ULL: goto x86_l_942;
	case 2372ULL: goto x86_l_944;
	case 2375ULL: goto x86_l_947;
	case 2380ULL: goto x86_l_94c;
	case 2382ULL: goto x86_l_94e;
	case 2385ULL: goto x86_l_951;
	case 2387ULL: goto x86_l_953;
	case 2390ULL: goto x86_l_956;
	case 2393ULL: goto x86_l_959;
	case 2398ULL: goto x86_l_95e;
	case 2401ULL: goto x86_l_961;
	case 2405ULL: goto x86_l_965;
	case 2407ULL: goto x86_l_967;
	case 2409ULL: goto x86_l_969;
	case 2413ULL: goto x86_l_96d;
	case 2418ULL: goto x86_l_972;
	case 2420ULL: goto x86_l_974;
	case 2423ULL: goto x86_l_977;
	case 2429ULL: goto x86_l_97d;
	case 2432ULL: goto x86_l_980;
	case 2435ULL: goto x86_l_983;
	case 2439ULL: goto x86_l_987;
	case 2443ULL: goto x86_l_98b;
	case 2448ULL: goto x86_l_990;
	case 2454ULL: goto x86_l_996;
	case 2460ULL: goto x86_l_99c;
	case 2462ULL: goto x86_l_99e;
	case 2465ULL: goto x86_l_9a1;
	case 2470ULL: goto x86_l_9a6;
	case 2476ULL: goto x86_l_9ac;
	case 2479ULL: goto x86_l_9af;
	case 2482ULL: goto x86_l_9b2;
	case 2488ULL: goto x86_l_9b8;
	case 2491ULL: goto x86_l_9bb;
	case 2497ULL: goto x86_l_9c1;
	case 2501ULL: goto x86_l_9c5;
	case 2506ULL: goto x86_l_9ca;
	case 2511ULL: goto x86_l_9cf;
	case 2516ULL: goto x86_l_9d4;
	case 2521ULL: goto x86_l_9d9;
	case 2525ULL: goto x86_l_9dd;
	case 2532ULL: goto x86_l_9e4;
	case 2537ULL: goto x86_l_9e9;
	case 2539ULL: goto x86_l_9eb;
	case 2542ULL: goto x86_l_9ee;
	case 2548ULL: goto x86_l_9f4;
	case 2551ULL: goto x86_l_9f7;
	case 2554ULL: goto x86_l_9fa;
	case 2559ULL: goto x86_l_9ff;
	case 2565ULL: goto x86_l_a05;
	case 2569ULL: goto x86_l_a09;
	case 2576ULL: goto x86_l_a10;
	case 2581ULL: goto x86_l_a15;
	case 2583ULL: goto x86_l_a17;
	case 2586ULL: goto x86_l_a1a;
	case 2592ULL: goto x86_l_a20;
	case 2595ULL: goto x86_l_a23;
	case 2598ULL: goto x86_l_a26;
	case 2603ULL: goto x86_l_a2b;
	case 2609ULL: goto x86_l_a31;
	case 2613ULL: goto x86_l_a35;
	case 2620ULL: goto x86_l_a3c;
	case 2625ULL: goto x86_l_a41;
	case 2627ULL: goto x86_l_a43;
	case 2630ULL: goto x86_l_a46;
	case 2636ULL: goto x86_l_a4c;
	case 2639ULL: goto x86_l_a4f;
	case 2642ULL: goto x86_l_a52;
	case 2647ULL: goto x86_l_a57;
	case 2653ULL: goto x86_l_a5d;
	case 2657ULL: goto x86_l_a61;
	case 2664ULL: goto x86_l_a68;
	case 2669ULL: goto x86_l_a6d;
	case 2671ULL: goto x86_l_a6f;
	case 2674ULL: goto x86_l_a72;
	case 2680ULL: goto x86_l_a78;
	case 2683ULL: goto x86_l_a7b;
	case 2686ULL: goto x86_l_a7e;
	case 2691ULL: goto x86_l_a83;
	case 2697ULL: goto x86_l_a89;
	case 2701ULL: goto x86_l_a8d;
	case 2708ULL: goto x86_l_a94;
	case 2713ULL: goto x86_l_a99;
	case 2715ULL: goto x86_l_a9b;
	case 2718ULL: goto x86_l_a9e;
	case 2724ULL: goto x86_l_aa4;
	case 2727ULL: goto x86_l_aa7;
	case 2730ULL: goto x86_l_aaa;
	case 2735ULL: goto x86_l_aaf;
	case 2741ULL: goto x86_l_ab5;
	case 2745ULL: goto x86_l_ab9;
	case 2752ULL: goto x86_l_ac0;
	case 2757ULL: goto x86_l_ac5;
	case 2759ULL: goto x86_l_ac7;
	case 2762ULL: goto x86_l_aca;
	case 2768ULL: goto x86_l_ad0;
	case 2771ULL: goto x86_l_ad3;
	case 2774ULL: goto x86_l_ad6;
	case 2779ULL: goto x86_l_adb;
	case 2785ULL: goto x86_l_ae1;
	case 2789ULL: goto x86_l_ae5;
	case 2796ULL: goto x86_l_aec;
	case 2801ULL: goto x86_l_af1;
	case 2803ULL: goto x86_l_af3;
	case 2806ULL: goto x86_l_af6;
	case 2812ULL: goto x86_l_afc;
	case 2815ULL: goto x86_l_aff;
	case 2818ULL: goto x86_l_b02;
	case 2823ULL: goto x86_l_b07;
	case 2829ULL: goto x86_l_b0d;
	case 2833ULL: goto x86_l_b11;
	case 2840ULL: goto x86_l_b18;
	case 2845ULL: goto x86_l_b1d;
	case 2847ULL: goto x86_l_b1f;
	case 2850ULL: goto x86_l_b22;
	case 2856ULL: goto x86_l_b28;
	case 2859ULL: goto x86_l_b2b;
	case 2862ULL: goto x86_l_b2e;
	case 2867ULL: goto x86_l_b33;
	case 2870ULL: goto x86_l_b36;
	case 2875ULL: goto x86_l_b3b;
	case 2880ULL: goto x86_l_b40;
	case 2885ULL: goto x86_l_b45;
	case 2890ULL: goto x86_l_b4a;
	case 2895ULL: goto x86_l_b4f;
	case 2899ULL: goto x86_l_b53;
	case 2905ULL: goto x86_l_b59;
	case 2909ULL: goto x86_l_b5d;
	case 2916ULL: goto x86_l_b64;
	case 2921ULL: goto x86_l_b69;
	case 2926ULL: goto x86_l_b6e;
	case 2929ULL: goto x86_l_b71;
	case 2934ULL: goto x86_l_b76;
	case 2936ULL: goto x86_l_b78;
	case 2939ULL: goto x86_l_b7b;
	case 2944ULL: goto x86_l_b80;
	case 2947ULL: goto x86_l_b83;
	case 2953ULL: goto x86_l_b89;
	case 2956ULL: goto x86_l_b8c;
	case 2959ULL: goto x86_l_b8f;
	case 2965ULL: goto x86_l_b95;
	case 2969ULL: goto x86_l_b99;
	case 2974ULL: goto x86_l_b9e;
	case 2979ULL: goto x86_l_ba3;
	case 2984ULL: goto x86_l_ba8;
	case 2989ULL: goto x86_l_bad;
	case 2993ULL: goto x86_l_bb1;
	case 3000ULL: goto x86_l_bb8;
	case 3005ULL: goto x86_l_bbd;
	case 3007ULL: goto x86_l_bbf;
	case 3010ULL: goto x86_l_bc2;
	case 3016ULL: goto x86_l_bc8;
	case 3019ULL: goto x86_l_bcb;
	case 3021ULL: goto x86_l_bcd;
	case 3026ULL: goto x86_l_bd2;
	case 3029ULL: goto x86_l_bd5;
	case 3035ULL: goto x86_l_bdb;
	case 3038ULL: goto x86_l_bde;
	case 3041ULL: goto x86_l_be1;
	case 3047ULL: goto x86_l_be7;
	case 3051ULL: goto x86_l_beb;
	case 3058ULL: goto x86_l_bf2;
	case 3063ULL: goto x86_l_bf7;
	case 3065ULL: goto x86_l_bf9;
	case 3068ULL: goto x86_l_bfc;
	case 3074ULL: goto x86_l_c02;
	case 3077ULL: goto x86_l_c05;
	case 3079ULL: goto x86_l_c07;
	case 3084ULL: goto x86_l_c0c;
	case 3087ULL: goto x86_l_c0f;
	case 3093ULL: goto x86_l_c15;
	case 3096ULL: goto x86_l_c18;
	case 3099ULL: goto x86_l_c1b;
	case 3105ULL: goto x86_l_c21;
	case 3109ULL: goto x86_l_c25;
	case 3116ULL: goto x86_l_c2c;
	case 3121ULL: goto x86_l_c31;
	case 3123ULL: goto x86_l_c33;
	case 3126ULL: goto x86_l_c36;
	case 3132ULL: goto x86_l_c3c;
	case 3135ULL: goto x86_l_c3f;
	case 3137ULL: goto x86_l_c41;
	case 3142ULL: goto x86_l_c46;
	case 3148ULL: goto x86_l_c4c;
	case 3151ULL: goto x86_l_c4f;
	case 3156ULL: goto x86_l_c54;
	case 3162ULL: goto x86_l_c5a;
	case 3166ULL: goto x86_l_c5e;
	case 3173ULL: goto x86_l_c65;
	case 3178ULL: goto x86_l_c6a;
	case 3180ULL: goto x86_l_c6c;
	case 3183ULL: goto x86_l_c6f;
	case 3189ULL: goto x86_l_c75;
	case 3192ULL: goto x86_l_c78;
	case 3194ULL: goto x86_l_c7a;
	case 3199ULL: goto x86_l_c7f;
	case 3205ULL: goto x86_l_c85;
	case 3208ULL: goto x86_l_c88;
	case 3213ULL: goto x86_l_c8d;
	case 3219ULL: goto x86_l_c93;
	case 3223ULL: goto x86_l_c97;
	case 3230ULL: goto x86_l_c9e;
	case 3235ULL: goto x86_l_ca3;
	case 3237ULL: goto x86_l_ca5;
	case 3240ULL: goto x86_l_ca8;
	case 3246ULL: goto x86_l_cae;
	case 3249ULL: goto x86_l_cb1;
	case 3251ULL: goto x86_l_cb3;
	case 3256ULL: goto x86_l_cb8;
	case 3262ULL: goto x86_l_cbe;
	case 3265ULL: goto x86_l_cc1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_664:
	/* 0x664: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_668:
	/* 0x668: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_66f:
	/* 0x66f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_674:
	/* 0x674: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_676:
	/* 0x676: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_679:
	/* 0x679: je     8f1 <generic_tracepoint_filter+0x8f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8f1;
	}
x86_l_67f:
	/* 0x67f: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_682:
	/* 0x682: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_684:
	/* 0x684: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_689:
	/* 0x689: je     82b <generic_tracepoint_filter+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_82b;
	}
x86_l_68f:
	/* 0x68f: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_692:
	/* 0x692: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_697:
	/* 0x697: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_69a:
	/* 0x69a: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_69f:
	/* 0x69f: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6a4:
	/* 0x6a4: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6a9:
	/* 0x6a9: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6ae:
	/* 0x6ae: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6b3:
	/* 0x6b3: je     916 <generic_tracepoint_filter+0x916> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_916;
	}
x86_l_6b9:
	/* 0x6b9: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6bd:
	/* 0x6bd: mov    rcx,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_6c4:
	/* 0x6c4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6c9:
	/* 0x6c9: jmp    8e8 <generic_tracepoint_filter+0x8e8> */
	goto x86_l_8e8;
x86_l_6ce:
	/* 0x6ce: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6d0:
	/* 0x6d0: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_6d3:
	/* 0x6d3: je     84c <generic_tracepoint_filter+0x84c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_84c;
	}
x86_l_6d9:
	/* 0x6d9: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_6dc:
	/* 0x6dc: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_6df:
	/* 0x6df: je     916 <generic_tracepoint_filter+0x916> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_916;
	}
x86_l_6e5:
	/* 0x6e5: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_6e8:
	/* 0x6e8: je     916 <generic_tracepoint_filter+0x916> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_916;
	}
x86_l_6ee:
	/* 0x6ee: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6f3:
	/* 0x6f3: mov    QWORD PTR [rsp+0x30],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6f8:
	/* 0x6f8: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6fd:
	/* 0x6fd: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_702:
	/* 0x702: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_707:
	/* 0x707: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_70b:
	/* 0x70b: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_712:
	/* 0x712: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_717:
	/* 0x717: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_719:
	/* 0x719: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_71c:
	/* 0x71c: je     8f1 <generic_tracepoint_filter+0x8f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8f1;
	}
x86_l_722:
	/* 0x722: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_725:
	/* 0x725: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_728:
	/* 0x728: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_72d:
	/* 0x72d: je     82b <generic_tracepoint_filter+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_82b;
	}
x86_l_733:
	/* 0x733: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_737:
	/* 0x737: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_73e:
	/* 0x73e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_743:
	/* 0x743: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_745:
	/* 0x745: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_748:
	/* 0x748: je     8f1 <generic_tracepoint_filter+0x8f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8f1;
	}
x86_l_74e:
	/* 0x74e: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_751:
	/* 0x751: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_754:
	/* 0x754: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_759:
	/* 0x759: je     82b <generic_tracepoint_filter+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_82b;
	}
x86_l_75f:
	/* 0x75f: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_763:
	/* 0x763: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_76a:
	/* 0x76a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_76f:
	/* 0x76f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_771:
	/* 0x771: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_774:
	/* 0x774: je     8f1 <generic_tracepoint_filter+0x8f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8f1;
	}
x86_l_77a:
	/* 0x77a: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_77d:
	/* 0x77d: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_780:
	/* 0x780: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_785:
	/* 0x785: je     82b <generic_tracepoint_filter+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_82b;
	}
x86_l_78b:
	/* 0x78b: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_78f:
	/* 0x78f: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_796:
	/* 0x796: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_79b:
	/* 0x79b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_79d:
	/* 0x79d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7a0:
	/* 0x7a0: je     8f1 <generic_tracepoint_filter+0x8f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8f1;
	}
x86_l_7a6:
	/* 0x7a6: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_7a9:
	/* 0x7a9: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_7ac:
	/* 0x7ac: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7b1:
	/* 0x7b1: je     82b <generic_tracepoint_filter+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_82b;
	}
x86_l_7b3:
	/* 0x7b3: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_7b7:
	/* 0x7b7: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_7be:
	/* 0x7be: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7c3:
	/* 0x7c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c5:
	/* 0x7c5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7c8:
	/* 0x7c8: je     8f1 <generic_tracepoint_filter+0x8f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8f1;
	}
x86_l_7ce:
	/* 0x7ce: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_7d1:
	/* 0x7d1: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_7d4:
	/* 0x7d4: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7d9:
	/* 0x7d9: je     82b <generic_tracepoint_filter+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_82b;
	}
x86_l_7db:
	/* 0x7db: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_7df:
	/* 0x7df: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_7e6:
	/* 0x7e6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7eb:
	/* 0x7eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ed:
	/* 0x7ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7f0:
	/* 0x7f0: je     8f1 <generic_tracepoint_filter+0x8f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8f1;
	}
x86_l_7f6:
	/* 0x7f6: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_7f9:
	/* 0x7f9: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_7fc:
	/* 0x7fc: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_801:
	/* 0x801: je     82b <generic_tracepoint_filter+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_82b;
	}
x86_l_803:
	/* 0x803: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_807:
	/* 0x807: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_80e:
	/* 0x80e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_813:
	/* 0x813: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_815:
	/* 0x815: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_818:
	/* 0x818: je     8f1 <generic_tracepoint_filter+0x8f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8f1;
	}
x86_l_81e:
	/* 0x81e: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_821:
	/* 0x821: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_824:
	/* 0x824: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_829:
	/* 0x829: jne    898 <generic_tracepoint_filter+0x898> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_898;
	}
x86_l_82b:
	/* 0x82b: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_82e:
	/* 0x82e: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_833:
	/* 0x833: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_838:
	/* 0x838: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_83d:
	/* 0x83d: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_842:
	/* 0x842: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_847:
	/* 0x847: jmp    916 <generic_tracepoint_filter+0x916> */
	goto x86_l_916;
x86_l_84c:
	/* 0x84c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_84f:
	/* 0x84f: jmp    924 <generic_tracepoint_filter+0x924> */
	goto x86_l_924;
x86_l_854:
	/* 0x854: mov    edx,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R10, X86_WIDTH_32);
x86_l_857:
	/* 0x857: and    edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_85a:
	/* 0x85a: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_85f:
	/* 0x85f: mov    DWORD PTR [rsp+0x50],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_863:
	/* 0x863: mov    ebp,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_32);
x86_l_866:
	/* 0x866: jmp    e08 <generic_tracepoint_filter+0xe08> */
	return 3592ULL;
x86_l_86b:
	/* 0x86b: mov    edx,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R10, X86_WIDTH_32);
x86_l_86e:
	/* 0x86e: and    edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_871:
	/* 0x871: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_876:
	/* 0x876: mov    r12d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_32);
x86_l_879:
	/* 0x879: mov    DWORD PTR [rsp+0x50],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_87d:
	/* 0x87d: mov    ebp,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_32);
x86_l_880:
	/* 0x880: jmp    12e1 <generic_tracepoint_filter+0x12e1> */
	return 4833ULL;
x86_l_885:
	/* 0x885: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_888:
	/* 0x888: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_88d:
	/* 0x88d: jne    392 <generic_tracepoint_filter+0x392> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 914ULL;
	}
x86_l_893:
	/* 0x893: jmp    201b <generic_tracepoint_filter+0x201b> */
	return 8219ULL;
x86_l_898:
	/* 0x898: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_89c:
	/* 0x89c: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_8a3:
	/* 0x8a3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8a8:
	/* 0x8a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8aa:
	/* 0x8aa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8ad:
	/* 0x8ad: je     8f1 <generic_tracepoint_filter+0x8f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8f1;
	}
x86_l_8af:
	/* 0x8af: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_8b2:
	/* 0x8b2: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_8b5:
	/* 0x8b5: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8ba:
	/* 0x8ba: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_8bd:
	/* 0x8bd: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8c2:
	/* 0x8c2: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8c7:
	/* 0x8c7: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8cc:
	/* 0x8cc: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8d1:
	/* 0x8d1: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8d6:
	/* 0x8d6: je     916 <generic_tracepoint_filter+0x916> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_916;
	}
x86_l_8d8:
	/* 0x8d8: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_8dc:
	/* 0x8dc: mov    rcx,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_8e3:
	/* 0x8e3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8e8:
	/* 0x8e8: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_8ef:
	/* 0x8ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f1:
	/* 0x8f1: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8f4:
	/* 0x8f4: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8f9:
	/* 0x8f9: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_8fd:
	/* 0x8fd: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_900:
	/* 0x900: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_905:
	/* 0x905: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_90a:
	/* 0x90a: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_90f:
	/* 0x90f: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_914:
	/* 0x914: je     924 <generic_tracepoint_filter+0x924> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_924;
	}
x86_l_916:
	/* 0x916: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_91a:
	/* 0x91a: setne  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_NE);
x86_l_91d:
	/* 0x91d: xor    r12b,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_921:
	/* 0x921: or     r12b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_924:
	/* 0x924: movzx  edi,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_928:
	/* 0x928: add    ebp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_92b:
	/* 0x92b: lea    rdx,[rcx+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_92f:
	/* 0x92f: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_935:
	/* 0x935: mov    rsi,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_938:
	/* 0x938: cmove  rsi,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_93c:
	/* 0x93c: cmp    ebp,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1000ULL);
x86_l_942:
	/* 0x942: jbe    94e <generic_tracepoint_filter+0x94e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_94e;
	}
x86_l_944:
	/* 0x944: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_947:
	/* 0x947: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_94c:
	/* 0x94c: jmp    961 <generic_tracepoint_filter+0x961> */
	goto x86_l_961;
x86_l_94e:
	/* 0x94e: mov    r12d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_32);
x86_l_951:
	/* 0x951: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_953:
	/* 0x953: and    edi,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_956:
	/* 0x956: mov    edi,DWORD PTR [rax+rdi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_959:
	/* 0x959: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_95e:
	/* 0x95e: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_961:
	/* 0x961: test   r10b,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R10, X86_WIDTH_8, 2ULL);
x86_l_965:
	/* 0x965: jne    990 <generic_tracepoint_filter+0x990> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_990;
	}
x86_l_967:
	/* 0x967: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_969:
	/* 0x969: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_96d:
	/* 0x96d: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_972:
	/* 0x972: jne    97d <generic_tracepoint_filter+0x97d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_97d;
	}
x86_l_974:
	/* 0x974: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_977:
	/* 0x977: jne    b6e <generic_tracepoint_filter+0xb6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b6e;
	}
x86_l_97d:
	/* 0x97d: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_980:
	/* 0x980: setne  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_NE);
x86_l_983:
	/* 0x983: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_987:
	/* 0x987: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_98b:
	/* 0x98b: jmp    dfa <generic_tracepoint_filter+0xdfa> */
	return 3578ULL;
x86_l_990:
	/* 0x990: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_996:
	/* 0x996: je     b76 <generic_tracepoint_filter+0xb76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b76;
	}
x86_l_99c:
	/* 0x99c: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_99e:
	/* 0x99e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_9a1:
	/* 0x9a1: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9a6:
	/* 0x9a6: je     b6e <generic_tracepoint_filter+0xb6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b6e;
	}
x86_l_9ac:
	/* 0x9ac: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_9af:
	/* 0x9af: test   rsi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_64);
x86_l_9b2:
	/* 0x9b2: je     def <generic_tracepoint_filter+0xdef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3567ULL;
	}
x86_l_9b8:
	/* 0x9b8: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_9bb:
	/* 0x9bb: je     def <generic_tracepoint_filter+0xdef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3567ULL;
	}
x86_l_9c1:
	/* 0x9c1: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_9c5:
	/* 0x9c5: mov    QWORD PTR [rsp+0x30],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9ca:
	/* 0x9ca: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9cf:
	/* 0x9cf: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9d4:
	/* 0x9d4: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9d9:
	/* 0x9d9: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9dd:
	/* 0x9dd: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_9e4:
	/* 0x9e4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9e9:
	/* 0x9e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9eb:
	/* 0x9eb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9ee:
	/* 0x9ee: je     da4 <generic_tracepoint_filter+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3492ULL;
	}
x86_l_9f4:
	/* 0x9f4: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_9f7:
	/* 0x9f7: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_9fa:
	/* 0x9fa: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9ff:
	/* 0x9ff: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3535ULL;
	}
x86_l_a05:
	/* 0xa05: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_a09:
	/* 0xa09: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_a10:
	/* 0xa10: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a15:
	/* 0xa15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a17:
	/* 0xa17: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a1a:
	/* 0xa1a: je     da4 <generic_tracepoint_filter+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3492ULL;
	}
x86_l_a20:
	/* 0xa20: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_a23:
	/* 0xa23: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_a26:
	/* 0xa26: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a2b:
	/* 0xa2b: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3535ULL;
	}
x86_l_a31:
	/* 0xa31: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_a35:
	/* 0xa35: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_a3c:
	/* 0xa3c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a41:
	/* 0xa41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a43:
	/* 0xa43: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a46:
	/* 0xa46: je     da4 <generic_tracepoint_filter+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3492ULL;
	}
x86_l_a4c:
	/* 0xa4c: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_a4f:
	/* 0xa4f: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_a52:
	/* 0xa52: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a57:
	/* 0xa57: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3535ULL;
	}
x86_l_a5d:
	/* 0xa5d: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_a61:
	/* 0xa61: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_a68:
	/* 0xa68: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a6d:
	/* 0xa6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a6f:
	/* 0xa6f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a72:
	/* 0xa72: je     da4 <generic_tracepoint_filter+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3492ULL;
	}
x86_l_a78:
	/* 0xa78: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_a7b:
	/* 0xa7b: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_a7e:
	/* 0xa7e: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a83:
	/* 0xa83: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3535ULL;
	}
x86_l_a89:
	/* 0xa89: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_a8d:
	/* 0xa8d: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_a94:
	/* 0xa94: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a99:
	/* 0xa99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a9b:
	/* 0xa9b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a9e:
	/* 0xa9e: je     da4 <generic_tracepoint_filter+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3492ULL;
	}
x86_l_aa4:
	/* 0xaa4: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_aa7:
	/* 0xaa7: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_aaa:
	/* 0xaaa: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_aaf:
	/* 0xaaf: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3535ULL;
	}
x86_l_ab5:
	/* 0xab5: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ab9:
	/* 0xab9: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_ac0:
	/* 0xac0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ac5:
	/* 0xac5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac7:
	/* 0xac7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aca:
	/* 0xaca: je     da4 <generic_tracepoint_filter+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3492ULL;
	}
x86_l_ad0:
	/* 0xad0: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_ad3:
	/* 0xad3: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_ad6:
	/* 0xad6: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_adb:
	/* 0xadb: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3535ULL;
	}
x86_l_ae1:
	/* 0xae1: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ae5:
	/* 0xae5: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_aec:
	/* 0xaec: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_af1:
	/* 0xaf1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af3:
	/* 0xaf3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_af6:
	/* 0xaf6: je     da4 <generic_tracepoint_filter+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3492ULL;
	}
x86_l_afc:
	/* 0xafc: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_aff:
	/* 0xaff: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_b02:
	/* 0xb02: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b07:
	/* 0xb07: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3535ULL;
	}
x86_l_b0d:
	/* 0xb0d: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_b11:
	/* 0xb11: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_b18:
	/* 0xb18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b1d:
	/* 0xb1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b1f:
	/* 0xb1f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b22:
	/* 0xb22: je     da4 <generic_tracepoint_filter+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3492ULL;
	}
x86_l_b28:
	/* 0xb28: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_b2b:
	/* 0xb2b: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_b2e:
	/* 0xb2e: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b33:
	/* 0xb33: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_b36:
	/* 0xb36: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b3b:
	/* 0xb3b: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b40:
	/* 0xb40: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b45:
	/* 0xb45: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b4a:
	/* 0xb4a: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b4f:
	/* 0xb4f: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_b53:
	/* 0xb53: je     def <generic_tracepoint_filter+0xdef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3567ULL;
	}
x86_l_b59:
	/* 0xb59: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_b5d:
	/* 0xb5d: mov    rcx,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_b64:
	/* 0xb64: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b69:
	/* 0xb69: jmp    d9b <generic_tracepoint_filter+0xd9b> */
	return 3483ULL;
x86_l_b6e:
	/* 0xb6e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b71:
	/* 0xb71: jmp    dfd <generic_tracepoint_filter+0xdfd> */
	return 3581ULL;
x86_l_b76:
	/* 0xb76: mov    edx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b78:
	/* 0xb78: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_b7b:
	/* 0xb7b: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b80:
	/* 0xb80: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_b83:
	/* 0xb83: je     def <generic_tracepoint_filter+0xdef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3567ULL;
	}
x86_l_b89:
	/* 0xb89: mov    edx,DWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b8c:
	/* 0xb8c: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_b8f:
	/* 0xb8f: je     def <generic_tracepoint_filter+0xdef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3567ULL;
	}
x86_l_b95:
	/* 0xb95: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_b99:
	/* 0xb99: mov    QWORD PTR [rsp+0x30],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b9e:
	/* 0xb9e: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ba3:
	/* 0xba3: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ba8:
	/* 0xba8: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bad:
	/* 0xbad: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bb1:
	/* 0xbb1: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_bb8:
	/* 0xbb8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bbd:
	/* 0xbbd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bbf:
	/* 0xbbf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bc2:
	/* 0xbc2: je     da4 <generic_tracepoint_filter+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3492ULL;
	}
x86_l_bc8:
	/* 0xbc8: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_bcb:
	/* 0xbcb: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bcd:
	/* 0xbcd: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_bd2:
	/* 0xbd2: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_bd5:
	/* 0xbd5: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3535ULL;
	}
x86_l_bdb:
	/* 0xbdb: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bde:
	/* 0xbde: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_be1:
	/* 0xbe1: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3535ULL;
	}
x86_l_be7:
	/* 0xbe7: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_beb:
	/* 0xbeb: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_bf2:
	/* 0xbf2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bf7:
	/* 0xbf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf9:
	/* 0xbf9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bfc:
	/* 0xbfc: je     da4 <generic_tracepoint_filter+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3492ULL;
	}
x86_l_c02:
	/* 0xc02: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_c05:
	/* 0xc05: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c07:
	/* 0xc07: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c0c:
	/* 0xc0c: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_c0f:
	/* 0xc0f: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3535ULL;
	}
x86_l_c15:
	/* 0xc15: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c18:
	/* 0xc18: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_c1b:
	/* 0xc1b: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3535ULL;
	}
x86_l_c21:
	/* 0xc21: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_c25:
	/* 0xc25: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_c2c:
	/* 0xc2c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c31:
	/* 0xc31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c33:
	/* 0xc33: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c36:
	/* 0xc36: je     da4 <generic_tracepoint_filter+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3492ULL;
	}
x86_l_c3c:
	/* 0xc3c: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_c3f:
	/* 0xc3f: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c41:
	/* 0xc41: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c46:
	/* 0xc46: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3535ULL;
	}
x86_l_c4c:
	/* 0xc4c: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c4f:
	/* 0xc4f: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c54:
	/* 0xc54: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3535ULL;
	}
x86_l_c5a:
	/* 0xc5a: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_c5e:
	/* 0xc5e: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_c65:
	/* 0xc65: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c6a:
	/* 0xc6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c6c:
	/* 0xc6c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c6f:
	/* 0xc6f: je     da4 <generic_tracepoint_filter+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3492ULL;
	}
x86_l_c75:
	/* 0xc75: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_c78:
	/* 0xc78: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c7a:
	/* 0xc7a: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c7f:
	/* 0xc7f: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3535ULL;
	}
x86_l_c85:
	/* 0xc85: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c88:
	/* 0xc88: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c8d:
	/* 0xc8d: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3535ULL;
	}
x86_l_c93:
	/* 0xc93: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_c97:
	/* 0xc97: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_c9e:
	/* 0xc9e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ca3:
	/* 0xca3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ca5:
	/* 0xca5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ca8:
	/* 0xca8: je     da4 <generic_tracepoint_filter+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3492ULL;
	}
x86_l_cae:
	/* 0xcae: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_cb1:
	/* 0xcb1: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cb3:
	/* 0xcb3: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cb8:
	/* 0xcb8: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3535ULL;
	}
x86_l_cbe:
	/* 0xcbe: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cc1:
	/* 0xcc1: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
	return 3270ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_generic_tracepoint_filter_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3270ULL: goto x86_l_cc6;
	case 3276ULL: goto x86_l_ccc;
	case 3280ULL: goto x86_l_cd0;
	case 3287ULL: goto x86_l_cd7;
	case 3292ULL: goto x86_l_cdc;
	case 3294ULL: goto x86_l_cde;
	case 3297ULL: goto x86_l_ce1;
	case 3303ULL: goto x86_l_ce7;
	case 3306ULL: goto x86_l_cea;
	case 3308ULL: goto x86_l_cec;
	case 3313ULL: goto x86_l_cf1;
	case 3319ULL: goto x86_l_cf7;
	case 3322ULL: goto x86_l_cfa;
	case 3327ULL: goto x86_l_cff;
	case 3333ULL: goto x86_l_d05;
	case 3337ULL: goto x86_l_d09;
	case 3344ULL: goto x86_l_d10;
	case 3349ULL: goto x86_l_d15;
	case 3351ULL: goto x86_l_d17;
	case 3354ULL: goto x86_l_d1a;
	case 3360ULL: goto x86_l_d20;
	case 3363ULL: goto x86_l_d23;
	case 3365ULL: goto x86_l_d25;
	case 3370ULL: goto x86_l_d2a;
	case 3376ULL: goto x86_l_d30;
	case 3379ULL: goto x86_l_d33;
	case 3384ULL: goto x86_l_d38;
	case 3390ULL: goto x86_l_d3e;
	case 3394ULL: goto x86_l_d42;
	case 3401ULL: goto x86_l_d49;
	case 3406ULL: goto x86_l_d4e;
	case 3408ULL: goto x86_l_d50;
	case 3411ULL: goto x86_l_d53;
	case 3413ULL: goto x86_l_d55;
	case 3416ULL: goto x86_l_d58;
	case 3418ULL: goto x86_l_d5a;
	case 3423ULL: goto x86_l_d5f;
	case 3425ULL: goto x86_l_d61;
	case 3428ULL: goto x86_l_d64;
	case 3433ULL: goto x86_l_d69;
	case 3436ULL: goto x86_l_d6c;
	case 3441ULL: goto x86_l_d71;
	case 3446ULL: goto x86_l_d76;
	case 3451ULL: goto x86_l_d7b;
	case 3456ULL: goto x86_l_d80;
	case 3461ULL: goto x86_l_d85;
	case 3465ULL: goto x86_l_d89;
	case 3467ULL: goto x86_l_d8b;
	case 3471ULL: goto x86_l_d8f;
	case 3478ULL: goto x86_l_d96;
	case 3483ULL: goto x86_l_d9b;
	case 3490ULL: goto x86_l_da2;
	case 3492ULL: goto x86_l_da4;
	case 3495ULL: goto x86_l_da7;
	case 3500ULL: goto x86_l_dac;
	case 3504ULL: goto x86_l_db0;
	case 3507ULL: goto x86_l_db3;
	case 3512ULL: goto x86_l_db8;
	case 3517ULL: goto x86_l_dbd;
	case 3522ULL: goto x86_l_dc2;
	case 3527ULL: goto x86_l_dc7;
	case 3531ULL: goto x86_l_dcb;
	case 3533ULL: goto x86_l_dcd;
	case 3535ULL: goto x86_l_dcf;
	case 3538ULL: goto x86_l_dd2;
	case 3543ULL: goto x86_l_dd7;
	case 3548ULL: goto x86_l_ddc;
	case 3553ULL: goto x86_l_de1;
	case 3558ULL: goto x86_l_de6;
	case 3563ULL: goto x86_l_deb;
	case 3567ULL: goto x86_l_def;
	case 3571ULL: goto x86_l_df3;
	case 3574ULL: goto x86_l_df6;
	case 3578ULL: goto x86_l_dfa;
	case 3581ULL: goto x86_l_dfd;
	case 3585ULL: goto x86_l_e01;
	case 3589ULL: goto x86_l_e05;
	case 3592ULL: goto x86_l_e08;
	case 3596ULL: goto x86_l_e0c;
	case 3602ULL: goto x86_l_e12;
	case 3605ULL: goto x86_l_e15;
	case 3609ULL: goto x86_l_e19;
	case 3615ULL: goto x86_l_e1f;
	case 3617ULL: goto x86_l_e21;
	case 3620ULL: goto x86_l_e24;
	case 3625ULL: goto x86_l_e29;
	case 3627ULL: goto x86_l_e2b;
	case 3630ULL: goto x86_l_e2e;
	case 3632ULL: goto x86_l_e30;
	case 3635ULL: goto x86_l_e33;
	case 3638ULL: goto x86_l_e36;
	case 3643ULL: goto x86_l_e3b;
	case 3646ULL: goto x86_l_e3e;
	case 3650ULL: goto x86_l_e42;
	case 3652ULL: goto x86_l_e44;
	case 3654ULL: goto x86_l_e46;
	case 3658ULL: goto x86_l_e4a;
	case 3663ULL: goto x86_l_e4f;
	case 3665ULL: goto x86_l_e51;
	case 3668ULL: goto x86_l_e54;
	case 3674ULL: goto x86_l_e5a;
	case 3677ULL: goto x86_l_e5d;
	case 3680ULL: goto x86_l_e60;
	case 3684ULL: goto x86_l_e64;
	case 3688ULL: goto x86_l_e68;
	case 3693ULL: goto x86_l_e6d;
	case 3699ULL: goto x86_l_e73;
	case 3705ULL: goto x86_l_e79;
	case 3707ULL: goto x86_l_e7b;
	case 3710ULL: goto x86_l_e7e;
	case 3715ULL: goto x86_l_e83;
	case 3721ULL: goto x86_l_e89;
	case 3724ULL: goto x86_l_e8c;
	case 3727ULL: goto x86_l_e8f;
	case 3733ULL: goto x86_l_e95;
	case 3736ULL: goto x86_l_e98;
	case 3742ULL: goto x86_l_e9e;
	case 3746ULL: goto x86_l_ea2;
	case 3751ULL: goto x86_l_ea7;
	case 3756ULL: goto x86_l_eac;
	case 3761ULL: goto x86_l_eb1;
	case 3766ULL: goto x86_l_eb6;
	case 3770ULL: goto x86_l_eba;
	case 3777ULL: goto x86_l_ec1;
	case 3782ULL: goto x86_l_ec6;
	case 3784ULL: goto x86_l_ec8;
	case 3787ULL: goto x86_l_ecb;
	case 3793ULL: goto x86_l_ed1;
	case 3796ULL: goto x86_l_ed4;
	case 3799ULL: goto x86_l_ed7;
	case 3804ULL: goto x86_l_edc;
	case 3810ULL: goto x86_l_ee2;
	case 3814ULL: goto x86_l_ee6;
	case 3821ULL: goto x86_l_eed;
	case 3826ULL: goto x86_l_ef2;
	case 3828ULL: goto x86_l_ef4;
	case 3831ULL: goto x86_l_ef7;
	case 3837ULL: goto x86_l_efd;
	case 3840ULL: goto x86_l_f00;
	case 3843ULL: goto x86_l_f03;
	case 3848ULL: goto x86_l_f08;
	case 3854ULL: goto x86_l_f0e;
	case 3858ULL: goto x86_l_f12;
	case 3865ULL: goto x86_l_f19;
	case 3870ULL: goto x86_l_f1e;
	case 3872ULL: goto x86_l_f20;
	case 3875ULL: goto x86_l_f23;
	case 3881ULL: goto x86_l_f29;
	case 3884ULL: goto x86_l_f2c;
	case 3887ULL: goto x86_l_f2f;
	case 3892ULL: goto x86_l_f34;
	case 3898ULL: goto x86_l_f3a;
	case 3902ULL: goto x86_l_f3e;
	case 3909ULL: goto x86_l_f45;
	case 3914ULL: goto x86_l_f4a;
	case 3916ULL: goto x86_l_f4c;
	case 3919ULL: goto x86_l_f4f;
	case 3925ULL: goto x86_l_f55;
	case 3928ULL: goto x86_l_f58;
	case 3931ULL: goto x86_l_f5b;
	case 3936ULL: goto x86_l_f60;
	case 3942ULL: goto x86_l_f66;
	case 3946ULL: goto x86_l_f6a;
	case 3953ULL: goto x86_l_f71;
	case 3958ULL: goto x86_l_f76;
	case 3960ULL: goto x86_l_f78;
	case 3963ULL: goto x86_l_f7b;
	case 3969ULL: goto x86_l_f81;
	case 3972ULL: goto x86_l_f84;
	case 3975ULL: goto x86_l_f87;
	case 3980ULL: goto x86_l_f8c;
	case 3986ULL: goto x86_l_f92;
	case 3990ULL: goto x86_l_f96;
	case 3997ULL: goto x86_l_f9d;
	case 4002ULL: goto x86_l_fa2;
	case 4004ULL: goto x86_l_fa4;
	case 4007ULL: goto x86_l_fa7;
	case 4013ULL: goto x86_l_fad;
	case 4016ULL: goto x86_l_fb0;
	case 4019ULL: goto x86_l_fb3;
	case 4024ULL: goto x86_l_fb8;
	case 4030ULL: goto x86_l_fbe;
	case 4034ULL: goto x86_l_fc2;
	case 4041ULL: goto x86_l_fc9;
	case 4046ULL: goto x86_l_fce;
	case 4048ULL: goto x86_l_fd0;
	case 4051ULL: goto x86_l_fd3;
	case 4057ULL: goto x86_l_fd9;
	case 4060ULL: goto x86_l_fdc;
	case 4063ULL: goto x86_l_fdf;
	case 4068ULL: goto x86_l_fe4;
	case 4074ULL: goto x86_l_fea;
	case 4078ULL: goto x86_l_fee;
	case 4085ULL: goto x86_l_ff5;
	case 4090ULL: goto x86_l_ffa;
	case 4092ULL: goto x86_l_ffc;
	case 4095ULL: goto x86_l_fff;
	case 4101ULL: goto x86_l_1005;
	case 4104ULL: goto x86_l_1008;
	case 4107ULL: goto x86_l_100b;
	case 4112ULL: goto x86_l_1010;
	case 4115ULL: goto x86_l_1013;
	case 4120ULL: goto x86_l_1018;
	case 4125ULL: goto x86_l_101d;
	case 4130ULL: goto x86_l_1022;
	case 4135ULL: goto x86_l_1027;
	case 4140ULL: goto x86_l_102c;
	case 4144ULL: goto x86_l_1030;
	case 4150ULL: goto x86_l_1036;
	case 4154ULL: goto x86_l_103a;
	case 4161ULL: goto x86_l_1041;
	case 4166ULL: goto x86_l_1046;
	case 4171ULL: goto x86_l_104b;
	case 4174ULL: goto x86_l_104e;
	case 4179ULL: goto x86_l_1053;
	case 4181ULL: goto x86_l_1055;
	case 4184ULL: goto x86_l_1058;
	case 4189ULL: goto x86_l_105d;
	case 4192ULL: goto x86_l_1060;
	case 4198ULL: goto x86_l_1066;
	case 4201ULL: goto x86_l_1069;
	case 4204ULL: goto x86_l_106c;
	case 4210ULL: goto x86_l_1072;
	case 4214ULL: goto x86_l_1076;
	case 4219ULL: goto x86_l_107b;
	case 4224ULL: goto x86_l_1080;
	case 4229ULL: goto x86_l_1085;
	case 4234ULL: goto x86_l_108a;
	case 4238ULL: goto x86_l_108e;
	case 4245ULL: goto x86_l_1095;
	case 4250ULL: goto x86_l_109a;
	case 4252ULL: goto x86_l_109c;
	case 4255ULL: goto x86_l_109f;
	case 4261ULL: goto x86_l_10a5;
	case 4264ULL: goto x86_l_10a8;
	case 4266ULL: goto x86_l_10aa;
	case 4271ULL: goto x86_l_10af;
	case 4274ULL: goto x86_l_10b2;
	case 4280ULL: goto x86_l_10b8;
	case 4283ULL: goto x86_l_10bb;
	case 4286ULL: goto x86_l_10be;
	case 4292ULL: goto x86_l_10c4;
	case 4296ULL: goto x86_l_10c8;
	case 4303ULL: goto x86_l_10cf;
	case 4308ULL: goto x86_l_10d4;
	case 4310ULL: goto x86_l_10d6;
	case 4313ULL: goto x86_l_10d9;
	case 4319ULL: goto x86_l_10df;
	case 4322ULL: goto x86_l_10e2;
	case 4324ULL: goto x86_l_10e4;
	case 4329ULL: goto x86_l_10e9;
	case 4332ULL: goto x86_l_10ec;
	case 4338ULL: goto x86_l_10f2;
	case 4341ULL: goto x86_l_10f5;
	case 4344ULL: goto x86_l_10f8;
	case 4350ULL: goto x86_l_10fe;
	case 4354ULL: goto x86_l_1102;
	case 4361ULL: goto x86_l_1109;
	case 4366ULL: goto x86_l_110e;
	case 4368ULL: goto x86_l_1110;
	case 4371ULL: goto x86_l_1113;
	case 4377ULL: goto x86_l_1119;
	case 4380ULL: goto x86_l_111c;
	case 4382ULL: goto x86_l_111e;
	case 4387ULL: goto x86_l_1123;
	case 4393ULL: goto x86_l_1129;
	case 4396ULL: goto x86_l_112c;
	case 4401ULL: goto x86_l_1131;
	case 4407ULL: goto x86_l_1137;
	case 4411ULL: goto x86_l_113b;
	case 4418ULL: goto x86_l_1142;
	case 4423ULL: goto x86_l_1147;
	case 4425ULL: goto x86_l_1149;
	case 4428ULL: goto x86_l_114c;
	case 4434ULL: goto x86_l_1152;
	case 4437ULL: goto x86_l_1155;
	case 4439ULL: goto x86_l_1157;
	case 4444ULL: goto x86_l_115c;
	case 4450ULL: goto x86_l_1162;
	case 4453ULL: goto x86_l_1165;
	case 4458ULL: goto x86_l_116a;
	case 4464ULL: goto x86_l_1170;
	case 4468ULL: goto x86_l_1174;
	case 4475ULL: goto x86_l_117b;
	case 4480ULL: goto x86_l_1180;
	case 4482ULL: goto x86_l_1182;
	case 4485ULL: goto x86_l_1185;
	case 4491ULL: goto x86_l_118b;
	case 4494ULL: goto x86_l_118e;
	case 4496ULL: goto x86_l_1190;
	case 4501ULL: goto x86_l_1195;
	case 4507ULL: goto x86_l_119b;
	case 4510ULL: goto x86_l_119e;
	case 4515ULL: goto x86_l_11a3;
	case 4521ULL: goto x86_l_11a9;
	case 4525ULL: goto x86_l_11ad;
	case 4532ULL: goto x86_l_11b4;
	case 4537ULL: goto x86_l_11b9;
	case 4539ULL: goto x86_l_11bb;
	case 4542ULL: goto x86_l_11be;
	case 4548ULL: goto x86_l_11c4;
	case 4551ULL: goto x86_l_11c7;
	case 4553ULL: goto x86_l_11c9;
	case 4558ULL: goto x86_l_11ce;
	case 4564ULL: goto x86_l_11d4;
	case 4567ULL: goto x86_l_11d7;
	case 4572ULL: goto x86_l_11dc;
	case 4578ULL: goto x86_l_11e2;
	case 4582ULL: goto x86_l_11e6;
	case 4589ULL: goto x86_l_11ed;
	case 4594ULL: goto x86_l_11f2;
	case 4596ULL: goto x86_l_11f4;
	case 4599ULL: goto x86_l_11f7;
	case 4605ULL: goto x86_l_11fd;
	case 4608ULL: goto x86_l_1200;
	case 4610ULL: goto x86_l_1202;
	case 4615ULL: goto x86_l_1207;
	case 4621ULL: goto x86_l_120d;
	case 4624ULL: goto x86_l_1210;
	case 4629ULL: goto x86_l_1215;
	case 4635ULL: goto x86_l_121b;
	case 4639ULL: goto x86_l_121f;
	case 4646ULL: goto x86_l_1226;
	case 4651ULL: goto x86_l_122b;
	case 4653ULL: goto x86_l_122d;
	case 4656ULL: goto x86_l_1230;
	case 4658ULL: goto x86_l_1232;
	case 4661ULL: goto x86_l_1235;
	case 4663ULL: goto x86_l_1237;
	case 4668ULL: goto x86_l_123c;
	case 4670ULL: goto x86_l_123e;
	case 4673ULL: goto x86_l_1241;
	case 4678ULL: goto x86_l_1246;
	case 4681ULL: goto x86_l_1249;
	case 4686ULL: goto x86_l_124e;
	case 4691ULL: goto x86_l_1253;
	case 4696ULL: goto x86_l_1258;
	case 4701ULL: goto x86_l_125d;
	case 4706ULL: goto x86_l_1262;
	case 4710ULL: goto x86_l_1266;
	case 4712ULL: goto x86_l_1268;
	case 4716ULL: goto x86_l_126c;
	case 4723ULL: goto x86_l_1273;
	case 4728ULL: goto x86_l_1278;
	case 4735ULL: goto x86_l_127f;
	case 4737ULL: goto x86_l_1281;
	case 4740ULL: goto x86_l_1284;
	case 4745ULL: goto x86_l_1289;
	case 4749ULL: goto x86_l_128d;
	case 4752ULL: goto x86_l_1290;
	case 4757ULL: goto x86_l_1295;
	case 4762ULL: goto x86_l_129a;
	case 4767ULL: goto x86_l_129f;
	case 4772ULL: goto x86_l_12a4;
	case 4776ULL: goto x86_l_12a8;
	case 4778ULL: goto x86_l_12aa;
	case 4780ULL: goto x86_l_12ac;
	case 4783ULL: goto x86_l_12af;
	case 4788ULL: goto x86_l_12b4;
	case 4793ULL: goto x86_l_12b9;
	case 4798ULL: goto x86_l_12be;
	case 4803ULL: goto x86_l_12c3;
	case 4808ULL: goto x86_l_12c8;
	case 4812ULL: goto x86_l_12cc;
	case 4816ULL: goto x86_l_12d0;
	case 4819ULL: goto x86_l_12d3;
	case 4823ULL: goto x86_l_12d7;
	case 4826ULL: goto x86_l_12da;
	case 4830ULL: goto x86_l_12de;
	case 4833ULL: goto x86_l_12e1;
	case 4837ULL: goto x86_l_12e5;
	case 4843ULL: goto x86_l_12eb;
	case 4846ULL: goto x86_l_12ee;
	case 4850ULL: goto x86_l_12f2;
	case 4856ULL: goto x86_l_12f8;
	case 4858ULL: goto x86_l_12fa;
	case 4860ULL: goto x86_l_12fc;
	case 4862ULL: goto x86_l_12fe;
	case 4865ULL: goto x86_l_1301;
	case 4868ULL: goto x86_l_1304;
	case 4873ULL: goto x86_l_1309;
	case 4877ULL: goto x86_l_130d;
	case 4879ULL: goto x86_l_130f;
	case 4881ULL: goto x86_l_1311;
	default: return 0xffffffffffffffffULL;
	}
x86_l_cc6:
	/* 0xcc6: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dcf;
	}
x86_l_ccc:
	/* 0xccc: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_cd0:
	/* 0xcd0: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
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
	/* 0xce1: je     da4 <generic_tracepoint_filter+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_da4;
	}
x86_l_ce7:
	/* 0xce7: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_cea:
	/* 0xcea: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cec:
	/* 0xcec: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cf1:
	/* 0xcf1: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dcf;
	}
x86_l_cf7:
	/* 0xcf7: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cfa:
	/* 0xcfa: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cff:
	/* 0xcff: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dcf;
	}
x86_l_d05:
	/* 0xd05: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d09:
	/* 0xd09: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_d10:
	/* 0xd10: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d15:
	/* 0xd15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d17:
	/* 0xd17: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d1a:
	/* 0xd1a: je     da4 <generic_tracepoint_filter+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_da4;
	}
x86_l_d20:
	/* 0xd20: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_d23:
	/* 0xd23: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d25:
	/* 0xd25: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d2a:
	/* 0xd2a: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dcf;
	}
x86_l_d30:
	/* 0xd30: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d33:
	/* 0xd33: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d38:
	/* 0xd38: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dcf;
	}
x86_l_d3e:
	/* 0xd3e: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d42:
	/* 0xd42: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_d49:
	/* 0xd49: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d4e:
	/* 0xd4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d50:
	/* 0xd50: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d53:
	/* 0xd53: je     da4 <generic_tracepoint_filter+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_da4;
	}
x86_l_d55:
	/* 0xd55: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_d58:
	/* 0xd58: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d5a:
	/* 0xd5a: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d5f:
	/* 0xd5f: je     dcf <generic_tracepoint_filter+0xdcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dcf;
	}
x86_l_d61:
	/* 0xd61: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d64:
	/* 0xd64: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d69:
	/* 0xd69: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_d6c:
	/* 0xd6c: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d71:
	/* 0xd71: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d76:
	/* 0xd76: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d7b:
	/* 0xd7b: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d80:
	/* 0xd80: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d85:
	/* 0xd85: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_d89:
	/* 0xd89: je     def <generic_tracepoint_filter+0xdef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_def;
	}
x86_l_d8b:
	/* 0xd8b: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d8f:
	/* 0xd8f: mov    rcx,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_d96:
	/* 0xd96: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d9b:
	/* 0xd9b: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_da2:
	/* 0xda2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_da4:
	/* 0xda4: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_da7:
	/* 0xda7: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dac:
	/* 0xdac: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_db0:
	/* 0xdb0: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_db3:
	/* 0xdb3: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_db8:
	/* 0xdb8: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dbd:
	/* 0xdbd: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dc2:
	/* 0xdc2: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_dc7:
	/* 0xdc7: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_dcb:
	/* 0xdcb: jne    def <generic_tracepoint_filter+0xdef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_def;
	}
x86_l_dcd:
	/* 0xdcd: jmp    dfd <generic_tracepoint_filter+0xdfd> */
	goto x86_l_dfd;
x86_l_dcf:
	/* 0xdcf: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_dd2:
	/* 0xdd2: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dd7:
	/* 0xdd7: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ddc:
	/* 0xddc: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_de1:
	/* 0xde1: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_de6:
	/* 0xde6: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_deb:
	/* 0xdeb: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_def:
	/* 0xdef: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_df3:
	/* 0xdf3: setne  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_NE);
x86_l_df6:
	/* 0xdf6: xor    r12b,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_dfa:
	/* 0xdfa: or     r12b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_dfd:
	/* 0xdfd: movzx  edx,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_e01:
	/* 0xe01: mov    DWORD PTR [rsp+0x50],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e05:
	/* 0xe05: add    ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_e08:
	/* 0xe08: lea    rdx,[rcx+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e0c:
	/* 0xe0c: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_e12:
	/* 0xe12: mov    rsi,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_e15:
	/* 0xe15: cmove  rsi,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_e19:
	/* 0xe19: cmp    ebp,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1000ULL);
x86_l_e1f:
	/* 0xe1f: jbe    e2b <generic_tracepoint_filter+0xe2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e2b;
	}
x86_l_e21:
	/* 0xe21: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e24:
	/* 0xe24: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e29:
	/* 0xe29: jmp    e3e <generic_tracepoint_filter+0xe3e> */
	goto x86_l_e3e;
x86_l_e2b:
	/* 0xe2b: mov    r12d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_32);
x86_l_e2e:
	/* 0xe2e: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_e30:
	/* 0xe30: and    edi,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_e33:
	/* 0xe33: mov    edi,DWORD PTR [rax+rdi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_e36:
	/* 0xe36: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e3b:
	/* 0xe3b: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_e3e:
	/* 0xe3e: test   r10b,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R10, X86_WIDTH_8, 2ULL);
x86_l_e42:
	/* 0xe42: jne    e6d <generic_tracepoint_filter+0xe6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e6d;
	}
x86_l_e44:
	/* 0xe44: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e46:
	/* 0xe46: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_e4a:
	/* 0xe4a: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e4f:
	/* 0xe4f: jne    e5a <generic_tracepoint_filter+0xe5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e5a;
	}
x86_l_e51:
	/* 0xe51: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_e54:
	/* 0xe54: jne    104b <generic_tracepoint_filter+0x104b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_104b;
	}
x86_l_e5a:
	/* 0xe5a: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_e5d:
	/* 0xe5d: setne  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_NE);
x86_l_e60:
	/* 0xe60: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_e64:
	/* 0xe64: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_e68:
	/* 0xe68: jmp    12d7 <generic_tracepoint_filter+0x12d7> */
	goto x86_l_12d7;
x86_l_e6d:
	/* 0xe6d: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_e73:
	/* 0xe73: je     1053 <generic_tracepoint_filter+0x1053> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1053;
	}
x86_l_e79:
	/* 0xe79: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e7b:
	/* 0xe7b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_e7e:
	/* 0xe7e: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e83:
	/* 0xe83: je     104b <generic_tracepoint_filter+0x104b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_104b;
	}
x86_l_e89:
	/* 0xe89: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_e8c:
	/* 0xe8c: test   rsi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_64);
x86_l_e8f:
	/* 0xe8f: je     12cc <generic_tracepoint_filter+0x12cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12cc;
	}
x86_l_e95:
	/* 0xe95: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_e98:
	/* 0xe98: je     12cc <generic_tracepoint_filter+0x12cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12cc;
	}
x86_l_e9e:
	/* 0xe9e: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ea2:
	/* 0xea2: mov    QWORD PTR [rsp+0x30],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ea7:
	/* 0xea7: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_eac:
	/* 0xeac: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eb1:
	/* 0xeb1: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_eb6:
	/* 0xeb6: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eba:
	/* 0xeba: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_ec1:
	/* 0xec1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ec6:
	/* 0xec6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ec8:
	/* 0xec8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ecb:
	/* 0xecb: je     1281 <generic_tracepoint_filter+0x1281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1281;
	}
x86_l_ed1:
	/* 0xed1: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_ed4:
	/* 0xed4: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_ed7:
	/* 0xed7: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_edc:
	/* 0xedc: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_ee2:
	/* 0xee2: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ee6:
	/* 0xee6: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_eed:
	/* 0xeed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ef2:
	/* 0xef2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef4:
	/* 0xef4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ef7:
	/* 0xef7: je     1281 <generic_tracepoint_filter+0x1281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1281;
	}
x86_l_efd:
	/* 0xefd: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f00:
	/* 0xf00: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f03:
	/* 0xf03: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f08:
	/* 0xf08: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_f0e:
	/* 0xf0e: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f12:
	/* 0xf12: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_f19:
	/* 0xf19: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f1e:
	/* 0xf1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f20:
	/* 0xf20: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f23:
	/* 0xf23: je     1281 <generic_tracepoint_filter+0x1281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1281;
	}
x86_l_f29:
	/* 0xf29: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f2c:
	/* 0xf2c: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f2f:
	/* 0xf2f: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f34:
	/* 0xf34: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_f3a:
	/* 0xf3a: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f3e:
	/* 0xf3e: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_f45:
	/* 0xf45: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f4a:
	/* 0xf4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f4c:
	/* 0xf4c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f4f:
	/* 0xf4f: je     1281 <generic_tracepoint_filter+0x1281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1281;
	}
x86_l_f55:
	/* 0xf55: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f58:
	/* 0xf58: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f5b:
	/* 0xf5b: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f60:
	/* 0xf60: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_f66:
	/* 0xf66: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f6a:
	/* 0xf6a: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_f71:
	/* 0xf71: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f76:
	/* 0xf76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f78:
	/* 0xf78: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f7b:
	/* 0xf7b: je     1281 <generic_tracepoint_filter+0x1281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1281;
	}
x86_l_f81:
	/* 0xf81: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f84:
	/* 0xf84: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f87:
	/* 0xf87: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f8c:
	/* 0xf8c: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_f92:
	/* 0xf92: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f96:
	/* 0xf96: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_f9d:
	/* 0xf9d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fa2:
	/* 0xfa2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fa4:
	/* 0xfa4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fa7:
	/* 0xfa7: je     1281 <generic_tracepoint_filter+0x1281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1281;
	}
x86_l_fad:
	/* 0xfad: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_fb0:
	/* 0xfb0: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_fb3:
	/* 0xfb3: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fb8:
	/* 0xfb8: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_fbe:
	/* 0xfbe: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_fc2:
	/* 0xfc2: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_fc9:
	/* 0xfc9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fce:
	/* 0xfce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fd0:
	/* 0xfd0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fd3:
	/* 0xfd3: je     1281 <generic_tracepoint_filter+0x1281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1281;
	}
x86_l_fd9:
	/* 0xfd9: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_fdc:
	/* 0xfdc: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_fdf:
	/* 0xfdf: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fe4:
	/* 0xfe4: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_fea:
	/* 0xfea: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_fee:
	/* 0xfee: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_ff5:
	/* 0xff5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ffa:
	/* 0xffa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ffc:
	/* 0xffc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fff:
	/* 0xfff: je     1281 <generic_tracepoint_filter+0x1281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1281;
	}
x86_l_1005:
	/* 0x1005: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1008:
	/* 0x1008: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_100b:
	/* 0x100b: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1010:
	/* 0x1010: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1013:
	/* 0x1013: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1018:
	/* 0x1018: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_101d:
	/* 0x101d: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1022:
	/* 0x1022: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1027:
	/* 0x1027: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_102c:
	/* 0x102c: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1030:
	/* 0x1030: je     12cc <generic_tracepoint_filter+0x12cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12cc;
	}
x86_l_1036:
	/* 0x1036: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_103a:
	/* 0x103a: mov    rcx,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1041:
	/* 0x1041: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1046:
	/* 0x1046: jmp    1278 <generic_tracepoint_filter+0x1278> */
	goto x86_l_1278;
x86_l_104b:
	/* 0x104b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_104e:
	/* 0x104e: jmp    12da <generic_tracepoint_filter+0x12da> */
	goto x86_l_12da;
x86_l_1053:
	/* 0x1053: mov    edx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1055:
	/* 0x1055: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_1058:
	/* 0x1058: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_105d:
	/* 0x105d: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1060:
	/* 0x1060: je     12cc <generic_tracepoint_filter+0x12cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12cc;
	}
x86_l_1066:
	/* 0x1066: mov    edx,DWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1069:
	/* 0x1069: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_106c:
	/* 0x106c: je     12cc <generic_tracepoint_filter+0x12cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12cc;
	}
x86_l_1072:
	/* 0x1072: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1076:
	/* 0x1076: mov    QWORD PTR [rsp+0x30],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_107b:
	/* 0x107b: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1080:
	/* 0x1080: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1085:
	/* 0x1085: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_108a:
	/* 0x108a: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_108e:
	/* 0x108e: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1095:
	/* 0x1095: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_109a:
	/* 0x109a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_109c:
	/* 0x109c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_109f:
	/* 0x109f: je     1281 <generic_tracepoint_filter+0x1281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1281;
	}
x86_l_10a5:
	/* 0x10a5: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_10a8:
	/* 0x10a8: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10aa:
	/* 0x10aa: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10af:
	/* 0x10af: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_10b2:
	/* 0x10b2: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_10b8:
	/* 0x10b8: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10bb:
	/* 0x10bb: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_10be:
	/* 0x10be: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_10c4:
	/* 0x10c4: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_10c8:
	/* 0x10c8: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_10cf:
	/* 0x10cf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10d4:
	/* 0x10d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d6:
	/* 0x10d6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10d9:
	/* 0x10d9: je     1281 <generic_tracepoint_filter+0x1281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1281;
	}
x86_l_10df:
	/* 0x10df: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_10e2:
	/* 0x10e2: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10e4:
	/* 0x10e4: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10e9:
	/* 0x10e9: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_10ec:
	/* 0x10ec: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_10f2:
	/* 0x10f2: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10f5:
	/* 0x10f5: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_10f8:
	/* 0x10f8: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_10fe:
	/* 0x10fe: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1102:
	/* 0x1102: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1109:
	/* 0x1109: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_110e:
	/* 0x110e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1110:
	/* 0x1110: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1113:
	/* 0x1113: je     1281 <generic_tracepoint_filter+0x1281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1281;
	}
x86_l_1119:
	/* 0x1119: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_111c:
	/* 0x111c: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_111e:
	/* 0x111e: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1123:
	/* 0x1123: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_1129:
	/* 0x1129: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_112c:
	/* 0x112c: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1131:
	/* 0x1131: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_1137:
	/* 0x1137: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_113b:
	/* 0x113b: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1142:
	/* 0x1142: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1147:
	/* 0x1147: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1149:
	/* 0x1149: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_114c:
	/* 0x114c: je     1281 <generic_tracepoint_filter+0x1281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1281;
	}
x86_l_1152:
	/* 0x1152: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1155:
	/* 0x1155: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1157:
	/* 0x1157: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_115c:
	/* 0x115c: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_1162:
	/* 0x1162: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1165:
	/* 0x1165: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_116a:
	/* 0x116a: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_1170:
	/* 0x1170: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1174:
	/* 0x1174: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_117b:
	/* 0x117b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1180:
	/* 0x1180: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1182:
	/* 0x1182: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1185:
	/* 0x1185: je     1281 <generic_tracepoint_filter+0x1281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1281;
	}
x86_l_118b:
	/* 0x118b: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_118e:
	/* 0x118e: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1190:
	/* 0x1190: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1195:
	/* 0x1195: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_119b:
	/* 0x119b: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_119e:
	/* 0x119e: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11a3:
	/* 0x11a3: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_11a9:
	/* 0x11a9: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_11ad:
	/* 0x11ad: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_11b4:
	/* 0x11b4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11b9:
	/* 0x11b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11bb:
	/* 0x11bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11be:
	/* 0x11be: je     1281 <generic_tracepoint_filter+0x1281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1281;
	}
x86_l_11c4:
	/* 0x11c4: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_11c7:
	/* 0x11c7: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11c9:
	/* 0x11c9: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11ce:
	/* 0x11ce: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_11d4:
	/* 0x11d4: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11d7:
	/* 0x11d7: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11dc:
	/* 0x11dc: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_11e2:
	/* 0x11e2: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_11e6:
	/* 0x11e6: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_11ed:
	/* 0x11ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11f2:
	/* 0x11f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11f4:
	/* 0x11f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11f7:
	/* 0x11f7: je     1281 <generic_tracepoint_filter+0x1281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1281;
	}
x86_l_11fd:
	/* 0x11fd: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1200:
	/* 0x1200: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1202:
	/* 0x1202: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1207:
	/* 0x1207: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_120d:
	/* 0x120d: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1210:
	/* 0x1210: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1215:
	/* 0x1215: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_121b:
	/* 0x121b: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_121f:
	/* 0x121f: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1226:
	/* 0x1226: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_122b:
	/* 0x122b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_122d:
	/* 0x122d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1230:
	/* 0x1230: je     1281 <generic_tracepoint_filter+0x1281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1281;
	}
x86_l_1232:
	/* 0x1232: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1235:
	/* 0x1235: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1237:
	/* 0x1237: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_123c:
	/* 0x123c: je     12ac <generic_tracepoint_filter+0x12ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ac;
	}
x86_l_123e:
	/* 0x123e: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1241:
	/* 0x1241: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1246:
	/* 0x1246: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1249:
	/* 0x1249: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_124e:
	/* 0x124e: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1253:
	/* 0x1253: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1258:
	/* 0x1258: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_125d:
	/* 0x125d: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1262:
	/* 0x1262: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1266:
	/* 0x1266: je     12cc <generic_tracepoint_filter+0x12cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12cc;
	}
x86_l_1268:
	/* 0x1268: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_126c:
	/* 0x126c: mov    rcx,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1273:
	/* 0x1273: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1278:
	/* 0x1278: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_127f:
	/* 0x127f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1281:
	/* 0x1281: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1284:
	/* 0x1284: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1289:
	/* 0x1289: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_128d:
	/* 0x128d: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1290:
	/* 0x1290: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1295:
	/* 0x1295: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_129a:
	/* 0x129a: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_129f:
	/* 0x129f: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12a4:
	/* 0x12a4: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_12a8:
	/* 0x12a8: jne    12cc <generic_tracepoint_filter+0x12cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_12cc;
	}
x86_l_12aa:
	/* 0x12aa: jmp    12da <generic_tracepoint_filter+0x12da> */
	goto x86_l_12da;
x86_l_12ac:
	/* 0x12ac: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_12af:
	/* 0x12af: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12b4:
	/* 0x12b4: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12b9:
	/* 0x12b9: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12be:
	/* 0x12be: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12c3:
	/* 0x12c3: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12c8:
	/* 0x12c8: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_12cc:
	/* 0x12cc: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_12d0:
	/* 0x12d0: setne  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_NE);
x86_l_12d3:
	/* 0x12d3: xor    r12b,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_12d7:
	/* 0x12d7: or     r12b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_12da:
	/* 0x12da: movzx  r12d,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_12de:
	/* 0x12de: add    ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_12e1:
	/* 0x12e1: lea    rdx,[rcx+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_12e5:
	/* 0x12e5: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_12eb:
	/* 0x12eb: mov    rsi,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_12ee:
	/* 0x12ee: cmove  rsi,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_12f2:
	/* 0x12f2: cmp    ebp,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1000ULL);
x86_l_12f8:
	/* 0x12f8: jbe    12fe <generic_tracepoint_filter+0x12fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_12fe;
	}
x86_l_12fa:
	/* 0x12fa: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12fc:
	/* 0x12fc: jmp    1304 <generic_tracepoint_filter+0x1304> */
	goto x86_l_1304;
x86_l_12fe:
	/* 0x12fe: and    ebp,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1301:
	/* 0x1301: mov    ebp,DWORD PTR [rax+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1304:
	/* 0x1304: mov    QWORD PTR [rsp+0x28],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1309:
	/* 0x1309: test   r10b,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R10, X86_WIDTH_8, 2ULL);
x86_l_130d:
	/* 0x130d: jne    133a <generic_tracepoint_filter+0x133a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4922ULL;
	}
x86_l_130f:
	/* 0x130f: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1311:
	/* 0x1311: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
	return 4885ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_generic_tracepoint_filter_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4885ULL: goto x86_l_1315;
	case 4890ULL: goto x86_l_131a;
	case 4892ULL: goto x86_l_131c;
	case 4894ULL: goto x86_l_131e;
	case 4897ULL: goto x86_l_1321;
	case 4903ULL: goto x86_l_1327;
	case 4906ULL: goto x86_l_132a;
	case 4909ULL: goto x86_l_132d;
	case 4913ULL: goto x86_l_1331;
	case 4917ULL: goto x86_l_1335;
	case 4922ULL: goto x86_l_133a;
	case 4928ULL: goto x86_l_1340;
	case 4933ULL: goto x86_l_1345;
	case 4939ULL: goto x86_l_134b;
	case 4941ULL: goto x86_l_134d;
	case 4944ULL: goto x86_l_1350;
	case 4950ULL: goto x86_l_1356;
	case 4953ULL: goto x86_l_1359;
	case 4956ULL: goto x86_l_135c;
	case 4962ULL: goto x86_l_1362;
	case 4965ULL: goto x86_l_1365;
	case 4971ULL: goto x86_l_136b;
	case 4975ULL: goto x86_l_136f;
	case 4980ULL: goto x86_l_1374;
	case 4985ULL: goto x86_l_1379;
	case 4990ULL: goto x86_l_137e;
	case 4994ULL: goto x86_l_1382;
	case 5001ULL: goto x86_l_1389;
	case 5006ULL: goto x86_l_138e;
	case 5008ULL: goto x86_l_1390;
	case 5011ULL: goto x86_l_1393;
	case 5017ULL: goto x86_l_1399;
	case 5020ULL: goto x86_l_139c;
	case 5023ULL: goto x86_l_139f;
	case 5028ULL: goto x86_l_13a4;
	case 5034ULL: goto x86_l_13aa;
	case 5038ULL: goto x86_l_13ae;
	case 5045ULL: goto x86_l_13b5;
	case 5050ULL: goto x86_l_13ba;
	case 5052ULL: goto x86_l_13bc;
	case 5055ULL: goto x86_l_13bf;
	case 5061ULL: goto x86_l_13c5;
	case 5064ULL: goto x86_l_13c8;
	case 5067ULL: goto x86_l_13cb;
	case 5072ULL: goto x86_l_13d0;
	case 5078ULL: goto x86_l_13d6;
	case 5082ULL: goto x86_l_13da;
	case 5089ULL: goto x86_l_13e1;
	case 5094ULL: goto x86_l_13e6;
	case 5096ULL: goto x86_l_13e8;
	case 5099ULL: goto x86_l_13eb;
	case 5105ULL: goto x86_l_13f1;
	case 5108ULL: goto x86_l_13f4;
	case 5111ULL: goto x86_l_13f7;
	case 5116ULL: goto x86_l_13fc;
	case 5122ULL: goto x86_l_1402;
	case 5126ULL: goto x86_l_1406;
	case 5133ULL: goto x86_l_140d;
	case 5138ULL: goto x86_l_1412;
	case 5140ULL: goto x86_l_1414;
	case 5143ULL: goto x86_l_1417;
	case 5149ULL: goto x86_l_141d;
	case 5152ULL: goto x86_l_1420;
	case 5155ULL: goto x86_l_1423;
	case 5160ULL: goto x86_l_1428;
	case 5166ULL: goto x86_l_142e;
	case 5170ULL: goto x86_l_1432;
	case 5177ULL: goto x86_l_1439;
	case 5182ULL: goto x86_l_143e;
	case 5184ULL: goto x86_l_1440;
	case 5187ULL: goto x86_l_1443;
	case 5193ULL: goto x86_l_1449;
	case 5196ULL: goto x86_l_144c;
	case 5199ULL: goto x86_l_144f;
	case 5204ULL: goto x86_l_1454;
	case 5210ULL: goto x86_l_145a;
	case 5214ULL: goto x86_l_145e;
	case 5221ULL: goto x86_l_1465;
	case 5226ULL: goto x86_l_146a;
	case 5228ULL: goto x86_l_146c;
	case 5231ULL: goto x86_l_146f;
	case 5237ULL: goto x86_l_1475;
	case 5240ULL: goto x86_l_1478;
	case 5243ULL: goto x86_l_147b;
	case 5248ULL: goto x86_l_1480;
	case 5254ULL: goto x86_l_1486;
	case 5258ULL: goto x86_l_148a;
	case 5265ULL: goto x86_l_1491;
	case 5270ULL: goto x86_l_1496;
	case 5272ULL: goto x86_l_1498;
	case 5275ULL: goto x86_l_149b;
	case 5281ULL: goto x86_l_14a1;
	case 5284ULL: goto x86_l_14a4;
	case 5287ULL: goto x86_l_14a7;
	case 5292ULL: goto x86_l_14ac;
	case 5298ULL: goto x86_l_14b2;
	case 5302ULL: goto x86_l_14b6;
	case 5309ULL: goto x86_l_14bd;
	case 5314ULL: goto x86_l_14c2;
	case 5316ULL: goto x86_l_14c4;
	case 5319ULL: goto x86_l_14c7;
	case 5325ULL: goto x86_l_14cd;
	case 5328ULL: goto x86_l_14d0;
	case 5331ULL: goto x86_l_14d3;
	case 5336ULL: goto x86_l_14d8;
	case 5339ULL: goto x86_l_14db;
	case 5344ULL: goto x86_l_14e0;
	case 5349ULL: goto x86_l_14e5;
	case 5354ULL: goto x86_l_14ea;
	case 5359ULL: goto x86_l_14ef;
	case 5363ULL: goto x86_l_14f3;
	case 5369ULL: goto x86_l_14f9;
	case 5373ULL: goto x86_l_14fd;
	case 5380ULL: goto x86_l_1504;
	case 5385ULL: goto x86_l_1509;
	case 5390ULL: goto x86_l_150e;
	case 5392ULL: goto x86_l_1510;
	case 5395ULL: goto x86_l_1513;
	case 5398ULL: goto x86_l_1516;
	case 5404ULL: goto x86_l_151c;
	case 5407ULL: goto x86_l_151f;
	case 5410ULL: goto x86_l_1522;
	case 5416ULL: goto x86_l_1528;
	case 5420ULL: goto x86_l_152c;
	case 5425ULL: goto x86_l_1531;
	case 5430ULL: goto x86_l_1536;
	case 5435ULL: goto x86_l_153b;
	case 5439ULL: goto x86_l_153f;
	case 5446ULL: goto x86_l_1546;
	case 5451ULL: goto x86_l_154b;
	case 5453ULL: goto x86_l_154d;
	case 5456ULL: goto x86_l_1550;
	case 5462ULL: goto x86_l_1556;
	case 5465ULL: goto x86_l_1559;
	case 5467ULL: goto x86_l_155b;
	case 5472ULL: goto x86_l_1560;
	case 5475ULL: goto x86_l_1563;
	case 5481ULL: goto x86_l_1569;
	case 5484ULL: goto x86_l_156c;
	case 5487ULL: goto x86_l_156f;
	case 5493ULL: goto x86_l_1575;
	case 5497ULL: goto x86_l_1579;
	case 5504ULL: goto x86_l_1580;
	case 5509ULL: goto x86_l_1585;
	case 5511ULL: goto x86_l_1587;
	case 5514ULL: goto x86_l_158a;
	case 5520ULL: goto x86_l_1590;
	case 5523ULL: goto x86_l_1593;
	case 5525ULL: goto x86_l_1595;
	case 5530ULL: goto x86_l_159a;
	case 5533ULL: goto x86_l_159d;
	case 5539ULL: goto x86_l_15a3;
	case 5542ULL: goto x86_l_15a6;
	case 5545ULL: goto x86_l_15a9;
	case 5551ULL: goto x86_l_15af;
	case 5555ULL: goto x86_l_15b3;
	case 5562ULL: goto x86_l_15ba;
	case 5567ULL: goto x86_l_15bf;
	case 5569ULL: goto x86_l_15c1;
	case 5572ULL: goto x86_l_15c4;
	case 5578ULL: goto x86_l_15ca;
	case 5581ULL: goto x86_l_15cd;
	case 5583ULL: goto x86_l_15cf;
	case 5588ULL: goto x86_l_15d4;
	case 5591ULL: goto x86_l_15d7;
	case 5597ULL: goto x86_l_15dd;
	case 5600ULL: goto x86_l_15e0;
	case 5603ULL: goto x86_l_15e3;
	case 5609ULL: goto x86_l_15e9;
	case 5613ULL: goto x86_l_15ed;
	case 5620ULL: goto x86_l_15f4;
	case 5625ULL: goto x86_l_15f9;
	case 5627ULL: goto x86_l_15fb;
	case 5630ULL: goto x86_l_15fe;
	case 5636ULL: goto x86_l_1604;
	case 5639ULL: goto x86_l_1607;
	case 5641ULL: goto x86_l_1609;
	case 5646ULL: goto x86_l_160e;
	case 5652ULL: goto x86_l_1614;
	case 5655ULL: goto x86_l_1617;
	case 5660ULL: goto x86_l_161c;
	case 5666ULL: goto x86_l_1622;
	case 5670ULL: goto x86_l_1626;
	case 5677ULL: goto x86_l_162d;
	case 5682ULL: goto x86_l_1632;
	case 5684ULL: goto x86_l_1634;
	case 5687ULL: goto x86_l_1637;
	case 5693ULL: goto x86_l_163d;
	case 5696ULL: goto x86_l_1640;
	case 5698ULL: goto x86_l_1642;
	case 5703ULL: goto x86_l_1647;
	case 5709ULL: goto x86_l_164d;
	case 5712ULL: goto x86_l_1650;
	case 5717ULL: goto x86_l_1655;
	case 5723ULL: goto x86_l_165b;
	case 5727ULL: goto x86_l_165f;
	case 5734ULL: goto x86_l_1666;
	case 5739ULL: goto x86_l_166b;
	case 5741ULL: goto x86_l_166d;
	case 5744ULL: goto x86_l_1670;
	case 5750ULL: goto x86_l_1676;
	case 5753ULL: goto x86_l_1679;
	case 5755ULL: goto x86_l_167b;
	case 5760ULL: goto x86_l_1680;
	case 5766ULL: goto x86_l_1686;
	case 5769ULL: goto x86_l_1689;
	case 5774ULL: goto x86_l_168e;
	case 5780ULL: goto x86_l_1694;
	case 5784ULL: goto x86_l_1698;
	case 5791ULL: goto x86_l_169f;
	case 5796ULL: goto x86_l_16a4;
	case 5798ULL: goto x86_l_16a6;
	case 5801ULL: goto x86_l_16a9;
	case 5807ULL: goto x86_l_16af;
	case 5810ULL: goto x86_l_16b2;
	case 5812ULL: goto x86_l_16b4;
	case 5817ULL: goto x86_l_16b9;
	case 5823ULL: goto x86_l_16bf;
	case 5826ULL: goto x86_l_16c2;
	case 5831ULL: goto x86_l_16c7;
	case 5837ULL: goto x86_l_16cd;
	case 5841ULL: goto x86_l_16d1;
	case 5848ULL: goto x86_l_16d8;
	case 5853ULL: goto x86_l_16dd;
	case 5855ULL: goto x86_l_16df;
	case 5858ULL: goto x86_l_16e2;
	case 5860ULL: goto x86_l_16e4;
	case 5863ULL: goto x86_l_16e7;
	case 5865ULL: goto x86_l_16e9;
	case 5870ULL: goto x86_l_16ee;
	case 5872ULL: goto x86_l_16f0;
	case 5875ULL: goto x86_l_16f3;
	case 5880ULL: goto x86_l_16f8;
	case 5883ULL: goto x86_l_16fb;
	case 5888ULL: goto x86_l_1700;
	case 5893ULL: goto x86_l_1705;
	case 5898ULL: goto x86_l_170a;
	case 5903ULL: goto x86_l_170f;
	case 5907ULL: goto x86_l_1713;
	case 5909ULL: goto x86_l_1715;
	case 5913ULL: goto x86_l_1719;
	case 5920ULL: goto x86_l_1720;
	case 5925ULL: goto x86_l_1725;
	case 5932ULL: goto x86_l_172c;
	case 5934ULL: goto x86_l_172e;
	case 5936ULL: goto x86_l_1730;
	case 5941ULL: goto x86_l_1735;
	case 5945ULL: goto x86_l_1739;
	case 5948ULL: goto x86_l_173c;
	case 5953ULL: goto x86_l_1741;
	case 5958ULL: goto x86_l_1746;
	case 5963ULL: goto x86_l_174b;
	case 5967ULL: goto x86_l_174f;
	case 5969ULL: goto x86_l_1751;
	case 5971ULL: goto x86_l_1753;
	case 5973ULL: goto x86_l_1755;
	case 5975ULL: goto x86_l_1757;
	case 5978ULL: goto x86_l_175a;
	case 5983ULL: goto x86_l_175f;
	case 5988ULL: goto x86_l_1764;
	case 5993ULL: goto x86_l_1769;
	case 5998ULL: goto x86_l_176e;
	case 6002ULL: goto x86_l_1772;
	case 6006ULL: goto x86_l_1776;
	case 6009ULL: goto x86_l_1779;
	case 6013ULL: goto x86_l_177d;
	case 6016ULL: goto x86_l_1780;
	case 6020ULL: goto x86_l_1784;
	case 6024ULL: goto x86_l_1788;
	case 6026ULL: goto x86_l_178a;
	case 6031ULL: goto x86_l_178f;
	case 6033ULL: goto x86_l_1791;
	case 6036ULL: goto x86_l_1794;
	case 6038ULL: goto x86_l_1796;
	case 6042ULL: goto x86_l_179a;
	case 6045ULL: goto x86_l_179d;
	case 6048ULL: goto x86_l_17a0;
	case 6051ULL: goto x86_l_17a3;
	case 6057ULL: goto x86_l_17a9;
	case 6062ULL: goto x86_l_17ae;
	case 6065ULL: goto x86_l_17b1;
	case 6069ULL: goto x86_l_17b5;
	case 6072ULL: goto x86_l_17b8;
	case 6078ULL: goto x86_l_17be;
	case 6081ULL: goto x86_l_17c1;
	case 6085ULL: goto x86_l_17c5;
	case 6088ULL: goto x86_l_17c8;
	case 6094ULL: goto x86_l_17ce;
	case 6100ULL: goto x86_l_17d4;
	case 6104ULL: goto x86_l_17d8;
	case 6108ULL: goto x86_l_17dc;
	case 6113ULL: goto x86_l_17e1;
	case 6117ULL: goto x86_l_17e5;
	case 6120ULL: goto x86_l_17e8;
	case 6125ULL: goto x86_l_17ed;
	case 6127ULL: goto x86_l_17ef;
	case 6129ULL: goto x86_l_17f1;
	case 6134ULL: goto x86_l_17f6;
	case 6137ULL: goto x86_l_17f9;
	case 6144ULL: goto x86_l_1800;
	case 6146ULL: goto x86_l_1802;
	case 6149ULL: goto x86_l_1805;
	case 6152ULL: goto x86_l_1808;
	case 6155ULL: goto x86_l_180b;
	case 6158ULL: goto x86_l_180e;
	case 6162ULL: goto x86_l_1812;
	case 6166ULL: goto x86_l_1816;
	case 6168ULL: goto x86_l_1818;
	case 6173ULL: goto x86_l_181d;
	case 6177ULL: goto x86_l_1821;
	case 6179ULL: goto x86_l_1823;
	case 6182ULL: goto x86_l_1826;
	case 6184ULL: goto x86_l_1828;
	case 6187ULL: goto x86_l_182b;
	case 6190ULL: goto x86_l_182e;
	case 6194ULL: goto x86_l_1832;
	case 6196ULL: goto x86_l_1834;
	case 6199ULL: goto x86_l_1837;
	case 6203ULL: goto x86_l_183b;
	case 6207ULL: goto x86_l_183f;
	case 6210ULL: goto x86_l_1842;
	case 6215ULL: goto x86_l_1847;
	case 6222ULL: goto x86_l_184e;
	case 6224ULL: goto x86_l_1850;
	case 6227ULL: goto x86_l_1853;
	case 6231ULL: goto x86_l_1857;
	case 6235ULL: goto x86_l_185b;
	case 6237ULL: goto x86_l_185d;
	case 6239ULL: goto x86_l_185f;
	case 6241ULL: goto x86_l_1861;
	case 6245ULL: goto x86_l_1865;
	case 6249ULL: goto x86_l_1869;
	case 6252ULL: goto x86_l_186c;
	case 6258ULL: goto x86_l_1872;
	case 6261ULL: goto x86_l_1875;
	case 6267ULL: goto x86_l_187b;
	case 6270ULL: goto x86_l_187e;
	case 6273ULL: goto x86_l_1881;
	case 6279ULL: goto x86_l_1887;
	case 6281ULL: goto x86_l_1889;
	case 6284ULL: goto x86_l_188c;
	case 6287ULL: goto x86_l_188f;
	case 6290ULL: goto x86_l_1892;
	case 6293ULL: goto x86_l_1895;
	case 6297ULL: goto x86_l_1899;
	case 6301ULL: goto x86_l_189d;
	case 6303ULL: goto x86_l_189f;
	case 6308ULL: goto x86_l_18a4;
	case 6312ULL: goto x86_l_18a8;
	case 6314ULL: goto x86_l_18aa;
	case 6316ULL: goto x86_l_18ac;
	case 6318ULL: goto x86_l_18ae;
	case 6320ULL: goto x86_l_18b0;
	case 6323ULL: goto x86_l_18b3;
	case 6326ULL: goto x86_l_18b6;
	case 6329ULL: goto x86_l_18b9;
	case 6331ULL: goto x86_l_18bb;
	case 6335ULL: goto x86_l_18bf;
	case 6339ULL: goto x86_l_18c3;
	case 6341ULL: goto x86_l_18c5;
	case 6346ULL: goto x86_l_18ca;
	case 6353ULL: goto x86_l_18d1;
	case 6355ULL: goto x86_l_18d3;
	case 6358ULL: goto x86_l_18d6;
	case 6361ULL: goto x86_l_18d9;
	case 6364ULL: goto x86_l_18dc;
	case 6367ULL: goto x86_l_18df;
	case 6371ULL: goto x86_l_18e3;
	case 6375ULL: goto x86_l_18e7;
	case 6377ULL: goto x86_l_18e9;
	case 6382ULL: goto x86_l_18ee;
	case 6386ULL: goto x86_l_18f2;
	case 6388ULL: goto x86_l_18f4;
	case 6391ULL: goto x86_l_18f7;
	case 6393ULL: goto x86_l_18f9;
	case 6396ULL: goto x86_l_18fc;
	case 6399ULL: goto x86_l_18ff;
	case 6403ULL: goto x86_l_1903;
	case 6405ULL: goto x86_l_1905;
	case 6408ULL: goto x86_l_1908;
	case 6412ULL: goto x86_l_190c;
	case 6416ULL: goto x86_l_1910;
	case 6419ULL: goto x86_l_1913;
	case 6424ULL: goto x86_l_1918;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1315:
	/* 0x1315: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_131a:
	/* 0x131a: jne    1327 <generic_tracepoint_filter+0x1327> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1327;
	}
x86_l_131c:
	/* 0x131c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_131e:
	/* 0x131e: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1321:
	/* 0x1321: jne    1796 <generic_tracepoint_filter+0x1796> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1796;
	}
x86_l_1327:
	/* 0x1327: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_132a:
	/* 0x132a: setne  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_NE);
x86_l_132d:
	/* 0x132d: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1331:
	/* 0x1331: setne  bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_NE);
x86_l_1335:
	/* 0x1335: jmp    177d <generic_tracepoint_filter+0x177d> */
	goto x86_l_177d;
x86_l_133a:
	/* 0x133a: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1340:
	/* 0x1340: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1345:
	/* 0x1345: je     150e <generic_tracepoint_filter+0x150e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_150e;
	}
x86_l_134b:
	/* 0x134b: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_134d:
	/* 0x134d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1350:
	/* 0x1350: je     1753 <generic_tracepoint_filter+0x1753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1753;
	}
x86_l_1356:
	/* 0x1356: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_1359:
	/* 0x1359: test   rsi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_64);
x86_l_135c:
	/* 0x135c: je     1772 <generic_tracepoint_filter+0x1772> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1772;
	}
x86_l_1362:
	/* 0x1362: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1365:
	/* 0x1365: je     1772 <generic_tracepoint_filter+0x1772> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1772;
	}
x86_l_136b:
	/* 0x136b: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_136f:
	/* 0x136f: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1374:
	/* 0x1374: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1379:
	/* 0x1379: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_137e:
	/* 0x137e: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1382:
	/* 0x1382: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1389:
	/* 0x1389: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_138e:
	/* 0x138e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1390:
	/* 0x1390: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1393:
	/* 0x1393: je     172e <generic_tracepoint_filter+0x172e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_172e;
	}
x86_l_1399:
	/* 0x1399: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_139c:
	/* 0x139c: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_139f:
	/* 0x139f: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13a4:
	/* 0x13a4: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_13aa:
	/* 0x13aa: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_13ae:
	/* 0x13ae: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_13b5:
	/* 0x13b5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13ba:
	/* 0x13ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13bc:
	/* 0x13bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13bf:
	/* 0x13bf: je     172e <generic_tracepoint_filter+0x172e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_172e;
	}
x86_l_13c5:
	/* 0x13c5: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_13c8:
	/* 0x13c8: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_13cb:
	/* 0x13cb: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13d0:
	/* 0x13d0: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_13d6:
	/* 0x13d6: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_13da:
	/* 0x13da: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_13e1:
	/* 0x13e1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13e6:
	/* 0x13e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e8:
	/* 0x13e8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13eb:
	/* 0x13eb: je     172e <generic_tracepoint_filter+0x172e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_172e;
	}
x86_l_13f1:
	/* 0x13f1: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_13f4:
	/* 0x13f4: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_13f7:
	/* 0x13f7: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13fc:
	/* 0x13fc: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_1402:
	/* 0x1402: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1406:
	/* 0x1406: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_140d:
	/* 0x140d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1412:
	/* 0x1412: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1414:
	/* 0x1414: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1417:
	/* 0x1417: je     172e <generic_tracepoint_filter+0x172e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_172e;
	}
x86_l_141d:
	/* 0x141d: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1420:
	/* 0x1420: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1423:
	/* 0x1423: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1428:
	/* 0x1428: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_142e:
	/* 0x142e: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1432:
	/* 0x1432: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1439:
	/* 0x1439: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_143e:
	/* 0x143e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1440:
	/* 0x1440: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1443:
	/* 0x1443: je     172e <generic_tracepoint_filter+0x172e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_172e;
	}
x86_l_1449:
	/* 0x1449: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_144c:
	/* 0x144c: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_144f:
	/* 0x144f: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1454:
	/* 0x1454: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_145a:
	/* 0x145a: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_145e:
	/* 0x145e: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1465:
	/* 0x1465: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_146a:
	/* 0x146a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_146c:
	/* 0x146c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_146f:
	/* 0x146f: je     172e <generic_tracepoint_filter+0x172e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_172e;
	}
x86_l_1475:
	/* 0x1475: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1478:
	/* 0x1478: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_147b:
	/* 0x147b: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1480:
	/* 0x1480: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_1486:
	/* 0x1486: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_148a:
	/* 0x148a: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1491:
	/* 0x1491: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1496:
	/* 0x1496: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1498:
	/* 0x1498: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_149b:
	/* 0x149b: je     172e <generic_tracepoint_filter+0x172e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_172e;
	}
x86_l_14a1:
	/* 0x14a1: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_14a4:
	/* 0x14a4: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_14a7:
	/* 0x14a7: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_14ac:
	/* 0x14ac: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_14b2:
	/* 0x14b2: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_14b6:
	/* 0x14b6: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_14bd:
	/* 0x14bd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14c2:
	/* 0x14c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c4:
	/* 0x14c4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14c7:
	/* 0x14c7: je     172e <generic_tracepoint_filter+0x172e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_172e;
	}
x86_l_14cd:
	/* 0x14cd: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_14d0:
	/* 0x14d0: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_14d3:
	/* 0x14d3: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_14d8:
	/* 0x14d8: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_14db:
	/* 0x14db: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14e0:
	/* 0x14e0: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14e5:
	/* 0x14e5: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14ea:
	/* 0x14ea: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14ef:
	/* 0x14ef: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_14f3:
	/* 0x14f3: je     1772 <generic_tracepoint_filter+0x1772> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1772;
	}
x86_l_14f9:
	/* 0x14f9: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_14fd:
	/* 0x14fd: mov    rcx,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1504:
	/* 0x1504: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1509:
	/* 0x1509: jmp    1725 <generic_tracepoint_filter+0x1725> */
	goto x86_l_1725;
x86_l_150e:
	/* 0x150e: mov    edx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1510:
	/* 0x1510: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_1513:
	/* 0x1513: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1516:
	/* 0x1516: je     1772 <generic_tracepoint_filter+0x1772> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1772;
	}
x86_l_151c:
	/* 0x151c: mov    edx,DWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_151f:
	/* 0x151f: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1522:
	/* 0x1522: je     1772 <generic_tracepoint_filter+0x1772> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1772;
	}
x86_l_1528:
	/* 0x1528: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_152c:
	/* 0x152c: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1531:
	/* 0x1531: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1536:
	/* 0x1536: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_153b:
	/* 0x153b: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_153f:
	/* 0x153f: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1546:
	/* 0x1546: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_154b:
	/* 0x154b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_154d:
	/* 0x154d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1550:
	/* 0x1550: je     172e <generic_tracepoint_filter+0x172e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_172e;
	}
x86_l_1556:
	/* 0x1556: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1559:
	/* 0x1559: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_155b:
	/* 0x155b: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1560:
	/* 0x1560: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1563:
	/* 0x1563: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_1569:
	/* 0x1569: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_156c:
	/* 0x156c: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_156f:
	/* 0x156f: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_1575:
	/* 0x1575: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1579:
	/* 0x1579: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1580:
	/* 0x1580: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1585:
	/* 0x1585: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1587:
	/* 0x1587: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_158a:
	/* 0x158a: je     172e <generic_tracepoint_filter+0x172e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_172e;
	}
x86_l_1590:
	/* 0x1590: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1593:
	/* 0x1593: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1595:
	/* 0x1595: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_159a:
	/* 0x159a: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_159d:
	/* 0x159d: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_15a3:
	/* 0x15a3: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15a6:
	/* 0x15a6: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_15a9:
	/* 0x15a9: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_15af:
	/* 0x15af: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_15b3:
	/* 0x15b3: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_15ba:
	/* 0x15ba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15bf:
	/* 0x15bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15c1:
	/* 0x15c1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15c4:
	/* 0x15c4: je     172e <generic_tracepoint_filter+0x172e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_172e;
	}
x86_l_15ca:
	/* 0x15ca: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_15cd:
	/* 0x15cd: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15cf:
	/* 0x15cf: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15d4:
	/* 0x15d4: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_15d7:
	/* 0x15d7: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_15dd:
	/* 0x15dd: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15e0:
	/* 0x15e0: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_15e3:
	/* 0x15e3: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_15e9:
	/* 0x15e9: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_15ed:
	/* 0x15ed: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_15f4:
	/* 0x15f4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15f9:
	/* 0x15f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15fb:
	/* 0x15fb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15fe:
	/* 0x15fe: je     172e <generic_tracepoint_filter+0x172e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_172e;
	}
x86_l_1604:
	/* 0x1604: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1607:
	/* 0x1607: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1609:
	/* 0x1609: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_160e:
	/* 0x160e: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_1614:
	/* 0x1614: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1617:
	/* 0x1617: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_161c:
	/* 0x161c: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_1622:
	/* 0x1622: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1626:
	/* 0x1626: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_162d:
	/* 0x162d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1632:
	/* 0x1632: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1634:
	/* 0x1634: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1637:
	/* 0x1637: je     172e <generic_tracepoint_filter+0x172e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_172e;
	}
x86_l_163d:
	/* 0x163d: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1640:
	/* 0x1640: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1642:
	/* 0x1642: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1647:
	/* 0x1647: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_164d:
	/* 0x164d: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1650:
	/* 0x1650: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1655:
	/* 0x1655: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_165b:
	/* 0x165b: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_165f:
	/* 0x165f: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1666:
	/* 0x1666: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_166b:
	/* 0x166b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_166d:
	/* 0x166d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1670:
	/* 0x1670: je     172e <generic_tracepoint_filter+0x172e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_172e;
	}
x86_l_1676:
	/* 0x1676: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1679:
	/* 0x1679: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_167b:
	/* 0x167b: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1680:
	/* 0x1680: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_1686:
	/* 0x1686: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1689:
	/* 0x1689: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_168e:
	/* 0x168e: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_1694:
	/* 0x1694: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1698:
	/* 0x1698: mov    rdi,QWORD PTR [rip+0x29f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_169f:
	/* 0x169f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16a4:
	/* 0x16a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16a6:
	/* 0x16a6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16a9:
	/* 0x16a9: je     172e <generic_tracepoint_filter+0x172e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_172e;
	}
x86_l_16af:
	/* 0x16af: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_16b2:
	/* 0x16b2: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16b4:
	/* 0x16b4: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16b9:
	/* 0x16b9: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_16bf:
	/* 0x16bf: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16c2:
	/* 0x16c2: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16c7:
	/* 0x16c7: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_16cd:
	/* 0x16cd: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_16d1:
	/* 0x16d1: mov    rdi,QWORD PTR [rip+0x29ec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_16d8:
	/* 0x16d8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16dd:
	/* 0x16dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16df:
	/* 0x16df: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16e2:
	/* 0x16e2: je     172e <generic_tracepoint_filter+0x172e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_172e;
	}
x86_l_16e4:
	/* 0x16e4: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_16e7:
	/* 0x16e7: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16e9:
	/* 0x16e9: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16ee:
	/* 0x16ee: je     1757 <generic_tracepoint_filter+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_16f0:
	/* 0x16f0: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16f3:
	/* 0x16f3: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16f8:
	/* 0x16f8: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_16fb:
	/* 0x16fb: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1700:
	/* 0x1700: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1705:
	/* 0x1705: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_170a:
	/* 0x170a: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_170f:
	/* 0x170f: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1713:
	/* 0x1713: je     1772 <generic_tracepoint_filter+0x1772> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1772;
	}
x86_l_1715:
	/* 0x1715: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1719:
	/* 0x1719: mov    rcx,QWORD PTR [rip+0x29ec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1720:
	/* 0x1720: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1725:
	/* 0x1725: mov    rdi,QWORD PTR [rip+0x29ec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_172c:
	/* 0x172c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_172e:
	/* 0x172e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1730:
	/* 0x1730: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1735:
	/* 0x1735: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_1739:
	/* 0x1739: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_173c:
	/* 0x173c: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1741:
	/* 0x1741: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1746:
	/* 0x1746: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_174b:
	/* 0x174b: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_174f:
	/* 0x174f: jne    1772 <generic_tracepoint_filter+0x1772> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1772;
	}
x86_l_1751:
	/* 0x1751: jmp    1796 <generic_tracepoint_filter+0x1796> */
	goto x86_l_1796;
x86_l_1753:
	/* 0x1753: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1755:
	/* 0x1755: jmp    1780 <generic_tracepoint_filter+0x1780> */
	goto x86_l_1780;
x86_l_1757:
	/* 0x1757: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_175a:
	/* 0x175a: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_175f:
	/* 0x175f: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1764:
	/* 0x1764: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1769:
	/* 0x1769: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_176e:
	/* 0x176e: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1772:
	/* 0x1772: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1776:
	/* 0x1776: setne  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_NE);
x86_l_1779:
	/* 0x1779: xor    bpl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_177d:
	/* 0x177d: or     bpl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1780:
	/* 0x1780: movzx  ebp,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1784:
	/* 0x1784: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1788:
	/* 0x1788: jne    1796 <generic_tracepoint_filter+0x1796> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1796;
	}
x86_l_178a:
	/* 0x178a: and    r12d,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 80ULL);
x86_l_178f:
	/* 0x178f: and    edi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_32, X86_ALU_AND);
x86_l_1791:
	/* 0x1791: and    r12d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDI, X86_WIDTH_32, X86_ALU_AND);
x86_l_1794:
	/* 0x1794: jmp    17a0 <generic_tracepoint_filter+0x17a0> */
	goto x86_l_17a0;
x86_l_1796:
	/* 0x1796: or     ebp,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 80ULL);
x86_l_179a:
	/* 0x179a: or     r12d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_179d:
	/* 0x179d: or     r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_OR);
x86_l_17a0:
	/* 0x17a0: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_17a3:
	/* 0x17a3: je     201b <generic_tracepoint_filter+0x201b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8219ULL;
	}
x86_l_17a9:
	/* 0x17a9: mov    edx,DWORD PTR [rax+r11*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 0), 8ULL);
x86_l_17ae:
	/* 0x17ae: and    edx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_17b1:
	/* 0x17b1: lea    r11d,[r8+rdx*4] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 0ULL);
x86_l_17b5:
	/* 0x17b5: mov    edx,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R11, X86_WIDTH_32);
x86_l_17b8:
	/* 0x17b8: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_17be:
	/* 0x17be: mov    edx,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_17c1:
	/* 0x17c1: lea    edi,[r11+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_17c5:
	/* 0x17c5: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_17c8:
	/* 0x17c8: je     1fe6 <generic_tracepoint_filter+0x1fe6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8166ULL;
	}
x86_l_17ce:
	/* 0x17ce: and    edi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_17d4:
	/* 0x17d4: lea    r8d,[r11+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17d8:
	/* 0x17d8: mov    r10d,DWORD PTR [rdi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_17dc:
	/* 0x17dc: mov    r9d,DWORD PTR [rdi+rax*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_17e1:
	/* 0x17e1: mov    esi,DWORD PTR [rdi+rax*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 8ULL);
x86_l_17e5:
	/* 0x17e5: cmp    esi,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 3ULL);
x86_l_17e8:
	/* 0x17e8: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17ed:
	/* 0x17ed: jbe    185f <generic_tracepoint_filter+0x185f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_185f;
	}
x86_l_17ef:
	/* 0x17ef: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17f1:
	/* 0x17f1: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_17f6:
	/* 0x17f6: mov    r12,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R11, X86_WIDTH_64);
x86_l_17f9:
	/* 0x17f9: cmp    r11d,0x3d8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 984ULL);
x86_l_1800:
	/* 0x1800: ja     180b <generic_tracepoint_filter+0x180b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_180b;
	}
x86_l_1802:
	/* 0x1802: mov    edx,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_32);
x86_l_1805:
	/* 0x1805: and    edx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1808:
	/* 0x1808: mov    edx,DWORD PTR [rax+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_180b:
	/* 0x180b: mov    r11d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R10, X86_WIDTH_32);
x86_l_180e:
	/* 0x180e: and    r11d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1812:
	/* 0x1812: cmp    r11,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_64, 9ULL);
x86_l_1816:
	/* 0x1816: ja     183b <generic_tracepoint_filter+0x183b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_183b;
	}
x86_l_1818:
	/* 0x1818: mov    r11d,DWORD PTR [r14+r11*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 2), 32ULL);
x86_l_181d:
	/* 0x181d: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_1821:
	/* 0x1821: jne    1828 <generic_tracepoint_filter+0x1828> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1828;
	}
x86_l_1823:
	/* 0x1823: cmp    edx,r11d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R11, X86_WIDTH_32);
x86_l_1826:
	/* 0x1826: jne    183b <generic_tracepoint_filter+0x183b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_183b;
	}
x86_l_1828:
	/* 0x1828: xor    edx,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_182b:
	/* 0x182b: mov    r11d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R9, X86_WIDTH_32);
x86_l_182e:
	/* 0x182e: xor    r11d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1832:
	/* 0x1832: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1834:
	/* 0x1834: or     r11d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1837:
	/* 0x1837: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_183b:
	/* 0x183b: add    r12d,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 20ULL);
x86_l_183f:
	/* 0x183f: xor    r11d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1842:
	/* 0x1842: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1847:
	/* 0x1847: cmp    r12d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1000ULL);
x86_l_184e:
	/* 0x184e: jbe    1889 <generic_tracepoint_filter+0x1889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1889;
	}
x86_l_1850:
	/* 0x1850: mov    r13d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R10, X86_WIDTH_32);
x86_l_1853:
	/* 0x1853: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1857:
	/* 0x1857: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_185b:
	/* 0x185b: jbe    189f <generic_tracepoint_filter+0x189f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_189f;
	}
x86_l_185d:
	/* 0x185d: jmp    18bf <generic_tracepoint_filter+0x18bf> */
	goto x86_l_18bf;
x86_l_185f:
	/* 0x185f: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1861:
	/* 0x1861: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1865:
	/* 0x1865: sete   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_E);
x86_l_1869:
	/* 0x1869: cmp    esi,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_186c:
	/* 0x186c: je     1a7e <generic_tracepoint_filter+0x1a7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6782ULL;
	}
x86_l_1872:
	/* 0x1872: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1875:
	/* 0x1875: je     1a5f <generic_tracepoint_filter+0x1a5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6751ULL;
	}
x86_l_187b:
	/* 0x187b: mov    r12d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_32);
x86_l_187e:
	/* 0x187e: cmp    esi,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 3ULL);
x86_l_1881:
	/* 0x1881: jne    17ef <generic_tracepoint_filter+0x17ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_17ef;
	}
x86_l_1887:
	/* 0x1887: jmp    183f <generic_tracepoint_filter+0x183f> */
	goto x86_l_183f;
x86_l_1889:
	/* 0x1889: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_188c:
	/* 0x188c: and    edx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_188f:
	/* 0x188f: mov    edx,DWORD PTR [rax+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_1892:
	/* 0x1892: mov    r13d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R10, X86_WIDTH_32);
x86_l_1895:
	/* 0x1895: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1899:
	/* 0x1899: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_189d:
	/* 0x189d: ja     18bf <generic_tracepoint_filter+0x18bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18bf;
	}
x86_l_189f:
	/* 0x189f: mov    ebp,DWORD PTR [r14+r13*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 32ULL);
x86_l_18a4:
	/* 0x18a4: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_18a8:
	/* 0x18a8: jne    18ae <generic_tracepoint_filter+0x18ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18ae;
	}
x86_l_18aa:
	/* 0x18aa: cmp    edx,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_18ac:
	/* 0x18ac: jne    18bf <generic_tracepoint_filter+0x18bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18bf;
	}
x86_l_18ae:
	/* 0x18ae: xor    edx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18b0:
	/* 0x18b0: mov    ebp,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R9, X86_WIDTH_32);
x86_l_18b3:
	/* 0x18b3: xor    ebp,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_18b6:
	/* 0x18b6: xor    r11d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18b9:
	/* 0x18b9: or     ebp,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_18bb:
	/* 0x18bb: setne  r11b */
	X86_SIM_L_EXEC_SETCC(X86_R11, X86_CC_NE);
x86_l_18bf:
	/* 0x18bf: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_18c3:
	/* 0x18c3: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18c5:
	/* 0x18c5: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_18ca:
	/* 0x18ca: cmp    r12d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1000ULL);
x86_l_18d1:
	/* 0x18d1: ja     18dc <generic_tracepoint_filter+0x18dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18dc;
	}
x86_l_18d3:
	/* 0x18d3: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_18d6:
	/* 0x18d6: and    edx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_18d9:
	/* 0x18d9: mov    edx,DWORD PTR [rax+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_18dc:
	/* 0x18dc: mov    r13d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R10, X86_WIDTH_32);
x86_l_18df:
	/* 0x18df: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_18e3:
	/* 0x18e3: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_18e7:
	/* 0x18e7: ja     190c <generic_tracepoint_filter+0x190c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_190c;
	}
x86_l_18e9:
	/* 0x18e9: mov    r13d,DWORD PTR [r14+r13*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 32ULL);
x86_l_18ee:
	/* 0x18ee: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_18f2:
	/* 0x18f2: jne    18f9 <generic_tracepoint_filter+0x18f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18f9;
	}
x86_l_18f4:
	/* 0x18f4: cmp    edx,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_18f7:
	/* 0x18f7: jne    190c <generic_tracepoint_filter+0x190c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_190c;
	}
x86_l_18f9:
	/* 0x18f9: xor    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18fc:
	/* 0x18fc: mov    r13d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_32);
x86_l_18ff:
	/* 0x18ff: xor    r13d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1903:
	/* 0x1903: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1905:
	/* 0x1905: or     r13d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1908:
	/* 0x1908: setne  bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_NE);
x86_l_190c:
	/* 0x190c: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1910:
	/* 0x1910: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1913:
	/* 0x1913: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1918:
	/* 0x1918: cmp    r12d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1000ULL);
	return 6431ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_generic_tracepoint_filter_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6431ULL: goto x86_l_191f;
	case 6433ULL: goto x86_l_1921;
	case 6437ULL: goto x86_l_1925;
	case 6441ULL: goto x86_l_1929;
	case 6445ULL: goto x86_l_192d;
	case 6449ULL: goto x86_l_1931;
	case 6451ULL: goto x86_l_1933;
	case 6456ULL: goto x86_l_1938;
	case 6460ULL: goto x86_l_193c;
	case 6462ULL: goto x86_l_193e;
	case 6465ULL: goto x86_l_1941;
	case 6468ULL: goto x86_l_1944;
	case 6470ULL: goto x86_l_1946;
	case 6473ULL: goto x86_l_1949;
	case 6476ULL: goto x86_l_194c;
	case 6480ULL: goto x86_l_1950;
	case 6483ULL: goto x86_l_1953;
	case 6486ULL: goto x86_l_1956;
	case 6490ULL: goto x86_l_195a;
	case 6494ULL: goto x86_l_195e;
	case 6496ULL: goto x86_l_1960;
	case 6499ULL: goto x86_l_1963;
	case 6502ULL: goto x86_l_1966;
	case 6504ULL: goto x86_l_1968;
	case 6506ULL: goto x86_l_196a;
	case 6509ULL: goto x86_l_196d;
	case 6511ULL: goto x86_l_196f;
	case 6514ULL: goto x86_l_1972;
	case 6516ULL: goto x86_l_1974;
	case 6522ULL: goto x86_l_197a;
	case 6525ULL: goto x86_l_197d;
	case 6527ULL: goto x86_l_197f;
	case 6530ULL: goto x86_l_1982;
	case 6533ULL: goto x86_l_1985;
	case 6538ULL: goto x86_l_198a;
	case 6541ULL: goto x86_l_198d;
	case 6543ULL: goto x86_l_198f;
	case 6549ULL: goto x86_l_1995;
	case 6551ULL: goto x86_l_1997;
	case 6557ULL: goto x86_l_199d;
	case 6560ULL: goto x86_l_19a0;
	case 6564ULL: goto x86_l_19a4;
	case 6569ULL: goto x86_l_19a9;
	case 6574ULL: goto x86_l_19ae;
	case 6578ULL: goto x86_l_19b2;
	case 6582ULL: goto x86_l_19b6;
	case 6584ULL: goto x86_l_19b8;
	case 6587ULL: goto x86_l_19bb;
	case 6592ULL: goto x86_l_19c0;
	case 6598ULL: goto x86_l_19c6;
	case 6600ULL: goto x86_l_19c8;
	case 6602ULL: goto x86_l_19ca;
	case 6605ULL: goto x86_l_19cd;
	case 6608ULL: goto x86_l_19d0;
	case 6611ULL: goto x86_l_19d3;
	case 6615ULL: goto x86_l_19d7;
	case 6619ULL: goto x86_l_19db;
	case 6621ULL: goto x86_l_19dd;
	case 6626ULL: goto x86_l_19e2;
	case 6630ULL: goto x86_l_19e6;
	case 6632ULL: goto x86_l_19e8;
	case 6635ULL: goto x86_l_19eb;
	case 6637ULL: goto x86_l_19ed;
	case 6640ULL: goto x86_l_19f0;
	case 6643ULL: goto x86_l_19f3;
	case 6647ULL: goto x86_l_19f7;
	case 6650ULL: goto x86_l_19fa;
	case 6653ULL: goto x86_l_19fd;
	case 6657ULL: goto x86_l_1a01;
	case 6660ULL: goto x86_l_1a04;
	case 6663ULL: goto x86_l_1a07;
	case 6665ULL: goto x86_l_1a09;
	case 6670ULL: goto x86_l_1a0e;
	case 6677ULL: goto x86_l_1a15;
	case 6683ULL: goto x86_l_1a1b;
	case 6686ULL: goto x86_l_1a1e;
	case 6690ULL: goto x86_l_1a22;
	case 6694ULL: goto x86_l_1a26;
	case 6700ULL: goto x86_l_1a2c;
	case 6705ULL: goto x86_l_1a31;
	case 6708ULL: goto x86_l_1a34;
	case 6712ULL: goto x86_l_1a38;
	case 6716ULL: goto x86_l_1a3c;
	case 6720ULL: goto x86_l_1a40;
	case 6726ULL: goto x86_l_1a46;
	case 6730ULL: goto x86_l_1a4a;
	case 6736ULL: goto x86_l_1a50;
	case 6739ULL: goto x86_l_1a53;
	case 6743ULL: goto x86_l_1a57;
	case 6749ULL: goto x86_l_1a5d;
	case 6751ULL: goto x86_l_1a5f;
	case 6754ULL: goto x86_l_1a62;
	case 6757ULL: goto x86_l_1a65;
	case 6759ULL: goto x86_l_1a67;
	case 6764ULL: goto x86_l_1a6c;
	case 6771ULL: goto x86_l_1a73;
	case 6777ULL: goto x86_l_1a79;
	case 6782ULL: goto x86_l_1a7e;
	case 6784ULL: goto x86_l_1a80;
	case 6787ULL: goto x86_l_1a83;
	case 6790ULL: goto x86_l_1a86;
	case 6793ULL: goto x86_l_1a89;
	case 6798ULL: goto x86_l_1a8e;
	case 6805ULL: goto x86_l_1a95;
	case 6811ULL: goto x86_l_1a9b;
	case 6816ULL: goto x86_l_1aa0;
	case 6819ULL: goto x86_l_1aa3;
	case 6822ULL: goto x86_l_1aa6;
	case 6825ULL: goto x86_l_1aa9;
	case 6828ULL: goto x86_l_1aac;
	case 6832ULL: goto x86_l_1ab0;
	case 6836ULL: goto x86_l_1ab4;
	case 6838ULL: goto x86_l_1ab6;
	case 6843ULL: goto x86_l_1abb;
	case 6847ULL: goto x86_l_1abf;
	case 6849ULL: goto x86_l_1ac1;
	case 6852ULL: goto x86_l_1ac4;
	case 6854ULL: goto x86_l_1ac6;
	case 6857ULL: goto x86_l_1ac9;
	case 6860ULL: goto x86_l_1acc;
	case 6864ULL: goto x86_l_1ad0;
	case 6866ULL: goto x86_l_1ad2;
	case 6869ULL: goto x86_l_1ad5;
	case 6873ULL: goto x86_l_1ad9;
	case 6877ULL: goto x86_l_1add;
	case 6879ULL: goto x86_l_1adf;
	case 6884ULL: goto x86_l_1ae4;
	case 6891ULL: goto x86_l_1aeb;
	case 6893ULL: goto x86_l_1aed;
	case 6896ULL: goto x86_l_1af0;
	case 6899ULL: goto x86_l_1af3;
	case 6902ULL: goto x86_l_1af6;
	case 6905ULL: goto x86_l_1af9;
	case 6909ULL: goto x86_l_1afd;
	case 6913ULL: goto x86_l_1b01;
	case 6915ULL: goto x86_l_1b03;
	case 6920ULL: goto x86_l_1b08;
	case 6924ULL: goto x86_l_1b0c;
	case 6926ULL: goto x86_l_1b0e;
	case 6929ULL: goto x86_l_1b11;
	case 6931ULL: goto x86_l_1b13;
	case 6934ULL: goto x86_l_1b16;
	case 6937ULL: goto x86_l_1b19;
	case 6941ULL: goto x86_l_1b1d;
	case 6943ULL: goto x86_l_1b1f;
	case 6946ULL: goto x86_l_1b22;
	case 6950ULL: goto x86_l_1b26;
	case 6954ULL: goto x86_l_1b2a;
	case 6957ULL: goto x86_l_1b2d;
	case 6962ULL: goto x86_l_1b32;
	case 6969ULL: goto x86_l_1b39;
	case 6971ULL: goto x86_l_1b3b;
	case 6975ULL: goto x86_l_1b3f;
	case 6979ULL: goto x86_l_1b43;
	case 6983ULL: goto x86_l_1b47;
	case 6987ULL: goto x86_l_1b4b;
	case 6989ULL: goto x86_l_1b4d;
	case 6994ULL: goto x86_l_1b52;
	case 6998ULL: goto x86_l_1b56;
	case 7000ULL: goto x86_l_1b58;
	case 7003ULL: goto x86_l_1b5b;
	case 7006ULL: goto x86_l_1b5e;
	case 7008ULL: goto x86_l_1b60;
	case 7011ULL: goto x86_l_1b63;
	case 7014ULL: goto x86_l_1b66;
	case 7018ULL: goto x86_l_1b6a;
	case 7021ULL: goto x86_l_1b6d;
	case 7024ULL: goto x86_l_1b70;
	case 7028ULL: goto x86_l_1b74;
	case 7032ULL: goto x86_l_1b78;
	case 7034ULL: goto x86_l_1b7a;
	case 7036ULL: goto x86_l_1b7c;
	case 7039ULL: goto x86_l_1b7f;
	case 7042ULL: goto x86_l_1b82;
	case 7044ULL: goto x86_l_1b84;
	case 7047ULL: goto x86_l_1b87;
	case 7050ULL: goto x86_l_1b8a;
	case 7053ULL: goto x86_l_1b8d;
	case 7055ULL: goto x86_l_1b8f;
	case 7061ULL: goto x86_l_1b95;
	case 7069ULL: goto x86_l_1b9d;
	case 7072ULL: goto x86_l_1ba0;
	case 7076ULL: goto x86_l_1ba4;
	case 7080ULL: goto x86_l_1ba8;
	case 7085ULL: goto x86_l_1bad;
	case 7088ULL: goto x86_l_1bb0;
	case 7090ULL: goto x86_l_1bb2;
	case 7096ULL: goto x86_l_1bb8;
	case 7098ULL: goto x86_l_1bba;
	case 7104ULL: goto x86_l_1bc0;
	case 7107ULL: goto x86_l_1bc3;
	case 7111ULL: goto x86_l_1bc7;
	case 7116ULL: goto x86_l_1bcc;
	case 7121ULL: goto x86_l_1bd1;
	case 7125ULL: goto x86_l_1bd5;
	case 7129ULL: goto x86_l_1bd9;
	case 7131ULL: goto x86_l_1bdb;
	case 7134ULL: goto x86_l_1bde;
	case 7139ULL: goto x86_l_1be3;
	case 7145ULL: goto x86_l_1be9;
	case 7147ULL: goto x86_l_1beb;
	case 7149ULL: goto x86_l_1bed;
	case 7152ULL: goto x86_l_1bf0;
	case 7155ULL: goto x86_l_1bf3;
	case 7158ULL: goto x86_l_1bf6;
	case 7162ULL: goto x86_l_1bfa;
	case 7166ULL: goto x86_l_1bfe;
	case 7168ULL: goto x86_l_1c00;
	case 7173ULL: goto x86_l_1c05;
	case 7177ULL: goto x86_l_1c09;
	case 7179ULL: goto x86_l_1c0b;
	case 7182ULL: goto x86_l_1c0e;
	case 7184ULL: goto x86_l_1c10;
	case 7187ULL: goto x86_l_1c13;
	case 7190ULL: goto x86_l_1c16;
	case 7194ULL: goto x86_l_1c1a;
	case 7197ULL: goto x86_l_1c1d;
	case 7200ULL: goto x86_l_1c20;
	case 7204ULL: goto x86_l_1c24;
	case 7207ULL: goto x86_l_1c27;
	case 7210ULL: goto x86_l_1c2a;
	case 7212ULL: goto x86_l_1c2c;
	case 7217ULL: goto x86_l_1c31;
	case 7224ULL: goto x86_l_1c38;
	case 7230ULL: goto x86_l_1c3e;
	case 7233ULL: goto x86_l_1c41;
	case 7237ULL: goto x86_l_1c45;
	case 7241ULL: goto x86_l_1c49;
	case 7247ULL: goto x86_l_1c4f;
	case 7252ULL: goto x86_l_1c54;
	case 7255ULL: goto x86_l_1c57;
	case 7259ULL: goto x86_l_1c5b;
	case 7263ULL: goto x86_l_1c5f;
	case 7267ULL: goto x86_l_1c63;
	case 7273ULL: goto x86_l_1c69;
	case 7277ULL: goto x86_l_1c6d;
	case 7283ULL: goto x86_l_1c73;
	case 7286ULL: goto x86_l_1c76;
	case 7290ULL: goto x86_l_1c7a;
	case 7296ULL: goto x86_l_1c80;
	case 7298ULL: goto x86_l_1c82;
	case 7301ULL: goto x86_l_1c85;
	case 7304ULL: goto x86_l_1c88;
	case 7306ULL: goto x86_l_1c8a;
	case 7311ULL: goto x86_l_1c8f;
	case 7318ULL: goto x86_l_1c96;
	case 7324ULL: goto x86_l_1c9c;
	case 7329ULL: goto x86_l_1ca1;
	case 7331ULL: goto x86_l_1ca3;
	case 7334ULL: goto x86_l_1ca6;
	case 7337ULL: goto x86_l_1ca9;
	case 7340ULL: goto x86_l_1cac;
	case 7343ULL: goto x86_l_1caf;
	case 7348ULL: goto x86_l_1cb4;
	case 7355ULL: goto x86_l_1cbb;
	case 7361ULL: goto x86_l_1cc1;
	case 7366ULL: goto x86_l_1cc6;
	case 7369ULL: goto x86_l_1cc9;
	case 7372ULL: goto x86_l_1ccc;
	case 7375ULL: goto x86_l_1ccf;
	case 7378ULL: goto x86_l_1cd2;
	case 7382ULL: goto x86_l_1cd6;
	case 7386ULL: goto x86_l_1cda;
	case 7388ULL: goto x86_l_1cdc;
	case 7393ULL: goto x86_l_1ce1;
	case 7397ULL: goto x86_l_1ce5;
	case 7399ULL: goto x86_l_1ce7;
	case 7402ULL: goto x86_l_1cea;
	case 7404ULL: goto x86_l_1cec;
	case 7407ULL: goto x86_l_1cef;
	case 7410ULL: goto x86_l_1cf2;
	case 7414ULL: goto x86_l_1cf6;
	case 7416ULL: goto x86_l_1cf8;
	case 7419ULL: goto x86_l_1cfb;
	case 7423ULL: goto x86_l_1cff;
	case 7427ULL: goto x86_l_1d03;
	case 7429ULL: goto x86_l_1d05;
	case 7434ULL: goto x86_l_1d0a;
	case 7441ULL: goto x86_l_1d11;
	case 7443ULL: goto x86_l_1d13;
	case 7446ULL: goto x86_l_1d16;
	case 7449ULL: goto x86_l_1d19;
	case 7452ULL: goto x86_l_1d1c;
	case 7455ULL: goto x86_l_1d1f;
	case 7459ULL: goto x86_l_1d23;
	case 7463ULL: goto x86_l_1d27;
	case 7465ULL: goto x86_l_1d29;
	case 7470ULL: goto x86_l_1d2e;
	case 7474ULL: goto x86_l_1d32;
	case 7476ULL: goto x86_l_1d34;
	case 7479ULL: goto x86_l_1d37;
	case 7481ULL: goto x86_l_1d39;
	case 7484ULL: goto x86_l_1d3c;
	case 7487ULL: goto x86_l_1d3f;
	case 7491ULL: goto x86_l_1d43;
	case 7493ULL: goto x86_l_1d45;
	case 7496ULL: goto x86_l_1d48;
	case 7500ULL: goto x86_l_1d4c;
	case 7504ULL: goto x86_l_1d50;
	case 7507ULL: goto x86_l_1d53;
	case 7512ULL: goto x86_l_1d58;
	case 7519ULL: goto x86_l_1d5f;
	case 7521ULL: goto x86_l_1d61;
	case 7525ULL: goto x86_l_1d65;
	case 7529ULL: goto x86_l_1d69;
	case 7533ULL: goto x86_l_1d6d;
	case 7537ULL: goto x86_l_1d71;
	case 7539ULL: goto x86_l_1d73;
	case 7544ULL: goto x86_l_1d78;
	case 7548ULL: goto x86_l_1d7c;
	case 7550ULL: goto x86_l_1d7e;
	case 7553ULL: goto x86_l_1d81;
	case 7556ULL: goto x86_l_1d84;
	case 7558ULL: goto x86_l_1d86;
	case 7561ULL: goto x86_l_1d89;
	case 7564ULL: goto x86_l_1d8c;
	case 7568ULL: goto x86_l_1d90;
	case 7571ULL: goto x86_l_1d93;
	case 7574ULL: goto x86_l_1d96;
	case 7578ULL: goto x86_l_1d9a;
	case 7582ULL: goto x86_l_1d9e;
	case 7584ULL: goto x86_l_1da0;
	case 7586ULL: goto x86_l_1da2;
	case 7589ULL: goto x86_l_1da5;
	case 7592ULL: goto x86_l_1da8;
	case 7594ULL: goto x86_l_1daa;
	case 7597ULL: goto x86_l_1dad;
	case 7600ULL: goto x86_l_1db0;
	case 7603ULL: goto x86_l_1db3;
	case 7605ULL: goto x86_l_1db5;
	case 7611ULL: goto x86_l_1dbb;
	case 7615ULL: goto x86_l_1dbf;
	case 7618ULL: goto x86_l_1dc2;
	case 7622ULL: goto x86_l_1dc6;
	case 7625ULL: goto x86_l_1dc9;
	case 7629ULL: goto x86_l_1dcd;
	case 7634ULL: goto x86_l_1dd2;
	case 7637ULL: goto x86_l_1dd5;
	case 7639ULL: goto x86_l_1dd7;
	case 7645ULL: goto x86_l_1ddd;
	case 7647ULL: goto x86_l_1ddf;
	case 7653ULL: goto x86_l_1de5;
	case 7656ULL: goto x86_l_1de8;
	case 7660ULL: goto x86_l_1dec;
	case 7665ULL: goto x86_l_1df1;
	case 7669ULL: goto x86_l_1df5;
	case 7672ULL: goto x86_l_1df8;
	case 7678ULL: goto x86_l_1dfe;
	case 7681ULL: goto x86_l_1e01;
	case 7687ULL: goto x86_l_1e07;
	case 7693ULL: goto x86_l_1e0d;
	case 7695ULL: goto x86_l_1e0f;
	case 7698ULL: goto x86_l_1e12;
	case 7702ULL: goto x86_l_1e16;
	case 7706ULL: goto x86_l_1e1a;
	case 7709ULL: goto x86_l_1e1d;
	case 7713ULL: goto x86_l_1e21;
	case 7717ULL: goto x86_l_1e25;
	case 7719ULL: goto x86_l_1e27;
	case 7724ULL: goto x86_l_1e2c;
	case 7728ULL: goto x86_l_1e30;
	case 7730ULL: goto x86_l_1e32;
	case 7733ULL: goto x86_l_1e35;
	case 7735ULL: goto x86_l_1e37;
	case 7738ULL: goto x86_l_1e3a;
	case 7741ULL: goto x86_l_1e3d;
	case 7744ULL: goto x86_l_1e40;
	case 7747ULL: goto x86_l_1e43;
	case 7750ULL: goto x86_l_1e46;
	case 7754ULL: goto x86_l_1e4a;
	case 7757ULL: goto x86_l_1e4d;
	case 7760ULL: goto x86_l_1e50;
	case 7762ULL: goto x86_l_1e52;
	case 7767ULL: goto x86_l_1e57;
	case 7774ULL: goto x86_l_1e5e;
	case 7780ULL: goto x86_l_1e64;
	case 7783ULL: goto x86_l_1e67;
	case 7787ULL: goto x86_l_1e6b;
	case 7791ULL: goto x86_l_1e6f;
	case 7797ULL: goto x86_l_1e75;
	case 7802ULL: goto x86_l_1e7a;
	case 7805ULL: goto x86_l_1e7d;
	case 7809ULL: goto x86_l_1e81;
	case 7813ULL: goto x86_l_1e85;
	default: return 0xffffffffffffffffULL;
	}
x86_l_191f:
	/* 0x191f: ja     1929 <generic_tracepoint_filter+0x1929> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1929;
	}
x86_l_1921:
	/* 0x1921: and    r12d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1925:
	/* 0x1925: mov    edx,DWORD PTR [rax+r12*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1929:
	/* 0x1929: and    r10d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_192d:
	/* 0x192d: cmp    r10,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 9ULL);
x86_l_1931:
	/* 0x1931: ja     195a <generic_tracepoint_filter+0x195a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_195a;
	}
x86_l_1933:
	/* 0x1933: mov    r10d,DWORD PTR [r14+r10*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R10, 2), 32ULL);
x86_l_1938:
	/* 0x1938: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_193c:
	/* 0x193c: jne    1946 <generic_tracepoint_filter+0x1946> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1946;
	}
x86_l_193e:
	/* 0x193e: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1941:
	/* 0x1941: cmp    edx,r10d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R10, X86_WIDTH_32);
x86_l_1944:
	/* 0x1944: jne    196a <generic_tracepoint_filter+0x196a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_196a;
	}
x86_l_1946:
	/* 0x1946: xor    edx,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1949:
	/* 0x1949: mov    r10d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R9, X86_WIDTH_32);
x86_l_194c:
	/* 0x194c: xor    r10d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1950:
	/* 0x1950: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1953:
	/* 0x1953: or     r10d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1956:
	/* 0x1956: setne  r13b */
	X86_SIM_L_EXEC_SETCC(X86_R13, X86_CC_NE);
x86_l_195a:
	/* 0x195a: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_195e:
	/* 0x195e: jne    196a <generic_tracepoint_filter+0x196a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_196a;
	}
x86_l_1960:
	/* 0x1960: and    ebp,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R11, X86_WIDTH_32, X86_ALU_AND);
x86_l_1963:
	/* 0x1963: and    edi,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_32, X86_ALU_AND);
x86_l_1966:
	/* 0x1966: and    ebp,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDI, X86_WIDTH_32, X86_ALU_AND);
x86_l_1968:
	/* 0x1968: jmp    1972 <generic_tracepoint_filter+0x1972> */
	goto x86_l_1972;
x86_l_196a:
	/* 0x196a: or     r13d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R11, X86_WIDTH_32, X86_ALU_OR);
x86_l_196d:
	/* 0x196d: or     ebp,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_196f:
	/* 0x196f: or     ebp,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_32, X86_ALU_OR);
x86_l_1972:
	/* 0x1972: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1974:
	/* 0x1974: je     201b <generic_tracepoint_filter+0x201b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8219ULL;
	}
x86_l_197a:
	/* 0x197a: shl    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_197d:
	/* 0x197d: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_197f:
	/* 0x197f: and    edi,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 28ULL);
x86_l_1982:
	/* 0x1982: add    edi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1985:
	/* 0x1985: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_198a:
	/* 0x198a: add    edx,0xfffffff0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 4294967280ULL);
x86_l_198d:
	/* 0x198d: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_198f:
	/* 0x198f: je     1fe6 <generic_tracepoint_filter+0x1fe6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8166ULL;
	}
x86_l_1995:
	/* 0x1995: mov    edx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_1997:
	/* 0x1997: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_199d:
	/* 0x199d: lea    ebp,[rdi+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_19a0:
	/* 0x19a0: mov    r12d,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_19a4:
	/* 0x19a4: mov    r11d,DWORD PTR [rdx+rax*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_19a9:
	/* 0x19a9: mov    r9d,DWORD PTR [rdx+rax*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 8ULL);
x86_l_19ae:
	/* 0x19ae: cmp    r9d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 3ULL);
x86_l_19b2:
	/* 0x19b2: mov    DWORD PTR [rsp+0x48],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_19b6:
	/* 0x19b6: jbe    1a31 <generic_tracepoint_filter+0x1a31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1a31;
	}
x86_l_19b8:
	/* 0x19b8: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19bb:
	/* 0x19bb: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_19c0:
	/* 0x19c0: cmp    edi,0x3dc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 988ULL);
x86_l_19c6:
	/* 0x19c6: ja     19d0 <generic_tracepoint_filter+0x19d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_19d0;
	}
x86_l_19c8:
	/* 0x19c8: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_19ca:
	/* 0x19ca: and    edx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_19cd:
	/* 0x19cd: mov    edx,DWORD PTR [rax+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_19d0:
	/* 0x19d0: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_19d3:
	/* 0x19d3: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_19d7:
	/* 0x19d7: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_19db:
	/* 0x19db: ja     1a01 <generic_tracepoint_filter+0x1a01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a01;
	}
x86_l_19dd:
	/* 0x19dd: mov    r8d,DWORD PTR [r14+r8*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 32ULL);
x86_l_19e2:
	/* 0x19e2: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_19e6:
	/* 0x19e6: jne    19ed <generic_tracepoint_filter+0x19ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19ed;
	}
x86_l_19e8:
	/* 0x19e8: cmp    edx,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R8, X86_WIDTH_32);
x86_l_19eb:
	/* 0x19eb: jne    1a01 <generic_tracepoint_filter+0x1a01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a01;
	}
x86_l_19ed:
	/* 0x19ed: xor    edx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19f0:
	/* 0x19f0: mov    r8d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R11, X86_WIDTH_32);
x86_l_19f3:
	/* 0x19f3: xor    r8d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_19f7:
	/* 0x19f7: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19fa:
	/* 0x19fa: or     r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_19fd:
	/* 0x19fd: setne  r10b */
	X86_SIM_L_EXEC_SETCC(X86_R10, X86_CC_NE);
x86_l_1a01:
	/* 0x1a01: add    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_1a04:
	/* 0x1a04: mov    r13d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_32);
x86_l_1a07:
	/* 0x1a07: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a09:
	/* 0x1a09: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1a0e:
	/* 0x1a0e: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1a15:
	/* 0x1a15: jbe    1aa0 <generic_tracepoint_filter+0x1aa0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1aa0;
	}
x86_l_1a1b:
	/* 0x1a1b: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1a1e:
	/* 0x1a1e: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1a22:
	/* 0x1a22: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_1a26:
	/* 0x1a26: jbe    1ab6 <generic_tracepoint_filter+0x1ab6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1ab6;
	}
x86_l_1a2c:
	/* 0x1a2c: jmp    1ad9 <generic_tracepoint_filter+0x1ad9> */
	goto x86_l_1ad9;
x86_l_1a31:
	/* 0x1a31: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a34:
	/* 0x1a34: cmp    r11d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 6ULL);
x86_l_1a38:
	/* 0x1a38: sete   r10b */
	X86_SIM_L_EXEC_SETCC(X86_R10, X86_CC_E);
x86_l_1a3c:
	/* 0x1a3c: cmp    r9d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 1ULL);
x86_l_1a40:
	/* 0x1a40: je     1ca1 <generic_tracepoint_filter+0x1ca1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ca1;
	}
x86_l_1a46:
	/* 0x1a46: cmp    r9d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 2ULL);
x86_l_1a4a:
	/* 0x1a4a: je     1c82 <generic_tracepoint_filter+0x1c82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c82;
	}
x86_l_1a50:
	/* 0x1a50: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_1a53:
	/* 0x1a53: cmp    r9d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 3ULL);
x86_l_1a57:
	/* 0x1a57: jne    19b8 <generic_tracepoint_filter+0x19b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19b8;
	}
x86_l_1a5d:
	/* 0x1a5d: jmp    1a07 <generic_tracepoint_filter+0x1a07> */
	goto x86_l_1a07;
x86_l_1a5f:
	/* 0x1a5f: mov    r11d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RDI, X86_WIDTH_32);
x86_l_1a62:
	/* 0x1a62: mov    r12d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_32);
x86_l_1a65:
	/* 0x1a65: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a67:
	/* 0x1a67: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1a6c:
	/* 0x1a6c: cmp    r12d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1000ULL);
x86_l_1a73:
	/* 0x1a73: jbe    18d3 <generic_tracepoint_filter+0x18d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 6355ULL;
	}
x86_l_1a79:
	/* 0x1a79: jmp    18dc <generic_tracepoint_filter+0x18dc> */
	return 6364ULL;
x86_l_1a7e:
	/* 0x1a7e: mov    ebp,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_32);
x86_l_1a80:
	/* 0x1a80: mov    r11d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RDI, X86_WIDTH_32);
x86_l_1a83:
	/* 0x1a83: mov    r12d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_32);
x86_l_1a86:
	/* 0x1a86: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a89:
	/* 0x1a89: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1a8e:
	/* 0x1a8e: cmp    r12d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1000ULL);
x86_l_1a95:
	/* 0x1a95: jbe    1921 <generic_tracepoint_filter+0x1921> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1921;
	}
x86_l_1a9b:
	/* 0x1a9b: jmp    1929 <generic_tracepoint_filter+0x1929> */
	goto x86_l_1929;
x86_l_1aa0:
	/* 0x1aa0: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_1aa3:
	/* 0x1aa3: and    edx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1aa6:
	/* 0x1aa6: mov    edx,DWORD PTR [rax+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_1aa9:
	/* 0x1aa9: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1aac:
	/* 0x1aac: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1ab0:
	/* 0x1ab0: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_1ab4:
	/* 0x1ab4: ja     1ad9 <generic_tracepoint_filter+0x1ad9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ad9;
	}
x86_l_1ab6:
	/* 0x1ab6: mov    r8d,DWORD PTR [r14+r8*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 32ULL);
x86_l_1abb:
	/* 0x1abb: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1abf:
	/* 0x1abf: jne    1ac6 <generic_tracepoint_filter+0x1ac6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ac6;
	}
x86_l_1ac1:
	/* 0x1ac1: cmp    edx,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R8, X86_WIDTH_32);
x86_l_1ac4:
	/* 0x1ac4: jne    1ad9 <generic_tracepoint_filter+0x1ad9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ad9;
	}
x86_l_1ac6:
	/* 0x1ac6: xor    edx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ac9:
	/* 0x1ac9: mov    r8d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R11, X86_WIDTH_32);
x86_l_1acc:
	/* 0x1acc: xor    r8d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1ad0:
	/* 0x1ad0: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ad2:
	/* 0x1ad2: or     r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1ad5:
	/* 0x1ad5: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_1ad9:
	/* 0x1ad9: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1add:
	/* 0x1add: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1adf:
	/* 0x1adf: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1ae4:
	/* 0x1ae4: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1aeb:
	/* 0x1aeb: ja     1af6 <generic_tracepoint_filter+0x1af6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1af6;
	}
x86_l_1aed:
	/* 0x1aed: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_1af0:
	/* 0x1af0: and    edx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1af3:
	/* 0x1af3: mov    edx,DWORD PTR [rax+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_1af6:
	/* 0x1af6: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1af9:
	/* 0x1af9: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1afd:
	/* 0x1afd: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_1b01:
	/* 0x1b01: ja     1b26 <generic_tracepoint_filter+0x1b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b26;
	}
x86_l_1b03:
	/* 0x1b03: mov    r8d,DWORD PTR [r14+r8*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 32ULL);
x86_l_1b08:
	/* 0x1b08: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1b0c:
	/* 0x1b0c: jne    1b13 <generic_tracepoint_filter+0x1b13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b13;
	}
x86_l_1b0e:
	/* 0x1b0e: cmp    edx,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R8, X86_WIDTH_32);
x86_l_1b11:
	/* 0x1b11: jne    1b26 <generic_tracepoint_filter+0x1b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b26;
	}
x86_l_1b13:
	/* 0x1b13: xor    edx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b16:
	/* 0x1b16: mov    r8d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R11, X86_WIDTH_32);
x86_l_1b19:
	/* 0x1b19: xor    r8d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1b1d:
	/* 0x1b1d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b1f:
	/* 0x1b1f: or     r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1b22:
	/* 0x1b22: setne  bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_NE);
x86_l_1b26:
	/* 0x1b26: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1b2a:
	/* 0x1b2a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b2d:
	/* 0x1b2d: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1b32:
	/* 0x1b32: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1b39:
	/* 0x1b39: ja     1b43 <generic_tracepoint_filter+0x1b43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b43;
	}
x86_l_1b3b:
	/* 0x1b3b: and    r13d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1b3f:
	/* 0x1b3f: mov    edx,DWORD PTR [rax+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1b43:
	/* 0x1b43: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1b47:
	/* 0x1b47: cmp    r12,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 9ULL);
x86_l_1b4b:
	/* 0x1b4b: ja     1b74 <generic_tracepoint_filter+0x1b74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b74;
	}
x86_l_1b4d:
	/* 0x1b4d: mov    r12d,DWORD PTR [r14+r12*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 32ULL);
x86_l_1b52:
	/* 0x1b52: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1b56:
	/* 0x1b56: jne    1b60 <generic_tracepoint_filter+0x1b60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b60;
	}
x86_l_1b58:
	/* 0x1b58: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b5b:
	/* 0x1b5b: cmp    edx,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_1b5e:
	/* 0x1b5e: jne    1b84 <generic_tracepoint_filter+0x1b84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b84;
	}
x86_l_1b60:
	/* 0x1b60: xor    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b63:
	/* 0x1b63: mov    r12d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R11, X86_WIDTH_32);
x86_l_1b66:
	/* 0x1b66: xor    r12d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1b6a:
	/* 0x1b6a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b6d:
	/* 0x1b6d: or     r12d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1b70:
	/* 0x1b70: setne  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_NE);
x86_l_1b74:
	/* 0x1b74: cmp    r11d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 6ULL);
x86_l_1b78:
	/* 0x1b78: jne    1b84 <generic_tracepoint_filter+0x1b84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b84;
	}
x86_l_1b7a:
	/* 0x1b7a: and    ebp,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDI, X86_WIDTH_32, X86_ALU_AND);
x86_l_1b7c:
	/* 0x1b7c: and    r10d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R8, X86_WIDTH_32, X86_ALU_AND);
x86_l_1b7f:
	/* 0x1b7f: and    ebp,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R10, X86_WIDTH_32, X86_ALU_AND);
x86_l_1b82:
	/* 0x1b82: jmp    1b8d <generic_tracepoint_filter+0x1b8d> */
	goto x86_l_1b8d;
x86_l_1b84:
	/* 0x1b84: or     r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_1b87:
	/* 0x1b87: or     ebp,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R10, X86_WIDTH_32, X86_ALU_OR);
x86_l_1b8a:
	/* 0x1b8a: or     ebp,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_32, X86_ALU_OR);
x86_l_1b8d:
	/* 0x1b8d: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1b8f:
	/* 0x1b8f: je     201b <generic_tracepoint_filter+0x201b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8219ULL;
	}
x86_l_1b95:
	/* 0x1b95: lea    edi,[r9*4+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 2), 0ULL);
x86_l_1b9d:
	/* 0x1b9d: and    edi,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 28ULL);
x86_l_1ba0:
	/* 0x1ba0: add    edi,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_1ba4:
	/* 0x1ba4: lea    esi,[rsi+r9*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 2), 0ULL);
x86_l_1ba8:
	/* 0x1ba8: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bad:
	/* 0x1bad: add    edx,0xffffffe4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 4294967268ULL);
x86_l_1bb0:
	/* 0x1bb0: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1bb2:
	/* 0x1bb2: je     1fe6 <generic_tracepoint_filter+0x1fe6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8166ULL;
	}
x86_l_1bb8:
	/* 0x1bb8: mov    edx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_1bba:
	/* 0x1bba: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1bc0:
	/* 0x1bc0: lea    ebp,[rdi+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1bc3:
	/* 0x1bc3: mov    r12d,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1bc7:
	/* 0x1bc7: mov    r11d,DWORD PTR [rdx+rax*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_1bcc:
	/* 0x1bcc: mov    r9d,DWORD PTR [rdx+rax*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 8ULL);
x86_l_1bd1:
	/* 0x1bd1: cmp    r9d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 3ULL);
x86_l_1bd5:
	/* 0x1bd5: mov    DWORD PTR [rsp+0x48],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1bd9:
	/* 0x1bd9: jbe    1c54 <generic_tracepoint_filter+0x1c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1c54;
	}
x86_l_1bdb:
	/* 0x1bdb: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bde:
	/* 0x1bde: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1be3:
	/* 0x1be3: cmp    edi,0x3dc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 988ULL);
x86_l_1be9:
	/* 0x1be9: ja     1bf3 <generic_tracepoint_filter+0x1bf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1bf3;
	}
x86_l_1beb:
	/* 0x1beb: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1bed:
	/* 0x1bed: and    edx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1bf0:
	/* 0x1bf0: mov    edx,DWORD PTR [rax+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_1bf3:
	/* 0x1bf3: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1bf6:
	/* 0x1bf6: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1bfa:
	/* 0x1bfa: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_1bfe:
	/* 0x1bfe: ja     1c24 <generic_tracepoint_filter+0x1c24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1c24;
	}
x86_l_1c00:
	/* 0x1c00: mov    r8d,DWORD PTR [r14+r8*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 32ULL);
x86_l_1c05:
	/* 0x1c05: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1c09:
	/* 0x1c09: jne    1c10 <generic_tracepoint_filter+0x1c10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c10;
	}
x86_l_1c0b:
	/* 0x1c0b: cmp    edx,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R8, X86_WIDTH_32);
x86_l_1c0e:
	/* 0x1c0e: jne    1c24 <generic_tracepoint_filter+0x1c24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c24;
	}
x86_l_1c10:
	/* 0x1c10: xor    edx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c13:
	/* 0x1c13: mov    r8d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R11, X86_WIDTH_32);
x86_l_1c16:
	/* 0x1c16: xor    r8d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1c1a:
	/* 0x1c1a: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c1d:
	/* 0x1c1d: or     r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1c20:
	/* 0x1c20: setne  r10b */
	X86_SIM_L_EXEC_SETCC(X86_R10, X86_CC_NE);
x86_l_1c24:
	/* 0x1c24: add    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_1c27:
	/* 0x1c27: mov    r13d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_32);
x86_l_1c2a:
	/* 0x1c2a: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c2c:
	/* 0x1c2c: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1c31:
	/* 0x1c31: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1c38:
	/* 0x1c38: jbe    1cc6 <generic_tracepoint_filter+0x1cc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1cc6;
	}
x86_l_1c3e:
	/* 0x1c3e: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1c41:
	/* 0x1c41: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1c45:
	/* 0x1c45: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_1c49:
	/* 0x1c49: jbe    1cdc <generic_tracepoint_filter+0x1cdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1cdc;
	}
x86_l_1c4f:
	/* 0x1c4f: jmp    1cff <generic_tracepoint_filter+0x1cff> */
	goto x86_l_1cff;
x86_l_1c54:
	/* 0x1c54: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c57:
	/* 0x1c57: cmp    r11d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 6ULL);
x86_l_1c5b:
	/* 0x1c5b: sete   r10b */
	X86_SIM_L_EXEC_SETCC(X86_R10, X86_CC_E);
x86_l_1c5f:
	/* 0x1c5f: cmp    r9d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 1ULL);
x86_l_1c63:
	/* 0x1c63: je     1ec4 <generic_tracepoint_filter+0x1ec4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7876ULL;
	}
x86_l_1c69:
	/* 0x1c69: cmp    r9d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 2ULL);
x86_l_1c6d:
	/* 0x1c6d: je     1ea5 <generic_tracepoint_filter+0x1ea5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7845ULL;
	}
x86_l_1c73:
	/* 0x1c73: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_1c76:
	/* 0x1c76: cmp    r9d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 3ULL);
x86_l_1c7a:
	/* 0x1c7a: jne    1bdb <generic_tracepoint_filter+0x1bdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bdb;
	}
x86_l_1c80:
	/* 0x1c80: jmp    1c2a <generic_tracepoint_filter+0x1c2a> */
	goto x86_l_1c2a;
x86_l_1c82:
	/* 0x1c82: mov    edi,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R10, X86_WIDTH_32);
x86_l_1c85:
	/* 0x1c85: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_1c88:
	/* 0x1c88: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c8a:
	/* 0x1c8a: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1c8f:
	/* 0x1c8f: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1c96:
	/* 0x1c96: jbe    1aed <generic_tracepoint_filter+0x1aed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1aed;
	}
x86_l_1c9c:
	/* 0x1c9c: jmp    1af6 <generic_tracepoint_filter+0x1af6> */
	goto x86_l_1af6;
x86_l_1ca1:
	/* 0x1ca1: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1ca3:
	/* 0x1ca3: mov    ebp,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R10, X86_WIDTH_32);
x86_l_1ca6:
	/* 0x1ca6: mov    edi,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R10, X86_WIDTH_32);
x86_l_1ca9:
	/* 0x1ca9: mov    r13d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_32);
x86_l_1cac:
	/* 0x1cac: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1caf:
	/* 0x1caf: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1cb4:
	/* 0x1cb4: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1cbb:
	/* 0x1cbb: jbe    1b3b <generic_tracepoint_filter+0x1b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1b3b;
	}
x86_l_1cc1:
	/* 0x1cc1: jmp    1b43 <generic_tracepoint_filter+0x1b43> */
	goto x86_l_1b43;
x86_l_1cc6:
	/* 0x1cc6: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_1cc9:
	/* 0x1cc9: and    edx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1ccc:
	/* 0x1ccc: mov    edx,DWORD PTR [rax+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_1ccf:
	/* 0x1ccf: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1cd2:
	/* 0x1cd2: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1cd6:
	/* 0x1cd6: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_1cda:
	/* 0x1cda: ja     1cff <generic_tracepoint_filter+0x1cff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1cff;
	}
x86_l_1cdc:
	/* 0x1cdc: mov    r8d,DWORD PTR [r14+r8*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 32ULL);
x86_l_1ce1:
	/* 0x1ce1: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1ce5:
	/* 0x1ce5: jne    1cec <generic_tracepoint_filter+0x1cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1cec;
	}
x86_l_1ce7:
	/* 0x1ce7: cmp    edx,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R8, X86_WIDTH_32);
x86_l_1cea:
	/* 0x1cea: jne    1cff <generic_tracepoint_filter+0x1cff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1cff;
	}
x86_l_1cec:
	/* 0x1cec: xor    edx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cef:
	/* 0x1cef: mov    r8d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R11, X86_WIDTH_32);
x86_l_1cf2:
	/* 0x1cf2: xor    r8d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1cf6:
	/* 0x1cf6: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cf8:
	/* 0x1cf8: or     r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1cfb:
	/* 0x1cfb: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_1cff:
	/* 0x1cff: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1d03:
	/* 0x1d03: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d05:
	/* 0x1d05: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1d0a:
	/* 0x1d0a: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1d11:
	/* 0x1d11: ja     1d1c <generic_tracepoint_filter+0x1d1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d1c;
	}
x86_l_1d13:
	/* 0x1d13: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_1d16:
	/* 0x1d16: and    edx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1d19:
	/* 0x1d19: mov    edx,DWORD PTR [rax+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_1d1c:
	/* 0x1d1c: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1d1f:
	/* 0x1d1f: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1d23:
	/* 0x1d23: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_1d27:
	/* 0x1d27: ja     1d4c <generic_tracepoint_filter+0x1d4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d4c;
	}
x86_l_1d29:
	/* 0x1d29: mov    r8d,DWORD PTR [r14+r8*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 32ULL);
x86_l_1d2e:
	/* 0x1d2e: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1d32:
	/* 0x1d32: jne    1d39 <generic_tracepoint_filter+0x1d39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d39;
	}
x86_l_1d34:
	/* 0x1d34: cmp    edx,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R8, X86_WIDTH_32);
x86_l_1d37:
	/* 0x1d37: jne    1d4c <generic_tracepoint_filter+0x1d4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d4c;
	}
x86_l_1d39:
	/* 0x1d39: xor    edx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d3c:
	/* 0x1d3c: mov    r8d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R11, X86_WIDTH_32);
x86_l_1d3f:
	/* 0x1d3f: xor    r8d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1d43:
	/* 0x1d43: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d45:
	/* 0x1d45: or     r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1d48:
	/* 0x1d48: setne  bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_NE);
x86_l_1d4c:
	/* 0x1d4c: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1d50:
	/* 0x1d50: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d53:
	/* 0x1d53: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1d58:
	/* 0x1d58: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1d5f:
	/* 0x1d5f: ja     1d69 <generic_tracepoint_filter+0x1d69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d69;
	}
x86_l_1d61:
	/* 0x1d61: and    r13d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1d65:
	/* 0x1d65: mov    edx,DWORD PTR [rax+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1d69:
	/* 0x1d69: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1d6d:
	/* 0x1d6d: cmp    r12,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 9ULL);
x86_l_1d71:
	/* 0x1d71: ja     1d9a <generic_tracepoint_filter+0x1d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d9a;
	}
x86_l_1d73:
	/* 0x1d73: mov    r12d,DWORD PTR [r14+r12*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 32ULL);
x86_l_1d78:
	/* 0x1d78: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1d7c:
	/* 0x1d7c: jne    1d86 <generic_tracepoint_filter+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d86;
	}
x86_l_1d7e:
	/* 0x1d7e: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d81:
	/* 0x1d81: cmp    edx,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_1d84:
	/* 0x1d84: jne    1daa <generic_tracepoint_filter+0x1daa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1daa;
	}
x86_l_1d86:
	/* 0x1d86: xor    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d89:
	/* 0x1d89: mov    r12d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R11, X86_WIDTH_32);
x86_l_1d8c:
	/* 0x1d8c: xor    r12d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1d90:
	/* 0x1d90: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d93:
	/* 0x1d93: or     r12d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1d96:
	/* 0x1d96: setne  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_NE);
x86_l_1d9a:
	/* 0x1d9a: cmp    r11d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 6ULL);
x86_l_1d9e:
	/* 0x1d9e: jne    1daa <generic_tracepoint_filter+0x1daa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1daa;
	}
x86_l_1da0:
	/* 0x1da0: and    ebp,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDI, X86_WIDTH_32, X86_ALU_AND);
x86_l_1da2:
	/* 0x1da2: and    r10d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R8, X86_WIDTH_32, X86_ALU_AND);
x86_l_1da5:
	/* 0x1da5: and    ebp,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R10, X86_WIDTH_32, X86_ALU_AND);
x86_l_1da8:
	/* 0x1da8: jmp    1db3 <generic_tracepoint_filter+0x1db3> */
	goto x86_l_1db3;
x86_l_1daa:
	/* 0x1daa: or     r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_1dad:
	/* 0x1dad: or     ebp,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R10, X86_WIDTH_32, X86_ALU_OR);
x86_l_1db0:
	/* 0x1db0: or     ebp,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_32, X86_ALU_OR);
x86_l_1db3:
	/* 0x1db3: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1db5:
	/* 0x1db5: je     201b <generic_tracepoint_filter+0x201b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8219ULL;
	}
x86_l_1dbb:
	/* 0x1dbb: shl    r9d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_1dbf:
	/* 0x1dbf: add    esi,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1dc2:
	/* 0x1dc2: and    r9d,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_AND, 28ULL);
x86_l_1dc6:
	/* 0x1dc6: mov    edi,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R9, X86_WIDTH_32);
x86_l_1dc9:
	/* 0x1dc9: add    edi,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_1dcd:
	/* 0x1dcd: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dd2:
	/* 0x1dd2: add    edx,0xffffffd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 4294967256ULL);
x86_l_1dd5:
	/* 0x1dd5: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1dd7:
	/* 0x1dd7: je     1fe6 <generic_tracepoint_filter+0x1fe6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8166ULL;
	}
x86_l_1ddd:
	/* 0x1ddd: mov    esi,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_1ddf:
	/* 0x1ddf: and    esi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1de5:
	/* 0x1de5: lea    edx,[rdi+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1de8:
	/* 0x1de8: mov    r10d,DWORD PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1dec:
	/* 0x1dec: mov    r9d,DWORD PTR [rsi+rax*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_1df1:
	/* 0x1df1: mov    esi,DWORD PTR [rsi+rax*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 8ULL);
x86_l_1df5:
	/* 0x1df5: cmp    esi,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 3ULL);
x86_l_1df8:
	/* 0x1df8: jbe    1e7a <generic_tracepoint_filter+0x1e7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e7a;
	}
x86_l_1dfe:
	/* 0x1dfe: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e01:
	/* 0x1e01: mov    r11d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_32, 0ULL);
x86_l_1e07:
	/* 0x1e07: cmp    edi,0x3dc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 988ULL);
x86_l_1e0d:
	/* 0x1e0d: ja     1e1a <generic_tracepoint_filter+0x1e1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e1a;
	}
x86_l_1e0f:
	/* 0x1e0f: mov    r11d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RDX, X86_WIDTH_32);
x86_l_1e12:
	/* 0x1e12: and    r11d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1e16:
	/* 0x1e16: mov    r11d,DWORD PTR [rax+r11*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_1e1a:
	/* 0x1e1a: mov    r12d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R10, X86_WIDTH_32);
x86_l_1e1d:
	/* 0x1e1d: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1e21:
	/* 0x1e21: cmp    r12,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 9ULL);
x86_l_1e25:
	/* 0x1e25: ja     1e4a <generic_tracepoint_filter+0x1e4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e4a;
	}
x86_l_1e27:
	/* 0x1e27: mov    ebp,DWORD PTR [r14+r12*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 32ULL);
x86_l_1e2c:
	/* 0x1e2c: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_1e30:
	/* 0x1e30: jne    1e37 <generic_tracepoint_filter+0x1e37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e37;
	}
x86_l_1e32:
	/* 0x1e32: cmp    r11d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R11, X86_RBP, X86_WIDTH_32);
x86_l_1e35:
	/* 0x1e35: jne    1e4a <generic_tracepoint_filter+0x1e4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e4a;
	}
x86_l_1e37:
	/* 0x1e37: xor    r11d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e3a:
	/* 0x1e3a: mov    ebp,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R9, X86_WIDTH_32);
x86_l_1e3d:
	/* 0x1e3d: xor    ebp,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1e40:
	/* 0x1e40: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e43:
	/* 0x1e43: or     ebp,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R11, X86_WIDTH_32, X86_ALU_OR);
x86_l_1e46:
	/* 0x1e46: setne  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_NE);
x86_l_1e4a:
	/* 0x1e4a: add    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_1e4d:
	/* 0x1e4d: mov    r11d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RDI, X86_WIDTH_32);
x86_l_1e50:
	/* 0x1e50: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e52:
	/* 0x1e52: mov    ebp,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 0ULL);
x86_l_1e57:
	/* 0x1e57: cmp    r11d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 1000ULL);
x86_l_1e5e:
	/* 0x1e5e: jbe    1ee9 <generic_tracepoint_filter+0x1ee9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 7913ULL;
	}
x86_l_1e64:
	/* 0x1e64: mov    r12d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R10, X86_WIDTH_32);
x86_l_1e67:
	/* 0x1e67: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1e6b:
	/* 0x1e6b: cmp    r12,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 9ULL);
x86_l_1e6f:
	/* 0x1e6f: jbe    1f01 <generic_tracepoint_filter+0x1f01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 7937ULL;
	}
x86_l_1e75:
	/* 0x1e75: jmp    1f24 <generic_tracepoint_filter+0x1f24> */
	return 7972ULL;
x86_l_1e7a:
	/* 0x1e7a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e7d:
	/* 0x1e7d: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1e81:
	/* 0x1e81: sete   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_E);
x86_l_1e85:
	/* 0x1e85: cmp    esi,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 1ULL);
	return 7816ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_generic_tracepoint_filter_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7816ULL: goto x86_l_1e88;
	case 7822ULL: goto x86_l_1e8e;
	case 7825ULL: goto x86_l_1e91;
	case 7831ULL: goto x86_l_1e97;
	case 7834ULL: goto x86_l_1e9a;
	case 7837ULL: goto x86_l_1e9d;
	case 7843ULL: goto x86_l_1ea3;
	case 7845ULL: goto x86_l_1ea5;
	case 7848ULL: goto x86_l_1ea8;
	case 7851ULL: goto x86_l_1eab;
	case 7853ULL: goto x86_l_1ead;
	case 7858ULL: goto x86_l_1eb2;
	case 7865ULL: goto x86_l_1eb9;
	case 7871ULL: goto x86_l_1ebf;
	case 7876ULL: goto x86_l_1ec4;
	case 7878ULL: goto x86_l_1ec6;
	case 7881ULL: goto x86_l_1ec9;
	case 7884ULL: goto x86_l_1ecc;
	case 7887ULL: goto x86_l_1ecf;
	case 7890ULL: goto x86_l_1ed2;
	case 7895ULL: goto x86_l_1ed7;
	case 7902ULL: goto x86_l_1ede;
	case 7908ULL: goto x86_l_1ee4;
	case 7913ULL: goto x86_l_1ee9;
	case 7916ULL: goto x86_l_1eec;
	case 7920ULL: goto x86_l_1ef0;
	case 7924ULL: goto x86_l_1ef4;
	case 7927ULL: goto x86_l_1ef7;
	case 7931ULL: goto x86_l_1efb;
	case 7935ULL: goto x86_l_1eff;
	case 7937ULL: goto x86_l_1f01;
	case 7942ULL: goto x86_l_1f06;
	case 7946ULL: goto x86_l_1f0a;
	case 7948ULL: goto x86_l_1f0c;
	case 7951ULL: goto x86_l_1f0f;
	case 7953ULL: goto x86_l_1f11;
	case 7956ULL: goto x86_l_1f14;
	case 7959ULL: goto x86_l_1f17;
	case 7963ULL: goto x86_l_1f1b;
	case 7965ULL: goto x86_l_1f1d;
	case 7968ULL: goto x86_l_1f20;
	case 7972ULL: goto x86_l_1f24;
	case 7976ULL: goto x86_l_1f28;
	case 7978ULL: goto x86_l_1f2a;
	case 7984ULL: goto x86_l_1f30;
	case 7991ULL: goto x86_l_1f37;
	case 7993ULL: goto x86_l_1f39;
	case 7996ULL: goto x86_l_1f3c;
	case 8000ULL: goto x86_l_1f40;
	case 8004ULL: goto x86_l_1f44;
	case 8007ULL: goto x86_l_1f47;
	case 8011ULL: goto x86_l_1f4b;
	case 8015ULL: goto x86_l_1f4f;
	case 8017ULL: goto x86_l_1f51;
	case 8022ULL: goto x86_l_1f56;
	case 8026ULL: goto x86_l_1f5a;
	case 8028ULL: goto x86_l_1f5c;
	case 8031ULL: goto x86_l_1f5f;
	case 8033ULL: goto x86_l_1f61;
	case 8036ULL: goto x86_l_1f64;
	case 8039ULL: goto x86_l_1f67;
	case 8043ULL: goto x86_l_1f6b;
	case 8045ULL: goto x86_l_1f6d;
	case 8048ULL: goto x86_l_1f70;
	case 8052ULL: goto x86_l_1f74;
	case 8056ULL: goto x86_l_1f78;
	case 8059ULL: goto x86_l_1f7b;
	case 8065ULL: goto x86_l_1f81;
	case 8072ULL: goto x86_l_1f88;
	case 8074ULL: goto x86_l_1f8a;
	case 8078ULL: goto x86_l_1f8e;
	case 8082ULL: goto x86_l_1f92;
	case 8086ULL: goto x86_l_1f96;
	case 8090ULL: goto x86_l_1f9a;
	case 8092ULL: goto x86_l_1f9c;
	case 8097ULL: goto x86_l_1fa1;
	case 8101ULL: goto x86_l_1fa5;
	case 8103ULL: goto x86_l_1fa7;
	case 8106ULL: goto x86_l_1faa;
	case 8109ULL: goto x86_l_1fad;
	case 8111ULL: goto x86_l_1faf;
	case 8114ULL: goto x86_l_1fb2;
	case 8117ULL: goto x86_l_1fb5;
	case 8121ULL: goto x86_l_1fb9;
	case 8124ULL: goto x86_l_1fbc;
	case 8127ULL: goto x86_l_1fbf;
	case 8131ULL: goto x86_l_1fc3;
	case 8135ULL: goto x86_l_1fc7;
	case 8137ULL: goto x86_l_1fc9;
	case 8139ULL: goto x86_l_1fcb;
	case 8142ULL: goto x86_l_1fce;
	case 8145ULL: goto x86_l_1fd1;
	case 8147ULL: goto x86_l_1fd3;
	case 8150ULL: goto x86_l_1fd6;
	case 8153ULL: goto x86_l_1fd9;
	case 8156ULL: goto x86_l_1fdc;
	case 8158ULL: goto x86_l_1fde;
	case 8160ULL: goto x86_l_1fe0;
	case 8163ULL: goto x86_l_1fe3;
	case 8166ULL: goto x86_l_1fe6;
	case 8168ULL: goto x86_l_1fe8;
	case 8174ULL: goto x86_l_1fee;
	case 8178ULL: goto x86_l_1ff2;
	case 8184ULL: goto x86_l_1ff8;
	case 8191ULL: goto x86_l_1fff;
	case 8194ULL: goto x86_l_2002;
	case 8203ULL: goto x86_l_200b;
	case 8211ULL: goto x86_l_2013;
	case 8219ULL: goto x86_l_201b;
	case 8226ULL: goto x86_l_2022;
	case 8229ULL: goto x86_l_2025;
	case 8236ULL: goto x86_l_202c;
	case 8239ULL: goto x86_l_202f;
	case 8241ULL: goto x86_l_2031;
	case 8243ULL: goto x86_l_2033;
	case 8247ULL: goto x86_l_2037;
	case 8251ULL: goto x86_l_203b;
	case 8255ULL: goto x86_l_203f;
	case 8263ULL: goto x86_l_2047;
	case 8265ULL: goto x86_l_2049;
	case 8272ULL: goto x86_l_2050;
	case 8277ULL: goto x86_l_2055;
	case 8282ULL: goto x86_l_205a;
	case 8285ULL: goto x86_l_205d;
	case 8290ULL: goto x86_l_2062;
	case 8292ULL: goto x86_l_2064;
	case 8294ULL: goto x86_l_2066;
	case 8298ULL: goto x86_l_206a;
	case 8299ULL: goto x86_l_206b;
	case 8301ULL: goto x86_l_206d;
	case 8303ULL: goto x86_l_206f;
	case 8305ULL: goto x86_l_2071;
	case 8307ULL: goto x86_l_2073;
	case 8308ULL: goto x86_l_2074;
	case 8313ULL: goto x86_l_2079;
	case 8320ULL: goto x86_l_2080;
	case 8325ULL: goto x86_l_2085;
	case 8330ULL: goto x86_l_208a;
	case 8333ULL: goto x86_l_208d;
	case 8338ULL: goto x86_l_2092;
	case 8340ULL: goto x86_l_2094;
	case 8343ULL: goto x86_l_2097;
	case 8349ULL: goto x86_l_209d;
	case 8352ULL: goto x86_l_20a0;
	case 8356ULL: goto x86_l_20a4;
	case 8361ULL: goto x86_l_20a9;
	case 8366ULL: goto x86_l_20ae;
	case 8369ULL: goto x86_l_20b1;
	case 8371ULL: goto x86_l_20b3;
	case 8374ULL: goto x86_l_20b6;
	case 8380ULL: goto x86_l_20bc;
	case 8384ULL: goto x86_l_20c0;
	case 8386ULL: goto x86_l_20c2;
	case 8391ULL: goto x86_l_20c7;
	case 8394ULL: goto x86_l_20ca;
	case 8400ULL: goto x86_l_20d0;
	case 8402ULL: goto x86_l_20d2;
	case 8405ULL: goto x86_l_20d5;
	case 8410ULL: goto x86_l_20da;
	case 8414ULL: goto x86_l_20de;
	case 8418ULL: goto x86_l_20e2;
	case 8421ULL: goto x86_l_20e5;
	case 8425ULL: goto x86_l_20e9;
	case 8428ULL: goto x86_l_20ec;
	case 8434ULL: goto x86_l_20f2;
	case 8439ULL: goto x86_l_20f7;
	case 8442ULL: goto x86_l_20fa;
	case 8445ULL: goto x86_l_20fd;
	case 8447ULL: goto x86_l_20ff;
	case 8453ULL: goto x86_l_2105;
	case 8460ULL: goto x86_l_210c;
	case 8466ULL: goto x86_l_2112;
	case 8471ULL: goto x86_l_2117;
	case 8474ULL: goto x86_l_211a;
	case 8477ULL: goto x86_l_211d;
	case 8480ULL: goto x86_l_2120;
	case 8483ULL: goto x86_l_2123;
	case 8489ULL: goto x86_l_2129;
	case 8496ULL: goto x86_l_2130;
	case 8502ULL: goto x86_l_2136;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1e88:
	/* 0x1e88: je     2117 <generic_tracepoint_filter+0x2117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2117;
	}
x86_l_1e8e:
	/* 0x1e8e: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1e91:
	/* 0x1e91: je     20f7 <generic_tracepoint_filter+0x20f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20f7;
	}
x86_l_1e97:
	/* 0x1e97: mov    r11d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RDX, X86_WIDTH_32);
x86_l_1e9a:
	/* 0x1e9a: cmp    esi,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 3ULL);
x86_l_1e9d:
	/* 0x1e9d: jne    1dfe <generic_tracepoint_filter+0x1dfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7678ULL;
	}
x86_l_1ea3:
	/* 0x1ea3: jmp    1e50 <generic_tracepoint_filter+0x1e50> */
	return 7760ULL;
x86_l_1ea5:
	/* 0x1ea5: mov    edi,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R10, X86_WIDTH_32);
x86_l_1ea8:
	/* 0x1ea8: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_1eab:
	/* 0x1eab: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ead:
	/* 0x1ead: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1eb2:
	/* 0x1eb2: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1eb9:
	/* 0x1eb9: jbe    1d13 <generic_tracepoint_filter+0x1d13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 7443ULL;
	}
x86_l_1ebf:
	/* 0x1ebf: jmp    1d1c <generic_tracepoint_filter+0x1d1c> */
	return 7452ULL;
x86_l_1ec4:
	/* 0x1ec4: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1ec6:
	/* 0x1ec6: mov    ebp,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R10, X86_WIDTH_32);
x86_l_1ec9:
	/* 0x1ec9: mov    edi,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R10, X86_WIDTH_32);
x86_l_1ecc:
	/* 0x1ecc: mov    r13d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_32);
x86_l_1ecf:
	/* 0x1ecf: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ed2:
	/* 0x1ed2: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1ed7:
	/* 0x1ed7: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1ede:
	/* 0x1ede: jbe    1d61 <generic_tracepoint_filter+0x1d61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 7521ULL;
	}
x86_l_1ee4:
	/* 0x1ee4: jmp    1d69 <generic_tracepoint_filter+0x1d69> */
	return 7529ULL;
x86_l_1ee9:
	/* 0x1ee9: mov    r12d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R11, X86_WIDTH_32);
x86_l_1eec:
	/* 0x1eec: and    r12d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1ef0:
	/* 0x1ef0: mov    ebp,DWORD PTR [rax+r12*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1ef4:
	/* 0x1ef4: mov    r12d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R10, X86_WIDTH_32);
x86_l_1ef7:
	/* 0x1ef7: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1efb:
	/* 0x1efb: cmp    r12,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 9ULL);
x86_l_1eff:
	/* 0x1eff: ja     1f24 <generic_tracepoint_filter+0x1f24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f24;
	}
x86_l_1f01:
	/* 0x1f01: mov    r12d,DWORD PTR [r14+r12*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 32ULL);
x86_l_1f06:
	/* 0x1f06: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_1f0a:
	/* 0x1f0a: jne    1f11 <generic_tracepoint_filter+0x1f11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f11;
	}
x86_l_1f0c:
	/* 0x1f0c: cmp    ebp,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R12, X86_WIDTH_32);
x86_l_1f0f:
	/* 0x1f0f: jne    1f24 <generic_tracepoint_filter+0x1f24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f24;
	}
x86_l_1f11:
	/* 0x1f11: xor    ebp,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f14:
	/* 0x1f14: mov    r12d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R9, X86_WIDTH_32);
x86_l_1f17:
	/* 0x1f17: xor    r12d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1f1b:
	/* 0x1f1b: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f1d:
	/* 0x1f1d: or     r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_OR);
x86_l_1f20:
	/* 0x1f20: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_1f24:
	/* 0x1f24: add    r11d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1f28:
	/* 0x1f28: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f2a:
	/* 0x1f2a: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_1f30:
	/* 0x1f30: cmp    r11d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 1000ULL);
x86_l_1f37:
	/* 0x1f37: ja     1f44 <generic_tracepoint_filter+0x1f44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f44;
	}
x86_l_1f39:
	/* 0x1f39: mov    r12d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R11, X86_WIDTH_32);
x86_l_1f3c:
	/* 0x1f3c: and    r12d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1f40:
	/* 0x1f40: mov    r12d,DWORD PTR [rax+r12*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1f44:
	/* 0x1f44: mov    r13d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R10, X86_WIDTH_32);
x86_l_1f47:
	/* 0x1f47: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1f4b:
	/* 0x1f4b: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_1f4f:
	/* 0x1f4f: ja     1f74 <generic_tracepoint_filter+0x1f74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f74;
	}
x86_l_1f51:
	/* 0x1f51: mov    r13d,DWORD PTR [r14+r13*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 32ULL);
x86_l_1f56:
	/* 0x1f56: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_1f5a:
	/* 0x1f5a: jne    1f61 <generic_tracepoint_filter+0x1f61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f61;
	}
x86_l_1f5c:
	/* 0x1f5c: cmp    r12d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R13, X86_WIDTH_32);
x86_l_1f5f:
	/* 0x1f5f: jne    1f74 <generic_tracepoint_filter+0x1f74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f74;
	}
x86_l_1f61:
	/* 0x1f61: xor    r12d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f64:
	/* 0x1f64: mov    r13d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_32);
x86_l_1f67:
	/* 0x1f67: xor    r13d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1f6b:
	/* 0x1f6b: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f6d:
	/* 0x1f6d: or     r13d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_32, X86_ALU_OR);
x86_l_1f70:
	/* 0x1f70: setne  bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_NE);
x86_l_1f74:
	/* 0x1f74: add    r11d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1f78:
	/* 0x1f78: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f7b:
	/* 0x1f7b: mov    r13d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 0ULL);
x86_l_1f81:
	/* 0x1f81: cmp    r11d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 1000ULL);
x86_l_1f88:
	/* 0x1f88: ja     1f92 <generic_tracepoint_filter+0x1f92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f92;
	}
x86_l_1f8a:
	/* 0x1f8a: and    r11d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1f8e:
	/* 0x1f8e: mov    r13d,DWORD PTR [rax+r11*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_1f92:
	/* 0x1f92: and    r10d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1f96:
	/* 0x1f96: cmp    r10,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 9ULL);
x86_l_1f9a:
	/* 0x1f9a: ja     1fc3 <generic_tracepoint_filter+0x1fc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1fc3;
	}
x86_l_1f9c:
	/* 0x1f9c: mov    r10d,DWORD PTR [r14+r10*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R10, 2), 32ULL);
x86_l_1fa1:
	/* 0x1fa1: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_1fa5:
	/* 0x1fa5: jne    1faf <generic_tracepoint_filter+0x1faf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1faf;
	}
x86_l_1fa7:
	/* 0x1fa7: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1faa:
	/* 0x1faa: cmp    r13d,r10d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R10, X86_WIDTH_32);
x86_l_1fad:
	/* 0x1fad: jne    1fd3 <generic_tracepoint_filter+0x1fd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fd3;
	}
x86_l_1faf:
	/* 0x1faf: xor    r13d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fb2:
	/* 0x1fb2: mov    r10d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R9, X86_WIDTH_32);
x86_l_1fb5:
	/* 0x1fb5: xor    r10d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1fb9:
	/* 0x1fb9: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fbc:
	/* 0x1fbc: or     r10d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R13, X86_WIDTH_32, X86_ALU_OR);
x86_l_1fbf:
	/* 0x1fbf: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_1fc3:
	/* 0x1fc3: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1fc7:
	/* 0x1fc7: jne    1fd3 <generic_tracepoint_filter+0x1fd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fd3;
	}
x86_l_1fc9:
	/* 0x1fc9: and    ebp,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDI, X86_WIDTH_32, X86_ALU_AND);
x86_l_1fcb:
	/* 0x1fcb: and    r8d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R12, X86_WIDTH_32, X86_ALU_AND);
x86_l_1fce:
	/* 0x1fce: and    ebp,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_32, X86_ALU_AND);
x86_l_1fd1:
	/* 0x1fd1: jmp    1fdc <generic_tracepoint_filter+0x1fdc> */
	goto x86_l_1fdc;
x86_l_1fd3:
	/* 0x1fd3: or     r12d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_1fd6:
	/* 0x1fd6: or     ebp,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_32, X86_ALU_OR);
x86_l_1fd9:
	/* 0x1fd9: or     ebp,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_32, X86_ALU_OR);
x86_l_1fdc:
	/* 0x1fdc: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1fde:
	/* 0x1fde: je     201b <generic_tracepoint_filter+0x201b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_201b;
	}
x86_l_1fe0:
	/* 0x1fe0: and    esi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1fe3:
	/* 0x1fe3: lea    edi,[rdx+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1fe6:
	/* 0x1fe6: mov    edx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_1fe8:
	/* 0x1fe8: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1fee:
	/* 0x1fee: cmp    DWORD PTR [rdx+rax*1],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_1ff2:
	/* 0x1ff2: jne    2094 <generic_tracepoint_filter+0x2094> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2094;
	}
x86_l_1ff8:
	/* 0x1ff8: mov    rax,QWORD PTR [r14+0x5eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24248ULL);
x86_l_1fff:
	/* 0x1fff: and    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 31ULL);
x86_l_2002:
	/* 0x2002: mov    BYTE PTR [r14+rax*1+0x5ec1],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 104183021699073ULL);
x86_l_200b:
	/* 0x200b: mov    BYTE PTR [r14+0x5ee0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685249ULL);
x86_l_2013:
	/* 0x2013: mov    BYTE PTR [r14+0x5ec0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731777ULL);
x86_l_201b:
	/* 0x201b: mov    rax,QWORD PTR [r14+0x5eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24248ULL);
x86_l_2022:
	/* 0x2022: inc    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2025:
	/* 0x2025: mov    QWORD PTR [r14+0x5eb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24248ULL);
x86_l_202c:
	/* 0x202c: cmp    rax,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_202f:
	/* 0x202f: jbe    2079 <generic_tracepoint_filter+0x2079> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2079;
	}
x86_l_2031:
	/* 0x2031: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2033:
	/* 0x2033: mov    DWORD PTR [r14+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2037:
	/* 0x2037: mov    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_203b:
	/* 0x203b: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_203f:
	/* 0x203f: cmp    BYTE PTR [r14+0x5ec0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731776ULL);
x86_l_2047:
	/* 0x2047: je     2064 <generic_tracepoint_filter+0x2064> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2064;
	}
x86_l_2049:
	/* 0x2049: mov    rsi,QWORD PTR [rip+0x29e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tp_calls)));
x86_l_2050:
	/* 0x2050: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2055:
	/* 0x2055: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_205a:
	/* 0x205a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_205d:
	/* 0x205d: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2062:
	/* 0x2062: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2064:
	/* 0x2064: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2066:
	/* 0x2066: add    rsp,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_206a:
	/* 0x206a: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_206b:
	/* 0x206b: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_206d:
	/* 0x206d: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_206f:
	/* 0x206f: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2071:
	/* 0x2071: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2073:
	/* 0x2073: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2074:
	/* 0x2074: jmp    213b <generic_tracepoint_filter+0x213b> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2079:
	/* 0x2079: mov    rsi,QWORD PTR [rip+0x29e4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tp_calls)));
x86_l_2080:
	/* 0x2080: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2085:
	/* 0x2085: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_208a:
	/* 0x208a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_208d:
	/* 0x208d: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2092:
	/* 0x2092: jmp    2062 <generic_tracepoint_filter+0x2062> */
	goto x86_l_2062;
x86_l_2094:
	/* 0x2094: add    edi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2097:
	/* 0x2097: and    edi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_209d:
	/* 0x209d: mov    esi,DWORD PTR [rdi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_20a0:
	/* 0x20a0: mov    edx,DWORD PTR [rdi+rax*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_20a4:
	/* 0x20a4: mov    r8d,DWORD PTR [rdi+rax*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 8ULL);
x86_l_20a9:
	/* 0x20a9: mov    rax,QWORD PTR [rdi+rax*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 12ULL);
x86_l_20ae:
	/* 0x20ae: test   r8d,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_32);
x86_l_20b1:
	/* 0x20b1: je     20c7 <generic_tracepoint_filter+0x20c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20c7;
	}
x86_l_20b3:
	/* 0x20b3: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_20b6:
	/* 0x20b6: ja     201b <generic_tracepoint_filter+0x201b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_201b;
	}
x86_l_20bc:
	/* 0x20bc: cmp    DWORD PTR [r14+0x44],r8d */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R14, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_20c0:
	/* 0x20c0: jne    20d0 <generic_tracepoint_filter+0x20d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_20d0;
	}
x86_l_20c2:
	/* 0x20c2: jmp    201b <generic_tracepoint_filter+0x201b> */
	goto x86_l_201b;
x86_l_20c7:
	/* 0x20c7: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_20ca:
	/* 0x20ca: ja     201b <generic_tracepoint_filter+0x201b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_201b;
	}
x86_l_20d0:
	/* 0x20d0: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20d2:
	/* 0x20d2: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20d5:
	/* 0x20d5: test   QWORD PTR [r14+rsi*8+0x48],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 3), 72ULL);
x86_l_20da:
	/* 0x20da: sete   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_E);
x86_l_20de:
	/* 0x20de: setne  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_NE);
x86_l_20e2:
	/* 0x20e2: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_20e5:
	/* 0x20e5: cmove  r8d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDI, X86_WIDTH_32, X86_CC_E);
x86_l_20e9:
	/* 0x20e9: test   r8b,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_8);
x86_l_20ec:
	/* 0x20ec: je     1ff8 <generic_tracepoint_filter+0x1ff8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ff8;
	}
x86_l_20f2:
	/* 0x20f2: jmp    201b <generic_tracepoint_filter+0x201b> */
	goto x86_l_201b;
x86_l_20f7:
	/* 0x20f7: mov    edi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R8, X86_WIDTH_32);
x86_l_20fa:
	/* 0x20fa: mov    r11d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RDX, X86_WIDTH_32);
x86_l_20fd:
	/* 0x20fd: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20ff:
	/* 0x20ff: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_2105:
	/* 0x2105: cmp    r11d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 1000ULL);
x86_l_210c:
	/* 0x210c: jbe    1f39 <generic_tracepoint_filter+0x1f39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1f39;
	}
x86_l_2112:
	/* 0x2112: jmp    1f44 <generic_tracepoint_filter+0x1f44> */
	goto x86_l_1f44;
x86_l_2117:
	/* 0x2117: mov    ebp,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_32);
x86_l_211a:
	/* 0x211a: mov    edi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R8, X86_WIDTH_32);
x86_l_211d:
	/* 0x211d: mov    r11d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RDX, X86_WIDTH_32);
x86_l_2120:
	/* 0x2120: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2123:
	/* 0x2123: mov    r13d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 0ULL);
x86_l_2129:
	/* 0x2129: cmp    r11d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 1000ULL);
x86_l_2130:
	/* 0x2130: jbe    1f8a <generic_tracepoint_filter+0x1f8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1f8a;
	}
x86_l_2136:
	/* 0x2136: jmp    1f92 <generic_tracepoint_filter+0x1f92> */
	goto x86_l_1f92;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_tracepoint_generic_tracepoint_filter_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 8400U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1630ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_generic_tracepoint_filter_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1636ULL && __x86_pc <= 3265ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_generic_tracepoint_filter_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3270ULL && __x86_pc <= 4881ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_generic_tracepoint_filter_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4885ULL && __x86_pc <= 6424ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_generic_tracepoint_filter_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6431ULL && __x86_pc <= 7813ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_generic_tracepoint_filter_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 7816ULL && __x86_pc <= 8502ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_generic_tracepoint_filter_x86_chunk_5(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

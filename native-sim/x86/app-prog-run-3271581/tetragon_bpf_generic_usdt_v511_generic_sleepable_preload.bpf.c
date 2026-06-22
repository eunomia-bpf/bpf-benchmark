extern char CONFIG_ITER_NUM;
extern char config_map;
extern char heap_ro_zero;
extern char sleepable_preload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_0(
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
	case 33ULL: goto x86_l_21;
	case 40ULL: goto x86_l_28;
	case 48ULL: goto x86_l_30;
	case 53ULL: goto x86_l_35;
	case 55ULL: goto x86_l_37;
	case 58ULL: goto x86_l_3a;
	case 64ULL: goto x86_l_40;
	case 67ULL: goto x86_l_43;
	case 74ULL: goto x86_l_4a;
	case 79ULL: goto x86_l_4f;
	case 86ULL: goto x86_l_56;
	case 91ULL: goto x86_l_5b;
	case 98ULL: goto x86_l_62;
	case 103ULL: goto x86_l_67;
	case 107ULL: goto x86_l_6b;
	case 115ULL: goto x86_l_73;
	case 119ULL: goto x86_l_77;
	case 124ULL: goto x86_l_7c;
	case 128ULL: goto x86_l_80;
	case 136ULL: goto x86_l_88;
	case 140ULL: goto x86_l_8c;
	case 145ULL: goto x86_l_91;
	case 149ULL: goto x86_l_95;
	case 157ULL: goto x86_l_9d;
	case 161ULL: goto x86_l_a1;
	case 166ULL: goto x86_l_a6;
	case 170ULL: goto x86_l_aa;
	case 178ULL: goto x86_l_b2;
	case 182ULL: goto x86_l_b6;
	case 187ULL: goto x86_l_bb;
	case 191ULL: goto x86_l_bf;
	case 199ULL: goto x86_l_c7;
	case 203ULL: goto x86_l_cb;
	case 208ULL: goto x86_l_d0;
	case 212ULL: goto x86_l_d4;
	case 220ULL: goto x86_l_dc;
	case 224ULL: goto x86_l_e0;
	case 229ULL: goto x86_l_e5;
	case 232ULL: goto x86_l_e8;
	case 236ULL: goto x86_l_ec;
	case 244ULL: goto x86_l_f4;
	case 248ULL: goto x86_l_f8;
	case 253ULL: goto x86_l_fd;
	case 258ULL: goto x86_l_102;
	case 264ULL: goto x86_l_108;
	case 268ULL: goto x86_l_10c;
	case 271ULL: goto x86_l_10f;
	case 278ULL: goto x86_l_116;
	case 284ULL: goto x86_l_11c;
	case 289ULL: goto x86_l_121;
	case 291ULL: goto x86_l_123;
	case 294ULL: goto x86_l_126;
	case 299ULL: goto x86_l_12b;
	case 304ULL: goto x86_l_130;
	case 308ULL: goto x86_l_134;
	case 312ULL: goto x86_l_138;
	case 316ULL: goto x86_l_13c;
	case 323ULL: goto x86_l_143;
	case 329ULL: goto x86_l_149;
	case 333ULL: goto x86_l_14d;
	case 338ULL: goto x86_l_152;
	case 340ULL: goto x86_l_154;
	case 342ULL: goto x86_l_156;
	case 344ULL: goto x86_l_158;
	case 348ULL: goto x86_l_15c;
	case 351ULL: goto x86_l_15f;
	case 357ULL: goto x86_l_165;
	case 360ULL: goto x86_l_168;
	case 366ULL: goto x86_l_16e;
	case 371ULL: goto x86_l_173;
	case 374ULL: goto x86_l_176;
	case 380ULL: goto x86_l_17c;
	case 383ULL: goto x86_l_17f;
	case 389ULL: goto x86_l_185;
	case 394ULL: goto x86_l_18a;
	case 399ULL: goto x86_l_18f;
	case 404ULL: goto x86_l_194;
	case 407ULL: goto x86_l_197;
	case 412ULL: goto x86_l_19c;
	case 414ULL: goto x86_l_19e;
	case 416ULL: goto x86_l_1a0;
	case 422ULL: goto x86_l_1a6;
	case 424ULL: goto x86_l_1a8;
	case 429ULL: goto x86_l_1ad;
	case 437ULL: goto x86_l_1b5;
	case 445ULL: goto x86_l_1bd;
	case 451ULL: goto x86_l_1c3;
	case 454ULL: goto x86_l_1c6;
	case 460ULL: goto x86_l_1cc;
	case 463ULL: goto x86_l_1cf;
	case 469ULL: goto x86_l_1d5;
	case 472ULL: goto x86_l_1d8;
	case 478ULL: goto x86_l_1de;
	case 486ULL: goto x86_l_1e6;
	case 489ULL: goto x86_l_1e9;
	case 495ULL: goto x86_l_1ef;
	case 500ULL: goto x86_l_1f4;
	case 503ULL: goto x86_l_1f7;
	case 509ULL: goto x86_l_1fd;
	case 514ULL: goto x86_l_202;
	case 517ULL: goto x86_l_205;
	case 523ULL: goto x86_l_20b;
	case 528ULL: goto x86_l_210;
	case 533ULL: goto x86_l_215;
	case 536ULL: goto x86_l_218;
	case 542ULL: goto x86_l_21e;
	case 547ULL: goto x86_l_223;
	case 550ULL: goto x86_l_226;
	case 556ULL: goto x86_l_22c;
	case 559ULL: goto x86_l_22f;
	case 565ULL: goto x86_l_235;
	case 570ULL: goto x86_l_23a;
	case 573ULL: goto x86_l_23d;
	case 578ULL: goto x86_l_242;
	case 583ULL: goto x86_l_247;
	case 586ULL: goto x86_l_24a;
	case 591ULL: goto x86_l_24f;
	case 593ULL: goto x86_l_251;
	case 595ULL: goto x86_l_253;
	case 601ULL: goto x86_l_259;
	case 604ULL: goto x86_l_25c;
	case 610ULL: goto x86_l_262;
	case 613ULL: goto x86_l_265;
	case 618ULL: goto x86_l_26a;
	case 623ULL: goto x86_l_26f;
	case 629ULL: goto x86_l_275;
	case 634ULL: goto x86_l_27a;
	case 636ULL: goto x86_l_27c;
	case 638ULL: goto x86_l_27e;
	case 644ULL: goto x86_l_284;
	case 648ULL: goto x86_l_288;
	case 655ULL: goto x86_l_28f;
	case 658ULL: goto x86_l_292;
	case 663ULL: goto x86_l_297;
	case 666ULL: goto x86_l_29a;
	case 671ULL: goto x86_l_29f;
	case 675ULL: goto x86_l_2a3;
	case 682ULL: goto x86_l_2aa;
	case 685ULL: goto x86_l_2ad;
	case 690ULL: goto x86_l_2b2;
	case 693ULL: goto x86_l_2b5;
	case 698ULL: goto x86_l_2ba;
	case 701ULL: goto x86_l_2bd;
	case 703ULL: goto x86_l_2bf;
	case 706ULL: goto x86_l_2c2;
	case 712ULL: goto x86_l_2c8;
	case 717ULL: goto x86_l_2cd;
	case 719ULL: goto x86_l_2cf;
	case 725ULL: goto x86_l_2d5;
	case 730ULL: goto x86_l_2da;
	case 735ULL: goto x86_l_2df;
	case 738ULL: goto x86_l_2e2;
	case 744ULL: goto x86_l_2e8;
	case 749ULL: goto x86_l_2ed;
	case 752ULL: goto x86_l_2f0;
	case 758ULL: goto x86_l_2f6;
	case 766ULL: goto x86_l_2fe;
	case 769ULL: goto x86_l_301;
	case 775ULL: goto x86_l_307;
	case 780ULL: goto x86_l_30c;
	case 785ULL: goto x86_l_311;
	case 788ULL: goto x86_l_314;
	case 794ULL: goto x86_l_31a;
	case 799ULL: goto x86_l_31f;
	case 802ULL: goto x86_l_322;
	case 808ULL: goto x86_l_328;
	case 816ULL: goto x86_l_330;
	case 819ULL: goto x86_l_333;
	case 825ULL: goto x86_l_339;
	case 830ULL: goto x86_l_33e;
	case 835ULL: goto x86_l_343;
	case 838ULL: goto x86_l_346;
	case 844ULL: goto x86_l_34c;
	case 849ULL: goto x86_l_351;
	case 852ULL: goto x86_l_354;
	case 857ULL: goto x86_l_359;
	case 861ULL: goto x86_l_35d;
	case 868ULL: goto x86_l_364;
	case 872ULL: goto x86_l_368;
	case 877ULL: goto x86_l_36d;
	case 882ULL: goto x86_l_372;
	case 886ULL: goto x86_l_376;
	case 888ULL: goto x86_l_378;
	case 891ULL: goto x86_l_37b;
	case 897ULL: goto x86_l_381;
	case 902ULL: goto x86_l_386;
	case 907ULL: goto x86_l_38b;
	case 913ULL: goto x86_l_391;
	case 916ULL: goto x86_l_394;
	case 921ULL: goto x86_l_399;
	case 923ULL: goto x86_l_39b;
	case 925ULL: goto x86_l_39d;
	case 927ULL: goto x86_l_39f;
	case 932ULL: goto x86_l_3a4;
	case 935ULL: goto x86_l_3a7;
	case 940ULL: goto x86_l_3ac;
	case 945ULL: goto x86_l_3b1;
	case 948ULL: goto x86_l_3b4;
	case 951ULL: goto x86_l_3b7;
	case 956ULL: goto x86_l_3bc;
	case 958ULL: goto x86_l_3be;
	case 960ULL: goto x86_l_3c0;
	case 962ULL: goto x86_l_3c2;
	case 965ULL: goto x86_l_3c5;
	case 970ULL: goto x86_l_3ca;
	case 973ULL: goto x86_l_3cd;
	case 975ULL: goto x86_l_3cf;
	case 979ULL: goto x86_l_3d3;
	case 986ULL: goto x86_l_3da;
	case 992ULL: goto x86_l_3e0;
	case 999ULL: goto x86_l_3e7;
	case 1002ULL: goto x86_l_3ea;
	case 1007ULL: goto x86_l_3ef;
	case 1010ULL: goto x86_l_3f2;
	case 1015ULL: goto x86_l_3f7;
	case 1021ULL: goto x86_l_3fd;
	case 1023ULL: goto x86_l_3ff;
	case 1028ULL: goto x86_l_404;
	case 1034ULL: goto x86_l_40a;
	case 1037ULL: goto x86_l_40d;
	case 1039ULL: goto x86_l_40f;
	case 1044ULL: goto x86_l_414;
	case 1049ULL: goto x86_l_419;
	case 1054ULL: goto x86_l_41e;
	case 1059ULL: goto x86_l_423;
	case 1061ULL: goto x86_l_425;
	case 1063ULL: goto x86_l_427;
	case 1069ULL: goto x86_l_42d;
	case 1076ULL: goto x86_l_434;
	case 1082ULL: goto x86_l_43a;
	case 1087ULL: goto x86_l_43f;
	case 1092ULL: goto x86_l_444;
	case 1097ULL: goto x86_l_449;
	case 1104ULL: goto x86_l_450;
	case 1106ULL: goto x86_l_452;
	case 1111ULL: goto x86_l_457;
	case 1116ULL: goto x86_l_45c;
	case 1121ULL: goto x86_l_461;
	case 1126ULL: goto x86_l_466;
	case 1128ULL: goto x86_l_468;
	case 1130ULL: goto x86_l_46a;
	case 1136ULL: goto x86_l_470;
	case 1143ULL: goto x86_l_477;
	case 1149ULL: goto x86_l_47d;
	case 1154ULL: goto x86_l_482;
	case 1159ULL: goto x86_l_487;
	case 1164ULL: goto x86_l_48c;
	case 1171ULL: goto x86_l_493;
	case 1173ULL: goto x86_l_495;
	case 1178ULL: goto x86_l_49a;
	case 1183ULL: goto x86_l_49f;
	case 1188ULL: goto x86_l_4a4;
	case 1193ULL: goto x86_l_4a9;
	case 1195ULL: goto x86_l_4ab;
	case 1197ULL: goto x86_l_4ad;
	case 1203ULL: goto x86_l_4b3;
	case 1210ULL: goto x86_l_4ba;
	case 1216ULL: goto x86_l_4c0;
	case 1221ULL: goto x86_l_4c5;
	case 1226ULL: goto x86_l_4ca;
	case 1231ULL: goto x86_l_4cf;
	case 1238ULL: goto x86_l_4d6;
	case 1240ULL: goto x86_l_4d8;
	case 1245ULL: goto x86_l_4dd;
	case 1250ULL: goto x86_l_4e2;
	case 1255ULL: goto x86_l_4e7;
	case 1260ULL: goto x86_l_4ec;
	case 1262ULL: goto x86_l_4ee;
	case 1264ULL: goto x86_l_4f0;
	case 1270ULL: goto x86_l_4f6;
	case 1277ULL: goto x86_l_4fd;
	case 1283ULL: goto x86_l_503;
	case 1288ULL: goto x86_l_508;
	case 1293ULL: goto x86_l_50d;
	case 1298ULL: goto x86_l_512;
	case 1305ULL: goto x86_l_519;
	case 1307ULL: goto x86_l_51b;
	case 1312ULL: goto x86_l_520;
	case 1317ULL: goto x86_l_525;
	case 1322ULL: goto x86_l_52a;
	case 1327ULL: goto x86_l_52f;
	case 1329ULL: goto x86_l_531;
	case 1331ULL: goto x86_l_533;
	case 1337ULL: goto x86_l_539;
	case 1344ULL: goto x86_l_540;
	case 1350ULL: goto x86_l_546;
	case 1355ULL: goto x86_l_54b;
	case 1360ULL: goto x86_l_550;
	case 1365ULL: goto x86_l_555;
	case 1372ULL: goto x86_l_55c;
	case 1374ULL: goto x86_l_55e;
	case 1379ULL: goto x86_l_563;
	case 1384ULL: goto x86_l_568;
	case 1389ULL: goto x86_l_56d;
	case 1394ULL: goto x86_l_572;
	case 1396ULL: goto x86_l_574;
	case 1398ULL: goto x86_l_576;
	case 1404ULL: goto x86_l_57c;
	case 1411ULL: goto x86_l_583;
	case 1417ULL: goto x86_l_589;
	case 1422ULL: goto x86_l_58e;
	case 1427ULL: goto x86_l_593;
	case 1432ULL: goto x86_l_598;
	case 1439ULL: goto x86_l_59f;
	case 1441ULL: goto x86_l_5a1;
	case 1446ULL: goto x86_l_5a6;
	case 1451ULL: goto x86_l_5ab;
	case 1456ULL: goto x86_l_5b0;
	case 1461ULL: goto x86_l_5b5;
	case 1463ULL: goto x86_l_5b7;
	case 1465ULL: goto x86_l_5b9;
	case 1471ULL: goto x86_l_5bf;
	case 1478ULL: goto x86_l_5c6;
	case 1484ULL: goto x86_l_5cc;
	case 1489ULL: goto x86_l_5d1;
	case 1494ULL: goto x86_l_5d6;
	case 1499ULL: goto x86_l_5db;
	case 1506ULL: goto x86_l_5e2;
	case 1508ULL: goto x86_l_5e4;
	case 1513ULL: goto x86_l_5e9;
	case 1518ULL: goto x86_l_5ee;
	case 1523ULL: goto x86_l_5f3;
	case 1528ULL: goto x86_l_5f8;
	case 1530ULL: goto x86_l_5fa;
	case 1532ULL: goto x86_l_5fc;
	case 1538ULL: goto x86_l_602;
	case 1545ULL: goto x86_l_609;
	case 1551ULL: goto x86_l_60f;
	case 1556ULL: goto x86_l_614;
	case 1561ULL: goto x86_l_619;
	case 1566ULL: goto x86_l_61e;
	case 1573ULL: goto x86_l_625;
	case 1575ULL: goto x86_l_627;
	case 1580ULL: goto x86_l_62c;
	case 1585ULL: goto x86_l_631;
	case 1590ULL: goto x86_l_636;
	case 1595ULL: goto x86_l_63b;
	case 1597ULL: goto x86_l_63d;
	case 1599ULL: goto x86_l_63f;
	case 1605ULL: goto x86_l_645;
	case 1612ULL: goto x86_l_64c;
	case 1618ULL: goto x86_l_652;
	case 1623ULL: goto x86_l_657;
	case 1628ULL: goto x86_l_65c;
	case 1633ULL: goto x86_l_661;
	case 1640ULL: goto x86_l_668;
	case 1646ULL: goto x86_l_66e;
	case 1651ULL: goto x86_l_673;
	case 1656ULL: goto x86_l_678;
	case 1661ULL: goto x86_l_67d;
	case 1666ULL: goto x86_l_682;
	case 1671ULL: goto x86_l_687;
	case 1674ULL: goto x86_l_68a;
	case 1676ULL: goto x86_l_68c;
	case 1681ULL: goto x86_l_691;
	case 1686ULL: goto x86_l_696;
	case 1691ULL: goto x86_l_69b;
	case 1696ULL: goto x86_l_6a0;
	case 1698ULL: goto x86_l_6a2;
	case 1700ULL: goto x86_l_6a4;
	case 1706ULL: goto x86_l_6aa;
	case 1713ULL: goto x86_l_6b1;
	case 1719ULL: goto x86_l_6b7;
	case 1724ULL: goto x86_l_6bc;
	case 1729ULL: goto x86_l_6c1;
	case 1734ULL: goto x86_l_6c6;
	case 1741ULL: goto x86_l_6cd;
	case 1743ULL: goto x86_l_6cf;
	case 1748ULL: goto x86_l_6d4;
	case 1753ULL: goto x86_l_6d9;
	case 1758ULL: goto x86_l_6de;
	case 1763ULL: goto x86_l_6e3;
	case 1765ULL: goto x86_l_6e5;
	case 1767ULL: goto x86_l_6e7;
	case 1773ULL: goto x86_l_6ed;
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
	/* 0x11: mov    QWORD PTR [rsp+0x30],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16:
	/* 0x16: mov    DWORD PTR [rsp+0xc4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_21:
	/* 0x21: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_28:
	/* 0x28: lea    rsi,[rsp+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_30:
	/* 0x30: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35:
	/* 0x35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37:
	/* 0x37: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: je     11f5 <generic_sleepable_preload+0x11f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4597ULL;
	}
x86_l_40:
	/* 0x40: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_43:
	/* 0x43: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_4a:
	/* 0x4a: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4f:
	/* 0x4f: lea    rcx,[r15+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_56:
	/* 0x56: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5b:
	/* 0x5b: lea    rcx,[r15+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_62:
	/* 0x62: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_67:
	/* 0x67: lea    rcx,[r15+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6b:
	/* 0x6b: mov    QWORD PTR [rsp+0xb0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_73:
	/* 0x73: lea    rcx,[r15+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_77:
	/* 0x77: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7c:
	/* 0x7c: lea    rcx,[r15+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_80:
	/* 0x80: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_88:
	/* 0x88: lea    rcx,[r15+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_8c:
	/* 0x8c: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_91:
	/* 0x91: lea    rcx,[r15+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_95:
	/* 0x95: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_9d:
	/* 0x9d: lea    rcx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a1:
	/* 0xa1: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a6:
	/* 0xa6: lea    rcx,[r15+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_aa:
	/* 0xaa: mov    QWORD PTR [rsp+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_b2:
	/* 0xb2: lea    rcx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b6:
	/* 0xb6: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_bb:
	/* 0xbb: lea    rcx,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bf:
	/* 0xbf: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_c7:
	/* 0xc7: lea    rcx,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cb:
	/* 0xcb: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d0:
	/* 0xd0: lea    rcx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d4:
	/* 0xd4: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_dc:
	/* 0xdc: lea    rcx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e0:
	/* 0xe0: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e5:
	/* 0xe5: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e8:
	/* 0xe8: lea    rax,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ec:
	/* 0xec: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_f4:
	/* 0xf4: lea    rax,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f8:
	/* 0xf8: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_fd:
	/* 0xfd: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_102:
	/* 0x102: je     11a9 <generic_sleepable_preload+0x11a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4521ULL;
	}
x86_l_108:
	/* 0x108: lea    r14,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10c:
	/* 0x10c: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_10f:
	/* 0x10f: add    rbx,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 512ULL);
x86_l_116:
	/* 0x116: mov    r15d,0xbe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 190ULL);
x86_l_11c:
	/* 0x11c: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_121:
	/* 0x121: jmp    149 <generic_sleepable_preload+0x149> */
	goto x86_l_149;
x86_l_123:
	/* 0x123: mov    DWORD PTR [rax],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_126:
	/* 0x126: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12b:
	/* 0x12b: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_130:
	/* 0x130: add    r14,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_134:
	/* 0x134: add    rbx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_138:
	/* 0x138: add    r15,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_13c:
	/* 0x13c: cmp    r15,0x24e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 590ULL);
x86_l_143:
	/* 0x143: je     11f5 <generic_sleepable_preload+0x11f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4597ULL;
	}
x86_l_149:
	/* 0x149: mov    eax,DWORD PTR [r14+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_14d:
	/* 0x14d: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_152:
	/* 0x152: je     130 <generic_sleepable_preload+0x130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_130;
	}
x86_l_154:
	/* 0x154: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_156:
	/* 0x156: js     1ad <generic_sleepable_preload+0x1ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ad;
	}
x86_l_158:
	/* 0x158: movzx  eax,BYTE PTR [rbx+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_15c:
	/* 0x15c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15f:
	/* 0x15f: jg     215 <generic_sleepable_preload+0x215> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_215;
	}
x86_l_165:
	/* 0x165: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_168:
	/* 0x168: je     351 <generic_sleepable_preload+0x351> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_351;
	}
x86_l_16e:
	/* 0x16e: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_173:
	/* 0x173: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_176:
	/* 0x176: jne    3c5 <generic_sleepable_preload+0x3c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3c5;
	}
x86_l_17c:
	/* 0x17c: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17f:
	/* 0x17f: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_185:
	/* 0x185: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_18a:
	/* 0x18a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18f:
	/* 0x18f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_194:
	/* 0x194: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_197:
	/* 0x197: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19c:
	/* 0x19c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e:
	/* 0x19e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a0:
	/* 0x1a0: je     359 <generic_sleepable_preload+0x359> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_359;
	}
x86_l_1a6:
	/* 0x1a6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a8:
	/* 0x1a8: jmp    3c5 <generic_sleepable_preload+0x3c5> */
	goto x86_l_3c5;
x86_l_1ad:
	/* 0x1ad: movzx  eax,BYTE PTR [r14+0x2be] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 702ULL);
x86_l_1b5:
	/* 0x1b5: movzx  ecx,WORD PTR [r14+0x2bc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 700ULL);
x86_l_1bd:
	/* 0x1bd: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_1c3:
	/* 0x1c3: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1c6:
	/* 0x1c6: jle    2ba <generic_sleepable_preload+0x2ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2ba;
	}
x86_l_1cc:
	/* 0x1cc: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_1cf:
	/* 0x1cf: jle    2ed <generic_sleepable_preload+0x2ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2ed;
	}
x86_l_1d5:
	/* 0x1d5: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1d8:
	/* 0x1d8: jle    979 <generic_sleepable_preload+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2425ULL;
	}
x86_l_1de:
	/* 0x1de: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1e6:
	/* 0x1e6: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_1e9:
	/* 0x1e9: je     995 <generic_sleepable_preload+0x995> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2453ULL;
	}
x86_l_1ef:
	/* 0x1ef: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1f4:
	/* 0x1f4: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1f7:
	/* 0x1f7: je     995 <generic_sleepable_preload+0x995> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2453ULL;
	}
x86_l_1fd:
	/* 0x1fd: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_202:
	/* 0x202: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_205:
	/* 0x205: jne    9a8 <generic_sleepable_preload+0x9a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2472ULL;
	}
x86_l_20b:
	/* 0x20b: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_210:
	/* 0x210: jmp    995 <generic_sleepable_preload+0x995> */
	return 2453ULL;
x86_l_215:
	/* 0x215: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_218:
	/* 0x218: je     378 <generic_sleepable_preload+0x378> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_378;
	}
x86_l_21e:
	/* 0x21e: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_223:
	/* 0x223: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_226:
	/* 0x226: jne    3c5 <generic_sleepable_preload+0x3c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3c5;
	}
x86_l_22c:
	/* 0x22c: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22f:
	/* 0x22f: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_235:
	/* 0x235: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23a:
	/* 0x23a: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23d:
	/* 0x23d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_242:
	/* 0x242: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_247:
	/* 0x247: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_24a:
	/* 0x24a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24f:
	/* 0x24f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_251:
	/* 0x251: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_253:
	/* 0x253: jne    3c2 <generic_sleepable_preload+0x3c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3c2;
	}
x86_l_259:
	/* 0x259: mov    edx,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_25c:
	/* 0x25c: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_262:
	/* 0x262: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_265:
	/* 0x265: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26a:
	/* 0x26a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26f:
	/* 0x26f: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_275:
	/* 0x275: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27a:
	/* 0x27a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27c:
	/* 0x27c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27e:
	/* 0x27e: jne    3c2 <generic_sleepable_preload+0x3c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3c2;
	}
x86_l_284:
	/* 0x284: movzx  eax,BYTE PTR [rbx+0x13] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 19ULL);
x86_l_288:
	/* 0x288: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_28f:
	/* 0x28f: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_292:
	/* 0x292: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_297:
	/* 0x297: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29a:
	/* 0x29a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_29f:
	/* 0x29f: movzx  ecx,BYTE PTR [rbx+0x13] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 19ULL);
x86_l_2a3:
	/* 0x2a3: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_2aa:
	/* 0x2aa: mov    rdx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ad:
	/* 0x2ad: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2b2:
	/* 0x2b2: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b5:
	/* 0x2b5: jmp    3b4 <generic_sleepable_preload+0x3b4> */
	goto x86_l_3b4;
x86_l_2ba:
	/* 0x2ba: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_2bd:
	/* 0x2bd: jg     31f <generic_sleepable_preload+0x31f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_31f;
	}
x86_l_2bf:
	/* 0x2bf: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2c2:
	/* 0x2c2: jg     93d <generic_sleepable_preload+0x93d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2365ULL;
	}
x86_l_2c8:
	/* 0x2c8: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2cd:
	/* 0x2cd: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2cf:
	/* 0x2cf: je     995 <generic_sleepable_preload+0x995> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2453ULL;
	}
x86_l_2d5:
	/* 0x2d5: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2da:
	/* 0x2da: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_2df:
	/* 0x2df: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2e2:
	/* 0x2e2: je     995 <generic_sleepable_preload+0x995> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2453ULL;
	}
x86_l_2e8:
	/* 0x2e8: jmp    9a8 <generic_sleepable_preload+0x9a8> */
	return 2472ULL;
x86_l_2ed:
	/* 0x2ed: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_2f0:
	/* 0x2f0: jg     91f <generic_sleepable_preload+0x91f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2335ULL;
	}
x86_l_2f6:
	/* 0x2f6: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2fe:
	/* 0x2fe: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_301:
	/* 0x301: je     995 <generic_sleepable_preload+0x995> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2453ULL;
	}
x86_l_307:
	/* 0x307: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_30c:
	/* 0x30c: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_311:
	/* 0x311: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_314:
	/* 0x314: je     995 <generic_sleepable_preload+0x995> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2453ULL;
	}
x86_l_31a:
	/* 0x31a: jmp    9a8 <generic_sleepable_preload+0x9a8> */
	return 2472ULL;
x86_l_31f:
	/* 0x31f: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_322:
	/* 0x322: jg     95b <generic_sleepable_preload+0x95b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2395ULL;
	}
x86_l_328:
	/* 0x328: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_330:
	/* 0x330: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_333:
	/* 0x333: je     995 <generic_sleepable_preload+0x995> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2453ULL;
	}
x86_l_339:
	/* 0x339: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_33e:
	/* 0x33e: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_343:
	/* 0x343: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_346:
	/* 0x346: je     995 <generic_sleepable_preload+0x995> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2453ULL;
	}
x86_l_34c:
	/* 0x34c: jmp    9a8 <generic_sleepable_preload+0x9a8> */
	return 2472ULL;
x86_l_351:
	/* 0x351: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_354:
	/* 0x354: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_359:
	/* 0x359: movzx  eax,BYTE PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_35d:
	/* 0x35d: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_364:
	/* 0x364: cmp    BYTE PTR [rbx+0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77309411328ULL);
x86_l_368:
	/* 0x368: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_36d:
	/* 0x36d: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_372:
	/* 0x372: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_376:
	/* 0x376: jmp    3c5 <generic_sleepable_preload+0x3c5> */
	goto x86_l_3c5;
x86_l_378:
	/* 0x378: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37b:
	/* 0x37b: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_381:
	/* 0x381: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_386:
	/* 0x386: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_38b:
	/* 0x38b: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_391:
	/* 0x391: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_394:
	/* 0x394: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_399:
	/* 0x399: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39b:
	/* 0x39b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39d:
	/* 0x39d: jne    3c2 <generic_sleepable_preload+0x3c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3c2;
	}
x86_l_39f:
	/* 0x39f: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3a4:
	/* 0x3a4: add    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3a7:
	/* 0x3a7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3ac:
	/* 0x3ac: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b1:
	/* 0x3b1: add    rdx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3b4:
	/* 0x3b4: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_3b7:
	/* 0x3b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bc:
	/* 0x3bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3be:
	/* 0x3be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c0:
	/* 0x3c0: je     359 <generic_sleepable_preload+0x359> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_359;
	}
x86_l_3c2:
	/* 0x3c2: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3c5:
	/* 0x3c5: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ca:
	/* 0x3ca: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3cd:
	/* 0x3cd: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_3cf:
	/* 0x3cf: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3d3:
	/* 0x3d3: cmp    WORD PTR [r13+r15*1-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743764471906304ULL);
x86_l_3da:
	/* 0x3da: je     67d <generic_sleepable_preload+0x67d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_67d;
	}
x86_l_3e0:
	/* 0x3e0: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_3e7:
	/* 0x3e7: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3ea:
	/* 0x3ea: mov    eax,DWORD PTR [r13+r15*1-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551538ULL);
x86_l_3ef:
	/* 0x3ef: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3f2:
	/* 0x3f2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f7:
	/* 0x3f7: movzx  eax,WORD PTR [r13+r15*1-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R15, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_3fd:
	/* 0x3fd: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_3ff:
	/* 0x3ff: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_404:
	/* 0x404: je     687 <generic_sleepable_preload+0x687> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_687;
	}
x86_l_40a:
	/* 0x40a: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_40d:
	/* 0x40d: je     42d <generic_sleepable_preload+0x42d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42d;
	}
x86_l_40f:
	/* 0x40f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_414:
	/* 0x414: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_419:
	/* 0x419: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41e:
	/* 0x41e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_423:
	/* 0x423: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_425:
	/* 0x425: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_427:
	/* 0x427: js     914 <generic_sleepable_preload+0x914> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2324ULL;
	}
x86_l_42d:
	/* 0x42d: cmp    WORD PTR [r13+r15*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743798831644672ULL);
x86_l_434:
	/* 0x434: je     fc7 <generic_sleepable_preload+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4039ULL;
	}
x86_l_43a:
	/* 0x43a: mov    ecx,DWORD PTR [r13+r15*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551546ULL);
x86_l_43f:
	/* 0x43f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_444:
	/* 0x444: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_449:
	/* 0x449: cmp    WORD PTR [r13+r15*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743790241710080ULL);
x86_l_450:
	/* 0x450: je     470 <generic_sleepable_preload+0x470> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_470;
	}
x86_l_452:
	/* 0x452: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_457:
	/* 0x457: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45c:
	/* 0x45c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_461:
	/* 0x461: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_466:
	/* 0x466: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_468:
	/* 0x468: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46a:
	/* 0x46a: js     f5a <generic_sleepable_preload+0xf5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3930ULL;
	}
x86_l_470:
	/* 0x470: cmp    WORD PTR [r13+r15*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743833191383040ULL);
x86_l_477:
	/* 0x477: je     fc7 <generic_sleepable_preload+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4039ULL;
	}
x86_l_47d:
	/* 0x47d: mov    ecx,DWORD PTR [r13+r15*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551554ULL);
x86_l_482:
	/* 0x482: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_487:
	/* 0x487: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48c:
	/* 0x48c: cmp    WORD PTR [r13+r15*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743824601448448ULL);
x86_l_493:
	/* 0x493: je     4b3 <generic_sleepable_preload+0x4b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b3;
	}
x86_l_495:
	/* 0x495: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_49a:
	/* 0x49a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49f:
	/* 0x49f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a4:
	/* 0x4a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a9:
	/* 0x4a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ab:
	/* 0x4ab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ad:
	/* 0x4ad: js     f6d <generic_sleepable_preload+0xf6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3949ULL;
	}
x86_l_4b3:
	/* 0x4b3: cmp    WORD PTR [r13+r15*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743867551121408ULL);
x86_l_4ba:
	/* 0x4ba: je     fc7 <generic_sleepable_preload+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4039ULL;
	}
x86_l_4c0:
	/* 0x4c0: mov    ecx,DWORD PTR [r13+r15*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551562ULL);
x86_l_4c5:
	/* 0x4c5: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4ca:
	/* 0x4ca: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cf:
	/* 0x4cf: cmp    WORD PTR [r13+r15*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743858961186816ULL);
x86_l_4d6:
	/* 0x4d6: je     4f6 <generic_sleepable_preload+0x4f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f6;
	}
x86_l_4d8:
	/* 0x4d8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4dd:
	/* 0x4dd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e2:
	/* 0x4e2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e7:
	/* 0x4e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ec:
	/* 0x4ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ee:
	/* 0x4ee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f0:
	/* 0x4f0: js     f80 <generic_sleepable_preload+0xf80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3968ULL;
	}
x86_l_4f6:
	/* 0x4f6: cmp    WORD PTR [r13+r15*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743901910859776ULL);
x86_l_4fd:
	/* 0x4fd: je     fc7 <generic_sleepable_preload+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4039ULL;
	}
x86_l_503:
	/* 0x503: mov    ecx,DWORD PTR [r13+r15*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551570ULL);
x86_l_508:
	/* 0x508: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_50d:
	/* 0x50d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_512:
	/* 0x512: cmp    WORD PTR [r13+r15*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743893320925184ULL);
x86_l_519:
	/* 0x519: je     539 <generic_sleepable_preload+0x539> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_539;
	}
x86_l_51b:
	/* 0x51b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_520:
	/* 0x520: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_525:
	/* 0x525: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52a:
	/* 0x52a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52f:
	/* 0x52f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_531:
	/* 0x531: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_533:
	/* 0x533: js     f93 <generic_sleepable_preload+0xf93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3987ULL;
	}
x86_l_539:
	/* 0x539: cmp    WORD PTR [r13+r15*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743936270598144ULL);
x86_l_540:
	/* 0x540: je     fc7 <generic_sleepable_preload+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4039ULL;
	}
x86_l_546:
	/* 0x546: mov    ecx,DWORD PTR [r13+r15*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551578ULL);
x86_l_54b:
	/* 0x54b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_550:
	/* 0x550: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_555:
	/* 0x555: cmp    WORD PTR [r13+r15*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743927680663552ULL);
x86_l_55c:
	/* 0x55c: je     57c <generic_sleepable_preload+0x57c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_57c;
	}
x86_l_55e:
	/* 0x55e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_563:
	/* 0x563: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_568:
	/* 0x568: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56d:
	/* 0x56d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_572:
	/* 0x572: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_574:
	/* 0x574: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_576:
	/* 0x576: js     fa6 <generic_sleepable_preload+0xfa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4006ULL;
	}
x86_l_57c:
	/* 0x57c: cmp    WORD PTR [r13+r15*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743970630336512ULL);
x86_l_583:
	/* 0x583: je     fc7 <generic_sleepable_preload+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4039ULL;
	}
x86_l_589:
	/* 0x589: mov    ecx,DWORD PTR [r13+r15*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551586ULL);
x86_l_58e:
	/* 0x58e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_593:
	/* 0x593: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_598:
	/* 0x598: cmp    WORD PTR [r13+r15*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743962040401920ULL);
x86_l_59f:
	/* 0x59f: je     5bf <generic_sleepable_preload+0x5bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5bf;
	}
x86_l_5a1:
	/* 0x5a1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5a6:
	/* 0x5a6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ab:
	/* 0x5ab: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b0:
	/* 0x5b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b5:
	/* 0x5b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b7:
	/* 0x5b7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5b9:
	/* 0x5b9: js     fb9 <generic_sleepable_preload+0xfb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4025ULL;
	}
x86_l_5bf:
	/* 0x5bf: cmp    WORD PTR [r13+r15*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744004990074880ULL);
x86_l_5c6:
	/* 0x5c6: je     fc7 <generic_sleepable_preload+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4039ULL;
	}
x86_l_5cc:
	/* 0x5cc: mov    ecx,DWORD PTR [r13+r15*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551594ULL);
x86_l_5d1:
	/* 0x5d1: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5d6:
	/* 0x5d6: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5db:
	/* 0x5db: cmp    WORD PTR [r13+r15*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743996400140288ULL);
x86_l_5e2:
	/* 0x5e2: je     602 <generic_sleepable_preload+0x602> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_602;
	}
x86_l_5e4:
	/* 0x5e4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5e9:
	/* 0x5e9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ee:
	/* 0x5ee: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f3:
	/* 0x5f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f8:
	/* 0x5f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fa:
	/* 0x5fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5fc:
	/* 0x5fc: js     1164 <generic_sleepable_preload+0x1164> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4452ULL;
	}
x86_l_602:
	/* 0x602: cmp    WORD PTR [r13+r15*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744039349813248ULL);
x86_l_609:
	/* 0x609: je     fc7 <generic_sleepable_preload+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4039ULL;
	}
x86_l_60f:
	/* 0x60f: mov    ecx,DWORD PTR [r13+r15*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551602ULL);
x86_l_614:
	/* 0x614: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_619:
	/* 0x619: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_61e:
	/* 0x61e: cmp    WORD PTR [r13+r15*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744030759878656ULL);
x86_l_625:
	/* 0x625: je     645 <generic_sleepable_preload+0x645> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_645;
	}
x86_l_627:
	/* 0x627: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_62c:
	/* 0x62c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_631:
	/* 0x631: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_636:
	/* 0x636: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_63b:
	/* 0x63b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63d:
	/* 0x63d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_63f:
	/* 0x63f: js     1193 <generic_sleepable_preload+0x1193> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4499ULL;
	}
x86_l_645:
	/* 0x645: cmp    WORD PTR [r13+r15*1+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_64c:
	/* 0x64c: je     fc7 <generic_sleepable_preload+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4039ULL;
	}
x86_l_652:
	/* 0x652: mov    ecx,DWORD PTR [r13+r15*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551610ULL);
x86_l_657:
	/* 0x657: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_65c:
	/* 0x65c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_661:
	/* 0x661: cmp    WORD PTR [r13+r15*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744065119617024ULL);
x86_l_668:
	/* 0x668: je     fc7 <generic_sleepable_preload+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4039ULL;
	}
x86_l_66e:
	/* 0x66e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_673:
	/* 0x673: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_678:
	/* 0x678: jmp    8f5 <generic_sleepable_preload+0x8f5> */
	return 2293ULL;
x86_l_67d:
	/* 0x67d: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_682:
	/* 0x682: jmp    fc7 <generic_sleepable_preload+0xfc7> */
	return 4039ULL;
x86_l_687:
	/* 0x687: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_68a:
	/* 0x68a: je     6aa <generic_sleepable_preload+0x6aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6aa;
	}
x86_l_68c:
	/* 0x68c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_691:
	/* 0x691: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_696:
	/* 0x696: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_69b:
	/* 0x69b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6a0:
	/* 0x6a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a2:
	/* 0x6a2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6a4:
	/* 0x6a4: js     914 <generic_sleepable_preload+0x914> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2324ULL;
	}
x86_l_6aa:
	/* 0x6aa: cmp    WORD PTR [r13+r15*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743798831644672ULL);
x86_l_6b1:
	/* 0x6b1: je     fc7 <generic_sleepable_preload+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4039ULL;
	}
x86_l_6b7:
	/* 0x6b7: mov    ecx,DWORD PTR [r13+r15*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551546ULL);
x86_l_6bc:
	/* 0x6bc: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6c1:
	/* 0x6c1: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6c6:
	/* 0x6c6: cmp    WORD PTR [r13+r15*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743790241710080ULL);
x86_l_6cd:
	/* 0x6cd: je     6ed <generic_sleepable_preload+0x6ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6ed;
	}
x86_l_6cf:
	/* 0x6cf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_6d4:
	/* 0x6d4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6d9:
	/* 0x6d9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6de:
	/* 0x6de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6e3:
	/* 0x6e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e5:
	/* 0x6e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6e7:
	/* 0x6e7: js     f5a <generic_sleepable_preload+0xf5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3930ULL;
	}
x86_l_6ed:
	/* 0x6ed: cmp    WORD PTR [r13+r15*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743833191383040ULL);
	return 1780ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1780ULL: goto x86_l_6f4;
	case 1786ULL: goto x86_l_6fa;
	case 1791ULL: goto x86_l_6ff;
	case 1796ULL: goto x86_l_704;
	case 1801ULL: goto x86_l_709;
	case 1808ULL: goto x86_l_710;
	case 1810ULL: goto x86_l_712;
	case 1815ULL: goto x86_l_717;
	case 1820ULL: goto x86_l_71c;
	case 1825ULL: goto x86_l_721;
	case 1830ULL: goto x86_l_726;
	case 1832ULL: goto x86_l_728;
	case 1834ULL: goto x86_l_72a;
	case 1840ULL: goto x86_l_730;
	case 1847ULL: goto x86_l_737;
	case 1853ULL: goto x86_l_73d;
	case 1858ULL: goto x86_l_742;
	case 1863ULL: goto x86_l_747;
	case 1868ULL: goto x86_l_74c;
	case 1875ULL: goto x86_l_753;
	case 1877ULL: goto x86_l_755;
	case 1882ULL: goto x86_l_75a;
	case 1887ULL: goto x86_l_75f;
	case 1892ULL: goto x86_l_764;
	case 1897ULL: goto x86_l_769;
	case 1899ULL: goto x86_l_76b;
	case 1901ULL: goto x86_l_76d;
	case 1907ULL: goto x86_l_773;
	case 1914ULL: goto x86_l_77a;
	case 1920ULL: goto x86_l_780;
	case 1925ULL: goto x86_l_785;
	case 1930ULL: goto x86_l_78a;
	case 1935ULL: goto x86_l_78f;
	case 1942ULL: goto x86_l_796;
	case 1944ULL: goto x86_l_798;
	case 1949ULL: goto x86_l_79d;
	case 1954ULL: goto x86_l_7a2;
	case 1959ULL: goto x86_l_7a7;
	case 1964ULL: goto x86_l_7ac;
	case 1966ULL: goto x86_l_7ae;
	case 1968ULL: goto x86_l_7b0;
	case 1974ULL: goto x86_l_7b6;
	case 1981ULL: goto x86_l_7bd;
	case 1987ULL: goto x86_l_7c3;
	case 1992ULL: goto x86_l_7c8;
	case 1997ULL: goto x86_l_7cd;
	case 2002ULL: goto x86_l_7d2;
	case 2009ULL: goto x86_l_7d9;
	case 2011ULL: goto x86_l_7db;
	case 2016ULL: goto x86_l_7e0;
	case 2021ULL: goto x86_l_7e5;
	case 2026ULL: goto x86_l_7ea;
	case 2031ULL: goto x86_l_7ef;
	case 2033ULL: goto x86_l_7f1;
	case 2035ULL: goto x86_l_7f3;
	case 2041ULL: goto x86_l_7f9;
	case 2048ULL: goto x86_l_800;
	case 2054ULL: goto x86_l_806;
	case 2059ULL: goto x86_l_80b;
	case 2064ULL: goto x86_l_810;
	case 2069ULL: goto x86_l_815;
	case 2076ULL: goto x86_l_81c;
	case 2078ULL: goto x86_l_81e;
	case 2083ULL: goto x86_l_823;
	case 2088ULL: goto x86_l_828;
	case 2093ULL: goto x86_l_82d;
	case 2098ULL: goto x86_l_832;
	case 2100ULL: goto x86_l_834;
	case 2102ULL: goto x86_l_836;
	case 2108ULL: goto x86_l_83c;
	case 2115ULL: goto x86_l_843;
	case 2121ULL: goto x86_l_849;
	case 2126ULL: goto x86_l_84e;
	case 2131ULL: goto x86_l_853;
	case 2136ULL: goto x86_l_858;
	case 2143ULL: goto x86_l_85f;
	case 2145ULL: goto x86_l_861;
	case 2150ULL: goto x86_l_866;
	case 2155ULL: goto x86_l_86b;
	case 2160ULL: goto x86_l_870;
	case 2165ULL: goto x86_l_875;
	case 2167ULL: goto x86_l_877;
	case 2169ULL: goto x86_l_879;
	case 2175ULL: goto x86_l_87f;
	case 2182ULL: goto x86_l_886;
	case 2188ULL: goto x86_l_88c;
	case 2193ULL: goto x86_l_891;
	case 2198ULL: goto x86_l_896;
	case 2203ULL: goto x86_l_89b;
	case 2210ULL: goto x86_l_8a2;
	case 2212ULL: goto x86_l_8a4;
	case 2217ULL: goto x86_l_8a9;
	case 2222ULL: goto x86_l_8ae;
	case 2227ULL: goto x86_l_8b3;
	case 2232ULL: goto x86_l_8b8;
	case 2234ULL: goto x86_l_8ba;
	case 2236ULL: goto x86_l_8bc;
	case 2242ULL: goto x86_l_8c2;
	case 2249ULL: goto x86_l_8c9;
	case 2255ULL: goto x86_l_8cf;
	case 2260ULL: goto x86_l_8d4;
	case 2265ULL: goto x86_l_8d9;
	case 2270ULL: goto x86_l_8de;
	case 2277ULL: goto x86_l_8e5;
	case 2283ULL: goto x86_l_8eb;
	case 2288ULL: goto x86_l_8f0;
	case 2293ULL: goto x86_l_8f5;
	case 2298ULL: goto x86_l_8fa;
	case 2303ULL: goto x86_l_8ff;
	case 2305ULL: goto x86_l_901;
	case 2307ULL: goto x86_l_903;
	case 2313ULL: goto x86_l_909;
	case 2319ULL: goto x86_l_90f;
	case 2324ULL: goto x86_l_914;
	case 2330ULL: goto x86_l_91a;
	case 2335ULL: goto x86_l_91f;
	case 2343ULL: goto x86_l_927;
	case 2346ULL: goto x86_l_92a;
	case 2348ULL: goto x86_l_92c;
	case 2353ULL: goto x86_l_931;
	case 2358ULL: goto x86_l_936;
	case 2361ULL: goto x86_l_939;
	case 2363ULL: goto x86_l_93b;
	case 2365ULL: goto x86_l_93d;
	case 2373ULL: goto x86_l_945;
	case 2376ULL: goto x86_l_948;
	case 2378ULL: goto x86_l_94a;
	case 2383ULL: goto x86_l_94f;
	case 2388ULL: goto x86_l_954;
	case 2391ULL: goto x86_l_957;
	case 2393ULL: goto x86_l_959;
	case 2395ULL: goto x86_l_95b;
	case 2403ULL: goto x86_l_963;
	case 2406ULL: goto x86_l_966;
	case 2408ULL: goto x86_l_968;
	case 2413ULL: goto x86_l_96d;
	case 2418ULL: goto x86_l_972;
	case 2421ULL: goto x86_l_975;
	case 2423ULL: goto x86_l_977;
	case 2425ULL: goto x86_l_979;
	case 2433ULL: goto x86_l_981;
	case 2436ULL: goto x86_l_984;
	case 2438ULL: goto x86_l_986;
	case 2443ULL: goto x86_l_98b;
	case 2448ULL: goto x86_l_990;
	case 2451ULL: goto x86_l_993;
	case 2453ULL: goto x86_l_995;
	case 2456ULL: goto x86_l_998;
	case 2458ULL: goto x86_l_99a;
	case 2460ULL: goto x86_l_99c;
	case 2465ULL: goto x86_l_9a1;
	case 2467ULL: goto x86_l_9a3;
	case 2472ULL: goto x86_l_9a8;
	case 2477ULL: goto x86_l_9ad;
	case 2480ULL: goto x86_l_9b0;
	case 2483ULL: goto x86_l_9b3;
	case 2485ULL: goto x86_l_9b5;
	case 2489ULL: goto x86_l_9b9;
	case 2496ULL: goto x86_l_9c0;
	case 2502ULL: goto x86_l_9c6;
	case 2509ULL: goto x86_l_9cd;
	case 2512ULL: goto x86_l_9d0;
	case 2517ULL: goto x86_l_9d5;
	case 2520ULL: goto x86_l_9d8;
	case 2525ULL: goto x86_l_9dd;
	case 2531ULL: goto x86_l_9e3;
	case 2533ULL: goto x86_l_9e5;
	case 2539ULL: goto x86_l_9eb;
	case 2542ULL: goto x86_l_9ee;
	case 2544ULL: goto x86_l_9f0;
	case 2549ULL: goto x86_l_9f5;
	case 2554ULL: goto x86_l_9fa;
	case 2559ULL: goto x86_l_9ff;
	case 2564ULL: goto x86_l_a04;
	case 2569ULL: goto x86_l_a09;
	case 2571ULL: goto x86_l_a0b;
	case 2573ULL: goto x86_l_a0d;
	case 2579ULL: goto x86_l_a13;
	case 2586ULL: goto x86_l_a1a;
	case 2592ULL: goto x86_l_a20;
	case 2597ULL: goto x86_l_a25;
	case 2602ULL: goto x86_l_a2a;
	case 2607ULL: goto x86_l_a2f;
	case 2614ULL: goto x86_l_a36;
	case 2616ULL: goto x86_l_a38;
	case 2621ULL: goto x86_l_a3d;
	case 2626ULL: goto x86_l_a42;
	case 2631ULL: goto x86_l_a47;
	case 2636ULL: goto x86_l_a4c;
	case 2641ULL: goto x86_l_a51;
	case 2643ULL: goto x86_l_a53;
	case 2645ULL: goto x86_l_a55;
	case 2651ULL: goto x86_l_a5b;
	case 2658ULL: goto x86_l_a62;
	case 2664ULL: goto x86_l_a68;
	case 2669ULL: goto x86_l_a6d;
	case 2674ULL: goto x86_l_a72;
	case 2679ULL: goto x86_l_a77;
	case 2686ULL: goto x86_l_a7e;
	case 2688ULL: goto x86_l_a80;
	case 2693ULL: goto x86_l_a85;
	case 2698ULL: goto x86_l_a8a;
	case 2703ULL: goto x86_l_a8f;
	case 2708ULL: goto x86_l_a94;
	case 2713ULL: goto x86_l_a99;
	case 2715ULL: goto x86_l_a9b;
	case 2717ULL: goto x86_l_a9d;
	case 2723ULL: goto x86_l_aa3;
	case 2730ULL: goto x86_l_aaa;
	case 2736ULL: goto x86_l_ab0;
	case 2741ULL: goto x86_l_ab5;
	case 2746ULL: goto x86_l_aba;
	case 2751ULL: goto x86_l_abf;
	case 2758ULL: goto x86_l_ac6;
	case 2760ULL: goto x86_l_ac8;
	case 2765ULL: goto x86_l_acd;
	case 2770ULL: goto x86_l_ad2;
	case 2775ULL: goto x86_l_ad7;
	case 2780ULL: goto x86_l_adc;
	case 2785ULL: goto x86_l_ae1;
	case 2787ULL: goto x86_l_ae3;
	case 2789ULL: goto x86_l_ae5;
	case 2795ULL: goto x86_l_aeb;
	case 2802ULL: goto x86_l_af2;
	case 2808ULL: goto x86_l_af8;
	case 2813ULL: goto x86_l_afd;
	case 2818ULL: goto x86_l_b02;
	case 2823ULL: goto x86_l_b07;
	case 2830ULL: goto x86_l_b0e;
	case 2832ULL: goto x86_l_b10;
	case 2837ULL: goto x86_l_b15;
	case 2842ULL: goto x86_l_b1a;
	case 2847ULL: goto x86_l_b1f;
	case 2852ULL: goto x86_l_b24;
	case 2857ULL: goto x86_l_b29;
	case 2859ULL: goto x86_l_b2b;
	case 2861ULL: goto x86_l_b2d;
	case 2867ULL: goto x86_l_b33;
	case 2874ULL: goto x86_l_b3a;
	case 2880ULL: goto x86_l_b40;
	case 2885ULL: goto x86_l_b45;
	case 2890ULL: goto x86_l_b4a;
	case 2895ULL: goto x86_l_b4f;
	case 2902ULL: goto x86_l_b56;
	case 2904ULL: goto x86_l_b58;
	case 2909ULL: goto x86_l_b5d;
	case 2914ULL: goto x86_l_b62;
	case 2919ULL: goto x86_l_b67;
	case 2924ULL: goto x86_l_b6c;
	case 2929ULL: goto x86_l_b71;
	case 2931ULL: goto x86_l_b73;
	case 2933ULL: goto x86_l_b75;
	case 2939ULL: goto x86_l_b7b;
	case 2946ULL: goto x86_l_b82;
	case 2952ULL: goto x86_l_b88;
	case 2957ULL: goto x86_l_b8d;
	case 2962ULL: goto x86_l_b92;
	case 2967ULL: goto x86_l_b97;
	case 2974ULL: goto x86_l_b9e;
	case 2976ULL: goto x86_l_ba0;
	case 2981ULL: goto x86_l_ba5;
	case 2986ULL: goto x86_l_baa;
	case 2991ULL: goto x86_l_baf;
	case 2996ULL: goto x86_l_bb4;
	case 3001ULL: goto x86_l_bb9;
	case 3003ULL: goto x86_l_bbb;
	case 3005ULL: goto x86_l_bbd;
	case 3011ULL: goto x86_l_bc3;
	case 3018ULL: goto x86_l_bca;
	case 3024ULL: goto x86_l_bd0;
	case 3029ULL: goto x86_l_bd5;
	case 3034ULL: goto x86_l_bda;
	case 3039ULL: goto x86_l_bdf;
	case 3046ULL: goto x86_l_be6;
	case 3048ULL: goto x86_l_be8;
	case 3053ULL: goto x86_l_bed;
	case 3058ULL: goto x86_l_bf2;
	case 3063ULL: goto x86_l_bf7;
	case 3068ULL: goto x86_l_bfc;
	case 3073ULL: goto x86_l_c01;
	case 3075ULL: goto x86_l_c03;
	case 3077ULL: goto x86_l_c05;
	case 3083ULL: goto x86_l_c0b;
	case 3090ULL: goto x86_l_c12;
	case 3096ULL: goto x86_l_c18;
	case 3101ULL: goto x86_l_c1d;
	case 3106ULL: goto x86_l_c22;
	case 3111ULL: goto x86_l_c27;
	case 3118ULL: goto x86_l_c2e;
	case 3120ULL: goto x86_l_c30;
	case 3125ULL: goto x86_l_c35;
	case 3130ULL: goto x86_l_c3a;
	case 3135ULL: goto x86_l_c3f;
	case 3140ULL: goto x86_l_c44;
	case 3145ULL: goto x86_l_c49;
	case 3147ULL: goto x86_l_c4b;
	case 3149ULL: goto x86_l_c4d;
	case 3155ULL: goto x86_l_c53;
	case 3162ULL: goto x86_l_c5a;
	case 3168ULL: goto x86_l_c60;
	case 3173ULL: goto x86_l_c65;
	case 3178ULL: goto x86_l_c6a;
	case 3183ULL: goto x86_l_c6f;
	case 3190ULL: goto x86_l_c76;
	case 3196ULL: goto x86_l_c7c;
	case 3201ULL: goto x86_l_c81;
	case 3206ULL: goto x86_l_c86;
	case 3211ULL: goto x86_l_c8b;
	case 3216ULL: goto x86_l_c90;
	case 3219ULL: goto x86_l_c93;
	case 3221ULL: goto x86_l_c95;
	case 3226ULL: goto x86_l_c9a;
	case 3231ULL: goto x86_l_c9f;
	case 3236ULL: goto x86_l_ca4;
	case 3241ULL: goto x86_l_ca9;
	case 3246ULL: goto x86_l_cae;
	case 3248ULL: goto x86_l_cb0;
	case 3250ULL: goto x86_l_cb2;
	case 3256ULL: goto x86_l_cb8;
	case 3263ULL: goto x86_l_cbf;
	case 3269ULL: goto x86_l_cc5;
	case 3274ULL: goto x86_l_cca;
	case 3279ULL: goto x86_l_ccf;
	case 3284ULL: goto x86_l_cd4;
	case 3291ULL: goto x86_l_cdb;
	case 3293ULL: goto x86_l_cdd;
	case 3298ULL: goto x86_l_ce2;
	case 3303ULL: goto x86_l_ce7;
	case 3308ULL: goto x86_l_cec;
	case 3313ULL: goto x86_l_cf1;
	case 3318ULL: goto x86_l_cf6;
	case 3320ULL: goto x86_l_cf8;
	case 3322ULL: goto x86_l_cfa;
	case 3328ULL: goto x86_l_d00;
	case 3335ULL: goto x86_l_d07;
	case 3341ULL: goto x86_l_d0d;
	case 3346ULL: goto x86_l_d12;
	case 3351ULL: goto x86_l_d17;
	case 3356ULL: goto x86_l_d1c;
	case 3363ULL: goto x86_l_d23;
	case 3365ULL: goto x86_l_d25;
	case 3370ULL: goto x86_l_d2a;
	case 3375ULL: goto x86_l_d2f;
	case 3380ULL: goto x86_l_d34;
	case 3385ULL: goto x86_l_d39;
	case 3390ULL: goto x86_l_d3e;
	case 3392ULL: goto x86_l_d40;
	case 3394ULL: goto x86_l_d42;
	case 3400ULL: goto x86_l_d48;
	case 3407ULL: goto x86_l_d4f;
	case 3413ULL: goto x86_l_d55;
	case 3418ULL: goto x86_l_d5a;
	case 3423ULL: goto x86_l_d5f;
	case 3428ULL: goto x86_l_d64;
	case 3435ULL: goto x86_l_d6b;
	case 3437ULL: goto x86_l_d6d;
	case 3442ULL: goto x86_l_d72;
	case 3447ULL: goto x86_l_d77;
	case 3452ULL: goto x86_l_d7c;
	case 3457ULL: goto x86_l_d81;
	case 3462ULL: goto x86_l_d86;
	case 3464ULL: goto x86_l_d88;
	case 3466ULL: goto x86_l_d8a;
	case 3472ULL: goto x86_l_d90;
	case 3479ULL: goto x86_l_d97;
	case 3485ULL: goto x86_l_d9d;
	case 3490ULL: goto x86_l_da2;
	case 3495ULL: goto x86_l_da7;
	case 3500ULL: goto x86_l_dac;
	case 3507ULL: goto x86_l_db3;
	case 3509ULL: goto x86_l_db5;
	case 3514ULL: goto x86_l_dba;
	case 3519ULL: goto x86_l_dbf;
	case 3524ULL: goto x86_l_dc4;
	case 3529ULL: goto x86_l_dc9;
	case 3534ULL: goto x86_l_dce;
	case 3536ULL: goto x86_l_dd0;
	case 3538ULL: goto x86_l_dd2;
	case 3544ULL: goto x86_l_dd8;
	case 3551ULL: goto x86_l_ddf;
	case 3557ULL: goto x86_l_de5;
	case 3562ULL: goto x86_l_dea;
	case 3567ULL: goto x86_l_def;
	case 3572ULL: goto x86_l_df4;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6f4:
	/* 0x6f4: je     fc7 <generic_sleepable_preload+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4039ULL;
	}
x86_l_6fa:
	/* 0x6fa: mov    ecx,DWORD PTR [r13+r15*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551554ULL);
x86_l_6ff:
	/* 0x6ff: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_704:
	/* 0x704: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_709:
	/* 0x709: cmp    WORD PTR [r13+r15*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743824601448448ULL);
x86_l_710:
	/* 0x710: je     730 <generic_sleepable_preload+0x730> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_730;
	}
x86_l_712:
	/* 0x712: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_717:
	/* 0x717: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_71c:
	/* 0x71c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_721:
	/* 0x721: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_726:
	/* 0x726: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_728:
	/* 0x728: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_72a:
	/* 0x72a: js     f6d <generic_sleepable_preload+0xf6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3949ULL;
	}
x86_l_730:
	/* 0x730: cmp    WORD PTR [r13+r15*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743867551121408ULL);
x86_l_737:
	/* 0x737: je     fc7 <generic_sleepable_preload+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4039ULL;
	}
x86_l_73d:
	/* 0x73d: mov    ecx,DWORD PTR [r13+r15*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551562ULL);
x86_l_742:
	/* 0x742: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_747:
	/* 0x747: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_74c:
	/* 0x74c: cmp    WORD PTR [r13+r15*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743858961186816ULL);
x86_l_753:
	/* 0x753: je     773 <generic_sleepable_preload+0x773> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_773;
	}
x86_l_755:
	/* 0x755: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_75a:
	/* 0x75a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_75f:
	/* 0x75f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_764:
	/* 0x764: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_769:
	/* 0x769: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76b:
	/* 0x76b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_76d:
	/* 0x76d: js     f80 <generic_sleepable_preload+0xf80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3968ULL;
	}
x86_l_773:
	/* 0x773: cmp    WORD PTR [r13+r15*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743901910859776ULL);
x86_l_77a:
	/* 0x77a: je     fc7 <generic_sleepable_preload+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4039ULL;
	}
x86_l_780:
	/* 0x780: mov    ecx,DWORD PTR [r13+r15*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551570ULL);
x86_l_785:
	/* 0x785: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_78a:
	/* 0x78a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_78f:
	/* 0x78f: cmp    WORD PTR [r13+r15*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743893320925184ULL);
x86_l_796:
	/* 0x796: je     7b6 <generic_sleepable_preload+0x7b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7b6;
	}
x86_l_798:
	/* 0x798: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_79d:
	/* 0x79d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7a2:
	/* 0x7a2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7a7:
	/* 0x7a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7ac:
	/* 0x7ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ae:
	/* 0x7ae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7b0:
	/* 0x7b0: js     f93 <generic_sleepable_preload+0xf93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3987ULL;
	}
x86_l_7b6:
	/* 0x7b6: cmp    WORD PTR [r13+r15*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743936270598144ULL);
x86_l_7bd:
	/* 0x7bd: je     fc7 <generic_sleepable_preload+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4039ULL;
	}
x86_l_7c3:
	/* 0x7c3: mov    ecx,DWORD PTR [r13+r15*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551578ULL);
x86_l_7c8:
	/* 0x7c8: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_7cd:
	/* 0x7cd: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7d2:
	/* 0x7d2: cmp    WORD PTR [r13+r15*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743927680663552ULL);
x86_l_7d9:
	/* 0x7d9: je     7f9 <generic_sleepable_preload+0x7f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7f9;
	}
x86_l_7db:
	/* 0x7db: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_7e0:
	/* 0x7e0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7e5:
	/* 0x7e5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7ea:
	/* 0x7ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7ef:
	/* 0x7ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f1:
	/* 0x7f1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7f3:
	/* 0x7f3: js     fa6 <generic_sleepable_preload+0xfa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4006ULL;
	}
x86_l_7f9:
	/* 0x7f9: cmp    WORD PTR [r13+r15*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743970630336512ULL);
x86_l_800:
	/* 0x800: je     fc7 <generic_sleepable_preload+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4039ULL;
	}
x86_l_806:
	/* 0x806: mov    ecx,DWORD PTR [r13+r15*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551586ULL);
x86_l_80b:
	/* 0x80b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_810:
	/* 0x810: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_815:
	/* 0x815: cmp    WORD PTR [r13+r15*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743962040401920ULL);
x86_l_81c:
	/* 0x81c: je     83c <generic_sleepable_preload+0x83c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_83c;
	}
x86_l_81e:
	/* 0x81e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_823:
	/* 0x823: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_828:
	/* 0x828: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_82d:
	/* 0x82d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_832:
	/* 0x832: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_834:
	/* 0x834: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_836:
	/* 0x836: js     fb9 <generic_sleepable_preload+0xfb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4025ULL;
	}
x86_l_83c:
	/* 0x83c: cmp    WORD PTR [r13+r15*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744004990074880ULL);
x86_l_843:
	/* 0x843: je     fc7 <generic_sleepable_preload+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4039ULL;
	}
x86_l_849:
	/* 0x849: mov    ecx,DWORD PTR [r13+r15*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551594ULL);
x86_l_84e:
	/* 0x84e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_853:
	/* 0x853: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_858:
	/* 0x858: cmp    WORD PTR [r13+r15*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743996400140288ULL);
x86_l_85f:
	/* 0x85f: je     87f <generic_sleepable_preload+0x87f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_87f;
	}
x86_l_861:
	/* 0x861: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_866:
	/* 0x866: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_86b:
	/* 0x86b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_870:
	/* 0x870: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_875:
	/* 0x875: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_877:
	/* 0x877: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_879:
	/* 0x879: js     1164 <generic_sleepable_preload+0x1164> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4452ULL;
	}
x86_l_87f:
	/* 0x87f: cmp    WORD PTR [r13+r15*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744039349813248ULL);
x86_l_886:
	/* 0x886: je     fc7 <generic_sleepable_preload+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4039ULL;
	}
x86_l_88c:
	/* 0x88c: mov    ecx,DWORD PTR [r13+r15*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551602ULL);
x86_l_891:
	/* 0x891: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_896:
	/* 0x896: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_89b:
	/* 0x89b: cmp    WORD PTR [r13+r15*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744030759878656ULL);
x86_l_8a2:
	/* 0x8a2: je     8c2 <generic_sleepable_preload+0x8c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8c2;
	}
x86_l_8a4:
	/* 0x8a4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8a9:
	/* 0x8a9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8ae:
	/* 0x8ae: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8b3:
	/* 0x8b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8b8:
	/* 0x8b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ba:
	/* 0x8ba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8bc:
	/* 0x8bc: js     1193 <generic_sleepable_preload+0x1193> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4499ULL;
	}
x86_l_8c2:
	/* 0x8c2: cmp    WORD PTR [r13+r15*1+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_8c9:
	/* 0x8c9: je     fc7 <generic_sleepable_preload+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4039ULL;
	}
x86_l_8cf:
	/* 0x8cf: mov    ecx,DWORD PTR [r13+r15*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551610ULL);
x86_l_8d4:
	/* 0x8d4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_8d9:
	/* 0x8d9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8de:
	/* 0x8de: cmp    WORD PTR [r13+r15*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744065119617024ULL);
x86_l_8e5:
	/* 0x8e5: je     fc7 <generic_sleepable_preload+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4039ULL;
	}
x86_l_8eb:
	/* 0x8eb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8f0:
	/* 0x8f0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8f5:
	/* 0x8f5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8fa:
	/* 0x8fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8ff:
	/* 0x8ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_901:
	/* 0x901: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_903:
	/* 0x903: jns    fc7 <generic_sleepable_preload+0xfc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 4039ULL;
	}
x86_l_909:
	/* 0x909: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_90f:
	/* 0x90f: jmp    fbf <generic_sleepable_preload+0xfbf> */
	return 4031ULL;
x86_l_914:
	/* 0x914: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_91a:
	/* 0x91a: jmp    fbf <generic_sleepable_preload+0xfbf> */
	return 4031ULL;
x86_l_91f:
	/* 0x91f: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_927:
	/* 0x927: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_92a:
	/* 0x92a: je     995 <generic_sleepable_preload+0x995> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_995;
	}
x86_l_92c:
	/* 0x92c: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_931:
	/* 0x931: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_936:
	/* 0x936: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_939:
	/* 0x939: je     995 <generic_sleepable_preload+0x995> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_995;
	}
x86_l_93b:
	/* 0x93b: jmp    9a8 <generic_sleepable_preload+0x9a8> */
	goto x86_l_9a8;
x86_l_93d:
	/* 0x93d: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_945:
	/* 0x945: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_948:
	/* 0x948: je     995 <generic_sleepable_preload+0x995> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_995;
	}
x86_l_94a:
	/* 0x94a: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_94f:
	/* 0x94f: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_954:
	/* 0x954: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_957:
	/* 0x957: je     995 <generic_sleepable_preload+0x995> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_995;
	}
x86_l_959:
	/* 0x959: jmp    9a8 <generic_sleepable_preload+0x9a8> */
	goto x86_l_9a8;
x86_l_95b:
	/* 0x95b: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_963:
	/* 0x963: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_966:
	/* 0x966: je     995 <generic_sleepable_preload+0x995> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_995;
	}
x86_l_968:
	/* 0x968: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_96d:
	/* 0x96d: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_972:
	/* 0x972: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_975:
	/* 0x975: je     995 <generic_sleepable_preload+0x995> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_995;
	}
x86_l_977:
	/* 0x977: jmp    9a8 <generic_sleepable_preload+0x9a8> */
	goto x86_l_9a8;
x86_l_979:
	/* 0x979: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_981:
	/* 0x981: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_984:
	/* 0x984: je     995 <generic_sleepable_preload+0x995> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_995;
	}
x86_l_986:
	/* 0x986: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_98b:
	/* 0x98b: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_990:
	/* 0x990: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_993:
	/* 0x993: jne    9a8 <generic_sleepable_preload+0x9a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9a8;
	}
x86_l_995:
	/* 0x995: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_998:
	/* 0x998: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_99a:
	/* 0x99a: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_99c:
	/* 0x99c: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_9a1:
	/* 0x9a1: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_9a3:
	/* 0x9a3: bzhi   rsi,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RSI, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_9a8:
	/* 0x9a8: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9ad:
	/* 0x9ad: mov    ebp,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9b0:
	/* 0x9b0: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9b3:
	/* 0x9b3: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_9b5:
	/* 0x9b5: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_9b9:
	/* 0x9b9: cmp    WORD PTR [r13+r15*1-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743764471906304ULL);
x86_l_9c0:
	/* 0x9c0: je     10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4272ULL;
	}
x86_l_9c6:
	/* 0x9c6: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_9cd:
	/* 0x9cd: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_9d0:
	/* 0x9d0: mov    eax,DWORD PTR [r13+r15*1-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551538ULL);
x86_l_9d5:
	/* 0x9d5: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9d8:
	/* 0x9d8: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9dd:
	/* 0x9dd: movzx  eax,WORD PTR [r13+r15*1-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R15, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_9e3:
	/* 0x9e3: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_9e5:
	/* 0x9e5: je     c90 <generic_sleepable_preload+0xc90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c90;
	}
x86_l_9eb:
	/* 0x9eb: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_9ee:
	/* 0x9ee: je     a13 <generic_sleepable_preload+0xa13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a13;
	}
x86_l_9f0:
	/* 0x9f0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_9f5:
	/* 0x9f5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9fa:
	/* 0x9fa: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9ff:
	/* 0x9ff: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a04:
	/* 0xa04: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a09:
	/* 0xa09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a0b:
	/* 0xa0b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a0d:
	/* 0xa0d: js     f4f <generic_sleepable_preload+0xf4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3919ULL;
	}
x86_l_a13:
	/* 0xa13: cmp    WORD PTR [r13+r15*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743798831644672ULL);
x86_l_a1a:
	/* 0xa1a: je     10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4272ULL;
	}
x86_l_a20:
	/* 0xa20: mov    ecx,DWORD PTR [r13+r15*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551546ULL);
x86_l_a25:
	/* 0xa25: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a2a:
	/* 0xa2a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a2f:
	/* 0xa2f: cmp    WORD PTR [r13+r15*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743790241710080ULL);
x86_l_a36:
	/* 0xa36: je     a5b <generic_sleepable_preload+0xa5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a5b;
	}
x86_l_a38:
	/* 0xa38: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a3d:
	/* 0xa3d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a42:
	/* 0xa42: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a47:
	/* 0xa47: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a4c:
	/* 0xa4c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a51:
	/* 0xa51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a53:
	/* 0xa53: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a55:
	/* 0xa55: js     f62 <generic_sleepable_preload+0xf62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3938ULL;
	}
x86_l_a5b:
	/* 0xa5b: cmp    WORD PTR [r13+r15*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743833191383040ULL);
x86_l_a62:
	/* 0xa62: je     10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4272ULL;
	}
x86_l_a68:
	/* 0xa68: mov    ecx,DWORD PTR [r13+r15*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551554ULL);
x86_l_a6d:
	/* 0xa6d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a72:
	/* 0xa72: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a77:
	/* 0xa77: cmp    WORD PTR [r13+r15*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743824601448448ULL);
x86_l_a7e:
	/* 0xa7e: je     aa3 <generic_sleepable_preload+0xaa3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_aa3;
	}
x86_l_a80:
	/* 0xa80: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a85:
	/* 0xa85: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a8a:
	/* 0xa8a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a8f:
	/* 0xa8f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a94:
	/* 0xa94: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a99:
	/* 0xa99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a9b:
	/* 0xa9b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a9d:
	/* 0xa9d: js     f75 <generic_sleepable_preload+0xf75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3957ULL;
	}
x86_l_aa3:
	/* 0xaa3: cmp    WORD PTR [r13+r15*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743867551121408ULL);
x86_l_aaa:
	/* 0xaaa: je     10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4272ULL;
	}
x86_l_ab0:
	/* 0xab0: mov    ecx,DWORD PTR [r13+r15*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551562ULL);
x86_l_ab5:
	/* 0xab5: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_aba:
	/* 0xaba: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_abf:
	/* 0xabf: cmp    WORD PTR [r13+r15*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743858961186816ULL);
x86_l_ac6:
	/* 0xac6: je     aeb <generic_sleepable_preload+0xaeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_aeb;
	}
x86_l_ac8:
	/* 0xac8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_acd:
	/* 0xacd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ad2:
	/* 0xad2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ad7:
	/* 0xad7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_adc:
	/* 0xadc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ae1:
	/* 0xae1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ae3:
	/* 0xae3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ae5:
	/* 0xae5: js     f88 <generic_sleepable_preload+0xf88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3976ULL;
	}
x86_l_aeb:
	/* 0xaeb: cmp    WORD PTR [r13+r15*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743901910859776ULL);
x86_l_af2:
	/* 0xaf2: je     10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4272ULL;
	}
x86_l_af8:
	/* 0xaf8: mov    ecx,DWORD PTR [r13+r15*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551570ULL);
x86_l_afd:
	/* 0xafd: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b02:
	/* 0xb02: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b07:
	/* 0xb07: cmp    WORD PTR [r13+r15*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743893320925184ULL);
x86_l_b0e:
	/* 0xb0e: je     b33 <generic_sleepable_preload+0xb33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b33;
	}
x86_l_b10:
	/* 0xb10: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b15:
	/* 0xb15: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b1a:
	/* 0xb1a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b1f:
	/* 0xb1f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b24:
	/* 0xb24: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b29:
	/* 0xb29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b2b:
	/* 0xb2b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b2d:
	/* 0xb2d: js     f9b <generic_sleepable_preload+0xf9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3995ULL;
	}
x86_l_b33:
	/* 0xb33: cmp    WORD PTR [r13+r15*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743936270598144ULL);
x86_l_b3a:
	/* 0xb3a: je     10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4272ULL;
	}
x86_l_b40:
	/* 0xb40: mov    ecx,DWORD PTR [r13+r15*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551578ULL);
x86_l_b45:
	/* 0xb45: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b4a:
	/* 0xb4a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b4f:
	/* 0xb4f: cmp    WORD PTR [r13+r15*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743927680663552ULL);
x86_l_b56:
	/* 0xb56: je     b7b <generic_sleepable_preload+0xb7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b7b;
	}
x86_l_b58:
	/* 0xb58: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b5d:
	/* 0xb5d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b62:
	/* 0xb62: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b67:
	/* 0xb67: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b6c:
	/* 0xb6c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b71:
	/* 0xb71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b73:
	/* 0xb73: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b75:
	/* 0xb75: js     fae <generic_sleepable_preload+0xfae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4014ULL;
	}
x86_l_b7b:
	/* 0xb7b: cmp    WORD PTR [r13+r15*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743970630336512ULL);
x86_l_b82:
	/* 0xb82: je     10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4272ULL;
	}
x86_l_b88:
	/* 0xb88: mov    ecx,DWORD PTR [r13+r15*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551586ULL);
x86_l_b8d:
	/* 0xb8d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b92:
	/* 0xb92: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b97:
	/* 0xb97: cmp    WORD PTR [r13+r15*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743962040401920ULL);
x86_l_b9e:
	/* 0xb9e: je     bc3 <generic_sleepable_preload+0xbc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bc3;
	}
x86_l_ba0:
	/* 0xba0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ba5:
	/* 0xba5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_baa:
	/* 0xbaa: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_baf:
	/* 0xbaf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bb4:
	/* 0xbb4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bb9:
	/* 0xbb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bbb:
	/* 0xbbb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bbd:
	/* 0xbbd: js     10a2 <generic_sleepable_preload+0x10a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4258ULL;
	}
x86_l_bc3:
	/* 0xbc3: cmp    WORD PTR [r13+r15*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744004990074880ULL);
x86_l_bca:
	/* 0xbca: je     10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4272ULL;
	}
x86_l_bd0:
	/* 0xbd0: mov    ecx,DWORD PTR [r13+r15*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551594ULL);
x86_l_bd5:
	/* 0xbd5: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_bda:
	/* 0xbda: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bdf:
	/* 0xbdf: cmp    WORD PTR [r13+r15*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743996400140288ULL);
x86_l_be6:
	/* 0xbe6: je     c0b <generic_sleepable_preload+0xc0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c0b;
	}
x86_l_be8:
	/* 0xbe8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_bed:
	/* 0xbed: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_bf2:
	/* 0xbf2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bf7:
	/* 0xbf7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bfc:
	/* 0xbfc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c01:
	/* 0xc01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c03:
	/* 0xc03: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c05:
	/* 0xc05: js     1177 <generic_sleepable_preload+0x1177> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4471ULL;
	}
x86_l_c0b:
	/* 0xc0b: cmp    WORD PTR [r13+r15*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744039349813248ULL);
x86_l_c12:
	/* 0xc12: je     10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4272ULL;
	}
x86_l_c18:
	/* 0xc18: mov    ecx,DWORD PTR [r13+r15*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551602ULL);
x86_l_c1d:
	/* 0xc1d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c22:
	/* 0xc22: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c27:
	/* 0xc27: cmp    WORD PTR [r13+r15*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744030759878656ULL);
x86_l_c2e:
	/* 0xc2e: je     c53 <generic_sleepable_preload+0xc53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c53;
	}
x86_l_c30:
	/* 0xc30: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c35:
	/* 0xc35: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c3a:
	/* 0xc3a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c3f:
	/* 0xc3f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c44:
	/* 0xc44: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c49:
	/* 0xc49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c4b:
	/* 0xc4b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c4d:
	/* 0xc4d: js     119e <generic_sleepable_preload+0x119e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4510ULL;
	}
x86_l_c53:
	/* 0xc53: cmp    WORD PTR [r13+r15*1+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_c5a:
	/* 0xc5a: je     10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4272ULL;
	}
x86_l_c60:
	/* 0xc60: mov    ecx,DWORD PTR [r13+r15*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551610ULL);
x86_l_c65:
	/* 0xc65: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c6a:
	/* 0xc6a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c6f:
	/* 0xc6f: cmp    WORD PTR [r13+r15*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744065119617024ULL);
x86_l_c76:
	/* 0xc76: je     10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4272ULL;
	}
x86_l_c7c:
	/* 0xc7c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c81:
	/* 0xc81: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c86:
	/* 0xc86: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c8b:
	/* 0xc8b: jmp    f30 <generic_sleepable_preload+0xf30> */
	return 3888ULL;
x86_l_c90:
	/* 0xc90: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_c93:
	/* 0xc93: je     cb8 <generic_sleepable_preload+0xcb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cb8;
	}
x86_l_c95:
	/* 0xc95: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c9a:
	/* 0xc9a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c9f:
	/* 0xc9f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ca4:
	/* 0xca4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ca9:
	/* 0xca9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cae:
	/* 0xcae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cb0:
	/* 0xcb0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cb2:
	/* 0xcb2: js     f4f <generic_sleepable_preload+0xf4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3919ULL;
	}
x86_l_cb8:
	/* 0xcb8: cmp    WORD PTR [r13+r15*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743798831644672ULL);
x86_l_cbf:
	/* 0xcbf: je     10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4272ULL;
	}
x86_l_cc5:
	/* 0xcc5: mov    ecx,DWORD PTR [r13+r15*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551546ULL);
x86_l_cca:
	/* 0xcca: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ccf:
	/* 0xccf: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cd4:
	/* 0xcd4: cmp    WORD PTR [r13+r15*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743790241710080ULL);
x86_l_cdb:
	/* 0xcdb: je     d00 <generic_sleepable_preload+0xd00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d00;
	}
x86_l_cdd:
	/* 0xcdd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ce2:
	/* 0xce2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ce7:
	/* 0xce7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cec:
	/* 0xcec: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cf1:
	/* 0xcf1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cf6:
	/* 0xcf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf8:
	/* 0xcf8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cfa:
	/* 0xcfa: js     f62 <generic_sleepable_preload+0xf62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3938ULL;
	}
x86_l_d00:
	/* 0xd00: cmp    WORD PTR [r13+r15*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743833191383040ULL);
x86_l_d07:
	/* 0xd07: je     10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4272ULL;
	}
x86_l_d0d:
	/* 0xd0d: mov    ecx,DWORD PTR [r13+r15*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551554ULL);
x86_l_d12:
	/* 0xd12: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d17:
	/* 0xd17: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d1c:
	/* 0xd1c: cmp    WORD PTR [r13+r15*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743824601448448ULL);
x86_l_d23:
	/* 0xd23: je     d48 <generic_sleepable_preload+0xd48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d48;
	}
x86_l_d25:
	/* 0xd25: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d2a:
	/* 0xd2a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d2f:
	/* 0xd2f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d34:
	/* 0xd34: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d39:
	/* 0xd39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d3e:
	/* 0xd3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d40:
	/* 0xd40: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d42:
	/* 0xd42: js     f75 <generic_sleepable_preload+0xf75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3957ULL;
	}
x86_l_d48:
	/* 0xd48: cmp    WORD PTR [r13+r15*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743867551121408ULL);
x86_l_d4f:
	/* 0xd4f: je     10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4272ULL;
	}
x86_l_d55:
	/* 0xd55: mov    ecx,DWORD PTR [r13+r15*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551562ULL);
x86_l_d5a:
	/* 0xd5a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d5f:
	/* 0xd5f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d64:
	/* 0xd64: cmp    WORD PTR [r13+r15*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743858961186816ULL);
x86_l_d6b:
	/* 0xd6b: je     d90 <generic_sleepable_preload+0xd90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d90;
	}
x86_l_d6d:
	/* 0xd6d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d72:
	/* 0xd72: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d77:
	/* 0xd77: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d7c:
	/* 0xd7c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d81:
	/* 0xd81: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d86:
	/* 0xd86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d88:
	/* 0xd88: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d8a:
	/* 0xd8a: js     f88 <generic_sleepable_preload+0xf88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3976ULL;
	}
x86_l_d90:
	/* 0xd90: cmp    WORD PTR [r13+r15*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743901910859776ULL);
x86_l_d97:
	/* 0xd97: je     10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4272ULL;
	}
x86_l_d9d:
	/* 0xd9d: mov    ecx,DWORD PTR [r13+r15*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551570ULL);
x86_l_da2:
	/* 0xda2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_da7:
	/* 0xda7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dac:
	/* 0xdac: cmp    WORD PTR [r13+r15*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743893320925184ULL);
x86_l_db3:
	/* 0xdb3: je     dd8 <generic_sleepable_preload+0xdd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dd8;
	}
x86_l_db5:
	/* 0xdb5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_dba:
	/* 0xdba: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_dbf:
	/* 0xdbf: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dc4:
	/* 0xdc4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dc9:
	/* 0xdc9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dce:
	/* 0xdce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dd0:
	/* 0xdd0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dd2:
	/* 0xdd2: js     f9b <generic_sleepable_preload+0xf9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3995ULL;
	}
x86_l_dd8:
	/* 0xdd8: cmp    WORD PTR [r13+r15*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743936270598144ULL);
x86_l_ddf:
	/* 0xddf: je     10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4272ULL;
	}
x86_l_de5:
	/* 0xde5: mov    ecx,DWORD PTR [r13+r15*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551578ULL);
x86_l_dea:
	/* 0xdea: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_def:
	/* 0xdef: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_df4:
	/* 0xdf4: cmp    WORD PTR [r13+r15*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743927680663552ULL);
	return 3579ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3579ULL: goto x86_l_dfb;
	case 3581ULL: goto x86_l_dfd;
	case 3586ULL: goto x86_l_e02;
	case 3591ULL: goto x86_l_e07;
	case 3596ULL: goto x86_l_e0c;
	case 3601ULL: goto x86_l_e11;
	case 3606ULL: goto x86_l_e16;
	case 3608ULL: goto x86_l_e18;
	case 3610ULL: goto x86_l_e1a;
	case 3616ULL: goto x86_l_e20;
	case 3623ULL: goto x86_l_e27;
	case 3629ULL: goto x86_l_e2d;
	case 3634ULL: goto x86_l_e32;
	case 3639ULL: goto x86_l_e37;
	case 3644ULL: goto x86_l_e3c;
	case 3651ULL: goto x86_l_e43;
	case 3653ULL: goto x86_l_e45;
	case 3658ULL: goto x86_l_e4a;
	case 3663ULL: goto x86_l_e4f;
	case 3668ULL: goto x86_l_e54;
	case 3673ULL: goto x86_l_e59;
	case 3678ULL: goto x86_l_e5e;
	case 3680ULL: goto x86_l_e60;
	case 3682ULL: goto x86_l_e62;
	case 3688ULL: goto x86_l_e68;
	case 3695ULL: goto x86_l_e6f;
	case 3701ULL: goto x86_l_e75;
	case 3706ULL: goto x86_l_e7a;
	case 3711ULL: goto x86_l_e7f;
	case 3716ULL: goto x86_l_e84;
	case 3723ULL: goto x86_l_e8b;
	case 3725ULL: goto x86_l_e8d;
	case 3730ULL: goto x86_l_e92;
	case 3735ULL: goto x86_l_e97;
	case 3740ULL: goto x86_l_e9c;
	case 3745ULL: goto x86_l_ea1;
	case 3750ULL: goto x86_l_ea6;
	case 3752ULL: goto x86_l_ea8;
	case 3754ULL: goto x86_l_eaa;
	case 3760ULL: goto x86_l_eb0;
	case 3767ULL: goto x86_l_eb7;
	case 3773ULL: goto x86_l_ebd;
	case 3778ULL: goto x86_l_ec2;
	case 3783ULL: goto x86_l_ec7;
	case 3788ULL: goto x86_l_ecc;
	case 3795ULL: goto x86_l_ed3;
	case 3797ULL: goto x86_l_ed5;
	case 3802ULL: goto x86_l_eda;
	case 3807ULL: goto x86_l_edf;
	case 3812ULL: goto x86_l_ee4;
	case 3817ULL: goto x86_l_ee9;
	case 3822ULL: goto x86_l_eee;
	case 3824ULL: goto x86_l_ef0;
	case 3826ULL: goto x86_l_ef2;
	case 3832ULL: goto x86_l_ef8;
	case 3839ULL: goto x86_l_eff;
	case 3845ULL: goto x86_l_f05;
	case 3850ULL: goto x86_l_f0a;
	case 3855ULL: goto x86_l_f0f;
	case 3860ULL: goto x86_l_f14;
	case 3867ULL: goto x86_l_f1b;
	case 3873ULL: goto x86_l_f21;
	case 3878ULL: goto x86_l_f26;
	case 3883ULL: goto x86_l_f2b;
	case 3888ULL: goto x86_l_f30;
	case 3893ULL: goto x86_l_f35;
	case 3898ULL: goto x86_l_f3a;
	case 3900ULL: goto x86_l_f3c;
	case 3902ULL: goto x86_l_f3e;
	case 3908ULL: goto x86_l_f44;
	case 3914ULL: goto x86_l_f4a;
	case 3919ULL: goto x86_l_f4f;
	case 3925ULL: goto x86_l_f55;
	case 3930ULL: goto x86_l_f5a;
	case 3936ULL: goto x86_l_f60;
	case 3938ULL: goto x86_l_f62;
	case 3944ULL: goto x86_l_f68;
	case 3949ULL: goto x86_l_f6d;
	case 3955ULL: goto x86_l_f73;
	case 3957ULL: goto x86_l_f75;
	case 3963ULL: goto x86_l_f7b;
	case 3968ULL: goto x86_l_f80;
	case 3974ULL: goto x86_l_f86;
	case 3976ULL: goto x86_l_f88;
	case 3982ULL: goto x86_l_f8e;
	case 3987ULL: goto x86_l_f93;
	case 3993ULL: goto x86_l_f99;
	case 3995ULL: goto x86_l_f9b;
	case 4001ULL: goto x86_l_fa1;
	case 4006ULL: goto x86_l_fa6;
	case 4012ULL: goto x86_l_fac;
	case 4014ULL: goto x86_l_fae;
	case 4020ULL: goto x86_l_fb4;
	case 4025ULL: goto x86_l_fb9;
	case 4031ULL: goto x86_l_fbf;
	case 4039ULL: goto x86_l_fc7;
	case 4042ULL: goto x86_l_fca;
	case 4047ULL: goto x86_l_fcf;
	case 4052ULL: goto x86_l_fd4;
	case 4057ULL: goto x86_l_fd9;
	case 4060ULL: goto x86_l_fdc;
	case 4062ULL: goto x86_l_fde;
	case 4066ULL: goto x86_l_fe2;
	case 4072ULL: goto x86_l_fe8;
	case 4077ULL: goto x86_l_fed;
	case 4085ULL: goto x86_l_ff5;
	case 4090ULL: goto x86_l_ffa;
	case 4092ULL: goto x86_l_ffc;
	case 4097ULL: goto x86_l_1001;
	case 4105ULL: goto x86_l_1009;
	case 4110ULL: goto x86_l_100e;
	case 4117ULL: goto x86_l_1015;
	case 4122ULL: goto x86_l_101a;
	case 4124ULL: goto x86_l_101c;
	case 4127ULL: goto x86_l_101f;
	case 4133ULL: goto x86_l_1025;
	case 4136ULL: goto x86_l_1028;
	case 4141ULL: goto x86_l_102d;
	case 4143ULL: goto x86_l_102f;
	case 4148ULL: goto x86_l_1034;
	case 4151ULL: goto x86_l_1037;
	case 4158ULL: goto x86_l_103e;
	case 4161ULL: goto x86_l_1041;
	case 4164ULL: goto x86_l_1044;
	case 4166ULL: goto x86_l_1046;
	case 4168ULL: goto x86_l_1048;
	case 4173ULL: goto x86_l_104d;
	case 4176ULL: goto x86_l_1050;
	case 4179ULL: goto x86_l_1053;
	case 4182ULL: goto x86_l_1056;
	case 4184ULL: goto x86_l_1058;
	case 4187ULL: goto x86_l_105b;
	case 4193ULL: goto x86_l_1061;
	case 4198ULL: goto x86_l_1066;
	case 4204ULL: goto x86_l_106c;
	case 4208ULL: goto x86_l_1070;
	case 4213ULL: goto x86_l_1075;
	case 4221ULL: goto x86_l_107d;
	case 4223ULL: goto x86_l_107f;
	case 4226ULL: goto x86_l_1082;
	case 4231ULL: goto x86_l_1087;
	case 4233ULL: goto x86_l_1089;
	case 4236ULL: goto x86_l_108c;
	case 4239ULL: goto x86_l_108f;
	case 4241ULL: goto x86_l_1091;
	case 4247ULL: goto x86_l_1097;
	case 4253ULL: goto x86_l_109d;
	case 4258ULL: goto x86_l_10a2;
	case 4264ULL: goto x86_l_10a8;
	case 4272ULL: goto x86_l_10b0;
	case 4275ULL: goto x86_l_10b3;
	case 4281ULL: goto x86_l_10b9;
	case 4286ULL: goto x86_l_10be;
	case 4294ULL: goto x86_l_10c6;
	case 4299ULL: goto x86_l_10cb;
	case 4301ULL: goto x86_l_10cd;
	case 4306ULL: goto x86_l_10d2;
	case 4314ULL: goto x86_l_10da;
	case 4319ULL: goto x86_l_10df;
	case 4326ULL: goto x86_l_10e6;
	case 4331ULL: goto x86_l_10eb;
	case 4333ULL: goto x86_l_10ed;
	case 4336ULL: goto x86_l_10f0;
	case 4342ULL: goto x86_l_10f6;
	case 4345ULL: goto x86_l_10f9;
	case 4350ULL: goto x86_l_10fe;
	case 4352ULL: goto x86_l_1100;
	case 4357ULL: goto x86_l_1105;
	case 4360ULL: goto x86_l_1108;
	case 4367ULL: goto x86_l_110f;
	case 4370ULL: goto x86_l_1112;
	case 4373ULL: goto x86_l_1115;
	case 4375ULL: goto x86_l_1117;
	case 4377ULL: goto x86_l_1119;
	case 4382ULL: goto x86_l_111e;
	case 4385ULL: goto x86_l_1121;
	case 4388ULL: goto x86_l_1124;
	case 4390ULL: goto x86_l_1126;
	case 4393ULL: goto x86_l_1129;
	case 4399ULL: goto x86_l_112f;
	case 4402ULL: goto x86_l_1132;
	case 4407ULL: goto x86_l_1137;
	case 4409ULL: goto x86_l_1139;
	case 4413ULL: goto x86_l_113d;
	case 4418ULL: goto x86_l_1142;
	case 4426ULL: goto x86_l_114a;
	case 4428ULL: goto x86_l_114c;
	case 4433ULL: goto x86_l_1151;
	case 4435ULL: goto x86_l_1153;
	case 4437ULL: goto x86_l_1155;
	case 4443ULL: goto x86_l_115b;
	case 4447ULL: goto x86_l_115f;
	case 4452ULL: goto x86_l_1164;
	case 4460ULL: goto x86_l_116c;
	case 4466ULL: goto x86_l_1172;
	case 4471ULL: goto x86_l_1177;
	case 4479ULL: goto x86_l_117f;
	case 4485ULL: goto x86_l_1185;
	case 4488ULL: goto x86_l_1188;
	case 4494ULL: goto x86_l_118e;
	case 4499ULL: goto x86_l_1193;
	case 4505ULL: goto x86_l_1199;
	case 4510ULL: goto x86_l_119e;
	case 4516ULL: goto x86_l_11a4;
	case 4521ULL: goto x86_l_11a9;
	case 4525ULL: goto x86_l_11ad;
	case 4530ULL: goto x86_l_11b2;
	case 4532ULL: goto x86_l_11b4;
	case 4536ULL: goto x86_l_11b8;
	case 4541ULL: goto x86_l_11bd;
	case 4547ULL: goto x86_l_11c3;
	case 4551ULL: goto x86_l_11c7;
	case 4556ULL: goto x86_l_11cc;
	case 4561ULL: goto x86_l_11d1;
	case 4567ULL: goto x86_l_11d7;
	case 4571ULL: goto x86_l_11db;
	case 4576ULL: goto x86_l_11e0;
	case 4582ULL: goto x86_l_11e6;
	case 4586ULL: goto x86_l_11ea;
	case 4591ULL: goto x86_l_11ef;
	case 4597ULL: goto x86_l_11f5;
	case 4599ULL: goto x86_l_11f7;
	case 4606ULL: goto x86_l_11fe;
	case 4607ULL: goto x86_l_11ff;
	case 4609ULL: goto x86_l_1201;
	case 4611ULL: goto x86_l_1203;
	case 4613ULL: goto x86_l_1205;
	case 4615ULL: goto x86_l_1207;
	case 4616ULL: goto x86_l_1208;
	case 4621ULL: goto x86_l_120d;
	case 4623ULL: goto x86_l_120f;
	case 4629ULL: goto x86_l_1215;
	case 4637ULL: goto x86_l_121d;
	case 4639ULL: goto x86_l_121f;
	case 4642ULL: goto x86_l_1222;
	case 4648ULL: goto x86_l_1228;
	case 4651ULL: goto x86_l_122b;
	case 4657ULL: goto x86_l_1231;
	case 4660ULL: goto x86_l_1234;
	case 4666ULL: goto x86_l_123a;
	case 4673ULL: goto x86_l_1241;
	case 4679ULL: goto x86_l_1247;
	case 4682ULL: goto x86_l_124a;
	case 4687ULL: goto x86_l_124f;
	case 4692ULL: goto x86_l_1254;
	case 4697ULL: goto x86_l_1259;
	case 4702ULL: goto x86_l_125e;
	case 4704ULL: goto x86_l_1260;
	case 4706ULL: goto x86_l_1262;
	case 4712ULL: goto x86_l_1268;
	case 4714ULL: goto x86_l_126a;
	case 4719ULL: goto x86_l_126f;
	case 4721ULL: goto x86_l_1271;
	case 4727ULL: goto x86_l_1277;
	case 4735ULL: goto x86_l_127f;
	case 4737ULL: goto x86_l_1281;
	case 4740ULL: goto x86_l_1284;
	case 4746ULL: goto x86_l_128a;
	case 4749ULL: goto x86_l_128d;
	case 4755ULL: goto x86_l_1293;
	case 4758ULL: goto x86_l_1296;
	case 4764ULL: goto x86_l_129c;
	case 4771ULL: goto x86_l_12a3;
	case 4777ULL: goto x86_l_12a9;
	case 4780ULL: goto x86_l_12ac;
	case 4785ULL: goto x86_l_12b1;
	case 4790ULL: goto x86_l_12b6;
	case 4795ULL: goto x86_l_12bb;
	case 4800ULL: goto x86_l_12c0;
	case 4802ULL: goto x86_l_12c2;
	case 4804ULL: goto x86_l_12c4;
	case 4810ULL: goto x86_l_12ca;
	case 4812ULL: goto x86_l_12cc;
	case 4817ULL: goto x86_l_12d1;
	case 4819ULL: goto x86_l_12d3;
	case 4825ULL: goto x86_l_12d9;
	case 4833ULL: goto x86_l_12e1;
	case 4835ULL: goto x86_l_12e3;
	case 4838ULL: goto x86_l_12e6;
	case 4844ULL: goto x86_l_12ec;
	case 4847ULL: goto x86_l_12ef;
	case 4852ULL: goto x86_l_12f4;
	case 4858ULL: goto x86_l_12fa;
	case 4861ULL: goto x86_l_12fd;
	case 4867ULL: goto x86_l_1303;
	case 4874ULL: goto x86_l_130a;
	case 4880ULL: goto x86_l_1310;
	case 4883ULL: goto x86_l_1313;
	case 4888ULL: goto x86_l_1318;
	case 4893ULL: goto x86_l_131d;
	case 4898ULL: goto x86_l_1322;
	case 4903ULL: goto x86_l_1327;
	case 4905ULL: goto x86_l_1329;
	case 4907ULL: goto x86_l_132b;
	case 4913ULL: goto x86_l_1331;
	case 4915ULL: goto x86_l_1333;
	case 4920ULL: goto x86_l_1338;
	case 4922ULL: goto x86_l_133a;
	case 4928ULL: goto x86_l_1340;
	case 4936ULL: goto x86_l_1348;
	case 4938ULL: goto x86_l_134a;
	case 4941ULL: goto x86_l_134d;
	case 4946ULL: goto x86_l_1352;
	case 4952ULL: goto x86_l_1358;
	case 4955ULL: goto x86_l_135b;
	case 4961ULL: goto x86_l_1361;
	case 4964ULL: goto x86_l_1364;
	case 4970ULL: goto x86_l_136a;
	case 4977ULL: goto x86_l_1371;
	case 4983ULL: goto x86_l_1377;
	case 4986ULL: goto x86_l_137a;
	case 4991ULL: goto x86_l_137f;
	case 4996ULL: goto x86_l_1384;
	case 5001ULL: goto x86_l_1389;
	case 5006ULL: goto x86_l_138e;
	case 5008ULL: goto x86_l_1390;
	case 5010ULL: goto x86_l_1392;
	case 5016ULL: goto x86_l_1398;
	case 5018ULL: goto x86_l_139a;
	case 5023ULL: goto x86_l_139f;
	case 5025ULL: goto x86_l_13a1;
	case 5031ULL: goto x86_l_13a7;
	case 5039ULL: goto x86_l_13af;
	case 5041ULL: goto x86_l_13b1;
	case 5044ULL: goto x86_l_13b4;
	case 5050ULL: goto x86_l_13ba;
	case 5053ULL: goto x86_l_13bd;
	case 5058ULL: goto x86_l_13c2;
	case 5064ULL: goto x86_l_13c8;
	case 5067ULL: goto x86_l_13cb;
	case 5073ULL: goto x86_l_13d1;
	case 5080ULL: goto x86_l_13d8;
	case 5085ULL: goto x86_l_13dd;
	case 5088ULL: goto x86_l_13e0;
	case 5093ULL: goto x86_l_13e5;
	case 5098ULL: goto x86_l_13ea;
	case 5103ULL: goto x86_l_13ef;
	case 5108ULL: goto x86_l_13f4;
	case 5110ULL: goto x86_l_13f6;
	case 5112ULL: goto x86_l_13f8;
	case 5118ULL: goto x86_l_13fe;
	case 5120ULL: goto x86_l_1400;
	case 5125ULL: goto x86_l_1405;
	case 5133ULL: goto x86_l_140d;
	case 5141ULL: goto x86_l_1415;
	case 5147ULL: goto x86_l_141b;
	case 5149ULL: goto x86_l_141d;
	case 5152ULL: goto x86_l_1420;
	case 5158ULL: goto x86_l_1426;
	case 5161ULL: goto x86_l_1429;
	case 5167ULL: goto x86_l_142f;
	case 5170ULL: goto x86_l_1432;
	case 5176ULL: goto x86_l_1438;
	case 5184ULL: goto x86_l_1440;
	case 5187ULL: goto x86_l_1443;
	case 5193ULL: goto x86_l_1449;
	case 5198ULL: goto x86_l_144e;
	case 5201ULL: goto x86_l_1451;
	case 5207ULL: goto x86_l_1457;
	case 5210ULL: goto x86_l_145a;
	case 5216ULL: goto x86_l_1460;
	case 5221ULL: goto x86_l_1465;
	case 5226ULL: goto x86_l_146a;
	case 5234ULL: goto x86_l_1472;
	case 5242ULL: goto x86_l_147a;
	case 5248ULL: goto x86_l_1480;
	case 5250ULL: goto x86_l_1482;
	case 5253ULL: goto x86_l_1485;
	case 5259ULL: goto x86_l_148b;
	case 5262ULL: goto x86_l_148e;
	case 5268ULL: goto x86_l_1494;
	case 5271ULL: goto x86_l_1497;
	case 5277ULL: goto x86_l_149d;
	case 5285ULL: goto x86_l_14a5;
	case 5288ULL: goto x86_l_14a8;
	case 5294ULL: goto x86_l_14ae;
	case 5299ULL: goto x86_l_14b3;
	case 5302ULL: goto x86_l_14b6;
	case 5308ULL: goto x86_l_14bc;
	case 5313ULL: goto x86_l_14c1;
	case 5316ULL: goto x86_l_14c4;
	case 5322ULL: goto x86_l_14ca;
	case 5327ULL: goto x86_l_14cf;
	case 5335ULL: goto x86_l_14d7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_dfb:
	/* 0xdfb: je     e20 <generic_sleepable_preload+0xe20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e20;
	}
x86_l_dfd:
	/* 0xdfd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e02:
	/* 0xe02: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e07:
	/* 0xe07: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e0c:
	/* 0xe0c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e11:
	/* 0xe11: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e16:
	/* 0xe16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e18:
	/* 0xe18: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e1a:
	/* 0xe1a: js     fae <generic_sleepable_preload+0xfae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_fae;
	}
x86_l_e20:
	/* 0xe20: cmp    WORD PTR [r13+r15*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743970630336512ULL);
x86_l_e27:
	/* 0xe27: je     10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b0;
	}
x86_l_e2d:
	/* 0xe2d: mov    ecx,DWORD PTR [r13+r15*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551586ULL);
x86_l_e32:
	/* 0xe32: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e37:
	/* 0xe37: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e3c:
	/* 0xe3c: cmp    WORD PTR [r13+r15*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743962040401920ULL);
x86_l_e43:
	/* 0xe43: je     e68 <generic_sleepable_preload+0xe68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e68;
	}
x86_l_e45:
	/* 0xe45: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e4a:
	/* 0xe4a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e4f:
	/* 0xe4f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e54:
	/* 0xe54: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e59:
	/* 0xe59: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e5e:
	/* 0xe5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e60:
	/* 0xe60: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e62:
	/* 0xe62: js     10a2 <generic_sleepable_preload+0x10a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_10a2;
	}
x86_l_e68:
	/* 0xe68: cmp    WORD PTR [r13+r15*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744004990074880ULL);
x86_l_e6f:
	/* 0xe6f: je     10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b0;
	}
x86_l_e75:
	/* 0xe75: mov    ecx,DWORD PTR [r13+r15*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551594ULL);
x86_l_e7a:
	/* 0xe7a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e7f:
	/* 0xe7f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e84:
	/* 0xe84: cmp    WORD PTR [r13+r15*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743996400140288ULL);
x86_l_e8b:
	/* 0xe8b: je     eb0 <generic_sleepable_preload+0xeb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eb0;
	}
x86_l_e8d:
	/* 0xe8d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e92:
	/* 0xe92: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e97:
	/* 0xe97: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e9c:
	/* 0xe9c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ea1:
	/* 0xea1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ea6:
	/* 0xea6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea8:
	/* 0xea8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_eaa:
	/* 0xeaa: js     1177 <generic_sleepable_preload+0x1177> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1177;
	}
x86_l_eb0:
	/* 0xeb0: cmp    WORD PTR [r13+r15*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744039349813248ULL);
x86_l_eb7:
	/* 0xeb7: je     10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b0;
	}
x86_l_ebd:
	/* 0xebd: mov    ecx,DWORD PTR [r13+r15*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551602ULL);
x86_l_ec2:
	/* 0xec2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ec7:
	/* 0xec7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ecc:
	/* 0xecc: cmp    WORD PTR [r13+r15*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744030759878656ULL);
x86_l_ed3:
	/* 0xed3: je     ef8 <generic_sleepable_preload+0xef8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ef8;
	}
x86_l_ed5:
	/* 0xed5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_eda:
	/* 0xeda: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_edf:
	/* 0xedf: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ee4:
	/* 0xee4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ee9:
	/* 0xee9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_eee:
	/* 0xeee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef0:
	/* 0xef0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ef2:
	/* 0xef2: js     119e <generic_sleepable_preload+0x119e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_119e;
	}
x86_l_ef8:
	/* 0xef8: cmp    WORD PTR [r13+r15*1+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_eff:
	/* 0xeff: je     10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b0;
	}
x86_l_f05:
	/* 0xf05: mov    ecx,DWORD PTR [r13+r15*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551610ULL);
x86_l_f0a:
	/* 0xf0a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_f0f:
	/* 0xf0f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f14:
	/* 0xf14: cmp    WORD PTR [r13+r15*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744065119617024ULL);
x86_l_f1b:
	/* 0xf1b: je     10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b0;
	}
x86_l_f21:
	/* 0xf21: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_f26:
	/* 0xf26: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_f2b:
	/* 0xf2b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f30:
	/* 0xf30: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f35:
	/* 0xf35: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f3a:
	/* 0xf3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f3c:
	/* 0xf3c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f3e:
	/* 0xf3e: jns    10b0 <generic_sleepable_preload+0x10b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_10b0;
	}
x86_l_f44:
	/* 0xf44: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_f4a:
	/* 0xf4a: jmp    10a8 <generic_sleepable_preload+0x10a8> */
	goto x86_l_10a8;
x86_l_f4f:
	/* 0xf4f: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_f55:
	/* 0xf55: jmp    10a8 <generic_sleepable_preload+0x10a8> */
	goto x86_l_10a8;
x86_l_f5a:
	/* 0xf5a: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_f60:
	/* 0xf60: jmp    fbf <generic_sleepable_preload+0xfbf> */
	goto x86_l_fbf;
x86_l_f62:
	/* 0xf62: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_f68:
	/* 0xf68: jmp    10a8 <generic_sleepable_preload+0x10a8> */
	goto x86_l_10a8;
x86_l_f6d:
	/* 0xf6d: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_f73:
	/* 0xf73: jmp    fbf <generic_sleepable_preload+0xfbf> */
	goto x86_l_fbf;
x86_l_f75:
	/* 0xf75: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_f7b:
	/* 0xf7b: jmp    10a8 <generic_sleepable_preload+0x10a8> */
	goto x86_l_10a8;
x86_l_f80:
	/* 0xf80: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_f86:
	/* 0xf86: jmp    fbf <generic_sleepable_preload+0xfbf> */
	goto x86_l_fbf;
x86_l_f88:
	/* 0xf88: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_f8e:
	/* 0xf8e: jmp    10a8 <generic_sleepable_preload+0x10a8> */
	goto x86_l_10a8;
x86_l_f93:
	/* 0xf93: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_f99:
	/* 0xf99: jmp    fbf <generic_sleepable_preload+0xfbf> */
	goto x86_l_fbf;
x86_l_f9b:
	/* 0xf9b: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_fa1:
	/* 0xfa1: jmp    10a8 <generic_sleepable_preload+0x10a8> */
	goto x86_l_10a8;
x86_l_fa6:
	/* 0xfa6: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_fac:
	/* 0xfac: jmp    fbf <generic_sleepable_preload+0xfbf> */
	goto x86_l_fbf;
x86_l_fae:
	/* 0xfae: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_fb4:
	/* 0xfb4: jmp    10a8 <generic_sleepable_preload+0x10a8> */
	goto x86_l_10a8;
x86_l_fb9:
	/* 0xfb9: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_fbf:
	/* 0xfbf: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_fc7:
	/* 0xfc7: mov    r13d,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fca:
	/* 0xfca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fcf:
	/* 0xfcf: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fd4:
	/* 0xfd4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fd9:
	/* 0xfd9: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_fdc:
	/* 0xfdc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fde:
	/* 0xfde: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_fe2:
	/* 0xfe2: jne    126 <generic_sleepable_preload+0x126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 294ULL;
	}
x86_l_fe8:
	/* 0xfe8: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fed:
	/* 0xfed: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_ff5:
	/* 0xff5: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_ffa:
	/* 0xffa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ffc:
	/* 0xffc: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1001:
	/* 0x1001: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1009:
	/* 0x1009: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_100e:
	/* 0x100e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1015:
	/* 0x1015: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_101a:
	/* 0x101a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_101c:
	/* 0x101c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_101f:
	/* 0x101f: je     126 <generic_sleepable_preload+0x126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 294ULL;
	}
x86_l_1025:
	/* 0x1025: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1028:
	/* 0x1028: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_102d:
	/* 0x102d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_102f:
	/* 0x102f: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1034:
	/* 0x1034: mov    r13d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_32);
x86_l_1037:
	/* 0x1037: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_103e:
	/* 0x103e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1041:
	/* 0x1041: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1044:
	/* 0x1044: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1046:
	/* 0x1046: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1048:
	/* 0x1048: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_104d:
	/* 0x104d: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1050:
	/* 0x1050: mov    r12d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_32);
x86_l_1053:
	/* 0x1053: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1056:
	/* 0x1056: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1058:
	/* 0x1058: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_105b:
	/* 0x105b: je     126 <generic_sleepable_preload+0x126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 294ULL;
	}
x86_l_1061:
	/* 0x1061: cmp    BYTE PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1066:
	/* 0x1066: je     123 <generic_sleepable_preload+0x123> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 291ULL;
	}
x86_l_106c:
	/* 0x106c: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1070:
	/* 0x1070: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1075:
	/* 0x1075: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_107d:
	/* 0x107d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_107f:
	/* 0x107f: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1082:
	/* 0x1082: call   1087 <generic_sleepable_preload+0x1087> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_1087:
	/* 0x1087: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1089:
	/* 0x1089: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_108c:
	/* 0x108c: mov    r12d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_32);
x86_l_108f:
	/* 0x108f: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1091:
	/* 0x1091: jns    123 <generic_sleepable_preload+0x123> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 291ULL;
	}
x86_l_1097:
	/* 0x1097: mov    r12d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_109d:
	/* 0x109d: jmp    123 <generic_sleepable_preload+0x123> */
	return 291ULL;
x86_l_10a2:
	/* 0x10a2: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_10a8:
	/* 0x10a8: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_10b0:
	/* 0x10b0: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_10b3:
	/* 0x10b3: jne    12b <generic_sleepable_preload+0x12b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 299ULL;
	}
x86_l_10b9:
	/* 0x10b9: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10be:
	/* 0x10be: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_10c6:
	/* 0x10c6: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_10cb:
	/* 0x10cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10cd:
	/* 0x10cd: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10d2:
	/* 0x10d2: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_10da:
	/* 0x10da: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10df:
	/* 0x10df: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_10e6:
	/* 0x10e6: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10eb:
	/* 0x10eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ed:
	/* 0x10ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10f0:
	/* 0x10f0: je     126 <generic_sleepable_preload+0x126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 294ULL;
	}
x86_l_10f6:
	/* 0x10f6: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_10f9:
	/* 0x10f9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_10fe:
	/* 0x10fe: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1100:
	/* 0x1100: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1105:
	/* 0x1105: mov    r13d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_32);
x86_l_1108:
	/* 0x1108: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_110f:
	/* 0x110f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1112:
	/* 0x1112: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1115:
	/* 0x1115: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1117:
	/* 0x1117: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1119:
	/* 0x1119: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_111e:
	/* 0x111e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1121:
	/* 0x1121: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1124:
	/* 0x1124: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1126:
	/* 0x1126: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1129:
	/* 0x1129: je     126 <generic_sleepable_preload+0x126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 294ULL;
	}
x86_l_112f:
	/* 0x112f: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1132:
	/* 0x1132: cmp    BYTE PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1137:
	/* 0x1137: je     115b <generic_sleepable_preload+0x115b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_115b;
	}
x86_l_1139:
	/* 0x1139: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_113d:
	/* 0x113d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1142:
	/* 0x1142: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_114a:
	/* 0x114a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_114c:
	/* 0x114c: call   1151 <generic_sleepable_preload+0x1151> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_1151:
	/* 0x1151: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1153:
	/* 0x1153: jns    115b <generic_sleepable_preload+0x115b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_115b;
	}
x86_l_1155:
	/* 0x1155: mov    r13d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967295ULL);
x86_l_115b:
	/* 0x115b: mov    DWORD PTR [rbp+0x0],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_115f:
	/* 0x115f: jmp    126 <generic_sleepable_preload+0x126> */
	return 294ULL;
x86_l_1164:
	/* 0x1164: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_116c:
	/* 0x116c: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_1172:
	/* 0x1172: jmp    fc7 <generic_sleepable_preload+0xfc7> */
	goto x86_l_fc7;
x86_l_1177:
	/* 0x1177: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_117f:
	/* 0x117f: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_1185:
	/* 0x1185: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1188:
	/* 0x1188: jne    12b <generic_sleepable_preload+0x12b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 299ULL;
	}
x86_l_118e:
	/* 0x118e: jmp    10b9 <generic_sleepable_preload+0x10b9> */
	goto x86_l_10b9;
x86_l_1193:
	/* 0x1193: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_1199:
	/* 0x1199: jmp    fbf <generic_sleepable_preload+0xfbf> */
	goto x86_l_fbf;
x86_l_119e:
	/* 0x119e: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_11a4:
	/* 0x11a4: jmp    10a8 <generic_sleepable_preload+0x10a8> */
	goto x86_l_10a8;
x86_l_11a9:
	/* 0x11a9: mov    eax,DWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11ad:
	/* 0x11ad: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_11b2:
	/* 0x11b2: jne    120d <generic_sleepable_preload+0x120d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_120d;
	}
x86_l_11b4:
	/* 0x11b4: mov    eax,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_11b8:
	/* 0x11b8: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_11bd:
	/* 0x11bd: jne    126f <generic_sleepable_preload+0x126f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_126f;
	}
x86_l_11c3:
	/* 0x11c3: mov    eax,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11c7:
	/* 0x11c7: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_11cc:
	/* 0x11cc: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11d1:
	/* 0x11d1: jne    12d1 <generic_sleepable_preload+0x12d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_12d1;
	}
x86_l_11d7:
	/* 0x11d7: mov    eax,DWORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_11db:
	/* 0x11db: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_11e0:
	/* 0x11e0: jne    1338 <generic_sleepable_preload+0x1338> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1338;
	}
x86_l_11e6:
	/* 0x11e6: mov    eax,DWORD PTR [r13+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11ea:
	/* 0x11ea: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_11ef:
	/* 0x11ef: jne    139f <generic_sleepable_preload+0x139f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_139f;
	}
x86_l_11f5:
	/* 0x11f5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11f7:
	/* 0x11f7: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_11fe:
	/* 0x11fe: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_11ff:
	/* 0x11ff: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1201:
	/* 0x1201: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_1203:
	/* 0x1203: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1205:
	/* 0x1205: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1207:
	/* 0x1207: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1208:
	/* 0x1208: jmp    6a6e <generic_sleepable_preload+0x6a6e> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_120d:
	/* 0x120d: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_120f:
	/* 0x120f: js     1405 <generic_sleepable_preload+0x1405> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1405;
	}
x86_l_1215:
	/* 0x1215: movzx  eax,BYTE PTR [r13+0x211] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 529ULL);
x86_l_121d:
	/* 0x121d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_121f:
	/* 0x121f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1222:
	/* 0x1222: jg     15fe <generic_sleepable_preload+0x15fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5630ULL;
	}
x86_l_1228:
	/* 0x1228: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_122b:
	/* 0x122b: je     1b6f <generic_sleepable_preload+0x1b6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7023ULL;
	}
x86_l_1231:
	/* 0x1231: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1234:
	/* 0x1234: jne    1ce5 <generic_sleepable_preload+0x1ce5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7397ULL;
	}
x86_l_123a:
	/* 0x123a: mov    edx,DWORD PTR [r13+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_1241:
	/* 0x1241: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1247:
	/* 0x1247: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_124a:
	/* 0x124a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_124f:
	/* 0x124f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1254:
	/* 0x1254: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1259:
	/* 0x1259: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_125e:
	/* 0x125e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1260:
	/* 0x1260: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1262:
	/* 0x1262: je     1b7b <generic_sleepable_preload+0x1b7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7035ULL;
	}
x86_l_1268:
	/* 0x1268: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_126a:
	/* 0x126a: jmp    1ce5 <generic_sleepable_preload+0x1ce5> */
	return 7397ULL;
x86_l_126f:
	/* 0x126f: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1271:
	/* 0x1271: js     146a <generic_sleepable_preload+0x146a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_146a;
	}
x86_l_1277:
	/* 0x1277: movzx  eax,BYTE PTR [r13+0x229] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 553ULL);
x86_l_127f:
	/* 0x127f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1281:
	/* 0x1281: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1284:
	/* 0x1284: jg     16cb <generic_sleepable_preload+0x16cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5835ULL;
	}
x86_l_128a:
	/* 0x128a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_128d:
	/* 0x128d: je     1ba5 <generic_sleepable_preload+0x1ba5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7077ULL;
	}
x86_l_1293:
	/* 0x1293: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1296:
	/* 0x1296: jne    23ae <generic_sleepable_preload+0x23ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9134ULL;
	}
x86_l_129c:
	/* 0x129c: mov    edx,DWORD PTR [r13+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_12a3:
	/* 0x12a3: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12a9:
	/* 0x12a9: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_12ac:
	/* 0x12ac: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12b1:
	/* 0x12b1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12b6:
	/* 0x12b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_12bb:
	/* 0x12bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12c0:
	/* 0x12c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12c2:
	/* 0x12c2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12c4:
	/* 0x12c4: je     1bb1 <generic_sleepable_preload+0x1bb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7089ULL;
	}
x86_l_12ca:
	/* 0x12ca: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12cc:
	/* 0x12cc: jmp    23ae <generic_sleepable_preload+0x23ae> */
	return 9134ULL;
x86_l_12d1:
	/* 0x12d1: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_12d3:
	/* 0x12d3: js     14cf <generic_sleepable_preload+0x14cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_14cf;
	}
x86_l_12d9:
	/* 0x12d9: movzx  eax,BYTE PTR [r13+0x241] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 577ULL);
x86_l_12e1:
	/* 0x12e1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12e3:
	/* 0x12e3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12e6:
	/* 0x12e6: jg     1746 <generic_sleepable_preload+0x1746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5958ULL;
	}
x86_l_12ec:
	/* 0x12ec: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12ef:
	/* 0x12ef: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12f4:
	/* 0x12f4: je     1be0 <generic_sleepable_preload+0x1be0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7136ULL;
	}
x86_l_12fa:
	/* 0x12fa: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12fd:
	/* 0x12fd: jne    2a83 <generic_sleepable_preload+0x2a83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10883ULL;
	}
x86_l_1303:
	/* 0x1303: mov    edx,DWORD PTR [r13+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_130a:
	/* 0x130a: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1310:
	/* 0x1310: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1313:
	/* 0x1313: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1318:
	/* 0x1318: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_131d:
	/* 0x131d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1322:
	/* 0x1322: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1327:
	/* 0x1327: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1329:
	/* 0x1329: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_132b:
	/* 0x132b: je     1bec <generic_sleepable_preload+0x1bec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7148ULL;
	}
x86_l_1331:
	/* 0x1331: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1333:
	/* 0x1333: jmp    2a83 <generic_sleepable_preload+0x2a83> */
	return 10883ULL;
x86_l_1338:
	/* 0x1338: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_133a:
	/* 0x133a: js     1534 <generic_sleepable_preload+0x1534> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5428ULL;
	}
x86_l_1340:
	/* 0x1340: movzx  eax,BYTE PTR [r13+0x259] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 601ULL);
x86_l_1348:
	/* 0x1348: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_134a:
	/* 0x134a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_134d:
	/* 0x134d: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1352:
	/* 0x1352: jg     17c6 <generic_sleepable_preload+0x17c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6086ULL;
	}
x86_l_1358:
	/* 0x1358: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_135b:
	/* 0x135b: je     1c16 <generic_sleepable_preload+0x1c16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7190ULL;
	}
x86_l_1361:
	/* 0x1361: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1364:
	/* 0x1364: jne    3167 <generic_sleepable_preload+0x3167> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12647ULL;
	}
x86_l_136a:
	/* 0x136a: mov    edx,DWORD PTR [r13+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_1371:
	/* 0x1371: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1377:
	/* 0x1377: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_137a:
	/* 0x137a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_137f:
	/* 0x137f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1384:
	/* 0x1384: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1389:
	/* 0x1389: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_138e:
	/* 0x138e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1390:
	/* 0x1390: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1392:
	/* 0x1392: je     1c22 <generic_sleepable_preload+0x1c22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7202ULL;
	}
x86_l_1398:
	/* 0x1398: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_139a:
	/* 0x139a: jmp    3167 <generic_sleepable_preload+0x3167> */
	return 12647ULL;
x86_l_139f:
	/* 0x139f: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_13a1:
	/* 0x13a1: js     1599 <generic_sleepable_preload+0x1599> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5529ULL;
	}
x86_l_13a7:
	/* 0x13a7: movzx  eax,BYTE PTR [r13+0x271] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 625ULL);
x86_l_13af:
	/* 0x13af: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13b1:
	/* 0x13b1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13b4:
	/* 0x13b4: jg     1841 <generic_sleepable_preload+0x1841> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6209ULL;
	}
x86_l_13ba:
	/* 0x13ba: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13bd:
	/* 0x13bd: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13c2:
	/* 0x13c2: je     1c4c <generic_sleepable_preload+0x1c4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7244ULL;
	}
x86_l_13c8:
	/* 0x13c8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13cb:
	/* 0x13cb: jne    383e <generic_sleepable_preload+0x383e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14398ULL;
	}
x86_l_13d1:
	/* 0x13d1: mov    eax,DWORD PTR [r13+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_13d8:
	/* 0x13d8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13dd:
	/* 0x13dd: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_13e0:
	/* 0x13e0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13e5:
	/* 0x13e5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13ea:
	/* 0x13ea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13ef:
	/* 0x13ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13f4:
	/* 0x13f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f6:
	/* 0x13f6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13f8:
	/* 0x13f8: je     1c58 <generic_sleepable_preload+0x1c58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7256ULL;
	}
x86_l_13fe:
	/* 0x13fe: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1400:
	/* 0x1400: jmp    383e <generic_sleepable_preload+0x383e> */
	return 14398ULL;
x86_l_1405:
	/* 0x1405: movzx  eax,BYTE PTR [r13+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_140d:
	/* 0x140d: movzx  ecx,WORD PTR [r13+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_1415:
	/* 0x1415: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_141b:
	/* 0x141b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_141d:
	/* 0x141d: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1420:
	/* 0x1420: jle    18c3 <generic_sleepable_preload+0x18c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6339ULL;
	}
x86_l_1426:
	/* 0x1426: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1429:
	/* 0x1429: jle    19ad <generic_sleepable_preload+0x19ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6573ULL;
	}
x86_l_142f:
	/* 0x142f: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1432:
	/* 0x1432: jle    40ac <generic_sleepable_preload+0x40ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 16556ULL;
	}
x86_l_1438:
	/* 0x1438: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1440:
	/* 0x1440: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_1443:
	/* 0x1443: je     40c3 <generic_sleepable_preload+0x40c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16579ULL;
	}
x86_l_1449:
	/* 0x1449: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_144e:
	/* 0x144e: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_1451:
	/* 0x1451: je     40c3 <generic_sleepable_preload+0x40c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16579ULL;
	}
x86_l_1457:
	/* 0x1457: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_145a:
	/* 0x145a: jne    40d6 <generic_sleepable_preload+0x40d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 16598ULL;
	}
x86_l_1460:
	/* 0x1460: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1465:
	/* 0x1465: jmp    40c3 <generic_sleepable_preload+0x40c3> */
	return 16579ULL;
x86_l_146a:
	/* 0x146a: movzx  eax,BYTE PTR [r13+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_1472:
	/* 0x1472: movzx  ecx,WORD PTR [r13+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_147a:
	/* 0x147a: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_1480:
	/* 0x1480: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1482:
	/* 0x1482: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1485:
	/* 0x1485: jle    18f3 <generic_sleepable_preload+0x18f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6387ULL;
	}
x86_l_148b:
	/* 0x148b: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_148e:
	/* 0x148e: jle    19da <generic_sleepable_preload+0x19da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6618ULL;
	}
x86_l_1494:
	/* 0x1494: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1497:
	/* 0x1497: jle    46f8 <generic_sleepable_preload+0x46f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 18168ULL;
	}
x86_l_149d:
	/* 0x149d: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_14a5:
	/* 0x14a5: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_14a8:
	/* 0x14a8: je     5452 <generic_sleepable_preload+0x5452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21586ULL;
	}
x86_l_14ae:
	/* 0x14ae: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_14b3:
	/* 0x14b3: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_14b6:
	/* 0x14b6: je     5452 <generic_sleepable_preload+0x5452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21586ULL;
	}
x86_l_14bc:
	/* 0x14bc: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_14c1:
	/* 0x14c1: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_14c4:
	/* 0x14c4: je     5452 <generic_sleepable_preload+0x5452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21586ULL;
	}
x86_l_14ca:
	/* 0x14ca: jmp    5465 <generic_sleepable_preload+0x5465> */
	return 21605ULL;
x86_l_14cf:
	/* 0x14cf: movzx  eax,BYTE PTR [r13+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_14d7:
	/* 0x14d7: movzx  ecx,WORD PTR [r13+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
	return 5343ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5343ULL: goto x86_l_14df;
	case 5349ULL: goto x86_l_14e5;
	case 5351ULL: goto x86_l_14e7;
	case 5354ULL: goto x86_l_14ea;
	case 5360ULL: goto x86_l_14f0;
	case 5363ULL: goto x86_l_14f3;
	case 5369ULL: goto x86_l_14f9;
	case 5372ULL: goto x86_l_14fc;
	case 5378ULL: goto x86_l_1502;
	case 5386ULL: goto x86_l_150a;
	case 5389ULL: goto x86_l_150d;
	case 5395ULL: goto x86_l_1513;
	case 5400ULL: goto x86_l_1518;
	case 5403ULL: goto x86_l_151b;
	case 5409ULL: goto x86_l_1521;
	case 5414ULL: goto x86_l_1526;
	case 5417ULL: goto x86_l_1529;
	case 5423ULL: goto x86_l_152f;
	case 5428ULL: goto x86_l_1534;
	case 5436ULL: goto x86_l_153c;
	case 5444ULL: goto x86_l_1544;
	case 5450ULL: goto x86_l_154a;
	case 5452ULL: goto x86_l_154c;
	case 5455ULL: goto x86_l_154f;
	case 5461ULL: goto x86_l_1555;
	case 5464ULL: goto x86_l_1558;
	case 5470ULL: goto x86_l_155e;
	case 5473ULL: goto x86_l_1561;
	case 5479ULL: goto x86_l_1567;
	case 5487ULL: goto x86_l_156f;
	case 5490ULL: goto x86_l_1572;
	case 5496ULL: goto x86_l_1578;
	case 5501ULL: goto x86_l_157d;
	case 5504ULL: goto x86_l_1580;
	case 5510ULL: goto x86_l_1586;
	case 5515ULL: goto x86_l_158b;
	case 5518ULL: goto x86_l_158e;
	case 5524ULL: goto x86_l_1594;
	case 5529ULL: goto x86_l_1599;
	case 5537ULL: goto x86_l_15a1;
	case 5545ULL: goto x86_l_15a9;
	case 5551ULL: goto x86_l_15af;
	case 5553ULL: goto x86_l_15b1;
	case 5556ULL: goto x86_l_15b4;
	case 5562ULL: goto x86_l_15ba;
	case 5565ULL: goto x86_l_15bd;
	case 5571ULL: goto x86_l_15c3;
	case 5574ULL: goto x86_l_15c6;
	case 5580ULL: goto x86_l_15cc;
	case 5588ULL: goto x86_l_15d4;
	case 5591ULL: goto x86_l_15d7;
	case 5597ULL: goto x86_l_15dd;
	case 5602ULL: goto x86_l_15e2;
	case 5605ULL: goto x86_l_15e5;
	case 5611ULL: goto x86_l_15eb;
	case 5616ULL: goto x86_l_15f0;
	case 5619ULL: goto x86_l_15f3;
	case 5625ULL: goto x86_l_15f9;
	case 5630ULL: goto x86_l_15fe;
	case 5633ULL: goto x86_l_1601;
	case 5639ULL: goto x86_l_1607;
	case 5642ULL: goto x86_l_160a;
	case 5648ULL: goto x86_l_1610;
	case 5655ULL: goto x86_l_1617;
	case 5661ULL: goto x86_l_161d;
	case 5664ULL: goto x86_l_1620;
	case 5669ULL: goto x86_l_1625;
	case 5674ULL: goto x86_l_162a;
	case 5679ULL: goto x86_l_162f;
	case 5684ULL: goto x86_l_1634;
	case 5686ULL: goto x86_l_1636;
	case 5688ULL: goto x86_l_1638;
	case 5694ULL: goto x86_l_163e;
	case 5701ULL: goto x86_l_1645;
	case 5707ULL: goto x86_l_164b;
	case 5710ULL: goto x86_l_164e;
	case 5715ULL: goto x86_l_1653;
	case 5720ULL: goto x86_l_1658;
	case 5725ULL: goto x86_l_165d;
	case 5730ULL: goto x86_l_1662;
	case 5732ULL: goto x86_l_1664;
	case 5734ULL: goto x86_l_1666;
	case 5740ULL: goto x86_l_166c;
	case 5748ULL: goto x86_l_1674;
	case 5755ULL: goto x86_l_167b;
	case 5762ULL: goto x86_l_1682;
	case 5767ULL: goto x86_l_1687;
	case 5770ULL: goto x86_l_168a;
	case 5775ULL: goto x86_l_168f;
	case 5780ULL: goto x86_l_1694;
	case 5785ULL: goto x86_l_1699;
	case 5793ULL: goto x86_l_16a1;
	case 5800ULL: goto x86_l_16a8;
	case 5807ULL: goto x86_l_16af;
	case 5812ULL: goto x86_l_16b4;
	case 5815ULL: goto x86_l_16b7;
	case 5820ULL: goto x86_l_16bc;
	case 5822ULL: goto x86_l_16be;
	case 5824ULL: goto x86_l_16c0;
	case 5830ULL: goto x86_l_16c6;
	case 5835ULL: goto x86_l_16cb;
	case 5838ULL: goto x86_l_16ce;
	case 5844ULL: goto x86_l_16d4;
	case 5847ULL: goto x86_l_16d7;
	case 5853ULL: goto x86_l_16dd;
	case 5860ULL: goto x86_l_16e4;
	case 5866ULL: goto x86_l_16ea;
	case 5869ULL: goto x86_l_16ed;
	case 5874ULL: goto x86_l_16f2;
	case 5879ULL: goto x86_l_16f7;
	case 5884ULL: goto x86_l_16fc;
	case 5889ULL: goto x86_l_1701;
	case 5891ULL: goto x86_l_1703;
	case 5893ULL: goto x86_l_1705;
	case 5899ULL: goto x86_l_170b;
	case 5904ULL: goto x86_l_1710;
	case 5911ULL: goto x86_l_1717;
	case 5916ULL: goto x86_l_171c;
	case 5921ULL: goto x86_l_1721;
	case 5926ULL: goto x86_l_1726;
	case 5931ULL: goto x86_l_172b;
	case 5938ULL: goto x86_l_1732;
	case 5943ULL: goto x86_l_1737;
	case 5945ULL: goto x86_l_1739;
	case 5947ULL: goto x86_l_173b;
	case 5953ULL: goto x86_l_1741;
	case 5958ULL: goto x86_l_1746;
	case 5961ULL: goto x86_l_1749;
	case 5966ULL: goto x86_l_174e;
	case 5972ULL: goto x86_l_1754;
	case 5975ULL: goto x86_l_1757;
	case 5981ULL: goto x86_l_175d;
	case 5988ULL: goto x86_l_1764;
	case 5994ULL: goto x86_l_176a;
	case 5997ULL: goto x86_l_176d;
	case 6002ULL: goto x86_l_1772;
	case 6007ULL: goto x86_l_1777;
	case 6012ULL: goto x86_l_177c;
	case 6017ULL: goto x86_l_1781;
	case 6019ULL: goto x86_l_1783;
	case 6021ULL: goto x86_l_1785;
	case 6027ULL: goto x86_l_178b;
	case 6032ULL: goto x86_l_1790;
	case 6039ULL: goto x86_l_1797;
	case 6044ULL: goto x86_l_179c;
	case 6049ULL: goto x86_l_17a1;
	case 6054ULL: goto x86_l_17a6;
	case 6059ULL: goto x86_l_17ab;
	case 6066ULL: goto x86_l_17b2;
	case 6071ULL: goto x86_l_17b7;
	case 6073ULL: goto x86_l_17b9;
	case 6075ULL: goto x86_l_17bb;
	case 6081ULL: goto x86_l_17c1;
	case 6086ULL: goto x86_l_17c6;
	case 6089ULL: goto x86_l_17c9;
	case 6095ULL: goto x86_l_17cf;
	case 6098ULL: goto x86_l_17d2;
	case 6104ULL: goto x86_l_17d8;
	case 6111ULL: goto x86_l_17df;
	case 6117ULL: goto x86_l_17e5;
	case 6120ULL: goto x86_l_17e8;
	case 6125ULL: goto x86_l_17ed;
	case 6130ULL: goto x86_l_17f2;
	case 6135ULL: goto x86_l_17f7;
	case 6140ULL: goto x86_l_17fc;
	case 6142ULL: goto x86_l_17fe;
	case 6144ULL: goto x86_l_1800;
	case 6150ULL: goto x86_l_1806;
	case 6155ULL: goto x86_l_180b;
	case 6162ULL: goto x86_l_1812;
	case 6167ULL: goto x86_l_1817;
	case 6172ULL: goto x86_l_181c;
	case 6177ULL: goto x86_l_1821;
	case 6182ULL: goto x86_l_1826;
	case 6189ULL: goto x86_l_182d;
	case 6194ULL: goto x86_l_1832;
	case 6196ULL: goto x86_l_1834;
	case 6198ULL: goto x86_l_1836;
	case 6204ULL: goto x86_l_183c;
	case 6209ULL: goto x86_l_1841;
	case 6212ULL: goto x86_l_1844;
	case 6217ULL: goto x86_l_1849;
	case 6223ULL: goto x86_l_184f;
	case 6226ULL: goto x86_l_1852;
	case 6232ULL: goto x86_l_1858;
	case 6239ULL: goto x86_l_185f;
	case 6244ULL: goto x86_l_1864;
	case 6247ULL: goto x86_l_1867;
	case 6252ULL: goto x86_l_186c;
	case 6257ULL: goto x86_l_1871;
	case 6262ULL: goto x86_l_1876;
	case 6267ULL: goto x86_l_187b;
	case 6270ULL: goto x86_l_187e;
	case 6272ULL: goto x86_l_1880;
	case 6274ULL: goto x86_l_1882;
	case 6280ULL: goto x86_l_1888;
	case 6285ULL: goto x86_l_188d;
	case 6292ULL: goto x86_l_1894;
	case 6297ULL: goto x86_l_1899;
	case 6302ULL: goto x86_l_189e;
	case 6307ULL: goto x86_l_18a3;
	case 6312ULL: goto x86_l_18a8;
	case 6319ULL: goto x86_l_18af;
	case 6324ULL: goto x86_l_18b4;
	case 6326ULL: goto x86_l_18b6;
	case 6328ULL: goto x86_l_18b8;
	case 6334ULL: goto x86_l_18be;
	case 6339ULL: goto x86_l_18c3;
	case 6342ULL: goto x86_l_18c6;
	case 6348ULL: goto x86_l_18cc;
	case 6351ULL: goto x86_l_18cf;
	case 6357ULL: goto x86_l_18d5;
	case 6360ULL: goto x86_l_18d8;
	case 6362ULL: goto x86_l_18da;
	case 6368ULL: goto x86_l_18e0;
	case 6373ULL: goto x86_l_18e5;
	case 6376ULL: goto x86_l_18e8;
	case 6382ULL: goto x86_l_18ee;
	case 6387ULL: goto x86_l_18f3;
	case 6390ULL: goto x86_l_18f6;
	case 6396ULL: goto x86_l_18fc;
	case 6399ULL: goto x86_l_18ff;
	case 6405ULL: goto x86_l_1905;
	case 6407ULL: goto x86_l_1907;
	case 6413ULL: goto x86_l_190d;
	case 6418ULL: goto x86_l_1912;
	case 6421ULL: goto x86_l_1915;
	case 6427ULL: goto x86_l_191b;
	case 6432ULL: goto x86_l_1920;
	case 6435ULL: goto x86_l_1923;
	case 6440ULL: goto x86_l_1928;
	case 6446ULL: goto x86_l_192e;
	case 6449ULL: goto x86_l_1931;
	case 6455ULL: goto x86_l_1937;
	case 6457ULL: goto x86_l_1939;
	case 6463ULL: goto x86_l_193f;
	case 6466ULL: goto x86_l_1942;
	case 6469ULL: goto x86_l_1945;
	case 6475ULL: goto x86_l_194b;
	case 6480ULL: goto x86_l_1950;
	case 6483ULL: goto x86_l_1953;
	case 6488ULL: goto x86_l_1958;
	case 6494ULL: goto x86_l_195e;
	case 6497ULL: goto x86_l_1961;
	case 6503ULL: goto x86_l_1967;
	case 6505ULL: goto x86_l_1969;
	case 6511ULL: goto x86_l_196f;
	case 6514ULL: goto x86_l_1972;
	case 6517ULL: goto x86_l_1975;
	case 6523ULL: goto x86_l_197b;
	case 6528ULL: goto x86_l_1980;
	case 6531ULL: goto x86_l_1983;
	case 6537ULL: goto x86_l_1989;
	case 6540ULL: goto x86_l_198c;
	case 6546ULL: goto x86_l_1992;
	case 6548ULL: goto x86_l_1994;
	case 6554ULL: goto x86_l_199a;
	case 6557ULL: goto x86_l_199d;
	case 6562ULL: goto x86_l_19a2;
	case 6568ULL: goto x86_l_19a8;
	case 6573ULL: goto x86_l_19ad;
	case 6576ULL: goto x86_l_19b0;
	case 6582ULL: goto x86_l_19b6;
	case 6590ULL: goto x86_l_19be;
	case 6593ULL: goto x86_l_19c1;
	case 6599ULL: goto x86_l_19c7;
	case 6604ULL: goto x86_l_19cc;
	case 6607ULL: goto x86_l_19cf;
	case 6613ULL: goto x86_l_19d5;
	case 6618ULL: goto x86_l_19da;
	case 6621ULL: goto x86_l_19dd;
	case 6627ULL: goto x86_l_19e3;
	case 6635ULL: goto x86_l_19eb;
	case 6638ULL: goto x86_l_19ee;
	case 6644ULL: goto x86_l_19f4;
	case 6649ULL: goto x86_l_19f9;
	case 6652ULL: goto x86_l_19fc;
	case 6658ULL: goto x86_l_1a02;
	case 6663ULL: goto x86_l_1a07;
	case 6666ULL: goto x86_l_1a0a;
	case 6672ULL: goto x86_l_1a10;
	case 6680ULL: goto x86_l_1a18;
	case 6683ULL: goto x86_l_1a1b;
	case 6689ULL: goto x86_l_1a21;
	case 6694ULL: goto x86_l_1a26;
	case 6697ULL: goto x86_l_1a29;
	case 6703ULL: goto x86_l_1a2f;
	case 6708ULL: goto x86_l_1a34;
	case 6711ULL: goto x86_l_1a37;
	case 6717ULL: goto x86_l_1a3d;
	case 6725ULL: goto x86_l_1a45;
	case 6728ULL: goto x86_l_1a48;
	case 6734ULL: goto x86_l_1a4e;
	case 6739ULL: goto x86_l_1a53;
	case 6742ULL: goto x86_l_1a56;
	case 6748ULL: goto x86_l_1a5c;
	case 6753ULL: goto x86_l_1a61;
	case 6756ULL: goto x86_l_1a64;
	case 6762ULL: goto x86_l_1a6a;
	case 6770ULL: goto x86_l_1a72;
	case 6773ULL: goto x86_l_1a75;
	case 6779ULL: goto x86_l_1a7b;
	case 6784ULL: goto x86_l_1a80;
	case 6787ULL: goto x86_l_1a83;
	case 6793ULL: goto x86_l_1a89;
	case 6798ULL: goto x86_l_1a8e;
	case 6801ULL: goto x86_l_1a91;
	case 6807ULL: goto x86_l_1a97;
	case 6815ULL: goto x86_l_1a9f;
	case 6818ULL: goto x86_l_1aa2;
	case 6824ULL: goto x86_l_1aa8;
	case 6829ULL: goto x86_l_1aad;
	case 6832ULL: goto x86_l_1ab0;
	case 6838ULL: goto x86_l_1ab6;
	case 6843ULL: goto x86_l_1abb;
	case 6846ULL: goto x86_l_1abe;
	case 6852ULL: goto x86_l_1ac4;
	case 6860ULL: goto x86_l_1acc;
	case 6863ULL: goto x86_l_1acf;
	case 6869ULL: goto x86_l_1ad5;
	case 6874ULL: goto x86_l_1ada;
	case 6877ULL: goto x86_l_1add;
	case 6883ULL: goto x86_l_1ae3;
	case 6888ULL: goto x86_l_1ae8;
	case 6891ULL: goto x86_l_1aeb;
	case 6897ULL: goto x86_l_1af1;
	case 6905ULL: goto x86_l_1af9;
	case 6908ULL: goto x86_l_1afc;
	case 6914ULL: goto x86_l_1b02;
	case 6919ULL: goto x86_l_1b07;
	case 6922ULL: goto x86_l_1b0a;
	case 6928ULL: goto x86_l_1b10;
	case 6933ULL: goto x86_l_1b15;
	case 6936ULL: goto x86_l_1b18;
	case 6942ULL: goto x86_l_1b1e;
	case 6950ULL: goto x86_l_1b26;
	case 6953ULL: goto x86_l_1b29;
	case 6959ULL: goto x86_l_1b2f;
	case 6964ULL: goto x86_l_1b34;
	case 6967ULL: goto x86_l_1b37;
	case 6973ULL: goto x86_l_1b3d;
	case 6978ULL: goto x86_l_1b42;
	case 6981ULL: goto x86_l_1b45;
	case 6987ULL: goto x86_l_1b4b;
	case 6995ULL: goto x86_l_1b53;
	case 6998ULL: goto x86_l_1b56;
	case 7004ULL: goto x86_l_1b5c;
	case 7009ULL: goto x86_l_1b61;
	case 7012ULL: goto x86_l_1b64;
	case 7018ULL: goto x86_l_1b6a;
	case 7023ULL: goto x86_l_1b6f;
	case 7030ULL: goto x86_l_1b76;
	case 7035ULL: goto x86_l_1b7b;
	case 7043ULL: goto x86_l_1b83;
	case 7050ULL: goto x86_l_1b8a;
	case 7058ULL: goto x86_l_1b92;
	case 7063ULL: goto x86_l_1b97;
	case 7068ULL: goto x86_l_1b9c;
	case 7072ULL: goto x86_l_1ba0;
	case 7077ULL: goto x86_l_1ba5;
	case 7084ULL: goto x86_l_1bac;
	case 7089ULL: goto x86_l_1bb1;
	case 7097ULL: goto x86_l_1bb9;
	case 7104ULL: goto x86_l_1bc0;
	case 7109ULL: goto x86_l_1bc5;
	case 7117ULL: goto x86_l_1bcd;
	case 7122ULL: goto x86_l_1bd2;
	case 7127ULL: goto x86_l_1bd7;
	case 7131ULL: goto x86_l_1bdb;
	case 7136ULL: goto x86_l_1be0;
	case 7143ULL: goto x86_l_1be7;
	case 7148ULL: goto x86_l_1bec;
	case 7156ULL: goto x86_l_1bf4;
	case 7163ULL: goto x86_l_1bfb;
	case 7171ULL: goto x86_l_1c03;
	case 7176ULL: goto x86_l_1c08;
	case 7181ULL: goto x86_l_1c0d;
	case 7185ULL: goto x86_l_1c11;
	case 7190ULL: goto x86_l_1c16;
	case 7197ULL: goto x86_l_1c1d;
	case 7202ULL: goto x86_l_1c22;
	case 7210ULL: goto x86_l_1c2a;
	case 7217ULL: goto x86_l_1c31;
	case 7225ULL: goto x86_l_1c39;
	default: return 0xffffffffffffffffULL;
	}
x86_l_14df:
	/* 0x14df: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_14e5:
	/* 0x14e5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14e7:
	/* 0x14e7: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_14ea:
	/* 0x14ea: jle    1920 <generic_sleepable_preload+0x1920> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1920;
	}
x86_l_14f0:
	/* 0x14f0: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_14f3:
	/* 0x14f3: jle    1a07 <generic_sleepable_preload+0x1a07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1a07;
	}
x86_l_14f9:
	/* 0x14f9: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_14fc:
	/* 0x14fc: jle    471c <generic_sleepable_preload+0x471c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 18204ULL;
	}
x86_l_1502:
	/* 0x1502: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_150a:
	/* 0x150a: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_150d:
	/* 0x150d: je     4733 <generic_sleepable_preload+0x4733> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18227ULL;
	}
x86_l_1513:
	/* 0x1513: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1518:
	/* 0x1518: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_151b:
	/* 0x151b: je     4733 <generic_sleepable_preload+0x4733> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18227ULL;
	}
x86_l_1521:
	/* 0x1521: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1526:
	/* 0x1526: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_1529:
	/* 0x1529: je     4733 <generic_sleepable_preload+0x4733> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18227ULL;
	}
x86_l_152f:
	/* 0x152f: jmp    4746 <generic_sleepable_preload+0x4746> */
	return 18246ULL;
x86_l_1534:
	/* 0x1534: movzx  eax,BYTE PTR [r13+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_153c:
	/* 0x153c: movzx  ecx,WORD PTR [r13+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_1544:
	/* 0x1544: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_154a:
	/* 0x154a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_154c:
	/* 0x154c: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_154f:
	/* 0x154f: jle    1950 <generic_sleepable_preload+0x1950> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1950;
	}
x86_l_1555:
	/* 0x1555: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1558:
	/* 0x1558: jle    1a34 <generic_sleepable_preload+0x1a34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1a34;
	}
x86_l_155e:
	/* 0x155e: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1561:
	/* 0x1561: jle    4d83 <generic_sleepable_preload+0x4d83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 19843ULL;
	}
x86_l_1567:
	/* 0x1567: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_156f:
	/* 0x156f: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_1572:
	/* 0x1572: je     4d9a <generic_sleepable_preload+0x4d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19866ULL;
	}
x86_l_1578:
	/* 0x1578: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_157d:
	/* 0x157d: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_1580:
	/* 0x1580: je     4d9a <generic_sleepable_preload+0x4d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19866ULL;
	}
x86_l_1586:
	/* 0x1586: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_158b:
	/* 0x158b: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_158e:
	/* 0x158e: je     4d9a <generic_sleepable_preload+0x4d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19866ULL;
	}
x86_l_1594:
	/* 0x1594: jmp    4dad <generic_sleepable_preload+0x4dad> */
	return 19885ULL;
x86_l_1599:
	/* 0x1599: movzx  eax,BYTE PTR [r13+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_15a1:
	/* 0x15a1: movzx  ecx,WORD PTR [r13+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_15a9:
	/* 0x15a9: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_15af:
	/* 0x15af: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15b1:
	/* 0x15b1: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_15b4:
	/* 0x15b4: jle    1980 <generic_sleepable_preload+0x1980> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1980;
	}
x86_l_15ba:
	/* 0x15ba: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_15bd:
	/* 0x15bd: jle    1a61 <generic_sleepable_preload+0x1a61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1a61;
	}
x86_l_15c3:
	/* 0x15c3: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_15c6:
	/* 0x15c6: jle    53db <generic_sleepable_preload+0x53db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 21467ULL;
	}
x86_l_15cc:
	/* 0x15cc: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_15d4:
	/* 0x15d4: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_15d7:
	/* 0x15d7: je     5aa2 <generic_sleepable_preload+0x5aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23202ULL;
	}
x86_l_15dd:
	/* 0x15dd: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15e2:
	/* 0x15e2: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_15e5:
	/* 0x15e5: je     5aa2 <generic_sleepable_preload+0x5aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23202ULL;
	}
x86_l_15eb:
	/* 0x15eb: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_15f0:
	/* 0x15f0: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_15f3:
	/* 0x15f3: je     5aa2 <generic_sleepable_preload+0x5aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23202ULL;
	}
x86_l_15f9:
	/* 0x15f9: jmp    5ab5 <generic_sleepable_preload+0x5ab5> */
	return 23221ULL;
x86_l_15fe:
	/* 0x15fe: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1601:
	/* 0x1601: je     1c82 <generic_sleepable_preload+0x1c82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7298ULL;
	}
x86_l_1607:
	/* 0x1607: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_160a:
	/* 0x160a: jne    1ce5 <generic_sleepable_preload+0x1ce5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7397ULL;
	}
x86_l_1610:
	/* 0x1610: mov    edx,DWORD PTR [r13+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_1617:
	/* 0x1617: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_161d:
	/* 0x161d: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1620:
	/* 0x1620: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1625:
	/* 0x1625: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_162a:
	/* 0x162a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_162f:
	/* 0x162f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1634:
	/* 0x1634: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1636:
	/* 0x1636: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1638:
	/* 0x1638: jne    1ce2 <generic_sleepable_preload+0x1ce2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7394ULL;
	}
x86_l_163e:
	/* 0x163e: mov    edx,DWORD PTR [r13+0x20c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_1645:
	/* 0x1645: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_164b:
	/* 0x164b: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_164e:
	/* 0x164e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1653:
	/* 0x1653: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1658:
	/* 0x1658: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_165d:
	/* 0x165d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1662:
	/* 0x1662: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1664:
	/* 0x1664: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1666:
	/* 0x1666: jne    1ce2 <generic_sleepable_preload+0x1ce2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7394ULL;
	}
x86_l_166c:
	/* 0x166c: movzx  eax,BYTE PTR [r13+0x213] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 531ULL);
x86_l_1674:
	/* 0x1674: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_167b:
	/* 0x167b: mov    rcx,QWORD PTR [r13+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_1682:
	/* 0x1682: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_1687:
	/* 0x1687: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_168a:
	/* 0x168a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_168f:
	/* 0x168f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1694:
	/* 0x1694: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1699:
	/* 0x1699: movzx  ecx,BYTE PTR [r13+0x213] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 531ULL);
x86_l_16a1:
	/* 0x16a1: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_16a8:
	/* 0x16a8: mov    rdx,QWORD PTR [r13+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_16af:
	/* 0x16af: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_16b4:
	/* 0x16b4: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16b7:
	/* 0x16b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16bc:
	/* 0x16bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16be:
	/* 0x16be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16c0:
	/* 0x16c0: jne    1ce2 <generic_sleepable_preload+0x1ce2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7394ULL;
	}
x86_l_16c6:
	/* 0x16c6: jmp    1b7b <generic_sleepable_preload+0x1b7b> */
	goto x86_l_1b7b;
x86_l_16cb:
	/* 0x16cb: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16ce:
	/* 0x16ce: je     22f9 <generic_sleepable_preload+0x22f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8953ULL;
	}
x86_l_16d4:
	/* 0x16d4: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_16d7:
	/* 0x16d7: jne    23ae <generic_sleepable_preload+0x23ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9134ULL;
	}
x86_l_16dd:
	/* 0x16dd: mov    edx,DWORD PTR [r13+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_16e4:
	/* 0x16e4: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16ea:
	/* 0x16ea: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16ed:
	/* 0x16ed: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16f2:
	/* 0x16f2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16f7:
	/* 0x16f7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16fc:
	/* 0x16fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1701:
	/* 0x1701: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1703:
	/* 0x1703: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1705:
	/* 0x1705: jne    23ab <generic_sleepable_preload+0x23ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9131ULL;
	}
x86_l_170b:
	/* 0x170b: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1710:
	/* 0x1710: add    rcx,QWORD PTR [r13+0x218] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 536ULL);
x86_l_1717:
	/* 0x1717: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_171c:
	/* 0x171c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1721:
	/* 0x1721: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1726:
	/* 0x1726: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_172b:
	/* 0x172b: add    rdx,QWORD PTR [r13+0x218] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 536ULL);
x86_l_1732:
	/* 0x1732: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1737:
	/* 0x1737: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1739:
	/* 0x1739: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_173b:
	/* 0x173b: jne    23ab <generic_sleepable_preload+0x23ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9131ULL;
	}
x86_l_1741:
	/* 0x1741: jmp    1bb1 <generic_sleepable_preload+0x1bb1> */
	goto x86_l_1bb1;
x86_l_1746:
	/* 0x1746: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1749:
	/* 0x1749: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_174e:
	/* 0x174e: je     29ce <generic_sleepable_preload+0x29ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10702ULL;
	}
x86_l_1754:
	/* 0x1754: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1757:
	/* 0x1757: jne    2a83 <generic_sleepable_preload+0x2a83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10883ULL;
	}
x86_l_175d:
	/* 0x175d: mov    edx,DWORD PTR [r13+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_1764:
	/* 0x1764: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_176a:
	/* 0x176a: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_176d:
	/* 0x176d: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1772:
	/* 0x1772: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1777:
	/* 0x1777: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_177c:
	/* 0x177c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1781:
	/* 0x1781: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1783:
	/* 0x1783: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1785:
	/* 0x1785: jne    2a80 <generic_sleepable_preload+0x2a80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10880ULL;
	}
x86_l_178b:
	/* 0x178b: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1790:
	/* 0x1790: add    rcx,QWORD PTR [r13+0x230] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 560ULL);
x86_l_1797:
	/* 0x1797: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_179c:
	/* 0x179c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_17a1:
	/* 0x17a1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_17a6:
	/* 0x17a6: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17ab:
	/* 0x17ab: add    rdx,QWORD PTR [r13+0x230] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 560ULL);
x86_l_17b2:
	/* 0x17b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17b7:
	/* 0x17b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17b9:
	/* 0x17b9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17bb:
	/* 0x17bb: jne    2a80 <generic_sleepable_preload+0x2a80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10880ULL;
	}
x86_l_17c1:
	/* 0x17c1: jmp    1bec <generic_sleepable_preload+0x1bec> */
	goto x86_l_1bec;
x86_l_17c6:
	/* 0x17c6: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17c9:
	/* 0x17c9: je     30b2 <generic_sleepable_preload+0x30b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12466ULL;
	}
x86_l_17cf:
	/* 0x17cf: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_17d2:
	/* 0x17d2: jne    3167 <generic_sleepable_preload+0x3167> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12647ULL;
	}
x86_l_17d8:
	/* 0x17d8: mov    edx,DWORD PTR [r13+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_17df:
	/* 0x17df: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17e5:
	/* 0x17e5: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_17e8:
	/* 0x17e8: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17ed:
	/* 0x17ed: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17f2:
	/* 0x17f2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17f7:
	/* 0x17f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17fc:
	/* 0x17fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17fe:
	/* 0x17fe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1800:
	/* 0x1800: jne    3164 <generic_sleepable_preload+0x3164> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12644ULL;
	}
x86_l_1806:
	/* 0x1806: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_180b:
	/* 0x180b: add    rcx,QWORD PTR [r13+0x248] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 584ULL);
x86_l_1812:
	/* 0x1812: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1817:
	/* 0x1817: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_181c:
	/* 0x181c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1821:
	/* 0x1821: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1826:
	/* 0x1826: add    rdx,QWORD PTR [r13+0x248] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 584ULL);
x86_l_182d:
	/* 0x182d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1832:
	/* 0x1832: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1834:
	/* 0x1834: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1836:
	/* 0x1836: jne    3164 <generic_sleepable_preload+0x3164> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12644ULL;
	}
x86_l_183c:
	/* 0x183c: jmp    1c22 <generic_sleepable_preload+0x1c22> */
	goto x86_l_1c22;
x86_l_1841:
	/* 0x1841: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1844:
	/* 0x1844: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1849:
	/* 0x1849: je     3787 <generic_sleepable_preload+0x3787> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14215ULL;
	}
x86_l_184f:
	/* 0x184f: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1852:
	/* 0x1852: jne    383e <generic_sleepable_preload+0x383e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14398ULL;
	}
x86_l_1858:
	/* 0x1858: mov    eax,DWORD PTR [r13+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_185f:
	/* 0x185f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1864:
	/* 0x1864: add    rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1867:
	/* 0x1867: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_186c:
	/* 0x186c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1871:
	/* 0x1871: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1876:
	/* 0x1876: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_187b:
	/* 0x187b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_187e:
	/* 0x187e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1880:
	/* 0x1880: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1882:
	/* 0x1882: jne    383b <generic_sleepable_preload+0x383b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14395ULL;
	}
x86_l_1888:
	/* 0x1888: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_188d:
	/* 0x188d: add    rcx,QWORD PTR [r13+0x260] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 608ULL);
x86_l_1894:
	/* 0x1894: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1899:
	/* 0x1899: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_189e:
	/* 0x189e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_18a3:
	/* 0x18a3: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18a8:
	/* 0x18a8: add    rdx,QWORD PTR [r13+0x260] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 608ULL);
x86_l_18af:
	/* 0x18af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18b4:
	/* 0x18b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b6:
	/* 0x18b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18b8:
	/* 0x18b8: jne    383b <generic_sleepable_preload+0x383b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14395ULL;
	}
x86_l_18be:
	/* 0x18be: jmp    1c58 <generic_sleepable_preload+0x1c58> */
	return 7256ULL;
x86_l_18c3:
	/* 0x18c3: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_18c6:
	/* 0x18c6: jg     1a8e <generic_sleepable_preload+0x1a8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1a8e;
	}
x86_l_18cc:
	/* 0x18cc: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_18cf:
	/* 0x18cf: jg     3f44 <generic_sleepable_preload+0x3f44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16196ULL;
	}
x86_l_18d5:
	/* 0x18d5: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_18d8:
	/* 0x18d8: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_18da:
	/* 0x18da: je     40c3 <generic_sleepable_preload+0x40c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16579ULL;
	}
x86_l_18e0:
	/* 0x18e0: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18e5:
	/* 0x18e5: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_18e8:
	/* 0x18e8: je     40c3 <generic_sleepable_preload+0x40c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16579ULL;
	}
x86_l_18ee:
	/* 0x18ee: jmp    40d6 <generic_sleepable_preload+0x40d6> */
	return 16598ULL;
x86_l_18f3:
	/* 0x18f3: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_18f6:
	/* 0x18f6: jg     1abb <generic_sleepable_preload+0x1abb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1abb;
	}
x86_l_18fc:
	/* 0x18fc: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_18ff:
	/* 0x18ff: jg     3f68 <generic_sleepable_preload+0x3f68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16232ULL;
	}
x86_l_1905:
	/* 0x1905: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1907:
	/* 0x1907: je     544f <generic_sleepable_preload+0x544f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21583ULL;
	}
x86_l_190d:
	/* 0x190d: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1912:
	/* 0x1912: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1915:
	/* 0x1915: je     5452 <generic_sleepable_preload+0x5452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21586ULL;
	}
x86_l_191b:
	/* 0x191b: jmp    5465 <generic_sleepable_preload+0x5465> */
	return 21605ULL;
x86_l_1920:
	/* 0x1920: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1923:
	/* 0x1923: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1928:
	/* 0x1928: jg     1ae8 <generic_sleepable_preload+0x1ae8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1ae8;
	}
x86_l_192e:
	/* 0x192e: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1931:
	/* 0x1931: jg     3f8c <generic_sleepable_preload+0x3f8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16268ULL;
	}
x86_l_1937:
	/* 0x1937: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1939:
	/* 0x1939: je     4733 <generic_sleepable_preload+0x4733> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18227ULL;
	}
x86_l_193f:
	/* 0x193f: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1942:
	/* 0x1942: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1945:
	/* 0x1945: je     4733 <generic_sleepable_preload+0x4733> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18227ULL;
	}
x86_l_194b:
	/* 0x194b: jmp    4746 <generic_sleepable_preload+0x4746> */
	return 18246ULL;
x86_l_1950:
	/* 0x1950: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1953:
	/* 0x1953: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1958:
	/* 0x1958: jg     1b15 <generic_sleepable_preload+0x1b15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1b15;
	}
x86_l_195e:
	/* 0x195e: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1961:
	/* 0x1961: jg     3fb0 <generic_sleepable_preload+0x3fb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16304ULL;
	}
x86_l_1967:
	/* 0x1967: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1969:
	/* 0x1969: je     4d9a <generic_sleepable_preload+0x4d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19866ULL;
	}
x86_l_196f:
	/* 0x196f: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1972:
	/* 0x1972: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1975:
	/* 0x1975: je     4d9a <generic_sleepable_preload+0x4d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19866ULL;
	}
x86_l_197b:
	/* 0x197b: jmp    4dad <generic_sleepable_preload+0x4dad> */
	return 19885ULL;
x86_l_1980:
	/* 0x1980: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1983:
	/* 0x1983: jg     1b42 <generic_sleepable_preload+0x1b42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1b42;
	}
x86_l_1989:
	/* 0x1989: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_198c:
	/* 0x198c: jg     3fd4 <generic_sleepable_preload+0x3fd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16340ULL;
	}
x86_l_1992:
	/* 0x1992: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1994:
	/* 0x1994: je     5a9d <generic_sleepable_preload+0x5a9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23197ULL;
	}
x86_l_199a:
	/* 0x199a: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_199d:
	/* 0x199d: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_19a2:
	/* 0x19a2: je     5aa2 <generic_sleepable_preload+0x5aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23202ULL;
	}
x86_l_19a8:
	/* 0x19a8: jmp    5ab5 <generic_sleepable_preload+0x5ab5> */
	return 23221ULL;
x86_l_19ad:
	/* 0x19ad: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_19b0:
	/* 0x19b0: jg     3e90 <generic_sleepable_preload+0x3e90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16016ULL;
	}
x86_l_19b6:
	/* 0x19b6: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_19be:
	/* 0x19be: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19c1:
	/* 0x19c1: je     40c3 <generic_sleepable_preload+0x40c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16579ULL;
	}
x86_l_19c7:
	/* 0x19c7: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_19cc:
	/* 0x19cc: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_19cf:
	/* 0x19cf: je     40c3 <generic_sleepable_preload+0x40c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16579ULL;
	}
x86_l_19d5:
	/* 0x19d5: jmp    40d6 <generic_sleepable_preload+0x40d6> */
	return 16598ULL;
x86_l_19da:
	/* 0x19da: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_19dd:
	/* 0x19dd: jg     3eb4 <generic_sleepable_preload+0x3eb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16052ULL;
	}
x86_l_19e3:
	/* 0x19e3: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_19eb:
	/* 0x19eb: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19ee:
	/* 0x19ee: je     5452 <generic_sleepable_preload+0x5452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21586ULL;
	}
x86_l_19f4:
	/* 0x19f4: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_19f9:
	/* 0x19f9: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_19fc:
	/* 0x19fc: je     5452 <generic_sleepable_preload+0x5452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21586ULL;
	}
x86_l_1a02:
	/* 0x1a02: jmp    5465 <generic_sleepable_preload+0x5465> */
	return 21605ULL;
x86_l_1a07:
	/* 0x1a07: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a0a:
	/* 0x1a0a: jg     3ed8 <generic_sleepable_preload+0x3ed8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16088ULL;
	}
x86_l_1a10:
	/* 0x1a10: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1a18:
	/* 0x1a18: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a1b:
	/* 0x1a1b: je     4733 <generic_sleepable_preload+0x4733> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18227ULL;
	}
x86_l_1a21:
	/* 0x1a21: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a26:
	/* 0x1a26: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a29:
	/* 0x1a29: je     4733 <generic_sleepable_preload+0x4733> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18227ULL;
	}
x86_l_1a2f:
	/* 0x1a2f: jmp    4746 <generic_sleepable_preload+0x4746> */
	return 18246ULL;
x86_l_1a34:
	/* 0x1a34: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a37:
	/* 0x1a37: jg     3efc <generic_sleepable_preload+0x3efc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16124ULL;
	}
x86_l_1a3d:
	/* 0x1a3d: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1a45:
	/* 0x1a45: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a48:
	/* 0x1a48: je     4d9a <generic_sleepable_preload+0x4d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19866ULL;
	}
x86_l_1a4e:
	/* 0x1a4e: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a53:
	/* 0x1a53: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a56:
	/* 0x1a56: je     4d9a <generic_sleepable_preload+0x4d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19866ULL;
	}
x86_l_1a5c:
	/* 0x1a5c: jmp    4dad <generic_sleepable_preload+0x4dad> */
	return 19885ULL;
x86_l_1a61:
	/* 0x1a61: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a64:
	/* 0x1a64: jg     3f20 <generic_sleepable_preload+0x3f20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16160ULL;
	}
x86_l_1a6a:
	/* 0x1a6a: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1a72:
	/* 0x1a72: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a75:
	/* 0x1a75: je     5aa2 <generic_sleepable_preload+0x5aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23202ULL;
	}
x86_l_1a7b:
	/* 0x1a7b: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a80:
	/* 0x1a80: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a83:
	/* 0x1a83: je     5aa2 <generic_sleepable_preload+0x5aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23202ULL;
	}
x86_l_1a89:
	/* 0x1a89: jmp    5ab5 <generic_sleepable_preload+0x5ab5> */
	return 23221ULL;
x86_l_1a8e:
	/* 0x1a8e: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1a91:
	/* 0x1a91: jg     3ff8 <generic_sleepable_preload+0x3ff8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16376ULL;
	}
x86_l_1a97:
	/* 0x1a97: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1a9f:
	/* 0x1a9f: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1aa2:
	/* 0x1aa2: je     40c3 <generic_sleepable_preload+0x40c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16579ULL;
	}
x86_l_1aa8:
	/* 0x1aa8: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1aad:
	/* 0x1aad: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1ab0:
	/* 0x1ab0: je     40c3 <generic_sleepable_preload+0x40c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16579ULL;
	}
x86_l_1ab6:
	/* 0x1ab6: jmp    40d6 <generic_sleepable_preload+0x40d6> */
	return 16598ULL;
x86_l_1abb:
	/* 0x1abb: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1abe:
	/* 0x1abe: jg     401c <generic_sleepable_preload+0x401c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16412ULL;
	}
x86_l_1ac4:
	/* 0x1ac4: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1acc:
	/* 0x1acc: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1acf:
	/* 0x1acf: je     5452 <generic_sleepable_preload+0x5452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21586ULL;
	}
x86_l_1ad5:
	/* 0x1ad5: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ada:
	/* 0x1ada: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1add:
	/* 0x1add: je     5452 <generic_sleepable_preload+0x5452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21586ULL;
	}
x86_l_1ae3:
	/* 0x1ae3: jmp    5465 <generic_sleepable_preload+0x5465> */
	return 21605ULL;
x86_l_1ae8:
	/* 0x1ae8: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1aeb:
	/* 0x1aeb: jg     4040 <generic_sleepable_preload+0x4040> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16448ULL;
	}
x86_l_1af1:
	/* 0x1af1: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1af9:
	/* 0x1af9: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1afc:
	/* 0x1afc: je     4733 <generic_sleepable_preload+0x4733> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18227ULL;
	}
x86_l_1b02:
	/* 0x1b02: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b07:
	/* 0x1b07: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1b0a:
	/* 0x1b0a: je     4733 <generic_sleepable_preload+0x4733> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18227ULL;
	}
x86_l_1b10:
	/* 0x1b10: jmp    4746 <generic_sleepable_preload+0x4746> */
	return 18246ULL;
x86_l_1b15:
	/* 0x1b15: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1b18:
	/* 0x1b18: jg     4064 <generic_sleepable_preload+0x4064> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16484ULL;
	}
x86_l_1b1e:
	/* 0x1b1e: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1b26:
	/* 0x1b26: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1b29:
	/* 0x1b29: je     4d9a <generic_sleepable_preload+0x4d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19866ULL;
	}
x86_l_1b2f:
	/* 0x1b2f: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b34:
	/* 0x1b34: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1b37:
	/* 0x1b37: je     4d9a <generic_sleepable_preload+0x4d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19866ULL;
	}
x86_l_1b3d:
	/* 0x1b3d: jmp    4dad <generic_sleepable_preload+0x4dad> */
	return 19885ULL;
x86_l_1b42:
	/* 0x1b42: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1b45:
	/* 0x1b45: jg     4088 <generic_sleepable_preload+0x4088> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16520ULL;
	}
x86_l_1b4b:
	/* 0x1b4b: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1b53:
	/* 0x1b53: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1b56:
	/* 0x1b56: je     5aa2 <generic_sleepable_preload+0x5aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23202ULL;
	}
x86_l_1b5c:
	/* 0x1b5c: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b61:
	/* 0x1b61: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1b64:
	/* 0x1b64: je     5aa2 <generic_sleepable_preload+0x5aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23202ULL;
	}
x86_l_1b6a:
	/* 0x1b6a: jmp    5ab5 <generic_sleepable_preload+0x5ab5> */
	return 23221ULL;
x86_l_1b6f:
	/* 0x1b6f: mov    rax,QWORD PTR [r13+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_1b76:
	/* 0x1b76: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b7b:
	/* 0x1b7b: movzx  eax,BYTE PTR [r13+0x210] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 528ULL);
x86_l_1b83:
	/* 0x1b83: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_1b8a:
	/* 0x1b8a: cmp    BYTE PTR [r13+0x212],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2276332666880ULL);
x86_l_1b92:
	/* 0x1b92: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_1b97:
	/* 0x1b97: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_1b9c:
	/* 0x1b9c: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1ba0:
	/* 0x1ba0: jmp    1ce5 <generic_sleepable_preload+0x1ce5> */
	return 7397ULL;
x86_l_1ba5:
	/* 0x1ba5: mov    rax,QWORD PTR [r13+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_1bac:
	/* 0x1bac: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bb1:
	/* 0x1bb1: movzx  eax,BYTE PTR [r13+0x228] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 552ULL);
x86_l_1bb9:
	/* 0x1bb9: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_1bc0:
	/* 0x1bc0: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bc5:
	/* 0x1bc5: cmp    BYTE PTR [r13+0x22a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2379411881984ULL);
x86_l_1bcd:
	/* 0x1bcd: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_1bd2:
	/* 0x1bd2: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_1bd7:
	/* 0x1bd7: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1bdb:
	/* 0x1bdb: jmp    23ae <generic_sleepable_preload+0x23ae> */
	return 9134ULL;
x86_l_1be0:
	/* 0x1be0: mov    rax,QWORD PTR [r13+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_1be7:
	/* 0x1be7: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bec:
	/* 0x1bec: movzx  eax,BYTE PTR [r13+0x240] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 576ULL);
x86_l_1bf4:
	/* 0x1bf4: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_1bfb:
	/* 0x1bfb: cmp    BYTE PTR [r13+0x242],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2482491097088ULL);
x86_l_1c03:
	/* 0x1c03: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_1c08:
	/* 0x1c08: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_1c0d:
	/* 0x1c0d: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1c11:
	/* 0x1c11: jmp    2a83 <generic_sleepable_preload+0x2a83> */
	return 10883ULL;
x86_l_1c16:
	/* 0x1c16: mov    rax,QWORD PTR [r13+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_1c1d:
	/* 0x1c1d: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c22:
	/* 0x1c22: movzx  eax,BYTE PTR [r13+0x258] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 600ULL);
x86_l_1c2a:
	/* 0x1c2a: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_1c31:
	/* 0x1c31: cmp    BYTE PTR [r13+0x25a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2585570312192ULL);
x86_l_1c39:
	/* 0x1c39: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
	return 7230ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7230ULL: goto x86_l_1c3e;
	case 7235ULL: goto x86_l_1c43;
	case 7239ULL: goto x86_l_1c47;
	case 7244ULL: goto x86_l_1c4c;
	case 7251ULL: goto x86_l_1c53;
	case 7256ULL: goto x86_l_1c58;
	case 7264ULL: goto x86_l_1c60;
	case 7271ULL: goto x86_l_1c67;
	case 7279ULL: goto x86_l_1c6f;
	case 7284ULL: goto x86_l_1c74;
	case 7289ULL: goto x86_l_1c79;
	case 7293ULL: goto x86_l_1c7d;
	case 7298ULL: goto x86_l_1c82;
	case 7305ULL: goto x86_l_1c89;
	case 7311ULL: goto x86_l_1c8f;
	case 7314ULL: goto x86_l_1c92;
	case 7319ULL: goto x86_l_1c97;
	case 7324ULL: goto x86_l_1c9c;
	case 7329ULL: goto x86_l_1ca1;
	case 7334ULL: goto x86_l_1ca6;
	case 7336ULL: goto x86_l_1ca8;
	case 7338ULL: goto x86_l_1caa;
	case 7340ULL: goto x86_l_1cac;
	case 7345ULL: goto x86_l_1cb1;
	case 7352ULL: goto x86_l_1cb8;
	case 7357ULL: goto x86_l_1cbd;
	case 7362ULL: goto x86_l_1cc2;
	case 7367ULL: goto x86_l_1cc7;
	case 7372ULL: goto x86_l_1ccc;
	case 7379ULL: goto x86_l_1cd3;
	case 7384ULL: goto x86_l_1cd8;
	case 7386ULL: goto x86_l_1cda;
	case 7388ULL: goto x86_l_1cdc;
	case 7394ULL: goto x86_l_1ce2;
	case 7397ULL: goto x86_l_1ce5;
	case 7402ULL: goto x86_l_1cea;
	case 7404ULL: goto x86_l_1cec;
	case 7407ULL: goto x86_l_1cef;
	case 7413ULL: goto x86_l_1cf5;
	case 7419ULL: goto x86_l_1cfb;
	case 7426ULL: goto x86_l_1d02;
	case 7429ULL: goto x86_l_1d05;
	case 7433ULL: goto x86_l_1d09;
	case 7436ULL: goto x86_l_1d0c;
	case 7441ULL: goto x86_l_1d11;
	case 7446ULL: goto x86_l_1d16;
	case 7448ULL: goto x86_l_1d18;
	case 7454ULL: goto x86_l_1d1e;
	case 7457ULL: goto x86_l_1d21;
	case 7459ULL: goto x86_l_1d23;
	case 7464ULL: goto x86_l_1d28;
	case 7469ULL: goto x86_l_1d2d;
	case 7474ULL: goto x86_l_1d32;
	case 7479ULL: goto x86_l_1d37;
	case 7484ULL: goto x86_l_1d3c;
	case 7486ULL: goto x86_l_1d3e;
	case 7488ULL: goto x86_l_1d40;
	case 7494ULL: goto x86_l_1d46;
	case 7500ULL: goto x86_l_1d4c;
	case 7506ULL: goto x86_l_1d52;
	case 7510ULL: goto x86_l_1d56;
	case 7515ULL: goto x86_l_1d5b;
	case 7520ULL: goto x86_l_1d60;
	case 7526ULL: goto x86_l_1d66;
	case 7528ULL: goto x86_l_1d68;
	case 7533ULL: goto x86_l_1d6d;
	case 7538ULL: goto x86_l_1d72;
	case 7543ULL: goto x86_l_1d77;
	case 7548ULL: goto x86_l_1d7c;
	case 7553ULL: goto x86_l_1d81;
	case 7555ULL: goto x86_l_1d83;
	case 7557ULL: goto x86_l_1d85;
	case 7563ULL: goto x86_l_1d8b;
	case 7572ULL: goto x86_l_1d94;
	case 7578ULL: goto x86_l_1d9a;
	case 7585ULL: goto x86_l_1da1;
	case 7590ULL: goto x86_l_1da6;
	case 7595ULL: goto x86_l_1dab;
	case 7604ULL: goto x86_l_1db4;
	case 7606ULL: goto x86_l_1db6;
	case 7611ULL: goto x86_l_1dbb;
	case 7616ULL: goto x86_l_1dc0;
	case 7621ULL: goto x86_l_1dc5;
	case 7626ULL: goto x86_l_1dca;
	case 7631ULL: goto x86_l_1dcf;
	case 7633ULL: goto x86_l_1dd1;
	case 7635ULL: goto x86_l_1dd3;
	case 7641ULL: goto x86_l_1dd9;
	case 7650ULL: goto x86_l_1de2;
	case 7656ULL: goto x86_l_1de8;
	case 7663ULL: goto x86_l_1def;
	case 7668ULL: goto x86_l_1df4;
	case 7673ULL: goto x86_l_1df9;
	case 7682ULL: goto x86_l_1e02;
	case 7684ULL: goto x86_l_1e04;
	case 7689ULL: goto x86_l_1e09;
	case 7694ULL: goto x86_l_1e0e;
	case 7699ULL: goto x86_l_1e13;
	case 7704ULL: goto x86_l_1e18;
	case 7709ULL: goto x86_l_1e1d;
	case 7711ULL: goto x86_l_1e1f;
	case 7713ULL: goto x86_l_1e21;
	case 7719ULL: goto x86_l_1e27;
	case 7728ULL: goto x86_l_1e30;
	case 7734ULL: goto x86_l_1e36;
	case 7741ULL: goto x86_l_1e3d;
	case 7746ULL: goto x86_l_1e42;
	case 7751ULL: goto x86_l_1e47;
	case 7760ULL: goto x86_l_1e50;
	case 7762ULL: goto x86_l_1e52;
	case 7767ULL: goto x86_l_1e57;
	case 7772ULL: goto x86_l_1e5c;
	case 7777ULL: goto x86_l_1e61;
	case 7782ULL: goto x86_l_1e66;
	case 7787ULL: goto x86_l_1e6b;
	case 7789ULL: goto x86_l_1e6d;
	case 7791ULL: goto x86_l_1e6f;
	case 7797ULL: goto x86_l_1e75;
	case 7806ULL: goto x86_l_1e7e;
	case 7812ULL: goto x86_l_1e84;
	case 7819ULL: goto x86_l_1e8b;
	case 7824ULL: goto x86_l_1e90;
	case 7829ULL: goto x86_l_1e95;
	case 7838ULL: goto x86_l_1e9e;
	case 7840ULL: goto x86_l_1ea0;
	case 7845ULL: goto x86_l_1ea5;
	case 7850ULL: goto x86_l_1eaa;
	case 7855ULL: goto x86_l_1eaf;
	case 7860ULL: goto x86_l_1eb4;
	case 7865ULL: goto x86_l_1eb9;
	case 7867ULL: goto x86_l_1ebb;
	case 7869ULL: goto x86_l_1ebd;
	case 7875ULL: goto x86_l_1ec3;
	case 7884ULL: goto x86_l_1ecc;
	case 7890ULL: goto x86_l_1ed2;
	case 7897ULL: goto x86_l_1ed9;
	case 7902ULL: goto x86_l_1ede;
	case 7907ULL: goto x86_l_1ee3;
	case 7916ULL: goto x86_l_1eec;
	case 7918ULL: goto x86_l_1eee;
	case 7923ULL: goto x86_l_1ef3;
	case 7928ULL: goto x86_l_1ef8;
	case 7933ULL: goto x86_l_1efd;
	case 7938ULL: goto x86_l_1f02;
	case 7943ULL: goto x86_l_1f07;
	case 7945ULL: goto x86_l_1f09;
	case 7947ULL: goto x86_l_1f0b;
	case 7953ULL: goto x86_l_1f11;
	case 7962ULL: goto x86_l_1f1a;
	case 7968ULL: goto x86_l_1f20;
	case 7975ULL: goto x86_l_1f27;
	case 7980ULL: goto x86_l_1f2c;
	case 7985ULL: goto x86_l_1f31;
	case 7994ULL: goto x86_l_1f3a;
	case 7996ULL: goto x86_l_1f3c;
	case 8001ULL: goto x86_l_1f41;
	case 8006ULL: goto x86_l_1f46;
	case 8011ULL: goto x86_l_1f4b;
	case 8016ULL: goto x86_l_1f50;
	case 8021ULL: goto x86_l_1f55;
	case 8023ULL: goto x86_l_1f57;
	case 8025ULL: goto x86_l_1f59;
	case 8031ULL: goto x86_l_1f5f;
	case 8040ULL: goto x86_l_1f68;
	case 8046ULL: goto x86_l_1f6e;
	case 8053ULL: goto x86_l_1f75;
	case 8058ULL: goto x86_l_1f7a;
	case 8063ULL: goto x86_l_1f7f;
	case 8072ULL: goto x86_l_1f88;
	case 8074ULL: goto x86_l_1f8a;
	case 8079ULL: goto x86_l_1f8f;
	case 8084ULL: goto x86_l_1f94;
	case 8089ULL: goto x86_l_1f99;
	case 8094ULL: goto x86_l_1f9e;
	case 8099ULL: goto x86_l_1fa3;
	case 8101ULL: goto x86_l_1fa5;
	case 8103ULL: goto x86_l_1fa7;
	case 8109ULL: goto x86_l_1fad;
	case 8114ULL: goto x86_l_1fb2;
	case 8123ULL: goto x86_l_1fbb;
	case 8128ULL: goto x86_l_1fc0;
	case 8134ULL: goto x86_l_1fc6;
	case 8141ULL: goto x86_l_1fcd;
	case 8146ULL: goto x86_l_1fd2;
	case 8151ULL: goto x86_l_1fd7;
	case 8160ULL: goto x86_l_1fe0;
	case 8166ULL: goto x86_l_1fe6;
	case 8171ULL: goto x86_l_1feb;
	case 8176ULL: goto x86_l_1ff0;
	case 8181ULL: goto x86_l_1ff5;
	case 8186ULL: goto x86_l_1ffa;
	case 8189ULL: goto x86_l_1ffd;
	case 8191ULL: goto x86_l_1fff;
	case 8196ULL: goto x86_l_2004;
	case 8201ULL: goto x86_l_2009;
	case 8206ULL: goto x86_l_200e;
	case 8211ULL: goto x86_l_2013;
	case 8216ULL: goto x86_l_2018;
	case 8218ULL: goto x86_l_201a;
	case 8220ULL: goto x86_l_201c;
	case 8226ULL: goto x86_l_2022;
	case 8232ULL: goto x86_l_2028;
	case 8238ULL: goto x86_l_202e;
	case 8242ULL: goto x86_l_2032;
	case 8247ULL: goto x86_l_2037;
	case 8252ULL: goto x86_l_203c;
	case 8258ULL: goto x86_l_2042;
	case 8260ULL: goto x86_l_2044;
	case 8265ULL: goto x86_l_2049;
	case 8270ULL: goto x86_l_204e;
	case 8275ULL: goto x86_l_2053;
	case 8280ULL: goto x86_l_2058;
	case 8285ULL: goto x86_l_205d;
	case 8287ULL: goto x86_l_205f;
	case 8289ULL: goto x86_l_2061;
	case 8295ULL: goto x86_l_2067;
	case 8304ULL: goto x86_l_2070;
	case 8310ULL: goto x86_l_2076;
	case 8317ULL: goto x86_l_207d;
	case 8322ULL: goto x86_l_2082;
	case 8327ULL: goto x86_l_2087;
	case 8336ULL: goto x86_l_2090;
	case 8338ULL: goto x86_l_2092;
	case 8343ULL: goto x86_l_2097;
	case 8348ULL: goto x86_l_209c;
	case 8353ULL: goto x86_l_20a1;
	case 8358ULL: goto x86_l_20a6;
	case 8363ULL: goto x86_l_20ab;
	case 8365ULL: goto x86_l_20ad;
	case 8367ULL: goto x86_l_20af;
	case 8373ULL: goto x86_l_20b5;
	case 8382ULL: goto x86_l_20be;
	case 8388ULL: goto x86_l_20c4;
	case 8395ULL: goto x86_l_20cb;
	case 8400ULL: goto x86_l_20d0;
	case 8405ULL: goto x86_l_20d5;
	case 8414ULL: goto x86_l_20de;
	case 8416ULL: goto x86_l_20e0;
	case 8421ULL: goto x86_l_20e5;
	case 8426ULL: goto x86_l_20ea;
	case 8431ULL: goto x86_l_20ef;
	case 8436ULL: goto x86_l_20f4;
	case 8441ULL: goto x86_l_20f9;
	case 8443ULL: goto x86_l_20fb;
	case 8445ULL: goto x86_l_20fd;
	case 8451ULL: goto x86_l_2103;
	case 8460ULL: goto x86_l_210c;
	case 8466ULL: goto x86_l_2112;
	case 8473ULL: goto x86_l_2119;
	case 8478ULL: goto x86_l_211e;
	case 8483ULL: goto x86_l_2123;
	case 8492ULL: goto x86_l_212c;
	case 8494ULL: goto x86_l_212e;
	case 8499ULL: goto x86_l_2133;
	case 8504ULL: goto x86_l_2138;
	case 8509ULL: goto x86_l_213d;
	case 8514ULL: goto x86_l_2142;
	case 8519ULL: goto x86_l_2147;
	case 8521ULL: goto x86_l_2149;
	case 8523ULL: goto x86_l_214b;
	case 8529ULL: goto x86_l_2151;
	case 8538ULL: goto x86_l_215a;
	case 8544ULL: goto x86_l_2160;
	case 8551ULL: goto x86_l_2167;
	case 8556ULL: goto x86_l_216c;
	case 8561ULL: goto x86_l_2171;
	case 8570ULL: goto x86_l_217a;
	case 8572ULL: goto x86_l_217c;
	case 8577ULL: goto x86_l_2181;
	case 8582ULL: goto x86_l_2186;
	case 8587ULL: goto x86_l_218b;
	case 8592ULL: goto x86_l_2190;
	case 8597ULL: goto x86_l_2195;
	case 8599ULL: goto x86_l_2197;
	case 8601ULL: goto x86_l_2199;
	case 8607ULL: goto x86_l_219f;
	case 8616ULL: goto x86_l_21a8;
	case 8622ULL: goto x86_l_21ae;
	case 8629ULL: goto x86_l_21b5;
	case 8634ULL: goto x86_l_21ba;
	case 8639ULL: goto x86_l_21bf;
	case 8648ULL: goto x86_l_21c8;
	case 8650ULL: goto x86_l_21ca;
	case 8655ULL: goto x86_l_21cf;
	case 8660ULL: goto x86_l_21d4;
	case 8665ULL: goto x86_l_21d9;
	case 8670ULL: goto x86_l_21de;
	case 8675ULL: goto x86_l_21e3;
	case 8677ULL: goto x86_l_21e5;
	case 8679ULL: goto x86_l_21e7;
	case 8685ULL: goto x86_l_21ed;
	case 8694ULL: goto x86_l_21f6;
	case 8700ULL: goto x86_l_21fc;
	case 8707ULL: goto x86_l_2203;
	case 8712ULL: goto x86_l_2208;
	case 8717ULL: goto x86_l_220d;
	case 8726ULL: goto x86_l_2216;
	case 8728ULL: goto x86_l_2218;
	case 8733ULL: goto x86_l_221d;
	case 8738ULL: goto x86_l_2222;
	case 8743ULL: goto x86_l_2227;
	case 8748ULL: goto x86_l_222c;
	case 8753ULL: goto x86_l_2231;
	case 8755ULL: goto x86_l_2233;
	case 8757ULL: goto x86_l_2235;
	case 8763ULL: goto x86_l_223b;
	case 8768ULL: goto x86_l_2240;
	case 8777ULL: goto x86_l_2249;
	case 8782ULL: goto x86_l_224e;
	case 8788ULL: goto x86_l_2254;
	case 8795ULL: goto x86_l_225b;
	case 8800ULL: goto x86_l_2260;
	case 8805ULL: goto x86_l_2265;
	case 8814ULL: goto x86_l_226e;
	case 8816ULL: goto x86_l_2270;
	case 8821ULL: goto x86_l_2275;
	case 8826ULL: goto x86_l_227a;
	case 8831ULL: goto x86_l_227f;
	case 8836ULL: goto x86_l_2284;
	case 8841ULL: goto x86_l_2289;
	case 8843ULL: goto x86_l_228b;
	case 8845ULL: goto x86_l_228d;
	case 8851ULL: goto x86_l_2293;
	case 8856ULL: goto x86_l_2298;
	case 8865ULL: goto x86_l_22a1;
	case 8870ULL: goto x86_l_22a6;
	case 8876ULL: goto x86_l_22ac;
	case 8883ULL: goto x86_l_22b3;
	case 8888ULL: goto x86_l_22b8;
	case 8893ULL: goto x86_l_22bd;
	case 8902ULL: goto x86_l_22c6;
	case 8908ULL: goto x86_l_22cc;
	case 8913ULL: goto x86_l_22d1;
	case 8918ULL: goto x86_l_22d6;
	case 8923ULL: goto x86_l_22db;
	case 8928ULL: goto x86_l_22e0;
	case 8933ULL: goto x86_l_22e5;
	case 8935ULL: goto x86_l_22e7;
	case 8937ULL: goto x86_l_22e9;
	case 8943ULL: goto x86_l_22ef;
	case 8948ULL: goto x86_l_22f4;
	case 8953ULL: goto x86_l_22f9;
	case 8960ULL: goto x86_l_2300;
	case 8966ULL: goto x86_l_2306;
	case 8969ULL: goto x86_l_2309;
	case 8974ULL: goto x86_l_230e;
	case 8979ULL: goto x86_l_2313;
	case 8984ULL: goto x86_l_2318;
	case 8989ULL: goto x86_l_231d;
	case 8991ULL: goto x86_l_231f;
	case 8993ULL: goto x86_l_2321;
	case 8999ULL: goto x86_l_2327;
	case 9006ULL: goto x86_l_232e;
	case 9012ULL: goto x86_l_2334;
	case 9015ULL: goto x86_l_2337;
	case 9020ULL: goto x86_l_233c;
	case 9025ULL: goto x86_l_2341;
	case 9030ULL: goto x86_l_2346;
	case 9035ULL: goto x86_l_234b;
	case 9037ULL: goto x86_l_234d;
	case 9039ULL: goto x86_l_234f;
	case 9041ULL: goto x86_l_2351;
	case 9049ULL: goto x86_l_2359;
	case 9056ULL: goto x86_l_2360;
	case 9063ULL: goto x86_l_2367;
	case 9068ULL: goto x86_l_236c;
	case 9071ULL: goto x86_l_236f;
	case 9076ULL: goto x86_l_2374;
	case 9081ULL: goto x86_l_2379;
	case 9086ULL: goto x86_l_237e;
	case 9094ULL: goto x86_l_2386;
	case 9101ULL: goto x86_l_238d;
	case 9108ULL: goto x86_l_2394;
	case 9113ULL: goto x86_l_2399;
	case 9116ULL: goto x86_l_239c;
	case 9121ULL: goto x86_l_23a1;
	case 9123ULL: goto x86_l_23a3;
	case 9125ULL: goto x86_l_23a5;
	case 9131ULL: goto x86_l_23ab;
	case 9134ULL: goto x86_l_23ae;
	case 9139ULL: goto x86_l_23b3;
	case 9141ULL: goto x86_l_23b5;
	case 9144ULL: goto x86_l_23b8;
	case 9153ULL: goto x86_l_23c1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c3e:
	/* 0x1c3e: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_1c43:
	/* 0x1c43: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1c47:
	/* 0x1c47: jmp    3167 <generic_sleepable_preload+0x3167> */
	return 12647ULL;
x86_l_1c4c:
	/* 0x1c4c: mov    rax,QWORD PTR [r13+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_1c53:
	/* 0x1c53: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c58:
	/* 0x1c58: movzx  eax,BYTE PTR [r13+0x270] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 624ULL);
x86_l_1c60:
	/* 0x1c60: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_1c67:
	/* 0x1c67: cmp    BYTE PTR [r13+0x272],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2688649527296ULL);
x86_l_1c6f:
	/* 0x1c6f: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_1c74:
	/* 0x1c74: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_1c79:
	/* 0x1c79: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1c7d:
	/* 0x1c7d: jmp    383e <generic_sleepable_preload+0x383e> */
	return 14398ULL;
x86_l_1c82:
	/* 0x1c82: mov    edx,DWORD PTR [r13+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_1c89:
	/* 0x1c89: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1c8f:
	/* 0x1c8f: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c92:
	/* 0x1c92: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c97:
	/* 0x1c97: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1c9c:
	/* 0x1c9c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ca1:
	/* 0x1ca1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ca6:
	/* 0x1ca6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca8:
	/* 0x1ca8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1caa:
	/* 0x1caa: jne    1ce2 <generic_sleepable_preload+0x1ce2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ce2;
	}
x86_l_1cac:
	/* 0x1cac: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cb1:
	/* 0x1cb1: add    rcx,QWORD PTR [r13+0x200] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 512ULL);
x86_l_1cb8:
	/* 0x1cb8: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cbd:
	/* 0x1cbd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1cc2:
	/* 0x1cc2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1cc7:
	/* 0x1cc7: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ccc:
	/* 0x1ccc: add    rdx,QWORD PTR [r13+0x200] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 512ULL);
x86_l_1cd3:
	/* 0x1cd3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cd8:
	/* 0x1cd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cda:
	/* 0x1cda: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cdc:
	/* 0x1cdc: je     1b7b <generic_sleepable_preload+0x1b7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7035ULL;
	}
x86_l_1ce2:
	/* 0x1ce2: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_1ce5:
	/* 0x1ce5: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cea:
	/* 0x1cea: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cec:
	/* 0x1cec: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_1cef:
	/* 0x1cef: cmp    WORD PTR [r13+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_1cf5:
	/* 0x1cf5: je     627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25210ULL;
	}
x86_l_1cfb:
	/* 0x1cfb: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1d02:
	/* 0x1d02: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1d05:
	/* 0x1d05: mov    eax,DWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1d09:
	/* 0x1d09: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1d0c:
	/* 0x1d0c: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d11:
	/* 0x1d11: movzx  eax,WORD PTR [r13+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_1d16:
	/* 0x1d16: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1d18:
	/* 0x1d18: je     1ffa <generic_sleepable_preload+0x1ffa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ffa;
	}
x86_l_1d1e:
	/* 0x1d1e: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1d21:
	/* 0x1d21: je     1d46 <generic_sleepable_preload+0x1d46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d46;
	}
x86_l_1d23:
	/* 0x1d23: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d28:
	/* 0x1d28: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d2d:
	/* 0x1d2d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d32:
	/* 0x1d32: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d37:
	/* 0x1d37: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d3c:
	/* 0x1d3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d3e:
	/* 0x1d3e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d40:
	/* 0x1d40: js     3e5e <generic_sleepable_preload+0x3e5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15966ULL;
	}
x86_l_1d46:
	/* 0x1d46: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_1d4c:
	/* 0x1d4c: je     627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25210ULL;
	}
x86_l_1d52:
	/* 0x1d52: mov    ecx,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1d56:
	/* 0x1d56: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1d5b:
	/* 0x1d5b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d60:
	/* 0x1d60: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_1d66:
	/* 0x1d66: je     1d8b <generic_sleepable_preload+0x1d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d8b;
	}
x86_l_1d68:
	/* 0x1d68: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d6d:
	/* 0x1d6d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d72:
	/* 0x1d72: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d77:
	/* 0x1d77: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d7c:
	/* 0x1d7c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d81:
	/* 0x1d81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d83:
	/* 0x1d83: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d85:
	/* 0x1d85: js     53ff <generic_sleepable_preload+0x53ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21503ULL;
	}
x86_l_1d8b:
	/* 0x1d8b: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_1d94:
	/* 0x1d94: je     627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25210ULL;
	}
x86_l_1d9a:
	/* 0x1d9a: mov    ecx,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1da1:
	/* 0x1da1: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1da6:
	/* 0x1da6: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dab:
	/* 0x1dab: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1db4:
	/* 0x1db4: je     1dd9 <generic_sleepable_preload+0x1dd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dd9;
	}
x86_l_1db6:
	/* 0x1db6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dbb:
	/* 0x1dbb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1dc0:
	/* 0x1dc0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1dc5:
	/* 0x1dc5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dca:
	/* 0x1dca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dcf:
	/* 0x1dcf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd1:
	/* 0x1dd1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1dd3:
	/* 0x1dd3: js     60e6 <generic_sleepable_preload+0x60e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24806ULL;
	}
x86_l_1dd9:
	/* 0x1dd9: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1de2:
	/* 0x1de2: je     627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25210ULL;
	}
x86_l_1de8:
	/* 0x1de8: mov    ecx,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1def:
	/* 0x1def: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1df4:
	/* 0x1df4: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1df9:
	/* 0x1df9: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1e02:
	/* 0x1e02: je     1e27 <generic_sleepable_preload+0x1e27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e27;
	}
x86_l_1e04:
	/* 0x1e04: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e09:
	/* 0x1e09: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1e0e:
	/* 0x1e0e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e13:
	/* 0x1e13: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e18:
	/* 0x1e18: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e1d:
	/* 0x1e1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e1f:
	/* 0x1e1f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e21:
	/* 0x1e21: js     614a <generic_sleepable_preload+0x614a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24906ULL;
	}
x86_l_1e27:
	/* 0x1e27: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1e30:
	/* 0x1e30: je     627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25210ULL;
	}
x86_l_1e36:
	/* 0x1e36: mov    ecx,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1e3d:
	/* 0x1e3d: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1e42:
	/* 0x1e42: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e47:
	/* 0x1e47: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1e50:
	/* 0x1e50: je     1e75 <generic_sleepable_preload+0x1e75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e75;
	}
x86_l_1e52:
	/* 0x1e52: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e57:
	/* 0x1e57: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1e5c:
	/* 0x1e5c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e61:
	/* 0x1e61: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e66:
	/* 0x1e66: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e6b:
	/* 0x1e6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e6d:
	/* 0x1e6d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e6f:
	/* 0x1e6f: js     61ae <generic_sleepable_preload+0x61ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25006ULL;
	}
x86_l_1e75:
	/* 0x1e75: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_1e7e:
	/* 0x1e7e: je     627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25210ULL;
	}
x86_l_1e84:
	/* 0x1e84: mov    ecx,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1e8b:
	/* 0x1e8b: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1e90:
	/* 0x1e90: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e95:
	/* 0x1e95: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1e9e:
	/* 0x1e9e: je     1ec3 <generic_sleepable_preload+0x1ec3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ec3;
	}
x86_l_1ea0:
	/* 0x1ea0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ea5:
	/* 0x1ea5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1eaa:
	/* 0x1eaa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1eaf:
	/* 0x1eaf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1eb4:
	/* 0x1eb4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1eb9:
	/* 0x1eb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ebb:
	/* 0x1ebb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ebd:
	/* 0x1ebd: js     6212 <generic_sleepable_preload+0x6212> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25106ULL;
	}
x86_l_1ec3:
	/* 0x1ec3: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1ecc:
	/* 0x1ecc: je     627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25210ULL;
	}
x86_l_1ed2:
	/* 0x1ed2: mov    ecx,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1ed9:
	/* 0x1ed9: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1ede:
	/* 0x1ede: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ee3:
	/* 0x1ee3: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1eec:
	/* 0x1eec: je     1f11 <generic_sleepable_preload+0x1f11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f11;
	}
x86_l_1eee:
	/* 0x1eee: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ef3:
	/* 0x1ef3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1ef8:
	/* 0x1ef8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1efd:
	/* 0x1efd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f02:
	/* 0x1f02: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f07:
	/* 0x1f07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f09:
	/* 0x1f09: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f0b:
	/* 0x1f0b: js     6273 <generic_sleepable_preload+0x6273> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25203ULL;
	}
x86_l_1f11:
	/* 0x1f11: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1f1a:
	/* 0x1f1a: je     627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25210ULL;
	}
x86_l_1f20:
	/* 0x1f20: mov    ecx,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1f27:
	/* 0x1f27: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1f2c:
	/* 0x1f2c: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f31:
	/* 0x1f31: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1f3a:
	/* 0x1f3a: je     1f5f <generic_sleepable_preload+0x1f5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f5f;
	}
x86_l_1f3c:
	/* 0x1f3c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f41:
	/* 0x1f41: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1f46:
	/* 0x1f46: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1f4b:
	/* 0x1f4b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f50:
	/* 0x1f50: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f55:
	/* 0x1f55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f57:
	/* 0x1f57: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f59:
	/* 0x1f59: js     68c3 <generic_sleepable_preload+0x68c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26819ULL;
	}
x86_l_1f5f:
	/* 0x1f5f: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1f68:
	/* 0x1f68: je     627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25210ULL;
	}
x86_l_1f6e:
	/* 0x1f6e: mov    ecx,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1f75:
	/* 0x1f75: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1f7a:
	/* 0x1f7a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f7f:
	/* 0x1f7f: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1f88:
	/* 0x1f88: je     1fad <generic_sleepable_preload+0x1fad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fad;
	}
x86_l_1f8a:
	/* 0x1f8a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f8f:
	/* 0x1f8f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1f94:
	/* 0x1f94: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1f99:
	/* 0x1f99: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f9e:
	/* 0x1f9e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fa3:
	/* 0x1fa3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fa5:
	/* 0x1fa5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fa7:
	/* 0x1fa7: js     6930 <generic_sleepable_preload+0x6930> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26928ULL;
	}
x86_l_1fad:
	/* 0x1fad: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1fb2:
	/* 0x1fb2: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1fbb:
	/* 0x1fbb: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fc0:
	/* 0x1fc0: je     627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25210ULL;
	}
x86_l_1fc6:
	/* 0x1fc6: mov    ecx,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1fcd:
	/* 0x1fcd: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1fd2:
	/* 0x1fd2: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fd7:
	/* 0x1fd7: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1fe0:
	/* 0x1fe0: je     627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25210ULL;
	}
x86_l_1fe6:
	/* 0x1fe6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1feb:
	/* 0x1feb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1ff0:
	/* 0x1ff0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1ff5:
	/* 0x1ff5: jmp    22db <generic_sleepable_preload+0x22db> */
	goto x86_l_22db;
x86_l_1ffa:
	/* 0x1ffa: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1ffd:
	/* 0x1ffd: je     2022 <generic_sleepable_preload+0x2022> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2022;
	}
x86_l_1fff:
	/* 0x1fff: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2004:
	/* 0x2004: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2009:
	/* 0x2009: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_200e:
	/* 0x200e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2013:
	/* 0x2013: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2018:
	/* 0x2018: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_201a:
	/* 0x201a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_201c:
	/* 0x201c: js     3e5e <generic_sleepable_preload+0x3e5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15966ULL;
	}
x86_l_2022:
	/* 0x2022: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_2028:
	/* 0x2028: je     627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25210ULL;
	}
x86_l_202e:
	/* 0x202e: mov    ecx,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2032:
	/* 0x2032: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2037:
	/* 0x2037: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_203c:
	/* 0x203c: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_2042:
	/* 0x2042: je     2067 <generic_sleepable_preload+0x2067> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2067;
	}
x86_l_2044:
	/* 0x2044: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2049:
	/* 0x2049: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_204e:
	/* 0x204e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2053:
	/* 0x2053: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2058:
	/* 0x2058: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_205d:
	/* 0x205d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_205f:
	/* 0x205f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2061:
	/* 0x2061: js     53ff <generic_sleepable_preload+0x53ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21503ULL;
	}
x86_l_2067:
	/* 0x2067: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_2070:
	/* 0x2070: je     627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25210ULL;
	}
x86_l_2076:
	/* 0x2076: mov    ecx,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_207d:
	/* 0x207d: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2082:
	/* 0x2082: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2087:
	/* 0x2087: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_2090:
	/* 0x2090: je     20b5 <generic_sleepable_preload+0x20b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20b5;
	}
x86_l_2092:
	/* 0x2092: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2097:
	/* 0x2097: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_209c:
	/* 0x209c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20a1:
	/* 0x20a1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20a6:
	/* 0x20a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20ab:
	/* 0x20ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ad:
	/* 0x20ad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20af:
	/* 0x20af: js     60e6 <generic_sleepable_preload+0x60e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24806ULL;
	}
x86_l_20b5:
	/* 0x20b5: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_20be:
	/* 0x20be: je     627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25210ULL;
	}
x86_l_20c4:
	/* 0x20c4: mov    ecx,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_20cb:
	/* 0x20cb: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_20d0:
	/* 0x20d0: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20d5:
	/* 0x20d5: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_20de:
	/* 0x20de: je     2103 <generic_sleepable_preload+0x2103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2103;
	}
x86_l_20e0:
	/* 0x20e0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20e5:
	/* 0x20e5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_20ea:
	/* 0x20ea: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20ef:
	/* 0x20ef: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20f4:
	/* 0x20f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20f9:
	/* 0x20f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20fb:
	/* 0x20fb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20fd:
	/* 0x20fd: js     614a <generic_sleepable_preload+0x614a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24906ULL;
	}
x86_l_2103:
	/* 0x2103: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_210c:
	/* 0x210c: je     627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25210ULL;
	}
x86_l_2112:
	/* 0x2112: mov    ecx,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2119:
	/* 0x2119: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_211e:
	/* 0x211e: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2123:
	/* 0x2123: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_212c:
	/* 0x212c: je     2151 <generic_sleepable_preload+0x2151> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2151;
	}
x86_l_212e:
	/* 0x212e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2133:
	/* 0x2133: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2138:
	/* 0x2138: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_213d:
	/* 0x213d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2142:
	/* 0x2142: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2147:
	/* 0x2147: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2149:
	/* 0x2149: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_214b:
	/* 0x214b: js     61ae <generic_sleepable_preload+0x61ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25006ULL;
	}
x86_l_2151:
	/* 0x2151: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_215a:
	/* 0x215a: je     627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25210ULL;
	}
x86_l_2160:
	/* 0x2160: mov    ecx,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2167:
	/* 0x2167: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_216c:
	/* 0x216c: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2171:
	/* 0x2171: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_217a:
	/* 0x217a: je     219f <generic_sleepable_preload+0x219f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_219f;
	}
x86_l_217c:
	/* 0x217c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2181:
	/* 0x2181: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2186:
	/* 0x2186: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_218b:
	/* 0x218b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2190:
	/* 0x2190: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2195:
	/* 0x2195: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2197:
	/* 0x2197: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2199:
	/* 0x2199: js     6212 <generic_sleepable_preload+0x6212> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25106ULL;
	}
x86_l_219f:
	/* 0x219f: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_21a8:
	/* 0x21a8: je     627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25210ULL;
	}
x86_l_21ae:
	/* 0x21ae: mov    ecx,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_21b5:
	/* 0x21b5: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_21ba:
	/* 0x21ba: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21bf:
	/* 0x21bf: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_21c8:
	/* 0x21c8: je     21ed <generic_sleepable_preload+0x21ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21ed;
	}
x86_l_21ca:
	/* 0x21ca: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21cf:
	/* 0x21cf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_21d4:
	/* 0x21d4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_21d9:
	/* 0x21d9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21de:
	/* 0x21de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21e3:
	/* 0x21e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21e5:
	/* 0x21e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21e7:
	/* 0x21e7: js     6273 <generic_sleepable_preload+0x6273> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25203ULL;
	}
x86_l_21ed:
	/* 0x21ed: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_21f6:
	/* 0x21f6: je     627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25210ULL;
	}
x86_l_21fc:
	/* 0x21fc: mov    ecx,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2203:
	/* 0x2203: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2208:
	/* 0x2208: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_220d:
	/* 0x220d: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_2216:
	/* 0x2216: je     223b <generic_sleepable_preload+0x223b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_223b;
	}
x86_l_2218:
	/* 0x2218: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_221d:
	/* 0x221d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2222:
	/* 0x2222: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2227:
	/* 0x2227: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x2235: js     69c0 <generic_sleepable_preload+0x69c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27072ULL;
	}
x86_l_223b:
	/* 0x223b: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2240:
	/* 0x2240: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_2249:
	/* 0x2249: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_224e:
	/* 0x224e: je     627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25210ULL;
	}
x86_l_2254:
	/* 0x2254: mov    ecx,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_225b:
	/* 0x225b: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2260:
	/* 0x2260: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2265:
	/* 0x2265: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_226e:
	/* 0x226e: je     2293 <generic_sleepable_preload+0x2293> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2293;
	}
x86_l_2270:
	/* 0x2270: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2275:
	/* 0x2275: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_227a:
	/* 0x227a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_227f:
	/* 0x227f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2284:
	/* 0x2284: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2289:
	/* 0x2289: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_228b:
	/* 0x228b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_228d:
	/* 0x228d: js     6930 <generic_sleepable_preload+0x6930> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26928ULL;
	}
x86_l_2293:
	/* 0x2293: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2298:
	/* 0x2298: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_22a1:
	/* 0x22a1: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22a6:
	/* 0x22a6: je     627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25210ULL;
	}
x86_l_22ac:
	/* 0x22ac: mov    ecx,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_22b3:
	/* 0x22b3: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_22b8:
	/* 0x22b8: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22bd:
	/* 0x22bd: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_22c6:
	/* 0x22c6: je     627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25210ULL;
	}
x86_l_22cc:
	/* 0x22cc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22d1:
	/* 0x22d1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_22d6:
	/* 0x22d6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_22db:
	/* 0x22db: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22e0:
	/* 0x22e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22e5:
	/* 0x22e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22e7:
	/* 0x22e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22e9:
	/* 0x22e9: jns    627a <generic_sleepable_preload+0x627a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25210ULL;
	}
x86_l_22ef:
	/* 0x22ef: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_22f4:
	/* 0x22f4: jmp    6278 <generic_sleepable_preload+0x6278> */
	return 25208ULL;
x86_l_22f9:
	/* 0x22f9: mov    edx,DWORD PTR [r13+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_2300:
	/* 0x2300: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2306:
	/* 0x2306: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2309:
	/* 0x2309: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_230e:
	/* 0x230e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2313:
	/* 0x2313: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2318:
	/* 0x2318: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_231d:
	/* 0x231d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_231f:
	/* 0x231f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2321:
	/* 0x2321: jne    23ab <generic_sleepable_preload+0x23ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23ab;
	}
x86_l_2327:
	/* 0x2327: mov    edx,DWORD PTR [r13+0x224] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 548ULL);
x86_l_232e:
	/* 0x232e: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2334:
	/* 0x2334: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2337:
	/* 0x2337: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_233c:
	/* 0x233c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2341:
	/* 0x2341: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2346:
	/* 0x2346: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_234b:
	/* 0x234b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_234d:
	/* 0x234d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_234f:
	/* 0x234f: jne    23ab <generic_sleepable_preload+0x23ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23ab;
	}
x86_l_2351:
	/* 0x2351: movzx  eax,BYTE PTR [r13+0x22b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 555ULL);
x86_l_2359:
	/* 0x2359: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_2360:
	/* 0x2360: mov    rcx,QWORD PTR [r13+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_2367:
	/* 0x2367: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_236c:
	/* 0x236c: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_236f:
	/* 0x236f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2374:
	/* 0x2374: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2379:
	/* 0x2379: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_237e:
	/* 0x237e: movzx  ecx,BYTE PTR [r13+0x22b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 555ULL);
x86_l_2386:
	/* 0x2386: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_238d:
	/* 0x238d: mov    rdx,QWORD PTR [r13+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_2394:
	/* 0x2394: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2399:
	/* 0x2399: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_239c:
	/* 0x239c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23a1:
	/* 0x23a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23a3:
	/* 0x23a3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23a5:
	/* 0x23a5: je     1bb1 <generic_sleepable_preload+0x1bb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7089ULL;
	}
x86_l_23ab:
	/* 0x23ab: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_23ae:
	/* 0x23ae: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23b3:
	/* 0x23b3: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23b5:
	/* 0x23b5: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_23b8:
	/* 0x23b8: cmp    WORD PTR [r13+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_23c1:
	/* 0x23c1: je     6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25351ULL;
	}
	return 9159ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9159ULL: goto x86_l_23c7;
	case 9166ULL: goto x86_l_23ce;
	case 9169ULL: goto x86_l_23d1;
	case 9176ULL: goto x86_l_23d8;
	case 9179ULL: goto x86_l_23db;
	case 9184ULL: goto x86_l_23e0;
	case 9192ULL: goto x86_l_23e8;
	case 9194ULL: goto x86_l_23ea;
	case 9200ULL: goto x86_l_23f0;
	case 9203ULL: goto x86_l_23f3;
	case 9205ULL: goto x86_l_23f5;
	case 9210ULL: goto x86_l_23fa;
	case 9215ULL: goto x86_l_23ff;
	case 9220ULL: goto x86_l_2404;
	case 9225ULL: goto x86_l_2409;
	case 9230ULL: goto x86_l_240e;
	case 9232ULL: goto x86_l_2410;
	case 9234ULL: goto x86_l_2412;
	case 9240ULL: goto x86_l_2418;
	case 9249ULL: goto x86_l_2421;
	case 9255ULL: goto x86_l_2427;
	case 9262ULL: goto x86_l_242e;
	case 9267ULL: goto x86_l_2433;
	case 9272ULL: goto x86_l_2438;
	case 9281ULL: goto x86_l_2441;
	case 9283ULL: goto x86_l_2443;
	case 9288ULL: goto x86_l_2448;
	case 9293ULL: goto x86_l_244d;
	case 9298ULL: goto x86_l_2452;
	case 9303ULL: goto x86_l_2457;
	case 9308ULL: goto x86_l_245c;
	case 9310ULL: goto x86_l_245e;
	case 9312ULL: goto x86_l_2460;
	case 9318ULL: goto x86_l_2466;
	case 9327ULL: goto x86_l_246f;
	case 9333ULL: goto x86_l_2475;
	case 9340ULL: goto x86_l_247c;
	case 9345ULL: goto x86_l_2481;
	case 9350ULL: goto x86_l_2486;
	case 9359ULL: goto x86_l_248f;
	case 9361ULL: goto x86_l_2491;
	case 9366ULL: goto x86_l_2496;
	case 9371ULL: goto x86_l_249b;
	case 9376ULL: goto x86_l_24a0;
	case 9381ULL: goto x86_l_24a5;
	case 9386ULL: goto x86_l_24aa;
	case 9388ULL: goto x86_l_24ac;
	case 9390ULL: goto x86_l_24ae;
	case 9396ULL: goto x86_l_24b4;
	case 9405ULL: goto x86_l_24bd;
	case 9411ULL: goto x86_l_24c3;
	case 9418ULL: goto x86_l_24ca;
	case 9423ULL: goto x86_l_24cf;
	case 9428ULL: goto x86_l_24d4;
	case 9437ULL: goto x86_l_24dd;
	case 9439ULL: goto x86_l_24df;
	case 9444ULL: goto x86_l_24e4;
	case 9449ULL: goto x86_l_24e9;
	case 9454ULL: goto x86_l_24ee;
	case 9459ULL: goto x86_l_24f3;
	case 9464ULL: goto x86_l_24f8;
	case 9466ULL: goto x86_l_24fa;
	case 9468ULL: goto x86_l_24fc;
	case 9474ULL: goto x86_l_2502;
	case 9483ULL: goto x86_l_250b;
	case 9489ULL: goto x86_l_2511;
	case 9496ULL: goto x86_l_2518;
	case 9501ULL: goto x86_l_251d;
	case 9506ULL: goto x86_l_2522;
	case 9515ULL: goto x86_l_252b;
	case 9517ULL: goto x86_l_252d;
	case 9522ULL: goto x86_l_2532;
	case 9527ULL: goto x86_l_2537;
	case 9532ULL: goto x86_l_253c;
	case 9537ULL: goto x86_l_2541;
	case 9542ULL: goto x86_l_2546;
	case 9544ULL: goto x86_l_2548;
	case 9546ULL: goto x86_l_254a;
	case 9552ULL: goto x86_l_2550;
	case 9561ULL: goto x86_l_2559;
	case 9567ULL: goto x86_l_255f;
	case 9574ULL: goto x86_l_2566;
	case 9579ULL: goto x86_l_256b;
	case 9584ULL: goto x86_l_2570;
	case 9593ULL: goto x86_l_2579;
	case 9595ULL: goto x86_l_257b;
	case 9600ULL: goto x86_l_2580;
	case 9605ULL: goto x86_l_2585;
	case 9610ULL: goto x86_l_258a;
	case 9615ULL: goto x86_l_258f;
	case 9620ULL: goto x86_l_2594;
	case 9622ULL: goto x86_l_2596;
	case 9624ULL: goto x86_l_2598;
	case 9630ULL: goto x86_l_259e;
	case 9639ULL: goto x86_l_25a7;
	case 9645ULL: goto x86_l_25ad;
	case 9652ULL: goto x86_l_25b4;
	case 9657ULL: goto x86_l_25b9;
	case 9662ULL: goto x86_l_25be;
	case 9671ULL: goto x86_l_25c7;
	case 9673ULL: goto x86_l_25c9;
	case 9678ULL: goto x86_l_25ce;
	case 9683ULL: goto x86_l_25d3;
	case 9688ULL: goto x86_l_25d8;
	case 9693ULL: goto x86_l_25dd;
	case 9698ULL: goto x86_l_25e2;
	case 9700ULL: goto x86_l_25e4;
	case 9702ULL: goto x86_l_25e6;
	case 9708ULL: goto x86_l_25ec;
	case 9717ULL: goto x86_l_25f5;
	case 9723ULL: goto x86_l_25fb;
	case 9730ULL: goto x86_l_2602;
	case 9735ULL: goto x86_l_2607;
	case 9740ULL: goto x86_l_260c;
	case 9749ULL: goto x86_l_2615;
	case 9751ULL: goto x86_l_2617;
	case 9756ULL: goto x86_l_261c;
	case 9761ULL: goto x86_l_2621;
	case 9766ULL: goto x86_l_2626;
	case 9771ULL: goto x86_l_262b;
	case 9776ULL: goto x86_l_2630;
	case 9778ULL: goto x86_l_2632;
	case 9780ULL: goto x86_l_2634;
	case 9786ULL: goto x86_l_263a;
	case 9795ULL: goto x86_l_2643;
	case 9801ULL: goto x86_l_2649;
	case 9808ULL: goto x86_l_2650;
	case 9813ULL: goto x86_l_2655;
	case 9818ULL: goto x86_l_265a;
	case 9827ULL: goto x86_l_2663;
	case 9829ULL: goto x86_l_2665;
	case 9834ULL: goto x86_l_266a;
	case 9839ULL: goto x86_l_266f;
	case 9844ULL: goto x86_l_2674;
	case 9849ULL: goto x86_l_2679;
	case 9854ULL: goto x86_l_267e;
	case 9856ULL: goto x86_l_2680;
	case 9858ULL: goto x86_l_2682;
	case 9864ULL: goto x86_l_2688;
	case 9869ULL: goto x86_l_268d;
	case 9878ULL: goto x86_l_2696;
	case 9884ULL: goto x86_l_269c;
	case 9891ULL: goto x86_l_26a3;
	case 9896ULL: goto x86_l_26a8;
	case 9901ULL: goto x86_l_26ad;
	case 9910ULL: goto x86_l_26b6;
	case 9916ULL: goto x86_l_26bc;
	case 9921ULL: goto x86_l_26c1;
	case 9926ULL: goto x86_l_26c6;
	case 9931ULL: goto x86_l_26cb;
	case 9936ULL: goto x86_l_26d0;
	case 9939ULL: goto x86_l_26d3;
	case 9941ULL: goto x86_l_26d5;
	case 9946ULL: goto x86_l_26da;
	case 9951ULL: goto x86_l_26df;
	case 9956ULL: goto x86_l_26e4;
	case 9961ULL: goto x86_l_26e9;
	case 9966ULL: goto x86_l_26ee;
	case 9968ULL: goto x86_l_26f0;
	case 9970ULL: goto x86_l_26f2;
	case 9976ULL: goto x86_l_26f8;
	case 9985ULL: goto x86_l_2701;
	case 9991ULL: goto x86_l_2707;
	case 9998ULL: goto x86_l_270e;
	case 10003ULL: goto x86_l_2713;
	case 10008ULL: goto x86_l_2718;
	case 10017ULL: goto x86_l_2721;
	case 10019ULL: goto x86_l_2723;
	case 10024ULL: goto x86_l_2728;
	case 10029ULL: goto x86_l_272d;
	case 10034ULL: goto x86_l_2732;
	case 10039ULL: goto x86_l_2737;
	case 10044ULL: goto x86_l_273c;
	case 10046ULL: goto x86_l_273e;
	case 10048ULL: goto x86_l_2740;
	case 10054ULL: goto x86_l_2746;
	case 10063ULL: goto x86_l_274f;
	case 10069ULL: goto x86_l_2755;
	case 10076ULL: goto x86_l_275c;
	case 10081ULL: goto x86_l_2761;
	case 10086ULL: goto x86_l_2766;
	case 10095ULL: goto x86_l_276f;
	case 10097ULL: goto x86_l_2771;
	case 10102ULL: goto x86_l_2776;
	case 10107ULL: goto x86_l_277b;
	case 10112ULL: goto x86_l_2780;
	case 10117ULL: goto x86_l_2785;
	case 10122ULL: goto x86_l_278a;
	case 10124ULL: goto x86_l_278c;
	case 10126ULL: goto x86_l_278e;
	case 10132ULL: goto x86_l_2794;
	case 10141ULL: goto x86_l_279d;
	case 10147ULL: goto x86_l_27a3;
	case 10154ULL: goto x86_l_27aa;
	case 10159ULL: goto x86_l_27af;
	case 10164ULL: goto x86_l_27b4;
	case 10173ULL: goto x86_l_27bd;
	case 10175ULL: goto x86_l_27bf;
	case 10180ULL: goto x86_l_27c4;
	case 10185ULL: goto x86_l_27c9;
	case 10190ULL: goto x86_l_27ce;
	case 10195ULL: goto x86_l_27d3;
	case 10200ULL: goto x86_l_27d8;
	case 10202ULL: goto x86_l_27da;
	case 10204ULL: goto x86_l_27dc;
	case 10210ULL: goto x86_l_27e2;
	case 10219ULL: goto x86_l_27eb;
	case 10225ULL: goto x86_l_27f1;
	case 10232ULL: goto x86_l_27f8;
	case 10237ULL: goto x86_l_27fd;
	case 10242ULL: goto x86_l_2802;
	case 10251ULL: goto x86_l_280b;
	case 10253ULL: goto x86_l_280d;
	case 10258ULL: goto x86_l_2812;
	case 10263ULL: goto x86_l_2817;
	case 10268ULL: goto x86_l_281c;
	case 10273ULL: goto x86_l_2821;
	case 10278ULL: goto x86_l_2826;
	case 10280ULL: goto x86_l_2828;
	case 10282ULL: goto x86_l_282a;
	case 10288ULL: goto x86_l_2830;
	case 10297ULL: goto x86_l_2839;
	case 10303ULL: goto x86_l_283f;
	case 10310ULL: goto x86_l_2846;
	case 10315ULL: goto x86_l_284b;
	case 10320ULL: goto x86_l_2850;
	case 10329ULL: goto x86_l_2859;
	case 10331ULL: goto x86_l_285b;
	case 10336ULL: goto x86_l_2860;
	case 10341ULL: goto x86_l_2865;
	case 10346ULL: goto x86_l_286a;
	case 10351ULL: goto x86_l_286f;
	case 10356ULL: goto x86_l_2874;
	case 10358ULL: goto x86_l_2876;
	case 10360ULL: goto x86_l_2878;
	case 10366ULL: goto x86_l_287e;
	case 10375ULL: goto x86_l_2887;
	case 10381ULL: goto x86_l_288d;
	case 10388ULL: goto x86_l_2894;
	case 10393ULL: goto x86_l_2899;
	case 10398ULL: goto x86_l_289e;
	case 10407ULL: goto x86_l_28a7;
	case 10409ULL: goto x86_l_28a9;
	case 10414ULL: goto x86_l_28ae;
	case 10419ULL: goto x86_l_28b3;
	case 10424ULL: goto x86_l_28b8;
	case 10429ULL: goto x86_l_28bd;
	case 10434ULL: goto x86_l_28c2;
	case 10436ULL: goto x86_l_28c4;
	case 10438ULL: goto x86_l_28c6;
	case 10444ULL: goto x86_l_28cc;
	case 10453ULL: goto x86_l_28d5;
	case 10459ULL: goto x86_l_28db;
	case 10466ULL: goto x86_l_28e2;
	case 10471ULL: goto x86_l_28e7;
	case 10476ULL: goto x86_l_28ec;
	case 10485ULL: goto x86_l_28f5;
	case 10487ULL: goto x86_l_28f7;
	case 10492ULL: goto x86_l_28fc;
	case 10497ULL: goto x86_l_2901;
	case 10502ULL: goto x86_l_2906;
	case 10507ULL: goto x86_l_290b;
	case 10512ULL: goto x86_l_2910;
	case 10514ULL: goto x86_l_2912;
	case 10516ULL: goto x86_l_2914;
	case 10522ULL: goto x86_l_291a;
	case 10527ULL: goto x86_l_291f;
	case 10536ULL: goto x86_l_2928;
	case 10542ULL: goto x86_l_292e;
	case 10549ULL: goto x86_l_2935;
	case 10554ULL: goto x86_l_293a;
	case 10559ULL: goto x86_l_293f;
	case 10568ULL: goto x86_l_2948;
	case 10570ULL: goto x86_l_294a;
	case 10575ULL: goto x86_l_294f;
	case 10580ULL: goto x86_l_2954;
	case 10585ULL: goto x86_l_2959;
	case 10590ULL: goto x86_l_295e;
	case 10595ULL: goto x86_l_2963;
	case 10597ULL: goto x86_l_2965;
	case 10599ULL: goto x86_l_2967;
	case 10605ULL: goto x86_l_296d;
	case 10610ULL: goto x86_l_2972;
	case 10619ULL: goto x86_l_297b;
	case 10625ULL: goto x86_l_2981;
	case 10632ULL: goto x86_l_2988;
	case 10637ULL: goto x86_l_298d;
	case 10642ULL: goto x86_l_2992;
	case 10651ULL: goto x86_l_299b;
	case 10657ULL: goto x86_l_29a1;
	case 10662ULL: goto x86_l_29a6;
	case 10667ULL: goto x86_l_29ab;
	case 10672ULL: goto x86_l_29b0;
	case 10677ULL: goto x86_l_29b5;
	case 10682ULL: goto x86_l_29ba;
	case 10684ULL: goto x86_l_29bc;
	case 10686ULL: goto x86_l_29be;
	case 10692ULL: goto x86_l_29c4;
	case 10697ULL: goto x86_l_29c9;
	case 10702ULL: goto x86_l_29ce;
	case 10709ULL: goto x86_l_29d5;
	case 10715ULL: goto x86_l_29db;
	case 10718ULL: goto x86_l_29de;
	case 10723ULL: goto x86_l_29e3;
	case 10728ULL: goto x86_l_29e8;
	case 10733ULL: goto x86_l_29ed;
	case 10738ULL: goto x86_l_29f2;
	case 10740ULL: goto x86_l_29f4;
	case 10742ULL: goto x86_l_29f6;
	case 10748ULL: goto x86_l_29fc;
	case 10755ULL: goto x86_l_2a03;
	case 10761ULL: goto x86_l_2a09;
	case 10764ULL: goto x86_l_2a0c;
	case 10769ULL: goto x86_l_2a11;
	case 10774ULL: goto x86_l_2a16;
	case 10779ULL: goto x86_l_2a1b;
	case 10784ULL: goto x86_l_2a20;
	case 10786ULL: goto x86_l_2a22;
	case 10788ULL: goto x86_l_2a24;
	case 10790ULL: goto x86_l_2a26;
	case 10798ULL: goto x86_l_2a2e;
	case 10805ULL: goto x86_l_2a35;
	case 10812ULL: goto x86_l_2a3c;
	case 10817ULL: goto x86_l_2a41;
	case 10820ULL: goto x86_l_2a44;
	case 10825ULL: goto x86_l_2a49;
	case 10830ULL: goto x86_l_2a4e;
	case 10835ULL: goto x86_l_2a53;
	case 10843ULL: goto x86_l_2a5b;
	case 10850ULL: goto x86_l_2a62;
	case 10857ULL: goto x86_l_2a69;
	case 10862ULL: goto x86_l_2a6e;
	case 10865ULL: goto x86_l_2a71;
	case 10870ULL: goto x86_l_2a76;
	case 10872ULL: goto x86_l_2a78;
	case 10874ULL: goto x86_l_2a7a;
	case 10880ULL: goto x86_l_2a80;
	case 10883ULL: goto x86_l_2a83;
	case 10888ULL: goto x86_l_2a88;
	case 10890ULL: goto x86_l_2a8a;
	case 10893ULL: goto x86_l_2a8d;
	case 10902ULL: goto x86_l_2a96;
	case 10908ULL: goto x86_l_2a9c;
	case 10915ULL: goto x86_l_2aa3;
	case 10918ULL: goto x86_l_2aa6;
	case 10925ULL: goto x86_l_2aad;
	case 10928ULL: goto x86_l_2ab0;
	case 10933ULL: goto x86_l_2ab5;
	case 10941ULL: goto x86_l_2abd;
	case 10943ULL: goto x86_l_2abf;
	case 10949ULL: goto x86_l_2ac5;
	case 10952ULL: goto x86_l_2ac8;
	case 10954ULL: goto x86_l_2aca;
	case 10959ULL: goto x86_l_2acf;
	case 10964ULL: goto x86_l_2ad4;
	case 10969ULL: goto x86_l_2ad9;
	case 10974ULL: goto x86_l_2ade;
	case 10979ULL: goto x86_l_2ae3;
	case 10981ULL: goto x86_l_2ae5;
	case 10983ULL: goto x86_l_2ae7;
	case 10989ULL: goto x86_l_2aed;
	case 10998ULL: goto x86_l_2af6;
	case 11004ULL: goto x86_l_2afc;
	case 11011ULL: goto x86_l_2b03;
	case 11016ULL: goto x86_l_2b08;
	case 11021ULL: goto x86_l_2b0d;
	case 11030ULL: goto x86_l_2b16;
	case 11032ULL: goto x86_l_2b18;
	case 11037ULL: goto x86_l_2b1d;
	case 11042ULL: goto x86_l_2b22;
	case 11047ULL: goto x86_l_2b27;
	case 11052ULL: goto x86_l_2b2c;
	case 11057ULL: goto x86_l_2b31;
	case 11059ULL: goto x86_l_2b33;
	case 11061ULL: goto x86_l_2b35;
	case 11067ULL: goto x86_l_2b3b;
	case 11076ULL: goto x86_l_2b44;
	case 11082ULL: goto x86_l_2b4a;
	case 11089ULL: goto x86_l_2b51;
	case 11094ULL: goto x86_l_2b56;
	case 11099ULL: goto x86_l_2b5b;
	case 11108ULL: goto x86_l_2b64;
	case 11110ULL: goto x86_l_2b66;
	case 11115ULL: goto x86_l_2b6b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_23c7:
	/* 0x23c7: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_23ce:
	/* 0x23ce: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_23d1:
	/* 0x23d1: mov    eax,DWORD PTR [r13+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_23d8:
	/* 0x23d8: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23db:
	/* 0x23db: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23e0:
	/* 0x23e0: movzx  eax,WORD PTR [r13+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_23e8:
	/* 0x23e8: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_23ea:
	/* 0x23ea: je     26d0 <generic_sleepable_preload+0x26d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d0;
	}
x86_l_23f0:
	/* 0x23f0: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_23f3:
	/* 0x23f3: je     2418 <generic_sleepable_preload+0x2418> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2418;
	}
x86_l_23f5:
	/* 0x23f5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23fa:
	/* 0x23fa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23ff:
	/* 0x23ff: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2404:
	/* 0x2404: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2409:
	/* 0x2409: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_240e:
	/* 0x240e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2410:
	/* 0x2410: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2412:
	/* 0x2412: js     3e68 <generic_sleepable_preload+0x3e68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15976ULL;
	}
x86_l_2418:
	/* 0x2418: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_2421:
	/* 0x2421: je     6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25351ULL;
	}
x86_l_2427:
	/* 0x2427: mov    ecx,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_242e:
	/* 0x242e: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2433:
	/* 0x2433: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2438:
	/* 0x2438: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_2441:
	/* 0x2441: je     2466 <generic_sleepable_preload+0x2466> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2466;
	}
x86_l_2443:
	/* 0x2443: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2448:
	/* 0x2448: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_244d:
	/* 0x244d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2452:
	/* 0x2452: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2457:
	/* 0x2457: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_245c:
	/* 0x245c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_245e:
	/* 0x245e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2460:
	/* 0x2460: js     5409 <generic_sleepable_preload+0x5409> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21513ULL;
	}
x86_l_2466:
	/* 0x2466: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_246f:
	/* 0x246f: je     6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25351ULL;
	}
x86_l_2475:
	/* 0x2475: mov    ecx,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_247c:
	/* 0x247c: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2481:
	/* 0x2481: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2486:
	/* 0x2486: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_248f:
	/* 0x248f: je     24b4 <generic_sleepable_preload+0x24b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24b4;
	}
x86_l_2491:
	/* 0x2491: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2496:
	/* 0x2496: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_249b:
	/* 0x249b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_24a0:
	/* 0x24a0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24a5:
	/* 0x24a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24aa:
	/* 0x24aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24ac:
	/* 0x24ac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24ae:
	/* 0x24ae: js     60f0 <generic_sleepable_preload+0x60f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24816ULL;
	}
x86_l_24b4:
	/* 0x24b4: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_24bd:
	/* 0x24bd: je     6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25351ULL;
	}
x86_l_24c3:
	/* 0x24c3: mov    ecx,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_24ca:
	/* 0x24ca: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_24cf:
	/* 0x24cf: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24d4:
	/* 0x24d4: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_24dd:
	/* 0x24dd: je     2502 <generic_sleepable_preload+0x2502> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2502;
	}
x86_l_24df:
	/* 0x24df: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24e4:
	/* 0x24e4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_24e9:
	/* 0x24e9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_24ee:
	/* 0x24ee: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24f3:
	/* 0x24f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24f8:
	/* 0x24f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24fa:
	/* 0x24fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24fc:
	/* 0x24fc: js     6154 <generic_sleepable_preload+0x6154> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24916ULL;
	}
x86_l_2502:
	/* 0x2502: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_250b:
	/* 0x250b: je     6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25351ULL;
	}
x86_l_2511:
	/* 0x2511: mov    ecx,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2518:
	/* 0x2518: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_251d:
	/* 0x251d: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2522:
	/* 0x2522: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_252b:
	/* 0x252b: je     2550 <generic_sleepable_preload+0x2550> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2550;
	}
x86_l_252d:
	/* 0x252d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2532:
	/* 0x2532: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2537:
	/* 0x2537: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_253c:
	/* 0x253c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2541:
	/* 0x2541: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2546:
	/* 0x2546: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2548:
	/* 0x2548: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_254a:
	/* 0x254a: js     61b8 <generic_sleepable_preload+0x61b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25016ULL;
	}
x86_l_2550:
	/* 0x2550: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_2559:
	/* 0x2559: je     6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25351ULL;
	}
x86_l_255f:
	/* 0x255f: mov    ecx,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2566:
	/* 0x2566: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_256b:
	/* 0x256b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2570:
	/* 0x2570: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2579:
	/* 0x2579: je     259e <generic_sleepable_preload+0x259e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_259e;
	}
x86_l_257b:
	/* 0x257b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2580:
	/* 0x2580: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2585:
	/* 0x2585: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_258a:
	/* 0x258a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_258f:
	/* 0x258f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2594:
	/* 0x2594: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2596:
	/* 0x2596: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2598:
	/* 0x2598: js     6219 <generic_sleepable_preload+0x6219> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25113ULL;
	}
x86_l_259e:
	/* 0x259e: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_25a7:
	/* 0x25a7: je     6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25351ULL;
	}
x86_l_25ad:
	/* 0x25ad: mov    ecx,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_25b4:
	/* 0x25b4: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_25b9:
	/* 0x25b9: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25be:
	/* 0x25be: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_25c7:
	/* 0x25c7: je     25ec <generic_sleepable_preload+0x25ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ec;
	}
x86_l_25c9:
	/* 0x25c9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25ce:
	/* 0x25ce: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_25d3:
	/* 0x25d3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_25d8:
	/* 0x25d8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25dd:
	/* 0x25dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25e2:
	/* 0x25e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25e4:
	/* 0x25e4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25e6:
	/* 0x25e6: js     6300 <generic_sleepable_preload+0x6300> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25344ULL;
	}
x86_l_25ec:
	/* 0x25ec: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_25f5:
	/* 0x25f5: je     6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25351ULL;
	}
x86_l_25fb:
	/* 0x25fb: mov    ecx,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2602:
	/* 0x2602: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2607:
	/* 0x2607: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_260c:
	/* 0x260c: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2615:
	/* 0x2615: je     263a <generic_sleepable_preload+0x263a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_263a;
	}
x86_l_2617:
	/* 0x2617: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_261c:
	/* 0x261c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2621:
	/* 0x2621: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2626:
	/* 0x2626: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_262b:
	/* 0x262b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2630:
	/* 0x2630: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2632:
	/* 0x2632: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2634:
	/* 0x2634: js     68cf <generic_sleepable_preload+0x68cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26831ULL;
	}
x86_l_263a:
	/* 0x263a: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2643:
	/* 0x2643: je     6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25351ULL;
	}
x86_l_2649:
	/* 0x2649: mov    ecx,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2650:
	/* 0x2650: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2655:
	/* 0x2655: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_265a:
	/* 0x265a: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_2663:
	/* 0x2663: je     2688 <generic_sleepable_preload+0x2688> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2688;
	}
x86_l_2665:
	/* 0x2665: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_266a:
	/* 0x266a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_266f:
	/* 0x266f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2674:
	/* 0x2674: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2679:
	/* 0x2679: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_267e:
	/* 0x267e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2680:
	/* 0x2680: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2682:
	/* 0x2682: js     693c <generic_sleepable_preload+0x693c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26940ULL;
	}
x86_l_2688:
	/* 0x2688: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_268d:
	/* 0x268d: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2696:
	/* 0x2696: je     6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25351ULL;
	}
x86_l_269c:
	/* 0x269c: mov    ecx,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_26a3:
	/* 0x26a3: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_26a8:
	/* 0x26a8: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26ad:
	/* 0x26ad: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_26b6:
	/* 0x26b6: je     6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25351ULL;
	}
x86_l_26bc:
	/* 0x26bc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26c1:
	/* 0x26c1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26c6:
	/* 0x26c6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26cb:
	/* 0x26cb: jmp    29b0 <generic_sleepable_preload+0x29b0> */
	goto x86_l_29b0;
x86_l_26d0:
	/* 0x26d0: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_26d3:
	/* 0x26d3: je     26f8 <generic_sleepable_preload+0x26f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26f8;
	}
x86_l_26d5:
	/* 0x26d5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26da:
	/* 0x26da: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26df:
	/* 0x26df: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26e4:
	/* 0x26e4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26e9:
	/* 0x26e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26ee:
	/* 0x26ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f0:
	/* 0x26f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26f2:
	/* 0x26f2: js     3e68 <generic_sleepable_preload+0x3e68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15976ULL;
	}
x86_l_26f8:
	/* 0x26f8: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_2701:
	/* 0x2701: je     6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25351ULL;
	}
x86_l_2707:
	/* 0x2707: mov    ecx,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_270e:
	/* 0x270e: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2713:
	/* 0x2713: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2718:
	/* 0x2718: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_2721:
	/* 0x2721: je     2746 <generic_sleepable_preload+0x2746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2746;
	}
x86_l_2723:
	/* 0x2723: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2728:
	/* 0x2728: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_272d:
	/* 0x272d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2732:
	/* 0x2732: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2737:
	/* 0x2737: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_273c:
	/* 0x273c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_273e:
	/* 0x273e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2740:
	/* 0x2740: js     5409 <generic_sleepable_preload+0x5409> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21513ULL;
	}
x86_l_2746:
	/* 0x2746: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_274f:
	/* 0x274f: je     6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25351ULL;
	}
x86_l_2755:
	/* 0x2755: mov    ecx,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_275c:
	/* 0x275c: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2761:
	/* 0x2761: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2766:
	/* 0x2766: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_276f:
	/* 0x276f: je     2794 <generic_sleepable_preload+0x2794> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2794;
	}
x86_l_2771:
	/* 0x2771: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2776:
	/* 0x2776: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_277b:
	/* 0x277b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2780:
	/* 0x2780: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2785:
	/* 0x2785: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_278a:
	/* 0x278a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_278c:
	/* 0x278c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_278e:
	/* 0x278e: js     60f0 <generic_sleepable_preload+0x60f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24816ULL;
	}
x86_l_2794:
	/* 0x2794: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_279d:
	/* 0x279d: je     6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25351ULL;
	}
x86_l_27a3:
	/* 0x27a3: mov    ecx,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_27aa:
	/* 0x27aa: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_27af:
	/* 0x27af: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27b4:
	/* 0x27b4: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_27bd:
	/* 0x27bd: je     27e2 <generic_sleepable_preload+0x27e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e2;
	}
x86_l_27bf:
	/* 0x27bf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27c4:
	/* 0x27c4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_27c9:
	/* 0x27c9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_27ce:
	/* 0x27ce: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27d3:
	/* 0x27d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27d8:
	/* 0x27d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27da:
	/* 0x27da: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27dc:
	/* 0x27dc: js     6154 <generic_sleepable_preload+0x6154> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24916ULL;
	}
x86_l_27e2:
	/* 0x27e2: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_27eb:
	/* 0x27eb: je     6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25351ULL;
	}
x86_l_27f1:
	/* 0x27f1: mov    ecx,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_27f8:
	/* 0x27f8: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_27fd:
	/* 0x27fd: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2802:
	/* 0x2802: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_280b:
	/* 0x280b: je     2830 <generic_sleepable_preload+0x2830> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2830;
	}
x86_l_280d:
	/* 0x280d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2812:
	/* 0x2812: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2817:
	/* 0x2817: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_281c:
	/* 0x281c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x282a: js     61b8 <generic_sleepable_preload+0x61b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25016ULL;
	}
x86_l_2830:
	/* 0x2830: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_2839:
	/* 0x2839: je     6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25351ULL;
	}
x86_l_283f:
	/* 0x283f: mov    ecx,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2846:
	/* 0x2846: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_284b:
	/* 0x284b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2850:
	/* 0x2850: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2859:
	/* 0x2859: je     287e <generic_sleepable_preload+0x287e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_287e;
	}
x86_l_285b:
	/* 0x285b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2860:
	/* 0x2860: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2865:
	/* 0x2865: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_286a:
	/* 0x286a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_286f:
	/* 0x286f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2874:
	/* 0x2874: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2876:
	/* 0x2876: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2878:
	/* 0x2878: js     6219 <generic_sleepable_preload+0x6219> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25113ULL;
	}
x86_l_287e:
	/* 0x287e: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2887:
	/* 0x2887: je     6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25351ULL;
	}
x86_l_288d:
	/* 0x288d: mov    ecx,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2894:
	/* 0x2894: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2899:
	/* 0x2899: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_289e:
	/* 0x289e: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_28a7:
	/* 0x28a7: je     28cc <generic_sleepable_preload+0x28cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28cc;
	}
x86_l_28a9:
	/* 0x28a9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28ae:
	/* 0x28ae: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_28b3:
	/* 0x28b3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_28b8:
	/* 0x28b8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28bd:
	/* 0x28bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28c2:
	/* 0x28c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28c4:
	/* 0x28c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28c6:
	/* 0x28c6: js     6300 <generic_sleepable_preload+0x6300> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25344ULL;
	}
x86_l_28cc:
	/* 0x28cc: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_28d5:
	/* 0x28d5: je     6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25351ULL;
	}
x86_l_28db:
	/* 0x28db: mov    ecx,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_28e2:
	/* 0x28e2: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_28e7:
	/* 0x28e7: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28ec:
	/* 0x28ec: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_28f5:
	/* 0x28f5: je     291a <generic_sleepable_preload+0x291a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_291a;
	}
x86_l_28f7:
	/* 0x28f7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28fc:
	/* 0x28fc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2901:
	/* 0x2901: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2906:
	/* 0x2906: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_290b:
	/* 0x290b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2910:
	/* 0x2910: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2912:
	/* 0x2912: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2914:
	/* 0x2914: js     69d6 <generic_sleepable_preload+0x69d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27094ULL;
	}
x86_l_291a:
	/* 0x291a: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_291f:
	/* 0x291f: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2928:
	/* 0x2928: je     6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25351ULL;
	}
x86_l_292e:
	/* 0x292e: mov    ecx,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2935:
	/* 0x2935: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_293a:
	/* 0x293a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_293f:
	/* 0x293f: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_2948:
	/* 0x2948: je     296d <generic_sleepable_preload+0x296d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_296d;
	}
x86_l_294a:
	/* 0x294a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_294f:
	/* 0x294f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2954:
	/* 0x2954: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2959:
	/* 0x2959: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_295e:
	/* 0x295e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2963:
	/* 0x2963: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2965:
	/* 0x2965: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2967:
	/* 0x2967: js     693c <generic_sleepable_preload+0x693c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26940ULL;
	}
x86_l_296d:
	/* 0x296d: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2972:
	/* 0x2972: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_297b:
	/* 0x297b: je     6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25351ULL;
	}
x86_l_2981:
	/* 0x2981: mov    ecx,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2988:
	/* 0x2988: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_298d:
	/* 0x298d: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2992:
	/* 0x2992: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_299b:
	/* 0x299b: je     6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25351ULL;
	}
x86_l_29a1:
	/* 0x29a1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29a6:
	/* 0x29a6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_29ab:
	/* 0x29ab: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_29b0:
	/* 0x29b0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29b5:
	/* 0x29b5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29ba:
	/* 0x29ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29bc:
	/* 0x29bc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29be:
	/* 0x29be: jns    6307 <generic_sleepable_preload+0x6307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25351ULL;
	}
x86_l_29c4:
	/* 0x29c4: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_29c9:
	/* 0x29c9: jmp    6305 <generic_sleepable_preload+0x6305> */
	return 25349ULL;
x86_l_29ce:
	/* 0x29ce: mov    edx,DWORD PTR [r13+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_29d5:
	/* 0x29d5: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29db:
	/* 0x29db: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29de:
	/* 0x29de: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29e3:
	/* 0x29e3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_29e8:
	/* 0x29e8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29ed:
	/* 0x29ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29f2:
	/* 0x29f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29f4:
	/* 0x29f4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29f6:
	/* 0x29f6: jne    2a80 <generic_sleepable_preload+0x2a80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a80;
	}
x86_l_29fc:
	/* 0x29fc: mov    edx,DWORD PTR [r13+0x23c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_2a03:
	/* 0x2a03: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a09:
	/* 0x2a09: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a0c:
	/* 0x2a0c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a11:
	/* 0x2a11: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a16:
	/* 0x2a16: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a1b:
	/* 0x2a1b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a20:
	/* 0x2a20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a22:
	/* 0x2a22: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a24:
	/* 0x2a24: jne    2a80 <generic_sleepable_preload+0x2a80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a80;
	}
x86_l_2a26:
	/* 0x2a26: movzx  eax,BYTE PTR [r13+0x243] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 579ULL);
x86_l_2a2e:
	/* 0x2a2e: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_2a35:
	/* 0x2a35: mov    rcx,QWORD PTR [r13+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_2a3c:
	/* 0x2a3c: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2a41:
	/* 0x2a41: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a44:
	/* 0x2a44: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a49:
	/* 0x2a49: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a4e:
	/* 0x2a4e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a53:
	/* 0x2a53: movzx  ecx,BYTE PTR [r13+0x243] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 579ULL);
x86_l_2a5b:
	/* 0x2a5b: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_2a62:
	/* 0x2a62: mov    rdx,QWORD PTR [r13+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_2a69:
	/* 0x2a69: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2a6e:
	/* 0x2a6e: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a71:
	/* 0x2a71: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a76:
	/* 0x2a76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a78:
	/* 0x2a78: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a7a:
	/* 0x2a7a: je     1bec <generic_sleepable_preload+0x1bec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7148ULL;
	}
x86_l_2a80:
	/* 0x2a80: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_2a83:
	/* 0x2a83: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a88:
	/* 0x2a88: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a8a:
	/* 0x2a8a: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_2a8d:
	/* 0x2a8d: cmp    WORD PTR [r13+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_2a96:
	/* 0x2a96: je     6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25492ULL;
	}
x86_l_2a9c:
	/* 0x2a9c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_2aa3:
	/* 0x2aa3: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2aa6:
	/* 0x2aa6: mov    eax,DWORD PTR [r13+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2aad:
	/* 0x2aad: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ab0:
	/* 0x2ab0: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ab5:
	/* 0x2ab5: movzx  eax,WORD PTR [r13+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_2abd:
	/* 0x2abd: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_2abf:
	/* 0x2abf: je     2daa <generic_sleepable_preload+0x2daa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11690ULL;
	}
x86_l_2ac5:
	/* 0x2ac5: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2ac8:
	/* 0x2ac8: je     2aed <generic_sleepable_preload+0x2aed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aed;
	}
x86_l_2aca:
	/* 0x2aca: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2acf:
	/* 0x2acf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ad4:
	/* 0x2ad4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ad9:
	/* 0x2ad9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ade:
	/* 0x2ade: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ae3:
	/* 0x2ae3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae5:
	/* 0x2ae5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ae7:
	/* 0x2ae7: js     3e72 <generic_sleepable_preload+0x3e72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15986ULL;
	}
x86_l_2aed:
	/* 0x2aed: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_2af6:
	/* 0x2af6: je     6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25492ULL;
	}
x86_l_2afc:
	/* 0x2afc: mov    ecx,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2b03:
	/* 0x2b03: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2b08:
	/* 0x2b08: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b0d:
	/* 0x2b0d: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_2b16:
	/* 0x2b16: je     2b3b <generic_sleepable_preload+0x2b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b3b;
	}
x86_l_2b18:
	/* 0x2b18: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b1d:
	/* 0x2b1d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b22:
	/* 0x2b22: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b27:
	/* 0x2b27: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b2c:
	/* 0x2b2c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b31:
	/* 0x2b31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b33:
	/* 0x2b33: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b35:
	/* 0x2b35: js     5413 <generic_sleepable_preload+0x5413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21523ULL;
	}
x86_l_2b3b:
	/* 0x2b3b: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_2b44:
	/* 0x2b44: je     6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25492ULL;
	}
x86_l_2b4a:
	/* 0x2b4a: mov    ecx,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2b51:
	/* 0x2b51: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2b56:
	/* 0x2b56: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b5b:
	/* 0x2b5b: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_2b64:
	/* 0x2b64: je     2b89 <generic_sleepable_preload+0x2b89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11145ULL;
	}
x86_l_2b66:
	/* 0x2b66: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b6b:
	/* 0x2b6b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
	return 11120ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11120ULL: goto x86_l_2b70;
	case 11125ULL: goto x86_l_2b75;
	case 11130ULL: goto x86_l_2b7a;
	case 11135ULL: goto x86_l_2b7f;
	case 11137ULL: goto x86_l_2b81;
	case 11139ULL: goto x86_l_2b83;
	case 11145ULL: goto x86_l_2b89;
	case 11154ULL: goto x86_l_2b92;
	case 11160ULL: goto x86_l_2b98;
	case 11167ULL: goto x86_l_2b9f;
	case 11172ULL: goto x86_l_2ba4;
	case 11177ULL: goto x86_l_2ba9;
	case 11186ULL: goto x86_l_2bb2;
	case 11188ULL: goto x86_l_2bb4;
	case 11193ULL: goto x86_l_2bb9;
	case 11198ULL: goto x86_l_2bbe;
	case 11203ULL: goto x86_l_2bc3;
	case 11208ULL: goto x86_l_2bc8;
	case 11213ULL: goto x86_l_2bcd;
	case 11215ULL: goto x86_l_2bcf;
	case 11217ULL: goto x86_l_2bd1;
	case 11223ULL: goto x86_l_2bd7;
	case 11232ULL: goto x86_l_2be0;
	case 11238ULL: goto x86_l_2be6;
	case 11245ULL: goto x86_l_2bed;
	case 11250ULL: goto x86_l_2bf2;
	case 11255ULL: goto x86_l_2bf7;
	case 11264ULL: goto x86_l_2c00;
	case 11266ULL: goto x86_l_2c02;
	case 11271ULL: goto x86_l_2c07;
	case 11276ULL: goto x86_l_2c0c;
	case 11281ULL: goto x86_l_2c11;
	case 11286ULL: goto x86_l_2c16;
	case 11291ULL: goto x86_l_2c1b;
	case 11293ULL: goto x86_l_2c1d;
	case 11295ULL: goto x86_l_2c1f;
	case 11301ULL: goto x86_l_2c25;
	case 11310ULL: goto x86_l_2c2e;
	case 11316ULL: goto x86_l_2c34;
	case 11323ULL: goto x86_l_2c3b;
	case 11328ULL: goto x86_l_2c40;
	case 11333ULL: goto x86_l_2c45;
	case 11342ULL: goto x86_l_2c4e;
	case 11344ULL: goto x86_l_2c50;
	case 11349ULL: goto x86_l_2c55;
	case 11354ULL: goto x86_l_2c5a;
	case 11359ULL: goto x86_l_2c5f;
	case 11364ULL: goto x86_l_2c64;
	case 11369ULL: goto x86_l_2c69;
	case 11371ULL: goto x86_l_2c6b;
	case 11373ULL: goto x86_l_2c6d;
	case 11379ULL: goto x86_l_2c73;
	case 11388ULL: goto x86_l_2c7c;
	case 11394ULL: goto x86_l_2c82;
	case 11401ULL: goto x86_l_2c89;
	case 11406ULL: goto x86_l_2c8e;
	case 11411ULL: goto x86_l_2c93;
	case 11420ULL: goto x86_l_2c9c;
	case 11422ULL: goto x86_l_2c9e;
	case 11427ULL: goto x86_l_2ca3;
	case 11432ULL: goto x86_l_2ca8;
	case 11437ULL: goto x86_l_2cad;
	case 11442ULL: goto x86_l_2cb2;
	case 11447ULL: goto x86_l_2cb7;
	case 11449ULL: goto x86_l_2cb9;
	case 11451ULL: goto x86_l_2cbb;
	case 11457ULL: goto x86_l_2cc1;
	case 11466ULL: goto x86_l_2cca;
	case 11472ULL: goto x86_l_2cd0;
	case 11479ULL: goto x86_l_2cd7;
	case 11484ULL: goto x86_l_2cdc;
	case 11489ULL: goto x86_l_2ce1;
	case 11498ULL: goto x86_l_2cea;
	case 11500ULL: goto x86_l_2cec;
	case 11505ULL: goto x86_l_2cf1;
	case 11510ULL: goto x86_l_2cf6;
	case 11515ULL: goto x86_l_2cfb;
	case 11520ULL: goto x86_l_2d00;
	case 11525ULL: goto x86_l_2d05;
	case 11527ULL: goto x86_l_2d07;
	case 11529ULL: goto x86_l_2d09;
	case 11535ULL: goto x86_l_2d0f;
	case 11544ULL: goto x86_l_2d18;
	case 11550ULL: goto x86_l_2d1e;
	case 11557ULL: goto x86_l_2d25;
	case 11562ULL: goto x86_l_2d2a;
	case 11567ULL: goto x86_l_2d2f;
	case 11576ULL: goto x86_l_2d38;
	case 11578ULL: goto x86_l_2d3a;
	case 11583ULL: goto x86_l_2d3f;
	case 11588ULL: goto x86_l_2d44;
	case 11593ULL: goto x86_l_2d49;
	case 11598ULL: goto x86_l_2d4e;
	case 11603ULL: goto x86_l_2d53;
	case 11605ULL: goto x86_l_2d55;
	case 11607ULL: goto x86_l_2d57;
	case 11613ULL: goto x86_l_2d5d;
	case 11618ULL: goto x86_l_2d62;
	case 11627ULL: goto x86_l_2d6b;
	case 11632ULL: goto x86_l_2d70;
	case 11638ULL: goto x86_l_2d76;
	case 11645ULL: goto x86_l_2d7d;
	case 11650ULL: goto x86_l_2d82;
	case 11655ULL: goto x86_l_2d87;
	case 11664ULL: goto x86_l_2d90;
	case 11670ULL: goto x86_l_2d96;
	case 11675ULL: goto x86_l_2d9b;
	case 11680ULL: goto x86_l_2da0;
	case 11685ULL: goto x86_l_2da5;
	case 11690ULL: goto x86_l_2daa;
	case 11693ULL: goto x86_l_2dad;
	case 11695ULL: goto x86_l_2daf;
	case 11700ULL: goto x86_l_2db4;
	case 11705ULL: goto x86_l_2db9;
	case 11710ULL: goto x86_l_2dbe;
	case 11715ULL: goto x86_l_2dc3;
	case 11720ULL: goto x86_l_2dc8;
	case 11722ULL: goto x86_l_2dca;
	case 11724ULL: goto x86_l_2dcc;
	case 11730ULL: goto x86_l_2dd2;
	case 11739ULL: goto x86_l_2ddb;
	case 11745ULL: goto x86_l_2de1;
	case 11752ULL: goto x86_l_2de8;
	case 11757ULL: goto x86_l_2ded;
	case 11762ULL: goto x86_l_2df2;
	case 11771ULL: goto x86_l_2dfb;
	case 11773ULL: goto x86_l_2dfd;
	case 11778ULL: goto x86_l_2e02;
	case 11783ULL: goto x86_l_2e07;
	case 11788ULL: goto x86_l_2e0c;
	case 11793ULL: goto x86_l_2e11;
	case 11798ULL: goto x86_l_2e16;
	case 11800ULL: goto x86_l_2e18;
	case 11802ULL: goto x86_l_2e1a;
	case 11808ULL: goto x86_l_2e20;
	case 11817ULL: goto x86_l_2e29;
	case 11823ULL: goto x86_l_2e2f;
	case 11830ULL: goto x86_l_2e36;
	case 11835ULL: goto x86_l_2e3b;
	case 11840ULL: goto x86_l_2e40;
	case 11849ULL: goto x86_l_2e49;
	case 11851ULL: goto x86_l_2e4b;
	case 11856ULL: goto x86_l_2e50;
	case 11861ULL: goto x86_l_2e55;
	case 11866ULL: goto x86_l_2e5a;
	case 11871ULL: goto x86_l_2e5f;
	case 11876ULL: goto x86_l_2e64;
	case 11878ULL: goto x86_l_2e66;
	case 11880ULL: goto x86_l_2e68;
	case 11886ULL: goto x86_l_2e6e;
	case 11895ULL: goto x86_l_2e77;
	case 11901ULL: goto x86_l_2e7d;
	case 11908ULL: goto x86_l_2e84;
	case 11913ULL: goto x86_l_2e89;
	case 11918ULL: goto x86_l_2e8e;
	case 11927ULL: goto x86_l_2e97;
	case 11929ULL: goto x86_l_2e99;
	case 11934ULL: goto x86_l_2e9e;
	case 11939ULL: goto x86_l_2ea3;
	case 11944ULL: goto x86_l_2ea8;
	case 11949ULL: goto x86_l_2ead;
	case 11954ULL: goto x86_l_2eb2;
	case 11956ULL: goto x86_l_2eb4;
	case 11958ULL: goto x86_l_2eb6;
	case 11964ULL: goto x86_l_2ebc;
	case 11973ULL: goto x86_l_2ec5;
	case 11979ULL: goto x86_l_2ecb;
	case 11986ULL: goto x86_l_2ed2;
	case 11991ULL: goto x86_l_2ed7;
	case 11996ULL: goto x86_l_2edc;
	case 12005ULL: goto x86_l_2ee5;
	case 12007ULL: goto x86_l_2ee7;
	case 12012ULL: goto x86_l_2eec;
	case 12017ULL: goto x86_l_2ef1;
	case 12022ULL: goto x86_l_2ef6;
	case 12027ULL: goto x86_l_2efb;
	case 12032ULL: goto x86_l_2f00;
	case 12034ULL: goto x86_l_2f02;
	case 12036ULL: goto x86_l_2f04;
	case 12042ULL: goto x86_l_2f0a;
	case 12051ULL: goto x86_l_2f13;
	case 12057ULL: goto x86_l_2f19;
	case 12064ULL: goto x86_l_2f20;
	case 12069ULL: goto x86_l_2f25;
	case 12074ULL: goto x86_l_2f2a;
	case 12083ULL: goto x86_l_2f33;
	case 12085ULL: goto x86_l_2f35;
	case 12090ULL: goto x86_l_2f3a;
	case 12095ULL: goto x86_l_2f3f;
	case 12100ULL: goto x86_l_2f44;
	case 12105ULL: goto x86_l_2f49;
	case 12110ULL: goto x86_l_2f4e;
	case 12112ULL: goto x86_l_2f50;
	case 12114ULL: goto x86_l_2f52;
	case 12120ULL: goto x86_l_2f58;
	case 12129ULL: goto x86_l_2f61;
	case 12135ULL: goto x86_l_2f67;
	case 12142ULL: goto x86_l_2f6e;
	case 12147ULL: goto x86_l_2f73;
	case 12152ULL: goto x86_l_2f78;
	case 12161ULL: goto x86_l_2f81;
	case 12163ULL: goto x86_l_2f83;
	case 12168ULL: goto x86_l_2f88;
	case 12173ULL: goto x86_l_2f8d;
	case 12178ULL: goto x86_l_2f92;
	case 12183ULL: goto x86_l_2f97;
	case 12188ULL: goto x86_l_2f9c;
	case 12190ULL: goto x86_l_2f9e;
	case 12192ULL: goto x86_l_2fa0;
	case 12198ULL: goto x86_l_2fa6;
	case 12207ULL: goto x86_l_2faf;
	case 12213ULL: goto x86_l_2fb5;
	case 12220ULL: goto x86_l_2fbc;
	case 12225ULL: goto x86_l_2fc1;
	case 12230ULL: goto x86_l_2fc6;
	case 12239ULL: goto x86_l_2fcf;
	case 12241ULL: goto x86_l_2fd1;
	case 12246ULL: goto x86_l_2fd6;
	case 12251ULL: goto x86_l_2fdb;
	case 12256ULL: goto x86_l_2fe0;
	case 12261ULL: goto x86_l_2fe5;
	case 12266ULL: goto x86_l_2fea;
	case 12268ULL: goto x86_l_2fec;
	case 12270ULL: goto x86_l_2fee;
	case 12276ULL: goto x86_l_2ff4;
	case 12281ULL: goto x86_l_2ff9;
	case 12290ULL: goto x86_l_3002;
	case 12295ULL: goto x86_l_3007;
	case 12301ULL: goto x86_l_300d;
	case 12308ULL: goto x86_l_3014;
	case 12313ULL: goto x86_l_3019;
	case 12318ULL: goto x86_l_301e;
	case 12327ULL: goto x86_l_3027;
	case 12329ULL: goto x86_l_3029;
	case 12334ULL: goto x86_l_302e;
	case 12339ULL: goto x86_l_3033;
	case 12344ULL: goto x86_l_3038;
	case 12349ULL: goto x86_l_303d;
	case 12354ULL: goto x86_l_3042;
	case 12356ULL: goto x86_l_3044;
	case 12358ULL: goto x86_l_3046;
	case 12364ULL: goto x86_l_304c;
	case 12369ULL: goto x86_l_3051;
	case 12378ULL: goto x86_l_305a;
	case 12383ULL: goto x86_l_305f;
	case 12389ULL: goto x86_l_3065;
	case 12396ULL: goto x86_l_306c;
	case 12401ULL: goto x86_l_3071;
	case 12406ULL: goto x86_l_3076;
	case 12415ULL: goto x86_l_307f;
	case 12421ULL: goto x86_l_3085;
	case 12426ULL: goto x86_l_308a;
	case 12431ULL: goto x86_l_308f;
	case 12436ULL: goto x86_l_3094;
	case 12441ULL: goto x86_l_3099;
	case 12446ULL: goto x86_l_309e;
	case 12448ULL: goto x86_l_30a0;
	case 12450ULL: goto x86_l_30a2;
	case 12456ULL: goto x86_l_30a8;
	case 12461ULL: goto x86_l_30ad;
	case 12466ULL: goto x86_l_30b2;
	case 12473ULL: goto x86_l_30b9;
	case 12479ULL: goto x86_l_30bf;
	case 12482ULL: goto x86_l_30c2;
	case 12487ULL: goto x86_l_30c7;
	case 12492ULL: goto x86_l_30cc;
	case 12497ULL: goto x86_l_30d1;
	case 12502ULL: goto x86_l_30d6;
	case 12504ULL: goto x86_l_30d8;
	case 12506ULL: goto x86_l_30da;
	case 12512ULL: goto x86_l_30e0;
	case 12519ULL: goto x86_l_30e7;
	case 12525ULL: goto x86_l_30ed;
	case 12528ULL: goto x86_l_30f0;
	case 12533ULL: goto x86_l_30f5;
	case 12538ULL: goto x86_l_30fa;
	case 12543ULL: goto x86_l_30ff;
	case 12548ULL: goto x86_l_3104;
	case 12550ULL: goto x86_l_3106;
	case 12552ULL: goto x86_l_3108;
	case 12554ULL: goto x86_l_310a;
	case 12562ULL: goto x86_l_3112;
	case 12569ULL: goto x86_l_3119;
	case 12576ULL: goto x86_l_3120;
	case 12581ULL: goto x86_l_3125;
	case 12584ULL: goto x86_l_3128;
	case 12589ULL: goto x86_l_312d;
	case 12594ULL: goto x86_l_3132;
	case 12599ULL: goto x86_l_3137;
	case 12607ULL: goto x86_l_313f;
	case 12614ULL: goto x86_l_3146;
	case 12621ULL: goto x86_l_314d;
	case 12626ULL: goto x86_l_3152;
	case 12629ULL: goto x86_l_3155;
	case 12634ULL: goto x86_l_315a;
	case 12636ULL: goto x86_l_315c;
	case 12638ULL: goto x86_l_315e;
	case 12644ULL: goto x86_l_3164;
	case 12647ULL: goto x86_l_3167;
	case 12652ULL: goto x86_l_316c;
	case 12654ULL: goto x86_l_316e;
	case 12657ULL: goto x86_l_3171;
	case 12666ULL: goto x86_l_317a;
	case 12672ULL: goto x86_l_3180;
	case 12679ULL: goto x86_l_3187;
	case 12682ULL: goto x86_l_318a;
	case 12689ULL: goto x86_l_3191;
	case 12692ULL: goto x86_l_3194;
	case 12697ULL: goto x86_l_3199;
	case 12705ULL: goto x86_l_31a1;
	case 12707ULL: goto x86_l_31a3;
	case 12713ULL: goto x86_l_31a9;
	case 12716ULL: goto x86_l_31ac;
	case 12718ULL: goto x86_l_31ae;
	case 12723ULL: goto x86_l_31b3;
	case 12728ULL: goto x86_l_31b8;
	case 12733ULL: goto x86_l_31bd;
	case 12738ULL: goto x86_l_31c2;
	case 12743ULL: goto x86_l_31c7;
	case 12745ULL: goto x86_l_31c9;
	case 12747ULL: goto x86_l_31cb;
	case 12753ULL: goto x86_l_31d1;
	case 12762ULL: goto x86_l_31da;
	case 12768ULL: goto x86_l_31e0;
	case 12775ULL: goto x86_l_31e7;
	case 12780ULL: goto x86_l_31ec;
	case 12785ULL: goto x86_l_31f1;
	case 12794ULL: goto x86_l_31fa;
	case 12796ULL: goto x86_l_31fc;
	case 12801ULL: goto x86_l_3201;
	case 12806ULL: goto x86_l_3206;
	case 12811ULL: goto x86_l_320b;
	case 12816ULL: goto x86_l_3210;
	case 12821ULL: goto x86_l_3215;
	case 12823ULL: goto x86_l_3217;
	case 12825ULL: goto x86_l_3219;
	case 12831ULL: goto x86_l_321f;
	case 12840ULL: goto x86_l_3228;
	case 12846ULL: goto x86_l_322e;
	case 12853ULL: goto x86_l_3235;
	case 12858ULL: goto x86_l_323a;
	case 12863ULL: goto x86_l_323f;
	case 12872ULL: goto x86_l_3248;
	case 12874ULL: goto x86_l_324a;
	case 12879ULL: goto x86_l_324f;
	case 12884ULL: goto x86_l_3254;
	case 12889ULL: goto x86_l_3259;
	case 12894ULL: goto x86_l_325e;
	case 12899ULL: goto x86_l_3263;
	case 12901ULL: goto x86_l_3265;
	case 12903ULL: goto x86_l_3267;
	case 12909ULL: goto x86_l_326d;
	case 12918ULL: goto x86_l_3276;
	case 12924ULL: goto x86_l_327c;
	case 12931ULL: goto x86_l_3283;
	case 12936ULL: goto x86_l_3288;
	case 12941ULL: goto x86_l_328d;
	case 12950ULL: goto x86_l_3296;
	case 12952ULL: goto x86_l_3298;
	case 12957ULL: goto x86_l_329d;
	case 12962ULL: goto x86_l_32a2;
	case 12967ULL: goto x86_l_32a7;
	case 12972ULL: goto x86_l_32ac;
	case 12977ULL: goto x86_l_32b1;
	case 12979ULL: goto x86_l_32b3;
	case 12981ULL: goto x86_l_32b5;
	case 12987ULL: goto x86_l_32bb;
	case 12996ULL: goto x86_l_32c4;
	case 13002ULL: goto x86_l_32ca;
	case 13009ULL: goto x86_l_32d1;
	case 13014ULL: goto x86_l_32d6;
	case 13019ULL: goto x86_l_32db;
	case 13028ULL: goto x86_l_32e4;
	case 13030ULL: goto x86_l_32e6;
	case 13035ULL: goto x86_l_32eb;
	case 13040ULL: goto x86_l_32f0;
	case 13045ULL: goto x86_l_32f5;
	case 13050ULL: goto x86_l_32fa;
	case 13055ULL: goto x86_l_32ff;
	case 13057ULL: goto x86_l_3301;
	case 13059ULL: goto x86_l_3303;
	case 13065ULL: goto x86_l_3309;
	case 13074ULL: goto x86_l_3312;
	case 13080ULL: goto x86_l_3318;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2b70:
	/* 0x2b70: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b75:
	/* 0x2b75: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b7a:
	/* 0x2b7a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b7f:
	/* 0x2b7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b81:
	/* 0x2b81: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b83:
	/* 0x2b83: js     60fa <generic_sleepable_preload+0x60fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24826ULL;
	}
x86_l_2b89:
	/* 0x2b89: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_2b92:
	/* 0x2b92: je     6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25492ULL;
	}
x86_l_2b98:
	/* 0x2b98: mov    ecx,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_2b9f:
	/* 0x2b9f: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2ba4:
	/* 0x2ba4: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ba9:
	/* 0x2ba9: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_2bb2:
	/* 0x2bb2: je     2bd7 <generic_sleepable_preload+0x2bd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bd7;
	}
x86_l_2bb4:
	/* 0x2bb4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bb9:
	/* 0x2bb9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2bbe:
	/* 0x2bbe: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2bc3:
	/* 0x2bc3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x2bd1: js     615e <generic_sleepable_preload+0x615e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24926ULL;
	}
x86_l_2bd7:
	/* 0x2bd7: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_2be0:
	/* 0x2be0: je     6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25492ULL;
	}
x86_l_2be6:
	/* 0x2be6: mov    ecx,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_2bed:
	/* 0x2bed: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2bf2:
	/* 0x2bf2: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bf7:
	/* 0x2bf7: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_2c00:
	/* 0x2c00: je     2c25 <generic_sleepable_preload+0x2c25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c25;
	}
x86_l_2c02:
	/* 0x2c02: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c07:
	/* 0x2c07: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2c0c:
	/* 0x2c0c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c11:
	/* 0x2c11: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c16:
	/* 0x2c16: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c1b:
	/* 0x2c1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c1d:
	/* 0x2c1d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c1f:
	/* 0x2c1f: js     61c2 <generic_sleepable_preload+0x61c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25026ULL;
	}
x86_l_2c25:
	/* 0x2c25: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_2c2e:
	/* 0x2c2e: je     6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25492ULL;
	}
x86_l_2c34:
	/* 0x2c34: mov    ecx,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_2c3b:
	/* 0x2c3b: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2c40:
	/* 0x2c40: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c45:
	/* 0x2c45: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_2c4e:
	/* 0x2c4e: je     2c73 <generic_sleepable_preload+0x2c73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c73;
	}
x86_l_2c50:
	/* 0x2c50: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c55:
	/* 0x2c55: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2c5a:
	/* 0x2c5a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c5f:
	/* 0x2c5f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c64:
	/* 0x2c64: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c69:
	/* 0x2c69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c6b:
	/* 0x2c6b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c6d:
	/* 0x2c6d: js     6223 <generic_sleepable_preload+0x6223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25123ULL;
	}
x86_l_2c73:
	/* 0x2c73: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_2c7c:
	/* 0x2c7c: je     6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25492ULL;
	}
x86_l_2c82:
	/* 0x2c82: mov    ecx,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_2c89:
	/* 0x2c89: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2c8e:
	/* 0x2c8e: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c93:
	/* 0x2c93: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_2c9c:
	/* 0x2c9c: je     2cc1 <generic_sleepable_preload+0x2cc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cc1;
	}
x86_l_2c9e:
	/* 0x2c9e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ca3:
	/* 0x2ca3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ca8:
	/* 0x2ca8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2cad:
	/* 0x2cad: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cb2:
	/* 0x2cb2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cb7:
	/* 0x2cb7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cb9:
	/* 0x2cb9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2cbb:
	/* 0x2cbb: js     638d <generic_sleepable_preload+0x638d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25485ULL;
	}
x86_l_2cc1:
	/* 0x2cc1: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_2cca:
	/* 0x2cca: je     6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25492ULL;
	}
x86_l_2cd0:
	/* 0x2cd0: mov    ecx,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_2cd7:
	/* 0x2cd7: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2cdc:
	/* 0x2cdc: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ce1:
	/* 0x2ce1: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_2cea:
	/* 0x2cea: je     2d0f <generic_sleepable_preload+0x2d0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d0f;
	}
x86_l_2cec:
	/* 0x2cec: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cf1:
	/* 0x2cf1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2cf6:
	/* 0x2cf6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2cfb:
	/* 0x2cfb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d00:
	/* 0x2d00: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d05:
	/* 0x2d05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d07:
	/* 0x2d07: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d09:
	/* 0x2d09: js     68db <generic_sleepable_preload+0x68db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26843ULL;
	}
x86_l_2d0f:
	/* 0x2d0f: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_2d18:
	/* 0x2d18: je     6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25492ULL;
	}
x86_l_2d1e:
	/* 0x2d1e: mov    ecx,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_2d25:
	/* 0x2d25: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2d2a:
	/* 0x2d2a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d2f:
	/* 0x2d2f: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_2d38:
	/* 0x2d38: je     2d5d <generic_sleepable_preload+0x2d5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d5d;
	}
x86_l_2d3a:
	/* 0x2d3a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d3f:
	/* 0x2d3f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d44:
	/* 0x2d44: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d49:
	/* 0x2d49: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d4e:
	/* 0x2d4e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d53:
	/* 0x2d53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d55:
	/* 0x2d55: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d57:
	/* 0x2d57: js     694d <generic_sleepable_preload+0x694d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26957ULL;
	}
x86_l_2d5d:
	/* 0x2d5d: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d62:
	/* 0x2d62: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_2d6b:
	/* 0x2d6b: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d70:
	/* 0x2d70: je     6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25492ULL;
	}
x86_l_2d76:
	/* 0x2d76: mov    ecx,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_2d7d:
	/* 0x2d7d: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2d82:
	/* 0x2d82: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d87:
	/* 0x2d87: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_2d90:
	/* 0x2d90: je     6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25492ULL;
	}
x86_l_2d96:
	/* 0x2d96: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d9b:
	/* 0x2d9b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2da0:
	/* 0x2da0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2da5:
	/* 0x2da5: jmp    3094 <generic_sleepable_preload+0x3094> */
	goto x86_l_3094;
x86_l_2daa:
	/* 0x2daa: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2dad:
	/* 0x2dad: je     2dd2 <generic_sleepable_preload+0x2dd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dd2;
	}
x86_l_2daf:
	/* 0x2daf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2db4:
	/* 0x2db4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2db9:
	/* 0x2db9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2dbe:
	/* 0x2dbe: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dc3:
	/* 0x2dc3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dc8:
	/* 0x2dc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dca:
	/* 0x2dca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2dcc:
	/* 0x2dcc: js     3e72 <generic_sleepable_preload+0x3e72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15986ULL;
	}
x86_l_2dd2:
	/* 0x2dd2: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_2ddb:
	/* 0x2ddb: je     6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25492ULL;
	}
x86_l_2de1:
	/* 0x2de1: mov    ecx,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2de8:
	/* 0x2de8: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2ded:
	/* 0x2ded: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2df2:
	/* 0x2df2: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_2dfb:
	/* 0x2dfb: je     2e20 <generic_sleepable_preload+0x2e20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e20;
	}
x86_l_2dfd:
	/* 0x2dfd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e02:
	/* 0x2e02: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e07:
	/* 0x2e07: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2e0c:
	/* 0x2e0c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e11:
	/* 0x2e11: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e16:
	/* 0x2e16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e18:
	/* 0x2e18: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e1a:
	/* 0x2e1a: js     5413 <generic_sleepable_preload+0x5413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21523ULL;
	}
x86_l_2e20:
	/* 0x2e20: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_2e29:
	/* 0x2e29: je     6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25492ULL;
	}
x86_l_2e2f:
	/* 0x2e2f: mov    ecx,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2e36:
	/* 0x2e36: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2e3b:
	/* 0x2e3b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e40:
	/* 0x2e40: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_2e49:
	/* 0x2e49: je     2e6e <generic_sleepable_preload+0x2e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e6e;
	}
x86_l_2e4b:
	/* 0x2e4b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e50:
	/* 0x2e50: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e55:
	/* 0x2e55: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2e5a:
	/* 0x2e5a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e5f:
	/* 0x2e5f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e64:
	/* 0x2e64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e66:
	/* 0x2e66: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e68:
	/* 0x2e68: js     60fa <generic_sleepable_preload+0x60fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24826ULL;
	}
x86_l_2e6e:
	/* 0x2e6e: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_2e77:
	/* 0x2e77: je     6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25492ULL;
	}
x86_l_2e7d:
	/* 0x2e7d: mov    ecx,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_2e84:
	/* 0x2e84: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2e89:
	/* 0x2e89: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e8e:
	/* 0x2e8e: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_2e97:
	/* 0x2e97: je     2ebc <generic_sleepable_preload+0x2ebc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ebc;
	}
x86_l_2e99:
	/* 0x2e99: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e9e:
	/* 0x2e9e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ea3:
	/* 0x2ea3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ea8:
	/* 0x2ea8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ead:
	/* 0x2ead: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2eb2:
	/* 0x2eb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eb4:
	/* 0x2eb4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2eb6:
	/* 0x2eb6: js     615e <generic_sleepable_preload+0x615e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24926ULL;
	}
x86_l_2ebc:
	/* 0x2ebc: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_2ec5:
	/* 0x2ec5: je     6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25492ULL;
	}
x86_l_2ecb:
	/* 0x2ecb: mov    ecx,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_2ed2:
	/* 0x2ed2: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2ed7:
	/* 0x2ed7: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2edc:
	/* 0x2edc: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_2ee5:
	/* 0x2ee5: je     2f0a <generic_sleepable_preload+0x2f0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f0a;
	}
x86_l_2ee7:
	/* 0x2ee7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eec:
	/* 0x2eec: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ef1:
	/* 0x2ef1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ef6:
	/* 0x2ef6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2efb:
	/* 0x2efb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f00:
	/* 0x2f00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f02:
	/* 0x2f02: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f04:
	/* 0x2f04: js     61c2 <generic_sleepable_preload+0x61c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25026ULL;
	}
x86_l_2f0a:
	/* 0x2f0a: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_2f13:
	/* 0x2f13: je     6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25492ULL;
	}
x86_l_2f19:
	/* 0x2f19: mov    ecx,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_2f20:
	/* 0x2f20: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2f25:
	/* 0x2f25: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f2a:
	/* 0x2f2a: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_2f33:
	/* 0x2f33: je     2f58 <generic_sleepable_preload+0x2f58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f58;
	}
x86_l_2f35:
	/* 0x2f35: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f3a:
	/* 0x2f3a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f3f:
	/* 0x2f3f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2f44:
	/* 0x2f44: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f49:
	/* 0x2f49: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f4e:
	/* 0x2f4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f50:
	/* 0x2f50: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f52:
	/* 0x2f52: js     6223 <generic_sleepable_preload+0x6223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25123ULL;
	}
x86_l_2f58:
	/* 0x2f58: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_2f61:
	/* 0x2f61: je     6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25492ULL;
	}
x86_l_2f67:
	/* 0x2f67: mov    ecx,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_2f6e:
	/* 0x2f6e: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2f73:
	/* 0x2f73: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f78:
	/* 0x2f78: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_2f81:
	/* 0x2f81: je     2fa6 <generic_sleepable_preload+0x2fa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fa6;
	}
x86_l_2f83:
	/* 0x2f83: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f88:
	/* 0x2f88: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f8d:
	/* 0x2f8d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2f92:
	/* 0x2f92: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f97:
	/* 0x2f97: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f9c:
	/* 0x2f9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f9e:
	/* 0x2f9e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fa0:
	/* 0x2fa0: js     638d <generic_sleepable_preload+0x638d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25485ULL;
	}
x86_l_2fa6:
	/* 0x2fa6: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_2faf:
	/* 0x2faf: je     6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25492ULL;
	}
x86_l_2fb5:
	/* 0x2fb5: mov    ecx,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_2fbc:
	/* 0x2fbc: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2fc1:
	/* 0x2fc1: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fc6:
	/* 0x2fc6: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_2fcf:
	/* 0x2fcf: je     2ff4 <generic_sleepable_preload+0x2ff4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ff4;
	}
x86_l_2fd1:
	/* 0x2fd1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fd6:
	/* 0x2fd6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2fdb:
	/* 0x2fdb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2fe0:
	/* 0x2fe0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fe5:
	/* 0x2fe5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fea:
	/* 0x2fea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fec:
	/* 0x2fec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fee:
	/* 0x2fee: js     69e7 <generic_sleepable_preload+0x69e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27111ULL;
	}
x86_l_2ff4:
	/* 0x2ff4: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ff9:
	/* 0x2ff9: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_3002:
	/* 0x3002: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3007:
	/* 0x3007: je     6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25492ULL;
	}
x86_l_300d:
	/* 0x300d: mov    ecx,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3014:
	/* 0x3014: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3019:
	/* 0x3019: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_301e:
	/* 0x301e: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3027:
	/* 0x3027: je     304c <generic_sleepable_preload+0x304c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_304c;
	}
x86_l_3029:
	/* 0x3029: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_302e:
	/* 0x302e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3033:
	/* 0x3033: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3038:
	/* 0x3038: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_303d:
	/* 0x303d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3042:
	/* 0x3042: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3044:
	/* 0x3044: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3046:
	/* 0x3046: js     694d <generic_sleepable_preload+0x694d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26957ULL;
	}
x86_l_304c:
	/* 0x304c: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3051:
	/* 0x3051: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_305a:
	/* 0x305a: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_305f:
	/* 0x305f: je     6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25492ULL;
	}
x86_l_3065:
	/* 0x3065: mov    ecx,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_306c:
	/* 0x306c: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3071:
	/* 0x3071: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3076:
	/* 0x3076: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_307f:
	/* 0x307f: je     6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25492ULL;
	}
x86_l_3085:
	/* 0x3085: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_308a:
	/* 0x308a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_308f:
	/* 0x308f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3094:
	/* 0x3094: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3099:
	/* 0x3099: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_309e:
	/* 0x309e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30a0:
	/* 0x30a0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30a2:
	/* 0x30a2: jns    6394 <generic_sleepable_preload+0x6394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25492ULL;
	}
x86_l_30a8:
	/* 0x30a8: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_30ad:
	/* 0x30ad: jmp    6392 <generic_sleepable_preload+0x6392> */
	return 25490ULL;
x86_l_30b2:
	/* 0x30b2: mov    edx,DWORD PTR [r13+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_30b9:
	/* 0x30b9: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_30bf:
	/* 0x30bf: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30c2:
	/* 0x30c2: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_30c7:
	/* 0x30c7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_30cc:
	/* 0x30cc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30d1:
	/* 0x30d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30d6:
	/* 0x30d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30d8:
	/* 0x30d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30da:
	/* 0x30da: jne    3164 <generic_sleepable_preload+0x3164> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3164;
	}
x86_l_30e0:
	/* 0x30e0: mov    edx,DWORD PTR [r13+0x254] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 596ULL);
x86_l_30e7:
	/* 0x30e7: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_30ed:
	/* 0x30ed: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30f0:
	/* 0x30f0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30f5:
	/* 0x30f5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_30fa:
	/* 0x30fa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30ff:
	/* 0x30ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3104:
	/* 0x3104: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3106:
	/* 0x3106: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3108:
	/* 0x3108: jne    3164 <generic_sleepable_preload+0x3164> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3164;
	}
x86_l_310a:
	/* 0x310a: movzx  eax,BYTE PTR [r13+0x25b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 603ULL);
x86_l_3112:
	/* 0x3112: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_3119:
	/* 0x3119: mov    rcx,QWORD PTR [r13+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_3120:
	/* 0x3120: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_3125:
	/* 0x3125: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3128:
	/* 0x3128: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_312d:
	/* 0x312d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3132:
	/* 0x3132: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3137:
	/* 0x3137: movzx  ecx,BYTE PTR [r13+0x25b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 603ULL);
x86_l_313f:
	/* 0x313f: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_3146:
	/* 0x3146: mov    rdx,QWORD PTR [r13+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_314d:
	/* 0x314d: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_3152:
	/* 0x3152: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3155:
	/* 0x3155: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_315a:
	/* 0x315a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_315c:
	/* 0x315c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_315e:
	/* 0x315e: je     1c22 <generic_sleepable_preload+0x1c22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7202ULL;
	}
x86_l_3164:
	/* 0x3164: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3167:
	/* 0x3167: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_316c:
	/* 0x316c: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_316e:
	/* 0x316e: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_3171:
	/* 0x3171: cmp    WORD PTR [r13+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_317a:
	/* 0x317a: je     6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25633ULL;
	}
x86_l_3180:
	/* 0x3180: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_3187:
	/* 0x3187: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_318a:
	/* 0x318a: mov    eax,DWORD PTR [r13+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_3191:
	/* 0x3191: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3194:
	/* 0x3194: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3199:
	/* 0x3199: movzx  eax,WORD PTR [r13+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_31a1:
	/* 0x31a1: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_31a3:
	/* 0x31a3: je     3489 <generic_sleepable_preload+0x3489> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13449ULL;
	}
x86_l_31a9:
	/* 0x31a9: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_31ac:
	/* 0x31ac: je     31d1 <generic_sleepable_preload+0x31d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31d1;
	}
x86_l_31ae:
	/* 0x31ae: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31b3:
	/* 0x31b3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_31b8:
	/* 0x31b8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_31bd:
	/* 0x31bd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31c2:
	/* 0x31c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31c7:
	/* 0x31c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31c9:
	/* 0x31c9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31cb:
	/* 0x31cb: js     3e7c <generic_sleepable_preload+0x3e7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15996ULL;
	}
x86_l_31d1:
	/* 0x31d1: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_31da:
	/* 0x31da: je     6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25633ULL;
	}
x86_l_31e0:
	/* 0x31e0: mov    ecx,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_31e7:
	/* 0x31e7: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_31ec:
	/* 0x31ec: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31f1:
	/* 0x31f1: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_31fa:
	/* 0x31fa: je     321f <generic_sleepable_preload+0x321f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_321f;
	}
x86_l_31fc:
	/* 0x31fc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3201:
	/* 0x3201: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3206:
	/* 0x3206: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_320b:
	/* 0x320b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3210:
	/* 0x3210: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3215:
	/* 0x3215: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3217:
	/* 0x3217: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3219:
	/* 0x3219: js     541d <generic_sleepable_preload+0x541d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21533ULL;
	}
x86_l_321f:
	/* 0x321f: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_3228:
	/* 0x3228: je     6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25633ULL;
	}
x86_l_322e:
	/* 0x322e: mov    ecx,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_3235:
	/* 0x3235: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_323a:
	/* 0x323a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_323f:
	/* 0x323f: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_3248:
	/* 0x3248: je     326d <generic_sleepable_preload+0x326d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_326d;
	}
x86_l_324a:
	/* 0x324a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_324f:
	/* 0x324f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3254:
	/* 0x3254: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3259:
	/* 0x3259: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_325e:
	/* 0x325e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3263:
	/* 0x3263: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3265:
	/* 0x3265: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3267:
	/* 0x3267: js     6104 <generic_sleepable_preload+0x6104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24836ULL;
	}
x86_l_326d:
	/* 0x326d: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_3276:
	/* 0x3276: je     6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25633ULL;
	}
x86_l_327c:
	/* 0x327c: mov    ecx,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_3283:
	/* 0x3283: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3288:
	/* 0x3288: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_328d:
	/* 0x328d: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_3296:
	/* 0x3296: je     32bb <generic_sleepable_preload+0x32bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32bb;
	}
x86_l_3298:
	/* 0x3298: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_329d:
	/* 0x329d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_32a2:
	/* 0x32a2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_32a7:
	/* 0x32a7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32ac:
	/* 0x32ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32b1:
	/* 0x32b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32b3:
	/* 0x32b3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32b5:
	/* 0x32b5: js     6168 <generic_sleepable_preload+0x6168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24936ULL;
	}
x86_l_32bb:
	/* 0x32bb: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_32c4:
	/* 0x32c4: je     6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25633ULL;
	}
x86_l_32ca:
	/* 0x32ca: mov    ecx,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_32d1:
	/* 0x32d1: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_32d6:
	/* 0x32d6: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32db:
	/* 0x32db: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_32e4:
	/* 0x32e4: je     3309 <generic_sleepable_preload+0x3309> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3309;
	}
x86_l_32e6:
	/* 0x32e6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32eb:
	/* 0x32eb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_32f0:
	/* 0x32f0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_32f5:
	/* 0x32f5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32fa:
	/* 0x32fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32ff:
	/* 0x32ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3301:
	/* 0x3301: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3303:
	/* 0x3303: js     61cc <generic_sleepable_preload+0x61cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25036ULL;
	}
x86_l_3309:
	/* 0x3309: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_3312:
	/* 0x3312: je     6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25633ULL;
	}
x86_l_3318:
	/* 0x3318: mov    ecx,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
	return 13087ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13087ULL: goto x86_l_331f;
	case 13092ULL: goto x86_l_3324;
	case 13097ULL: goto x86_l_3329;
	case 13106ULL: goto x86_l_3332;
	case 13108ULL: goto x86_l_3334;
	case 13113ULL: goto x86_l_3339;
	case 13118ULL: goto x86_l_333e;
	case 13123ULL: goto x86_l_3343;
	case 13128ULL: goto x86_l_3348;
	case 13133ULL: goto x86_l_334d;
	case 13135ULL: goto x86_l_334f;
	case 13137ULL: goto x86_l_3351;
	case 13143ULL: goto x86_l_3357;
	case 13152ULL: goto x86_l_3360;
	case 13158ULL: goto x86_l_3366;
	case 13165ULL: goto x86_l_336d;
	case 13170ULL: goto x86_l_3372;
	case 13175ULL: goto x86_l_3377;
	case 13184ULL: goto x86_l_3380;
	case 13186ULL: goto x86_l_3382;
	case 13191ULL: goto x86_l_3387;
	case 13196ULL: goto x86_l_338c;
	case 13201ULL: goto x86_l_3391;
	case 13206ULL: goto x86_l_3396;
	case 13211ULL: goto x86_l_339b;
	case 13213ULL: goto x86_l_339d;
	case 13215ULL: goto x86_l_339f;
	case 13221ULL: goto x86_l_33a5;
	case 13230ULL: goto x86_l_33ae;
	case 13236ULL: goto x86_l_33b4;
	case 13243ULL: goto x86_l_33bb;
	case 13248ULL: goto x86_l_33c0;
	case 13253ULL: goto x86_l_33c5;
	case 13262ULL: goto x86_l_33ce;
	case 13264ULL: goto x86_l_33d0;
	case 13269ULL: goto x86_l_33d5;
	case 13274ULL: goto x86_l_33da;
	case 13279ULL: goto x86_l_33df;
	case 13284ULL: goto x86_l_33e4;
	case 13289ULL: goto x86_l_33e9;
	case 13291ULL: goto x86_l_33eb;
	case 13293ULL: goto x86_l_33ed;
	case 13299ULL: goto x86_l_33f3;
	case 13308ULL: goto x86_l_33fc;
	case 13314ULL: goto x86_l_3402;
	case 13321ULL: goto x86_l_3409;
	case 13326ULL: goto x86_l_340e;
	case 13331ULL: goto x86_l_3413;
	case 13340ULL: goto x86_l_341c;
	case 13342ULL: goto x86_l_341e;
	case 13347ULL: goto x86_l_3423;
	case 13352ULL: goto x86_l_3428;
	case 13357ULL: goto x86_l_342d;
	case 13362ULL: goto x86_l_3432;
	case 13367ULL: goto x86_l_3437;
	case 13369ULL: goto x86_l_3439;
	case 13371ULL: goto x86_l_343b;
	case 13377ULL: goto x86_l_3441;
	case 13382ULL: goto x86_l_3446;
	case 13391ULL: goto x86_l_344f;
	case 13397ULL: goto x86_l_3455;
	case 13404ULL: goto x86_l_345c;
	case 13409ULL: goto x86_l_3461;
	case 13414ULL: goto x86_l_3466;
	case 13423ULL: goto x86_l_346f;
	case 13429ULL: goto x86_l_3475;
	case 13434ULL: goto x86_l_347a;
	case 13439ULL: goto x86_l_347f;
	case 13444ULL: goto x86_l_3484;
	case 13449ULL: goto x86_l_3489;
	case 13452ULL: goto x86_l_348c;
	case 13454ULL: goto x86_l_348e;
	case 13459ULL: goto x86_l_3493;
	case 13464ULL: goto x86_l_3498;
	case 13469ULL: goto x86_l_349d;
	case 13474ULL: goto x86_l_34a2;
	case 13479ULL: goto x86_l_34a7;
	case 13481ULL: goto x86_l_34a9;
	case 13483ULL: goto x86_l_34ab;
	case 13489ULL: goto x86_l_34b1;
	case 13498ULL: goto x86_l_34ba;
	case 13504ULL: goto x86_l_34c0;
	case 13511ULL: goto x86_l_34c7;
	case 13516ULL: goto x86_l_34cc;
	case 13521ULL: goto x86_l_34d1;
	case 13530ULL: goto x86_l_34da;
	case 13532ULL: goto x86_l_34dc;
	case 13537ULL: goto x86_l_34e1;
	case 13542ULL: goto x86_l_34e6;
	case 13547ULL: goto x86_l_34eb;
	case 13552ULL: goto x86_l_34f0;
	case 13557ULL: goto x86_l_34f5;
	case 13559ULL: goto x86_l_34f7;
	case 13561ULL: goto x86_l_34f9;
	case 13567ULL: goto x86_l_34ff;
	case 13576ULL: goto x86_l_3508;
	case 13582ULL: goto x86_l_350e;
	case 13589ULL: goto x86_l_3515;
	case 13594ULL: goto x86_l_351a;
	case 13599ULL: goto x86_l_351f;
	case 13608ULL: goto x86_l_3528;
	case 13610ULL: goto x86_l_352a;
	case 13615ULL: goto x86_l_352f;
	case 13620ULL: goto x86_l_3534;
	case 13625ULL: goto x86_l_3539;
	case 13630ULL: goto x86_l_353e;
	case 13635ULL: goto x86_l_3543;
	case 13637ULL: goto x86_l_3545;
	case 13639ULL: goto x86_l_3547;
	case 13645ULL: goto x86_l_354d;
	case 13654ULL: goto x86_l_3556;
	case 13660ULL: goto x86_l_355c;
	case 13667ULL: goto x86_l_3563;
	case 13672ULL: goto x86_l_3568;
	case 13677ULL: goto x86_l_356d;
	case 13686ULL: goto x86_l_3576;
	case 13688ULL: goto x86_l_3578;
	case 13693ULL: goto x86_l_357d;
	case 13698ULL: goto x86_l_3582;
	case 13703ULL: goto x86_l_3587;
	case 13708ULL: goto x86_l_358c;
	case 13713ULL: goto x86_l_3591;
	case 13715ULL: goto x86_l_3593;
	case 13717ULL: goto x86_l_3595;
	case 13723ULL: goto x86_l_359b;
	case 13732ULL: goto x86_l_35a4;
	case 13738ULL: goto x86_l_35aa;
	case 13745ULL: goto x86_l_35b1;
	case 13750ULL: goto x86_l_35b6;
	case 13755ULL: goto x86_l_35bb;
	case 13764ULL: goto x86_l_35c4;
	case 13766ULL: goto x86_l_35c6;
	case 13771ULL: goto x86_l_35cb;
	case 13776ULL: goto x86_l_35d0;
	case 13781ULL: goto x86_l_35d5;
	case 13786ULL: goto x86_l_35da;
	case 13791ULL: goto x86_l_35df;
	case 13793ULL: goto x86_l_35e1;
	case 13795ULL: goto x86_l_35e3;
	case 13801ULL: goto x86_l_35e9;
	case 13810ULL: goto x86_l_35f2;
	case 13816ULL: goto x86_l_35f8;
	case 13823ULL: goto x86_l_35ff;
	case 13828ULL: goto x86_l_3604;
	case 13833ULL: goto x86_l_3609;
	case 13842ULL: goto x86_l_3612;
	case 13844ULL: goto x86_l_3614;
	case 13849ULL: goto x86_l_3619;
	case 13854ULL: goto x86_l_361e;
	case 13859ULL: goto x86_l_3623;
	case 13864ULL: goto x86_l_3628;
	case 13869ULL: goto x86_l_362d;
	case 13871ULL: goto x86_l_362f;
	case 13873ULL: goto x86_l_3631;
	case 13879ULL: goto x86_l_3637;
	case 13888ULL: goto x86_l_3640;
	case 13894ULL: goto x86_l_3646;
	case 13901ULL: goto x86_l_364d;
	case 13906ULL: goto x86_l_3652;
	case 13911ULL: goto x86_l_3657;
	case 13920ULL: goto x86_l_3660;
	case 13922ULL: goto x86_l_3662;
	case 13927ULL: goto x86_l_3667;
	case 13932ULL: goto x86_l_366c;
	case 13937ULL: goto x86_l_3671;
	case 13942ULL: goto x86_l_3676;
	case 13947ULL: goto x86_l_367b;
	case 13949ULL: goto x86_l_367d;
	case 13951ULL: goto x86_l_367f;
	case 13957ULL: goto x86_l_3685;
	case 13966ULL: goto x86_l_368e;
	case 13972ULL: goto x86_l_3694;
	case 13979ULL: goto x86_l_369b;
	case 13984ULL: goto x86_l_36a0;
	case 13989ULL: goto x86_l_36a5;
	case 13998ULL: goto x86_l_36ae;
	case 14000ULL: goto x86_l_36b0;
	case 14005ULL: goto x86_l_36b5;
	case 14010ULL: goto x86_l_36ba;
	case 14015ULL: goto x86_l_36bf;
	case 14020ULL: goto x86_l_36c4;
	case 14025ULL: goto x86_l_36c9;
	case 14027ULL: goto x86_l_36cb;
	case 14029ULL: goto x86_l_36cd;
	case 14035ULL: goto x86_l_36d3;
	case 14040ULL: goto x86_l_36d8;
	case 14049ULL: goto x86_l_36e1;
	case 14055ULL: goto x86_l_36e7;
	case 14062ULL: goto x86_l_36ee;
	case 14067ULL: goto x86_l_36f3;
	case 14072ULL: goto x86_l_36f8;
	case 14081ULL: goto x86_l_3701;
	case 14083ULL: goto x86_l_3703;
	case 14088ULL: goto x86_l_3708;
	case 14093ULL: goto x86_l_370d;
	case 14098ULL: goto x86_l_3712;
	case 14103ULL: goto x86_l_3717;
	case 14108ULL: goto x86_l_371c;
	case 14110ULL: goto x86_l_371e;
	case 14112ULL: goto x86_l_3720;
	case 14118ULL: goto x86_l_3726;
	case 14123ULL: goto x86_l_372b;
	case 14132ULL: goto x86_l_3734;
	case 14138ULL: goto x86_l_373a;
	case 14145ULL: goto x86_l_3741;
	case 14150ULL: goto x86_l_3746;
	case 14155ULL: goto x86_l_374b;
	case 14164ULL: goto x86_l_3754;
	case 14170ULL: goto x86_l_375a;
	case 14175ULL: goto x86_l_375f;
	case 14180ULL: goto x86_l_3764;
	case 14185ULL: goto x86_l_3769;
	case 14190ULL: goto x86_l_376e;
	case 14195ULL: goto x86_l_3773;
	case 14197ULL: goto x86_l_3775;
	case 14199ULL: goto x86_l_3777;
	case 14205ULL: goto x86_l_377d;
	case 14210ULL: goto x86_l_3782;
	case 14215ULL: goto x86_l_3787;
	case 14222ULL: goto x86_l_378e;
	case 14228ULL: goto x86_l_3794;
	case 14231ULL: goto x86_l_3797;
	case 14236ULL: goto x86_l_379c;
	case 14241ULL: goto x86_l_37a1;
	case 14246ULL: goto x86_l_37a6;
	case 14251ULL: goto x86_l_37ab;
	case 14253ULL: goto x86_l_37ad;
	case 14255ULL: goto x86_l_37af;
	case 14261ULL: goto x86_l_37b5;
	case 14268ULL: goto x86_l_37bc;
	case 14273ULL: goto x86_l_37c1;
	case 14276ULL: goto x86_l_37c4;
	case 14281ULL: goto x86_l_37c9;
	case 14286ULL: goto x86_l_37ce;
	case 14291ULL: goto x86_l_37d3;
	case 14296ULL: goto x86_l_37d8;
	case 14299ULL: goto x86_l_37db;
	case 14301ULL: goto x86_l_37dd;
	case 14303ULL: goto x86_l_37df;
	case 14305ULL: goto x86_l_37e1;
	case 14313ULL: goto x86_l_37e9;
	case 14320ULL: goto x86_l_37f0;
	case 14327ULL: goto x86_l_37f7;
	case 14332ULL: goto x86_l_37fc;
	case 14335ULL: goto x86_l_37ff;
	case 14340ULL: goto x86_l_3804;
	case 14345ULL: goto x86_l_3809;
	case 14350ULL: goto x86_l_380e;
	case 14358ULL: goto x86_l_3816;
	case 14365ULL: goto x86_l_381d;
	case 14372ULL: goto x86_l_3824;
	case 14377ULL: goto x86_l_3829;
	case 14380ULL: goto x86_l_382c;
	case 14385ULL: goto x86_l_3831;
	case 14387ULL: goto x86_l_3833;
	case 14389ULL: goto x86_l_3835;
	case 14395ULL: goto x86_l_383b;
	case 14398ULL: goto x86_l_383e;
	case 14403ULL: goto x86_l_3843;
	case 14405ULL: goto x86_l_3845;
	case 14408ULL: goto x86_l_3848;
	case 14417ULL: goto x86_l_3851;
	case 14423ULL: goto x86_l_3857;
	case 14430ULL: goto x86_l_385e;
	case 14433ULL: goto x86_l_3861;
	case 14440ULL: goto x86_l_3868;
	case 14443ULL: goto x86_l_386b;
	case 14448ULL: goto x86_l_3870;
	case 14456ULL: goto x86_l_3878;
	case 14458ULL: goto x86_l_387a;
	case 14464ULL: goto x86_l_3880;
	case 14467ULL: goto x86_l_3883;
	case 14469ULL: goto x86_l_3885;
	case 14474ULL: goto x86_l_388a;
	case 14479ULL: goto x86_l_388f;
	case 14484ULL: goto x86_l_3894;
	case 14489ULL: goto x86_l_3899;
	case 14494ULL: goto x86_l_389e;
	case 14496ULL: goto x86_l_38a0;
	case 14498ULL: goto x86_l_38a2;
	case 14504ULL: goto x86_l_38a8;
	case 14513ULL: goto x86_l_38b1;
	case 14519ULL: goto x86_l_38b7;
	case 14526ULL: goto x86_l_38be;
	case 14531ULL: goto x86_l_38c3;
	case 14536ULL: goto x86_l_38c8;
	case 14545ULL: goto x86_l_38d1;
	case 14547ULL: goto x86_l_38d3;
	case 14552ULL: goto x86_l_38d8;
	case 14557ULL: goto x86_l_38dd;
	case 14562ULL: goto x86_l_38e2;
	case 14567ULL: goto x86_l_38e7;
	case 14572ULL: goto x86_l_38ec;
	case 14574ULL: goto x86_l_38ee;
	case 14576ULL: goto x86_l_38f0;
	case 14582ULL: goto x86_l_38f6;
	case 14591ULL: goto x86_l_38ff;
	case 14597ULL: goto x86_l_3905;
	case 14604ULL: goto x86_l_390c;
	case 14609ULL: goto x86_l_3911;
	case 14614ULL: goto x86_l_3916;
	case 14623ULL: goto x86_l_391f;
	case 14625ULL: goto x86_l_3921;
	case 14630ULL: goto x86_l_3926;
	case 14635ULL: goto x86_l_392b;
	case 14640ULL: goto x86_l_3930;
	case 14645ULL: goto x86_l_3935;
	case 14650ULL: goto x86_l_393a;
	case 14652ULL: goto x86_l_393c;
	case 14654ULL: goto x86_l_393e;
	case 14660ULL: goto x86_l_3944;
	case 14669ULL: goto x86_l_394d;
	case 14675ULL: goto x86_l_3953;
	case 14682ULL: goto x86_l_395a;
	case 14687ULL: goto x86_l_395f;
	case 14692ULL: goto x86_l_3964;
	case 14701ULL: goto x86_l_396d;
	case 14703ULL: goto x86_l_396f;
	case 14708ULL: goto x86_l_3974;
	case 14713ULL: goto x86_l_3979;
	case 14718ULL: goto x86_l_397e;
	case 14723ULL: goto x86_l_3983;
	case 14728ULL: goto x86_l_3988;
	case 14730ULL: goto x86_l_398a;
	case 14732ULL: goto x86_l_398c;
	case 14738ULL: goto x86_l_3992;
	case 14747ULL: goto x86_l_399b;
	case 14753ULL: goto x86_l_39a1;
	case 14760ULL: goto x86_l_39a8;
	case 14765ULL: goto x86_l_39ad;
	case 14770ULL: goto x86_l_39b2;
	case 14779ULL: goto x86_l_39bb;
	case 14781ULL: goto x86_l_39bd;
	case 14786ULL: goto x86_l_39c2;
	case 14791ULL: goto x86_l_39c7;
	case 14796ULL: goto x86_l_39cc;
	case 14801ULL: goto x86_l_39d1;
	case 14806ULL: goto x86_l_39d6;
	case 14808ULL: goto x86_l_39d8;
	case 14810ULL: goto x86_l_39da;
	case 14816ULL: goto x86_l_39e0;
	case 14825ULL: goto x86_l_39e9;
	case 14831ULL: goto x86_l_39ef;
	case 14838ULL: goto x86_l_39f6;
	case 14843ULL: goto x86_l_39fb;
	case 14848ULL: goto x86_l_3a00;
	case 14857ULL: goto x86_l_3a09;
	case 14859ULL: goto x86_l_3a0b;
	case 14864ULL: goto x86_l_3a10;
	case 14869ULL: goto x86_l_3a15;
	case 14874ULL: goto x86_l_3a1a;
	case 14879ULL: goto x86_l_3a1f;
	case 14884ULL: goto x86_l_3a24;
	case 14886ULL: goto x86_l_3a26;
	case 14888ULL: goto x86_l_3a28;
	case 14894ULL: goto x86_l_3a2e;
	case 14903ULL: goto x86_l_3a37;
	case 14909ULL: goto x86_l_3a3d;
	case 14916ULL: goto x86_l_3a44;
	case 14921ULL: goto x86_l_3a49;
	case 14926ULL: goto x86_l_3a4e;
	case 14935ULL: goto x86_l_3a57;
	case 14937ULL: goto x86_l_3a59;
	case 14942ULL: goto x86_l_3a5e;
	case 14947ULL: goto x86_l_3a63;
	case 14952ULL: goto x86_l_3a68;
	case 14957ULL: goto x86_l_3a6d;
	case 14962ULL: goto x86_l_3a72;
	case 14964ULL: goto x86_l_3a74;
	case 14966ULL: goto x86_l_3a76;
	case 14972ULL: goto x86_l_3a7c;
	case 14981ULL: goto x86_l_3a85;
	case 14987ULL: goto x86_l_3a8b;
	case 14994ULL: goto x86_l_3a92;
	case 14999ULL: goto x86_l_3a97;
	case 15004ULL: goto x86_l_3a9c;
	case 15013ULL: goto x86_l_3aa5;
	case 15015ULL: goto x86_l_3aa7;
	case 15020ULL: goto x86_l_3aac;
	case 15025ULL: goto x86_l_3ab1;
	case 15030ULL: goto x86_l_3ab6;
	case 15035ULL: goto x86_l_3abb;
	case 15040ULL: goto x86_l_3ac0;
	case 15042ULL: goto x86_l_3ac2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_331f:
	/* 0x331f: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3324:
	/* 0x3324: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3329:
	/* 0x3329: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_3332:
	/* 0x3332: je     3357 <generic_sleepable_preload+0x3357> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3357;
	}
x86_l_3334:
	/* 0x3334: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3339:
	/* 0x3339: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_333e:
	/* 0x333e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3343:
	/* 0x3343: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3348:
	/* 0x3348: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_334d:
	/* 0x334d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_334f:
	/* 0x334f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3351:
	/* 0x3351: js     622d <generic_sleepable_preload+0x622d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25133ULL;
	}
x86_l_3357:
	/* 0x3357: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_3360:
	/* 0x3360: je     6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25633ULL;
	}
x86_l_3366:
	/* 0x3366: mov    ecx,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_336d:
	/* 0x336d: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3372:
	/* 0x3372: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3377:
	/* 0x3377: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_3380:
	/* 0x3380: je     33a5 <generic_sleepable_preload+0x33a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33a5;
	}
x86_l_3382:
	/* 0x3382: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3387:
	/* 0x3387: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_338c:
	/* 0x338c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3391:
	/* 0x3391: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3396:
	/* 0x3396: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_339b:
	/* 0x339b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_339d:
	/* 0x339d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_339f:
	/* 0x339f: js     641a <generic_sleepable_preload+0x641a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25626ULL;
	}
x86_l_33a5:
	/* 0x33a5: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_33ae:
	/* 0x33ae: je     6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25633ULL;
	}
x86_l_33b4:
	/* 0x33b4: mov    ecx,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_33bb:
	/* 0x33bb: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_33c0:
	/* 0x33c0: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33c5:
	/* 0x33c5: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_33ce:
	/* 0x33ce: je     33f3 <generic_sleepable_preload+0x33f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33f3;
	}
x86_l_33d0:
	/* 0x33d0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33d5:
	/* 0x33d5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_33da:
	/* 0x33da: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_33df:
	/* 0x33df: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33e4:
	/* 0x33e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33e9:
	/* 0x33e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33eb:
	/* 0x33eb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33ed:
	/* 0x33ed: js     68e7 <generic_sleepable_preload+0x68e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26855ULL;
	}
x86_l_33f3:
	/* 0x33f3: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_33fc:
	/* 0x33fc: je     6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25633ULL;
	}
x86_l_3402:
	/* 0x3402: mov    ecx,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_3409:
	/* 0x3409: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_340e:
	/* 0x340e: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3413:
	/* 0x3413: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_341c:
	/* 0x341c: je     3441 <generic_sleepable_preload+0x3441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3441;
	}
x86_l_341e:
	/* 0x341e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3423:
	/* 0x3423: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3428:
	/* 0x3428: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_342d:
	/* 0x342d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3432:
	/* 0x3432: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3437:
	/* 0x3437: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3439:
	/* 0x3439: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_343b:
	/* 0x343b: js     6959 <generic_sleepable_preload+0x6959> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26969ULL;
	}
x86_l_3441:
	/* 0x3441: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3446:
	/* 0x3446: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_344f:
	/* 0x344f: je     6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25633ULL;
	}
x86_l_3455:
	/* 0x3455: mov    ecx,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_345c:
	/* 0x345c: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3461:
	/* 0x3461: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3466:
	/* 0x3466: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_346f:
	/* 0x346f: je     6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25633ULL;
	}
x86_l_3475:
	/* 0x3475: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_347a:
	/* 0x347a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_347f:
	/* 0x347f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3484:
	/* 0x3484: jmp    3769 <generic_sleepable_preload+0x3769> */
	goto x86_l_3769;
x86_l_3489:
	/* 0x3489: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_348c:
	/* 0x348c: je     34b1 <generic_sleepable_preload+0x34b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34b1;
	}
x86_l_348e:
	/* 0x348e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3493:
	/* 0x3493: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3498:
	/* 0x3498: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_349d:
	/* 0x349d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34a2:
	/* 0x34a2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34a7:
	/* 0x34a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34a9:
	/* 0x34a9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34ab:
	/* 0x34ab: js     3e7c <generic_sleepable_preload+0x3e7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15996ULL;
	}
x86_l_34b1:
	/* 0x34b1: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_34ba:
	/* 0x34ba: je     6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25633ULL;
	}
x86_l_34c0:
	/* 0x34c0: mov    ecx,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_34c7:
	/* 0x34c7: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_34cc:
	/* 0x34cc: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34d1:
	/* 0x34d1: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_34da:
	/* 0x34da: je     34ff <generic_sleepable_preload+0x34ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34ff;
	}
x86_l_34dc:
	/* 0x34dc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34e1:
	/* 0x34e1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_34e6:
	/* 0x34e6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_34eb:
	/* 0x34eb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34f0:
	/* 0x34f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34f5:
	/* 0x34f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34f7:
	/* 0x34f7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34f9:
	/* 0x34f9: js     541d <generic_sleepable_preload+0x541d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21533ULL;
	}
x86_l_34ff:
	/* 0x34ff: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_3508:
	/* 0x3508: je     6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25633ULL;
	}
x86_l_350e:
	/* 0x350e: mov    ecx,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_3515:
	/* 0x3515: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_351a:
	/* 0x351a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_351f:
	/* 0x351f: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_3528:
	/* 0x3528: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_352a:
	/* 0x352a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_352f:
	/* 0x352f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3534:
	/* 0x3534: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3539:
	/* 0x3539: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_353e:
	/* 0x353e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3543:
	/* 0x3543: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3545:
	/* 0x3545: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3547:
	/* 0x3547: js     6104 <generic_sleepable_preload+0x6104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24836ULL;
	}
x86_l_354d:
	/* 0x354d: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_3556:
	/* 0x3556: je     6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25633ULL;
	}
x86_l_355c:
	/* 0x355c: mov    ecx,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_3563:
	/* 0x3563: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3568:
	/* 0x3568: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_356d:
	/* 0x356d: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_3576:
	/* 0x3576: je     359b <generic_sleepable_preload+0x359b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_359b;
	}
x86_l_3578:
	/* 0x3578: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_357d:
	/* 0x357d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3582:
	/* 0x3582: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3587:
	/* 0x3587: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_358c:
	/* 0x358c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3591:
	/* 0x3591: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3593:
	/* 0x3593: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3595:
	/* 0x3595: js     6168 <generic_sleepable_preload+0x6168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24936ULL;
	}
x86_l_359b:
	/* 0x359b: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_35a4:
	/* 0x35a4: je     6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25633ULL;
	}
x86_l_35aa:
	/* 0x35aa: mov    ecx,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_35b1:
	/* 0x35b1: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_35b6:
	/* 0x35b6: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35bb:
	/* 0x35bb: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_35c4:
	/* 0x35c4: je     35e9 <generic_sleepable_preload+0x35e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35e9;
	}
x86_l_35c6:
	/* 0x35c6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35cb:
	/* 0x35cb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_35d0:
	/* 0x35d0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_35d5:
	/* 0x35d5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35da:
	/* 0x35da: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35df:
	/* 0x35df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35e1:
	/* 0x35e1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35e3:
	/* 0x35e3: js     61cc <generic_sleepable_preload+0x61cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25036ULL;
	}
x86_l_35e9:
	/* 0x35e9: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_35f2:
	/* 0x35f2: je     6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25633ULL;
	}
x86_l_35f8:
	/* 0x35f8: mov    ecx,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_35ff:
	/* 0x35ff: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3604:
	/* 0x3604: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3609:
	/* 0x3609: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_3612:
	/* 0x3612: je     3637 <generic_sleepable_preload+0x3637> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3637;
	}
x86_l_3614:
	/* 0x3614: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3619:
	/* 0x3619: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_361e:
	/* 0x361e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3623:
	/* 0x3623: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3628:
	/* 0x3628: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_362d:
	/* 0x362d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_362f:
	/* 0x362f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3631:
	/* 0x3631: js     622d <generic_sleepable_preload+0x622d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25133ULL;
	}
x86_l_3637:
	/* 0x3637: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_3640:
	/* 0x3640: je     6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25633ULL;
	}
x86_l_3646:
	/* 0x3646: mov    ecx,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_364d:
	/* 0x364d: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3652:
	/* 0x3652: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3657:
	/* 0x3657: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_3660:
	/* 0x3660: je     3685 <generic_sleepable_preload+0x3685> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3685;
	}
x86_l_3662:
	/* 0x3662: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3667:
	/* 0x3667: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_366c:
	/* 0x366c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3671:
	/* 0x3671: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3676:
	/* 0x3676: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_367b:
	/* 0x367b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_367d:
	/* 0x367d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_367f:
	/* 0x367f: js     641a <generic_sleepable_preload+0x641a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25626ULL;
	}
x86_l_3685:
	/* 0x3685: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_368e:
	/* 0x368e: je     6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25633ULL;
	}
x86_l_3694:
	/* 0x3694: mov    ecx,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_369b:
	/* 0x369b: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_36a0:
	/* 0x36a0: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36a5:
	/* 0x36a5: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_36ae:
	/* 0x36ae: je     36d3 <generic_sleepable_preload+0x36d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36d3;
	}
x86_l_36b0:
	/* 0x36b0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36b5:
	/* 0x36b5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_36ba:
	/* 0x36ba: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_36bf:
	/* 0x36bf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36c4:
	/* 0x36c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36c9:
	/* 0x36c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36cb:
	/* 0x36cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36cd:
	/* 0x36cd: js     69fd <generic_sleepable_preload+0x69fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27133ULL;
	}
x86_l_36d3:
	/* 0x36d3: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_36d8:
	/* 0x36d8: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_36e1:
	/* 0x36e1: je     6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25633ULL;
	}
x86_l_36e7:
	/* 0x36e7: mov    ecx,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_36ee:
	/* 0x36ee: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_36f3:
	/* 0x36f3: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36f8:
	/* 0x36f8: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_3701:
	/* 0x3701: je     3726 <generic_sleepable_preload+0x3726> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3726;
	}
x86_l_3703:
	/* 0x3703: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3708:
	/* 0x3708: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_370d:
	/* 0x370d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3712:
	/* 0x3712: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3717:
	/* 0x3717: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_371c:
	/* 0x371c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_371e:
	/* 0x371e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3720:
	/* 0x3720: js     6959 <generic_sleepable_preload+0x6959> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26969ULL;
	}
x86_l_3726:
	/* 0x3726: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_372b:
	/* 0x372b: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_3734:
	/* 0x3734: je     6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25633ULL;
	}
x86_l_373a:
	/* 0x373a: mov    ecx,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_3741:
	/* 0x3741: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3746:
	/* 0x3746: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_374b:
	/* 0x374b: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_3754:
	/* 0x3754: je     6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25633ULL;
	}
x86_l_375a:
	/* 0x375a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_375f:
	/* 0x375f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3764:
	/* 0x3764: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3769:
	/* 0x3769: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_376e:
	/* 0x376e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3773:
	/* 0x3773: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3775:
	/* 0x3775: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3777:
	/* 0x3777: jns    6421 <generic_sleepable_preload+0x6421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25633ULL;
	}
x86_l_377d:
	/* 0x377d: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_3782:
	/* 0x3782: jmp    641f <generic_sleepable_preload+0x641f> */
	return 25631ULL;
x86_l_3787:
	/* 0x3787: mov    edx,DWORD PTR [r13+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_378e:
	/* 0x378e: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3794:
	/* 0x3794: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3797:
	/* 0x3797: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_379c:
	/* 0x379c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_37a1:
	/* 0x37a1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37a6:
	/* 0x37a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37ab:
	/* 0x37ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37ad:
	/* 0x37ad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37af:
	/* 0x37af: jne    383b <generic_sleepable_preload+0x383b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_383b;
	}
x86_l_37b5:
	/* 0x37b5: mov    eax,DWORD PTR [r13+0x26c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 620ULL);
x86_l_37bc:
	/* 0x37bc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_37c1:
	/* 0x37c1: add    rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_37c4:
	/* 0x37c4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37c9:
	/* 0x37c9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_37ce:
	/* 0x37ce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37d3:
	/* 0x37d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37d8:
	/* 0x37d8: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_37db:
	/* 0x37db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37dd:
	/* 0x37dd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37df:
	/* 0x37df: jne    383b <generic_sleepable_preload+0x383b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_383b;
	}
x86_l_37e1:
	/* 0x37e1: movzx  eax,BYTE PTR [r13+0x273] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 627ULL);
x86_l_37e9:
	/* 0x37e9: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_37f0:
	/* 0x37f0: mov    rcx,QWORD PTR [r13+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_37f7:
	/* 0x37f7: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_37fc:
	/* 0x37fc: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_37ff:
	/* 0x37ff: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3804:
	/* 0x3804: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3809:
	/* 0x3809: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_380e:
	/* 0x380e: movzx  ecx,BYTE PTR [r13+0x273] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 627ULL);
x86_l_3816:
	/* 0x3816: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_381d:
	/* 0x381d: mov    rdx,QWORD PTR [r13+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_3824:
	/* 0x3824: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_3829:
	/* 0x3829: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_382c:
	/* 0x382c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3831:
	/* 0x3831: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3833:
	/* 0x3833: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3835:
	/* 0x3835: je     1c58 <generic_sleepable_preload+0x1c58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7256ULL;
	}
x86_l_383b:
	/* 0x383b: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_383e:
	/* 0x383e: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3843:
	/* 0x3843: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3845:
	/* 0x3845: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_3848:
	/* 0x3848: cmp    WORD PTR [r13+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_3851:
	/* 0x3851: je     64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25775ULL;
	}
x86_l_3857:
	/* 0x3857: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_385e:
	/* 0x385e: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3861:
	/* 0x3861: mov    eax,DWORD PTR [r13+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_3868:
	/* 0x3868: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_386b:
	/* 0x386b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3870:
	/* 0x3870: movzx  eax,WORD PTR [r13+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_3878:
	/* 0x3878: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_387a:
	/* 0x387a: je     3b60 <generic_sleepable_preload+0x3b60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15200ULL;
	}
x86_l_3880:
	/* 0x3880: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3883:
	/* 0x3883: je     38a8 <generic_sleepable_preload+0x38a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38a8;
	}
x86_l_3885:
	/* 0x3885: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_388a:
	/* 0x388a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_388f:
	/* 0x388f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3894:
	/* 0x3894: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3899:
	/* 0x3899: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_389e:
	/* 0x389e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38a0:
	/* 0x38a0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38a2:
	/* 0x38a2: js     3e86 <generic_sleepable_preload+0x3e86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 16006ULL;
	}
x86_l_38a8:
	/* 0x38a8: cmp    WORD PTR [r13+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_38b1:
	/* 0x38b1: je     64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25775ULL;
	}
x86_l_38b7:
	/* 0x38b7: mov    ecx,DWORD PTR [r13+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_38be:
	/* 0x38be: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_38c3:
	/* 0x38c3: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38c8:
	/* 0x38c8: cmp    WORD PTR [r13+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_38d1:
	/* 0x38d1: je     38f6 <generic_sleepable_preload+0x38f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38f6;
	}
x86_l_38d3:
	/* 0x38d3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38d8:
	/* 0x38d8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_38dd:
	/* 0x38dd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_38e2:
	/* 0x38e2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38e7:
	/* 0x38e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38ec:
	/* 0x38ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38ee:
	/* 0x38ee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38f0:
	/* 0x38f0: js     5427 <generic_sleepable_preload+0x5427> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21543ULL;
	}
x86_l_38f6:
	/* 0x38f6: cmp    WORD PTR [r13+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_38ff:
	/* 0x38ff: je     64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25775ULL;
	}
x86_l_3905:
	/* 0x3905: mov    ecx,DWORD PTR [r13+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_390c:
	/* 0x390c: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3911:
	/* 0x3911: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3916:
	/* 0x3916: cmp    WORD PTR [r13+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_391f:
	/* 0x391f: je     3944 <generic_sleepable_preload+0x3944> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3944;
	}
x86_l_3921:
	/* 0x3921: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3926:
	/* 0x3926: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_392b:
	/* 0x392b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3930:
	/* 0x3930: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3935:
	/* 0x3935: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_393a:
	/* 0x393a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_393c:
	/* 0x393c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_393e:
	/* 0x393e: js     610e <generic_sleepable_preload+0x610e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24846ULL;
	}
x86_l_3944:
	/* 0x3944: cmp    WORD PTR [r13+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_394d:
	/* 0x394d: je     64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25775ULL;
	}
x86_l_3953:
	/* 0x3953: mov    ecx,DWORD PTR [r13+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_395a:
	/* 0x395a: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_395f:
	/* 0x395f: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3964:
	/* 0x3964: cmp    WORD PTR [r13+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_396d:
	/* 0x396d: je     3992 <generic_sleepable_preload+0x3992> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3992;
	}
x86_l_396f:
	/* 0x396f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3974:
	/* 0x3974: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3979:
	/* 0x3979: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_397e:
	/* 0x397e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3983:
	/* 0x3983: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3988:
	/* 0x3988: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_398a:
	/* 0x398a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_398c:
	/* 0x398c: js     6172 <generic_sleepable_preload+0x6172> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24946ULL;
	}
x86_l_3992:
	/* 0x3992: cmp    WORD PTR [r13+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_399b:
	/* 0x399b: je     64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25775ULL;
	}
x86_l_39a1:
	/* 0x39a1: mov    ecx,DWORD PTR [r13+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_39a8:
	/* 0x39a8: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_39ad:
	/* 0x39ad: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39b2:
	/* 0x39b2: cmp    WORD PTR [r13+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_39bb:
	/* 0x39bb: je     39e0 <generic_sleepable_preload+0x39e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39e0;
	}
x86_l_39bd:
	/* 0x39bd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39c2:
	/* 0x39c2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_39c7:
	/* 0x39c7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_39cc:
	/* 0x39cc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39d1:
	/* 0x39d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39d6:
	/* 0x39d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39d8:
	/* 0x39d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39da:
	/* 0x39da: js     61d6 <generic_sleepable_preload+0x61d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25046ULL;
	}
x86_l_39e0:
	/* 0x39e0: cmp    WORD PTR [r13+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_39e9:
	/* 0x39e9: je     64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25775ULL;
	}
x86_l_39ef:
	/* 0x39ef: mov    ecx,DWORD PTR [r13+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_39f6:
	/* 0x39f6: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_39fb:
	/* 0x39fb: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a00:
	/* 0x3a00: cmp    WORD PTR [r13+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_3a09:
	/* 0x3a09: je     3a2e <generic_sleepable_preload+0x3a2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a2e;
	}
x86_l_3a0b:
	/* 0x3a0b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a10:
	/* 0x3a10: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a15:
	/* 0x3a15: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a1a:
	/* 0x3a1a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a1f:
	/* 0x3a1f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a24:
	/* 0x3a24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a26:
	/* 0x3a26: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a28:
	/* 0x3a28: js     6237 <generic_sleepable_preload+0x6237> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25143ULL;
	}
x86_l_3a2e:
	/* 0x3a2e: cmp    WORD PTR [r13+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_3a37:
	/* 0x3a37: je     64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25775ULL;
	}
x86_l_3a3d:
	/* 0x3a3d: mov    ecx,DWORD PTR [r13+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_3a44:
	/* 0x3a44: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3a49:
	/* 0x3a49: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a4e:
	/* 0x3a4e: cmp    WORD PTR [r13+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_3a57:
	/* 0x3a57: je     3a7c <generic_sleepable_preload+0x3a7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a7c;
	}
x86_l_3a59:
	/* 0x3a59: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a5e:
	/* 0x3a5e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a63:
	/* 0x3a63: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a68:
	/* 0x3a68: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a6d:
	/* 0x3a6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a72:
	/* 0x3a72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a74:
	/* 0x3a74: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a76:
	/* 0x3a76: js     64a7 <generic_sleepable_preload+0x64a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25767ULL;
	}
x86_l_3a7c:
	/* 0x3a7c: cmp    WORD PTR [r13+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_3a85:
	/* 0x3a85: je     64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25775ULL;
	}
x86_l_3a8b:
	/* 0x3a8b: mov    ecx,DWORD PTR [r13+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_3a92:
	/* 0x3a92: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3a97:
	/* 0x3a97: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a9c:
	/* 0x3a9c: cmp    WORD PTR [r13+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_3aa5:
	/* 0x3aa5: je     3aca <generic_sleepable_preload+0x3aca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15050ULL;
	}
x86_l_3aa7:
	/* 0x3aa7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3aac:
	/* 0x3aac: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3ab1:
	/* 0x3ab1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3ab6:
	/* 0x3ab6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3abb:
	/* 0x3abb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ac0:
	/* 0x3ac0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ac2:
	/* 0x3ac2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
	return 15044ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15044ULL: goto x86_l_3ac4;
	case 15050ULL: goto x86_l_3aca;
	case 15059ULL: goto x86_l_3ad3;
	case 15065ULL: goto x86_l_3ad9;
	case 15072ULL: goto x86_l_3ae0;
	case 15077ULL: goto x86_l_3ae5;
	case 15082ULL: goto x86_l_3aea;
	case 15091ULL: goto x86_l_3af3;
	case 15093ULL: goto x86_l_3af5;
	case 15098ULL: goto x86_l_3afa;
	case 15103ULL: goto x86_l_3aff;
	case 15108ULL: goto x86_l_3b04;
	case 15113ULL: goto x86_l_3b09;
	case 15118ULL: goto x86_l_3b0e;
	case 15120ULL: goto x86_l_3b10;
	case 15122ULL: goto x86_l_3b12;
	case 15128ULL: goto x86_l_3b18;
	case 15133ULL: goto x86_l_3b1d;
	case 15142ULL: goto x86_l_3b26;
	case 15148ULL: goto x86_l_3b2c;
	case 15155ULL: goto x86_l_3b33;
	case 15160ULL: goto x86_l_3b38;
	case 15165ULL: goto x86_l_3b3d;
	case 15174ULL: goto x86_l_3b46;
	case 15180ULL: goto x86_l_3b4c;
	case 15185ULL: goto x86_l_3b51;
	case 15190ULL: goto x86_l_3b56;
	case 15195ULL: goto x86_l_3b5b;
	case 15200ULL: goto x86_l_3b60;
	case 15203ULL: goto x86_l_3b63;
	case 15205ULL: goto x86_l_3b65;
	case 15210ULL: goto x86_l_3b6a;
	case 15215ULL: goto x86_l_3b6f;
	case 15220ULL: goto x86_l_3b74;
	case 15225ULL: goto x86_l_3b79;
	case 15230ULL: goto x86_l_3b7e;
	case 15232ULL: goto x86_l_3b80;
	case 15234ULL: goto x86_l_3b82;
	case 15240ULL: goto x86_l_3b88;
	case 15249ULL: goto x86_l_3b91;
	case 15255ULL: goto x86_l_3b97;
	case 15262ULL: goto x86_l_3b9e;
	case 15267ULL: goto x86_l_3ba3;
	case 15272ULL: goto x86_l_3ba8;
	case 15281ULL: goto x86_l_3bb1;
	case 15283ULL: goto x86_l_3bb3;
	case 15288ULL: goto x86_l_3bb8;
	case 15293ULL: goto x86_l_3bbd;
	case 15298ULL: goto x86_l_3bc2;
	case 15303ULL: goto x86_l_3bc7;
	case 15308ULL: goto x86_l_3bcc;
	case 15310ULL: goto x86_l_3bce;
	case 15312ULL: goto x86_l_3bd0;
	case 15318ULL: goto x86_l_3bd6;
	case 15327ULL: goto x86_l_3bdf;
	case 15333ULL: goto x86_l_3be5;
	case 15340ULL: goto x86_l_3bec;
	case 15345ULL: goto x86_l_3bf1;
	case 15350ULL: goto x86_l_3bf6;
	case 15359ULL: goto x86_l_3bff;
	case 15361ULL: goto x86_l_3c01;
	case 15366ULL: goto x86_l_3c06;
	case 15371ULL: goto x86_l_3c0b;
	case 15376ULL: goto x86_l_3c10;
	case 15381ULL: goto x86_l_3c15;
	case 15386ULL: goto x86_l_3c1a;
	case 15388ULL: goto x86_l_3c1c;
	case 15390ULL: goto x86_l_3c1e;
	case 15396ULL: goto x86_l_3c24;
	case 15405ULL: goto x86_l_3c2d;
	case 15411ULL: goto x86_l_3c33;
	case 15418ULL: goto x86_l_3c3a;
	case 15423ULL: goto x86_l_3c3f;
	case 15428ULL: goto x86_l_3c44;
	case 15437ULL: goto x86_l_3c4d;
	case 15439ULL: goto x86_l_3c4f;
	case 15444ULL: goto x86_l_3c54;
	case 15449ULL: goto x86_l_3c59;
	case 15454ULL: goto x86_l_3c5e;
	case 15459ULL: goto x86_l_3c63;
	case 15464ULL: goto x86_l_3c68;
	case 15466ULL: goto x86_l_3c6a;
	case 15468ULL: goto x86_l_3c6c;
	case 15474ULL: goto x86_l_3c72;
	case 15483ULL: goto x86_l_3c7b;
	case 15489ULL: goto x86_l_3c81;
	case 15496ULL: goto x86_l_3c88;
	case 15501ULL: goto x86_l_3c8d;
	case 15506ULL: goto x86_l_3c92;
	case 15515ULL: goto x86_l_3c9b;
	case 15517ULL: goto x86_l_3c9d;
	case 15522ULL: goto x86_l_3ca2;
	case 15527ULL: goto x86_l_3ca7;
	case 15532ULL: goto x86_l_3cac;
	case 15537ULL: goto x86_l_3cb1;
	case 15542ULL: goto x86_l_3cb6;
	case 15544ULL: goto x86_l_3cb8;
	case 15546ULL: goto x86_l_3cba;
	case 15552ULL: goto x86_l_3cc0;
	case 15561ULL: goto x86_l_3cc9;
	case 15567ULL: goto x86_l_3ccf;
	case 15574ULL: goto x86_l_3cd6;
	case 15579ULL: goto x86_l_3cdb;
	case 15584ULL: goto x86_l_3ce0;
	case 15593ULL: goto x86_l_3ce9;
	case 15595ULL: goto x86_l_3ceb;
	case 15600ULL: goto x86_l_3cf0;
	case 15605ULL: goto x86_l_3cf5;
	case 15610ULL: goto x86_l_3cfa;
	case 15615ULL: goto x86_l_3cff;
	case 15620ULL: goto x86_l_3d04;
	case 15622ULL: goto x86_l_3d06;
	case 15624ULL: goto x86_l_3d08;
	case 15630ULL: goto x86_l_3d0e;
	case 15639ULL: goto x86_l_3d17;
	case 15645ULL: goto x86_l_3d1d;
	case 15652ULL: goto x86_l_3d24;
	case 15657ULL: goto x86_l_3d29;
	case 15662ULL: goto x86_l_3d2e;
	case 15671ULL: goto x86_l_3d37;
	case 15673ULL: goto x86_l_3d39;
	case 15678ULL: goto x86_l_3d3e;
	case 15683ULL: goto x86_l_3d43;
	case 15688ULL: goto x86_l_3d48;
	case 15693ULL: goto x86_l_3d4d;
	case 15698ULL: goto x86_l_3d52;
	case 15700ULL: goto x86_l_3d54;
	case 15702ULL: goto x86_l_3d56;
	case 15708ULL: goto x86_l_3d5c;
	case 15717ULL: goto x86_l_3d65;
	case 15723ULL: goto x86_l_3d6b;
	case 15730ULL: goto x86_l_3d72;
	case 15735ULL: goto x86_l_3d77;
	case 15740ULL: goto x86_l_3d7c;
	case 15749ULL: goto x86_l_3d85;
	case 15751ULL: goto x86_l_3d87;
	case 15756ULL: goto x86_l_3d8c;
	case 15761ULL: goto x86_l_3d91;
	case 15766ULL: goto x86_l_3d96;
	case 15771ULL: goto x86_l_3d9b;
	case 15776ULL: goto x86_l_3da0;
	case 15778ULL: goto x86_l_3da2;
	case 15780ULL: goto x86_l_3da4;
	case 15786ULL: goto x86_l_3daa;
	case 15791ULL: goto x86_l_3daf;
	case 15800ULL: goto x86_l_3db8;
	case 15806ULL: goto x86_l_3dbe;
	case 15813ULL: goto x86_l_3dc5;
	case 15818ULL: goto x86_l_3dca;
	case 15823ULL: goto x86_l_3dcf;
	case 15832ULL: goto x86_l_3dd8;
	case 15834ULL: goto x86_l_3dda;
	case 15839ULL: goto x86_l_3ddf;
	case 15844ULL: goto x86_l_3de4;
	case 15849ULL: goto x86_l_3de9;
	case 15854ULL: goto x86_l_3dee;
	case 15859ULL: goto x86_l_3df3;
	case 15861ULL: goto x86_l_3df5;
	case 15863ULL: goto x86_l_3df7;
	case 15869ULL: goto x86_l_3dfd;
	case 15874ULL: goto x86_l_3e02;
	case 15883ULL: goto x86_l_3e0b;
	case 15889ULL: goto x86_l_3e11;
	case 15896ULL: goto x86_l_3e18;
	case 15901ULL: goto x86_l_3e1d;
	case 15906ULL: goto x86_l_3e22;
	case 15915ULL: goto x86_l_3e2b;
	case 15921ULL: goto x86_l_3e31;
	case 15926ULL: goto x86_l_3e36;
	case 15931ULL: goto x86_l_3e3b;
	case 15936ULL: goto x86_l_3e40;
	case 15941ULL: goto x86_l_3e45;
	case 15946ULL: goto x86_l_3e4a;
	case 15948ULL: goto x86_l_3e4c;
	case 15950ULL: goto x86_l_3e4e;
	case 15956ULL: goto x86_l_3e54;
	case 15961ULL: goto x86_l_3e59;
	case 15966ULL: goto x86_l_3e5e;
	case 15971ULL: goto x86_l_3e63;
	case 15976ULL: goto x86_l_3e68;
	case 15981ULL: goto x86_l_3e6d;
	case 15986ULL: goto x86_l_3e72;
	case 15991ULL: goto x86_l_3e77;
	case 15996ULL: goto x86_l_3e7c;
	case 16001ULL: goto x86_l_3e81;
	case 16006ULL: goto x86_l_3e86;
	case 16011ULL: goto x86_l_3e8b;
	case 16016ULL: goto x86_l_3e90;
	case 16024ULL: goto x86_l_3e98;
	case 16027ULL: goto x86_l_3e9b;
	case 16033ULL: goto x86_l_3ea1;
	case 16038ULL: goto x86_l_3ea6;
	case 16041ULL: goto x86_l_3ea9;
	case 16047ULL: goto x86_l_3eaf;
	case 16052ULL: goto x86_l_3eb4;
	case 16060ULL: goto x86_l_3ebc;
	case 16063ULL: goto x86_l_3ebf;
	case 16069ULL: goto x86_l_3ec5;
	case 16074ULL: goto x86_l_3eca;
	case 16077ULL: goto x86_l_3ecd;
	case 16083ULL: goto x86_l_3ed3;
	case 16088ULL: goto x86_l_3ed8;
	case 16096ULL: goto x86_l_3ee0;
	case 16099ULL: goto x86_l_3ee3;
	case 16105ULL: goto x86_l_3ee9;
	case 16110ULL: goto x86_l_3eee;
	case 16113ULL: goto x86_l_3ef1;
	case 16119ULL: goto x86_l_3ef7;
	case 16124ULL: goto x86_l_3efc;
	case 16132ULL: goto x86_l_3f04;
	case 16135ULL: goto x86_l_3f07;
	case 16141ULL: goto x86_l_3f0d;
	case 16146ULL: goto x86_l_3f12;
	case 16149ULL: goto x86_l_3f15;
	case 16155ULL: goto x86_l_3f1b;
	case 16160ULL: goto x86_l_3f20;
	case 16168ULL: goto x86_l_3f28;
	case 16171ULL: goto x86_l_3f2b;
	case 16177ULL: goto x86_l_3f31;
	case 16182ULL: goto x86_l_3f36;
	case 16185ULL: goto x86_l_3f39;
	case 16191ULL: goto x86_l_3f3f;
	case 16196ULL: goto x86_l_3f44;
	case 16204ULL: goto x86_l_3f4c;
	case 16207ULL: goto x86_l_3f4f;
	case 16213ULL: goto x86_l_3f55;
	case 16218ULL: goto x86_l_3f5a;
	case 16221ULL: goto x86_l_3f5d;
	case 16227ULL: goto x86_l_3f63;
	case 16232ULL: goto x86_l_3f68;
	case 16240ULL: goto x86_l_3f70;
	case 16243ULL: goto x86_l_3f73;
	case 16249ULL: goto x86_l_3f79;
	case 16254ULL: goto x86_l_3f7e;
	case 16257ULL: goto x86_l_3f81;
	case 16263ULL: goto x86_l_3f87;
	case 16268ULL: goto x86_l_3f8c;
	case 16276ULL: goto x86_l_3f94;
	case 16279ULL: goto x86_l_3f97;
	case 16285ULL: goto x86_l_3f9d;
	case 16290ULL: goto x86_l_3fa2;
	case 16293ULL: goto x86_l_3fa5;
	case 16299ULL: goto x86_l_3fab;
	case 16304ULL: goto x86_l_3fb0;
	case 16312ULL: goto x86_l_3fb8;
	case 16315ULL: goto x86_l_3fbb;
	case 16321ULL: goto x86_l_3fc1;
	case 16326ULL: goto x86_l_3fc6;
	case 16329ULL: goto x86_l_3fc9;
	case 16335ULL: goto x86_l_3fcf;
	case 16340ULL: goto x86_l_3fd4;
	case 16348ULL: goto x86_l_3fdc;
	case 16351ULL: goto x86_l_3fdf;
	case 16357ULL: goto x86_l_3fe5;
	case 16362ULL: goto x86_l_3fea;
	case 16365ULL: goto x86_l_3fed;
	case 16371ULL: goto x86_l_3ff3;
	case 16376ULL: goto x86_l_3ff8;
	case 16384ULL: goto x86_l_4000;
	case 16387ULL: goto x86_l_4003;
	case 16393ULL: goto x86_l_4009;
	case 16398ULL: goto x86_l_400e;
	case 16401ULL: goto x86_l_4011;
	case 16407ULL: goto x86_l_4017;
	case 16412ULL: goto x86_l_401c;
	case 16420ULL: goto x86_l_4024;
	case 16423ULL: goto x86_l_4027;
	case 16429ULL: goto x86_l_402d;
	case 16434ULL: goto x86_l_4032;
	case 16437ULL: goto x86_l_4035;
	case 16443ULL: goto x86_l_403b;
	case 16448ULL: goto x86_l_4040;
	case 16456ULL: goto x86_l_4048;
	case 16459ULL: goto x86_l_404b;
	case 16465ULL: goto x86_l_4051;
	case 16470ULL: goto x86_l_4056;
	case 16473ULL: goto x86_l_4059;
	case 16479ULL: goto x86_l_405f;
	case 16484ULL: goto x86_l_4064;
	case 16492ULL: goto x86_l_406c;
	case 16495ULL: goto x86_l_406f;
	case 16501ULL: goto x86_l_4075;
	case 16506ULL: goto x86_l_407a;
	case 16509ULL: goto x86_l_407d;
	case 16515ULL: goto x86_l_4083;
	case 16520ULL: goto x86_l_4088;
	case 16528ULL: goto x86_l_4090;
	case 16531ULL: goto x86_l_4093;
	case 16537ULL: goto x86_l_4099;
	case 16542ULL: goto x86_l_409e;
	case 16545ULL: goto x86_l_40a1;
	case 16551ULL: goto x86_l_40a7;
	case 16556ULL: goto x86_l_40ac;
	case 16564ULL: goto x86_l_40b4;
	case 16567ULL: goto x86_l_40b7;
	case 16569ULL: goto x86_l_40b9;
	case 16574ULL: goto x86_l_40be;
	case 16577ULL: goto x86_l_40c1;
	case 16579ULL: goto x86_l_40c3;
	case 16582ULL: goto x86_l_40c6;
	case 16584ULL: goto x86_l_40c8;
	case 16586ULL: goto x86_l_40ca;
	case 16591ULL: goto x86_l_40cf;
	case 16593ULL: goto x86_l_40d1;
	case 16598ULL: goto x86_l_40d6;
	case 16603ULL: goto x86_l_40db;
	case 16607ULL: goto x86_l_40df;
	case 16609ULL: goto x86_l_40e1;
	case 16612ULL: goto x86_l_40e4;
	case 16618ULL: goto x86_l_40ea;
	case 16624ULL: goto x86_l_40f0;
	case 16631ULL: goto x86_l_40f7;
	case 16634ULL: goto x86_l_40fa;
	case 16638ULL: goto x86_l_40fe;
	case 16641ULL: goto x86_l_4101;
	case 16646ULL: goto x86_l_4106;
	case 16651ULL: goto x86_l_410b;
	case 16653ULL: goto x86_l_410d;
	case 16659ULL: goto x86_l_4113;
	case 16662ULL: goto x86_l_4116;
	case 16664ULL: goto x86_l_4118;
	case 16669ULL: goto x86_l_411d;
	case 16674ULL: goto x86_l_4122;
	case 16679ULL: goto x86_l_4127;
	case 16684ULL: goto x86_l_412c;
	case 16689ULL: goto x86_l_4131;
	case 16691ULL: goto x86_l_4133;
	case 16693ULL: goto x86_l_4135;
	case 16699ULL: goto x86_l_413b;
	case 16705ULL: goto x86_l_4141;
	case 16711ULL: goto x86_l_4147;
	case 16715ULL: goto x86_l_414b;
	case 16720ULL: goto x86_l_4150;
	case 16725ULL: goto x86_l_4155;
	case 16731ULL: goto x86_l_415b;
	case 16733ULL: goto x86_l_415d;
	case 16738ULL: goto x86_l_4162;
	case 16743ULL: goto x86_l_4167;
	case 16748ULL: goto x86_l_416c;
	case 16753ULL: goto x86_l_4171;
	case 16758ULL: goto x86_l_4176;
	case 16760ULL: goto x86_l_4178;
	case 16762ULL: goto x86_l_417a;
	case 16768ULL: goto x86_l_4180;
	case 16777ULL: goto x86_l_4189;
	case 16783ULL: goto x86_l_418f;
	case 16790ULL: goto x86_l_4196;
	case 16795ULL: goto x86_l_419b;
	case 16800ULL: goto x86_l_41a0;
	case 16809ULL: goto x86_l_41a9;
	case 16811ULL: goto x86_l_41ab;
	case 16816ULL: goto x86_l_41b0;
	case 16821ULL: goto x86_l_41b5;
	case 16826ULL: goto x86_l_41ba;
	case 16831ULL: goto x86_l_41bf;
	case 16836ULL: goto x86_l_41c4;
	case 16838ULL: goto x86_l_41c6;
	case 16840ULL: goto x86_l_41c8;
	case 16846ULL: goto x86_l_41ce;
	case 16855ULL: goto x86_l_41d7;
	case 16861ULL: goto x86_l_41dd;
	case 16868ULL: goto x86_l_41e4;
	case 16873ULL: goto x86_l_41e9;
	case 16878ULL: goto x86_l_41ee;
	case 16887ULL: goto x86_l_41f7;
	case 16889ULL: goto x86_l_41f9;
	case 16894ULL: goto x86_l_41fe;
	case 16899ULL: goto x86_l_4203;
	case 16904ULL: goto x86_l_4208;
	case 16909ULL: goto x86_l_420d;
	case 16914ULL: goto x86_l_4212;
	case 16916ULL: goto x86_l_4214;
	case 16918ULL: goto x86_l_4216;
	case 16924ULL: goto x86_l_421c;
	case 16933ULL: goto x86_l_4225;
	case 16939ULL: goto x86_l_422b;
	case 16946ULL: goto x86_l_4232;
	case 16951ULL: goto x86_l_4237;
	case 16956ULL: goto x86_l_423c;
	case 16965ULL: goto x86_l_4245;
	case 16967ULL: goto x86_l_4247;
	case 16972ULL: goto x86_l_424c;
	case 16977ULL: goto x86_l_4251;
	case 16982ULL: goto x86_l_4256;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3ac4:
	/* 0x3ac4: js     68f3 <generic_sleepable_preload+0x68f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26867ULL;
	}
x86_l_3aca:
	/* 0x3aca: cmp    WORD PTR [r13+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_3ad3:
	/* 0x3ad3: je     64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25775ULL;
	}
x86_l_3ad9:
	/* 0x3ad9: mov    ecx,DWORD PTR [r13+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_3ae0:
	/* 0x3ae0: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3ae5:
	/* 0x3ae5: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3aea:
	/* 0x3aea: cmp    WORD PTR [r13+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_3af3:
	/* 0x3af3: je     3b18 <generic_sleepable_preload+0x3b18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b18;
	}
x86_l_3af5:
	/* 0x3af5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3afa:
	/* 0x3afa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3aff:
	/* 0x3aff: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b04:
	/* 0x3b04: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b09:
	/* 0x3b09: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b0e:
	/* 0x3b0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b10:
	/* 0x3b10: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b12:
	/* 0x3b12: js     696a <generic_sleepable_preload+0x696a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26986ULL;
	}
x86_l_3b18:
	/* 0x3b18: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3b1d:
	/* 0x3b1d: cmp    WORD PTR [r13+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_3b26:
	/* 0x3b26: je     64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25775ULL;
	}
x86_l_3b2c:
	/* 0x3b2c: mov    ecx,DWORD PTR [r13+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_3b33:
	/* 0x3b33: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3b38:
	/* 0x3b38: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b3d:
	/* 0x3b3d: cmp    WORD PTR [r13+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_3b46:
	/* 0x3b46: je     64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25775ULL;
	}
x86_l_3b4c:
	/* 0x3b4c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b51:
	/* 0x3b51: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3b56:
	/* 0x3b56: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b5b:
	/* 0x3b5b: jmp    3e40 <generic_sleepable_preload+0x3e40> */
	goto x86_l_3e40;
x86_l_3b60:
	/* 0x3b60: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3b63:
	/* 0x3b63: je     3b88 <generic_sleepable_preload+0x3b88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b88;
	}
x86_l_3b65:
	/* 0x3b65: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b6a:
	/* 0x3b6a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3b6f:
	/* 0x3b6f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b74:
	/* 0x3b74: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b79:
	/* 0x3b79: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b7e:
	/* 0x3b7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b80:
	/* 0x3b80: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b82:
	/* 0x3b82: js     3e86 <generic_sleepable_preload+0x3e86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3e86;
	}
x86_l_3b88:
	/* 0x3b88: cmp    WORD PTR [r13+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_3b91:
	/* 0x3b91: je     64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25775ULL;
	}
x86_l_3b97:
	/* 0x3b97: mov    ecx,DWORD PTR [r13+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_3b9e:
	/* 0x3b9e: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3ba3:
	/* 0x3ba3: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ba8:
	/* 0x3ba8: cmp    WORD PTR [r13+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_3bb1:
	/* 0x3bb1: je     3bd6 <generic_sleepable_preload+0x3bd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bd6;
	}
x86_l_3bb3:
	/* 0x3bb3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bb8:
	/* 0x3bb8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3bbd:
	/* 0x3bbd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3bc2:
	/* 0x3bc2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bc7:
	/* 0x3bc7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bcc:
	/* 0x3bcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bce:
	/* 0x3bce: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3bd0:
	/* 0x3bd0: js     5427 <generic_sleepable_preload+0x5427> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21543ULL;
	}
x86_l_3bd6:
	/* 0x3bd6: cmp    WORD PTR [r13+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_3bdf:
	/* 0x3bdf: je     64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25775ULL;
	}
x86_l_3be5:
	/* 0x3be5: mov    ecx,DWORD PTR [r13+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_3bec:
	/* 0x3bec: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3bf1:
	/* 0x3bf1: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bf6:
	/* 0x3bf6: cmp    WORD PTR [r13+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_3bff:
	/* 0x3bff: je     3c24 <generic_sleepable_preload+0x3c24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c24;
	}
x86_l_3c01:
	/* 0x3c01: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c06:
	/* 0x3c06: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3c0b:
	/* 0x3c0b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3c10:
	/* 0x3c10: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c15:
	/* 0x3c15: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c1a:
	/* 0x3c1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c1c:
	/* 0x3c1c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c1e:
	/* 0x3c1e: js     610e <generic_sleepable_preload+0x610e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24846ULL;
	}
x86_l_3c24:
	/* 0x3c24: cmp    WORD PTR [r13+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_3c2d:
	/* 0x3c2d: je     64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25775ULL;
	}
x86_l_3c33:
	/* 0x3c33: mov    ecx,DWORD PTR [r13+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_3c3a:
	/* 0x3c3a: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3c3f:
	/* 0x3c3f: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c44:
	/* 0x3c44: cmp    WORD PTR [r13+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_3c4d:
	/* 0x3c4d: je     3c72 <generic_sleepable_preload+0x3c72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c72;
	}
x86_l_3c4f:
	/* 0x3c4f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c54:
	/* 0x3c54: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3c59:
	/* 0x3c59: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3c5e:
	/* 0x3c5e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c63:
	/* 0x3c63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c68:
	/* 0x3c68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c6a:
	/* 0x3c6a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c6c:
	/* 0x3c6c: js     6172 <generic_sleepable_preload+0x6172> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24946ULL;
	}
x86_l_3c72:
	/* 0x3c72: cmp    WORD PTR [r13+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_3c7b:
	/* 0x3c7b: je     64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25775ULL;
	}
x86_l_3c81:
	/* 0x3c81: mov    ecx,DWORD PTR [r13+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_3c88:
	/* 0x3c88: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3c8d:
	/* 0x3c8d: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c92:
	/* 0x3c92: cmp    WORD PTR [r13+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_3c9b:
	/* 0x3c9b: je     3cc0 <generic_sleepable_preload+0x3cc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cc0;
	}
x86_l_3c9d:
	/* 0x3c9d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ca2:
	/* 0x3ca2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3ca7:
	/* 0x3ca7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3cac:
	/* 0x3cac: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cb1:
	/* 0x3cb1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cb6:
	/* 0x3cb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cb8:
	/* 0x3cb8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3cba:
	/* 0x3cba: js     61d6 <generic_sleepable_preload+0x61d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25046ULL;
	}
x86_l_3cc0:
	/* 0x3cc0: cmp    WORD PTR [r13+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_3cc9:
	/* 0x3cc9: je     64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25775ULL;
	}
x86_l_3ccf:
	/* 0x3ccf: mov    ecx,DWORD PTR [r13+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_3cd6:
	/* 0x3cd6: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3cdb:
	/* 0x3cdb: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ce0:
	/* 0x3ce0: cmp    WORD PTR [r13+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_3ce9:
	/* 0x3ce9: je     3d0e <generic_sleepable_preload+0x3d0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d0e;
	}
x86_l_3ceb:
	/* 0x3ceb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cf0:
	/* 0x3cf0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3cf5:
	/* 0x3cf5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3cfa:
	/* 0x3cfa: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cff:
	/* 0x3cff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d04:
	/* 0x3d04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d06:
	/* 0x3d06: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d08:
	/* 0x3d08: js     6237 <generic_sleepable_preload+0x6237> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25143ULL;
	}
x86_l_3d0e:
	/* 0x3d0e: cmp    WORD PTR [r13+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_3d17:
	/* 0x3d17: je     64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25775ULL;
	}
x86_l_3d1d:
	/* 0x3d1d: mov    ecx,DWORD PTR [r13+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_3d24:
	/* 0x3d24: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3d29:
	/* 0x3d29: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d2e:
	/* 0x3d2e: cmp    WORD PTR [r13+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_3d37:
	/* 0x3d37: je     3d5c <generic_sleepable_preload+0x3d5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d5c;
	}
x86_l_3d39:
	/* 0x3d39: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d3e:
	/* 0x3d3e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3d43:
	/* 0x3d43: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3d48:
	/* 0x3d48: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d4d:
	/* 0x3d4d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d52:
	/* 0x3d52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d54:
	/* 0x3d54: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d56:
	/* 0x3d56: js     64a7 <generic_sleepable_preload+0x64a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25767ULL;
	}
x86_l_3d5c:
	/* 0x3d5c: cmp    WORD PTR [r13+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_3d65:
	/* 0x3d65: je     64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25775ULL;
	}
x86_l_3d6b:
	/* 0x3d6b: mov    ecx,DWORD PTR [r13+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_3d72:
	/* 0x3d72: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3d77:
	/* 0x3d77: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d7c:
	/* 0x3d7c: cmp    WORD PTR [r13+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_3d85:
	/* 0x3d85: je     3daa <generic_sleepable_preload+0x3daa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3daa;
	}
x86_l_3d87:
	/* 0x3d87: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d8c:
	/* 0x3d8c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3d91:
	/* 0x3d91: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3d96:
	/* 0x3d96: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d9b:
	/* 0x3d9b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3da0:
	/* 0x3da0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3da2:
	/* 0x3da2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3da4:
	/* 0x3da4: js     6a0e <generic_sleepable_preload+0x6a0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27150ULL;
	}
x86_l_3daa:
	/* 0x3daa: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3daf:
	/* 0x3daf: cmp    WORD PTR [r13+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_3db8:
	/* 0x3db8: je     64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25775ULL;
	}
x86_l_3dbe:
	/* 0x3dbe: mov    ecx,DWORD PTR [r13+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_3dc5:
	/* 0x3dc5: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3dca:
	/* 0x3dca: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3dcf:
	/* 0x3dcf: cmp    WORD PTR [r13+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_3dd8:
	/* 0x3dd8: je     3dfd <generic_sleepable_preload+0x3dfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3dfd;
	}
x86_l_3dda:
	/* 0x3dda: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ddf:
	/* 0x3ddf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3de4:
	/* 0x3de4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3de9:
	/* 0x3de9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3dee:
	/* 0x3dee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3df3:
	/* 0x3df3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3df5:
	/* 0x3df5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3df7:
	/* 0x3df7: js     696a <generic_sleepable_preload+0x696a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26986ULL;
	}
x86_l_3dfd:
	/* 0x3dfd: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3e02:
	/* 0x3e02: cmp    WORD PTR [r13+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_3e0b:
	/* 0x3e0b: je     64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25775ULL;
	}
x86_l_3e11:
	/* 0x3e11: mov    ecx,DWORD PTR [r13+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_3e18:
	/* 0x3e18: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3e1d:
	/* 0x3e1d: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e22:
	/* 0x3e22: cmp    WORD PTR [r13+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_3e2b:
	/* 0x3e2b: je     64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25775ULL;
	}
x86_l_3e31:
	/* 0x3e31: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e36:
	/* 0x3e36: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3e3b:
	/* 0x3e3b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3e40:
	/* 0x3e40: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e45:
	/* 0x3e45: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e4a:
	/* 0x3e4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e4c:
	/* 0x3e4c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3e4e:
	/* 0x3e4e: jns    64af <generic_sleepable_preload+0x64af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25775ULL;
	}
x86_l_3e54:
	/* 0x3e54: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_3e59:
	/* 0x3e59: jmp    64ac <generic_sleepable_preload+0x64ac> */
	return 25772ULL;
x86_l_3e5e:
	/* 0x3e5e: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3e63:
	/* 0x3e63: jmp    6278 <generic_sleepable_preload+0x6278> */
	return 25208ULL;
x86_l_3e68:
	/* 0x3e68: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3e6d:
	/* 0x3e6d: jmp    6305 <generic_sleepable_preload+0x6305> */
	return 25349ULL;
x86_l_3e72:
	/* 0x3e72: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3e77:
	/* 0x3e77: jmp    6392 <generic_sleepable_preload+0x6392> */
	return 25490ULL;
x86_l_3e7c:
	/* 0x3e7c: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3e81:
	/* 0x3e81: jmp    641f <generic_sleepable_preload+0x641f> */
	return 25631ULL;
x86_l_3e86:
	/* 0x3e86: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_3e8b:
	/* 0x3e8b: jmp    64ac <generic_sleepable_preload+0x64ac> */
	return 25772ULL;
x86_l_3e90:
	/* 0x3e90: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3e98:
	/* 0x3e98: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_3e9b:
	/* 0x3e9b: je     40c3 <generic_sleepable_preload+0x40c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40c3;
	}
x86_l_3ea1:
	/* 0x3ea1: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3ea6:
	/* 0x3ea6: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3ea9:
	/* 0x3ea9: je     40c3 <generic_sleepable_preload+0x40c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40c3;
	}
x86_l_3eaf:
	/* 0x3eaf: jmp    40d6 <generic_sleepable_preload+0x40d6> */
	goto x86_l_40d6;
x86_l_3eb4:
	/* 0x3eb4: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3ebc:
	/* 0x3ebc: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_3ebf:
	/* 0x3ebf: je     5452 <generic_sleepable_preload+0x5452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21586ULL;
	}
x86_l_3ec5:
	/* 0x3ec5: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3eca:
	/* 0x3eca: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3ecd:
	/* 0x3ecd: je     5452 <generic_sleepable_preload+0x5452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21586ULL;
	}
x86_l_3ed3:
	/* 0x3ed3: jmp    5465 <generic_sleepable_preload+0x5465> */
	return 21605ULL;
x86_l_3ed8:
	/* 0x3ed8: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3ee0:
	/* 0x3ee0: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_3ee3:
	/* 0x3ee3: je     4733 <generic_sleepable_preload+0x4733> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18227ULL;
	}
x86_l_3ee9:
	/* 0x3ee9: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3eee:
	/* 0x3eee: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3ef1:
	/* 0x3ef1: je     4733 <generic_sleepable_preload+0x4733> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18227ULL;
	}
x86_l_3ef7:
	/* 0x3ef7: jmp    4746 <generic_sleepable_preload+0x4746> */
	return 18246ULL;
x86_l_3efc:
	/* 0x3efc: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3f04:
	/* 0x3f04: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_3f07:
	/* 0x3f07: je     4d9a <generic_sleepable_preload+0x4d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19866ULL;
	}
x86_l_3f0d:
	/* 0x3f0d: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3f12:
	/* 0x3f12: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3f15:
	/* 0x3f15: je     4d9a <generic_sleepable_preload+0x4d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19866ULL;
	}
x86_l_3f1b:
	/* 0x3f1b: jmp    4dad <generic_sleepable_preload+0x4dad> */
	return 19885ULL;
x86_l_3f20:
	/* 0x3f20: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3f28:
	/* 0x3f28: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_3f2b:
	/* 0x3f2b: je     5aa2 <generic_sleepable_preload+0x5aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23202ULL;
	}
x86_l_3f31:
	/* 0x3f31: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3f36:
	/* 0x3f36: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3f39:
	/* 0x3f39: je     5aa2 <generic_sleepable_preload+0x5aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23202ULL;
	}
x86_l_3f3f:
	/* 0x3f3f: jmp    5ab5 <generic_sleepable_preload+0x5ab5> */
	return 23221ULL;
x86_l_3f44:
	/* 0x3f44: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3f4c:
	/* 0x3f4c: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3f4f:
	/* 0x3f4f: je     40c3 <generic_sleepable_preload+0x40c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40c3;
	}
x86_l_3f55:
	/* 0x3f55: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3f5a:
	/* 0x3f5a: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3f5d:
	/* 0x3f5d: je     40c3 <generic_sleepable_preload+0x40c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40c3;
	}
x86_l_3f63:
	/* 0x3f63: jmp    40d6 <generic_sleepable_preload+0x40d6> */
	goto x86_l_40d6;
x86_l_3f68:
	/* 0x3f68: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3f70:
	/* 0x3f70: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3f73:
	/* 0x3f73: je     5452 <generic_sleepable_preload+0x5452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21586ULL;
	}
x86_l_3f79:
	/* 0x3f79: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3f7e:
	/* 0x3f7e: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3f81:
	/* 0x3f81: je     5452 <generic_sleepable_preload+0x5452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21586ULL;
	}
x86_l_3f87:
	/* 0x3f87: jmp    5465 <generic_sleepable_preload+0x5465> */
	return 21605ULL;
x86_l_3f8c:
	/* 0x3f8c: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3f94:
	/* 0x3f94: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3f97:
	/* 0x3f97: je     4733 <generic_sleepable_preload+0x4733> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18227ULL;
	}
x86_l_3f9d:
	/* 0x3f9d: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3fa2:
	/* 0x3fa2: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3fa5:
	/* 0x3fa5: je     4733 <generic_sleepable_preload+0x4733> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18227ULL;
	}
x86_l_3fab:
	/* 0x3fab: jmp    4746 <generic_sleepable_preload+0x4746> */
	return 18246ULL;
x86_l_3fb0:
	/* 0x3fb0: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3fb8:
	/* 0x3fb8: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3fbb:
	/* 0x3fbb: je     4d9a <generic_sleepable_preload+0x4d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19866ULL;
	}
x86_l_3fc1:
	/* 0x3fc1: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3fc6:
	/* 0x3fc6: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3fc9:
	/* 0x3fc9: je     4d9a <generic_sleepable_preload+0x4d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19866ULL;
	}
x86_l_3fcf:
	/* 0x3fcf: jmp    4dad <generic_sleepable_preload+0x4dad> */
	return 19885ULL;
x86_l_3fd4:
	/* 0x3fd4: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3fdc:
	/* 0x3fdc: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3fdf:
	/* 0x3fdf: je     5aa2 <generic_sleepable_preload+0x5aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23202ULL;
	}
x86_l_3fe5:
	/* 0x3fe5: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3fea:
	/* 0x3fea: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3fed:
	/* 0x3fed: je     5aa2 <generic_sleepable_preload+0x5aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23202ULL;
	}
x86_l_3ff3:
	/* 0x3ff3: jmp    5ab5 <generic_sleepable_preload+0x5ab5> */
	return 23221ULL;
x86_l_3ff8:
	/* 0x3ff8: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4000:
	/* 0x4000: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_4003:
	/* 0x4003: je     40c3 <generic_sleepable_preload+0x40c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40c3;
	}
x86_l_4009:
	/* 0x4009: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_400e:
	/* 0x400e: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4011:
	/* 0x4011: je     40c3 <generic_sleepable_preload+0x40c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40c3;
	}
x86_l_4017:
	/* 0x4017: jmp    40d6 <generic_sleepable_preload+0x40d6> */
	goto x86_l_40d6;
x86_l_401c:
	/* 0x401c: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4024:
	/* 0x4024: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_4027:
	/* 0x4027: je     5452 <generic_sleepable_preload+0x5452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21586ULL;
	}
x86_l_402d:
	/* 0x402d: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4032:
	/* 0x4032: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4035:
	/* 0x4035: je     5452 <generic_sleepable_preload+0x5452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21586ULL;
	}
x86_l_403b:
	/* 0x403b: jmp    5465 <generic_sleepable_preload+0x5465> */
	return 21605ULL;
x86_l_4040:
	/* 0x4040: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4048:
	/* 0x4048: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_404b:
	/* 0x404b: je     4733 <generic_sleepable_preload+0x4733> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18227ULL;
	}
x86_l_4051:
	/* 0x4051: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4056:
	/* 0x4056: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4059:
	/* 0x4059: je     4733 <generic_sleepable_preload+0x4733> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18227ULL;
	}
x86_l_405f:
	/* 0x405f: jmp    4746 <generic_sleepable_preload+0x4746> */
	return 18246ULL;
x86_l_4064:
	/* 0x4064: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_406c:
	/* 0x406c: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_406f:
	/* 0x406f: je     4d9a <generic_sleepable_preload+0x4d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19866ULL;
	}
x86_l_4075:
	/* 0x4075: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_407a:
	/* 0x407a: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_407d:
	/* 0x407d: je     4d9a <generic_sleepable_preload+0x4d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19866ULL;
	}
x86_l_4083:
	/* 0x4083: jmp    4dad <generic_sleepable_preload+0x4dad> */
	return 19885ULL;
x86_l_4088:
	/* 0x4088: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4090:
	/* 0x4090: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_4093:
	/* 0x4093: je     5aa2 <generic_sleepable_preload+0x5aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23202ULL;
	}
x86_l_4099:
	/* 0x4099: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_409e:
	/* 0x409e: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_40a1:
	/* 0x40a1: je     5aa2 <generic_sleepable_preload+0x5aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23202ULL;
	}
x86_l_40a7:
	/* 0x40a7: jmp    5ab5 <generic_sleepable_preload+0x5ab5> */
	return 23221ULL;
x86_l_40ac:
	/* 0x40ac: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_40b4:
	/* 0x40b4: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_40b7:
	/* 0x40b7: je     40c3 <generic_sleepable_preload+0x40c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40c3;
	}
x86_l_40b9:
	/* 0x40b9: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_40be:
	/* 0x40be: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_40c1:
	/* 0x40c1: jne    40d6 <generic_sleepable_preload+0x40d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_40d6;
	}
x86_l_40c3:
	/* 0x40c3: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_40c6:
	/* 0x40c6: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_40c8:
	/* 0x40c8: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_40ca:
	/* 0x40ca: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_40cf:
	/* 0x40cf: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_40d1:
	/* 0x40d1: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_40d6:
	/* 0x40d6: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40db:
	/* 0x40db: mov    r14d,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_40df:
	/* 0x40df: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_40e1:
	/* 0x40e1: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_40e4:
	/* 0x40e4: cmp    WORD PTR [r13+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_40ea:
	/* 0x40ea: je     653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25915ULL;
	}
x86_l_40f0:
	/* 0x40f0: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_40f7:
	/* 0x40f7: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_40fa:
	/* 0x40fa: mov    eax,DWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_40fe:
	/* 0x40fe: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4101:
	/* 0x4101: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4106:
	/* 0x4106: movzx  eax,WORD PTR [r13+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_410b:
	/* 0x410b: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_410d:
	/* 0x410d: je     43ef <generic_sleepable_preload+0x43ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17391ULL;
	}
x86_l_4113:
	/* 0x4113: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4116:
	/* 0x4116: je     413b <generic_sleepable_preload+0x413b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_413b;
	}
x86_l_4118:
	/* 0x4118: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_411d:
	/* 0x411d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4122:
	/* 0x4122: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4127:
	/* 0x4127: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_412c:
	/* 0x412c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4131:
	/* 0x4131: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4133:
	/* 0x4133: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4135:
	/* 0x4135: js     46ee <generic_sleepable_preload+0x46ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 18158ULL;
	}
x86_l_413b:
	/* 0x413b: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_4141:
	/* 0x4141: je     653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25915ULL;
	}
x86_l_4147:
	/* 0x4147: mov    ecx,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_414b:
	/* 0x414b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4150:
	/* 0x4150: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4155:
	/* 0x4155: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_415b:
	/* 0x415b: je     4180 <generic_sleepable_preload+0x4180> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4180;
	}
x86_l_415d:
	/* 0x415d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4162:
	/* 0x4162: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4167:
	/* 0x4167: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_416c:
	/* 0x416c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4171:
	/* 0x4171: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4176:
	/* 0x4176: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4178:
	/* 0x4178: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_417a:
	/* 0x417a: js     5431 <generic_sleepable_preload+0x5431> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21553ULL;
	}
x86_l_4180:
	/* 0x4180: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_4189:
	/* 0x4189: je     653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25915ULL;
	}
x86_l_418f:
	/* 0x418f: mov    ecx,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4196:
	/* 0x4196: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_419b:
	/* 0x419b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41a0:
	/* 0x41a0: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_41a9:
	/* 0x41a9: je     41ce <generic_sleepable_preload+0x41ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41ce;
	}
x86_l_41ab:
	/* 0x41ab: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41b0:
	/* 0x41b0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_41b5:
	/* 0x41b5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_41ba:
	/* 0x41ba: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41bf:
	/* 0x41bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41c4:
	/* 0x41c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41c6:
	/* 0x41c6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_41c8:
	/* 0x41c8: js     6118 <generic_sleepable_preload+0x6118> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24856ULL;
	}
x86_l_41ce:
	/* 0x41ce: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_41d7:
	/* 0x41d7: je     653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25915ULL;
	}
x86_l_41dd:
	/* 0x41dd: mov    ecx,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_41e4:
	/* 0x41e4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_41e9:
	/* 0x41e9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41ee:
	/* 0x41ee: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_41f7:
	/* 0x41f7: je     421c <generic_sleepable_preload+0x421c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_421c;
	}
x86_l_41f9:
	/* 0x41f9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41fe:
	/* 0x41fe: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4203:
	/* 0x4203: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4208:
	/* 0x4208: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_420d:
	/* 0x420d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4212:
	/* 0x4212: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4214:
	/* 0x4214: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4216:
	/* 0x4216: js     617c <generic_sleepable_preload+0x617c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24956ULL;
	}
x86_l_421c:
	/* 0x421c: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_4225:
	/* 0x4225: je     653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25915ULL;
	}
x86_l_422b:
	/* 0x422b: mov    ecx,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4232:
	/* 0x4232: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4237:
	/* 0x4237: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_423c:
	/* 0x423c: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_4245:
	/* 0x4245: je     426a <generic_sleepable_preload+0x426a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17002ULL;
	}
x86_l_4247:
	/* 0x4247: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_424c:
	/* 0x424c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4251:
	/* 0x4251: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4256:
	/* 0x4256: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 16987ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 16987ULL: goto x86_l_425b;
	case 16992ULL: goto x86_l_4260;
	case 16994ULL: goto x86_l_4262;
	case 16996ULL: goto x86_l_4264;
	case 17002ULL: goto x86_l_426a;
	case 17011ULL: goto x86_l_4273;
	case 17017ULL: goto x86_l_4279;
	case 17024ULL: goto x86_l_4280;
	case 17029ULL: goto x86_l_4285;
	case 17034ULL: goto x86_l_428a;
	case 17043ULL: goto x86_l_4293;
	case 17045ULL: goto x86_l_4295;
	case 17050ULL: goto x86_l_429a;
	case 17055ULL: goto x86_l_429f;
	case 17060ULL: goto x86_l_42a4;
	case 17065ULL: goto x86_l_42a9;
	case 17070ULL: goto x86_l_42ae;
	case 17072ULL: goto x86_l_42b0;
	case 17074ULL: goto x86_l_42b2;
	case 17080ULL: goto x86_l_42b8;
	case 17089ULL: goto x86_l_42c1;
	case 17095ULL: goto x86_l_42c7;
	case 17102ULL: goto x86_l_42ce;
	case 17107ULL: goto x86_l_42d3;
	case 17112ULL: goto x86_l_42d8;
	case 17121ULL: goto x86_l_42e1;
	case 17123ULL: goto x86_l_42e3;
	case 17128ULL: goto x86_l_42e8;
	case 17133ULL: goto x86_l_42ed;
	case 17138ULL: goto x86_l_42f2;
	case 17143ULL: goto x86_l_42f7;
	case 17148ULL: goto x86_l_42fc;
	case 17150ULL: goto x86_l_42fe;
	case 17152ULL: goto x86_l_4300;
	case 17158ULL: goto x86_l_4306;
	case 17167ULL: goto x86_l_430f;
	case 17173ULL: goto x86_l_4315;
	case 17180ULL: goto x86_l_431c;
	case 17185ULL: goto x86_l_4321;
	case 17190ULL: goto x86_l_4326;
	case 17199ULL: goto x86_l_432f;
	case 17201ULL: goto x86_l_4331;
	case 17206ULL: goto x86_l_4336;
	case 17211ULL: goto x86_l_433b;
	case 17216ULL: goto x86_l_4340;
	case 17221ULL: goto x86_l_4345;
	case 17226ULL: goto x86_l_434a;
	case 17228ULL: goto x86_l_434c;
	case 17230ULL: goto x86_l_434e;
	case 17236ULL: goto x86_l_4354;
	case 17245ULL: goto x86_l_435d;
	case 17251ULL: goto x86_l_4363;
	case 17258ULL: goto x86_l_436a;
	case 17263ULL: goto x86_l_436f;
	case 17268ULL: goto x86_l_4374;
	case 17277ULL: goto x86_l_437d;
	case 17279ULL: goto x86_l_437f;
	case 17284ULL: goto x86_l_4384;
	case 17289ULL: goto x86_l_4389;
	case 17294ULL: goto x86_l_438e;
	case 17299ULL: goto x86_l_4393;
	case 17304ULL: goto x86_l_4398;
	case 17306ULL: goto x86_l_439a;
	case 17308ULL: goto x86_l_439c;
	case 17314ULL: goto x86_l_43a2;
	case 17319ULL: goto x86_l_43a7;
	case 17328ULL: goto x86_l_43b0;
	case 17333ULL: goto x86_l_43b5;
	case 17339ULL: goto x86_l_43bb;
	case 17346ULL: goto x86_l_43c2;
	case 17351ULL: goto x86_l_43c7;
	case 17356ULL: goto x86_l_43cc;
	case 17365ULL: goto x86_l_43d5;
	case 17371ULL: goto x86_l_43db;
	case 17376ULL: goto x86_l_43e0;
	case 17381ULL: goto x86_l_43e5;
	case 17386ULL: goto x86_l_43ea;
	case 17391ULL: goto x86_l_43ef;
	case 17394ULL: goto x86_l_43f2;
	case 17396ULL: goto x86_l_43f4;
	case 17401ULL: goto x86_l_43f9;
	case 17406ULL: goto x86_l_43fe;
	case 17411ULL: goto x86_l_4403;
	case 17416ULL: goto x86_l_4408;
	case 17421ULL: goto x86_l_440d;
	case 17423ULL: goto x86_l_440f;
	case 17425ULL: goto x86_l_4411;
	case 17431ULL: goto x86_l_4417;
	case 17437ULL: goto x86_l_441d;
	case 17443ULL: goto x86_l_4423;
	case 17447ULL: goto x86_l_4427;
	case 17452ULL: goto x86_l_442c;
	case 17457ULL: goto x86_l_4431;
	case 17463ULL: goto x86_l_4437;
	case 17465ULL: goto x86_l_4439;
	case 17470ULL: goto x86_l_443e;
	case 17475ULL: goto x86_l_4443;
	case 17480ULL: goto x86_l_4448;
	case 17485ULL: goto x86_l_444d;
	case 17490ULL: goto x86_l_4452;
	case 17492ULL: goto x86_l_4454;
	case 17494ULL: goto x86_l_4456;
	case 17500ULL: goto x86_l_445c;
	case 17509ULL: goto x86_l_4465;
	case 17515ULL: goto x86_l_446b;
	case 17522ULL: goto x86_l_4472;
	case 17527ULL: goto x86_l_4477;
	case 17532ULL: goto x86_l_447c;
	case 17541ULL: goto x86_l_4485;
	case 17543ULL: goto x86_l_4487;
	case 17548ULL: goto x86_l_448c;
	case 17553ULL: goto x86_l_4491;
	case 17558ULL: goto x86_l_4496;
	case 17563ULL: goto x86_l_449b;
	case 17568ULL: goto x86_l_44a0;
	case 17570ULL: goto x86_l_44a2;
	case 17572ULL: goto x86_l_44a4;
	case 17578ULL: goto x86_l_44aa;
	case 17587ULL: goto x86_l_44b3;
	case 17593ULL: goto x86_l_44b9;
	case 17600ULL: goto x86_l_44c0;
	case 17605ULL: goto x86_l_44c5;
	case 17610ULL: goto x86_l_44ca;
	case 17619ULL: goto x86_l_44d3;
	case 17621ULL: goto x86_l_44d5;
	case 17626ULL: goto x86_l_44da;
	case 17631ULL: goto x86_l_44df;
	case 17636ULL: goto x86_l_44e4;
	case 17641ULL: goto x86_l_44e9;
	case 17646ULL: goto x86_l_44ee;
	case 17648ULL: goto x86_l_44f0;
	case 17650ULL: goto x86_l_44f2;
	case 17656ULL: goto x86_l_44f8;
	case 17665ULL: goto x86_l_4501;
	case 17671ULL: goto x86_l_4507;
	case 17678ULL: goto x86_l_450e;
	case 17683ULL: goto x86_l_4513;
	case 17688ULL: goto x86_l_4518;
	case 17697ULL: goto x86_l_4521;
	case 17699ULL: goto x86_l_4523;
	case 17704ULL: goto x86_l_4528;
	case 17709ULL: goto x86_l_452d;
	case 17714ULL: goto x86_l_4532;
	case 17719ULL: goto x86_l_4537;
	case 17724ULL: goto x86_l_453c;
	case 17726ULL: goto x86_l_453e;
	case 17728ULL: goto x86_l_4540;
	case 17734ULL: goto x86_l_4546;
	case 17743ULL: goto x86_l_454f;
	case 17749ULL: goto x86_l_4555;
	case 17756ULL: goto x86_l_455c;
	case 17761ULL: goto x86_l_4561;
	case 17766ULL: goto x86_l_4566;
	case 17775ULL: goto x86_l_456f;
	case 17777ULL: goto x86_l_4571;
	case 17782ULL: goto x86_l_4576;
	case 17787ULL: goto x86_l_457b;
	case 17792ULL: goto x86_l_4580;
	case 17797ULL: goto x86_l_4585;
	case 17802ULL: goto x86_l_458a;
	case 17804ULL: goto x86_l_458c;
	case 17806ULL: goto x86_l_458e;
	case 17812ULL: goto x86_l_4594;
	case 17821ULL: goto x86_l_459d;
	case 17827ULL: goto x86_l_45a3;
	case 17834ULL: goto x86_l_45aa;
	case 17839ULL: goto x86_l_45af;
	case 17844ULL: goto x86_l_45b4;
	case 17853ULL: goto x86_l_45bd;
	case 17855ULL: goto x86_l_45bf;
	case 17860ULL: goto x86_l_45c4;
	case 17865ULL: goto x86_l_45c9;
	case 17870ULL: goto x86_l_45ce;
	case 17875ULL: goto x86_l_45d3;
	case 17880ULL: goto x86_l_45d8;
	case 17882ULL: goto x86_l_45da;
	case 17884ULL: goto x86_l_45dc;
	case 17890ULL: goto x86_l_45e2;
	case 17899ULL: goto x86_l_45eb;
	case 17905ULL: goto x86_l_45f1;
	case 17912ULL: goto x86_l_45f8;
	case 17917ULL: goto x86_l_45fd;
	case 17922ULL: goto x86_l_4602;
	case 17931ULL: goto x86_l_460b;
	case 17933ULL: goto x86_l_460d;
	case 17938ULL: goto x86_l_4612;
	case 17943ULL: goto x86_l_4617;
	case 17948ULL: goto x86_l_461c;
	case 17953ULL: goto x86_l_4621;
	case 17958ULL: goto x86_l_4626;
	case 17960ULL: goto x86_l_4628;
	case 17962ULL: goto x86_l_462a;
	case 17968ULL: goto x86_l_4630;
	case 17973ULL: goto x86_l_4635;
	case 17982ULL: goto x86_l_463e;
	case 17987ULL: goto x86_l_4643;
	case 17993ULL: goto x86_l_4649;
	case 18000ULL: goto x86_l_4650;
	case 18005ULL: goto x86_l_4655;
	case 18010ULL: goto x86_l_465a;
	case 18019ULL: goto x86_l_4663;
	case 18021ULL: goto x86_l_4665;
	case 18026ULL: goto x86_l_466a;
	case 18031ULL: goto x86_l_466f;
	case 18036ULL: goto x86_l_4674;
	case 18041ULL: goto x86_l_4679;
	case 18046ULL: goto x86_l_467e;
	case 18048ULL: goto x86_l_4680;
	case 18050ULL: goto x86_l_4682;
	case 18056ULL: goto x86_l_4688;
	case 18061ULL: goto x86_l_468d;
	case 18070ULL: goto x86_l_4696;
	case 18075ULL: goto x86_l_469b;
	case 18081ULL: goto x86_l_46a1;
	case 18088ULL: goto x86_l_46a8;
	case 18093ULL: goto x86_l_46ad;
	case 18098ULL: goto x86_l_46b2;
	case 18107ULL: goto x86_l_46bb;
	case 18113ULL: goto x86_l_46c1;
	case 18118ULL: goto x86_l_46c6;
	case 18123ULL: goto x86_l_46cb;
	case 18128ULL: goto x86_l_46d0;
	case 18133ULL: goto x86_l_46d5;
	case 18138ULL: goto x86_l_46da;
	case 18140ULL: goto x86_l_46dc;
	case 18142ULL: goto x86_l_46de;
	case 18148ULL: goto x86_l_46e4;
	case 18153ULL: goto x86_l_46e9;
	case 18158ULL: goto x86_l_46ee;
	case 18163ULL: goto x86_l_46f3;
	case 18168ULL: goto x86_l_46f8;
	case 18176ULL: goto x86_l_4700;
	case 18179ULL: goto x86_l_4703;
	case 18185ULL: goto x86_l_4709;
	case 18190ULL: goto x86_l_470e;
	case 18193ULL: goto x86_l_4711;
	case 18199ULL: goto x86_l_4717;
	case 18204ULL: goto x86_l_471c;
	case 18212ULL: goto x86_l_4724;
	case 18215ULL: goto x86_l_4727;
	case 18217ULL: goto x86_l_4729;
	case 18222ULL: goto x86_l_472e;
	case 18225ULL: goto x86_l_4731;
	case 18227ULL: goto x86_l_4733;
	case 18230ULL: goto x86_l_4736;
	case 18232ULL: goto x86_l_4738;
	case 18234ULL: goto x86_l_473a;
	case 18239ULL: goto x86_l_473f;
	case 18241ULL: goto x86_l_4741;
	case 18246ULL: goto x86_l_4746;
	case 18251ULL: goto x86_l_474b;
	case 18255ULL: goto x86_l_474f;
	case 18257ULL: goto x86_l_4751;
	case 18260ULL: goto x86_l_4754;
	case 18269ULL: goto x86_l_475d;
	case 18275ULL: goto x86_l_4763;
	case 18282ULL: goto x86_l_476a;
	case 18285ULL: goto x86_l_476d;
	case 18292ULL: goto x86_l_4774;
	case 18295ULL: goto x86_l_4777;
	case 18300ULL: goto x86_l_477c;
	case 18308ULL: goto x86_l_4784;
	case 18310ULL: goto x86_l_4786;
	case 18316ULL: goto x86_l_478c;
	case 18319ULL: goto x86_l_478f;
	case 18321ULL: goto x86_l_4791;
	case 18326ULL: goto x86_l_4796;
	case 18331ULL: goto x86_l_479b;
	case 18336ULL: goto x86_l_47a0;
	case 18341ULL: goto x86_l_47a5;
	case 18346ULL: goto x86_l_47aa;
	case 18348ULL: goto x86_l_47ac;
	case 18350ULL: goto x86_l_47ae;
	case 18356ULL: goto x86_l_47b4;
	case 18365ULL: goto x86_l_47bd;
	case 18371ULL: goto x86_l_47c3;
	case 18378ULL: goto x86_l_47ca;
	case 18383ULL: goto x86_l_47cf;
	case 18388ULL: goto x86_l_47d4;
	case 18397ULL: goto x86_l_47dd;
	case 18399ULL: goto x86_l_47df;
	case 18404ULL: goto x86_l_47e4;
	case 18409ULL: goto x86_l_47e9;
	case 18414ULL: goto x86_l_47ee;
	case 18419ULL: goto x86_l_47f3;
	case 18424ULL: goto x86_l_47f8;
	case 18426ULL: goto x86_l_47fa;
	case 18428ULL: goto x86_l_47fc;
	case 18434ULL: goto x86_l_4802;
	case 18443ULL: goto x86_l_480b;
	case 18449ULL: goto x86_l_4811;
	case 18456ULL: goto x86_l_4818;
	case 18461ULL: goto x86_l_481d;
	case 18466ULL: goto x86_l_4822;
	case 18475ULL: goto x86_l_482b;
	case 18477ULL: goto x86_l_482d;
	case 18482ULL: goto x86_l_4832;
	case 18487ULL: goto x86_l_4837;
	case 18492ULL: goto x86_l_483c;
	case 18497ULL: goto x86_l_4841;
	case 18502ULL: goto x86_l_4846;
	case 18504ULL: goto x86_l_4848;
	case 18506ULL: goto x86_l_484a;
	case 18512ULL: goto x86_l_4850;
	case 18521ULL: goto x86_l_4859;
	case 18527ULL: goto x86_l_485f;
	case 18534ULL: goto x86_l_4866;
	case 18539ULL: goto x86_l_486b;
	case 18544ULL: goto x86_l_4870;
	case 18553ULL: goto x86_l_4879;
	case 18555ULL: goto x86_l_487b;
	case 18560ULL: goto x86_l_4880;
	case 18565ULL: goto x86_l_4885;
	case 18570ULL: goto x86_l_488a;
	case 18575ULL: goto x86_l_488f;
	case 18580ULL: goto x86_l_4894;
	case 18582ULL: goto x86_l_4896;
	case 18584ULL: goto x86_l_4898;
	case 18590ULL: goto x86_l_489e;
	case 18599ULL: goto x86_l_48a7;
	case 18605ULL: goto x86_l_48ad;
	case 18612ULL: goto x86_l_48b4;
	case 18617ULL: goto x86_l_48b9;
	case 18622ULL: goto x86_l_48be;
	case 18631ULL: goto x86_l_48c7;
	case 18633ULL: goto x86_l_48c9;
	case 18638ULL: goto x86_l_48ce;
	case 18643ULL: goto x86_l_48d3;
	case 18648ULL: goto x86_l_48d8;
	case 18653ULL: goto x86_l_48dd;
	case 18658ULL: goto x86_l_48e2;
	case 18660ULL: goto x86_l_48e4;
	case 18662ULL: goto x86_l_48e6;
	case 18668ULL: goto x86_l_48ec;
	case 18677ULL: goto x86_l_48f5;
	case 18683ULL: goto x86_l_48fb;
	case 18690ULL: goto x86_l_4902;
	case 18695ULL: goto x86_l_4907;
	case 18700ULL: goto x86_l_490c;
	case 18709ULL: goto x86_l_4915;
	case 18711ULL: goto x86_l_4917;
	case 18716ULL: goto x86_l_491c;
	case 18721ULL: goto x86_l_4921;
	case 18726ULL: goto x86_l_4926;
	case 18731ULL: goto x86_l_492b;
	case 18736ULL: goto x86_l_4930;
	case 18738ULL: goto x86_l_4932;
	case 18740ULL: goto x86_l_4934;
	case 18746ULL: goto x86_l_493a;
	case 18755ULL: goto x86_l_4943;
	case 18761ULL: goto x86_l_4949;
	case 18768ULL: goto x86_l_4950;
	case 18773ULL: goto x86_l_4955;
	case 18778ULL: goto x86_l_495a;
	case 18787ULL: goto x86_l_4963;
	case 18789ULL: goto x86_l_4965;
	case 18794ULL: goto x86_l_496a;
	case 18799ULL: goto x86_l_496f;
	case 18804ULL: goto x86_l_4974;
	case 18809ULL: goto x86_l_4979;
	case 18814ULL: goto x86_l_497e;
	case 18816ULL: goto x86_l_4980;
	case 18818ULL: goto x86_l_4982;
	case 18824ULL: goto x86_l_4988;
	case 18833ULL: goto x86_l_4991;
	case 18839ULL: goto x86_l_4997;
	case 18846ULL: goto x86_l_499e;
	case 18851ULL: goto x86_l_49a3;
	case 18856ULL: goto x86_l_49a8;
	case 18865ULL: goto x86_l_49b1;
	case 18867ULL: goto x86_l_49b3;
	case 18872ULL: goto x86_l_49b8;
	case 18877ULL: goto x86_l_49bd;
	case 18882ULL: goto x86_l_49c2;
	case 18887ULL: goto x86_l_49c7;
	case 18892ULL: goto x86_l_49cc;
	case 18894ULL: goto x86_l_49ce;
	case 18896ULL: goto x86_l_49d0;
	case 18902ULL: goto x86_l_49d6;
	case 18911ULL: goto x86_l_49df;
	case 18917ULL: goto x86_l_49e5;
	case 18924ULL: goto x86_l_49ec;
	case 18929ULL: goto x86_l_49f1;
	case 18934ULL: goto x86_l_49f6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_425b:
	/* 0x425b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4260:
	/* 0x4260: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4262:
	/* 0x4262: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4264:
	/* 0x4264: js     61e0 <generic_sleepable_preload+0x61e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25056ULL;
	}
x86_l_426a:
	/* 0x426a: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_4273:
	/* 0x4273: je     653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25915ULL;
	}
x86_l_4279:
	/* 0x4279: mov    ecx,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4280:
	/* 0x4280: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4285:
	/* 0x4285: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_428a:
	/* 0x428a: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_4293:
	/* 0x4293: je     42b8 <generic_sleepable_preload+0x42b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42b8;
	}
x86_l_4295:
	/* 0x4295: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_429a:
	/* 0x429a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_429f:
	/* 0x429f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_42a4:
	/* 0x42a4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42a9:
	/* 0x42a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42ae:
	/* 0x42ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42b0:
	/* 0x42b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42b2:
	/* 0x42b2: js     6241 <generic_sleepable_preload+0x6241> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25153ULL;
	}
x86_l_42b8:
	/* 0x42b8: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_42c1:
	/* 0x42c1: je     653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25915ULL;
	}
x86_l_42c7:
	/* 0x42c7: mov    ecx,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_42ce:
	/* 0x42ce: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_42d3:
	/* 0x42d3: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42d8:
	/* 0x42d8: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_42e1:
	/* 0x42e1: je     4306 <generic_sleepable_preload+0x4306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4306;
	}
x86_l_42e3:
	/* 0x42e3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42e8:
	/* 0x42e8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_42ed:
	/* 0x42ed: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_42f2:
	/* 0x42f2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42f7:
	/* 0x42f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42fc:
	/* 0x42fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42fe:
	/* 0x42fe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4300:
	/* 0x4300: js     6534 <generic_sleepable_preload+0x6534> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25908ULL;
	}
x86_l_4306:
	/* 0x4306: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_430f:
	/* 0x430f: je     653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25915ULL;
	}
x86_l_4315:
	/* 0x4315: mov    ecx,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_431c:
	/* 0x431c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4321:
	/* 0x4321: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4326:
	/* 0x4326: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_432f:
	/* 0x432f: je     4354 <generic_sleepable_preload+0x4354> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4354;
	}
x86_l_4331:
	/* 0x4331: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4336:
	/* 0x4336: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_433b:
	/* 0x433b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4340:
	/* 0x4340: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4345:
	/* 0x4345: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_434a:
	/* 0x434a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_434c:
	/* 0x434c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_434e:
	/* 0x434e: js     6900 <generic_sleepable_preload+0x6900> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26880ULL;
	}
x86_l_4354:
	/* 0x4354: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_435d:
	/* 0x435d: je     653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25915ULL;
	}
x86_l_4363:
	/* 0x4363: mov    ecx,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_436a:
	/* 0x436a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_436f:
	/* 0x436f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4374:
	/* 0x4374: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_437d:
	/* 0x437d: je     43a2 <generic_sleepable_preload+0x43a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43a2;
	}
x86_l_437f:
	/* 0x437f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4384:
	/* 0x4384: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4389:
	/* 0x4389: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_438e:
	/* 0x438e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4393:
	/* 0x4393: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4398:
	/* 0x4398: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_439a:
	/* 0x439a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_439c:
	/* 0x439c: js     697c <generic_sleepable_preload+0x697c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27004ULL;
	}
x86_l_43a2:
	/* 0x43a2: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_43a7:
	/* 0x43a7: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_43b0:
	/* 0x43b0: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_43b5:
	/* 0x43b5: je     653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25915ULL;
	}
x86_l_43bb:
	/* 0x43bb: mov    ecx,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_43c2:
	/* 0x43c2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_43c7:
	/* 0x43c7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43cc:
	/* 0x43cc: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_43d5:
	/* 0x43d5: je     653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25915ULL;
	}
x86_l_43db:
	/* 0x43db: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43e0:
	/* 0x43e0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_43e5:
	/* 0x43e5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_43ea:
	/* 0x43ea: jmp    46d0 <generic_sleepable_preload+0x46d0> */
	goto x86_l_46d0;
x86_l_43ef:
	/* 0x43ef: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_43f2:
	/* 0x43f2: je     4417 <generic_sleepable_preload+0x4417> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4417;
	}
x86_l_43f4:
	/* 0x43f4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43f9:
	/* 0x43f9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_43fe:
	/* 0x43fe: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4403:
	/* 0x4403: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4408:
	/* 0x4408: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_440d:
	/* 0x440d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_440f:
	/* 0x440f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4411:
	/* 0x4411: js     46ee <generic_sleepable_preload+0x46ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_46ee;
	}
x86_l_4417:
	/* 0x4417: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_441d:
	/* 0x441d: je     653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25915ULL;
	}
x86_l_4423:
	/* 0x4423: mov    ecx,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4427:
	/* 0x4427: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_442c:
	/* 0x442c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4431:
	/* 0x4431: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_4437:
	/* 0x4437: je     445c <generic_sleepable_preload+0x445c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_445c;
	}
x86_l_4439:
	/* 0x4439: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_443e:
	/* 0x443e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4443:
	/* 0x4443: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4448:
	/* 0x4448: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_444d:
	/* 0x444d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4452:
	/* 0x4452: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4454:
	/* 0x4454: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4456:
	/* 0x4456: js     5431 <generic_sleepable_preload+0x5431> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21553ULL;
	}
x86_l_445c:
	/* 0x445c: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_4465:
	/* 0x4465: je     653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25915ULL;
	}
x86_l_446b:
	/* 0x446b: mov    ecx,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4472:
	/* 0x4472: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4477:
	/* 0x4477: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_447c:
	/* 0x447c: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_4485:
	/* 0x4485: je     44aa <generic_sleepable_preload+0x44aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44aa;
	}
x86_l_4487:
	/* 0x4487: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_448c:
	/* 0x448c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4491:
	/* 0x4491: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4496:
	/* 0x4496: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_449b:
	/* 0x449b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44a0:
	/* 0x44a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44a2:
	/* 0x44a2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_44a4:
	/* 0x44a4: js     6118 <generic_sleepable_preload+0x6118> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24856ULL;
	}
x86_l_44aa:
	/* 0x44aa: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_44b3:
	/* 0x44b3: je     653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25915ULL;
	}
x86_l_44b9:
	/* 0x44b9: mov    ecx,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_44c0:
	/* 0x44c0: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_44c5:
	/* 0x44c5: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44ca:
	/* 0x44ca: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_44d3:
	/* 0x44d3: je     44f8 <generic_sleepable_preload+0x44f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44f8;
	}
x86_l_44d5:
	/* 0x44d5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44da:
	/* 0x44da: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_44df:
	/* 0x44df: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_44e4:
	/* 0x44e4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44e9:
	/* 0x44e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44ee:
	/* 0x44ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44f0:
	/* 0x44f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_44f2:
	/* 0x44f2: js     617c <generic_sleepable_preload+0x617c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24956ULL;
	}
x86_l_44f8:
	/* 0x44f8: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_4501:
	/* 0x4501: je     653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25915ULL;
	}
x86_l_4507:
	/* 0x4507: mov    ecx,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_450e:
	/* 0x450e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4513:
	/* 0x4513: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4518:
	/* 0x4518: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_4521:
	/* 0x4521: je     4546 <generic_sleepable_preload+0x4546> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4546;
	}
x86_l_4523:
	/* 0x4523: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4528:
	/* 0x4528: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_452d:
	/* 0x452d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4532:
	/* 0x4532: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4537:
	/* 0x4537: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_453c:
	/* 0x453c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_453e:
	/* 0x453e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4540:
	/* 0x4540: js     61e0 <generic_sleepable_preload+0x61e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25056ULL;
	}
x86_l_4546:
	/* 0x4546: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_454f:
	/* 0x454f: je     653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25915ULL;
	}
x86_l_4555:
	/* 0x4555: mov    ecx,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_455c:
	/* 0x455c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4561:
	/* 0x4561: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4566:
	/* 0x4566: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_456f:
	/* 0x456f: je     4594 <generic_sleepable_preload+0x4594> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4594;
	}
x86_l_4571:
	/* 0x4571: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4576:
	/* 0x4576: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_457b:
	/* 0x457b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4580:
	/* 0x4580: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4585:
	/* 0x4585: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_458a:
	/* 0x458a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_458c:
	/* 0x458c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_458e:
	/* 0x458e: js     6241 <generic_sleepable_preload+0x6241> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25153ULL;
	}
x86_l_4594:
	/* 0x4594: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_459d:
	/* 0x459d: je     653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25915ULL;
	}
x86_l_45a3:
	/* 0x45a3: mov    ecx,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_45aa:
	/* 0x45aa: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_45af:
	/* 0x45af: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45b4:
	/* 0x45b4: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_45bd:
	/* 0x45bd: je     45e2 <generic_sleepable_preload+0x45e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45e2;
	}
x86_l_45bf:
	/* 0x45bf: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45c4:
	/* 0x45c4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_45c9:
	/* 0x45c9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_45ce:
	/* 0x45ce: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45d3:
	/* 0x45d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45d8:
	/* 0x45d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45da:
	/* 0x45da: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_45dc:
	/* 0x45dc: js     6534 <generic_sleepable_preload+0x6534> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25908ULL;
	}
x86_l_45e2:
	/* 0x45e2: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_45eb:
	/* 0x45eb: je     653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25915ULL;
	}
x86_l_45f1:
	/* 0x45f1: mov    ecx,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_45f8:
	/* 0x45f8: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_45fd:
	/* 0x45fd: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4602:
	/* 0x4602: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_460b:
	/* 0x460b: je     4630 <generic_sleepable_preload+0x4630> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4630;
	}
x86_l_460d:
	/* 0x460d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4612:
	/* 0x4612: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4617:
	/* 0x4617: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_461c:
	/* 0x461c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4621:
	/* 0x4621: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4626:
	/* 0x4626: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4628:
	/* 0x4628: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_462a:
	/* 0x462a: js     6a20 <generic_sleepable_preload+0x6a20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27168ULL;
	}
x86_l_4630:
	/* 0x4630: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4635:
	/* 0x4635: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_463e:
	/* 0x463e: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4643:
	/* 0x4643: je     653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25915ULL;
	}
x86_l_4649:
	/* 0x4649: mov    ecx,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_4650:
	/* 0x4650: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4655:
	/* 0x4655: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_465a:
	/* 0x465a: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_4663:
	/* 0x4663: je     4688 <generic_sleepable_preload+0x4688> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4688;
	}
x86_l_4665:
	/* 0x4665: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_466a:
	/* 0x466a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_466f:
	/* 0x466f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4674:
	/* 0x4674: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4679:
	/* 0x4679: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_467e:
	/* 0x467e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4680:
	/* 0x4680: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4682:
	/* 0x4682: js     697c <generic_sleepable_preload+0x697c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27004ULL;
	}
x86_l_4688:
	/* 0x4688: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_468d:
	/* 0x468d: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_4696:
	/* 0x4696: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_469b:
	/* 0x469b: je     653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25915ULL;
	}
x86_l_46a1:
	/* 0x46a1: mov    ecx,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_46a8:
	/* 0x46a8: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_46ad:
	/* 0x46ad: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46b2:
	/* 0x46b2: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_46bb:
	/* 0x46bb: je     653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25915ULL;
	}
x86_l_46c1:
	/* 0x46c1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46c6:
	/* 0x46c6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_46cb:
	/* 0x46cb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_46d0:
	/* 0x46d0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46d5:
	/* 0x46d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46da:
	/* 0x46da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46dc:
	/* 0x46dc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46de:
	/* 0x46de: jns    653b <generic_sleepable_preload+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25915ULL;
	}
x86_l_46e4:
	/* 0x46e4: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_46e9:
	/* 0x46e9: jmp    6539 <generic_sleepable_preload+0x6539> */
	return 25913ULL;
x86_l_46ee:
	/* 0x46ee: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_46f3:
	/* 0x46f3: jmp    6539 <generic_sleepable_preload+0x6539> */
	return 25913ULL;
x86_l_46f8:
	/* 0x46f8: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4700:
	/* 0x4700: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_4703:
	/* 0x4703: je     5452 <generic_sleepable_preload+0x5452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21586ULL;
	}
x86_l_4709:
	/* 0x4709: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_470e:
	/* 0x470e: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4711:
	/* 0x4711: je     5452 <generic_sleepable_preload+0x5452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21586ULL;
	}
x86_l_4717:
	/* 0x4717: jmp    5465 <generic_sleepable_preload+0x5465> */
	return 21605ULL;
x86_l_471c:
	/* 0x471c: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4724:
	/* 0x4724: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_4727:
	/* 0x4727: je     4733 <generic_sleepable_preload+0x4733> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4733;
	}
x86_l_4729:
	/* 0x4729: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_472e:
	/* 0x472e: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4731:
	/* 0x4731: jne    4746 <generic_sleepable_preload+0x4746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4746;
	}
x86_l_4733:
	/* 0x4733: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_4736:
	/* 0x4736: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_4738:
	/* 0x4738: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_473a:
	/* 0x473a: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_473f:
	/* 0x473f: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4741:
	/* 0x4741: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_4746:
	/* 0x4746: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_474b:
	/* 0x474b: mov    r14d,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_474f:
	/* 0x474f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4751:
	/* 0x4751: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_4754:
	/* 0x4754: cmp    WORD PTR [r13+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_475d:
	/* 0x475d: je     65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26095ULL;
	}
x86_l_4763:
	/* 0x4763: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_476a:
	/* 0x476a: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_476d:
	/* 0x476d: mov    eax,DWORD PTR [r13+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_4774:
	/* 0x4774: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4777:
	/* 0x4777: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_477c:
	/* 0x477c: movzx  eax,WORD PTR [r13+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_4784:
	/* 0x4784: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_4786:
	/* 0x4786: je     4a71 <generic_sleepable_preload+0x4a71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19057ULL;
	}
x86_l_478c:
	/* 0x478c: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_478f:
	/* 0x478f: je     47b4 <generic_sleepable_preload+0x47b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47b4;
	}
x86_l_4791:
	/* 0x4791: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4796:
	/* 0x4796: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_479b:
	/* 0x479b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47a0:
	/* 0x47a0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
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
	/* 0x47ae: js     4d79 <generic_sleepable_preload+0x4d79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19833ULL;
	}
x86_l_47b4:
	/* 0x47b4: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_47bd:
	/* 0x47bd: je     65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26095ULL;
	}
x86_l_47c3:
	/* 0x47c3: mov    ecx,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_47ca:
	/* 0x47ca: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_47cf:
	/* 0x47cf: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47d4:
	/* 0x47d4: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_47dd:
	/* 0x47dd: je     4802 <generic_sleepable_preload+0x4802> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4802;
	}
x86_l_47df:
	/* 0x47df: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47e4:
	/* 0x47e4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_47e9:
	/* 0x47e9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47ee:
	/* 0x47ee: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47f3:
	/* 0x47f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47f8:
	/* 0x47f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47fa:
	/* 0x47fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_47fc:
	/* 0x47fc: js     543b <generic_sleepable_preload+0x543b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21563ULL;
	}
x86_l_4802:
	/* 0x4802: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_480b:
	/* 0x480b: je     65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26095ULL;
	}
x86_l_4811:
	/* 0x4811: mov    ecx,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_4818:
	/* 0x4818: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_481d:
	/* 0x481d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4822:
	/* 0x4822: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_482b:
	/* 0x482b: je     4850 <generic_sleepable_preload+0x4850> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4850;
	}
x86_l_482d:
	/* 0x482d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4832:
	/* 0x4832: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4837:
	/* 0x4837: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_483c:
	/* 0x483c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4841:
	/* 0x4841: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4846:
	/* 0x4846: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4848:
	/* 0x4848: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_484a:
	/* 0x484a: js     6122 <generic_sleepable_preload+0x6122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24866ULL;
	}
x86_l_4850:
	/* 0x4850: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_4859:
	/* 0x4859: je     65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26095ULL;
	}
x86_l_485f:
	/* 0x485f: mov    ecx,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_4866:
	/* 0x4866: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_486b:
	/* 0x486b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4870:
	/* 0x4870: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_4879:
	/* 0x4879: je     489e <generic_sleepable_preload+0x489e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_489e;
	}
x86_l_487b:
	/* 0x487b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4880:
	/* 0x4880: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4885:
	/* 0x4885: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_488a:
	/* 0x488a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_488f:
	/* 0x488f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4894:
	/* 0x4894: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4896:
	/* 0x4896: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4898:
	/* 0x4898: js     6186 <generic_sleepable_preload+0x6186> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24966ULL;
	}
x86_l_489e:
	/* 0x489e: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_48a7:
	/* 0x48a7: je     65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26095ULL;
	}
x86_l_48ad:
	/* 0x48ad: mov    ecx,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_48b4:
	/* 0x48b4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_48b9:
	/* 0x48b9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48be:
	/* 0x48be: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_48c7:
	/* 0x48c7: je     48ec <generic_sleepable_preload+0x48ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48ec;
	}
x86_l_48c9:
	/* 0x48c9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48ce:
	/* 0x48ce: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_48d3:
	/* 0x48d3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_48d8:
	/* 0x48d8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48dd:
	/* 0x48dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48e2:
	/* 0x48e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48e4:
	/* 0x48e4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48e6:
	/* 0x48e6: js     61ea <generic_sleepable_preload+0x61ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25066ULL;
	}
x86_l_48ec:
	/* 0x48ec: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_48f5:
	/* 0x48f5: je     65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26095ULL;
	}
x86_l_48fb:
	/* 0x48fb: mov    ecx,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_4902:
	/* 0x4902: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4907:
	/* 0x4907: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_490c:
	/* 0x490c: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_4915:
	/* 0x4915: je     493a <generic_sleepable_preload+0x493a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_493a;
	}
x86_l_4917:
	/* 0x4917: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_491c:
	/* 0x491c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4921:
	/* 0x4921: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4926:
	/* 0x4926: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
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
	/* 0x4934: js     624b <generic_sleepable_preload+0x624b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25163ULL;
	}
x86_l_493a:
	/* 0x493a: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_4943:
	/* 0x4943: je     65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26095ULL;
	}
x86_l_4949:
	/* 0x4949: mov    ecx,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_4950:
	/* 0x4950: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4955:
	/* 0x4955: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_495a:
	/* 0x495a: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_4963:
	/* 0x4963: je     4988 <generic_sleepable_preload+0x4988> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4988;
	}
x86_l_4965:
	/* 0x4965: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_496a:
	/* 0x496a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_496f:
	/* 0x496f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4974:
	/* 0x4974: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4979:
	/* 0x4979: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_497e:
	/* 0x497e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4980:
	/* 0x4980: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4982:
	/* 0x4982: js     65e8 <generic_sleepable_preload+0x65e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26088ULL;
	}
x86_l_4988:
	/* 0x4988: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_4991:
	/* 0x4991: je     65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26095ULL;
	}
x86_l_4997:
	/* 0x4997: mov    ecx,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_499e:
	/* 0x499e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_49a3:
	/* 0x49a3: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49a8:
	/* 0x49a8: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_49b1:
	/* 0x49b1: je     49d6 <generic_sleepable_preload+0x49d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49d6;
	}
x86_l_49b3:
	/* 0x49b3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49b8:
	/* 0x49b8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_49bd:
	/* 0x49bd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_49c2:
	/* 0x49c2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49c7:
	/* 0x49c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49cc:
	/* 0x49cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49ce:
	/* 0x49ce: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_49d0:
	/* 0x49d0: js     690c <generic_sleepable_preload+0x690c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26892ULL;
	}
x86_l_49d6:
	/* 0x49d6: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_49df:
	/* 0x49df: je     65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26095ULL;
	}
x86_l_49e5:
	/* 0x49e5: mov    ecx,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_49ec:
	/* 0x49ec: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_49f1:
	/* 0x49f1: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49f6:
	/* 0x49f6: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
	return 18943ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 18943ULL: goto x86_l_49ff;
	case 18945ULL: goto x86_l_4a01;
	case 18950ULL: goto x86_l_4a06;
	case 18955ULL: goto x86_l_4a0b;
	case 18960ULL: goto x86_l_4a10;
	case 18965ULL: goto x86_l_4a15;
	case 18970ULL: goto x86_l_4a1a;
	case 18972ULL: goto x86_l_4a1c;
	case 18974ULL: goto x86_l_4a1e;
	case 18980ULL: goto x86_l_4a24;
	case 18985ULL: goto x86_l_4a29;
	case 18994ULL: goto x86_l_4a32;
	case 18999ULL: goto x86_l_4a37;
	case 19005ULL: goto x86_l_4a3d;
	case 19012ULL: goto x86_l_4a44;
	case 19017ULL: goto x86_l_4a49;
	case 19022ULL: goto x86_l_4a4e;
	case 19031ULL: goto x86_l_4a57;
	case 19037ULL: goto x86_l_4a5d;
	case 19042ULL: goto x86_l_4a62;
	case 19047ULL: goto x86_l_4a67;
	case 19052ULL: goto x86_l_4a6c;
	case 19057ULL: goto x86_l_4a71;
	case 19060ULL: goto x86_l_4a74;
	case 19062ULL: goto x86_l_4a76;
	case 19067ULL: goto x86_l_4a7b;
	case 19072ULL: goto x86_l_4a80;
	case 19077ULL: goto x86_l_4a85;
	case 19082ULL: goto x86_l_4a8a;
	case 19087ULL: goto x86_l_4a8f;
	case 19089ULL: goto x86_l_4a91;
	case 19091ULL: goto x86_l_4a93;
	case 19097ULL: goto x86_l_4a99;
	case 19106ULL: goto x86_l_4aa2;
	case 19112ULL: goto x86_l_4aa8;
	case 19119ULL: goto x86_l_4aaf;
	case 19124ULL: goto x86_l_4ab4;
	case 19129ULL: goto x86_l_4ab9;
	case 19138ULL: goto x86_l_4ac2;
	case 19140ULL: goto x86_l_4ac4;
	case 19145ULL: goto x86_l_4ac9;
	case 19150ULL: goto x86_l_4ace;
	case 19155ULL: goto x86_l_4ad3;
	case 19160ULL: goto x86_l_4ad8;
	case 19165ULL: goto x86_l_4add;
	case 19167ULL: goto x86_l_4adf;
	case 19169ULL: goto x86_l_4ae1;
	case 19175ULL: goto x86_l_4ae7;
	case 19184ULL: goto x86_l_4af0;
	case 19190ULL: goto x86_l_4af6;
	case 19197ULL: goto x86_l_4afd;
	case 19202ULL: goto x86_l_4b02;
	case 19207ULL: goto x86_l_4b07;
	case 19216ULL: goto x86_l_4b10;
	case 19218ULL: goto x86_l_4b12;
	case 19223ULL: goto x86_l_4b17;
	case 19228ULL: goto x86_l_4b1c;
	case 19233ULL: goto x86_l_4b21;
	case 19238ULL: goto x86_l_4b26;
	case 19243ULL: goto x86_l_4b2b;
	case 19245ULL: goto x86_l_4b2d;
	case 19247ULL: goto x86_l_4b2f;
	case 19253ULL: goto x86_l_4b35;
	case 19262ULL: goto x86_l_4b3e;
	case 19268ULL: goto x86_l_4b44;
	case 19275ULL: goto x86_l_4b4b;
	case 19280ULL: goto x86_l_4b50;
	case 19285ULL: goto x86_l_4b55;
	case 19294ULL: goto x86_l_4b5e;
	case 19296ULL: goto x86_l_4b60;
	case 19301ULL: goto x86_l_4b65;
	case 19306ULL: goto x86_l_4b6a;
	case 19311ULL: goto x86_l_4b6f;
	case 19316ULL: goto x86_l_4b74;
	case 19321ULL: goto x86_l_4b79;
	case 19323ULL: goto x86_l_4b7b;
	case 19325ULL: goto x86_l_4b7d;
	case 19331ULL: goto x86_l_4b83;
	case 19340ULL: goto x86_l_4b8c;
	case 19346ULL: goto x86_l_4b92;
	case 19353ULL: goto x86_l_4b99;
	case 19358ULL: goto x86_l_4b9e;
	case 19363ULL: goto x86_l_4ba3;
	case 19372ULL: goto x86_l_4bac;
	case 19374ULL: goto x86_l_4bae;
	case 19379ULL: goto x86_l_4bb3;
	case 19384ULL: goto x86_l_4bb8;
	case 19389ULL: goto x86_l_4bbd;
	case 19394ULL: goto x86_l_4bc2;
	case 19399ULL: goto x86_l_4bc7;
	case 19401ULL: goto x86_l_4bc9;
	case 19403ULL: goto x86_l_4bcb;
	case 19409ULL: goto x86_l_4bd1;
	case 19418ULL: goto x86_l_4bda;
	case 19424ULL: goto x86_l_4be0;
	case 19431ULL: goto x86_l_4be7;
	case 19436ULL: goto x86_l_4bec;
	case 19441ULL: goto x86_l_4bf1;
	case 19450ULL: goto x86_l_4bfa;
	case 19452ULL: goto x86_l_4bfc;
	case 19457ULL: goto x86_l_4c01;
	case 19462ULL: goto x86_l_4c06;
	case 19467ULL: goto x86_l_4c0b;
	case 19472ULL: goto x86_l_4c10;
	case 19477ULL: goto x86_l_4c15;
	case 19479ULL: goto x86_l_4c17;
	case 19481ULL: goto x86_l_4c19;
	case 19487ULL: goto x86_l_4c1f;
	case 19496ULL: goto x86_l_4c28;
	case 19502ULL: goto x86_l_4c2e;
	case 19509ULL: goto x86_l_4c35;
	case 19514ULL: goto x86_l_4c3a;
	case 19519ULL: goto x86_l_4c3f;
	case 19528ULL: goto x86_l_4c48;
	case 19530ULL: goto x86_l_4c4a;
	case 19535ULL: goto x86_l_4c4f;
	case 19540ULL: goto x86_l_4c54;
	case 19545ULL: goto x86_l_4c59;
	case 19550ULL: goto x86_l_4c5e;
	case 19555ULL: goto x86_l_4c63;
	case 19557ULL: goto x86_l_4c65;
	case 19559ULL: goto x86_l_4c67;
	case 19565ULL: goto x86_l_4c6d;
	case 19574ULL: goto x86_l_4c76;
	case 19580ULL: goto x86_l_4c7c;
	case 19587ULL: goto x86_l_4c83;
	case 19592ULL: goto x86_l_4c88;
	case 19597ULL: goto x86_l_4c8d;
	case 19606ULL: goto x86_l_4c96;
	case 19608ULL: goto x86_l_4c98;
	case 19613ULL: goto x86_l_4c9d;
	case 19618ULL: goto x86_l_4ca2;
	case 19623ULL: goto x86_l_4ca7;
	case 19628ULL: goto x86_l_4cac;
	case 19633ULL: goto x86_l_4cb1;
	case 19635ULL: goto x86_l_4cb3;
	case 19637ULL: goto x86_l_4cb5;
	case 19643ULL: goto x86_l_4cbb;
	case 19648ULL: goto x86_l_4cc0;
	case 19657ULL: goto x86_l_4cc9;
	case 19662ULL: goto x86_l_4cce;
	case 19668ULL: goto x86_l_4cd4;
	case 19675ULL: goto x86_l_4cdb;
	case 19680ULL: goto x86_l_4ce0;
	case 19685ULL: goto x86_l_4ce5;
	case 19694ULL: goto x86_l_4cee;
	case 19696ULL: goto x86_l_4cf0;
	case 19701ULL: goto x86_l_4cf5;
	case 19706ULL: goto x86_l_4cfa;
	case 19711ULL: goto x86_l_4cff;
	case 19716ULL: goto x86_l_4d04;
	case 19721ULL: goto x86_l_4d09;
	case 19723ULL: goto x86_l_4d0b;
	case 19725ULL: goto x86_l_4d0d;
	case 19731ULL: goto x86_l_4d13;
	case 19736ULL: goto x86_l_4d18;
	case 19745ULL: goto x86_l_4d21;
	case 19750ULL: goto x86_l_4d26;
	case 19756ULL: goto x86_l_4d2c;
	case 19763ULL: goto x86_l_4d33;
	case 19768ULL: goto x86_l_4d38;
	case 19773ULL: goto x86_l_4d3d;
	case 19782ULL: goto x86_l_4d46;
	case 19788ULL: goto x86_l_4d4c;
	case 19793ULL: goto x86_l_4d51;
	case 19798ULL: goto x86_l_4d56;
	case 19803ULL: goto x86_l_4d5b;
	case 19808ULL: goto x86_l_4d60;
	case 19813ULL: goto x86_l_4d65;
	case 19815ULL: goto x86_l_4d67;
	case 19817ULL: goto x86_l_4d69;
	case 19823ULL: goto x86_l_4d6f;
	case 19828ULL: goto x86_l_4d74;
	case 19833ULL: goto x86_l_4d79;
	case 19838ULL: goto x86_l_4d7e;
	case 19843ULL: goto x86_l_4d83;
	case 19851ULL: goto x86_l_4d8b;
	case 19854ULL: goto x86_l_4d8e;
	case 19856ULL: goto x86_l_4d90;
	case 19861ULL: goto x86_l_4d95;
	case 19864ULL: goto x86_l_4d98;
	case 19866ULL: goto x86_l_4d9a;
	case 19869ULL: goto x86_l_4d9d;
	case 19871ULL: goto x86_l_4d9f;
	case 19873ULL: goto x86_l_4da1;
	case 19878ULL: goto x86_l_4da6;
	case 19880ULL: goto x86_l_4da8;
	case 19885ULL: goto x86_l_4dad;
	case 19890ULL: goto x86_l_4db2;
	case 19894ULL: goto x86_l_4db6;
	case 19896ULL: goto x86_l_4db8;
	case 19899ULL: goto x86_l_4dbb;
	case 19908ULL: goto x86_l_4dc4;
	case 19914ULL: goto x86_l_4dca;
	case 19921ULL: goto x86_l_4dd1;
	case 19924ULL: goto x86_l_4dd4;
	case 19931ULL: goto x86_l_4ddb;
	case 19934ULL: goto x86_l_4dde;
	case 19939ULL: goto x86_l_4de3;
	case 19947ULL: goto x86_l_4deb;
	case 19949ULL: goto x86_l_4ded;
	case 19955ULL: goto x86_l_4df3;
	case 19958ULL: goto x86_l_4df6;
	case 19960ULL: goto x86_l_4df8;
	case 19965ULL: goto x86_l_4dfd;
	case 19970ULL: goto x86_l_4e02;
	case 19975ULL: goto x86_l_4e07;
	case 19980ULL: goto x86_l_4e0c;
	case 19985ULL: goto x86_l_4e11;
	case 19987ULL: goto x86_l_4e13;
	case 19989ULL: goto x86_l_4e15;
	case 19995ULL: goto x86_l_4e1b;
	case 20004ULL: goto x86_l_4e24;
	case 20010ULL: goto x86_l_4e2a;
	case 20017ULL: goto x86_l_4e31;
	case 20022ULL: goto x86_l_4e36;
	case 20027ULL: goto x86_l_4e3b;
	case 20036ULL: goto x86_l_4e44;
	case 20038ULL: goto x86_l_4e46;
	case 20043ULL: goto x86_l_4e4b;
	case 20048ULL: goto x86_l_4e50;
	case 20053ULL: goto x86_l_4e55;
	case 20058ULL: goto x86_l_4e5a;
	case 20063ULL: goto x86_l_4e5f;
	case 20065ULL: goto x86_l_4e61;
	case 20067ULL: goto x86_l_4e63;
	case 20073ULL: goto x86_l_4e69;
	case 20082ULL: goto x86_l_4e72;
	case 20088ULL: goto x86_l_4e78;
	case 20095ULL: goto x86_l_4e7f;
	case 20100ULL: goto x86_l_4e84;
	case 20105ULL: goto x86_l_4e89;
	case 20114ULL: goto x86_l_4e92;
	case 20116ULL: goto x86_l_4e94;
	case 20121ULL: goto x86_l_4e99;
	case 20126ULL: goto x86_l_4e9e;
	case 20131ULL: goto x86_l_4ea3;
	case 20136ULL: goto x86_l_4ea8;
	case 20141ULL: goto x86_l_4ead;
	case 20143ULL: goto x86_l_4eaf;
	case 20145ULL: goto x86_l_4eb1;
	case 20151ULL: goto x86_l_4eb7;
	case 20160ULL: goto x86_l_4ec0;
	case 20166ULL: goto x86_l_4ec6;
	case 20173ULL: goto x86_l_4ecd;
	case 20178ULL: goto x86_l_4ed2;
	case 20183ULL: goto x86_l_4ed7;
	case 20192ULL: goto x86_l_4ee0;
	case 20194ULL: goto x86_l_4ee2;
	case 20199ULL: goto x86_l_4ee7;
	case 20204ULL: goto x86_l_4eec;
	case 20209ULL: goto x86_l_4ef1;
	case 20214ULL: goto x86_l_4ef6;
	case 20219ULL: goto x86_l_4efb;
	case 20221ULL: goto x86_l_4efd;
	case 20223ULL: goto x86_l_4eff;
	case 20229ULL: goto x86_l_4f05;
	case 20238ULL: goto x86_l_4f0e;
	case 20244ULL: goto x86_l_4f14;
	case 20251ULL: goto x86_l_4f1b;
	case 20256ULL: goto x86_l_4f20;
	case 20261ULL: goto x86_l_4f25;
	case 20270ULL: goto x86_l_4f2e;
	case 20272ULL: goto x86_l_4f30;
	case 20277ULL: goto x86_l_4f35;
	case 20282ULL: goto x86_l_4f3a;
	case 20287ULL: goto x86_l_4f3f;
	case 20292ULL: goto x86_l_4f44;
	case 20297ULL: goto x86_l_4f49;
	case 20299ULL: goto x86_l_4f4b;
	case 20301ULL: goto x86_l_4f4d;
	case 20307ULL: goto x86_l_4f53;
	case 20316ULL: goto x86_l_4f5c;
	case 20322ULL: goto x86_l_4f62;
	case 20329ULL: goto x86_l_4f69;
	case 20334ULL: goto x86_l_4f6e;
	case 20339ULL: goto x86_l_4f73;
	case 20348ULL: goto x86_l_4f7c;
	case 20350ULL: goto x86_l_4f7e;
	case 20355ULL: goto x86_l_4f83;
	case 20360ULL: goto x86_l_4f88;
	case 20365ULL: goto x86_l_4f8d;
	case 20370ULL: goto x86_l_4f92;
	case 20375ULL: goto x86_l_4f97;
	case 20377ULL: goto x86_l_4f99;
	case 20379ULL: goto x86_l_4f9b;
	case 20385ULL: goto x86_l_4fa1;
	case 20394ULL: goto x86_l_4faa;
	case 20400ULL: goto x86_l_4fb0;
	case 20407ULL: goto x86_l_4fb7;
	case 20412ULL: goto x86_l_4fbc;
	case 20417ULL: goto x86_l_4fc1;
	case 20426ULL: goto x86_l_4fca;
	case 20428ULL: goto x86_l_4fcc;
	case 20433ULL: goto x86_l_4fd1;
	case 20438ULL: goto x86_l_4fd6;
	case 20443ULL: goto x86_l_4fdb;
	case 20448ULL: goto x86_l_4fe0;
	case 20453ULL: goto x86_l_4fe5;
	case 20455ULL: goto x86_l_4fe7;
	case 20457ULL: goto x86_l_4fe9;
	case 20463ULL: goto x86_l_4fef;
	case 20472ULL: goto x86_l_4ff8;
	case 20478ULL: goto x86_l_4ffe;
	case 20485ULL: goto x86_l_5005;
	case 20490ULL: goto x86_l_500a;
	case 20495ULL: goto x86_l_500f;
	case 20504ULL: goto x86_l_5018;
	case 20506ULL: goto x86_l_501a;
	case 20511ULL: goto x86_l_501f;
	case 20516ULL: goto x86_l_5024;
	case 20521ULL: goto x86_l_5029;
	case 20526ULL: goto x86_l_502e;
	case 20531ULL: goto x86_l_5033;
	case 20533ULL: goto x86_l_5035;
	case 20535ULL: goto x86_l_5037;
	case 20541ULL: goto x86_l_503d;
	case 20550ULL: goto x86_l_5046;
	case 20556ULL: goto x86_l_504c;
	case 20563ULL: goto x86_l_5053;
	case 20568ULL: goto x86_l_5058;
	case 20573ULL: goto x86_l_505d;
	case 20582ULL: goto x86_l_5066;
	case 20584ULL: goto x86_l_5068;
	case 20589ULL: goto x86_l_506d;
	case 20594ULL: goto x86_l_5072;
	case 20599ULL: goto x86_l_5077;
	case 20604ULL: goto x86_l_507c;
	case 20609ULL: goto x86_l_5081;
	case 20611ULL: goto x86_l_5083;
	case 20613ULL: goto x86_l_5085;
	case 20619ULL: goto x86_l_508b;
	case 20624ULL: goto x86_l_5090;
	case 20633ULL: goto x86_l_5099;
	case 20639ULL: goto x86_l_509f;
	case 20646ULL: goto x86_l_50a6;
	case 20651ULL: goto x86_l_50ab;
	case 20656ULL: goto x86_l_50b0;
	case 20665ULL: goto x86_l_50b9;
	case 20671ULL: goto x86_l_50bf;
	case 20676ULL: goto x86_l_50c4;
	case 20681ULL: goto x86_l_50c9;
	case 20686ULL: goto x86_l_50ce;
	case 20691ULL: goto x86_l_50d3;
	case 20694ULL: goto x86_l_50d6;
	case 20696ULL: goto x86_l_50d8;
	case 20701ULL: goto x86_l_50dd;
	case 20706ULL: goto x86_l_50e2;
	case 20711ULL: goto x86_l_50e7;
	case 20716ULL: goto x86_l_50ec;
	case 20721ULL: goto x86_l_50f1;
	case 20723ULL: goto x86_l_50f3;
	case 20725ULL: goto x86_l_50f5;
	case 20731ULL: goto x86_l_50fb;
	case 20740ULL: goto x86_l_5104;
	case 20746ULL: goto x86_l_510a;
	case 20753ULL: goto x86_l_5111;
	case 20758ULL: goto x86_l_5116;
	case 20763ULL: goto x86_l_511b;
	case 20772ULL: goto x86_l_5124;
	case 20774ULL: goto x86_l_5126;
	case 20779ULL: goto x86_l_512b;
	case 20784ULL: goto x86_l_5130;
	case 20789ULL: goto x86_l_5135;
	case 20794ULL: goto x86_l_513a;
	case 20799ULL: goto x86_l_513f;
	case 20801ULL: goto x86_l_5141;
	case 20803ULL: goto x86_l_5143;
	case 20809ULL: goto x86_l_5149;
	case 20818ULL: goto x86_l_5152;
	case 20824ULL: goto x86_l_5158;
	case 20831ULL: goto x86_l_515f;
	case 20836ULL: goto x86_l_5164;
	case 20841ULL: goto x86_l_5169;
	case 20850ULL: goto x86_l_5172;
	case 20852ULL: goto x86_l_5174;
	case 20857ULL: goto x86_l_5179;
	case 20862ULL: goto x86_l_517e;
	case 20867ULL: goto x86_l_5183;
	case 20872ULL: goto x86_l_5188;
	case 20877ULL: goto x86_l_518d;
	case 20879ULL: goto x86_l_518f;
	case 20881ULL: goto x86_l_5191;
	case 20887ULL: goto x86_l_5197;
	default: return 0xffffffffffffffffULL;
	}
x86_l_49ff:
	/* 0x49ff: je     4a24 <generic_sleepable_preload+0x4a24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a24;
	}
x86_l_4a01:
	/* 0x4a01: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a06:
	/* 0x4a06: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a0b:
	/* 0x4a0b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a10:
	/* 0x4a10: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a15:
	/* 0x4a15: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a1a:
	/* 0x4a1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a1c:
	/* 0x4a1c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a1e:
	/* 0x4a1e: js     6988 <generic_sleepable_preload+0x6988> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27016ULL;
	}
x86_l_4a24:
	/* 0x4a24: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4a29:
	/* 0x4a29: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_4a32:
	/* 0x4a32: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4a37:
	/* 0x4a37: je     65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26095ULL;
	}
x86_l_4a3d:
	/* 0x4a3d: mov    ecx,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_4a44:
	/* 0x4a44: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4a49:
	/* 0x4a49: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a4e:
	/* 0x4a4e: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_4a57:
	/* 0x4a57: je     65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26095ULL;
	}
x86_l_4a5d:
	/* 0x4a5d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a62:
	/* 0x4a62: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a67:
	/* 0x4a67: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a6c:
	/* 0x4a6c: jmp    4d5b <generic_sleepable_preload+0x4d5b> */
	goto x86_l_4d5b;
x86_l_4a71:
	/* 0x4a71: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4a74:
	/* 0x4a74: je     4a99 <generic_sleepable_preload+0x4a99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a99;
	}
x86_l_4a76:
	/* 0x4a76: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a7b:
	/* 0x4a7b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a80:
	/* 0x4a80: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a85:
	/* 0x4a85: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a8a:
	/* 0x4a8a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a8f:
	/* 0x4a8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a91:
	/* 0x4a91: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a93:
	/* 0x4a93: js     4d79 <generic_sleepable_preload+0x4d79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4d79;
	}
x86_l_4a99:
	/* 0x4a99: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_4aa2:
	/* 0x4aa2: je     65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26095ULL;
	}
x86_l_4aa8:
	/* 0x4aa8: mov    ecx,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_4aaf:
	/* 0x4aaf: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4ab4:
	/* 0x4ab4: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ab9:
	/* 0x4ab9: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_4ac2:
	/* 0x4ac2: je     4ae7 <generic_sleepable_preload+0x4ae7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ae7;
	}
x86_l_4ac4:
	/* 0x4ac4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ac9:
	/* 0x4ac9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4ace:
	/* 0x4ace: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ad3:
	/* 0x4ad3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ad8:
	/* 0x4ad8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4add:
	/* 0x4add: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4adf:
	/* 0x4adf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ae1:
	/* 0x4ae1: js     543b <generic_sleepable_preload+0x543b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21563ULL;
	}
x86_l_4ae7:
	/* 0x4ae7: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_4af0:
	/* 0x4af0: je     65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26095ULL;
	}
x86_l_4af6:
	/* 0x4af6: mov    ecx,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_4afd:
	/* 0x4afd: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4b02:
	/* 0x4b02: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b07:
	/* 0x4b07: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_4b10:
	/* 0x4b10: je     4b35 <generic_sleepable_preload+0x4b35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b35;
	}
x86_l_4b12:
	/* 0x4b12: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b17:
	/* 0x4b17: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4b1c:
	/* 0x4b1c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b21:
	/* 0x4b21: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b26:
	/* 0x4b26: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b2b:
	/* 0x4b2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b2d:
	/* 0x4b2d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b2f:
	/* 0x4b2f: js     6122 <generic_sleepable_preload+0x6122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24866ULL;
	}
x86_l_4b35:
	/* 0x4b35: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_4b3e:
	/* 0x4b3e: je     65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26095ULL;
	}
x86_l_4b44:
	/* 0x4b44: mov    ecx,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_4b4b:
	/* 0x4b4b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4b50:
	/* 0x4b50: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b55:
	/* 0x4b55: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_4b5e:
	/* 0x4b5e: je     4b83 <generic_sleepable_preload+0x4b83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b83;
	}
x86_l_4b60:
	/* 0x4b60: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b65:
	/* 0x4b65: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4b6a:
	/* 0x4b6a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b6f:
	/* 0x4b6f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b74:
	/* 0x4b74: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b79:
	/* 0x4b79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b7b:
	/* 0x4b7b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b7d:
	/* 0x4b7d: js     6186 <generic_sleepable_preload+0x6186> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24966ULL;
	}
x86_l_4b83:
	/* 0x4b83: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_4b8c:
	/* 0x4b8c: je     65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26095ULL;
	}
x86_l_4b92:
	/* 0x4b92: mov    ecx,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_4b99:
	/* 0x4b99: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4b9e:
	/* 0x4b9e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ba3:
	/* 0x4ba3: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_4bac:
	/* 0x4bac: je     4bd1 <generic_sleepable_preload+0x4bd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bd1;
	}
x86_l_4bae:
	/* 0x4bae: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bb3:
	/* 0x4bb3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4bb8:
	/* 0x4bb8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4bbd:
	/* 0x4bbd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bc2:
	/* 0x4bc2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4bc7:
	/* 0x4bc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bc9:
	/* 0x4bc9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4bcb:
	/* 0x4bcb: js     61ea <generic_sleepable_preload+0x61ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25066ULL;
	}
x86_l_4bd1:
	/* 0x4bd1: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_4bda:
	/* 0x4bda: je     65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26095ULL;
	}
x86_l_4be0:
	/* 0x4be0: mov    ecx,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_4be7:
	/* 0x4be7: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4bec:
	/* 0x4bec: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bf1:
	/* 0x4bf1: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_4bfa:
	/* 0x4bfa: je     4c1f <generic_sleepable_preload+0x4c1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c1f;
	}
x86_l_4bfc:
	/* 0x4bfc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c01:
	/* 0x4c01: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4c06:
	/* 0x4c06: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4c0b:
	/* 0x4c0b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c10:
	/* 0x4c10: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c15:
	/* 0x4c15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c17:
	/* 0x4c17: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c19:
	/* 0x4c19: js     624b <generic_sleepable_preload+0x624b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25163ULL;
	}
x86_l_4c1f:
	/* 0x4c1f: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_4c28:
	/* 0x4c28: je     65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26095ULL;
	}
x86_l_4c2e:
	/* 0x4c2e: mov    ecx,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_4c35:
	/* 0x4c35: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4c3a:
	/* 0x4c3a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c3f:
	/* 0x4c3f: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_4c48:
	/* 0x4c48: je     4c6d <generic_sleepable_preload+0x4c6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c6d;
	}
x86_l_4c4a:
	/* 0x4c4a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c4f:
	/* 0x4c4f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4c54:
	/* 0x4c54: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4c59:
	/* 0x4c59: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c5e:
	/* 0x4c5e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c63:
	/* 0x4c63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c65:
	/* 0x4c65: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c67:
	/* 0x4c67: js     65e8 <generic_sleepable_preload+0x65e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26088ULL;
	}
x86_l_4c6d:
	/* 0x4c6d: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_4c76:
	/* 0x4c76: je     65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26095ULL;
	}
x86_l_4c7c:
	/* 0x4c7c: mov    ecx,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_4c83:
	/* 0x4c83: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4c88:
	/* 0x4c88: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c8d:
	/* 0x4c8d: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_4c96:
	/* 0x4c96: je     4cbb <generic_sleepable_preload+0x4cbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4cbb;
	}
x86_l_4c98:
	/* 0x4c98: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c9d:
	/* 0x4c9d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4ca2:
	/* 0x4ca2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ca7:
	/* 0x4ca7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cac:
	/* 0x4cac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cb1:
	/* 0x4cb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cb3:
	/* 0x4cb3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4cb5:
	/* 0x4cb5: js     6a36 <generic_sleepable_preload+0x6a36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27190ULL;
	}
x86_l_4cbb:
	/* 0x4cbb: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4cc0:
	/* 0x4cc0: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_4cc9:
	/* 0x4cc9: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4cce:
	/* 0x4cce: je     65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26095ULL;
	}
x86_l_4cd4:
	/* 0x4cd4: mov    ecx,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_4cdb:
	/* 0x4cdb: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4ce0:
	/* 0x4ce0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ce5:
	/* 0x4ce5: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_4cee:
	/* 0x4cee: je     4d13 <generic_sleepable_preload+0x4d13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d13;
	}
x86_l_4cf0:
	/* 0x4cf0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cf5:
	/* 0x4cf5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4cfa:
	/* 0x4cfa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4cff:
	/* 0x4cff: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d04:
	/* 0x4d04: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d09:
	/* 0x4d09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d0b:
	/* 0x4d0b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d0d:
	/* 0x4d0d: js     6988 <generic_sleepable_preload+0x6988> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27016ULL;
	}
x86_l_4d13:
	/* 0x4d13: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4d18:
	/* 0x4d18: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_4d21:
	/* 0x4d21: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4d26:
	/* 0x4d26: je     65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26095ULL;
	}
x86_l_4d2c:
	/* 0x4d2c: mov    ecx,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_4d33:
	/* 0x4d33: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4d38:
	/* 0x4d38: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d3d:
	/* 0x4d3d: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_4d46:
	/* 0x4d46: je     65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26095ULL;
	}
x86_l_4d4c:
	/* 0x4d4c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d51:
	/* 0x4d51: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4d56:
	/* 0x4d56: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4d5b:
	/* 0x4d5b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d60:
	/* 0x4d60: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d65:
	/* 0x4d65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d67:
	/* 0x4d67: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d69:
	/* 0x4d69: jns    65ef <generic_sleepable_preload+0x65ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 26095ULL;
	}
x86_l_4d6f:
	/* 0x4d6f: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_4d74:
	/* 0x4d74: jmp    65ed <generic_sleepable_preload+0x65ed> */
	return 26093ULL;
x86_l_4d79:
	/* 0x4d79: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_4d7e:
	/* 0x4d7e: jmp    65ed <generic_sleepable_preload+0x65ed> */
	return 26093ULL;
x86_l_4d83:
	/* 0x4d83: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4d8b:
	/* 0x4d8b: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_4d8e:
	/* 0x4d8e: je     4d9a <generic_sleepable_preload+0x4d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d9a;
	}
x86_l_4d90:
	/* 0x4d90: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4d95:
	/* 0x4d95: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4d98:
	/* 0x4d98: jne    4dad <generic_sleepable_preload+0x4dad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4dad;
	}
x86_l_4d9a:
	/* 0x4d9a: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_4d9d:
	/* 0x4d9d: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_4d9f:
	/* 0x4d9f: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_4da1:
	/* 0x4da1: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_4da6:
	/* 0x4da6: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4da8:
	/* 0x4da8: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_4dad:
	/* 0x4dad: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4db2:
	/* 0x4db2: mov    r14d,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4db6:
	/* 0x4db6: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4db8:
	/* 0x4db8: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_4dbb:
	/* 0x4dbb: cmp    WORD PTR [r13+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_4dc4:
	/* 0x4dc4: je     66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26276ULL;
	}
x86_l_4dca:
	/* 0x4dca: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_4dd1:
	/* 0x4dd1: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_4dd4:
	/* 0x4dd4: mov    eax,DWORD PTR [r13+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_4ddb:
	/* 0x4ddb: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4dde:
	/* 0x4dde: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4de3:
	/* 0x4de3: movzx  eax,WORD PTR [r13+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_4deb:
	/* 0x4deb: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_4ded:
	/* 0x4ded: je     50d3 <generic_sleepable_preload+0x50d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50d3;
	}
x86_l_4df3:
	/* 0x4df3: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4df6:
	/* 0x4df6: je     4e1b <generic_sleepable_preload+0x4e1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e1b;
	}
x86_l_4df8:
	/* 0x4df8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4dfd:
	/* 0x4dfd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4e02:
	/* 0x4e02: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e07:
	/* 0x4e07: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e0c:
	/* 0x4e0c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e11:
	/* 0x4e11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e13:
	/* 0x4e13: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e15:
	/* 0x4e15: js     53d1 <generic_sleepable_preload+0x53d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21457ULL;
	}
x86_l_4e1b:
	/* 0x4e1b: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_4e24:
	/* 0x4e24: je     66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26276ULL;
	}
x86_l_4e2a:
	/* 0x4e2a: mov    ecx,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_4e31:
	/* 0x4e31: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4e36:
	/* 0x4e36: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e3b:
	/* 0x4e3b: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_4e44:
	/* 0x4e44: je     4e69 <generic_sleepable_preload+0x4e69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e69;
	}
x86_l_4e46:
	/* 0x4e46: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e4b:
	/* 0x4e4b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4e50:
	/* 0x4e50: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e55:
	/* 0x4e55: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e5a:
	/* 0x4e5a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e5f:
	/* 0x4e5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e61:
	/* 0x4e61: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e63:
	/* 0x4e63: js     5445 <generic_sleepable_preload+0x5445> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21573ULL;
	}
x86_l_4e69:
	/* 0x4e69: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_4e72:
	/* 0x4e72: je     66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26276ULL;
	}
x86_l_4e78:
	/* 0x4e78: mov    ecx,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_4e7f:
	/* 0x4e7f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4e84:
	/* 0x4e84: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e89:
	/* 0x4e89: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_4e92:
	/* 0x4e92: je     4eb7 <generic_sleepable_preload+0x4eb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4eb7;
	}
x86_l_4e94:
	/* 0x4e94: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e99:
	/* 0x4e99: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4e9e:
	/* 0x4e9e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ea3:
	/* 0x4ea3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ea8:
	/* 0x4ea8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ead:
	/* 0x4ead: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4eaf:
	/* 0x4eaf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4eb1:
	/* 0x4eb1: js     612c <generic_sleepable_preload+0x612c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24876ULL;
	}
x86_l_4eb7:
	/* 0x4eb7: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_4ec0:
	/* 0x4ec0: je     66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26276ULL;
	}
x86_l_4ec6:
	/* 0x4ec6: mov    ecx,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_4ecd:
	/* 0x4ecd: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4ed2:
	/* 0x4ed2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ed7:
	/* 0x4ed7: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_4ee0:
	/* 0x4ee0: je     4f05 <generic_sleepable_preload+0x4f05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f05;
	}
x86_l_4ee2:
	/* 0x4ee2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ee7:
	/* 0x4ee7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4eec:
	/* 0x4eec: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ef1:
	/* 0x4ef1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ef6:
	/* 0x4ef6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4efb:
	/* 0x4efb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4efd:
	/* 0x4efd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4eff:
	/* 0x4eff: js     6190 <generic_sleepable_preload+0x6190> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24976ULL;
	}
x86_l_4f05:
	/* 0x4f05: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_4f0e:
	/* 0x4f0e: je     66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26276ULL;
	}
x86_l_4f14:
	/* 0x4f14: mov    ecx,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_4f1b:
	/* 0x4f1b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4f20:
	/* 0x4f20: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f25:
	/* 0x4f25: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_4f2e:
	/* 0x4f2e: je     4f53 <generic_sleepable_preload+0x4f53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f53;
	}
x86_l_4f30:
	/* 0x4f30: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f35:
	/* 0x4f35: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4f3a:
	/* 0x4f3a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4f3f:
	/* 0x4f3f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f44:
	/* 0x4f44: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f49:
	/* 0x4f49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f4b:
	/* 0x4f4b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f4d:
	/* 0x4f4d: js     61f4 <generic_sleepable_preload+0x61f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25076ULL;
	}
x86_l_4f53:
	/* 0x4f53: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_4f5c:
	/* 0x4f5c: je     66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26276ULL;
	}
x86_l_4f62:
	/* 0x4f62: mov    ecx,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_4f69:
	/* 0x4f69: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4f6e:
	/* 0x4f6e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f73:
	/* 0x4f73: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_4f7c:
	/* 0x4f7c: je     4fa1 <generic_sleepable_preload+0x4fa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fa1;
	}
x86_l_4f7e:
	/* 0x4f7e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f83:
	/* 0x4f83: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4f88:
	/* 0x4f88: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4f8d:
	/* 0x4f8d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f92:
	/* 0x4f92: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f97:
	/* 0x4f97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f99:
	/* 0x4f99: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f9b:
	/* 0x4f9b: js     6255 <generic_sleepable_preload+0x6255> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25173ULL;
	}
x86_l_4fa1:
	/* 0x4fa1: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_4faa:
	/* 0x4faa: je     66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26276ULL;
	}
x86_l_4fb0:
	/* 0x4fb0: mov    ecx,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_4fb7:
	/* 0x4fb7: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4fbc:
	/* 0x4fbc: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fc1:
	/* 0x4fc1: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_4fca:
	/* 0x4fca: je     4fef <generic_sleepable_preload+0x4fef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fef;
	}
x86_l_4fcc:
	/* 0x4fcc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fd1:
	/* 0x4fd1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4fd6:
	/* 0x4fd6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4fdb:
	/* 0x4fdb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fe0:
	/* 0x4fe0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4fe5:
	/* 0x4fe5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fe7:
	/* 0x4fe7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4fe9:
	/* 0x4fe9: js     669d <generic_sleepable_preload+0x669d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26269ULL;
	}
x86_l_4fef:
	/* 0x4fef: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_4ff8:
	/* 0x4ff8: je     66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26276ULL;
	}
x86_l_4ffe:
	/* 0x4ffe: mov    ecx,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_5005:
	/* 0x5005: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_500a:
	/* 0x500a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_500f:
	/* 0x500f: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_5018:
	/* 0x5018: je     503d <generic_sleepable_preload+0x503d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_503d;
	}
x86_l_501a:
	/* 0x501a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_501f:
	/* 0x501f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5024:
	/* 0x5024: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5029:
	/* 0x5029: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_502e:
	/* 0x502e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5033:
	/* 0x5033: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5035:
	/* 0x5035: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5037:
	/* 0x5037: js     6918 <generic_sleepable_preload+0x6918> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26904ULL;
	}
x86_l_503d:
	/* 0x503d: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_5046:
	/* 0x5046: je     66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26276ULL;
	}
x86_l_504c:
	/* 0x504c: mov    ecx,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_5053:
	/* 0x5053: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5058:
	/* 0x5058: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_505d:
	/* 0x505d: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_5066:
	/* 0x5066: je     508b <generic_sleepable_preload+0x508b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_508b;
	}
x86_l_5068:
	/* 0x5068: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_506d:
	/* 0x506d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5072:
	/* 0x5072: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5077:
	/* 0x5077: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_507c:
	/* 0x507c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5081:
	/* 0x5081: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5083:
	/* 0x5083: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5085:
	/* 0x5085: js     6994 <generic_sleepable_preload+0x6994> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27028ULL;
	}
x86_l_508b:
	/* 0x508b: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5090:
	/* 0x5090: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_5099:
	/* 0x5099: je     66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26276ULL;
	}
x86_l_509f:
	/* 0x509f: mov    ecx,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_50a6:
	/* 0x50a6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_50ab:
	/* 0x50ab: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50b0:
	/* 0x50b0: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_50b9:
	/* 0x50b9: je     66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26276ULL;
	}
x86_l_50bf:
	/* 0x50bf: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50c4:
	/* 0x50c4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_50c9:
	/* 0x50c9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_50ce:
	/* 0x50ce: jmp    53b3 <generic_sleepable_preload+0x53b3> */
	return 21427ULL;
x86_l_50d3:
	/* 0x50d3: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_50d6:
	/* 0x50d6: je     50fb <generic_sleepable_preload+0x50fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50fb;
	}
x86_l_50d8:
	/* 0x50d8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50dd:
	/* 0x50dd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_50e2:
	/* 0x50e2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_50e7:
	/* 0x50e7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50ec:
	/* 0x50ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50f1:
	/* 0x50f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50f3:
	/* 0x50f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_50f5:
	/* 0x50f5: js     53d1 <generic_sleepable_preload+0x53d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21457ULL;
	}
x86_l_50fb:
	/* 0x50fb: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_5104:
	/* 0x5104: je     66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26276ULL;
	}
x86_l_510a:
	/* 0x510a: mov    ecx,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_5111:
	/* 0x5111: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5116:
	/* 0x5116: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_511b:
	/* 0x511b: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_5124:
	/* 0x5124: je     5149 <generic_sleepable_preload+0x5149> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5149;
	}
x86_l_5126:
	/* 0x5126: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_512b:
	/* 0x512b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5130:
	/* 0x5130: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5135:
	/* 0x5135: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_513a:
	/* 0x513a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_513f:
	/* 0x513f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5141:
	/* 0x5141: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5143:
	/* 0x5143: js     5445 <generic_sleepable_preload+0x5445> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21573ULL;
	}
x86_l_5149:
	/* 0x5149: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_5152:
	/* 0x5152: je     66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26276ULL;
	}
x86_l_5158:
	/* 0x5158: mov    ecx,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_515f:
	/* 0x515f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5164:
	/* 0x5164: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5169:
	/* 0x5169: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_5172:
	/* 0x5172: je     5197 <generic_sleepable_preload+0x5197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5197;
	}
x86_l_5174:
	/* 0x5174: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5179:
	/* 0x5179: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_517e:
	/* 0x517e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5183:
	/* 0x5183: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5188:
	/* 0x5188: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_518d:
	/* 0x518d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_518f:
	/* 0x518f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5191:
	/* 0x5191: js     612c <generic_sleepable_preload+0x612c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24876ULL;
	}
x86_l_5197:
	/* 0x5197: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
	return 20896ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 20896ULL: goto x86_l_51a0;
	case 20902ULL: goto x86_l_51a6;
	case 20909ULL: goto x86_l_51ad;
	case 20914ULL: goto x86_l_51b2;
	case 20919ULL: goto x86_l_51b7;
	case 20928ULL: goto x86_l_51c0;
	case 20930ULL: goto x86_l_51c2;
	case 20935ULL: goto x86_l_51c7;
	case 20940ULL: goto x86_l_51cc;
	case 20945ULL: goto x86_l_51d1;
	case 20950ULL: goto x86_l_51d6;
	case 20955ULL: goto x86_l_51db;
	case 20957ULL: goto x86_l_51dd;
	case 20959ULL: goto x86_l_51df;
	case 20965ULL: goto x86_l_51e5;
	case 20974ULL: goto x86_l_51ee;
	case 20980ULL: goto x86_l_51f4;
	case 20987ULL: goto x86_l_51fb;
	case 20992ULL: goto x86_l_5200;
	case 20997ULL: goto x86_l_5205;
	case 21006ULL: goto x86_l_520e;
	case 21008ULL: goto x86_l_5210;
	case 21013ULL: goto x86_l_5215;
	case 21018ULL: goto x86_l_521a;
	case 21023ULL: goto x86_l_521f;
	case 21028ULL: goto x86_l_5224;
	case 21033ULL: goto x86_l_5229;
	case 21035ULL: goto x86_l_522b;
	case 21037ULL: goto x86_l_522d;
	case 21043ULL: goto x86_l_5233;
	case 21052ULL: goto x86_l_523c;
	case 21058ULL: goto x86_l_5242;
	case 21065ULL: goto x86_l_5249;
	case 21070ULL: goto x86_l_524e;
	case 21075ULL: goto x86_l_5253;
	case 21084ULL: goto x86_l_525c;
	case 21086ULL: goto x86_l_525e;
	case 21091ULL: goto x86_l_5263;
	case 21096ULL: goto x86_l_5268;
	case 21101ULL: goto x86_l_526d;
	case 21106ULL: goto x86_l_5272;
	case 21111ULL: goto x86_l_5277;
	case 21113ULL: goto x86_l_5279;
	case 21115ULL: goto x86_l_527b;
	case 21121ULL: goto x86_l_5281;
	case 21130ULL: goto x86_l_528a;
	case 21136ULL: goto x86_l_5290;
	case 21143ULL: goto x86_l_5297;
	case 21148ULL: goto x86_l_529c;
	case 21153ULL: goto x86_l_52a1;
	case 21162ULL: goto x86_l_52aa;
	case 21164ULL: goto x86_l_52ac;
	case 21169ULL: goto x86_l_52b1;
	case 21174ULL: goto x86_l_52b6;
	case 21179ULL: goto x86_l_52bb;
	case 21184ULL: goto x86_l_52c0;
	case 21189ULL: goto x86_l_52c5;
	case 21191ULL: goto x86_l_52c7;
	case 21193ULL: goto x86_l_52c9;
	case 21199ULL: goto x86_l_52cf;
	case 21208ULL: goto x86_l_52d8;
	case 21214ULL: goto x86_l_52de;
	case 21221ULL: goto x86_l_52e5;
	case 21226ULL: goto x86_l_52ea;
	case 21231ULL: goto x86_l_52ef;
	case 21240ULL: goto x86_l_52f8;
	case 21242ULL: goto x86_l_52fa;
	case 21247ULL: goto x86_l_52ff;
	case 21252ULL: goto x86_l_5304;
	case 21257ULL: goto x86_l_5309;
	case 21262ULL: goto x86_l_530e;
	case 21267ULL: goto x86_l_5313;
	case 21269ULL: goto x86_l_5315;
	case 21271ULL: goto x86_l_5317;
	case 21277ULL: goto x86_l_531d;
	case 21282ULL: goto x86_l_5322;
	case 21291ULL: goto x86_l_532b;
	case 21297ULL: goto x86_l_5331;
	case 21304ULL: goto x86_l_5338;
	case 21309ULL: goto x86_l_533d;
	case 21314ULL: goto x86_l_5342;
	case 21323ULL: goto x86_l_534b;
	case 21325ULL: goto x86_l_534d;
	case 21330ULL: goto x86_l_5352;
	case 21335ULL: goto x86_l_5357;
	case 21340ULL: goto x86_l_535c;
	case 21345ULL: goto x86_l_5361;
	case 21350ULL: goto x86_l_5366;
	case 21352ULL: goto x86_l_5368;
	case 21354ULL: goto x86_l_536a;
	case 21360ULL: goto x86_l_5370;
	case 21365ULL: goto x86_l_5375;
	case 21374ULL: goto x86_l_537e;
	case 21380ULL: goto x86_l_5384;
	case 21387ULL: goto x86_l_538b;
	case 21392ULL: goto x86_l_5390;
	case 21397ULL: goto x86_l_5395;
	case 21406ULL: goto x86_l_539e;
	case 21412ULL: goto x86_l_53a4;
	case 21417ULL: goto x86_l_53a9;
	case 21422ULL: goto x86_l_53ae;
	case 21427ULL: goto x86_l_53b3;
	case 21432ULL: goto x86_l_53b8;
	case 21437ULL: goto x86_l_53bd;
	case 21439ULL: goto x86_l_53bf;
	case 21441ULL: goto x86_l_53c1;
	case 21447ULL: goto x86_l_53c7;
	case 21452ULL: goto x86_l_53cc;
	case 21457ULL: goto x86_l_53d1;
	case 21462ULL: goto x86_l_53d6;
	case 21467ULL: goto x86_l_53db;
	case 21475ULL: goto x86_l_53e3;
	case 21478ULL: goto x86_l_53e6;
	case 21484ULL: goto x86_l_53ec;
	case 21489ULL: goto x86_l_53f1;
	case 21492ULL: goto x86_l_53f4;
	case 21498ULL: goto x86_l_53fa;
	case 21503ULL: goto x86_l_53ff;
	case 21508ULL: goto x86_l_5404;
	case 21513ULL: goto x86_l_5409;
	case 21518ULL: goto x86_l_540e;
	case 21523ULL: goto x86_l_5413;
	case 21528ULL: goto x86_l_5418;
	case 21533ULL: goto x86_l_541d;
	case 21538ULL: goto x86_l_5422;
	case 21543ULL: goto x86_l_5427;
	case 21548ULL: goto x86_l_542c;
	case 21553ULL: goto x86_l_5431;
	case 21558ULL: goto x86_l_5436;
	case 21563ULL: goto x86_l_543b;
	case 21568ULL: goto x86_l_5440;
	case 21573ULL: goto x86_l_5445;
	case 21578ULL: goto x86_l_544a;
	case 21583ULL: goto x86_l_544f;
	case 21586ULL: goto x86_l_5452;
	case 21589ULL: goto x86_l_5455;
	case 21591ULL: goto x86_l_5457;
	case 21593ULL: goto x86_l_5459;
	case 21598ULL: goto x86_l_545e;
	case 21600ULL: goto x86_l_5460;
	case 21605ULL: goto x86_l_5465;
	case 21610ULL: goto x86_l_546a;
	case 21614ULL: goto x86_l_546e;
	case 21616ULL: goto x86_l_5470;
	case 21619ULL: goto x86_l_5473;
	case 21628ULL: goto x86_l_547c;
	case 21634ULL: goto x86_l_5482;
	case 21641ULL: goto x86_l_5489;
	case 21644ULL: goto x86_l_548c;
	case 21651ULL: goto x86_l_5493;
	case 21654ULL: goto x86_l_5496;
	case 21659ULL: goto x86_l_549b;
	case 21667ULL: goto x86_l_54a3;
	case 21669ULL: goto x86_l_54a5;
	case 21675ULL: goto x86_l_54ab;
	case 21678ULL: goto x86_l_54ae;
	case 21680ULL: goto x86_l_54b0;
	case 21685ULL: goto x86_l_54b5;
	case 21690ULL: goto x86_l_54ba;
	case 21695ULL: goto x86_l_54bf;
	case 21700ULL: goto x86_l_54c4;
	case 21705ULL: goto x86_l_54c9;
	case 21707ULL: goto x86_l_54cb;
	case 21709ULL: goto x86_l_54cd;
	case 21715ULL: goto x86_l_54d3;
	case 21724ULL: goto x86_l_54dc;
	case 21730ULL: goto x86_l_54e2;
	case 21737ULL: goto x86_l_54e9;
	case 21742ULL: goto x86_l_54ee;
	case 21747ULL: goto x86_l_54f3;
	case 21756ULL: goto x86_l_54fc;
	case 21758ULL: goto x86_l_54fe;
	case 21763ULL: goto x86_l_5503;
	case 21768ULL: goto x86_l_5508;
	case 21773ULL: goto x86_l_550d;
	case 21778ULL: goto x86_l_5512;
	case 21783ULL: goto x86_l_5517;
	case 21785ULL: goto x86_l_5519;
	case 21787ULL: goto x86_l_551b;
	case 21793ULL: goto x86_l_5521;
	case 21802ULL: goto x86_l_552a;
	case 21808ULL: goto x86_l_5530;
	case 21815ULL: goto x86_l_5537;
	case 21820ULL: goto x86_l_553c;
	case 21825ULL: goto x86_l_5541;
	case 21834ULL: goto x86_l_554a;
	case 21836ULL: goto x86_l_554c;
	case 21841ULL: goto x86_l_5551;
	case 21846ULL: goto x86_l_5556;
	case 21851ULL: goto x86_l_555b;
	case 21856ULL: goto x86_l_5560;
	case 21861ULL: goto x86_l_5565;
	case 21863ULL: goto x86_l_5567;
	case 21865ULL: goto x86_l_5569;
	case 21871ULL: goto x86_l_556f;
	case 21880ULL: goto x86_l_5578;
	case 21886ULL: goto x86_l_557e;
	case 21893ULL: goto x86_l_5585;
	case 21898ULL: goto x86_l_558a;
	case 21903ULL: goto x86_l_558f;
	case 21912ULL: goto x86_l_5598;
	case 21914ULL: goto x86_l_559a;
	case 21919ULL: goto x86_l_559f;
	case 21924ULL: goto x86_l_55a4;
	case 21929ULL: goto x86_l_55a9;
	case 21934ULL: goto x86_l_55ae;
	case 21939ULL: goto x86_l_55b3;
	case 21941ULL: goto x86_l_55b5;
	case 21943ULL: goto x86_l_55b7;
	case 21949ULL: goto x86_l_55bd;
	case 21958ULL: goto x86_l_55c6;
	case 21964ULL: goto x86_l_55cc;
	case 21971ULL: goto x86_l_55d3;
	case 21976ULL: goto x86_l_55d8;
	case 21981ULL: goto x86_l_55dd;
	case 21990ULL: goto x86_l_55e6;
	case 21992ULL: goto x86_l_55e8;
	case 21997ULL: goto x86_l_55ed;
	case 22002ULL: goto x86_l_55f2;
	case 22007ULL: goto x86_l_55f7;
	case 22012ULL: goto x86_l_55fc;
	case 22017ULL: goto x86_l_5601;
	case 22019ULL: goto x86_l_5603;
	case 22021ULL: goto x86_l_5605;
	case 22027ULL: goto x86_l_560b;
	case 22036ULL: goto x86_l_5614;
	case 22042ULL: goto x86_l_561a;
	case 22049ULL: goto x86_l_5621;
	case 22054ULL: goto x86_l_5626;
	case 22059ULL: goto x86_l_562b;
	case 22068ULL: goto x86_l_5634;
	case 22070ULL: goto x86_l_5636;
	case 22075ULL: goto x86_l_563b;
	case 22080ULL: goto x86_l_5640;
	case 22085ULL: goto x86_l_5645;
	case 22090ULL: goto x86_l_564a;
	case 22095ULL: goto x86_l_564f;
	case 22097ULL: goto x86_l_5651;
	case 22099ULL: goto x86_l_5653;
	case 22105ULL: goto x86_l_5659;
	case 22114ULL: goto x86_l_5662;
	case 22120ULL: goto x86_l_5668;
	case 22127ULL: goto x86_l_566f;
	case 22132ULL: goto x86_l_5674;
	case 22137ULL: goto x86_l_5679;
	case 22146ULL: goto x86_l_5682;
	case 22148ULL: goto x86_l_5684;
	case 22153ULL: goto x86_l_5689;
	case 22158ULL: goto x86_l_568e;
	case 22163ULL: goto x86_l_5693;
	case 22168ULL: goto x86_l_5698;
	case 22173ULL: goto x86_l_569d;
	case 22175ULL: goto x86_l_569f;
	case 22177ULL: goto x86_l_56a1;
	case 22183ULL: goto x86_l_56a7;
	case 22192ULL: goto x86_l_56b0;
	case 22198ULL: goto x86_l_56b6;
	case 22205ULL: goto x86_l_56bd;
	case 22210ULL: goto x86_l_56c2;
	case 22215ULL: goto x86_l_56c7;
	case 22224ULL: goto x86_l_56d0;
	case 22226ULL: goto x86_l_56d2;
	case 22231ULL: goto x86_l_56d7;
	case 22236ULL: goto x86_l_56dc;
	case 22241ULL: goto x86_l_56e1;
	case 22246ULL: goto x86_l_56e6;
	case 22251ULL: goto x86_l_56eb;
	case 22253ULL: goto x86_l_56ed;
	case 22255ULL: goto x86_l_56ef;
	case 22261ULL: goto x86_l_56f5;
	case 22270ULL: goto x86_l_56fe;
	case 22276ULL: goto x86_l_5704;
	case 22283ULL: goto x86_l_570b;
	case 22288ULL: goto x86_l_5710;
	case 22293ULL: goto x86_l_5715;
	case 22302ULL: goto x86_l_571e;
	case 22304ULL: goto x86_l_5720;
	case 22309ULL: goto x86_l_5725;
	case 22314ULL: goto x86_l_572a;
	case 22319ULL: goto x86_l_572f;
	case 22324ULL: goto x86_l_5734;
	case 22329ULL: goto x86_l_5739;
	case 22331ULL: goto x86_l_573b;
	case 22333ULL: goto x86_l_573d;
	case 22339ULL: goto x86_l_5743;
	case 22344ULL: goto x86_l_5748;
	case 22353ULL: goto x86_l_5751;
	case 22359ULL: goto x86_l_5757;
	case 22366ULL: goto x86_l_575e;
	case 22371ULL: goto x86_l_5763;
	case 22376ULL: goto x86_l_5768;
	case 22385ULL: goto x86_l_5771;
	case 22391ULL: goto x86_l_5777;
	case 22396ULL: goto x86_l_577c;
	case 22401ULL: goto x86_l_5781;
	case 22406ULL: goto x86_l_5786;
	case 22411ULL: goto x86_l_578b;
	case 22414ULL: goto x86_l_578e;
	case 22416ULL: goto x86_l_5790;
	case 22421ULL: goto x86_l_5795;
	case 22426ULL: goto x86_l_579a;
	case 22431ULL: goto x86_l_579f;
	case 22436ULL: goto x86_l_57a4;
	case 22441ULL: goto x86_l_57a9;
	case 22443ULL: goto x86_l_57ab;
	case 22445ULL: goto x86_l_57ad;
	case 22451ULL: goto x86_l_57b3;
	case 22460ULL: goto x86_l_57bc;
	case 22466ULL: goto x86_l_57c2;
	case 22473ULL: goto x86_l_57c9;
	case 22478ULL: goto x86_l_57ce;
	case 22483ULL: goto x86_l_57d3;
	case 22492ULL: goto x86_l_57dc;
	case 22494ULL: goto x86_l_57de;
	case 22499ULL: goto x86_l_57e3;
	case 22504ULL: goto x86_l_57e8;
	case 22509ULL: goto x86_l_57ed;
	case 22514ULL: goto x86_l_57f2;
	case 22519ULL: goto x86_l_57f7;
	case 22521ULL: goto x86_l_57f9;
	case 22523ULL: goto x86_l_57fb;
	case 22529ULL: goto x86_l_5801;
	case 22538ULL: goto x86_l_580a;
	case 22544ULL: goto x86_l_5810;
	case 22551ULL: goto x86_l_5817;
	case 22556ULL: goto x86_l_581c;
	case 22561ULL: goto x86_l_5821;
	case 22570ULL: goto x86_l_582a;
	case 22572ULL: goto x86_l_582c;
	case 22577ULL: goto x86_l_5831;
	case 22582ULL: goto x86_l_5836;
	case 22587ULL: goto x86_l_583b;
	case 22592ULL: goto x86_l_5840;
	case 22597ULL: goto x86_l_5845;
	case 22599ULL: goto x86_l_5847;
	case 22601ULL: goto x86_l_5849;
	case 22607ULL: goto x86_l_584f;
	case 22616ULL: goto x86_l_5858;
	case 22622ULL: goto x86_l_585e;
	case 22629ULL: goto x86_l_5865;
	case 22634ULL: goto x86_l_586a;
	case 22639ULL: goto x86_l_586f;
	case 22648ULL: goto x86_l_5878;
	case 22650ULL: goto x86_l_587a;
	case 22655ULL: goto x86_l_587f;
	case 22660ULL: goto x86_l_5884;
	case 22665ULL: goto x86_l_5889;
	case 22670ULL: goto x86_l_588e;
	case 22675ULL: goto x86_l_5893;
	case 22677ULL: goto x86_l_5895;
	case 22679ULL: goto x86_l_5897;
	case 22685ULL: goto x86_l_589d;
	case 22694ULL: goto x86_l_58a6;
	case 22700ULL: goto x86_l_58ac;
	case 22707ULL: goto x86_l_58b3;
	case 22712ULL: goto x86_l_58b8;
	case 22717ULL: goto x86_l_58bd;
	case 22726ULL: goto x86_l_58c6;
	case 22728ULL: goto x86_l_58c8;
	case 22733ULL: goto x86_l_58cd;
	case 22738ULL: goto x86_l_58d2;
	case 22743ULL: goto x86_l_58d7;
	case 22748ULL: goto x86_l_58dc;
	case 22753ULL: goto x86_l_58e1;
	case 22755ULL: goto x86_l_58e3;
	case 22757ULL: goto x86_l_58e5;
	case 22763ULL: goto x86_l_58eb;
	case 22772ULL: goto x86_l_58f4;
	case 22778ULL: goto x86_l_58fa;
	case 22785ULL: goto x86_l_5901;
	case 22790ULL: goto x86_l_5906;
	case 22795ULL: goto x86_l_590b;
	case 22804ULL: goto x86_l_5914;
	case 22806ULL: goto x86_l_5916;
	case 22811ULL: goto x86_l_591b;
	case 22816ULL: goto x86_l_5920;
	case 22821ULL: goto x86_l_5925;
	case 22826ULL: goto x86_l_592a;
	case 22831ULL: goto x86_l_592f;
	case 22833ULL: goto x86_l_5931;
	case 22835ULL: goto x86_l_5933;
	case 22841ULL: goto x86_l_5939;
	case 22850ULL: goto x86_l_5942;
	case 22856ULL: goto x86_l_5948;
	default: return 0xffffffffffffffffULL;
	}
x86_l_51a0:
	/* 0x51a0: je     66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26276ULL;
	}
x86_l_51a6:
	/* 0x51a6: mov    ecx,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_51ad:
	/* 0x51ad: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_51b2:
	/* 0x51b2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51b7:
	/* 0x51b7: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_51c0:
	/* 0x51c0: je     51e5 <generic_sleepable_preload+0x51e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_51e5;
	}
x86_l_51c2:
	/* 0x51c2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51c7:
	/* 0x51c7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_51cc:
	/* 0x51cc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_51d1:
	/* 0x51d1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51d6:
	/* 0x51d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51db:
	/* 0x51db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51dd:
	/* 0x51dd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_51df:
	/* 0x51df: js     6190 <generic_sleepable_preload+0x6190> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24976ULL;
	}
x86_l_51e5:
	/* 0x51e5: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_51ee:
	/* 0x51ee: je     66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26276ULL;
	}
x86_l_51f4:
	/* 0x51f4: mov    ecx,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_51fb:
	/* 0x51fb: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5200:
	/* 0x5200: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5205:
	/* 0x5205: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_520e:
	/* 0x520e: je     5233 <generic_sleepable_preload+0x5233> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5233;
	}
x86_l_5210:
	/* 0x5210: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5215:
	/* 0x5215: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_521a:
	/* 0x521a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_521f:
	/* 0x521f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5224:
	/* 0x5224: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5229:
	/* 0x5229: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_522b:
	/* 0x522b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_522d:
	/* 0x522d: js     61f4 <generic_sleepable_preload+0x61f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25076ULL;
	}
x86_l_5233:
	/* 0x5233: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_523c:
	/* 0x523c: je     66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26276ULL;
	}
x86_l_5242:
	/* 0x5242: mov    ecx,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_5249:
	/* 0x5249: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_524e:
	/* 0x524e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5253:
	/* 0x5253: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_525c:
	/* 0x525c: je     5281 <generic_sleepable_preload+0x5281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5281;
	}
x86_l_525e:
	/* 0x525e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5263:
	/* 0x5263: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5268:
	/* 0x5268: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_526d:
	/* 0x526d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5272:
	/* 0x5272: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5277:
	/* 0x5277: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5279:
	/* 0x5279: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_527b:
	/* 0x527b: js     6255 <generic_sleepable_preload+0x6255> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25173ULL;
	}
x86_l_5281:
	/* 0x5281: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_528a:
	/* 0x528a: je     66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26276ULL;
	}
x86_l_5290:
	/* 0x5290: mov    ecx,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_5297:
	/* 0x5297: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_529c:
	/* 0x529c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52a1:
	/* 0x52a1: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_52aa:
	/* 0x52aa: je     52cf <generic_sleepable_preload+0x52cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_52cf;
	}
x86_l_52ac:
	/* 0x52ac: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52b1:
	/* 0x52b1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_52b6:
	/* 0x52b6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_52bb:
	/* 0x52bb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52c0:
	/* 0x52c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52c5:
	/* 0x52c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52c7:
	/* 0x52c7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52c9:
	/* 0x52c9: js     669d <generic_sleepable_preload+0x669d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26269ULL;
	}
x86_l_52cf:
	/* 0x52cf: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_52d8:
	/* 0x52d8: je     66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26276ULL;
	}
x86_l_52de:
	/* 0x52de: mov    ecx,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_52e5:
	/* 0x52e5: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_52ea:
	/* 0x52ea: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52ef:
	/* 0x52ef: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_52f8:
	/* 0x52f8: je     531d <generic_sleepable_preload+0x531d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_531d;
	}
x86_l_52fa:
	/* 0x52fa: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52ff:
	/* 0x52ff: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5304:
	/* 0x5304: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5309:
	/* 0x5309: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_530e:
	/* 0x530e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5313:
	/* 0x5313: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5315:
	/* 0x5315: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5317:
	/* 0x5317: js     6a4c <generic_sleepable_preload+0x6a4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27212ULL;
	}
x86_l_531d:
	/* 0x531d: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5322:
	/* 0x5322: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_532b:
	/* 0x532b: je     66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26276ULL;
	}
x86_l_5331:
	/* 0x5331: mov    ecx,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_5338:
	/* 0x5338: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_533d:
	/* 0x533d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5342:
	/* 0x5342: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_534b:
	/* 0x534b: je     5370 <generic_sleepable_preload+0x5370> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5370;
	}
x86_l_534d:
	/* 0x534d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5352:
	/* 0x5352: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5357:
	/* 0x5357: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_535c:
	/* 0x535c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5361:
	/* 0x5361: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5366:
	/* 0x5366: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5368:
	/* 0x5368: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_536a:
	/* 0x536a: js     6994 <generic_sleepable_preload+0x6994> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27028ULL;
	}
x86_l_5370:
	/* 0x5370: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5375:
	/* 0x5375: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_537e:
	/* 0x537e: je     66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26276ULL;
	}
x86_l_5384:
	/* 0x5384: mov    ecx,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_538b:
	/* 0x538b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5390:
	/* 0x5390: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5395:
	/* 0x5395: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_539e:
	/* 0x539e: je     66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26276ULL;
	}
x86_l_53a4:
	/* 0x53a4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53a9:
	/* 0x53a9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_53ae:
	/* 0x53ae: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_53b3:
	/* 0x53b3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53b8:
	/* 0x53b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53bd:
	/* 0x53bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53bf:
	/* 0x53bf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_53c1:
	/* 0x53c1: jns    66a4 <generic_sleepable_preload+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 26276ULL;
	}
x86_l_53c7:
	/* 0x53c7: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_53cc:
	/* 0x53cc: jmp    66a2 <generic_sleepable_preload+0x66a2> */
	return 26274ULL;
x86_l_53d1:
	/* 0x53d1: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_53d6:
	/* 0x53d6: jmp    66a2 <generic_sleepable_preload+0x66a2> */
	return 26274ULL;
x86_l_53db:
	/* 0x53db: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_53e3:
	/* 0x53e3: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_53e6:
	/* 0x53e6: je     5aa2 <generic_sleepable_preload+0x5aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23202ULL;
	}
x86_l_53ec:
	/* 0x53ec: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_53f1:
	/* 0x53f1: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_53f4:
	/* 0x53f4: je     5aa2 <generic_sleepable_preload+0x5aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23202ULL;
	}
x86_l_53fa:
	/* 0x53fa: jmp    5ab5 <generic_sleepable_preload+0x5ab5> */
	return 23221ULL;
x86_l_53ff:
	/* 0x53ff: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5404:
	/* 0x5404: jmp    6278 <generic_sleepable_preload+0x6278> */
	return 25208ULL;
x86_l_5409:
	/* 0x5409: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_540e:
	/* 0x540e: jmp    6305 <generic_sleepable_preload+0x6305> */
	return 25349ULL;
x86_l_5413:
	/* 0x5413: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5418:
	/* 0x5418: jmp    6392 <generic_sleepable_preload+0x6392> */
	return 25490ULL;
x86_l_541d:
	/* 0x541d: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5422:
	/* 0x5422: jmp    641f <generic_sleepable_preload+0x641f> */
	return 25631ULL;
x86_l_5427:
	/* 0x5427: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_542c:
	/* 0x542c: jmp    64ac <generic_sleepable_preload+0x64ac> */
	return 25772ULL;
x86_l_5431:
	/* 0x5431: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5436:
	/* 0x5436: jmp    6539 <generic_sleepable_preload+0x6539> */
	return 25913ULL;
x86_l_543b:
	/* 0x543b: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5440:
	/* 0x5440: jmp    65ed <generic_sleepable_preload+0x65ed> */
	return 26093ULL;
x86_l_5445:
	/* 0x5445: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_544a:
	/* 0x544a: jmp    66a2 <generic_sleepable_preload+0x66a2> */
	return 26274ULL;
x86_l_544f:
	/* 0x544f: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5452:
	/* 0x5452: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_5455:
	/* 0x5455: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_5457:
	/* 0x5457: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_5459:
	/* 0x5459: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_545e:
	/* 0x545e: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5460:
	/* 0x5460: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_5465:
	/* 0x5465: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_546a:
	/* 0x546a: mov    r14d,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_546e:
	/* 0x546e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5470:
	/* 0x5470: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_5473:
	/* 0x5473: cmp    WORD PTR [r13+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_547c:
	/* 0x547c: je     6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26452ULL;
	}
x86_l_5482:
	/* 0x5482: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_5489:
	/* 0x5489: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_548c:
	/* 0x548c: mov    eax,DWORD PTR [r13+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_5493:
	/* 0x5493: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5496:
	/* 0x5496: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_549b:
	/* 0x549b: movzx  eax,WORD PTR [r13+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_54a3:
	/* 0x54a3: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_54a5:
	/* 0x54a5: je     578b <generic_sleepable_preload+0x578b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_578b;
	}
x86_l_54ab:
	/* 0x54ab: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_54ae:
	/* 0x54ae: je     54d3 <generic_sleepable_preload+0x54d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54d3;
	}
x86_l_54b0:
	/* 0x54b0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54b5:
	/* 0x54b5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_54ba:
	/* 0x54ba: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_54bf:
	/* 0x54bf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54c4:
	/* 0x54c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54c9:
	/* 0x54c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54cb:
	/* 0x54cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_54cd:
	/* 0x54cd: js     5a89 <generic_sleepable_preload+0x5a89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23177ULL;
	}
x86_l_54d3:
	/* 0x54d3: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_54dc:
	/* 0x54dc: je     6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26452ULL;
	}
x86_l_54e2:
	/* 0x54e2: mov    ecx,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_54e9:
	/* 0x54e9: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_54ee:
	/* 0x54ee: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54f3:
	/* 0x54f3: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_54fc:
	/* 0x54fc: je     5521 <generic_sleepable_preload+0x5521> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5521;
	}
x86_l_54fe:
	/* 0x54fe: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5503:
	/* 0x5503: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5508:
	/* 0x5508: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_550d:
	/* 0x550d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5512:
	/* 0x5512: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5517:
	/* 0x5517: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5519:
	/* 0x5519: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_551b:
	/* 0x551b: js     5a93 <generic_sleepable_preload+0x5a93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23187ULL;
	}
x86_l_5521:
	/* 0x5521: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_552a:
	/* 0x552a: je     6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26452ULL;
	}
x86_l_5530:
	/* 0x5530: mov    ecx,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_5537:
	/* 0x5537: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_553c:
	/* 0x553c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5541:
	/* 0x5541: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_554a:
	/* 0x554a: je     556f <generic_sleepable_preload+0x556f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_556f;
	}
x86_l_554c:
	/* 0x554c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5551:
	/* 0x5551: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5556:
	/* 0x5556: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_555b:
	/* 0x555b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5560:
	/* 0x5560: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5565:
	/* 0x5565: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5567:
	/* 0x5567: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5569:
	/* 0x5569: js     6136 <generic_sleepable_preload+0x6136> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24886ULL;
	}
x86_l_556f:
	/* 0x556f: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_5578:
	/* 0x5578: je     6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26452ULL;
	}
x86_l_557e:
	/* 0x557e: mov    ecx,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_5585:
	/* 0x5585: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_558a:
	/* 0x558a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_558f:
	/* 0x558f: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_5598:
	/* 0x5598: je     55bd <generic_sleepable_preload+0x55bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_55bd;
	}
x86_l_559a:
	/* 0x559a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_559f:
	/* 0x559f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_55a4:
	/* 0x55a4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_55a9:
	/* 0x55a9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55ae:
	/* 0x55ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55b3:
	/* 0x55b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55b5:
	/* 0x55b5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_55b7:
	/* 0x55b7: js     619a <generic_sleepable_preload+0x619a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24986ULL;
	}
x86_l_55bd:
	/* 0x55bd: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_55c6:
	/* 0x55c6: je     6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26452ULL;
	}
x86_l_55cc:
	/* 0x55cc: mov    ecx,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_55d3:
	/* 0x55d3: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_55d8:
	/* 0x55d8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55dd:
	/* 0x55dd: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_55e6:
	/* 0x55e6: je     560b <generic_sleepable_preload+0x560b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_560b;
	}
x86_l_55e8:
	/* 0x55e8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55ed:
	/* 0x55ed: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_55f2:
	/* 0x55f2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_55f7:
	/* 0x55f7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55fc:
	/* 0x55fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5601:
	/* 0x5601: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5603:
	/* 0x5603: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5605:
	/* 0x5605: js     61fe <generic_sleepable_preload+0x61fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25086ULL;
	}
x86_l_560b:
	/* 0x560b: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_5614:
	/* 0x5614: je     6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26452ULL;
	}
x86_l_561a:
	/* 0x561a: mov    ecx,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_5621:
	/* 0x5621: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5626:
	/* 0x5626: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_562b:
	/* 0x562b: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_5634:
	/* 0x5634: je     5659 <generic_sleepable_preload+0x5659> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5659;
	}
x86_l_5636:
	/* 0x5636: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_563b:
	/* 0x563b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5640:
	/* 0x5640: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5645:
	/* 0x5645: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_564a:
	/* 0x564a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_564f:
	/* 0x564f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5651:
	/* 0x5651: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5653:
	/* 0x5653: js     625f <generic_sleepable_preload+0x625f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25183ULL;
	}
x86_l_5659:
	/* 0x5659: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_5662:
	/* 0x5662: je     6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26452ULL;
	}
x86_l_5668:
	/* 0x5668: mov    ecx,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_566f:
	/* 0x566f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5674:
	/* 0x5674: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5679:
	/* 0x5679: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_5682:
	/* 0x5682: je     56a7 <generic_sleepable_preload+0x56a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56a7;
	}
x86_l_5684:
	/* 0x5684: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5689:
	/* 0x5689: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_568e:
	/* 0x568e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5693:
	/* 0x5693: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5698:
	/* 0x5698: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_569d:
	/* 0x569d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_569f:
	/* 0x569f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56a1:
	/* 0x56a1: js     674d <generic_sleepable_preload+0x674d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26445ULL;
	}
x86_l_56a7:
	/* 0x56a7: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_56b0:
	/* 0x56b0: je     6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26452ULL;
	}
x86_l_56b6:
	/* 0x56b6: mov    ecx,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_56bd:
	/* 0x56bd: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_56c2:
	/* 0x56c2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56c7:
	/* 0x56c7: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_56d0:
	/* 0x56d0: je     56f5 <generic_sleepable_preload+0x56f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56f5;
	}
x86_l_56d2:
	/* 0x56d2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56d7:
	/* 0x56d7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_56dc:
	/* 0x56dc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_56e1:
	/* 0x56e1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56e6:
	/* 0x56e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56eb:
	/* 0x56eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56ed:
	/* 0x56ed: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56ef:
	/* 0x56ef: js     6924 <generic_sleepable_preload+0x6924> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26916ULL;
	}
x86_l_56f5:
	/* 0x56f5: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_56fe:
	/* 0x56fe: je     6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26452ULL;
	}
x86_l_5704:
	/* 0x5704: mov    ecx,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_570b:
	/* 0x570b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5710:
	/* 0x5710: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5715:
	/* 0x5715: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_571e:
	/* 0x571e: je     5743 <generic_sleepable_preload+0x5743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5743;
	}
x86_l_5720:
	/* 0x5720: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5725:
	/* 0x5725: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_572a:
	/* 0x572a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_572f:
	/* 0x572f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5734:
	/* 0x5734: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5739:
	/* 0x5739: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_573b:
	/* 0x573b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_573d:
	/* 0x573d: js     69a5 <generic_sleepable_preload+0x69a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27045ULL;
	}
x86_l_5743:
	/* 0x5743: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5748:
	/* 0x5748: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_5751:
	/* 0x5751: je     6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26452ULL;
	}
x86_l_5757:
	/* 0x5757: mov    ecx,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_575e:
	/* 0x575e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5763:
	/* 0x5763: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5768:
	/* 0x5768: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_5771:
	/* 0x5771: je     6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26452ULL;
	}
x86_l_5777:
	/* 0x5777: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_577c:
	/* 0x577c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5781:
	/* 0x5781: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5786:
	/* 0x5786: jmp    5a6b <generic_sleepable_preload+0x5a6b> */
	return 23147ULL;
x86_l_578b:
	/* 0x578b: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_578e:
	/* 0x578e: je     57b3 <generic_sleepable_preload+0x57b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_57b3;
	}
x86_l_5790:
	/* 0x5790: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5795:
	/* 0x5795: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_579a:
	/* 0x579a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_579f:
	/* 0x579f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57a4:
	/* 0x57a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57a9:
	/* 0x57a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57ab:
	/* 0x57ab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_57ad:
	/* 0x57ad: js     5a89 <generic_sleepable_preload+0x5a89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23177ULL;
	}
x86_l_57b3:
	/* 0x57b3: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_57bc:
	/* 0x57bc: je     6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26452ULL;
	}
x86_l_57c2:
	/* 0x57c2: mov    ecx,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_57c9:
	/* 0x57c9: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_57ce:
	/* 0x57ce: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57d3:
	/* 0x57d3: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_57dc:
	/* 0x57dc: je     5801 <generic_sleepable_preload+0x5801> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5801;
	}
x86_l_57de:
	/* 0x57de: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57e3:
	/* 0x57e3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_57e8:
	/* 0x57e8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_57ed:
	/* 0x57ed: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57f2:
	/* 0x57f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57f7:
	/* 0x57f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57f9:
	/* 0x57f9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_57fb:
	/* 0x57fb: js     5a93 <generic_sleepable_preload+0x5a93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23187ULL;
	}
x86_l_5801:
	/* 0x5801: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_580a:
	/* 0x580a: je     6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26452ULL;
	}
x86_l_5810:
	/* 0x5810: mov    ecx,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_5817:
	/* 0x5817: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_581c:
	/* 0x581c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5821:
	/* 0x5821: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_582a:
	/* 0x582a: je     584f <generic_sleepable_preload+0x584f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_584f;
	}
x86_l_582c:
	/* 0x582c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5831:
	/* 0x5831: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5836:
	/* 0x5836: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_583b:
	/* 0x583b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5840:
	/* 0x5840: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5845:
	/* 0x5845: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5847:
	/* 0x5847: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5849:
	/* 0x5849: js     6136 <generic_sleepable_preload+0x6136> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24886ULL;
	}
x86_l_584f:
	/* 0x584f: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_5858:
	/* 0x5858: je     6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26452ULL;
	}
x86_l_585e:
	/* 0x585e: mov    ecx,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_5865:
	/* 0x5865: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_586a:
	/* 0x586a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_586f:
	/* 0x586f: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_5878:
	/* 0x5878: je     589d <generic_sleepable_preload+0x589d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_589d;
	}
x86_l_587a:
	/* 0x587a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_587f:
	/* 0x587f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5884:
	/* 0x5884: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5889:
	/* 0x5889: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_588e:
	/* 0x588e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5893:
	/* 0x5893: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5895:
	/* 0x5895: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5897:
	/* 0x5897: js     619a <generic_sleepable_preload+0x619a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24986ULL;
	}
x86_l_589d:
	/* 0x589d: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_58a6:
	/* 0x58a6: je     6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26452ULL;
	}
x86_l_58ac:
	/* 0x58ac: mov    ecx,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_58b3:
	/* 0x58b3: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_58b8:
	/* 0x58b8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58bd:
	/* 0x58bd: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_58c6:
	/* 0x58c6: je     58eb <generic_sleepable_preload+0x58eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58eb;
	}
x86_l_58c8:
	/* 0x58c8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58cd:
	/* 0x58cd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_58d2:
	/* 0x58d2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_58d7:
	/* 0x58d7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58dc:
	/* 0x58dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58e1:
	/* 0x58e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58e3:
	/* 0x58e3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_58e5:
	/* 0x58e5: js     61fe <generic_sleepable_preload+0x61fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25086ULL;
	}
x86_l_58eb:
	/* 0x58eb: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_58f4:
	/* 0x58f4: je     6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26452ULL;
	}
x86_l_58fa:
	/* 0x58fa: mov    ecx,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_5901:
	/* 0x5901: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5906:
	/* 0x5906: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_590b:
	/* 0x590b: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_5914:
	/* 0x5914: je     5939 <generic_sleepable_preload+0x5939> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5939;
	}
x86_l_5916:
	/* 0x5916: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_591b:
	/* 0x591b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5920:
	/* 0x5920: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5925:
	/* 0x5925: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_592a:
	/* 0x592a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_592f:
	/* 0x592f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5931:
	/* 0x5931: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5933:
	/* 0x5933: js     625f <generic_sleepable_preload+0x625f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25183ULL;
	}
x86_l_5939:
	/* 0x5939: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_5942:
	/* 0x5942: je     6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26452ULL;
	}
x86_l_5948:
	/* 0x5948: mov    ecx,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
	return 22863ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 22863ULL: goto x86_l_594f;
	case 22868ULL: goto x86_l_5954;
	case 22873ULL: goto x86_l_5959;
	case 22882ULL: goto x86_l_5962;
	case 22884ULL: goto x86_l_5964;
	case 22889ULL: goto x86_l_5969;
	case 22894ULL: goto x86_l_596e;
	case 22899ULL: goto x86_l_5973;
	case 22904ULL: goto x86_l_5978;
	case 22909ULL: goto x86_l_597d;
	case 22911ULL: goto x86_l_597f;
	case 22913ULL: goto x86_l_5981;
	case 22919ULL: goto x86_l_5987;
	case 22928ULL: goto x86_l_5990;
	case 22934ULL: goto x86_l_5996;
	case 22941ULL: goto x86_l_599d;
	case 22946ULL: goto x86_l_59a2;
	case 22951ULL: goto x86_l_59a7;
	case 22960ULL: goto x86_l_59b0;
	case 22962ULL: goto x86_l_59b2;
	case 22967ULL: goto x86_l_59b7;
	case 22972ULL: goto x86_l_59bc;
	case 22977ULL: goto x86_l_59c1;
	case 22982ULL: goto x86_l_59c6;
	case 22987ULL: goto x86_l_59cb;
	case 22989ULL: goto x86_l_59cd;
	case 22991ULL: goto x86_l_59cf;
	case 22997ULL: goto x86_l_59d5;
	case 23002ULL: goto x86_l_59da;
	case 23011ULL: goto x86_l_59e3;
	case 23017ULL: goto x86_l_59e9;
	case 23024ULL: goto x86_l_59f0;
	case 23029ULL: goto x86_l_59f5;
	case 23034ULL: goto x86_l_59fa;
	case 23043ULL: goto x86_l_5a03;
	case 23045ULL: goto x86_l_5a05;
	case 23050ULL: goto x86_l_5a0a;
	case 23055ULL: goto x86_l_5a0f;
	case 23060ULL: goto x86_l_5a14;
	case 23065ULL: goto x86_l_5a19;
	case 23070ULL: goto x86_l_5a1e;
	case 23072ULL: goto x86_l_5a20;
	case 23074ULL: goto x86_l_5a22;
	case 23080ULL: goto x86_l_5a28;
	case 23085ULL: goto x86_l_5a2d;
	case 23094ULL: goto x86_l_5a36;
	case 23100ULL: goto x86_l_5a3c;
	case 23107ULL: goto x86_l_5a43;
	case 23112ULL: goto x86_l_5a48;
	case 23117ULL: goto x86_l_5a4d;
	case 23126ULL: goto x86_l_5a56;
	case 23132ULL: goto x86_l_5a5c;
	case 23137ULL: goto x86_l_5a61;
	case 23142ULL: goto x86_l_5a66;
	case 23147ULL: goto x86_l_5a6b;
	case 23152ULL: goto x86_l_5a70;
	case 23157ULL: goto x86_l_5a75;
	case 23159ULL: goto x86_l_5a77;
	case 23161ULL: goto x86_l_5a79;
	case 23167ULL: goto x86_l_5a7f;
	case 23172ULL: goto x86_l_5a84;
	case 23177ULL: goto x86_l_5a89;
	case 23182ULL: goto x86_l_5a8e;
	case 23187ULL: goto x86_l_5a93;
	case 23192ULL: goto x86_l_5a98;
	case 23197ULL: goto x86_l_5a9d;
	case 23202ULL: goto x86_l_5aa2;
	case 23205ULL: goto x86_l_5aa5;
	case 23207ULL: goto x86_l_5aa7;
	case 23209ULL: goto x86_l_5aa9;
	case 23214ULL: goto x86_l_5aae;
	case 23216ULL: goto x86_l_5ab0;
	case 23221ULL: goto x86_l_5ab5;
	case 23226ULL: goto x86_l_5aba;
	case 23230ULL: goto x86_l_5abe;
	case 23232ULL: goto x86_l_5ac0;
	case 23235ULL: goto x86_l_5ac3;
	case 23244ULL: goto x86_l_5acc;
	case 23250ULL: goto x86_l_5ad2;
	case 23257ULL: goto x86_l_5ad9;
	case 23260ULL: goto x86_l_5adc;
	case 23267ULL: goto x86_l_5ae3;
	case 23270ULL: goto x86_l_5ae6;
	case 23275ULL: goto x86_l_5aeb;
	case 23283ULL: goto x86_l_5af3;
	case 23285ULL: goto x86_l_5af5;
	case 23291ULL: goto x86_l_5afb;
	case 23294ULL: goto x86_l_5afe;
	case 23296ULL: goto x86_l_5b00;
	case 23301ULL: goto x86_l_5b05;
	case 23306ULL: goto x86_l_5b0a;
	case 23311ULL: goto x86_l_5b0f;
	case 23316ULL: goto x86_l_5b14;
	case 23321ULL: goto x86_l_5b19;
	case 23323ULL: goto x86_l_5b1b;
	case 23325ULL: goto x86_l_5b1d;
	case 23331ULL: goto x86_l_5b23;
	case 23340ULL: goto x86_l_5b2c;
	case 23346ULL: goto x86_l_5b32;
	case 23353ULL: goto x86_l_5b39;
	case 23358ULL: goto x86_l_5b3e;
	case 23363ULL: goto x86_l_5b43;
	case 23372ULL: goto x86_l_5b4c;
	case 23374ULL: goto x86_l_5b4e;
	case 23379ULL: goto x86_l_5b53;
	case 23384ULL: goto x86_l_5b58;
	case 23389ULL: goto x86_l_5b5d;
	case 23394ULL: goto x86_l_5b62;
	case 23399ULL: goto x86_l_5b67;
	case 23401ULL: goto x86_l_5b69;
	case 23403ULL: goto x86_l_5b6b;
	case 23409ULL: goto x86_l_5b71;
	case 23418ULL: goto x86_l_5b7a;
	case 23424ULL: goto x86_l_5b80;
	case 23431ULL: goto x86_l_5b87;
	case 23436ULL: goto x86_l_5b8c;
	case 23441ULL: goto x86_l_5b91;
	case 23450ULL: goto x86_l_5b9a;
	case 23452ULL: goto x86_l_5b9c;
	case 23457ULL: goto x86_l_5ba1;
	case 23462ULL: goto x86_l_5ba6;
	case 23467ULL: goto x86_l_5bab;
	case 23472ULL: goto x86_l_5bb0;
	case 23477ULL: goto x86_l_5bb5;
	case 23479ULL: goto x86_l_5bb7;
	case 23481ULL: goto x86_l_5bb9;
	case 23487ULL: goto x86_l_5bbf;
	case 23496ULL: goto x86_l_5bc8;
	case 23502ULL: goto x86_l_5bce;
	case 23509ULL: goto x86_l_5bd5;
	case 23514ULL: goto x86_l_5bda;
	case 23519ULL: goto x86_l_5bdf;
	case 23528ULL: goto x86_l_5be8;
	case 23530ULL: goto x86_l_5bea;
	case 23535ULL: goto x86_l_5bef;
	case 23540ULL: goto x86_l_5bf4;
	case 23545ULL: goto x86_l_5bf9;
	case 23550ULL: goto x86_l_5bfe;
	case 23555ULL: goto x86_l_5c03;
	case 23557ULL: goto x86_l_5c05;
	case 23559ULL: goto x86_l_5c07;
	case 23565ULL: goto x86_l_5c0d;
	case 23574ULL: goto x86_l_5c16;
	case 23580ULL: goto x86_l_5c1c;
	case 23587ULL: goto x86_l_5c23;
	case 23592ULL: goto x86_l_5c28;
	case 23597ULL: goto x86_l_5c2d;
	case 23606ULL: goto x86_l_5c36;
	case 23608ULL: goto x86_l_5c38;
	case 23613ULL: goto x86_l_5c3d;
	case 23618ULL: goto x86_l_5c42;
	case 23623ULL: goto x86_l_5c47;
	case 23628ULL: goto x86_l_5c4c;
	case 23633ULL: goto x86_l_5c51;
	case 23635ULL: goto x86_l_5c53;
	case 23637ULL: goto x86_l_5c55;
	case 23643ULL: goto x86_l_5c5b;
	case 23652ULL: goto x86_l_5c64;
	case 23658ULL: goto x86_l_5c6a;
	case 23665ULL: goto x86_l_5c71;
	case 23670ULL: goto x86_l_5c76;
	case 23675ULL: goto x86_l_5c7b;
	case 23684ULL: goto x86_l_5c84;
	case 23686ULL: goto x86_l_5c86;
	case 23691ULL: goto x86_l_5c8b;
	case 23696ULL: goto x86_l_5c90;
	case 23701ULL: goto x86_l_5c95;
	case 23706ULL: goto x86_l_5c9a;
	case 23711ULL: goto x86_l_5c9f;
	case 23713ULL: goto x86_l_5ca1;
	case 23715ULL: goto x86_l_5ca3;
	case 23721ULL: goto x86_l_5ca9;
	case 23730ULL: goto x86_l_5cb2;
	case 23736ULL: goto x86_l_5cb8;
	case 23743ULL: goto x86_l_5cbf;
	case 23748ULL: goto x86_l_5cc4;
	case 23753ULL: goto x86_l_5cc9;
	case 23762ULL: goto x86_l_5cd2;
	case 23764ULL: goto x86_l_5cd4;
	case 23769ULL: goto x86_l_5cd9;
	case 23774ULL: goto x86_l_5cde;
	case 23779ULL: goto x86_l_5ce3;
	case 23784ULL: goto x86_l_5ce8;
	case 23789ULL: goto x86_l_5ced;
	case 23791ULL: goto x86_l_5cef;
	case 23793ULL: goto x86_l_5cf1;
	case 23799ULL: goto x86_l_5cf7;
	case 23808ULL: goto x86_l_5d00;
	case 23814ULL: goto x86_l_5d06;
	case 23821ULL: goto x86_l_5d0d;
	case 23826ULL: goto x86_l_5d12;
	case 23831ULL: goto x86_l_5d17;
	case 23840ULL: goto x86_l_5d20;
	case 23842ULL: goto x86_l_5d22;
	case 23847ULL: goto x86_l_5d27;
	case 23852ULL: goto x86_l_5d2c;
	case 23857ULL: goto x86_l_5d31;
	case 23862ULL: goto x86_l_5d36;
	case 23867ULL: goto x86_l_5d3b;
	case 23869ULL: goto x86_l_5d3d;
	case 23871ULL: goto x86_l_5d3f;
	case 23877ULL: goto x86_l_5d45;
	case 23882ULL: goto x86_l_5d4a;
	case 23890ULL: goto x86_l_5d52;
	case 23896ULL: goto x86_l_5d58;
	case 23902ULL: goto x86_l_5d5e;
	case 23907ULL: goto x86_l_5d63;
	case 23912ULL: goto x86_l_5d68;
	case 23920ULL: goto x86_l_5d70;
	case 23922ULL: goto x86_l_5d72;
	case 23927ULL: goto x86_l_5d77;
	case 23932ULL: goto x86_l_5d7c;
	case 23937ULL: goto x86_l_5d81;
	case 23942ULL: goto x86_l_5d86;
	case 23947ULL: goto x86_l_5d8b;
	case 23949ULL: goto x86_l_5d8d;
	case 23951ULL: goto x86_l_5d8f;
	case 23957ULL: goto x86_l_5d95;
	case 23962ULL: goto x86_l_5d9a;
	case 23970ULL: goto x86_l_5da2;
	case 23976ULL: goto x86_l_5da8;
	case 23982ULL: goto x86_l_5dae;
	case 23987ULL: goto x86_l_5db3;
	case 23992ULL: goto x86_l_5db8;
	case 24000ULL: goto x86_l_5dc0;
	case 24006ULL: goto x86_l_5dc6;
	case 24011ULL: goto x86_l_5dcb;
	case 24016ULL: goto x86_l_5dd0;
	case 24021ULL: goto x86_l_5dd5;
	case 24026ULL: goto x86_l_5dda;
	case 24029ULL: goto x86_l_5ddd;
	case 24031ULL: goto x86_l_5ddf;
	case 24036ULL: goto x86_l_5de4;
	case 24041ULL: goto x86_l_5de9;
	case 24046ULL: goto x86_l_5dee;
	case 24051ULL: goto x86_l_5df3;
	case 24056ULL: goto x86_l_5df8;
	case 24058ULL: goto x86_l_5dfa;
	case 24060ULL: goto x86_l_5dfc;
	case 24066ULL: goto x86_l_5e02;
	case 24075ULL: goto x86_l_5e0b;
	case 24081ULL: goto x86_l_5e11;
	case 24088ULL: goto x86_l_5e18;
	case 24093ULL: goto x86_l_5e1d;
	case 24098ULL: goto x86_l_5e22;
	case 24107ULL: goto x86_l_5e2b;
	case 24109ULL: goto x86_l_5e2d;
	case 24114ULL: goto x86_l_5e32;
	case 24119ULL: goto x86_l_5e37;
	case 24124ULL: goto x86_l_5e3c;
	case 24129ULL: goto x86_l_5e41;
	case 24134ULL: goto x86_l_5e46;
	case 24136ULL: goto x86_l_5e48;
	case 24138ULL: goto x86_l_5e4a;
	case 24144ULL: goto x86_l_5e50;
	case 24153ULL: goto x86_l_5e59;
	case 24159ULL: goto x86_l_5e5f;
	case 24166ULL: goto x86_l_5e66;
	case 24171ULL: goto x86_l_5e6b;
	case 24176ULL: goto x86_l_5e70;
	case 24185ULL: goto x86_l_5e79;
	case 24187ULL: goto x86_l_5e7b;
	case 24192ULL: goto x86_l_5e80;
	case 24197ULL: goto x86_l_5e85;
	case 24202ULL: goto x86_l_5e8a;
	case 24207ULL: goto x86_l_5e8f;
	case 24212ULL: goto x86_l_5e94;
	case 24214ULL: goto x86_l_5e96;
	case 24216ULL: goto x86_l_5e98;
	case 24222ULL: goto x86_l_5e9e;
	case 24231ULL: goto x86_l_5ea7;
	case 24237ULL: goto x86_l_5ead;
	case 24244ULL: goto x86_l_5eb4;
	case 24249ULL: goto x86_l_5eb9;
	case 24254ULL: goto x86_l_5ebe;
	case 24263ULL: goto x86_l_5ec7;
	case 24265ULL: goto x86_l_5ec9;
	case 24270ULL: goto x86_l_5ece;
	case 24275ULL: goto x86_l_5ed3;
	case 24280ULL: goto x86_l_5ed8;
	case 24285ULL: goto x86_l_5edd;
	case 24290ULL: goto x86_l_5ee2;
	case 24292ULL: goto x86_l_5ee4;
	case 24294ULL: goto x86_l_5ee6;
	case 24300ULL: goto x86_l_5eec;
	case 24309ULL: goto x86_l_5ef5;
	case 24315ULL: goto x86_l_5efb;
	case 24322ULL: goto x86_l_5f02;
	case 24327ULL: goto x86_l_5f07;
	case 24332ULL: goto x86_l_5f0c;
	case 24341ULL: goto x86_l_5f15;
	case 24343ULL: goto x86_l_5f17;
	case 24348ULL: goto x86_l_5f1c;
	case 24353ULL: goto x86_l_5f21;
	case 24358ULL: goto x86_l_5f26;
	case 24363ULL: goto x86_l_5f2b;
	case 24368ULL: goto x86_l_5f30;
	case 24370ULL: goto x86_l_5f32;
	case 24372ULL: goto x86_l_5f34;
	case 24378ULL: goto x86_l_5f3a;
	case 24387ULL: goto x86_l_5f43;
	case 24393ULL: goto x86_l_5f49;
	case 24400ULL: goto x86_l_5f50;
	case 24405ULL: goto x86_l_5f55;
	case 24410ULL: goto x86_l_5f5a;
	case 24419ULL: goto x86_l_5f63;
	case 24421ULL: goto x86_l_5f65;
	case 24426ULL: goto x86_l_5f6a;
	case 24431ULL: goto x86_l_5f6f;
	case 24436ULL: goto x86_l_5f74;
	case 24441ULL: goto x86_l_5f79;
	case 24446ULL: goto x86_l_5f7e;
	case 24448ULL: goto x86_l_5f80;
	case 24450ULL: goto x86_l_5f82;
	case 24456ULL: goto x86_l_5f88;
	case 24465ULL: goto x86_l_5f91;
	case 24471ULL: goto x86_l_5f97;
	case 24478ULL: goto x86_l_5f9e;
	case 24483ULL: goto x86_l_5fa3;
	case 24488ULL: goto x86_l_5fa8;
	case 24497ULL: goto x86_l_5fb1;
	case 24499ULL: goto x86_l_5fb3;
	case 24504ULL: goto x86_l_5fb8;
	case 24509ULL: goto x86_l_5fbd;
	case 24514ULL: goto x86_l_5fc2;
	case 24519ULL: goto x86_l_5fc7;
	case 24524ULL: goto x86_l_5fcc;
	case 24526ULL: goto x86_l_5fce;
	case 24528ULL: goto x86_l_5fd0;
	case 24534ULL: goto x86_l_5fd6;
	case 24543ULL: goto x86_l_5fdf;
	case 24549ULL: goto x86_l_5fe5;
	case 24556ULL: goto x86_l_5fec;
	case 24561ULL: goto x86_l_5ff1;
	case 24566ULL: goto x86_l_5ff6;
	case 24575ULL: goto x86_l_5fff;
	case 24577ULL: goto x86_l_6001;
	case 24582ULL: goto x86_l_6006;
	case 24587ULL: goto x86_l_600b;
	case 24592ULL: goto x86_l_6010;
	case 24597ULL: goto x86_l_6015;
	case 24602ULL: goto x86_l_601a;
	case 24604ULL: goto x86_l_601c;
	case 24606ULL: goto x86_l_601e;
	case 24612ULL: goto x86_l_6024;
	case 24617ULL: goto x86_l_6029;
	case 24625ULL: goto x86_l_6031;
	case 24631ULL: goto x86_l_6037;
	case 24637ULL: goto x86_l_603d;
	case 24642ULL: goto x86_l_6042;
	case 24647ULL: goto x86_l_6047;
	case 24655ULL: goto x86_l_604f;
	case 24657ULL: goto x86_l_6051;
	case 24662ULL: goto x86_l_6056;
	case 24667ULL: goto x86_l_605b;
	case 24672ULL: goto x86_l_6060;
	case 24677ULL: goto x86_l_6065;
	case 24682ULL: goto x86_l_606a;
	case 24684ULL: goto x86_l_606c;
	case 24686ULL: goto x86_l_606e;
	case 24692ULL: goto x86_l_6074;
	case 24697ULL: goto x86_l_6079;
	case 24705ULL: goto x86_l_6081;
	case 24711ULL: goto x86_l_6087;
	case 24717ULL: goto x86_l_608d;
	case 24722ULL: goto x86_l_6092;
	case 24727ULL: goto x86_l_6097;
	case 24735ULL: goto x86_l_609f;
	case 24741ULL: goto x86_l_60a5;
	case 24746ULL: goto x86_l_60aa;
	case 24751ULL: goto x86_l_60af;
	case 24756ULL: goto x86_l_60b4;
	case 24761ULL: goto x86_l_60b9;
	case 24766ULL: goto x86_l_60be;
	case 24768ULL: goto x86_l_60c0;
	case 24770ULL: goto x86_l_60c2;
	case 24776ULL: goto x86_l_60c8;
	case 24781ULL: goto x86_l_60cd;
	case 24786ULL: goto x86_l_60d2;
	case 24791ULL: goto x86_l_60d7;
	case 24796ULL: goto x86_l_60dc;
	case 24801ULL: goto x86_l_60e1;
	case 24806ULL: goto x86_l_60e6;
	case 24811ULL: goto x86_l_60eb;
	default: return 0xffffffffffffffffULL;
	}
x86_l_594f:
	/* 0x594f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5954:
	/* 0x5954: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5959:
	/* 0x5959: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_5962:
	/* 0x5962: je     5987 <generic_sleepable_preload+0x5987> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5987;
	}
x86_l_5964:
	/* 0x5964: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5969:
	/* 0x5969: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_596e:
	/* 0x596e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5973:
	/* 0x5973: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5978:
	/* 0x5978: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_597d:
	/* 0x597d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_597f:
	/* 0x597f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5981:
	/* 0x5981: js     674d <generic_sleepable_preload+0x674d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26445ULL;
	}
x86_l_5987:
	/* 0x5987: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_5990:
	/* 0x5990: je     6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26452ULL;
	}
x86_l_5996:
	/* 0x5996: mov    ecx,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_599d:
	/* 0x599d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_59a2:
	/* 0x59a2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59a7:
	/* 0x59a7: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_59b0:
	/* 0x59b0: je     59d5 <generic_sleepable_preload+0x59d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59d5;
	}
x86_l_59b2:
	/* 0x59b2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59b7:
	/* 0x59b7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_59bc:
	/* 0x59bc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_59c1:
	/* 0x59c1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59c6:
	/* 0x59c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59cb:
	/* 0x59cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59cd:
	/* 0x59cd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_59cf:
	/* 0x59cf: js     6a5d <generic_sleepable_preload+0x6a5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27229ULL;
	}
x86_l_59d5:
	/* 0x59d5: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_59da:
	/* 0x59da: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_59e3:
	/* 0x59e3: je     6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26452ULL;
	}
x86_l_59e9:
	/* 0x59e9: mov    ecx,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_59f0:
	/* 0x59f0: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_59f5:
	/* 0x59f5: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59fa:
	/* 0x59fa: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_5a03:
	/* 0x5a03: je     5a28 <generic_sleepable_preload+0x5a28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a28;
	}
x86_l_5a05:
	/* 0x5a05: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a0a:
	/* 0x5a0a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5a0f:
	/* 0x5a0f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5a14:
	/* 0x5a14: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a19:
	/* 0x5a19: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a1e:
	/* 0x5a1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a20:
	/* 0x5a20: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5a22:
	/* 0x5a22: js     69a5 <generic_sleepable_preload+0x69a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27045ULL;
	}
x86_l_5a28:
	/* 0x5a28: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5a2d:
	/* 0x5a2d: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_5a36:
	/* 0x5a36: je     6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26452ULL;
	}
x86_l_5a3c:
	/* 0x5a3c: mov    ecx,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_5a43:
	/* 0x5a43: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5a48:
	/* 0x5a48: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a4d:
	/* 0x5a4d: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_5a56:
	/* 0x5a56: je     6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26452ULL;
	}
x86_l_5a5c:
	/* 0x5a5c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a61:
	/* 0x5a61: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5a66:
	/* 0x5a66: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5a6b:
	/* 0x5a6b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a70:
	/* 0x5a70: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a75:
	/* 0x5a75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a77:
	/* 0x5a77: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5a79:
	/* 0x5a79: jns    6754 <generic_sleepable_preload+0x6754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 26452ULL;
	}
x86_l_5a7f:
	/* 0x5a7f: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_5a84:
	/* 0x5a84: jmp    6752 <generic_sleepable_preload+0x6752> */
	return 26450ULL;
x86_l_5a89:
	/* 0x5a89: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_5a8e:
	/* 0x5a8e: jmp    6752 <generic_sleepable_preload+0x6752> */
	return 26450ULL;
x86_l_5a93:
	/* 0x5a93: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5a98:
	/* 0x5a98: jmp    6752 <generic_sleepable_preload+0x6752> */
	return 26450ULL;
x86_l_5a9d:
	/* 0x5a9d: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5aa2:
	/* 0x5aa2: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_5aa5:
	/* 0x5aa5: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_5aa7:
	/* 0x5aa7: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_5aa9:
	/* 0x5aa9: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_5aae:
	/* 0x5aae: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5ab0:
	/* 0x5ab0: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_5ab5:
	/* 0x5ab5: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5aba:
	/* 0x5aba: mov    ebx,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5abe:
	/* 0x5abe: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ac0:
	/* 0x5ac0: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_5ac3:
	/* 0x5ac3: cmp    WORD PTR [r13+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_5acc:
	/* 0x5acc: je     6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26629ULL;
	}
x86_l_5ad2:
	/* 0x5ad2: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_5ad9:
	/* 0x5ad9: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_5adc:
	/* 0x5adc: mov    eax,DWORD PTR [r13+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_5ae3:
	/* 0x5ae3: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5ae6:
	/* 0x5ae6: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5aeb:
	/* 0x5aeb: movzx  eax,WORD PTR [r13+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_5af3:
	/* 0x5af3: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_5af5:
	/* 0x5af5: je     5dda <generic_sleepable_preload+0x5dda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5dda;
	}
x86_l_5afb:
	/* 0x5afb: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_5afe:
	/* 0x5afe: je     5b23 <generic_sleepable_preload+0x5b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b23;
	}
x86_l_5b00:
	/* 0x5b00: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b05:
	/* 0x5b05: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5b0a:
	/* 0x5b0a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5b0f:
	/* 0x5b0f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b14:
	/* 0x5b14: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b19:
	/* 0x5b19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b1b:
	/* 0x5b1b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5b1d:
	/* 0x5b1d: js     60d2 <generic_sleepable_preload+0x60d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_60d2;
	}
x86_l_5b23:
	/* 0x5b23: cmp    WORD PTR [r13+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_5b2c:
	/* 0x5b2c: je     6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26629ULL;
	}
x86_l_5b32:
	/* 0x5b32: mov    ecx,DWORD PTR [r13+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_5b39:
	/* 0x5b39: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5b3e:
	/* 0x5b3e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b43:
	/* 0x5b43: cmp    WORD PTR [r13+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_5b4c:
	/* 0x5b4c: je     5b71 <generic_sleepable_preload+0x5b71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b71;
	}
x86_l_5b4e:
	/* 0x5b4e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b53:
	/* 0x5b53: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5b58:
	/* 0x5b58: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5b5d:
	/* 0x5b5d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b62:
	/* 0x5b62: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b67:
	/* 0x5b67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b69:
	/* 0x5b69: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5b6b:
	/* 0x5b6b: js     60dc <generic_sleepable_preload+0x60dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_60dc;
	}
x86_l_5b71:
	/* 0x5b71: cmp    WORD PTR [r13+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_5b7a:
	/* 0x5b7a: je     6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26629ULL;
	}
x86_l_5b80:
	/* 0x5b80: mov    ecx,DWORD PTR [r13+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_5b87:
	/* 0x5b87: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5b8c:
	/* 0x5b8c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b91:
	/* 0x5b91: cmp    WORD PTR [r13+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_5b9a:
	/* 0x5b9a: je     5bbf <generic_sleepable_preload+0x5bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5bbf;
	}
x86_l_5b9c:
	/* 0x5b9c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ba1:
	/* 0x5ba1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5ba6:
	/* 0x5ba6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5bab:
	/* 0x5bab: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bb0:
	/* 0x5bb0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5bb5:
	/* 0x5bb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bb7:
	/* 0x5bb7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5bb9:
	/* 0x5bb9: js     6140 <generic_sleepable_preload+0x6140> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24896ULL;
	}
x86_l_5bbf:
	/* 0x5bbf: cmp    WORD PTR [r13+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_5bc8:
	/* 0x5bc8: je     6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26629ULL;
	}
x86_l_5bce:
	/* 0x5bce: mov    ecx,DWORD PTR [r13+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_5bd5:
	/* 0x5bd5: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5bda:
	/* 0x5bda: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bdf:
	/* 0x5bdf: cmp    WORD PTR [r13+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_5be8:
	/* 0x5be8: je     5c0d <generic_sleepable_preload+0x5c0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c0d;
	}
x86_l_5bea:
	/* 0x5bea: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bef:
	/* 0x5bef: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5bf4:
	/* 0x5bf4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5bf9:
	/* 0x5bf9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bfe:
	/* 0x5bfe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c03:
	/* 0x5c03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c05:
	/* 0x5c05: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5c07:
	/* 0x5c07: js     61a4 <generic_sleepable_preload+0x61a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24996ULL;
	}
x86_l_5c0d:
	/* 0x5c0d: cmp    WORD PTR [r13+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_5c16:
	/* 0x5c16: je     6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26629ULL;
	}
x86_l_5c1c:
	/* 0x5c1c: mov    ecx,DWORD PTR [r13+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_5c23:
	/* 0x5c23: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5c28:
	/* 0x5c28: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c2d:
	/* 0x5c2d: cmp    WORD PTR [r13+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_5c36:
	/* 0x5c36: je     5c5b <generic_sleepable_preload+0x5c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c5b;
	}
x86_l_5c38:
	/* 0x5c38: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c3d:
	/* 0x5c3d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5c42:
	/* 0x5c42: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5c47:
	/* 0x5c47: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c4c:
	/* 0x5c4c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c51:
	/* 0x5c51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c53:
	/* 0x5c53: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5c55:
	/* 0x5c55: js     6208 <generic_sleepable_preload+0x6208> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25096ULL;
	}
x86_l_5c5b:
	/* 0x5c5b: cmp    WORD PTR [r13+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_5c64:
	/* 0x5c64: je     6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26629ULL;
	}
x86_l_5c6a:
	/* 0x5c6a: mov    ecx,DWORD PTR [r13+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_5c71:
	/* 0x5c71: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5c76:
	/* 0x5c76: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c7b:
	/* 0x5c7b: cmp    WORD PTR [r13+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_5c84:
	/* 0x5c84: je     5ca9 <generic_sleepable_preload+0x5ca9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ca9;
	}
x86_l_5c86:
	/* 0x5c86: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c8b:
	/* 0x5c8b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5c90:
	/* 0x5c90: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5c95:
	/* 0x5c95: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c9a:
	/* 0x5c9a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c9f:
	/* 0x5c9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ca1:
	/* 0x5ca1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5ca3:
	/* 0x5ca3: js     6269 <generic_sleepable_preload+0x6269> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25193ULL;
	}
x86_l_5ca9:
	/* 0x5ca9: cmp    WORD PTR [r13+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_5cb2:
	/* 0x5cb2: je     6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26629ULL;
	}
x86_l_5cb8:
	/* 0x5cb8: mov    ecx,DWORD PTR [r13+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_5cbf:
	/* 0x5cbf: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5cc4:
	/* 0x5cc4: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cc9:
	/* 0x5cc9: cmp    WORD PTR [r13+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_5cd2:
	/* 0x5cd2: je     5cf7 <generic_sleepable_preload+0x5cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5cf7;
	}
x86_l_5cd4:
	/* 0x5cd4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cd9:
	/* 0x5cd9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5cde:
	/* 0x5cde: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5ce3:
	/* 0x5ce3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ce8:
	/* 0x5ce8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ced:
	/* 0x5ced: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cef:
	/* 0x5cef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5cf1:
	/* 0x5cf1: js     67fd <generic_sleepable_preload+0x67fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26621ULL;
	}
x86_l_5cf7:
	/* 0x5cf7: cmp    WORD PTR [r13+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_5d00:
	/* 0x5d00: je     6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26629ULL;
	}
x86_l_5d06:
	/* 0x5d06: mov    ecx,DWORD PTR [r13+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_5d0d:
	/* 0x5d0d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5d12:
	/* 0x5d12: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d17:
	/* 0x5d17: cmp    WORD PTR [r13+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_5d20:
	/* 0x5d20: je     5d45 <generic_sleepable_preload+0x5d45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d45;
	}
x86_l_5d22:
	/* 0x5d22: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d27:
	/* 0x5d27: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5d2c:
	/* 0x5d2c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5d31:
	/* 0x5d31: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d36:
	/* 0x5d36: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d3b:
	/* 0x5d3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d3d:
	/* 0x5d3d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5d3f:
	/* 0x5d3f: js     68ad <generic_sleepable_preload+0x68ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26797ULL;
	}
x86_l_5d45:
	/* 0x5d45: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5d4a:
	/* 0x5d4a: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_5d52:
	/* 0x5d52: je     6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26629ULL;
	}
x86_l_5d58:
	/* 0x5d58: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_5d5e:
	/* 0x5d5e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5d63:
	/* 0x5d63: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d68:
	/* 0x5d68: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_5d70:
	/* 0x5d70: je     5d95 <generic_sleepable_preload+0x5d95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d95;
	}
x86_l_5d72:
	/* 0x5d72: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d77:
	/* 0x5d77: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5d7c:
	/* 0x5d7c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5d81:
	/* 0x5d81: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d86:
	/* 0x5d86: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d8b:
	/* 0x5d8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d8d:
	/* 0x5d8d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5d8f:
	/* 0x5d8f: js     69b6 <generic_sleepable_preload+0x69b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27062ULL;
	}
x86_l_5d95:
	/* 0x5d95: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5d9a:
	/* 0x5d9a: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_5da2:
	/* 0x5da2: je     6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26629ULL;
	}
x86_l_5da8:
	/* 0x5da8: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_5dae:
	/* 0x5dae: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5db3:
	/* 0x5db3: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5db8:
	/* 0x5db8: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_5dc0:
	/* 0x5dc0: je     6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26629ULL;
	}
x86_l_5dc6:
	/* 0x5dc6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dcb:
	/* 0x5dcb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5dd0:
	/* 0x5dd0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5dd5:
	/* 0x5dd5: jmp    60b4 <generic_sleepable_preload+0x60b4> */
	goto x86_l_60b4;
x86_l_5dda:
	/* 0x5dda: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_5ddd:
	/* 0x5ddd: je     5e02 <generic_sleepable_preload+0x5e02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e02;
	}
x86_l_5ddf:
	/* 0x5ddf: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5de4:
	/* 0x5de4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5de9:
	/* 0x5de9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5dee:
	/* 0x5dee: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5df3:
	/* 0x5df3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5df8:
	/* 0x5df8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5dfa:
	/* 0x5dfa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5dfc:
	/* 0x5dfc: js     60d2 <generic_sleepable_preload+0x60d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_60d2;
	}
x86_l_5e02:
	/* 0x5e02: cmp    WORD PTR [r13+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_5e0b:
	/* 0x5e0b: je     6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26629ULL;
	}
x86_l_5e11:
	/* 0x5e11: mov    ecx,DWORD PTR [r13+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_5e18:
	/* 0x5e18: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5e1d:
	/* 0x5e1d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e22:
	/* 0x5e22: cmp    WORD PTR [r13+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_5e2b:
	/* 0x5e2b: je     5e50 <generic_sleepable_preload+0x5e50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e50;
	}
x86_l_5e2d:
	/* 0x5e2d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e32:
	/* 0x5e32: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5e37:
	/* 0x5e37: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5e3c:
	/* 0x5e3c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e41:
	/* 0x5e41: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e46:
	/* 0x5e46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e48:
	/* 0x5e48: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5e4a:
	/* 0x5e4a: js     60dc <generic_sleepable_preload+0x60dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_60dc;
	}
x86_l_5e50:
	/* 0x5e50: cmp    WORD PTR [r13+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_5e59:
	/* 0x5e59: je     6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26629ULL;
	}
x86_l_5e5f:
	/* 0x5e5f: mov    ecx,DWORD PTR [r13+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_5e66:
	/* 0x5e66: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5e6b:
	/* 0x5e6b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e70:
	/* 0x5e70: cmp    WORD PTR [r13+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_5e79:
	/* 0x5e79: je     5e9e <generic_sleepable_preload+0x5e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e9e;
	}
x86_l_5e7b:
	/* 0x5e7b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e80:
	/* 0x5e80: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5e85:
	/* 0x5e85: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5e8a:
	/* 0x5e8a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e8f:
	/* 0x5e8f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e94:
	/* 0x5e94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e96:
	/* 0x5e96: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5e98:
	/* 0x5e98: js     6140 <generic_sleepable_preload+0x6140> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24896ULL;
	}
x86_l_5e9e:
	/* 0x5e9e: cmp    WORD PTR [r13+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_5ea7:
	/* 0x5ea7: je     6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26629ULL;
	}
x86_l_5ead:
	/* 0x5ead: mov    ecx,DWORD PTR [r13+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_5eb4:
	/* 0x5eb4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5eb9:
	/* 0x5eb9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ebe:
	/* 0x5ebe: cmp    WORD PTR [r13+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_5ec7:
	/* 0x5ec7: je     5eec <generic_sleepable_preload+0x5eec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5eec;
	}
x86_l_5ec9:
	/* 0x5ec9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ece:
	/* 0x5ece: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5ed3:
	/* 0x5ed3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5ed8:
	/* 0x5ed8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5edd:
	/* 0x5edd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ee2:
	/* 0x5ee2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ee4:
	/* 0x5ee4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5ee6:
	/* 0x5ee6: js     61a4 <generic_sleepable_preload+0x61a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24996ULL;
	}
x86_l_5eec:
	/* 0x5eec: cmp    WORD PTR [r13+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_5ef5:
	/* 0x5ef5: je     6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26629ULL;
	}
x86_l_5efb:
	/* 0x5efb: mov    ecx,DWORD PTR [r13+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_5f02:
	/* 0x5f02: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5f07:
	/* 0x5f07: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f0c:
	/* 0x5f0c: cmp    WORD PTR [r13+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_5f15:
	/* 0x5f15: je     5f3a <generic_sleepable_preload+0x5f3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f3a;
	}
x86_l_5f17:
	/* 0x5f17: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f1c:
	/* 0x5f1c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5f21:
	/* 0x5f21: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5f26:
	/* 0x5f26: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f2b:
	/* 0x5f2b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f30:
	/* 0x5f30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f32:
	/* 0x5f32: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5f34:
	/* 0x5f34: js     6208 <generic_sleepable_preload+0x6208> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25096ULL;
	}
x86_l_5f3a:
	/* 0x5f3a: cmp    WORD PTR [r13+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_5f43:
	/* 0x5f43: je     6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26629ULL;
	}
x86_l_5f49:
	/* 0x5f49: mov    ecx,DWORD PTR [r13+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_5f50:
	/* 0x5f50: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5f55:
	/* 0x5f55: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f5a:
	/* 0x5f5a: cmp    WORD PTR [r13+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_5f63:
	/* 0x5f63: je     5f88 <generic_sleepable_preload+0x5f88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f88;
	}
x86_l_5f65:
	/* 0x5f65: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f6a:
	/* 0x5f6a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5f6f:
	/* 0x5f6f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5f74:
	/* 0x5f74: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f79:
	/* 0x5f79: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f7e:
	/* 0x5f7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f80:
	/* 0x5f80: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5f82:
	/* 0x5f82: js     6269 <generic_sleepable_preload+0x6269> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25193ULL;
	}
x86_l_5f88:
	/* 0x5f88: cmp    WORD PTR [r13+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_5f91:
	/* 0x5f91: je     6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26629ULL;
	}
x86_l_5f97:
	/* 0x5f97: mov    ecx,DWORD PTR [r13+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_5f9e:
	/* 0x5f9e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5fa3:
	/* 0x5fa3: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5fa8:
	/* 0x5fa8: cmp    WORD PTR [r13+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_5fb1:
	/* 0x5fb1: je     5fd6 <generic_sleepable_preload+0x5fd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5fd6;
	}
x86_l_5fb3:
	/* 0x5fb3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5fb8:
	/* 0x5fb8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5fbd:
	/* 0x5fbd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5fc2:
	/* 0x5fc2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5fc7:
	/* 0x5fc7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5fcc:
	/* 0x5fcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fce:
	/* 0x5fce: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5fd0:
	/* 0x5fd0: js     67fd <generic_sleepable_preload+0x67fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26621ULL;
	}
x86_l_5fd6:
	/* 0x5fd6: cmp    WORD PTR [r13+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_5fdf:
	/* 0x5fdf: je     6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26629ULL;
	}
x86_l_5fe5:
	/* 0x5fe5: mov    ecx,DWORD PTR [r13+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_5fec:
	/* 0x5fec: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5ff1:
	/* 0x5ff1: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ff6:
	/* 0x5ff6: cmp    WORD PTR [r13+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_5fff:
	/* 0x5fff: je     6024 <generic_sleepable_preload+0x6024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6024;
	}
x86_l_6001:
	/* 0x6001: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6006:
	/* 0x6006: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_600b:
	/* 0x600b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_6010:
	/* 0x6010: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6015:
	/* 0x6015: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_601a:
	/* 0x601a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_601c:
	/* 0x601c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_601e:
	/* 0x601e: js     68ad <generic_sleepable_preload+0x68ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26797ULL;
	}
x86_l_6024:
	/* 0x6024: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6029:
	/* 0x6029: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_6031:
	/* 0x6031: je     6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26629ULL;
	}
x86_l_6037:
	/* 0x6037: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_603d:
	/* 0x603d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6042:
	/* 0x6042: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6047:
	/* 0x6047: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_604f:
	/* 0x604f: je     6074 <generic_sleepable_preload+0x6074> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6074;
	}
x86_l_6051:
	/* 0x6051: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6056:
	/* 0x6056: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_605b:
	/* 0x605b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_6060:
	/* 0x6060: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6065:
	/* 0x6065: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_606a:
	/* 0x606a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_606c:
	/* 0x606c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_606e:
	/* 0x606e: js     69b6 <generic_sleepable_preload+0x69b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27062ULL;
	}
x86_l_6074:
	/* 0x6074: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6079:
	/* 0x6079: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_6081:
	/* 0x6081: je     6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26629ULL;
	}
x86_l_6087:
	/* 0x6087: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_608d:
	/* 0x608d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6092:
	/* 0x6092: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6097:
	/* 0x6097: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_609f:
	/* 0x609f: je     6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26629ULL;
	}
x86_l_60a5:
	/* 0x60a5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60aa:
	/* 0x60aa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_60af:
	/* 0x60af: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_60b4:
	/* 0x60b4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60b9:
	/* 0x60b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_60be:
	/* 0x60be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60c0:
	/* 0x60c0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_60c2:
	/* 0x60c2: jns    6805 <generic_sleepable_preload+0x6805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 26629ULL;
	}
x86_l_60c8:
	/* 0x60c8: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_60cd:
	/* 0x60cd: jmp    6802 <generic_sleepable_preload+0x6802> */
	return 26626ULL;
x86_l_60d2:
	/* 0x60d2: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_60d7:
	/* 0x60d7: jmp    6802 <generic_sleepable_preload+0x6802> */
	return 26626ULL;
x86_l_60dc:
	/* 0x60dc: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_60e1:
	/* 0x60e1: jmp    6802 <generic_sleepable_preload+0x6802> */
	return 26626ULL;
x86_l_60e6:
	/* 0x60e6: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_60eb:
	/* 0x60eb: jmp    6278 <generic_sleepable_preload+0x6278> */
	return 25208ULL;
	return 24816ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 24816ULL: goto x86_l_60f0;
	case 24821ULL: goto x86_l_60f5;
	case 24826ULL: goto x86_l_60fa;
	case 24831ULL: goto x86_l_60ff;
	case 24836ULL: goto x86_l_6104;
	case 24841ULL: goto x86_l_6109;
	case 24846ULL: goto x86_l_610e;
	case 24851ULL: goto x86_l_6113;
	case 24856ULL: goto x86_l_6118;
	case 24861ULL: goto x86_l_611d;
	case 24866ULL: goto x86_l_6122;
	case 24871ULL: goto x86_l_6127;
	case 24876ULL: goto x86_l_612c;
	case 24881ULL: goto x86_l_6131;
	case 24886ULL: goto x86_l_6136;
	case 24891ULL: goto x86_l_613b;
	case 24896ULL: goto x86_l_6140;
	case 24901ULL: goto x86_l_6145;
	case 24906ULL: goto x86_l_614a;
	case 24911ULL: goto x86_l_614f;
	case 24916ULL: goto x86_l_6154;
	case 24921ULL: goto x86_l_6159;
	case 24926ULL: goto x86_l_615e;
	case 24931ULL: goto x86_l_6163;
	case 24936ULL: goto x86_l_6168;
	case 24941ULL: goto x86_l_616d;
	case 24946ULL: goto x86_l_6172;
	case 24951ULL: goto x86_l_6177;
	case 24956ULL: goto x86_l_617c;
	case 24961ULL: goto x86_l_6181;
	case 24966ULL: goto x86_l_6186;
	case 24971ULL: goto x86_l_618b;
	case 24976ULL: goto x86_l_6190;
	case 24981ULL: goto x86_l_6195;
	case 24986ULL: goto x86_l_619a;
	case 24991ULL: goto x86_l_619f;
	case 24996ULL: goto x86_l_61a4;
	case 25001ULL: goto x86_l_61a9;
	case 25006ULL: goto x86_l_61ae;
	case 25011ULL: goto x86_l_61b3;
	case 25016ULL: goto x86_l_61b8;
	case 25021ULL: goto x86_l_61bd;
	case 25026ULL: goto x86_l_61c2;
	case 25031ULL: goto x86_l_61c7;
	case 25036ULL: goto x86_l_61cc;
	case 25041ULL: goto x86_l_61d1;
	case 25046ULL: goto x86_l_61d6;
	case 25051ULL: goto x86_l_61db;
	case 25056ULL: goto x86_l_61e0;
	case 25061ULL: goto x86_l_61e5;
	case 25066ULL: goto x86_l_61ea;
	case 25071ULL: goto x86_l_61ef;
	case 25076ULL: goto x86_l_61f4;
	case 25081ULL: goto x86_l_61f9;
	case 25086ULL: goto x86_l_61fe;
	case 25091ULL: goto x86_l_6203;
	case 25096ULL: goto x86_l_6208;
	case 25101ULL: goto x86_l_620d;
	case 25106ULL: goto x86_l_6212;
	case 25111ULL: goto x86_l_6217;
	case 25113ULL: goto x86_l_6219;
	case 25118ULL: goto x86_l_621e;
	case 25123ULL: goto x86_l_6223;
	case 25128ULL: goto x86_l_6228;
	case 25133ULL: goto x86_l_622d;
	case 25138ULL: goto x86_l_6232;
	case 25143ULL: goto x86_l_6237;
	case 25148ULL: goto x86_l_623c;
	case 25153ULL: goto x86_l_6241;
	case 25158ULL: goto x86_l_6246;
	case 25163ULL: goto x86_l_624b;
	case 25168ULL: goto x86_l_6250;
	case 25173ULL: goto x86_l_6255;
	case 25178ULL: goto x86_l_625a;
	case 25183ULL: goto x86_l_625f;
	case 25188ULL: goto x86_l_6264;
	case 25193ULL: goto x86_l_6269;
	case 25198ULL: goto x86_l_626e;
	case 25203ULL: goto x86_l_6273;
	case 25208ULL: goto x86_l_6278;
	case 25210ULL: goto x86_l_627a;
	case 25214ULL: goto x86_l_627e;
	case 25219ULL: goto x86_l_6283;
	case 25224ULL: goto x86_l_6288;
	case 25229ULL: goto x86_l_628d;
	case 25234ULL: goto x86_l_6292;
	case 25237ULL: goto x86_l_6295;
	case 25239ULL: goto x86_l_6297;
	case 25243ULL: goto x86_l_629b;
	case 25249ULL: goto x86_l_62a1;
	case 25254ULL: goto x86_l_62a6;
	case 25259ULL: goto x86_l_62ab;
	case 25261ULL: goto x86_l_62ad;
	case 25266ULL: goto x86_l_62b2;
	case 25274ULL: goto x86_l_62ba;
	case 25281ULL: goto x86_l_62c1;
	case 25286ULL: goto x86_l_62c6;
	case 25291ULL: goto x86_l_62cb;
	case 25293ULL: goto x86_l_62cd;
	case 25296ULL: goto x86_l_62d0;
	case 25302ULL: goto x86_l_62d6;
	case 25305ULL: goto x86_l_62d9;
	case 25312ULL: goto x86_l_62e0;
	case 25314ULL: goto x86_l_62e2;
	case 25319ULL: goto x86_l_62e7;
	case 25324ULL: goto x86_l_62ec;
	case 25327ULL: goto x86_l_62ef;
	case 25330ULL: goto x86_l_62f2;
	case 25332ULL: goto x86_l_62f4;
	case 25334ULL: goto x86_l_62f6;
	case 25339ULL: goto x86_l_62fb;
	case 25344ULL: goto x86_l_6300;
	case 25349ULL: goto x86_l_6305;
	case 25351ULL: goto x86_l_6307;
	case 25355ULL: goto x86_l_630b;
	case 25360ULL: goto x86_l_6310;
	case 25365ULL: goto x86_l_6315;
	case 25370ULL: goto x86_l_631a;
	case 25375ULL: goto x86_l_631f;
	case 25378ULL: goto x86_l_6322;
	case 25380ULL: goto x86_l_6324;
	case 25384ULL: goto x86_l_6328;
	case 25390ULL: goto x86_l_632e;
	case 25395ULL: goto x86_l_6333;
	case 25400ULL: goto x86_l_6338;
	case 25402ULL: goto x86_l_633a;
	case 25407ULL: goto x86_l_633f;
	case 25415ULL: goto x86_l_6347;
	case 25422ULL: goto x86_l_634e;
	case 25427ULL: goto x86_l_6353;
	case 25432ULL: goto x86_l_6358;
	case 25434ULL: goto x86_l_635a;
	case 25437ULL: goto x86_l_635d;
	case 25443ULL: goto x86_l_6363;
	case 25446ULL: goto x86_l_6366;
	case 25453ULL: goto x86_l_636d;
	case 25455ULL: goto x86_l_636f;
	case 25460ULL: goto x86_l_6374;
	case 25465ULL: goto x86_l_6379;
	case 25468ULL: goto x86_l_637c;
	case 25471ULL: goto x86_l_637f;
	case 25473ULL: goto x86_l_6381;
	case 25475ULL: goto x86_l_6383;
	case 25480ULL: goto x86_l_6388;
	case 25485ULL: goto x86_l_638d;
	case 25490ULL: goto x86_l_6392;
	case 25492ULL: goto x86_l_6394;
	case 25496ULL: goto x86_l_6398;
	case 25501ULL: goto x86_l_639d;
	case 25506ULL: goto x86_l_63a2;
	case 25511ULL: goto x86_l_63a7;
	case 25516ULL: goto x86_l_63ac;
	case 25519ULL: goto x86_l_63af;
	case 25521ULL: goto x86_l_63b1;
	case 25525ULL: goto x86_l_63b5;
	case 25531ULL: goto x86_l_63bb;
	case 25536ULL: goto x86_l_63c0;
	case 25541ULL: goto x86_l_63c5;
	case 25543ULL: goto x86_l_63c7;
	case 25548ULL: goto x86_l_63cc;
	case 25556ULL: goto x86_l_63d4;
	case 25563ULL: goto x86_l_63db;
	case 25568ULL: goto x86_l_63e0;
	case 25573ULL: goto x86_l_63e5;
	case 25575ULL: goto x86_l_63e7;
	case 25578ULL: goto x86_l_63ea;
	case 25584ULL: goto x86_l_63f0;
	case 25587ULL: goto x86_l_63f3;
	case 25594ULL: goto x86_l_63fa;
	case 25596ULL: goto x86_l_63fc;
	case 25601ULL: goto x86_l_6401;
	case 25606ULL: goto x86_l_6406;
	case 25609ULL: goto x86_l_6409;
	case 25612ULL: goto x86_l_640c;
	case 25614ULL: goto x86_l_640e;
	case 25616ULL: goto x86_l_6410;
	case 25621ULL: goto x86_l_6415;
	case 25626ULL: goto x86_l_641a;
	case 25631ULL: goto x86_l_641f;
	case 25633ULL: goto x86_l_6421;
	case 25637ULL: goto x86_l_6425;
	case 25642ULL: goto x86_l_642a;
	case 25647ULL: goto x86_l_642f;
	case 25652ULL: goto x86_l_6434;
	case 25657ULL: goto x86_l_6439;
	case 25660ULL: goto x86_l_643c;
	case 25662ULL: goto x86_l_643e;
	case 25666ULL: goto x86_l_6442;
	case 25672ULL: goto x86_l_6448;
	case 25677ULL: goto x86_l_644d;
	case 25682ULL: goto x86_l_6452;
	case 25684ULL: goto x86_l_6454;
	case 25689ULL: goto x86_l_6459;
	case 25697ULL: goto x86_l_6461;
	case 25704ULL: goto x86_l_6468;
	case 25709ULL: goto x86_l_646d;
	case 25714ULL: goto x86_l_6472;
	case 25716ULL: goto x86_l_6474;
	case 25719ULL: goto x86_l_6477;
	case 25725ULL: goto x86_l_647d;
	case 25728ULL: goto x86_l_6480;
	case 25735ULL: goto x86_l_6487;
	case 25737ULL: goto x86_l_6489;
	case 25742ULL: goto x86_l_648e;
	case 25747ULL: goto x86_l_6493;
	case 25750ULL: goto x86_l_6496;
	case 25753ULL: goto x86_l_6499;
	case 25755ULL: goto x86_l_649b;
	case 25757ULL: goto x86_l_649d;
	case 25762ULL: goto x86_l_64a2;
	case 25767ULL: goto x86_l_64a7;
	case 25772ULL: goto x86_l_64ac;
	case 25775ULL: goto x86_l_64af;
	case 25779ULL: goto x86_l_64b3;
	case 25784ULL: goto x86_l_64b8;
	case 25789ULL: goto x86_l_64bd;
	case 25794ULL: goto x86_l_64c2;
	case 25799ULL: goto x86_l_64c7;
	case 25802ULL: goto x86_l_64ca;
	case 25804ULL: goto x86_l_64cc;
	case 25807ULL: goto x86_l_64cf;
	case 25813ULL: goto x86_l_64d5;
	case 25818ULL: goto x86_l_64da;
	case 25823ULL: goto x86_l_64df;
	case 25825ULL: goto x86_l_64e1;
	case 25830ULL: goto x86_l_64e6;
	case 25838ULL: goto x86_l_64ee;
	case 25845ULL: goto x86_l_64f5;
	case 25850ULL: goto x86_l_64fa;
	case 25855ULL: goto x86_l_64ff;
	case 25857ULL: goto x86_l_6501;
	case 25860ULL: goto x86_l_6504;
	case 25866ULL: goto x86_l_650a;
	case 25869ULL: goto x86_l_650d;
	case 25876ULL: goto x86_l_6514;
	case 25878ULL: goto x86_l_6516;
	case 25883ULL: goto x86_l_651b;
	case 25888ULL: goto x86_l_6520;
	case 25891ULL: goto x86_l_6523;
	case 25894ULL: goto x86_l_6526;
	case 25896ULL: goto x86_l_6528;
	case 25898ULL: goto x86_l_652a;
	case 25903ULL: goto x86_l_652f;
	case 25908ULL: goto x86_l_6534;
	case 25913ULL: goto x86_l_6539;
	case 25915ULL: goto x86_l_653b;
	case 25919ULL: goto x86_l_653f;
	case 25925ULL: goto x86_l_6545;
	case 25930ULL: goto x86_l_654a;
	case 25935ULL: goto x86_l_654f;
	case 25937ULL: goto x86_l_6551;
	case 25942ULL: goto x86_l_6556;
	case 25950ULL: goto x86_l_655e;
	case 25957ULL: goto x86_l_6565;
	case 25962ULL: goto x86_l_656a;
	case 25967ULL: goto x86_l_656f;
	case 25969ULL: goto x86_l_6571;
	case 25972ULL: goto x86_l_6574;
	case 25978ULL: goto x86_l_657a;
	case 25981ULL: goto x86_l_657d;
	case 25988ULL: goto x86_l_6584;
	case 25990ULL: goto x86_l_6586;
	case 25995ULL: goto x86_l_658b;
	case 26000ULL: goto x86_l_6590;
	case 26003ULL: goto x86_l_6593;
	case 26006ULL: goto x86_l_6596;
	case 26008ULL: goto x86_l_6598;
	case 26010ULL: goto x86_l_659a;
	case 26015ULL: goto x86_l_659f;
	case 26018ULL: goto x86_l_65a2;
	case 26023ULL: goto x86_l_65a7;
	case 26026ULL: goto x86_l_65aa;
	case 26028ULL: goto x86_l_65ac;
	case 26031ULL: goto x86_l_65af;
	case 26037ULL: goto x86_l_65b5;
	case 26040ULL: goto x86_l_65b8;
	case 26042ULL: goto x86_l_65ba;
	case 26045ULL: goto x86_l_65bd;
	case 26049ULL: goto x86_l_65c1;
	case 26054ULL: goto x86_l_65c6;
	case 26057ULL: goto x86_l_65c9;
	case 26059ULL: goto x86_l_65cb;
	case 26062ULL: goto x86_l_65ce;
	case 26067ULL: goto x86_l_65d3;
	case 26069ULL: goto x86_l_65d5;
	case 26072ULL: goto x86_l_65d8;
	case 26074ULL: goto x86_l_65da;
	case 26076ULL: goto x86_l_65dc;
	case 26081ULL: goto x86_l_65e1;
	case 26083ULL: goto x86_l_65e3;
	case 26088ULL: goto x86_l_65e8;
	case 26093ULL: goto x86_l_65ed;
	case 26095ULL: goto x86_l_65ef;
	case 26099ULL: goto x86_l_65f3;
	case 26105ULL: goto x86_l_65f9;
	case 26110ULL: goto x86_l_65fe;
	case 26115ULL: goto x86_l_6603;
	case 26117ULL: goto x86_l_6605;
	case 26122ULL: goto x86_l_660a;
	case 26130ULL: goto x86_l_6612;
	case 26137ULL: goto x86_l_6619;
	case 26142ULL: goto x86_l_661e;
	case 26147ULL: goto x86_l_6623;
	case 26149ULL: goto x86_l_6625;
	case 26152ULL: goto x86_l_6628;
	case 26158ULL: goto x86_l_662e;
	case 26161ULL: goto x86_l_6631;
	case 26168ULL: goto x86_l_6638;
	case 26170ULL: goto x86_l_663a;
	case 26175ULL: goto x86_l_663f;
	case 26180ULL: goto x86_l_6644;
	case 26183ULL: goto x86_l_6647;
	case 26186ULL: goto x86_l_664a;
	case 26188ULL: goto x86_l_664c;
	case 26190ULL: goto x86_l_664e;
	case 26195ULL: goto x86_l_6653;
	case 26198ULL: goto x86_l_6656;
	case 26203ULL: goto x86_l_665b;
	case 26206ULL: goto x86_l_665e;
	case 26208ULL: goto x86_l_6660;
	case 26211ULL: goto x86_l_6663;
	case 26217ULL: goto x86_l_6669;
	case 26220ULL: goto x86_l_666c;
	case 26222ULL: goto x86_l_666e;
	case 26225ULL: goto x86_l_6671;
	case 26229ULL: goto x86_l_6675;
	case 26234ULL: goto x86_l_667a;
	case 26237ULL: goto x86_l_667d;
	case 26239ULL: goto x86_l_667f;
	case 26242ULL: goto x86_l_6682;
	case 26247ULL: goto x86_l_6687;
	case 26249ULL: goto x86_l_6689;
	case 26252ULL: goto x86_l_668c;
	case 26254ULL: goto x86_l_668e;
	case 26259ULL: goto x86_l_6693;
	case 26262ULL: goto x86_l_6696;
	case 26264ULL: goto x86_l_6698;
	case 26269ULL: goto x86_l_669d;
	case 26274ULL: goto x86_l_66a2;
	case 26276ULL: goto x86_l_66a4;
	case 26280ULL: goto x86_l_66a8;
	case 26286ULL: goto x86_l_66ae;
	case 26291ULL: goto x86_l_66b3;
	case 26296ULL: goto x86_l_66b8;
	case 26298ULL: goto x86_l_66ba;
	case 26303ULL: goto x86_l_66bf;
	case 26311ULL: goto x86_l_66c7;
	case 26318ULL: goto x86_l_66ce;
	case 26323ULL: goto x86_l_66d3;
	case 26328ULL: goto x86_l_66d8;
	case 26330ULL: goto x86_l_66da;
	case 26333ULL: goto x86_l_66dd;
	case 26339ULL: goto x86_l_66e3;
	case 26342ULL: goto x86_l_66e6;
	case 26349ULL: goto x86_l_66ed;
	case 26351ULL: goto x86_l_66ef;
	case 26356ULL: goto x86_l_66f4;
	case 26361ULL: goto x86_l_66f9;
	case 26364ULL: goto x86_l_66fc;
	case 26367ULL: goto x86_l_66ff;
	case 26369ULL: goto x86_l_6701;
	case 26371ULL: goto x86_l_6703;
	case 26376ULL: goto x86_l_6708;
	case 26379ULL: goto x86_l_670b;
	case 26382ULL: goto x86_l_670e;
	case 26384ULL: goto x86_l_6710;
	case 26387ULL: goto x86_l_6713;
	case 26393ULL: goto x86_l_6719;
	case 26396ULL: goto x86_l_671c;
	case 26398ULL: goto x86_l_671e;
	case 26401ULL: goto x86_l_6721;
	case 26405ULL: goto x86_l_6725;
	case 26410ULL: goto x86_l_672a;
	case 26413ULL: goto x86_l_672d;
	case 26415ULL: goto x86_l_672f;
	case 26418ULL: goto x86_l_6732;
	case 26423ULL: goto x86_l_6737;
	case 26425ULL: goto x86_l_6739;
	case 26428ULL: goto x86_l_673c;
	case 26430ULL: goto x86_l_673e;
	case 26435ULL: goto x86_l_6743;
	case 26438ULL: goto x86_l_6746;
	case 26440ULL: goto x86_l_6748;
	case 26445ULL: goto x86_l_674d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_60f0:
	/* 0x60f0: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_60f5:
	/* 0x60f5: jmp    6305 <generic_sleepable_preload+0x6305> */
	goto x86_l_6305;
x86_l_60fa:
	/* 0x60fa: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_60ff:
	/* 0x60ff: jmp    6392 <generic_sleepable_preload+0x6392> */
	goto x86_l_6392;
x86_l_6104:
	/* 0x6104: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_6109:
	/* 0x6109: jmp    641f <generic_sleepable_preload+0x641f> */
	goto x86_l_641f;
x86_l_610e:
	/* 0x610e: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_6113:
	/* 0x6113: jmp    64ac <generic_sleepable_preload+0x64ac> */
	goto x86_l_64ac;
x86_l_6118:
	/* 0x6118: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_611d:
	/* 0x611d: jmp    6539 <generic_sleepable_preload+0x6539> */
	goto x86_l_6539;
x86_l_6122:
	/* 0x6122: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_6127:
	/* 0x6127: jmp    65ed <generic_sleepable_preload+0x65ed> */
	goto x86_l_65ed;
x86_l_612c:
	/* 0x612c: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_6131:
	/* 0x6131: jmp    66a2 <generic_sleepable_preload+0x66a2> */
	goto x86_l_66a2;
x86_l_6136:
	/* 0x6136: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_613b:
	/* 0x613b: jmp    6752 <generic_sleepable_preload+0x6752> */
	return 26450ULL;
x86_l_6140:
	/* 0x6140: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_6145:
	/* 0x6145: jmp    6802 <generic_sleepable_preload+0x6802> */
	return 26626ULL;
x86_l_614a:
	/* 0x614a: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_614f:
	/* 0x614f: jmp    6278 <generic_sleepable_preload+0x6278> */
	goto x86_l_6278;
x86_l_6154:
	/* 0x6154: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_6159:
	/* 0x6159: jmp    6305 <generic_sleepable_preload+0x6305> */
	goto x86_l_6305;
x86_l_615e:
	/* 0x615e: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_6163:
	/* 0x6163: jmp    6392 <generic_sleepable_preload+0x6392> */
	goto x86_l_6392;
x86_l_6168:
	/* 0x6168: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_616d:
	/* 0x616d: jmp    641f <generic_sleepable_preload+0x641f> */
	goto x86_l_641f;
x86_l_6172:
	/* 0x6172: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_6177:
	/* 0x6177: jmp    64ac <generic_sleepable_preload+0x64ac> */
	goto x86_l_64ac;
x86_l_617c:
	/* 0x617c: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_6181:
	/* 0x6181: jmp    6539 <generic_sleepable_preload+0x6539> */
	goto x86_l_6539;
x86_l_6186:
	/* 0x6186: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_618b:
	/* 0x618b: jmp    65ed <generic_sleepable_preload+0x65ed> */
	goto x86_l_65ed;
x86_l_6190:
	/* 0x6190: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_6195:
	/* 0x6195: jmp    66a2 <generic_sleepable_preload+0x66a2> */
	goto x86_l_66a2;
x86_l_619a:
	/* 0x619a: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_619f:
	/* 0x619f: jmp    6752 <generic_sleepable_preload+0x6752> */
	return 26450ULL;
x86_l_61a4:
	/* 0x61a4: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_61a9:
	/* 0x61a9: jmp    6802 <generic_sleepable_preload+0x6802> */
	return 26626ULL;
x86_l_61ae:
	/* 0x61ae: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61b3:
	/* 0x61b3: jmp    6278 <generic_sleepable_preload+0x6278> */
	goto x86_l_6278;
x86_l_61b8:
	/* 0x61b8: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61bd:
	/* 0x61bd: jmp    6305 <generic_sleepable_preload+0x6305> */
	goto x86_l_6305;
x86_l_61c2:
	/* 0x61c2: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61c7:
	/* 0x61c7: jmp    6392 <generic_sleepable_preload+0x6392> */
	goto x86_l_6392;
x86_l_61cc:
	/* 0x61cc: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61d1:
	/* 0x61d1: jmp    641f <generic_sleepable_preload+0x641f> */
	goto x86_l_641f;
x86_l_61d6:
	/* 0x61d6: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_61db:
	/* 0x61db: jmp    64ac <generic_sleepable_preload+0x64ac> */
	goto x86_l_64ac;
x86_l_61e0:
	/* 0x61e0: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61e5:
	/* 0x61e5: jmp    6539 <generic_sleepable_preload+0x6539> */
	goto x86_l_6539;
x86_l_61ea:
	/* 0x61ea: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61ef:
	/* 0x61ef: jmp    65ed <generic_sleepable_preload+0x65ed> */
	goto x86_l_65ed;
x86_l_61f4:
	/* 0x61f4: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61f9:
	/* 0x61f9: jmp    66a2 <generic_sleepable_preload+0x66a2> */
	goto x86_l_66a2;
x86_l_61fe:
	/* 0x61fe: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_6203:
	/* 0x6203: jmp    6752 <generic_sleepable_preload+0x6752> */
	return 26450ULL;
x86_l_6208:
	/* 0x6208: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_620d:
	/* 0x620d: jmp    6802 <generic_sleepable_preload+0x6802> */
	return 26626ULL;
x86_l_6212:
	/* 0x6212: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6217:
	/* 0x6217: jmp    6278 <generic_sleepable_preload+0x6278> */
	goto x86_l_6278;
x86_l_6219:
	/* 0x6219: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_621e:
	/* 0x621e: jmp    6305 <generic_sleepable_preload+0x6305> */
	goto x86_l_6305;
x86_l_6223:
	/* 0x6223: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6228:
	/* 0x6228: jmp    6392 <generic_sleepable_preload+0x6392> */
	goto x86_l_6392;
x86_l_622d:
	/* 0x622d: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6232:
	/* 0x6232: jmp    641f <generic_sleepable_preload+0x641f> */
	goto x86_l_641f;
x86_l_6237:
	/* 0x6237: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_623c:
	/* 0x623c: jmp    64ac <generic_sleepable_preload+0x64ac> */
	goto x86_l_64ac;
x86_l_6241:
	/* 0x6241: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6246:
	/* 0x6246: jmp    6539 <generic_sleepable_preload+0x6539> */
	goto x86_l_6539;
x86_l_624b:
	/* 0x624b: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6250:
	/* 0x6250: jmp    65ed <generic_sleepable_preload+0x65ed> */
	goto x86_l_65ed;
x86_l_6255:
	/* 0x6255: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_625a:
	/* 0x625a: jmp    66a2 <generic_sleepable_preload+0x66a2> */
	goto x86_l_66a2;
x86_l_625f:
	/* 0x625f: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6264:
	/* 0x6264: jmp    6752 <generic_sleepable_preload+0x6752> */
	return 26450ULL;
x86_l_6269:
	/* 0x6269: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_626e:
	/* 0x626e: jmp    6802 <generic_sleepable_preload+0x6802> */
	return 26626ULL;
x86_l_6273:
	/* 0x6273: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_6278:
	/* 0x6278: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_627a:
	/* 0x627a: mov    r14d,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_627e:
	/* 0x627e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6283:
	/* 0x6283: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6288:
	/* 0x6288: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_628d:
	/* 0x628d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6292:
	/* 0x6292: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_6295:
	/* 0x6295: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6297:
	/* 0x6297: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_629b:
	/* 0x629b: jne    11b4 <generic_sleepable_preload+0x11b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4532ULL;
	}
x86_l_62a1:
	/* 0x62a1: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_62a6:
	/* 0x62a6: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_62ab:
	/* 0x62ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62ad:
	/* 0x62ad: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_62b2:
	/* 0x62b2: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_62ba:
	/* 0x62ba: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_62c1:
	/* 0x62c1: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_62c6:
	/* 0x62c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_62cb:
	/* 0x62cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62cd:
	/* 0x62cd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_62d0:
	/* 0x62d0: je     11b4 <generic_sleepable_preload+0x11b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4532ULL;
	}
x86_l_62d6:
	/* 0x62d6: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_62d9:
	/* 0x62d9: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_62e0:
	/* 0x62e0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_62e2:
	/* 0x62e2: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_62e7:
	/* 0x62e7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_62ec:
	/* 0x62ec: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_62ef:
	/* 0x62ef: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_62f2:
	/* 0x62f2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_62f4:
	/* 0x62f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62f6:
	/* 0x62f6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_62fb:
	/* 0x62fb: jmp    659f <generic_sleepable_preload+0x659f> */
	goto x86_l_659f;
x86_l_6300:
	/* 0x6300: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_6305:
	/* 0x6305: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6307:
	/* 0x6307: mov    r14d,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_630b:
	/* 0x630b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6310:
	/* 0x6310: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6315:
	/* 0x6315: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_631a:
	/* 0x631a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_631f:
	/* 0x631f: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_6322:
	/* 0x6322: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6324:
	/* 0x6324: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_6328:
	/* 0x6328: jne    11c3 <generic_sleepable_preload+0x11c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4547ULL;
	}
x86_l_632e:
	/* 0x632e: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6333:
	/* 0x6333: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6338:
	/* 0x6338: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_633a:
	/* 0x633a: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_633f:
	/* 0x633f: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_6347:
	/* 0x6347: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_634e:
	/* 0x634e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6353:
	/* 0x6353: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6358:
	/* 0x6358: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_635a:
	/* 0x635a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_635d:
	/* 0x635d: je     11c3 <generic_sleepable_preload+0x11c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4547ULL;
	}
x86_l_6363:
	/* 0x6363: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6366:
	/* 0x6366: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_636d:
	/* 0x636d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_636f:
	/* 0x636f: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6374:
	/* 0x6374: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6379:
	/* 0x6379: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_637c:
	/* 0x637c: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_637f:
	/* 0x637f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6381:
	/* 0x6381: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6383:
	/* 0x6383: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6388:
	/* 0x6388: jmp    67b8 <generic_sleepable_preload+0x67b8> */
	return 26552ULL;
x86_l_638d:
	/* 0x638d: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_6392:
	/* 0x6392: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6394:
	/* 0x6394: mov    r14d,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_6398:
	/* 0x6398: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_639d:
	/* 0x639d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_63a2:
	/* 0x63a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_63a7:
	/* 0x63a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_63ac:
	/* 0x63ac: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_63af:
	/* 0x63af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63b1:
	/* 0x63b1: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_63b5:
	/* 0x63b5: jne    11d7 <generic_sleepable_preload+0x11d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4567ULL;
	}
x86_l_63bb:
	/* 0x63bb: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_63c0:
	/* 0x63c0: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_63c5:
	/* 0x63c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63c7:
	/* 0x63c7: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_63cc:
	/* 0x63cc: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_63d4:
	/* 0x63d4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_63db:
	/* 0x63db: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_63e0:
	/* 0x63e0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_63e5:
	/* 0x63e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63e7:
	/* 0x63e7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_63ea:
	/* 0x63ea: je     11d7 <generic_sleepable_preload+0x11d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4567ULL;
	}
x86_l_63f0:
	/* 0x63f0: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_63f3:
	/* 0x63f3: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_63fa:
	/* 0x63fa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_63fc:
	/* 0x63fc: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6401:
	/* 0x6401: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6406:
	/* 0x6406: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6409:
	/* 0x6409: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_640c:
	/* 0x640c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_640e:
	/* 0x640e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6410:
	/* 0x6410: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6415:
	/* 0x6415: jmp    6653 <generic_sleepable_preload+0x6653> */
	goto x86_l_6653;
x86_l_641a:
	/* 0x641a: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_641f:
	/* 0x641f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6421:
	/* 0x6421: mov    r14d,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6425:
	/* 0x6425: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_642a:
	/* 0x642a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_642f:
	/* 0x642f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6434:
	/* 0x6434: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6439:
	/* 0x6439: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_643c:
	/* 0x643c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_643e:
	/* 0x643e: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_6442:
	/* 0x6442: jne    11e6 <generic_sleepable_preload+0x11e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4582ULL;
	}
x86_l_6448:
	/* 0x6448: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_644d:
	/* 0x644d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6452:
	/* 0x6452: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6454:
	/* 0x6454: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6459:
	/* 0x6459: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_6461:
	/* 0x6461: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_6468:
	/* 0x6468: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_646d:
	/* 0x646d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6472:
	/* 0x6472: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6474:
	/* 0x6474: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6477:
	/* 0x6477: je     11e6 <generic_sleepable_preload+0x11e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4582ULL;
	}
x86_l_647d:
	/* 0x647d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6480:
	/* 0x6480: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_6487:
	/* 0x6487: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6489:
	/* 0x6489: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_648e:
	/* 0x648e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6493:
	/* 0x6493: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6496:
	/* 0x6496: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_6499:
	/* 0x6499: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_649b:
	/* 0x649b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_649d:
	/* 0x649d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_64a2:
	/* 0x64a2: jmp    6708 <generic_sleepable_preload+0x6708> */
	goto x86_l_6708;
x86_l_64a7:
	/* 0x64a7: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_64ac:
	/* 0x64ac: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_64af:
	/* 0x64af: mov    ebx,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_64b3:
	/* 0x64b3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64b8:
	/* 0x64b8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_64bd:
	/* 0x64bd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_64c2:
	/* 0x64c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64c7:
	/* 0x64c7: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_64ca:
	/* 0x64ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64cc:
	/* 0x64cc: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_64cf:
	/* 0x64cf: jne    11f5 <generic_sleepable_preload+0x11f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4597ULL;
	}
x86_l_64d5:
	/* 0x64d5: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64da:
	/* 0x64da: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_64df:
	/* 0x64df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64e1:
	/* 0x64e1: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_64e6:
	/* 0x64e6: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_64ee:
	/* 0x64ee: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_64f5:
	/* 0x64f5: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_64fa:
	/* 0x64fa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_64ff:
	/* 0x64ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6501:
	/* 0x6501: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6504:
	/* 0x6504: je     11f5 <generic_sleepable_preload+0x11f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4597ULL;
	}
x86_l_650a:
	/* 0x650a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_650d:
	/* 0x650d: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_6514:
	/* 0x6514: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6516:
	/* 0x6516: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_651b:
	/* 0x651b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6520:
	/* 0x6520: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_6523:
	/* 0x6523: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_6526:
	/* 0x6526: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6528:
	/* 0x6528: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_652a:
	/* 0x652a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_652f:
	/* 0x652f: jmp    6868 <generic_sleepable_preload+0x6868> */
	return 26728ULL;
x86_l_6534:
	/* 0x6534: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_6539:
	/* 0x6539: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_653b:
	/* 0x653b: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_653f:
	/* 0x653f: jne    11b4 <generic_sleepable_preload+0x11b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4532ULL;
	}
x86_l_6545:
	/* 0x6545: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_654a:
	/* 0x654a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_654f:
	/* 0x654f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6551:
	/* 0x6551: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6556:
	/* 0x6556: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_655e:
	/* 0x655e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_6565:
	/* 0x6565: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_656a:
	/* 0x656a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_656f:
	/* 0x656f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6571:
	/* 0x6571: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6574:
	/* 0x6574: je     11b4 <generic_sleepable_preload+0x11b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4532ULL;
	}
x86_l_657a:
	/* 0x657a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_657d:
	/* 0x657d: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_6584:
	/* 0x6584: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6586:
	/* 0x6586: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_658b:
	/* 0x658b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6590:
	/* 0x6590: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6593:
	/* 0x6593: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_6596:
	/* 0x6596: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6598:
	/* 0x6598: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_659a:
	/* 0x659a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_659f:
	/* 0x659f: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_65a2:
	/* 0x65a2: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_65a7:
	/* 0x65a7: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_65aa:
	/* 0x65aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65ac:
	/* 0x65ac: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_65af:
	/* 0x65af: je     11b4 <generic_sleepable_preload+0x11b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4532ULL;
	}
x86_l_65b5:
	/* 0x65b5: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_65b8:
	/* 0x65b8: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_65e1;
	}
x86_l_65ba:
	/* 0x65ba: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_65bd:
	/* 0x65bd: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_65c1:
	/* 0x65c1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_65c6:
	/* 0x65c6: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_65c9:
	/* 0x65c9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_65cb:
	/* 0x65cb: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_65ce:
	/* 0x65ce: call   65d3 <generic_sleepable_preload+0x65d3> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_65d3:
	/* 0x65d3: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_65d5:
	/* 0x65d5: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_65d8:
	/* 0x65d8: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_65da:
	/* 0x65da: jns    65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_65e1;
	}
x86_l_65dc:
	/* 0x65dc: mov    ebx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_65e1:
	/* 0x65e1: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_65e3:
	/* 0x65e3: jmp    11b4 <generic_sleepable_preload+0x11b4> */
	return 4532ULL;
x86_l_65e8:
	/* 0x65e8: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_65ed:
	/* 0x65ed: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_65ef:
	/* 0x65ef: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_65f3:
	/* 0x65f3: jne    11d7 <generic_sleepable_preload+0x11d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4567ULL;
	}
x86_l_65f9:
	/* 0x65f9: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_65fe:
	/* 0x65fe: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6603:
	/* 0x6603: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6605:
	/* 0x6605: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_660a:
	/* 0x660a: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_6612:
	/* 0x6612: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_6619:
	/* 0x6619: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_661e:
	/* 0x661e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6623:
	/* 0x6623: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6625:
	/* 0x6625: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6628:
	/* 0x6628: je     11d7 <generic_sleepable_preload+0x11d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4567ULL;
	}
x86_l_662e:
	/* 0x662e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6631:
	/* 0x6631: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_6638:
	/* 0x6638: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_663a:
	/* 0x663a: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_663f:
	/* 0x663f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6644:
	/* 0x6644: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6647:
	/* 0x6647: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_664a:
	/* 0x664a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_664c:
	/* 0x664c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_664e:
	/* 0x664e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6653:
	/* 0x6653: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6656:
	/* 0x6656: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_665b:
	/* 0x665b: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_665e:
	/* 0x665e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6660:
	/* 0x6660: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6663:
	/* 0x6663: je     11d7 <generic_sleepable_preload+0x11d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4567ULL;
	}
x86_l_6669:
	/* 0x6669: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_666c:
	/* 0x666c: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6696;
	}
x86_l_666e:
	/* 0x666e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_6671:
	/* 0x6671: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_6675:
	/* 0x6675: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_667a:
	/* 0x667a: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_667d:
	/* 0x667d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_667f:
	/* 0x667f: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_6682:
	/* 0x6682: call   6687 <generic_sleepable_preload+0x6687> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_6687:
	/* 0x6687: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_6689:
	/* 0x6689: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_668c:
	/* 0x668c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_668e:
	/* 0x668e: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_6693:
	/* 0x6693: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_6696:
	/* 0x6696: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6698:
	/* 0x6698: jmp    11d7 <generic_sleepable_preload+0x11d7> */
	return 4567ULL;
x86_l_669d:
	/* 0x669d: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_66a2:
	/* 0x66a2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_66a4:
	/* 0x66a4: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_66a8:
	/* 0x66a8: jne    11e6 <generic_sleepable_preload+0x11e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4582ULL;
	}
x86_l_66ae:
	/* 0x66ae: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_66b3:
	/* 0x66b3: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_66b8:
	/* 0x66b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66ba:
	/* 0x66ba: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_66bf:
	/* 0x66bf: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_66c7:
	/* 0x66c7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_66ce:
	/* 0x66ce: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_66d3:
	/* 0x66d3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_66d8:
	/* 0x66d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66da:
	/* 0x66da: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_66dd:
	/* 0x66dd: je     11e6 <generic_sleepable_preload+0x11e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4582ULL;
	}
x86_l_66e3:
	/* 0x66e3: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_66e6:
	/* 0x66e6: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_66ed:
	/* 0x66ed: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_66ef:
	/* 0x66ef: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_66f4:
	/* 0x66f4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_66f9:
	/* 0x66f9: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_66fc:
	/* 0x66fc: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_66ff:
	/* 0x66ff: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6701:
	/* 0x6701: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6703:
	/* 0x6703: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6708:
	/* 0x6708: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_670b:
	/* 0x670b: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_670e:
	/* 0x670e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6710:
	/* 0x6710: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6713:
	/* 0x6713: je     11e6 <generic_sleepable_preload+0x11e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4582ULL;
	}
x86_l_6719:
	/* 0x6719: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_671c:
	/* 0x671c: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6746;
	}
x86_l_671e:
	/* 0x671e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_6721:
	/* 0x6721: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_6725:
	/* 0x6725: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_672a:
	/* 0x672a: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_672d:
	/* 0x672d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_672f:
	/* 0x672f: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_6732:
	/* 0x6732: call   6737 <generic_sleepable_preload+0x6737> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_6737:
	/* 0x6737: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_6739:
	/* 0x6739: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_673c:
	/* 0x673c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_673e:
	/* 0x673e: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_6743:
	/* 0x6743: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_6746:
	/* 0x6746: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6748:
	/* 0x6748: jmp    11e6 <generic_sleepable_preload+0x11e6> */
	return 4582ULL;
x86_l_674d:
	/* 0x674d: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
	return 26450ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_14(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 26450ULL: goto x86_l_6752;
	case 26452ULL: goto x86_l_6754;
	case 26456ULL: goto x86_l_6758;
	case 26462ULL: goto x86_l_675e;
	case 26467ULL: goto x86_l_6763;
	case 26472ULL: goto x86_l_6768;
	case 26474ULL: goto x86_l_676a;
	case 26479ULL: goto x86_l_676f;
	case 26487ULL: goto x86_l_6777;
	case 26494ULL: goto x86_l_677e;
	case 26499ULL: goto x86_l_6783;
	case 26504ULL: goto x86_l_6788;
	case 26506ULL: goto x86_l_678a;
	case 26509ULL: goto x86_l_678d;
	case 26515ULL: goto x86_l_6793;
	case 26518ULL: goto x86_l_6796;
	case 26525ULL: goto x86_l_679d;
	case 26527ULL: goto x86_l_679f;
	case 26532ULL: goto x86_l_67a4;
	case 26537ULL: goto x86_l_67a9;
	case 26540ULL: goto x86_l_67ac;
	case 26543ULL: goto x86_l_67af;
	case 26545ULL: goto x86_l_67b1;
	case 26547ULL: goto x86_l_67b3;
	case 26552ULL: goto x86_l_67b8;
	case 26555ULL: goto x86_l_67bb;
	case 26558ULL: goto x86_l_67be;
	case 26560ULL: goto x86_l_67c0;
	case 26563ULL: goto x86_l_67c3;
	case 26569ULL: goto x86_l_67c9;
	case 26572ULL: goto x86_l_67cc;
	case 26574ULL: goto x86_l_67ce;
	case 26577ULL: goto x86_l_67d1;
	case 26581ULL: goto x86_l_67d5;
	case 26586ULL: goto x86_l_67da;
	case 26589ULL: goto x86_l_67dd;
	case 26591ULL: goto x86_l_67df;
	case 26594ULL: goto x86_l_67e2;
	case 26599ULL: goto x86_l_67e7;
	case 26601ULL: goto x86_l_67e9;
	case 26604ULL: goto x86_l_67ec;
	case 26606ULL: goto x86_l_67ee;
	case 26611ULL: goto x86_l_67f3;
	case 26614ULL: goto x86_l_67f6;
	case 26616ULL: goto x86_l_67f8;
	case 26621ULL: goto x86_l_67fd;
	case 26626ULL: goto x86_l_6802;
	case 26629ULL: goto x86_l_6805;
	case 26632ULL: goto x86_l_6808;
	case 26638ULL: goto x86_l_680e;
	case 26643ULL: goto x86_l_6813;
	case 26648ULL: goto x86_l_6818;
	case 26650ULL: goto x86_l_681a;
	case 26655ULL: goto x86_l_681f;
	case 26663ULL: goto x86_l_6827;
	case 26670ULL: goto x86_l_682e;
	case 26675ULL: goto x86_l_6833;
	case 26680ULL: goto x86_l_6838;
	case 26682ULL: goto x86_l_683a;
	case 26685ULL: goto x86_l_683d;
	case 26691ULL: goto x86_l_6843;
	case 26694ULL: goto x86_l_6846;
	case 26701ULL: goto x86_l_684d;
	case 26703ULL: goto x86_l_684f;
	case 26708ULL: goto x86_l_6854;
	case 26713ULL: goto x86_l_6859;
	case 26716ULL: goto x86_l_685c;
	case 26719ULL: goto x86_l_685f;
	case 26721ULL: goto x86_l_6861;
	case 26723ULL: goto x86_l_6863;
	case 26728ULL: goto x86_l_6868;
	case 26731ULL: goto x86_l_686b;
	case 26734ULL: goto x86_l_686e;
	case 26736ULL: goto x86_l_6870;
	case 26739ULL: goto x86_l_6873;
	case 26745ULL: goto x86_l_6879;
	case 26748ULL: goto x86_l_687c;
	case 26750ULL: goto x86_l_687e;
	case 26753ULL: goto x86_l_6881;
	case 26757ULL: goto x86_l_6885;
	case 26762ULL: goto x86_l_688a;
	case 26765ULL: goto x86_l_688d;
	case 26767ULL: goto x86_l_688f;
	case 26770ULL: goto x86_l_6892;
	case 26775ULL: goto x86_l_6897;
	case 26777ULL: goto x86_l_6899;
	case 26780ULL: goto x86_l_689c;
	case 26782ULL: goto x86_l_689e;
	case 26787ULL: goto x86_l_68a3;
	case 26790ULL: goto x86_l_68a6;
	case 26792ULL: goto x86_l_68a8;
	case 26797ULL: goto x86_l_68ad;
	case 26800ULL: goto x86_l_68b0;
	case 26805ULL: goto x86_l_68b5;
	case 26808ULL: goto x86_l_68b8;
	case 26814ULL: goto x86_l_68be;
	case 26819ULL: goto x86_l_68c3;
	case 26821ULL: goto x86_l_68c5;
	case 26826ULL: goto x86_l_68ca;
	case 26831ULL: goto x86_l_68cf;
	case 26833ULL: goto x86_l_68d1;
	case 26838ULL: goto x86_l_68d6;
	case 26843ULL: goto x86_l_68db;
	case 26845ULL: goto x86_l_68dd;
	case 26850ULL: goto x86_l_68e2;
	case 26855ULL: goto x86_l_68e7;
	case 26857ULL: goto x86_l_68e9;
	case 26862ULL: goto x86_l_68ee;
	case 26867ULL: goto x86_l_68f3;
	case 26870ULL: goto x86_l_68f6;
	case 26875ULL: goto x86_l_68fb;
	case 26880ULL: goto x86_l_6900;
	case 26882ULL: goto x86_l_6902;
	case 26887ULL: goto x86_l_6907;
	case 26892ULL: goto x86_l_690c;
	case 26894ULL: goto x86_l_690e;
	case 26899ULL: goto x86_l_6913;
	case 26904ULL: goto x86_l_6918;
	case 26906ULL: goto x86_l_691a;
	case 26911ULL: goto x86_l_691f;
	case 26916ULL: goto x86_l_6924;
	case 26918ULL: goto x86_l_6926;
	case 26923ULL: goto x86_l_692b;
	case 26928ULL: goto x86_l_6930;
	case 26933ULL: goto x86_l_6935;
	case 26935ULL: goto x86_l_6937;
	case 26940ULL: goto x86_l_693c;
	case 26945ULL: goto x86_l_6941;
	case 26947ULL: goto x86_l_6943;
	case 26952ULL: goto x86_l_6948;
	case 26957ULL: goto x86_l_694d;
	case 26962ULL: goto x86_l_6952;
	case 26964ULL: goto x86_l_6954;
	case 26969ULL: goto x86_l_6959;
	case 26974ULL: goto x86_l_695e;
	case 26976ULL: goto x86_l_6960;
	case 26981ULL: goto x86_l_6965;
	case 26986ULL: goto x86_l_696a;
	case 26991ULL: goto x86_l_696f;
	case 26994ULL: goto x86_l_6972;
	case 26999ULL: goto x86_l_6977;
	case 27004ULL: goto x86_l_697c;
	case 27009ULL: goto x86_l_6981;
	case 27011ULL: goto x86_l_6983;
	case 27016ULL: goto x86_l_6988;
	case 27021ULL: goto x86_l_698d;
	case 27023ULL: goto x86_l_698f;
	case 27028ULL: goto x86_l_6994;
	case 27033ULL: goto x86_l_6999;
	case 27035ULL: goto x86_l_699b;
	case 27040ULL: goto x86_l_69a0;
	case 27045ULL: goto x86_l_69a5;
	case 27050ULL: goto x86_l_69aa;
	case 27052ULL: goto x86_l_69ac;
	case 27057ULL: goto x86_l_69b1;
	case 27062ULL: goto x86_l_69b6;
	case 27067ULL: goto x86_l_69bb;
	case 27072ULL: goto x86_l_69c0;
	case 27074ULL: goto x86_l_69c2;
	case 27079ULL: goto x86_l_69c7;
	case 27084ULL: goto x86_l_69cc;
	case 27089ULL: goto x86_l_69d1;
	case 27094ULL: goto x86_l_69d6;
	case 27096ULL: goto x86_l_69d8;
	case 27101ULL: goto x86_l_69dd;
	case 27106ULL: goto x86_l_69e2;
	case 27111ULL: goto x86_l_69e7;
	case 27113ULL: goto x86_l_69e9;
	case 27118ULL: goto x86_l_69ee;
	case 27123ULL: goto x86_l_69f3;
	case 27128ULL: goto x86_l_69f8;
	case 27133ULL: goto x86_l_69fd;
	case 27135ULL: goto x86_l_69ff;
	case 27140ULL: goto x86_l_6a04;
	case 27145ULL: goto x86_l_6a09;
	case 27150ULL: goto x86_l_6a0e;
	case 27153ULL: goto x86_l_6a11;
	case 27158ULL: goto x86_l_6a16;
	case 27163ULL: goto x86_l_6a1b;
	case 27168ULL: goto x86_l_6a20;
	case 27170ULL: goto x86_l_6a22;
	case 27175ULL: goto x86_l_6a27;
	case 27180ULL: goto x86_l_6a2c;
	case 27185ULL: goto x86_l_6a31;
	case 27190ULL: goto x86_l_6a36;
	case 27192ULL: goto x86_l_6a38;
	case 27197ULL: goto x86_l_6a3d;
	case 27202ULL: goto x86_l_6a42;
	case 27207ULL: goto x86_l_6a47;
	case 27212ULL: goto x86_l_6a4c;
	case 27214ULL: goto x86_l_6a4e;
	case 27219ULL: goto x86_l_6a53;
	case 27224ULL: goto x86_l_6a58;
	case 27229ULL: goto x86_l_6a5d;
	case 27231ULL: goto x86_l_6a5f;
	case 27236ULL: goto x86_l_6a64;
	case 27241ULL: goto x86_l_6a69;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6752:
	/* 0x6752: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6754:
	/* 0x6754: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_6758:
	/* 0x6758: jne    11c3 <generic_sleepable_preload+0x11c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4547ULL;
	}
x86_l_675e:
	/* 0x675e: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6763:
	/* 0x6763: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6768:
	/* 0x6768: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_676a:
	/* 0x676a: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_676f:
	/* 0x676f: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_6777:
	/* 0x6777: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_677e:
	/* 0x677e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6783:
	/* 0x6783: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6788:
	/* 0x6788: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_678a:
	/* 0x678a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_678d:
	/* 0x678d: je     11c3 <generic_sleepable_preload+0x11c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4547ULL;
	}
x86_l_6793:
	/* 0x6793: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6796:
	/* 0x6796: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_679d:
	/* 0x679d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_679f:
	/* 0x679f: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_67a4:
	/* 0x67a4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_67a9:
	/* 0x67a9: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_67ac:
	/* 0x67ac: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_67af:
	/* 0x67af: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_67b1:
	/* 0x67b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67b3:
	/* 0x67b3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_67b8:
	/* 0x67b8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_67bb:
	/* 0x67bb: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_67be:
	/* 0x67be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67c0:
	/* 0x67c0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_67c3:
	/* 0x67c3: je     11c3 <generic_sleepable_preload+0x11c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4547ULL;
	}
x86_l_67c9:
	/* 0x67c9: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_67cc:
	/* 0x67cc: je     67f6 <generic_sleepable_preload+0x67f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_67f6;
	}
x86_l_67ce:
	/* 0x67ce: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_67d1:
	/* 0x67d1: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_67d5:
	/* 0x67d5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_67da:
	/* 0x67da: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_67dd:
	/* 0x67dd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_67df:
	/* 0x67df: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_67e2:
	/* 0x67e2: call   67e7 <generic_sleepable_preload+0x67e7> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_67e7:
	/* 0x67e7: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_67e9:
	/* 0x67e9: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_67ec:
	/* 0x67ec: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_67ee:
	/* 0x67ee: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_67f3:
	/* 0x67f3: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_67f6:
	/* 0x67f6: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67f8:
	/* 0x67f8: jmp    11c3 <generic_sleepable_preload+0x11c3> */
	return 4547ULL;
x86_l_67fd:
	/* 0x67fd: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_6802:
	/* 0x6802: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6805:
	/* 0x6805: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6808:
	/* 0x6808: jne    11f5 <generic_sleepable_preload+0x11f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4597ULL;
	}
x86_l_680e:
	/* 0x680e: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6813:
	/* 0x6813: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6818:
	/* 0x6818: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_681a:
	/* 0x681a: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_681f:
	/* 0x681f: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_6827:
	/* 0x6827: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_682e:
	/* 0x682e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6833:
	/* 0x6833: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6838:
	/* 0x6838: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_683a:
	/* 0x683a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_683d:
	/* 0x683d: je     11f5 <generic_sleepable_preload+0x11f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4597ULL;
	}
x86_l_6843:
	/* 0x6843: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6846:
	/* 0x6846: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_684d:
	/* 0x684d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_684f:
	/* 0x684f: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6854:
	/* 0x6854: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6859:
	/* 0x6859: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_685c:
	/* 0x685c: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_685f:
	/* 0x685f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6861:
	/* 0x6861: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6863:
	/* 0x6863: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6868:
	/* 0x6868: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_686b:
	/* 0x686b: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_686e:
	/* 0x686e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6870:
	/* 0x6870: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6873:
	/* 0x6873: je     11f5 <generic_sleepable_preload+0x11f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4597ULL;
	}
x86_l_6879:
	/* 0x6879: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_687c:
	/* 0x687c: je     68a6 <generic_sleepable_preload+0x68a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_68a6;
	}
x86_l_687e:
	/* 0x687e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_6881:
	/* 0x6881: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_6885:
	/* 0x6885: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_688a:
	/* 0x688a: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_688d:
	/* 0x688d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_688f:
	/* 0x688f: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_6892:
	/* 0x6892: call   6897 <generic_sleepable_preload+0x6897> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_6897:
	/* 0x6897: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_6899:
	/* 0x6899: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_689c:
	/* 0x689c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_689e:
	/* 0x689e: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_68a3:
	/* 0x68a3: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_68a6:
	/* 0x68a6: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_68a8:
	/* 0x68a8: jmp    11f5 <generic_sleepable_preload+0x11f5> */
	return 4597ULL;
x86_l_68ad:
	/* 0x68ad: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68b0:
	/* 0x68b0: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_68b5:
	/* 0x68b5: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_68b8:
	/* 0x68b8: jne    11f5 <generic_sleepable_preload+0x11f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4597ULL;
	}
x86_l_68be:
	/* 0x68be: jmp    680e <generic_sleepable_preload+0x680e> */
	goto x86_l_680e;
x86_l_68c3:
	/* 0x68c3: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68c5:
	/* 0x68c5: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_68ca:
	/* 0x68ca: jmp    627a <generic_sleepable_preload+0x627a> */
	return 25210ULL;
x86_l_68cf:
	/* 0x68cf: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68d1:
	/* 0x68d1: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_68d6:
	/* 0x68d6: jmp    6307 <generic_sleepable_preload+0x6307> */
	return 25351ULL;
x86_l_68db:
	/* 0x68db: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68dd:
	/* 0x68dd: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_68e2:
	/* 0x68e2: jmp    6394 <generic_sleepable_preload+0x6394> */
	return 25492ULL;
x86_l_68e7:
	/* 0x68e7: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68e9:
	/* 0x68e9: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_68ee:
	/* 0x68ee: jmp    6421 <generic_sleepable_preload+0x6421> */
	return 25633ULL;
x86_l_68f3:
	/* 0x68f3: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68f6:
	/* 0x68f6: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_68fb:
	/* 0x68fb: jmp    64af <generic_sleepable_preload+0x64af> */
	return 25775ULL;
x86_l_6900:
	/* 0x6900: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6902:
	/* 0x6902: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6907:
	/* 0x6907: jmp    653b <generic_sleepable_preload+0x653b> */
	return 25915ULL;
x86_l_690c:
	/* 0x690c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_690e:
	/* 0x690e: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6913:
	/* 0x6913: jmp    65ef <generic_sleepable_preload+0x65ef> */
	return 26095ULL;
x86_l_6918:
	/* 0x6918: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_691a:
	/* 0x691a: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_691f:
	/* 0x691f: jmp    66a4 <generic_sleepable_preload+0x66a4> */
	return 26276ULL;
x86_l_6924:
	/* 0x6924: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6926:
	/* 0x6926: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_692b:
	/* 0x692b: jmp    6754 <generic_sleepable_preload+0x6754> */
	goto x86_l_6754;
x86_l_6930:
	/* 0x6930: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_6935:
	/* 0x6935: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6937:
	/* 0x6937: jmp    69c7 <generic_sleepable_preload+0x69c7> */
	goto x86_l_69c7;
x86_l_693c:
	/* 0x693c: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_6941:
	/* 0x6941: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6943:
	/* 0x6943: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6948:
	/* 0x6948: jmp    6307 <generic_sleepable_preload+0x6307> */
	return 25351ULL;
x86_l_694d:
	/* 0x694d: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_6952:
	/* 0x6952: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6954:
	/* 0x6954: jmp    69ee <generic_sleepable_preload+0x69ee> */
	goto x86_l_69ee;
x86_l_6959:
	/* 0x6959: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_695e:
	/* 0x695e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6960:
	/* 0x6960: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6965:
	/* 0x6965: jmp    6421 <generic_sleepable_preload+0x6421> */
	return 25633ULL;
x86_l_696a:
	/* 0x696a: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_696f:
	/* 0x696f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6972:
	/* 0x6972: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6977:
	/* 0x6977: jmp    64af <generic_sleepable_preload+0x64af> */
	return 25775ULL;
x86_l_697c:
	/* 0x697c: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_6981:
	/* 0x6981: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6983:
	/* 0x6983: jmp    6a27 <generic_sleepable_preload+0x6a27> */
	goto x86_l_6a27;
x86_l_6988:
	/* 0x6988: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_698d:
	/* 0x698d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_698f:
	/* 0x698f: jmp    6a3d <generic_sleepable_preload+0x6a3d> */
	goto x86_l_6a3d;
x86_l_6994:
	/* 0x6994: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_6999:
	/* 0x6999: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_699b:
	/* 0x699b: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69a0:
	/* 0x69a0: jmp    66a4 <generic_sleepable_preload+0x66a4> */
	return 26276ULL;
x86_l_69a5:
	/* 0x69a5: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_69aa:
	/* 0x69aa: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69ac:
	/* 0x69ac: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69b1:
	/* 0x69b1: jmp    6754 <generic_sleepable_preload+0x6754> */
	goto x86_l_6754;
x86_l_69b6:
	/* 0x69b6: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_69bb:
	/* 0x69bb: jmp    6802 <generic_sleepable_preload+0x6802> */
	goto x86_l_6802;
x86_l_69c0:
	/* 0x69c0: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69c2:
	/* 0x69c2: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_69c7:
	/* 0x69c7: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69cc:
	/* 0x69cc: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_69d1:
	/* 0x69d1: jmp    627a <generic_sleepable_preload+0x627a> */
	return 25210ULL;
x86_l_69d6:
	/* 0x69d6: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69d8:
	/* 0x69d8: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_69dd:
	/* 0x69dd: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69e2:
	/* 0x69e2: jmp    6307 <generic_sleepable_preload+0x6307> */
	return 25351ULL;
x86_l_69e7:
	/* 0x69e7: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69e9:
	/* 0x69e9: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_69ee:
	/* 0x69ee: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69f3:
	/* 0x69f3: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_69f8:
	/* 0x69f8: jmp    6394 <generic_sleepable_preload+0x6394> */
	return 25492ULL;
x86_l_69fd:
	/* 0x69fd: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69ff:
	/* 0x69ff: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6a04:
	/* 0x6a04: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a09:
	/* 0x6a09: jmp    6421 <generic_sleepable_preload+0x6421> */
	return 25633ULL;
x86_l_6a0e:
	/* 0x6a0e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a11:
	/* 0x6a11: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_6a16:
	/* 0x6a16: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a1b:
	/* 0x6a1b: jmp    64af <generic_sleepable_preload+0x64af> */
	return 25775ULL;
x86_l_6a20:
	/* 0x6a20: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a22:
	/* 0x6a22: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6a27:
	/* 0x6a27: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a2c:
	/* 0x6a2c: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6a31:
	/* 0x6a31: jmp    653b <generic_sleepable_preload+0x653b> */
	return 25915ULL;
x86_l_6a36:
	/* 0x6a36: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a38:
	/* 0x6a38: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6a3d:
	/* 0x6a3d: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a42:
	/* 0x6a42: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6a47:
	/* 0x6a47: jmp    65ef <generic_sleepable_preload+0x65ef> */
	return 26095ULL;
x86_l_6a4c:
	/* 0x6a4c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a4e:
	/* 0x6a4e: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6a53:
	/* 0x6a53: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a58:
	/* 0x6a58: jmp    66a4 <generic_sleepable_preload+0x66a4> */
	return 26276ULL;
x86_l_6a5d:
	/* 0x6a5d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a5f:
	/* 0x6a5f: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6a64:
	/* 0x6a64: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a69:
	/* 0x6a69: jmp    6754 <generic_sleepable_preload+0x6754> */
	goto x86_l_6754;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 22292U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1773ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1780ULL && __x86_pc <= 3572ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3579ULL && __x86_pc <= 5335ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5343ULL && __x86_pc <= 7225ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7230ULL && __x86_pc <= 9153ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9159ULL && __x86_pc <= 11115ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 11120ULL && __x86_pc <= 13080ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 13087ULL && __x86_pc <= 15042ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 15044ULL && __x86_pc <= 16982ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 16987ULL && __x86_pc <= 18934ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 18943ULL && __x86_pc <= 20887ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 20896ULL && __x86_pc <= 22856ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 22863ULL && __x86_pc <= 24811ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 24816ULL && __x86_pc <= 26445ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_13(__x86_state, __x86_pc);
		else if (__x86_pc >= 26450ULL && __x86_pc <= 27241ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_14(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

extern char CONFIG_ITER_NUM;
extern char heap_ro_zero;
extern char sleepable_preload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_uprobe_v61_try_preload_arg_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 5ULL: goto x86_l_5;
	case 6ULL: goto x86_l_6;
	case 10ULL: goto x86_l_a;
	case 12ULL: goto x86_l_c;
	case 15ULL: goto x86_l_f;
	case 18ULL: goto x86_l_12;
	case 23ULL: goto x86_l_17;
	case 28ULL: goto x86_l_1c;
	case 30ULL: goto x86_l_1e;
	case 32ULL: goto x86_l_20;
	case 36ULL: goto x86_l_24;
	case 37ULL: goto x86_l_25;
	case 39ULL: goto x86_l_27;
	case 41ULL: goto x86_l_29;
	case 42ULL: goto x86_l_2a;
	case 47ULL: goto x86_l_2f;
	case 51ULL: goto x86_l_33;
	case 53ULL: goto x86_l_35;
	case 55ULL: goto x86_l_37;
	case 63ULL: goto x86_l_3f;
	case 68ULL: goto x86_l_44;
	case 71ULL: goto x86_l_47;
	case 77ULL: goto x86_l_4d;
	case 80ULL: goto x86_l_50;
	case 86ULL: goto x86_l_56;
	case 89ULL: goto x86_l_59;
	case 95ULL: goto x86_l_5f;
	case 98ULL: goto x86_l_62;
	case 104ULL: goto x86_l_68;
	case 108ULL: goto x86_l_6c;
	case 113ULL: goto x86_l_71;
	case 121ULL: goto x86_l_79;
	case 130ULL: goto x86_l_82;
	case 133ULL: goto x86_l_85;
	case 135ULL: goto x86_l_87;
	case 137ULL: goto x86_l_89;
	case 146ULL: goto x86_l_92;
	case 149ULL: goto x86_l_95;
	case 154ULL: goto x86_l_9a;
	case 159ULL: goto x86_l_9f;
	case 164ULL: goto x86_l_a4;
	case 167ULL: goto x86_l_a7;
	case 173ULL: goto x86_l_ad;
	case 177ULL: goto x86_l_b1;
	case 180ULL: goto x86_l_b4;
	case 187ULL: goto x86_l_bb;
	case 193ULL: goto x86_l_c1;
	case 197ULL: goto x86_l_c5;
	case 201ULL: goto x86_l_c9;
	case 206ULL: goto x86_l_ce;
	case 211ULL: goto x86_l_d3;
	case 216ULL: goto x86_l_d8;
	case 221ULL: goto x86_l_dd;
	case 226ULL: goto x86_l_e2;
	case 231ULL: goto x86_l_e7;
	case 238ULL: goto x86_l_ee;
	case 241ULL: goto x86_l_f1;
	case 247ULL: goto x86_l_f7;
	case 252ULL: goto x86_l_fc;
	case 258ULL: goto x86_l_102;
	case 260ULL: goto x86_l_104;
	case 265ULL: goto x86_l_109;
	case 270ULL: goto x86_l_10e;
	case 275ULL: goto x86_l_113;
	case 277ULL: goto x86_l_115;
	case 282ULL: goto x86_l_11a;
	case 287ULL: goto x86_l_11f;
	case 292ULL: goto x86_l_124;
	case 297ULL: goto x86_l_129;
	case 302ULL: goto x86_l_12e;
	case 304ULL: goto x86_l_130;
	case 310ULL: goto x86_l_136;
	case 312ULL: goto x86_l_138;
	case 318ULL: goto x86_l_13e;
	case 323ULL: goto x86_l_143;
	case 329ULL: goto x86_l_149;
	case 332ULL: goto x86_l_14c;
	case 337ULL: goto x86_l_151;
	case 342ULL: goto x86_l_156;
	case 347ULL: goto x86_l_15b;
	case 349ULL: goto x86_l_15d;
	case 354ULL: goto x86_l_162;
	case 359ULL: goto x86_l_167;
	case 364ULL: goto x86_l_16c;
	case 369ULL: goto x86_l_171;
	case 374ULL: goto x86_l_176;
	case 376ULL: goto x86_l_178;
	case 382ULL: goto x86_l_17e;
	case 384ULL: goto x86_l_180;
	case 390ULL: goto x86_l_186;
	case 395ULL: goto x86_l_18b;
	case 401ULL: goto x86_l_191;
	case 404ULL: goto x86_l_194;
	case 409ULL: goto x86_l_199;
	case 414ULL: goto x86_l_19e;
	case 419ULL: goto x86_l_1a3;
	case 421ULL: goto x86_l_1a5;
	case 426ULL: goto x86_l_1aa;
	case 431ULL: goto x86_l_1af;
	case 436ULL: goto x86_l_1b4;
	case 441ULL: goto x86_l_1b9;
	case 446ULL: goto x86_l_1be;
	case 448ULL: goto x86_l_1c0;
	case 454ULL: goto x86_l_1c6;
	case 456ULL: goto x86_l_1c8;
	case 462ULL: goto x86_l_1ce;
	case 467ULL: goto x86_l_1d3;
	case 473ULL: goto x86_l_1d9;
	case 476ULL: goto x86_l_1dc;
	case 481ULL: goto x86_l_1e1;
	case 486ULL: goto x86_l_1e6;
	case 491ULL: goto x86_l_1eb;
	case 493ULL: goto x86_l_1ed;
	case 498ULL: goto x86_l_1f2;
	case 503ULL: goto x86_l_1f7;
	case 508ULL: goto x86_l_1fc;
	case 513ULL: goto x86_l_201;
	case 518ULL: goto x86_l_206;
	case 520ULL: goto x86_l_208;
	case 526ULL: goto x86_l_20e;
	case 528ULL: goto x86_l_210;
	case 534ULL: goto x86_l_216;
	case 539ULL: goto x86_l_21b;
	case 545ULL: goto x86_l_221;
	case 548ULL: goto x86_l_224;
	case 553ULL: goto x86_l_229;
	case 558ULL: goto x86_l_22e;
	case 563ULL: goto x86_l_233;
	case 565ULL: goto x86_l_235;
	case 570ULL: goto x86_l_23a;
	case 575ULL: goto x86_l_23f;
	case 580ULL: goto x86_l_244;
	case 585ULL: goto x86_l_249;
	case 590ULL: goto x86_l_24e;
	case 592ULL: goto x86_l_250;
	case 598ULL: goto x86_l_256;
	case 600ULL: goto x86_l_258;
	case 606ULL: goto x86_l_25e;
	case 611ULL: goto x86_l_263;
	case 617ULL: goto x86_l_269;
	case 620ULL: goto x86_l_26c;
	case 625ULL: goto x86_l_271;
	case 630ULL: goto x86_l_276;
	case 635ULL: goto x86_l_27b;
	case 637ULL: goto x86_l_27d;
	case 642ULL: goto x86_l_282;
	case 647ULL: goto x86_l_287;
	case 652ULL: goto x86_l_28c;
	case 657ULL: goto x86_l_291;
	case 662ULL: goto x86_l_296;
	case 664ULL: goto x86_l_298;
	case 670ULL: goto x86_l_29e;
	case 672ULL: goto x86_l_2a0;
	case 678ULL: goto x86_l_2a6;
	case 683ULL: goto x86_l_2ab;
	case 689ULL: goto x86_l_2b1;
	case 692ULL: goto x86_l_2b4;
	case 697ULL: goto x86_l_2b9;
	case 702ULL: goto x86_l_2be;
	case 707ULL: goto x86_l_2c3;
	case 709ULL: goto x86_l_2c5;
	case 714ULL: goto x86_l_2ca;
	case 719ULL: goto x86_l_2cf;
	case 724ULL: goto x86_l_2d4;
	case 729ULL: goto x86_l_2d9;
	case 734ULL: goto x86_l_2de;
	case 736ULL: goto x86_l_2e0;
	case 742ULL: goto x86_l_2e6;
	case 744ULL: goto x86_l_2e8;
	case 750ULL: goto x86_l_2ee;
	case 755ULL: goto x86_l_2f3;
	case 761ULL: goto x86_l_2f9;
	case 764ULL: goto x86_l_2fc;
	case 769ULL: goto x86_l_301;
	case 774ULL: goto x86_l_306;
	case 779ULL: goto x86_l_30b;
	case 781ULL: goto x86_l_30d;
	case 786ULL: goto x86_l_312;
	case 791ULL: goto x86_l_317;
	case 796ULL: goto x86_l_31c;
	case 801ULL: goto x86_l_321;
	case 807ULL: goto x86_l_327;
	case 812ULL: goto x86_l_32c;
	case 814ULL: goto x86_l_32e;
	case 816ULL: goto x86_l_330;
	case 822ULL: goto x86_l_336;
	case 827ULL: goto x86_l_33b;
	case 833ULL: goto x86_l_341;
	case 836ULL: goto x86_l_344;
	case 841ULL: goto x86_l_349;
	case 846ULL: goto x86_l_34e;
	case 851ULL: goto x86_l_353;
	case 853ULL: goto x86_l_355;
	case 858ULL: goto x86_l_35a;
	case 863ULL: goto x86_l_35f;
	case 868ULL: goto x86_l_364;
	case 873ULL: goto x86_l_369;
	case 878ULL: goto x86_l_36e;
	case 880ULL: goto x86_l_370;
	case 886ULL: goto x86_l_376;
	case 888ULL: goto x86_l_378;
	case 890ULL: goto x86_l_37a;
	case 895ULL: goto x86_l_37f;
	case 901ULL: goto x86_l_385;
	case 904ULL: goto x86_l_388;
	case 909ULL: goto x86_l_38d;
	case 914ULL: goto x86_l_392;
	case 919ULL: goto x86_l_397;
	case 925ULL: goto x86_l_39d;
	case 930ULL: goto x86_l_3a2;
	case 935ULL: goto x86_l_3a7;
	case 940ULL: goto x86_l_3ac;
	case 945ULL: goto x86_l_3b1;
	case 950ULL: goto x86_l_3b6;
	case 952ULL: goto x86_l_3b8;
	case 958ULL: goto x86_l_3be;
	case 960ULL: goto x86_l_3c0;
	case 966ULL: goto x86_l_3c6;
	case 971ULL: goto x86_l_3cb;
	case 976ULL: goto x86_l_3d0;
	case 978ULL: goto x86_l_3d2;
	case 980ULL: goto x86_l_3d4;
	case 983ULL: goto x86_l_3d7;
	case 985ULL: goto x86_l_3d9;
	case 989ULL: goto x86_l_3dd;
	case 991ULL: goto x86_l_3df;
	case 995ULL: goto x86_l_3e3;
	case 997ULL: goto x86_l_3e5;
	case 1001ULL: goto x86_l_3e9;
	case 1003ULL: goto x86_l_3eb;
	case 1007ULL: goto x86_l_3ef;
	case 1012ULL: goto x86_l_3f4;
	case 1015ULL: goto x86_l_3f7;
	case 1021ULL: goto x86_l_3fd;
	case 1025ULL: goto x86_l_401;
	case 1028ULL: goto x86_l_404;
	case 1035ULL: goto x86_l_40b;
	case 1041ULL: goto x86_l_411;
	case 1045ULL: goto x86_l_415;
	case 1049ULL: goto x86_l_419;
	case 1054ULL: goto x86_l_41e;
	case 1059ULL: goto x86_l_423;
	case 1064ULL: goto x86_l_428;
	case 1069ULL: goto x86_l_42d;
	case 1074ULL: goto x86_l_432;
	case 1079ULL: goto x86_l_437;
	case 1086ULL: goto x86_l_43e;
	case 1089ULL: goto x86_l_441;
	case 1095ULL: goto x86_l_447;
	case 1101ULL: goto x86_l_44d;
	case 1107ULL: goto x86_l_453;
	case 1110ULL: goto x86_l_456;
	case 1115ULL: goto x86_l_45b;
	case 1120ULL: goto x86_l_460;
	case 1126ULL: goto x86_l_466;
	case 1128ULL: goto x86_l_468;
	case 1133ULL: goto x86_l_46d;
	case 1138ULL: goto x86_l_472;
	case 1143ULL: goto x86_l_477;
	case 1148ULL: goto x86_l_47c;
	case 1153ULL: goto x86_l_481;
	case 1155ULL: goto x86_l_483;
	case 1160ULL: goto x86_l_488;
	case 1162ULL: goto x86_l_48a;
	case 1168ULL: goto x86_l_490;
	case 1174ULL: goto x86_l_496;
	case 1180ULL: goto x86_l_49c;
	case 1184ULL: goto x86_l_4a0;
	case 1189ULL: goto x86_l_4a5;
	case 1194ULL: goto x86_l_4aa;
	case 1200ULL: goto x86_l_4b0;
	case 1202ULL: goto x86_l_4b2;
	case 1207ULL: goto x86_l_4b7;
	case 1212ULL: goto x86_l_4bc;
	case 1217ULL: goto x86_l_4c1;
	case 1222ULL: goto x86_l_4c6;
	case 1227ULL: goto x86_l_4cb;
	case 1229ULL: goto x86_l_4cd;
	case 1234ULL: goto x86_l_4d2;
	case 1236ULL: goto x86_l_4d4;
	case 1242ULL: goto x86_l_4da;
	case 1248ULL: goto x86_l_4e0;
	case 1254ULL: goto x86_l_4e6;
	case 1258ULL: goto x86_l_4ea;
	case 1263ULL: goto x86_l_4ef;
	case 1268ULL: goto x86_l_4f4;
	case 1274ULL: goto x86_l_4fa;
	case 1276ULL: goto x86_l_4fc;
	case 1281ULL: goto x86_l_501;
	case 1286ULL: goto x86_l_506;
	case 1291ULL: goto x86_l_50b;
	case 1296ULL: goto x86_l_510;
	case 1301ULL: goto x86_l_515;
	case 1303ULL: goto x86_l_517;
	case 1308ULL: goto x86_l_51c;
	case 1310ULL: goto x86_l_51e;
	case 1316ULL: goto x86_l_524;
	case 1322ULL: goto x86_l_52a;
	case 1328ULL: goto x86_l_530;
	case 1332ULL: goto x86_l_534;
	case 1337ULL: goto x86_l_539;
	case 1342ULL: goto x86_l_53e;
	case 1348ULL: goto x86_l_544;
	case 1350ULL: goto x86_l_546;
	case 1355ULL: goto x86_l_54b;
	case 1360ULL: goto x86_l_550;
	case 1365ULL: goto x86_l_555;
	case 1370ULL: goto x86_l_55a;
	case 1375ULL: goto x86_l_55f;
	case 1377ULL: goto x86_l_561;
	case 1382ULL: goto x86_l_566;
	case 1384ULL: goto x86_l_568;
	case 1390ULL: goto x86_l_56e;
	case 1396ULL: goto x86_l_574;
	case 1402ULL: goto x86_l_57a;
	case 1406ULL: goto x86_l_57e;
	case 1411ULL: goto x86_l_583;
	case 1416ULL: goto x86_l_588;
	case 1422ULL: goto x86_l_58e;
	case 1424ULL: goto x86_l_590;
	case 1429ULL: goto x86_l_595;
	case 1434ULL: goto x86_l_59a;
	case 1439ULL: goto x86_l_59f;
	case 1444ULL: goto x86_l_5a4;
	case 1449ULL: goto x86_l_5a9;
	case 1451ULL: goto x86_l_5ab;
	case 1456ULL: goto x86_l_5b0;
	case 1458ULL: goto x86_l_5b2;
	case 1464ULL: goto x86_l_5b8;
	case 1470ULL: goto x86_l_5be;
	case 1476ULL: goto x86_l_5c4;
	case 1480ULL: goto x86_l_5c8;
	case 1485ULL: goto x86_l_5cd;
	case 1490ULL: goto x86_l_5d2;
	case 1496ULL: goto x86_l_5d8;
	case 1498ULL: goto x86_l_5da;
	case 1503ULL: goto x86_l_5df;
	case 1508ULL: goto x86_l_5e4;
	case 1513ULL: goto x86_l_5e9;
	case 1518ULL: goto x86_l_5ee;
	case 1523ULL: goto x86_l_5f3;
	case 1525ULL: goto x86_l_5f5;
	case 1530ULL: goto x86_l_5fa;
	case 1532ULL: goto x86_l_5fc;
	case 1538ULL: goto x86_l_602;
	case 1544ULL: goto x86_l_608;
	case 1550ULL: goto x86_l_60e;
	case 1554ULL: goto x86_l_612;
	case 1559ULL: goto x86_l_617;
	case 1564ULL: goto x86_l_61c;
	case 1570ULL: goto x86_l_622;
	case 1572ULL: goto x86_l_624;
	case 1577ULL: goto x86_l_629;
	case 1582ULL: goto x86_l_62e;
	case 1587ULL: goto x86_l_633;
	case 1592ULL: goto x86_l_638;
	case 1597ULL: goto x86_l_63d;
	case 1599ULL: goto x86_l_63f;
	case 1604ULL: goto x86_l_644;
	case 1606ULL: goto x86_l_646;
	case 1612ULL: goto x86_l_64c;
	case 1618ULL: goto x86_l_652;
	case 1624ULL: goto x86_l_658;
	case 1628ULL: goto x86_l_65c;
	case 1633ULL: goto x86_l_661;
	case 1638ULL: goto x86_l_666;
	case 1644ULL: goto x86_l_66c;
	case 1646ULL: goto x86_l_66e;
	case 1651ULL: goto x86_l_673;
	case 1656ULL: goto x86_l_678;
	case 1661ULL: goto x86_l_67d;
	case 1666ULL: goto x86_l_682;
	case 1671ULL: goto x86_l_687;
	case 1676ULL: goto x86_l_68c;
	case 1678ULL: goto x86_l_68e;
	case 1680ULL: goto x86_l_690;
	case 1686ULL: goto x86_l_696;
	case 1692ULL: goto x86_l_69c;
	case 1698ULL: goto x86_l_6a2;
	case 1702ULL: goto x86_l_6a6;
	case 1707ULL: goto x86_l_6ab;
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
	/* 0x5: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_6:
	/* 0x6: sub    rsp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 56ULL);
x86_l_a:
	/* 0xa: mov    ebx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_32);
x86_l_c:
	/* 0xc: and    ebx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_f:
	/* 0xf: mov    r14,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12:
	/* 0x12: mov    eax,DWORD PTR [r14+rbx*4+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 24ULL);
x86_l_17:
	/* 0x17: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_1c:
	/* 0x1c: jne    2f <try_preload_arg+0x2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f;
	}
x86_l_1e:
	/* 0x1e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20:
	/* 0x20: add    rsp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_24:
	/* 0x24: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_25:
	/* 0x25: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_27:
	/* 0x27: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_29:
	/* 0x29: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2a:
	/* 0x2a: jmp    8a9 <try_preload_arg+0x8a9> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2f:
	/* 0x2f: mov    rdi,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33:
	/* 0x33: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_35:
	/* 0x35: js     71 <try_preload_arg+0x71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_71;
	}
x86_l_37:
	/* 0x37: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3f:
	/* 0x3f: mov    eax,DWORD PTR [r14+rbx*4+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 64ULL);
x86_l_44:
	/* 0x44: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_47:
	/* 0x47: jle    3d0 <try_preload_arg+0x3d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3d0;
	}
x86_l_4d:
	/* 0x4d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_50:
	/* 0x50: je     3df <try_preload_arg+0x3df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3df;
	}
x86_l_56:
	/* 0x56: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_59:
	/* 0x59: je     3e5 <try_preload_arg+0x3e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e5;
	}
x86_l_5f:
	/* 0x5f: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_62:
	/* 0x62: jne    3f4 <try_preload_arg+0x3f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3f4;
	}
x86_l_68:
	/* 0x68: mov    rax,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6c:
	/* 0x6c: jmp    3ef <try_preload_arg+0x3ef> */
	goto x86_l_3ef;
x86_l_71:
	/* 0x71: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_79:
	/* 0x79: movzx  eax,BYTE PTR [r14+rbx*4+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBX, 2, X86_WIDTH_8), 706ULL);
x86_l_82:
	/* 0x82: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_85:
	/* 0x85: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_87:
	/* 0x87: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_89:
	/* 0x89: movzx  esi,WORD PTR [r14+rbx*4+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBX, 2, X86_WIDTH_16), 704ULL);
x86_l_92:
	/* 0x92: movzx  edx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_95:
	/* 0x95: call   0 <try_preload_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 154ULL);
	__x86_sim_call_depth++;
	goto x86_l_0;
x86_l_9a:
	/* 0x9a: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9f:
	/* 0x9f: mov    ebp,DWORD PTR [r14+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_a4:
	/* 0xa4: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_a7:
	/* 0xa7: ja     754 <try_preload_arg+0x754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1876ULL;
	}
x86_l_ad:
	/* 0xad: lea    rax,[rbx+rbx*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 2), 0ULL);
x86_l_b1:
	/* 0xb1: shl    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_b4:
	/* 0xb4: cmp    WORD PTR [r14+rax*1+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 506806140928ULL);
x86_l_bb:
	/* 0xbb: je     754 <try_preload_arg+0x754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1876ULL;
	}
x86_l_c1:
	/* 0xc1: lea    rbx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_c5:
	/* 0xc5: add    rbx,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_c9:
	/* 0xc9: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ce:
	/* 0xce: lea    rax,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d3:
	/* 0xd3: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d8:
	/* 0xd8: mov    BYTE PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_dd:
	/* 0xdd: lea    rax,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e2:
	/* 0xe2: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e7:
	/* 0xe7: mov    rax,QWORD PTR [rip+0x2e2c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_ee:
	/* 0xee: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f1:
	/* 0xf1: je     733 <try_preload_arg+0x733> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1843ULL;
	}
x86_l_f7:
	/* 0xf7: cmp    WORD PTR [rbx+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 25769803776ULL);
x86_l_fc:
	/* 0xfc: je     754 <try_preload_arg+0x754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1876ULL;
	}
x86_l_102:
	/* 0x102: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_104:
	/* 0x104: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_109:
	/* 0x109: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10e:
	/* 0x10e: cmp    WORD PTR [rbx+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_113:
	/* 0x113: je     13e <try_preload_arg+0x13e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13e;
	}
x86_l_115:
	/* 0x115: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11a:
	/* 0x11a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_11f:
	/* 0x11f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_124:
	/* 0x124: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_129:
	/* 0x129: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12e:
	/* 0x12e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_130:
	/* 0x130: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_136:
	/* 0x136: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_138:
	/* 0x138: js     3c6 <try_preload_arg+0x3c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c6;
	}
x86_l_13e:
	/* 0x13e: cmp    WORD PTR [rbx+0xe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_143:
	/* 0x143: je     754 <try_preload_arg+0x754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1876ULL;
	}
x86_l_149:
	/* 0x149: mov    ecx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14c:
	/* 0x14c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_151:
	/* 0x151: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_156:
	/* 0x156: cmp    WORD PTR [rbx+0xc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_15b:
	/* 0x15b: je     186 <try_preload_arg+0x186> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_186;
	}
x86_l_15d:
	/* 0x15d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_162:
	/* 0x162: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_167:
	/* 0x167: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_16c:
	/* 0x16c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_171:
	/* 0x171: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_176:
	/* 0x176: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_178:
	/* 0x178: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_17e:
	/* 0x17e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_180:
	/* 0x180: js     3c6 <try_preload_arg+0x3c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c6;
	}
x86_l_186:
	/* 0x186: cmp    WORD PTR [rbx+0x16],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94489280512ULL);
x86_l_18b:
	/* 0x18b: je     754 <try_preload_arg+0x754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1876ULL;
	}
x86_l_191:
	/* 0x191: mov    ecx,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_194:
	/* 0x194: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_199:
	/* 0x199: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19e:
	/* 0x19e: cmp    WORD PTR [rbx+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1a3:
	/* 0x1a3: je     1ce <try_preload_arg+0x1ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ce;
	}
x86_l_1a5:
	/* 0x1a5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aa:
	/* 0x1aa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1af:
	/* 0x1af: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b4:
	/* 0x1b4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b9:
	/* 0x1b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1be:
	/* 0x1be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c0:
	/* 0x1c0: mov    r14d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 3ULL);
x86_l_1c6:
	/* 0x1c6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c8:
	/* 0x1c8: js     3c6 <try_preload_arg+0x3c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c6;
	}
x86_l_1ce:
	/* 0x1ce: cmp    WORD PTR [rbx+0x1e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128849018880ULL);
x86_l_1d3:
	/* 0x1d3: je     754 <try_preload_arg+0x754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1876ULL;
	}
x86_l_1d9:
	/* 0x1d9: mov    ecx,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1dc:
	/* 0x1dc: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1e1:
	/* 0x1e1: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e6:
	/* 0x1e6: cmp    WORD PTR [rbx+0x1c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_1eb:
	/* 0x1eb: je     216 <try_preload_arg+0x216> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_216;
	}
x86_l_1ed:
	/* 0x1ed: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f2:
	/* 0x1f2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1f7:
	/* 0x1f7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1fc:
	/* 0x1fc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_201:
	/* 0x201: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_206:
	/* 0x206: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_208:
	/* 0x208: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_20e:
	/* 0x20e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_210:
	/* 0x210: js     3c6 <try_preload_arg+0x3c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c6;
	}
x86_l_216:
	/* 0x216: cmp    WORD PTR [rbx+0x26],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_21b:
	/* 0x21b: je     754 <try_preload_arg+0x754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1876ULL;
	}
x86_l_221:
	/* 0x221: mov    ecx,DWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_224:
	/* 0x224: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_229:
	/* 0x229: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22e:
	/* 0x22e: cmp    WORD PTR [rbx+0x24],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_233:
	/* 0x233: je     25e <try_preload_arg+0x25e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e;
	}
x86_l_235:
	/* 0x235: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23a:
	/* 0x23a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23f:
	/* 0x23f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_244:
	/* 0x244: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_249:
	/* 0x249: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24e:
	/* 0x24e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_250:
	/* 0x250: mov    r14d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 5ULL);
x86_l_256:
	/* 0x256: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_258:
	/* 0x258: js     3c6 <try_preload_arg+0x3c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c6;
	}
x86_l_25e:
	/* 0x25e: cmp    WORD PTR [rbx+0x2e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 197568495616ULL);
x86_l_263:
	/* 0x263: je     754 <try_preload_arg+0x754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1876ULL;
	}
x86_l_269:
	/* 0x269: mov    ecx,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_26c:
	/* 0x26c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_271:
	/* 0x271: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_276:
	/* 0x276: cmp    WORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_27b:
	/* 0x27b: je     2a6 <try_preload_arg+0x2a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a6;
	}
x86_l_27d:
	/* 0x27d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_282:
	/* 0x282: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_287:
	/* 0x287: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_28c:
	/* 0x28c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_291:
	/* 0x291: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_296:
	/* 0x296: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_298:
	/* 0x298: mov    r14d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 6ULL);
x86_l_29e:
	/* 0x29e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a0:
	/* 0x2a0: js     3c6 <try_preload_arg+0x3c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c6;
	}
x86_l_2a6:
	/* 0x2a6: cmp    WORD PTR [rbx+0x36],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 231928233984ULL);
x86_l_2ab:
	/* 0x2ab: je     754 <try_preload_arg+0x754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1876ULL;
	}
x86_l_2b1:
	/* 0x2b1: mov    ecx,DWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b4:
	/* 0x2b4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2b9:
	/* 0x2b9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2be:
	/* 0x2be: cmp    WORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_2c3:
	/* 0x2c3: je     2ee <try_preload_arg+0x2ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ee;
	}
x86_l_2c5:
	/* 0x2c5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ca:
	/* 0x2ca: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2cf:
	/* 0x2cf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d4:
	/* 0x2d4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d9:
	/* 0x2d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2de:
	/* 0x2de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e0:
	/* 0x2e0: mov    r14d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 7ULL);
x86_l_2e6:
	/* 0x2e6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e8:
	/* 0x2e8: js     3c6 <try_preload_arg+0x3c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c6;
	}
x86_l_2ee:
	/* 0x2ee: cmp    WORD PTR [rbx+0x3e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 266287972352ULL);
x86_l_2f3:
	/* 0x2f3: je     754 <try_preload_arg+0x754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1876ULL;
	}
x86_l_2f9:
	/* 0x2f9: mov    ecx,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2fc:
	/* 0x2fc: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_301:
	/* 0x301: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_306:
	/* 0x306: cmp    WORD PTR [rbx+0x3c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_30b:
	/* 0x30b: je     336 <try_preload_arg+0x336> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_336;
	}
x86_l_30d:
	/* 0x30d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_312:
	/* 0x312: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_317:
	/* 0x317: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_31c:
	/* 0x31c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_321:
	/* 0x321: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_327:
	/* 0x327: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32c:
	/* 0x32c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32e:
	/* 0x32e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_330:
	/* 0x330: js     3c6 <try_preload_arg+0x3c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c6;
	}
x86_l_336:
	/* 0x336: cmp    WORD PTR [rbx+0x46],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 300647710720ULL);
x86_l_33b:
	/* 0x33b: je     754 <try_preload_arg+0x754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1876ULL;
	}
x86_l_341:
	/* 0x341: mov    ecx,DWORD PTR [rbx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_344:
	/* 0x344: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_349:
	/* 0x349: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34e:
	/* 0x34e: cmp    WORD PTR [rbx+0x44],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_353:
	/* 0x353: je     37a <try_preload_arg+0x37a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37a;
	}
x86_l_355:
	/* 0x355: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35a:
	/* 0x35a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_35f:
	/* 0x35f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_364:
	/* 0x364: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_369:
	/* 0x369: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36e:
	/* 0x36e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_370:
	/* 0x370: mov    r14d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 9ULL);
x86_l_376:
	/* 0x376: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_378:
	/* 0x378: js     3c6 <try_preload_arg+0x3c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c6;
	}
x86_l_37a:
	/* 0x37a: cmp    WORD PTR [rbx+0x4e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 335007449088ULL);
x86_l_37f:
	/* 0x37f: je     754 <try_preload_arg+0x754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1876ULL;
	}
x86_l_385:
	/* 0x385: mov    ecx,DWORD PTR [rbx+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_388:
	/* 0x388: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_38d:
	/* 0x38d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_392:
	/* 0x392: cmp    WORD PTR [rbx+0x4c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 326417514496ULL);
x86_l_397:
	/* 0x397: je     754 <try_preload_arg+0x754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1876ULL;
	}
x86_l_39d:
	/* 0x39d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a2:
	/* 0x3a2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a7:
	/* 0x3a7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3ac:
	/* 0x3ac: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b1:
	/* 0x3b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b6:
	/* 0x3b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b8:
	/* 0x3b8: mov    r14d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 10ULL);
x86_l_3be:
	/* 0x3be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c0:
	/* 0x3c0: jns    754 <try_preload_arg+0x754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 1876ULL;
	}
x86_l_3c6:
	/* 0x3c6: mov    DWORD PTR [rsp+0x10],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cb:
	/* 0x3cb: jmp    754 <try_preload_arg+0x754> */
	return 1876ULL;
x86_l_3d0:
	/* 0x3d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d2:
	/* 0x3d2: je     3eb <try_preload_arg+0x3eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3eb;
	}
x86_l_3d4:
	/* 0x3d4: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3d7:
	/* 0x3d7: jne    3f4 <try_preload_arg+0x3f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3f4;
	}
x86_l_3d9:
	/* 0x3d9: mov    rax,QWORD PTR [rdi+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3dd:
	/* 0x3dd: jmp    3ef <try_preload_arg+0x3ef> */
	goto x86_l_3ef;
x86_l_3df:
	/* 0x3df: mov    rax,QWORD PTR [rdi+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3e3:
	/* 0x3e3: jmp    3ef <try_preload_arg+0x3ef> */
	goto x86_l_3ef;
x86_l_3e5:
	/* 0x3e5: mov    rax,QWORD PTR [rdi+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3e9:
	/* 0x3e9: jmp    3ef <try_preload_arg+0x3ef> */
	goto x86_l_3ef;
x86_l_3eb:
	/* 0x3eb: mov    rax,QWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3ef:
	/* 0x3ef: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f4:
	/* 0x3f4: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_3f7:
	/* 0x3f7: ja     7e1 <try_preload_arg+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2017ULL;
	}
x86_l_3fd:
	/* 0x3fd: lea    rax,[rbx+rbx*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 2), 0ULL);
x86_l_401:
	/* 0x401: shl    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_404:
	/* 0x404: cmp    WORD PTR [r14+rax*1+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 506806140928ULL);
x86_l_40b:
	/* 0x40b: je     7e1 <try_preload_arg+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2017ULL;
	}
x86_l_411:
	/* 0x411: lea    r15,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_415:
	/* 0x415: add    r15,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_419:
	/* 0x419: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_41e:
	/* 0x41e: lea    rax,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_423:
	/* 0x423: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_428:
	/* 0x428: mov    BYTE PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_42d:
	/* 0x42d: lea    rax,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_432:
	/* 0x432: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_437:
	/* 0x437: mov    rax,QWORD PTR [rip+0x2e2c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_43e:
	/* 0x43e: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_441:
	/* 0x441: je     7c0 <try_preload_arg+0x7c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1984ULL;
	}
x86_l_447:
	/* 0x447: cmp    WORD PTR [r15+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 25769803776ULL);
x86_l_44d:
	/* 0x44d: je     7e1 <try_preload_arg+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2017ULL;
	}
x86_l_453:
	/* 0x453: mov    ecx,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_456:
	/* 0x456: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_45b:
	/* 0x45b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_460:
	/* 0x460: cmp    WORD PTR [r15+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_466:
	/* 0x466: je     490 <try_preload_arg+0x490> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_490;
	}
x86_l_468:
	/* 0x468: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46d:
	/* 0x46d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_472:
	/* 0x472: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_477:
	/* 0x477: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47c:
	/* 0x47c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_481:
	/* 0x481: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_483:
	/* 0x483: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_488:
	/* 0x488: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48a:
	/* 0x48a: js     72a <try_preload_arg+0x72a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1834ULL;
	}
x86_l_490:
	/* 0x490: cmp    WORD PTR [r15+0xe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_496:
	/* 0x496: je     7e1 <try_preload_arg+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2017ULL;
	}
x86_l_49c:
	/* 0x49c: mov    ecx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a0:
	/* 0x4a0: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4a5:
	/* 0x4a5: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4aa:
	/* 0x4aa: cmp    WORD PTR [r15+0xc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_4b0:
	/* 0x4b0: je     4da <try_preload_arg+0x4da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4da;
	}
x86_l_4b2:
	/* 0x4b2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b7:
	/* 0x4b7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4bc:
	/* 0x4bc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4c1:
	/* 0x4c1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c6:
	/* 0x4c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cb:
	/* 0x4cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cd:
	/* 0x4cd: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_4d2:
	/* 0x4d2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d4:
	/* 0x4d4: js     72a <try_preload_arg+0x72a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1834ULL;
	}
x86_l_4da:
	/* 0x4da: cmp    WORD PTR [r15+0x16],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94489280512ULL);
x86_l_4e0:
	/* 0x4e0: je     7e1 <try_preload_arg+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2017ULL;
	}
x86_l_4e6:
	/* 0x4e6: mov    ecx,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ea:
	/* 0x4ea: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4ef:
	/* 0x4ef: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f4:
	/* 0x4f4: cmp    WORD PTR [r15+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_4fa:
	/* 0x4fa: je     524 <try_preload_arg+0x524> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_524;
	}
x86_l_4fc:
	/* 0x4fc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_501:
	/* 0x501: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_506:
	/* 0x506: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_50b:
	/* 0x50b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_510:
	/* 0x510: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_515:
	/* 0x515: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_517:
	/* 0x517: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_51c:
	/* 0x51c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_51e:
	/* 0x51e: js     72a <try_preload_arg+0x72a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1834ULL;
	}
x86_l_524:
	/* 0x524: cmp    WORD PTR [r15+0x1e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128849018880ULL);
x86_l_52a:
	/* 0x52a: je     7e1 <try_preload_arg+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2017ULL;
	}
x86_l_530:
	/* 0x530: mov    ecx,DWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_534:
	/* 0x534: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_539:
	/* 0x539: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53e:
	/* 0x53e: cmp    WORD PTR [r15+0x1c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_544:
	/* 0x544: je     56e <try_preload_arg+0x56e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56e;
	}
x86_l_546:
	/* 0x546: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54b:
	/* 0x54b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_550:
	/* 0x550: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_555:
	/* 0x555: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55a:
	/* 0x55a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55f:
	/* 0x55f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_561:
	/* 0x561: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_566:
	/* 0x566: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_568:
	/* 0x568: js     72a <try_preload_arg+0x72a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1834ULL;
	}
x86_l_56e:
	/* 0x56e: cmp    WORD PTR [r15+0x26],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_574:
	/* 0x574: je     7e1 <try_preload_arg+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2017ULL;
	}
x86_l_57a:
	/* 0x57a: mov    ecx,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_57e:
	/* 0x57e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_583:
	/* 0x583: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_588:
	/* 0x588: cmp    WORD PTR [r15+0x24],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_58e:
	/* 0x58e: je     5b8 <try_preload_arg+0x5b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b8;
	}
x86_l_590:
	/* 0x590: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_595:
	/* 0x595: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_59a:
	/* 0x59a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_59f:
	/* 0x59f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a4:
	/* 0x5a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a9:
	/* 0x5a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ab:
	/* 0x5ab: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_5b0:
	/* 0x5b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5b2:
	/* 0x5b2: js     72a <try_preload_arg+0x72a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1834ULL;
	}
x86_l_5b8:
	/* 0x5b8: cmp    WORD PTR [r15+0x2e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 197568495616ULL);
x86_l_5be:
	/* 0x5be: je     7e1 <try_preload_arg+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2017ULL;
	}
x86_l_5c4:
	/* 0x5c4: mov    ecx,DWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5c8:
	/* 0x5c8: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5cd:
	/* 0x5cd: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d2:
	/* 0x5d2: cmp    WORD PTR [r15+0x2c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_5d8:
	/* 0x5d8: je     602 <try_preload_arg+0x602> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_602;
	}
x86_l_5da:
	/* 0x5da: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5df:
	/* 0x5df: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5e4:
	/* 0x5e4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5e9:
	/* 0x5e9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ee:
	/* 0x5ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f3:
	/* 0x5f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f5:
	/* 0x5f5: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_5fa:
	/* 0x5fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5fc:
	/* 0x5fc: js     72a <try_preload_arg+0x72a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1834ULL;
	}
x86_l_602:
	/* 0x602: cmp    WORD PTR [r15+0x36],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 231928233984ULL);
x86_l_608:
	/* 0x608: je     7e1 <try_preload_arg+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2017ULL;
	}
x86_l_60e:
	/* 0x60e: mov    ecx,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_612:
	/* 0x612: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_617:
	/* 0x617: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_61c:
	/* 0x61c: cmp    WORD PTR [r15+0x34],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_622:
	/* 0x622: je     64c <try_preload_arg+0x64c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_64c;
	}
x86_l_624:
	/* 0x624: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_629:
	/* 0x629: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_62e:
	/* 0x62e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_633:
	/* 0x633: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_638:
	/* 0x638: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_63d:
	/* 0x63d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63f:
	/* 0x63f: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_644:
	/* 0x644: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_646:
	/* 0x646: js     72a <try_preload_arg+0x72a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1834ULL;
	}
x86_l_64c:
	/* 0x64c: cmp    WORD PTR [r15+0x3e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 266287972352ULL);
x86_l_652:
	/* 0x652: je     7e1 <try_preload_arg+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2017ULL;
	}
x86_l_658:
	/* 0x658: mov    ecx,DWORD PTR [r15+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_65c:
	/* 0x65c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_661:
	/* 0x661: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_666:
	/* 0x666: cmp    WORD PTR [r15+0x3c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_66c:
	/* 0x66c: je     696 <try_preload_arg+0x696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_696;
	}
x86_l_66e:
	/* 0x66e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_673:
	/* 0x673: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_678:
	/* 0x678: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_67d:
	/* 0x67d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_682:
	/* 0x682: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_687:
	/* 0x687: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_68c:
	/* 0x68c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68e:
	/* 0x68e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_690:
	/* 0x690: js     72a <try_preload_arg+0x72a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1834ULL;
	}
x86_l_696:
	/* 0x696: cmp    WORD PTR [r15+0x46],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 300647710720ULL);
x86_l_69c:
	/* 0x69c: je     7e1 <try_preload_arg+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2017ULL;
	}
x86_l_6a2:
	/* 0x6a2: mov    ecx,DWORD PTR [r15+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6a6:
	/* 0x6a6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6ab:
	/* 0x6ab: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 1712ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v61_try_preload_arg_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1712ULL: goto x86_l_6b0;
	case 1718ULL: goto x86_l_6b6;
	case 1720ULL: goto x86_l_6b8;
	case 1725ULL: goto x86_l_6bd;
	case 1730ULL: goto x86_l_6c2;
	case 1735ULL: goto x86_l_6c7;
	case 1740ULL: goto x86_l_6cc;
	case 1745ULL: goto x86_l_6d1;
	case 1747ULL: goto x86_l_6d3;
	case 1752ULL: goto x86_l_6d8;
	case 1754ULL: goto x86_l_6da;
	case 1756ULL: goto x86_l_6dc;
	case 1762ULL: goto x86_l_6e2;
	case 1768ULL: goto x86_l_6e8;
	case 1772ULL: goto x86_l_6ec;
	case 1777ULL: goto x86_l_6f1;
	case 1782ULL: goto x86_l_6f6;
	case 1788ULL: goto x86_l_6fc;
	case 1794ULL: goto x86_l_702;
	case 1799ULL: goto x86_l_707;
	case 1804ULL: goto x86_l_70c;
	case 1809ULL: goto x86_l_711;
	case 1814ULL: goto x86_l_716;
	case 1819ULL: goto x86_l_71b;
	case 1821ULL: goto x86_l_71d;
	case 1826ULL: goto x86_l_722;
	case 1828ULL: goto x86_l_724;
	case 1834ULL: goto x86_l_72a;
	case 1838ULL: goto x86_l_72e;
	case 1843ULL: goto x86_l_733;
	case 1850ULL: goto x86_l_73a;
	case 1852ULL: goto x86_l_73c;
	case 1857ULL: goto x86_l_741;
	case 1862ULL: goto x86_l_746;
	case 1867ULL: goto x86_l_74b;
	case 1872ULL: goto x86_l_750;
	case 1874ULL: goto x86_l_752;
	case 1876ULL: goto x86_l_754;
	case 1879ULL: goto x86_l_757;
	case 1885ULL: goto x86_l_75d;
	case 1890ULL: goto x86_l_762;
	case 1894ULL: goto x86_l_766;
	case 1899ULL: goto x86_l_76b;
	case 1901ULL: goto x86_l_76d;
	case 1906ULL: goto x86_l_772;
	case 1914ULL: goto x86_l_77a;
	case 1921ULL: goto x86_l_781;
	case 1926ULL: goto x86_l_786;
	case 1931ULL: goto x86_l_78b;
	case 1933ULL: goto x86_l_78d;
	case 1936ULL: goto x86_l_790;
	case 1942ULL: goto x86_l_796;
	case 1945ULL: goto x86_l_799;
	case 1952ULL: goto x86_l_7a0;
	case 1954ULL: goto x86_l_7a2;
	case 1959ULL: goto x86_l_7a7;
	case 1964ULL: goto x86_l_7ac;
	case 1967ULL: goto x86_l_7af;
	case 1970ULL: goto x86_l_7b2;
	case 1972ULL: goto x86_l_7b4;
	case 1974ULL: goto x86_l_7b6;
	case 1979ULL: goto x86_l_7bb;
	case 1984ULL: goto x86_l_7c0;
	case 1991ULL: goto x86_l_7c7;
	case 1993ULL: goto x86_l_7c9;
	case 1998ULL: goto x86_l_7ce;
	case 2003ULL: goto x86_l_7d3;
	case 2008ULL: goto x86_l_7d8;
	case 2013ULL: goto x86_l_7dd;
	case 2015ULL: goto x86_l_7df;
	case 2017ULL: goto x86_l_7e1;
	case 2022ULL: goto x86_l_7e6;
	case 2027ULL: goto x86_l_7eb;
	case 2032ULL: goto x86_l_7f0;
	case 2037ULL: goto x86_l_7f5;
	case 2042ULL: goto x86_l_7fa;
	case 2045ULL: goto x86_l_7fd;
	case 2047ULL: goto x86_l_7ff;
	case 2050ULL: goto x86_l_802;
	case 2056ULL: goto x86_l_808;
	case 2061ULL: goto x86_l_80d;
	case 2065ULL: goto x86_l_811;
	case 2070ULL: goto x86_l_816;
	case 2072ULL: goto x86_l_818;
	case 2077ULL: goto x86_l_81d;
	case 2085ULL: goto x86_l_825;
	case 2092ULL: goto x86_l_82c;
	case 2097ULL: goto x86_l_831;
	case 2102ULL: goto x86_l_836;
	case 2104ULL: goto x86_l_838;
	case 2107ULL: goto x86_l_83b;
	case 2113ULL: goto x86_l_841;
	case 2116ULL: goto x86_l_844;
	case 2123ULL: goto x86_l_84b;
	case 2125ULL: goto x86_l_84d;
	case 2130ULL: goto x86_l_852;
	case 2135ULL: goto x86_l_857;
	case 2138ULL: goto x86_l_85a;
	case 2141ULL: goto x86_l_85d;
	case 2143ULL: goto x86_l_85f;
	case 2145ULL: goto x86_l_861;
	case 2150ULL: goto x86_l_866;
	case 2153ULL: goto x86_l_869;
	case 2156ULL: goto x86_l_86c;
	case 2158ULL: goto x86_l_86e;
	case 2161ULL: goto x86_l_871;
	case 2167ULL: goto x86_l_877;
	case 2169ULL: goto x86_l_879;
	case 2171ULL: goto x86_l_87b;
	case 2174ULL: goto x86_l_87e;
	case 2178ULL: goto x86_l_882;
	case 2183ULL: goto x86_l_887;
	case 2186ULL: goto x86_l_88a;
	case 2188ULL: goto x86_l_88c;
	case 2191ULL: goto x86_l_88f;
	case 2196ULL: goto x86_l_894;
	case 2198ULL: goto x86_l_896;
	case 2201ULL: goto x86_l_899;
	case 2203ULL: goto x86_l_89b;
	case 2205ULL: goto x86_l_89d;
	case 2210ULL: goto x86_l_8a2;
	case 2212ULL: goto x86_l_8a4;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6b0:
	/* 0x6b0: cmp    WORD PTR [r15+0x44],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_6b6:
	/* 0x6b6: je     6dc <try_preload_arg+0x6dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6dc;
	}
x86_l_6b8:
	/* 0x6b8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6bd:
	/* 0x6bd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6c2:
	/* 0x6c2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_6c7:
	/* 0x6c7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6cc:
	/* 0x6cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6d1:
	/* 0x6d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d3:
	/* 0x6d3: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_6d8:
	/* 0x6d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6da:
	/* 0x6da: js     72a <try_preload_arg+0x72a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_72a;
	}
x86_l_6dc:
	/* 0x6dc: cmp    WORD PTR [r15+0x4e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 335007449088ULL);
x86_l_6e2:
	/* 0x6e2: je     7e1 <try_preload_arg+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e1;
	}
x86_l_6e8:
	/* 0x6e8: mov    ecx,DWORD PTR [r15+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6ec:
	/* 0x6ec: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6f1:
	/* 0x6f1: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6f6:
	/* 0x6f6: cmp    WORD PTR [r15+0x4c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 326417514496ULL);
x86_l_6fc:
	/* 0x6fc: je     7e1 <try_preload_arg+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e1;
	}
x86_l_702:
	/* 0x702: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_707:
	/* 0x707: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_70c:
	/* 0x70c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_711:
	/* 0x711: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_716:
	/* 0x716: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_71b:
	/* 0x71b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_71d:
	/* 0x71d: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_722:
	/* 0x722: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_724:
	/* 0x724: jns    7e1 <try_preload_arg+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_7e1;
	}
x86_l_72a:
	/* 0x72a: mov    DWORD PTR [rsp+0x10],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_72e:
	/* 0x72e: jmp    7e1 <try_preload_arg+0x7e1> */
	goto x86_l_7e1;
x86_l_733:
	/* 0x733: lea    rsi,[rip+0xfffffffffffff9ea] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 18446744073709550058ULL);
x86_l_73a:
	/* 0x73a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_73c:
	/* 0x73c: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_741:
	/* 0x741: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_746:
	/* 0x746: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_74b:
	/* 0x74b: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_750:
	/* 0x750: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_752:
	/* 0x752: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_754:
	/* 0x754: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_757:
	/* 0x757: jne    1e <try_preload_arg+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 30ULL;
	}
x86_l_75d:
	/* 0x75d: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_762:
	/* 0x762: mov    ebp,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_766:
	/* 0x766: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_76b:
	/* 0x76b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76d:
	/* 0x76d: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_772:
	/* 0x772: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_77a:
	/* 0x77a: mov    rdi,QWORD PTR [rip+0x2e2c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_781:
	/* 0x781: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_786:
	/* 0x786: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_78b:
	/* 0x78b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_78d:
	/* 0x78d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_790:
	/* 0x790: je     1e <try_preload_arg+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 30ULL;
	}
x86_l_796:
	/* 0x796: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_799:
	/* 0x799: mov    r14,QWORD PTR [rip+0x2e2c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_7a0:
	/* 0x7a0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7a2:
	/* 0x7a2: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7a7:
	/* 0x7a7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7ac:
	/* 0x7ac: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_7af:
	/* 0x7af: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_7b2:
	/* 0x7b2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7b4:
	/* 0x7b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b6:
	/* 0x7b6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7bb:
	/* 0x7bb: jmp    866 <try_preload_arg+0x866> */
	goto x86_l_866;
x86_l_7c0:
	/* 0x7c0: lea    rsi,[rip+0xfffffffffffff95d] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 18446744073709549917ULL);
x86_l_7c7:
	/* 0x7c7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7c9:
	/* 0x7c9: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7ce:
	/* 0x7ce: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_7d3:
	/* 0x7d3: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_7d8:
	/* 0x7d8: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_7dd:
	/* 0x7dd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7df:
	/* 0x7df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e1:
	/* 0x7e1: mov    ebx,DWORD PTR [r14+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_7e6:
	/* 0x7e6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7eb:
	/* 0x7eb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7f0:
	/* 0x7f0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7f5:
	/* 0x7f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7fa:
	/* 0x7fa: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_7fd:
	/* 0x7fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ff:
	/* 0x7ff: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_802:
	/* 0x802: jne    1e <try_preload_arg+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 30ULL;
	}
x86_l_808:
	/* 0x808: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_80d:
	/* 0x80d: mov    ebp,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_811:
	/* 0x811: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_816:
	/* 0x816: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_818:
	/* 0x818: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_81d:
	/* 0x81d: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_825:
	/* 0x825: mov    rdi,QWORD PTR [rip+0x2e2c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_82c:
	/* 0x82c: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_831:
	/* 0x831: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_836:
	/* 0x836: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_838:
	/* 0x838: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_83b:
	/* 0x83b: je     1e <try_preload_arg+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 30ULL;
	}
x86_l_841:
	/* 0x841: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_844:
	/* 0x844: mov    r14,QWORD PTR [rip+0x2e2c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_84b:
	/* 0x84b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_84d:
	/* 0x84d: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_852:
	/* 0x852: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_857:
	/* 0x857: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_85a:
	/* 0x85a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_85d:
	/* 0x85d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_85f:
	/* 0x85f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_861:
	/* 0x861: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_866:
	/* 0x866: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_869:
	/* 0x869: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_86c:
	/* 0x86c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_86e:
	/* 0x86e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_871:
	/* 0x871: je     1e <try_preload_arg+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 30ULL;
	}
x86_l_877:
	/* 0x877: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_879:
	/* 0x879: jne    8a2 <try_preload_arg+0x8a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8a2;
	}
x86_l_87b:
	/* 0x87b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_87e:
	/* 0x87e: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_882:
	/* 0x882: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_887:
	/* 0x887: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_88a:
	/* 0x88a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_88c:
	/* 0x88c: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_88f:
	/* 0x88f: call   36c0 <try_preload_arg+0x36c0> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_894:
	/* 0x894: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_896:
	/* 0x896: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_899:
	/* 0x899: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_89b:
	/* 0x89b: jns    8a2 <try_preload_arg+0x8a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_8a2;
	}
x86_l_89d:
	/* 0x89d: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_8a2:
	/* 0x8a2: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8a4:
	/* 0x8a4: jmp    1e <try_preload_arg+0x1e> */
	return 30ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_uprobe_v61_try_preload_arg_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 2024U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1707ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v61_try_preload_arg_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1712ULL && __x86_pc <= 2212ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v61_try_preload_arg_x86_chunk_1(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

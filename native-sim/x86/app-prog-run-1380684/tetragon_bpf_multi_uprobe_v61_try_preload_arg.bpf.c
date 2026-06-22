extern char CONFIG_ITER_NUM;
extern char heap_ro_zero;
extern char sleepable_preload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_multi_uprobe_v61_try_preload_arg_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 4ULL: goto x86_l_4;
	case 6ULL: goto x86_l_6;
	case 9ULL: goto x86_l_9;
	case 12ULL: goto x86_l_c;
	case 17ULL: goto x86_l_11;
	case 22ULL: goto x86_l_16;
	case 24ULL: goto x86_l_18;
	case 26ULL: goto x86_l_1a;
	case 30ULL: goto x86_l_1e;
	case 35ULL: goto x86_l_23;
	case 39ULL: goto x86_l_27;
	case 41ULL: goto x86_l_29;
	case 43ULL: goto x86_l_2b;
	case 51ULL: goto x86_l_33;
	case 56ULL: goto x86_l_38;
	case 59ULL: goto x86_l_3b;
	case 65ULL: goto x86_l_41;
	case 68ULL: goto x86_l_44;
	case 74ULL: goto x86_l_4a;
	case 77ULL: goto x86_l_4d;
	case 83ULL: goto x86_l_53;
	case 86ULL: goto x86_l_56;
	case 92ULL: goto x86_l_5c;
	case 96ULL: goto x86_l_60;
	case 101ULL: goto x86_l_65;
	case 109ULL: goto x86_l_6d;
	case 118ULL: goto x86_l_76;
	case 121ULL: goto x86_l_79;
	case 123ULL: goto x86_l_7b;
	case 125ULL: goto x86_l_7d;
	case 134ULL: goto x86_l_86;
	case 137ULL: goto x86_l_89;
	case 142ULL: goto x86_l_8e;
	case 147ULL: goto x86_l_93;
	case 152ULL: goto x86_l_98;
	case 155ULL: goto x86_l_9b;
	case 161ULL: goto x86_l_a1;
	case 165ULL: goto x86_l_a5;
	case 168ULL: goto x86_l_a8;
	case 175ULL: goto x86_l_af;
	case 181ULL: goto x86_l_b5;
	case 185ULL: goto x86_l_b9;
	case 189ULL: goto x86_l_bd;
	case 194ULL: goto x86_l_c2;
	case 199ULL: goto x86_l_c7;
	case 204ULL: goto x86_l_cc;
	case 209ULL: goto x86_l_d1;
	case 214ULL: goto x86_l_d6;
	case 219ULL: goto x86_l_db;
	case 226ULL: goto x86_l_e2;
	case 229ULL: goto x86_l_e5;
	case 235ULL: goto x86_l_eb;
	case 240ULL: goto x86_l_f0;
	case 246ULL: goto x86_l_f6;
	case 248ULL: goto x86_l_f8;
	case 253ULL: goto x86_l_fd;
	case 258ULL: goto x86_l_102;
	case 260ULL: goto x86_l_104;
	case 265ULL: goto x86_l_109;
	case 270ULL: goto x86_l_10e;
	case 275ULL: goto x86_l_113;
	case 280ULL: goto x86_l_118;
	case 282ULL: goto x86_l_11a;
	case 288ULL: goto x86_l_120;
	case 290ULL: goto x86_l_122;
	case 296ULL: goto x86_l_128;
	case 301ULL: goto x86_l_12d;
	case 307ULL: goto x86_l_133;
	case 310ULL: goto x86_l_136;
	case 315ULL: goto x86_l_13b;
	case 320ULL: goto x86_l_140;
	case 322ULL: goto x86_l_142;
	case 327ULL: goto x86_l_147;
	case 332ULL: goto x86_l_14c;
	case 337ULL: goto x86_l_151;
	case 342ULL: goto x86_l_156;
	case 344ULL: goto x86_l_158;
	case 350ULL: goto x86_l_15e;
	case 352ULL: goto x86_l_160;
	case 358ULL: goto x86_l_166;
	case 363ULL: goto x86_l_16b;
	case 369ULL: goto x86_l_171;
	case 372ULL: goto x86_l_174;
	case 377ULL: goto x86_l_179;
	case 382ULL: goto x86_l_17e;
	case 384ULL: goto x86_l_180;
	case 389ULL: goto x86_l_185;
	case 394ULL: goto x86_l_18a;
	case 399ULL: goto x86_l_18f;
	case 404ULL: goto x86_l_194;
	case 406ULL: goto x86_l_196;
	case 412ULL: goto x86_l_19c;
	case 414ULL: goto x86_l_19e;
	case 420ULL: goto x86_l_1a4;
	case 425ULL: goto x86_l_1a9;
	case 431ULL: goto x86_l_1af;
	case 434ULL: goto x86_l_1b2;
	case 439ULL: goto x86_l_1b7;
	case 444ULL: goto x86_l_1bc;
	case 446ULL: goto x86_l_1be;
	case 451ULL: goto x86_l_1c3;
	case 456ULL: goto x86_l_1c8;
	case 461ULL: goto x86_l_1cd;
	case 466ULL: goto x86_l_1d2;
	case 468ULL: goto x86_l_1d4;
	case 474ULL: goto x86_l_1da;
	case 476ULL: goto x86_l_1dc;
	case 482ULL: goto x86_l_1e2;
	case 487ULL: goto x86_l_1e7;
	case 493ULL: goto x86_l_1ed;
	case 496ULL: goto x86_l_1f0;
	case 501ULL: goto x86_l_1f5;
	case 506ULL: goto x86_l_1fa;
	case 508ULL: goto x86_l_1fc;
	case 513ULL: goto x86_l_201;
	case 518ULL: goto x86_l_206;
	case 523ULL: goto x86_l_20b;
	case 528ULL: goto x86_l_210;
	case 530ULL: goto x86_l_212;
	case 536ULL: goto x86_l_218;
	case 538ULL: goto x86_l_21a;
	case 544ULL: goto x86_l_220;
	case 549ULL: goto x86_l_225;
	case 555ULL: goto x86_l_22b;
	case 558ULL: goto x86_l_22e;
	case 563ULL: goto x86_l_233;
	case 568ULL: goto x86_l_238;
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
	case 632ULL: goto x86_l_278;
	case 637ULL: goto x86_l_27d;
	case 642ULL: goto x86_l_282;
	case 647ULL: goto x86_l_287;
	case 652ULL: goto x86_l_28c;
	case 654ULL: goto x86_l_28e;
	case 660ULL: goto x86_l_294;
	case 662ULL: goto x86_l_296;
	case 668ULL: goto x86_l_29c;
	case 673ULL: goto x86_l_2a1;
	case 679ULL: goto x86_l_2a7;
	case 682ULL: goto x86_l_2aa;
	case 687ULL: goto x86_l_2af;
	case 692ULL: goto x86_l_2b4;
	case 694ULL: goto x86_l_2b6;
	case 699ULL: goto x86_l_2bb;
	case 704ULL: goto x86_l_2c0;
	case 709ULL: goto x86_l_2c5;
	case 715ULL: goto x86_l_2cb;
	case 720ULL: goto x86_l_2d0;
	case 722ULL: goto x86_l_2d2;
	case 724ULL: goto x86_l_2d4;
	case 730ULL: goto x86_l_2da;
	case 735ULL: goto x86_l_2df;
	case 741ULL: goto x86_l_2e5;
	case 744ULL: goto x86_l_2e8;
	case 749ULL: goto x86_l_2ed;
	case 754ULL: goto x86_l_2f2;
	case 756ULL: goto x86_l_2f4;
	case 761ULL: goto x86_l_2f9;
	case 766ULL: goto x86_l_2fe;
	case 771ULL: goto x86_l_303;
	case 776ULL: goto x86_l_308;
	case 778ULL: goto x86_l_30a;
	case 784ULL: goto x86_l_310;
	case 786ULL: goto x86_l_312;
	case 788ULL: goto x86_l_314;
	case 793ULL: goto x86_l_319;
	case 799ULL: goto x86_l_31f;
	case 802ULL: goto x86_l_322;
	case 807ULL: goto x86_l_327;
	case 812ULL: goto x86_l_32c;
	case 818ULL: goto x86_l_332;
	case 823ULL: goto x86_l_337;
	case 828ULL: goto x86_l_33c;
	case 833ULL: goto x86_l_341;
	case 838ULL: goto x86_l_346;
	case 840ULL: goto x86_l_348;
	case 846ULL: goto x86_l_34e;
	case 848ULL: goto x86_l_350;
	case 854ULL: goto x86_l_356;
	case 859ULL: goto x86_l_35b;
	case 864ULL: goto x86_l_360;
	case 866ULL: goto x86_l_362;
	case 868ULL: goto x86_l_364;
	case 871ULL: goto x86_l_367;
	case 873ULL: goto x86_l_369;
	case 877ULL: goto x86_l_36d;
	case 879ULL: goto x86_l_36f;
	case 883ULL: goto x86_l_373;
	case 885ULL: goto x86_l_375;
	case 889ULL: goto x86_l_379;
	case 891ULL: goto x86_l_37b;
	case 895ULL: goto x86_l_37f;
	case 900ULL: goto x86_l_384;
	case 903ULL: goto x86_l_387;
	case 909ULL: goto x86_l_38d;
	case 913ULL: goto x86_l_391;
	case 916ULL: goto x86_l_394;
	case 923ULL: goto x86_l_39b;
	case 929ULL: goto x86_l_3a1;
	case 933ULL: goto x86_l_3a5;
	case 937ULL: goto x86_l_3a9;
	case 942ULL: goto x86_l_3ae;
	case 947ULL: goto x86_l_3b3;
	case 952ULL: goto x86_l_3b8;
	case 957ULL: goto x86_l_3bd;
	case 962ULL: goto x86_l_3c2;
	case 967ULL: goto x86_l_3c7;
	case 974ULL: goto x86_l_3ce;
	case 977ULL: goto x86_l_3d1;
	case 983ULL: goto x86_l_3d7;
	case 989ULL: goto x86_l_3dd;
	case 995ULL: goto x86_l_3e3;
	case 998ULL: goto x86_l_3e6;
	case 1003ULL: goto x86_l_3eb;
	case 1009ULL: goto x86_l_3f1;
	case 1011ULL: goto x86_l_3f3;
	case 1016ULL: goto x86_l_3f8;
	case 1021ULL: goto x86_l_3fd;
	case 1026ULL: goto x86_l_402;
	case 1031ULL: goto x86_l_407;
	case 1033ULL: goto x86_l_409;
	case 1039ULL: goto x86_l_40f;
	case 1041ULL: goto x86_l_411;
	case 1047ULL: goto x86_l_417;
	case 1053ULL: goto x86_l_41d;
	case 1059ULL: goto x86_l_423;
	case 1063ULL: goto x86_l_427;
	case 1068ULL: goto x86_l_42c;
	case 1074ULL: goto x86_l_432;
	case 1076ULL: goto x86_l_434;
	case 1081ULL: goto x86_l_439;
	case 1086ULL: goto x86_l_43e;
	case 1091ULL: goto x86_l_443;
	case 1096ULL: goto x86_l_448;
	case 1098ULL: goto x86_l_44a;
	case 1104ULL: goto x86_l_450;
	case 1106ULL: goto x86_l_452;
	case 1112ULL: goto x86_l_458;
	case 1118ULL: goto x86_l_45e;
	case 1124ULL: goto x86_l_464;
	case 1128ULL: goto x86_l_468;
	case 1133ULL: goto x86_l_46d;
	case 1139ULL: goto x86_l_473;
	case 1141ULL: goto x86_l_475;
	case 1146ULL: goto x86_l_47a;
	case 1151ULL: goto x86_l_47f;
	case 1156ULL: goto x86_l_484;
	case 1161ULL: goto x86_l_489;
	case 1163ULL: goto x86_l_48b;
	case 1169ULL: goto x86_l_491;
	case 1171ULL: goto x86_l_493;
	case 1177ULL: goto x86_l_499;
	case 1183ULL: goto x86_l_49f;
	case 1189ULL: goto x86_l_4a5;
	case 1193ULL: goto x86_l_4a9;
	case 1198ULL: goto x86_l_4ae;
	case 1204ULL: goto x86_l_4b4;
	case 1206ULL: goto x86_l_4b6;
	case 1211ULL: goto x86_l_4bb;
	case 1216ULL: goto x86_l_4c0;
	case 1221ULL: goto x86_l_4c5;
	case 1226ULL: goto x86_l_4ca;
	case 1228ULL: goto x86_l_4cc;
	case 1234ULL: goto x86_l_4d2;
	case 1236ULL: goto x86_l_4d4;
	case 1242ULL: goto x86_l_4da;
	case 1248ULL: goto x86_l_4e0;
	case 1254ULL: goto x86_l_4e6;
	case 1258ULL: goto x86_l_4ea;
	case 1263ULL: goto x86_l_4ef;
	case 1269ULL: goto x86_l_4f5;
	case 1271ULL: goto x86_l_4f7;
	case 1276ULL: goto x86_l_4fc;
	case 1281ULL: goto x86_l_501;
	case 1286ULL: goto x86_l_506;
	case 1291ULL: goto x86_l_50b;
	case 1293ULL: goto x86_l_50d;
	case 1299ULL: goto x86_l_513;
	case 1301ULL: goto x86_l_515;
	case 1307ULL: goto x86_l_51b;
	case 1313ULL: goto x86_l_521;
	case 1319ULL: goto x86_l_527;
	case 1323ULL: goto x86_l_52b;
	case 1328ULL: goto x86_l_530;
	case 1334ULL: goto x86_l_536;
	case 1336ULL: goto x86_l_538;
	case 1341ULL: goto x86_l_53d;
	case 1346ULL: goto x86_l_542;
	case 1351ULL: goto x86_l_547;
	case 1356ULL: goto x86_l_54c;
	case 1358ULL: goto x86_l_54e;
	case 1364ULL: goto x86_l_554;
	case 1366ULL: goto x86_l_556;
	case 1372ULL: goto x86_l_55c;
	case 1378ULL: goto x86_l_562;
	case 1384ULL: goto x86_l_568;
	case 1388ULL: goto x86_l_56c;
	case 1393ULL: goto x86_l_571;
	case 1399ULL: goto x86_l_577;
	case 1401ULL: goto x86_l_579;
	case 1406ULL: goto x86_l_57e;
	case 1411ULL: goto x86_l_583;
	case 1416ULL: goto x86_l_588;
	case 1421ULL: goto x86_l_58d;
	case 1423ULL: goto x86_l_58f;
	case 1429ULL: goto x86_l_595;
	case 1431ULL: goto x86_l_597;
	case 1437ULL: goto x86_l_59d;
	case 1443ULL: goto x86_l_5a3;
	case 1449ULL: goto x86_l_5a9;
	case 1453ULL: goto x86_l_5ad;
	case 1458ULL: goto x86_l_5b2;
	case 1464ULL: goto x86_l_5b8;
	case 1466ULL: goto x86_l_5ba;
	case 1471ULL: goto x86_l_5bf;
	case 1476ULL: goto x86_l_5c4;
	case 1481ULL: goto x86_l_5c9;
	case 1487ULL: goto x86_l_5cf;
	case 1492ULL: goto x86_l_5d4;
	case 1494ULL: goto x86_l_5d6;
	case 1496ULL: goto x86_l_5d8;
	case 1502ULL: goto x86_l_5de;
	case 1508ULL: goto x86_l_5e4;
	case 1514ULL: goto x86_l_5ea;
	case 1518ULL: goto x86_l_5ee;
	case 1523ULL: goto x86_l_5f3;
	case 1529ULL: goto x86_l_5f9;
	case 1531ULL: goto x86_l_5fb;
	case 1536ULL: goto x86_l_600;
	case 1541ULL: goto x86_l_605;
	case 1546ULL: goto x86_l_60a;
	case 1551ULL: goto x86_l_60f;
	case 1553ULL: goto x86_l_611;
	case 1559ULL: goto x86_l_617;
	case 1561ULL: goto x86_l_619;
	case 1563ULL: goto x86_l_61b;
	case 1569ULL: goto x86_l_621;
	case 1575ULL: goto x86_l_627;
	case 1579ULL: goto x86_l_62b;
	case 1584ULL: goto x86_l_630;
	case 1590ULL: goto x86_l_636;
	case 1596ULL: goto x86_l_63c;
	case 1601ULL: goto x86_l_641;
	case 1606ULL: goto x86_l_646;
	case 1611ULL: goto x86_l_64b;
	case 1616ULL: goto x86_l_650;
	case 1618ULL: goto x86_l_652;
	case 1624ULL: goto x86_l_658;
	case 1626ULL: goto x86_l_65a;
	case 1632ULL: goto x86_l_660;
	case 1637ULL: goto x86_l_665;
	case 1642ULL: goto x86_l_66a;
	case 1647ULL: goto x86_l_66f;
	case 1654ULL: goto x86_l_676;
	case 1659ULL: goto x86_l_67b;
	case 1664ULL: goto x86_l_680;
	case 1666ULL: goto x86_l_682;
	case 1668ULL: goto x86_l_684;
	case 1672ULL: goto x86_l_688;
	case 1678ULL: goto x86_l_68e;
	case 1683ULL: goto x86_l_693;
	case 1688ULL: goto x86_l_698;
	case 1693ULL: goto x86_l_69d;
	case 1695ULL: goto x86_l_69f;
	case 1700ULL: goto x86_l_6a4;
	case 1708ULL: goto x86_l_6ac;
	case 1713ULL: goto x86_l_6b1;
	case 1720ULL: goto x86_l_6b8;
	case 1725ULL: goto x86_l_6bd;
	case 1727ULL: goto x86_l_6bf;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: sub    rsp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 56ULL);
x86_l_4:
	/* 0x4: mov    ebx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_32);
x86_l_6:
	/* 0x6: and    ebx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_9:
	/* 0x9: mov    r14,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c:
	/* 0xc: mov    eax,DWORD PTR [r14+rbx*4+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 24ULL);
x86_l_11:
	/* 0x11: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_16:
	/* 0x16: jne    23 <try_preload_arg+0x23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23;
	}
x86_l_18:
	/* 0x18: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a:
	/* 0x1a: add    rsp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_1e:
	/* 0x1e: jmp    7d3 <try_preload_arg+0x7d3> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_23:
	/* 0x23: mov    rdi,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27:
	/* 0x27: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_29:
	/* 0x29: js     65 <try_preload_arg+0x65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_65;
	}
x86_l_2b:
	/* 0x2b: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_33:
	/* 0x33: mov    eax,DWORD PTR [r14+rbx*4+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 64ULL);
x86_l_38:
	/* 0x38: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3b:
	/* 0x3b: jle    360 <try_preload_arg+0x360> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_360;
	}
x86_l_41:
	/* 0x41: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_44:
	/* 0x44: je     36f <try_preload_arg+0x36f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36f;
	}
x86_l_4a:
	/* 0x4a: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_4d:
	/* 0x4d: je     375 <try_preload_arg+0x375> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_375;
	}
x86_l_53:
	/* 0x53: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_56:
	/* 0x56: jne    384 <try_preload_arg+0x384> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_384;
	}
x86_l_5c:
	/* 0x5c: mov    rax,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_60:
	/* 0x60: jmp    37f <try_preload_arg+0x37f> */
	goto x86_l_37f;
x86_l_65:
	/* 0x65: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_6d:
	/* 0x6d: movzx  eax,BYTE PTR [r14+rbx*4+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBX, 2, X86_WIDTH_8), 706ULL);
x86_l_76:
	/* 0x76: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_79:
	/* 0x79: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_7b:
	/* 0x7b: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_7d:
	/* 0x7d: movzx  esi,WORD PTR [r14+rbx*4+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBX, 2, X86_WIDTH_16), 704ULL);
x86_l_86:
	/* 0x86: movzx  edx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_89:
	/* 0x89: call   0 <try_preload_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 142ULL);
	__x86_sim_call_depth++;
	goto x86_l_0;
x86_l_8e:
	/* 0x8e: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_93:
	/* 0x93: mov    r13d,DWORD PTR [r14+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_98:
	/* 0x98: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_9b:
	/* 0x9b: ja     684 <try_preload_arg+0x684> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_684;
	}
x86_l_a1:
	/* 0xa1: lea    rax,[rbx+rbx*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 2), 0ULL);
x86_l_a5:
	/* 0xa5: shl    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_a8:
	/* 0xa8: cmp    WORD PTR [r14+rax*1+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 506806140928ULL);
x86_l_af:
	/* 0xaf: je     684 <try_preload_arg+0x684> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_684;
	}
x86_l_b5:
	/* 0xb5: lea    rbx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_b9:
	/* 0xb9: add    rbx,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_bd:
	/* 0xbd: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c2:
	/* 0xc2: lea    rax,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c7:
	/* 0xc7: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cc:
	/* 0xcc: mov    BYTE PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_d1:
	/* 0xd1: lea    rax,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d6:
	/* 0xd6: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_db:
	/* 0xdb: mov    rax,QWORD PTR [rip+0x2da8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_e2:
	/* 0xe2: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e5:
	/* 0xe5: je     66a <try_preload_arg+0x66a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_66a;
	}
x86_l_eb:
	/* 0xeb: cmp    WORD PTR [rbx+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 25769803776ULL);
x86_l_f0:
	/* 0xf0: je     684 <try_preload_arg+0x684> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_684;
	}
x86_l_f6:
	/* 0xf6: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f8:
	/* 0xf8: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_fd:
	/* 0xfd: cmp    WORD PTR [rbx+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_102:
	/* 0x102: je     128 <try_preload_arg+0x128> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_128;
	}
x86_l_104:
	/* 0x104: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_109:
	/* 0x109: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10e:
	/* 0x10e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_113:
	/* 0x113: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_118:
	/* 0x118: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11a:
	/* 0x11a: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_120:
	/* 0x120: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_122:
	/* 0x122: js     356 <try_preload_arg+0x356> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_356;
	}
x86_l_128:
	/* 0x128: cmp    WORD PTR [rbx+0xe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_12d:
	/* 0x12d: je     684 <try_preload_arg+0x684> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_684;
	}
x86_l_133:
	/* 0x133: mov    eax,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_136:
	/* 0x136: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_13b:
	/* 0x13b: cmp    WORD PTR [rbx+0xc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_140:
	/* 0x140: je     166 <try_preload_arg+0x166> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_166;
	}
x86_l_142:
	/* 0x142: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_147:
	/* 0x147: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14c:
	/* 0x14c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_151:
	/* 0x151: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_156:
	/* 0x156: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_158:
	/* 0x158: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_15e:
	/* 0x15e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_160:
	/* 0x160: js     356 <try_preload_arg+0x356> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_356;
	}
x86_l_166:
	/* 0x166: cmp    WORD PTR [rbx+0x16],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94489280512ULL);
x86_l_16b:
	/* 0x16b: je     684 <try_preload_arg+0x684> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_684;
	}
x86_l_171:
	/* 0x171: mov    eax,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_174:
	/* 0x174: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_179:
	/* 0x179: cmp    WORD PTR [rbx+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_17e:
	/* 0x17e: je     1a4 <try_preload_arg+0x1a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a4;
	}
x86_l_180:
	/* 0x180: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_185:
	/* 0x185: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18a:
	/* 0x18a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18f:
	/* 0x18f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_194:
	/* 0x194: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_196:
	/* 0x196: mov    r14d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 3ULL);
x86_l_19c:
	/* 0x19c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19e:
	/* 0x19e: js     356 <try_preload_arg+0x356> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_356;
	}
x86_l_1a4:
	/* 0x1a4: cmp    WORD PTR [rbx+0x1e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128849018880ULL);
x86_l_1a9:
	/* 0x1a9: je     684 <try_preload_arg+0x684> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_684;
	}
x86_l_1af:
	/* 0x1af: mov    eax,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b2:
	/* 0x1b2: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1b7:
	/* 0x1b7: cmp    WORD PTR [rbx+0x1c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_1bc:
	/* 0x1bc: je     1e2 <try_preload_arg+0x1e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e2;
	}
x86_l_1be:
	/* 0x1be: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1c3:
	/* 0x1c3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c8:
	/* 0x1c8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cd:
	/* 0x1cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d2:
	/* 0x1d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d4:
	/* 0x1d4: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_1da:
	/* 0x1da: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1dc:
	/* 0x1dc: js     356 <try_preload_arg+0x356> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_356;
	}
x86_l_1e2:
	/* 0x1e2: cmp    WORD PTR [rbx+0x26],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_1e7:
	/* 0x1e7: je     684 <try_preload_arg+0x684> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_684;
	}
x86_l_1ed:
	/* 0x1ed: mov    eax,DWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f0:
	/* 0x1f0: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1f5:
	/* 0x1f5: cmp    WORD PTR [rbx+0x24],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1fa:
	/* 0x1fa: je     220 <try_preload_arg+0x220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_220;
	}
x86_l_1fc:
	/* 0x1fc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_201:
	/* 0x201: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_206:
	/* 0x206: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20b:
	/* 0x20b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_210:
	/* 0x210: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_212:
	/* 0x212: mov    r14d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 5ULL);
x86_l_218:
	/* 0x218: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21a:
	/* 0x21a: js     356 <try_preload_arg+0x356> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_356;
	}
x86_l_220:
	/* 0x220: cmp    WORD PTR [rbx+0x2e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 197568495616ULL);
x86_l_225:
	/* 0x225: je     684 <try_preload_arg+0x684> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_684;
	}
x86_l_22b:
	/* 0x22b: mov    eax,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22e:
	/* 0x22e: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_233:
	/* 0x233: cmp    WORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_238:
	/* 0x238: je     25e <try_preload_arg+0x25e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e;
	}
x86_l_23a:
	/* 0x23a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_23f:
	/* 0x23f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_244:
	/* 0x244: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_249:
	/* 0x249: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24e:
	/* 0x24e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_250:
	/* 0x250: mov    r14d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 6ULL);
x86_l_256:
	/* 0x256: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_258:
	/* 0x258: js     356 <try_preload_arg+0x356> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_356;
	}
x86_l_25e:
	/* 0x25e: cmp    WORD PTR [rbx+0x36],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 231928233984ULL);
x86_l_263:
	/* 0x263: je     684 <try_preload_arg+0x684> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_684;
	}
x86_l_269:
	/* 0x269: mov    eax,DWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26c:
	/* 0x26c: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_271:
	/* 0x271: cmp    WORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_276:
	/* 0x276: je     29c <try_preload_arg+0x29c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29c;
	}
x86_l_278:
	/* 0x278: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_27d:
	/* 0x27d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_282:
	/* 0x282: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_287:
	/* 0x287: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28c:
	/* 0x28c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28e:
	/* 0x28e: mov    r14d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 7ULL);
x86_l_294:
	/* 0x294: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_296:
	/* 0x296: js     356 <try_preload_arg+0x356> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_356;
	}
x86_l_29c:
	/* 0x29c: cmp    WORD PTR [rbx+0x3e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 266287972352ULL);
x86_l_2a1:
	/* 0x2a1: je     684 <try_preload_arg+0x684> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_684;
	}
x86_l_2a7:
	/* 0x2a7: mov    eax,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2aa:
	/* 0x2aa: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2af:
	/* 0x2af: cmp    WORD PTR [rbx+0x3c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_2b4:
	/* 0x2b4: je     2da <try_preload_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2da;
	}
x86_l_2b6:
	/* 0x2b6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2bb:
	/* 0x2bb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c0:
	/* 0x2c0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c5:
	/* 0x2c5: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_2cb:
	/* 0x2cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d0:
	/* 0x2d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d2:
	/* 0x2d2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d4:
	/* 0x2d4: js     356 <try_preload_arg+0x356> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_356;
	}
x86_l_2da:
	/* 0x2da: cmp    WORD PTR [rbx+0x46],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 300647710720ULL);
x86_l_2df:
	/* 0x2df: je     684 <try_preload_arg+0x684> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_684;
	}
x86_l_2e5:
	/* 0x2e5: mov    eax,DWORD PTR [rbx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e8:
	/* 0x2e8: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2ed:
	/* 0x2ed: cmp    WORD PTR [rbx+0x44],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_2f2:
	/* 0x2f2: je     314 <try_preload_arg+0x314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_314;
	}
x86_l_2f4:
	/* 0x2f4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2f9:
	/* 0x2f9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fe:
	/* 0x2fe: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_303:
	/* 0x303: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_308:
	/* 0x308: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30a:
	/* 0x30a: mov    r14d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 9ULL);
x86_l_310:
	/* 0x310: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_312:
	/* 0x312: js     356 <try_preload_arg+0x356> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_356;
	}
x86_l_314:
	/* 0x314: cmp    WORD PTR [rbx+0x4e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 335007449088ULL);
x86_l_319:
	/* 0x319: je     684 <try_preload_arg+0x684> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_684;
	}
x86_l_31f:
	/* 0x31f: mov    eax,DWORD PTR [rbx+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_322:
	/* 0x322: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_327:
	/* 0x327: cmp    WORD PTR [rbx+0x4c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 326417514496ULL);
x86_l_32c:
	/* 0x32c: je     684 <try_preload_arg+0x684> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_684;
	}
x86_l_332:
	/* 0x332: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_337:
	/* 0x337: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33c:
	/* 0x33c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_341:
	/* 0x341: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_346:
	/* 0x346: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_348:
	/* 0x348: mov    r14d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 10ULL);
x86_l_34e:
	/* 0x34e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_350:
	/* 0x350: jns    684 <try_preload_arg+0x684> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_684;
	}
x86_l_356:
	/* 0x356: mov    DWORD PTR [rsp+0x10],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35b:
	/* 0x35b: jmp    684 <try_preload_arg+0x684> */
	goto x86_l_684;
x86_l_360:
	/* 0x360: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_362:
	/* 0x362: je     37b <try_preload_arg+0x37b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37b;
	}
x86_l_364:
	/* 0x364: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_367:
	/* 0x367: jne    384 <try_preload_arg+0x384> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_384;
	}
x86_l_369:
	/* 0x369: mov    rax,QWORD PTR [rdi+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_36d:
	/* 0x36d: jmp    37f <try_preload_arg+0x37f> */
	goto x86_l_37f;
x86_l_36f:
	/* 0x36f: mov    rax,QWORD PTR [rdi+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_373:
	/* 0x373: jmp    37f <try_preload_arg+0x37f> */
	goto x86_l_37f;
x86_l_375:
	/* 0x375: mov    rax,QWORD PTR [rdi+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_379:
	/* 0x379: jmp    37f <try_preload_arg+0x37f> */
	goto x86_l_37f;
x86_l_37b:
	/* 0x37b: mov    rax,QWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_37f:
	/* 0x37f: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_384:
	/* 0x384: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_387:
	/* 0x387: ja     70c <try_preload_arg+0x70c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1804ULL;
	}
x86_l_38d:
	/* 0x38d: lea    rax,[rbx+rbx*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 2), 0ULL);
x86_l_391:
	/* 0x391: shl    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_394:
	/* 0x394: cmp    WORD PTR [r14+rax*1+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 506806140928ULL);
x86_l_39b:
	/* 0x39b: je     70c <try_preload_arg+0x70c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1804ULL;
	}
x86_l_3a1:
	/* 0x3a1: lea    r15,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3a5:
	/* 0x3a5: add    r15,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_3a9:
	/* 0x3a9: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ae:
	/* 0x3ae: lea    rax,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b3:
	/* 0x3b3: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3b8:
	/* 0x3b8: mov    BYTE PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_3bd:
	/* 0x3bd: lea    rax,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c2:
	/* 0x3c2: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c7:
	/* 0x3c7: mov    rax,QWORD PTR [rip+0x2da4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_3ce:
	/* 0x3ce: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d1:
	/* 0x3d1: je     6f2 <try_preload_arg+0x6f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1778ULL;
	}
x86_l_3d7:
	/* 0x3d7: cmp    WORD PTR [r15+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 25769803776ULL);
x86_l_3dd:
	/* 0x3dd: je     70c <try_preload_arg+0x70c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1804ULL;
	}
x86_l_3e3:
	/* 0x3e3: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e6:
	/* 0x3e6: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3eb:
	/* 0x3eb: cmp    WORD PTR [r15+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3f1:
	/* 0x3f1: je     417 <try_preload_arg+0x417> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_417;
	}
x86_l_3f3:
	/* 0x3f3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3f8:
	/* 0x3f8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fd:
	/* 0x3fd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_402:
	/* 0x402: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_407:
	/* 0x407: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_409:
	/* 0x409: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_40f:
	/* 0x40f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_411:
	/* 0x411: js     660 <try_preload_arg+0x660> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_660;
	}
x86_l_417:
	/* 0x417: cmp    WORD PTR [r15+0xe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_41d:
	/* 0x41d: je     70c <try_preload_arg+0x70c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1804ULL;
	}
x86_l_423:
	/* 0x423: mov    eax,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_427:
	/* 0x427: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_42c:
	/* 0x42c: cmp    WORD PTR [r15+0xc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_432:
	/* 0x432: je     458 <try_preload_arg+0x458> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_458;
	}
x86_l_434:
	/* 0x434: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_439:
	/* 0x439: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43e:
	/* 0x43e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_443:
	/* 0x443: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_448:
	/* 0x448: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44a:
	/* 0x44a: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_450:
	/* 0x450: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_452:
	/* 0x452: js     660 <try_preload_arg+0x660> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_660;
	}
x86_l_458:
	/* 0x458: cmp    WORD PTR [r15+0x16],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94489280512ULL);
x86_l_45e:
	/* 0x45e: je     70c <try_preload_arg+0x70c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1804ULL;
	}
x86_l_464:
	/* 0x464: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_468:
	/* 0x468: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_46d:
	/* 0x46d: cmp    WORD PTR [r15+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_473:
	/* 0x473: je     499 <try_preload_arg+0x499> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_499;
	}
x86_l_475:
	/* 0x475: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47a:
	/* 0x47a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47f:
	/* 0x47f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_484:
	/* 0x484: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_489:
	/* 0x489: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48b:
	/* 0x48b: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_491:
	/* 0x491: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_493:
	/* 0x493: js     660 <try_preload_arg+0x660> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_660;
	}
x86_l_499:
	/* 0x499: cmp    WORD PTR [r15+0x1e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128849018880ULL);
x86_l_49f:
	/* 0x49f: je     70c <try_preload_arg+0x70c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1804ULL;
	}
x86_l_4a5:
	/* 0x4a5: mov    eax,DWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a9:
	/* 0x4a9: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4ae:
	/* 0x4ae: cmp    WORD PTR [r15+0x1c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_4b4:
	/* 0x4b4: je     4da <try_preload_arg+0x4da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4da;
	}
x86_l_4b6:
	/* 0x4b6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4bb:
	/* 0x4bb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c0:
	/* 0x4c0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c5:
	/* 0x4c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ca:
	/* 0x4ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cc:
	/* 0x4cc: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_4d2:
	/* 0x4d2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d4:
	/* 0x4d4: js     660 <try_preload_arg+0x660> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_660;
	}
x86_l_4da:
	/* 0x4da: cmp    WORD PTR [r15+0x26],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_4e0:
	/* 0x4e0: je     70c <try_preload_arg+0x70c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1804ULL;
	}
x86_l_4e6:
	/* 0x4e6: mov    eax,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ea:
	/* 0x4ea: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4ef:
	/* 0x4ef: cmp    WORD PTR [r15+0x24],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_4f5:
	/* 0x4f5: je     51b <try_preload_arg+0x51b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_51b;
	}
x86_l_4f7:
	/* 0x4f7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4fc:
	/* 0x4fc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_501:
	/* 0x501: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_506:
	/* 0x506: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50b:
	/* 0x50b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50d:
	/* 0x50d: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_513:
	/* 0x513: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_515:
	/* 0x515: js     660 <try_preload_arg+0x660> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_660;
	}
x86_l_51b:
	/* 0x51b: cmp    WORD PTR [r15+0x2e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 197568495616ULL);
x86_l_521:
	/* 0x521: je     70c <try_preload_arg+0x70c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1804ULL;
	}
x86_l_527:
	/* 0x527: mov    eax,DWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_52b:
	/* 0x52b: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_530:
	/* 0x530: cmp    WORD PTR [r15+0x2c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_536:
	/* 0x536: je     55c <try_preload_arg+0x55c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_55c;
	}
x86_l_538:
	/* 0x538: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_53d:
	/* 0x53d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_542:
	/* 0x542: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_547:
	/* 0x547: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54c:
	/* 0x54c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54e:
	/* 0x54e: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_554:
	/* 0x554: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_556:
	/* 0x556: js     660 <try_preload_arg+0x660> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_660;
	}
x86_l_55c:
	/* 0x55c: cmp    WORD PTR [r15+0x36],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 231928233984ULL);
x86_l_562:
	/* 0x562: je     70c <try_preload_arg+0x70c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1804ULL;
	}
x86_l_568:
	/* 0x568: mov    eax,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_56c:
	/* 0x56c: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_571:
	/* 0x571: cmp    WORD PTR [r15+0x34],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_577:
	/* 0x577: je     59d <try_preload_arg+0x59d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59d;
	}
x86_l_579:
	/* 0x579: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_57e:
	/* 0x57e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_583:
	/* 0x583: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_588:
	/* 0x588: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58d:
	/* 0x58d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58f:
	/* 0x58f: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_595:
	/* 0x595: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_597:
	/* 0x597: js     660 <try_preload_arg+0x660> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_660;
	}
x86_l_59d:
	/* 0x59d: cmp    WORD PTR [r15+0x3e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 266287972352ULL);
x86_l_5a3:
	/* 0x5a3: je     70c <try_preload_arg+0x70c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1804ULL;
	}
x86_l_5a9:
	/* 0x5a9: mov    eax,DWORD PTR [r15+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5ad:
	/* 0x5ad: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5b2:
	/* 0x5b2: cmp    WORD PTR [r15+0x3c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_5b8:
	/* 0x5b8: je     5de <try_preload_arg+0x5de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5de;
	}
x86_l_5ba:
	/* 0x5ba: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5bf:
	/* 0x5bf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c4:
	/* 0x5c4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c9:
	/* 0x5c9: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_5cf:
	/* 0x5cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d4:
	/* 0x5d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d6:
	/* 0x5d6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5d8:
	/* 0x5d8: js     660 <try_preload_arg+0x660> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_660;
	}
x86_l_5de:
	/* 0x5de: cmp    WORD PTR [r15+0x46],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 300647710720ULL);
x86_l_5e4:
	/* 0x5e4: je     70c <try_preload_arg+0x70c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1804ULL;
	}
x86_l_5ea:
	/* 0x5ea: mov    eax,DWORD PTR [r15+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5ee:
	/* 0x5ee: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5f3:
	/* 0x5f3: cmp    WORD PTR [r15+0x44],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_5f9:
	/* 0x5f9: je     61b <try_preload_arg+0x61b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61b;
	}
x86_l_5fb:
	/* 0x5fb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_600:
	/* 0x600: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_605:
	/* 0x605: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60a:
	/* 0x60a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_60f:
	/* 0x60f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_611:
	/* 0x611: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_617:
	/* 0x617: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_619:
	/* 0x619: js     660 <try_preload_arg+0x660> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_660;
	}
x86_l_61b:
	/* 0x61b: cmp    WORD PTR [r15+0x4e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 335007449088ULL);
x86_l_621:
	/* 0x621: je     70c <try_preload_arg+0x70c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1804ULL;
	}
x86_l_627:
	/* 0x627: mov    eax,DWORD PTR [r15+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_62b:
	/* 0x62b: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_630:
	/* 0x630: cmp    WORD PTR [r15+0x4c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 326417514496ULL);
x86_l_636:
	/* 0x636: je     70c <try_preload_arg+0x70c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1804ULL;
	}
x86_l_63c:
	/* 0x63c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_641:
	/* 0x641: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_646:
	/* 0x646: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_64b:
	/* 0x64b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_650:
	/* 0x650: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_652:
	/* 0x652: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_658:
	/* 0x658: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_65a:
	/* 0x65a: jns    70c <try_preload_arg+0x70c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 1804ULL;
	}
x86_l_660:
	/* 0x660: mov    DWORD PTR [rsp+0x10],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_665:
	/* 0x665: jmp    70c <try_preload_arg+0x70c> */
	return 1804ULL;
x86_l_66a:
	/* 0x66a: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_66f:
	/* 0x66f: lea    rsi,[rip+0xfffffffffffffaa2] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 18446744073709550242ULL);
x86_l_676:
	/* 0x676: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_67b:
	/* 0x67b: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_680:
	/* 0x680: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_682:
	/* 0x682: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_684:
	/* 0x684: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_688:
	/* 0x688: jne    18 <try_preload_arg+0x18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18;
	}
x86_l_68e:
	/* 0x68e: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_693:
	/* 0x693: mov    r13d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_698:
	/* 0x698: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_69d:
	/* 0x69d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69f:
	/* 0x69f: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6a4:
	/* 0x6a4: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_6ac:
	/* 0x6ac: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6b1:
	/* 0x6b1: mov    rdi,QWORD PTR [rip+0x2d97] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_6b8:
	/* 0x6b8: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6bd:
	/* 0x6bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6bf:
	/* 0x6bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
	return 1730ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v61_try_preload_arg_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1730ULL: goto x86_l_6c2;
	case 1736ULL: goto x86_l_6c8;
	case 1742ULL: goto x86_l_6ce;
	case 1749ULL: goto x86_l_6d5;
	case 1754ULL: goto x86_l_6da;
	case 1757ULL: goto x86_l_6dd;
	case 1760ULL: goto x86_l_6e0;
	case 1763ULL: goto x86_l_6e3;
	case 1765ULL: goto x86_l_6e5;
	case 1768ULL: goto x86_l_6e8;
	case 1773ULL: goto x86_l_6ed;
	case 1778ULL: goto x86_l_6f2;
	case 1783ULL: goto x86_l_6f7;
	case 1790ULL: goto x86_l_6fe;
	case 1795ULL: goto x86_l_703;
	case 1800ULL: goto x86_l_708;
	case 1802ULL: goto x86_l_70a;
	case 1804ULL: goto x86_l_70c;
	case 1809ULL: goto x86_l_711;
	case 1814ULL: goto x86_l_716;
	case 1819ULL: goto x86_l_71b;
	case 1824ULL: goto x86_l_720;
	case 1827ULL: goto x86_l_723;
	case 1829ULL: goto x86_l_725;
	case 1832ULL: goto x86_l_728;
	case 1838ULL: goto x86_l_72e;
	case 1843ULL: goto x86_l_733;
	case 1848ULL: goto x86_l_738;
	case 1853ULL: goto x86_l_73d;
	case 1855ULL: goto x86_l_73f;
	case 1860ULL: goto x86_l_744;
	case 1868ULL: goto x86_l_74c;
	case 1873ULL: goto x86_l_751;
	case 1880ULL: goto x86_l_758;
	case 1885ULL: goto x86_l_75d;
	case 1887ULL: goto x86_l_75f;
	case 1890ULL: goto x86_l_762;
	case 1896ULL: goto x86_l_768;
	case 1902ULL: goto x86_l_76e;
	case 1909ULL: goto x86_l_775;
	case 1914ULL: goto x86_l_77a;
	case 1917ULL: goto x86_l_77d;
	case 1920ULL: goto x86_l_780;
	case 1923ULL: goto x86_l_783;
	case 1925ULL: goto x86_l_785;
	case 1928ULL: goto x86_l_788;
	case 1933ULL: goto x86_l_78d;
	case 1936ULL: goto x86_l_790;
	case 1939ULL: goto x86_l_793;
	case 1941ULL: goto x86_l_795;
	case 1944ULL: goto x86_l_798;
	case 1950ULL: goto x86_l_79e;
	case 1953ULL: goto x86_l_7a1;
	case 1955ULL: goto x86_l_7a3;
	case 1958ULL: goto x86_l_7a6;
	case 1962ULL: goto x86_l_7aa;
	case 1967ULL: goto x86_l_7af;
	case 1970ULL: goto x86_l_7b2;
	case 1972ULL: goto x86_l_7b4;
	case 1975ULL: goto x86_l_7b7;
	case 1980ULL: goto x86_l_7bc;
	case 1982ULL: goto x86_l_7be;
	case 1985ULL: goto x86_l_7c1;
	case 1987ULL: goto x86_l_7c3;
	case 1989ULL: goto x86_l_7c5;
	case 1995ULL: goto x86_l_7cb;
	case 1998ULL: goto x86_l_7ce;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6c2:
	/* 0x6c2: je     18 <try_preload_arg+0x18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24ULL;
	}
x86_l_6c8:
	/* 0x6c8: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_6ce:
	/* 0x6ce: mov    r14,QWORD PTR [rip+0x2d97] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_6d5:
	/* 0x6d5: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6da:
	/* 0x6da: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_6dd:
	/* 0x6dd: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_6e0:
	/* 0x6e0: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6e3:
	/* 0x6e3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6e5:
	/* 0x6e5: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6e8:
	/* 0x6e8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6ed:
	/* 0x6ed: jmp    78d <try_preload_arg+0x78d> */
	goto x86_l_78d;
x86_l_6f2:
	/* 0x6f2: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_6f7:
	/* 0x6f7: lea    rsi,[rip+0xfffffffffffffa1a] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 18446744073709550106ULL);
x86_l_6fe:
	/* 0x6fe: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_703:
	/* 0x703: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_708:
	/* 0x708: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_70a:
	/* 0x70a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_70c:
	/* 0x70c: mov    ebx,DWORD PTR [r14+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_711:
	/* 0x711: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_716:
	/* 0x716: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_71b:
	/* 0x71b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_720:
	/* 0x720: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_723:
	/* 0x723: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_725:
	/* 0x725: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_728:
	/* 0x728: jne    18 <try_preload_arg+0x18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24ULL;
	}
x86_l_72e:
	/* 0x72e: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_733:
	/* 0x733: mov    r13d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_738:
	/* 0x738: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_73d:
	/* 0x73d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_73f:
	/* 0x73f: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_744:
	/* 0x744: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_74c:
	/* 0x74c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_751:
	/* 0x751: mov    rdi,QWORD PTR [rip+0x2d96] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_758:
	/* 0x758: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_75d:
	/* 0x75d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_75f:
	/* 0x75f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_762:
	/* 0x762: je     18 <try_preload_arg+0x18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24ULL;
	}
x86_l_768:
	/* 0x768: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_76e:
	/* 0x76e: mov    r14,QWORD PTR [rip+0x2d96] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_775:
	/* 0x775: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_77a:
	/* 0x77a: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_77d:
	/* 0x77d: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_780:
	/* 0x780: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_783:
	/* 0x783: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_785:
	/* 0x785: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_788:
	/* 0x788: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_78d:
	/* 0x78d: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_790:
	/* 0x790: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_793:
	/* 0x793: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_795:
	/* 0x795: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_798:
	/* 0x798: je     18 <try_preload_arg+0x18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24ULL;
	}
x86_l_79e:
	/* 0x79e: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_7a1:
	/* 0x7a1: jne    7cb <try_preload_arg+0x7cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7cb;
	}
x86_l_7a3:
	/* 0x7a3: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_7a6:
	/* 0x7a6: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_7aa:
	/* 0x7aa: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_7af:
	/* 0x7af: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_7b2:
	/* 0x7b2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7b4:
	/* 0x7b4: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_7b7:
	/* 0x7b7: call   3551 <try_preload_arg+0x3551> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_7bc:
	/* 0x7bc: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_7be:
	/* 0x7be: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_7c1:
	/* 0x7c1: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_7c3:
	/* 0x7c3: jns    7cb <try_preload_arg+0x7cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_7cb;
	}
x86_l_7c5:
	/* 0x7c5: mov    r13d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967295ULL);
x86_l_7cb:
	/* 0x7cb: mov    DWORD PTR [rax],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7ce:
	/* 0x7ce: jmp    18 <try_preload_arg+0x18> */
	return 24ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_multi_uprobe_v61_try_preload_arg_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 1804U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1727ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v61_try_preload_arg_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1730ULL && __x86_pc <= 1998ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v61_try_preload_arg_x86_chunk_1(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

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
	case 263ULL: goto x86_l_107;
	case 265ULL: goto x86_l_109;
	case 270ULL: goto x86_l_10e;
	case 275ULL: goto x86_l_113;
	case 280ULL: goto x86_l_118;
	case 285ULL: goto x86_l_11d;
	case 290ULL: goto x86_l_122;
	case 292ULL: goto x86_l_124;
	case 298ULL: goto x86_l_12a;
	case 300ULL: goto x86_l_12c;
	case 306ULL: goto x86_l_132;
	case 311ULL: goto x86_l_137;
	case 317ULL: goto x86_l_13d;
	case 320ULL: goto x86_l_140;
	case 325ULL: goto x86_l_145;
	case 330ULL: goto x86_l_14a;
	case 335ULL: goto x86_l_14f;
	case 337ULL: goto x86_l_151;
	case 342ULL: goto x86_l_156;
	case 347ULL: goto x86_l_15b;
	case 352ULL: goto x86_l_160;
	case 357ULL: goto x86_l_165;
	case 362ULL: goto x86_l_16a;
	case 364ULL: goto x86_l_16c;
	case 370ULL: goto x86_l_172;
	case 372ULL: goto x86_l_174;
	case 378ULL: goto x86_l_17a;
	case 383ULL: goto x86_l_17f;
	case 389ULL: goto x86_l_185;
	case 392ULL: goto x86_l_188;
	case 397ULL: goto x86_l_18d;
	case 402ULL: goto x86_l_192;
	case 407ULL: goto x86_l_197;
	case 409ULL: goto x86_l_199;
	case 414ULL: goto x86_l_19e;
	case 419ULL: goto x86_l_1a3;
	case 424ULL: goto x86_l_1a8;
	case 429ULL: goto x86_l_1ad;
	case 434ULL: goto x86_l_1b2;
	case 436ULL: goto x86_l_1b4;
	case 442ULL: goto x86_l_1ba;
	case 444ULL: goto x86_l_1bc;
	case 450ULL: goto x86_l_1c2;
	case 455ULL: goto x86_l_1c7;
	case 461ULL: goto x86_l_1cd;
	case 464ULL: goto x86_l_1d0;
	case 469ULL: goto x86_l_1d5;
	case 474ULL: goto x86_l_1da;
	case 479ULL: goto x86_l_1df;
	case 481ULL: goto x86_l_1e1;
	case 486ULL: goto x86_l_1e6;
	case 491ULL: goto x86_l_1eb;
	case 496ULL: goto x86_l_1f0;
	case 501ULL: goto x86_l_1f5;
	case 506ULL: goto x86_l_1fa;
	case 508ULL: goto x86_l_1fc;
	case 514ULL: goto x86_l_202;
	case 516ULL: goto x86_l_204;
	case 522ULL: goto x86_l_20a;
	case 527ULL: goto x86_l_20f;
	case 533ULL: goto x86_l_215;
	case 536ULL: goto x86_l_218;
	case 541ULL: goto x86_l_21d;
	case 546ULL: goto x86_l_222;
	case 551ULL: goto x86_l_227;
	case 553ULL: goto x86_l_229;
	case 558ULL: goto x86_l_22e;
	case 563ULL: goto x86_l_233;
	case 568ULL: goto x86_l_238;
	case 573ULL: goto x86_l_23d;
	case 578ULL: goto x86_l_242;
	case 580ULL: goto x86_l_244;
	case 586ULL: goto x86_l_24a;
	case 588ULL: goto x86_l_24c;
	case 594ULL: goto x86_l_252;
	case 599ULL: goto x86_l_257;
	case 605ULL: goto x86_l_25d;
	case 608ULL: goto x86_l_260;
	case 613ULL: goto x86_l_265;
	case 618ULL: goto x86_l_26a;
	case 623ULL: goto x86_l_26f;
	case 625ULL: goto x86_l_271;
	case 630ULL: goto x86_l_276;
	case 635ULL: goto x86_l_27b;
	case 640ULL: goto x86_l_280;
	case 645ULL: goto x86_l_285;
	case 650ULL: goto x86_l_28a;
	case 652ULL: goto x86_l_28c;
	case 658ULL: goto x86_l_292;
	case 660ULL: goto x86_l_294;
	case 666ULL: goto x86_l_29a;
	case 671ULL: goto x86_l_29f;
	case 677ULL: goto x86_l_2a5;
	case 680ULL: goto x86_l_2a8;
	case 685ULL: goto x86_l_2ad;
	case 690ULL: goto x86_l_2b2;
	case 695ULL: goto x86_l_2b7;
	case 697ULL: goto x86_l_2b9;
	case 702ULL: goto x86_l_2be;
	case 707ULL: goto x86_l_2c3;
	case 712ULL: goto x86_l_2c8;
	case 717ULL: goto x86_l_2cd;
	case 722ULL: goto x86_l_2d2;
	case 724ULL: goto x86_l_2d4;
	case 730ULL: goto x86_l_2da;
	case 732ULL: goto x86_l_2dc;
	case 738ULL: goto x86_l_2e2;
	case 743ULL: goto x86_l_2e7;
	case 749ULL: goto x86_l_2ed;
	case 752ULL: goto x86_l_2f0;
	case 757ULL: goto x86_l_2f5;
	case 762ULL: goto x86_l_2fa;
	case 767ULL: goto x86_l_2ff;
	case 769ULL: goto x86_l_301;
	case 774ULL: goto x86_l_306;
	case 779ULL: goto x86_l_30b;
	case 784ULL: goto x86_l_310;
	case 789ULL: goto x86_l_315;
	case 795ULL: goto x86_l_31b;
	case 800ULL: goto x86_l_320;
	case 802ULL: goto x86_l_322;
	case 804ULL: goto x86_l_324;
	case 810ULL: goto x86_l_32a;
	case 815ULL: goto x86_l_32f;
	case 821ULL: goto x86_l_335;
	case 824ULL: goto x86_l_338;
	case 829ULL: goto x86_l_33d;
	case 834ULL: goto x86_l_342;
	case 839ULL: goto x86_l_347;
	case 841ULL: goto x86_l_349;
	case 846ULL: goto x86_l_34e;
	case 851ULL: goto x86_l_353;
	case 856ULL: goto x86_l_358;
	case 861ULL: goto x86_l_35d;
	case 866ULL: goto x86_l_362;
	case 868ULL: goto x86_l_364;
	case 874ULL: goto x86_l_36a;
	case 876ULL: goto x86_l_36c;
	case 878ULL: goto x86_l_36e;
	case 883ULL: goto x86_l_373;
	case 889ULL: goto x86_l_379;
	case 892ULL: goto x86_l_37c;
	case 897ULL: goto x86_l_381;
	case 902ULL: goto x86_l_386;
	case 907ULL: goto x86_l_38b;
	case 913ULL: goto x86_l_391;
	case 918ULL: goto x86_l_396;
	case 923ULL: goto x86_l_39b;
	case 928ULL: goto x86_l_3a0;
	case 933ULL: goto x86_l_3a5;
	case 938ULL: goto x86_l_3aa;
	case 940ULL: goto x86_l_3ac;
	case 946ULL: goto x86_l_3b2;
	case 948ULL: goto x86_l_3b4;
	case 954ULL: goto x86_l_3ba;
	case 959ULL: goto x86_l_3bf;
	case 964ULL: goto x86_l_3c4;
	case 966ULL: goto x86_l_3c6;
	case 968ULL: goto x86_l_3c8;
	case 971ULL: goto x86_l_3cb;
	case 973ULL: goto x86_l_3cd;
	case 977ULL: goto x86_l_3d1;
	case 979ULL: goto x86_l_3d3;
	case 983ULL: goto x86_l_3d7;
	case 985ULL: goto x86_l_3d9;
	case 989ULL: goto x86_l_3dd;
	case 991ULL: goto x86_l_3df;
	case 995ULL: goto x86_l_3e3;
	case 1000ULL: goto x86_l_3e8;
	case 1003ULL: goto x86_l_3eb;
	case 1009ULL: goto x86_l_3f1;
	case 1013ULL: goto x86_l_3f5;
	case 1016ULL: goto x86_l_3f8;
	case 1023ULL: goto x86_l_3ff;
	case 1029ULL: goto x86_l_405;
	case 1033ULL: goto x86_l_409;
	case 1037ULL: goto x86_l_40d;
	case 1042ULL: goto x86_l_412;
	case 1047ULL: goto x86_l_417;
	case 1052ULL: goto x86_l_41c;
	case 1057ULL: goto x86_l_421;
	case 1062ULL: goto x86_l_426;
	case 1067ULL: goto x86_l_42b;
	case 1074ULL: goto x86_l_432;
	case 1077ULL: goto x86_l_435;
	case 1083ULL: goto x86_l_43b;
	case 1089ULL: goto x86_l_441;
	case 1095ULL: goto x86_l_447;
	case 1098ULL: goto x86_l_44a;
	case 1103ULL: goto x86_l_44f;
	case 1108ULL: goto x86_l_454;
	case 1114ULL: goto x86_l_45a;
	case 1116ULL: goto x86_l_45c;
	case 1121ULL: goto x86_l_461;
	case 1126ULL: goto x86_l_466;
	case 1131ULL: goto x86_l_46b;
	case 1136ULL: goto x86_l_470;
	case 1141ULL: goto x86_l_475;
	case 1143ULL: goto x86_l_477;
	case 1149ULL: goto x86_l_47d;
	case 1151ULL: goto x86_l_47f;
	case 1157ULL: goto x86_l_485;
	case 1163ULL: goto x86_l_48b;
	case 1169ULL: goto x86_l_491;
	case 1173ULL: goto x86_l_495;
	case 1178ULL: goto x86_l_49a;
	case 1183ULL: goto x86_l_49f;
	case 1189ULL: goto x86_l_4a5;
	case 1191ULL: goto x86_l_4a7;
	case 1196ULL: goto x86_l_4ac;
	case 1201ULL: goto x86_l_4b1;
	case 1206ULL: goto x86_l_4b6;
	case 1211ULL: goto x86_l_4bb;
	case 1216ULL: goto x86_l_4c0;
	case 1218ULL: goto x86_l_4c2;
	case 1224ULL: goto x86_l_4c8;
	case 1226ULL: goto x86_l_4ca;
	case 1232ULL: goto x86_l_4d0;
	case 1238ULL: goto x86_l_4d6;
	case 1244ULL: goto x86_l_4dc;
	case 1248ULL: goto x86_l_4e0;
	case 1253ULL: goto x86_l_4e5;
	case 1258ULL: goto x86_l_4ea;
	case 1264ULL: goto x86_l_4f0;
	case 1266ULL: goto x86_l_4f2;
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
	case 1333ULL: goto x86_l_535;
	case 1339ULL: goto x86_l_53b;
	case 1341ULL: goto x86_l_53d;
	case 1346ULL: goto x86_l_542;
	case 1351ULL: goto x86_l_547;
	case 1356ULL: goto x86_l_54c;
	case 1361ULL: goto x86_l_551;
	case 1366ULL: goto x86_l_556;
	case 1368ULL: goto x86_l_558;
	case 1374ULL: goto x86_l_55e;
	case 1376ULL: goto x86_l_560;
	case 1382ULL: goto x86_l_566;
	case 1388ULL: goto x86_l_56c;
	case 1394ULL: goto x86_l_572;
	case 1398ULL: goto x86_l_576;
	case 1403ULL: goto x86_l_57b;
	case 1408ULL: goto x86_l_580;
	case 1414ULL: goto x86_l_586;
	case 1416ULL: goto x86_l_588;
	case 1421ULL: goto x86_l_58d;
	case 1426ULL: goto x86_l_592;
	case 1431ULL: goto x86_l_597;
	case 1436ULL: goto x86_l_59c;
	case 1441ULL: goto x86_l_5a1;
	case 1443ULL: goto x86_l_5a3;
	case 1449ULL: goto x86_l_5a9;
	case 1451ULL: goto x86_l_5ab;
	case 1457ULL: goto x86_l_5b1;
	case 1463ULL: goto x86_l_5b7;
	case 1469ULL: goto x86_l_5bd;
	case 1473ULL: goto x86_l_5c1;
	case 1478ULL: goto x86_l_5c6;
	case 1483ULL: goto x86_l_5cb;
	case 1489ULL: goto x86_l_5d1;
	case 1491ULL: goto x86_l_5d3;
	case 1496ULL: goto x86_l_5d8;
	case 1501ULL: goto x86_l_5dd;
	case 1506ULL: goto x86_l_5e2;
	case 1511ULL: goto x86_l_5e7;
	case 1516ULL: goto x86_l_5ec;
	case 1518ULL: goto x86_l_5ee;
	case 1524ULL: goto x86_l_5f4;
	case 1526ULL: goto x86_l_5f6;
	case 1532ULL: goto x86_l_5fc;
	case 1538ULL: goto x86_l_602;
	case 1544ULL: goto x86_l_608;
	case 1548ULL: goto x86_l_60c;
	case 1553ULL: goto x86_l_611;
	case 1558ULL: goto x86_l_616;
	case 1564ULL: goto x86_l_61c;
	case 1566ULL: goto x86_l_61e;
	case 1571ULL: goto x86_l_623;
	case 1576ULL: goto x86_l_628;
	case 1581ULL: goto x86_l_62d;
	case 1586ULL: goto x86_l_632;
	case 1591ULL: goto x86_l_637;
	case 1593ULL: goto x86_l_639;
	case 1599ULL: goto x86_l_63f;
	case 1601ULL: goto x86_l_641;
	case 1607ULL: goto x86_l_647;
	case 1613ULL: goto x86_l_64d;
	case 1619ULL: goto x86_l_653;
	case 1623ULL: goto x86_l_657;
	case 1628ULL: goto x86_l_65c;
	case 1633ULL: goto x86_l_661;
	case 1639ULL: goto x86_l_667;
	case 1641ULL: goto x86_l_669;
	case 1646ULL: goto x86_l_66e;
	case 1651ULL: goto x86_l_673;
	case 1656ULL: goto x86_l_678;
	case 1661ULL: goto x86_l_67d;
	case 1667ULL: goto x86_l_683;
	case 1672ULL: goto x86_l_688;
	case 1674ULL: goto x86_l_68a;
	case 1676ULL: goto x86_l_68c;
	case 1682ULL: goto x86_l_692;
	case 1688ULL: goto x86_l_698;
	case 1694ULL: goto x86_l_69e;
	case 1698ULL: goto x86_l_6a2;
	case 1703ULL: goto x86_l_6a7;
	case 1708ULL: goto x86_l_6ac;
	case 1714ULL: goto x86_l_6b2;
	case 1716ULL: goto x86_l_6b4;
	case 1721ULL: goto x86_l_6b9;
	case 1726ULL: goto x86_l_6be;
	case 1731ULL: goto x86_l_6c3;
	case 1736ULL: goto x86_l_6c8;
	case 1741ULL: goto x86_l_6cd;
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
	/* 0x1e: jmp    8ae <try_preload_arg+0x8ae> ; native-link entry RET */
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
	/* 0x3b: jle    3c4 <try_preload_arg+0x3c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3c4;
	}
x86_l_41:
	/* 0x41: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_44:
	/* 0x44: je     3d3 <try_preload_arg+0x3d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d3;
	}
x86_l_4a:
	/* 0x4a: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_4d:
	/* 0x4d: je     3d9 <try_preload_arg+0x3d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d9;
	}
x86_l_53:
	/* 0x53: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_56:
	/* 0x56: jne    3e8 <try_preload_arg+0x3e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3e8;
	}
x86_l_5c:
	/* 0x5c: mov    rax,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_60:
	/* 0x60: jmp    3e3 <try_preload_arg+0x3e3> */
	goto x86_l_3e3;
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
	/* 0x9b: ja     753 <try_preload_arg+0x753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1875ULL;
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
	/* 0xaf: je     753 <try_preload_arg+0x753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1875ULL;
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
	/* 0xdb: mov    rax,QWORD PTR [rip+0x2e38] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_e2:
	/* 0xe2: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e5:
	/* 0xe5: je     732 <try_preload_arg+0x732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1842ULL;
	}
x86_l_eb:
	/* 0xeb: cmp    WORD PTR [rbx+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 25769803776ULL);
x86_l_f0:
	/* 0xf0: je     753 <try_preload_arg+0x753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1875ULL;
	}
x86_l_f6:
	/* 0xf6: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f8:
	/* 0xf8: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_fd:
	/* 0xfd: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_102:
	/* 0x102: cmp    WORD PTR [rbx+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_107:
	/* 0x107: je     132 <try_preload_arg+0x132> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_132;
	}
x86_l_109:
	/* 0x109: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10e:
	/* 0x10e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_113:
	/* 0x113: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_118:
	/* 0x118: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11d:
	/* 0x11d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_122:
	/* 0x122: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_124:
	/* 0x124: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_12a:
	/* 0x12a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12c:
	/* 0x12c: js     3ba <try_preload_arg+0x3ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3ba;
	}
x86_l_132:
	/* 0x132: cmp    WORD PTR [rbx+0xe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_137:
	/* 0x137: je     753 <try_preload_arg+0x753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1875ULL;
	}
x86_l_13d:
	/* 0x13d: mov    ecx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_140:
	/* 0x140: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_145:
	/* 0x145: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14a:
	/* 0x14a: cmp    WORD PTR [rbx+0xc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_14f:
	/* 0x14f: je     17a <try_preload_arg+0x17a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17a;
	}
x86_l_151:
	/* 0x151: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_156:
	/* 0x156: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_15b:
	/* 0x15b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_160:
	/* 0x160: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_165:
	/* 0x165: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16a:
	/* 0x16a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c:
	/* 0x16c: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_172:
	/* 0x172: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_174:
	/* 0x174: js     3ba <try_preload_arg+0x3ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3ba;
	}
x86_l_17a:
	/* 0x17a: cmp    WORD PTR [rbx+0x16],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94489280512ULL);
x86_l_17f:
	/* 0x17f: je     753 <try_preload_arg+0x753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1875ULL;
	}
x86_l_185:
	/* 0x185: mov    ecx,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_188:
	/* 0x188: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_18d:
	/* 0x18d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_192:
	/* 0x192: cmp    WORD PTR [rbx+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_197:
	/* 0x197: je     1c2 <try_preload_arg+0x1c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c2;
	}
x86_l_199:
	/* 0x199: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19e:
	/* 0x19e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a3:
	/* 0x1a3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a8:
	/* 0x1a8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ad:
	/* 0x1ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b2:
	/* 0x1b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b4:
	/* 0x1b4: mov    r14d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 3ULL);
x86_l_1ba:
	/* 0x1ba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bc:
	/* 0x1bc: js     3ba <try_preload_arg+0x3ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3ba;
	}
x86_l_1c2:
	/* 0x1c2: cmp    WORD PTR [rbx+0x1e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128849018880ULL);
x86_l_1c7:
	/* 0x1c7: je     753 <try_preload_arg+0x753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1875ULL;
	}
x86_l_1cd:
	/* 0x1cd: mov    ecx,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d0:
	/* 0x1d0: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1d5:
	/* 0x1d5: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1da:
	/* 0x1da: cmp    WORD PTR [rbx+0x1c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_1df:
	/* 0x1df: je     20a <try_preload_arg+0x20a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20a;
	}
x86_l_1e1:
	/* 0x1e1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e6:
	/* 0x1e6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1eb:
	/* 0x1eb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1f0:
	/* 0x1f0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f5:
	/* 0x1f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fa:
	/* 0x1fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fc:
	/* 0x1fc: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_202:
	/* 0x202: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_204:
	/* 0x204: js     3ba <try_preload_arg+0x3ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3ba;
	}
x86_l_20a:
	/* 0x20a: cmp    WORD PTR [rbx+0x26],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_20f:
	/* 0x20f: je     753 <try_preload_arg+0x753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1875ULL;
	}
x86_l_215:
	/* 0x215: mov    ecx,DWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_218:
	/* 0x218: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_21d:
	/* 0x21d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_222:
	/* 0x222: cmp    WORD PTR [rbx+0x24],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_227:
	/* 0x227: je     252 <try_preload_arg+0x252> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_252;
	}
x86_l_229:
	/* 0x229: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22e:
	/* 0x22e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_233:
	/* 0x233: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_238:
	/* 0x238: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23d:
	/* 0x23d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_242:
	/* 0x242: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_244:
	/* 0x244: mov    r14d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 5ULL);
x86_l_24a:
	/* 0x24a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24c:
	/* 0x24c: js     3ba <try_preload_arg+0x3ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3ba;
	}
x86_l_252:
	/* 0x252: cmp    WORD PTR [rbx+0x2e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 197568495616ULL);
x86_l_257:
	/* 0x257: je     753 <try_preload_arg+0x753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1875ULL;
	}
x86_l_25d:
	/* 0x25d: mov    ecx,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_260:
	/* 0x260: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_265:
	/* 0x265: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26a:
	/* 0x26a: cmp    WORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_26f:
	/* 0x26f: je     29a <try_preload_arg+0x29a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29a;
	}
x86_l_271:
	/* 0x271: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_276:
	/* 0x276: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_27b:
	/* 0x27b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_280:
	/* 0x280: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_285:
	/* 0x285: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28a:
	/* 0x28a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28c:
	/* 0x28c: mov    r14d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 6ULL);
x86_l_292:
	/* 0x292: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_294:
	/* 0x294: js     3ba <try_preload_arg+0x3ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3ba;
	}
x86_l_29a:
	/* 0x29a: cmp    WORD PTR [rbx+0x36],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 231928233984ULL);
x86_l_29f:
	/* 0x29f: je     753 <try_preload_arg+0x753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1875ULL;
	}
x86_l_2a5:
	/* 0x2a5: mov    ecx,DWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a8:
	/* 0x2a8: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2ad:
	/* 0x2ad: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b2:
	/* 0x2b2: cmp    WORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_2b7:
	/* 0x2b7: je     2e2 <try_preload_arg+0x2e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e2;
	}
x86_l_2b9:
	/* 0x2b9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2be:
	/* 0x2be: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2c3:
	/* 0x2c3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c8:
	/* 0x2c8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cd:
	/* 0x2cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d2:
	/* 0x2d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d4:
	/* 0x2d4: mov    r14d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 7ULL);
x86_l_2da:
	/* 0x2da: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2dc:
	/* 0x2dc: js     3ba <try_preload_arg+0x3ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3ba;
	}
x86_l_2e2:
	/* 0x2e2: cmp    WORD PTR [rbx+0x3e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 266287972352ULL);
x86_l_2e7:
	/* 0x2e7: je     753 <try_preload_arg+0x753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1875ULL;
	}
x86_l_2ed:
	/* 0x2ed: mov    ecx,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f0:
	/* 0x2f0: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2f5:
	/* 0x2f5: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fa:
	/* 0x2fa: cmp    WORD PTR [rbx+0x3c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_2ff:
	/* 0x2ff: je     32a <try_preload_arg+0x32a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32a;
	}
x86_l_301:
	/* 0x301: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_306:
	/* 0x306: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_30b:
	/* 0x30b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_310:
	/* 0x310: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_315:
	/* 0x315: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
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
	/* 0x324: js     3ba <try_preload_arg+0x3ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3ba;
	}
x86_l_32a:
	/* 0x32a: cmp    WORD PTR [rbx+0x46],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 300647710720ULL);
x86_l_32f:
	/* 0x32f: je     753 <try_preload_arg+0x753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1875ULL;
	}
x86_l_335:
	/* 0x335: mov    ecx,DWORD PTR [rbx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_338:
	/* 0x338: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_33d:
	/* 0x33d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_342:
	/* 0x342: cmp    WORD PTR [rbx+0x44],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_347:
	/* 0x347: je     36e <try_preload_arg+0x36e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36e;
	}
x86_l_349:
	/* 0x349: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34e:
	/* 0x34e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_353:
	/* 0x353: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_358:
	/* 0x358: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35d:
	/* 0x35d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_362:
	/* 0x362: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_364:
	/* 0x364: mov    r14d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 9ULL);
x86_l_36a:
	/* 0x36a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36c:
	/* 0x36c: js     3ba <try_preload_arg+0x3ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3ba;
	}
x86_l_36e:
	/* 0x36e: cmp    WORD PTR [rbx+0x4e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 335007449088ULL);
x86_l_373:
	/* 0x373: je     753 <try_preload_arg+0x753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1875ULL;
	}
x86_l_379:
	/* 0x379: mov    ecx,DWORD PTR [rbx+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_37c:
	/* 0x37c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_381:
	/* 0x381: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_386:
	/* 0x386: cmp    WORD PTR [rbx+0x4c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 326417514496ULL);
x86_l_38b:
	/* 0x38b: je     753 <try_preload_arg+0x753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1875ULL;
	}
x86_l_391:
	/* 0x391: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_396:
	/* 0x396: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_39b:
	/* 0x39b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a0:
	/* 0x3a0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a5:
	/* 0x3a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3aa:
	/* 0x3aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ac:
	/* 0x3ac: mov    r14d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 10ULL);
x86_l_3b2:
	/* 0x3b2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b4:
	/* 0x3b4: jns    753 <try_preload_arg+0x753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 1875ULL;
	}
x86_l_3ba:
	/* 0x3ba: mov    DWORD PTR [rsp+0x10],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bf:
	/* 0x3bf: jmp    753 <try_preload_arg+0x753> */
	return 1875ULL;
x86_l_3c4:
	/* 0x3c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c6:
	/* 0x3c6: je     3df <try_preload_arg+0x3df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3df;
	}
x86_l_3c8:
	/* 0x3c8: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3cb:
	/* 0x3cb: jne    3e8 <try_preload_arg+0x3e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3e8;
	}
x86_l_3cd:
	/* 0x3cd: mov    rax,QWORD PTR [rdi+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3d1:
	/* 0x3d1: jmp    3e3 <try_preload_arg+0x3e3> */
	goto x86_l_3e3;
x86_l_3d3:
	/* 0x3d3: mov    rax,QWORD PTR [rdi+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3d7:
	/* 0x3d7: jmp    3e3 <try_preload_arg+0x3e3> */
	goto x86_l_3e3;
x86_l_3d9:
	/* 0x3d9: mov    rax,QWORD PTR [rdi+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3dd:
	/* 0x3dd: jmp    3e3 <try_preload_arg+0x3e3> */
	goto x86_l_3e3;
x86_l_3df:
	/* 0x3df: mov    rax,QWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3e3:
	/* 0x3e3: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e8:
	/* 0x3e8: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_3eb:
	/* 0x3eb: ja     7e2 <try_preload_arg+0x7e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2018ULL;
	}
x86_l_3f1:
	/* 0x3f1: lea    rax,[rbx+rbx*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 2), 0ULL);
x86_l_3f5:
	/* 0x3f5: shl    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_3f8:
	/* 0x3f8: cmp    WORD PTR [r14+rax*1+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 506806140928ULL);
x86_l_3ff:
	/* 0x3ff: je     7e2 <try_preload_arg+0x7e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2018ULL;
	}
x86_l_405:
	/* 0x405: lea    r15,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_409:
	/* 0x409: add    r15,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_40d:
	/* 0x40d: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_412:
	/* 0x412: lea    rax,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_417:
	/* 0x417: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_41c:
	/* 0x41c: mov    BYTE PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_421:
	/* 0x421: lea    rax,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_426:
	/* 0x426: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_42b:
	/* 0x42b: mov    rax,QWORD PTR [rip+0x2e38] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_432:
	/* 0x432: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_435:
	/* 0x435: je     7c1 <try_preload_arg+0x7c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1985ULL;
	}
x86_l_43b:
	/* 0x43b: cmp    WORD PTR [r15+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 25769803776ULL);
x86_l_441:
	/* 0x441: je     7e2 <try_preload_arg+0x7e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2018ULL;
	}
x86_l_447:
	/* 0x447: mov    ecx,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44a:
	/* 0x44a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_44f:
	/* 0x44f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_454:
	/* 0x454: cmp    WORD PTR [r15+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_45a:
	/* 0x45a: je     485 <try_preload_arg+0x485> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_485;
	}
x86_l_45c:
	/* 0x45c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_461:
	/* 0x461: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_466:
	/* 0x466: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_46b:
	/* 0x46b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_470:
	/* 0x470: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_475:
	/* 0x475: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_477:
	/* 0x477: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_47d:
	/* 0x47d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_47f:
	/* 0x47f: js     728 <try_preload_arg+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1832ULL;
	}
x86_l_485:
	/* 0x485: cmp    WORD PTR [r15+0xe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_48b:
	/* 0x48b: je     7e2 <try_preload_arg+0x7e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2018ULL;
	}
x86_l_491:
	/* 0x491: mov    ecx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_495:
	/* 0x495: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_49a:
	/* 0x49a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49f:
	/* 0x49f: cmp    WORD PTR [r15+0xc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_4a5:
	/* 0x4a5: je     4d0 <try_preload_arg+0x4d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d0;
	}
x86_l_4a7:
	/* 0x4a7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ac:
	/* 0x4ac: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4b1:
	/* 0x4b1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b6:
	/* 0x4b6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bb:
	/* 0x4bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c0:
	/* 0x4c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c2:
	/* 0x4c2: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_4c8:
	/* 0x4c8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ca:
	/* 0x4ca: js     728 <try_preload_arg+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1832ULL;
	}
x86_l_4d0:
	/* 0x4d0: cmp    WORD PTR [r15+0x16],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94489280512ULL);
x86_l_4d6:
	/* 0x4d6: je     7e2 <try_preload_arg+0x7e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2018ULL;
	}
x86_l_4dc:
	/* 0x4dc: mov    ecx,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e0:
	/* 0x4e0: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4e5:
	/* 0x4e5: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ea:
	/* 0x4ea: cmp    WORD PTR [r15+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_4f0:
	/* 0x4f0: je     51b <try_preload_arg+0x51b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_51b;
	}
x86_l_4f2:
	/* 0x4f2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f7:
	/* 0x4f7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4fc:
	/* 0x4fc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_501:
	/* 0x501: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_506:
	/* 0x506: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50b:
	/* 0x50b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50d:
	/* 0x50d: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_513:
	/* 0x513: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_515:
	/* 0x515: js     728 <try_preload_arg+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1832ULL;
	}
x86_l_51b:
	/* 0x51b: cmp    WORD PTR [r15+0x1e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128849018880ULL);
x86_l_521:
	/* 0x521: je     7e2 <try_preload_arg+0x7e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2018ULL;
	}
x86_l_527:
	/* 0x527: mov    ecx,DWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_52b:
	/* 0x52b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_530:
	/* 0x530: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_535:
	/* 0x535: cmp    WORD PTR [r15+0x1c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_53b:
	/* 0x53b: je     566 <try_preload_arg+0x566> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_566;
	}
x86_l_53d:
	/* 0x53d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_542:
	/* 0x542: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_547:
	/* 0x547: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_54c:
	/* 0x54c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_551:
	/* 0x551: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_556:
	/* 0x556: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_558:
	/* 0x558: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_55e:
	/* 0x55e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_560:
	/* 0x560: js     728 <try_preload_arg+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1832ULL;
	}
x86_l_566:
	/* 0x566: cmp    WORD PTR [r15+0x26],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_56c:
	/* 0x56c: je     7e2 <try_preload_arg+0x7e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2018ULL;
	}
x86_l_572:
	/* 0x572: mov    ecx,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_576:
	/* 0x576: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_57b:
	/* 0x57b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_580:
	/* 0x580: cmp    WORD PTR [r15+0x24],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_586:
	/* 0x586: je     5b1 <try_preload_arg+0x5b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b1;
	}
x86_l_588:
	/* 0x588: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58d:
	/* 0x58d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_592:
	/* 0x592: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_597:
	/* 0x597: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59c:
	/* 0x59c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a1:
	/* 0x5a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a3:
	/* 0x5a3: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_5a9:
	/* 0x5a9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5ab:
	/* 0x5ab: js     728 <try_preload_arg+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1832ULL;
	}
x86_l_5b1:
	/* 0x5b1: cmp    WORD PTR [r15+0x2e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 197568495616ULL);
x86_l_5b7:
	/* 0x5b7: je     7e2 <try_preload_arg+0x7e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2018ULL;
	}
x86_l_5bd:
	/* 0x5bd: mov    ecx,DWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5c1:
	/* 0x5c1: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5c6:
	/* 0x5c6: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cb:
	/* 0x5cb: cmp    WORD PTR [r15+0x2c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_5d1:
	/* 0x5d1: je     5fc <try_preload_arg+0x5fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5fc;
	}
x86_l_5d3:
	/* 0x5d3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d8:
	/* 0x5d8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5dd:
	/* 0x5dd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5e2:
	/* 0x5e2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e7:
	/* 0x5e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ec:
	/* 0x5ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ee:
	/* 0x5ee: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_5f4:
	/* 0x5f4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5f6:
	/* 0x5f6: js     728 <try_preload_arg+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1832ULL;
	}
x86_l_5fc:
	/* 0x5fc: cmp    WORD PTR [r15+0x36],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 231928233984ULL);
x86_l_602:
	/* 0x602: je     7e2 <try_preload_arg+0x7e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2018ULL;
	}
x86_l_608:
	/* 0x608: mov    ecx,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_60c:
	/* 0x60c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_611:
	/* 0x611: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_616:
	/* 0x616: cmp    WORD PTR [r15+0x34],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_61c:
	/* 0x61c: je     647 <try_preload_arg+0x647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_647;
	}
x86_l_61e:
	/* 0x61e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_623:
	/* 0x623: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_628:
	/* 0x628: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_62d:
	/* 0x62d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_632:
	/* 0x632: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_637:
	/* 0x637: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_639:
	/* 0x639: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_63f:
	/* 0x63f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_641:
	/* 0x641: js     728 <try_preload_arg+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1832ULL;
	}
x86_l_647:
	/* 0x647: cmp    WORD PTR [r15+0x3e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 266287972352ULL);
x86_l_64d:
	/* 0x64d: je     7e2 <try_preload_arg+0x7e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2018ULL;
	}
x86_l_653:
	/* 0x653: mov    ecx,DWORD PTR [r15+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_657:
	/* 0x657: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_65c:
	/* 0x65c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_661:
	/* 0x661: cmp    WORD PTR [r15+0x3c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_667:
	/* 0x667: je     692 <try_preload_arg+0x692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_692;
	}
x86_l_669:
	/* 0x669: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_66e:
	/* 0x66e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_673:
	/* 0x673: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_678:
	/* 0x678: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_67d:
	/* 0x67d: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_683:
	/* 0x683: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_688:
	/* 0x688: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68a:
	/* 0x68a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_68c:
	/* 0x68c: js     728 <try_preload_arg+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1832ULL;
	}
x86_l_692:
	/* 0x692: cmp    WORD PTR [r15+0x46],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 300647710720ULL);
x86_l_698:
	/* 0x698: je     7e2 <try_preload_arg+0x7e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2018ULL;
	}
x86_l_69e:
	/* 0x69e: mov    ecx,DWORD PTR [r15+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6a2:
	/* 0x6a2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6a7:
	/* 0x6a7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6ac:
	/* 0x6ac: cmp    WORD PTR [r15+0x44],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_6b2:
	/* 0x6b2: je     6d9 <try_preload_arg+0x6d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1753ULL;
	}
x86_l_6b4:
	/* 0x6b4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6b9:
	/* 0x6b9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6be:
	/* 0x6be: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_6c3:
	/* 0x6c3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6c8:
	/* 0x6c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6cd:
	/* 0x6cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 1743ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v61_try_preload_arg_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1743ULL: goto x86_l_6cf;
	case 1749ULL: goto x86_l_6d5;
	case 1751ULL: goto x86_l_6d7;
	case 1753ULL: goto x86_l_6d9;
	case 1759ULL: goto x86_l_6df;
	case 1765ULL: goto x86_l_6e5;
	case 1769ULL: goto x86_l_6e9;
	case 1774ULL: goto x86_l_6ee;
	case 1779ULL: goto x86_l_6f3;
	case 1785ULL: goto x86_l_6f9;
	case 1791ULL: goto x86_l_6ff;
	case 1796ULL: goto x86_l_704;
	case 1801ULL: goto x86_l_709;
	case 1806ULL: goto x86_l_70e;
	case 1811ULL: goto x86_l_713;
	case 1816ULL: goto x86_l_718;
	case 1818ULL: goto x86_l_71a;
	case 1824ULL: goto x86_l_720;
	case 1826ULL: goto x86_l_722;
	case 1832ULL: goto x86_l_728;
	case 1837ULL: goto x86_l_72d;
	case 1842ULL: goto x86_l_732;
	case 1849ULL: goto x86_l_739;
	case 1851ULL: goto x86_l_73b;
	case 1856ULL: goto x86_l_740;
	case 1861ULL: goto x86_l_745;
	case 1866ULL: goto x86_l_74a;
	case 1871ULL: goto x86_l_74f;
	case 1873ULL: goto x86_l_751;
	case 1875ULL: goto x86_l_753;
	case 1879ULL: goto x86_l_757;
	case 1885ULL: goto x86_l_75d;
	case 1890ULL: goto x86_l_762;
	case 1895ULL: goto x86_l_767;
	case 1900ULL: goto x86_l_76c;
	case 1902ULL: goto x86_l_76e;
	case 1907ULL: goto x86_l_773;
	case 1915ULL: goto x86_l_77b;
	case 1922ULL: goto x86_l_782;
	case 1927ULL: goto x86_l_787;
	case 1932ULL: goto x86_l_78c;
	case 1934ULL: goto x86_l_78e;
	case 1937ULL: goto x86_l_791;
	case 1943ULL: goto x86_l_797;
	case 1946ULL: goto x86_l_79a;
	case 1953ULL: goto x86_l_7a1;
	case 1955ULL: goto x86_l_7a3;
	case 1960ULL: goto x86_l_7a8;
	case 1965ULL: goto x86_l_7ad;
	case 1968ULL: goto x86_l_7b0;
	case 1971ULL: goto x86_l_7b3;
	case 1973ULL: goto x86_l_7b5;
	case 1975ULL: goto x86_l_7b7;
	case 1980ULL: goto x86_l_7bc;
	case 1985ULL: goto x86_l_7c1;
	case 1992ULL: goto x86_l_7c8;
	case 1994ULL: goto x86_l_7ca;
	case 1999ULL: goto x86_l_7cf;
	case 2004ULL: goto x86_l_7d4;
	case 2009ULL: goto x86_l_7d9;
	case 2014ULL: goto x86_l_7de;
	case 2016ULL: goto x86_l_7e0;
	case 2018ULL: goto x86_l_7e2;
	case 2023ULL: goto x86_l_7e7;
	case 2028ULL: goto x86_l_7ec;
	case 2033ULL: goto x86_l_7f1;
	case 2038ULL: goto x86_l_7f6;
	case 2043ULL: goto x86_l_7fb;
	case 2046ULL: goto x86_l_7fe;
	case 2048ULL: goto x86_l_800;
	case 2051ULL: goto x86_l_803;
	case 2057ULL: goto x86_l_809;
	case 2062ULL: goto x86_l_80e;
	case 2067ULL: goto x86_l_813;
	case 2072ULL: goto x86_l_818;
	case 2074ULL: goto x86_l_81a;
	case 2079ULL: goto x86_l_81f;
	case 2087ULL: goto x86_l_827;
	case 2094ULL: goto x86_l_82e;
	case 2099ULL: goto x86_l_833;
	case 2104ULL: goto x86_l_838;
	case 2106ULL: goto x86_l_83a;
	case 2109ULL: goto x86_l_83d;
	case 2115ULL: goto x86_l_843;
	case 2118ULL: goto x86_l_846;
	case 2125ULL: goto x86_l_84d;
	case 2127ULL: goto x86_l_84f;
	case 2132ULL: goto x86_l_854;
	case 2137ULL: goto x86_l_859;
	case 2140ULL: goto x86_l_85c;
	case 2143ULL: goto x86_l_85f;
	case 2145ULL: goto x86_l_861;
	case 2147ULL: goto x86_l_863;
	case 2152ULL: goto x86_l_868;
	case 2155ULL: goto x86_l_86b;
	case 2158ULL: goto x86_l_86e;
	case 2160ULL: goto x86_l_870;
	case 2163ULL: goto x86_l_873;
	case 2169ULL: goto x86_l_879;
	case 2172ULL: goto x86_l_87c;
	case 2174ULL: goto x86_l_87e;
	case 2177ULL: goto x86_l_881;
	case 2181ULL: goto x86_l_885;
	case 2186ULL: goto x86_l_88a;
	case 2189ULL: goto x86_l_88d;
	case 2191ULL: goto x86_l_88f;
	case 2194ULL: goto x86_l_892;
	case 2199ULL: goto x86_l_897;
	case 2201ULL: goto x86_l_899;
	case 2204ULL: goto x86_l_89c;
	case 2206ULL: goto x86_l_89e;
	case 2208ULL: goto x86_l_8a0;
	case 2214ULL: goto x86_l_8a6;
	case 2217ULL: goto x86_l_8a9;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6cf:
	/* 0x6cf: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_6d5:
	/* 0x6d5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6d7:
	/* 0x6d7: js     728 <try_preload_arg+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_728;
	}
x86_l_6d9:
	/* 0x6d9: cmp    WORD PTR [r15+0x4e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 335007449088ULL);
x86_l_6df:
	/* 0x6df: je     7e2 <try_preload_arg+0x7e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e2;
	}
x86_l_6e5:
	/* 0x6e5: mov    ecx,DWORD PTR [r15+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6e9:
	/* 0x6e9: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6ee:
	/* 0x6ee: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6f3:
	/* 0x6f3: cmp    WORD PTR [r15+0x4c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 326417514496ULL);
x86_l_6f9:
	/* 0x6f9: je     7e2 <try_preload_arg+0x7e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e2;
	}
x86_l_6ff:
	/* 0x6ff: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_704:
	/* 0x704: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_709:
	/* 0x709: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_70e:
	/* 0x70e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_713:
	/* 0x713: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_718:
	/* 0x718: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_71a:
	/* 0x71a: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_720:
	/* 0x720: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_722:
	/* 0x722: jns    7e2 <try_preload_arg+0x7e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_7e2;
	}
x86_l_728:
	/* 0x728: mov    DWORD PTR [rsp+0x10],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_72d:
	/* 0x72d: jmp    7e2 <try_preload_arg+0x7e2> */
	goto x86_l_7e2;
x86_l_732:
	/* 0x732: lea    rsi,[rip+0xfffffffffffff9df] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 18446744073709550047ULL);
x86_l_739:
	/* 0x739: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_73b:
	/* 0x73b: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_740:
	/* 0x740: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_745:
	/* 0x745: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_74a:
	/* 0x74a: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_74f:
	/* 0x74f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_751:
	/* 0x751: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_753:
	/* 0x753: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_757:
	/* 0x757: jne    18 <try_preload_arg+0x18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24ULL;
	}
x86_l_75d:
	/* 0x75d: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_762:
	/* 0x762: mov    r13d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_767:
	/* 0x767: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_76c:
	/* 0x76c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76e:
	/* 0x76e: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_773:
	/* 0x773: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_77b:
	/* 0x77b: mov    rdi,QWORD PTR [rip+0x2e2b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_782:
	/* 0x782: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_787:
	/* 0x787: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_78c:
	/* 0x78c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_78e:
	/* 0x78e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_791:
	/* 0x791: je     18 <try_preload_arg+0x18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24ULL;
	}
x86_l_797:
	/* 0x797: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_79a:
	/* 0x79a: mov    r14,QWORD PTR [rip+0x2e2b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_7a1:
	/* 0x7a1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7a3:
	/* 0x7a3: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7a8:
	/* 0x7a8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7ad:
	/* 0x7ad: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_7b0:
	/* 0x7b0: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_7b3:
	/* 0x7b3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7b5:
	/* 0x7b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b7:
	/* 0x7b7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7bc:
	/* 0x7bc: jmp    868 <try_preload_arg+0x868> */
	goto x86_l_868;
x86_l_7c1:
	/* 0x7c1: lea    rsi,[rip+0xfffffffffffff950] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 18446744073709549904ULL);
x86_l_7c8:
	/* 0x7c8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7ca:
	/* 0x7ca: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7cf:
	/* 0x7cf: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_7d4:
	/* 0x7d4: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_7d9:
	/* 0x7d9: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_7de:
	/* 0x7de: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7e0:
	/* 0x7e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e2:
	/* 0x7e2: mov    ebx,DWORD PTR [r14+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_7e7:
	/* 0x7e7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7ec:
	/* 0x7ec: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7f1:
	/* 0x7f1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7f6:
	/* 0x7f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7fb:
	/* 0x7fb: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_7fe:
	/* 0x7fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_800:
	/* 0x800: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_803:
	/* 0x803: jne    18 <try_preload_arg+0x18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24ULL;
	}
x86_l_809:
	/* 0x809: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_80e:
	/* 0x80e: mov    r13d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_813:
	/* 0x813: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_818:
	/* 0x818: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_81a:
	/* 0x81a: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_81f:
	/* 0x81f: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_827:
	/* 0x827: mov    rdi,QWORD PTR [rip+0x2e2a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_82e:
	/* 0x82e: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_833:
	/* 0x833: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_838:
	/* 0x838: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_83a:
	/* 0x83a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_83d:
	/* 0x83d: je     18 <try_preload_arg+0x18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24ULL;
	}
x86_l_843:
	/* 0x843: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_846:
	/* 0x846: mov    r14,QWORD PTR [rip+0x2e2a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_84d:
	/* 0x84d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_84f:
	/* 0x84f: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_854:
	/* 0x854: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_859:
	/* 0x859: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_85c:
	/* 0x85c: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_85f:
	/* 0x85f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_861:
	/* 0x861: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_863:
	/* 0x863: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_868:
	/* 0x868: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_86b:
	/* 0x86b: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_86e:
	/* 0x86e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_870:
	/* 0x870: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_873:
	/* 0x873: je     18 <try_preload_arg+0x18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24ULL;
	}
x86_l_879:
	/* 0x879: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_87c:
	/* 0x87c: jne    8a6 <try_preload_arg+0x8a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8a6;
	}
x86_l_87e:
	/* 0x87e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_881:
	/* 0x881: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_885:
	/* 0x885: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_88a:
	/* 0x88a: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_88d:
	/* 0x88d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_88f:
	/* 0x88f: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_892:
	/* 0x892: call   36c0 <try_preload_arg+0x36c0> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_897:
	/* 0x897: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_899:
	/* 0x899: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_89c:
	/* 0x89c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_89e:
	/* 0x89e: jns    8a6 <try_preload_arg+0x8a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_8a6;
	}
x86_l_8a0:
	/* 0x8a0: mov    r13d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967295ULL);
x86_l_8a6:
	/* 0x8a6: mov    DWORD PTR [rax],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8a9:
	/* 0x8a9: jmp    18 <try_preload_arg+0x18> */
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
	for (__u32 __x86_iter = 0; __x86_iter < 1992U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1741ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v61_try_preload_arg_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1743ULL && __x86_pc <= 2217ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v61_try_preload_arg_x86_chunk_1(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

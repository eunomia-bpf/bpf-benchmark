extern char CONFIG_ITER_NUM;
extern char buffer_heap_map;
extern char config_map;
extern char execve_map;
extern char fdinstall_map;
extern char process_call_heap;
extern char retprobe_map;
extern char retuprobe_calls;
extern char socktrack_map;
extern char tg_ipv6_ext_heap;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_multi_retuprobe_v61_generic_retuprobe_event_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 17ULL: goto x86_l_11;
	case 28ULL: goto x86_l_1c;
	case 33ULL: goto x86_l_21;
	case 40ULL: goto x86_l_28;
	case 48ULL: goto x86_l_30;
	case 50ULL: goto x86_l_32;
	case 52ULL: goto x86_l_34;
	case 55ULL: goto x86_l_37;
	case 61ULL: goto x86_l_3d;
	case 64ULL: goto x86_l_40;
	case 67ULL: goto x86_l_43;
	case 72ULL: goto x86_l_48;
	case 75ULL: goto x86_l_4b;
	case 77ULL: goto x86_l_4d;
	case 84ULL: goto x86_l_54;
	case 91ULL: goto x86_l_5b;
	case 96ULL: goto x86_l_60;
	case 103ULL: goto x86_l_67;
	case 105ULL: goto x86_l_69;
	case 108ULL: goto x86_l_6c;
	case 114ULL: goto x86_l_72;
	case 117ULL: goto x86_l_75;
	case 119ULL: goto x86_l_77;
	case 123ULL: goto x86_l_7b;
	case 128ULL: goto x86_l_80;
	case 130ULL: goto x86_l_82;
	case 134ULL: goto x86_l_86;
	case 136ULL: goto x86_l_88;
	case 140ULL: goto x86_l_8c;
	case 144ULL: goto x86_l_90;
	case 149ULL: goto x86_l_95;
	case 151ULL: goto x86_l_97;
	case 155ULL: goto x86_l_9b;
	case 159ULL: goto x86_l_9f;
	case 163ULL: goto x86_l_a3;
	case 168ULL: goto x86_l_a8;
	case 173ULL: goto x86_l_ad;
	case 178ULL: goto x86_l_b2;
	case 185ULL: goto x86_l_b9;
	case 190ULL: goto x86_l_be;
	case 192ULL: goto x86_l_c0;
	case 195ULL: goto x86_l_c3;
	case 201ULL: goto x86_l_c9;
	case 209ULL: goto x86_l_d1;
	case 212ULL: goto x86_l_d4;
	case 216ULL: goto x86_l_d8;
	case 224ULL: goto x86_l_e0;
	case 228ULL: goto x86_l_e4;
	case 233ULL: goto x86_l_e9;
	case 240ULL: goto x86_l_f0;
	case 245ULL: goto x86_l_f5;
	case 247ULL: goto x86_l_f7;
	case 254ULL: goto x86_l_fe;
	case 259ULL: goto x86_l_103;
	case 267ULL: goto x86_l_10b;
	case 272ULL: goto x86_l_110;
	case 275ULL: goto x86_l_113;
	case 277ULL: goto x86_l_115;
	case 281ULL: goto x86_l_119;
	case 292ULL: goto x86_l_124;
	case 303ULL: goto x86_l_12f;
	case 308ULL: goto x86_l_134;
	case 315ULL: goto x86_l_13b;
	case 323ULL: goto x86_l_143;
	case 325ULL: goto x86_l_145;
	case 328ULL: goto x86_l_148;
	case 334ULL: goto x86_l_14e;
	case 340ULL: goto x86_l_154;
	case 346ULL: goto x86_l_15a;
	case 357ULL: goto x86_l_165;
	case 362ULL: goto x86_l_16a;
	case 364ULL: goto x86_l_16c;
	case 370ULL: goto x86_l_172;
	case 374ULL: goto x86_l_176;
	case 379ULL: goto x86_l_17b;
	case 384ULL: goto x86_l_180;
	case 391ULL: goto x86_l_187;
	case 394ULL: goto x86_l_18a;
	case 400ULL: goto x86_l_190;
	case 408ULL: goto x86_l_198;
	case 412ULL: goto x86_l_19c;
	case 415ULL: goto x86_l_19f;
	case 421ULL: goto x86_l_1a5;
	case 429ULL: goto x86_l_1ad;
	case 434ULL: goto x86_l_1b2;
	case 439ULL: goto x86_l_1b7;
	case 444ULL: goto x86_l_1bc;
	case 449ULL: goto x86_l_1c1;
	case 457ULL: goto x86_l_1c9;
	case 459ULL: goto x86_l_1cb;
	case 464ULL: goto x86_l_1d0;
	case 466ULL: goto x86_l_1d2;
	case 472ULL: goto x86_l_1d8;
	case 477ULL: goto x86_l_1dd;
	case 480ULL: goto x86_l_1e0;
	case 483ULL: goto x86_l_1e3;
	case 487ULL: goto x86_l_1e7;
	case 490ULL: goto x86_l_1ea;
	case 494ULL: goto x86_l_1ee;
	case 499ULL: goto x86_l_1f3;
	case 506ULL: goto x86_l_1fa;
	case 512ULL: goto x86_l_200;
	case 515ULL: goto x86_l_203;
	case 518ULL: goto x86_l_206;
	case 522ULL: goto x86_l_20a;
	case 527ULL: goto x86_l_20f;
	case 531ULL: goto x86_l_213;
	case 536ULL: goto x86_l_218;
	case 541ULL: goto x86_l_21d;
	case 546ULL: goto x86_l_222;
	case 551ULL: goto x86_l_227;
	case 553ULL: goto x86_l_229;
	case 558ULL: goto x86_l_22e;
	case 563ULL: goto x86_l_233;
	case 565ULL: goto x86_l_235;
	case 571ULL: goto x86_l_23b;
	case 574ULL: goto x86_l_23e;
	case 580ULL: goto x86_l_244;
	case 583ULL: goto x86_l_247;
	case 591ULL: goto x86_l_24f;
	case 597ULL: goto x86_l_255;
	case 599ULL: goto x86_l_257;
	case 601ULL: goto x86_l_259;
	case 605ULL: goto x86_l_25d;
	case 610ULL: goto x86_l_262;
	case 617ULL: goto x86_l_269;
	case 622ULL: goto x86_l_26e;
	case 631ULL: goto x86_l_277;
	case 635ULL: goto x86_l_27b;
	case 640ULL: goto x86_l_280;
	case 648ULL: goto x86_l_288;
	case 650ULL: goto x86_l_28a;
	case 654ULL: goto x86_l_28e;
	case 656ULL: goto x86_l_290;
	case 660ULL: goto x86_l_294;
	case 666ULL: goto x86_l_29a;
	case 670ULL: goto x86_l_29e;
	case 676ULL: goto x86_l_2a4;
	case 681ULL: goto x86_l_2a9;
	case 686ULL: goto x86_l_2ae;
	case 691ULL: goto x86_l_2b3;
	case 696ULL: goto x86_l_2b8;
	case 698ULL: goto x86_l_2ba;
	case 703ULL: goto x86_l_2bf;
	case 708ULL: goto x86_l_2c4;
	case 710ULL: goto x86_l_2c6;
	case 713ULL: goto x86_l_2c9;
	case 717ULL: goto x86_l_2cd;
	case 722ULL: goto x86_l_2d2;
	case 726ULL: goto x86_l_2d6;
	case 729ULL: goto x86_l_2d9;
	case 734ULL: goto x86_l_2de;
	case 738ULL: goto x86_l_2e2;
	case 744ULL: goto x86_l_2e8;
	case 748ULL: goto x86_l_2ec;
	case 754ULL: goto x86_l_2f2;
	case 759ULL: goto x86_l_2f7;
	case 764ULL: goto x86_l_2fc;
	case 769ULL: goto x86_l_301;
	case 771ULL: goto x86_l_303;
	case 783ULL: goto x86_l_30f;
	case 791ULL: goto x86_l_317;
	case 799ULL: goto x86_l_31f;
	case 801ULL: goto x86_l_321;
	case 805ULL: goto x86_l_325;
	case 810ULL: goto x86_l_32a;
	case 815ULL: goto x86_l_32f;
	case 820ULL: goto x86_l_334;
	case 825ULL: goto x86_l_339;
	case 830ULL: goto x86_l_33e;
	case 832ULL: goto x86_l_340;
	case 837ULL: goto x86_l_345;
	case 841ULL: goto x86_l_349;
	case 849ULL: goto x86_l_351;
	case 854ULL: goto x86_l_356;
	case 865ULL: goto x86_l_361;
	case 870ULL: goto x86_l_366;
	case 877ULL: goto x86_l_36d;
	case 885ULL: goto x86_l_375;
	case 887ULL: goto x86_l_377;
	case 890ULL: goto x86_l_37a;
	case 896ULL: goto x86_l_380;
	case 899ULL: goto x86_l_383;
	case 905ULL: goto x86_l_389;
	case 910ULL: goto x86_l_38e;
	case 915ULL: goto x86_l_393;
	case 917ULL: goto x86_l_395;
	case 924ULL: goto x86_l_39c;
	case 929ULL: goto x86_l_3a1;
	case 937ULL: goto x86_l_3a9;
	case 942ULL: goto x86_l_3ae;
	case 944ULL: goto x86_l_3b0;
	case 952ULL: goto x86_l_3b8;
	case 957ULL: goto x86_l_3bd;
	case 965ULL: goto x86_l_3c5;
	case 973ULL: goto x86_l_3cd;
	case 977ULL: goto x86_l_3d1;
	case 982ULL: goto x86_l_3d6;
	case 990ULL: goto x86_l_3de;
	case 995ULL: goto x86_l_3e3;
	case 1003ULL: goto x86_l_3eb;
	case 1005ULL: goto x86_l_3ed;
	case 1013ULL: goto x86_l_3f5;
	case 1017ULL: goto x86_l_3f9;
	case 1022ULL: goto x86_l_3fe;
	case 1027ULL: goto x86_l_403;
	case 1032ULL: goto x86_l_408;
	case 1034ULL: goto x86_l_40a;
	case 1040ULL: goto x86_l_410;
	case 1045ULL: goto x86_l_415;
	case 1047ULL: goto x86_l_417;
	case 1052ULL: goto x86_l_41c;
	case 1054ULL: goto x86_l_41e;
	case 1056ULL: goto x86_l_420;
	case 1061ULL: goto x86_l_425;
	case 1066ULL: goto x86_l_42a;
	case 1070ULL: goto x86_l_42e;
	case 1075ULL: goto x86_l_433;
	case 1080ULL: goto x86_l_438;
	case 1085ULL: goto x86_l_43d;
	case 1087ULL: goto x86_l_43f;
	case 1092ULL: goto x86_l_444;
	case 1097ULL: goto x86_l_449;
	case 1099ULL: goto x86_l_44b;
	case 1102ULL: goto x86_l_44e;
	case 1109ULL: goto x86_l_455;
	case 1119ULL: goto x86_l_45f;
	case 1126ULL: goto x86_l_466;
	case 1136ULL: goto x86_l_470;
	case 1141ULL: goto x86_l_475;
	case 1150ULL: goto x86_l_47e;
	case 1159ULL: goto x86_l_487;
	case 1164ULL: goto x86_l_48c;
	case 1169ULL: goto x86_l_491;
	case 1174ULL: goto x86_l_496;
	case 1183ULL: goto x86_l_49f;
	case 1192ULL: goto x86_l_4a8;
	case 1201ULL: goto x86_l_4b1;
	case 1206ULL: goto x86_l_4b6;
	case 1211ULL: goto x86_l_4bb;
	case 1215ULL: goto x86_l_4bf;
	case 1220ULL: goto x86_l_4c4;
	case 1225ULL: goto x86_l_4c9;
	case 1229ULL: goto x86_l_4cd;
	case 1234ULL: goto x86_l_4d2;
	case 1239ULL: goto x86_l_4d7;
	case 1244ULL: goto x86_l_4dc;
	case 1247ULL: goto x86_l_4df;
	case 1249ULL: goto x86_l_4e1;
	case 1254ULL: goto x86_l_4e6;
	case 1257ULL: goto x86_l_4e9;
	case 1262ULL: goto x86_l_4ee;
	case 1270ULL: goto x86_l_4f6;
	case 1272ULL: goto x86_l_4f8;
	case 1277ULL: goto x86_l_4fd;
	case 1280ULL: goto x86_l_500;
	case 1285ULL: goto x86_l_505;
	case 1293ULL: goto x86_l_50d;
	case 1295ULL: goto x86_l_50f;
	case 1300ULL: goto x86_l_514;
	case 1303ULL: goto x86_l_517;
	case 1308ULL: goto x86_l_51c;
	case 1316ULL: goto x86_l_524;
	case 1318ULL: goto x86_l_526;
	case 1323ULL: goto x86_l_52b;
	case 1327ULL: goto x86_l_52f;
	case 1332ULL: goto x86_l_534;
	case 1339ULL: goto x86_l_53b;
	case 1342ULL: goto x86_l_53e;
	case 1348ULL: goto x86_l_544;
	case 1353ULL: goto x86_l_549;
	case 1358ULL: goto x86_l_54e;
	case 1363ULL: goto x86_l_553;
	case 1368ULL: goto x86_l_558;
	case 1373ULL: goto x86_l_55d;
	case 1378ULL: goto x86_l_562;
	case 1380ULL: goto x86_l_564;
	case 1385ULL: goto x86_l_569;
	case 1391ULL: goto x86_l_56f;
	case 1396ULL: goto x86_l_574;
	case 1404ULL: goto x86_l_57c;
	case 1409ULL: goto x86_l_581;
	case 1411ULL: goto x86_l_583;
	case 1419ULL: goto x86_l_58b;
	case 1425ULL: goto x86_l_591;
	case 1429ULL: goto x86_l_595;
	case 1434ULL: goto x86_l_59a;
	case 1439ULL: goto x86_l_59f;
	case 1444ULL: goto x86_l_5a4;
	case 1447ULL: goto x86_l_5a7;
	case 1449ULL: goto x86_l_5a9;
	case 1454ULL: goto x86_l_5ae;
	case 1460ULL: goto x86_l_5b4;
	case 1465ULL: goto x86_l_5b9;
	case 1473ULL: goto x86_l_5c1;
	case 1478ULL: goto x86_l_5c6;
	case 1481ULL: goto x86_l_5c9;
	case 1483ULL: goto x86_l_5cb;
	case 1487ULL: goto x86_l_5cf;
	case 1492ULL: goto x86_l_5d4;
	case 1497ULL: goto x86_l_5d9;
	case 1502ULL: goto x86_l_5de;
	case 1505ULL: goto x86_l_5e1;
	case 1507ULL: goto x86_l_5e3;
	case 1512ULL: goto x86_l_5e8;
	case 1517ULL: goto x86_l_5ed;
	case 1521ULL: goto x86_l_5f1;
	case 1524ULL: goto x86_l_5f4;
	case 1528ULL: goto x86_l_5f8;
	case 1530ULL: goto x86_l_5fa;
	case 1532ULL: goto x86_l_5fc;
	case 1537ULL: goto x86_l_601;
	case 1540ULL: goto x86_l_604;
	case 1545ULL: goto x86_l_609;
	case 1548ULL: goto x86_l_60c;
	case 1550ULL: goto x86_l_60e;
	case 1554ULL: goto x86_l_612;
	case 1556ULL: goto x86_l_614;
	case 1559ULL: goto x86_l_617;
	case 1562ULL: goto x86_l_61a;
	case 1565ULL: goto x86_l_61d;
	case 1568ULL: goto x86_l_620;
	case 1573ULL: goto x86_l_625;
	case 1576ULL: goto x86_l_628;
	case 1581ULL: goto x86_l_62d;
	case 1587ULL: goto x86_l_633;
	case 1593ULL: goto x86_l_639;
	case 1599ULL: goto x86_l_63f;
	case 1601ULL: goto x86_l_641;
	case 1607ULL: goto x86_l_647;
	case 1611ULL: goto x86_l_64b;
	case 1616ULL: goto x86_l_650;
	case 1620ULL: goto x86_l_654;
	case 1624ULL: goto x86_l_658;
	case 1627ULL: goto x86_l_65b;
	case 1632ULL: goto x86_l_660;
	case 1634ULL: goto x86_l_662;
	case 1639ULL: goto x86_l_667;
	case 1644ULL: goto x86_l_66c;
	case 1652ULL: goto x86_l_674;
	case 1657ULL: goto x86_l_679;
	case 1659ULL: goto x86_l_67b;
	case 1665ULL: goto x86_l_681;
	case 1670ULL: goto x86_l_686;
	case 1675ULL: goto x86_l_68b;
	case 1680ULL: goto x86_l_690;
	case 1685ULL: goto x86_l_695;
	case 1690ULL: goto x86_l_69a;
	case 1692ULL: goto x86_l_69c;
	case 1697ULL: goto x86_l_6a1;
	case 1702ULL: goto x86_l_6a6;
	case 1708ULL: goto x86_l_6ac;
	case 1712ULL: goto x86_l_6b0;
	case 1717ULL: goto x86_l_6b5;
	case 1722ULL: goto x86_l_6ba;
	case 1727ULL: goto x86_l_6bf;
	case 1730ULL: goto x86_l_6c2;
	case 1732ULL: goto x86_l_6c4;
	case 1737ULL: goto x86_l_6c9;
	case 1742ULL: goto x86_l_6ce;
	case 1746ULL: goto x86_l_6d2;
	case 1751ULL: goto x86_l_6d7;
	case 1756ULL: goto x86_l_6dc;
	case 1758ULL: goto x86_l_6de;
	case 1764ULL: goto x86_l_6e4;
	case 1769ULL: goto x86_l_6e9;
	case 1774ULL: goto x86_l_6ee;
	case 1781ULL: goto x86_l_6f5;
	case 1786ULL: goto x86_l_6fa;
	case 1791ULL: goto x86_l_6ff;
	case 1793ULL: goto x86_l_701;
	case 1795ULL: goto x86_l_703;
	case 1800ULL: goto x86_l_708;
	case 1805ULL: goto x86_l_70d;
	case 1810ULL: goto x86_l_712;
	case 1815ULL: goto x86_l_717;
	case 1820ULL: goto x86_l_71c;
	case 1825ULL: goto x86_l_721;
	case 1827ULL: goto x86_l_723;
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
	/* 0xd: mov    r13,QWORD PTR [rdi+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_11:
	/* 0x11: mov    DWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_1c:
	/* 0x1c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21:
	/* 0x21: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_28:
	/* 0x28: lea    rsi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_30:
	/* 0x30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32:
	/* 0x32: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34:
	/* 0x34: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_37:
	/* 0x37: je     2c2b <generic_retuprobe_event+0x2c2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11307ULL;
	}
x86_l_3d:
	/* 0x3d: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_40:
	/* 0x40: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_43:
	/* 0x43: mov    eax,0xae */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 174ULL);
x86_l_48:
	/* 0x48: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4b:
	/* 0x4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d:
	/* 0x4d: lea    rsi,[r15+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_54:
	/* 0x54: mov    DWORD PTR [r15+0x5ef8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_5b:
	/* 0x5b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_60:
	/* 0x60: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_67:
	/* 0x67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69:
	/* 0x69: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6c:
	/* 0x6c: je     2c2b <generic_retuprobe_event+0x2c2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11307ULL;
	}
x86_l_72:
	/* 0x72: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_75:
	/* 0x75: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_77:
	/* 0x77: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7b:
	/* 0x7b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_80:
	/* 0x80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_82:
	/* 0x82: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_86:
	/* 0x86: jne    8c <generic_retuprobe_event+0x8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8c;
	}
x86_l_88:
	/* 0x88: mov    rax,QWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8c:
	/* 0x8c: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_90:
	/* 0x90: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_95:
	/* 0x95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_97:
	/* 0x97: mov    DWORD PTR [r14+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_9b:
	/* 0x9b: mov    rax,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9f:
	/* 0x9f: mov    rcx,QWORD PTR [r14+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a3:
	/* 0xa3: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a8:
	/* 0xa8: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_ad:
	/* 0xad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b2:
	/* 0xb2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_b9:
	/* 0xb9: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_be:
	/* 0xbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c0:
	/* 0xc0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c3:
	/* 0xc3: je     2c2b <generic_retuprobe_event+0x2c2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11307ULL;
	}
x86_l_c9:
	/* 0xc9: mov    QWORD PTR [rsp+0xe0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_d1:
	/* 0xd1: mov    rbx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d4:
	/* 0xd4: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d8:
	/* 0xd8: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_e0:
	/* 0xe0: mov    rbp,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e4:
	/* 0xe4: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_e9:
	/* 0xe9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_f0:
	/* 0xf0: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f5:
	/* 0xf5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f7:
	/* 0xf7: mov    QWORD PTR [r14+0x90],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_fe:
	/* 0xfe: mov    eax,DWORD PTR [r12+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_103:
	/* 0x103: mov    QWORD PTR [rsp+0xf0],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_10b:
	/* 0x10b: mov    r12d,DWORD PTR [r12+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_110:
	/* 0x110: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_113:
	/* 0x113: je     17b <generic_retuprobe_event+0x17b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17b;
	}
x86_l_115:
	/* 0x115: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_119:
	/* 0x119: mov    DWORD PTR [r14+0x5ea0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104041287778304ULL);
x86_l_124:
	/* 0x124: mov    DWORD PTR [rsp+0xd4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_12f:
	/* 0x12f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_134:
	/* 0x134: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_13b:
	/* 0x13b: lea    rsi,[rsp+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_143:
	/* 0x143: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_145:
	/* 0x145: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_148:
	/* 0x148: je     257 <generic_retuprobe_event+0x257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_257;
	}
x86_l_14e:
	/* 0x14e: mov    ecx,DWORD PTR [rax+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24224ULL);
x86_l_154:
	/* 0x154: mov    DWORD PTR [rax+0x98],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_15a:
	/* 0x15a: mov    QWORD PTR [rax+0x5e78],0xc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103869489086476ULL);
x86_l_165:
	/* 0x165: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_16a:
	/* 0x16a: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_16c:
	/* 0x16c: je     262 <generic_retuprobe_event+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_262;
	}
x86_l_172:
	/* 0x172: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_176:
	/* 0x176: jmp    a55 <generic_retuprobe_event+0xa55> */
	return 2645ULL;
x86_l_17b:
	/* 0x17b: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_180:
	/* 0x180: add    r15,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_187:
	/* 0x187: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_18a:
	/* 0x18a: jne    a6e <generic_retuprobe_event+0xa6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2670ULL;
	}
x86_l_190:
	/* 0x190: mov    DWORD PTR [r15+rbx*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_198:
	/* 0x198: lea    r12,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19c:
	/* 0x19c: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_19f:
	/* 0x19f: je     2c6 <generic_retuprobe_event+0x2c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c6;
	}
x86_l_1a5:
	/* 0x1a5: mov    QWORD PTR [rsp+0x80],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1ad:
	/* 0x1ad: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1b2:
	/* 0x1b2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b7:
	/* 0x1b7: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1bc:
	/* 0x1bc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1c1:
	/* 0x1c1: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1c9:
	/* 0x1c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cb:
	/* 0x1cb: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1d0:
	/* 0x1d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d2:
	/* 0x1d2: js     29e9 <generic_retuprobe_event+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10729ULL;
	}
x86_l_1d8:
	/* 0x1d8: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1dd:
	/* 0x1dd: cmp    rsi,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1e0:
	/* 0x1e0: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_1e3:
	/* 0x1e3: cmovb  r13,rsi */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RSI, X86_WIDTH_64, X86_CC_B);
x86_l_1e7:
	/* 0x1e7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ea:
	/* 0x1ea: cmovne rsi,r13 */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R13, X86_WIDTH_64, X86_CC_NE);
x86_l_1ee:
	/* 0x1ee: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_1f3:
	/* 0x1f3: cmp    rsi,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 4094ULL);
x86_l_1fa:
	/* 0x1fa: ja     29e9 <generic_retuprobe_event+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10729ULL;
	}
x86_l_200:
	/* 0x200: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_203:
	/* 0x203: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_206:
	/* 0x206: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_20a:
	/* 0x20a: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20f:
	/* 0x20f: lea    rdi,[r15+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_213:
	/* 0x213: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_218:
	/* 0x218: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_21d:
	/* 0x21d: mov    QWORD PTR [rsp+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_222:
	/* 0x222: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_227:
	/* 0x227: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_229:
	/* 0x229: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22e:
	/* 0x22e: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_233:
	/* 0x233: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_235:
	/* 0x235: js     29e9 <generic_retuprobe_event+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10729ULL;
	}
x86_l_23b:
	/* 0x23b: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_23e:
	/* 0x23e: je     867 <generic_retuprobe_event+0x867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2151ULL;
	}
x86_l_244:
	/* 0x244: sub    rbx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_247:
	/* 0x247: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_24f:
	/* 0x24f: jne    871 <generic_retuprobe_event+0x871> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2161ULL;
	}
x86_l_255:
	/* 0x255: jmp    2c9 <generic_retuprobe_event+0x2c9> */
	goto x86_l_2c9;
x86_l_257:
	/* 0x257: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_259:
	/* 0x259: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25d:
	/* 0x25d: jmp    a55 <generic_retuprobe_event+0xa55> */
	return 2645ULL;
x86_l_262:
	/* 0x262: lea    rcx,[rax+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_269:
	/* 0x269: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_26e:
	/* 0x26e: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_277:
	/* 0x277: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_27b:
	/* 0x27b: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_280:
	/* 0x280: mov    QWORD PTR [rsp+0x80],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_288:
	/* 0x288: jle    2de <generic_retuprobe_event+0x2de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2de;
	}
x86_l_28a:
	/* 0x28a: cmp    r12d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 42ULL);
x86_l_28e:
	/* 0x28e: je     303 <generic_retuprobe_event+0x303> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_303;
	}
x86_l_290:
	/* 0x290: cmp    r12d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 37ULL);
x86_l_294:
	/* 0x294: je     321 <generic_retuprobe_event+0x321> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_321;
	}
x86_l_29a:
	/* 0x29a: cmp    r12d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 24ULL);
x86_l_29e:
	/* 0x29e: jne    7bc <generic_retuprobe_event+0x7bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1980ULL;
	}
x86_l_2a4:
	/* 0x2a4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a9:
	/* 0x2a9: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ae:
	/* 0x2ae: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b3:
	/* 0x2b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b8:
	/* 0x2b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ba:
	/* 0x2ba: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2bf:
	/* 0x2bf: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c4:
	/* 0x2c4: jmp    2f2 <generic_retuprobe_event+0x2f2> */
	goto x86_l_2f2;
x86_l_2c6:
	/* 0x2c6: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c9:
	/* 0x2c9: mov    DWORD PTR [r15+r12*1],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2cd:
	/* 0x2cd: mov    DWORD PTR [r15+r12*1+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 4ULL);
x86_l_2d2:
	/* 0x2d2: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d6:
	/* 0x2d6: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_2d9:
	/* 0x2d9: jmp    29ed <generic_retuprobe_event+0x29ed> */
	return 10733ULL;
x86_l_2de:
	/* 0x2de: cmp    r12d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 15ULL);
x86_l_2e2:
	/* 0x2e2: je     708 <generic_retuprobe_event+0x708> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_708;
	}
x86_l_2e8:
	/* 0x2e8: cmp    r12d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 16ULL);
x86_l_2ec:
	/* 0x2ec: jne    7bc <generic_retuprobe_event+0x7bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1980ULL;
	}
x86_l_2f2:
	/* 0x2f2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f7:
	/* 0x2f7: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fc:
	/* 0x2fc: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_301:
	/* 0x301: jmp    339 <generic_retuprobe_event+0x339> */
	goto x86_l_339;
x86_l_303:
	/* 0x303: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_30f:
	/* 0x30f: mov    QWORD PTR [rsp+0x98],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_317:
	/* 0x317: lea    rax,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_31f:
	/* 0x31f: jmp    349 <generic_retuprobe_event+0x349> */
	goto x86_l_349;
x86_l_321:
	/* 0x321: lea    rax,[r13+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_325:
	/* 0x325: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_32a:
	/* 0x32a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32f:
	/* 0x32f: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_334:
	/* 0x334: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_339:
	/* 0x339: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33e:
	/* 0x33e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_340:
	/* 0x340: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_345:
	/* 0x345: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_349:
	/* 0x349: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_351:
	/* 0x351: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_356:
	/* 0x356: mov    DWORD PTR [rsp+0xac],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_361:
	/* 0x361: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_366:
	/* 0x366: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_36d:
	/* 0x36d: lea    rsi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_375:
	/* 0x375: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_377:
	/* 0x377: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_37a:
	/* 0x37a: je     41e <generic_retuprobe_event+0x41e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41e;
	}
x86_l_380:
	/* 0x380: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_383:
	/* 0x383: add    rax,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4096ULL);
x86_l_389:
	/* 0x389: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38e:
	/* 0x38e: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_393:
	/* 0x393: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_395:
	/* 0x395: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_39c:
	/* 0x39c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a1:
	/* 0x3a1: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3a9:
	/* 0x3a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ae:
	/* 0x3ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b0:
	/* 0x3b0: mov    r12,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3b8:
	/* 0x3b8: lea    rax,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3bd:
	/* 0x3bd: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_3c5:
	/* 0x3c5: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3cd:
	/* 0x3cd: lea    rdx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d1:
	/* 0x3d1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d6:
	/* 0x3d6: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_3de:
	/* 0x3de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e3:
	/* 0x3e3: mov    QWORD PTR [rsp+0xd8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_3eb:
	/* 0x3eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ed:
	/* 0x3ed: mov    rbp,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_3f5:
	/* 0x3f5: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f9:
	/* 0x3f9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3fe:
	/* 0x3fe: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_403:
	/* 0x403: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_408:
	/* 0x408: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40a:
	/* 0x40a: cmp    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_410:
	/* 0x410: mov    ebx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4096ULL);
x86_l_415:
	/* 0x415: je     42a <generic_retuprobe_event+0x42a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42a;
	}
x86_l_417:
	/* 0x417: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41c:
	/* 0x41c: jmp    475 <generic_retuprobe_event+0x475> */
	goto x86_l_475;
x86_l_41e:
	/* 0x41e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_420:
	/* 0x420: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_425:
	/* 0x425: jmp    a3c <generic_retuprobe_event+0xa3c> */
	return 2620ULL;
x86_l_42a:
	/* 0x42a: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_42e:
	/* 0x42e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_433:
	/* 0x433: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_438:
	/* 0x438: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_43d:
	/* 0x43d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43f:
	/* 0x43f: cmp    QWORD PTR [rsp+0x40],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_444:
	/* 0x444: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_449:
	/* 0x449: je     475 <generic_retuprobe_event+0x475> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_475;
	}
x86_l_44b:
	/* 0x44b: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_44e:
	/* 0x44e: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_455:
	/* 0x455: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_45f:
	/* 0x45f: mov    QWORD PTR [r13+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_466:
	/* 0x466: mov    WORD PTR [r13+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_470:
	/* 0x470: mov    ebx,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4086ULL);
x86_l_475:
	/* 0x475: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_47e:
	/* 0x47e: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_487:
	/* 0x487: mov    QWORD PTR [rsp+0x50],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_48c:
	/* 0x48c: lea    r13,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_491:
	/* 0x491: lea    rbp,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_496:
	/* 0x496: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_49f:
	/* 0x49f: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_4a8:
	/* 0x4a8: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_4b1:
	/* 0x4b1: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b6:
	/* 0x4b6: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4bb:
	/* 0x4bb: mov    DWORD PTR [rsp+0x78],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4bf:
	/* 0x4bf: lea    rbx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4c4:
	/* 0x4c4: mov    BYTE PTR [rsp+0x7c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_4c9:
	/* 0x4c9: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_4cd:
	/* 0x4cd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4d2:
	/* 0x4d2: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4d7:
	/* 0x4d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4dc:
	/* 0x4dc: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4df:
	/* 0x4df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e1:
	/* 0x4e1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4e6:
	/* 0x4e6: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_4e9:
	/* 0x4e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ee:
	/* 0x4ee: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_4f6:
	/* 0x4f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f8:
	/* 0x4f8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4fd:
	/* 0x4fd: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_500:
	/* 0x500: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_505:
	/* 0x505: mov    rdx,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_50d:
	/* 0x50d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50f:
	/* 0x50f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_514:
	/* 0x514: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_517:
	/* 0x517: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51c:
	/* 0x51c: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_524:
	/* 0x524: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_526:
	/* 0x526: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_52b:
	/* 0x52b: add    rax,0xffffffffffffffe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_52f:
	/* 0x52f: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_534:
	/* 0x534: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_53b:
	/* 0x53b: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53e:
	/* 0x53e: je     6e9 <generic_retuprobe_event+0x6e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6e9;
	}
x86_l_544:
	/* 0x544: mov    ebx,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2048ULL);
x86_l_549:
	/* 0x549: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_54e:
	/* 0x54e: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_553:
	/* 0x553: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_558:
	/* 0x558: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_55d:
	/* 0x55d: cmp    rbp,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_562:
	/* 0x562: jne    56f <generic_retuprobe_event+0x56f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_56f;
	}
x86_l_564:
	/* 0x564: cmp    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_569:
	/* 0x569: je     85d <generic_retuprobe_event+0x85d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2141ULL;
	}
x86_l_56f:
	/* 0x56f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_574:
	/* 0x574: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_57c:
	/* 0x57c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_581:
	/* 0x581: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_583:
	/* 0x583: cmp    rbp,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 176ULL);
x86_l_58b:
	/* 0x58b: je     686 <generic_retuprobe_event+0x686> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_686;
	}
x86_l_591:
	/* 0x591: lea    r13,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_595:
	/* 0x595: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_59a:
	/* 0x59a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_59f:
	/* 0x59f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a4:
	/* 0x5a4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5a7:
	/* 0x5a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a9:
	/* 0x5a9: cmp    QWORD PTR [rsp+0x20],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5ae:
	/* 0x5ae: je     686 <generic_retuprobe_event+0x686> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_686;
	}
x86_l_5b4:
	/* 0x5b4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5b9:
	/* 0x5b9: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_5c1:
	/* 0x5c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c6:
	/* 0x5c6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5c9:
	/* 0x5c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cb:
	/* 0x5cb: add    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_5cf:
	/* 0x5cf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5d4:
	/* 0x5d4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5d9:
	/* 0x5d9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5de:
	/* 0x5de: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5e1:
	/* 0x5e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e3:
	/* 0x5e3: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5e8:
	/* 0x5e8: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5ed:
	/* 0x5ed: mov    ecx,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_5f1:
	/* 0x5f1: sub    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_5f4:
	/* 0x5f4: mov    esi,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_5f8:
	/* 0x5f8: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_5fa:
	/* 0x5fa: sub    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5fc:
	/* 0x5fc: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_601:
	/* 0x601: cmovb  edx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_604:
	/* 0x604: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_609:
	/* 0x609: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_60c:
	/* 0x60c: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_60e:
	/* 0x60e: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_612:
	/* 0x612: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_614:
	/* 0x614: cmovb  edi,esi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_32, X86_CC_B);
x86_l_617:
	/* 0x617: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_61a:
	/* 0x61a: mov    r9d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RSI, X86_WIDTH_32);
x86_l_61d:
	/* 0x61d: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_620:
	/* 0x620: mov    DWORD PTR [rsp+0x78],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_625:
	/* 0x625: sub    rax,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_628:
	/* 0x628: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_62d:
	/* 0x62d: jb     94a <generic_retuprobe_event+0x94a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2378ULL;
	}
x86_l_633:
	/* 0x633: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_639:
	/* 0x639: ja     94a <generic_retuprobe_event+0x94a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2378ULL;
	}
x86_l_63f:
	/* 0x63f: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_641:
	/* 0x641: jbe    c39 <generic_retuprobe_event+0xc39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3129ULL;
	}
x86_l_647:
	/* 0x647: lea    r13,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_64b:
	/* 0x64b: mov    BYTE PTR [r12+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_650:
	/* 0x650: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_654:
	/* 0x654: lea    rdi,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_658:
	/* 0x658: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_65b:
	/* 0x65b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_660:
	/* 0x660: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_662:
	/* 0x662: mov    QWORD PTR [rsp+0x70],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_667:
	/* 0x667: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_66c:
	/* 0x66c: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_674:
	/* 0x674: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_679:
	/* 0x679: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_67b:
	/* 0x67b: jne    54e <generic_retuprobe_event+0x54e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_54e;
	}
x86_l_681:
	/* 0x681: jmp    94a <generic_retuprobe_event+0x94a> */
	return 2378ULL;
x86_l_686:
	/* 0x686: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_68b:
	/* 0x68b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_690:
	/* 0x690: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_695:
	/* 0x695: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_69a:
	/* 0x69a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69c:
	/* 0x69c: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6a1:
	/* 0x6a1: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_6a6:
	/* 0x6a6: je     940 <generic_retuprobe_event+0x940> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2368ULL;
	}
x86_l_6ac:
	/* 0x6ac: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_6b0:
	/* 0x6b0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6b5:
	/* 0x6b5: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_6ba:
	/* 0x6ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6bf:
	/* 0x6bf: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_6c2:
	/* 0x6c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c4:
	/* 0x6c4: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6c9:
	/* 0x6c9: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6ce:
	/* 0x6ce: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_6d2:
	/* 0x6d2: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6d7:
	/* 0x6d7: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6dc:
	/* 0x6dc: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_6de:
	/* 0x6de: jne    54e <generic_retuprobe_event+0x54e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_54e;
	}
x86_l_6e4:
	/* 0x6e4: jmp    94a <generic_retuprobe_event+0x94a> */
	return 2378ULL;
x86_l_6e9:
	/* 0x6e9: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_6ee:
	/* 0x6ee: lea    rsi,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_6f5:
	/* 0x6f5: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6fa:
	/* 0x6fa: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_6ff:
	/* 0x6ff: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_701:
	/* 0x701: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_703:
	/* 0x703: jmp    945 <generic_retuprobe_event+0x945> */
	return 2373ULL;
x86_l_708:
	/* 0x708: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_70d:
	/* 0x70d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_712:
	/* 0x712: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_717:
	/* 0x717: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_71c:
	/* 0x71c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_721:
	/* 0x721: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_723:
	/* 0x723: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
	return 1832ULL;
}

static __noinline __u64 tetragon_bpf_multi_retuprobe_v61_generic_retuprobe_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1832ULL: goto x86_l_728;
	case 1840ULL: goto x86_l_730;
	case 1843ULL: goto x86_l_733;
	case 1849ULL: goto x86_l_739;
	case 1860ULL: goto x86_l_744;
	case 1865ULL: goto x86_l_749;
	case 1872ULL: goto x86_l_750;
	case 1880ULL: goto x86_l_758;
	case 1882ULL: goto x86_l_75a;
	case 1884ULL: goto x86_l_75c;
	case 1887ULL: goto x86_l_75f;
	case 1893ULL: goto x86_l_765;
	case 1897ULL: goto x86_l_769;
	case 1902ULL: goto x86_l_76e;
	case 1908ULL: goto x86_l_774;
	case 1912ULL: goto x86_l_778;
	case 1918ULL: goto x86_l_77e;
	case 1922ULL: goto x86_l_782;
	case 1928ULL: goto x86_l_788;
	case 1932ULL: goto x86_l_78c;
	case 1938ULL: goto x86_l_792;
	case 1942ULL: goto x86_l_796;
	case 1948ULL: goto x86_l_79c;
	case 1952ULL: goto x86_l_7a0;
	case 1958ULL: goto x86_l_7a6;
	case 1968ULL: goto x86_l_7b0;
	case 1975ULL: goto x86_l_7b7;
	case 1980ULL: goto x86_l_7bc;
	case 1985ULL: goto x86_l_7c1;
	case 1989ULL: goto x86_l_7c5;
	case 1995ULL: goto x86_l_7cb;
	case 1998ULL: goto x86_l_7ce;
	case 2008ULL: goto x86_l_7d8;
	case 2012ULL: goto x86_l_7dc;
	case 2018ULL: goto x86_l_7e2;
	case 2023ULL: goto x86_l_7e7;
	case 2034ULL: goto x86_l_7f2;
	case 2039ULL: goto x86_l_7f7;
	case 2046ULL: goto x86_l_7fe;
	case 2054ULL: goto x86_l_806;
	case 2056ULL: goto x86_l_808;
	case 2058ULL: goto x86_l_80a;
	case 2061ULL: goto x86_l_80d;
	case 2067ULL: goto x86_l_813;
	case 2071ULL: goto x86_l_817;
	case 2077ULL: goto x86_l_81d;
	case 2081ULL: goto x86_l_821;
	case 2086ULL: goto x86_l_826;
	case 2092ULL: goto x86_l_82c;
	case 2096ULL: goto x86_l_830;
	case 2102ULL: goto x86_l_836;
	case 2107ULL: goto x86_l_83b;
	case 2110ULL: goto x86_l_83e;
	case 2116ULL: goto x86_l_844;
	case 2121ULL: goto x86_l_849;
	case 2126ULL: goto x86_l_84e;
	case 2131ULL: goto x86_l_853;
	case 2136ULL: goto x86_l_858;
	case 2141ULL: goto x86_l_85d;
	case 2146ULL: goto x86_l_862;
	case 2151ULL: goto x86_l_867;
	case 2153ULL: goto x86_l_869;
	case 2161ULL: goto x86_l_871;
	case 2165ULL: goto x86_l_875;
	case 2167ULL: goto x86_l_877;
	case 2170ULL: goto x86_l_87a;
	case 2175ULL: goto x86_l_87f;
	case 2183ULL: goto x86_l_887;
	case 2187ULL: goto x86_l_88b;
	case 2192ULL: goto x86_l_890;
	case 2197ULL: goto x86_l_895;
	case 2202ULL: goto x86_l_89a;
	case 2207ULL: goto x86_l_89f;
	case 2209ULL: goto x86_l_8a1;
	case 2214ULL: goto x86_l_8a6;
	case 2216ULL: goto x86_l_8a8;
	case 2222ULL: goto x86_l_8ae;
	case 2227ULL: goto x86_l_8b3;
	case 2230ULL: goto x86_l_8b6;
	case 2233ULL: goto x86_l_8b9;
	case 2236ULL: goto x86_l_8bc;
	case 2240ULL: goto x86_l_8c0;
	case 2243ULL: goto x86_l_8c3;
	case 2247ULL: goto x86_l_8c7;
	case 2252ULL: goto x86_l_8cc;
	case 2259ULL: goto x86_l_8d3;
	case 2265ULL: goto x86_l_8d9;
	case 2270ULL: goto x86_l_8de;
	case 2275ULL: goto x86_l_8e3;
	case 2280ULL: goto x86_l_8e8;
	case 2284ULL: goto x86_l_8ec;
	case 2289ULL: goto x86_l_8f1;
	case 2294ULL: goto x86_l_8f6;
	case 2299ULL: goto x86_l_8fb;
	case 2304ULL: goto x86_l_900;
	case 2306ULL: goto x86_l_902;
	case 2311ULL: goto x86_l_907;
	case 2316ULL: goto x86_l_90c;
	case 2318ULL: goto x86_l_90e;
	case 2324ULL: goto x86_l_914;
	case 2329ULL: goto x86_l_919;
	case 2332ULL: goto x86_l_91c;
	case 2335ULL: goto x86_l_91f;
	case 2341ULL: goto x86_l_925;
	case 2344ULL: goto x86_l_928;
	case 2349ULL: goto x86_l_92d;
	case 2357ULL: goto x86_l_935;
	case 2363ULL: goto x86_l_93b;
	case 2368ULL: goto x86_l_940;
	case 2373ULL: goto x86_l_945;
	case 2378ULL: goto x86_l_94a;
	case 2383ULL: goto x86_l_94f;
	case 2388ULL: goto x86_l_954;
	case 2390ULL: goto x86_l_956;
	case 2393ULL: goto x86_l_959;
	case 2395ULL: goto x86_l_95b;
	case 2400ULL: goto x86_l_960;
	case 2403ULL: goto x86_l_963;
	case 2407ULL: goto x86_l_967;
	case 2412ULL: goto x86_l_96c;
	case 2414ULL: goto x86_l_96e;
	case 2416ULL: goto x86_l_970;
	case 2419ULL: goto x86_l_973;
	case 2422ULL: goto x86_l_976;
	case 2427ULL: goto x86_l_97b;
	case 2433ULL: goto x86_l_981;
	case 2435ULL: goto x86_l_983;
	case 2437ULL: goto x86_l_985;
	case 2440ULL: goto x86_l_988;
	case 2442ULL: goto x86_l_98a;
	case 2444ULL: goto x86_l_98c;
	case 2449ULL: goto x86_l_991;
	case 2456ULL: goto x86_l_998;
	case 2462ULL: goto x86_l_99e;
	case 2467ULL: goto x86_l_9a3;
	case 2469ULL: goto x86_l_9a5;
	case 2471ULL: goto x86_l_9a7;
	case 2476ULL: goto x86_l_9ac;
	case 2482ULL: goto x86_l_9b2;
	case 2487ULL: goto x86_l_9b7;
	case 2492ULL: goto x86_l_9bc;
	case 2497ULL: goto x86_l_9c1;
	case 2505ULL: goto x86_l_9c9;
	case 2507ULL: goto x86_l_9cb;
	case 2512ULL: goto x86_l_9d0;
	case 2517ULL: goto x86_l_9d5;
	case 2521ULL: goto x86_l_9d9;
	case 2526ULL: goto x86_l_9de;
	case 2531ULL: goto x86_l_9e3;
	case 2533ULL: goto x86_l_9e5;
	case 2538ULL: goto x86_l_9ea;
	case 2543ULL: goto x86_l_9ef;
	case 2548ULL: goto x86_l_9f4;
	case 2553ULL: goto x86_l_9f9;
	case 2555ULL: goto x86_l_9fb;
	case 2560ULL: goto x86_l_a00;
	case 2567ULL: goto x86_l_a07;
	case 2572ULL: goto x86_l_a0c;
	case 2580ULL: goto x86_l_a14;
	case 2583ULL: goto x86_l_a17;
	case 2588ULL: goto x86_l_a1c;
	case 2590ULL: goto x86_l_a1e;
	case 2594ULL: goto x86_l_a22;
	case 2596ULL: goto x86_l_a24;
	case 2606ULL: goto x86_l_a2e;
	case 2616ULL: goto x86_l_a38;
	case 2618ULL: goto x86_l_a3a;
	case 2620ULL: goto x86_l_a3c;
	case 2624ULL: goto x86_l_a40;
	case 2630ULL: goto x86_l_a46;
	case 2634ULL: goto x86_l_a4a;
	case 2637ULL: goto x86_l_a4d;
	case 2645ULL: goto x86_l_a55;
	case 2648ULL: goto x86_l_a58;
	case 2654ULL: goto x86_l_a5e;
	case 2661ULL: goto x86_l_a65;
	case 2664ULL: goto x86_l_a68;
	case 2670ULL: goto x86_l_a6e;
	case 2673ULL: goto x86_l_a71;
	case 2679ULL: goto x86_l_a77;
	case 2687ULL: goto x86_l_a7f;
	case 2690ULL: goto x86_l_a82;
	case 2694ULL: goto x86_l_a86;
	case 2697ULL: goto x86_l_a89;
	case 2701ULL: goto x86_l_a8d;
	case 2705ULL: goto x86_l_a91;
	case 2712ULL: goto x86_l_a98;
	case 2718ULL: goto x86_l_a9e;
	case 2722ULL: goto x86_l_aa2;
	case 2726ULL: goto x86_l_aa6;
	case 2730ULL: goto x86_l_aaa;
	case 2736ULL: goto x86_l_ab0;
	case 2741ULL: goto x86_l_ab5;
	case 2744ULL: goto x86_l_ab8;
	case 2752ULL: goto x86_l_ac0;
	case 2754ULL: goto x86_l_ac2;
	case 2759ULL: goto x86_l_ac7;
	case 2761ULL: goto x86_l_ac9;
	case 2763ULL: goto x86_l_acb;
	case 2767ULL: goto x86_l_acf;
	case 2771ULL: goto x86_l_ad3;
	case 2773ULL: goto x86_l_ad5;
	case 2776ULL: goto x86_l_ad8;
	case 2779ULL: goto x86_l_adb;
	case 2783ULL: goto x86_l_adf;
	case 2786ULL: goto x86_l_ae2;
	case 2791ULL: goto x86_l_ae7;
	case 2795ULL: goto x86_l_aeb;
	case 2801ULL: goto x86_l_af1;
	case 2805ULL: goto x86_l_af5;
	case 2810ULL: goto x86_l_afa;
	case 2816ULL: goto x86_l_b00;
	case 2820ULL: goto x86_l_b04;
	case 2826ULL: goto x86_l_b0a;
	case 2830ULL: goto x86_l_b0e;
	case 2836ULL: goto x86_l_b14;
	case 2844ULL: goto x86_l_b1c;
	case 2848ULL: goto x86_l_b20;
	case 2854ULL: goto x86_l_b26;
	case 2859ULL: goto x86_l_b2b;
	case 2864ULL: goto x86_l_b30;
	case 2871ULL: goto x86_l_b37;
	case 2878ULL: goto x86_l_b3e;
	case 2882ULL: goto x86_l_b42;
	case 2887ULL: goto x86_l_b47;
	case 2892ULL: goto x86_l_b4c;
	case 2895ULL: goto x86_l_b4f;
	case 2897ULL: goto x86_l_b51;
	case 2904ULL: goto x86_l_b58;
	case 2908ULL: goto x86_l_b5c;
	case 2913ULL: goto x86_l_b61;
	case 2918ULL: goto x86_l_b66;
	case 2920ULL: goto x86_l_b68;
	case 2927ULL: goto x86_l_b6f;
	case 2934ULL: goto x86_l_b76;
	case 2939ULL: goto x86_l_b7b;
	case 2944ULL: goto x86_l_b80;
	case 2946ULL: goto x86_l_b82;
	case 2953ULL: goto x86_l_b89;
	case 2960ULL: goto x86_l_b90;
	case 2965ULL: goto x86_l_b95;
	case 2970ULL: goto x86_l_b9a;
	case 2972ULL: goto x86_l_b9c;
	case 2979ULL: goto x86_l_ba3;
	case 2986ULL: goto x86_l_baa;
	case 2991ULL: goto x86_l_baf;
	case 2996ULL: goto x86_l_bb4;
	case 2998ULL: goto x86_l_bb6;
	case 3005ULL: goto x86_l_bbd;
	case 3012ULL: goto x86_l_bc4;
	case 3017ULL: goto x86_l_bc9;
	case 3022ULL: goto x86_l_bce;
	case 3024ULL: goto x86_l_bd0;
	case 3031ULL: goto x86_l_bd7;
	case 3036ULL: goto x86_l_bdc;
	case 3043ULL: goto x86_l_be3;
	case 3051ULL: goto x86_l_beb;
	case 3059ULL: goto x86_l_bf3;
	case 3067ULL: goto x86_l_bfb;
	case 3074ULL: goto x86_l_c02;
	case 3077ULL: goto x86_l_c05;
	case 3083ULL: goto x86_l_c0b;
	case 3086ULL: goto x86_l_c0e;
	case 3092ULL: goto x86_l_c14;
	case 3096ULL: goto x86_l_c18;
	case 3101ULL: goto x86_l_c1d;
	case 3106ULL: goto x86_l_c22;
	case 3108ULL: goto x86_l_c24;
	case 3113ULL: goto x86_l_c29;
	case 3116ULL: goto x86_l_c2c;
	case 3121ULL: goto x86_l_c31;
	case 3124ULL: goto x86_l_c34;
	case 3129ULL: goto x86_l_c39;
	case 3133ULL: goto x86_l_c3d;
	case 3136ULL: goto x86_l_c40;
	case 3141ULL: goto x86_l_c45;
	case 3144ULL: goto x86_l_c48;
	case 3146ULL: goto x86_l_c4a;
	case 3151ULL: goto x86_l_c4f;
	case 3156ULL: goto x86_l_c54;
	case 3160ULL: goto x86_l_c58;
	case 3166ULL: goto x86_l_c5e;
	case 3170ULL: goto x86_l_c62;
	case 3176ULL: goto x86_l_c68;
	case 3180ULL: goto x86_l_c6c;
	case 3186ULL: goto x86_l_c72;
	case 3190ULL: goto x86_l_c76;
	case 3195ULL: goto x86_l_c7b;
	case 3201ULL: goto x86_l_c81;
	case 3206ULL: goto x86_l_c86;
	case 3211ULL: goto x86_l_c8b;
	case 3214ULL: goto x86_l_c8e;
	case 3219ULL: goto x86_l_c93;
	case 3225ULL: goto x86_l_c99;
	case 3230ULL: goto x86_l_c9e;
	case 3233ULL: goto x86_l_ca1;
	case 3239ULL: goto x86_l_ca7;
	case 3243ULL: goto x86_l_cab;
	case 3249ULL: goto x86_l_cb1;
	case 3254ULL: goto x86_l_cb6;
	case 3259ULL: goto x86_l_cbb;
	case 3264ULL: goto x86_l_cc0;
	case 3269ULL: goto x86_l_cc5;
	case 3272ULL: goto x86_l_cc8;
	case 3274ULL: goto x86_l_cca;
	case 3279ULL: goto x86_l_ccf;
	case 3284ULL: goto x86_l_cd4;
	case 3287ULL: goto x86_l_cd7;
	case 3292ULL: goto x86_l_cdc;
	case 3294ULL: goto x86_l_cde;
	case 3299ULL: goto x86_l_ce3;
	case 3304ULL: goto x86_l_ce8;
	case 3307ULL: goto x86_l_ceb;
	case 3314ULL: goto x86_l_cf2;
	case 3319ULL: goto x86_l_cf7;
	case 3324ULL: goto x86_l_cfc;
	case 3326ULL: goto x86_l_cfe;
	case 3329ULL: goto x86_l_d01;
	case 3332ULL: goto x86_l_d04;
	case 3338ULL: goto x86_l_d0a;
	case 3341ULL: goto x86_l_d0d;
	case 3346ULL: goto x86_l_d12;
	case 3348ULL: goto x86_l_d14;
	case 3352ULL: goto x86_l_d18;
	case 3357ULL: goto x86_l_d1d;
	case 3362ULL: goto x86_l_d22;
	case 3366ULL: goto x86_l_d26;
	case 3372ULL: goto x86_l_d2c;
	case 3377ULL: goto x86_l_d31;
	case 3380ULL: goto x86_l_d34;
	case 3386ULL: goto x86_l_d3a;
	case 3391ULL: goto x86_l_d3f;
	case 3396ULL: goto x86_l_d44;
	case 3401ULL: goto x86_l_d49;
	case 3404ULL: goto x86_l_d4c;
	case 3409ULL: goto x86_l_d51;
	case 3413ULL: goto x86_l_d55;
	case 3419ULL: goto x86_l_d5b;
	case 3423ULL: goto x86_l_d5f;
	case 3429ULL: goto x86_l_d65;
	case 3433ULL: goto x86_l_d69;
	case 3438ULL: goto x86_l_d6e;
	case 3444ULL: goto x86_l_d74;
	case 3447ULL: goto x86_l_d77;
	case 3452ULL: goto x86_l_d7c;
	case 3457ULL: goto x86_l_d81;
	case 3462ULL: goto x86_l_d86;
	case 3470ULL: goto x86_l_d8e;
	case 3478ULL: goto x86_l_d96;
	case 3486ULL: goto x86_l_d9e;
	case 3494ULL: goto x86_l_da6;
	case 3502ULL: goto x86_l_dae;
	case 3510ULL: goto x86_l_db6;
	case 3518ULL: goto x86_l_dbe;
	case 3526ULL: goto x86_l_dc6;
	case 3534ULL: goto x86_l_dce;
	case 3542ULL: goto x86_l_dd6;
	case 3550ULL: goto x86_l_dde;
	case 3558ULL: goto x86_l_de6;
	case 3566ULL: goto x86_l_dee;
	case 3573ULL: goto x86_l_df5;
	case 3578ULL: goto x86_l_dfa;
	case 3583ULL: goto x86_l_dff;
	case 3586ULL: goto x86_l_e02;
	case 3588ULL: goto x86_l_e04;
	case 3591ULL: goto x86_l_e07;
	case 3597ULL: goto x86_l_e0d;
	case 3602ULL: goto x86_l_e12;
	case 3607ULL: goto x86_l_e17;
	case 3612ULL: goto x86_l_e1c;
	case 3617ULL: goto x86_l_e21;
	case 3620ULL: goto x86_l_e24;
	case 3622ULL: goto x86_l_e26;
	case 3625ULL: goto x86_l_e29;
	case 3631ULL: goto x86_l_e2f;
	case 3636ULL: goto x86_l_e34;
	case 3639ULL: goto x86_l_e37;
	case 3646ULL: goto x86_l_e3e;
	case 3651ULL: goto x86_l_e43;
	case 3658ULL: goto x86_l_e4a;
	case 3664ULL: goto x86_l_e50;
	case 3669ULL: goto x86_l_e55;
	case 3674ULL: goto x86_l_e5a;
	case 3677ULL: goto x86_l_e5d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_728:
	/* 0x728: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_730:
	/* 0x730: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_733:
	/* 0x733: jne    351 <generic_retuprobe_event+0x351> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 849ULL;
	}
x86_l_739:
	/* 0x739: mov    DWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_744:
	/* 0x744: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_749:
	/* 0x749: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_750:
	/* 0x750: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_758:
	/* 0x758: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_75a:
	/* 0x75a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_75c:
	/* 0x75c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_75f:
	/* 0x75f: je     1592 <generic_retuprobe_event+0x1592> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5522ULL;
	}
x86_l_765:
	/* 0x765: cmp    r12d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 25ULL);
x86_l_769:
	/* 0x769: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_76e:
	/* 0x76e: jg     d22 <generic_retuprobe_event+0xd22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d22;
	}
x86_l_774:
	/* 0x774: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_778:
	/* 0x778: jle    e6e <generic_retuprobe_event+0xe6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3694ULL;
	}
x86_l_77e:
	/* 0x77e: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_782:
	/* 0x782: jle    1137 <generic_retuprobe_event+0x1137> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4407ULL;
	}
x86_l_788:
	/* 0x788: cmp    r12d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 21ULL);
x86_l_78c:
	/* 0x78c: je     1a2a <generic_retuprobe_event+0x1a2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6698ULL;
	}
x86_l_792:
	/* 0x792: cmp    r12d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 22ULL);
x86_l_796:
	/* 0x796: je     19a6 <generic_retuprobe_event+0x19a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6566ULL;
	}
x86_l_79c:
	/* 0x79c: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_7a0:
	/* 0x7a0: jne    a1c <generic_retuprobe_event+0xa1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a1c;
	}
x86_l_7a6:
	/* 0x7a6: mov    DWORD PTR [rcx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_7b0:
	/* 0x7b0: mov    DWORD PTR [rcx+0x9c],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_7b7:
	/* 0x7b7: jmp    eda <generic_retuprobe_event+0xeda> */
	return 3802ULL;
x86_l_7bc:
	/* 0x7bc: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7c1:
	/* 0x7c1: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_7c5:
	/* 0x7c5: ja     739 <generic_retuprobe_event+0x739> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_739;
	}
x86_l_7cb:
	/* 0x7cb: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_7ce:
	/* 0x7ce: movabs rcx,0x11c1f2027cf2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19524686609650ULL);
x86_l_7d8:
	/* 0x7d8: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_7dc:
	/* 0x7dc: jae    739 <generic_retuprobe_event+0x739> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_739;
	}
x86_l_7e2:
	/* 0x7e2: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7e7:
	/* 0x7e7: mov    DWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_7f2:
	/* 0x7f2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7f7:
	/* 0x7f7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_7fe:
	/* 0x7fe: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_806:
	/* 0x806: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_808:
	/* 0x808: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_80a:
	/* 0x80a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_80d:
	/* 0x80d: je     1592 <generic_retuprobe_event+0x1592> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5522ULL;
	}
x86_l_813:
	/* 0x813: cmp    r12d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 16ULL);
x86_l_817:
	/* 0x817: jle    ae7 <generic_retuprobe_event+0xae7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_ae7;
	}
x86_l_81d:
	/* 0x81d: cmp    r12d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 30ULL);
x86_l_821:
	/* 0x821: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_826:
	/* 0x826: jle    c54 <generic_retuprobe_event+0xc54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_c54;
	}
x86_l_82c:
	/* 0x82c: cmp    r12d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 38ULL);
x86_l_830:
	/* 0x830: jg     d51 <generic_retuprobe_event+0xd51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d51;
	}
x86_l_836:
	/* 0x836: lea    eax,[r12-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_83b:
	/* 0x83b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_83e:
	/* 0x83e: jae    11f1 <generic_retuprobe_event+0x11f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4593ULL;
	}
x86_l_844:
	/* 0x844: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_849:
	/* 0x849: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_84e:
	/* 0x84e: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_853:
	/* 0x853: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_858:
	/* 0x858: jmp    efd <generic_retuprobe_event+0xefd> */
	return 3837ULL;
x86_l_85d:
	/* 0x85d: mov    BYTE PTR [rsp+0x7c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 532575944705ULL);
x86_l_862:
	/* 0x862: jmp    94a <generic_retuprobe_event+0x94a> */
	goto x86_l_94a;
x86_l_867:
	/* 0x867: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_869:
	/* 0x869: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_871:
	/* 0x871: cmp    rax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 1ULL);
x86_l_875:
	/* 0x875: jne    87f <generic_retuprobe_event+0x87f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_87f;
	}
x86_l_877:
	/* 0x877: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_87a:
	/* 0x87a: jmp    2c9 <generic_retuprobe_event+0x2c9> */
	return 713ULL;
x86_l_87f:
	/* 0x87f: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_887:
	/* 0x887: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_88b:
	/* 0x88b: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_890:
	/* 0x890: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_895:
	/* 0x895: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_89a:
	/* 0x89a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_89f:
	/* 0x89f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a1:
	/* 0x8a1: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_8a6:
	/* 0x8a6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8a8:
	/* 0x8a8: js     29e9 <generic_retuprobe_event+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10729ULL;
	}
x86_l_8ae:
	/* 0x8ae: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8b3:
	/* 0x8b3: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_8b6:
	/* 0x8b6: cmp    rsi,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_8b9:
	/* 0x8b9: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_8bc:
	/* 0x8bc: cmovb  r13,rsi */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RSI, X86_WIDTH_64, X86_CC_B);
x86_l_8c0:
	/* 0x8c0: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_8c3:
	/* 0x8c3: cmovne rsi,r13 */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R13, X86_WIDTH_64, X86_CC_NE);
x86_l_8c7:
	/* 0x8c7: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_8cc:
	/* 0x8cc: cmp    rsi,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 4094ULL);
x86_l_8d3:
	/* 0x8d3: ja     29e9 <generic_retuprobe_event+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10729ULL;
	}
x86_l_8d9:
	/* 0x8d9: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8de:
	/* 0x8de: add    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_8e3:
	/* 0x8e3: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8e8:
	/* 0x8e8: lea    rdi,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_8ec:
	/* 0x8ec: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8f1:
	/* 0x8f1: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8f6:
	/* 0x8f6: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8fb:
	/* 0x8fb: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_900:
	/* 0x900: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_902:
	/* 0x902: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_907:
	/* 0x907: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_90c:
	/* 0x90c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_90e:
	/* 0x90e: js     29e9 <generic_retuprobe_event+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10729ULL;
	}
x86_l_914:
	/* 0x914: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_919:
	/* 0x919: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_91c:
	/* 0x91c: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_91f:
	/* 0x91f: je     1629 <generic_retuprobe_event+0x1629> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5673ULL;
	}
x86_l_925:
	/* 0x925: sub    rbx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_928:
	/* 0x928: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_92d:
	/* 0x92d: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_935:
	/* 0x935: jne    1638 <generic_retuprobe_event+0x1638> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5688ULL;
	}
x86_l_93b:
	/* 0x93b: jmp    16fd <generic_retuprobe_event+0x16fd> */
	return 5885ULL;
x86_l_940:
	/* 0x940: mov    BYTE PTR [rsp+0x7c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 532575944705ULL);
x86_l_945:
	/* 0x945: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_94a:
	/* 0x94a: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_94f:
	/* 0x94f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_954:
	/* 0x954: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_956:
	/* 0x956: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_959:
	/* 0x959: je     98a <generic_retuprobe_event+0x98a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_98a;
	}
x86_l_95b:
	/* 0x95b: cmp    BYTE PTR [rsp+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_960:
	/* 0x960: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_963:
	/* 0x963: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_967:
	/* 0x967: mov    ebp,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_96c:
	/* 0x96c: sub    ebp,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_96e:
	/* 0x96e: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_970:
	/* 0x970: cmovle ebp,edx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_973:
	/* 0x973: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_976:
	/* 0x976: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_97b:
	/* 0x97b: je     a3a <generic_retuprobe_event+0xa3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a3a;
	}
x86_l_981:
	/* 0x981: mov    bl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_8);
x86_l_983:
	/* 0x983: add    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_985:
	/* 0x985: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_988:
	/* 0x988: jmp    991 <generic_retuprobe_event+0x991> */
	goto x86_l_991;
x86_l_98a:
	/* 0x98a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_98c:
	/* 0x98c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_991:
	/* 0x991: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_998:
	/* 0x998: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_99e:
	/* 0x99e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9a3:
	/* 0x9a3: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_9a5:
	/* 0x9a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a7:
	/* 0x9a7: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9ac:
	/* 0x9ac: mov    DWORD PTR [rax+0x9c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_9b2:
	/* 0x9b2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9b7:
	/* 0x9b7: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9bc:
	/* 0x9bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9c1:
	/* 0x9c1: mov    rdx,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_9c9:
	/* 0x9c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9cb:
	/* 0x9cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9d0:
	/* 0x9d0: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9d5:
	/* 0x9d5: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_9d9:
	/* 0x9d9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9de:
	/* 0x9de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9e3:
	/* 0x9e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e5:
	/* 0x9e5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9ea:
	/* 0x9ea: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9ef:
	/* 0x9ef: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9f4:
	/* 0x9f4: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_9f9:
	/* 0x9f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9fb:
	/* 0x9fb: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a00:
	/* 0xa00: mov    DWORD PTR [rcx+rbp*1+0xa0],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 160ULL);
x86_l_a07:
	/* 0xa07: movzx  eax,WORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_a0c:
	/* 0xa0c: mov    WORD PTR [rcx+rbp*1+0xa4],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_RBP, 0), 164ULL);
x86_l_a14:
	/* 0xa14: add    ebp,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_a17:
	/* 0xa17: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_a1c:
	/* 0xa1c: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_a1e:
	/* 0xa1e: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a22:
	/* 0xa22: jns    a40 <generic_retuprobe_event+0xa40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_a40;
	}
x86_l_a24:
	/* 0xa24: mov    DWORD PTR [rcx+0x5ea0],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104045582745599ULL);
x86_l_a2e:
	/* 0xa2e: mov    DWORD PTR [rcx+0x98],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 657129996287ULL);
x86_l_a38:
	/* 0xa38: jmp    a4d <generic_retuprobe_event+0xa4d> */
	goto x86_l_a4d;
x86_l_a3a:
	/* 0xa3a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a3c:
	/* 0xa3c: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a40:
	/* 0xa40: and    ebp,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_a46:
	/* 0xa46: add    rbp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a4a:
	/* 0xa4a: mov    rbx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RBP, X86_WIDTH_64);
x86_l_a4d:
	/* 0xa4d: mov    rbp,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a55:
	/* 0xa55: add    ebx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_a58:
	/* 0xa58: and    ebx,0x1fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 8191ULL);
x86_l_a5e:
	/* 0xa5e: add    r15,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_a65:
	/* 0xa65: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_a68:
	/* 0xa68: je     190 <generic_retuprobe_event+0x190> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 400ULL;
	}
x86_l_a6e:
	/* 0xa6e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a71:
	/* 0xa71: jne    29f3 <generic_retuprobe_event+0x29f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10739ULL;
	}
x86_l_a77:
	/* 0xa77: mov    DWORD PTR [r15+rbx*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_a7f:
	/* 0xa7f: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_a82:
	/* 0xa82: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a86:
	/* 0xa86: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_a89:
	/* 0xa89: lea    r13,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_a8d:
	/* 0xa8d: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a91:
	/* 0xa91: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_a98:
	/* 0xa98: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_a9e:
	/* 0xa9e: cmovb  r12,rbp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_64, X86_CC_B);
x86_l_aa2:
	/* 0xaa2: lea    rdi,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_aa6:
	/* 0xaa6: add    rdi,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_aaa:
	/* 0xaaa: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_ab0:
	/* 0xab0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ab5:
	/* 0xab5: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_ab8:
	/* 0xab8: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_ac0:
	/* 0xac0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac2:
	/* 0xac2: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_ac7:
	/* 0xac7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ac9:
	/* 0xac9: js     ad8 <generic_retuprobe_event+0xad8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_ad8;
	}
x86_l_acb:
	/* 0xacb: mov    DWORD PTR [r13+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_acf:
	/* 0xacf: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_ad3:
	/* 0xad3: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_ad5:
	/* 0xad5: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_ad8:
	/* 0xad8: add    r15,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_adb:
	/* 0xadb: mov    DWORD PTR [r13+0x0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_adf:
	/* 0xadf: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_ae2:
	/* 0xae2: jmp    29f3 <generic_retuprobe_event+0x29f3> */
	return 10739ULL;
x86_l_ae7:
	/* 0xae7: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_aeb:
	/* 0xaeb: jg     c86 <generic_retuprobe_event+0xc86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_c86;
	}
x86_l_af1:
	/* 0xaf1: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_af5:
	/* 0xaf5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_afa:
	/* 0xafa: jle    eaf <generic_retuprobe_event+0xeaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3759ULL;
	}
x86_l_b00:
	/* 0xb00: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_b04:
	/* 0xb04: je     13c1 <generic_retuprobe_event+0x13c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5057ULL;
	}
x86_l_b0a:
	/* 0xb0a: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_b0e:
	/* 0xb0e: je     ce3 <generic_retuprobe_event+0xce3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ce3;
	}
x86_l_b14:
	/* 0xb14: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b1c:
	/* 0xb1c: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_b20:
	/* 0xb20: jne    a1c <generic_retuprobe_event+0xa1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a1c;
	}
x86_l_b26:
	/* 0xb26: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b2b:
	/* 0xb2b: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b30:
	/* 0xb30: mov    QWORD PTR [rcx+0xc4],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_b37:
	/* 0xb37: lea    rdi,[rcx+0xc2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_b3e:
	/* 0xb3e: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b42:
	/* 0xb42: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b47:
	/* 0xb47: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_b4c:
	/* 0xb4c: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_b4f:
	/* 0xb4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b51:
	/* 0xb51: lea    rdi,[rbx+0xd6] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 214ULL);
x86_l_b58:
	/* 0xb58: lea    rdx,[r13+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_b5c:
	/* 0xb5c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b61:
	/* 0xb61: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_b66:
	/* 0xb66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b68:
	/* 0xb68: lea    rdi,[rbx+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_b6f:
	/* 0xb6f: lea    rdx,[r13+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_b76:
	/* 0xb76: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b7b:
	/* 0xb7b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_b80:
	/* 0xb80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b82:
	/* 0xb82: lea    rdi,[rbx+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_b89:
	/* 0xb89: lea    rdx,[r13+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_b90:
	/* 0xb90: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b95:
	/* 0xb95: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_b9a:
	/* 0xb9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b9c:
	/* 0xb9c: lea    rdi,[rbx+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_ba3:
	/* 0xba3: lea    rdx,[r13+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_baa:
	/* 0xbaa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_baf:
	/* 0xbaf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_bb4:
	/* 0xbb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb6:
	/* 0xbb6: lea    rdi,[rbx+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_bbd:
	/* 0xbbd: lea    rdx,[r13+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_bc4:
	/* 0xbc4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bc9:
	/* 0xbc9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_bce:
	/* 0xbce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd0:
	/* 0xbd0: lea    r12,[rbx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_bd7:
	/* 0xbd7: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bdc:
	/* 0xbdc: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_be3:
	/* 0xbe3: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_beb:
	/* 0xbeb: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_bf3:
	/* 0xbf3: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_bfb:
	/* 0xbfb: movzx  eax,WORD PTR [rbx+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_c02:
	/* 0xc02: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_c05:
	/* 0xc05: je     1d6d <generic_retuprobe_event+0x1d6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7533ULL;
	}
x86_l_c0b:
	/* 0xc0b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c0e:
	/* 0xc0e: jne    1d90 <generic_retuprobe_event+0x1d90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7568ULL;
	}
x86_l_c14:
	/* 0xc14: lea    rdx,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c18:
	/* 0xc18: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c1d:
	/* 0xc1d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c22:
	/* 0xc22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c24:
	/* 0xc24: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c29:
	/* 0xc29: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_c2c:
	/* 0xc2c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c31:
	/* 0xc31: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_c34:
	/* 0xc34: jmp    1d8e <generic_retuprobe_event+0x1d8e> */
	return 7566ULL;
x86_l_c39:
	/* 0xc39: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_c3d:
	/* 0xc3d: add    r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c40:
	/* 0xc40: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c45:
	/* 0xc45: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_c48:
	/* 0xc48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c4a:
	/* 0xc4a: mov    QWORD PTR [rsp+0x70],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c4f:
	/* 0xc4f: jmp    94a <generic_retuprobe_event+0x94a> */
	goto x86_l_94a;
x86_l_c54:
	/* 0xc54: cmp    r12d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 28ULL);
x86_l_c58:
	/* 0xc58: jg     e99 <generic_retuprobe_event+0xe99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3737ULL;
	}
x86_l_c5e:
	/* 0xc5e: cmp    r12d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 17ULL);
x86_l_c62:
	/* 0xc62: je     123d <generic_retuprobe_event+0x123d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4669ULL;
	}
x86_l_c68:
	/* 0xc68: cmp    r12d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 25ULL);
x86_l_c6c:
	/* 0xc6c: je     1302 <generic_retuprobe_event+0x1302> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4866ULL;
	}
x86_l_c72:
	/* 0xc72: cmp    r12d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 28ULL);
x86_l_c76:
	/* 0xc76: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c7b:
	/* 0xc7b: je     ebf <generic_retuprobe_event+0xebf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3775ULL;
	}
x86_l_c81:
	/* 0xc81: jmp    a1c <generic_retuprobe_event+0xa1c> */
	goto x86_l_a1c;
x86_l_c86:
	/* 0xc86: lea    eax,[r12-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_c8b:
	/* 0xc8b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c8e:
	/* 0xc8e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c93:
	/* 0xc93: jb     ebf <generic_retuprobe_event+0xebf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3775ULL;
	}
x86_l_c99:
	/* 0xc99: lea    eax,[r12-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_c9e:
	/* 0xc9e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ca1:
	/* 0xca1: jb     ee4 <generic_retuprobe_event+0xee4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3812ULL;
	}
x86_l_ca7:
	/* 0xca7: cmp    r12d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 14ULL);
x86_l_cab:
	/* 0xcab: jne    a1c <generic_retuprobe_event+0xa1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a1c;
	}
x86_l_cb1:
	/* 0xcb1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cb6:
	/* 0xcb6: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_cbb:
	/* 0xcbb: lea    r12,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cc0:
	/* 0xcc0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cc5:
	/* 0xcc5: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_cc8:
	/* 0xcc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cca:
	/* 0xcca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ccf:
	/* 0xccf: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_cd4:
	/* 0xcd4: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_cd7:
	/* 0xcd7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cdc:
	/* 0xcdc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cde:
	/* 0xcde: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ce3:
	/* 0xce3: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ce8:
	/* 0xce8: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_ceb:
	/* 0xceb: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_cf2:
	/* 0xcf2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_cf7:
	/* 0xcf7: mov    esi,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4097ULL);
x86_l_cfc:
	/* 0xcfc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cfe:
	/* 0xcfe: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_d01:
	/* 0xd01: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d04:
	/* 0xd04: js     1592 <generic_retuprobe_event+0x1592> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5522ULL;
	}
x86_l_d0a:
	/* 0xd0a: lea    eax,[rbp-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_d0d:
	/* 0xd0d: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d12:
	/* 0xd12: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d14:
	/* 0xd14: add    rbp,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_d18:
	/* 0xd18: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d1d:
	/* 0xd1d: jmp    a1c <generic_retuprobe_event+0xa1c> */
	goto x86_l_a1c;
x86_l_d22:
	/* 0xd22: cmp    r12d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 32ULL);
x86_l_d26:
	/* 0xd26: jle    1056 <generic_retuprobe_event+0x1056> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4182ULL;
	}
x86_l_d2c:
	/* 0xd2c: lea    edx,[r12-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_d31:
	/* 0xd31: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_d34:
	/* 0xd34: jae    f09 <generic_retuprobe_event+0xf09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3849ULL;
	}
x86_l_d3a:
	/* 0xd3a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d3f:
	/* 0xd3f: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d44:
	/* 0xd44: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d49:
	/* 0xd49: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_d4c:
	/* 0xd4c: jmp    ed3 <generic_retuprobe_event+0xed3> */
	return 3795ULL;
x86_l_d51:
	/* 0xd51: cmp    r12d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 39ULL);
x86_l_d55:
	/* 0xd55: je     1564 <generic_retuprobe_event+0x1564> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5476ULL;
	}
x86_l_d5b:
	/* 0xd5b: cmp    r12d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 40ULL);
x86_l_d5f:
	/* 0xd5f: je     159c <generic_retuprobe_event+0x159c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5532ULL;
	}
x86_l_d65:
	/* 0xd65: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_d69:
	/* 0xd69: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d6e:
	/* 0xd6e: jne    a1c <generic_retuprobe_event+0xa1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a1c;
	}
x86_l_d74:
	/* 0xd74: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_d77:
	/* 0xd77: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d7c:
	/* 0xd7c: mov    BYTE PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_d81:
	/* 0xd81: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d86:
	/* 0xd86: mov    QWORD PTR [rdi+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_d8e:
	/* 0xd8e: mov    QWORD PTR [rdi+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_d96:
	/* 0xd96: mov    QWORD PTR [rdi+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_d9e:
	/* 0xd9e: mov    QWORD PTR [rdi+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_da6:
	/* 0xda6: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_dae:
	/* 0xdae: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_db6:
	/* 0xdb6: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_dbe:
	/* 0xdbe: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_dc6:
	/* 0xdc6: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_dce:
	/* 0xdce: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_dd6:
	/* 0xdd6: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_dde:
	/* 0xdde: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_de6:
	/* 0xde6: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_dee:
	/* 0xdee: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_df5:
	/* 0xdf5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_dfa:
	/* 0xdfa: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_dff:
	/* 0xdff: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_e02:
	/* 0xe02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e04:
	/* 0xe04: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e07:
	/* 0xe07: js     1f67 <generic_retuprobe_event+0x1f67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8039ULL;
	}
x86_l_e0d:
	/* 0xe0d: lea    r13,[r12+0x2] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_e12:
	/* 0xe12: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e17:
	/* 0xe17: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e1c:
	/* 0xe1c: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_e21:
	/* 0xe21: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_e24:
	/* 0xe24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e26:
	/* 0xe26: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e29:
	/* 0xe29: js     1f67 <generic_retuprobe_event+0x1f67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8039ULL;
	}
x86_l_e2f:
	/* 0xe2f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e34:
	/* 0xe34: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_e37:
	/* 0xe37: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_e3e:
	/* 0xe3e: cmp    BYTE PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_e43:
	/* 0xe43: sete   BYTE PTR [rax+0x9e] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_RAX, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 158ULL);
x86_l_e4a:
	/* 0xe4a: je     1f40 <generic_retuprobe_event+0x1f40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8000ULL;
	}
x86_l_e50:
	/* 0xe50: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_e55:
	/* 0xe55: mov    esi,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 108ULL);
x86_l_e5a:
	/* 0xe5a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_e5d:
	/* 0xe5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 3679ULL;
}

static __noinline __u64 tetragon_bpf_multi_retuprobe_v61_generic_retuprobe_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3679ULL: goto x86_l_e5f;
	case 3681ULL: goto x86_l_e61;
	case 3687ULL: goto x86_l_e67;
	case 3689ULL: goto x86_l_e69;
	case 3694ULL: goto x86_l_e6e;
	case 3698ULL: goto x86_l_e72;
	case 3704ULL: goto x86_l_e78;
	case 3708ULL: goto x86_l_e7c;
	case 3714ULL: goto x86_l_e82;
	case 3718ULL: goto x86_l_e86;
	case 3724ULL: goto x86_l_e8c;
	case 3735ULL: goto x86_l_e97;
	case 3737ULL: goto x86_l_e99;
	case 3742ULL: goto x86_l_e9e;
	case 3747ULL: goto x86_l_ea3;
	case 3752ULL: goto x86_l_ea8;
	case 3757ULL: goto x86_l_ead;
	case 3759ULL: goto x86_l_eaf;
	case 3763ULL: goto x86_l_eb3;
	case 3765ULL: goto x86_l_eb5;
	case 3769ULL: goto x86_l_eb9;
	case 3775ULL: goto x86_l_ebf;
	case 3780ULL: goto x86_l_ec4;
	case 3785ULL: goto x86_l_ec9;
	case 3790ULL: goto x86_l_ece;
	case 3795ULL: goto x86_l_ed3;
	case 3797ULL: goto x86_l_ed5;
	case 3802ULL: goto x86_l_eda;
	case 3807ULL: goto x86_l_edf;
	case 3812ULL: goto x86_l_ee4;
	case 3817ULL: goto x86_l_ee9;
	case 3822ULL: goto x86_l_eee;
	case 3827ULL: goto x86_l_ef3;
	case 3832ULL: goto x86_l_ef8;
	case 3837ULL: goto x86_l_efd;
	case 3839ULL: goto x86_l_eff;
	case 3844ULL: goto x86_l_f04;
	case 3849ULL: goto x86_l_f09;
	case 3853ULL: goto x86_l_f0d;
	case 3859ULL: goto x86_l_f13;
	case 3863ULL: goto x86_l_f17;
	case 3869ULL: goto x86_l_f1d;
	case 3872ULL: goto x86_l_f20;
	case 3877ULL: goto x86_l_f25;
	case 3881ULL: goto x86_l_f29;
	case 3886ULL: goto x86_l_f2e;
	case 3891ULL: goto x86_l_f33;
	case 3896ULL: goto x86_l_f38;
	case 3898ULL: goto x86_l_f3a;
	case 3903ULL: goto x86_l_f3f;
	case 3906ULL: goto x86_l_f42;
	case 3912ULL: goto x86_l_f48;
	case 3917ULL: goto x86_l_f4d;
	case 3924ULL: goto x86_l_f54;
	case 3931ULL: goto x86_l_f5b;
	case 3935ULL: goto x86_l_f5f;
	case 3940ULL: goto x86_l_f64;
	case 3945ULL: goto x86_l_f69;
	case 3947ULL: goto x86_l_f6b;
	case 3954ULL: goto x86_l_f72;
	case 3958ULL: goto x86_l_f76;
	case 3963ULL: goto x86_l_f7b;
	case 3968ULL: goto x86_l_f80;
	case 3970ULL: goto x86_l_f82;
	case 3977ULL: goto x86_l_f89;
	case 3984ULL: goto x86_l_f90;
	case 3989ULL: goto x86_l_f95;
	case 3994ULL: goto x86_l_f9a;
	case 3996ULL: goto x86_l_f9c;
	case 4003ULL: goto x86_l_fa3;
	case 4010ULL: goto x86_l_faa;
	case 4015ULL: goto x86_l_faf;
	case 4020ULL: goto x86_l_fb4;
	case 4022ULL: goto x86_l_fb6;
	case 4029ULL: goto x86_l_fbd;
	case 4036ULL: goto x86_l_fc4;
	case 4041ULL: goto x86_l_fc9;
	case 4046ULL: goto x86_l_fce;
	case 4048ULL: goto x86_l_fd0;
	case 4055ULL: goto x86_l_fd7;
	case 4062ULL: goto x86_l_fde;
	case 4067ULL: goto x86_l_fe3;
	case 4072ULL: goto x86_l_fe8;
	case 4074ULL: goto x86_l_fea;
	case 4081ULL: goto x86_l_ff1;
	case 4086ULL: goto x86_l_ff6;
	case 4093ULL: goto x86_l_ffd;
	case 4101ULL: goto x86_l_1005;
	case 4109ULL: goto x86_l_100d;
	case 4112ULL: goto x86_l_1010;
	case 4120ULL: goto x86_l_1018;
	case 4127ULL: goto x86_l_101f;
	case 4130ULL: goto x86_l_1022;
	case 4136ULL: goto x86_l_1028;
	case 4139ULL: goto x86_l_102b;
	case 4145ULL: goto x86_l_1031;
	case 4149ULL: goto x86_l_1035;
	case 4154ULL: goto x86_l_103a;
	case 4159ULL: goto x86_l_103f;
	case 4161ULL: goto x86_l_1041;
	case 4166ULL: goto x86_l_1046;
	case 4169ULL: goto x86_l_1049;
	case 4174ULL: goto x86_l_104e;
	case 4177ULL: goto x86_l_1051;
	case 4182ULL: goto x86_l_1056;
	case 4186ULL: goto x86_l_105a;
	case 4192ULL: goto x86_l_1060;
	case 4196ULL: goto x86_l_1064;
	case 4202ULL: goto x86_l_106a;
	case 4207ULL: goto x86_l_106f;
	case 4215ULL: goto x86_l_1077;
	case 4223ULL: goto x86_l_107f;
	case 4231ULL: goto x86_l_1087;
	case 4239ULL: goto x86_l_108f;
	case 4247ULL: goto x86_l_1097;
	case 4255ULL: goto x86_l_109f;
	case 4263ULL: goto x86_l_10a7;
	case 4271ULL: goto x86_l_10af;
	case 4279ULL: goto x86_l_10b7;
	case 4286ULL: goto x86_l_10be;
	case 4293ULL: goto x86_l_10c5;
	case 4297ULL: goto x86_l_10c9;
	case 4302ULL: goto x86_l_10ce;
	case 4307ULL: goto x86_l_10d3;
	case 4309ULL: goto x86_l_10d5;
	case 4312ULL: goto x86_l_10d8;
	case 4318ULL: goto x86_l_10de;
	case 4323ULL: goto x86_l_10e3;
	case 4326ULL: goto x86_l_10e6;
	case 4333ULL: goto x86_l_10ed;
	case 4340ULL: goto x86_l_10f4;
	case 4345ULL: goto x86_l_10f9;
	case 4350ULL: goto x86_l_10fe;
	case 4352ULL: goto x86_l_1100;
	case 4355ULL: goto x86_l_1103;
	case 4360ULL: goto x86_l_1108;
	case 4365ULL: goto x86_l_110d;
	case 4369ULL: goto x86_l_1111;
	case 4375ULL: goto x86_l_1117;
	case 4379ULL: goto x86_l_111b;
	case 4385ULL: goto x86_l_1121;
	case 4390ULL: goto x86_l_1126;
	case 4392ULL: goto x86_l_1128;
	case 4397ULL: goto x86_l_112d;
	case 4399ULL: goto x86_l_112f;
	case 4402ULL: goto x86_l_1132;
	case 4407ULL: goto x86_l_1137;
	case 4411ULL: goto x86_l_113b;
	case 4417ULL: goto x86_l_1141;
	case 4421ULL: goto x86_l_1145;
	case 4427ULL: goto x86_l_114b;
	case 4436ULL: goto x86_l_1154;
	case 4443ULL: goto x86_l_115b;
	case 4450ULL: goto x86_l_1162;
	case 4455ULL: goto x86_l_1167;
	case 4460ULL: goto x86_l_116c;
	case 4465ULL: goto x86_l_1171;
	case 4467ULL: goto x86_l_1173;
	case 4472ULL: goto x86_l_1178;
	case 4477ULL: goto x86_l_117d;
	case 4482ULL: goto x86_l_1182;
	case 4487ULL: goto x86_l_1187;
	case 4489ULL: goto x86_l_1189;
	case 4494ULL: goto x86_l_118e;
	case 4501ULL: goto x86_l_1195;
	case 4506ULL: goto x86_l_119a;
	case 4511ULL: goto x86_l_119f;
	case 4514ULL: goto x86_l_11a2;
	case 4516ULL: goto x86_l_11a4;
	case 4521ULL: goto x86_l_11a9;
	case 4528ULL: goto x86_l_11b0;
	case 4535ULL: goto x86_l_11b7;
	case 4540ULL: goto x86_l_11bc;
	case 4545ULL: goto x86_l_11c1;
	case 4547ULL: goto x86_l_11c3;
	case 4552ULL: goto x86_l_11c8;
	case 4559ULL: goto x86_l_11cf;
	case 4566ULL: goto x86_l_11d6;
	case 4571ULL: goto x86_l_11db;
	case 4576ULL: goto x86_l_11e0;
	case 4578ULL: goto x86_l_11e2;
	case 4583ULL: goto x86_l_11e7;
	case 4588ULL: goto x86_l_11ec;
	case 4593ULL: goto x86_l_11f1;
	case 4597ULL: goto x86_l_11f5;
	case 4602ULL: goto x86_l_11fa;
	case 4608ULL: goto x86_l_1200;
	case 4613ULL: goto x86_l_1205;
	case 4616ULL: goto x86_l_1208;
	case 4624ULL: goto x86_l_1210;
	case 4627ULL: goto x86_l_1213;
	case 4633ULL: goto x86_l_1219;
	case 4636ULL: goto x86_l_121c;
	case 4643ULL: goto x86_l_1223;
	case 4645ULL: goto x86_l_1225;
	case 4650ULL: goto x86_l_122a;
	case 4652ULL: goto x86_l_122c;
	case 4655ULL: goto x86_l_122f;
	case 4658ULL: goto x86_l_1232;
	case 4664ULL: goto x86_l_1238;
	case 4669ULL: goto x86_l_123d;
	case 4678ULL: goto x86_l_1246;
	case 4687ULL: goto x86_l_124f;
	case 4692ULL: goto x86_l_1254;
	case 4694ULL: goto x86_l_1256;
	case 4698ULL: goto x86_l_125a;
	case 4703ULL: goto x86_l_125f;
	case 4708ULL: goto x86_l_1264;
	case 4713ULL: goto x86_l_1269;
	case 4718ULL: goto x86_l_126e;
	case 4723ULL: goto x86_l_1273;
	case 4725ULL: goto x86_l_1275;
	case 4729ULL: goto x86_l_1279;
	case 4733ULL: goto x86_l_127d;
	case 4738ULL: goto x86_l_1282;
	case 4745ULL: goto x86_l_1289;
	case 4750ULL: goto x86_l_128e;
	case 4752ULL: goto x86_l_1290;
	case 4755ULL: goto x86_l_1293;
	case 4761ULL: goto x86_l_1299;
	case 4763ULL: goto x86_l_129b;
	case 4768ULL: goto x86_l_12a0;
	case 4773ULL: goto x86_l_12a5;
	case 4778ULL: goto x86_l_12aa;
	case 4783ULL: goto x86_l_12af;
	case 4786ULL: goto x86_l_12b2;
	case 4788ULL: goto x86_l_12b4;
	case 4794ULL: goto x86_l_12ba;
	case 4799ULL: goto x86_l_12bf;
	case 4806ULL: goto x86_l_12c6;
	case 4809ULL: goto x86_l_12c9;
	case 4814ULL: goto x86_l_12ce;
	case 4817ULL: goto x86_l_12d1;
	case 4819ULL: goto x86_l_12d3;
	case 4824ULL: goto x86_l_12d8;
	case 4828ULL: goto x86_l_12dc;
	case 4832ULL: goto x86_l_12e0;
	case 4836ULL: goto x86_l_12e4;
	case 4840ULL: goto x86_l_12e8;
	case 4845ULL: goto x86_l_12ed;
	case 4850ULL: goto x86_l_12f2;
	case 4852ULL: goto x86_l_12f4;
	case 4856ULL: goto x86_l_12f8;
	case 4861ULL: goto x86_l_12fd;
	case 4866ULL: goto x86_l_1302;
	case 4871ULL: goto x86_l_1307;
	case 4874ULL: goto x86_l_130a;
	case 4879ULL: goto x86_l_130f;
	case 4884ULL: goto x86_l_1314;
	case 4892ULL: goto x86_l_131c;
	case 4897ULL: goto x86_l_1321;
	case 4900ULL: goto x86_l_1324;
	case 4902ULL: goto x86_l_1326;
	case 4910ULL: goto x86_l_132e;
	case 4912ULL: goto x86_l_1330;
	case 4918ULL: goto x86_l_1336;
	case 4921ULL: goto x86_l_1339;
	case 4927ULL: goto x86_l_133f;
	case 4931ULL: goto x86_l_1343;
	case 4936ULL: goto x86_l_1348;
	case 4941ULL: goto x86_l_134d;
	case 4946ULL: goto x86_l_1352;
	case 4951ULL: goto x86_l_1357;
	case 4954ULL: goto x86_l_135a;
	case 4956ULL: goto x86_l_135c;
	case 4961ULL: goto x86_l_1361;
	case 4966ULL: goto x86_l_1366;
	case 4971ULL: goto x86_l_136b;
	case 4976ULL: goto x86_l_1370;
	case 4978ULL: goto x86_l_1372;
	case 4983ULL: goto x86_l_1377;
	case 4987ULL: goto x86_l_137b;
	case 4992ULL: goto x86_l_1380;
	case 5000ULL: goto x86_l_1388;
	case 5005ULL: goto x86_l_138d;
	case 5007ULL: goto x86_l_138f;
	case 5012ULL: goto x86_l_1394;
	case 5020ULL: goto x86_l_139c;
	case 5027ULL: goto x86_l_13a3;
	case 5033ULL: goto x86_l_13a9;
	case 5037ULL: goto x86_l_13ad;
	case 5040ULL: goto x86_l_13b0;
	case 5047ULL: goto x86_l_13b7;
	case 5052ULL: goto x86_l_13bc;
	case 5057ULL: goto x86_l_13c1;
	case 5062ULL: goto x86_l_13c6;
	case 5069ULL: goto x86_l_13cd;
	case 5076ULL: goto x86_l_13d4;
	case 5081ULL: goto x86_l_13d9;
	case 5086ULL: goto x86_l_13de;
	case 5089ULL: goto x86_l_13e1;
	case 5091ULL: goto x86_l_13e3;
	case 5098ULL: goto x86_l_13ea;
	case 5102ULL: goto x86_l_13ee;
	case 5107ULL: goto x86_l_13f3;
	case 5112ULL: goto x86_l_13f8;
	case 5114ULL: goto x86_l_13fa;
	case 5121ULL: goto x86_l_1401;
	case 5128ULL: goto x86_l_1408;
	case 5133ULL: goto x86_l_140d;
	case 5138ULL: goto x86_l_1412;
	case 5140ULL: goto x86_l_1414;
	case 5147ULL: goto x86_l_141b;
	case 5154ULL: goto x86_l_1422;
	case 5159ULL: goto x86_l_1427;
	case 5164ULL: goto x86_l_142c;
	case 5166ULL: goto x86_l_142e;
	case 5175ULL: goto x86_l_1437;
	case 5182ULL: goto x86_l_143e;
	case 5187ULL: goto x86_l_1443;
	case 5192ULL: goto x86_l_1448;
	case 5197ULL: goto x86_l_144d;
	case 5199ULL: goto x86_l_144f;
	case 5206ULL: goto x86_l_1456;
	case 5211ULL: goto x86_l_145b;
	case 5219ULL: goto x86_l_1463;
	case 5224ULL: goto x86_l_1468;
	case 5226ULL: goto x86_l_146a;
	case 5235ULL: goto x86_l_1473;
	case 5240ULL: goto x86_l_1478;
	case 5245ULL: goto x86_l_147d;
	case 5253ULL: goto x86_l_1485;
	case 5258ULL: goto x86_l_148a;
	case 5261ULL: goto x86_l_148d;
	case 5263ULL: goto x86_l_148f;
	case 5271ULL: goto x86_l_1497;
	case 5274ULL: goto x86_l_149a;
	case 5277ULL: goto x86_l_149d;
	case 5283ULL: goto x86_l_14a3;
	case 5286ULL: goto x86_l_14a6;
	case 5291ULL: goto x86_l_14ab;
	case 5297ULL: goto x86_l_14b1;
	case 5302ULL: goto x86_l_14b6;
	case 5307ULL: goto x86_l_14bb;
	case 5312ULL: goto x86_l_14c0;
	case 5320ULL: goto x86_l_14c8;
	case 5325ULL: goto x86_l_14cd;
	case 5327ULL: goto x86_l_14cf;
	case 5335ULL: goto x86_l_14d7;
	case 5340ULL: goto x86_l_14dc;
	case 5347ULL: goto x86_l_14e3;
	case 5356ULL: goto x86_l_14ec;
	case 5363ULL: goto x86_l_14f3;
	case 5368ULL: goto x86_l_14f8;
	case 5373ULL: goto x86_l_14fd;
	case 5380ULL: goto x86_l_1504;
	case 5388ULL: goto x86_l_150c;
	case 5396ULL: goto x86_l_1514;
	case 5404ULL: goto x86_l_151c;
	case 5409ULL: goto x86_l_1521;
	case 5414ULL: goto x86_l_1526;
	case 5416ULL: goto x86_l_1528;
	case 5420ULL: goto x86_l_152c;
	case 5425ULL: goto x86_l_1531;
	case 5428ULL: goto x86_l_1534;
	case 5433ULL: goto x86_l_1539;
	case 5436ULL: goto x86_l_153c;
	case 5438ULL: goto x86_l_153e;
	case 5446ULL: goto x86_l_1546;
	case 5453ULL: goto x86_l_154d;
	case 5458ULL: goto x86_l_1552;
	case 5466ULL: goto x86_l_155a;
	case 5471ULL: goto x86_l_155f;
	case 5476ULL: goto x86_l_1564;
	case 5481ULL: goto x86_l_1569;
	case 5486ULL: goto x86_l_156e;
	case 5491ULL: goto x86_l_1573;
	case 5498ULL: goto x86_l_157a;
	case 5503ULL: goto x86_l_157f;
	case 5508ULL: goto x86_l_1584;
	case 5510ULL: goto x86_l_1586;
	case 5513ULL: goto x86_l_1589;
	case 5516ULL: goto x86_l_158c;
	case 5522ULL: goto x86_l_1592;
	case 5527ULL: goto x86_l_1597;
	case 5532ULL: goto x86_l_159c;
	case 5537ULL: goto x86_l_15a1;
	case 5545ULL: goto x86_l_15a9;
	case 5553ULL: goto x86_l_15b1;
	case 5560ULL: goto x86_l_15b8;
	case 5565ULL: goto x86_l_15bd;
	case 5570ULL: goto x86_l_15c2;
	case 5573ULL: goto x86_l_15c5;
	case 5576ULL: goto x86_l_15c8;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e5f:
	/* 0xe5f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e61:
	/* 0xe61: js     1f67 <generic_retuprobe_event+0x1f67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8039ULL;
	}
x86_l_e67:
	/* 0xe67: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_e69:
	/* 0xe69: jmp    1f5c <generic_retuprobe_event+0x1f5c> */
	return 8028ULL;
x86_l_e6e:
	/* 0xe6e: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_e72:
	/* 0xe72: jg     110d <generic_retuprobe_event+0x110d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_110d;
	}
x86_l_e78:
	/* 0xe78: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_e7c:
	/* 0xe7c: je     1705 <generic_retuprobe_event+0x1705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5893ULL;
	}
x86_l_e82:
	/* 0xe82: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_e86:
	/* 0xe86: jne    a1c <generic_retuprobe_event+0xa1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2588ULL;
	}
x86_l_e8c:
	/* 0xe8c: mov    QWORD PTR [rax+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_e97:
	/* 0xe97: jmp    eda <generic_retuprobe_event+0xeda> */
	goto x86_l_eda;
x86_l_e99:
	/* 0xe99: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_e9e:
	/* 0xe9e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ea3:
	/* 0xea3: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ea8:
	/* 0xea8: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_ead:
	/* 0xead: jmp    efd <generic_retuprobe_event+0xefd> */
	goto x86_l_efd;
x86_l_eaf:
	/* 0xeaf: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_eb3:
	/* 0xeb3: je     ee4 <generic_retuprobe_event+0xee4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ee4;
	}
x86_l_eb5:
	/* 0xeb5: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_eb9:
	/* 0xeb9: jne    a1c <generic_retuprobe_event+0xa1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2588ULL;
	}
x86_l_ebf:
	/* 0xebf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ec4:
	/* 0xec4: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ec9:
	/* 0xec9: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ece:
	/* 0xece: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ed3:
	/* 0xed3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed5:
	/* 0xed5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_eda:
	/* 0xeda: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_edf:
	/* 0xedf: jmp    a1c <generic_retuprobe_event+0xa1c> */
	return 2588ULL;
x86_l_ee4:
	/* 0xee4: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_ee9:
	/* 0xee9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_eee:
	/* 0xeee: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ef3:
	/* 0xef3: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ef8:
	/* 0xef8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_efd:
	/* 0xefd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eff:
	/* 0xeff: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f04:
	/* 0xf04: jmp    a1c <generic_retuprobe_event+0xa1c> */
	return 2588ULL;
x86_l_f09:
	/* 0xf09: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_f0d:
	/* 0xf0d: je     1b05 <generic_retuprobe_event+0x1b05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6917ULL;
	}
x86_l_f13:
	/* 0xf13: cmp    r12d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 41ULL);
x86_l_f17:
	/* 0xf17: jne    a1c <generic_retuprobe_event+0xa1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2588ULL;
	}
x86_l_f1d:
	/* 0xf1d: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_f20:
	/* 0xf20: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f25:
	/* 0xf25: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f29:
	/* 0xf29: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f2e:
	/* 0xf2e: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f33:
	/* 0xf33: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f38:
	/* 0xf38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f3a:
	/* 0xf3a: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f3f:
	/* 0xf3f: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_f42:
	/* 0xf42: je     1fe8 <generic_retuprobe_event+0x1fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8168ULL;
	}
x86_l_f48:
	/* 0xf48: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f4d:
	/* 0xf4d: mov    QWORD PTR [rbx+0xc4],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_f54:
	/* 0xf54: lea    rdi,[rbx+0xc2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_f5b:
	/* 0xf5b: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f5f:
	/* 0xf5f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f64:
	/* 0xf64: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_f69:
	/* 0xf69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f6b:
	/* 0xf6b: lea    rdi,[rbx+0xd6] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 214ULL);
x86_l_f72:
	/* 0xf72: lea    rdx,[r13+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_f76:
	/* 0xf76: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f7b:
	/* 0xf7b: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_f80:
	/* 0xf80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f82:
	/* 0xf82: lea    rdi,[rbx+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_f89:
	/* 0xf89: lea    rdx,[r13+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_f90:
	/* 0xf90: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f95:
	/* 0xf95: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_f9a:
	/* 0xf9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f9c:
	/* 0xf9c: lea    rdi,[rbx+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_fa3:
	/* 0xfa3: lea    rdx,[r13+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_faa:
	/* 0xfaa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_faf:
	/* 0xfaf: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_fb4:
	/* 0xfb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb6:
	/* 0xfb6: lea    rdi,[rbx+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_fbd:
	/* 0xfbd: lea    rdx,[r13+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_fc4:
	/* 0xfc4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fc9:
	/* 0xfc9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fce:
	/* 0xfce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fd0:
	/* 0xfd0: lea    rdi,[rbx+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_fd7:
	/* 0xfd7: lea    rdx,[r13+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_fde:
	/* 0xfde: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fe3:
	/* 0xfe3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fe8:
	/* 0xfe8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fea:
	/* 0xfea: lea    r12,[rbx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_ff1:
	/* 0xff1: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ff6:
	/* 0xff6: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ffd:
	/* 0xffd: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1005:
	/* 0x1005: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_100d:
	/* 0x100d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1010:
	/* 0x1010: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1018:
	/* 0x1018: movzx  eax,WORD PTR [rbx+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_101f:
	/* 0x101f: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1022:
	/* 0x1022: je     1f79 <generic_retuprobe_event+0x1f79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8057ULL;
	}
x86_l_1028:
	/* 0x1028: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_102b:
	/* 0x102b: jne    1f9c <generic_retuprobe_event+0x1f9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8092ULL;
	}
x86_l_1031:
	/* 0x1031: lea    rdx,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1035:
	/* 0x1035: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_103a:
	/* 0x103a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_103f:
	/* 0x103f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1041:
	/* 0x1041: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1046:
	/* 0x1046: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1049:
	/* 0x1049: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_104e:
	/* 0x104e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1051:
	/* 0x1051: jmp    1f9a <generic_retuprobe_event+0x1f9a> */
	return 8090ULL;
x86_l_1056:
	/* 0x1056: cmp    r12d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 26ULL);
x86_l_105a:
	/* 0x105a: je     1b93 <generic_retuprobe_event+0x1b93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7059ULL;
	}
x86_l_1060:
	/* 0x1060: cmp    r12d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 27ULL);
x86_l_1064:
	/* 0x1064: jne    a1c <generic_retuprobe_event+0xa1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2588ULL;
	}
x86_l_106a:
	/* 0x106a: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_106f:
	/* 0x106f: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1077:
	/* 0x1077: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_107f:
	/* 0x107f: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1087:
	/* 0x1087: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_108f:
	/* 0x108f: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1097:
	/* 0x1097: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_109f:
	/* 0x109f: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_10a7:
	/* 0x10a7: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_10af:
	/* 0x10af: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_10b7:
	/* 0x10b7: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10be:
	/* 0x10be: lea    rdi,[rcx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_10c5:
	/* 0x10c5: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10c9:
	/* 0x10c9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_10ce:
	/* 0x10ce: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_10d3:
	/* 0x10d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d5:
	/* 0x10d5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10d8:
	/* 0x10d8: js     1f34 <generic_retuprobe_event+0x1f34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7988ULL;
	}
x86_l_10de:
	/* 0x10de: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10e3:
	/* 0x10e3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10e6:
	/* 0x10e6: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_10ed:
	/* 0x10ed: lea    rdx,[r13+0x348] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 840ULL);
x86_l_10f4:
	/* 0x10f4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10f9:
	/* 0x10f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10fe:
	/* 0x10fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1100:
	/* 0x1100: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_1103:
	/* 0x1103: mov    ebp,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 80ULL);
x86_l_1108:
	/* 0x1108: jmp    a17 <generic_retuprobe_event+0xa17> */
	return 2583ULL;
x86_l_110d:
	/* 0x110d: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_1111:
	/* 0x1111: je     1799 <generic_retuprobe_event+0x1799> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6041ULL;
	}
x86_l_1117:
	/* 0x1117: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_111b:
	/* 0x111b: jne    a1c <generic_retuprobe_event+0xa1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2588ULL;
	}
x86_l_1121:
	/* 0x1121: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1126:
	/* 0x1126: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1128:
	/* 0x1128: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_112d:
	/* 0x112d: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_112f:
	/* 0x112f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1132:
	/* 0x1132: jmp    efd <generic_retuprobe_event+0xefd> */
	goto x86_l_efd;
x86_l_1137:
	/* 0x1137: cmp    r12d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 19ULL);
x86_l_113b:
	/* 0x113b: je     1abe <generic_retuprobe_event+0x1abe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6846ULL;
	}
x86_l_1141:
	/* 0x1141: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_1145:
	/* 0x1145: jne    a1c <generic_retuprobe_event+0xa1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2588ULL;
	}
x86_l_114b:
	/* 0x114b: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1154:
	/* 0x1154: lea    r12,[r13+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_115b:
	/* 0x115b: lea    rdx,[r13+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_1162:
	/* 0x1162: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1167:
	/* 0x1167: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_116c:
	/* 0x116c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1171:
	/* 0x1171: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1173:
	/* 0x1173: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1178:
	/* 0x1178: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_117d:
	/* 0x117d: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1182:
	/* 0x1182: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_1187:
	/* 0x1187: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1189:
	/* 0x1189: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_118e:
	/* 0x118e: lea    rdi,[rax+0x12c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 300ULL);
x86_l_1195:
	/* 0x1195: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_119a:
	/* 0x119a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_119f:
	/* 0x119f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_11a2:
	/* 0x11a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11a4:
	/* 0x11a4: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11a9:
	/* 0x11a9: lea    rdi,[rax+0x11c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 284ULL);
x86_l_11b0:
	/* 0x11b0: lea    rdx,[r13+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_11b7:
	/* 0x11b7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11bc:
	/* 0x11bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11c1:
	/* 0x11c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11c3:
	/* 0x11c3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11c8:
	/* 0x11c8: add    rdi,0x124 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 292ULL);
x86_l_11cf:
	/* 0x11cf: lea    rdx,[r13+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_11d6:
	/* 0x11d6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11db:
	/* 0x11db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11e0:
	/* 0x11e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11e2:
	/* 0x11e2: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11e7:
	/* 0x11e7: mov    ebp,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 152ULL);
x86_l_11ec:
	/* 0x11ec: jmp    a1c <generic_retuprobe_event+0xa1c> */
	return 2588ULL;
x86_l_11f1:
	/* 0x11f1: cmp    r12d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 38ULL);
x86_l_11f5:
	/* 0x11f5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11fa:
	/* 0x11fa: jne    a1c <generic_retuprobe_event+0xa1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2588ULL;
	}
x86_l_1200:
	/* 0x1200: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1205:
	/* 0x1205: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1208:
	/* 0x1208: add    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 224ULL);
x86_l_1210:
	/* 0x1210: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1213:
	/* 0x1213: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1219:
	/* 0x1219: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_121c:
	/* 0x121c: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_1223:
	/* 0x1223: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1225:
	/* 0x1225: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_122a:
	/* 0x122a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_122c:
	/* 0x122c: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_122f:
	/* 0x122f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1232:
	/* 0x1232: jns    d0a <generic_retuprobe_event+0xd0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 3338ULL;
	}
x86_l_1238:
	/* 0x1238: jmp    1592 <generic_retuprobe_event+0x1592> */
	goto x86_l_1592;
x86_l_123d:
	/* 0x123d: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1246:
	/* 0x1246: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_124f:
	/* 0x124f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1254:
	/* 0x1254: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1256:
	/* 0x1256: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_125a:
	/* 0x125a: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_125f:
	/* 0x125f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1264:
	/* 0x1264: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1269:
	/* 0x1269: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_126e:
	/* 0x126e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1273:
	/* 0x1273: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1275:
	/* 0x1275: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1279:
	/* 0x1279: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_127d:
	/* 0x127d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1282:
	/* 0x1282: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1289:
	/* 0x1289: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_128e:
	/* 0x128e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1290:
	/* 0x1290: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1293:
	/* 0x1293: je     1c1b <generic_retuprobe_event+0x1c1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7195ULL;
	}
x86_l_1299:
	/* 0x1299: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_129b:
	/* 0x129b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12a0:
	/* 0x12a0: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12a5:
	/* 0x12a5: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12aa:
	/* 0x12aa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12af:
	/* 0x12af: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_12b2:
	/* 0x12b2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_12b4:
	/* 0x12b4: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12ba:
	/* 0x12ba: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12bf:
	/* 0x12bf: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_12c6:
	/* 0x12c6: lea    esi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_12c9:
	/* 0x12c9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12ce:
	/* 0x12ce: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_12d1:
	/* 0x12d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d3:
	/* 0x12d3: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12d8:
	/* 0x12d8: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_12dc:
	/* 0x12dc: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_12e0:
	/* 0x12e0: lea    rdx,[r12+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_12e4:
	/* 0x12e4: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_12e8:
	/* 0x12e8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12ed:
	/* 0x12ed: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12f2:
	/* 0x12f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12f4:
	/* 0x12f4: add    rbp,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_12f8:
	/* 0x12f8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12fd:
	/* 0x12fd: jmp    a1c <generic_retuprobe_event+0xa1c> */
	return 2588ULL;
x86_l_1302:
	/* 0x1302: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1307:
	/* 0x1307: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_130a:
	/* 0x130a: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_130f:
	/* 0x130f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1314:
	/* 0x1314: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_131c:
	/* 0x131c: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1321:
	/* 0x1321: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1324:
	/* 0x1324: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1326:
	/* 0x1326: movzx  eax,BYTE PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 176ULL);
x86_l_132e:
	/* 0x132e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1330:
	/* 0x1330: je     1c2c <generic_retuprobe_event+0x1c2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7212ULL;
	}
x86_l_1336:
	/* 0x1336: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1339:
	/* 0x1339: jne    1e20 <generic_retuprobe_event+0x1e20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7712ULL;
	}
x86_l_133f:
	/* 0x133f: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1343:
	/* 0x1343: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1348:
	/* 0x1348: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_134d:
	/* 0x134d: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1352:
	/* 0x1352: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1357:
	/* 0x1357: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_135a:
	/* 0x135a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_135c:
	/* 0x135c: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1361:
	/* 0x1361: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1366:
	/* 0x1366: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_136b:
	/* 0x136b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1370:
	/* 0x1370: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1372:
	/* 0x1372: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1377:
	/* 0x1377: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_137b:
	/* 0x137b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1380:
	/* 0x1380: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1388:
	/* 0x1388: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_138d:
	/* 0x138d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_138f:
	/* 0x138f: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1394:
	/* 0x1394: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_139c:
	/* 0x139c: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_13a3:
	/* 0x13a3: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_13a9:
	/* 0x13a9: cmovb  r12,r13 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_13ad:
	/* 0x13ad: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_13b0:
	/* 0x13b0: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_13b7:
	/* 0x13b7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13bc:
	/* 0x13bc: jmp    1c8f <generic_retuprobe_event+0x1c8f> */
	return 7311ULL;
x86_l_13c1:
	/* 0x13c1: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13c6:
	/* 0x13c6: lea    rdi,[rcx+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_13cd:
	/* 0x13cd: lea    rdx,[rbp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_13d4:
	/* 0x13d4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13d9:
	/* 0x13d9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13de:
	/* 0x13de: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_13e1:
	/* 0x13e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e3:
	/* 0x13e3: lea    rdi,[rbx+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_13ea:
	/* 0x13ea: lea    rdx,[rbp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_13ee:
	/* 0x13ee: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13f3:
	/* 0x13f3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13f8:
	/* 0x13f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13fa:
	/* 0x13fa: lea    rdi,[rbx+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1401:
	/* 0x1401: lea    rdx,[rbp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1408:
	/* 0x1408: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_140d:
	/* 0x140d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1412:
	/* 0x1412: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1414:
	/* 0x1414: lea    rdi,[rbx+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_141b:
	/* 0x141b: lea    rdx,[rbp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1422:
	/* 0x1422: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1427:
	/* 0x1427: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_142c:
	/* 0x142c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_142e:
	/* 0x142e: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1437:
	/* 0x1437: lea    rdx,[rbp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_143e:
	/* 0x143e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1443:
	/* 0x1443: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1448:
	/* 0x1448: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_144d:
	/* 0x144d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_144f:
	/* 0x144f: lea    rdx,[rbp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1456:
	/* 0x1456: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_145b:
	/* 0x145b: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1463:
	/* 0x1463: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1468:
	/* 0x1468: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_146a:
	/* 0x146a: movzx  r12d,WORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 176ULL);
x86_l_1473:
	/* 0x1473: add    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_1478:
	/* 0x1478: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_147d:
	/* 0x147d: lea    rdi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1485:
	/* 0x1485: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_148a:
	/* 0x148a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_148d:
	/* 0x148d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_148f:
	/* 0x148f: movzx  eax,BYTE PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 172ULL);
x86_l_1497:
	/* 0x1497: shr    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_149a:
	/* 0x149a: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_149d:
	/* 0x149d: je     1cc1 <generic_retuprobe_event+0x1cc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7361ULL;
	}
x86_l_14a3:
	/* 0x14a3: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14a6:
	/* 0x14a6: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_14ab:
	/* 0x14ab: jne    2865 <generic_retuprobe_event+0x2865> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10341ULL;
	}
x86_l_14b1:
	/* 0x14b1: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14b6:
	/* 0x14b6: lea    rdx,[r12+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_14bb:
	/* 0x14bb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14c0:
	/* 0x14c0: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_14c8:
	/* 0x14c8: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_14cd:
	/* 0x14cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14cf:
	/* 0x14cf: movzx  eax,BYTE PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 184ULL);
x86_l_14d7:
	/* 0x14d7: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14dc:
	/* 0x14dc: mov    WORD PTR [rcx+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_14e3:
	/* 0x14e3: mov    WORD PTR [rcx+0xc2],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655426ULL);
x86_l_14ec:
	/* 0x14ec: lea    r13,[rcx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_14f3:
	/* 0x14f3: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_14f8:
	/* 0x14f8: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14fd:
	/* 0x14fd: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1504:
	/* 0x1504: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_150c:
	/* 0x150c: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1514:
	/* 0x1514: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_151c:
	/* 0x151c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1521:
	/* 0x1521: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1526:
	/* 0x1526: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1528:
	/* 0x1528: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_152c:
	/* 0x152c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1531:
	/* 0x1531: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1534:
	/* 0x1534: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1539:
	/* 0x1539: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_153c:
	/* 0x153c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_153e:
	/* 0x153e: mov    QWORD PTR [rsp+0x88],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1546:
	/* 0x1546: lea    rdx,[rbp+0xb6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_154d:
	/* 0x154d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1552:
	/* 0x1552: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_155a:
	/* 0x155a: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_155f:
	/* 0x155f: jmp    26fc <generic_retuprobe_event+0x26fc> */
	return 9980ULL;
x86_l_1564:
	/* 0x1564: mov    edx,0x120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 288ULL);
x86_l_1569:
	/* 0x1569: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_156e:
	/* 0x156e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1573:
	/* 0x1573: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_157a:
	/* 0x157a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_157f:
	/* 0x157f: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1584:
	/* 0x1584: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1586:
	/* 0x1586: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1589:
	/* 0x1589: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_158c:
	/* 0x158c: jns    d0a <generic_retuprobe_event+0xd0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 3338ULL;
	}
x86_l_1592:
	/* 0x1592: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1597:
	/* 0x1597: jmp    a1c <generic_retuprobe_event+0xa1c> */
	return 2588ULL;
x86_l_159c:
	/* 0x159c: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15a1:
	/* 0x15a1: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_15a9:
	/* 0x15a9: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_15b1:
	/* 0x15b1: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15b8:
	/* 0x15b8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15bd:
	/* 0x15bd: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_15c2:
	/* 0x15c2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_15c5:
	/* 0x15c5: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_15c8:
	/* 0x15c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 5578ULL;
}

static __noinline __u64 tetragon_bpf_multi_retuprobe_v61_generic_retuprobe_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5578ULL: goto x86_l_15ca;
	case 5581ULL: goto x86_l_15cd;
	case 5586ULL: goto x86_l_15d2;
	case 5592ULL: goto x86_l_15d8;
	case 5596ULL: goto x86_l_15dc;
	case 5599ULL: goto x86_l_15df;
	case 5605ULL: goto x86_l_15e5;
	case 5608ULL: goto x86_l_15e8;
	case 5614ULL: goto x86_l_15ee;
	case 5619ULL: goto x86_l_15f3;
	case 5624ULL: goto x86_l_15f8;
	case 5629ULL: goto x86_l_15fd;
	case 5634ULL: goto x86_l_1602;
	case 5636ULL: goto x86_l_1604;
	case 5640ULL: goto x86_l_1608;
	case 5645ULL: goto x86_l_160d;
	case 5652ULL: goto x86_l_1614;
	case 5659ULL: goto x86_l_161b;
	case 5663ULL: goto x86_l_161f;
	case 5668ULL: goto x86_l_1624;
	case 5673ULL: goto x86_l_1629;
	case 5675ULL: goto x86_l_162b;
	case 5680ULL: goto x86_l_1630;
	case 5688ULL: goto x86_l_1638;
	case 5692ULL: goto x86_l_163c;
	case 5698ULL: goto x86_l_1642;
	case 5703ULL: goto x86_l_1647;
	case 5711ULL: goto x86_l_164f;
	case 5715ULL: goto x86_l_1653;
	case 5720ULL: goto x86_l_1658;
	case 5725ULL: goto x86_l_165d;
	case 5730ULL: goto x86_l_1662;
	case 5735ULL: goto x86_l_1667;
	case 5737ULL: goto x86_l_1669;
	case 5742ULL: goto x86_l_166e;
	case 5744ULL: goto x86_l_1670;
	case 5750ULL: goto x86_l_1676;
	case 5755ULL: goto x86_l_167b;
	case 5760ULL: goto x86_l_1680;
	case 5763ULL: goto x86_l_1683;
	case 5766ULL: goto x86_l_1686;
	case 5770ULL: goto x86_l_168a;
	case 5773ULL: goto x86_l_168d;
	case 5777ULL: goto x86_l_1691;
	case 5782ULL: goto x86_l_1696;
	case 5789ULL: goto x86_l_169d;
	case 5795ULL: goto x86_l_16a3;
	case 5800ULL: goto x86_l_16a8;
	case 5805ULL: goto x86_l_16ad;
	case 5810ULL: goto x86_l_16b2;
	case 5816ULL: goto x86_l_16b8;
	case 5819ULL: goto x86_l_16bb;
	case 5824ULL: goto x86_l_16c0;
	case 5829ULL: goto x86_l_16c5;
	case 5832ULL: goto x86_l_16c8;
	case 5834ULL: goto x86_l_16ca;
	case 5839ULL: goto x86_l_16cf;
	case 5841ULL: goto x86_l_16d1;
	case 5847ULL: goto x86_l_16d7;
	case 5852ULL: goto x86_l_16dc;
	case 5857ULL: goto x86_l_16e1;
	case 5863ULL: goto x86_l_16e7;
	case 5869ULL: goto x86_l_16ed;
	case 5874ULL: goto x86_l_16f2;
	case 5880ULL: goto x86_l_16f8;
	case 5885ULL: goto x86_l_16fd;
	case 5888ULL: goto x86_l_1700;
	case 5893ULL: goto x86_l_1705;
	case 5902ULL: goto x86_l_170e;
	case 5911ULL: goto x86_l_1717;
	case 5916ULL: goto x86_l_171c;
	case 5921ULL: goto x86_l_1721;
	case 5926ULL: goto x86_l_1726;
	case 5931ULL: goto x86_l_172b;
	case 5936ULL: goto x86_l_1730;
	case 5939ULL: goto x86_l_1733;
	case 5941ULL: goto x86_l_1735;
	case 5944ULL: goto x86_l_1738;
	case 5949ULL: goto x86_l_173d;
	case 5956ULL: goto x86_l_1744;
	case 5962ULL: goto x86_l_174a;
	case 5966ULL: goto x86_l_174e;
	case 5971ULL: goto x86_l_1753;
	case 5978ULL: goto x86_l_175a;
	case 5983ULL: goto x86_l_175f;
	case 5986ULL: goto x86_l_1762;
	case 5989ULL: goto x86_l_1765;
	case 5992ULL: goto x86_l_1768;
	case 5994ULL: goto x86_l_176a;
	case 5999ULL: goto x86_l_176f;
	case 6001ULL: goto x86_l_1771;
	case 6003ULL: goto x86_l_1773;
	case 6008ULL: goto x86_l_1778;
	case 6015ULL: goto x86_l_177f;
	case 6019ULL: goto x86_l_1783;
	case 6022ULL: goto x86_l_1786;
	case 6025ULL: goto x86_l_1789;
	case 6030ULL: goto x86_l_178e;
	case 6036ULL: goto x86_l_1794;
	case 6041ULL: goto x86_l_1799;
	case 6048ULL: goto x86_l_17a0;
	case 6051ULL: goto x86_l_17a3;
	case 6058ULL: goto x86_l_17aa;
	case 6062ULL: goto x86_l_17ae;
	case 6067ULL: goto x86_l_17b3;
	case 6072ULL: goto x86_l_17b8;
	case 6077ULL: goto x86_l_17bd;
	case 6079ULL: goto x86_l_17bf;
	case 6084ULL: goto x86_l_17c4;
	case 6091ULL: goto x86_l_17cb;
	case 6095ULL: goto x86_l_17cf;
	case 6100ULL: goto x86_l_17d4;
	case 6105ULL: goto x86_l_17d9;
	case 6107ULL: goto x86_l_17db;
	case 6112ULL: goto x86_l_17e0;
	case 6119ULL: goto x86_l_17e7;
	case 6123ULL: goto x86_l_17eb;
	case 6128ULL: goto x86_l_17f0;
	case 6133ULL: goto x86_l_17f5;
	case 6135ULL: goto x86_l_17f7;
	case 6140ULL: goto x86_l_17fc;
	case 6147ULL: goto x86_l_1803;
	case 6151ULL: goto x86_l_1807;
	case 6156ULL: goto x86_l_180c;
	case 6161ULL: goto x86_l_1811;
	case 6163ULL: goto x86_l_1813;
	case 6168ULL: goto x86_l_1818;
	case 6175ULL: goto x86_l_181f;
	case 6179ULL: goto x86_l_1823;
	case 6184ULL: goto x86_l_1828;
	case 6189ULL: goto x86_l_182d;
	case 6191ULL: goto x86_l_182f;
	case 6196ULL: goto x86_l_1834;
	case 6203ULL: goto x86_l_183b;
	case 6207ULL: goto x86_l_183f;
	case 6212ULL: goto x86_l_1844;
	case 6217ULL: goto x86_l_1849;
	case 6219ULL: goto x86_l_184b;
	case 6224ULL: goto x86_l_1850;
	case 6231ULL: goto x86_l_1857;
	case 6235ULL: goto x86_l_185b;
	case 6240ULL: goto x86_l_1860;
	case 6245ULL: goto x86_l_1865;
	case 6247ULL: goto x86_l_1867;
	case 6252ULL: goto x86_l_186c;
	case 6259ULL: goto x86_l_1873;
	case 6263ULL: goto x86_l_1877;
	case 6268ULL: goto x86_l_187c;
	case 6273ULL: goto x86_l_1881;
	case 6275ULL: goto x86_l_1883;
	case 6280ULL: goto x86_l_1888;
	case 6290ULL: goto x86_l_1892;
	case 6295ULL: goto x86_l_1897;
	case 6302ULL: goto x86_l_189e;
	case 6306ULL: goto x86_l_18a2;
	case 6311ULL: goto x86_l_18a7;
	case 6316ULL: goto x86_l_18ac;
	case 6318ULL: goto x86_l_18ae;
	case 6323ULL: goto x86_l_18b3;
	case 6330ULL: goto x86_l_18ba;
	case 6334ULL: goto x86_l_18be;
	case 6339ULL: goto x86_l_18c3;
	case 6344ULL: goto x86_l_18c8;
	case 6346ULL: goto x86_l_18ca;
	case 6351ULL: goto x86_l_18cf;
	case 6358ULL: goto x86_l_18d6;
	case 6362ULL: goto x86_l_18da;
	case 6367ULL: goto x86_l_18df;
	case 6372ULL: goto x86_l_18e4;
	case 6374ULL: goto x86_l_18e6;
	case 6378ULL: goto x86_l_18ea;
	case 6383ULL: goto x86_l_18ef;
	case 6386ULL: goto x86_l_18f2;
	case 6391ULL: goto x86_l_18f7;
	case 6393ULL: goto x86_l_18f9;
	case 6400ULL: goto x86_l_1900;
	case 6405ULL: goto x86_l_1905;
	case 6410ULL: goto x86_l_190a;
	case 6415ULL: goto x86_l_190f;
	case 6417ULL: goto x86_l_1911;
	case 6422ULL: goto x86_l_1916;
	case 6430ULL: goto x86_l_191e;
	case 6435ULL: goto x86_l_1923;
	case 6438ULL: goto x86_l_1926;
	case 6441ULL: goto x86_l_1929;
	case 6446ULL: goto x86_l_192e;
	case 6451ULL: goto x86_l_1933;
	case 6453ULL: goto x86_l_1935;
	case 6458ULL: goto x86_l_193a;
	case 6465ULL: goto x86_l_1941;
	case 6473ULL: goto x86_l_1949;
	case 6478ULL: goto x86_l_194e;
	case 6483ULL: goto x86_l_1953;
	case 6485ULL: goto x86_l_1955;
	case 6490ULL: goto x86_l_195a;
	case 6497ULL: goto x86_l_1961;
	case 6505ULL: goto x86_l_1969;
	case 6510ULL: goto x86_l_196e;
	case 6515ULL: goto x86_l_1973;
	case 6517ULL: goto x86_l_1975;
	case 6522ULL: goto x86_l_197a;
	case 6529ULL: goto x86_l_1981;
	case 6536ULL: goto x86_l_1988;
	case 6541ULL: goto x86_l_198d;
	case 6546ULL: goto x86_l_1992;
	case 6549ULL: goto x86_l_1995;
	case 6551ULL: goto x86_l_1997;
	case 6556ULL: goto x86_l_199c;
	case 6561ULL: goto x86_l_19a1;
	case 6566ULL: goto x86_l_19a6;
	case 6573ULL: goto x86_l_19ad;
	case 6578ULL: goto x86_l_19b2;
	case 6583ULL: goto x86_l_19b7;
	case 6588ULL: goto x86_l_19bc;
	case 6590ULL: goto x86_l_19be;
	case 6595ULL: goto x86_l_19c3;
	case 6602ULL: goto x86_l_19ca;
	case 6609ULL: goto x86_l_19d1;
	case 6614ULL: goto x86_l_19d6;
	case 6619ULL: goto x86_l_19db;
	case 6621ULL: goto x86_l_19dd;
	case 6626ULL: goto x86_l_19e2;
	case 6633ULL: goto x86_l_19e9;
	case 6640ULL: goto x86_l_19f0;
	case 6645ULL: goto x86_l_19f5;
	case 6650ULL: goto x86_l_19fa;
	case 6652ULL: goto x86_l_19fc;
	case 6657ULL: goto x86_l_1a01;
	case 6664ULL: goto x86_l_1a08;
	case 6671ULL: goto x86_l_1a0f;
	case 6676ULL: goto x86_l_1a14;
	case 6681ULL: goto x86_l_1a19;
	case 6683ULL: goto x86_l_1a1b;
	case 6688ULL: goto x86_l_1a20;
	case 6693ULL: goto x86_l_1a25;
	case 6698ULL: goto x86_l_1a2a;
	case 6702ULL: goto x86_l_1a2e;
	case 6707ULL: goto x86_l_1a33;
	case 6712ULL: goto x86_l_1a38;
	case 6717ULL: goto x86_l_1a3d;
	case 6719ULL: goto x86_l_1a3f;
	case 6724ULL: goto x86_l_1a44;
	case 6731ULL: goto x86_l_1a4b;
	case 6735ULL: goto x86_l_1a4f;
	case 6740ULL: goto x86_l_1a54;
	case 6745ULL: goto x86_l_1a59;
	case 6747ULL: goto x86_l_1a5b;
	case 6752ULL: goto x86_l_1a60;
	case 6759ULL: goto x86_l_1a67;
	case 6763ULL: goto x86_l_1a6b;
	case 6768ULL: goto x86_l_1a70;
	case 6773ULL: goto x86_l_1a75;
	case 6775ULL: goto x86_l_1a77;
	case 6780ULL: goto x86_l_1a7c;
	case 6787ULL: goto x86_l_1a83;
	case 6791ULL: goto x86_l_1a87;
	case 6796ULL: goto x86_l_1a8c;
	case 6801ULL: goto x86_l_1a91;
	case 6803ULL: goto x86_l_1a93;
	case 6808ULL: goto x86_l_1a98;
	case 6815ULL: goto x86_l_1a9f;
	case 6819ULL: goto x86_l_1aa3;
	case 6824ULL: goto x86_l_1aa8;
	case 6829ULL: goto x86_l_1aad;
	case 6831ULL: goto x86_l_1aaf;
	case 6836ULL: goto x86_l_1ab4;
	case 6841ULL: goto x86_l_1ab9;
	case 6846ULL: goto x86_l_1abe;
	case 6851ULL: goto x86_l_1ac3;
	case 6856ULL: goto x86_l_1ac8;
	case 6861ULL: goto x86_l_1acd;
	case 6864ULL: goto x86_l_1ad0;
	case 6866ULL: goto x86_l_1ad2;
	case 6871ULL: goto x86_l_1ad7;
	case 6878ULL: goto x86_l_1ade;
	case 6882ULL: goto x86_l_1ae2;
	case 6887ULL: goto x86_l_1ae7;
	case 6892ULL: goto x86_l_1aec;
	case 6894ULL: goto x86_l_1aee;
	case 6899ULL: goto x86_l_1af3;
	case 6906ULL: goto x86_l_1afa;
	case 6910ULL: goto x86_l_1afe;
	case 6915ULL: goto x86_l_1b03;
	case 6917ULL: goto x86_l_1b05;
	case 6921ULL: goto x86_l_1b09;
	case 6926ULL: goto x86_l_1b0e;
	case 6931ULL: goto x86_l_1b13;
	case 6936ULL: goto x86_l_1b18;
	case 6938ULL: goto x86_l_1b1a;
	case 6942ULL: goto x86_l_1b1e;
	case 6947ULL: goto x86_l_1b23;
	case 6953ULL: goto x86_l_1b29;
	case 6957ULL: goto x86_l_1b2d;
	case 6962ULL: goto x86_l_1b32;
	case 6967ULL: goto x86_l_1b37;
	case 6972ULL: goto x86_l_1b3c;
	case 6974ULL: goto x86_l_1b3e;
	case 6978ULL: goto x86_l_1b42;
	case 6983ULL: goto x86_l_1b47;
	case 6989ULL: goto x86_l_1b4d;
	case 6993ULL: goto x86_l_1b51;
	case 6998ULL: goto x86_l_1b56;
	case 7003ULL: goto x86_l_1b5b;
	case 7008ULL: goto x86_l_1b60;
	case 7010ULL: goto x86_l_1b62;
	case 7015ULL: goto x86_l_1b67;
	case 7022ULL: goto x86_l_1b6e;
	case 7027ULL: goto x86_l_1b73;
	case 7032ULL: goto x86_l_1b78;
	case 7037ULL: goto x86_l_1b7d;
	case 7042ULL: goto x86_l_1b82;
	case 7044ULL: goto x86_l_1b84;
	case 7049ULL: goto x86_l_1b89;
	case 7054ULL: goto x86_l_1b8e;
	case 7059ULL: goto x86_l_1b93;
	case 7064ULL: goto x86_l_1b98;
	case 7072ULL: goto x86_l_1ba0;
	case 7080ULL: goto x86_l_1ba8;
	case 7088ULL: goto x86_l_1bb0;
	case 7096ULL: goto x86_l_1bb8;
	case 7104ULL: goto x86_l_1bc0;
	case 7112ULL: goto x86_l_1bc8;
	case 7120ULL: goto x86_l_1bd0;
	case 7128ULL: goto x86_l_1bd8;
	case 7136ULL: goto x86_l_1be0;
	case 7141ULL: goto x86_l_1be5;
	case 7148ULL: goto x86_l_1bec;
	case 7153ULL: goto x86_l_1bf1;
	case 7158ULL: goto x86_l_1bf6;
	case 7163ULL: goto x86_l_1bfb;
	case 7166ULL: goto x86_l_1bfe;
	case 7169ULL: goto x86_l_1c01;
	case 7171ULL: goto x86_l_1c03;
	case 7174ULL: goto x86_l_1c06;
	case 7180ULL: goto x86_l_1c0c;
	case 7182ULL: goto x86_l_1c0e;
	case 7187ULL: goto x86_l_1c13;
	case 7190ULL: goto x86_l_1c16;
	case 7195ULL: goto x86_l_1c1b;
	case 7202ULL: goto x86_l_1c22;
	case 7207ULL: goto x86_l_1c27;
	case 7212ULL: goto x86_l_1c2c;
	case 7217ULL: goto x86_l_1c31;
	case 7222ULL: goto x86_l_1c36;
	case 7227ULL: goto x86_l_1c3b;
	case 7232ULL: goto x86_l_1c40;
	case 7237ULL: goto x86_l_1c45;
	case 7239ULL: goto x86_l_1c47;
	case 7243ULL: goto x86_l_1c4b;
	case 7248ULL: goto x86_l_1c50;
	case 7256ULL: goto x86_l_1c58;
	case 7261ULL: goto x86_l_1c5d;
	case 7264ULL: goto x86_l_1c60;
	case 7266ULL: goto x86_l_1c62;
	case 7271ULL: goto x86_l_1c67;
	case 7279ULL: goto x86_l_1c6f;
	case 7286ULL: goto x86_l_1c76;
	case 7292ULL: goto x86_l_1c7c;
	case 7296ULL: goto x86_l_1c80;
	case 7299ULL: goto x86_l_1c83;
	case 7306ULL: goto x86_l_1c8a;
	case 7311ULL: goto x86_l_1c8f;
	case 7314ULL: goto x86_l_1c92;
	case 7316ULL: goto x86_l_1c94;
	case 7318ULL: goto x86_l_1c96;
	case 7320ULL: goto x86_l_1c98;
	case 7327ULL: goto x86_l_1c9f;
	case 7334ULL: goto x86_l_1ca6;
	case 7338ULL: goto x86_l_1caa;
	case 7341ULL: goto x86_l_1cad;
	case 7346ULL: goto x86_l_1cb2;
	case 7356ULL: goto x86_l_1cbc;
	case 7361ULL: goto x86_l_1cc1;
	case 7369ULL: goto x86_l_1cc9;
	case 7374ULL: goto x86_l_1cce;
	case 7379ULL: goto x86_l_1cd3;
	case 7387ULL: goto x86_l_1cdb;
	case 7390ULL: goto x86_l_1cde;
	case 7394ULL: goto x86_l_1ce2;
	case 7402ULL: goto x86_l_1cea;
	case 7407ULL: goto x86_l_1cef;
	case 7414ULL: goto x86_l_1cf6;
	case 7419ULL: goto x86_l_1cfb;
	case 7421ULL: goto x86_l_1cfd;
	default: return 0xffffffffffffffffULL;
	}
x86_l_15ca:
	/* 0x15ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15cd:
	/* 0x15cd: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15d2:
	/* 0x15d2: js     1e91 <generic_retuprobe_event+0x1e91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7825ULL;
	}
x86_l_15d8:
	/* 0x15d8: movzx  eax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15dc:
	/* 0x15dc: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_15df:
	/* 0x15df: je     1e3f <generic_retuprobe_event+0x1e3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7743ULL;
	}
x86_l_15e5:
	/* 0x15e5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15e8:
	/* 0x15e8: jne    1e77 <generic_retuprobe_event+0x1e77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7799ULL;
	}
x86_l_15ee:
	/* 0x15ee: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_15f3:
	/* 0x15f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15f8:
	/* 0x15f8: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15fd:
	/* 0x15fd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1602:
	/* 0x1602: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1604:
	/* 0x1604: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1608:
	/* 0x1608: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_160d:
	/* 0x160d: mov    QWORD PTR [rdi+0xa4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1614:
	/* 0x1614: add    rdi,0x9e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 158ULL);
x86_l_161b:
	/* 0x161b: add    r12,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_161f:
	/* 0x161f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1624:
	/* 0x1624: jmp    1e6d <generic_retuprobe_event+0x1e6d> */
	return 7789ULL;
x86_l_1629:
	/* 0x1629: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_162b:
	/* 0x162b: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1630:
	/* 0x1630: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1638:
	/* 0x1638: cmp    rax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 3ULL);
x86_l_163c:
	/* 0x163c: jb     16fd <generic_retuprobe_event+0x16fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_16fd;
	}
x86_l_1642:
	/* 0x1642: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1647:
	/* 0x1647: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_164f:
	/* 0x164f: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1653:
	/* 0x1653: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1658:
	/* 0x1658: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_165d:
	/* 0x165d: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1662:
	/* 0x1662: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1667:
	/* 0x1667: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1669:
	/* 0x1669: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_166e:
	/* 0x166e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1670:
	/* 0x1670: js     29e9 <generic_retuprobe_event+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10729ULL;
	}
x86_l_1676:
	/* 0x1676: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_167b:
	/* 0x167b: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1680:
	/* 0x1680: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1683:
	/* 0x1683: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1686:
	/* 0x1686: cmovb  rbx,r13 */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_168a:
	/* 0x168a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_168d:
	/* 0x168d: cmovne r13,rbx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBX, X86_WIDTH_64, X86_CC_NE);
x86_l_1691:
	/* 0x1691: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_1696:
	/* 0x1696: cmp    r13,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4094ULL);
x86_l_169d:
	/* 0x169d: ja     29e9 <generic_retuprobe_event+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10729ULL;
	}
x86_l_16a3:
	/* 0x16a3: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16a8:
	/* 0x16a8: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_16ad:
	/* 0x16ad: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16b2:
	/* 0x16b2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_16b8:
	/* 0x16b8: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16bb:
	/* 0x16bb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16c0:
	/* 0x16c0: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16c5:
	/* 0x16c5: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_16c8:
	/* 0x16c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ca:
	/* 0x16ca: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_16cf:
	/* 0x16cf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16d1:
	/* 0x16d1: js     29e9 <generic_retuprobe_event+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10729ULL;
	}
x86_l_16d7:
	/* 0x16d7: mov    QWORD PTR [rsp+0x8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16dc:
	/* 0x16dc: add    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_16e1:
	/* 0x16e1: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_16e7:
	/* 0x16e7: je     2070 <generic_retuprobe_event+0x2070> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8304ULL;
	}
x86_l_16ed:
	/* 0x16ed: sub    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 24ULL);
x86_l_16f2:
	/* 0x16f2: jne    2077 <generic_retuprobe_event+0x2077> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8311ULL;
	}
x86_l_16f8:
	/* 0x16f8: jmp    2082 <generic_retuprobe_event+0x2082> */
	return 8322ULL;
x86_l_16fd:
	/* 0x16fd: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_1700:
	/* 0x1700: jmp    2c9 <generic_retuprobe_event+0x2c9> */
	return 713ULL;
x86_l_1705:
	/* 0x1705: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_170e:
	/* 0x170e: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1717:
	/* 0x1717: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_171c:
	/* 0x171c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1721:
	/* 0x1721: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1726:
	/* 0x1726: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_172b:
	/* 0x172b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1730:
	/* 0x1730: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1733:
	/* 0x1733: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1735:
	/* 0x1735: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1738:
	/* 0x1738: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_173d:
	/* 0x173d: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_1744:
	/* 0x1744: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_174a:
	/* 0x174a: cmovb  r12,r13 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_174e:
	/* 0x174e: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1753:
	/* 0x1753: add    rbx,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_175a:
	/* 0x175a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_175f:
	/* 0x175f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1762:
	/* 0x1762: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_1765:
	/* 0x1765: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_1768:
	/* 0x1768: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_176a:
	/* 0x176a: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_176f:
	/* 0x176f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1771:
	/* 0x1771: js     1789 <generic_retuprobe_event+0x1789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1789;
	}
x86_l_1773:
	/* 0x1773: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1778:
	/* 0x1778: mov    DWORD PTR [rax+0xa0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_177f:
	/* 0x177f: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1783:
	/* 0x1783: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_1786:
	/* 0x1786: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_1789:
	/* 0x1789: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_178e:
	/* 0x178e: mov    DWORD PTR [rax+0x9c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1794:
	/* 0x1794: jmp    1c0e <generic_retuprobe_event+0x1c0e> */
	goto x86_l_1c0e;
x86_l_1799:
	/* 0x1799: lea    rbp,[rcx+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_17a0:
	/* 0x17a0: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_17a3:
	/* 0x17a3: lea    r13,[rcx+0xdc] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_17aa:
	/* 0x17aa: lea    rdx,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17ae:
	/* 0x17ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17b3:
	/* 0x17b3: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17b8:
	/* 0x17b8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17bd:
	/* 0x17bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17bf:
	/* 0x17bf: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17c4:
	/* 0x17c4: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_17cb:
	/* 0x17cb: lea    rdx,[rbx+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_17cf:
	/* 0x17cf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17d4:
	/* 0x17d4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17d9:
	/* 0x17d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17db:
	/* 0x17db: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17e0:
	/* 0x17e0: lea    rdi,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_17e7:
	/* 0x17e7: lea    rdx,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17eb:
	/* 0x17eb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17f0:
	/* 0x17f0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17f5:
	/* 0x17f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f7:
	/* 0x17f7: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17fc:
	/* 0x17fc: lea    rdi,[rax+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1803:
	/* 0x1803: lea    rdx,[rbx+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1807:
	/* 0x1807: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_180c:
	/* 0x180c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1811:
	/* 0x1811: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1813:
	/* 0x1813: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1818:
	/* 0x1818: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_181f:
	/* 0x181f: lea    rdx,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1823:
	/* 0x1823: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1828:
	/* 0x1828: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_182d:
	/* 0x182d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_182f:
	/* 0x182f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1834:
	/* 0x1834: lea    rdi,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_183b:
	/* 0x183b: lea    rdx,[rbx+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_183f:
	/* 0x183f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1844:
	/* 0x1844: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1849:
	/* 0x1849: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_184b:
	/* 0x184b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1850:
	/* 0x1850: lea    rdi,[rax+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_1857:
	/* 0x1857: lea    rdx,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_185b:
	/* 0x185b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1860:
	/* 0x1860: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1865:
	/* 0x1865: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1867:
	/* 0x1867: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_186c:
	/* 0x186c: lea    rdi,[rax+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1873:
	/* 0x1873: lea    rdx,[rbx+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1877:
	/* 0x1877: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_187c:
	/* 0x187c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1881:
	/* 0x1881: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1883:
	/* 0x1883: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1888:
	/* 0x1888: mov    DWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_1892:
	/* 0x1892: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1897:
	/* 0x1897: lea    rdi,[rax+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_189e:
	/* 0x189e: lea    rdx,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18a2:
	/* 0x18a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18a7:
	/* 0x18a7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18ac:
	/* 0x18ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ae:
	/* 0x18ae: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18b3:
	/* 0x18b3: lea    rdi,[rax+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_18ba:
	/* 0x18ba: lea    rdx,[rbx+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18be:
	/* 0x18be: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18c3:
	/* 0x18c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18c8:
	/* 0x18c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ca:
	/* 0x18ca: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18cf:
	/* 0x18cf: lea    rdi,[rax+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_18d6:
	/* 0x18d6: lea    rdx,[rbx+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18da:
	/* 0x18da: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18df:
	/* 0x18df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18e4:
	/* 0x18e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e6:
	/* 0x18e6: lea    rdx,[rbx+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18ea:
	/* 0x18ea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18ef:
	/* 0x18ef: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_18f2:
	/* 0x18f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18f7:
	/* 0x18f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18f9:
	/* 0x18f9: lea    rdx,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1900:
	/* 0x1900: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1905:
	/* 0x1905: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_190a:
	/* 0x190a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_190f:
	/* 0x190f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1911:
	/* 0x1911: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1916:
	/* 0x1916: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_191e:
	/* 0x191e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1923:
	/* 0x1923: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1926:
	/* 0x1926: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_1929:
	/* 0x1929: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_192e:
	/* 0x192e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1933:
	/* 0x1933: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1935:
	/* 0x1935: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_193a:
	/* 0x193a: lea    rdi,[rax+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1941:
	/* 0x1941: lea    rdx,[r12+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1949:
	/* 0x1949: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_194e:
	/* 0x194e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1953:
	/* 0x1953: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1955:
	/* 0x1955: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_195a:
	/* 0x195a: lea    rdi,[rax+0xe4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_1961:
	/* 0x1961: lea    rdx,[r12+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1969:
	/* 0x1969: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_196e:
	/* 0x196e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1973:
	/* 0x1973: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1975:
	/* 0x1975: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_197a:
	/* 0x197a: add    rdi,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1981:
	/* 0x1981: add    r12,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1988:
	/* 0x1988: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_198d:
	/* 0x198d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1992:
	/* 0x1992: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1995:
	/* 0x1995: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1997:
	/* 0x1997: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_199c:
	/* 0x199c: mov    ebp,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 80ULL);
x86_l_19a1:
	/* 0x19a1: jmp    a1c <generic_retuprobe_event+0xa1c> */
	return 2588ULL;
x86_l_19a6:
	/* 0x19a6: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_19ad:
	/* 0x19ad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19b2:
	/* 0x19b2: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19b7:
	/* 0x19b7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19bc:
	/* 0x19bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19be:
	/* 0x19be: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19c3:
	/* 0x19c3: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_19ca:
	/* 0x19ca: lea    rdx,[r13+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_19d1:
	/* 0x19d1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19d6:
	/* 0x19d6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19db:
	/* 0x19db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19dd:
	/* 0x19dd: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19e2:
	/* 0x19e2: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_19e9:
	/* 0x19e9: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_19f0:
	/* 0x19f0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19f5:
	/* 0x19f5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19fa:
	/* 0x19fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19fc:
	/* 0x19fc: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a01:
	/* 0x1a01: add    rdi,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_1a08:
	/* 0x1a08: lea    rdx,[r13+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1a0f:
	/* 0x1a0f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a14:
	/* 0x1a14: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a19:
	/* 0x1a19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a1b:
	/* 0x1a1b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a20:
	/* 0x1a20: mov    ebp,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_1a25:
	/* 0x1a25: jmp    a1c <generic_retuprobe_event+0xa1c> */
	return 2588ULL;
x86_l_1a2a:
	/* 0x1a2a: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a2e:
	/* 0x1a2e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a33:
	/* 0x1a33: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a38:
	/* 0x1a38: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a3d:
	/* 0x1a3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a3f:
	/* 0x1a3f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a44:
	/* 0x1a44: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1a4b:
	/* 0x1a4b: lea    rdx,[r13+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1a4f:
	/* 0x1a4f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a54:
	/* 0x1a54: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a59:
	/* 0x1a59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a5b:
	/* 0x1a5b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a60:
	/* 0x1a60: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1a67:
	/* 0x1a67: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a6b:
	/* 0x1a6b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a70:
	/* 0x1a70: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a75:
	/* 0x1a75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a77:
	/* 0x1a77: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a7c:
	/* 0x1a7c: lea    rdi,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1a83:
	/* 0x1a83: lea    rdx,[r13+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a87:
	/* 0x1a87: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a8c:
	/* 0x1a8c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a91:
	/* 0x1a91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a93:
	/* 0x1a93: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a98:
	/* 0x1a98: add    rdi,0xac */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 172ULL);
x86_l_1a9f:
	/* 0x1a9f: lea    rdx,[r13+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1aa3:
	/* 0x1aa3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1aa8:
	/* 0x1aa8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1aad:
	/* 0x1aad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aaf:
	/* 0x1aaf: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ab4:
	/* 0x1ab4: mov    ebp,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 32ULL);
x86_l_1ab9:
	/* 0x1ab9: jmp    a1c <generic_retuprobe_event+0xa1c> */
	return 2588ULL;
x86_l_1abe:
	/* 0x1abe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ac3:
	/* 0x1ac3: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ac8:
	/* 0x1ac8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1acd:
	/* 0x1acd: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1ad0:
	/* 0x1ad0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad2:
	/* 0x1ad2: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ad7:
	/* 0x1ad7: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1ade:
	/* 0x1ade: lea    rdx,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ae2:
	/* 0x1ae2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ae7:
	/* 0x1ae7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1aec:
	/* 0x1aec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aee:
	/* 0x1aee: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1af3:
	/* 0x1af3: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1afa:
	/* 0x1afa: lea    rdx,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1afe:
	/* 0x1afe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b03:
	/* 0x1b03: jmp    1b7d <generic_retuprobe_event+0x1b7d> */
	goto x86_l_1b7d;
x86_l_1b05:
	/* 0x1b05: lea    rdx,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b09:
	/* 0x1b09: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b0e:
	/* 0x1b0e: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b13:
	/* 0x1b13: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b18:
	/* 0x1b18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b1a:
	/* 0x1b1a: mov    ecx,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b1e:
	/* 0x1b1e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b23:
	/* 0x1b23: mov    DWORD PTR [rax+0x9c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1b29:
	/* 0x1b29: lea    rdx,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b2d:
	/* 0x1b2d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b32:
	/* 0x1b32: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b37:
	/* 0x1b37: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b3c:
	/* 0x1b3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b3e:
	/* 0x1b3e: mov    ecx,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b42:
	/* 0x1b42: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b47:
	/* 0x1b47: mov    DWORD PTR [rax+0xa0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1b4d:
	/* 0x1b4d: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b51:
	/* 0x1b51: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b56:
	/* 0x1b56: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b5b:
	/* 0x1b5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b60:
	/* 0x1b60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b62:
	/* 0x1b62: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b67:
	/* 0x1b67: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1b6e:
	/* 0x1b6e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1b73:
	/* 0x1b73: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_1b78:
	/* 0x1b78: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_1b7d:
	/* 0x1b7d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b82:
	/* 0x1b82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b84:
	/* 0x1b84: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b89:
	/* 0x1b89: mov    ebp,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_1b8e:
	/* 0x1b8e: jmp    a1c <generic_retuprobe_event+0xa1c> */
	return 2588ULL;
x86_l_1b93:
	/* 0x1b93: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b98:
	/* 0x1b98: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1ba0:
	/* 0x1ba0: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1ba8:
	/* 0x1ba8: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1bb0:
	/* 0x1bb0: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1bb8:
	/* 0x1bb8: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1bc0:
	/* 0x1bc0: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1bc8:
	/* 0x1bc8: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1bd0:
	/* 0x1bd0: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1bd8:
	/* 0x1bd8: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1be0:
	/* 0x1be0: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1be5:
	/* 0x1be5: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bec:
	/* 0x1bec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bf1:
	/* 0x1bf1: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1bf6:
	/* 0x1bf6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bfb:
	/* 0x1bfb: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_1bfe:
	/* 0x1bfe: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1c01:
	/* 0x1c01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c03:
	/* 0x1c03: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c06:
	/* 0x1c06: je     1e9b <generic_retuprobe_event+0x1e9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7835ULL;
	}
x86_l_1c0c:
	/* 0x1c0c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c0e:
	/* 0x1c0e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c13:
	/* 0x1c13: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_1c16:
	/* 0x1c16: jmp    a17 <generic_retuprobe_event+0xa17> */
	return 2583ULL;
x86_l_1c1b:
	/* 0x1c1b: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1c22:
	/* 0x1c22: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c27:
	/* 0x1c27: jmp    a1c <generic_retuprobe_event+0xa1c> */
	return 2588ULL;
x86_l_1c2c:
	/* 0x1c2c: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c31:
	/* 0x1c31: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1c36:
	/* 0x1c36: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c3b:
	/* 0x1c3b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c40:
	/* 0x1c40: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c45:
	/* 0x1c45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c47:
	/* 0x1c47: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1c4b:
	/* 0x1c4b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c50:
	/* 0x1c50: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1c58:
	/* 0x1c58: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c5d:
	/* 0x1c5d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1c60:
	/* 0x1c60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c62:
	/* 0x1c62: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c67:
	/* 0x1c67: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1c6f:
	/* 0x1c6f: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_1c76:
	/* 0x1c76: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_1c7c:
	/* 0x1c7c: cmovb  r12,r13 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_1c80:
	/* 0x1c80: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1c83:
	/* 0x1c83: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1c8a:
	/* 0x1c8a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c8f:
	/* 0x1c8f: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_1c92:
	/* 0x1c92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c94:
	/* 0x1c94: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c96:
	/* 0x1c96: js     1cb2 <generic_retuprobe_event+0x1cb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1cb2;
	}
x86_l_1c98:
	/* 0x1c98: mov    DWORD PTR [rbx+0x9c],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1c9f:
	/* 0x1c9f: mov    DWORD PTR [rbx+0xa0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1ca6:
	/* 0x1ca6: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1caa:
	/* 0x1caa: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_1cad:
	/* 0x1cad: jmp    1e30 <generic_retuprobe_event+0x1e30> */
	return 7728ULL;
x86_l_1cb2:
	/* 0x1cb2: mov    DWORD PTR [rbx+0x9c],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 674309865470ULL);
x86_l_1cbc:
	/* 0x1cbc: jmp    1e30 <generic_retuprobe_event+0x1e30> */
	return 7728ULL;
x86_l_1cc1:
	/* 0x1cc1: mov    QWORD PTR [rsp+0x88],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1cc9:
	/* 0x1cc9: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cce:
	/* 0x1cce: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1cd3:
	/* 0x1cd3: movzx  ebx,WORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 176ULL);
x86_l_1cdb:
	/* 0x1cdb: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1cde:
	/* 0x1cde: lea    r13,[rax+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1ce2:
	/* 0x1ce2: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1cea:
	/* 0x1cea: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cef:
	/* 0x1cef: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_1cf6:
	/* 0x1cf6: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cfb:
	/* 0x1cfb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cfd:
	/* 0x1cfd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
	return 7424ULL;
}

static __noinline __u64 tetragon_bpf_multi_retuprobe_v61_generic_retuprobe_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7424ULL: goto x86_l_1d00;
	case 7430ULL: goto x86_l_1d06;
	case 7433ULL: goto x86_l_1d09;
	case 7436ULL: goto x86_l_1d0c;
	case 7440ULL: goto x86_l_1d10;
	case 7444ULL: goto x86_l_1d14;
	case 7447ULL: goto x86_l_1d17;
	case 7451ULL: goto x86_l_1d1b;
	case 7455ULL: goto x86_l_1d1f;
	case 7460ULL: goto x86_l_1d24;
	case 7463ULL: goto x86_l_1d27;
	case 7468ULL: goto x86_l_1d2c;
	case 7470ULL: goto x86_l_1d2e;
	case 7473ULL: goto x86_l_1d31;
	case 7479ULL: goto x86_l_1d37;
	case 7483ULL: goto x86_l_1d3b;
	case 7486ULL: goto x86_l_1d3e;
	case 7492ULL: goto x86_l_1d44;
	case 7494ULL: goto x86_l_1d46;
	case 7500ULL: goto x86_l_1d4c;
	case 7503ULL: goto x86_l_1d4f;
	case 7509ULL: goto x86_l_1d55;
	case 7512ULL: goto x86_l_1d58;
	case 7518ULL: goto x86_l_1d5e;
	case 7524ULL: goto x86_l_1d64;
	case 7528ULL: goto x86_l_1d68;
	case 7533ULL: goto x86_l_1d6d;
	case 7537ULL: goto x86_l_1d71;
	case 7542ULL: goto x86_l_1d76;
	case 7547ULL: goto x86_l_1d7b;
	case 7549ULL: goto x86_l_1d7d;
	case 7553ULL: goto x86_l_1d81;
	case 7558ULL: goto x86_l_1d86;
	case 7561ULL: goto x86_l_1d89;
	case 7566ULL: goto x86_l_1d8e;
	case 7568ULL: goto x86_l_1d90;
	case 7573ULL: goto x86_l_1d95;
	case 7580ULL: goto x86_l_1d9c;
	case 7584ULL: goto x86_l_1da0;
	case 7588ULL: goto x86_l_1da4;
	case 7593ULL: goto x86_l_1da9;
	case 7598ULL: goto x86_l_1dae;
	case 7601ULL: goto x86_l_1db1;
	case 7603ULL: goto x86_l_1db3;
	case 7606ULL: goto x86_l_1db6;
	case 7613ULL: goto x86_l_1dbd;
	case 7618ULL: goto x86_l_1dc2;
	case 7623ULL: goto x86_l_1dc7;
	case 7626ULL: goto x86_l_1dca;
	case 7628ULL: goto x86_l_1dcc;
	case 7635ULL: goto x86_l_1dd3;
	case 7644ULL: goto x86_l_1ddc;
	case 7649ULL: goto x86_l_1de1;
	case 7654ULL: goto x86_l_1de6;
	case 7659ULL: goto x86_l_1deb;
	case 7666ULL: goto x86_l_1df2;
	case 7671ULL: goto x86_l_1df7;
	case 7673ULL: goto x86_l_1df9;
	case 7676ULL: goto x86_l_1dfc;
	case 7678ULL: goto x86_l_1dfe;
	case 7680ULL: goto x86_l_1e00;
	case 7688ULL: goto x86_l_1e08;
	case 7691ULL: goto x86_l_1e0b;
	case 7695ULL: goto x86_l_1e0f;
	case 7699ULL: goto x86_l_1e13;
	case 7702ULL: goto x86_l_1e16;
	case 7705ULL: goto x86_l_1e19;
	case 7710ULL: goto x86_l_1e1e;
	case 7712ULL: goto x86_l_1e20;
	case 7723ULL: goto x86_l_1e2b;
	case 7728ULL: goto x86_l_1e30;
	case 7733ULL: goto x86_l_1e35;
	case 7738ULL: goto x86_l_1e3a;
	case 7743ULL: goto x86_l_1e3f;
	case 7750ULL: goto x86_l_1e46;
	case 7755ULL: goto x86_l_1e4b;
	case 7760ULL: goto x86_l_1e50;
	case 7765ULL: goto x86_l_1e55;
	case 7768ULL: goto x86_l_1e58;
	case 7770ULL: goto x86_l_1e5a;
	case 7773ULL: goto x86_l_1e5d;
	case 7780ULL: goto x86_l_1e64;
	case 7784ULL: goto x86_l_1e68;
	case 7789ULL: goto x86_l_1e6d;
	case 7794ULL: goto x86_l_1e72;
	case 7797ULL: goto x86_l_1e75;
	case 7799ULL: goto x86_l_1e77;
	case 7804ULL: goto x86_l_1e7c;
	case 7811ULL: goto x86_l_1e83;
	case 7820ULL: goto x86_l_1e8c;
	case 7825ULL: goto x86_l_1e91;
	case 7830ULL: goto x86_l_1e96;
	case 7835ULL: goto x86_l_1e9b;
	case 7840ULL: goto x86_l_1ea0;
	case 7847ULL: goto x86_l_1ea7;
	case 7852ULL: goto x86_l_1eac;
	case 7857ULL: goto x86_l_1eb1;
	case 7862ULL: goto x86_l_1eb6;
	case 7864ULL: goto x86_l_1eb8;
	case 7867ULL: goto x86_l_1ebb;
	case 7873ULL: goto x86_l_1ec1;
	case 7876ULL: goto x86_l_1ec4;
	case 7880ULL: goto x86_l_1ec8;
	case 7885ULL: goto x86_l_1ecd;
	case 7890ULL: goto x86_l_1ed2;
	case 7895ULL: goto x86_l_1ed7;
	case 7897ULL: goto x86_l_1ed9;
	case 7902ULL: goto x86_l_1ede;
	case 7909ULL: goto x86_l_1ee5;
	case 7914ULL: goto x86_l_1eea;
	case 7919ULL: goto x86_l_1eef;
	case 7924ULL: goto x86_l_1ef4;
	case 7929ULL: goto x86_l_1ef9;
	case 7931ULL: goto x86_l_1efb;
	case 7935ULL: goto x86_l_1eff;
	case 7940ULL: goto x86_l_1f04;
	case 7945ULL: goto x86_l_1f09;
	case 7950ULL: goto x86_l_1f0e;
	case 7952ULL: goto x86_l_1f10;
	case 7957ULL: goto x86_l_1f15;
	case 7960ULL: goto x86_l_1f18;
	case 7966ULL: goto x86_l_1f1e;
	case 7968ULL: goto x86_l_1f20;
	case 7973ULL: goto x86_l_1f25;
	case 7976ULL: goto x86_l_1f28;
	case 7981ULL: goto x86_l_1f2d;
	case 7983ULL: goto x86_l_1f2f;
	case 7988ULL: goto x86_l_1f34;
	case 7990ULL: goto x86_l_1f36;
	case 7995ULL: goto x86_l_1f3b;
	case 8000ULL: goto x86_l_1f40;
	case 8004ULL: goto x86_l_1f44;
	case 8009ULL: goto x86_l_1f49;
	case 8014ULL: goto x86_l_1f4e;
	case 8017ULL: goto x86_l_1f51;
	case 8019ULL: goto x86_l_1f53;
	case 8022ULL: goto x86_l_1f56;
	case 8024ULL: goto x86_l_1f58;
	case 8026ULL: goto x86_l_1f5a;
	case 8028ULL: goto x86_l_1f5c;
	case 8033ULL: goto x86_l_1f61;
	case 8039ULL: goto x86_l_1f67;
	case 8044ULL: goto x86_l_1f6c;
	case 8049ULL: goto x86_l_1f71;
	case 8052ULL: goto x86_l_1f74;
	case 8057ULL: goto x86_l_1f79;
	case 8061ULL: goto x86_l_1f7d;
	case 8066ULL: goto x86_l_1f82;
	case 8071ULL: goto x86_l_1f87;
	case 8073ULL: goto x86_l_1f89;
	case 8077ULL: goto x86_l_1f8d;
	case 8082ULL: goto x86_l_1f92;
	case 8085ULL: goto x86_l_1f95;
	case 8090ULL: goto x86_l_1f9a;
	case 8092ULL: goto x86_l_1f9c;
	case 8097ULL: goto x86_l_1fa1;
	case 8104ULL: goto x86_l_1fa8;
	case 8108ULL: goto x86_l_1fac;
	case 8112ULL: goto x86_l_1fb0;
	case 8117ULL: goto x86_l_1fb5;
	case 8122ULL: goto x86_l_1fba;
	case 8125ULL: goto x86_l_1fbd;
	case 8127ULL: goto x86_l_1fbf;
	case 8130ULL: goto x86_l_1fc2;
	case 8137ULL: goto x86_l_1fc9;
	case 8142ULL: goto x86_l_1fce;
	case 8147ULL: goto x86_l_1fd3;
	case 8150ULL: goto x86_l_1fd6;
	case 8152ULL: goto x86_l_1fd8;
	case 8159ULL: goto x86_l_1fdf;
	case 8168ULL: goto x86_l_1fe8;
	case 8173ULL: goto x86_l_1fed;
	case 8180ULL: goto x86_l_1ff4;
	case 8185ULL: goto x86_l_1ff9;
	case 8190ULL: goto x86_l_1ffe;
	case 8197ULL: goto x86_l_2005;
	case 8202ULL: goto x86_l_200a;
	case 8204ULL: goto x86_l_200c;
	case 8207ULL: goto x86_l_200f;
	case 8209ULL: goto x86_l_2011;
	case 8211ULL: goto x86_l_2013;
	case 8214ULL: goto x86_l_2016;
	case 8218ULL: goto x86_l_201a;
	case 8222ULL: goto x86_l_201e;
	case 8225ULL: goto x86_l_2021;
	case 8228ULL: goto x86_l_2024;
	case 8233ULL: goto x86_l_2029;
	case 8238ULL: goto x86_l_202e;
	case 8243ULL: goto x86_l_2033;
	case 8248ULL: goto x86_l_2038;
	case 8251ULL: goto x86_l_203b;
	case 8257ULL: goto x86_l_2041;
	case 8260ULL: goto x86_l_2044;
	case 8262ULL: goto x86_l_2046;
	case 8267ULL: goto x86_l_204b;
	case 8273ULL: goto x86_l_2051;
	case 8279ULL: goto x86_l_2057;
	case 8283ULL: goto x86_l_205b;
	case 8288ULL: goto x86_l_2060;
	case 8292ULL: goto x86_l_2064;
	case 8299ULL: goto x86_l_206b;
	case 8304ULL: goto x86_l_2070;
	case 8306ULL: goto x86_l_2072;
	case 8311ULL: goto x86_l_2077;
	case 8320ULL: goto x86_l_2080;
	case 8322ULL: goto x86_l_2082;
	case 8327ULL: goto x86_l_2087;
	case 8332ULL: goto x86_l_208c;
	case 8340ULL: goto x86_l_2094;
	case 8344ULL: goto x86_l_2098;
	case 8349ULL: goto x86_l_209d;
	case 8354ULL: goto x86_l_20a2;
	case 8359ULL: goto x86_l_20a7;
	case 8364ULL: goto x86_l_20ac;
	case 8366ULL: goto x86_l_20ae;
	case 8371ULL: goto x86_l_20b3;
	case 8373ULL: goto x86_l_20b5;
	case 8379ULL: goto x86_l_20bb;
	case 8384ULL: goto x86_l_20c0;
	case 8389ULL: goto x86_l_20c5;
	case 8392ULL: goto x86_l_20c8;
	case 8395ULL: goto x86_l_20cb;
	case 8399ULL: goto x86_l_20cf;
	case 8402ULL: goto x86_l_20d2;
	case 8406ULL: goto x86_l_20d6;
	case 8411ULL: goto x86_l_20db;
	case 8418ULL: goto x86_l_20e2;
	case 8424ULL: goto x86_l_20e8;
	case 8427ULL: goto x86_l_20eb;
	case 8432ULL: goto x86_l_20f0;
	case 8437ULL: goto x86_l_20f5;
	case 8442ULL: goto x86_l_20fa;
	case 8448ULL: goto x86_l_2100;
	case 8451ULL: goto x86_l_2103;
	case 8456ULL: goto x86_l_2108;
	case 8461ULL: goto x86_l_210d;
	case 8464ULL: goto x86_l_2110;
	case 8466ULL: goto x86_l_2112;
	case 8471ULL: goto x86_l_2117;
	case 8473ULL: goto x86_l_2119;
	case 8479ULL: goto x86_l_211f;
	case 8484ULL: goto x86_l_2124;
	case 8490ULL: goto x86_l_212a;
	case 8496ULL: goto x86_l_2130;
	case 8501ULL: goto x86_l_2135;
	case 8507ULL: goto x86_l_213b;
	case 8512ULL: goto x86_l_2140;
	case 8516ULL: goto x86_l_2144;
	case 8523ULL: goto x86_l_214b;
	case 8527ULL: goto x86_l_214f;
	case 8531ULL: goto x86_l_2153;
	case 8535ULL: goto x86_l_2157;
	case 8539ULL: goto x86_l_215b;
	case 8543ULL: goto x86_l_215f;
	case 8549ULL: goto x86_l_2165;
	case 8559ULL: goto x86_l_216f;
	case 8563ULL: goto x86_l_2173;
	case 8569ULL: goto x86_l_2179;
	case 8572ULL: goto x86_l_217c;
	case 8577ULL: goto x86_l_2181;
	case 8581ULL: goto x86_l_2185;
	case 8584ULL: goto x86_l_2188;
	case 8587ULL: goto x86_l_218b;
	case 8592ULL: goto x86_l_2190;
	case 8594ULL: goto x86_l_2192;
	case 8597ULL: goto x86_l_2195;
	case 8603ULL: goto x86_l_219b;
	case 8607ULL: goto x86_l_219f;
	case 8610ULL: goto x86_l_21a2;
	case 8612ULL: goto x86_l_21a4;
	case 8614ULL: goto x86_l_21a6;
	case 8616ULL: goto x86_l_21a8;
	case 8619ULL: goto x86_l_21ab;
	case 8621ULL: goto x86_l_21ad;
	case 8624ULL: goto x86_l_21b0;
	case 8626ULL: goto x86_l_21b2;
	case 8632ULL: goto x86_l_21b8;
	case 8636ULL: goto x86_l_21bc;
	case 8638ULL: goto x86_l_21be;
	case 8641ULL: goto x86_l_21c1;
	case 8643ULL: goto x86_l_21c3;
	case 8646ULL: goto x86_l_21c6;
	case 8648ULL: goto x86_l_21c8;
	case 8653ULL: goto x86_l_21cd;
	case 8655ULL: goto x86_l_21cf;
	case 8661ULL: goto x86_l_21d5;
	case 8665ULL: goto x86_l_21d9;
	case 8667ULL: goto x86_l_21db;
	case 8671ULL: goto x86_l_21df;
	case 8678ULL: goto x86_l_21e6;
	case 8682ULL: goto x86_l_21ea;
	case 8684ULL: goto x86_l_21ec;
	case 8688ULL: goto x86_l_21f0;
	case 8693ULL: goto x86_l_21f5;
	case 8697ULL: goto x86_l_21f9;
	case 8704ULL: goto x86_l_2200;
	case 8708ULL: goto x86_l_2204;
	case 8710ULL: goto x86_l_2206;
	case 8714ULL: goto x86_l_220a;
	case 8718ULL: goto x86_l_220e;
	case 8722ULL: goto x86_l_2212;
	case 8726ULL: goto x86_l_2216;
	case 8730ULL: goto x86_l_221a;
	case 8736ULL: goto x86_l_2220;
	case 8746ULL: goto x86_l_222a;
	case 8750ULL: goto x86_l_222e;
	case 8756ULL: goto x86_l_2234;
	case 8759ULL: goto x86_l_2237;
	case 8764ULL: goto x86_l_223c;
	case 8768ULL: goto x86_l_2240;
	case 8771ULL: goto x86_l_2243;
	case 8774ULL: goto x86_l_2246;
	case 8779ULL: goto x86_l_224b;
	case 8781ULL: goto x86_l_224d;
	case 8784ULL: goto x86_l_2250;
	case 8790ULL: goto x86_l_2256;
	case 8794ULL: goto x86_l_225a;
	case 8797ULL: goto x86_l_225d;
	case 8799ULL: goto x86_l_225f;
	case 8801ULL: goto x86_l_2261;
	case 8803ULL: goto x86_l_2263;
	case 8806ULL: goto x86_l_2266;
	case 8808ULL: goto x86_l_2268;
	case 8811ULL: goto x86_l_226b;
	case 8813ULL: goto x86_l_226d;
	case 8819ULL: goto x86_l_2273;
	case 8823ULL: goto x86_l_2277;
	case 8825ULL: goto x86_l_2279;
	case 8828ULL: goto x86_l_227c;
	case 8830ULL: goto x86_l_227e;
	case 8833ULL: goto x86_l_2281;
	case 8835ULL: goto x86_l_2283;
	case 8840ULL: goto x86_l_2288;
	case 8842ULL: goto x86_l_228a;
	case 8848ULL: goto x86_l_2290;
	case 8852ULL: goto x86_l_2294;
	case 8854ULL: goto x86_l_2296;
	case 8858ULL: goto x86_l_229a;
	case 8865ULL: goto x86_l_22a1;
	case 8869ULL: goto x86_l_22a5;
	case 8871ULL: goto x86_l_22a7;
	case 8875ULL: goto x86_l_22ab;
	case 8882ULL: goto x86_l_22b2;
	case 8886ULL: goto x86_l_22b6;
	case 8888ULL: goto x86_l_22b8;
	case 8892ULL: goto x86_l_22bc;
	case 8896ULL: goto x86_l_22c0;
	case 8900ULL: goto x86_l_22c4;
	case 8904ULL: goto x86_l_22c8;
	case 8908ULL: goto x86_l_22cc;
	case 8914ULL: goto x86_l_22d2;
	case 8924ULL: goto x86_l_22dc;
	case 8928ULL: goto x86_l_22e0;
	case 8934ULL: goto x86_l_22e6;
	case 8937ULL: goto x86_l_22e9;
	case 8942ULL: goto x86_l_22ee;
	case 8946ULL: goto x86_l_22f2;
	case 8949ULL: goto x86_l_22f5;
	case 8952ULL: goto x86_l_22f8;
	case 8957ULL: goto x86_l_22fd;
	case 8959ULL: goto x86_l_22ff;
	case 8962ULL: goto x86_l_2302;
	case 8968ULL: goto x86_l_2308;
	case 8972ULL: goto x86_l_230c;
	case 8975ULL: goto x86_l_230f;
	case 8977ULL: goto x86_l_2311;
	case 8979ULL: goto x86_l_2313;
	case 8981ULL: goto x86_l_2315;
	case 8984ULL: goto x86_l_2318;
	case 8986ULL: goto x86_l_231a;
	case 8989ULL: goto x86_l_231d;
	case 8991ULL: goto x86_l_231f;
	case 8997ULL: goto x86_l_2325;
	case 9001ULL: goto x86_l_2329;
	case 9003ULL: goto x86_l_232b;
	case 9006ULL: goto x86_l_232e;
	case 9008ULL: goto x86_l_2330;
	case 9011ULL: goto x86_l_2333;
	case 9013ULL: goto x86_l_2335;
	case 9018ULL: goto x86_l_233a;
	case 9020ULL: goto x86_l_233c;
	case 9026ULL: goto x86_l_2342;
	case 9030ULL: goto x86_l_2346;
	case 9032ULL: goto x86_l_2348;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1d00:
	/* 0x1d00: je     26ae <generic_retuprobe_event+0x26ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9902ULL;
	}
x86_l_1d06:
	/* 0x1d06: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1d09:
	/* 0x1d09: mov    WORD PTR [rax],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d0c:
	/* 0x1d0c: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_1d10:
	/* 0x1d10: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_1d14:
	/* 0x1d14: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1d17:
	/* 0x1d17: add    rdi,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_1d1b:
	/* 0x1d1b: lea    rdx,[r13+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1d1f:
	/* 0x1d1f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d24:
	/* 0x1d24: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_1d27:
	/* 0x1d27: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1d2c:
	/* 0x1d2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d2e:
	/* 0x1d2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d31:
	/* 0x1d31: js     26ae <generic_retuprobe_event+0x26ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9902ULL;
	}
x86_l_1d37:
	/* 0x1d37: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_1d3b:
	/* 0x1d3b: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_1d3e:
	/* 0x1d3e: jg     2038 <generic_retuprobe_event+0x2038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2038;
	}
x86_l_1d44:
	/* 0x1d44: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d46:
	/* 0x1d46: je     2060 <generic_retuprobe_event+0x2060> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2060;
	}
x86_l_1d4c:
	/* 0x1d4c: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1d4f:
	/* 0x1d4f: je     2060 <generic_retuprobe_event+0x2060> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2060;
	}
x86_l_1d55:
	/* 0x1d55: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_1d58:
	/* 0x1d58: jne    21ec <generic_retuprobe_event+0x21ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21ec;
	}
x86_l_1d5e:
	/* 0x1d5e: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_1d64:
	/* 0x1d64: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_1d68:
	/* 0x1d68: jmp    214f <generic_retuprobe_event+0x214f> */
	goto x86_l_214f;
x86_l_1d6d:
	/* 0x1d6d: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1d71:
	/* 0x1d71: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d76:
	/* 0x1d76: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d7b:
	/* 0x1d7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d7d:
	/* 0x1d7d: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d81:
	/* 0x1d81: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d86:
	/* 0x1d86: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1d89:
	/* 0x1d89: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d8e:
	/* 0x1d8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d90:
	/* 0x1d90: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d95:
	/* 0x1d95: lea    rdi,[rbx+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1d9c:
	/* 0x1d9c: lea    r12,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1da0:
	/* 0x1da0: add    r13,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_1da4:
	/* 0x1da4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1da9:
	/* 0x1da9: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1dae:
	/* 0x1dae: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1db1:
	/* 0x1db1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1db3:
	/* 0x1db3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1db6:
	/* 0x1db6: add    rdi,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_1dbd:
	/* 0x1dbd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dc2:
	/* 0x1dc2: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1dc7:
	/* 0x1dc7: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1dca:
	/* 0x1dca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dcc:
	/* 0x1dcc: movzx  eax,WORD PTR [rbx+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1dd3:
	/* 0x1dd3: movbe  WORD PTR [rbx+0xbe],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1ddc:
	/* 0x1ddc: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1de1:
	/* 0x1de1: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1de6:
	/* 0x1de6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1deb:
	/* 0x1deb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_1df2:
	/* 0x1df2: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1df7:
	/* 0x1df7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1df9:
	/* 0x1df9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dfc:
	/* 0x1dfc: je     1e19 <generic_retuprobe_event+0x1e19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e19;
	}
x86_l_1dfe:
	/* 0x1dfe: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e00:
	/* 0x1e00: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1e08:
	/* 0x1e08: mov    DWORD PTR [rdx+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e0b:
	/* 0x1e0b: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e0f:
	/* 0x1e0f: mov    QWORD PTR [rdx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e13:
	/* 0x1e13: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e16:
	/* 0x1e16: mov    DWORD PTR [rdx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1e19:
	/* 0x1e19: mov    ebp,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_1e1e:
	/* 0x1e1e: jmp    1e30 <generic_retuprobe_event+0x1e30> */
	goto x86_l_1e30;
x86_l_1e20:
	/* 0x1e20: mov    QWORD PTR [rbx+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1e2b:
	/* 0x1e2b: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_1e30:
	/* 0x1e30: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e35:
	/* 0x1e35: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e3a:
	/* 0x1e3a: jmp    a17 <generic_retuprobe_event+0xa17> */
	return 2583ULL;
x86_l_1e3f:
	/* 0x1e3f: lea    rdi,[rcx+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1e46:
	/* 0x1e46: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e4b:
	/* 0x1e4b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e50:
	/* 0x1e50: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e55:
	/* 0x1e55: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_1e58:
	/* 0x1e58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e5a:
	/* 0x1e5a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e5d:
	/* 0x1e5d: add    rdi,0x9e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 158ULL);
x86_l_1e64:
	/* 0x1e64: add    r12,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1e68:
	/* 0x1e68: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e6d:
	/* 0x1e6d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1e72:
	/* 0x1e72: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1e75:
	/* 0x1e75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e77:
	/* 0x1e77: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e7c:
	/* 0x1e7c: movzx  eax,WORD PTR [rcx+0x9e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_1e83:
	/* 0x1e83: movbe  WORD PTR [rcx+0x9e],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_1e8c:
	/* 0x1e8c: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_1e91:
	/* 0x1e91: mov    ebp,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_1e96:
	/* 0x1e96: jmp    a1c <generic_retuprobe_event+0xa1c> */
	return 2588ULL;
x86_l_1e9b:
	/* 0x1e9b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ea0:
	/* 0x1ea0: lea    rdi,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1ea7:
	/* 0x1ea7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1eac:
	/* 0x1eac: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1eb1:
	/* 0x1eb1: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_1eb6:
	/* 0x1eb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eb8:
	/* 0x1eb8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ebb:
	/* 0x1ebb: js     1c0c <generic_retuprobe_event+0x1c0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7180ULL;
	}
x86_l_1ec1:
	/* 0x1ec1: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_1ec4:
	/* 0x1ec4: lea    rdx,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ec8:
	/* 0x1ec8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ecd:
	/* 0x1ecd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ed2:
	/* 0x1ed2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ed7:
	/* 0x1ed7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ed9:
	/* 0x1ed9: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ede:
	/* 0x1ede: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1ee5:
	/* 0x1ee5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1eea:
	/* 0x1eea: mov    edx,0x348 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 840ULL);
x86_l_1eef:
	/* 0x1eef: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_1ef4:
	/* 0x1ef4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ef9:
	/* 0x1ef9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1efb:
	/* 0x1efb: lea    rdx,[rbx+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1eff:
	/* 0x1eff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f04:
	/* 0x1f04: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f09:
	/* 0x1f09: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f0e:
	/* 0x1f0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f10:
	/* 0x1f10: mov    ebp,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 80ULL);
x86_l_1f15:
	/* 0x1f15: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f18:
	/* 0x1f18: jne    1c0e <generic_retuprobe_event+0x1c0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7182ULL;
	}
x86_l_1f1e:
	/* 0x1f1e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f20:
	/* 0x1f20: cmp    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1f25:
	/* 0x1f25: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1f28:
	/* 0x1f28: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f2d:
	/* 0x1f2d: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f2f:
	/* 0x1f2f: jmp    1c0e <generic_retuprobe_event+0x1c0e> */
	return 7182ULL;
x86_l_1f34:
	/* 0x1f34: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f36:
	/* 0x1f36: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f3b:
	/* 0x1f3b: jmp    a17 <generic_retuprobe_event+0xa17> */
	return 2583ULL;
x86_l_1f40:
	/* 0x1f40: add    r12,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_1f44:
	/* 0x1f44: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f49:
	/* 0x1f49: mov    esi,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 107ULL);
x86_l_1f4e:
	/* 0x1f4e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f51:
	/* 0x1f51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f53:
	/* 0x1f53: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1f56:
	/* 0x1f56: mov    al,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 107ULL);
x86_l_1f58:
	/* 0x1f58: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1f5a:
	/* 0x1f5a: js     1f67 <generic_retuprobe_event+0x1f67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1f67;
	}
x86_l_1f5c:
	/* 0x1f5c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f61:
	/* 0x1f61: mov    BYTE PTR [rcx+0x9f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 159ULL);
x86_l_1f67:
	/* 0x1f67: mov    ebp,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 112ULL);
x86_l_1f6c:
	/* 0x1f6c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f71:
	/* 0x1f71: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_1f74:
	/* 0x1f74: jmp    a17 <generic_retuprobe_event+0xa17> */
	return 2583ULL;
x86_l_1f79:
	/* 0x1f79: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1f7d:
	/* 0x1f7d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f82:
	/* 0x1f82: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1f87:
	/* 0x1f87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f89:
	/* 0x1f89: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f8d:
	/* 0x1f8d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f92:
	/* 0x1f92: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1f95:
	/* 0x1f95: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1f9a:
	/* 0x1f9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f9c:
	/* 0x1f9c: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fa1:
	/* 0x1fa1: lea    rdi,[rbx+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1fa8:
	/* 0x1fa8: lea    r12,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1fac:
	/* 0x1fac: add    r13,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_1fb0:
	/* 0x1fb0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fb5:
	/* 0x1fb5: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1fba:
	/* 0x1fba: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1fbd:
	/* 0x1fbd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fbf:
	/* 0x1fbf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1fc2:
	/* 0x1fc2: add    rdi,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_1fc9:
	/* 0x1fc9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fce:
	/* 0x1fce: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1fd3:
	/* 0x1fd3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1fd6:
	/* 0x1fd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fd8:
	/* 0x1fd8: movzx  eax,WORD PTR [rbx+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1fdf:
	/* 0x1fdf: movbe  WORD PTR [rbx+0xbe],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1fe8:
	/* 0x1fe8: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fed:
	/* 0x1fed: mov    rax,QWORD PTR [rax+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1ff4:
	/* 0x1ff4: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ff9:
	/* 0x1ff9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ffe:
	/* 0x1ffe: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_2005:
	/* 0x2005: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_200a:
	/* 0x200a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_200c:
	/* 0x200c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_200f:
	/* 0x200f: je     2024 <generic_retuprobe_event+0x2024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2024;
	}
x86_l_2011:
	/* 0x2011: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2013:
	/* 0x2013: mov    DWORD PTR [rbp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2016:
	/* 0x2016: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_201a:
	/* 0x201a: mov    QWORD PTR [rbp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_201e:
	/* 0x201e: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2021:
	/* 0x2021: mov    DWORD PTR [rbp+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2024:
	/* 0x2024: mov    ebp,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_2029:
	/* 0x2029: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_202e:
	/* 0x202e: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2033:
	/* 0x2033: jmp    a17 <generic_retuprobe_event+0xa17> */
	return 2583ULL;
x86_l_2038:
	/* 0x2038: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_203b:
	/* 0x203b: je     2140 <generic_retuprobe_event+0x2140> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2140;
	}
x86_l_2041:
	/* 0x2041: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2044:
	/* 0x2044: je     2060 <generic_retuprobe_event+0x2060> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2060;
	}
x86_l_2046:
	/* 0x2046: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_204b:
	/* 0x204b: jne    21ec <generic_retuprobe_event+0x21ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21ec;
	}
x86_l_2051:
	/* 0x2051: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2057:
	/* 0x2057: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_205b:
	/* 0x205b: jmp    214f <generic_retuprobe_event+0x214f> */
	goto x86_l_214f;
x86_l_2060:
	/* 0x2060: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2064:
	/* 0x2064: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_206b:
	/* 0x206b: jmp    214b <generic_retuprobe_event+0x214b> */
	goto x86_l_214b;
x86_l_2070:
	/* 0x2070: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2072:
	/* 0x2072: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2077:
	/* 0x2077: cmp    QWORD PTR [rsp+0x80],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813891ULL);
x86_l_2080:
	/* 0x2080: jne    208c <generic_retuprobe_event+0x208c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_208c;
	}
x86_l_2082:
	/* 0x2082: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2087:
	/* 0x2087: jmp    2c9 <generic_retuprobe_event+0x2c9> */
	return 713ULL;
x86_l_208c:
	/* 0x208c: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2094:
	/* 0x2094: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2098:
	/* 0x2098: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_209d:
	/* 0x209d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20a2:
	/* 0x20a2: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_20a7:
	/* 0x20a7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_20ac:
	/* 0x20ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ae:
	/* 0x20ae: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_20b3:
	/* 0x20b3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20b5:
	/* 0x20b5: js     29e9 <generic_retuprobe_event+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10729ULL;
	}
x86_l_20bb:
	/* 0x20bb: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_20c0:
	/* 0x20c0: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20c5:
	/* 0x20c5: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_20c8:
	/* 0x20c8: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_20cb:
	/* 0x20cb: cmovb  rbx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_20cf:
	/* 0x20cf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20d2:
	/* 0x20d2: cmovne rdx,rbx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RBX, X86_WIDTH_64, X86_CC_NE);
x86_l_20d6:
	/* 0x20d6: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_20db:
	/* 0x20db: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_20e2:
	/* 0x20e2: ja     29e9 <generic_retuprobe_event+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10729ULL;
	}
x86_l_20e8:
	/* 0x20e8: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_20eb:
	/* 0x20eb: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20f0:
	/* 0x20f0: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_20f5:
	/* 0x20f5: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20fa:
	/* 0x20fa: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2100:
	/* 0x2100: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2103:
	/* 0x2103: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2108:
	/* 0x2108: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_210d:
	/* 0x210d: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_2110:
	/* 0x2110: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2112:
	/* 0x2112: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2117:
	/* 0x2117: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2119:
	/* 0x2119: js     29e9 <generic_retuprobe_event+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10729ULL;
	}
x86_l_211f:
	/* 0x211f: add    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_2124:
	/* 0x2124: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_212a:
	/* 0x212a: je     2420 <generic_retuprobe_event+0x2420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9248ULL;
	}
x86_l_2130:
	/* 0x2130: sub    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 24ULL);
x86_l_2135:
	/* 0x2135: jne    2427 <generic_retuprobe_event+0x2427> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9255ULL;
	}
x86_l_213b:
	/* 0x213b: jmp    2082 <generic_retuprobe_event+0x2082> */
	goto x86_l_2082;
x86_l_2140:
	/* 0x2140: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2144:
	/* 0x2144: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_214b:
	/* 0x214b: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_214f:
	/* 0x214f: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2153:
	/* 0x2153: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2157:
	/* 0x2157: movzx  ecx,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_215b:
	/* 0x215b: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_215f:
	/* 0x215f: ja     2874 <generic_retuprobe_event+0x2874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10356ULL;
	}
x86_l_2165:
	/* 0x2165: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_216f:
	/* 0x216f: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2173:
	/* 0x2173: jae    2874 <generic_retuprobe_event+0x2874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10356ULL;
	}
x86_l_2179:
	/* 0x2179: mov    BYTE PTR [rbp+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_217c:
	/* 0x217c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2181:
	/* 0x2181: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2185:
	/* 0x2185: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2188:
	/* 0x2188: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_218b:
	/* 0x218b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2190:
	/* 0x2190: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2192:
	/* 0x2192: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2195:
	/* 0x2195: js     26ae <generic_retuprobe_event+0x26ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9902ULL;
	}
x86_l_219b:
	/* 0x219b: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_219f:
	/* 0x219f: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_21a2:
	/* 0x21a2: jg     21be <generic_retuprobe_event+0x21be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_21be;
	}
x86_l_21a4:
	/* 0x21a4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21a6:
	/* 0x21a6: je     21db <generic_retuprobe_event+0x21db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21db;
	}
x86_l_21a8:
	/* 0x21a8: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_21ab:
	/* 0x21ab: je     21db <generic_retuprobe_event+0x21db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21db;
	}
x86_l_21ad:
	/* 0x21ad: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_21b0:
	/* 0x21b0: jne    2206 <generic_retuprobe_event+0x2206> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2206;
	}
x86_l_21b2:
	/* 0x21b2: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_21b8:
	/* 0x21b8: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_21bc:
	/* 0x21bc: jmp    220a <generic_retuprobe_event+0x220a> */
	goto x86_l_220a;
x86_l_21be:
	/* 0x21be: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_21c1:
	/* 0x21c1: je     21f5 <generic_retuprobe_event+0x21f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21f5;
	}
x86_l_21c3:
	/* 0x21c3: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_21c6:
	/* 0x21c6: je     21db <generic_retuprobe_event+0x21db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21db;
	}
x86_l_21c8:
	/* 0x21c8: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_21cd:
	/* 0x21cd: jne    2206 <generic_retuprobe_event+0x2206> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2206;
	}
x86_l_21cf:
	/* 0x21cf: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_21d5:
	/* 0x21d5: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_21d9:
	/* 0x21d9: jmp    220a <generic_retuprobe_event+0x220a> */
	goto x86_l_220a;
x86_l_21db:
	/* 0x21db: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_21df:
	/* 0x21df: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_21e6:
	/* 0x21e6: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_21ea:
	/* 0x21ea: jmp    220a <generic_retuprobe_event+0x220a> */
	goto x86_l_220a;
x86_l_21ec:
	/* 0x21ec: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_21f0:
	/* 0x21f0: jmp    214f <generic_retuprobe_event+0x214f> */
	goto x86_l_214f;
x86_l_21f5:
	/* 0x21f5: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_21f9:
	/* 0x21f9: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2200:
	/* 0x2200: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2204:
	/* 0x2204: jmp    220a <generic_retuprobe_event+0x220a> */
	goto x86_l_220a;
x86_l_2206:
	/* 0x2206: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_220a:
	/* 0x220a: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_220e:
	/* 0x220e: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2212:
	/* 0x2212: movzx  ecx,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2216:
	/* 0x2216: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_221a:
	/* 0x221a: ja     2874 <generic_retuprobe_event+0x2874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10356ULL;
	}
x86_l_2220:
	/* 0x2220: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_222a:
	/* 0x222a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_222e:
	/* 0x222e: jae    2874 <generic_retuprobe_event+0x2874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10356ULL;
	}
x86_l_2234:
	/* 0x2234: mov    BYTE PTR [rbp+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2237:
	/* 0x2237: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_223c:
	/* 0x223c: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2240:
	/* 0x2240: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2243:
	/* 0x2243: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2246:
	/* 0x2246: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_224b:
	/* 0x224b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_224d:
	/* 0x224d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2250:
	/* 0x2250: js     26ae <generic_retuprobe_event+0x26ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9902ULL;
	}
x86_l_2256:
	/* 0x2256: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_225a:
	/* 0x225a: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_225d:
	/* 0x225d: jg     2279 <generic_retuprobe_event+0x2279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2279;
	}
x86_l_225f:
	/* 0x225f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2261:
	/* 0x2261: je     2296 <generic_retuprobe_event+0x2296> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2296;
	}
x86_l_2263:
	/* 0x2263: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2266:
	/* 0x2266: je     2296 <generic_retuprobe_event+0x2296> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2296;
	}
x86_l_2268:
	/* 0x2268: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_226b:
	/* 0x226b: jne    22b8 <generic_retuprobe_event+0x22b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22b8;
	}
x86_l_226d:
	/* 0x226d: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2273:
	/* 0x2273: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2277:
	/* 0x2277: jmp    22bc <generic_retuprobe_event+0x22bc> */
	goto x86_l_22bc;
x86_l_2279:
	/* 0x2279: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_227c:
	/* 0x227c: je     22a7 <generic_retuprobe_event+0x22a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22a7;
	}
x86_l_227e:
	/* 0x227e: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2281:
	/* 0x2281: je     2296 <generic_retuprobe_event+0x2296> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2296;
	}
x86_l_2283:
	/* 0x2283: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2288:
	/* 0x2288: jne    22b8 <generic_retuprobe_event+0x22b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22b8;
	}
x86_l_228a:
	/* 0x228a: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2290:
	/* 0x2290: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2294:
	/* 0x2294: jmp    22bc <generic_retuprobe_event+0x22bc> */
	goto x86_l_22bc;
x86_l_2296:
	/* 0x2296: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_229a:
	/* 0x229a: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_22a1:
	/* 0x22a1: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_22a5:
	/* 0x22a5: jmp    22bc <generic_retuprobe_event+0x22bc> */
	goto x86_l_22bc;
x86_l_22a7:
	/* 0x22a7: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_22ab:
	/* 0x22ab: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_22b2:
	/* 0x22b2: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_22b6:
	/* 0x22b6: jmp    22bc <generic_retuprobe_event+0x22bc> */
	goto x86_l_22bc;
x86_l_22b8:
	/* 0x22b8: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_22bc:
	/* 0x22bc: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_22c0:
	/* 0x22c0: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22c4:
	/* 0x22c4: movzx  ecx,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_22c8:
	/* 0x22c8: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_22cc:
	/* 0x22cc: ja     2874 <generic_retuprobe_event+0x2874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10356ULL;
	}
x86_l_22d2:
	/* 0x22d2: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_22dc:
	/* 0x22dc: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_22e0:
	/* 0x22e0: jae    2874 <generic_retuprobe_event+0x2874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10356ULL;
	}
x86_l_22e6:
	/* 0x22e6: mov    BYTE PTR [rbp+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_22e9:
	/* 0x22e9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22ee:
	/* 0x22ee: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_22f2:
	/* 0x22f2: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_22f5:
	/* 0x22f5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_22f8:
	/* 0x22f8: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_22fd:
	/* 0x22fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22ff:
	/* 0x22ff: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2302:
	/* 0x2302: js     26ae <generic_retuprobe_event+0x26ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9902ULL;
	}
x86_l_2308:
	/* 0x2308: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_230c:
	/* 0x230c: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_230f:
	/* 0x230f: jg     232b <generic_retuprobe_event+0x232b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_232b;
	}
x86_l_2311:
	/* 0x2311: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2313:
	/* 0x2313: je     2348 <generic_retuprobe_event+0x2348> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2348;
	}
x86_l_2315:
	/* 0x2315: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2318:
	/* 0x2318: je     2348 <generic_retuprobe_event+0x2348> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2348;
	}
x86_l_231a:
	/* 0x231a: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_231d:
	/* 0x231d: jne    236a <generic_retuprobe_event+0x236a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9066ULL;
	}
x86_l_231f:
	/* 0x231f: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2325:
	/* 0x2325: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2329:
	/* 0x2329: jmp    236e <generic_retuprobe_event+0x236e> */
	return 9070ULL;
x86_l_232b:
	/* 0x232b: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_232e:
	/* 0x232e: je     2359 <generic_retuprobe_event+0x2359> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9049ULL;
	}
x86_l_2330:
	/* 0x2330: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2333:
	/* 0x2333: je     2348 <generic_retuprobe_event+0x2348> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2348;
	}
x86_l_2335:
	/* 0x2335: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_233a:
	/* 0x233a: jne    236a <generic_retuprobe_event+0x236a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9066ULL;
	}
x86_l_233c:
	/* 0x233c: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2342:
	/* 0x2342: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2346:
	/* 0x2346: jmp    236e <generic_retuprobe_event+0x236e> */
	return 9070ULL;
x86_l_2348:
	/* 0x2348: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
	return 9036ULL;
}

static __noinline __u64 tetragon_bpf_multi_retuprobe_v61_generic_retuprobe_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9036ULL: goto x86_l_234c;
	case 9043ULL: goto x86_l_2353;
	case 9047ULL: goto x86_l_2357;
	case 9049ULL: goto x86_l_2359;
	case 9053ULL: goto x86_l_235d;
	case 9060ULL: goto x86_l_2364;
	case 9064ULL: goto x86_l_2368;
	case 9066ULL: goto x86_l_236a;
	case 9070ULL: goto x86_l_236e;
	case 9074ULL: goto x86_l_2372;
	case 9078ULL: goto x86_l_2376;
	case 9082ULL: goto x86_l_237a;
	case 9086ULL: goto x86_l_237e;
	case 9092ULL: goto x86_l_2384;
	case 9102ULL: goto x86_l_238e;
	case 9106ULL: goto x86_l_2392;
	case 9112ULL: goto x86_l_2398;
	case 9115ULL: goto x86_l_239b;
	case 9120ULL: goto x86_l_23a0;
	case 9124ULL: goto x86_l_23a4;
	case 9127ULL: goto x86_l_23a7;
	case 9130ULL: goto x86_l_23aa;
	case 9135ULL: goto x86_l_23af;
	case 9137ULL: goto x86_l_23b1;
	case 9140ULL: goto x86_l_23b4;
	case 9146ULL: goto x86_l_23ba;
	case 9150ULL: goto x86_l_23be;
	case 9153ULL: goto x86_l_23c1;
	case 9155ULL: goto x86_l_23c3;
	case 9157ULL: goto x86_l_23c5;
	case 9159ULL: goto x86_l_23c7;
	case 9162ULL: goto x86_l_23ca;
	case 9164ULL: goto x86_l_23cc;
	case 9167ULL: goto x86_l_23cf;
	case 9173ULL: goto x86_l_23d5;
	case 9179ULL: goto x86_l_23db;
	case 9183ULL: goto x86_l_23df;
	case 9188ULL: goto x86_l_23e4;
	case 9191ULL: goto x86_l_23e7;
	case 9197ULL: goto x86_l_23ed;
	case 9200ULL: goto x86_l_23f0;
	case 9202ULL: goto x86_l_23f2;
	case 9207ULL: goto x86_l_23f7;
	case 9213ULL: goto x86_l_23fd;
	case 9219ULL: goto x86_l_2403;
	case 9223ULL: goto x86_l_2407;
	case 9228ULL: goto x86_l_240c;
	case 9232ULL: goto x86_l_2410;
	case 9239ULL: goto x86_l_2417;
	case 9243ULL: goto x86_l_241b;
	case 9248ULL: goto x86_l_2420;
	case 9250ULL: goto x86_l_2422;
	case 9255ULL: goto x86_l_2427;
	case 9264ULL: goto x86_l_2430;
	case 9270ULL: goto x86_l_2436;
	case 9278ULL: goto x86_l_243e;
	case 9282ULL: goto x86_l_2442;
	case 9287ULL: goto x86_l_2447;
	case 9292ULL: goto x86_l_244c;
	case 9297ULL: goto x86_l_2451;
	case 9302ULL: goto x86_l_2456;
	case 9304ULL: goto x86_l_2458;
	case 9309ULL: goto x86_l_245d;
	case 9311ULL: goto x86_l_245f;
	case 9317ULL: goto x86_l_2465;
	case 9322ULL: goto x86_l_246a;
	case 9327ULL: goto x86_l_246f;
	case 9330ULL: goto x86_l_2472;
	case 9333ULL: goto x86_l_2475;
	case 9337ULL: goto x86_l_2479;
	case 9340ULL: goto x86_l_247c;
	case 9344ULL: goto x86_l_2480;
	case 9349ULL: goto x86_l_2485;
	case 9354ULL: goto x86_l_248a;
	case 9361ULL: goto x86_l_2491;
	case 9367ULL: goto x86_l_2497;
	case 9370ULL: goto x86_l_249a;
	case 9375ULL: goto x86_l_249f;
	case 9378ULL: goto x86_l_24a2;
	case 9384ULL: goto x86_l_24a8;
	case 9387ULL: goto x86_l_24ab;
	case 9392ULL: goto x86_l_24b0;
	case 9397ULL: goto x86_l_24b5;
	case 9402ULL: goto x86_l_24ba;
	case 9404ULL: goto x86_l_24bc;
	case 9409ULL: goto x86_l_24c1;
	case 9411ULL: goto x86_l_24c3;
	case 9417ULL: goto x86_l_24c9;
	case 9422ULL: goto x86_l_24ce;
	case 9427ULL: goto x86_l_24d3;
	case 9433ULL: goto x86_l_24d9;
	case 9439ULL: goto x86_l_24df;
	case 9444ULL: goto x86_l_24e4;
	case 9450ULL: goto x86_l_24ea;
	case 9455ULL: goto x86_l_24ef;
	case 9459ULL: goto x86_l_24f3;
	case 9466ULL: goto x86_l_24fa;
	case 9470ULL: goto x86_l_24fe;
	case 9472ULL: goto x86_l_2500;
	case 9476ULL: goto x86_l_2504;
	case 9480ULL: goto x86_l_2508;
	case 9484ULL: goto x86_l_250c;
	case 9488ULL: goto x86_l_2510;
	case 9492ULL: goto x86_l_2514;
	case 9498ULL: goto x86_l_251a;
	case 9508ULL: goto x86_l_2524;
	case 9512ULL: goto x86_l_2528;
	case 9518ULL: goto x86_l_252e;
	case 9521ULL: goto x86_l_2531;
	case 9526ULL: goto x86_l_2536;
	case 9530ULL: goto x86_l_253a;
	case 9533ULL: goto x86_l_253d;
	case 9536ULL: goto x86_l_2540;
	case 9541ULL: goto x86_l_2545;
	case 9543ULL: goto x86_l_2547;
	case 9546ULL: goto x86_l_254a;
	case 9552ULL: goto x86_l_2550;
	case 9556ULL: goto x86_l_2554;
	case 9559ULL: goto x86_l_2557;
	case 9561ULL: goto x86_l_2559;
	case 9563ULL: goto x86_l_255b;
	case 9565ULL: goto x86_l_255d;
	case 9568ULL: goto x86_l_2560;
	case 9570ULL: goto x86_l_2562;
	case 9573ULL: goto x86_l_2565;
	case 9575ULL: goto x86_l_2567;
	case 9581ULL: goto x86_l_256d;
	case 9585ULL: goto x86_l_2571;
	case 9587ULL: goto x86_l_2573;
	case 9590ULL: goto x86_l_2576;
	case 9592ULL: goto x86_l_2578;
	case 9595ULL: goto x86_l_257b;
	case 9597ULL: goto x86_l_257d;
	case 9602ULL: goto x86_l_2582;
	case 9604ULL: goto x86_l_2584;
	case 9610ULL: goto x86_l_258a;
	case 9614ULL: goto x86_l_258e;
	case 9616ULL: goto x86_l_2590;
	case 9620ULL: goto x86_l_2594;
	case 9627ULL: goto x86_l_259b;
	case 9631ULL: goto x86_l_259f;
	case 9633ULL: goto x86_l_25a1;
	case 9637ULL: goto x86_l_25a5;
	case 9644ULL: goto x86_l_25ac;
	case 9648ULL: goto x86_l_25b0;
	case 9650ULL: goto x86_l_25b2;
	case 9654ULL: goto x86_l_25b6;
	case 9658ULL: goto x86_l_25ba;
	case 9662ULL: goto x86_l_25be;
	case 9666ULL: goto x86_l_25c2;
	case 9670ULL: goto x86_l_25c6;
	case 9676ULL: goto x86_l_25cc;
	case 9686ULL: goto x86_l_25d6;
	case 9690ULL: goto x86_l_25da;
	case 9696ULL: goto x86_l_25e0;
	case 9699ULL: goto x86_l_25e3;
	case 9704ULL: goto x86_l_25e8;
	case 9708ULL: goto x86_l_25ec;
	case 9711ULL: goto x86_l_25ef;
	case 9714ULL: goto x86_l_25f2;
	case 9719ULL: goto x86_l_25f7;
	case 9721ULL: goto x86_l_25f9;
	case 9724ULL: goto x86_l_25fc;
	case 9730ULL: goto x86_l_2602;
	case 9734ULL: goto x86_l_2606;
	case 9737ULL: goto x86_l_2609;
	case 9739ULL: goto x86_l_260b;
	case 9741ULL: goto x86_l_260d;
	case 9743ULL: goto x86_l_260f;
	case 9746ULL: goto x86_l_2612;
	case 9748ULL: goto x86_l_2614;
	case 9751ULL: goto x86_l_2617;
	case 9753ULL: goto x86_l_2619;
	case 9759ULL: goto x86_l_261f;
	case 9763ULL: goto x86_l_2623;
	case 9765ULL: goto x86_l_2625;
	case 9768ULL: goto x86_l_2628;
	case 9770ULL: goto x86_l_262a;
	case 9773ULL: goto x86_l_262d;
	case 9775ULL: goto x86_l_262f;
	case 9780ULL: goto x86_l_2634;
	case 9782ULL: goto x86_l_2636;
	case 9788ULL: goto x86_l_263c;
	case 9792ULL: goto x86_l_2640;
	case 9794ULL: goto x86_l_2642;
	case 9798ULL: goto x86_l_2646;
	case 9805ULL: goto x86_l_264d;
	case 9809ULL: goto x86_l_2651;
	case 9811ULL: goto x86_l_2653;
	case 9815ULL: goto x86_l_2657;
	case 9822ULL: goto x86_l_265e;
	case 9826ULL: goto x86_l_2662;
	case 9828ULL: goto x86_l_2664;
	case 9832ULL: goto x86_l_2668;
	case 9836ULL: goto x86_l_266c;
	case 9840ULL: goto x86_l_2670;
	case 9844ULL: goto x86_l_2674;
	case 9848ULL: goto x86_l_2678;
	case 9854ULL: goto x86_l_267e;
	case 9864ULL: goto x86_l_2688;
	case 9868ULL: goto x86_l_268c;
	case 9874ULL: goto x86_l_2692;
	case 9877ULL: goto x86_l_2695;
	case 9882ULL: goto x86_l_269a;
	case 9886ULL: goto x86_l_269e;
	case 9889ULL: goto x86_l_26a1;
	case 9892ULL: goto x86_l_26a4;
	case 9897ULL: goto x86_l_26a9;
	case 9900ULL: goto x86_l_26ac;
	case 9902ULL: goto x86_l_26ae;
	case 9904ULL: goto x86_l_26b0;
	case 9911ULL: goto x86_l_26b7;
	case 9914ULL: goto x86_l_26ba;
	case 9919ULL: goto x86_l_26bf;
	case 9926ULL: goto x86_l_26c6;
	case 9935ULL: goto x86_l_26cf;
	case 9939ULL: goto x86_l_26d3;
	case 9944ULL: goto x86_l_26d8;
	case 9949ULL: goto x86_l_26dd;
	case 9954ULL: goto x86_l_26e2;
	case 9956ULL: goto x86_l_26e4;
	case 9963ULL: goto x86_l_26eb;
	case 9967ULL: goto x86_l_26ef;
	case 9972ULL: goto x86_l_26f4;
	case 9977ULL: goto x86_l_26f9;
	case 9980ULL: goto x86_l_26fc;
	case 9982ULL: goto x86_l_26fe;
	case 9990ULL: goto x86_l_2706;
	case 9993ULL: goto x86_l_2709;
	case 9995ULL: goto x86_l_270b;
	case 9998ULL: goto x86_l_270e;
	case 10004ULL: goto x86_l_2714;
	case 10009ULL: goto x86_l_2719;
	case 10018ULL: goto x86_l_2722;
	case 10022ULL: goto x86_l_2726;
	case 10027ULL: goto x86_l_272b;
	case 10034ULL: goto x86_l_2732;
	case 10039ULL: goto x86_l_2737;
	case 10044ULL: goto x86_l_273c;
	case 10046ULL: goto x86_l_273e;
	case 10053ULL: goto x86_l_2745;
	case 10057ULL: goto x86_l_2749;
	case 10061ULL: goto x86_l_274d;
	case 10066ULL: goto x86_l_2752;
	case 10068ULL: goto x86_l_2754;
	case 10073ULL: goto x86_l_2759;
	case 10082ULL: goto x86_l_2762;
	case 10086ULL: goto x86_l_2766;
	case 10091ULL: goto x86_l_276b;
	case 10098ULL: goto x86_l_2772;
	case 10103ULL: goto x86_l_2777;
	case 10108ULL: goto x86_l_277c;
	case 10110ULL: goto x86_l_277e;
	case 10117ULL: goto x86_l_2785;
	case 10121ULL: goto x86_l_2789;
	case 10125ULL: goto x86_l_278d;
	case 10130ULL: goto x86_l_2792;
	case 10135ULL: goto x86_l_2797;
	case 10137ULL: goto x86_l_2799;
	case 10139ULL: goto x86_l_279b;
	case 10144ULL: goto x86_l_27a0;
	case 10154ULL: goto x86_l_27aa;
	case 10159ULL: goto x86_l_27af;
	case 10166ULL: goto x86_l_27b6;
	case 10173ULL: goto x86_l_27bd;
	case 10182ULL: goto x86_l_27c6;
	case 10191ULL: goto x86_l_27cf;
	case 10199ULL: goto x86_l_27d7;
	case 10206ULL: goto x86_l_27de;
	case 10211ULL: goto x86_l_27e3;
	case 10216ULL: goto x86_l_27e8;
	case 10221ULL: goto x86_l_27ed;
	case 10223ULL: goto x86_l_27ef;
	case 10229ULL: goto x86_l_27f5;
	case 10231ULL: goto x86_l_27f7;
	case 10236ULL: goto x86_l_27fc;
	case 10241ULL: goto x86_l_2801;
	case 10245ULL: goto x86_l_2805;
	case 10253ULL: goto x86_l_280d;
	case 10258ULL: goto x86_l_2812;
	case 10260ULL: goto x86_l_2814;
	case 10265ULL: goto x86_l_2819;
	case 10273ULL: goto x86_l_2821;
	case 10277ULL: goto x86_l_2825;
	case 10282ULL: goto x86_l_282a;
	case 10289ULL: goto x86_l_2831;
	case 10294ULL: goto x86_l_2836;
	case 10299ULL: goto x86_l_283b;
	case 10301ULL: goto x86_l_283d;
	case 10304ULL: goto x86_l_2840;
	case 10311ULL: goto x86_l_2847;
	case 10315ULL: goto x86_l_284b;
	case 10319ULL: goto x86_l_284f;
	case 10324ULL: goto x86_l_2854;
	case 10329ULL: goto x86_l_2859;
	case 10331ULL: goto x86_l_285b;
	case 10336ULL: goto x86_l_2860;
	case 10341ULL: goto x86_l_2865;
	case 10346ULL: goto x86_l_286a;
	case 10351ULL: goto x86_l_286f;
	case 10356ULL: goto x86_l_2874;
	case 10364ULL: goto x86_l_287c;
	case 10369ULL: goto x86_l_2881;
	case 10371ULL: goto x86_l_2883;
	case 10376ULL: goto x86_l_2888;
	case 10385ULL: goto x86_l_2891;
	case 10391ULL: goto x86_l_2897;
	case 10399ULL: goto x86_l_289f;
	case 10403ULL: goto x86_l_28a3;
	case 10408ULL: goto x86_l_28a8;
	case 10413ULL: goto x86_l_28ad;
	case 10418ULL: goto x86_l_28b2;
	case 10423ULL: goto x86_l_28b7;
	case 10425ULL: goto x86_l_28b9;
	case 10430ULL: goto x86_l_28be;
	case 10432ULL: goto x86_l_28c0;
	case 10438ULL: goto x86_l_28c6;
	case 10443ULL: goto x86_l_28cb;
	case 10448ULL: goto x86_l_28d0;
	case 10451ULL: goto x86_l_28d3;
	case 10454ULL: goto x86_l_28d6;
	case 10458ULL: goto x86_l_28da;
	case 10461ULL: goto x86_l_28dd;
	case 10465ULL: goto x86_l_28e1;
	case 10470ULL: goto x86_l_28e6;
	case 10475ULL: goto x86_l_28eb;
	case 10482ULL: goto x86_l_28f2;
	case 10488ULL: goto x86_l_28f8;
	case 10493ULL: goto x86_l_28fd;
	case 10496ULL: goto x86_l_2900;
	case 10501ULL: goto x86_l_2905;
	case 10507ULL: goto x86_l_290b;
	case 10510ULL: goto x86_l_290e;
	case 10515ULL: goto x86_l_2913;
	case 10520ULL: goto x86_l_2918;
	case 10525ULL: goto x86_l_291d;
	case 10527ULL: goto x86_l_291f;
	case 10532ULL: goto x86_l_2924;
	case 10534ULL: goto x86_l_2926;
	case 10540ULL: goto x86_l_292c;
	case 10545ULL: goto x86_l_2931;
	case 10550ULL: goto x86_l_2936;
	case 10556ULL: goto x86_l_293c;
	case 10558ULL: goto x86_l_293e;
	case 10563ULL: goto x86_l_2943;
	case 10565ULL: goto x86_l_2945;
	case 10570ULL: goto x86_l_294a;
	case 10572ULL: goto x86_l_294c;
	case 10577ULL: goto x86_l_2951;
	case 10586ULL: goto x86_l_295a;
	case 10592ULL: goto x86_l_2960;
	case 10600ULL: goto x86_l_2968;
	case 10604ULL: goto x86_l_296c;
	case 10609ULL: goto x86_l_2971;
	case 10614ULL: goto x86_l_2976;
	case 10619ULL: goto x86_l_297b;
	case 10624ULL: goto x86_l_2980;
	case 10626ULL: goto x86_l_2982;
	case 10631ULL: goto x86_l_2987;
	case 10633ULL: goto x86_l_2989;
	case 10635ULL: goto x86_l_298b;
	case 10640ULL: goto x86_l_2990;
	case 10645ULL: goto x86_l_2995;
	case 10648ULL: goto x86_l_2998;
	case 10651ULL: goto x86_l_299b;
	case 10655ULL: goto x86_l_299f;
	case 10658ULL: goto x86_l_29a2;
	case 10662ULL: goto x86_l_29a6;
	case 10667ULL: goto x86_l_29ab;
	case 10674ULL: goto x86_l_29b2;
	case 10676ULL: goto x86_l_29b4;
	case 10681ULL: goto x86_l_29b9;
	case 10686ULL: goto x86_l_29be;
	case 10692ULL: goto x86_l_29c4;
	case 10695ULL: goto x86_l_29c7;
	case 10700ULL: goto x86_l_29cc;
	case 10705ULL: goto x86_l_29d1;
	case 10708ULL: goto x86_l_29d4;
	case 10710ULL: goto x86_l_29d6;
	case 10715ULL: goto x86_l_29db;
	case 10717ULL: goto x86_l_29dd;
	case 10719ULL: goto x86_l_29df;
	case 10724ULL: goto x86_l_29e4;
	case 10729ULL: goto x86_l_29e9;
	default: return 0xffffffffffffffffULL;
	}
x86_l_234c:
	/* 0x234c: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2353:
	/* 0x2353: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2357:
	/* 0x2357: jmp    236e <generic_retuprobe_event+0x236e> */
	goto x86_l_236e;
x86_l_2359:
	/* 0x2359: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_235d:
	/* 0x235d: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2364:
	/* 0x2364: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2368:
	/* 0x2368: jmp    236e <generic_retuprobe_event+0x236e> */
	goto x86_l_236e;
x86_l_236a:
	/* 0x236a: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_236e:
	/* 0x236e: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2372:
	/* 0x2372: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2376:
	/* 0x2376: movzx  ecx,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_237a:
	/* 0x237a: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_237e:
	/* 0x237e: ja     2874 <generic_retuprobe_event+0x2874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2874;
	}
x86_l_2384:
	/* 0x2384: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_238e:
	/* 0x238e: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2392:
	/* 0x2392: jae    2874 <generic_retuprobe_event+0x2874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2874;
	}
x86_l_2398:
	/* 0x2398: mov    BYTE PTR [rbp+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_239b:
	/* 0x239b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23a0:
	/* 0x23a0: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_23a4:
	/* 0x23a4: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23a7:
	/* 0x23a7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_23aa:
	/* 0x23aa: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_23af:
	/* 0x23af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23b1:
	/* 0x23b1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23b4:
	/* 0x23b4: js     26ae <generic_retuprobe_event+0x26ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_26ae;
	}
x86_l_23ba:
	/* 0x23ba: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_23be:
	/* 0x23be: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_23c1:
	/* 0x23c1: jg     23e4 <generic_retuprobe_event+0x23e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_23e4;
	}
x86_l_23c3:
	/* 0x23c3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23c5:
	/* 0x23c5: je     240c <generic_retuprobe_event+0x240c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_240c;
	}
x86_l_23c7:
	/* 0x23c7: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_23ca:
	/* 0x23ca: je     240c <generic_retuprobe_event+0x240c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_240c;
	}
x86_l_23cc:
	/* 0x23cc: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_23cf:
	/* 0x23cf: jne    2500 <generic_retuprobe_event+0x2500> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2500;
	}
x86_l_23d5:
	/* 0x23d5: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_23db:
	/* 0x23db: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_23df:
	/* 0x23df: jmp    2504 <generic_retuprobe_event+0x2504> */
	goto x86_l_2504;
x86_l_23e4:
	/* 0x23e4: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_23e7:
	/* 0x23e7: je     24ef <generic_retuprobe_event+0x24ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24ef;
	}
x86_l_23ed:
	/* 0x23ed: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_23f0:
	/* 0x23f0: je     240c <generic_retuprobe_event+0x240c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_240c;
	}
x86_l_23f2:
	/* 0x23f2: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_23f7:
	/* 0x23f7: jne    2500 <generic_retuprobe_event+0x2500> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2500;
	}
x86_l_23fd:
	/* 0x23fd: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2403:
	/* 0x2403: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2407:
	/* 0x2407: jmp    2504 <generic_retuprobe_event+0x2504> */
	goto x86_l_2504;
x86_l_240c:
	/* 0x240c: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2410:
	/* 0x2410: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2417:
	/* 0x2417: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_241b:
	/* 0x241b: jmp    2504 <generic_retuprobe_event+0x2504> */
	goto x86_l_2504;
x86_l_2420:
	/* 0x2420: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2422:
	/* 0x2422: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2427:
	/* 0x2427: cmp    QWORD PTR [rsp+0x80],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813893ULL);
x86_l_2430:
	/* 0x2430: jb     2082 <generic_retuprobe_event+0x2082> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8322ULL;
	}
x86_l_2436:
	/* 0x2436: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_243e:
	/* 0x243e: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2442:
	/* 0x2442: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_2447:
	/* 0x2447: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_244c:
	/* 0x244c: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2451:
	/* 0x2451: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2456:
	/* 0x2456: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2458:
	/* 0x2458: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_245d:
	/* 0x245d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_245f:
	/* 0x245f: js     29e9 <generic_retuprobe_event+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29e9;
	}
x86_l_2465:
	/* 0x2465: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_246a:
	/* 0x246a: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_246f:
	/* 0x246f: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2472:
	/* 0x2472: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2475:
	/* 0x2475: cmovb  rbx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_2479:
	/* 0x2479: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_247c:
	/* 0x247c: cmovne rdx,rbx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RBX, X86_WIDTH_64, X86_CC_NE);
x86_l_2480:
	/* 0x2480: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2485:
	/* 0x2485: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_248a:
	/* 0x248a: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_2491:
	/* 0x2491: ja     29e9 <generic_retuprobe_event+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29e9;
	}
x86_l_2497:
	/* 0x2497: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_249a:
	/* 0x249a: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_249f:
	/* 0x249f: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_24a2:
	/* 0x24a2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_24a8:
	/* 0x24a8: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_24ab:
	/* 0x24ab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24b0:
	/* 0x24b0: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_24b5:
	/* 0x24b5: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24ba:
	/* 0x24ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24bc:
	/* 0x24bc: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_24c1:
	/* 0x24c1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24c3:
	/* 0x24c3: js     29e9 <generic_retuprobe_event+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29e9;
	}
x86_l_24c9:
	/* 0x24c9: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24ce:
	/* 0x24ce: add    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_24d3:
	/* 0x24d3: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_24d9:
	/* 0x24d9: je     2881 <generic_retuprobe_event+0x2881> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2881;
	}
x86_l_24df:
	/* 0x24df: sub    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 24ULL);
x86_l_24e4:
	/* 0x24e4: jne    2888 <generic_retuprobe_event+0x2888> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2888;
	}
x86_l_24ea:
	/* 0x24ea: jmp    2082 <generic_retuprobe_event+0x2082> */
	return 8322ULL;
x86_l_24ef:
	/* 0x24ef: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_24f3:
	/* 0x24f3: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_24fa:
	/* 0x24fa: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_24fe:
	/* 0x24fe: jmp    2504 <generic_retuprobe_event+0x2504> */
	goto x86_l_2504;
x86_l_2500:
	/* 0x2500: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2504:
	/* 0x2504: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2508:
	/* 0x2508: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_250c:
	/* 0x250c: movzx  ecx,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2510:
	/* 0x2510: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2514:
	/* 0x2514: ja     2874 <generic_retuprobe_event+0x2874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2874;
	}
x86_l_251a:
	/* 0x251a: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2524:
	/* 0x2524: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2528:
	/* 0x2528: jae    2874 <generic_retuprobe_event+0x2874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2874;
	}
x86_l_252e:
	/* 0x252e: mov    BYTE PTR [rbp+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2531:
	/* 0x2531: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2536:
	/* 0x2536: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_253a:
	/* 0x253a: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_253d:
	/* 0x253d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2540:
	/* 0x2540: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2545:
	/* 0x2545: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2547:
	/* 0x2547: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_254a:
	/* 0x254a: js     26ae <generic_retuprobe_event+0x26ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_26ae;
	}
x86_l_2550:
	/* 0x2550: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2554:
	/* 0x2554: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2557:
	/* 0x2557: jg     2573 <generic_retuprobe_event+0x2573> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2573;
	}
x86_l_2559:
	/* 0x2559: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_255b:
	/* 0x255b: je     2590 <generic_retuprobe_event+0x2590> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2590;
	}
x86_l_255d:
	/* 0x255d: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2560:
	/* 0x2560: je     2590 <generic_retuprobe_event+0x2590> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2590;
	}
x86_l_2562:
	/* 0x2562: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2565:
	/* 0x2565: jne    25b2 <generic_retuprobe_event+0x25b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25b2;
	}
x86_l_2567:
	/* 0x2567: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_256d:
	/* 0x256d: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2571:
	/* 0x2571: jmp    25b6 <generic_retuprobe_event+0x25b6> */
	goto x86_l_25b6;
x86_l_2573:
	/* 0x2573: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2576:
	/* 0x2576: je     25a1 <generic_retuprobe_event+0x25a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25a1;
	}
x86_l_2578:
	/* 0x2578: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_257b:
	/* 0x257b: je     2590 <generic_retuprobe_event+0x2590> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2590;
	}
x86_l_257d:
	/* 0x257d: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2582:
	/* 0x2582: jne    25b2 <generic_retuprobe_event+0x25b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25b2;
	}
x86_l_2584:
	/* 0x2584: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_258a:
	/* 0x258a: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_258e:
	/* 0x258e: jmp    25b6 <generic_retuprobe_event+0x25b6> */
	goto x86_l_25b6;
x86_l_2590:
	/* 0x2590: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2594:
	/* 0x2594: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_259b:
	/* 0x259b: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_259f:
	/* 0x259f: jmp    25b6 <generic_retuprobe_event+0x25b6> */
	goto x86_l_25b6;
x86_l_25a1:
	/* 0x25a1: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_25a5:
	/* 0x25a5: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_25ac:
	/* 0x25ac: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_25b0:
	/* 0x25b0: jmp    25b6 <generic_retuprobe_event+0x25b6> */
	goto x86_l_25b6;
x86_l_25b2:
	/* 0x25b2: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_25b6:
	/* 0x25b6: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_25ba:
	/* 0x25ba: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25be:
	/* 0x25be: movzx  ecx,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_25c2:
	/* 0x25c2: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_25c6:
	/* 0x25c6: ja     2874 <generic_retuprobe_event+0x2874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2874;
	}
x86_l_25cc:
	/* 0x25cc: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_25d6:
	/* 0x25d6: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_25da:
	/* 0x25da: jae    2874 <generic_retuprobe_event+0x2874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2874;
	}
x86_l_25e0:
	/* 0x25e0: mov    BYTE PTR [rbp+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_25e3:
	/* 0x25e3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25e8:
	/* 0x25e8: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_25ec:
	/* 0x25ec: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_25ef:
	/* 0x25ef: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_25f2:
	/* 0x25f2: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_25f7:
	/* 0x25f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25f9:
	/* 0x25f9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25fc:
	/* 0x25fc: js     26ae <generic_retuprobe_event+0x26ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_26ae;
	}
x86_l_2602:
	/* 0x2602: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2606:
	/* 0x2606: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2609:
	/* 0x2609: jg     2625 <generic_retuprobe_event+0x2625> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2625;
	}
x86_l_260b:
	/* 0x260b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_260d:
	/* 0x260d: je     2642 <generic_retuprobe_event+0x2642> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2642;
	}
x86_l_260f:
	/* 0x260f: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2612:
	/* 0x2612: je     2642 <generic_retuprobe_event+0x2642> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2642;
	}
x86_l_2614:
	/* 0x2614: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2617:
	/* 0x2617: jne    2664 <generic_retuprobe_event+0x2664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2664;
	}
x86_l_2619:
	/* 0x2619: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_261f:
	/* 0x261f: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2623:
	/* 0x2623: jmp    2668 <generic_retuprobe_event+0x2668> */
	goto x86_l_2668;
x86_l_2625:
	/* 0x2625: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2628:
	/* 0x2628: je     2653 <generic_retuprobe_event+0x2653> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2653;
	}
x86_l_262a:
	/* 0x262a: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_262d:
	/* 0x262d: je     2642 <generic_retuprobe_event+0x2642> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2642;
	}
x86_l_262f:
	/* 0x262f: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2634:
	/* 0x2634: jne    2664 <generic_retuprobe_event+0x2664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2664;
	}
x86_l_2636:
	/* 0x2636: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_263c:
	/* 0x263c: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2640:
	/* 0x2640: jmp    2668 <generic_retuprobe_event+0x2668> */
	goto x86_l_2668;
x86_l_2642:
	/* 0x2642: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2646:
	/* 0x2646: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_264d:
	/* 0x264d: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2651:
	/* 0x2651: jmp    2668 <generic_retuprobe_event+0x2668> */
	goto x86_l_2668;
x86_l_2653:
	/* 0x2653: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2657:
	/* 0x2657: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_265e:
	/* 0x265e: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2662:
	/* 0x2662: jmp    2668 <generic_retuprobe_event+0x2668> */
	goto x86_l_2668;
x86_l_2664:
	/* 0x2664: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2668:
	/* 0x2668: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_266c:
	/* 0x266c: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2670:
	/* 0x2670: movzx  ecx,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2674:
	/* 0x2674: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2678:
	/* 0x2678: ja     2874 <generic_retuprobe_event+0x2874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2874;
	}
x86_l_267e:
	/* 0x267e: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2688:
	/* 0x2688: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_268c:
	/* 0x268c: jae    2874 <generic_retuprobe_event+0x2874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2874;
	}
x86_l_2692:
	/* 0x2692: mov    BYTE PTR [rbp+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2695:
	/* 0x2695: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_269a:
	/* 0x269a: movzx  ecx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_269e:
	/* 0x269e: add    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26a1:
	/* 0x26a1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_26a4:
	/* 0x26a4: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_26a9:
	/* 0x26a9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_26ac:
	/* 0x26ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26ae:
	/* 0x26ae: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26b0:
	/* 0x26b0: mov    BYTE PTR [rsp+0xb8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_26b7:
	/* 0x26b7: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_26ba:
	/* 0x26ba: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26bf:
	/* 0x26bf: mov    WORD PTR [rbx+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_26c6:
	/* 0x26c6: mov    WORD PTR [rbx+0xc2],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655434ULL);
x86_l_26cf:
	/* 0x26cf: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26d3:
	/* 0x26d3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26d8:
	/* 0x26d8: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26dd:
	/* 0x26dd: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_26e2:
	/* 0x26e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26e4:
	/* 0x26e4: lea    rdi,[rbx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_26eb:
	/* 0x26eb: add    r13,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_26ef:
	/* 0x26ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26f4:
	/* 0x26f4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_26f9:
	/* 0x26f9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_26fc:
	/* 0x26fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26fe:
	/* 0x26fe: movzx  eax,BYTE PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 184ULL);
x86_l_2706:
	/* 0x2706: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2709:
	/* 0x2709: je     2754 <generic_retuprobe_event+0x2754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2754;
	}
x86_l_270b:
	/* 0x270b: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_270e:
	/* 0x270e: jne    279b <generic_retuprobe_event+0x279b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_279b;
	}
x86_l_2714:
	/* 0x2714: mov    rbx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2719:
	/* 0x2719: movzx  r12d,WORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 192ULL);
x86_l_2722:
	/* 0x2722: lea    rdx,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2726:
	/* 0x2726: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_272b:
	/* 0x272b: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2732:
	/* 0x2732: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2737:
	/* 0x2737: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_273c:
	/* 0x273c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_273e:
	/* 0x273e: lea    rdi,[r13+0xbe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 190ULL);
x86_l_2745:
	/* 0x2745: lea    rdx,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2749:
	/* 0x2749: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_274d:
	/* 0x274d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2752:
	/* 0x2752: jmp    2792 <generic_retuprobe_event+0x2792> */
	goto x86_l_2792;
x86_l_2754:
	/* 0x2754: mov    rbx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2759:
	/* 0x2759: movzx  r12d,WORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 192ULL);
x86_l_2762:
	/* 0x2762: lea    rdx,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2766:
	/* 0x2766: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_276b:
	/* 0x276b: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2772:
	/* 0x2772: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2777:
	/* 0x2777: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_277c:
	/* 0x277c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_277e:
	/* 0x277e: lea    rdi,[r13+0xbe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 190ULL);
x86_l_2785:
	/* 0x2785: lea    rdx,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2789:
	/* 0x2789: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_278d:
	/* 0x278d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2792:
	/* 0x2792: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2797:
	/* 0x2797: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2799:
	/* 0x2799: jmp    27aa <generic_retuprobe_event+0x27aa> */
	goto x86_l_27aa;
x86_l_279b:
	/* 0x279b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27a0:
	/* 0x27a0: mov    DWORD PTR [rax+0xbc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_27aa:
	/* 0x27aa: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27af:
	/* 0x27af: movzx  ecx,WORD PTR [rax+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_27b6:
	/* 0x27b6: movzx  edx,WORD PTR [rax+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_27bd:
	/* 0x27bd: movbe  WORD PTR [rax+0xbc],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_27c6:
	/* 0x27c6: movbe  WORD PTR [rax+0xbe],dx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_27cf:
	/* 0x27cf: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_27d7:
	/* 0x27d7: add    rdx,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_27de:
	/* 0x27de: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27e3:
	/* 0x27e3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27e8:
	/* 0x27e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27ed:
	/* 0x27ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27ef:
	/* 0x27ef: cmp    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_27f5:
	/* 0x27f5: je     285b <generic_retuprobe_event+0x285b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_285b;
	}
x86_l_27f7:
	/* 0x27f7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27fc:
	/* 0x27fc: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2801:
	/* 0x2801: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_2805:
	/* 0x2805: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_280d:
	/* 0x280d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2812:
	/* 0x2812: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2814:
	/* 0x2814: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2819:
	/* 0x2819: mov    r12,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2821:
	/* 0x2821: lea    rdx,[rbx+r12*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_2825:
	/* 0x2825: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_282a:
	/* 0x282a: lea    rdi,[r13+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_2831:
	/* 0x2831: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2836:
	/* 0x2836: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_283b:
	/* 0x283b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_283d:
	/* 0x283d: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2840:
	/* 0x2840: add    rdi,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_2847:
	/* 0x2847: lea    rdx,[rbx+r12*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_284b:
	/* 0x284b: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_284f:
	/* 0x284f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2854:
	/* 0x2854: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2859:
	/* 0x2859: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_285b:
	/* 0x285b: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2860:
	/* 0x2860: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2865:
	/* 0x2865: mov    ebp,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_286a:
	/* 0x286a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_286f:
	/* 0x286f: jmp    a1c <generic_retuprobe_event+0xa1c> */
	return 2588ULL;
x86_l_2874:
	/* 0x2874: mov    WORD PTR [rsp+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_287c:
	/* 0x287c: jmp    26b0 <generic_retuprobe_event+0x26b0> */
	goto x86_l_26b0;
x86_l_2881:
	/* 0x2881: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2883:
	/* 0x2883: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2888:
	/* 0x2888: cmp    QWORD PTR [rsp+0x80],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813893ULL);
x86_l_2891:
	/* 0x2891: je     2082 <generic_retuprobe_event+0x2082> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8322ULL;
	}
x86_l_2897:
	/* 0x2897: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_289f:
	/* 0x289f: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_28a3:
	/* 0x28a3: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_28a8:
	/* 0x28a8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28ad:
	/* 0x28ad: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_28b2:
	/* 0x28b2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_28b7:
	/* 0x28b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28b9:
	/* 0x28b9: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_28be:
	/* 0x28be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28c0:
	/* 0x28c0: js     29e9 <generic_retuprobe_event+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29e9;
	}
x86_l_28c6:
	/* 0x28c6: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_28cb:
	/* 0x28cb: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28d0:
	/* 0x28d0: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_28d3:
	/* 0x28d3: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_28d6:
	/* 0x28d6: cmovb  rbx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_28da:
	/* 0x28da: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28dd:
	/* 0x28dd: cmovne rdx,rbx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RBX, X86_WIDTH_64, X86_CC_NE);
x86_l_28e1:
	/* 0x28e1: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_28e6:
	/* 0x28e6: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28eb:
	/* 0x28eb: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_28f2:
	/* 0x28f2: ja     29e9 <generic_retuprobe_event+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29e9;
	}
x86_l_28f8:
	/* 0x28f8: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28fd:
	/* 0x28fd: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2900:
	/* 0x2900: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2905:
	/* 0x2905: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_290b:
	/* 0x290b: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_290e:
	/* 0x290e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2913:
	/* 0x2913: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2918:
	/* 0x2918: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_291d:
	/* 0x291d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_291f:
	/* 0x291f: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2924:
	/* 0x2924: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2926:
	/* 0x2926: js     29e9 <generic_retuprobe_event+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29e9;
	}
x86_l_292c:
	/* 0x292c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2931:
	/* 0x2931: add    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_2936:
	/* 0x2936: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_293c:
	/* 0x293c: je     294a <generic_retuprobe_event+0x294a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_294a;
	}
x86_l_293e:
	/* 0x293e: sub    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 24ULL);
x86_l_2943:
	/* 0x2943: jne    2951 <generic_retuprobe_event+0x2951> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2951;
	}
x86_l_2945:
	/* 0x2945: jmp    2082 <generic_retuprobe_event+0x2082> */
	return 8322ULL;
x86_l_294a:
	/* 0x294a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_294c:
	/* 0x294c: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2951:
	/* 0x2951: cmp    QWORD PTR [rsp+0x80],0x7 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813895ULL);
x86_l_295a:
	/* 0x295a: jb     2082 <generic_retuprobe_event+0x2082> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8322ULL;
	}
x86_l_2960:
	/* 0x2960: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2968:
	/* 0x2968: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_296c:
	/* 0x296c: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_2971:
	/* 0x2971: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2976:
	/* 0x2976: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_297b:
	/* 0x297b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2980:
	/* 0x2980: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2982:
	/* 0x2982: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2987:
	/* 0x2987: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2989:
	/* 0x2989: js     29e9 <generic_retuprobe_event+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29e9;
	}
x86_l_298b:
	/* 0x298b: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2990:
	/* 0x2990: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2995:
	/* 0x2995: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_2998:
	/* 0x2998: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_299b:
	/* 0x299b: cmovb  r13,rax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_64, X86_CC_B);
x86_l_299f:
	/* 0x299f: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_29a2:
	/* 0x29a2: cmove  r13,rax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_64, X86_CC_E);
x86_l_29a6:
	/* 0x29a6: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_29ab:
	/* 0x29ab: cmp    r13,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4094ULL);
x86_l_29b2:
	/* 0x29b2: ja     29e9 <generic_retuprobe_event+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29e9;
	}
x86_l_29b4:
	/* 0x29b4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29b9:
	/* 0x29b9: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_29be:
	/* 0x29be: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_29c4:
	/* 0x29c4: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29c7:
	/* 0x29c7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29cc:
	/* 0x29cc: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_29d1:
	/* 0x29d1: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_29d4:
	/* 0x29d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29d6:
	/* 0x29d6: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_29db:
	/* 0x29db: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29dd:
	/* 0x29dd: js     29e9 <generic_retuprobe_event+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29e9;
	}
x86_l_29df:
	/* 0x29df: add    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_29e4:
	/* 0x29e4: jmp    2c9 <generic_retuprobe_event+0x2c9> */
	return 713ULL;
x86_l_29e9:
	/* 0x29e9: mov    DWORD PTR [r15+r12*1],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
	return 10733ULL;
}

static __noinline __u64 tetragon_bpf_multi_retuprobe_v61_generic_retuprobe_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10733ULL: goto x86_l_29ed;
	case 10736ULL: goto x86_l_29f0;
	case 10739ULL: goto x86_l_29f3;
	case 10744ULL: goto x86_l_29f8;
	case 10746ULL: goto x86_l_29fa;
	case 10749ULL: goto x86_l_29fd;
	case 10754ULL: goto x86_l_2a02;
	case 10759ULL: goto x86_l_2a07;
	case 10767ULL: goto x86_l_2a0f;
	case 10775ULL: goto x86_l_2a17;
	case 10780ULL: goto x86_l_2a1c;
	case 10782ULL: goto x86_l_2a1e;
	case 10789ULL: goto x86_l_2a25;
	case 10793ULL: goto x86_l_2a29;
	case 10798ULL: goto x86_l_2a2e;
	case 10805ULL: goto x86_l_2a35;
	case 10810ULL: goto x86_l_2a3a;
	case 10812ULL: goto x86_l_2a3c;
	case 10815ULL: goto x86_l_2a3f;
	case 10817ULL: goto x86_l_2a41;
	case 10820ULL: goto x86_l_2a44;
	case 10825ULL: goto x86_l_2a49;
	case 10831ULL: goto x86_l_2a4f;
	case 10836ULL: goto x86_l_2a54;
	case 10843ULL: goto x86_l_2a5b;
	case 10848ULL: goto x86_l_2a60;
	case 10853ULL: goto x86_l_2a65;
	case 10856ULL: goto x86_l_2a68;
	case 10858ULL: goto x86_l_2a6a;
	case 10864ULL: goto x86_l_2a70;
	case 10870ULL: goto x86_l_2a76;
	case 10875ULL: goto x86_l_2a7b;
	case 10880ULL: goto x86_l_2a80;
	case 10885ULL: goto x86_l_2a85;
	case 10893ULL: goto x86_l_2a8d;
	case 10898ULL: goto x86_l_2a92;
	case 10900ULL: goto x86_l_2a94;
	case 10907ULL: goto x86_l_2a9b;
	case 10911ULL: goto x86_l_2a9f;
	case 10916ULL: goto x86_l_2aa4;
	case 10923ULL: goto x86_l_2aab;
	case 10928ULL: goto x86_l_2ab0;
	case 10930ULL: goto x86_l_2ab2;
	case 10933ULL: goto x86_l_2ab5;
	case 10935ULL: goto x86_l_2ab7;
	case 10938ULL: goto x86_l_2aba;
	case 10943ULL: goto x86_l_2abf;
	case 10949ULL: goto x86_l_2ac5;
	case 10954ULL: goto x86_l_2aca;
	case 10959ULL: goto x86_l_2acf;
	case 10964ULL: goto x86_l_2ad4;
	case 10969ULL: goto x86_l_2ad9;
	case 10974ULL: goto x86_l_2ade;
	case 10976ULL: goto x86_l_2ae0;
	case 10982ULL: goto x86_l_2ae6;
	case 10988ULL: goto x86_l_2aec;
	case 10993ULL: goto x86_l_2af1;
	case 10998ULL: goto x86_l_2af6;
	case 11003ULL: goto x86_l_2afb;
	case 11011ULL: goto x86_l_2b03;
	case 11016ULL: goto x86_l_2b08;
	case 11018ULL: goto x86_l_2b0a;
	case 11025ULL: goto x86_l_2b11;
	case 11029ULL: goto x86_l_2b15;
	case 11034ULL: goto x86_l_2b1a;
	case 11041ULL: goto x86_l_2b21;
	case 11046ULL: goto x86_l_2b26;
	case 11048ULL: goto x86_l_2b28;
	case 11051ULL: goto x86_l_2b2b;
	case 11053ULL: goto x86_l_2b2d;
	case 11056ULL: goto x86_l_2b30;
	case 11061ULL: goto x86_l_2b35;
	case 11067ULL: goto x86_l_2b3b;
	case 11072ULL: goto x86_l_2b40;
	case 11077ULL: goto x86_l_2b45;
	case 11082ULL: goto x86_l_2b4a;
	case 11087ULL: goto x86_l_2b4f;
	case 11092ULL: goto x86_l_2b54;
	case 11094ULL: goto x86_l_2b56;
	case 11100ULL: goto x86_l_2b5c;
	case 11102ULL: goto x86_l_2b5e;
	case 11107ULL: goto x86_l_2b63;
	case 11112ULL: goto x86_l_2b68;
	case 11117ULL: goto x86_l_2b6d;
	case 11125ULL: goto x86_l_2b75;
	case 11130ULL: goto x86_l_2b7a;
	case 11132ULL: goto x86_l_2b7c;
	case 11139ULL: goto x86_l_2b83;
	case 11143ULL: goto x86_l_2b87;
	case 11148ULL: goto x86_l_2b8c;
	case 11155ULL: goto x86_l_2b93;
	case 11160ULL: goto x86_l_2b98;
	case 11162ULL: goto x86_l_2b9a;
	case 11165ULL: goto x86_l_2b9d;
	case 11167ULL: goto x86_l_2b9f;
	case 11170ULL: goto x86_l_2ba2;
	case 11175ULL: goto x86_l_2ba7;
	case 11177ULL: goto x86_l_2ba9;
	case 11182ULL: goto x86_l_2bae;
	case 11187ULL: goto x86_l_2bb3;
	case 11192ULL: goto x86_l_2bb8;
	case 11197ULL: goto x86_l_2bbd;
	case 11202ULL: goto x86_l_2bc2;
	case 11204ULL: goto x86_l_2bc4;
	case 11207ULL: goto x86_l_2bc7;
	case 11214ULL: goto x86_l_2bce;
	case 11218ULL: goto x86_l_2bd2;
	case 11223ULL: goto x86_l_2bd7;
	case 11225ULL: goto x86_l_2bd9;
	case 11229ULL: goto x86_l_2bdd;
	case 11232ULL: goto x86_l_2be0;
	case 11234ULL: goto x86_l_2be2;
	case 11237ULL: goto x86_l_2be5;
	case 11241ULL: goto x86_l_2be9;
	case 11245ULL: goto x86_l_2bed;
	case 11249ULL: goto x86_l_2bf1;
	case 11257ULL: goto x86_l_2bf9;
	case 11265ULL: goto x86_l_2c01;
	case 11267ULL: goto x86_l_2c03;
	case 11271ULL: goto x86_l_2c07;
	case 11275ULL: goto x86_l_2c0b;
	case 11280ULL: goto x86_l_2c10;
	case 11287ULL: goto x86_l_2c17;
	case 11295ULL: goto x86_l_2c1f;
	case 11300ULL: goto x86_l_2c24;
	case 11302ULL: goto x86_l_2c26;
	case 11307ULL: goto x86_l_2c2b;
	case 11309ULL: goto x86_l_2c2d;
	case 11316ULL: goto x86_l_2c34;
	case 11318ULL: goto x86_l_2c36;
	case 11319ULL: goto x86_l_2c37;
	case 11324ULL: goto x86_l_2c3c;
	case 11326ULL: goto x86_l_2c3e;
	case 11328ULL: goto x86_l_2c40;
	case 11330ULL: goto x86_l_2c42;
	case 11331ULL: goto x86_l_2c43;
	case 11335ULL: goto x86_l_2c47;
	case 11338ULL: goto x86_l_2c4a;
	case 11342ULL: goto x86_l_2c4e;
	case 11346ULL: goto x86_l_2c52;
	case 11350ULL: goto x86_l_2c56;
	case 11353ULL: goto x86_l_2c59;
	case 11355ULL: goto x86_l_2c5b;
	case 11359ULL: goto x86_l_2c5f;
	case 11365ULL: goto x86_l_2c65;
	case 11370ULL: goto x86_l_2c6a;
	case 11375ULL: goto x86_l_2c6f;
	case 11380ULL: goto x86_l_2c74;
	case 11382ULL: goto x86_l_2c76;
	case 11387ULL: goto x86_l_2c7b;
	case 11393ULL: goto x86_l_2c81;
	case 11397ULL: goto x86_l_2c85;
	case 11402ULL: goto x86_l_2c8a;
	case 11407ULL: goto x86_l_2c8f;
	case 11412ULL: goto x86_l_2c94;
	case 11415ULL: goto x86_l_2c97;
	case 11417ULL: goto x86_l_2c99;
	case 11422ULL: goto x86_l_2c9e;
	case 11428ULL: goto x86_l_2ca4;
	case 11433ULL: goto x86_l_2ca9;
	case 11438ULL: goto x86_l_2cae;
	case 11443ULL: goto x86_l_2cb3;
	case 11446ULL: goto x86_l_2cb6;
	case 11448ULL: goto x86_l_2cb8;
	case 11452ULL: goto x86_l_2cbc;
	case 11457ULL: goto x86_l_2cc1;
	case 11462ULL: goto x86_l_2cc6;
	case 11467ULL: goto x86_l_2ccb;
	case 11470ULL: goto x86_l_2cce;
	case 11472ULL: goto x86_l_2cd0;
	case 11476ULL: goto x86_l_2cd4;
	case 11480ULL: goto x86_l_2cd8;
	case 11484ULL: goto x86_l_2cdc;
	case 11487ULL: goto x86_l_2cdf;
	case 11490ULL: goto x86_l_2ce2;
	case 11492ULL: goto x86_l_2ce4;
	case 11494ULL: goto x86_l_2ce6;
	case 11496ULL: goto x86_l_2ce8;
	case 11499ULL: goto x86_l_2ceb;
	case 11504ULL: goto x86_l_2cf0;
	case 11507ULL: goto x86_l_2cf3;
	case 11509ULL: goto x86_l_2cf5;
	case 11513ULL: goto x86_l_2cf9;
	case 11516ULL: goto x86_l_2cfc;
	case 11520ULL: goto x86_l_2d00;
	case 11523ULL: goto x86_l_2d03;
	case 11525ULL: goto x86_l_2d05;
	case 11528ULL: goto x86_l_2d08;
	case 11531ULL: goto x86_l_2d0b;
	case 11536ULL: goto x86_l_2d10;
	case 11539ULL: goto x86_l_2d13;
	case 11545ULL: goto x86_l_2d19;
	case 11552ULL: goto x86_l_2d20;
	case 11558ULL: goto x86_l_2d26;
	case 11560ULL: goto x86_l_2d28;
	case 11566ULL: goto x86_l_2d2e;
	case 11570ULL: goto x86_l_2d32;
	case 11575ULL: goto x86_l_2d37;
	case 11579ULL: goto x86_l_2d3b;
	case 11583ULL: goto x86_l_2d3f;
	case 11586ULL: goto x86_l_2d42;
	case 11591ULL: goto x86_l_2d47;
	case 11593ULL: goto x86_l_2d49;
	case 11597ULL: goto x86_l_2d4d;
	case 11602ULL: goto x86_l_2d52;
	case 11606ULL: goto x86_l_2d56;
	case 11608ULL: goto x86_l_2d58;
	case 11610ULL: goto x86_l_2d5a;
	case 11614ULL: goto x86_l_2d5e;
	case 11619ULL: goto x86_l_2d63;
	case 11624ULL: goto x86_l_2d68;
	case 11629ULL: goto x86_l_2d6d;
	case 11631ULL: goto x86_l_2d6f;
	case 11635ULL: goto x86_l_2d73;
	case 11640ULL: goto x86_l_2d78;
	case 11642ULL: goto x86_l_2d7a;
	case 11646ULL: goto x86_l_2d7e;
	case 11650ULL: goto x86_l_2d82;
	case 11655ULL: goto x86_l_2d87;
	case 11660ULL: goto x86_l_2d8c;
	case 11663ULL: goto x86_l_2d8f;
	case 11665ULL: goto x86_l_2d91;
	case 11670ULL: goto x86_l_2d96;
	case 11674ULL: goto x86_l_2d9a;
	case 11678ULL: goto x86_l_2d9e;
	case 11682ULL: goto x86_l_2da2;
	case 11684ULL: goto x86_l_2da4;
	case 11686ULL: goto x86_l_2da6;
	case 11690ULL: goto x86_l_2daa;
	case 11695ULL: goto x86_l_2daf;
	case 11699ULL: goto x86_l_2db3;
	case 11700ULL: goto x86_l_2db4;
	case 11702ULL: goto x86_l_2db6;
	case 11704ULL: goto x86_l_2db8;
	case 11706ULL: goto x86_l_2dba;
	case 11707ULL: goto x86_l_2dbb;
	case 11711ULL: goto x86_l_2dbf;
	case 11714ULL: goto x86_l_2dc2;
	case 11719ULL: goto x86_l_2dc7;
	case 11722ULL: goto x86_l_2dca;
	case 11724ULL: goto x86_l_2dcc;
	case 11729ULL: goto x86_l_2dd1;
	case 11733ULL: goto x86_l_2dd5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_29ed:
	/* 0x29ed: add    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29f0:
	/* 0x29f0: mov    rbx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RBP, X86_WIDTH_64);
x86_l_29f3:
	/* 0x29f3: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_29f8:
	/* 0x29f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29fa:
	/* 0x29fa: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_29fd:
	/* 0x29fd: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2a02:
	/* 0x2a02: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a07:
	/* 0x2a07: lea    rdx,[r12+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_2a0f:
	/* 0x2a0f: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2a17:
	/* 0x2a17: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a1c:
	/* 0x2a1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a1e:
	/* 0x2a1e: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2a25:
	/* 0x2a25: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a29:
	/* 0x2a29: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a2e:
	/* 0x2a2e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2a35:
	/* 0x2a35: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a3a:
	/* 0x2a3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a3c:
	/* 0x2a3c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a3f:
	/* 0x2a3f: je     2a4f <generic_retuprobe_event+0x2a4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a4f;
	}
x86_l_2a41:
	/* 0x2a41: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2a44:
	/* 0x2a44: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2a49:
	/* 0x2a49: jne    2bc7 <generic_retuprobe_event+0x2bc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2bc7;
	}
x86_l_2a4f:
	/* 0x2a4f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a54:
	/* 0x2a54: add    r12,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_2a5b:
	/* 0x2a5b: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2a60:
	/* 0x2a60: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a65:
	/* 0x2a65: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2a68:
	/* 0x2a68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a6a:
	/* 0x2a6a: cmp    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2a70:
	/* 0x2a70: je     2bc4 <generic_retuprobe_event+0x2bc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bc4;
	}
x86_l_2a76:
	/* 0x2a76: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a7b:
	/* 0x2a7b: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2a80:
	/* 0x2a80: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2a85:
	/* 0x2a85: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2a8d:
	/* 0x2a8d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a92:
	/* 0x2a92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a94:
	/* 0x2a94: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2a9b:
	/* 0x2a9b: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a9f:
	/* 0x2a9f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2aa4:
	/* 0x2aa4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2aab:
	/* 0x2aab: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ab0:
	/* 0x2ab0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ab2:
	/* 0x2ab2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ab5:
	/* 0x2ab5: je     2ac5 <generic_retuprobe_event+0x2ac5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ac5;
	}
x86_l_2ab7:
	/* 0x2ab7: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2aba:
	/* 0x2aba: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2abf:
	/* 0x2abf: jne    2bc7 <generic_retuprobe_event+0x2bc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2bc7;
	}
x86_l_2ac5:
	/* 0x2ac5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2aca:
	/* 0x2aca: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2acf:
	/* 0x2acf: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2ad4:
	/* 0x2ad4: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ad9:
	/* 0x2ad9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ade:
	/* 0x2ade: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae0:
	/* 0x2ae0: cmp    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2ae6:
	/* 0x2ae6: je     2bc4 <generic_retuprobe_event+0x2bc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bc4;
	}
x86_l_2aec:
	/* 0x2aec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2af1:
	/* 0x2af1: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2af6:
	/* 0x2af6: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2afb:
	/* 0x2afb: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2b03:
	/* 0x2b03: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b08:
	/* 0x2b08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b0a:
	/* 0x2b0a: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2b11:
	/* 0x2b11: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b15:
	/* 0x2b15: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b1a:
	/* 0x2b1a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2b21:
	/* 0x2b21: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b26:
	/* 0x2b26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b28:
	/* 0x2b28: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b2b:
	/* 0x2b2b: je     2b3b <generic_retuprobe_event+0x2b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b3b;
	}
x86_l_2b2d:
	/* 0x2b2d: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2b30:
	/* 0x2b30: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2b35:
	/* 0x2b35: jne    2bc7 <generic_retuprobe_event+0x2bc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2bc7;
	}
x86_l_2b3b:
	/* 0x2b3b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b40:
	/* 0x2b40: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2b45:
	/* 0x2b45: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2b4a:
	/* 0x2b4a: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b4f:
	/* 0x2b4f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b54:
	/* 0x2b54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b56:
	/* 0x2b56: cmp    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2b5c:
	/* 0x2b5c: je     2bc4 <generic_retuprobe_event+0x2bc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bc4;
	}
x86_l_2b5e:
	/* 0x2b5e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b63:
	/* 0x2b63: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2b68:
	/* 0x2b68: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2b6d:
	/* 0x2b6d: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2b75:
	/* 0x2b75: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b7a:
	/* 0x2b7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b7c:
	/* 0x2b7c: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2b83:
	/* 0x2b83: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b87:
	/* 0x2b87: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b8c:
	/* 0x2b8c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2b93:
	/* 0x2b93: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b98:
	/* 0x2b98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b9a:
	/* 0x2b9a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b9d:
	/* 0x2b9d: je     2ba9 <generic_retuprobe_event+0x2ba9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ba9;
	}
x86_l_2b9f:
	/* 0x2b9f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2ba2:
	/* 0x2ba2: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2ba7:
	/* 0x2ba7: jne    2bc7 <generic_retuprobe_event+0x2bc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2bc7;
	}
x86_l_2ba9:
	/* 0x2ba9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bae:
	/* 0x2bae: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2bb3:
	/* 0x2bb3: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2bb8:
	/* 0x2bb8: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2bbd:
	/* 0x2bbd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bc2:
	/* 0x2bc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bc4:
	/* 0x2bc4: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bc7:
	/* 0x2bc7: mov    DWORD PTR [r14],0x10f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 271ULL);
x86_l_2bce:
	/* 0x2bce: mov    DWORD PTR [r14+0x4],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2bd2:
	/* 0x2bd2: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_2bd7:
	/* 0x2bd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bd9:
	/* 0x2bd9: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bdd:
	/* 0x2bdd: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_2be0:
	/* 0x2be0: je     2bf1 <generic_retuprobe_event+0x2bf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bf1;
	}
x86_l_2be2:
	/* 0x2be2: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2be5:
	/* 0x2be5: mov    DWORD PTR [r14+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2be9:
	/* 0x2be9: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bed:
	/* 0x2bed: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2bf1:
	/* 0x2bf1: mov    DWORD PTR [r14+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2bf9:
	/* 0x2bf9: mov    rax,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2c01:
	/* 0x2c01: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c03:
	/* 0x2c03: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2c07:
	/* 0x2c07: mov    DWORD PTR [r14+0x4],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c0b:
	/* 0x2c0b: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2c10:
	/* 0x2c10: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retuprobe_calls)));
x86_l_2c17:
	/* 0x2c17: mov    rdi,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2c1f:
	/* 0x2c1f: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2c24:
	/* 0x2c24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c26:
	/* 0x2c26: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2c2b:
	/* 0x2c2b: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_2c2d:
	/* 0x2c2d: add    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_2c34:
	/* 0x2c34: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2c36:
	/* 0x2c36: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2c37:
	/* 0x2c37: jmp    2dd7 <cwd_read_v61+0x19b> ; native-link entry RET */
	return 0xffffffffffffffffULL;
x86_l_2c3c:
	/* 0x2c3c: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_2c3e:
	/* 0x2c3e: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2c40:
	/* 0x2c40: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2c42:
	/* 0x2c42: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2c43:
	/* 0x2c43: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_2c47:
	/* 0x2c47: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_2c4a:
	/* 0x2c4a: mov    r15,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c4e:
	/* 0x2c4e: mov    rdx,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c52:
	/* 0x2c52: mov    r14,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c56:
	/* 0x2c56: cmp    r15,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2c59:
	/* 0x2c59: jne    2c65 <cwd_read_v61+0x29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c65;
	}
x86_l_2c5b:
	/* 0x2c5b: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2c5f:
	/* 0x2c5f: je     2da6 <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2da6;
	}
x86_l_2c65:
	/* 0x2c65: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c6a:
	/* 0x2c6a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c6f:
	/* 0x2c6f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c74:
	/* 0x2c74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c76:
	/* 0x2c76: cmp    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2c7b:
	/* 0x2c7b: je     2d5a <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d5a;
	}
x86_l_2c81:
	/* 0x2c81: lea    r12,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c85:
	/* 0x2c85: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c8a:
	/* 0x2c8a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c8f:
	/* 0x2c8f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c94:
	/* 0x2c94: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2c97:
	/* 0x2c97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c99:
	/* 0x2c99: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c9e:
	/* 0x2c9e: je     2d5a <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d5a;
	}
x86_l_2ca4:
	/* 0x2ca4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ca9:
	/* 0x2ca9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2cae:
	/* 0x2cae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cb3:
	/* 0x2cb3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2cb6:
	/* 0x2cb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cb8:
	/* 0x2cb8: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2cbc:
	/* 0x2cbc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cc1:
	/* 0x2cc1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cc6:
	/* 0x2cc6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2ccb:
	/* 0x2ccb: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2cce:
	/* 0x2cce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cd0:
	/* 0x2cd0: mov    r14,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cd4:
	/* 0x2cd4: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2cd8:
	/* 0x2cd8: mov    esi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2cdc:
	/* 0x2cdc: sub    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2cdf:
	/* 0x2cdf: mov    edi,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ce2:
	/* 0x2ce2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ce4:
	/* 0x2ce4: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2ce6:
	/* 0x2ce6: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2ce8:
	/* 0x2ce8: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2ceb:
	/* 0x2ceb: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2cf0:
	/* 0x2cf0: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cf3:
	/* 0x2cf3: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2cf5:
	/* 0x2cf5: seta   r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_A);
x86_l_2cf9:
	/* 0x2cf9: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_2cfc:
	/* 0x2cfc: cmovb  r8d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_2d00:
	/* 0x2d00: add    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2d03:
	/* 0x2d03: mov    eax,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDI, X86_WIDTH_32);
x86_l_2d05:
	/* 0x2d05: sub    eax,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R9, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d08:
	/* 0x2d08: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d0b:
	/* 0x2d0b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d10:
	/* 0x2d10: sub    rcx,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R9, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2d13:
	/* 0x2d13: jb     2daf <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2daf;
	}
x86_l_2d19:
	/* 0x2d19: cmp    rcx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4095ULL);
x86_l_2d20:
	/* 0x2d20: ja     2daf <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2daf;
	}
x86_l_2d26:
	/* 0x2d26: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2d28:
	/* 0x2d28: jbe    2dbb <cwd_read_v61+0x17f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2dbb;
	}
x86_l_2d2e:
	/* 0x2d2e: lea    r15,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2d32:
	/* 0x2d32: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2d37:
	/* 0x2d37: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2d3b:
	/* 0x2d3b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2d3f:
	/* 0x2d3f: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2d42:
	/* 0x2d42: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d47:
	/* 0x2d47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d49:
	/* 0x2d49: mov    QWORD PTR [rbx+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d4d:
	/* 0x2d4d: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d52:
	/* 0x2d52: mov    QWORD PTR [rbx+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d56:
	/* 0x2d56: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d58:
	/* 0x2d58: jmp    2daf <cwd_read_v61+0x173> */
	goto x86_l_2daf;
x86_l_2d5a:
	/* 0x2d5a: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d5e:
	/* 0x2d5e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d63:
	/* 0x2d63: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d68:
	/* 0x2d68: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d6d:
	/* 0x2d6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d6f:
	/* 0x2d6f: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d73:
	/* 0x2d73: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2d78:
	/* 0x2d78: je     2da6 <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2da6;
	}
x86_l_2d7a:
	/* 0x2d7a: lea    rdi,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d7e:
	/* 0x2d7e: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2d82:
	/* 0x2d82: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d87:
	/* 0x2d87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d8c:
	/* 0x2d8c: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2d8f:
	/* 0x2d8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d91:
	/* 0x2d91: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d96:
	/* 0x2d96: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d9a:
	/* 0x2d9a: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2d9e:
	/* 0x2d9e: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2da2:
	/* 0x2da2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2da4:
	/* 0x2da4: jmp    2daf <cwd_read_v61+0x173> */
	goto x86_l_2daf;
x86_l_2da6:
	/* 0x2da6: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_2daa:
	/* 0x2daa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2daf:
	/* 0x2daf: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_2db3:
	/* 0x2db3: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2db4:
	/* 0x2db4: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2db6:
	/* 0x2db6: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2db8:
	/* 0x2db8: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2dba:
	/* 0x2dba: ret */
	return 0xffffffffffffffffULL;
x86_l_2dbb:
	/* 0x2dbb: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2dbf:
	/* 0x2dbf: add    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2dc2:
	/* 0x2dc2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2dc7:
	/* 0x2dc7: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2dca:
	/* 0x2dca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dcc:
	/* 0x2dcc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2dd1:
	/* 0x2dd1: mov    QWORD PTR [rbx+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2dd5:
	/* 0x2dd5: jmp    2daf <cwd_read_v61+0x173> */
	goto x86_l_2daf;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_multi_retuprobe_v61_generic_retuprobe_event_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 10188U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1827ULL)
			__x86_pc = tetragon_bpf_multi_retuprobe_v61_generic_retuprobe_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1832ULL && __x86_pc <= 3677ULL)
			__x86_pc = tetragon_bpf_multi_retuprobe_v61_generic_retuprobe_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3679ULL && __x86_pc <= 5576ULL)
			__x86_pc = tetragon_bpf_multi_retuprobe_v61_generic_retuprobe_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5578ULL && __x86_pc <= 7421ULL)
			__x86_pc = tetragon_bpf_multi_retuprobe_v61_generic_retuprobe_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7424ULL && __x86_pc <= 9032ULL)
			__x86_pc = tetragon_bpf_multi_retuprobe_v61_generic_retuprobe_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9036ULL && __x86_pc <= 10729ULL)
			__x86_pc = tetragon_bpf_multi_retuprobe_v61_generic_retuprobe_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10733ULL && __x86_pc <= 11733ULL)
			__x86_pc = tetragon_bpf_multi_retuprobe_v61_generic_retuprobe_event_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

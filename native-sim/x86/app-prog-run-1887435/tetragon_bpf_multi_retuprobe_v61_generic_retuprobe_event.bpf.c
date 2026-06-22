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
	/* 0x37: je     2c09 <generic_retuprobe_event+0x2c09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11273ULL;
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
	/* 0x6c: je     2c09 <generic_retuprobe_event+0x2c09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11273ULL;
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
	/* 0xc3: je     2c09 <generic_retuprobe_event+0x2c09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11273ULL;
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
	/* 0x1d2: js     29c7 <generic_retuprobe_event+0x29c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10695ULL;
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
	/* 0x1fa: ja     29c7 <generic_retuprobe_event+0x29c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10695ULL;
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
	/* 0x235: js     29c7 <generic_retuprobe_event+0x29c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10695ULL;
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
	/* 0x2d9: jmp    29cb <generic_retuprobe_event+0x29cb> */
	return 10699ULL;
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
	/* 0x78c: je     1a08 <generic_retuprobe_event+0x1a08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6664ULL;
	}
x86_l_792:
	/* 0x792: cmp    r12d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 22ULL);
x86_l_796:
	/* 0x796: je     1984 <generic_retuprobe_event+0x1984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6532ULL;
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
	/* 0x8a8: js     29c7 <generic_retuprobe_event+0x29c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10695ULL;
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
	/* 0x8d3: ja     29c7 <generic_retuprobe_event+0x29c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10695ULL;
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
	/* 0x90e: js     29c7 <generic_retuprobe_event+0x29c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10695ULL;
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
	/* 0xa71: jne    29d1 <generic_retuprobe_event+0x29d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10705ULL;
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
	/* 0xae2: jmp    29d1 <generic_retuprobe_event+0x29d1> */
	return 10705ULL;
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
	/* 0xc05: je     1d4b <generic_retuprobe_event+0x1d4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7499ULL;
	}
x86_l_c0b:
	/* 0xc0b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c0e:
	/* 0xc0e: jne    1d6e <generic_retuprobe_event+0x1d6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7534ULL;
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
	/* 0xc34: jmp    1d6c <generic_retuprobe_event+0x1d6c> */
	return 7532ULL;
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
	/* 0xe07: js     1f45 <generic_retuprobe_event+0x1f45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8005ULL;
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
	/* 0xe29: js     1f45 <generic_retuprobe_event+0x1f45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8005ULL;
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
	/* 0xe4a: je     1f1e <generic_retuprobe_event+0x1f1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7966ULL;
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
	/* 0xe61: js     1f45 <generic_retuprobe_event+0x1f45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8005ULL;
	}
x86_l_e67:
	/* 0xe67: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_e69:
	/* 0xe69: jmp    1f3a <generic_retuprobe_event+0x1f3a> */
	return 7994ULL;
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
	/* 0xf0d: je     1ae3 <generic_retuprobe_event+0x1ae3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6883ULL;
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
	/* 0xf42: je     1fc6 <generic_retuprobe_event+0x1fc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8134ULL;
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
	/* 0x1022: je     1f57 <generic_retuprobe_event+0x1f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8023ULL;
	}
x86_l_1028:
	/* 0x1028: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_102b:
	/* 0x102b: jne    1f7a <generic_retuprobe_event+0x1f7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8058ULL;
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
	/* 0x1051: jmp    1f78 <generic_retuprobe_event+0x1f78> */
	return 8056ULL;
x86_l_1056:
	/* 0x1056: cmp    r12d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 26ULL);
x86_l_105a:
	/* 0x105a: je     1b71 <generic_retuprobe_event+0x1b71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7025ULL;
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
	/* 0x10d8: js     1f12 <generic_retuprobe_event+0x1f12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7954ULL;
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
	/* 0x113b: je     1a9c <generic_retuprobe_event+0x1a9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6812ULL;
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
	/* 0x1293: je     1bf9 <generic_retuprobe_event+0x1bf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7161ULL;
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
	/* 0x1330: je     1c0a <generic_retuprobe_event+0x1c0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7178ULL;
	}
x86_l_1336:
	/* 0x1336: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1339:
	/* 0x1339: jne    1dfe <generic_retuprobe_event+0x1dfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7678ULL;
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
	/* 0x13bc: jmp    1c6d <generic_retuprobe_event+0x1c6d> */
	return 7277ULL;
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
	/* 0x149d: je     1c9f <generic_retuprobe_event+0x1c9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7327ULL;
	}
x86_l_14a3:
	/* 0x14a3: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14a6:
	/* 0x14a6: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_14ab:
	/* 0x14ab: jne    2843 <generic_retuprobe_event+0x2843> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10307ULL;
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
	/* 0x155f: jmp    26da <generic_retuprobe_event+0x26da> */
	return 9946ULL;
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
	case 6044ULL: goto x86_l_179c;
	case 6051ULL: goto x86_l_17a3;
	case 6055ULL: goto x86_l_17a7;
	case 6060ULL: goto x86_l_17ac;
	case 6065ULL: goto x86_l_17b1;
	case 6070ULL: goto x86_l_17b6;
	case 6072ULL: goto x86_l_17b8;
	case 6077ULL: goto x86_l_17bd;
	case 6084ULL: goto x86_l_17c4;
	case 6088ULL: goto x86_l_17c8;
	case 6093ULL: goto x86_l_17cd;
	case 6098ULL: goto x86_l_17d2;
	case 6100ULL: goto x86_l_17d4;
	case 6105ULL: goto x86_l_17d9;
	case 6112ULL: goto x86_l_17e0;
	case 6116ULL: goto x86_l_17e4;
	case 6121ULL: goto x86_l_17e9;
	case 6126ULL: goto x86_l_17ee;
	case 6128ULL: goto x86_l_17f0;
	case 6133ULL: goto x86_l_17f5;
	case 6140ULL: goto x86_l_17fc;
	case 6144ULL: goto x86_l_1800;
	case 6149ULL: goto x86_l_1805;
	case 6154ULL: goto x86_l_180a;
	case 6156ULL: goto x86_l_180c;
	case 6161ULL: goto x86_l_1811;
	case 6168ULL: goto x86_l_1818;
	case 6172ULL: goto x86_l_181c;
	case 6177ULL: goto x86_l_1821;
	case 6182ULL: goto x86_l_1826;
	case 6184ULL: goto x86_l_1828;
	case 6189ULL: goto x86_l_182d;
	case 6196ULL: goto x86_l_1834;
	case 6200ULL: goto x86_l_1838;
	case 6205ULL: goto x86_l_183d;
	case 6210ULL: goto x86_l_1842;
	case 6212ULL: goto x86_l_1844;
	case 6217ULL: goto x86_l_1849;
	case 6224ULL: goto x86_l_1850;
	case 6228ULL: goto x86_l_1854;
	case 6233ULL: goto x86_l_1859;
	case 6238ULL: goto x86_l_185e;
	case 6240ULL: goto x86_l_1860;
	case 6245ULL: goto x86_l_1865;
	case 6252ULL: goto x86_l_186c;
	case 6256ULL: goto x86_l_1870;
	case 6261ULL: goto x86_l_1875;
	case 6266ULL: goto x86_l_187a;
	case 6268ULL: goto x86_l_187c;
	case 6273ULL: goto x86_l_1881;
	case 6283ULL: goto x86_l_188b;
	case 6288ULL: goto x86_l_1890;
	case 6295ULL: goto x86_l_1897;
	case 6299ULL: goto x86_l_189b;
	case 6304ULL: goto x86_l_18a0;
	case 6309ULL: goto x86_l_18a5;
	case 6311ULL: goto x86_l_18a7;
	case 6315ULL: goto x86_l_18ab;
	case 6320ULL: goto x86_l_18b0;
	case 6327ULL: goto x86_l_18b7;
	case 6331ULL: goto x86_l_18bb;
	case 6336ULL: goto x86_l_18c0;
	case 6343ULL: goto x86_l_18c7;
	case 6347ULL: goto x86_l_18cb;
	case 6352ULL: goto x86_l_18d0;
	case 6359ULL: goto x86_l_18d7;
	case 6366ULL: goto x86_l_18de;
	case 6371ULL: goto x86_l_18e3;
	case 6376ULL: goto x86_l_18e8;
	case 6381ULL: goto x86_l_18ed;
	case 6383ULL: goto x86_l_18ef;
	case 6388ULL: goto x86_l_18f4;
	case 6396ULL: goto x86_l_18fc;
	case 6401ULL: goto x86_l_1901;
	case 6404ULL: goto x86_l_1904;
	case 6407ULL: goto x86_l_1907;
	case 6412ULL: goto x86_l_190c;
	case 6417ULL: goto x86_l_1911;
	case 6419ULL: goto x86_l_1913;
	case 6424ULL: goto x86_l_1918;
	case 6431ULL: goto x86_l_191f;
	case 6439ULL: goto x86_l_1927;
	case 6444ULL: goto x86_l_192c;
	case 6449ULL: goto x86_l_1931;
	case 6451ULL: goto x86_l_1933;
	case 6456ULL: goto x86_l_1938;
	case 6463ULL: goto x86_l_193f;
	case 6471ULL: goto x86_l_1947;
	case 6476ULL: goto x86_l_194c;
	case 6481ULL: goto x86_l_1951;
	case 6483ULL: goto x86_l_1953;
	case 6488ULL: goto x86_l_1958;
	case 6495ULL: goto x86_l_195f;
	case 6502ULL: goto x86_l_1966;
	case 6507ULL: goto x86_l_196b;
	case 6512ULL: goto x86_l_1970;
	case 6515ULL: goto x86_l_1973;
	case 6517ULL: goto x86_l_1975;
	case 6522ULL: goto x86_l_197a;
	case 6527ULL: goto x86_l_197f;
	case 6532ULL: goto x86_l_1984;
	case 6539ULL: goto x86_l_198b;
	case 6544ULL: goto x86_l_1990;
	case 6549ULL: goto x86_l_1995;
	case 6554ULL: goto x86_l_199a;
	case 6556ULL: goto x86_l_199c;
	case 6561ULL: goto x86_l_19a1;
	case 6568ULL: goto x86_l_19a8;
	case 6575ULL: goto x86_l_19af;
	case 6580ULL: goto x86_l_19b4;
	case 6585ULL: goto x86_l_19b9;
	case 6587ULL: goto x86_l_19bb;
	case 6592ULL: goto x86_l_19c0;
	case 6599ULL: goto x86_l_19c7;
	case 6606ULL: goto x86_l_19ce;
	case 6611ULL: goto x86_l_19d3;
	case 6616ULL: goto x86_l_19d8;
	case 6618ULL: goto x86_l_19da;
	case 6623ULL: goto x86_l_19df;
	case 6630ULL: goto x86_l_19e6;
	case 6637ULL: goto x86_l_19ed;
	case 6642ULL: goto x86_l_19f2;
	case 6647ULL: goto x86_l_19f7;
	case 6649ULL: goto x86_l_19f9;
	case 6654ULL: goto x86_l_19fe;
	case 6659ULL: goto x86_l_1a03;
	case 6664ULL: goto x86_l_1a08;
	case 6668ULL: goto x86_l_1a0c;
	case 6673ULL: goto x86_l_1a11;
	case 6678ULL: goto x86_l_1a16;
	case 6683ULL: goto x86_l_1a1b;
	case 6685ULL: goto x86_l_1a1d;
	case 6690ULL: goto x86_l_1a22;
	case 6697ULL: goto x86_l_1a29;
	case 6701ULL: goto x86_l_1a2d;
	case 6706ULL: goto x86_l_1a32;
	case 6711ULL: goto x86_l_1a37;
	case 6713ULL: goto x86_l_1a39;
	case 6718ULL: goto x86_l_1a3e;
	case 6725ULL: goto x86_l_1a45;
	case 6729ULL: goto x86_l_1a49;
	case 6734ULL: goto x86_l_1a4e;
	case 6739ULL: goto x86_l_1a53;
	case 6741ULL: goto x86_l_1a55;
	case 6746ULL: goto x86_l_1a5a;
	case 6753ULL: goto x86_l_1a61;
	case 6757ULL: goto x86_l_1a65;
	case 6762ULL: goto x86_l_1a6a;
	case 6767ULL: goto x86_l_1a6f;
	case 6769ULL: goto x86_l_1a71;
	case 6774ULL: goto x86_l_1a76;
	case 6781ULL: goto x86_l_1a7d;
	case 6785ULL: goto x86_l_1a81;
	case 6790ULL: goto x86_l_1a86;
	case 6795ULL: goto x86_l_1a8b;
	case 6797ULL: goto x86_l_1a8d;
	case 6802ULL: goto x86_l_1a92;
	case 6807ULL: goto x86_l_1a97;
	case 6812ULL: goto x86_l_1a9c;
	case 6817ULL: goto x86_l_1aa1;
	case 6822ULL: goto x86_l_1aa6;
	case 6827ULL: goto x86_l_1aab;
	case 6830ULL: goto x86_l_1aae;
	case 6832ULL: goto x86_l_1ab0;
	case 6837ULL: goto x86_l_1ab5;
	case 6844ULL: goto x86_l_1abc;
	case 6848ULL: goto x86_l_1ac0;
	case 6853ULL: goto x86_l_1ac5;
	case 6858ULL: goto x86_l_1aca;
	case 6860ULL: goto x86_l_1acc;
	case 6865ULL: goto x86_l_1ad1;
	case 6872ULL: goto x86_l_1ad8;
	case 6876ULL: goto x86_l_1adc;
	case 6881ULL: goto x86_l_1ae1;
	case 6883ULL: goto x86_l_1ae3;
	case 6887ULL: goto x86_l_1ae7;
	case 6892ULL: goto x86_l_1aec;
	case 6897ULL: goto x86_l_1af1;
	case 6902ULL: goto x86_l_1af6;
	case 6904ULL: goto x86_l_1af8;
	case 6908ULL: goto x86_l_1afc;
	case 6913ULL: goto x86_l_1b01;
	case 6919ULL: goto x86_l_1b07;
	case 6923ULL: goto x86_l_1b0b;
	case 6928ULL: goto x86_l_1b10;
	case 6933ULL: goto x86_l_1b15;
	case 6938ULL: goto x86_l_1b1a;
	case 6940ULL: goto x86_l_1b1c;
	case 6944ULL: goto x86_l_1b20;
	case 6949ULL: goto x86_l_1b25;
	case 6955ULL: goto x86_l_1b2b;
	case 6959ULL: goto x86_l_1b2f;
	case 6964ULL: goto x86_l_1b34;
	case 6969ULL: goto x86_l_1b39;
	case 6974ULL: goto x86_l_1b3e;
	case 6976ULL: goto x86_l_1b40;
	case 6981ULL: goto x86_l_1b45;
	case 6988ULL: goto x86_l_1b4c;
	case 6993ULL: goto x86_l_1b51;
	case 6998ULL: goto x86_l_1b56;
	case 7003ULL: goto x86_l_1b5b;
	case 7008ULL: goto x86_l_1b60;
	case 7010ULL: goto x86_l_1b62;
	case 7015ULL: goto x86_l_1b67;
	case 7020ULL: goto x86_l_1b6c;
	case 7025ULL: goto x86_l_1b71;
	case 7030ULL: goto x86_l_1b76;
	case 7038ULL: goto x86_l_1b7e;
	case 7046ULL: goto x86_l_1b86;
	case 7054ULL: goto x86_l_1b8e;
	case 7062ULL: goto x86_l_1b96;
	case 7070ULL: goto x86_l_1b9e;
	case 7078ULL: goto x86_l_1ba6;
	case 7086ULL: goto x86_l_1bae;
	case 7094ULL: goto x86_l_1bb6;
	case 7102ULL: goto x86_l_1bbe;
	case 7107ULL: goto x86_l_1bc3;
	case 7114ULL: goto x86_l_1bca;
	case 7119ULL: goto x86_l_1bcf;
	case 7124ULL: goto x86_l_1bd4;
	case 7129ULL: goto x86_l_1bd9;
	case 7132ULL: goto x86_l_1bdc;
	case 7135ULL: goto x86_l_1bdf;
	case 7137ULL: goto x86_l_1be1;
	case 7140ULL: goto x86_l_1be4;
	case 7146ULL: goto x86_l_1bea;
	case 7148ULL: goto x86_l_1bec;
	case 7153ULL: goto x86_l_1bf1;
	case 7156ULL: goto x86_l_1bf4;
	case 7161ULL: goto x86_l_1bf9;
	case 7168ULL: goto x86_l_1c00;
	case 7173ULL: goto x86_l_1c05;
	case 7178ULL: goto x86_l_1c0a;
	case 7183ULL: goto x86_l_1c0f;
	case 7188ULL: goto x86_l_1c14;
	case 7193ULL: goto x86_l_1c19;
	case 7198ULL: goto x86_l_1c1e;
	case 7203ULL: goto x86_l_1c23;
	case 7205ULL: goto x86_l_1c25;
	case 7209ULL: goto x86_l_1c29;
	case 7214ULL: goto x86_l_1c2e;
	case 7222ULL: goto x86_l_1c36;
	case 7227ULL: goto x86_l_1c3b;
	case 7230ULL: goto x86_l_1c3e;
	case 7232ULL: goto x86_l_1c40;
	case 7237ULL: goto x86_l_1c45;
	case 7245ULL: goto x86_l_1c4d;
	case 7252ULL: goto x86_l_1c54;
	case 7258ULL: goto x86_l_1c5a;
	case 7262ULL: goto x86_l_1c5e;
	case 7265ULL: goto x86_l_1c61;
	case 7272ULL: goto x86_l_1c68;
	case 7277ULL: goto x86_l_1c6d;
	case 7280ULL: goto x86_l_1c70;
	case 7282ULL: goto x86_l_1c72;
	case 7284ULL: goto x86_l_1c74;
	case 7286ULL: goto x86_l_1c76;
	case 7293ULL: goto x86_l_1c7d;
	case 7300ULL: goto x86_l_1c84;
	case 7304ULL: goto x86_l_1c88;
	case 7307ULL: goto x86_l_1c8b;
	case 7312ULL: goto x86_l_1c90;
	case 7322ULL: goto x86_l_1c9a;
	case 7327ULL: goto x86_l_1c9f;
	case 7335ULL: goto x86_l_1ca7;
	case 7340ULL: goto x86_l_1cac;
	case 7345ULL: goto x86_l_1cb1;
	case 7353ULL: goto x86_l_1cb9;
	case 7356ULL: goto x86_l_1cbc;
	case 7360ULL: goto x86_l_1cc0;
	case 7368ULL: goto x86_l_1cc8;
	case 7373ULL: goto x86_l_1ccd;
	case 7380ULL: goto x86_l_1cd4;
	case 7385ULL: goto x86_l_1cd9;
	case 7387ULL: goto x86_l_1cdb;
	case 7390ULL: goto x86_l_1cde;
	case 7396ULL: goto x86_l_1ce4;
	case 7399ULL: goto x86_l_1ce7;
	case 7402ULL: goto x86_l_1cea;
	case 7406ULL: goto x86_l_1cee;
	case 7410ULL: goto x86_l_1cf2;
	case 7413ULL: goto x86_l_1cf5;
	case 7417ULL: goto x86_l_1cf9;
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
	/* 0x15d2: js     1e6f <generic_retuprobe_event+0x1e6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7791ULL;
	}
x86_l_15d8:
	/* 0x15d8: movzx  eax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15dc:
	/* 0x15dc: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_15df:
	/* 0x15df: je     1e1d <generic_retuprobe_event+0x1e1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7709ULL;
	}
x86_l_15e5:
	/* 0x15e5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15e8:
	/* 0x15e8: jne    1e55 <generic_retuprobe_event+0x1e55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7765ULL;
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
	/* 0x1624: jmp    1e4b <generic_retuprobe_event+0x1e4b> */
	return 7755ULL;
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
	/* 0x1670: js     29c7 <generic_retuprobe_event+0x29c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10695ULL;
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
	/* 0x169d: ja     29c7 <generic_retuprobe_event+0x29c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10695ULL;
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
	/* 0x16d1: js     29c7 <generic_retuprobe_event+0x29c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10695ULL;
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
	/* 0x16e7: je     204e <generic_retuprobe_event+0x204e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8270ULL;
	}
x86_l_16ed:
	/* 0x16ed: sub    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 24ULL);
x86_l_16f2:
	/* 0x16f2: jne    2055 <generic_retuprobe_event+0x2055> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8277ULL;
	}
x86_l_16f8:
	/* 0x16f8: jmp    2060 <generic_retuprobe_event+0x2060> */
	return 8288ULL;
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
	/* 0x1794: jmp    1bec <generic_retuprobe_event+0x1bec> */
	goto x86_l_1bec;
x86_l_1799:
	/* 0x1799: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_179c:
	/* 0x179c: lea    r13,[rcx+0xdc] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_17a3:
	/* 0x17a3: lea    rdx,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17a7:
	/* 0x17a7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17ac:
	/* 0x17ac: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17b1:
	/* 0x17b1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17b6:
	/* 0x17b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17b8:
	/* 0x17b8: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17bd:
	/* 0x17bd: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_17c4:
	/* 0x17c4: lea    rdx,[rbx+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_17c8:
	/* 0x17c8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17cd:
	/* 0x17cd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17d2:
	/* 0x17d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17d4:
	/* 0x17d4: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17d9:
	/* 0x17d9: lea    rdi,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_17e0:
	/* 0x17e0: lea    rdx,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17e4:
	/* 0x17e4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17e9:
	/* 0x17e9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17ee:
	/* 0x17ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f0:
	/* 0x17f0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17f5:
	/* 0x17f5: lea    rdi,[rax+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_17fc:
	/* 0x17fc: lea    rdx,[rbx+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1800:
	/* 0x1800: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1805:
	/* 0x1805: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_180a:
	/* 0x180a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_180c:
	/* 0x180c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1811:
	/* 0x1811: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1818:
	/* 0x1818: lea    rdx,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_181c:
	/* 0x181c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1821:
	/* 0x1821: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1826:
	/* 0x1826: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1828:
	/* 0x1828: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_182d:
	/* 0x182d: lea    rdi,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1834:
	/* 0x1834: lea    rdx,[rbx+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1838:
	/* 0x1838: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_183d:
	/* 0x183d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1842:
	/* 0x1842: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1844:
	/* 0x1844: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1849:
	/* 0x1849: lea    rdi,[rax+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_1850:
	/* 0x1850: lea    rdx,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1854:
	/* 0x1854: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1859:
	/* 0x1859: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_185e:
	/* 0x185e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1860:
	/* 0x1860: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1865:
	/* 0x1865: lea    rdi,[rax+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_186c:
	/* 0x186c: lea    rdx,[rbx+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1870:
	/* 0x1870: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1875:
	/* 0x1875: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_187a:
	/* 0x187a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_187c:
	/* 0x187c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1881:
	/* 0x1881: mov    DWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_188b:
	/* 0x188b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1890:
	/* 0x1890: lea    rdi,[rax+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1897:
	/* 0x1897: lea    rdx,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_189b:
	/* 0x189b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18a0:
	/* 0x18a0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18a5:
	/* 0x18a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18a7:
	/* 0x18a7: mov    rcx,QWORD PTR [rbx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18ab:
	/* 0x18ab: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18b0:
	/* 0x18b0: mov    QWORD PTR [rax+0xcc],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_18b7:
	/* 0x18b7: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18bb:
	/* 0x18bb: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18c0:
	/* 0x18c0: mov    QWORD PTR [rax+0xd4],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_18c7:
	/* 0x18c7: mov    rcx,QWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18cb:
	/* 0x18cb: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18d0:
	/* 0x18d0: mov    QWORD PTR [rax+0xc4],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_18d7:
	/* 0x18d7: lea    rdx,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_18de:
	/* 0x18de: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18e3:
	/* 0x18e3: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18e8:
	/* 0x18e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18ed:
	/* 0x18ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ef:
	/* 0x18ef: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18f4:
	/* 0x18f4: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_18fc:
	/* 0x18fc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1901:
	/* 0x1901: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1904:
	/* 0x1904: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_1907:
	/* 0x1907: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_190c:
	/* 0x190c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1911:
	/* 0x1911: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1913:
	/* 0x1913: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1918:
	/* 0x1918: lea    rdi,[rax+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_191f:
	/* 0x191f: lea    rdx,[r12+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1927:
	/* 0x1927: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_192c:
	/* 0x192c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1931:
	/* 0x1931: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1933:
	/* 0x1933: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1938:
	/* 0x1938: lea    rdi,[rax+0xe4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_193f:
	/* 0x193f: lea    rdx,[r12+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1947:
	/* 0x1947: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_194c:
	/* 0x194c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1951:
	/* 0x1951: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1953:
	/* 0x1953: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1958:
	/* 0x1958: add    rdi,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_195f:
	/* 0x195f: add    r12,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1966:
	/* 0x1966: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_196b:
	/* 0x196b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1970:
	/* 0x1970: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1973:
	/* 0x1973: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1975:
	/* 0x1975: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_197a:
	/* 0x197a: mov    ebp,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 80ULL);
x86_l_197f:
	/* 0x197f: jmp    a1c <generic_retuprobe_event+0xa1c> */
	return 2588ULL;
x86_l_1984:
	/* 0x1984: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_198b:
	/* 0x198b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1990:
	/* 0x1990: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1995:
	/* 0x1995: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_199a:
	/* 0x199a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_199c:
	/* 0x199c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19a1:
	/* 0x19a1: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_19a8:
	/* 0x19a8: lea    rdx,[r13+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_19af:
	/* 0x19af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19b4:
	/* 0x19b4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19b9:
	/* 0x19b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19bb:
	/* 0x19bb: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19c0:
	/* 0x19c0: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_19c7:
	/* 0x19c7: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_19ce:
	/* 0x19ce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19d3:
	/* 0x19d3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19d8:
	/* 0x19d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19da:
	/* 0x19da: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19df:
	/* 0x19df: add    rdi,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_19e6:
	/* 0x19e6: lea    rdx,[r13+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_19ed:
	/* 0x19ed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19f2:
	/* 0x19f2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19f7:
	/* 0x19f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19f9:
	/* 0x19f9: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19fe:
	/* 0x19fe: mov    ebp,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_1a03:
	/* 0x1a03: jmp    a1c <generic_retuprobe_event+0xa1c> */
	return 2588ULL;
x86_l_1a08:
	/* 0x1a08: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a0c:
	/* 0x1a0c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a11:
	/* 0x1a11: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a16:
	/* 0x1a16: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a1b:
	/* 0x1a1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a1d:
	/* 0x1a1d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a22:
	/* 0x1a22: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1a29:
	/* 0x1a29: lea    rdx,[r13+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1a2d:
	/* 0x1a2d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a32:
	/* 0x1a32: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a37:
	/* 0x1a37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a39:
	/* 0x1a39: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a3e:
	/* 0x1a3e: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1a45:
	/* 0x1a45: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a49:
	/* 0x1a49: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a4e:
	/* 0x1a4e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a53:
	/* 0x1a53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a55:
	/* 0x1a55: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a5a:
	/* 0x1a5a: lea    rdi,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1a61:
	/* 0x1a61: lea    rdx,[r13+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a65:
	/* 0x1a65: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a6a:
	/* 0x1a6a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a6f:
	/* 0x1a6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a71:
	/* 0x1a71: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a76:
	/* 0x1a76: add    rdi,0xac */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 172ULL);
x86_l_1a7d:
	/* 0x1a7d: lea    rdx,[r13+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a81:
	/* 0x1a81: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a86:
	/* 0x1a86: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1a8b:
	/* 0x1a8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a8d:
	/* 0x1a8d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a92:
	/* 0x1a92: mov    ebp,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 32ULL);
x86_l_1a97:
	/* 0x1a97: jmp    a1c <generic_retuprobe_event+0xa1c> */
	return 2588ULL;
x86_l_1a9c:
	/* 0x1a9c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1aa1:
	/* 0x1aa1: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1aa6:
	/* 0x1aa6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1aab:
	/* 0x1aab: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1aae:
	/* 0x1aae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ab0:
	/* 0x1ab0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ab5:
	/* 0x1ab5: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1abc:
	/* 0x1abc: lea    rdx,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ac0:
	/* 0x1ac0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ac5:
	/* 0x1ac5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1aca:
	/* 0x1aca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1acc:
	/* 0x1acc: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ad1:
	/* 0x1ad1: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1ad8:
	/* 0x1ad8: lea    rdx,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1adc:
	/* 0x1adc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ae1:
	/* 0x1ae1: jmp    1b5b <generic_retuprobe_event+0x1b5b> */
	goto x86_l_1b5b;
x86_l_1ae3:
	/* 0x1ae3: lea    rdx,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ae7:
	/* 0x1ae7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1aec:
	/* 0x1aec: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1af1:
	/* 0x1af1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1af6:
	/* 0x1af6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1af8:
	/* 0x1af8: mov    ecx,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1afc:
	/* 0x1afc: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b01:
	/* 0x1b01: mov    DWORD PTR [rax+0x9c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1b07:
	/* 0x1b07: lea    rdx,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b0b:
	/* 0x1b0b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b10:
	/* 0x1b10: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b15:
	/* 0x1b15: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b1a:
	/* 0x1b1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b1c:
	/* 0x1b1c: mov    ecx,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b20:
	/* 0x1b20: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b25:
	/* 0x1b25: mov    DWORD PTR [rax+0xa0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1b2b:
	/* 0x1b2b: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b2f:
	/* 0x1b2f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b34:
	/* 0x1b34: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b39:
	/* 0x1b39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b3e:
	/* 0x1b3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b40:
	/* 0x1b40: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b45:
	/* 0x1b45: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1b4c:
	/* 0x1b4c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1b51:
	/* 0x1b51: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_1b56:
	/* 0x1b56: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_1b5b:
	/* 0x1b5b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b60:
	/* 0x1b60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b62:
	/* 0x1b62: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b67:
	/* 0x1b67: mov    ebp,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_1b6c:
	/* 0x1b6c: jmp    a1c <generic_retuprobe_event+0xa1c> */
	return 2588ULL;
x86_l_1b71:
	/* 0x1b71: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b76:
	/* 0x1b76: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1b7e:
	/* 0x1b7e: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1b86:
	/* 0x1b86: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1b8e:
	/* 0x1b8e: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1b96:
	/* 0x1b96: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1b9e:
	/* 0x1b9e: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1ba6:
	/* 0x1ba6: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1bae:
	/* 0x1bae: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1bb6:
	/* 0x1bb6: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1bbe:
	/* 0x1bbe: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bc3:
	/* 0x1bc3: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bca:
	/* 0x1bca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bcf:
	/* 0x1bcf: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1bd4:
	/* 0x1bd4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bd9:
	/* 0x1bd9: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_1bdc:
	/* 0x1bdc: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1bdf:
	/* 0x1bdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1be1:
	/* 0x1be1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1be4:
	/* 0x1be4: je     1e79 <generic_retuprobe_event+0x1e79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7801ULL;
	}
x86_l_1bea:
	/* 0x1bea: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bec:
	/* 0x1bec: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bf1:
	/* 0x1bf1: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_1bf4:
	/* 0x1bf4: jmp    a17 <generic_retuprobe_event+0xa17> */
	return 2583ULL;
x86_l_1bf9:
	/* 0x1bf9: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1c00:
	/* 0x1c00: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c05:
	/* 0x1c05: jmp    a1c <generic_retuprobe_event+0xa1c> */
	return 2588ULL;
x86_l_1c0a:
	/* 0x1c0a: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c0f:
	/* 0x1c0f: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1c14:
	/* 0x1c14: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c19:
	/* 0x1c19: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c1e:
	/* 0x1c1e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c23:
	/* 0x1c23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c25:
	/* 0x1c25: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1c29:
	/* 0x1c29: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c2e:
	/* 0x1c2e: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1c36:
	/* 0x1c36: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c3b:
	/* 0x1c3b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1c3e:
	/* 0x1c3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c40:
	/* 0x1c40: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c45:
	/* 0x1c45: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1c4d:
	/* 0x1c4d: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_1c54:
	/* 0x1c54: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_1c5a:
	/* 0x1c5a: cmovb  r12,r13 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_1c5e:
	/* 0x1c5e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1c61:
	/* 0x1c61: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1c68:
	/* 0x1c68: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c6d:
	/* 0x1c6d: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_1c70:
	/* 0x1c70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c72:
	/* 0x1c72: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c74:
	/* 0x1c74: js     1c90 <generic_retuprobe_event+0x1c90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1c90;
	}
x86_l_1c76:
	/* 0x1c76: mov    DWORD PTR [rbx+0x9c],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1c7d:
	/* 0x1c7d: mov    DWORD PTR [rbx+0xa0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1c84:
	/* 0x1c84: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1c88:
	/* 0x1c88: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_1c8b:
	/* 0x1c8b: jmp    1e0e <generic_retuprobe_event+0x1e0e> */
	return 7694ULL;
x86_l_1c90:
	/* 0x1c90: mov    DWORD PTR [rbx+0x9c],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 674309865470ULL);
x86_l_1c9a:
	/* 0x1c9a: jmp    1e0e <generic_retuprobe_event+0x1e0e> */
	return 7694ULL;
x86_l_1c9f:
	/* 0x1c9f: mov    QWORD PTR [rsp+0x88],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1ca7:
	/* 0x1ca7: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cac:
	/* 0x1cac: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1cb1:
	/* 0x1cb1: movzx  ebx,WORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 176ULL);
x86_l_1cb9:
	/* 0x1cb9: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1cbc:
	/* 0x1cbc: lea    r13,[rax+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1cc0:
	/* 0x1cc0: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1cc8:
	/* 0x1cc8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ccd:
	/* 0x1ccd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_1cd4:
	/* 0x1cd4: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cd9:
	/* 0x1cd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cdb:
	/* 0x1cdb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cde:
	/* 0x1cde: je     268c <generic_retuprobe_event+0x268c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9868ULL;
	}
x86_l_1ce4:
	/* 0x1ce4: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1ce7:
	/* 0x1ce7: mov    WORD PTR [rax],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cea:
	/* 0x1cea: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_1cee:
	/* 0x1cee: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_1cf2:
	/* 0x1cf2: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1cf5:
	/* 0x1cf5: add    rdi,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_1cf9:
	/* 0x1cf9: lea    rdx,[r13+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1cfd:
	/* 0x1cfd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 7426ULL;
}

static __noinline __u64 tetragon_bpf_multi_retuprobe_v61_generic_retuprobe_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7426ULL: goto x86_l_1d02;
	case 7429ULL: goto x86_l_1d05;
	case 7434ULL: goto x86_l_1d0a;
	case 7436ULL: goto x86_l_1d0c;
	case 7439ULL: goto x86_l_1d0f;
	case 7445ULL: goto x86_l_1d15;
	case 7449ULL: goto x86_l_1d19;
	case 7452ULL: goto x86_l_1d1c;
	case 7458ULL: goto x86_l_1d22;
	case 7460ULL: goto x86_l_1d24;
	case 7466ULL: goto x86_l_1d2a;
	case 7469ULL: goto x86_l_1d2d;
	case 7475ULL: goto x86_l_1d33;
	case 7478ULL: goto x86_l_1d36;
	case 7484ULL: goto x86_l_1d3c;
	case 7490ULL: goto x86_l_1d42;
	case 7494ULL: goto x86_l_1d46;
	case 7499ULL: goto x86_l_1d4b;
	case 7503ULL: goto x86_l_1d4f;
	case 7508ULL: goto x86_l_1d54;
	case 7513ULL: goto x86_l_1d59;
	case 7515ULL: goto x86_l_1d5b;
	case 7519ULL: goto x86_l_1d5f;
	case 7524ULL: goto x86_l_1d64;
	case 7527ULL: goto x86_l_1d67;
	case 7532ULL: goto x86_l_1d6c;
	case 7534ULL: goto x86_l_1d6e;
	case 7539ULL: goto x86_l_1d73;
	case 7546ULL: goto x86_l_1d7a;
	case 7550ULL: goto x86_l_1d7e;
	case 7554ULL: goto x86_l_1d82;
	case 7559ULL: goto x86_l_1d87;
	case 7564ULL: goto x86_l_1d8c;
	case 7567ULL: goto x86_l_1d8f;
	case 7569ULL: goto x86_l_1d91;
	case 7572ULL: goto x86_l_1d94;
	case 7579ULL: goto x86_l_1d9b;
	case 7584ULL: goto x86_l_1da0;
	case 7589ULL: goto x86_l_1da5;
	case 7592ULL: goto x86_l_1da8;
	case 7594ULL: goto x86_l_1daa;
	case 7601ULL: goto x86_l_1db1;
	case 7610ULL: goto x86_l_1dba;
	case 7615ULL: goto x86_l_1dbf;
	case 7620ULL: goto x86_l_1dc4;
	case 7625ULL: goto x86_l_1dc9;
	case 7632ULL: goto x86_l_1dd0;
	case 7637ULL: goto x86_l_1dd5;
	case 7639ULL: goto x86_l_1dd7;
	case 7642ULL: goto x86_l_1dda;
	case 7644ULL: goto x86_l_1ddc;
	case 7646ULL: goto x86_l_1dde;
	case 7654ULL: goto x86_l_1de6;
	case 7657ULL: goto x86_l_1de9;
	case 7661ULL: goto x86_l_1ded;
	case 7665ULL: goto x86_l_1df1;
	case 7668ULL: goto x86_l_1df4;
	case 7671ULL: goto x86_l_1df7;
	case 7676ULL: goto x86_l_1dfc;
	case 7678ULL: goto x86_l_1dfe;
	case 7689ULL: goto x86_l_1e09;
	case 7694ULL: goto x86_l_1e0e;
	case 7699ULL: goto x86_l_1e13;
	case 7704ULL: goto x86_l_1e18;
	case 7709ULL: goto x86_l_1e1d;
	case 7716ULL: goto x86_l_1e24;
	case 7721ULL: goto x86_l_1e29;
	case 7726ULL: goto x86_l_1e2e;
	case 7731ULL: goto x86_l_1e33;
	case 7734ULL: goto x86_l_1e36;
	case 7736ULL: goto x86_l_1e38;
	case 7739ULL: goto x86_l_1e3b;
	case 7746ULL: goto x86_l_1e42;
	case 7750ULL: goto x86_l_1e46;
	case 7755ULL: goto x86_l_1e4b;
	case 7760ULL: goto x86_l_1e50;
	case 7763ULL: goto x86_l_1e53;
	case 7765ULL: goto x86_l_1e55;
	case 7770ULL: goto x86_l_1e5a;
	case 7777ULL: goto x86_l_1e61;
	case 7786ULL: goto x86_l_1e6a;
	case 7791ULL: goto x86_l_1e6f;
	case 7796ULL: goto x86_l_1e74;
	case 7801ULL: goto x86_l_1e79;
	case 7806ULL: goto x86_l_1e7e;
	case 7813ULL: goto x86_l_1e85;
	case 7818ULL: goto x86_l_1e8a;
	case 7823ULL: goto x86_l_1e8f;
	case 7828ULL: goto x86_l_1e94;
	case 7830ULL: goto x86_l_1e96;
	case 7833ULL: goto x86_l_1e99;
	case 7839ULL: goto x86_l_1e9f;
	case 7842ULL: goto x86_l_1ea2;
	case 7846ULL: goto x86_l_1ea6;
	case 7851ULL: goto x86_l_1eab;
	case 7856ULL: goto x86_l_1eb0;
	case 7861ULL: goto x86_l_1eb5;
	case 7863ULL: goto x86_l_1eb7;
	case 7868ULL: goto x86_l_1ebc;
	case 7875ULL: goto x86_l_1ec3;
	case 7880ULL: goto x86_l_1ec8;
	case 7885ULL: goto x86_l_1ecd;
	case 7890ULL: goto x86_l_1ed2;
	case 7895ULL: goto x86_l_1ed7;
	case 7897ULL: goto x86_l_1ed9;
	case 7901ULL: goto x86_l_1edd;
	case 7906ULL: goto x86_l_1ee2;
	case 7911ULL: goto x86_l_1ee7;
	case 7916ULL: goto x86_l_1eec;
	case 7918ULL: goto x86_l_1eee;
	case 7923ULL: goto x86_l_1ef3;
	case 7926ULL: goto x86_l_1ef6;
	case 7932ULL: goto x86_l_1efc;
	case 7934ULL: goto x86_l_1efe;
	case 7939ULL: goto x86_l_1f03;
	case 7942ULL: goto x86_l_1f06;
	case 7947ULL: goto x86_l_1f0b;
	case 7949ULL: goto x86_l_1f0d;
	case 7954ULL: goto x86_l_1f12;
	case 7956ULL: goto x86_l_1f14;
	case 7961ULL: goto x86_l_1f19;
	case 7966ULL: goto x86_l_1f1e;
	case 7970ULL: goto x86_l_1f22;
	case 7975ULL: goto x86_l_1f27;
	case 7980ULL: goto x86_l_1f2c;
	case 7983ULL: goto x86_l_1f2f;
	case 7985ULL: goto x86_l_1f31;
	case 7988ULL: goto x86_l_1f34;
	case 7990ULL: goto x86_l_1f36;
	case 7992ULL: goto x86_l_1f38;
	case 7994ULL: goto x86_l_1f3a;
	case 7999ULL: goto x86_l_1f3f;
	case 8005ULL: goto x86_l_1f45;
	case 8010ULL: goto x86_l_1f4a;
	case 8015ULL: goto x86_l_1f4f;
	case 8018ULL: goto x86_l_1f52;
	case 8023ULL: goto x86_l_1f57;
	case 8027ULL: goto x86_l_1f5b;
	case 8032ULL: goto x86_l_1f60;
	case 8037ULL: goto x86_l_1f65;
	case 8039ULL: goto x86_l_1f67;
	case 8043ULL: goto x86_l_1f6b;
	case 8048ULL: goto x86_l_1f70;
	case 8051ULL: goto x86_l_1f73;
	case 8056ULL: goto x86_l_1f78;
	case 8058ULL: goto x86_l_1f7a;
	case 8063ULL: goto x86_l_1f7f;
	case 8070ULL: goto x86_l_1f86;
	case 8074ULL: goto x86_l_1f8a;
	case 8078ULL: goto x86_l_1f8e;
	case 8083ULL: goto x86_l_1f93;
	case 8088ULL: goto x86_l_1f98;
	case 8091ULL: goto x86_l_1f9b;
	case 8093ULL: goto x86_l_1f9d;
	case 8096ULL: goto x86_l_1fa0;
	case 8103ULL: goto x86_l_1fa7;
	case 8108ULL: goto x86_l_1fac;
	case 8113ULL: goto x86_l_1fb1;
	case 8116ULL: goto x86_l_1fb4;
	case 8118ULL: goto x86_l_1fb6;
	case 8125ULL: goto x86_l_1fbd;
	case 8134ULL: goto x86_l_1fc6;
	case 8139ULL: goto x86_l_1fcb;
	case 8146ULL: goto x86_l_1fd2;
	case 8151ULL: goto x86_l_1fd7;
	case 8156ULL: goto x86_l_1fdc;
	case 8163ULL: goto x86_l_1fe3;
	case 8168ULL: goto x86_l_1fe8;
	case 8170ULL: goto x86_l_1fea;
	case 8173ULL: goto x86_l_1fed;
	case 8175ULL: goto x86_l_1fef;
	case 8177ULL: goto x86_l_1ff1;
	case 8180ULL: goto x86_l_1ff4;
	case 8184ULL: goto x86_l_1ff8;
	case 8188ULL: goto x86_l_1ffc;
	case 8191ULL: goto x86_l_1fff;
	case 8194ULL: goto x86_l_2002;
	case 8199ULL: goto x86_l_2007;
	case 8204ULL: goto x86_l_200c;
	case 8209ULL: goto x86_l_2011;
	case 8214ULL: goto x86_l_2016;
	case 8217ULL: goto x86_l_2019;
	case 8223ULL: goto x86_l_201f;
	case 8226ULL: goto x86_l_2022;
	case 8228ULL: goto x86_l_2024;
	case 8233ULL: goto x86_l_2029;
	case 8239ULL: goto x86_l_202f;
	case 8245ULL: goto x86_l_2035;
	case 8249ULL: goto x86_l_2039;
	case 8254ULL: goto x86_l_203e;
	case 8258ULL: goto x86_l_2042;
	case 8265ULL: goto x86_l_2049;
	case 8270ULL: goto x86_l_204e;
	case 8272ULL: goto x86_l_2050;
	case 8277ULL: goto x86_l_2055;
	case 8286ULL: goto x86_l_205e;
	case 8288ULL: goto x86_l_2060;
	case 8293ULL: goto x86_l_2065;
	case 8298ULL: goto x86_l_206a;
	case 8306ULL: goto x86_l_2072;
	case 8310ULL: goto x86_l_2076;
	case 8315ULL: goto x86_l_207b;
	case 8320ULL: goto x86_l_2080;
	case 8325ULL: goto x86_l_2085;
	case 8330ULL: goto x86_l_208a;
	case 8332ULL: goto x86_l_208c;
	case 8337ULL: goto x86_l_2091;
	case 8339ULL: goto x86_l_2093;
	case 8345ULL: goto x86_l_2099;
	case 8350ULL: goto x86_l_209e;
	case 8355ULL: goto x86_l_20a3;
	case 8358ULL: goto x86_l_20a6;
	case 8361ULL: goto x86_l_20a9;
	case 8365ULL: goto x86_l_20ad;
	case 8368ULL: goto x86_l_20b0;
	case 8372ULL: goto x86_l_20b4;
	case 8377ULL: goto x86_l_20b9;
	case 8384ULL: goto x86_l_20c0;
	case 8390ULL: goto x86_l_20c6;
	case 8393ULL: goto x86_l_20c9;
	case 8398ULL: goto x86_l_20ce;
	case 8403ULL: goto x86_l_20d3;
	case 8408ULL: goto x86_l_20d8;
	case 8414ULL: goto x86_l_20de;
	case 8417ULL: goto x86_l_20e1;
	case 8422ULL: goto x86_l_20e6;
	case 8427ULL: goto x86_l_20eb;
	case 8430ULL: goto x86_l_20ee;
	case 8432ULL: goto x86_l_20f0;
	case 8437ULL: goto x86_l_20f5;
	case 8439ULL: goto x86_l_20f7;
	case 8445ULL: goto x86_l_20fd;
	case 8450ULL: goto x86_l_2102;
	case 8456ULL: goto x86_l_2108;
	case 8462ULL: goto x86_l_210e;
	case 8467ULL: goto x86_l_2113;
	case 8473ULL: goto x86_l_2119;
	case 8478ULL: goto x86_l_211e;
	case 8482ULL: goto x86_l_2122;
	case 8489ULL: goto x86_l_2129;
	case 8493ULL: goto x86_l_212d;
	case 8497ULL: goto x86_l_2131;
	case 8501ULL: goto x86_l_2135;
	case 8505ULL: goto x86_l_2139;
	case 8509ULL: goto x86_l_213d;
	case 8515ULL: goto x86_l_2143;
	case 8525ULL: goto x86_l_214d;
	case 8529ULL: goto x86_l_2151;
	case 8535ULL: goto x86_l_2157;
	case 8538ULL: goto x86_l_215a;
	case 8543ULL: goto x86_l_215f;
	case 8547ULL: goto x86_l_2163;
	case 8550ULL: goto x86_l_2166;
	case 8553ULL: goto x86_l_2169;
	case 8558ULL: goto x86_l_216e;
	case 8560ULL: goto x86_l_2170;
	case 8563ULL: goto x86_l_2173;
	case 8569ULL: goto x86_l_2179;
	case 8573ULL: goto x86_l_217d;
	case 8576ULL: goto x86_l_2180;
	case 8578ULL: goto x86_l_2182;
	case 8580ULL: goto x86_l_2184;
	case 8582ULL: goto x86_l_2186;
	case 8585ULL: goto x86_l_2189;
	case 8587ULL: goto x86_l_218b;
	case 8590ULL: goto x86_l_218e;
	case 8592ULL: goto x86_l_2190;
	case 8598ULL: goto x86_l_2196;
	case 8602ULL: goto x86_l_219a;
	case 8604ULL: goto x86_l_219c;
	case 8607ULL: goto x86_l_219f;
	case 8609ULL: goto x86_l_21a1;
	case 8612ULL: goto x86_l_21a4;
	case 8614ULL: goto x86_l_21a6;
	case 8619ULL: goto x86_l_21ab;
	case 8621ULL: goto x86_l_21ad;
	case 8627ULL: goto x86_l_21b3;
	case 8631ULL: goto x86_l_21b7;
	case 8633ULL: goto x86_l_21b9;
	case 8637ULL: goto x86_l_21bd;
	case 8644ULL: goto x86_l_21c4;
	case 8648ULL: goto x86_l_21c8;
	case 8650ULL: goto x86_l_21ca;
	case 8654ULL: goto x86_l_21ce;
	case 8659ULL: goto x86_l_21d3;
	case 8663ULL: goto x86_l_21d7;
	case 8670ULL: goto x86_l_21de;
	case 8674ULL: goto x86_l_21e2;
	case 8676ULL: goto x86_l_21e4;
	case 8680ULL: goto x86_l_21e8;
	case 8684ULL: goto x86_l_21ec;
	case 8688ULL: goto x86_l_21f0;
	case 8692ULL: goto x86_l_21f4;
	case 8696ULL: goto x86_l_21f8;
	case 8702ULL: goto x86_l_21fe;
	case 8712ULL: goto x86_l_2208;
	case 8716ULL: goto x86_l_220c;
	case 8722ULL: goto x86_l_2212;
	case 8725ULL: goto x86_l_2215;
	case 8730ULL: goto x86_l_221a;
	case 8734ULL: goto x86_l_221e;
	case 8737ULL: goto x86_l_2221;
	case 8740ULL: goto x86_l_2224;
	case 8745ULL: goto x86_l_2229;
	case 8747ULL: goto x86_l_222b;
	case 8750ULL: goto x86_l_222e;
	case 8756ULL: goto x86_l_2234;
	case 8760ULL: goto x86_l_2238;
	case 8763ULL: goto x86_l_223b;
	case 8765ULL: goto x86_l_223d;
	case 8767ULL: goto x86_l_223f;
	case 8769ULL: goto x86_l_2241;
	case 8772ULL: goto x86_l_2244;
	case 8774ULL: goto x86_l_2246;
	case 8777ULL: goto x86_l_2249;
	case 8779ULL: goto x86_l_224b;
	case 8785ULL: goto x86_l_2251;
	case 8789ULL: goto x86_l_2255;
	case 8791ULL: goto x86_l_2257;
	case 8794ULL: goto x86_l_225a;
	case 8796ULL: goto x86_l_225c;
	case 8799ULL: goto x86_l_225f;
	case 8801ULL: goto x86_l_2261;
	case 8806ULL: goto x86_l_2266;
	case 8808ULL: goto x86_l_2268;
	case 8814ULL: goto x86_l_226e;
	case 8818ULL: goto x86_l_2272;
	case 8820ULL: goto x86_l_2274;
	case 8824ULL: goto x86_l_2278;
	case 8831ULL: goto x86_l_227f;
	case 8835ULL: goto x86_l_2283;
	case 8837ULL: goto x86_l_2285;
	case 8841ULL: goto x86_l_2289;
	case 8848ULL: goto x86_l_2290;
	case 8852ULL: goto x86_l_2294;
	case 8854ULL: goto x86_l_2296;
	case 8858ULL: goto x86_l_229a;
	case 8862ULL: goto x86_l_229e;
	case 8866ULL: goto x86_l_22a2;
	case 8870ULL: goto x86_l_22a6;
	case 8874ULL: goto x86_l_22aa;
	case 8880ULL: goto x86_l_22b0;
	case 8890ULL: goto x86_l_22ba;
	case 8894ULL: goto x86_l_22be;
	case 8900ULL: goto x86_l_22c4;
	case 8903ULL: goto x86_l_22c7;
	case 8908ULL: goto x86_l_22cc;
	case 8912ULL: goto x86_l_22d0;
	case 8915ULL: goto x86_l_22d3;
	case 8918ULL: goto x86_l_22d6;
	case 8923ULL: goto x86_l_22db;
	case 8925ULL: goto x86_l_22dd;
	case 8928ULL: goto x86_l_22e0;
	case 8934ULL: goto x86_l_22e6;
	case 8938ULL: goto x86_l_22ea;
	case 8941ULL: goto x86_l_22ed;
	case 8943ULL: goto x86_l_22ef;
	case 8945ULL: goto x86_l_22f1;
	case 8947ULL: goto x86_l_22f3;
	case 8950ULL: goto x86_l_22f6;
	case 8952ULL: goto x86_l_22f8;
	case 8955ULL: goto x86_l_22fb;
	case 8957ULL: goto x86_l_22fd;
	case 8963ULL: goto x86_l_2303;
	case 8967ULL: goto x86_l_2307;
	case 8969ULL: goto x86_l_2309;
	case 8972ULL: goto x86_l_230c;
	case 8974ULL: goto x86_l_230e;
	case 8977ULL: goto x86_l_2311;
	case 8979ULL: goto x86_l_2313;
	case 8984ULL: goto x86_l_2318;
	case 8986ULL: goto x86_l_231a;
	case 8992ULL: goto x86_l_2320;
	case 8996ULL: goto x86_l_2324;
	case 8998ULL: goto x86_l_2326;
	case 9002ULL: goto x86_l_232a;
	case 9009ULL: goto x86_l_2331;
	case 9013ULL: goto x86_l_2335;
	case 9015ULL: goto x86_l_2337;
	case 9019ULL: goto x86_l_233b;
	case 9026ULL: goto x86_l_2342;
	case 9030ULL: goto x86_l_2346;
	case 9032ULL: goto x86_l_2348;
	case 9036ULL: goto x86_l_234c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1d02:
	/* 0x1d02: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_1d05:
	/* 0x1d05: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1d0a:
	/* 0x1d0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d0c:
	/* 0x1d0c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d0f:
	/* 0x1d0f: js     268c <generic_retuprobe_event+0x268c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9868ULL;
	}
x86_l_1d15:
	/* 0x1d15: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_1d19:
	/* 0x1d19: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_1d1c:
	/* 0x1d1c: jg     2016 <generic_retuprobe_event+0x2016> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2016;
	}
x86_l_1d22:
	/* 0x1d22: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d24:
	/* 0x1d24: je     203e <generic_retuprobe_event+0x203e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_203e;
	}
x86_l_1d2a:
	/* 0x1d2a: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1d2d:
	/* 0x1d2d: je     203e <generic_retuprobe_event+0x203e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_203e;
	}
x86_l_1d33:
	/* 0x1d33: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_1d36:
	/* 0x1d36: jne    21ca <generic_retuprobe_event+0x21ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21ca;
	}
x86_l_1d3c:
	/* 0x1d3c: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_1d42:
	/* 0x1d42: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_1d46:
	/* 0x1d46: jmp    212d <generic_retuprobe_event+0x212d> */
	goto x86_l_212d;
x86_l_1d4b:
	/* 0x1d4b: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1d4f:
	/* 0x1d4f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d54:
	/* 0x1d54: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d59:
	/* 0x1d59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d5b:
	/* 0x1d5b: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d5f:
	/* 0x1d5f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d64:
	/* 0x1d64: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1d67:
	/* 0x1d67: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d6c:
	/* 0x1d6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d6e:
	/* 0x1d6e: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d73:
	/* 0x1d73: lea    rdi,[rbx+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1d7a:
	/* 0x1d7a: lea    r12,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d7e:
	/* 0x1d7e: add    r13,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_1d82:
	/* 0x1d82: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d87:
	/* 0x1d87: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1d8c:
	/* 0x1d8c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1d8f:
	/* 0x1d8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d91:
	/* 0x1d91: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d94:
	/* 0x1d94: add    rdi,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_1d9b:
	/* 0x1d9b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1da0:
	/* 0x1da0: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1da5:
	/* 0x1da5: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1da8:
	/* 0x1da8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1daa:
	/* 0x1daa: movzx  eax,WORD PTR [rbx+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1db1:
	/* 0x1db1: movbe  WORD PTR [rbx+0xbe],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1dba:
	/* 0x1dba: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dbf:
	/* 0x1dbf: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1dc4:
	/* 0x1dc4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dc9:
	/* 0x1dc9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_1dd0:
	/* 0x1dd0: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1dd5:
	/* 0x1dd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd7:
	/* 0x1dd7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dda:
	/* 0x1dda: je     1df7 <generic_retuprobe_event+0x1df7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1df7;
	}
x86_l_1ddc:
	/* 0x1ddc: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dde:
	/* 0x1dde: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1de6:
	/* 0x1de6: mov    DWORD PTR [rdx+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1de9:
	/* 0x1de9: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ded:
	/* 0x1ded: mov    QWORD PTR [rdx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1df1:
	/* 0x1df1: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1df4:
	/* 0x1df4: mov    DWORD PTR [rdx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1df7:
	/* 0x1df7: mov    ebp,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_1dfc:
	/* 0x1dfc: jmp    1e0e <generic_retuprobe_event+0x1e0e> */
	goto x86_l_1e0e;
x86_l_1dfe:
	/* 0x1dfe: mov    QWORD PTR [rbx+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1e09:
	/* 0x1e09: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_1e0e:
	/* 0x1e0e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e13:
	/* 0x1e13: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e18:
	/* 0x1e18: jmp    a17 <generic_retuprobe_event+0xa17> */
	return 2583ULL;
x86_l_1e1d:
	/* 0x1e1d: lea    rdi,[rcx+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1e24:
	/* 0x1e24: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e29:
	/* 0x1e29: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e2e:
	/* 0x1e2e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e33:
	/* 0x1e33: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_1e36:
	/* 0x1e36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e38:
	/* 0x1e38: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e3b:
	/* 0x1e3b: add    rdi,0x9e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 158ULL);
x86_l_1e42:
	/* 0x1e42: add    r12,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1e46:
	/* 0x1e46: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e4b:
	/* 0x1e4b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1e50:
	/* 0x1e50: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1e53:
	/* 0x1e53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e55:
	/* 0x1e55: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e5a:
	/* 0x1e5a: movzx  eax,WORD PTR [rcx+0x9e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_1e61:
	/* 0x1e61: movbe  WORD PTR [rcx+0x9e],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_1e6a:
	/* 0x1e6a: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_1e6f:
	/* 0x1e6f: mov    ebp,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_1e74:
	/* 0x1e74: jmp    a1c <generic_retuprobe_event+0xa1c> */
	return 2588ULL;
x86_l_1e79:
	/* 0x1e79: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e7e:
	/* 0x1e7e: lea    rdi,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1e85:
	/* 0x1e85: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1e8a:
	/* 0x1e8a: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e8f:
	/* 0x1e8f: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_1e94:
	/* 0x1e94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e96:
	/* 0x1e96: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e99:
	/* 0x1e99: js     1bea <generic_retuprobe_event+0x1bea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7146ULL;
	}
x86_l_1e9f:
	/* 0x1e9f: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_1ea2:
	/* 0x1ea2: lea    rdx,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ea6:
	/* 0x1ea6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1eab:
	/* 0x1eab: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1eb0:
	/* 0x1eb0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1eb5:
	/* 0x1eb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eb7:
	/* 0x1eb7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ebc:
	/* 0x1ebc: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1ec3:
	/* 0x1ec3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ec8:
	/* 0x1ec8: mov    edx,0x348 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 840ULL);
x86_l_1ecd:
	/* 0x1ecd: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_1ed2:
	/* 0x1ed2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ed7:
	/* 0x1ed7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ed9:
	/* 0x1ed9: lea    rdx,[rbx+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1edd:
	/* 0x1edd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ee2:
	/* 0x1ee2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ee7:
	/* 0x1ee7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1eec:
	/* 0x1eec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eee:
	/* 0x1eee: mov    ebp,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 80ULL);
x86_l_1ef3:
	/* 0x1ef3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ef6:
	/* 0x1ef6: jne    1bec <generic_retuprobe_event+0x1bec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7148ULL;
	}
x86_l_1efc:
	/* 0x1efc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1efe:
	/* 0x1efe: cmp    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1f03:
	/* 0x1f03: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1f06:
	/* 0x1f06: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f0b:
	/* 0x1f0b: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f0d:
	/* 0x1f0d: jmp    1bec <generic_retuprobe_event+0x1bec> */
	return 7148ULL;
x86_l_1f12:
	/* 0x1f12: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f14:
	/* 0x1f14: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f19:
	/* 0x1f19: jmp    a17 <generic_retuprobe_event+0xa17> */
	return 2583ULL;
x86_l_1f1e:
	/* 0x1f1e: add    r12,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_1f22:
	/* 0x1f22: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f27:
	/* 0x1f27: mov    esi,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 107ULL);
x86_l_1f2c:
	/* 0x1f2c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f2f:
	/* 0x1f2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f31:
	/* 0x1f31: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1f34:
	/* 0x1f34: mov    al,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 107ULL);
x86_l_1f36:
	/* 0x1f36: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1f38:
	/* 0x1f38: js     1f45 <generic_retuprobe_event+0x1f45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1f45;
	}
x86_l_1f3a:
	/* 0x1f3a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f3f:
	/* 0x1f3f: mov    BYTE PTR [rcx+0x9f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 159ULL);
x86_l_1f45:
	/* 0x1f45: mov    ebp,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 112ULL);
x86_l_1f4a:
	/* 0x1f4a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f4f:
	/* 0x1f4f: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_1f52:
	/* 0x1f52: jmp    a17 <generic_retuprobe_event+0xa17> */
	return 2583ULL;
x86_l_1f57:
	/* 0x1f57: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1f5b:
	/* 0x1f5b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f60:
	/* 0x1f60: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1f65:
	/* 0x1f65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f67:
	/* 0x1f67: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f6b:
	/* 0x1f6b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f70:
	/* 0x1f70: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1f73:
	/* 0x1f73: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1f78:
	/* 0x1f78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f7a:
	/* 0x1f7a: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f7f:
	/* 0x1f7f: lea    rdi,[rbx+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1f86:
	/* 0x1f86: lea    r12,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f8a:
	/* 0x1f8a: add    r13,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_1f8e:
	/* 0x1f8e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f93:
	/* 0x1f93: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1f98:
	/* 0x1f98: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1f9b:
	/* 0x1f9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f9d:
	/* 0x1f9d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1fa0:
	/* 0x1fa0: add    rdi,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_1fa7:
	/* 0x1fa7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fac:
	/* 0x1fac: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1fb1:
	/* 0x1fb1: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1fb4:
	/* 0x1fb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb6:
	/* 0x1fb6: movzx  eax,WORD PTR [rbx+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1fbd:
	/* 0x1fbd: movbe  WORD PTR [rbx+0xbe],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1fc6:
	/* 0x1fc6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fcb:
	/* 0x1fcb: mov    rax,QWORD PTR [rax+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1fd2:
	/* 0x1fd2: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1fd7:
	/* 0x1fd7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fdc:
	/* 0x1fdc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_1fe3:
	/* 0x1fe3: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1fe8:
	/* 0x1fe8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fea:
	/* 0x1fea: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fed:
	/* 0x1fed: je     2002 <generic_retuprobe_event+0x2002> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2002;
	}
x86_l_1fef:
	/* 0x1fef: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ff1:
	/* 0x1ff1: mov    DWORD PTR [rbp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ff4:
	/* 0x1ff4: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ff8:
	/* 0x1ff8: mov    QWORD PTR [rbp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ffc:
	/* 0x1ffc: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1fff:
	/* 0x1fff: mov    DWORD PTR [rbp+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2002:
	/* 0x2002: mov    ebp,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_2007:
	/* 0x2007: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_200c:
	/* 0x200c: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2011:
	/* 0x2011: jmp    a17 <generic_retuprobe_event+0xa17> */
	return 2583ULL;
x86_l_2016:
	/* 0x2016: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2019:
	/* 0x2019: je     211e <generic_retuprobe_event+0x211e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_211e;
	}
x86_l_201f:
	/* 0x201f: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2022:
	/* 0x2022: je     203e <generic_retuprobe_event+0x203e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_203e;
	}
x86_l_2024:
	/* 0x2024: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2029:
	/* 0x2029: jne    21ca <generic_retuprobe_event+0x21ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21ca;
	}
x86_l_202f:
	/* 0x202f: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2035:
	/* 0x2035: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2039:
	/* 0x2039: jmp    212d <generic_retuprobe_event+0x212d> */
	goto x86_l_212d;
x86_l_203e:
	/* 0x203e: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2042:
	/* 0x2042: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2049:
	/* 0x2049: jmp    2129 <generic_retuprobe_event+0x2129> */
	goto x86_l_2129;
x86_l_204e:
	/* 0x204e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2050:
	/* 0x2050: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2055:
	/* 0x2055: cmp    QWORD PTR [rsp+0x80],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813891ULL);
x86_l_205e:
	/* 0x205e: jne    206a <generic_retuprobe_event+0x206a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_206a;
	}
x86_l_2060:
	/* 0x2060: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2065:
	/* 0x2065: jmp    2c9 <generic_retuprobe_event+0x2c9> */
	return 713ULL;
x86_l_206a:
	/* 0x206a: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2072:
	/* 0x2072: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2076:
	/* 0x2076: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_207b:
	/* 0x207b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2080:
	/* 0x2080: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2085:
	/* 0x2085: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_208a:
	/* 0x208a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_208c:
	/* 0x208c: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2091:
	/* 0x2091: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2093:
	/* 0x2093: js     29c7 <generic_retuprobe_event+0x29c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10695ULL;
	}
x86_l_2099:
	/* 0x2099: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_209e:
	/* 0x209e: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20a3:
	/* 0x20a3: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_20a6:
	/* 0x20a6: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_20a9:
	/* 0x20a9: cmovb  rbx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_20ad:
	/* 0x20ad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20b0:
	/* 0x20b0: cmovne rdx,rbx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RBX, X86_WIDTH_64, X86_CC_NE);
x86_l_20b4:
	/* 0x20b4: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_20b9:
	/* 0x20b9: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_20c0:
	/* 0x20c0: ja     29c7 <generic_retuprobe_event+0x29c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10695ULL;
	}
x86_l_20c6:
	/* 0x20c6: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_20c9:
	/* 0x20c9: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20ce:
	/* 0x20ce: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_20d3:
	/* 0x20d3: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20d8:
	/* 0x20d8: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_20de:
	/* 0x20de: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_20e1:
	/* 0x20e1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20e6:
	/* 0x20e6: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_20eb:
	/* 0x20eb: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_20ee:
	/* 0x20ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20f0:
	/* 0x20f0: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_20f5:
	/* 0x20f5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20f7:
	/* 0x20f7: js     29c7 <generic_retuprobe_event+0x29c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10695ULL;
	}
x86_l_20fd:
	/* 0x20fd: add    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_2102:
	/* 0x2102: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2108:
	/* 0x2108: je     23fe <generic_retuprobe_event+0x23fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9214ULL;
	}
x86_l_210e:
	/* 0x210e: sub    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 24ULL);
x86_l_2113:
	/* 0x2113: jne    2405 <generic_retuprobe_event+0x2405> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9221ULL;
	}
x86_l_2119:
	/* 0x2119: jmp    2060 <generic_retuprobe_event+0x2060> */
	goto x86_l_2060;
x86_l_211e:
	/* 0x211e: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2122:
	/* 0x2122: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2129:
	/* 0x2129: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_212d:
	/* 0x212d: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2131:
	/* 0x2131: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2135:
	/* 0x2135: movzx  ecx,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2139:
	/* 0x2139: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_213d:
	/* 0x213d: ja     2852 <generic_retuprobe_event+0x2852> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10322ULL;
	}
x86_l_2143:
	/* 0x2143: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_214d:
	/* 0x214d: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2151:
	/* 0x2151: jae    2852 <generic_retuprobe_event+0x2852> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10322ULL;
	}
x86_l_2157:
	/* 0x2157: mov    BYTE PTR [rbp+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_215a:
	/* 0x215a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_215f:
	/* 0x215f: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2163:
	/* 0x2163: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2166:
	/* 0x2166: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2169:
	/* 0x2169: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_216e:
	/* 0x216e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2170:
	/* 0x2170: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2173:
	/* 0x2173: js     268c <generic_retuprobe_event+0x268c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9868ULL;
	}
x86_l_2179:
	/* 0x2179: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_217d:
	/* 0x217d: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2180:
	/* 0x2180: jg     219c <generic_retuprobe_event+0x219c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_219c;
	}
x86_l_2182:
	/* 0x2182: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2184:
	/* 0x2184: je     21b9 <generic_retuprobe_event+0x21b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21b9;
	}
x86_l_2186:
	/* 0x2186: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2189:
	/* 0x2189: je     21b9 <generic_retuprobe_event+0x21b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21b9;
	}
x86_l_218b:
	/* 0x218b: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_218e:
	/* 0x218e: jne    21e4 <generic_retuprobe_event+0x21e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21e4;
	}
x86_l_2190:
	/* 0x2190: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2196:
	/* 0x2196: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_219a:
	/* 0x219a: jmp    21e8 <generic_retuprobe_event+0x21e8> */
	goto x86_l_21e8;
x86_l_219c:
	/* 0x219c: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_219f:
	/* 0x219f: je     21d3 <generic_retuprobe_event+0x21d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21d3;
	}
x86_l_21a1:
	/* 0x21a1: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_21a4:
	/* 0x21a4: je     21b9 <generic_retuprobe_event+0x21b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21b9;
	}
x86_l_21a6:
	/* 0x21a6: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_21ab:
	/* 0x21ab: jne    21e4 <generic_retuprobe_event+0x21e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21e4;
	}
x86_l_21ad:
	/* 0x21ad: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_21b3:
	/* 0x21b3: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_21b7:
	/* 0x21b7: jmp    21e8 <generic_retuprobe_event+0x21e8> */
	goto x86_l_21e8;
x86_l_21b9:
	/* 0x21b9: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_21bd:
	/* 0x21bd: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_21c4:
	/* 0x21c4: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_21c8:
	/* 0x21c8: jmp    21e8 <generic_retuprobe_event+0x21e8> */
	goto x86_l_21e8;
x86_l_21ca:
	/* 0x21ca: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_21ce:
	/* 0x21ce: jmp    212d <generic_retuprobe_event+0x212d> */
	goto x86_l_212d;
x86_l_21d3:
	/* 0x21d3: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_21d7:
	/* 0x21d7: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_21de:
	/* 0x21de: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_21e2:
	/* 0x21e2: jmp    21e8 <generic_retuprobe_event+0x21e8> */
	goto x86_l_21e8;
x86_l_21e4:
	/* 0x21e4: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_21e8:
	/* 0x21e8: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_21ec:
	/* 0x21ec: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21f0:
	/* 0x21f0: movzx  ecx,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_21f4:
	/* 0x21f4: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_21f8:
	/* 0x21f8: ja     2852 <generic_retuprobe_event+0x2852> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10322ULL;
	}
x86_l_21fe:
	/* 0x21fe: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2208:
	/* 0x2208: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_220c:
	/* 0x220c: jae    2852 <generic_retuprobe_event+0x2852> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10322ULL;
	}
x86_l_2212:
	/* 0x2212: mov    BYTE PTR [rbp+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2215:
	/* 0x2215: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_221a:
	/* 0x221a: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_221e:
	/* 0x221e: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2221:
	/* 0x2221: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2224:
	/* 0x2224: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2229:
	/* 0x2229: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_222b:
	/* 0x222b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_222e:
	/* 0x222e: js     268c <generic_retuprobe_event+0x268c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9868ULL;
	}
x86_l_2234:
	/* 0x2234: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2238:
	/* 0x2238: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_223b:
	/* 0x223b: jg     2257 <generic_retuprobe_event+0x2257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2257;
	}
x86_l_223d:
	/* 0x223d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_223f:
	/* 0x223f: je     2274 <generic_retuprobe_event+0x2274> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2274;
	}
x86_l_2241:
	/* 0x2241: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2244:
	/* 0x2244: je     2274 <generic_retuprobe_event+0x2274> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2274;
	}
x86_l_2246:
	/* 0x2246: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2249:
	/* 0x2249: jne    2296 <generic_retuprobe_event+0x2296> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2296;
	}
x86_l_224b:
	/* 0x224b: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2251:
	/* 0x2251: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2255:
	/* 0x2255: jmp    229a <generic_retuprobe_event+0x229a> */
	goto x86_l_229a;
x86_l_2257:
	/* 0x2257: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_225a:
	/* 0x225a: je     2285 <generic_retuprobe_event+0x2285> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2285;
	}
x86_l_225c:
	/* 0x225c: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_225f:
	/* 0x225f: je     2274 <generic_retuprobe_event+0x2274> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2274;
	}
x86_l_2261:
	/* 0x2261: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2266:
	/* 0x2266: jne    2296 <generic_retuprobe_event+0x2296> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2296;
	}
x86_l_2268:
	/* 0x2268: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_226e:
	/* 0x226e: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2272:
	/* 0x2272: jmp    229a <generic_retuprobe_event+0x229a> */
	goto x86_l_229a;
x86_l_2274:
	/* 0x2274: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2278:
	/* 0x2278: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_227f:
	/* 0x227f: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2283:
	/* 0x2283: jmp    229a <generic_retuprobe_event+0x229a> */
	goto x86_l_229a;
x86_l_2285:
	/* 0x2285: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2289:
	/* 0x2289: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2290:
	/* 0x2290: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2294:
	/* 0x2294: jmp    229a <generic_retuprobe_event+0x229a> */
	goto x86_l_229a;
x86_l_2296:
	/* 0x2296: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_229a:
	/* 0x229a: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_229e:
	/* 0x229e: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22a2:
	/* 0x22a2: movzx  ecx,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_22a6:
	/* 0x22a6: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_22aa:
	/* 0x22aa: ja     2852 <generic_retuprobe_event+0x2852> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10322ULL;
	}
x86_l_22b0:
	/* 0x22b0: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_22ba:
	/* 0x22ba: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_22be:
	/* 0x22be: jae    2852 <generic_retuprobe_event+0x2852> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10322ULL;
	}
x86_l_22c4:
	/* 0x22c4: mov    BYTE PTR [rbp+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_22c7:
	/* 0x22c7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22cc:
	/* 0x22cc: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_22d0:
	/* 0x22d0: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_22d3:
	/* 0x22d3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_22d6:
	/* 0x22d6: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_22db:
	/* 0x22db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22dd:
	/* 0x22dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22e0:
	/* 0x22e0: js     268c <generic_retuprobe_event+0x268c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9868ULL;
	}
x86_l_22e6:
	/* 0x22e6: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_22ea:
	/* 0x22ea: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_22ed:
	/* 0x22ed: jg     2309 <generic_retuprobe_event+0x2309> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2309;
	}
x86_l_22ef:
	/* 0x22ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22f1:
	/* 0x22f1: je     2326 <generic_retuprobe_event+0x2326> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2326;
	}
x86_l_22f3:
	/* 0x22f3: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_22f6:
	/* 0x22f6: je     2326 <generic_retuprobe_event+0x2326> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2326;
	}
x86_l_22f8:
	/* 0x22f8: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_22fb:
	/* 0x22fb: jne    2348 <generic_retuprobe_event+0x2348> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2348;
	}
x86_l_22fd:
	/* 0x22fd: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2303:
	/* 0x2303: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2307:
	/* 0x2307: jmp    234c <generic_retuprobe_event+0x234c> */
	goto x86_l_234c;
x86_l_2309:
	/* 0x2309: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_230c:
	/* 0x230c: je     2337 <generic_retuprobe_event+0x2337> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2337;
	}
x86_l_230e:
	/* 0x230e: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2311:
	/* 0x2311: je     2326 <generic_retuprobe_event+0x2326> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2326;
	}
x86_l_2313:
	/* 0x2313: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2318:
	/* 0x2318: jne    2348 <generic_retuprobe_event+0x2348> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2348;
	}
x86_l_231a:
	/* 0x231a: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2320:
	/* 0x2320: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2324:
	/* 0x2324: jmp    234c <generic_retuprobe_event+0x234c> */
	goto x86_l_234c;
x86_l_2326:
	/* 0x2326: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_232a:
	/* 0x232a: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2331:
	/* 0x2331: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2335:
	/* 0x2335: jmp    234c <generic_retuprobe_event+0x234c> */
	goto x86_l_234c;
x86_l_2337:
	/* 0x2337: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_233b:
	/* 0x233b: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2342:
	/* 0x2342: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2346:
	/* 0x2346: jmp    234c <generic_retuprobe_event+0x234c> */
	goto x86_l_234c;
x86_l_2348:
	/* 0x2348: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_234c:
	/* 0x234c: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
	return 9040ULL;
}

static __noinline __u64 tetragon_bpf_multi_retuprobe_v61_generic_retuprobe_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9040ULL: goto x86_l_2350;
	case 9044ULL: goto x86_l_2354;
	case 9048ULL: goto x86_l_2358;
	case 9052ULL: goto x86_l_235c;
	case 9058ULL: goto x86_l_2362;
	case 9068ULL: goto x86_l_236c;
	case 9072ULL: goto x86_l_2370;
	case 9078ULL: goto x86_l_2376;
	case 9081ULL: goto x86_l_2379;
	case 9086ULL: goto x86_l_237e;
	case 9090ULL: goto x86_l_2382;
	case 9093ULL: goto x86_l_2385;
	case 9096ULL: goto x86_l_2388;
	case 9101ULL: goto x86_l_238d;
	case 9103ULL: goto x86_l_238f;
	case 9106ULL: goto x86_l_2392;
	case 9112ULL: goto x86_l_2398;
	case 9116ULL: goto x86_l_239c;
	case 9119ULL: goto x86_l_239f;
	case 9121ULL: goto x86_l_23a1;
	case 9123ULL: goto x86_l_23a3;
	case 9125ULL: goto x86_l_23a5;
	case 9128ULL: goto x86_l_23a8;
	case 9130ULL: goto x86_l_23aa;
	case 9133ULL: goto x86_l_23ad;
	case 9139ULL: goto x86_l_23b3;
	case 9145ULL: goto x86_l_23b9;
	case 9149ULL: goto x86_l_23bd;
	case 9154ULL: goto x86_l_23c2;
	case 9157ULL: goto x86_l_23c5;
	case 9163ULL: goto x86_l_23cb;
	case 9166ULL: goto x86_l_23ce;
	case 9168ULL: goto x86_l_23d0;
	case 9173ULL: goto x86_l_23d5;
	case 9179ULL: goto x86_l_23db;
	case 9185ULL: goto x86_l_23e1;
	case 9189ULL: goto x86_l_23e5;
	case 9194ULL: goto x86_l_23ea;
	case 9198ULL: goto x86_l_23ee;
	case 9205ULL: goto x86_l_23f5;
	case 9209ULL: goto x86_l_23f9;
	case 9214ULL: goto x86_l_23fe;
	case 9216ULL: goto x86_l_2400;
	case 9221ULL: goto x86_l_2405;
	case 9230ULL: goto x86_l_240e;
	case 9236ULL: goto x86_l_2414;
	case 9244ULL: goto x86_l_241c;
	case 9248ULL: goto x86_l_2420;
	case 9253ULL: goto x86_l_2425;
	case 9258ULL: goto x86_l_242a;
	case 9263ULL: goto x86_l_242f;
	case 9268ULL: goto x86_l_2434;
	case 9270ULL: goto x86_l_2436;
	case 9275ULL: goto x86_l_243b;
	case 9277ULL: goto x86_l_243d;
	case 9283ULL: goto x86_l_2443;
	case 9288ULL: goto x86_l_2448;
	case 9293ULL: goto x86_l_244d;
	case 9296ULL: goto x86_l_2450;
	case 9299ULL: goto x86_l_2453;
	case 9303ULL: goto x86_l_2457;
	case 9306ULL: goto x86_l_245a;
	case 9310ULL: goto x86_l_245e;
	case 9315ULL: goto x86_l_2463;
	case 9320ULL: goto x86_l_2468;
	case 9327ULL: goto x86_l_246f;
	case 9333ULL: goto x86_l_2475;
	case 9336ULL: goto x86_l_2478;
	case 9341ULL: goto x86_l_247d;
	case 9344ULL: goto x86_l_2480;
	case 9350ULL: goto x86_l_2486;
	case 9353ULL: goto x86_l_2489;
	case 9358ULL: goto x86_l_248e;
	case 9363ULL: goto x86_l_2493;
	case 9368ULL: goto x86_l_2498;
	case 9370ULL: goto x86_l_249a;
	case 9375ULL: goto x86_l_249f;
	case 9377ULL: goto x86_l_24a1;
	case 9383ULL: goto x86_l_24a7;
	case 9388ULL: goto x86_l_24ac;
	case 9393ULL: goto x86_l_24b1;
	case 9399ULL: goto x86_l_24b7;
	case 9405ULL: goto x86_l_24bd;
	case 9410ULL: goto x86_l_24c2;
	case 9416ULL: goto x86_l_24c8;
	case 9421ULL: goto x86_l_24cd;
	case 9425ULL: goto x86_l_24d1;
	case 9432ULL: goto x86_l_24d8;
	case 9436ULL: goto x86_l_24dc;
	case 9438ULL: goto x86_l_24de;
	case 9442ULL: goto x86_l_24e2;
	case 9446ULL: goto x86_l_24e6;
	case 9450ULL: goto x86_l_24ea;
	case 9454ULL: goto x86_l_24ee;
	case 9458ULL: goto x86_l_24f2;
	case 9464ULL: goto x86_l_24f8;
	case 9474ULL: goto x86_l_2502;
	case 9478ULL: goto x86_l_2506;
	case 9484ULL: goto x86_l_250c;
	case 9487ULL: goto x86_l_250f;
	case 9492ULL: goto x86_l_2514;
	case 9496ULL: goto x86_l_2518;
	case 9499ULL: goto x86_l_251b;
	case 9502ULL: goto x86_l_251e;
	case 9507ULL: goto x86_l_2523;
	case 9509ULL: goto x86_l_2525;
	case 9512ULL: goto x86_l_2528;
	case 9518ULL: goto x86_l_252e;
	case 9522ULL: goto x86_l_2532;
	case 9525ULL: goto x86_l_2535;
	case 9527ULL: goto x86_l_2537;
	case 9529ULL: goto x86_l_2539;
	case 9531ULL: goto x86_l_253b;
	case 9534ULL: goto x86_l_253e;
	case 9536ULL: goto x86_l_2540;
	case 9539ULL: goto x86_l_2543;
	case 9541ULL: goto x86_l_2545;
	case 9547ULL: goto x86_l_254b;
	case 9551ULL: goto x86_l_254f;
	case 9553ULL: goto x86_l_2551;
	case 9556ULL: goto x86_l_2554;
	case 9558ULL: goto x86_l_2556;
	case 9561ULL: goto x86_l_2559;
	case 9563ULL: goto x86_l_255b;
	case 9568ULL: goto x86_l_2560;
	case 9570ULL: goto x86_l_2562;
	case 9576ULL: goto x86_l_2568;
	case 9580ULL: goto x86_l_256c;
	case 9582ULL: goto x86_l_256e;
	case 9586ULL: goto x86_l_2572;
	case 9593ULL: goto x86_l_2579;
	case 9597ULL: goto x86_l_257d;
	case 9599ULL: goto x86_l_257f;
	case 9603ULL: goto x86_l_2583;
	case 9610ULL: goto x86_l_258a;
	case 9614ULL: goto x86_l_258e;
	case 9616ULL: goto x86_l_2590;
	case 9620ULL: goto x86_l_2594;
	case 9624ULL: goto x86_l_2598;
	case 9628ULL: goto x86_l_259c;
	case 9632ULL: goto x86_l_25a0;
	case 9636ULL: goto x86_l_25a4;
	case 9642ULL: goto x86_l_25aa;
	case 9652ULL: goto x86_l_25b4;
	case 9656ULL: goto x86_l_25b8;
	case 9662ULL: goto x86_l_25be;
	case 9665ULL: goto x86_l_25c1;
	case 9670ULL: goto x86_l_25c6;
	case 9674ULL: goto x86_l_25ca;
	case 9677ULL: goto x86_l_25cd;
	case 9680ULL: goto x86_l_25d0;
	case 9685ULL: goto x86_l_25d5;
	case 9687ULL: goto x86_l_25d7;
	case 9690ULL: goto x86_l_25da;
	case 9696ULL: goto x86_l_25e0;
	case 9700ULL: goto x86_l_25e4;
	case 9703ULL: goto x86_l_25e7;
	case 9705ULL: goto x86_l_25e9;
	case 9707ULL: goto x86_l_25eb;
	case 9709ULL: goto x86_l_25ed;
	case 9712ULL: goto x86_l_25f0;
	case 9714ULL: goto x86_l_25f2;
	case 9717ULL: goto x86_l_25f5;
	case 9719ULL: goto x86_l_25f7;
	case 9725ULL: goto x86_l_25fd;
	case 9729ULL: goto x86_l_2601;
	case 9731ULL: goto x86_l_2603;
	case 9734ULL: goto x86_l_2606;
	case 9736ULL: goto x86_l_2608;
	case 9739ULL: goto x86_l_260b;
	case 9741ULL: goto x86_l_260d;
	case 9746ULL: goto x86_l_2612;
	case 9748ULL: goto x86_l_2614;
	case 9754ULL: goto x86_l_261a;
	case 9758ULL: goto x86_l_261e;
	case 9760ULL: goto x86_l_2620;
	case 9764ULL: goto x86_l_2624;
	case 9771ULL: goto x86_l_262b;
	case 9775ULL: goto x86_l_262f;
	case 9777ULL: goto x86_l_2631;
	case 9781ULL: goto x86_l_2635;
	case 9788ULL: goto x86_l_263c;
	case 9792ULL: goto x86_l_2640;
	case 9794ULL: goto x86_l_2642;
	case 9798ULL: goto x86_l_2646;
	case 9802ULL: goto x86_l_264a;
	case 9806ULL: goto x86_l_264e;
	case 9810ULL: goto x86_l_2652;
	case 9814ULL: goto x86_l_2656;
	case 9820ULL: goto x86_l_265c;
	case 9830ULL: goto x86_l_2666;
	case 9834ULL: goto x86_l_266a;
	case 9840ULL: goto x86_l_2670;
	case 9843ULL: goto x86_l_2673;
	case 9848ULL: goto x86_l_2678;
	case 9852ULL: goto x86_l_267c;
	case 9855ULL: goto x86_l_267f;
	case 9858ULL: goto x86_l_2682;
	case 9863ULL: goto x86_l_2687;
	case 9866ULL: goto x86_l_268a;
	case 9868ULL: goto x86_l_268c;
	case 9870ULL: goto x86_l_268e;
	case 9877ULL: goto x86_l_2695;
	case 9880ULL: goto x86_l_2698;
	case 9885ULL: goto x86_l_269d;
	case 9892ULL: goto x86_l_26a4;
	case 9901ULL: goto x86_l_26ad;
	case 9905ULL: goto x86_l_26b1;
	case 9910ULL: goto x86_l_26b6;
	case 9915ULL: goto x86_l_26bb;
	case 9920ULL: goto x86_l_26c0;
	case 9922ULL: goto x86_l_26c2;
	case 9929ULL: goto x86_l_26c9;
	case 9933ULL: goto x86_l_26cd;
	case 9938ULL: goto x86_l_26d2;
	case 9943ULL: goto x86_l_26d7;
	case 9946ULL: goto x86_l_26da;
	case 9948ULL: goto x86_l_26dc;
	case 9956ULL: goto x86_l_26e4;
	case 9959ULL: goto x86_l_26e7;
	case 9961ULL: goto x86_l_26e9;
	case 9964ULL: goto x86_l_26ec;
	case 9970ULL: goto x86_l_26f2;
	case 9975ULL: goto x86_l_26f7;
	case 9984ULL: goto x86_l_2700;
	case 9988ULL: goto x86_l_2704;
	case 9993ULL: goto x86_l_2709;
	case 10000ULL: goto x86_l_2710;
	case 10005ULL: goto x86_l_2715;
	case 10010ULL: goto x86_l_271a;
	case 10012ULL: goto x86_l_271c;
	case 10019ULL: goto x86_l_2723;
	case 10023ULL: goto x86_l_2727;
	case 10027ULL: goto x86_l_272b;
	case 10032ULL: goto x86_l_2730;
	case 10034ULL: goto x86_l_2732;
	case 10039ULL: goto x86_l_2737;
	case 10048ULL: goto x86_l_2740;
	case 10052ULL: goto x86_l_2744;
	case 10057ULL: goto x86_l_2749;
	case 10064ULL: goto x86_l_2750;
	case 10069ULL: goto x86_l_2755;
	case 10074ULL: goto x86_l_275a;
	case 10076ULL: goto x86_l_275c;
	case 10083ULL: goto x86_l_2763;
	case 10087ULL: goto x86_l_2767;
	case 10091ULL: goto x86_l_276b;
	case 10096ULL: goto x86_l_2770;
	case 10101ULL: goto x86_l_2775;
	case 10103ULL: goto x86_l_2777;
	case 10105ULL: goto x86_l_2779;
	case 10110ULL: goto x86_l_277e;
	case 10120ULL: goto x86_l_2788;
	case 10125ULL: goto x86_l_278d;
	case 10132ULL: goto x86_l_2794;
	case 10139ULL: goto x86_l_279b;
	case 10148ULL: goto x86_l_27a4;
	case 10157ULL: goto x86_l_27ad;
	case 10165ULL: goto x86_l_27b5;
	case 10172ULL: goto x86_l_27bc;
	case 10177ULL: goto x86_l_27c1;
	case 10182ULL: goto x86_l_27c6;
	case 10187ULL: goto x86_l_27cb;
	case 10189ULL: goto x86_l_27cd;
	case 10195ULL: goto x86_l_27d3;
	case 10197ULL: goto x86_l_27d5;
	case 10202ULL: goto x86_l_27da;
	case 10207ULL: goto x86_l_27df;
	case 10211ULL: goto x86_l_27e3;
	case 10219ULL: goto x86_l_27eb;
	case 10224ULL: goto x86_l_27f0;
	case 10226ULL: goto x86_l_27f2;
	case 10231ULL: goto x86_l_27f7;
	case 10239ULL: goto x86_l_27ff;
	case 10243ULL: goto x86_l_2803;
	case 10248ULL: goto x86_l_2808;
	case 10255ULL: goto x86_l_280f;
	case 10260ULL: goto x86_l_2814;
	case 10265ULL: goto x86_l_2819;
	case 10267ULL: goto x86_l_281b;
	case 10270ULL: goto x86_l_281e;
	case 10277ULL: goto x86_l_2825;
	case 10281ULL: goto x86_l_2829;
	case 10285ULL: goto x86_l_282d;
	case 10290ULL: goto x86_l_2832;
	case 10295ULL: goto x86_l_2837;
	case 10297ULL: goto x86_l_2839;
	case 10302ULL: goto x86_l_283e;
	case 10307ULL: goto x86_l_2843;
	case 10312ULL: goto x86_l_2848;
	case 10317ULL: goto x86_l_284d;
	case 10322ULL: goto x86_l_2852;
	case 10330ULL: goto x86_l_285a;
	case 10335ULL: goto x86_l_285f;
	case 10337ULL: goto x86_l_2861;
	case 10342ULL: goto x86_l_2866;
	case 10351ULL: goto x86_l_286f;
	case 10357ULL: goto x86_l_2875;
	case 10365ULL: goto x86_l_287d;
	case 10369ULL: goto x86_l_2881;
	case 10374ULL: goto x86_l_2886;
	case 10379ULL: goto x86_l_288b;
	case 10384ULL: goto x86_l_2890;
	case 10389ULL: goto x86_l_2895;
	case 10391ULL: goto x86_l_2897;
	case 10396ULL: goto x86_l_289c;
	case 10398ULL: goto x86_l_289e;
	case 10404ULL: goto x86_l_28a4;
	case 10409ULL: goto x86_l_28a9;
	case 10414ULL: goto x86_l_28ae;
	case 10417ULL: goto x86_l_28b1;
	case 10420ULL: goto x86_l_28b4;
	case 10424ULL: goto x86_l_28b8;
	case 10427ULL: goto x86_l_28bb;
	case 10431ULL: goto x86_l_28bf;
	case 10436ULL: goto x86_l_28c4;
	case 10441ULL: goto x86_l_28c9;
	case 10448ULL: goto x86_l_28d0;
	case 10454ULL: goto x86_l_28d6;
	case 10459ULL: goto x86_l_28db;
	case 10462ULL: goto x86_l_28de;
	case 10467ULL: goto x86_l_28e3;
	case 10473ULL: goto x86_l_28e9;
	case 10476ULL: goto x86_l_28ec;
	case 10481ULL: goto x86_l_28f1;
	case 10486ULL: goto x86_l_28f6;
	case 10491ULL: goto x86_l_28fb;
	case 10493ULL: goto x86_l_28fd;
	case 10498ULL: goto x86_l_2902;
	case 10500ULL: goto x86_l_2904;
	case 10506ULL: goto x86_l_290a;
	case 10511ULL: goto x86_l_290f;
	case 10516ULL: goto x86_l_2914;
	case 10522ULL: goto x86_l_291a;
	case 10524ULL: goto x86_l_291c;
	case 10529ULL: goto x86_l_2921;
	case 10531ULL: goto x86_l_2923;
	case 10536ULL: goto x86_l_2928;
	case 10538ULL: goto x86_l_292a;
	case 10543ULL: goto x86_l_292f;
	case 10552ULL: goto x86_l_2938;
	case 10558ULL: goto x86_l_293e;
	case 10566ULL: goto x86_l_2946;
	case 10570ULL: goto x86_l_294a;
	case 10575ULL: goto x86_l_294f;
	case 10580ULL: goto x86_l_2954;
	case 10585ULL: goto x86_l_2959;
	case 10590ULL: goto x86_l_295e;
	case 10592ULL: goto x86_l_2960;
	case 10597ULL: goto x86_l_2965;
	case 10599ULL: goto x86_l_2967;
	case 10601ULL: goto x86_l_2969;
	case 10606ULL: goto x86_l_296e;
	case 10611ULL: goto x86_l_2973;
	case 10614ULL: goto x86_l_2976;
	case 10617ULL: goto x86_l_2979;
	case 10621ULL: goto x86_l_297d;
	case 10624ULL: goto x86_l_2980;
	case 10628ULL: goto x86_l_2984;
	case 10633ULL: goto x86_l_2989;
	case 10640ULL: goto x86_l_2990;
	case 10642ULL: goto x86_l_2992;
	case 10647ULL: goto x86_l_2997;
	case 10652ULL: goto x86_l_299c;
	case 10658ULL: goto x86_l_29a2;
	case 10661ULL: goto x86_l_29a5;
	case 10666ULL: goto x86_l_29aa;
	case 10671ULL: goto x86_l_29af;
	case 10674ULL: goto x86_l_29b2;
	case 10676ULL: goto x86_l_29b4;
	case 10681ULL: goto x86_l_29b9;
	case 10683ULL: goto x86_l_29bb;
	case 10685ULL: goto x86_l_29bd;
	case 10690ULL: goto x86_l_29c2;
	case 10695ULL: goto x86_l_29c7;
	case 10699ULL: goto x86_l_29cb;
	case 10702ULL: goto x86_l_29ce;
	case 10705ULL: goto x86_l_29d1;
	case 10710ULL: goto x86_l_29d6;
	case 10712ULL: goto x86_l_29d8;
	case 10715ULL: goto x86_l_29db;
	case 10720ULL: goto x86_l_29e0;
	case 10725ULL: goto x86_l_29e5;
	case 10733ULL: goto x86_l_29ed;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2350:
	/* 0x2350: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2354:
	/* 0x2354: movzx  ecx,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2358:
	/* 0x2358: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_235c:
	/* 0x235c: ja     2852 <generic_retuprobe_event+0x2852> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2852;
	}
x86_l_2362:
	/* 0x2362: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_236c:
	/* 0x236c: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2370:
	/* 0x2370: jae    2852 <generic_retuprobe_event+0x2852> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2852;
	}
x86_l_2376:
	/* 0x2376: mov    BYTE PTR [rbp+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2379:
	/* 0x2379: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_237e:
	/* 0x237e: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2382:
	/* 0x2382: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2385:
	/* 0x2385: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2388:
	/* 0x2388: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_238d:
	/* 0x238d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_238f:
	/* 0x238f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2392:
	/* 0x2392: js     268c <generic_retuprobe_event+0x268c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_268c;
	}
x86_l_2398:
	/* 0x2398: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_239c:
	/* 0x239c: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_239f:
	/* 0x239f: jg     23c2 <generic_retuprobe_event+0x23c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_23c2;
	}
x86_l_23a1:
	/* 0x23a1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23a3:
	/* 0x23a3: je     23ea <generic_retuprobe_event+0x23ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23ea;
	}
x86_l_23a5:
	/* 0x23a5: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_23a8:
	/* 0x23a8: je     23ea <generic_retuprobe_event+0x23ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23ea;
	}
x86_l_23aa:
	/* 0x23aa: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_23ad:
	/* 0x23ad: jne    24de <generic_retuprobe_event+0x24de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24de;
	}
x86_l_23b3:
	/* 0x23b3: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_23b9:
	/* 0x23b9: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_23bd:
	/* 0x23bd: jmp    24e2 <generic_retuprobe_event+0x24e2> */
	goto x86_l_24e2;
x86_l_23c2:
	/* 0x23c2: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_23c5:
	/* 0x23c5: je     24cd <generic_retuprobe_event+0x24cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24cd;
	}
x86_l_23cb:
	/* 0x23cb: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_23ce:
	/* 0x23ce: je     23ea <generic_retuprobe_event+0x23ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23ea;
	}
x86_l_23d0:
	/* 0x23d0: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_23d5:
	/* 0x23d5: jne    24de <generic_retuprobe_event+0x24de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24de;
	}
x86_l_23db:
	/* 0x23db: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_23e1:
	/* 0x23e1: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_23e5:
	/* 0x23e5: jmp    24e2 <generic_retuprobe_event+0x24e2> */
	goto x86_l_24e2;
x86_l_23ea:
	/* 0x23ea: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_23ee:
	/* 0x23ee: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_23f5:
	/* 0x23f5: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_23f9:
	/* 0x23f9: jmp    24e2 <generic_retuprobe_event+0x24e2> */
	goto x86_l_24e2;
x86_l_23fe:
	/* 0x23fe: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2400:
	/* 0x2400: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2405:
	/* 0x2405: cmp    QWORD PTR [rsp+0x80],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813893ULL);
x86_l_240e:
	/* 0x240e: jb     2060 <generic_retuprobe_event+0x2060> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8288ULL;
	}
x86_l_2414:
	/* 0x2414: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_241c:
	/* 0x241c: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2420:
	/* 0x2420: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_2425:
	/* 0x2425: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_242a:
	/* 0x242a: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_242f:
	/* 0x242f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2434:
	/* 0x2434: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2436:
	/* 0x2436: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_243b:
	/* 0x243b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_243d:
	/* 0x243d: js     29c7 <generic_retuprobe_event+0x29c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29c7;
	}
x86_l_2443:
	/* 0x2443: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2448:
	/* 0x2448: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_244d:
	/* 0x244d: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2450:
	/* 0x2450: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2453:
	/* 0x2453: cmovb  rbx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_2457:
	/* 0x2457: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_245a:
	/* 0x245a: cmovne rdx,rbx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RBX, X86_WIDTH_64, X86_CC_NE);
x86_l_245e:
	/* 0x245e: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2463:
	/* 0x2463: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2468:
	/* 0x2468: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_246f:
	/* 0x246f: ja     29c7 <generic_retuprobe_event+0x29c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29c7;
	}
x86_l_2475:
	/* 0x2475: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2478:
	/* 0x2478: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_247d:
	/* 0x247d: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_2480:
	/* 0x2480: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2486:
	/* 0x2486: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2489:
	/* 0x2489: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_248e:
	/* 0x248e: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2493:
	/* 0x2493: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2498:
	/* 0x2498: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_249a:
	/* 0x249a: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_249f:
	/* 0x249f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24a1:
	/* 0x24a1: js     29c7 <generic_retuprobe_event+0x29c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29c7;
	}
x86_l_24a7:
	/* 0x24a7: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24ac:
	/* 0x24ac: add    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_24b1:
	/* 0x24b1: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_24b7:
	/* 0x24b7: je     285f <generic_retuprobe_event+0x285f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_285f;
	}
x86_l_24bd:
	/* 0x24bd: sub    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 24ULL);
x86_l_24c2:
	/* 0x24c2: jne    2866 <generic_retuprobe_event+0x2866> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2866;
	}
x86_l_24c8:
	/* 0x24c8: jmp    2060 <generic_retuprobe_event+0x2060> */
	return 8288ULL;
x86_l_24cd:
	/* 0x24cd: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_24d1:
	/* 0x24d1: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_24d8:
	/* 0x24d8: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_24dc:
	/* 0x24dc: jmp    24e2 <generic_retuprobe_event+0x24e2> */
	goto x86_l_24e2;
x86_l_24de:
	/* 0x24de: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_24e2:
	/* 0x24e2: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_24e6:
	/* 0x24e6: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24ea:
	/* 0x24ea: movzx  ecx,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_24ee:
	/* 0x24ee: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_24f2:
	/* 0x24f2: ja     2852 <generic_retuprobe_event+0x2852> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2852;
	}
x86_l_24f8:
	/* 0x24f8: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2502:
	/* 0x2502: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2506:
	/* 0x2506: jae    2852 <generic_retuprobe_event+0x2852> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2852;
	}
x86_l_250c:
	/* 0x250c: mov    BYTE PTR [rbp+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_250f:
	/* 0x250f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2514:
	/* 0x2514: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2518:
	/* 0x2518: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_251b:
	/* 0x251b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_251e:
	/* 0x251e: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2523:
	/* 0x2523: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2525:
	/* 0x2525: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2528:
	/* 0x2528: js     268c <generic_retuprobe_event+0x268c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_268c;
	}
x86_l_252e:
	/* 0x252e: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2532:
	/* 0x2532: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2535:
	/* 0x2535: jg     2551 <generic_retuprobe_event+0x2551> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2551;
	}
x86_l_2537:
	/* 0x2537: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2539:
	/* 0x2539: je     256e <generic_retuprobe_event+0x256e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_256e;
	}
x86_l_253b:
	/* 0x253b: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_253e:
	/* 0x253e: je     256e <generic_retuprobe_event+0x256e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_256e;
	}
x86_l_2540:
	/* 0x2540: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2543:
	/* 0x2543: jne    2590 <generic_retuprobe_event+0x2590> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2590;
	}
x86_l_2545:
	/* 0x2545: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_254b:
	/* 0x254b: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_254f:
	/* 0x254f: jmp    2594 <generic_retuprobe_event+0x2594> */
	goto x86_l_2594;
x86_l_2551:
	/* 0x2551: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2554:
	/* 0x2554: je     257f <generic_retuprobe_event+0x257f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_257f;
	}
x86_l_2556:
	/* 0x2556: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2559:
	/* 0x2559: je     256e <generic_retuprobe_event+0x256e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_256e;
	}
x86_l_255b:
	/* 0x255b: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2560:
	/* 0x2560: jne    2590 <generic_retuprobe_event+0x2590> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2590;
	}
x86_l_2562:
	/* 0x2562: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2568:
	/* 0x2568: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_256c:
	/* 0x256c: jmp    2594 <generic_retuprobe_event+0x2594> */
	goto x86_l_2594;
x86_l_256e:
	/* 0x256e: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2572:
	/* 0x2572: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2579:
	/* 0x2579: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_257d:
	/* 0x257d: jmp    2594 <generic_retuprobe_event+0x2594> */
	goto x86_l_2594;
x86_l_257f:
	/* 0x257f: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2583:
	/* 0x2583: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_258a:
	/* 0x258a: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_258e:
	/* 0x258e: jmp    2594 <generic_retuprobe_event+0x2594> */
	goto x86_l_2594;
x86_l_2590:
	/* 0x2590: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2594:
	/* 0x2594: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2598:
	/* 0x2598: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_259c:
	/* 0x259c: movzx  ecx,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_25a0:
	/* 0x25a0: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_25a4:
	/* 0x25a4: ja     2852 <generic_retuprobe_event+0x2852> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2852;
	}
x86_l_25aa:
	/* 0x25aa: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_25b4:
	/* 0x25b4: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_25b8:
	/* 0x25b8: jae    2852 <generic_retuprobe_event+0x2852> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2852;
	}
x86_l_25be:
	/* 0x25be: mov    BYTE PTR [rbp+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_25c1:
	/* 0x25c1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25c6:
	/* 0x25c6: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_25ca:
	/* 0x25ca: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_25cd:
	/* 0x25cd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_25d0:
	/* 0x25d0: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_25d5:
	/* 0x25d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25d7:
	/* 0x25d7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25da:
	/* 0x25da: js     268c <generic_retuprobe_event+0x268c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_268c;
	}
x86_l_25e0:
	/* 0x25e0: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_25e4:
	/* 0x25e4: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_25e7:
	/* 0x25e7: jg     2603 <generic_retuprobe_event+0x2603> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2603;
	}
x86_l_25e9:
	/* 0x25e9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25eb:
	/* 0x25eb: je     2620 <generic_retuprobe_event+0x2620> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2620;
	}
x86_l_25ed:
	/* 0x25ed: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_25f0:
	/* 0x25f0: je     2620 <generic_retuprobe_event+0x2620> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2620;
	}
x86_l_25f2:
	/* 0x25f2: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_25f5:
	/* 0x25f5: jne    2642 <generic_retuprobe_event+0x2642> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2642;
	}
x86_l_25f7:
	/* 0x25f7: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_25fd:
	/* 0x25fd: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2601:
	/* 0x2601: jmp    2646 <generic_retuprobe_event+0x2646> */
	goto x86_l_2646;
x86_l_2603:
	/* 0x2603: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2606:
	/* 0x2606: je     2631 <generic_retuprobe_event+0x2631> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2631;
	}
x86_l_2608:
	/* 0x2608: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_260b:
	/* 0x260b: je     2620 <generic_retuprobe_event+0x2620> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2620;
	}
x86_l_260d:
	/* 0x260d: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2612:
	/* 0x2612: jne    2642 <generic_retuprobe_event+0x2642> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2642;
	}
x86_l_2614:
	/* 0x2614: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_261a:
	/* 0x261a: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_261e:
	/* 0x261e: jmp    2646 <generic_retuprobe_event+0x2646> */
	goto x86_l_2646;
x86_l_2620:
	/* 0x2620: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2624:
	/* 0x2624: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_262b:
	/* 0x262b: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_262f:
	/* 0x262f: jmp    2646 <generic_retuprobe_event+0x2646> */
	goto x86_l_2646;
x86_l_2631:
	/* 0x2631: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2635:
	/* 0x2635: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_263c:
	/* 0x263c: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2640:
	/* 0x2640: jmp    2646 <generic_retuprobe_event+0x2646> */
	goto x86_l_2646;
x86_l_2642:
	/* 0x2642: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2646:
	/* 0x2646: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_264a:
	/* 0x264a: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_264e:
	/* 0x264e: movzx  ecx,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2652:
	/* 0x2652: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2656:
	/* 0x2656: ja     2852 <generic_retuprobe_event+0x2852> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2852;
	}
x86_l_265c:
	/* 0x265c: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2666:
	/* 0x2666: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_266a:
	/* 0x266a: jae    2852 <generic_retuprobe_event+0x2852> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2852;
	}
x86_l_2670:
	/* 0x2670: mov    BYTE PTR [rbp+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2673:
	/* 0x2673: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2678:
	/* 0x2678: movzx  ecx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_267c:
	/* 0x267c: add    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_267f:
	/* 0x267f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2682:
	/* 0x2682: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2687:
	/* 0x2687: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_268a:
	/* 0x268a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_268c:
	/* 0x268c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_268e:
	/* 0x268e: mov    BYTE PTR [rsp+0xb8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2695:
	/* 0x2695: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2698:
	/* 0x2698: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_269d:
	/* 0x269d: mov    WORD PTR [rbx+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_26a4:
	/* 0x26a4: mov    WORD PTR [rbx+0xc2],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655434ULL);
x86_l_26ad:
	/* 0x26ad: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26b1:
	/* 0x26b1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26b6:
	/* 0x26b6: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26bb:
	/* 0x26bb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_26c0:
	/* 0x26c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26c2:
	/* 0x26c2: lea    rdi,[rbx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_26c9:
	/* 0x26c9: add    r13,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_26cd:
	/* 0x26cd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26d2:
	/* 0x26d2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_26d7:
	/* 0x26d7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_26da:
	/* 0x26da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26dc:
	/* 0x26dc: movzx  eax,BYTE PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 184ULL);
x86_l_26e4:
	/* 0x26e4: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_26e7:
	/* 0x26e7: je     2732 <generic_retuprobe_event+0x2732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2732;
	}
x86_l_26e9:
	/* 0x26e9: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_26ec:
	/* 0x26ec: jne    2779 <generic_retuprobe_event+0x2779> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2779;
	}
x86_l_26f2:
	/* 0x26f2: mov    rbx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_26f7:
	/* 0x26f7: movzx  r12d,WORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 192ULL);
x86_l_2700:
	/* 0x2700: lea    rdx,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2704:
	/* 0x2704: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2709:
	/* 0x2709: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2710:
	/* 0x2710: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2715:
	/* 0x2715: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_271a:
	/* 0x271a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_271c:
	/* 0x271c: lea    rdi,[r13+0xbe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 190ULL);
x86_l_2723:
	/* 0x2723: lea    rdx,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2727:
	/* 0x2727: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_272b:
	/* 0x272b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2730:
	/* 0x2730: jmp    2770 <generic_retuprobe_event+0x2770> */
	goto x86_l_2770;
x86_l_2732:
	/* 0x2732: mov    rbx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2737:
	/* 0x2737: movzx  r12d,WORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 192ULL);
x86_l_2740:
	/* 0x2740: lea    rdx,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2744:
	/* 0x2744: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2749:
	/* 0x2749: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2750:
	/* 0x2750: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2755:
	/* 0x2755: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_275a:
	/* 0x275a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_275c:
	/* 0x275c: lea    rdi,[r13+0xbe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 190ULL);
x86_l_2763:
	/* 0x2763: lea    rdx,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2767:
	/* 0x2767: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_276b:
	/* 0x276b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2770:
	/* 0x2770: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2775:
	/* 0x2775: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2777:
	/* 0x2777: jmp    2788 <generic_retuprobe_event+0x2788> */
	goto x86_l_2788;
x86_l_2779:
	/* 0x2779: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_277e:
	/* 0x277e: mov    DWORD PTR [rax+0xbc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_2788:
	/* 0x2788: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_278d:
	/* 0x278d: movzx  ecx,WORD PTR [rax+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_2794:
	/* 0x2794: movzx  edx,WORD PTR [rax+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_279b:
	/* 0x279b: movbe  WORD PTR [rax+0xbc],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_27a4:
	/* 0x27a4: movbe  WORD PTR [rax+0xbe],dx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_27ad:
	/* 0x27ad: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_27b5:
	/* 0x27b5: add    rdx,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_27bc:
	/* 0x27bc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27c1:
	/* 0x27c1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27c6:
	/* 0x27c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27cb:
	/* 0x27cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27cd:
	/* 0x27cd: cmp    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_27d3:
	/* 0x27d3: je     2839 <generic_retuprobe_event+0x2839> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2839;
	}
x86_l_27d5:
	/* 0x27d5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27da:
	/* 0x27da: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27df:
	/* 0x27df: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_27e3:
	/* 0x27e3: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_27eb:
	/* 0x27eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27f0:
	/* 0x27f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27f2:
	/* 0x27f2: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27f7:
	/* 0x27f7: mov    r12,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_27ff:
	/* 0x27ff: lea    rdx,[rbx+r12*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_2803:
	/* 0x2803: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2808:
	/* 0x2808: lea    rdi,[r13+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_280f:
	/* 0x280f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2814:
	/* 0x2814: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2819:
	/* 0x2819: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_281b:
	/* 0x281b: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_281e:
	/* 0x281e: add    rdi,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_2825:
	/* 0x2825: lea    rdx,[rbx+r12*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_2829:
	/* 0x2829: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_282d:
	/* 0x282d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2832:
	/* 0x2832: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2837:
	/* 0x2837: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2839:
	/* 0x2839: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_283e:
	/* 0x283e: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2843:
	/* 0x2843: mov    ebp,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_2848:
	/* 0x2848: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_284d:
	/* 0x284d: jmp    a1c <generic_retuprobe_event+0xa1c> */
	return 2588ULL;
x86_l_2852:
	/* 0x2852: mov    WORD PTR [rsp+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_285a:
	/* 0x285a: jmp    268e <generic_retuprobe_event+0x268e> */
	goto x86_l_268e;
x86_l_285f:
	/* 0x285f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2861:
	/* 0x2861: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2866:
	/* 0x2866: cmp    QWORD PTR [rsp+0x80],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813893ULL);
x86_l_286f:
	/* 0x286f: je     2060 <generic_retuprobe_event+0x2060> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8288ULL;
	}
x86_l_2875:
	/* 0x2875: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_287d:
	/* 0x287d: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2881:
	/* 0x2881: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_2886:
	/* 0x2886: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_288b:
	/* 0x288b: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2890:
	/* 0x2890: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2895:
	/* 0x2895: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2897:
	/* 0x2897: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_289c:
	/* 0x289c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_289e:
	/* 0x289e: js     29c7 <generic_retuprobe_event+0x29c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29c7;
	}
x86_l_28a4:
	/* 0x28a4: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_28a9:
	/* 0x28a9: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28ae:
	/* 0x28ae: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_28b1:
	/* 0x28b1: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_28b4:
	/* 0x28b4: cmovb  rbx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_28b8:
	/* 0x28b8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28bb:
	/* 0x28bb: cmovne rdx,rbx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RBX, X86_WIDTH_64, X86_CC_NE);
x86_l_28bf:
	/* 0x28bf: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_28c4:
	/* 0x28c4: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28c9:
	/* 0x28c9: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_28d0:
	/* 0x28d0: ja     29c7 <generic_retuprobe_event+0x29c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29c7;
	}
x86_l_28d6:
	/* 0x28d6: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28db:
	/* 0x28db: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28de:
	/* 0x28de: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28e3:
	/* 0x28e3: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_28e9:
	/* 0x28e9: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28ec:
	/* 0x28ec: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28f1:
	/* 0x28f1: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_28f6:
	/* 0x28f6: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28fb:
	/* 0x28fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28fd:
	/* 0x28fd: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2902:
	/* 0x2902: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2904:
	/* 0x2904: js     29c7 <generic_retuprobe_event+0x29c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29c7;
	}
x86_l_290a:
	/* 0x290a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_290f:
	/* 0x290f: add    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_2914:
	/* 0x2914: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_291a:
	/* 0x291a: je     2928 <generic_retuprobe_event+0x2928> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2928;
	}
x86_l_291c:
	/* 0x291c: sub    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 24ULL);
x86_l_2921:
	/* 0x2921: jne    292f <generic_retuprobe_event+0x292f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_292f;
	}
x86_l_2923:
	/* 0x2923: jmp    2060 <generic_retuprobe_event+0x2060> */
	return 8288ULL;
x86_l_2928:
	/* 0x2928: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_292a:
	/* 0x292a: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_292f:
	/* 0x292f: cmp    QWORD PTR [rsp+0x80],0x7 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813895ULL);
x86_l_2938:
	/* 0x2938: jb     2060 <generic_retuprobe_event+0x2060> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8288ULL;
	}
x86_l_293e:
	/* 0x293e: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2946:
	/* 0x2946: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_294a:
	/* 0x294a: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_294f:
	/* 0x294f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2954:
	/* 0x2954: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2959:
	/* 0x2959: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_295e:
	/* 0x295e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2960:
	/* 0x2960: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2965:
	/* 0x2965: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2967:
	/* 0x2967: js     29c7 <generic_retuprobe_event+0x29c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29c7;
	}
x86_l_2969:
	/* 0x2969: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_296e:
	/* 0x296e: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2973:
	/* 0x2973: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_2976:
	/* 0x2976: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_2979:
	/* 0x2979: cmovb  r13,rax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_64, X86_CC_B);
x86_l_297d:
	/* 0x297d: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2980:
	/* 0x2980: cmove  r13,rax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_64, X86_CC_E);
x86_l_2984:
	/* 0x2984: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2989:
	/* 0x2989: cmp    r13,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4094ULL);
x86_l_2990:
	/* 0x2990: ja     29c7 <generic_retuprobe_event+0x29c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29c7;
	}
x86_l_2992:
	/* 0x2992: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2997:
	/* 0x2997: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_299c:
	/* 0x299c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_29a2:
	/* 0x29a2: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29a5:
	/* 0x29a5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29aa:
	/* 0x29aa: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_29af:
	/* 0x29af: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_29b2:
	/* 0x29b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29b4:
	/* 0x29b4: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_29b9:
	/* 0x29b9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29bb:
	/* 0x29bb: js     29c7 <generic_retuprobe_event+0x29c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29c7;
	}
x86_l_29bd:
	/* 0x29bd: add    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_29c2:
	/* 0x29c2: jmp    2c9 <generic_retuprobe_event+0x2c9> */
	return 713ULL;
x86_l_29c7:
	/* 0x29c7: mov    DWORD PTR [r15+r12*1],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_29cb:
	/* 0x29cb: add    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29ce:
	/* 0x29ce: mov    rbx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RBP, X86_WIDTH_64);
x86_l_29d1:
	/* 0x29d1: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_29d6:
	/* 0x29d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29d8:
	/* 0x29d8: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_29db:
	/* 0x29db: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_29e0:
	/* 0x29e0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29e5:
	/* 0x29e5: lea    rdx,[r12+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_29ed:
	/* 0x29ed: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
	return 10741ULL;
}

static __noinline __u64 tetragon_bpf_multi_retuprobe_v61_generic_retuprobe_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10741ULL: goto x86_l_29f5;
	case 10746ULL: goto x86_l_29fa;
	case 10748ULL: goto x86_l_29fc;
	case 10755ULL: goto x86_l_2a03;
	case 10759ULL: goto x86_l_2a07;
	case 10764ULL: goto x86_l_2a0c;
	case 10771ULL: goto x86_l_2a13;
	case 10776ULL: goto x86_l_2a18;
	case 10778ULL: goto x86_l_2a1a;
	case 10781ULL: goto x86_l_2a1d;
	case 10783ULL: goto x86_l_2a1f;
	case 10786ULL: goto x86_l_2a22;
	case 10791ULL: goto x86_l_2a27;
	case 10797ULL: goto x86_l_2a2d;
	case 10802ULL: goto x86_l_2a32;
	case 10809ULL: goto x86_l_2a39;
	case 10814ULL: goto x86_l_2a3e;
	case 10819ULL: goto x86_l_2a43;
	case 10822ULL: goto x86_l_2a46;
	case 10824ULL: goto x86_l_2a48;
	case 10830ULL: goto x86_l_2a4e;
	case 10836ULL: goto x86_l_2a54;
	case 10841ULL: goto x86_l_2a59;
	case 10846ULL: goto x86_l_2a5e;
	case 10851ULL: goto x86_l_2a63;
	case 10859ULL: goto x86_l_2a6b;
	case 10864ULL: goto x86_l_2a70;
	case 10866ULL: goto x86_l_2a72;
	case 10873ULL: goto x86_l_2a79;
	case 10877ULL: goto x86_l_2a7d;
	case 10882ULL: goto x86_l_2a82;
	case 10889ULL: goto x86_l_2a89;
	case 10894ULL: goto x86_l_2a8e;
	case 10896ULL: goto x86_l_2a90;
	case 10899ULL: goto x86_l_2a93;
	case 10901ULL: goto x86_l_2a95;
	case 10904ULL: goto x86_l_2a98;
	case 10909ULL: goto x86_l_2a9d;
	case 10915ULL: goto x86_l_2aa3;
	case 10920ULL: goto x86_l_2aa8;
	case 10925ULL: goto x86_l_2aad;
	case 10930ULL: goto x86_l_2ab2;
	case 10935ULL: goto x86_l_2ab7;
	case 10940ULL: goto x86_l_2abc;
	case 10942ULL: goto x86_l_2abe;
	case 10948ULL: goto x86_l_2ac4;
	case 10954ULL: goto x86_l_2aca;
	case 10959ULL: goto x86_l_2acf;
	case 10964ULL: goto x86_l_2ad4;
	case 10969ULL: goto x86_l_2ad9;
	case 10977ULL: goto x86_l_2ae1;
	case 10982ULL: goto x86_l_2ae6;
	case 10984ULL: goto x86_l_2ae8;
	case 10991ULL: goto x86_l_2aef;
	case 10995ULL: goto x86_l_2af3;
	case 11000ULL: goto x86_l_2af8;
	case 11007ULL: goto x86_l_2aff;
	case 11012ULL: goto x86_l_2b04;
	case 11014ULL: goto x86_l_2b06;
	case 11017ULL: goto x86_l_2b09;
	case 11019ULL: goto x86_l_2b0b;
	case 11022ULL: goto x86_l_2b0e;
	case 11027ULL: goto x86_l_2b13;
	case 11033ULL: goto x86_l_2b19;
	case 11038ULL: goto x86_l_2b1e;
	case 11043ULL: goto x86_l_2b23;
	case 11048ULL: goto x86_l_2b28;
	case 11053ULL: goto x86_l_2b2d;
	case 11058ULL: goto x86_l_2b32;
	case 11060ULL: goto x86_l_2b34;
	case 11066ULL: goto x86_l_2b3a;
	case 11068ULL: goto x86_l_2b3c;
	case 11073ULL: goto x86_l_2b41;
	case 11078ULL: goto x86_l_2b46;
	case 11083ULL: goto x86_l_2b4b;
	case 11091ULL: goto x86_l_2b53;
	case 11096ULL: goto x86_l_2b58;
	case 11098ULL: goto x86_l_2b5a;
	case 11105ULL: goto x86_l_2b61;
	case 11109ULL: goto x86_l_2b65;
	case 11114ULL: goto x86_l_2b6a;
	case 11121ULL: goto x86_l_2b71;
	case 11126ULL: goto x86_l_2b76;
	case 11128ULL: goto x86_l_2b78;
	case 11131ULL: goto x86_l_2b7b;
	case 11133ULL: goto x86_l_2b7d;
	case 11136ULL: goto x86_l_2b80;
	case 11141ULL: goto x86_l_2b85;
	case 11143ULL: goto x86_l_2b87;
	case 11148ULL: goto x86_l_2b8c;
	case 11153ULL: goto x86_l_2b91;
	case 11158ULL: goto x86_l_2b96;
	case 11163ULL: goto x86_l_2b9b;
	case 11168ULL: goto x86_l_2ba0;
	case 11170ULL: goto x86_l_2ba2;
	case 11173ULL: goto x86_l_2ba5;
	case 11180ULL: goto x86_l_2bac;
	case 11184ULL: goto x86_l_2bb0;
	case 11189ULL: goto x86_l_2bb5;
	case 11191ULL: goto x86_l_2bb7;
	case 11195ULL: goto x86_l_2bbb;
	case 11198ULL: goto x86_l_2bbe;
	case 11200ULL: goto x86_l_2bc0;
	case 11203ULL: goto x86_l_2bc3;
	case 11207ULL: goto x86_l_2bc7;
	case 11211ULL: goto x86_l_2bcb;
	case 11215ULL: goto x86_l_2bcf;
	case 11223ULL: goto x86_l_2bd7;
	case 11231ULL: goto x86_l_2bdf;
	case 11233ULL: goto x86_l_2be1;
	case 11237ULL: goto x86_l_2be5;
	case 11241ULL: goto x86_l_2be9;
	case 11246ULL: goto x86_l_2bee;
	case 11253ULL: goto x86_l_2bf5;
	case 11261ULL: goto x86_l_2bfd;
	case 11266ULL: goto x86_l_2c02;
	case 11268ULL: goto x86_l_2c04;
	case 11273ULL: goto x86_l_2c09;
	case 11275ULL: goto x86_l_2c0b;
	case 11282ULL: goto x86_l_2c12;
	case 11284ULL: goto x86_l_2c14;
	case 11285ULL: goto x86_l_2c15;
	case 11290ULL: goto x86_l_2c1a;
	case 11292ULL: goto x86_l_2c1c;
	case 11294ULL: goto x86_l_2c1e;
	case 11296ULL: goto x86_l_2c20;
	case 11297ULL: goto x86_l_2c21;
	case 11301ULL: goto x86_l_2c25;
	case 11304ULL: goto x86_l_2c28;
	case 11308ULL: goto x86_l_2c2c;
	case 11312ULL: goto x86_l_2c30;
	case 11316ULL: goto x86_l_2c34;
	case 11319ULL: goto x86_l_2c37;
	case 11321ULL: goto x86_l_2c39;
	case 11325ULL: goto x86_l_2c3d;
	case 11331ULL: goto x86_l_2c43;
	case 11336ULL: goto x86_l_2c48;
	case 11341ULL: goto x86_l_2c4d;
	case 11346ULL: goto x86_l_2c52;
	case 11348ULL: goto x86_l_2c54;
	case 11353ULL: goto x86_l_2c59;
	case 11359ULL: goto x86_l_2c5f;
	case 11363ULL: goto x86_l_2c63;
	case 11368ULL: goto x86_l_2c68;
	case 11373ULL: goto x86_l_2c6d;
	case 11378ULL: goto x86_l_2c72;
	case 11381ULL: goto x86_l_2c75;
	case 11383ULL: goto x86_l_2c77;
	case 11388ULL: goto x86_l_2c7c;
	case 11394ULL: goto x86_l_2c82;
	case 11399ULL: goto x86_l_2c87;
	case 11404ULL: goto x86_l_2c8c;
	case 11409ULL: goto x86_l_2c91;
	case 11412ULL: goto x86_l_2c94;
	case 11414ULL: goto x86_l_2c96;
	case 11418ULL: goto x86_l_2c9a;
	case 11423ULL: goto x86_l_2c9f;
	case 11428ULL: goto x86_l_2ca4;
	case 11433ULL: goto x86_l_2ca9;
	case 11436ULL: goto x86_l_2cac;
	case 11438ULL: goto x86_l_2cae;
	case 11442ULL: goto x86_l_2cb2;
	case 11446ULL: goto x86_l_2cb6;
	case 11450ULL: goto x86_l_2cba;
	case 11453ULL: goto x86_l_2cbd;
	case 11456ULL: goto x86_l_2cc0;
	case 11458ULL: goto x86_l_2cc2;
	case 11460ULL: goto x86_l_2cc4;
	case 11462ULL: goto x86_l_2cc6;
	case 11465ULL: goto x86_l_2cc9;
	case 11470ULL: goto x86_l_2cce;
	case 11473ULL: goto x86_l_2cd1;
	case 11475ULL: goto x86_l_2cd3;
	case 11479ULL: goto x86_l_2cd7;
	case 11482ULL: goto x86_l_2cda;
	case 11486ULL: goto x86_l_2cde;
	case 11489ULL: goto x86_l_2ce1;
	case 11491ULL: goto x86_l_2ce3;
	case 11494ULL: goto x86_l_2ce6;
	case 11497ULL: goto x86_l_2ce9;
	case 11502ULL: goto x86_l_2cee;
	case 11505ULL: goto x86_l_2cf1;
	case 11511ULL: goto x86_l_2cf7;
	case 11518ULL: goto x86_l_2cfe;
	case 11524ULL: goto x86_l_2d04;
	case 11526ULL: goto x86_l_2d06;
	case 11532ULL: goto x86_l_2d0c;
	case 11536ULL: goto x86_l_2d10;
	case 11541ULL: goto x86_l_2d15;
	case 11545ULL: goto x86_l_2d19;
	case 11549ULL: goto x86_l_2d1d;
	case 11552ULL: goto x86_l_2d20;
	case 11557ULL: goto x86_l_2d25;
	case 11559ULL: goto x86_l_2d27;
	case 11563ULL: goto x86_l_2d2b;
	case 11568ULL: goto x86_l_2d30;
	case 11572ULL: goto x86_l_2d34;
	case 11574ULL: goto x86_l_2d36;
	case 11576ULL: goto x86_l_2d38;
	case 11580ULL: goto x86_l_2d3c;
	case 11585ULL: goto x86_l_2d41;
	case 11590ULL: goto x86_l_2d46;
	case 11595ULL: goto x86_l_2d4b;
	case 11597ULL: goto x86_l_2d4d;
	case 11601ULL: goto x86_l_2d51;
	case 11606ULL: goto x86_l_2d56;
	case 11608ULL: goto x86_l_2d58;
	case 11612ULL: goto x86_l_2d5c;
	case 11616ULL: goto x86_l_2d60;
	case 11621ULL: goto x86_l_2d65;
	case 11626ULL: goto x86_l_2d6a;
	case 11629ULL: goto x86_l_2d6d;
	case 11631ULL: goto x86_l_2d6f;
	case 11636ULL: goto x86_l_2d74;
	case 11640ULL: goto x86_l_2d78;
	case 11644ULL: goto x86_l_2d7c;
	case 11648ULL: goto x86_l_2d80;
	case 11650ULL: goto x86_l_2d82;
	case 11652ULL: goto x86_l_2d84;
	case 11656ULL: goto x86_l_2d88;
	case 11661ULL: goto x86_l_2d8d;
	case 11665ULL: goto x86_l_2d91;
	case 11666ULL: goto x86_l_2d92;
	case 11668ULL: goto x86_l_2d94;
	case 11670ULL: goto x86_l_2d96;
	case 11672ULL: goto x86_l_2d98;
	case 11673ULL: goto x86_l_2d99;
	case 11677ULL: goto x86_l_2d9d;
	case 11680ULL: goto x86_l_2da0;
	case 11685ULL: goto x86_l_2da5;
	case 11688ULL: goto x86_l_2da8;
	case 11690ULL: goto x86_l_2daa;
	case 11695ULL: goto x86_l_2daf;
	case 11699ULL: goto x86_l_2db3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_29f5:
	/* 0x29f5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_29fa:
	/* 0x29fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29fc:
	/* 0x29fc: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2a03:
	/* 0x2a03: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a07:
	/* 0x2a07: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a0c:
	/* 0x2a0c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2a13:
	/* 0x2a13: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a18:
	/* 0x2a18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a1a:
	/* 0x2a1a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a1d:
	/* 0x2a1d: je     2a2d <generic_retuprobe_event+0x2a2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a2d;
	}
x86_l_2a1f:
	/* 0x2a1f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2a22:
	/* 0x2a22: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2a27:
	/* 0x2a27: jne    2ba5 <generic_retuprobe_event+0x2ba5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ba5;
	}
x86_l_2a2d:
	/* 0x2a2d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a32:
	/* 0x2a32: add    r12,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_2a39:
	/* 0x2a39: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2a3e:
	/* 0x2a3e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a43:
	/* 0x2a43: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2a46:
	/* 0x2a46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a48:
	/* 0x2a48: cmp    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2a4e:
	/* 0x2a4e: je     2ba2 <generic_retuprobe_event+0x2ba2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ba2;
	}
x86_l_2a54:
	/* 0x2a54: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a59:
	/* 0x2a59: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2a5e:
	/* 0x2a5e: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2a63:
	/* 0x2a63: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2a6b:
	/* 0x2a6b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a70:
	/* 0x2a70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a72:
	/* 0x2a72: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2a79:
	/* 0x2a79: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a7d:
	/* 0x2a7d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a82:
	/* 0x2a82: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2a89:
	/* 0x2a89: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a8e:
	/* 0x2a8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a90:
	/* 0x2a90: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a93:
	/* 0x2a93: je     2aa3 <generic_retuprobe_event+0x2aa3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aa3;
	}
x86_l_2a95:
	/* 0x2a95: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2a98:
	/* 0x2a98: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2a9d:
	/* 0x2a9d: jne    2ba5 <generic_retuprobe_event+0x2ba5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ba5;
	}
x86_l_2aa3:
	/* 0x2aa3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2aa8:
	/* 0x2aa8: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2aad:
	/* 0x2aad: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2ab2:
	/* 0x2ab2: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ab7:
	/* 0x2ab7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2abc:
	/* 0x2abc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2abe:
	/* 0x2abe: cmp    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2ac4:
	/* 0x2ac4: je     2ba2 <generic_retuprobe_event+0x2ba2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ba2;
	}
x86_l_2aca:
	/* 0x2aca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2acf:
	/* 0x2acf: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2ad4:
	/* 0x2ad4: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2ad9:
	/* 0x2ad9: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2ae1:
	/* 0x2ae1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ae6:
	/* 0x2ae6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae8:
	/* 0x2ae8: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2aef:
	/* 0x2aef: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2af3:
	/* 0x2af3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2af8:
	/* 0x2af8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2aff:
	/* 0x2aff: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b04:
	/* 0x2b04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b06:
	/* 0x2b06: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b09:
	/* 0x2b09: je     2b19 <generic_retuprobe_event+0x2b19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b19;
	}
x86_l_2b0b:
	/* 0x2b0b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2b0e:
	/* 0x2b0e: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2b13:
	/* 0x2b13: jne    2ba5 <generic_retuprobe_event+0x2ba5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ba5;
	}
x86_l_2b19:
	/* 0x2b19: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b1e:
	/* 0x2b1e: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2b23:
	/* 0x2b23: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2b28:
	/* 0x2b28: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b2d:
	/* 0x2b2d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b32:
	/* 0x2b32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b34:
	/* 0x2b34: cmp    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2b3a:
	/* 0x2b3a: je     2ba2 <generic_retuprobe_event+0x2ba2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ba2;
	}
x86_l_2b3c:
	/* 0x2b3c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b41:
	/* 0x2b41: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2b46:
	/* 0x2b46: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2b4b:
	/* 0x2b4b: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2b53:
	/* 0x2b53: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b58:
	/* 0x2b58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b5a:
	/* 0x2b5a: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2b61:
	/* 0x2b61: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b65:
	/* 0x2b65: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b6a:
	/* 0x2b6a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2b71:
	/* 0x2b71: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b76:
	/* 0x2b76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b78:
	/* 0x2b78: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b7b:
	/* 0x2b7b: je     2b87 <generic_retuprobe_event+0x2b87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b87;
	}
x86_l_2b7d:
	/* 0x2b7d: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2b80:
	/* 0x2b80: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2b85:
	/* 0x2b85: jne    2ba5 <generic_retuprobe_event+0x2ba5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ba5;
	}
x86_l_2b87:
	/* 0x2b87: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b8c:
	/* 0x2b8c: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2b91:
	/* 0x2b91: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2b96:
	/* 0x2b96: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b9b:
	/* 0x2b9b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ba0:
	/* 0x2ba0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ba2:
	/* 0x2ba2: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ba5:
	/* 0x2ba5: mov    DWORD PTR [r14],0x10f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 271ULL);
x86_l_2bac:
	/* 0x2bac: mov    DWORD PTR [r14+0x4],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2bb0:
	/* 0x2bb0: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_2bb5:
	/* 0x2bb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bb7:
	/* 0x2bb7: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bbb:
	/* 0x2bbb: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_2bbe:
	/* 0x2bbe: je     2bcf <generic_retuprobe_event+0x2bcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bcf;
	}
x86_l_2bc0:
	/* 0x2bc0: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bc3:
	/* 0x2bc3: mov    DWORD PTR [r14+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bc7:
	/* 0x2bc7: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bcb:
	/* 0x2bcb: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2bcf:
	/* 0x2bcf: mov    DWORD PTR [r14+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2bd7:
	/* 0x2bd7: mov    rax,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2bdf:
	/* 0x2bdf: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2be1:
	/* 0x2be1: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2be5:
	/* 0x2be5: mov    DWORD PTR [r14+0x4],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2be9:
	/* 0x2be9: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2bee:
	/* 0x2bee: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retuprobe_calls)));
x86_l_2bf5:
	/* 0x2bf5: mov    rdi,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2bfd:
	/* 0x2bfd: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2c02:
	/* 0x2c02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c04:
	/* 0x2c04: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2c09:
	/* 0x2c09: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_2c0b:
	/* 0x2c0b: add    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_2c12:
	/* 0x2c12: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2c14:
	/* 0x2c14: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2c15:
	/* 0x2c15: jmp    2db5 <cwd_read_v61+0x19b> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2c1a:
	/* 0x2c1a: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_2c1c:
	/* 0x2c1c: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2c1e:
	/* 0x2c1e: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2c20:
	/* 0x2c20: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2c21:
	/* 0x2c21: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_2c25:
	/* 0x2c25: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_2c28:
	/* 0x2c28: mov    r15,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c2c:
	/* 0x2c2c: mov    rdx,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c30:
	/* 0x2c30: mov    r14,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c34:
	/* 0x2c34: cmp    r15,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2c37:
	/* 0x2c37: jne    2c43 <cwd_read_v61+0x29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c43;
	}
x86_l_2c39:
	/* 0x2c39: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2c3d:
	/* 0x2c3d: je     2d84 <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d84;
	}
x86_l_2c43:
	/* 0x2c43: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c48:
	/* 0x2c48: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c4d:
	/* 0x2c4d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c52:
	/* 0x2c52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c54:
	/* 0x2c54: cmp    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2c59:
	/* 0x2c59: je     2d38 <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d38;
	}
x86_l_2c5f:
	/* 0x2c5f: lea    r12,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c63:
	/* 0x2c63: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c68:
	/* 0x2c68: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c6d:
	/* 0x2c6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c72:
	/* 0x2c72: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2c75:
	/* 0x2c75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c77:
	/* 0x2c77: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c7c:
	/* 0x2c7c: je     2d38 <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d38;
	}
x86_l_2c82:
	/* 0x2c82: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c87:
	/* 0x2c87: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c8c:
	/* 0x2c8c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c91:
	/* 0x2c91: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2c94:
	/* 0x2c94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c96:
	/* 0x2c96: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2c9a:
	/* 0x2c9a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c9f:
	/* 0x2c9f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ca4:
	/* 0x2ca4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2ca9:
	/* 0x2ca9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2cac:
	/* 0x2cac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cae:
	/* 0x2cae: mov    r14,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cb2:
	/* 0x2cb2: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2cb6:
	/* 0x2cb6: mov    esi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2cba:
	/* 0x2cba: sub    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2cbd:
	/* 0x2cbd: mov    edi,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2cc0:
	/* 0x2cc0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cc2:
	/* 0x2cc2: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2cc4:
	/* 0x2cc4: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2cc6:
	/* 0x2cc6: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2cc9:
	/* 0x2cc9: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2cce:
	/* 0x2cce: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cd1:
	/* 0x2cd1: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2cd3:
	/* 0x2cd3: seta   r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_A);
x86_l_2cd7:
	/* 0x2cd7: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_2cda:
	/* 0x2cda: cmovb  r8d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_2cde:
	/* 0x2cde: add    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2ce1:
	/* 0x2ce1: mov    eax,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDI, X86_WIDTH_32);
x86_l_2ce3:
	/* 0x2ce3: sub    eax,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R9, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2ce6:
	/* 0x2ce6: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ce9:
	/* 0x2ce9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cee:
	/* 0x2cee: sub    rcx,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R9, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2cf1:
	/* 0x2cf1: jb     2d8d <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2d8d;
	}
x86_l_2cf7:
	/* 0x2cf7: cmp    rcx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4095ULL);
x86_l_2cfe:
	/* 0x2cfe: ja     2d8d <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2d8d;
	}
x86_l_2d04:
	/* 0x2d04: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2d06:
	/* 0x2d06: jbe    2d99 <cwd_read_v61+0x17f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2d99;
	}
x86_l_2d0c:
	/* 0x2d0c: lea    r15,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2d10:
	/* 0x2d10: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2d15:
	/* 0x2d15: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2d19:
	/* 0x2d19: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2d1d:
	/* 0x2d1d: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2d20:
	/* 0x2d20: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d25:
	/* 0x2d25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d27:
	/* 0x2d27: mov    QWORD PTR [rbx+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d2b:
	/* 0x2d2b: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d30:
	/* 0x2d30: mov    QWORD PTR [rbx+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d34:
	/* 0x2d34: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d36:
	/* 0x2d36: jmp    2d8d <cwd_read_v61+0x173> */
	goto x86_l_2d8d;
x86_l_2d38:
	/* 0x2d38: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d3c:
	/* 0x2d3c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d41:
	/* 0x2d41: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d46:
	/* 0x2d46: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d4b:
	/* 0x2d4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d4d:
	/* 0x2d4d: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d51:
	/* 0x2d51: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2d56:
	/* 0x2d56: je     2d84 <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d84;
	}
x86_l_2d58:
	/* 0x2d58: lea    rdi,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d5c:
	/* 0x2d5c: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2d60:
	/* 0x2d60: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d65:
	/* 0x2d65: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d6a:
	/* 0x2d6a: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2d6d:
	/* 0x2d6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d6f:
	/* 0x2d6f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d74:
	/* 0x2d74: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d78:
	/* 0x2d78: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2d7c:
	/* 0x2d7c: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d80:
	/* 0x2d80: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d82:
	/* 0x2d82: jmp    2d8d <cwd_read_v61+0x173> */
	goto x86_l_2d8d;
x86_l_2d84:
	/* 0x2d84: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_2d88:
	/* 0x2d88: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d8d:
	/* 0x2d8d: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_2d91:
	/* 0x2d91: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2d92:
	/* 0x2d92: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2d94:
	/* 0x2d94: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2d96:
	/* 0x2d96: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2d98:
	/* 0x2d98: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2d99:
	/* 0x2d99: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2d9d:
	/* 0x2d9d: add    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2da0:
	/* 0x2da0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2da5:
	/* 0x2da5: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2da8:
	/* 0x2da8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2daa:
	/* 0x2daa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2daf:
	/* 0x2daf: mov    QWORD PTR [rbx+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2db3:
	/* 0x2db3: jmp    2d8d <cwd_read_v61+0x173> */
	goto x86_l_2d8d;
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
	for (__u32 __x86_iter = 0; __x86_iter < 10152U; __x86_iter++) {
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
		else if (__x86_pc >= 7426ULL && __x86_pc <= 9036ULL)
			__x86_pc = tetragon_bpf_multi_retuprobe_v61_generic_retuprobe_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9040ULL && __x86_pc <= 10733ULL)
			__x86_pc = tetragon_bpf_multi_retuprobe_v61_generic_retuprobe_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10741ULL && __x86_pc <= 11699ULL)
			__x86_pc = tetragon_bpf_multi_retuprobe_v61_generic_retuprobe_event_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

extern char CONFIG_ITER_NUM;
extern char buffer_heap_map;
extern char config_map;
extern char data_heap;
extern char fdinstall_map;
extern char lsm_calls;
extern char process_call_heap;
extern char retprobe_map;
extern char socktrack_map;
extern char tcpmon_map;
extern char tg_conf_map;
extern char tg_errmetrics_map;
extern char tg_ipv6_ext_heap;
extern char tg_rb_events;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_0(
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
	case 20ULL: goto x86_l_14;
	case 31ULL: goto x86_l_1f;
	case 38ULL: goto x86_l_26;
	case 46ULL: goto x86_l_2e;
	case 51ULL: goto x86_l_33;
	case 53ULL: goto x86_l_35;
	case 56ULL: goto x86_l_38;
	case 62ULL: goto x86_l_3e;
	case 65ULL: goto x86_l_41;
	case 72ULL: goto x86_l_48;
	case 75ULL: goto x86_l_4b;
	case 82ULL: goto x86_l_52;
	case 88ULL: goto x86_l_58;
	case 99ULL: goto x86_l_63;
	case 106ULL: goto x86_l_6a;
	case 114ULL: goto x86_l_72;
	case 119ULL: goto x86_l_77;
	case 121ULL: goto x86_l_79;
	case 124ULL: goto x86_l_7c;
	case 130ULL: goto x86_l_82;
	case 133ULL: goto x86_l_85;
	case 140ULL: goto x86_l_8c;
	case 147ULL: goto x86_l_93;
	case 152ULL: goto x86_l_98;
	case 154ULL: goto x86_l_9a;
	case 158ULL: goto x86_l_9e;
	case 164ULL: goto x86_l_a4;
	case 167ULL: goto x86_l_a7;
	case 173ULL: goto x86_l_ad;
	case 178ULL: goto x86_l_b2;
	case 181ULL: goto x86_l_b5;
	case 184ULL: goto x86_l_b8;
	case 186ULL: goto x86_l_ba;
	case 191ULL: goto x86_l_bf;
	case 196ULL: goto x86_l_c4;
	case 198ULL: goto x86_l_c6;
	case 210ULL: goto x86_l_d2;
	case 216ULL: goto x86_l_d8;
	case 220ULL: goto x86_l_dc;
	case 225ULL: goto x86_l_e1;
	case 230ULL: goto x86_l_e6;
	case 232ULL: goto x86_l_e8;
	case 234ULL: goto x86_l_ea;
	case 236ULL: goto x86_l_ec;
	case 240ULL: goto x86_l_f0;
	case 242ULL: goto x86_l_f2;
	case 246ULL: goto x86_l_f6;
	case 249ULL: goto x86_l_f9;
	case 257ULL: goto x86_l_101;
	case 259ULL: goto x86_l_103;
	case 271ULL: goto x86_l_10f;
	case 273ULL: goto x86_l_111;
	case 278ULL: goto x86_l_116;
	case 290ULL: goto x86_l_122;
	case 292ULL: goto x86_l_124;
	case 294ULL: goto x86_l_126;
	case 299ULL: goto x86_l_12b;
	case 302ULL: goto x86_l_12e;
	case 305ULL: goto x86_l_131;
	case 310ULL: goto x86_l_136;
	case 312ULL: goto x86_l_138;
	case 316ULL: goto x86_l_13c;
	case 319ULL: goto x86_l_13f;
	case 322ULL: goto x86_l_142;
	case 325ULL: goto x86_l_145;
	case 330ULL: goto x86_l_14a;
	case 338ULL: goto x86_l_152;
	case 341ULL: goto x86_l_155;
	case 347ULL: goto x86_l_15b;
	case 351ULL: goto x86_l_15f;
	case 354ULL: goto x86_l_162;
	case 360ULL: goto x86_l_168;
	case 366ULL: goto x86_l_16e;
	case 369ULL: goto x86_l_171;
	case 373ULL: goto x86_l_175;
	case 378ULL: goto x86_l_17a;
	case 386ULL: goto x86_l_182;
	case 391ULL: goto x86_l_187;
	case 396ULL: goto x86_l_18c;
	case 400ULL: goto x86_l_190;
	case 406ULL: goto x86_l_196;
	case 414ULL: goto x86_l_19e;
	case 421ULL: goto x86_l_1a5;
	case 424ULL: goto x86_l_1a8;
	case 426ULL: goto x86_l_1aa;
	case 429ULL: goto x86_l_1ad;
	case 434ULL: goto x86_l_1b2;
	case 436ULL: goto x86_l_1b4;
	case 441ULL: goto x86_l_1b9;
	case 446ULL: goto x86_l_1be;
	case 449ULL: goto x86_l_1c1;
	case 454ULL: goto x86_l_1c6;
	case 456ULL: goto x86_l_1c8;
	case 458ULL: goto x86_l_1ca;
	case 460ULL: goto x86_l_1cc;
	case 463ULL: goto x86_l_1cf;
	case 467ULL: goto x86_l_1d3;
	case 469ULL: goto x86_l_1d5;
	case 474ULL: goto x86_l_1da;
	case 481ULL: goto x86_l_1e1;
	case 483ULL: goto x86_l_1e3;
	case 488ULL: goto x86_l_1e8;
	case 492ULL: goto x86_l_1ec;
	case 495ULL: goto x86_l_1ef;
	case 498ULL: goto x86_l_1f2;
	case 505ULL: goto x86_l_1f9;
	case 507ULL: goto x86_l_1fb;
	case 512ULL: goto x86_l_200;
	case 514ULL: goto x86_l_202;
	case 519ULL: goto x86_l_207;
	case 521ULL: goto x86_l_209;
	case 528ULL: goto x86_l_210;
	case 530ULL: goto x86_l_212;
	case 535ULL: goto x86_l_217;
	case 540ULL: goto x86_l_21c;
	case 545ULL: goto x86_l_221;
	case 550ULL: goto x86_l_226;
	case 552ULL: goto x86_l_228;
	case 554ULL: goto x86_l_22a;
	case 556ULL: goto x86_l_22c;
	case 559ULL: goto x86_l_22f;
	case 567ULL: goto x86_l_237;
	case 570ULL: goto x86_l_23a;
	case 578ULL: goto x86_l_242;
	case 584ULL: goto x86_l_248;
	case 588ULL: goto x86_l_24c;
	case 590ULL: goto x86_l_24e;
	case 594ULL: goto x86_l_252;
	case 599ULL: goto x86_l_257;
	case 601ULL: goto x86_l_259;
	case 605ULL: goto x86_l_25d;
	case 611ULL: goto x86_l_263;
	case 615ULL: goto x86_l_267;
	case 621ULL: goto x86_l_26d;
	case 625ULL: goto x86_l_271;
	case 628ULL: goto x86_l_274;
	case 634ULL: goto x86_l_27a;
	case 638ULL: goto x86_l_27e;
	case 644ULL: goto x86_l_284;
	case 649ULL: goto x86_l_289;
	case 653ULL: goto x86_l_28d;
	case 658ULL: goto x86_l_292;
	case 660ULL: goto x86_l_294;
	case 664ULL: goto x86_l_298;
	case 670ULL: goto x86_l_29e;
	case 674ULL: goto x86_l_2a2;
	case 677ULL: goto x86_l_2a5;
	case 683ULL: goto x86_l_2ab;
	case 687ULL: goto x86_l_2af;
	case 693ULL: goto x86_l_2b5;
	case 697ULL: goto x86_l_2b9;
	case 703ULL: goto x86_l_2bf;
	case 708ULL: goto x86_l_2c4;
	case 712ULL: goto x86_l_2c8;
	case 718ULL: goto x86_l_2ce;
	case 722ULL: goto x86_l_2d2;
	case 725ULL: goto x86_l_2d5;
	case 731ULL: goto x86_l_2db;
	case 735ULL: goto x86_l_2df;
	case 738ULL: goto x86_l_2e2;
	case 744ULL: goto x86_l_2e8;
	case 749ULL: goto x86_l_2ed;
	case 753ULL: goto x86_l_2f1;
	case 759ULL: goto x86_l_2f7;
	case 763ULL: goto x86_l_2fb;
	case 769ULL: goto x86_l_301;
	case 773ULL: goto x86_l_305;
	case 779ULL: goto x86_l_30b;
	case 783ULL: goto x86_l_30f;
	case 789ULL: goto x86_l_315;
	case 794ULL: goto x86_l_31a;
	case 798ULL: goto x86_l_31e;
	case 804ULL: goto x86_l_324;
	case 808ULL: goto x86_l_328;
	case 814ULL: goto x86_l_32e;
	case 818ULL: goto x86_l_332;
	case 824ULL: goto x86_l_338;
	case 828ULL: goto x86_l_33c;
	case 834ULL: goto x86_l_342;
	case 840ULL: goto x86_l_348;
	case 845ULL: goto x86_l_34d;
	case 849ULL: goto x86_l_351;
	case 855ULL: goto x86_l_357;
	case 859ULL: goto x86_l_35b;
	case 865ULL: goto x86_l_361;
	case 869ULL: goto x86_l_365;
	case 871ULL: goto x86_l_367;
	case 875ULL: goto x86_l_36b;
	case 881ULL: goto x86_l_371;
	case 886ULL: goto x86_l_376;
	case 890ULL: goto x86_l_37a;
	case 892ULL: goto x86_l_37c;
	case 897ULL: goto x86_l_381;
	case 901ULL: goto x86_l_385;
	case 907ULL: goto x86_l_38b;
	case 911ULL: goto x86_l_38f;
	case 913ULL: goto x86_l_391;
	case 915ULL: goto x86_l_393;
	case 919ULL: goto x86_l_397;
	case 922ULL: goto x86_l_39a;
	case 924ULL: goto x86_l_39c;
	case 930ULL: goto x86_l_3a2;
	case 932ULL: goto x86_l_3a4;
	case 938ULL: goto x86_l_3aa;
	case 940ULL: goto x86_l_3ac;
	case 944ULL: goto x86_l_3b0;
	case 946ULL: goto x86_l_3b2;
	case 950ULL: goto x86_l_3b6;
	case 952ULL: goto x86_l_3b8;
	case 958ULL: goto x86_l_3be;
	case 960ULL: goto x86_l_3c0;
	case 964ULL: goto x86_l_3c4;
	case 966ULL: goto x86_l_3c6;
	case 970ULL: goto x86_l_3ca;
	case 972ULL: goto x86_l_3cc;
	case 974ULL: goto x86_l_3ce;
	case 980ULL: goto x86_l_3d4;
	case 982ULL: goto x86_l_3d6;
	case 986ULL: goto x86_l_3da;
	case 988ULL: goto x86_l_3dc;
	case 992ULL: goto x86_l_3e0;
	case 994ULL: goto x86_l_3e2;
	case 1000ULL: goto x86_l_3e8;
	case 1002ULL: goto x86_l_3ea;
	case 1008ULL: goto x86_l_3f0;
	case 1010ULL: goto x86_l_3f2;
	case 1016ULL: goto x86_l_3f8;
	case 1018ULL: goto x86_l_3fa;
	case 1022ULL: goto x86_l_3fe;
	case 1024ULL: goto x86_l_400;
	case 1030ULL: goto x86_l_406;
	case 1032ULL: goto x86_l_408;
	case 1035ULL: goto x86_l_40b;
	case 1040ULL: goto x86_l_410;
	case 1051ULL: goto x86_l_41b;
	case 1058ULL: goto x86_l_422;
	case 1066ULL: goto x86_l_42a;
	case 1071ULL: goto x86_l_42f;
	case 1073ULL: goto x86_l_431;
	case 1076ULL: goto x86_l_434;
	case 1082ULL: goto x86_l_43a;
	case 1087ULL: goto x86_l_43f;
	case 1090ULL: goto x86_l_442;
	case 1093ULL: goto x86_l_445;
	case 1099ULL: goto x86_l_44b;
	case 1103ULL: goto x86_l_44f;
	case 1110ULL: goto x86_l_456;
	case 1117ULL: goto x86_l_45d;
	case 1121ULL: goto x86_l_461;
	case 1129ULL: goto x86_l_469;
	case 1134ULL: goto x86_l_46e;
	case 1136ULL: goto x86_l_470;
	case 1142ULL: goto x86_l_476;
	case 1145ULL: goto x86_l_479;
	case 1152ULL: goto x86_l_480;
	case 1159ULL: goto x86_l_487;
	case 1162ULL: goto x86_l_48a;
	case 1167ULL: goto x86_l_48f;
	case 1172ULL: goto x86_l_494;
	case 1184ULL: goto x86_l_4a0;
	case 1188ULL: goto x86_l_4a4;
	case 1193ULL: goto x86_l_4a9;
	case 1198ULL: goto x86_l_4ae;
	case 1203ULL: goto x86_l_4b3;
	case 1205ULL: goto x86_l_4b5;
	case 1209ULL: goto x86_l_4b9;
	case 1211ULL: goto x86_l_4bb;
	case 1215ULL: goto x86_l_4bf;
	case 1221ULL: goto x86_l_4c5;
	case 1225ULL: goto x86_l_4c9;
	case 1231ULL: goto x86_l_4cf;
	case 1243ULL: goto x86_l_4db;
	case 1251ULL: goto x86_l_4e3;
	case 1259ULL: goto x86_l_4eb;
	case 1264ULL: goto x86_l_4f0;
	case 1268ULL: goto x86_l_4f4;
	case 1274ULL: goto x86_l_4fa;
	case 1278ULL: goto x86_l_4fe;
	case 1284ULL: goto x86_l_504;
	case 1289ULL: goto x86_l_509;
	case 1291ULL: goto x86_l_50b;
	case 1296ULL: goto x86_l_510;
	case 1301ULL: goto x86_l_515;
	case 1306ULL: goto x86_l_51a;
	case 1311ULL: goto x86_l_51f;
	case 1314ULL: goto x86_l_522;
	case 1319ULL: goto x86_l_527;
	case 1321ULL: goto x86_l_529;
	case 1326ULL: goto x86_l_52e;
	case 1331ULL: goto x86_l_533;
	case 1336ULL: goto x86_l_538;
	case 1341ULL: goto x86_l_53d;
	case 1346ULL: goto x86_l_542;
	case 1351ULL: goto x86_l_547;
	case 1353ULL: goto x86_l_549;
	case 1357ULL: goto x86_l_54d;
	case 1362ULL: goto x86_l_552;
	case 1367ULL: goto x86_l_557;
	case 1372ULL: goto x86_l_55c;
	case 1377ULL: goto x86_l_561;
	case 1382ULL: goto x86_l_566;
	case 1387ULL: goto x86_l_56b;
	case 1389ULL: goto x86_l_56d;
	case 1394ULL: goto x86_l_572;
	case 1398ULL: goto x86_l_576;
	case 1403ULL: goto x86_l_57b;
	case 1414ULL: goto x86_l_586;
	case 1421ULL: goto x86_l_58d;
	case 1429ULL: goto x86_l_595;
	case 1434ULL: goto x86_l_59a;
	case 1436ULL: goto x86_l_59c;
	case 1439ULL: goto x86_l_59f;
	case 1445ULL: goto x86_l_5a5;
	case 1448ULL: goto x86_l_5a8;
	case 1453ULL: goto x86_l_5ad;
	case 1459ULL: goto x86_l_5b3;
	case 1464ULL: goto x86_l_5b8;
	case 1469ULL: goto x86_l_5bd;
	case 1471ULL: goto x86_l_5bf;
	case 1478ULL: goto x86_l_5c6;
	case 1486ULL: goto x86_l_5ce;
	case 1491ULL: goto x86_l_5d3;
	case 1496ULL: goto x86_l_5d8;
	case 1501ULL: goto x86_l_5dd;
	case 1503ULL: goto x86_l_5df;
	case 1511ULL: goto x86_l_5e7;
	case 1516ULL: goto x86_l_5ec;
	case 1520ULL: goto x86_l_5f0;
	case 1528ULL: goto x86_l_5f8;
	case 1533ULL: goto x86_l_5fd;
	case 1538ULL: goto x86_l_602;
	case 1543ULL: goto x86_l_607;
	case 1548ULL: goto x86_l_60c;
	case 1553ULL: goto x86_l_611;
	case 1558ULL: goto x86_l_616;
	case 1560ULL: goto x86_l_618;
	case 1568ULL: goto x86_l_620;
	case 1572ULL: goto x86_l_624;
	case 1577ULL: goto x86_l_629;
	case 1582ULL: goto x86_l_62e;
	case 1587ULL: goto x86_l_633;
	case 1592ULL: goto x86_l_638;
	case 1594ULL: goto x86_l_63a;
	case 1600ULL: goto x86_l_640;
	case 1605ULL: goto x86_l_645;
	case 1607ULL: goto x86_l_647;
	case 1612ULL: goto x86_l_64c;
	case 1614ULL: goto x86_l_64e;
	case 1617ULL: goto x86_l_651;
	case 1622ULL: goto x86_l_656;
	case 1627ULL: goto x86_l_65b;
	case 1631ULL: goto x86_l_65f;
	case 1636ULL: goto x86_l_664;
	case 1641ULL: goto x86_l_669;
	case 1646ULL: goto x86_l_66e;
	case 1651ULL: goto x86_l_673;
	case 1653ULL: goto x86_l_675;
	case 1658ULL: goto x86_l_67a;
	case 1663ULL: goto x86_l_67f;
	case 1665ULL: goto x86_l_681;
	case 1668ULL: goto x86_l_684;
	case 1675ULL: goto x86_l_68b;
	case 1685ULL: goto x86_l_695;
	case 1692ULL: goto x86_l_69c;
	case 1702ULL: goto x86_l_6a6;
	case 1707ULL: goto x86_l_6ab;
	case 1716ULL: goto x86_l_6b4;
	case 1725ULL: goto x86_l_6bd;
	case 1730ULL: goto x86_l_6c2;
	case 1742ULL: goto x86_l_6ce;
	case 1754ULL: goto x86_l_6da;
	case 1766ULL: goto x86_l_6e6;
	case 1771ULL: goto x86_l_6eb;
	case 1779ULL: goto x86_l_6f3;
	case 1786ULL: goto x86_l_6fa;
	case 1794ULL: goto x86_l_702;
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
	/* 0xa: sub    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 264ULL);
x86_l_11:
	/* 0x11: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    DWORD PTR [rsp+0xec],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_1f:
	/* 0x1f: mov    rdi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_26:
	/* 0x26: lea    rsi,[rsp+0xec] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 236ULL);
x86_l_2e:
	/* 0x2e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33:
	/* 0x33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35:
	/* 0x35: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38:
	/* 0x38: je     d48 <generic_lsm_process_event+0xd48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3400ULL;
	}
x86_l_3e:
	/* 0x3e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_41:
	/* 0x41: mov    r12d,DWORD PTR [rax+0x5efc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24316ULL);
x86_l_48:
	/* 0x48: mov    ebp,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4b:
	/* 0x4b: cmp    rbp,0x2327 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 8999ULL);
x86_l_52:
	/* 0x52: ja     ca9 <generic_lsm_process_event+0xca9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3241ULL;
	}
x86_l_58:
	/* 0x58: mov    DWORD PTR [rsp+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_63:
	/* 0x63: mov    rdi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_6a:
	/* 0x6a: lea    rsi,[rsp+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_72:
	/* 0x72: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_77:
	/* 0x77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_79:
	/* 0x79: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7c:
	/* 0x7c: je     ca9 <generic_lsm_process_event+0xca9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3241ULL;
	}
x86_l_82:
	/* 0x82: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_85:
	/* 0x85: lea    rsi,[rax+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_8c:
	/* 0x8c: mov    rdi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_93:
	/* 0x93: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_98:
	/* 0x98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a:
	/* 0x9a: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_9e:
	/* 0x9e: jg     ca9 <generic_lsm_process_event+0xca9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3241ULL;
	}
x86_l_a4:
	/* 0xa4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a7:
	/* 0xa7: je     ca9 <generic_lsm_process_event+0xca9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3241ULL;
	}
x86_l_ad:
	/* 0xad: mov    QWORD PTR [rsp+0x18],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b2:
	/* 0xb2: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_b5:
	/* 0xb5: and    edx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_b8:
	/* 0xb8: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_ba:
	/* 0xba: mov    r13d,DWORD PTR [rax+rbp*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 4ULL);
x86_l_bf:
	/* 0xbf: movsxd rsi,DWORD PTR [rax+rbp*4+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RBP, 2, X86_WIDTH_32), 24ULL);
x86_l_c4:
	/* 0xc4: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_c6:
	/* 0xc6: mov    DWORD PTR [r15+rbp*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 104041287778304ULL);
x86_l_d2:
	/* 0xd2: test   esi,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_d8:
	/* 0xd8: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dc:
	/* 0xdc: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e1:
	/* 0xe1: mov    QWORD PTR [rsp+0x30],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e6:
	/* 0xe6: jne    103 <generic_lsm_process_event+0x103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_103;
	}
x86_l_e8:
	/* 0xe8: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_ea:
	/* 0xea: js     116 <generic_lsm_process_event+0x116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_116;
	}
x86_l_ec:
	/* 0xec: test   sil,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_8, 64ULL);
x86_l_f0:
	/* 0xf0: jne    126 <generic_lsm_process_event+0x126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_126;
	}
x86_l_f2:
	/* 0xf2: mov    ecx,DWORD PTR [rax+rdx*4+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 64ULL);
x86_l_f6:
	/* 0xf6: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_f9:
	/* 0xf9: mov    rsi,QWORD PTR [r15+rcx*8+0x5e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24144ULL);
x86_l_101:
	/* 0x101: jmp    14a <generic_lsm_process_event+0x14a> */
	goto x86_l_14a;
x86_l_103:
	/* 0x103: mov    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_10f:
	/* 0x10f: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_111:
	/* 0x111: jmp    242 <generic_lsm_process_event+0x242> */
	goto x86_l_242;
x86_l_116:
	/* 0x116: mov    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_122:
	/* 0x122: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_124:
	/* 0x124: jmp    152 <generic_lsm_process_event+0x152> */
	goto x86_l_152;
x86_l_126:
	/* 0x126: mov    QWORD PTR [rsp+0x38],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_12b:
	/* 0x12b: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_12e:
	/* 0x12e: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_131:
	/* 0x131: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_136:
	/* 0x136: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_138:
	/* 0x138: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13c:
	/* 0x13c: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_13f:
	/* 0x13f: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_142:
	/* 0x142: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_145:
	/* 0x145: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14a:
	/* 0x14a: mov    QWORD PTR [rsp+0xd8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_152:
	/* 0x152: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_155:
	/* 0x155: ja     242 <generic_lsm_process_event+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_242;
	}
x86_l_15b:
	/* 0x15b: lea    rcx,[rdx+rdx*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 2), 0ULL);
x86_l_15f:
	/* 0x15f: shl    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_162:
	/* 0x162: cmp    WORD PTR [rax+rcx*1+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 506806140928ULL);
x86_l_168:
	/* 0x168: je     242 <generic_lsm_process_event+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_242;
	}
x86_l_16e:
	/* 0x16e: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_171:
	/* 0x171: add    rax,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_175:
	/* 0x175: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_17a:
	/* 0x17a: lea    rax,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_182:
	/* 0x182: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_187:
	/* 0x187: mov    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_18c:
	/* 0x18c: lea    rax,[r15+rbp*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 2), 0ULL);
x86_l_190:
	/* 0x190: add    rax,0x5ea0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24224ULL);
x86_l_196:
	/* 0x196: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_19e:
	/* 0x19e: mov    rax,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1a5:
	/* 0x1a5: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a8:
	/* 0x1a8: je     209 <generic_lsm_process_event+0x209> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_209;
	}
x86_l_1aa:
	/* 0x1aa: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ad:
	/* 0x1ad: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_1b2:
	/* 0x1b2: jmp    1d5 <generic_lsm_process_event+0x1d5> */
	goto x86_l_1d5;
x86_l_1b4:
	/* 0x1b4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b9:
	/* 0x1b9: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1be:
	/* 0x1be: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c1:
	/* 0x1c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c6:
	/* 0x1c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c8:
	/* 0x1c8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ca:
	/* 0x1ca: js     22c <generic_lsm_process_event+0x22c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_22c;
	}
x86_l_1cc:
	/* 0x1cc: inc    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1cf:
	/* 0x1cf: cmp    r15,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 10ULL);
x86_l_1d3:
	/* 0x1d3: je     23a <generic_lsm_process_event+0x23a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23a;
	}
x86_l_1d5:
	/* 0x1d5: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1da:
	/* 0x1da: cmp    WORD PTR [rax+r15*8+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 3), 25769803776ULL);
x86_l_1e1:
	/* 0x1e1: je     23a <generic_lsm_process_event+0x23a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23a;
	}
x86_l_1e3:
	/* 0x1e3: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1e8:
	/* 0x1e8: mov    edx,DWORD PTR [rax+r15*8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 3), 0ULL);
x86_l_1ec:
	/* 0x1ec: add    rdx,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1ef:
	/* 0x1ef: mov    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f2:
	/* 0x1f2: cmp    WORD PTR [rax+r15*8+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 3), 17179869184ULL);
x86_l_1f9:
	/* 0x1f9: je     1cc <generic_lsm_process_event+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cc;
	}
x86_l_1fb:
	/* 0x1fb: cmp    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_200:
	/* 0x200: je     1b4 <generic_lsm_process_event+0x1b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b4;
	}
x86_l_202:
	/* 0x202: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_207:
	/* 0x207: jmp    1b9 <generic_lsm_process_event+0x1b9> */
	goto x86_l_1b9;
x86_l_209:
	/* 0x209: lea    rsi,[rip+0x1d0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 464ULL);
x86_l_210:
	/* 0x210: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_212:
	/* 0x212: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_217:
	/* 0x217: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_21c:
	/* 0x21c: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_221:
	/* 0x221: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_226:
	/* 0x226: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_228:
	/* 0x228: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22a:
	/* 0x22a: jmp    23a <generic_lsm_process_event+0x23a> */
	goto x86_l_23a;
x86_l_22c:
	/* 0x22c: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_22f:
	/* 0x22f: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_237:
	/* 0x237: mov    DWORD PTR [rax],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23a:
	/* 0x23a: mov    rsi,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_242:
	/* 0x242: mov    r15d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4096ULL);
x86_l_248:
	/* 0x248: cmp    r13d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 21ULL);
x86_l_24c:
	/* 0x24c: jg     289 <generic_lsm_process_event+0x289> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_289;
	}
x86_l_24e:
	/* 0x24e: cmp    r13d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 11ULL);
x86_l_252:
	/* 0x252: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_257:
	/* 0x257: jg     2c4 <generic_lsm_process_event+0x2c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2c4;
	}
x86_l_259:
	/* 0x259: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_25d:
	/* 0x25d: jg     34d <generic_lsm_process_event+0x34d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_34d;
	}
x86_l_263:
	/* 0x263: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_267:
	/* 0x267: jg     3d6 <generic_lsm_process_event+0x3d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3d6;
	}
x86_l_26d:
	/* 0x26d: lea    eax,[r13-0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_271:
	/* 0x271: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_274:
	/* 0x274: jb     39c <generic_lsm_process_event+0x39c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_39c;
	}
x86_l_27a:
	/* 0x27a: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_27e:
	/* 0x27e: je     39c <generic_lsm_process_event+0x39c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39c;
	}
x86_l_284:
	/* 0x284: jmp    408 <generic_lsm_process_event+0x408> */
	goto x86_l_408;
x86_l_289:
	/* 0x289: cmp    r13d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 32ULL);
x86_l_28d:
	/* 0x28d: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_292:
	/* 0x292: jle    2ed <generic_lsm_process_event+0x2ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2ed;
	}
x86_l_294:
	/* 0x294: cmp    r13d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 39ULL);
x86_l_298:
	/* 0x298: jg     31a <generic_lsm_process_event+0x31a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_31a;
	}
x86_l_29e:
	/* 0x29e: lea    eax,[r13-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_2a2:
	/* 0x2a2: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a5:
	/* 0x2a5: jb     3ea <generic_lsm_process_event+0x3ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3ea;
	}
x86_l_2ab:
	/* 0x2ab: cmp    r13d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 37ULL);
x86_l_2af:
	/* 0x2af: je     40b <generic_lsm_process_event+0x40b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40b;
	}
x86_l_2b5:
	/* 0x2b5: cmp    r13d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 39ULL);
x86_l_2b9:
	/* 0x2b9: je     3a4 <generic_lsm_process_event+0x3a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a4;
	}
x86_l_2bf:
	/* 0x2bf: jmp    408 <generic_lsm_process_event+0x408> */
	goto x86_l_408;
x86_l_2c4:
	/* 0x2c4: cmp    r13d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 17ULL);
x86_l_2c8:
	/* 0x2c8: jg     376 <generic_lsm_process_event+0x376> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_376;
	}
x86_l_2ce:
	/* 0x2ce: lea    eax,[r13-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_2d2:
	/* 0x2d2: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2d5:
	/* 0x2d5: jb     40b <generic_lsm_process_event+0x40b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_40b;
	}
x86_l_2db:
	/* 0x2db: lea    eax,[r13-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_2df:
	/* 0x2df: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e2:
	/* 0x2e2: jb     39c <generic_lsm_process_event+0x39c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_39c;
	}
x86_l_2e8:
	/* 0x2e8: jmp    408 <generic_lsm_process_event+0x408> */
	goto x86_l_408;
x86_l_2ed:
	/* 0x2ed: cmp    r13d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 26ULL);
x86_l_2f1:
	/* 0x2f1: jg     393 <generic_lsm_process_event+0x393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_393;
	}
x86_l_2f7:
	/* 0x2f7: cmp    r13d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 22ULL);
x86_l_2fb:
	/* 0x2fb: je     3a4 <generic_lsm_process_event+0x3a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a4;
	}
x86_l_301:
	/* 0x301: cmp    r13d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 23ULL);
x86_l_305:
	/* 0x305: je     3ea <generic_lsm_process_event+0x3ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea;
	}
x86_l_30b:
	/* 0x30b: cmp    r13d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 26ULL);
x86_l_30f:
	/* 0x30f: je     400 <generic_lsm_process_event+0x400> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_400;
	}
x86_l_315:
	/* 0x315: jmp    408 <generic_lsm_process_event+0x408> */
	goto x86_l_408;
x86_l_31a:
	/* 0x31a: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_31e:
	/* 0x31e: jle    3c0 <generic_lsm_process_event+0x3c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3c0;
	}
x86_l_324:
	/* 0x324: cmp    r13d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 42ULL);
x86_l_328:
	/* 0x328: je     40b <generic_lsm_process_event+0x40b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40b;
	}
x86_l_32e:
	/* 0x32e: cmp    r13d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 43ULL);
x86_l_332:
	/* 0x332: je     3ce <generic_lsm_process_event+0x3ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ce;
	}
x86_l_338:
	/* 0x338: cmp    r13d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 44ULL);
x86_l_33c:
	/* 0x33c: jne    408 <generic_lsm_process_event+0x408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_408;
	}
x86_l_342:
	/* 0x342: mov    r15d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 112ULL);
x86_l_348:
	/* 0x348: jmp    40b <generic_lsm_process_event+0x40b> */
	goto x86_l_40b;
x86_l_34d:
	/* 0x34d: cmp    r13d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 9ULL);
x86_l_351:
	/* 0x351: jg     3ea <generic_lsm_process_event+0x3ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3ea;
	}
x86_l_357:
	/* 0x357: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_35b:
	/* 0x35b: je     40b <generic_lsm_process_event+0x40b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40b;
	}
x86_l_361:
	/* 0x361: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_365:
	/* 0x365: je     3e2 <generic_lsm_process_event+0x3e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e2;
	}
x86_l_367:
	/* 0x367: cmp    r13d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 8ULL);
x86_l_36b:
	/* 0x36b: je     400 <generic_lsm_process_event+0x400> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_400;
	}
x86_l_371:
	/* 0x371: jmp    408 <generic_lsm_process_event+0x408> */
	goto x86_l_408;
x86_l_376:
	/* 0x376: cmp    r13d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 19ULL);
x86_l_37a:
	/* 0x37a: jg     3ac <generic_lsm_process_event+0x3ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3ac;
	}
x86_l_37c:
	/* 0x37c: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_381:
	/* 0x381: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_385:
	/* 0x385: je     40b <generic_lsm_process_event+0x40b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40b;
	}
x86_l_38b:
	/* 0x38b: cmp    r13d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 19ULL);
x86_l_38f:
	/* 0x38f: je     3ce <generic_lsm_process_event+0x3ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ce;
	}
x86_l_391:
	/* 0x391: jmp    408 <generic_lsm_process_event+0x408> */
	goto x86_l_408;
x86_l_393:
	/* 0x393: lea    eax,[r13-0x1d] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551587ULL);
x86_l_397:
	/* 0x397: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_39a:
	/* 0x39a: jae    3fa <generic_lsm_process_event+0x3fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3fa;
	}
x86_l_39c:
	/* 0x39c: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_3a2:
	/* 0x3a2: jmp    40b <generic_lsm_process_event+0x40b> */
	goto x86_l_40b;
x86_l_3a4:
	/* 0x3a4: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_3aa:
	/* 0x3aa: jmp    40b <generic_lsm_process_event+0x40b> */
	goto x86_l_40b;
x86_l_3ac:
	/* 0x3ac: cmp    r13d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 20ULL);
x86_l_3b0:
	/* 0x3b0: je     3f2 <generic_lsm_process_event+0x3f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f2;
	}
x86_l_3b2:
	/* 0x3b2: cmp    r13d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 21ULL);
x86_l_3b6:
	/* 0x3b6: jne    408 <generic_lsm_process_event+0x408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_408;
	}
x86_l_3b8:
	/* 0x3b8: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_3be:
	/* 0x3be: jmp    40b <generic_lsm_process_event+0x40b> */
	goto x86_l_40b;
x86_l_3c0:
	/* 0x3c0: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_3c4:
	/* 0x3c4: je     3ce <generic_lsm_process_event+0x3ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ce;
	}
x86_l_3c6:
	/* 0x3c6: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_3ca:
	/* 0x3ca: je     3e2 <generic_lsm_process_event+0x3e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e2;
	}
x86_l_3cc:
	/* 0x3cc: jmp    408 <generic_lsm_process_event+0x408> */
	goto x86_l_408;
x86_l_3ce:
	/* 0x3ce: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_3d4:
	/* 0x3d4: jmp    40b <generic_lsm_process_event+0x40b> */
	goto x86_l_40b;
x86_l_3d6:
	/* 0x3d6: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_3da:
	/* 0x3da: je     3ea <generic_lsm_process_event+0x3ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea;
	}
x86_l_3dc:
	/* 0x3dc: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_3e0:
	/* 0x3e0: jne    408 <generic_lsm_process_event+0x408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_408;
	}
x86_l_3e2:
	/* 0x3e2: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_3e8:
	/* 0x3e8: jmp    40b <generic_lsm_process_event+0x40b> */
	goto x86_l_40b;
x86_l_3ea:
	/* 0x3ea: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_3f0:
	/* 0x3f0: jmp    40b <generic_lsm_process_event+0x40b> */
	goto x86_l_40b;
x86_l_3f2:
	/* 0x3f2: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_3f8:
	/* 0x3f8: jmp    40b <generic_lsm_process_event+0x40b> */
	goto x86_l_40b;
x86_l_3fa:
	/* 0x3fa: cmp    r13d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 27ULL);
x86_l_3fe:
	/* 0x3fe: jne    408 <generic_lsm_process_event+0x408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_408;
	}
x86_l_400:
	/* 0x400: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_406:
	/* 0x406: jmp    40b <generic_lsm_process_event+0x40b> */
	goto x86_l_40b;
x86_l_408:
	/* 0x408: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_40b:
	/* 0x40b: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_410:
	/* 0x410: mov    DWORD PTR [rsp+0xf4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_41b:
	/* 0x41b: mov    rdi,QWORD PTR [rip+0x1cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_422:
	/* 0x422: lea    rsi,[rsp+0xf4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 244ULL);
x86_l_42a:
	/* 0x42a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_42f:
	/* 0x42f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_431:
	/* 0x431: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_434:
	/* 0x434: je     ca9 <generic_lsm_process_event+0xca9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3241ULL;
	}
x86_l_43a:
	/* 0x43a: mov    ecx,0x3ffb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16379ULL);
x86_l_43f:
	/* 0x43f: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_442:
	/* 0x442: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_445:
	/* 0x445: jbe    ca9 <generic_lsm_process_event+0xca9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3241ULL;
	}
x86_l_44b:
	/* 0x44b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44f:
	/* 0x44f: mov    ecx,DWORD PTR [rax+rdx*4+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 24224ULL);
x86_l_456:
	/* 0x456: mov    DWORD PTR [rax+rbp*1+0x90],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_45d:
	/* 0x45d: lea    r15,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_461:
	/* 0x461: mov    QWORD PTR [rax+rdx*8+0x5e78],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_469:
	/* 0x469: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_46e:
	/* 0x46e: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_470:
	/* 0x470: jne    ca5 <generic_lsm_process_event+0xca5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3237ULL;
	}
x86_l_476:
	/* 0x476: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_479:
	/* 0x479: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_480:
	/* 0x480: and    r15d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_487:
	/* 0x487: add    rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_48a:
	/* 0x48a: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_48f:
	/* 0x48f: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_494:
	/* 0x494: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_4a0:
	/* 0x4a0: cmp    r13d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 23ULL);
x86_l_4a4:
	/* 0x4a4: mov    QWORD PTR [rsp+0x28],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4a9:
	/* 0x4a9: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ae:
	/* 0x4ae: mov    QWORD PTR [rsp+0x38],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4b3:
	/* 0x4b3: jle    4f0 <generic_lsm_process_event+0x4f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4f0;
	}
x86_l_4b5:
	/* 0x4b5: cmp    r13d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 24ULL);
x86_l_4b9:
	/* 0x4b9: je     50b <generic_lsm_process_event+0x50b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50b;
	}
x86_l_4bb:
	/* 0x4bb: cmp    r13d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 37ULL);
x86_l_4bf:
	/* 0x4bf: je     549 <generic_lsm_process_event+0x549> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_549;
	}
x86_l_4c5:
	/* 0x4c5: cmp    r13d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 42ULL);
x86_l_4c9:
	/* 0x4c9: jne    a8c <generic_lsm_process_event+0xa8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2700ULL;
	}
x86_l_4cf:
	/* 0x4cf: mov    QWORD PTR [rsp+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_4db:
	/* 0x4db: mov    QWORD PTR [rsp+0x100],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_4e3:
	/* 0x4e3: lea    rax,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_4eb:
	/* 0x4eb: jmp    576 <generic_lsm_process_event+0x576> */
	goto x86_l_576;
x86_l_4f0:
	/* 0x4f0: cmp    r13d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 15ULL);
x86_l_4f4:
	/* 0x4f4: je     9b4 <generic_lsm_process_event+0x9b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2484ULL;
	}
x86_l_4fa:
	/* 0x4fa: cmp    r13d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 16ULL);
x86_l_4fe:
	/* 0x4fe: jne    a8c <generic_lsm_process_event+0xa8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2700ULL;
	}
x86_l_504:
	/* 0x504: lea    r15,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_509:
	/* 0x509: jmp    533 <generic_lsm_process_event+0x533> */
	goto x86_l_533;
x86_l_50b:
	/* 0x50b: lea    r15,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_510:
	/* 0x510: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_515:
	/* 0x515: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_51a:
	/* 0x51a: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_51f:
	/* 0x51f: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_522:
	/* 0x522: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_527:
	/* 0x527: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_529:
	/* 0x529: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_52e:
	/* 0x52e: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_533:
	/* 0x533: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_538:
	/* 0x538: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_53d:
	/* 0x53d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_542:
	/* 0x542: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_547:
	/* 0x547: jmp    566 <generic_lsm_process_event+0x566> */
	goto x86_l_566;
x86_l_549:
	/* 0x549: add    rdx,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_54d:
	/* 0x54d: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_552:
	/* 0x552: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_557:
	/* 0x557: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_55c:
	/* 0x55c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_561:
	/* 0x561: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_566:
	/* 0x566: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56b:
	/* 0x56b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56d:
	/* 0x56d: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_572:
	/* 0x572: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_576:
	/* 0x576: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_57b:
	/* 0x57b: mov    DWORD PTR [rsp+0xbc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_586:
	/* 0x586: mov    rdi,QWORD PTR [rip+0x1cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_58d:
	/* 0x58d: lea    rsi,[rsp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_595:
	/* 0x595: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_59a:
	/* 0x59a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59c:
	/* 0x59c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_59f:
	/* 0x59f: je     64e <generic_lsm_process_event+0x64e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_64e;
	}
x86_l_5a5:
	/* 0x5a5: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_5a8:
	/* 0x5a8: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ad:
	/* 0x5ad: add    rax,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4096ULL);
x86_l_5b3:
	/* 0x5b3: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5b8:
	/* 0x5b8: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_5bd:
	/* 0x5bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bf:
	/* 0x5bf: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_5c6:
	/* 0x5c6: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_5ce:
	/* 0x5ce: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5d3:
	/* 0x5d3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5d8:
	/* 0x5d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5dd:
	/* 0x5dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5df:
	/* 0x5df: mov    r12,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_5e7:
	/* 0x5e7: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5ec:
	/* 0x5ec: lea    rdx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f0:
	/* 0x5f0: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_5f8:
	/* 0x5f8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5fd:
	/* 0x5fd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_602:
	/* 0x602: lea    rcx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_607:
	/* 0x607: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_60c:
	/* 0x60c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_611:
	/* 0x611: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_616:
	/* 0x616: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_618:
	/* 0x618: mov    r15,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_620:
	/* 0x620: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_624:
	/* 0x624: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_629:
	/* 0x629: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_62e:
	/* 0x62e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_633:
	/* 0x633: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_638:
	/* 0x638: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63a:
	/* 0x63a: cmp    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_640:
	/* 0x640: mov    ebp,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_645:
	/* 0x645: je     65b <generic_lsm_process_event+0x65b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_65b;
	}
x86_l_647:
	/* 0x647: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_64c:
	/* 0x64c: jmp    6ab <generic_lsm_process_event+0x6ab> */
	goto x86_l_6ab;
x86_l_64e:
	/* 0x64e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_651:
	/* 0x651: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_656:
	/* 0x656: jmp    c92 <generic_lsm_process_event+0xc92> */
	return 3218ULL;
x86_l_65b:
	/* 0x65b: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_65f:
	/* 0x65f: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_664:
	/* 0x664: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_669:
	/* 0x669: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_66e:
	/* 0x66e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_673:
	/* 0x673: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_675:
	/* 0x675: cmp    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_67a:
	/* 0x67a: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_67f:
	/* 0x67f: je     6ab <generic_lsm_process_event+0x6ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6ab;
	}
x86_l_681:
	/* 0x681: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_684:
	/* 0x684: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_68b:
	/* 0x68b: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_695:
	/* 0x695: mov    QWORD PTR [r13+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_69c:
	/* 0x69c: mov    WORD PTR [r13+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_6a6:
	/* 0x6a6: mov    ebp,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4086ULL);
x86_l_6ab:
	/* 0x6ab: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_6b4:
	/* 0x6b4: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_6bd:
	/* 0x6bd: mov    QWORD PTR [rsp+0x78],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6c2:
	/* 0x6c2: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_6ce:
	/* 0x6ce: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_6da:
	/* 0x6da: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_6e6:
	/* 0x6e6: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6eb:
	/* 0x6eb: mov    QWORD PTR [rsp+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_6f3:
	/* 0x6f3: mov    DWORD PTR [rsp+0xa0],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_6fa:
	/* 0x6fa: mov    BYTE PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_702:
	/* 0x702: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
	return 1798ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1798ULL: goto x86_l_706;
	case 1803ULL: goto x86_l_70b;
	case 1808ULL: goto x86_l_710;
	case 1813ULL: goto x86_l_715;
	case 1818ULL: goto x86_l_71a;
	case 1826ULL: goto x86_l_722;
	case 1834ULL: goto x86_l_72a;
	case 1839ULL: goto x86_l_72f;
	case 1842ULL: goto x86_l_732;
	case 1844ULL: goto x86_l_734;
	case 1849ULL: goto x86_l_739;
	case 1854ULL: goto x86_l_73e;
	case 1859ULL: goto x86_l_743;
	case 1862ULL: goto x86_l_746;
	case 1867ULL: goto x86_l_74b;
	case 1869ULL: goto x86_l_74d;
	case 1874ULL: goto x86_l_752;
	case 1879ULL: goto x86_l_757;
	case 1884ULL: goto x86_l_75c;
	case 1887ULL: goto x86_l_75f;
	case 1892ULL: goto x86_l_764;
	case 1894ULL: goto x86_l_766;
	case 1899ULL: goto x86_l_76b;
	case 1904ULL: goto x86_l_770;
	case 1909ULL: goto x86_l_775;
	case 1912ULL: goto x86_l_778;
	case 1917ULL: goto x86_l_77d;
	case 1919ULL: goto x86_l_77f;
	case 1927ULL: goto x86_l_787;
	case 1931ULL: goto x86_l_78b;
	case 1939ULL: goto x86_l_793;
	case 1946ULL: goto x86_l_79a;
	case 1949ULL: goto x86_l_79d;
	case 1955ULL: goto x86_l_7a3;
	case 1960ULL: goto x86_l_7a8;
	case 1966ULL: goto x86_l_7ae;
	case 1974ULL: goto x86_l_7b6;
	case 1982ULL: goto x86_l_7be;
	case 1990ULL: goto x86_l_7c6;
	case 1995ULL: goto x86_l_7cb;
	case 1997ULL: goto x86_l_7cd;
	case 2002ULL: goto x86_l_7d2;
	case 2008ULL: goto x86_l_7d8;
	case 2013ULL: goto x86_l_7dd;
	case 2021ULL: goto x86_l_7e5;
	case 2026ULL: goto x86_l_7ea;
	case 2028ULL: goto x86_l_7ec;
	case 2036ULL: goto x86_l_7f4;
	case 2042ULL: goto x86_l_7fa;
	case 2048ULL: goto x86_l_800;
	case 2052ULL: goto x86_l_804;
	case 2057ULL: goto x86_l_809;
	case 2062ULL: goto x86_l_80e;
	case 2067ULL: goto x86_l_813;
	case 2070ULL: goto x86_l_816;
	case 2072ULL: goto x86_l_818;
	case 2077ULL: goto x86_l_81d;
	case 2083ULL: goto x86_l_823;
	case 2088ULL: goto x86_l_828;
	case 2093ULL: goto x86_l_82d;
	case 2098ULL: goto x86_l_832;
	case 2101ULL: goto x86_l_835;
	case 2103ULL: goto x86_l_837;
	case 2107ULL: goto x86_l_83b;
	case 2112ULL: goto x86_l_840;
	case 2120ULL: goto x86_l_848;
	case 2125ULL: goto x86_l_84d;
	case 2130ULL: goto x86_l_852;
	case 2133ULL: goto x86_l_855;
	case 2135ULL: goto x86_l_857;
	case 2140ULL: goto x86_l_85c;
	case 2148ULL: goto x86_l_864;
	case 2156ULL: goto x86_l_86c;
	case 2159ULL: goto x86_l_86f;
	case 2167ULL: goto x86_l_877;
	case 2170ULL: goto x86_l_87a;
	case 2173ULL: goto x86_l_87d;
	case 2178ULL: goto x86_l_882;
	case 2181ULL: goto x86_l_885;
	case 2189ULL: goto x86_l_88d;
	case 2191ULL: goto x86_l_88f;
	case 2194ULL: goto x86_l_892;
	case 2198ULL: goto x86_l_896;
	case 2201ULL: goto x86_l_899;
	case 2205ULL: goto x86_l_89d;
	case 2207ULL: goto x86_l_89f;
	case 2210ULL: goto x86_l_8a2;
	case 2212ULL: goto x86_l_8a4;
	case 2219ULL: goto x86_l_8ab;
	case 2222ULL: goto x86_l_8ae;
	case 2227ULL: goto x86_l_8b3;
	case 2233ULL: goto x86_l_8b9;
	case 2239ULL: goto x86_l_8bf;
	case 2245ULL: goto x86_l_8c5;
	case 2248ULL: goto x86_l_8c8;
	case 2250ULL: goto x86_l_8ca;
	case 2255ULL: goto x86_l_8cf;
	case 2257ULL: goto x86_l_8d1;
	case 2260ULL: goto x86_l_8d4;
	case 2264ULL: goto x86_l_8d8;
	case 2267ULL: goto x86_l_8db;
	case 2270ULL: goto x86_l_8de;
	case 2273ULL: goto x86_l_8e1;
	case 2278ULL: goto x86_l_8e6;
	case 2280ULL: goto x86_l_8e8;
	case 2288ULL: goto x86_l_8f0;
	case 2291ULL: goto x86_l_8f3;
	case 2297ULL: goto x86_l_8f9;
	case 2302ULL: goto x86_l_8fe;
	case 2310ULL: goto x86_l_906;
	case 2316ULL: goto x86_l_90c;
	case 2318ULL: goto x86_l_90e;
	case 2324ULL: goto x86_l_914;
	case 2329ULL: goto x86_l_919;
	case 2334ULL: goto x86_l_91e;
	case 2339ULL: goto x86_l_923;
	case 2344ULL: goto x86_l_928;
	case 2349ULL: goto x86_l_92d;
	case 2351ULL: goto x86_l_92f;
	case 2359ULL: goto x86_l_937;
	case 2364ULL: goto x86_l_93c;
	case 2370ULL: goto x86_l_942;
	case 2376ULL: goto x86_l_948;
	case 2380ULL: goto x86_l_94c;
	case 2385ULL: goto x86_l_951;
	case 2393ULL: goto x86_l_959;
	case 2398ULL: goto x86_l_95e;
	case 2401ULL: goto x86_l_961;
	case 2403ULL: goto x86_l_963;
	case 2408ULL: goto x86_l_968;
	case 2416ULL: goto x86_l_970;
	case 2420ULL: goto x86_l_974;
	case 2428ULL: goto x86_l_97c;
	case 2433ULL: goto x86_l_981;
	case 2435ULL: goto x86_l_983;
	case 2441ULL: goto x86_l_989;
	case 2446ULL: goto x86_l_98e;
	case 2453ULL: goto x86_l_995;
	case 2455ULL: goto x86_l_997;
	case 2460ULL: goto x86_l_99c;
	case 2465ULL: goto x86_l_9a1;
	case 2470ULL: goto x86_l_9a6;
	case 2475ULL: goto x86_l_9ab;
	case 2477ULL: goto x86_l_9ad;
	case 2479ULL: goto x86_l_9af;
	case 2484ULL: goto x86_l_9b4;
	case 2492ULL: goto x86_l_9bc;
	case 2497ULL: goto x86_l_9c1;
	case 2502ULL: goto x86_l_9c6;
	case 2507ULL: goto x86_l_9cb;
	case 2512ULL: goto x86_l_9d0;
	case 2514ULL: goto x86_l_9d2;
	case 2522ULL: goto x86_l_9da;
	case 2527ULL: goto x86_l_9df;
	case 2530ULL: goto x86_l_9e2;
	case 2536ULL: goto x86_l_9e8;
	case 2547ULL: goto x86_l_9f3;
	case 2554ULL: goto x86_l_9fa;
	case 2562ULL: goto x86_l_a02;
	case 2567ULL: goto x86_l_a07;
	case 2569ULL: goto x86_l_a09;
	case 2572ULL: goto x86_l_a0c;
	case 2578ULL: goto x86_l_a12;
	case 2583ULL: goto x86_l_a17;
	case 2588ULL: goto x86_l_a1c;
	case 2591ULL: goto x86_l_a1f;
	case 2595ULL: goto x86_l_a23;
	case 2600ULL: goto x86_l_a28;
	case 2605ULL: goto x86_l_a2d;
	case 2611ULL: goto x86_l_a33;
	case 2615ULL: goto x86_l_a37;
	case 2621ULL: goto x86_l_a3d;
	case 2625ULL: goto x86_l_a41;
	case 2631ULL: goto x86_l_a47;
	case 2635ULL: goto x86_l_a4b;
	case 2641ULL: goto x86_l_a51;
	case 2645ULL: goto x86_l_a55;
	case 2651ULL: goto x86_l_a5b;
	case 2655ULL: goto x86_l_a5f;
	case 2660ULL: goto x86_l_a64;
	case 2664ULL: goto x86_l_a68;
	case 2669ULL: goto x86_l_a6d;
	case 2675ULL: goto x86_l_a73;
	case 2680ULL: goto x86_l_a78;
	case 2687ULL: goto x86_l_a7f;
	case 2689ULL: goto x86_l_a81;
	case 2695ULL: goto x86_l_a87;
	case 2700ULL: goto x86_l_a8c;
	case 2704ULL: goto x86_l_a90;
	case 2710ULL: goto x86_l_a96;
	case 2713ULL: goto x86_l_a99;
	case 2723ULL: goto x86_l_aa3;
	case 2727ULL: goto x86_l_aa7;
	case 2733ULL: goto x86_l_aad;
	case 2738ULL: goto x86_l_ab2;
	case 2749ULL: goto x86_l_abd;
	case 2756ULL: goto x86_l_ac4;
	case 2764ULL: goto x86_l_acc;
	case 2769ULL: goto x86_l_ad1;
	case 2771ULL: goto x86_l_ad3;
	case 2774ULL: goto x86_l_ad6;
	case 2776ULL: goto x86_l_ad8;
	case 2781ULL: goto x86_l_add;
	case 2786ULL: goto x86_l_ae2;
	case 2789ULL: goto x86_l_ae5;
	case 2793ULL: goto x86_l_ae9;
	case 2798ULL: goto x86_l_aee;
	case 2804ULL: goto x86_l_af4;
	case 2808ULL: goto x86_l_af8;
	case 2813ULL: goto x86_l_afd;
	case 2818ULL: goto x86_l_b02;
	case 2824ULL: goto x86_l_b08;
	case 2828ULL: goto x86_l_b0c;
	case 2834ULL: goto x86_l_b12;
	case 2838ULL: goto x86_l_b16;
	case 2841ULL: goto x86_l_b19;
	case 2847ULL: goto x86_l_b1f;
	case 2852ULL: goto x86_l_b24;
	case 2858ULL: goto x86_l_b2a;
	case 2863ULL: goto x86_l_b2f;
	case 2868ULL: goto x86_l_b34;
	case 2873ULL: goto x86_l_b39;
	case 2878ULL: goto x86_l_b3e;
	case 2883ULL: goto x86_l_b43;
	case 2886ULL: goto x86_l_b46;
	case 2891ULL: goto x86_l_b4b;
	case 2896ULL: goto x86_l_b50;
	case 2901ULL: goto x86_l_b55;
	case 2909ULL: goto x86_l_b5d;
	case 2911ULL: goto x86_l_b5f;
	case 2919ULL: goto x86_l_b67;
	case 2924ULL: goto x86_l_b6c;
	case 2932ULL: goto x86_l_b74;
	case 2937ULL: goto x86_l_b79;
	case 2939ULL: goto x86_l_b7b;
	case 2942ULL: goto x86_l_b7e;
	case 2944ULL: goto x86_l_b80;
	case 2952ULL: goto x86_l_b88;
	case 2955ULL: goto x86_l_b8b;
	case 2962ULL: goto x86_l_b92;
	case 2968ULL: goto x86_l_b98;
	case 2971ULL: goto x86_l_b9b;
	case 2973ULL: goto x86_l_b9d;
	case 2977ULL: goto x86_l_ba1;
	case 2980ULL: goto x86_l_ba4;
	case 2985ULL: goto x86_l_ba9;
	case 2991ULL: goto x86_l_baf;
	case 2994ULL: goto x86_l_bb2;
	case 2996ULL: goto x86_l_bb4;
	case 2999ULL: goto x86_l_bb7;
	case 3001ULL: goto x86_l_bb9;
	case 3004ULL: goto x86_l_bbc;
	case 3009ULL: goto x86_l_bc1;
	case 3014ULL: goto x86_l_bc6;
	case 3018ULL: goto x86_l_bca;
	case 3025ULL: goto x86_l_bd1;
	case 3030ULL: goto x86_l_bd6;
	case 3033ULL: goto x86_l_bd9;
	case 3035ULL: goto x86_l_bdb;
	case 3039ULL: goto x86_l_bdf;
	case 3044ULL: goto x86_l_be4;
	case 3049ULL: goto x86_l_be9;
	case 3054ULL: goto x86_l_bee;
	case 3059ULL: goto x86_l_bf3;
	case 3064ULL: goto x86_l_bf8;
	case 3066ULL: goto x86_l_bfa;
	case 3071ULL: goto x86_l_bff;
	case 3075ULL: goto x86_l_c03;
	case 3083ULL: goto x86_l_c0b;
	case 3088ULL: goto x86_l_c10;
	case 3093ULL: goto x86_l_c15;
	case 3098ULL: goto x86_l_c1a;
	case 3102ULL: goto x86_l_c1e;
	case 3107ULL: goto x86_l_c23;
	case 3109ULL: goto x86_l_c25;
	case 3117ULL: goto x86_l_c2d;
	case 3122ULL: goto x86_l_c32;
	case 3127ULL: goto x86_l_c37;
	case 3132ULL: goto x86_l_c3c;
	case 3140ULL: goto x86_l_c44;
	case 3145ULL: goto x86_l_c49;
	case 3147ULL: goto x86_l_c4b;
	case 3152ULL: goto x86_l_c50;
	case 3157ULL: goto x86_l_c55;
	case 3163ULL: goto x86_l_c5b;
	case 3167ULL: goto x86_l_c5f;
	case 3172ULL: goto x86_l_c64;
	case 3177ULL: goto x86_l_c69;
	case 3181ULL: goto x86_l_c6d;
	case 3184ULL: goto x86_l_c70;
	case 3186ULL: goto x86_l_c72;
	case 3197ULL: goto x86_l_c7d;
	case 3208ULL: goto x86_l_c88;
	case 3213ULL: goto x86_l_c8d;
	case 3215ULL: goto x86_l_c8f;
	case 3218ULL: goto x86_l_c92;
	case 3223ULL: goto x86_l_c97;
	case 3230ULL: goto x86_l_c9e;
	case 3234ULL: goto x86_l_ca2;
	case 3237ULL: goto x86_l_ca5;
	case 3239ULL: goto x86_l_ca7;
	case 3241ULL: goto x86_l_ca9;
	case 3245ULL: goto x86_l_cad;
	case 3249ULL: goto x86_l_cb1;
	case 3251ULL: goto x86_l_cb3;
	case 3259ULL: goto x86_l_cbb;
	case 3266ULL: goto x86_l_cc2;
	case 3271ULL: goto x86_l_cc7;
	case 3276ULL: goto x86_l_ccc;
	case 3278ULL: goto x86_l_cce;
	case 3281ULL: goto x86_l_cd1;
	case 3283ULL: goto x86_l_cd3;
	case 3286ULL: goto x86_l_cd6;
	case 3293ULL: goto x86_l_cdd;
	case 3300ULL: goto x86_l_ce4;
	case 3305ULL: goto x86_l_ce9;
	case 3307ULL: goto x86_l_ceb;
	case 3310ULL: goto x86_l_cee;
	case 3312ULL: goto x86_l_cf0;
	case 3315ULL: goto x86_l_cf3;
	case 3318ULL: goto x86_l_cf6;
	case 3321ULL: goto x86_l_cf9;
	case 3326ULL: goto x86_l_cfe;
	case 3328ULL: goto x86_l_d00;
	case 3335ULL: goto x86_l_d07;
	case 3342ULL: goto x86_l_d0e;
	case 3347ULL: goto x86_l_d13;
	case 3352ULL: goto x86_l_d18;
	case 3355ULL: goto x86_l_d1b;
	case 3360ULL: goto x86_l_d20;
	case 3362ULL: goto x86_l_d22;
	case 3373ULL: goto x86_l_d2d;
	case 3380ULL: goto x86_l_d34;
	case 3385ULL: goto x86_l_d39;
	case 3390ULL: goto x86_l_d3e;
	case 3393ULL: goto x86_l_d41;
	case 3398ULL: goto x86_l_d46;
	case 3400ULL: goto x86_l_d48;
	case 3402ULL: goto x86_l_d4a;
	case 3409ULL: goto x86_l_d51;
	case 3410ULL: goto x86_l_d52;
	case 3412ULL: goto x86_l_d54;
	case 3414ULL: goto x86_l_d56;
	case 3416ULL: goto x86_l_d58;
	case 3418ULL: goto x86_l_d5a;
	case 3419ULL: goto x86_l_d5b;
	case 3424ULL: goto x86_l_d60;
	case 3428ULL: goto x86_l_d64;
	case 3433ULL: goto x86_l_d69;
	case 3438ULL: goto x86_l_d6e;
	case 3442ULL: goto x86_l_d72;
	case 3448ULL: goto x86_l_d78;
	case 3452ULL: goto x86_l_d7c;
	case 3458ULL: goto x86_l_d82;
	case 3462ULL: goto x86_l_d86;
	case 3468ULL: goto x86_l_d8c;
	case 3472ULL: goto x86_l_d90;
	case 3478ULL: goto x86_l_d96;
	case 3483ULL: goto x86_l_d9b;
	case 3487ULL: goto x86_l_d9f;
	case 3492ULL: goto x86_l_da4;
	case 3496ULL: goto x86_l_da8;
	case 3502ULL: goto x86_l_dae;
	case 3507ULL: goto x86_l_db3;
	case 3512ULL: goto x86_l_db8;
	case 3516ULL: goto x86_l_dbc;
	case 3520ULL: goto x86_l_dc0;
	case 3524ULL: goto x86_l_dc4;
	case 3529ULL: goto x86_l_dc9;
	case 3534ULL: goto x86_l_dce;
	case 3539ULL: goto x86_l_dd3;
	case 3541ULL: goto x86_l_dd5;
	case 3545ULL: goto x86_l_dd9;
	case 3549ULL: goto x86_l_ddd;
	case 3554ULL: goto x86_l_de2;
	case 3559ULL: goto x86_l_de7;
	case 3564ULL: goto x86_l_dec;
	case 3566ULL: goto x86_l_dee;
	case 3570ULL: goto x86_l_df2;
	case 3577ULL: goto x86_l_df9;
	case 3582ULL: goto x86_l_dfe;
	case 3587ULL: goto x86_l_e03;
	case 3592ULL: goto x86_l_e08;
	case 3594ULL: goto x86_l_e0a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_706:
	/* 0x706: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_70b:
	/* 0x70b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_710:
	/* 0x710: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_715:
	/* 0x715: lea    r13,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_71a:
	/* 0x71a: lea    r15,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_722:
	/* 0x722: lea    rbp,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_72a:
	/* 0x72a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_72f:
	/* 0x72f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_732:
	/* 0x732: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_734:
	/* 0x734: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_739:
	/* 0x739: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_73e:
	/* 0x73e: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_743:
	/* 0x743: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_746:
	/* 0x746: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_74b:
	/* 0x74b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_74d:
	/* 0x74d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_752:
	/* 0x752: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_757:
	/* 0x757: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_75c:
	/* 0x75c: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_75f:
	/* 0x75f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_764:
	/* 0x764: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_766:
	/* 0x766: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_76b:
	/* 0x76b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_770:
	/* 0x770: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_775:
	/* 0x775: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_778:
	/* 0x778: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_77d:
	/* 0x77d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_77f:
	/* 0x77f: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_787:
	/* 0x787: add    rax,0xffffffffffffffe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_78b:
	/* 0x78b: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_793:
	/* 0x793: mov    rax,QWORD PTR [rip+0x1cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_79a:
	/* 0x79a: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_79d:
	/* 0x79d: je     98e <generic_lsm_process_event+0x98e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_98e;
	}
x86_l_7a3:
	/* 0x7a3: mov    ebp,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2048ULL);
x86_l_7a8:
	/* 0x7a8: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_7ae:
	/* 0x7ae: mov    r13,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7b6:
	/* 0x7b6: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_7be:
	/* 0x7be: mov    r12,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_7c6:
	/* 0x7c6: cmp    r13,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 104ULL);
x86_l_7cb:
	/* 0x7cb: jne    7d8 <generic_lsm_process_event+0x7d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7d8;
	}
x86_l_7cd:
	/* 0x7cd: cmp    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_7d2:
	/* 0x7d2: je     b55 <generic_lsm_process_event+0xb55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b55;
	}
x86_l_7d8:
	/* 0x7d8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7dd:
	/* 0x7dd: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_7e5:
	/* 0x7e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7ea:
	/* 0x7ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ec:
	/* 0x7ec: cmp    r13,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 208ULL);
x86_l_7f4:
	/* 0x7f4: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_7fa:
	/* 0x7fa: je     919 <generic_lsm_process_event+0x919> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_919;
	}
x86_l_800:
	/* 0x800: lea    r15,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_804:
	/* 0x804: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_809:
	/* 0x809: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_80e:
	/* 0x80e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_813:
	/* 0x813: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_816:
	/* 0x816: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_818:
	/* 0x818: cmp    QWORD PTR [rsp+0x58],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_81d:
	/* 0x81d: je     919 <generic_lsm_process_event+0x919> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_919;
	}
x86_l_823:
	/* 0x823: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_828:
	/* 0x828: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_82d:
	/* 0x82d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_832:
	/* 0x832: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_835:
	/* 0x835: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_837:
	/* 0x837: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_83b:
	/* 0x83b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_840:
	/* 0x840: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_848:
	/* 0x848: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_84d:
	/* 0x84d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_852:
	/* 0x852: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_855:
	/* 0x855: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_857:
	/* 0x857: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_85c:
	/* 0x85c: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_864:
	/* 0x864: mov    r12d,DWORD PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_86c:
	/* 0x86c: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_86f:
	/* 0x86f: mov    r13d,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_877:
	/* 0x877: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_87a:
	/* 0x87a: sub    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_87d:
	/* 0x87d: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_882:
	/* 0x882: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_885:
	/* 0x885: add    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 176ULL);
x86_l_88d:
	/* 0x88d: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_88f:
	/* 0x88f: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_892:
	/* 0x892: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_896:
	/* 0x896: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_899:
	/* 0x899: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_89d:
	/* 0x89d: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_89f:
	/* 0x89f: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_8a2:
	/* 0x8a2: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_8a4:
	/* 0x8a4: mov    DWORD PTR [rsp+0xa0],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_8ab:
	/* 0x8ab: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_8ae:
	/* 0x8ae: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8b3:
	/* 0x8b3: jb     b6c <generic_lsm_process_event+0xb6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b6c;
	}
x86_l_8b9:
	/* 0x8b9: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_8bf:
	/* 0x8bf: ja     b6c <generic_lsm_process_event+0xb6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b6c;
	}
x86_l_8c5:
	/* 0x8c5: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_8c8:
	/* 0x8c8: jbe    8cf <generic_lsm_process_event+0x8cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_8cf;
	}
x86_l_8ca:
	/* 0x8ca: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_8cf:
	/* 0x8cf: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8d1:
	/* 0x8d1: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_8d4:
	/* 0x8d4: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_8d8:
	/* 0x8d8: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_8db:
	/* 0x8db: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_8de:
	/* 0x8de: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_8e1:
	/* 0x8e1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8e6:
	/* 0x8e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e8:
	/* 0x8e8: mov    QWORD PTR [rsp+0x98],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_8f0:
	/* 0x8f0: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_8f3:
	/* 0x8f3: jbe    b6c <generic_lsm_process_event+0xb6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_b6c;
	}
x86_l_8f9:
	/* 0x8f9: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8fe:
	/* 0x8fe: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_906:
	/* 0x906: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_90c:
	/* 0x90c: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_90e:
	/* 0x90e: jne    7ae <generic_lsm_process_event+0x7ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7ae;
	}
x86_l_914:
	/* 0x914: jmp    b6c <generic_lsm_process_event+0xb6c> */
	goto x86_l_b6c;
x86_l_919:
	/* 0x919: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_91e:
	/* 0x91e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_923:
	/* 0x923: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_928:
	/* 0x928: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_92d:
	/* 0x92d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_92f:
	/* 0x92f: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_937:
	/* 0x937: cmp    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 88ULL);
x86_l_93c:
	/* 0x93c: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_942:
	/* 0x942: je     b5f <generic_lsm_process_event+0xb5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b5f;
	}
x86_l_948:
	/* 0x948: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_94c:
	/* 0x94c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_951:
	/* 0x951: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_959:
	/* 0x959: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_95e:
	/* 0x95e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_961:
	/* 0x961: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_963:
	/* 0x963: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_968:
	/* 0x968: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_970:
	/* 0x970: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_974:
	/* 0x974: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_97c:
	/* 0x97c: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_981:
	/* 0x981: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_983:
	/* 0x983: jne    7ae <generic_lsm_process_event+0x7ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7ae;
	}
x86_l_989:
	/* 0x989: jmp    b6c <generic_lsm_process_event+0xb6c> */
	goto x86_l_b6c;
x86_l_98e:
	/* 0x98e: lea    rsi,[rip+0x1cc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 460ULL);
x86_l_995:
	/* 0x995: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_997:
	/* 0x997: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_99c:
	/* 0x99c: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_9a1:
	/* 0x9a1: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_9a6:
	/* 0x9a6: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_9ab:
	/* 0x9ab: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9ad:
	/* 0x9ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9af:
	/* 0x9af: jmp    b6c <generic_lsm_process_event+0xb6c> */
	goto x86_l_b6c;
x86_l_9b4:
	/* 0x9b4: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_9bc:
	/* 0x9bc: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9c1:
	/* 0x9c1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9c6:
	/* 0x9c6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9cb:
	/* 0x9cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9d0:
	/* 0x9d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d2:
	/* 0x9d2: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_9da:
	/* 0x9da: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9df:
	/* 0x9df: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9e2:
	/* 0x9e2: jne    57b <generic_lsm_process_event+0x57b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1403ULL;
	}
x86_l_9e8:
	/* 0x9e8: mov    DWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_9f3:
	/* 0x9f3: mov    rdi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_9fa:
	/* 0x9fa: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_a02:
	/* 0xa02: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a07:
	/* 0xa07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a09:
	/* 0xa09: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a0c:
	/* 0xa0c: je     b43 <generic_lsm_process_event+0xb43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b43;
	}
x86_l_a12:
	/* 0xa12: mov    QWORD PTR [rsp+0x50],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a17:
	/* 0xa17: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a1c:
	/* 0xa1c: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a1f:
	/* 0xa1f: cmp    r13d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 25ULL);
x86_l_a23:
	/* 0xa23: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a28:
	/* 0xa28: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a2d:
	/* 0xa2d: jg     f83 <generic_lsm_process_event+0xf83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3971ULL;
	}
x86_l_a33:
	/* 0xa33: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_a37:
	/* 0xa37: jle    10ec <generic_lsm_process_event+0x10ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4332ULL;
	}
x86_l_a3d:
	/* 0xa3d: cmp    r13d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 20ULL);
x86_l_a41:
	/* 0xa41: jle    1475 <generic_lsm_process_event+0x1475> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5237ULL;
	}
x86_l_a47:
	/* 0xa47: cmp    r13d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 21ULL);
x86_l_a4b:
	/* 0xa4b: je     1ce9 <generic_lsm_process_event+0x1ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7401ULL;
	}
x86_l_a51:
	/* 0xa51: cmp    r13d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 22ULL);
x86_l_a55:
	/* 0xa55: je     1c5f <generic_lsm_process_event+0x1c5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7263ULL;
	}
x86_l_a5b:
	/* 0xa5b: cmp    r13d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 23ULL);
x86_l_a5f:
	/* 0xa5f: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a64:
	/* 0xa64: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a68:
	/* 0xa68: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a6d:
	/* 0xa6d: jne    c6d <generic_lsm_process_event+0xc6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c6d;
	}
x86_l_a73:
	/* 0xa73: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a78:
	/* 0xa78: mov    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_a7f:
	/* 0xa7f: mov    DWORD PTR [rax],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a81:
	/* 0xa81: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_a87:
	/* 0xa87: jmp    c6d <generic_lsm_process_event+0xc6d> */
	goto x86_l_c6d;
x86_l_a8c:
	/* 0xa8c: cmp    r13d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 44ULL);
x86_l_a90:
	/* 0xa90: ja     9e8 <generic_lsm_process_event+0x9e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_9e8;
	}
x86_l_a96:
	/* 0xa96: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_a99:
	/* 0xa99: movabs rcx,0x11c1f2027cf2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19524686609650ULL);
x86_l_aa3:
	/* 0xaa3: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_aa7:
	/* 0xaa7: jae    9e8 <generic_lsm_process_event+0x9e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_9e8;
	}
x86_l_aad:
	/* 0xaad: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_ab2:
	/* 0xab2: mov    DWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_abd:
	/* 0xabd: mov    rdi,QWORD PTR [rip+0x1cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_ac4:
	/* 0xac4: lea    rsi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_acc:
	/* 0xacc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ad1:
	/* 0xad1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad3:
	/* 0xad3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ad6:
	/* 0xad6: je     b43 <generic_lsm_process_event+0xb43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b43;
	}
x86_l_ad8:
	/* 0xad8: mov    QWORD PTR [rsp+0x50],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_add:
	/* 0xadd: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ae2:
	/* 0xae2: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ae5:
	/* 0xae5: cmp    r13d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 16ULL);
x86_l_ae9:
	/* 0xae9: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_aee:
	/* 0xaee: jle    d60 <generic_lsm_process_event+0xd60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_d60;
	}
x86_l_af4:
	/* 0xaf4: cmp    r13d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 30ULL);
x86_l_af8:
	/* 0xaf8: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_afd:
	/* 0xafd: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b02:
	/* 0xb02: jle    ecb <generic_lsm_process_event+0xecb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3787ULL;
	}
x86_l_b08:
	/* 0xb08: cmp    r13d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 38ULL);
x86_l_b0c:
	/* 0xb0c: jg     fc4 <generic_lsm_process_event+0xfc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4036ULL;
	}
x86_l_b12:
	/* 0xb12: lea    eax,[r13-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_b16:
	/* 0xb16: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b19:
	/* 0xb19: jae    1563 <generic_lsm_process_event+0x1563> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5475ULL;
	}
x86_l_b1f:
	/* 0xb1f: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b24:
	/* 0xb24: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_b2a:
	/* 0xb2a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b2f:
	/* 0xb2f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b34:
	/* 0xb34: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b39:
	/* 0xb39: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_b3e:
	/* 0xb3e: jmp    1185 <generic_lsm_process_event+0x1185> */
	return 4485ULL;
x86_l_b43:
	/* 0xb43: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b46:
	/* 0xb46: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b4b:
	/* 0xb4b: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b50:
	/* 0xb50: jmp    c64 <generic_lsm_process_event+0xc64> */
	goto x86_l_c64;
x86_l_b55:
	/* 0xb55: mov    BYTE PTR [rsp+0xa4],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 704374636545ULL);
x86_l_b5d:
	/* 0xb5d: jmp    b6c <generic_lsm_process_event+0xb6c> */
	goto x86_l_b6c;
x86_l_b5f:
	/* 0xb5f: mov    BYTE PTR [rsp+0xa4],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 704374636545ULL);
x86_l_b67:
	/* 0xb67: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b6c:
	/* 0xb6c: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_b74:
	/* 0xb74: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b79:
	/* 0xb79: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b7b:
	/* 0xb7b: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_b7e:
	/* 0xb7e: je     bb9 <generic_lsm_process_event+0xbb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bb9;
	}
x86_l_b80:
	/* 0xb80: cmp    BYTE PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_b88:
	/* 0xb88: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_b8b:
	/* 0xb8b: mov    edx,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_b92:
	/* 0xb92: mov    r15d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4096ULL);
x86_l_b98:
	/* 0xb98: sub    r15d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_b9b:
	/* 0xb9b: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_b9d:
	/* 0xb9d: cmovle r15d,edx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_ba1:
	/* 0xba1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ba4:
	/* 0xba4: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ba9:
	/* 0xba9: je     c8f <generic_lsm_process_event+0xc8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c8f;
	}
x86_l_baf:
	/* 0xbaf: mov    bpl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_8);
x86_l_bb2:
	/* 0xbb2: add    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_bb4:
	/* 0xbb4: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_bb7:
	/* 0xbb7: jmp    bc1 <generic_lsm_process_event+0xbc1> */
	goto x86_l_bc1;
x86_l_bb9:
	/* 0xbb9: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bbc:
	/* 0xbbc: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_bc1:
	/* 0xbc1: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bc6:
	/* 0xbc6: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bca:
	/* 0xbca: and    r15d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bd1:
	/* 0xbd1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bd6:
	/* 0xbd6: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_bd9:
	/* 0xbd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bdb:
	/* 0xbdb: mov    DWORD PTR [r13+0x0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bdf:
	/* 0xbdf: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_be4:
	/* 0xbe4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_be9:
	/* 0xbe9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bee:
	/* 0xbee: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bf3:
	/* 0xbf3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bf8:
	/* 0xbf8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bfa:
	/* 0xbfa: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_bff:
	/* 0xbff: add    rcx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_c03:
	/* 0xc03: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_c0b:
	/* 0xc0b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c10:
	/* 0xc10: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c15:
	/* 0xc15: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c1a:
	/* 0xc1a: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_c1e:
	/* 0xc1e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c23:
	/* 0xc23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c25:
	/* 0xc25: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_c2d:
	/* 0xc2d: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c32:
	/* 0xc32: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_c37:
	/* 0xc37: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c3c:
	/* 0xc3c: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_c44:
	/* 0xc44: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c49:
	/* 0xc49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c4b:
	/* 0xc4b: mov    DWORD PTR [r13+r15*1+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 4ULL);
x86_l_c50:
	/* 0xc50: movzx  eax,WORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 88ULL);
x86_l_c55:
	/* 0xc55: mov    WORD PTR [r13+r15*1+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 8ULL);
x86_l_c5b:
	/* 0xc5b: add    r15d,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_c5f:
	/* 0xc5f: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c64:
	/* 0xc64: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c69:
	/* 0xc69: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c6d:
	/* 0xc6d: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_c70:
	/* 0xc70: jns    c97 <generic_lsm_process_event+0xc97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_c97;
	}
x86_l_c72:
	/* 0xc72: mov    DWORD PTR [rcx+rsi*4+0x5ea0],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 104045582745599ULL);
x86_l_c7d:
	/* 0xc7d: mov    DWORD PTR [rcx+rbp*1+0x90],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 622770257919ULL);
x86_l_c88:
	/* 0xc88: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_c8d:
	/* 0xc8d: jmp    ca5 <generic_lsm_process_event+0xca5> */
	goto x86_l_ca5;
x86_l_c8f:
	/* 0xc8f: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c92:
	/* 0xc92: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c97:
	/* 0xc97: and    r15d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_c9e:
	/* 0xc9e: add    r15d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_ca2:
	/* 0xca2: mov    edx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_32);
x86_l_ca5:
	/* 0xca5: add    edx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ca7:
	/* 0xca7: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_ca9:
	/* 0xca9: mov    DWORD PTR [r14+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_cad:
	/* 0xcad: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_cb1:
	/* 0xcb1: jg     d22 <generic_lsm_process_event+0xd22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d22;
	}
x86_l_cb3:
	/* 0xcb3: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_cbb:
	/* 0xcbb: mov    rdi,QWORD PTR [rip+0x1cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_cc2:
	/* 0xcc2: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_cc7:
	/* 0xcc7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ccc:
	/* 0xccc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cce:
	/* 0xcce: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cd1:
	/* 0xcd1: je     d22 <generic_lsm_process_event+0xd22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d22;
	}
x86_l_cd3:
	/* 0xcd3: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_cd6:
	/* 0xcd6: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_cdd:
	/* 0xcdd: mov    rdi,QWORD PTR [rip+0x1cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_ce4:
	/* 0xce4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ce9:
	/* 0xce9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ceb:
	/* 0xceb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cee:
	/* 0xcee: je     d22 <generic_lsm_process_event+0xd22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d22;
	}
x86_l_cf0:
	/* 0xcf0: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_cf3:
	/* 0xcf3: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_cf6:
	/* 0xcf6: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_cf9:
	/* 0xcf9: cmp    DWORD PTR [rax+rcx*4+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 279172874239ULL);
x86_l_cfe:
	/* 0xcfe: je     d22 <generic_lsm_process_event+0xd22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d22;
	}
x86_l_d00:
	/* 0xd00: mov    DWORD PTR [r14+0x5efc],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24316ULL);
x86_l_d07:
	/* 0xd07: mov    rsi,QWORD PTR [rip+0x1cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&lsm_calls)));
x86_l_d0e:
	/* 0xd0e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d13:
	/* 0xd13: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_d18:
	/* 0xd18: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_d1b:
	/* 0xd1b: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_d20:
	/* 0xd20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d22:
	/* 0xd22: mov    DWORD PTR [r14+0x5efc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104436424769536ULL);
x86_l_d2d:
	/* 0xd2d: mov    rsi,QWORD PTR [rip+0x1d4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&lsm_calls)));
x86_l_d34:
	/* 0xd34: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_d39:
	/* 0xd39: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_d3e:
	/* 0xd3e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_d41:
	/* 0xd41: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_d46:
	/* 0xd46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d48:
	/* 0xd48: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d4a:
	/* 0xd4a: add    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 264ULL);
x86_l_d51:
	/* 0xd51: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_d52:
	/* 0xd52: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_d54:
	/* 0xd54: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_d56:
	/* 0xd56: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_d58:
	/* 0xd58: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_d5a:
	/* 0xd5a: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_d5b:
	/* 0xd5b: jmp    398b <__do_bytes+0xc4> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_d60:
	/* 0xd60: cmp    r13d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 9ULL);
x86_l_d64:
	/* 0xd64: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d69:
	/* 0xd69: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d6e:
	/* 0xd6e: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d72:
	/* 0xd72: jg     f01 <generic_lsm_process_event+0xf01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3841ULL;
	}
x86_l_d78:
	/* 0xd78: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_d7c:
	/* 0xd7c: jle    118c <generic_lsm_process_event+0x118c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4492ULL;
	}
x86_l_d82:
	/* 0xd82: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_d86:
	/* 0xd86: je     174e <generic_lsm_process_event+0x174e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5966ULL;
	}
x86_l_d8c:
	/* 0xd8c: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_d90:
	/* 0xd90: je     f61 <generic_lsm_process_event+0xf61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3937ULL;
	}
x86_l_d96:
	/* 0xd96: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d9b:
	/* 0xd9b: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_d9f:
	/* 0xd9f: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_da4:
	/* 0xda4: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_da8:
	/* 0xda8: jne    c6d <generic_lsm_process_event+0xc6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c6d;
	}
x86_l_dae:
	/* 0xdae: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_db3:
	/* 0xdb3: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_db8:
	/* 0xdb8: mov    QWORD PTR [r13+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_dbc:
	/* 0xdbc: lea    rdi,[r13+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_dc0:
	/* 0xdc0: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dc4:
	/* 0xdc4: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_dc9:
	/* 0xdc9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_dce:
	/* 0xdce: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_dd3:
	/* 0xdd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dd5:
	/* 0xdd5: lea    rdi,[r13+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_dd9:
	/* 0xdd9: lea    rdx,[r15+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_ddd:
	/* 0xddd: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_de2:
	/* 0xde2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_de7:
	/* 0xde7: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_dec:
	/* 0xdec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dee:
	/* 0xdee: lea    rdi,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_df2:
	/* 0xdf2: lea    rdx,[r15+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_df9:
	/* 0xdf9: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_dfe:
	/* 0xdfe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e03:
	/* 0xe03: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e08:
	/* 0xe08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e0a:
	/* 0xe0a: lea    rdi,[r13+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
	return 3598ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3598ULL: goto x86_l_e0e;
	case 3605ULL: goto x86_l_e15;
	case 3610ULL: goto x86_l_e1a;
	case 3615ULL: goto x86_l_e1f;
	case 3620ULL: goto x86_l_e24;
	case 3622ULL: goto x86_l_e26;
	case 3626ULL: goto x86_l_e2a;
	case 3633ULL: goto x86_l_e31;
	case 3638ULL: goto x86_l_e36;
	case 3643ULL: goto x86_l_e3b;
	case 3648ULL: goto x86_l_e40;
	case 3650ULL: goto x86_l_e42;
	case 3654ULL: goto x86_l_e46;
	case 3661ULL: goto x86_l_e4d;
	case 3666ULL: goto x86_l_e52;
	case 3671ULL: goto x86_l_e57;
	case 3676ULL: goto x86_l_e5c;
	case 3678ULL: goto x86_l_e5e;
	case 3682ULL: goto x86_l_e62;
	case 3690ULL: goto x86_l_e6a;
	case 3698ULL: goto x86_l_e72;
	case 3706ULL: goto x86_l_e7a;
	case 3714ULL: goto x86_l_e82;
	case 3719ULL: goto x86_l_e87;
	case 3722ULL: goto x86_l_e8a;
	case 3728ULL: goto x86_l_e90;
	case 3731ULL: goto x86_l_e93;
	case 3737ULL: goto x86_l_e99;
	case 3741ULL: goto x86_l_e9d;
	case 3746ULL: goto x86_l_ea2;
	case 3751ULL: goto x86_l_ea7;
	case 3754ULL: goto x86_l_eaa;
	case 3759ULL: goto x86_l_eaf;
	case 3761ULL: goto x86_l_eb1;
	case 3766ULL: goto x86_l_eb6;
	case 3771ULL: goto x86_l_ebb;
	case 3774ULL: goto x86_l_ebe;
	case 3779ULL: goto x86_l_ec3;
	case 3782ULL: goto x86_l_ec6;
	case 3787ULL: goto x86_l_ecb;
	case 3791ULL: goto x86_l_ecf;
	case 3797ULL: goto x86_l_ed5;
	case 3801ULL: goto x86_l_ed9;
	case 3807ULL: goto x86_l_edf;
	case 3811ULL: goto x86_l_ee3;
	case 3817ULL: goto x86_l_ee9;
	case 3821ULL: goto x86_l_eed;
	case 3826ULL: goto x86_l_ef2;
	case 3830ULL: goto x86_l_ef6;
	case 3836ULL: goto x86_l_efc;
	case 3841ULL: goto x86_l_f01;
	case 3845ULL: goto x86_l_f05;
	case 3848ULL: goto x86_l_f08;
	case 3854ULL: goto x86_l_f0e;
	case 3858ULL: goto x86_l_f12;
	case 3861ULL: goto x86_l_f15;
	case 3867ULL: goto x86_l_f1b;
	case 3871ULL: goto x86_l_f1f;
	case 3877ULL: goto x86_l_f25;
	case 3882ULL: goto x86_l_f2a;
	case 3887ULL: goto x86_l_f2f;
	case 3892ULL: goto x86_l_f34;
	case 3897ULL: goto x86_l_f39;
	case 3902ULL: goto x86_l_f3e;
	case 3905ULL: goto x86_l_f41;
	case 3907ULL: goto x86_l_f43;
	case 3912ULL: goto x86_l_f48;
	case 3917ULL: goto x86_l_f4d;
	case 3922ULL: goto x86_l_f52;
	case 3927ULL: goto x86_l_f57;
	case 3930ULL: goto x86_l_f5a;
	case 3935ULL: goto x86_l_f5f;
	case 3937ULL: goto x86_l_f61;
	case 3942ULL: goto x86_l_f66;
	case 3947ULL: goto x86_l_f6b;
	case 3951ULL: goto x86_l_f6f;
	case 3956ULL: goto x86_l_f74;
	case 3961ULL: goto x86_l_f79;
	case 3966ULL: goto x86_l_f7e;
	case 3971ULL: goto x86_l_f83;
	case 3975ULL: goto x86_l_f87;
	case 3980ULL: goto x86_l_f8c;
	case 3986ULL: goto x86_l_f92;
	case 3989ULL: goto x86_l_f95;
	case 3993ULL: goto x86_l_f99;
	case 3996ULL: goto x86_l_f9c;
	case 4002ULL: goto x86_l_fa2;
	case 4008ULL: goto x86_l_fa8;
	case 4013ULL: goto x86_l_fad;
	case 4018ULL: goto x86_l_fb2;
	case 4023ULL: goto x86_l_fb7;
	case 4028ULL: goto x86_l_fbc;
	case 4031ULL: goto x86_l_fbf;
	case 4036ULL: goto x86_l_fc4;
	case 4040ULL: goto x86_l_fc8;
	case 4046ULL: goto x86_l_fce;
	case 4050ULL: goto x86_l_fd2;
	case 4056ULL: goto x86_l_fd8;
	case 4060ULL: goto x86_l_fdc;
	case 4064ULL: goto x86_l_fe0;
	case 4070ULL: goto x86_l_fe6;
	case 4075ULL: goto x86_l_feb;
	case 4080ULL: goto x86_l_ff0;
	case 4085ULL: goto x86_l_ff5;
	case 4093ULL: goto x86_l_ffd;
	case 4101ULL: goto x86_l_1005;
	case 4109ULL: goto x86_l_100d;
	case 4117ULL: goto x86_l_1015;
	case 4125ULL: goto x86_l_101d;
	case 4133ULL: goto x86_l_1025;
	case 4141ULL: goto x86_l_102d;
	case 4149ULL: goto x86_l_1035;
	case 4157ULL: goto x86_l_103d;
	case 4165ULL: goto x86_l_1045;
	case 4173ULL: goto x86_l_104d;
	case 4181ULL: goto x86_l_1055;
	case 4189ULL: goto x86_l_105d;
	case 4196ULL: goto x86_l_1064;
	case 4201ULL: goto x86_l_1069;
	case 4206ULL: goto x86_l_106e;
	case 4211ULL: goto x86_l_1073;
	case 4214ULL: goto x86_l_1076;
	case 4216ULL: goto x86_l_1078;
	case 4219ULL: goto x86_l_107b;
	case 4225ULL: goto x86_l_1081;
	case 4229ULL: goto x86_l_1085;
	case 4234ULL: goto x86_l_108a;
	case 4239ULL: goto x86_l_108f;
	case 4244ULL: goto x86_l_1094;
	case 4249ULL: goto x86_l_1099;
	case 4252ULL: goto x86_l_109c;
	case 4254ULL: goto x86_l_109e;
	case 4257ULL: goto x86_l_10a1;
	case 4263ULL: goto x86_l_10a7;
	case 4268ULL: goto x86_l_10ac;
	case 4272ULL: goto x86_l_10b0;
	case 4277ULL: goto x86_l_10b5;
	case 4281ULL: goto x86_l_10b9;
	case 4287ULL: goto x86_l_10bf;
	case 4292ULL: goto x86_l_10c4;
	case 4297ULL: goto x86_l_10c9;
	case 4302ULL: goto x86_l_10ce;
	case 4305ULL: goto x86_l_10d1;
	case 4307ULL: goto x86_l_10d3;
	case 4309ULL: goto x86_l_10d5;
	case 4314ULL: goto x86_l_10da;
	case 4319ULL: goto x86_l_10df;
	case 4325ULL: goto x86_l_10e5;
	case 4327ULL: goto x86_l_10e7;
	case 4332ULL: goto x86_l_10ec;
	case 4336ULL: goto x86_l_10f0;
	case 4342ULL: goto x86_l_10f6;
	case 4345ULL: goto x86_l_10f9;
	case 4349ULL: goto x86_l_10fd;
	case 4355ULL: goto x86_l_1103;
	case 4360ULL: goto x86_l_1108;
	case 4364ULL: goto x86_l_110c;
	case 4369ULL: goto x86_l_1111;
	case 4373ULL: goto x86_l_1115;
	case 4379ULL: goto x86_l_111b;
	case 4382ULL: goto x86_l_111e;
	case 4387ULL: goto x86_l_1123;
	case 4394ULL: goto x86_l_112a;
	case 4399ULL: goto x86_l_112f;
	case 4402ULL: goto x86_l_1132;
	case 4405ULL: goto x86_l_1135;
	case 4411ULL: goto x86_l_113b;
	case 4414ULL: goto x86_l_113e;
	case 4420ULL: goto x86_l_1144;
	case 4423ULL: goto x86_l_1147;
	case 4429ULL: goto x86_l_114d;
	case 4432ULL: goto x86_l_1150;
	case 4438ULL: goto x86_l_1156;
	case 4443ULL: goto x86_l_115b;
	case 4449ULL: goto x86_l_1161;
	case 4454ULL: goto x86_l_1166;
	case 4459ULL: goto x86_l_116b;
	case 4465ULL: goto x86_l_1171;
	case 4470ULL: goto x86_l_1176;
	case 4475ULL: goto x86_l_117b;
	case 4480ULL: goto x86_l_1180;
	case 4485ULL: goto x86_l_1185;
	case 4487ULL: goto x86_l_1187;
	case 4492ULL: goto x86_l_118c;
	case 4496ULL: goto x86_l_1190;
	case 4498ULL: goto x86_l_1192;
	case 4502ULL: goto x86_l_1196;
	case 4508ULL: goto x86_l_119c;
	case 4514ULL: goto x86_l_11a2;
	case 4519ULL: goto x86_l_11a7;
	case 4524ULL: goto x86_l_11ac;
	case 4529ULL: goto x86_l_11b1;
	case 4534ULL: goto x86_l_11b6;
	case 4539ULL: goto x86_l_11bb;
	case 4541ULL: goto x86_l_11bd;
	case 4546ULL: goto x86_l_11c2;
	case 4552ULL: goto x86_l_11c8;
	case 4557ULL: goto x86_l_11cd;
	case 4562ULL: goto x86_l_11d2;
	case 4567ULL: goto x86_l_11d7;
	case 4572ULL: goto x86_l_11dc;
	case 4574ULL: goto x86_l_11de;
	case 4578ULL: goto x86_l_11e2;
	case 4583ULL: goto x86_l_11e7;
	case 4588ULL: goto x86_l_11ec;
	case 4593ULL: goto x86_l_11f1;
	case 4597ULL: goto x86_l_11f5;
	case 4603ULL: goto x86_l_11fb;
	case 4607ULL: goto x86_l_11ff;
	case 4612ULL: goto x86_l_1204;
	case 4616ULL: goto x86_l_1208;
	case 4622ULL: goto x86_l_120e;
	case 4625ULL: goto x86_l_1211;
	case 4629ULL: goto x86_l_1215;
	case 4634ULL: goto x86_l_121a;
	case 4640ULL: goto x86_l_1220;
	case 4645ULL: goto x86_l_1225;
	case 4650ULL: goto x86_l_122a;
	case 4655ULL: goto x86_l_122f;
	case 4658ULL: goto x86_l_1232;
	case 4660ULL: goto x86_l_1234;
	case 4665ULL: goto x86_l_1239;
	case 4668ULL: goto x86_l_123c;
	case 4674ULL: goto x86_l_1242;
	case 4679ULL: goto x86_l_1247;
	case 4683ULL: goto x86_l_124b;
	case 4687ULL: goto x86_l_124f;
	case 4691ULL: goto x86_l_1253;
	case 4696ULL: goto x86_l_1258;
	case 4701ULL: goto x86_l_125d;
	case 4706ULL: goto x86_l_1262;
	case 4708ULL: goto x86_l_1264;
	case 4712ULL: goto x86_l_1268;
	case 4716ULL: goto x86_l_126c;
	case 4721ULL: goto x86_l_1271;
	case 4726ULL: goto x86_l_1276;
	case 4731ULL: goto x86_l_127b;
	case 4733ULL: goto x86_l_127d;
	case 4737ULL: goto x86_l_1281;
	case 4744ULL: goto x86_l_1288;
	case 4749ULL: goto x86_l_128d;
	case 4754ULL: goto x86_l_1292;
	case 4759ULL: goto x86_l_1297;
	case 4761ULL: goto x86_l_1299;
	case 4765ULL: goto x86_l_129d;
	case 4772ULL: goto x86_l_12a4;
	case 4777ULL: goto x86_l_12a9;
	case 4782ULL: goto x86_l_12ae;
	case 4787ULL: goto x86_l_12b3;
	case 4789ULL: goto x86_l_12b5;
	case 4793ULL: goto x86_l_12b9;
	case 4800ULL: goto x86_l_12c0;
	case 4805ULL: goto x86_l_12c5;
	case 4810ULL: goto x86_l_12ca;
	case 4812ULL: goto x86_l_12cc;
	case 4816ULL: goto x86_l_12d0;
	case 4823ULL: goto x86_l_12d7;
	case 4828ULL: goto x86_l_12dc;
	case 4833ULL: goto x86_l_12e1;
	case 4835ULL: goto x86_l_12e3;
	case 4839ULL: goto x86_l_12e7;
	case 4847ULL: goto x86_l_12ef;
	case 4855ULL: goto x86_l_12f7;
	case 4863ULL: goto x86_l_12ff;
	case 4871ULL: goto x86_l_1307;
	case 4875ULL: goto x86_l_130b;
	case 4878ULL: goto x86_l_130e;
	case 4884ULL: goto x86_l_1314;
	case 4887ULL: goto x86_l_1317;
	case 4893ULL: goto x86_l_131d;
	case 4897ULL: goto x86_l_1321;
	case 4902ULL: goto x86_l_1326;
	case 4907ULL: goto x86_l_132b;
	case 4912ULL: goto x86_l_1330;
	case 4917ULL: goto x86_l_1335;
	case 4919ULL: goto x86_l_1337;
	case 4924ULL: goto x86_l_133c;
	case 4929ULL: goto x86_l_1341;
	case 4932ULL: goto x86_l_1344;
	case 4937ULL: goto x86_l_1349;
	case 4940ULL: goto x86_l_134c;
	case 4945ULL: goto x86_l_1351;
	case 4949ULL: goto x86_l_1355;
	case 4955ULL: goto x86_l_135b;
	case 4959ULL: goto x86_l_135f;
	case 4964ULL: goto x86_l_1364;
	case 4968ULL: goto x86_l_1368;
	case 4974ULL: goto x86_l_136e;
	case 4977ULL: goto x86_l_1371;
	case 4980ULL: goto x86_l_1374;
	case 4985ULL: goto x86_l_1379;
	case 4993ULL: goto x86_l_1381;
	case 5001ULL: goto x86_l_1389;
	case 5009ULL: goto x86_l_1391;
	case 5017ULL: goto x86_l_1399;
	case 5025ULL: goto x86_l_13a1;
	case 5033ULL: goto x86_l_13a9;
	case 5041ULL: goto x86_l_13b1;
	case 5049ULL: goto x86_l_13b9;
	case 5057ULL: goto x86_l_13c1;
	case 5064ULL: goto x86_l_13c8;
	case 5068ULL: goto x86_l_13cc;
	case 5072ULL: goto x86_l_13d0;
	case 5077ULL: goto x86_l_13d5;
	case 5082ULL: goto x86_l_13da;
	case 5087ULL: goto x86_l_13df;
	case 5089ULL: goto x86_l_13e1;
	case 5092ULL: goto x86_l_13e4;
	case 5098ULL: goto x86_l_13ea;
	case 5103ULL: goto x86_l_13ef;
	case 5107ULL: goto x86_l_13f3;
	case 5112ULL: goto x86_l_13f8;
	case 5119ULL: goto x86_l_13ff;
	case 5124ULL: goto x86_l_1404;
	case 5129ULL: goto x86_l_1409;
	case 5134ULL: goto x86_l_140e;
	case 5136ULL: goto x86_l_1410;
	case 5142ULL: goto x86_l_1416;
	case 5147ULL: goto x86_l_141b;
	case 5150ULL: goto x86_l_141e;
	case 5154ULL: goto x86_l_1422;
	case 5160ULL: goto x86_l_1428;
	case 5164ULL: goto x86_l_142c;
	case 5169ULL: goto x86_l_1431;
	case 5172ULL: goto x86_l_1434;
	case 5177ULL: goto x86_l_1439;
	case 5181ULL: goto x86_l_143d;
	case 5186ULL: goto x86_l_1442;
	case 5192ULL: goto x86_l_1448;
	case 5197ULL: goto x86_l_144d;
	case 5204ULL: goto x86_l_1454;
	case 5207ULL: goto x86_l_1457;
	case 5212ULL: goto x86_l_145c;
	case 5217ULL: goto x86_l_1461;
	case 5220ULL: goto x86_l_1464;
	case 5222ULL: goto x86_l_1466;
	case 5226ULL: goto x86_l_146a;
	case 5229ULL: goto x86_l_146d;
	case 5232ULL: goto x86_l_1470;
	case 5237ULL: goto x86_l_1475;
	case 5241ULL: goto x86_l_1479;
	case 5247ULL: goto x86_l_147f;
	case 5251ULL: goto x86_l_1483;
	case 5256ULL: goto x86_l_1488;
	case 5260ULL: goto x86_l_148c;
	case 5265ULL: goto x86_l_1491;
	case 5271ULL: goto x86_l_1497;
	case 5280ULL: goto x86_l_14a0;
	case 5287ULL: goto x86_l_14a7;
	case 5292ULL: goto x86_l_14ac;
	case 5297ULL: goto x86_l_14b1;
	case 5302ULL: goto x86_l_14b6;
	case 5309ULL: goto x86_l_14bd;
	case 5314ULL: goto x86_l_14c2;
	case 5317ULL: goto x86_l_14c5;
	case 5319ULL: goto x86_l_14c7;
	case 5324ULL: goto x86_l_14cc;
	case 5329ULL: goto x86_l_14d1;
	case 5334ULL: goto x86_l_14d6;
	case 5339ULL: goto x86_l_14db;
	case 5344ULL: goto x86_l_14e0;
	case 5347ULL: goto x86_l_14e3;
	case 5352ULL: goto x86_l_14e8;
	case 5354ULL: goto x86_l_14ea;
	case 5361ULL: goto x86_l_14f1;
	case 5366ULL: goto x86_l_14f6;
	case 5371ULL: goto x86_l_14fb;
	case 5376ULL: goto x86_l_1500;
	case 5379ULL: goto x86_l_1503;
	case 5381ULL: goto x86_l_1505;
	case 5388ULL: goto x86_l_150c;
	case 5396ULL: goto x86_l_1514;
	case 5401ULL: goto x86_l_1519;
	case 5406ULL: goto x86_l_151e;
	case 5411ULL: goto x86_l_1523;
	case 5413ULL: goto x86_l_1525;
	case 5420ULL: goto x86_l_152c;
	case 5427ULL: goto x86_l_1533;
	case 5432ULL: goto x86_l_1538;
	case 5437ULL: goto x86_l_153d;
	case 5440ULL: goto x86_l_1540;
	case 5445ULL: goto x86_l_1545;
	case 5448ULL: goto x86_l_1548;
	case 5450ULL: goto x86_l_154a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e0e:
	/* 0xe0e: lea    rdx,[r15+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_e15:
	/* 0xe15: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e1a:
	/* 0xe1a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e1f:
	/* 0xe1f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e24:
	/* 0xe24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e26:
	/* 0xe26: lea    rdi,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e2a:
	/* 0xe2a: lea    rdx,[r15+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_e31:
	/* 0xe31: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e36:
	/* 0xe36: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e3b:
	/* 0xe3b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e40:
	/* 0xe40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e42:
	/* 0xe42: lea    rdi,[r13+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_e46:
	/* 0xe46: lea    rdx,[r15+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_e4d:
	/* 0xe4d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e52:
	/* 0xe52: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e57:
	/* 0xe57: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e5c:
	/* 0xe5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e5e:
	/* 0xe5e: lea    r12,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e62:
	/* 0xe62: mov    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e6a:
	/* 0xe6a: mov    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_e72:
	/* 0xe72: mov    QWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_e7a:
	/* 0xe7a: mov    QWORD PTR [r13+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_e82:
	/* 0xe82: movzx  eax,WORD PTR [r13+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_e87:
	/* 0xe87: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_e8a:
	/* 0xe8a: je     2046 <generic_lsm_process_event+0x2046> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8262ULL;
	}
x86_l_e90:
	/* 0xe90: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e93:
	/* 0xe93: jne    2076 <generic_lsm_process_event+0x2076> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8310ULL;
	}
x86_l_e99:
	/* 0xe99: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e9d:
	/* 0xe9d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ea2:
	/* 0xea2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ea7:
	/* 0xea7: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_eaa:
	/* 0xeaa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_eaf:
	/* 0xeaf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eb1:
	/* 0xeb1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_eb6:
	/* 0xeb6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ebb:
	/* 0xebb: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_ebe:
	/* 0xebe: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ec3:
	/* 0xec3: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_ec6:
	/* 0xec6: jmp    2074 <generic_lsm_process_event+0x2074> */
	return 8308ULL;
x86_l_ecb:
	/* 0xecb: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_ecf:
	/* 0xecf: jg     1166 <generic_lsm_process_event+0x1166> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1166;
	}
x86_l_ed5:
	/* 0xed5: cmp    r13d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 17ULL);
x86_l_ed9:
	/* 0xed9: je     159a <generic_lsm_process_event+0x159a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5530ULL;
	}
x86_l_edf:
	/* 0xedf: cmp    r13d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 25ULL);
x86_l_ee3:
	/* 0xee3: je     1663 <generic_lsm_process_event+0x1663> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5731ULL;
	}
x86_l_ee9:
	/* 0xee9: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_eed:
	/* 0xeed: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ef2:
	/* 0xef2: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ef6:
	/* 0xef6: je     119c <generic_lsm_process_event+0x119c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_119c;
	}
x86_l_efc:
	/* 0xefc: jmp    c6d <generic_lsm_process_event+0xc6d> */
	return 3181ULL;
x86_l_f01:
	/* 0xf01: lea    eax,[r13-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_f05:
	/* 0xf05: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f08:
	/* 0xf08: jb     119c <generic_lsm_process_event+0x119c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_119c;
	}
x86_l_f0e:
	/* 0xf0e: lea    eax,[r13-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_f12:
	/* 0xf12: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f15:
	/* 0xf15: jb     11bd <generic_lsm_process_event+0x11bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_11bd;
	}
x86_l_f1b:
	/* 0xf1b: cmp    r13d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 14ULL);
x86_l_f1f:
	/* 0xf1f: jne    c6d <generic_lsm_process_event+0xc6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3181ULL;
	}
x86_l_f25:
	/* 0xf25: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_f2a:
	/* 0xf2a: lea    r15,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f2f:
	/* 0xf2f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f34:
	/* 0xf34: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f39:
	/* 0xf39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f3e:
	/* 0xf3e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_f41:
	/* 0xf41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f43:
	/* 0xf43: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_f48:
	/* 0xf48: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_f4d:
	/* 0xf4d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f52:
	/* 0xf52: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_f57:
	/* 0xf57: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_f5a:
	/* 0xf5a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f5f:
	/* 0xf5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f61:
	/* 0xf61: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f66:
	/* 0xf66: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f6b:
	/* 0xf6b: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f6f:
	/* 0xf6f: mov    ecx,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4097ULL);
x86_l_f74:
	/* 0xf74: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_f79:
	/* 0xf79: mov    esi,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4097ULL);
x86_l_f7e:
	/* 0xf7e: jmp    1934 <generic_lsm_process_event+0x1934> */
	return 6452ULL;
x86_l_f83:
	/* 0xf83: cmp    r13d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 32ULL);
x86_l_f87:
	/* 0xf87: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f8c:
	/* 0xf8c: jle    1351 <generic_lsm_process_event+0x1351> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1351;
	}
x86_l_f92:
	/* 0xf92: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_f95:
	/* 0xf95: lea    eax,[r13-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_f99:
	/* 0xf99: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f9c:
	/* 0xf9c: jae    11ec <generic_lsm_process_event+0x11ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_11ec;
	}
x86_l_fa2:
	/* 0xfa2: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_fa8:
	/* 0xfa8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fad:
	/* 0xfad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fb2:
	/* 0xfb2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fb7:
	/* 0xfb7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fbc:
	/* 0xfbc: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_fbf:
	/* 0xfbf: jmp    1185 <generic_lsm_process_event+0x1185> */
	goto x86_l_1185;
x86_l_fc4:
	/* 0xfc4: cmp    r13d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 39ULL);
x86_l_fc8:
	/* 0xfc8: je     1912 <generic_lsm_process_event+0x1912> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6418ULL;
	}
x86_l_fce:
	/* 0xfce: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_fd2:
	/* 0xfd2: je     1953 <generic_lsm_process_event+0x1953> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6483ULL;
	}
x86_l_fd8:
	/* 0xfd8: cmp    r13d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 44ULL);
x86_l_fdc:
	/* 0xfdc: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fe0:
	/* 0xfe0: jne    c6d <generic_lsm_process_event+0xc6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3181ULL;
	}
x86_l_fe6:
	/* 0xfe6: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_feb:
	/* 0xfeb: mov    BYTE PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_ff0:
	/* 0xff0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ff5:
	/* 0xff5: mov    QWORD PTR [rdi+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_ffd:
	/* 0xffd: mov    QWORD PTR [rdi+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1005:
	/* 0x1005: mov    QWORD PTR [rdi+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_100d:
	/* 0x100d: mov    QWORD PTR [rdi+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1015:
	/* 0x1015: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_101d:
	/* 0x101d: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1025:
	/* 0x1025: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_102d:
	/* 0x102d: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1035:
	/* 0x1035: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_103d:
	/* 0x103d: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1045:
	/* 0x1045: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_104d:
	/* 0x104d: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1055:
	/* 0x1055: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_105d:
	/* 0x105d: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1064:
	/* 0x1064: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1069:
	/* 0x1069: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_106e:
	/* 0x106e: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1073:
	/* 0x1073: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1076:
	/* 0x1076: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1078:
	/* 0x1078: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_107b:
	/* 0x107b: js     236a <generic_lsm_process_event+0x236a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9066ULL;
	}
x86_l_1081:
	/* 0x1081: lea    r12,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1085:
	/* 0x1085: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_108a:
	/* 0x108a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_108f:
	/* 0x108f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1094:
	/* 0x1094: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1099:
	/* 0x1099: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_109c:
	/* 0x109c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_109e:
	/* 0x109e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10a1:
	/* 0x10a1: js     236a <generic_lsm_process_event+0x236a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9066ULL;
	}
x86_l_10a7:
	/* 0x10a7: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10ac:
	/* 0x10ac: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10b0:
	/* 0x10b0: cmp    BYTE PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_10b5:
	/* 0x10b5: sete   BYTE PTR [rax+0x2] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_RAX, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 2ULL);
x86_l_10b9:
	/* 0x10b9: je     2337 <generic_lsm_process_event+0x2337> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9015ULL;
	}
x86_l_10bf:
	/* 0x10bf: mov    ecx,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 108ULL);
x86_l_10c4:
	/* 0x10c4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_10c9:
	/* 0x10c9: mov    esi,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 108ULL);
x86_l_10ce:
	/* 0x10ce: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_10d1:
	/* 0x10d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d3:
	/* 0x10d3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10d5:
	/* 0x10d5: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10da:
	/* 0x10da: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10df:
	/* 0x10df: js     236a <generic_lsm_process_event+0x236a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9066ULL;
	}
x86_l_10e5:
	/* 0x10e5: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_10e7:
	/* 0x10e7: jmp    2362 <generic_lsm_process_event+0x2362> */
	return 9058ULL;
x86_l_10ec:
	/* 0x10ec: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_10f0:
	/* 0x10f0: jg     141b <generic_lsm_process_event+0x141b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_141b;
	}
x86_l_10f6:
	/* 0x10f6: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_10f9:
	/* 0x10f9: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_10fd:
	/* 0x10fd: je     19ea <generic_lsm_process_event+0x19ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6634ULL;
	}
x86_l_1103:
	/* 0x1103: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1108:
	/* 0x1108: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_110c:
	/* 0x110c: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1111:
	/* 0x1111: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1115:
	/* 0x1115: jne    c6d <generic_lsm_process_event+0xc6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3181ULL;
	}
x86_l_111b:
	/* 0x111b: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_111e:
	/* 0x111e: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1123:
	/* 0x1123: lea    r12,[rax+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_112a:
	/* 0x112a: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_112f:
	/* 0x112f: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1132:
	/* 0x1132: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1135:
	/* 0x1135: jle    21d3 <generic_lsm_process_event+0x21d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8659ULL;
	}
x86_l_113b:
	/* 0x113b: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_113e:
	/* 0x113e: je     2462 <generic_lsm_process_event+0x2462> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9314ULL;
	}
x86_l_1144:
	/* 0x1144: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1147:
	/* 0x1147: je     246f <generic_lsm_process_event+0x246f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9327ULL;
	}
x86_l_114d:
	/* 0x114d: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_1150:
	/* 0x1150: jne    28bc <generic_lsm_process_event+0x28bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10428ULL;
	}
x86_l_1156:
	/* 0x1156: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_115b:
	/* 0x115b: add    rax,0x5e70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24176ULL);
x86_l_1161:
	/* 0x1161: jmp    2487 <generic_lsm_process_event+0x2487> */
	return 9351ULL;
x86_l_1166:
	/* 0x1166: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_116b:
	/* 0x116b: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_1171:
	/* 0x1171: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1176:
	/* 0x1176: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_117b:
	/* 0x117b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1180:
	/* 0x1180: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1185:
	/* 0x1185: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1187:
	/* 0x1187: jmp    2255 <generic_lsm_process_event+0x2255> */
	return 8789ULL;
x86_l_118c:
	/* 0x118c: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_1190:
	/* 0x1190: je     11bd <generic_lsm_process_event+0x11bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11bd;
	}
x86_l_1192:
	/* 0x1192: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1196:
	/* 0x1196: jne    c6d <generic_lsm_process_event+0xc6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3181ULL;
	}
x86_l_119c:
	/* 0x119c: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_11a2:
	/* 0x11a2: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_11a7:
	/* 0x11a7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11ac:
	/* 0x11ac: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11b1:
	/* 0x11b1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11b6:
	/* 0x11b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11bb:
	/* 0x11bb: jmp    11dc <generic_lsm_process_event+0x11dc> */
	goto x86_l_11dc;
x86_l_11bd:
	/* 0x11bd: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_11c2:
	/* 0x11c2: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_11c8:
	/* 0x11c8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_11cd:
	/* 0x11cd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11d2:
	/* 0x11d2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11d7:
	/* 0x11d7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_11dc:
	/* 0x11dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11de:
	/* 0x11de: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11e2:
	/* 0x11e2: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11e7:
	/* 0x11e7: jmp    c6d <generic_lsm_process_event+0xc6d> */
	return 3181ULL;
x86_l_11ec:
	/* 0x11ec: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11f1:
	/* 0x11f1: cmp    r13d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 43ULL);
x86_l_11f5:
	/* 0x11f5: je     1ddc <generic_lsm_process_event+0x1ddc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7644ULL;
	}
x86_l_11fb:
	/* 0x11fb: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_11ff:
	/* 0x11ff: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1204:
	/* 0x1204: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1208:
	/* 0x1208: jne    c6d <generic_lsm_process_event+0xc6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3181ULL;
	}
x86_l_120e:
	/* 0x120e: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_1211:
	/* 0x1211: add    r8,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1215:
	/* 0x1215: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_121a:
	/* 0x121a: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_1220:
	/* 0x1220: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1225:
	/* 0x1225: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_122a:
	/* 0x122a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_122f:
	/* 0x122f: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_1232:
	/* 0x1232: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1234:
	/* 0x1234: mov    r15,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1239:
	/* 0x1239: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_123c:
	/* 0x123c: je     2416 <generic_lsm_process_event+0x2416> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9238ULL;
	}
x86_l_1242:
	/* 0x1242: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1247:
	/* 0x1247: mov    QWORD PTR [rbp+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_124b:
	/* 0x124b: lea    rdi,[rbp+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_124f:
	/* 0x124f: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1253:
	/* 0x1253: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1258:
	/* 0x1258: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_125d:
	/* 0x125d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1262:
	/* 0x1262: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1264:
	/* 0x1264: lea    rdi,[rbp+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_1268:
	/* 0x1268: lea    rdx,[r15+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_126c:
	/* 0x126c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1271:
	/* 0x1271: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1276:
	/* 0x1276: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_127b:
	/* 0x127b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_127d:
	/* 0x127d: lea    rdi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1281:
	/* 0x1281: lea    rdx,[r15+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_1288:
	/* 0x1288: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_128d:
	/* 0x128d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1292:
	/* 0x1292: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1297:
	/* 0x1297: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1299:
	/* 0x1299: lea    rdi,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_129d:
	/* 0x129d: lea    rdx,[r15+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_12a4:
	/* 0x12a4: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_12a9:
	/* 0x12a9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12ae:
	/* 0x12ae: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_12b3:
	/* 0x12b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12b5:
	/* 0x12b5: lea    rdi,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12b9:
	/* 0x12b9: lea    rdx,[r15+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_12c0:
	/* 0x12c0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12c5:
	/* 0x12c5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12ca:
	/* 0x12ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12cc:
	/* 0x12cc: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_12d0:
	/* 0x12d0: lea    rdx,[r15+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_12d7:
	/* 0x12d7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12dc:
	/* 0x12dc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12e1:
	/* 0x12e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12e3:
	/* 0x12e3: lea    r12,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12e7:
	/* 0x12e7: mov    QWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12ef:
	/* 0x12ef: mov    QWORD PTR [rbp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_12f7:
	/* 0x12f7: mov    QWORD PTR [rbp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_12ff:
	/* 0x12ff: mov    QWORD PTR [rbp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1307:
	/* 0x1307: movzx  eax,WORD PTR [rbp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_130b:
	/* 0x130b: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_130e:
	/* 0x130e: je     239d <generic_lsm_process_event+0x239d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9117ULL;
	}
x86_l_1314:
	/* 0x1314: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1317:
	/* 0x1317: jne    23cf <generic_lsm_process_event+0x23cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9167ULL;
	}
x86_l_131d:
	/* 0x131d: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1321:
	/* 0x1321: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1326:
	/* 0x1326: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_132b:
	/* 0x132b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1330:
	/* 0x1330: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1335:
	/* 0x1335: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1337:
	/* 0x1337: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_133c:
	/* 0x133c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1341:
	/* 0x1341: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1344:
	/* 0x1344: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1349:
	/* 0x1349: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_134c:
	/* 0x134c: jmp    23cd <generic_lsm_process_event+0x23cd> */
	return 9165ULL;
x86_l_1351:
	/* 0x1351: cmp    r13d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 26ULL);
x86_l_1355:
	/* 0x1355: je     1e73 <generic_lsm_process_event+0x1e73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7795ULL;
	}
x86_l_135b:
	/* 0x135b: cmp    r13d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 27ULL);
x86_l_135f:
	/* 0x135f: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1364:
	/* 0x1364: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1368:
	/* 0x1368: jne    c6d <generic_lsm_process_event+0xc6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3181ULL;
	}
x86_l_136e:
	/* 0x136e: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_1371:
	/* 0x1371: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_1374:
	/* 0x1374: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1379:
	/* 0x1379: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1381:
	/* 0x1381: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1389:
	/* 0x1389: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1391:
	/* 0x1391: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1399:
	/* 0x1399: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_13a1:
	/* 0x13a1: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_13a9:
	/* 0x13a9: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_13b1:
	/* 0x13b1: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_13b9:
	/* 0x13b9: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_13c1:
	/* 0x13c1: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13c8:
	/* 0x13c8: lea    rdi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13cc:
	/* 0x13cc: lea    rdx,[r8+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13d0:
	/* 0x13d0: mov    ecx,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 63ULL);
x86_l_13d5:
	/* 0x13d5: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_13da:
	/* 0x13da: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_13df:
	/* 0x13df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e1:
	/* 0x13e1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13e4:
	/* 0x13e4: js     2329 <generic_lsm_process_event+0x2329> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9001ULL;
	}
x86_l_13ea:
	/* 0x13ea: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13ef:
	/* 0x13ef: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_13f3:
	/* 0x13f3: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13f8:
	/* 0x13f8: add    rdx,0x348 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 840ULL);
x86_l_13ff:
	/* 0x13ff: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1404:
	/* 0x1404: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1409:
	/* 0x1409: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_140e:
	/* 0x140e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1410:
	/* 0x1410: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_1416:
	/* 0x1416: jmp    232c <generic_lsm_process_event+0x232c> */
	return 9004ULL;
x86_l_141b:
	/* 0x141b: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_141e:
	/* 0x141e: cmp    r13d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 8ULL);
x86_l_1422:
	/* 0x1422: je     1a58 <generic_lsm_process_event+0x1a58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6744ULL;
	}
x86_l_1428:
	/* 0x1428: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_142c:
	/* 0x142c: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1431:
	/* 0x1431: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_1434:
	/* 0x1434: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1439:
	/* 0x1439: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_143d:
	/* 0x143d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1442:
	/* 0x1442: jne    c6d <generic_lsm_process_event+0xc6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3181ULL;
	}
x86_l_1448:
	/* 0x1448: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_144d:
	/* 0x144d: and    r13d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1454:
	/* 0x1454: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_1457:
	/* 0x1457: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_145c:
	/* 0x145c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1461:
	/* 0x1461: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_1464:
	/* 0x1464: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1466:
	/* 0x1466: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_146a:
	/* 0x146a: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_146d:
	/* 0x146d: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_1470:
	/* 0x1470: jmp    c6d <generic_lsm_process_event+0xc6d> */
	return 3181ULL;
x86_l_1475:
	/* 0x1475: cmp    r13d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 19ULL);
x86_l_1479:
	/* 0x1479: je     1d80 <generic_lsm_process_event+0x1d80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7552ULL;
	}
x86_l_147f:
	/* 0x147f: cmp    r13d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 20ULL);
x86_l_1483:
	/* 0x1483: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1488:
	/* 0x1488: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_148c:
	/* 0x148c: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1491:
	/* 0x1491: jne    c6d <generic_lsm_process_event+0xc6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3181ULL;
	}
x86_l_1497:
	/* 0x1497: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_14a0:
	/* 0x14a0: lea    rdx,[r8+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_14a7:
	/* 0x14a7: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_14ac:
	/* 0x14ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14b1:
	/* 0x14b1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14b6:
	/* 0x14b6: lea    r15,[r8+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_14bd:
	/* 0x14bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14c2:
	/* 0x14c2: mov    r12,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_64);
x86_l_14c5:
	/* 0x14c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c7:
	/* 0x14c7: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_14cc:
	/* 0x14cc: mov    edx,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 128ULL);
x86_l_14d1:
	/* 0x14d1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_14d6:
	/* 0x14d6: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14db:
	/* 0x14db: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_14e0:
	/* 0x14e0: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_14e3:
	/* 0x14e3: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_14e8:
	/* 0x14e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14ea:
	/* 0x14ea: lea    rdi,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_14f1:
	/* 0x14f1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_14f6:
	/* 0x14f6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14fb:
	/* 0x14fb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1500:
	/* 0x1500: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1503:
	/* 0x1503: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1505:
	/* 0x1505: lea    rdi,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_150c:
	/* 0x150c: lea    rdx,[r12+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1514:
	/* 0x1514: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1519:
	/* 0x1519: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_151e:
	/* 0x151e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1523:
	/* 0x1523: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1525:
	/* 0x1525: add    r13,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_152c:
	/* 0x152c: add    r12,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_1533:
	/* 0x1533: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1538:
	/* 0x1538: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_153d:
	/* 0x153d: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1540:
	/* 0x1540: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1545:
	/* 0x1545: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1548:
	/* 0x1548: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_154a:
	/* 0x154a: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 5454ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5454ULL: goto x86_l_154e;
	case 5459ULL: goto x86_l_1553;
	case 5464ULL: goto x86_l_1558;
	case 5470ULL: goto x86_l_155e;
	case 5475ULL: goto x86_l_1563;
	case 5479ULL: goto x86_l_1567;
	case 5483ULL: goto x86_l_156b;
	case 5489ULL: goto x86_l_1571;
	case 5494ULL: goto x86_l_1576;
	case 5497ULL: goto x86_l_1579;
	case 5500ULL: goto x86_l_157c;
	case 5503ULL: goto x86_l_157f;
	case 5509ULL: goto x86_l_1585;
	case 5514ULL: goto x86_l_158a;
	case 5518ULL: goto x86_l_158e;
	case 5520ULL: goto x86_l_1590;
	case 5525ULL: goto x86_l_1595;
	case 5530ULL: goto x86_l_159a;
	case 5539ULL: goto x86_l_15a3;
	case 5544ULL: goto x86_l_15a8;
	case 5546ULL: goto x86_l_15aa;
	case 5550ULL: goto x86_l_15ae;
	case 5555ULL: goto x86_l_15b3;
	case 5563ULL: goto x86_l_15bb;
	case 5568ULL: goto x86_l_15c0;
	case 5573ULL: goto x86_l_15c5;
	case 5578ULL: goto x86_l_15ca;
	case 5584ULL: goto x86_l_15d0;
	case 5589ULL: goto x86_l_15d5;
	case 5591ULL: goto x86_l_15d7;
	case 5598ULL: goto x86_l_15de;
	case 5602ULL: goto x86_l_15e2;
	case 5609ULL: goto x86_l_15e9;
	case 5614ULL: goto x86_l_15ee;
	case 5619ULL: goto x86_l_15f3;
	case 5621ULL: goto x86_l_15f5;
	case 5624ULL: goto x86_l_15f8;
	case 5630ULL: goto x86_l_15fe;
	case 5633ULL: goto x86_l_1601;
	case 5641ULL: goto x86_l_1609;
	case 5644ULL: goto x86_l_160c;
	case 5649ULL: goto x86_l_1611;
	case 5654ULL: goto x86_l_1616;
	case 5657ULL: goto x86_l_1619;
	case 5662ULL: goto x86_l_161e;
	case 5664ULL: goto x86_l_1620;
	case 5671ULL: goto x86_l_1627;
	case 5675ULL: goto x86_l_162b;
	case 5679ULL: goto x86_l_162f;
	case 5684ULL: goto x86_l_1634;
	case 5687ULL: goto x86_l_1637;
	case 5689ULL: goto x86_l_1639;
	case 5693ULL: goto x86_l_163d;
	case 5697ULL: goto x86_l_1641;
	case 5701ULL: goto x86_l_1645;
	case 5705ULL: goto x86_l_1649;
	case 5710ULL: goto x86_l_164e;
	case 5715ULL: goto x86_l_1653;
	case 5717ULL: goto x86_l_1655;
	case 5721ULL: goto x86_l_1659;
	case 5726ULL: goto x86_l_165e;
	case 5731ULL: goto x86_l_1663;
	case 5734ULL: goto x86_l_1666;
	case 5739ULL: goto x86_l_166b;
	case 5747ULL: goto x86_l_1673;
	case 5752ULL: goto x86_l_1678;
	case 5757ULL: goto x86_l_167d;
	case 5762ULL: goto x86_l_1682;
	case 5765ULL: goto x86_l_1685;
	case 5767ULL: goto x86_l_1687;
	case 5775ULL: goto x86_l_168f;
	case 5777ULL: goto x86_l_1691;
	case 5783ULL: goto x86_l_1697;
	case 5786ULL: goto x86_l_169a;
	case 5792ULL: goto x86_l_16a0;
	case 5796ULL: goto x86_l_16a4;
	case 5801ULL: goto x86_l_16a9;
	case 5807ULL: goto x86_l_16af;
	case 5812ULL: goto x86_l_16b4;
	case 5817ULL: goto x86_l_16b9;
	case 5822ULL: goto x86_l_16be;
	case 5825ULL: goto x86_l_16c1;
	case 5827ULL: goto x86_l_16c3;
	case 5832ULL: goto x86_l_16c8;
	case 5840ULL: goto x86_l_16d0;
	case 5845ULL: goto x86_l_16d5;
	case 5850ULL: goto x86_l_16da;
	case 5855ULL: goto x86_l_16df;
	case 5857ULL: goto x86_l_16e1;
	case 5862ULL: goto x86_l_16e6;
	case 5866ULL: goto x86_l_16ea;
	case 5871ULL: goto x86_l_16ef;
	case 5876ULL: goto x86_l_16f4;
	case 5881ULL: goto x86_l_16f9;
	case 5886ULL: goto x86_l_16fe;
	case 5888ULL: goto x86_l_1700;
	case 5896ULL: goto x86_l_1708;
	case 5901ULL: goto x86_l_170d;
	case 5906ULL: goto x86_l_1712;
	case 5910ULL: goto x86_l_1716;
	case 5917ULL: goto x86_l_171d;
	case 5922ULL: goto x86_l_1722;
	case 5928ULL: goto x86_l_1728;
	case 5935ULL: goto x86_l_172f;
	case 5941ULL: goto x86_l_1735;
	case 5948ULL: goto x86_l_173c;
	case 5952ULL: goto x86_l_1740;
	case 5955ULL: goto x86_l_1743;
	case 5958ULL: goto x86_l_1746;
	case 5961ULL: goto x86_l_1749;
	case 5966ULL: goto x86_l_174e;
	case 5971ULL: goto x86_l_1753;
	case 5976ULL: goto x86_l_1758;
	case 5981ULL: goto x86_l_175d;
	case 5985ULL: goto x86_l_1761;
	case 5993ULL: goto x86_l_1769;
	case 5998ULL: goto x86_l_176e;
	case 6003ULL: goto x86_l_1773;
	case 6008ULL: goto x86_l_1778;
	case 6010ULL: goto x86_l_177a;
	case 6014ULL: goto x86_l_177e;
	case 6019ULL: goto x86_l_1783;
	case 6024ULL: goto x86_l_1788;
	case 6029ULL: goto x86_l_178d;
	case 6034ULL: goto x86_l_1792;
	case 6036ULL: goto x86_l_1794;
	case 6040ULL: goto x86_l_1798;
	case 6048ULL: goto x86_l_17a0;
	case 6053ULL: goto x86_l_17a5;
	case 6058ULL: goto x86_l_17aa;
	case 6063ULL: goto x86_l_17af;
	case 6065ULL: goto x86_l_17b1;
	case 6069ULL: goto x86_l_17b5;
	case 6077ULL: goto x86_l_17bd;
	case 6082ULL: goto x86_l_17c2;
	case 6087ULL: goto x86_l_17c7;
	case 6092ULL: goto x86_l_17cc;
	case 6094ULL: goto x86_l_17ce;
	case 6103ULL: goto x86_l_17d7;
	case 6111ULL: goto x86_l_17df;
	case 6116ULL: goto x86_l_17e4;
	case 6121ULL: goto x86_l_17e9;
	case 6126ULL: goto x86_l_17ee;
	case 6131ULL: goto x86_l_17f3;
	case 6133ULL: goto x86_l_17f5;
	case 6141ULL: goto x86_l_17fd;
	case 6149ULL: goto x86_l_1805;
	case 6154ULL: goto x86_l_180a;
	case 6159ULL: goto x86_l_180f;
	case 6164ULL: goto x86_l_1814;
	case 6166ULL: goto x86_l_1816;
	case 6175ULL: goto x86_l_181f;
	case 6180ULL: goto x86_l_1824;
	case 6188ULL: goto x86_l_182c;
	case 6193ULL: goto x86_l_1831;
	case 6198ULL: goto x86_l_1836;
	case 6203ULL: goto x86_l_183b;
	case 6206ULL: goto x86_l_183e;
	case 6208ULL: goto x86_l_1840;
	case 6216ULL: goto x86_l_1848;
	case 6219ULL: goto x86_l_184b;
	case 6222ULL: goto x86_l_184e;
	case 6228ULL: goto x86_l_1854;
	case 6231ULL: goto x86_l_1857;
	case 6237ULL: goto x86_l_185d;
	case 6241ULL: goto x86_l_1861;
	case 6249ULL: goto x86_l_1869;
	case 6254ULL: goto x86_l_186e;
	case 6259ULL: goto x86_l_1873;
	case 6264ULL: goto x86_l_1878;
	case 6266ULL: goto x86_l_187a;
	case 6274ULL: goto x86_l_1882;
	case 6279ULL: goto x86_l_1887;
	case 6283ULL: goto x86_l_188b;
	case 6289ULL: goto x86_l_1891;
	case 6293ULL: goto x86_l_1895;
	case 6300ULL: goto x86_l_189c;
	case 6308ULL: goto x86_l_18a4;
	case 6316ULL: goto x86_l_18ac;
	case 6324ULL: goto x86_l_18b4;
	case 6329ULL: goto x86_l_18b9;
	case 6334ULL: goto x86_l_18be;
	case 6338ULL: goto x86_l_18c2;
	case 6343ULL: goto x86_l_18c7;
	case 6345ULL: goto x86_l_18c9;
	case 6349ULL: goto x86_l_18cd;
	case 6354ULL: goto x86_l_18d2;
	case 6359ULL: goto x86_l_18d7;
	case 6362ULL: goto x86_l_18da;
	case 6367ULL: goto x86_l_18df;
	case 6370ULL: goto x86_l_18e2;
	case 6372ULL: goto x86_l_18e4;
	case 6380ULL: goto x86_l_18ec;
	case 6388ULL: goto x86_l_18f4;
	case 6393ULL: goto x86_l_18f9;
	case 6398ULL: goto x86_l_18fe;
	case 6403ULL: goto x86_l_1903;
	case 6405ULL: goto x86_l_1905;
	case 6413ULL: goto x86_l_190d;
	case 6418ULL: goto x86_l_1912;
	case 6423ULL: goto x86_l_1917;
	case 6428ULL: goto x86_l_191c;
	case 6433ULL: goto x86_l_1921;
	case 6437ULL: goto x86_l_1925;
	case 6442ULL: goto x86_l_192a;
	case 6447ULL: goto x86_l_192f;
	case 6452ULL: goto x86_l_1934;
	case 6454ULL: goto x86_l_1936;
	case 6457ULL: goto x86_l_1939;
	case 6460ULL: goto x86_l_193c;
	case 6466ULL: goto x86_l_1942;
	case 6470ULL: goto x86_l_1946;
	case 6474ULL: goto x86_l_194a;
	case 6478ULL: goto x86_l_194e;
	case 6483ULL: goto x86_l_1953;
	case 6488ULL: goto x86_l_1958;
	case 6493ULL: goto x86_l_195d;
	case 6501ULL: goto x86_l_1965;
	case 6509ULL: goto x86_l_196d;
	case 6517ULL: goto x86_l_1975;
	case 6522ULL: goto x86_l_197a;
	case 6527ULL: goto x86_l_197f;
	case 6530ULL: goto x86_l_1982;
	case 6535ULL: goto x86_l_1987;
	case 6538ULL: goto x86_l_198a;
	case 6540ULL: goto x86_l_198c;
	case 6543ULL: goto x86_l_198f;
	case 6549ULL: goto x86_l_1995;
	case 6554ULL: goto x86_l_199a;
	case 6557ULL: goto x86_l_199d;
	case 6563ULL: goto x86_l_19a3;
	case 6566ULL: goto x86_l_19a6;
	case 6572ULL: goto x86_l_19ac;
	case 6576ULL: goto x86_l_19b0;
	case 6581ULL: goto x86_l_19b5;
	case 6586ULL: goto x86_l_19ba;
	case 6591ULL: goto x86_l_19bf;
	case 6596ULL: goto x86_l_19c4;
	case 6598ULL: goto x86_l_19c6;
	case 6602ULL: goto x86_l_19ca;
	case 6607ULL: goto x86_l_19cf;
	case 6611ULL: goto x86_l_19d3;
	case 6615ULL: goto x86_l_19d7;
	case 6619ULL: goto x86_l_19db;
	case 6624ULL: goto x86_l_19e0;
	case 6629ULL: goto x86_l_19e5;
	case 6634ULL: goto x86_l_19ea;
	case 6639ULL: goto x86_l_19ef;
	case 6644ULL: goto x86_l_19f4;
	case 6647ULL: goto x86_l_19f7;
	case 6651ULL: goto x86_l_19fb;
	case 6658ULL: goto x86_l_1a02;
	case 6670ULL: goto x86_l_1a0e;
	case 6675ULL: goto x86_l_1a13;
	case 6681ULL: goto x86_l_1a19;
	case 6686ULL: goto x86_l_1a1e;
	case 6688ULL: goto x86_l_1a20;
	case 6691ULL: goto x86_l_1a23;
	case 6693ULL: goto x86_l_1a25;
	case 6696ULL: goto x86_l_1a28;
	case 6699ULL: goto x86_l_1a2b;
	case 6705ULL: goto x86_l_1a31;
	case 6708ULL: goto x86_l_1a34;
	case 6714ULL: goto x86_l_1a3a;
	case 6717ULL: goto x86_l_1a3d;
	case 6723ULL: goto x86_l_1a43;
	case 6726ULL: goto x86_l_1a46;
	case 6732ULL: goto x86_l_1a4c;
	case 6739ULL: goto x86_l_1a53;
	case 6744ULL: goto x86_l_1a58;
	case 6749ULL: goto x86_l_1a5d;
	case 6753ULL: goto x86_l_1a61;
	case 6757ULL: goto x86_l_1a65;
	case 6762ULL: goto x86_l_1a6a;
	case 6767ULL: goto x86_l_1a6f;
	case 6772ULL: goto x86_l_1a74;
	case 6777ULL: goto x86_l_1a79;
	case 6782ULL: goto x86_l_1a7e;
	case 6785ULL: goto x86_l_1a81;
	case 6790ULL: goto x86_l_1a86;
	case 6792ULL: goto x86_l_1a88;
	case 6796ULL: goto x86_l_1a8c;
	case 6801ULL: goto x86_l_1a91;
	case 6806ULL: goto x86_l_1a96;
	case 6811ULL: goto x86_l_1a9b;
	case 6816ULL: goto x86_l_1aa0;
	case 6818ULL: goto x86_l_1aa2;
	case 6822ULL: goto x86_l_1aa6;
	case 6827ULL: goto x86_l_1aab;
	case 6832ULL: goto x86_l_1ab0;
	case 6837ULL: goto x86_l_1ab5;
	case 6842ULL: goto x86_l_1aba;
	case 6844ULL: goto x86_l_1abc;
	case 6848ULL: goto x86_l_1ac0;
	case 6853ULL: goto x86_l_1ac5;
	case 6858ULL: goto x86_l_1aca;
	case 6863ULL: goto x86_l_1acf;
	case 6868ULL: goto x86_l_1ad4;
	case 6870ULL: goto x86_l_1ad6;
	case 6874ULL: goto x86_l_1ada;
	case 6879ULL: goto x86_l_1adf;
	case 6884ULL: goto x86_l_1ae4;
	case 6889ULL: goto x86_l_1ae9;
	case 6894ULL: goto x86_l_1aee;
	case 6896ULL: goto x86_l_1af0;
	case 6900ULL: goto x86_l_1af4;
	case 6905ULL: goto x86_l_1af9;
	case 6910ULL: goto x86_l_1afe;
	case 6915ULL: goto x86_l_1b03;
	case 6920ULL: goto x86_l_1b08;
	case 6922ULL: goto x86_l_1b0a;
	case 6926ULL: goto x86_l_1b0e;
	case 6931ULL: goto x86_l_1b13;
	case 6936ULL: goto x86_l_1b18;
	case 6941ULL: goto x86_l_1b1d;
	case 6946ULL: goto x86_l_1b22;
	case 6948ULL: goto x86_l_1b24;
	case 6952ULL: goto x86_l_1b28;
	case 6957ULL: goto x86_l_1b2d;
	case 6962ULL: goto x86_l_1b32;
	case 6967ULL: goto x86_l_1b37;
	case 6972ULL: goto x86_l_1b3c;
	case 6974ULL: goto x86_l_1b3e;
	case 6982ULL: goto x86_l_1b46;
	case 6986ULL: goto x86_l_1b4a;
	case 6991ULL: goto x86_l_1b4f;
	case 6996ULL: goto x86_l_1b54;
	case 7001ULL: goto x86_l_1b59;
	case 7006ULL: goto x86_l_1b5e;
	case 7008ULL: goto x86_l_1b60;
	case 7012ULL: goto x86_l_1b64;
	case 7017ULL: goto x86_l_1b69;
	case 7022ULL: goto x86_l_1b6e;
	case 7027ULL: goto x86_l_1b73;
	case 7032ULL: goto x86_l_1b78;
	case 7034ULL: goto x86_l_1b7a;
	case 7038ULL: goto x86_l_1b7e;
	case 7043ULL: goto x86_l_1b83;
	case 7048ULL: goto x86_l_1b88;
	case 7053ULL: goto x86_l_1b8d;
	case 7058ULL: goto x86_l_1b92;
	case 7060ULL: goto x86_l_1b94;
	case 7065ULL: goto x86_l_1b99;
	case 7070ULL: goto x86_l_1b9e;
	case 7075ULL: goto x86_l_1ba3;
	case 7078ULL: goto x86_l_1ba6;
	case 7083ULL: goto x86_l_1bab;
	case 7085ULL: goto x86_l_1bad;
	case 7092ULL: goto x86_l_1bb4;
	case 7097ULL: goto x86_l_1bb9;
	case 7102ULL: goto x86_l_1bbe;
	case 7107ULL: goto x86_l_1bc3;
	case 7112ULL: goto x86_l_1bc8;
	case 7115ULL: goto x86_l_1bcb;
	case 7117ULL: goto x86_l_1bcd;
	case 7122ULL: goto x86_l_1bd2;
	case 7130ULL: goto x86_l_1bda;
	case 7135ULL: goto x86_l_1bdf;
	case 7140ULL: goto x86_l_1be4;
	case 7145ULL: goto x86_l_1be9;
	case 7150ULL: goto x86_l_1bee;
	case 7152ULL: goto x86_l_1bf0;
	case 7156ULL: goto x86_l_1bf4;
	case 7164ULL: goto x86_l_1bfc;
	case 7169ULL: goto x86_l_1c01;
	case 7174ULL: goto x86_l_1c06;
	case 7179ULL: goto x86_l_1c0b;
	case 7181ULL: goto x86_l_1c0d;
	case 7185ULL: goto x86_l_1c11;
	case 7193ULL: goto x86_l_1c19;
	case 7198ULL: goto x86_l_1c1e;
	case 7203ULL: goto x86_l_1c23;
	case 7208ULL: goto x86_l_1c28;
	case 7210ULL: goto x86_l_1c2a;
	case 7214ULL: goto x86_l_1c2e;
	case 7221ULL: goto x86_l_1c35;
	case 7226ULL: goto x86_l_1c3a;
	case 7231ULL: goto x86_l_1c3f;
	case 7234ULL: goto x86_l_1c42;
	case 7239ULL: goto x86_l_1c47;
	case 7242ULL: goto x86_l_1c4a;
	case 7244ULL: goto x86_l_1c4c;
	case 7250ULL: goto x86_l_1c52;
	case 7255ULL: goto x86_l_1c57;
	default: return 0xffffffffffffffffULL;
	}
x86_l_154e:
	/* 0x154e: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1553:
	/* 0x1553: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1558:
	/* 0x1558: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_155e:
	/* 0x155e: jmp    c6d <generic_lsm_process_event+0xc6d> */
	return 3181ULL;
x86_l_1563:
	/* 0x1563: cmp    r13d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 38ULL);
x86_l_1567:
	/* 0x1567: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_156b:
	/* 0x156b: jne    c6d <generic_lsm_process_event+0xc6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3181ULL;
	}
x86_l_1571:
	/* 0x1571: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1576:
	/* 0x1576: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1579:
	/* 0x1579: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_157c:
	/* 0x157c: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_157f:
	/* 0x157f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1585:
	/* 0x1585: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_158a:
	/* 0x158a: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_158e:
	/* 0x158e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1590:
	/* 0x1590: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1595:
	/* 0x1595: jmp    1934 <generic_lsm_process_event+0x1934> */
	goto x86_l_1934;
x86_l_159a:
	/* 0x159a: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_15a3:
	/* 0x15a3: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_15a8:
	/* 0x15a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15aa:
	/* 0x15aa: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_15ae:
	/* 0x15ae: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_15b3:
	/* 0x15b3: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_15bb:
	/* 0x15bb: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15c0:
	/* 0x15c0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_15c5:
	/* 0x15c5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15ca:
	/* 0x15ca: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_15d0:
	/* 0x15d0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15d5:
	/* 0x15d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d7:
	/* 0x15d7: mov    eax,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_15de:
	/* 0x15de: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_15e2:
	/* 0x15e2: mov    rdi,QWORD PTR [rip+0x1c8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_15e9:
	/* 0x15e9: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_15ee:
	/* 0x15ee: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15f3:
	/* 0x15f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15f5:
	/* 0x15f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15f8:
	/* 0x15f8: je     1ef6 <generic_lsm_process_event+0x1ef6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7926ULL;
	}
x86_l_15fe:
	/* 0x15fe: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1601:
	/* 0x1601: lea    rdx,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1609:
	/* 0x1609: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_160c:
	/* 0x160c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1611:
	/* 0x1611: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1616:
	/* 0x1616: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1619:
	/* 0x1619: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_161e:
	/* 0x161e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1620:
	/* 0x1620: and    r15d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1627:
	/* 0x1627: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_162b:
	/* 0x162b: lea    rsi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_162f:
	/* 0x162f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1634:
	/* 0x1634: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1637:
	/* 0x1637: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1639:
	/* 0x1639: lea    rdi,[r15+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_163d:
	/* 0x163d: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1641:
	/* 0x1641: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1645:
	/* 0x1645: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1649:
	/* 0x1649: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_164e:
	/* 0x164e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1653:
	/* 0x1653: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1655:
	/* 0x1655: add    r15,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1659:
	/* 0x1659: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_165e:
	/* 0x165e: jmp    333d <generic_lsm_process_event+0x333d> */
	return 13117ULL;
x86_l_1663:
	/* 0x1663: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1666:
	/* 0x1666: mov    r12,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_166b:
	/* 0x166b: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1673:
	/* 0x1673: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1678:
	/* 0x1678: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_167d:
	/* 0x167d: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1682:
	/* 0x1682: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1685:
	/* 0x1685: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1687:
	/* 0x1687: movzx  eax,BYTE PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 192ULL);
x86_l_168f:
	/* 0x168f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1691:
	/* 0x1691: je     1f07 <generic_lsm_process_event+0x1f07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7943ULL;
	}
x86_l_1697:
	/* 0x1697: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_169a:
	/* 0x169a: jne    2104 <generic_lsm_process_event+0x2104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8452ULL;
	}
x86_l_16a0:
	/* 0x16a0: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_16a4:
	/* 0x16a4: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_16a9:
	/* 0x16a9: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_16af:
	/* 0x16af: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16b4:
	/* 0x16b4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16b9:
	/* 0x16b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16be:
	/* 0x16be: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_16c1:
	/* 0x16c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c3:
	/* 0x16c3: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_16c8:
	/* 0x16c8: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_16d0:
	/* 0x16d0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16d5:
	/* 0x16d5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16da:
	/* 0x16da: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16df:
	/* 0x16df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16e1:
	/* 0x16e1: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_16e6:
	/* 0x16e6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_16ea:
	/* 0x16ea: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_16ef:
	/* 0x16ef: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16f4:
	/* 0x16f4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16f9:
	/* 0x16f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16fe:
	/* 0x16fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1700:
	/* 0x1700: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1708:
	/* 0x1708: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_170d:
	/* 0x170d: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1712:
	/* 0x1712: lea    r14,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1716:
	/* 0x1716: add    r14,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_171d:
	/* 0x171d: test   BYTE PTR [rsp+0x30],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430240ULL);
x86_l_1722:
	/* 0x1722: je     29c8 <generic_lsm_process_event+0x29c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10696ULL;
	}
x86_l_1728:
	/* 0x1728: cmp    r13,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4096ULL);
x86_l_172f:
	/* 0x172f: jb     29a1 <generic_lsm_process_event+0x29a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10657ULL;
	}
x86_l_1735:
	/* 0x1735: mov    DWORD PTR [r14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_173c:
	/* 0x173c: add    r14,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1740:
	/* 0x1740: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1743:
	/* 0x1743: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1746:
	/* 0x1746: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1749:
	/* 0x1749: jmp    2bcc <generic_lsm_process_event+0x2bcc> */
	return 11212ULL;
x86_l_174e:
	/* 0x174e: mov    QWORD PTR [rsp+0x40],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1753:
	/* 0x1753: mov    r12,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1758:
	/* 0x1758: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_175d:
	/* 0x175d: lea    rdi,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1761:
	/* 0x1761: lea    rdx,[r12+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1769:
	/* 0x1769: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_176e:
	/* 0x176e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1773:
	/* 0x1773: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1778:
	/* 0x1778: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_177a:
	/* 0x177a: lea    rdi,[rbx+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_177e:
	/* 0x177e: lea    rdx,[r12+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1783:
	/* 0x1783: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1788:
	/* 0x1788: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_178d:
	/* 0x178d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1792:
	/* 0x1792: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1794:
	/* 0x1794: lea    rdi,[rbx+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1798:
	/* 0x1798: lea    rdx,[r12+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_17a0:
	/* 0x17a0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_17a5:
	/* 0x17a5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17aa:
	/* 0x17aa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17af:
	/* 0x17af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17b1:
	/* 0x17b1: lea    rdi,[rbx+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_17b5:
	/* 0x17b5: lea    rdx,[r12+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_17bd:
	/* 0x17bd: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_17c2:
	/* 0x17c2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17c7:
	/* 0x17c7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17cc:
	/* 0x17cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ce:
	/* 0x17ce: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_17d7:
	/* 0x17d7: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_17df:
	/* 0x17df: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_17e4:
	/* 0x17e4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17e9:
	/* 0x17e9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17ee:
	/* 0x17ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17f3:
	/* 0x17f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f5:
	/* 0x17f5: lea    rdx,[r12+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_17fd:
	/* 0x17fd: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1805:
	/* 0x1805: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_180a:
	/* 0x180a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_180f:
	/* 0x180f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1814:
	/* 0x1814: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1816:
	/* 0x1816: movzx  r15d,WORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 192ULL);
x86_l_181f:
	/* 0x181f: add    r15,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 104ULL);
x86_l_1824:
	/* 0x1824: lea    rdi,[rsp+0xbb] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 187ULL);
x86_l_182c:
	/* 0x182c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1831:
	/* 0x1831: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1836:
	/* 0x1836: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_183b:
	/* 0x183b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_183e:
	/* 0x183e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1840:
	/* 0x1840: movzx  eax,BYTE PTR [rsp+0xbb] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 187ULL);
x86_l_1848:
	/* 0x1848: shr    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_184b:
	/* 0x184b: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_184e:
	/* 0x184e: je     1f9b <generic_lsm_process_event+0x1f9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8091ULL;
	}
x86_l_1854:
	/* 0x1854: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1857:
	/* 0x1857: jne    332d <generic_lsm_process_event+0x332d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13101ULL;
	}
x86_l_185d:
	/* 0x185d: lea    rdx,[r15+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_1861:
	/* 0x1861: lea    rdi,[rsp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1869:
	/* 0x1869: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_186e:
	/* 0x186e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1873:
	/* 0x1873: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1878:
	/* 0x1878: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_187a:
	/* 0x187a: movzx  eax,BYTE PTR [rsp+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 188ULL);
x86_l_1882:
	/* 0x1882: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1887:
	/* 0x1887: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_188b:
	/* 0x188b: mov    WORD PTR [rdi+0x26],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757250ULL);
x86_l_1891:
	/* 0x1891: lea    rdx,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1895:
	/* 0x1895: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_189c:
	/* 0x189c: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_18a4:
	/* 0x18a4: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_18ac:
	/* 0x18ac: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_18b4:
	/* 0x18b4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_18b9:
	/* 0x18b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18be:
	/* 0x18be: lea    r13,[rdi+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18c2:
	/* 0x18c2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18c7:
	/* 0x18c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c9:
	/* 0x18c9: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_18cd:
	/* 0x18cd: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_18d2:
	/* 0x18d2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18d7:
	/* 0x18d7: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_18da:
	/* 0x18da: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18df:
	/* 0x18df: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_18e2:
	/* 0x18e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e4:
	/* 0x18e4: lea    rdx,[r12+0xb6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_18ec:
	/* 0x18ec: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_18f4:
	/* 0x18f4: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_18f9:
	/* 0x18f9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18fe:
	/* 0x18fe: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1903:
	/* 0x1903: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1905:
	/* 0x1905: movzx  ebp,BYTE PTR [rsp+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 188ULL);
x86_l_190d:
	/* 0x190d: jmp    31c9 <generic_lsm_process_event+0x31c9> */
	return 12745ULL;
x86_l_1912:
	/* 0x1912: mov    edx,0x120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 288ULL);
x86_l_1917:
	/* 0x1917: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_191c:
	/* 0x191c: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1921:
	/* 0x1921: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1925:
	/* 0x1925: mov    ecx,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_192a:
	/* 0x192a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_192f:
	/* 0x192f: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1934:
	/* 0x1934: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1936:
	/* 0x1936: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1939:
	/* 0x1939: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_193c:
	/* 0x193c: js     2255 <generic_lsm_process_event+0x2255> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8789ULL;
	}
x86_l_1942:
	/* 0x1942: lea    eax,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1946:
	/* 0x1946: mov    DWORD PTR [r13+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_194a:
	/* 0x194a: add    r15,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_194e:
	/* 0x194e: jmp    2255 <generic_lsm_process_event+0x2255> */
	return 8789ULL;
x86_l_1953:
	/* 0x1953: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1958:
	/* 0x1958: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_195d:
	/* 0x195d: mov    QWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1965:
	/* 0x1965: mov    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_196d:
	/* 0x196d: mov    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1975:
	/* 0x1975: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_197a:
	/* 0x197a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_197f:
	/* 0x197f: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1982:
	/* 0x1982: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1987:
	/* 0x1987: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_198a:
	/* 0x198a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_198c:
	/* 0x198c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_198f:
	/* 0x198f: js     224f <generic_lsm_process_event+0x224f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8783ULL;
	}
x86_l_1995:
	/* 0x1995: movzx  eax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_199a:
	/* 0x199a: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_199d:
	/* 0x199d: je     21f5 <generic_lsm_process_event+0x21f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8693ULL;
	}
x86_l_19a3:
	/* 0x19a3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_19a6:
	/* 0x19a6: jne    2231 <generic_lsm_process_event+0x2231> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8753ULL;
	}
x86_l_19ac:
	/* 0x19ac: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19b0:
	/* 0x19b0: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_19b5:
	/* 0x19b5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_19ba:
	/* 0x19ba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19bf:
	/* 0x19bf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19c4:
	/* 0x19c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19c6:
	/* 0x19c6: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_19ca:
	/* 0x19ca: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19cf:
	/* 0x19cf: mov    QWORD PTR [rcx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19d3:
	/* 0x19d3: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_19d7:
	/* 0x19d7: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_19db:
	/* 0x19db: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_19e0:
	/* 0x19e0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19e5:
	/* 0x19e5: jmp    2227 <generic_lsm_process_event+0x2227> */
	return 8743ULL;
x86_l_19ea:
	/* 0x19ea: mov    QWORD PTR [rsp+0x40],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19ef:
	/* 0x19ef: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_19f4:
	/* 0x19f4: mov    rbp,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_19f7:
	/* 0x19f7: lea    r12,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_19fb:
	/* 0x19fb: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1a02:
	/* 0x1a02: mov    QWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_1a0e:
	/* 0x1a0e: test   BYTE PTR [rsp+0x30],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430224ULL);
x86_l_1a13:
	/* 0x1a13: jne    2125 <generic_lsm_process_event+0x2125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8485ULL;
	}
x86_l_1a19:
	/* 0x1a19: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a1e:
	/* 0x1a1e: mov    ebx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_32);
x86_l_1a20:
	/* 0x1a20: and    edx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1a23:
	/* 0x1a23: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a25:
	/* 0x1a25: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1a28:
	/* 0x1a28: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1a2b:
	/* 0x1a2b: jle    237f <generic_lsm_process_event+0x237f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 9087ULL;
	}
x86_l_1a31:
	/* 0x1a31: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1a34:
	/* 0x1a34: je     2b52 <generic_lsm_process_event+0x2b52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11090ULL;
	}
x86_l_1a3a:
	/* 0x1a3a: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a3d:
	/* 0x1a3d: je     2b5b <generic_lsm_process_event+0x2b5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11099ULL;
	}
x86_l_1a43:
	/* 0x1a43: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1a46:
	/* 0x1a46: jne    2b6e <generic_lsm_process_event+0x2b6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11118ULL;
	}
x86_l_1a4c:
	/* 0x1a4c: lea    rax,[rbp+0x5e70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24176ULL);
x86_l_1a53:
	/* 0x1a53: jmp    2b6b <generic_lsm_process_event+0x2b6b> */
	return 11115ULL;
x86_l_1a58:
	/* 0x1a58: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a5d:
	/* 0x1a5d: lea    r13,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a61:
	/* 0x1a61: lea    rax,[r15+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a65:
	/* 0x1a65: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a6a:
	/* 0x1a6a: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a6f:
	/* 0x1a6f: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a74:
	/* 0x1a74: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a79:
	/* 0x1a79: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a7e:
	/* 0x1a7e: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1a81:
	/* 0x1a81: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a86:
	/* 0x1a86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a88:
	/* 0x1a88: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a8c:
	/* 0x1a8c: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1a91:
	/* 0x1a91: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a96:
	/* 0x1a96: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a9b:
	/* 0x1a9b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1aa0:
	/* 0x1aa0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aa2:
	/* 0x1aa2: lea    rdi,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1aa6:
	/* 0x1aa6: lea    rdx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1aab:
	/* 0x1aab: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ab0:
	/* 0x1ab0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ab5:
	/* 0x1ab5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1aba:
	/* 0x1aba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1abc:
	/* 0x1abc: lea    rdi,[r15+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1ac0:
	/* 0x1ac0: lea    rdx,[r12+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1ac5:
	/* 0x1ac5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1aca:
	/* 0x1aca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1acf:
	/* 0x1acf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ad4:
	/* 0x1ad4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad6:
	/* 0x1ad6: lea    rdi,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ada:
	/* 0x1ada: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1adf:
	/* 0x1adf: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ae4:
	/* 0x1ae4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ae9:
	/* 0x1ae9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1aee:
	/* 0x1aee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1af0:
	/* 0x1af0: lea    rdi,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1af4:
	/* 0x1af4: lea    rdx,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1af9:
	/* 0x1af9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1afe:
	/* 0x1afe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b03:
	/* 0x1b03: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b08:
	/* 0x1b08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b0a:
	/* 0x1b0a: lea    rdi,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b0e:
	/* 0x1b0e: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b13:
	/* 0x1b13: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b18:
	/* 0x1b18: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b1d:
	/* 0x1b1d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b22:
	/* 0x1b22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b24:
	/* 0x1b24: lea    rdi,[r15+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1b28:
	/* 0x1b28: lea    rdx,[r12+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1b2d:
	/* 0x1b2d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b32:
	/* 0x1b32: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b37:
	/* 0x1b37: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b3c:
	/* 0x1b3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b3e:
	/* 0x1b3e: mov    DWORD PTR [r15+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1b46:
	/* 0x1b46: lea    rdi,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b4a:
	/* 0x1b4a: lea    rdx,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b4f:
	/* 0x1b4f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b54:
	/* 0x1b54: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b59:
	/* 0x1b59: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b5e:
	/* 0x1b5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b60:
	/* 0x1b60: lea    rdi,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b64:
	/* 0x1b64: lea    rdx,[r12+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b69:
	/* 0x1b69: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b6e:
	/* 0x1b6e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b73:
	/* 0x1b73: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b78:
	/* 0x1b78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b7a:
	/* 0x1b7a: lea    rdi,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b7e:
	/* 0x1b7e: lea    rdx,[r12+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b83:
	/* 0x1b83: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b88:
	/* 0x1b88: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b8d:
	/* 0x1b8d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b92:
	/* 0x1b92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b94:
	/* 0x1b94: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b99:
	/* 0x1b99: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b9e:
	/* 0x1b9e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ba3:
	/* 0x1ba3: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1ba6:
	/* 0x1ba6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bab:
	/* 0x1bab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bad:
	/* 0x1bad: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1bb4:
	/* 0x1bb4: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1bb9:
	/* 0x1bb9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1bbe:
	/* 0x1bbe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bc3:
	/* 0x1bc3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bc8:
	/* 0x1bc8: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1bcb:
	/* 0x1bcb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bcd:
	/* 0x1bcd: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1bd2:
	/* 0x1bd2: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1bda:
	/* 0x1bda: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1bdf:
	/* 0x1bdf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1be4:
	/* 0x1be4: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1be9:
	/* 0x1be9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bee:
	/* 0x1bee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bf0:
	/* 0x1bf0: lea    rdi,[r15+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1bf4:
	/* 0x1bf4: lea    rdx,[r12+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1bfc:
	/* 0x1bfc: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c01:
	/* 0x1c01: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c06:
	/* 0x1c06: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c0b:
	/* 0x1c0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c0d:
	/* 0x1c0d: lea    rdi,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1c11:
	/* 0x1c11: lea    rdx,[r12+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1c19:
	/* 0x1c19: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c1e:
	/* 0x1c1e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c23:
	/* 0x1c23: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c28:
	/* 0x1c28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c2a:
	/* 0x1c2a: add    r15,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_1c2e:
	/* 0x1c2e: add    r12,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1c35:
	/* 0x1c35: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c3a:
	/* 0x1c3a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c3f:
	/* 0x1c3f: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1c42:
	/* 0x1c42: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c47:
	/* 0x1c47: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1c4a:
	/* 0x1c4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c4c:
	/* 0x1c4c: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_1c52:
	/* 0x1c52: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c57:
	/* 0x1c57: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
	return 7258ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7258ULL: goto x86_l_1c5a;
	case 7263ULL: goto x86_l_1c5f;
	case 7268ULL: goto x86_l_1c64;
	case 7275ULL: goto x86_l_1c6b;
	case 7280ULL: goto x86_l_1c70;
	case 7285ULL: goto x86_l_1c75;
	case 7290ULL: goto x86_l_1c7a;
	case 7293ULL: goto x86_l_1c7d;
	case 7298ULL: goto x86_l_1c82;
	case 7300ULL: goto x86_l_1c84;
	case 7304ULL: goto x86_l_1c88;
	case 7311ULL: goto x86_l_1c8f;
	case 7316ULL: goto x86_l_1c94;
	case 7321ULL: goto x86_l_1c99;
	case 7326ULL: goto x86_l_1c9e;
	case 7328ULL: goto x86_l_1ca0;
	case 7332ULL: goto x86_l_1ca4;
	case 7339ULL: goto x86_l_1cab;
	case 7344ULL: goto x86_l_1cb0;
	case 7349ULL: goto x86_l_1cb5;
	case 7354ULL: goto x86_l_1cba;
	case 7356ULL: goto x86_l_1cbc;
	case 7360ULL: goto x86_l_1cc0;
	case 7367ULL: goto x86_l_1cc7;
	case 7372ULL: goto x86_l_1ccc;
	case 7377ULL: goto x86_l_1cd1;
	case 7380ULL: goto x86_l_1cd4;
	case 7385ULL: goto x86_l_1cd9;
	case 7388ULL: goto x86_l_1cdc;
	case 7390ULL: goto x86_l_1cde;
	case 7396ULL: goto x86_l_1ce4;
	case 7401ULL: goto x86_l_1ce9;
	case 7406ULL: goto x86_l_1cee;
	case 7410ULL: goto x86_l_1cf2;
	case 7415ULL: goto x86_l_1cf7;
	case 7420ULL: goto x86_l_1cfc;
	case 7425ULL: goto x86_l_1d01;
	case 7428ULL: goto x86_l_1d04;
	case 7433ULL: goto x86_l_1d09;
	case 7435ULL: goto x86_l_1d0b;
	case 7439ULL: goto x86_l_1d0f;
	case 7443ULL: goto x86_l_1d13;
	case 7448ULL: goto x86_l_1d18;
	case 7453ULL: goto x86_l_1d1d;
	case 7458ULL: goto x86_l_1d22;
	case 7460ULL: goto x86_l_1d24;
	case 7464ULL: goto x86_l_1d28;
	case 7468ULL: goto x86_l_1d2c;
	case 7473ULL: goto x86_l_1d31;
	case 7478ULL: goto x86_l_1d36;
	case 7483ULL: goto x86_l_1d3b;
	case 7485ULL: goto x86_l_1d3d;
	case 7489ULL: goto x86_l_1d41;
	case 7493ULL: goto x86_l_1d45;
	case 7498ULL: goto x86_l_1d4a;
	case 7503ULL: goto x86_l_1d4f;
	case 7508ULL: goto x86_l_1d54;
	case 7510ULL: goto x86_l_1d56;
	case 7514ULL: goto x86_l_1d5a;
	case 7518ULL: goto x86_l_1d5e;
	case 7523ULL: goto x86_l_1d63;
	case 7528ULL: goto x86_l_1d68;
	case 7531ULL: goto x86_l_1d6b;
	case 7536ULL: goto x86_l_1d70;
	case 7539ULL: goto x86_l_1d73;
	case 7541ULL: goto x86_l_1d75;
	case 7547ULL: goto x86_l_1d7b;
	case 7552ULL: goto x86_l_1d80;
	case 7557ULL: goto x86_l_1d85;
	case 7562ULL: goto x86_l_1d8a;
	case 7567ULL: goto x86_l_1d8f;
	case 7572ULL: goto x86_l_1d94;
	case 7575ULL: goto x86_l_1d97;
	case 7580ULL: goto x86_l_1d9c;
	case 7583ULL: goto x86_l_1d9f;
	case 7585ULL: goto x86_l_1da1;
	case 7589ULL: goto x86_l_1da5;
	case 7593ULL: goto x86_l_1da9;
	case 7598ULL: goto x86_l_1dae;
	case 7603ULL: goto x86_l_1db3;
	case 7608ULL: goto x86_l_1db8;
	case 7610ULL: goto x86_l_1dba;
	case 7614ULL: goto x86_l_1dbe;
	case 7618ULL: goto x86_l_1dc2;
	case 7623ULL: goto x86_l_1dc7;
	case 7628ULL: goto x86_l_1dcc;
	case 7631ULL: goto x86_l_1dcf;
	case 7636ULL: goto x86_l_1dd4;
	case 7639ULL: goto x86_l_1dd7;
	case 7644ULL: goto x86_l_1ddc;
	case 7648ULL: goto x86_l_1de0;
	case 7653ULL: goto x86_l_1de5;
	case 7658ULL: goto x86_l_1dea;
	case 7663ULL: goto x86_l_1def;
	case 7668ULL: goto x86_l_1df4;
	case 7671ULL: goto x86_l_1df7;
	case 7673ULL: goto x86_l_1df9;
	case 7677ULL: goto x86_l_1dfd;
	case 7682ULL: goto x86_l_1e02;
	case 7685ULL: goto x86_l_1e05;
	case 7689ULL: goto x86_l_1e09;
	case 7694ULL: goto x86_l_1e0e;
	case 7699ULL: goto x86_l_1e13;
	case 7704ULL: goto x86_l_1e18;
	case 7709ULL: goto x86_l_1e1d;
	case 7711ULL: goto x86_l_1e1f;
	case 7715ULL: goto x86_l_1e23;
	case 7719ULL: goto x86_l_1e27;
	case 7723ULL: goto x86_l_1e2b;
	case 7728ULL: goto x86_l_1e30;
	case 7733ULL: goto x86_l_1e35;
	case 7738ULL: goto x86_l_1e3a;
	case 7743ULL: goto x86_l_1e3f;
	case 7746ULL: goto x86_l_1e42;
	case 7748ULL: goto x86_l_1e44;
	case 7752ULL: goto x86_l_1e48;
	case 7757ULL: goto x86_l_1e4d;
	case 7762ULL: goto x86_l_1e52;
	case 7765ULL: goto x86_l_1e55;
	case 7770ULL: goto x86_l_1e5a;
	case 7775ULL: goto x86_l_1e5f;
	case 7780ULL: goto x86_l_1e64;
	case 7783ULL: goto x86_l_1e67;
	case 7788ULL: goto x86_l_1e6c;
	case 7790ULL: goto x86_l_1e6e;
	case 7795ULL: goto x86_l_1e73;
	case 7800ULL: goto x86_l_1e78;
	case 7808ULL: goto x86_l_1e80;
	case 7816ULL: goto x86_l_1e88;
	case 7824ULL: goto x86_l_1e90;
	case 7832ULL: goto x86_l_1e98;
	case 7840ULL: goto x86_l_1ea0;
	case 7848ULL: goto x86_l_1ea8;
	case 7856ULL: goto x86_l_1eb0;
	case 7864ULL: goto x86_l_1eb8;
	case 7872ULL: goto x86_l_1ec0;
	case 7879ULL: goto x86_l_1ec7;
	case 7884ULL: goto x86_l_1ecc;
	case 7889ULL: goto x86_l_1ed1;
	case 7894ULL: goto x86_l_1ed6;
	case 7899ULL: goto x86_l_1edb;
	case 7902ULL: goto x86_l_1ede;
	case 7904ULL: goto x86_l_1ee0;
	case 7907ULL: goto x86_l_1ee3;
	case 7913ULL: goto x86_l_1ee9;
	case 7916ULL: goto x86_l_1eec;
	case 7921ULL: goto x86_l_1ef1;
	case 7926ULL: goto x86_l_1ef6;
	case 7933ULL: goto x86_l_1efd;
	case 7938ULL: goto x86_l_1f02;
	case 7943ULL: goto x86_l_1f07;
	case 7948ULL: goto x86_l_1f0c;
	case 7956ULL: goto x86_l_1f14;
	case 7961ULL: goto x86_l_1f19;
	case 7966ULL: goto x86_l_1f1e;
	case 7971ULL: goto x86_l_1f23;
	case 7976ULL: goto x86_l_1f28;
	case 7981ULL: goto x86_l_1f2d;
	case 7983ULL: goto x86_l_1f2f;
	case 7987ULL: goto x86_l_1f33;
	case 7992ULL: goto x86_l_1f38;
	case 7997ULL: goto x86_l_1f3d;
	case 8002ULL: goto x86_l_1f42;
	case 8007ULL: goto x86_l_1f47;
	case 8010ULL: goto x86_l_1f4a;
	case 8012ULL: goto x86_l_1f4c;
	case 8020ULL: goto x86_l_1f54;
	case 8025ULL: goto x86_l_1f59;
	case 8030ULL: goto x86_l_1f5e;
	case 8034ULL: goto x86_l_1f62;
	case 8041ULL: goto x86_l_1f69;
	case 8046ULL: goto x86_l_1f6e;
	case 8052ULL: goto x86_l_1f74;
	case 8059ULL: goto x86_l_1f7b;
	case 8065ULL: goto x86_l_1f81;
	case 8073ULL: goto x86_l_1f89;
	case 8077ULL: goto x86_l_1f8d;
	case 8080ULL: goto x86_l_1f90;
	case 8083ULL: goto x86_l_1f93;
	case 8086ULL: goto x86_l_1f96;
	case 8091ULL: goto x86_l_1f9b;
	case 8096ULL: goto x86_l_1fa0;
	case 8107ULL: goto x86_l_1fab;
	case 8115ULL: goto x86_l_1fb3;
	case 8122ULL: goto x86_l_1fba;
	case 8130ULL: goto x86_l_1fc2;
	case 8135ULL: goto x86_l_1fc7;
	case 8139ULL: goto x86_l_1fcb;
	case 8141ULL: goto x86_l_1fcd;
	case 8144ULL: goto x86_l_1fd0;
	case 8150ULL: goto x86_l_1fd6;
	case 8153ULL: goto x86_l_1fd9;
	case 8156ULL: goto x86_l_1fdc;
	case 8160ULL: goto x86_l_1fe0;
	case 8164ULL: goto x86_l_1fe4;
	case 8167ULL: goto x86_l_1fe7;
	case 8171ULL: goto x86_l_1feb;
	case 8175ULL: goto x86_l_1fef;
	case 8180ULL: goto x86_l_1ff4;
	case 8185ULL: goto x86_l_1ff9;
	case 8190ULL: goto x86_l_1ffe;
	case 8195ULL: goto x86_l_2003;
	case 8197ULL: goto x86_l_2005;
	case 8200ULL: goto x86_l_2008;
	case 8206ULL: goto x86_l_200e;
	case 8211ULL: goto x86_l_2013;
	case 8214ULL: goto x86_l_2016;
	case 8220ULL: goto x86_l_201c;
	case 8222ULL: goto x86_l_201e;
	case 8228ULL: goto x86_l_2024;
	case 8231ULL: goto x86_l_2027;
	case 8237ULL: goto x86_l_202d;
	case 8240ULL: goto x86_l_2030;
	case 8246ULL: goto x86_l_2036;
	case 8253ULL: goto x86_l_203d;
	case 8257ULL: goto x86_l_2041;
	case 8262ULL: goto x86_l_2046;
	case 8266ULL: goto x86_l_204a;
	case 8271ULL: goto x86_l_204f;
	case 8276ULL: goto x86_l_2054;
	case 8279ULL: goto x86_l_2057;
	case 8284ULL: goto x86_l_205c;
	case 8286ULL: goto x86_l_205e;
	case 8290ULL: goto x86_l_2062;
	case 8295ULL: goto x86_l_2067;
	case 8300ULL: goto x86_l_206c;
	case 8303ULL: goto x86_l_206f;
	case 8308ULL: goto x86_l_2074;
	case 8310ULL: goto x86_l_2076;
	case 8314ULL: goto x86_l_207a;
	case 8318ULL: goto x86_l_207e;
	case 8322ULL: goto x86_l_2082;
	case 8327ULL: goto x86_l_2087;
	case 8332ULL: goto x86_l_208c;
	case 8337ULL: goto x86_l_2091;
	case 8340ULL: goto x86_l_2094;
	case 8342ULL: goto x86_l_2096;
	case 8346ULL: goto x86_l_209a;
	case 8351ULL: goto x86_l_209f;
	case 8356ULL: goto x86_l_20a4;
	case 8361ULL: goto x86_l_20a9;
	case 8364ULL: goto x86_l_20ac;
	case 8366ULL: goto x86_l_20ae;
	case 8371ULL: goto x86_l_20b3;
	case 8378ULL: goto x86_l_20ba;
	case 8383ULL: goto x86_l_20bf;
	case 8388ULL: goto x86_l_20c4;
	case 8395ULL: goto x86_l_20cb;
	case 8400ULL: goto x86_l_20d0;
	case 8405ULL: goto x86_l_20d5;
	case 8407ULL: goto x86_l_20d7;
	case 8410ULL: goto x86_l_20da;
	case 8412ULL: goto x86_l_20dc;
	case 8414ULL: goto x86_l_20de;
	case 8419ULL: goto x86_l_20e3;
	case 8422ULL: goto x86_l_20e6;
	case 8426ULL: goto x86_l_20ea;
	case 8430ULL: goto x86_l_20ee;
	case 8433ULL: goto x86_l_20f1;
	case 8436ULL: goto x86_l_20f4;
	case 8442ULL: goto x86_l_20fa;
	case 8447ULL: goto x86_l_20ff;
	case 8452ULL: goto x86_l_2104;
	case 8457ULL: goto x86_l_2109;
	case 8469ULL: goto x86_l_2115;
	case 8475ULL: goto x86_l_211b;
	case 8480ULL: goto x86_l_2120;
	case 8485ULL: goto x86_l_2125;
	case 8490ULL: goto x86_l_212a;
	case 8492ULL: goto x86_l_212c;
	case 8496ULL: goto x86_l_2130;
	case 8498ULL: goto x86_l_2132;
	case 8503ULL: goto x86_l_2137;
	case 8507ULL: goto x86_l_213b;
	case 8511ULL: goto x86_l_213f;
	case 8515ULL: goto x86_l_2143;
	case 8520ULL: goto x86_l_2148;
	case 8525ULL: goto x86_l_214d;
	case 8530ULL: goto x86_l_2152;
	case 8539ULL: goto x86_l_215b;
	case 8547ULL: goto x86_l_2163;
	case 8555ULL: goto x86_l_216b;
	case 8562ULL: goto x86_l_2172;
	case 8564ULL: goto x86_l_2174;
	case 8572ULL: goto x86_l_217c;
	case 8577ULL: goto x86_l_2181;
	case 8582ULL: goto x86_l_2186;
	case 8584ULL: goto x86_l_2188;
	case 8586ULL: goto x86_l_218a;
	case 8589ULL: goto x86_l_218d;
	case 8595ULL: goto x86_l_2193;
	case 8597ULL: goto x86_l_2195;
	case 8602ULL: goto x86_l_219a;
	case 8609ULL: goto x86_l_21a1;
	case 8619ULL: goto x86_l_21ab;
	case 8624ULL: goto x86_l_21b0;
	case 8631ULL: goto x86_l_21b7;
	case 8636ULL: goto x86_l_21bc;
	case 8641ULL: goto x86_l_21c1;
	case 8643ULL: goto x86_l_21c3;
	case 8646ULL: goto x86_l_21c6;
	case 8652ULL: goto x86_l_21cc;
	case 8654ULL: goto x86_l_21ce;
	case 8659ULL: goto x86_l_21d3;
	case 8662ULL: goto x86_l_21d6;
	case 8668ULL: goto x86_l_21dc;
	case 8671ULL: goto x86_l_21df;
	case 8677ULL: goto x86_l_21e5;
	case 8682ULL: goto x86_l_21ea;
	case 8688ULL: goto x86_l_21f0;
	case 8693ULL: goto x86_l_21f5;
	case 8698ULL: goto x86_l_21fa;
	case 8703ULL: goto x86_l_21ff;
	case 8707ULL: goto x86_l_2203;
	case 8712ULL: goto x86_l_2208;
	case 8717ULL: goto x86_l_220d;
	case 8722ULL: goto x86_l_2212;
	case 8724ULL: goto x86_l_2214;
	case 8729ULL: goto x86_l_2219;
	case 8733ULL: goto x86_l_221d;
	case 8738ULL: goto x86_l_2222;
	case 8743ULL: goto x86_l_2227;
	case 8748ULL: goto x86_l_222c;
	case 8751ULL: goto x86_l_222f;
	case 8753ULL: goto x86_l_2231;
	case 8758ULL: goto x86_l_2236;
	case 8762ULL: goto x86_l_223a;
	case 8768ULL: goto x86_l_2240;
	case 8773ULL: goto x86_l_2245;
	case 8778ULL: goto x86_l_224a;
	case 8783ULL: goto x86_l_224f;
	case 8789ULL: goto x86_l_2255;
	case 8794ULL: goto x86_l_225a;
	case 8799ULL: goto x86_l_225f;
	case 8804ULL: goto x86_l_2264;
	case 8808ULL: goto x86_l_2268;
	case 8813ULL: goto x86_l_226d;
	case 8818ULL: goto x86_l_2272;
	case 8823ULL: goto x86_l_2277;
	case 8828ULL: goto x86_l_227c;
	case 8833ULL: goto x86_l_2281;
	case 8835ULL: goto x86_l_2283;
	case 8838ULL: goto x86_l_2286;
	case 8844ULL: goto x86_l_228c;
	case 8849ULL: goto x86_l_2291;
	case 8853ULL: goto x86_l_2295;
	case 8861ULL: goto x86_l_229d;
	case 8866ULL: goto x86_l_22a2;
	case 8871ULL: goto x86_l_22a7;
	case 8876ULL: goto x86_l_22ac;
	case 8878ULL: goto x86_l_22ae;
	case 8883ULL: goto x86_l_22b3;
	case 8887ULL: goto x86_l_22b7;
	case 8892ULL: goto x86_l_22bc;
	case 8900ULL: goto x86_l_22c4;
	case 8903ULL: goto x86_l_22c7;
	case 8908ULL: goto x86_l_22cc;
	case 8913ULL: goto x86_l_22d1;
	case 8921ULL: goto x86_l_22d9;
	case 8926ULL: goto x86_l_22de;
	case 8928ULL: goto x86_l_22e0;
	case 8932ULL: goto x86_l_22e4;
	case 8940ULL: goto x86_l_22ec;
	case 8945ULL: goto x86_l_22f1;
	case 8950ULL: goto x86_l_22f6;
	case 8955ULL: goto x86_l_22fb;
	case 8958ULL: goto x86_l_22fe;
	case 8960ULL: goto x86_l_2300;
	case 8966ULL: goto x86_l_2306;
	case 8969ULL: goto x86_l_2309;
	case 8971ULL: goto x86_l_230b;
	case 8973ULL: goto x86_l_230d;
	case 8981ULL: goto x86_l_2315;
	case 8984ULL: goto x86_l_2318;
	case 8989ULL: goto x86_l_231d;
	case 8991ULL: goto x86_l_231f;
	case 8996ULL: goto x86_l_2324;
	case 9001ULL: goto x86_l_2329;
	case 9004ULL: goto x86_l_232c;
	case 9007ULL: goto x86_l_232f;
	case 9010ULL: goto x86_l_2332;
	case 9015ULL: goto x86_l_2337;
	case 9019ULL: goto x86_l_233b;
	case 9024ULL: goto x86_l_2340;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c5a:
	/* 0x1c5a: jmp    c64 <generic_lsm_process_event+0xc64> */
	return 3172ULL;
x86_l_1c5f:
	/* 0x1c5f: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c64:
	/* 0x1c64: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1c6b:
	/* 0x1c6b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c70:
	/* 0x1c70: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c75:
	/* 0x1c75: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c7a:
	/* 0x1c7a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1c7d:
	/* 0x1c7d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c82:
	/* 0x1c82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c84:
	/* 0x1c84: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c88:
	/* 0x1c88: lea    rdx,[r13+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1c8f:
	/* 0x1c8f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c94:
	/* 0x1c94: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c99:
	/* 0x1c99: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c9e:
	/* 0x1c9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca0:
	/* 0x1ca0: lea    rdi,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ca4:
	/* 0x1ca4: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1cab:
	/* 0x1cab: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1cb0:
	/* 0x1cb0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cb5:
	/* 0x1cb5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cba:
	/* 0x1cba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cbc:
	/* 0x1cbc: add    r15,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1cc0:
	/* 0x1cc0: add    r13,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1cc7:
	/* 0x1cc7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ccc:
	/* 0x1ccc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cd1:
	/* 0x1cd1: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1cd4:
	/* 0x1cd4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cd9:
	/* 0x1cd9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1cdc:
	/* 0x1cdc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cde:
	/* 0x1cde: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_1ce4:
	/* 0x1ce4: jmp    2255 <generic_lsm_process_event+0x2255> */
	goto x86_l_2255;
x86_l_1ce9:
	/* 0x1ce9: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cee:
	/* 0x1cee: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cf2:
	/* 0x1cf2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1cf7:
	/* 0x1cf7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cfc:
	/* 0x1cfc: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d01:
	/* 0x1d01: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1d04:
	/* 0x1d04: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d09:
	/* 0x1d09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d0b:
	/* 0x1d0b: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d0f:
	/* 0x1d0f: lea    rdx,[r13+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1d13:
	/* 0x1d13: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d18:
	/* 0x1d18: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d1d:
	/* 0x1d1d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d22:
	/* 0x1d22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d24:
	/* 0x1d24: lea    rdi,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d28:
	/* 0x1d28: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d2c:
	/* 0x1d2c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d31:
	/* 0x1d31: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d36:
	/* 0x1d36: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d3b:
	/* 0x1d3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d3d:
	/* 0x1d3d: lea    rdi,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d41:
	/* 0x1d41: lea    rdx,[r13+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1d45:
	/* 0x1d45: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d4a:
	/* 0x1d4a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d4f:
	/* 0x1d4f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d54:
	/* 0x1d54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d56:
	/* 0x1d56: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1d5a:
	/* 0x1d5a: add    r13,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1d5e:
	/* 0x1d5e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1d63:
	/* 0x1d63: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d68:
	/* 0x1d68: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1d6b:
	/* 0x1d6b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d70:
	/* 0x1d70: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1d73:
	/* 0x1d73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d75:
	/* 0x1d75: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_1d7b:
	/* 0x1d7b: jmp    2255 <generic_lsm_process_event+0x2255> */
	goto x86_l_2255;
x86_l_1d80:
	/* 0x1d80: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d85:
	/* 0x1d85: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d8a:
	/* 0x1d8a: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d8f:
	/* 0x1d8f: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d94:
	/* 0x1d94: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1d97:
	/* 0x1d97: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d9c:
	/* 0x1d9c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1d9f:
	/* 0x1d9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1da1:
	/* 0x1da1: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1da5:
	/* 0x1da5: lea    rdx,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1da9:
	/* 0x1da9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1dae:
	/* 0x1dae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1db3:
	/* 0x1db3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1db8:
	/* 0x1db8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dba:
	/* 0x1dba: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1dbe:
	/* 0x1dbe: add    r13,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_1dc2:
	/* 0x1dc2: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1dc7:
	/* 0x1dc7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dcc:
	/* 0x1dcc: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1dcf:
	/* 0x1dcf: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1dd4:
	/* 0x1dd4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1dd7:
	/* 0x1dd7: jmp    1e6c <generic_lsm_process_event+0x1e6c> */
	goto x86_l_1e6c;
x86_l_1ddc:
	/* 0x1ddc: lea    rdx,[r8+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1de0:
	/* 0x1de0: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1de5:
	/* 0x1de5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1dea:
	/* 0x1dea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1def:
	/* 0x1def: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1df4:
	/* 0x1df4: mov    r13,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_64);
x86_l_1df7:
	/* 0x1df7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1df9:
	/* 0x1df9: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1dfd:
	/* 0x1dfd: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e02:
	/* 0x1e02: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e05:
	/* 0x1e05: lea    rdx,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e09:
	/* 0x1e09: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1e0e:
	/* 0x1e0e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e13:
	/* 0x1e13: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e18:
	/* 0x1e18: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e1d:
	/* 0x1e1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e1f:
	/* 0x1e1f: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1e23:
	/* 0x1e23: mov    DWORD PTR [r15+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e27:
	/* 0x1e27: add    r13,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_1e2b:
	/* 0x1e2b: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1e30:
	/* 0x1e30: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e35:
	/* 0x1e35: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1e3a:
	/* 0x1e3a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e3f:
	/* 0x1e3f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1e42:
	/* 0x1e42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e44:
	/* 0x1e44: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1e48:
	/* 0x1e48: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_1e4d:
	/* 0x1e4d: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1e52:
	/* 0x1e52: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1e55:
	/* 0x1e55: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e5a:
	/* 0x1e5a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1e5f:
	/* 0x1e5f: add    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 104ULL);
x86_l_1e64:
	/* 0x1e64: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1e67:
	/* 0x1e67: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e6c:
	/* 0x1e6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e6e:
	/* 0x1e6e: jmp    224f <generic_lsm_process_event+0x224f> */
	goto x86_l_224f;
x86_l_1e73:
	/* 0x1e73: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e78:
	/* 0x1e78: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1e80:
	/* 0x1e80: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1e88:
	/* 0x1e88: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1e90:
	/* 0x1e90: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1e98:
	/* 0x1e98: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1ea0:
	/* 0x1ea0: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1ea8:
	/* 0x1ea8: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1eb0:
	/* 0x1eb0: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1eb8:
	/* 0x1eb8: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1ec0:
	/* 0x1ec0: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ec7:
	/* 0x1ec7: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1ecc:
	/* 0x1ecc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ed1:
	/* 0x1ed1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ed6:
	/* 0x1ed6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1edb:
	/* 0x1edb: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_1ede:
	/* 0x1ede: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ee0:
	/* 0x1ee0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ee3:
	/* 0x1ee3: je     225f <generic_lsm_process_event+0x225f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_225f;
	}
x86_l_1ee9:
	/* 0x1ee9: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1eec:
	/* 0x1eec: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ef1:
	/* 0x1ef1: jmp    3342 <generic_lsm_process_event+0x3342> */
	return 13122ULL;
x86_l_1ef6:
	/* 0x1ef6: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1efd:
	/* 0x1efd: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f02:
	/* 0x1f02: jmp    333d <generic_lsm_process_event+0x333d> */
	return 13117ULL;
x86_l_1f07:
	/* 0x1f07: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f0c:
	/* 0x1f0c: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1f14:
	/* 0x1f14: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1f19:
	/* 0x1f19: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f1e:
	/* 0x1f1e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f23:
	/* 0x1f23: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f28:
	/* 0x1f28: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f2d:
	/* 0x1f2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f2f:
	/* 0x1f2f: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1f33:
	/* 0x1f33: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1f38:
	/* 0x1f38: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f3d:
	/* 0x1f3d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f42:
	/* 0x1f42: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f47:
	/* 0x1f47: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f4a:
	/* 0x1f4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f4c:
	/* 0x1f4c: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1f54:
	/* 0x1f54: mov    r14,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1f59:
	/* 0x1f59: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1f5e:
	/* 0x1f5e: lea    r12,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1f62:
	/* 0x1f62: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1f69:
	/* 0x1f69: test   BYTE PTR [rsp+0x40],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906976ULL);
x86_l_1f6e:
	/* 0x1f6e: je     2a42 <generic_lsm_process_event+0x2a42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10818ULL;
	}
x86_l_1f74:
	/* 0x1f74: cmp    r14,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 4096ULL);
x86_l_1f7b:
	/* 0x1f7b: jb     2a16 <generic_lsm_process_event+0x2a16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10774ULL;
	}
x86_l_1f81:
	/* 0x1f81: mov    DWORD PTR [r12],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1f89:
	/* 0x1f89: add    r12,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1f8d:
	/* 0x1f8d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1f90:
	/* 0x1f90: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1f93:
	/* 0x1f93: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_1f96:
	/* 0x1f96: jmp    2bcc <generic_lsm_process_event+0x2bcc> */
	return 11212ULL;
x86_l_1f9b:
	/* 0x1f9b: mov    rbx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1fa0:
	/* 0x1fa0: mov    DWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_1fab:
	/* 0x1fab: movzx  ebp,WORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 192ULL);
x86_l_1fb3:
	/* 0x1fb3: mov    rdi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_1fba:
	/* 0x1fba: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1fc2:
	/* 0x1fc2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fc7:
	/* 0x1fc7: lea    r13,[rbx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1fcb:
	/* 0x1fcb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fcd:
	/* 0x1fcd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fd0:
	/* 0x1fd0: je     3178 <generic_lsm_process_event+0x3178> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12664ULL;
	}
x86_l_1fd6:
	/* 0x1fd6: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1fd9:
	/* 0x1fd9: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fdc:
	/* 0x1fdc: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_1fe0:
	/* 0x1fe0: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_1fe4:
	/* 0x1fe4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1fe7:
	/* 0x1fe7: add    rdi,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_1feb:
	/* 0x1feb: lea    rdx,[r13+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1fef:
	/* 0x1fef: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1ff4:
	/* 0x1ff4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ff9:
	/* 0x1ff9: mov    QWORD PTR [rsp+0x20],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ffe:
	/* 0x1ffe: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_2003:
	/* 0x2003: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2005:
	/* 0x2005: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2008:
	/* 0x2008: js     3178 <generic_lsm_process_event+0x3178> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12664ULL;
	}
x86_l_200e:
	/* 0x200e: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2013:
	/* 0x2013: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2016:
	/* 0x2016: jg     2a99 <generic_lsm_process_event+0x2a99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10905ULL;
	}
x86_l_201c:
	/* 0x201c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_201e:
	/* 0x201e: je     2b41 <generic_lsm_process_event+0x2b41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11073ULL;
	}
x86_l_2024:
	/* 0x2024: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2027:
	/* 0x2027: je     2b41 <generic_lsm_process_event+0x2b41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11073ULL;
	}
x86_l_202d:
	/* 0x202d: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2030:
	/* 0x2030: jne    2d17 <generic_lsm_process_event+0x2d17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11543ULL;
	}
x86_l_2036:
	/* 0x2036: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_203d:
	/* 0x203d: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2041:
	/* 0x2041: jmp    2c66 <generic_lsm_process_event+0x2c66> */
	return 11366ULL;
x86_l_2046:
	/* 0x2046: lea    rdx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_204a:
	/* 0x204a: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_204f:
	/* 0x204f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2054:
	/* 0x2054: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2057:
	/* 0x2057: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_205c:
	/* 0x205c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_205e:
	/* 0x205e: lea    rdx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2062:
	/* 0x2062: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2067:
	/* 0x2067: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_206c:
	/* 0x206c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_206f:
	/* 0x206f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2074:
	/* 0x2074: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2076:
	/* 0x2076: lea    rdi,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_207a:
	/* 0x207a: lea    r12,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_207e:
	/* 0x207e: add    r15,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_2082:
	/* 0x2082: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2087:
	/* 0x2087: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_208c:
	/* 0x208c: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2091:
	/* 0x2091: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2094:
	/* 0x2094: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2096:
	/* 0x2096: lea    rdi,[r13+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_209a:
	/* 0x209a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_209f:
	/* 0x209f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20a4:
	/* 0x20a4: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_20a9:
	/* 0x20a9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_20ac:
	/* 0x20ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ae:
	/* 0x20ae: movzx  eax,WORD PTR [r13+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_20b3:
	/* 0x20b3: movbe  WORD PTR [r13+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_20ba:
	/* 0x20ba: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_20bf:
	/* 0x20bf: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_20c4:
	/* 0x20c4: mov    rdi,QWORD PTR [rip+0x1c8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_20cb:
	/* 0x20cb: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_20d0:
	/* 0x20d0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20d5:
	/* 0x20d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20d7:
	/* 0x20d7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20da:
	/* 0x20da: je     20f4 <generic_lsm_process_event+0x20f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20f4;
	}
x86_l_20dc:
	/* 0x20dc: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20de:
	/* 0x20de: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20e3:
	/* 0x20e3: mov    DWORD PTR [rdx+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20e6:
	/* 0x20e6: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20ea:
	/* 0x20ea: mov    QWORD PTR [rdx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20ee:
	/* 0x20ee: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_20f1:
	/* 0x20f1: mov    DWORD PTR [rdx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_20f4:
	/* 0x20f4: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_20fa:
	/* 0x20fa: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20ff:
	/* 0x20ff: jmp    333d <generic_lsm_process_event+0x333d> */
	return 13117ULL;
x86_l_2104:
	/* 0x2104: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2109:
	/* 0x2109: mov    QWORD PTR [rbp+rax*1+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 618475290624ULL);
x86_l_2115:
	/* 0x2115: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_211b:
	/* 0x211b: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2120:
	/* 0x2120: jmp    333d <generic_lsm_process_event+0x333d> */
	return 13117ULL;
x86_l_2125:
	/* 0x2125: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_212a:
	/* 0x212a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_212c:
	/* 0x212c: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_2130:
	/* 0x2130: jne    213b <generic_lsm_process_event+0x213b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_213b;
	}
x86_l_2132:
	/* 0x2132: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2137:
	/* 0x2137: mov    rax,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_213b:
	/* 0x213b: mov    rcx,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_213f:
	/* 0x213f: mov    rdx,QWORD PTR [rbp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2143:
	/* 0x2143: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2148:
	/* 0x2148: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_214d:
	/* 0x214d: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2152:
	/* 0x2152: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_215b:
	/* 0x215b: mov    QWORD PTR [rsp+0xa8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2163:
	/* 0x2163: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_216b:
	/* 0x216b: mov    rdi,QWORD PTR [rip+0x1c8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_2172:
	/* 0x2172: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2174:
	/* 0x2174: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_217c:
	/* 0x217c: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2181:
	/* 0x2181: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2186:
	/* 0x2186: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2188:
	/* 0x2188: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_218a:
	/* 0x218a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_218d:
	/* 0x218d: je     2af0 <generic_lsm_process_event+0x2af0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10992ULL;
	}
x86_l_2193:
	/* 0x2193: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2195:
	/* 0x2195: mov    WORD PTR [rsp+0x58],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_219a:
	/* 0x219a: mov    WORD PTR [rsp+0x5a],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 386547056645ULL);
x86_l_21a1:
	/* 0x21a1: movabs rax,0x200000046 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934662ULL);
x86_l_21ab:
	/* 0x21ab: mov    QWORD PTR [rsp+0x5c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_21b0:
	/* 0x21b0: mov    rdi,QWORD PTR [rip+0x1c8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_21b7:
	/* 0x21b7: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_21bc:
	/* 0x21bc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21c1:
	/* 0x21c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21c3:
	/* 0x21c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21c6:
	/* 0x21c6: je     2ac6 <generic_lsm_process_event+0x2ac6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10950ULL;
	}
x86_l_21cc:
	/* 0x21cc: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_21ce:
	/* 0x21ce: jmp    2af0 <generic_lsm_process_event+0x2af0> */
	return 10992ULL;
x86_l_21d3:
	/* 0x21d3: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21d6:
	/* 0x21d6: je     247c <generic_lsm_process_event+0x247c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9340ULL;
	}
x86_l_21dc:
	/* 0x21dc: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_21df:
	/* 0x21df: jne    28bc <generic_lsm_process_event+0x28bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10428ULL;
	}
x86_l_21e5:
	/* 0x21e5: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21ea:
	/* 0x21ea: add    rax,0x5e58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24152ULL);
x86_l_21f0:
	/* 0x21f0: jmp    2487 <generic_lsm_process_event+0x2487> */
	return 9351ULL;
x86_l_21f5:
	/* 0x21f5: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21fa:
	/* 0x21fa: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21ff:
	/* 0x21ff: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2203:
	/* 0x2203: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2208:
	/* 0x2208: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_220d:
	/* 0x220d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2212:
	/* 0x2212: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2214:
	/* 0x2214: lea    rdi,[r12+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2219:
	/* 0x2219: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_221d:
	/* 0x221d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2222:
	/* 0x2222: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2227:
	/* 0x2227: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_222c:
	/* 0x222c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_222f:
	/* 0x222f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2231:
	/* 0x2231: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2236:
	/* 0x2236: movzx  eax,WORD PTR [rcx+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_223a:
	/* 0x223a: movbe  WORD PTR [rcx+0x2],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2240:
	/* 0x2240: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2245:
	/* 0x2245: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_224a:
	/* 0x224a: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_224f:
	/* 0x224f: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_2255:
	/* 0x2255: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_225a:
	/* 0x225a: jmp    c69 <generic_lsm_process_event+0xc69> */
	return 3177ULL;
x86_l_225f:
	/* 0x225f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2264:
	/* 0x2264: lea    rdi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2268:
	/* 0x2268: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_226d:
	/* 0x226d: mov    edx,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 63ULL);
x86_l_2272:
	/* 0x2272: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2277:
	/* 0x2277: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_227c:
	/* 0x227c: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_2281:
	/* 0x2281: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2283:
	/* 0x2283: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2286:
	/* 0x2286: js     1ee9 <generic_lsm_process_event+0x1ee9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ee9;
	}
x86_l_228c:
	/* 0x228c: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2291:
	/* 0x2291: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2295:
	/* 0x2295: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_229d:
	/* 0x229d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22a2:
	/* 0x22a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22a7:
	/* 0x22a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22ac:
	/* 0x22ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22ae:
	/* 0x22ae: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22b3:
	/* 0x22b3: lea    rdi,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22b7:
	/* 0x22b7: mov    edx,0x348 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 840ULL);
x86_l_22bc:
	/* 0x22bc: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_22c4:
	/* 0x22c4: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_22c7:
	/* 0x22c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22cc:
	/* 0x22cc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22d1:
	/* 0x22d1: add    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 168ULL);
x86_l_22d9:
	/* 0x22d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22de:
	/* 0x22de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22e0:
	/* 0x22e0: add    r15,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_22e4:
	/* 0x22e4: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_22ec:
	/* 0x22ec: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_22f1:
	/* 0x22f1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22f6:
	/* 0x22f6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_22fb:
	/* 0x22fb: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_22fe:
	/* 0x22fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2300:
	/* 0x2300: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_2306:
	/* 0x2306: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2309:
	/* 0x2309: jne    231f <generic_lsm_process_event+0x231f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_231f;
	}
x86_l_230b:
	/* 0x230b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_230d:
	/* 0x230d: cmp    DWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_2315:
	/* 0x2315: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_2318:
	/* 0x2318: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_231d:
	/* 0x231d: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_231f:
	/* 0x231f: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2324:
	/* 0x2324: jmp    3342 <generic_lsm_process_event+0x3342> */
	return 13122ULL;
x86_l_2329:
	/* 0x2329: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_232c:
	/* 0x232c: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_232f:
	/* 0x232f: mov    r12,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_64);
x86_l_2332:
	/* 0x2332: jmp    3342 <generic_lsm_process_event+0x3342> */
	return 13122ULL;
x86_l_2337:
	/* 0x2337: add    r15,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_233b:
	/* 0x233b: mov    ecx,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 107ULL);
x86_l_2340:
	/* 0x2340: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
	return 9029ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9029ULL: goto x86_l_2345;
	case 9034ULL: goto x86_l_234a;
	case 9037ULL: goto x86_l_234d;
	case 9039ULL: goto x86_l_234f;
	case 9042ULL: goto x86_l_2352;
	case 9044ULL: goto x86_l_2354;
	case 9046ULL: goto x86_l_2356;
	case 9051ULL: goto x86_l_235b;
	case 9056ULL: goto x86_l_2360;
	case 9058ULL: goto x86_l_2362;
	case 9063ULL: goto x86_l_2367;
	case 9066ULL: goto x86_l_236a;
	case 9072ULL: goto x86_l_2370;
	case 9077ULL: goto x86_l_2375;
	case 9082ULL: goto x86_l_237a;
	case 9087ULL: goto x86_l_237f;
	case 9090ULL: goto x86_l_2382;
	case 9096ULL: goto x86_l_2388;
	case 9099ULL: goto x86_l_238b;
	case 9105ULL: goto x86_l_2391;
	case 9112ULL: goto x86_l_2398;
	case 9117ULL: goto x86_l_239d;
	case 9121ULL: goto x86_l_23a1;
	case 9126ULL: goto x86_l_23a6;
	case 9131ULL: goto x86_l_23ab;
	case 9136ULL: goto x86_l_23b0;
	case 9141ULL: goto x86_l_23b5;
	case 9143ULL: goto x86_l_23b7;
	case 9147ULL: goto x86_l_23bb;
	case 9152ULL: goto x86_l_23c0;
	case 9157ULL: goto x86_l_23c5;
	case 9160ULL: goto x86_l_23c8;
	case 9165ULL: goto x86_l_23cd;
	case 9167ULL: goto x86_l_23cf;
	case 9172ULL: goto x86_l_23d4;
	case 9176ULL: goto x86_l_23d8;
	case 9180ULL: goto x86_l_23dc;
	case 9184ULL: goto x86_l_23e0;
	case 9189ULL: goto x86_l_23e5;
	case 9194ULL: goto x86_l_23ea;
	case 9199ULL: goto x86_l_23ef;
	case 9202ULL: goto x86_l_23f2;
	case 9204ULL: goto x86_l_23f4;
	case 9208ULL: goto x86_l_23f8;
	case 9213ULL: goto x86_l_23fd;
	case 9218ULL: goto x86_l_2402;
	case 9223ULL: goto x86_l_2407;
	case 9226ULL: goto x86_l_240a;
	case 9228ULL: goto x86_l_240c;
	case 9232ULL: goto x86_l_2410;
	case 9238ULL: goto x86_l_2416;
	case 9243ULL: goto x86_l_241b;
	case 9247ULL: goto x86_l_241f;
	case 9252ULL: goto x86_l_2424;
	case 9259ULL: goto x86_l_242b;
	case 9264ULL: goto x86_l_2430;
	case 9269ULL: goto x86_l_2435;
	case 9271ULL: goto x86_l_2437;
	case 9274ULL: goto x86_l_243a;
	case 9276ULL: goto x86_l_243c;
	case 9278ULL: goto x86_l_243e;
	case 9283ULL: goto x86_l_2443;
	case 9286ULL: goto x86_l_2446;
	case 9290ULL: goto x86_l_244a;
	case 9294ULL: goto x86_l_244e;
	case 9297ULL: goto x86_l_2451;
	case 9300ULL: goto x86_l_2454;
	case 9306ULL: goto x86_l_245a;
	case 9309ULL: goto x86_l_245d;
	case 9314ULL: goto x86_l_2462;
	case 9319ULL: goto x86_l_2467;
	case 9325ULL: goto x86_l_246d;
	case 9327ULL: goto x86_l_246f;
	case 9332ULL: goto x86_l_2474;
	case 9338ULL: goto x86_l_247a;
	case 9340ULL: goto x86_l_247c;
	case 9345ULL: goto x86_l_2481;
	case 9351ULL: goto x86_l_2487;
	case 9354ULL: goto x86_l_248a;
	case 9359ULL: goto x86_l_248f;
	case 9365ULL: goto x86_l_2495;
	case 9368ULL: goto x86_l_2498;
	case 9374ULL: goto x86_l_249e;
	case 9379ULL: goto x86_l_24a3;
	case 9385ULL: goto x86_l_24a9;
	case 9390ULL: goto x86_l_24ae;
	case 9395ULL: goto x86_l_24b3;
	case 9400ULL: goto x86_l_24b8;
	case 9405ULL: goto x86_l_24bd;
	case 9407ULL: goto x86_l_24bf;
	case 9412ULL: goto x86_l_24c4;
	case 9414ULL: goto x86_l_24c6;
	case 9420ULL: goto x86_l_24cc;
	case 9425ULL: goto x86_l_24d1;
	case 9430ULL: goto x86_l_24d6;
	case 9433ULL: goto x86_l_24d9;
	case 9438ULL: goto x86_l_24de;
	case 9445ULL: goto x86_l_24e5;
	case 9451ULL: goto x86_l_24eb;
	case 9456ULL: goto x86_l_24f0;
	case 9460ULL: goto x86_l_24f4;
	case 9463ULL: goto x86_l_24f7;
	case 9469ULL: goto x86_l_24fd;
	case 9472ULL: goto x86_l_2500;
	case 9477ULL: goto x86_l_2505;
	case 9482ULL: goto x86_l_250a;
	case 9487ULL: goto x86_l_250f;
	case 9492ULL: goto x86_l_2514;
	case 9494ULL: goto x86_l_2516;
	case 9499ULL: goto x86_l_251b;
	case 9501ULL: goto x86_l_251d;
	case 9507ULL: goto x86_l_2523;
	case 9511ULL: goto x86_l_2527;
	case 9517ULL: goto x86_l_252d;
	case 9522ULL: goto x86_l_2532;
	case 9526ULL: goto x86_l_2536;
	case 9531ULL: goto x86_l_253b;
	case 9537ULL: goto x86_l_2541;
	case 9542ULL: goto x86_l_2546;
	case 9547ULL: goto x86_l_254b;
	case 9552ULL: goto x86_l_2550;
	case 9554ULL: goto x86_l_2552;
	case 9559ULL: goto x86_l_2557;
	case 9561ULL: goto x86_l_2559;
	case 9567ULL: goto x86_l_255f;
	case 9572ULL: goto x86_l_2564;
	case 9577ULL: goto x86_l_2569;
	case 9582ULL: goto x86_l_256e;
	case 9588ULL: goto x86_l_2574;
	case 9594ULL: goto x86_l_257a;
	case 9599ULL: goto x86_l_257f;
	case 9604ULL: goto x86_l_2584;
	case 9607ULL: goto x86_l_2587;
	case 9613ULL: goto x86_l_258d;
	case 9616ULL: goto x86_l_2590;
	case 9621ULL: goto x86_l_2595;
	case 9626ULL: goto x86_l_259a;
	case 9631ULL: goto x86_l_259f;
	case 9636ULL: goto x86_l_25a4;
	case 9638ULL: goto x86_l_25a6;
	case 9643ULL: goto x86_l_25ab;
	case 9645ULL: goto x86_l_25ad;
	case 9651ULL: goto x86_l_25b3;
	case 9656ULL: goto x86_l_25b8;
	case 9661ULL: goto x86_l_25bd;
	case 9665ULL: goto x86_l_25c1;
	case 9671ULL: goto x86_l_25c7;
	case 9676ULL: goto x86_l_25cc;
	case 9680ULL: goto x86_l_25d0;
	case 9685ULL: goto x86_l_25d5;
	case 9691ULL: goto x86_l_25db;
	case 9696ULL: goto x86_l_25e0;
	case 9701ULL: goto x86_l_25e5;
	case 9706ULL: goto x86_l_25ea;
	case 9708ULL: goto x86_l_25ec;
	case 9713ULL: goto x86_l_25f1;
	case 9715ULL: goto x86_l_25f3;
	case 9721ULL: goto x86_l_25f9;
	case 9726ULL: goto x86_l_25fe;
	case 9731ULL: goto x86_l_2603;
	case 9739ULL: goto x86_l_260b;
	case 9745ULL: goto x86_l_2611;
	case 9751ULL: goto x86_l_2617;
	case 9756ULL: goto x86_l_261c;
	case 9761ULL: goto x86_l_2621;
	case 9764ULL: goto x86_l_2624;
	case 9770ULL: goto x86_l_262a;
	case 9773ULL: goto x86_l_262d;
	case 9778ULL: goto x86_l_2632;
	case 9783ULL: goto x86_l_2637;
	case 9791ULL: goto x86_l_263f;
	case 9796ULL: goto x86_l_2644;
	case 9798ULL: goto x86_l_2646;
	case 9803ULL: goto x86_l_264b;
	case 9805ULL: goto x86_l_264d;
	case 9811ULL: goto x86_l_2653;
	case 9819ULL: goto x86_l_265b;
	case 9824ULL: goto x86_l_2660;
	case 9828ULL: goto x86_l_2664;
	case 9834ULL: goto x86_l_266a;
	case 9839ULL: goto x86_l_266f;
	case 9843ULL: goto x86_l_2673;
	case 9848ULL: goto x86_l_2678;
	case 9854ULL: goto x86_l_267e;
	case 9859ULL: goto x86_l_2683;
	case 9864ULL: goto x86_l_2688;
	case 9869ULL: goto x86_l_268d;
	case 9871ULL: goto x86_l_268f;
	case 9876ULL: goto x86_l_2694;
	case 9878ULL: goto x86_l_2696;
	case 9884ULL: goto x86_l_269c;
	case 9889ULL: goto x86_l_26a1;
	case 9894ULL: goto x86_l_26a6;
	case 9899ULL: goto x86_l_26ab;
	case 9905ULL: goto x86_l_26b1;
	case 9911ULL: goto x86_l_26b7;
	case 9919ULL: goto x86_l_26bf;
	case 9922ULL: goto x86_l_26c2;
	case 9925ULL: goto x86_l_26c5;
	case 9931ULL: goto x86_l_26cb;
	case 9934ULL: goto x86_l_26ce;
	case 9939ULL: goto x86_l_26d3;
	case 9944ULL: goto x86_l_26d8;
	case 9949ULL: goto x86_l_26dd;
	case 9954ULL: goto x86_l_26e2;
	case 9956ULL: goto x86_l_26e4;
	case 9961ULL: goto x86_l_26e9;
	case 9963ULL: goto x86_l_26eb;
	case 9969ULL: goto x86_l_26f1;
	case 9974ULL: goto x86_l_26f6;
	case 9979ULL: goto x86_l_26fb;
	case 9983ULL: goto x86_l_26ff;
	case 9989ULL: goto x86_l_2705;
	case 9994ULL: goto x86_l_270a;
	case 9998ULL: goto x86_l_270e;
	case 10003ULL: goto x86_l_2713;
	case 10009ULL: goto x86_l_2719;
	case 10014ULL: goto x86_l_271e;
	case 10019ULL: goto x86_l_2723;
	case 10024ULL: goto x86_l_2728;
	case 10026ULL: goto x86_l_272a;
	case 10031ULL: goto x86_l_272f;
	case 10033ULL: goto x86_l_2731;
	case 10039ULL: goto x86_l_2737;
	case 10044ULL: goto x86_l_273c;
	case 10049ULL: goto x86_l_2741;
	case 10054ULL: goto x86_l_2746;
	case 10060ULL: goto x86_l_274c;
	case 10066ULL: goto x86_l_2752;
	case 10071ULL: goto x86_l_2757;
	case 10074ULL: goto x86_l_275a;
	case 10077ULL: goto x86_l_275d;
	case 10083ULL: goto x86_l_2763;
	case 10086ULL: goto x86_l_2766;
	case 10091ULL: goto x86_l_276b;
	case 10096ULL: goto x86_l_2770;
	case 10101ULL: goto x86_l_2775;
	case 10106ULL: goto x86_l_277a;
	case 10108ULL: goto x86_l_277c;
	case 10113ULL: goto x86_l_2781;
	case 10115ULL: goto x86_l_2783;
	case 10121ULL: goto x86_l_2789;
	case 10126ULL: goto x86_l_278e;
	case 10131ULL: goto x86_l_2793;
	case 10135ULL: goto x86_l_2797;
	case 10141ULL: goto x86_l_279d;
	case 10146ULL: goto x86_l_27a2;
	case 10150ULL: goto x86_l_27a6;
	case 10155ULL: goto x86_l_27ab;
	case 10161ULL: goto x86_l_27b1;
	case 10166ULL: goto x86_l_27b6;
	case 10171ULL: goto x86_l_27bb;
	case 10176ULL: goto x86_l_27c0;
	case 10178ULL: goto x86_l_27c2;
	case 10183ULL: goto x86_l_27c7;
	case 10185ULL: goto x86_l_27c9;
	case 10191ULL: goto x86_l_27cf;
	case 10196ULL: goto x86_l_27d4;
	case 10201ULL: goto x86_l_27d9;
	case 10206ULL: goto x86_l_27de;
	case 10212ULL: goto x86_l_27e4;
	case 10218ULL: goto x86_l_27ea;
	case 10223ULL: goto x86_l_27ef;
	case 10226ULL: goto x86_l_27f2;
	case 10229ULL: goto x86_l_27f5;
	case 10235ULL: goto x86_l_27fb;
	case 10238ULL: goto x86_l_27fe;
	case 10243ULL: goto x86_l_2803;
	case 10248ULL: goto x86_l_2808;
	case 10253ULL: goto x86_l_280d;
	case 10258ULL: goto x86_l_2812;
	case 10260ULL: goto x86_l_2814;
	case 10265ULL: goto x86_l_2819;
	case 10267ULL: goto x86_l_281b;
	case 10273ULL: goto x86_l_2821;
	case 10278ULL: goto x86_l_2826;
	case 10283ULL: goto x86_l_282b;
	case 10287ULL: goto x86_l_282f;
	case 10293ULL: goto x86_l_2835;
	case 10298ULL: goto x86_l_283a;
	case 10302ULL: goto x86_l_283e;
	case 10307ULL: goto x86_l_2843;
	case 10313ULL: goto x86_l_2849;
	case 10318ULL: goto x86_l_284e;
	case 10323ULL: goto x86_l_2853;
	case 10328ULL: goto x86_l_2858;
	case 10330ULL: goto x86_l_285a;
	case 10335ULL: goto x86_l_285f;
	case 10337ULL: goto x86_l_2861;
	case 10339ULL: goto x86_l_2863;
	case 10344ULL: goto x86_l_2868;
	case 10349ULL: goto x86_l_286d;
	case 10356ULL: goto x86_l_2874;
	case 10358ULL: goto x86_l_2876;
	case 10363ULL: goto x86_l_287b;
	case 10366ULL: goto x86_l_287e;
	case 10372ULL: goto x86_l_2884;
	case 10375ULL: goto x86_l_2887;
	case 10380ULL: goto x86_l_288c;
	case 10385ULL: goto x86_l_2891;
	case 10390ULL: goto x86_l_2896;
	case 10393ULL: goto x86_l_2899;
	case 10395ULL: goto x86_l_289b;
	case 10400ULL: goto x86_l_28a0;
	case 10402ULL: goto x86_l_28a2;
	case 10404ULL: goto x86_l_28a4;
	case 10409ULL: goto x86_l_28a9;
	case 10414ULL: goto x86_l_28ae;
	case 10419ULL: goto x86_l_28b3;
	case 10423ULL: goto x86_l_28b7;
	case 10428ULL: goto x86_l_28bc;
	case 10431ULL: goto x86_l_28bf;
	case 10436ULL: goto x86_l_28c4;
	case 10441ULL: goto x86_l_28c9;
	case 10446ULL: goto x86_l_28ce;
	case 10452ULL: goto x86_l_28d4;
	case 10457ULL: goto x86_l_28d9;
	case 10459ULL: goto x86_l_28db;
	case 10463ULL: goto x86_l_28df;
	case 10465ULL: goto x86_l_28e1;
	case 10469ULL: goto x86_l_28e5;
	case 10474ULL: goto x86_l_28ea;
	case 10478ULL: goto x86_l_28ee;
	case 10482ULL: goto x86_l_28f2;
	case 10487ULL: goto x86_l_28f7;
	case 10492ULL: goto x86_l_28fc;
	case 10497ULL: goto x86_l_2901;
	case 10502ULL: goto x86_l_2906;
	case 10510ULL: goto x86_l_290e;
	case 10518ULL: goto x86_l_2916;
	case 10525ULL: goto x86_l_291d;
	case 10527ULL: goto x86_l_291f;
	case 10535ULL: goto x86_l_2927;
	case 10540ULL: goto x86_l_292c;
	case 10545ULL: goto x86_l_2931;
	case 10547ULL: goto x86_l_2933;
	case 10549ULL: goto x86_l_2935;
	case 10552ULL: goto x86_l_2938;
	case 10558ULL: goto x86_l_293e;
	case 10560ULL: goto x86_l_2940;
	case 10565ULL: goto x86_l_2945;
	case 10572ULL: goto x86_l_294c;
	case 10582ULL: goto x86_l_2956;
	case 10587ULL: goto x86_l_295b;
	case 10594ULL: goto x86_l_2962;
	case 10599ULL: goto x86_l_2967;
	case 10604ULL: goto x86_l_296c;
	case 10606ULL: goto x86_l_296e;
	case 10609ULL: goto x86_l_2971;
	case 10615ULL: goto x86_l_2977;
	case 10617ULL: goto x86_l_2979;
	case 10622ULL: goto x86_l_297e;
	case 10624ULL: goto x86_l_2980;
	case 10629ULL: goto x86_l_2985;
	case 10634ULL: goto x86_l_298a;
	case 10639ULL: goto x86_l_298f;
	case 10643ULL: goto x86_l_2993;
	case 10648ULL: goto x86_l_2998;
	case 10652ULL: goto x86_l_299c;
	case 10657ULL: goto x86_l_29a1;
	case 10664ULL: goto x86_l_29a8;
	case 10671ULL: goto x86_l_29af;
	case 10676ULL: goto x86_l_29b4;
	case 10680ULL: goto x86_l_29b8;
	case 10687ULL: goto x86_l_29bf;
	case 10690ULL: goto x86_l_29c2;
	case 10696ULL: goto x86_l_29c8;
	case 10703ULL: goto x86_l_29cf;
	case 10709ULL: goto x86_l_29d5;
	case 10713ULL: goto x86_l_29d9;
	case 10717ULL: goto x86_l_29dd;
	case 10722ULL: goto x86_l_29e2;
	case 10725ULL: goto x86_l_29e5;
	case 10727ULL: goto x86_l_29e7;
	case 10729ULL: goto x86_l_29e9;
	case 10731ULL: goto x86_l_29eb;
	case 10734ULL: goto x86_l_29ee;
	case 10738ULL: goto x86_l_29f2;
	case 10741ULL: goto x86_l_29f5;
	case 10746ULL: goto x86_l_29fa;
	case 10751ULL: goto x86_l_29ff;
	case 10758ULL: goto x86_l_2a06;
	case 10764ULL: goto x86_l_2a0c;
	case 10769ULL: goto x86_l_2a11;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2345:
	/* 0x2345: mov    esi,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 107ULL);
x86_l_234a:
	/* 0x234a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_234d:
	/* 0x234d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_234f:
	/* 0x234f: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2352:
	/* 0x2352: mov    al,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 107ULL);
x86_l_2354:
	/* 0x2354: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2356:
	/* 0x2356: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_235b:
	/* 0x235b: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2360:
	/* 0x2360: js     236a <generic_lsm_process_event+0x236a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_236a;
	}
x86_l_2362:
	/* 0x2362: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2367:
	/* 0x2367: mov    BYTE PTR [rcx+0x3],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_236a:
	/* 0x236a: mov    r15d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 112ULL);
x86_l_2370:
	/* 0x2370: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2375:
	/* 0x2375: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_237a:
	/* 0x237a: jmp    c69 <generic_lsm_process_event+0xc69> */
	return 3177ULL;
x86_l_237f:
	/* 0x237f: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2382:
	/* 0x2382: je     2b64 <generic_lsm_process_event+0x2b64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11108ULL;
	}
x86_l_2388:
	/* 0x2388: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_238b:
	/* 0x238b: jne    2b6e <generic_lsm_process_event+0x2b6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11118ULL;
	}
x86_l_2391:
	/* 0x2391: lea    rax,[rbp+0x5e58] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24152ULL);
x86_l_2398:
	/* 0x2398: jmp    2b6b <generic_lsm_process_event+0x2b6b> */
	return 11115ULL;
x86_l_239d:
	/* 0x239d: lea    rdx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_23a1:
	/* 0x23a1: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_23a6:
	/* 0x23a6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23ab:
	/* 0x23ab: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23b0:
	/* 0x23b0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_23b5:
	/* 0x23b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23b7:
	/* 0x23b7: lea    rdx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_23bb:
	/* 0x23bb: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_23c0:
	/* 0x23c0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23c5:
	/* 0x23c5: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_23c8:
	/* 0x23c8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_23cd:
	/* 0x23cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23cf:
	/* 0x23cf: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23d4:
	/* 0x23d4: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23d8:
	/* 0x23d8: lea    r12,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_23dc:
	/* 0x23dc: add    r15,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_23e0:
	/* 0x23e0: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_23e5:
	/* 0x23e5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23ea:
	/* 0x23ea: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_23ef:
	/* 0x23ef: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_23f2:
	/* 0x23f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23f4:
	/* 0x23f4: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_23f8:
	/* 0x23f8: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_23fd:
	/* 0x23fd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2402:
	/* 0x2402: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2407:
	/* 0x2407: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_240a:
	/* 0x240a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_240c:
	/* 0x240c: movzx  eax,WORD PTR [rbp+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2410:
	/* 0x2410: movbe  WORD PTR [rbp+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2416:
	/* 0x2416: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_241b:
	/* 0x241b: mov    rax,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_241f:
	/* 0x241f: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2424:
	/* 0x2424: mov    rdi,QWORD PTR [rip+0x1c8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_242b:
	/* 0x242b: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2430:
	/* 0x2430: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2435:
	/* 0x2435: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2437:
	/* 0x2437: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_243a:
	/* 0x243a: je     2454 <generic_lsm_process_event+0x2454> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2454;
	}
x86_l_243c:
	/* 0x243c: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_243e:
	/* 0x243e: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2443:
	/* 0x2443: mov    DWORD PTR [rdx+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2446:
	/* 0x2446: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_244a:
	/* 0x244a: mov    QWORD PTR [rdx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_244e:
	/* 0x244e: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2451:
	/* 0x2451: mov    DWORD PTR [rdx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2454:
	/* 0x2454: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_245a:
	/* 0x245a: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_245d:
	/* 0x245d: jmp    333d <generic_lsm_process_event+0x333d> */
	return 13117ULL;
x86_l_2462:
	/* 0x2462: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2467:
	/* 0x2467: add    rax,0x5e60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24160ULL);
x86_l_246d:
	/* 0x246d: jmp    2487 <generic_lsm_process_event+0x2487> */
	goto x86_l_2487;
x86_l_246f:
	/* 0x246f: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2474:
	/* 0x2474: add    rax,0x5e68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24168ULL);
x86_l_247a:
	/* 0x247a: jmp    2487 <generic_lsm_process_event+0x2487> */
	goto x86_l_2487;
x86_l_247c:
	/* 0x247c: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2481:
	/* 0x2481: add    rax,0x5e50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24144ULL);
x86_l_2487:
	/* 0x2487: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_248a:
	/* 0x248a: test   BYTE PTR [rsp+0x40],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906960ULL);
x86_l_248f:
	/* 0x248f: jne    28d4 <generic_lsm_process_event+0x28d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28d4;
	}
x86_l_2495:
	/* 0x2495: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2498:
	/* 0x2498: je     297e <generic_lsm_process_event+0x297e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_297e;
	}
x86_l_249e:
	/* 0x249e: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_24a3:
	/* 0x24a3: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_24a9:
	/* 0x24a9: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_24ae:
	/* 0x24ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24b3:
	/* 0x24b3: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24b8:
	/* 0x24b8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_24bd:
	/* 0x24bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24bf:
	/* 0x24bf: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_24c4:
	/* 0x24c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24c6:
	/* 0x24c6: js     28ae <generic_lsm_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28ae;
	}
x86_l_24cc:
	/* 0x24cc: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_24d1:
	/* 0x24d1: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_24d6:
	/* 0x24d6: mov    rax,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_24d9:
	/* 0x24d9: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24de:
	/* 0x24de: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_24e5:
	/* 0x24e5: ja     28ae <generic_lsm_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28ae;
	}
x86_l_24eb:
	/* 0x24eb: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_24f0:
	/* 0x24f0: lea    rdi,[rax+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_24f4:
	/* 0x24f4: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_24f7:
	/* 0x24f7: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_24fd:
	/* 0x24fd: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2500:
	/* 0x2500: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2505:
	/* 0x2505: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_250a:
	/* 0x250a: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_250f:
	/* 0x250f: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2514:
	/* 0x2514: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2516:
	/* 0x2516: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_251b:
	/* 0x251b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_251d:
	/* 0x251d: js     28ae <generic_lsm_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28ae;
	}
x86_l_2523:
	/* 0x2523: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_2527:
	/* 0x2527: je     2985 <generic_lsm_process_event+0x2985> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2985;
	}
x86_l_252d:
	/* 0x252d: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2532:
	/* 0x2532: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2536:
	/* 0x2536: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_253b:
	/* 0x253b: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2541:
	/* 0x2541: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2546:
	/* 0x2546: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_254b:
	/* 0x254b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2550:
	/* 0x2550: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2552:
	/* 0x2552: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2557:
	/* 0x2557: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2559:
	/* 0x2559: js     28ae <generic_lsm_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28ae;
	}
x86_l_255f:
	/* 0x255f: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2564:
	/* 0x2564: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2569:
	/* 0x2569: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_256e:
	/* 0x256e: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_2574:
	/* 0x2574: ja     28ae <generic_lsm_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28ae;
	}
x86_l_257a:
	/* 0x257a: add    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_257f:
	/* 0x257f: mov    QWORD PTR [rsp+0x40],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2584:
	/* 0x2584: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_2587:
	/* 0x2587: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_258d:
	/* 0x258d: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2590:
	/* 0x2590: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2595:
	/* 0x2595: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_259a:
	/* 0x259a: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_259f:
	/* 0x259f: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_25a4:
	/* 0x25a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25a6:
	/* 0x25a6: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_25ab:
	/* 0x25ab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25ad:
	/* 0x25ad: js     28ae <generic_lsm_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28ae;
	}
x86_l_25b3:
	/* 0x25b3: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25b8:
	/* 0x25b8: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_25bd:
	/* 0x25bd: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_25c1:
	/* 0x25c1: jb     2985 <generic_lsm_process_event+0x2985> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2985;
	}
x86_l_25c7:
	/* 0x25c7: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25cc:
	/* 0x25cc: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25d0:
	/* 0x25d0: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_25d5:
	/* 0x25d5: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_25db:
	/* 0x25db: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_25e0:
	/* 0x25e0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25e5:
	/* 0x25e5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_25ea:
	/* 0x25ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25ec:
	/* 0x25ec: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_25f1:
	/* 0x25f1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25f3:
	/* 0x25f3: js     28ae <generic_lsm_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28ae;
	}
x86_l_25f9:
	/* 0x25f9: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_25fe:
	/* 0x25fe: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2603:
	/* 0x2603: mov    QWORD PTR [rsp+0xe0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_260b:
	/* 0x260b: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_2611:
	/* 0x2611: ja     28ae <generic_lsm_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28ae;
	}
x86_l_2617:
	/* 0x2617: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_261c:
	/* 0x261c: add    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2621:
	/* 0x2621: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_2624:
	/* 0x2624: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_262a:
	/* 0x262a: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_262d:
	/* 0x262d: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2632:
	/* 0x2632: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2637:
	/* 0x2637: mov    rsi,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_263f:
	/* 0x263f: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2644:
	/* 0x2644: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2646:
	/* 0x2646: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_264b:
	/* 0x264b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_264d:
	/* 0x264d: js     28ae <generic_lsm_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28ae;
	}
x86_l_2653:
	/* 0x2653: mov    rax,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_265b:
	/* 0x265b: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2660:
	/* 0x2660: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_2664:
	/* 0x2664: je     2985 <generic_lsm_process_event+0x2985> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2985;
	}
x86_l_266a:
	/* 0x266a: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_266f:
	/* 0x266f: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2673:
	/* 0x2673: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2678:
	/* 0x2678: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_267e:
	/* 0x267e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2683:
	/* 0x2683: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2688:
	/* 0x2688: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_268d:
	/* 0x268d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_268f:
	/* 0x268f: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2694:
	/* 0x2694: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2696:
	/* 0x2696: js     28ae <generic_lsm_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28ae;
	}
x86_l_269c:
	/* 0x269c: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_26a1:
	/* 0x26a1: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_26a6:
	/* 0x26a6: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26ab:
	/* 0x26ab: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_26b1:
	/* 0x26b1: ja     28ae <generic_lsm_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28ae;
	}
x86_l_26b7:
	/* 0x26b7: mov    rdi,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_26bf:
	/* 0x26bf: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26c2:
	/* 0x26c2: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_26c5:
	/* 0x26c5: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_26cb:
	/* 0x26cb: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26ce:
	/* 0x26ce: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_26d3:
	/* 0x26d3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26d8:
	/* 0x26d8: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26dd:
	/* 0x26dd: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_26e2:
	/* 0x26e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26e4:
	/* 0x26e4: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_26e9:
	/* 0x26e9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26eb:
	/* 0x26eb: js     28ae <generic_lsm_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28ae;
	}
x86_l_26f1:
	/* 0x26f1: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26f6:
	/* 0x26f6: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_26fb:
	/* 0x26fb: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_26ff:
	/* 0x26ff: jb     2985 <generic_lsm_process_event+0x2985> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2985;
	}
x86_l_2705:
	/* 0x2705: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_270a:
	/* 0x270a: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_270e:
	/* 0x270e: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2713:
	/* 0x2713: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2719:
	/* 0x2719: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_271e:
	/* 0x271e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2723:
	/* 0x2723: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2728:
	/* 0x2728: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_272a:
	/* 0x272a: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_272f:
	/* 0x272f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2731:
	/* 0x2731: js     28ae <generic_lsm_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28ae;
	}
x86_l_2737:
	/* 0x2737: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_273c:
	/* 0x273c: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2741:
	/* 0x2741: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2746:
	/* 0x2746: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_274c:
	/* 0x274c: ja     28ae <generic_lsm_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28ae;
	}
x86_l_2752:
	/* 0x2752: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2757:
	/* 0x2757: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_275a:
	/* 0x275a: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_275d:
	/* 0x275d: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2763:
	/* 0x2763: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2766:
	/* 0x2766: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_276b:
	/* 0x276b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2770:
	/* 0x2770: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2775:
	/* 0x2775: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_277a:
	/* 0x277a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_277c:
	/* 0x277c: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2781:
	/* 0x2781: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2783:
	/* 0x2783: js     28ae <generic_lsm_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28ae;
	}
x86_l_2789:
	/* 0x2789: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_278e:
	/* 0x278e: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2793:
	/* 0x2793: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_2797:
	/* 0x2797: je     2985 <generic_lsm_process_event+0x2985> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2985;
	}
x86_l_279d:
	/* 0x279d: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27a2:
	/* 0x27a2: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_27a6:
	/* 0x27a6: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_27ab:
	/* 0x27ab: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_27b1:
	/* 0x27b1: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_27b6:
	/* 0x27b6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27bb:
	/* 0x27bb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_27c0:
	/* 0x27c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27c2:
	/* 0x27c2: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_27c7:
	/* 0x27c7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27c9:
	/* 0x27c9: js     28ae <generic_lsm_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28ae;
	}
x86_l_27cf:
	/* 0x27cf: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_27d4:
	/* 0x27d4: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_27d9:
	/* 0x27d9: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27de:
	/* 0x27de: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_27e4:
	/* 0x27e4: ja     28ae <generic_lsm_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28ae;
	}
x86_l_27ea:
	/* 0x27ea: mov    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_27ef:
	/* 0x27ef: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_27f2:
	/* 0x27f2: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_27f5:
	/* 0x27f5: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_27fb:
	/* 0x27fb: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_27fe:
	/* 0x27fe: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2803:
	/* 0x2803: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2808:
	/* 0x2808: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_280d:
	/* 0x280d: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2812:
	/* 0x2812: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2814:
	/* 0x2814: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2819:
	/* 0x2819: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_281b:
	/* 0x281b: js     28ae <generic_lsm_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28ae;
	}
x86_l_2821:
	/* 0x2821: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2826:
	/* 0x2826: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_282b:
	/* 0x282b: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_282f:
	/* 0x282f: jb     2985 <generic_lsm_process_event+0x2985> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2985;
	}
x86_l_2835:
	/* 0x2835: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_283a:
	/* 0x283a: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_283e:
	/* 0x283e: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2843:
	/* 0x2843: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2849:
	/* 0x2849: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_284e:
	/* 0x284e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2853:
	/* 0x2853: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2858:
	/* 0x2858: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_285a:
	/* 0x285a: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_285f:
	/* 0x285f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2861:
	/* 0x2861: js     28ae <generic_lsm_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28ae;
	}
x86_l_2863:
	/* 0x2863: mov    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2868:
	/* 0x2868: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_286d:
	/* 0x286d: cmp    r13,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4094ULL);
x86_l_2874:
	/* 0x2874: ja     28ae <generic_lsm_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28ae;
	}
x86_l_2876:
	/* 0x2876: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_287b:
	/* 0x287b: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_287e:
	/* 0x287e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2884:
	/* 0x2884: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2887:
	/* 0x2887: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_288c:
	/* 0x288c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2891:
	/* 0x2891: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2896:
	/* 0x2896: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_2899:
	/* 0x2899: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_289b:
	/* 0x289b: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_28a0:
	/* 0x28a0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28a2:
	/* 0x28a2: js     28ae <generic_lsm_process_event+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28ae;
	}
x86_l_28a4:
	/* 0x28a4: add    QWORD PTR [rsp+0x8],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_28a9:
	/* 0x28a9: jmp    2985 <generic_lsm_process_event+0x2985> */
	goto x86_l_2985;
x86_l_28ae:
	/* 0x28ae: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_28b3:
	/* 0x28b3: mov    DWORD PTR [r12+rax*1],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_28b7:
	/* 0x28b7: jmp    2b34 <generic_lsm_process_event+0x2b34> */
	return 11060ULL;
x86_l_28bc:
	/* 0x28bc: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28bf:
	/* 0x28bf: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_28c4:
	/* 0x28c4: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28c9:
	/* 0x28c9: test   BYTE PTR [rsp+0x40],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906960ULL);
x86_l_28ce:
	/* 0x28ce: je     2985 <generic_lsm_process_event+0x2985> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2985;
	}
x86_l_28d4:
	/* 0x28d4: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_28d9:
	/* 0x28d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28db:
	/* 0x28db: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_28df:
	/* 0x28df: jne    28e5 <generic_lsm_process_event+0x28e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28e5;
	}
x86_l_28e1:
	/* 0x28e1: mov    rax,QWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28e5:
	/* 0x28e5: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28ea:
	/* 0x28ea: mov    rcx,QWORD PTR [rdx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28ee:
	/* 0x28ee: mov    rdx,QWORD PTR [rdx+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_28f2:
	/* 0x28f2: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_28f7:
	/* 0x28f7: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28fc:
	/* 0x28fc: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2901:
	/* 0x2901: mov    QWORD PTR [rsp+0x78],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2906:
	/* 0x2906: mov    QWORD PTR [rsp+0xa8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_290e:
	/* 0x290e: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2916:
	/* 0x2916: mov    rdi,QWORD PTR [rip+0x1c8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_291d:
	/* 0x291d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_291f:
	/* 0x291f: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2927:
	/* 0x2927: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_292c:
	/* 0x292c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2931:
	/* 0x2931: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2933:
	/* 0x2933: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2935:
	/* 0x2935: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2938:
	/* 0x2938: je     2b21 <generic_lsm_process_event+0x2b21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11041ULL;
	}
x86_l_293e:
	/* 0x293e: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2940:
	/* 0x2940: mov    WORD PTR [rsp+0x58],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2945:
	/* 0x2945: mov    WORD PTR [rsp+0x5a],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 386547056645ULL);
x86_l_294c:
	/* 0x294c: movabs rax,0x200000057 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934679ULL);
x86_l_2956:
	/* 0x2956: mov    QWORD PTR [rsp+0x5c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_295b:
	/* 0x295b: mov    rdi,QWORD PTR [rip+0x1c8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2962:
	/* 0x2962: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2967:
	/* 0x2967: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_296c:
	/* 0x296c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_296e:
	/* 0x296e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2971:
	/* 0x2971: je     2afd <generic_lsm_process_event+0x2afd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11005ULL;
	}
x86_l_2977:
	/* 0x2977: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2979:
	/* 0x2979: jmp    2b21 <generic_lsm_process_event+0x2b21> */
	return 11041ULL;
x86_l_297e:
	/* 0x297e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2980:
	/* 0x2980: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2985:
	/* 0x2985: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_298a:
	/* 0x298a: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_298f:
	/* 0x298f: mov    DWORD PTR [r12+rax*1],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2993:
	/* 0x2993: mov    DWORD PTR [r12+rax*1+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_2998:
	/* 0x2998: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_299c:
	/* 0x299c: jmp    2b34 <generic_lsm_process_event+0x2b34> */
	return 11060ULL;
x86_l_29a1:
	/* 0x29a1: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_29a8:
	/* 0x29a8: mov    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29af:
	/* 0x29af: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29b4:
	/* 0x29b4: lea    r14d,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29b8:
	/* 0x29b8: and    r14d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_29bf:
	/* 0x29bf: add    r14,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29c2:
	/* 0x29c2: mov    r15d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 12ULL);
x86_l_29c8:
	/* 0x29c8: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_29cf:
	/* 0x29cf: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_29d5:
	/* 0x29d5: cmovb  r12,r13 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_29d9:
	/* 0x29d9: lea    rdi,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29dd:
	/* 0x29dd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29e2:
	/* 0x29e2: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_29e5:
	/* 0x29e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29e7:
	/* 0x29e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29e9:
	/* 0x29e9: js     29ff <generic_lsm_process_event+0x29ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29ff;
	}
x86_l_29eb:
	/* 0x29eb: mov    DWORD PTR [r14],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29ee:
	/* 0x29ee: mov    DWORD PTR [r14+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_29f2:
	/* 0x29f2: add    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29f5:
	/* 0x29f5: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29fa:
	/* 0x29fa: jmp    333d <generic_lsm_process_event+0x333d> */
	return 13117ULL;
x86_l_29ff:
	/* 0x29ff: mov    DWORD PTR [r14],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_2a06:
	/* 0x2a06: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2a0c:
	/* 0x2a0c: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a11:
	/* 0x2a11: jmp    333d <generic_lsm_process_event+0x333d> */
	return 13117ULL;
	return 10774ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10774ULL: goto x86_l_2a16;
	case 10781ULL: goto x86_l_2a1d;
	case 10789ULL: goto x86_l_2a25;
	case 10794ULL: goto x86_l_2a2a;
	case 10798ULL: goto x86_l_2a2e;
	case 10805ULL: goto x86_l_2a35;
	case 10808ULL: goto x86_l_2a38;
	case 10813ULL: goto x86_l_2a3d;
	case 10818ULL: goto x86_l_2a42;
	case 10825ULL: goto x86_l_2a49;
	case 10831ULL: goto x86_l_2a4f;
	case 10835ULL: goto x86_l_2a53;
	case 10840ULL: goto x86_l_2a58;
	case 10845ULL: goto x86_l_2a5d;
	case 10851ULL: goto x86_l_2a63;
	case 10854ULL: goto x86_l_2a66;
	case 10856ULL: goto x86_l_2a68;
	case 10858ULL: goto x86_l_2a6a;
	case 10860ULL: goto x86_l_2a6c;
	case 10864ULL: goto x86_l_2a70;
	case 10869ULL: goto x86_l_2a75;
	case 10874ULL: goto x86_l_2a7a;
	case 10877ULL: goto x86_l_2a7d;
	case 10882ULL: goto x86_l_2a82;
	case 10887ULL: goto x86_l_2a87;
	case 10895ULL: goto x86_l_2a8f;
	case 10900ULL: goto x86_l_2a94;
	case 10905ULL: goto x86_l_2a99;
	case 10908ULL: goto x86_l_2a9c;
	case 10914ULL: goto x86_l_2aa2;
	case 10917ULL: goto x86_l_2aa5;
	case 10923ULL: goto x86_l_2aab;
	case 10928ULL: goto x86_l_2ab0;
	case 10934ULL: goto x86_l_2ab6;
	case 10941ULL: goto x86_l_2abd;
	case 10945ULL: goto x86_l_2ac1;
	case 10950ULL: goto x86_l_2ac6;
	case 10961ULL: goto x86_l_2ad1;
	case 10968ULL: goto x86_l_2ad8;
	case 10970ULL: goto x86_l_2ada;
	case 10975ULL: goto x86_l_2adf;
	case 10983ULL: goto x86_l_2ae7;
	case 10988ULL: goto x86_l_2aec;
	case 10990ULL: goto x86_l_2aee;
	case 10992ULL: goto x86_l_2af0;
	case 11000ULL: goto x86_l_2af8;
	case 11005ULL: goto x86_l_2afd;
	case 11013ULL: goto x86_l_2b05;
	case 11020ULL: goto x86_l_2b0c;
	case 11022ULL: goto x86_l_2b0e;
	case 11027ULL: goto x86_l_2b13;
	case 11032ULL: goto x86_l_2b18;
	case 11037ULL: goto x86_l_2b1d;
	case 11039ULL: goto x86_l_2b1f;
	case 11041ULL: goto x86_l_2b21;
	case 11046ULL: goto x86_l_2b26;
	case 11054ULL: goto x86_l_2b2e;
	case 11060ULL: goto x86_l_2b34;
	case 11065ULL: goto x86_l_2b39;
	case 11068ULL: goto x86_l_2b3c;
	case 11073ULL: goto x86_l_2b41;
	case 11078ULL: goto x86_l_2b46;
	case 11085ULL: goto x86_l_2b4d;
	case 11090ULL: goto x86_l_2b52;
	case 11097ULL: goto x86_l_2b59;
	case 11099ULL: goto x86_l_2b5b;
	case 11106ULL: goto x86_l_2b62;
	case 11108ULL: goto x86_l_2b64;
	case 11115ULL: goto x86_l_2b6b;
	case 11118ULL: goto x86_l_2b6e;
	case 11123ULL: goto x86_l_2b73;
	case 11131ULL: goto x86_l_2b7b;
	case 11136ULL: goto x86_l_2b80;
	case 11141ULL: goto x86_l_2b85;
	case 11146ULL: goto x86_l_2b8a;
	case 11152ULL: goto x86_l_2b90;
	case 11157ULL: goto x86_l_2b95;
	case 11159ULL: goto x86_l_2b97;
	case 11167ULL: goto x86_l_2b9f;
	case 11170ULL: goto x86_l_2ba2;
	case 11172ULL: goto x86_l_2ba4;
	case 11179ULL: goto x86_l_2bab;
	case 11181ULL: goto x86_l_2bad;
	case 11189ULL: goto x86_l_2bb5;
	case 11193ULL: goto x86_l_2bb9;
	case 11198ULL: goto x86_l_2bbe;
	case 11201ULL: goto x86_l_2bc1;
	case 11204ULL: goto x86_l_2bc4;
	case 11209ULL: goto x86_l_2bc9;
	case 11212ULL: goto x86_l_2bcc;
	case 11217ULL: goto x86_l_2bd1;
	case 11220ULL: goto x86_l_2bd4;
	case 11224ULL: goto x86_l_2bd8;
	case 11229ULL: goto x86_l_2bdd;
	case 11234ULL: goto x86_l_2be2;
	case 11241ULL: goto x86_l_2be9;
	case 11249ULL: goto x86_l_2bf1;
	case 11254ULL: goto x86_l_2bf6;
	case 11258ULL: goto x86_l_2bfa;
	case 11265ULL: goto x86_l_2c01;
	case 11268ULL: goto x86_l_2c04;
	case 11274ULL: goto x86_l_2c0a;
	case 11281ULL: goto x86_l_2c11;
	case 11286ULL: goto x86_l_2c16;
	case 11290ULL: goto x86_l_2c1a;
	case 11295ULL: goto x86_l_2c1f;
	case 11300ULL: goto x86_l_2c24;
	case 11305ULL: goto x86_l_2c29;
	case 11307ULL: goto x86_l_2c2b;
	case 11309ULL: goto x86_l_2c2d;
	case 11311ULL: goto x86_l_2c2f;
	case 11313ULL: goto x86_l_2c31;
	case 11317ULL: goto x86_l_2c35;
	case 11322ULL: goto x86_l_2c3a;
	case 11325ULL: goto x86_l_2c3d;
	case 11330ULL: goto x86_l_2c42;
	case 11338ULL: goto x86_l_2c4a;
	case 11344ULL: goto x86_l_2c50;
	case 11349ULL: goto x86_l_2c55;
	case 11354ULL: goto x86_l_2c5a;
	case 11361ULL: goto x86_l_2c61;
	case 11366ULL: goto x86_l_2c66;
	case 11370ULL: goto x86_l_2c6a;
	case 11374ULL: goto x86_l_2c6e;
	case 11379ULL: goto x86_l_2c73;
	case 11383ULL: goto x86_l_2c77;
	case 11389ULL: goto x86_l_2c7d;
	case 11399ULL: goto x86_l_2c87;
	case 11403ULL: goto x86_l_2c8b;
	case 11409ULL: goto x86_l_2c91;
	case 11413ULL: goto x86_l_2c95;
	case 11416ULL: goto x86_l_2c98;
	case 11419ULL: goto x86_l_2c9b;
	case 11424ULL: goto x86_l_2ca0;
	case 11429ULL: goto x86_l_2ca5;
	case 11434ULL: goto x86_l_2caa;
	case 11438ULL: goto x86_l_2cae;
	case 11441ULL: goto x86_l_2cb1;
	case 11446ULL: goto x86_l_2cb6;
	case 11448ULL: goto x86_l_2cb8;
	case 11451ULL: goto x86_l_2cbb;
	case 11457ULL: goto x86_l_2cc1;
	case 11462ULL: goto x86_l_2cc6;
	case 11465ULL: goto x86_l_2cc9;
	case 11467ULL: goto x86_l_2ccb;
	case 11469ULL: goto x86_l_2ccd;
	case 11471ULL: goto x86_l_2ccf;
	case 11474ULL: goto x86_l_2cd2;
	case 11476ULL: goto x86_l_2cd4;
	case 11479ULL: goto x86_l_2cd7;
	case 11481ULL: goto x86_l_2cd9;
	case 11488ULL: goto x86_l_2ce0;
	case 11492ULL: goto x86_l_2ce4;
	case 11494ULL: goto x86_l_2ce6;
	case 11497ULL: goto x86_l_2ce9;
	case 11499ULL: goto x86_l_2ceb;
	case 11502ULL: goto x86_l_2cee;
	case 11504ULL: goto x86_l_2cf0;
	case 11509ULL: goto x86_l_2cf5;
	case 11511ULL: goto x86_l_2cf7;
	case 11518ULL: goto x86_l_2cfe;
	case 11522ULL: goto x86_l_2d02;
	case 11524ULL: goto x86_l_2d04;
	case 11529ULL: goto x86_l_2d09;
	case 11536ULL: goto x86_l_2d10;
	case 11541ULL: goto x86_l_2d15;
	case 11543ULL: goto x86_l_2d17;
	case 11548ULL: goto x86_l_2d1c;
	case 11553ULL: goto x86_l_2d21;
	case 11558ULL: goto x86_l_2d26;
	case 11565ULL: goto x86_l_2d2d;
	case 11570ULL: goto x86_l_2d32;
	case 11572ULL: goto x86_l_2d34;
	case 11577ULL: goto x86_l_2d39;
	case 11581ULL: goto x86_l_2d3d;
	case 11585ULL: goto x86_l_2d41;
	case 11590ULL: goto x86_l_2d46;
	case 11594ULL: goto x86_l_2d4a;
	case 11600ULL: goto x86_l_2d50;
	case 11610ULL: goto x86_l_2d5a;
	case 11614ULL: goto x86_l_2d5e;
	case 11620ULL: goto x86_l_2d64;
	case 11624ULL: goto x86_l_2d68;
	case 11627ULL: goto x86_l_2d6b;
	case 11630ULL: goto x86_l_2d6e;
	case 11635ULL: goto x86_l_2d73;
	case 11640ULL: goto x86_l_2d78;
	case 11645ULL: goto x86_l_2d7d;
	case 11649ULL: goto x86_l_2d81;
	case 11652ULL: goto x86_l_2d84;
	case 11657ULL: goto x86_l_2d89;
	case 11659ULL: goto x86_l_2d8b;
	case 11662ULL: goto x86_l_2d8e;
	case 11668ULL: goto x86_l_2d94;
	case 11673ULL: goto x86_l_2d99;
	case 11676ULL: goto x86_l_2d9c;
	case 11678ULL: goto x86_l_2d9e;
	case 11680ULL: goto x86_l_2da0;
	case 11682ULL: goto x86_l_2da2;
	case 11685ULL: goto x86_l_2da5;
	case 11687ULL: goto x86_l_2da7;
	case 11690ULL: goto x86_l_2daa;
	case 11692ULL: goto x86_l_2dac;
	case 11699ULL: goto x86_l_2db3;
	case 11703ULL: goto x86_l_2db7;
	case 11705ULL: goto x86_l_2db9;
	case 11708ULL: goto x86_l_2dbc;
	case 11710ULL: goto x86_l_2dbe;
	case 11713ULL: goto x86_l_2dc1;
	case 11715ULL: goto x86_l_2dc3;
	case 11720ULL: goto x86_l_2dc8;
	case 11722ULL: goto x86_l_2dca;
	case 11729ULL: goto x86_l_2dd1;
	case 11733ULL: goto x86_l_2dd5;
	case 11735ULL: goto x86_l_2dd7;
	case 11740ULL: goto x86_l_2ddc;
	case 11747ULL: goto x86_l_2de3;
	case 11752ULL: goto x86_l_2de8;
	case 11754ULL: goto x86_l_2dea;
	case 11759ULL: goto x86_l_2def;
	case 11766ULL: goto x86_l_2df6;
	case 11771ULL: goto x86_l_2dfb;
	case 11773ULL: goto x86_l_2dfd;
	case 11778ULL: goto x86_l_2e02;
	case 11782ULL: goto x86_l_2e06;
	case 11786ULL: goto x86_l_2e0a;
	case 11791ULL: goto x86_l_2e0f;
	case 11795ULL: goto x86_l_2e13;
	case 11801ULL: goto x86_l_2e19;
	case 11811ULL: goto x86_l_2e23;
	case 11815ULL: goto x86_l_2e27;
	case 11821ULL: goto x86_l_2e2d;
	case 11825ULL: goto x86_l_2e31;
	case 11828ULL: goto x86_l_2e34;
	case 11831ULL: goto x86_l_2e37;
	case 11836ULL: goto x86_l_2e3c;
	case 11841ULL: goto x86_l_2e41;
	case 11846ULL: goto x86_l_2e46;
	case 11850ULL: goto x86_l_2e4a;
	case 11853ULL: goto x86_l_2e4d;
	case 11858ULL: goto x86_l_2e52;
	case 11860ULL: goto x86_l_2e54;
	case 11863ULL: goto x86_l_2e57;
	case 11869ULL: goto x86_l_2e5d;
	case 11874ULL: goto x86_l_2e62;
	case 11877ULL: goto x86_l_2e65;
	case 11879ULL: goto x86_l_2e67;
	case 11881ULL: goto x86_l_2e69;
	case 11883ULL: goto x86_l_2e6b;
	case 11886ULL: goto x86_l_2e6e;
	case 11888ULL: goto x86_l_2e70;
	case 11891ULL: goto x86_l_2e73;
	case 11893ULL: goto x86_l_2e75;
	case 11900ULL: goto x86_l_2e7c;
	case 11904ULL: goto x86_l_2e80;
	case 11906ULL: goto x86_l_2e82;
	case 11909ULL: goto x86_l_2e85;
	case 11911ULL: goto x86_l_2e87;
	case 11914ULL: goto x86_l_2e8a;
	case 11916ULL: goto x86_l_2e8c;
	case 11921ULL: goto x86_l_2e91;
	case 11923ULL: goto x86_l_2e93;
	case 11930ULL: goto x86_l_2e9a;
	case 11934ULL: goto x86_l_2e9e;
	case 11936ULL: goto x86_l_2ea0;
	case 11941ULL: goto x86_l_2ea5;
	case 11948ULL: goto x86_l_2eac;
	case 11953ULL: goto x86_l_2eb1;
	case 11955ULL: goto x86_l_2eb3;
	case 11960ULL: goto x86_l_2eb8;
	case 11967ULL: goto x86_l_2ebf;
	case 11972ULL: goto x86_l_2ec4;
	case 11974ULL: goto x86_l_2ec6;
	case 11979ULL: goto x86_l_2ecb;
	case 11983ULL: goto x86_l_2ecf;
	case 11987ULL: goto x86_l_2ed3;
	case 11992ULL: goto x86_l_2ed8;
	case 11996ULL: goto x86_l_2edc;
	case 12002ULL: goto x86_l_2ee2;
	case 12012ULL: goto x86_l_2eec;
	case 12016ULL: goto x86_l_2ef0;
	case 12022ULL: goto x86_l_2ef6;
	case 12026ULL: goto x86_l_2efa;
	case 12029ULL: goto x86_l_2efd;
	case 12032ULL: goto x86_l_2f00;
	case 12037ULL: goto x86_l_2f05;
	case 12042ULL: goto x86_l_2f0a;
	case 12047ULL: goto x86_l_2f0f;
	case 12051ULL: goto x86_l_2f13;
	case 12054ULL: goto x86_l_2f16;
	case 12059ULL: goto x86_l_2f1b;
	case 12061ULL: goto x86_l_2f1d;
	case 12064ULL: goto x86_l_2f20;
	case 12070ULL: goto x86_l_2f26;
	case 12075ULL: goto x86_l_2f2b;
	case 12078ULL: goto x86_l_2f2e;
	case 12080ULL: goto x86_l_2f30;
	case 12082ULL: goto x86_l_2f32;
	case 12084ULL: goto x86_l_2f34;
	case 12087ULL: goto x86_l_2f37;
	case 12089ULL: goto x86_l_2f39;
	case 12092ULL: goto x86_l_2f3c;
	case 12094ULL: goto x86_l_2f3e;
	case 12101ULL: goto x86_l_2f45;
	case 12105ULL: goto x86_l_2f49;
	case 12107ULL: goto x86_l_2f4b;
	case 12110ULL: goto x86_l_2f4e;
	case 12112ULL: goto x86_l_2f50;
	case 12115ULL: goto x86_l_2f53;
	case 12117ULL: goto x86_l_2f55;
	case 12122ULL: goto x86_l_2f5a;
	case 12124ULL: goto x86_l_2f5c;
	case 12131ULL: goto x86_l_2f63;
	case 12135ULL: goto x86_l_2f67;
	case 12137ULL: goto x86_l_2f69;
	case 12142ULL: goto x86_l_2f6e;
	case 12149ULL: goto x86_l_2f75;
	case 12154ULL: goto x86_l_2f7a;
	case 12156ULL: goto x86_l_2f7c;
	case 12161ULL: goto x86_l_2f81;
	case 12168ULL: goto x86_l_2f88;
	case 12173ULL: goto x86_l_2f8d;
	case 12175ULL: goto x86_l_2f8f;
	case 12180ULL: goto x86_l_2f94;
	case 12184ULL: goto x86_l_2f98;
	case 12188ULL: goto x86_l_2f9c;
	case 12193ULL: goto x86_l_2fa1;
	case 12197ULL: goto x86_l_2fa5;
	case 12203ULL: goto x86_l_2fab;
	case 12213ULL: goto x86_l_2fb5;
	case 12217ULL: goto x86_l_2fb9;
	case 12223ULL: goto x86_l_2fbf;
	case 12227ULL: goto x86_l_2fc3;
	case 12230ULL: goto x86_l_2fc6;
	case 12233ULL: goto x86_l_2fc9;
	case 12238ULL: goto x86_l_2fce;
	case 12243ULL: goto x86_l_2fd3;
	case 12248ULL: goto x86_l_2fd8;
	case 12252ULL: goto x86_l_2fdc;
	case 12255ULL: goto x86_l_2fdf;
	case 12260ULL: goto x86_l_2fe4;
	case 12262ULL: goto x86_l_2fe6;
	case 12265ULL: goto x86_l_2fe9;
	case 12271ULL: goto x86_l_2fef;
	case 12276ULL: goto x86_l_2ff4;
	case 12279ULL: goto x86_l_2ff7;
	case 12281ULL: goto x86_l_2ff9;
	case 12283ULL: goto x86_l_2ffb;
	case 12285ULL: goto x86_l_2ffd;
	case 12288ULL: goto x86_l_3000;
	case 12290ULL: goto x86_l_3002;
	case 12293ULL: goto x86_l_3005;
	case 12295ULL: goto x86_l_3007;
	case 12302ULL: goto x86_l_300e;
	case 12306ULL: goto x86_l_3012;
	case 12308ULL: goto x86_l_3014;
	case 12311ULL: goto x86_l_3017;
	case 12313ULL: goto x86_l_3019;
	case 12316ULL: goto x86_l_301c;
	case 12318ULL: goto x86_l_301e;
	case 12323ULL: goto x86_l_3023;
	case 12325ULL: goto x86_l_3025;
	case 12332ULL: goto x86_l_302c;
	case 12336ULL: goto x86_l_3030;
	case 12338ULL: goto x86_l_3032;
	case 12343ULL: goto x86_l_3037;
	case 12350ULL: goto x86_l_303e;
	case 12355ULL: goto x86_l_3043;
	case 12357ULL: goto x86_l_3045;
	case 12362ULL: goto x86_l_304a;
	case 12369ULL: goto x86_l_3051;
	case 12374ULL: goto x86_l_3056;
	case 12376ULL: goto x86_l_3058;
	case 12381ULL: goto x86_l_305d;
	case 12385ULL: goto x86_l_3061;
	case 12389ULL: goto x86_l_3065;
	case 12394ULL: goto x86_l_306a;
	case 12398ULL: goto x86_l_306e;
	case 12404ULL: goto x86_l_3074;
	case 12414ULL: goto x86_l_307e;
	case 12418ULL: goto x86_l_3082;
	case 12424ULL: goto x86_l_3088;
	case 12428ULL: goto x86_l_308c;
	case 12431ULL: goto x86_l_308f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a16:
	/* 0x2a16: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2a1d:
	/* 0x2a1d: mov    DWORD PTR [r12],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a25:
	/* 0x2a25: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a2a:
	/* 0x2a2a: lea    r12d,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a2e:
	/* 0x2a2e: and    r12d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2a35:
	/* 0x2a35: add    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a38:
	/* 0x2a38: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2a3d:
	/* 0x2a3d: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a42:
	/* 0x2a42: cmp    r14,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 4095ULL);
x86_l_2a49:
	/* 0x2a49: mov    r13d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4095ULL);
x86_l_2a4f:
	/* 0x2a4f: cmovb  r13,r14 */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_R14, X86_WIDTH_64, X86_CC_B);
x86_l_2a53:
	/* 0x2a53: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a58:
	/* 0x2a58: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a5d:
	/* 0x2a5d: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2a63:
	/* 0x2a63: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_2a66:
	/* 0x2a66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a68:
	/* 0x2a68: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a6a:
	/* 0x2a6a: js     2a87 <generic_lsm_process_event+0x2a87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2a87;
	}
x86_l_2a6c:
	/* 0x2a6c: mov    DWORD PTR [r12],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a70:
	/* 0x2a70: mov    DWORD PTR [r12+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2a75:
	/* 0x2a75: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a7a:
	/* 0x2a7a: add    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a7d:
	/* 0x2a7d: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a82:
	/* 0x2a82: jmp    333d <generic_lsm_process_event+0x333d> */
	return 13117ULL;
x86_l_2a87:
	/* 0x2a87: mov    DWORD PTR [r12],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_2a8f:
	/* 0x2a8f: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a94:
	/* 0x2a94: jmp    333d <generic_lsm_process_event+0x333d> */
	return 13117ULL;
x86_l_2a99:
	/* 0x2a99: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2a9c:
	/* 0x2a9c: je     2c55 <generic_lsm_process_event+0x2c55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c55;
	}
x86_l_2aa2:
	/* 0x2aa2: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2aa5:
	/* 0x2aa5: je     2b41 <generic_lsm_process_event+0x2b41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b41;
	}
x86_l_2aab:
	/* 0x2aab: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2ab0:
	/* 0x2ab0: jne    2d17 <generic_lsm_process_event+0x2d17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d17;
	}
x86_l_2ab6:
	/* 0x2ab6: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2abd:
	/* 0x2abd: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2ac1:
	/* 0x2ac1: jmp    2c66 <generic_lsm_process_event+0x2c66> */
	goto x86_l_2c66;
x86_l_2ac6:
	/* 0x2ac6: mov    DWORD PTR [rsp+0xc0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 824633720833ULL);
x86_l_2ad1:
	/* 0x2ad1: mov    rdi,QWORD PTR [rip+0x1c8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2ad8:
	/* 0x2ad8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ada:
	/* 0x2ada: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2adf:
	/* 0x2adf: lea    rdx,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2ae7:
	/* 0x2ae7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2aec:
	/* 0x2aec: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2aee:
	/* 0x2aee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2af0:
	/* 0x2af0: mov    DWORD PTR [r12],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967292ULL);
x86_l_2af8:
	/* 0x2af8: jmp    2c4a <generic_lsm_process_event+0x2c4a> */
	goto x86_l_2c4a;
x86_l_2afd:
	/* 0x2afd: mov    DWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_2b05:
	/* 0x2b05: mov    rdi,QWORD PTR [rip+0x1c8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2b0c:
	/* 0x2b0c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b0e:
	/* 0x2b0e: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2b13:
	/* 0x2b13: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b18:
	/* 0x2b18: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2b1d:
	/* 0x2b1d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b1f:
	/* 0x2b1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b21:
	/* 0x2b21: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b26:
	/* 0x2b26: mov    DWORD PTR [r12+rax*1],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4294967292ULL);
x86_l_2b2e:
	/* 0x2b2e: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2b34:
	/* 0x2b34: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b39:
	/* 0x2b39: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_2b3c:
	/* 0x2b3c: jmp    3342 <generic_lsm_process_event+0x3342> */
	return 13122ULL;
x86_l_2b41:
	/* 0x2b41: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2b46:
	/* 0x2b46: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2b4d:
	/* 0x2b4d: jmp    2c61 <generic_lsm_process_event+0x2c61> */
	goto x86_l_2c61;
x86_l_2b52:
	/* 0x2b52: lea    rax,[rbp+0x5e60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24160ULL);
x86_l_2b59:
	/* 0x2b59: jmp    2b6b <generic_lsm_process_event+0x2b6b> */
	goto x86_l_2b6b;
x86_l_2b5b:
	/* 0x2b5b: lea    rax,[rbp+0x5e68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24168ULL);
x86_l_2b62:
	/* 0x2b62: jmp    2b6b <generic_lsm_process_event+0x2b6b> */
	goto x86_l_2b6b;
x86_l_2b64:
	/* 0x2b64: lea    rax,[rbp+0x5e50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24144ULL);
x86_l_2b6b:
	/* 0x2b6b: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b6e:
	/* 0x2b6e: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b73:
	/* 0x2b73: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2b7b:
	/* 0x2b7b: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b80:
	/* 0x2b80: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b85:
	/* 0x2b85: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b8a:
	/* 0x2b8a: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_2b90:
	/* 0x2b90: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b95:
	/* 0x2b95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b97:
	/* 0x2b97: mov    r13,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2b9f:
	/* 0x2b9f: test   bl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_8, 32ULL);
x86_l_2ba2:
	/* 0x2ba2: je     2c0a <generic_lsm_process_event+0x2c0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c0a;
	}
x86_l_2ba4:
	/* 0x2ba4: cmp    r13,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4096ULL);
x86_l_2bab:
	/* 0x2bab: jb     2be2 <generic_lsm_process_event+0x2be2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2be2;
	}
x86_l_2bad:
	/* 0x2bad: mov    DWORD PTR [r12],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2bb5:
	/* 0x2bb5: add    r12,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2bb9:
	/* 0x2bb9: mov    rbx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2bbe:
	/* 0x2bbe: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2bc1:
	/* 0x2bc1: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2bc4:
	/* 0x2bc4: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2bc9:
	/* 0x2bc9: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_2bcc:
	/* 0x2bcc: call   0 <generic_lsm_process_event> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 11217ULL);
	__x86_sim_call_depth++;
	return 13716ULL;
x86_l_2bd1:
	/* 0x2bd1: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2bd4:
	/* 0x2bd4: add    r15,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2bd8:
	/* 0x2bd8: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bdd:
	/* 0x2bdd: jmp    333d <generic_lsm_process_event+0x333d> */
	return 13117ULL;
x86_l_2be2:
	/* 0x2be2: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2be9:
	/* 0x2be9: mov    DWORD PTR [r12],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bf1:
	/* 0x2bf1: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2bf6:
	/* 0x2bf6: lea    r12d,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bfa:
	/* 0x2bfa: and    r12d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2c01:
	/* 0x2c01: add    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c04:
	/* 0x2c04: mov    r15d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 12ULL);
x86_l_2c0a:
	/* 0x2c0a: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_2c11:
	/* 0x2c11: mov    ebx,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4095ULL);
x86_l_2c16:
	/* 0x2c16: cmovb  rbx,r13 */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_2c1a:
	/* 0x2c1a: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c1f:
	/* 0x2c1f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c24:
	/* 0x2c24: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c29:
	/* 0x2c29: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_2c2b:
	/* 0x2c2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c2d:
	/* 0x2c2d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c2f:
	/* 0x2c2f: js     2c42 <generic_lsm_process_event+0x2c42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c42;
	}
x86_l_2c31:
	/* 0x2c31: mov    DWORD PTR [r12],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c35:
	/* 0x2c35: mov    DWORD PTR [r12+0x4],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c3a:
	/* 0x2c3a: add    r15,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c3d:
	/* 0x2c3d: jmp    3333 <generic_lsm_process_event+0x3333> */
	return 13107ULL;
x86_l_2c42:
	/* 0x2c42: mov    DWORD PTR [r12],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_2c4a:
	/* 0x2c4a: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2c50:
	/* 0x2c50: jmp    3333 <generic_lsm_process_event+0x3333> */
	return 13107ULL;
x86_l_2c55:
	/* 0x2c55: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2c5a:
	/* 0x2c5a: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2c61:
	/* 0x2c61: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2c66:
	/* 0x2c66: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2c6a:
	/* 0x2c6a: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c6e:
	/* 0x2c6e: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2c73:
	/* 0x2c73: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2c77:
	/* 0x2c77: ja     3355 <generic_lsm_process_event+0x3355> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13141ULL;
	}
x86_l_2c7d:
	/* 0x2c7d: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2c87:
	/* 0x2c87: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2c8b:
	/* 0x2c8b: jae    3355 <generic_lsm_process_event+0x3355> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13141ULL;
	}
x86_l_2c91:
	/* 0x2c91: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2c95:
	/* 0x2c95: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2c98:
	/* 0x2c98: add    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c9b:
	/* 0x2c9b: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2ca0:
	/* 0x2ca0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ca5:
	/* 0x2ca5: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2caa:
	/* 0x2caa: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2cae:
	/* 0x2cae: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2cb1:
	/* 0x2cb1: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2cb6:
	/* 0x2cb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cb8:
	/* 0x2cb8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cbb:
	/* 0x2cbb: js     3178 <generic_lsm_process_event+0x3178> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12664ULL;
	}
x86_l_2cc1:
	/* 0x2cc1: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2cc6:
	/* 0x2cc6: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2cc9:
	/* 0x2cc9: jg     2ce6 <generic_lsm_process_event+0x2ce6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2ce6;
	}
x86_l_2ccb:
	/* 0x2ccb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ccd:
	/* 0x2ccd: je     2d04 <generic_lsm_process_event+0x2d04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d04;
	}
x86_l_2ccf:
	/* 0x2ccf: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2cd2:
	/* 0x2cd2: je     2d04 <generic_lsm_process_event+0x2d04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d04;
	}
x86_l_2cd4:
	/* 0x2cd4: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2cd7:
	/* 0x2cd7: jne    2d34 <generic_lsm_process_event+0x2d34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d34;
	}
x86_l_2cd9:
	/* 0x2cd9: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2ce0:
	/* 0x2ce0: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2ce4:
	/* 0x2ce4: jmp    2d39 <generic_lsm_process_event+0x2d39> */
	goto x86_l_2d39;
x86_l_2ce6:
	/* 0x2ce6: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2ce9:
	/* 0x2ce9: je     2d21 <generic_lsm_process_event+0x2d21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d21;
	}
x86_l_2ceb:
	/* 0x2ceb: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2cee:
	/* 0x2cee: je     2d04 <generic_lsm_process_event+0x2d04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d04;
	}
x86_l_2cf0:
	/* 0x2cf0: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2cf5:
	/* 0x2cf5: jne    2d34 <generic_lsm_process_event+0x2d34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d34;
	}
x86_l_2cf7:
	/* 0x2cf7: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2cfe:
	/* 0x2cfe: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2d02:
	/* 0x2d02: jmp    2d39 <generic_lsm_process_event+0x2d39> */
	goto x86_l_2d39;
x86_l_2d04:
	/* 0x2d04: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2d09:
	/* 0x2d09: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2d10:
	/* 0x2d10: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2d15:
	/* 0x2d15: jmp    2d39 <generic_lsm_process_event+0x2d39> */
	goto x86_l_2d39;
x86_l_2d17:
	/* 0x2d17: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2d1c:
	/* 0x2d1c: jmp    2c66 <generic_lsm_process_event+0x2c66> */
	goto x86_l_2c66;
x86_l_2d21:
	/* 0x2d21: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2d26:
	/* 0x2d26: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2d2d:
	/* 0x2d2d: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2d32:
	/* 0x2d32: jmp    2d39 <generic_lsm_process_event+0x2d39> */
	goto x86_l_2d39;
x86_l_2d34:
	/* 0x2d34: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2d39:
	/* 0x2d39: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2d3d:
	/* 0x2d3d: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d41:
	/* 0x2d41: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2d46:
	/* 0x2d46: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2d4a:
	/* 0x2d4a: ja     3355 <generic_lsm_process_event+0x3355> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13141ULL;
	}
x86_l_2d50:
	/* 0x2d50: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2d5a:
	/* 0x2d5a: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2d5e:
	/* 0x2d5e: jae    3355 <generic_lsm_process_event+0x3355> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13141ULL;
	}
x86_l_2d64:
	/* 0x2d64: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2d68:
	/* 0x2d68: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2d6b:
	/* 0x2d6b: add    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d6e:
	/* 0x2d6e: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2d73:
	/* 0x2d73: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d78:
	/* 0x2d78: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d7d:
	/* 0x2d7d: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d81:
	/* 0x2d81: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d84:
	/* 0x2d84: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2d89:
	/* 0x2d89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d8b:
	/* 0x2d8b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d8e:
	/* 0x2d8e: js     3178 <generic_lsm_process_event+0x3178> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12664ULL;
	}
x86_l_2d94:
	/* 0x2d94: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2d99:
	/* 0x2d99: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2d9c:
	/* 0x2d9c: jg     2db9 <generic_lsm_process_event+0x2db9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2db9;
	}
x86_l_2d9e:
	/* 0x2d9e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2da0:
	/* 0x2da0: je     2dd7 <generic_lsm_process_event+0x2dd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dd7;
	}
x86_l_2da2:
	/* 0x2da2: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2da5:
	/* 0x2da5: je     2dd7 <generic_lsm_process_event+0x2dd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dd7;
	}
x86_l_2da7:
	/* 0x2da7: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2daa:
	/* 0x2daa: jne    2dfd <generic_lsm_process_event+0x2dfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2dfd;
	}
x86_l_2dac:
	/* 0x2dac: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2db3:
	/* 0x2db3: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2db7:
	/* 0x2db7: jmp    2e02 <generic_lsm_process_event+0x2e02> */
	goto x86_l_2e02;
x86_l_2db9:
	/* 0x2db9: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2dbc:
	/* 0x2dbc: je     2dea <generic_lsm_process_event+0x2dea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dea;
	}
x86_l_2dbe:
	/* 0x2dbe: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2dc1:
	/* 0x2dc1: je     2dd7 <generic_lsm_process_event+0x2dd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dd7;
	}
x86_l_2dc3:
	/* 0x2dc3: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2dc8:
	/* 0x2dc8: jne    2dfd <generic_lsm_process_event+0x2dfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2dfd;
	}
x86_l_2dca:
	/* 0x2dca: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2dd1:
	/* 0x2dd1: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2dd5:
	/* 0x2dd5: jmp    2e02 <generic_lsm_process_event+0x2e02> */
	goto x86_l_2e02;
x86_l_2dd7:
	/* 0x2dd7: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2ddc:
	/* 0x2ddc: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2de3:
	/* 0x2de3: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2de8:
	/* 0x2de8: jmp    2e02 <generic_lsm_process_event+0x2e02> */
	goto x86_l_2e02;
x86_l_2dea:
	/* 0x2dea: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2def:
	/* 0x2def: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2df6:
	/* 0x2df6: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2dfb:
	/* 0x2dfb: jmp    2e02 <generic_lsm_process_event+0x2e02> */
	goto x86_l_2e02;
x86_l_2dfd:
	/* 0x2dfd: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2e02:
	/* 0x2e02: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2e06:
	/* 0x2e06: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e0a:
	/* 0x2e0a: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2e0f:
	/* 0x2e0f: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2e13:
	/* 0x2e13: ja     3355 <generic_lsm_process_event+0x3355> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13141ULL;
	}
x86_l_2e19:
	/* 0x2e19: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2e23:
	/* 0x2e23: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2e27:
	/* 0x2e27: jae    3355 <generic_lsm_process_event+0x3355> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13141ULL;
	}
x86_l_2e2d:
	/* 0x2e2d: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2e31:
	/* 0x2e31: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2e34:
	/* 0x2e34: add    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e37:
	/* 0x2e37: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2e3c:
	/* 0x2e3c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e41:
	/* 0x2e41: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e46:
	/* 0x2e46: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e4a:
	/* 0x2e4a: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e4d:
	/* 0x2e4d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2e52:
	/* 0x2e52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e54:
	/* 0x2e54: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e57:
	/* 0x2e57: js     3178 <generic_lsm_process_event+0x3178> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12664ULL;
	}
x86_l_2e5d:
	/* 0x2e5d: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2e62:
	/* 0x2e62: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2e65:
	/* 0x2e65: jg     2e82 <generic_lsm_process_event+0x2e82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2e82;
	}
x86_l_2e67:
	/* 0x2e67: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e69:
	/* 0x2e69: je     2ea0 <generic_lsm_process_event+0x2ea0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ea0;
	}
x86_l_2e6b:
	/* 0x2e6b: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2e6e:
	/* 0x2e6e: je     2ea0 <generic_lsm_process_event+0x2ea0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ea0;
	}
x86_l_2e70:
	/* 0x2e70: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2e73:
	/* 0x2e73: jne    2ec6 <generic_lsm_process_event+0x2ec6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ec6;
	}
x86_l_2e75:
	/* 0x2e75: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2e7c:
	/* 0x2e7c: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2e80:
	/* 0x2e80: jmp    2ecb <generic_lsm_process_event+0x2ecb> */
	goto x86_l_2ecb;
x86_l_2e82:
	/* 0x2e82: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2e85:
	/* 0x2e85: je     2eb3 <generic_lsm_process_event+0x2eb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2eb3;
	}
x86_l_2e87:
	/* 0x2e87: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2e8a:
	/* 0x2e8a: je     2ea0 <generic_lsm_process_event+0x2ea0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ea0;
	}
x86_l_2e8c:
	/* 0x2e8c: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2e91:
	/* 0x2e91: jne    2ec6 <generic_lsm_process_event+0x2ec6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ec6;
	}
x86_l_2e93:
	/* 0x2e93: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2e9a:
	/* 0x2e9a: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2e9e:
	/* 0x2e9e: jmp    2ecb <generic_lsm_process_event+0x2ecb> */
	goto x86_l_2ecb;
x86_l_2ea0:
	/* 0x2ea0: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2ea5:
	/* 0x2ea5: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2eac:
	/* 0x2eac: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2eb1:
	/* 0x2eb1: jmp    2ecb <generic_lsm_process_event+0x2ecb> */
	goto x86_l_2ecb;
x86_l_2eb3:
	/* 0x2eb3: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2eb8:
	/* 0x2eb8: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2ebf:
	/* 0x2ebf: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2ec4:
	/* 0x2ec4: jmp    2ecb <generic_lsm_process_event+0x2ecb> */
	goto x86_l_2ecb;
x86_l_2ec6:
	/* 0x2ec6: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2ecb:
	/* 0x2ecb: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2ecf:
	/* 0x2ecf: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ed3:
	/* 0x2ed3: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2ed8:
	/* 0x2ed8: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2edc:
	/* 0x2edc: ja     3355 <generic_lsm_process_event+0x3355> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13141ULL;
	}
x86_l_2ee2:
	/* 0x2ee2: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2eec:
	/* 0x2eec: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2ef0:
	/* 0x2ef0: jae    3355 <generic_lsm_process_event+0x3355> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13141ULL;
	}
x86_l_2ef6:
	/* 0x2ef6: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2efa:
	/* 0x2efa: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2efd:
	/* 0x2efd: add    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f00:
	/* 0x2f00: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2f05:
	/* 0x2f05: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f0a:
	/* 0x2f0a: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f0f:
	/* 0x2f0f: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f13:
	/* 0x2f13: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f16:
	/* 0x2f16: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2f1b:
	/* 0x2f1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f1d:
	/* 0x2f1d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f20:
	/* 0x2f20: js     3178 <generic_lsm_process_event+0x3178> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12664ULL;
	}
x86_l_2f26:
	/* 0x2f26: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2f2b:
	/* 0x2f2b: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2f2e:
	/* 0x2f2e: jg     2f4b <generic_lsm_process_event+0x2f4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2f4b;
	}
x86_l_2f30:
	/* 0x2f30: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f32:
	/* 0x2f32: je     2f69 <generic_lsm_process_event+0x2f69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f69;
	}
x86_l_2f34:
	/* 0x2f34: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2f37:
	/* 0x2f37: je     2f69 <generic_lsm_process_event+0x2f69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f69;
	}
x86_l_2f39:
	/* 0x2f39: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2f3c:
	/* 0x2f3c: jne    2f8f <generic_lsm_process_event+0x2f8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f8f;
	}
x86_l_2f3e:
	/* 0x2f3e: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2f45:
	/* 0x2f45: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2f49:
	/* 0x2f49: jmp    2f94 <generic_lsm_process_event+0x2f94> */
	goto x86_l_2f94;
x86_l_2f4b:
	/* 0x2f4b: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2f4e:
	/* 0x2f4e: je     2f7c <generic_lsm_process_event+0x2f7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f7c;
	}
x86_l_2f50:
	/* 0x2f50: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2f53:
	/* 0x2f53: je     2f69 <generic_lsm_process_event+0x2f69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f69;
	}
x86_l_2f55:
	/* 0x2f55: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2f5a:
	/* 0x2f5a: jne    2f8f <generic_lsm_process_event+0x2f8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f8f;
	}
x86_l_2f5c:
	/* 0x2f5c: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2f63:
	/* 0x2f63: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2f67:
	/* 0x2f67: jmp    2f94 <generic_lsm_process_event+0x2f94> */
	goto x86_l_2f94;
x86_l_2f69:
	/* 0x2f69: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2f6e:
	/* 0x2f6e: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2f75:
	/* 0x2f75: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2f7a:
	/* 0x2f7a: jmp    2f94 <generic_lsm_process_event+0x2f94> */
	goto x86_l_2f94;
x86_l_2f7c:
	/* 0x2f7c: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2f81:
	/* 0x2f81: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2f88:
	/* 0x2f88: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2f8d:
	/* 0x2f8d: jmp    2f94 <generic_lsm_process_event+0x2f94> */
	goto x86_l_2f94;
x86_l_2f8f:
	/* 0x2f8f: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2f94:
	/* 0x2f94: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2f98:
	/* 0x2f98: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f9c:
	/* 0x2f9c: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2fa1:
	/* 0x2fa1: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2fa5:
	/* 0x2fa5: ja     3355 <generic_lsm_process_event+0x3355> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13141ULL;
	}
x86_l_2fab:
	/* 0x2fab: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2fb5:
	/* 0x2fb5: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2fb9:
	/* 0x2fb9: jae    3355 <generic_lsm_process_event+0x3355> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13141ULL;
	}
x86_l_2fbf:
	/* 0x2fbf: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2fc3:
	/* 0x2fc3: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2fc6:
	/* 0x2fc6: add    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2fc9:
	/* 0x2fc9: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2fce:
	/* 0x2fce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2fd3:
	/* 0x2fd3: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fd8:
	/* 0x2fd8: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2fdc:
	/* 0x2fdc: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2fdf:
	/* 0x2fdf: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2fe4:
	/* 0x2fe4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fe6:
	/* 0x2fe6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2fe9:
	/* 0x2fe9: js     3178 <generic_lsm_process_event+0x3178> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12664ULL;
	}
x86_l_2fef:
	/* 0x2fef: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2ff4:
	/* 0x2ff4: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2ff7:
	/* 0x2ff7: jg     3014 <generic_lsm_process_event+0x3014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3014;
	}
x86_l_2ff9:
	/* 0x2ff9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ffb:
	/* 0x2ffb: je     3032 <generic_lsm_process_event+0x3032> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3032;
	}
x86_l_2ffd:
	/* 0x2ffd: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_3000:
	/* 0x3000: je     3032 <generic_lsm_process_event+0x3032> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3032;
	}
x86_l_3002:
	/* 0x3002: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_3005:
	/* 0x3005: jne    3058 <generic_lsm_process_event+0x3058> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3058;
	}
x86_l_3007:
	/* 0x3007: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_300e:
	/* 0x300e: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_3012:
	/* 0x3012: jmp    305d <generic_lsm_process_event+0x305d> */
	goto x86_l_305d;
x86_l_3014:
	/* 0x3014: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_3017:
	/* 0x3017: je     3045 <generic_lsm_process_event+0x3045> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3045;
	}
x86_l_3019:
	/* 0x3019: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_301c:
	/* 0x301c: je     3032 <generic_lsm_process_event+0x3032> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3032;
	}
x86_l_301e:
	/* 0x301e: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_3023:
	/* 0x3023: jne    3058 <generic_lsm_process_event+0x3058> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3058;
	}
x86_l_3025:
	/* 0x3025: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_302c:
	/* 0x302c: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_3030:
	/* 0x3030: jmp    305d <generic_lsm_process_event+0x305d> */
	goto x86_l_305d;
x86_l_3032:
	/* 0x3032: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3037:
	/* 0x3037: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_303e:
	/* 0x303e: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3043:
	/* 0x3043: jmp    305d <generic_lsm_process_event+0x305d> */
	goto x86_l_305d;
x86_l_3045:
	/* 0x3045: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_304a:
	/* 0x304a: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_3051:
	/* 0x3051: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3056:
	/* 0x3056: jmp    305d <generic_lsm_process_event+0x305d> */
	goto x86_l_305d;
x86_l_3058:
	/* 0x3058: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_305d:
	/* 0x305d: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3061:
	/* 0x3061: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3065:
	/* 0x3065: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_306a:
	/* 0x306a: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_306e:
	/* 0x306e: ja     3355 <generic_lsm_process_event+0x3355> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13141ULL;
	}
x86_l_3074:
	/* 0x3074: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_307e:
	/* 0x307e: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_3082:
	/* 0x3082: jae    3355 <generic_lsm_process_event+0x3355> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13141ULL;
	}
x86_l_3088:
	/* 0x3088: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_308c:
	/* 0x308c: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_308f:
	/* 0x308f: add    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
	return 12434ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12434ULL: goto x86_l_3092;
	case 12439ULL: goto x86_l_3097;
	case 12444ULL: goto x86_l_309c;
	case 12449ULL: goto x86_l_30a1;
	case 12453ULL: goto x86_l_30a5;
	case 12456ULL: goto x86_l_30a8;
	case 12461ULL: goto x86_l_30ad;
	case 12463ULL: goto x86_l_30af;
	case 12466ULL: goto x86_l_30b2;
	case 12472ULL: goto x86_l_30b8;
	case 12477ULL: goto x86_l_30bd;
	case 12480ULL: goto x86_l_30c0;
	case 12482ULL: goto x86_l_30c2;
	case 12484ULL: goto x86_l_30c4;
	case 12486ULL: goto x86_l_30c6;
	case 12489ULL: goto x86_l_30c9;
	case 12491ULL: goto x86_l_30cb;
	case 12494ULL: goto x86_l_30ce;
	case 12496ULL: goto x86_l_30d0;
	case 12503ULL: goto x86_l_30d7;
	case 12507ULL: goto x86_l_30db;
	case 12509ULL: goto x86_l_30dd;
	case 12512ULL: goto x86_l_30e0;
	case 12514ULL: goto x86_l_30e2;
	case 12517ULL: goto x86_l_30e5;
	case 12519ULL: goto x86_l_30e7;
	case 12524ULL: goto x86_l_30ec;
	case 12526ULL: goto x86_l_30ee;
	case 12533ULL: goto x86_l_30f5;
	case 12537ULL: goto x86_l_30f9;
	case 12539ULL: goto x86_l_30fb;
	case 12544ULL: goto x86_l_3100;
	case 12551ULL: goto x86_l_3107;
	case 12556ULL: goto x86_l_310c;
	case 12558ULL: goto x86_l_310e;
	case 12563ULL: goto x86_l_3113;
	case 12570ULL: goto x86_l_311a;
	case 12575ULL: goto x86_l_311f;
	case 12577ULL: goto x86_l_3121;
	case 12582ULL: goto x86_l_3126;
	case 12586ULL: goto x86_l_312a;
	case 12590ULL: goto x86_l_312e;
	case 12595ULL: goto x86_l_3133;
	case 12599ULL: goto x86_l_3137;
	case 12605ULL: goto x86_l_313d;
	case 12615ULL: goto x86_l_3147;
	case 12619ULL: goto x86_l_314b;
	case 12625ULL: goto x86_l_3151;
	case 12629ULL: goto x86_l_3155;
	case 12632ULL: goto x86_l_3158;
	case 12635ULL: goto x86_l_315b;
	case 12640ULL: goto x86_l_3160;
	case 12645ULL: goto x86_l_3165;
	case 12650ULL: goto x86_l_316a;
	case 12654ULL: goto x86_l_316e;
	case 12657ULL: goto x86_l_3171;
	case 12662ULL: goto x86_l_3176;
	case 12664ULL: goto x86_l_3178;
	case 12666ULL: goto x86_l_317a;
	case 12674ULL: goto x86_l_3182;
	case 12678ULL: goto x86_l_3186;
	case 12683ULL: goto x86_l_318b;
	case 12687ULL: goto x86_l_318f;
	case 12693ULL: goto x86_l_3195;
	case 12697ULL: goto x86_l_3199;
	case 12702ULL: goto x86_l_319e;
	case 12707ULL: goto x86_l_31a3;
	case 12710ULL: goto x86_l_31a6;
	case 12715ULL: goto x86_l_31ab;
	case 12717ULL: goto x86_l_31ad;
	case 12721ULL: goto x86_l_31b1;
	case 12725ULL: goto x86_l_31b5;
	case 12730ULL: goto x86_l_31ba;
	case 12735ULL: goto x86_l_31bf;
	case 12740ULL: goto x86_l_31c4;
	case 12743ULL: goto x86_l_31c7;
	case 12745ULL: goto x86_l_31c9;
	case 12749ULL: goto x86_l_31cd;
	case 12751ULL: goto x86_l_31cf;
	case 12755ULL: goto x86_l_31d3;
	case 12758ULL: goto x86_l_31d6;
	case 12764ULL: goto x86_l_31dc;
	case 12769ULL: goto x86_l_31e1;
	case 12778ULL: goto x86_l_31ea;
	case 12782ULL: goto x86_l_31ee;
	case 12787ULL: goto x86_l_31f3;
	case 12791ULL: goto x86_l_31f7;
	case 12796ULL: goto x86_l_31fc;
	case 12801ULL: goto x86_l_3201;
	case 12806ULL: goto x86_l_3206;
	case 12808ULL: goto x86_l_3208;
	case 12812ULL: goto x86_l_320c;
	case 12816ULL: goto x86_l_3210;
	case 12820ULL: goto x86_l_3214;
	case 12825ULL: goto x86_l_3219;
	case 12830ULL: goto x86_l_321e;
	case 12832ULL: goto x86_l_3220;
	case 12837ULL: goto x86_l_3225;
	case 12846ULL: goto x86_l_322e;
	case 12850ULL: goto x86_l_3232;
	case 12855ULL: goto x86_l_3237;
	case 12859ULL: goto x86_l_323b;
	case 12864ULL: goto x86_l_3240;
	case 12869ULL: goto x86_l_3245;
	case 12874ULL: goto x86_l_324a;
	case 12876ULL: goto x86_l_324c;
	case 12880ULL: goto x86_l_3250;
	case 12884ULL: goto x86_l_3254;
	case 12888ULL: goto x86_l_3258;
	case 12893ULL: goto x86_l_325d;
	case 12898ULL: goto x86_l_3262;
	case 12903ULL: goto x86_l_3267;
	case 12905ULL: goto x86_l_3269;
	case 12907ULL: goto x86_l_326b;
	case 12912ULL: goto x86_l_3270;
	case 12919ULL: goto x86_l_3277;
	case 12924ULL: goto x86_l_327c;
	case 12928ULL: goto x86_l_3280;
	case 12932ULL: goto x86_l_3284;
	case 12938ULL: goto x86_l_328a;
	case 12944ULL: goto x86_l_3290;
	case 12951ULL: goto x86_l_3297;
	case 12959ULL: goto x86_l_329f;
	case 12964ULL: goto x86_l_32a4;
	case 12969ULL: goto x86_l_32a9;
	case 12975ULL: goto x86_l_32af;
	case 12980ULL: goto x86_l_32b4;
	case 12983ULL: goto x86_l_32b7;
	case 12985ULL: goto x86_l_32b9;
	case 12993ULL: goto x86_l_32c1;
	case 12996ULL: goto x86_l_32c4;
	case 12998ULL: goto x86_l_32c6;
	case 13002ULL: goto x86_l_32ca;
	case 13007ULL: goto x86_l_32cf;
	case 13012ULL: goto x86_l_32d4;
	case 13017ULL: goto x86_l_32d9;
	case 13025ULL: goto x86_l_32e1;
	case 13029ULL: goto x86_l_32e5;
	case 13034ULL: goto x86_l_32ea;
	case 13036ULL: goto x86_l_32ec;
	case 13044ULL: goto x86_l_32f4;
	case 13049ULL: goto x86_l_32f9;
	case 13053ULL: goto x86_l_32fd;
	case 13058ULL: goto x86_l_3302;
	case 13062ULL: goto x86_l_3306;
	case 13067ULL: goto x86_l_330b;
	case 13072ULL: goto x86_l_3310;
	case 13074ULL: goto x86_l_3312;
	case 13078ULL: goto x86_l_3316;
	case 13082ULL: goto x86_l_331a;
	case 13086ULL: goto x86_l_331e;
	case 13091ULL: goto x86_l_3323;
	case 13094ULL: goto x86_l_3326;
	case 13099ULL: goto x86_l_332b;
	case 13101ULL: goto x86_l_332d;
	case 13107ULL: goto x86_l_3333;
	case 13112ULL: goto x86_l_3338;
	case 13117ULL: goto x86_l_333d;
	case 13122ULL: goto x86_l_3342;
	case 13127ULL: goto x86_l_3347;
	case 13131ULL: goto x86_l_334b;
	case 13136ULL: goto x86_l_3350;
	case 13141ULL: goto x86_l_3355;
	case 13149ULL: goto x86_l_335d;
	case 13154ULL: goto x86_l_3362;
	case 13159ULL: goto x86_l_3367;
	case 13162ULL: goto x86_l_336a;
	case 13164ULL: goto x86_l_336c;
	case 13166ULL: goto x86_l_336e;
	case 13167ULL: goto x86_l_336f;
	case 13168ULL: goto x86_l_3370;
	case 13171ULL: goto x86_l_3373;
	case 13174ULL: goto x86_l_3376;
	case 13181ULL: goto x86_l_337d;
	case 13183ULL: goto x86_l_337f;
	case 13187ULL: goto x86_l_3383;
	case 13191ULL: goto x86_l_3387;
	case 13194ULL: goto x86_l_338a;
	case 13197ULL: goto x86_l_338d;
	case 13199ULL: goto x86_l_338f;
	case 13206ULL: goto x86_l_3396;
	case 13208ULL: goto x86_l_3398;
	case 13210ULL: goto x86_l_339a;
	case 13214ULL: goto x86_l_339e;
	case 13216ULL: goto x86_l_33a0;
	case 13221ULL: goto x86_l_33a5;
	case 13226ULL: goto x86_l_33aa;
	case 13228ULL: goto x86_l_33ac;
	case 13233ULL: goto x86_l_33b1;
	case 13238ULL: goto x86_l_33b6;
	case 13241ULL: goto x86_l_33b9;
	case 13245ULL: goto x86_l_33bd;
	case 13248ULL: goto x86_l_33c0;
	case 13253ULL: goto x86_l_33c5;
	case 13255ULL: goto x86_l_33c7;
	case 13257ULL: goto x86_l_33c9;
	case 13262ULL: goto x86_l_33ce;
	case 13264ULL: goto x86_l_33d0;
	case 13266ULL: goto x86_l_33d2;
	case 13270ULL: goto x86_l_33d6;
	case 13272ULL: goto x86_l_33d8;
	case 13277ULL: goto x86_l_33dd;
	case 13281ULL: goto x86_l_33e1;
	case 13282ULL: goto x86_l_33e2;
	case 13284ULL: goto x86_l_33e4;
	case 13285ULL: goto x86_l_33e5;
	case 13286ULL: goto x86_l_33e6;
	case 13288ULL: goto x86_l_33e8;
	case 13290ULL: goto x86_l_33ea;
	case 13292ULL: goto x86_l_33ec;
	case 13294ULL: goto x86_l_33ee;
	case 13295ULL: goto x86_l_33ef;
	case 13299ULL: goto x86_l_33f3;
	case 13302ULL: goto x86_l_33f6;
	case 13306ULL: goto x86_l_33fa;
	case 13310ULL: goto x86_l_33fe;
	case 13314ULL: goto x86_l_3402;
	case 13317ULL: goto x86_l_3405;
	case 13319ULL: goto x86_l_3407;
	case 13323ULL: goto x86_l_340b;
	case 13329ULL: goto x86_l_3411;
	case 13333ULL: goto x86_l_3415;
	case 13338ULL: goto x86_l_341a;
	case 13343ULL: goto x86_l_341f;
	case 13348ULL: goto x86_l_3424;
	case 13353ULL: goto x86_l_3429;
	case 13355ULL: goto x86_l_342b;
	case 13360ULL: goto x86_l_3430;
	case 13366ULL: goto x86_l_3436;
	case 13371ULL: goto x86_l_343b;
	case 13376ULL: goto x86_l_3440;
	case 13381ULL: goto x86_l_3445;
	case 13386ULL: goto x86_l_344a;
	case 13391ULL: goto x86_l_344f;
	case 13394ULL: goto x86_l_3452;
	case 13396ULL: goto x86_l_3454;
	case 13401ULL: goto x86_l_3459;
	case 13407ULL: goto x86_l_345f;
	case 13412ULL: goto x86_l_3464;
	case 13417ULL: goto x86_l_3469;
	case 13422ULL: goto x86_l_346e;
	case 13427ULL: goto x86_l_3473;
	case 13430ULL: goto x86_l_3476;
	case 13432ULL: goto x86_l_3478;
	case 13436ULL: goto x86_l_347c;
	case 13441ULL: goto x86_l_3481;
	case 13446ULL: goto x86_l_3486;
	case 13451ULL: goto x86_l_348b;
	case 13456ULL: goto x86_l_3490;
	case 13459ULL: goto x86_l_3493;
	case 13461ULL: goto x86_l_3495;
	case 13465ULL: goto x86_l_3499;
	case 13469ULL: goto x86_l_349d;
	case 13473ULL: goto x86_l_34a1;
	case 13476ULL: goto x86_l_34a4;
	case 13480ULL: goto x86_l_34a8;
	case 13482ULL: goto x86_l_34aa;
	case 13484ULL: goto x86_l_34ac;
	case 13487ULL: goto x86_l_34af;
	case 13490ULL: goto x86_l_34b2;
	case 13495ULL: goto x86_l_34b7;
	case 13497ULL: goto x86_l_34b9;
	case 13500ULL: goto x86_l_34bc;
	case 13504ULL: goto x86_l_34c0;
	case 13506ULL: goto x86_l_34c2;
	case 13510ULL: goto x86_l_34c6;
	case 13512ULL: goto x86_l_34c8;
	case 13515ULL: goto x86_l_34cb;
	case 13517ULL: goto x86_l_34cd;
	case 13520ULL: goto x86_l_34d0;
	case 13525ULL: goto x86_l_34d5;
	case 13528ULL: goto x86_l_34d8;
	case 13534ULL: goto x86_l_34de;
	case 13541ULL: goto x86_l_34e5;
	case 13547ULL: goto x86_l_34eb;
	case 13550ULL: goto x86_l_34ee;
	case 13552ULL: goto x86_l_34f0;
	case 13557ULL: goto x86_l_34f5;
	case 13559ULL: goto x86_l_34f7;
	case 13562ULL: goto x86_l_34fa;
	case 13566ULL: goto x86_l_34fe;
	case 13570ULL: goto x86_l_3502;
	case 13573ULL: goto x86_l_3505;
	case 13576ULL: goto x86_l_3508;
	case 13581ULL: goto x86_l_350d;
	case 13583ULL: goto x86_l_350f;
	case 13587ULL: goto x86_l_3513;
	case 13590ULL: goto x86_l_3516;
	case 13595ULL: goto x86_l_351b;
	case 13597ULL: goto x86_l_351d;
	case 13602ULL: goto x86_l_3522;
	case 13605ULL: goto x86_l_3525;
	case 13607ULL: goto x86_l_3527;
	case 13611ULL: goto x86_l_352b;
	case 13616ULL: goto x86_l_3530;
	case 13621ULL: goto x86_l_3535;
	case 13626ULL: goto x86_l_353a;
	case 13631ULL: goto x86_l_353f;
	case 13633ULL: goto x86_l_3541;
	case 13637ULL: goto x86_l_3545;
	case 13642ULL: goto x86_l_354a;
	case 13644ULL: goto x86_l_354c;
	case 13648ULL: goto x86_l_3550;
	case 13653ULL: goto x86_l_3555;
	case 13658ULL: goto x86_l_355a;
	case 13661ULL: goto x86_l_355d;
	case 13666ULL: goto x86_l_3562;
	case 13669ULL: goto x86_l_3565;
	case 13671ULL: goto x86_l_3567;
	case 13676ULL: goto x86_l_356c;
	case 13680ULL: goto x86_l_3570;
	case 13684ULL: goto x86_l_3574;
	case 13688ULL: goto x86_l_3578;
	case 13690ULL: goto x86_l_357a;
	case 13692ULL: goto x86_l_357c;
	case 13696ULL: goto x86_l_3580;
	case 13701ULL: goto x86_l_3585;
	case 13705ULL: goto x86_l_3589;
	case 13706ULL: goto x86_l_358a;
	case 13708ULL: goto x86_l_358c;
	case 13710ULL: goto x86_l_358e;
	case 13712ULL: goto x86_l_3590;
	case 13714ULL: goto x86_l_3592;
	case 13715ULL: goto x86_l_3593;
	case 13716ULL: goto x86_l_3594;
	case 13717ULL: goto x86_l_3595;
	case 13719ULL: goto x86_l_3597;
	case 13721ULL: goto x86_l_3599;
	case 13723ULL: goto x86_l_359b;
	case 13725ULL: goto x86_l_359d;
	case 13726ULL: goto x86_l_359e;
	case 13727ULL: goto x86_l_359f;
	case 13730ULL: goto x86_l_35a2;
	case 13733ULL: goto x86_l_35a5;
	case 13736ULL: goto x86_l_35a8;
	case 13739ULL: goto x86_l_35ab;
	case 13747ULL: goto x86_l_35b3;
	case 13754ULL: goto x86_l_35ba;
	case 13759ULL: goto x86_l_35bf;
	case 13764ULL: goto x86_l_35c4;
	case 13766ULL: goto x86_l_35c6;
	case 13769ULL: goto x86_l_35c9;
	case 13771ULL: goto x86_l_35cb;
	case 13774ULL: goto x86_l_35ce;
	case 13780ULL: goto x86_l_35d4;
	case 13785ULL: goto x86_l_35d9;
	case 13787ULL: goto x86_l_35db;
	case 13790ULL: goto x86_l_35de;
	case 13794ULL: goto x86_l_35e2;
	case 13798ULL: goto x86_l_35e6;
	case 13802ULL: goto x86_l_35ea;
	case 13804ULL: goto x86_l_35ec;
	case 13809ULL: goto x86_l_35f1;
	case 13813ULL: goto x86_l_35f5;
	case 13818ULL: goto x86_l_35fa;
	case 13820ULL: goto x86_l_35fc;
	case 13824ULL: goto x86_l_3600;
	case 13828ULL: goto x86_l_3604;
	case 13832ULL: goto x86_l_3608;
	case 13836ULL: goto x86_l_360c;
	case 13840ULL: goto x86_l_3610;
	case 13843ULL: goto x86_l_3613;
	case 13846ULL: goto x86_l_3616;
	case 13849ULL: goto x86_l_3619;
	case 13852ULL: goto x86_l_361c;
	case 13857ULL: goto x86_l_3621;
	case 13859ULL: goto x86_l_3623;
	case 13861ULL: goto x86_l_3625;
	case 13868ULL: goto x86_l_362c;
	case 13871ULL: goto x86_l_362f;
	case 13873ULL: goto x86_l_3631;
	case 13875ULL: goto x86_l_3633;
	case 13879ULL: goto x86_l_3637;
	case 13882ULL: goto x86_l_363a;
	case 13884ULL: goto x86_l_363c;
	case 13886ULL: goto x86_l_363e;
	case 13888ULL: goto x86_l_3640;
	case 13890ULL: goto x86_l_3642;
	case 13897ULL: goto x86_l_3649;
	case 13899ULL: goto x86_l_364b;
	case 13901ULL: goto x86_l_364d;
	case 13904ULL: goto x86_l_3650;
	case 13907ULL: goto x86_l_3653;
	case 13912ULL: goto x86_l_3658;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3092:
	/* 0x3092: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3097:
	/* 0x3097: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_309c:
	/* 0x309c: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_30a1:
	/* 0x30a1: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_30a5:
	/* 0x30a5: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30a8:
	/* 0x30a8: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_30ad:
	/* 0x30ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30af:
	/* 0x30af: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30b2:
	/* 0x30b2: js     3178 <generic_lsm_process_event+0x3178> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3178;
	}
x86_l_30b8:
	/* 0x30b8: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_30bd:
	/* 0x30bd: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_30c0:
	/* 0x30c0: jg     30dd <generic_lsm_process_event+0x30dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_30dd;
	}
x86_l_30c2:
	/* 0x30c2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30c4:
	/* 0x30c4: je     30fb <generic_lsm_process_event+0x30fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30fb;
	}
x86_l_30c6:
	/* 0x30c6: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_30c9:
	/* 0x30c9: je     30fb <generic_lsm_process_event+0x30fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30fb;
	}
x86_l_30cb:
	/* 0x30cb: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_30ce:
	/* 0x30ce: jne    3121 <generic_lsm_process_event+0x3121> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3121;
	}
x86_l_30d0:
	/* 0x30d0: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_30d7:
	/* 0x30d7: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_30db:
	/* 0x30db: jmp    3126 <generic_lsm_process_event+0x3126> */
	goto x86_l_3126;
x86_l_30dd:
	/* 0x30dd: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_30e0:
	/* 0x30e0: je     310e <generic_lsm_process_event+0x310e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_310e;
	}
x86_l_30e2:
	/* 0x30e2: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_30e5:
	/* 0x30e5: je     30fb <generic_lsm_process_event+0x30fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30fb;
	}
x86_l_30e7:
	/* 0x30e7: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_30ec:
	/* 0x30ec: jne    3121 <generic_lsm_process_event+0x3121> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3121;
	}
x86_l_30ee:
	/* 0x30ee: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_30f5:
	/* 0x30f5: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_30f9:
	/* 0x30f9: jmp    3126 <generic_lsm_process_event+0x3126> */
	goto x86_l_3126;
x86_l_30fb:
	/* 0x30fb: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3100:
	/* 0x3100: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_3107:
	/* 0x3107: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_310c:
	/* 0x310c: jmp    3126 <generic_lsm_process_event+0x3126> */
	goto x86_l_3126;
x86_l_310e:
	/* 0x310e: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3113:
	/* 0x3113: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_311a:
	/* 0x311a: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_311f:
	/* 0x311f: jmp    3126 <generic_lsm_process_event+0x3126> */
	goto x86_l_3126;
x86_l_3121:
	/* 0x3121: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_3126:
	/* 0x3126: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_312a:
	/* 0x312a: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_312e:
	/* 0x312e: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_3133:
	/* 0x3133: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_3137:
	/* 0x3137: ja     3355 <generic_lsm_process_event+0x3355> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3355;
	}
x86_l_313d:
	/* 0x313d: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_3147:
	/* 0x3147: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_314b:
	/* 0x314b: jae    3355 <generic_lsm_process_event+0x3355> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3355;
	}
x86_l_3151:
	/* 0x3151: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_3155:
	/* 0x3155: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3158:
	/* 0x3158: add    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_315b:
	/* 0x315b: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3160:
	/* 0x3160: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3165:
	/* 0x3165: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_316a:
	/* 0x316a: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_316e:
	/* 0x316e: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3171:
	/* 0x3171: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3176:
	/* 0x3176: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3178:
	/* 0x3178: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_317a:
	/* 0x317a: mov    BYTE PTR [rsp+0xbc],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_3182:
	/* 0x3182: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3186:
	/* 0x3186: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_318b:
	/* 0x318b: mov    WORD PTR [rbx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_318f:
	/* 0x318f: mov    WORD PTR [rbx+0x26],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757258ULL);
x86_l_3195:
	/* 0x3195: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3199:
	/* 0x3199: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_319e:
	/* 0x319e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31a3:
	/* 0x31a3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_31a6:
	/* 0x31a6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_31ab:
	/* 0x31ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31ad:
	/* 0x31ad: lea    rdi,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31b1:
	/* 0x31b1: add    r13,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_31b5:
	/* 0x31b5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_31ba:
	/* 0x31ba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31bf:
	/* 0x31bf: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_31c4:
	/* 0x31c4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_31c7:
	/* 0x31c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31c9:
	/* 0x31c9: cmp    bpl,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 17ULL);
x86_l_31cd:
	/* 0x31cd: je     3220 <generic_lsm_process_event+0x3220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3220;
	}
x86_l_31cf:
	/* 0x31cf: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_31d3:
	/* 0x31d3: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_31d6:
	/* 0x31d6: jne    326b <generic_lsm_process_event+0x326b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_326b;
	}
x86_l_31dc:
	/* 0x31dc: mov    rbx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_31e1:
	/* 0x31e1: movzx  r15d,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_31ea:
	/* 0x31ea: lea    rdx,[rbx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_31ee:
	/* 0x31ee: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31f3:
	/* 0x31f3: lea    rdi,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31f7:
	/* 0x31f7: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_31fc:
	/* 0x31fc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3201:
	/* 0x3201: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3206:
	/* 0x3206: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3208:
	/* 0x3208: lea    rdi,[r13+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_320c:
	/* 0x320c: lea    rdx,[rbx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_3210:
	/* 0x3210: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_3214:
	/* 0x3214: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3219:
	/* 0x3219: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_321e:
	/* 0x321e: jmp    3262 <generic_lsm_process_event+0x3262> */
	goto x86_l_3262;
x86_l_3220:
	/* 0x3220: mov    rbx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3225:
	/* 0x3225: movzx  r15d,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_322e:
	/* 0x322e: lea    rdx,[rbx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_3232:
	/* 0x3232: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3237:
	/* 0x3237: lea    rdi,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_323b:
	/* 0x323b: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3240:
	/* 0x3240: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3245:
	/* 0x3245: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_324a:
	/* 0x324a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_324c:
	/* 0x324c: lea    rdi,[r13+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_3250:
	/* 0x3250: lea    rdx,[rbx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_3254:
	/* 0x3254: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_3258:
	/* 0x3258: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_325d:
	/* 0x325d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3262:
	/* 0x3262: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3267:
	/* 0x3267: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3269:
	/* 0x3269: jmp    3277 <generic_lsm_process_event+0x3277> */
	goto x86_l_3277;
x86_l_326b:
	/* 0x326b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3270:
	/* 0x3270: mov    DWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3277:
	/* 0x3277: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_327c:
	/* 0x327c: movzx  eax,WORD PTR [rdx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_3280:
	/* 0x3280: movzx  ecx,WORD PTR [rdx+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_3284:
	/* 0x3284: movbe  WORD PTR [rdx+0x20],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_328a:
	/* 0x328a: movbe  WORD PTR [rdx+0x22],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_3290:
	/* 0x3290: add    r12,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_3297:
	/* 0x3297: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_329f:
	/* 0x329f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_32a4:
	/* 0x32a4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32a9:
	/* 0x32a9: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_32af:
	/* 0x32af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32b4:
	/* 0x32b4: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_32b7:
	/* 0x32b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32b9:
	/* 0x32b9: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_32c1:
	/* 0x32c1: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_32c4:
	/* 0x32c4: je     332d <generic_lsm_process_event+0x332d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_332d;
	}
x86_l_32c6:
	/* 0x32c6: add    rcx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_32ca:
	/* 0x32ca: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_32cf:
	/* 0x32cf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_32d4:
	/* 0x32d4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32d9:
	/* 0x32d9: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_32e1:
	/* 0x32e1: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_32e5:
	/* 0x32e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32ea:
	/* 0x32ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32ec:
	/* 0x32ec: mov    rbx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_32f4:
	/* 0x32f4: mov    r12,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_32f9:
	/* 0x32f9: lea    rdx,[rbx+r12*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_32fd:
	/* 0x32fd: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3302:
	/* 0x3302: lea    rdi,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3306:
	/* 0x3306: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_330b:
	/* 0x330b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3310:
	/* 0x3310: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3312:
	/* 0x3312: add    r13,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 60ULL);
x86_l_3316:
	/* 0x3316: lea    rdx,[rbx+r12*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_331a:
	/* 0x331a: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_331e:
	/* 0x331e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3323:
	/* 0x3323: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_3326:
	/* 0x3326: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_332b:
	/* 0x332b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_332d:
	/* 0x332d: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_3333:
	/* 0x3333: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3338:
	/* 0x3338: mov    rbx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_333d:
	/* 0x333d: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3342:
	/* 0x3342: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3347:
	/* 0x3347: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_334b:
	/* 0x334b: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3350:
	/* 0x3350: jmp    c6d <generic_lsm_process_event+0xc6d> */
	return 3181ULL;
x86_l_3355:
	/* 0x3355: mov    WORD PTR [rsp+0xc8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_335d:
	/* 0x335d: jmp    317a <generic_lsm_process_event+0x317a> */
	goto x86_l_317a;
x86_l_3362:
	/* 0x3362: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3367:
	/* 0x3367: cmp    edi,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 9ULL);
x86_l_336a:
	/* 0x336a: ja     33e4 <extract_arg_depth+0x82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_33e4;
	}
x86_l_336c:
	/* 0x336c: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_336e:
	/* 0x336e: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_336f:
	/* 0x336f: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_3370:
	/* 0x3370: mov    r8,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3373:
	/* 0x3373: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_3376:
	/* 0x3376: cmp    WORD PTR [r8+r9*8+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R9, 3), 25769803776ULL);
x86_l_337d:
	/* 0x337d: je     33dd <extract_arg_depth+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33dd;
	}
x86_l_337f:
	/* 0x337f: mov    rcx,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3383:
	/* 0x3383: mov    edx,DWORD PTR [r8+r9*8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 3), 0ULL);
x86_l_3387:
	/* 0x3387: add    rdx,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_338a:
	/* 0x338a: mov    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_338d:
	/* 0x338d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_338f:
	/* 0x338f: cmp    WORD PTR [r8+r9*8+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R9, 3), 17179869184ULL);
x86_l_3396:
	/* 0x3396: je     33dd <extract_arg_depth+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33dd;
	}
x86_l_3398:
	/* 0x3398: mov    ebx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_32);
x86_l_339a:
	/* 0x339a: cmp    BYTE PTR [rsi+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_339e:
	/* 0x339e: je     33ac <extract_arg_depth+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33ac;
	}
x86_l_33a0:
	/* 0x33a0: mov    edi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 8ULL);
x86_l_33a5:
	/* 0x33a5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_33aa:
	/* 0x33aa: jmp    33b6 <extract_arg_depth+0x54> */
	goto x86_l_33b6;
x86_l_33ac:
	/* 0x33ac: mov    edi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 8ULL);
x86_l_33b1:
	/* 0x33b1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_33b6:
	/* 0x33b6: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_33b9:
	/* 0x33b9: mov    rdi,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33bd:
	/* 0x33bd: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33c0:
	/* 0x33c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33c5:
	/* 0x33c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33c7:
	/* 0x33c7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33c9:
	/* 0x33c9: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_33ce:
	/* 0x33ce: jns    33dd <extract_arg_depth+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_33dd;
	}
x86_l_33d0:
	/* 0x33d0: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_33d2:
	/* 0x33d2: mov    rax,QWORD PTR [r14+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33d6:
	/* 0x33d6: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33d8:
	/* 0x33d8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33dd:
	/* 0x33dd: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_33e1:
	/* 0x33e1: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_33e2:
	/* 0x33e2: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_33e4:
	/* 0x33e4: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_33e5:
	/* 0x33e5: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_33e6:
	/* 0x33e6: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_33e8:
	/* 0x33e8: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_33ea:
	/* 0x33ea: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_33ec:
	/* 0x33ec: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_33ee:
	/* 0x33ee: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_33ef:
	/* 0x33ef: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_33f3:
	/* 0x33f3: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_33f6:
	/* 0x33f6: mov    r12,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33fa:
	/* 0x33fa: mov    rdx,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33fe:
	/* 0x33fe: mov    r15,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3402:
	/* 0x3402: cmp    r12,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_3405:
	/* 0x3405: jne    3411 <cwd_read_v61+0x2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3411;
	}
x86_l_3407:
	/* 0x3407: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_340b:
	/* 0x340b: je     357c <cwd_read_v61+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_357c;
	}
x86_l_3411:
	/* 0x3411: lea    r14,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3415:
	/* 0x3415: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_341a:
	/* 0x341a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_341f:
	/* 0x341f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3424:
	/* 0x3424: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3429:
	/* 0x3429: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_342b:
	/* 0x342b: cmp    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_3430:
	/* 0x3430: je     3527 <cwd_read_v61+0x142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3527;
	}
x86_l_3436:
	/* 0x3436: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_343b:
	/* 0x343b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3440:
	/* 0x3440: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3445:
	/* 0x3445: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_344a:
	/* 0x344a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_344f:
	/* 0x344f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3452:
	/* 0x3452: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3454:
	/* 0x3454: cmp    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3459:
	/* 0x3459: je     3527 <cwd_read_v61+0x142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3527;
	}
x86_l_345f:
	/* 0x345f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3464:
	/* 0x3464: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3469:
	/* 0x3469: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_346e:
	/* 0x346e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3473:
	/* 0x3473: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3476:
	/* 0x3476: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3478:
	/* 0x3478: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_347c:
	/* 0x347c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3481:
	/* 0x3481: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3486:
	/* 0x3486: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_348b:
	/* 0x348b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3490:
	/* 0x3490: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3493:
	/* 0x3493: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3495:
	/* 0x3495: mov    r15,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3499:
	/* 0x3499: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_349d:
	/* 0x349d: mov    ebp,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_34a1:
	/* 0x34a1: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_34a4:
	/* 0x34a4: mov    r12d,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_34a8:
	/* 0x34a8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34aa:
	/* 0x34aa: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_34ac:
	/* 0x34ac: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_34af:
	/* 0x34af: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_34b2:
	/* 0x34b2: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_34b7:
	/* 0x34b7: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34b9:
	/* 0x34b9: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_34bc:
	/* 0x34bc: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_34c0:
	/* 0x34c0: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_34c2:
	/* 0x34c2: cmovb  esi,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_34c6:
	/* 0x34c6: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_34c8:
	/* 0x34c8: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_34cb:
	/* 0x34cb: sub    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_34cd:
	/* 0x34cd: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_34d0:
	/* 0x34d0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34d5:
	/* 0x34d5: sub    rcx,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_34d8:
	/* 0x34d8: jb     3585 <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3585;
	}
x86_l_34de:
	/* 0x34de: cmp    rcx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4095ULL);
x86_l_34e5:
	/* 0x34e5: ja     3585 <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3585;
	}
x86_l_34eb:
	/* 0x34eb: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_34ee:
	/* 0x34ee: jbe    34f5 <cwd_read_v61+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_34f5;
	}
x86_l_34f0:
	/* 0x34f0: mov    BYTE PTR [r15+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_34f5:
	/* 0x34f5: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34f7:
	/* 0x34f7: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_34fa:
	/* 0x34fa: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_34fe:
	/* 0x34fe: movzx  esi,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3502:
	/* 0x3502: add    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3505:
	/* 0x3505: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3508:
	/* 0x3508: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_350d:
	/* 0x350d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_350f:
	/* 0x350f: mov    QWORD PTR [rbx+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3513:
	/* 0x3513: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3516:
	/* 0x3516: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_351b:
	/* 0x351b: jbe    3585 <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3585;
	}
x86_l_351d:
	/* 0x351d: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3522:
	/* 0x3522: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3525:
	/* 0x3525: jmp    3578 <cwd_read_v61+0x193> */
	goto x86_l_3578;
x86_l_3527:
	/* 0x3527: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_352b:
	/* 0x352b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3530:
	/* 0x3530: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3535:
	/* 0x3535: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_353a:
	/* 0x353a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_353f:
	/* 0x353f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3541:
	/* 0x3541: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3545:
	/* 0x3545: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_354a:
	/* 0x354a: je     357c <cwd_read_v61+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_357c;
	}
x86_l_354c:
	/* 0x354c: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3550:
	/* 0x3550: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3555:
	/* 0x3555: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_355a:
	/* 0x355a: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_355d:
	/* 0x355d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3562:
	/* 0x3562: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3565:
	/* 0x3565: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3567:
	/* 0x3567: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_356c:
	/* 0x356c: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3570:
	/* 0x3570: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3574:
	/* 0x3574: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3578:
	/* 0x3578: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_357a:
	/* 0x357a: jmp    3585 <cwd_read_v61+0x1a0> */
	goto x86_l_3585;
x86_l_357c:
	/* 0x357c: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_3580:
	/* 0x3580: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3585:
	/* 0x3585: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_3589:
	/* 0x3589: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_358a:
	/* 0x358a: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_358c:
	/* 0x358c: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_358e:
	/* 0x358e: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3590:
	/* 0x3590: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3592:
	/* 0x3592: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3593:
	/* 0x3593: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3594:
	/* 0x3594: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_3595:
	/* 0x3595: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_3597:
	/* 0x3597: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_3599:
	/* 0x3599: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_359b:
	/* 0x359b: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_359d:
	/* 0x359d: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_359e:
	/* 0x359e: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_359f:
	/* 0x359f: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_35a2:
	/* 0x35a2: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_35a5:
	/* 0x35a5: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_35a8:
	/* 0x35a8: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_35ab:
	/* 0x35ab: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_35b3:
	/* 0x35b3: mov    rdi,QWORD PTR [rip+0x240] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_heap)));
x86_l_35ba:
	/* 0x35ba: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_35bf:
	/* 0x35bf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35c4:
	/* 0x35c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35c6:
	/* 0x35c6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35c9:
	/* 0x35c9: je     363c <data_event_bytes+0xa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_363c;
	}
x86_l_35cb:
	/* 0x35cb: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_35ce:
	/* 0x35ce: mov    DWORD PTR [rax],0x18 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_35d4:
	/* 0x35d4: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_35d9:
	/* 0x35d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35db:
	/* 0x35db: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_35de:
	/* 0x35de: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_35e2:
	/* 0x35e2: mov    QWORD PTR [r13+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35e6:
	/* 0x35e6: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_35ea:
	/* 0x35ea: jne    35f5 <data_event_bytes+0x61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_35f5;
	}
x86_l_35ec:
	/* 0x35ec: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35f1:
	/* 0x35f1: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35f5:
	/* 0x35f5: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_35fa:
	/* 0x35fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35fc:
	/* 0x35fc: mov    QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3600:
	/* 0x3600: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3604:
	/* 0x3604: mov    rcx,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3608:
	/* 0x3608: mov    QWORD PTR [rbx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_360c:
	/* 0x360c: mov    QWORD PTR [rbx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3610:
	/* 0x3610: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3613:
	/* 0x3613: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3616:
	/* 0x3616: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3619:
	/* 0x3619: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_361c:
	/* 0x361c: call   3667 <do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13857ULL);
	__x86_sim_call_depth++;
	return 13927ULL;
x86_l_3621:
	/* 0x3621: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3623:
	/* 0x3623: js     3640 <data_event_bytes+0xac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3640;
	}
x86_l_3625:
	/* 0x3625: mov    QWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_362c:
	/* 0x362c: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_362f:
	/* 0x362f: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3631:
	/* 0x3631: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3633:
	/* 0x3633: cmp    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_3637:
	/* 0x3637: cmovne ecx,edx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_363a:
	/* 0x363a: jmp    364d <data_event_bytes+0xb9> */
	goto x86_l_364d;
x86_l_363c:
	/* 0x363c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_363e:
	/* 0x363e: jmp    3658 <data_event_bytes+0xc4> */
	goto x86_l_3658;
x86_l_3640:
	/* 0x3640: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3642:
	/* 0x3642: mov    DWORD PTR [rbx+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3649:
	/* 0x3649: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_364b:
	/* 0x364b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_364d:
	/* 0x364d: mov    DWORD PTR [rbx+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3650:
	/* 0x3650: mov    DWORD PTR [rbx+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3653:
	/* 0x3653: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_3658:
	/* 0x3658: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
	return 13916ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13916ULL: goto x86_l_365c;
	case 13917ULL: goto x86_l_365d;
	case 13919ULL: goto x86_l_365f;
	case 13921ULL: goto x86_l_3661;
	case 13923ULL: goto x86_l_3663;
	case 13925ULL: goto x86_l_3665;
	case 13926ULL: goto x86_l_3666;
	case 13927ULL: goto x86_l_3667;
	case 13928ULL: goto x86_l_3668;
	case 13930ULL: goto x86_l_366a;
	case 13932ULL: goto x86_l_366c;
	case 13934ULL: goto x86_l_366e;
	case 13936ULL: goto x86_l_3670;
	case 13937ULL: goto x86_l_3671;
	case 13938ULL: goto x86_l_3672;
	case 13941ULL: goto x86_l_3675;
	case 13944ULL: goto x86_l_3678;
	case 13947ULL: goto x86_l_367b;
	case 13950ULL: goto x86_l_367e;
	case 13955ULL: goto x86_l_3683;
	case 13957ULL: goto x86_l_3685;
	case 13963ULL: goto x86_l_368b;
	case 13966ULL: goto x86_l_368e;
	case 13973ULL: goto x86_l_3695;
	case 13976ULL: goto x86_l_3698;
	case 13979ULL: goto x86_l_369b;
	case 13985ULL: goto x86_l_36a1;
	case 13989ULL: goto x86_l_36a5;
	case 13992ULL: goto x86_l_36a8;
	case 13995ULL: goto x86_l_36ab;
	case 14000ULL: goto x86_l_36b0;
	case 14002ULL: goto x86_l_36b2;
	case 14008ULL: goto x86_l_36b8;
	case 14013ULL: goto x86_l_36bd;
	case 14016ULL: goto x86_l_36c0;
	case 14019ULL: goto x86_l_36c3;
	case 14022ULL: goto x86_l_36c6;
	case 14025ULL: goto x86_l_36c9;
	case 14031ULL: goto x86_l_36cf;
	case 14035ULL: goto x86_l_36d3;
	case 14038ULL: goto x86_l_36d6;
	case 14041ULL: goto x86_l_36d9;
	case 14046ULL: goto x86_l_36de;
	case 14048ULL: goto x86_l_36e0;
	case 14054ULL: goto x86_l_36e6;
	case 14059ULL: goto x86_l_36eb;
	case 14062ULL: goto x86_l_36ee;
	case 14065ULL: goto x86_l_36f1;
	case 14068ULL: goto x86_l_36f4;
	case 14071ULL: goto x86_l_36f7;
	case 14077ULL: goto x86_l_36fd;
	case 14081ULL: goto x86_l_3701;
	case 14084ULL: goto x86_l_3704;
	case 14087ULL: goto x86_l_3707;
	case 14092ULL: goto x86_l_370c;
	case 14094ULL: goto x86_l_370e;
	case 14100ULL: goto x86_l_3714;
	case 14105ULL: goto x86_l_3719;
	case 14108ULL: goto x86_l_371c;
	case 14111ULL: goto x86_l_371f;
	case 14114ULL: goto x86_l_3722;
	case 14117ULL: goto x86_l_3725;
	case 14123ULL: goto x86_l_372b;
	case 14127ULL: goto x86_l_372f;
	case 14130ULL: goto x86_l_3732;
	case 14133ULL: goto x86_l_3735;
	case 14138ULL: goto x86_l_373a;
	case 14140ULL: goto x86_l_373c;
	case 14146ULL: goto x86_l_3742;
	case 14151ULL: goto x86_l_3747;
	case 14154ULL: goto x86_l_374a;
	case 14157ULL: goto x86_l_374d;
	case 14160ULL: goto x86_l_3750;
	case 14163ULL: goto x86_l_3753;
	case 14169ULL: goto x86_l_3759;
	case 14173ULL: goto x86_l_375d;
	case 14176ULL: goto x86_l_3760;
	case 14179ULL: goto x86_l_3763;
	case 14184ULL: goto x86_l_3768;
	case 14186ULL: goto x86_l_376a;
	case 14192ULL: goto x86_l_3770;
	case 14197ULL: goto x86_l_3775;
	case 14200ULL: goto x86_l_3778;
	case 14203ULL: goto x86_l_377b;
	case 14206ULL: goto x86_l_377e;
	case 14209ULL: goto x86_l_3781;
	case 14215ULL: goto x86_l_3787;
	case 14219ULL: goto x86_l_378b;
	case 14222ULL: goto x86_l_378e;
	case 14225ULL: goto x86_l_3791;
	case 14230ULL: goto x86_l_3796;
	case 14232ULL: goto x86_l_3798;
	case 14238ULL: goto x86_l_379e;
	case 14243ULL: goto x86_l_37a3;
	case 14246ULL: goto x86_l_37a6;
	case 14249ULL: goto x86_l_37a9;
	case 14252ULL: goto x86_l_37ac;
	case 14255ULL: goto x86_l_37af;
	case 14261ULL: goto x86_l_37b5;
	case 14265ULL: goto x86_l_37b9;
	case 14268ULL: goto x86_l_37bc;
	case 14271ULL: goto x86_l_37bf;
	case 14276ULL: goto x86_l_37c4;
	case 14278ULL: goto x86_l_37c6;
	case 14280ULL: goto x86_l_37c8;
	case 14285ULL: goto x86_l_37cd;
	case 14288ULL: goto x86_l_37d0;
	case 14291ULL: goto x86_l_37d3;
	case 14294ULL: goto x86_l_37d6;
	case 14297ULL: goto x86_l_37d9;
	case 14303ULL: goto x86_l_37df;
	case 14307ULL: goto x86_l_37e3;
	case 14310ULL: goto x86_l_37e6;
	case 14313ULL: goto x86_l_37e9;
	case 14318ULL: goto x86_l_37ee;
	case 14320ULL: goto x86_l_37f0;
	case 14322ULL: goto x86_l_37f2;
	case 14327ULL: goto x86_l_37f7;
	case 14330ULL: goto x86_l_37fa;
	case 14333ULL: goto x86_l_37fd;
	case 14336ULL: goto x86_l_3800;
	case 14339ULL: goto x86_l_3803;
	case 14345ULL: goto x86_l_3809;
	case 14348ULL: goto x86_l_380c;
	case 14351ULL: goto x86_l_380f;
	case 14354ULL: goto x86_l_3812;
	case 14357ULL: goto x86_l_3815;
	case 14362ULL: goto x86_l_381a;
	case 14364ULL: goto x86_l_381c;
	case 14366ULL: goto x86_l_381e;
	case 14371ULL: goto x86_l_3823;
	case 14374ULL: goto x86_l_3826;
	case 14377ULL: goto x86_l_3829;
	case 14382ULL: goto x86_l_382e;
	case 14385ULL: goto x86_l_3831;
	case 14393ULL: goto x86_l_3839;
	case 14400ULL: goto x86_l_3840;
	case 14405ULL: goto x86_l_3845;
	case 14410ULL: goto x86_l_384a;
	case 14412ULL: goto x86_l_384c;
	case 14415ULL: goto x86_l_384f;
	case 14417ULL: goto x86_l_3851;
	case 14421ULL: goto x86_l_3855;
	case 14423ULL: goto x86_l_3857;
	case 14427ULL: goto x86_l_385b;
	case 14429ULL: goto x86_l_385d;
	case 14433ULL: goto x86_l_3861;
	case 14435ULL: goto x86_l_3863;
	case 14439ULL: goto x86_l_3867;
	case 14441ULL: goto x86_l_3869;
	case 14447ULL: goto x86_l_386f;
	case 14449ULL: goto x86_l_3871;
	case 14453ULL: goto x86_l_3875;
	case 14455ULL: goto x86_l_3877;
	case 14459ULL: goto x86_l_387b;
	case 14461ULL: goto x86_l_387d;
	case 14465ULL: goto x86_l_3881;
	case 14467ULL: goto x86_l_3883;
	case 14473ULL: goto x86_l_3889;
	case 14475ULL: goto x86_l_388b;
	case 14481ULL: goto x86_l_3891;
	case 14483ULL: goto x86_l_3893;
	case 14489ULL: goto x86_l_3899;
	case 14491ULL: goto x86_l_389b;
	case 14497ULL: goto x86_l_38a1;
	case 14499ULL: goto x86_l_38a3;
	case 14505ULL: goto x86_l_38a9;
	case 14507ULL: goto x86_l_38ab;
	case 14513ULL: goto x86_l_38b1;
	case 14517ULL: goto x86_l_38b5;
	case 14520ULL: goto x86_l_38b8;
	case 14524ULL: goto x86_l_38bc;
	case 14525ULL: goto x86_l_38bd;
	case 14527ULL: goto x86_l_38bf;
	case 14529ULL: goto x86_l_38c1;
	case 14531ULL: goto x86_l_38c3;
	case 14533ULL: goto x86_l_38c5;
	case 14534ULL: goto x86_l_38c6;
	case 14535ULL: goto x86_l_38c7;
	case 14537ULL: goto x86_l_38c9;
	case 14539ULL: goto x86_l_38cb;
	case 14541ULL: goto x86_l_38cd;
	case 14542ULL: goto x86_l_38ce;
	case 14543ULL: goto x86_l_38cf;
	case 14546ULL: goto x86_l_38d2;
	case 14552ULL: goto x86_l_38d8;
	case 14555ULL: goto x86_l_38db;
	case 14558ULL: goto x86_l_38de;
	case 14565ULL: goto x86_l_38e5;
	case 14570ULL: goto x86_l_38ea;
	case 14574ULL: goto x86_l_38ee;
	case 14578ULL: goto x86_l_38f2;
	case 14583ULL: goto x86_l_38f7;
	case 14585ULL: goto x86_l_38f9;
	case 14587ULL: goto x86_l_38fb;
	case 14589ULL: goto x86_l_38fd;
	case 14591ULL: goto x86_l_38ff;
	case 14595ULL: goto x86_l_3903;
	case 14599ULL: goto x86_l_3907;
	case 14607ULL: goto x86_l_390f;
	case 14614ULL: goto x86_l_3916;
	case 14619ULL: goto x86_l_391b;
	case 14624ULL: goto x86_l_3920;
	case 14626ULL: goto x86_l_3922;
	case 14629ULL: goto x86_l_3925;
	case 14631ULL: goto x86_l_3927;
	case 14635ULL: goto x86_l_392b;
	case 14637ULL: goto x86_l_392d;
	case 14644ULL: goto x86_l_3934;
	case 14649ULL: goto x86_l_3939;
	case 14654ULL: goto x86_l_393e;
	case 14657ULL: goto x86_l_3941;
	case 14662ULL: goto x86_l_3946;
	case 14665ULL: goto x86_l_3949;
	case 14668ULL: goto x86_l_394c;
	case 14670ULL: goto x86_l_394e;
	case 14672ULL: goto x86_l_3950;
	case 14674ULL: goto x86_l_3952;
	case 14676ULL: goto x86_l_3954;
	case 14683ULL: goto x86_l_395b;
	case 14685ULL: goto x86_l_395d;
	case 14692ULL: goto x86_l_3964;
	case 14694ULL: goto x86_l_3966;
	case 14699ULL: goto x86_l_396b;
	case 14702ULL: goto x86_l_396e;
	case 14705ULL: goto x86_l_3971;
	case 14707ULL: goto x86_l_3973;
	case 14709ULL: goto x86_l_3975;
	case 14711ULL: goto x86_l_3977;
	case 14713ULL: goto x86_l_3979;
	case 14716ULL: goto x86_l_397c;
	case 14719ULL: goto x86_l_397f;
	case 14723ULL: goto x86_l_3983;
	case 14724ULL: goto x86_l_3984;
	case 14726ULL: goto x86_l_3986;
	case 14728ULL: goto x86_l_3988;
	case 14730ULL: goto x86_l_398a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_365c:
	/* 0x365c: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_365d:
	/* 0x365d: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_365f:
	/* 0x365f: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_3661:
	/* 0x3661: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3663:
	/* 0x3663: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3665:
	/* 0x3665: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3666:
	/* 0x3666: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3667:
	/* 0x3667: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_3668:
	/* 0x3668: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_366a:
	/* 0x366a: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_366c:
	/* 0x366c: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_366e:
	/* 0x366e: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3670:
	/* 0x3670: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3671:
	/* 0x3671: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_3672:
	/* 0x3672: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_3675:
	/* 0x3675: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_3678:
	/* 0x3678: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_367b:
	/* 0x367b: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_367e:
	/* 0x367e: call   38c7 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13955ULL);
	__x86_sim_call_depth++;
	goto x86_l_38c7;
x86_l_3683:
	/* 0x3683: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3685:
	/* 0x3685: js     382e <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_382e;
	}
x86_l_368b:
	/* 0x368b: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_368e:
	/* 0x368e: and    r13d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3695:
	/* 0x3695: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3698:
	/* 0x3698: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_369b:
	/* 0x369b: je     38b5 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38b5;
	}
x86_l_36a1:
	/* 0x36a1: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_36a5:
	/* 0x36a5: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_36a8:
	/* 0x36a8: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_36ab:
	/* 0x36ab: call   38c7 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14000ULL);
	__x86_sim_call_depth++;
	goto x86_l_38c7;
x86_l_36b0:
	/* 0x36b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36b2:
	/* 0x36b2: js     382e <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_382e;
	}
x86_l_36b8:
	/* 0x36b8: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_36bd:
	/* 0x36bd: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_36c0:
	/* 0x36c0: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_36c3:
	/* 0x36c3: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_36c6:
	/* 0x36c6: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_36c9:
	/* 0x36c9: je     38b5 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38b5;
	}
x86_l_36cf:
	/* 0x36cf: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_36d3:
	/* 0x36d3: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_36d6:
	/* 0x36d6: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_36d9:
	/* 0x36d9: call   38c7 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14046ULL);
	__x86_sim_call_depth++;
	goto x86_l_38c7;
x86_l_36de:
	/* 0x36de: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36e0:
	/* 0x36e0: js     382e <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_382e;
	}
x86_l_36e6:
	/* 0x36e6: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_36eb:
	/* 0x36eb: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_36ee:
	/* 0x36ee: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_36f1:
	/* 0x36f1: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_36f4:
	/* 0x36f4: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_36f7:
	/* 0x36f7: je     38b5 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38b5;
	}
x86_l_36fd:
	/* 0x36fd: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3701:
	/* 0x3701: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3704:
	/* 0x3704: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3707:
	/* 0x3707: call   38c7 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14092ULL);
	__x86_sim_call_depth++;
	goto x86_l_38c7;
x86_l_370c:
	/* 0x370c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_370e:
	/* 0x370e: js     382e <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_382e;
	}
x86_l_3714:
	/* 0x3714: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3719:
	/* 0x3719: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_371c:
	/* 0x371c: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_371f:
	/* 0x371f: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3722:
	/* 0x3722: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3725:
	/* 0x3725: je     38b5 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38b5;
	}
x86_l_372b:
	/* 0x372b: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_372f:
	/* 0x372f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3732:
	/* 0x3732: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3735:
	/* 0x3735: call   38c7 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14138ULL);
	__x86_sim_call_depth++;
	goto x86_l_38c7;
x86_l_373a:
	/* 0x373a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_373c:
	/* 0x373c: js     382e <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_382e;
	}
x86_l_3742:
	/* 0x3742: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3747:
	/* 0x3747: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_374a:
	/* 0x374a: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_374d:
	/* 0x374d: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3750:
	/* 0x3750: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3753:
	/* 0x3753: je     38b5 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38b5;
	}
x86_l_3759:
	/* 0x3759: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_375d:
	/* 0x375d: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3760:
	/* 0x3760: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3763:
	/* 0x3763: call   38c7 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14184ULL);
	__x86_sim_call_depth++;
	goto x86_l_38c7;
x86_l_3768:
	/* 0x3768: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_376a:
	/* 0x376a: js     382e <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_382e;
	}
x86_l_3770:
	/* 0x3770: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3775:
	/* 0x3775: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_3778:
	/* 0x3778: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_377b:
	/* 0x377b: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_377e:
	/* 0x377e: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3781:
	/* 0x3781: je     38b5 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38b5;
	}
x86_l_3787:
	/* 0x3787: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_378b:
	/* 0x378b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_378e:
	/* 0x378e: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3791:
	/* 0x3791: call   38c7 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14230ULL);
	__x86_sim_call_depth++;
	goto x86_l_38c7;
x86_l_3796:
	/* 0x3796: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3798:
	/* 0x3798: js     382e <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_382e;
	}
x86_l_379e:
	/* 0x379e: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_37a3:
	/* 0x37a3: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_37a6:
	/* 0x37a6: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_37a9:
	/* 0x37a9: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_37ac:
	/* 0x37ac: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_37af:
	/* 0x37af: je     38b5 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38b5;
	}
x86_l_37b5:
	/* 0x37b5: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_37b9:
	/* 0x37b9: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_37bc:
	/* 0x37bc: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_37bf:
	/* 0x37bf: call   38c7 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14276ULL);
	__x86_sim_call_depth++;
	goto x86_l_38c7;
x86_l_37c4:
	/* 0x37c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37c6:
	/* 0x37c6: js     382e <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_382e;
	}
x86_l_37c8:
	/* 0x37c8: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_37cd:
	/* 0x37cd: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_37d0:
	/* 0x37d0: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_37d3:
	/* 0x37d3: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_37d6:
	/* 0x37d6: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_37d9:
	/* 0x37d9: je     38b5 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38b5;
	}
x86_l_37df:
	/* 0x37df: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_37e3:
	/* 0x37e3: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_37e6:
	/* 0x37e6: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_37e9:
	/* 0x37e9: call   38c7 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14318ULL);
	__x86_sim_call_depth++;
	goto x86_l_38c7;
x86_l_37ee:
	/* 0x37ee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37f0:
	/* 0x37f0: js     382e <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_382e;
	}
x86_l_37f2:
	/* 0x37f2: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_37f7:
	/* 0x37f7: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_37fa:
	/* 0x37fa: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_37fd:
	/* 0x37fd: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3800:
	/* 0x3800: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3803:
	/* 0x3803: je     38b5 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38b5;
	}
x86_l_3809:
	/* 0x3809: add    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_380c:
	/* 0x380c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_380f:
	/* 0x380f: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3812:
	/* 0x3812: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3815:
	/* 0x3815: call   38c7 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14362ULL);
	__x86_sim_call_depth++;
	goto x86_l_38c7;
x86_l_381a:
	/* 0x381a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_381c:
	/* 0x381c: js     382e <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_382e;
	}
x86_l_381e:
	/* 0x381e: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3823:
	/* 0x3823: add    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3826:
	/* 0x3826: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3829:
	/* 0x3829: jmp    38b5 <do_bytes+0x24e> */
	goto x86_l_38b5;
x86_l_382e:
	/* 0x382e: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3831:
	/* 0x3831: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3839:
	/* 0x3839: mov    rdi,QWORD PTR [rip+0x320] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_3840:
	/* 0x3840: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3845:
	/* 0x3845: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_384a:
	/* 0x384a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_384c:
	/* 0x384c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_384f:
	/* 0x384f: je     38b5 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38b5;
	}
x86_l_3851:
	/* 0x3851: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_3855:
	/* 0x3855: jg     3871 <do_bytes+0x20a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3871;
	}
x86_l_3857:
	/* 0x3857: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_385b:
	/* 0x385b: je     388b <do_bytes+0x224> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_388b;
	}
x86_l_385d:
	/* 0x385d: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_3861:
	/* 0x3861: je     38a3 <do_bytes+0x23c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38a3;
	}
x86_l_3863:
	/* 0x3863: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_3867:
	/* 0x3867: jne    389b <do_bytes+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_389b;
	}
x86_l_3869:
	/* 0x3869: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_386f:
	/* 0x386f: jmp    38b1 <do_bytes+0x24a> */
	goto x86_l_38b1;
x86_l_3871:
	/* 0x3871: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_3875:
	/* 0x3875: je     3893 <do_bytes+0x22c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3893;
	}
x86_l_3877:
	/* 0x3877: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_387b:
	/* 0x387b: je     38ab <do_bytes+0x244> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38ab;
	}
x86_l_387d:
	/* 0x387d: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_3881:
	/* 0x3881: jne    389b <do_bytes+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_389b;
	}
x86_l_3883:
	/* 0x3883: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_3889:
	/* 0x3889: jmp    38b1 <do_bytes+0x24a> */
	goto x86_l_38b1;
x86_l_388b:
	/* 0x388b: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_3891:
	/* 0x3891: jmp    38b1 <do_bytes+0x24a> */
	goto x86_l_38b1;
x86_l_3893:
	/* 0x3893: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_3899:
	/* 0x3899: jmp    38b1 <do_bytes+0x24a> */
	goto x86_l_38b1;
x86_l_389b:
	/* 0x389b: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_38a1:
	/* 0x38a1: jmp    38b1 <do_bytes+0x24a> */
	goto x86_l_38b1;
x86_l_38a3:
	/* 0x38a3: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_38a9:
	/* 0x38a9: jmp    38b1 <do_bytes+0x24a> */
	goto x86_l_38b1;
x86_l_38ab:
	/* 0x38ab: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_38b1:
	/* 0x38b1: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_38b5:
	/* 0x38b5: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_38b8:
	/* 0x38b8: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_38bc:
	/* 0x38bc: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_38bd:
	/* 0x38bd: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_38bf:
	/* 0x38bf: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_38c1:
	/* 0x38c1: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_38c3:
	/* 0x38c3: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_38c5:
	/* 0x38c5: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_38c6:
	/* 0x38c6: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_38c7:
	/* 0x38c7: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_38c9:
	/* 0x38c9: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_38cb:
	/* 0x38cb: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_38cd:
	/* 0x38cd: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_38ce:
	/* 0x38ce: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_38cf:
	/* 0x38cf: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_38d2:
	/* 0x38d2: js     3954 <__do_bytes+0x8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3954;
	}
x86_l_38d8:
	/* 0x38d8: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_38db:
	/* 0x38db: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_38de:
	/* 0x38de: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_38e5:
	/* 0x38e5: mov    ebx,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32736ULL);
x86_l_38ea:
	/* 0x38ea: cmovb  rbx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_38ee:
	/* 0x38ee: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_38f2:
	/* 0x38f2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_38f7:
	/* 0x38f7: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_38f9:
	/* 0x38f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38fb:
	/* 0x38fb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38fd:
	/* 0x38fd: js     3979 <__do_bytes+0xb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3979;
	}
x86_l_38ff:
	/* 0x38ff: lea    r15d,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3903:
	/* 0x3903: mov    DWORD PTR [r14+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3907:
	/* 0x3907: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_390f:
	/* 0x390f: mov    rdi,QWORD PTR [rip+0x57c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_3916:
	/* 0x3916: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_391b:
	/* 0x391b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3920:
	/* 0x3920: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3922:
	/* 0x3922: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3925:
	/* 0x3925: je     395d <__do_bytes+0x96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_395d;
	}
x86_l_3927:
	/* 0x3927: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_392b:
	/* 0x392b: je     395d <__do_bytes+0x96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_395d;
	}
x86_l_392d:
	/* 0x392d: mov    rsi,QWORD PTR [rip+0x57c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_3934:
	/* 0x3934: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_3939:
	/* 0x3939: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_393e:
	/* 0x393e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3941:
	/* 0x3941: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_3946:
	/* 0x3946: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_3949:
	/* 0x3949: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_394c:
	/* 0x394c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_394e:
	/* 0x394e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3950:
	/* 0x3950: js     3979 <__do_bytes+0xb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3979;
	}
x86_l_3952:
	/* 0x3952: jmp    397c <__do_bytes+0xb5> */
	goto x86_l_397c;
x86_l_3954:
	/* 0x3954: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_395b:
	/* 0x395b: jmp    397c <__do_bytes+0xb5> */
	goto x86_l_397c;
x86_l_395d:
	/* 0x395d: mov    rdi,QWORD PTR [rip+0x57c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_3964:
	/* 0x3964: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3966:
	/* 0x3966: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_396b:
	/* 0x396b: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_396e:
	/* 0x396e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3971:
	/* 0x3971: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3973:
	/* 0x3973: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3975:
	/* 0x3975: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3977:
	/* 0x3977: jns    397c <__do_bytes+0xb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_397c;
	}
x86_l_3979:
	/* 0x3979: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_397c:
	/* 0x397c: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_397f:
	/* 0x397f: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3983:
	/* 0x3983: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3984:
	/* 0x3984: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3986:
	/* 0x3986: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3988:
	/* 0x3988: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_398a:
	/* 0x398a: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 13236U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1794ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1798ULL && __x86_pc <= 3594ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3598ULL && __x86_pc <= 5450ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5454ULL && __x86_pc <= 7255ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7258ULL && __x86_pc <= 9024ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9029ULL && __x86_pc <= 10769ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10774ULL && __x86_pc <= 12431ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12434ULL && __x86_pc <= 13912ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13916ULL && __x86_pc <= 14730ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

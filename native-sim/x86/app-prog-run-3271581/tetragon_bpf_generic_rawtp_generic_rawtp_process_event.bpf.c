extern char buffer_heap_map;
extern char config_map;
extern char fdinstall_map;
extern char process_call_heap;
extern char retprobe_map;
extern char tg_errmetrics_map;
extern char tg_ipv6_ext_heap;
extern char tp_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_rawtp_generic_rawtp_process_event_x86_chunk_0(
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
	case 71ULL: goto x86_l_47;
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
	case 157ULL: goto x86_l_9d;
	case 163ULL: goto x86_l_a3;
	case 166ULL: goto x86_l_a6;
	case 172ULL: goto x86_l_ac;
	case 180ULL: goto x86_l_b4;
	case 182ULL: goto x86_l_b6;
	case 185ULL: goto x86_l_b9;
	case 187ULL: goto x86_l_bb;
	case 192ULL: goto x86_l_c0;
	case 197ULL: goto x86_l_c5;
	case 209ULL: goto x86_l_d1;
	case 216ULL: goto x86_l_d8;
	case 221ULL: goto x86_l_dd;
	case 223ULL: goto x86_l_df;
	case 225ULL: goto x86_l_e1;
	case 227ULL: goto x86_l_e3;
	case 231ULL: goto x86_l_e7;
	case 233ULL: goto x86_l_e9;
	case 237ULL: goto x86_l_ed;
	case 240ULL: goto x86_l_f0;
	case 248ULL: goto x86_l_f8;
	case 250ULL: goto x86_l_fa;
	case 255ULL: goto x86_l_ff;
	case 257ULL: goto x86_l_101;
	case 262ULL: goto x86_l_106;
	case 266ULL: goto x86_l_10a;
	case 268ULL: goto x86_l_10c;
	case 274ULL: goto x86_l_112;
	case 278ULL: goto x86_l_116;
	case 280ULL: goto x86_l_118;
	case 284ULL: goto x86_l_11c;
	case 290ULL: goto x86_l_122;
	case 294ULL: goto x86_l_126;
	case 300ULL: goto x86_l_12c;
	case 305ULL: goto x86_l_131;
	case 308ULL: goto x86_l_134;
	case 314ULL: goto x86_l_13a;
	case 318ULL: goto x86_l_13e;
	case 324ULL: goto x86_l_144;
	case 329ULL: goto x86_l_149;
	case 333ULL: goto x86_l_14d;
	case 335ULL: goto x86_l_14f;
	case 339ULL: goto x86_l_153;
	case 345ULL: goto x86_l_159;
	case 350ULL: goto x86_l_15e;
	case 353ULL: goto x86_l_161;
	case 359ULL: goto x86_l_167;
	case 363ULL: goto x86_l_16b;
	case 369ULL: goto x86_l_171;
	case 374ULL: goto x86_l_176;
	case 378ULL: goto x86_l_17a;
	case 384ULL: goto x86_l_180;
	case 388ULL: goto x86_l_184;
	case 394ULL: goto x86_l_18a;
	case 398ULL: goto x86_l_18e;
	case 404ULL: goto x86_l_194;
	case 408ULL: goto x86_l_198;
	case 414ULL: goto x86_l_19e;
	case 418ULL: goto x86_l_1a2;
	case 424ULL: goto x86_l_1a8;
	case 430ULL: goto x86_l_1ae;
	case 435ULL: goto x86_l_1b3;
	case 439ULL: goto x86_l_1b7;
	case 445ULL: goto x86_l_1bd;
	case 449ULL: goto x86_l_1c1;
	case 455ULL: goto x86_l_1c7;
	case 459ULL: goto x86_l_1cb;
	case 465ULL: goto x86_l_1d1;
	case 469ULL: goto x86_l_1d5;
	case 471ULL: goto x86_l_1d7;
	case 476ULL: goto x86_l_1dc;
	case 480ULL: goto x86_l_1e0;
	case 486ULL: goto x86_l_1e6;
	case 490ULL: goto x86_l_1ea;
	case 496ULL: goto x86_l_1f0;
	case 500ULL: goto x86_l_1f4;
	case 506ULL: goto x86_l_1fa;
	case 510ULL: goto x86_l_1fe;
	case 516ULL: goto x86_l_204;
	case 521ULL: goto x86_l_209;
	case 525ULL: goto x86_l_20d;
	case 531ULL: goto x86_l_213;
	case 535ULL: goto x86_l_217;
	case 541ULL: goto x86_l_21d;
	case 545ULL: goto x86_l_221;
	case 551ULL: goto x86_l_227;
	case 555ULL: goto x86_l_22b;
	case 557ULL: goto x86_l_22d;
	case 562ULL: goto x86_l_232;
	case 567ULL: goto x86_l_237;
	case 570ULL: goto x86_l_23a;
	case 576ULL: goto x86_l_240;
	case 581ULL: goto x86_l_245;
	case 584ULL: goto x86_l_248;
	case 590ULL: goto x86_l_24e;
	case 598ULL: goto x86_l_256;
	case 605ULL: goto x86_l_25d;
	case 610ULL: goto x86_l_262;
	case 615ULL: goto x86_l_267;
	case 617ULL: goto x86_l_269;
	case 620ULL: goto x86_l_26c;
	case 628ULL: goto x86_l_274;
	case 634ULL: goto x86_l_27a;
	case 637ULL: goto x86_l_27d;
	case 644ULL: goto x86_l_284;
	case 650ULL: goto x86_l_28a;
	case 661ULL: goto x86_l_295;
	case 668ULL: goto x86_l_29c;
	case 673ULL: goto x86_l_2a1;
	case 678ULL: goto x86_l_2a6;
	case 680ULL: goto x86_l_2a8;
	case 683ULL: goto x86_l_2ab;
	case 689ULL: goto x86_l_2b1;
	case 692ULL: goto x86_l_2b4;
	case 697ULL: goto x86_l_2b9;
	case 705ULL: goto x86_l_2c1;
	case 713ULL: goto x86_l_2c9;
	case 721ULL: goto x86_l_2d1;
	case 724ULL: goto x86_l_2d4;
	case 728ULL: goto x86_l_2d8;
	case 736ULL: goto x86_l_2e0;
	case 741ULL: goto x86_l_2e5;
	case 743ULL: goto x86_l_2e7;
	case 749ULL: goto x86_l_2ed;
	case 752ULL: goto x86_l_2f0;
	case 758ULL: goto x86_l_2f6;
	case 761ULL: goto x86_l_2f9;
	case 768ULL: goto x86_l_300;
	case 774ULL: goto x86_l_306;
	case 777ULL: goto x86_l_309;
	case 782ULL: goto x86_l_30e;
	case 785ULL: goto x86_l_311;
	case 792ULL: goto x86_l_318;
	case 796ULL: goto x86_l_31c;
	case 800ULL: goto x86_l_320;
	case 807ULL: goto x86_l_327;
	case 812ULL: goto x86_l_32c;
	case 815ULL: goto x86_l_32f;
	case 820ULL: goto x86_l_334;
	case 823ULL: goto x86_l_337;
	case 825ULL: goto x86_l_339;
	case 833ULL: goto x86_l_341;
	case 837ULL: goto x86_l_345;
	case 842ULL: goto x86_l_34a;
	case 847ULL: goto x86_l_34f;
	case 852ULL: goto x86_l_354;
	case 857ULL: goto x86_l_359;
	case 860ULL: goto x86_l_35c;
	case 868ULL: goto x86_l_364;
	case 870ULL: goto x86_l_366;
	case 875ULL: goto x86_l_36b;
	case 879ULL: goto x86_l_36f;
	case 884ULL: goto x86_l_374;
	case 889ULL: goto x86_l_379;
	case 894ULL: goto x86_l_37e;
	case 899ULL: goto x86_l_383;
	case 903ULL: goto x86_l_387;
	case 908ULL: goto x86_l_38c;
	case 910ULL: goto x86_l_38e;
	case 915ULL: goto x86_l_393;
	case 923ULL: goto x86_l_39b;
	case 928ULL: goto x86_l_3a0;
	case 933ULL: goto x86_l_3a5;
	case 938ULL: goto x86_l_3aa;
	case 943ULL: goto x86_l_3af;
	case 945ULL: goto x86_l_3b1;
	case 948ULL: goto x86_l_3b4;
	case 953ULL: goto x86_l_3b9;
	case 962ULL: goto x86_l_3c2;
	case 970ULL: goto x86_l_3ca;
	case 976ULL: goto x86_l_3d0;
	case 979ULL: goto x86_l_3d3;
	case 987ULL: goto x86_l_3db;
	case 992ULL: goto x86_l_3e0;
	case 997ULL: goto x86_l_3e5;
	case 1000ULL: goto x86_l_3e8;
	case 1002ULL: goto x86_l_3ea;
	case 1008ULL: goto x86_l_3f0;
	case 1013ULL: goto x86_l_3f5;
	case 1017ULL: goto x86_l_3f9;
	case 1023ULL: goto x86_l_3ff;
	case 1026ULL: goto x86_l_402;
	case 1030ULL: goto x86_l_406;
	case 1036ULL: goto x86_l_40c;
	case 1041ULL: goto x86_l_411;
	case 1045ULL: goto x86_l_415;
	case 1047ULL: goto x86_l_417;
	case 1051ULL: goto x86_l_41b;
	case 1057ULL: goto x86_l_421;
	case 1063ULL: goto x86_l_427;
	case 1068ULL: goto x86_l_42c;
	case 1074ULL: goto x86_l_432;
	case 1076ULL: goto x86_l_434;
	case 1080ULL: goto x86_l_438;
	case 1082ULL: goto x86_l_43a;
	case 1086ULL: goto x86_l_43e;
	case 1088ULL: goto x86_l_440;
	case 1094ULL: goto x86_l_446;
	case 1096ULL: goto x86_l_448;
	case 1102ULL: goto x86_l_44e;
	case 1104ULL: goto x86_l_450;
	case 1108ULL: goto x86_l_454;
	case 1110ULL: goto x86_l_456;
	case 1114ULL: goto x86_l_45a;
	case 1116ULL: goto x86_l_45c;
	case 1122ULL: goto x86_l_462;
	case 1124ULL: goto x86_l_464;
	case 1129ULL: goto x86_l_469;
	case 1134ULL: goto x86_l_46e;
	case 1143ULL: goto x86_l_477;
	case 1147ULL: goto x86_l_47b;
	case 1153ULL: goto x86_l_481;
	case 1157ULL: goto x86_l_485;
	case 1163ULL: goto x86_l_48b;
	case 1167ULL: goto x86_l_48f;
	case 1173ULL: goto x86_l_495;
	case 1181ULL: goto x86_l_49d;
	case 1186ULL: goto x86_l_4a2;
	case 1192ULL: goto x86_l_4a8;
	case 1194ULL: goto x86_l_4aa;
	case 1197ULL: goto x86_l_4ad;
	case 1208ULL: goto x86_l_4b8;
	case 1215ULL: goto x86_l_4bf;
	case 1223ULL: goto x86_l_4c7;
	case 1228ULL: goto x86_l_4cc;
	case 1230ULL: goto x86_l_4ce;
	case 1232ULL: goto x86_l_4d0;
	case 1235ULL: goto x86_l_4d3;
	case 1241ULL: goto x86_l_4d9;
	case 1246ULL: goto x86_l_4de;
	case 1249ULL: goto x86_l_4e1;
	case 1257ULL: goto x86_l_4e9;
	case 1263ULL: goto x86_l_4ef;
	case 1271ULL: goto x86_l_4f7;
	case 1276ULL: goto x86_l_4fc;
	case 1283ULL: goto x86_l_503;
	case 1291ULL: goto x86_l_50b;
	case 1298ULL: goto x86_l_512;
	case 1302ULL: goto x86_l_516;
	case 1310ULL: goto x86_l_51e;
	case 1315ULL: goto x86_l_523;
	case 1317ULL: goto x86_l_525;
	case 1319ULL: goto x86_l_527;
	case 1327ULL: goto x86_l_52f;
	case 1332ULL: goto x86_l_534;
	case 1335ULL: goto x86_l_537;
	case 1342ULL: goto x86_l_53e;
	case 1345ULL: goto x86_l_541;
	case 1350ULL: goto x86_l_546;
	case 1355ULL: goto x86_l_54b;
	case 1360ULL: goto x86_l_550;
	case 1369ULL: goto x86_l_559;
	case 1373ULL: goto x86_l_55d;
	case 1378ULL: goto x86_l_562;
	case 1380ULL: goto x86_l_564;
	case 1384ULL: goto x86_l_568;
	case 1390ULL: goto x86_l_56e;
	case 1394ULL: goto x86_l_572;
	case 1396ULL: goto x86_l_574;
	case 1401ULL: goto x86_l_579;
	case 1406ULL: goto x86_l_57e;
	case 1410ULL: goto x86_l_582;
	case 1416ULL: goto x86_l_588;
	case 1420ULL: goto x86_l_58c;
	case 1422ULL: goto x86_l_58e;
	case 1434ULL: goto x86_l_59a;
	case 1442ULL: goto x86_l_5a2;
	case 1450ULL: goto x86_l_5aa;
	case 1455ULL: goto x86_l_5af;
	case 1459ULL: goto x86_l_5b3;
	case 1465ULL: goto x86_l_5b9;
	case 1468ULL: goto x86_l_5bc;
	case 1478ULL: goto x86_l_5c6;
	case 1482ULL: goto x86_l_5ca;
	case 1488ULL: goto x86_l_5d0;
	case 1493ULL: goto x86_l_5d5;
	case 1504ULL: goto x86_l_5e0;
	case 1511ULL: goto x86_l_5e7;
	case 1519ULL: goto x86_l_5ef;
	case 1524ULL: goto x86_l_5f4;
	case 1526ULL: goto x86_l_5f6;
	case 1529ULL: goto x86_l_5f9;
	case 1532ULL: goto x86_l_5fc;
	case 1538ULL: goto x86_l_602;
	case 1542ULL: goto x86_l_606;
	case 1547ULL: goto x86_l_60b;
	case 1552ULL: goto x86_l_610;
	case 1558ULL: goto x86_l_616;
	case 1562ULL: goto x86_l_61a;
	case 1570ULL: goto x86_l_622;
	case 1576ULL: goto x86_l_628;
	case 1580ULL: goto x86_l_62c;
	case 1586ULL: goto x86_l_632;
	case 1590ULL: goto x86_l_636;
	case 1596ULL: goto x86_l_63c;
	case 1600ULL: goto x86_l_640;
	case 1606ULL: goto x86_l_646;
	case 1610ULL: goto x86_l_64a;
	case 1615ULL: goto x86_l_64f;
	case 1621ULL: goto x86_l_655;
	case 1626ULL: goto x86_l_65a;
	case 1631ULL: goto x86_l_65f;
	case 1636ULL: goto x86_l_664;
	case 1641ULL: goto x86_l_669;
	case 1646ULL: goto x86_l_66e;
	case 1651ULL: goto x86_l_673;
	case 1653ULL: goto x86_l_675;
	case 1658ULL: goto x86_l_67a;
	case 1661ULL: goto x86_l_67d;
	case 1667ULL: goto x86_l_683;
	case 1678ULL: goto x86_l_68e;
	case 1685ULL: goto x86_l_695;
	case 1693ULL: goto x86_l_69d;
	case 1698ULL: goto x86_l_6a2;
	case 1700ULL: goto x86_l_6a4;
	case 1703ULL: goto x86_l_6a7;
	case 1706ULL: goto x86_l_6aa;
	case 1712ULL: goto x86_l_6b0;
	case 1716ULL: goto x86_l_6b4;
	case 1722ULL: goto x86_l_6ba;
	case 1726ULL: goto x86_l_6be;
	case 1732ULL: goto x86_l_6c4;
	case 1736ULL: goto x86_l_6c8;
	case 1742ULL: goto x86_l_6ce;
	case 1746ULL: goto x86_l_6d2;
	case 1752ULL: goto x86_l_6d8;
	case 1756ULL: goto x86_l_6dc;
	case 1762ULL: goto x86_l_6e2;
	case 1766ULL: goto x86_l_6e6;
	case 1771ULL: goto x86_l_6eb;
	case 1776ULL: goto x86_l_6f0;
	case 1781ULL: goto x86_l_6f5;
	case 1786ULL: goto x86_l_6fa;
	case 1792ULL: goto x86_l_700;
	case 1799ULL: goto x86_l_707;
	case 1804ULL: goto x86_l_70c;
	case 1806ULL: goto x86_l_70e;
	case 1812ULL: goto x86_l_714;
	case 1817ULL: goto x86_l_719;
	case 1822ULL: goto x86_l_71e;
	case 1827ULL: goto x86_l_723;
	case 1832ULL: goto x86_l_728;
	case 1837ULL: goto x86_l_72d;
	case 1840ULL: goto x86_l_730;
	case 1845ULL: goto x86_l_735;
	case 1847ULL: goto x86_l_737;
	case 1852ULL: goto x86_l_73c;
	case 1857ULL: goto x86_l_741;
	case 1862ULL: goto x86_l_746;
	case 1867ULL: goto x86_l_74b;
	case 1872ULL: goto x86_l_750;
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
	/* 0xa: sub    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 248ULL);
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
	/* 0x38: je     3c2c <generic_rawtp_process_event+0x3c2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15404ULL;
	}
x86_l_3e:
	/* 0x3e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_41:
	/* 0x41: mov    ebp,DWORD PTR [rax+0x5eec] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24300ULL);
x86_l_47:
	/* 0x47: mov    r12d,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4b:
	/* 0x4b: cmp    r12,0x2327 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 8999ULL);
x86_l_52:
	/* 0x52: ja     3b90 <generic_rawtp_process_event+0x3b90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 15248ULL;
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
	/* 0x7c: je     3b90 <generic_rawtp_process_event+0x3b90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15248ULL;
	}
x86_l_82:
	/* 0x82: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_85:
	/* 0x85: lea    rsi,[rax+0x5ee8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24296ULL);
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
	/* 0x9a: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_9d:
	/* 0x9d: jg     3b90 <generic_rawtp_process_event+0x3b90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 15248ULL;
	}
x86_l_a3:
	/* 0xa3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a6:
	/* 0xa6: je     3b90 <generic_rawtp_process_event+0x3b90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15248ULL;
	}
x86_l_ac:
	/* 0xac: mov    QWORD PTR [rsp+0xa0],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_b4:
	/* 0xb4: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_b6:
	/* 0xb6: and    edx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_b9:
	/* 0xb9: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_bb:
	/* 0xbb: mov    r12d,DWORD PTR [rax+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_c0:
	/* 0xc0: movsxd r13,DWORD PTR [rax+rcx*4+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RCX, 2, X86_WIDTH_32), 24ULL);
x86_l_c5:
	/* 0xc5: mov    DWORD PTR [r15+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_d1:
	/* 0xd1: test   r13d,0x180 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R13, X86_WIDTH_32, 384ULL);
x86_l_d8:
	/* 0xd8: mov    QWORD PTR [rsp+0x18],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dd:
	/* 0xdd: je     e3 <generic_rawtp_process_event+0xe3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e3;
	}
x86_l_df:
	/* 0xdf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e1:
	/* 0xe1: jmp    101 <generic_rawtp_process_event+0x101> */
	goto x86_l_101;
x86_l_e3:
	/* 0xe3: test   r13b,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R13, X86_WIDTH_8, 64ULL);
x86_l_e7:
	/* 0xe7: jne    fa <generic_rawtp_process_event+0xfa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fa;
	}
x86_l_e9:
	/* 0xe9: mov    eax,DWORD PTR [rax+rdx*4+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 64ULL);
x86_l_ed:
	/* 0xed: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_f0:
	/* 0xf0: mov    rax,QWORD PTR [r15+rax*8+0x5e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24144ULL);
x86_l_f8:
	/* 0xf8: jmp    101 <generic_rawtp_process_event+0x101> */
	goto x86_l_101;
x86_l_fa:
	/* 0xfa: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_ff:
	/* 0xff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_101:
	/* 0x101: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_106:
	/* 0x106: cmp    r12d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 21ULL);
x86_l_10a:
	/* 0x10a: jg     149 <generic_rawtp_process_event+0x149> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_149;
	}
x86_l_10c:
	/* 0x10c: mov    r15d,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 144ULL);
x86_l_112:
	/* 0x112: cmp    r12d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 11ULL);
x86_l_116:
	/* 0x116: jg     176 <generic_rawtp_process_event+0x176> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_176;
	}
x86_l_118:
	/* 0x118: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_11c:
	/* 0x11c: jg     1dc <generic_rawtp_process_event+0x1dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1dc;
	}
x86_l_122:
	/* 0x122: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_126:
	/* 0x126: jg     411 <generic_rawtp_process_event+0x411> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_411;
	}
x86_l_12c:
	/* 0x12c: lea    eax,[r12-0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_131:
	/* 0x131: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_134:
	/* 0x134: jb     3ea <generic_rawtp_process_event+0x3ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3ea;
	}
x86_l_13a:
	/* 0x13a: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_13e:
	/* 0x13e: je     3ea <generic_rawtp_process_event+0x3ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea;
	}
x86_l_144:
	/* 0x144: jmp    4aa <generic_rawtp_process_event+0x4aa> */
	goto x86_l_4aa;
x86_l_149:
	/* 0x149: cmp    r12d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 32ULL);
x86_l_14d:
	/* 0x14d: jle    1b3 <generic_rawtp_process_event+0x1b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1b3;
	}
x86_l_14f:
	/* 0x14f: cmp    r12d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 38ULL);
x86_l_153:
	/* 0x153: jg     209 <generic_rawtp_process_event+0x209> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_209;
	}
x86_l_159:
	/* 0x159: lea    eax,[r12-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_15e:
	/* 0x15e: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_161:
	/* 0x161: jb     42c <generic_rawtp_process_event+0x42c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_42c;
	}
x86_l_167:
	/* 0x167: cmp    r12d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 37ULL);
x86_l_16b:
	/* 0x16b: je     24e <generic_rawtp_process_event+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24e;
	}
x86_l_171:
	/* 0x171: jmp    4aa <generic_rawtp_process_event+0x4aa> */
	goto x86_l_4aa;
x86_l_176:
	/* 0x176: cmp    r12d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 16ULL);
x86_l_17a:
	/* 0x17a: jle    232 <generic_rawtp_process_event+0x232> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_232;
	}
x86_l_180:
	/* 0x180: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_184:
	/* 0x184: jle    3f5 <generic_rawtp_process_event+0x3f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3f5;
	}
x86_l_18a:
	/* 0x18a: cmp    r12d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 19ULL);
x86_l_18e:
	/* 0x18e: je     440 <generic_rawtp_process_event+0x440> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_440;
	}
x86_l_194:
	/* 0x194: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_198:
	/* 0x198: je     4a2 <generic_rawtp_process_event+0x4a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a2;
	}
x86_l_19e:
	/* 0x19e: cmp    r12d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 21ULL);
x86_l_1a2:
	/* 0x1a2: jne    4aa <generic_rawtp_process_event+0x4aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4aa;
	}
x86_l_1a8:
	/* 0x1a8: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_1ae:
	/* 0x1ae: jmp    4ad <generic_rawtp_process_event+0x4ad> */
	goto x86_l_4ad;
x86_l_1b3:
	/* 0x1b3: cmp    r12d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 25ULL);
x86_l_1b7:
	/* 0x1b7: jg     3e0 <generic_rawtp_process_event+0x3e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3e0;
	}
x86_l_1bd:
	/* 0x1bd: cmp    r12d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 22ULL);
x86_l_1c1:
	/* 0x1c1: je     448 <generic_rawtp_process_event+0x448> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_448;
	}
x86_l_1c7:
	/* 0x1c7: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_1cb:
	/* 0x1cb: je     42c <generic_rawtp_process_event+0x42c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42c;
	}
x86_l_1d1:
	/* 0x1d1: cmp    r12d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 24ULL);
x86_l_1d5:
	/* 0x1d5: je     24e <generic_rawtp_process_event+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24e;
	}
x86_l_1d7:
	/* 0x1d7: jmp    4aa <generic_rawtp_process_event+0x4aa> */
	goto x86_l_4aa;
x86_l_1dc:
	/* 0x1dc: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_1e0:
	/* 0x1e0: jg     42c <generic_rawtp_process_event+0x42c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_42c;
	}
x86_l_1e6:
	/* 0x1e6: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_1ea:
	/* 0x1ea: je     4ad <generic_rawtp_process_event+0x4ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ad;
	}
x86_l_1f0:
	/* 0x1f0: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_1f4:
	/* 0x1f4: je     421 <generic_rawtp_process_event+0x421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_421;
	}
x86_l_1fa:
	/* 0x1fa: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_1fe:
	/* 0x1fe: je     45c <generic_rawtp_process_event+0x45c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45c;
	}
x86_l_204:
	/* 0x204: jmp    4aa <generic_rawtp_process_event+0x4aa> */
	goto x86_l_4aa;
x86_l_209:
	/* 0x209: cmp    r12d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 40ULL);
x86_l_20d:
	/* 0x20d: jle    434 <generic_rawtp_process_event+0x434> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_434;
	}
x86_l_213:
	/* 0x213: cmp    r12d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 41ULL);
x86_l_217:
	/* 0x217: je     421 <generic_rawtp_process_event+0x421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_421;
	}
x86_l_21d:
	/* 0x21d: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_221:
	/* 0x221: je     440 <generic_rawtp_process_event+0x440> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_440;
	}
x86_l_227:
	/* 0x227: cmp    r12d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 42ULL);
x86_l_22b:
	/* 0x22b: je     24e <generic_rawtp_process_event+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24e;
	}
x86_l_22d:
	/* 0x22d: jmp    4aa <generic_rawtp_process_event+0x4aa> */
	goto x86_l_4aa;
x86_l_232:
	/* 0x232: lea    eax,[r12-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_237:
	/* 0x237: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_23a:
	/* 0x23a: jb     3ea <generic_rawtp_process_event+0x3ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3ea;
	}
x86_l_240:
	/* 0x240: lea    eax,[r12-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_245:
	/* 0x245: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_248:
	/* 0x248: jae    4aa <generic_rawtp_process_event+0x4aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4aa;
	}
x86_l_24e:
	/* 0x24e: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_256:
	/* 0x256: mov    rdi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_25d:
	/* 0x25d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_262:
	/* 0x262: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_267:
	/* 0x267: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_269:
	/* 0x269: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26c:
	/* 0x26c: mov    QWORD PTR [rsp+0x98],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_274:
	/* 0x274: je     f85 <generic_rawtp_process_event+0xf85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3973ULL;
	}
x86_l_27a:
	/* 0x27a: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_27d:
	/* 0x27d: cmp    DWORD PTR [rax+0x6410],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 110019882254336ULL);
x86_l_284:
	/* 0x284: je     464 <generic_rawtp_process_event+0x464> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_464;
	}
x86_l_28a:
	/* 0x28a: mov    DWORD PTR [r15+0x6410],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 110019882254336ULL);
x86_l_295:
	/* 0x295: mov    rdi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_29c:
	/* 0x29c: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a1:
	/* 0x2a1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a6:
	/* 0x2a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a8:
	/* 0x2a8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ab:
	/* 0x2ab: je     f85 <generic_rawtp_process_event+0xf85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3973ULL;
	}
x86_l_2b1:
	/* 0x2b1: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2b4:
	/* 0x2b4: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b9:
	/* 0x2b9: mov    eax,DWORD PTR [r15+rcx*4+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 24224ULL);
x86_l_2c1:
	/* 0x2c1: mov    r12,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2c9:
	/* 0x2c9: mov    DWORD PTR [r15+r12*1+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 144ULL);
x86_l_2d1:
	/* 0x2d1: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_2d4:
	/* 0x2d4: add    rbp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2d8:
	/* 0x2d8: mov    QWORD PTR [r15+rcx*8+0x5e78],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_2e0:
	/* 0x2e0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e5:
	/* 0x2e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e7:
	/* 0x2e7: jne    3d3 <generic_rawtp_process_event+0x3d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3d3;
	}
x86_l_2ed:
	/* 0x2ed: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_2f0:
	/* 0x2f0: add    rax,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2f6:
	/* 0x2f6: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2f9:
	/* 0x2f9: mov    eax,DWORD PTR [r15+0x6414] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25620ULL);
x86_l_300:
	/* 0x300: mov    r13d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4095ULL);
x86_l_306:
	/* 0x306: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_309:
	/* 0x309: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_30e:
	/* 0x30e: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_311:
	/* 0x311: mov    r12,QWORD PTR [r15+0x6430] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 25648ULL);
x86_l_318:
	/* 0x318: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_31c:
	/* 0x31c: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_320:
	/* 0x320: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_327:
	/* 0x327: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32c:
	/* 0x32c: add    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_32f:
	/* 0x32f: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_334:
	/* 0x334: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_337:
	/* 0x337: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_339:
	/* 0x339: mov    DWORD PTR [r15+rbp*1+0x90],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_341:
	/* 0x341: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_345:
	/* 0x345: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_34a:
	/* 0x34a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_34f:
	/* 0x34f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_354:
	/* 0x354: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_359:
	/* 0x359: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_35c:
	/* 0x35c: mov    r12,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_364:
	/* 0x364: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_366:
	/* 0x366: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_36b:
	/* 0x36b: add    rcx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_36f:
	/* 0x36f: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_374:
	/* 0x374: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_379:
	/* 0x379: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37e:
	/* 0x37e: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_383:
	/* 0x383: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_387:
	/* 0x387: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38c:
	/* 0x38c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38e:
	/* 0x38e: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_393:
	/* 0x393: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_39b:
	/* 0x39b: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3a0:
	/* 0x3a0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a5:
	/* 0x3a5: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3aa:
	/* 0x3aa: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3af:
	/* 0x3af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b1:
	/* 0x3b1: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3b4:
	/* 0x3b4: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b9:
	/* 0x3b9: mov    DWORD PTR [r13+rcx*1+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 17179869184ULL);
x86_l_3c2:
	/* 0x3c2: movzx  eax,WORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 176ULL);
x86_l_3ca:
	/* 0x3ca: mov    WORD PTR [r13+rcx*1+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 8ULL);
x86_l_3d0:
	/* 0x3d0: add    esi,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 14ULL);
x86_l_3d3:
	/* 0x3d3: mov    rbp,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3db:
	/* 0x3db: jmp    3b8a <generic_rawtp_process_event+0x3b8a> */
	return 15242ULL;
x86_l_3e0:
	/* 0x3e0: lea    eax,[r12-0x1d] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551587ULL);
x86_l_3e5:
	/* 0x3e5: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e8:
	/* 0x3e8: jae    450 <generic_rawtp_process_event+0x450> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_450;
	}
x86_l_3ea:
	/* 0x3ea: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_3f0:
	/* 0x3f0: jmp    4ad <generic_rawtp_process_event+0x4ad> */
	goto x86_l_4ad;
x86_l_3f5:
	/* 0x3f5: cmp    r12d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 17ULL);
x86_l_3f9:
	/* 0x3f9: je     4ad <generic_rawtp_process_event+0x4ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ad;
	}
x86_l_3ff:
	/* 0x3ff: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_402:
	/* 0x402: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_406:
	/* 0x406: je     4ad <generic_rawtp_process_event+0x4ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ad;
	}
x86_l_40c:
	/* 0x40c: jmp    4aa <generic_rawtp_process_event+0x4aa> */
	goto x86_l_4aa;
x86_l_411:
	/* 0x411: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_415:
	/* 0x415: je     42c <generic_rawtp_process_event+0x42c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42c;
	}
x86_l_417:
	/* 0x417: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_41b:
	/* 0x41b: jne    4aa <generic_rawtp_process_event+0x4aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4aa;
	}
x86_l_421:
	/* 0x421: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_427:
	/* 0x427: jmp    4ad <generic_rawtp_process_event+0x4ad> */
	goto x86_l_4ad;
x86_l_42c:
	/* 0x42c: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_432:
	/* 0x432: jmp    4ad <generic_rawtp_process_event+0x4ad> */
	goto x86_l_4ad;
x86_l_434:
	/* 0x434: cmp    r12d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 39ULL);
x86_l_438:
	/* 0x438: je     448 <generic_rawtp_process_event+0x448> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_448;
	}
x86_l_43a:
	/* 0x43a: cmp    r12d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 40ULL);
x86_l_43e:
	/* 0x43e: jne    4aa <generic_rawtp_process_event+0x4aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4aa;
	}
x86_l_440:
	/* 0x440: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_446:
	/* 0x446: jmp    4ad <generic_rawtp_process_event+0x4ad> */
	goto x86_l_4ad;
x86_l_448:
	/* 0x448: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_44e:
	/* 0x44e: jmp    4ad <generic_rawtp_process_event+0x4ad> */
	goto x86_l_4ad;
x86_l_450:
	/* 0x450: cmp    r12d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 26ULL);
x86_l_454:
	/* 0x454: je     45c <generic_rawtp_process_event+0x45c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45c;
	}
x86_l_456:
	/* 0x456: cmp    r12d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 27ULL);
x86_l_45a:
	/* 0x45a: jne    4aa <generic_rawtp_process_event+0x4aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4aa;
	}
x86_l_45c:
	/* 0x45c: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_462:
	/* 0x462: jmp    4ad <generic_rawtp_process_event+0x4ad> */
	goto x86_l_4ad;
x86_l_464:
	/* 0x464: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_469:
	/* 0x469: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_46e:
	/* 0x46e: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_477:
	/* 0x477: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_47b:
	/* 0x47b: jg     d54 <generic_rawtp_process_event+0xd54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3412ULL;
	}
x86_l_481:
	/* 0x481: cmp    r12d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 15ULL);
x86_l_485:
	/* 0x485: je     ee4 <generic_rawtp_process_event+0xee4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3812ULL;
	}
x86_l_48b:
	/* 0x48b: cmp    r12d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 16ULL);
x86_l_48f:
	/* 0x48f: jne    f85 <generic_rawtp_process_event+0xf85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3973ULL;
	}
x86_l_495:
	/* 0x495: lea    r12,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_49d:
	/* 0x49d: jmp    f39 <generic_rawtp_process_event+0xf39> */
	return 3897ULL;
x86_l_4a2:
	/* 0x4a2: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_4a8:
	/* 0x4a8: jmp    4ad <generic_rawtp_process_event+0x4ad> */
	goto x86_l_4ad;
x86_l_4aa:
	/* 0x4aa: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ad:
	/* 0x4ad: mov    DWORD PTR [rsp+0xf4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_4b8:
	/* 0x4b8: mov    rdi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_4bf:
	/* 0x4bf: lea    rsi,[rsp+0xf4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 244ULL);
x86_l_4c7:
	/* 0x4c7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4cc:
	/* 0x4cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ce:
	/* 0x4ce: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4d0:
	/* 0x4d0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4d3:
	/* 0x4d3: je     3b82 <generic_rawtp_process_event+0x3b82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15234ULL;
	}
x86_l_4d9:
	/* 0x4d9: mov    ecx,0x3ffb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16379ULL);
x86_l_4de:
	/* 0x4de: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_4e1:
	/* 0x4e1: cmp    rcx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 160ULL);
x86_l_4e9:
	/* 0x4e9: jbe    3b82 <generic_rawtp_process_event+0x3b82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 15234ULL;
	}
x86_l_4ef:
	/* 0x4ef: mov    QWORD PTR [rsp+0x98],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4f7:
	/* 0x4f7: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4fc:
	/* 0x4fc: mov    ecx,DWORD PTR [rax+rsi*4+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 24224ULL);
x86_l_503:
	/* 0x503: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_50b:
	/* 0x50b: mov    DWORD PTR [rax+rdx*1+0x90],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 144ULL);
x86_l_512:
	/* 0x512: lea    rbp,[rdx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_516:
	/* 0x516: mov    QWORD PTR [rax+rsi*8+0x5e78],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 3), 24184ULL);
x86_l_51e:
	/* 0x51e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_523:
	/* 0x523: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_525:
	/* 0x525: je     534 <generic_rawtp_process_event+0x534> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_534;
	}
x86_l_527:
	/* 0x527: mov    rbp,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_52f:
	/* 0x52f: jmp    3b82 <generic_rawtp_process_event+0x3b82> */
	return 15234ULL;
x86_l_534:
	/* 0x534: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_537:
	/* 0x537: add    rcx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_53e:
	/* 0x53e: add    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_541:
	/* 0x541: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_546:
	/* 0x546: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_54b:
	/* 0x54b: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_550:
	/* 0x550: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_559:
	/* 0x559: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_55d:
	/* 0x55d: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_562:
	/* 0x562: jg     57e <generic_rawtp_process_event+0x57e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_57e;
	}
x86_l_564:
	/* 0x564: cmp    r12d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 15ULL);
x86_l_568:
	/* 0x568: je     65a <generic_rawtp_process_event+0x65a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_65a;
	}
x86_l_56e:
	/* 0x56e: cmp    r12d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 16ULL);
x86_l_572:
	/* 0x572: jne    5af <generic_rawtp_process_event+0x5af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5af;
	}
x86_l_574:
	/* 0x574: lea    r15,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_579:
	/* 0x579: jmp    741 <generic_rawtp_process_event+0x741> */
	goto x86_l_741;
x86_l_57e:
	/* 0x57e: cmp    r12d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 24ULL);
x86_l_582:
	/* 0x582: je     719 <generic_rawtp_process_event+0x719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_719;
	}
x86_l_588:
	/* 0x588: cmp    r12d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 42ULL);
x86_l_58c:
	/* 0x58c: jne    5af <generic_rawtp_process_event+0x5af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5af;
	}
x86_l_58e:
	/* 0x58e: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_59a:
	/* 0x59a: mov    QWORD PTR [rsp+0xb8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_5a2:
	/* 0x5a2: lea    r15,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_5aa:
	/* 0x5aa: jmp    765 <generic_rawtp_process_event+0x765> */
	return 1893ULL;
x86_l_5af:
	/* 0x5af: cmp    r12d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 40ULL);
x86_l_5b3:
	/* 0x5b3: ja     683 <generic_rawtp_process_event+0x683> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_683;
	}
x86_l_5b9:
	/* 0x5b9: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_5bc:
	/* 0x5bc: movabs rcx,0x1c1f2027cf2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1932500565234ULL);
x86_l_5c6:
	/* 0x5c6: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_5ca:
	/* 0x5ca: jae    683 <generic_rawtp_process_event+0x683> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_683;
	}
x86_l_5d0:
	/* 0x5d0: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d5:
	/* 0x5d5: mov    DWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_5e0:
	/* 0x5e0: mov    rdi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_5e7:
	/* 0x5e7: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_5ef:
	/* 0x5ef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5f4:
	/* 0x5f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f6:
	/* 0x5f6: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f9:
	/* 0x5f9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5fc:
	/* 0x5fc: je     3b37 <generic_rawtp_process_event+0x3b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15159ULL;
	}
x86_l_602:
	/* 0x602: cmp    r12d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 13ULL);
x86_l_606:
	/* 0x606: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_60b:
	/* 0x60b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_610:
	/* 0x610: jle    d88 <generic_rawtp_process_event+0xd88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3464ULL;
	}
x86_l_616:
	/* 0x616: cmp    r12d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 30ULL);
x86_l_61a:
	/* 0x61a: mov    rbp,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_622:
	/* 0x622: jg     f9c <generic_rawtp_process_event+0xf9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3996ULL;
	}
x86_l_628:
	/* 0x628: cmp    r12d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 28ULL);
x86_l_62c:
	/* 0x62c: jg     1241 <generic_rawtp_process_event+0x1241> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4673ULL;
	}
x86_l_632:
	/* 0x632: cmp    r12d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 14ULL);
x86_l_636:
	/* 0x636: je     1b72 <generic_rawtp_process_event+0x1b72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7026ULL;
	}
x86_l_63c:
	/* 0x63c: cmp    r12d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 17ULL);
x86_l_640:
	/* 0x640: je     1ab7 <generic_rawtp_process_event+0x1ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6839ULL;
	}
x86_l_646:
	/* 0x646: cmp    r12d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 28ULL);
x86_l_64a:
	/* 0x64a: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_64f:
	/* 0x64f: je     1190 <generic_rawtp_process_event+0x1190> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4496ULL;
	}
x86_l_655:
	/* 0x655: jmp    3b4e <generic_rawtp_process_event+0x3b4e> */
	return 15182ULL;
x86_l_65a:
	/* 0x65a: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_65f:
	/* 0x65f: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
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
	/* 0x675: mov    r15,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_67a:
	/* 0x67a: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_67d:
	/* 0x67d: jne    765 <generic_rawtp_process_event+0x765> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1893ULL;
	}
x86_l_683:
	/* 0x683: mov    DWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_68e:
	/* 0x68e: mov    rdi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_695:
	/* 0x695: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_69d:
	/* 0x69d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6a2:
	/* 0x6a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a4:
	/* 0x6a4: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a7:
	/* 0x6a7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6aa:
	/* 0x6aa: je     2efd <generic_rawtp_process_event+0x2efd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12029ULL;
	}
x86_l_6b0:
	/* 0x6b0: cmp    r12d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 25ULL);
x86_l_6b4:
	/* 0x6b4: jg     11b4 <generic_rawtp_process_event+0x11b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4532ULL;
	}
x86_l_6ba:
	/* 0x6ba: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_6be:
	/* 0x6be: jle    132a <generic_rawtp_process_event+0x132a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4906ULL;
	}
x86_l_6c4:
	/* 0x6c4: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_6c8:
	/* 0x6c8: jle    180c <generic_rawtp_process_event+0x180c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6156ULL;
	}
x86_l_6ce:
	/* 0x6ce: cmp    r12d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 21ULL);
x86_l_6d2:
	/* 0x6d2: je     1efc <generic_rawtp_process_event+0x1efc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7932ULL;
	}
x86_l_6d8:
	/* 0x6d8: cmp    r12d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 22ULL);
x86_l_6dc:
	/* 0x6dc: je     1e6f <generic_rawtp_process_event+0x1e6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7791ULL;
	}
x86_l_6e2:
	/* 0x6e2: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_6e6:
	/* 0x6e6: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6eb:
	/* 0x6eb: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6f0:
	/* 0x6f0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6f5:
	/* 0x6f5: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6fa:
	/* 0x6fa: jne    2f0c <generic_rawtp_process_event+0x2f0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12044ULL;
	}
x86_l_700:
	/* 0x700: mov    DWORD PTR [rcx+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_707:
	/* 0x707: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_70c:
	/* 0x70c: mov    DWORD PTR [rcx],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_70e:
	/* 0x70e: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_714:
	/* 0x714: jmp    2f0c <generic_rawtp_process_event+0x2f0c> */
	return 12044ULL;
x86_l_719:
	/* 0x719: lea    r15,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_71e:
	/* 0x71e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_723:
	/* 0x723: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_728:
	/* 0x728: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_72d:
	/* 0x72d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_730:
	/* 0x730: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_735:
	/* 0x735: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_737:
	/* 0x737: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_73c:
	/* 0x73c: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_741:
	/* 0x741: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_746:
	/* 0x746: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_74b:
	/* 0x74b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_750:
	/* 0x750: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 1877ULL;
}

static __noinline __u64 tetragon_bpf_generic_rawtp_generic_rawtp_process_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1877ULL: goto x86_l_755;
	case 1882ULL: goto x86_l_75a;
	case 1884ULL: goto x86_l_75c;
	case 1889ULL: goto x86_l_761;
	case 1893ULL: goto x86_l_765;
	case 1904ULL: goto x86_l_770;
	case 1911ULL: goto x86_l_777;
	case 1919ULL: goto x86_l_77f;
	case 1924ULL: goto x86_l_784;
	case 1926ULL: goto x86_l_786;
	case 1929ULL: goto x86_l_789;
	case 1935ULL: goto x86_l_78f;
	case 1938ULL: goto x86_l_792;
	case 1944ULL: goto x86_l_798;
	case 1949ULL: goto x86_l_79d;
	case 1954ULL: goto x86_l_7a2;
	case 1956ULL: goto x86_l_7a4;
	case 1963ULL: goto x86_l_7ab;
	case 1971ULL: goto x86_l_7b3;
	case 1976ULL: goto x86_l_7b8;
	case 1981ULL: goto x86_l_7bd;
	case 1986ULL: goto x86_l_7c2;
	case 1988ULL: goto x86_l_7c4;
	case 1996ULL: goto x86_l_7cc;
	case 2004ULL: goto x86_l_7d4;
	case 2008ULL: goto x86_l_7d8;
	case 2016ULL: goto x86_l_7e0;
	case 2021ULL: goto x86_l_7e5;
	case 2026ULL: goto x86_l_7ea;
	case 2030ULL: goto x86_l_7ee;
	case 2038ULL: goto x86_l_7f6;
	case 2043ULL: goto x86_l_7fb;
	case 2051ULL: goto x86_l_803;
	case 2053ULL: goto x86_l_805;
	case 2061ULL: goto x86_l_80d;
	case 2065ULL: goto x86_l_811;
	case 2070ULL: goto x86_l_816;
	case 2075ULL: goto x86_l_81b;
	case 2080ULL: goto x86_l_820;
	case 2085ULL: goto x86_l_825;
	case 2087ULL: goto x86_l_827;
	case 2093ULL: goto x86_l_82d;
	case 2099ULL: goto x86_l_833;
	case 2101ULL: goto x86_l_835;
	case 2106ULL: goto x86_l_83a;
	case 2108ULL: goto x86_l_83c;
	case 2112ULL: goto x86_l_840;
	case 2117ULL: goto x86_l_845;
	case 2122ULL: goto x86_l_84a;
	case 2127ULL: goto x86_l_84f;
	case 2132ULL: goto x86_l_854;
	case 2134ULL: goto x86_l_856;
	case 2139ULL: goto x86_l_85b;
	case 2144ULL: goto x86_l_860;
	case 2146ULL: goto x86_l_862;
	case 2149ULL: goto x86_l_865;
	case 2156ULL: goto x86_l_86c;
	case 2166ULL: goto x86_l_876;
	case 2173ULL: goto x86_l_87d;
	case 2183ULL: goto x86_l_887;
	case 2189ULL: goto x86_l_88d;
	case 2198ULL: goto x86_l_896;
	case 2207ULL: goto x86_l_89f;
	case 2212ULL: goto x86_l_8a4;
	case 2221ULL: goto x86_l_8ad;
	case 2230ULL: goto x86_l_8b6;
	case 2239ULL: goto x86_l_8bf;
	case 2244ULL: goto x86_l_8c4;
	case 2249ULL: goto x86_l_8c9;
	case 2254ULL: goto x86_l_8ce;
	case 2259ULL: goto x86_l_8d3;
	case 2263ULL: goto x86_l_8d7;
	case 2268ULL: goto x86_l_8dc;
	case 2273ULL: goto x86_l_8e1;
	case 2278ULL: goto x86_l_8e6;
	case 2283ULL: goto x86_l_8eb;
	case 2288ULL: goto x86_l_8f0;
	case 2293ULL: goto x86_l_8f5;
	case 2298ULL: goto x86_l_8fa;
	case 2301ULL: goto x86_l_8fd;
	case 2303ULL: goto x86_l_8ff;
	case 2308ULL: goto x86_l_904;
	case 2313ULL: goto x86_l_909;
	case 2321ULL: goto x86_l_911;
	case 2324ULL: goto x86_l_914;
	case 2329ULL: goto x86_l_919;
	case 2331ULL: goto x86_l_91b;
	case 2336ULL: goto x86_l_920;
	case 2341ULL: goto x86_l_925;
	case 2349ULL: goto x86_l_92d;
	case 2352ULL: goto x86_l_930;
	case 2357ULL: goto x86_l_935;
	case 2359ULL: goto x86_l_937;
	case 2364ULL: goto x86_l_93c;
	case 2369ULL: goto x86_l_941;
	case 2377ULL: goto x86_l_949;
	case 2380ULL: goto x86_l_94c;
	case 2385ULL: goto x86_l_951;
	case 2387ULL: goto x86_l_953;
	case 2392ULL: goto x86_l_958;
	case 2396ULL: goto x86_l_95c;
	case 2401ULL: goto x86_l_961;
	case 2406ULL: goto x86_l_966;
	case 2411ULL: goto x86_l_96b;
	case 2413ULL: goto x86_l_96d;
	case 2418ULL: goto x86_l_972;
	case 2420ULL: goto x86_l_974;
	case 2425ULL: goto x86_l_979;
	case 2430ULL: goto x86_l_97e;
	case 2435ULL: goto x86_l_983;
	case 2438ULL: goto x86_l_986;
	case 2446ULL: goto x86_l_98e;
	case 2452ULL: goto x86_l_994;
	case 2454ULL: goto x86_l_996;
	case 2459ULL: goto x86_l_99b;
	case 2462ULL: goto x86_l_99e;
	case 2466ULL: goto x86_l_9a2;
	case 2472ULL: goto x86_l_9a8;
	case 2475ULL: goto x86_l_9ab;
	case 2477ULL: goto x86_l_9ad;
	case 2481ULL: goto x86_l_9b1;
	case 2484ULL: goto x86_l_9b4;
	case 2486ULL: goto x86_l_9b6;
	case 2489ULL: goto x86_l_9b9;
	case 2491ULL: goto x86_l_9bb;
	case 2494ULL: goto x86_l_9be;
	case 2499ULL: goto x86_l_9c3;
	case 2502ULL: goto x86_l_9c6;
	case 2510ULL: goto x86_l_9ce;
	case 2515ULL: goto x86_l_9d3;
	case 2523ULL: goto x86_l_9db;
	case 2528ULL: goto x86_l_9e0;
	case 2533ULL: goto x86_l_9e5;
	case 2538ULL: goto x86_l_9ea;
	case 2541ULL: goto x86_l_9ed;
	case 2543ULL: goto x86_l_9ef;
	case 2551ULL: goto x86_l_9f7;
	case 2557ULL: goto x86_l_9fd;
	case 2562ULL: goto x86_l_a02;
	case 2567ULL: goto x86_l_a07;
	case 2572ULL: goto x86_l_a0c;
	case 2577ULL: goto x86_l_a11;
	case 2582ULL: goto x86_l_a16;
	case 2585ULL: goto x86_l_a19;
	case 2587ULL: goto x86_l_a1b;
	case 2592ULL: goto x86_l_a20;
	case 2598ULL: goto x86_l_a26;
	case 2606ULL: goto x86_l_a2e;
	case 2611ULL: goto x86_l_a33;
	case 2616ULL: goto x86_l_a38;
	case 2621ULL: goto x86_l_a3d;
	case 2624ULL: goto x86_l_a40;
	case 2626ULL: goto x86_l_a42;
	case 2630ULL: goto x86_l_a46;
	case 2635ULL: goto x86_l_a4b;
	case 2640ULL: goto x86_l_a50;
	case 2645ULL: goto x86_l_a55;
	case 2650ULL: goto x86_l_a5a;
	case 2653ULL: goto x86_l_a5d;
	case 2655ULL: goto x86_l_a5f;
	case 2660ULL: goto x86_l_a64;
	case 2665ULL: goto x86_l_a69;
	case 2669ULL: goto x86_l_a6d;
	case 2672ULL: goto x86_l_a70;
	case 2677ULL: goto x86_l_a75;
	case 2679ULL: goto x86_l_a77;
	case 2681ULL: goto x86_l_a79;
	case 2684ULL: goto x86_l_a7c;
	case 2687ULL: goto x86_l_a7f;
	case 2692ULL: goto x86_l_a84;
	case 2694ULL: goto x86_l_a86;
	case 2697ULL: goto x86_l_a89;
	case 2701ULL: goto x86_l_a8d;
	case 2703ULL: goto x86_l_a8f;
	case 2707ULL: goto x86_l_a93;
	case 2709ULL: goto x86_l_a95;
	case 2712ULL: goto x86_l_a98;
	case 2714ULL: goto x86_l_a9a;
	case 2718ULL: goto x86_l_a9e;
	case 2721ULL: goto x86_l_aa1;
	case 2727ULL: goto x86_l_aa7;
	case 2733ULL: goto x86_l_aad;
	case 2739ULL: goto x86_l_ab3;
	case 2742ULL: goto x86_l_ab6;
	case 2744ULL: goto x86_l_ab8;
	case 2749ULL: goto x86_l_abd;
	case 2751ULL: goto x86_l_abf;
	case 2754ULL: goto x86_l_ac2;
	case 2758ULL: goto x86_l_ac6;
	case 2761ULL: goto x86_l_ac9;
	case 2764ULL: goto x86_l_acc;
	case 2767ULL: goto x86_l_acf;
	case 2772ULL: goto x86_l_ad4;
	case 2774ULL: goto x86_l_ad6;
	case 2779ULL: goto x86_l_adb;
	case 2782ULL: goto x86_l_ade;
	case 2788ULL: goto x86_l_ae4;
	case 2796ULL: goto x86_l_aec;
	case 2801ULL: goto x86_l_af1;
	case 2806ULL: goto x86_l_af6;
	case 2811ULL: goto x86_l_afb;
	case 2816ULL: goto x86_l_b00;
	case 2818ULL: goto x86_l_b02;
	case 2821ULL: goto x86_l_b05;
	case 2826ULL: goto x86_l_b0a;
	case 2830ULL: goto x86_l_b0e;
	case 2837ULL: goto x86_l_b15;
	case 2842ULL: goto x86_l_b1a;
	case 2845ULL: goto x86_l_b1d;
	case 2847ULL: goto x86_l_b1f;
	case 2851ULL: goto x86_l_b23;
	case 2856ULL: goto x86_l_b28;
	case 2861ULL: goto x86_l_b2d;
	case 2866ULL: goto x86_l_b32;
	case 2874ULL: goto x86_l_b3a;
	case 2879ULL: goto x86_l_b3f;
	case 2881ULL: goto x86_l_b41;
	case 2886ULL: goto x86_l_b46;
	case 2890ULL: goto x86_l_b4a;
	case 2895ULL: goto x86_l_b4f;
	case 2900ULL: goto x86_l_b54;
	case 2905ULL: goto x86_l_b59;
	case 2910ULL: goto x86_l_b5e;
	case 2914ULL: goto x86_l_b62;
	case 2919ULL: goto x86_l_b67;
	case 2921ULL: goto x86_l_b69;
	case 2926ULL: goto x86_l_b6e;
	case 2931ULL: goto x86_l_b73;
	case 2936ULL: goto x86_l_b78;
	case 2941ULL: goto x86_l_b7d;
	case 2946ULL: goto x86_l_b82;
	case 2951ULL: goto x86_l_b87;
	case 2953ULL: goto x86_l_b89;
	case 2958ULL: goto x86_l_b8e;
	case 2963ULL: goto x86_l_b93;
	case 2969ULL: goto x86_l_b99;
	case 2973ULL: goto x86_l_b9d;
	case 2978ULL: goto x86_l_ba2;
	case 2986ULL: goto x86_l_baa;
	case 2991ULL: goto x86_l_baf;
	case 2996ULL: goto x86_l_bb4;
	case 3001ULL: goto x86_l_bb9;
	case 3005ULL: goto x86_l_bbd;
	case 3010ULL: goto x86_l_bc2;
	case 3015ULL: goto x86_l_bc7;
	case 3020ULL: goto x86_l_bcc;
	case 3025ULL: goto x86_l_bd1;
	case 3027ULL: goto x86_l_bd3;
	case 3032ULL: goto x86_l_bd8;
	case 3037ULL: goto x86_l_bdd;
	case 3043ULL: goto x86_l_be3;
	case 3047ULL: goto x86_l_be7;
	case 3052ULL: goto x86_l_bec;
	case 3057ULL: goto x86_l_bf1;
	case 3062ULL: goto x86_l_bf6;
	case 3067ULL: goto x86_l_bfb;
	case 3070ULL: goto x86_l_bfe;
	case 3072ULL: goto x86_l_c00;
	case 3077ULL: goto x86_l_c05;
	case 3082ULL: goto x86_l_c0a;
	case 3086ULL: goto x86_l_c0e;
	case 3091ULL: goto x86_l_c13;
	case 3096ULL: goto x86_l_c18;
	case 3101ULL: goto x86_l_c1d;
	case 3103ULL: goto x86_l_c1f;
	case 3108ULL: goto x86_l_c24;
	case 3114ULL: goto x86_l_c2a;
	case 3122ULL: goto x86_l_c32;
	case 3127ULL: goto x86_l_c37;
	case 3132ULL: goto x86_l_c3c;
	case 3137ULL: goto x86_l_c41;
	case 3139ULL: goto x86_l_c43;
	case 3147ULL: goto x86_l_c4b;
	case 3153ULL: goto x86_l_c51;
	case 3158ULL: goto x86_l_c56;
	case 3163ULL: goto x86_l_c5b;
	case 3168ULL: goto x86_l_c60;
	case 3173ULL: goto x86_l_c65;
	case 3178ULL: goto x86_l_c6a;
	case 3181ULL: goto x86_l_c6d;
	case 3183ULL: goto x86_l_c6f;
	case 3188ULL: goto x86_l_c74;
	case 3194ULL: goto x86_l_c7a;
	case 3202ULL: goto x86_l_c82;
	case 3207ULL: goto x86_l_c87;
	case 3212ULL: goto x86_l_c8c;
	case 3217ULL: goto x86_l_c91;
	case 3220ULL: goto x86_l_c94;
	case 3222ULL: goto x86_l_c96;
	case 3226ULL: goto x86_l_c9a;
	case 3231ULL: goto x86_l_c9f;
	case 3236ULL: goto x86_l_ca4;
	case 3241ULL: goto x86_l_ca9;
	case 3246ULL: goto x86_l_cae;
	case 3249ULL: goto x86_l_cb1;
	case 3251ULL: goto x86_l_cb3;
	case 3256ULL: goto x86_l_cb8;
	case 3261ULL: goto x86_l_cbd;
	case 3265ULL: goto x86_l_cc1;
	case 3268ULL: goto x86_l_cc4;
	case 3273ULL: goto x86_l_cc9;
	case 3275ULL: goto x86_l_ccb;
	case 3277ULL: goto x86_l_ccd;
	case 3280ULL: goto x86_l_cd0;
	case 3283ULL: goto x86_l_cd3;
	case 3288ULL: goto x86_l_cd8;
	case 3290ULL: goto x86_l_cda;
	case 3293ULL: goto x86_l_cdd;
	case 3297ULL: goto x86_l_ce1;
	case 3299ULL: goto x86_l_ce3;
	case 3303ULL: goto x86_l_ce7;
	case 3305ULL: goto x86_l_ce9;
	case 3308ULL: goto x86_l_cec;
	case 3310ULL: goto x86_l_cee;
	case 3314ULL: goto x86_l_cf2;
	case 3317ULL: goto x86_l_cf5;
	case 3323ULL: goto x86_l_cfb;
	case 3329ULL: goto x86_l_d01;
	case 3335ULL: goto x86_l_d07;
	case 3338ULL: goto x86_l_d0a;
	case 3340ULL: goto x86_l_d0c;
	case 3345ULL: goto x86_l_d11;
	case 3347ULL: goto x86_l_d13;
	case 3350ULL: goto x86_l_d16;
	case 3354ULL: goto x86_l_d1a;
	case 3357ULL: goto x86_l_d1d;
	case 3360ULL: goto x86_l_d20;
	case 3363ULL: goto x86_l_d23;
	case 3368ULL: goto x86_l_d28;
	case 3370ULL: goto x86_l_d2a;
	case 3375ULL: goto x86_l_d2f;
	case 3378ULL: goto x86_l_d32;
	case 3384ULL: goto x86_l_d38;
	case 3392ULL: goto x86_l_d40;
	case 3397ULL: goto x86_l_d45;
	case 3402ULL: goto x86_l_d4a;
	case 3407ULL: goto x86_l_d4f;
	case 3412ULL: goto x86_l_d54;
	case 3416ULL: goto x86_l_d58;
	case 3422ULL: goto x86_l_d5e;
	case 3426ULL: goto x86_l_d62;
	case 3432ULL: goto x86_l_d68;
	case 3435ULL: goto x86_l_d6b;
	case 3441ULL: goto x86_l_d71;
	case 3452ULL: goto x86_l_d7c;
	case 3459ULL: goto x86_l_d83;
	case 3464ULL: goto x86_l_d88;
	case 3468ULL: goto x86_l_d8c;
	case 3476ULL: goto x86_l_d94;
	case 3481ULL: goto x86_l_d99;
	case 3487ULL: goto x86_l_d9f;
	case 3492ULL: goto x86_l_da4;
	case 3495ULL: goto x86_l_da7;
	case 3501ULL: goto x86_l_dad;
	case 3506ULL: goto x86_l_db2;
	case 3509ULL: goto x86_l_db5;
	case 3515ULL: goto x86_l_dbb;
	case 3519ULL: goto x86_l_dbf;
	case 3525ULL: goto x86_l_dc5;
	case 3528ULL: goto x86_l_dc8;
	case 3533ULL: goto x86_l_dcd;
	case 3538ULL: goto x86_l_dd2;
	case 3542ULL: goto x86_l_dd6;
	case 3546ULL: goto x86_l_dda;
	case 3550ULL: goto x86_l_dde;
	case 3555ULL: goto x86_l_de3;
	case 3560ULL: goto x86_l_de8;
	case 3565ULL: goto x86_l_ded;
	case 3567ULL: goto x86_l_def;
	case 3571ULL: goto x86_l_df3;
	case 3575ULL: goto x86_l_df7;
	case 3580ULL: goto x86_l_dfc;
	case 3585ULL: goto x86_l_e01;
	case 3590ULL: goto x86_l_e06;
	case 3592ULL: goto x86_l_e08;
	case 3596ULL: goto x86_l_e0c;
	case 3603ULL: goto x86_l_e13;
	case 3608ULL: goto x86_l_e18;
	case 3613ULL: goto x86_l_e1d;
	case 3618ULL: goto x86_l_e22;
	case 3620ULL: goto x86_l_e24;
	case 3624ULL: goto x86_l_e28;
	case 3631ULL: goto x86_l_e2f;
	case 3636ULL: goto x86_l_e34;
	default: return 0xffffffffffffffffULL;
	}
x86_l_755:
	/* 0x755: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_75a:
	/* 0x75a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_75c:
	/* 0x75c: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_761:
	/* 0x761: add    r15,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_765:
	/* 0x765: mov    DWORD PTR [rsp+0xd4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_770:
	/* 0x770: mov    rdi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_777:
	/* 0x777: lea    rsi,[rsp+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_77f:
	/* 0x77f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_784:
	/* 0x784: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_786:
	/* 0x786: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_789:
	/* 0x789: je     9c3 <generic_rawtp_process_event+0x9c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9c3;
	}
x86_l_78f:
	/* 0x78f: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_792:
	/* 0x792: add    rax,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4096ULL);
x86_l_798:
	/* 0x798: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_79d:
	/* 0x79d: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_7a2:
	/* 0x7a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a4:
	/* 0x7a4: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_7ab:
	/* 0x7ab: lea    rdi,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_7b3:
	/* 0x7b3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7b8:
	/* 0x7b8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7bd:
	/* 0x7bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7c2:
	/* 0x7c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c4:
	/* 0x7c4: mov    rbp,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_7cc:
	/* 0x7cc: mov    QWORD PTR [rsp+0xa8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_7d4:
	/* 0x7d4: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7d8:
	/* 0x7d8: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_7e0:
	/* 0x7e0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7e5:
	/* 0x7e5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7ea:
	/* 0x7ea: lea    rcx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7ee:
	/* 0x7ee: mov    QWORD PTR [rsp+0xc0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_7f6:
	/* 0x7f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7fb:
	/* 0x7fb: mov    QWORD PTR [rsp+0x90],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_803:
	/* 0x803: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_805:
	/* 0x805: mov    r15,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_80d:
	/* 0x80d: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_811:
	/* 0x811: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_816:
	/* 0x816: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_81b:
	/* 0x81b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_820:
	/* 0x820: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_825:
	/* 0x825: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_827:
	/* 0x827: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_82d:
	/* 0x82d: mov    r12d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4096ULL);
x86_l_833:
	/* 0x833: je     83c <generic_rawtp_process_event+0x83c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_83c;
	}
x86_l_835:
	/* 0x835: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_83a:
	/* 0x83a: jmp    88d <generic_rawtp_process_event+0x88d> */
	goto x86_l_88d;
x86_l_83c:
	/* 0x83c: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_840:
	/* 0x840: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_845:
	/* 0x845: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_84a:
	/* 0x84a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_84f:
	/* 0x84f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_854:
	/* 0x854: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_856:
	/* 0x856: cmp    QWORD PTR [rsp+0x28],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_85b:
	/* 0x85b: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_860:
	/* 0x860: je     88d <generic_rawtp_process_event+0x88d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_88d;
	}
x86_l_862:
	/* 0x862: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_865:
	/* 0x865: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_86c:
	/* 0x86c: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_876:
	/* 0x876: mov    QWORD PTR [r13+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_87d:
	/* 0x87d: mov    WORD PTR [r13+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_887:
	/* 0x887: mov    r12d,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4086ULL);
x86_l_88d:
	/* 0x88d: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_896:
	/* 0x896: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_89f:
	/* 0x89f: mov    QWORD PTR [rsp+0x38],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_8a4:
	/* 0x8a4: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_8ad:
	/* 0x8ad: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_8b6:
	/* 0x8b6: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_8bf:
	/* 0x8bf: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8c4:
	/* 0x8c4: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_8c9:
	/* 0x8c9: mov    DWORD PTR [rsp+0x60],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8ce:
	/* 0x8ce: mov    BYTE PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_8d3:
	/* 0x8d3: add    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_8d7:
	/* 0x8d7: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8dc:
	/* 0x8dc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8e1:
	/* 0x8e1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8e6:
	/* 0x8e6: lea    r13,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8eb:
	/* 0x8eb: lea    r15,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8f0:
	/* 0x8f0: lea    r12,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8f5:
	/* 0x8f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8fa:
	/* 0x8fa: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_8fd:
	/* 0x8fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ff:
	/* 0x8ff: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_904:
	/* 0x904: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_909:
	/* 0x909: mov    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_911:
	/* 0x911: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_914:
	/* 0x914: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_919:
	/* 0x919: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_91b:
	/* 0x91b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_920:
	/* 0x920: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_925:
	/* 0x925: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_92d:
	/* 0x92d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_930:
	/* 0x930: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_935:
	/* 0x935: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_937:
	/* 0x937: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_93c:
	/* 0x93c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_941:
	/* 0x941: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_949:
	/* 0x949: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_94c:
	/* 0x94c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_951:
	/* 0x951: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_953:
	/* 0x953: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_958:
	/* 0x958: lea    rax,[r15-0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551584ULL);
x86_l_95c:
	/* 0x95c: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_961:
	/* 0x961: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_966:
	/* 0x966: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_96b:
	/* 0x96b: jne    9d3 <generic_rawtp_process_event+0x9d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9d3;
	}
x86_l_96d:
	/* 0x96d: cmp    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_972:
	/* 0x972: jne    9d3 <generic_rawtp_process_event+0x9d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9d3;
	}
x86_l_974:
	/* 0x974: mov    BYTE PTR [rsp+0x64],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 429496729601ULL);
x86_l_979:
	/* 0x979: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_97e:
	/* 0x97e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_983:
	/* 0x983: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_986:
	/* 0x986: mov    r12,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_98e:
	/* 0x98e: je     b00 <generic_rawtp_process_event+0xb00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b00;
	}
x86_l_994:
	/* 0x994: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_996:
	/* 0x996: cmp    BYTE PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_99b:
	/* 0x99b: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_99e:
	/* 0x99e: mov    edx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9a2:
	/* 0x9a2: mov    r15d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4096ULL);
x86_l_9a8:
	/* 0x9a8: sub    r15d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_9ab:
	/* 0x9ab: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_9ad:
	/* 0x9ad: cmovle r15d,edx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_9b1:
	/* 0x9b1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9b4:
	/* 0x9b4: je     9c3 <generic_rawtp_process_event+0x9c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9c3;
	}
x86_l_9b6:
	/* 0x9b6: mov    bpl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_8);
x86_l_9b9:
	/* 0x9b9: add    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_9bb:
	/* 0x9bb: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_9be:
	/* 0x9be: jmp    b05 <generic_rawtp_process_event+0xb05> */
	goto x86_l_b05;
x86_l_9c3:
	/* 0x9c3: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9c6:
	/* 0x9c6: mov    rbp,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_9ce:
	/* 0x9ce: jmp    3b5b <generic_rawtp_process_event+0x3b5b> */
	return 15195ULL;
x86_l_9d3:
	/* 0x9d3: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9db:
	/* 0x9db: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9e0:
	/* 0x9e0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9e5:
	/* 0x9e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9ea:
	/* 0x9ea: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_9ed:
	/* 0x9ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ef:
	/* 0x9ef: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_9f7:
	/* 0x9f7: je     bb9 <generic_rawtp_process_event+0xbb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bb9;
	}
x86_l_9fd:
	/* 0x9fd: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a02:
	/* 0xa02: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a07:
	/* 0xa07: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a0c:
	/* 0xa0c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a11:
	/* 0xa11: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a16:
	/* 0xa16: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_a19:
	/* 0xa19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a1b:
	/* 0xa1b: cmp    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a20:
	/* 0xa20: je     bb9 <generic_rawtp_process_event+0xbb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bb9;
	}
x86_l_a26:
	/* 0xa26: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_a2e:
	/* 0xa2e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a33:
	/* 0xa33: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a38:
	/* 0xa38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a3d:
	/* 0xa3d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_a40:
	/* 0xa40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a42:
	/* 0xa42: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_a46:
	/* 0xa46: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a4b:
	/* 0xa4b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_a50:
	/* 0xa50: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a55:
	/* 0xa55: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_a5a:
	/* 0xa5a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_a5d:
	/* 0xa5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a5f:
	/* 0xa5f: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a64:
	/* 0xa64: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a69:
	/* 0xa69: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_a6d:
	/* 0xa6d: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_a70:
	/* 0xa70: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a75:
	/* 0xa75: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a77:
	/* 0xa77: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_a79:
	/* 0xa79: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_a7c:
	/* 0xa7c: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_a7f:
	/* 0xa7f: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_a84:
	/* 0xa84: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a86:
	/* 0xa86: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_a89:
	/* 0xa89: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_a8d:
	/* 0xa8d: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_a8f:
	/* 0xa8f: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_a93:
	/* 0xa93: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a95:
	/* 0xa95: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_a98:
	/* 0xa98: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_a9a:
	/* 0xa9a: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a9e:
	/* 0xa9e: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_aa1:
	/* 0xaa1: jb     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_979;
	}
x86_l_aa7:
	/* 0xaa7: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_aad:
	/* 0xaad: ja     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_979;
	}
x86_l_ab3:
	/* 0xab3: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_ab6:
	/* 0xab6: jbe    abd <generic_rawtp_process_event+0xabd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_abd;
	}
x86_l_ab8:
	/* 0xab8: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_abd:
	/* 0xabd: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_abf:
	/* 0xabf: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_ac2:
	/* 0xac2: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_ac6:
	/* 0xac6: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ac9:
	/* 0xac9: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_acc:
	/* 0xacc: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_acf:
	/* 0xacf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ad4:
	/* 0xad4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad6:
	/* 0xad6: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_adb:
	/* 0xadb: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_ade:
	/* 0xade: jbe    979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_979;
	}
x86_l_ae4:
	/* 0xae4: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_aec:
	/* 0xaec: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_af1:
	/* 0xaf1: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_af6:
	/* 0xaf6: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_afb:
	/* 0xafb: jmp    c18 <generic_rawtp_process_event+0xc18> */
	goto x86_l_c18;
x86_l_b00:
	/* 0xb00: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b02:
	/* 0xb02: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b05:
	/* 0xb05: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b0a:
	/* 0xb0a: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b0e:
	/* 0xb0e: and    r15d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b15:
	/* 0xb15: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b1a:
	/* 0xb1a: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_b1d:
	/* 0xb1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b1f:
	/* 0xb1f: mov    DWORD PTR [r13+0x0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b23:
	/* 0xb23: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b28:
	/* 0xb28: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b2d:
	/* 0xb2d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b32:
	/* 0xb32: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_b3a:
	/* 0xb3a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b3f:
	/* 0xb3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b41:
	/* 0xb41: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b46:
	/* 0xb46: add    rcx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_b4a:
	/* 0xb4a: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b4f:
	/* 0xb4f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b54:
	/* 0xb54: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b59:
	/* 0xb59: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b5e:
	/* 0xb5e: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_b62:
	/* 0xb62: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b67:
	/* 0xb67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b69:
	/* 0xb69: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b6e:
	/* 0xb6e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b73:
	/* 0xb73: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_b78:
	/* 0xb78: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b7d:
	/* 0xb7d: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b82:
	/* 0xb82: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_b87:
	/* 0xb87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b89:
	/* 0xb89: mov    DWORD PTR [r13+r15*1+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 4ULL);
x86_l_b8e:
	/* 0xb8e: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_b93:
	/* 0xb93: mov    WORD PTR [r13+r15*1+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 8ULL);
x86_l_b99:
	/* 0xb99: add    r15d,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_b9d:
	/* 0xb9d: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ba2:
	/* 0xba2: mov    rbp,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_baa:
	/* 0xbaa: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_baf:
	/* 0xbaf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_bb4:
	/* 0xbb4: jmp    3b56 <generic_rawtp_process_event+0x3b56> */
	return 15190ULL;
x86_l_bb9:
	/* 0xbb9: lea    rdx,[r15-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_bbd:
	/* 0xbbd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bc2:
	/* 0xbc2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_bc7:
	/* 0xbc7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bcc:
	/* 0xbcc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bd1:
	/* 0xbd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd3:
	/* 0xbd3: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_bd8:
	/* 0xbd8: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_bdd:
	/* 0xbdd: je     974 <generic_rawtp_process_event+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_974;
	}
x86_l_be3:
	/* 0xbe3: add    r15,0xfffffffffffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551608ULL);
x86_l_be7:
	/* 0xbe7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_bec:
	/* 0xbec: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bf1:
	/* 0xbf1: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_bf6:
	/* 0xbf6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bfb:
	/* 0xbfb: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_bfe:
	/* 0xbfe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c00:
	/* 0xc00: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c05:
	/* 0xc05: mov    QWORD PTR [rsp+0x50],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_c0a:
	/* 0xc0a: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c0e:
	/* 0xc0e: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c13:
	/* 0xc13: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c18:
	/* 0xc18: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_c1d:
	/* 0xc1d: jne    c2a <generic_rawtp_process_event+0xc2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c2a;
	}
x86_l_c1f:
	/* 0xc1f: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_c24:
	/* 0xc24: je     974 <generic_rawtp_process_event+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_974;
	}
x86_l_c2a:
	/* 0xc2a: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c32:
	/* 0xc32: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c37:
	/* 0xc37: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c3c:
	/* 0xc3c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c41:
	/* 0xc41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c43:
	/* 0xc43: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_c4b:
	/* 0xc4b: je     fdb <generic_rawtp_process_event+0xfdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4059ULL;
	}
x86_l_c51:
	/* 0xc51: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c56:
	/* 0xc56: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c5b:
	/* 0xc5b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c60:
	/* 0xc60: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c65:
	/* 0xc65: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c6a:
	/* 0xc6a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_c6d:
	/* 0xc6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c6f:
	/* 0xc6f: cmp    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c74:
	/* 0xc74: je     fdb <generic_rawtp_process_event+0xfdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4059ULL;
	}
x86_l_c7a:
	/* 0xc7a: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c82:
	/* 0xc82: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c87:
	/* 0xc87: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c8c:
	/* 0xc8c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c91:
	/* 0xc91: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_c94:
	/* 0xc94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c96:
	/* 0xc96: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_c9a:
	/* 0xc9a: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c9f:
	/* 0xc9f: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_ca4:
	/* 0xca4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ca9:
	/* 0xca9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_cae:
	/* 0xcae: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_cb1:
	/* 0xcb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cb3:
	/* 0xcb3: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cb8:
	/* 0xcb8: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_cbd:
	/* 0xcbd: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_cc1:
	/* 0xcc1: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_cc4:
	/* 0xcc4: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_cc9:
	/* 0xcc9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ccb:
	/* 0xccb: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_ccd:
	/* 0xccd: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_cd0:
	/* 0xcd0: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_cd3:
	/* 0xcd3: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_cd8:
	/* 0xcd8: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cda:
	/* 0xcda: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_cdd:
	/* 0xcdd: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_ce1:
	/* 0xce1: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_ce3:
	/* 0xce3: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_ce7:
	/* 0xce7: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ce9:
	/* 0xce9: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_cec:
	/* 0xcec: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_cee:
	/* 0xcee: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_cf2:
	/* 0xcf2: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_cf5:
	/* 0xcf5: jb     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_979;
	}
x86_l_cfb:
	/* 0xcfb: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_d01:
	/* 0xd01: ja     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_979;
	}
x86_l_d07:
	/* 0xd07: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_d0a:
	/* 0xd0a: jbe    d11 <generic_rawtp_process_event+0xd11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_d11;
	}
x86_l_d0c:
	/* 0xd0c: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_d11:
	/* 0xd11: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d13:
	/* 0xd13: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_d16:
	/* 0xd16: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_d1a:
	/* 0xd1a: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_d1d:
	/* 0xd1d: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d20:
	/* 0xd20: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d23:
	/* 0xd23: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d28:
	/* 0xd28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d2a:
	/* 0xd2a: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d2f:
	/* 0xd2f: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_d32:
	/* 0xd32: jbe    979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_979;
	}
x86_l_d38:
	/* 0xd38: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_d40:
	/* 0xd40: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d45:
	/* 0xd45: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d4a:
	/* 0xd4a: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d4f:
	/* 0xd4f: jmp    103a <generic_rawtp_process_event+0x103a> */
	return 4154ULL;
x86_l_d54:
	/* 0xd54: cmp    r12d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 24ULL);
x86_l_d58:
	/* 0xd58: je     f0b <generic_rawtp_process_event+0xf0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3851ULL;
	}
x86_l_d5e:
	/* 0xd5e: cmp    r12d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 42ULL);
x86_l_d62:
	/* 0xd62: jne    f85 <generic_rawtp_process_event+0xf85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3973ULL;
	}
x86_l_d68:
	/* 0xd68: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_d6b:
	/* 0xd6b: add    rax,0x6420 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 25632ULL);
x86_l_d71:
	/* 0xd71: mov    QWORD PTR [r15+0x6420],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 110088601731072ULL);
x86_l_d7c:
	/* 0xd7c: mov    QWORD PTR [r15+0x6428],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 25640ULL);
x86_l_d83:
	/* 0xd83: jmp    f63 <generic_rawtp_process_event+0xf63> */
	return 3939ULL;
x86_l_d88:
	/* 0xd88: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_d8c:
	/* 0xd8c: mov    rbp,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_d94:
	/* 0xd94: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d99:
	/* 0xd99: jle    1176 <generic_rawtp_process_event+0x1176> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4470ULL;
	}
x86_l_d9f:
	/* 0xd9f: lea    ecx,[r12-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_da4:
	/* 0xda4: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_da7:
	/* 0xda7: jb     1190 <generic_rawtp_process_event+0x1190> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4496ULL;
	}
x86_l_dad:
	/* 0xdad: lea    ecx,[r12-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_db2:
	/* 0xdb2: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_db5:
	/* 0xdb5: jb     11f2 <generic_rawtp_process_event+0x11f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4594ULL;
	}
x86_l_dbb:
	/* 0xdbb: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_dbf:
	/* 0xdbf: jne    3b4e <generic_rawtp_process_event+0x3b4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15182ULL;
	}
x86_l_dc5:
	/* 0xdc5: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_dc8:
	/* 0xdc8: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dcd:
	/* 0xdcd: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dd2:
	/* 0xdd2: mov    QWORD PTR [rbp+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_dd6:
	/* 0xdd6: lea    rdi,[rbp+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_dda:
	/* 0xdda: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dde:
	/* 0xdde: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_de3:
	/* 0xde3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_de8:
	/* 0xde8: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_ded:
	/* 0xded: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_def:
	/* 0xdef: lea    rdi,[rbp+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_df3:
	/* 0xdf3: lea    rdx,[r15+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_df7:
	/* 0xdf7: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_dfc:
	/* 0xdfc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e01:
	/* 0xe01: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_e06:
	/* 0xe06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e08:
	/* 0xe08: lea    rdi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e0c:
	/* 0xe0c: lea    rdx,[r15+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_e13:
	/* 0xe13: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e18:
	/* 0xe18: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e1d:
	/* 0xe1d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e22:
	/* 0xe22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e24:
	/* 0xe24: lea    rdi,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e28:
	/* 0xe28: lea    rdx,[r15+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_e2f:
	/* 0xe2f: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e34:
	/* 0xe34: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 3641ULL;
}

static __noinline __u64 tetragon_bpf_generic_rawtp_generic_rawtp_process_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3641ULL: goto x86_l_e39;
	case 3646ULL: goto x86_l_e3e;
	case 3648ULL: goto x86_l_e40;
	case 3652ULL: goto x86_l_e44;
	case 3659ULL: goto x86_l_e4b;
	case 3664ULL: goto x86_l_e50;
	case 3669ULL: goto x86_l_e55;
	case 3674ULL: goto x86_l_e5a;
	case 3676ULL: goto x86_l_e5c;
	case 3680ULL: goto x86_l_e60;
	case 3687ULL: goto x86_l_e67;
	case 3692ULL: goto x86_l_e6c;
	case 3697ULL: goto x86_l_e71;
	case 3702ULL: goto x86_l_e76;
	case 3704ULL: goto x86_l_e78;
	case 3708ULL: goto x86_l_e7c;
	case 3716ULL: goto x86_l_e84;
	case 3724ULL: goto x86_l_e8c;
	case 3732ULL: goto x86_l_e94;
	case 3740ULL: goto x86_l_e9c;
	case 3744ULL: goto x86_l_ea0;
	case 3747ULL: goto x86_l_ea3;
	case 3753ULL: goto x86_l_ea9;
	case 3756ULL: goto x86_l_eac;
	case 3762ULL: goto x86_l_eb2;
	case 3766ULL: goto x86_l_eb6;
	case 3771ULL: goto x86_l_ebb;
	case 3776ULL: goto x86_l_ec0;
	case 3779ULL: goto x86_l_ec3;
	case 3784ULL: goto x86_l_ec8;
	case 3786ULL: goto x86_l_eca;
	case 3791ULL: goto x86_l_ecf;
	case 3796ULL: goto x86_l_ed4;
	case 3799ULL: goto x86_l_ed7;
	case 3804ULL: goto x86_l_edc;
	case 3807ULL: goto x86_l_edf;
	case 3812ULL: goto x86_l_ee4;
	case 3817ULL: goto x86_l_ee9;
	case 3822ULL: goto x86_l_eee;
	case 3827ULL: goto x86_l_ef3;
	case 3832ULL: goto x86_l_ef8;
	case 3837ULL: goto x86_l_efd;
	case 3839ULL: goto x86_l_eff;
	case 3844ULL: goto x86_l_f04;
	case 3847ULL: goto x86_l_f07;
	case 3849ULL: goto x86_l_f09;
	case 3851ULL: goto x86_l_f0b;
	case 3859ULL: goto x86_l_f13;
	case 3864ULL: goto x86_l_f18;
	case 3869ULL: goto x86_l_f1d;
	case 3874ULL: goto x86_l_f22;
	case 3877ULL: goto x86_l_f25;
	case 3882ULL: goto x86_l_f2a;
	case 3884ULL: goto x86_l_f2c;
	case 3892ULL: goto x86_l_f34;
	case 3897ULL: goto x86_l_f39;
	case 3902ULL: goto x86_l_f3e;
	case 3907ULL: goto x86_l_f43;
	case 3912ULL: goto x86_l_f48;
	case 3920ULL: goto x86_l_f50;
	case 3925ULL: goto x86_l_f55;
	case 3927ULL: goto x86_l_f57;
	case 3935ULL: goto x86_l_f5f;
	case 3939ULL: goto x86_l_f63;
	case 3946ULL: goto x86_l_f6a;
	case 3953ULL: goto x86_l_f71;
	case 3958ULL: goto x86_l_f76;
	case 3963ULL: goto x86_l_f7b;
	case 3966ULL: goto x86_l_f7e;
	case 3971ULL: goto x86_l_f83;
	case 3973ULL: goto x86_l_f85;
	case 3975ULL: goto x86_l_f87;
	case 3983ULL: goto x86_l_f8f;
	case 3991ULL: goto x86_l_f97;
	case 3996ULL: goto x86_l_f9c;
	case 4000ULL: goto x86_l_fa0;
	case 4006ULL: goto x86_l_fa6;
	case 4011ULL: goto x86_l_fab;
	case 4014ULL: goto x86_l_fae;
	case 4020ULL: goto x86_l_fb4;
	case 4025ULL: goto x86_l_fb9;
	case 4031ULL: goto x86_l_fbf;
	case 4036ULL: goto x86_l_fc4;
	case 4039ULL: goto x86_l_fc7;
	case 4044ULL: goto x86_l_fcc;
	case 4049ULL: goto x86_l_fd1;
	case 4054ULL: goto x86_l_fd6;
	case 4059ULL: goto x86_l_fdb;
	case 4063ULL: goto x86_l_fdf;
	case 4068ULL: goto x86_l_fe4;
	case 4073ULL: goto x86_l_fe9;
	case 4078ULL: goto x86_l_fee;
	case 4083ULL: goto x86_l_ff3;
	case 4085ULL: goto x86_l_ff5;
	case 4090ULL: goto x86_l_ffa;
	case 4095ULL: goto x86_l_fff;
	case 4101ULL: goto x86_l_1005;
	case 4105ULL: goto x86_l_1009;
	case 4110ULL: goto x86_l_100e;
	case 4115ULL: goto x86_l_1013;
	case 4120ULL: goto x86_l_1018;
	case 4125ULL: goto x86_l_101d;
	case 4128ULL: goto x86_l_1020;
	case 4130ULL: goto x86_l_1022;
	case 4135ULL: goto x86_l_1027;
	case 4140ULL: goto x86_l_102c;
	case 4144ULL: goto x86_l_1030;
	case 4149ULL: goto x86_l_1035;
	case 4154ULL: goto x86_l_103a;
	case 4159ULL: goto x86_l_103f;
	case 4161ULL: goto x86_l_1041;
	case 4166ULL: goto x86_l_1046;
	case 4172ULL: goto x86_l_104c;
	case 4180ULL: goto x86_l_1054;
	case 4185ULL: goto x86_l_1059;
	case 4190ULL: goto x86_l_105e;
	case 4195ULL: goto x86_l_1063;
	case 4197ULL: goto x86_l_1065;
	case 4205ULL: goto x86_l_106d;
	case 4211ULL: goto x86_l_1073;
	case 4216ULL: goto x86_l_1078;
	case 4221ULL: goto x86_l_107d;
	case 4226ULL: goto x86_l_1082;
	case 4231ULL: goto x86_l_1087;
	case 4236ULL: goto x86_l_108c;
	case 4239ULL: goto x86_l_108f;
	case 4241ULL: goto x86_l_1091;
	case 4246ULL: goto x86_l_1096;
	case 4252ULL: goto x86_l_109c;
	case 4260ULL: goto x86_l_10a4;
	case 4265ULL: goto x86_l_10a9;
	case 4270ULL: goto x86_l_10ae;
	case 4275ULL: goto x86_l_10b3;
	case 4278ULL: goto x86_l_10b6;
	case 4280ULL: goto x86_l_10b8;
	case 4284ULL: goto x86_l_10bc;
	case 4289ULL: goto x86_l_10c1;
	case 4294ULL: goto x86_l_10c6;
	case 4299ULL: goto x86_l_10cb;
	case 4304ULL: goto x86_l_10d0;
	case 4307ULL: goto x86_l_10d3;
	case 4309ULL: goto x86_l_10d5;
	case 4314ULL: goto x86_l_10da;
	case 4319ULL: goto x86_l_10df;
	case 4323ULL: goto x86_l_10e3;
	case 4326ULL: goto x86_l_10e6;
	case 4331ULL: goto x86_l_10eb;
	case 4333ULL: goto x86_l_10ed;
	case 4335ULL: goto x86_l_10ef;
	case 4338ULL: goto x86_l_10f2;
	case 4341ULL: goto x86_l_10f5;
	case 4346ULL: goto x86_l_10fa;
	case 4348ULL: goto x86_l_10fc;
	case 4351ULL: goto x86_l_10ff;
	case 4355ULL: goto x86_l_1103;
	case 4357ULL: goto x86_l_1105;
	case 4361ULL: goto x86_l_1109;
	case 4363ULL: goto x86_l_110b;
	case 4366ULL: goto x86_l_110e;
	case 4368ULL: goto x86_l_1110;
	case 4372ULL: goto x86_l_1114;
	case 4375ULL: goto x86_l_1117;
	case 4381ULL: goto x86_l_111d;
	case 4387ULL: goto x86_l_1123;
	case 4393ULL: goto x86_l_1129;
	case 4396ULL: goto x86_l_112c;
	case 4398ULL: goto x86_l_112e;
	case 4403ULL: goto x86_l_1133;
	case 4405ULL: goto x86_l_1135;
	case 4408ULL: goto x86_l_1138;
	case 4412ULL: goto x86_l_113c;
	case 4415ULL: goto x86_l_113f;
	case 4418ULL: goto x86_l_1142;
	case 4421ULL: goto x86_l_1145;
	case 4426ULL: goto x86_l_114a;
	case 4428ULL: goto x86_l_114c;
	case 4433ULL: goto x86_l_1151;
	case 4436ULL: goto x86_l_1154;
	case 4442ULL: goto x86_l_115a;
	case 4450ULL: goto x86_l_1162;
	case 4455ULL: goto x86_l_1167;
	case 4460ULL: goto x86_l_116c;
	case 4465ULL: goto x86_l_1171;
	case 4470ULL: goto x86_l_1176;
	case 4474ULL: goto x86_l_117a;
	case 4480ULL: goto x86_l_1180;
	case 4484ULL: goto x86_l_1184;
	case 4486ULL: goto x86_l_1186;
	case 4490ULL: goto x86_l_118a;
	case 4496ULL: goto x86_l_1190;
	case 4502ULL: goto x86_l_1196;
	case 4507ULL: goto x86_l_119b;
	case 4512ULL: goto x86_l_11a0;
	case 4515ULL: goto x86_l_11a3;
	case 4520ULL: goto x86_l_11a8;
	case 4525ULL: goto x86_l_11ad;
	case 4530ULL: goto x86_l_11b2;
	case 4532ULL: goto x86_l_11b4;
	case 4536ULL: goto x86_l_11b8;
	case 4542ULL: goto x86_l_11be;
	case 4547ULL: goto x86_l_11c3;
	case 4550ULL: goto x86_l_11c6;
	case 4555ULL: goto x86_l_11cb;
	case 4561ULL: goto x86_l_11d1;
	case 4567ULL: goto x86_l_11d7;
	case 4572ULL: goto x86_l_11dc;
	case 4577ULL: goto x86_l_11e1;
	case 4582ULL: goto x86_l_11e6;
	case 4587ULL: goto x86_l_11eb;
	case 4589ULL: goto x86_l_11ed;
	case 4594ULL: goto x86_l_11f2;
	case 4599ULL: goto x86_l_11f7;
	case 4605ULL: goto x86_l_11fd;
	case 4610ULL: goto x86_l_1202;
	case 4613ULL: goto x86_l_1205;
	case 4618ULL: goto x86_l_120a;
	case 4623ULL: goto x86_l_120f;
	case 4628ULL: goto x86_l_1214;
	case 4630ULL: goto x86_l_1216;
	case 4635ULL: goto x86_l_121b;
	case 4640ULL: goto x86_l_1220;
	case 4643ULL: goto x86_l_1223;
	case 4648ULL: goto x86_l_1228;
	case 4652ULL: goto x86_l_122c;
	case 4658ULL: goto x86_l_1232;
	case 4662ULL: goto x86_l_1236;
	case 4668ULL: goto x86_l_123c;
	case 4673ULL: goto x86_l_1241;
	case 4678ULL: goto x86_l_1246;
	case 4684ULL: goto x86_l_124c;
	case 4689ULL: goto x86_l_1251;
	case 4692ULL: goto x86_l_1254;
	case 4697ULL: goto x86_l_1259;
	case 4702ULL: goto x86_l_125e;
	case 4707ULL: goto x86_l_1263;
	case 4709ULL: goto x86_l_1265;
	case 4714ULL: goto x86_l_126a;
	case 4717ULL: goto x86_l_126d;
	case 4722ULL: goto x86_l_1272;
	case 4727ULL: goto x86_l_1277;
	case 4731ULL: goto x86_l_127b;
	case 4737ULL: goto x86_l_1281;
	case 4741ULL: goto x86_l_1285;
	case 4746ULL: goto x86_l_128a;
	case 4752ULL: goto x86_l_1290;
	case 4755ULL: goto x86_l_1293;
	case 4760ULL: goto x86_l_1298;
	case 4765ULL: goto x86_l_129d;
	case 4773ULL: goto x86_l_12a5;
	case 4781ULL: goto x86_l_12ad;
	case 4789ULL: goto x86_l_12b5;
	case 4794ULL: goto x86_l_12ba;
	case 4799ULL: goto x86_l_12bf;
	case 4802ULL: goto x86_l_12c2;
	case 4807ULL: goto x86_l_12c7;
	case 4810ULL: goto x86_l_12ca;
	case 4812ULL: goto x86_l_12cc;
	case 4815ULL: goto x86_l_12cf;
	case 4821ULL: goto x86_l_12d5;
	case 4826ULL: goto x86_l_12da;
	case 4829ULL: goto x86_l_12dd;
	case 4835ULL: goto x86_l_12e3;
	case 4838ULL: goto x86_l_12e6;
	case 4844ULL: goto x86_l_12ec;
	case 4848ULL: goto x86_l_12f0;
	case 4853ULL: goto x86_l_12f5;
	case 4858ULL: goto x86_l_12fa;
	case 4863ULL: goto x86_l_12ff;
	case 4868ULL: goto x86_l_1304;
	case 4870ULL: goto x86_l_1306;
	case 4874ULL: goto x86_l_130a;
	case 4879ULL: goto x86_l_130f;
	case 4883ULL: goto x86_l_1313;
	case 4887ULL: goto x86_l_1317;
	case 4891ULL: goto x86_l_131b;
	case 4896ULL: goto x86_l_1320;
	case 4901ULL: goto x86_l_1325;
	case 4906ULL: goto x86_l_132a;
	case 4909ULL: goto x86_l_132d;
	case 4913ULL: goto x86_l_1331;
	case 4919ULL: goto x86_l_1337;
	case 4923ULL: goto x86_l_133b;
	case 4929ULL: goto x86_l_1341;
	case 4932ULL: goto x86_l_1344;
	case 4936ULL: goto x86_l_1348;
	case 4941ULL: goto x86_l_134d;
	case 4946ULL: goto x86_l_1352;
	case 4951ULL: goto x86_l_1357;
	case 4957ULL: goto x86_l_135d;
	case 4964ULL: goto x86_l_1364;
	case 4969ULL: goto x86_l_1369;
	case 4971ULL: goto x86_l_136b;
	case 4974ULL: goto x86_l_136e;
	case 4977ULL: goto x86_l_1371;
	case 4983ULL: goto x86_l_1377;
	case 4986ULL: goto x86_l_137a;
	case 4992ULL: goto x86_l_1380;
	case 4995ULL: goto x86_l_1383;
	case 5001ULL: goto x86_l_1389;
	case 5004ULL: goto x86_l_138c;
	case 5010ULL: goto x86_l_1392;
	case 5013ULL: goto x86_l_1395;
	case 5019ULL: goto x86_l_139b;
	case 5024ULL: goto x86_l_13a0;
	case 5028ULL: goto x86_l_13a4;
	case 5033ULL: goto x86_l_13a9;
	case 5039ULL: goto x86_l_13af;
	case 5042ULL: goto x86_l_13b2;
	case 5047ULL: goto x86_l_13b7;
	case 5050ULL: goto x86_l_13ba;
	case 5053ULL: goto x86_l_13bd;
	case 5056ULL: goto x86_l_13c0;
	case 5062ULL: goto x86_l_13c6;
	case 5067ULL: goto x86_l_13cb;
	case 5071ULL: goto x86_l_13cf;
	case 5073ULL: goto x86_l_13d1;
	case 5078ULL: goto x86_l_13d6;
	case 5083ULL: goto x86_l_13db;
	case 5087ULL: goto x86_l_13df;
	case 5093ULL: goto x86_l_13e5;
	case 5097ULL: goto x86_l_13e9;
	case 5102ULL: goto x86_l_13ee;
	case 5107ULL: goto x86_l_13f3;
	case 5112ULL: goto x86_l_13f8;
	case 5118ULL: goto x86_l_13fe;
	case 5121ULL: goto x86_l_1401;
	case 5126ULL: goto x86_l_1406;
	case 5130ULL: goto x86_l_140a;
	case 5135ULL: goto x86_l_140f;
	case 5141ULL: goto x86_l_1415;
	case 5146ULL: goto x86_l_141a;
	case 5151ULL: goto x86_l_141f;
	case 5156ULL: goto x86_l_1424;
	case 5158ULL: goto x86_l_1426;
	case 5163ULL: goto x86_l_142b;
	case 5166ULL: goto x86_l_142e;
	case 5172ULL: goto x86_l_1434;
	case 5177ULL: goto x86_l_1439;
	case 5181ULL: goto x86_l_143d;
	case 5185ULL: goto x86_l_1441;
	case 5189ULL: goto x86_l_1445;
	case 5194ULL: goto x86_l_144a;
	case 5199ULL: goto x86_l_144f;
	case 5204ULL: goto x86_l_1454;
	case 5206ULL: goto x86_l_1456;
	case 5210ULL: goto x86_l_145a;
	case 5214ULL: goto x86_l_145e;
	case 5219ULL: goto x86_l_1463;
	case 5224ULL: goto x86_l_1468;
	case 5229ULL: goto x86_l_146d;
	case 5231ULL: goto x86_l_146f;
	case 5235ULL: goto x86_l_1473;
	case 5242ULL: goto x86_l_147a;
	case 5247ULL: goto x86_l_147f;
	case 5252ULL: goto x86_l_1484;
	case 5257ULL: goto x86_l_1489;
	case 5259ULL: goto x86_l_148b;
	case 5263ULL: goto x86_l_148f;
	case 5270ULL: goto x86_l_1496;
	case 5275ULL: goto x86_l_149b;
	case 5280ULL: goto x86_l_14a0;
	case 5285ULL: goto x86_l_14a5;
	case 5287ULL: goto x86_l_14a7;
	case 5291ULL: goto x86_l_14ab;
	case 5298ULL: goto x86_l_14b2;
	case 5303ULL: goto x86_l_14b7;
	case 5308ULL: goto x86_l_14bc;
	case 5310ULL: goto x86_l_14be;
	case 5314ULL: goto x86_l_14c2;
	case 5321ULL: goto x86_l_14c9;
	case 5326ULL: goto x86_l_14ce;
	case 5331ULL: goto x86_l_14d3;
	case 5333ULL: goto x86_l_14d5;
	case 5337ULL: goto x86_l_14d9;
	case 5345ULL: goto x86_l_14e1;
	case 5353ULL: goto x86_l_14e9;
	case 5361ULL: goto x86_l_14f1;
	case 5369ULL: goto x86_l_14f9;
	case 5373ULL: goto x86_l_14fd;
	case 5376ULL: goto x86_l_1500;
	case 5382ULL: goto x86_l_1506;
	case 5385ULL: goto x86_l_1509;
	case 5391ULL: goto x86_l_150f;
	case 5395ULL: goto x86_l_1513;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e39:
	/* 0xe39: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e3e:
	/* 0xe3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e40:
	/* 0xe40: lea    rdi,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e44:
	/* 0xe44: lea    rdx,[r15+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_e4b:
	/* 0xe4b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e50:
	/* 0xe50: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e55:
	/* 0xe55: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e5a:
	/* 0xe5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e5c:
	/* 0xe5c: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_e60:
	/* 0xe60: lea    rdx,[r15+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_e67:
	/* 0xe67: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e6c:
	/* 0xe6c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e71:
	/* 0xe71: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e76:
	/* 0xe76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e78:
	/* 0xe78: lea    r12,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e7c:
	/* 0xe7c: mov    QWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e84:
	/* 0xe84: mov    QWORD PTR [rbp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_e8c:
	/* 0xe8c: mov    QWORD PTR [rbp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_e94:
	/* 0xe94: mov    QWORD PTR [rbp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_e9c:
	/* 0xe9c: movzx  eax,WORD PTR [rbp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_ea0:
	/* 0xea0: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_ea3:
	/* 0xea3: je     21d2 <generic_rawtp_process_event+0x21d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8658ULL;
	}
x86_l_ea9:
	/* 0xea9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_eac:
	/* 0xeac: jne    2202 <generic_rawtp_process_event+0x2202> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8706ULL;
	}
x86_l_eb2:
	/* 0xeb2: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_eb6:
	/* 0xeb6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ebb:
	/* 0xebb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ec0:
	/* 0xec0: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_ec3:
	/* 0xec3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ec8:
	/* 0xec8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eca:
	/* 0xeca: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ecf:
	/* 0xecf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ed4:
	/* 0xed4: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_ed7:
	/* 0xed7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_edc:
	/* 0xedc: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_edf:
	/* 0xedf: jmp    2200 <generic_rawtp_process_event+0x2200> */
	return 8704ULL;
x86_l_ee4:
	/* 0xee4: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_ee9:
	/* 0xee9: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_eee:
	/* 0xeee: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ef3:
	/* 0xef3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ef8:
	/* 0xef8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_efd:
	/* 0xefd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eff:
	/* 0xeff: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_f04:
	/* 0xf04: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f07:
	/* 0xf07: jne    f63 <generic_rawtp_process_event+0xf63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f63;
	}
x86_l_f09:
	/* 0xf09: jmp    f85 <generic_rawtp_process_event+0xf85> */
	goto x86_l_f85;
x86_l_f0b:
	/* 0xf0b: lea    r12,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_f13:
	/* 0xf13: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f18:
	/* 0xf18: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f1d:
	/* 0xf1d: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f22:
	/* 0xf22: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_f25:
	/* 0xf25: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f2a:
	/* 0xf2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f2c:
	/* 0xf2c: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_f34:
	/* 0xf34: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f39:
	/* 0xf39: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f3e:
	/* 0xf3e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f43:
	/* 0xf43: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f48:
	/* 0xf48: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_f50:
	/* 0xf50: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f55:
	/* 0xf55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f57:
	/* 0xf57: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_f5f:
	/* 0xf5f: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_f63:
	/* 0xf63: mov    QWORD PTR [r15+0x6430],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 25648ULL);
x86_l_f6a:
	/* 0xf6a: mov    rsi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tp_calls)));
x86_l_f71:
	/* 0xf71: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_f76:
	/* 0xf76: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_f7b:
	/* 0xf7b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f7e:
	/* 0xf7e: mov    edx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_f83:
	/* 0xf83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f85:
	/* 0xf85: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f87:
	/* 0xf87: mov    r12,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_f8f:
	/* 0xf8f: mov    rbp,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_f97:
	/* 0xf97: jmp    3b8a <generic_rawtp_process_event+0x3b8a> */
	return 15242ULL;
x86_l_f9c:
	/* 0xf9c: cmp    r12d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 38ULL);
x86_l_fa0:
	/* 0xfa0: jg     1277 <generic_rawtp_process_event+0x1277> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1277;
	}
x86_l_fa6:
	/* 0xfa6: lea    ecx,[r12-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_fab:
	/* 0xfab: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_fae:
	/* 0xfae: jae    13a0 <generic_rawtp_process_event+0x13a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_13a0;
	}
x86_l_fb4:
	/* 0xfb4: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fb9:
	/* 0xfb9: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_fbf:
	/* 0xfbf: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_fc4:
	/* 0xfc4: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_fc7:
	/* 0xfc7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fcc:
	/* 0xfcc: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fd1:
	/* 0xfd1: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_fd6:
	/* 0xfd6: jmp    1263 <generic_rawtp_process_event+0x1263> */
	goto x86_l_1263;
x86_l_fdb:
	/* 0xfdb: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fdf:
	/* 0xfdf: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fe4:
	/* 0xfe4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fe9:
	/* 0xfe9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fee:
	/* 0xfee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ff3:
	/* 0xff3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff5:
	/* 0xff5: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ffa:
	/* 0xffa: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_fff:
	/* 0xfff: je     974 <generic_rawtp_process_event+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2420ULL;
	}
x86_l_1005:
	/* 0x1005: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1009:
	/* 0x1009: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_100e:
	/* 0x100e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1013:
	/* 0x1013: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1018:
	/* 0x1018: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_101d:
	/* 0x101d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1020:
	/* 0x1020: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1022:
	/* 0x1022: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1027:
	/* 0x1027: mov    QWORD PTR [rsp+0x50],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_102c:
	/* 0x102c: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1030:
	/* 0x1030: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1035:
	/* 0x1035: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_103a:
	/* 0x103a: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_103f:
	/* 0x103f: jne    104c <generic_rawtp_process_event+0x104c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_104c;
	}
x86_l_1041:
	/* 0x1041: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_1046:
	/* 0x1046: je     974 <generic_rawtp_process_event+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2420ULL;
	}
x86_l_104c:
	/* 0x104c: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1054:
	/* 0x1054: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1059:
	/* 0x1059: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_105e:
	/* 0x105e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1063:
	/* 0x1063: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1065:
	/* 0x1065: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_106d:
	/* 0x106d: je     1618 <generic_rawtp_process_event+0x1618> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5656ULL;
	}
x86_l_1073:
	/* 0x1073: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1078:
	/* 0x1078: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_107d:
	/* 0x107d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1082:
	/* 0x1082: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1087:
	/* 0x1087: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_108c:
	/* 0x108c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_108f:
	/* 0x108f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1091:
	/* 0x1091: cmp    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1096:
	/* 0x1096: je     1618 <generic_rawtp_process_event+0x1618> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5656ULL;
	}
x86_l_109c:
	/* 0x109c: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
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
	/* 0x10b3: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_10b6:
	/* 0x10b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b8:
	/* 0x10b8: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_10bc:
	/* 0x10bc: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_10c1:
	/* 0x10c1: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_10c6:
	/* 0x10c6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10cb:
	/* 0x10cb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_10d0:
	/* 0x10d0: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_10d3:
	/* 0x10d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d5:
	/* 0x10d5: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_10da:
	/* 0x10da: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_10df:
	/* 0x10df: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_10e3:
	/* 0x10e3: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_10e6:
	/* 0x10e6: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_10eb:
	/* 0x10eb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10ed:
	/* 0x10ed: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_10ef:
	/* 0x10ef: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_10f2:
	/* 0x10f2: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_10f5:
	/* 0x10f5: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_10fa:
	/* 0x10fa: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10fc:
	/* 0x10fc: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_10ff:
	/* 0x10ff: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_1103:
	/* 0x1103: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1105:
	/* 0x1105: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_1109:
	/* 0x1109: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_110b:
	/* 0x110b: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_110e:
	/* 0x110e: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1110:
	/* 0x1110: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1114:
	/* 0x1114: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1117:
	/* 0x1117: jb     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2425ULL;
	}
x86_l_111d:
	/* 0x111d: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_1123:
	/* 0x1123: ja     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2425ULL;
	}
x86_l_1129:
	/* 0x1129: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_112c:
	/* 0x112c: jbe    1133 <generic_rawtp_process_event+0x1133> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1133;
	}
x86_l_112e:
	/* 0x112e: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_1133:
	/* 0x1133: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1135:
	/* 0x1135: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1138:
	/* 0x1138: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_113c:
	/* 0x113c: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_113f:
	/* 0x113f: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1142:
	/* 0x1142: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1145:
	/* 0x1145: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_114a:
	/* 0x114a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_114c:
	/* 0x114c: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1151:
	/* 0x1151: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1154:
	/* 0x1154: jbe    979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2425ULL;
	}
x86_l_115a:
	/* 0x115a: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1162:
	/* 0x1162: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1167:
	/* 0x1167: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_116c:
	/* 0x116c: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1171:
	/* 0x1171: jmp    1677 <generic_rawtp_process_event+0x1677> */
	return 5751ULL;
x86_l_1176:
	/* 0x1176: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_117a:
	/* 0x117a: jg     1228 <generic_rawtp_process_event+0x1228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1228;
	}
x86_l_1180:
	/* 0x1180: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_1184:
	/* 0x1184: je     11f2 <generic_rawtp_process_event+0x11f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11f2;
	}
x86_l_1186:
	/* 0x1186: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_118a:
	/* 0x118a: jne    3b4e <generic_rawtp_process_event+0x3b4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15182ULL;
	}
x86_l_1190:
	/* 0x1190: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_1196:
	/* 0x1196: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_119b:
	/* 0x119b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11a0:
	/* 0x11a0: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_11a3:
	/* 0x11a3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11a8:
	/* 0x11a8: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11ad:
	/* 0x11ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11b2:
	/* 0x11b2: jmp    1214 <generic_rawtp_process_event+0x1214> */
	goto x86_l_1214;
x86_l_11b4:
	/* 0x11b4: cmp    r12d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 32ULL);
x86_l_11b8:
	/* 0x11b8: jle    1543 <generic_rawtp_process_event+0x1543> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5443ULL;
	}
x86_l_11be:
	/* 0x11be: lea    eax,[r12-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_11c3:
	/* 0x11c3: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11c6:
	/* 0x11c6: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11cb:
	/* 0x11cb: jae    13db <generic_rawtp_process_event+0x13db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_13db;
	}
x86_l_11d1:
	/* 0x11d1: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_11d7:
	/* 0x11d7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11dc:
	/* 0x11dc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11e1:
	/* 0x11e1: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11e6:
	/* 0x11e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11eb:
	/* 0x11eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ed:
	/* 0x11ed: jmp    2efd <generic_rawtp_process_event+0x2efd> */
	return 12029ULL;
x86_l_11f2:
	/* 0x11f2: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11f7:
	/* 0x11f7: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_11fd:
	/* 0x11fd: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1202:
	/* 0x1202: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1205:
	/* 0x1205: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_120a:
	/* 0x120a: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_120f:
	/* 0x120f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1214:
	/* 0x1214: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1216:
	/* 0x1216: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_121b:
	/* 0x121b: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1220:
	/* 0x1220: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1223:
	/* 0x1223: jmp    3b4e <generic_rawtp_process_event+0x3b4e> */
	return 15182ULL;
x86_l_1228:
	/* 0x1228: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_122c:
	/* 0x122c: je     18fe <generic_rawtp_process_event+0x18fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6398ULL;
	}
x86_l_1232:
	/* 0x1232: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_1236:
	/* 0x1236: je     1bb4 <generic_rawtp_process_event+0x1bb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7092ULL;
	}
x86_l_123c:
	/* 0x123c: jmp    3b4e <generic_rawtp_process_event+0x3b4e> */
	return 15182ULL;
x86_l_1241:
	/* 0x1241: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1246:
	/* 0x1246: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_124c:
	/* 0x124c: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1251:
	/* 0x1251: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1254:
	/* 0x1254: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1259:
	/* 0x1259: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_125e:
	/* 0x125e: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1263:
	/* 0x1263: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1265:
	/* 0x1265: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_126a:
	/* 0x126a: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_126d:
	/* 0x126d: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1272:
	/* 0x1272: jmp    3b4e <generic_rawtp_process_event+0x3b4e> */
	return 15182ULL;
x86_l_1277:
	/* 0x1277: cmp    r12d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 39ULL);
x86_l_127b:
	/* 0x127b: je     1bd6 <generic_rawtp_process_event+0x1bd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7126ULL;
	}
x86_l_1281:
	/* 0x1281: cmp    r12d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 40ULL);
x86_l_1285:
	/* 0x1285: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_128a:
	/* 0x128a: jne    3b4e <generic_rawtp_process_event+0x3b4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15182ULL;
	}
x86_l_1290:
	/* 0x1290: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1293:
	/* 0x1293: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1298:
	/* 0x1298: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_129d:
	/* 0x129d: mov    QWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_12a5:
	/* 0x12a5: mov    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_12ad:
	/* 0x12ad: mov    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12b5:
	/* 0x12b5: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_12ba:
	/* 0x12ba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12bf:
	/* 0x12bf: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_12c2:
	/* 0x12c2: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_12c7:
	/* 0x12c7: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_12ca:
	/* 0x12ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12cc:
	/* 0x12cc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12cf:
	/* 0x12cf: js     24ea <generic_rawtp_process_event+0x24ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9450ULL;
	}
x86_l_12d5:
	/* 0x12d5: movzx  eax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_12da:
	/* 0x12da: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_12dd:
	/* 0x12dd: je     2499 <generic_rawtp_process_event+0x2499> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9369ULL;
	}
x86_l_12e3:
	/* 0x12e3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12e6:
	/* 0x12e6: jne    24d3 <generic_rawtp_process_event+0x24d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9427ULL;
	}
x86_l_12ec:
	/* 0x12ec: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_12f0:
	/* 0x12f0: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12f5:
	/* 0x12f5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12fa:
	/* 0x12fa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12ff:
	/* 0x12ff: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1304:
	/* 0x1304: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1306:
	/* 0x1306: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_130a:
	/* 0x130a: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_130f:
	/* 0x130f: mov    QWORD PTR [rcx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1313:
	/* 0x1313: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1317:
	/* 0x1317: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_131b:
	/* 0x131b: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1320:
	/* 0x1320: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1325:
	/* 0x1325: jmp    24c9 <generic_rawtp_process_event+0x24c9> */
	return 9417ULL;
x86_l_132a:
	/* 0x132a: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_132d:
	/* 0x132d: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_1331:
	/* 0x1331: jg     17b3 <generic_rawtp_process_event+0x17b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6067ULL;
	}
x86_l_1337:
	/* 0x1337: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_133b:
	/* 0x133b: je     1c1a <generic_rawtp_process_event+0x1c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7194ULL;
	}
x86_l_1341:
	/* 0x1341: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1344:
	/* 0x1344: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_1348:
	/* 0x1348: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_134d:
	/* 0x134d: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1352:
	/* 0x1352: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1357:
	/* 0x1357: jne    2f0c <generic_rawtp_process_event+0x2f0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12044ULL;
	}
x86_l_135d:
	/* 0x135d: lea    rax,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1364:
	/* 0x1364: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1369:
	/* 0x1369: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_136b:
	/* 0x136b: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_136e:
	/* 0x136e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1371:
	/* 0x1371: jle    24f8 <generic_rawtp_process_event+0x24f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 9464ULL;
	}
x86_l_1377:
	/* 0x1377: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_137a:
	/* 0x137a: je     2684 <generic_rawtp_process_event+0x2684> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9860ULL;
	}
x86_l_1380:
	/* 0x1380: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1383:
	/* 0x1383: je     268f <generic_rawtp_process_event+0x268f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9871ULL;
	}
x86_l_1389:
	/* 0x1389: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_138c:
	/* 0x138c: jne    2b30 <generic_rawtp_process_event+0x2b30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11056ULL;
	}
x86_l_1392:
	/* 0x1392: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_1395:
	/* 0x1395: add    rax,0x5e70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24176ULL);
x86_l_139b:
	/* 0x139b: jmp    26a3 <generic_rawtp_process_event+0x26a3> */
	return 9891ULL;
x86_l_13a0:
	/* 0x13a0: cmp    r12d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 38ULL);
x86_l_13a4:
	/* 0x13a4: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13a9:
	/* 0x13a9: jne    3b4e <generic_rawtp_process_event+0x3b4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15182ULL;
	}
x86_l_13af:
	/* 0x13af: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_13b2:
	/* 0x13b2: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13b7:
	/* 0x13b7: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_13ba:
	/* 0x13ba: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_13bd:
	/* 0x13bd: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_13c0:
	/* 0x13c0: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13c6:
	/* 0x13c6: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13cb:
	/* 0x13cb: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13cf:
	/* 0x13cf: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_13d1:
	/* 0x13d1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_13d6:
	/* 0x13d6: jmp    1bfb <generic_rawtp_process_event+0x1bfb> */
	return 7163ULL;
x86_l_13db:
	/* 0x13db: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_13df:
	/* 0x13df: je     1ff4 <generic_rawtp_process_event+0x1ff4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8180ULL;
	}
x86_l_13e5:
	/* 0x13e5: cmp    r12d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 41ULL);
x86_l_13e9:
	/* 0x13e9: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_13ee:
	/* 0x13ee: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13f3:
	/* 0x13f3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13f8:
	/* 0x13f8: jne    2f0c <generic_rawtp_process_event+0x2f0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12044ULL;
	}
x86_l_13fe:
	/* 0x13fe: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1401:
	/* 0x1401: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1406:
	/* 0x1406: add    rdx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_140a:
	/* 0x140a: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_140f:
	/* 0x140f: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_1415:
	/* 0x1415: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_141a:
	/* 0x141a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_141f:
	/* 0x141f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1424:
	/* 0x1424: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1426:
	/* 0x1426: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_142b:
	/* 0x142b: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_142e:
	/* 0x142e: je     2676 <generic_rawtp_process_event+0x2676> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9846ULL;
	}
x86_l_1434:
	/* 0x1434: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1439:
	/* 0x1439: mov    QWORD PTR [rbp+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_143d:
	/* 0x143d: lea    rdi,[rbp+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_1441:
	/* 0x1441: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1445:
	/* 0x1445: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_144a:
	/* 0x144a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_144f:
	/* 0x144f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1454:
	/* 0x1454: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1456:
	/* 0x1456: lea    rdi,[rbp+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_145a:
	/* 0x145a: lea    rdx,[r15+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_145e:
	/* 0x145e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1463:
	/* 0x1463: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1468:
	/* 0x1468: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_146d:
	/* 0x146d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_146f:
	/* 0x146f: lea    rdi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1473:
	/* 0x1473: lea    rdx,[r15+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_147a:
	/* 0x147a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_147f:
	/* 0x147f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1484:
	/* 0x1484: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1489:
	/* 0x1489: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_148b:
	/* 0x148b: lea    rdi,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_148f:
	/* 0x148f: lea    rdx,[r15+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_1496:
	/* 0x1496: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_149b:
	/* 0x149b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14a0:
	/* 0x14a0: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_14a5:
	/* 0x14a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14a7:
	/* 0x14a7: lea    rdi,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14ab:
	/* 0x14ab: lea    rdx,[r15+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_14b2:
	/* 0x14b2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14b7:
	/* 0x14b7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14bc:
	/* 0x14bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14be:
	/* 0x14be: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_14c2:
	/* 0x14c2: lea    rdx,[r15+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_14c9:
	/* 0x14c9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14ce:
	/* 0x14ce: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14d3:
	/* 0x14d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d5:
	/* 0x14d5: lea    r12,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14d9:
	/* 0x14d9: mov    QWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14e1:
	/* 0x14e1: mov    QWORD PTR [rbp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_14e9:
	/* 0x14e9: mov    QWORD PTR [rbp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_14f1:
	/* 0x14f1: mov    QWORD PTR [rbp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_14f9:
	/* 0x14f9: movzx  eax,WORD PTR [rbp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_14fd:
	/* 0x14fd: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1500:
	/* 0x1500: je     25fd <generic_rawtp_process_event+0x25fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9725ULL;
	}
x86_l_1506:
	/* 0x1506: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1509:
	/* 0x1509: jne    262f <generic_rawtp_process_event+0x262f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9775ULL;
	}
x86_l_150f:
	/* 0x150f: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1513:
	/* 0x1513: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
	return 5400ULL;
}

static __noinline __u64 tetragon_bpf_generic_rawtp_generic_rawtp_process_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5400ULL: goto x86_l_1518;
	case 5405ULL: goto x86_l_151d;
	case 5410ULL: goto x86_l_1522;
	case 5415ULL: goto x86_l_1527;
	case 5417ULL: goto x86_l_1529;
	case 5422ULL: goto x86_l_152e;
	case 5427ULL: goto x86_l_1533;
	case 5430ULL: goto x86_l_1536;
	case 5435ULL: goto x86_l_153b;
	case 5438ULL: goto x86_l_153e;
	case 5443ULL: goto x86_l_1543;
	case 5447ULL: goto x86_l_1547;
	case 5453ULL: goto x86_l_154d;
	case 5457ULL: goto x86_l_1551;
	case 5462ULL: goto x86_l_1556;
	case 5467ULL: goto x86_l_155b;
	case 5472ULL: goto x86_l_1560;
	case 5477ULL: goto x86_l_1565;
	case 5483ULL: goto x86_l_156b;
	case 5486ULL: goto x86_l_156e;
	case 5494ULL: goto x86_l_1576;
	case 5502ULL: goto x86_l_157e;
	case 5510ULL: goto x86_l_1586;
	case 5518ULL: goto x86_l_158e;
	case 5526ULL: goto x86_l_1596;
	case 5534ULL: goto x86_l_159e;
	case 5542ULL: goto x86_l_15a6;
	case 5550ULL: goto x86_l_15ae;
	case 5558ULL: goto x86_l_15b6;
	case 5565ULL: goto x86_l_15bd;
	case 5569ULL: goto x86_l_15c1;
	case 5574ULL: goto x86_l_15c6;
	case 5578ULL: goto x86_l_15ca;
	case 5583ULL: goto x86_l_15cf;
	case 5588ULL: goto x86_l_15d4;
	case 5593ULL: goto x86_l_15d9;
	case 5595ULL: goto x86_l_15db;
	case 5598ULL: goto x86_l_15de;
	case 5604ULL: goto x86_l_15e4;
	case 5609ULL: goto x86_l_15e9;
	case 5613ULL: goto x86_l_15ed;
	case 5618ULL: goto x86_l_15f2;
	case 5625ULL: goto x86_l_15f9;
	case 5630ULL: goto x86_l_15fe;
	case 5635ULL: goto x86_l_1603;
	case 5640ULL: goto x86_l_1608;
	case 5642ULL: goto x86_l_160a;
	case 5648ULL: goto x86_l_1610;
	case 5651ULL: goto x86_l_1613;
	case 5656ULL: goto x86_l_1618;
	case 5660ULL: goto x86_l_161c;
	case 5665ULL: goto x86_l_1621;
	case 5670ULL: goto x86_l_1626;
	case 5675ULL: goto x86_l_162b;
	case 5680ULL: goto x86_l_1630;
	case 5682ULL: goto x86_l_1632;
	case 5687ULL: goto x86_l_1637;
	case 5692ULL: goto x86_l_163c;
	case 5698ULL: goto x86_l_1642;
	case 5702ULL: goto x86_l_1646;
	case 5707ULL: goto x86_l_164b;
	case 5712ULL: goto x86_l_1650;
	case 5717ULL: goto x86_l_1655;
	case 5722ULL: goto x86_l_165a;
	case 5725ULL: goto x86_l_165d;
	case 5727ULL: goto x86_l_165f;
	case 5732ULL: goto x86_l_1664;
	case 5737ULL: goto x86_l_1669;
	case 5741ULL: goto x86_l_166d;
	case 5746ULL: goto x86_l_1672;
	case 5751ULL: goto x86_l_1677;
	case 5756ULL: goto x86_l_167c;
	case 5758ULL: goto x86_l_167e;
	case 5763ULL: goto x86_l_1683;
	case 5769ULL: goto x86_l_1689;
	case 5777ULL: goto x86_l_1691;
	case 5782ULL: goto x86_l_1696;
	case 5787ULL: goto x86_l_169b;
	case 5792ULL: goto x86_l_16a0;
	case 5794ULL: goto x86_l_16a2;
	case 5802ULL: goto x86_l_16aa;
	case 5808ULL: goto x86_l_16b0;
	case 5813ULL: goto x86_l_16b5;
	case 5818ULL: goto x86_l_16ba;
	case 5823ULL: goto x86_l_16bf;
	case 5828ULL: goto x86_l_16c4;
	case 5833ULL: goto x86_l_16c9;
	case 5836ULL: goto x86_l_16cc;
	case 5838ULL: goto x86_l_16ce;
	case 5843ULL: goto x86_l_16d3;
	case 5849ULL: goto x86_l_16d9;
	case 5857ULL: goto x86_l_16e1;
	case 5862ULL: goto x86_l_16e6;
	case 5867ULL: goto x86_l_16eb;
	case 5872ULL: goto x86_l_16f0;
	case 5875ULL: goto x86_l_16f3;
	case 5877ULL: goto x86_l_16f5;
	case 5881ULL: goto x86_l_16f9;
	case 5886ULL: goto x86_l_16fe;
	case 5891ULL: goto x86_l_1703;
	case 5896ULL: goto x86_l_1708;
	case 5901ULL: goto x86_l_170d;
	case 5904ULL: goto x86_l_1710;
	case 5906ULL: goto x86_l_1712;
	case 5911ULL: goto x86_l_1717;
	case 5916ULL: goto x86_l_171c;
	case 5920ULL: goto x86_l_1720;
	case 5923ULL: goto x86_l_1723;
	case 5928ULL: goto x86_l_1728;
	case 5930ULL: goto x86_l_172a;
	case 5932ULL: goto x86_l_172c;
	case 5935ULL: goto x86_l_172f;
	case 5938ULL: goto x86_l_1732;
	case 5943ULL: goto x86_l_1737;
	case 5945ULL: goto x86_l_1739;
	case 5948ULL: goto x86_l_173c;
	case 5952ULL: goto x86_l_1740;
	case 5954ULL: goto x86_l_1742;
	case 5958ULL: goto x86_l_1746;
	case 5960ULL: goto x86_l_1748;
	case 5963ULL: goto x86_l_174b;
	case 5965ULL: goto x86_l_174d;
	case 5969ULL: goto x86_l_1751;
	case 5972ULL: goto x86_l_1754;
	case 5978ULL: goto x86_l_175a;
	case 5984ULL: goto x86_l_1760;
	case 5990ULL: goto x86_l_1766;
	case 5993ULL: goto x86_l_1769;
	case 5995ULL: goto x86_l_176b;
	case 6000ULL: goto x86_l_1770;
	case 6002ULL: goto x86_l_1772;
	case 6005ULL: goto x86_l_1775;
	case 6009ULL: goto x86_l_1779;
	case 6012ULL: goto x86_l_177c;
	case 6015ULL: goto x86_l_177f;
	case 6018ULL: goto x86_l_1782;
	case 6023ULL: goto x86_l_1787;
	case 6025ULL: goto x86_l_1789;
	case 6030ULL: goto x86_l_178e;
	case 6033ULL: goto x86_l_1791;
	case 6039ULL: goto x86_l_1797;
	case 6047ULL: goto x86_l_179f;
	case 6052ULL: goto x86_l_17a4;
	case 6057ULL: goto x86_l_17a9;
	case 6062ULL: goto x86_l_17ae;
	case 6067ULL: goto x86_l_17b3;
	case 6071ULL: goto x86_l_17b7;
	case 6077ULL: goto x86_l_17bd;
	case 6081ULL: goto x86_l_17c1;
	case 6086ULL: goto x86_l_17c6;
	case 6091ULL: goto x86_l_17cb;
	case 6096ULL: goto x86_l_17d0;
	case 6101ULL: goto x86_l_17d5;
	case 6107ULL: goto x86_l_17db;
	case 6110ULL: goto x86_l_17de;
	case 6117ULL: goto x86_l_17e5;
	case 6120ULL: goto x86_l_17e8;
	case 6125ULL: goto x86_l_17ed;
	case 6130ULL: goto x86_l_17f2;
	case 6133ULL: goto x86_l_17f5;
	case 6135ULL: goto x86_l_17f7;
	case 6140ULL: goto x86_l_17fc;
	case 6145ULL: goto x86_l_1801;
	case 6148ULL: goto x86_l_1804;
	case 6151ULL: goto x86_l_1807;
	case 6156ULL: goto x86_l_180c;
	case 6160ULL: goto x86_l_1810;
	case 6166ULL: goto x86_l_1816;
	case 6170ULL: goto x86_l_181a;
	case 6175ULL: goto x86_l_181f;
	case 6180ULL: goto x86_l_1824;
	case 6185ULL: goto x86_l_1829;
	case 6190ULL: goto x86_l_182e;
	case 6196ULL: goto x86_l_1834;
	case 6205ULL: goto x86_l_183d;
	case 6210ULL: goto x86_l_1842;
	case 6217ULL: goto x86_l_1849;
	case 6222ULL: goto x86_l_184e;
	case 6227ULL: goto x86_l_1853;
	case 6230ULL: goto x86_l_1856;
	case 6235ULL: goto x86_l_185b;
	case 6242ULL: goto x86_l_1862;
	case 6247ULL: goto x86_l_1867;
	case 6249ULL: goto x86_l_1869;
	case 6254ULL: goto x86_l_186e;
	case 6259ULL: goto x86_l_1873;
	case 6264ULL: goto x86_l_1878;
	case 6269ULL: goto x86_l_187d;
	case 6272ULL: goto x86_l_1880;
	case 6277ULL: goto x86_l_1885;
	case 6279ULL: goto x86_l_1887;
	case 6286ULL: goto x86_l_188e;
	case 6291ULL: goto x86_l_1893;
	case 6296ULL: goto x86_l_1898;
	case 6301ULL: goto x86_l_189d;
	case 6304ULL: goto x86_l_18a0;
	case 6306ULL: goto x86_l_18a2;
	case 6313ULL: goto x86_l_18a9;
	case 6320ULL: goto x86_l_18b0;
	case 6325ULL: goto x86_l_18b5;
	case 6330ULL: goto x86_l_18ba;
	case 6335ULL: goto x86_l_18bf;
	case 6337ULL: goto x86_l_18c1;
	case 6344ULL: goto x86_l_18c8;
	case 6351ULL: goto x86_l_18cf;
	case 6356ULL: goto x86_l_18d4;
	case 6361ULL: goto x86_l_18d9;
	case 6364ULL: goto x86_l_18dc;
	case 6369ULL: goto x86_l_18e1;
	case 6372ULL: goto x86_l_18e4;
	case 6374ULL: goto x86_l_18e6;
	case 6379ULL: goto x86_l_18eb;
	case 6384ULL: goto x86_l_18f0;
	case 6387ULL: goto x86_l_18f3;
	case 6393ULL: goto x86_l_18f9;
	case 6398ULL: goto x86_l_18fe;
	case 6403ULL: goto x86_l_1903;
	case 6408ULL: goto x86_l_1908;
	case 6412ULL: goto x86_l_190c;
	case 6419ULL: goto x86_l_1913;
	case 6424ULL: goto x86_l_1918;
	case 6429ULL: goto x86_l_191d;
	case 6434ULL: goto x86_l_1922;
	case 6436ULL: goto x86_l_1924;
	case 6440ULL: goto x86_l_1928;
	case 6444ULL: goto x86_l_192c;
	case 6449ULL: goto x86_l_1931;
	case 6454ULL: goto x86_l_1936;
	case 6459ULL: goto x86_l_193b;
	case 6461ULL: goto x86_l_193d;
	case 6465ULL: goto x86_l_1941;
	case 6472ULL: goto x86_l_1948;
	case 6477ULL: goto x86_l_194d;
	case 6482ULL: goto x86_l_1952;
	case 6487ULL: goto x86_l_1957;
	case 6489ULL: goto x86_l_1959;
	case 6493ULL: goto x86_l_195d;
	case 6500ULL: goto x86_l_1964;
	case 6505ULL: goto x86_l_1969;
	case 6510ULL: goto x86_l_196e;
	case 6515ULL: goto x86_l_1973;
	case 6517ULL: goto x86_l_1975;
	case 6526ULL: goto x86_l_197e;
	case 6533ULL: goto x86_l_1985;
	case 6538ULL: goto x86_l_198a;
	case 6543ULL: goto x86_l_198f;
	case 6548ULL: goto x86_l_1994;
	case 6553ULL: goto x86_l_1999;
	case 6555ULL: goto x86_l_199b;
	case 6562ULL: goto x86_l_19a2;
	case 6570ULL: goto x86_l_19aa;
	case 6575ULL: goto x86_l_19af;
	case 6580ULL: goto x86_l_19b4;
	case 6585ULL: goto x86_l_19b9;
	case 6587ULL: goto x86_l_19bb;
	case 6596ULL: goto x86_l_19c4;
	case 6601ULL: goto x86_l_19c9;
	case 6609ULL: goto x86_l_19d1;
	case 6614ULL: goto x86_l_19d6;
	case 6619ULL: goto x86_l_19db;
	case 6624ULL: goto x86_l_19e0;
	case 6627ULL: goto x86_l_19e3;
	case 6629ULL: goto x86_l_19e5;
	case 6637ULL: goto x86_l_19ed;
	case 6640ULL: goto x86_l_19f0;
	case 6643ULL: goto x86_l_19f3;
	case 6649ULL: goto x86_l_19f9;
	case 6652ULL: goto x86_l_19fc;
	case 6658ULL: goto x86_l_1a02;
	case 6662ULL: goto x86_l_1a06;
	case 6670ULL: goto x86_l_1a0e;
	case 6675ULL: goto x86_l_1a13;
	case 6680ULL: goto x86_l_1a18;
	case 6685ULL: goto x86_l_1a1d;
	case 6687ULL: goto x86_l_1a1f;
	case 6695ULL: goto x86_l_1a27;
	case 6700ULL: goto x86_l_1a2c;
	case 6704ULL: goto x86_l_1a30;
	case 6710ULL: goto x86_l_1a36;
	case 6714ULL: goto x86_l_1a3a;
	case 6721ULL: goto x86_l_1a41;
	case 6729ULL: goto x86_l_1a49;
	case 6737ULL: goto x86_l_1a51;
	case 6745ULL: goto x86_l_1a59;
	case 6750ULL: goto x86_l_1a5e;
	case 6755ULL: goto x86_l_1a63;
	case 6759ULL: goto x86_l_1a67;
	case 6764ULL: goto x86_l_1a6c;
	case 6766ULL: goto x86_l_1a6e;
	case 6770ULL: goto x86_l_1a72;
	case 6775ULL: goto x86_l_1a77;
	case 6780ULL: goto x86_l_1a7c;
	case 6783ULL: goto x86_l_1a7f;
	case 6788ULL: goto x86_l_1a84;
	case 6791ULL: goto x86_l_1a87;
	case 6793ULL: goto x86_l_1a89;
	case 6800ULL: goto x86_l_1a90;
	case 6808ULL: goto x86_l_1a98;
	case 6813ULL: goto x86_l_1a9d;
	case 6818ULL: goto x86_l_1aa2;
	case 6823ULL: goto x86_l_1aa7;
	case 6825ULL: goto x86_l_1aa9;
	case 6834ULL: goto x86_l_1ab2;
	case 6839ULL: goto x86_l_1ab7;
	case 6848ULL: goto x86_l_1ac0;
	case 6853ULL: goto x86_l_1ac5;
	case 6855ULL: goto x86_l_1ac7;
	case 6859ULL: goto x86_l_1acb;
	case 6864ULL: goto x86_l_1ad0;
	case 6869ULL: goto x86_l_1ad5;
	case 6874ULL: goto x86_l_1ada;
	case 6879ULL: goto x86_l_1adf;
	case 6884ULL: goto x86_l_1ae4;
	case 6889ULL: goto x86_l_1ae9;
	case 6891ULL: goto x86_l_1aeb;
	case 6895ULL: goto x86_l_1aef;
	case 6899ULL: goto x86_l_1af3;
	case 6906ULL: goto x86_l_1afa;
	case 6911ULL: goto x86_l_1aff;
	case 6916ULL: goto x86_l_1b04;
	case 6918ULL: goto x86_l_1b06;
	case 6921ULL: goto x86_l_1b09;
	case 6927ULL: goto x86_l_1b0f;
	case 6930ULL: goto x86_l_1b12;
	case 6935ULL: goto x86_l_1b17;
	case 6938ULL: goto x86_l_1b1a;
	case 6943ULL: goto x86_l_1b1f;
	case 6948ULL: goto x86_l_1b24;
	case 6954ULL: goto x86_l_1b2a;
	case 6957ULL: goto x86_l_1b2d;
	case 6962ULL: goto x86_l_1b32;
	case 6964ULL: goto x86_l_1b34;
	case 6971ULL: goto x86_l_1b3b;
	case 6975ULL: goto x86_l_1b3f;
	case 6979ULL: goto x86_l_1b43;
	case 6984ULL: goto x86_l_1b48;
	case 6987ULL: goto x86_l_1b4b;
	case 6989ULL: goto x86_l_1b4d;
	case 6993ULL: goto x86_l_1b51;
	case 6997ULL: goto x86_l_1b55;
	case 7001ULL: goto x86_l_1b59;
	case 7005ULL: goto x86_l_1b5d;
	case 7010ULL: goto x86_l_1b62;
	case 7015ULL: goto x86_l_1b67;
	case 7017ULL: goto x86_l_1b69;
	case 7021ULL: goto x86_l_1b6d;
	case 7026ULL: goto x86_l_1b72;
	case 7031ULL: goto x86_l_1b77;
	case 7036ULL: goto x86_l_1b7c;
	case 7041ULL: goto x86_l_1b81;
	case 7044ULL: goto x86_l_1b84;
	case 7049ULL: goto x86_l_1b89;
	case 7054ULL: goto x86_l_1b8e;
	case 7057ULL: goto x86_l_1b91;
	case 7059ULL: goto x86_l_1b93;
	case 7064ULL: goto x86_l_1b98;
	case 7069ULL: goto x86_l_1b9d;
	case 7074ULL: goto x86_l_1ba2;
	case 7079ULL: goto x86_l_1ba7;
	case 7082ULL: goto x86_l_1baa;
	case 7087ULL: goto x86_l_1baf;
	case 7089ULL: goto x86_l_1bb1;
	case 7092ULL: goto x86_l_1bb4;
	case 7095ULL: goto x86_l_1bb7;
	case 7100ULL: goto x86_l_1bbc;
	case 7105ULL: goto x86_l_1bc1;
	case 7109ULL: goto x86_l_1bc5;
	case 7114ULL: goto x86_l_1bca;
	case 7119ULL: goto x86_l_1bcf;
	case 7124ULL: goto x86_l_1bd4;
	case 7126ULL: goto x86_l_1bd6;
	case 7129ULL: goto x86_l_1bd9;
	case 7134ULL: goto x86_l_1bde;
	case 7139ULL: goto x86_l_1be3;
	case 7144ULL: goto x86_l_1be8;
	case 7148ULL: goto x86_l_1bec;
	case 7153ULL: goto x86_l_1bf1;
	case 7158ULL: goto x86_l_1bf6;
	case 7163ULL: goto x86_l_1bfb;
	case 7165ULL: goto x86_l_1bfd;
	case 7168ULL: goto x86_l_1c00;
	case 7171ULL: goto x86_l_1c03;
	case 7177ULL: goto x86_l_1c09;
	case 7181ULL: goto x86_l_1c0d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1518:
	/* 0x1518: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_151d:
	/* 0x151d: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1522:
	/* 0x1522: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1527:
	/* 0x1527: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1529:
	/* 0x1529: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_152e:
	/* 0x152e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1533:
	/* 0x1533: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1536:
	/* 0x1536: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_153b:
	/* 0x153b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_153e:
	/* 0x153e: jmp    262d <generic_rawtp_process_event+0x262d> */
	return 9773ULL;
x86_l_1543:
	/* 0x1543: cmp    r12d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 26ULL);
x86_l_1547:
	/* 0x1547: je     2097 <generic_rawtp_process_event+0x2097> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8343ULL;
	}
x86_l_154d:
	/* 0x154d: cmp    r12d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 27ULL);
x86_l_1551:
	/* 0x1551: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1556:
	/* 0x1556: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_155b:
	/* 0x155b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1560:
	/* 0x1560: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1565:
	/* 0x1565: jne    2f0c <generic_rawtp_process_event+0x2f0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12044ULL;
	}
x86_l_156b:
	/* 0x156b: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_156e:
	/* 0x156e: mov    QWORD PTR [rcx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1576:
	/* 0x1576: mov    QWORD PTR [rcx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_157e:
	/* 0x157e: mov    QWORD PTR [rcx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1586:
	/* 0x1586: mov    QWORD PTR [rcx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_158e:
	/* 0x158e: mov    QWORD PTR [rcx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1596:
	/* 0x1596: mov    QWORD PTR [rcx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_159e:
	/* 0x159e: mov    QWORD PTR [rcx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_15a6:
	/* 0x15a6: mov    QWORD PTR [rcx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_15ae:
	/* 0x15ae: mov    QWORD PTR [rcx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_15b6:
	/* 0x15b6: mov    QWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15bd:
	/* 0x15bd: lea    rdi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15c1:
	/* 0x15c1: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15c6:
	/* 0x15c6: lea    rdx,[rax+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15ca:
	/* 0x15ca: mov    ecx,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 63ULL);
x86_l_15cf:
	/* 0x15cf: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_15d4:
	/* 0x15d4: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_15d9:
	/* 0x15d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15db:
	/* 0x15db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15de:
	/* 0x15de: js     25d2 <generic_rawtp_process_event+0x25d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9682ULL;
	}
x86_l_15e4:
	/* 0x15e4: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15e9:
	/* 0x15e9: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_15ed:
	/* 0x15ed: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15f2:
	/* 0x15f2: add    rdx,0x348 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 840ULL);
x86_l_15f9:
	/* 0x15f9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_15fe:
	/* 0x15fe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1603:
	/* 0x1603: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1608:
	/* 0x1608: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_160a:
	/* 0x160a: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_1610:
	/* 0x1610: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1613:
	/* 0x1613: jmp    2f02 <generic_rawtp_process_event+0x2f02> */
	return 12034ULL;
x86_l_1618:
	/* 0x1618: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_161c:
	/* 0x161c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1621:
	/* 0x1621: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1626:
	/* 0x1626: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_162b:
	/* 0x162b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1630:
	/* 0x1630: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1632:
	/* 0x1632: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1637:
	/* 0x1637: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_163c:
	/* 0x163c: je     974 <generic_rawtp_process_event+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2420ULL;
	}
x86_l_1642:
	/* 0x1642: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1646:
	/* 0x1646: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_164b:
	/* 0x164b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1650:
	/* 0x1650: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1655:
	/* 0x1655: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_165a:
	/* 0x165a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_165d:
	/* 0x165d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_165f:
	/* 0x165f: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1664:
	/* 0x1664: mov    QWORD PTR [rsp+0x50],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1669:
	/* 0x1669: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_166d:
	/* 0x166d: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1672:
	/* 0x1672: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1677:
	/* 0x1677: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_167c:
	/* 0x167c: jne    1689 <generic_rawtp_process_event+0x1689> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1689;
	}
x86_l_167e:
	/* 0x167e: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_1683:
	/* 0x1683: je     974 <generic_rawtp_process_event+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2420ULL;
	}
x86_l_1689:
	/* 0x1689: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1691:
	/* 0x1691: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1696:
	/* 0x1696: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_169b:
	/* 0x169b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16a0:
	/* 0x16a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16a2:
	/* 0x16a2: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_16aa:
	/* 0x16aa: je     22fe <generic_rawtp_process_event+0x22fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8958ULL;
	}
x86_l_16b0:
	/* 0x16b0: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16b5:
	/* 0x16b5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16ba:
	/* 0x16ba: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16bf:
	/* 0x16bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16c4:
	/* 0x16c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16c9:
	/* 0x16c9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_16cc:
	/* 0x16cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ce:
	/* 0x16ce: cmp    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16d3:
	/* 0x16d3: je     22fe <generic_rawtp_process_event+0x22fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8958ULL;
	}
x86_l_16d9:
	/* 0x16d9: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_16e1:
	/* 0x16e1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16e6:
	/* 0x16e6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16eb:
	/* 0x16eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16f0:
	/* 0x16f0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_16f3:
	/* 0x16f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16f5:
	/* 0x16f5: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_16f9:
	/* 0x16f9: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_16fe:
	/* 0x16fe: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1703:
	/* 0x1703: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1708:
	/* 0x1708: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_170d:
	/* 0x170d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1710:
	/* 0x1710: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1712:
	/* 0x1712: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1717:
	/* 0x1717: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_171c:
	/* 0x171c: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_1720:
	/* 0x1720: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1723:
	/* 0x1723: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1728:
	/* 0x1728: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_172a:
	/* 0x172a: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_172c:
	/* 0x172c: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_172f:
	/* 0x172f: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1732:
	/* 0x1732: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_1737:
	/* 0x1737: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1739:
	/* 0x1739: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_173c:
	/* 0x173c: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_1740:
	/* 0x1740: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1742:
	/* 0x1742: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_1746:
	/* 0x1746: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1748:
	/* 0x1748: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_174b:
	/* 0x174b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_174d:
	/* 0x174d: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1751:
	/* 0x1751: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1754:
	/* 0x1754: jb     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2425ULL;
	}
x86_l_175a:
	/* 0x175a: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_1760:
	/* 0x1760: ja     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2425ULL;
	}
x86_l_1766:
	/* 0x1766: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1769:
	/* 0x1769: jbe    1770 <generic_rawtp_process_event+0x1770> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1770;
	}
x86_l_176b:
	/* 0x176b: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_1770:
	/* 0x1770: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1772:
	/* 0x1772: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1775:
	/* 0x1775: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_1779:
	/* 0x1779: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_177c:
	/* 0x177c: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_177f:
	/* 0x177f: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1782:
	/* 0x1782: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1787:
	/* 0x1787: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1789:
	/* 0x1789: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_178e:
	/* 0x178e: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1791:
	/* 0x1791: jbe    979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2425ULL;
	}
x86_l_1797:
	/* 0x1797: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_179f:
	/* 0x179f: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_17a4:
	/* 0x17a4: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17a9:
	/* 0x17a9: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_17ae:
	/* 0x17ae: jmp    235d <generic_rawtp_process_event+0x235d> */
	return 9053ULL;
x86_l_17b3:
	/* 0x17b3: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_17b7:
	/* 0x17b7: je     1c77 <generic_rawtp_process_event+0x1c77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7287ULL;
	}
x86_l_17bd:
	/* 0x17bd: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_17c1:
	/* 0x17c1: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_17c6:
	/* 0x17c6: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17cb:
	/* 0x17cb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17d0:
	/* 0x17d0: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17d5:
	/* 0x17d5: jne    2f0c <generic_rawtp_process_event+0x2f0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12044ULL;
	}
x86_l_17db:
	/* 0x17db: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_17de:
	/* 0x17de: and    r12d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_17e5:
	/* 0x17e5: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_17e8:
	/* 0x17e8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17ed:
	/* 0x17ed: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17f2:
	/* 0x17f2: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_17f5:
	/* 0x17f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f7:
	/* 0x17f7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17fc:
	/* 0x17fc: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1801:
	/* 0x1801: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_1804:
	/* 0x1804: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_1807:
	/* 0x1807: jmp    2f0c <generic_rawtp_process_event+0x2f0c> */
	return 12044ULL;
x86_l_180c:
	/* 0x180c: cmp    r12d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 19ULL);
x86_l_1810:
	/* 0x1810: je     1f97 <generic_rawtp_process_event+0x1f97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8087ULL;
	}
x86_l_1816:
	/* 0x1816: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_181a:
	/* 0x181a: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_181f:
	/* 0x181f: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1824:
	/* 0x1824: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1829:
	/* 0x1829: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_182e:
	/* 0x182e: jne    2f0c <generic_rawtp_process_event+0x2f0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12044ULL;
	}
x86_l_1834:
	/* 0x1834: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_183d:
	/* 0x183d: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1842:
	/* 0x1842: lea    rdx,[rbp+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_1849:
	/* 0x1849: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_184e:
	/* 0x184e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1853:
	/* 0x1853: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1856:
	/* 0x1856: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_185b:
	/* 0x185b: lea    r15,[rbp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1862:
	/* 0x1862: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1867:
	/* 0x1867: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1869:
	/* 0x1869: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_186e:
	/* 0x186e: mov    edx,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 128ULL);
x86_l_1873:
	/* 0x1873: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1878:
	/* 0x1878: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_187d:
	/* 0x187d: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1880:
	/* 0x1880: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_1885:
	/* 0x1885: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1887:
	/* 0x1887: lea    rdi,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_188e:
	/* 0x188e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1893:
	/* 0x1893: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1898:
	/* 0x1898: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_189d:
	/* 0x189d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_18a0:
	/* 0x18a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18a2:
	/* 0x18a2: lea    rdi,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_18a9:
	/* 0x18a9: lea    rdx,[rbp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_18b0:
	/* 0x18b0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_18b5:
	/* 0x18b5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18ba:
	/* 0x18ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18bf:
	/* 0x18bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c1:
	/* 0x18c1: add    r13,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_18c8:
	/* 0x18c8: add    rbp,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_18cf:
	/* 0x18cf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_18d4:
	/* 0x18d4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18d9:
	/* 0x18d9: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_18dc:
	/* 0x18dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18e1:
	/* 0x18e1: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_18e4:
	/* 0x18e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e6:
	/* 0x18e6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18eb:
	/* 0x18eb: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18f0:
	/* 0x18f0: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_18f3:
	/* 0x18f3: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_18f9:
	/* 0x18f9: jmp    2f0c <generic_rawtp_process_event+0x2f0c> */
	return 12044ULL;
x86_l_18fe:
	/* 0x18fe: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1903:
	/* 0x1903: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1908:
	/* 0x1908: lea    rdi,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_190c:
	/* 0x190c: lea    rdx,[r13+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1913:
	/* 0x1913: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1918:
	/* 0x1918: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_191d:
	/* 0x191d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1922:
	/* 0x1922: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1924:
	/* 0x1924: lea    rdi,[r15+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1928:
	/* 0x1928: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_192c:
	/* 0x192c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1931:
	/* 0x1931: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1936:
	/* 0x1936: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_193b:
	/* 0x193b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_193d:
	/* 0x193d: lea    rdi,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1941:
	/* 0x1941: lea    rdx,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1948:
	/* 0x1948: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_194d:
	/* 0x194d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1952:
	/* 0x1952: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1957:
	/* 0x1957: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1959:
	/* 0x1959: lea    rdi,[r15+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_195d:
	/* 0x195d: lea    rdx,[r13+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1964:
	/* 0x1964: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
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
	/* 0x1975: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_197e:
	/* 0x197e: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1985:
	/* 0x1985: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_198a:
	/* 0x198a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_198f:
	/* 0x198f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1994:
	/* 0x1994: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1999:
	/* 0x1999: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_199b:
	/* 0x199b: lea    rdx,[r13+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_19a2:
	/* 0x19a2: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_19aa:
	/* 0x19aa: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_19af:
	/* 0x19af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19b4:
	/* 0x19b4: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_19b9:
	/* 0x19b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19bb:
	/* 0x19bb: movzx  r15d,WORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 128ULL);
x86_l_19c4:
	/* 0x19c4: add    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_19c9:
	/* 0x19c9: lea    rdi,[rsp+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_19d1:
	/* 0x19d1: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_19d6:
	/* 0x19d6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19db:
	/* 0x19db: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_19e0:
	/* 0x19e0: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_19e3:
	/* 0x19e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e5:
	/* 0x19e5: movzx  eax,BYTE PTR [rsp+0xd4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 212ULL);
x86_l_19ed:
	/* 0x19ed: shr    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_19f0:
	/* 0x19f0: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_19f3:
	/* 0x19f3: je     2123 <generic_rawtp_process_event+0x2123> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8483ULL;
	}
x86_l_19f9:
	/* 0x19f9: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19fc:
	/* 0x19fc: jne    3b31 <generic_rawtp_process_event+0x3b31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15153ULL;
	}
x86_l_1a02:
	/* 0x1a02: lea    rdx,[r15+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_1a06:
	/* 0x1a06: lea    rdi,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1a0e:
	/* 0x1a0e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1a13:
	/* 0x1a13: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a18:
	/* 0x1a18: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1a1d:
	/* 0x1a1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a1f:
	/* 0x1a1f: movzx  eax,BYTE PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 216ULL);
x86_l_1a27:
	/* 0x1a27: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a2c:
	/* 0x1a2c: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a30:
	/* 0x1a30: mov    WORD PTR [rdi+0x26],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757250ULL);
x86_l_1a36:
	/* 0x1a36: lea    rdx,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1a3a:
	/* 0x1a3a: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a41:
	/* 0x1a41: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1a49:
	/* 0x1a49: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1a51:
	/* 0x1a51: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1a59:
	/* 0x1a59: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a5e:
	/* 0x1a5e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a63:
	/* 0x1a63: lea    r12,[rdi+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a67:
	/* 0x1a67: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a6c:
	/* 0x1a6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a6e:
	/* 0x1a6e: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a72:
	/* 0x1a72: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a77:
	/* 0x1a77: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a7c:
	/* 0x1a7c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1a7f:
	/* 0x1a7f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a84:
	/* 0x1a84: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1a87:
	/* 0x1a87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a89:
	/* 0x1a89: lea    rdx,[r13+0xb6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_1a90:
	/* 0x1a90: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1a98:
	/* 0x1a98: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1a9d:
	/* 0x1a9d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1aa2:
	/* 0x1aa2: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1aa7:
	/* 0x1aa7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aa9:
	/* 0x1aa9: movzx  r12d,BYTE PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 216ULL);
x86_l_1ab2:
	/* 0x1ab2: jmp    39d8 <generic_rawtp_process_event+0x39d8> */
	return 14808ULL;
x86_l_1ab7:
	/* 0x1ab7: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1ac0:
	/* 0x1ac0: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1ac5:
	/* 0x1ac5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ac7:
	/* 0x1ac7: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1acb:
	/* 0x1acb: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ad0:
	/* 0x1ad0: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1ad5:
	/* 0x1ad5: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ada:
	/* 0x1ada: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1adf:
	/* 0x1adf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ae4:
	/* 0x1ae4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ae9:
	/* 0x1ae9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aeb:
	/* 0x1aeb: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1aef:
	/* 0x1aef: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1af3:
	/* 0x1af3: mov    rdi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1afa:
	/* 0x1afa: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1aff:
	/* 0x1aff: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b04:
	/* 0x1b04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b06:
	/* 0x1b06: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b09:
	/* 0x1b09: je     2117 <generic_rawtp_process_event+0x2117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8471ULL;
	}
x86_l_1b0f:
	/* 0x1b0f: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b12:
	/* 0x1b12: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1b17:
	/* 0x1b17: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1b1a:
	/* 0x1b1a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b1f:
	/* 0x1b1f: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b24:
	/* 0x1b24: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1b2a:
	/* 0x1b2a: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1b2d:
	/* 0x1b2d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b32:
	/* 0x1b32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b34:
	/* 0x1b34: and    r15d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1b3b:
	/* 0x1b3b: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b3f:
	/* 0x1b3f: lea    rsi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b43:
	/* 0x1b43: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b48:
	/* 0x1b48: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1b4b:
	/* 0x1b4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b4d:
	/* 0x1b4d: lea    rdi,[r15+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1b51:
	/* 0x1b51: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1b55:
	/* 0x1b55: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1b59:
	/* 0x1b59: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1b5d:
	/* 0x1b5d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b62:
	/* 0x1b62: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b67:
	/* 0x1b67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b69:
	/* 0x1b69: add    r15,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1b6d:
	/* 0x1b6d: jmp    3b37 <generic_rawtp_process_event+0x3b37> */
	return 15159ULL;
x86_l_1b72:
	/* 0x1b72: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b77:
	/* 0x1b77: lea    r15,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b7c:
	/* 0x1b7c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b81:
	/* 0x1b81: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1b84:
	/* 0x1b84: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b89:
	/* 0x1b89: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b8e:
	/* 0x1b8e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1b91:
	/* 0x1b91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b93:
	/* 0x1b93: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b98:
	/* 0x1b98: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b9d:
	/* 0x1b9d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ba2:
	/* 0x1ba2: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ba7:
	/* 0x1ba7: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1baa:
	/* 0x1baa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1baf:
	/* 0x1baf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bb1:
	/* 0x1bb1: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1bb4:
	/* 0x1bb4: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1bb7:
	/* 0x1bb7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bbc:
	/* 0x1bbc: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bc1:
	/* 0x1bc1: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1bc5:
	/* 0x1bc5: mov    ecx,0x91 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 145ULL);
x86_l_1bca:
	/* 0x1bca: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1bcf:
	/* 0x1bcf: mov    esi,0x91 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 145ULL);
x86_l_1bd4:
	/* 0x1bd4: jmp    1bfb <generic_rawtp_process_event+0x1bfb> */
	goto x86_l_1bfb;
x86_l_1bd6:
	/* 0x1bd6: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1bd9:
	/* 0x1bd9: mov    edx,0x120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 288ULL);
x86_l_1bde:
	/* 0x1bde: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1be3:
	/* 0x1be3: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1be8:
	/* 0x1be8: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1bec:
	/* 0x1bec: mov    ecx,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_1bf1:
	/* 0x1bf1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1bf6:
	/* 0x1bf6: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1bfb:
	/* 0x1bfb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bfd:
	/* 0x1bfd: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1c00:
	/* 0x1c00: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c03:
	/* 0x1c03: js     24f0 <generic_rawtp_process_event+0x24f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9456ULL;
	}
x86_l_1c09:
	/* 0x1c09: lea    eax,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1c0d:
	/* 0x1c0d: mov    DWORD PTR [r13+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 7185ULL;
}

static __noinline __u64 tetragon_bpf_generic_rawtp_generic_rawtp_process_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7185ULL: goto x86_l_1c11;
	case 7189ULL: goto x86_l_1c15;
	case 7194ULL: goto x86_l_1c1a;
	case 7197ULL: goto x86_l_1c1d;
	case 7200ULL: goto x86_l_1c20;
	case 7207ULL: goto x86_l_1c27;
	case 7219ULL: goto x86_l_1c33;
	case 7223ULL: goto x86_l_1c37;
	case 7229ULL: goto x86_l_1c3d;
	case 7233ULL: goto x86_l_1c41;
	case 7235ULL: goto x86_l_1c43;
	case 7239ULL: goto x86_l_1c47;
	case 7245ULL: goto x86_l_1c4d;
	case 7249ULL: goto x86_l_1c51;
	case 7255ULL: goto x86_l_1c57;
	case 7259ULL: goto x86_l_1c5b;
	case 7265ULL: goto x86_l_1c61;
	case 7269ULL: goto x86_l_1c65;
	case 7275ULL: goto x86_l_1c6b;
	case 7282ULL: goto x86_l_1c72;
	case 7287ULL: goto x86_l_1c77;
	case 7292ULL: goto x86_l_1c7c;
	case 7297ULL: goto x86_l_1c81;
	case 7302ULL: goto x86_l_1c86;
	case 7307ULL: goto x86_l_1c8b;
	case 7311ULL: goto x86_l_1c8f;
	case 7316ULL: goto x86_l_1c94;
	case 7321ULL: goto x86_l_1c99;
	case 7324ULL: goto x86_l_1c9c;
	case 7329ULL: goto x86_l_1ca1;
	case 7331ULL: goto x86_l_1ca3;
	case 7336ULL: goto x86_l_1ca8;
	case 7340ULL: goto x86_l_1cac;
	case 7345ULL: goto x86_l_1cb1;
	case 7350ULL: goto x86_l_1cb6;
	case 7355ULL: goto x86_l_1cbb;
	case 7357ULL: goto x86_l_1cbd;
	case 7362ULL: goto x86_l_1cc2;
	case 7366ULL: goto x86_l_1cc6;
	case 7371ULL: goto x86_l_1ccb;
	case 7376ULL: goto x86_l_1cd0;
	case 7381ULL: goto x86_l_1cd5;
	case 7383ULL: goto x86_l_1cd7;
	case 7388ULL: goto x86_l_1cdc;
	case 7392ULL: goto x86_l_1ce0;
	case 7397ULL: goto x86_l_1ce5;
	case 7402ULL: goto x86_l_1cea;
	case 7407ULL: goto x86_l_1cef;
	case 7409ULL: goto x86_l_1cf1;
	case 7414ULL: goto x86_l_1cf6;
	case 7418ULL: goto x86_l_1cfa;
	case 7423ULL: goto x86_l_1cff;
	case 7428ULL: goto x86_l_1d04;
	case 7433ULL: goto x86_l_1d09;
	case 7435ULL: goto x86_l_1d0b;
	case 7440ULL: goto x86_l_1d10;
	case 7444ULL: goto x86_l_1d14;
	case 7449ULL: goto x86_l_1d19;
	case 7454ULL: goto x86_l_1d1e;
	case 7459ULL: goto x86_l_1d23;
	case 7461ULL: goto x86_l_1d25;
	case 7466ULL: goto x86_l_1d2a;
	case 7470ULL: goto x86_l_1d2e;
	case 7475ULL: goto x86_l_1d33;
	case 7480ULL: goto x86_l_1d38;
	case 7485ULL: goto x86_l_1d3d;
	case 7487ULL: goto x86_l_1d3f;
	case 7492ULL: goto x86_l_1d44;
	case 7496ULL: goto x86_l_1d48;
	case 7501ULL: goto x86_l_1d4d;
	case 7506ULL: goto x86_l_1d52;
	case 7511ULL: goto x86_l_1d57;
	case 7513ULL: goto x86_l_1d59;
	case 7522ULL: goto x86_l_1d62;
	case 7527ULL: goto x86_l_1d67;
	case 7531ULL: goto x86_l_1d6b;
	case 7536ULL: goto x86_l_1d70;
	case 7541ULL: goto x86_l_1d75;
	case 7546ULL: goto x86_l_1d7a;
	case 7548ULL: goto x86_l_1d7c;
	case 7553ULL: goto x86_l_1d81;
	case 7557ULL: goto x86_l_1d85;
	case 7562ULL: goto x86_l_1d8a;
	case 7567ULL: goto x86_l_1d8f;
	case 7572ULL: goto x86_l_1d94;
	case 7574ULL: goto x86_l_1d96;
	case 7579ULL: goto x86_l_1d9b;
	case 7583ULL: goto x86_l_1d9f;
	case 7588ULL: goto x86_l_1da4;
	case 7593ULL: goto x86_l_1da9;
	case 7598ULL: goto x86_l_1dae;
	case 7600ULL: goto x86_l_1db0;
	case 7604ULL: goto x86_l_1db4;
	case 7609ULL: goto x86_l_1db9;
	case 7614ULL: goto x86_l_1dbe;
	case 7617ULL: goto x86_l_1dc1;
	case 7622ULL: goto x86_l_1dc6;
	case 7624ULL: goto x86_l_1dc8;
	case 7631ULL: goto x86_l_1dcf;
	case 7636ULL: goto x86_l_1dd4;
	case 7641ULL: goto x86_l_1dd9;
	case 7646ULL: goto x86_l_1dde;
	case 7651ULL: goto x86_l_1de3;
	case 7654ULL: goto x86_l_1de6;
	case 7656ULL: goto x86_l_1de8;
	case 7661ULL: goto x86_l_1ded;
	case 7668ULL: goto x86_l_1df4;
	case 7673ULL: goto x86_l_1df9;
	case 7678ULL: goto x86_l_1dfe;
	case 7681ULL: goto x86_l_1e01;
	case 7686ULL: goto x86_l_1e06;
	case 7688ULL: goto x86_l_1e08;
	case 7693ULL: goto x86_l_1e0d;
	case 7700ULL: goto x86_l_1e14;
	case 7705ULL: goto x86_l_1e19;
	case 7710ULL: goto x86_l_1e1e;
	case 7715ULL: goto x86_l_1e23;
	case 7717ULL: goto x86_l_1e25;
	case 7722ULL: goto x86_l_1e2a;
	case 7729ULL: goto x86_l_1e31;
	case 7734ULL: goto x86_l_1e36;
	case 7739ULL: goto x86_l_1e3b;
	case 7744ULL: goto x86_l_1e40;
	case 7746ULL: goto x86_l_1e42;
	case 7750ULL: goto x86_l_1e46;
	case 7757ULL: goto x86_l_1e4d;
	case 7762ULL: goto x86_l_1e52;
	case 7767ULL: goto x86_l_1e57;
	case 7770ULL: goto x86_l_1e5a;
	case 7775ULL: goto x86_l_1e5f;
	case 7778ULL: goto x86_l_1e62;
	case 7780ULL: goto x86_l_1e64;
	case 7786ULL: goto x86_l_1e6a;
	case 7791ULL: goto x86_l_1e6f;
	case 7796ULL: goto x86_l_1e74;
	case 7804ULL: goto x86_l_1e7c;
	case 7809ULL: goto x86_l_1e81;
	case 7814ULL: goto x86_l_1e86;
	case 7819ULL: goto x86_l_1e8b;
	case 7822ULL: goto x86_l_1e8e;
	case 7827ULL: goto x86_l_1e93;
	case 7829ULL: goto x86_l_1e95;
	case 7833ULL: goto x86_l_1e99;
	case 7841ULL: goto x86_l_1ea1;
	case 7846ULL: goto x86_l_1ea6;
	case 7851ULL: goto x86_l_1eab;
	case 7856ULL: goto x86_l_1eb0;
	case 7858ULL: goto x86_l_1eb2;
	case 7862ULL: goto x86_l_1eb6;
	case 7870ULL: goto x86_l_1ebe;
	case 7875ULL: goto x86_l_1ec3;
	case 7880ULL: goto x86_l_1ec8;
	case 7885ULL: goto x86_l_1ecd;
	case 7887ULL: goto x86_l_1ecf;
	case 7891ULL: goto x86_l_1ed3;
	case 7898ULL: goto x86_l_1eda;
	case 7903ULL: goto x86_l_1edf;
	case 7908ULL: goto x86_l_1ee4;
	case 7911ULL: goto x86_l_1ee7;
	case 7916ULL: goto x86_l_1eec;
	case 7919ULL: goto x86_l_1eef;
	case 7921ULL: goto x86_l_1ef1;
	case 7927ULL: goto x86_l_1ef7;
	case 7932ULL: goto x86_l_1efc;
	case 7937ULL: goto x86_l_1f01;
	case 7942ULL: goto x86_l_1f06;
	case 7947ULL: goto x86_l_1f0b;
	case 7952ULL: goto x86_l_1f10;
	case 7957ULL: goto x86_l_1f15;
	case 7960ULL: goto x86_l_1f18;
	case 7965ULL: goto x86_l_1f1d;
	case 7967ULL: goto x86_l_1f1f;
	case 7971ULL: goto x86_l_1f23;
	case 7976ULL: goto x86_l_1f28;
	case 7981ULL: goto x86_l_1f2d;
	case 7986ULL: goto x86_l_1f32;
	case 7991ULL: goto x86_l_1f37;
	case 7993ULL: goto x86_l_1f39;
	case 7997ULL: goto x86_l_1f3d;
	case 8002ULL: goto x86_l_1f42;
	case 8007ULL: goto x86_l_1f47;
	case 8012ULL: goto x86_l_1f4c;
	case 8017ULL: goto x86_l_1f51;
	case 8019ULL: goto x86_l_1f53;
	case 8023ULL: goto x86_l_1f57;
	case 8028ULL: goto x86_l_1f5c;
	case 8033ULL: goto x86_l_1f61;
	case 8038ULL: goto x86_l_1f66;
	case 8043ULL: goto x86_l_1f6b;
	case 8045ULL: goto x86_l_1f6d;
	case 8049ULL: goto x86_l_1f71;
	case 8053ULL: goto x86_l_1f75;
	case 8058ULL: goto x86_l_1f7a;
	case 8063ULL: goto x86_l_1f7f;
	case 8066ULL: goto x86_l_1f82;
	case 8071ULL: goto x86_l_1f87;
	case 8074ULL: goto x86_l_1f8a;
	case 8076ULL: goto x86_l_1f8c;
	case 8082ULL: goto x86_l_1f92;
	case 8087ULL: goto x86_l_1f97;
	case 8092ULL: goto x86_l_1f9c;
	case 8097ULL: goto x86_l_1fa1;
	case 8102ULL: goto x86_l_1fa6;
	case 8107ULL: goto x86_l_1fab;
	case 8110ULL: goto x86_l_1fae;
	case 8115ULL: goto x86_l_1fb3;
	case 8118ULL: goto x86_l_1fb6;
	case 8120ULL: goto x86_l_1fb8;
	case 8124ULL: goto x86_l_1fbc;
	case 8129ULL: goto x86_l_1fc1;
	case 8134ULL: goto x86_l_1fc6;
	case 8139ULL: goto x86_l_1fcb;
	case 8144ULL: goto x86_l_1fd0;
	case 8146ULL: goto x86_l_1fd2;
	case 8150ULL: goto x86_l_1fd6;
	case 8154ULL: goto x86_l_1fda;
	case 8159ULL: goto x86_l_1fdf;
	case 8164ULL: goto x86_l_1fe4;
	case 8167ULL: goto x86_l_1fe7;
	case 8172ULL: goto x86_l_1fec;
	case 8175ULL: goto x86_l_1fef;
	case 8180ULL: goto x86_l_1ff4;
	case 8183ULL: goto x86_l_1ff7;
	case 8188ULL: goto x86_l_1ffc;
	case 8193ULL: goto x86_l_2001;
	case 8198ULL: goto x86_l_2006;
	case 8203ULL: goto x86_l_200b;
	case 8208ULL: goto x86_l_2010;
	case 8213ULL: goto x86_l_2015;
	case 8215ULL: goto x86_l_2017;
	case 8219ULL: goto x86_l_201b;
	case 8222ULL: goto x86_l_201e;
	case 8226ULL: goto x86_l_2022;
	case 8231ULL: goto x86_l_2027;
	case 8236ULL: goto x86_l_202c;
	case 8241ULL: goto x86_l_2031;
	case 8246ULL: goto x86_l_2036;
	case 8251ULL: goto x86_l_203b;
	case 8253ULL: goto x86_l_203d;
	case 8257ULL: goto x86_l_2041;
	case 8261ULL: goto x86_l_2045;
	case 8265ULL: goto x86_l_2049;
	case 8270ULL: goto x86_l_204e;
	case 8275ULL: goto x86_l_2053;
	case 8280ULL: goto x86_l_2058;
	case 8285ULL: goto x86_l_205d;
	case 8288ULL: goto x86_l_2060;
	case 8290ULL: goto x86_l_2062;
	case 8294ULL: goto x86_l_2066;
	case 8299ULL: goto x86_l_206b;
	case 8304ULL: goto x86_l_2070;
	case 8307ULL: goto x86_l_2073;
	case 8312ULL: goto x86_l_2078;
	case 8317ULL: goto x86_l_207d;
	case 8322ULL: goto x86_l_2082;
	case 8325ULL: goto x86_l_2085;
	case 8330ULL: goto x86_l_208a;
	case 8332ULL: goto x86_l_208c;
	case 8338ULL: goto x86_l_2092;
	case 8343ULL: goto x86_l_2097;
	case 8348ULL: goto x86_l_209c;
	case 8356ULL: goto x86_l_20a4;
	case 8364ULL: goto x86_l_20ac;
	case 8372ULL: goto x86_l_20b4;
	case 8380ULL: goto x86_l_20bc;
	case 8388ULL: goto x86_l_20c4;
	case 8396ULL: goto x86_l_20cc;
	case 8404ULL: goto x86_l_20d4;
	case 8412ULL: goto x86_l_20dc;
	case 8420ULL: goto x86_l_20e4;
	case 8427ULL: goto x86_l_20eb;
	case 8432ULL: goto x86_l_20f0;
	case 8437ULL: goto x86_l_20f5;
	case 8442ULL: goto x86_l_20fa;
	case 8447ULL: goto x86_l_20ff;
	case 8452ULL: goto x86_l_2104;
	case 8454ULL: goto x86_l_2106;
	case 8457ULL: goto x86_l_2109;
	case 8463ULL: goto x86_l_210f;
	case 8466ULL: goto x86_l_2112;
	case 8471ULL: goto x86_l_2117;
	case 8478ULL: goto x86_l_211e;
	case 8483ULL: goto x86_l_2123;
	case 8488ULL: goto x86_l_2128;
	case 8496ULL: goto x86_l_2130;
	case 8505ULL: goto x86_l_2139;
	case 8512ULL: goto x86_l_2140;
	case 8517ULL: goto x86_l_2145;
	case 8522ULL: goto x86_l_214a;
	case 8527ULL: goto x86_l_214f;
	case 8531ULL: goto x86_l_2153;
	case 8533ULL: goto x86_l_2155;
	case 8536ULL: goto x86_l_2158;
	case 8542ULL: goto x86_l_215e;
	case 8545ULL: goto x86_l_2161;
	case 8549ULL: goto x86_l_2165;
	case 8553ULL: goto x86_l_2169;
	case 8557ULL: goto x86_l_216d;
	case 8560ULL: goto x86_l_2170;
	case 8564ULL: goto x86_l_2174;
	case 8568ULL: goto x86_l_2178;
	case 8573ULL: goto x86_l_217d;
	case 8578ULL: goto x86_l_2182;
	case 8586ULL: goto x86_l_218a;
	case 8591ULL: goto x86_l_218f;
	case 8593ULL: goto x86_l_2191;
	case 8596ULL: goto x86_l_2194;
	case 8602ULL: goto x86_l_219a;
	case 8607ULL: goto x86_l_219f;
	case 8610ULL: goto x86_l_21a2;
	case 8616ULL: goto x86_l_21a8;
	case 8618ULL: goto x86_l_21aa;
	case 8624ULL: goto x86_l_21b0;
	case 8627ULL: goto x86_l_21b3;
	case 8633ULL: goto x86_l_21b9;
	case 8636ULL: goto x86_l_21bc;
	case 8642ULL: goto x86_l_21c2;
	case 8649ULL: goto x86_l_21c9;
	case 8653ULL: goto x86_l_21cd;
	case 8658ULL: goto x86_l_21d2;
	case 8662ULL: goto x86_l_21d6;
	case 8667ULL: goto x86_l_21db;
	case 8672ULL: goto x86_l_21e0;
	case 8675ULL: goto x86_l_21e3;
	case 8680ULL: goto x86_l_21e8;
	case 8682ULL: goto x86_l_21ea;
	case 8686ULL: goto x86_l_21ee;
	case 8691ULL: goto x86_l_21f3;
	case 8696ULL: goto x86_l_21f8;
	case 8699ULL: goto x86_l_21fb;
	case 8704ULL: goto x86_l_2200;
	case 8706ULL: goto x86_l_2202;
	case 8710ULL: goto x86_l_2206;
	case 8714ULL: goto x86_l_220a;
	case 8718ULL: goto x86_l_220e;
	case 8723ULL: goto x86_l_2213;
	case 8728ULL: goto x86_l_2218;
	case 8733ULL: goto x86_l_221d;
	case 8736ULL: goto x86_l_2220;
	case 8738ULL: goto x86_l_2222;
	case 8742ULL: goto x86_l_2226;
	case 8747ULL: goto x86_l_222b;
	case 8752ULL: goto x86_l_2230;
	case 8757ULL: goto x86_l_2235;
	case 8760ULL: goto x86_l_2238;
	case 8762ULL: goto x86_l_223a;
	case 8766ULL: goto x86_l_223e;
	case 8772ULL: goto x86_l_2244;
	case 8778ULL: goto x86_l_224a;
	case 8781ULL: goto x86_l_224d;
	case 8786ULL: goto x86_l_2252;
	case 8791ULL: goto x86_l_2257;
	case 8793ULL: goto x86_l_2259;
	case 8797ULL: goto x86_l_225d;
	case 8799ULL: goto x86_l_225f;
	case 8803ULL: goto x86_l_2263;
	case 8807ULL: goto x86_l_2267;
	case 8811ULL: goto x86_l_226b;
	case 8816ULL: goto x86_l_2270;
	case 8821ULL: goto x86_l_2275;
	case 8826ULL: goto x86_l_227a;
	case 8835ULL: goto x86_l_2283;
	case 8840ULL: goto x86_l_2288;
	case 8845ULL: goto x86_l_228d;
	case 8852ULL: goto x86_l_2294;
	case 8854ULL: goto x86_l_2296;
	case 8859ULL: goto x86_l_229b;
	case 8864ULL: goto x86_l_22a0;
	case 8869ULL: goto x86_l_22a5;
	case 8871ULL: goto x86_l_22a7;
	case 8873ULL: goto x86_l_22a9;
	case 8876ULL: goto x86_l_22ac;
	case 8882ULL: goto x86_l_22b2;
	case 8884ULL: goto x86_l_22b4;
	case 8892ULL: goto x86_l_22bc;
	case 8902ULL: goto x86_l_22c6;
	case 8912ULL: goto x86_l_22d0;
	case 8920ULL: goto x86_l_22d8;
	case 8927ULL: goto x86_l_22df;
	case 8935ULL: goto x86_l_22e7;
	case 8940ULL: goto x86_l_22ec;
	case 8942ULL: goto x86_l_22ee;
	case 8945ULL: goto x86_l_22f1;
	case 8951ULL: goto x86_l_22f7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c11:
	/* 0x1c11: add    r15,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_1c15:
	/* 0x1c15: jmp    24f0 <generic_rawtp_process_event+0x24f0> */
	return 9456ULL;
x86_l_1c1a:
	/* 0x1c1a: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1c1d:
	/* 0x1c1d: add    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c20:
	/* 0x1c20: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1c27:
	/* 0x1c27: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_1c33:
	/* 0x1c33: test   r13b,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R13, X86_WIDTH_8, 16ULL);
x86_l_1c37:
	/* 0x1c37: jne    2252 <generic_rawtp_process_event+0x2252> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2252;
	}
x86_l_1c3d:
	/* 0x1c3d: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1c41:
	/* 0x1c41: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c43:
	/* 0x1c43: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_1c47:
	/* 0x1c47: jle    25dd <generic_rawtp_process_event+0x25dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 9693ULL;
	}
x86_l_1c4d:
	/* 0x1c4d: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_1c51:
	/* 0x1c51: je     2e70 <generic_rawtp_process_event+0x2e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11888ULL;
	}
x86_l_1c57:
	/* 0x1c57: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1c5b:
	/* 0x1c5b: je     2e79 <generic_rawtp_process_event+0x2e79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11897ULL;
	}
x86_l_1c61:
	/* 0x1c61: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_1c65:
	/* 0x1c65: jne    2e8c <generic_rawtp_process_event+0x2e8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11916ULL;
	}
x86_l_1c6b:
	/* 0x1c6b: add    r15,0x5e70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24176ULL);
x86_l_1c72:
	/* 0x1c72: jmp    2e89 <generic_rawtp_process_event+0x2e89> */
	return 11913ULL;
x86_l_1c77:
	/* 0x1c77: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c7c:
	/* 0x1c7c: lea    r15,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c81:
	/* 0x1c81: lea    rbp,[r12+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1c86:
	/* 0x1c86: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c8b:
	/* 0x1c8b: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c8f:
	/* 0x1c8f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c94:
	/* 0x1c94: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c99:
	/* 0x1c99: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1c9c:
	/* 0x1c9c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ca1:
	/* 0x1ca1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca3:
	/* 0x1ca3: lea    rdi,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ca8:
	/* 0x1ca8: lea    rdx,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1cac:
	/* 0x1cac: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1cb1:
	/* 0x1cb1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cb6:
	/* 0x1cb6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cbb:
	/* 0x1cbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cbd:
	/* 0x1cbd: lea    rdi,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cc2:
	/* 0x1cc2: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cc6:
	/* 0x1cc6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ccb:
	/* 0x1ccb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cd0:
	/* 0x1cd0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cd5:
	/* 0x1cd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd7:
	/* 0x1cd7: lea    rdi,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1cdc:
	/* 0x1cdc: lea    rdx,[r13+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1ce0:
	/* 0x1ce0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ce5:
	/* 0x1ce5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cea:
	/* 0x1cea: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cef:
	/* 0x1cef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cf1:
	/* 0x1cf1: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cf6:
	/* 0x1cf6: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cfa:
	/* 0x1cfa: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1cff:
	/* 0x1cff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d04:
	/* 0x1d04: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d09:
	/* 0x1d09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d0b:
	/* 0x1d0b: lea    rdi,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d10:
	/* 0x1d10: lea    rdx,[r13+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1d14:
	/* 0x1d14: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d19:
	/* 0x1d19: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d1e:
	/* 0x1d1e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d23:
	/* 0x1d23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d25:
	/* 0x1d25: lea    rdi,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d2a:
	/* 0x1d2a: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d2e:
	/* 0x1d2e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d33:
	/* 0x1d33: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d38:
	/* 0x1d38: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d3d:
	/* 0x1d3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d3f:
	/* 0x1d3f: lea    rdi,[r12+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1d44:
	/* 0x1d44: lea    rdx,[r13+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1d48:
	/* 0x1d48: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d4d:
	/* 0x1d4d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d52:
	/* 0x1d52: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d57:
	/* 0x1d57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d59:
	/* 0x1d59: mov    DWORD PTR [r12+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1d62:
	/* 0x1d62: lea    rdi,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d67:
	/* 0x1d67: lea    rdx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d6b:
	/* 0x1d6b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d70:
	/* 0x1d70: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d75:
	/* 0x1d75: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d7a:
	/* 0x1d7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d7c:
	/* 0x1d7c: lea    rdi,[r12+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d81:
	/* 0x1d81: lea    rdx,[r13+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d85:
	/* 0x1d85: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d8a:
	/* 0x1d8a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d8f:
	/* 0x1d8f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d94:
	/* 0x1d94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d96:
	/* 0x1d96: lea    rdi,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d9b:
	/* 0x1d9b: lea    rdx,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d9f:
	/* 0x1d9f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1da4:
	/* 0x1da4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1da9:
	/* 0x1da9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dae:
	/* 0x1dae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1db0:
	/* 0x1db0: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1db4:
	/* 0x1db4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1db9:
	/* 0x1db9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dbe:
	/* 0x1dbe: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1dc1:
	/* 0x1dc1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dc6:
	/* 0x1dc6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc8:
	/* 0x1dc8: add    r13,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1dcf:
	/* 0x1dcf: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1dd4:
	/* 0x1dd4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1dd9:
	/* 0x1dd9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dde:
	/* 0x1dde: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1de3:
	/* 0x1de3: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1de6:
	/* 0x1de6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de8:
	/* 0x1de8: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ded:
	/* 0x1ded: lea    rdx,[r15+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1df4:
	/* 0x1df4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1df9:
	/* 0x1df9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dfe:
	/* 0x1dfe: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1e01:
	/* 0x1e01: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e06:
	/* 0x1e06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e08:
	/* 0x1e08: lea    rdi,[r12+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1e0d:
	/* 0x1e0d: lea    rdx,[r15+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1e14:
	/* 0x1e14: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e19:
	/* 0x1e19: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e1e:
	/* 0x1e1e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e23:
	/* 0x1e23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e25:
	/* 0x1e25: lea    rdi,[r12+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1e2a:
	/* 0x1e2a: lea    rdx,[r15+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1e31:
	/* 0x1e31: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e36:
	/* 0x1e36: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e3b:
	/* 0x1e3b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e40:
	/* 0x1e40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e42:
	/* 0x1e42: add    r12,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_1e46:
	/* 0x1e46: add    r15,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1e4d:
	/* 0x1e4d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e52:
	/* 0x1e52: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e57:
	/* 0x1e57: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1e5a:
	/* 0x1e5a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e5f:
	/* 0x1e5f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1e62:
	/* 0x1e62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e64:
	/* 0x1e64: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_1e6a:
	/* 0x1e6a: jmp    2efd <generic_rawtp_process_event+0x2efd> */
	return 12029ULL;
x86_l_1e6f:
	/* 0x1e6f: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e74:
	/* 0x1e74: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1e7c:
	/* 0x1e7c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e81:
	/* 0x1e81: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e86:
	/* 0x1e86: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e8b:
	/* 0x1e8b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1e8e:
	/* 0x1e8e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e93:
	/* 0x1e93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e95:
	/* 0x1e95: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e99:
	/* 0x1e99: lea    rdx,[r12+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1ea1:
	/* 0x1ea1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ea6:
	/* 0x1ea6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1eab:
	/* 0x1eab: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1eb0:
	/* 0x1eb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eb2:
	/* 0x1eb2: lea    rdi,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1eb6:
	/* 0x1eb6: lea    rdx,[r12+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1ebe:
	/* 0x1ebe: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ec3:
	/* 0x1ec3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ec8:
	/* 0x1ec8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ecd:
	/* 0x1ecd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ecf:
	/* 0x1ecf: add    r15,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1ed3:
	/* 0x1ed3: add    r12,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1eda:
	/* 0x1eda: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1edf:
	/* 0x1edf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ee4:
	/* 0x1ee4: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1ee7:
	/* 0x1ee7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1eec:
	/* 0x1eec: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1eef:
	/* 0x1eef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ef1:
	/* 0x1ef1: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_1ef7:
	/* 0x1ef7: jmp    2efd <generic_rawtp_process_event+0x2efd> */
	return 12029ULL;
x86_l_1efc:
	/* 0x1efc: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f01:
	/* 0x1f01: lea    rdx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f06:
	/* 0x1f06: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1f0b:
	/* 0x1f0b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f10:
	/* 0x1f10: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f15:
	/* 0x1f15: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1f18:
	/* 0x1f18: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f1d:
	/* 0x1f1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f1f:
	/* 0x1f1f: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f23:
	/* 0x1f23: lea    rdx,[r12+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1f28:
	/* 0x1f28: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1f2d:
	/* 0x1f2d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f32:
	/* 0x1f32: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f37:
	/* 0x1f37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f39:
	/* 0x1f39: lea    rdi,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f3d:
	/* 0x1f3d: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f42:
	/* 0x1f42: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1f47:
	/* 0x1f47: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f4c:
	/* 0x1f4c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f51:
	/* 0x1f51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f53:
	/* 0x1f53: lea    rdi,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f57:
	/* 0x1f57: lea    rdx,[r12+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1f5c:
	/* 0x1f5c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1f61:
	/* 0x1f61: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f66:
	/* 0x1f66: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f6b:
	/* 0x1f6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f6d:
	/* 0x1f6d: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1f71:
	/* 0x1f71: add    r12,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1f75:
	/* 0x1f75: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1f7a:
	/* 0x1f7a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f7f:
	/* 0x1f7f: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1f82:
	/* 0x1f82: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1f87:
	/* 0x1f87: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f8a:
	/* 0x1f8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f8c:
	/* 0x1f8c: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_1f92:
	/* 0x1f92: jmp    2efd <generic_rawtp_process_event+0x2efd> */
	return 12029ULL;
x86_l_1f97:
	/* 0x1f97: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1f9c:
	/* 0x1f9c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fa1:
	/* 0x1fa1: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fa6:
	/* 0x1fa6: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fab:
	/* 0x1fab: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1fae:
	/* 0x1fae: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fb3:
	/* 0x1fb3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1fb6:
	/* 0x1fb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb8:
	/* 0x1fb8: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1fbc:
	/* 0x1fbc: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1fc1:
	/* 0x1fc1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1fc6:
	/* 0x1fc6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fcb:
	/* 0x1fcb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fd0:
	/* 0x1fd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fd2:
	/* 0x1fd2: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1fd6:
	/* 0x1fd6: add    r12,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_1fda:
	/* 0x1fda: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1fdf:
	/* 0x1fdf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fe4:
	/* 0x1fe4: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1fe7:
	/* 0x1fe7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1fec:
	/* 0x1fec: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1fef:
	/* 0x1fef: jmp    208a <generic_rawtp_process_event+0x208a> */
	goto x86_l_208a;
x86_l_1ff4:
	/* 0x1ff4: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_1ff7:
	/* 0x1ff7: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ffc:
	/* 0x1ffc: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2001:
	/* 0x2001: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2006:
	/* 0x2006: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_200b:
	/* 0x200b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2010:
	/* 0x2010: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2015:
	/* 0x2015: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2017:
	/* 0x2017: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_201b:
	/* 0x201b: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_201e:
	/* 0x201e: mov    DWORD PTR [r13+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2022:
	/* 0x2022: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2027:
	/* 0x2027: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_202c:
	/* 0x202c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2031:
	/* 0x2031: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2036:
	/* 0x2036: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_203b:
	/* 0x203b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_203d:
	/* 0x203d: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2041:
	/* 0x2041: mov    DWORD PTR [r13+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2045:
	/* 0x2045: add    r12,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_2049:
	/* 0x2049: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_204e:
	/* 0x204e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2053:
	/* 0x2053: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2058:
	/* 0x2058: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_205d:
	/* 0x205d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2060:
	/* 0x2060: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2062:
	/* 0x2062: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2066:
	/* 0x2066: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_206b:
	/* 0x206b: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2070:
	/* 0x2070: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2073:
	/* 0x2073: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2078:
	/* 0x2078: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_207d:
	/* 0x207d: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_2082:
	/* 0x2082: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2085:
	/* 0x2085: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_208a:
	/* 0x208a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_208c:
	/* 0x208c: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_2092:
	/* 0x2092: jmp    2efd <generic_rawtp_process_event+0x2efd> */
	return 12029ULL;
x86_l_2097:
	/* 0x2097: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_209c:
	/* 0x209c: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_20a4:
	/* 0x20a4: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_20ac:
	/* 0x20ac: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_20b4:
	/* 0x20b4: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_20bc:
	/* 0x20bc: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_20c4:
	/* 0x20c4: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_20cc:
	/* 0x20cc: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_20d4:
	/* 0x20d4: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_20dc:
	/* 0x20dc: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_20e4:
	/* 0x20e4: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20eb:
	/* 0x20eb: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_20f0:
	/* 0x20f0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_20f5:
	/* 0x20f5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20fa:
	/* 0x20fa: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20ff:
	/* 0x20ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2104:
	/* 0x2104: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2106:
	/* 0x2106: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2109:
	/* 0x2109: je     2518 <generic_rawtp_process_event+0x2518> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9496ULL;
	}
x86_l_210f:
	/* 0x210f: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2112:
	/* 0x2112: jmp    2efd <generic_rawtp_process_event+0x2efd> */
	return 12029ULL;
x86_l_2117:
	/* 0x2117: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_211e:
	/* 0x211e: jmp    3b37 <generic_rawtp_process_event+0x3b37> */
	return 15159ULL;
x86_l_2123:
	/* 0x2123: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2128:
	/* 0x2128: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_2130:
	/* 0x2130: movzx  r12d,WORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 128ULL);
x86_l_2139:
	/* 0x2139: mov    rdi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_2140:
	/* 0x2140: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2145:
	/* 0x2145: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_214a:
	/* 0x214a: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_214f:
	/* 0x214f: lea    rbp,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2153:
	/* 0x2153: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2155:
	/* 0x2155: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2158:
	/* 0x2158: je     3984 <generic_rawtp_process_event+0x3984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14724ULL;
	}
x86_l_215e:
	/* 0x215e: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2161:
	/* 0x2161: mov    WORD PTR [rax],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2165:
	/* 0x2165: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_2169:
	/* 0x2169: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_216d:
	/* 0x216d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2170:
	/* 0x2170: add    rdi,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_2174:
	/* 0x2174: lea    rdx,[rbp+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_2178:
	/* 0x2178: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_217d:
	/* 0x217d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2182:
	/* 0x2182: mov    QWORD PTR [rsp+0x90],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_218a:
	/* 0x218a: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_218f:
	/* 0x218f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2191:
	/* 0x2191: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2194:
	/* 0x2194: js     3984 <generic_rawtp_process_event+0x3984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14724ULL;
	}
x86_l_219a:
	/* 0x219a: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_219f:
	/* 0x219f: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_21a2:
	/* 0x21a2: jg     2c1a <generic_rawtp_process_event+0x2c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 11290ULL;
	}
x86_l_21a8:
	/* 0x21a8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21aa:
	/* 0x21aa: je     2cc4 <generic_rawtp_process_event+0x2cc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11460ULL;
	}
x86_l_21b0:
	/* 0x21b0: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_21b3:
	/* 0x21b3: je     2cc4 <generic_rawtp_process_event+0x2cc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11460ULL;
	}
x86_l_21b9:
	/* 0x21b9: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_21bc:
	/* 0x21bc: jne    2ff8 <generic_rawtp_process_event+0x2ff8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12280ULL;
	}
x86_l_21c2:
	/* 0x21c2: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_21c9:
	/* 0x21c9: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_21cd:
	/* 0x21cd: jmp    2f2a <generic_rawtp_process_event+0x2f2a> */
	return 12074ULL;
x86_l_21d2:
	/* 0x21d2: lea    rdx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_21d6:
	/* 0x21d6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_21db:
	/* 0x21db: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21e0:
	/* 0x21e0: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_21e3:
	/* 0x21e3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_21e8:
	/* 0x21e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21ea:
	/* 0x21ea: lea    rdx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21ee:
	/* 0x21ee: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_21f3:
	/* 0x21f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21f8:
	/* 0x21f8: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_21fb:
	/* 0x21fb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2200:
	/* 0x2200: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2202:
	/* 0x2202: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2206:
	/* 0x2206: lea    r12,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_220a:
	/* 0x220a: add    r15,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_220e:
	/* 0x220e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2213:
	/* 0x2213: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2218:
	/* 0x2218: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_221d:
	/* 0x221d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2220:
	/* 0x2220: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2222:
	/* 0x2222: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_2226:
	/* 0x2226: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_222b:
	/* 0x222b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2230:
	/* 0x2230: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2235:
	/* 0x2235: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2238:
	/* 0x2238: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_223a:
	/* 0x223a: movzx  eax,WORD PTR [rbp+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_223e:
	/* 0x223e: movbe  WORD PTR [rbp+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2244:
	/* 0x2244: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_224a:
	/* 0x224a: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_224d:
	/* 0x224d: jmp    3b3c <generic_rawtp_process_event+0x3b3c> */
	return 15164ULL;
x86_l_2252:
	/* 0x2252: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2257:
	/* 0x2257: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2259:
	/* 0x2259: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_225d:
	/* 0x225d: jne    2263 <generic_rawtp_process_event+0x2263> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2263;
	}
x86_l_225f:
	/* 0x225f: mov    rax,QWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2263:
	/* 0x2263: mov    rcx,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2267:
	/* 0x2267: mov    rdx,QWORD PTR [r15+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_226b:
	/* 0x226b: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2270:
	/* 0x2270: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2275:
	/* 0x2275: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_227a:
	/* 0x227a: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2283:
	/* 0x2283: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2288:
	/* 0x2288: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_228d:
	/* 0x228d: mov    rdi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_2294:
	/* 0x2294: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2296:
	/* 0x2296: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_229b:
	/* 0x229b: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22a0:
	/* 0x22a0: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_22a5:
	/* 0x22a5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22a7:
	/* 0x22a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22a9:
	/* 0x22a9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22ac:
	/* 0x22ac: je     2c74 <generic_rawtp_process_event+0x2c74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11380ULL;
	}
x86_l_22b2:
	/* 0x22b2: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_22b4:
	/* 0x22b4: mov    WORD PTR [rsp+0xb0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_22bc:
	/* 0x22bc: mov    WORD PTR [rsp+0xb2],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 764504178693ULL);
x86_l_22c6:
	/* 0x22c6: movabs rax,0x200000046 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934662ULL);
x86_l_22d0:
	/* 0x22d0: mov    QWORD PTR [rsp+0xb4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_22d8:
	/* 0x22d8: mov    rdi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_22df:
	/* 0x22df: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_22e7:
	/* 0x22e7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22ec:
	/* 0x22ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22ee:
	/* 0x22ee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22f1:
	/* 0x22f1: je     2c47 <generic_rawtp_process_event+0x2c47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11335ULL;
	}
x86_l_22f7:
	/* 0x22f7: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
	return 8953ULL;
}

static __noinline __u64 tetragon_bpf_generic_rawtp_generic_rawtp_process_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8953ULL: goto x86_l_22f9;
	case 8958ULL: goto x86_l_22fe;
	case 8962ULL: goto x86_l_2302;
	case 8967ULL: goto x86_l_2307;
	case 8972ULL: goto x86_l_230c;
	case 8977ULL: goto x86_l_2311;
	case 8982ULL: goto x86_l_2316;
	case 8984ULL: goto x86_l_2318;
	case 8989ULL: goto x86_l_231d;
	case 8994ULL: goto x86_l_2322;
	case 9000ULL: goto x86_l_2328;
	case 9004ULL: goto x86_l_232c;
	case 9009ULL: goto x86_l_2331;
	case 9014ULL: goto x86_l_2336;
	case 9019ULL: goto x86_l_233b;
	case 9024ULL: goto x86_l_2340;
	case 9027ULL: goto x86_l_2343;
	case 9029ULL: goto x86_l_2345;
	case 9034ULL: goto x86_l_234a;
	case 9039ULL: goto x86_l_234f;
	case 9043ULL: goto x86_l_2353;
	case 9048ULL: goto x86_l_2358;
	case 9053ULL: goto x86_l_235d;
	case 9058ULL: goto x86_l_2362;
	case 9060ULL: goto x86_l_2364;
	case 9065ULL: goto x86_l_2369;
	case 9071ULL: goto x86_l_236f;
	case 9079ULL: goto x86_l_2377;
	case 9084ULL: goto x86_l_237c;
	case 9089ULL: goto x86_l_2381;
	case 9094ULL: goto x86_l_2386;
	case 9096ULL: goto x86_l_2388;
	case 9104ULL: goto x86_l_2390;
	case 9110ULL: goto x86_l_2396;
	case 9115ULL: goto x86_l_239b;
	case 9120ULL: goto x86_l_23a0;
	case 9125ULL: goto x86_l_23a5;
	case 9130ULL: goto x86_l_23aa;
	case 9135ULL: goto x86_l_23af;
	case 9138ULL: goto x86_l_23b2;
	case 9140ULL: goto x86_l_23b4;
	case 9145ULL: goto x86_l_23b9;
	case 9151ULL: goto x86_l_23bf;
	case 9159ULL: goto x86_l_23c7;
	case 9164ULL: goto x86_l_23cc;
	case 9169ULL: goto x86_l_23d1;
	case 9174ULL: goto x86_l_23d6;
	case 9177ULL: goto x86_l_23d9;
	case 9179ULL: goto x86_l_23db;
	case 9183ULL: goto x86_l_23df;
	case 9188ULL: goto x86_l_23e4;
	case 9193ULL: goto x86_l_23e9;
	case 9198ULL: goto x86_l_23ee;
	case 9203ULL: goto x86_l_23f3;
	case 9206ULL: goto x86_l_23f6;
	case 9208ULL: goto x86_l_23f8;
	case 9213ULL: goto x86_l_23fd;
	case 9218ULL: goto x86_l_2402;
	case 9222ULL: goto x86_l_2406;
	case 9225ULL: goto x86_l_2409;
	case 9230ULL: goto x86_l_240e;
	case 9232ULL: goto x86_l_2410;
	case 9234ULL: goto x86_l_2412;
	case 9237ULL: goto x86_l_2415;
	case 9240ULL: goto x86_l_2418;
	case 9245ULL: goto x86_l_241d;
	case 9247ULL: goto x86_l_241f;
	case 9250ULL: goto x86_l_2422;
	case 9254ULL: goto x86_l_2426;
	case 9256ULL: goto x86_l_2428;
	case 9260ULL: goto x86_l_242c;
	case 9262ULL: goto x86_l_242e;
	case 9265ULL: goto x86_l_2431;
	case 9267ULL: goto x86_l_2433;
	case 9271ULL: goto x86_l_2437;
	case 9274ULL: goto x86_l_243a;
	case 9280ULL: goto x86_l_2440;
	case 9286ULL: goto x86_l_2446;
	case 9292ULL: goto x86_l_244c;
	case 9295ULL: goto x86_l_244f;
	case 9297ULL: goto x86_l_2451;
	case 9302ULL: goto x86_l_2456;
	case 9304ULL: goto x86_l_2458;
	case 9307ULL: goto x86_l_245b;
	case 9311ULL: goto x86_l_245f;
	case 9314ULL: goto x86_l_2462;
	case 9317ULL: goto x86_l_2465;
	case 9320ULL: goto x86_l_2468;
	case 9325ULL: goto x86_l_246d;
	case 9327ULL: goto x86_l_246f;
	case 9332ULL: goto x86_l_2474;
	case 9335ULL: goto x86_l_2477;
	case 9341ULL: goto x86_l_247d;
	case 9349ULL: goto x86_l_2485;
	case 9354ULL: goto x86_l_248a;
	case 9359ULL: goto x86_l_248f;
	case 9364ULL: goto x86_l_2494;
	case 9369ULL: goto x86_l_2499;
	case 9374ULL: goto x86_l_249e;
	case 9378ULL: goto x86_l_24a2;
	case 9382ULL: goto x86_l_24a6;
	case 9387ULL: goto x86_l_24ab;
	case 9392ULL: goto x86_l_24b0;
	case 9397ULL: goto x86_l_24b5;
	case 9399ULL: goto x86_l_24b7;
	case 9403ULL: goto x86_l_24bb;
	case 9407ULL: goto x86_l_24bf;
	case 9412ULL: goto x86_l_24c4;
	case 9417ULL: goto x86_l_24c9;
	case 9422ULL: goto x86_l_24ce;
	case 9425ULL: goto x86_l_24d1;
	case 9427ULL: goto x86_l_24d3;
	case 9432ULL: goto x86_l_24d8;
	case 9436ULL: goto x86_l_24dc;
	case 9442ULL: goto x86_l_24e2;
	case 9450ULL: goto x86_l_24ea;
	case 9456ULL: goto x86_l_24f0;
	case 9459ULL: goto x86_l_24f3;
	case 9464ULL: goto x86_l_24f8;
	case 9467ULL: goto x86_l_24fb;
	case 9473ULL: goto x86_l_2501;
	case 9476ULL: goto x86_l_2504;
	case 9482ULL: goto x86_l_250a;
	case 9485ULL: goto x86_l_250d;
	case 9491ULL: goto x86_l_2513;
	case 9496ULL: goto x86_l_2518;
	case 9501ULL: goto x86_l_251d;
	case 9505ULL: goto x86_l_2521;
	case 9510ULL: goto x86_l_2526;
	case 9515ULL: goto x86_l_252b;
	case 9520ULL: goto x86_l_2530;
	case 9525ULL: goto x86_l_2535;
	case 9530ULL: goto x86_l_253a;
	case 9532ULL: goto x86_l_253c;
	case 9535ULL: goto x86_l_253f;
	case 9541ULL: goto x86_l_2545;
	case 9546ULL: goto x86_l_254a;
	case 9550ULL: goto x86_l_254e;
	case 9555ULL: goto x86_l_2553;
	case 9560ULL: goto x86_l_2558;
	case 9565ULL: goto x86_l_255d;
	case 9570ULL: goto x86_l_2562;
	case 9572ULL: goto x86_l_2564;
	case 9577ULL: goto x86_l_2569;
	case 9581ULL: goto x86_l_256d;
	case 9586ULL: goto x86_l_2572;
	case 9591ULL: goto x86_l_2577;
	case 9594ULL: goto x86_l_257a;
	case 9599ULL: goto x86_l_257f;
	case 9604ULL: goto x86_l_2584;
	case 9609ULL: goto x86_l_2589;
	case 9614ULL: goto x86_l_258e;
	case 9616ULL: goto x86_l_2590;
	case 9620ULL: goto x86_l_2594;
	case 9625ULL: goto x86_l_2599;
	case 9630ULL: goto x86_l_259e;
	case 9635ULL: goto x86_l_25a3;
	case 9640ULL: goto x86_l_25a8;
	case 9643ULL: goto x86_l_25ab;
	case 9645ULL: goto x86_l_25ad;
	case 9651ULL: goto x86_l_25b3;
	case 9654ULL: goto x86_l_25b6;
	case 9660ULL: goto x86_l_25bc;
	case 9662ULL: goto x86_l_25be;
	case 9667ULL: goto x86_l_25c3;
	case 9670ULL: goto x86_l_25c6;
	case 9675ULL: goto x86_l_25cb;
	case 9677ULL: goto x86_l_25cd;
	case 9682ULL: goto x86_l_25d2;
	case 9685ULL: goto x86_l_25d5;
	case 9688ULL: goto x86_l_25d8;
	case 9693ULL: goto x86_l_25dd;
	case 9697ULL: goto x86_l_25e1;
	case 9703ULL: goto x86_l_25e7;
	case 9707ULL: goto x86_l_25eb;
	case 9713ULL: goto x86_l_25f1;
	case 9720ULL: goto x86_l_25f8;
	case 9725ULL: goto x86_l_25fd;
	case 9729ULL: goto x86_l_2601;
	case 9734ULL: goto x86_l_2606;
	case 9739ULL: goto x86_l_260b;
	case 9744ULL: goto x86_l_2610;
	case 9749ULL: goto x86_l_2615;
	case 9751ULL: goto x86_l_2617;
	case 9755ULL: goto x86_l_261b;
	case 9760ULL: goto x86_l_2620;
	case 9765ULL: goto x86_l_2625;
	case 9768ULL: goto x86_l_2628;
	case 9773ULL: goto x86_l_262d;
	case 9775ULL: goto x86_l_262f;
	case 9780ULL: goto x86_l_2634;
	case 9784ULL: goto x86_l_2638;
	case 9788ULL: goto x86_l_263c;
	case 9792ULL: goto x86_l_2640;
	case 9797ULL: goto x86_l_2645;
	case 9802ULL: goto x86_l_264a;
	case 9807ULL: goto x86_l_264f;
	case 9810ULL: goto x86_l_2652;
	case 9812ULL: goto x86_l_2654;
	case 9816ULL: goto x86_l_2658;
	case 9821ULL: goto x86_l_265d;
	case 9826ULL: goto x86_l_2662;
	case 9831ULL: goto x86_l_2667;
	case 9834ULL: goto x86_l_266a;
	case 9836ULL: goto x86_l_266c;
	case 9840ULL: goto x86_l_2670;
	case 9846ULL: goto x86_l_2676;
	case 9852ULL: goto x86_l_267c;
	case 9855ULL: goto x86_l_267f;
	case 9860ULL: goto x86_l_2684;
	case 9863ULL: goto x86_l_2687;
	case 9869ULL: goto x86_l_268d;
	case 9871ULL: goto x86_l_268f;
	case 9874ULL: goto x86_l_2692;
	case 9880ULL: goto x86_l_2698;
	case 9882ULL: goto x86_l_269a;
	case 9885ULL: goto x86_l_269d;
	case 9891ULL: goto x86_l_26a3;
	case 9894ULL: goto x86_l_26a6;
	case 9897ULL: goto x86_l_26a9;
	case 9903ULL: goto x86_l_26af;
	case 9906ULL: goto x86_l_26b2;
	case 9912ULL: goto x86_l_26b8;
	case 9917ULL: goto x86_l_26bd;
	case 9923ULL: goto x86_l_26c3;
	case 9928ULL: goto x86_l_26c8;
	case 9933ULL: goto x86_l_26cd;
	case 9938ULL: goto x86_l_26d2;
	case 9943ULL: goto x86_l_26d7;
	case 9945ULL: goto x86_l_26d9;
	case 9950ULL: goto x86_l_26de;
	case 9952ULL: goto x86_l_26e0;
	case 9958ULL: goto x86_l_26e6;
	case 9963ULL: goto x86_l_26eb;
	case 9968ULL: goto x86_l_26f0;
	case 9971ULL: goto x86_l_26f3;
	case 9979ULL: goto x86_l_26fb;
	case 9986ULL: goto x86_l_2702;
	case 9992ULL: goto x86_l_2708;
	case 10000ULL: goto x86_l_2710;
	case 10004ULL: goto x86_l_2714;
	case 10009ULL: goto x86_l_2719;
	case 10012ULL: goto x86_l_271c;
	case 10016ULL: goto x86_l_2720;
	case 10021ULL: goto x86_l_2725;
	case 10026ULL: goto x86_l_272a;
	case 10034ULL: goto x86_l_2732;
	case 10039ULL: goto x86_l_2737;
	case 10041ULL: goto x86_l_2739;
	case 10046ULL: goto x86_l_273e;
	case 10048ULL: goto x86_l_2740;
	case 10054ULL: goto x86_l_2746;
	case 10058ULL: goto x86_l_274a;
	case 10064ULL: goto x86_l_2750;
	case 10069ULL: goto x86_l_2755;
	case 10073ULL: goto x86_l_2759;
	case 10078ULL: goto x86_l_275e;
	case 10084ULL: goto x86_l_2764;
	case 10089ULL: goto x86_l_2769;
	case 10094ULL: goto x86_l_276e;
	case 10099ULL: goto x86_l_2773;
	case 10101ULL: goto x86_l_2775;
	case 10106ULL: goto x86_l_277a;
	case 10108ULL: goto x86_l_277c;
	case 10114ULL: goto x86_l_2782;
	case 10119ULL: goto x86_l_2787;
	case 10124ULL: goto x86_l_278c;
	case 10132ULL: goto x86_l_2794;
	case 10138ULL: goto x86_l_279a;
	case 10144ULL: goto x86_l_27a0;
	case 10152ULL: goto x86_l_27a8;
	case 10157ULL: goto x86_l_27ad;
	case 10165ULL: goto x86_l_27b5;
	case 10169ULL: goto x86_l_27b9;
	case 10174ULL: goto x86_l_27be;
	case 10179ULL: goto x86_l_27c3;
	case 10187ULL: goto x86_l_27cb;
	case 10192ULL: goto x86_l_27d0;
	case 10194ULL: goto x86_l_27d2;
	case 10199ULL: goto x86_l_27d7;
	case 10201ULL: goto x86_l_27d9;
	case 10207ULL: goto x86_l_27df;
	case 10215ULL: goto x86_l_27e7;
	case 10223ULL: goto x86_l_27ef;
	case 10227ULL: goto x86_l_27f3;
	case 10233ULL: goto x86_l_27f9;
	case 10238ULL: goto x86_l_27fe;
	case 10242ULL: goto x86_l_2802;
	case 10247ULL: goto x86_l_2807;
	case 10253ULL: goto x86_l_280d;
	case 10258ULL: goto x86_l_2812;
	case 10263ULL: goto x86_l_2817;
	case 10268ULL: goto x86_l_281c;
	case 10270ULL: goto x86_l_281e;
	case 10275ULL: goto x86_l_2823;
	case 10277ULL: goto x86_l_2825;
	case 10283ULL: goto x86_l_282b;
	case 10288ULL: goto x86_l_2830;
	case 10293ULL: goto x86_l_2835;
	case 10301ULL: goto x86_l_283d;
	case 10307ULL: goto x86_l_2843;
	case 10313ULL: goto x86_l_2849;
	case 10321ULL: goto x86_l_2851;
	case 10329ULL: goto x86_l_2859;
	case 10332ULL: goto x86_l_285c;
	case 10338ULL: goto x86_l_2862;
	case 10343ULL: goto x86_l_2867;
	case 10348ULL: goto x86_l_286c;
	case 10353ULL: goto x86_l_2871;
	case 10361ULL: goto x86_l_2879;
	case 10366ULL: goto x86_l_287e;
	case 10368ULL: goto x86_l_2880;
	case 10373ULL: goto x86_l_2885;
	case 10375ULL: goto x86_l_2887;
	case 10381ULL: goto x86_l_288d;
	case 10389ULL: goto x86_l_2895;
	case 10397ULL: goto x86_l_289d;
	case 10401ULL: goto x86_l_28a1;
	case 10407ULL: goto x86_l_28a7;
	case 10412ULL: goto x86_l_28ac;
	case 10416ULL: goto x86_l_28b0;
	case 10421ULL: goto x86_l_28b5;
	case 10427ULL: goto x86_l_28bb;
	case 10432ULL: goto x86_l_28c0;
	case 10437ULL: goto x86_l_28c5;
	case 10442ULL: goto x86_l_28ca;
	case 10444ULL: goto x86_l_28cc;
	case 10449ULL: goto x86_l_28d1;
	case 10451ULL: goto x86_l_28d3;
	case 10457ULL: goto x86_l_28d9;
	case 10462ULL: goto x86_l_28de;
	case 10467ULL: goto x86_l_28e3;
	case 10475ULL: goto x86_l_28eb;
	case 10481ULL: goto x86_l_28f1;
	case 10487ULL: goto x86_l_28f7;
	case 10495ULL: goto x86_l_28ff;
	case 10498ULL: goto x86_l_2902;
	case 10501ULL: goto x86_l_2905;
	case 10507ULL: goto x86_l_290b;
	case 10512ULL: goto x86_l_2910;
	case 10517ULL: goto x86_l_2915;
	case 10522ULL: goto x86_l_291a;
	case 10530ULL: goto x86_l_2922;
	case 10535ULL: goto x86_l_2927;
	case 10537ULL: goto x86_l_2929;
	case 10542ULL: goto x86_l_292e;
	case 10544ULL: goto x86_l_2930;
	case 10550ULL: goto x86_l_2936;
	case 10558ULL: goto x86_l_293e;
	case 10566ULL: goto x86_l_2946;
	case 10570ULL: goto x86_l_294a;
	case 10576ULL: goto x86_l_2950;
	case 10581ULL: goto x86_l_2955;
	case 10585ULL: goto x86_l_2959;
	case 10590ULL: goto x86_l_295e;
	case 10596ULL: goto x86_l_2964;
	case 10601ULL: goto x86_l_2969;
	case 10606ULL: goto x86_l_296e;
	case 10611ULL: goto x86_l_2973;
	case 10613ULL: goto x86_l_2975;
	case 10618ULL: goto x86_l_297a;
	case 10620ULL: goto x86_l_297c;
	case 10626ULL: goto x86_l_2982;
	case 10631ULL: goto x86_l_2987;
	case 10636ULL: goto x86_l_298c;
	case 10644ULL: goto x86_l_2994;
	case 10650ULL: goto x86_l_299a;
	case 10656ULL: goto x86_l_29a0;
	case 10664ULL: goto x86_l_29a8;
	case 10667ULL: goto x86_l_29ab;
	case 10670ULL: goto x86_l_29ae;
	case 10676ULL: goto x86_l_29b4;
	case 10681ULL: goto x86_l_29b9;
	case 10686ULL: goto x86_l_29be;
	case 10691ULL: goto x86_l_29c3;
	case 10699ULL: goto x86_l_29cb;
	case 10704ULL: goto x86_l_29d0;
	case 10706ULL: goto x86_l_29d2;
	case 10711ULL: goto x86_l_29d7;
	case 10713ULL: goto x86_l_29d9;
	case 10719ULL: goto x86_l_29df;
	case 10727ULL: goto x86_l_29e7;
	case 10735ULL: goto x86_l_29ef;
	case 10739ULL: goto x86_l_29f3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_22f9:
	/* 0x22f9: jmp    2c74 <generic_rawtp_process_event+0x2c74> */
	return 11380ULL;
x86_l_22fe:
	/* 0x22fe: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2302:
	/* 0x2302: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2307:
	/* 0x2307: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_230c:
	/* 0x230c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2311:
	/* 0x2311: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2316:
	/* 0x2316: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2318:
	/* 0x2318: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_231d:
	/* 0x231d: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2322:
	/* 0x2322: je     974 <generic_rawtp_process_event+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2420ULL;
	}
x86_l_2328:
	/* 0x2328: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_232c:
	/* 0x232c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2331:
	/* 0x2331: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2336:
	/* 0x2336: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_233b:
	/* 0x233b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2340:
	/* 0x2340: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2343:
	/* 0x2343: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2345:
	/* 0x2345: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_234a:
	/* 0x234a: mov    QWORD PTR [rsp+0x50],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_234f:
	/* 0x234f: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2353:
	/* 0x2353: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2358:
	/* 0x2358: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_235d:
	/* 0x235d: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2362:
	/* 0x2362: jne    236f <generic_rawtp_process_event+0x236f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_236f;
	}
x86_l_2364:
	/* 0x2364: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2369:
	/* 0x2369: je     974 <generic_rawtp_process_event+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2420ULL;
	}
x86_l_236f:
	/* 0x236f: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2377:
	/* 0x2377: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_237c:
	/* 0x237c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2381:
	/* 0x2381: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2386:
	/* 0x2386: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2388:
	/* 0x2388: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_2390:
	/* 0x2390: je     2cd5 <generic_rawtp_process_event+0x2cd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11477ULL;
	}
x86_l_2396:
	/* 0x2396: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_239b:
	/* 0x239b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23a0:
	/* 0x23a0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_23a5:
	/* 0x23a5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23aa:
	/* 0x23aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23af:
	/* 0x23af: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_23b2:
	/* 0x23b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23b4:
	/* 0x23b4: cmp    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23b9:
	/* 0x23b9: je     2cd5 <generic_rawtp_process_event+0x2cd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11477ULL;
	}
x86_l_23bf:
	/* 0x23bf: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_23c7:
	/* 0x23c7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_23cc:
	/* 0x23cc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23d1:
	/* 0x23d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23d6:
	/* 0x23d6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_23d9:
	/* 0x23d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23db:
	/* 0x23db: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_23df:
	/* 0x23df: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_23e4:
	/* 0x23e4: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_23e9:
	/* 0x23e9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23ee:
	/* 0x23ee: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_23f3:
	/* 0x23f3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_23f6:
	/* 0x23f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23f8:
	/* 0x23f8: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_23fd:
	/* 0x23fd: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2402:
	/* 0x2402: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_2406:
	/* 0x2406: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2409:
	/* 0x2409: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_240e:
	/* 0x240e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2410:
	/* 0x2410: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_2412:
	/* 0x2412: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2415:
	/* 0x2415: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2418:
	/* 0x2418: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_241d:
	/* 0x241d: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_241f:
	/* 0x241f: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2422:
	/* 0x2422: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_2426:
	/* 0x2426: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_2428:
	/* 0x2428: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_242c:
	/* 0x242c: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_242e:
	/* 0x242e: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_2431:
	/* 0x2431: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2433:
	/* 0x2433: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2437:
	/* 0x2437: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_243a:
	/* 0x243a: jb     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2425ULL;
	}
x86_l_2440:
	/* 0x2440: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_2446:
	/* 0x2446: ja     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2425ULL;
	}
x86_l_244c:
	/* 0x244c: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_244f:
	/* 0x244f: jbe    2456 <generic_rawtp_process_event+0x2456> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2456;
	}
x86_l_2451:
	/* 0x2451: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2456:
	/* 0x2456: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2458:
	/* 0x2458: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_245b:
	/* 0x245b: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_245f:
	/* 0x245f: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2462:
	/* 0x2462: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2465:
	/* 0x2465: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2468:
	/* 0x2468: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_246d:
	/* 0x246d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_246f:
	/* 0x246f: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2474:
	/* 0x2474: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2477:
	/* 0x2477: jbe    979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2425ULL;
	}
x86_l_247d:
	/* 0x247d: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2485:
	/* 0x2485: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_248a:
	/* 0x248a: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_248f:
	/* 0x248f: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2494:
	/* 0x2494: jmp    2d34 <generic_rawtp_process_event+0x2d34> */
	return 11572ULL;
x86_l_2499:
	/* 0x2499: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_249e:
	/* 0x249e: lea    rdi,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24a2:
	/* 0x24a2: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24a6:
	/* 0x24a6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_24ab:
	/* 0x24ab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24b0:
	/* 0x24b0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_24b5:
	/* 0x24b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b7:
	/* 0x24b7: lea    rdi,[r13+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_24bb:
	/* 0x24bb: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_24bf:
	/* 0x24bf: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_24c4:
	/* 0x24c4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24c9:
	/* 0x24c9: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_24ce:
	/* 0x24ce: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_24d1:
	/* 0x24d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24d3:
	/* 0x24d3: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24d8:
	/* 0x24d8: movzx  eax,WORD PTR [rcx+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_24dc:
	/* 0x24dc: movbe  WORD PTR [rcx+0x2],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_24e2:
	/* 0x24e2: mov    rbp,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_24ea:
	/* 0x24ea: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_24f0:
	/* 0x24f0: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_24f3:
	/* 0x24f3: jmp    3b44 <generic_rawtp_process_event+0x3b44> */
	return 15172ULL;
x86_l_24f8:
	/* 0x24f8: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24fb:
	/* 0x24fb: je     269a <generic_rawtp_process_event+0x269a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_269a;
	}
x86_l_2501:
	/* 0x2501: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2504:
	/* 0x2504: jne    2b30 <generic_rawtp_process_event+0x2b30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11056ULL;
	}
x86_l_250a:
	/* 0x250a: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_250d:
	/* 0x250d: add    rax,0x5e58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24152ULL);
x86_l_2513:
	/* 0x2513: jmp    26a3 <generic_rawtp_process_event+0x26a3> */
	goto x86_l_26a3;
x86_l_2518:
	/* 0x2518: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_251d:
	/* 0x251d: lea    rdi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2521:
	/* 0x2521: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2526:
	/* 0x2526: mov    edx,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 63ULL);
x86_l_252b:
	/* 0x252b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2530:
	/* 0x2530: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2535:
	/* 0x2535: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_253a:
	/* 0x253a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_253c:
	/* 0x253c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_253f:
	/* 0x253f: js     210f <generic_rawtp_process_event+0x210f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8463ULL;
	}
x86_l_2545:
	/* 0x2545: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_254a:
	/* 0x254a: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_254e:
	/* 0x254e: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2553:
	/* 0x2553: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2558:
	/* 0x2558: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_255d:
	/* 0x255d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2562:
	/* 0x2562: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2564:
	/* 0x2564: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2569:
	/* 0x2569: lea    rdi,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_256d:
	/* 0x256d: mov    edx,0x348 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 840ULL);
x86_l_2572:
	/* 0x2572: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2577:
	/* 0x2577: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_257a:
	/* 0x257a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_257f:
	/* 0x257f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2584:
	/* 0x2584: add    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 104ULL);
x86_l_2589:
	/* 0x2589: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_258e:
	/* 0x258e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2590:
	/* 0x2590: add    r15,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_2594:
	/* 0x2594: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2599:
	/* 0x2599: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_259e:
	/* 0x259e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25a3:
	/* 0x25a3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_25a8:
	/* 0x25a8: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_25ab:
	/* 0x25ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25ad:
	/* 0x25ad: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_25b3:
	/* 0x25b3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25b6:
	/* 0x25b6: jne    2efd <generic_rawtp_process_event+0x2efd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12029ULL;
	}
x86_l_25bc:
	/* 0x25bc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25be:
	/* 0x25be: cmp    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_25c3:
	/* 0x25c3: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_25c6:
	/* 0x25c6: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25cb:
	/* 0x25cb: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25cd:
	/* 0x25cd: jmp    2efd <generic_rawtp_process_event+0x2efd> */
	return 12029ULL;
x86_l_25d2:
	/* 0x25d2: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25d5:
	/* 0x25d5: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_25d8:
	/* 0x25d8: jmp    2f02 <generic_rawtp_process_event+0x2f02> */
	return 12034ULL;
x86_l_25dd:
	/* 0x25dd: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_25e1:
	/* 0x25e1: je     2e82 <generic_rawtp_process_event+0x2e82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11906ULL;
	}
x86_l_25e7:
	/* 0x25e7: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_25eb:
	/* 0x25eb: jne    2e8c <generic_rawtp_process_event+0x2e8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11916ULL;
	}
x86_l_25f1:
	/* 0x25f1: add    r15,0x5e58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24152ULL);
x86_l_25f8:
	/* 0x25f8: jmp    2e89 <generic_rawtp_process_event+0x2e89> */
	return 11913ULL;
x86_l_25fd:
	/* 0x25fd: lea    rdx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2601:
	/* 0x2601: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2606:
	/* 0x2606: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_260b:
	/* 0x260b: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2610:
	/* 0x2610: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2615:
	/* 0x2615: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2617:
	/* 0x2617: lea    rdx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_261b:
	/* 0x261b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2620:
	/* 0x2620: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2625:
	/* 0x2625: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2628:
	/* 0x2628: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_262d:
	/* 0x262d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_262f:
	/* 0x262f: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2634:
	/* 0x2634: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2638:
	/* 0x2638: lea    r12,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_263c:
	/* 0x263c: add    r15,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_2640:
	/* 0x2640: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2645:
	/* 0x2645: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_264a:
	/* 0x264a: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_264f:
	/* 0x264f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2652:
	/* 0x2652: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2654:
	/* 0x2654: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_2658:
	/* 0x2658: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_265d:
	/* 0x265d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2662:
	/* 0x2662: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2667:
	/* 0x2667: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_266a:
	/* 0x266a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_266c:
	/* 0x266c: movzx  eax,WORD PTR [rbp+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2670:
	/* 0x2670: movbe  WORD PTR [rbp+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2676:
	/* 0x2676: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_267c:
	/* 0x267c: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_267f:
	/* 0x267f: jmp    2f02 <generic_rawtp_process_event+0x2f02> */
	return 12034ULL;
x86_l_2684:
	/* 0x2684: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_2687:
	/* 0x2687: add    rax,0x5e60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24160ULL);
x86_l_268d:
	/* 0x268d: jmp    26a3 <generic_rawtp_process_event+0x26a3> */
	goto x86_l_26a3;
x86_l_268f:
	/* 0x268f: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_2692:
	/* 0x2692: add    rax,0x5e68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24168ULL);
x86_l_2698:
	/* 0x2698: jmp    26a3 <generic_rawtp_process_event+0x26a3> */
	goto x86_l_26a3;
x86_l_269a:
	/* 0x269a: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_269d:
	/* 0x269d: add    rax,0x5e50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24144ULL);
x86_l_26a3:
	/* 0x26a3: mov    r12,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26a6:
	/* 0x26a6: test   cl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_26a9:
	/* 0x26a9: jne    2b49 <generic_rawtp_process_event+0x2b49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11081ULL;
	}
x86_l_26af:
	/* 0x26af: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_26b2:
	/* 0x26b2: je     2bf1 <generic_rawtp_process_event+0x2bf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11249ULL;
	}
x86_l_26b8:
	/* 0x26b8: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_26bd:
	/* 0x26bd: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_26c3:
	/* 0x26c3: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_26c8:
	/* 0x26c8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26cd:
	/* 0x26cd: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26d2:
	/* 0x26d2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_26d7:
	/* 0x26d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26d9:
	/* 0x26d9: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_26de:
	/* 0x26de: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26e0:
	/* 0x26e0: js     2b23 <generic_rawtp_process_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11043ULL;
	}
x86_l_26e6:
	/* 0x26e6: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26eb:
	/* 0x26eb: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_26f0:
	/* 0x26f0: mov    rax,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_26f3:
	/* 0x26f3: mov    QWORD PTR [rsp+0x90],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_26fb:
	/* 0x26fb: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_2702:
	/* 0x2702: ja     2b23 <generic_rawtp_process_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11043ULL;
	}
x86_l_2708:
	/* 0x2708: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2710:
	/* 0x2710: lea    rcx,[rax+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2714:
	/* 0x2714: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2719:
	/* 0x2719: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_271c:
	/* 0x271c: lea    rdi,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2720:
	/* 0x2720: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2725:
	/* 0x2725: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_272a:
	/* 0x272a: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2732:
	/* 0x2732: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2737:
	/* 0x2737: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2739:
	/* 0x2739: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_273e:
	/* 0x273e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2740:
	/* 0x2740: js     2b23 <generic_rawtp_process_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11043ULL;
	}
x86_l_2746:
	/* 0x2746: cmp    r12,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 1ULL);
x86_l_274a:
	/* 0x274a: je     2bfb <generic_rawtp_process_event+0x2bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11259ULL;
	}
x86_l_2750:
	/* 0x2750: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2755:
	/* 0x2755: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2759:
	/* 0x2759: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_275e:
	/* 0x275e: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2764:
	/* 0x2764: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2769:
	/* 0x2769: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_276e:
	/* 0x276e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2773:
	/* 0x2773: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2775:
	/* 0x2775: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_277a:
	/* 0x277a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_277c:
	/* 0x277c: js     2b23 <generic_rawtp_process_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11043ULL;
	}
x86_l_2782:
	/* 0x2782: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2787:
	/* 0x2787: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_278c:
	/* 0x278c: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2794:
	/* 0x2794: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_279a:
	/* 0x279a: ja     2b23 <generic_rawtp_process_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11043ULL;
	}
x86_l_27a0:
	/* 0x27a0: add    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 144ULL);
x86_l_27a8:
	/* 0x27a8: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27ad:
	/* 0x27ad: mov    QWORD PTR [rsp+0xc0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_27b5:
	/* 0x27b5: lea    rdi,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_27b9:
	/* 0x27b9: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27be:
	/* 0x27be: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27c3:
	/* 0x27c3: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_27cb:
	/* 0x27cb: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27d0:
	/* 0x27d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27d2:
	/* 0x27d2: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_27d7:
	/* 0x27d7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27d9:
	/* 0x27d9: js     2b23 <generic_rawtp_process_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11043ULL;
	}
x86_l_27df:
	/* 0x27df: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_27e7:
	/* 0x27e7: add    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 144ULL);
x86_l_27ef:
	/* 0x27ef: cmp    r12,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 3ULL);
x86_l_27f3:
	/* 0x27f3: jb     2bfb <generic_rawtp_process_event+0x2bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11259ULL;
	}
x86_l_27f9:
	/* 0x27f9: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27fe:
	/* 0x27fe: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2802:
	/* 0x2802: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2807:
	/* 0x2807: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_280d:
	/* 0x280d: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2812:
	/* 0x2812: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2817:
	/* 0x2817: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_281c:
	/* 0x281c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_281e:
	/* 0x281e: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2823:
	/* 0x2823: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2825:
	/* 0x2825: js     2b23 <generic_rawtp_process_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11043ULL;
	}
x86_l_282b:
	/* 0x282b: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2830:
	/* 0x2830: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2835:
	/* 0x2835: mov    QWORD PTR [rsp+0xe0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_283d:
	/* 0x283d: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_2843:
	/* 0x2843: ja     2b23 <generic_rawtp_process_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11043ULL;
	}
x86_l_2849:
	/* 0x2849: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2851:
	/* 0x2851: add    rdi,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 192ULL);
x86_l_2859:
	/* 0x2859: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_285c:
	/* 0x285c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2862:
	/* 0x2862: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2867:
	/* 0x2867: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_286c:
	/* 0x286c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2871:
	/* 0x2871: mov    rsi,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2879:
	/* 0x2879: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_287e:
	/* 0x287e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2880:
	/* 0x2880: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2885:
	/* 0x2885: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2887:
	/* 0x2887: js     2b23 <generic_rawtp_process_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11043ULL;
	}
x86_l_288d:
	/* 0x288d: mov    rax,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2895:
	/* 0x2895: add    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 144ULL);
x86_l_289d:
	/* 0x289d: cmp    r12,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 3ULL);
x86_l_28a1:
	/* 0x28a1: je     2bfb <generic_rawtp_process_event+0x2bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11259ULL;
	}
x86_l_28a7:
	/* 0x28a7: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28ac:
	/* 0x28ac: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28b0:
	/* 0x28b0: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_28b5:
	/* 0x28b5: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_28bb:
	/* 0x28bb: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_28c0:
	/* 0x28c0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28c5:
	/* 0x28c5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_28ca:
	/* 0x28ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28cc:
	/* 0x28cc: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_28d1:
	/* 0x28d1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28d3:
	/* 0x28d3: js     2b23 <generic_rawtp_process_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11043ULL;
	}
x86_l_28d9:
	/* 0x28d9: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28de:
	/* 0x28de: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_28e3:
	/* 0x28e3: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_28eb:
	/* 0x28eb: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_28f1:
	/* 0x28f1: ja     2b23 <generic_rawtp_process_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11043ULL;
	}
x86_l_28f7:
	/* 0x28f7: mov    rdi,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_28ff:
	/* 0x28ff: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2902:
	/* 0x2902: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_2905:
	/* 0x2905: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_290b:
	/* 0x290b: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2910:
	/* 0x2910: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2915:
	/* 0x2915: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_291a:
	/* 0x291a: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2922:
	/* 0x2922: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2927:
	/* 0x2927: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2929:
	/* 0x2929: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_292e:
	/* 0x292e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2930:
	/* 0x2930: js     2b23 <generic_rawtp_process_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11043ULL;
	}
x86_l_2936:
	/* 0x2936: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_293e:
	/* 0x293e: add    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 144ULL);
x86_l_2946:
	/* 0x2946: cmp    r12,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 5ULL);
x86_l_294a:
	/* 0x294a: jb     2bfb <generic_rawtp_process_event+0x2bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11259ULL;
	}
x86_l_2950:
	/* 0x2950: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2955:
	/* 0x2955: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2959:
	/* 0x2959: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_295e:
	/* 0x295e: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2964:
	/* 0x2964: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2969:
	/* 0x2969: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_296e:
	/* 0x296e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2973:
	/* 0x2973: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2975:
	/* 0x2975: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_297a:
	/* 0x297a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_297c:
	/* 0x297c: js     2b23 <generic_rawtp_process_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11043ULL;
	}
x86_l_2982:
	/* 0x2982: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2987:
	/* 0x2987: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_298c:
	/* 0x298c: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2994:
	/* 0x2994: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_299a:
	/* 0x299a: ja     2b23 <generic_rawtp_process_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11043ULL;
	}
x86_l_29a0:
	/* 0x29a0: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_29a8:
	/* 0x29a8: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29ab:
	/* 0x29ab: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_29ae:
	/* 0x29ae: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_29b4:
	/* 0x29b4: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_29b9:
	/* 0x29b9: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29be:
	/* 0x29be: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29c3:
	/* 0x29c3: mov    rsi,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_29cb:
	/* 0x29cb: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29d0:
	/* 0x29d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29d2:
	/* 0x29d2: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_29d7:
	/* 0x29d7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29d9:
	/* 0x29d9: js     2b23 <generic_rawtp_process_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11043ULL;
	}
x86_l_29df:
	/* 0x29df: mov    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_29e7:
	/* 0x29e7: add    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 144ULL);
x86_l_29ef:
	/* 0x29ef: cmp    r12,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 5ULL);
x86_l_29f3:
	/* 0x29f3: je     2bfb <generic_rawtp_process_event+0x2bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11259ULL;
	}
	return 10745ULL;
}

static __noinline __u64 tetragon_bpf_generic_rawtp_generic_rawtp_process_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10745ULL: goto x86_l_29f9;
	case 10750ULL: goto x86_l_29fe;
	case 10754ULL: goto x86_l_2a02;
	case 10759ULL: goto x86_l_2a07;
	case 10765ULL: goto x86_l_2a0d;
	case 10770ULL: goto x86_l_2a12;
	case 10775ULL: goto x86_l_2a17;
	case 10780ULL: goto x86_l_2a1c;
	case 10782ULL: goto x86_l_2a1e;
	case 10787ULL: goto x86_l_2a23;
	case 10789ULL: goto x86_l_2a25;
	case 10795ULL: goto x86_l_2a2b;
	case 10800ULL: goto x86_l_2a30;
	case 10805ULL: goto x86_l_2a35;
	case 10813ULL: goto x86_l_2a3d;
	case 10819ULL: goto x86_l_2a43;
	case 10825ULL: goto x86_l_2a49;
	case 10833ULL: goto x86_l_2a51;
	case 10836ULL: goto x86_l_2a54;
	case 10839ULL: goto x86_l_2a57;
	case 10845ULL: goto x86_l_2a5d;
	case 10850ULL: goto x86_l_2a62;
	case 10855ULL: goto x86_l_2a67;
	case 10860ULL: goto x86_l_2a6c;
	case 10868ULL: goto x86_l_2a74;
	case 10873ULL: goto x86_l_2a79;
	case 10875ULL: goto x86_l_2a7b;
	case 10880ULL: goto x86_l_2a80;
	case 10882ULL: goto x86_l_2a82;
	case 10888ULL: goto x86_l_2a88;
	case 10896ULL: goto x86_l_2a90;
	case 10904ULL: goto x86_l_2a98;
	case 10908ULL: goto x86_l_2a9c;
	case 10914ULL: goto x86_l_2aa2;
	case 10919ULL: goto x86_l_2aa7;
	case 10923ULL: goto x86_l_2aab;
	case 10928ULL: goto x86_l_2ab0;
	case 10934ULL: goto x86_l_2ab6;
	case 10939ULL: goto x86_l_2abb;
	case 10944ULL: goto x86_l_2ac0;
	case 10949ULL: goto x86_l_2ac5;
	case 10951ULL: goto x86_l_2ac7;
	case 10956ULL: goto x86_l_2acc;
	case 10958ULL: goto x86_l_2ace;
	case 10960ULL: goto x86_l_2ad0;
	case 10965ULL: goto x86_l_2ad5;
	case 10970ULL: goto x86_l_2ada;
	case 10977ULL: goto x86_l_2ae1;
	case 10979ULL: goto x86_l_2ae3;
	case 10987ULL: goto x86_l_2aeb;
	case 10990ULL: goto x86_l_2aee;
	case 10996ULL: goto x86_l_2af4;
	case 11001ULL: goto x86_l_2af9;
	case 11006ULL: goto x86_l_2afe;
	case 11011ULL: goto x86_l_2b03;
	case 11016ULL: goto x86_l_2b08;
	case 11019ULL: goto x86_l_2b0b;
	case 11021ULL: goto x86_l_2b0d;
	case 11026ULL: goto x86_l_2b12;
	case 11028ULL: goto x86_l_2b14;
	case 11030ULL: goto x86_l_2b16;
	case 11038ULL: goto x86_l_2b1e;
	case 11043ULL: goto x86_l_2b23;
	case 11048ULL: goto x86_l_2b28;
	case 11051ULL: goto x86_l_2b2b;
	case 11056ULL: goto x86_l_2b30;
	case 11059ULL: goto x86_l_2b33;
	case 11064ULL: goto x86_l_2b38;
	case 11072ULL: goto x86_l_2b40;
	case 11075ULL: goto x86_l_2b43;
	case 11081ULL: goto x86_l_2b49;
	case 11086ULL: goto x86_l_2b4e;
	case 11088ULL: goto x86_l_2b50;
	case 11092ULL: goto x86_l_2b54;
	case 11094ULL: goto x86_l_2b56;
	case 11098ULL: goto x86_l_2b5a;
	case 11102ULL: goto x86_l_2b5e;
	case 11106ULL: goto x86_l_2b62;
	case 11111ULL: goto x86_l_2b67;
	case 11116ULL: goto x86_l_2b6c;
	case 11121ULL: goto x86_l_2b71;
	case 11126ULL: goto x86_l_2b76;
	case 11131ULL: goto x86_l_2b7b;
	case 11136ULL: goto x86_l_2b80;
	case 11143ULL: goto x86_l_2b87;
	case 11145ULL: goto x86_l_2b89;
	case 11150ULL: goto x86_l_2b8e;
	case 11155ULL: goto x86_l_2b93;
	case 11160ULL: goto x86_l_2b98;
	case 11162ULL: goto x86_l_2b9a;
	case 11164ULL: goto x86_l_2b9c;
	case 11167ULL: goto x86_l_2b9f;
	case 11173ULL: goto x86_l_2ba5;
	case 11175ULL: goto x86_l_2ba7;
	case 11183ULL: goto x86_l_2baf;
	case 11193ULL: goto x86_l_2bb9;
	case 11203ULL: goto x86_l_2bc3;
	case 11211ULL: goto x86_l_2bcb;
	case 11218ULL: goto x86_l_2bd2;
	case 11226ULL: goto x86_l_2bda;
	case 11231ULL: goto x86_l_2bdf;
	case 11233ULL: goto x86_l_2be1;
	case 11236ULL: goto x86_l_2be4;
	case 11242ULL: goto x86_l_2bea;
	case 11244ULL: goto x86_l_2bec;
	case 11249ULL: goto x86_l_2bf1;
	case 11251ULL: goto x86_l_2bf3;
	case 11259ULL: goto x86_l_2bfb;
	case 11264ULL: goto x86_l_2c00;
	case 11272ULL: goto x86_l_2c08;
	case 11276ULL: goto x86_l_2c0c;
	case 11281ULL: goto x86_l_2c11;
	case 11285ULL: goto x86_l_2c15;
	case 11290ULL: goto x86_l_2c1a;
	case 11293ULL: goto x86_l_2c1d;
	case 11299ULL: goto x86_l_2c23;
	case 11302ULL: goto x86_l_2c26;
	case 11308ULL: goto x86_l_2c2c;
	case 11313ULL: goto x86_l_2c31;
	case 11319ULL: goto x86_l_2c37;
	case 11326ULL: goto x86_l_2c3e;
	case 11330ULL: goto x86_l_2c42;
	case 11335ULL: goto x86_l_2c47;
	case 11346ULL: goto x86_l_2c52;
	case 11353ULL: goto x86_l_2c59;
	case 11355ULL: goto x86_l_2c5b;
	case 11363ULL: goto x86_l_2c63;
	case 11371ULL: goto x86_l_2c6b;
	case 11376ULL: goto x86_l_2c70;
	case 11378ULL: goto x86_l_2c72;
	case 11380ULL: goto x86_l_2c74;
	case 11387ULL: goto x86_l_2c7b;
	case 11393ULL: goto x86_l_2c81;
	case 11398ULL: goto x86_l_2c86;
	case 11406ULL: goto x86_l_2c8e;
	case 11413ULL: goto x86_l_2c95;
	case 11415ULL: goto x86_l_2c97;
	case 11423ULL: goto x86_l_2c9f;
	case 11428ULL: goto x86_l_2ca4;
	case 11433ULL: goto x86_l_2ca9;
	case 11435ULL: goto x86_l_2cab;
	case 11437ULL: goto x86_l_2cad;
	case 11442ULL: goto x86_l_2cb2;
	case 11449ULL: goto x86_l_2cb9;
	case 11455ULL: goto x86_l_2cbf;
	case 11460ULL: goto x86_l_2cc4;
	case 11465ULL: goto x86_l_2cc9;
	case 11472ULL: goto x86_l_2cd0;
	case 11477ULL: goto x86_l_2cd5;
	case 11481ULL: goto x86_l_2cd9;
	case 11486ULL: goto x86_l_2cde;
	case 11491ULL: goto x86_l_2ce3;
	case 11496ULL: goto x86_l_2ce8;
	case 11501ULL: goto x86_l_2ced;
	case 11503ULL: goto x86_l_2cef;
	case 11508ULL: goto x86_l_2cf4;
	case 11513ULL: goto x86_l_2cf9;
	case 11519ULL: goto x86_l_2cff;
	case 11523ULL: goto x86_l_2d03;
	case 11528ULL: goto x86_l_2d08;
	case 11533ULL: goto x86_l_2d0d;
	case 11538ULL: goto x86_l_2d12;
	case 11543ULL: goto x86_l_2d17;
	case 11546ULL: goto x86_l_2d1a;
	case 11548ULL: goto x86_l_2d1c;
	case 11553ULL: goto x86_l_2d21;
	case 11558ULL: goto x86_l_2d26;
	case 11562ULL: goto x86_l_2d2a;
	case 11567ULL: goto x86_l_2d2f;
	case 11572ULL: goto x86_l_2d34;
	case 11577ULL: goto x86_l_2d39;
	case 11579ULL: goto x86_l_2d3b;
	case 11584ULL: goto x86_l_2d40;
	case 11590ULL: goto x86_l_2d46;
	case 11598ULL: goto x86_l_2d4e;
	case 11603ULL: goto x86_l_2d53;
	case 11608ULL: goto x86_l_2d58;
	case 11613ULL: goto x86_l_2d5d;
	case 11615ULL: goto x86_l_2d5f;
	case 11623ULL: goto x86_l_2d67;
	case 11629ULL: goto x86_l_2d6d;
	case 11634ULL: goto x86_l_2d72;
	case 11639ULL: goto x86_l_2d77;
	case 11644ULL: goto x86_l_2d7c;
	case 11649ULL: goto x86_l_2d81;
	case 11654ULL: goto x86_l_2d86;
	case 11657ULL: goto x86_l_2d89;
	case 11659ULL: goto x86_l_2d8b;
	case 11664ULL: goto x86_l_2d90;
	case 11670ULL: goto x86_l_2d96;
	case 11678ULL: goto x86_l_2d9e;
	case 11683ULL: goto x86_l_2da3;
	case 11688ULL: goto x86_l_2da8;
	case 11693ULL: goto x86_l_2dad;
	case 11696ULL: goto x86_l_2db0;
	case 11698ULL: goto x86_l_2db2;
	case 11702ULL: goto x86_l_2db6;
	case 11707ULL: goto x86_l_2dbb;
	case 11712ULL: goto x86_l_2dc0;
	case 11717ULL: goto x86_l_2dc5;
	case 11722ULL: goto x86_l_2dca;
	case 11725ULL: goto x86_l_2dcd;
	case 11727ULL: goto x86_l_2dcf;
	case 11732ULL: goto x86_l_2dd4;
	case 11737ULL: goto x86_l_2dd9;
	case 11741ULL: goto x86_l_2ddd;
	case 11744ULL: goto x86_l_2de0;
	case 11749ULL: goto x86_l_2de5;
	case 11751ULL: goto x86_l_2de7;
	case 11753ULL: goto x86_l_2de9;
	case 11756ULL: goto x86_l_2dec;
	case 11759ULL: goto x86_l_2def;
	case 11764ULL: goto x86_l_2df4;
	case 11766ULL: goto x86_l_2df6;
	case 11769ULL: goto x86_l_2df9;
	case 11773ULL: goto x86_l_2dfd;
	case 11775ULL: goto x86_l_2dff;
	case 11779ULL: goto x86_l_2e03;
	case 11781ULL: goto x86_l_2e05;
	case 11784ULL: goto x86_l_2e08;
	case 11786ULL: goto x86_l_2e0a;
	case 11790ULL: goto x86_l_2e0e;
	case 11793ULL: goto x86_l_2e11;
	case 11799ULL: goto x86_l_2e17;
	case 11805ULL: goto x86_l_2e1d;
	case 11811ULL: goto x86_l_2e23;
	case 11814ULL: goto x86_l_2e26;
	case 11816ULL: goto x86_l_2e28;
	case 11821ULL: goto x86_l_2e2d;
	case 11823ULL: goto x86_l_2e2f;
	case 11826ULL: goto x86_l_2e32;
	case 11830ULL: goto x86_l_2e36;
	case 11833ULL: goto x86_l_2e39;
	case 11836ULL: goto x86_l_2e3c;
	case 11839ULL: goto x86_l_2e3f;
	case 11844ULL: goto x86_l_2e44;
	case 11846ULL: goto x86_l_2e46;
	case 11851ULL: goto x86_l_2e4b;
	case 11854ULL: goto x86_l_2e4e;
	case 11860ULL: goto x86_l_2e54;
	case 11868ULL: goto x86_l_2e5c;
	case 11873ULL: goto x86_l_2e61;
	case 11878ULL: goto x86_l_2e66;
	case 11883ULL: goto x86_l_2e6b;
	case 11888ULL: goto x86_l_2e70;
	case 11895ULL: goto x86_l_2e77;
	case 11897ULL: goto x86_l_2e79;
	case 11904ULL: goto x86_l_2e80;
	case 11906ULL: goto x86_l_2e82;
	case 11913ULL: goto x86_l_2e89;
	case 11916ULL: goto x86_l_2e8c;
	case 11921ULL: goto x86_l_2e91;
	case 11929ULL: goto x86_l_2e99;
	case 11934ULL: goto x86_l_2e9e;
	case 11939ULL: goto x86_l_2ea3;
	case 11944ULL: goto x86_l_2ea8;
	case 11950ULL: goto x86_l_2eae;
	case 11955ULL: goto x86_l_2eb3;
	case 11957ULL: goto x86_l_2eb5;
	case 11965ULL: goto x86_l_2ebd;
	case 11972ULL: goto x86_l_2ec4;
	case 11978ULL: goto x86_l_2eca;
	case 11982ULL: goto x86_l_2ece;
	case 11986ULL: goto x86_l_2ed2;
	case 11991ULL: goto x86_l_2ed7;
	case 11996ULL: goto x86_l_2edc;
	case 11999ULL: goto x86_l_2edf;
	case 12001ULL: goto x86_l_2ee1;
	case 12003ULL: goto x86_l_2ee3;
	case 12005ULL: goto x86_l_2ee5;
	case 12009ULL: goto x86_l_2ee9;
	case 12013ULL: goto x86_l_2eed;
	case 12017ULL: goto x86_l_2ef1;
	case 12020ULL: goto x86_l_2ef4;
	case 12022ULL: goto x86_l_2ef6;
	case 12029ULL: goto x86_l_2efd;
	case 12034ULL: goto x86_l_2f02;
	case 12039ULL: goto x86_l_2f07;
	case 12044ULL: goto x86_l_2f0c;
	case 12052ULL: goto x86_l_2f14;
	case 12057ULL: goto x86_l_2f19;
	case 12062ULL: goto x86_l_2f1e;
	case 12069ULL: goto x86_l_2f25;
	case 12074ULL: goto x86_l_2f2a;
	case 12078ULL: goto x86_l_2f2e;
	case 12082ULL: goto x86_l_2f32;
	case 12087ULL: goto x86_l_2f37;
	case 12091ULL: goto x86_l_2f3b;
	case 12097ULL: goto x86_l_2f41;
	case 12107ULL: goto x86_l_2f4b;
	case 12111ULL: goto x86_l_2f4f;
	case 12117ULL: goto x86_l_2f55;
	case 12121ULL: goto x86_l_2f59;
	case 12124ULL: goto x86_l_2f5c;
	case 12129ULL: goto x86_l_2f61;
	case 12132ULL: goto x86_l_2f64;
	case 12137ULL: goto x86_l_2f69;
	case 12142ULL: goto x86_l_2f6e;
	case 12150ULL: goto x86_l_2f76;
	case 12154ULL: goto x86_l_2f7a;
	case 12157ULL: goto x86_l_2f7d;
	case 12162ULL: goto x86_l_2f82;
	case 12164ULL: goto x86_l_2f84;
	case 12167ULL: goto x86_l_2f87;
	case 12173ULL: goto x86_l_2f8d;
	case 12178ULL: goto x86_l_2f92;
	case 12181ULL: goto x86_l_2f95;
	case 12183ULL: goto x86_l_2f97;
	case 12185ULL: goto x86_l_2f99;
	case 12187ULL: goto x86_l_2f9b;
	case 12190ULL: goto x86_l_2f9e;
	case 12192ULL: goto x86_l_2fa0;
	case 12195ULL: goto x86_l_2fa3;
	case 12201ULL: goto x86_l_2fa9;
	case 12208ULL: goto x86_l_2fb0;
	case 12212ULL: goto x86_l_2fb4;
	case 12217ULL: goto x86_l_2fb9;
	case 12220ULL: goto x86_l_2fbc;
	case 12226ULL: goto x86_l_2fc2;
	case 12229ULL: goto x86_l_2fc5;
	case 12231ULL: goto x86_l_2fc7;
	case 12236ULL: goto x86_l_2fcc;
	case 12242ULL: goto x86_l_2fd2;
	case 12249ULL: goto x86_l_2fd9;
	case 12253ULL: goto x86_l_2fdd;
	case 12258ULL: goto x86_l_2fe2;
	case 12263ULL: goto x86_l_2fe7;
	case 12270ULL: goto x86_l_2fee;
	case 12275ULL: goto x86_l_2ff3;
	case 12280ULL: goto x86_l_2ff8;
	case 12285ULL: goto x86_l_2ffd;
	case 12290ULL: goto x86_l_3002;
	case 12294ULL: goto x86_l_3006;
	case 12299ULL: goto x86_l_300b;
	case 12304ULL: goto x86_l_3010;
	case 12309ULL: goto x86_l_3015;
	case 12314ULL: goto x86_l_301a;
	case 12316ULL: goto x86_l_301c;
	case 12321ULL: goto x86_l_3021;
	case 12326ULL: goto x86_l_3026;
	case 12332ULL: goto x86_l_302c;
	case 12336ULL: goto x86_l_3030;
	case 12341ULL: goto x86_l_3035;
	case 12346ULL: goto x86_l_303a;
	case 12351ULL: goto x86_l_303f;
	case 12356ULL: goto x86_l_3044;
	case 12359ULL: goto x86_l_3047;
	case 12361ULL: goto x86_l_3049;
	case 12366ULL: goto x86_l_304e;
	case 12371ULL: goto x86_l_3053;
	case 12375ULL: goto x86_l_3057;
	case 12380ULL: goto x86_l_305c;
	case 12385ULL: goto x86_l_3061;
	case 12390ULL: goto x86_l_3066;
	case 12392ULL: goto x86_l_3068;
	case 12397ULL: goto x86_l_306d;
	case 12403ULL: goto x86_l_3073;
	case 12411ULL: goto x86_l_307b;
	case 12416ULL: goto x86_l_3080;
	case 12421ULL: goto x86_l_3085;
	case 12426ULL: goto x86_l_308a;
	case 12428ULL: goto x86_l_308c;
	case 12436ULL: goto x86_l_3094;
	case 12442ULL: goto x86_l_309a;
	case 12447ULL: goto x86_l_309f;
	case 12452ULL: goto x86_l_30a4;
	case 12457ULL: goto x86_l_30a9;
	case 12462ULL: goto x86_l_30ae;
	case 12467ULL: goto x86_l_30b3;
	case 12470ULL: goto x86_l_30b6;
	case 12472ULL: goto x86_l_30b8;
	case 12477ULL: goto x86_l_30bd;
	case 12483ULL: goto x86_l_30c3;
	case 12491ULL: goto x86_l_30cb;
	case 12496ULL: goto x86_l_30d0;
	case 12501ULL: goto x86_l_30d5;
	case 12506ULL: goto x86_l_30da;
	case 12509ULL: goto x86_l_30dd;
	case 12511ULL: goto x86_l_30df;
	case 12515ULL: goto x86_l_30e3;
	case 12520ULL: goto x86_l_30e8;
	case 12525ULL: goto x86_l_30ed;
	case 12530ULL: goto x86_l_30f2;
	case 12535ULL: goto x86_l_30f7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_29f9:
	/* 0x29f9: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29fe:
	/* 0x29fe: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2a02:
	/* 0x2a02: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a07:
	/* 0x2a07: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2a0d:
	/* 0x2a0d: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2a12:
	/* 0x2a12: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a17:
	/* 0x2a17: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2a1c:
	/* 0x2a1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a1e:
	/* 0x2a1e: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2a23:
	/* 0x2a23: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a25:
	/* 0x2a25: js     2b23 <generic_rawtp_process_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2b23;
	}
x86_l_2a2b:
	/* 0x2a2b: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a30:
	/* 0x2a30: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2a35:
	/* 0x2a35: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2a3d:
	/* 0x2a3d: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_2a43:
	/* 0x2a43: ja     2b23 <generic_rawtp_process_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2b23;
	}
x86_l_2a49:
	/* 0x2a49: mov    rdi,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2a51:
	/* 0x2a51: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a54:
	/* 0x2a54: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_2a57:
	/* 0x2a57: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2a5d:
	/* 0x2a5d: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2a62:
	/* 0x2a62: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a67:
	/* 0x2a67: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a6c:
	/* 0x2a6c: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2a74:
	/* 0x2a74: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a79:
	/* 0x2a79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a7b:
	/* 0x2a7b: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2a80:
	/* 0x2a80: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a82:
	/* 0x2a82: js     2b23 <generic_rawtp_process_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2b23;
	}
x86_l_2a88:
	/* 0x2a88: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2a90:
	/* 0x2a90: add    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 144ULL);
x86_l_2a98:
	/* 0x2a98: cmp    r12,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 7ULL);
x86_l_2a9c:
	/* 0x2a9c: jb     2bfb <generic_rawtp_process_event+0x2bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2bfb;
	}
x86_l_2aa2:
	/* 0x2aa2: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2aa7:
	/* 0x2aa7: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_2aab:
	/* 0x2aab: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ab0:
	/* 0x2ab0: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2ab6:
	/* 0x2ab6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2abb:
	/* 0x2abb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ac0:
	/* 0x2ac0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2ac5:
	/* 0x2ac5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ac7:
	/* 0x2ac7: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2acc:
	/* 0x2acc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ace:
	/* 0x2ace: js     2b23 <generic_rawtp_process_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2b23;
	}
x86_l_2ad0:
	/* 0x2ad0: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ad5:
	/* 0x2ad5: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2ada:
	/* 0x2ada: cmp    r12,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 4094ULL);
x86_l_2ae1:
	/* 0x2ae1: ja     2b23 <generic_rawtp_process_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2b23;
	}
x86_l_2ae3:
	/* 0x2ae3: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2aeb:
	/* 0x2aeb: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2aee:
	/* 0x2aee: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2af4:
	/* 0x2af4: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2af9:
	/* 0x2af9: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2afe:
	/* 0x2afe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b03:
	/* 0x2b03: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b08:
	/* 0x2b08: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2b0b:
	/* 0x2b0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b0d:
	/* 0x2b0d: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2b12:
	/* 0x2b12: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b14:
	/* 0x2b14: js     2b23 <generic_rawtp_process_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2b23;
	}
x86_l_2b16:
	/* 0x2b16: add    QWORD PTR [rsp+0x90],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 144ULL);
x86_l_2b1e:
	/* 0x2b1e: jmp    2bfb <generic_rawtp_process_event+0x2bfb> */
	goto x86_l_2bfb;
x86_l_2b23:
	/* 0x2b23: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b28:
	/* 0x2b28: mov    DWORD PTR [rax+rbp*1],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2b2b:
	/* 0x2b2b: jmp    2efd <generic_rawtp_process_event+0x2efd> */
	goto x86_l_2efd;
x86_l_2b30:
	/* 0x2b30: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b33:
	/* 0x2b33: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_2b38:
	/* 0x2b38: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2b40:
	/* 0x2b40: test   cl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_2b43:
	/* 0x2b43: je     2bfb <generic_rawtp_process_event+0x2bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bfb;
	}
x86_l_2b49:
	/* 0x2b49: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2b4e:
	/* 0x2b4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b50:
	/* 0x2b50: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_2b54:
	/* 0x2b54: jne    2b5a <generic_rawtp_process_event+0x2b5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b5a;
	}
x86_l_2b56:
	/* 0x2b56: mov    rax,QWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b5a:
	/* 0x2b5a: mov    rcx,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b5e:
	/* 0x2b5e: mov    rdx,QWORD PTR [r13+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2b62:
	/* 0x2b62: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b67:
	/* 0x2b67: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b6c:
	/* 0x2b6c: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b71:
	/* 0x2b71: mov    QWORD PTR [rsp+0x38],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b76:
	/* 0x2b76: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2b7b:
	/* 0x2b7b: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2b80:
	/* 0x2b80: mov    rdi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_2b87:
	/* 0x2b87: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b89:
	/* 0x2b89: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2b8e:
	/* 0x2b8e: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b93:
	/* 0x2b93: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2b98:
	/* 0x2b98: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b9a:
	/* 0x2b9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b9c:
	/* 0x2b9c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b9f:
	/* 0x2b9f: je     2cad <generic_rawtp_process_event+0x2cad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cad;
	}
x86_l_2ba5:
	/* 0x2ba5: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2ba7:
	/* 0x2ba7: mov    WORD PTR [rsp+0xb0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2baf:
	/* 0x2baf: mov    WORD PTR [rsp+0xb2],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 764504178693ULL);
x86_l_2bb9:
	/* 0x2bb9: movabs rax,0x200000057 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934679ULL);
x86_l_2bc3:
	/* 0x2bc3: mov    QWORD PTR [rsp+0xb4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_2bcb:
	/* 0x2bcb: mov    rdi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2bd2:
	/* 0x2bd2: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2bda:
	/* 0x2bda: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bdf:
	/* 0x2bdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2be1:
	/* 0x2be1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2be4:
	/* 0x2be4: je     2c86 <generic_rawtp_process_event+0x2c86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c86;
	}
x86_l_2bea:
	/* 0x2bea: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2bec:
	/* 0x2bec: jmp    2cad <generic_rawtp_process_event+0x2cad> */
	goto x86_l_2cad;
x86_l_2bf1:
	/* 0x2bf1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bf3:
	/* 0x2bf3: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2bfb:
	/* 0x2bfb: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c00:
	/* 0x2c00: mov    r15,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2c08:
	/* 0x2c08: mov    DWORD PTR [rax+rbp*1],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2c0c:
	/* 0x2c0c: mov    DWORD PTR [rax+rbp*1+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 4ULL);
x86_l_2c11:
	/* 0x2c11: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c15:
	/* 0x2c15: jmp    2efd <generic_rawtp_process_event+0x2efd> */
	goto x86_l_2efd;
x86_l_2c1a:
	/* 0x2c1a: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2c1d:
	/* 0x2c1d: je     2f19 <generic_rawtp_process_event+0x2f19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f19;
	}
x86_l_2c23:
	/* 0x2c23: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2c26:
	/* 0x2c26: je     2cc4 <generic_rawtp_process_event+0x2cc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cc4;
	}
x86_l_2c2c:
	/* 0x2c2c: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2c31:
	/* 0x2c31: jne    2ff8 <generic_rawtp_process_event+0x2ff8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ff8;
	}
x86_l_2c37:
	/* 0x2c37: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2c3e:
	/* 0x2c3e: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2c42:
	/* 0x2c42: jmp    2f2a <generic_rawtp_process_event+0x2f2a> */
	goto x86_l_2f2a;
x86_l_2c47:
	/* 0x2c47: mov    DWORD PTR [rsp+0x80],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813889ULL);
x86_l_2c52:
	/* 0x2c52: mov    rdi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2c59:
	/* 0x2c59: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c5b:
	/* 0x2c5b: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2c63:
	/* 0x2c63: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2c6b:
	/* 0x2c6b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c70:
	/* 0x2c70: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c72:
	/* 0x2c72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c74:
	/* 0x2c74: mov    DWORD PTR [rbp+0x0],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967292ULL);
x86_l_2c7b:
	/* 0x2c7b: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2c81:
	/* 0x2c81: jmp    2efd <generic_rawtp_process_event+0x2efd> */
	goto x86_l_2efd;
x86_l_2c86:
	/* 0x2c86: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2c8e:
	/* 0x2c8e: mov    rdi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2c95:
	/* 0x2c95: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c97:
	/* 0x2c97: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2c9f:
	/* 0x2c9f: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ca4:
	/* 0x2ca4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ca9:
	/* 0x2ca9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cab:
	/* 0x2cab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cad:
	/* 0x2cad: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cb2:
	/* 0x2cb2: mov    DWORD PTR [rax+rbp*1],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 4294967292ULL);
x86_l_2cb9:
	/* 0x2cb9: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2cbf:
	/* 0x2cbf: jmp    2efd <generic_rawtp_process_event+0x2efd> */
	goto x86_l_2efd;
x86_l_2cc4:
	/* 0x2cc4: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2cc9:
	/* 0x2cc9: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2cd0:
	/* 0x2cd0: jmp    2f25 <generic_rawtp_process_event+0x2f25> */
	goto x86_l_2f25;
x86_l_2cd5:
	/* 0x2cd5: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cd9:
	/* 0x2cd9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cde:
	/* 0x2cde: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ce3:
	/* 0x2ce3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ce8:
	/* 0x2ce8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ced:
	/* 0x2ced: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cef:
	/* 0x2cef: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2cf4:
	/* 0x2cf4: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2cf9:
	/* 0x2cf9: je     974 <generic_rawtp_process_event+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2420ULL;
	}
x86_l_2cff:
	/* 0x2cff: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2d03:
	/* 0x2d03: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d08:
	/* 0x2d08: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d0d:
	/* 0x2d0d: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d12:
	/* 0x2d12: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d17:
	/* 0x2d17: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2d1a:
	/* 0x2d1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d1c:
	/* 0x2d1c: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d21:
	/* 0x2d21: mov    QWORD PTR [rsp+0x50],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2d26:
	/* 0x2d26: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d2a:
	/* 0x2d2a: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2d2f:
	/* 0x2d2f: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d34:
	/* 0x2d34: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2d39:
	/* 0x2d39: jne    2d46 <generic_rawtp_process_event+0x2d46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d46;
	}
x86_l_2d3b:
	/* 0x2d3b: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2d40:
	/* 0x2d40: je     974 <generic_rawtp_process_event+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2420ULL;
	}
x86_l_2d46:
	/* 0x2d46: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2d4e:
	/* 0x2d4e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d53:
	/* 0x2d53: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d58:
	/* 0x2d58: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d5d:
	/* 0x2d5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d5f:
	/* 0x2d5f: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_2d67:
	/* 0x2d67: je     3002 <generic_rawtp_process_event+0x3002> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3002;
	}
x86_l_2d6d:
	/* 0x2d6d: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d72:
	/* 0x2d72: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d77:
	/* 0x2d77: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d7c:
	/* 0x2d7c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d81:
	/* 0x2d81: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d86:
	/* 0x2d86: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2d89:
	/* 0x2d89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d8b:
	/* 0x2d8b: cmp    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d90:
	/* 0x2d90: je     3002 <generic_rawtp_process_event+0x3002> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3002;
	}
x86_l_2d96:
	/* 0x2d96: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2d9e:
	/* 0x2d9e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2da3:
	/* 0x2da3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2da8:
	/* 0x2da8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dad:
	/* 0x2dad: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2db0:
	/* 0x2db0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2db2:
	/* 0x2db2: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2db6:
	/* 0x2db6: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2dbb:
	/* 0x2dbb: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2dc0:
	/* 0x2dc0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2dc5:
	/* 0x2dc5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2dca:
	/* 0x2dca: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2dcd:
	/* 0x2dcd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dcf:
	/* 0x2dcf: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2dd4:
	/* 0x2dd4: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2dd9:
	/* 0x2dd9: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_2ddd:
	/* 0x2ddd: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2de0:
	/* 0x2de0: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2de5:
	/* 0x2de5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2de7:
	/* 0x2de7: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_2de9:
	/* 0x2de9: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2dec:
	/* 0x2dec: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2def:
	/* 0x2def: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_2df4:
	/* 0x2df4: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2df6:
	/* 0x2df6: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2df9:
	/* 0x2df9: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_2dfd:
	/* 0x2dfd: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_2dff:
	/* 0x2dff: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_2e03:
	/* 0x2e03: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2e05:
	/* 0x2e05: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_2e08:
	/* 0x2e08: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e0a:
	/* 0x2e0a: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2e0e:
	/* 0x2e0e: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2e11:
	/* 0x2e11: jb     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2425ULL;
	}
x86_l_2e17:
	/* 0x2e17: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_2e1d:
	/* 0x2e1d: ja     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2425ULL;
	}
x86_l_2e23:
	/* 0x2e23: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2e26:
	/* 0x2e26: jbe    2e2d <generic_rawtp_process_event+0x2e2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2e2d;
	}
x86_l_2e28:
	/* 0x2e28: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2e2d:
	/* 0x2e2d: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e2f:
	/* 0x2e2f: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2e32:
	/* 0x2e32: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_2e36:
	/* 0x2e36: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e39:
	/* 0x2e39: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e3c:
	/* 0x2e3c: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e3f:
	/* 0x2e3f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e44:
	/* 0x2e44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e46:
	/* 0x2e46: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2e4b:
	/* 0x2e4b: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2e4e:
	/* 0x2e4e: jbe    979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2425ULL;
	}
x86_l_2e54:
	/* 0x2e54: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2e5c:
	/* 0x2e5c: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e61:
	/* 0x2e61: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2e66:
	/* 0x2e66: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2e6b:
	/* 0x2e6b: jmp    3061 <generic_rawtp_process_event+0x3061> */
	goto x86_l_3061;
x86_l_2e70:
	/* 0x2e70: add    r15,0x5e60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24160ULL);
x86_l_2e77:
	/* 0x2e77: jmp    2e89 <generic_rawtp_process_event+0x2e89> */
	goto x86_l_2e89;
x86_l_2e79:
	/* 0x2e79: add    r15,0x5e68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24168ULL);
x86_l_2e80:
	/* 0x2e80: jmp    2e89 <generic_rawtp_process_event+0x2e89> */
	goto x86_l_2e89;
x86_l_2e82:
	/* 0x2e82: add    r15,0x5e50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24144ULL);
x86_l_2e89:
	/* 0x2e89: mov    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e8c:
	/* 0x2e8c: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e91:
	/* 0x2e91: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2e99:
	/* 0x2e99: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e9e:
	/* 0x2e9e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ea3:
	/* 0x2ea3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ea8:
	/* 0x2ea8: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2eae:
	/* 0x2eae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2eb3:
	/* 0x2eb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eb5:
	/* 0x2eb5: mov    r13,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2ebd:
	/* 0x2ebd: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_2ec4:
	/* 0x2ec4: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_2eca:
	/* 0x2eca: cmovb  r12,r13 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_2ece:
	/* 0x2ece: lea    rdi,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ed2:
	/* 0x2ed2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ed7:
	/* 0x2ed7: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2edc:
	/* 0x2edc: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2edf:
	/* 0x2edf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ee1:
	/* 0x2ee1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ee3:
	/* 0x2ee3: js     2ef6 <generic_rawtp_process_event+0x2ef6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2ef6;
	}
x86_l_2ee5:
	/* 0x2ee5: mov    DWORD PTR [rbp+0x0],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ee9:
	/* 0x2ee9: mov    DWORD PTR [rbp+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2eed:
	/* 0x2eed: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2ef1:
	/* 0x2ef1: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_2ef4:
	/* 0x2ef4: jmp    2efd <generic_rawtp_process_event+0x2efd> */
	goto x86_l_2efd;
x86_l_2ef6:
	/* 0x2ef6: mov    DWORD PTR [rbp+0x0],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_2efd:
	/* 0x2efd: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2f02:
	/* 0x2f02: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f07:
	/* 0x2f07: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2f0c:
	/* 0x2f0c: mov    rbp,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2f14:
	/* 0x2f14: jmp    3b4e <generic_rawtp_process_event+0x3b4e> */
	return 15182ULL;
x86_l_2f19:
	/* 0x2f19: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2f1e:
	/* 0x2f1e: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2f25:
	/* 0x2f25: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2f2a:
	/* 0x2f2a: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2f2e:
	/* 0x2f2e: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f32:
	/* 0x2f32: movzx  r12d,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2f37:
	/* 0x2f37: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_2f3b:
	/* 0x2f3b: ja     3c44 <generic_rawtp_process_event+0x3c44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 15428ULL;
	}
x86_l_2f41:
	/* 0x2f41: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2f4b:
	/* 0x2f4b: bt     rcx,r12 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2f4f:
	/* 0x2f4f: jae    3c44 <generic_rawtp_process_event+0x3c44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 15428ULL;
	}
x86_l_2f55:
	/* 0x2f55: mov    BYTE PTR [r15+0x5],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2f59:
	/* 0x2f59: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2f5c:
	/* 0x2f5c: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f61:
	/* 0x2f61: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f64:
	/* 0x2f64: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2f69:
	/* 0x2f69: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f6e:
	/* 0x2f6e: mov    rdi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2f76:
	/* 0x2f76: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f7a:
	/* 0x2f7a: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f7d:
	/* 0x2f7d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2f82:
	/* 0x2f82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f84:
	/* 0x2f84: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f87:
	/* 0x2f87: js     3984 <generic_rawtp_process_event+0x3984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14724ULL;
	}
x86_l_2f8d:
	/* 0x2f8d: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2f92:
	/* 0x2f92: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2f95:
	/* 0x2f95: jg     2fb9 <generic_rawtp_process_event+0x2fb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2fb9;
	}
x86_l_2f97:
	/* 0x2f97: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f99:
	/* 0x2f99: je     2fe2 <generic_rawtp_process_event+0x2fe2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fe2;
	}
x86_l_2f9b:
	/* 0x2f9b: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2f9e:
	/* 0x2f9e: je     2fe2 <generic_rawtp_process_event+0x2fe2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fe2;
	}
x86_l_2fa0:
	/* 0x2fa0: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2fa3:
	/* 0x2fa3: jne    31b0 <generic_rawtp_process_event+0x31b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12720ULL;
	}
x86_l_2fa9:
	/* 0x2fa9: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2fb0:
	/* 0x2fb0: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2fb4:
	/* 0x2fb4: jmp    31b5 <generic_rawtp_process_event+0x31b5> */
	return 12725ULL;
x86_l_2fb9:
	/* 0x2fb9: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2fbc:
	/* 0x2fbc: je     319d <generic_rawtp_process_event+0x319d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12701ULL;
	}
x86_l_2fc2:
	/* 0x2fc2: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2fc5:
	/* 0x2fc5: je     2fe2 <generic_rawtp_process_event+0x2fe2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fe2;
	}
x86_l_2fc7:
	/* 0x2fc7: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2fcc:
	/* 0x2fcc: jne    31b0 <generic_rawtp_process_event+0x31b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12720ULL;
	}
x86_l_2fd2:
	/* 0x2fd2: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2fd9:
	/* 0x2fd9: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2fdd:
	/* 0x2fdd: jmp    31b5 <generic_rawtp_process_event+0x31b5> */
	return 12725ULL;
x86_l_2fe2:
	/* 0x2fe2: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2fe7:
	/* 0x2fe7: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2fee:
	/* 0x2fee: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2ff3:
	/* 0x2ff3: jmp    31b5 <generic_rawtp_process_event+0x31b5> */
	return 12725ULL;
x86_l_2ff8:
	/* 0x2ff8: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2ffd:
	/* 0x2ffd: jmp    2f2a <generic_rawtp_process_event+0x2f2a> */
	goto x86_l_2f2a;
x86_l_3002:
	/* 0x3002: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3006:
	/* 0x3006: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_300b:
	/* 0x300b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3010:
	/* 0x3010: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3015:
	/* 0x3015: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_301a:
	/* 0x301a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_301c:
	/* 0x301c: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3021:
	/* 0x3021: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_3026:
	/* 0x3026: je     974 <generic_rawtp_process_event+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2420ULL;
	}
x86_l_302c:
	/* 0x302c: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3030:
	/* 0x3030: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3035:
	/* 0x3035: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_303a:
	/* 0x303a: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_303f:
	/* 0x303f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3044:
	/* 0x3044: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3047:
	/* 0x3047: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3049:
	/* 0x3049: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_304e:
	/* 0x304e: mov    QWORD PTR [rsp+0x50],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3053:
	/* 0x3053: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3057:
	/* 0x3057: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_305c:
	/* 0x305c: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3061:
	/* 0x3061: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_3066:
	/* 0x3066: jne    3073 <generic_rawtp_process_event+0x3073> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3073;
	}
x86_l_3068:
	/* 0x3068: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_306d:
	/* 0x306d: je     974 <generic_rawtp_process_event+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2420ULL;
	}
x86_l_3073:
	/* 0x3073: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_307b:
	/* 0x307b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3080:
	/* 0x3080: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3085:
	/* 0x3085: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_308a:
	/* 0x308a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_308c:
	/* 0x308c: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_3094:
	/* 0x3094: je     3425 <generic_rawtp_process_event+0x3425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13349ULL;
	}
x86_l_309a:
	/* 0x309a: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_309f:
	/* 0x309f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30a4:
	/* 0x30a4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_30a9:
	/* 0x30a9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30ae:
	/* 0x30ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30b3:
	/* 0x30b3: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_30b6:
	/* 0x30b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30b8:
	/* 0x30b8: cmp    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30bd:
	/* 0x30bd: je     3425 <generic_rawtp_process_event+0x3425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13349ULL;
	}
x86_l_30c3:
	/* 0x30c3: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_30cb:
	/* 0x30cb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_30d0:
	/* 0x30d0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30d5:
	/* 0x30d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30da:
	/* 0x30da: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_30dd:
	/* 0x30dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30df:
	/* 0x30df: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_30e3:
	/* 0x30e3: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_30e8:
	/* 0x30e8: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_30ed:
	/* 0x30ed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30f2:
	/* 0x30f2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_30f7:
	/* 0x30f7: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
	return 12538ULL;
}

static __noinline __u64 tetragon_bpf_generic_rawtp_generic_rawtp_process_event_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12538ULL: goto x86_l_30fa;
	case 12540ULL: goto x86_l_30fc;
	case 12545ULL: goto x86_l_3101;
	case 12550ULL: goto x86_l_3106;
	case 12554ULL: goto x86_l_310a;
	case 12557ULL: goto x86_l_310d;
	case 12562ULL: goto x86_l_3112;
	case 12564ULL: goto x86_l_3114;
	case 12566ULL: goto x86_l_3116;
	case 12569ULL: goto x86_l_3119;
	case 12572ULL: goto x86_l_311c;
	case 12577ULL: goto x86_l_3121;
	case 12579ULL: goto x86_l_3123;
	case 12582ULL: goto x86_l_3126;
	case 12586ULL: goto x86_l_312a;
	case 12588ULL: goto x86_l_312c;
	case 12592ULL: goto x86_l_3130;
	case 12594ULL: goto x86_l_3132;
	case 12597ULL: goto x86_l_3135;
	case 12599ULL: goto x86_l_3137;
	case 12603ULL: goto x86_l_313b;
	case 12606ULL: goto x86_l_313e;
	case 12612ULL: goto x86_l_3144;
	case 12618ULL: goto x86_l_314a;
	case 12624ULL: goto x86_l_3150;
	case 12627ULL: goto x86_l_3153;
	case 12629ULL: goto x86_l_3155;
	case 12634ULL: goto x86_l_315a;
	case 12636ULL: goto x86_l_315c;
	case 12639ULL: goto x86_l_315f;
	case 12643ULL: goto x86_l_3163;
	case 12646ULL: goto x86_l_3166;
	case 12649ULL: goto x86_l_3169;
	case 12652ULL: goto x86_l_316c;
	case 12657ULL: goto x86_l_3171;
	case 12659ULL: goto x86_l_3173;
	case 12664ULL: goto x86_l_3178;
	case 12667ULL: goto x86_l_317b;
	case 12673ULL: goto x86_l_3181;
	case 12681ULL: goto x86_l_3189;
	case 12686ULL: goto x86_l_318e;
	case 12691ULL: goto x86_l_3193;
	case 12696ULL: goto x86_l_3198;
	case 12701ULL: goto x86_l_319d;
	case 12706ULL: goto x86_l_31a2;
	case 12713ULL: goto x86_l_31a9;
	case 12718ULL: goto x86_l_31ae;
	case 12720ULL: goto x86_l_31b0;
	case 12725ULL: goto x86_l_31b5;
	case 12729ULL: goto x86_l_31b9;
	case 12733ULL: goto x86_l_31bd;
	case 12738ULL: goto x86_l_31c2;
	case 12742ULL: goto x86_l_31c6;
	case 12748ULL: goto x86_l_31cc;
	case 12758ULL: goto x86_l_31d6;
	case 12762ULL: goto x86_l_31da;
	case 12768ULL: goto x86_l_31e0;
	case 12772ULL: goto x86_l_31e4;
	case 12775ULL: goto x86_l_31e7;
	case 12780ULL: goto x86_l_31ec;
	case 12783ULL: goto x86_l_31ef;
	case 12788ULL: goto x86_l_31f4;
	case 12793ULL: goto x86_l_31f9;
	case 12801ULL: goto x86_l_3201;
	case 12805ULL: goto x86_l_3205;
	case 12808ULL: goto x86_l_3208;
	case 12813ULL: goto x86_l_320d;
	case 12815ULL: goto x86_l_320f;
	case 12818ULL: goto x86_l_3212;
	case 12824ULL: goto x86_l_3218;
	case 12829ULL: goto x86_l_321d;
	case 12832ULL: goto x86_l_3220;
	case 12834ULL: goto x86_l_3222;
	case 12836ULL: goto x86_l_3224;
	case 12838ULL: goto x86_l_3226;
	case 12841ULL: goto x86_l_3229;
	case 12843ULL: goto x86_l_322b;
	case 12846ULL: goto x86_l_322e;
	case 12848ULL: goto x86_l_3230;
	case 12855ULL: goto x86_l_3237;
	case 12859ULL: goto x86_l_323b;
	case 12861ULL: goto x86_l_323d;
	case 12864ULL: goto x86_l_3240;
	case 12866ULL: goto x86_l_3242;
	case 12869ULL: goto x86_l_3245;
	case 12871ULL: goto x86_l_3247;
	case 12876ULL: goto x86_l_324c;
	case 12878ULL: goto x86_l_324e;
	case 12885ULL: goto x86_l_3255;
	case 12889ULL: goto x86_l_3259;
	case 12891ULL: goto x86_l_325b;
	case 12896ULL: goto x86_l_3260;
	case 12903ULL: goto x86_l_3267;
	case 12908ULL: goto x86_l_326c;
	case 12910ULL: goto x86_l_326e;
	case 12915ULL: goto x86_l_3273;
	case 12922ULL: goto x86_l_327a;
	case 12927ULL: goto x86_l_327f;
	case 12929ULL: goto x86_l_3281;
	case 12934ULL: goto x86_l_3286;
	case 12938ULL: goto x86_l_328a;
	case 12942ULL: goto x86_l_328e;
	case 12947ULL: goto x86_l_3293;
	case 12951ULL: goto x86_l_3297;
	case 12957ULL: goto x86_l_329d;
	case 12967ULL: goto x86_l_32a7;
	case 12971ULL: goto x86_l_32ab;
	case 12977ULL: goto x86_l_32b1;
	case 12981ULL: goto x86_l_32b5;
	case 12984ULL: goto x86_l_32b8;
	case 12989ULL: goto x86_l_32bd;
	case 12992ULL: goto x86_l_32c0;
	case 12997ULL: goto x86_l_32c5;
	case 13002ULL: goto x86_l_32ca;
	case 13010ULL: goto x86_l_32d2;
	case 13014ULL: goto x86_l_32d6;
	case 13017ULL: goto x86_l_32d9;
	case 13022ULL: goto x86_l_32de;
	case 13024ULL: goto x86_l_32e0;
	case 13027ULL: goto x86_l_32e3;
	case 13033ULL: goto x86_l_32e9;
	case 13038ULL: goto x86_l_32ee;
	case 13041ULL: goto x86_l_32f1;
	case 13043ULL: goto x86_l_32f3;
	case 13045ULL: goto x86_l_32f5;
	case 13047ULL: goto x86_l_32f7;
	case 13050ULL: goto x86_l_32fa;
	case 13052ULL: goto x86_l_32fc;
	case 13055ULL: goto x86_l_32ff;
	case 13057ULL: goto x86_l_3301;
	case 13064ULL: goto x86_l_3308;
	case 13068ULL: goto x86_l_330c;
	case 13070ULL: goto x86_l_330e;
	case 13073ULL: goto x86_l_3311;
	case 13075ULL: goto x86_l_3313;
	case 13078ULL: goto x86_l_3316;
	case 13080ULL: goto x86_l_3318;
	case 13085ULL: goto x86_l_331d;
	case 13087ULL: goto x86_l_331f;
	case 13094ULL: goto x86_l_3326;
	case 13098ULL: goto x86_l_332a;
	case 13100ULL: goto x86_l_332c;
	case 13105ULL: goto x86_l_3331;
	case 13112ULL: goto x86_l_3338;
	case 13117ULL: goto x86_l_333d;
	case 13119ULL: goto x86_l_333f;
	case 13124ULL: goto x86_l_3344;
	case 13131ULL: goto x86_l_334b;
	case 13136ULL: goto x86_l_3350;
	case 13138ULL: goto x86_l_3352;
	case 13143ULL: goto x86_l_3357;
	case 13147ULL: goto x86_l_335b;
	case 13151ULL: goto x86_l_335f;
	case 13156ULL: goto x86_l_3364;
	case 13160ULL: goto x86_l_3368;
	case 13166ULL: goto x86_l_336e;
	case 13176ULL: goto x86_l_3378;
	case 13180ULL: goto x86_l_337c;
	case 13186ULL: goto x86_l_3382;
	case 13190ULL: goto x86_l_3386;
	case 13193ULL: goto x86_l_3389;
	case 13198ULL: goto x86_l_338e;
	case 13201ULL: goto x86_l_3391;
	case 13206ULL: goto x86_l_3396;
	case 13211ULL: goto x86_l_339b;
	case 13219ULL: goto x86_l_33a3;
	case 13223ULL: goto x86_l_33a7;
	case 13226ULL: goto x86_l_33aa;
	case 13231ULL: goto x86_l_33af;
	case 13233ULL: goto x86_l_33b1;
	case 13236ULL: goto x86_l_33b4;
	case 13242ULL: goto x86_l_33ba;
	case 13247ULL: goto x86_l_33bf;
	case 13250ULL: goto x86_l_33c2;
	case 13252ULL: goto x86_l_33c4;
	case 13254ULL: goto x86_l_33c6;
	case 13256ULL: goto x86_l_33c8;
	case 13259ULL: goto x86_l_33cb;
	case 13261ULL: goto x86_l_33cd;
	case 13264ULL: goto x86_l_33d0;
	case 13270ULL: goto x86_l_33d6;
	case 13277ULL: goto x86_l_33dd;
	case 13281ULL: goto x86_l_33e1;
	case 13286ULL: goto x86_l_33e6;
	case 13289ULL: goto x86_l_33e9;
	case 13295ULL: goto x86_l_33ef;
	case 13298ULL: goto x86_l_33f2;
	case 13300ULL: goto x86_l_33f4;
	case 13305ULL: goto x86_l_33f9;
	case 13311ULL: goto x86_l_33ff;
	case 13318ULL: goto x86_l_3406;
	case 13322ULL: goto x86_l_340a;
	case 13327ULL: goto x86_l_340f;
	case 13332ULL: goto x86_l_3414;
	case 13339ULL: goto x86_l_341b;
	case 13344ULL: goto x86_l_3420;
	case 13349ULL: goto x86_l_3425;
	case 13353ULL: goto x86_l_3429;
	case 13358ULL: goto x86_l_342e;
	case 13363ULL: goto x86_l_3433;
	case 13368ULL: goto x86_l_3438;
	case 13373ULL: goto x86_l_343d;
	case 13375ULL: goto x86_l_343f;
	case 13380ULL: goto x86_l_3444;
	case 13385ULL: goto x86_l_3449;
	case 13391ULL: goto x86_l_344f;
	case 13395ULL: goto x86_l_3453;
	case 13400ULL: goto x86_l_3458;
	case 13405ULL: goto x86_l_345d;
	case 13410ULL: goto x86_l_3462;
	case 13415ULL: goto x86_l_3467;
	case 13418ULL: goto x86_l_346a;
	case 13420ULL: goto x86_l_346c;
	case 13425ULL: goto x86_l_3471;
	case 13430ULL: goto x86_l_3476;
	case 13434ULL: goto x86_l_347a;
	case 13439ULL: goto x86_l_347f;
	case 13444ULL: goto x86_l_3484;
	case 13449ULL: goto x86_l_3489;
	case 13451ULL: goto x86_l_348b;
	case 13456ULL: goto x86_l_3490;
	case 13462ULL: goto x86_l_3496;
	case 13470ULL: goto x86_l_349e;
	case 13475ULL: goto x86_l_34a3;
	case 13480ULL: goto x86_l_34a8;
	case 13485ULL: goto x86_l_34ad;
	case 13487ULL: goto x86_l_34af;
	case 13495ULL: goto x86_l_34b7;
	case 13501ULL: goto x86_l_34bd;
	case 13506ULL: goto x86_l_34c2;
	case 13511ULL: goto x86_l_34c7;
	case 13516ULL: goto x86_l_34cc;
	case 13521ULL: goto x86_l_34d1;
	case 13526ULL: goto x86_l_34d6;
	case 13529ULL: goto x86_l_34d9;
	case 13531ULL: goto x86_l_34db;
	case 13536ULL: goto x86_l_34e0;
	case 13542ULL: goto x86_l_34e6;
	case 13550ULL: goto x86_l_34ee;
	case 13555ULL: goto x86_l_34f3;
	case 13560ULL: goto x86_l_34f8;
	case 13565ULL: goto x86_l_34fd;
	case 13568ULL: goto x86_l_3500;
	case 13570ULL: goto x86_l_3502;
	case 13574ULL: goto x86_l_3506;
	case 13579ULL: goto x86_l_350b;
	case 13584ULL: goto x86_l_3510;
	case 13589ULL: goto x86_l_3515;
	case 13594ULL: goto x86_l_351a;
	case 13597ULL: goto x86_l_351d;
	case 13599ULL: goto x86_l_351f;
	case 13604ULL: goto x86_l_3524;
	case 13609ULL: goto x86_l_3529;
	case 13613ULL: goto x86_l_352d;
	case 13616ULL: goto x86_l_3530;
	case 13621ULL: goto x86_l_3535;
	case 13623ULL: goto x86_l_3537;
	case 13625ULL: goto x86_l_3539;
	case 13628ULL: goto x86_l_353c;
	case 13631ULL: goto x86_l_353f;
	case 13636ULL: goto x86_l_3544;
	case 13638ULL: goto x86_l_3546;
	case 13641ULL: goto x86_l_3549;
	case 13645ULL: goto x86_l_354d;
	case 13647ULL: goto x86_l_354f;
	case 13651ULL: goto x86_l_3553;
	case 13653ULL: goto x86_l_3555;
	case 13656ULL: goto x86_l_3558;
	case 13658ULL: goto x86_l_355a;
	case 13662ULL: goto x86_l_355e;
	case 13665ULL: goto x86_l_3561;
	case 13671ULL: goto x86_l_3567;
	case 13677ULL: goto x86_l_356d;
	case 13683ULL: goto x86_l_3573;
	case 13686ULL: goto x86_l_3576;
	case 13688ULL: goto x86_l_3578;
	case 13693ULL: goto x86_l_357d;
	case 13695ULL: goto x86_l_357f;
	case 13698ULL: goto x86_l_3582;
	case 13702ULL: goto x86_l_3586;
	case 13705ULL: goto x86_l_3589;
	case 13708ULL: goto x86_l_358c;
	case 13711ULL: goto x86_l_358f;
	case 13716ULL: goto x86_l_3594;
	case 13718ULL: goto x86_l_3596;
	case 13723ULL: goto x86_l_359b;
	case 13726ULL: goto x86_l_359e;
	case 13732ULL: goto x86_l_35a4;
	case 13740ULL: goto x86_l_35ac;
	case 13745ULL: goto x86_l_35b1;
	case 13750ULL: goto x86_l_35b6;
	case 13755ULL: goto x86_l_35bb;
	case 13760ULL: goto x86_l_35c0;
	case 13765ULL: goto x86_l_35c5;
	case 13772ULL: goto x86_l_35cc;
	case 13777ULL: goto x86_l_35d1;
	case 13779ULL: goto x86_l_35d3;
	case 13784ULL: goto x86_l_35d8;
	case 13788ULL: goto x86_l_35dc;
	case 13792ULL: goto x86_l_35e0;
	case 13797ULL: goto x86_l_35e5;
	case 13801ULL: goto x86_l_35e9;
	case 13807ULL: goto x86_l_35ef;
	case 13817ULL: goto x86_l_35f9;
	case 13821ULL: goto x86_l_35fd;
	case 13827ULL: goto x86_l_3603;
	case 13831ULL: goto x86_l_3607;
	case 13834ULL: goto x86_l_360a;
	case 13839ULL: goto x86_l_360f;
	case 13842ULL: goto x86_l_3612;
	case 13847ULL: goto x86_l_3617;
	case 13852ULL: goto x86_l_361c;
	case 13860ULL: goto x86_l_3624;
	case 13864ULL: goto x86_l_3628;
	case 13867ULL: goto x86_l_362b;
	case 13872ULL: goto x86_l_3630;
	case 13874ULL: goto x86_l_3632;
	case 13877ULL: goto x86_l_3635;
	case 13883ULL: goto x86_l_363b;
	case 13888ULL: goto x86_l_3640;
	case 13891ULL: goto x86_l_3643;
	case 13893ULL: goto x86_l_3645;
	case 13895ULL: goto x86_l_3647;
	case 13897ULL: goto x86_l_3649;
	case 13900ULL: goto x86_l_364c;
	case 13902ULL: goto x86_l_364e;
	case 13905ULL: goto x86_l_3651;
	case 13907ULL: goto x86_l_3653;
	case 13914ULL: goto x86_l_365a;
	case 13918ULL: goto x86_l_365e;
	case 13920ULL: goto x86_l_3660;
	case 13923ULL: goto x86_l_3663;
	case 13925ULL: goto x86_l_3665;
	case 13928ULL: goto x86_l_3668;
	case 13930ULL: goto x86_l_366a;
	case 13935ULL: goto x86_l_366f;
	case 13937ULL: goto x86_l_3671;
	case 13944ULL: goto x86_l_3678;
	case 13948ULL: goto x86_l_367c;
	case 13950ULL: goto x86_l_367e;
	case 13955ULL: goto x86_l_3683;
	case 13962ULL: goto x86_l_368a;
	case 13967ULL: goto x86_l_368f;
	case 13969ULL: goto x86_l_3691;
	case 13974ULL: goto x86_l_3696;
	case 13981ULL: goto x86_l_369d;
	case 13986ULL: goto x86_l_36a2;
	case 13988ULL: goto x86_l_36a4;
	case 13993ULL: goto x86_l_36a9;
	case 13997ULL: goto x86_l_36ad;
	case 14001ULL: goto x86_l_36b1;
	case 14006ULL: goto x86_l_36b6;
	case 14010ULL: goto x86_l_36ba;
	case 14016ULL: goto x86_l_36c0;
	case 14026ULL: goto x86_l_36ca;
	case 14030ULL: goto x86_l_36ce;
	case 14036ULL: goto x86_l_36d4;
	case 14040ULL: goto x86_l_36d8;
	case 14043ULL: goto x86_l_36db;
	case 14048ULL: goto x86_l_36e0;
	case 14051ULL: goto x86_l_36e3;
	case 14056ULL: goto x86_l_36e8;
	case 14061ULL: goto x86_l_36ed;
	case 14069ULL: goto x86_l_36f5;
	case 14073ULL: goto x86_l_36f9;
	case 14076ULL: goto x86_l_36fc;
	case 14081ULL: goto x86_l_3701;
	case 14083ULL: goto x86_l_3703;
	case 14086ULL: goto x86_l_3706;
	case 14092ULL: goto x86_l_370c;
	case 14097ULL: goto x86_l_3711;
	case 14100ULL: goto x86_l_3714;
	case 14102ULL: goto x86_l_3716;
	case 14104ULL: goto x86_l_3718;
	case 14106ULL: goto x86_l_371a;
	case 14109ULL: goto x86_l_371d;
	case 14111ULL: goto x86_l_371f;
	case 14114ULL: goto x86_l_3722;
	case 14120ULL: goto x86_l_3728;
	case 14127ULL: goto x86_l_372f;
	case 14131ULL: goto x86_l_3733;
	case 14136ULL: goto x86_l_3738;
	case 14139ULL: goto x86_l_373b;
	case 14145ULL: goto x86_l_3741;
	default: return 0xffffffffffffffffULL;
	}
x86_l_30fa:
	/* 0x30fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30fc:
	/* 0x30fc: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3101:
	/* 0x3101: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3106:
	/* 0x3106: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_310a:
	/* 0x310a: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_310d:
	/* 0x310d: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3112:
	/* 0x3112: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3114:
	/* 0x3114: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_3116:
	/* 0x3116: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3119:
	/* 0x3119: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_311c:
	/* 0x311c: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_3121:
	/* 0x3121: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3123:
	/* 0x3123: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3126:
	/* 0x3126: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_312a:
	/* 0x312a: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_312c:
	/* 0x312c: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_3130:
	/* 0x3130: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3132:
	/* 0x3132: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_3135:
	/* 0x3135: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3137:
	/* 0x3137: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_313b:
	/* 0x313b: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_313e:
	/* 0x313e: jb     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2425ULL;
	}
x86_l_3144:
	/* 0x3144: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_314a:
	/* 0x314a: ja     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2425ULL;
	}
x86_l_3150:
	/* 0x3150: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3153:
	/* 0x3153: jbe    315a <generic_rawtp_process_event+0x315a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_315a;
	}
x86_l_3155:
	/* 0x3155: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_315a:
	/* 0x315a: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_315c:
	/* 0x315c: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_315f:
	/* 0x315f: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_3163:
	/* 0x3163: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3166:
	/* 0x3166: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3169:
	/* 0x3169: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_316c:
	/* 0x316c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3171:
	/* 0x3171: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3173:
	/* 0x3173: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3178:
	/* 0x3178: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_317b:
	/* 0x317b: jbe    979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2425ULL;
	}
x86_l_3181:
	/* 0x3181: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3189:
	/* 0x3189: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_318e:
	/* 0x318e: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3193:
	/* 0x3193: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3198:
	/* 0x3198: jmp    3484 <generic_rawtp_process_event+0x3484> */
	goto x86_l_3484;
x86_l_319d:
	/* 0x319d: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_31a2:
	/* 0x31a2: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_31a9:
	/* 0x31a9: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_31ae:
	/* 0x31ae: jmp    31b5 <generic_rawtp_process_event+0x31b5> */
	goto x86_l_31b5;
x86_l_31b0:
	/* 0x31b0: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_31b5:
	/* 0x31b5: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_31b9:
	/* 0x31b9: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31bd:
	/* 0x31bd: movzx  r12d,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_31c2:
	/* 0x31c2: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_31c6:
	/* 0x31c6: ja     3c44 <generic_rawtp_process_event+0x3c44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 15428ULL;
	}
x86_l_31cc:
	/* 0x31cc: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_31d6:
	/* 0x31d6: bt     rcx,r12 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_31da:
	/* 0x31da: jae    3c44 <generic_rawtp_process_event+0x3c44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 15428ULL;
	}
x86_l_31e0:
	/* 0x31e0: mov    BYTE PTR [r15+0x5],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_31e4:
	/* 0x31e4: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_31e7:
	/* 0x31e7: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31ec:
	/* 0x31ec: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_31ef:
	/* 0x31ef: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_31f4:
	/* 0x31f4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31f9:
	/* 0x31f9: mov    rdi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3201:
	/* 0x3201: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3205:
	/* 0x3205: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3208:
	/* 0x3208: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_320d:
	/* 0x320d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_320f:
	/* 0x320f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3212:
	/* 0x3212: js     3984 <generic_rawtp_process_event+0x3984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14724ULL;
	}
x86_l_3218:
	/* 0x3218: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_321d:
	/* 0x321d: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_3220:
	/* 0x3220: jg     323d <generic_rawtp_process_event+0x323d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_323d;
	}
x86_l_3222:
	/* 0x3222: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3224:
	/* 0x3224: je     325b <generic_rawtp_process_event+0x325b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_325b;
	}
x86_l_3226:
	/* 0x3226: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_3229:
	/* 0x3229: je     325b <generic_rawtp_process_event+0x325b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_325b;
	}
x86_l_322b:
	/* 0x322b: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_322e:
	/* 0x322e: jne    3281 <generic_rawtp_process_event+0x3281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3281;
	}
x86_l_3230:
	/* 0x3230: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_3237:
	/* 0x3237: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_323b:
	/* 0x323b: jmp    3286 <generic_rawtp_process_event+0x3286> */
	goto x86_l_3286;
x86_l_323d:
	/* 0x323d: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_3240:
	/* 0x3240: je     326e <generic_rawtp_process_event+0x326e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_326e;
	}
x86_l_3242:
	/* 0x3242: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_3245:
	/* 0x3245: je     325b <generic_rawtp_process_event+0x325b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_325b;
	}
x86_l_3247:
	/* 0x3247: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_324c:
	/* 0x324c: jne    3281 <generic_rawtp_process_event+0x3281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3281;
	}
x86_l_324e:
	/* 0x324e: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_3255:
	/* 0x3255: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_3259:
	/* 0x3259: jmp    3286 <generic_rawtp_process_event+0x3286> */
	goto x86_l_3286;
x86_l_325b:
	/* 0x325b: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3260:
	/* 0x3260: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_3267:
	/* 0x3267: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_326c:
	/* 0x326c: jmp    3286 <generic_rawtp_process_event+0x3286> */
	goto x86_l_3286;
x86_l_326e:
	/* 0x326e: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3273:
	/* 0x3273: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_327a:
	/* 0x327a: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_327f:
	/* 0x327f: jmp    3286 <generic_rawtp_process_event+0x3286> */
	goto x86_l_3286;
x86_l_3281:
	/* 0x3281: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_3286:
	/* 0x3286: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_328a:
	/* 0x328a: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_328e:
	/* 0x328e: movzx  r12d,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_3293:
	/* 0x3293: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_3297:
	/* 0x3297: ja     3c44 <generic_rawtp_process_event+0x3c44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 15428ULL;
	}
x86_l_329d:
	/* 0x329d: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_32a7:
	/* 0x32a7: bt     rcx,r12 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_32ab:
	/* 0x32ab: jae    3c44 <generic_rawtp_process_event+0x3c44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 15428ULL;
	}
x86_l_32b1:
	/* 0x32b1: mov    BYTE PTR [r15+0x5],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_32b5:
	/* 0x32b5: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_32b8:
	/* 0x32b8: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32bd:
	/* 0x32bd: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_32c0:
	/* 0x32c0: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_32c5:
	/* 0x32c5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32ca:
	/* 0x32ca: mov    rdi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_32d2:
	/* 0x32d2: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_32d6:
	/* 0x32d6: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_32d9:
	/* 0x32d9: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_32de:
	/* 0x32de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32e0:
	/* 0x32e0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32e3:
	/* 0x32e3: js     3984 <generic_rawtp_process_event+0x3984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14724ULL;
	}
x86_l_32e9:
	/* 0x32e9: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_32ee:
	/* 0x32ee: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_32f1:
	/* 0x32f1: jg     330e <generic_rawtp_process_event+0x330e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_330e;
	}
x86_l_32f3:
	/* 0x32f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32f5:
	/* 0x32f5: je     332c <generic_rawtp_process_event+0x332c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_332c;
	}
x86_l_32f7:
	/* 0x32f7: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_32fa:
	/* 0x32fa: je     332c <generic_rawtp_process_event+0x332c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_332c;
	}
x86_l_32fc:
	/* 0x32fc: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_32ff:
	/* 0x32ff: jne    3352 <generic_rawtp_process_event+0x3352> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3352;
	}
x86_l_3301:
	/* 0x3301: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_3308:
	/* 0x3308: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_330c:
	/* 0x330c: jmp    3357 <generic_rawtp_process_event+0x3357> */
	goto x86_l_3357;
x86_l_330e:
	/* 0x330e: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_3311:
	/* 0x3311: je     333f <generic_rawtp_process_event+0x333f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_333f;
	}
x86_l_3313:
	/* 0x3313: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_3316:
	/* 0x3316: je     332c <generic_rawtp_process_event+0x332c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_332c;
	}
x86_l_3318:
	/* 0x3318: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_331d:
	/* 0x331d: jne    3352 <generic_rawtp_process_event+0x3352> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3352;
	}
x86_l_331f:
	/* 0x331f: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_3326:
	/* 0x3326: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_332a:
	/* 0x332a: jmp    3357 <generic_rawtp_process_event+0x3357> */
	goto x86_l_3357;
x86_l_332c:
	/* 0x332c: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3331:
	/* 0x3331: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_3338:
	/* 0x3338: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_333d:
	/* 0x333d: jmp    3357 <generic_rawtp_process_event+0x3357> */
	goto x86_l_3357;
x86_l_333f:
	/* 0x333f: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3344:
	/* 0x3344: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_334b:
	/* 0x334b: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3350:
	/* 0x3350: jmp    3357 <generic_rawtp_process_event+0x3357> */
	goto x86_l_3357;
x86_l_3352:
	/* 0x3352: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_3357:
	/* 0x3357: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_335b:
	/* 0x335b: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_335f:
	/* 0x335f: movzx  r12d,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_3364:
	/* 0x3364: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_3368:
	/* 0x3368: ja     3c44 <generic_rawtp_process_event+0x3c44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 15428ULL;
	}
x86_l_336e:
	/* 0x336e: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_3378:
	/* 0x3378: bt     rcx,r12 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_337c:
	/* 0x337c: jae    3c44 <generic_rawtp_process_event+0x3c44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 15428ULL;
	}
x86_l_3382:
	/* 0x3382: mov    BYTE PTR [r15+0x5],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_3386:
	/* 0x3386: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3389:
	/* 0x3389: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_338e:
	/* 0x338e: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3391:
	/* 0x3391: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3396:
	/* 0x3396: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_339b:
	/* 0x339b: mov    rdi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_33a3:
	/* 0x33a3: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_33a7:
	/* 0x33a7: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_33aa:
	/* 0x33aa: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_33af:
	/* 0x33af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33b1:
	/* 0x33b1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33b4:
	/* 0x33b4: js     3984 <generic_rawtp_process_event+0x3984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14724ULL;
	}
x86_l_33ba:
	/* 0x33ba: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_33bf:
	/* 0x33bf: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_33c2:
	/* 0x33c2: jg     33e6 <generic_rawtp_process_event+0x33e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_33e6;
	}
x86_l_33c4:
	/* 0x33c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33c6:
	/* 0x33c6: je     340f <generic_rawtp_process_event+0x340f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_340f;
	}
x86_l_33c8:
	/* 0x33c8: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_33cb:
	/* 0x33cb: je     340f <generic_rawtp_process_event+0x340f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_340f;
	}
x86_l_33cd:
	/* 0x33cd: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_33d0:
	/* 0x33d0: jne    35d3 <generic_rawtp_process_event+0x35d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_35d3;
	}
x86_l_33d6:
	/* 0x33d6: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_33dd:
	/* 0x33dd: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_33e1:
	/* 0x33e1: jmp    35d8 <generic_rawtp_process_event+0x35d8> */
	goto x86_l_35d8;
x86_l_33e6:
	/* 0x33e6: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_33e9:
	/* 0x33e9: je     35c0 <generic_rawtp_process_event+0x35c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35c0;
	}
x86_l_33ef:
	/* 0x33ef: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_33f2:
	/* 0x33f2: je     340f <generic_rawtp_process_event+0x340f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_340f;
	}
x86_l_33f4:
	/* 0x33f4: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_33f9:
	/* 0x33f9: jne    35d3 <generic_rawtp_process_event+0x35d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_35d3;
	}
x86_l_33ff:
	/* 0x33ff: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_3406:
	/* 0x3406: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_340a:
	/* 0x340a: jmp    35d8 <generic_rawtp_process_event+0x35d8> */
	goto x86_l_35d8;
x86_l_340f:
	/* 0x340f: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3414:
	/* 0x3414: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_341b:
	/* 0x341b: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3420:
	/* 0x3420: jmp    35d8 <generic_rawtp_process_event+0x35d8> */
	goto x86_l_35d8;
x86_l_3425:
	/* 0x3425: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3429:
	/* 0x3429: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_342e:
	/* 0x342e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3433:
	/* 0x3433: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3438:
	/* 0x3438: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_343d:
	/* 0x343d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_343f:
	/* 0x343f: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3444:
	/* 0x3444: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_3449:
	/* 0x3449: je     974 <generic_rawtp_process_event+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2420ULL;
	}
x86_l_344f:
	/* 0x344f: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3453:
	/* 0x3453: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3458:
	/* 0x3458: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_345d:
	/* 0x345d: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3462:
	/* 0x3462: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3467:
	/* 0x3467: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_346a:
	/* 0x346a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_346c:
	/* 0x346c: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3471:
	/* 0x3471: mov    QWORD PTR [rsp+0x50],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3476:
	/* 0x3476: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_347a:
	/* 0x347a: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_347f:
	/* 0x347f: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3484:
	/* 0x3484: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_3489:
	/* 0x3489: jne    3496 <generic_rawtp_process_event+0x3496> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3496;
	}
x86_l_348b:
	/* 0x348b: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_3490:
	/* 0x3490: je     974 <generic_rawtp_process_event+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2420ULL;
	}
x86_l_3496:
	/* 0x3496: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_349e:
	/* 0x349e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_34a3:
	/* 0x34a3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_34a8:
	/* 0x34a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34ad:
	/* 0x34ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34af:
	/* 0x34af: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_34b7:
	/* 0x34b7: je     3777 <generic_rawtp_process_event+0x3777> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14199ULL;
	}
x86_l_34bd:
	/* 0x34bd: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_34c2:
	/* 0x34c2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34c7:
	/* 0x34c7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_34cc:
	/* 0x34cc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_34d1:
	/* 0x34d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34d6:
	/* 0x34d6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_34d9:
	/* 0x34d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34db:
	/* 0x34db: cmp    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34e0:
	/* 0x34e0: je     3777 <generic_rawtp_process_event+0x3777> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14199ULL;
	}
x86_l_34e6:
	/* 0x34e6: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_34ee:
	/* 0x34ee: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_34f3:
	/* 0x34f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_34f8:
	/* 0x34f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34fd:
	/* 0x34fd: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3500:
	/* 0x3500: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3502:
	/* 0x3502: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3506:
	/* 0x3506: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_350b:
	/* 0x350b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3510:
	/* 0x3510: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3515:
	/* 0x3515: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_351a:
	/* 0x351a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_351d:
	/* 0x351d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_351f:
	/* 0x351f: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3524:
	/* 0x3524: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3529:
	/* 0x3529: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_352d:
	/* 0x352d: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3530:
	/* 0x3530: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3535:
	/* 0x3535: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3537:
	/* 0x3537: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_3539:
	/* 0x3539: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_353c:
	/* 0x353c: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_353f:
	/* 0x353f: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_3544:
	/* 0x3544: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3546:
	/* 0x3546: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3549:
	/* 0x3549: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_354d:
	/* 0x354d: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_354f:
	/* 0x354f: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_3553:
	/* 0x3553: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3555:
	/* 0x3555: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_3558:
	/* 0x3558: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_355a:
	/* 0x355a: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_355e:
	/* 0x355e: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3561:
	/* 0x3561: jb     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2425ULL;
	}
x86_l_3567:
	/* 0x3567: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_356d:
	/* 0x356d: ja     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2425ULL;
	}
x86_l_3573:
	/* 0x3573: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3576:
	/* 0x3576: jbe    357d <generic_rawtp_process_event+0x357d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_357d;
	}
x86_l_3578:
	/* 0x3578: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_357d:
	/* 0x357d: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_357f:
	/* 0x357f: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3582:
	/* 0x3582: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_3586:
	/* 0x3586: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3589:
	/* 0x3589: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_358c:
	/* 0x358c: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_358f:
	/* 0x358f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3594:
	/* 0x3594: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3596:
	/* 0x3596: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_359b:
	/* 0x359b: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_359e:
	/* 0x359e: jbe    979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2425ULL;
	}
x86_l_35a4:
	/* 0x35a4: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_35ac:
	/* 0x35ac: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_35b1:
	/* 0x35b1: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_35b6:
	/* 0x35b6: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_35bb:
	/* 0x35bb: jmp    37d6 <generic_rawtp_process_event+0x37d6> */
	return 14294ULL;
x86_l_35c0:
	/* 0x35c0: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_35c5:
	/* 0x35c5: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_35cc:
	/* 0x35cc: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_35d1:
	/* 0x35d1: jmp    35d8 <generic_rawtp_process_event+0x35d8> */
	goto x86_l_35d8;
x86_l_35d3:
	/* 0x35d3: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_35d8:
	/* 0x35d8: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_35dc:
	/* 0x35dc: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35e0:
	/* 0x35e0: movzx  r12d,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_35e5:
	/* 0x35e5: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_35e9:
	/* 0x35e9: ja     3c44 <generic_rawtp_process_event+0x3c44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 15428ULL;
	}
x86_l_35ef:
	/* 0x35ef: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_35f9:
	/* 0x35f9: bt     rcx,r12 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_35fd:
	/* 0x35fd: jae    3c44 <generic_rawtp_process_event+0x3c44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 15428ULL;
	}
x86_l_3603:
	/* 0x3603: mov    BYTE PTR [r15+0x5],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_3607:
	/* 0x3607: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_360a:
	/* 0x360a: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_360f:
	/* 0x360f: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3612:
	/* 0x3612: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3617:
	/* 0x3617: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_361c:
	/* 0x361c: mov    rdi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3624:
	/* 0x3624: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3628:
	/* 0x3628: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_362b:
	/* 0x362b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3630:
	/* 0x3630: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3632:
	/* 0x3632: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3635:
	/* 0x3635: js     3984 <generic_rawtp_process_event+0x3984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14724ULL;
	}
x86_l_363b:
	/* 0x363b: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_3640:
	/* 0x3640: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_3643:
	/* 0x3643: jg     3660 <generic_rawtp_process_event+0x3660> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3660;
	}
x86_l_3645:
	/* 0x3645: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3647:
	/* 0x3647: je     367e <generic_rawtp_process_event+0x367e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_367e;
	}
x86_l_3649:
	/* 0x3649: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_364c:
	/* 0x364c: je     367e <generic_rawtp_process_event+0x367e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_367e;
	}
x86_l_364e:
	/* 0x364e: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_3651:
	/* 0x3651: jne    36a4 <generic_rawtp_process_event+0x36a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_36a4;
	}
x86_l_3653:
	/* 0x3653: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_365a:
	/* 0x365a: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_365e:
	/* 0x365e: jmp    36a9 <generic_rawtp_process_event+0x36a9> */
	goto x86_l_36a9;
x86_l_3660:
	/* 0x3660: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_3663:
	/* 0x3663: je     3691 <generic_rawtp_process_event+0x3691> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3691;
	}
x86_l_3665:
	/* 0x3665: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_3668:
	/* 0x3668: je     367e <generic_rawtp_process_event+0x367e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_367e;
	}
x86_l_366a:
	/* 0x366a: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_366f:
	/* 0x366f: jne    36a4 <generic_rawtp_process_event+0x36a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_36a4;
	}
x86_l_3671:
	/* 0x3671: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_3678:
	/* 0x3678: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_367c:
	/* 0x367c: jmp    36a9 <generic_rawtp_process_event+0x36a9> */
	goto x86_l_36a9;
x86_l_367e:
	/* 0x367e: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3683:
	/* 0x3683: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_368a:
	/* 0x368a: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_368f:
	/* 0x368f: jmp    36a9 <generic_rawtp_process_event+0x36a9> */
	goto x86_l_36a9;
x86_l_3691:
	/* 0x3691: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3696:
	/* 0x3696: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_369d:
	/* 0x369d: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_36a2:
	/* 0x36a2: jmp    36a9 <generic_rawtp_process_event+0x36a9> */
	goto x86_l_36a9;
x86_l_36a4:
	/* 0x36a4: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_36a9:
	/* 0x36a9: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_36ad:
	/* 0x36ad: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36b1:
	/* 0x36b1: movzx  r12d,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_36b6:
	/* 0x36b6: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_36ba:
	/* 0x36ba: ja     3c44 <generic_rawtp_process_event+0x3c44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 15428ULL;
	}
x86_l_36c0:
	/* 0x36c0: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_36ca:
	/* 0x36ca: bt     rcx,r12 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_36ce:
	/* 0x36ce: jae    3c44 <generic_rawtp_process_event+0x3c44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 15428ULL;
	}
x86_l_36d4:
	/* 0x36d4: mov    BYTE PTR [r15+0x5],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_36d8:
	/* 0x36d8: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_36db:
	/* 0x36db: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_36e0:
	/* 0x36e0: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_36e3:
	/* 0x36e3: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_36e8:
	/* 0x36e8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_36ed:
	/* 0x36ed: mov    rdi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_36f5:
	/* 0x36f5: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_36f9:
	/* 0x36f9: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_36fc:
	/* 0x36fc: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3701:
	/* 0x3701: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3703:
	/* 0x3703: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3706:
	/* 0x3706: js     3984 <generic_rawtp_process_event+0x3984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14724ULL;
	}
x86_l_370c:
	/* 0x370c: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_3711:
	/* 0x3711: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_3714:
	/* 0x3714: jg     3738 <generic_rawtp_process_event+0x3738> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3738;
	}
x86_l_3716:
	/* 0x3716: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3718:
	/* 0x3718: je     3761 <generic_rawtp_process_event+0x3761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14177ULL;
	}
x86_l_371a:
	/* 0x371a: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_371d:
	/* 0x371d: je     3761 <generic_rawtp_process_event+0x3761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14177ULL;
	}
x86_l_371f:
	/* 0x371f: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_3722:
	/* 0x3722: jne    3925 <generic_rawtp_process_event+0x3925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14629ULL;
	}
x86_l_3728:
	/* 0x3728: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_372f:
	/* 0x372f: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_3733:
	/* 0x3733: jmp    392a <generic_rawtp_process_event+0x392a> */
	return 14634ULL;
x86_l_3738:
	/* 0x3738: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_373b:
	/* 0x373b: je     3912 <generic_rawtp_process_event+0x3912> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14610ULL;
	}
x86_l_3741:
	/* 0x3741: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
	return 14148ULL;
}

static __noinline __u64 tetragon_bpf_generic_rawtp_generic_rawtp_process_event_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14148ULL: goto x86_l_3744;
	case 14150ULL: goto x86_l_3746;
	case 14155ULL: goto x86_l_374b;
	case 14161ULL: goto x86_l_3751;
	case 14168ULL: goto x86_l_3758;
	case 14172ULL: goto x86_l_375c;
	case 14177ULL: goto x86_l_3761;
	case 14182ULL: goto x86_l_3766;
	case 14189ULL: goto x86_l_376d;
	case 14194ULL: goto x86_l_3772;
	case 14199ULL: goto x86_l_3777;
	case 14203ULL: goto x86_l_377b;
	case 14208ULL: goto x86_l_3780;
	case 14213ULL: goto x86_l_3785;
	case 14218ULL: goto x86_l_378a;
	case 14223ULL: goto x86_l_378f;
	case 14225ULL: goto x86_l_3791;
	case 14230ULL: goto x86_l_3796;
	case 14235ULL: goto x86_l_379b;
	case 14241ULL: goto x86_l_37a1;
	case 14245ULL: goto x86_l_37a5;
	case 14250ULL: goto x86_l_37aa;
	case 14255ULL: goto x86_l_37af;
	case 14260ULL: goto x86_l_37b4;
	case 14265ULL: goto x86_l_37b9;
	case 14268ULL: goto x86_l_37bc;
	case 14270ULL: goto x86_l_37be;
	case 14275ULL: goto x86_l_37c3;
	case 14280ULL: goto x86_l_37c8;
	case 14284ULL: goto x86_l_37cc;
	case 14289ULL: goto x86_l_37d1;
	case 14294ULL: goto x86_l_37d6;
	case 14299ULL: goto x86_l_37db;
	case 14301ULL: goto x86_l_37dd;
	case 14306ULL: goto x86_l_37e2;
	case 14312ULL: goto x86_l_37e8;
	case 14320ULL: goto x86_l_37f0;
	case 14325ULL: goto x86_l_37f5;
	case 14330ULL: goto x86_l_37fa;
	case 14335ULL: goto x86_l_37ff;
	case 14337ULL: goto x86_l_3801;
	case 14345ULL: goto x86_l_3809;
	case 14351ULL: goto x86_l_380f;
	case 14356ULL: goto x86_l_3814;
	case 14361ULL: goto x86_l_3819;
	case 14366ULL: goto x86_l_381e;
	case 14371ULL: goto x86_l_3823;
	case 14376ULL: goto x86_l_3828;
	case 14379ULL: goto x86_l_382b;
	case 14381ULL: goto x86_l_382d;
	case 14386ULL: goto x86_l_3832;
	case 14392ULL: goto x86_l_3838;
	case 14400ULL: goto x86_l_3840;
	case 14405ULL: goto x86_l_3845;
	case 14410ULL: goto x86_l_384a;
	case 14415ULL: goto x86_l_384f;
	case 14418ULL: goto x86_l_3852;
	case 14420ULL: goto x86_l_3854;
	case 14424ULL: goto x86_l_3858;
	case 14429ULL: goto x86_l_385d;
	case 14434ULL: goto x86_l_3862;
	case 14439ULL: goto x86_l_3867;
	case 14444ULL: goto x86_l_386c;
	case 14447ULL: goto x86_l_386f;
	case 14449ULL: goto x86_l_3871;
	case 14454ULL: goto x86_l_3876;
	case 14459ULL: goto x86_l_387b;
	case 14463ULL: goto x86_l_387f;
	case 14466ULL: goto x86_l_3882;
	case 14471ULL: goto x86_l_3887;
	case 14473ULL: goto x86_l_3889;
	case 14475ULL: goto x86_l_388b;
	case 14478ULL: goto x86_l_388e;
	case 14481ULL: goto x86_l_3891;
	case 14486ULL: goto x86_l_3896;
	case 14488ULL: goto x86_l_3898;
	case 14491ULL: goto x86_l_389b;
	case 14495ULL: goto x86_l_389f;
	case 14497ULL: goto x86_l_38a1;
	case 14501ULL: goto x86_l_38a5;
	case 14503ULL: goto x86_l_38a7;
	case 14506ULL: goto x86_l_38aa;
	case 14508ULL: goto x86_l_38ac;
	case 14512ULL: goto x86_l_38b0;
	case 14515ULL: goto x86_l_38b3;
	case 14521ULL: goto x86_l_38b9;
	case 14527ULL: goto x86_l_38bf;
	case 14533ULL: goto x86_l_38c5;
	case 14536ULL: goto x86_l_38c8;
	case 14538ULL: goto x86_l_38ca;
	case 14543ULL: goto x86_l_38cf;
	case 14545ULL: goto x86_l_38d1;
	case 14548ULL: goto x86_l_38d4;
	case 14552ULL: goto x86_l_38d8;
	case 14555ULL: goto x86_l_38db;
	case 14558ULL: goto x86_l_38de;
	case 14561ULL: goto x86_l_38e1;
	case 14566ULL: goto x86_l_38e6;
	case 14568ULL: goto x86_l_38e8;
	case 14573ULL: goto x86_l_38ed;
	case 14576ULL: goto x86_l_38f0;
	case 14582ULL: goto x86_l_38f6;
	case 14590ULL: goto x86_l_38fe;
	case 14595ULL: goto x86_l_3903;
	case 14600ULL: goto x86_l_3908;
	case 14605ULL: goto x86_l_390d;
	case 14610ULL: goto x86_l_3912;
	case 14615ULL: goto x86_l_3917;
	case 14622ULL: goto x86_l_391e;
	case 14627ULL: goto x86_l_3923;
	case 14629ULL: goto x86_l_3925;
	case 14634ULL: goto x86_l_392a;
	case 14638ULL: goto x86_l_392e;
	case 14642ULL: goto x86_l_3932;
	case 14647ULL: goto x86_l_3937;
	case 14651ULL: goto x86_l_393b;
	case 14657ULL: goto x86_l_3941;
	case 14667ULL: goto x86_l_394b;
	case 14671ULL: goto x86_l_394f;
	case 14677ULL: goto x86_l_3955;
	case 14681ULL: goto x86_l_3959;
	case 14684ULL: goto x86_l_395c;
	case 14689ULL: goto x86_l_3961;
	case 14692ULL: goto x86_l_3964;
	case 14697ULL: goto x86_l_3969;
	case 14702ULL: goto x86_l_396e;
	case 14710ULL: goto x86_l_3976;
	case 14714ULL: goto x86_l_397a;
	case 14717ULL: goto x86_l_397d;
	case 14722ULL: goto x86_l_3982;
	case 14724ULL: goto x86_l_3984;
	case 14727ULL: goto x86_l_3987;
	case 14735ULL: goto x86_l_398f;
	case 14739ULL: goto x86_l_3993;
	case 14744ULL: goto x86_l_3998;
	case 14749ULL: goto x86_l_399d;
	case 14756ULL: goto x86_l_39a4;
	case 14760ULL: goto x86_l_39a8;
	case 14765ULL: goto x86_l_39ad;
	case 14770ULL: goto x86_l_39b2;
	case 14773ULL: goto x86_l_39b5;
	case 14778ULL: goto x86_l_39ba;
	case 14780ULL: goto x86_l_39bc;
	case 14784ULL: goto x86_l_39c0;
	case 14788ULL: goto x86_l_39c4;
	case 14793ULL: goto x86_l_39c9;
	case 14798ULL: goto x86_l_39ce;
	case 14803ULL: goto x86_l_39d3;
	case 14806ULL: goto x86_l_39d6;
	case 14808ULL: goto x86_l_39d8;
	case 14812ULL: goto x86_l_39dc;
	case 14814ULL: goto x86_l_39de;
	case 14818ULL: goto x86_l_39e2;
	case 14821ULL: goto x86_l_39e5;
	case 14827ULL: goto x86_l_39eb;
	case 14832ULL: goto x86_l_39f0;
	case 14841ULL: goto x86_l_39f9;
	case 14845ULL: goto x86_l_39fd;
	case 14850ULL: goto x86_l_3a02;
	case 14854ULL: goto x86_l_3a06;
	case 14859ULL: goto x86_l_3a0b;
	case 14864ULL: goto x86_l_3a10;
	case 14869ULL: goto x86_l_3a15;
	case 14871ULL: goto x86_l_3a17;
	case 14875ULL: goto x86_l_3a1b;
	case 14879ULL: goto x86_l_3a1f;
	case 14883ULL: goto x86_l_3a23;
	case 14888ULL: goto x86_l_3a28;
	case 14893ULL: goto x86_l_3a2d;
	case 14895ULL: goto x86_l_3a2f;
	case 14900ULL: goto x86_l_3a34;
	case 14909ULL: goto x86_l_3a3d;
	case 14913ULL: goto x86_l_3a41;
	case 14918ULL: goto x86_l_3a46;
	case 14922ULL: goto x86_l_3a4a;
	case 14927ULL: goto x86_l_3a4f;
	case 14932ULL: goto x86_l_3a54;
	case 14937ULL: goto x86_l_3a59;
	case 14939ULL: goto x86_l_3a5b;
	case 14943ULL: goto x86_l_3a5f;
	case 14947ULL: goto x86_l_3a63;
	case 14951ULL: goto x86_l_3a67;
	case 14956ULL: goto x86_l_3a6c;
	case 14961ULL: goto x86_l_3a71;
	case 14966ULL: goto x86_l_3a76;
	case 14968ULL: goto x86_l_3a78;
	case 14970ULL: goto x86_l_3a7a;
	case 14975ULL: goto x86_l_3a7f;
	case 14982ULL: goto x86_l_3a86;
	case 14986ULL: goto x86_l_3a8a;
	case 14990ULL: goto x86_l_3a8e;
	case 14996ULL: goto x86_l_3a94;
	case 15002ULL: goto x86_l_3a9a;
	case 15009ULL: goto x86_l_3aa1;
	case 15014ULL: goto x86_l_3aa6;
	case 15019ULL: goto x86_l_3aab;
	case 15024ULL: goto x86_l_3ab0;
	case 15030ULL: goto x86_l_3ab6;
	case 15035ULL: goto x86_l_3abb;
	case 15038ULL: goto x86_l_3abe;
	case 15040ULL: goto x86_l_3ac0;
	case 15045ULL: goto x86_l_3ac5;
	case 15048ULL: goto x86_l_3ac8;
	case 15050ULL: goto x86_l_3aca;
	case 15054ULL: goto x86_l_3ace;
	case 15062ULL: goto x86_l_3ad6;
	case 15067ULL: goto x86_l_3adb;
	case 15072ULL: goto x86_l_3ae0;
	case 15077ULL: goto x86_l_3ae5;
	case 15081ULL: goto x86_l_3ae9;
	case 15086ULL: goto x86_l_3aee;
	case 15088ULL: goto x86_l_3af0;
	case 15093ULL: goto x86_l_3af5;
	case 15101ULL: goto x86_l_3afd;
	case 15105ULL: goto x86_l_3b01;
	case 15110ULL: goto x86_l_3b06;
	case 15114ULL: goto x86_l_3b0a;
	case 15119ULL: goto x86_l_3b0f;
	case 15124ULL: goto x86_l_3b14;
	case 15126ULL: goto x86_l_3b16;
	case 15130ULL: goto x86_l_3b1a;
	case 15134ULL: goto x86_l_3b1e;
	case 15138ULL: goto x86_l_3b22;
	case 15143ULL: goto x86_l_3b27;
	case 15146ULL: goto x86_l_3b2a;
	case 15151ULL: goto x86_l_3b2f;
	case 15153ULL: goto x86_l_3b31;
	case 15159ULL: goto x86_l_3b37;
	case 15164ULL: goto x86_l_3b3c;
	case 15172ULL: goto x86_l_3b44;
	case 15177ULL: goto x86_l_3b49;
	case 15182ULL: goto x86_l_3b4e;
	case 15190ULL: goto x86_l_3b56;
	case 15193ULL: goto x86_l_3b59;
	case 15195ULL: goto x86_l_3b5b;
	case 15202ULL: goto x86_l_3b62;
	case 15206ULL: goto x86_l_3b66;
	case 15209ULL: goto x86_l_3b69;
	case 15211ULL: goto x86_l_3b6b;
	case 15222ULL: goto x86_l_3b76;
	case 15234ULL: goto x86_l_3b82;
	case 15242ULL: goto x86_l_3b8a;
	case 15245ULL: goto x86_l_3b8d;
	case 15248ULL: goto x86_l_3b90;
	case 15252ULL: goto x86_l_3b94;
	case 15255ULL: goto x86_l_3b97;
	case 15257ULL: goto x86_l_3b99;
	case 15265ULL: goto x86_l_3ba1;
	case 15272ULL: goto x86_l_3ba8;
	case 15277ULL: goto x86_l_3bad;
	case 15282ULL: goto x86_l_3bb2;
	case 15284ULL: goto x86_l_3bb4;
	case 15287ULL: goto x86_l_3bb7;
	case 15289ULL: goto x86_l_3bb9;
	case 15292ULL: goto x86_l_3bbc;
	case 15299ULL: goto x86_l_3bc3;
	case 15306ULL: goto x86_l_3bca;
	case 15311ULL: goto x86_l_3bcf;
	case 15313ULL: goto x86_l_3bd1;
	case 15316ULL: goto x86_l_3bd4;
	case 15318ULL: goto x86_l_3bd6;
	case 15320ULL: goto x86_l_3bd8;
	case 15322ULL: goto x86_l_3bda;
	case 15325ULL: goto x86_l_3bdd;
	case 15330ULL: goto x86_l_3be2;
	case 15332ULL: goto x86_l_3be4;
	case 15339ULL: goto x86_l_3beb;
	case 15346ULL: goto x86_l_3bf2;
	case 15351ULL: goto x86_l_3bf7;
	case 15356ULL: goto x86_l_3bfc;
	case 15359ULL: goto x86_l_3bff;
	case 15364ULL: goto x86_l_3c04;
	case 15366ULL: goto x86_l_3c06;
	case 15377ULL: goto x86_l_3c11;
	case 15384ULL: goto x86_l_3c18;
	case 15389ULL: goto x86_l_3c1d;
	case 15394ULL: goto x86_l_3c22;
	case 15397ULL: goto x86_l_3c25;
	case 15402ULL: goto x86_l_3c2a;
	case 15404ULL: goto x86_l_3c2c;
	case 15406ULL: goto x86_l_3c2e;
	case 15413ULL: goto x86_l_3c35;
	case 15414ULL: goto x86_l_3c36;
	case 15416ULL: goto x86_l_3c38;
	case 15418ULL: goto x86_l_3c3a;
	case 15420ULL: goto x86_l_3c3c;
	case 15422ULL: goto x86_l_3c3e;
	case 15423ULL: goto x86_l_3c3f;
	case 15428ULL: goto x86_l_3c44;
	case 15436ULL: goto x86_l_3c4c;
	case 15441ULL: goto x86_l_3c51;
	case 15445ULL: goto x86_l_3c55;
	case 15450ULL: goto x86_l_3c5a;
	case 15455ULL: goto x86_l_3c5f;
	case 15460ULL: goto x86_l_3c64;
	case 15465ULL: goto x86_l_3c69;
	case 15467ULL: goto x86_l_3c6b;
	case 15472ULL: goto x86_l_3c70;
	case 15477ULL: goto x86_l_3c75;
	case 15483ULL: goto x86_l_3c7b;
	case 15487ULL: goto x86_l_3c7f;
	case 15492ULL: goto x86_l_3c84;
	case 15497ULL: goto x86_l_3c89;
	case 15502ULL: goto x86_l_3c8e;
	case 15507ULL: goto x86_l_3c93;
	case 15510ULL: goto x86_l_3c96;
	case 15512ULL: goto x86_l_3c98;
	case 15517ULL: goto x86_l_3c9d;
	case 15522ULL: goto x86_l_3ca2;
	case 15526ULL: goto x86_l_3ca6;
	case 15531ULL: goto x86_l_3cab;
	case 15536ULL: goto x86_l_3cb0;
	case 15541ULL: goto x86_l_3cb5;
	case 15543ULL: goto x86_l_3cb7;
	case 15548ULL: goto x86_l_3cbc;
	case 15554ULL: goto x86_l_3cc2;
	case 15562ULL: goto x86_l_3cca;
	case 15567ULL: goto x86_l_3ccf;
	case 15572ULL: goto x86_l_3cd4;
	case 15577ULL: goto x86_l_3cd9;
	case 15579ULL: goto x86_l_3cdb;
	case 15587ULL: goto x86_l_3ce3;
	case 15593ULL: goto x86_l_3ce9;
	case 15598ULL: goto x86_l_3cee;
	case 15603ULL: goto x86_l_3cf3;
	case 15608ULL: goto x86_l_3cf8;
	case 15613ULL: goto x86_l_3cfd;
	case 15618ULL: goto x86_l_3d02;
	case 15621ULL: goto x86_l_3d05;
	case 15623ULL: goto x86_l_3d07;
	case 15628ULL: goto x86_l_3d0c;
	case 15634ULL: goto x86_l_3d12;
	case 15642ULL: goto x86_l_3d1a;
	case 15647ULL: goto x86_l_3d1f;
	case 15652ULL: goto x86_l_3d24;
	case 15657ULL: goto x86_l_3d29;
	case 15660ULL: goto x86_l_3d2c;
	case 15662ULL: goto x86_l_3d2e;
	case 15666ULL: goto x86_l_3d32;
	case 15671ULL: goto x86_l_3d37;
	case 15676ULL: goto x86_l_3d3c;
	case 15681ULL: goto x86_l_3d41;
	case 15686ULL: goto x86_l_3d46;
	case 15689ULL: goto x86_l_3d49;
	case 15691ULL: goto x86_l_3d4b;
	case 15696ULL: goto x86_l_3d50;
	case 15701ULL: goto x86_l_3d55;
	case 15705ULL: goto x86_l_3d59;
	case 15708ULL: goto x86_l_3d5c;
	case 15713ULL: goto x86_l_3d61;
	case 15715ULL: goto x86_l_3d63;
	case 15717ULL: goto x86_l_3d65;
	case 15720ULL: goto x86_l_3d68;
	case 15723ULL: goto x86_l_3d6b;
	case 15728ULL: goto x86_l_3d70;
	case 15730ULL: goto x86_l_3d72;
	case 15733ULL: goto x86_l_3d75;
	case 15737ULL: goto x86_l_3d79;
	case 15739ULL: goto x86_l_3d7b;
	case 15743ULL: goto x86_l_3d7f;
	case 15745ULL: goto x86_l_3d81;
	case 15748ULL: goto x86_l_3d84;
	case 15750ULL: goto x86_l_3d86;
	case 15754ULL: goto x86_l_3d8a;
	case 15757ULL: goto x86_l_3d8d;
	case 15763ULL: goto x86_l_3d93;
	case 15769ULL: goto x86_l_3d99;
	case 15775ULL: goto x86_l_3d9f;
	case 15778ULL: goto x86_l_3da2;
	case 15780ULL: goto x86_l_3da4;
	case 15785ULL: goto x86_l_3da9;
	case 15787ULL: goto x86_l_3dab;
	case 15790ULL: goto x86_l_3dae;
	case 15794ULL: goto x86_l_3db2;
	case 15797ULL: goto x86_l_3db5;
	case 15800ULL: goto x86_l_3db8;
	case 15803ULL: goto x86_l_3dbb;
	case 15808ULL: goto x86_l_3dc0;
	case 15810ULL: goto x86_l_3dc2;
	case 15815ULL: goto x86_l_3dc7;
	case 15818ULL: goto x86_l_3dca;
	case 15824ULL: goto x86_l_3dd0;
	case 15832ULL: goto x86_l_3dd8;
	case 15837ULL: goto x86_l_3ddd;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3744:
	/* 0x3744: je     3761 <generic_rawtp_process_event+0x3761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3761;
	}
x86_l_3746:
	/* 0x3746: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_374b:
	/* 0x374b: jne    3925 <generic_rawtp_process_event+0x3925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3925;
	}
x86_l_3751:
	/* 0x3751: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_3758:
	/* 0x3758: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_375c:
	/* 0x375c: jmp    392a <generic_rawtp_process_event+0x392a> */
	goto x86_l_392a;
x86_l_3761:
	/* 0x3761: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3766:
	/* 0x3766: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_376d:
	/* 0x376d: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3772:
	/* 0x3772: jmp    392a <generic_rawtp_process_event+0x392a> */
	goto x86_l_392a;
x86_l_3777:
	/* 0x3777: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_377b:
	/* 0x377b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3780:
	/* 0x3780: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3785:
	/* 0x3785: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_378a:
	/* 0x378a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_378f:
	/* 0x378f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3791:
	/* 0x3791: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3796:
	/* 0x3796: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_379b:
	/* 0x379b: je     974 <generic_rawtp_process_event+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2420ULL;
	}
x86_l_37a1:
	/* 0x37a1: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_37a5:
	/* 0x37a5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_37aa:
	/* 0x37aa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37af:
	/* 0x37af: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_37b4:
	/* 0x37b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37b9:
	/* 0x37b9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_37bc:
	/* 0x37bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37be:
	/* 0x37be: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37c3:
	/* 0x37c3: mov    QWORD PTR [rsp+0x50],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_37c8:
	/* 0x37c8: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_37cc:
	/* 0x37cc: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_37d1:
	/* 0x37d1: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_37d6:
	/* 0x37d6: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_37db:
	/* 0x37db: jne    37e8 <generic_rawtp_process_event+0x37e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_37e8;
	}
x86_l_37dd:
	/* 0x37dd: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_37e2:
	/* 0x37e2: je     974 <generic_rawtp_process_event+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2420ULL;
	}
x86_l_37e8:
	/* 0x37e8: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_37f0:
	/* 0x37f0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_37f5:
	/* 0x37f5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37fa:
	/* 0x37fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37ff:
	/* 0x37ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3801:
	/* 0x3801: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_3809:
	/* 0x3809: je     3c51 <generic_rawtp_process_event+0x3c51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c51;
	}
x86_l_380f:
	/* 0x380f: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3814:
	/* 0x3814: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3819:
	/* 0x3819: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_381e:
	/* 0x381e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3823:
	/* 0x3823: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3828:
	/* 0x3828: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_382b:
	/* 0x382b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_382d:
	/* 0x382d: cmp    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3832:
	/* 0x3832: je     3c51 <generic_rawtp_process_event+0x3c51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c51;
	}
x86_l_3838:
	/* 0x3838: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3840:
	/* 0x3840: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3845:
	/* 0x3845: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_384a:
	/* 0x384a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_384f:
	/* 0x384f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3852:
	/* 0x3852: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3854:
	/* 0x3854: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3858:
	/* 0x3858: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_385d:
	/* 0x385d: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3862:
	/* 0x3862: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3867:
	/* 0x3867: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_386c:
	/* 0x386c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_386f:
	/* 0x386f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3871:
	/* 0x3871: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3876:
	/* 0x3876: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_387b:
	/* 0x387b: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_387f:
	/* 0x387f: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3882:
	/* 0x3882: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3887:
	/* 0x3887: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3889:
	/* 0x3889: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_388b:
	/* 0x388b: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_388e:
	/* 0x388e: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_3891:
	/* 0x3891: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_3896:
	/* 0x3896: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3898:
	/* 0x3898: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_389b:
	/* 0x389b: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_389f:
	/* 0x389f: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_38a1:
	/* 0x38a1: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_38a5:
	/* 0x38a5: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_38a7:
	/* 0x38a7: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_38aa:
	/* 0x38aa: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_38ac:
	/* 0x38ac: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_38b0:
	/* 0x38b0: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_38b3:
	/* 0x38b3: jb     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2425ULL;
	}
x86_l_38b9:
	/* 0x38b9: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_38bf:
	/* 0x38bf: ja     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2425ULL;
	}
x86_l_38c5:
	/* 0x38c5: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_38c8:
	/* 0x38c8: jbe    38cf <generic_rawtp_process_event+0x38cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_38cf;
	}
x86_l_38ca:
	/* 0x38ca: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_38cf:
	/* 0x38cf: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_38d1:
	/* 0x38d1: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_38d4:
	/* 0x38d4: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_38d8:
	/* 0x38d8: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_38db:
	/* 0x38db: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_38de:
	/* 0x38de: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_38e1:
	/* 0x38e1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_38e6:
	/* 0x38e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38e8:
	/* 0x38e8: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_38ed:
	/* 0x38ed: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_38f0:
	/* 0x38f0: jbe    979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2425ULL;
	}
x86_l_38f6:
	/* 0x38f6: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_38fe:
	/* 0x38fe: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3903:
	/* 0x3903: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3908:
	/* 0x3908: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_390d:
	/* 0x390d: jmp    3cb0 <generic_rawtp_process_event+0x3cb0> */
	goto x86_l_3cb0;
x86_l_3912:
	/* 0x3912: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3917:
	/* 0x3917: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_391e:
	/* 0x391e: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3923:
	/* 0x3923: jmp    392a <generic_rawtp_process_event+0x392a> */
	goto x86_l_392a;
x86_l_3925:
	/* 0x3925: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_392a:
	/* 0x392a: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_392e:
	/* 0x392e: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3932:
	/* 0x3932: movzx  r12d,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_3937:
	/* 0x3937: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_393b:
	/* 0x393b: ja     3c44 <generic_rawtp_process_event+0x3c44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3c44;
	}
x86_l_3941:
	/* 0x3941: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_394b:
	/* 0x394b: bt     rcx,r12 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_394f:
	/* 0x394f: jae    3c44 <generic_rawtp_process_event+0x3c44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3c44;
	}
x86_l_3955:
	/* 0x3955: mov    BYTE PTR [r15+0x5],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_3959:
	/* 0x3959: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_395c:
	/* 0x395c: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3961:
	/* 0x3961: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3964:
	/* 0x3964: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3969:
	/* 0x3969: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_396e:
	/* 0x396e: mov    rdi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3976:
	/* 0x3976: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_397a:
	/* 0x397a: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_397d:
	/* 0x397d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3982:
	/* 0x3982: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3984:
	/* 0x3984: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3987:
	/* 0x3987: mov    BYTE PTR [rsp+0xd8],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_398f:
	/* 0x398f: movzx  eax,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3993:
	/* 0x3993: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3998:
	/* 0x3998: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_399d:
	/* 0x399d: mov    WORD PTR [r15+0x26],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757258ULL);
x86_l_39a4:
	/* 0x39a4: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39a8:
	/* 0x39a8: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_39ad:
	/* 0x39ad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_39b2:
	/* 0x39b2: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_39b5:
	/* 0x39b5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_39ba:
	/* 0x39ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39bc:
	/* 0x39bc: lea    rdi,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39c0:
	/* 0x39c0: add    rbp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_39c4:
	/* 0x39c4: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_39c9:
	/* 0x39c9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_39ce:
	/* 0x39ce: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_39d3:
	/* 0x39d3: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_39d6:
	/* 0x39d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39d8:
	/* 0x39d8: cmp    r12b,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 17ULL);
x86_l_39dc:
	/* 0x39dc: je     3a2f <generic_rawtp_process_event+0x3a2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a2f;
	}
x86_l_39de:
	/* 0x39de: movzx  eax,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_39e2:
	/* 0x39e2: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_39e5:
	/* 0x39e5: jne    3a7a <generic_rawtp_process_event+0x3a7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3a7a;
	}
x86_l_39eb:
	/* 0x39eb: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_39f0:
	/* 0x39f0: movzx  r12d,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_39f9:
	/* 0x39f9: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_39fd:
	/* 0x39fd: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a02:
	/* 0x3a02: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3a06:
	/* 0x3a06: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3a0b:
	/* 0x3a0b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a10:
	/* 0x3a10: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3a15:
	/* 0x3a15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a17:
	/* 0x3a17: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_3a1b:
	/* 0x3a1b: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3a1f:
	/* 0x3a1f: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_3a23:
	/* 0x3a23: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3a28:
	/* 0x3a28: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a2d:
	/* 0x3a2d: jmp    3a71 <generic_rawtp_process_event+0x3a71> */
	goto x86_l_3a71;
x86_l_3a2f:
	/* 0x3a2f: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3a34:
	/* 0x3a34: movzx  r12d,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_3a3d:
	/* 0x3a3d: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3a41:
	/* 0x3a41: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a46:
	/* 0x3a46: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3a4a:
	/* 0x3a4a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3a4f:
	/* 0x3a4f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a54:
	/* 0x3a54: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3a59:
	/* 0x3a59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a5b:
	/* 0x3a5b: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_3a5f:
	/* 0x3a5f: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3a63:
	/* 0x3a63: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_3a67:
	/* 0x3a67: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3a6c:
	/* 0x3a6c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a71:
	/* 0x3a71: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3a76:
	/* 0x3a76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a78:
	/* 0x3a78: jmp    3a86 <generic_rawtp_process_event+0x3a86> */
	goto x86_l_3a86;
x86_l_3a7a:
	/* 0x3a7a: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a7f:
	/* 0x3a7f: mov    DWORD PTR [rbp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3a86:
	/* 0x3a86: movzx  eax,WORD PTR [rbp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_3a8a:
	/* 0x3a8a: movzx  ecx,WORD PTR [rbp+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_3a8e:
	/* 0x3a8e: movbe  WORD PTR [rbp+0x20],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_3a94:
	/* 0x3a94: movbe  WORD PTR [rbp+0x22],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_3a9a:
	/* 0x3a9a: add    r13,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_3aa1:
	/* 0x3aa1: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3aa6:
	/* 0x3aa6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3aab:
	/* 0x3aab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ab0:
	/* 0x3ab0: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_3ab6:
	/* 0x3ab6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3abb:
	/* 0x3abb: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3abe:
	/* 0x3abe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ac0:
	/* 0x3ac0: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3ac5:
	/* 0x3ac5: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_3ac8:
	/* 0x3ac8: je     3b31 <generic_rawtp_process_event+0x3b31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b31;
	}
x86_l_3aca:
	/* 0x3aca: add    rcx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_3ace:
	/* 0x3ace: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3ad6:
	/* 0x3ad6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3adb:
	/* 0x3adb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ae0:
	/* 0x3ae0: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3ae5:
	/* 0x3ae5: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_3ae9:
	/* 0x3ae9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3aee:
	/* 0x3aee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3af0:
	/* 0x3af0: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3af5:
	/* 0x3af5: mov    r13,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3afd:
	/* 0x3afd: lea    rdx,[r12+r13*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 0ULL);
x86_l_3b01:
	/* 0x3b01: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b06:
	/* 0x3b06: lea    rdi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3b0a:
	/* 0x3b0a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b0f:
	/* 0x3b0f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3b14:
	/* 0x3b14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b16:
	/* 0x3b16: add    rbp,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 60ULL);
x86_l_3b1a:
	/* 0x3b1a: lea    rdx,[r12+r13*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 0ULL);
x86_l_3b1e:
	/* 0x3b1e: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3b22:
	/* 0x3b22: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b27:
	/* 0x3b27: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_3b2a:
	/* 0x3b2a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3b2f:
	/* 0x3b2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b31:
	/* 0x3b31: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_3b37:
	/* 0x3b37: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3b3c:
	/* 0x3b3c: mov    rbp,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3b44:
	/* 0x3b44: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b49:
	/* 0x3b49: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3b4e:
	/* 0x3b4e: mov    r12,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3b56:
	/* 0x3b56: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_3b59:
	/* 0x3b59: js     3b6b <generic_rawtp_process_event+0x3b6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b6b;
	}
x86_l_3b5b:
	/* 0x3b5b: and    r15d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3b62:
	/* 0x3b62: add    r15,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3b66:
	/* 0x3b66: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3b69:
	/* 0x3b69: jmp    3b82 <generic_rawtp_process_event+0x3b82> */
	goto x86_l_3b82;
x86_l_3b6b:
	/* 0x3b6b: mov    DWORD PTR [rax+rdx*4+0x5ea0],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 104045582745599ULL);
x86_l_3b76:
	/* 0x3b76: mov    DWORD PTR [rax+r12*1+0x90],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 622770257919ULL);
x86_l_3b82:
	/* 0x3b82: mov    r12,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3b8a:
	/* 0x3b8a: add    esi,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3b8d:
	/* 0x3b8d: mov    r12d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_32);
x86_l_3b90:
	/* 0x3b90: mov    DWORD PTR [r14+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3b94:
	/* 0x3b94: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_3b97:
	/* 0x3b97: jg     3c06 <generic_rawtp_process_event+0x3c06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3c06;
	}
x86_l_3b99:
	/* 0x3b99: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_3ba1:
	/* 0x3ba1: mov    rdi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_3ba8:
	/* 0x3ba8: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3bad:
	/* 0x3bad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3bb2:
	/* 0x3bb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bb4:
	/* 0x3bb4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3bb7:
	/* 0x3bb7: je     3c06 <generic_rawtp_process_event+0x3c06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c06;
	}
x86_l_3bb9:
	/* 0x3bb9: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_3bbc:
	/* 0x3bbc: add    rsi,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_3bc3:
	/* 0x3bc3: mov    rdi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_3bca:
	/* 0x3bca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3bcf:
	/* 0x3bcf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bd1:
	/* 0x3bd1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3bd4:
	/* 0x3bd4: je     3c06 <generic_rawtp_process_event+0x3c06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c06;
	}
x86_l_3bd6:
	/* 0x3bd6: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3bd8:
	/* 0x3bd8: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_3bda:
	/* 0x3bda: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_3bdd:
	/* 0x3bdd: cmp    DWORD PTR [rax+rcx*4+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 279172874239ULL);
x86_l_3be2:
	/* 0x3be2: je     3c06 <generic_rawtp_process_event+0x3c06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c06;
	}
x86_l_3be4:
	/* 0x3be4: mov    DWORD PTR [r14+0x5eec],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24300ULL);
x86_l_3beb:
	/* 0x3beb: mov    rsi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tp_calls)));
x86_l_3bf2:
	/* 0x3bf2: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3bf7:
	/* 0x3bf7: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3bfc:
	/* 0x3bfc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3bff:
	/* 0x3bff: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_3c04:
	/* 0x3c04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c06:
	/* 0x3c06: mov    DWORD PTR [r14+0x5eec],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104367705292800ULL);
x86_l_3c11:
	/* 0x3c11: mov    rsi,QWORD PTR [rip+0x1d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tp_calls)));
x86_l_3c18:
	/* 0x3c18: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_3c1d:
	/* 0x3c1d: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3c22:
	/* 0x3c22: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3c25:
	/* 0x3c25: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3c2a:
	/* 0x3c2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c2c:
	/* 0x3c2c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c2e:
	/* 0x3c2e: add    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_3c35:
	/* 0x3c35: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3c36:
	/* 0x3c36: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3c38:
	/* 0x3c38: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_3c3a:
	/* 0x3c3a: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3c3c:
	/* 0x3c3c: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3c3e:
	/* 0x3c3e: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3c3f:
	/* 0x3c3f: jmp    3fc6 <generic_rawtp_process_event+0x3fc6> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3c44:
	/* 0x3c44: mov    WORD PTR [rsp+0xc8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_3c4c:
	/* 0x3c4c: jmp    3987 <generic_rawtp_process_event+0x3987> */
	goto x86_l_3987;
x86_l_3c51:
	/* 0x3c51: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c55:
	/* 0x3c55: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c5a:
	/* 0x3c5a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3c5f:
	/* 0x3c5f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c64:
	/* 0x3c64: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c69:
	/* 0x3c69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c6b:
	/* 0x3c6b: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3c70:
	/* 0x3c70: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_3c75:
	/* 0x3c75: je     974 <generic_rawtp_process_event+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2420ULL;
	}
x86_l_3c7b:
	/* 0x3c7b: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3c7f:
	/* 0x3c7f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3c84:
	/* 0x3c84: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c89:
	/* 0x3c89: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3c8e:
	/* 0x3c8e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c93:
	/* 0x3c93: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3c96:
	/* 0x3c96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c98:
	/* 0x3c98: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c9d:
	/* 0x3c9d: mov    QWORD PTR [rsp+0x50],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3ca2:
	/* 0x3ca2: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3ca6:
	/* 0x3ca6: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3cab:
	/* 0x3cab: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3cb0:
	/* 0x3cb0: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_3cb5:
	/* 0x3cb5: jne    3cc2 <generic_rawtp_process_event+0x3cc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3cc2;
	}
x86_l_3cb7:
	/* 0x3cb7: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_3cbc:
	/* 0x3cbc: je     974 <generic_rawtp_process_event+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2420ULL;
	}
x86_l_3cc2:
	/* 0x3cc2: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3cca:
	/* 0x3cca: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3ccf:
	/* 0x3ccf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3cd4:
	/* 0x3cd4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cd9:
	/* 0x3cd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cdb:
	/* 0x3cdb: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_3ce3:
	/* 0x3ce3: je     3de9 <generic_rawtp_process_event+0x3de9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15849ULL;
	}
x86_l_3ce9:
	/* 0x3ce9: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3cee:
	/* 0x3cee: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3cf3:
	/* 0x3cf3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3cf8:
	/* 0x3cf8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3cfd:
	/* 0x3cfd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d02:
	/* 0x3d02: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3d05:
	/* 0x3d05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d07:
	/* 0x3d07: cmp    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d0c:
	/* 0x3d0c: je     3de9 <generic_rawtp_process_event+0x3de9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15849ULL;
	}
x86_l_3d12:
	/* 0x3d12: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3d1a:
	/* 0x3d1a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3d1f:
	/* 0x3d1f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d24:
	/* 0x3d24: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d29:
	/* 0x3d29: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3d2c:
	/* 0x3d2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d2e:
	/* 0x3d2e: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3d32:
	/* 0x3d32: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3d37:
	/* 0x3d37: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3d3c:
	/* 0x3d3c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d41:
	/* 0x3d41: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3d46:
	/* 0x3d46: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3d49:
	/* 0x3d49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d4b:
	/* 0x3d4b: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3d50:
	/* 0x3d50: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3d55:
	/* 0x3d55: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_3d59:
	/* 0x3d59: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3d5c:
	/* 0x3d5c: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3d61:
	/* 0x3d61: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3d63:
	/* 0x3d63: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_3d65:
	/* 0x3d65: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3d68:
	/* 0x3d68: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_3d6b:
	/* 0x3d6b: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_3d70:
	/* 0x3d70: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3d72:
	/* 0x3d72: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3d75:
	/* 0x3d75: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_3d79:
	/* 0x3d79: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_3d7b:
	/* 0x3d7b: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_3d7f:
	/* 0x3d7f: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3d81:
	/* 0x3d81: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_3d84:
	/* 0x3d84: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3d86:
	/* 0x3d86: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3d8a:
	/* 0x3d8a: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3d8d:
	/* 0x3d8d: jb     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2425ULL;
	}
x86_l_3d93:
	/* 0x3d93: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_3d99:
	/* 0x3d99: ja     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2425ULL;
	}
x86_l_3d9f:
	/* 0x3d9f: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3da2:
	/* 0x3da2: jbe    3da9 <generic_rawtp_process_event+0x3da9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3da9;
	}
x86_l_3da4:
	/* 0x3da4: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_3da9:
	/* 0x3da9: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3dab:
	/* 0x3dab: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3dae:
	/* 0x3dae: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_3db2:
	/* 0x3db2: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3db5:
	/* 0x3db5: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3db8:
	/* 0x3db8: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3dbb:
	/* 0x3dbb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3dc0:
	/* 0x3dc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dc2:
	/* 0x3dc2: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3dc7:
	/* 0x3dc7: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3dca:
	/* 0x3dca: jbe    979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2425ULL;
	}
x86_l_3dd0:
	/* 0x3dd0: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3dd8:
	/* 0x3dd8: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3ddd:
	/* 0x3ddd: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
	return 15842ULL;
}

static __noinline __u64 tetragon_bpf_generic_rawtp_generic_rawtp_process_event_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15842ULL: goto x86_l_3de2;
	case 15847ULL: goto x86_l_3de7;
	case 15849ULL: goto x86_l_3de9;
	case 15853ULL: goto x86_l_3ded;
	case 15858ULL: goto x86_l_3df2;
	case 15863ULL: goto x86_l_3df7;
	case 15868ULL: goto x86_l_3dfc;
	case 15873ULL: goto x86_l_3e01;
	case 15875ULL: goto x86_l_3e03;
	case 15880ULL: goto x86_l_3e08;
	case 15885ULL: goto x86_l_3e0d;
	case 15891ULL: goto x86_l_3e13;
	case 15895ULL: goto x86_l_3e17;
	case 15900ULL: goto x86_l_3e1c;
	case 15905ULL: goto x86_l_3e21;
	case 15910ULL: goto x86_l_3e26;
	case 15915ULL: goto x86_l_3e2b;
	case 15918ULL: goto x86_l_3e2e;
	case 15920ULL: goto x86_l_3e30;
	case 15925ULL: goto x86_l_3e35;
	case 15930ULL: goto x86_l_3e3a;
	case 15934ULL: goto x86_l_3e3e;
	case 15939ULL: goto x86_l_3e43;
	case 15944ULL: goto x86_l_3e48;
	case 15949ULL: goto x86_l_3e4d;
	case 15951ULL: goto x86_l_3e4f;
	case 15956ULL: goto x86_l_3e54;
	case 15962ULL: goto x86_l_3e5a;
	case 15970ULL: goto x86_l_3e62;
	case 15975ULL: goto x86_l_3e67;
	case 15980ULL: goto x86_l_3e6c;
	case 15985ULL: goto x86_l_3e71;
	case 15987ULL: goto x86_l_3e73;
	case 15995ULL: goto x86_l_3e7b;
	case 16001ULL: goto x86_l_3e81;
	case 16006ULL: goto x86_l_3e86;
	case 16011ULL: goto x86_l_3e8b;
	case 16016ULL: goto x86_l_3e90;
	case 16021ULL: goto x86_l_3e95;
	case 16026ULL: goto x86_l_3e9a;
	case 16029ULL: goto x86_l_3e9d;
	case 16031ULL: goto x86_l_3e9f;
	case 16036ULL: goto x86_l_3ea4;
	case 16042ULL: goto x86_l_3eaa;
	case 16050ULL: goto x86_l_3eb2;
	case 16055ULL: goto x86_l_3eb7;
	case 16060ULL: goto x86_l_3ebc;
	case 16065ULL: goto x86_l_3ec1;
	case 16068ULL: goto x86_l_3ec4;
	case 16070ULL: goto x86_l_3ec6;
	case 16074ULL: goto x86_l_3eca;
	case 16079ULL: goto x86_l_3ecf;
	case 16084ULL: goto x86_l_3ed4;
	case 16089ULL: goto x86_l_3ed9;
	case 16094ULL: goto x86_l_3ede;
	case 16097ULL: goto x86_l_3ee1;
	case 16099ULL: goto x86_l_3ee3;
	case 16104ULL: goto x86_l_3ee8;
	case 16109ULL: goto x86_l_3eed;
	case 16113ULL: goto x86_l_3ef1;
	case 16116ULL: goto x86_l_3ef4;
	case 16121ULL: goto x86_l_3ef9;
	case 16123ULL: goto x86_l_3efb;
	case 16125ULL: goto x86_l_3efd;
	case 16128ULL: goto x86_l_3f00;
	case 16131ULL: goto x86_l_3f03;
	case 16136ULL: goto x86_l_3f08;
	case 16138ULL: goto x86_l_3f0a;
	case 16141ULL: goto x86_l_3f0d;
	case 16145ULL: goto x86_l_3f11;
	case 16147ULL: goto x86_l_3f13;
	case 16151ULL: goto x86_l_3f17;
	case 16153ULL: goto x86_l_3f19;
	case 16156ULL: goto x86_l_3f1c;
	case 16158ULL: goto x86_l_3f1e;
	case 16162ULL: goto x86_l_3f22;
	case 16165ULL: goto x86_l_3f25;
	case 16171ULL: goto x86_l_3f2b;
	case 16177ULL: goto x86_l_3f31;
	case 16183ULL: goto x86_l_3f37;
	case 16186ULL: goto x86_l_3f3a;
	case 16188ULL: goto x86_l_3f3c;
	case 16193ULL: goto x86_l_3f41;
	case 16195ULL: goto x86_l_3f43;
	case 16198ULL: goto x86_l_3f46;
	case 16202ULL: goto x86_l_3f4a;
	case 16205ULL: goto x86_l_3f4d;
	case 16208ULL: goto x86_l_3f50;
	case 16211ULL: goto x86_l_3f53;
	case 16216ULL: goto x86_l_3f58;
	case 16218ULL: goto x86_l_3f5a;
	case 16223ULL: goto x86_l_3f5f;
	case 16226ULL: goto x86_l_3f62;
	case 16232ULL: goto x86_l_3f68;
	case 16240ULL: goto x86_l_3f70;
	case 16245ULL: goto x86_l_3f75;
	case 16250ULL: goto x86_l_3f7a;
	case 16254ULL: goto x86_l_3f7e;
	case 16259ULL: goto x86_l_3f83;
	case 16264ULL: goto x86_l_3f88;
	case 16269ULL: goto x86_l_3f8d;
	case 16274ULL: goto x86_l_3f92;
	case 16276ULL: goto x86_l_3f94;
	case 16281ULL: goto x86_l_3f99;
	case 16286ULL: goto x86_l_3f9e;
	case 16292ULL: goto x86_l_3fa4;
	case 16296ULL: goto x86_l_3fa8;
	case 16301ULL: goto x86_l_3fad;
	case 16306ULL: goto x86_l_3fb2;
	case 16311ULL: goto x86_l_3fb7;
	case 16316ULL: goto x86_l_3fbc;
	case 16319ULL: goto x86_l_3fbf;
	case 16321ULL: goto x86_l_3fc1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3de2:
	/* 0x3de2: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3de7:
	/* 0x3de7: jmp    3e48 <generic_rawtp_process_event+0x3e48> */
	goto x86_l_3e48;
x86_l_3de9:
	/* 0x3de9: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ded:
	/* 0x3ded: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3df2:
	/* 0x3df2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3df7:
	/* 0x3df7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3dfc:
	/* 0x3dfc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e01:
	/* 0x3e01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e03:
	/* 0x3e03: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3e08:
	/* 0x3e08: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_3e0d:
	/* 0x3e0d: je     974 <generic_rawtp_process_event+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2420ULL;
	}
x86_l_3e13:
	/* 0x3e13: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3e17:
	/* 0x3e17: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3e1c:
	/* 0x3e1c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e21:
	/* 0x3e21: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3e26:
	/* 0x3e26: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e2b:
	/* 0x3e2b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3e2e:
	/* 0x3e2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e30:
	/* 0x3e30: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e35:
	/* 0x3e35: mov    QWORD PTR [rsp+0x50],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3e3a:
	/* 0x3e3a: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e3e:
	/* 0x3e3e: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3e43:
	/* 0x3e43: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3e48:
	/* 0x3e48: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_3e4d:
	/* 0x3e4d: jne    3e5a <generic_rawtp_process_event+0x3e5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3e5a;
	}
x86_l_3e4f:
	/* 0x3e4f: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_3e54:
	/* 0x3e54: je     974 <generic_rawtp_process_event+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2420ULL;
	}
x86_l_3e5a:
	/* 0x3e5a: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3e62:
	/* 0x3e62: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3e67:
	/* 0x3e67: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e6c:
	/* 0x3e6c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e71:
	/* 0x3e71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e73:
	/* 0x3e73: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_3e7b:
	/* 0x3e7b: je     3f7a <generic_rawtp_process_event+0x3f7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f7a;
	}
x86_l_3e81:
	/* 0x3e81: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3e86:
	/* 0x3e86: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e8b:
	/* 0x3e8b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3e90:
	/* 0x3e90: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e95:
	/* 0x3e95: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e9a:
	/* 0x3e9a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3e9d:
	/* 0x3e9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e9f:
	/* 0x3e9f: cmp    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ea4:
	/* 0x3ea4: je     3f7a <generic_rawtp_process_event+0x3f7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f7a;
	}
x86_l_3eaa:
	/* 0x3eaa: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3eb2:
	/* 0x3eb2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3eb7:
	/* 0x3eb7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ebc:
	/* 0x3ebc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ec1:
	/* 0x3ec1: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3ec4:
	/* 0x3ec4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ec6:
	/* 0x3ec6: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3eca:
	/* 0x3eca: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3ecf:
	/* 0x3ecf: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3ed4:
	/* 0x3ed4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ed9:
	/* 0x3ed9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3ede:
	/* 0x3ede: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3ee1:
	/* 0x3ee1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ee3:
	/* 0x3ee3: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3ee8:
	/* 0x3ee8: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3eed:
	/* 0x3eed: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_3ef1:
	/* 0x3ef1: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3ef4:
	/* 0x3ef4: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3ef9:
	/* 0x3ef9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3efb:
	/* 0x3efb: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_3efd:
	/* 0x3efd: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3f00:
	/* 0x3f00: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_3f03:
	/* 0x3f03: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_3f08:
	/* 0x3f08: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f0a:
	/* 0x3f0a: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3f0d:
	/* 0x3f0d: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_3f11:
	/* 0x3f11: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_3f13:
	/* 0x3f13: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_3f17:
	/* 0x3f17: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3f19:
	/* 0x3f19: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_3f1c:
	/* 0x3f1c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3f1e:
	/* 0x3f1e: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3f22:
	/* 0x3f22: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3f25:
	/* 0x3f25: jb     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2425ULL;
	}
x86_l_3f2b:
	/* 0x3f2b: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_3f31:
	/* 0x3f31: ja     979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2425ULL;
	}
x86_l_3f37:
	/* 0x3f37: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3f3a:
	/* 0x3f3a: jbe    3f41 <generic_rawtp_process_event+0x3f41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3f41;
	}
x86_l_3f3c:
	/* 0x3f3c: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_3f41:
	/* 0x3f41: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f43:
	/* 0x3f43: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3f46:
	/* 0x3f46: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_3f4a:
	/* 0x3f4a: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3f4d:
	/* 0x3f4d: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3f50:
	/* 0x3f50: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3f53:
	/* 0x3f53: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3f58:
	/* 0x3f58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f5a:
	/* 0x3f5a: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3f5f:
	/* 0x3f5f: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3f62:
	/* 0x3f62: jbe    979 <generic_rawtp_process_event+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2425ULL;
	}
x86_l_3f68:
	/* 0x3f68: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3f70:
	/* 0x3f70: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3f75:
	/* 0x3f75: jmp    979 <generic_rawtp_process_event+0x979> */
	return 2425ULL;
x86_l_3f7a:
	/* 0x3f7a: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f7e:
	/* 0x3f7e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f83:
	/* 0x3f83: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3f88:
	/* 0x3f88: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3f8d:
	/* 0x3f8d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f92:
	/* 0x3f92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f94:
	/* 0x3f94: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3f99:
	/* 0x3f99: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_3f9e:
	/* 0x3f9e: je     974 <generic_rawtp_process_event+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2420ULL;
	}
x86_l_3fa4:
	/* 0x3fa4: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3fa8:
	/* 0x3fa8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3fad:
	/* 0x3fad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3fb2:
	/* 0x3fb2: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3fb7:
	/* 0x3fb7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3fbc:
	/* 0x3fbc: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3fbf:
	/* 0x3fbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fc1:
	/* 0x3fc1: jmp    979 <generic_rawtp_process_event+0x979> */
	return 2425ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_rawtp_generic_rawtp_process_event_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 14276U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1872ULL)
			__x86_pc = tetragon_bpf_generic_rawtp_generic_rawtp_process_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1877ULL && __x86_pc <= 3636ULL)
			__x86_pc = tetragon_bpf_generic_rawtp_generic_rawtp_process_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3641ULL && __x86_pc <= 5395ULL)
			__x86_pc = tetragon_bpf_generic_rawtp_generic_rawtp_process_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5400ULL && __x86_pc <= 7181ULL)
			__x86_pc = tetragon_bpf_generic_rawtp_generic_rawtp_process_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7185ULL && __x86_pc <= 8951ULL)
			__x86_pc = tetragon_bpf_generic_rawtp_generic_rawtp_process_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8953ULL && __x86_pc <= 10739ULL)
			__x86_pc = tetragon_bpf_generic_rawtp_generic_rawtp_process_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10745ULL && __x86_pc <= 12535ULL)
			__x86_pc = tetragon_bpf_generic_rawtp_generic_rawtp_process_event_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12538ULL && __x86_pc <= 14145ULL)
			__x86_pc = tetragon_bpf_generic_rawtp_generic_rawtp_process_event_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14148ULL && __x86_pc <= 15837ULL)
			__x86_pc = tetragon_bpf_generic_rawtp_generic_rawtp_process_event_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 15842ULL && __x86_pc <= 16321ULL)
			__x86_pc = tetragon_bpf_generic_rawtp_generic_rawtp_process_event_x86_chunk_9(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

extern char CONFIG_ITER_NUM;
extern char config_map;
extern char heap_ro_zero;
extern char sleepable_preload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_0(
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
	case 112ULL: goto x86_l_70;
	case 116ULL: goto x86_l_74;
	case 121ULL: goto x86_l_79;
	case 125ULL: goto x86_l_7d;
	case 130ULL: goto x86_l_82;
	case 134ULL: goto x86_l_86;
	case 139ULL: goto x86_l_8b;
	case 143ULL: goto x86_l_8f;
	case 151ULL: goto x86_l_97;
	case 155ULL: goto x86_l_9b;
	case 160ULL: goto x86_l_a0;
	case 164ULL: goto x86_l_a4;
	case 172ULL: goto x86_l_ac;
	case 176ULL: goto x86_l_b0;
	case 181ULL: goto x86_l_b5;
	case 185ULL: goto x86_l_b9;
	case 193ULL: goto x86_l_c1;
	case 197ULL: goto x86_l_c5;
	case 202ULL: goto x86_l_ca;
	case 206ULL: goto x86_l_ce;
	case 214ULL: goto x86_l_d6;
	case 218ULL: goto x86_l_da;
	case 223ULL: goto x86_l_df;
	case 226ULL: goto x86_l_e2;
	case 230ULL: goto x86_l_e6;
	case 235ULL: goto x86_l_eb;
	case 239ULL: goto x86_l_ef;
	case 244ULL: goto x86_l_f4;
	case 250ULL: goto x86_l_fa;
	case 258ULL: goto x86_l_102;
	case 261ULL: goto x86_l_105;
	case 268ULL: goto x86_l_10c;
	case 271ULL: goto x86_l_10f;
	case 273ULL: goto x86_l_111;
	case 275ULL: goto x86_l_113;
	case 280ULL: goto x86_l_118;
	case 283ULL: goto x86_l_11b;
	case 287ULL: goto x86_l_11f;
	case 291ULL: goto x86_l_123;
	case 297ULL: goto x86_l_129;
	case 302ULL: goto x86_l_12e;
	case 307ULL: goto x86_l_133;
	case 309ULL: goto x86_l_135;
	case 311ULL: goto x86_l_137;
	case 313ULL: goto x86_l_139;
	case 318ULL: goto x86_l_13e;
	case 321ULL: goto x86_l_141;
	case 327ULL: goto x86_l_147;
	case 330ULL: goto x86_l_14a;
	case 336ULL: goto x86_l_150;
	case 339ULL: goto x86_l_153;
	case 345ULL: goto x86_l_159;
	case 348ULL: goto x86_l_15c;
	case 354ULL: goto x86_l_162;
	case 359ULL: goto x86_l_167;
	case 364ULL: goto x86_l_16c;
	case 373ULL: goto x86_l_175;
	case 382ULL: goto x86_l_17e;
	case 388ULL: goto x86_l_184;
	case 391ULL: goto x86_l_187;
	case 393ULL: goto x86_l_189;
	case 396ULL: goto x86_l_18c;
	case 402ULL: goto x86_l_192;
	case 405ULL: goto x86_l_195;
	case 411ULL: goto x86_l_19b;
	case 416ULL: goto x86_l_1a0;
	case 419ULL: goto x86_l_1a3;
	case 425ULL: goto x86_l_1a9;
	case 430ULL: goto x86_l_1ae;
	case 433ULL: goto x86_l_1b1;
	case 439ULL: goto x86_l_1b7;
	case 444ULL: goto x86_l_1bc;
	case 447ULL: goto x86_l_1bf;
	case 453ULL: goto x86_l_1c5;
	case 458ULL: goto x86_l_1ca;
	case 463ULL: goto x86_l_1cf;
	case 466ULL: goto x86_l_1d2;
	case 468ULL: goto x86_l_1d4;
	case 471ULL: goto x86_l_1d7;
	case 477ULL: goto x86_l_1dd;
	case 482ULL: goto x86_l_1e2;
	case 484ULL: goto x86_l_1e4;
	case 490ULL: goto x86_l_1ea;
	case 498ULL: goto x86_l_1f2;
	case 503ULL: goto x86_l_1f7;
	case 506ULL: goto x86_l_1fa;
	case 512ULL: goto x86_l_200;
	case 517ULL: goto x86_l_205;
	case 519ULL: goto x86_l_207;
	case 525ULL: goto x86_l_20d;
	case 528ULL: goto x86_l_210;
	case 534ULL: goto x86_l_216;
	case 539ULL: goto x86_l_21b;
	case 541ULL: goto x86_l_21d;
	case 544ULL: goto x86_l_220;
	case 550ULL: goto x86_l_226;
	case 558ULL: goto x86_l_22e;
	case 561ULL: goto x86_l_231;
	case 567ULL: goto x86_l_237;
	case 572ULL: goto x86_l_23c;
	case 577ULL: goto x86_l_241;
	case 580ULL: goto x86_l_244;
	case 586ULL: goto x86_l_24a;
	case 591ULL: goto x86_l_24f;
	case 594ULL: goto x86_l_252;
	case 600ULL: goto x86_l_258;
	case 608ULL: goto x86_l_260;
	case 611ULL: goto x86_l_263;
	case 617ULL: goto x86_l_269;
	case 622ULL: goto x86_l_26e;
	case 627ULL: goto x86_l_273;
	case 630ULL: goto x86_l_276;
	case 636ULL: goto x86_l_27c;
	case 641ULL: goto x86_l_281;
	case 646ULL: goto x86_l_286;
	case 648ULL: goto x86_l_288;
	case 653ULL: goto x86_l_28d;
	case 655ULL: goto x86_l_28f;
	case 660ULL: goto x86_l_294;
	case 663ULL: goto x86_l_297;
	case 667ULL: goto x86_l_29b;
	case 670ULL: goto x86_l_29e;
	case 673ULL: goto x86_l_2a1;
	case 678ULL: goto x86_l_2a6;
	case 684ULL: goto x86_l_2ac;
	case 691ULL: goto x86_l_2b3;
	case 694ULL: goto x86_l_2b6;
	case 697ULL: goto x86_l_2b9;
	case 700ULL: goto x86_l_2bc;
	case 704ULL: goto x86_l_2c0;
	case 708ULL: goto x86_l_2c4;
	case 710ULL: goto x86_l_2c6;
	case 716ULL: goto x86_l_2cc;
	case 719ULL: goto x86_l_2cf;
	case 721ULL: goto x86_l_2d1;
	case 726ULL: goto x86_l_2d6;
	case 731ULL: goto x86_l_2db;
	case 734ULL: goto x86_l_2de;
	case 738ULL: goto x86_l_2e2;
	case 743ULL: goto x86_l_2e7;
	case 745ULL: goto x86_l_2e9;
	case 747ULL: goto x86_l_2eb;
	case 753ULL: goto x86_l_2f1;
	case 758ULL: goto x86_l_2f6;
	case 764ULL: goto x86_l_2fc;
	case 767ULL: goto x86_l_2ff;
	case 771ULL: goto x86_l_303;
	case 775ULL: goto x86_l_307;
	case 780ULL: goto x86_l_30c;
	case 782ULL: goto x86_l_30e;
	case 787ULL: goto x86_l_313;
	case 792ULL: goto x86_l_318;
	case 795ULL: goto x86_l_31b;
	case 799ULL: goto x86_l_31f;
	case 804ULL: goto x86_l_324;
	case 806ULL: goto x86_l_326;
	case 808ULL: goto x86_l_328;
	case 814ULL: goto x86_l_32e;
	case 819ULL: goto x86_l_333;
	case 825ULL: goto x86_l_339;
	case 828ULL: goto x86_l_33c;
	case 832ULL: goto x86_l_340;
	case 836ULL: goto x86_l_344;
	case 841ULL: goto x86_l_349;
	case 843ULL: goto x86_l_34b;
	case 848ULL: goto x86_l_350;
	case 853ULL: goto x86_l_355;
	case 856ULL: goto x86_l_358;
	case 860ULL: goto x86_l_35c;
	case 865ULL: goto x86_l_361;
	case 867ULL: goto x86_l_363;
	case 869ULL: goto x86_l_365;
	case 875ULL: goto x86_l_36b;
	case 880ULL: goto x86_l_370;
	case 886ULL: goto x86_l_376;
	case 889ULL: goto x86_l_379;
	case 893ULL: goto x86_l_37d;
	case 897ULL: goto x86_l_381;
	case 902ULL: goto x86_l_386;
	case 904ULL: goto x86_l_388;
	case 909ULL: goto x86_l_38d;
	case 914ULL: goto x86_l_392;
	case 917ULL: goto x86_l_395;
	case 921ULL: goto x86_l_399;
	case 926ULL: goto x86_l_39e;
	case 928ULL: goto x86_l_3a0;
	case 930ULL: goto x86_l_3a2;
	case 936ULL: goto x86_l_3a8;
	case 941ULL: goto x86_l_3ad;
	case 947ULL: goto x86_l_3b3;
	case 950ULL: goto x86_l_3b6;
	case 954ULL: goto x86_l_3ba;
	case 958ULL: goto x86_l_3be;
	case 963ULL: goto x86_l_3c3;
	case 965ULL: goto x86_l_3c5;
	case 970ULL: goto x86_l_3ca;
	case 975ULL: goto x86_l_3cf;
	case 978ULL: goto x86_l_3d2;
	case 982ULL: goto x86_l_3d6;
	case 987ULL: goto x86_l_3db;
	case 989ULL: goto x86_l_3dd;
	case 991ULL: goto x86_l_3df;
	case 997ULL: goto x86_l_3e5;
	case 1002ULL: goto x86_l_3ea;
	case 1008ULL: goto x86_l_3f0;
	case 1011ULL: goto x86_l_3f3;
	case 1015ULL: goto x86_l_3f7;
	case 1019ULL: goto x86_l_3fb;
	case 1024ULL: goto x86_l_400;
	case 1026ULL: goto x86_l_402;
	case 1031ULL: goto x86_l_407;
	case 1036ULL: goto x86_l_40c;
	case 1039ULL: goto x86_l_40f;
	case 1043ULL: goto x86_l_413;
	case 1048ULL: goto x86_l_418;
	case 1050ULL: goto x86_l_41a;
	case 1052ULL: goto x86_l_41c;
	case 1058ULL: goto x86_l_422;
	case 1063ULL: goto x86_l_427;
	case 1069ULL: goto x86_l_42d;
	case 1072ULL: goto x86_l_430;
	case 1076ULL: goto x86_l_434;
	case 1080ULL: goto x86_l_438;
	case 1085ULL: goto x86_l_43d;
	case 1087ULL: goto x86_l_43f;
	case 1092ULL: goto x86_l_444;
	case 1097ULL: goto x86_l_449;
	case 1100ULL: goto x86_l_44c;
	case 1104ULL: goto x86_l_450;
	case 1109ULL: goto x86_l_455;
	case 1111ULL: goto x86_l_457;
	case 1113ULL: goto x86_l_459;
	case 1119ULL: goto x86_l_45f;
	case 1124ULL: goto x86_l_464;
	case 1130ULL: goto x86_l_46a;
	case 1133ULL: goto x86_l_46d;
	case 1137ULL: goto x86_l_471;
	case 1141ULL: goto x86_l_475;
	case 1146ULL: goto x86_l_47a;
	case 1148ULL: goto x86_l_47c;
	case 1153ULL: goto x86_l_481;
	case 1158ULL: goto x86_l_486;
	case 1161ULL: goto x86_l_489;
	case 1165ULL: goto x86_l_48d;
	case 1170ULL: goto x86_l_492;
	case 1172ULL: goto x86_l_494;
	case 1174ULL: goto x86_l_496;
	case 1180ULL: goto x86_l_49c;
	case 1185ULL: goto x86_l_4a1;
	case 1191ULL: goto x86_l_4a7;
	case 1194ULL: goto x86_l_4aa;
	case 1198ULL: goto x86_l_4ae;
	case 1202ULL: goto x86_l_4b2;
	case 1207ULL: goto x86_l_4b7;
	case 1209ULL: goto x86_l_4b9;
	case 1214ULL: goto x86_l_4be;
	case 1219ULL: goto x86_l_4c3;
	case 1222ULL: goto x86_l_4c6;
	case 1226ULL: goto x86_l_4ca;
	case 1231ULL: goto x86_l_4cf;
	case 1233ULL: goto x86_l_4d1;
	case 1235ULL: goto x86_l_4d3;
	case 1241ULL: goto x86_l_4d9;
	case 1245ULL: goto x86_l_4dd;
	case 1251ULL: goto x86_l_4e3;
	case 1254ULL: goto x86_l_4e6;
	case 1258ULL: goto x86_l_4ea;
	case 1262ULL: goto x86_l_4ee;
	case 1267ULL: goto x86_l_4f3;
	case 1273ULL: goto x86_l_4f9;
	case 1278ULL: goto x86_l_4fe;
	case 1283ULL: goto x86_l_503;
	case 1286ULL: goto x86_l_506;
	case 1291ULL: goto x86_l_50b;
	case 1294ULL: goto x86_l_50e;
	case 1296ULL: goto x86_l_510;
	case 1301ULL: goto x86_l_515;
	case 1306ULL: goto x86_l_51a;
	case 1309ULL: goto x86_l_51d;
	case 1313ULL: goto x86_l_521;
	case 1318ULL: goto x86_l_526;
	case 1320ULL: goto x86_l_528;
	case 1322ULL: goto x86_l_52a;
	case 1328ULL: goto x86_l_530;
	case 1333ULL: goto x86_l_535;
	case 1339ULL: goto x86_l_53b;
	case 1342ULL: goto x86_l_53e;
	case 1346ULL: goto x86_l_542;
	case 1350ULL: goto x86_l_546;
	case 1355ULL: goto x86_l_54b;
	case 1357ULL: goto x86_l_54d;
	case 1362ULL: goto x86_l_552;
	case 1367ULL: goto x86_l_557;
	case 1370ULL: goto x86_l_55a;
	case 1374ULL: goto x86_l_55e;
	case 1379ULL: goto x86_l_563;
	case 1381ULL: goto x86_l_565;
	case 1383ULL: goto x86_l_567;
	case 1389ULL: goto x86_l_56d;
	case 1394ULL: goto x86_l_572;
	case 1400ULL: goto x86_l_578;
	case 1403ULL: goto x86_l_57b;
	case 1407ULL: goto x86_l_57f;
	case 1411ULL: goto x86_l_583;
	case 1416ULL: goto x86_l_588;
	case 1418ULL: goto x86_l_58a;
	case 1423ULL: goto x86_l_58f;
	case 1428ULL: goto x86_l_594;
	case 1431ULL: goto x86_l_597;
	case 1435ULL: goto x86_l_59b;
	case 1440ULL: goto x86_l_5a0;
	case 1442ULL: goto x86_l_5a2;
	case 1444ULL: goto x86_l_5a4;
	case 1450ULL: goto x86_l_5aa;
	case 1455ULL: goto x86_l_5af;
	case 1461ULL: goto x86_l_5b5;
	case 1464ULL: goto x86_l_5b8;
	case 1468ULL: goto x86_l_5bc;
	case 1472ULL: goto x86_l_5c0;
	case 1477ULL: goto x86_l_5c5;
	case 1479ULL: goto x86_l_5c7;
	case 1484ULL: goto x86_l_5cc;
	case 1489ULL: goto x86_l_5d1;
	case 1492ULL: goto x86_l_5d4;
	case 1496ULL: goto x86_l_5d8;
	case 1501ULL: goto x86_l_5dd;
	case 1503ULL: goto x86_l_5df;
	case 1505ULL: goto x86_l_5e1;
	case 1511ULL: goto x86_l_5e7;
	case 1516ULL: goto x86_l_5ec;
	case 1522ULL: goto x86_l_5f2;
	case 1525ULL: goto x86_l_5f5;
	case 1529ULL: goto x86_l_5f9;
	case 1533ULL: goto x86_l_5fd;
	case 1538ULL: goto x86_l_602;
	case 1540ULL: goto x86_l_604;
	case 1545ULL: goto x86_l_609;
	case 1550ULL: goto x86_l_60e;
	case 1553ULL: goto x86_l_611;
	case 1557ULL: goto x86_l_615;
	case 1562ULL: goto x86_l_61a;
	case 1564ULL: goto x86_l_61c;
	case 1566ULL: goto x86_l_61e;
	case 1572ULL: goto x86_l_624;
	case 1577ULL: goto x86_l_629;
	case 1583ULL: goto x86_l_62f;
	case 1586ULL: goto x86_l_632;
	case 1590ULL: goto x86_l_636;
	case 1594ULL: goto x86_l_63a;
	case 1599ULL: goto x86_l_63f;
	case 1601ULL: goto x86_l_641;
	case 1606ULL: goto x86_l_646;
	case 1611ULL: goto x86_l_64b;
	case 1614ULL: goto x86_l_64e;
	case 1618ULL: goto x86_l_652;
	case 1623ULL: goto x86_l_657;
	case 1625ULL: goto x86_l_659;
	case 1627ULL: goto x86_l_65b;
	case 1633ULL: goto x86_l_661;
	case 1638ULL: goto x86_l_666;
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
	/* 0xa: sub    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 184ULL);
x86_l_11:
	/* 0x11: mov    QWORD PTR [rsp+0x48],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_16:
	/* 0x16: mov    DWORD PTR [rsp+0xac],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_21:
	/* 0x21: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_28:
	/* 0x28: lea    rsi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
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
	/* 0x3a: je     4c77 <generic_sleepable_preload+0x4c77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19575ULL;
	}
x86_l_40:
	/* 0x40: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_43:
	/* 0x43: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_4a:
	/* 0x4a: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4f:
	/* 0x4f: lea    rdx,[rcx+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_56:
	/* 0x56: mov    QWORD PTR [rsp+0x50],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5b:
	/* 0x5b: lea    rdx,[rcx+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_62:
	/* 0x62: mov    QWORD PTR [rsp+0x70],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_67:
	/* 0x67: lea    rdx,[rcx+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6b:
	/* 0x6b: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_70:
	/* 0x70: lea    rdx,[rcx+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_74:
	/* 0x74: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_79:
	/* 0x79: lea    rdx,[rcx+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7d:
	/* 0x7d: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_82:
	/* 0x82: lea    rdx,[rcx+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_86:
	/* 0x86: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8b:
	/* 0x8b: lea    rdx,[rcx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8f:
	/* 0x8f: mov    QWORD PTR [rsp+0x98],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_97:
	/* 0x97: lea    rdx,[rcx+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9b:
	/* 0x9b: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a0:
	/* 0xa0: lea    rdx,[rcx+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a4:
	/* 0xa4: mov    QWORD PTR [rsp+0x90],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_ac:
	/* 0xac: lea    rdx,[rcx+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b0:
	/* 0xb0: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b5:
	/* 0xb5: lea    rdx,[rcx+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b9:
	/* 0xb9: mov    QWORD PTR [rsp+0x88],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c1:
	/* 0xc1: lea    rdx,[rcx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c5:
	/* 0xc5: mov    QWORD PTR [rsp+0x60],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ca:
	/* 0xca: lea    rdx,[rcx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ce:
	/* 0xce: mov    QWORD PTR [rsp+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d6:
	/* 0xd6: lea    rdx,[rcx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_da:
	/* 0xda: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_df:
	/* 0xdf: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e2:
	/* 0xe2: lea    rax,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e6:
	/* 0xe6: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_eb:
	/* 0xeb: lea    r14,[rcx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ef:
	/* 0xef: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f4:
	/* 0xf4: je     efb <generic_sleepable_preload+0xefb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3835ULL;
	}
x86_l_fa:
	/* 0xfa: mov    QWORD PTR [rsp+0xb0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_102:
	/* 0x102: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_105:
	/* 0x105: add    rbx,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_10c:
	/* 0x10c: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10f:
	/* 0x10f: jmp    129 <generic_sleepable_preload+0x129> */
	goto x86_l_129;
x86_l_111:
	/* 0x111: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_113:
	/* 0x113: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_118:
	/* 0x118: inc    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_11b:
	/* 0x11b: add    rbx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_11f:
	/* 0x11f: cmp    r14,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 5ULL);
x86_l_123:
	/* 0x123: je     4c77 <generic_sleepable_preload+0x4c77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19575ULL;
	}
x86_l_129:
	/* 0x129: mov    eax,DWORD PTR [r12+r14*4+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 24ULL);
x86_l_12e:
	/* 0x12e: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_133:
	/* 0x133: je     118 <generic_sleepable_preload+0x118> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_118;
	}
x86_l_135:
	/* 0x135: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_137:
	/* 0x137: js     16c <generic_sleepable_preload+0x16c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_16c;
	}
x86_l_139:
	/* 0x139: mov    eax,DWORD PTR [r12+r14*4+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 64ULL);
x86_l_13e:
	/* 0x13e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_141:
	/* 0x141: jle    205 <generic_sleepable_preload+0x205> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_205;
	}
x86_l_147:
	/* 0x147: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_14a:
	/* 0x14a: je     281 <generic_sleepable_preload+0x281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_281;
	}
x86_l_150:
	/* 0x150: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_153:
	/* 0x153: je     288 <generic_sleepable_preload+0x288> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_288;
	}
x86_l_159:
	/* 0x159: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15c:
	/* 0x15c: jne    29b <generic_sleepable_preload+0x29b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29b;
	}
x86_l_162:
	/* 0x162: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_167:
	/* 0x167: jmp    294 <generic_sleepable_preload+0x294> */
	goto x86_l_294;
x86_l_16c:
	/* 0x16c: movzx  eax,BYTE PTR [r12+r14*4+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_8), 706ULL);
x86_l_175:
	/* 0x175: movzx  ecx,WORD PTR [r12+r14*4+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_16), 704ULL);
x86_l_17e:
	/* 0x17e: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_184:
	/* 0x184: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_187:
	/* 0x187: jle    1cf <generic_sleepable_preload+0x1cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1cf;
	}
x86_l_189:
	/* 0x189: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_18c:
	/* 0x18c: jle    21d <generic_sleepable_preload+0x21d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_21d;
	}
x86_l_192:
	/* 0x192: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_195:
	/* 0x195: jle    7c5 <generic_sleepable_preload+0x7c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 1989ULL;
	}
x86_l_19b:
	/* 0x19b: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a0:
	/* 0x1a0: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_1a3:
	/* 0x1a3: je     7de <generic_sleepable_preload+0x7de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2014ULL;
	}
x86_l_1a9:
	/* 0x1a9: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1ae:
	/* 0x1ae: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1b1:
	/* 0x1b1: je     7de <generic_sleepable_preload+0x7de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2014ULL;
	}
x86_l_1b7:
	/* 0x1b7: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_1bc:
	/* 0x1bc: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_1bf:
	/* 0x1bf: jne    7f1 <generic_sleepable_preload+0x7f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2033ULL;
	}
x86_l_1c5:
	/* 0x1c5: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ca:
	/* 0x1ca: jmp    7de <generic_sleepable_preload+0x7de> */
	return 2014ULL;
x86_l_1cf:
	/* 0x1cf: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1d2:
	/* 0x1d2: jg     24f <generic_sleepable_preload+0x24f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_24f;
	}
x86_l_1d4:
	/* 0x1d4: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1d7:
	/* 0x1d7: jg     78c <generic_sleepable_preload+0x78c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1932ULL;
	}
x86_l_1dd:
	/* 0x1dd: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1e2:
	/* 0x1e2: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1e4:
	/* 0x1e4: je     7de <generic_sleepable_preload+0x7de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2014ULL;
	}
x86_l_1ea:
	/* 0x1ea: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1f2:
	/* 0x1f2: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_1f7:
	/* 0x1f7: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1fa:
	/* 0x1fa: je     7de <generic_sleepable_preload+0x7de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2014ULL;
	}
x86_l_200:
	/* 0x200: jmp    7f1 <generic_sleepable_preload+0x7f1> */
	return 2033ULL;
x86_l_205:
	/* 0x205: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_207:
	/* 0x207: je     28f <generic_sleepable_preload+0x28f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28f;
	}
x86_l_20d:
	/* 0x20d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_210:
	/* 0x210: jne    29b <generic_sleepable_preload+0x29b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29b;
	}
x86_l_216:
	/* 0x216: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21b:
	/* 0x21b: jmp    294 <generic_sleepable_preload+0x294> */
	goto x86_l_294;
x86_l_21d:
	/* 0x21d: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_220:
	/* 0x220: jg     76e <generic_sleepable_preload+0x76e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1902ULL;
	}
x86_l_226:
	/* 0x226: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_22e:
	/* 0x22e: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_231:
	/* 0x231: je     7de <generic_sleepable_preload+0x7de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2014ULL;
	}
x86_l_237:
	/* 0x237: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_23c:
	/* 0x23c: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_241:
	/* 0x241: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_244:
	/* 0x244: je     7de <generic_sleepable_preload+0x7de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2014ULL;
	}
x86_l_24a:
	/* 0x24a: jmp    7f1 <generic_sleepable_preload+0x7f1> */
	return 2033ULL;
x86_l_24f:
	/* 0x24f: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_252:
	/* 0x252: jg     7a7 <generic_sleepable_preload+0x7a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1959ULL;
	}
x86_l_258:
	/* 0x258: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_260:
	/* 0x260: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_263:
	/* 0x263: je     7de <generic_sleepable_preload+0x7de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2014ULL;
	}
x86_l_269:
	/* 0x269: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_26e:
	/* 0x26e: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_273:
	/* 0x273: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_276:
	/* 0x276: je     7de <generic_sleepable_preload+0x7de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2014ULL;
	}
x86_l_27c:
	/* 0x27c: jmp    7f1 <generic_sleepable_preload+0x7f1> */
	return 2033ULL;
x86_l_281:
	/* 0x281: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_286:
	/* 0x286: jmp    294 <generic_sleepable_preload+0x294> */
	goto x86_l_294;
x86_l_288:
	/* 0x288: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28d:
	/* 0x28d: jmp    294 <generic_sleepable_preload+0x294> */
	goto x86_l_294;
x86_l_28f:
	/* 0x28f: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_294:
	/* 0x294: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_297:
	/* 0x297: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29b:
	/* 0x29b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29e:
	/* 0x29e: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_2a1:
	/* 0x2a1: cmp    WORD PTR [rbx-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743764471906304ULL);
x86_l_2a6:
	/* 0x2a6: je     d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3372ULL;
	}
x86_l_2ac:
	/* 0x2ac: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_2b3:
	/* 0x2b3: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2b6:
	/* 0x2b6: mov    eax,DWORD PTR [rbx-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551538ULL);
x86_l_2b9:
	/* 0x2b9: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2bc:
	/* 0x2bc: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c0:
	/* 0x2c0: movzx  eax,WORD PTR [rbx-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_2c4:
	/* 0x2c4: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_2c6:
	/* 0x2c6: je     50b <generic_sleepable_preload+0x50b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50b;
	}
x86_l_2cc:
	/* 0x2cc: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2cf:
	/* 0x2cf: je     2f1 <generic_sleepable_preload+0x2f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f1;
	}
x86_l_2d1:
	/* 0x2d1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d6:
	/* 0x2d6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2db:
	/* 0x2db: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2de:
	/* 0x2de: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e2:
	/* 0x2e2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e7:
	/* 0x2e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e9:
	/* 0x2e9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2eb:
	/* 0x2eb: js     763 <generic_sleepable_preload+0x763> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1891ULL;
	}
x86_l_2f1:
	/* 0x2f1: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_2f6:
	/* 0x2f6: je     d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3372ULL;
	}
x86_l_2fc:
	/* 0x2fc: mov    ecx,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_2ff:
	/* 0x2ff: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_303:
	/* 0x303: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_307:
	/* 0x307: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_30c:
	/* 0x30c: je     32e <generic_sleepable_preload+0x32e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32e;
	}
x86_l_30e:
	/* 0x30e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_313:
	/* 0x313: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_318:
	/* 0x318: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_31b:
	/* 0x31b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31f:
	/* 0x31f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_324:
	/* 0x324: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_326:
	/* 0x326: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_328:
	/* 0x328: js     cca <generic_sleepable_preload+0xcca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3274ULL;
	}
x86_l_32e:
	/* 0x32e: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_333:
	/* 0x333: je     d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3372ULL;
	}
x86_l_339:
	/* 0x339: mov    ecx,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_33c:
	/* 0x33c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_340:
	/* 0x340: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_344:
	/* 0x344: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_349:
	/* 0x349: je     36b <generic_sleepable_preload+0x36b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36b;
	}
x86_l_34b:
	/* 0x34b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_350:
	/* 0x350: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_355:
	/* 0x355: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_358:
	/* 0x358: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35c:
	/* 0x35c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_361:
	/* 0x361: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_363:
	/* 0x363: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_365:
	/* 0x365: js     cdc <generic_sleepable_preload+0xcdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3292ULL;
	}
x86_l_36b:
	/* 0x36b: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_370:
	/* 0x370: je     d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3372ULL;
	}
x86_l_376:
	/* 0x376: mov    ecx,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_379:
	/* 0x379: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_37d:
	/* 0x37d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_381:
	/* 0x381: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_386:
	/* 0x386: je     3a8 <generic_sleepable_preload+0x3a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a8;
	}
x86_l_388:
	/* 0x388: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_38d:
	/* 0x38d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_392:
	/* 0x392: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_395:
	/* 0x395: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_399:
	/* 0x399: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39e:
	/* 0x39e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a0:
	/* 0x3a0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a2:
	/* 0x3a2: js     cee <generic_sleepable_preload+0xcee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3310ULL;
	}
x86_l_3a8:
	/* 0x3a8: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_3ad:
	/* 0x3ad: je     d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3372ULL;
	}
x86_l_3b3:
	/* 0x3b3: mov    ecx,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_3b6:
	/* 0x3b6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3ba:
	/* 0x3ba: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3be:
	/* 0x3be: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_3c3:
	/* 0x3c3: je     3e5 <generic_sleepable_preload+0x3e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e5;
	}
x86_l_3c5:
	/* 0x3c5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3ca:
	/* 0x3ca: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3cf:
	/* 0x3cf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3d2:
	/* 0x3d2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d6:
	/* 0x3d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3db:
	/* 0x3db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dd:
	/* 0x3dd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3df:
	/* 0x3df: js     d00 <generic_sleepable_preload+0xd00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3328ULL;
	}
x86_l_3e5:
	/* 0x3e5: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_3ea:
	/* 0x3ea: je     d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3372ULL;
	}
x86_l_3f0:
	/* 0x3f0: mov    ecx,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_3f3:
	/* 0x3f3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3f7:
	/* 0x3f7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fb:
	/* 0x3fb: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_400:
	/* 0x400: je     422 <generic_sleepable_preload+0x422> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_422;
	}
x86_l_402:
	/* 0x402: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_407:
	/* 0x407: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_40c:
	/* 0x40c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_40f:
	/* 0x40f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_413:
	/* 0x413: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_418:
	/* 0x418: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41a:
	/* 0x41a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_41c:
	/* 0x41c: js     d12 <generic_sleepable_preload+0xd12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3346ULL;
	}
x86_l_422:
	/* 0x422: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_427:
	/* 0x427: je     d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3372ULL;
	}
x86_l_42d:
	/* 0x42d: mov    ecx,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_430:
	/* 0x430: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_434:
	/* 0x434: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_438:
	/* 0x438: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_43d:
	/* 0x43d: je     45f <generic_sleepable_preload+0x45f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45f;
	}
x86_l_43f:
	/* 0x43f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_444:
	/* 0x444: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_449:
	/* 0x449: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_44c:
	/* 0x44c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_450:
	/* 0x450: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_455:
	/* 0x455: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_457:
	/* 0x457: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_459:
	/* 0x459: js     d24 <generic_sleepable_preload+0xd24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3364ULL;
	}
x86_l_45f:
	/* 0x45f: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_464:
	/* 0x464: je     d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3372ULL;
	}
x86_l_46a:
	/* 0x46a: mov    ecx,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_46d:
	/* 0x46d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_471:
	/* 0x471: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_475:
	/* 0x475: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_47a:
	/* 0x47a: je     49c <generic_sleepable_preload+0x49c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49c;
	}
x86_l_47c:
	/* 0x47c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_481:
	/* 0x481: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_486:
	/* 0x486: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_489:
	/* 0x489: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48d:
	/* 0x48d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_492:
	/* 0x492: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_494:
	/* 0x494: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_496:
	/* 0x496: js     ec2 <generic_sleepable_preload+0xec2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3778ULL;
	}
x86_l_49c:
	/* 0x49c: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_4a1:
	/* 0x4a1: je     d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3372ULL;
	}
x86_l_4a7:
	/* 0x4a7: mov    ecx,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_4aa:
	/* 0x4aa: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4ae:
	/* 0x4ae: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b2:
	/* 0x4b2: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_4b7:
	/* 0x4b7: je     4d9 <generic_sleepable_preload+0x4d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d9;
	}
x86_l_4b9:
	/* 0x4b9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4be:
	/* 0x4be: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4c3:
	/* 0x4c3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4c6:
	/* 0x4c6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ca:
	/* 0x4ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cf:
	/* 0x4cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d1:
	/* 0x4d1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d3:
	/* 0x4d3: js     ee6 <generic_sleepable_preload+0xee6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3814ULL;
	}
x86_l_4d9:
	/* 0x4d9: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dd:
	/* 0x4dd: je     d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3372ULL;
	}
x86_l_4e3:
	/* 0x4e3: mov    ecx,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_4e6:
	/* 0x4e6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4ea:
	/* 0x4ea: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ee:
	/* 0x4ee: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_4f3:
	/* 0x4f3: je     d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3372ULL;
	}
x86_l_4f9:
	/* 0x4f9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4fe:
	/* 0x4fe: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_503:
	/* 0x503: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_506:
	/* 0x506: jmp    745 <generic_sleepable_preload+0x745> */
	return 1861ULL;
x86_l_50b:
	/* 0x50b: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_50e:
	/* 0x50e: je     530 <generic_sleepable_preload+0x530> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_530;
	}
x86_l_510:
	/* 0x510: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_515:
	/* 0x515: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_51a:
	/* 0x51a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_51d:
	/* 0x51d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_521:
	/* 0x521: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_526:
	/* 0x526: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_528:
	/* 0x528: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52a:
	/* 0x52a: js     763 <generic_sleepable_preload+0x763> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1891ULL;
	}
x86_l_530:
	/* 0x530: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_535:
	/* 0x535: je     d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3372ULL;
	}
x86_l_53b:
	/* 0x53b: mov    ecx,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_53e:
	/* 0x53e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_542:
	/* 0x542: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_546:
	/* 0x546: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_54b:
	/* 0x54b: je     56d <generic_sleepable_preload+0x56d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56d;
	}
x86_l_54d:
	/* 0x54d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_552:
	/* 0x552: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_557:
	/* 0x557: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_55a:
	/* 0x55a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55e:
	/* 0x55e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_563:
	/* 0x563: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_565:
	/* 0x565: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_567:
	/* 0x567: js     cca <generic_sleepable_preload+0xcca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3274ULL;
	}
x86_l_56d:
	/* 0x56d: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_572:
	/* 0x572: je     d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3372ULL;
	}
x86_l_578:
	/* 0x578: mov    ecx,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_57b:
	/* 0x57b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_57f:
	/* 0x57f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_583:
	/* 0x583: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_588:
	/* 0x588: je     5aa <generic_sleepable_preload+0x5aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5aa;
	}
x86_l_58a:
	/* 0x58a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_58f:
	/* 0x58f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_594:
	/* 0x594: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_597:
	/* 0x597: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59b:
	/* 0x59b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a0:
	/* 0x5a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a2:
	/* 0x5a2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5a4:
	/* 0x5a4: js     cdc <generic_sleepable_preload+0xcdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3292ULL;
	}
x86_l_5aa:
	/* 0x5aa: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_5af:
	/* 0x5af: je     d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3372ULL;
	}
x86_l_5b5:
	/* 0x5b5: mov    ecx,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_5b8:
	/* 0x5b8: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5bc:
	/* 0x5bc: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c0:
	/* 0x5c0: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_5c5:
	/* 0x5c5: je     5e7 <generic_sleepable_preload+0x5e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e7;
	}
x86_l_5c7:
	/* 0x5c7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5cc:
	/* 0x5cc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5d1:
	/* 0x5d1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5d4:
	/* 0x5d4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d8:
	/* 0x5d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5dd:
	/* 0x5dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5df:
	/* 0x5df: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5e1:
	/* 0x5e1: js     cee <generic_sleepable_preload+0xcee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3310ULL;
	}
x86_l_5e7:
	/* 0x5e7: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_5ec:
	/* 0x5ec: je     d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3372ULL;
	}
x86_l_5f2:
	/* 0x5f2: mov    ecx,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_5f5:
	/* 0x5f5: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5f9:
	/* 0x5f9: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5fd:
	/* 0x5fd: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_602:
	/* 0x602: je     624 <generic_sleepable_preload+0x624> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_624;
	}
x86_l_604:
	/* 0x604: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_609:
	/* 0x609: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_60e:
	/* 0x60e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_611:
	/* 0x611: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_615:
	/* 0x615: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_61a:
	/* 0x61a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61c:
	/* 0x61c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_61e:
	/* 0x61e: js     d00 <generic_sleepable_preload+0xd00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3328ULL;
	}
x86_l_624:
	/* 0x624: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_629:
	/* 0x629: je     d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3372ULL;
	}
x86_l_62f:
	/* 0x62f: mov    ecx,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_632:
	/* 0x632: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_636:
	/* 0x636: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_63a:
	/* 0x63a: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_63f:
	/* 0x63f: je     661 <generic_sleepable_preload+0x661> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_661;
	}
x86_l_641:
	/* 0x641: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_646:
	/* 0x646: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_64b:
	/* 0x64b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_64e:
	/* 0x64e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_652:
	/* 0x652: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_657:
	/* 0x657: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_659:
	/* 0x659: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_65b:
	/* 0x65b: js     d12 <generic_sleepable_preload+0xd12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3346ULL;
	}
x86_l_661:
	/* 0x661: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_666:
	/* 0x666: je     d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3372ULL;
	}
	return 1644ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1644ULL: goto x86_l_66c;
	case 1647ULL: goto x86_l_66f;
	case 1651ULL: goto x86_l_673;
	case 1655ULL: goto x86_l_677;
	case 1660ULL: goto x86_l_67c;
	case 1662ULL: goto x86_l_67e;
	case 1667ULL: goto x86_l_683;
	case 1672ULL: goto x86_l_688;
	case 1675ULL: goto x86_l_68b;
	case 1679ULL: goto x86_l_68f;
	case 1684ULL: goto x86_l_694;
	case 1686ULL: goto x86_l_696;
	case 1688ULL: goto x86_l_698;
	case 1694ULL: goto x86_l_69e;
	case 1699ULL: goto x86_l_6a3;
	case 1705ULL: goto x86_l_6a9;
	case 1708ULL: goto x86_l_6ac;
	case 1712ULL: goto x86_l_6b0;
	case 1716ULL: goto x86_l_6b4;
	case 1721ULL: goto x86_l_6b9;
	case 1723ULL: goto x86_l_6bb;
	case 1728ULL: goto x86_l_6c0;
	case 1733ULL: goto x86_l_6c5;
	case 1736ULL: goto x86_l_6c8;
	case 1740ULL: goto x86_l_6cc;
	case 1745ULL: goto x86_l_6d1;
	case 1747ULL: goto x86_l_6d3;
	case 1749ULL: goto x86_l_6d5;
	case 1755ULL: goto x86_l_6db;
	case 1760ULL: goto x86_l_6e0;
	case 1766ULL: goto x86_l_6e6;
	case 1769ULL: goto x86_l_6e9;
	case 1773ULL: goto x86_l_6ed;
	case 1777ULL: goto x86_l_6f1;
	case 1782ULL: goto x86_l_6f6;
	case 1784ULL: goto x86_l_6f8;
	case 1789ULL: goto x86_l_6fd;
	case 1794ULL: goto x86_l_702;
	case 1797ULL: goto x86_l_705;
	case 1801ULL: goto x86_l_709;
	case 1806ULL: goto x86_l_70e;
	case 1808ULL: goto x86_l_710;
	case 1810ULL: goto x86_l_712;
	case 1816ULL: goto x86_l_718;
	case 1820ULL: goto x86_l_71c;
	case 1826ULL: goto x86_l_722;
	case 1829ULL: goto x86_l_725;
	case 1833ULL: goto x86_l_729;
	case 1837ULL: goto x86_l_72d;
	case 1842ULL: goto x86_l_732;
	case 1848ULL: goto x86_l_738;
	case 1853ULL: goto x86_l_73d;
	case 1858ULL: goto x86_l_742;
	case 1861ULL: goto x86_l_745;
	case 1865ULL: goto x86_l_749;
	case 1870ULL: goto x86_l_74e;
	case 1872ULL: goto x86_l_750;
	case 1874ULL: goto x86_l_752;
	case 1880ULL: goto x86_l_758;
	case 1886ULL: goto x86_l_75e;
	case 1891ULL: goto x86_l_763;
	case 1897ULL: goto x86_l_769;
	case 1902ULL: goto x86_l_76e;
	case 1910ULL: goto x86_l_776;
	case 1913ULL: goto x86_l_779;
	case 1915ULL: goto x86_l_77b;
	case 1920ULL: goto x86_l_780;
	case 1925ULL: goto x86_l_785;
	case 1928ULL: goto x86_l_788;
	case 1930ULL: goto x86_l_78a;
	case 1932ULL: goto x86_l_78c;
	case 1937ULL: goto x86_l_791;
	case 1940ULL: goto x86_l_794;
	case 1942ULL: goto x86_l_796;
	case 1947ULL: goto x86_l_79b;
	case 1952ULL: goto x86_l_7a0;
	case 1955ULL: goto x86_l_7a3;
	case 1957ULL: goto x86_l_7a5;
	case 1959ULL: goto x86_l_7a7;
	case 1967ULL: goto x86_l_7af;
	case 1970ULL: goto x86_l_7b2;
	case 1972ULL: goto x86_l_7b4;
	case 1977ULL: goto x86_l_7b9;
	case 1982ULL: goto x86_l_7be;
	case 1985ULL: goto x86_l_7c1;
	case 1987ULL: goto x86_l_7c3;
	case 1989ULL: goto x86_l_7c5;
	case 1994ULL: goto x86_l_7ca;
	case 1997ULL: goto x86_l_7cd;
	case 1999ULL: goto x86_l_7cf;
	case 2004ULL: goto x86_l_7d4;
	case 2009ULL: goto x86_l_7d9;
	case 2012ULL: goto x86_l_7dc;
	case 2014ULL: goto x86_l_7de;
	case 2017ULL: goto x86_l_7e1;
	case 2019ULL: goto x86_l_7e3;
	case 2021ULL: goto x86_l_7e5;
	case 2026ULL: goto x86_l_7ea;
	case 2028ULL: goto x86_l_7ec;
	case 2033ULL: goto x86_l_7f1;
	case 2037ULL: goto x86_l_7f5;
	case 2042ULL: goto x86_l_7fa;
	case 2044ULL: goto x86_l_7fc;
	case 2047ULL: goto x86_l_7ff;
	case 2052ULL: goto x86_l_804;
	case 2058ULL: goto x86_l_80a;
	case 2065ULL: goto x86_l_811;
	case 2068ULL: goto x86_l_814;
	case 2071ULL: goto x86_l_817;
	case 2074ULL: goto x86_l_81a;
	case 2078ULL: goto x86_l_81e;
	case 2082ULL: goto x86_l_822;
	case 2084ULL: goto x86_l_824;
	case 2090ULL: goto x86_l_82a;
	case 2093ULL: goto x86_l_82d;
	case 2095ULL: goto x86_l_82f;
	case 2100ULL: goto x86_l_834;
	case 2105ULL: goto x86_l_839;
	case 2108ULL: goto x86_l_83c;
	case 2112ULL: goto x86_l_840;
	case 2117ULL: goto x86_l_845;
	case 2119ULL: goto x86_l_847;
	case 2121ULL: goto x86_l_849;
	case 2127ULL: goto x86_l_84f;
	case 2132ULL: goto x86_l_854;
	case 2138ULL: goto x86_l_85a;
	case 2141ULL: goto x86_l_85d;
	case 2145ULL: goto x86_l_861;
	case 2149ULL: goto x86_l_865;
	case 2154ULL: goto x86_l_86a;
	case 2156ULL: goto x86_l_86c;
	case 2161ULL: goto x86_l_871;
	case 2166ULL: goto x86_l_876;
	case 2169ULL: goto x86_l_879;
	case 2173ULL: goto x86_l_87d;
	case 2178ULL: goto x86_l_882;
	case 2180ULL: goto x86_l_884;
	case 2182ULL: goto x86_l_886;
	case 2188ULL: goto x86_l_88c;
	case 2193ULL: goto x86_l_891;
	case 2199ULL: goto x86_l_897;
	case 2202ULL: goto x86_l_89a;
	case 2206ULL: goto x86_l_89e;
	case 2210ULL: goto x86_l_8a2;
	case 2215ULL: goto x86_l_8a7;
	case 2217ULL: goto x86_l_8a9;
	case 2222ULL: goto x86_l_8ae;
	case 2227ULL: goto x86_l_8b3;
	case 2230ULL: goto x86_l_8b6;
	case 2234ULL: goto x86_l_8ba;
	case 2239ULL: goto x86_l_8bf;
	case 2241ULL: goto x86_l_8c1;
	case 2243ULL: goto x86_l_8c3;
	case 2249ULL: goto x86_l_8c9;
	case 2254ULL: goto x86_l_8ce;
	case 2260ULL: goto x86_l_8d4;
	case 2263ULL: goto x86_l_8d7;
	case 2267ULL: goto x86_l_8db;
	case 2271ULL: goto x86_l_8df;
	case 2276ULL: goto x86_l_8e4;
	case 2278ULL: goto x86_l_8e6;
	case 2283ULL: goto x86_l_8eb;
	case 2288ULL: goto x86_l_8f0;
	case 2291ULL: goto x86_l_8f3;
	case 2295ULL: goto x86_l_8f7;
	case 2300ULL: goto x86_l_8fc;
	case 2302ULL: goto x86_l_8fe;
	case 2304ULL: goto x86_l_900;
	case 2310ULL: goto x86_l_906;
	case 2315ULL: goto x86_l_90b;
	case 2321ULL: goto x86_l_911;
	case 2324ULL: goto x86_l_914;
	case 2328ULL: goto x86_l_918;
	case 2332ULL: goto x86_l_91c;
	case 2337ULL: goto x86_l_921;
	case 2339ULL: goto x86_l_923;
	case 2344ULL: goto x86_l_928;
	case 2349ULL: goto x86_l_92d;
	case 2352ULL: goto x86_l_930;
	case 2356ULL: goto x86_l_934;
	case 2361ULL: goto x86_l_939;
	case 2363ULL: goto x86_l_93b;
	case 2365ULL: goto x86_l_93d;
	case 2371ULL: goto x86_l_943;
	case 2376ULL: goto x86_l_948;
	case 2382ULL: goto x86_l_94e;
	case 2385ULL: goto x86_l_951;
	case 2389ULL: goto x86_l_955;
	case 2393ULL: goto x86_l_959;
	case 2398ULL: goto x86_l_95e;
	case 2400ULL: goto x86_l_960;
	case 2405ULL: goto x86_l_965;
	case 2410ULL: goto x86_l_96a;
	case 2413ULL: goto x86_l_96d;
	case 2417ULL: goto x86_l_971;
	case 2422ULL: goto x86_l_976;
	case 2424ULL: goto x86_l_978;
	case 2426ULL: goto x86_l_97a;
	case 2432ULL: goto x86_l_980;
	case 2437ULL: goto x86_l_985;
	case 2443ULL: goto x86_l_98b;
	case 2446ULL: goto x86_l_98e;
	case 2450ULL: goto x86_l_992;
	case 2454ULL: goto x86_l_996;
	case 2459ULL: goto x86_l_99b;
	case 2461ULL: goto x86_l_99d;
	case 2466ULL: goto x86_l_9a2;
	case 2471ULL: goto x86_l_9a7;
	case 2474ULL: goto x86_l_9aa;
	case 2478ULL: goto x86_l_9ae;
	case 2483ULL: goto x86_l_9b3;
	case 2485ULL: goto x86_l_9b5;
	case 2487ULL: goto x86_l_9b7;
	case 2493ULL: goto x86_l_9bd;
	case 2498ULL: goto x86_l_9c2;
	case 2504ULL: goto x86_l_9c8;
	case 2507ULL: goto x86_l_9cb;
	case 2511ULL: goto x86_l_9cf;
	case 2515ULL: goto x86_l_9d3;
	case 2520ULL: goto x86_l_9d8;
	case 2522ULL: goto x86_l_9da;
	case 2527ULL: goto x86_l_9df;
	case 2532ULL: goto x86_l_9e4;
	case 2535ULL: goto x86_l_9e7;
	case 2539ULL: goto x86_l_9eb;
	case 2544ULL: goto x86_l_9f0;
	case 2546ULL: goto x86_l_9f2;
	case 2548ULL: goto x86_l_9f4;
	case 2554ULL: goto x86_l_9fa;
	case 2559ULL: goto x86_l_9ff;
	case 2565ULL: goto x86_l_a05;
	case 2568ULL: goto x86_l_a08;
	case 2572ULL: goto x86_l_a0c;
	case 2576ULL: goto x86_l_a10;
	case 2581ULL: goto x86_l_a15;
	case 2583ULL: goto x86_l_a17;
	case 2588ULL: goto x86_l_a1c;
	case 2593ULL: goto x86_l_a21;
	case 2596ULL: goto x86_l_a24;
	case 2600ULL: goto x86_l_a28;
	case 2605ULL: goto x86_l_a2d;
	case 2607ULL: goto x86_l_a2f;
	case 2609ULL: goto x86_l_a31;
	case 2615ULL: goto x86_l_a37;
	case 2619ULL: goto x86_l_a3b;
	case 2625ULL: goto x86_l_a41;
	case 2628ULL: goto x86_l_a44;
	case 2632ULL: goto x86_l_a48;
	case 2636ULL: goto x86_l_a4c;
	case 2641ULL: goto x86_l_a51;
	case 2647ULL: goto x86_l_a57;
	case 2652ULL: goto x86_l_a5c;
	case 2657ULL: goto x86_l_a61;
	case 2660ULL: goto x86_l_a64;
	case 2665ULL: goto x86_l_a69;
	case 2668ULL: goto x86_l_a6c;
	case 2670ULL: goto x86_l_a6e;
	case 2675ULL: goto x86_l_a73;
	case 2680ULL: goto x86_l_a78;
	case 2683ULL: goto x86_l_a7b;
	case 2687ULL: goto x86_l_a7f;
	case 2692ULL: goto x86_l_a84;
	case 2694ULL: goto x86_l_a86;
	case 2696ULL: goto x86_l_a88;
	case 2702ULL: goto x86_l_a8e;
	case 2707ULL: goto x86_l_a93;
	case 2713ULL: goto x86_l_a99;
	case 2716ULL: goto x86_l_a9c;
	case 2720ULL: goto x86_l_aa0;
	case 2724ULL: goto x86_l_aa4;
	case 2729ULL: goto x86_l_aa9;
	case 2731ULL: goto x86_l_aab;
	case 2736ULL: goto x86_l_ab0;
	case 2741ULL: goto x86_l_ab5;
	case 2744ULL: goto x86_l_ab8;
	case 2748ULL: goto x86_l_abc;
	case 2753ULL: goto x86_l_ac1;
	case 2755ULL: goto x86_l_ac3;
	case 2757ULL: goto x86_l_ac5;
	case 2763ULL: goto x86_l_acb;
	case 2768ULL: goto x86_l_ad0;
	case 2774ULL: goto x86_l_ad6;
	case 2777ULL: goto x86_l_ad9;
	case 2781ULL: goto x86_l_add;
	case 2785ULL: goto x86_l_ae1;
	case 2790ULL: goto x86_l_ae6;
	case 2792ULL: goto x86_l_ae8;
	case 2797ULL: goto x86_l_aed;
	case 2802ULL: goto x86_l_af2;
	case 2805ULL: goto x86_l_af5;
	case 2809ULL: goto x86_l_af9;
	case 2814ULL: goto x86_l_afe;
	case 2816ULL: goto x86_l_b00;
	case 2818ULL: goto x86_l_b02;
	case 2824ULL: goto x86_l_b08;
	case 2829ULL: goto x86_l_b0d;
	case 2835ULL: goto x86_l_b13;
	case 2838ULL: goto x86_l_b16;
	case 2842ULL: goto x86_l_b1a;
	case 2846ULL: goto x86_l_b1e;
	case 2851ULL: goto x86_l_b23;
	case 2853ULL: goto x86_l_b25;
	case 2858ULL: goto x86_l_b2a;
	case 2863ULL: goto x86_l_b2f;
	case 2866ULL: goto x86_l_b32;
	case 2870ULL: goto x86_l_b36;
	case 2875ULL: goto x86_l_b3b;
	case 2877ULL: goto x86_l_b3d;
	case 2879ULL: goto x86_l_b3f;
	case 2885ULL: goto x86_l_b45;
	case 2890ULL: goto x86_l_b4a;
	case 2896ULL: goto x86_l_b50;
	case 2899ULL: goto x86_l_b53;
	case 2903ULL: goto x86_l_b57;
	case 2907ULL: goto x86_l_b5b;
	case 2912ULL: goto x86_l_b60;
	case 2914ULL: goto x86_l_b62;
	case 2919ULL: goto x86_l_b67;
	case 2924ULL: goto x86_l_b6c;
	case 2927ULL: goto x86_l_b6f;
	case 2931ULL: goto x86_l_b73;
	case 2936ULL: goto x86_l_b78;
	case 2938ULL: goto x86_l_b7a;
	case 2940ULL: goto x86_l_b7c;
	case 2946ULL: goto x86_l_b82;
	case 2951ULL: goto x86_l_b87;
	case 2957ULL: goto x86_l_b8d;
	case 2960ULL: goto x86_l_b90;
	case 2964ULL: goto x86_l_b94;
	case 2968ULL: goto x86_l_b98;
	case 2973ULL: goto x86_l_b9d;
	case 2975ULL: goto x86_l_b9f;
	case 2980ULL: goto x86_l_ba4;
	case 2985ULL: goto x86_l_ba9;
	case 2988ULL: goto x86_l_bac;
	case 2992ULL: goto x86_l_bb0;
	case 2997ULL: goto x86_l_bb5;
	case 2999ULL: goto x86_l_bb7;
	case 3001ULL: goto x86_l_bb9;
	case 3007ULL: goto x86_l_bbf;
	case 3012ULL: goto x86_l_bc4;
	case 3018ULL: goto x86_l_bca;
	case 3021ULL: goto x86_l_bcd;
	case 3025ULL: goto x86_l_bd1;
	case 3029ULL: goto x86_l_bd5;
	case 3034ULL: goto x86_l_bda;
	case 3036ULL: goto x86_l_bdc;
	case 3041ULL: goto x86_l_be1;
	case 3046ULL: goto x86_l_be6;
	case 3049ULL: goto x86_l_be9;
	case 3053ULL: goto x86_l_bed;
	case 3058ULL: goto x86_l_bf2;
	case 3060ULL: goto x86_l_bf4;
	case 3062ULL: goto x86_l_bf6;
	case 3068ULL: goto x86_l_bfc;
	case 3073ULL: goto x86_l_c01;
	case 3079ULL: goto x86_l_c07;
	case 3082ULL: goto x86_l_c0a;
	case 3086ULL: goto x86_l_c0e;
	case 3090ULL: goto x86_l_c12;
	case 3095ULL: goto x86_l_c17;
	case 3097ULL: goto x86_l_c19;
	case 3102ULL: goto x86_l_c1e;
	case 3107ULL: goto x86_l_c23;
	case 3110ULL: goto x86_l_c26;
	case 3114ULL: goto x86_l_c2a;
	case 3119ULL: goto x86_l_c2f;
	case 3121ULL: goto x86_l_c31;
	case 3123ULL: goto x86_l_c33;
	case 3129ULL: goto x86_l_c39;
	case 3134ULL: goto x86_l_c3e;
	case 3140ULL: goto x86_l_c44;
	case 3143ULL: goto x86_l_c47;
	case 3147ULL: goto x86_l_c4b;
	case 3151ULL: goto x86_l_c4f;
	case 3156ULL: goto x86_l_c54;
	case 3158ULL: goto x86_l_c56;
	case 3163ULL: goto x86_l_c5b;
	case 3168ULL: goto x86_l_c60;
	case 3171ULL: goto x86_l_c63;
	case 3175ULL: goto x86_l_c67;
	case 3180ULL: goto x86_l_c6c;
	case 3182ULL: goto x86_l_c6e;
	case 3184ULL: goto x86_l_c70;
	default: return 0xffffffffffffffffULL;
	}
x86_l_66c:
	/* 0x66c: mov    ecx,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_66f:
	/* 0x66f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_673:
	/* 0x673: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_677:
	/* 0x677: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_67c:
	/* 0x67c: je     69e <generic_sleepable_preload+0x69e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_69e;
	}
x86_l_67e:
	/* 0x67e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_683:
	/* 0x683: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_688:
	/* 0x688: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_68b:
	/* 0x68b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_68f:
	/* 0x68f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_694:
	/* 0x694: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_696:
	/* 0x696: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_698:
	/* 0x698: js     d24 <generic_sleepable_preload+0xd24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3364ULL;
	}
x86_l_69e:
	/* 0x69e: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_6a3:
	/* 0x6a3: je     d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3372ULL;
	}
x86_l_6a9:
	/* 0x6a9: mov    ecx,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_6ac:
	/* 0x6ac: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_6b0:
	/* 0x6b0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6b4:
	/* 0x6b4: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_6b9:
	/* 0x6b9: je     6db <generic_sleepable_preload+0x6db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6db;
	}
x86_l_6bb:
	/* 0x6bb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_6c0:
	/* 0x6c0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6c5:
	/* 0x6c5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6c8:
	/* 0x6c8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6cc:
	/* 0x6cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6d1:
	/* 0x6d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d3:
	/* 0x6d3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6d5:
	/* 0x6d5: js     ec2 <generic_sleepable_preload+0xec2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3778ULL;
	}
x86_l_6db:
	/* 0x6db: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_6e0:
	/* 0x6e0: je     d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3372ULL;
	}
x86_l_6e6:
	/* 0x6e6: mov    ecx,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_6e9:
	/* 0x6e9: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_6ed:
	/* 0x6ed: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6f1:
	/* 0x6f1: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_6f6:
	/* 0x6f6: je     718 <generic_sleepable_preload+0x718> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_718;
	}
x86_l_6f8:
	/* 0x6f8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_6fd:
	/* 0x6fd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_702:
	/* 0x702: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_705:
	/* 0x705: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_709:
	/* 0x709: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_70e:
	/* 0x70e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_710:
	/* 0x710: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_712:
	/* 0x712: js     ee6 <generic_sleepable_preload+0xee6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3814ULL;
	}
x86_l_718:
	/* 0x718: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_71c:
	/* 0x71c: je     d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3372ULL;
	}
x86_l_722:
	/* 0x722: mov    ecx,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_725:
	/* 0x725: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_729:
	/* 0x729: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_72d:
	/* 0x72d: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_732:
	/* 0x732: je     d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3372ULL;
	}
x86_l_738:
	/* 0x738: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_73d:
	/* 0x73d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_742:
	/* 0x742: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_745:
	/* 0x745: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_749:
	/* 0x749: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_74e:
	/* 0x74e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_750:
	/* 0x750: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_752:
	/* 0x752: jns    d2c <generic_sleepable_preload+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 3372ULL;
	}
x86_l_758:
	/* 0x758: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_75e:
	/* 0x75e: jmp    d2a <generic_sleepable_preload+0xd2a> */
	return 3370ULL;
x86_l_763:
	/* 0x763: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_769:
	/* 0x769: jmp    d2a <generic_sleepable_preload+0xd2a> */
	return 3370ULL;
x86_l_76e:
	/* 0x76e: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_776:
	/* 0x776: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_779:
	/* 0x779: je     7de <generic_sleepable_preload+0x7de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7de;
	}
x86_l_77b:
	/* 0x77b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_780:
	/* 0x780: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_785:
	/* 0x785: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_788:
	/* 0x788: je     7de <generic_sleepable_preload+0x7de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7de;
	}
x86_l_78a:
	/* 0x78a: jmp    7f1 <generic_sleepable_preload+0x7f1> */
	goto x86_l_7f1;
x86_l_78c:
	/* 0x78c: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_791:
	/* 0x791: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_794:
	/* 0x794: je     7de <generic_sleepable_preload+0x7de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7de;
	}
x86_l_796:
	/* 0x796: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_79b:
	/* 0x79b: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_7a0:
	/* 0x7a0: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_7a3:
	/* 0x7a3: je     7de <generic_sleepable_preload+0x7de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7de;
	}
x86_l_7a5:
	/* 0x7a5: jmp    7f1 <generic_sleepable_preload+0x7f1> */
	goto x86_l_7f1;
x86_l_7a7:
	/* 0x7a7: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_7af:
	/* 0x7af: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_7b2:
	/* 0x7b2: je     7de <generic_sleepable_preload+0x7de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7de;
	}
x86_l_7b4:
	/* 0x7b4: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_7b9:
	/* 0x7b9: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_7be:
	/* 0x7be: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_7c1:
	/* 0x7c1: je     7de <generic_sleepable_preload+0x7de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7de;
	}
x86_l_7c3:
	/* 0x7c3: jmp    7f1 <generic_sleepable_preload+0x7f1> */
	goto x86_l_7f1;
x86_l_7c5:
	/* 0x7c5: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7ca:
	/* 0x7ca: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_7cd:
	/* 0x7cd: je     7de <generic_sleepable_preload+0x7de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7de;
	}
x86_l_7cf:
	/* 0x7cf: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7d4:
	/* 0x7d4: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_7d9:
	/* 0x7d9: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_7dc:
	/* 0x7dc: jne    7f1 <generic_sleepable_preload+0x7f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7f1;
	}
x86_l_7de:
	/* 0x7de: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_7e1:
	/* 0x7e1: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_7e3:
	/* 0x7e3: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_7e5:
	/* 0x7e5: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_7ea:
	/* 0x7ea: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_7ec:
	/* 0x7ec: bzhi   rsi,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RSI, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_7f1:
	/* 0x7f1: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7f5:
	/* 0x7f5: mov    r12d,DWORD PTR [r12+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_7fa:
	/* 0x7fa: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7fc:
	/* 0x7fc: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_7ff:
	/* 0x7ff: cmp    WORD PTR [rbx-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743764471906304ULL);
x86_l_804:
	/* 0x804: je     e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3597ULL;
	}
x86_l_80a:
	/* 0x80a: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_811:
	/* 0x811: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_814:
	/* 0x814: mov    eax,DWORD PTR [rbx-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551538ULL);
x86_l_817:
	/* 0x817: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_81a:
	/* 0x81a: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_81e:
	/* 0x81e: movzx  eax,WORD PTR [rbx-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_822:
	/* 0x822: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_824:
	/* 0x824: je     a69 <generic_sleepable_preload+0xa69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a69;
	}
x86_l_82a:
	/* 0x82a: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_82d:
	/* 0x82d: je     84f <generic_sleepable_preload+0x84f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_84f;
	}
x86_l_82f:
	/* 0x82f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_834:
	/* 0x834: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_839:
	/* 0x839: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_83c:
	/* 0x83c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_840:
	/* 0x840: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_845:
	/* 0x845: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_847:
	/* 0x847: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_849:
	/* 0x849: js     cc0 <generic_sleepable_preload+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3264ULL;
	}
x86_l_84f:
	/* 0x84f: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_854:
	/* 0x854: je     e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3597ULL;
	}
x86_l_85a:
	/* 0x85a: mov    ecx,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_85d:
	/* 0x85d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_861:
	/* 0x861: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_865:
	/* 0x865: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_86a:
	/* 0x86a: je     88c <generic_sleepable_preload+0x88c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_88c;
	}
x86_l_86c:
	/* 0x86c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_871:
	/* 0x871: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_876:
	/* 0x876: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_879:
	/* 0x879: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_87d:
	/* 0x87d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_882:
	/* 0x882: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_884:
	/* 0x884: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_886:
	/* 0x886: js     cd2 <generic_sleepable_preload+0xcd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3282ULL;
	}
x86_l_88c:
	/* 0x88c: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_891:
	/* 0x891: je     e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3597ULL;
	}
x86_l_897:
	/* 0x897: mov    ecx,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_89a:
	/* 0x89a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_89e:
	/* 0x89e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8a2:
	/* 0x8a2: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_8a7:
	/* 0x8a7: je     8c9 <generic_sleepable_preload+0x8c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8c9;
	}
x86_l_8a9:
	/* 0x8a9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8ae:
	/* 0x8ae: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_8b3:
	/* 0x8b3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8b6:
	/* 0x8b6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8ba:
	/* 0x8ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8bf:
	/* 0x8bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c1:
	/* 0x8c1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8c3:
	/* 0x8c3: js     ce4 <generic_sleepable_preload+0xce4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3300ULL;
	}
x86_l_8c9:
	/* 0x8c9: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_8ce:
	/* 0x8ce: je     e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3597ULL;
	}
x86_l_8d4:
	/* 0x8d4: mov    ecx,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_8d7:
	/* 0x8d7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_8db:
	/* 0x8db: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8df:
	/* 0x8df: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_8e4:
	/* 0x8e4: je     906 <generic_sleepable_preload+0x906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_906;
	}
x86_l_8e6:
	/* 0x8e6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8eb:
	/* 0x8eb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_8f0:
	/* 0x8f0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8f3:
	/* 0x8f3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8f7:
	/* 0x8f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8fc:
	/* 0x8fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8fe:
	/* 0x8fe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_900:
	/* 0x900: js     cf6 <generic_sleepable_preload+0xcf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3318ULL;
	}
x86_l_906:
	/* 0x906: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_90b:
	/* 0x90b: je     e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3597ULL;
	}
x86_l_911:
	/* 0x911: mov    ecx,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_914:
	/* 0x914: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_918:
	/* 0x918: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_91c:
	/* 0x91c: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_921:
	/* 0x921: je     943 <generic_sleepable_preload+0x943> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_943;
	}
x86_l_923:
	/* 0x923: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_928:
	/* 0x928: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_92d:
	/* 0x92d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_930:
	/* 0x930: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_934:
	/* 0x934: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_939:
	/* 0x939: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_93b:
	/* 0x93b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_93d:
	/* 0x93d: js     d08 <generic_sleepable_preload+0xd08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3336ULL;
	}
x86_l_943:
	/* 0x943: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_948:
	/* 0x948: je     e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3597ULL;
	}
x86_l_94e:
	/* 0x94e: mov    ecx,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_951:
	/* 0x951: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_955:
	/* 0x955: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_959:
	/* 0x959: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_95e:
	/* 0x95e: je     980 <generic_sleepable_preload+0x980> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_980;
	}
x86_l_960:
	/* 0x960: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_965:
	/* 0x965: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_96a:
	/* 0x96a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_96d:
	/* 0x96d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_971:
	/* 0x971: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_976:
	/* 0x976: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_978:
	/* 0x978: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_97a:
	/* 0x97a: js     d1a <generic_sleepable_preload+0xd1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3354ULL;
	}
x86_l_980:
	/* 0x980: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_985:
	/* 0x985: je     e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3597ULL;
	}
x86_l_98b:
	/* 0x98b: mov    ecx,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_98e:
	/* 0x98e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_992:
	/* 0x992: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_996:
	/* 0x996: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_99b:
	/* 0x99b: je     9bd <generic_sleepable_preload+0x9bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9bd;
	}
x86_l_99d:
	/* 0x99d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_9a2:
	/* 0x9a2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_9a7:
	/* 0x9a7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_9aa:
	/* 0x9aa: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9ae:
	/* 0x9ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9b3:
	/* 0x9b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b5:
	/* 0x9b5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9b7:
	/* 0x9b7: js     e05 <generic_sleepable_preload+0xe05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3589ULL;
	}
x86_l_9bd:
	/* 0x9bd: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_9c2:
	/* 0x9c2: je     e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3597ULL;
	}
x86_l_9c8:
	/* 0x9c8: mov    ecx,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_9cb:
	/* 0x9cb: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_9cf:
	/* 0x9cf: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9d3:
	/* 0x9d3: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_9d8:
	/* 0x9d8: je     9fa <generic_sleepable_preload+0x9fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9fa;
	}
x86_l_9da:
	/* 0x9da: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_9df:
	/* 0x9df: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_9e4:
	/* 0x9e4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_9e7:
	/* 0x9e7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9eb:
	/* 0x9eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9f0:
	/* 0x9f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f2:
	/* 0x9f2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9f4:
	/* 0x9f4: js     ecf <generic_sleepable_preload+0xecf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3791ULL;
	}
x86_l_9fa:
	/* 0x9fa: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_9ff:
	/* 0x9ff: je     e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3597ULL;
	}
x86_l_a05:
	/* 0xa05: mov    ecx,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_a08:
	/* 0xa08: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_a0c:
	/* 0xa0c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a10:
	/* 0xa10: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_a15:
	/* 0xa15: je     a37 <generic_sleepable_preload+0xa37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a37;
	}
x86_l_a17:
	/* 0xa17: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a1c:
	/* 0xa1c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a21:
	/* 0xa21: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a24:
	/* 0xa24: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a28:
	/* 0xa28: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a2d:
	/* 0xa2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a2f:
	/* 0xa2f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a31:
	/* 0xa31: js     ef1 <generic_sleepable_preload+0xef1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3825ULL;
	}
x86_l_a37:
	/* 0xa37: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a3b:
	/* 0xa3b: je     e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3597ULL;
	}
x86_l_a41:
	/* 0xa41: mov    ecx,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_a44:
	/* 0xa44: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_a48:
	/* 0xa48: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a4c:
	/* 0xa4c: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_a51:
	/* 0xa51: je     e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3597ULL;
	}
x86_l_a57:
	/* 0xa57: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a5c:
	/* 0xa5c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a61:
	/* 0xa61: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a64:
	/* 0xa64: jmp    ca3 <generic_sleepable_preload+0xca3> */
	return 3235ULL;
x86_l_a69:
	/* 0xa69: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_a6c:
	/* 0xa6c: je     a8e <generic_sleepable_preload+0xa8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a8e;
	}
x86_l_a6e:
	/* 0xa6e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a73:
	/* 0xa73: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a78:
	/* 0xa78: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a7b:
	/* 0xa7b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a7f:
	/* 0xa7f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a84:
	/* 0xa84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a86:
	/* 0xa86: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a88:
	/* 0xa88: js     cc0 <generic_sleepable_preload+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3264ULL;
	}
x86_l_a8e:
	/* 0xa8e: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_a93:
	/* 0xa93: je     e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3597ULL;
	}
x86_l_a99:
	/* 0xa99: mov    ecx,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_a9c:
	/* 0xa9c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_aa0:
	/* 0xaa0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aa4:
	/* 0xaa4: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_aa9:
	/* 0xaa9: je     acb <generic_sleepable_preload+0xacb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_acb;
	}
x86_l_aab:
	/* 0xaab: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ab0:
	/* 0xab0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ab5:
	/* 0xab5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ab8:
	/* 0xab8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_abc:
	/* 0xabc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ac1:
	/* 0xac1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac3:
	/* 0xac3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ac5:
	/* 0xac5: js     cd2 <generic_sleepable_preload+0xcd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3282ULL;
	}
x86_l_acb:
	/* 0xacb: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_ad0:
	/* 0xad0: je     e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3597ULL;
	}
x86_l_ad6:
	/* 0xad6: mov    ecx,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_ad9:
	/* 0xad9: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_add:
	/* 0xadd: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ae1:
	/* 0xae1: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_ae6:
	/* 0xae6: je     b08 <generic_sleepable_preload+0xb08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b08;
	}
x86_l_ae8:
	/* 0xae8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_aed:
	/* 0xaed: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_af2:
	/* 0xaf2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_af5:
	/* 0xaf5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af9:
	/* 0xaf9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_afe:
	/* 0xafe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b00:
	/* 0xb00: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b02:
	/* 0xb02: js     ce4 <generic_sleepable_preload+0xce4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3300ULL;
	}
x86_l_b08:
	/* 0xb08: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_b0d:
	/* 0xb0d: je     e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3597ULL;
	}
x86_l_b13:
	/* 0xb13: mov    ecx,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_b16:
	/* 0xb16: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_b1a:
	/* 0xb1a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b1e:
	/* 0xb1e: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_b23:
	/* 0xb23: je     b45 <generic_sleepable_preload+0xb45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b45;
	}
x86_l_b25:
	/* 0xb25: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b2a:
	/* 0xb2a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b2f:
	/* 0xb2f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b32:
	/* 0xb32: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b36:
	/* 0xb36: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b3b:
	/* 0xb3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b3d:
	/* 0xb3d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b3f:
	/* 0xb3f: js     cf6 <generic_sleepable_preload+0xcf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3318ULL;
	}
x86_l_b45:
	/* 0xb45: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_b4a:
	/* 0xb4a: je     e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3597ULL;
	}
x86_l_b50:
	/* 0xb50: mov    ecx,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_b53:
	/* 0xb53: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_b57:
	/* 0xb57: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b5b:
	/* 0xb5b: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_b60:
	/* 0xb60: je     b82 <generic_sleepable_preload+0xb82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b82;
	}
x86_l_b62:
	/* 0xb62: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b67:
	/* 0xb67: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b6c:
	/* 0xb6c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b6f:
	/* 0xb6f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b73:
	/* 0xb73: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b78:
	/* 0xb78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b7a:
	/* 0xb7a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b7c:
	/* 0xb7c: js     d08 <generic_sleepable_preload+0xd08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3336ULL;
	}
x86_l_b82:
	/* 0xb82: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_b87:
	/* 0xb87: je     e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3597ULL;
	}
x86_l_b8d:
	/* 0xb8d: mov    ecx,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_b90:
	/* 0xb90: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_b94:
	/* 0xb94: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b98:
	/* 0xb98: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_b9d:
	/* 0xb9d: je     bbf <generic_sleepable_preload+0xbbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bbf;
	}
x86_l_b9f:
	/* 0xb9f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ba4:
	/* 0xba4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ba9:
	/* 0xba9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_bac:
	/* 0xbac: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bb0:
	/* 0xbb0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bb5:
	/* 0xbb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb7:
	/* 0xbb7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bb9:
	/* 0xbb9: js     d1a <generic_sleepable_preload+0xd1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3354ULL;
	}
x86_l_bbf:
	/* 0xbbf: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_bc4:
	/* 0xbc4: je     e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3597ULL;
	}
x86_l_bca:
	/* 0xbca: mov    ecx,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_bcd:
	/* 0xbcd: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_bd1:
	/* 0xbd1: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bd5:
	/* 0xbd5: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_bda:
	/* 0xbda: je     bfc <generic_sleepable_preload+0xbfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bfc;
	}
x86_l_bdc:
	/* 0xbdc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_be1:
	/* 0xbe1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_be6:
	/* 0xbe6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_be9:
	/* 0xbe9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bed:
	/* 0xbed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bf2:
	/* 0xbf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf4:
	/* 0xbf4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bf6:
	/* 0xbf6: js     e05 <generic_sleepable_preload+0xe05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3589ULL;
	}
x86_l_bfc:
	/* 0xbfc: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_c01:
	/* 0xc01: je     e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3597ULL;
	}
x86_l_c07:
	/* 0xc07: mov    ecx,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_c0a:
	/* 0xc0a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_c0e:
	/* 0xc0e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c12:
	/* 0xc12: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_c17:
	/* 0xc17: je     c39 <generic_sleepable_preload+0xc39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c39;
	}
x86_l_c19:
	/* 0xc19: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c1e:
	/* 0xc1e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c23:
	/* 0xc23: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c26:
	/* 0xc26: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c2a:
	/* 0xc2a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c2f:
	/* 0xc2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c31:
	/* 0xc31: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c33:
	/* 0xc33: js     ecf <generic_sleepable_preload+0xecf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3791ULL;
	}
x86_l_c39:
	/* 0xc39: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_c3e:
	/* 0xc3e: je     e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3597ULL;
	}
x86_l_c44:
	/* 0xc44: mov    ecx,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_c47:
	/* 0xc47: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_c4b:
	/* 0xc4b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c4f:
	/* 0xc4f: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_c54:
	/* 0xc54: je     c76 <generic_sleepable_preload+0xc76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3190ULL;
	}
x86_l_c56:
	/* 0xc56: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c5b:
	/* 0xc5b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c60:
	/* 0xc60: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c63:
	/* 0xc63: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c67:
	/* 0xc67: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c6c:
	/* 0xc6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c6e:
	/* 0xc6e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c70:
	/* 0xc70: js     ef1 <generic_sleepable_preload+0xef1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3825ULL;
	}
	return 3190ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3190ULL: goto x86_l_c76;
	case 3194ULL: goto x86_l_c7a;
	case 3200ULL: goto x86_l_c80;
	case 3203ULL: goto x86_l_c83;
	case 3207ULL: goto x86_l_c87;
	case 3211ULL: goto x86_l_c8b;
	case 3216ULL: goto x86_l_c90;
	case 3222ULL: goto x86_l_c96;
	case 3227ULL: goto x86_l_c9b;
	case 3232ULL: goto x86_l_ca0;
	case 3235ULL: goto x86_l_ca3;
	case 3239ULL: goto x86_l_ca7;
	case 3244ULL: goto x86_l_cac;
	case 3246ULL: goto x86_l_cae;
	case 3248ULL: goto x86_l_cb0;
	case 3254ULL: goto x86_l_cb6;
	case 3259ULL: goto x86_l_cbb;
	case 3264ULL: goto x86_l_cc0;
	case 3269ULL: goto x86_l_cc5;
	case 3274ULL: goto x86_l_cca;
	case 3280ULL: goto x86_l_cd0;
	case 3282ULL: goto x86_l_cd2;
	case 3287ULL: goto x86_l_cd7;
	case 3292ULL: goto x86_l_cdc;
	case 3298ULL: goto x86_l_ce2;
	case 3300ULL: goto x86_l_ce4;
	case 3305ULL: goto x86_l_ce9;
	case 3310ULL: goto x86_l_cee;
	case 3316ULL: goto x86_l_cf4;
	case 3318ULL: goto x86_l_cf6;
	case 3323ULL: goto x86_l_cfb;
	case 3328ULL: goto x86_l_d00;
	case 3334ULL: goto x86_l_d06;
	case 3336ULL: goto x86_l_d08;
	case 3341ULL: goto x86_l_d0d;
	case 3346ULL: goto x86_l_d12;
	case 3352ULL: goto x86_l_d18;
	case 3354ULL: goto x86_l_d1a;
	case 3359ULL: goto x86_l_d1f;
	case 3364ULL: goto x86_l_d24;
	case 3370ULL: goto x86_l_d2a;
	case 3372ULL: goto x86_l_d2c;
	case 3377ULL: goto x86_l_d31;
	case 3382ULL: goto x86_l_d36;
	case 3387ULL: goto x86_l_d3b;
	case 3390ULL: goto x86_l_d3e;
	case 3395ULL: goto x86_l_d43;
	case 3398ULL: goto x86_l_d46;
	case 3400ULL: goto x86_l_d48;
	case 3404ULL: goto x86_l_d4c;
	case 3410ULL: goto x86_l_d52;
	case 3414ULL: goto x86_l_d56;
	case 3422ULL: goto x86_l_d5e;
	case 3427ULL: goto x86_l_d63;
	case 3429ULL: goto x86_l_d65;
	case 3434ULL: goto x86_l_d6a;
	case 3442ULL: goto x86_l_d72;
	case 3447ULL: goto x86_l_d77;
	case 3454ULL: goto x86_l_d7e;
	case 3459ULL: goto x86_l_d83;
	case 3461ULL: goto x86_l_d85;
	case 3464ULL: goto x86_l_d88;
	case 3470ULL: goto x86_l_d8e;
	case 3473ULL: goto x86_l_d91;
	case 3478ULL: goto x86_l_d96;
	case 3480ULL: goto x86_l_d98;
	case 3487ULL: goto x86_l_d9f;
	case 3490ULL: goto x86_l_da2;
	case 3493ULL: goto x86_l_da5;
	case 3498ULL: goto x86_l_daa;
	case 3501ULL: goto x86_l_dad;
	case 3504ULL: goto x86_l_db0;
	case 3506ULL: goto x86_l_db2;
	case 3508ULL: goto x86_l_db4;
	case 3513ULL: goto x86_l_db9;
	case 3516ULL: goto x86_l_dbc;
	case 3519ULL: goto x86_l_dbf;
	case 3521ULL: goto x86_l_dc1;
	case 3524ULL: goto x86_l_dc4;
	case 3530ULL: goto x86_l_dca;
	case 3533ULL: goto x86_l_dcd;
	case 3539ULL: goto x86_l_dd3;
	case 3543ULL: goto x86_l_dd7;
	case 3548ULL: goto x86_l_ddc;
	case 3556ULL: goto x86_l_de4;
	case 3558ULL: goto x86_l_de6;
	case 3561ULL: goto x86_l_de9;
	case 3566ULL: goto x86_l_dee;
	case 3568ULL: goto x86_l_df0;
	case 3571ULL: goto x86_l_df3;
	case 3573ULL: goto x86_l_df5;
	case 3579ULL: goto x86_l_dfb;
	case 3584ULL: goto x86_l_e00;
	case 3589ULL: goto x86_l_e05;
	case 3594ULL: goto x86_l_e0a;
	case 3597ULL: goto x86_l_e0d;
	case 3601ULL: goto x86_l_e11;
	case 3607ULL: goto x86_l_e17;
	case 3611ULL: goto x86_l_e1b;
	case 3619ULL: goto x86_l_e23;
	case 3624ULL: goto x86_l_e28;
	case 3626ULL: goto x86_l_e2a;
	case 3631ULL: goto x86_l_e2f;
	case 3639ULL: goto x86_l_e37;
	case 3644ULL: goto x86_l_e3c;
	case 3651ULL: goto x86_l_e43;
	case 3656ULL: goto x86_l_e48;
	case 3658ULL: goto x86_l_e4a;
	case 3661ULL: goto x86_l_e4d;
	case 3667ULL: goto x86_l_e53;
	case 3670ULL: goto x86_l_e56;
	case 3675ULL: goto x86_l_e5b;
	case 3677ULL: goto x86_l_e5d;
	case 3684ULL: goto x86_l_e64;
	case 3687ULL: goto x86_l_e67;
	case 3690ULL: goto x86_l_e6a;
	case 3695ULL: goto x86_l_e6f;
	case 3698ULL: goto x86_l_e72;
	case 3701ULL: goto x86_l_e75;
	case 3703ULL: goto x86_l_e77;
	case 3705ULL: goto x86_l_e79;
	case 3710ULL: goto x86_l_e7e;
	case 3713ULL: goto x86_l_e81;
	case 3716ULL: goto x86_l_e84;
	case 3718ULL: goto x86_l_e86;
	case 3721ULL: goto x86_l_e89;
	case 3727ULL: goto x86_l_e8f;
	case 3730ULL: goto x86_l_e92;
	case 3733ULL: goto x86_l_e95;
	case 3735ULL: goto x86_l_e97;
	case 3739ULL: goto x86_l_e9b;
	case 3744ULL: goto x86_l_ea0;
	case 3752ULL: goto x86_l_ea8;
	case 3754ULL: goto x86_l_eaa;
	case 3759ULL: goto x86_l_eaf;
	case 3761ULL: goto x86_l_eb1;
	case 3763ULL: goto x86_l_eb3;
	case 3769ULL: goto x86_l_eb9;
	case 3773ULL: goto x86_l_ebd;
	case 3778ULL: goto x86_l_ec2;
	case 3780ULL: goto x86_l_ec4;
	case 3786ULL: goto x86_l_eca;
	case 3791ULL: goto x86_l_ecf;
	case 3794ULL: goto x86_l_ed2;
	case 3799ULL: goto x86_l_ed7;
	case 3803ULL: goto x86_l_edb;
	case 3809ULL: goto x86_l_ee1;
	case 3814ULL: goto x86_l_ee6;
	case 3820ULL: goto x86_l_eec;
	case 3825ULL: goto x86_l_ef1;
	case 3830ULL: goto x86_l_ef6;
	case 3835ULL: goto x86_l_efb;
	case 3840ULL: goto x86_l_f00;
	case 3845ULL: goto x86_l_f05;
	case 3851ULL: goto x86_l_f0b;
	case 3853ULL: goto x86_l_f0d;
	case 3855ULL: goto x86_l_f0f;
	case 3860ULL: goto x86_l_f14;
	case 3863ULL: goto x86_l_f17;
	case 3869ULL: goto x86_l_f1d;
	case 3872ULL: goto x86_l_f20;
	case 3878ULL: goto x86_l_f26;
	case 3881ULL: goto x86_l_f29;
	case 3887ULL: goto x86_l_f2f;
	case 3890ULL: goto x86_l_f32;
	case 3896ULL: goto x86_l_f38;
	case 3901ULL: goto x86_l_f3d;
	case 3906ULL: goto x86_l_f42;
	case 3915ULL: goto x86_l_f4b;
	case 3924ULL: goto x86_l_f54;
	case 3930ULL: goto x86_l_f5a;
	case 3932ULL: goto x86_l_f5c;
	case 3935ULL: goto x86_l_f5f;
	case 3937ULL: goto x86_l_f61;
	case 3940ULL: goto x86_l_f64;
	case 3942ULL: goto x86_l_f66;
	case 3945ULL: goto x86_l_f69;
	case 3951ULL: goto x86_l_f6f;
	case 3956ULL: goto x86_l_f74;
	case 3959ULL: goto x86_l_f77;
	case 3965ULL: goto x86_l_f7d;
	case 3970ULL: goto x86_l_f82;
	case 3973ULL: goto x86_l_f85;
	case 3979ULL: goto x86_l_f8b;
	case 3982ULL: goto x86_l_f8e;
	case 3988ULL: goto x86_l_f94;
	case 3993ULL: goto x86_l_f99;
	case 3998ULL: goto x86_l_f9e;
	case 4001ULL: goto x86_l_fa1;
	case 4003ULL: goto x86_l_fa3;
	case 4006ULL: goto x86_l_fa6;
	case 4012ULL: goto x86_l_fac;
	case 4017ULL: goto x86_l_fb1;
	case 4019ULL: goto x86_l_fb3;
	case 4025ULL: goto x86_l_fb9;
	case 4028ULL: goto x86_l_fbc;
	case 4031ULL: goto x86_l_fbf;
	case 4037ULL: goto x86_l_fc5;
	case 4042ULL: goto x86_l_fca;
	case 4044ULL: goto x86_l_fcc;
	case 4046ULL: goto x86_l_fce;
	case 4049ULL: goto x86_l_fd1;
	case 4051ULL: goto x86_l_fd3;
	case 4056ULL: goto x86_l_fd8;
	case 4058ULL: goto x86_l_fda;
	case 4061ULL: goto x86_l_fdd;
	case 4067ULL: goto x86_l_fe3;
	case 4075ULL: goto x86_l_feb;
	case 4078ULL: goto x86_l_fee;
	case 4084ULL: goto x86_l_ff4;
	case 4089ULL: goto x86_l_ff9;
	case 4092ULL: goto x86_l_ffc;
	case 4098ULL: goto x86_l_1002;
	case 4103ULL: goto x86_l_1007;
	case 4106ULL: goto x86_l_100a;
	case 4112ULL: goto x86_l_1010;
	case 4120ULL: goto x86_l_1018;
	case 4123ULL: goto x86_l_101b;
	case 4129ULL: goto x86_l_1021;
	case 4134ULL: goto x86_l_1026;
	case 4137ULL: goto x86_l_1029;
	case 4143ULL: goto x86_l_102f;
	case 4148ULL: goto x86_l_1034;
	case 4153ULL: goto x86_l_1039;
	case 4155ULL: goto x86_l_103b;
	case 4160ULL: goto x86_l_1040;
	case 4162ULL: goto x86_l_1042;
	case 4167ULL: goto x86_l_1047;
	case 4170ULL: goto x86_l_104a;
	case 4174ULL: goto x86_l_104e;
	case 4176ULL: goto x86_l_1050;
	case 4179ULL: goto x86_l_1053;
	case 4186ULL: goto x86_l_105a;
	case 4192ULL: goto x86_l_1060;
	case 4199ULL: goto x86_l_1067;
	case 4202ULL: goto x86_l_106a;
	case 4207ULL: goto x86_l_106f;
	case 4210ULL: goto x86_l_1072;
	case 4214ULL: goto x86_l_1076;
	case 4220ULL: goto x86_l_107c;
	case 4222ULL: goto x86_l_107e;
	case 4228ULL: goto x86_l_1084;
	case 4231ULL: goto x86_l_1087;
	case 4233ULL: goto x86_l_1089;
	case 4236ULL: goto x86_l_108c;
	case 4241ULL: goto x86_l_1091;
	case 4246ULL: goto x86_l_1096;
	case 4250ULL: goto x86_l_109a;
	case 4255ULL: goto x86_l_109f;
	case 4257ULL: goto x86_l_10a1;
	case 4259ULL: goto x86_l_10a3;
	case 4265ULL: goto x86_l_10a9;
	case 4272ULL: goto x86_l_10b0;
	case 4278ULL: goto x86_l_10b6;
	case 4283ULL: goto x86_l_10bb;
	case 4287ULL: goto x86_l_10bf;
	case 4291ULL: goto x86_l_10c3;
	case 4298ULL: goto x86_l_10ca;
	case 4300ULL: goto x86_l_10cc;
	case 4303ULL: goto x86_l_10cf;
	case 4308ULL: goto x86_l_10d4;
	case 4313ULL: goto x86_l_10d9;
	case 4317ULL: goto x86_l_10dd;
	case 4322ULL: goto x86_l_10e2;
	case 4324ULL: goto x86_l_10e4;
	case 4326ULL: goto x86_l_10e6;
	case 4332ULL: goto x86_l_10ec;
	case 4342ULL: goto x86_l_10f6;
	case 4348ULL: goto x86_l_10fc;
	case 4356ULL: goto x86_l_1104;
	case 4360ULL: goto x86_l_1108;
	case 4364ULL: goto x86_l_110c;
	case 4374ULL: goto x86_l_1116;
	case 4376ULL: goto x86_l_1118;
	case 4379ULL: goto x86_l_111b;
	case 4384ULL: goto x86_l_1120;
	case 4389ULL: goto x86_l_1125;
	case 4393ULL: goto x86_l_1129;
	case 4398ULL: goto x86_l_112e;
	case 4400ULL: goto x86_l_1130;
	case 4402ULL: goto x86_l_1132;
	case 4408ULL: goto x86_l_1138;
	case 4418ULL: goto x86_l_1142;
	case 4424ULL: goto x86_l_1148;
	case 4432ULL: goto x86_l_1150;
	case 4436ULL: goto x86_l_1154;
	case 4440ULL: goto x86_l_1158;
	case 4450ULL: goto x86_l_1162;
	case 4452ULL: goto x86_l_1164;
	case 4455ULL: goto x86_l_1167;
	case 4460ULL: goto x86_l_116c;
	case 4465ULL: goto x86_l_1171;
	case 4469ULL: goto x86_l_1175;
	case 4474ULL: goto x86_l_117a;
	case 4476ULL: goto x86_l_117c;
	case 4478ULL: goto x86_l_117e;
	case 4484ULL: goto x86_l_1184;
	case 4494ULL: goto x86_l_118e;
	case 4500ULL: goto x86_l_1194;
	case 4508ULL: goto x86_l_119c;
	case 4512ULL: goto x86_l_11a0;
	case 4516ULL: goto x86_l_11a4;
	case 4526ULL: goto x86_l_11ae;
	case 4528ULL: goto x86_l_11b0;
	case 4531ULL: goto x86_l_11b3;
	case 4536ULL: goto x86_l_11b8;
	case 4541ULL: goto x86_l_11bd;
	case 4545ULL: goto x86_l_11c1;
	case 4550ULL: goto x86_l_11c6;
	case 4552ULL: goto x86_l_11c8;
	case 4554ULL: goto x86_l_11ca;
	case 4560ULL: goto x86_l_11d0;
	case 4570ULL: goto x86_l_11da;
	case 4576ULL: goto x86_l_11e0;
	case 4584ULL: goto x86_l_11e8;
	case 4588ULL: goto x86_l_11ec;
	case 4592ULL: goto x86_l_11f0;
	case 4602ULL: goto x86_l_11fa;
	case 4604ULL: goto x86_l_11fc;
	case 4607ULL: goto x86_l_11ff;
	case 4612ULL: goto x86_l_1204;
	case 4617ULL: goto x86_l_1209;
	case 4621ULL: goto x86_l_120d;
	case 4626ULL: goto x86_l_1212;
	case 4628ULL: goto x86_l_1214;
	case 4630ULL: goto x86_l_1216;
	case 4636ULL: goto x86_l_121c;
	case 4646ULL: goto x86_l_1226;
	case 4652ULL: goto x86_l_122c;
	case 4660ULL: goto x86_l_1234;
	case 4664ULL: goto x86_l_1238;
	case 4668ULL: goto x86_l_123c;
	case 4678ULL: goto x86_l_1246;
	case 4680ULL: goto x86_l_1248;
	case 4683ULL: goto x86_l_124b;
	case 4688ULL: goto x86_l_1250;
	case 4693ULL: goto x86_l_1255;
	case 4697ULL: goto x86_l_1259;
	case 4702ULL: goto x86_l_125e;
	case 4704ULL: goto x86_l_1260;
	case 4706ULL: goto x86_l_1262;
	case 4712ULL: goto x86_l_1268;
	case 4722ULL: goto x86_l_1272;
	case 4728ULL: goto x86_l_1278;
	case 4736ULL: goto x86_l_1280;
	case 4740ULL: goto x86_l_1284;
	case 4744ULL: goto x86_l_1288;
	case 4754ULL: goto x86_l_1292;
	case 4756ULL: goto x86_l_1294;
	case 4759ULL: goto x86_l_1297;
	case 4764ULL: goto x86_l_129c;
	case 4769ULL: goto x86_l_12a1;
	case 4773ULL: goto x86_l_12a5;
	case 4778ULL: goto x86_l_12aa;
	case 4780ULL: goto x86_l_12ac;
	case 4782ULL: goto x86_l_12ae;
	case 4788ULL: goto x86_l_12b4;
	case 4798ULL: goto x86_l_12be;
	case 4804ULL: goto x86_l_12c4;
	case 4812ULL: goto x86_l_12cc;
	case 4816ULL: goto x86_l_12d0;
	case 4820ULL: goto x86_l_12d4;
	case 4830ULL: goto x86_l_12de;
	case 4832ULL: goto x86_l_12e0;
	case 4835ULL: goto x86_l_12e3;
	case 4840ULL: goto x86_l_12e8;
	case 4845ULL: goto x86_l_12ed;
	case 4849ULL: goto x86_l_12f1;
	case 4854ULL: goto x86_l_12f6;
	case 4856ULL: goto x86_l_12f8;
	case 4858ULL: goto x86_l_12fa;
	case 4864ULL: goto x86_l_1300;
	case 4869ULL: goto x86_l_1305;
	case 4879ULL: goto x86_l_130f;
	case 4885ULL: goto x86_l_1315;
	case 4893ULL: goto x86_l_131d;
	case 4897ULL: goto x86_l_1321;
	case 4901ULL: goto x86_l_1325;
	case 4911ULL: goto x86_l_132f;
	case 4917ULL: goto x86_l_1335;
	case 4920ULL: goto x86_l_1338;
	case 4925ULL: goto x86_l_133d;
	case 4930ULL: goto x86_l_1342;
	case 4935ULL: goto x86_l_1347;
	default: return 0xffffffffffffffffULL;
	}
x86_l_c76:
	/* 0xc76: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c7a:
	/* 0xc7a: je     e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e0d;
	}
x86_l_c80:
	/* 0xc80: mov    ecx,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_c83:
	/* 0xc83: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_c87:
	/* 0xc87: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c8b:
	/* 0xc8b: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_c90:
	/* 0xc90: je     e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e0d;
	}
x86_l_c96:
	/* 0xc96: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c9b:
	/* 0xc9b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ca0:
	/* 0xca0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ca3:
	/* 0xca3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ca7:
	/* 0xca7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cac:
	/* 0xcac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cae:
	/* 0xcae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cb0:
	/* 0xcb0: jns    e0d <generic_sleepable_preload+0xe0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_e0d;
	}
x86_l_cb6:
	/* 0xcb6: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_cbb:
	/* 0xcbb: jmp    e0a <generic_sleepable_preload+0xe0a> */
	goto x86_l_e0a;
x86_l_cc0:
	/* 0xcc0: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_cc5:
	/* 0xcc5: jmp    e0a <generic_sleepable_preload+0xe0a> */
	goto x86_l_e0a;
x86_l_cca:
	/* 0xcca: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_cd0:
	/* 0xcd0: jmp    d2a <generic_sleepable_preload+0xd2a> */
	goto x86_l_d2a;
x86_l_cd2:
	/* 0xcd2: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_cd7:
	/* 0xcd7: jmp    e0a <generic_sleepable_preload+0xe0a> */
	goto x86_l_e0a;
x86_l_cdc:
	/* 0xcdc: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_ce2:
	/* 0xce2: jmp    d2a <generic_sleepable_preload+0xd2a> */
	goto x86_l_d2a;
x86_l_ce4:
	/* 0xce4: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_ce9:
	/* 0xce9: jmp    e0a <generic_sleepable_preload+0xe0a> */
	goto x86_l_e0a;
x86_l_cee:
	/* 0xcee: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_cf4:
	/* 0xcf4: jmp    d2a <generic_sleepable_preload+0xd2a> */
	goto x86_l_d2a;
x86_l_cf6:
	/* 0xcf6: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_cfb:
	/* 0xcfb: jmp    e0a <generic_sleepable_preload+0xe0a> */
	goto x86_l_e0a;
x86_l_d00:
	/* 0xd00: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_d06:
	/* 0xd06: jmp    d2a <generic_sleepable_preload+0xd2a> */
	goto x86_l_d2a;
x86_l_d08:
	/* 0xd08: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_d0d:
	/* 0xd0d: jmp    e0a <generic_sleepable_preload+0xe0a> */
	goto x86_l_e0a;
x86_l_d12:
	/* 0xd12: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_d18:
	/* 0xd18: jmp    d2a <generic_sleepable_preload+0xd2a> */
	goto x86_l_d2a;
x86_l_d1a:
	/* 0xd1a: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_d1f:
	/* 0xd1f: jmp    e0a <generic_sleepable_preload+0xe0a> */
	goto x86_l_e0a;
x86_l_d24:
	/* 0xd24: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_d2a:
	/* 0xd2a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d2c:
	/* 0xd2c: mov    r15d,DWORD PTR [r12+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_d31:
	/* 0xd31: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d36:
	/* 0xd36: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d3b:
	/* 0xd3b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_d3e:
	/* 0xd3e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d43:
	/* 0xd43: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_d46:
	/* 0xd46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d48:
	/* 0xd48: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_d4c:
	/* 0xd4c: jne    118 <generic_sleepable_preload+0x118> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 280ULL;
	}
x86_l_d52:
	/* 0xd52: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d56:
	/* 0xd56: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_d5e:
	/* 0xd5e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_d63:
	/* 0xd63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d65:
	/* 0xd65: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d6a:
	/* 0xd6a: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_d72:
	/* 0xd72: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d77:
	/* 0xd77: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_d7e:
	/* 0xd7e: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_d83:
	/* 0xd83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d85:
	/* 0xd85: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d88:
	/* 0xd88: je     113 <generic_sleepable_preload+0x113> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 275ULL;
	}
x86_l_d8e:
	/* 0xd8e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_d91:
	/* 0xd91: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d96:
	/* 0xd96: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d98:
	/* 0xd98: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_d9f:
	/* 0xd9f: mov    r12d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_da2:
	/* 0xda2: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_da5:
	/* 0xda5: lea    r13,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_daa:
	/* 0xdaa: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_dad:
	/* 0xdad: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_db0:
	/* 0xdb0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_db2:
	/* 0xdb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_db4:
	/* 0xdb4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_db9:
	/* 0xdb9: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_dbc:
	/* 0xdbc: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_dbf:
	/* 0xdbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dc1:
	/* 0xdc1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dc4:
	/* 0xdc4: je     113 <generic_sleepable_preload+0x113> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 275ULL;
	}
x86_l_dca:
	/* 0xdca: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_dcd:
	/* 0xdcd: je     111 <generic_sleepable_preload+0x111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 273ULL;
	}
x86_l_dd3:
	/* 0xdd3: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_dd7:
	/* 0xdd7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_ddc:
	/* 0xddc: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_de4:
	/* 0xde4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_de6:
	/* 0xde6: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_de9:
	/* 0xde9: call   dee <generic_sleepable_preload+0xdee> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_dee:
	/* 0xdee: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_df0:
	/* 0xdf0: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_df3:
	/* 0xdf3: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_df5:
	/* 0xdf5: jns    111 <generic_sleepable_preload+0x111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 273ULL;
	}
x86_l_dfb:
	/* 0xdfb: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_e00:
	/* 0xe00: jmp    111 <generic_sleepable_preload+0x111> */
	return 273ULL;
x86_l_e05:
	/* 0xe05: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_e0a:
	/* 0xe0a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e0d:
	/* 0xe0d: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_e11:
	/* 0xe11: jne    113 <generic_sleepable_preload+0x113> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 275ULL;
	}
x86_l_e17:
	/* 0xe17: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e1b:
	/* 0xe1b: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_e23:
	/* 0xe23: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_e28:
	/* 0xe28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e2a:
	/* 0xe2a: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e2f:
	/* 0xe2f: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_e37:
	/* 0xe37: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e3c:
	/* 0xe3c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_e43:
	/* 0xe43: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_e48:
	/* 0xe48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e4a:
	/* 0xe4a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e4d:
	/* 0xe4d: je     113 <generic_sleepable_preload+0x113> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 275ULL;
	}
x86_l_e53:
	/* 0xe53: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_e56:
	/* 0xe56: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e5b:
	/* 0xe5b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e5d:
	/* 0xe5d: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_e64:
	/* 0xe64: mov    r12d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_32);
x86_l_e67:
	/* 0xe67: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_e6a:
	/* 0xe6a: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e6f:
	/* 0xe6f: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_e72:
	/* 0xe72: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_e75:
	/* 0xe75: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e77:
	/* 0xe77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e79:
	/* 0xe79: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e7e:
	/* 0xe7e: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_e81:
	/* 0xe81: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_e84:
	/* 0xe84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e86:
	/* 0xe86: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e89:
	/* 0xe89: je     113 <generic_sleepable_preload+0x113> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 275ULL;
	}
x86_l_e8f:
	/* 0xe8f: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_e92:
	/* 0xe92: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_e95:
	/* 0xe95: je     eb9 <generic_sleepable_preload+0xeb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eb9;
	}
x86_l_e97:
	/* 0xe97: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e9b:
	/* 0xe9b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_ea0:
	/* 0xea0: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_ea8:
	/* 0xea8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_eaa:
	/* 0xeaa: call   eaf <generic_sleepable_preload+0xeaf> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_eaf:
	/* 0xeaf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_eb1:
	/* 0xeb1: jns    eb9 <generic_sleepable_preload+0xeb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_eb9;
	}
x86_l_eb3:
	/* 0xeb3: mov    r15d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967295ULL);
x86_l_eb9:
	/* 0xeb9: mov    DWORD PTR [r13+0x0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ebd:
	/* 0xebd: jmp    113 <generic_sleepable_preload+0x113> */
	return 275ULL;
x86_l_ec2:
	/* 0xec2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ec4:
	/* 0xec4: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_eca:
	/* 0xeca: jmp    d2c <generic_sleepable_preload+0xd2c> */
	goto x86_l_d2c;
x86_l_ecf:
	/* 0xecf: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ed2:
	/* 0xed2: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_ed7:
	/* 0xed7: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_edb:
	/* 0xedb: jne    113 <generic_sleepable_preload+0x113> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 275ULL;
	}
x86_l_ee1:
	/* 0xee1: jmp    e17 <generic_sleepable_preload+0xe17> */
	goto x86_l_e17;
x86_l_ee6:
	/* 0xee6: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_eec:
	/* 0xeec: jmp    d2a <generic_sleepable_preload+0xd2a> */
	goto x86_l_d2a;
x86_l_ef1:
	/* 0xef1: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_ef6:
	/* 0xef6: jmp    e0a <generic_sleepable_preload+0xe0a> */
	goto x86_l_e0a;
x86_l_efb:
	/* 0xefb: mov    eax,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f00:
	/* 0xf00: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_f05:
	/* 0xf05: je     1e2a <generic_sleepable_preload+0x1e2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7722ULL;
	}
x86_l_f0b:
	/* 0xf0b: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_f0d:
	/* 0xf0d: js     f42 <generic_sleepable_preload+0xf42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_f42;
	}
x86_l_f0f:
	/* 0xf0f: mov    eax,DWORD PTR [r12+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f14:
	/* 0xf14: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f17:
	/* 0xf17: jle    fca <generic_sleepable_preload+0xfca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_fca;
	}
x86_l_f1d:
	/* 0xf1d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f20:
	/* 0xf20: je     1034 <generic_sleepable_preload+0x1034> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1034;
	}
x86_l_f26:
	/* 0xf26: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_f29:
	/* 0xf29: je     103b <generic_sleepable_preload+0x103b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_103b;
	}
x86_l_f2f:
	/* 0xf2f: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f32:
	/* 0xf32: jne    104e <generic_sleepable_preload+0x104e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_104e;
	}
x86_l_f38:
	/* 0xf38: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f3d:
	/* 0xf3d: jmp    1047 <generic_sleepable_preload+0x1047> */
	goto x86_l_1047;
x86_l_f42:
	/* 0xf42: movzx  eax,BYTE PTR [r12+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_f4b:
	/* 0xf4b: movzx  ecx,WORD PTR [r12+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_f54:
	/* 0xf54: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_f5a:
	/* 0xf5a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f5c:
	/* 0xf5c: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_f5f:
	/* 0xf5f: jle    f9e <generic_sleepable_preload+0xf9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_f9e;
	}
x86_l_f61:
	/* 0xf61: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_f64:
	/* 0xf64: jle    fda <generic_sleepable_preload+0xfda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_fda;
	}
x86_l_f66:
	/* 0xf66: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_f69:
	/* 0xf69: jle    1682 <generic_sleepable_preload+0x1682> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5762ULL;
	}
x86_l_f6f:
	/* 0xf6f: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f74:
	/* 0xf74: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_f77:
	/* 0xf77: je     1696 <generic_sleepable_preload+0x1696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5782ULL;
	}
x86_l_f7d:
	/* 0xf7d: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_f82:
	/* 0xf82: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_f85:
	/* 0xf85: je     1696 <generic_sleepable_preload+0x1696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5782ULL;
	}
x86_l_f8b:
	/* 0xf8b: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_f8e:
	/* 0xf8e: jne    16a9 <generic_sleepable_preload+0x16a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5801ULL;
	}
x86_l_f94:
	/* 0xf94: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f99:
	/* 0xf99: jmp    1696 <generic_sleepable_preload+0x1696> */
	return 5782ULL;
x86_l_f9e:
	/* 0xf9e: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_fa1:
	/* 0xfa1: jg     1007 <generic_sleepable_preload+0x1007> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1007;
	}
x86_l_fa3:
	/* 0xfa3: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_fa6:
	/* 0xfa6: jg     1653 <generic_sleepable_preload+0x1653> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5715ULL;
	}
x86_l_fac:
	/* 0xfac: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_fb1:
	/* 0xfb1: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_fb3:
	/* 0xfb3: je     1696 <generic_sleepable_preload+0x1696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5782ULL;
	}
x86_l_fb9:
	/* 0xfb9: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_fbc:
	/* 0xfbc: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_fbf:
	/* 0xfbf: je     1696 <generic_sleepable_preload+0x1696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5782ULL;
	}
x86_l_fc5:
	/* 0xfc5: jmp    16a9 <generic_sleepable_preload+0x16a9> */
	return 5801ULL;
x86_l_fca:
	/* 0xfca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fcc:
	/* 0xfcc: je     1042 <generic_sleepable_preload+0x1042> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1042;
	}
x86_l_fce:
	/* 0xfce: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fd1:
	/* 0xfd1: jne    104e <generic_sleepable_preload+0x104e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_104e;
	}
x86_l_fd3:
	/* 0xfd3: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fd8:
	/* 0xfd8: jmp    1047 <generic_sleepable_preload+0x1047> */
	goto x86_l_1047;
x86_l_fda:
	/* 0xfda: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_fdd:
	/* 0xfdd: jg     163a <generic_sleepable_preload+0x163a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5690ULL;
	}
x86_l_fe3:
	/* 0xfe3: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_feb:
	/* 0xfeb: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_fee:
	/* 0xfee: je     1696 <generic_sleepable_preload+0x1696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5782ULL;
	}
x86_l_ff4:
	/* 0xff4: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ff9:
	/* 0xff9: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_ffc:
	/* 0xffc: je     1696 <generic_sleepable_preload+0x1696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5782ULL;
	}
x86_l_1002:
	/* 0x1002: jmp    16a9 <generic_sleepable_preload+0x16a9> */
	return 5801ULL;
x86_l_1007:
	/* 0x1007: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_100a:
	/* 0x100a: jg     1669 <generic_sleepable_preload+0x1669> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5737ULL;
	}
x86_l_1010:
	/* 0x1010: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1018:
	/* 0x1018: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_101b:
	/* 0x101b: je     1696 <generic_sleepable_preload+0x1696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5782ULL;
	}
x86_l_1021:
	/* 0x1021: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1026:
	/* 0x1026: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1029:
	/* 0x1029: je     1696 <generic_sleepable_preload+0x1696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5782ULL;
	}
x86_l_102f:
	/* 0x102f: jmp    16a9 <generic_sleepable_preload+0x16a9> */
	return 5801ULL;
x86_l_1034:
	/* 0x1034: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1039:
	/* 0x1039: jmp    1047 <generic_sleepable_preload+0x1047> */
	goto x86_l_1047;
x86_l_103b:
	/* 0x103b: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1040:
	/* 0x1040: jmp    1047 <generic_sleepable_preload+0x1047> */
	goto x86_l_1047;
x86_l_1042:
	/* 0x1042: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1047:
	/* 0x1047: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_104a:
	/* 0x104a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_104e:
	/* 0x104e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1050:
	/* 0x1050: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_1053:
	/* 0x1053: cmp    WORD PTR [r12+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_105a:
	/* 0x105a: je     1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7419ULL;
	}
x86_l_1060:
	/* 0x1060: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1067:
	/* 0x1067: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_106a:
	/* 0x106a: mov    eax,DWORD PTR [r12+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_106f:
	/* 0x106f: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1072:
	/* 0x1072: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1076:
	/* 0x1076: movzx  eax,WORD PTR [r12+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_107c:
	/* 0x107c: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_107e:
	/* 0x107e: je     1347 <generic_sleepable_preload+0x1347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1347;
	}
x86_l_1084:
	/* 0x1084: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1087:
	/* 0x1087: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10a9;
	}
x86_l_1089:
	/* 0x1089: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_108c:
	/* 0x108c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1091:
	/* 0x1091: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1096:
	/* 0x1096: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_109a:
	/* 0x109a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_109f:
	/* 0x109f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10a1:
	/* 0x10a1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10a3:
	/* 0x10a3: js     1630 <generic_sleepable_preload+0x1630> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5680ULL;
	}
x86_l_10a9:
	/* 0x10a9: cmp    WORD PTR [r12+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_10b0:
	/* 0x10b0: je     1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7419ULL;
	}
x86_l_10b6:
	/* 0x10b6: mov    ecx,DWORD PTR [r12+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_10bb:
	/* 0x10bb: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_10bf:
	/* 0x10bf: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10c3:
	/* 0x10c3: cmp    WORD PTR [r12+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_10ca:
	/* 0x10ca: je     10ec <generic_sleepable_preload+0x10ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10ec;
	}
x86_l_10cc:
	/* 0x10cc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_10cf:
	/* 0x10cf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_10d4:
	/* 0x10d4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_10d9:
	/* 0x10d9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10dd:
	/* 0x10dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10e2:
	/* 0x10e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10e4:
	/* 0x10e4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10e6:
	/* 0x10e6: js     1c9e <generic_sleepable_preload+0x1c9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7326ULL;
	}
x86_l_10ec:
	/* 0x10ec: cmp    WORD PTR [r12+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_10f6:
	/* 0x10f6: je     1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7419ULL;
	}
x86_l_10fc:
	/* 0x10fc: mov    ecx,DWORD PTR [r12+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1104:
	/* 0x1104: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1108:
	/* 0x1108: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_110c:
	/* 0x110c: cmp    WORD PTR [r12+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1116:
	/* 0x1116: je     1138 <generic_sleepable_preload+0x1138> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1138;
	}
x86_l_1118:
	/* 0x1118: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_111b:
	/* 0x111b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1120:
	/* 0x1120: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1125:
	/* 0x1125: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1129:
	/* 0x1129: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_112e:
	/* 0x112e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1130:
	/* 0x1130: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1132:
	/* 0x1132: js     1caf <generic_sleepable_preload+0x1caf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7343ULL;
	}
x86_l_1138:
	/* 0x1138: cmp    WORD PTR [r12+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1142:
	/* 0x1142: je     1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7419ULL;
	}
x86_l_1148:
	/* 0x1148: mov    ecx,DWORD PTR [r12+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1150:
	/* 0x1150: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1154:
	/* 0x1154: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1158:
	/* 0x1158: cmp    WORD PTR [r12+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1162:
	/* 0x1162: je     1184 <generic_sleepable_preload+0x1184> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1184;
	}
x86_l_1164:
	/* 0x1164: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1167:
	/* 0x1167: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_116c:
	/* 0x116c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1171:
	/* 0x1171: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1175:
	/* 0x1175: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_117a:
	/* 0x117a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_117c:
	/* 0x117c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_117e:
	/* 0x117e: js     1cc0 <generic_sleepable_preload+0x1cc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7360ULL;
	}
x86_l_1184:
	/* 0x1184: cmp    WORD PTR [r12+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_118e:
	/* 0x118e: je     1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7419ULL;
	}
x86_l_1194:
	/* 0x1194: mov    ecx,DWORD PTR [r12+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_119c:
	/* 0x119c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_11a0:
	/* 0x11a0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11a4:
	/* 0x11a4: cmp    WORD PTR [r12+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_11ae:
	/* 0x11ae: je     11d0 <generic_sleepable_preload+0x11d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d0;
	}
x86_l_11b0:
	/* 0x11b0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_11b3:
	/* 0x11b3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_11b8:
	/* 0x11b8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_11bd:
	/* 0x11bd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11c1:
	/* 0x11c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11c6:
	/* 0x11c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11c8:
	/* 0x11c8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11ca:
	/* 0x11ca: js     1cd1 <generic_sleepable_preload+0x1cd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7377ULL;
	}
x86_l_11d0:
	/* 0x11d0: cmp    WORD PTR [r12+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_11da:
	/* 0x11da: je     1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7419ULL;
	}
x86_l_11e0:
	/* 0x11e0: mov    ecx,DWORD PTR [r12+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_11e8:
	/* 0x11e8: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_11ec:
	/* 0x11ec: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11f0:
	/* 0x11f0: cmp    WORD PTR [r12+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_11fa:
	/* 0x11fa: je     121c <generic_sleepable_preload+0x121c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_121c;
	}
x86_l_11fc:
	/* 0x11fc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_11ff:
	/* 0x11ff: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1204:
	/* 0x1204: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1209:
	/* 0x1209: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_120d:
	/* 0x120d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1212:
	/* 0x1212: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1214:
	/* 0x1214: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1216:
	/* 0x1216: js     1ce2 <generic_sleepable_preload+0x1ce2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7394ULL;
	}
x86_l_121c:
	/* 0x121c: cmp    WORD PTR [r12+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1226:
	/* 0x1226: je     1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7419ULL;
	}
x86_l_122c:
	/* 0x122c: mov    ecx,DWORD PTR [r12+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1234:
	/* 0x1234: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1238:
	/* 0x1238: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_123c:
	/* 0x123c: cmp    WORD PTR [r12+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1246:
	/* 0x1246: je     1268 <generic_sleepable_preload+0x1268> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1268;
	}
x86_l_1248:
	/* 0x1248: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_124b:
	/* 0x124b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1250:
	/* 0x1250: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1255:
	/* 0x1255: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
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
	/* 0x1262: js     1cf3 <generic_sleepable_preload+0x1cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7411ULL;
	}
x86_l_1268:
	/* 0x1268: cmp    WORD PTR [r12+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1272:
	/* 0x1272: je     1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7419ULL;
	}
x86_l_1278:
	/* 0x1278: mov    ecx,DWORD PTR [r12+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1280:
	/* 0x1280: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1284:
	/* 0x1284: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1288:
	/* 0x1288: cmp    WORD PTR [r12+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1292:
	/* 0x1292: je     12b4 <generic_sleepable_preload+0x12b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12b4;
	}
x86_l_1294:
	/* 0x1294: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1297:
	/* 0x1297: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_129c:
	/* 0x129c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_12a1:
	/* 0x12a1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12a5:
	/* 0x12a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12aa:
	/* 0x12aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12ac:
	/* 0x12ac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12ae:
	/* 0x12ae: js     5bcd <generic_sleepable_preload+0x5bcd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23501ULL;
	}
x86_l_12b4:
	/* 0x12b4: cmp    WORD PTR [r12+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_12be:
	/* 0x12be: je     1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7419ULL;
	}
x86_l_12c4:
	/* 0x12c4: mov    ecx,DWORD PTR [r12+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_12cc:
	/* 0x12cc: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_12d0:
	/* 0x12d0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12d4:
	/* 0x12d4: cmp    WORD PTR [r12+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_12de:
	/* 0x12de: je     1300 <generic_sleepable_preload+0x1300> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1300;
	}
x86_l_12e0:
	/* 0x12e0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_12e3:
	/* 0x12e3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_12e8:
	/* 0x12e8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_12ed:
	/* 0x12ed: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12f1:
	/* 0x12f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12f6:
	/* 0x12f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12f8:
	/* 0x12f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12fa:
	/* 0x12fa: js     5cb3 <generic_sleepable_preload+0x5cb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23731ULL;
	}
x86_l_1300:
	/* 0x1300: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1305:
	/* 0x1305: cmp    WORD PTR [r12+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_130f:
	/* 0x130f: je     1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7419ULL;
	}
x86_l_1315:
	/* 0x1315: mov    ecx,DWORD PTR [r12+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_131d:
	/* 0x131d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1321:
	/* 0x1321: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1325:
	/* 0x1325: cmp    WORD PTR [r12+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_132f:
	/* 0x132f: je     1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7419ULL;
	}
x86_l_1335:
	/* 0x1335: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1338:
	/* 0x1338: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_133d:
	/* 0x133d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1342:
	/* 0x1342: jmp    1613 <generic_sleepable_preload+0x1613> */
	return 5651ULL;
x86_l_1347:
	/* 0x1347: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
	return 4938ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4938ULL: goto x86_l_134a;
	case 4940ULL: goto x86_l_134c;
	case 4943ULL: goto x86_l_134f;
	case 4948ULL: goto x86_l_1354;
	case 4953ULL: goto x86_l_1359;
	case 4957ULL: goto x86_l_135d;
	case 4962ULL: goto x86_l_1362;
	case 4964ULL: goto x86_l_1364;
	case 4966ULL: goto x86_l_1366;
	case 4972ULL: goto x86_l_136c;
	case 4979ULL: goto x86_l_1373;
	case 4985ULL: goto x86_l_1379;
	case 4990ULL: goto x86_l_137e;
	case 4994ULL: goto x86_l_1382;
	case 4998ULL: goto x86_l_1386;
	case 5005ULL: goto x86_l_138d;
	case 5007ULL: goto x86_l_138f;
	case 5010ULL: goto x86_l_1392;
	case 5015ULL: goto x86_l_1397;
	case 5020ULL: goto x86_l_139c;
	case 5024ULL: goto x86_l_13a0;
	case 5029ULL: goto x86_l_13a5;
	case 5031ULL: goto x86_l_13a7;
	case 5033ULL: goto x86_l_13a9;
	case 5039ULL: goto x86_l_13af;
	case 5049ULL: goto x86_l_13b9;
	case 5055ULL: goto x86_l_13bf;
	case 5063ULL: goto x86_l_13c7;
	case 5067ULL: goto x86_l_13cb;
	case 5071ULL: goto x86_l_13cf;
	case 5081ULL: goto x86_l_13d9;
	case 5083ULL: goto x86_l_13db;
	case 5086ULL: goto x86_l_13de;
	case 5091ULL: goto x86_l_13e3;
	case 5096ULL: goto x86_l_13e8;
	case 5100ULL: goto x86_l_13ec;
	case 5105ULL: goto x86_l_13f1;
	case 5107ULL: goto x86_l_13f3;
	case 5109ULL: goto x86_l_13f5;
	case 5115ULL: goto x86_l_13fb;
	case 5125ULL: goto x86_l_1405;
	case 5131ULL: goto x86_l_140b;
	case 5139ULL: goto x86_l_1413;
	case 5143ULL: goto x86_l_1417;
	case 5147ULL: goto x86_l_141b;
	case 5157ULL: goto x86_l_1425;
	case 5159ULL: goto x86_l_1427;
	case 5162ULL: goto x86_l_142a;
	case 5167ULL: goto x86_l_142f;
	case 5172ULL: goto x86_l_1434;
	case 5176ULL: goto x86_l_1438;
	case 5181ULL: goto x86_l_143d;
	case 5183ULL: goto x86_l_143f;
	case 5185ULL: goto x86_l_1441;
	case 5191ULL: goto x86_l_1447;
	case 5201ULL: goto x86_l_1451;
	case 5207ULL: goto x86_l_1457;
	case 5215ULL: goto x86_l_145f;
	case 5219ULL: goto x86_l_1463;
	case 5223ULL: goto x86_l_1467;
	case 5233ULL: goto x86_l_1471;
	case 5235ULL: goto x86_l_1473;
	case 5238ULL: goto x86_l_1476;
	case 5243ULL: goto x86_l_147b;
	case 5248ULL: goto x86_l_1480;
	case 5252ULL: goto x86_l_1484;
	case 5257ULL: goto x86_l_1489;
	case 5259ULL: goto x86_l_148b;
	case 5261ULL: goto x86_l_148d;
	case 5267ULL: goto x86_l_1493;
	case 5277ULL: goto x86_l_149d;
	case 5283ULL: goto x86_l_14a3;
	case 5291ULL: goto x86_l_14ab;
	case 5295ULL: goto x86_l_14af;
	case 5299ULL: goto x86_l_14b3;
	case 5309ULL: goto x86_l_14bd;
	case 5311ULL: goto x86_l_14bf;
	case 5314ULL: goto x86_l_14c2;
	case 5319ULL: goto x86_l_14c7;
	case 5324ULL: goto x86_l_14cc;
	case 5328ULL: goto x86_l_14d0;
	case 5333ULL: goto x86_l_14d5;
	case 5335ULL: goto x86_l_14d7;
	case 5337ULL: goto x86_l_14d9;
	case 5343ULL: goto x86_l_14df;
	case 5353ULL: goto x86_l_14e9;
	case 5359ULL: goto x86_l_14ef;
	case 5367ULL: goto x86_l_14f7;
	case 5371ULL: goto x86_l_14fb;
	case 5375ULL: goto x86_l_14ff;
	case 5385ULL: goto x86_l_1509;
	case 5387ULL: goto x86_l_150b;
	case 5390ULL: goto x86_l_150e;
	case 5395ULL: goto x86_l_1513;
	case 5400ULL: goto x86_l_1518;
	case 5404ULL: goto x86_l_151c;
	case 5409ULL: goto x86_l_1521;
	case 5411ULL: goto x86_l_1523;
	case 5413ULL: goto x86_l_1525;
	case 5419ULL: goto x86_l_152b;
	case 5429ULL: goto x86_l_1535;
	case 5435ULL: goto x86_l_153b;
	case 5438ULL: goto x86_l_153e;
	case 5446ULL: goto x86_l_1546;
	case 5450ULL: goto x86_l_154a;
	case 5454ULL: goto x86_l_154e;
	case 5464ULL: goto x86_l_1558;
	case 5466ULL: goto x86_l_155a;
	case 5469ULL: goto x86_l_155d;
	case 5474ULL: goto x86_l_1562;
	case 5479ULL: goto x86_l_1567;
	case 5483ULL: goto x86_l_156b;
	case 5488ULL: goto x86_l_1570;
	case 5490ULL: goto x86_l_1572;
	case 5492ULL: goto x86_l_1574;
	case 5498ULL: goto x86_l_157a;
	case 5503ULL: goto x86_l_157f;
	case 5513ULL: goto x86_l_1589;
	case 5516ULL: goto x86_l_158c;
	case 5522ULL: goto x86_l_1592;
	case 5530ULL: goto x86_l_159a;
	case 5534ULL: goto x86_l_159e;
	case 5538ULL: goto x86_l_15a2;
	case 5548ULL: goto x86_l_15ac;
	case 5550ULL: goto x86_l_15ae;
	case 5553ULL: goto x86_l_15b1;
	case 5558ULL: goto x86_l_15b6;
	case 5563ULL: goto x86_l_15bb;
	case 5567ULL: goto x86_l_15bf;
	case 5572ULL: goto x86_l_15c4;
	case 5574ULL: goto x86_l_15c6;
	case 5576ULL: goto x86_l_15c8;
	case 5582ULL: goto x86_l_15ce;
	case 5587ULL: goto x86_l_15d3;
	case 5597ULL: goto x86_l_15dd;
	case 5600ULL: goto x86_l_15e0;
	case 5606ULL: goto x86_l_15e6;
	case 5614ULL: goto x86_l_15ee;
	case 5618ULL: goto x86_l_15f2;
	case 5622ULL: goto x86_l_15f6;
	case 5632ULL: goto x86_l_1600;
	case 5638ULL: goto x86_l_1606;
	case 5641ULL: goto x86_l_1609;
	case 5646ULL: goto x86_l_160e;
	case 5651ULL: goto x86_l_1613;
	case 5655ULL: goto x86_l_1617;
	case 5660ULL: goto x86_l_161c;
	case 5662ULL: goto x86_l_161e;
	case 5664ULL: goto x86_l_1620;
	case 5670ULL: goto x86_l_1626;
	case 5675ULL: goto x86_l_162b;
	case 5680ULL: goto x86_l_1630;
	case 5685ULL: goto x86_l_1635;
	case 5690ULL: goto x86_l_163a;
	case 5698ULL: goto x86_l_1642;
	case 5701ULL: goto x86_l_1645;
	case 5703ULL: goto x86_l_1647;
	case 5708ULL: goto x86_l_164c;
	case 5711ULL: goto x86_l_164f;
	case 5713ULL: goto x86_l_1651;
	case 5715ULL: goto x86_l_1653;
	case 5720ULL: goto x86_l_1658;
	case 5723ULL: goto x86_l_165b;
	case 5725ULL: goto x86_l_165d;
	case 5730ULL: goto x86_l_1662;
	case 5733ULL: goto x86_l_1665;
	case 5735ULL: goto x86_l_1667;
	case 5737ULL: goto x86_l_1669;
	case 5745ULL: goto x86_l_1671;
	case 5748ULL: goto x86_l_1674;
	case 5750ULL: goto x86_l_1676;
	case 5755ULL: goto x86_l_167b;
	case 5758ULL: goto x86_l_167e;
	case 5760ULL: goto x86_l_1680;
	case 5762ULL: goto x86_l_1682;
	case 5767ULL: goto x86_l_1687;
	case 5770ULL: goto x86_l_168a;
	case 5772ULL: goto x86_l_168c;
	case 5777ULL: goto x86_l_1691;
	case 5780ULL: goto x86_l_1694;
	case 5782ULL: goto x86_l_1696;
	case 5785ULL: goto x86_l_1699;
	case 5787ULL: goto x86_l_169b;
	case 5789ULL: goto x86_l_169d;
	case 5794ULL: goto x86_l_16a2;
	case 5796ULL: goto x86_l_16a4;
	case 5801ULL: goto x86_l_16a9;
	case 5805ULL: goto x86_l_16ad;
	case 5810ULL: goto x86_l_16b2;
	case 5812ULL: goto x86_l_16b4;
	case 5815ULL: goto x86_l_16b7;
	case 5822ULL: goto x86_l_16be;
	case 5828ULL: goto x86_l_16c4;
	case 5835ULL: goto x86_l_16cb;
	case 5838ULL: goto x86_l_16ce;
	case 5843ULL: goto x86_l_16d3;
	case 5846ULL: goto x86_l_16d6;
	case 5850ULL: goto x86_l_16da;
	case 5856ULL: goto x86_l_16e0;
	case 5858ULL: goto x86_l_16e2;
	case 5864ULL: goto x86_l_16e8;
	case 5867ULL: goto x86_l_16eb;
	case 5869ULL: goto x86_l_16ed;
	case 5872ULL: goto x86_l_16f0;
	case 5877ULL: goto x86_l_16f5;
	case 5882ULL: goto x86_l_16fa;
	case 5886ULL: goto x86_l_16fe;
	case 5891ULL: goto x86_l_1703;
	case 5893ULL: goto x86_l_1705;
	case 5895ULL: goto x86_l_1707;
	case 5901ULL: goto x86_l_170d;
	case 5908ULL: goto x86_l_1714;
	case 5914ULL: goto x86_l_171a;
	case 5919ULL: goto x86_l_171f;
	case 5923ULL: goto x86_l_1723;
	case 5927ULL: goto x86_l_1727;
	case 5934ULL: goto x86_l_172e;
	case 5936ULL: goto x86_l_1730;
	case 5939ULL: goto x86_l_1733;
	case 5944ULL: goto x86_l_1738;
	case 5949ULL: goto x86_l_173d;
	case 5953ULL: goto x86_l_1741;
	case 5958ULL: goto x86_l_1746;
	case 5960ULL: goto x86_l_1748;
	case 5962ULL: goto x86_l_174a;
	case 5968ULL: goto x86_l_1750;
	case 5978ULL: goto x86_l_175a;
	case 5984ULL: goto x86_l_1760;
	case 5992ULL: goto x86_l_1768;
	case 5996ULL: goto x86_l_176c;
	case 6000ULL: goto x86_l_1770;
	case 6010ULL: goto x86_l_177a;
	case 6012ULL: goto x86_l_177c;
	case 6015ULL: goto x86_l_177f;
	case 6020ULL: goto x86_l_1784;
	case 6025ULL: goto x86_l_1789;
	case 6029ULL: goto x86_l_178d;
	case 6034ULL: goto x86_l_1792;
	case 6036ULL: goto x86_l_1794;
	case 6038ULL: goto x86_l_1796;
	case 6044ULL: goto x86_l_179c;
	case 6054ULL: goto x86_l_17a6;
	case 6060ULL: goto x86_l_17ac;
	case 6068ULL: goto x86_l_17b4;
	case 6072ULL: goto x86_l_17b8;
	case 6076ULL: goto x86_l_17bc;
	case 6086ULL: goto x86_l_17c6;
	case 6088ULL: goto x86_l_17c8;
	case 6091ULL: goto x86_l_17cb;
	case 6096ULL: goto x86_l_17d0;
	case 6101ULL: goto x86_l_17d5;
	case 6105ULL: goto x86_l_17d9;
	case 6110ULL: goto x86_l_17de;
	case 6112ULL: goto x86_l_17e0;
	case 6114ULL: goto x86_l_17e2;
	case 6120ULL: goto x86_l_17e8;
	case 6130ULL: goto x86_l_17f2;
	case 6136ULL: goto x86_l_17f8;
	case 6144ULL: goto x86_l_1800;
	case 6148ULL: goto x86_l_1804;
	case 6152ULL: goto x86_l_1808;
	case 6162ULL: goto x86_l_1812;
	case 6164ULL: goto x86_l_1814;
	case 6167ULL: goto x86_l_1817;
	case 6172ULL: goto x86_l_181c;
	case 6177ULL: goto x86_l_1821;
	case 6181ULL: goto x86_l_1825;
	case 6186ULL: goto x86_l_182a;
	case 6188ULL: goto x86_l_182c;
	case 6190ULL: goto x86_l_182e;
	case 6196ULL: goto x86_l_1834;
	case 6206ULL: goto x86_l_183e;
	case 6212ULL: goto x86_l_1844;
	case 6220ULL: goto x86_l_184c;
	case 6224ULL: goto x86_l_1850;
	case 6228ULL: goto x86_l_1854;
	case 6238ULL: goto x86_l_185e;
	case 6240ULL: goto x86_l_1860;
	case 6243ULL: goto x86_l_1863;
	case 6248ULL: goto x86_l_1868;
	case 6253ULL: goto x86_l_186d;
	case 6257ULL: goto x86_l_1871;
	case 6262ULL: goto x86_l_1876;
	case 6264ULL: goto x86_l_1878;
	case 6266ULL: goto x86_l_187a;
	case 6272ULL: goto x86_l_1880;
	case 6282ULL: goto x86_l_188a;
	case 6288ULL: goto x86_l_1890;
	case 6296ULL: goto x86_l_1898;
	case 6300ULL: goto x86_l_189c;
	case 6304ULL: goto x86_l_18a0;
	case 6314ULL: goto x86_l_18aa;
	case 6316ULL: goto x86_l_18ac;
	case 6319ULL: goto x86_l_18af;
	case 6324ULL: goto x86_l_18b4;
	case 6329ULL: goto x86_l_18b9;
	case 6333ULL: goto x86_l_18bd;
	case 6338ULL: goto x86_l_18c2;
	case 6340ULL: goto x86_l_18c4;
	case 6342ULL: goto x86_l_18c6;
	case 6348ULL: goto x86_l_18cc;
	case 6358ULL: goto x86_l_18d6;
	case 6364ULL: goto x86_l_18dc;
	case 6372ULL: goto x86_l_18e4;
	case 6376ULL: goto x86_l_18e8;
	case 6380ULL: goto x86_l_18ec;
	case 6390ULL: goto x86_l_18f6;
	case 6392ULL: goto x86_l_18f8;
	case 6395ULL: goto x86_l_18fb;
	case 6400ULL: goto x86_l_1900;
	case 6405ULL: goto x86_l_1905;
	case 6409ULL: goto x86_l_1909;
	case 6414ULL: goto x86_l_190e;
	case 6416ULL: goto x86_l_1910;
	case 6418ULL: goto x86_l_1912;
	case 6424ULL: goto x86_l_1918;
	case 6434ULL: goto x86_l_1922;
	case 6440ULL: goto x86_l_1928;
	case 6448ULL: goto x86_l_1930;
	case 6452ULL: goto x86_l_1934;
	case 6456ULL: goto x86_l_1938;
	case 6466ULL: goto x86_l_1942;
	case 6468ULL: goto x86_l_1944;
	case 6471ULL: goto x86_l_1947;
	case 6476ULL: goto x86_l_194c;
	case 6481ULL: goto x86_l_1951;
	case 6485ULL: goto x86_l_1955;
	case 6490ULL: goto x86_l_195a;
	case 6492ULL: goto x86_l_195c;
	case 6494ULL: goto x86_l_195e;
	case 6500ULL: goto x86_l_1964;
	case 6505ULL: goto x86_l_1969;
	case 6515ULL: goto x86_l_1973;
	case 6521ULL: goto x86_l_1979;
	case 6529ULL: goto x86_l_1981;
	case 6533ULL: goto x86_l_1985;
	case 6537ULL: goto x86_l_1989;
	case 6547ULL: goto x86_l_1993;
	case 6553ULL: goto x86_l_1999;
	case 6556ULL: goto x86_l_199c;
	case 6561ULL: goto x86_l_19a1;
	case 6566ULL: goto x86_l_19a6;
	case 6571ULL: goto x86_l_19ab;
	case 6574ULL: goto x86_l_19ae;
	case 6576ULL: goto x86_l_19b0;
	case 6579ULL: goto x86_l_19b3;
	case 6584ULL: goto x86_l_19b8;
	case 6589ULL: goto x86_l_19bd;
	case 6593ULL: goto x86_l_19c1;
	case 6598ULL: goto x86_l_19c6;
	case 6600ULL: goto x86_l_19c8;
	case 6602ULL: goto x86_l_19ca;
	case 6608ULL: goto x86_l_19d0;
	case 6615ULL: goto x86_l_19d7;
	case 6621ULL: goto x86_l_19dd;
	case 6626ULL: goto x86_l_19e2;
	case 6630ULL: goto x86_l_19e6;
	case 6634ULL: goto x86_l_19ea;
	case 6641ULL: goto x86_l_19f1;
	case 6643ULL: goto x86_l_19f3;
	case 6646ULL: goto x86_l_19f6;
	case 6651ULL: goto x86_l_19fb;
	case 6656ULL: goto x86_l_1a00;
	case 6660ULL: goto x86_l_1a04;
	case 6665ULL: goto x86_l_1a09;
	case 6667ULL: goto x86_l_1a0b;
	case 6669ULL: goto x86_l_1a0d;
	case 6675ULL: goto x86_l_1a13;
	case 6685ULL: goto x86_l_1a1d;
	case 6691ULL: goto x86_l_1a23;
	case 6699ULL: goto x86_l_1a2b;
	case 6703ULL: goto x86_l_1a2f;
	case 6707ULL: goto x86_l_1a33;
	case 6717ULL: goto x86_l_1a3d;
	case 6719ULL: goto x86_l_1a3f;
	case 6722ULL: goto x86_l_1a42;
	case 6727ULL: goto x86_l_1a47;
	case 6732ULL: goto x86_l_1a4c;
	case 6736ULL: goto x86_l_1a50;
	case 6741ULL: goto x86_l_1a55;
	case 6743ULL: goto x86_l_1a57;
	case 6745ULL: goto x86_l_1a59;
	case 6751ULL: goto x86_l_1a5f;
	case 6761ULL: goto x86_l_1a69;
	default: return 0xffffffffffffffffULL;
	}
x86_l_134a:
	/* 0x134a: je     136c <generic_sleepable_preload+0x136c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_136c;
	}
x86_l_134c:
	/* 0x134c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_134f:
	/* 0x134f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1354:
	/* 0x1354: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1359:
	/* 0x1359: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_135d:
	/* 0x135d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1362:
	/* 0x1362: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1364:
	/* 0x1364: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1366:
	/* 0x1366: js     1630 <generic_sleepable_preload+0x1630> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1630;
	}
x86_l_136c:
	/* 0x136c: cmp    WORD PTR [r12+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_1373:
	/* 0x1373: je     1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7419ULL;
	}
x86_l_1379:
	/* 0x1379: mov    ecx,DWORD PTR [r12+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_137e:
	/* 0x137e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1382:
	/* 0x1382: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1386:
	/* 0x1386: cmp    WORD PTR [r12+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_138d:
	/* 0x138d: je     13af <generic_sleepable_preload+0x13af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13af;
	}
x86_l_138f:
	/* 0x138f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1392:
	/* 0x1392: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1397:
	/* 0x1397: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_139c:
	/* 0x139c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13a0:
	/* 0x13a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13a5:
	/* 0x13a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a7:
	/* 0x13a7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13a9:
	/* 0x13a9: js     1c9e <generic_sleepable_preload+0x1c9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7326ULL;
	}
x86_l_13af:
	/* 0x13af: cmp    WORD PTR [r12+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_13b9:
	/* 0x13b9: je     1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7419ULL;
	}
x86_l_13bf:
	/* 0x13bf: mov    ecx,DWORD PTR [r12+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_13c7:
	/* 0x13c7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_13cb:
	/* 0x13cb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13cf:
	/* 0x13cf: cmp    WORD PTR [r12+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_13d9:
	/* 0x13d9: je     13fb <generic_sleepable_preload+0x13fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13fb;
	}
x86_l_13db:
	/* 0x13db: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_13de:
	/* 0x13de: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_13e3:
	/* 0x13e3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_13e8:
	/* 0x13e8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13ec:
	/* 0x13ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13f1:
	/* 0x13f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f3:
	/* 0x13f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13f5:
	/* 0x13f5: js     1caf <generic_sleepable_preload+0x1caf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7343ULL;
	}
x86_l_13fb:
	/* 0x13fb: cmp    WORD PTR [r12+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1405:
	/* 0x1405: je     1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7419ULL;
	}
x86_l_140b:
	/* 0x140b: mov    ecx,DWORD PTR [r12+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1413:
	/* 0x1413: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1417:
	/* 0x1417: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_141b:
	/* 0x141b: cmp    WORD PTR [r12+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1425:
	/* 0x1425: je     1447 <generic_sleepable_preload+0x1447> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1447;
	}
x86_l_1427:
	/* 0x1427: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_142a:
	/* 0x142a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_142f:
	/* 0x142f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1434:
	/* 0x1434: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1438:
	/* 0x1438: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_143d:
	/* 0x143d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_143f:
	/* 0x143f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1441:
	/* 0x1441: js     1cc0 <generic_sleepable_preload+0x1cc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7360ULL;
	}
x86_l_1447:
	/* 0x1447: cmp    WORD PTR [r12+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1451:
	/* 0x1451: je     1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7419ULL;
	}
x86_l_1457:
	/* 0x1457: mov    ecx,DWORD PTR [r12+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_145f:
	/* 0x145f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1463:
	/* 0x1463: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1467:
	/* 0x1467: cmp    WORD PTR [r12+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1471:
	/* 0x1471: je     1493 <generic_sleepable_preload+0x1493> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1493;
	}
x86_l_1473:
	/* 0x1473: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1476:
	/* 0x1476: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_147b:
	/* 0x147b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1480:
	/* 0x1480: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1484:
	/* 0x1484: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1489:
	/* 0x1489: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_148b:
	/* 0x148b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_148d:
	/* 0x148d: js     1cd1 <generic_sleepable_preload+0x1cd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7377ULL;
	}
x86_l_1493:
	/* 0x1493: cmp    WORD PTR [r12+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_149d:
	/* 0x149d: je     1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7419ULL;
	}
x86_l_14a3:
	/* 0x14a3: mov    ecx,DWORD PTR [r12+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_14ab:
	/* 0x14ab: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_14af:
	/* 0x14af: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14b3:
	/* 0x14b3: cmp    WORD PTR [r12+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_14bd:
	/* 0x14bd: je     14df <generic_sleepable_preload+0x14df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14df;
	}
x86_l_14bf:
	/* 0x14bf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_14c2:
	/* 0x14c2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_14c7:
	/* 0x14c7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_14cc:
	/* 0x14cc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14d0:
	/* 0x14d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14d5:
	/* 0x14d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d7:
	/* 0x14d7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14d9:
	/* 0x14d9: js     1ce2 <generic_sleepable_preload+0x1ce2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7394ULL;
	}
x86_l_14df:
	/* 0x14df: cmp    WORD PTR [r12+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_14e9:
	/* 0x14e9: je     1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7419ULL;
	}
x86_l_14ef:
	/* 0x14ef: mov    ecx,DWORD PTR [r12+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_14f7:
	/* 0x14f7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_14fb:
	/* 0x14fb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14ff:
	/* 0x14ff: cmp    WORD PTR [r12+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1509:
	/* 0x1509: je     152b <generic_sleepable_preload+0x152b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_152b;
	}
x86_l_150b:
	/* 0x150b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_150e:
	/* 0x150e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1513:
	/* 0x1513: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1518:
	/* 0x1518: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_151c:
	/* 0x151c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1521:
	/* 0x1521: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1523:
	/* 0x1523: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1525:
	/* 0x1525: js     1cf3 <generic_sleepable_preload+0x1cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7411ULL;
	}
x86_l_152b:
	/* 0x152b: cmp    WORD PTR [r12+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1535:
	/* 0x1535: je     1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7419ULL;
	}
x86_l_153b:
	/* 0x153b: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_153e:
	/* 0x153e: mov    ecx,DWORD PTR [r12+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1546:
	/* 0x1546: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_154a:
	/* 0x154a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_154e:
	/* 0x154e: cmp    WORD PTR [r12+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1558:
	/* 0x1558: je     157a <generic_sleepable_preload+0x157a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_157a;
	}
x86_l_155a:
	/* 0x155a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_155d:
	/* 0x155d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1562:
	/* 0x1562: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1567:
	/* 0x1567: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_156b:
	/* 0x156b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1570:
	/* 0x1570: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1572:
	/* 0x1572: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1574:
	/* 0x1574: js     5c4b <generic_sleepable_preload+0x5c4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23627ULL;
	}
x86_l_157a:
	/* 0x157a: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_157f:
	/* 0x157f: cmp    WORD PTR [r12+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1589:
	/* 0x1589: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_158c:
	/* 0x158c: je     1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7419ULL;
	}
x86_l_1592:
	/* 0x1592: mov    ecx,DWORD PTR [r12+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_159a:
	/* 0x159a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_159e:
	/* 0x159e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15a2:
	/* 0x15a2: cmp    WORD PTR [r12+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_15ac:
	/* 0x15ac: je     15ce <generic_sleepable_preload+0x15ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15ce;
	}
x86_l_15ae:
	/* 0x15ae: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_15b1:
	/* 0x15b1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_15b6:
	/* 0x15b6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_15bb:
	/* 0x15bb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15bf:
	/* 0x15bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15c4:
	/* 0x15c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15c6:
	/* 0x15c6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15c8:
	/* 0x15c8: js     5d43 <generic_sleepable_preload+0x5d43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23875ULL;
	}
x86_l_15ce:
	/* 0x15ce: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15d3:
	/* 0x15d3: cmp    WORD PTR [r12+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_15dd:
	/* 0x15dd: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_15e0:
	/* 0x15e0: je     1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7419ULL;
	}
x86_l_15e6:
	/* 0x15e6: mov    ecx,DWORD PTR [r12+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_15ee:
	/* 0x15ee: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_15f2:
	/* 0x15f2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15f6:
	/* 0x15f6: cmp    WORD PTR [r12+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1600:
	/* 0x1600: je     1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7419ULL;
	}
x86_l_1606:
	/* 0x1606: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1609:
	/* 0x1609: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_160e:
	/* 0x160e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1613:
	/* 0x1613: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1617:
	/* 0x1617: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_161c:
	/* 0x161c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_161e:
	/* 0x161e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1620:
	/* 0x1620: jns    1cfb <generic_sleepable_preload+0x1cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 7419ULL;
	}
x86_l_1626:
	/* 0x1626: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_162b:
	/* 0x162b: jmp    1cf8 <generic_sleepable_preload+0x1cf8> */
	return 7416ULL;
x86_l_1630:
	/* 0x1630: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_1635:
	/* 0x1635: jmp    1cf8 <generic_sleepable_preload+0x1cf8> */
	return 7416ULL;
x86_l_163a:
	/* 0x163a: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1642:
	/* 0x1642: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1645:
	/* 0x1645: je     1696 <generic_sleepable_preload+0x1696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1696;
	}
x86_l_1647:
	/* 0x1647: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_164c:
	/* 0x164c: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_164f:
	/* 0x164f: je     1696 <generic_sleepable_preload+0x1696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1696;
	}
x86_l_1651:
	/* 0x1651: jmp    16a9 <generic_sleepable_preload+0x16a9> */
	goto x86_l_16a9;
x86_l_1653:
	/* 0x1653: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1658:
	/* 0x1658: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_165b:
	/* 0x165b: je     1696 <generic_sleepable_preload+0x1696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1696;
	}
x86_l_165d:
	/* 0x165d: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1662:
	/* 0x1662: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1665:
	/* 0x1665: je     1696 <generic_sleepable_preload+0x1696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1696;
	}
x86_l_1667:
	/* 0x1667: jmp    16a9 <generic_sleepable_preload+0x16a9> */
	goto x86_l_16a9;
x86_l_1669:
	/* 0x1669: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1671:
	/* 0x1671: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_1674:
	/* 0x1674: je     1696 <generic_sleepable_preload+0x1696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1696;
	}
x86_l_1676:
	/* 0x1676: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_167b:
	/* 0x167b: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_167e:
	/* 0x167e: je     1696 <generic_sleepable_preload+0x1696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1696;
	}
x86_l_1680:
	/* 0x1680: jmp    16a9 <generic_sleepable_preload+0x16a9> */
	goto x86_l_16a9;
x86_l_1682:
	/* 0x1682: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1687:
	/* 0x1687: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_168a:
	/* 0x168a: je     1696 <generic_sleepable_preload+0x1696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1696;
	}
x86_l_168c:
	/* 0x168c: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1691:
	/* 0x1691: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1694:
	/* 0x1694: jne    16a9 <generic_sleepable_preload+0x16a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16a9;
	}
x86_l_1696:
	/* 0x1696: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_1699:
	/* 0x1699: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_169b:
	/* 0x169b: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_169d:
	/* 0x169d: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_16a2:
	/* 0x16a2: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_16a4:
	/* 0x16a4: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_16a9:
	/* 0x16a9: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16ad:
	/* 0x16ad: mov    ebp,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16b2:
	/* 0x16b2: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16b4:
	/* 0x16b4: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_16b7:
	/* 0x16b7: cmp    WORD PTR [r12+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_16be:
	/* 0x16be: je     1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7558ULL;
	}
x86_l_16c4:
	/* 0x16c4: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_16cb:
	/* 0x16cb: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_16ce:
	/* 0x16ce: mov    eax,DWORD PTR [r12+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_16d3:
	/* 0x16d3: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16d6:
	/* 0x16d6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16da:
	/* 0x16da: movzx  eax,WORD PTR [r12+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_16e0:
	/* 0x16e0: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_16e2:
	/* 0x16e2: je     19ab <generic_sleepable_preload+0x19ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19ab;
	}
x86_l_16e8:
	/* 0x16e8: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_16eb:
	/* 0x16eb: je     170d <generic_sleepable_preload+0x170d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_170d;
	}
x86_l_16ed:
	/* 0x16ed: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_16f0:
	/* 0x16f0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_16f5:
	/* 0x16f5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_16fa:
	/* 0x16fa: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16fe:
	/* 0x16fe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1703:
	/* 0x1703: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1705:
	/* 0x1705: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1707:
	/* 0x1707: js     1c94 <generic_sleepable_preload+0x1c94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7316ULL;
	}
x86_l_170d:
	/* 0x170d: cmp    WORD PTR [r12+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_1714:
	/* 0x1714: je     1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7558ULL;
	}
x86_l_171a:
	/* 0x171a: mov    ecx,DWORD PTR [r12+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_171f:
	/* 0x171f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1723:
	/* 0x1723: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1727:
	/* 0x1727: cmp    WORD PTR [r12+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_172e:
	/* 0x172e: je     1750 <generic_sleepable_preload+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_1730:
	/* 0x1730: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1733:
	/* 0x1733: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1738:
	/* 0x1738: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_173d:
	/* 0x173d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1741:
	/* 0x1741: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1746:
	/* 0x1746: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1748:
	/* 0x1748: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_174a:
	/* 0x174a: js     1ca5 <generic_sleepable_preload+0x1ca5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7333ULL;
	}
x86_l_1750:
	/* 0x1750: cmp    WORD PTR [r12+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_175a:
	/* 0x175a: je     1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7558ULL;
	}
x86_l_1760:
	/* 0x1760: mov    ecx,DWORD PTR [r12+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1768:
	/* 0x1768: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_176c:
	/* 0x176c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1770:
	/* 0x1770: cmp    WORD PTR [r12+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_177a:
	/* 0x177a: je     179c <generic_sleepable_preload+0x179c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_179c;
	}
x86_l_177c:
	/* 0x177c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_177f:
	/* 0x177f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1784:
	/* 0x1784: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1789:
	/* 0x1789: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_178d:
	/* 0x178d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1792:
	/* 0x1792: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1794:
	/* 0x1794: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1796:
	/* 0x1796: js     1cb6 <generic_sleepable_preload+0x1cb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7350ULL;
	}
x86_l_179c:
	/* 0x179c: cmp    WORD PTR [r12+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_17a6:
	/* 0x17a6: je     1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7558ULL;
	}
x86_l_17ac:
	/* 0x17ac: mov    ecx,DWORD PTR [r12+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_17b4:
	/* 0x17b4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_17b8:
	/* 0x17b8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17bc:
	/* 0x17bc: cmp    WORD PTR [r12+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_17c6:
	/* 0x17c6: je     17e8 <generic_sleepable_preload+0x17e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17e8;
	}
x86_l_17c8:
	/* 0x17c8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_17cb:
	/* 0x17cb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_17d0:
	/* 0x17d0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_17d5:
	/* 0x17d5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17d9:
	/* 0x17d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17de:
	/* 0x17de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17e0:
	/* 0x17e0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17e2:
	/* 0x17e2: js     1cc7 <generic_sleepable_preload+0x1cc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7367ULL;
	}
x86_l_17e8:
	/* 0x17e8: cmp    WORD PTR [r12+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_17f2:
	/* 0x17f2: je     1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7558ULL;
	}
x86_l_17f8:
	/* 0x17f8: mov    ecx,DWORD PTR [r12+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1800:
	/* 0x1800: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1804:
	/* 0x1804: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1808:
	/* 0x1808: cmp    WORD PTR [r12+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1812:
	/* 0x1812: je     1834 <generic_sleepable_preload+0x1834> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1834;
	}
x86_l_1814:
	/* 0x1814: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1817:
	/* 0x1817: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_181c:
	/* 0x181c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1821:
	/* 0x1821: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1825:
	/* 0x1825: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_182a:
	/* 0x182a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_182c:
	/* 0x182c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_182e:
	/* 0x182e: js     1cd8 <generic_sleepable_preload+0x1cd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7384ULL;
	}
x86_l_1834:
	/* 0x1834: cmp    WORD PTR [r12+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_183e:
	/* 0x183e: je     1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7558ULL;
	}
x86_l_1844:
	/* 0x1844: mov    ecx,DWORD PTR [r12+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_184c:
	/* 0x184c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1850:
	/* 0x1850: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1854:
	/* 0x1854: cmp    WORD PTR [r12+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_185e:
	/* 0x185e: je     1880 <generic_sleepable_preload+0x1880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1880;
	}
x86_l_1860:
	/* 0x1860: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1863:
	/* 0x1863: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1868:
	/* 0x1868: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_186d:
	/* 0x186d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1871:
	/* 0x1871: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1876:
	/* 0x1876: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1878:
	/* 0x1878: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_187a:
	/* 0x187a: js     1ce9 <generic_sleepable_preload+0x1ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7401ULL;
	}
x86_l_1880:
	/* 0x1880: cmp    WORD PTR [r12+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_188a:
	/* 0x188a: je     1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7558ULL;
	}
x86_l_1890:
	/* 0x1890: mov    ecx,DWORD PTR [r12+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1898:
	/* 0x1898: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_189c:
	/* 0x189c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18a0:
	/* 0x18a0: cmp    WORD PTR [r12+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_18aa:
	/* 0x18aa: je     18cc <generic_sleepable_preload+0x18cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18cc;
	}
x86_l_18ac:
	/* 0x18ac: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_18af:
	/* 0x18af: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_18b4:
	/* 0x18b4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_18b9:
	/* 0x18b9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18bd:
	/* 0x18bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18c2:
	/* 0x18c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c4:
	/* 0x18c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18c6:
	/* 0x18c6: js     1d7e <generic_sleepable_preload+0x1d7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7550ULL;
	}
x86_l_18cc:
	/* 0x18cc: cmp    WORD PTR [r12+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_18d6:
	/* 0x18d6: je     1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7558ULL;
	}
x86_l_18dc:
	/* 0x18dc: mov    ecx,DWORD PTR [r12+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_18e4:
	/* 0x18e4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_18e8:
	/* 0x18e8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18ec:
	/* 0x18ec: cmp    WORD PTR [r12+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_18f6:
	/* 0x18f6: je     1918 <generic_sleepable_preload+0x1918> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1918;
	}
x86_l_18f8:
	/* 0x18f8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_18fb:
	/* 0x18fb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1900:
	/* 0x1900: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1905:
	/* 0x1905: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1909:
	/* 0x1909: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_190e:
	/* 0x190e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1910:
	/* 0x1910: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1912:
	/* 0x1912: js     5bda <generic_sleepable_preload+0x5bda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23514ULL;
	}
x86_l_1918:
	/* 0x1918: cmp    WORD PTR [r12+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1922:
	/* 0x1922: je     1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7558ULL;
	}
x86_l_1928:
	/* 0x1928: mov    ecx,DWORD PTR [r12+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1930:
	/* 0x1930: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1934:
	/* 0x1934: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1938:
	/* 0x1938: cmp    WORD PTR [r12+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1942:
	/* 0x1942: je     1964 <generic_sleepable_preload+0x1964> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1964;
	}
x86_l_1944:
	/* 0x1944: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1947:
	/* 0x1947: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_194c:
	/* 0x194c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1951:
	/* 0x1951: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1955:
	/* 0x1955: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_195a:
	/* 0x195a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_195c:
	/* 0x195c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_195e:
	/* 0x195e: js     5cc5 <generic_sleepable_preload+0x5cc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23749ULL;
	}
x86_l_1964:
	/* 0x1964: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1969:
	/* 0x1969: cmp    WORD PTR [r12+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1973:
	/* 0x1973: je     1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7558ULL;
	}
x86_l_1979:
	/* 0x1979: mov    ecx,DWORD PTR [r12+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1981:
	/* 0x1981: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1985:
	/* 0x1985: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1989:
	/* 0x1989: cmp    WORD PTR [r12+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1993:
	/* 0x1993: je     1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7558ULL;
	}
x86_l_1999:
	/* 0x1999: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_199c:
	/* 0x199c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19a1:
	/* 0x19a1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_19a6:
	/* 0x19a6: jmp    1c77 <generic_sleepable_preload+0x1c77> */
	return 7287ULL;
x86_l_19ab:
	/* 0x19ab: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_19ae:
	/* 0x19ae: je     19d0 <generic_sleepable_preload+0x19d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19d0;
	}
x86_l_19b0:
	/* 0x19b0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_19b3:
	/* 0x19b3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19b8:
	/* 0x19b8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_19bd:
	/* 0x19bd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19c1:
	/* 0x19c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19c6:
	/* 0x19c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19c8:
	/* 0x19c8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19ca:
	/* 0x19ca: js     1c94 <generic_sleepable_preload+0x1c94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7316ULL;
	}
x86_l_19d0:
	/* 0x19d0: cmp    WORD PTR [r12+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_19d7:
	/* 0x19d7: je     1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7558ULL;
	}
x86_l_19dd:
	/* 0x19dd: mov    ecx,DWORD PTR [r12+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_19e2:
	/* 0x19e2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_19e6:
	/* 0x19e6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19ea:
	/* 0x19ea: cmp    WORD PTR [r12+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_19f1:
	/* 0x19f1: je     1a13 <generic_sleepable_preload+0x1a13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a13;
	}
x86_l_19f3:
	/* 0x19f3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_19f6:
	/* 0x19f6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19fb:
	/* 0x19fb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a00:
	/* 0x1a00: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a04:
	/* 0x1a04: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a09:
	/* 0x1a09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a0b:
	/* 0x1a0b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a0d:
	/* 0x1a0d: js     1ca5 <generic_sleepable_preload+0x1ca5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7333ULL;
	}
x86_l_1a13:
	/* 0x1a13: cmp    WORD PTR [r12+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_1a1d:
	/* 0x1a1d: je     1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7558ULL;
	}
x86_l_1a23:
	/* 0x1a23: mov    ecx,DWORD PTR [r12+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a2b:
	/* 0x1a2b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1a2f:
	/* 0x1a2f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a33:
	/* 0x1a33: cmp    WORD PTR [r12+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1a3d:
	/* 0x1a3d: je     1a5f <generic_sleepable_preload+0x1a5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a5f;
	}
x86_l_1a3f:
	/* 0x1a3f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a42:
	/* 0x1a42: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a47:
	/* 0x1a47: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a4c:
	/* 0x1a4c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a50:
	/* 0x1a50: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a55:
	/* 0x1a55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a57:
	/* 0x1a57: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a59:
	/* 0x1a59: js     1cb6 <generic_sleepable_preload+0x1cb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7350ULL;
	}
x86_l_1a5f:
	/* 0x1a5f: cmp    WORD PTR [r12+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1a69:
	/* 0x1a69: je     1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7558ULL;
	}
	return 6767ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6767ULL: goto x86_l_1a6f;
	case 6775ULL: goto x86_l_1a77;
	case 6779ULL: goto x86_l_1a7b;
	case 6783ULL: goto x86_l_1a7f;
	case 6793ULL: goto x86_l_1a89;
	case 6795ULL: goto x86_l_1a8b;
	case 6798ULL: goto x86_l_1a8e;
	case 6803ULL: goto x86_l_1a93;
	case 6808ULL: goto x86_l_1a98;
	case 6812ULL: goto x86_l_1a9c;
	case 6817ULL: goto x86_l_1aa1;
	case 6819ULL: goto x86_l_1aa3;
	case 6821ULL: goto x86_l_1aa5;
	case 6827ULL: goto x86_l_1aab;
	case 6837ULL: goto x86_l_1ab5;
	case 6843ULL: goto x86_l_1abb;
	case 6851ULL: goto x86_l_1ac3;
	case 6855ULL: goto x86_l_1ac7;
	case 6859ULL: goto x86_l_1acb;
	case 6869ULL: goto x86_l_1ad5;
	case 6871ULL: goto x86_l_1ad7;
	case 6874ULL: goto x86_l_1ada;
	case 6879ULL: goto x86_l_1adf;
	case 6884ULL: goto x86_l_1ae4;
	case 6888ULL: goto x86_l_1ae8;
	case 6893ULL: goto x86_l_1aed;
	case 6895ULL: goto x86_l_1aef;
	case 6897ULL: goto x86_l_1af1;
	case 6903ULL: goto x86_l_1af7;
	case 6913ULL: goto x86_l_1b01;
	case 6919ULL: goto x86_l_1b07;
	case 6927ULL: goto x86_l_1b0f;
	case 6931ULL: goto x86_l_1b13;
	case 6935ULL: goto x86_l_1b17;
	case 6945ULL: goto x86_l_1b21;
	case 6947ULL: goto x86_l_1b23;
	case 6950ULL: goto x86_l_1b26;
	case 6955ULL: goto x86_l_1b2b;
	case 6960ULL: goto x86_l_1b30;
	case 6964ULL: goto x86_l_1b34;
	case 6969ULL: goto x86_l_1b39;
	case 6971ULL: goto x86_l_1b3b;
	case 6973ULL: goto x86_l_1b3d;
	case 6979ULL: goto x86_l_1b43;
	case 6989ULL: goto x86_l_1b4d;
	case 6995ULL: goto x86_l_1b53;
	case 7003ULL: goto x86_l_1b5b;
	case 7007ULL: goto x86_l_1b5f;
	case 7011ULL: goto x86_l_1b63;
	case 7021ULL: goto x86_l_1b6d;
	case 7023ULL: goto x86_l_1b6f;
	case 7026ULL: goto x86_l_1b72;
	case 7031ULL: goto x86_l_1b77;
	case 7036ULL: goto x86_l_1b7c;
	case 7040ULL: goto x86_l_1b80;
	case 7045ULL: goto x86_l_1b85;
	case 7047ULL: goto x86_l_1b87;
	case 7049ULL: goto x86_l_1b89;
	case 7055ULL: goto x86_l_1b8f;
	case 7065ULL: goto x86_l_1b99;
	case 7071ULL: goto x86_l_1b9f;
	case 7074ULL: goto x86_l_1ba2;
	case 7082ULL: goto x86_l_1baa;
	case 7086ULL: goto x86_l_1bae;
	case 7090ULL: goto x86_l_1bb2;
	case 7100ULL: goto x86_l_1bbc;
	case 7102ULL: goto x86_l_1bbe;
	case 7105ULL: goto x86_l_1bc1;
	case 7110ULL: goto x86_l_1bc6;
	case 7115ULL: goto x86_l_1bcb;
	case 7119ULL: goto x86_l_1bcf;
	case 7124ULL: goto x86_l_1bd4;
	case 7126ULL: goto x86_l_1bd6;
	case 7128ULL: goto x86_l_1bd8;
	case 7134ULL: goto x86_l_1bde;
	case 7139ULL: goto x86_l_1be3;
	case 7149ULL: goto x86_l_1bed;
	case 7152ULL: goto x86_l_1bf0;
	case 7158ULL: goto x86_l_1bf6;
	case 7166ULL: goto x86_l_1bfe;
	case 7170ULL: goto x86_l_1c02;
	case 7174ULL: goto x86_l_1c06;
	case 7184ULL: goto x86_l_1c10;
	case 7186ULL: goto x86_l_1c12;
	case 7189ULL: goto x86_l_1c15;
	case 7194ULL: goto x86_l_1c1a;
	case 7199ULL: goto x86_l_1c1f;
	case 7203ULL: goto x86_l_1c23;
	case 7208ULL: goto x86_l_1c28;
	case 7210ULL: goto x86_l_1c2a;
	case 7212ULL: goto x86_l_1c2c;
	case 7218ULL: goto x86_l_1c32;
	case 7223ULL: goto x86_l_1c37;
	case 7233ULL: goto x86_l_1c41;
	case 7236ULL: goto x86_l_1c44;
	case 7242ULL: goto x86_l_1c4a;
	case 7250ULL: goto x86_l_1c52;
	case 7254ULL: goto x86_l_1c56;
	case 7258ULL: goto x86_l_1c5a;
	case 7268ULL: goto x86_l_1c64;
	case 7274ULL: goto x86_l_1c6a;
	case 7277ULL: goto x86_l_1c6d;
	case 7282ULL: goto x86_l_1c72;
	case 7287ULL: goto x86_l_1c77;
	case 7291ULL: goto x86_l_1c7b;
	case 7296ULL: goto x86_l_1c80;
	case 7298ULL: goto x86_l_1c82;
	case 7300ULL: goto x86_l_1c84;
	case 7306ULL: goto x86_l_1c8a;
	case 7311ULL: goto x86_l_1c8f;
	case 7316ULL: goto x86_l_1c94;
	case 7321ULL: goto x86_l_1c99;
	case 7326ULL: goto x86_l_1c9e;
	case 7331ULL: goto x86_l_1ca3;
	case 7333ULL: goto x86_l_1ca5;
	case 7338ULL: goto x86_l_1caa;
	case 7343ULL: goto x86_l_1caf;
	case 7348ULL: goto x86_l_1cb4;
	case 7350ULL: goto x86_l_1cb6;
	case 7355ULL: goto x86_l_1cbb;
	case 7360ULL: goto x86_l_1cc0;
	case 7365ULL: goto x86_l_1cc5;
	case 7367ULL: goto x86_l_1cc7;
	case 7372ULL: goto x86_l_1ccc;
	case 7377ULL: goto x86_l_1cd1;
	case 7382ULL: goto x86_l_1cd6;
	case 7384ULL: goto x86_l_1cd8;
	case 7389ULL: goto x86_l_1cdd;
	case 7394ULL: goto x86_l_1ce2;
	case 7399ULL: goto x86_l_1ce7;
	case 7401ULL: goto x86_l_1ce9;
	case 7406ULL: goto x86_l_1cee;
	case 7411ULL: goto x86_l_1cf3;
	case 7416ULL: goto x86_l_1cf8;
	case 7419ULL: goto x86_l_1cfb;
	case 7424ULL: goto x86_l_1d00;
	case 7427ULL: goto x86_l_1d03;
	case 7432ULL: goto x86_l_1d08;
	case 7437ULL: goto x86_l_1d0d;
	case 7442ULL: goto x86_l_1d12;
	case 7445ULL: goto x86_l_1d15;
	case 7447ULL: goto x86_l_1d17;
	case 7450ULL: goto x86_l_1d1a;
	case 7456ULL: goto x86_l_1d20;
	case 7459ULL: goto x86_l_1d23;
	case 7463ULL: goto x86_l_1d27;
	case 7468ULL: goto x86_l_1d2c;
	case 7470ULL: goto x86_l_1d2e;
	case 7475ULL: goto x86_l_1d33;
	case 7483ULL: goto x86_l_1d3b;
	case 7490ULL: goto x86_l_1d42;
	case 7495ULL: goto x86_l_1d47;
	case 7500ULL: goto x86_l_1d4c;
	case 7502ULL: goto x86_l_1d4e;
	case 7505ULL: goto x86_l_1d51;
	case 7511ULL: goto x86_l_1d57;
	case 7514ULL: goto x86_l_1d5a;
	case 7521ULL: goto x86_l_1d61;
	case 7523ULL: goto x86_l_1d63;
	case 7528ULL: goto x86_l_1d68;
	case 7533ULL: goto x86_l_1d6d;
	case 7536ULL: goto x86_l_1d70;
	case 7539ULL: goto x86_l_1d73;
	case 7541ULL: goto x86_l_1d75;
	case 7543ULL: goto x86_l_1d77;
	case 7548ULL: goto x86_l_1d7c;
	case 7550ULL: goto x86_l_1d7e;
	case 7555ULL: goto x86_l_1d83;
	case 7558ULL: goto x86_l_1d86;
	case 7561ULL: goto x86_l_1d89;
	case 7567ULL: goto x86_l_1d8f;
	case 7570ULL: goto x86_l_1d92;
	case 7574ULL: goto x86_l_1d96;
	case 7579ULL: goto x86_l_1d9b;
	case 7581ULL: goto x86_l_1d9d;
	case 7586ULL: goto x86_l_1da2;
	case 7594ULL: goto x86_l_1daa;
	case 7601ULL: goto x86_l_1db1;
	case 7606ULL: goto x86_l_1db6;
	case 7611ULL: goto x86_l_1dbb;
	case 7613ULL: goto x86_l_1dbd;
	case 7616ULL: goto x86_l_1dc0;
	case 7618ULL: goto x86_l_1dc2;
	case 7621ULL: goto x86_l_1dc5;
	case 7628ULL: goto x86_l_1dcc;
	case 7630ULL: goto x86_l_1dce;
	case 7635ULL: goto x86_l_1dd3;
	case 7640ULL: goto x86_l_1dd8;
	case 7643ULL: goto x86_l_1ddb;
	case 7646ULL: goto x86_l_1dde;
	case 7648ULL: goto x86_l_1de0;
	case 7650ULL: goto x86_l_1de2;
	case 7655ULL: goto x86_l_1de7;
	case 7658ULL: goto x86_l_1dea;
	case 7661ULL: goto x86_l_1ded;
	case 7666ULL: goto x86_l_1df2;
	case 7668ULL: goto x86_l_1df4;
	case 7671ULL: goto x86_l_1df7;
	case 7673ULL: goto x86_l_1df9;
	case 7676ULL: goto x86_l_1dfc;
	case 7678ULL: goto x86_l_1dfe;
	case 7681ULL: goto x86_l_1e01;
	case 7685ULL: goto x86_l_1e05;
	case 7690ULL: goto x86_l_1e0a;
	case 7693ULL: goto x86_l_1e0d;
	case 7695ULL: goto x86_l_1e0f;
	case 7698ULL: goto x86_l_1e12;
	case 7703ULL: goto x86_l_1e17;
	case 7705ULL: goto x86_l_1e19;
	case 7708ULL: goto x86_l_1e1c;
	case 7710ULL: goto x86_l_1e1e;
	case 7712ULL: goto x86_l_1e20;
	case 7717ULL: goto x86_l_1e25;
	case 7719ULL: goto x86_l_1e27;
	case 7722ULL: goto x86_l_1e2a;
	case 7727ULL: goto x86_l_1e2f;
	case 7732ULL: goto x86_l_1e34;
	case 7738ULL: goto x86_l_1e3a;
	case 7740ULL: goto x86_l_1e3c;
	case 7742ULL: goto x86_l_1e3e;
	case 7747ULL: goto x86_l_1e43;
	case 7750ULL: goto x86_l_1e46;
	case 7756ULL: goto x86_l_1e4c;
	case 7759ULL: goto x86_l_1e4f;
	case 7765ULL: goto x86_l_1e55;
	case 7768ULL: goto x86_l_1e58;
	case 7774ULL: goto x86_l_1e5e;
	case 7777ULL: goto x86_l_1e61;
	case 7783ULL: goto x86_l_1e67;
	case 7788ULL: goto x86_l_1e6c;
	case 7793ULL: goto x86_l_1e71;
	case 7802ULL: goto x86_l_1e7a;
	case 7811ULL: goto x86_l_1e83;
	case 7817ULL: goto x86_l_1e89;
	case 7819ULL: goto x86_l_1e8b;
	case 7822ULL: goto x86_l_1e8e;
	case 7824ULL: goto x86_l_1e90;
	case 7827ULL: goto x86_l_1e93;
	case 7829ULL: goto x86_l_1e95;
	case 7832ULL: goto x86_l_1e98;
	case 7838ULL: goto x86_l_1e9e;
	case 7843ULL: goto x86_l_1ea3;
	case 7846ULL: goto x86_l_1ea6;
	case 7852ULL: goto x86_l_1eac;
	case 7857ULL: goto x86_l_1eb1;
	case 7860ULL: goto x86_l_1eb4;
	case 7866ULL: goto x86_l_1eba;
	case 7871ULL: goto x86_l_1ebf;
	case 7874ULL: goto x86_l_1ec2;
	case 7880ULL: goto x86_l_1ec8;
	case 7885ULL: goto x86_l_1ecd;
	case 7888ULL: goto x86_l_1ed0;
	case 7890ULL: goto x86_l_1ed2;
	case 7893ULL: goto x86_l_1ed5;
	case 7899ULL: goto x86_l_1edb;
	case 7901ULL: goto x86_l_1edd;
	case 7907ULL: goto x86_l_1ee3;
	case 7910ULL: goto x86_l_1ee6;
	case 7913ULL: goto x86_l_1ee9;
	case 7919ULL: goto x86_l_1eef;
	case 7924ULL: goto x86_l_1ef4;
	case 7926ULL: goto x86_l_1ef6;
	case 7928ULL: goto x86_l_1ef8;
	case 7931ULL: goto x86_l_1efb;
	case 7933ULL: goto x86_l_1efd;
	case 7938ULL: goto x86_l_1f02;
	case 7940ULL: goto x86_l_1f04;
	case 7943ULL: goto x86_l_1f07;
	case 7949ULL: goto x86_l_1f0d;
	case 7957ULL: goto x86_l_1f15;
	case 7960ULL: goto x86_l_1f18;
	case 7966ULL: goto x86_l_1f1e;
	case 7971ULL: goto x86_l_1f23;
	case 7974ULL: goto x86_l_1f26;
	case 7980ULL: goto x86_l_1f2c;
	case 7985ULL: goto x86_l_1f31;
	case 7988ULL: goto x86_l_1f34;
	case 7994ULL: goto x86_l_1f3a;
	case 8002ULL: goto x86_l_1f42;
	case 8005ULL: goto x86_l_1f45;
	case 8011ULL: goto x86_l_1f4b;
	case 8016ULL: goto x86_l_1f50;
	case 8019ULL: goto x86_l_1f53;
	case 8025ULL: goto x86_l_1f59;
	case 8030ULL: goto x86_l_1f5e;
	case 8035ULL: goto x86_l_1f63;
	case 8037ULL: goto x86_l_1f65;
	case 8042ULL: goto x86_l_1f6a;
	case 8044ULL: goto x86_l_1f6c;
	case 8049ULL: goto x86_l_1f71;
	case 8052ULL: goto x86_l_1f74;
	case 8056ULL: goto x86_l_1f78;
	case 8058ULL: goto x86_l_1f7a;
	case 8061ULL: goto x86_l_1f7d;
	case 8071ULL: goto x86_l_1f87;
	case 8077ULL: goto x86_l_1f8d;
	case 8084ULL: goto x86_l_1f94;
	case 8087ULL: goto x86_l_1f97;
	case 8095ULL: goto x86_l_1f9f;
	case 8098ULL: goto x86_l_1fa2;
	case 8102ULL: goto x86_l_1fa6;
	case 8111ULL: goto x86_l_1faf;
	case 8113ULL: goto x86_l_1fb1;
	case 8119ULL: goto x86_l_1fb7;
	case 8122ULL: goto x86_l_1fba;
	case 8124ULL: goto x86_l_1fbc;
	case 8127ULL: goto x86_l_1fbf;
	case 8132ULL: goto x86_l_1fc4;
	case 8137ULL: goto x86_l_1fc9;
	case 8141ULL: goto x86_l_1fcd;
	case 8146ULL: goto x86_l_1fd2;
	case 8148ULL: goto x86_l_1fd4;
	case 8150ULL: goto x86_l_1fd6;
	case 8156ULL: goto x86_l_1fdc;
	case 8166ULL: goto x86_l_1fe6;
	case 8172ULL: goto x86_l_1fec;
	case 8180ULL: goto x86_l_1ff4;
	case 8184ULL: goto x86_l_1ff8;
	case 8188ULL: goto x86_l_1ffc;
	case 8198ULL: goto x86_l_2006;
	case 8200ULL: goto x86_l_2008;
	case 8203ULL: goto x86_l_200b;
	case 8208ULL: goto x86_l_2010;
	case 8213ULL: goto x86_l_2015;
	case 8217ULL: goto x86_l_2019;
	case 8222ULL: goto x86_l_201e;
	case 8224ULL: goto x86_l_2020;
	case 8226ULL: goto x86_l_2022;
	case 8232ULL: goto x86_l_2028;
	case 8242ULL: goto x86_l_2032;
	case 8248ULL: goto x86_l_2038;
	case 8256ULL: goto x86_l_2040;
	case 8260ULL: goto x86_l_2044;
	case 8264ULL: goto x86_l_2048;
	case 8274ULL: goto x86_l_2052;
	case 8276ULL: goto x86_l_2054;
	case 8279ULL: goto x86_l_2057;
	case 8284ULL: goto x86_l_205c;
	case 8289ULL: goto x86_l_2061;
	case 8293ULL: goto x86_l_2065;
	case 8298ULL: goto x86_l_206a;
	case 8300ULL: goto x86_l_206c;
	case 8302ULL: goto x86_l_206e;
	case 8308ULL: goto x86_l_2074;
	case 8318ULL: goto x86_l_207e;
	case 8324ULL: goto x86_l_2084;
	case 8332ULL: goto x86_l_208c;
	case 8336ULL: goto x86_l_2090;
	case 8340ULL: goto x86_l_2094;
	case 8350ULL: goto x86_l_209e;
	case 8352ULL: goto x86_l_20a0;
	case 8355ULL: goto x86_l_20a3;
	case 8360ULL: goto x86_l_20a8;
	case 8365ULL: goto x86_l_20ad;
	case 8369ULL: goto x86_l_20b1;
	case 8374ULL: goto x86_l_20b6;
	case 8376ULL: goto x86_l_20b8;
	case 8378ULL: goto x86_l_20ba;
	case 8384ULL: goto x86_l_20c0;
	case 8394ULL: goto x86_l_20ca;
	case 8400ULL: goto x86_l_20d0;
	case 8408ULL: goto x86_l_20d8;
	case 8412ULL: goto x86_l_20dc;
	case 8416ULL: goto x86_l_20e0;
	case 8426ULL: goto x86_l_20ea;
	case 8428ULL: goto x86_l_20ec;
	case 8431ULL: goto x86_l_20ef;
	case 8436ULL: goto x86_l_20f4;
	case 8441ULL: goto x86_l_20f9;
	case 8445ULL: goto x86_l_20fd;
	case 8450ULL: goto x86_l_2102;
	case 8452ULL: goto x86_l_2104;
	case 8454ULL: goto x86_l_2106;
	case 8460ULL: goto x86_l_210c;
	case 8470ULL: goto x86_l_2116;
	case 8476ULL: goto x86_l_211c;
	case 8484ULL: goto x86_l_2124;
	case 8488ULL: goto x86_l_2128;
	case 8492ULL: goto x86_l_212c;
	case 8502ULL: goto x86_l_2136;
	case 8504ULL: goto x86_l_2138;
	case 8507ULL: goto x86_l_213b;
	case 8512ULL: goto x86_l_2140;
	case 8517ULL: goto x86_l_2145;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1a6f:
	/* 0x1a6f: mov    ecx,DWORD PTR [r12+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1a77:
	/* 0x1a77: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1a7b:
	/* 0x1a7b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a7f:
	/* 0x1a7f: cmp    WORD PTR [r12+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1a89:
	/* 0x1a89: je     1aab <generic_sleepable_preload+0x1aab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1aab;
	}
x86_l_1a8b:
	/* 0x1a8b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a8e:
	/* 0x1a8e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a93:
	/* 0x1a93: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a98:
	/* 0x1a98: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a9c:
	/* 0x1a9c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1aa1:
	/* 0x1aa1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aa3:
	/* 0x1aa3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1aa5:
	/* 0x1aa5: js     1cc7 <generic_sleepable_preload+0x1cc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1cc7;
	}
x86_l_1aab:
	/* 0x1aab: cmp    WORD PTR [r12+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1ab5:
	/* 0x1ab5: je     1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d86;
	}
x86_l_1abb:
	/* 0x1abb: mov    ecx,DWORD PTR [r12+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1ac3:
	/* 0x1ac3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1ac7:
	/* 0x1ac7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1acb:
	/* 0x1acb: cmp    WORD PTR [r12+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1ad5:
	/* 0x1ad5: je     1af7 <generic_sleepable_preload+0x1af7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1af7;
	}
x86_l_1ad7:
	/* 0x1ad7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1ada:
	/* 0x1ada: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1adf:
	/* 0x1adf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1ae4:
	/* 0x1ae4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ae8:
	/* 0x1ae8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1aed:
	/* 0x1aed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aef:
	/* 0x1aef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1af1:
	/* 0x1af1: js     1cd8 <generic_sleepable_preload+0x1cd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1cd8;
	}
x86_l_1af7:
	/* 0x1af7: cmp    WORD PTR [r12+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_1b01:
	/* 0x1b01: je     1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d86;
	}
x86_l_1b07:
	/* 0x1b07: mov    ecx,DWORD PTR [r12+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1b0f:
	/* 0x1b0f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1b13:
	/* 0x1b13: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b17:
	/* 0x1b17: cmp    WORD PTR [r12+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1b21:
	/* 0x1b21: je     1b43 <generic_sleepable_preload+0x1b43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b43;
	}
x86_l_1b23:
	/* 0x1b23: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1b26:
	/* 0x1b26: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b2b:
	/* 0x1b2b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b30:
	/* 0x1b30: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b34:
	/* 0x1b34: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b39:
	/* 0x1b39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b3b:
	/* 0x1b3b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b3d:
	/* 0x1b3d: js     1ce9 <generic_sleepable_preload+0x1ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ce9;
	}
x86_l_1b43:
	/* 0x1b43: cmp    WORD PTR [r12+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1b4d:
	/* 0x1b4d: je     1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d86;
	}
x86_l_1b53:
	/* 0x1b53: mov    ecx,DWORD PTR [r12+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1b5b:
	/* 0x1b5b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1b5f:
	/* 0x1b5f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b63:
	/* 0x1b63: cmp    WORD PTR [r12+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1b6d:
	/* 0x1b6d: je     1b8f <generic_sleepable_preload+0x1b8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b8f;
	}
x86_l_1b6f:
	/* 0x1b6f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1b72:
	/* 0x1b72: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b77:
	/* 0x1b77: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b7c:
	/* 0x1b7c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b80:
	/* 0x1b80: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b85:
	/* 0x1b85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b87:
	/* 0x1b87: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b89:
	/* 0x1b89: js     1d7e <generic_sleepable_preload+0x1d7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1d7e;
	}
x86_l_1b8f:
	/* 0x1b8f: cmp    WORD PTR [r12+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1b99:
	/* 0x1b99: je     1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d86;
	}
x86_l_1b9f:
	/* 0x1b9f: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_1ba2:
	/* 0x1ba2: mov    ecx,DWORD PTR [r12+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1baa:
	/* 0x1baa: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1bae:
	/* 0x1bae: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bb2:
	/* 0x1bb2: cmp    WORD PTR [r12+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1bbc:
	/* 0x1bbc: je     1bde <generic_sleepable_preload+0x1bde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bde;
	}
x86_l_1bbe:
	/* 0x1bbe: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1bc1:
	/* 0x1bc1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1bc6:
	/* 0x1bc6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1bcb:
	/* 0x1bcb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bcf:
	/* 0x1bcf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bd4:
	/* 0x1bd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bd6:
	/* 0x1bd6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bd8:
	/* 0x1bd8: js     5c58 <generic_sleepable_preload+0x5c58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23640ULL;
	}
x86_l_1bde:
	/* 0x1bde: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1be3:
	/* 0x1be3: cmp    WORD PTR [r12+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1bed:
	/* 0x1bed: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_1bf0:
	/* 0x1bf0: je     1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d86;
	}
x86_l_1bf6:
	/* 0x1bf6: mov    ecx,DWORD PTR [r12+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1bfe:
	/* 0x1bfe: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1c02:
	/* 0x1c02: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c06:
	/* 0x1c06: cmp    WORD PTR [r12+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1c10:
	/* 0x1c10: je     1c32 <generic_sleepable_preload+0x1c32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c32;
	}
x86_l_1c12:
	/* 0x1c12: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1c15:
	/* 0x1c15: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1c1a:
	/* 0x1c1a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1c1f:
	/* 0x1c1f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c23:
	/* 0x1c23: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c28:
	/* 0x1c28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c2a:
	/* 0x1c2a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c2c:
	/* 0x1c2c: js     5d58 <generic_sleepable_preload+0x5d58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23896ULL;
	}
x86_l_1c32:
	/* 0x1c32: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c37:
	/* 0x1c37: cmp    WORD PTR [r12+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1c41:
	/* 0x1c41: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_1c44:
	/* 0x1c44: je     1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d86;
	}
x86_l_1c4a:
	/* 0x1c4a: mov    ecx,DWORD PTR [r12+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1c52:
	/* 0x1c52: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1c56:
	/* 0x1c56: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c5a:
	/* 0x1c5a: cmp    WORD PTR [r12+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1c64:
	/* 0x1c64: je     1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d86;
	}
x86_l_1c6a:
	/* 0x1c6a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1c6d:
	/* 0x1c6d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1c72:
	/* 0x1c72: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1c77:
	/* 0x1c77: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c7b:
	/* 0x1c7b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c80:
	/* 0x1c80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c82:
	/* 0x1c82: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c84:
	/* 0x1c84: jns    1d86 <generic_sleepable_preload+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1d86;
	}
x86_l_1c8a:
	/* 0x1c8a: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_1c8f:
	/* 0x1c8f: jmp    1d83 <generic_sleepable_preload+0x1d83> */
	goto x86_l_1d83;
x86_l_1c94:
	/* 0x1c94: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_1c99:
	/* 0x1c99: jmp    1d83 <generic_sleepable_preload+0x1d83> */
	goto x86_l_1d83;
x86_l_1c9e:
	/* 0x1c9e: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_1ca3:
	/* 0x1ca3: jmp    1cf8 <generic_sleepable_preload+0x1cf8> */
	goto x86_l_1cf8;
x86_l_1ca5:
	/* 0x1ca5: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_1caa:
	/* 0x1caa: jmp    1d83 <generic_sleepable_preload+0x1d83> */
	goto x86_l_1d83;
x86_l_1caf:
	/* 0x1caf: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_1cb4:
	/* 0x1cb4: jmp    1cf8 <generic_sleepable_preload+0x1cf8> */
	goto x86_l_1cf8;
x86_l_1cb6:
	/* 0x1cb6: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_1cbb:
	/* 0x1cbb: jmp    1d83 <generic_sleepable_preload+0x1d83> */
	goto x86_l_1d83;
x86_l_1cc0:
	/* 0x1cc0: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_1cc5:
	/* 0x1cc5: jmp    1cf8 <generic_sleepable_preload+0x1cf8> */
	goto x86_l_1cf8;
x86_l_1cc7:
	/* 0x1cc7: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_1ccc:
	/* 0x1ccc: jmp    1d83 <generic_sleepable_preload+0x1d83> */
	goto x86_l_1d83;
x86_l_1cd1:
	/* 0x1cd1: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_1cd6:
	/* 0x1cd6: jmp    1cf8 <generic_sleepable_preload+0x1cf8> */
	goto x86_l_1cf8;
x86_l_1cd8:
	/* 0x1cd8: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_1cdd:
	/* 0x1cdd: jmp    1d83 <generic_sleepable_preload+0x1d83> */
	goto x86_l_1d83;
x86_l_1ce2:
	/* 0x1ce2: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_1ce7:
	/* 0x1ce7: jmp    1cf8 <generic_sleepable_preload+0x1cf8> */
	goto x86_l_1cf8;
x86_l_1ce9:
	/* 0x1ce9: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_1cee:
	/* 0x1cee: jmp    1d83 <generic_sleepable_preload+0x1d83> */
	goto x86_l_1d83;
x86_l_1cf3:
	/* 0x1cf3: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_1cf8:
	/* 0x1cf8: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cfb:
	/* 0x1cfb: mov    ebp,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d00:
	/* 0x1d00: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1d03:
	/* 0x1d03: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d08:
	/* 0x1d08: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d0d:
	/* 0x1d0d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d12:
	/* 0x1d12: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1d15:
	/* 0x1d15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d17:
	/* 0x1d17: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1d1a:
	/* 0x1d1a: jne    1e2a <generic_sleepable_preload+0x1e2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e2a;
	}
x86_l_1d20:
	/* 0x1d20: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_1d23:
	/* 0x1d23: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d27:
	/* 0x1d27: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1d2c:
	/* 0x1d2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d2e:
	/* 0x1d2e: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d33:
	/* 0x1d33: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1d3b:
	/* 0x1d3b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1d42:
	/* 0x1d42: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1d47:
	/* 0x1d47: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d4c:
	/* 0x1d4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d4e:
	/* 0x1d4e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d51:
	/* 0x1d51: je     1e27 <generic_sleepable_preload+0x1e27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e27;
	}
x86_l_1d57:
	/* 0x1d57: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1d5a:
	/* 0x1d5a: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1d61:
	/* 0x1d61: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d63:
	/* 0x1d63: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d68:
	/* 0x1d68: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1d6d:
	/* 0x1d6d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1d70:
	/* 0x1d70: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1d73:
	/* 0x1d73: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d75:
	/* 0x1d75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d77:
	/* 0x1d77: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d7c:
	/* 0x1d7c: jmp    1de7 <generic_sleepable_preload+0x1de7> */
	goto x86_l_1de7;
x86_l_1d7e:
	/* 0x1d7e: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_1d83:
	/* 0x1d83: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d86:
	/* 0x1d86: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1d89:
	/* 0x1d89: jne    1e2a <generic_sleepable_preload+0x1e2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e2a;
	}
x86_l_1d8f:
	/* 0x1d8f: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_1d92:
	/* 0x1d92: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d96:
	/* 0x1d96: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1d9b:
	/* 0x1d9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d9d:
	/* 0x1d9d: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1da2:
	/* 0x1da2: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1daa:
	/* 0x1daa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1db1:
	/* 0x1db1: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1db6:
	/* 0x1db6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dbb:
	/* 0x1dbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dbd:
	/* 0x1dbd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dc0:
	/* 0x1dc0: je     1e27 <generic_sleepable_preload+0x1e27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e27;
	}
x86_l_1dc2:
	/* 0x1dc2: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1dc5:
	/* 0x1dc5: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1dcc:
	/* 0x1dcc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dce:
	/* 0x1dce: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1dd3:
	/* 0x1dd3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1dd8:
	/* 0x1dd8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1ddb:
	/* 0x1ddb: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1dde:
	/* 0x1dde: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1de0:
	/* 0x1de0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de2:
	/* 0x1de2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1de7:
	/* 0x1de7: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1dea:
	/* 0x1dea: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1ded:
	/* 0x1ded: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1df2:
	/* 0x1df2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1df4:
	/* 0x1df4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1df7:
	/* 0x1df7: je     1e27 <generic_sleepable_preload+0x1e27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e27;
	}
x86_l_1df9:
	/* 0x1df9: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_1dfc:
	/* 0x1dfc: je     1e25 <generic_sleepable_preload+0x1e25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e25;
	}
x86_l_1dfe:
	/* 0x1dfe: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1e01:
	/* 0x1e01: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1e05:
	/* 0x1e05: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1e0a:
	/* 0x1e0a: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1e0d:
	/* 0x1e0d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e0f:
	/* 0x1e0f: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1e12:
	/* 0x1e12: call   1e17 <generic_sleepable_preload+0x1e17> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_1e17:
	/* 0x1e17: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1e19:
	/* 0x1e19: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_1e1c:
	/* 0x1e1c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1e1e:
	/* 0x1e1e: jns    1e25 <generic_sleepable_preload+0x1e25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1e25;
	}
x86_l_1e20:
	/* 0x1e20: mov    ebx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_1e25:
	/* 0x1e25: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e27:
	/* 0x1e27: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_1e2a:
	/* 0x1e2a: mov    eax,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1e2f:
	/* 0x1e2f: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_1e34:
	/* 0x1e34: je     2d95 <generic_sleepable_preload+0x2d95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11669ULL;
	}
x86_l_1e3a:
	/* 0x1e3a: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1e3c:
	/* 0x1e3c: js     1e71 <generic_sleepable_preload+0x1e71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1e71;
	}
x86_l_1e3e:
	/* 0x1e3e: mov    eax,DWORD PTR [r12+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1e43:
	/* 0x1e43: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e46:
	/* 0x1e46: jle    1ef4 <generic_sleepable_preload+0x1ef4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1ef4;
	}
x86_l_1e4c:
	/* 0x1e4c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e4f:
	/* 0x1e4f: je     1f5e <generic_sleepable_preload+0x1f5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f5e;
	}
x86_l_1e55:
	/* 0x1e55: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1e58:
	/* 0x1e58: je     1f65 <generic_sleepable_preload+0x1f65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f65;
	}
x86_l_1e5e:
	/* 0x1e5e: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e61:
	/* 0x1e61: jne    1f78 <generic_sleepable_preload+0x1f78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f78;
	}
x86_l_1e67:
	/* 0x1e67: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e6c:
	/* 0x1e6c: jmp    1f71 <generic_sleepable_preload+0x1f71> */
	goto x86_l_1f71;
x86_l_1e71:
	/* 0x1e71: movzx  eax,BYTE PTR [r12+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_1e7a:
	/* 0x1e7a: movzx  ecx,WORD PTR [r12+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_1e83:
	/* 0x1e83: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_1e89:
	/* 0x1e89: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e8b:
	/* 0x1e8b: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1e8e:
	/* 0x1e8e: jle    1ecd <generic_sleepable_preload+0x1ecd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1ecd;
	}
x86_l_1e90:
	/* 0x1e90: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1e93:
	/* 0x1e93: jle    1f04 <generic_sleepable_preload+0x1f04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1f04;
	}
x86_l_1e95:
	/* 0x1e95: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1e98:
	/* 0x1e98: jle    25c7 <generic_sleepable_preload+0x25c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 9671ULL;
	}
x86_l_1e9e:
	/* 0x1e9e: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ea3:
	/* 0x1ea3: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_1ea6:
	/* 0x1ea6: je     25ec <generic_sleepable_preload+0x25ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9708ULL;
	}
x86_l_1eac:
	/* 0x1eac: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1eb1:
	/* 0x1eb1: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_1eb4:
	/* 0x1eb4: je     25ec <generic_sleepable_preload+0x25ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9708ULL;
	}
x86_l_1eba:
	/* 0x1eba: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1ebf:
	/* 0x1ebf: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_1ec2:
	/* 0x1ec2: je     25ec <generic_sleepable_preload+0x25ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9708ULL;
	}
x86_l_1ec8:
	/* 0x1ec8: jmp    25ff <generic_sleepable_preload+0x25ff> */
	return 9727ULL;
x86_l_1ecd:
	/* 0x1ecd: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1ed0:
	/* 0x1ed0: jg     1f31 <generic_sleepable_preload+0x1f31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1f31;
	}
x86_l_1ed2:
	/* 0x1ed2: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1ed5:
	/* 0x1ed5: jg     2598 <generic_sleepable_preload+0x2598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9624ULL;
	}
x86_l_1edb:
	/* 0x1edb: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1edd:
	/* 0x1edd: je     25e7 <generic_sleepable_preload+0x25e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9703ULL;
	}
x86_l_1ee3:
	/* 0x1ee3: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1ee6:
	/* 0x1ee6: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1ee9:
	/* 0x1ee9: je     25ec <generic_sleepable_preload+0x25ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9708ULL;
	}
x86_l_1eef:
	/* 0x1eef: jmp    25ff <generic_sleepable_preload+0x25ff> */
	return 9727ULL;
x86_l_1ef4:
	/* 0x1ef4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ef6:
	/* 0x1ef6: je     1f6c <generic_sleepable_preload+0x1f6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f6c;
	}
x86_l_1ef8:
	/* 0x1ef8: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1efb:
	/* 0x1efb: jne    1f78 <generic_sleepable_preload+0x1f78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f78;
	}
x86_l_1efd:
	/* 0x1efd: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f02:
	/* 0x1f02: jmp    1f71 <generic_sleepable_preload+0x1f71> */
	goto x86_l_1f71;
x86_l_1f04:
	/* 0x1f04: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1f07:
	/* 0x1f07: jg     257f <generic_sleepable_preload+0x257f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9599ULL;
	}
x86_l_1f0d:
	/* 0x1f0d: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1f15:
	/* 0x1f15: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1f18:
	/* 0x1f18: je     25ec <generic_sleepable_preload+0x25ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9708ULL;
	}
x86_l_1f1e:
	/* 0x1f1e: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f23:
	/* 0x1f23: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1f26:
	/* 0x1f26: je     25ec <generic_sleepable_preload+0x25ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9708ULL;
	}
x86_l_1f2c:
	/* 0x1f2c: jmp    25ff <generic_sleepable_preload+0x25ff> */
	return 9727ULL;
x86_l_1f31:
	/* 0x1f31: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1f34:
	/* 0x1f34: jg     25ae <generic_sleepable_preload+0x25ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9646ULL;
	}
x86_l_1f3a:
	/* 0x1f3a: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1f42:
	/* 0x1f42: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1f45:
	/* 0x1f45: je     25ec <generic_sleepable_preload+0x25ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9708ULL;
	}
x86_l_1f4b:
	/* 0x1f4b: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1f50:
	/* 0x1f50: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1f53:
	/* 0x1f53: je     25ec <generic_sleepable_preload+0x25ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9708ULL;
	}
x86_l_1f59:
	/* 0x1f59: jmp    25ff <generic_sleepable_preload+0x25ff> */
	return 9727ULL;
x86_l_1f5e:
	/* 0x1f5e: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f63:
	/* 0x1f63: jmp    1f71 <generic_sleepable_preload+0x1f71> */
	goto x86_l_1f71;
x86_l_1f65:
	/* 0x1f65: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f6a:
	/* 0x1f6a: jmp    1f71 <generic_sleepable_preload+0x1f71> */
	goto x86_l_1f71;
x86_l_1f6c:
	/* 0x1f6c: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f71:
	/* 0x1f71: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f74:
	/* 0x1f74: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f78:
	/* 0x1f78: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f7a:
	/* 0x1f7a: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_1f7d:
	/* 0x1f7d: cmp    WORD PTR [r12+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_1f87:
	/* 0x1f87: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_1f8d:
	/* 0x1f8d: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1f94:
	/* 0x1f94: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1f97:
	/* 0x1f97: mov    eax,DWORD PTR [r12+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1f9f:
	/* 0x1f9f: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1fa2:
	/* 0x1fa2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fa6:
	/* 0x1fa6: movzx  eax,WORD PTR [r12+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_1faf:
	/* 0x1faf: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1fb1:
	/* 0x1fb1: je     2283 <generic_sleepable_preload+0x2283> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8835ULL;
	}
x86_l_1fb7:
	/* 0x1fb7: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1fba:
	/* 0x1fba: je     1fdc <generic_sleepable_preload+0x1fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fdc;
	}
x86_l_1fbc:
	/* 0x1fbc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1fbf:
	/* 0x1fbf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1fc4:
	/* 0x1fc4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1fc9:
	/* 0x1fc9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fcd:
	/* 0x1fcd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fd2:
	/* 0x1fd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fd4:
	/* 0x1fd4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fd6:
	/* 0x1fd6: js     2575 <generic_sleepable_preload+0x2575> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9589ULL;
	}
x86_l_1fdc:
	/* 0x1fdc: cmp    WORD PTR [r12+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_1fe6:
	/* 0x1fe6: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_1fec:
	/* 0x1fec: mov    ecx,DWORD PTR [r12+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1ff4:
	/* 0x1ff4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1ff8:
	/* 0x1ff8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ffc:
	/* 0x1ffc: cmp    WORD PTR [r12+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_2006:
	/* 0x2006: je     2028 <generic_sleepable_preload+0x2028> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2028;
	}
x86_l_2008:
	/* 0x2008: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_200b:
	/* 0x200b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2010:
	/* 0x2010: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2015:
	/* 0x2015: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2019:
	/* 0x2019: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_201e:
	/* 0x201e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2020:
	/* 0x2020: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2022:
	/* 0x2022: js     25dd <generic_sleepable_preload+0x25dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9693ULL;
	}
x86_l_2028:
	/* 0x2028: cmp    WORD PTR [r12+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_2032:
	/* 0x2032: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_2038:
	/* 0x2038: mov    ecx,DWORD PTR [r12+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2040:
	/* 0x2040: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2044:
	/* 0x2044: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2048:
	/* 0x2048: cmp    WORD PTR [r12+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_2052:
	/* 0x2052: je     2074 <generic_sleepable_preload+0x2074> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2074;
	}
x86_l_2054:
	/* 0x2054: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2057:
	/* 0x2057: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_205c:
	/* 0x205c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2061:
	/* 0x2061: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2065:
	/* 0x2065: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_206a:
	/* 0x206a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_206c:
	/* 0x206c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_206e:
	/* 0x206e: js     2c19 <generic_sleepable_preload+0x2c19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11289ULL;
	}
x86_l_2074:
	/* 0x2074: cmp    WORD PTR [r12+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_207e:
	/* 0x207e: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_2084:
	/* 0x2084: mov    ecx,DWORD PTR [r12+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_208c:
	/* 0x208c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2090:
	/* 0x2090: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2094:
	/* 0x2094: cmp    WORD PTR [r12+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_209e:
	/* 0x209e: je     20c0 <generic_sleepable_preload+0x20c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20c0;
	}
x86_l_20a0:
	/* 0x20a0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20a3:
	/* 0x20a3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_20a8:
	/* 0x20a8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20ad:
	/* 0x20ad: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20b1:
	/* 0x20b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20b6:
	/* 0x20b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20b8:
	/* 0x20b8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20ba:
	/* 0x20ba: js     2c2a <generic_sleepable_preload+0x2c2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11306ULL;
	}
x86_l_20c0:
	/* 0x20c0: cmp    WORD PTR [r12+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_20ca:
	/* 0x20ca: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_20d0:
	/* 0x20d0: mov    ecx,DWORD PTR [r12+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_20d8:
	/* 0x20d8: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_20dc:
	/* 0x20dc: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20e0:
	/* 0x20e0: cmp    WORD PTR [r12+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_20ea:
	/* 0x20ea: je     210c <generic_sleepable_preload+0x210c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_210c;
	}
x86_l_20ec:
	/* 0x20ec: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20ef:
	/* 0x20ef: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_20f4:
	/* 0x20f4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20f9:
	/* 0x20f9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20fd:
	/* 0x20fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2102:
	/* 0x2102: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2104:
	/* 0x2104: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2106:
	/* 0x2106: js     2c3b <generic_sleepable_preload+0x2c3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11323ULL;
	}
x86_l_210c:
	/* 0x210c: cmp    WORD PTR [r12+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_2116:
	/* 0x2116: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_211c:
	/* 0x211c: mov    ecx,DWORD PTR [r12+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2124:
	/* 0x2124: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2128:
	/* 0x2128: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_212c:
	/* 0x212c: cmp    WORD PTR [r12+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2136:
	/* 0x2136: je     2158 <generic_sleepable_preload+0x2158> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8536ULL;
	}
x86_l_2138:
	/* 0x2138: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_213b:
	/* 0x213b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2140:
	/* 0x2140: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2145:
	/* 0x2145: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 8521ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8521ULL: goto x86_l_2149;
	case 8526ULL: goto x86_l_214e;
	case 8528ULL: goto x86_l_2150;
	case 8530ULL: goto x86_l_2152;
	case 8536ULL: goto x86_l_2158;
	case 8546ULL: goto x86_l_2162;
	case 8552ULL: goto x86_l_2168;
	case 8560ULL: goto x86_l_2170;
	case 8564ULL: goto x86_l_2174;
	case 8568ULL: goto x86_l_2178;
	case 8578ULL: goto x86_l_2182;
	case 8580ULL: goto x86_l_2184;
	case 8583ULL: goto x86_l_2187;
	case 8588ULL: goto x86_l_218c;
	case 8593ULL: goto x86_l_2191;
	case 8597ULL: goto x86_l_2195;
	case 8602ULL: goto x86_l_219a;
	case 8604ULL: goto x86_l_219c;
	case 8606ULL: goto x86_l_219e;
	case 8612ULL: goto x86_l_21a4;
	case 8622ULL: goto x86_l_21ae;
	case 8628ULL: goto x86_l_21b4;
	case 8636ULL: goto x86_l_21bc;
	case 8640ULL: goto x86_l_21c0;
	case 8644ULL: goto x86_l_21c4;
	case 8654ULL: goto x86_l_21ce;
	case 8656ULL: goto x86_l_21d0;
	case 8659ULL: goto x86_l_21d3;
	case 8664ULL: goto x86_l_21d8;
	case 8669ULL: goto x86_l_21dd;
	case 8673ULL: goto x86_l_21e1;
	case 8678ULL: goto x86_l_21e6;
	case 8680ULL: goto x86_l_21e8;
	case 8682ULL: goto x86_l_21ea;
	case 8688ULL: goto x86_l_21f0;
	case 8698ULL: goto x86_l_21fa;
	case 8704ULL: goto x86_l_2200;
	case 8712ULL: goto x86_l_2208;
	case 8716ULL: goto x86_l_220c;
	case 8720ULL: goto x86_l_2210;
	case 8730ULL: goto x86_l_221a;
	case 8732ULL: goto x86_l_221c;
	case 8735ULL: goto x86_l_221f;
	case 8740ULL: goto x86_l_2224;
	case 8745ULL: goto x86_l_2229;
	case 8749ULL: goto x86_l_222d;
	case 8754ULL: goto x86_l_2232;
	case 8756ULL: goto x86_l_2234;
	case 8758ULL: goto x86_l_2236;
	case 8764ULL: goto x86_l_223c;
	case 8769ULL: goto x86_l_2241;
	case 8779ULL: goto x86_l_224b;
	case 8785ULL: goto x86_l_2251;
	case 8793ULL: goto x86_l_2259;
	case 8797ULL: goto x86_l_225d;
	case 8801ULL: goto x86_l_2261;
	case 8811ULL: goto x86_l_226b;
	case 8817ULL: goto x86_l_2271;
	case 8820ULL: goto x86_l_2274;
	case 8825ULL: goto x86_l_2279;
	case 8830ULL: goto x86_l_227e;
	case 8835ULL: goto x86_l_2283;
	case 8838ULL: goto x86_l_2286;
	case 8840ULL: goto x86_l_2288;
	case 8843ULL: goto x86_l_228b;
	case 8848ULL: goto x86_l_2290;
	case 8853ULL: goto x86_l_2295;
	case 8857ULL: goto x86_l_2299;
	case 8862ULL: goto x86_l_229e;
	case 8864ULL: goto x86_l_22a0;
	case 8866ULL: goto x86_l_22a2;
	case 8872ULL: goto x86_l_22a8;
	case 8882ULL: goto x86_l_22b2;
	case 8888ULL: goto x86_l_22b8;
	case 8896ULL: goto x86_l_22c0;
	case 8900ULL: goto x86_l_22c4;
	case 8904ULL: goto x86_l_22c8;
	case 8914ULL: goto x86_l_22d2;
	case 8916ULL: goto x86_l_22d4;
	case 8919ULL: goto x86_l_22d7;
	case 8924ULL: goto x86_l_22dc;
	case 8929ULL: goto x86_l_22e1;
	case 8933ULL: goto x86_l_22e5;
	case 8938ULL: goto x86_l_22ea;
	case 8940ULL: goto x86_l_22ec;
	case 8942ULL: goto x86_l_22ee;
	case 8948ULL: goto x86_l_22f4;
	case 8958ULL: goto x86_l_22fe;
	case 8964ULL: goto x86_l_2304;
	case 8972ULL: goto x86_l_230c;
	case 8976ULL: goto x86_l_2310;
	case 8980ULL: goto x86_l_2314;
	case 8990ULL: goto x86_l_231e;
	case 8992ULL: goto x86_l_2320;
	case 8995ULL: goto x86_l_2323;
	case 9000ULL: goto x86_l_2328;
	case 9005ULL: goto x86_l_232d;
	case 9009ULL: goto x86_l_2331;
	case 9014ULL: goto x86_l_2336;
	case 9016ULL: goto x86_l_2338;
	case 9018ULL: goto x86_l_233a;
	case 9024ULL: goto x86_l_2340;
	case 9034ULL: goto x86_l_234a;
	case 9040ULL: goto x86_l_2350;
	case 9048ULL: goto x86_l_2358;
	case 9052ULL: goto x86_l_235c;
	case 9056ULL: goto x86_l_2360;
	case 9066ULL: goto x86_l_236a;
	case 9068ULL: goto x86_l_236c;
	case 9071ULL: goto x86_l_236f;
	case 9076ULL: goto x86_l_2374;
	case 9081ULL: goto x86_l_2379;
	case 9085ULL: goto x86_l_237d;
	case 9090ULL: goto x86_l_2382;
	case 9092ULL: goto x86_l_2384;
	case 9094ULL: goto x86_l_2386;
	case 9100ULL: goto x86_l_238c;
	case 9110ULL: goto x86_l_2396;
	case 9116ULL: goto x86_l_239c;
	case 9124ULL: goto x86_l_23a4;
	case 9128ULL: goto x86_l_23a8;
	case 9132ULL: goto x86_l_23ac;
	case 9142ULL: goto x86_l_23b6;
	case 9144ULL: goto x86_l_23b8;
	case 9147ULL: goto x86_l_23bb;
	case 9152ULL: goto x86_l_23c0;
	case 9157ULL: goto x86_l_23c5;
	case 9161ULL: goto x86_l_23c9;
	case 9166ULL: goto x86_l_23ce;
	case 9168ULL: goto x86_l_23d0;
	case 9170ULL: goto x86_l_23d2;
	case 9176ULL: goto x86_l_23d8;
	case 9186ULL: goto x86_l_23e2;
	case 9192ULL: goto x86_l_23e8;
	case 9200ULL: goto x86_l_23f0;
	case 9204ULL: goto x86_l_23f4;
	case 9208ULL: goto x86_l_23f8;
	case 9218ULL: goto x86_l_2402;
	case 9220ULL: goto x86_l_2404;
	case 9223ULL: goto x86_l_2407;
	case 9228ULL: goto x86_l_240c;
	case 9233ULL: goto x86_l_2411;
	case 9237ULL: goto x86_l_2415;
	case 9242ULL: goto x86_l_241a;
	case 9244ULL: goto x86_l_241c;
	case 9246ULL: goto x86_l_241e;
	case 9252ULL: goto x86_l_2424;
	case 9262ULL: goto x86_l_242e;
	case 9268ULL: goto x86_l_2434;
	case 9276ULL: goto x86_l_243c;
	case 9280ULL: goto x86_l_2440;
	case 9284ULL: goto x86_l_2444;
	case 9294ULL: goto x86_l_244e;
	case 9296ULL: goto x86_l_2450;
	case 9299ULL: goto x86_l_2453;
	case 9304ULL: goto x86_l_2458;
	case 9309ULL: goto x86_l_245d;
	case 9313ULL: goto x86_l_2461;
	case 9318ULL: goto x86_l_2466;
	case 9320ULL: goto x86_l_2468;
	case 9322ULL: goto x86_l_246a;
	case 9328ULL: goto x86_l_2470;
	case 9338ULL: goto x86_l_247a;
	case 9344ULL: goto x86_l_2480;
	case 9347ULL: goto x86_l_2483;
	case 9355ULL: goto x86_l_248b;
	case 9359ULL: goto x86_l_248f;
	case 9363ULL: goto x86_l_2493;
	case 9373ULL: goto x86_l_249d;
	case 9375ULL: goto x86_l_249f;
	case 9378ULL: goto x86_l_24a2;
	case 9383ULL: goto x86_l_24a7;
	case 9388ULL: goto x86_l_24ac;
	case 9392ULL: goto x86_l_24b0;
	case 9397ULL: goto x86_l_24b5;
	case 9399ULL: goto x86_l_24b7;
	case 9401ULL: goto x86_l_24b9;
	case 9407ULL: goto x86_l_24bf;
	case 9412ULL: goto x86_l_24c4;
	case 9422ULL: goto x86_l_24ce;
	case 9425ULL: goto x86_l_24d1;
	case 9431ULL: goto x86_l_24d7;
	case 9439ULL: goto x86_l_24df;
	case 9443ULL: goto x86_l_24e3;
	case 9447ULL: goto x86_l_24e7;
	case 9457ULL: goto x86_l_24f1;
	case 9459ULL: goto x86_l_24f3;
	case 9462ULL: goto x86_l_24f6;
	case 9467ULL: goto x86_l_24fb;
	case 9472ULL: goto x86_l_2500;
	case 9476ULL: goto x86_l_2504;
	case 9481ULL: goto x86_l_2509;
	case 9483ULL: goto x86_l_250b;
	case 9485ULL: goto x86_l_250d;
	case 9491ULL: goto x86_l_2513;
	case 9496ULL: goto x86_l_2518;
	case 9506ULL: goto x86_l_2522;
	case 9509ULL: goto x86_l_2525;
	case 9515ULL: goto x86_l_252b;
	case 9523ULL: goto x86_l_2533;
	case 9527ULL: goto x86_l_2537;
	case 9531ULL: goto x86_l_253b;
	case 9541ULL: goto x86_l_2545;
	case 9547ULL: goto x86_l_254b;
	case 9550ULL: goto x86_l_254e;
	case 9555ULL: goto x86_l_2553;
	case 9560ULL: goto x86_l_2558;
	case 9564ULL: goto x86_l_255c;
	case 9569ULL: goto x86_l_2561;
	case 9571ULL: goto x86_l_2563;
	case 9573ULL: goto x86_l_2565;
	case 9579ULL: goto x86_l_256b;
	case 9584ULL: goto x86_l_2570;
	case 9589ULL: goto x86_l_2575;
	case 9594ULL: goto x86_l_257a;
	case 9599ULL: goto x86_l_257f;
	case 9607ULL: goto x86_l_2587;
	case 9610ULL: goto x86_l_258a;
	case 9612ULL: goto x86_l_258c;
	case 9617ULL: goto x86_l_2591;
	case 9620ULL: goto x86_l_2594;
	case 9622ULL: goto x86_l_2596;
	case 9624ULL: goto x86_l_2598;
	case 9629ULL: goto x86_l_259d;
	case 9632ULL: goto x86_l_25a0;
	case 9634ULL: goto x86_l_25a2;
	case 9639ULL: goto x86_l_25a7;
	case 9642ULL: goto x86_l_25aa;
	case 9644ULL: goto x86_l_25ac;
	case 9646ULL: goto x86_l_25ae;
	case 9654ULL: goto x86_l_25b6;
	case 9657ULL: goto x86_l_25b9;
	case 9659ULL: goto x86_l_25bb;
	case 9664ULL: goto x86_l_25c0;
	case 9667ULL: goto x86_l_25c3;
	case 9669ULL: goto x86_l_25c5;
	case 9671ULL: goto x86_l_25c7;
	case 9676ULL: goto x86_l_25cc;
	case 9679ULL: goto x86_l_25cf;
	case 9681ULL: goto x86_l_25d1;
	case 9686ULL: goto x86_l_25d6;
	case 9689ULL: goto x86_l_25d9;
	case 9691ULL: goto x86_l_25db;
	case 9693ULL: goto x86_l_25dd;
	case 9698ULL: goto x86_l_25e2;
	case 9703ULL: goto x86_l_25e7;
	case 9708ULL: goto x86_l_25ec;
	case 9711ULL: goto x86_l_25ef;
	case 9713ULL: goto x86_l_25f1;
	case 9715ULL: goto x86_l_25f3;
	case 9720ULL: goto x86_l_25f8;
	case 9722ULL: goto x86_l_25fa;
	case 9727ULL: goto x86_l_25ff;
	case 9731ULL: goto x86_l_2603;
	case 9736ULL: goto x86_l_2608;
	case 9738ULL: goto x86_l_260a;
	case 9741ULL: goto x86_l_260d;
	case 9751ULL: goto x86_l_2617;
	case 9757ULL: goto x86_l_261d;
	case 9764ULL: goto x86_l_2624;
	case 9767ULL: goto x86_l_2627;
	case 9775ULL: goto x86_l_262f;
	case 9778ULL: goto x86_l_2632;
	case 9782ULL: goto x86_l_2636;
	case 9791ULL: goto x86_l_263f;
	case 9793ULL: goto x86_l_2641;
	case 9799ULL: goto x86_l_2647;
	case 9802ULL: goto x86_l_264a;
	case 9804ULL: goto x86_l_264c;
	case 9807ULL: goto x86_l_264f;
	case 9812ULL: goto x86_l_2654;
	case 9817ULL: goto x86_l_2659;
	case 9821ULL: goto x86_l_265d;
	case 9826ULL: goto x86_l_2662;
	case 9828ULL: goto x86_l_2664;
	case 9830ULL: goto x86_l_2666;
	case 9836ULL: goto x86_l_266c;
	case 9846ULL: goto x86_l_2676;
	case 9852ULL: goto x86_l_267c;
	case 9860ULL: goto x86_l_2684;
	case 9864ULL: goto x86_l_2688;
	case 9868ULL: goto x86_l_268c;
	case 9878ULL: goto x86_l_2696;
	case 9880ULL: goto x86_l_2698;
	case 9883ULL: goto x86_l_269b;
	case 9888ULL: goto x86_l_26a0;
	case 9893ULL: goto x86_l_26a5;
	case 9897ULL: goto x86_l_26a9;
	case 9902ULL: goto x86_l_26ae;
	case 9904ULL: goto x86_l_26b0;
	case 9906ULL: goto x86_l_26b2;
	case 9912ULL: goto x86_l_26b8;
	case 9922ULL: goto x86_l_26c2;
	case 9928ULL: goto x86_l_26c8;
	case 9936ULL: goto x86_l_26d0;
	case 9940ULL: goto x86_l_26d4;
	case 9944ULL: goto x86_l_26d8;
	case 9954ULL: goto x86_l_26e2;
	case 9956ULL: goto x86_l_26e4;
	case 9959ULL: goto x86_l_26e7;
	case 9964ULL: goto x86_l_26ec;
	case 9969ULL: goto x86_l_26f1;
	case 9973ULL: goto x86_l_26f5;
	case 9978ULL: goto x86_l_26fa;
	case 9980ULL: goto x86_l_26fc;
	case 9982ULL: goto x86_l_26fe;
	case 9988ULL: goto x86_l_2704;
	case 9998ULL: goto x86_l_270e;
	case 10004ULL: goto x86_l_2714;
	case 10012ULL: goto x86_l_271c;
	case 10016ULL: goto x86_l_2720;
	case 10020ULL: goto x86_l_2724;
	case 10030ULL: goto x86_l_272e;
	case 10032ULL: goto x86_l_2730;
	case 10035ULL: goto x86_l_2733;
	case 10040ULL: goto x86_l_2738;
	case 10045ULL: goto x86_l_273d;
	case 10049ULL: goto x86_l_2741;
	case 10054ULL: goto x86_l_2746;
	case 10056ULL: goto x86_l_2748;
	case 10058ULL: goto x86_l_274a;
	case 10064ULL: goto x86_l_2750;
	case 10074ULL: goto x86_l_275a;
	case 10080ULL: goto x86_l_2760;
	case 10088ULL: goto x86_l_2768;
	case 10092ULL: goto x86_l_276c;
	case 10096ULL: goto x86_l_2770;
	case 10106ULL: goto x86_l_277a;
	case 10108ULL: goto x86_l_277c;
	case 10111ULL: goto x86_l_277f;
	case 10116ULL: goto x86_l_2784;
	case 10121ULL: goto x86_l_2789;
	case 10125ULL: goto x86_l_278d;
	case 10130ULL: goto x86_l_2792;
	case 10132ULL: goto x86_l_2794;
	case 10134ULL: goto x86_l_2796;
	case 10140ULL: goto x86_l_279c;
	case 10150ULL: goto x86_l_27a6;
	case 10156ULL: goto x86_l_27ac;
	case 10164ULL: goto x86_l_27b4;
	case 10168ULL: goto x86_l_27b8;
	case 10172ULL: goto x86_l_27bc;
	case 10182ULL: goto x86_l_27c6;
	case 10184ULL: goto x86_l_27c8;
	case 10187ULL: goto x86_l_27cb;
	case 10192ULL: goto x86_l_27d0;
	case 10197ULL: goto x86_l_27d5;
	case 10201ULL: goto x86_l_27d9;
	case 10206ULL: goto x86_l_27de;
	case 10208ULL: goto x86_l_27e0;
	case 10210ULL: goto x86_l_27e2;
	case 10216ULL: goto x86_l_27e8;
	case 10226ULL: goto x86_l_27f2;
	case 10232ULL: goto x86_l_27f8;
	case 10240ULL: goto x86_l_2800;
	case 10244ULL: goto x86_l_2804;
	case 10248ULL: goto x86_l_2808;
	case 10258ULL: goto x86_l_2812;
	case 10260ULL: goto x86_l_2814;
	case 10263ULL: goto x86_l_2817;
	case 10268ULL: goto x86_l_281c;
	case 10273ULL: goto x86_l_2821;
	case 10277ULL: goto x86_l_2825;
	case 10282ULL: goto x86_l_282a;
	case 10284ULL: goto x86_l_282c;
	case 10286ULL: goto x86_l_282e;
	case 10292ULL: goto x86_l_2834;
	case 10302ULL: goto x86_l_283e;
	case 10308ULL: goto x86_l_2844;
	case 10316ULL: goto x86_l_284c;
	case 10320ULL: goto x86_l_2850;
	case 10324ULL: goto x86_l_2854;
	case 10334ULL: goto x86_l_285e;
	case 10336ULL: goto x86_l_2860;
	case 10339ULL: goto x86_l_2863;
	case 10344ULL: goto x86_l_2868;
	case 10349ULL: goto x86_l_286d;
	case 10353ULL: goto x86_l_2871;
	case 10358ULL: goto x86_l_2876;
	case 10360ULL: goto x86_l_2878;
	case 10362ULL: goto x86_l_287a;
	case 10368ULL: goto x86_l_2880;
	case 10378ULL: goto x86_l_288a;
	case 10384ULL: goto x86_l_2890;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2149:
	/* 0x2149: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_214e:
	/* 0x214e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2150:
	/* 0x2150: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2152:
	/* 0x2152: js     2c4c <generic_sleepable_preload+0x2c4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11340ULL;
	}
x86_l_2158:
	/* 0x2158: cmp    WORD PTR [r12+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2162:
	/* 0x2162: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_2168:
	/* 0x2168: mov    ecx,DWORD PTR [r12+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2170:
	/* 0x2170: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2174:
	/* 0x2174: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2178:
	/* 0x2178: cmp    WORD PTR [r12+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_2182:
	/* 0x2182: je     21a4 <generic_sleepable_preload+0x21a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21a4;
	}
x86_l_2184:
	/* 0x2184: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2187:
	/* 0x2187: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_218c:
	/* 0x218c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2191:
	/* 0x2191: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2195:
	/* 0x2195: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_219a:
	/* 0x219a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_219c:
	/* 0x219c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_219e:
	/* 0x219e: js     2c5d <generic_sleepable_preload+0x2c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11357ULL;
	}
x86_l_21a4:
	/* 0x21a4: cmp    WORD PTR [r12+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_21ae:
	/* 0x21ae: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_21b4:
	/* 0x21b4: mov    ecx,DWORD PTR [r12+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_21bc:
	/* 0x21bc: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_21c0:
	/* 0x21c0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21c4:
	/* 0x21c4: cmp    WORD PTR [r12+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_21ce:
	/* 0x21ce: je     21f0 <generic_sleepable_preload+0x21f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21f0;
	}
x86_l_21d0:
	/* 0x21d0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_21d3:
	/* 0x21d3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_21d8:
	/* 0x21d8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_21dd:
	/* 0x21dd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21e1:
	/* 0x21e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21e6:
	/* 0x21e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21e8:
	/* 0x21e8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21ea:
	/* 0x21ea: js     5be7 <generic_sleepable_preload+0x5be7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23527ULL;
	}
x86_l_21f0:
	/* 0x21f0: cmp    WORD PTR [r12+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_21fa:
	/* 0x21fa: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_2200:
	/* 0x2200: mov    ecx,DWORD PTR [r12+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2208:
	/* 0x2208: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_220c:
	/* 0x220c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2210:
	/* 0x2210: cmp    WORD PTR [r12+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_221a:
	/* 0x221a: je     223c <generic_sleepable_preload+0x223c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_223c;
	}
x86_l_221c:
	/* 0x221c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_221f:
	/* 0x221f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2224:
	/* 0x2224: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2229:
	/* 0x2229: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_222d:
	/* 0x222d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2232:
	/* 0x2232: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2234:
	/* 0x2234: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2236:
	/* 0x2236: js     5cd7 <generic_sleepable_preload+0x5cd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23767ULL;
	}
x86_l_223c:
	/* 0x223c: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2241:
	/* 0x2241: cmp    WORD PTR [r12+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_224b:
	/* 0x224b: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_2251:
	/* 0x2251: mov    ecx,DWORD PTR [r12+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2259:
	/* 0x2259: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_225d:
	/* 0x225d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2261:
	/* 0x2261: cmp    WORD PTR [r12+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_226b:
	/* 0x226b: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_2271:
	/* 0x2271: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2274:
	/* 0x2274: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2279:
	/* 0x2279: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_227e:
	/* 0x227e: jmp    2558 <generic_sleepable_preload+0x2558> */
	goto x86_l_2558;
x86_l_2283:
	/* 0x2283: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2286:
	/* 0x2286: je     22a8 <generic_sleepable_preload+0x22a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22a8;
	}
x86_l_2288:
	/* 0x2288: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_228b:
	/* 0x228b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2290:
	/* 0x2290: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2295:
	/* 0x2295: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2299:
	/* 0x2299: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_229e:
	/* 0x229e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22a0:
	/* 0x22a0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22a2:
	/* 0x22a2: js     2575 <generic_sleepable_preload+0x2575> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2575;
	}
x86_l_22a8:
	/* 0x22a8: cmp    WORD PTR [r12+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_22b2:
	/* 0x22b2: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_22b8:
	/* 0x22b8: mov    ecx,DWORD PTR [r12+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_22c0:
	/* 0x22c0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_22c4:
	/* 0x22c4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22c8:
	/* 0x22c8: cmp    WORD PTR [r12+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_22d2:
	/* 0x22d2: je     22f4 <generic_sleepable_preload+0x22f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22f4;
	}
x86_l_22d4:
	/* 0x22d4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_22d7:
	/* 0x22d7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_22dc:
	/* 0x22dc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_22e1:
	/* 0x22e1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22e5:
	/* 0x22e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22ea:
	/* 0x22ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22ec:
	/* 0x22ec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22ee:
	/* 0x22ee: js     25dd <generic_sleepable_preload+0x25dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_25dd;
	}
x86_l_22f4:
	/* 0x22f4: cmp    WORD PTR [r12+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_22fe:
	/* 0x22fe: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_2304:
	/* 0x2304: mov    ecx,DWORD PTR [r12+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_230c:
	/* 0x230c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2310:
	/* 0x2310: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2314:
	/* 0x2314: cmp    WORD PTR [r12+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_231e:
	/* 0x231e: je     2340 <generic_sleepable_preload+0x2340> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2340;
	}
x86_l_2320:
	/* 0x2320: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2323:
	/* 0x2323: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2328:
	/* 0x2328: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_232d:
	/* 0x232d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2331:
	/* 0x2331: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2336:
	/* 0x2336: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2338:
	/* 0x2338: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_233a:
	/* 0x233a: js     2c19 <generic_sleepable_preload+0x2c19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11289ULL;
	}
x86_l_2340:
	/* 0x2340: cmp    WORD PTR [r12+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_234a:
	/* 0x234a: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_2350:
	/* 0x2350: mov    ecx,DWORD PTR [r12+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2358:
	/* 0x2358: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_235c:
	/* 0x235c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2360:
	/* 0x2360: cmp    WORD PTR [r12+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_236a:
	/* 0x236a: je     238c <generic_sleepable_preload+0x238c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_238c;
	}
x86_l_236c:
	/* 0x236c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_236f:
	/* 0x236f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2374:
	/* 0x2374: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2379:
	/* 0x2379: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_237d:
	/* 0x237d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2382:
	/* 0x2382: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2384:
	/* 0x2384: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2386:
	/* 0x2386: js     2c2a <generic_sleepable_preload+0x2c2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11306ULL;
	}
x86_l_238c:
	/* 0x238c: cmp    WORD PTR [r12+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_2396:
	/* 0x2396: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_239c:
	/* 0x239c: mov    ecx,DWORD PTR [r12+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_23a4:
	/* 0x23a4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_23a8:
	/* 0x23a8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23ac:
	/* 0x23ac: cmp    WORD PTR [r12+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_23b6:
	/* 0x23b6: je     23d8 <generic_sleepable_preload+0x23d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23d8;
	}
x86_l_23b8:
	/* 0x23b8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_23bb:
	/* 0x23bb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23c0:
	/* 0x23c0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_23c5:
	/* 0x23c5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23c9:
	/* 0x23c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23ce:
	/* 0x23ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23d0:
	/* 0x23d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23d2:
	/* 0x23d2: js     2c3b <generic_sleepable_preload+0x2c3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11323ULL;
	}
x86_l_23d8:
	/* 0x23d8: cmp    WORD PTR [r12+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_23e2:
	/* 0x23e2: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_23e8:
	/* 0x23e8: mov    ecx,DWORD PTR [r12+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_23f0:
	/* 0x23f0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_23f4:
	/* 0x23f4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23f8:
	/* 0x23f8: cmp    WORD PTR [r12+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2402:
	/* 0x2402: je     2424 <generic_sleepable_preload+0x2424> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2424;
	}
x86_l_2404:
	/* 0x2404: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2407:
	/* 0x2407: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_240c:
	/* 0x240c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2411:
	/* 0x2411: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2415:
	/* 0x2415: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_241a:
	/* 0x241a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_241c:
	/* 0x241c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_241e:
	/* 0x241e: js     2c4c <generic_sleepable_preload+0x2c4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11340ULL;
	}
x86_l_2424:
	/* 0x2424: cmp    WORD PTR [r12+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_242e:
	/* 0x242e: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_2434:
	/* 0x2434: mov    ecx,DWORD PTR [r12+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_243c:
	/* 0x243c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2440:
	/* 0x2440: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2444:
	/* 0x2444: cmp    WORD PTR [r12+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_244e:
	/* 0x244e: je     2470 <generic_sleepable_preload+0x2470> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2470;
	}
x86_l_2450:
	/* 0x2450: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2453:
	/* 0x2453: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2458:
	/* 0x2458: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_245d:
	/* 0x245d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2461:
	/* 0x2461: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2466:
	/* 0x2466: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2468:
	/* 0x2468: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_246a:
	/* 0x246a: js     2c5d <generic_sleepable_preload+0x2c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11357ULL;
	}
x86_l_2470:
	/* 0x2470: cmp    WORD PTR [r12+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_247a:
	/* 0x247a: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_2480:
	/* 0x2480: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_2483:
	/* 0x2483: mov    ecx,DWORD PTR [r12+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_248b:
	/* 0x248b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_248f:
	/* 0x248f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2493:
	/* 0x2493: cmp    WORD PTR [r12+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_249d:
	/* 0x249d: je     24bf <generic_sleepable_preload+0x24bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24bf;
	}
x86_l_249f:
	/* 0x249f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_24a2:
	/* 0x24a2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_24a7:
	/* 0x24a7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_24ac:
	/* 0x24ac: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24b0:
	/* 0x24b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24b5:
	/* 0x24b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b7:
	/* 0x24b7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24b9:
	/* 0x24b9: js     5c65 <generic_sleepable_preload+0x5c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23653ULL;
	}
x86_l_24bf:
	/* 0x24bf: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24c4:
	/* 0x24c4: cmp    WORD PTR [r12+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_24ce:
	/* 0x24ce: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_24d1:
	/* 0x24d1: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_24d7:
	/* 0x24d7: mov    ecx,DWORD PTR [r12+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_24df:
	/* 0x24df: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_24e3:
	/* 0x24e3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24e7:
	/* 0x24e7: cmp    WORD PTR [r12+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_24f1:
	/* 0x24f1: je     2513 <generic_sleepable_preload+0x2513> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2513;
	}
x86_l_24f3:
	/* 0x24f3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_24f6:
	/* 0x24f6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_24fb:
	/* 0x24fb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2500:
	/* 0x2500: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2504:
	/* 0x2504: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2509:
	/* 0x2509: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_250b:
	/* 0x250b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_250d:
	/* 0x250d: js     5d6d <generic_sleepable_preload+0x5d6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23917ULL;
	}
x86_l_2513:
	/* 0x2513: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2518:
	/* 0x2518: cmp    WORD PTR [r12+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2522:
	/* 0x2522: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_2525:
	/* 0x2525: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_252b:
	/* 0x252b: mov    ecx,DWORD PTR [r12+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2533:
	/* 0x2533: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2537:
	/* 0x2537: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_253b:
	/* 0x253b: cmp    WORD PTR [r12+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_2545:
	/* 0x2545: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_254b:
	/* 0x254b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_254e:
	/* 0x254e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2553:
	/* 0x2553: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2558:
	/* 0x2558: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_255c:
	/* 0x255c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2561:
	/* 0x2561: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2563:
	/* 0x2563: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2565:
	/* 0x2565: jns    2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 11365ULL;
	}
x86_l_256b:
	/* 0x256b: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_2570:
	/* 0x2570: jmp    2c62 <generic_sleepable_preload+0x2c62> */
	return 11362ULL;
x86_l_2575:
	/* 0x2575: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_257a:
	/* 0x257a: jmp    2c62 <generic_sleepable_preload+0x2c62> */
	return 11362ULL;
x86_l_257f:
	/* 0x257f: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2587:
	/* 0x2587: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_258a:
	/* 0x258a: je     25ec <generic_sleepable_preload+0x25ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ec;
	}
x86_l_258c:
	/* 0x258c: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2591:
	/* 0x2591: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_2594:
	/* 0x2594: je     25ec <generic_sleepable_preload+0x25ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ec;
	}
x86_l_2596:
	/* 0x2596: jmp    25ff <generic_sleepable_preload+0x25ff> */
	goto x86_l_25ff;
x86_l_2598:
	/* 0x2598: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_259d:
	/* 0x259d: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_25a0:
	/* 0x25a0: je     25ec <generic_sleepable_preload+0x25ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ec;
	}
x86_l_25a2:
	/* 0x25a2: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_25a7:
	/* 0x25a7: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_25aa:
	/* 0x25aa: je     25ec <generic_sleepable_preload+0x25ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ec;
	}
x86_l_25ac:
	/* 0x25ac: jmp    25ff <generic_sleepable_preload+0x25ff> */
	goto x86_l_25ff;
x86_l_25ae:
	/* 0x25ae: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_25b6:
	/* 0x25b6: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_25b9:
	/* 0x25b9: je     25ec <generic_sleepable_preload+0x25ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ec;
	}
x86_l_25bb:
	/* 0x25bb: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_25c0:
	/* 0x25c0: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_25c3:
	/* 0x25c3: je     25ec <generic_sleepable_preload+0x25ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ec;
	}
x86_l_25c5:
	/* 0x25c5: jmp    25ff <generic_sleepable_preload+0x25ff> */
	goto x86_l_25ff;
x86_l_25c7:
	/* 0x25c7: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_25cc:
	/* 0x25cc: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_25cf:
	/* 0x25cf: je     25ec <generic_sleepable_preload+0x25ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ec;
	}
x86_l_25d1:
	/* 0x25d1: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25d6:
	/* 0x25d6: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_25d9:
	/* 0x25d9: je     25ec <generic_sleepable_preload+0x25ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ec;
	}
x86_l_25db:
	/* 0x25db: jmp    25ff <generic_sleepable_preload+0x25ff> */
	goto x86_l_25ff;
x86_l_25dd:
	/* 0x25dd: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_25e2:
	/* 0x25e2: jmp    2c62 <generic_sleepable_preload+0x2c62> */
	return 11362ULL;
x86_l_25e7:
	/* 0x25e7: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_25ec:
	/* 0x25ec: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_25ef:
	/* 0x25ef: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_25f1:
	/* 0x25f1: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_25f3:
	/* 0x25f3: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_25f8:
	/* 0x25f8: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_25fa:
	/* 0x25fa: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_25ff:
	/* 0x25ff: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2603:
	/* 0x2603: mov    ebp,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2608:
	/* 0x2608: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_260a:
	/* 0x260a: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_260d:
	/* 0x260d: cmp    WORD PTR [r12+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_2617:
	/* 0x2617: je     2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11504ULL;
	}
x86_l_261d:
	/* 0x261d: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_2624:
	/* 0x2624: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2627:
	/* 0x2627: mov    eax,DWORD PTR [r12+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_262f:
	/* 0x262f: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2632:
	/* 0x2632: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2636:
	/* 0x2636: movzx  eax,WORD PTR [r12+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_263f:
	/* 0x263f: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_2641:
	/* 0x2641: je     2913 <generic_sleepable_preload+0x2913> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10515ULL;
	}
x86_l_2647:
	/* 0x2647: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_264a:
	/* 0x264a: je     266c <generic_sleepable_preload+0x266c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_266c;
	}
x86_l_264c:
	/* 0x264c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_264f:
	/* 0x264f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2654:
	/* 0x2654: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2659:
	/* 0x2659: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_265d:
	/* 0x265d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2662:
	/* 0x2662: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2664:
	/* 0x2664: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2666:
	/* 0x2666: js     2c05 <generic_sleepable_preload+0x2c05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11269ULL;
	}
x86_l_266c:
	/* 0x266c: cmp    WORD PTR [r12+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_2676:
	/* 0x2676: je     2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11504ULL;
	}
x86_l_267c:
	/* 0x267c: mov    ecx,DWORD PTR [r12+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2684:
	/* 0x2684: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2688:
	/* 0x2688: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_268c:
	/* 0x268c: cmp    WORD PTR [r12+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_2696:
	/* 0x2696: je     26b8 <generic_sleepable_preload+0x26b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26b8;
	}
x86_l_2698:
	/* 0x2698: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_269b:
	/* 0x269b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26a0:
	/* 0x26a0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26a5:
	/* 0x26a5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26a9:
	/* 0x26a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26ae:
	/* 0x26ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26b0:
	/* 0x26b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26b2:
	/* 0x26b2: js     2c0f <generic_sleepable_preload+0x2c0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11279ULL;
	}
x86_l_26b8:
	/* 0x26b8: cmp    WORD PTR [r12+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_26c2:
	/* 0x26c2: je     2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11504ULL;
	}
x86_l_26c8:
	/* 0x26c8: mov    ecx,DWORD PTR [r12+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_26d0:
	/* 0x26d0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_26d4:
	/* 0x26d4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26d8:
	/* 0x26d8: cmp    WORD PTR [r12+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_26e2:
	/* 0x26e2: je     2704 <generic_sleepable_preload+0x2704> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2704;
	}
x86_l_26e4:
	/* 0x26e4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_26e7:
	/* 0x26e7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26ec:
	/* 0x26ec: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26f1:
	/* 0x26f1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26f5:
	/* 0x26f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26fa:
	/* 0x26fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26fc:
	/* 0x26fc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26fe:
	/* 0x26fe: js     2c20 <generic_sleepable_preload+0x2c20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11296ULL;
	}
x86_l_2704:
	/* 0x2704: cmp    WORD PTR [r12+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_270e:
	/* 0x270e: je     2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11504ULL;
	}
x86_l_2714:
	/* 0x2714: mov    ecx,DWORD PTR [r12+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_271c:
	/* 0x271c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2720:
	/* 0x2720: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2724:
	/* 0x2724: cmp    WORD PTR [r12+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_272e:
	/* 0x272e: je     2750 <generic_sleepable_preload+0x2750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2750;
	}
x86_l_2730:
	/* 0x2730: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2733:
	/* 0x2733: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2738:
	/* 0x2738: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_273d:
	/* 0x273d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2741:
	/* 0x2741: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2746:
	/* 0x2746: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2748:
	/* 0x2748: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_274a:
	/* 0x274a: js     2c31 <generic_sleepable_preload+0x2c31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11313ULL;
	}
x86_l_2750:
	/* 0x2750: cmp    WORD PTR [r12+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_275a:
	/* 0x275a: je     2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11504ULL;
	}
x86_l_2760:
	/* 0x2760: mov    ecx,DWORD PTR [r12+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2768:
	/* 0x2768: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_276c:
	/* 0x276c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2770:
	/* 0x2770: cmp    WORD PTR [r12+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_277a:
	/* 0x277a: je     279c <generic_sleepable_preload+0x279c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_279c;
	}
x86_l_277c:
	/* 0x277c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_277f:
	/* 0x277f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2784:
	/* 0x2784: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2789:
	/* 0x2789: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_278d:
	/* 0x278d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2792:
	/* 0x2792: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2794:
	/* 0x2794: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2796:
	/* 0x2796: js     2c42 <generic_sleepable_preload+0x2c42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11330ULL;
	}
x86_l_279c:
	/* 0x279c: cmp    WORD PTR [r12+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_27a6:
	/* 0x27a6: je     2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11504ULL;
	}
x86_l_27ac:
	/* 0x27ac: mov    ecx,DWORD PTR [r12+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_27b4:
	/* 0x27b4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_27b8:
	/* 0x27b8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27bc:
	/* 0x27bc: cmp    WORD PTR [r12+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_27c6:
	/* 0x27c6: je     27e8 <generic_sleepable_preload+0x27e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e8;
	}
x86_l_27c8:
	/* 0x27c8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_27cb:
	/* 0x27cb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_27d0:
	/* 0x27d0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_27d5:
	/* 0x27d5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27d9:
	/* 0x27d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27de:
	/* 0x27de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27e0:
	/* 0x27e0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27e2:
	/* 0x27e2: js     2c53 <generic_sleepable_preload+0x2c53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11347ULL;
	}
x86_l_27e8:
	/* 0x27e8: cmp    WORD PTR [r12+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_27f2:
	/* 0x27f2: je     2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11504ULL;
	}
x86_l_27f8:
	/* 0x27f8: mov    ecx,DWORD PTR [r12+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2800:
	/* 0x2800: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2804:
	/* 0x2804: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2808:
	/* 0x2808: cmp    WORD PTR [r12+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_2812:
	/* 0x2812: je     2834 <generic_sleepable_preload+0x2834> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2834;
	}
x86_l_2814:
	/* 0x2814: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2817:
	/* 0x2817: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_281c:
	/* 0x281c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2821:
	/* 0x2821: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2825:
	/* 0x2825: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_282a:
	/* 0x282a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_282c:
	/* 0x282c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_282e:
	/* 0x282e: js     2ce8 <generic_sleepable_preload+0x2ce8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11496ULL;
	}
x86_l_2834:
	/* 0x2834: cmp    WORD PTR [r12+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_283e:
	/* 0x283e: je     2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11504ULL;
	}
x86_l_2844:
	/* 0x2844: mov    ecx,DWORD PTR [r12+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_284c:
	/* 0x284c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2850:
	/* 0x2850: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2854:
	/* 0x2854: cmp    WORD PTR [r12+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_285e:
	/* 0x285e: je     2880 <generic_sleepable_preload+0x2880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2880;
	}
x86_l_2860:
	/* 0x2860: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2863:
	/* 0x2863: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2868:
	/* 0x2868: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_286d:
	/* 0x286d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2871:
	/* 0x2871: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2876:
	/* 0x2876: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2878:
	/* 0x2878: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_287a:
	/* 0x287a: js     5bf4 <generic_sleepable_preload+0x5bf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23540ULL;
	}
x86_l_2880:
	/* 0x2880: cmp    WORD PTR [r12+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_288a:
	/* 0x288a: je     2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11504ULL;
	}
x86_l_2890:
	/* 0x2890: mov    ecx,DWORD PTR [r12+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
	return 10392ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10392ULL: goto x86_l_2898;
	case 10396ULL: goto x86_l_289c;
	case 10400ULL: goto x86_l_28a0;
	case 10410ULL: goto x86_l_28aa;
	case 10412ULL: goto x86_l_28ac;
	case 10415ULL: goto x86_l_28af;
	case 10420ULL: goto x86_l_28b4;
	case 10425ULL: goto x86_l_28b9;
	case 10429ULL: goto x86_l_28bd;
	case 10434ULL: goto x86_l_28c2;
	case 10436ULL: goto x86_l_28c4;
	case 10438ULL: goto x86_l_28c6;
	case 10444ULL: goto x86_l_28cc;
	case 10449ULL: goto x86_l_28d1;
	case 10459ULL: goto x86_l_28db;
	case 10465ULL: goto x86_l_28e1;
	case 10473ULL: goto x86_l_28e9;
	case 10477ULL: goto x86_l_28ed;
	case 10481ULL: goto x86_l_28f1;
	case 10491ULL: goto x86_l_28fb;
	case 10497ULL: goto x86_l_2901;
	case 10500ULL: goto x86_l_2904;
	case 10505ULL: goto x86_l_2909;
	case 10510ULL: goto x86_l_290e;
	case 10515ULL: goto x86_l_2913;
	case 10518ULL: goto x86_l_2916;
	case 10520ULL: goto x86_l_2918;
	case 10523ULL: goto x86_l_291b;
	case 10528ULL: goto x86_l_2920;
	case 10533ULL: goto x86_l_2925;
	case 10537ULL: goto x86_l_2929;
	case 10542ULL: goto x86_l_292e;
	case 10544ULL: goto x86_l_2930;
	case 10546ULL: goto x86_l_2932;
	case 10552ULL: goto x86_l_2938;
	case 10562ULL: goto x86_l_2942;
	case 10568ULL: goto x86_l_2948;
	case 10576ULL: goto x86_l_2950;
	case 10580ULL: goto x86_l_2954;
	case 10584ULL: goto x86_l_2958;
	case 10594ULL: goto x86_l_2962;
	case 10596ULL: goto x86_l_2964;
	case 10599ULL: goto x86_l_2967;
	case 10604ULL: goto x86_l_296c;
	case 10609ULL: goto x86_l_2971;
	case 10613ULL: goto x86_l_2975;
	case 10618ULL: goto x86_l_297a;
	case 10620ULL: goto x86_l_297c;
	case 10622ULL: goto x86_l_297e;
	case 10628ULL: goto x86_l_2984;
	case 10638ULL: goto x86_l_298e;
	case 10644ULL: goto x86_l_2994;
	case 10652ULL: goto x86_l_299c;
	case 10656ULL: goto x86_l_29a0;
	case 10660ULL: goto x86_l_29a4;
	case 10670ULL: goto x86_l_29ae;
	case 10672ULL: goto x86_l_29b0;
	case 10675ULL: goto x86_l_29b3;
	case 10680ULL: goto x86_l_29b8;
	case 10685ULL: goto x86_l_29bd;
	case 10689ULL: goto x86_l_29c1;
	case 10694ULL: goto x86_l_29c6;
	case 10696ULL: goto x86_l_29c8;
	case 10698ULL: goto x86_l_29ca;
	case 10704ULL: goto x86_l_29d0;
	case 10714ULL: goto x86_l_29da;
	case 10720ULL: goto x86_l_29e0;
	case 10728ULL: goto x86_l_29e8;
	case 10732ULL: goto x86_l_29ec;
	case 10736ULL: goto x86_l_29f0;
	case 10746ULL: goto x86_l_29fa;
	case 10748ULL: goto x86_l_29fc;
	case 10751ULL: goto x86_l_29ff;
	case 10756ULL: goto x86_l_2a04;
	case 10761ULL: goto x86_l_2a09;
	case 10765ULL: goto x86_l_2a0d;
	case 10770ULL: goto x86_l_2a12;
	case 10772ULL: goto x86_l_2a14;
	case 10774ULL: goto x86_l_2a16;
	case 10780ULL: goto x86_l_2a1c;
	case 10790ULL: goto x86_l_2a26;
	case 10796ULL: goto x86_l_2a2c;
	case 10804ULL: goto x86_l_2a34;
	case 10808ULL: goto x86_l_2a38;
	case 10812ULL: goto x86_l_2a3c;
	case 10822ULL: goto x86_l_2a46;
	case 10824ULL: goto x86_l_2a48;
	case 10827ULL: goto x86_l_2a4b;
	case 10832ULL: goto x86_l_2a50;
	case 10837ULL: goto x86_l_2a55;
	case 10841ULL: goto x86_l_2a59;
	case 10846ULL: goto x86_l_2a5e;
	case 10848ULL: goto x86_l_2a60;
	case 10850ULL: goto x86_l_2a62;
	case 10856ULL: goto x86_l_2a68;
	case 10866ULL: goto x86_l_2a72;
	case 10872ULL: goto x86_l_2a78;
	case 10880ULL: goto x86_l_2a80;
	case 10884ULL: goto x86_l_2a84;
	case 10888ULL: goto x86_l_2a88;
	case 10898ULL: goto x86_l_2a92;
	case 10900ULL: goto x86_l_2a94;
	case 10903ULL: goto x86_l_2a97;
	case 10908ULL: goto x86_l_2a9c;
	case 10913ULL: goto x86_l_2aa1;
	case 10917ULL: goto x86_l_2aa5;
	case 10922ULL: goto x86_l_2aaa;
	case 10924ULL: goto x86_l_2aac;
	case 10926ULL: goto x86_l_2aae;
	case 10932ULL: goto x86_l_2ab4;
	case 10942ULL: goto x86_l_2abe;
	case 10948ULL: goto x86_l_2ac4;
	case 10956ULL: goto x86_l_2acc;
	case 10960ULL: goto x86_l_2ad0;
	case 10964ULL: goto x86_l_2ad4;
	case 10974ULL: goto x86_l_2ade;
	case 10976ULL: goto x86_l_2ae0;
	case 10979ULL: goto x86_l_2ae3;
	case 10984ULL: goto x86_l_2ae8;
	case 10989ULL: goto x86_l_2aed;
	case 10993ULL: goto x86_l_2af1;
	case 10998ULL: goto x86_l_2af6;
	case 11000ULL: goto x86_l_2af8;
	case 11002ULL: goto x86_l_2afa;
	case 11008ULL: goto x86_l_2b00;
	case 11018ULL: goto x86_l_2b0a;
	case 11024ULL: goto x86_l_2b10;
	case 11027ULL: goto x86_l_2b13;
	case 11035ULL: goto x86_l_2b1b;
	case 11039ULL: goto x86_l_2b1f;
	case 11043ULL: goto x86_l_2b23;
	case 11053ULL: goto x86_l_2b2d;
	case 11055ULL: goto x86_l_2b2f;
	case 11058ULL: goto x86_l_2b32;
	case 11063ULL: goto x86_l_2b37;
	case 11068ULL: goto x86_l_2b3c;
	case 11072ULL: goto x86_l_2b40;
	case 11077ULL: goto x86_l_2b45;
	case 11079ULL: goto x86_l_2b47;
	case 11081ULL: goto x86_l_2b49;
	case 11087ULL: goto x86_l_2b4f;
	case 11092ULL: goto x86_l_2b54;
	case 11102ULL: goto x86_l_2b5e;
	case 11105ULL: goto x86_l_2b61;
	case 11111ULL: goto x86_l_2b67;
	case 11119ULL: goto x86_l_2b6f;
	case 11123ULL: goto x86_l_2b73;
	case 11127ULL: goto x86_l_2b77;
	case 11137ULL: goto x86_l_2b81;
	case 11139ULL: goto x86_l_2b83;
	case 11142ULL: goto x86_l_2b86;
	case 11147ULL: goto x86_l_2b8b;
	case 11152ULL: goto x86_l_2b90;
	case 11156ULL: goto x86_l_2b94;
	case 11161ULL: goto x86_l_2b99;
	case 11163ULL: goto x86_l_2b9b;
	case 11165ULL: goto x86_l_2b9d;
	case 11171ULL: goto x86_l_2ba3;
	case 11176ULL: goto x86_l_2ba8;
	case 11186ULL: goto x86_l_2bb2;
	case 11189ULL: goto x86_l_2bb5;
	case 11195ULL: goto x86_l_2bbb;
	case 11203ULL: goto x86_l_2bc3;
	case 11207ULL: goto x86_l_2bc7;
	case 11211ULL: goto x86_l_2bcb;
	case 11221ULL: goto x86_l_2bd5;
	case 11227ULL: goto x86_l_2bdb;
	case 11230ULL: goto x86_l_2bde;
	case 11235ULL: goto x86_l_2be3;
	case 11240ULL: goto x86_l_2be8;
	case 11244ULL: goto x86_l_2bec;
	case 11249ULL: goto x86_l_2bf1;
	case 11251ULL: goto x86_l_2bf3;
	case 11253ULL: goto x86_l_2bf5;
	case 11259ULL: goto x86_l_2bfb;
	case 11264ULL: goto x86_l_2c00;
	case 11269ULL: goto x86_l_2c05;
	case 11274ULL: goto x86_l_2c0a;
	case 11279ULL: goto x86_l_2c0f;
	case 11284ULL: goto x86_l_2c14;
	case 11289ULL: goto x86_l_2c19;
	case 11294ULL: goto x86_l_2c1e;
	case 11296ULL: goto x86_l_2c20;
	case 11301ULL: goto x86_l_2c25;
	case 11306ULL: goto x86_l_2c2a;
	case 11311ULL: goto x86_l_2c2f;
	case 11313ULL: goto x86_l_2c31;
	case 11318ULL: goto x86_l_2c36;
	case 11323ULL: goto x86_l_2c3b;
	case 11328ULL: goto x86_l_2c40;
	case 11330ULL: goto x86_l_2c42;
	case 11335ULL: goto x86_l_2c47;
	case 11340ULL: goto x86_l_2c4c;
	case 11345ULL: goto x86_l_2c51;
	case 11347ULL: goto x86_l_2c53;
	case 11352ULL: goto x86_l_2c58;
	case 11357ULL: goto x86_l_2c5d;
	case 11362ULL: goto x86_l_2c62;
	case 11365ULL: goto x86_l_2c65;
	case 11370ULL: goto x86_l_2c6a;
	case 11373ULL: goto x86_l_2c6d;
	case 11378ULL: goto x86_l_2c72;
	case 11383ULL: goto x86_l_2c77;
	case 11388ULL: goto x86_l_2c7c;
	case 11391ULL: goto x86_l_2c7f;
	case 11393ULL: goto x86_l_2c81;
	case 11396ULL: goto x86_l_2c84;
	case 11402ULL: goto x86_l_2c8a;
	case 11405ULL: goto x86_l_2c8d;
	case 11409ULL: goto x86_l_2c91;
	case 11414ULL: goto x86_l_2c96;
	case 11416ULL: goto x86_l_2c98;
	case 11421ULL: goto x86_l_2c9d;
	case 11429ULL: goto x86_l_2ca5;
	case 11436ULL: goto x86_l_2cac;
	case 11441ULL: goto x86_l_2cb1;
	case 11446ULL: goto x86_l_2cb6;
	case 11448ULL: goto x86_l_2cb8;
	case 11451ULL: goto x86_l_2cbb;
	case 11457ULL: goto x86_l_2cc1;
	case 11460ULL: goto x86_l_2cc4;
	case 11467ULL: goto x86_l_2ccb;
	case 11469ULL: goto x86_l_2ccd;
	case 11474ULL: goto x86_l_2cd2;
	case 11479ULL: goto x86_l_2cd7;
	case 11482ULL: goto x86_l_2cda;
	case 11485ULL: goto x86_l_2cdd;
	case 11487ULL: goto x86_l_2cdf;
	case 11489ULL: goto x86_l_2ce1;
	case 11494ULL: goto x86_l_2ce6;
	case 11496ULL: goto x86_l_2ce8;
	case 11501ULL: goto x86_l_2ced;
	case 11504ULL: goto x86_l_2cf0;
	case 11507ULL: goto x86_l_2cf3;
	case 11513ULL: goto x86_l_2cf9;
	case 11516ULL: goto x86_l_2cfc;
	case 11520ULL: goto x86_l_2d00;
	case 11525ULL: goto x86_l_2d05;
	case 11527ULL: goto x86_l_2d07;
	case 11532ULL: goto x86_l_2d0c;
	case 11540ULL: goto x86_l_2d14;
	case 11547ULL: goto x86_l_2d1b;
	case 11552ULL: goto x86_l_2d20;
	case 11557ULL: goto x86_l_2d25;
	case 11559ULL: goto x86_l_2d27;
	case 11562ULL: goto x86_l_2d2a;
	case 11564ULL: goto x86_l_2d2c;
	case 11567ULL: goto x86_l_2d2f;
	case 11574ULL: goto x86_l_2d36;
	case 11576ULL: goto x86_l_2d38;
	case 11581ULL: goto x86_l_2d3d;
	case 11586ULL: goto x86_l_2d42;
	case 11589ULL: goto x86_l_2d45;
	case 11592ULL: goto x86_l_2d48;
	case 11594ULL: goto x86_l_2d4a;
	case 11596ULL: goto x86_l_2d4c;
	case 11601ULL: goto x86_l_2d51;
	case 11604ULL: goto x86_l_2d54;
	case 11607ULL: goto x86_l_2d57;
	case 11612ULL: goto x86_l_2d5c;
	case 11614ULL: goto x86_l_2d5e;
	case 11617ULL: goto x86_l_2d61;
	case 11619ULL: goto x86_l_2d63;
	case 11622ULL: goto x86_l_2d66;
	case 11624ULL: goto x86_l_2d68;
	case 11627ULL: goto x86_l_2d6b;
	case 11631ULL: goto x86_l_2d6f;
	case 11636ULL: goto x86_l_2d74;
	case 11639ULL: goto x86_l_2d77;
	case 11641ULL: goto x86_l_2d79;
	case 11644ULL: goto x86_l_2d7c;
	case 11649ULL: goto x86_l_2d81;
	case 11651ULL: goto x86_l_2d83;
	case 11654ULL: goto x86_l_2d86;
	case 11656ULL: goto x86_l_2d88;
	case 11661ULL: goto x86_l_2d8d;
	case 11664ULL: goto x86_l_2d90;
	case 11666ULL: goto x86_l_2d92;
	case 11669ULL: goto x86_l_2d95;
	case 11674ULL: goto x86_l_2d9a;
	case 11679ULL: goto x86_l_2d9f;
	case 11685ULL: goto x86_l_2da5;
	case 11687ULL: goto x86_l_2da7;
	case 11689ULL: goto x86_l_2da9;
	case 11694ULL: goto x86_l_2dae;
	case 11697ULL: goto x86_l_2db1;
	case 11703ULL: goto x86_l_2db7;
	case 11706ULL: goto x86_l_2dba;
	case 11712ULL: goto x86_l_2dc0;
	case 11715ULL: goto x86_l_2dc3;
	case 11721ULL: goto x86_l_2dc9;
	case 11724ULL: goto x86_l_2dcc;
	case 11730ULL: goto x86_l_2dd2;
	case 11735ULL: goto x86_l_2dd7;
	case 11740ULL: goto x86_l_2ddc;
	case 11749ULL: goto x86_l_2de5;
	case 11758ULL: goto x86_l_2dee;
	case 11764ULL: goto x86_l_2df4;
	case 11766ULL: goto x86_l_2df6;
	case 11769ULL: goto x86_l_2df9;
	case 11771ULL: goto x86_l_2dfb;
	case 11774ULL: goto x86_l_2dfe;
	case 11776ULL: goto x86_l_2e00;
	case 11779ULL: goto x86_l_2e03;
	case 11785ULL: goto x86_l_2e09;
	case 11790ULL: goto x86_l_2e0e;
	case 11793ULL: goto x86_l_2e11;
	case 11799ULL: goto x86_l_2e17;
	case 11804ULL: goto x86_l_2e1c;
	case 11807ULL: goto x86_l_2e1f;
	case 11813ULL: goto x86_l_2e25;
	case 11818ULL: goto x86_l_2e2a;
	case 11821ULL: goto x86_l_2e2d;
	case 11827ULL: goto x86_l_2e33;
	case 11832ULL: goto x86_l_2e38;
	case 11835ULL: goto x86_l_2e3b;
	case 11837ULL: goto x86_l_2e3d;
	case 11840ULL: goto x86_l_2e40;
	case 11846ULL: goto x86_l_2e46;
	case 11848ULL: goto x86_l_2e48;
	case 11854ULL: goto x86_l_2e4e;
	case 11857ULL: goto x86_l_2e51;
	case 11860ULL: goto x86_l_2e54;
	case 11866ULL: goto x86_l_2e5a;
	case 11871ULL: goto x86_l_2e5f;
	case 11873ULL: goto x86_l_2e61;
	case 11875ULL: goto x86_l_2e63;
	case 11878ULL: goto x86_l_2e66;
	case 11880ULL: goto x86_l_2e68;
	case 11885ULL: goto x86_l_2e6d;
	case 11887ULL: goto x86_l_2e6f;
	case 11890ULL: goto x86_l_2e72;
	case 11896ULL: goto x86_l_2e78;
	case 11904ULL: goto x86_l_2e80;
	case 11907ULL: goto x86_l_2e83;
	case 11913ULL: goto x86_l_2e89;
	case 11918ULL: goto x86_l_2e8e;
	case 11921ULL: goto x86_l_2e91;
	case 11927ULL: goto x86_l_2e97;
	case 11932ULL: goto x86_l_2e9c;
	case 11935ULL: goto x86_l_2e9f;
	case 11941ULL: goto x86_l_2ea5;
	case 11949ULL: goto x86_l_2ead;
	case 11952ULL: goto x86_l_2eb0;
	case 11958ULL: goto x86_l_2eb6;
	case 11963ULL: goto x86_l_2ebb;
	case 11966ULL: goto x86_l_2ebe;
	case 11972ULL: goto x86_l_2ec4;
	case 11977ULL: goto x86_l_2ec9;
	case 11982ULL: goto x86_l_2ece;
	case 11984ULL: goto x86_l_2ed0;
	case 11989ULL: goto x86_l_2ed5;
	case 11991ULL: goto x86_l_2ed7;
	case 11996ULL: goto x86_l_2edc;
	case 11999ULL: goto x86_l_2edf;
	case 12003ULL: goto x86_l_2ee3;
	case 12005ULL: goto x86_l_2ee5;
	case 12008ULL: goto x86_l_2ee8;
	case 12018ULL: goto x86_l_2ef2;
	case 12024ULL: goto x86_l_2ef8;
	case 12031ULL: goto x86_l_2eff;
	case 12034ULL: goto x86_l_2f02;
	case 12042ULL: goto x86_l_2f0a;
	case 12045ULL: goto x86_l_2f0d;
	case 12049ULL: goto x86_l_2f11;
	case 12058ULL: goto x86_l_2f1a;
	case 12060ULL: goto x86_l_2f1c;
	case 12066ULL: goto x86_l_2f22;
	case 12069ULL: goto x86_l_2f25;
	case 12071ULL: goto x86_l_2f27;
	case 12074ULL: goto x86_l_2f2a;
	case 12079ULL: goto x86_l_2f2f;
	case 12084ULL: goto x86_l_2f34;
	case 12088ULL: goto x86_l_2f38;
	case 12093ULL: goto x86_l_2f3d;
	case 12095ULL: goto x86_l_2f3f;
	case 12097ULL: goto x86_l_2f41;
	case 12103ULL: goto x86_l_2f47;
	case 12113ULL: goto x86_l_2f51;
	case 12119ULL: goto x86_l_2f57;
	case 12127ULL: goto x86_l_2f5f;
	case 12131ULL: goto x86_l_2f63;
	case 12135ULL: goto x86_l_2f67;
	case 12145ULL: goto x86_l_2f71;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2898:
	/* 0x2898: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_289c:
	/* 0x289c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28a0:
	/* 0x28a0: cmp    WORD PTR [r12+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_28aa:
	/* 0x28aa: je     28cc <generic_sleepable_preload+0x28cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28cc;
	}
x86_l_28ac:
	/* 0x28ac: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_28af:
	/* 0x28af: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_28b4:
	/* 0x28b4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_28b9:
	/* 0x28b9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
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
	/* 0x28c6: js     5ce9 <generic_sleepable_preload+0x5ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23785ULL;
	}
x86_l_28cc:
	/* 0x28cc: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28d1:
	/* 0x28d1: cmp    WORD PTR [r12+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_28db:
	/* 0x28db: je     2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf0;
	}
x86_l_28e1:
	/* 0x28e1: mov    ecx,DWORD PTR [r12+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_28e9:
	/* 0x28e9: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_28ed:
	/* 0x28ed: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28f1:
	/* 0x28f1: cmp    WORD PTR [r12+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_28fb:
	/* 0x28fb: je     2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf0;
	}
x86_l_2901:
	/* 0x2901: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2904:
	/* 0x2904: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2909:
	/* 0x2909: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_290e:
	/* 0x290e: jmp    2be8 <generic_sleepable_preload+0x2be8> */
	goto x86_l_2be8;
x86_l_2913:
	/* 0x2913: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2916:
	/* 0x2916: je     2938 <generic_sleepable_preload+0x2938> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2938;
	}
x86_l_2918:
	/* 0x2918: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_291b:
	/* 0x291b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2920:
	/* 0x2920: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2925:
	/* 0x2925: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2929:
	/* 0x2929: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_292e:
	/* 0x292e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2930:
	/* 0x2930: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2932:
	/* 0x2932: js     2c05 <generic_sleepable_preload+0x2c05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c05;
	}
x86_l_2938:
	/* 0x2938: cmp    WORD PTR [r12+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_2942:
	/* 0x2942: je     2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf0;
	}
x86_l_2948:
	/* 0x2948: mov    ecx,DWORD PTR [r12+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2950:
	/* 0x2950: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2954:
	/* 0x2954: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2958:
	/* 0x2958: cmp    WORD PTR [r12+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_2962:
	/* 0x2962: je     2984 <generic_sleepable_preload+0x2984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2984;
	}
x86_l_2964:
	/* 0x2964: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2967:
	/* 0x2967: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_296c:
	/* 0x296c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2971:
	/* 0x2971: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2975:
	/* 0x2975: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_297a:
	/* 0x297a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_297c:
	/* 0x297c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_297e:
	/* 0x297e: js     2c0f <generic_sleepable_preload+0x2c0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c0f;
	}
x86_l_2984:
	/* 0x2984: cmp    WORD PTR [r12+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_298e:
	/* 0x298e: je     2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf0;
	}
x86_l_2994:
	/* 0x2994: mov    ecx,DWORD PTR [r12+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_299c:
	/* 0x299c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_29a0:
	/* 0x29a0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29a4:
	/* 0x29a4: cmp    WORD PTR [r12+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_29ae:
	/* 0x29ae: je     29d0 <generic_sleepable_preload+0x29d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29d0;
	}
x86_l_29b0:
	/* 0x29b0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29b3:
	/* 0x29b3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_29b8:
	/* 0x29b8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_29bd:
	/* 0x29bd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29c1:
	/* 0x29c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29c6:
	/* 0x29c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29c8:
	/* 0x29c8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29ca:
	/* 0x29ca: js     2c20 <generic_sleepable_preload+0x2c20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c20;
	}
x86_l_29d0:
	/* 0x29d0: cmp    WORD PTR [r12+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_29da:
	/* 0x29da: je     2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf0;
	}
x86_l_29e0:
	/* 0x29e0: mov    ecx,DWORD PTR [r12+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_29e8:
	/* 0x29e8: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_29ec:
	/* 0x29ec: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29f0:
	/* 0x29f0: cmp    WORD PTR [r12+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_29fa:
	/* 0x29fa: je     2a1c <generic_sleepable_preload+0x2a1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a1c;
	}
x86_l_29fc:
	/* 0x29fc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29ff:
	/* 0x29ff: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a04:
	/* 0x2a04: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a09:
	/* 0x2a09: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a0d:
	/* 0x2a0d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a12:
	/* 0x2a12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a14:
	/* 0x2a14: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a16:
	/* 0x2a16: js     2c31 <generic_sleepable_preload+0x2c31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c31;
	}
x86_l_2a1c:
	/* 0x2a1c: cmp    WORD PTR [r12+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_2a26:
	/* 0x2a26: je     2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf0;
	}
x86_l_2a2c:
	/* 0x2a2c: mov    ecx,DWORD PTR [r12+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2a34:
	/* 0x2a34: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a38:
	/* 0x2a38: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a3c:
	/* 0x2a3c: cmp    WORD PTR [r12+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_2a46:
	/* 0x2a46: je     2a68 <generic_sleepable_preload+0x2a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a68;
	}
x86_l_2a48:
	/* 0x2a48: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a4b:
	/* 0x2a4b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a50:
	/* 0x2a50: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a55:
	/* 0x2a55: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a59:
	/* 0x2a59: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a5e:
	/* 0x2a5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a60:
	/* 0x2a60: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a62:
	/* 0x2a62: js     2c42 <generic_sleepable_preload+0x2c42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c42;
	}
x86_l_2a68:
	/* 0x2a68: cmp    WORD PTR [r12+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_2a72:
	/* 0x2a72: je     2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf0;
	}
x86_l_2a78:
	/* 0x2a78: mov    ecx,DWORD PTR [r12+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2a80:
	/* 0x2a80: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a84:
	/* 0x2a84: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a88:
	/* 0x2a88: cmp    WORD PTR [r12+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2a92:
	/* 0x2a92: je     2ab4 <generic_sleepable_preload+0x2ab4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ab4;
	}
x86_l_2a94:
	/* 0x2a94: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a97:
	/* 0x2a97: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a9c:
	/* 0x2a9c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2aa1:
	/* 0x2aa1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2aa5:
	/* 0x2aa5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2aaa:
	/* 0x2aaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aac:
	/* 0x2aac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2aae:
	/* 0x2aae: js     2c53 <generic_sleepable_preload+0x2c53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c53;
	}
x86_l_2ab4:
	/* 0x2ab4: cmp    WORD PTR [r12+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2abe:
	/* 0x2abe: je     2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf0;
	}
x86_l_2ac4:
	/* 0x2ac4: mov    ecx,DWORD PTR [r12+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2acc:
	/* 0x2acc: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2ad0:
	/* 0x2ad0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ad4:
	/* 0x2ad4: cmp    WORD PTR [r12+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_2ade:
	/* 0x2ade: je     2b00 <generic_sleepable_preload+0x2b00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b00;
	}
x86_l_2ae0:
	/* 0x2ae0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ae3:
	/* 0x2ae3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ae8:
	/* 0x2ae8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2aed:
	/* 0x2aed: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2af1:
	/* 0x2af1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2af6:
	/* 0x2af6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2af8:
	/* 0x2af8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2afa:
	/* 0x2afa: js     2ce8 <generic_sleepable_preload+0x2ce8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2ce8;
	}
x86_l_2b00:
	/* 0x2b00: cmp    WORD PTR [r12+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_2b0a:
	/* 0x2b0a: je     2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf0;
	}
x86_l_2b10:
	/* 0x2b10: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_2b13:
	/* 0x2b13: mov    ecx,DWORD PTR [r12+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2b1b:
	/* 0x2b1b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2b1f:
	/* 0x2b1f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b23:
	/* 0x2b23: cmp    WORD PTR [r12+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2b2d:
	/* 0x2b2d: je     2b4f <generic_sleepable_preload+0x2b4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b4f;
	}
x86_l_2b2f:
	/* 0x2b2f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b32:
	/* 0x2b32: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b37:
	/* 0x2b37: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b3c:
	/* 0x2b3c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b40:
	/* 0x2b40: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b45:
	/* 0x2b45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b47:
	/* 0x2b47: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b49:
	/* 0x2b49: js     5c72 <generic_sleepable_preload+0x5c72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23666ULL;
	}
x86_l_2b4f:
	/* 0x2b4f: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b54:
	/* 0x2b54: cmp    WORD PTR [r12+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2b5e:
	/* 0x2b5e: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_2b61:
	/* 0x2b61: je     2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf0;
	}
x86_l_2b67:
	/* 0x2b67: mov    ecx,DWORD PTR [r12+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2b6f:
	/* 0x2b6f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2b73:
	/* 0x2b73: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b77:
	/* 0x2b77: cmp    WORD PTR [r12+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_2b81:
	/* 0x2b81: je     2ba3 <generic_sleepable_preload+0x2ba3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ba3;
	}
x86_l_2b83:
	/* 0x2b83: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b86:
	/* 0x2b86: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b8b:
	/* 0x2b8b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b90:
	/* 0x2b90: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b94:
	/* 0x2b94: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b99:
	/* 0x2b99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b9b:
	/* 0x2b9b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b9d:
	/* 0x2b9d: js     5d82 <generic_sleepable_preload+0x5d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23938ULL;
	}
x86_l_2ba3:
	/* 0x2ba3: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ba8:
	/* 0x2ba8: cmp    WORD PTR [r12+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2bb2:
	/* 0x2bb2: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_2bb5:
	/* 0x2bb5: je     2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf0;
	}
x86_l_2bbb:
	/* 0x2bbb: mov    ecx,DWORD PTR [r12+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2bc3:
	/* 0x2bc3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2bc7:
	/* 0x2bc7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bcb:
	/* 0x2bcb: cmp    WORD PTR [r12+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_2bd5:
	/* 0x2bd5: je     2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf0;
	}
x86_l_2bdb:
	/* 0x2bdb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2bde:
	/* 0x2bde: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2be3:
	/* 0x2be3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2be8:
	/* 0x2be8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bec:
	/* 0x2bec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bf1:
	/* 0x2bf1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf3:
	/* 0x2bf3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bf5:
	/* 0x2bf5: jns    2cf0 <generic_sleepable_preload+0x2cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_2cf0;
	}
x86_l_2bfb:
	/* 0x2bfb: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_2c00:
	/* 0x2c00: jmp    2ced <generic_sleepable_preload+0x2ced> */
	goto x86_l_2ced;
x86_l_2c05:
	/* 0x2c05: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2c0a:
	/* 0x2c0a: jmp    2ced <generic_sleepable_preload+0x2ced> */
	goto x86_l_2ced;
x86_l_2c0f:
	/* 0x2c0f: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_2c14:
	/* 0x2c14: jmp    2ced <generic_sleepable_preload+0x2ced> */
	goto x86_l_2ced;
x86_l_2c19:
	/* 0x2c19: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_2c1e:
	/* 0x2c1e: jmp    2c62 <generic_sleepable_preload+0x2c62> */
	goto x86_l_2c62;
x86_l_2c20:
	/* 0x2c20: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_2c25:
	/* 0x2c25: jmp    2ced <generic_sleepable_preload+0x2ced> */
	goto x86_l_2ced;
x86_l_2c2a:
	/* 0x2c2a: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2c2f:
	/* 0x2c2f: jmp    2c62 <generic_sleepable_preload+0x2c62> */
	goto x86_l_2c62;
x86_l_2c31:
	/* 0x2c31: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2c36:
	/* 0x2c36: jmp    2ced <generic_sleepable_preload+0x2ced> */
	goto x86_l_2ced;
x86_l_2c3b:
	/* 0x2c3b: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2c40:
	/* 0x2c40: jmp    2c62 <generic_sleepable_preload+0x2c62> */
	goto x86_l_2c62;
x86_l_2c42:
	/* 0x2c42: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2c47:
	/* 0x2c47: jmp    2ced <generic_sleepable_preload+0x2ced> */
	goto x86_l_2ced;
x86_l_2c4c:
	/* 0x2c4c: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2c51:
	/* 0x2c51: jmp    2c62 <generic_sleepable_preload+0x2c62> */
	goto x86_l_2c62;
x86_l_2c53:
	/* 0x2c53: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2c58:
	/* 0x2c58: jmp    2ced <generic_sleepable_preload+0x2ced> */
	goto x86_l_2ced;
x86_l_2c5d:
	/* 0x2c5d: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_2c62:
	/* 0x2c62: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c65:
	/* 0x2c65: mov    ebp,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c6a:
	/* 0x2c6a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2c6d:
	/* 0x2c6d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c72:
	/* 0x2c72: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c77:
	/* 0x2c77: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c7c:
	/* 0x2c7c: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2c7f:
	/* 0x2c7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c81:
	/* 0x2c81: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_2c84:
	/* 0x2c84: jne    2d95 <generic_sleepable_preload+0x2d95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d95;
	}
x86_l_2c8a:
	/* 0x2c8a: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_2c8d:
	/* 0x2c8d: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c91:
	/* 0x2c91: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2c96:
	/* 0x2c96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c98:
	/* 0x2c98: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c9d:
	/* 0x2c9d: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2ca5:
	/* 0x2ca5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2cac:
	/* 0x2cac: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2cb1:
	/* 0x2cb1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cb6:
	/* 0x2cb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cb8:
	/* 0x2cb8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cbb:
	/* 0x2cbb: je     2d92 <generic_sleepable_preload+0x2d92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d92;
	}
x86_l_2cc1:
	/* 0x2cc1: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2cc4:
	/* 0x2cc4: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2ccb:
	/* 0x2ccb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ccd:
	/* 0x2ccd: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cd2:
	/* 0x2cd2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2cd7:
	/* 0x2cd7: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2cda:
	/* 0x2cda: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2cdd:
	/* 0x2cdd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cdf:
	/* 0x2cdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ce1:
	/* 0x2ce1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ce6:
	/* 0x2ce6: jmp    2d51 <generic_sleepable_preload+0x2d51> */
	goto x86_l_2d51;
x86_l_2ce8:
	/* 0x2ce8: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_2ced:
	/* 0x2ced: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cf0:
	/* 0x2cf0: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_2cf3:
	/* 0x2cf3: jne    2d95 <generic_sleepable_preload+0x2d95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d95;
	}
x86_l_2cf9:
	/* 0x2cf9: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_2cfc:
	/* 0x2cfc: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d00:
	/* 0x2d00: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2d05:
	/* 0x2d05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d07:
	/* 0x2d07: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d0c:
	/* 0x2d0c: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2d14:
	/* 0x2d14: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2d1b:
	/* 0x2d1b: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2d20:
	/* 0x2d20: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d25:
	/* 0x2d25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d27:
	/* 0x2d27: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d2a:
	/* 0x2d2a: je     2d92 <generic_sleepable_preload+0x2d92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d92;
	}
x86_l_2d2c:
	/* 0x2d2c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2d2f:
	/* 0x2d2f: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2d36:
	/* 0x2d36: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d38:
	/* 0x2d38: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d3d:
	/* 0x2d3d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d42:
	/* 0x2d42: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2d45:
	/* 0x2d45: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2d48:
	/* 0x2d48: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d4a:
	/* 0x2d4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d4c:
	/* 0x2d4c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d51:
	/* 0x2d51: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2d54:
	/* 0x2d54: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2d57:
	/* 0x2d57: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d5c:
	/* 0x2d5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d5e:
	/* 0x2d5e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d61:
	/* 0x2d61: je     2d92 <generic_sleepable_preload+0x2d92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d92;
	}
x86_l_2d63:
	/* 0x2d63: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_2d66:
	/* 0x2d66: je     2d90 <generic_sleepable_preload+0x2d90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d90;
	}
x86_l_2d68:
	/* 0x2d68: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2d6b:
	/* 0x2d6b: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2d6f:
	/* 0x2d6f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2d74:
	/* 0x2d74: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2d77:
	/* 0x2d77: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d79:
	/* 0x2d79: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_2d7c:
	/* 0x2d7c: call   2d81 <generic_sleepable_preload+0x2d81> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_2d81:
	/* 0x2d81: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2d83:
	/* 0x2d83: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_2d86:
	/* 0x2d86: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2d88:
	/* 0x2d88: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2d8d:
	/* 0x2d8d: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_2d90:
	/* 0x2d90: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d92:
	/* 0x2d92: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_2d95:
	/* 0x2d95: mov    eax,DWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d9a:
	/* 0x2d9a: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_2d9f:
	/* 0x2d9f: je     3d00 <generic_sleepable_preload+0x3d00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15616ULL;
	}
x86_l_2da5:
	/* 0x2da5: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2da7:
	/* 0x2da7: js     2ddc <generic_sleepable_preload+0x2ddc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2ddc;
	}
x86_l_2da9:
	/* 0x2da9: mov    eax,DWORD PTR [r12+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2dae:
	/* 0x2dae: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2db1:
	/* 0x2db1: jle    2e5f <generic_sleepable_preload+0x2e5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e5f;
	}
x86_l_2db7:
	/* 0x2db7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2dba:
	/* 0x2dba: je     2ec9 <generic_sleepable_preload+0x2ec9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ec9;
	}
x86_l_2dc0:
	/* 0x2dc0: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2dc3:
	/* 0x2dc3: je     2ed0 <generic_sleepable_preload+0x2ed0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ed0;
	}
x86_l_2dc9:
	/* 0x2dc9: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2dcc:
	/* 0x2dcc: jne    2ee3 <generic_sleepable_preload+0x2ee3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ee3;
	}
x86_l_2dd2:
	/* 0x2dd2: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2dd7:
	/* 0x2dd7: jmp    2edc <generic_sleepable_preload+0x2edc> */
	goto x86_l_2edc;
x86_l_2ddc:
	/* 0x2ddc: movzx  eax,BYTE PTR [r12+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_2de5:
	/* 0x2de5: movzx  ecx,WORD PTR [r12+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
x86_l_2dee:
	/* 0x2dee: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_2df4:
	/* 0x2df4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2df6:
	/* 0x2df6: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_2df9:
	/* 0x2df9: jle    2e38 <generic_sleepable_preload+0x2e38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e38;
	}
x86_l_2dfb:
	/* 0x2dfb: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_2dfe:
	/* 0x2dfe: jle    2e6f <generic_sleepable_preload+0x2e6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e6f;
	}
x86_l_2e00:
	/* 0x2e00: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2e03:
	/* 0x2e03: jle    3532 <generic_sleepable_preload+0x3532> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 13618ULL;
	}
x86_l_2e09:
	/* 0x2e09: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e0e:
	/* 0x2e0e: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_2e11:
	/* 0x2e11: je     3557 <generic_sleepable_preload+0x3557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13655ULL;
	}
x86_l_2e17:
	/* 0x2e17: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2e1c:
	/* 0x2e1c: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_2e1f:
	/* 0x2e1f: je     3557 <generic_sleepable_preload+0x3557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13655ULL;
	}
x86_l_2e25:
	/* 0x2e25: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2e2a:
	/* 0x2e2a: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_2e2d:
	/* 0x2e2d: je     3557 <generic_sleepable_preload+0x3557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13655ULL;
	}
x86_l_2e33:
	/* 0x2e33: jmp    356a <generic_sleepable_preload+0x356a> */
	return 13674ULL;
x86_l_2e38:
	/* 0x2e38: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2e3b:
	/* 0x2e3b: jg     2e9c <generic_sleepable_preload+0x2e9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2e9c;
	}
x86_l_2e3d:
	/* 0x2e3d: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2e40:
	/* 0x2e40: jg     3503 <generic_sleepable_preload+0x3503> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 13571ULL;
	}
x86_l_2e46:
	/* 0x2e46: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2e48:
	/* 0x2e48: je     3552 <generic_sleepable_preload+0x3552> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13650ULL;
	}
x86_l_2e4e:
	/* 0x2e4e: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2e51:
	/* 0x2e51: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2e54:
	/* 0x2e54: je     3557 <generic_sleepable_preload+0x3557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13655ULL;
	}
x86_l_2e5a:
	/* 0x2e5a: jmp    356a <generic_sleepable_preload+0x356a> */
	return 13674ULL;
x86_l_2e5f:
	/* 0x2e5f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e61:
	/* 0x2e61: je     2ed7 <generic_sleepable_preload+0x2ed7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ed7;
	}
x86_l_2e63:
	/* 0x2e63: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e66:
	/* 0x2e66: jne    2ee3 <generic_sleepable_preload+0x2ee3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ee3;
	}
x86_l_2e68:
	/* 0x2e68: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e6d:
	/* 0x2e6d: jmp    2edc <generic_sleepable_preload+0x2edc> */
	goto x86_l_2edc;
x86_l_2e6f:
	/* 0x2e6f: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_2e72:
	/* 0x2e72: jg     34ea <generic_sleepable_preload+0x34ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 13546ULL;
	}
x86_l_2e78:
	/* 0x2e78: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2e80:
	/* 0x2e80: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e83:
	/* 0x2e83: je     3557 <generic_sleepable_preload+0x3557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13655ULL;
	}
x86_l_2e89:
	/* 0x2e89: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e8e:
	/* 0x2e8e: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_2e91:
	/* 0x2e91: je     3557 <generic_sleepable_preload+0x3557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13655ULL;
	}
x86_l_2e97:
	/* 0x2e97: jmp    356a <generic_sleepable_preload+0x356a> */
	return 13674ULL;
x86_l_2e9c:
	/* 0x2e9c: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_2e9f:
	/* 0x2e9f: jg     3519 <generic_sleepable_preload+0x3519> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 13593ULL;
	}
x86_l_2ea5:
	/* 0x2ea5: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2ead:
	/* 0x2ead: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2eb0:
	/* 0x2eb0: je     3557 <generic_sleepable_preload+0x3557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13655ULL;
	}
x86_l_2eb6:
	/* 0x2eb6: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2ebb:
	/* 0x2ebb: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_2ebe:
	/* 0x2ebe: je     3557 <generic_sleepable_preload+0x3557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13655ULL;
	}
x86_l_2ec4:
	/* 0x2ec4: jmp    356a <generic_sleepable_preload+0x356a> */
	return 13674ULL;
x86_l_2ec9:
	/* 0x2ec9: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ece:
	/* 0x2ece: jmp    2edc <generic_sleepable_preload+0x2edc> */
	goto x86_l_2edc;
x86_l_2ed0:
	/* 0x2ed0: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ed5:
	/* 0x2ed5: jmp    2edc <generic_sleepable_preload+0x2edc> */
	goto x86_l_2edc;
x86_l_2ed7:
	/* 0x2ed7: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2edc:
	/* 0x2edc: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2edf:
	/* 0x2edf: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ee3:
	/* 0x2ee3: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ee5:
	/* 0x2ee5: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_2ee8:
	/* 0x2ee8: cmp    WORD PTR [r12+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_2ef2:
	/* 0x2ef2: je     3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15312ULL;
	}
x86_l_2ef8:
	/* 0x2ef8: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_2eff:
	/* 0x2eff: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2f02:
	/* 0x2f02: mov    eax,DWORD PTR [r12+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2f0a:
	/* 0x2f0a: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f0d:
	/* 0x2f0d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f11:
	/* 0x2f11: movzx  eax,WORD PTR [r12+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_2f1a:
	/* 0x2f1a: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_2f1c:
	/* 0x2f1c: je     31ee <generic_sleepable_preload+0x31ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12782ULL;
	}
x86_l_2f22:
	/* 0x2f22: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2f25:
	/* 0x2f25: je     2f47 <generic_sleepable_preload+0x2f47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f47;
	}
x86_l_2f27:
	/* 0x2f27: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2f2a:
	/* 0x2f2a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f2f:
	/* 0x2f2f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2f34:
	/* 0x2f34: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f38:
	/* 0x2f38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f3d:
	/* 0x2f3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f3f:
	/* 0x2f3f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f41:
	/* 0x2f41: js     34e0 <generic_sleepable_preload+0x34e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13536ULL;
	}
x86_l_2f47:
	/* 0x2f47: cmp    WORD PTR [r12+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_2f51:
	/* 0x2f51: je     3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15312ULL;
	}
x86_l_2f57:
	/* 0x2f57: mov    ecx,DWORD PTR [r12+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2f5f:
	/* 0x2f5f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2f63:
	/* 0x2f63: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f67:
	/* 0x2f67: cmp    WORD PTR [r12+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_2f71:
	/* 0x2f71: je     2f93 <generic_sleepable_preload+0x2f93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12179ULL;
	}
	return 12147ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12147ULL: goto x86_l_2f73;
	case 12150ULL: goto x86_l_2f76;
	case 12155ULL: goto x86_l_2f7b;
	case 12160ULL: goto x86_l_2f80;
	case 12164ULL: goto x86_l_2f84;
	case 12169ULL: goto x86_l_2f89;
	case 12171ULL: goto x86_l_2f8b;
	case 12173ULL: goto x86_l_2f8d;
	case 12179ULL: goto x86_l_2f93;
	case 12189ULL: goto x86_l_2f9d;
	case 12195ULL: goto x86_l_2fa3;
	case 12203ULL: goto x86_l_2fab;
	case 12207ULL: goto x86_l_2faf;
	case 12211ULL: goto x86_l_2fb3;
	case 12221ULL: goto x86_l_2fbd;
	case 12223ULL: goto x86_l_2fbf;
	case 12226ULL: goto x86_l_2fc2;
	case 12231ULL: goto x86_l_2fc7;
	case 12236ULL: goto x86_l_2fcc;
	case 12240ULL: goto x86_l_2fd0;
	case 12245ULL: goto x86_l_2fd5;
	case 12247ULL: goto x86_l_2fd7;
	case 12249ULL: goto x86_l_2fd9;
	case 12255ULL: goto x86_l_2fdf;
	case 12265ULL: goto x86_l_2fe9;
	case 12271ULL: goto x86_l_2fef;
	case 12279ULL: goto x86_l_2ff7;
	case 12283ULL: goto x86_l_2ffb;
	case 12287ULL: goto x86_l_2fff;
	case 12297ULL: goto x86_l_3009;
	case 12299ULL: goto x86_l_300b;
	case 12302ULL: goto x86_l_300e;
	case 12307ULL: goto x86_l_3013;
	case 12312ULL: goto x86_l_3018;
	case 12316ULL: goto x86_l_301c;
	case 12321ULL: goto x86_l_3021;
	case 12323ULL: goto x86_l_3023;
	case 12325ULL: goto x86_l_3025;
	case 12331ULL: goto x86_l_302b;
	case 12341ULL: goto x86_l_3035;
	case 12347ULL: goto x86_l_303b;
	case 12355ULL: goto x86_l_3043;
	case 12359ULL: goto x86_l_3047;
	case 12363ULL: goto x86_l_304b;
	case 12373ULL: goto x86_l_3055;
	case 12375ULL: goto x86_l_3057;
	case 12378ULL: goto x86_l_305a;
	case 12383ULL: goto x86_l_305f;
	case 12388ULL: goto x86_l_3064;
	case 12392ULL: goto x86_l_3068;
	case 12397ULL: goto x86_l_306d;
	case 12399ULL: goto x86_l_306f;
	case 12401ULL: goto x86_l_3071;
	case 12407ULL: goto x86_l_3077;
	case 12417ULL: goto x86_l_3081;
	case 12423ULL: goto x86_l_3087;
	case 12431ULL: goto x86_l_308f;
	case 12435ULL: goto x86_l_3093;
	case 12439ULL: goto x86_l_3097;
	case 12449ULL: goto x86_l_30a1;
	case 12451ULL: goto x86_l_30a3;
	case 12454ULL: goto x86_l_30a6;
	case 12459ULL: goto x86_l_30ab;
	case 12464ULL: goto x86_l_30b0;
	case 12468ULL: goto x86_l_30b4;
	case 12473ULL: goto x86_l_30b9;
	case 12475ULL: goto x86_l_30bb;
	case 12477ULL: goto x86_l_30bd;
	case 12483ULL: goto x86_l_30c3;
	case 12493ULL: goto x86_l_30cd;
	case 12499ULL: goto x86_l_30d3;
	case 12507ULL: goto x86_l_30db;
	case 12511ULL: goto x86_l_30df;
	case 12515ULL: goto x86_l_30e3;
	case 12525ULL: goto x86_l_30ed;
	case 12527ULL: goto x86_l_30ef;
	case 12530ULL: goto x86_l_30f2;
	case 12535ULL: goto x86_l_30f7;
	case 12540ULL: goto x86_l_30fc;
	case 12544ULL: goto x86_l_3100;
	case 12549ULL: goto x86_l_3105;
	case 12551ULL: goto x86_l_3107;
	case 12553ULL: goto x86_l_3109;
	case 12559ULL: goto x86_l_310f;
	case 12569ULL: goto x86_l_3119;
	case 12575ULL: goto x86_l_311f;
	case 12583ULL: goto x86_l_3127;
	case 12587ULL: goto x86_l_312b;
	case 12591ULL: goto x86_l_312f;
	case 12601ULL: goto x86_l_3139;
	case 12603ULL: goto x86_l_313b;
	case 12606ULL: goto x86_l_313e;
	case 12611ULL: goto x86_l_3143;
	case 12616ULL: goto x86_l_3148;
	case 12620ULL: goto x86_l_314c;
	case 12625ULL: goto x86_l_3151;
	case 12627ULL: goto x86_l_3153;
	case 12629ULL: goto x86_l_3155;
	case 12635ULL: goto x86_l_315b;
	case 12645ULL: goto x86_l_3165;
	case 12651ULL: goto x86_l_316b;
	case 12659ULL: goto x86_l_3173;
	case 12663ULL: goto x86_l_3177;
	case 12667ULL: goto x86_l_317b;
	case 12677ULL: goto x86_l_3185;
	case 12679ULL: goto x86_l_3187;
	case 12682ULL: goto x86_l_318a;
	case 12687ULL: goto x86_l_318f;
	case 12692ULL: goto x86_l_3194;
	case 12696ULL: goto x86_l_3198;
	case 12701ULL: goto x86_l_319d;
	case 12703ULL: goto x86_l_319f;
	case 12705ULL: goto x86_l_31a1;
	case 12711ULL: goto x86_l_31a7;
	case 12716ULL: goto x86_l_31ac;
	case 12726ULL: goto x86_l_31b6;
	case 12732ULL: goto x86_l_31bc;
	case 12740ULL: goto x86_l_31c4;
	case 12744ULL: goto x86_l_31c8;
	case 12748ULL: goto x86_l_31cc;
	case 12758ULL: goto x86_l_31d6;
	case 12764ULL: goto x86_l_31dc;
	case 12767ULL: goto x86_l_31df;
	case 12772ULL: goto x86_l_31e4;
	case 12777ULL: goto x86_l_31e9;
	case 12782ULL: goto x86_l_31ee;
	case 12785ULL: goto x86_l_31f1;
	case 12787ULL: goto x86_l_31f3;
	case 12790ULL: goto x86_l_31f6;
	case 12795ULL: goto x86_l_31fb;
	case 12800ULL: goto x86_l_3200;
	case 12804ULL: goto x86_l_3204;
	case 12809ULL: goto x86_l_3209;
	case 12811ULL: goto x86_l_320b;
	case 12813ULL: goto x86_l_320d;
	case 12819ULL: goto x86_l_3213;
	case 12829ULL: goto x86_l_321d;
	case 12835ULL: goto x86_l_3223;
	case 12843ULL: goto x86_l_322b;
	case 12847ULL: goto x86_l_322f;
	case 12851ULL: goto x86_l_3233;
	case 12861ULL: goto x86_l_323d;
	case 12863ULL: goto x86_l_323f;
	case 12866ULL: goto x86_l_3242;
	case 12871ULL: goto x86_l_3247;
	case 12876ULL: goto x86_l_324c;
	case 12880ULL: goto x86_l_3250;
	case 12885ULL: goto x86_l_3255;
	case 12887ULL: goto x86_l_3257;
	case 12889ULL: goto x86_l_3259;
	case 12895ULL: goto x86_l_325f;
	case 12905ULL: goto x86_l_3269;
	case 12911ULL: goto x86_l_326f;
	case 12919ULL: goto x86_l_3277;
	case 12923ULL: goto x86_l_327b;
	case 12927ULL: goto x86_l_327f;
	case 12937ULL: goto x86_l_3289;
	case 12939ULL: goto x86_l_328b;
	case 12942ULL: goto x86_l_328e;
	case 12947ULL: goto x86_l_3293;
	case 12952ULL: goto x86_l_3298;
	case 12956ULL: goto x86_l_329c;
	case 12961ULL: goto x86_l_32a1;
	case 12963ULL: goto x86_l_32a3;
	case 12965ULL: goto x86_l_32a5;
	case 12971ULL: goto x86_l_32ab;
	case 12981ULL: goto x86_l_32b5;
	case 12987ULL: goto x86_l_32bb;
	case 12995ULL: goto x86_l_32c3;
	case 12999ULL: goto x86_l_32c7;
	case 13003ULL: goto x86_l_32cb;
	case 13013ULL: goto x86_l_32d5;
	case 13015ULL: goto x86_l_32d7;
	case 13018ULL: goto x86_l_32da;
	case 13023ULL: goto x86_l_32df;
	case 13028ULL: goto x86_l_32e4;
	case 13032ULL: goto x86_l_32e8;
	case 13037ULL: goto x86_l_32ed;
	case 13039ULL: goto x86_l_32ef;
	case 13041ULL: goto x86_l_32f1;
	case 13047ULL: goto x86_l_32f7;
	case 13057ULL: goto x86_l_3301;
	case 13063ULL: goto x86_l_3307;
	case 13071ULL: goto x86_l_330f;
	case 13075ULL: goto x86_l_3313;
	case 13079ULL: goto x86_l_3317;
	case 13089ULL: goto x86_l_3321;
	case 13091ULL: goto x86_l_3323;
	case 13094ULL: goto x86_l_3326;
	case 13099ULL: goto x86_l_332b;
	case 13104ULL: goto x86_l_3330;
	case 13108ULL: goto x86_l_3334;
	case 13113ULL: goto x86_l_3339;
	case 13115ULL: goto x86_l_333b;
	case 13117ULL: goto x86_l_333d;
	case 13123ULL: goto x86_l_3343;
	case 13133ULL: goto x86_l_334d;
	case 13139ULL: goto x86_l_3353;
	case 13147ULL: goto x86_l_335b;
	case 13151ULL: goto x86_l_335f;
	case 13155ULL: goto x86_l_3363;
	case 13165ULL: goto x86_l_336d;
	case 13167ULL: goto x86_l_336f;
	case 13170ULL: goto x86_l_3372;
	case 13175ULL: goto x86_l_3377;
	case 13180ULL: goto x86_l_337c;
	case 13184ULL: goto x86_l_3380;
	case 13189ULL: goto x86_l_3385;
	case 13191ULL: goto x86_l_3387;
	case 13193ULL: goto x86_l_3389;
	case 13199ULL: goto x86_l_338f;
	case 13209ULL: goto x86_l_3399;
	case 13215ULL: goto x86_l_339f;
	case 13223ULL: goto x86_l_33a7;
	case 13227ULL: goto x86_l_33ab;
	case 13231ULL: goto x86_l_33af;
	case 13241ULL: goto x86_l_33b9;
	case 13243ULL: goto x86_l_33bb;
	case 13246ULL: goto x86_l_33be;
	case 13251ULL: goto x86_l_33c3;
	case 13256ULL: goto x86_l_33c8;
	case 13260ULL: goto x86_l_33cc;
	case 13265ULL: goto x86_l_33d1;
	case 13267ULL: goto x86_l_33d3;
	case 13269ULL: goto x86_l_33d5;
	case 13275ULL: goto x86_l_33db;
	case 13285ULL: goto x86_l_33e5;
	case 13291ULL: goto x86_l_33eb;
	case 13294ULL: goto x86_l_33ee;
	case 13302ULL: goto x86_l_33f6;
	case 13306ULL: goto x86_l_33fa;
	case 13310ULL: goto x86_l_33fe;
	case 13320ULL: goto x86_l_3408;
	case 13322ULL: goto x86_l_340a;
	case 13325ULL: goto x86_l_340d;
	case 13330ULL: goto x86_l_3412;
	case 13335ULL: goto x86_l_3417;
	case 13339ULL: goto x86_l_341b;
	case 13344ULL: goto x86_l_3420;
	case 13346ULL: goto x86_l_3422;
	case 13348ULL: goto x86_l_3424;
	case 13354ULL: goto x86_l_342a;
	case 13359ULL: goto x86_l_342f;
	case 13369ULL: goto x86_l_3439;
	case 13372ULL: goto x86_l_343c;
	case 13378ULL: goto x86_l_3442;
	case 13386ULL: goto x86_l_344a;
	case 13390ULL: goto x86_l_344e;
	case 13394ULL: goto x86_l_3452;
	case 13404ULL: goto x86_l_345c;
	case 13406ULL: goto x86_l_345e;
	case 13409ULL: goto x86_l_3461;
	case 13414ULL: goto x86_l_3466;
	case 13419ULL: goto x86_l_346b;
	case 13423ULL: goto x86_l_346f;
	case 13428ULL: goto x86_l_3474;
	case 13430ULL: goto x86_l_3476;
	case 13432ULL: goto x86_l_3478;
	case 13438ULL: goto x86_l_347e;
	case 13443ULL: goto x86_l_3483;
	case 13453ULL: goto x86_l_348d;
	case 13456ULL: goto x86_l_3490;
	case 13462ULL: goto x86_l_3496;
	case 13470ULL: goto x86_l_349e;
	case 13474ULL: goto x86_l_34a2;
	case 13478ULL: goto x86_l_34a6;
	case 13488ULL: goto x86_l_34b0;
	case 13494ULL: goto x86_l_34b6;
	case 13497ULL: goto x86_l_34b9;
	case 13502ULL: goto x86_l_34be;
	case 13507ULL: goto x86_l_34c3;
	case 13511ULL: goto x86_l_34c7;
	case 13516ULL: goto x86_l_34cc;
	case 13518ULL: goto x86_l_34ce;
	case 13520ULL: goto x86_l_34d0;
	case 13526ULL: goto x86_l_34d6;
	case 13531ULL: goto x86_l_34db;
	case 13536ULL: goto x86_l_34e0;
	case 13541ULL: goto x86_l_34e5;
	case 13546ULL: goto x86_l_34ea;
	case 13554ULL: goto x86_l_34f2;
	case 13557ULL: goto x86_l_34f5;
	case 13559ULL: goto x86_l_34f7;
	case 13564ULL: goto x86_l_34fc;
	case 13567ULL: goto x86_l_34ff;
	case 13569ULL: goto x86_l_3501;
	case 13571ULL: goto x86_l_3503;
	case 13576ULL: goto x86_l_3508;
	case 13579ULL: goto x86_l_350b;
	case 13581ULL: goto x86_l_350d;
	case 13586ULL: goto x86_l_3512;
	case 13589ULL: goto x86_l_3515;
	case 13591ULL: goto x86_l_3517;
	case 13593ULL: goto x86_l_3519;
	case 13601ULL: goto x86_l_3521;
	case 13604ULL: goto x86_l_3524;
	case 13606ULL: goto x86_l_3526;
	case 13611ULL: goto x86_l_352b;
	case 13614ULL: goto x86_l_352e;
	case 13616ULL: goto x86_l_3530;
	case 13618ULL: goto x86_l_3532;
	case 13623ULL: goto x86_l_3537;
	case 13626ULL: goto x86_l_353a;
	case 13628ULL: goto x86_l_353c;
	case 13633ULL: goto x86_l_3541;
	case 13636ULL: goto x86_l_3544;
	case 13638ULL: goto x86_l_3546;
	case 13640ULL: goto x86_l_3548;
	case 13645ULL: goto x86_l_354d;
	case 13650ULL: goto x86_l_3552;
	case 13655ULL: goto x86_l_3557;
	case 13658ULL: goto x86_l_355a;
	case 13660ULL: goto x86_l_355c;
	case 13662ULL: goto x86_l_355e;
	case 13667ULL: goto x86_l_3563;
	case 13669ULL: goto x86_l_3565;
	case 13674ULL: goto x86_l_356a;
	case 13678ULL: goto x86_l_356e;
	case 13683ULL: goto x86_l_3573;
	case 13685ULL: goto x86_l_3575;
	case 13688ULL: goto x86_l_3578;
	case 13698ULL: goto x86_l_3582;
	case 13704ULL: goto x86_l_3588;
	case 13711ULL: goto x86_l_358f;
	case 13714ULL: goto x86_l_3592;
	case 13722ULL: goto x86_l_359a;
	case 13725ULL: goto x86_l_359d;
	case 13729ULL: goto x86_l_35a1;
	case 13738ULL: goto x86_l_35aa;
	case 13740ULL: goto x86_l_35ac;
	case 13746ULL: goto x86_l_35b2;
	case 13749ULL: goto x86_l_35b5;
	case 13751ULL: goto x86_l_35b7;
	case 13754ULL: goto x86_l_35ba;
	case 13759ULL: goto x86_l_35bf;
	case 13764ULL: goto x86_l_35c4;
	case 13768ULL: goto x86_l_35c8;
	case 13773ULL: goto x86_l_35cd;
	case 13775ULL: goto x86_l_35cf;
	case 13777ULL: goto x86_l_35d1;
	case 13783ULL: goto x86_l_35d7;
	case 13793ULL: goto x86_l_35e1;
	case 13799ULL: goto x86_l_35e7;
	case 13807ULL: goto x86_l_35ef;
	case 13811ULL: goto x86_l_35f3;
	case 13815ULL: goto x86_l_35f7;
	case 13825ULL: goto x86_l_3601;
	case 13827ULL: goto x86_l_3603;
	case 13830ULL: goto x86_l_3606;
	case 13835ULL: goto x86_l_360b;
	case 13840ULL: goto x86_l_3610;
	case 13844ULL: goto x86_l_3614;
	case 13849ULL: goto x86_l_3619;
	case 13851ULL: goto x86_l_361b;
	case 13853ULL: goto x86_l_361d;
	case 13859ULL: goto x86_l_3623;
	case 13869ULL: goto x86_l_362d;
	case 13875ULL: goto x86_l_3633;
	case 13883ULL: goto x86_l_363b;
	case 13887ULL: goto x86_l_363f;
	case 13891ULL: goto x86_l_3643;
	case 13901ULL: goto x86_l_364d;
	case 13903ULL: goto x86_l_364f;
	case 13906ULL: goto x86_l_3652;
	case 13911ULL: goto x86_l_3657;
	case 13916ULL: goto x86_l_365c;
	case 13920ULL: goto x86_l_3660;
	case 13925ULL: goto x86_l_3665;
	case 13927ULL: goto x86_l_3667;
	case 13929ULL: goto x86_l_3669;
	case 13935ULL: goto x86_l_366f;
	case 13945ULL: goto x86_l_3679;
	case 13951ULL: goto x86_l_367f;
	case 13959ULL: goto x86_l_3687;
	case 13963ULL: goto x86_l_368b;
	case 13967ULL: goto x86_l_368f;
	case 13977ULL: goto x86_l_3699;
	case 13979ULL: goto x86_l_369b;
	case 13982ULL: goto x86_l_369e;
	case 13987ULL: goto x86_l_36a3;
	case 13992ULL: goto x86_l_36a8;
	case 13996ULL: goto x86_l_36ac;
	case 14001ULL: goto x86_l_36b1;
	case 14003ULL: goto x86_l_36b3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2f73:
	/* 0x2f73: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2f76:
	/* 0x2f76: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f7b:
	/* 0x2f7b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2f80:
	/* 0x2f80: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f84:
	/* 0x2f84: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f89:
	/* 0x2f89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f8b:
	/* 0x2f8b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f8d:
	/* 0x2f8d: js     3548 <generic_sleepable_preload+0x3548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3548;
	}
x86_l_2f93:
	/* 0x2f93: cmp    WORD PTR [r12+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_2f9d:
	/* 0x2f9d: je     3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15312ULL;
	}
x86_l_2fa3:
	/* 0x2fa3: mov    ecx,DWORD PTR [r12+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2fab:
	/* 0x2fab: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2faf:
	/* 0x2faf: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fb3:
	/* 0x2fb3: cmp    WORD PTR [r12+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_2fbd:
	/* 0x2fbd: je     2fdf <generic_sleepable_preload+0x2fdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fdf;
	}
x86_l_2fbf:
	/* 0x2fbf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2fc2:
	/* 0x2fc2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2fc7:
	/* 0x2fc7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2fcc:
	/* 0x2fcc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fd0:
	/* 0x2fd0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fd5:
	/* 0x2fd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fd7:
	/* 0x2fd7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fd9:
	/* 0x2fd9: js     3b84 <generic_sleepable_preload+0x3b84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15236ULL;
	}
x86_l_2fdf:
	/* 0x2fdf: cmp    WORD PTR [r12+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_2fe9:
	/* 0x2fe9: je     3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15312ULL;
	}
x86_l_2fef:
	/* 0x2fef: mov    ecx,DWORD PTR [r12+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_2ff7:
	/* 0x2ff7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2ffb:
	/* 0x2ffb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fff:
	/* 0x2fff: cmp    WORD PTR [r12+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_3009:
	/* 0x3009: je     302b <generic_sleepable_preload+0x302b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_302b;
	}
x86_l_300b:
	/* 0x300b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_300e:
	/* 0x300e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3013:
	/* 0x3013: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3018:
	/* 0x3018: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_301c:
	/* 0x301c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3021:
	/* 0x3021: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3023:
	/* 0x3023: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3025:
	/* 0x3025: js     3b95 <generic_sleepable_preload+0x3b95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15253ULL;
	}
x86_l_302b:
	/* 0x302b: cmp    WORD PTR [r12+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_3035:
	/* 0x3035: je     3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15312ULL;
	}
x86_l_303b:
	/* 0x303b: mov    ecx,DWORD PTR [r12+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_3043:
	/* 0x3043: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3047:
	/* 0x3047: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_304b:
	/* 0x304b: cmp    WORD PTR [r12+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_3055:
	/* 0x3055: je     3077 <generic_sleepable_preload+0x3077> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3077;
	}
x86_l_3057:
	/* 0x3057: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_305a:
	/* 0x305a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_305f:
	/* 0x305f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3064:
	/* 0x3064: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3068:
	/* 0x3068: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_306d:
	/* 0x306d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_306f:
	/* 0x306f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3071:
	/* 0x3071: js     3ba6 <generic_sleepable_preload+0x3ba6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15270ULL;
	}
x86_l_3077:
	/* 0x3077: cmp    WORD PTR [r12+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_3081:
	/* 0x3081: je     3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15312ULL;
	}
x86_l_3087:
	/* 0x3087: mov    ecx,DWORD PTR [r12+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_308f:
	/* 0x308f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3093:
	/* 0x3093: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3097:
	/* 0x3097: cmp    WORD PTR [r12+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_30a1:
	/* 0x30a1: je     30c3 <generic_sleepable_preload+0x30c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30c3;
	}
x86_l_30a3:
	/* 0x30a3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_30a6:
	/* 0x30a6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_30ab:
	/* 0x30ab: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_30b0:
	/* 0x30b0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30b4:
	/* 0x30b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30b9:
	/* 0x30b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30bb:
	/* 0x30bb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30bd:
	/* 0x30bd: js     3bb7 <generic_sleepable_preload+0x3bb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15287ULL;
	}
x86_l_30c3:
	/* 0x30c3: cmp    WORD PTR [r12+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_30cd:
	/* 0x30cd: je     3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15312ULL;
	}
x86_l_30d3:
	/* 0x30d3: mov    ecx,DWORD PTR [r12+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_30db:
	/* 0x30db: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_30df:
	/* 0x30df: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30e3:
	/* 0x30e3: cmp    WORD PTR [r12+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_30ed:
	/* 0x30ed: je     310f <generic_sleepable_preload+0x310f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_310f;
	}
x86_l_30ef:
	/* 0x30ef: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_30f2:
	/* 0x30f2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_30f7:
	/* 0x30f7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_30fc:
	/* 0x30fc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3100:
	/* 0x3100: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3105:
	/* 0x3105: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3107:
	/* 0x3107: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3109:
	/* 0x3109: js     3bc8 <generic_sleepable_preload+0x3bc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15304ULL;
	}
x86_l_310f:
	/* 0x310f: cmp    WORD PTR [r12+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_3119:
	/* 0x3119: je     3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15312ULL;
	}
x86_l_311f:
	/* 0x311f: mov    ecx,DWORD PTR [r12+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_3127:
	/* 0x3127: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_312b:
	/* 0x312b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_312f:
	/* 0x312f: cmp    WORD PTR [r12+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_3139:
	/* 0x3139: je     315b <generic_sleepable_preload+0x315b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_315b;
	}
x86_l_313b:
	/* 0x313b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_313e:
	/* 0x313e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3143:
	/* 0x3143: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3148:
	/* 0x3148: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_314c:
	/* 0x314c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3151:
	/* 0x3151: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3153:
	/* 0x3153: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3155:
	/* 0x3155: js     5c01 <generic_sleepable_preload+0x5c01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23553ULL;
	}
x86_l_315b:
	/* 0x315b: cmp    WORD PTR [r12+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_3165:
	/* 0x3165: je     3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15312ULL;
	}
x86_l_316b:
	/* 0x316b: mov    ecx,DWORD PTR [r12+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3173:
	/* 0x3173: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3177:
	/* 0x3177: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_317b:
	/* 0x317b: cmp    WORD PTR [r12+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3185:
	/* 0x3185: je     31a7 <generic_sleepable_preload+0x31a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31a7;
	}
x86_l_3187:
	/* 0x3187: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_318a:
	/* 0x318a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_318f:
	/* 0x318f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3194:
	/* 0x3194: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3198:
	/* 0x3198: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_319d:
	/* 0x319d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_319f:
	/* 0x319f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31a1:
	/* 0x31a1: js     5cfb <generic_sleepable_preload+0x5cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23803ULL;
	}
x86_l_31a7:
	/* 0x31a7: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31ac:
	/* 0x31ac: cmp    WORD PTR [r12+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_31b6:
	/* 0x31b6: je     3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15312ULL;
	}
x86_l_31bc:
	/* 0x31bc: mov    ecx,DWORD PTR [r12+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_31c4:
	/* 0x31c4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_31c8:
	/* 0x31c8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31cc:
	/* 0x31cc: cmp    WORD PTR [r12+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_31d6:
	/* 0x31d6: je     3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15312ULL;
	}
x86_l_31dc:
	/* 0x31dc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_31df:
	/* 0x31df: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_31e4:
	/* 0x31e4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_31e9:
	/* 0x31e9: jmp    34c3 <generic_sleepable_preload+0x34c3> */
	goto x86_l_34c3;
x86_l_31ee:
	/* 0x31ee: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_31f1:
	/* 0x31f1: je     3213 <generic_sleepable_preload+0x3213> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3213;
	}
x86_l_31f3:
	/* 0x31f3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_31f6:
	/* 0x31f6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_31fb:
	/* 0x31fb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3200:
	/* 0x3200: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3204:
	/* 0x3204: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3209:
	/* 0x3209: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_320b:
	/* 0x320b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_320d:
	/* 0x320d: js     34e0 <generic_sleepable_preload+0x34e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_34e0;
	}
x86_l_3213:
	/* 0x3213: cmp    WORD PTR [r12+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_321d:
	/* 0x321d: je     3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15312ULL;
	}
x86_l_3223:
	/* 0x3223: mov    ecx,DWORD PTR [r12+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_322b:
	/* 0x322b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_322f:
	/* 0x322f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3233:
	/* 0x3233: cmp    WORD PTR [r12+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_323d:
	/* 0x323d: je     325f <generic_sleepable_preload+0x325f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_325f;
	}
x86_l_323f:
	/* 0x323f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3242:
	/* 0x3242: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3247:
	/* 0x3247: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_324c:
	/* 0x324c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3250:
	/* 0x3250: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3255:
	/* 0x3255: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3257:
	/* 0x3257: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3259:
	/* 0x3259: js     3548 <generic_sleepable_preload+0x3548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3548;
	}
x86_l_325f:
	/* 0x325f: cmp    WORD PTR [r12+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_3269:
	/* 0x3269: je     3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15312ULL;
	}
x86_l_326f:
	/* 0x326f: mov    ecx,DWORD PTR [r12+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_3277:
	/* 0x3277: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_327b:
	/* 0x327b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_327f:
	/* 0x327f: cmp    WORD PTR [r12+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_3289:
	/* 0x3289: je     32ab <generic_sleepable_preload+0x32ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32ab;
	}
x86_l_328b:
	/* 0x328b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_328e:
	/* 0x328e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3293:
	/* 0x3293: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3298:
	/* 0x3298: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_329c:
	/* 0x329c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32a1:
	/* 0x32a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32a3:
	/* 0x32a3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32a5:
	/* 0x32a5: js     3b84 <generic_sleepable_preload+0x3b84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15236ULL;
	}
x86_l_32ab:
	/* 0x32ab: cmp    WORD PTR [r12+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_32b5:
	/* 0x32b5: je     3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15312ULL;
	}
x86_l_32bb:
	/* 0x32bb: mov    ecx,DWORD PTR [r12+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_32c3:
	/* 0x32c3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_32c7:
	/* 0x32c7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32cb:
	/* 0x32cb: cmp    WORD PTR [r12+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_32d5:
	/* 0x32d5: je     32f7 <generic_sleepable_preload+0x32f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32f7;
	}
x86_l_32d7:
	/* 0x32d7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_32da:
	/* 0x32da: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_32df:
	/* 0x32df: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_32e4:
	/* 0x32e4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32e8:
	/* 0x32e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32ed:
	/* 0x32ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32ef:
	/* 0x32ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32f1:
	/* 0x32f1: js     3b95 <generic_sleepable_preload+0x3b95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15253ULL;
	}
x86_l_32f7:
	/* 0x32f7: cmp    WORD PTR [r12+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_3301:
	/* 0x3301: je     3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15312ULL;
	}
x86_l_3307:
	/* 0x3307: mov    ecx,DWORD PTR [r12+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_330f:
	/* 0x330f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3313:
	/* 0x3313: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3317:
	/* 0x3317: cmp    WORD PTR [r12+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_3321:
	/* 0x3321: je     3343 <generic_sleepable_preload+0x3343> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3343;
	}
x86_l_3323:
	/* 0x3323: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3326:
	/* 0x3326: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_332b:
	/* 0x332b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3330:
	/* 0x3330: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3334:
	/* 0x3334: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3339:
	/* 0x3339: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_333b:
	/* 0x333b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_333d:
	/* 0x333d: js     3ba6 <generic_sleepable_preload+0x3ba6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15270ULL;
	}
x86_l_3343:
	/* 0x3343: cmp    WORD PTR [r12+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_334d:
	/* 0x334d: je     3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15312ULL;
	}
x86_l_3353:
	/* 0x3353: mov    ecx,DWORD PTR [r12+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_335b:
	/* 0x335b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_335f:
	/* 0x335f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3363:
	/* 0x3363: cmp    WORD PTR [r12+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_336d:
	/* 0x336d: je     338f <generic_sleepable_preload+0x338f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_338f;
	}
x86_l_336f:
	/* 0x336f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3372:
	/* 0x3372: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3377:
	/* 0x3377: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_337c:
	/* 0x337c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3380:
	/* 0x3380: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3385:
	/* 0x3385: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3387:
	/* 0x3387: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3389:
	/* 0x3389: js     3bb7 <generic_sleepable_preload+0x3bb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15287ULL;
	}
x86_l_338f:
	/* 0x338f: cmp    WORD PTR [r12+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_3399:
	/* 0x3399: je     3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15312ULL;
	}
x86_l_339f:
	/* 0x339f: mov    ecx,DWORD PTR [r12+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_33a7:
	/* 0x33a7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_33ab:
	/* 0x33ab: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33af:
	/* 0x33af: cmp    WORD PTR [r12+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_33b9:
	/* 0x33b9: je     33db <generic_sleepable_preload+0x33db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33db;
	}
x86_l_33bb:
	/* 0x33bb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_33be:
	/* 0x33be: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_33c3:
	/* 0x33c3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_33c8:
	/* 0x33c8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33cc:
	/* 0x33cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33d1:
	/* 0x33d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33d3:
	/* 0x33d3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33d5:
	/* 0x33d5: js     3bc8 <generic_sleepable_preload+0x3bc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15304ULL;
	}
x86_l_33db:
	/* 0x33db: cmp    WORD PTR [r12+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_33e5:
	/* 0x33e5: je     3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15312ULL;
	}
x86_l_33eb:
	/* 0x33eb: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_33ee:
	/* 0x33ee: mov    ecx,DWORD PTR [r12+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_33f6:
	/* 0x33f6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_33fa:
	/* 0x33fa: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33fe:
	/* 0x33fe: cmp    WORD PTR [r12+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_3408:
	/* 0x3408: je     342a <generic_sleepable_preload+0x342a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_342a;
	}
x86_l_340a:
	/* 0x340a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_340d:
	/* 0x340d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3412:
	/* 0x3412: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3417:
	/* 0x3417: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_341b:
	/* 0x341b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3420:
	/* 0x3420: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3422:
	/* 0x3422: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3424:
	/* 0x3424: js     5c7f <generic_sleepable_preload+0x5c7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23679ULL;
	}
x86_l_342a:
	/* 0x342a: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_342f:
	/* 0x342f: cmp    WORD PTR [r12+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_3439:
	/* 0x3439: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_343c:
	/* 0x343c: je     3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15312ULL;
	}
x86_l_3442:
	/* 0x3442: mov    ecx,DWORD PTR [r12+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_344a:
	/* 0x344a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_344e:
	/* 0x344e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3452:
	/* 0x3452: cmp    WORD PTR [r12+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_345c:
	/* 0x345c: je     347e <generic_sleepable_preload+0x347e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_347e;
	}
x86_l_345e:
	/* 0x345e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3461:
	/* 0x3461: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3466:
	/* 0x3466: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_346b:
	/* 0x346b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_346f:
	/* 0x346f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3474:
	/* 0x3474: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3476:
	/* 0x3476: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3478:
	/* 0x3478: js     5d97 <generic_sleepable_preload+0x5d97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23959ULL;
	}
x86_l_347e:
	/* 0x347e: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3483:
	/* 0x3483: cmp    WORD PTR [r12+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_348d:
	/* 0x348d: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_3490:
	/* 0x3490: je     3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15312ULL;
	}
x86_l_3496:
	/* 0x3496: mov    ecx,DWORD PTR [r12+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_349e:
	/* 0x349e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_34a2:
	/* 0x34a2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34a6:
	/* 0x34a6: cmp    WORD PTR [r12+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_34b0:
	/* 0x34b0: je     3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15312ULL;
	}
x86_l_34b6:
	/* 0x34b6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_34b9:
	/* 0x34b9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_34be:
	/* 0x34be: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_34c3:
	/* 0x34c3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34c7:
	/* 0x34c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34cc:
	/* 0x34cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34ce:
	/* 0x34ce: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34d0:
	/* 0x34d0: jns    3bd0 <generic_sleepable_preload+0x3bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 15312ULL;
	}
x86_l_34d6:
	/* 0x34d6: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_34db:
	/* 0x34db: jmp    3bcd <generic_sleepable_preload+0x3bcd> */
	return 15309ULL;
x86_l_34e0:
	/* 0x34e0: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_34e5:
	/* 0x34e5: jmp    3bcd <generic_sleepable_preload+0x3bcd> */
	return 15309ULL;
x86_l_34ea:
	/* 0x34ea: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_34f2:
	/* 0x34f2: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_34f5:
	/* 0x34f5: je     3557 <generic_sleepable_preload+0x3557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3557;
	}
x86_l_34f7:
	/* 0x34f7: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34fc:
	/* 0x34fc: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_34ff:
	/* 0x34ff: je     3557 <generic_sleepable_preload+0x3557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3557;
	}
x86_l_3501:
	/* 0x3501: jmp    356a <generic_sleepable_preload+0x356a> */
	goto x86_l_356a;
x86_l_3503:
	/* 0x3503: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3508:
	/* 0x3508: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_350b:
	/* 0x350b: je     3557 <generic_sleepable_preload+0x3557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3557;
	}
x86_l_350d:
	/* 0x350d: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3512:
	/* 0x3512: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3515:
	/* 0x3515: je     3557 <generic_sleepable_preload+0x3557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3557;
	}
x86_l_3517:
	/* 0x3517: jmp    356a <generic_sleepable_preload+0x356a> */
	goto x86_l_356a;
x86_l_3519:
	/* 0x3519: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3521:
	/* 0x3521: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_3524:
	/* 0x3524: je     3557 <generic_sleepable_preload+0x3557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3557;
	}
x86_l_3526:
	/* 0x3526: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_352b:
	/* 0x352b: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_352e:
	/* 0x352e: je     3557 <generic_sleepable_preload+0x3557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3557;
	}
x86_l_3530:
	/* 0x3530: jmp    356a <generic_sleepable_preload+0x356a> */
	goto x86_l_356a;
x86_l_3532:
	/* 0x3532: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3537:
	/* 0x3537: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_353a:
	/* 0x353a: je     3557 <generic_sleepable_preload+0x3557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3557;
	}
x86_l_353c:
	/* 0x353c: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3541:
	/* 0x3541: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_3544:
	/* 0x3544: je     3557 <generic_sleepable_preload+0x3557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3557;
	}
x86_l_3546:
	/* 0x3546: jmp    356a <generic_sleepable_preload+0x356a> */
	goto x86_l_356a;
x86_l_3548:
	/* 0x3548: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_354d:
	/* 0x354d: jmp    3bcd <generic_sleepable_preload+0x3bcd> */
	return 15309ULL;
x86_l_3552:
	/* 0x3552: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3557:
	/* 0x3557: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_355a:
	/* 0x355a: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_355c:
	/* 0x355c: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_355e:
	/* 0x355e: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_3563:
	/* 0x3563: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3565:
	/* 0x3565: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_356a:
	/* 0x356a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_356e:
	/* 0x356e: mov    ebp,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3573:
	/* 0x3573: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3575:
	/* 0x3575: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_3578:
	/* 0x3578: cmp    WORD PTR [r12+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_3582:
	/* 0x3582: je     3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15451ULL;
	}
x86_l_3588:
	/* 0x3588: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_358f:
	/* 0x358f: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3592:
	/* 0x3592: mov    eax,DWORD PTR [r12+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_359a:
	/* 0x359a: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_359d:
	/* 0x359d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35a1:
	/* 0x35a1: movzx  eax,WORD PTR [r12+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_35aa:
	/* 0x35aa: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_35ac:
	/* 0x35ac: je     387e <generic_sleepable_preload+0x387e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14462ULL;
	}
x86_l_35b2:
	/* 0x35b2: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_35b5:
	/* 0x35b5: je     35d7 <generic_sleepable_preload+0x35d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35d7;
	}
x86_l_35b7:
	/* 0x35b7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_35ba:
	/* 0x35ba: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_35bf:
	/* 0x35bf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_35c4:
	/* 0x35c4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35c8:
	/* 0x35c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35cd:
	/* 0x35cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35cf:
	/* 0x35cf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35d1:
	/* 0x35d1: js     3b70 <generic_sleepable_preload+0x3b70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15216ULL;
	}
x86_l_35d7:
	/* 0x35d7: cmp    WORD PTR [r12+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_35e1:
	/* 0x35e1: je     3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15451ULL;
	}
x86_l_35e7:
	/* 0x35e7: mov    ecx,DWORD PTR [r12+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_35ef:
	/* 0x35ef: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_35f3:
	/* 0x35f3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35f7:
	/* 0x35f7: cmp    WORD PTR [r12+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_3601:
	/* 0x3601: je     3623 <generic_sleepable_preload+0x3623> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3623;
	}
x86_l_3603:
	/* 0x3603: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3606:
	/* 0x3606: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_360b:
	/* 0x360b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3610:
	/* 0x3610: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3614:
	/* 0x3614: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3619:
	/* 0x3619: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_361b:
	/* 0x361b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_361d:
	/* 0x361d: js     3b7a <generic_sleepable_preload+0x3b7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15226ULL;
	}
x86_l_3623:
	/* 0x3623: cmp    WORD PTR [r12+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_362d:
	/* 0x362d: je     3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15451ULL;
	}
x86_l_3633:
	/* 0x3633: mov    ecx,DWORD PTR [r12+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_363b:
	/* 0x363b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_363f:
	/* 0x363f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3643:
	/* 0x3643: cmp    WORD PTR [r12+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_364d:
	/* 0x364d: je     366f <generic_sleepable_preload+0x366f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_366f;
	}
x86_l_364f:
	/* 0x364f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3652:
	/* 0x3652: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3657:
	/* 0x3657: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_365c:
	/* 0x365c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3660:
	/* 0x3660: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3665:
	/* 0x3665: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3667:
	/* 0x3667: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3669:
	/* 0x3669: js     3b8b <generic_sleepable_preload+0x3b8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15243ULL;
	}
x86_l_366f:
	/* 0x366f: cmp    WORD PTR [r12+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_3679:
	/* 0x3679: je     3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15451ULL;
	}
x86_l_367f:
	/* 0x367f: mov    ecx,DWORD PTR [r12+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_3687:
	/* 0x3687: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_368b:
	/* 0x368b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_368f:
	/* 0x368f: cmp    WORD PTR [r12+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_3699:
	/* 0x3699: je     36bb <generic_sleepable_preload+0x36bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14011ULL;
	}
x86_l_369b:
	/* 0x369b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_369e:
	/* 0x369e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_36a3:
	/* 0x36a3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_36a8:
	/* 0x36a8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36ac:
	/* 0x36ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36b1:
	/* 0x36b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36b3:
	/* 0x36b3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
	return 14005ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14005ULL: goto x86_l_36b5;
	case 14011ULL: goto x86_l_36bb;
	case 14021ULL: goto x86_l_36c5;
	case 14027ULL: goto x86_l_36cb;
	case 14035ULL: goto x86_l_36d3;
	case 14039ULL: goto x86_l_36d7;
	case 14043ULL: goto x86_l_36db;
	case 14053ULL: goto x86_l_36e5;
	case 14055ULL: goto x86_l_36e7;
	case 14058ULL: goto x86_l_36ea;
	case 14063ULL: goto x86_l_36ef;
	case 14068ULL: goto x86_l_36f4;
	case 14072ULL: goto x86_l_36f8;
	case 14077ULL: goto x86_l_36fd;
	case 14079ULL: goto x86_l_36ff;
	case 14081ULL: goto x86_l_3701;
	case 14087ULL: goto x86_l_3707;
	case 14097ULL: goto x86_l_3711;
	case 14103ULL: goto x86_l_3717;
	case 14111ULL: goto x86_l_371f;
	case 14115ULL: goto x86_l_3723;
	case 14119ULL: goto x86_l_3727;
	case 14129ULL: goto x86_l_3731;
	case 14131ULL: goto x86_l_3733;
	case 14134ULL: goto x86_l_3736;
	case 14139ULL: goto x86_l_373b;
	case 14144ULL: goto x86_l_3740;
	case 14148ULL: goto x86_l_3744;
	case 14153ULL: goto x86_l_3749;
	case 14155ULL: goto x86_l_374b;
	case 14157ULL: goto x86_l_374d;
	case 14163ULL: goto x86_l_3753;
	case 14173ULL: goto x86_l_375d;
	case 14179ULL: goto x86_l_3763;
	case 14187ULL: goto x86_l_376b;
	case 14191ULL: goto x86_l_376f;
	case 14195ULL: goto x86_l_3773;
	case 14205ULL: goto x86_l_377d;
	case 14207ULL: goto x86_l_377f;
	case 14210ULL: goto x86_l_3782;
	case 14215ULL: goto x86_l_3787;
	case 14220ULL: goto x86_l_378c;
	case 14224ULL: goto x86_l_3790;
	case 14229ULL: goto x86_l_3795;
	case 14231ULL: goto x86_l_3797;
	case 14233ULL: goto x86_l_3799;
	case 14239ULL: goto x86_l_379f;
	case 14249ULL: goto x86_l_37a9;
	case 14255ULL: goto x86_l_37af;
	case 14263ULL: goto x86_l_37b7;
	case 14267ULL: goto x86_l_37bb;
	case 14271ULL: goto x86_l_37bf;
	case 14281ULL: goto x86_l_37c9;
	case 14283ULL: goto x86_l_37cb;
	case 14286ULL: goto x86_l_37ce;
	case 14291ULL: goto x86_l_37d3;
	case 14296ULL: goto x86_l_37d8;
	case 14300ULL: goto x86_l_37dc;
	case 14305ULL: goto x86_l_37e1;
	case 14307ULL: goto x86_l_37e3;
	case 14309ULL: goto x86_l_37e5;
	case 14315ULL: goto x86_l_37eb;
	case 14325ULL: goto x86_l_37f5;
	case 14331ULL: goto x86_l_37fb;
	case 14339ULL: goto x86_l_3803;
	case 14343ULL: goto x86_l_3807;
	case 14347ULL: goto x86_l_380b;
	case 14357ULL: goto x86_l_3815;
	case 14359ULL: goto x86_l_3817;
	case 14362ULL: goto x86_l_381a;
	case 14367ULL: goto x86_l_381f;
	case 14372ULL: goto x86_l_3824;
	case 14376ULL: goto x86_l_3828;
	case 14381ULL: goto x86_l_382d;
	case 14383ULL: goto x86_l_382f;
	case 14385ULL: goto x86_l_3831;
	case 14391ULL: goto x86_l_3837;
	case 14396ULL: goto x86_l_383c;
	case 14406ULL: goto x86_l_3846;
	case 14412ULL: goto x86_l_384c;
	case 14420ULL: goto x86_l_3854;
	case 14424ULL: goto x86_l_3858;
	case 14428ULL: goto x86_l_385c;
	case 14438ULL: goto x86_l_3866;
	case 14444ULL: goto x86_l_386c;
	case 14447ULL: goto x86_l_386f;
	case 14452ULL: goto x86_l_3874;
	case 14457ULL: goto x86_l_3879;
	case 14462ULL: goto x86_l_387e;
	case 14465ULL: goto x86_l_3881;
	case 14467ULL: goto x86_l_3883;
	case 14470ULL: goto x86_l_3886;
	case 14475ULL: goto x86_l_388b;
	case 14480ULL: goto x86_l_3890;
	case 14484ULL: goto x86_l_3894;
	case 14489ULL: goto x86_l_3899;
	case 14491ULL: goto x86_l_389b;
	case 14493ULL: goto x86_l_389d;
	case 14499ULL: goto x86_l_38a3;
	case 14509ULL: goto x86_l_38ad;
	case 14515ULL: goto x86_l_38b3;
	case 14523ULL: goto x86_l_38bb;
	case 14527ULL: goto x86_l_38bf;
	case 14531ULL: goto x86_l_38c3;
	case 14541ULL: goto x86_l_38cd;
	case 14543ULL: goto x86_l_38cf;
	case 14546ULL: goto x86_l_38d2;
	case 14551ULL: goto x86_l_38d7;
	case 14556ULL: goto x86_l_38dc;
	case 14560ULL: goto x86_l_38e0;
	case 14565ULL: goto x86_l_38e5;
	case 14567ULL: goto x86_l_38e7;
	case 14569ULL: goto x86_l_38e9;
	case 14575ULL: goto x86_l_38ef;
	case 14585ULL: goto x86_l_38f9;
	case 14591ULL: goto x86_l_38ff;
	case 14599ULL: goto x86_l_3907;
	case 14603ULL: goto x86_l_390b;
	case 14607ULL: goto x86_l_390f;
	case 14617ULL: goto x86_l_3919;
	case 14619ULL: goto x86_l_391b;
	case 14622ULL: goto x86_l_391e;
	case 14627ULL: goto x86_l_3923;
	case 14632ULL: goto x86_l_3928;
	case 14636ULL: goto x86_l_392c;
	case 14641ULL: goto x86_l_3931;
	case 14643ULL: goto x86_l_3933;
	case 14645ULL: goto x86_l_3935;
	case 14651ULL: goto x86_l_393b;
	case 14661ULL: goto x86_l_3945;
	case 14667ULL: goto x86_l_394b;
	case 14675ULL: goto x86_l_3953;
	case 14679ULL: goto x86_l_3957;
	case 14683ULL: goto x86_l_395b;
	case 14693ULL: goto x86_l_3965;
	case 14695ULL: goto x86_l_3967;
	case 14698ULL: goto x86_l_396a;
	case 14703ULL: goto x86_l_396f;
	case 14708ULL: goto x86_l_3974;
	case 14712ULL: goto x86_l_3978;
	case 14717ULL: goto x86_l_397d;
	case 14719ULL: goto x86_l_397f;
	case 14721ULL: goto x86_l_3981;
	case 14727ULL: goto x86_l_3987;
	case 14737ULL: goto x86_l_3991;
	case 14743ULL: goto x86_l_3997;
	case 14751ULL: goto x86_l_399f;
	case 14755ULL: goto x86_l_39a3;
	case 14759ULL: goto x86_l_39a7;
	case 14769ULL: goto x86_l_39b1;
	case 14771ULL: goto x86_l_39b3;
	case 14774ULL: goto x86_l_39b6;
	case 14779ULL: goto x86_l_39bb;
	case 14784ULL: goto x86_l_39c0;
	case 14788ULL: goto x86_l_39c4;
	case 14793ULL: goto x86_l_39c9;
	case 14795ULL: goto x86_l_39cb;
	case 14797ULL: goto x86_l_39cd;
	case 14803ULL: goto x86_l_39d3;
	case 14813ULL: goto x86_l_39dd;
	case 14819ULL: goto x86_l_39e3;
	case 14827ULL: goto x86_l_39eb;
	case 14831ULL: goto x86_l_39ef;
	case 14835ULL: goto x86_l_39f3;
	case 14845ULL: goto x86_l_39fd;
	case 14847ULL: goto x86_l_39ff;
	case 14850ULL: goto x86_l_3a02;
	case 14855ULL: goto x86_l_3a07;
	case 14860ULL: goto x86_l_3a0c;
	case 14864ULL: goto x86_l_3a10;
	case 14869ULL: goto x86_l_3a15;
	case 14871ULL: goto x86_l_3a17;
	case 14873ULL: goto x86_l_3a19;
	case 14879ULL: goto x86_l_3a1f;
	case 14889ULL: goto x86_l_3a29;
	case 14895ULL: goto x86_l_3a2f;
	case 14903ULL: goto x86_l_3a37;
	case 14907ULL: goto x86_l_3a3b;
	case 14911ULL: goto x86_l_3a3f;
	case 14921ULL: goto x86_l_3a49;
	case 14923ULL: goto x86_l_3a4b;
	case 14926ULL: goto x86_l_3a4e;
	case 14931ULL: goto x86_l_3a53;
	case 14936ULL: goto x86_l_3a58;
	case 14940ULL: goto x86_l_3a5c;
	case 14945ULL: goto x86_l_3a61;
	case 14947ULL: goto x86_l_3a63;
	case 14949ULL: goto x86_l_3a65;
	case 14955ULL: goto x86_l_3a6b;
	case 14965ULL: goto x86_l_3a75;
	case 14971ULL: goto x86_l_3a7b;
	case 14974ULL: goto x86_l_3a7e;
	case 14982ULL: goto x86_l_3a86;
	case 14986ULL: goto x86_l_3a8a;
	case 14990ULL: goto x86_l_3a8e;
	case 15000ULL: goto x86_l_3a98;
	case 15002ULL: goto x86_l_3a9a;
	case 15005ULL: goto x86_l_3a9d;
	case 15010ULL: goto x86_l_3aa2;
	case 15015ULL: goto x86_l_3aa7;
	case 15019ULL: goto x86_l_3aab;
	case 15024ULL: goto x86_l_3ab0;
	case 15026ULL: goto x86_l_3ab2;
	case 15028ULL: goto x86_l_3ab4;
	case 15034ULL: goto x86_l_3aba;
	case 15039ULL: goto x86_l_3abf;
	case 15049ULL: goto x86_l_3ac9;
	case 15052ULL: goto x86_l_3acc;
	case 15058ULL: goto x86_l_3ad2;
	case 15066ULL: goto x86_l_3ada;
	case 15070ULL: goto x86_l_3ade;
	case 15074ULL: goto x86_l_3ae2;
	case 15084ULL: goto x86_l_3aec;
	case 15086ULL: goto x86_l_3aee;
	case 15089ULL: goto x86_l_3af1;
	case 15094ULL: goto x86_l_3af6;
	case 15099ULL: goto x86_l_3afb;
	case 15103ULL: goto x86_l_3aff;
	case 15108ULL: goto x86_l_3b04;
	case 15110ULL: goto x86_l_3b06;
	case 15112ULL: goto x86_l_3b08;
	case 15118ULL: goto x86_l_3b0e;
	case 15123ULL: goto x86_l_3b13;
	case 15133ULL: goto x86_l_3b1d;
	case 15136ULL: goto x86_l_3b20;
	case 15142ULL: goto x86_l_3b26;
	case 15150ULL: goto x86_l_3b2e;
	case 15154ULL: goto x86_l_3b32;
	case 15158ULL: goto x86_l_3b36;
	case 15168ULL: goto x86_l_3b40;
	case 15174ULL: goto x86_l_3b46;
	case 15177ULL: goto x86_l_3b49;
	case 15182ULL: goto x86_l_3b4e;
	case 15187ULL: goto x86_l_3b53;
	case 15191ULL: goto x86_l_3b57;
	case 15196ULL: goto x86_l_3b5c;
	case 15198ULL: goto x86_l_3b5e;
	case 15200ULL: goto x86_l_3b60;
	case 15206ULL: goto x86_l_3b66;
	case 15211ULL: goto x86_l_3b6b;
	case 15216ULL: goto x86_l_3b70;
	case 15221ULL: goto x86_l_3b75;
	case 15226ULL: goto x86_l_3b7a;
	case 15231ULL: goto x86_l_3b7f;
	case 15236ULL: goto x86_l_3b84;
	case 15241ULL: goto x86_l_3b89;
	case 15243ULL: goto x86_l_3b8b;
	case 15248ULL: goto x86_l_3b90;
	case 15253ULL: goto x86_l_3b95;
	case 15258ULL: goto x86_l_3b9a;
	case 15260ULL: goto x86_l_3b9c;
	case 15265ULL: goto x86_l_3ba1;
	case 15270ULL: goto x86_l_3ba6;
	case 15275ULL: goto x86_l_3bab;
	case 15277ULL: goto x86_l_3bad;
	case 15282ULL: goto x86_l_3bb2;
	case 15287ULL: goto x86_l_3bb7;
	case 15292ULL: goto x86_l_3bbc;
	case 15294ULL: goto x86_l_3bbe;
	case 15299ULL: goto x86_l_3bc3;
	case 15304ULL: goto x86_l_3bc8;
	case 15309ULL: goto x86_l_3bcd;
	case 15312ULL: goto x86_l_3bd0;
	case 15317ULL: goto x86_l_3bd5;
	case 15320ULL: goto x86_l_3bd8;
	case 15325ULL: goto x86_l_3bdd;
	case 15330ULL: goto x86_l_3be2;
	case 15335ULL: goto x86_l_3be7;
	case 15338ULL: goto x86_l_3bea;
	case 15340ULL: goto x86_l_3bec;
	case 15343ULL: goto x86_l_3bef;
	case 15349ULL: goto x86_l_3bf5;
	case 15352ULL: goto x86_l_3bf8;
	case 15356ULL: goto x86_l_3bfc;
	case 15361ULL: goto x86_l_3c01;
	case 15363ULL: goto x86_l_3c03;
	case 15368ULL: goto x86_l_3c08;
	case 15376ULL: goto x86_l_3c10;
	case 15383ULL: goto x86_l_3c17;
	case 15388ULL: goto x86_l_3c1c;
	case 15393ULL: goto x86_l_3c21;
	case 15395ULL: goto x86_l_3c23;
	case 15398ULL: goto x86_l_3c26;
	case 15404ULL: goto x86_l_3c2c;
	case 15407ULL: goto x86_l_3c2f;
	case 15414ULL: goto x86_l_3c36;
	case 15416ULL: goto x86_l_3c38;
	case 15421ULL: goto x86_l_3c3d;
	case 15426ULL: goto x86_l_3c42;
	case 15429ULL: goto x86_l_3c45;
	case 15432ULL: goto x86_l_3c48;
	case 15434ULL: goto x86_l_3c4a;
	case 15436ULL: goto x86_l_3c4c;
	case 15441ULL: goto x86_l_3c51;
	case 15443ULL: goto x86_l_3c53;
	case 15448ULL: goto x86_l_3c58;
	case 15451ULL: goto x86_l_3c5b;
	case 15454ULL: goto x86_l_3c5e;
	case 15460ULL: goto x86_l_3c64;
	case 15463ULL: goto x86_l_3c67;
	case 15467ULL: goto x86_l_3c6b;
	case 15472ULL: goto x86_l_3c70;
	case 15474ULL: goto x86_l_3c72;
	case 15479ULL: goto x86_l_3c77;
	case 15487ULL: goto x86_l_3c7f;
	case 15494ULL: goto x86_l_3c86;
	case 15499ULL: goto x86_l_3c8b;
	case 15504ULL: goto x86_l_3c90;
	case 15506ULL: goto x86_l_3c92;
	case 15509ULL: goto x86_l_3c95;
	case 15511ULL: goto x86_l_3c97;
	case 15514ULL: goto x86_l_3c9a;
	case 15521ULL: goto x86_l_3ca1;
	case 15523ULL: goto x86_l_3ca3;
	case 15528ULL: goto x86_l_3ca8;
	case 15533ULL: goto x86_l_3cad;
	case 15536ULL: goto x86_l_3cb0;
	case 15539ULL: goto x86_l_3cb3;
	case 15541ULL: goto x86_l_3cb5;
	case 15543ULL: goto x86_l_3cb7;
	case 15548ULL: goto x86_l_3cbc;
	case 15551ULL: goto x86_l_3cbf;
	case 15554ULL: goto x86_l_3cc2;
	case 15559ULL: goto x86_l_3cc7;
	case 15561ULL: goto x86_l_3cc9;
	case 15564ULL: goto x86_l_3ccc;
	case 15566ULL: goto x86_l_3cce;
	case 15569ULL: goto x86_l_3cd1;
	case 15571ULL: goto x86_l_3cd3;
	case 15574ULL: goto x86_l_3cd6;
	case 15578ULL: goto x86_l_3cda;
	case 15583ULL: goto x86_l_3cdf;
	case 15586ULL: goto x86_l_3ce2;
	case 15588ULL: goto x86_l_3ce4;
	case 15591ULL: goto x86_l_3ce7;
	case 15596ULL: goto x86_l_3cec;
	case 15598ULL: goto x86_l_3cee;
	case 15601ULL: goto x86_l_3cf1;
	case 15603ULL: goto x86_l_3cf3;
	case 15608ULL: goto x86_l_3cf8;
	case 15611ULL: goto x86_l_3cfb;
	case 15613ULL: goto x86_l_3cfd;
	case 15616ULL: goto x86_l_3d00;
	case 15621ULL: goto x86_l_3d05;
	case 15626ULL: goto x86_l_3d0a;
	case 15632ULL: goto x86_l_3d10;
	case 15634ULL: goto x86_l_3d12;
	case 15636ULL: goto x86_l_3d14;
	case 15641ULL: goto x86_l_3d19;
	case 15644ULL: goto x86_l_3d1c;
	case 15650ULL: goto x86_l_3d22;
	case 15653ULL: goto x86_l_3d25;
	case 15659ULL: goto x86_l_3d2b;
	case 15662ULL: goto x86_l_3d2e;
	case 15668ULL: goto x86_l_3d34;
	case 15671ULL: goto x86_l_3d37;
	case 15677ULL: goto x86_l_3d3d;
	case 15682ULL: goto x86_l_3d42;
	case 15687ULL: goto x86_l_3d47;
	case 15696ULL: goto x86_l_3d50;
	case 15705ULL: goto x86_l_3d59;
	case 15711ULL: goto x86_l_3d5f;
	case 15713ULL: goto x86_l_3d61;
	case 15716ULL: goto x86_l_3d64;
	case 15718ULL: goto x86_l_3d66;
	case 15721ULL: goto x86_l_3d69;
	case 15723ULL: goto x86_l_3d6b;
	case 15726ULL: goto x86_l_3d6e;
	case 15732ULL: goto x86_l_3d74;
	case 15737ULL: goto x86_l_3d79;
	case 15740ULL: goto x86_l_3d7c;
	case 15746ULL: goto x86_l_3d82;
	case 15751ULL: goto x86_l_3d87;
	case 15754ULL: goto x86_l_3d8a;
	case 15760ULL: goto x86_l_3d90;
	case 15765ULL: goto x86_l_3d95;
	case 15768ULL: goto x86_l_3d98;
	case 15774ULL: goto x86_l_3d9e;
	case 15779ULL: goto x86_l_3da3;
	case 15782ULL: goto x86_l_3da6;
	case 15784ULL: goto x86_l_3da8;
	case 15787ULL: goto x86_l_3dab;
	case 15793ULL: goto x86_l_3db1;
	case 15795ULL: goto x86_l_3db3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_36b5:
	/* 0x36b5: js     3b9c <generic_sleepable_preload+0x3b9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b9c;
	}
x86_l_36bb:
	/* 0x36bb: cmp    WORD PTR [r12+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_36c5:
	/* 0x36c5: je     3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5b;
	}
x86_l_36cb:
	/* 0x36cb: mov    ecx,DWORD PTR [r12+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_36d3:
	/* 0x36d3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_36d7:
	/* 0x36d7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36db:
	/* 0x36db: cmp    WORD PTR [r12+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_36e5:
	/* 0x36e5: je     3707 <generic_sleepable_preload+0x3707> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3707;
	}
x86_l_36e7:
	/* 0x36e7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_36ea:
	/* 0x36ea: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_36ef:
	/* 0x36ef: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_36f4:
	/* 0x36f4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36f8:
	/* 0x36f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36fd:
	/* 0x36fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36ff:
	/* 0x36ff: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3701:
	/* 0x3701: js     3bad <generic_sleepable_preload+0x3bad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3bad;
	}
x86_l_3707:
	/* 0x3707: cmp    WORD PTR [r12+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_3711:
	/* 0x3711: je     3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5b;
	}
x86_l_3717:
	/* 0x3717: mov    ecx,DWORD PTR [r12+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_371f:
	/* 0x371f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3723:
	/* 0x3723: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3727:
	/* 0x3727: cmp    WORD PTR [r12+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_3731:
	/* 0x3731: je     3753 <generic_sleepable_preload+0x3753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3753;
	}
x86_l_3733:
	/* 0x3733: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3736:
	/* 0x3736: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_373b:
	/* 0x373b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3740:
	/* 0x3740: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3744:
	/* 0x3744: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3749:
	/* 0x3749: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_374b:
	/* 0x374b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_374d:
	/* 0x374d: js     3bbe <generic_sleepable_preload+0x3bbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3bbe;
	}
x86_l_3753:
	/* 0x3753: cmp    WORD PTR [r12+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_375d:
	/* 0x375d: je     3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5b;
	}
x86_l_3763:
	/* 0x3763: mov    ecx,DWORD PTR [r12+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_376b:
	/* 0x376b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_376f:
	/* 0x376f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3773:
	/* 0x3773: cmp    WORD PTR [r12+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_377d:
	/* 0x377d: je     379f <generic_sleepable_preload+0x379f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_379f;
	}
x86_l_377f:
	/* 0x377f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3782:
	/* 0x3782: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3787:
	/* 0x3787: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_378c:
	/* 0x378c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3790:
	/* 0x3790: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3795:
	/* 0x3795: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3797:
	/* 0x3797: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3799:
	/* 0x3799: js     3c53 <generic_sleepable_preload+0x3c53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c53;
	}
x86_l_379f:
	/* 0x379f: cmp    WORD PTR [r12+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_37a9:
	/* 0x37a9: je     3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5b;
	}
x86_l_37af:
	/* 0x37af: mov    ecx,DWORD PTR [r12+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_37b7:
	/* 0x37b7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_37bb:
	/* 0x37bb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37bf:
	/* 0x37bf: cmp    WORD PTR [r12+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_37c9:
	/* 0x37c9: je     37eb <generic_sleepable_preload+0x37eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37eb;
	}
x86_l_37cb:
	/* 0x37cb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_37ce:
	/* 0x37ce: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_37d3:
	/* 0x37d3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_37d8:
	/* 0x37d8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37dc:
	/* 0x37dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37e1:
	/* 0x37e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37e3:
	/* 0x37e3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37e5:
	/* 0x37e5: js     5c0e <generic_sleepable_preload+0x5c0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23566ULL;
	}
x86_l_37eb:
	/* 0x37eb: cmp    WORD PTR [r12+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_37f5:
	/* 0x37f5: je     3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5b;
	}
x86_l_37fb:
	/* 0x37fb: mov    ecx,DWORD PTR [r12+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3803:
	/* 0x3803: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3807:
	/* 0x3807: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_380b:
	/* 0x380b: cmp    WORD PTR [r12+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3815:
	/* 0x3815: je     3837 <generic_sleepable_preload+0x3837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3837;
	}
x86_l_3817:
	/* 0x3817: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_381a:
	/* 0x381a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_381f:
	/* 0x381f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3824:
	/* 0x3824: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3828:
	/* 0x3828: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_382d:
	/* 0x382d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_382f:
	/* 0x382f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3831:
	/* 0x3831: js     5d0d <generic_sleepable_preload+0x5d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23821ULL;
	}
x86_l_3837:
	/* 0x3837: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_383c:
	/* 0x383c: cmp    WORD PTR [r12+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_3846:
	/* 0x3846: je     3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5b;
	}
x86_l_384c:
	/* 0x384c: mov    ecx,DWORD PTR [r12+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_3854:
	/* 0x3854: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3858:
	/* 0x3858: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_385c:
	/* 0x385c: cmp    WORD PTR [r12+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_3866:
	/* 0x3866: je     3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5b;
	}
x86_l_386c:
	/* 0x386c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_386f:
	/* 0x386f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3874:
	/* 0x3874: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3879:
	/* 0x3879: jmp    3b53 <generic_sleepable_preload+0x3b53> */
	goto x86_l_3b53;
x86_l_387e:
	/* 0x387e: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3881:
	/* 0x3881: je     38a3 <generic_sleepable_preload+0x38a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38a3;
	}
x86_l_3883:
	/* 0x3883: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3886:
	/* 0x3886: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_388b:
	/* 0x388b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3890:
	/* 0x3890: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3894:
	/* 0x3894: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3899:
	/* 0x3899: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_389b:
	/* 0x389b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_389d:
	/* 0x389d: js     3b70 <generic_sleepable_preload+0x3b70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b70;
	}
x86_l_38a3:
	/* 0x38a3: cmp    WORD PTR [r12+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_38ad:
	/* 0x38ad: je     3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5b;
	}
x86_l_38b3:
	/* 0x38b3: mov    ecx,DWORD PTR [r12+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_38bb:
	/* 0x38bb: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_38bf:
	/* 0x38bf: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38c3:
	/* 0x38c3: cmp    WORD PTR [r12+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_38cd:
	/* 0x38cd: je     38ef <generic_sleepable_preload+0x38ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38ef;
	}
x86_l_38cf:
	/* 0x38cf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_38d2:
	/* 0x38d2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_38d7:
	/* 0x38d7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_38dc:
	/* 0x38dc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38e0:
	/* 0x38e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38e5:
	/* 0x38e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38e7:
	/* 0x38e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38e9:
	/* 0x38e9: js     3b7a <generic_sleepable_preload+0x3b7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b7a;
	}
x86_l_38ef:
	/* 0x38ef: cmp    WORD PTR [r12+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_38f9:
	/* 0x38f9: je     3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5b;
	}
x86_l_38ff:
	/* 0x38ff: mov    ecx,DWORD PTR [r12+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_3907:
	/* 0x3907: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_390b:
	/* 0x390b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_390f:
	/* 0x390f: cmp    WORD PTR [r12+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_3919:
	/* 0x3919: je     393b <generic_sleepable_preload+0x393b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_393b;
	}
x86_l_391b:
	/* 0x391b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_391e:
	/* 0x391e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3923:
	/* 0x3923: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3928:
	/* 0x3928: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_392c:
	/* 0x392c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3931:
	/* 0x3931: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3933:
	/* 0x3933: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3935:
	/* 0x3935: js     3b8b <generic_sleepable_preload+0x3b8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b8b;
	}
x86_l_393b:
	/* 0x393b: cmp    WORD PTR [r12+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_3945:
	/* 0x3945: je     3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5b;
	}
x86_l_394b:
	/* 0x394b: mov    ecx,DWORD PTR [r12+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_3953:
	/* 0x3953: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3957:
	/* 0x3957: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_395b:
	/* 0x395b: cmp    WORD PTR [r12+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_3965:
	/* 0x3965: je     3987 <generic_sleepable_preload+0x3987> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3987;
	}
x86_l_3967:
	/* 0x3967: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_396a:
	/* 0x396a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_396f:
	/* 0x396f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3974:
	/* 0x3974: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3978:
	/* 0x3978: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_397d:
	/* 0x397d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_397f:
	/* 0x397f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3981:
	/* 0x3981: js     3b9c <generic_sleepable_preload+0x3b9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b9c;
	}
x86_l_3987:
	/* 0x3987: cmp    WORD PTR [r12+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_3991:
	/* 0x3991: je     3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5b;
	}
x86_l_3997:
	/* 0x3997: mov    ecx,DWORD PTR [r12+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_399f:
	/* 0x399f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_39a3:
	/* 0x39a3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39a7:
	/* 0x39a7: cmp    WORD PTR [r12+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_39b1:
	/* 0x39b1: je     39d3 <generic_sleepable_preload+0x39d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39d3;
	}
x86_l_39b3:
	/* 0x39b3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_39b6:
	/* 0x39b6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_39bb:
	/* 0x39bb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_39c0:
	/* 0x39c0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39c4:
	/* 0x39c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39c9:
	/* 0x39c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39cb:
	/* 0x39cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39cd:
	/* 0x39cd: js     3bad <generic_sleepable_preload+0x3bad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3bad;
	}
x86_l_39d3:
	/* 0x39d3: cmp    WORD PTR [r12+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_39dd:
	/* 0x39dd: je     3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5b;
	}
x86_l_39e3:
	/* 0x39e3: mov    ecx,DWORD PTR [r12+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_39eb:
	/* 0x39eb: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_39ef:
	/* 0x39ef: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39f3:
	/* 0x39f3: cmp    WORD PTR [r12+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_39fd:
	/* 0x39fd: je     3a1f <generic_sleepable_preload+0x3a1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a1f;
	}
x86_l_39ff:
	/* 0x39ff: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3a02:
	/* 0x3a02: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a07:
	/* 0x3a07: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a0c:
	/* 0x3a0c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a10:
	/* 0x3a10: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a15:
	/* 0x3a15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a17:
	/* 0x3a17: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a19:
	/* 0x3a19: js     3bbe <generic_sleepable_preload+0x3bbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3bbe;
	}
x86_l_3a1f:
	/* 0x3a1f: cmp    WORD PTR [r12+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_3a29:
	/* 0x3a29: je     3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5b;
	}
x86_l_3a2f:
	/* 0x3a2f: mov    ecx,DWORD PTR [r12+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_3a37:
	/* 0x3a37: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3a3b:
	/* 0x3a3b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a3f:
	/* 0x3a3f: cmp    WORD PTR [r12+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_3a49:
	/* 0x3a49: je     3a6b <generic_sleepable_preload+0x3a6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a6b;
	}
x86_l_3a4b:
	/* 0x3a4b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3a4e:
	/* 0x3a4e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a53:
	/* 0x3a53: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a58:
	/* 0x3a58: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a5c:
	/* 0x3a5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a61:
	/* 0x3a61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a63:
	/* 0x3a63: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a65:
	/* 0x3a65: js     3c53 <generic_sleepable_preload+0x3c53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c53;
	}
x86_l_3a6b:
	/* 0x3a6b: cmp    WORD PTR [r12+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_3a75:
	/* 0x3a75: je     3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5b;
	}
x86_l_3a7b:
	/* 0x3a7b: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_3a7e:
	/* 0x3a7e: mov    ecx,DWORD PTR [r12+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_3a86:
	/* 0x3a86: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3a8a:
	/* 0x3a8a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a8e:
	/* 0x3a8e: cmp    WORD PTR [r12+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_3a98:
	/* 0x3a98: je     3aba <generic_sleepable_preload+0x3aba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3aba;
	}
x86_l_3a9a:
	/* 0x3a9a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3a9d:
	/* 0x3a9d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3aa2:
	/* 0x3aa2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3aa7:
	/* 0x3aa7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3aab:
	/* 0x3aab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ab0:
	/* 0x3ab0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ab2:
	/* 0x3ab2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ab4:
	/* 0x3ab4: js     5c8c <generic_sleepable_preload+0x5c8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23692ULL;
	}
x86_l_3aba:
	/* 0x3aba: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3abf:
	/* 0x3abf: cmp    WORD PTR [r12+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_3ac9:
	/* 0x3ac9: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_3acc:
	/* 0x3acc: je     3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5b;
	}
x86_l_3ad2:
	/* 0x3ad2: mov    ecx,DWORD PTR [r12+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3ada:
	/* 0x3ada: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3ade:
	/* 0x3ade: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ae2:
	/* 0x3ae2: cmp    WORD PTR [r12+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3aec:
	/* 0x3aec: je     3b0e <generic_sleepable_preload+0x3b0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b0e;
	}
x86_l_3aee:
	/* 0x3aee: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3af1:
	/* 0x3af1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3af6:
	/* 0x3af6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3afb:
	/* 0x3afb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3aff:
	/* 0x3aff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b04:
	/* 0x3b04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b06:
	/* 0x3b06: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b08:
	/* 0x3b08: js     5dac <generic_sleepable_preload+0x5dac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23980ULL;
	}
x86_l_3b0e:
	/* 0x3b0e: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b13:
	/* 0x3b13: cmp    WORD PTR [r12+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_3b1d:
	/* 0x3b1d: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_3b20:
	/* 0x3b20: je     3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5b;
	}
x86_l_3b26:
	/* 0x3b26: mov    ecx,DWORD PTR [r12+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_3b2e:
	/* 0x3b2e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3b32:
	/* 0x3b32: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b36:
	/* 0x3b36: cmp    WORD PTR [r12+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_3b40:
	/* 0x3b40: je     3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5b;
	}
x86_l_3b46:
	/* 0x3b46: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3b49:
	/* 0x3b49: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3b4e:
	/* 0x3b4e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b53:
	/* 0x3b53: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b57:
	/* 0x3b57: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b5c:
	/* 0x3b5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b5e:
	/* 0x3b5e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b60:
	/* 0x3b60: jns    3c5b <generic_sleepable_preload+0x3c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_3c5b;
	}
x86_l_3b66:
	/* 0x3b66: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_3b6b:
	/* 0x3b6b: jmp    3c58 <generic_sleepable_preload+0x3c58> */
	goto x86_l_3c58;
x86_l_3b70:
	/* 0x3b70: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3b75:
	/* 0x3b75: jmp    3c58 <generic_sleepable_preload+0x3c58> */
	goto x86_l_3c58;
x86_l_3b7a:
	/* 0x3b7a: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_3b7f:
	/* 0x3b7f: jmp    3c58 <generic_sleepable_preload+0x3c58> */
	goto x86_l_3c58;
x86_l_3b84:
	/* 0x3b84: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_3b89:
	/* 0x3b89: jmp    3bcd <generic_sleepable_preload+0x3bcd> */
	goto x86_l_3bcd;
x86_l_3b8b:
	/* 0x3b8b: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_3b90:
	/* 0x3b90: jmp    3c58 <generic_sleepable_preload+0x3c58> */
	goto x86_l_3c58;
x86_l_3b95:
	/* 0x3b95: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_3b9a:
	/* 0x3b9a: jmp    3bcd <generic_sleepable_preload+0x3bcd> */
	goto x86_l_3bcd;
x86_l_3b9c:
	/* 0x3b9c: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_3ba1:
	/* 0x3ba1: jmp    3c58 <generic_sleepable_preload+0x3c58> */
	goto x86_l_3c58;
x86_l_3ba6:
	/* 0x3ba6: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_3bab:
	/* 0x3bab: jmp    3bcd <generic_sleepable_preload+0x3bcd> */
	goto x86_l_3bcd;
x86_l_3bad:
	/* 0x3bad: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_3bb2:
	/* 0x3bb2: jmp    3c58 <generic_sleepable_preload+0x3c58> */
	goto x86_l_3c58;
x86_l_3bb7:
	/* 0x3bb7: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_3bbc:
	/* 0x3bbc: jmp    3bcd <generic_sleepable_preload+0x3bcd> */
	goto x86_l_3bcd;
x86_l_3bbe:
	/* 0x3bbe: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_3bc3:
	/* 0x3bc3: jmp    3c58 <generic_sleepable_preload+0x3c58> */
	goto x86_l_3c58;
x86_l_3bc8:
	/* 0x3bc8: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_3bcd:
	/* 0x3bcd: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3bd0:
	/* 0x3bd0: mov    ebp,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3bd5:
	/* 0x3bd5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3bd8:
	/* 0x3bd8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3bdd:
	/* 0x3bdd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3be2:
	/* 0x3be2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3be7:
	/* 0x3be7: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_3bea:
	/* 0x3bea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bec:
	/* 0x3bec: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_3bef:
	/* 0x3bef: jne    3d00 <generic_sleepable_preload+0x3d00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3d00;
	}
x86_l_3bf5:
	/* 0x3bf5: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_3bf8:
	/* 0x3bf8: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3bfc:
	/* 0x3bfc: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3c01:
	/* 0x3c01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c03:
	/* 0x3c03: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3c08:
	/* 0x3c08: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_3c10:
	/* 0x3c10: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3c17:
	/* 0x3c17: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3c1c:
	/* 0x3c1c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c21:
	/* 0x3c21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c23:
	/* 0x3c23: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3c26:
	/* 0x3c26: je     3cfd <generic_sleepable_preload+0x3cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cfd;
	}
x86_l_3c2c:
	/* 0x3c2c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3c2f:
	/* 0x3c2f: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3c36:
	/* 0x3c36: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c38:
	/* 0x3c38: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3c3d:
	/* 0x3c3d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3c42:
	/* 0x3c42: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3c45:
	/* 0x3c45: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_3c48:
	/* 0x3c48: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c4a:
	/* 0x3c4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c4c:
	/* 0x3c4c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c51:
	/* 0x3c51: jmp    3cbc <generic_sleepable_preload+0x3cbc> */
	goto x86_l_3cbc;
x86_l_3c53:
	/* 0x3c53: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_3c58:
	/* 0x3c58: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c5b:
	/* 0x3c5b: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_3c5e:
	/* 0x3c5e: jne    3d00 <generic_sleepable_preload+0x3d00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3d00;
	}
x86_l_3c64:
	/* 0x3c64: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_3c67:
	/* 0x3c67: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c6b:
	/* 0x3c6b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3c70:
	/* 0x3c70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c72:
	/* 0x3c72: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3c77:
	/* 0x3c77: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_3c7f:
	/* 0x3c7f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3c86:
	/* 0x3c86: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3c8b:
	/* 0x3c8b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c90:
	/* 0x3c90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c92:
	/* 0x3c92: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3c95:
	/* 0x3c95: je     3cfd <generic_sleepable_preload+0x3cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cfd;
	}
x86_l_3c97:
	/* 0x3c97: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3c9a:
	/* 0x3c9a: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3ca1:
	/* 0x3ca1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ca3:
	/* 0x3ca3: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ca8:
	/* 0x3ca8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3cad:
	/* 0x3cad: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3cb0:
	/* 0x3cb0: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_3cb3:
	/* 0x3cb3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3cb5:
	/* 0x3cb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cb7:
	/* 0x3cb7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3cbc:
	/* 0x3cbc: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3cbf:
	/* 0x3cbf: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_3cc2:
	/* 0x3cc2: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3cc7:
	/* 0x3cc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cc9:
	/* 0x3cc9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3ccc:
	/* 0x3ccc: je     3cfd <generic_sleepable_preload+0x3cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cfd;
	}
x86_l_3cce:
	/* 0x3cce: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_3cd1:
	/* 0x3cd1: je     3cfb <generic_sleepable_preload+0x3cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cfb;
	}
x86_l_3cd3:
	/* 0x3cd3: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3cd6:
	/* 0x3cd6: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3cda:
	/* 0x3cda: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3cdf:
	/* 0x3cdf: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3ce2:
	/* 0x3ce2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ce4:
	/* 0x3ce4: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3ce7:
	/* 0x3ce7: call   3cec <generic_sleepable_preload+0x3cec> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_3cec:
	/* 0x3cec: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_3cee:
	/* 0x3cee: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_3cf1:
	/* 0x3cf1: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_3cf3:
	/* 0x3cf3: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_3cf8:
	/* 0x3cf8: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_3cfb:
	/* 0x3cfb: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3cfd:
	/* 0x3cfd: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_3d00:
	/* 0x3d00: mov    eax,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3d05:
	/* 0x3d05: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_3d0a:
	/* 0x3d0a: je     4c6b <generic_sleepable_preload+0x4c6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19563ULL;
	}
x86_l_3d10:
	/* 0x3d10: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_3d12:
	/* 0x3d12: js     3d47 <generic_sleepable_preload+0x3d47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3d47;
	}
x86_l_3d14:
	/* 0x3d14: mov    eax,DWORD PTR [r12+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_3d19:
	/* 0x3d19: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3d1c:
	/* 0x3d1c: jle    3dca <generic_sleepable_preload+0x3dca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 15818ULL;
	}
x86_l_3d22:
	/* 0x3d22: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3d25:
	/* 0x3d25: je     3e34 <generic_sleepable_preload+0x3e34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15924ULL;
	}
x86_l_3d2b:
	/* 0x3d2b: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3d2e:
	/* 0x3d2e: je     3e3b <generic_sleepable_preload+0x3e3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15931ULL;
	}
x86_l_3d34:
	/* 0x3d34: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d37:
	/* 0x3d37: jne    3e4e <generic_sleepable_preload+0x3e4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15950ULL;
	}
x86_l_3d3d:
	/* 0x3d3d: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3d42:
	/* 0x3d42: jmp    3e47 <generic_sleepable_preload+0x3e47> */
	return 15943ULL;
x86_l_3d47:
	/* 0x3d47: movzx  eax,BYTE PTR [r12+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_3d50:
	/* 0x3d50: movzx  ecx,WORD PTR [r12+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_3d59:
	/* 0x3d59: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_3d5f:
	/* 0x3d5f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3d61:
	/* 0x3d61: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_3d64:
	/* 0x3d64: jle    3da3 <generic_sleepable_preload+0x3da3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3da3;
	}
x86_l_3d66:
	/* 0x3d66: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3d69:
	/* 0x3d69: jle    3dda <generic_sleepable_preload+0x3dda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 15834ULL;
	}
x86_l_3d6b:
	/* 0x3d6b: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_3d6e:
	/* 0x3d6e: jle    449d <generic_sleepable_preload+0x449d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 17565ULL;
	}
x86_l_3d74:
	/* 0x3d74: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3d79:
	/* 0x3d79: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_3d7c:
	/* 0x3d7c: je     44c2 <generic_sleepable_preload+0x44c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17602ULL;
	}
x86_l_3d82:
	/* 0x3d82: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3d87:
	/* 0x3d87: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_3d8a:
	/* 0x3d8a: je     44c2 <generic_sleepable_preload+0x44c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17602ULL;
	}
x86_l_3d90:
	/* 0x3d90: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3d95:
	/* 0x3d95: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_3d98:
	/* 0x3d98: je     44c2 <generic_sleepable_preload+0x44c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17602ULL;
	}
x86_l_3d9e:
	/* 0x3d9e: jmp    44d5 <generic_sleepable_preload+0x44d5> */
	return 17621ULL;
x86_l_3da3:
	/* 0x3da3: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3da6:
	/* 0x3da6: jg     3e07 <generic_sleepable_preload+0x3e07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 15879ULL;
	}
x86_l_3da8:
	/* 0x3da8: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_3dab:
	/* 0x3dab: jg     446e <generic_sleepable_preload+0x446e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 17518ULL;
	}
x86_l_3db1:
	/* 0x3db1: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_3db3:
	/* 0x3db3: je     44bd <generic_sleepable_preload+0x44bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17597ULL;
	}
	return 15801ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15801ULL: goto x86_l_3db9;
	case 15804ULL: goto x86_l_3dbc;
	case 15807ULL: goto x86_l_3dbf;
	case 15813ULL: goto x86_l_3dc5;
	case 15818ULL: goto x86_l_3dca;
	case 15820ULL: goto x86_l_3dcc;
	case 15822ULL: goto x86_l_3dce;
	case 15825ULL: goto x86_l_3dd1;
	case 15827ULL: goto x86_l_3dd3;
	case 15832ULL: goto x86_l_3dd8;
	case 15834ULL: goto x86_l_3dda;
	case 15837ULL: goto x86_l_3ddd;
	case 15843ULL: goto x86_l_3de3;
	case 15851ULL: goto x86_l_3deb;
	case 15854ULL: goto x86_l_3dee;
	case 15860ULL: goto x86_l_3df4;
	case 15865ULL: goto x86_l_3df9;
	case 15868ULL: goto x86_l_3dfc;
	case 15874ULL: goto x86_l_3e02;
	case 15879ULL: goto x86_l_3e07;
	case 15882ULL: goto x86_l_3e0a;
	case 15888ULL: goto x86_l_3e10;
	case 15896ULL: goto x86_l_3e18;
	case 15899ULL: goto x86_l_3e1b;
	case 15905ULL: goto x86_l_3e21;
	case 15910ULL: goto x86_l_3e26;
	case 15913ULL: goto x86_l_3e29;
	case 15919ULL: goto x86_l_3e2f;
	case 15924ULL: goto x86_l_3e34;
	case 15929ULL: goto x86_l_3e39;
	case 15931ULL: goto x86_l_3e3b;
	case 15936ULL: goto x86_l_3e40;
	case 15938ULL: goto x86_l_3e42;
	case 15943ULL: goto x86_l_3e47;
	case 15946ULL: goto x86_l_3e4a;
	case 15950ULL: goto x86_l_3e4e;
	case 15952ULL: goto x86_l_3e50;
	case 15955ULL: goto x86_l_3e53;
	case 15965ULL: goto x86_l_3e5d;
	case 15971ULL: goto x86_l_3e63;
	case 15978ULL: goto x86_l_3e6a;
	case 15981ULL: goto x86_l_3e6d;
	case 15989ULL: goto x86_l_3e75;
	case 15992ULL: goto x86_l_3e78;
	case 15996ULL: goto x86_l_3e7c;
	case 16005ULL: goto x86_l_3e85;
	case 16007ULL: goto x86_l_3e87;
	case 16013ULL: goto x86_l_3e8d;
	case 16016ULL: goto x86_l_3e90;
	case 16018ULL: goto x86_l_3e92;
	case 16021ULL: goto x86_l_3e95;
	case 16026ULL: goto x86_l_3e9a;
	case 16031ULL: goto x86_l_3e9f;
	case 16035ULL: goto x86_l_3ea3;
	case 16040ULL: goto x86_l_3ea8;
	case 16042ULL: goto x86_l_3eaa;
	case 16044ULL: goto x86_l_3eac;
	case 16050ULL: goto x86_l_3eb2;
	case 16060ULL: goto x86_l_3ebc;
	case 16066ULL: goto x86_l_3ec2;
	case 16074ULL: goto x86_l_3eca;
	case 16078ULL: goto x86_l_3ece;
	case 16082ULL: goto x86_l_3ed2;
	case 16092ULL: goto x86_l_3edc;
	case 16094ULL: goto x86_l_3ede;
	case 16097ULL: goto x86_l_3ee1;
	case 16102ULL: goto x86_l_3ee6;
	case 16107ULL: goto x86_l_3eeb;
	case 16111ULL: goto x86_l_3eef;
	case 16116ULL: goto x86_l_3ef4;
	case 16118ULL: goto x86_l_3ef6;
	case 16120ULL: goto x86_l_3ef8;
	case 16126ULL: goto x86_l_3efe;
	case 16136ULL: goto x86_l_3f08;
	case 16142ULL: goto x86_l_3f0e;
	case 16150ULL: goto x86_l_3f16;
	case 16154ULL: goto x86_l_3f1a;
	case 16158ULL: goto x86_l_3f1e;
	case 16168ULL: goto x86_l_3f28;
	case 16170ULL: goto x86_l_3f2a;
	case 16173ULL: goto x86_l_3f2d;
	case 16178ULL: goto x86_l_3f32;
	case 16183ULL: goto x86_l_3f37;
	case 16187ULL: goto x86_l_3f3b;
	case 16192ULL: goto x86_l_3f40;
	case 16194ULL: goto x86_l_3f42;
	case 16196ULL: goto x86_l_3f44;
	case 16202ULL: goto x86_l_3f4a;
	case 16212ULL: goto x86_l_3f54;
	case 16218ULL: goto x86_l_3f5a;
	case 16226ULL: goto x86_l_3f62;
	case 16230ULL: goto x86_l_3f66;
	case 16234ULL: goto x86_l_3f6a;
	case 16244ULL: goto x86_l_3f74;
	case 16246ULL: goto x86_l_3f76;
	case 16249ULL: goto x86_l_3f79;
	case 16254ULL: goto x86_l_3f7e;
	case 16259ULL: goto x86_l_3f83;
	case 16263ULL: goto x86_l_3f87;
	case 16268ULL: goto x86_l_3f8c;
	case 16270ULL: goto x86_l_3f8e;
	case 16272ULL: goto x86_l_3f90;
	case 16278ULL: goto x86_l_3f96;
	case 16288ULL: goto x86_l_3fa0;
	case 16294ULL: goto x86_l_3fa6;
	case 16302ULL: goto x86_l_3fae;
	case 16306ULL: goto x86_l_3fb2;
	case 16310ULL: goto x86_l_3fb6;
	case 16320ULL: goto x86_l_3fc0;
	case 16322ULL: goto x86_l_3fc2;
	case 16325ULL: goto x86_l_3fc5;
	case 16330ULL: goto x86_l_3fca;
	case 16335ULL: goto x86_l_3fcf;
	case 16339ULL: goto x86_l_3fd3;
	case 16344ULL: goto x86_l_3fd8;
	case 16346ULL: goto x86_l_3fda;
	case 16348ULL: goto x86_l_3fdc;
	case 16354ULL: goto x86_l_3fe2;
	case 16364ULL: goto x86_l_3fec;
	case 16370ULL: goto x86_l_3ff2;
	case 16378ULL: goto x86_l_3ffa;
	case 16382ULL: goto x86_l_3ffe;
	case 16386ULL: goto x86_l_4002;
	case 16396ULL: goto x86_l_400c;
	case 16398ULL: goto x86_l_400e;
	case 16401ULL: goto x86_l_4011;
	case 16406ULL: goto x86_l_4016;
	case 16411ULL: goto x86_l_401b;
	case 16415ULL: goto x86_l_401f;
	case 16420ULL: goto x86_l_4024;
	case 16422ULL: goto x86_l_4026;
	case 16424ULL: goto x86_l_4028;
	case 16430ULL: goto x86_l_402e;
	case 16440ULL: goto x86_l_4038;
	case 16446ULL: goto x86_l_403e;
	case 16454ULL: goto x86_l_4046;
	case 16458ULL: goto x86_l_404a;
	case 16462ULL: goto x86_l_404e;
	case 16472ULL: goto x86_l_4058;
	case 16474ULL: goto x86_l_405a;
	case 16477ULL: goto x86_l_405d;
	case 16482ULL: goto x86_l_4062;
	case 16487ULL: goto x86_l_4067;
	case 16491ULL: goto x86_l_406b;
	case 16496ULL: goto x86_l_4070;
	case 16498ULL: goto x86_l_4072;
	case 16500ULL: goto x86_l_4074;
	case 16506ULL: goto x86_l_407a;
	case 16516ULL: goto x86_l_4084;
	case 16522ULL: goto x86_l_408a;
	case 16530ULL: goto x86_l_4092;
	case 16534ULL: goto x86_l_4096;
	case 16538ULL: goto x86_l_409a;
	case 16548ULL: goto x86_l_40a4;
	case 16550ULL: goto x86_l_40a6;
	case 16553ULL: goto x86_l_40a9;
	case 16558ULL: goto x86_l_40ae;
	case 16563ULL: goto x86_l_40b3;
	case 16567ULL: goto x86_l_40b7;
	case 16572ULL: goto x86_l_40bc;
	case 16574ULL: goto x86_l_40be;
	case 16576ULL: goto x86_l_40c0;
	case 16582ULL: goto x86_l_40c6;
	case 16592ULL: goto x86_l_40d0;
	case 16598ULL: goto x86_l_40d6;
	case 16606ULL: goto x86_l_40de;
	case 16610ULL: goto x86_l_40e2;
	case 16614ULL: goto x86_l_40e6;
	case 16624ULL: goto x86_l_40f0;
	case 16626ULL: goto x86_l_40f2;
	case 16629ULL: goto x86_l_40f5;
	case 16634ULL: goto x86_l_40fa;
	case 16639ULL: goto x86_l_40ff;
	case 16643ULL: goto x86_l_4103;
	case 16648ULL: goto x86_l_4108;
	case 16650ULL: goto x86_l_410a;
	case 16652ULL: goto x86_l_410c;
	case 16658ULL: goto x86_l_4112;
	case 16663ULL: goto x86_l_4117;
	case 16673ULL: goto x86_l_4121;
	case 16679ULL: goto x86_l_4127;
	case 16687ULL: goto x86_l_412f;
	case 16691ULL: goto x86_l_4133;
	case 16695ULL: goto x86_l_4137;
	case 16705ULL: goto x86_l_4141;
	case 16711ULL: goto x86_l_4147;
	case 16714ULL: goto x86_l_414a;
	case 16719ULL: goto x86_l_414f;
	case 16724ULL: goto x86_l_4154;
	case 16729ULL: goto x86_l_4159;
	case 16732ULL: goto x86_l_415c;
	case 16734ULL: goto x86_l_415e;
	case 16737ULL: goto x86_l_4161;
	case 16742ULL: goto x86_l_4166;
	case 16747ULL: goto x86_l_416b;
	case 16751ULL: goto x86_l_416f;
	case 16756ULL: goto x86_l_4174;
	case 16758ULL: goto x86_l_4176;
	case 16760ULL: goto x86_l_4178;
	case 16766ULL: goto x86_l_417e;
	case 16776ULL: goto x86_l_4188;
	case 16782ULL: goto x86_l_418e;
	case 16790ULL: goto x86_l_4196;
	case 16794ULL: goto x86_l_419a;
	case 16798ULL: goto x86_l_419e;
	case 16808ULL: goto x86_l_41a8;
	case 16810ULL: goto x86_l_41aa;
	case 16813ULL: goto x86_l_41ad;
	case 16818ULL: goto x86_l_41b2;
	case 16823ULL: goto x86_l_41b7;
	case 16827ULL: goto x86_l_41bb;
	case 16832ULL: goto x86_l_41c0;
	case 16834ULL: goto x86_l_41c2;
	case 16836ULL: goto x86_l_41c4;
	case 16842ULL: goto x86_l_41ca;
	case 16852ULL: goto x86_l_41d4;
	case 16858ULL: goto x86_l_41da;
	case 16866ULL: goto x86_l_41e2;
	case 16870ULL: goto x86_l_41e6;
	case 16874ULL: goto x86_l_41ea;
	case 16884ULL: goto x86_l_41f4;
	case 16886ULL: goto x86_l_41f6;
	case 16889ULL: goto x86_l_41f9;
	case 16894ULL: goto x86_l_41fe;
	case 16899ULL: goto x86_l_4203;
	case 16903ULL: goto x86_l_4207;
	case 16908ULL: goto x86_l_420c;
	case 16910ULL: goto x86_l_420e;
	case 16912ULL: goto x86_l_4210;
	case 16918ULL: goto x86_l_4216;
	case 16928ULL: goto x86_l_4220;
	case 16934ULL: goto x86_l_4226;
	case 16942ULL: goto x86_l_422e;
	case 16946ULL: goto x86_l_4232;
	case 16950ULL: goto x86_l_4236;
	case 16960ULL: goto x86_l_4240;
	case 16962ULL: goto x86_l_4242;
	case 16965ULL: goto x86_l_4245;
	case 16970ULL: goto x86_l_424a;
	case 16975ULL: goto x86_l_424f;
	case 16979ULL: goto x86_l_4253;
	case 16984ULL: goto x86_l_4258;
	case 16986ULL: goto x86_l_425a;
	case 16988ULL: goto x86_l_425c;
	case 16994ULL: goto x86_l_4262;
	case 17004ULL: goto x86_l_426c;
	case 17010ULL: goto x86_l_4272;
	case 17018ULL: goto x86_l_427a;
	case 17022ULL: goto x86_l_427e;
	case 17026ULL: goto x86_l_4282;
	case 17036ULL: goto x86_l_428c;
	case 17038ULL: goto x86_l_428e;
	case 17041ULL: goto x86_l_4291;
	case 17046ULL: goto x86_l_4296;
	case 17051ULL: goto x86_l_429b;
	case 17055ULL: goto x86_l_429f;
	case 17060ULL: goto x86_l_42a4;
	case 17062ULL: goto x86_l_42a6;
	case 17064ULL: goto x86_l_42a8;
	case 17070ULL: goto x86_l_42ae;
	case 17080ULL: goto x86_l_42b8;
	case 17086ULL: goto x86_l_42be;
	case 17094ULL: goto x86_l_42c6;
	case 17098ULL: goto x86_l_42ca;
	case 17102ULL: goto x86_l_42ce;
	case 17112ULL: goto x86_l_42d8;
	case 17114ULL: goto x86_l_42da;
	case 17117ULL: goto x86_l_42dd;
	case 17122ULL: goto x86_l_42e2;
	case 17127ULL: goto x86_l_42e7;
	case 17131ULL: goto x86_l_42eb;
	case 17136ULL: goto x86_l_42f0;
	case 17138ULL: goto x86_l_42f2;
	case 17140ULL: goto x86_l_42f4;
	case 17146ULL: goto x86_l_42fa;
	case 17156ULL: goto x86_l_4304;
	case 17162ULL: goto x86_l_430a;
	case 17170ULL: goto x86_l_4312;
	case 17174ULL: goto x86_l_4316;
	case 17178ULL: goto x86_l_431a;
	case 17188ULL: goto x86_l_4324;
	case 17190ULL: goto x86_l_4326;
	case 17193ULL: goto x86_l_4329;
	case 17198ULL: goto x86_l_432e;
	case 17203ULL: goto x86_l_4333;
	case 17207ULL: goto x86_l_4337;
	case 17212ULL: goto x86_l_433c;
	case 17214ULL: goto x86_l_433e;
	case 17216ULL: goto x86_l_4340;
	case 17222ULL: goto x86_l_4346;
	case 17232ULL: goto x86_l_4350;
	case 17238ULL: goto x86_l_4356;
	case 17241ULL: goto x86_l_4359;
	case 17249ULL: goto x86_l_4361;
	case 17253ULL: goto x86_l_4365;
	case 17257ULL: goto x86_l_4369;
	case 17267ULL: goto x86_l_4373;
	case 17269ULL: goto x86_l_4375;
	case 17272ULL: goto x86_l_4378;
	case 17277ULL: goto x86_l_437d;
	case 17282ULL: goto x86_l_4382;
	case 17286ULL: goto x86_l_4386;
	case 17291ULL: goto x86_l_438b;
	case 17293ULL: goto x86_l_438d;
	case 17295ULL: goto x86_l_438f;
	case 17301ULL: goto x86_l_4395;
	case 17306ULL: goto x86_l_439a;
	case 17316ULL: goto x86_l_43a4;
	case 17319ULL: goto x86_l_43a7;
	case 17325ULL: goto x86_l_43ad;
	case 17333ULL: goto x86_l_43b5;
	case 17337ULL: goto x86_l_43b9;
	case 17341ULL: goto x86_l_43bd;
	case 17351ULL: goto x86_l_43c7;
	case 17353ULL: goto x86_l_43c9;
	case 17356ULL: goto x86_l_43cc;
	case 17361ULL: goto x86_l_43d1;
	case 17366ULL: goto x86_l_43d6;
	case 17370ULL: goto x86_l_43da;
	case 17375ULL: goto x86_l_43df;
	case 17377ULL: goto x86_l_43e1;
	case 17379ULL: goto x86_l_43e3;
	case 17385ULL: goto x86_l_43e9;
	case 17390ULL: goto x86_l_43ee;
	case 17400ULL: goto x86_l_43f8;
	case 17403ULL: goto x86_l_43fb;
	case 17409ULL: goto x86_l_4401;
	case 17417ULL: goto x86_l_4409;
	case 17421ULL: goto x86_l_440d;
	case 17425ULL: goto x86_l_4411;
	case 17435ULL: goto x86_l_441b;
	case 17441ULL: goto x86_l_4421;
	case 17444ULL: goto x86_l_4424;
	case 17449ULL: goto x86_l_4429;
	case 17454ULL: goto x86_l_442e;
	case 17458ULL: goto x86_l_4432;
	case 17463ULL: goto x86_l_4437;
	case 17465ULL: goto x86_l_4439;
	case 17467ULL: goto x86_l_443b;
	case 17473ULL: goto x86_l_4441;
	case 17478ULL: goto x86_l_4446;
	case 17483ULL: goto x86_l_444b;
	case 17488ULL: goto x86_l_4450;
	case 17493ULL: goto x86_l_4455;
	case 17501ULL: goto x86_l_445d;
	case 17504ULL: goto x86_l_4460;
	case 17506ULL: goto x86_l_4462;
	case 17511ULL: goto x86_l_4467;
	case 17514ULL: goto x86_l_446a;
	case 17516ULL: goto x86_l_446c;
	case 17518ULL: goto x86_l_446e;
	case 17523ULL: goto x86_l_4473;
	case 17526ULL: goto x86_l_4476;
	case 17528ULL: goto x86_l_4478;
	case 17533ULL: goto x86_l_447d;
	case 17536ULL: goto x86_l_4480;
	case 17538ULL: goto x86_l_4482;
	case 17540ULL: goto x86_l_4484;
	case 17548ULL: goto x86_l_448c;
	case 17551ULL: goto x86_l_448f;
	case 17553ULL: goto x86_l_4491;
	case 17558ULL: goto x86_l_4496;
	case 17561ULL: goto x86_l_4499;
	case 17563ULL: goto x86_l_449b;
	case 17565ULL: goto x86_l_449d;
	case 17570ULL: goto x86_l_44a2;
	case 17573ULL: goto x86_l_44a5;
	case 17575ULL: goto x86_l_44a7;
	case 17580ULL: goto x86_l_44ac;
	case 17583ULL: goto x86_l_44af;
	case 17585ULL: goto x86_l_44b1;
	case 17587ULL: goto x86_l_44b3;
	case 17592ULL: goto x86_l_44b8;
	case 17597ULL: goto x86_l_44bd;
	case 17602ULL: goto x86_l_44c2;
	case 17605ULL: goto x86_l_44c5;
	case 17607ULL: goto x86_l_44c7;
	case 17609ULL: goto x86_l_44c9;
	case 17614ULL: goto x86_l_44ce;
	case 17616ULL: goto x86_l_44d0;
	case 17621ULL: goto x86_l_44d5;
	case 17625ULL: goto x86_l_44d9;
	case 17630ULL: goto x86_l_44de;
	case 17632ULL: goto x86_l_44e0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3db9:
	/* 0x3db9: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_3dbc:
	/* 0x3dbc: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_3dbf:
	/* 0x3dbf: je     44c2 <generic_sleepable_preload+0x44c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c2;
	}
x86_l_3dc5:
	/* 0x3dc5: jmp    44d5 <generic_sleepable_preload+0x44d5> */
	goto x86_l_44d5;
x86_l_3dca:
	/* 0x3dca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3dcc:
	/* 0x3dcc: je     3e42 <generic_sleepable_preload+0x3e42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e42;
	}
x86_l_3dce:
	/* 0x3dce: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3dd1:
	/* 0x3dd1: jne    3e4e <generic_sleepable_preload+0x3e4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3e4e;
	}
x86_l_3dd3:
	/* 0x3dd3: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3dd8:
	/* 0x3dd8: jmp    3e47 <generic_sleepable_preload+0x3e47> */
	goto x86_l_3e47;
x86_l_3dda:
	/* 0x3dda: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_3ddd:
	/* 0x3ddd: jg     4455 <generic_sleepable_preload+0x4455> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4455;
	}
x86_l_3de3:
	/* 0x3de3: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3deb:
	/* 0x3deb: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3dee:
	/* 0x3dee: je     44c2 <generic_sleepable_preload+0x44c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c2;
	}
x86_l_3df4:
	/* 0x3df4: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3df9:
	/* 0x3df9: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_3dfc:
	/* 0x3dfc: je     44c2 <generic_sleepable_preload+0x44c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c2;
	}
x86_l_3e02:
	/* 0x3e02: jmp    44d5 <generic_sleepable_preload+0x44d5> */
	goto x86_l_44d5;
x86_l_3e07:
	/* 0x3e07: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_3e0a:
	/* 0x3e0a: jg     4484 <generic_sleepable_preload+0x4484> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4484;
	}
x86_l_3e10:
	/* 0x3e10: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3e18:
	/* 0x3e18: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3e1b:
	/* 0x3e1b: je     44c2 <generic_sleepable_preload+0x44c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c2;
	}
x86_l_3e21:
	/* 0x3e21: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3e26:
	/* 0x3e26: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_3e29:
	/* 0x3e29: je     44c2 <generic_sleepable_preload+0x44c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c2;
	}
x86_l_3e2f:
	/* 0x3e2f: jmp    44d5 <generic_sleepable_preload+0x44d5> */
	goto x86_l_44d5;
x86_l_3e34:
	/* 0x3e34: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3e39:
	/* 0x3e39: jmp    3e47 <generic_sleepable_preload+0x3e47> */
	goto x86_l_3e47;
x86_l_3e3b:
	/* 0x3e3b: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e40:
	/* 0x3e40: jmp    3e47 <generic_sleepable_preload+0x3e47> */
	goto x86_l_3e47;
x86_l_3e42:
	/* 0x3e42: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3e47:
	/* 0x3e47: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e4a:
	/* 0x3e4a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e4e:
	/* 0x3e4e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e50:
	/* 0x3e50: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_3e53:
	/* 0x3e53: cmp    WORD PTR [r12+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_3e5d:
	/* 0x3e5d: je     4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19259ULL;
	}
x86_l_3e63:
	/* 0x3e63: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_3e6a:
	/* 0x3e6a: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3e6d:
	/* 0x3e6d: mov    eax,DWORD PTR [r12+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_3e75:
	/* 0x3e75: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3e78:
	/* 0x3e78: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e7c:
	/* 0x3e7c: movzx  eax,WORD PTR [r12+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_3e85:
	/* 0x3e85: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_3e87:
	/* 0x3e87: je     4159 <generic_sleepable_preload+0x4159> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4159;
	}
x86_l_3e8d:
	/* 0x3e8d: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3e90:
	/* 0x3e90: je     3eb2 <generic_sleepable_preload+0x3eb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3eb2;
	}
x86_l_3e92:
	/* 0x3e92: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3e95:
	/* 0x3e95: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3e9a:
	/* 0x3e9a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3e9f:
	/* 0x3e9f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ea3:
	/* 0x3ea3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ea8:
	/* 0x3ea8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3eaa:
	/* 0x3eaa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3eac:
	/* 0x3eac: js     444b <generic_sleepable_preload+0x444b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_444b;
	}
x86_l_3eb2:
	/* 0x3eb2: cmp    WORD PTR [r12+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_3ebc:
	/* 0x3ebc: je     4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19259ULL;
	}
x86_l_3ec2:
	/* 0x3ec2: mov    ecx,DWORD PTR [r12+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_3eca:
	/* 0x3eca: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3ece:
	/* 0x3ece: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ed2:
	/* 0x3ed2: cmp    WORD PTR [r12+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_3edc:
	/* 0x3edc: je     3efe <generic_sleepable_preload+0x3efe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3efe;
	}
x86_l_3ede:
	/* 0x3ede: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3ee1:
	/* 0x3ee1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3ee6:
	/* 0x3ee6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3eeb:
	/* 0x3eeb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3eef:
	/* 0x3eef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ef4:
	/* 0x3ef4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ef6:
	/* 0x3ef6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ef8:
	/* 0x3ef8: js     44b3 <generic_sleepable_preload+0x44b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_44b3;
	}
x86_l_3efe:
	/* 0x3efe: cmp    WORD PTR [r12+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_3f08:
	/* 0x3f08: je     4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19259ULL;
	}
x86_l_3f0e:
	/* 0x3f0e: mov    ecx,DWORD PTR [r12+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_3f16:
	/* 0x3f16: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3f1a:
	/* 0x3f1a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f1e:
	/* 0x3f1e: cmp    WORD PTR [r12+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_3f28:
	/* 0x3f28: je     3f4a <generic_sleepable_preload+0x3f4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f4a;
	}
x86_l_3f2a:
	/* 0x3f2a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3f2d:
	/* 0x3f2d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3f32:
	/* 0x3f32: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3f37:
	/* 0x3f37: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f3b:
	/* 0x3f3b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f40:
	/* 0x3f40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f42:
	/* 0x3f42: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3f44:
	/* 0x3f44: js     4aef <generic_sleepable_preload+0x4aef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19183ULL;
	}
x86_l_3f4a:
	/* 0x3f4a: cmp    WORD PTR [r12+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_3f54:
	/* 0x3f54: je     4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19259ULL;
	}
x86_l_3f5a:
	/* 0x3f5a: mov    ecx,DWORD PTR [r12+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_3f62:
	/* 0x3f62: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3f66:
	/* 0x3f66: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f6a:
	/* 0x3f6a: cmp    WORD PTR [r12+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_3f74:
	/* 0x3f74: je     3f96 <generic_sleepable_preload+0x3f96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f96;
	}
x86_l_3f76:
	/* 0x3f76: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3f79:
	/* 0x3f79: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3f7e:
	/* 0x3f7e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3f83:
	/* 0x3f83: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f87:
	/* 0x3f87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f8c:
	/* 0x3f8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f8e:
	/* 0x3f8e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3f90:
	/* 0x3f90: js     4b00 <generic_sleepable_preload+0x4b00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19200ULL;
	}
x86_l_3f96:
	/* 0x3f96: cmp    WORD PTR [r12+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_3fa0:
	/* 0x3fa0: je     4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19259ULL;
	}
x86_l_3fa6:
	/* 0x3fa6: mov    ecx,DWORD PTR [r12+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_3fae:
	/* 0x3fae: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3fb2:
	/* 0x3fb2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fb6:
	/* 0x3fb6: cmp    WORD PTR [r12+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_3fc0:
	/* 0x3fc0: je     3fe2 <generic_sleepable_preload+0x3fe2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fe2;
	}
x86_l_3fc2:
	/* 0x3fc2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3fc5:
	/* 0x3fc5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3fca:
	/* 0x3fca: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3fcf:
	/* 0x3fcf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fd3:
	/* 0x3fd3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3fd8:
	/* 0x3fd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fda:
	/* 0x3fda: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3fdc:
	/* 0x3fdc: js     4b11 <generic_sleepable_preload+0x4b11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19217ULL;
	}
x86_l_3fe2:
	/* 0x3fe2: cmp    WORD PTR [r12+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_3fec:
	/* 0x3fec: je     4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19259ULL;
	}
x86_l_3ff2:
	/* 0x3ff2: mov    ecx,DWORD PTR [r12+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_3ffa:
	/* 0x3ffa: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3ffe:
	/* 0x3ffe: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4002:
	/* 0x4002: cmp    WORD PTR [r12+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_400c:
	/* 0x400c: je     402e <generic_sleepable_preload+0x402e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_402e;
	}
x86_l_400e:
	/* 0x400e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4011:
	/* 0x4011: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4016:
	/* 0x4016: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_401b:
	/* 0x401b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_401f:
	/* 0x401f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4024:
	/* 0x4024: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4026:
	/* 0x4026: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4028:
	/* 0x4028: js     4b22 <generic_sleepable_preload+0x4b22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19234ULL;
	}
x86_l_402e:
	/* 0x402e: cmp    WORD PTR [r12+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_4038:
	/* 0x4038: je     4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19259ULL;
	}
x86_l_403e:
	/* 0x403e: mov    ecx,DWORD PTR [r12+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_4046:
	/* 0x4046: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_404a:
	/* 0x404a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_404e:
	/* 0x404e: cmp    WORD PTR [r12+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_4058:
	/* 0x4058: je     407a <generic_sleepable_preload+0x407a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_407a;
	}
x86_l_405a:
	/* 0x405a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_405d:
	/* 0x405d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4062:
	/* 0x4062: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4067:
	/* 0x4067: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_406b:
	/* 0x406b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4070:
	/* 0x4070: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4072:
	/* 0x4072: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4074:
	/* 0x4074: js     4b33 <generic_sleepable_preload+0x4b33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19251ULL;
	}
x86_l_407a:
	/* 0x407a: cmp    WORD PTR [r12+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_4084:
	/* 0x4084: je     4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19259ULL;
	}
x86_l_408a:
	/* 0x408a: mov    ecx,DWORD PTR [r12+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_4092:
	/* 0x4092: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4096:
	/* 0x4096: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_409a:
	/* 0x409a: cmp    WORD PTR [r12+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_40a4:
	/* 0x40a4: je     40c6 <generic_sleepable_preload+0x40c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40c6;
	}
x86_l_40a6:
	/* 0x40a6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_40a9:
	/* 0x40a9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_40ae:
	/* 0x40ae: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_40b3:
	/* 0x40b3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40b7:
	/* 0x40b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_40bc:
	/* 0x40bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40be:
	/* 0x40be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_40c0:
	/* 0x40c0: js     5c1b <generic_sleepable_preload+0x5c1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23579ULL;
	}
x86_l_40c6:
	/* 0x40c6: cmp    WORD PTR [r12+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_40d0:
	/* 0x40d0: je     4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19259ULL;
	}
x86_l_40d6:
	/* 0x40d6: mov    ecx,DWORD PTR [r12+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_40de:
	/* 0x40de: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_40e2:
	/* 0x40e2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40e6:
	/* 0x40e6: cmp    WORD PTR [r12+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_40f0:
	/* 0x40f0: je     4112 <generic_sleepable_preload+0x4112> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4112;
	}
x86_l_40f2:
	/* 0x40f2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_40f5:
	/* 0x40f5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_40fa:
	/* 0x40fa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_40ff:
	/* 0x40ff: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4103:
	/* 0x4103: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4108:
	/* 0x4108: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_410a:
	/* 0x410a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_410c:
	/* 0x410c: js     5d1f <generic_sleepable_preload+0x5d1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23839ULL;
	}
x86_l_4112:
	/* 0x4112: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4117:
	/* 0x4117: cmp    WORD PTR [r12+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_4121:
	/* 0x4121: je     4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19259ULL;
	}
x86_l_4127:
	/* 0x4127: mov    ecx,DWORD PTR [r12+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_412f:
	/* 0x412f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4133:
	/* 0x4133: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4137:
	/* 0x4137: cmp    WORD PTR [r12+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_4141:
	/* 0x4141: je     4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19259ULL;
	}
x86_l_4147:
	/* 0x4147: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_414a:
	/* 0x414a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_414f:
	/* 0x414f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4154:
	/* 0x4154: jmp    442e <generic_sleepable_preload+0x442e> */
	goto x86_l_442e;
x86_l_4159:
	/* 0x4159: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_415c:
	/* 0x415c: je     417e <generic_sleepable_preload+0x417e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_417e;
	}
x86_l_415e:
	/* 0x415e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4161:
	/* 0x4161: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4166:
	/* 0x4166: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_416b:
	/* 0x416b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_416f:
	/* 0x416f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4174:
	/* 0x4174: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4176:
	/* 0x4176: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4178:
	/* 0x4178: js     444b <generic_sleepable_preload+0x444b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_444b;
	}
x86_l_417e:
	/* 0x417e: cmp    WORD PTR [r12+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_4188:
	/* 0x4188: je     4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19259ULL;
	}
x86_l_418e:
	/* 0x418e: mov    ecx,DWORD PTR [r12+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_4196:
	/* 0x4196: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_419a:
	/* 0x419a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_419e:
	/* 0x419e: cmp    WORD PTR [r12+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_41a8:
	/* 0x41a8: je     41ca <generic_sleepable_preload+0x41ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41ca;
	}
x86_l_41aa:
	/* 0x41aa: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_41ad:
	/* 0x41ad: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_41b2:
	/* 0x41b2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_41b7:
	/* 0x41b7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41bb:
	/* 0x41bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41c0:
	/* 0x41c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41c2:
	/* 0x41c2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_41c4:
	/* 0x41c4: js     44b3 <generic_sleepable_preload+0x44b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_44b3;
	}
x86_l_41ca:
	/* 0x41ca: cmp    WORD PTR [r12+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_41d4:
	/* 0x41d4: je     4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19259ULL;
	}
x86_l_41da:
	/* 0x41da: mov    ecx,DWORD PTR [r12+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_41e2:
	/* 0x41e2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_41e6:
	/* 0x41e6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41ea:
	/* 0x41ea: cmp    WORD PTR [r12+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_41f4:
	/* 0x41f4: je     4216 <generic_sleepable_preload+0x4216> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4216;
	}
x86_l_41f6:
	/* 0x41f6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_41f9:
	/* 0x41f9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_41fe:
	/* 0x41fe: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4203:
	/* 0x4203: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4207:
	/* 0x4207: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_420c:
	/* 0x420c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_420e:
	/* 0x420e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4210:
	/* 0x4210: js     4aef <generic_sleepable_preload+0x4aef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19183ULL;
	}
x86_l_4216:
	/* 0x4216: cmp    WORD PTR [r12+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_4220:
	/* 0x4220: je     4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19259ULL;
	}
x86_l_4226:
	/* 0x4226: mov    ecx,DWORD PTR [r12+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_422e:
	/* 0x422e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4232:
	/* 0x4232: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4236:
	/* 0x4236: cmp    WORD PTR [r12+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_4240:
	/* 0x4240: je     4262 <generic_sleepable_preload+0x4262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4262;
	}
x86_l_4242:
	/* 0x4242: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4245:
	/* 0x4245: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_424a:
	/* 0x424a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_424f:
	/* 0x424f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4253:
	/* 0x4253: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4258:
	/* 0x4258: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_425a:
	/* 0x425a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_425c:
	/* 0x425c: js     4b00 <generic_sleepable_preload+0x4b00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19200ULL;
	}
x86_l_4262:
	/* 0x4262: cmp    WORD PTR [r12+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_426c:
	/* 0x426c: je     4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19259ULL;
	}
x86_l_4272:
	/* 0x4272: mov    ecx,DWORD PTR [r12+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_427a:
	/* 0x427a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_427e:
	/* 0x427e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4282:
	/* 0x4282: cmp    WORD PTR [r12+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_428c:
	/* 0x428c: je     42ae <generic_sleepable_preload+0x42ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42ae;
	}
x86_l_428e:
	/* 0x428e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4291:
	/* 0x4291: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4296:
	/* 0x4296: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_429b:
	/* 0x429b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_429f:
	/* 0x429f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42a4:
	/* 0x42a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42a6:
	/* 0x42a6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42a8:
	/* 0x42a8: js     4b11 <generic_sleepable_preload+0x4b11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19217ULL;
	}
x86_l_42ae:
	/* 0x42ae: cmp    WORD PTR [r12+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_42b8:
	/* 0x42b8: je     4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19259ULL;
	}
x86_l_42be:
	/* 0x42be: mov    ecx,DWORD PTR [r12+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_42c6:
	/* 0x42c6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_42ca:
	/* 0x42ca: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42ce:
	/* 0x42ce: cmp    WORD PTR [r12+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_42d8:
	/* 0x42d8: je     42fa <generic_sleepable_preload+0x42fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42fa;
	}
x86_l_42da:
	/* 0x42da: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_42dd:
	/* 0x42dd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_42e2:
	/* 0x42e2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_42e7:
	/* 0x42e7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42eb:
	/* 0x42eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42f0:
	/* 0x42f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42f2:
	/* 0x42f2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42f4:
	/* 0x42f4: js     4b22 <generic_sleepable_preload+0x4b22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19234ULL;
	}
x86_l_42fa:
	/* 0x42fa: cmp    WORD PTR [r12+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_4304:
	/* 0x4304: je     4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19259ULL;
	}
x86_l_430a:
	/* 0x430a: mov    ecx,DWORD PTR [r12+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_4312:
	/* 0x4312: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4316:
	/* 0x4316: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_431a:
	/* 0x431a: cmp    WORD PTR [r12+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_4324:
	/* 0x4324: je     4346 <generic_sleepable_preload+0x4346> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4346;
	}
x86_l_4326:
	/* 0x4326: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4329:
	/* 0x4329: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_432e:
	/* 0x432e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4333:
	/* 0x4333: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4337:
	/* 0x4337: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_433c:
	/* 0x433c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_433e:
	/* 0x433e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4340:
	/* 0x4340: js     4b33 <generic_sleepable_preload+0x4b33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19251ULL;
	}
x86_l_4346:
	/* 0x4346: cmp    WORD PTR [r12+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_4350:
	/* 0x4350: je     4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19259ULL;
	}
x86_l_4356:
	/* 0x4356: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_4359:
	/* 0x4359: mov    ecx,DWORD PTR [r12+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_4361:
	/* 0x4361: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4365:
	/* 0x4365: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4369:
	/* 0x4369: cmp    WORD PTR [r12+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_4373:
	/* 0x4373: je     4395 <generic_sleepable_preload+0x4395> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4395;
	}
x86_l_4375:
	/* 0x4375: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4378:
	/* 0x4378: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_437d:
	/* 0x437d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4382:
	/* 0x4382: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4386:
	/* 0x4386: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_438b:
	/* 0x438b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_438d:
	/* 0x438d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_438f:
	/* 0x438f: js     5c99 <generic_sleepable_preload+0x5c99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23705ULL;
	}
x86_l_4395:
	/* 0x4395: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_439a:
	/* 0x439a: cmp    WORD PTR [r12+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_43a4:
	/* 0x43a4: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_43a7:
	/* 0x43a7: je     4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19259ULL;
	}
x86_l_43ad:
	/* 0x43ad: mov    ecx,DWORD PTR [r12+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_43b5:
	/* 0x43b5: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_43b9:
	/* 0x43b9: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43bd:
	/* 0x43bd: cmp    WORD PTR [r12+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_43c7:
	/* 0x43c7: je     43e9 <generic_sleepable_preload+0x43e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43e9;
	}
x86_l_43c9:
	/* 0x43c9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_43cc:
	/* 0x43cc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_43d1:
	/* 0x43d1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_43d6:
	/* 0x43d6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43da:
	/* 0x43da: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_43df:
	/* 0x43df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43e1:
	/* 0x43e1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_43e3:
	/* 0x43e3: js     5dc1 <generic_sleepable_preload+0x5dc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24001ULL;
	}
x86_l_43e9:
	/* 0x43e9: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43ee:
	/* 0x43ee: cmp    WORD PTR [r12+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_43f8:
	/* 0x43f8: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_43fb:
	/* 0x43fb: je     4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19259ULL;
	}
x86_l_4401:
	/* 0x4401: mov    ecx,DWORD PTR [r12+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_4409:
	/* 0x4409: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_440d:
	/* 0x440d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4411:
	/* 0x4411: cmp    WORD PTR [r12+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_441b:
	/* 0x441b: je     4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19259ULL;
	}
x86_l_4421:
	/* 0x4421: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4424:
	/* 0x4424: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4429:
	/* 0x4429: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_442e:
	/* 0x442e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4432:
	/* 0x4432: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4437:
	/* 0x4437: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4439:
	/* 0x4439: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_443b:
	/* 0x443b: jns    4b3b <generic_sleepable_preload+0x4b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 19259ULL;
	}
x86_l_4441:
	/* 0x4441: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_4446:
	/* 0x4446: jmp    4b38 <generic_sleepable_preload+0x4b38> */
	return 19256ULL;
x86_l_444b:
	/* 0x444b: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_4450:
	/* 0x4450: jmp    4b38 <generic_sleepable_preload+0x4b38> */
	return 19256ULL;
x86_l_4455:
	/* 0x4455: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_445d:
	/* 0x445d: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_4460:
	/* 0x4460: je     44c2 <generic_sleepable_preload+0x44c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c2;
	}
x86_l_4462:
	/* 0x4462: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4467:
	/* 0x4467: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_446a:
	/* 0x446a: je     44c2 <generic_sleepable_preload+0x44c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c2;
	}
x86_l_446c:
	/* 0x446c: jmp    44d5 <generic_sleepable_preload+0x44d5> */
	goto x86_l_44d5;
x86_l_446e:
	/* 0x446e: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4473:
	/* 0x4473: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_4476:
	/* 0x4476: je     44c2 <generic_sleepable_preload+0x44c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c2;
	}
x86_l_4478:
	/* 0x4478: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_447d:
	/* 0x447d: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4480:
	/* 0x4480: je     44c2 <generic_sleepable_preload+0x44c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c2;
	}
x86_l_4482:
	/* 0x4482: jmp    44d5 <generic_sleepable_preload+0x44d5> */
	goto x86_l_44d5;
x86_l_4484:
	/* 0x4484: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_448c:
	/* 0x448c: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_448f:
	/* 0x448f: je     44c2 <generic_sleepable_preload+0x44c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c2;
	}
x86_l_4491:
	/* 0x4491: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4496:
	/* 0x4496: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4499:
	/* 0x4499: je     44c2 <generic_sleepable_preload+0x44c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c2;
	}
x86_l_449b:
	/* 0x449b: jmp    44d5 <generic_sleepable_preload+0x44d5> */
	goto x86_l_44d5;
x86_l_449d:
	/* 0x449d: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_44a2:
	/* 0x44a2: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_44a5:
	/* 0x44a5: je     44c2 <generic_sleepable_preload+0x44c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c2;
	}
x86_l_44a7:
	/* 0x44a7: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_44ac:
	/* 0x44ac: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_44af:
	/* 0x44af: je     44c2 <generic_sleepable_preload+0x44c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c2;
	}
x86_l_44b1:
	/* 0x44b1: jmp    44d5 <generic_sleepable_preload+0x44d5> */
	goto x86_l_44d5;
x86_l_44b3:
	/* 0x44b3: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_44b8:
	/* 0x44b8: jmp    4b38 <generic_sleepable_preload+0x4b38> */
	return 19256ULL;
x86_l_44bd:
	/* 0x44bd: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_44c2:
	/* 0x44c2: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_44c5:
	/* 0x44c5: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_44c7:
	/* 0x44c7: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_44c9:
	/* 0x44c9: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_44ce:
	/* 0x44ce: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_44d0:
	/* 0x44d0: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_44d5:
	/* 0x44d5: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44d9:
	/* 0x44d9: mov    ebp,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44de:
	/* 0x44de: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_44e0:
	/* 0x44e0: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
	return 17635ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 17635ULL: goto x86_l_44e3;
	case 17645ULL: goto x86_l_44ed;
	case 17651ULL: goto x86_l_44f3;
	case 17658ULL: goto x86_l_44fa;
	case 17661ULL: goto x86_l_44fd;
	case 17669ULL: goto x86_l_4505;
	case 17672ULL: goto x86_l_4508;
	case 17676ULL: goto x86_l_450c;
	case 17685ULL: goto x86_l_4515;
	case 17687ULL: goto x86_l_4517;
	case 17693ULL: goto x86_l_451d;
	case 17696ULL: goto x86_l_4520;
	case 17698ULL: goto x86_l_4522;
	case 17701ULL: goto x86_l_4525;
	case 17706ULL: goto x86_l_452a;
	case 17711ULL: goto x86_l_452f;
	case 17715ULL: goto x86_l_4533;
	case 17720ULL: goto x86_l_4538;
	case 17722ULL: goto x86_l_453a;
	case 17724ULL: goto x86_l_453c;
	case 17730ULL: goto x86_l_4542;
	case 17740ULL: goto x86_l_454c;
	case 17746ULL: goto x86_l_4552;
	case 17754ULL: goto x86_l_455a;
	case 17758ULL: goto x86_l_455e;
	case 17762ULL: goto x86_l_4562;
	case 17772ULL: goto x86_l_456c;
	case 17774ULL: goto x86_l_456e;
	case 17777ULL: goto x86_l_4571;
	case 17782ULL: goto x86_l_4576;
	case 17787ULL: goto x86_l_457b;
	case 17791ULL: goto x86_l_457f;
	case 17796ULL: goto x86_l_4584;
	case 17798ULL: goto x86_l_4586;
	case 17800ULL: goto x86_l_4588;
	case 17806ULL: goto x86_l_458e;
	case 17816ULL: goto x86_l_4598;
	case 17822ULL: goto x86_l_459e;
	case 17830ULL: goto x86_l_45a6;
	case 17834ULL: goto x86_l_45aa;
	case 17838ULL: goto x86_l_45ae;
	case 17848ULL: goto x86_l_45b8;
	case 17850ULL: goto x86_l_45ba;
	case 17853ULL: goto x86_l_45bd;
	case 17858ULL: goto x86_l_45c2;
	case 17863ULL: goto x86_l_45c7;
	case 17867ULL: goto x86_l_45cb;
	case 17872ULL: goto x86_l_45d0;
	case 17874ULL: goto x86_l_45d2;
	case 17876ULL: goto x86_l_45d4;
	case 17882ULL: goto x86_l_45da;
	case 17892ULL: goto x86_l_45e4;
	case 17898ULL: goto x86_l_45ea;
	case 17906ULL: goto x86_l_45f2;
	case 17910ULL: goto x86_l_45f6;
	case 17914ULL: goto x86_l_45fa;
	case 17924ULL: goto x86_l_4604;
	case 17926ULL: goto x86_l_4606;
	case 17929ULL: goto x86_l_4609;
	case 17934ULL: goto x86_l_460e;
	case 17939ULL: goto x86_l_4613;
	case 17943ULL: goto x86_l_4617;
	case 17948ULL: goto x86_l_461c;
	case 17950ULL: goto x86_l_461e;
	case 17952ULL: goto x86_l_4620;
	case 17958ULL: goto x86_l_4626;
	case 17968ULL: goto x86_l_4630;
	case 17974ULL: goto x86_l_4636;
	case 17982ULL: goto x86_l_463e;
	case 17986ULL: goto x86_l_4642;
	case 17990ULL: goto x86_l_4646;
	case 18000ULL: goto x86_l_4650;
	case 18002ULL: goto x86_l_4652;
	case 18005ULL: goto x86_l_4655;
	case 18010ULL: goto x86_l_465a;
	case 18015ULL: goto x86_l_465f;
	case 18019ULL: goto x86_l_4663;
	case 18024ULL: goto x86_l_4668;
	case 18026ULL: goto x86_l_466a;
	case 18028ULL: goto x86_l_466c;
	case 18034ULL: goto x86_l_4672;
	case 18044ULL: goto x86_l_467c;
	case 18050ULL: goto x86_l_4682;
	case 18058ULL: goto x86_l_468a;
	case 18062ULL: goto x86_l_468e;
	case 18066ULL: goto x86_l_4692;
	case 18076ULL: goto x86_l_469c;
	case 18078ULL: goto x86_l_469e;
	case 18081ULL: goto x86_l_46a1;
	case 18086ULL: goto x86_l_46a6;
	case 18091ULL: goto x86_l_46ab;
	case 18095ULL: goto x86_l_46af;
	case 18100ULL: goto x86_l_46b4;
	case 18102ULL: goto x86_l_46b6;
	case 18104ULL: goto x86_l_46b8;
	case 18110ULL: goto x86_l_46be;
	case 18120ULL: goto x86_l_46c8;
	case 18126ULL: goto x86_l_46ce;
	case 18134ULL: goto x86_l_46d6;
	case 18138ULL: goto x86_l_46da;
	case 18142ULL: goto x86_l_46de;
	case 18152ULL: goto x86_l_46e8;
	case 18154ULL: goto x86_l_46ea;
	case 18157ULL: goto x86_l_46ed;
	case 18162ULL: goto x86_l_46f2;
	case 18167ULL: goto x86_l_46f7;
	case 18171ULL: goto x86_l_46fb;
	case 18176ULL: goto x86_l_4700;
	case 18178ULL: goto x86_l_4702;
	case 18180ULL: goto x86_l_4704;
	case 18186ULL: goto x86_l_470a;
	case 18196ULL: goto x86_l_4714;
	case 18202ULL: goto x86_l_471a;
	case 18210ULL: goto x86_l_4722;
	case 18214ULL: goto x86_l_4726;
	case 18218ULL: goto x86_l_472a;
	case 18228ULL: goto x86_l_4734;
	case 18230ULL: goto x86_l_4736;
	case 18233ULL: goto x86_l_4739;
	case 18238ULL: goto x86_l_473e;
	case 18243ULL: goto x86_l_4743;
	case 18247ULL: goto x86_l_4747;
	case 18252ULL: goto x86_l_474c;
	case 18254ULL: goto x86_l_474e;
	case 18256ULL: goto x86_l_4750;
	case 18262ULL: goto x86_l_4756;
	case 18272ULL: goto x86_l_4760;
	case 18278ULL: goto x86_l_4766;
	case 18286ULL: goto x86_l_476e;
	case 18290ULL: goto x86_l_4772;
	case 18294ULL: goto x86_l_4776;
	case 18304ULL: goto x86_l_4780;
	case 18306ULL: goto x86_l_4782;
	case 18309ULL: goto x86_l_4785;
	case 18314ULL: goto x86_l_478a;
	case 18319ULL: goto x86_l_478f;
	case 18323ULL: goto x86_l_4793;
	case 18328ULL: goto x86_l_4798;
	case 18330ULL: goto x86_l_479a;
	case 18332ULL: goto x86_l_479c;
	case 18338ULL: goto x86_l_47a2;
	case 18343ULL: goto x86_l_47a7;
	case 18353ULL: goto x86_l_47b1;
	case 18359ULL: goto x86_l_47b7;
	case 18367ULL: goto x86_l_47bf;
	case 18371ULL: goto x86_l_47c3;
	case 18375ULL: goto x86_l_47c7;
	case 18385ULL: goto x86_l_47d1;
	case 18391ULL: goto x86_l_47d7;
	case 18394ULL: goto x86_l_47da;
	case 18399ULL: goto x86_l_47df;
	case 18404ULL: goto x86_l_47e4;
	case 18409ULL: goto x86_l_47e9;
	case 18412ULL: goto x86_l_47ec;
	case 18414ULL: goto x86_l_47ee;
	case 18417ULL: goto x86_l_47f1;
	case 18422ULL: goto x86_l_47f6;
	case 18427ULL: goto x86_l_47fb;
	case 18431ULL: goto x86_l_47ff;
	case 18436ULL: goto x86_l_4804;
	case 18438ULL: goto x86_l_4806;
	case 18440ULL: goto x86_l_4808;
	case 18446ULL: goto x86_l_480e;
	case 18456ULL: goto x86_l_4818;
	case 18462ULL: goto x86_l_481e;
	case 18470ULL: goto x86_l_4826;
	case 18474ULL: goto x86_l_482a;
	case 18478ULL: goto x86_l_482e;
	case 18488ULL: goto x86_l_4838;
	case 18490ULL: goto x86_l_483a;
	case 18493ULL: goto x86_l_483d;
	case 18498ULL: goto x86_l_4842;
	case 18503ULL: goto x86_l_4847;
	case 18507ULL: goto x86_l_484b;
	case 18512ULL: goto x86_l_4850;
	case 18514ULL: goto x86_l_4852;
	case 18516ULL: goto x86_l_4854;
	case 18522ULL: goto x86_l_485a;
	case 18532ULL: goto x86_l_4864;
	case 18538ULL: goto x86_l_486a;
	case 18546ULL: goto x86_l_4872;
	case 18550ULL: goto x86_l_4876;
	case 18554ULL: goto x86_l_487a;
	case 18564ULL: goto x86_l_4884;
	case 18566ULL: goto x86_l_4886;
	case 18569ULL: goto x86_l_4889;
	case 18574ULL: goto x86_l_488e;
	case 18579ULL: goto x86_l_4893;
	case 18583ULL: goto x86_l_4897;
	case 18588ULL: goto x86_l_489c;
	case 18590ULL: goto x86_l_489e;
	case 18592ULL: goto x86_l_48a0;
	case 18598ULL: goto x86_l_48a6;
	case 18608ULL: goto x86_l_48b0;
	case 18614ULL: goto x86_l_48b6;
	case 18622ULL: goto x86_l_48be;
	case 18626ULL: goto x86_l_48c2;
	case 18630ULL: goto x86_l_48c6;
	case 18640ULL: goto x86_l_48d0;
	case 18642ULL: goto x86_l_48d2;
	case 18645ULL: goto x86_l_48d5;
	case 18650ULL: goto x86_l_48da;
	case 18655ULL: goto x86_l_48df;
	case 18659ULL: goto x86_l_48e3;
	case 18664ULL: goto x86_l_48e8;
	case 18666ULL: goto x86_l_48ea;
	case 18668ULL: goto x86_l_48ec;
	case 18674ULL: goto x86_l_48f2;
	case 18684ULL: goto x86_l_48fc;
	case 18690ULL: goto x86_l_4902;
	case 18698ULL: goto x86_l_490a;
	case 18702ULL: goto x86_l_490e;
	case 18706ULL: goto x86_l_4912;
	case 18716ULL: goto x86_l_491c;
	case 18718ULL: goto x86_l_491e;
	case 18721ULL: goto x86_l_4921;
	case 18726ULL: goto x86_l_4926;
	case 18731ULL: goto x86_l_492b;
	case 18735ULL: goto x86_l_492f;
	case 18740ULL: goto x86_l_4934;
	case 18742ULL: goto x86_l_4936;
	case 18744ULL: goto x86_l_4938;
	case 18750ULL: goto x86_l_493e;
	case 18760ULL: goto x86_l_4948;
	case 18766ULL: goto x86_l_494e;
	case 18774ULL: goto x86_l_4956;
	case 18778ULL: goto x86_l_495a;
	case 18782ULL: goto x86_l_495e;
	case 18792ULL: goto x86_l_4968;
	case 18794ULL: goto x86_l_496a;
	case 18797ULL: goto x86_l_496d;
	case 18802ULL: goto x86_l_4972;
	case 18807ULL: goto x86_l_4977;
	case 18811ULL: goto x86_l_497b;
	case 18816ULL: goto x86_l_4980;
	case 18818ULL: goto x86_l_4982;
	case 18820ULL: goto x86_l_4984;
	case 18826ULL: goto x86_l_498a;
	case 18836ULL: goto x86_l_4994;
	case 18842ULL: goto x86_l_499a;
	case 18850ULL: goto x86_l_49a2;
	case 18854ULL: goto x86_l_49a6;
	case 18858ULL: goto x86_l_49aa;
	case 18868ULL: goto x86_l_49b4;
	case 18870ULL: goto x86_l_49b6;
	case 18873ULL: goto x86_l_49b9;
	case 18878ULL: goto x86_l_49be;
	case 18883ULL: goto x86_l_49c3;
	case 18887ULL: goto x86_l_49c7;
	case 18892ULL: goto x86_l_49cc;
	case 18894ULL: goto x86_l_49ce;
	case 18896ULL: goto x86_l_49d0;
	case 18902ULL: goto x86_l_49d6;
	case 18912ULL: goto x86_l_49e0;
	case 18918ULL: goto x86_l_49e6;
	case 18921ULL: goto x86_l_49e9;
	case 18929ULL: goto x86_l_49f1;
	case 18933ULL: goto x86_l_49f5;
	case 18937ULL: goto x86_l_49f9;
	case 18947ULL: goto x86_l_4a03;
	case 18949ULL: goto x86_l_4a05;
	case 18952ULL: goto x86_l_4a08;
	case 18957ULL: goto x86_l_4a0d;
	case 18962ULL: goto x86_l_4a12;
	case 18966ULL: goto x86_l_4a16;
	case 18971ULL: goto x86_l_4a1b;
	case 18973ULL: goto x86_l_4a1d;
	case 18975ULL: goto x86_l_4a1f;
	case 18981ULL: goto x86_l_4a25;
	case 18986ULL: goto x86_l_4a2a;
	case 18996ULL: goto x86_l_4a34;
	case 18999ULL: goto x86_l_4a37;
	case 19005ULL: goto x86_l_4a3d;
	case 19013ULL: goto x86_l_4a45;
	case 19017ULL: goto x86_l_4a49;
	case 19021ULL: goto x86_l_4a4d;
	case 19031ULL: goto x86_l_4a57;
	case 19033ULL: goto x86_l_4a59;
	case 19036ULL: goto x86_l_4a5c;
	case 19041ULL: goto x86_l_4a61;
	case 19046ULL: goto x86_l_4a66;
	case 19050ULL: goto x86_l_4a6a;
	case 19055ULL: goto x86_l_4a6f;
	case 19057ULL: goto x86_l_4a71;
	case 19059ULL: goto x86_l_4a73;
	case 19065ULL: goto x86_l_4a79;
	case 19070ULL: goto x86_l_4a7e;
	case 19080ULL: goto x86_l_4a88;
	case 19083ULL: goto x86_l_4a8b;
	case 19089ULL: goto x86_l_4a91;
	case 19097ULL: goto x86_l_4a99;
	case 19101ULL: goto x86_l_4a9d;
	case 19105ULL: goto x86_l_4aa1;
	case 19115ULL: goto x86_l_4aab;
	case 19121ULL: goto x86_l_4ab1;
	case 19124ULL: goto x86_l_4ab4;
	case 19129ULL: goto x86_l_4ab9;
	case 19134ULL: goto x86_l_4abe;
	case 19138ULL: goto x86_l_4ac2;
	case 19143ULL: goto x86_l_4ac7;
	case 19145ULL: goto x86_l_4ac9;
	case 19147ULL: goto x86_l_4acb;
	case 19153ULL: goto x86_l_4ad1;
	case 19158ULL: goto x86_l_4ad6;
	case 19163ULL: goto x86_l_4adb;
	case 19168ULL: goto x86_l_4ae0;
	case 19173ULL: goto x86_l_4ae5;
	case 19178ULL: goto x86_l_4aea;
	case 19183ULL: goto x86_l_4aef;
	case 19188ULL: goto x86_l_4af4;
	case 19190ULL: goto x86_l_4af6;
	case 19195ULL: goto x86_l_4afb;
	case 19200ULL: goto x86_l_4b00;
	case 19205ULL: goto x86_l_4b05;
	case 19207ULL: goto x86_l_4b07;
	case 19212ULL: goto x86_l_4b0c;
	case 19217ULL: goto x86_l_4b11;
	case 19222ULL: goto x86_l_4b16;
	case 19224ULL: goto x86_l_4b18;
	case 19229ULL: goto x86_l_4b1d;
	case 19234ULL: goto x86_l_4b22;
	case 19239ULL: goto x86_l_4b27;
	case 19241ULL: goto x86_l_4b29;
	case 19246ULL: goto x86_l_4b2e;
	case 19251ULL: goto x86_l_4b33;
	case 19256ULL: goto x86_l_4b38;
	case 19259ULL: goto x86_l_4b3b;
	case 19264ULL: goto x86_l_4b40;
	case 19267ULL: goto x86_l_4b43;
	case 19272ULL: goto x86_l_4b48;
	case 19277ULL: goto x86_l_4b4d;
	case 19282ULL: goto x86_l_4b52;
	case 19285ULL: goto x86_l_4b55;
	case 19287ULL: goto x86_l_4b57;
	case 19290ULL: goto x86_l_4b5a;
	case 19296ULL: goto x86_l_4b60;
	case 19299ULL: goto x86_l_4b63;
	case 19303ULL: goto x86_l_4b67;
	case 19308ULL: goto x86_l_4b6c;
	case 19310ULL: goto x86_l_4b6e;
	case 19315ULL: goto x86_l_4b73;
	case 19323ULL: goto x86_l_4b7b;
	case 19330ULL: goto x86_l_4b82;
	case 19335ULL: goto x86_l_4b87;
	case 19340ULL: goto x86_l_4b8c;
	case 19342ULL: goto x86_l_4b8e;
	case 19345ULL: goto x86_l_4b91;
	case 19351ULL: goto x86_l_4b97;
	case 19354ULL: goto x86_l_4b9a;
	case 19361ULL: goto x86_l_4ba1;
	case 19363ULL: goto x86_l_4ba3;
	case 19368ULL: goto x86_l_4ba8;
	case 19373ULL: goto x86_l_4bad;
	case 19376ULL: goto x86_l_4bb0;
	case 19379ULL: goto x86_l_4bb3;
	case 19381ULL: goto x86_l_4bb5;
	case 19383ULL: goto x86_l_4bb7;
	case 19388ULL: goto x86_l_4bbc;
	case 19390ULL: goto x86_l_4bbe;
	case 19395ULL: goto x86_l_4bc3;
	case 19398ULL: goto x86_l_4bc6;
	case 19401ULL: goto x86_l_4bc9;
	case 19407ULL: goto x86_l_4bcf;
	case 19410ULL: goto x86_l_4bd2;
	case 19414ULL: goto x86_l_4bd6;
	case 19419ULL: goto x86_l_4bdb;
	case 19421ULL: goto x86_l_4bdd;
	case 19426ULL: goto x86_l_4be2;
	case 19434ULL: goto x86_l_4bea;
	case 19441ULL: goto x86_l_4bf1;
	case 19446ULL: goto x86_l_4bf6;
	case 19451ULL: goto x86_l_4bfb;
	case 19453ULL: goto x86_l_4bfd;
	case 19456ULL: goto x86_l_4c00;
	case 19458ULL: goto x86_l_4c02;
	case 19461ULL: goto x86_l_4c05;
	case 19468ULL: goto x86_l_4c0c;
	case 19470ULL: goto x86_l_4c0e;
	case 19475ULL: goto x86_l_4c13;
	case 19480ULL: goto x86_l_4c18;
	case 19483ULL: goto x86_l_4c1b;
	case 19486ULL: goto x86_l_4c1e;
	case 19488ULL: goto x86_l_4c20;
	case 19490ULL: goto x86_l_4c22;
	default: return 0xffffffffffffffffULL;
	}
x86_l_44e3:
	/* 0x44e3: cmp    WORD PTR [r12+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_44ed:
	/* 0x44ed: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_44f3:
	/* 0x44f3: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_44fa:
	/* 0x44fa: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_44fd:
	/* 0x44fd: mov    eax,DWORD PTR [r12+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_4505:
	/* 0x4505: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4508:
	/* 0x4508: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_450c:
	/* 0x450c: movzx  eax,WORD PTR [r12+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_4515:
	/* 0x4515: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_4517:
	/* 0x4517: je     47e9 <generic_sleepable_preload+0x47e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47e9;
	}
x86_l_451d:
	/* 0x451d: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4520:
	/* 0x4520: je     4542 <generic_sleepable_preload+0x4542> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4542;
	}
x86_l_4522:
	/* 0x4522: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4525:
	/* 0x4525: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_452a:
	/* 0x452a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_452f:
	/* 0x452f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4533:
	/* 0x4533: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4538:
	/* 0x4538: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_453a:
	/* 0x453a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_453c:
	/* 0x453c: js     4adb <generic_sleepable_preload+0x4adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4adb;
	}
x86_l_4542:
	/* 0x4542: cmp    WORD PTR [r12+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_454c:
	/* 0x454c: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_4552:
	/* 0x4552: mov    ecx,DWORD PTR [r12+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_455a:
	/* 0x455a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_455e:
	/* 0x455e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4562:
	/* 0x4562: cmp    WORD PTR [r12+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_456c:
	/* 0x456c: je     458e <generic_sleepable_preload+0x458e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_458e;
	}
x86_l_456e:
	/* 0x456e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4571:
	/* 0x4571: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4576:
	/* 0x4576: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_457b:
	/* 0x457b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_457f:
	/* 0x457f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4584:
	/* 0x4584: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4586:
	/* 0x4586: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4588:
	/* 0x4588: js     4ae5 <generic_sleepable_preload+0x4ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ae5;
	}
x86_l_458e:
	/* 0x458e: cmp    WORD PTR [r12+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_4598:
	/* 0x4598: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_459e:
	/* 0x459e: mov    ecx,DWORD PTR [r12+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_45a6:
	/* 0x45a6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_45aa:
	/* 0x45aa: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45ae:
	/* 0x45ae: cmp    WORD PTR [r12+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_45b8:
	/* 0x45b8: je     45da <generic_sleepable_preload+0x45da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45da;
	}
x86_l_45ba:
	/* 0x45ba: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_45bd:
	/* 0x45bd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_45c2:
	/* 0x45c2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_45c7:
	/* 0x45c7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45cb:
	/* 0x45cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45d0:
	/* 0x45d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45d2:
	/* 0x45d2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_45d4:
	/* 0x45d4: js     4af6 <generic_sleepable_preload+0x4af6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4af6;
	}
x86_l_45da:
	/* 0x45da: cmp    WORD PTR [r12+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_45e4:
	/* 0x45e4: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_45ea:
	/* 0x45ea: mov    ecx,DWORD PTR [r12+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_45f2:
	/* 0x45f2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_45f6:
	/* 0x45f6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45fa:
	/* 0x45fa: cmp    WORD PTR [r12+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_4604:
	/* 0x4604: je     4626 <generic_sleepable_preload+0x4626> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4626;
	}
x86_l_4606:
	/* 0x4606: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4609:
	/* 0x4609: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_460e:
	/* 0x460e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4613:
	/* 0x4613: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4617:
	/* 0x4617: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_461c:
	/* 0x461c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_461e:
	/* 0x461e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4620:
	/* 0x4620: js     4b07 <generic_sleepable_preload+0x4b07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b07;
	}
x86_l_4626:
	/* 0x4626: cmp    WORD PTR [r12+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_4630:
	/* 0x4630: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_4636:
	/* 0x4636: mov    ecx,DWORD PTR [r12+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_463e:
	/* 0x463e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4642:
	/* 0x4642: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4646:
	/* 0x4646: cmp    WORD PTR [r12+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_4650:
	/* 0x4650: je     4672 <generic_sleepable_preload+0x4672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4672;
	}
x86_l_4652:
	/* 0x4652: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4655:
	/* 0x4655: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_465a:
	/* 0x465a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_465f:
	/* 0x465f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4663:
	/* 0x4663: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4668:
	/* 0x4668: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_466a:
	/* 0x466a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_466c:
	/* 0x466c: js     4b18 <generic_sleepable_preload+0x4b18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b18;
	}
x86_l_4672:
	/* 0x4672: cmp    WORD PTR [r12+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_467c:
	/* 0x467c: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_4682:
	/* 0x4682: mov    ecx,DWORD PTR [r12+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_468a:
	/* 0x468a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_468e:
	/* 0x468e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4692:
	/* 0x4692: cmp    WORD PTR [r12+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_469c:
	/* 0x469c: je     46be <generic_sleepable_preload+0x46be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46be;
	}
x86_l_469e:
	/* 0x469e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_46a1:
	/* 0x46a1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_46a6:
	/* 0x46a6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_46ab:
	/* 0x46ab: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46af:
	/* 0x46af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46b4:
	/* 0x46b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46b6:
	/* 0x46b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46b8:
	/* 0x46b8: js     4b29 <generic_sleepable_preload+0x4b29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b29;
	}
x86_l_46be:
	/* 0x46be: cmp    WORD PTR [r12+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_46c8:
	/* 0x46c8: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_46ce:
	/* 0x46ce: mov    ecx,DWORD PTR [r12+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_46d6:
	/* 0x46d6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_46da:
	/* 0x46da: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46de:
	/* 0x46de: cmp    WORD PTR [r12+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_46e8:
	/* 0x46e8: je     470a <generic_sleepable_preload+0x470a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_470a;
	}
x86_l_46ea:
	/* 0x46ea: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_46ed:
	/* 0x46ed: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_46f2:
	/* 0x46f2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_46f7:
	/* 0x46f7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46fb:
	/* 0x46fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4700:
	/* 0x4700: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4702:
	/* 0x4702: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4704:
	/* 0x4704: js     4bbe <generic_sleepable_preload+0x4bbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4bbe;
	}
x86_l_470a:
	/* 0x470a: cmp    WORD PTR [r12+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_4714:
	/* 0x4714: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_471a:
	/* 0x471a: mov    ecx,DWORD PTR [r12+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_4722:
	/* 0x4722: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4726:
	/* 0x4726: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_472a:
	/* 0x472a: cmp    WORD PTR [r12+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_4734:
	/* 0x4734: je     4756 <generic_sleepable_preload+0x4756> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4756;
	}
x86_l_4736:
	/* 0x4736: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4739:
	/* 0x4739: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_473e:
	/* 0x473e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4743:
	/* 0x4743: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4747:
	/* 0x4747: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_474c:
	/* 0x474c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_474e:
	/* 0x474e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4750:
	/* 0x4750: js     5c28 <generic_sleepable_preload+0x5c28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23592ULL;
	}
x86_l_4756:
	/* 0x4756: cmp    WORD PTR [r12+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_4760:
	/* 0x4760: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_4766:
	/* 0x4766: mov    ecx,DWORD PTR [r12+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_476e:
	/* 0x476e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4772:
	/* 0x4772: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4776:
	/* 0x4776: cmp    WORD PTR [r12+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_4780:
	/* 0x4780: je     47a2 <generic_sleepable_preload+0x47a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47a2;
	}
x86_l_4782:
	/* 0x4782: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4785:
	/* 0x4785: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_478a:
	/* 0x478a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_478f:
	/* 0x478f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4793:
	/* 0x4793: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4798:
	/* 0x4798: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_479a:
	/* 0x479a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_479c:
	/* 0x479c: js     5d31 <generic_sleepable_preload+0x5d31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23857ULL;
	}
x86_l_47a2:
	/* 0x47a2: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47a7:
	/* 0x47a7: cmp    WORD PTR [r12+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_47b1:
	/* 0x47b1: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_47b7:
	/* 0x47b7: mov    ecx,DWORD PTR [r12+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_47bf:
	/* 0x47bf: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_47c3:
	/* 0x47c3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47c7:
	/* 0x47c7: cmp    WORD PTR [r12+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_47d1:
	/* 0x47d1: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_47d7:
	/* 0x47d7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_47da:
	/* 0x47da: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_47df:
	/* 0x47df: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47e4:
	/* 0x47e4: jmp    4abe <generic_sleepable_preload+0x4abe> */
	goto x86_l_4abe;
x86_l_47e9:
	/* 0x47e9: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_47ec:
	/* 0x47ec: je     480e <generic_sleepable_preload+0x480e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_480e;
	}
x86_l_47ee:
	/* 0x47ee: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_47f1:
	/* 0x47f1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_47f6:
	/* 0x47f6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47fb:
	/* 0x47fb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47ff:
	/* 0x47ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4804:
	/* 0x4804: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4806:
	/* 0x4806: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4808:
	/* 0x4808: js     4adb <generic_sleepable_preload+0x4adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4adb;
	}
x86_l_480e:
	/* 0x480e: cmp    WORD PTR [r12+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_4818:
	/* 0x4818: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_481e:
	/* 0x481e: mov    ecx,DWORD PTR [r12+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_4826:
	/* 0x4826: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_482a:
	/* 0x482a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_482e:
	/* 0x482e: cmp    WORD PTR [r12+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_4838:
	/* 0x4838: je     485a <generic_sleepable_preload+0x485a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_485a;
	}
x86_l_483a:
	/* 0x483a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_483d:
	/* 0x483d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4842:
	/* 0x4842: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4847:
	/* 0x4847: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_484b:
	/* 0x484b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4850:
	/* 0x4850: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4852:
	/* 0x4852: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4854:
	/* 0x4854: js     4ae5 <generic_sleepable_preload+0x4ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ae5;
	}
x86_l_485a:
	/* 0x485a: cmp    WORD PTR [r12+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_4864:
	/* 0x4864: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_486a:
	/* 0x486a: mov    ecx,DWORD PTR [r12+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_4872:
	/* 0x4872: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4876:
	/* 0x4876: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_487a:
	/* 0x487a: cmp    WORD PTR [r12+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_4884:
	/* 0x4884: je     48a6 <generic_sleepable_preload+0x48a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48a6;
	}
x86_l_4886:
	/* 0x4886: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4889:
	/* 0x4889: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_488e:
	/* 0x488e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4893:
	/* 0x4893: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4897:
	/* 0x4897: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_489c:
	/* 0x489c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_489e:
	/* 0x489e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48a0:
	/* 0x48a0: js     4af6 <generic_sleepable_preload+0x4af6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4af6;
	}
x86_l_48a6:
	/* 0x48a6: cmp    WORD PTR [r12+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_48b0:
	/* 0x48b0: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_48b6:
	/* 0x48b6: mov    ecx,DWORD PTR [r12+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_48be:
	/* 0x48be: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_48c2:
	/* 0x48c2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48c6:
	/* 0x48c6: cmp    WORD PTR [r12+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_48d0:
	/* 0x48d0: je     48f2 <generic_sleepable_preload+0x48f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48f2;
	}
x86_l_48d2:
	/* 0x48d2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_48d5:
	/* 0x48d5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_48da:
	/* 0x48da: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_48df:
	/* 0x48df: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48e3:
	/* 0x48e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48e8:
	/* 0x48e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48ea:
	/* 0x48ea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48ec:
	/* 0x48ec: js     4b07 <generic_sleepable_preload+0x4b07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b07;
	}
x86_l_48f2:
	/* 0x48f2: cmp    WORD PTR [r12+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_48fc:
	/* 0x48fc: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_4902:
	/* 0x4902: mov    ecx,DWORD PTR [r12+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_490a:
	/* 0x490a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_490e:
	/* 0x490e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4912:
	/* 0x4912: cmp    WORD PTR [r12+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_491c:
	/* 0x491c: je     493e <generic_sleepable_preload+0x493e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_493e;
	}
x86_l_491e:
	/* 0x491e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4921:
	/* 0x4921: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4926:
	/* 0x4926: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_492b:
	/* 0x492b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_492f:
	/* 0x492f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4934:
	/* 0x4934: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4936:
	/* 0x4936: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4938:
	/* 0x4938: js     4b18 <generic_sleepable_preload+0x4b18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b18;
	}
x86_l_493e:
	/* 0x493e: cmp    WORD PTR [r12+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_4948:
	/* 0x4948: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_494e:
	/* 0x494e: mov    ecx,DWORD PTR [r12+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_4956:
	/* 0x4956: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_495a:
	/* 0x495a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_495e:
	/* 0x495e: cmp    WORD PTR [r12+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_4968:
	/* 0x4968: je     498a <generic_sleepable_preload+0x498a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_498a;
	}
x86_l_496a:
	/* 0x496a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_496d:
	/* 0x496d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4972:
	/* 0x4972: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4977:
	/* 0x4977: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_497b:
	/* 0x497b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4980:
	/* 0x4980: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4982:
	/* 0x4982: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4984:
	/* 0x4984: js     4b29 <generic_sleepable_preload+0x4b29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b29;
	}
x86_l_498a:
	/* 0x498a: cmp    WORD PTR [r12+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_4994:
	/* 0x4994: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_499a:
	/* 0x499a: mov    ecx,DWORD PTR [r12+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_49a2:
	/* 0x49a2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_49a6:
	/* 0x49a6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49aa:
	/* 0x49aa: cmp    WORD PTR [r12+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_49b4:
	/* 0x49b4: je     49d6 <generic_sleepable_preload+0x49d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49d6;
	}
x86_l_49b6:
	/* 0x49b6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_49b9:
	/* 0x49b9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_49be:
	/* 0x49be: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_49c3:
	/* 0x49c3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
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
	/* 0x49d0: js     4bbe <generic_sleepable_preload+0x4bbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4bbe;
	}
x86_l_49d6:
	/* 0x49d6: cmp    WORD PTR [r12+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_49e0:
	/* 0x49e0: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_49e6:
	/* 0x49e6: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_49e9:
	/* 0x49e9: mov    ecx,DWORD PTR [r12+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_49f1:
	/* 0x49f1: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_49f5:
	/* 0x49f5: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49f9:
	/* 0x49f9: cmp    WORD PTR [r12+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_4a03:
	/* 0x4a03: je     4a25 <generic_sleepable_preload+0x4a25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a25;
	}
x86_l_4a05:
	/* 0x4a05: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4a08:
	/* 0x4a08: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a0d:
	/* 0x4a0d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a12:
	/* 0x4a12: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a16:
	/* 0x4a16: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a1b:
	/* 0x4a1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a1d:
	/* 0x4a1d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a1f:
	/* 0x4a1f: js     5ca6 <generic_sleepable_preload+0x5ca6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23718ULL;
	}
x86_l_4a25:
	/* 0x4a25: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a2a:
	/* 0x4a2a: cmp    WORD PTR [r12+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_4a34:
	/* 0x4a34: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_4a37:
	/* 0x4a37: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_4a3d:
	/* 0x4a3d: mov    ecx,DWORD PTR [r12+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_4a45:
	/* 0x4a45: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4a49:
	/* 0x4a49: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a4d:
	/* 0x4a4d: cmp    WORD PTR [r12+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_4a57:
	/* 0x4a57: je     4a79 <generic_sleepable_preload+0x4a79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a79;
	}
x86_l_4a59:
	/* 0x4a59: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4a5c:
	/* 0x4a5c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a61:
	/* 0x4a61: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a66:
	/* 0x4a66: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a6a:
	/* 0x4a6a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a6f:
	/* 0x4a6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a71:
	/* 0x4a71: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a73:
	/* 0x4a73: js     5dd6 <generic_sleepable_preload+0x5dd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24022ULL;
	}
x86_l_4a79:
	/* 0x4a79: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a7e:
	/* 0x4a7e: cmp    WORD PTR [r12+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_4a88:
	/* 0x4a88: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_4a8b:
	/* 0x4a8b: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_4a91:
	/* 0x4a91: mov    ecx,DWORD PTR [r12+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_4a99:
	/* 0x4a99: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4a9d:
	/* 0x4a9d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4aa1:
	/* 0x4aa1: cmp    WORD PTR [r12+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_4aab:
	/* 0x4aab: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_4ab1:
	/* 0x4ab1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4ab4:
	/* 0x4ab4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4ab9:
	/* 0x4ab9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4abe:
	/* 0x4abe: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ac2:
	/* 0x4ac2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ac7:
	/* 0x4ac7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ac9:
	/* 0x4ac9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4acb:
	/* 0x4acb: jns    4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_4bc6;
	}
x86_l_4ad1:
	/* 0x4ad1: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_4ad6:
	/* 0x4ad6: jmp    4bc3 <generic_sleepable_preload+0x4bc3> */
	goto x86_l_4bc3;
x86_l_4adb:
	/* 0x4adb: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_4ae0:
	/* 0x4ae0: jmp    4bc3 <generic_sleepable_preload+0x4bc3> */
	goto x86_l_4bc3;
x86_l_4ae5:
	/* 0x4ae5: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_4aea:
	/* 0x4aea: jmp    4bc3 <generic_sleepable_preload+0x4bc3> */
	goto x86_l_4bc3;
x86_l_4aef:
	/* 0x4aef: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_4af4:
	/* 0x4af4: jmp    4b38 <generic_sleepable_preload+0x4b38> */
	goto x86_l_4b38;
x86_l_4af6:
	/* 0x4af6: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_4afb:
	/* 0x4afb: jmp    4bc3 <generic_sleepable_preload+0x4bc3> */
	goto x86_l_4bc3;
x86_l_4b00:
	/* 0x4b00: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_4b05:
	/* 0x4b05: jmp    4b38 <generic_sleepable_preload+0x4b38> */
	goto x86_l_4b38;
x86_l_4b07:
	/* 0x4b07: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_4b0c:
	/* 0x4b0c: jmp    4bc3 <generic_sleepable_preload+0x4bc3> */
	goto x86_l_4bc3;
x86_l_4b11:
	/* 0x4b11: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_4b16:
	/* 0x4b16: jmp    4b38 <generic_sleepable_preload+0x4b38> */
	goto x86_l_4b38;
x86_l_4b18:
	/* 0x4b18: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_4b1d:
	/* 0x4b1d: jmp    4bc3 <generic_sleepable_preload+0x4bc3> */
	goto x86_l_4bc3;
x86_l_4b22:
	/* 0x4b22: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_4b27:
	/* 0x4b27: jmp    4b38 <generic_sleepable_preload+0x4b38> */
	goto x86_l_4b38;
x86_l_4b29:
	/* 0x4b29: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_4b2e:
	/* 0x4b2e: jmp    4bc3 <generic_sleepable_preload+0x4bc3> */
	goto x86_l_4bc3;
x86_l_4b33:
	/* 0x4b33: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_4b38:
	/* 0x4b38: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4b3b:
	/* 0x4b3b: mov    ebp,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b40:
	/* 0x4b40: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4b43:
	/* 0x4b43: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4b48:
	/* 0x4b48: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4b4d:
	/* 0x4b4d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b52:
	/* 0x4b52: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_4b55:
	/* 0x4b55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b57:
	/* 0x4b57: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_4b5a:
	/* 0x4b5a: jne    4c6b <generic_sleepable_preload+0x4c6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19563ULL;
	}
x86_l_4b60:
	/* 0x4b60: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_4b63:
	/* 0x4b63: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b67:
	/* 0x4b67: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4b6c:
	/* 0x4b6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b6e:
	/* 0x4b6e: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b73:
	/* 0x4b73: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_4b7b:
	/* 0x4b7b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_4b82:
	/* 0x4b82: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4b87:
	/* 0x4b87: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4b8c:
	/* 0x4b8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b8e:
	/* 0x4b8e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b91:
	/* 0x4b91: je     4c68 <generic_sleepable_preload+0x4c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19560ULL;
	}
x86_l_4b97:
	/* 0x4b97: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4b9a:
	/* 0x4b9a: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_4ba1:
	/* 0x4ba1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ba3:
	/* 0x4ba3: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4ba8:
	/* 0x4ba8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4bad:
	/* 0x4bad: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_4bb0:
	/* 0x4bb0: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_4bb3:
	/* 0x4bb3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4bb5:
	/* 0x4bb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bb7:
	/* 0x4bb7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4bbc:
	/* 0x4bbc: jmp    4c27 <generic_sleepable_preload+0x4c27> */
	return 19495ULL;
x86_l_4bbe:
	/* 0x4bbe: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_4bc3:
	/* 0x4bc3: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4bc6:
	/* 0x4bc6: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_4bc9:
	/* 0x4bc9: jne    4c6b <generic_sleepable_preload+0x4c6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19563ULL;
	}
x86_l_4bcf:
	/* 0x4bcf: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_4bd2:
	/* 0x4bd2: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4bd6:
	/* 0x4bd6: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4bdb:
	/* 0x4bdb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bdd:
	/* 0x4bdd: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4be2:
	/* 0x4be2: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_4bea:
	/* 0x4bea: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_4bf1:
	/* 0x4bf1: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4bf6:
	/* 0x4bf6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4bfb:
	/* 0x4bfb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bfd:
	/* 0x4bfd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4c00:
	/* 0x4c00: je     4c68 <generic_sleepable_preload+0x4c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19560ULL;
	}
x86_l_4c02:
	/* 0x4c02: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4c05:
	/* 0x4c05: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_4c0c:
	/* 0x4c0c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c0e:
	/* 0x4c0e: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4c13:
	/* 0x4c13: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4c18:
	/* 0x4c18: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_4c1b:
	/* 0x4c1b: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_4c1e:
	/* 0x4c1e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c20:
	/* 0x4c20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c22:
	/* 0x4c22: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
	return 19495ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 19495ULL: goto x86_l_4c27;
	case 19498ULL: goto x86_l_4c2a;
	case 19501ULL: goto x86_l_4c2d;
	case 19506ULL: goto x86_l_4c32;
	case 19508ULL: goto x86_l_4c34;
	case 19511ULL: goto x86_l_4c37;
	case 19513ULL: goto x86_l_4c39;
	case 19516ULL: goto x86_l_4c3c;
	case 19518ULL: goto x86_l_4c3e;
	case 19521ULL: goto x86_l_4c41;
	case 19525ULL: goto x86_l_4c45;
	case 19530ULL: goto x86_l_4c4a;
	case 19533ULL: goto x86_l_4c4d;
	case 19535ULL: goto x86_l_4c4f;
	case 19538ULL: goto x86_l_4c52;
	case 19543ULL: goto x86_l_4c57;
	case 19545ULL: goto x86_l_4c59;
	case 19548ULL: goto x86_l_4c5c;
	case 19550ULL: goto x86_l_4c5e;
	case 19555ULL: goto x86_l_4c63;
	case 19558ULL: goto x86_l_4c66;
	case 19560ULL: goto x86_l_4c68;
	case 19563ULL: goto x86_l_4c6b;
	case 19568ULL: goto x86_l_4c70;
	case 19573ULL: goto x86_l_4c75;
	case 19575ULL: goto x86_l_4c77;
	case 19577ULL: goto x86_l_4c79;
	case 19584ULL: goto x86_l_4c80;
	case 19585ULL: goto x86_l_4c81;
	case 19587ULL: goto x86_l_4c83;
	case 19589ULL: goto x86_l_4c85;
	case 19591ULL: goto x86_l_4c87;
	case 19593ULL: goto x86_l_4c89;
	case 19594ULL: goto x86_l_4c8a;
	case 19599ULL: goto x86_l_4c8f;
	case 19601ULL: goto x86_l_4c91;
	case 19603ULL: goto x86_l_4c93;
	case 19608ULL: goto x86_l_4c98;
	case 19611ULL: goto x86_l_4c9b;
	case 19617ULL: goto x86_l_4ca1;
	case 19620ULL: goto x86_l_4ca4;
	case 19626ULL: goto x86_l_4caa;
	case 19629ULL: goto x86_l_4cad;
	case 19635ULL: goto x86_l_4cb3;
	case 19638ULL: goto x86_l_4cb6;
	case 19644ULL: goto x86_l_4cbc;
	case 19649ULL: goto x86_l_4cc1;
	case 19654ULL: goto x86_l_4cc6;
	case 19663ULL: goto x86_l_4ccf;
	case 19672ULL: goto x86_l_4cd8;
	case 19678ULL: goto x86_l_4cde;
	case 19680ULL: goto x86_l_4ce0;
	case 19683ULL: goto x86_l_4ce3;
	case 19685ULL: goto x86_l_4ce5;
	case 19688ULL: goto x86_l_4ce8;
	case 19690ULL: goto x86_l_4cea;
	case 19693ULL: goto x86_l_4ced;
	case 19699ULL: goto x86_l_4cf3;
	case 19704ULL: goto x86_l_4cf8;
	case 19707ULL: goto x86_l_4cfb;
	case 19713ULL: goto x86_l_4d01;
	case 19718ULL: goto x86_l_4d06;
	case 19721ULL: goto x86_l_4d09;
	case 19727ULL: goto x86_l_4d0f;
	case 19732ULL: goto x86_l_4d14;
	case 19735ULL: goto x86_l_4d17;
	case 19741ULL: goto x86_l_4d1d;
	case 19746ULL: goto x86_l_4d22;
	case 19749ULL: goto x86_l_4d25;
	case 19751ULL: goto x86_l_4d27;
	case 19754ULL: goto x86_l_4d2a;
	case 19760ULL: goto x86_l_4d30;
	case 19762ULL: goto x86_l_4d32;
	case 19768ULL: goto x86_l_4d38;
	case 19771ULL: goto x86_l_4d3b;
	case 19774ULL: goto x86_l_4d3e;
	case 19780ULL: goto x86_l_4d44;
	case 19785ULL: goto x86_l_4d49;
	case 19787ULL: goto x86_l_4d4b;
	case 19789ULL: goto x86_l_4d4d;
	case 19792ULL: goto x86_l_4d50;
	case 19794ULL: goto x86_l_4d52;
	case 19799ULL: goto x86_l_4d57;
	case 19801ULL: goto x86_l_4d59;
	case 19804ULL: goto x86_l_4d5c;
	case 19810ULL: goto x86_l_4d62;
	case 19818ULL: goto x86_l_4d6a;
	case 19821ULL: goto x86_l_4d6d;
	case 19827ULL: goto x86_l_4d73;
	case 19832ULL: goto x86_l_4d78;
	case 19835ULL: goto x86_l_4d7b;
	case 19841ULL: goto x86_l_4d81;
	case 19846ULL: goto x86_l_4d86;
	case 19849ULL: goto x86_l_4d89;
	case 19855ULL: goto x86_l_4d8f;
	case 19863ULL: goto x86_l_4d97;
	case 19866ULL: goto x86_l_4d9a;
	case 19872ULL: goto x86_l_4da0;
	case 19877ULL: goto x86_l_4da5;
	case 19880ULL: goto x86_l_4da8;
	case 19886ULL: goto x86_l_4dae;
	case 19891ULL: goto x86_l_4db3;
	case 19896ULL: goto x86_l_4db8;
	case 19898ULL: goto x86_l_4dba;
	case 19903ULL: goto x86_l_4dbf;
	case 19905ULL: goto x86_l_4dc1;
	case 19910ULL: goto x86_l_4dc6;
	case 19913ULL: goto x86_l_4dc9;
	case 19917ULL: goto x86_l_4dcd;
	case 19920ULL: goto x86_l_4dd0;
	case 19923ULL: goto x86_l_4dd3;
	case 19928ULL: goto x86_l_4dd8;
	case 19936ULL: goto x86_l_4de0;
	case 19942ULL: goto x86_l_4de6;
	case 19949ULL: goto x86_l_4ded;
	case 19952ULL: goto x86_l_4df0;
	case 19958ULL: goto x86_l_4df6;
	case 19961ULL: goto x86_l_4df9;
	case 19965ULL: goto x86_l_4dfd;
	case 19972ULL: goto x86_l_4e04;
	case 19974ULL: goto x86_l_4e06;
	case 19980ULL: goto x86_l_4e0c;
	case 19983ULL: goto x86_l_4e0f;
	case 19985ULL: goto x86_l_4e11;
	case 19988ULL: goto x86_l_4e14;
	case 19993ULL: goto x86_l_4e19;
	case 19998ULL: goto x86_l_4e1e;
	case 20002ULL: goto x86_l_4e22;
	case 20007ULL: goto x86_l_4e27;
	case 20009ULL: goto x86_l_4e29;
	case 20011ULL: goto x86_l_4e2b;
	case 20017ULL: goto x86_l_4e31;
	case 20022ULL: goto x86_l_4e36;
	case 20030ULL: goto x86_l_4e3e;
	case 20036ULL: goto x86_l_4e44;
	case 20042ULL: goto x86_l_4e4a;
	case 20046ULL: goto x86_l_4e4e;
	case 20050ULL: goto x86_l_4e52;
	case 20058ULL: goto x86_l_4e5a;
	case 20060ULL: goto x86_l_4e5c;
	case 20063ULL: goto x86_l_4e5f;
	case 20068ULL: goto x86_l_4e64;
	case 20073ULL: goto x86_l_4e69;
	case 20077ULL: goto x86_l_4e6d;
	case 20082ULL: goto x86_l_4e72;
	case 20084ULL: goto x86_l_4e74;
	case 20086ULL: goto x86_l_4e76;
	case 20092ULL: goto x86_l_4e7c;
	case 20097ULL: goto x86_l_4e81;
	case 20105ULL: goto x86_l_4e89;
	case 20111ULL: goto x86_l_4e8f;
	case 20117ULL: goto x86_l_4e95;
	case 20121ULL: goto x86_l_4e99;
	case 20125ULL: goto x86_l_4e9d;
	case 20133ULL: goto x86_l_4ea5;
	case 20135ULL: goto x86_l_4ea7;
	case 20138ULL: goto x86_l_4eaa;
	case 20143ULL: goto x86_l_4eaf;
	case 20148ULL: goto x86_l_4eb4;
	case 20152ULL: goto x86_l_4eb8;
	case 20157ULL: goto x86_l_4ebd;
	case 20159ULL: goto x86_l_4ebf;
	case 20161ULL: goto x86_l_4ec1;
	case 20167ULL: goto x86_l_4ec7;
	case 20172ULL: goto x86_l_4ecc;
	case 20180ULL: goto x86_l_4ed4;
	case 20186ULL: goto x86_l_4eda;
	case 20192ULL: goto x86_l_4ee0;
	case 20196ULL: goto x86_l_4ee4;
	case 20200ULL: goto x86_l_4ee8;
	case 20208ULL: goto x86_l_4ef0;
	case 20210ULL: goto x86_l_4ef2;
	case 20213ULL: goto x86_l_4ef5;
	case 20218ULL: goto x86_l_4efa;
	case 20223ULL: goto x86_l_4eff;
	case 20227ULL: goto x86_l_4f03;
	case 20232ULL: goto x86_l_4f08;
	case 20234ULL: goto x86_l_4f0a;
	case 20236ULL: goto x86_l_4f0c;
	case 20242ULL: goto x86_l_4f12;
	case 20247ULL: goto x86_l_4f17;
	case 20255ULL: goto x86_l_4f1f;
	case 20261ULL: goto x86_l_4f25;
	case 20267ULL: goto x86_l_4f2b;
	case 20271ULL: goto x86_l_4f2f;
	case 20275ULL: goto x86_l_4f33;
	case 20283ULL: goto x86_l_4f3b;
	case 20285ULL: goto x86_l_4f3d;
	case 20288ULL: goto x86_l_4f40;
	case 20293ULL: goto x86_l_4f45;
	case 20298ULL: goto x86_l_4f4a;
	case 20302ULL: goto x86_l_4f4e;
	case 20307ULL: goto x86_l_4f53;
	case 20309ULL: goto x86_l_4f55;
	case 20311ULL: goto x86_l_4f57;
	case 20317ULL: goto x86_l_4f5d;
	case 20322ULL: goto x86_l_4f62;
	case 20330ULL: goto x86_l_4f6a;
	case 20336ULL: goto x86_l_4f70;
	case 20342ULL: goto x86_l_4f76;
	case 20346ULL: goto x86_l_4f7a;
	case 20350ULL: goto x86_l_4f7e;
	case 20358ULL: goto x86_l_4f86;
	case 20360ULL: goto x86_l_4f88;
	case 20363ULL: goto x86_l_4f8b;
	case 20368ULL: goto x86_l_4f90;
	case 20373ULL: goto x86_l_4f95;
	case 20377ULL: goto x86_l_4f99;
	case 20382ULL: goto x86_l_4f9e;
	case 20384ULL: goto x86_l_4fa0;
	case 20386ULL: goto x86_l_4fa2;
	case 20392ULL: goto x86_l_4fa8;
	case 20397ULL: goto x86_l_4fad;
	case 20405ULL: goto x86_l_4fb5;
	case 20411ULL: goto x86_l_4fbb;
	case 20417ULL: goto x86_l_4fc1;
	case 20421ULL: goto x86_l_4fc5;
	case 20425ULL: goto x86_l_4fc9;
	case 20433ULL: goto x86_l_4fd1;
	case 20435ULL: goto x86_l_4fd3;
	case 20438ULL: goto x86_l_4fd6;
	case 20443ULL: goto x86_l_4fdb;
	case 20448ULL: goto x86_l_4fe0;
	case 20452ULL: goto x86_l_4fe4;
	case 20457ULL: goto x86_l_4fe9;
	case 20459ULL: goto x86_l_4feb;
	case 20461ULL: goto x86_l_4fed;
	case 20467ULL: goto x86_l_4ff3;
	case 20472ULL: goto x86_l_4ff8;
	case 20480ULL: goto x86_l_5000;
	case 20486ULL: goto x86_l_5006;
	case 20492ULL: goto x86_l_500c;
	case 20496ULL: goto x86_l_5010;
	case 20500ULL: goto x86_l_5014;
	case 20508ULL: goto x86_l_501c;
	case 20510ULL: goto x86_l_501e;
	case 20513ULL: goto x86_l_5021;
	case 20518ULL: goto x86_l_5026;
	case 20523ULL: goto x86_l_502b;
	case 20527ULL: goto x86_l_502f;
	case 20532ULL: goto x86_l_5034;
	case 20534ULL: goto x86_l_5036;
	case 20536ULL: goto x86_l_5038;
	case 20542ULL: goto x86_l_503e;
	case 20547ULL: goto x86_l_5043;
	case 20555ULL: goto x86_l_504b;
	case 20561ULL: goto x86_l_5051;
	case 20567ULL: goto x86_l_5057;
	case 20571ULL: goto x86_l_505b;
	case 20575ULL: goto x86_l_505f;
	case 20583ULL: goto x86_l_5067;
	case 20585ULL: goto x86_l_5069;
	case 20588ULL: goto x86_l_506c;
	case 20593ULL: goto x86_l_5071;
	case 20598ULL: goto x86_l_5076;
	case 20602ULL: goto x86_l_507a;
	case 20607ULL: goto x86_l_507f;
	case 20609ULL: goto x86_l_5081;
	case 20611ULL: goto x86_l_5083;
	case 20617ULL: goto x86_l_5089;
	case 20622ULL: goto x86_l_508e;
	case 20630ULL: goto x86_l_5096;
	case 20636ULL: goto x86_l_509c;
	case 20642ULL: goto x86_l_50a2;
	case 20646ULL: goto x86_l_50a6;
	case 20650ULL: goto x86_l_50aa;
	case 20658ULL: goto x86_l_50b2;
	case 20664ULL: goto x86_l_50b8;
	case 20667ULL: goto x86_l_50bb;
	case 20672ULL: goto x86_l_50c0;
	case 20677ULL: goto x86_l_50c5;
	case 20682ULL: goto x86_l_50ca;
	case 20685ULL: goto x86_l_50cd;
	case 20687ULL: goto x86_l_50cf;
	case 20690ULL: goto x86_l_50d2;
	case 20695ULL: goto x86_l_50d7;
	case 20700ULL: goto x86_l_50dc;
	case 20704ULL: goto x86_l_50e0;
	case 20709ULL: goto x86_l_50e5;
	case 20711ULL: goto x86_l_50e7;
	case 20713ULL: goto x86_l_50e9;
	case 20719ULL: goto x86_l_50ef;
	case 20724ULL: goto x86_l_50f4;
	case 20732ULL: goto x86_l_50fc;
	case 20738ULL: goto x86_l_5102;
	case 20744ULL: goto x86_l_5108;
	case 20748ULL: goto x86_l_510c;
	case 20752ULL: goto x86_l_5110;
	case 20760ULL: goto x86_l_5118;
	case 20762ULL: goto x86_l_511a;
	case 20765ULL: goto x86_l_511d;
	case 20770ULL: goto x86_l_5122;
	case 20775ULL: goto x86_l_5127;
	case 20779ULL: goto x86_l_512b;
	case 20784ULL: goto x86_l_5130;
	case 20786ULL: goto x86_l_5132;
	case 20788ULL: goto x86_l_5134;
	case 20794ULL: goto x86_l_513a;
	case 20799ULL: goto x86_l_513f;
	case 20807ULL: goto x86_l_5147;
	case 20813ULL: goto x86_l_514d;
	case 20819ULL: goto x86_l_5153;
	case 20823ULL: goto x86_l_5157;
	case 20827ULL: goto x86_l_515b;
	case 20835ULL: goto x86_l_5163;
	case 20837ULL: goto x86_l_5165;
	case 20840ULL: goto x86_l_5168;
	case 20845ULL: goto x86_l_516d;
	case 20850ULL: goto x86_l_5172;
	case 20854ULL: goto x86_l_5176;
	case 20859ULL: goto x86_l_517b;
	case 20861ULL: goto x86_l_517d;
	case 20863ULL: goto x86_l_517f;
	case 20869ULL: goto x86_l_5185;
	case 20874ULL: goto x86_l_518a;
	case 20882ULL: goto x86_l_5192;
	case 20888ULL: goto x86_l_5198;
	case 20894ULL: goto x86_l_519e;
	case 20898ULL: goto x86_l_51a2;
	case 20902ULL: goto x86_l_51a6;
	case 20910ULL: goto x86_l_51ae;
	case 20912ULL: goto x86_l_51b0;
	case 20915ULL: goto x86_l_51b3;
	case 20920ULL: goto x86_l_51b8;
	case 20925ULL: goto x86_l_51bd;
	case 20929ULL: goto x86_l_51c1;
	case 20934ULL: goto x86_l_51c6;
	case 20936ULL: goto x86_l_51c8;
	case 20938ULL: goto x86_l_51ca;
	case 20944ULL: goto x86_l_51d0;
	case 20949ULL: goto x86_l_51d5;
	case 20957ULL: goto x86_l_51dd;
	case 20963ULL: goto x86_l_51e3;
	case 20969ULL: goto x86_l_51e9;
	case 20973ULL: goto x86_l_51ed;
	case 20977ULL: goto x86_l_51f1;
	case 20985ULL: goto x86_l_51f9;
	case 20987ULL: goto x86_l_51fb;
	case 20990ULL: goto x86_l_51fe;
	case 20995ULL: goto x86_l_5203;
	case 21000ULL: goto x86_l_5208;
	case 21004ULL: goto x86_l_520c;
	case 21009ULL: goto x86_l_5211;
	case 21011ULL: goto x86_l_5213;
	case 21013ULL: goto x86_l_5215;
	case 21019ULL: goto x86_l_521b;
	case 21024ULL: goto x86_l_5220;
	case 21032ULL: goto x86_l_5228;
	case 21038ULL: goto x86_l_522e;
	case 21044ULL: goto x86_l_5234;
	case 21048ULL: goto x86_l_5238;
	case 21052ULL: goto x86_l_523c;
	case 21060ULL: goto x86_l_5244;
	case 21062ULL: goto x86_l_5246;
	case 21065ULL: goto x86_l_5249;
	case 21070ULL: goto x86_l_524e;
	case 21075ULL: goto x86_l_5253;
	case 21079ULL: goto x86_l_5257;
	case 21084ULL: goto x86_l_525c;
	case 21086ULL: goto x86_l_525e;
	case 21088ULL: goto x86_l_5260;
	case 21094ULL: goto x86_l_5266;
	case 21099ULL: goto x86_l_526b;
	case 21107ULL: goto x86_l_5273;
	case 21113ULL: goto x86_l_5279;
	case 21119ULL: goto x86_l_527f;
	case 21123ULL: goto x86_l_5283;
	case 21127ULL: goto x86_l_5287;
	case 21135ULL: goto x86_l_528f;
	case 21137ULL: goto x86_l_5291;
	case 21140ULL: goto x86_l_5294;
	case 21145ULL: goto x86_l_5299;
	case 21150ULL: goto x86_l_529e;
	case 21154ULL: goto x86_l_52a2;
	case 21159ULL: goto x86_l_52a7;
	case 21161ULL: goto x86_l_52a9;
	case 21163ULL: goto x86_l_52ab;
	case 21169ULL: goto x86_l_52b1;
	case 21174ULL: goto x86_l_52b6;
	case 21182ULL: goto x86_l_52be;
	case 21188ULL: goto x86_l_52c4;
	case 21194ULL: goto x86_l_52ca;
	case 21198ULL: goto x86_l_52ce;
	case 21202ULL: goto x86_l_52d2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4c27:
	/* 0x4c27: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_4c2a:
	/* 0x4c2a: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_4c2d:
	/* 0x4c2d: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c32:
	/* 0x4c32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c34:
	/* 0x4c34: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4c37:
	/* 0x4c37: je     4c68 <generic_sleepable_preload+0x4c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c68;
	}
x86_l_4c39:
	/* 0x4c39: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_4c3c:
	/* 0x4c3c: je     4c66 <generic_sleepable_preload+0x4c66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c66;
	}
x86_l_4c3e:
	/* 0x4c3e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4c41:
	/* 0x4c41: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4c45:
	/* 0x4c45: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4c4a:
	/* 0x4c4a: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4c4d:
	/* 0x4c4d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c4f:
	/* 0x4c4f: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_4c52:
	/* 0x4c52: call   4c57 <generic_sleepable_preload+0x4c57> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_4c57:
	/* 0x4c57: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_4c59:
	/* 0x4c59: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_4c5c:
	/* 0x4c5c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_4c5e:
	/* 0x4c5e: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_4c63:
	/* 0x4c63: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_4c66:
	/* 0x4c66: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c68:
	/* 0x4c68: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_4c6b:
	/* 0x4c6b: mov    eax,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4c70:
	/* 0x4c70: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_4c75:
	/* 0x4c75: jne    4c8f <generic_sleepable_preload+0x4c8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4c8f;
	}
x86_l_4c77:
	/* 0x4c77: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c79:
	/* 0x4c79: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_4c80:
	/* 0x4c80: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_4c81:
	/* 0x4c81: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_4c83:
	/* 0x4c83: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_4c85:
	/* 0x4c85: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_4c87:
	/* 0x4c87: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_4c89:
	/* 0x4c89: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_4c8a:
	/* 0x4c8a: jmp    5deb <generic_sleepable_preload+0x5deb> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_4c8f:
	/* 0x4c8f: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_4c91:
	/* 0x4c91: js     4cc6 <generic_sleepable_preload+0x4cc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4cc6;
	}
x86_l_4c93:
	/* 0x4c93: mov    eax,DWORD PTR [r12+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4c98:
	/* 0x4c98: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4c9b:
	/* 0x4c9b: jle    4d49 <generic_sleepable_preload+0x4d49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4d49;
	}
x86_l_4ca1:
	/* 0x4ca1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4ca4:
	/* 0x4ca4: je     4db3 <generic_sleepable_preload+0x4db3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4db3;
	}
x86_l_4caa:
	/* 0x4caa: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_4cad:
	/* 0x4cad: je     4dba <generic_sleepable_preload+0x4dba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4dba;
	}
x86_l_4cb3:
	/* 0x4cb3: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4cb6:
	/* 0x4cb6: jne    4dcd <generic_sleepable_preload+0x4dcd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4dcd;
	}
x86_l_4cbc:
	/* 0x4cbc: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4cc1:
	/* 0x4cc1: jmp    4dc6 <generic_sleepable_preload+0x4dc6> */
	goto x86_l_4dc6;
x86_l_4cc6:
	/* 0x4cc6: movzx  eax,BYTE PTR [r12+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_4ccf:
	/* 0x4ccf: movzx  ecx,WORD PTR [r12+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_4cd8:
	/* 0x4cd8: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_4cde:
	/* 0x4cde: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ce0:
	/* 0x4ce0: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4ce3:
	/* 0x4ce3: jle    4d22 <generic_sleepable_preload+0x4d22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4d22;
	}
x86_l_4ce5:
	/* 0x4ce5: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_4ce8:
	/* 0x4ce8: jle    4d59 <generic_sleepable_preload+0x4d59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4d59;
	}
x86_l_4cea:
	/* 0x4cea: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4ced:
	/* 0x4ced: jle    53f4 <generic_sleepable_preload+0x53f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 21492ULL;
	}
x86_l_4cf3:
	/* 0x4cf3: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4cf8:
	/* 0x4cf8: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_4cfb:
	/* 0x4cfb: je     541a <generic_sleepable_preload+0x541a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21530ULL;
	}
x86_l_4d01:
	/* 0x4d01: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4d06:
	/* 0x4d06: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_4d09:
	/* 0x4d09: je     541a <generic_sleepable_preload+0x541a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21530ULL;
	}
x86_l_4d0f:
	/* 0x4d0f: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4d14:
	/* 0x4d14: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_4d17:
	/* 0x4d17: je     541a <generic_sleepable_preload+0x541a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21530ULL;
	}
x86_l_4d1d:
	/* 0x4d1d: jmp    542d <generic_sleepable_preload+0x542d> */
	return 21549ULL;
x86_l_4d22:
	/* 0x4d22: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4d25:
	/* 0x4d25: jg     4d86 <generic_sleepable_preload+0x4d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4d86;
	}
x86_l_4d27:
	/* 0x4d27: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4d2a:
	/* 0x4d2a: jg     53c5 <generic_sleepable_preload+0x53c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 21445ULL;
	}
x86_l_4d30:
	/* 0x4d30: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_4d32:
	/* 0x4d32: je     5415 <generic_sleepable_preload+0x5415> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21525ULL;
	}
x86_l_4d38:
	/* 0x4d38: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4d3b:
	/* 0x4d3b: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_4d3e:
	/* 0x4d3e: je     541a <generic_sleepable_preload+0x541a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21530ULL;
	}
x86_l_4d44:
	/* 0x4d44: jmp    542d <generic_sleepable_preload+0x542d> */
	return 21549ULL;
x86_l_4d49:
	/* 0x4d49: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d4b:
	/* 0x4d4b: je     4dc1 <generic_sleepable_preload+0x4dc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4dc1;
	}
x86_l_4d4d:
	/* 0x4d4d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4d50:
	/* 0x4d50: jne    4dcd <generic_sleepable_preload+0x4dcd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4dcd;
	}
x86_l_4d52:
	/* 0x4d52: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4d57:
	/* 0x4d57: jmp    4dc6 <generic_sleepable_preload+0x4dc6> */
	goto x86_l_4dc6;
x86_l_4d59:
	/* 0x4d59: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_4d5c:
	/* 0x4d5c: jg     53ac <generic_sleepable_preload+0x53ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 21420ULL;
	}
x86_l_4d62:
	/* 0x4d62: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4d6a:
	/* 0x4d6a: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4d6d:
	/* 0x4d6d: je     541a <generic_sleepable_preload+0x541a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21530ULL;
	}
x86_l_4d73:
	/* 0x4d73: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4d78:
	/* 0x4d78: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_4d7b:
	/* 0x4d7b: je     541a <generic_sleepable_preload+0x541a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21530ULL;
	}
x86_l_4d81:
	/* 0x4d81: jmp    542d <generic_sleepable_preload+0x542d> */
	return 21549ULL;
x86_l_4d86:
	/* 0x4d86: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4d89:
	/* 0x4d89: jg     53db <generic_sleepable_preload+0x53db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 21467ULL;
	}
x86_l_4d8f:
	/* 0x4d8f: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4d97:
	/* 0x4d97: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_4d9a:
	/* 0x4d9a: je     541a <generic_sleepable_preload+0x541a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21530ULL;
	}
x86_l_4da0:
	/* 0x4da0: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4da5:
	/* 0x4da5: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4da8:
	/* 0x4da8: je     541a <generic_sleepable_preload+0x541a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21530ULL;
	}
x86_l_4dae:
	/* 0x4dae: jmp    542d <generic_sleepable_preload+0x542d> */
	return 21549ULL;
x86_l_4db3:
	/* 0x4db3: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4db8:
	/* 0x4db8: jmp    4dc6 <generic_sleepable_preload+0x4dc6> */
	goto x86_l_4dc6;
x86_l_4dba:
	/* 0x4dba: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4dbf:
	/* 0x4dbf: jmp    4dc6 <generic_sleepable_preload+0x4dc6> */
	goto x86_l_4dc6;
x86_l_4dc1:
	/* 0x4dc1: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4dc6:
	/* 0x4dc6: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dc9:
	/* 0x4dc9: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dcd:
	/* 0x4dcd: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4dd0:
	/* 0x4dd0: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_4dd3:
	/* 0x4dd3: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4dd8:
	/* 0x4dd8: cmp    WORD PTR [rsi+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_4de0:
	/* 0x4de0: je     5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23155ULL;
	}
x86_l_4de6:
	/* 0x4de6: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_4ded:
	/* 0x4ded: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_4df0:
	/* 0x4df0: mov    eax,DWORD PTR [rsi+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_4df6:
	/* 0x4df6: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4df9:
	/* 0x4df9: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dfd:
	/* 0x4dfd: movzx  eax,WORD PTR [rsi+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_4e04:
	/* 0x4e04: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_4e06:
	/* 0x4e06: je     50ca <generic_sleepable_preload+0x50ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50ca;
	}
x86_l_4e0c:
	/* 0x4e0c: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4e0f:
	/* 0x4e0f: je     4e31 <generic_sleepable_preload+0x4e31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e31;
	}
x86_l_4e11:
	/* 0x4e11: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4e14:
	/* 0x4e14: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4e19:
	/* 0x4e19: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e1e:
	/* 0x4e1e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e22:
	/* 0x4e22: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e27:
	/* 0x4e27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e29:
	/* 0x4e29: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e2b:
	/* 0x4e2b: js     53a1 <generic_sleepable_preload+0x53a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21409ULL;
	}
x86_l_4e31:
	/* 0x4e31: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e36:
	/* 0x4e36: cmp    WORD PTR [rax+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_4e3e:
	/* 0x4e3e: je     5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23155ULL;
	}
x86_l_4e44:
	/* 0x4e44: mov    ecx,DWORD PTR [rax+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_4e4a:
	/* 0x4e4a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4e4e:
	/* 0x4e4e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e52:
	/* 0x4e52: cmp    WORD PTR [rax+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_4e5a:
	/* 0x4e5a: je     4e7c <generic_sleepable_preload+0x4e7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e7c;
	}
x86_l_4e5c:
	/* 0x4e5c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4e5f:
	/* 0x4e5f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4e64:
	/* 0x4e64: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e69:
	/* 0x4e69: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e6d:
	/* 0x4e6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e72:
	/* 0x4e72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e74:
	/* 0x4e74: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e76:
	/* 0x4e76: js     540a <generic_sleepable_preload+0x540a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21514ULL;
	}
x86_l_4e7c:
	/* 0x4e7c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e81:
	/* 0x4e81: cmp    WORD PTR [rax+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_4e89:
	/* 0x4e89: je     5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23155ULL;
	}
x86_l_4e8f:
	/* 0x4e8f: mov    ecx,DWORD PTR [rax+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_4e95:
	/* 0x4e95: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4e99:
	/* 0x4e99: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e9d:
	/* 0x4e9d: cmp    WORD PTR [rax+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_4ea5:
	/* 0x4ea5: je     4ec7 <generic_sleepable_preload+0x4ec7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ec7;
	}
x86_l_4ea7:
	/* 0x4ea7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4eaa:
	/* 0x4eaa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4eaf:
	/* 0x4eaf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4eb4:
	/* 0x4eb4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4eb8:
	/* 0x4eb8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ebd:
	/* 0x4ebd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ebf:
	/* 0x4ebf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ec1:
	/* 0x4ec1: js     5a1e <generic_sleepable_preload+0x5a1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23070ULL;
	}
x86_l_4ec7:
	/* 0x4ec7: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ecc:
	/* 0x4ecc: cmp    WORD PTR [rax+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_4ed4:
	/* 0x4ed4: je     5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23155ULL;
	}
x86_l_4eda:
	/* 0x4eda: mov    ecx,DWORD PTR [rax+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_4ee0:
	/* 0x4ee0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4ee4:
	/* 0x4ee4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ee8:
	/* 0x4ee8: cmp    WORD PTR [rax+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_4ef0:
	/* 0x4ef0: je     4f12 <generic_sleepable_preload+0x4f12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f12;
	}
x86_l_4ef2:
	/* 0x4ef2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4ef5:
	/* 0x4ef5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4efa:
	/* 0x4efa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4eff:
	/* 0x4eff: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f03:
	/* 0x4f03: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f08:
	/* 0x4f08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f0a:
	/* 0x4f0a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f0c:
	/* 0x4f0c: js     5a31 <generic_sleepable_preload+0x5a31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23089ULL;
	}
x86_l_4f12:
	/* 0x4f12: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f17:
	/* 0x4f17: cmp    WORD PTR [rax+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_4f1f:
	/* 0x4f1f: je     5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23155ULL;
	}
x86_l_4f25:
	/* 0x4f25: mov    ecx,DWORD PTR [rax+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_4f2b:
	/* 0x4f2b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4f2f:
	/* 0x4f2f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f33:
	/* 0x4f33: cmp    WORD PTR [rax+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_4f3b:
	/* 0x4f3b: je     4f5d <generic_sleepable_preload+0x4f5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f5d;
	}
x86_l_4f3d:
	/* 0x4f3d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4f40:
	/* 0x4f40: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4f45:
	/* 0x4f45: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4f4a:
	/* 0x4f4a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f4e:
	/* 0x4f4e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f53:
	/* 0x4f53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f55:
	/* 0x4f55: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f57:
	/* 0x4f57: js     5a44 <generic_sleepable_preload+0x5a44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23108ULL;
	}
x86_l_4f5d:
	/* 0x4f5d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f62:
	/* 0x4f62: cmp    WORD PTR [rax+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_4f6a:
	/* 0x4f6a: je     5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23155ULL;
	}
x86_l_4f70:
	/* 0x4f70: mov    ecx,DWORD PTR [rax+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_4f76:
	/* 0x4f76: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4f7a:
	/* 0x4f7a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f7e:
	/* 0x4f7e: cmp    WORD PTR [rax+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_4f86:
	/* 0x4f86: je     4fa8 <generic_sleepable_preload+0x4fa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fa8;
	}
x86_l_4f88:
	/* 0x4f88: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4f8b:
	/* 0x4f8b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4f90:
	/* 0x4f90: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4f95:
	/* 0x4f95: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f99:
	/* 0x4f99: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f9e:
	/* 0x4f9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fa0:
	/* 0x4fa0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4fa2:
	/* 0x4fa2: js     5a57 <generic_sleepable_preload+0x5a57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23127ULL;
	}
x86_l_4fa8:
	/* 0x4fa8: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fad:
	/* 0x4fad: cmp    WORD PTR [rax+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_4fb5:
	/* 0x4fb5: je     5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23155ULL;
	}
x86_l_4fbb:
	/* 0x4fbb: mov    ecx,DWORD PTR [rax+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_4fc1:
	/* 0x4fc1: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4fc5:
	/* 0x4fc5: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fc9:
	/* 0x4fc9: cmp    WORD PTR [rax+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_4fd1:
	/* 0x4fd1: je     4ff3 <generic_sleepable_preload+0x4ff3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ff3;
	}
x86_l_4fd3:
	/* 0x4fd3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4fd6:
	/* 0x4fd6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4fdb:
	/* 0x4fdb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4fe0:
	/* 0x4fe0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fe4:
	/* 0x4fe4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4fe9:
	/* 0x4fe9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4feb:
	/* 0x4feb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4fed:
	/* 0x4fed: js     5a6a <generic_sleepable_preload+0x5a6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23146ULL;
	}
x86_l_4ff3:
	/* 0x4ff3: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ff8:
	/* 0x4ff8: cmp    WORD PTR [rax+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_5000:
	/* 0x5000: je     5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23155ULL;
	}
x86_l_5006:
	/* 0x5006: mov    ecx,DWORD PTR [rax+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_500c:
	/* 0x500c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5010:
	/* 0x5010: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5014:
	/* 0x5014: cmp    WORD PTR [rax+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_501c:
	/* 0x501c: je     503e <generic_sleepable_preload+0x503e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_503e;
	}
x86_l_501e:
	/* 0x501e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5021:
	/* 0x5021: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5026:
	/* 0x5026: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_502b:
	/* 0x502b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_502f:
	/* 0x502f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5034:
	/* 0x5034: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5036:
	/* 0x5036: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5038:
	/* 0x5038: js     5ba8 <generic_sleepable_preload+0x5ba8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23464ULL;
	}
x86_l_503e:
	/* 0x503e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5043:
	/* 0x5043: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_504b:
	/* 0x504b: je     5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23155ULL;
	}
x86_l_5051:
	/* 0x5051: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_5057:
	/* 0x5057: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_505b:
	/* 0x505b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_505f:
	/* 0x505f: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_5067:
	/* 0x5067: je     5089 <generic_sleepable_preload+0x5089> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5089;
	}
x86_l_5069:
	/* 0x5069: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_506c:
	/* 0x506c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5071:
	/* 0x5071: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5076:
	/* 0x5076: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_507a:
	/* 0x507a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_507f:
	/* 0x507f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5081:
	/* 0x5081: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5083:
	/* 0x5083: js     5c35 <generic_sleepable_preload+0x5c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23605ULL;
	}
x86_l_5089:
	/* 0x5089: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_508e:
	/* 0x508e: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_5096:
	/* 0x5096: je     5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23155ULL;
	}
x86_l_509c:
	/* 0x509c: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_50a2:
	/* 0x50a2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_50a6:
	/* 0x50a6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_50aa:
	/* 0x50aa: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_50b2:
	/* 0x50b2: je     5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23155ULL;
	}
x86_l_50b8:
	/* 0x50b8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_50bb:
	/* 0x50bb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_50c0:
	/* 0x50c0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_50c5:
	/* 0x50c5: jmp    5383 <generic_sleepable_preload+0x5383> */
	return 21379ULL;
x86_l_50ca:
	/* 0x50ca: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_50cd:
	/* 0x50cd: je     50ef <generic_sleepable_preload+0x50ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50ef;
	}
x86_l_50cf:
	/* 0x50cf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_50d2:
	/* 0x50d2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_50d7:
	/* 0x50d7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_50dc:
	/* 0x50dc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_50e0:
	/* 0x50e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50e5:
	/* 0x50e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50e7:
	/* 0x50e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_50e9:
	/* 0x50e9: js     53a1 <generic_sleepable_preload+0x53a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21409ULL;
	}
x86_l_50ef:
	/* 0x50ef: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50f4:
	/* 0x50f4: cmp    WORD PTR [rax+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_50fc:
	/* 0x50fc: je     5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23155ULL;
	}
x86_l_5102:
	/* 0x5102: mov    ecx,DWORD PTR [rax+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_5108:
	/* 0x5108: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_510c:
	/* 0x510c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5110:
	/* 0x5110: cmp    WORD PTR [rax+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_5118:
	/* 0x5118: je     513a <generic_sleepable_preload+0x513a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_513a;
	}
x86_l_511a:
	/* 0x511a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_511d:
	/* 0x511d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5122:
	/* 0x5122: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5127:
	/* 0x5127: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_512b:
	/* 0x512b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5130:
	/* 0x5130: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5132:
	/* 0x5132: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5134:
	/* 0x5134: js     540a <generic_sleepable_preload+0x540a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21514ULL;
	}
x86_l_513a:
	/* 0x513a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_513f:
	/* 0x513f: cmp    WORD PTR [rax+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_5147:
	/* 0x5147: je     5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23155ULL;
	}
x86_l_514d:
	/* 0x514d: mov    ecx,DWORD PTR [rax+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_5153:
	/* 0x5153: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5157:
	/* 0x5157: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_515b:
	/* 0x515b: cmp    WORD PTR [rax+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_5163:
	/* 0x5163: je     5185 <generic_sleepable_preload+0x5185> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5185;
	}
x86_l_5165:
	/* 0x5165: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5168:
	/* 0x5168: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_516d:
	/* 0x516d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5172:
	/* 0x5172: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5176:
	/* 0x5176: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_517b:
	/* 0x517b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_517d:
	/* 0x517d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_517f:
	/* 0x517f: js     5a1e <generic_sleepable_preload+0x5a1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23070ULL;
	}
x86_l_5185:
	/* 0x5185: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_518a:
	/* 0x518a: cmp    WORD PTR [rax+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_5192:
	/* 0x5192: je     5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23155ULL;
	}
x86_l_5198:
	/* 0x5198: mov    ecx,DWORD PTR [rax+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_519e:
	/* 0x519e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_51a2:
	/* 0x51a2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51a6:
	/* 0x51a6: cmp    WORD PTR [rax+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_51ae:
	/* 0x51ae: je     51d0 <generic_sleepable_preload+0x51d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_51d0;
	}
x86_l_51b0:
	/* 0x51b0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_51b3:
	/* 0x51b3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_51b8:
	/* 0x51b8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_51bd:
	/* 0x51bd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51c1:
	/* 0x51c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51c6:
	/* 0x51c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51c8:
	/* 0x51c8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_51ca:
	/* 0x51ca: js     5a31 <generic_sleepable_preload+0x5a31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23089ULL;
	}
x86_l_51d0:
	/* 0x51d0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51d5:
	/* 0x51d5: cmp    WORD PTR [rax+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_51dd:
	/* 0x51dd: je     5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23155ULL;
	}
x86_l_51e3:
	/* 0x51e3: mov    ecx,DWORD PTR [rax+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_51e9:
	/* 0x51e9: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_51ed:
	/* 0x51ed: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51f1:
	/* 0x51f1: cmp    WORD PTR [rax+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_51f9:
	/* 0x51f9: je     521b <generic_sleepable_preload+0x521b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_521b;
	}
x86_l_51fb:
	/* 0x51fb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_51fe:
	/* 0x51fe: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5203:
	/* 0x5203: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5208:
	/* 0x5208: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_520c:
	/* 0x520c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5211:
	/* 0x5211: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5213:
	/* 0x5213: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5215:
	/* 0x5215: js     5a44 <generic_sleepable_preload+0x5a44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23108ULL;
	}
x86_l_521b:
	/* 0x521b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5220:
	/* 0x5220: cmp    WORD PTR [rax+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_5228:
	/* 0x5228: je     5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23155ULL;
	}
x86_l_522e:
	/* 0x522e: mov    ecx,DWORD PTR [rax+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_5234:
	/* 0x5234: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5238:
	/* 0x5238: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_523c:
	/* 0x523c: cmp    WORD PTR [rax+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_5244:
	/* 0x5244: je     5266 <generic_sleepable_preload+0x5266> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5266;
	}
x86_l_5246:
	/* 0x5246: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5249:
	/* 0x5249: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_524e:
	/* 0x524e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5253:
	/* 0x5253: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5257:
	/* 0x5257: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_525c:
	/* 0x525c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_525e:
	/* 0x525e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5260:
	/* 0x5260: js     5a57 <generic_sleepable_preload+0x5a57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23127ULL;
	}
x86_l_5266:
	/* 0x5266: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_526b:
	/* 0x526b: cmp    WORD PTR [rax+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_5273:
	/* 0x5273: je     5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23155ULL;
	}
x86_l_5279:
	/* 0x5279: mov    ecx,DWORD PTR [rax+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_527f:
	/* 0x527f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5283:
	/* 0x5283: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5287:
	/* 0x5287: cmp    WORD PTR [rax+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_528f:
	/* 0x528f: je     52b1 <generic_sleepable_preload+0x52b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_52b1;
	}
x86_l_5291:
	/* 0x5291: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5294:
	/* 0x5294: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5299:
	/* 0x5299: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_529e:
	/* 0x529e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52a2:
	/* 0x52a2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52a7:
	/* 0x52a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52a9:
	/* 0x52a9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52ab:
	/* 0x52ab: js     5a6a <generic_sleepable_preload+0x5a6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23146ULL;
	}
x86_l_52b1:
	/* 0x52b1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52b6:
	/* 0x52b6: cmp    WORD PTR [rax+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_52be:
	/* 0x52be: je     5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23155ULL;
	}
x86_l_52c4:
	/* 0x52c4: mov    ecx,DWORD PTR [rax+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_52ca:
	/* 0x52ca: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_52ce:
	/* 0x52ce: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52d2:
	/* 0x52d2: cmp    WORD PTR [rax+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
	return 21210ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 21210ULL: goto x86_l_52da;
	case 21212ULL: goto x86_l_52dc;
	case 21215ULL: goto x86_l_52df;
	case 21220ULL: goto x86_l_52e4;
	case 21225ULL: goto x86_l_52e9;
	case 21229ULL: goto x86_l_52ed;
	case 21234ULL: goto x86_l_52f2;
	case 21236ULL: goto x86_l_52f4;
	case 21238ULL: goto x86_l_52f6;
	case 21244ULL: goto x86_l_52fc;
	case 21249ULL: goto x86_l_5301;
	case 21257ULL: goto x86_l_5309;
	case 21263ULL: goto x86_l_530f;
	case 21269ULL: goto x86_l_5315;
	case 21273ULL: goto x86_l_5319;
	case 21277ULL: goto x86_l_531d;
	case 21285ULL: goto x86_l_5325;
	case 21287ULL: goto x86_l_5327;
	case 21290ULL: goto x86_l_532a;
	case 21295ULL: goto x86_l_532f;
	case 21300ULL: goto x86_l_5334;
	case 21304ULL: goto x86_l_5338;
	case 21309ULL: goto x86_l_533d;
	case 21311ULL: goto x86_l_533f;
	case 21313ULL: goto x86_l_5341;
	case 21319ULL: goto x86_l_5347;
	case 21324ULL: goto x86_l_534c;
	case 21332ULL: goto x86_l_5354;
	case 21338ULL: goto x86_l_535a;
	case 21344ULL: goto x86_l_5360;
	case 21348ULL: goto x86_l_5364;
	case 21352ULL: goto x86_l_5368;
	case 21360ULL: goto x86_l_5370;
	case 21366ULL: goto x86_l_5376;
	case 21369ULL: goto x86_l_5379;
	case 21374ULL: goto x86_l_537e;
	case 21379ULL: goto x86_l_5383;
	case 21383ULL: goto x86_l_5387;
	case 21388ULL: goto x86_l_538c;
	case 21390ULL: goto x86_l_538e;
	case 21392ULL: goto x86_l_5390;
	case 21398ULL: goto x86_l_5396;
	case 21404ULL: goto x86_l_539c;
	case 21409ULL: goto x86_l_53a1;
	case 21415ULL: goto x86_l_53a7;
	case 21420ULL: goto x86_l_53ac;
	case 21428ULL: goto x86_l_53b4;
	case 21431ULL: goto x86_l_53b7;
	case 21433ULL: goto x86_l_53b9;
	case 21438ULL: goto x86_l_53be;
	case 21441ULL: goto x86_l_53c1;
	case 21443ULL: goto x86_l_53c3;
	case 21445ULL: goto x86_l_53c5;
	case 21450ULL: goto x86_l_53ca;
	case 21453ULL: goto x86_l_53cd;
	case 21455ULL: goto x86_l_53cf;
	case 21460ULL: goto x86_l_53d4;
	case 21463ULL: goto x86_l_53d7;
	case 21465ULL: goto x86_l_53d9;
	case 21467ULL: goto x86_l_53db;
	case 21475ULL: goto x86_l_53e3;
	case 21478ULL: goto x86_l_53e6;
	case 21480ULL: goto x86_l_53e8;
	case 21485ULL: goto x86_l_53ed;
	case 21488ULL: goto x86_l_53f0;
	case 21490ULL: goto x86_l_53f2;
	case 21492ULL: goto x86_l_53f4;
	case 21497ULL: goto x86_l_53f9;
	case 21500ULL: goto x86_l_53fc;
	case 21502ULL: goto x86_l_53fe;
	case 21507ULL: goto x86_l_5403;
	case 21510ULL: goto x86_l_5406;
	case 21512ULL: goto x86_l_5408;
	case 21514ULL: goto x86_l_540a;
	case 21520ULL: goto x86_l_5410;
	case 21525ULL: goto x86_l_5415;
	case 21530ULL: goto x86_l_541a;
	case 21533ULL: goto x86_l_541d;
	case 21535ULL: goto x86_l_541f;
	case 21537ULL: goto x86_l_5421;
	case 21542ULL: goto x86_l_5426;
	case 21544ULL: goto x86_l_5428;
	case 21549ULL: goto x86_l_542d;
	case 21553ULL: goto x86_l_5431;
	case 21558ULL: goto x86_l_5436;
	case 21561ULL: goto x86_l_5439;
	case 21564ULL: goto x86_l_543c;
	case 21567ULL: goto x86_l_543f;
	case 21575ULL: goto x86_l_5447;
	case 21581ULL: goto x86_l_544d;
	case 21588ULL: goto x86_l_5454;
	case 21591ULL: goto x86_l_5457;
	case 21597ULL: goto x86_l_545d;
	case 21600ULL: goto x86_l_5460;
	case 21604ULL: goto x86_l_5464;
	case 21611ULL: goto x86_l_546b;
	case 21613ULL: goto x86_l_546d;
	case 21619ULL: goto x86_l_5473;
	case 21622ULL: goto x86_l_5476;
	case 21624ULL: goto x86_l_5478;
	case 21627ULL: goto x86_l_547b;
	case 21632ULL: goto x86_l_5480;
	case 21637ULL: goto x86_l_5485;
	case 21641ULL: goto x86_l_5489;
	case 21646ULL: goto x86_l_548e;
	case 21648ULL: goto x86_l_5490;
	case 21650ULL: goto x86_l_5492;
	case 21656ULL: goto x86_l_5498;
	case 21661ULL: goto x86_l_549d;
	case 21669ULL: goto x86_l_54a5;
	case 21675ULL: goto x86_l_54ab;
	case 21681ULL: goto x86_l_54b1;
	case 21685ULL: goto x86_l_54b5;
	case 21689ULL: goto x86_l_54b9;
	case 21697ULL: goto x86_l_54c1;
	case 21699ULL: goto x86_l_54c3;
	case 21702ULL: goto x86_l_54c6;
	case 21707ULL: goto x86_l_54cb;
	case 21712ULL: goto x86_l_54d0;
	case 21716ULL: goto x86_l_54d4;
	case 21721ULL: goto x86_l_54d9;
	case 21723ULL: goto x86_l_54db;
	case 21725ULL: goto x86_l_54dd;
	case 21731ULL: goto x86_l_54e3;
	case 21736ULL: goto x86_l_54e8;
	case 21744ULL: goto x86_l_54f0;
	case 21750ULL: goto x86_l_54f6;
	case 21756ULL: goto x86_l_54fc;
	case 21760ULL: goto x86_l_5500;
	case 21764ULL: goto x86_l_5504;
	case 21772ULL: goto x86_l_550c;
	case 21774ULL: goto x86_l_550e;
	case 21777ULL: goto x86_l_5511;
	case 21782ULL: goto x86_l_5516;
	case 21787ULL: goto x86_l_551b;
	case 21791ULL: goto x86_l_551f;
	case 21796ULL: goto x86_l_5524;
	case 21798ULL: goto x86_l_5526;
	case 21800ULL: goto x86_l_5528;
	case 21806ULL: goto x86_l_552e;
	case 21811ULL: goto x86_l_5533;
	case 21819ULL: goto x86_l_553b;
	case 21825ULL: goto x86_l_5541;
	case 21831ULL: goto x86_l_5547;
	case 21835ULL: goto x86_l_554b;
	case 21839ULL: goto x86_l_554f;
	case 21847ULL: goto x86_l_5557;
	case 21849ULL: goto x86_l_5559;
	case 21852ULL: goto x86_l_555c;
	case 21857ULL: goto x86_l_5561;
	case 21862ULL: goto x86_l_5566;
	case 21866ULL: goto x86_l_556a;
	case 21871ULL: goto x86_l_556f;
	case 21873ULL: goto x86_l_5571;
	case 21875ULL: goto x86_l_5573;
	case 21881ULL: goto x86_l_5579;
	case 21886ULL: goto x86_l_557e;
	case 21894ULL: goto x86_l_5586;
	case 21900ULL: goto x86_l_558c;
	case 21906ULL: goto x86_l_5592;
	case 21910ULL: goto x86_l_5596;
	case 21914ULL: goto x86_l_559a;
	case 21922ULL: goto x86_l_55a2;
	case 21924ULL: goto x86_l_55a4;
	case 21927ULL: goto x86_l_55a7;
	case 21932ULL: goto x86_l_55ac;
	case 21937ULL: goto x86_l_55b1;
	case 21941ULL: goto x86_l_55b5;
	case 21946ULL: goto x86_l_55ba;
	case 21948ULL: goto x86_l_55bc;
	case 21950ULL: goto x86_l_55be;
	case 21956ULL: goto x86_l_55c4;
	case 21961ULL: goto x86_l_55c9;
	case 21969ULL: goto x86_l_55d1;
	case 21975ULL: goto x86_l_55d7;
	case 21981ULL: goto x86_l_55dd;
	case 21985ULL: goto x86_l_55e1;
	case 21989ULL: goto x86_l_55e5;
	case 21997ULL: goto x86_l_55ed;
	case 21999ULL: goto x86_l_55ef;
	case 22002ULL: goto x86_l_55f2;
	case 22007ULL: goto x86_l_55f7;
	case 22012ULL: goto x86_l_55fc;
	case 22016ULL: goto x86_l_5600;
	case 22021ULL: goto x86_l_5605;
	case 22023ULL: goto x86_l_5607;
	case 22025ULL: goto x86_l_5609;
	case 22031ULL: goto x86_l_560f;
	case 22036ULL: goto x86_l_5614;
	case 22044ULL: goto x86_l_561c;
	case 22050ULL: goto x86_l_5622;
	case 22056ULL: goto x86_l_5628;
	case 22060ULL: goto x86_l_562c;
	case 22064ULL: goto x86_l_5630;
	case 22072ULL: goto x86_l_5638;
	case 22074ULL: goto x86_l_563a;
	case 22077ULL: goto x86_l_563d;
	case 22082ULL: goto x86_l_5642;
	case 22087ULL: goto x86_l_5647;
	case 22091ULL: goto x86_l_564b;
	case 22096ULL: goto x86_l_5650;
	case 22098ULL: goto x86_l_5652;
	case 22100ULL: goto x86_l_5654;
	case 22106ULL: goto x86_l_565a;
	case 22111ULL: goto x86_l_565f;
	case 22119ULL: goto x86_l_5667;
	case 22125ULL: goto x86_l_566d;
	case 22131ULL: goto x86_l_5673;
	case 22135ULL: goto x86_l_5677;
	case 22139ULL: goto x86_l_567b;
	case 22147ULL: goto x86_l_5683;
	case 22149ULL: goto x86_l_5685;
	case 22152ULL: goto x86_l_5688;
	case 22157ULL: goto x86_l_568d;
	case 22162ULL: goto x86_l_5692;
	case 22166ULL: goto x86_l_5696;
	case 22171ULL: goto x86_l_569b;
	case 22173ULL: goto x86_l_569d;
	case 22175ULL: goto x86_l_569f;
	case 22181ULL: goto x86_l_56a5;
	case 22186ULL: goto x86_l_56aa;
	case 22194ULL: goto x86_l_56b2;
	case 22200ULL: goto x86_l_56b8;
	case 22206ULL: goto x86_l_56be;
	case 22210ULL: goto x86_l_56c2;
	case 22214ULL: goto x86_l_56c6;
	case 22222ULL: goto x86_l_56ce;
	case 22224ULL: goto x86_l_56d0;
	case 22227ULL: goto x86_l_56d3;
	case 22232ULL: goto x86_l_56d8;
	case 22237ULL: goto x86_l_56dd;
	case 22241ULL: goto x86_l_56e1;
	case 22246ULL: goto x86_l_56e6;
	case 22248ULL: goto x86_l_56e8;
	case 22250ULL: goto x86_l_56ea;
	case 22256ULL: goto x86_l_56f0;
	case 22261ULL: goto x86_l_56f5;
	case 22269ULL: goto x86_l_56fd;
	case 22275ULL: goto x86_l_5703;
	case 22281ULL: goto x86_l_5709;
	case 22285ULL: goto x86_l_570d;
	case 22289ULL: goto x86_l_5711;
	case 22297ULL: goto x86_l_5719;
	case 22303ULL: goto x86_l_571f;
	case 22306ULL: goto x86_l_5722;
	case 22311ULL: goto x86_l_5727;
	case 22316ULL: goto x86_l_572c;
	case 22321ULL: goto x86_l_5731;
	case 22324ULL: goto x86_l_5734;
	case 22326ULL: goto x86_l_5736;
	case 22329ULL: goto x86_l_5739;
	case 22334ULL: goto x86_l_573e;
	case 22339ULL: goto x86_l_5743;
	case 22343ULL: goto x86_l_5747;
	case 22348ULL: goto x86_l_574c;
	case 22350ULL: goto x86_l_574e;
	case 22352ULL: goto x86_l_5750;
	case 22358ULL: goto x86_l_5756;
	case 22363ULL: goto x86_l_575b;
	case 22371ULL: goto x86_l_5763;
	case 22377ULL: goto x86_l_5769;
	case 22383ULL: goto x86_l_576f;
	case 22387ULL: goto x86_l_5773;
	case 22391ULL: goto x86_l_5777;
	case 22399ULL: goto x86_l_577f;
	case 22401ULL: goto x86_l_5781;
	case 22404ULL: goto x86_l_5784;
	case 22409ULL: goto x86_l_5789;
	case 22414ULL: goto x86_l_578e;
	case 22418ULL: goto x86_l_5792;
	case 22423ULL: goto x86_l_5797;
	case 22425ULL: goto x86_l_5799;
	case 22427ULL: goto x86_l_579b;
	case 22433ULL: goto x86_l_57a1;
	case 22438ULL: goto x86_l_57a6;
	case 22446ULL: goto x86_l_57ae;
	case 22452ULL: goto x86_l_57b4;
	case 22458ULL: goto x86_l_57ba;
	case 22462ULL: goto x86_l_57be;
	case 22466ULL: goto x86_l_57c2;
	case 22474ULL: goto x86_l_57ca;
	case 22476ULL: goto x86_l_57cc;
	case 22479ULL: goto x86_l_57cf;
	case 22484ULL: goto x86_l_57d4;
	case 22489ULL: goto x86_l_57d9;
	case 22493ULL: goto x86_l_57dd;
	case 22498ULL: goto x86_l_57e2;
	case 22500ULL: goto x86_l_57e4;
	case 22502ULL: goto x86_l_57e6;
	case 22508ULL: goto x86_l_57ec;
	case 22513ULL: goto x86_l_57f1;
	case 22521ULL: goto x86_l_57f9;
	case 22527ULL: goto x86_l_57ff;
	case 22533ULL: goto x86_l_5805;
	case 22537ULL: goto x86_l_5809;
	case 22541ULL: goto x86_l_580d;
	case 22549ULL: goto x86_l_5815;
	case 22551ULL: goto x86_l_5817;
	case 22554ULL: goto x86_l_581a;
	case 22559ULL: goto x86_l_581f;
	case 22564ULL: goto x86_l_5824;
	case 22568ULL: goto x86_l_5828;
	case 22573ULL: goto x86_l_582d;
	case 22575ULL: goto x86_l_582f;
	case 22577ULL: goto x86_l_5831;
	case 22583ULL: goto x86_l_5837;
	case 22588ULL: goto x86_l_583c;
	case 22596ULL: goto x86_l_5844;
	case 22602ULL: goto x86_l_584a;
	case 22608ULL: goto x86_l_5850;
	case 22612ULL: goto x86_l_5854;
	case 22616ULL: goto x86_l_5858;
	case 22624ULL: goto x86_l_5860;
	case 22626ULL: goto x86_l_5862;
	case 22629ULL: goto x86_l_5865;
	case 22634ULL: goto x86_l_586a;
	case 22639ULL: goto x86_l_586f;
	case 22643ULL: goto x86_l_5873;
	case 22648ULL: goto x86_l_5878;
	case 22650ULL: goto x86_l_587a;
	case 22652ULL: goto x86_l_587c;
	case 22658ULL: goto x86_l_5882;
	case 22663ULL: goto x86_l_5887;
	case 22671ULL: goto x86_l_588f;
	case 22677ULL: goto x86_l_5895;
	case 22683ULL: goto x86_l_589b;
	case 22687ULL: goto x86_l_589f;
	case 22691ULL: goto x86_l_58a3;
	case 22699ULL: goto x86_l_58ab;
	case 22701ULL: goto x86_l_58ad;
	case 22704ULL: goto x86_l_58b0;
	case 22709ULL: goto x86_l_58b5;
	case 22714ULL: goto x86_l_58ba;
	case 22718ULL: goto x86_l_58be;
	case 22723ULL: goto x86_l_58c3;
	case 22725ULL: goto x86_l_58c5;
	case 22727ULL: goto x86_l_58c7;
	case 22733ULL: goto x86_l_58cd;
	case 22738ULL: goto x86_l_58d2;
	case 22746ULL: goto x86_l_58da;
	case 22752ULL: goto x86_l_58e0;
	case 22758ULL: goto x86_l_58e6;
	case 22762ULL: goto x86_l_58ea;
	case 22766ULL: goto x86_l_58ee;
	case 22774ULL: goto x86_l_58f6;
	case 22776ULL: goto x86_l_58f8;
	case 22779ULL: goto x86_l_58fb;
	case 22784ULL: goto x86_l_5900;
	case 22789ULL: goto x86_l_5905;
	case 22793ULL: goto x86_l_5909;
	case 22798ULL: goto x86_l_590e;
	case 22800ULL: goto x86_l_5910;
	case 22802ULL: goto x86_l_5912;
	case 22808ULL: goto x86_l_5918;
	case 22813ULL: goto x86_l_591d;
	case 22821ULL: goto x86_l_5925;
	case 22827ULL: goto x86_l_592b;
	case 22833ULL: goto x86_l_5931;
	case 22837ULL: goto x86_l_5935;
	case 22841ULL: goto x86_l_5939;
	case 22849ULL: goto x86_l_5941;
	case 22851ULL: goto x86_l_5943;
	case 22854ULL: goto x86_l_5946;
	case 22859ULL: goto x86_l_594b;
	case 22864ULL: goto x86_l_5950;
	case 22868ULL: goto x86_l_5954;
	case 22873ULL: goto x86_l_5959;
	case 22875ULL: goto x86_l_595b;
	case 22877ULL: goto x86_l_595d;
	case 22883ULL: goto x86_l_5963;
	case 22888ULL: goto x86_l_5968;
	case 22896ULL: goto x86_l_5970;
	case 22902ULL: goto x86_l_5976;
	case 22908ULL: goto x86_l_597c;
	case 22912ULL: goto x86_l_5980;
	case 22916ULL: goto x86_l_5984;
	case 22924ULL: goto x86_l_598c;
	case 22926ULL: goto x86_l_598e;
	case 22929ULL: goto x86_l_5991;
	case 22934ULL: goto x86_l_5996;
	case 22939ULL: goto x86_l_599b;
	case 22943ULL: goto x86_l_599f;
	case 22948ULL: goto x86_l_59a4;
	case 22950ULL: goto x86_l_59a6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_52da:
	/* 0x52da: je     52fc <generic_sleepable_preload+0x52fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_52fc;
	}
x86_l_52dc:
	/* 0x52dc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_52df:
	/* 0x52df: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_52e4:
	/* 0x52e4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_52e9:
	/* 0x52e9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52ed:
	/* 0x52ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52f2:
	/* 0x52f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52f4:
	/* 0x52f4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52f6:
	/* 0x52f6: js     5ba8 <generic_sleepable_preload+0x5ba8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23464ULL;
	}
x86_l_52fc:
	/* 0x52fc: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5301:
	/* 0x5301: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_5309:
	/* 0x5309: je     5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23155ULL;
	}
x86_l_530f:
	/* 0x530f: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_5315:
	/* 0x5315: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5319:
	/* 0x5319: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_531d:
	/* 0x531d: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_5325:
	/* 0x5325: je     5347 <generic_sleepable_preload+0x5347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5347;
	}
x86_l_5327:
	/* 0x5327: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_532a:
	/* 0x532a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_532f:
	/* 0x532f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5334:
	/* 0x5334: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5338:
	/* 0x5338: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_533d:
	/* 0x533d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_533f:
	/* 0x533f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5341:
	/* 0x5341: js     5c35 <generic_sleepable_preload+0x5c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23605ULL;
	}
x86_l_5347:
	/* 0x5347: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_534c:
	/* 0x534c: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_5354:
	/* 0x5354: je     5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23155ULL;
	}
x86_l_535a:
	/* 0x535a: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_5360:
	/* 0x5360: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5364:
	/* 0x5364: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5368:
	/* 0x5368: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_5370:
	/* 0x5370: je     5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23155ULL;
	}
x86_l_5376:
	/* 0x5376: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5379:
	/* 0x5379: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_537e:
	/* 0x537e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5383:
	/* 0x5383: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5387:
	/* 0x5387: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_538c:
	/* 0x538c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_538e:
	/* 0x538e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5390:
	/* 0x5390: jns    5a73 <generic_sleepable_preload+0x5a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 23155ULL;
	}
x86_l_5396:
	/* 0x5396: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_539c:
	/* 0x539c: jmp    5a70 <generic_sleepable_preload+0x5a70> */
	return 23152ULL;
x86_l_53a1:
	/* 0x53a1: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_53a7:
	/* 0x53a7: jmp    5a70 <generic_sleepable_preload+0x5a70> */
	return 23152ULL;
x86_l_53ac:
	/* 0x53ac: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_53b4:
	/* 0x53b4: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_53b7:
	/* 0x53b7: je     541a <generic_sleepable_preload+0x541a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_541a;
	}
x86_l_53b9:
	/* 0x53b9: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_53be:
	/* 0x53be: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_53c1:
	/* 0x53c1: je     541a <generic_sleepable_preload+0x541a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_541a;
	}
x86_l_53c3:
	/* 0x53c3: jmp    542d <generic_sleepable_preload+0x542d> */
	goto x86_l_542d;
x86_l_53c5:
	/* 0x53c5: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_53ca:
	/* 0x53ca: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_53cd:
	/* 0x53cd: je     541a <generic_sleepable_preload+0x541a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_541a;
	}
x86_l_53cf:
	/* 0x53cf: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_53d4:
	/* 0x53d4: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_53d7:
	/* 0x53d7: je     541a <generic_sleepable_preload+0x541a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_541a;
	}
x86_l_53d9:
	/* 0x53d9: jmp    542d <generic_sleepable_preload+0x542d> */
	goto x86_l_542d;
x86_l_53db:
	/* 0x53db: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_53e3:
	/* 0x53e3: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_53e6:
	/* 0x53e6: je     541a <generic_sleepable_preload+0x541a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_541a;
	}
x86_l_53e8:
	/* 0x53e8: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_53ed:
	/* 0x53ed: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_53f0:
	/* 0x53f0: je     541a <generic_sleepable_preload+0x541a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_541a;
	}
x86_l_53f2:
	/* 0x53f2: jmp    542d <generic_sleepable_preload+0x542d> */
	goto x86_l_542d;
x86_l_53f4:
	/* 0x53f4: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_53f9:
	/* 0x53f9: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_53fc:
	/* 0x53fc: je     541a <generic_sleepable_preload+0x541a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_541a;
	}
x86_l_53fe:
	/* 0x53fe: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5403:
	/* 0x5403: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_5406:
	/* 0x5406: je     541a <generic_sleepable_preload+0x541a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_541a;
	}
x86_l_5408:
	/* 0x5408: jmp    542d <generic_sleepable_preload+0x542d> */
	goto x86_l_542d;
x86_l_540a:
	/* 0x540a: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_5410:
	/* 0x5410: jmp    5a70 <generic_sleepable_preload+0x5a70> */
	return 23152ULL;
x86_l_5415:
	/* 0x5415: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_541a:
	/* 0x541a: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_541d:
	/* 0x541d: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_541f:
	/* 0x541f: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_5421:
	/* 0x5421: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_5426:
	/* 0x5426: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5428:
	/* 0x5428: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_542d:
	/* 0x542d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5431:
	/* 0x5431: mov    ebx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5436:
	/* 0x5436: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_5439:
	/* 0x5439: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_543c:
	/* 0x543c: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_543f:
	/* 0x543f: cmp    WORD PTR [rsi+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_5447:
	/* 0x5447: je     5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23295ULL;
	}
x86_l_544d:
	/* 0x544d: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_5454:
	/* 0x5454: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_5457:
	/* 0x5457: mov    eax,DWORD PTR [rsi+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_545d:
	/* 0x545d: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5460:
	/* 0x5460: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5464:
	/* 0x5464: movzx  eax,WORD PTR [rsi+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_546b:
	/* 0x546b: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_546d:
	/* 0x546d: je     5731 <generic_sleepable_preload+0x5731> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5731;
	}
x86_l_5473:
	/* 0x5473: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_5476:
	/* 0x5476: je     5498 <generic_sleepable_preload+0x5498> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5498;
	}
x86_l_5478:
	/* 0x5478: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_547b:
	/* 0x547b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5480:
	/* 0x5480: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5485:
	/* 0x5485: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5489:
	/* 0x5489: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_548e:
	/* 0x548e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5490:
	/* 0x5490: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5492:
	/* 0x5492: js     5a08 <generic_sleepable_preload+0x5a08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23048ULL;
	}
x86_l_5498:
	/* 0x5498: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_549d:
	/* 0x549d: cmp    WORD PTR [rax+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_54a5:
	/* 0x54a5: je     5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23295ULL;
	}
x86_l_54ab:
	/* 0x54ab: mov    ecx,DWORD PTR [rax+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_54b1:
	/* 0x54b1: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_54b5:
	/* 0x54b5: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54b9:
	/* 0x54b9: cmp    WORD PTR [rax+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_54c1:
	/* 0x54c1: je     54e3 <generic_sleepable_preload+0x54e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54e3;
	}
x86_l_54c3:
	/* 0x54c3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_54c6:
	/* 0x54c6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_54cb:
	/* 0x54cb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_54d0:
	/* 0x54d0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54d4:
	/* 0x54d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54d9:
	/* 0x54d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54db:
	/* 0x54db: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_54dd:
	/* 0x54dd: js     5a13 <generic_sleepable_preload+0x5a13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23059ULL;
	}
x86_l_54e3:
	/* 0x54e3: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54e8:
	/* 0x54e8: cmp    WORD PTR [rax+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_54f0:
	/* 0x54f0: je     5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23295ULL;
	}
x86_l_54f6:
	/* 0x54f6: mov    ecx,DWORD PTR [rax+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_54fc:
	/* 0x54fc: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5500:
	/* 0x5500: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5504:
	/* 0x5504: cmp    WORD PTR [rax+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_550c:
	/* 0x550c: je     552e <generic_sleepable_preload+0x552e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_552e;
	}
x86_l_550e:
	/* 0x550e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5511:
	/* 0x5511: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5516:
	/* 0x5516: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_551b:
	/* 0x551b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_551f:
	/* 0x551f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5524:
	/* 0x5524: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5526:
	/* 0x5526: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5528:
	/* 0x5528: js     5a26 <generic_sleepable_preload+0x5a26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23078ULL;
	}
x86_l_552e:
	/* 0x552e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5533:
	/* 0x5533: cmp    WORD PTR [rax+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_553b:
	/* 0x553b: je     5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23295ULL;
	}
x86_l_5541:
	/* 0x5541: mov    ecx,DWORD PTR [rax+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_5547:
	/* 0x5547: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_554b:
	/* 0x554b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_554f:
	/* 0x554f: cmp    WORD PTR [rax+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_5557:
	/* 0x5557: je     5579 <generic_sleepable_preload+0x5579> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5579;
	}
x86_l_5559:
	/* 0x5559: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_555c:
	/* 0x555c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5561:
	/* 0x5561: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5566:
	/* 0x5566: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_556a:
	/* 0x556a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_556f:
	/* 0x556f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5571:
	/* 0x5571: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5573:
	/* 0x5573: js     5a39 <generic_sleepable_preload+0x5a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23097ULL;
	}
x86_l_5579:
	/* 0x5579: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_557e:
	/* 0x557e: cmp    WORD PTR [rax+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_5586:
	/* 0x5586: je     5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23295ULL;
	}
x86_l_558c:
	/* 0x558c: mov    ecx,DWORD PTR [rax+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_5592:
	/* 0x5592: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5596:
	/* 0x5596: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_559a:
	/* 0x559a: cmp    WORD PTR [rax+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_55a2:
	/* 0x55a2: je     55c4 <generic_sleepable_preload+0x55c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_55c4;
	}
x86_l_55a4:
	/* 0x55a4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_55a7:
	/* 0x55a7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_55ac:
	/* 0x55ac: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_55b1:
	/* 0x55b1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55b5:
	/* 0x55b5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55ba:
	/* 0x55ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55bc:
	/* 0x55bc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_55be:
	/* 0x55be: js     5a4c <generic_sleepable_preload+0x5a4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23116ULL;
	}
x86_l_55c4:
	/* 0x55c4: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55c9:
	/* 0x55c9: cmp    WORD PTR [rax+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_55d1:
	/* 0x55d1: je     5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23295ULL;
	}
x86_l_55d7:
	/* 0x55d7: mov    ecx,DWORD PTR [rax+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_55dd:
	/* 0x55dd: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_55e1:
	/* 0x55e1: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55e5:
	/* 0x55e5: cmp    WORD PTR [rax+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_55ed:
	/* 0x55ed: je     560f <generic_sleepable_preload+0x560f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_560f;
	}
x86_l_55ef:
	/* 0x55ef: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_55f2:
	/* 0x55f2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_55f7:
	/* 0x55f7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_55fc:
	/* 0x55fc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5600:
	/* 0x5600: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5605:
	/* 0x5605: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5607:
	/* 0x5607: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5609:
	/* 0x5609: js     5a5f <generic_sleepable_preload+0x5a5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23135ULL;
	}
x86_l_560f:
	/* 0x560f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5614:
	/* 0x5614: cmp    WORD PTR [rax+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_561c:
	/* 0x561c: je     5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23295ULL;
	}
x86_l_5622:
	/* 0x5622: mov    ecx,DWORD PTR [rax+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_5628:
	/* 0x5628: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_562c:
	/* 0x562c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5630:
	/* 0x5630: cmp    WORD PTR [rax+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_5638:
	/* 0x5638: je     565a <generic_sleepable_preload+0x565a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_565a;
	}
x86_l_563a:
	/* 0x563a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_563d:
	/* 0x563d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5642:
	/* 0x5642: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5647:
	/* 0x5647: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_564b:
	/* 0x564b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5650:
	/* 0x5650: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5652:
	/* 0x5652: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5654:
	/* 0x5654: js     5af6 <generic_sleepable_preload+0x5af6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23286ULL;
	}
x86_l_565a:
	/* 0x565a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_565f:
	/* 0x565f: cmp    WORD PTR [rax+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_5667:
	/* 0x5667: je     5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23295ULL;
	}
x86_l_566d:
	/* 0x566d: mov    ecx,DWORD PTR [rax+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_5673:
	/* 0x5673: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5677:
	/* 0x5677: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_567b:
	/* 0x567b: cmp    WORD PTR [rax+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_5683:
	/* 0x5683: je     56a5 <generic_sleepable_preload+0x56a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56a5;
	}
x86_l_5685:
	/* 0x5685: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5688:
	/* 0x5688: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_568d:
	/* 0x568d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5692:
	/* 0x5692: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5696:
	/* 0x5696: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_569b:
	/* 0x569b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_569d:
	/* 0x569d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_569f:
	/* 0x569f: js     5bb6 <generic_sleepable_preload+0x5bb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23478ULL;
	}
x86_l_56a5:
	/* 0x56a5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56aa:
	/* 0x56aa: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_56b2:
	/* 0x56b2: je     5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23295ULL;
	}
x86_l_56b8:
	/* 0x56b8: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_56be:
	/* 0x56be: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_56c2:
	/* 0x56c2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56c6:
	/* 0x56c6: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_56ce:
	/* 0x56ce: je     56f0 <generic_sleepable_preload+0x56f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56f0;
	}
x86_l_56d0:
	/* 0x56d0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_56d3:
	/* 0x56d3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_56d8:
	/* 0x56d8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_56dd:
	/* 0x56dd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56e1:
	/* 0x56e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56e6:
	/* 0x56e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56e8:
	/* 0x56e8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56ea:
	/* 0x56ea: js     5c40 <generic_sleepable_preload+0x5c40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23616ULL;
	}
x86_l_56f0:
	/* 0x56f0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56f5:
	/* 0x56f5: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_56fd:
	/* 0x56fd: je     5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23295ULL;
	}
x86_l_5703:
	/* 0x5703: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_5709:
	/* 0x5709: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_570d:
	/* 0x570d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5711:
	/* 0x5711: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_5719:
	/* 0x5719: je     5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23295ULL;
	}
x86_l_571f:
	/* 0x571f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5722:
	/* 0x5722: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5727:
	/* 0x5727: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_572c:
	/* 0x572c: jmp    59ea <generic_sleepable_preload+0x59ea> */
	return 23018ULL;
x86_l_5731:
	/* 0x5731: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_5734:
	/* 0x5734: je     5756 <generic_sleepable_preload+0x5756> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5756;
	}
x86_l_5736:
	/* 0x5736: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5739:
	/* 0x5739: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_573e:
	/* 0x573e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5743:
	/* 0x5743: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5747:
	/* 0x5747: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_574c:
	/* 0x574c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_574e:
	/* 0x574e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5750:
	/* 0x5750: js     5a08 <generic_sleepable_preload+0x5a08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23048ULL;
	}
x86_l_5756:
	/* 0x5756: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_575b:
	/* 0x575b: cmp    WORD PTR [rax+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_5763:
	/* 0x5763: je     5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23295ULL;
	}
x86_l_5769:
	/* 0x5769: mov    ecx,DWORD PTR [rax+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_576f:
	/* 0x576f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5773:
	/* 0x5773: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5777:
	/* 0x5777: cmp    WORD PTR [rax+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_577f:
	/* 0x577f: je     57a1 <generic_sleepable_preload+0x57a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_57a1;
	}
x86_l_5781:
	/* 0x5781: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5784:
	/* 0x5784: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5789:
	/* 0x5789: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_578e:
	/* 0x578e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5792:
	/* 0x5792: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5797:
	/* 0x5797: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5799:
	/* 0x5799: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_579b:
	/* 0x579b: js     5a13 <generic_sleepable_preload+0x5a13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23059ULL;
	}
x86_l_57a1:
	/* 0x57a1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57a6:
	/* 0x57a6: cmp    WORD PTR [rax+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_57ae:
	/* 0x57ae: je     5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23295ULL;
	}
x86_l_57b4:
	/* 0x57b4: mov    ecx,DWORD PTR [rax+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_57ba:
	/* 0x57ba: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_57be:
	/* 0x57be: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57c2:
	/* 0x57c2: cmp    WORD PTR [rax+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_57ca:
	/* 0x57ca: je     57ec <generic_sleepable_preload+0x57ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_57ec;
	}
x86_l_57cc:
	/* 0x57cc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_57cf:
	/* 0x57cf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_57d4:
	/* 0x57d4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_57d9:
	/* 0x57d9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57dd:
	/* 0x57dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57e2:
	/* 0x57e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57e4:
	/* 0x57e4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_57e6:
	/* 0x57e6: js     5a26 <generic_sleepable_preload+0x5a26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23078ULL;
	}
x86_l_57ec:
	/* 0x57ec: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57f1:
	/* 0x57f1: cmp    WORD PTR [rax+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_57f9:
	/* 0x57f9: je     5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23295ULL;
	}
x86_l_57ff:
	/* 0x57ff: mov    ecx,DWORD PTR [rax+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_5805:
	/* 0x5805: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5809:
	/* 0x5809: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_580d:
	/* 0x580d: cmp    WORD PTR [rax+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_5815:
	/* 0x5815: je     5837 <generic_sleepable_preload+0x5837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5837;
	}
x86_l_5817:
	/* 0x5817: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_581a:
	/* 0x581a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_581f:
	/* 0x581f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5824:
	/* 0x5824: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5828:
	/* 0x5828: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_582d:
	/* 0x582d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_582f:
	/* 0x582f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5831:
	/* 0x5831: js     5a39 <generic_sleepable_preload+0x5a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23097ULL;
	}
x86_l_5837:
	/* 0x5837: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_583c:
	/* 0x583c: cmp    WORD PTR [rax+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_5844:
	/* 0x5844: je     5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23295ULL;
	}
x86_l_584a:
	/* 0x584a: mov    ecx,DWORD PTR [rax+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_5850:
	/* 0x5850: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5854:
	/* 0x5854: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5858:
	/* 0x5858: cmp    WORD PTR [rax+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_5860:
	/* 0x5860: je     5882 <generic_sleepable_preload+0x5882> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5882;
	}
x86_l_5862:
	/* 0x5862: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5865:
	/* 0x5865: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_586a:
	/* 0x586a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_586f:
	/* 0x586f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5873:
	/* 0x5873: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5878:
	/* 0x5878: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_587a:
	/* 0x587a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_587c:
	/* 0x587c: js     5a4c <generic_sleepable_preload+0x5a4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23116ULL;
	}
x86_l_5882:
	/* 0x5882: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5887:
	/* 0x5887: cmp    WORD PTR [rax+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_588f:
	/* 0x588f: je     5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23295ULL;
	}
x86_l_5895:
	/* 0x5895: mov    ecx,DWORD PTR [rax+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_589b:
	/* 0x589b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_589f:
	/* 0x589f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58a3:
	/* 0x58a3: cmp    WORD PTR [rax+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_58ab:
	/* 0x58ab: je     58cd <generic_sleepable_preload+0x58cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58cd;
	}
x86_l_58ad:
	/* 0x58ad: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_58b0:
	/* 0x58b0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_58b5:
	/* 0x58b5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_58ba:
	/* 0x58ba: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58be:
	/* 0x58be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58c3:
	/* 0x58c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58c5:
	/* 0x58c5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_58c7:
	/* 0x58c7: js     5a5f <generic_sleepable_preload+0x5a5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23135ULL;
	}
x86_l_58cd:
	/* 0x58cd: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58d2:
	/* 0x58d2: cmp    WORD PTR [rax+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_58da:
	/* 0x58da: je     5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23295ULL;
	}
x86_l_58e0:
	/* 0x58e0: mov    ecx,DWORD PTR [rax+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_58e6:
	/* 0x58e6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_58ea:
	/* 0x58ea: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58ee:
	/* 0x58ee: cmp    WORD PTR [rax+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_58f6:
	/* 0x58f6: je     5918 <generic_sleepable_preload+0x5918> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5918;
	}
x86_l_58f8:
	/* 0x58f8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_58fb:
	/* 0x58fb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5900:
	/* 0x5900: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5905:
	/* 0x5905: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5909:
	/* 0x5909: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_590e:
	/* 0x590e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5910:
	/* 0x5910: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5912:
	/* 0x5912: js     5af6 <generic_sleepable_preload+0x5af6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23286ULL;
	}
x86_l_5918:
	/* 0x5918: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_591d:
	/* 0x591d: cmp    WORD PTR [rax+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_5925:
	/* 0x5925: je     5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23295ULL;
	}
x86_l_592b:
	/* 0x592b: mov    ecx,DWORD PTR [rax+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_5931:
	/* 0x5931: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5935:
	/* 0x5935: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5939:
	/* 0x5939: cmp    WORD PTR [rax+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_5941:
	/* 0x5941: je     5963 <generic_sleepable_preload+0x5963> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5963;
	}
x86_l_5943:
	/* 0x5943: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5946:
	/* 0x5946: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_594b:
	/* 0x594b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5950:
	/* 0x5950: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5954:
	/* 0x5954: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5959:
	/* 0x5959: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_595b:
	/* 0x595b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_595d:
	/* 0x595d: js     5bb6 <generic_sleepable_preload+0x5bb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23478ULL;
	}
x86_l_5963:
	/* 0x5963: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5968:
	/* 0x5968: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_5970:
	/* 0x5970: je     5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23295ULL;
	}
x86_l_5976:
	/* 0x5976: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_597c:
	/* 0x597c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5980:
	/* 0x5980: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5984:
	/* 0x5984: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_598c:
	/* 0x598c: je     59ae <generic_sleepable_preload+0x59ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22958ULL;
	}
x86_l_598e:
	/* 0x598e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5991:
	/* 0x5991: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5996:
	/* 0x5996: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_599b:
	/* 0x599b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_599f:
	/* 0x599f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59a4:
	/* 0x59a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59a6:
	/* 0x59a6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
	return 22952ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 22952ULL: goto x86_l_59a8;
	case 22958ULL: goto x86_l_59ae;
	case 22963ULL: goto x86_l_59b3;
	case 22971ULL: goto x86_l_59bb;
	case 22977ULL: goto x86_l_59c1;
	case 22983ULL: goto x86_l_59c7;
	case 22987ULL: goto x86_l_59cb;
	case 22991ULL: goto x86_l_59cf;
	case 22999ULL: goto x86_l_59d7;
	case 23005ULL: goto x86_l_59dd;
	case 23008ULL: goto x86_l_59e0;
	case 23013ULL: goto x86_l_59e5;
	case 23018ULL: goto x86_l_59ea;
	case 23022ULL: goto x86_l_59ee;
	case 23027ULL: goto x86_l_59f3;
	case 23029ULL: goto x86_l_59f5;
	case 23031ULL: goto x86_l_59f7;
	case 23037ULL: goto x86_l_59fd;
	case 23043ULL: goto x86_l_5a03;
	case 23048ULL: goto x86_l_5a08;
	case 23054ULL: goto x86_l_5a0e;
	case 23059ULL: goto x86_l_5a13;
	case 23065ULL: goto x86_l_5a19;
	case 23070ULL: goto x86_l_5a1e;
	case 23076ULL: goto x86_l_5a24;
	case 23078ULL: goto x86_l_5a26;
	case 23084ULL: goto x86_l_5a2c;
	case 23089ULL: goto x86_l_5a31;
	case 23095ULL: goto x86_l_5a37;
	case 23097ULL: goto x86_l_5a39;
	case 23103ULL: goto x86_l_5a3f;
	case 23108ULL: goto x86_l_5a44;
	case 23114ULL: goto x86_l_5a4a;
	case 23116ULL: goto x86_l_5a4c;
	case 23122ULL: goto x86_l_5a52;
	case 23127ULL: goto x86_l_5a57;
	case 23133ULL: goto x86_l_5a5d;
	case 23135ULL: goto x86_l_5a5f;
	case 23141ULL: goto x86_l_5a65;
	case 23146ULL: goto x86_l_5a6a;
	case 23152ULL: goto x86_l_5a70;
	case 23155ULL: goto x86_l_5a73;
	case 23160ULL: goto x86_l_5a78;
	case 23163ULL: goto x86_l_5a7b;
	case 23166ULL: goto x86_l_5a7e;
	case 23171ULL: goto x86_l_5a83;
	case 23176ULL: goto x86_l_5a88;
	case 23181ULL: goto x86_l_5a8d;
	case 23184ULL: goto x86_l_5a90;
	case 23186ULL: goto x86_l_5a92;
	case 23189ULL: goto x86_l_5a95;
	case 23195ULL: goto x86_l_5a9b;
	case 23199ULL: goto x86_l_5a9f;
	case 23204ULL: goto x86_l_5aa4;
	case 23206ULL: goto x86_l_5aa6;
	case 23211ULL: goto x86_l_5aab;
	case 23219ULL: goto x86_l_5ab3;
	case 23226ULL: goto x86_l_5aba;
	case 23231ULL: goto x86_l_5abf;
	case 23236ULL: goto x86_l_5ac4;
	case 23238ULL: goto x86_l_5ac6;
	case 23241ULL: goto x86_l_5ac9;
	case 23247ULL: goto x86_l_5acf;
	case 23250ULL: goto x86_l_5ad2;
	case 23257ULL: goto x86_l_5ad9;
	case 23259ULL: goto x86_l_5adb;
	case 23264ULL: goto x86_l_5ae0;
	case 23269ULL: goto x86_l_5ae5;
	case 23272ULL: goto x86_l_5ae8;
	case 23275ULL: goto x86_l_5aeb;
	case 23277ULL: goto x86_l_5aed;
	case 23279ULL: goto x86_l_5aef;
	case 23284ULL: goto x86_l_5af4;
	case 23286ULL: goto x86_l_5af6;
	case 23292ULL: goto x86_l_5afc;
	case 23295ULL: goto x86_l_5aff;
	case 23298ULL: goto x86_l_5b02;
	case 23304ULL: goto x86_l_5b08;
	case 23308ULL: goto x86_l_5b0c;
	case 23313ULL: goto x86_l_5b11;
	case 23315ULL: goto x86_l_5b13;
	case 23320ULL: goto x86_l_5b18;
	case 23328ULL: goto x86_l_5b20;
	case 23335ULL: goto x86_l_5b27;
	case 23340ULL: goto x86_l_5b2c;
	case 23345ULL: goto x86_l_5b31;
	case 23347ULL: goto x86_l_5b33;
	case 23350ULL: goto x86_l_5b36;
	case 23356ULL: goto x86_l_5b3c;
	case 23359ULL: goto x86_l_5b3f;
	case 23366ULL: goto x86_l_5b46;
	case 23368ULL: goto x86_l_5b48;
	case 23373ULL: goto x86_l_5b4d;
	case 23378ULL: goto x86_l_5b52;
	case 23381ULL: goto x86_l_5b55;
	case 23384ULL: goto x86_l_5b58;
	case 23386ULL: goto x86_l_5b5a;
	case 23388ULL: goto x86_l_5b5c;
	case 23393ULL: goto x86_l_5b61;
	case 23396ULL: goto x86_l_5b64;
	case 23399ULL: goto x86_l_5b67;
	case 23401ULL: goto x86_l_5b69;
	case 23404ULL: goto x86_l_5b6c;
	case 23410ULL: goto x86_l_5b72;
	case 23413ULL: goto x86_l_5b75;
	case 23415ULL: goto x86_l_5b77;
	case 23418ULL: goto x86_l_5b7a;
	case 23422ULL: goto x86_l_5b7e;
	case 23427ULL: goto x86_l_5b83;
	case 23430ULL: goto x86_l_5b86;
	case 23432ULL: goto x86_l_5b88;
	case 23435ULL: goto x86_l_5b8b;
	case 23440ULL: goto x86_l_5b90;
	case 23442ULL: goto x86_l_5b92;
	case 23445ULL: goto x86_l_5b95;
	case 23447ULL: goto x86_l_5b97;
	case 23452ULL: goto x86_l_5b9c;
	case 23456ULL: goto x86_l_5ba0;
	case 23459ULL: goto x86_l_5ba3;
	case 23464ULL: goto x86_l_5ba8;
	case 23467ULL: goto x86_l_5bab;
	case 23473ULL: goto x86_l_5bb1;
	case 23478ULL: goto x86_l_5bb6;
	case 23481ULL: goto x86_l_5bb9;
	case 23487ULL: goto x86_l_5bbf;
	case 23490ULL: goto x86_l_5bc2;
	case 23496ULL: goto x86_l_5bc8;
	case 23501ULL: goto x86_l_5bcd;
	case 23504ULL: goto x86_l_5bd0;
	case 23509ULL: goto x86_l_5bd5;
	case 23514ULL: goto x86_l_5bda;
	case 23517ULL: goto x86_l_5bdd;
	case 23522ULL: goto x86_l_5be2;
	case 23527ULL: goto x86_l_5be7;
	case 23530ULL: goto x86_l_5bea;
	case 23535ULL: goto x86_l_5bef;
	case 23540ULL: goto x86_l_5bf4;
	case 23543ULL: goto x86_l_5bf7;
	case 23548ULL: goto x86_l_5bfc;
	case 23553ULL: goto x86_l_5c01;
	case 23556ULL: goto x86_l_5c04;
	case 23561ULL: goto x86_l_5c09;
	case 23566ULL: goto x86_l_5c0e;
	case 23569ULL: goto x86_l_5c11;
	case 23574ULL: goto x86_l_5c16;
	case 23579ULL: goto x86_l_5c1b;
	case 23582ULL: goto x86_l_5c1e;
	case 23587ULL: goto x86_l_5c23;
	case 23592ULL: goto x86_l_5c28;
	case 23595ULL: goto x86_l_5c2b;
	case 23600ULL: goto x86_l_5c30;
	case 23605ULL: goto x86_l_5c35;
	case 23611ULL: goto x86_l_5c3b;
	case 23616ULL: goto x86_l_5c40;
	case 23622ULL: goto x86_l_5c46;
	case 23627ULL: goto x86_l_5c4b;
	case 23630ULL: goto x86_l_5c4e;
	case 23635ULL: goto x86_l_5c53;
	case 23640ULL: goto x86_l_5c58;
	case 23643ULL: goto x86_l_5c5b;
	case 23648ULL: goto x86_l_5c60;
	case 23653ULL: goto x86_l_5c65;
	case 23656ULL: goto x86_l_5c68;
	case 23661ULL: goto x86_l_5c6d;
	case 23666ULL: goto x86_l_5c72;
	case 23669ULL: goto x86_l_5c75;
	case 23674ULL: goto x86_l_5c7a;
	case 23679ULL: goto x86_l_5c7f;
	case 23682ULL: goto x86_l_5c82;
	case 23687ULL: goto x86_l_5c87;
	case 23692ULL: goto x86_l_5c8c;
	case 23695ULL: goto x86_l_5c8f;
	case 23700ULL: goto x86_l_5c94;
	case 23705ULL: goto x86_l_5c99;
	case 23708ULL: goto x86_l_5c9c;
	case 23713ULL: goto x86_l_5ca1;
	case 23718ULL: goto x86_l_5ca6;
	case 23721ULL: goto x86_l_5ca9;
	case 23726ULL: goto x86_l_5cae;
	case 23731ULL: goto x86_l_5cb3;
	case 23736ULL: goto x86_l_5cb8;
	case 23739ULL: goto x86_l_5cbb;
	case 23744ULL: goto x86_l_5cc0;
	case 23749ULL: goto x86_l_5cc5;
	case 23754ULL: goto x86_l_5cca;
	case 23757ULL: goto x86_l_5ccd;
	case 23762ULL: goto x86_l_5cd2;
	case 23767ULL: goto x86_l_5cd7;
	case 23772ULL: goto x86_l_5cdc;
	case 23775ULL: goto x86_l_5cdf;
	case 23780ULL: goto x86_l_5ce4;
	case 23785ULL: goto x86_l_5ce9;
	case 23790ULL: goto x86_l_5cee;
	case 23793ULL: goto x86_l_5cf1;
	case 23798ULL: goto x86_l_5cf6;
	case 23803ULL: goto x86_l_5cfb;
	case 23808ULL: goto x86_l_5d00;
	case 23811ULL: goto x86_l_5d03;
	case 23816ULL: goto x86_l_5d08;
	case 23821ULL: goto x86_l_5d0d;
	case 23826ULL: goto x86_l_5d12;
	case 23829ULL: goto x86_l_5d15;
	case 23834ULL: goto x86_l_5d1a;
	case 23839ULL: goto x86_l_5d1f;
	case 23844ULL: goto x86_l_5d24;
	case 23847ULL: goto x86_l_5d27;
	case 23852ULL: goto x86_l_5d2c;
	case 23857ULL: goto x86_l_5d31;
	case 23862ULL: goto x86_l_5d36;
	case 23865ULL: goto x86_l_5d39;
	case 23870ULL: goto x86_l_5d3e;
	case 23875ULL: goto x86_l_5d43;
	case 23880ULL: goto x86_l_5d48;
	case 23883ULL: goto x86_l_5d4b;
	case 23888ULL: goto x86_l_5d50;
	case 23891ULL: goto x86_l_5d53;
	case 23896ULL: goto x86_l_5d58;
	case 23901ULL: goto x86_l_5d5d;
	case 23904ULL: goto x86_l_5d60;
	case 23909ULL: goto x86_l_5d65;
	case 23912ULL: goto x86_l_5d68;
	case 23917ULL: goto x86_l_5d6d;
	case 23922ULL: goto x86_l_5d72;
	case 23925ULL: goto x86_l_5d75;
	case 23930ULL: goto x86_l_5d7a;
	case 23933ULL: goto x86_l_5d7d;
	case 23938ULL: goto x86_l_5d82;
	case 23943ULL: goto x86_l_5d87;
	case 23946ULL: goto x86_l_5d8a;
	case 23951ULL: goto x86_l_5d8f;
	case 23954ULL: goto x86_l_5d92;
	case 23959ULL: goto x86_l_5d97;
	case 23964ULL: goto x86_l_5d9c;
	case 23967ULL: goto x86_l_5d9f;
	case 23972ULL: goto x86_l_5da4;
	case 23975ULL: goto x86_l_5da7;
	case 23980ULL: goto x86_l_5dac;
	case 23985ULL: goto x86_l_5db1;
	case 23988ULL: goto x86_l_5db4;
	case 23993ULL: goto x86_l_5db9;
	case 23996ULL: goto x86_l_5dbc;
	case 24001ULL: goto x86_l_5dc1;
	case 24006ULL: goto x86_l_5dc6;
	case 24009ULL: goto x86_l_5dc9;
	case 24014ULL: goto x86_l_5dce;
	case 24017ULL: goto x86_l_5dd1;
	case 24022ULL: goto x86_l_5dd6;
	case 24027ULL: goto x86_l_5ddb;
	case 24030ULL: goto x86_l_5dde;
	case 24035ULL: goto x86_l_5de3;
	case 24038ULL: goto x86_l_5de6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_59a8:
	/* 0x59a8: js     5c40 <generic_sleepable_preload+0x5c40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_5c40;
	}
x86_l_59ae:
	/* 0x59ae: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59b3:
	/* 0x59b3: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_59bb:
	/* 0x59bb: je     5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5aff;
	}
x86_l_59c1:
	/* 0x59c1: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_59c7:
	/* 0x59c7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_59cb:
	/* 0x59cb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59cf:
	/* 0x59cf: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_59d7:
	/* 0x59d7: je     5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5aff;
	}
x86_l_59dd:
	/* 0x59dd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_59e0:
	/* 0x59e0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_59e5:
	/* 0x59e5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_59ea:
	/* 0x59ea: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59ee:
	/* 0x59ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59f3:
	/* 0x59f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59f5:
	/* 0x59f5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_59f7:
	/* 0x59f7: jns    5aff <generic_sleepable_preload+0x5aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_5aff;
	}
x86_l_59fd:
	/* 0x59fd: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_5a03:
	/* 0x5a03: jmp    5afc <generic_sleepable_preload+0x5afc> */
	goto x86_l_5afc;
x86_l_5a08:
	/* 0x5a08: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_5a0e:
	/* 0x5a0e: jmp    5afc <generic_sleepable_preload+0x5afc> */
	goto x86_l_5afc;
x86_l_5a13:
	/* 0x5a13: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_5a19:
	/* 0x5a19: jmp    5afc <generic_sleepable_preload+0x5afc> */
	goto x86_l_5afc;
x86_l_5a1e:
	/* 0x5a1e: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_5a24:
	/* 0x5a24: jmp    5a70 <generic_sleepable_preload+0x5a70> */
	goto x86_l_5a70;
x86_l_5a26:
	/* 0x5a26: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_5a2c:
	/* 0x5a2c: jmp    5afc <generic_sleepable_preload+0x5afc> */
	goto x86_l_5afc;
x86_l_5a31:
	/* 0x5a31: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_5a37:
	/* 0x5a37: jmp    5a70 <generic_sleepable_preload+0x5a70> */
	goto x86_l_5a70;
x86_l_5a39:
	/* 0x5a39: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_5a3f:
	/* 0x5a3f: jmp    5afc <generic_sleepable_preload+0x5afc> */
	goto x86_l_5afc;
x86_l_5a44:
	/* 0x5a44: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_5a4a:
	/* 0x5a4a: jmp    5a70 <generic_sleepable_preload+0x5a70> */
	goto x86_l_5a70;
x86_l_5a4c:
	/* 0x5a4c: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_5a52:
	/* 0x5a52: jmp    5afc <generic_sleepable_preload+0x5afc> */
	goto x86_l_5afc;
x86_l_5a57:
	/* 0x5a57: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_5a5d:
	/* 0x5a5d: jmp    5a70 <generic_sleepable_preload+0x5a70> */
	goto x86_l_5a70;
x86_l_5a5f:
	/* 0x5a5f: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_5a65:
	/* 0x5a65: jmp    5afc <generic_sleepable_preload+0x5afc> */
	goto x86_l_5afc;
x86_l_5a6a:
	/* 0x5a6a: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_5a70:
	/* 0x5a70: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5a73:
	/* 0x5a73: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a78:
	/* 0x5a78: mov    ebx,DWORD PTR [rax+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5a7b:
	/* 0x5a7b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5a7e:
	/* 0x5a7e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5a83:
	/* 0x5a83: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5a88:
	/* 0x5a88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a8d:
	/* 0x5a8d: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_5a90:
	/* 0x5a90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a92:
	/* 0x5a92: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_5a95:
	/* 0x5a95: jne    4c77 <generic_sleepable_preload+0x4c77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19575ULL;
	}
x86_l_5a9b:
	/* 0x5a9b: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a9f:
	/* 0x5a9f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5aa4:
	/* 0x5aa4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5aa6:
	/* 0x5aa6: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5aab:
	/* 0x5aab: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_5ab3:
	/* 0x5ab3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5aba:
	/* 0x5aba: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5abf:
	/* 0x5abf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5ac4:
	/* 0x5ac4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ac6:
	/* 0x5ac6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5ac9:
	/* 0x5ac9: je     4c77 <generic_sleepable_preload+0x4c77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19575ULL;
	}
x86_l_5acf:
	/* 0x5acf: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5ad2:
	/* 0x5ad2: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_5ad9:
	/* 0x5ad9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5adb:
	/* 0x5adb: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ae0:
	/* 0x5ae0: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5ae5:
	/* 0x5ae5: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5ae8:
	/* 0x5ae8: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5aeb:
	/* 0x5aeb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5aed:
	/* 0x5aed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5aef:
	/* 0x5aef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5af4:
	/* 0x5af4: jmp    5b61 <generic_sleepable_preload+0x5b61> */
	goto x86_l_5b61;
x86_l_5af6:
	/* 0x5af6: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_5afc:
	/* 0x5afc: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5aff:
	/* 0x5aff: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_5b02:
	/* 0x5b02: jne    4c77 <generic_sleepable_preload+0x4c77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19575ULL;
	}
x86_l_5b08:
	/* 0x5b08: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b0c:
	/* 0x5b0c: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5b11:
	/* 0x5b11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b13:
	/* 0x5b13: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b18:
	/* 0x5b18: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_5b20:
	/* 0x5b20: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5b27:
	/* 0x5b27: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5b2c:
	/* 0x5b2c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5b31:
	/* 0x5b31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b33:
	/* 0x5b33: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b36:
	/* 0x5b36: je     4c77 <generic_sleepable_preload+0x4c77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19575ULL;
	}
x86_l_5b3c:
	/* 0x5b3c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5b3f:
	/* 0x5b3f: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_5b46:
	/* 0x5b46: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b48:
	/* 0x5b48: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b4d:
	/* 0x5b4d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5b52:
	/* 0x5b52: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5b55:
	/* 0x5b55: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5b58:
	/* 0x5b58: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b5a:
	/* 0x5b5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b5c:
	/* 0x5b5c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5b61:
	/* 0x5b61: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5b64:
	/* 0x5b64: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5b67:
	/* 0x5b67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b69:
	/* 0x5b69: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b6c:
	/* 0x5b6c: je     4c77 <generic_sleepable_preload+0x4c77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19575ULL;
	}
x86_l_5b72:
	/* 0x5b72: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_5b75:
	/* 0x5b75: je     5ba0 <generic_sleepable_preload+0x5ba0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ba0;
	}
x86_l_5b77:
	/* 0x5b77: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_5b7a:
	/* 0x5b7a: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_5b7e:
	/* 0x5b7e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5b83:
	/* 0x5b83: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_5b86:
	/* 0x5b86: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b88:
	/* 0x5b88: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_5b8b:
	/* 0x5b8b: call   5b90 <generic_sleepable_preload+0x5b90> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_5b90:
	/* 0x5b90: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_5b92:
	/* 0x5b92: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_5b95:
	/* 0x5b95: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_5b97:
	/* 0x5b97: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_5b9c:
	/* 0x5b9c: cmovs  r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_5ba0:
	/* 0x5ba0: mov    DWORD PTR [rax],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ba3:
	/* 0x5ba3: jmp    4c77 <generic_sleepable_preload+0x4c77> */
	return 19575ULL;
x86_l_5ba8:
	/* 0x5ba8: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bab:
	/* 0x5bab: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_5bb1:
	/* 0x5bb1: jmp    5a73 <generic_sleepable_preload+0x5a73> */
	goto x86_l_5a73;
x86_l_5bb6:
	/* 0x5bb6: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bb9:
	/* 0x5bb9: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_5bbf:
	/* 0x5bbf: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_5bc2:
	/* 0x5bc2: jne    4c77 <generic_sleepable_preload+0x4c77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19575ULL;
	}
x86_l_5bc8:
	/* 0x5bc8: jmp    5b08 <generic_sleepable_preload+0x5b08> */
	goto x86_l_5b08;
x86_l_5bcd:
	/* 0x5bcd: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bd0:
	/* 0x5bd0: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5bd5:
	/* 0x5bd5: jmp    1cfb <generic_sleepable_preload+0x1cfb> */
	return 7419ULL;
x86_l_5bda:
	/* 0x5bda: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bdd:
	/* 0x5bdd: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5be2:
	/* 0x5be2: jmp    1d86 <generic_sleepable_preload+0x1d86> */
	return 7558ULL;
x86_l_5be7:
	/* 0x5be7: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bea:
	/* 0x5bea: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5bef:
	/* 0x5bef: jmp    2c65 <generic_sleepable_preload+0x2c65> */
	return 11365ULL;
x86_l_5bf4:
	/* 0x5bf4: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bf7:
	/* 0x5bf7: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5bfc:
	/* 0x5bfc: jmp    2cf0 <generic_sleepable_preload+0x2cf0> */
	return 11504ULL;
x86_l_5c01:
	/* 0x5c01: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c04:
	/* 0x5c04: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c09:
	/* 0x5c09: jmp    3bd0 <generic_sleepable_preload+0x3bd0> */
	return 15312ULL;
x86_l_5c0e:
	/* 0x5c0e: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c11:
	/* 0x5c11: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c16:
	/* 0x5c16: jmp    3c5b <generic_sleepable_preload+0x3c5b> */
	return 15451ULL;
x86_l_5c1b:
	/* 0x5c1b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c1e:
	/* 0x5c1e: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c23:
	/* 0x5c23: jmp    4b3b <generic_sleepable_preload+0x4b3b> */
	return 19259ULL;
x86_l_5c28:
	/* 0x5c28: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c2b:
	/* 0x5c2b: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c30:
	/* 0x5c30: jmp    4bc6 <generic_sleepable_preload+0x4bc6> */
	return 19398ULL;
x86_l_5c35:
	/* 0x5c35: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_5c3b:
	/* 0x5c3b: jmp    5a70 <generic_sleepable_preload+0x5a70> */
	goto x86_l_5a70;
x86_l_5c40:
	/* 0x5c40: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_5c46:
	/* 0x5c46: jmp    5afc <generic_sleepable_preload+0x5afc> */
	goto x86_l_5afc;
x86_l_5c4b:
	/* 0x5c4b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c4e:
	/* 0x5c4e: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c53:
	/* 0x5c53: jmp    5d4b <generic_sleepable_preload+0x5d4b> */
	goto x86_l_5d4b;
x86_l_5c58:
	/* 0x5c58: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c5b:
	/* 0x5c5b: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c60:
	/* 0x5c60: jmp    5d60 <generic_sleepable_preload+0x5d60> */
	goto x86_l_5d60;
x86_l_5c65:
	/* 0x5c65: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c68:
	/* 0x5c68: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c6d:
	/* 0x5c6d: jmp    5d75 <generic_sleepable_preload+0x5d75> */
	goto x86_l_5d75;
x86_l_5c72:
	/* 0x5c72: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c75:
	/* 0x5c75: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c7a:
	/* 0x5c7a: jmp    5d8a <generic_sleepable_preload+0x5d8a> */
	goto x86_l_5d8a;
x86_l_5c7f:
	/* 0x5c7f: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c82:
	/* 0x5c82: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c87:
	/* 0x5c87: jmp    5d9f <generic_sleepable_preload+0x5d9f> */
	goto x86_l_5d9f;
x86_l_5c8c:
	/* 0x5c8c: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c8f:
	/* 0x5c8f: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c94:
	/* 0x5c94: jmp    5db4 <generic_sleepable_preload+0x5db4> */
	goto x86_l_5db4;
x86_l_5c99:
	/* 0x5c99: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c9c:
	/* 0x5c9c: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5ca1:
	/* 0x5ca1: jmp    5dc9 <generic_sleepable_preload+0x5dc9> */
	goto x86_l_5dc9;
x86_l_5ca6:
	/* 0x5ca6: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ca9:
	/* 0x5ca9: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5cae:
	/* 0x5cae: jmp    5dde <generic_sleepable_preload+0x5dde> */
	goto x86_l_5dde;
x86_l_5cb3:
	/* 0x5cb3: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5cb8:
	/* 0x5cb8: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5cbb:
	/* 0x5cbb: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cc0:
	/* 0x5cc0: jmp    1cfb <generic_sleepable_preload+0x1cfb> */
	return 7419ULL;
x86_l_5cc5:
	/* 0x5cc5: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5cca:
	/* 0x5cca: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ccd:
	/* 0x5ccd: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cd2:
	/* 0x5cd2: jmp    1d86 <generic_sleepable_preload+0x1d86> */
	return 7558ULL;
x86_l_5cd7:
	/* 0x5cd7: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5cdc:
	/* 0x5cdc: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5cdf:
	/* 0x5cdf: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ce4:
	/* 0x5ce4: jmp    2c65 <generic_sleepable_preload+0x2c65> */
	return 11365ULL;
x86_l_5ce9:
	/* 0x5ce9: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5cee:
	/* 0x5cee: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5cf1:
	/* 0x5cf1: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cf6:
	/* 0x5cf6: jmp    2cf0 <generic_sleepable_preload+0x2cf0> */
	return 11504ULL;
x86_l_5cfb:
	/* 0x5cfb: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d00:
	/* 0x5d00: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d03:
	/* 0x5d03: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d08:
	/* 0x5d08: jmp    3bd0 <generic_sleepable_preload+0x3bd0> */
	return 15312ULL;
x86_l_5d0d:
	/* 0x5d0d: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d12:
	/* 0x5d12: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d15:
	/* 0x5d15: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d1a:
	/* 0x5d1a: jmp    3c5b <generic_sleepable_preload+0x3c5b> */
	return 15451ULL;
x86_l_5d1f:
	/* 0x5d1f: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d24:
	/* 0x5d24: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d27:
	/* 0x5d27: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d2c:
	/* 0x5d2c: jmp    4b3b <generic_sleepable_preload+0x4b3b> */
	return 19259ULL;
x86_l_5d31:
	/* 0x5d31: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d36:
	/* 0x5d36: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d39:
	/* 0x5d39: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d3e:
	/* 0x5d3e: jmp    4bc6 <generic_sleepable_preload+0x4bc6> */
	return 19398ULL;
x86_l_5d43:
	/* 0x5d43: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d48:
	/* 0x5d48: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d4b:
	/* 0x5d4b: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d50:
	/* 0x5d50: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5d53:
	/* 0x5d53: jmp    1cfb <generic_sleepable_preload+0x1cfb> */
	return 7419ULL;
x86_l_5d58:
	/* 0x5d58: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d5d:
	/* 0x5d5d: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d60:
	/* 0x5d60: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d65:
	/* 0x5d65: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5d68:
	/* 0x5d68: jmp    1d86 <generic_sleepable_preload+0x1d86> */
	return 7558ULL;
x86_l_5d6d:
	/* 0x5d6d: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d72:
	/* 0x5d72: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d75:
	/* 0x5d75: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d7a:
	/* 0x5d7a: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5d7d:
	/* 0x5d7d: jmp    2c65 <generic_sleepable_preload+0x2c65> */
	return 11365ULL;
x86_l_5d82:
	/* 0x5d82: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d87:
	/* 0x5d87: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d8a:
	/* 0x5d8a: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d8f:
	/* 0x5d8f: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5d92:
	/* 0x5d92: jmp    2cf0 <generic_sleepable_preload+0x2cf0> */
	return 11504ULL;
x86_l_5d97:
	/* 0x5d97: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d9c:
	/* 0x5d9c: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d9f:
	/* 0x5d9f: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5da4:
	/* 0x5da4: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5da7:
	/* 0x5da7: jmp    3bd0 <generic_sleepable_preload+0x3bd0> */
	return 15312ULL;
x86_l_5dac:
	/* 0x5dac: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5db1:
	/* 0x5db1: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5db4:
	/* 0x5db4: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5db9:
	/* 0x5db9: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5dbc:
	/* 0x5dbc: jmp    3c5b <generic_sleepable_preload+0x3c5b> */
	return 15451ULL;
x86_l_5dc1:
	/* 0x5dc1: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5dc6:
	/* 0x5dc6: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5dc9:
	/* 0x5dc9: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dce:
	/* 0x5dce: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5dd1:
	/* 0x5dd1: jmp    4b3b <generic_sleepable_preload+0x4b3b> */
	return 19259ULL;
x86_l_5dd6:
	/* 0x5dd6: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5ddb:
	/* 0x5ddb: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5dde:
	/* 0x5dde: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5de3:
	/* 0x5de3: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5de6:
	/* 0x5de6: jmp    4bc6 <generic_sleepable_preload+0x4bc6> */
	return 19398ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 20972U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1638ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1644ULL && __x86_pc <= 3184ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3190ULL && __x86_pc <= 4935ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4938ULL && __x86_pc <= 6761ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6767ULL && __x86_pc <= 8517ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8521ULL && __x86_pc <= 10384ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10392ULL && __x86_pc <= 12145ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12147ULL && __x86_pc <= 14003ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14005ULL && __x86_pc <= 15795ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 15801ULL && __x86_pc <= 17632ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 17635ULL && __x86_pc <= 19490ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 19495ULL && __x86_pc <= 21202ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 21210ULL && __x86_pc <= 22950ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 22952ULL && __x86_pc <= 24038ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_13(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

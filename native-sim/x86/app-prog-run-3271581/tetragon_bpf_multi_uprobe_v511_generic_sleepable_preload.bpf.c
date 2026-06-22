extern char CONFIG_ITER_NUM;
extern char config_map;
extern char heap_ro_zero;
extern char sleepable_preload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_0(
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
	case 27ULL: goto x86_l_1b;
	case 29ULL: goto x86_l_1d;
	case 36ULL: goto x86_l_24;
	case 43ULL: goto x86_l_2b;
	case 51ULL: goto x86_l_33;
	case 56ULL: goto x86_l_38;
	case 58ULL: goto x86_l_3a;
	case 61ULL: goto x86_l_3d;
	case 67ULL: goto x86_l_43;
	case 70ULL: goto x86_l_46;
	case 77ULL: goto x86_l_4d;
	case 82ULL: goto x86_l_52;
	case 89ULL: goto x86_l_59;
	case 94ULL: goto x86_l_5e;
	case 101ULL: goto x86_l_65;
	case 106ULL: goto x86_l_6a;
	case 110ULL: goto x86_l_6e;
	case 115ULL: goto x86_l_73;
	case 119ULL: goto x86_l_77;
	case 124ULL: goto x86_l_7c;
	case 128ULL: goto x86_l_80;
	case 133ULL: goto x86_l_85;
	case 137ULL: goto x86_l_89;
	case 142ULL: goto x86_l_8e;
	case 146ULL: goto x86_l_92;
	case 154ULL: goto x86_l_9a;
	case 158ULL: goto x86_l_9e;
	case 163ULL: goto x86_l_a3;
	case 167ULL: goto x86_l_a7;
	case 175ULL: goto x86_l_af;
	case 179ULL: goto x86_l_b3;
	case 184ULL: goto x86_l_b8;
	case 188ULL: goto x86_l_bc;
	case 196ULL: goto x86_l_c4;
	case 200ULL: goto x86_l_c8;
	case 205ULL: goto x86_l_cd;
	case 209ULL: goto x86_l_d1;
	case 217ULL: goto x86_l_d9;
	case 221ULL: goto x86_l_dd;
	case 226ULL: goto x86_l_e2;
	case 229ULL: goto x86_l_e5;
	case 233ULL: goto x86_l_e9;
	case 238ULL: goto x86_l_ee;
	case 242ULL: goto x86_l_f2;
	case 247ULL: goto x86_l_f7;
	case 253ULL: goto x86_l_fd;
	case 261ULL: goto x86_l_105;
	case 264ULL: goto x86_l_108;
	case 271ULL: goto x86_l_10f;
	case 274ULL: goto x86_l_112;
	case 276ULL: goto x86_l_114;
	case 278ULL: goto x86_l_116;
	case 283ULL: goto x86_l_11b;
	case 286ULL: goto x86_l_11e;
	case 290ULL: goto x86_l_122;
	case 294ULL: goto x86_l_126;
	case 300ULL: goto x86_l_12c;
	case 305ULL: goto x86_l_131;
	case 310ULL: goto x86_l_136;
	case 312ULL: goto x86_l_138;
	case 314ULL: goto x86_l_13a;
	case 316ULL: goto x86_l_13c;
	case 321ULL: goto x86_l_141;
	case 324ULL: goto x86_l_144;
	case 330ULL: goto x86_l_14a;
	case 333ULL: goto x86_l_14d;
	case 339ULL: goto x86_l_153;
	case 342ULL: goto x86_l_156;
	case 348ULL: goto x86_l_15c;
	case 351ULL: goto x86_l_15f;
	case 357ULL: goto x86_l_165;
	case 362ULL: goto x86_l_16a;
	case 367ULL: goto x86_l_16f;
	case 376ULL: goto x86_l_178;
	case 385ULL: goto x86_l_181;
	case 391ULL: goto x86_l_187;
	case 394ULL: goto x86_l_18a;
	case 396ULL: goto x86_l_18c;
	case 399ULL: goto x86_l_18f;
	case 405ULL: goto x86_l_195;
	case 408ULL: goto x86_l_198;
	case 414ULL: goto x86_l_19e;
	case 419ULL: goto x86_l_1a3;
	case 422ULL: goto x86_l_1a6;
	case 428ULL: goto x86_l_1ac;
	case 433ULL: goto x86_l_1b1;
	case 436ULL: goto x86_l_1b4;
	case 442ULL: goto x86_l_1ba;
	case 447ULL: goto x86_l_1bf;
	case 450ULL: goto x86_l_1c2;
	case 456ULL: goto x86_l_1c8;
	case 461ULL: goto x86_l_1cd;
	case 466ULL: goto x86_l_1d2;
	case 469ULL: goto x86_l_1d5;
	case 471ULL: goto x86_l_1d7;
	case 474ULL: goto x86_l_1da;
	case 480ULL: goto x86_l_1e0;
	case 485ULL: goto x86_l_1e5;
	case 487ULL: goto x86_l_1e7;
	case 493ULL: goto x86_l_1ed;
	case 501ULL: goto x86_l_1f5;
	case 506ULL: goto x86_l_1fa;
	case 509ULL: goto x86_l_1fd;
	case 515ULL: goto x86_l_203;
	case 520ULL: goto x86_l_208;
	case 522ULL: goto x86_l_20a;
	case 528ULL: goto x86_l_210;
	case 531ULL: goto x86_l_213;
	case 537ULL: goto x86_l_219;
	case 542ULL: goto x86_l_21e;
	case 544ULL: goto x86_l_220;
	case 547ULL: goto x86_l_223;
	case 553ULL: goto x86_l_229;
	case 561ULL: goto x86_l_231;
	case 564ULL: goto x86_l_234;
	case 570ULL: goto x86_l_23a;
	case 575ULL: goto x86_l_23f;
	case 580ULL: goto x86_l_244;
	case 583ULL: goto x86_l_247;
	case 589ULL: goto x86_l_24d;
	case 594ULL: goto x86_l_252;
	case 597ULL: goto x86_l_255;
	case 603ULL: goto x86_l_25b;
	case 611ULL: goto x86_l_263;
	case 614ULL: goto x86_l_266;
	case 620ULL: goto x86_l_26c;
	case 625ULL: goto x86_l_271;
	case 630ULL: goto x86_l_276;
	case 633ULL: goto x86_l_279;
	case 639ULL: goto x86_l_27f;
	case 644ULL: goto x86_l_284;
	case 649ULL: goto x86_l_289;
	case 651ULL: goto x86_l_28b;
	case 656ULL: goto x86_l_290;
	case 658ULL: goto x86_l_292;
	case 663ULL: goto x86_l_297;
	case 666ULL: goto x86_l_29a;
	case 670ULL: goto x86_l_29e;
	case 673ULL: goto x86_l_2a1;
	case 676ULL: goto x86_l_2a4;
	case 681ULL: goto x86_l_2a9;
	case 687ULL: goto x86_l_2af;
	case 694ULL: goto x86_l_2b6;
	case 697ULL: goto x86_l_2b9;
	case 700ULL: goto x86_l_2bc;
	case 703ULL: goto x86_l_2bf;
	case 707ULL: goto x86_l_2c3;
	case 711ULL: goto x86_l_2c7;
	case 713ULL: goto x86_l_2c9;
	case 719ULL: goto x86_l_2cf;
	case 722ULL: goto x86_l_2d2;
	case 724ULL: goto x86_l_2d4;
	case 729ULL: goto x86_l_2d9;
	case 734ULL: goto x86_l_2de;
	case 737ULL: goto x86_l_2e1;
	case 741ULL: goto x86_l_2e5;
	case 746ULL: goto x86_l_2ea;
	case 748ULL: goto x86_l_2ec;
	case 750ULL: goto x86_l_2ee;
	case 756ULL: goto x86_l_2f4;
	case 761ULL: goto x86_l_2f9;
	case 767ULL: goto x86_l_2ff;
	case 770ULL: goto x86_l_302;
	case 774ULL: goto x86_l_306;
	case 778ULL: goto x86_l_30a;
	case 783ULL: goto x86_l_30f;
	case 785ULL: goto x86_l_311;
	case 790ULL: goto x86_l_316;
	case 795ULL: goto x86_l_31b;
	case 798ULL: goto x86_l_31e;
	case 802ULL: goto x86_l_322;
	case 807ULL: goto x86_l_327;
	case 809ULL: goto x86_l_329;
	case 811ULL: goto x86_l_32b;
	case 817ULL: goto x86_l_331;
	case 822ULL: goto x86_l_336;
	case 828ULL: goto x86_l_33c;
	case 831ULL: goto x86_l_33f;
	case 835ULL: goto x86_l_343;
	case 839ULL: goto x86_l_347;
	case 844ULL: goto x86_l_34c;
	case 846ULL: goto x86_l_34e;
	case 851ULL: goto x86_l_353;
	case 856ULL: goto x86_l_358;
	case 859ULL: goto x86_l_35b;
	case 863ULL: goto x86_l_35f;
	case 868ULL: goto x86_l_364;
	case 870ULL: goto x86_l_366;
	case 872ULL: goto x86_l_368;
	case 878ULL: goto x86_l_36e;
	case 883ULL: goto x86_l_373;
	case 889ULL: goto x86_l_379;
	case 892ULL: goto x86_l_37c;
	case 896ULL: goto x86_l_380;
	case 900ULL: goto x86_l_384;
	case 905ULL: goto x86_l_389;
	case 907ULL: goto x86_l_38b;
	case 912ULL: goto x86_l_390;
	case 917ULL: goto x86_l_395;
	case 920ULL: goto x86_l_398;
	case 924ULL: goto x86_l_39c;
	case 929ULL: goto x86_l_3a1;
	case 931ULL: goto x86_l_3a3;
	case 933ULL: goto x86_l_3a5;
	case 939ULL: goto x86_l_3ab;
	case 944ULL: goto x86_l_3b0;
	case 950ULL: goto x86_l_3b6;
	case 953ULL: goto x86_l_3b9;
	case 957ULL: goto x86_l_3bd;
	case 961ULL: goto x86_l_3c1;
	case 966ULL: goto x86_l_3c6;
	case 968ULL: goto x86_l_3c8;
	case 973ULL: goto x86_l_3cd;
	case 978ULL: goto x86_l_3d2;
	case 981ULL: goto x86_l_3d5;
	case 985ULL: goto x86_l_3d9;
	case 990ULL: goto x86_l_3de;
	case 992ULL: goto x86_l_3e0;
	case 994ULL: goto x86_l_3e2;
	case 1000ULL: goto x86_l_3e8;
	case 1005ULL: goto x86_l_3ed;
	case 1011ULL: goto x86_l_3f3;
	case 1014ULL: goto x86_l_3f6;
	case 1018ULL: goto x86_l_3fa;
	case 1022ULL: goto x86_l_3fe;
	case 1027ULL: goto x86_l_403;
	case 1029ULL: goto x86_l_405;
	case 1034ULL: goto x86_l_40a;
	case 1039ULL: goto x86_l_40f;
	case 1042ULL: goto x86_l_412;
	case 1046ULL: goto x86_l_416;
	case 1051ULL: goto x86_l_41b;
	case 1053ULL: goto x86_l_41d;
	case 1055ULL: goto x86_l_41f;
	case 1061ULL: goto x86_l_425;
	case 1066ULL: goto x86_l_42a;
	case 1072ULL: goto x86_l_430;
	case 1075ULL: goto x86_l_433;
	case 1079ULL: goto x86_l_437;
	case 1083ULL: goto x86_l_43b;
	case 1088ULL: goto x86_l_440;
	case 1090ULL: goto x86_l_442;
	case 1095ULL: goto x86_l_447;
	case 1100ULL: goto x86_l_44c;
	case 1103ULL: goto x86_l_44f;
	case 1107ULL: goto x86_l_453;
	case 1112ULL: goto x86_l_458;
	case 1114ULL: goto x86_l_45a;
	case 1116ULL: goto x86_l_45c;
	case 1122ULL: goto x86_l_462;
	case 1127ULL: goto x86_l_467;
	case 1133ULL: goto x86_l_46d;
	case 1136ULL: goto x86_l_470;
	case 1140ULL: goto x86_l_474;
	case 1144ULL: goto x86_l_478;
	case 1149ULL: goto x86_l_47d;
	case 1151ULL: goto x86_l_47f;
	case 1156ULL: goto x86_l_484;
	case 1161ULL: goto x86_l_489;
	case 1164ULL: goto x86_l_48c;
	case 1168ULL: goto x86_l_490;
	case 1173ULL: goto x86_l_495;
	case 1175ULL: goto x86_l_497;
	case 1177ULL: goto x86_l_499;
	case 1183ULL: goto x86_l_49f;
	case 1188ULL: goto x86_l_4a4;
	case 1194ULL: goto x86_l_4aa;
	case 1197ULL: goto x86_l_4ad;
	case 1201ULL: goto x86_l_4b1;
	case 1205ULL: goto x86_l_4b5;
	case 1210ULL: goto x86_l_4ba;
	case 1212ULL: goto x86_l_4bc;
	case 1217ULL: goto x86_l_4c1;
	case 1222ULL: goto x86_l_4c6;
	case 1225ULL: goto x86_l_4c9;
	case 1229ULL: goto x86_l_4cd;
	case 1234ULL: goto x86_l_4d2;
	case 1236ULL: goto x86_l_4d4;
	case 1238ULL: goto x86_l_4d6;
	case 1244ULL: goto x86_l_4dc;
	case 1248ULL: goto x86_l_4e0;
	case 1254ULL: goto x86_l_4e6;
	case 1257ULL: goto x86_l_4e9;
	case 1261ULL: goto x86_l_4ed;
	case 1265ULL: goto x86_l_4f1;
	case 1270ULL: goto x86_l_4f6;
	case 1276ULL: goto x86_l_4fc;
	case 1281ULL: goto x86_l_501;
	case 1286ULL: goto x86_l_506;
	case 1289ULL: goto x86_l_509;
	case 1294ULL: goto x86_l_50e;
	case 1297ULL: goto x86_l_511;
	case 1299ULL: goto x86_l_513;
	case 1304ULL: goto x86_l_518;
	case 1309ULL: goto x86_l_51d;
	case 1312ULL: goto x86_l_520;
	case 1316ULL: goto x86_l_524;
	case 1321ULL: goto x86_l_529;
	case 1323ULL: goto x86_l_52b;
	case 1325ULL: goto x86_l_52d;
	case 1331ULL: goto x86_l_533;
	case 1336ULL: goto x86_l_538;
	case 1342ULL: goto x86_l_53e;
	case 1345ULL: goto x86_l_541;
	case 1349ULL: goto x86_l_545;
	case 1353ULL: goto x86_l_549;
	case 1358ULL: goto x86_l_54e;
	case 1360ULL: goto x86_l_550;
	case 1365ULL: goto x86_l_555;
	case 1370ULL: goto x86_l_55a;
	case 1373ULL: goto x86_l_55d;
	case 1377ULL: goto x86_l_561;
	case 1382ULL: goto x86_l_566;
	case 1384ULL: goto x86_l_568;
	case 1386ULL: goto x86_l_56a;
	case 1392ULL: goto x86_l_570;
	case 1397ULL: goto x86_l_575;
	case 1403ULL: goto x86_l_57b;
	case 1406ULL: goto x86_l_57e;
	case 1410ULL: goto x86_l_582;
	case 1414ULL: goto x86_l_586;
	case 1419ULL: goto x86_l_58b;
	case 1421ULL: goto x86_l_58d;
	case 1426ULL: goto x86_l_592;
	case 1431ULL: goto x86_l_597;
	case 1434ULL: goto x86_l_59a;
	case 1438ULL: goto x86_l_59e;
	case 1443ULL: goto x86_l_5a3;
	case 1445ULL: goto x86_l_5a5;
	case 1447ULL: goto x86_l_5a7;
	case 1453ULL: goto x86_l_5ad;
	case 1458ULL: goto x86_l_5b2;
	case 1464ULL: goto x86_l_5b8;
	case 1467ULL: goto x86_l_5bb;
	case 1471ULL: goto x86_l_5bf;
	case 1475ULL: goto x86_l_5c3;
	case 1480ULL: goto x86_l_5c8;
	case 1482ULL: goto x86_l_5ca;
	case 1487ULL: goto x86_l_5cf;
	case 1492ULL: goto x86_l_5d4;
	case 1495ULL: goto x86_l_5d7;
	case 1499ULL: goto x86_l_5db;
	case 1504ULL: goto x86_l_5e0;
	case 1506ULL: goto x86_l_5e2;
	case 1508ULL: goto x86_l_5e4;
	case 1514ULL: goto x86_l_5ea;
	case 1519ULL: goto x86_l_5ef;
	case 1525ULL: goto x86_l_5f5;
	case 1528ULL: goto x86_l_5f8;
	case 1532ULL: goto x86_l_5fc;
	case 1536ULL: goto x86_l_600;
	case 1541ULL: goto x86_l_605;
	case 1543ULL: goto x86_l_607;
	case 1548ULL: goto x86_l_60c;
	case 1553ULL: goto x86_l_611;
	case 1556ULL: goto x86_l_614;
	case 1560ULL: goto x86_l_618;
	case 1565ULL: goto x86_l_61d;
	case 1567ULL: goto x86_l_61f;
	case 1569ULL: goto x86_l_621;
	case 1575ULL: goto x86_l_627;
	case 1580ULL: goto x86_l_62c;
	case 1586ULL: goto x86_l_632;
	case 1589ULL: goto x86_l_635;
	case 1593ULL: goto x86_l_639;
	case 1597ULL: goto x86_l_63d;
	case 1602ULL: goto x86_l_642;
	case 1604ULL: goto x86_l_644;
	case 1609ULL: goto x86_l_649;
	case 1614ULL: goto x86_l_64e;
	case 1617ULL: goto x86_l_651;
	case 1621ULL: goto x86_l_655;
	case 1626ULL: goto x86_l_65a;
	case 1628ULL: goto x86_l_65c;
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
	/* 0xa: sub    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 184ULL);
x86_l_11:
	/* 0x11: mov    eax,0xae */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 174ULL);
x86_l_16:
	/* 0x16: mov    QWORD PTR [rsp+0x48],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b:
	/* 0x1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d:
	/* 0x1d: mov    DWORD PTR [rsp+0xac],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_24:
	/* 0x24: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_2b:
	/* 0x2b: lea    rsi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_33:
	/* 0x33: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_38:
	/* 0x38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a:
	/* 0x3a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3d:
	/* 0x3d: je     4c7a <generic_sleepable_preload+0x4c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19578ULL;
	}
x86_l_43:
	/* 0x43: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_46:
	/* 0x46: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_4d:
	/* 0x4d: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_52:
	/* 0x52: lea    rdx,[rcx+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_59:
	/* 0x59: mov    QWORD PTR [rsp+0x50],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5e:
	/* 0x5e: lea    rdx,[rcx+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_65:
	/* 0x65: mov    QWORD PTR [rsp+0x70],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6a:
	/* 0x6a: lea    rdx,[rcx+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6e:
	/* 0x6e: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_73:
	/* 0x73: lea    rdx,[rcx+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_77:
	/* 0x77: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7c:
	/* 0x7c: lea    rdx,[rcx+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_80:
	/* 0x80: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_85:
	/* 0x85: lea    rdx,[rcx+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_89:
	/* 0x89: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8e:
	/* 0x8e: lea    rdx,[rcx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_92:
	/* 0x92: mov    QWORD PTR [rsp+0x98],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_9a:
	/* 0x9a: lea    rdx,[rcx+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9e:
	/* 0x9e: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a3:
	/* 0xa3: lea    rdx,[rcx+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a7:
	/* 0xa7: mov    QWORD PTR [rsp+0x90],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_af:
	/* 0xaf: lea    rdx,[rcx+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b3:
	/* 0xb3: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b8:
	/* 0xb8: lea    rdx,[rcx+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bc:
	/* 0xbc: mov    QWORD PTR [rsp+0x88],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c4:
	/* 0xc4: lea    rdx,[rcx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c8:
	/* 0xc8: mov    QWORD PTR [rsp+0x60],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_cd:
	/* 0xcd: lea    rdx,[rcx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d1:
	/* 0xd1: mov    QWORD PTR [rsp+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d9:
	/* 0xd9: lea    rdx,[rcx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dd:
	/* 0xdd: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e2:
	/* 0xe2: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e5:
	/* 0xe5: lea    rax,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e9:
	/* 0xe9: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ee:
	/* 0xee: lea    r14,[rcx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f2:
	/* 0xf2: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f7:
	/* 0xf7: je     efe <generic_sleepable_preload+0xefe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3838ULL;
	}
x86_l_fd:
	/* 0xfd: mov    QWORD PTR [rsp+0xb0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_105:
	/* 0x105: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_108:
	/* 0x108: add    rbx,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_10f:
	/* 0x10f: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_112:
	/* 0x112: jmp    12c <generic_sleepable_preload+0x12c> */
	goto x86_l_12c;
x86_l_114:
	/* 0x114: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_116:
	/* 0x116: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11b:
	/* 0x11b: inc    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_11e:
	/* 0x11e: add    rbx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_122:
	/* 0x122: cmp    r14,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 5ULL);
x86_l_126:
	/* 0x126: je     4c7a <generic_sleepable_preload+0x4c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19578ULL;
	}
x86_l_12c:
	/* 0x12c: mov    eax,DWORD PTR [r12+r14*4+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 24ULL);
x86_l_131:
	/* 0x131: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_136:
	/* 0x136: je     11b <generic_sleepable_preload+0x11b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11b;
	}
x86_l_138:
	/* 0x138: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_13a:
	/* 0x13a: js     16f <generic_sleepable_preload+0x16f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_16f;
	}
x86_l_13c:
	/* 0x13c: mov    eax,DWORD PTR [r12+r14*4+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 64ULL);
x86_l_141:
	/* 0x141: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_144:
	/* 0x144: jle    208 <generic_sleepable_preload+0x208> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_208;
	}
x86_l_14a:
	/* 0x14a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_14d:
	/* 0x14d: je     284 <generic_sleepable_preload+0x284> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_284;
	}
x86_l_153:
	/* 0x153: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_156:
	/* 0x156: je     28b <generic_sleepable_preload+0x28b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28b;
	}
x86_l_15c:
	/* 0x15c: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15f:
	/* 0x15f: jne    29e <generic_sleepable_preload+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29e;
	}
x86_l_165:
	/* 0x165: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16a:
	/* 0x16a: jmp    297 <generic_sleepable_preload+0x297> */
	goto x86_l_297;
x86_l_16f:
	/* 0x16f: movzx  eax,BYTE PTR [r12+r14*4+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_8), 706ULL);
x86_l_178:
	/* 0x178: movzx  ecx,WORD PTR [r12+r14*4+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_16), 704ULL);
x86_l_181:
	/* 0x181: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_187:
	/* 0x187: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_18a:
	/* 0x18a: jle    1d2 <generic_sleepable_preload+0x1d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1d2;
	}
x86_l_18c:
	/* 0x18c: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_18f:
	/* 0x18f: jle    220 <generic_sleepable_preload+0x220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_220;
	}
x86_l_195:
	/* 0x195: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_198:
	/* 0x198: jle    7c8 <generic_sleepable_preload+0x7c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 1992ULL;
	}
x86_l_19e:
	/* 0x19e: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a3:
	/* 0x1a3: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_1a6:
	/* 0x1a6: je     7e1 <generic_sleepable_preload+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2017ULL;
	}
x86_l_1ac:
	/* 0x1ac: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1b1:
	/* 0x1b1: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1b4:
	/* 0x1b4: je     7e1 <generic_sleepable_preload+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2017ULL;
	}
x86_l_1ba:
	/* 0x1ba: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_1bf:
	/* 0x1bf: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_1c2:
	/* 0x1c2: jne    7f4 <generic_sleepable_preload+0x7f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2036ULL;
	}
x86_l_1c8:
	/* 0x1c8: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1cd:
	/* 0x1cd: jmp    7e1 <generic_sleepable_preload+0x7e1> */
	return 2017ULL;
x86_l_1d2:
	/* 0x1d2: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1d5:
	/* 0x1d5: jg     252 <generic_sleepable_preload+0x252> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_252;
	}
x86_l_1d7:
	/* 0x1d7: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1da:
	/* 0x1da: jg     78f <generic_sleepable_preload+0x78f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1935ULL;
	}
x86_l_1e0:
	/* 0x1e0: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1e5:
	/* 0x1e5: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1e7:
	/* 0x1e7: je     7e1 <generic_sleepable_preload+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2017ULL;
	}
x86_l_1ed:
	/* 0x1ed: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1f5:
	/* 0x1f5: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_1fa:
	/* 0x1fa: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1fd:
	/* 0x1fd: je     7e1 <generic_sleepable_preload+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2017ULL;
	}
x86_l_203:
	/* 0x203: jmp    7f4 <generic_sleepable_preload+0x7f4> */
	return 2036ULL;
x86_l_208:
	/* 0x208: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20a:
	/* 0x20a: je     292 <generic_sleepable_preload+0x292> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_292;
	}
x86_l_210:
	/* 0x210: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_213:
	/* 0x213: jne    29e <generic_sleepable_preload+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29e;
	}
x86_l_219:
	/* 0x219: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21e:
	/* 0x21e: jmp    297 <generic_sleepable_preload+0x297> */
	goto x86_l_297;
x86_l_220:
	/* 0x220: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_223:
	/* 0x223: jg     771 <generic_sleepable_preload+0x771> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1905ULL;
	}
x86_l_229:
	/* 0x229: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_231:
	/* 0x231: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_234:
	/* 0x234: je     7e1 <generic_sleepable_preload+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2017ULL;
	}
x86_l_23a:
	/* 0x23a: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_23f:
	/* 0x23f: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_244:
	/* 0x244: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_247:
	/* 0x247: je     7e1 <generic_sleepable_preload+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2017ULL;
	}
x86_l_24d:
	/* 0x24d: jmp    7f4 <generic_sleepable_preload+0x7f4> */
	return 2036ULL;
x86_l_252:
	/* 0x252: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_255:
	/* 0x255: jg     7aa <generic_sleepable_preload+0x7aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1962ULL;
	}
x86_l_25b:
	/* 0x25b: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_263:
	/* 0x263: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_266:
	/* 0x266: je     7e1 <generic_sleepable_preload+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2017ULL;
	}
x86_l_26c:
	/* 0x26c: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_271:
	/* 0x271: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_276:
	/* 0x276: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_279:
	/* 0x279: je     7e1 <generic_sleepable_preload+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2017ULL;
	}
x86_l_27f:
	/* 0x27f: jmp    7f4 <generic_sleepable_preload+0x7f4> */
	return 2036ULL;
x86_l_284:
	/* 0x284: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_289:
	/* 0x289: jmp    297 <generic_sleepable_preload+0x297> */
	goto x86_l_297;
x86_l_28b:
	/* 0x28b: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_290:
	/* 0x290: jmp    297 <generic_sleepable_preload+0x297> */
	goto x86_l_297;
x86_l_292:
	/* 0x292: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_297:
	/* 0x297: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29a:
	/* 0x29a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29e:
	/* 0x29e: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a1:
	/* 0x2a1: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_2a4:
	/* 0x2a4: cmp    WORD PTR [rbx-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743764471906304ULL);
x86_l_2a9:
	/* 0x2a9: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_2af:
	/* 0x2af: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_2b6:
	/* 0x2b6: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2b9:
	/* 0x2b9: mov    eax,DWORD PTR [rbx-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551538ULL);
x86_l_2bc:
	/* 0x2bc: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2bf:
	/* 0x2bf: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c3:
	/* 0x2c3: movzx  eax,WORD PTR [rbx-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_2c7:
	/* 0x2c7: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_2c9:
	/* 0x2c9: je     50e <generic_sleepable_preload+0x50e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50e;
	}
x86_l_2cf:
	/* 0x2cf: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2d2:
	/* 0x2d2: je     2f4 <generic_sleepable_preload+0x2f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f4;
	}
x86_l_2d4:
	/* 0x2d4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d9:
	/* 0x2d9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2de:
	/* 0x2de: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2e1:
	/* 0x2e1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e5:
	/* 0x2e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ea:
	/* 0x2ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ec:
	/* 0x2ec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ee:
	/* 0x2ee: js     766 <generic_sleepable_preload+0x766> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1894ULL;
	}
x86_l_2f4:
	/* 0x2f4: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_2f9:
	/* 0x2f9: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_2ff:
	/* 0x2ff: mov    ecx,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_302:
	/* 0x302: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_306:
	/* 0x306: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30a:
	/* 0x30a: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_30f:
	/* 0x30f: je     331 <generic_sleepable_preload+0x331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_331;
	}
x86_l_311:
	/* 0x311: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_316:
	/* 0x316: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_31b:
	/* 0x31b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_31e:
	/* 0x31e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_322:
	/* 0x322: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_327:
	/* 0x327: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_329:
	/* 0x329: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32b:
	/* 0x32b: js     ccd <generic_sleepable_preload+0xccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3277ULL;
	}
x86_l_331:
	/* 0x331: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_336:
	/* 0x336: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_33c:
	/* 0x33c: mov    ecx,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_33f:
	/* 0x33f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_343:
	/* 0x343: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_347:
	/* 0x347: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_34c:
	/* 0x34c: je     36e <generic_sleepable_preload+0x36e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36e;
	}
x86_l_34e:
	/* 0x34e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_353:
	/* 0x353: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_358:
	/* 0x358: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_35b:
	/* 0x35b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35f:
	/* 0x35f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_364:
	/* 0x364: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_366:
	/* 0x366: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_368:
	/* 0x368: js     cdf <generic_sleepable_preload+0xcdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3295ULL;
	}
x86_l_36e:
	/* 0x36e: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_373:
	/* 0x373: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_379:
	/* 0x379: mov    ecx,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_37c:
	/* 0x37c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_380:
	/* 0x380: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_384:
	/* 0x384: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_389:
	/* 0x389: je     3ab <generic_sleepable_preload+0x3ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ab;
	}
x86_l_38b:
	/* 0x38b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_390:
	/* 0x390: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_395:
	/* 0x395: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_398:
	/* 0x398: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39c:
	/* 0x39c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a1:
	/* 0x3a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a3:
	/* 0x3a3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a5:
	/* 0x3a5: js     cf1 <generic_sleepable_preload+0xcf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3313ULL;
	}
x86_l_3ab:
	/* 0x3ab: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_3b0:
	/* 0x3b0: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_3b6:
	/* 0x3b6: mov    ecx,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_3b9:
	/* 0x3b9: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3bd:
	/* 0x3bd: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c1:
	/* 0x3c1: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_3c6:
	/* 0x3c6: je     3e8 <generic_sleepable_preload+0x3e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e8;
	}
x86_l_3c8:
	/* 0x3c8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3cd:
	/* 0x3cd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3d2:
	/* 0x3d2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3d5:
	/* 0x3d5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d9:
	/* 0x3d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3de:
	/* 0x3de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e0:
	/* 0x3e0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3e2:
	/* 0x3e2: js     d03 <generic_sleepable_preload+0xd03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3331ULL;
	}
x86_l_3e8:
	/* 0x3e8: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_3ed:
	/* 0x3ed: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_3f3:
	/* 0x3f3: mov    ecx,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_3f6:
	/* 0x3f6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3fa:
	/* 0x3fa: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fe:
	/* 0x3fe: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_403:
	/* 0x403: je     425 <generic_sleepable_preload+0x425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_425;
	}
x86_l_405:
	/* 0x405: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_40a:
	/* 0x40a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_40f:
	/* 0x40f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_412:
	/* 0x412: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_416:
	/* 0x416: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41b:
	/* 0x41b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41d:
	/* 0x41d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_41f:
	/* 0x41f: js     d15 <generic_sleepable_preload+0xd15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3349ULL;
	}
x86_l_425:
	/* 0x425: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_42a:
	/* 0x42a: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_430:
	/* 0x430: mov    ecx,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_433:
	/* 0x433: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_437:
	/* 0x437: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43b:
	/* 0x43b: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_440:
	/* 0x440: je     462 <generic_sleepable_preload+0x462> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_462;
	}
x86_l_442:
	/* 0x442: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_447:
	/* 0x447: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_44c:
	/* 0x44c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_44f:
	/* 0x44f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_453:
	/* 0x453: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_458:
	/* 0x458: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45a:
	/* 0x45a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_45c:
	/* 0x45c: js     d27 <generic_sleepable_preload+0xd27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3367ULL;
	}
x86_l_462:
	/* 0x462: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_467:
	/* 0x467: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_46d:
	/* 0x46d: mov    ecx,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_470:
	/* 0x470: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_474:
	/* 0x474: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_478:
	/* 0x478: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_47d:
	/* 0x47d: je     49f <generic_sleepable_preload+0x49f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49f;
	}
x86_l_47f:
	/* 0x47f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_484:
	/* 0x484: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_489:
	/* 0x489: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_48c:
	/* 0x48c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_490:
	/* 0x490: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_495:
	/* 0x495: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_497:
	/* 0x497: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_499:
	/* 0x499: js     ec5 <generic_sleepable_preload+0xec5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3781ULL;
	}
x86_l_49f:
	/* 0x49f: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_4a4:
	/* 0x4a4: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_4aa:
	/* 0x4aa: mov    ecx,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_4ad:
	/* 0x4ad: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4b1:
	/* 0x4b1: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b5:
	/* 0x4b5: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_4ba:
	/* 0x4ba: je     4dc <generic_sleepable_preload+0x4dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4dc;
	}
x86_l_4bc:
	/* 0x4bc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4c1:
	/* 0x4c1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4c6:
	/* 0x4c6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4c9:
	/* 0x4c9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4cd:
	/* 0x4cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d2:
	/* 0x4d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d4:
	/* 0x4d4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d6:
	/* 0x4d6: js     ee9 <generic_sleepable_preload+0xee9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3817ULL;
	}
x86_l_4dc:
	/* 0x4dc: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e0:
	/* 0x4e0: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_4e6:
	/* 0x4e6: mov    ecx,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_4e9:
	/* 0x4e9: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4ed:
	/* 0x4ed: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f1:
	/* 0x4f1: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_4f6:
	/* 0x4f6: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_4fc:
	/* 0x4fc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_501:
	/* 0x501: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_506:
	/* 0x506: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_509:
	/* 0x509: jmp    748 <generic_sleepable_preload+0x748> */
	return 1864ULL;
x86_l_50e:
	/* 0x50e: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_511:
	/* 0x511: je     533 <generic_sleepable_preload+0x533> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_533;
	}
x86_l_513:
	/* 0x513: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_518:
	/* 0x518: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_51d:
	/* 0x51d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_520:
	/* 0x520: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_524:
	/* 0x524: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_529:
	/* 0x529: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52b:
	/* 0x52b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52d:
	/* 0x52d: js     766 <generic_sleepable_preload+0x766> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1894ULL;
	}
x86_l_533:
	/* 0x533: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_538:
	/* 0x538: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_53e:
	/* 0x53e: mov    ecx,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_541:
	/* 0x541: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_545:
	/* 0x545: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_549:
	/* 0x549: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_54e:
	/* 0x54e: je     570 <generic_sleepable_preload+0x570> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_570;
	}
x86_l_550:
	/* 0x550: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_555:
	/* 0x555: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_55a:
	/* 0x55a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_55d:
	/* 0x55d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_561:
	/* 0x561: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_566:
	/* 0x566: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_568:
	/* 0x568: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56a:
	/* 0x56a: js     ccd <generic_sleepable_preload+0xccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3277ULL;
	}
x86_l_570:
	/* 0x570: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_575:
	/* 0x575: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_57b:
	/* 0x57b: mov    ecx,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_57e:
	/* 0x57e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_582:
	/* 0x582: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_586:
	/* 0x586: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_58b:
	/* 0x58b: je     5ad <generic_sleepable_preload+0x5ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ad;
	}
x86_l_58d:
	/* 0x58d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_592:
	/* 0x592: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_597:
	/* 0x597: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_59a:
	/* 0x59a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59e:
	/* 0x59e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a3:
	/* 0x5a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a5:
	/* 0x5a5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5a7:
	/* 0x5a7: js     cdf <generic_sleepable_preload+0xcdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3295ULL;
	}
x86_l_5ad:
	/* 0x5ad: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_5b2:
	/* 0x5b2: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_5b8:
	/* 0x5b8: mov    ecx,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_5bb:
	/* 0x5bb: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5bf:
	/* 0x5bf: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c3:
	/* 0x5c3: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_5c8:
	/* 0x5c8: je     5ea <generic_sleepable_preload+0x5ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ea;
	}
x86_l_5ca:
	/* 0x5ca: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5cf:
	/* 0x5cf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5d4:
	/* 0x5d4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5d7:
	/* 0x5d7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5db:
	/* 0x5db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e0:
	/* 0x5e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e2:
	/* 0x5e2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5e4:
	/* 0x5e4: js     cf1 <generic_sleepable_preload+0xcf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3313ULL;
	}
x86_l_5ea:
	/* 0x5ea: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_5ef:
	/* 0x5ef: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_5f5:
	/* 0x5f5: mov    ecx,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_5f8:
	/* 0x5f8: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5fc:
	/* 0x5fc: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_600:
	/* 0x600: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_605:
	/* 0x605: je     627 <generic_sleepable_preload+0x627> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_627;
	}
x86_l_607:
	/* 0x607: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_60c:
	/* 0x60c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_611:
	/* 0x611: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_614:
	/* 0x614: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_618:
	/* 0x618: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_61d:
	/* 0x61d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61f:
	/* 0x61f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_621:
	/* 0x621: js     d03 <generic_sleepable_preload+0xd03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3331ULL;
	}
x86_l_627:
	/* 0x627: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_62c:
	/* 0x62c: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_632:
	/* 0x632: mov    ecx,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_635:
	/* 0x635: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_639:
	/* 0x639: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_63d:
	/* 0x63d: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_642:
	/* 0x642: je     664 <generic_sleepable_preload+0x664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1636ULL;
	}
x86_l_644:
	/* 0x644: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_649:
	/* 0x649: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_64e:
	/* 0x64e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_651:
	/* 0x651: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_655:
	/* 0x655: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_65a:
	/* 0x65a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65c:
	/* 0x65c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_65e:
	/* 0x65e: js     d15 <generic_sleepable_preload+0xd15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3349ULL;
	}
	return 1636ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1636ULL: goto x86_l_664;
	case 1641ULL: goto x86_l_669;
	case 1647ULL: goto x86_l_66f;
	case 1650ULL: goto x86_l_672;
	case 1654ULL: goto x86_l_676;
	case 1658ULL: goto x86_l_67a;
	case 1663ULL: goto x86_l_67f;
	case 1665ULL: goto x86_l_681;
	case 1670ULL: goto x86_l_686;
	case 1675ULL: goto x86_l_68b;
	case 1678ULL: goto x86_l_68e;
	case 1682ULL: goto x86_l_692;
	case 1687ULL: goto x86_l_697;
	case 1689ULL: goto x86_l_699;
	case 1691ULL: goto x86_l_69b;
	case 1697ULL: goto x86_l_6a1;
	case 1702ULL: goto x86_l_6a6;
	case 1708ULL: goto x86_l_6ac;
	case 1711ULL: goto x86_l_6af;
	case 1715ULL: goto x86_l_6b3;
	case 1719ULL: goto x86_l_6b7;
	case 1724ULL: goto x86_l_6bc;
	case 1726ULL: goto x86_l_6be;
	case 1731ULL: goto x86_l_6c3;
	case 1736ULL: goto x86_l_6c8;
	case 1739ULL: goto x86_l_6cb;
	case 1743ULL: goto x86_l_6cf;
	case 1748ULL: goto x86_l_6d4;
	case 1750ULL: goto x86_l_6d6;
	case 1752ULL: goto x86_l_6d8;
	case 1758ULL: goto x86_l_6de;
	case 1763ULL: goto x86_l_6e3;
	case 1769ULL: goto x86_l_6e9;
	case 1772ULL: goto x86_l_6ec;
	case 1776ULL: goto x86_l_6f0;
	case 1780ULL: goto x86_l_6f4;
	case 1785ULL: goto x86_l_6f9;
	case 1787ULL: goto x86_l_6fb;
	case 1792ULL: goto x86_l_700;
	case 1797ULL: goto x86_l_705;
	case 1800ULL: goto x86_l_708;
	case 1804ULL: goto x86_l_70c;
	case 1809ULL: goto x86_l_711;
	case 1811ULL: goto x86_l_713;
	case 1813ULL: goto x86_l_715;
	case 1819ULL: goto x86_l_71b;
	case 1823ULL: goto x86_l_71f;
	case 1829ULL: goto x86_l_725;
	case 1832ULL: goto x86_l_728;
	case 1836ULL: goto x86_l_72c;
	case 1840ULL: goto x86_l_730;
	case 1845ULL: goto x86_l_735;
	case 1851ULL: goto x86_l_73b;
	case 1856ULL: goto x86_l_740;
	case 1861ULL: goto x86_l_745;
	case 1864ULL: goto x86_l_748;
	case 1868ULL: goto x86_l_74c;
	case 1873ULL: goto x86_l_751;
	case 1875ULL: goto x86_l_753;
	case 1877ULL: goto x86_l_755;
	case 1883ULL: goto x86_l_75b;
	case 1889ULL: goto x86_l_761;
	case 1894ULL: goto x86_l_766;
	case 1900ULL: goto x86_l_76c;
	case 1905ULL: goto x86_l_771;
	case 1913ULL: goto x86_l_779;
	case 1916ULL: goto x86_l_77c;
	case 1918ULL: goto x86_l_77e;
	case 1923ULL: goto x86_l_783;
	case 1928ULL: goto x86_l_788;
	case 1931ULL: goto x86_l_78b;
	case 1933ULL: goto x86_l_78d;
	case 1935ULL: goto x86_l_78f;
	case 1940ULL: goto x86_l_794;
	case 1943ULL: goto x86_l_797;
	case 1945ULL: goto x86_l_799;
	case 1950ULL: goto x86_l_79e;
	case 1955ULL: goto x86_l_7a3;
	case 1958ULL: goto x86_l_7a6;
	case 1960ULL: goto x86_l_7a8;
	case 1962ULL: goto x86_l_7aa;
	case 1970ULL: goto x86_l_7b2;
	case 1973ULL: goto x86_l_7b5;
	case 1975ULL: goto x86_l_7b7;
	case 1980ULL: goto x86_l_7bc;
	case 1985ULL: goto x86_l_7c1;
	case 1988ULL: goto x86_l_7c4;
	case 1990ULL: goto x86_l_7c6;
	case 1992ULL: goto x86_l_7c8;
	case 1997ULL: goto x86_l_7cd;
	case 2000ULL: goto x86_l_7d0;
	case 2002ULL: goto x86_l_7d2;
	case 2007ULL: goto x86_l_7d7;
	case 2012ULL: goto x86_l_7dc;
	case 2015ULL: goto x86_l_7df;
	case 2017ULL: goto x86_l_7e1;
	case 2020ULL: goto x86_l_7e4;
	case 2022ULL: goto x86_l_7e6;
	case 2024ULL: goto x86_l_7e8;
	case 2029ULL: goto x86_l_7ed;
	case 2031ULL: goto x86_l_7ef;
	case 2036ULL: goto x86_l_7f4;
	case 2040ULL: goto x86_l_7f8;
	case 2045ULL: goto x86_l_7fd;
	case 2047ULL: goto x86_l_7ff;
	case 2050ULL: goto x86_l_802;
	case 2055ULL: goto x86_l_807;
	case 2061ULL: goto x86_l_80d;
	case 2068ULL: goto x86_l_814;
	case 2071ULL: goto x86_l_817;
	case 2074ULL: goto x86_l_81a;
	case 2077ULL: goto x86_l_81d;
	case 2081ULL: goto x86_l_821;
	case 2085ULL: goto x86_l_825;
	case 2087ULL: goto x86_l_827;
	case 2093ULL: goto x86_l_82d;
	case 2096ULL: goto x86_l_830;
	case 2098ULL: goto x86_l_832;
	case 2103ULL: goto x86_l_837;
	case 2108ULL: goto x86_l_83c;
	case 2111ULL: goto x86_l_83f;
	case 2115ULL: goto x86_l_843;
	case 2120ULL: goto x86_l_848;
	case 2122ULL: goto x86_l_84a;
	case 2124ULL: goto x86_l_84c;
	case 2130ULL: goto x86_l_852;
	case 2135ULL: goto x86_l_857;
	case 2141ULL: goto x86_l_85d;
	case 2144ULL: goto x86_l_860;
	case 2148ULL: goto x86_l_864;
	case 2152ULL: goto x86_l_868;
	case 2157ULL: goto x86_l_86d;
	case 2159ULL: goto x86_l_86f;
	case 2164ULL: goto x86_l_874;
	case 2169ULL: goto x86_l_879;
	case 2172ULL: goto x86_l_87c;
	case 2176ULL: goto x86_l_880;
	case 2181ULL: goto x86_l_885;
	case 2183ULL: goto x86_l_887;
	case 2185ULL: goto x86_l_889;
	case 2191ULL: goto x86_l_88f;
	case 2196ULL: goto x86_l_894;
	case 2202ULL: goto x86_l_89a;
	case 2205ULL: goto x86_l_89d;
	case 2209ULL: goto x86_l_8a1;
	case 2213ULL: goto x86_l_8a5;
	case 2218ULL: goto x86_l_8aa;
	case 2220ULL: goto x86_l_8ac;
	case 2225ULL: goto x86_l_8b1;
	case 2230ULL: goto x86_l_8b6;
	case 2233ULL: goto x86_l_8b9;
	case 2237ULL: goto x86_l_8bd;
	case 2242ULL: goto x86_l_8c2;
	case 2244ULL: goto x86_l_8c4;
	case 2246ULL: goto x86_l_8c6;
	case 2252ULL: goto x86_l_8cc;
	case 2257ULL: goto x86_l_8d1;
	case 2263ULL: goto x86_l_8d7;
	case 2266ULL: goto x86_l_8da;
	case 2270ULL: goto x86_l_8de;
	case 2274ULL: goto x86_l_8e2;
	case 2279ULL: goto x86_l_8e7;
	case 2281ULL: goto x86_l_8e9;
	case 2286ULL: goto x86_l_8ee;
	case 2291ULL: goto x86_l_8f3;
	case 2294ULL: goto x86_l_8f6;
	case 2298ULL: goto x86_l_8fa;
	case 2303ULL: goto x86_l_8ff;
	case 2305ULL: goto x86_l_901;
	case 2307ULL: goto x86_l_903;
	case 2313ULL: goto x86_l_909;
	case 2318ULL: goto x86_l_90e;
	case 2324ULL: goto x86_l_914;
	case 2327ULL: goto x86_l_917;
	case 2331ULL: goto x86_l_91b;
	case 2335ULL: goto x86_l_91f;
	case 2340ULL: goto x86_l_924;
	case 2342ULL: goto x86_l_926;
	case 2347ULL: goto x86_l_92b;
	case 2352ULL: goto x86_l_930;
	case 2355ULL: goto x86_l_933;
	case 2359ULL: goto x86_l_937;
	case 2364ULL: goto x86_l_93c;
	case 2366ULL: goto x86_l_93e;
	case 2368ULL: goto x86_l_940;
	case 2374ULL: goto x86_l_946;
	case 2379ULL: goto x86_l_94b;
	case 2385ULL: goto x86_l_951;
	case 2388ULL: goto x86_l_954;
	case 2392ULL: goto x86_l_958;
	case 2396ULL: goto x86_l_95c;
	case 2401ULL: goto x86_l_961;
	case 2403ULL: goto x86_l_963;
	case 2408ULL: goto x86_l_968;
	case 2413ULL: goto x86_l_96d;
	case 2416ULL: goto x86_l_970;
	case 2420ULL: goto x86_l_974;
	case 2425ULL: goto x86_l_979;
	case 2427ULL: goto x86_l_97b;
	case 2429ULL: goto x86_l_97d;
	case 2435ULL: goto x86_l_983;
	case 2440ULL: goto x86_l_988;
	case 2446ULL: goto x86_l_98e;
	case 2449ULL: goto x86_l_991;
	case 2453ULL: goto x86_l_995;
	case 2457ULL: goto x86_l_999;
	case 2462ULL: goto x86_l_99e;
	case 2464ULL: goto x86_l_9a0;
	case 2469ULL: goto x86_l_9a5;
	case 2474ULL: goto x86_l_9aa;
	case 2477ULL: goto x86_l_9ad;
	case 2481ULL: goto x86_l_9b1;
	case 2486ULL: goto x86_l_9b6;
	case 2488ULL: goto x86_l_9b8;
	case 2490ULL: goto x86_l_9ba;
	case 2496ULL: goto x86_l_9c0;
	case 2501ULL: goto x86_l_9c5;
	case 2507ULL: goto x86_l_9cb;
	case 2510ULL: goto x86_l_9ce;
	case 2514ULL: goto x86_l_9d2;
	case 2518ULL: goto x86_l_9d6;
	case 2523ULL: goto x86_l_9db;
	case 2525ULL: goto x86_l_9dd;
	case 2530ULL: goto x86_l_9e2;
	case 2535ULL: goto x86_l_9e7;
	case 2538ULL: goto x86_l_9ea;
	case 2542ULL: goto x86_l_9ee;
	case 2547ULL: goto x86_l_9f3;
	case 2549ULL: goto x86_l_9f5;
	case 2551ULL: goto x86_l_9f7;
	case 2557ULL: goto x86_l_9fd;
	case 2562ULL: goto x86_l_a02;
	case 2568ULL: goto x86_l_a08;
	case 2571ULL: goto x86_l_a0b;
	case 2575ULL: goto x86_l_a0f;
	case 2579ULL: goto x86_l_a13;
	case 2584ULL: goto x86_l_a18;
	case 2586ULL: goto x86_l_a1a;
	case 2591ULL: goto x86_l_a1f;
	case 2596ULL: goto x86_l_a24;
	case 2599ULL: goto x86_l_a27;
	case 2603ULL: goto x86_l_a2b;
	case 2608ULL: goto x86_l_a30;
	case 2610ULL: goto x86_l_a32;
	case 2612ULL: goto x86_l_a34;
	case 2618ULL: goto x86_l_a3a;
	case 2622ULL: goto x86_l_a3e;
	case 2628ULL: goto x86_l_a44;
	case 2631ULL: goto x86_l_a47;
	case 2635ULL: goto x86_l_a4b;
	case 2639ULL: goto x86_l_a4f;
	case 2644ULL: goto x86_l_a54;
	case 2650ULL: goto x86_l_a5a;
	case 2655ULL: goto x86_l_a5f;
	case 2660ULL: goto x86_l_a64;
	case 2663ULL: goto x86_l_a67;
	case 2668ULL: goto x86_l_a6c;
	case 2671ULL: goto x86_l_a6f;
	case 2673ULL: goto x86_l_a71;
	case 2678ULL: goto x86_l_a76;
	case 2683ULL: goto x86_l_a7b;
	case 2686ULL: goto x86_l_a7e;
	case 2690ULL: goto x86_l_a82;
	case 2695ULL: goto x86_l_a87;
	case 2697ULL: goto x86_l_a89;
	case 2699ULL: goto x86_l_a8b;
	case 2705ULL: goto x86_l_a91;
	case 2710ULL: goto x86_l_a96;
	case 2716ULL: goto x86_l_a9c;
	case 2719ULL: goto x86_l_a9f;
	case 2723ULL: goto x86_l_aa3;
	case 2727ULL: goto x86_l_aa7;
	case 2732ULL: goto x86_l_aac;
	case 2734ULL: goto x86_l_aae;
	case 2739ULL: goto x86_l_ab3;
	case 2744ULL: goto x86_l_ab8;
	case 2747ULL: goto x86_l_abb;
	case 2751ULL: goto x86_l_abf;
	case 2756ULL: goto x86_l_ac4;
	case 2758ULL: goto x86_l_ac6;
	case 2760ULL: goto x86_l_ac8;
	case 2766ULL: goto x86_l_ace;
	case 2771ULL: goto x86_l_ad3;
	case 2777ULL: goto x86_l_ad9;
	case 2780ULL: goto x86_l_adc;
	case 2784ULL: goto x86_l_ae0;
	case 2788ULL: goto x86_l_ae4;
	case 2793ULL: goto x86_l_ae9;
	case 2795ULL: goto x86_l_aeb;
	case 2800ULL: goto x86_l_af0;
	case 2805ULL: goto x86_l_af5;
	case 2808ULL: goto x86_l_af8;
	case 2812ULL: goto x86_l_afc;
	case 2817ULL: goto x86_l_b01;
	case 2819ULL: goto x86_l_b03;
	case 2821ULL: goto x86_l_b05;
	case 2827ULL: goto x86_l_b0b;
	case 2832ULL: goto x86_l_b10;
	case 2838ULL: goto x86_l_b16;
	case 2841ULL: goto x86_l_b19;
	case 2845ULL: goto x86_l_b1d;
	case 2849ULL: goto x86_l_b21;
	case 2854ULL: goto x86_l_b26;
	case 2856ULL: goto x86_l_b28;
	case 2861ULL: goto x86_l_b2d;
	case 2866ULL: goto x86_l_b32;
	case 2869ULL: goto x86_l_b35;
	case 2873ULL: goto x86_l_b39;
	case 2878ULL: goto x86_l_b3e;
	case 2880ULL: goto x86_l_b40;
	case 2882ULL: goto x86_l_b42;
	case 2888ULL: goto x86_l_b48;
	case 2893ULL: goto x86_l_b4d;
	case 2899ULL: goto x86_l_b53;
	case 2902ULL: goto x86_l_b56;
	case 2906ULL: goto x86_l_b5a;
	case 2910ULL: goto x86_l_b5e;
	case 2915ULL: goto x86_l_b63;
	case 2917ULL: goto x86_l_b65;
	case 2922ULL: goto x86_l_b6a;
	case 2927ULL: goto x86_l_b6f;
	case 2930ULL: goto x86_l_b72;
	case 2934ULL: goto x86_l_b76;
	case 2939ULL: goto x86_l_b7b;
	case 2941ULL: goto x86_l_b7d;
	case 2943ULL: goto x86_l_b7f;
	case 2949ULL: goto x86_l_b85;
	case 2954ULL: goto x86_l_b8a;
	case 2960ULL: goto x86_l_b90;
	case 2963ULL: goto x86_l_b93;
	case 2967ULL: goto x86_l_b97;
	case 2971ULL: goto x86_l_b9b;
	case 2976ULL: goto x86_l_ba0;
	case 2978ULL: goto x86_l_ba2;
	case 2983ULL: goto x86_l_ba7;
	case 2988ULL: goto x86_l_bac;
	case 2991ULL: goto x86_l_baf;
	case 2995ULL: goto x86_l_bb3;
	case 3000ULL: goto x86_l_bb8;
	case 3002ULL: goto x86_l_bba;
	case 3004ULL: goto x86_l_bbc;
	case 3010ULL: goto x86_l_bc2;
	case 3015ULL: goto x86_l_bc7;
	case 3021ULL: goto x86_l_bcd;
	case 3024ULL: goto x86_l_bd0;
	case 3028ULL: goto x86_l_bd4;
	case 3032ULL: goto x86_l_bd8;
	case 3037ULL: goto x86_l_bdd;
	case 3039ULL: goto x86_l_bdf;
	case 3044ULL: goto x86_l_be4;
	case 3049ULL: goto x86_l_be9;
	case 3052ULL: goto x86_l_bec;
	case 3056ULL: goto x86_l_bf0;
	case 3061ULL: goto x86_l_bf5;
	case 3063ULL: goto x86_l_bf7;
	case 3065ULL: goto x86_l_bf9;
	case 3071ULL: goto x86_l_bff;
	case 3076ULL: goto x86_l_c04;
	case 3082ULL: goto x86_l_c0a;
	case 3085ULL: goto x86_l_c0d;
	case 3089ULL: goto x86_l_c11;
	case 3093ULL: goto x86_l_c15;
	case 3098ULL: goto x86_l_c1a;
	case 3100ULL: goto x86_l_c1c;
	case 3105ULL: goto x86_l_c21;
	case 3110ULL: goto x86_l_c26;
	case 3113ULL: goto x86_l_c29;
	case 3117ULL: goto x86_l_c2d;
	case 3122ULL: goto x86_l_c32;
	case 3124ULL: goto x86_l_c34;
	case 3126ULL: goto x86_l_c36;
	case 3132ULL: goto x86_l_c3c;
	case 3137ULL: goto x86_l_c41;
	case 3143ULL: goto x86_l_c47;
	case 3146ULL: goto x86_l_c4a;
	case 3150ULL: goto x86_l_c4e;
	case 3154ULL: goto x86_l_c52;
	case 3159ULL: goto x86_l_c57;
	case 3161ULL: goto x86_l_c59;
	case 3166ULL: goto x86_l_c5e;
	case 3171ULL: goto x86_l_c63;
	case 3174ULL: goto x86_l_c66;
	case 3178ULL: goto x86_l_c6a;
	case 3183ULL: goto x86_l_c6f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_664:
	/* 0x664: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_669:
	/* 0x669: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_66f:
	/* 0x66f: mov    ecx,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_672:
	/* 0x672: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_676:
	/* 0x676: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67a:
	/* 0x67a: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_67f:
	/* 0x67f: je     6a1 <generic_sleepable_preload+0x6a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6a1;
	}
x86_l_681:
	/* 0x681: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_686:
	/* 0x686: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_68b:
	/* 0x68b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_68e:
	/* 0x68e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_692:
	/* 0x692: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_697:
	/* 0x697: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_699:
	/* 0x699: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_69b:
	/* 0x69b: js     d27 <generic_sleepable_preload+0xd27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3367ULL;
	}
x86_l_6a1:
	/* 0x6a1: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_6a6:
	/* 0x6a6: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_6ac:
	/* 0x6ac: mov    ecx,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_6af:
	/* 0x6af: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_6b3:
	/* 0x6b3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6b7:
	/* 0x6b7: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_6bc:
	/* 0x6bc: je     6de <generic_sleepable_preload+0x6de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6de;
	}
x86_l_6be:
	/* 0x6be: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_6c3:
	/* 0x6c3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6c8:
	/* 0x6c8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6cb:
	/* 0x6cb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6cf:
	/* 0x6cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6d4:
	/* 0x6d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d6:
	/* 0x6d6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6d8:
	/* 0x6d8: js     ec5 <generic_sleepable_preload+0xec5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3781ULL;
	}
x86_l_6de:
	/* 0x6de: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_6e3:
	/* 0x6e3: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_6e9:
	/* 0x6e9: mov    ecx,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_6ec:
	/* 0x6ec: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_6f0:
	/* 0x6f0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6f4:
	/* 0x6f4: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_6f9:
	/* 0x6f9: je     71b <generic_sleepable_preload+0x71b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_71b;
	}
x86_l_6fb:
	/* 0x6fb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_700:
	/* 0x700: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_705:
	/* 0x705: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_708:
	/* 0x708: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_70c:
	/* 0x70c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_711:
	/* 0x711: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_713:
	/* 0x713: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_715:
	/* 0x715: js     ee9 <generic_sleepable_preload+0xee9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3817ULL;
	}
x86_l_71b:
	/* 0x71b: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_71f:
	/* 0x71f: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_725:
	/* 0x725: mov    ecx,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_728:
	/* 0x728: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_72c:
	/* 0x72c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_730:
	/* 0x730: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_735:
	/* 0x735: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_73b:
	/* 0x73b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_740:
	/* 0x740: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_745:
	/* 0x745: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_748:
	/* 0x748: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_74c:
	/* 0x74c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_751:
	/* 0x751: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_753:
	/* 0x753: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_755:
	/* 0x755: jns    d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 3375ULL;
	}
x86_l_75b:
	/* 0x75b: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_761:
	/* 0x761: jmp    d2d <generic_sleepable_preload+0xd2d> */
	return 3373ULL;
x86_l_766:
	/* 0x766: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_76c:
	/* 0x76c: jmp    d2d <generic_sleepable_preload+0xd2d> */
	return 3373ULL;
x86_l_771:
	/* 0x771: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_779:
	/* 0x779: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_77c:
	/* 0x77c: je     7e1 <generic_sleepable_preload+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e1;
	}
x86_l_77e:
	/* 0x77e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_783:
	/* 0x783: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_788:
	/* 0x788: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_78b:
	/* 0x78b: je     7e1 <generic_sleepable_preload+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e1;
	}
x86_l_78d:
	/* 0x78d: jmp    7f4 <generic_sleepable_preload+0x7f4> */
	goto x86_l_7f4;
x86_l_78f:
	/* 0x78f: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_794:
	/* 0x794: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_797:
	/* 0x797: je     7e1 <generic_sleepable_preload+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e1;
	}
x86_l_799:
	/* 0x799: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_79e:
	/* 0x79e: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_7a3:
	/* 0x7a3: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_7a6:
	/* 0x7a6: je     7e1 <generic_sleepable_preload+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e1;
	}
x86_l_7a8:
	/* 0x7a8: jmp    7f4 <generic_sleepable_preload+0x7f4> */
	goto x86_l_7f4;
x86_l_7aa:
	/* 0x7aa: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_7b2:
	/* 0x7b2: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_7b5:
	/* 0x7b5: je     7e1 <generic_sleepable_preload+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e1;
	}
x86_l_7b7:
	/* 0x7b7: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_7bc:
	/* 0x7bc: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_7c1:
	/* 0x7c1: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_7c4:
	/* 0x7c4: je     7e1 <generic_sleepable_preload+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e1;
	}
x86_l_7c6:
	/* 0x7c6: jmp    7f4 <generic_sleepable_preload+0x7f4> */
	goto x86_l_7f4;
x86_l_7c8:
	/* 0x7c8: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7cd:
	/* 0x7cd: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_7d0:
	/* 0x7d0: je     7e1 <generic_sleepable_preload+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e1;
	}
x86_l_7d2:
	/* 0x7d2: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7d7:
	/* 0x7d7: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_7dc:
	/* 0x7dc: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_7df:
	/* 0x7df: jne    7f4 <generic_sleepable_preload+0x7f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7f4;
	}
x86_l_7e1:
	/* 0x7e1: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_7e4:
	/* 0x7e4: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_7e6:
	/* 0x7e6: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_7e8:
	/* 0x7e8: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_7ed:
	/* 0x7ed: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_7ef:
	/* 0x7ef: bzhi   rsi,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RSI, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_7f4:
	/* 0x7f4: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7f8:
	/* 0x7f8: mov    r12d,DWORD PTR [r12+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_7fd:
	/* 0x7fd: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7ff:
	/* 0x7ff: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_802:
	/* 0x802: cmp    WORD PTR [rbx-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743764471906304ULL);
x86_l_807:
	/* 0x807: je     e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3600ULL;
	}
x86_l_80d:
	/* 0x80d: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_814:
	/* 0x814: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_817:
	/* 0x817: mov    eax,DWORD PTR [rbx-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551538ULL);
x86_l_81a:
	/* 0x81a: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_81d:
	/* 0x81d: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_821:
	/* 0x821: movzx  eax,WORD PTR [rbx-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_825:
	/* 0x825: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_827:
	/* 0x827: je     a6c <generic_sleepable_preload+0xa6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6c;
	}
x86_l_82d:
	/* 0x82d: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_830:
	/* 0x830: je     852 <generic_sleepable_preload+0x852> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_852;
	}
x86_l_832:
	/* 0x832: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_837:
	/* 0x837: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_83c:
	/* 0x83c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_83f:
	/* 0x83f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_843:
	/* 0x843: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_848:
	/* 0x848: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_84a:
	/* 0x84a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_84c:
	/* 0x84c: js     cc3 <generic_sleepable_preload+0xcc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3267ULL;
	}
x86_l_852:
	/* 0x852: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_857:
	/* 0x857: je     e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3600ULL;
	}
x86_l_85d:
	/* 0x85d: mov    ecx,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_860:
	/* 0x860: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_864:
	/* 0x864: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_868:
	/* 0x868: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_86d:
	/* 0x86d: je     88f <generic_sleepable_preload+0x88f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_88f;
	}
x86_l_86f:
	/* 0x86f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_874:
	/* 0x874: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_879:
	/* 0x879: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_87c:
	/* 0x87c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_880:
	/* 0x880: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_885:
	/* 0x885: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_887:
	/* 0x887: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_889:
	/* 0x889: js     cd5 <generic_sleepable_preload+0xcd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3285ULL;
	}
x86_l_88f:
	/* 0x88f: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_894:
	/* 0x894: je     e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3600ULL;
	}
x86_l_89a:
	/* 0x89a: mov    ecx,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_89d:
	/* 0x89d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_8a1:
	/* 0x8a1: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8a5:
	/* 0x8a5: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_8aa:
	/* 0x8aa: je     8cc <generic_sleepable_preload+0x8cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8cc;
	}
x86_l_8ac:
	/* 0x8ac: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8b1:
	/* 0x8b1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_8b6:
	/* 0x8b6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8b9:
	/* 0x8b9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8bd:
	/* 0x8bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8c2:
	/* 0x8c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c4:
	/* 0x8c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8c6:
	/* 0x8c6: js     ce7 <generic_sleepable_preload+0xce7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3303ULL;
	}
x86_l_8cc:
	/* 0x8cc: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_8d1:
	/* 0x8d1: je     e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3600ULL;
	}
x86_l_8d7:
	/* 0x8d7: mov    ecx,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_8da:
	/* 0x8da: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_8de:
	/* 0x8de: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8e2:
	/* 0x8e2: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_8e7:
	/* 0x8e7: je     909 <generic_sleepable_preload+0x909> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_909;
	}
x86_l_8e9:
	/* 0x8e9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8ee:
	/* 0x8ee: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_8f3:
	/* 0x8f3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8f6:
	/* 0x8f6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
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
	/* 0x903: js     cf9 <generic_sleepable_preload+0xcf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3321ULL;
	}
x86_l_909:
	/* 0x909: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_90e:
	/* 0x90e: je     e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3600ULL;
	}
x86_l_914:
	/* 0x914: mov    ecx,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_917:
	/* 0x917: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_91b:
	/* 0x91b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_91f:
	/* 0x91f: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_924:
	/* 0x924: je     946 <generic_sleepable_preload+0x946> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_946;
	}
x86_l_926:
	/* 0x926: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_92b:
	/* 0x92b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_930:
	/* 0x930: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_933:
	/* 0x933: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_937:
	/* 0x937: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_93c:
	/* 0x93c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_93e:
	/* 0x93e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_940:
	/* 0x940: js     d0b <generic_sleepable_preload+0xd0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3339ULL;
	}
x86_l_946:
	/* 0x946: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_94b:
	/* 0x94b: je     e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3600ULL;
	}
x86_l_951:
	/* 0x951: mov    ecx,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_954:
	/* 0x954: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_958:
	/* 0x958: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_95c:
	/* 0x95c: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_961:
	/* 0x961: je     983 <generic_sleepable_preload+0x983> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_983;
	}
x86_l_963:
	/* 0x963: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_968:
	/* 0x968: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_96d:
	/* 0x96d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_970:
	/* 0x970: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_974:
	/* 0x974: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_979:
	/* 0x979: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_97b:
	/* 0x97b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_97d:
	/* 0x97d: js     d1d <generic_sleepable_preload+0xd1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3357ULL;
	}
x86_l_983:
	/* 0x983: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_988:
	/* 0x988: je     e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3600ULL;
	}
x86_l_98e:
	/* 0x98e: mov    ecx,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_991:
	/* 0x991: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_995:
	/* 0x995: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_999:
	/* 0x999: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_99e:
	/* 0x99e: je     9c0 <generic_sleepable_preload+0x9c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9c0;
	}
x86_l_9a0:
	/* 0x9a0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_9a5:
	/* 0x9a5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_9aa:
	/* 0x9aa: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_9ad:
	/* 0x9ad: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9b1:
	/* 0x9b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9b6:
	/* 0x9b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b8:
	/* 0x9b8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9ba:
	/* 0x9ba: js     e08 <generic_sleepable_preload+0xe08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3592ULL;
	}
x86_l_9c0:
	/* 0x9c0: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_9c5:
	/* 0x9c5: je     e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3600ULL;
	}
x86_l_9cb:
	/* 0x9cb: mov    ecx,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_9ce:
	/* 0x9ce: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_9d2:
	/* 0x9d2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9d6:
	/* 0x9d6: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_9db:
	/* 0x9db: je     9fd <generic_sleepable_preload+0x9fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9fd;
	}
x86_l_9dd:
	/* 0x9dd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_9e2:
	/* 0x9e2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_9e7:
	/* 0x9e7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_9ea:
	/* 0x9ea: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9ee:
	/* 0x9ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9f3:
	/* 0x9f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f5:
	/* 0x9f5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9f7:
	/* 0x9f7: js     ed2 <generic_sleepable_preload+0xed2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3794ULL;
	}
x86_l_9fd:
	/* 0x9fd: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_a02:
	/* 0xa02: je     e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3600ULL;
	}
x86_l_a08:
	/* 0xa08: mov    ecx,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_a0b:
	/* 0xa0b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_a0f:
	/* 0xa0f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a13:
	/* 0xa13: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_a18:
	/* 0xa18: je     a3a <generic_sleepable_preload+0xa3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a3a;
	}
x86_l_a1a:
	/* 0xa1a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a1f:
	/* 0xa1f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a24:
	/* 0xa24: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a27:
	/* 0xa27: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a2b:
	/* 0xa2b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a30:
	/* 0xa30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a32:
	/* 0xa32: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a34:
	/* 0xa34: js     ef4 <generic_sleepable_preload+0xef4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3828ULL;
	}
x86_l_a3a:
	/* 0xa3a: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a3e:
	/* 0xa3e: je     e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3600ULL;
	}
x86_l_a44:
	/* 0xa44: mov    ecx,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_a47:
	/* 0xa47: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_a4b:
	/* 0xa4b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a4f:
	/* 0xa4f: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_a54:
	/* 0xa54: je     e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3600ULL;
	}
x86_l_a5a:
	/* 0xa5a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a5f:
	/* 0xa5f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a64:
	/* 0xa64: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a67:
	/* 0xa67: jmp    ca6 <generic_sleepable_preload+0xca6> */
	return 3238ULL;
x86_l_a6c:
	/* 0xa6c: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_a6f:
	/* 0xa6f: je     a91 <generic_sleepable_preload+0xa91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a91;
	}
x86_l_a71:
	/* 0xa71: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a76:
	/* 0xa76: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a7b:
	/* 0xa7b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a7e:
	/* 0xa7e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a82:
	/* 0xa82: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a87:
	/* 0xa87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a89:
	/* 0xa89: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a8b:
	/* 0xa8b: js     cc3 <generic_sleepable_preload+0xcc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3267ULL;
	}
x86_l_a91:
	/* 0xa91: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_a96:
	/* 0xa96: je     e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3600ULL;
	}
x86_l_a9c:
	/* 0xa9c: mov    ecx,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_a9f:
	/* 0xa9f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_aa3:
	/* 0xaa3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aa7:
	/* 0xaa7: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_aac:
	/* 0xaac: je     ace <generic_sleepable_preload+0xace> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ace;
	}
x86_l_aae:
	/* 0xaae: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ab3:
	/* 0xab3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ab8:
	/* 0xab8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_abb:
	/* 0xabb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_abf:
	/* 0xabf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ac4:
	/* 0xac4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac6:
	/* 0xac6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ac8:
	/* 0xac8: js     cd5 <generic_sleepable_preload+0xcd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3285ULL;
	}
x86_l_ace:
	/* 0xace: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_ad3:
	/* 0xad3: je     e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3600ULL;
	}
x86_l_ad9:
	/* 0xad9: mov    ecx,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_adc:
	/* 0xadc: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_ae0:
	/* 0xae0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ae4:
	/* 0xae4: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_ae9:
	/* 0xae9: je     b0b <generic_sleepable_preload+0xb0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b0b;
	}
x86_l_aeb:
	/* 0xaeb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_af0:
	/* 0xaf0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_af5:
	/* 0xaf5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_af8:
	/* 0xaf8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_afc:
	/* 0xafc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b01:
	/* 0xb01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b03:
	/* 0xb03: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b05:
	/* 0xb05: js     ce7 <generic_sleepable_preload+0xce7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3303ULL;
	}
x86_l_b0b:
	/* 0xb0b: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_b10:
	/* 0xb10: je     e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3600ULL;
	}
x86_l_b16:
	/* 0xb16: mov    ecx,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_b19:
	/* 0xb19: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_b1d:
	/* 0xb1d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b21:
	/* 0xb21: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_b26:
	/* 0xb26: je     b48 <generic_sleepable_preload+0xb48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b48;
	}
x86_l_b28:
	/* 0xb28: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b2d:
	/* 0xb2d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b32:
	/* 0xb32: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b35:
	/* 0xb35: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b39:
	/* 0xb39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b3e:
	/* 0xb3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b40:
	/* 0xb40: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b42:
	/* 0xb42: js     cf9 <generic_sleepable_preload+0xcf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3321ULL;
	}
x86_l_b48:
	/* 0xb48: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_b4d:
	/* 0xb4d: je     e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3600ULL;
	}
x86_l_b53:
	/* 0xb53: mov    ecx,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_b56:
	/* 0xb56: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_b5a:
	/* 0xb5a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b5e:
	/* 0xb5e: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_b63:
	/* 0xb63: je     b85 <generic_sleepable_preload+0xb85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b85;
	}
x86_l_b65:
	/* 0xb65: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b6a:
	/* 0xb6a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b6f:
	/* 0xb6f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b72:
	/* 0xb72: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b76:
	/* 0xb76: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b7b:
	/* 0xb7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b7d:
	/* 0xb7d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b7f:
	/* 0xb7f: js     d0b <generic_sleepable_preload+0xd0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3339ULL;
	}
x86_l_b85:
	/* 0xb85: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_b8a:
	/* 0xb8a: je     e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3600ULL;
	}
x86_l_b90:
	/* 0xb90: mov    ecx,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_b93:
	/* 0xb93: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_b97:
	/* 0xb97: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b9b:
	/* 0xb9b: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_ba0:
	/* 0xba0: je     bc2 <generic_sleepable_preload+0xbc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bc2;
	}
x86_l_ba2:
	/* 0xba2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ba7:
	/* 0xba7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_bac:
	/* 0xbac: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_baf:
	/* 0xbaf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bb3:
	/* 0xbb3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bb8:
	/* 0xbb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bba:
	/* 0xbba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bbc:
	/* 0xbbc: js     d1d <generic_sleepable_preload+0xd1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3357ULL;
	}
x86_l_bc2:
	/* 0xbc2: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_bc7:
	/* 0xbc7: je     e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3600ULL;
	}
x86_l_bcd:
	/* 0xbcd: mov    ecx,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_bd0:
	/* 0xbd0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_bd4:
	/* 0xbd4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bd8:
	/* 0xbd8: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_bdd:
	/* 0xbdd: je     bff <generic_sleepable_preload+0xbff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bff;
	}
x86_l_bdf:
	/* 0xbdf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_be4:
	/* 0xbe4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_be9:
	/* 0xbe9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_bec:
	/* 0xbec: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bf0:
	/* 0xbf0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bf5:
	/* 0xbf5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf7:
	/* 0xbf7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bf9:
	/* 0xbf9: js     e08 <generic_sleepable_preload+0xe08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3592ULL;
	}
x86_l_bff:
	/* 0xbff: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_c04:
	/* 0xc04: je     e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3600ULL;
	}
x86_l_c0a:
	/* 0xc0a: mov    ecx,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_c0d:
	/* 0xc0d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_c11:
	/* 0xc11: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c15:
	/* 0xc15: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_c1a:
	/* 0xc1a: je     c3c <generic_sleepable_preload+0xc3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c3c;
	}
x86_l_c1c:
	/* 0xc1c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c21:
	/* 0xc21: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c26:
	/* 0xc26: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c29:
	/* 0xc29: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c2d:
	/* 0xc2d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c32:
	/* 0xc32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c34:
	/* 0xc34: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c36:
	/* 0xc36: js     ed2 <generic_sleepable_preload+0xed2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3794ULL;
	}
x86_l_c3c:
	/* 0xc3c: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_c41:
	/* 0xc41: je     e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3600ULL;
	}
x86_l_c47:
	/* 0xc47: mov    ecx,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_c4a:
	/* 0xc4a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_c4e:
	/* 0xc4e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c52:
	/* 0xc52: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_c57:
	/* 0xc57: je     c79 <generic_sleepable_preload+0xc79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3193ULL;
	}
x86_l_c59:
	/* 0xc59: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c5e:
	/* 0xc5e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c63:
	/* 0xc63: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c66:
	/* 0xc66: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c6a:
	/* 0xc6a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c6f:
	/* 0xc6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 3185ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3185ULL: goto x86_l_c71;
	case 3187ULL: goto x86_l_c73;
	case 3193ULL: goto x86_l_c79;
	case 3197ULL: goto x86_l_c7d;
	case 3203ULL: goto x86_l_c83;
	case 3206ULL: goto x86_l_c86;
	case 3210ULL: goto x86_l_c8a;
	case 3214ULL: goto x86_l_c8e;
	case 3219ULL: goto x86_l_c93;
	case 3225ULL: goto x86_l_c99;
	case 3230ULL: goto x86_l_c9e;
	case 3235ULL: goto x86_l_ca3;
	case 3238ULL: goto x86_l_ca6;
	case 3242ULL: goto x86_l_caa;
	case 3247ULL: goto x86_l_caf;
	case 3249ULL: goto x86_l_cb1;
	case 3251ULL: goto x86_l_cb3;
	case 3257ULL: goto x86_l_cb9;
	case 3262ULL: goto x86_l_cbe;
	case 3267ULL: goto x86_l_cc3;
	case 3272ULL: goto x86_l_cc8;
	case 3277ULL: goto x86_l_ccd;
	case 3283ULL: goto x86_l_cd3;
	case 3285ULL: goto x86_l_cd5;
	case 3290ULL: goto x86_l_cda;
	case 3295ULL: goto x86_l_cdf;
	case 3301ULL: goto x86_l_ce5;
	case 3303ULL: goto x86_l_ce7;
	case 3308ULL: goto x86_l_cec;
	case 3313ULL: goto x86_l_cf1;
	case 3319ULL: goto x86_l_cf7;
	case 3321ULL: goto x86_l_cf9;
	case 3326ULL: goto x86_l_cfe;
	case 3331ULL: goto x86_l_d03;
	case 3337ULL: goto x86_l_d09;
	case 3339ULL: goto x86_l_d0b;
	case 3344ULL: goto x86_l_d10;
	case 3349ULL: goto x86_l_d15;
	case 3355ULL: goto x86_l_d1b;
	case 3357ULL: goto x86_l_d1d;
	case 3362ULL: goto x86_l_d22;
	case 3367ULL: goto x86_l_d27;
	case 3373ULL: goto x86_l_d2d;
	case 3375ULL: goto x86_l_d2f;
	case 3380ULL: goto x86_l_d34;
	case 3385ULL: goto x86_l_d39;
	case 3390ULL: goto x86_l_d3e;
	case 3393ULL: goto x86_l_d41;
	case 3398ULL: goto x86_l_d46;
	case 3401ULL: goto x86_l_d49;
	case 3403ULL: goto x86_l_d4b;
	case 3407ULL: goto x86_l_d4f;
	case 3413ULL: goto x86_l_d55;
	case 3417ULL: goto x86_l_d59;
	case 3425ULL: goto x86_l_d61;
	case 3430ULL: goto x86_l_d66;
	case 3432ULL: goto x86_l_d68;
	case 3437ULL: goto x86_l_d6d;
	case 3445ULL: goto x86_l_d75;
	case 3450ULL: goto x86_l_d7a;
	case 3457ULL: goto x86_l_d81;
	case 3462ULL: goto x86_l_d86;
	case 3464ULL: goto x86_l_d88;
	case 3467ULL: goto x86_l_d8b;
	case 3473ULL: goto x86_l_d91;
	case 3476ULL: goto x86_l_d94;
	case 3481ULL: goto x86_l_d99;
	case 3483ULL: goto x86_l_d9b;
	case 3490ULL: goto x86_l_da2;
	case 3493ULL: goto x86_l_da5;
	case 3496ULL: goto x86_l_da8;
	case 3501ULL: goto x86_l_dad;
	case 3504ULL: goto x86_l_db0;
	case 3507ULL: goto x86_l_db3;
	case 3509ULL: goto x86_l_db5;
	case 3511ULL: goto x86_l_db7;
	case 3516ULL: goto x86_l_dbc;
	case 3519ULL: goto x86_l_dbf;
	case 3522ULL: goto x86_l_dc2;
	case 3524ULL: goto x86_l_dc4;
	case 3527ULL: goto x86_l_dc7;
	case 3533ULL: goto x86_l_dcd;
	case 3536ULL: goto x86_l_dd0;
	case 3542ULL: goto x86_l_dd6;
	case 3546ULL: goto x86_l_dda;
	case 3551ULL: goto x86_l_ddf;
	case 3559ULL: goto x86_l_de7;
	case 3561ULL: goto x86_l_de9;
	case 3564ULL: goto x86_l_dec;
	case 3569ULL: goto x86_l_df1;
	case 3571ULL: goto x86_l_df3;
	case 3574ULL: goto x86_l_df6;
	case 3576ULL: goto x86_l_df8;
	case 3582ULL: goto x86_l_dfe;
	case 3587ULL: goto x86_l_e03;
	case 3592ULL: goto x86_l_e08;
	case 3597ULL: goto x86_l_e0d;
	case 3600ULL: goto x86_l_e10;
	case 3604ULL: goto x86_l_e14;
	case 3610ULL: goto x86_l_e1a;
	case 3614ULL: goto x86_l_e1e;
	case 3622ULL: goto x86_l_e26;
	case 3627ULL: goto x86_l_e2b;
	case 3629ULL: goto x86_l_e2d;
	case 3634ULL: goto x86_l_e32;
	case 3642ULL: goto x86_l_e3a;
	case 3647ULL: goto x86_l_e3f;
	case 3654ULL: goto x86_l_e46;
	case 3659ULL: goto x86_l_e4b;
	case 3661ULL: goto x86_l_e4d;
	case 3664ULL: goto x86_l_e50;
	case 3670ULL: goto x86_l_e56;
	case 3673ULL: goto x86_l_e59;
	case 3678ULL: goto x86_l_e5e;
	case 3680ULL: goto x86_l_e60;
	case 3687ULL: goto x86_l_e67;
	case 3690ULL: goto x86_l_e6a;
	case 3693ULL: goto x86_l_e6d;
	case 3698ULL: goto x86_l_e72;
	case 3701ULL: goto x86_l_e75;
	case 3704ULL: goto x86_l_e78;
	case 3706ULL: goto x86_l_e7a;
	case 3708ULL: goto x86_l_e7c;
	case 3713ULL: goto x86_l_e81;
	case 3716ULL: goto x86_l_e84;
	case 3719ULL: goto x86_l_e87;
	case 3721ULL: goto x86_l_e89;
	case 3724ULL: goto x86_l_e8c;
	case 3730ULL: goto x86_l_e92;
	case 3733ULL: goto x86_l_e95;
	case 3736ULL: goto x86_l_e98;
	case 3738ULL: goto x86_l_e9a;
	case 3742ULL: goto x86_l_e9e;
	case 3747ULL: goto x86_l_ea3;
	case 3755ULL: goto x86_l_eab;
	case 3757ULL: goto x86_l_ead;
	case 3762ULL: goto x86_l_eb2;
	case 3764ULL: goto x86_l_eb4;
	case 3766ULL: goto x86_l_eb6;
	case 3772ULL: goto x86_l_ebc;
	case 3776ULL: goto x86_l_ec0;
	case 3781ULL: goto x86_l_ec5;
	case 3783ULL: goto x86_l_ec7;
	case 3789ULL: goto x86_l_ecd;
	case 3794ULL: goto x86_l_ed2;
	case 3797ULL: goto x86_l_ed5;
	case 3802ULL: goto x86_l_eda;
	case 3806ULL: goto x86_l_ede;
	case 3812ULL: goto x86_l_ee4;
	case 3817ULL: goto x86_l_ee9;
	case 3823ULL: goto x86_l_eef;
	case 3828ULL: goto x86_l_ef4;
	case 3833ULL: goto x86_l_ef9;
	case 3838ULL: goto x86_l_efe;
	case 3843ULL: goto x86_l_f03;
	case 3848ULL: goto x86_l_f08;
	case 3854ULL: goto x86_l_f0e;
	case 3856ULL: goto x86_l_f10;
	case 3858ULL: goto x86_l_f12;
	case 3863ULL: goto x86_l_f17;
	case 3866ULL: goto x86_l_f1a;
	case 3872ULL: goto x86_l_f20;
	case 3875ULL: goto x86_l_f23;
	case 3881ULL: goto x86_l_f29;
	case 3884ULL: goto x86_l_f2c;
	case 3890ULL: goto x86_l_f32;
	case 3893ULL: goto x86_l_f35;
	case 3899ULL: goto x86_l_f3b;
	case 3904ULL: goto x86_l_f40;
	case 3909ULL: goto x86_l_f45;
	case 3918ULL: goto x86_l_f4e;
	case 3927ULL: goto x86_l_f57;
	case 3933ULL: goto x86_l_f5d;
	case 3935ULL: goto x86_l_f5f;
	case 3938ULL: goto x86_l_f62;
	case 3940ULL: goto x86_l_f64;
	case 3943ULL: goto x86_l_f67;
	case 3945ULL: goto x86_l_f69;
	case 3948ULL: goto x86_l_f6c;
	case 3954ULL: goto x86_l_f72;
	case 3959ULL: goto x86_l_f77;
	case 3962ULL: goto x86_l_f7a;
	case 3968ULL: goto x86_l_f80;
	case 3973ULL: goto x86_l_f85;
	case 3976ULL: goto x86_l_f88;
	case 3982ULL: goto x86_l_f8e;
	case 3985ULL: goto x86_l_f91;
	case 3991ULL: goto x86_l_f97;
	case 3996ULL: goto x86_l_f9c;
	case 4001ULL: goto x86_l_fa1;
	case 4004ULL: goto x86_l_fa4;
	case 4006ULL: goto x86_l_fa6;
	case 4009ULL: goto x86_l_fa9;
	case 4015ULL: goto x86_l_faf;
	case 4020ULL: goto x86_l_fb4;
	case 4022ULL: goto x86_l_fb6;
	case 4028ULL: goto x86_l_fbc;
	case 4031ULL: goto x86_l_fbf;
	case 4034ULL: goto x86_l_fc2;
	case 4040ULL: goto x86_l_fc8;
	case 4045ULL: goto x86_l_fcd;
	case 4047ULL: goto x86_l_fcf;
	case 4049ULL: goto x86_l_fd1;
	case 4052ULL: goto x86_l_fd4;
	case 4054ULL: goto x86_l_fd6;
	case 4059ULL: goto x86_l_fdb;
	case 4061ULL: goto x86_l_fdd;
	case 4064ULL: goto x86_l_fe0;
	case 4070ULL: goto x86_l_fe6;
	case 4078ULL: goto x86_l_fee;
	case 4081ULL: goto x86_l_ff1;
	case 4087ULL: goto x86_l_ff7;
	case 4092ULL: goto x86_l_ffc;
	case 4095ULL: goto x86_l_fff;
	case 4101ULL: goto x86_l_1005;
	case 4106ULL: goto x86_l_100a;
	case 4109ULL: goto x86_l_100d;
	case 4115ULL: goto x86_l_1013;
	case 4123ULL: goto x86_l_101b;
	case 4126ULL: goto x86_l_101e;
	case 4132ULL: goto x86_l_1024;
	case 4137ULL: goto x86_l_1029;
	case 4140ULL: goto x86_l_102c;
	case 4146ULL: goto x86_l_1032;
	case 4151ULL: goto x86_l_1037;
	case 4156ULL: goto x86_l_103c;
	case 4158ULL: goto x86_l_103e;
	case 4163ULL: goto x86_l_1043;
	case 4165ULL: goto x86_l_1045;
	case 4170ULL: goto x86_l_104a;
	case 4173ULL: goto x86_l_104d;
	case 4177ULL: goto x86_l_1051;
	case 4179ULL: goto x86_l_1053;
	case 4182ULL: goto x86_l_1056;
	case 4189ULL: goto x86_l_105d;
	case 4195ULL: goto x86_l_1063;
	case 4202ULL: goto x86_l_106a;
	case 4205ULL: goto x86_l_106d;
	case 4210ULL: goto x86_l_1072;
	case 4213ULL: goto x86_l_1075;
	case 4217ULL: goto x86_l_1079;
	case 4223ULL: goto x86_l_107f;
	case 4225ULL: goto x86_l_1081;
	case 4231ULL: goto x86_l_1087;
	case 4234ULL: goto x86_l_108a;
	case 4236ULL: goto x86_l_108c;
	case 4239ULL: goto x86_l_108f;
	case 4244ULL: goto x86_l_1094;
	case 4249ULL: goto x86_l_1099;
	case 4253ULL: goto x86_l_109d;
	case 4258ULL: goto x86_l_10a2;
	case 4260ULL: goto x86_l_10a4;
	case 4262ULL: goto x86_l_10a6;
	case 4268ULL: goto x86_l_10ac;
	case 4275ULL: goto x86_l_10b3;
	case 4281ULL: goto x86_l_10b9;
	case 4286ULL: goto x86_l_10be;
	case 4290ULL: goto x86_l_10c2;
	case 4294ULL: goto x86_l_10c6;
	case 4301ULL: goto x86_l_10cd;
	case 4303ULL: goto x86_l_10cf;
	case 4306ULL: goto x86_l_10d2;
	case 4311ULL: goto x86_l_10d7;
	case 4316ULL: goto x86_l_10dc;
	case 4320ULL: goto x86_l_10e0;
	case 4325ULL: goto x86_l_10e5;
	case 4327ULL: goto x86_l_10e7;
	case 4329ULL: goto x86_l_10e9;
	case 4335ULL: goto x86_l_10ef;
	case 4345ULL: goto x86_l_10f9;
	case 4351ULL: goto x86_l_10ff;
	case 4359ULL: goto x86_l_1107;
	case 4363ULL: goto x86_l_110b;
	case 4367ULL: goto x86_l_110f;
	case 4377ULL: goto x86_l_1119;
	case 4379ULL: goto x86_l_111b;
	case 4382ULL: goto x86_l_111e;
	case 4387ULL: goto x86_l_1123;
	case 4392ULL: goto x86_l_1128;
	case 4396ULL: goto x86_l_112c;
	case 4401ULL: goto x86_l_1131;
	case 4403ULL: goto x86_l_1133;
	case 4405ULL: goto x86_l_1135;
	case 4411ULL: goto x86_l_113b;
	case 4421ULL: goto x86_l_1145;
	case 4427ULL: goto x86_l_114b;
	case 4435ULL: goto x86_l_1153;
	case 4439ULL: goto x86_l_1157;
	case 4443ULL: goto x86_l_115b;
	case 4453ULL: goto x86_l_1165;
	case 4455ULL: goto x86_l_1167;
	case 4458ULL: goto x86_l_116a;
	case 4463ULL: goto x86_l_116f;
	case 4468ULL: goto x86_l_1174;
	case 4472ULL: goto x86_l_1178;
	case 4477ULL: goto x86_l_117d;
	case 4479ULL: goto x86_l_117f;
	case 4481ULL: goto x86_l_1181;
	case 4487ULL: goto x86_l_1187;
	case 4497ULL: goto x86_l_1191;
	case 4503ULL: goto x86_l_1197;
	case 4511ULL: goto x86_l_119f;
	case 4515ULL: goto x86_l_11a3;
	case 4519ULL: goto x86_l_11a7;
	case 4529ULL: goto x86_l_11b1;
	case 4531ULL: goto x86_l_11b3;
	case 4534ULL: goto x86_l_11b6;
	case 4539ULL: goto x86_l_11bb;
	case 4544ULL: goto x86_l_11c0;
	case 4548ULL: goto x86_l_11c4;
	case 4553ULL: goto x86_l_11c9;
	case 4555ULL: goto x86_l_11cb;
	case 4557ULL: goto x86_l_11cd;
	case 4563ULL: goto x86_l_11d3;
	case 4573ULL: goto x86_l_11dd;
	case 4579ULL: goto x86_l_11e3;
	case 4587ULL: goto x86_l_11eb;
	case 4591ULL: goto x86_l_11ef;
	case 4595ULL: goto x86_l_11f3;
	case 4605ULL: goto x86_l_11fd;
	case 4607ULL: goto x86_l_11ff;
	case 4610ULL: goto x86_l_1202;
	case 4615ULL: goto x86_l_1207;
	case 4620ULL: goto x86_l_120c;
	case 4624ULL: goto x86_l_1210;
	case 4629ULL: goto x86_l_1215;
	case 4631ULL: goto x86_l_1217;
	case 4633ULL: goto x86_l_1219;
	case 4639ULL: goto x86_l_121f;
	case 4649ULL: goto x86_l_1229;
	case 4655ULL: goto x86_l_122f;
	case 4663ULL: goto x86_l_1237;
	case 4667ULL: goto x86_l_123b;
	case 4671ULL: goto x86_l_123f;
	case 4681ULL: goto x86_l_1249;
	case 4683ULL: goto x86_l_124b;
	case 4686ULL: goto x86_l_124e;
	case 4691ULL: goto x86_l_1253;
	case 4696ULL: goto x86_l_1258;
	case 4700ULL: goto x86_l_125c;
	case 4705ULL: goto x86_l_1261;
	case 4707ULL: goto x86_l_1263;
	case 4709ULL: goto x86_l_1265;
	case 4715ULL: goto x86_l_126b;
	case 4725ULL: goto x86_l_1275;
	case 4731ULL: goto x86_l_127b;
	case 4739ULL: goto x86_l_1283;
	case 4743ULL: goto x86_l_1287;
	case 4747ULL: goto x86_l_128b;
	case 4757ULL: goto x86_l_1295;
	case 4759ULL: goto x86_l_1297;
	case 4762ULL: goto x86_l_129a;
	case 4767ULL: goto x86_l_129f;
	case 4772ULL: goto x86_l_12a4;
	case 4776ULL: goto x86_l_12a8;
	case 4781ULL: goto x86_l_12ad;
	case 4783ULL: goto x86_l_12af;
	case 4785ULL: goto x86_l_12b1;
	case 4791ULL: goto x86_l_12b7;
	case 4801ULL: goto x86_l_12c1;
	case 4807ULL: goto x86_l_12c7;
	case 4815ULL: goto x86_l_12cf;
	case 4819ULL: goto x86_l_12d3;
	case 4823ULL: goto x86_l_12d7;
	case 4833ULL: goto x86_l_12e1;
	case 4835ULL: goto x86_l_12e3;
	case 4838ULL: goto x86_l_12e6;
	case 4843ULL: goto x86_l_12eb;
	case 4848ULL: goto x86_l_12f0;
	case 4852ULL: goto x86_l_12f4;
	case 4857ULL: goto x86_l_12f9;
	case 4859ULL: goto x86_l_12fb;
	case 4861ULL: goto x86_l_12fd;
	case 4867ULL: goto x86_l_1303;
	case 4872ULL: goto x86_l_1308;
	case 4882ULL: goto x86_l_1312;
	case 4888ULL: goto x86_l_1318;
	case 4896ULL: goto x86_l_1320;
	case 4900ULL: goto x86_l_1324;
	case 4904ULL: goto x86_l_1328;
	case 4914ULL: goto x86_l_1332;
	case 4920ULL: goto x86_l_1338;
	case 4923ULL: goto x86_l_133b;
	case 4928ULL: goto x86_l_1340;
	default: return 0xffffffffffffffffULL;
	}
x86_l_c71:
	/* 0xc71: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c73:
	/* 0xc73: js     ef4 <generic_sleepable_preload+0xef4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_ef4;
	}
x86_l_c79:
	/* 0xc79: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c7d:
	/* 0xc7d: je     e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e10;
	}
x86_l_c83:
	/* 0xc83: mov    ecx,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_c86:
	/* 0xc86: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_c8a:
	/* 0xc8a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c8e:
	/* 0xc8e: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_c93:
	/* 0xc93: je     e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e10;
	}
x86_l_c99:
	/* 0xc99: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c9e:
	/* 0xc9e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ca3:
	/* 0xca3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ca6:
	/* 0xca6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_caa:
	/* 0xcaa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_caf:
	/* 0xcaf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cb1:
	/* 0xcb1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cb3:
	/* 0xcb3: jns    e10 <generic_sleepable_preload+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_e10;
	}
x86_l_cb9:
	/* 0xcb9: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_cbe:
	/* 0xcbe: jmp    e0d <generic_sleepable_preload+0xe0d> */
	goto x86_l_e0d;
x86_l_cc3:
	/* 0xcc3: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_cc8:
	/* 0xcc8: jmp    e0d <generic_sleepable_preload+0xe0d> */
	goto x86_l_e0d;
x86_l_ccd:
	/* 0xccd: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_cd3:
	/* 0xcd3: jmp    d2d <generic_sleepable_preload+0xd2d> */
	goto x86_l_d2d;
x86_l_cd5:
	/* 0xcd5: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_cda:
	/* 0xcda: jmp    e0d <generic_sleepable_preload+0xe0d> */
	goto x86_l_e0d;
x86_l_cdf:
	/* 0xcdf: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_ce5:
	/* 0xce5: jmp    d2d <generic_sleepable_preload+0xd2d> */
	goto x86_l_d2d;
x86_l_ce7:
	/* 0xce7: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_cec:
	/* 0xcec: jmp    e0d <generic_sleepable_preload+0xe0d> */
	goto x86_l_e0d;
x86_l_cf1:
	/* 0xcf1: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_cf7:
	/* 0xcf7: jmp    d2d <generic_sleepable_preload+0xd2d> */
	goto x86_l_d2d;
x86_l_cf9:
	/* 0xcf9: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_cfe:
	/* 0xcfe: jmp    e0d <generic_sleepable_preload+0xe0d> */
	goto x86_l_e0d;
x86_l_d03:
	/* 0xd03: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_d09:
	/* 0xd09: jmp    d2d <generic_sleepable_preload+0xd2d> */
	goto x86_l_d2d;
x86_l_d0b:
	/* 0xd0b: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_d10:
	/* 0xd10: jmp    e0d <generic_sleepable_preload+0xe0d> */
	goto x86_l_e0d;
x86_l_d15:
	/* 0xd15: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_d1b:
	/* 0xd1b: jmp    d2d <generic_sleepable_preload+0xd2d> */
	goto x86_l_d2d;
x86_l_d1d:
	/* 0xd1d: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_d22:
	/* 0xd22: jmp    e0d <generic_sleepable_preload+0xe0d> */
	goto x86_l_e0d;
x86_l_d27:
	/* 0xd27: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_d2d:
	/* 0xd2d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d2f:
	/* 0xd2f: mov    r15d,DWORD PTR [r12+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_d34:
	/* 0xd34: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d39:
	/* 0xd39: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d3e:
	/* 0xd3e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_d41:
	/* 0xd41: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d46:
	/* 0xd46: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_d49:
	/* 0xd49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d4b:
	/* 0xd4b: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_d4f:
	/* 0xd4f: jne    11b <generic_sleepable_preload+0x11b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 283ULL;
	}
x86_l_d55:
	/* 0xd55: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d59:
	/* 0xd59: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_d61:
	/* 0xd61: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_d66:
	/* 0xd66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d68:
	/* 0xd68: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d6d:
	/* 0xd6d: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_d75:
	/* 0xd75: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d7a:
	/* 0xd7a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_d81:
	/* 0xd81: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_d86:
	/* 0xd86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d88:
	/* 0xd88: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d8b:
	/* 0xd8b: je     116 <generic_sleepable_preload+0x116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 278ULL;
	}
x86_l_d91:
	/* 0xd91: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_d94:
	/* 0xd94: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d99:
	/* 0xd99: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d9b:
	/* 0xd9b: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_da2:
	/* 0xda2: mov    r12d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_da5:
	/* 0xda5: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_da8:
	/* 0xda8: lea    r13,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dad:
	/* 0xdad: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_db0:
	/* 0xdb0: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_db3:
	/* 0xdb3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_db5:
	/* 0xdb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_db7:
	/* 0xdb7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dbc:
	/* 0xdbc: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_dbf:
	/* 0xdbf: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_dc2:
	/* 0xdc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dc4:
	/* 0xdc4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dc7:
	/* 0xdc7: je     116 <generic_sleepable_preload+0x116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 278ULL;
	}
x86_l_dcd:
	/* 0xdcd: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_dd0:
	/* 0xdd0: je     114 <generic_sleepable_preload+0x114> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 276ULL;
	}
x86_l_dd6:
	/* 0xdd6: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_dda:
	/* 0xdda: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_ddf:
	/* 0xddf: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_de7:
	/* 0xde7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_de9:
	/* 0xde9: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_dec:
	/* 0xdec: call   df1 <generic_sleepable_preload+0xdf1> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_df1:
	/* 0xdf1: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_df3:
	/* 0xdf3: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_df6:
	/* 0xdf6: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_df8:
	/* 0xdf8: jns    114 <generic_sleepable_preload+0x114> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 276ULL;
	}
x86_l_dfe:
	/* 0xdfe: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_e03:
	/* 0xe03: jmp    114 <generic_sleepable_preload+0x114> */
	return 276ULL;
x86_l_e08:
	/* 0xe08: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_e0d:
	/* 0xe0d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e10:
	/* 0xe10: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_e14:
	/* 0xe14: jne    116 <generic_sleepable_preload+0x116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 278ULL;
	}
x86_l_e1a:
	/* 0xe1a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e1e:
	/* 0xe1e: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_e26:
	/* 0xe26: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_e2b:
	/* 0xe2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e2d:
	/* 0xe2d: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e32:
	/* 0xe32: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_e3a:
	/* 0xe3a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e3f:
	/* 0xe3f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_e46:
	/* 0xe46: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_e4b:
	/* 0xe4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e4d:
	/* 0xe4d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e50:
	/* 0xe50: je     116 <generic_sleepable_preload+0x116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 278ULL;
	}
x86_l_e56:
	/* 0xe56: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_e59:
	/* 0xe59: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e5e:
	/* 0xe5e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e60:
	/* 0xe60: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_e67:
	/* 0xe67: mov    r12d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_32);
x86_l_e6a:
	/* 0xe6a: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_e6d:
	/* 0xe6d: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e72:
	/* 0xe72: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_e75:
	/* 0xe75: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_e78:
	/* 0xe78: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e7a:
	/* 0xe7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e7c:
	/* 0xe7c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e81:
	/* 0xe81: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_e84:
	/* 0xe84: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_e87:
	/* 0xe87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e89:
	/* 0xe89: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e8c:
	/* 0xe8c: je     116 <generic_sleepable_preload+0x116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 278ULL;
	}
x86_l_e92:
	/* 0xe92: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_e95:
	/* 0xe95: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_e98:
	/* 0xe98: je     ebc <generic_sleepable_preload+0xebc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ebc;
	}
x86_l_e9a:
	/* 0xe9a: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e9e:
	/* 0xe9e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_ea3:
	/* 0xea3: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_eab:
	/* 0xeab: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ead:
	/* 0xead: call   eb2 <generic_sleepable_preload+0xeb2> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_eb2:
	/* 0xeb2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_eb4:
	/* 0xeb4: jns    ebc <generic_sleepable_preload+0xebc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_ebc;
	}
x86_l_eb6:
	/* 0xeb6: mov    r15d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967295ULL);
x86_l_ebc:
	/* 0xebc: mov    DWORD PTR [r13+0x0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ec0:
	/* 0xec0: jmp    116 <generic_sleepable_preload+0x116> */
	return 278ULL;
x86_l_ec5:
	/* 0xec5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ec7:
	/* 0xec7: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_ecd:
	/* 0xecd: jmp    d2f <generic_sleepable_preload+0xd2f> */
	goto x86_l_d2f;
x86_l_ed2:
	/* 0xed2: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ed5:
	/* 0xed5: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_eda:
	/* 0xeda: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_ede:
	/* 0xede: jne    116 <generic_sleepable_preload+0x116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 278ULL;
	}
x86_l_ee4:
	/* 0xee4: jmp    e1a <generic_sleepable_preload+0xe1a> */
	goto x86_l_e1a;
x86_l_ee9:
	/* 0xee9: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_eef:
	/* 0xeef: jmp    d2d <generic_sleepable_preload+0xd2d> */
	goto x86_l_d2d;
x86_l_ef4:
	/* 0xef4: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_ef9:
	/* 0xef9: jmp    e0d <generic_sleepable_preload+0xe0d> */
	goto x86_l_e0d;
x86_l_efe:
	/* 0xefe: mov    eax,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f03:
	/* 0xf03: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_f08:
	/* 0xf08: je     1e2d <generic_sleepable_preload+0x1e2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7725ULL;
	}
x86_l_f0e:
	/* 0xf0e: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_f10:
	/* 0xf10: js     f45 <generic_sleepable_preload+0xf45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_f45;
	}
x86_l_f12:
	/* 0xf12: mov    eax,DWORD PTR [r12+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f17:
	/* 0xf17: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f1a:
	/* 0xf1a: jle    fcd <generic_sleepable_preload+0xfcd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_fcd;
	}
x86_l_f20:
	/* 0xf20: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f23:
	/* 0xf23: je     1037 <generic_sleepable_preload+0x1037> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1037;
	}
x86_l_f29:
	/* 0xf29: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_f2c:
	/* 0xf2c: je     103e <generic_sleepable_preload+0x103e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_103e;
	}
x86_l_f32:
	/* 0xf32: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f35:
	/* 0xf35: jne    1051 <generic_sleepable_preload+0x1051> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1051;
	}
x86_l_f3b:
	/* 0xf3b: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f40:
	/* 0xf40: jmp    104a <generic_sleepable_preload+0x104a> */
	goto x86_l_104a;
x86_l_f45:
	/* 0xf45: movzx  eax,BYTE PTR [r12+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_f4e:
	/* 0xf4e: movzx  ecx,WORD PTR [r12+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_f57:
	/* 0xf57: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_f5d:
	/* 0xf5d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f5f:
	/* 0xf5f: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_f62:
	/* 0xf62: jle    fa1 <generic_sleepable_preload+0xfa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_fa1;
	}
x86_l_f64:
	/* 0xf64: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_f67:
	/* 0xf67: jle    fdd <generic_sleepable_preload+0xfdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_fdd;
	}
x86_l_f69:
	/* 0xf69: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_f6c:
	/* 0xf6c: jle    1685 <generic_sleepable_preload+0x1685> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5765ULL;
	}
x86_l_f72:
	/* 0xf72: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f77:
	/* 0xf77: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_f7a:
	/* 0xf7a: je     1699 <generic_sleepable_preload+0x1699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5785ULL;
	}
x86_l_f80:
	/* 0xf80: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_f85:
	/* 0xf85: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_f88:
	/* 0xf88: je     1699 <generic_sleepable_preload+0x1699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5785ULL;
	}
x86_l_f8e:
	/* 0xf8e: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_f91:
	/* 0xf91: jne    16ac <generic_sleepable_preload+0x16ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5804ULL;
	}
x86_l_f97:
	/* 0xf97: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f9c:
	/* 0xf9c: jmp    1699 <generic_sleepable_preload+0x1699> */
	return 5785ULL;
x86_l_fa1:
	/* 0xfa1: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_fa4:
	/* 0xfa4: jg     100a <generic_sleepable_preload+0x100a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_100a;
	}
x86_l_fa6:
	/* 0xfa6: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_fa9:
	/* 0xfa9: jg     1656 <generic_sleepable_preload+0x1656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5718ULL;
	}
x86_l_faf:
	/* 0xfaf: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_fb4:
	/* 0xfb4: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_fb6:
	/* 0xfb6: je     1699 <generic_sleepable_preload+0x1699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5785ULL;
	}
x86_l_fbc:
	/* 0xfbc: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_fbf:
	/* 0xfbf: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_fc2:
	/* 0xfc2: je     1699 <generic_sleepable_preload+0x1699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5785ULL;
	}
x86_l_fc8:
	/* 0xfc8: jmp    16ac <generic_sleepable_preload+0x16ac> */
	return 5804ULL;
x86_l_fcd:
	/* 0xfcd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fcf:
	/* 0xfcf: je     1045 <generic_sleepable_preload+0x1045> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1045;
	}
x86_l_fd1:
	/* 0xfd1: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fd4:
	/* 0xfd4: jne    1051 <generic_sleepable_preload+0x1051> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1051;
	}
x86_l_fd6:
	/* 0xfd6: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fdb:
	/* 0xfdb: jmp    104a <generic_sleepable_preload+0x104a> */
	goto x86_l_104a;
x86_l_fdd:
	/* 0xfdd: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_fe0:
	/* 0xfe0: jg     163d <generic_sleepable_preload+0x163d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5693ULL;
	}
x86_l_fe6:
	/* 0xfe6: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_fee:
	/* 0xfee: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ff1:
	/* 0xff1: je     1699 <generic_sleepable_preload+0x1699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5785ULL;
	}
x86_l_ff7:
	/* 0xff7: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ffc:
	/* 0xffc: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_fff:
	/* 0xfff: je     1699 <generic_sleepable_preload+0x1699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5785ULL;
	}
x86_l_1005:
	/* 0x1005: jmp    16ac <generic_sleepable_preload+0x16ac> */
	return 5804ULL;
x86_l_100a:
	/* 0x100a: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_100d:
	/* 0x100d: jg     166c <generic_sleepable_preload+0x166c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5740ULL;
	}
x86_l_1013:
	/* 0x1013: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_101b:
	/* 0x101b: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_101e:
	/* 0x101e: je     1699 <generic_sleepable_preload+0x1699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5785ULL;
	}
x86_l_1024:
	/* 0x1024: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1029:
	/* 0x1029: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_102c:
	/* 0x102c: je     1699 <generic_sleepable_preload+0x1699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5785ULL;
	}
x86_l_1032:
	/* 0x1032: jmp    16ac <generic_sleepable_preload+0x16ac> */
	return 5804ULL;
x86_l_1037:
	/* 0x1037: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_103c:
	/* 0x103c: jmp    104a <generic_sleepable_preload+0x104a> */
	goto x86_l_104a;
x86_l_103e:
	/* 0x103e: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1043:
	/* 0x1043: jmp    104a <generic_sleepable_preload+0x104a> */
	goto x86_l_104a;
x86_l_1045:
	/* 0x1045: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_104a:
	/* 0x104a: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_104d:
	/* 0x104d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1051:
	/* 0x1051: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1053:
	/* 0x1053: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_1056:
	/* 0x1056: cmp    WORD PTR [r12+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_105d:
	/* 0x105d: je     1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_1063:
	/* 0x1063: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_106a:
	/* 0x106a: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_106d:
	/* 0x106d: mov    eax,DWORD PTR [r12+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1072:
	/* 0x1072: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1075:
	/* 0x1075: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1079:
	/* 0x1079: movzx  eax,WORD PTR [r12+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_107f:
	/* 0x107f: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1081:
	/* 0x1081: je     134a <generic_sleepable_preload+0x134a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4938ULL;
	}
x86_l_1087:
	/* 0x1087: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_108a:
	/* 0x108a: je     10ac <generic_sleepable_preload+0x10ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10ac;
	}
x86_l_108c:
	/* 0x108c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_108f:
	/* 0x108f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1094:
	/* 0x1094: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1099:
	/* 0x1099: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_109d:
	/* 0x109d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10a2:
	/* 0x10a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10a4:
	/* 0x10a4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10a6:
	/* 0x10a6: js     1633 <generic_sleepable_preload+0x1633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5683ULL;
	}
x86_l_10ac:
	/* 0x10ac: cmp    WORD PTR [r12+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_10b3:
	/* 0x10b3: je     1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_10b9:
	/* 0x10b9: mov    ecx,DWORD PTR [r12+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_10be:
	/* 0x10be: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_10c2:
	/* 0x10c2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10c6:
	/* 0x10c6: cmp    WORD PTR [r12+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_10cd:
	/* 0x10cd: je     10ef <generic_sleepable_preload+0x10ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10ef;
	}
x86_l_10cf:
	/* 0x10cf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_10d2:
	/* 0x10d2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_10d7:
	/* 0x10d7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_10dc:
	/* 0x10dc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10e0:
	/* 0x10e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10e5:
	/* 0x10e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10e7:
	/* 0x10e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10e9:
	/* 0x10e9: js     1ca1 <generic_sleepable_preload+0x1ca1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7329ULL;
	}
x86_l_10ef:
	/* 0x10ef: cmp    WORD PTR [r12+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_10f9:
	/* 0x10f9: je     1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_10ff:
	/* 0x10ff: mov    ecx,DWORD PTR [r12+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1107:
	/* 0x1107: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_110b:
	/* 0x110b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_110f:
	/* 0x110f: cmp    WORD PTR [r12+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1119:
	/* 0x1119: je     113b <generic_sleepable_preload+0x113b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_113b;
	}
x86_l_111b:
	/* 0x111b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_111e:
	/* 0x111e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1123:
	/* 0x1123: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1128:
	/* 0x1128: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_112c:
	/* 0x112c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1131:
	/* 0x1131: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1133:
	/* 0x1133: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1135:
	/* 0x1135: js     1cb2 <generic_sleepable_preload+0x1cb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7346ULL;
	}
x86_l_113b:
	/* 0x113b: cmp    WORD PTR [r12+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1145:
	/* 0x1145: je     1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_114b:
	/* 0x114b: mov    ecx,DWORD PTR [r12+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1153:
	/* 0x1153: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1157:
	/* 0x1157: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_115b:
	/* 0x115b: cmp    WORD PTR [r12+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1165:
	/* 0x1165: je     1187 <generic_sleepable_preload+0x1187> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1187;
	}
x86_l_1167:
	/* 0x1167: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_116a:
	/* 0x116a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_116f:
	/* 0x116f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1174:
	/* 0x1174: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1178:
	/* 0x1178: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_117d:
	/* 0x117d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_117f:
	/* 0x117f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1181:
	/* 0x1181: js     1cc3 <generic_sleepable_preload+0x1cc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7363ULL;
	}
x86_l_1187:
	/* 0x1187: cmp    WORD PTR [r12+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1191:
	/* 0x1191: je     1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_1197:
	/* 0x1197: mov    ecx,DWORD PTR [r12+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_119f:
	/* 0x119f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_11a3:
	/* 0x11a3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11a7:
	/* 0x11a7: cmp    WORD PTR [r12+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_11b1:
	/* 0x11b1: je     11d3 <generic_sleepable_preload+0x11d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d3;
	}
x86_l_11b3:
	/* 0x11b3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_11b6:
	/* 0x11b6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_11bb:
	/* 0x11bb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_11c0:
	/* 0x11c0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11c4:
	/* 0x11c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11c9:
	/* 0x11c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11cb:
	/* 0x11cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11cd:
	/* 0x11cd: js     1cd4 <generic_sleepable_preload+0x1cd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7380ULL;
	}
x86_l_11d3:
	/* 0x11d3: cmp    WORD PTR [r12+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_11dd:
	/* 0x11dd: je     1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_11e3:
	/* 0x11e3: mov    ecx,DWORD PTR [r12+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_11eb:
	/* 0x11eb: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_11ef:
	/* 0x11ef: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11f3:
	/* 0x11f3: cmp    WORD PTR [r12+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_11fd:
	/* 0x11fd: je     121f <generic_sleepable_preload+0x121f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_121f;
	}
x86_l_11ff:
	/* 0x11ff: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1202:
	/* 0x1202: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1207:
	/* 0x1207: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_120c:
	/* 0x120c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1210:
	/* 0x1210: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1215:
	/* 0x1215: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1217:
	/* 0x1217: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1219:
	/* 0x1219: js     1ce5 <generic_sleepable_preload+0x1ce5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7397ULL;
	}
x86_l_121f:
	/* 0x121f: cmp    WORD PTR [r12+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1229:
	/* 0x1229: je     1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_122f:
	/* 0x122f: mov    ecx,DWORD PTR [r12+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1237:
	/* 0x1237: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_123b:
	/* 0x123b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_123f:
	/* 0x123f: cmp    WORD PTR [r12+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1249:
	/* 0x1249: je     126b <generic_sleepable_preload+0x126b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_126b;
	}
x86_l_124b:
	/* 0x124b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_124e:
	/* 0x124e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1253:
	/* 0x1253: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1258:
	/* 0x1258: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_125c:
	/* 0x125c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1261:
	/* 0x1261: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1263:
	/* 0x1263: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1265:
	/* 0x1265: js     1cf6 <generic_sleepable_preload+0x1cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7414ULL;
	}
x86_l_126b:
	/* 0x126b: cmp    WORD PTR [r12+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1275:
	/* 0x1275: je     1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_127b:
	/* 0x127b: mov    ecx,DWORD PTR [r12+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1283:
	/* 0x1283: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1287:
	/* 0x1287: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_128b:
	/* 0x128b: cmp    WORD PTR [r12+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1295:
	/* 0x1295: je     12b7 <generic_sleepable_preload+0x12b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12b7;
	}
x86_l_1297:
	/* 0x1297: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_129a:
	/* 0x129a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_129f:
	/* 0x129f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_12a4:
	/* 0x12a4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12a8:
	/* 0x12a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12ad:
	/* 0x12ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12af:
	/* 0x12af: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12b1:
	/* 0x12b1: js     5bd0 <generic_sleepable_preload+0x5bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23504ULL;
	}
x86_l_12b7:
	/* 0x12b7: cmp    WORD PTR [r12+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_12c1:
	/* 0x12c1: je     1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_12c7:
	/* 0x12c7: mov    ecx,DWORD PTR [r12+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_12cf:
	/* 0x12cf: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_12d3:
	/* 0x12d3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12d7:
	/* 0x12d7: cmp    WORD PTR [r12+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_12e1:
	/* 0x12e1: je     1303 <generic_sleepable_preload+0x1303> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1303;
	}
x86_l_12e3:
	/* 0x12e3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_12e6:
	/* 0x12e6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_12eb:
	/* 0x12eb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_12f0:
	/* 0x12f0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12f4:
	/* 0x12f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12f9:
	/* 0x12f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12fb:
	/* 0x12fb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12fd:
	/* 0x12fd: js     5cb6 <generic_sleepable_preload+0x5cb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23734ULL;
	}
x86_l_1303:
	/* 0x1303: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1308:
	/* 0x1308: cmp    WORD PTR [r12+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1312:
	/* 0x1312: je     1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_1318:
	/* 0x1318: mov    ecx,DWORD PTR [r12+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1320:
	/* 0x1320: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1324:
	/* 0x1324: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1328:
	/* 0x1328: cmp    WORD PTR [r12+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1332:
	/* 0x1332: je     1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_1338:
	/* 0x1338: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_133b:
	/* 0x133b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1340:
	/* 0x1340: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
	return 4933ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4933ULL: goto x86_l_1345;
	case 4938ULL: goto x86_l_134a;
	case 4941ULL: goto x86_l_134d;
	case 4943ULL: goto x86_l_134f;
	case 4946ULL: goto x86_l_1352;
	case 4951ULL: goto x86_l_1357;
	case 4956ULL: goto x86_l_135c;
	case 4960ULL: goto x86_l_1360;
	case 4965ULL: goto x86_l_1365;
	case 4967ULL: goto x86_l_1367;
	case 4969ULL: goto x86_l_1369;
	case 4975ULL: goto x86_l_136f;
	case 4982ULL: goto x86_l_1376;
	case 4988ULL: goto x86_l_137c;
	case 4993ULL: goto x86_l_1381;
	case 4997ULL: goto x86_l_1385;
	case 5001ULL: goto x86_l_1389;
	case 5008ULL: goto x86_l_1390;
	case 5010ULL: goto x86_l_1392;
	case 5013ULL: goto x86_l_1395;
	case 5018ULL: goto x86_l_139a;
	case 5023ULL: goto x86_l_139f;
	case 5027ULL: goto x86_l_13a3;
	case 5032ULL: goto x86_l_13a8;
	case 5034ULL: goto x86_l_13aa;
	case 5036ULL: goto x86_l_13ac;
	case 5042ULL: goto x86_l_13b2;
	case 5052ULL: goto x86_l_13bc;
	case 5058ULL: goto x86_l_13c2;
	case 5066ULL: goto x86_l_13ca;
	case 5070ULL: goto x86_l_13ce;
	case 5074ULL: goto x86_l_13d2;
	case 5084ULL: goto x86_l_13dc;
	case 5086ULL: goto x86_l_13de;
	case 5089ULL: goto x86_l_13e1;
	case 5094ULL: goto x86_l_13e6;
	case 5099ULL: goto x86_l_13eb;
	case 5103ULL: goto x86_l_13ef;
	case 5108ULL: goto x86_l_13f4;
	case 5110ULL: goto x86_l_13f6;
	case 5112ULL: goto x86_l_13f8;
	case 5118ULL: goto x86_l_13fe;
	case 5128ULL: goto x86_l_1408;
	case 5134ULL: goto x86_l_140e;
	case 5142ULL: goto x86_l_1416;
	case 5146ULL: goto x86_l_141a;
	case 5150ULL: goto x86_l_141e;
	case 5160ULL: goto x86_l_1428;
	case 5162ULL: goto x86_l_142a;
	case 5165ULL: goto x86_l_142d;
	case 5170ULL: goto x86_l_1432;
	case 5175ULL: goto x86_l_1437;
	case 5179ULL: goto x86_l_143b;
	case 5184ULL: goto x86_l_1440;
	case 5186ULL: goto x86_l_1442;
	case 5188ULL: goto x86_l_1444;
	case 5194ULL: goto x86_l_144a;
	case 5204ULL: goto x86_l_1454;
	case 5210ULL: goto x86_l_145a;
	case 5218ULL: goto x86_l_1462;
	case 5222ULL: goto x86_l_1466;
	case 5226ULL: goto x86_l_146a;
	case 5236ULL: goto x86_l_1474;
	case 5238ULL: goto x86_l_1476;
	case 5241ULL: goto x86_l_1479;
	case 5246ULL: goto x86_l_147e;
	case 5251ULL: goto x86_l_1483;
	case 5255ULL: goto x86_l_1487;
	case 5260ULL: goto x86_l_148c;
	case 5262ULL: goto x86_l_148e;
	case 5264ULL: goto x86_l_1490;
	case 5270ULL: goto x86_l_1496;
	case 5280ULL: goto x86_l_14a0;
	case 5286ULL: goto x86_l_14a6;
	case 5294ULL: goto x86_l_14ae;
	case 5298ULL: goto x86_l_14b2;
	case 5302ULL: goto x86_l_14b6;
	case 5312ULL: goto x86_l_14c0;
	case 5314ULL: goto x86_l_14c2;
	case 5317ULL: goto x86_l_14c5;
	case 5322ULL: goto x86_l_14ca;
	case 5327ULL: goto x86_l_14cf;
	case 5331ULL: goto x86_l_14d3;
	case 5336ULL: goto x86_l_14d8;
	case 5338ULL: goto x86_l_14da;
	case 5340ULL: goto x86_l_14dc;
	case 5346ULL: goto x86_l_14e2;
	case 5356ULL: goto x86_l_14ec;
	case 5362ULL: goto x86_l_14f2;
	case 5370ULL: goto x86_l_14fa;
	case 5374ULL: goto x86_l_14fe;
	case 5378ULL: goto x86_l_1502;
	case 5388ULL: goto x86_l_150c;
	case 5390ULL: goto x86_l_150e;
	case 5393ULL: goto x86_l_1511;
	case 5398ULL: goto x86_l_1516;
	case 5403ULL: goto x86_l_151b;
	case 5407ULL: goto x86_l_151f;
	case 5412ULL: goto x86_l_1524;
	case 5414ULL: goto x86_l_1526;
	case 5416ULL: goto x86_l_1528;
	case 5422ULL: goto x86_l_152e;
	case 5432ULL: goto x86_l_1538;
	case 5438ULL: goto x86_l_153e;
	case 5441ULL: goto x86_l_1541;
	case 5449ULL: goto x86_l_1549;
	case 5453ULL: goto x86_l_154d;
	case 5457ULL: goto x86_l_1551;
	case 5467ULL: goto x86_l_155b;
	case 5469ULL: goto x86_l_155d;
	case 5472ULL: goto x86_l_1560;
	case 5477ULL: goto x86_l_1565;
	case 5482ULL: goto x86_l_156a;
	case 5486ULL: goto x86_l_156e;
	case 5491ULL: goto x86_l_1573;
	case 5493ULL: goto x86_l_1575;
	case 5495ULL: goto x86_l_1577;
	case 5501ULL: goto x86_l_157d;
	case 5506ULL: goto x86_l_1582;
	case 5516ULL: goto x86_l_158c;
	case 5519ULL: goto x86_l_158f;
	case 5525ULL: goto x86_l_1595;
	case 5533ULL: goto x86_l_159d;
	case 5537ULL: goto x86_l_15a1;
	case 5541ULL: goto x86_l_15a5;
	case 5551ULL: goto x86_l_15af;
	case 5553ULL: goto x86_l_15b1;
	case 5556ULL: goto x86_l_15b4;
	case 5561ULL: goto x86_l_15b9;
	case 5566ULL: goto x86_l_15be;
	case 5570ULL: goto x86_l_15c2;
	case 5575ULL: goto x86_l_15c7;
	case 5577ULL: goto x86_l_15c9;
	case 5579ULL: goto x86_l_15cb;
	case 5585ULL: goto x86_l_15d1;
	case 5590ULL: goto x86_l_15d6;
	case 5600ULL: goto x86_l_15e0;
	case 5603ULL: goto x86_l_15e3;
	case 5609ULL: goto x86_l_15e9;
	case 5617ULL: goto x86_l_15f1;
	case 5621ULL: goto x86_l_15f5;
	case 5625ULL: goto x86_l_15f9;
	case 5635ULL: goto x86_l_1603;
	case 5641ULL: goto x86_l_1609;
	case 5644ULL: goto x86_l_160c;
	case 5649ULL: goto x86_l_1611;
	case 5654ULL: goto x86_l_1616;
	case 5658ULL: goto x86_l_161a;
	case 5663ULL: goto x86_l_161f;
	case 5665ULL: goto x86_l_1621;
	case 5667ULL: goto x86_l_1623;
	case 5673ULL: goto x86_l_1629;
	case 5678ULL: goto x86_l_162e;
	case 5683ULL: goto x86_l_1633;
	case 5688ULL: goto x86_l_1638;
	case 5693ULL: goto x86_l_163d;
	case 5701ULL: goto x86_l_1645;
	case 5704ULL: goto x86_l_1648;
	case 5706ULL: goto x86_l_164a;
	case 5711ULL: goto x86_l_164f;
	case 5714ULL: goto x86_l_1652;
	case 5716ULL: goto x86_l_1654;
	case 5718ULL: goto x86_l_1656;
	case 5723ULL: goto x86_l_165b;
	case 5726ULL: goto x86_l_165e;
	case 5728ULL: goto x86_l_1660;
	case 5733ULL: goto x86_l_1665;
	case 5736ULL: goto x86_l_1668;
	case 5738ULL: goto x86_l_166a;
	case 5740ULL: goto x86_l_166c;
	case 5748ULL: goto x86_l_1674;
	case 5751ULL: goto x86_l_1677;
	case 5753ULL: goto x86_l_1679;
	case 5758ULL: goto x86_l_167e;
	case 5761ULL: goto x86_l_1681;
	case 5763ULL: goto x86_l_1683;
	case 5765ULL: goto x86_l_1685;
	case 5770ULL: goto x86_l_168a;
	case 5773ULL: goto x86_l_168d;
	case 5775ULL: goto x86_l_168f;
	case 5780ULL: goto x86_l_1694;
	case 5783ULL: goto x86_l_1697;
	case 5785ULL: goto x86_l_1699;
	case 5788ULL: goto x86_l_169c;
	case 5790ULL: goto x86_l_169e;
	case 5792ULL: goto x86_l_16a0;
	case 5797ULL: goto x86_l_16a5;
	case 5799ULL: goto x86_l_16a7;
	case 5804ULL: goto x86_l_16ac;
	case 5808ULL: goto x86_l_16b0;
	case 5813ULL: goto x86_l_16b5;
	case 5815ULL: goto x86_l_16b7;
	case 5818ULL: goto x86_l_16ba;
	case 5825ULL: goto x86_l_16c1;
	case 5831ULL: goto x86_l_16c7;
	case 5838ULL: goto x86_l_16ce;
	case 5841ULL: goto x86_l_16d1;
	case 5846ULL: goto x86_l_16d6;
	case 5849ULL: goto x86_l_16d9;
	case 5853ULL: goto x86_l_16dd;
	case 5859ULL: goto x86_l_16e3;
	case 5861ULL: goto x86_l_16e5;
	case 5867ULL: goto x86_l_16eb;
	case 5870ULL: goto x86_l_16ee;
	case 5872ULL: goto x86_l_16f0;
	case 5875ULL: goto x86_l_16f3;
	case 5880ULL: goto x86_l_16f8;
	case 5885ULL: goto x86_l_16fd;
	case 5889ULL: goto x86_l_1701;
	case 5894ULL: goto x86_l_1706;
	case 5896ULL: goto x86_l_1708;
	case 5898ULL: goto x86_l_170a;
	case 5904ULL: goto x86_l_1710;
	case 5911ULL: goto x86_l_1717;
	case 5917ULL: goto x86_l_171d;
	case 5922ULL: goto x86_l_1722;
	case 5926ULL: goto x86_l_1726;
	case 5930ULL: goto x86_l_172a;
	case 5937ULL: goto x86_l_1731;
	case 5939ULL: goto x86_l_1733;
	case 5942ULL: goto x86_l_1736;
	case 5947ULL: goto x86_l_173b;
	case 5952ULL: goto x86_l_1740;
	case 5956ULL: goto x86_l_1744;
	case 5961ULL: goto x86_l_1749;
	case 5963ULL: goto x86_l_174b;
	case 5965ULL: goto x86_l_174d;
	case 5971ULL: goto x86_l_1753;
	case 5981ULL: goto x86_l_175d;
	case 5987ULL: goto x86_l_1763;
	case 5995ULL: goto x86_l_176b;
	case 5999ULL: goto x86_l_176f;
	case 6003ULL: goto x86_l_1773;
	case 6013ULL: goto x86_l_177d;
	case 6015ULL: goto x86_l_177f;
	case 6018ULL: goto x86_l_1782;
	case 6023ULL: goto x86_l_1787;
	case 6028ULL: goto x86_l_178c;
	case 6032ULL: goto x86_l_1790;
	case 6037ULL: goto x86_l_1795;
	case 6039ULL: goto x86_l_1797;
	case 6041ULL: goto x86_l_1799;
	case 6047ULL: goto x86_l_179f;
	case 6057ULL: goto x86_l_17a9;
	case 6063ULL: goto x86_l_17af;
	case 6071ULL: goto x86_l_17b7;
	case 6075ULL: goto x86_l_17bb;
	case 6079ULL: goto x86_l_17bf;
	case 6089ULL: goto x86_l_17c9;
	case 6091ULL: goto x86_l_17cb;
	case 6094ULL: goto x86_l_17ce;
	case 6099ULL: goto x86_l_17d3;
	case 6104ULL: goto x86_l_17d8;
	case 6108ULL: goto x86_l_17dc;
	case 6113ULL: goto x86_l_17e1;
	case 6115ULL: goto x86_l_17e3;
	case 6117ULL: goto x86_l_17e5;
	case 6123ULL: goto x86_l_17eb;
	case 6133ULL: goto x86_l_17f5;
	case 6139ULL: goto x86_l_17fb;
	case 6147ULL: goto x86_l_1803;
	case 6151ULL: goto x86_l_1807;
	case 6155ULL: goto x86_l_180b;
	case 6165ULL: goto x86_l_1815;
	case 6167ULL: goto x86_l_1817;
	case 6170ULL: goto x86_l_181a;
	case 6175ULL: goto x86_l_181f;
	case 6180ULL: goto x86_l_1824;
	case 6184ULL: goto x86_l_1828;
	case 6189ULL: goto x86_l_182d;
	case 6191ULL: goto x86_l_182f;
	case 6193ULL: goto x86_l_1831;
	case 6199ULL: goto x86_l_1837;
	case 6209ULL: goto x86_l_1841;
	case 6215ULL: goto x86_l_1847;
	case 6223ULL: goto x86_l_184f;
	case 6227ULL: goto x86_l_1853;
	case 6231ULL: goto x86_l_1857;
	case 6241ULL: goto x86_l_1861;
	case 6243ULL: goto x86_l_1863;
	case 6246ULL: goto x86_l_1866;
	case 6251ULL: goto x86_l_186b;
	case 6256ULL: goto x86_l_1870;
	case 6260ULL: goto x86_l_1874;
	case 6265ULL: goto x86_l_1879;
	case 6267ULL: goto x86_l_187b;
	case 6269ULL: goto x86_l_187d;
	case 6275ULL: goto x86_l_1883;
	case 6285ULL: goto x86_l_188d;
	case 6291ULL: goto x86_l_1893;
	case 6299ULL: goto x86_l_189b;
	case 6303ULL: goto x86_l_189f;
	case 6307ULL: goto x86_l_18a3;
	case 6317ULL: goto x86_l_18ad;
	case 6319ULL: goto x86_l_18af;
	case 6322ULL: goto x86_l_18b2;
	case 6327ULL: goto x86_l_18b7;
	case 6332ULL: goto x86_l_18bc;
	case 6336ULL: goto x86_l_18c0;
	case 6341ULL: goto x86_l_18c5;
	case 6343ULL: goto x86_l_18c7;
	case 6345ULL: goto x86_l_18c9;
	case 6351ULL: goto x86_l_18cf;
	case 6361ULL: goto x86_l_18d9;
	case 6367ULL: goto x86_l_18df;
	case 6375ULL: goto x86_l_18e7;
	case 6379ULL: goto x86_l_18eb;
	case 6383ULL: goto x86_l_18ef;
	case 6393ULL: goto x86_l_18f9;
	case 6395ULL: goto x86_l_18fb;
	case 6398ULL: goto x86_l_18fe;
	case 6403ULL: goto x86_l_1903;
	case 6408ULL: goto x86_l_1908;
	case 6412ULL: goto x86_l_190c;
	case 6417ULL: goto x86_l_1911;
	case 6419ULL: goto x86_l_1913;
	case 6421ULL: goto x86_l_1915;
	case 6427ULL: goto x86_l_191b;
	case 6437ULL: goto x86_l_1925;
	case 6443ULL: goto x86_l_192b;
	case 6451ULL: goto x86_l_1933;
	case 6455ULL: goto x86_l_1937;
	case 6459ULL: goto x86_l_193b;
	case 6469ULL: goto x86_l_1945;
	case 6471ULL: goto x86_l_1947;
	case 6474ULL: goto x86_l_194a;
	case 6479ULL: goto x86_l_194f;
	case 6484ULL: goto x86_l_1954;
	case 6488ULL: goto x86_l_1958;
	case 6493ULL: goto x86_l_195d;
	case 6495ULL: goto x86_l_195f;
	case 6497ULL: goto x86_l_1961;
	case 6503ULL: goto x86_l_1967;
	case 6508ULL: goto x86_l_196c;
	case 6518ULL: goto x86_l_1976;
	case 6524ULL: goto x86_l_197c;
	case 6532ULL: goto x86_l_1984;
	case 6536ULL: goto x86_l_1988;
	case 6540ULL: goto x86_l_198c;
	case 6550ULL: goto x86_l_1996;
	case 6556ULL: goto x86_l_199c;
	case 6559ULL: goto x86_l_199f;
	case 6564ULL: goto x86_l_19a4;
	case 6569ULL: goto x86_l_19a9;
	case 6574ULL: goto x86_l_19ae;
	case 6577ULL: goto x86_l_19b1;
	case 6579ULL: goto x86_l_19b3;
	case 6582ULL: goto x86_l_19b6;
	case 6587ULL: goto x86_l_19bb;
	case 6592ULL: goto x86_l_19c0;
	case 6596ULL: goto x86_l_19c4;
	case 6601ULL: goto x86_l_19c9;
	case 6603ULL: goto x86_l_19cb;
	case 6605ULL: goto x86_l_19cd;
	case 6611ULL: goto x86_l_19d3;
	case 6618ULL: goto x86_l_19da;
	case 6624ULL: goto x86_l_19e0;
	case 6629ULL: goto x86_l_19e5;
	case 6633ULL: goto x86_l_19e9;
	case 6637ULL: goto x86_l_19ed;
	case 6644ULL: goto x86_l_19f4;
	case 6646ULL: goto x86_l_19f6;
	case 6649ULL: goto x86_l_19f9;
	case 6654ULL: goto x86_l_19fe;
	case 6659ULL: goto x86_l_1a03;
	case 6663ULL: goto x86_l_1a07;
	case 6668ULL: goto x86_l_1a0c;
	case 6670ULL: goto x86_l_1a0e;
	case 6672ULL: goto x86_l_1a10;
	case 6678ULL: goto x86_l_1a16;
	case 6688ULL: goto x86_l_1a20;
	case 6694ULL: goto x86_l_1a26;
	case 6702ULL: goto x86_l_1a2e;
	case 6706ULL: goto x86_l_1a32;
	case 6710ULL: goto x86_l_1a36;
	case 6720ULL: goto x86_l_1a40;
	case 6722ULL: goto x86_l_1a42;
	case 6725ULL: goto x86_l_1a45;
	case 6730ULL: goto x86_l_1a4a;
	case 6735ULL: goto x86_l_1a4f;
	case 6739ULL: goto x86_l_1a53;
	case 6744ULL: goto x86_l_1a58;
	case 6746ULL: goto x86_l_1a5a;
	case 6748ULL: goto x86_l_1a5c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1345:
	/* 0x1345: jmp    1616 <generic_sleepable_preload+0x1616> */
	goto x86_l_1616;
x86_l_134a:
	/* 0x134a: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_134d:
	/* 0x134d: je     136f <generic_sleepable_preload+0x136f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_136f;
	}
x86_l_134f:
	/* 0x134f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1352:
	/* 0x1352: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1357:
	/* 0x1357: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_135c:
	/* 0x135c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1360:
	/* 0x1360: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1365:
	/* 0x1365: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1367:
	/* 0x1367: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1369:
	/* 0x1369: js     1633 <generic_sleepable_preload+0x1633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1633;
	}
x86_l_136f:
	/* 0x136f: cmp    WORD PTR [r12+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_1376:
	/* 0x1376: je     1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_137c:
	/* 0x137c: mov    ecx,DWORD PTR [r12+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1381:
	/* 0x1381: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1385:
	/* 0x1385: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1389:
	/* 0x1389: cmp    WORD PTR [r12+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_1390:
	/* 0x1390: je     13b2 <generic_sleepable_preload+0x13b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13b2;
	}
x86_l_1392:
	/* 0x1392: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1395:
	/* 0x1395: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_139a:
	/* 0x139a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_139f:
	/* 0x139f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13a3:
	/* 0x13a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13a8:
	/* 0x13a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13aa:
	/* 0x13aa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13ac:
	/* 0x13ac: js     1ca1 <generic_sleepable_preload+0x1ca1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7329ULL;
	}
x86_l_13b2:
	/* 0x13b2: cmp    WORD PTR [r12+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_13bc:
	/* 0x13bc: je     1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_13c2:
	/* 0x13c2: mov    ecx,DWORD PTR [r12+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_13ca:
	/* 0x13ca: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_13ce:
	/* 0x13ce: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13d2:
	/* 0x13d2: cmp    WORD PTR [r12+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_13dc:
	/* 0x13dc: je     13fe <generic_sleepable_preload+0x13fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13fe;
	}
x86_l_13de:
	/* 0x13de: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_13e1:
	/* 0x13e1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_13e6:
	/* 0x13e6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_13eb:
	/* 0x13eb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
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
	/* 0x13f8: js     1cb2 <generic_sleepable_preload+0x1cb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7346ULL;
	}
x86_l_13fe:
	/* 0x13fe: cmp    WORD PTR [r12+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1408:
	/* 0x1408: je     1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_140e:
	/* 0x140e: mov    ecx,DWORD PTR [r12+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1416:
	/* 0x1416: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_141a:
	/* 0x141a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_141e:
	/* 0x141e: cmp    WORD PTR [r12+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1428:
	/* 0x1428: je     144a <generic_sleepable_preload+0x144a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_144a;
	}
x86_l_142a:
	/* 0x142a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_142d:
	/* 0x142d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1432:
	/* 0x1432: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1437:
	/* 0x1437: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_143b:
	/* 0x143b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1440:
	/* 0x1440: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1442:
	/* 0x1442: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1444:
	/* 0x1444: js     1cc3 <generic_sleepable_preload+0x1cc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7363ULL;
	}
x86_l_144a:
	/* 0x144a: cmp    WORD PTR [r12+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1454:
	/* 0x1454: je     1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_145a:
	/* 0x145a: mov    ecx,DWORD PTR [r12+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1462:
	/* 0x1462: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1466:
	/* 0x1466: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_146a:
	/* 0x146a: cmp    WORD PTR [r12+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1474:
	/* 0x1474: je     1496 <generic_sleepable_preload+0x1496> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1496;
	}
x86_l_1476:
	/* 0x1476: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1479:
	/* 0x1479: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_147e:
	/* 0x147e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1483:
	/* 0x1483: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1487:
	/* 0x1487: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_148c:
	/* 0x148c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_148e:
	/* 0x148e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1490:
	/* 0x1490: js     1cd4 <generic_sleepable_preload+0x1cd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7380ULL;
	}
x86_l_1496:
	/* 0x1496: cmp    WORD PTR [r12+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_14a0:
	/* 0x14a0: je     1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_14a6:
	/* 0x14a6: mov    ecx,DWORD PTR [r12+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_14ae:
	/* 0x14ae: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_14b2:
	/* 0x14b2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14b6:
	/* 0x14b6: cmp    WORD PTR [r12+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_14c0:
	/* 0x14c0: je     14e2 <generic_sleepable_preload+0x14e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14e2;
	}
x86_l_14c2:
	/* 0x14c2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_14c5:
	/* 0x14c5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_14ca:
	/* 0x14ca: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_14cf:
	/* 0x14cf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14d3:
	/* 0x14d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14d8:
	/* 0x14d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14da:
	/* 0x14da: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14dc:
	/* 0x14dc: js     1ce5 <generic_sleepable_preload+0x1ce5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7397ULL;
	}
x86_l_14e2:
	/* 0x14e2: cmp    WORD PTR [r12+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_14ec:
	/* 0x14ec: je     1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_14f2:
	/* 0x14f2: mov    ecx,DWORD PTR [r12+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_14fa:
	/* 0x14fa: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_14fe:
	/* 0x14fe: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1502:
	/* 0x1502: cmp    WORD PTR [r12+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_150c:
	/* 0x150c: je     152e <generic_sleepable_preload+0x152e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_152e;
	}
x86_l_150e:
	/* 0x150e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1511:
	/* 0x1511: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1516:
	/* 0x1516: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_151b:
	/* 0x151b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_151f:
	/* 0x151f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1524:
	/* 0x1524: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1526:
	/* 0x1526: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1528:
	/* 0x1528: js     1cf6 <generic_sleepable_preload+0x1cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7414ULL;
	}
x86_l_152e:
	/* 0x152e: cmp    WORD PTR [r12+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1538:
	/* 0x1538: je     1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_153e:
	/* 0x153e: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_1541:
	/* 0x1541: mov    ecx,DWORD PTR [r12+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1549:
	/* 0x1549: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_154d:
	/* 0x154d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1551:
	/* 0x1551: cmp    WORD PTR [r12+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_155b:
	/* 0x155b: je     157d <generic_sleepable_preload+0x157d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_157d;
	}
x86_l_155d:
	/* 0x155d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1560:
	/* 0x1560: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1565:
	/* 0x1565: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_156a:
	/* 0x156a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_156e:
	/* 0x156e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1573:
	/* 0x1573: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1575:
	/* 0x1575: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1577:
	/* 0x1577: js     5c4e <generic_sleepable_preload+0x5c4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23630ULL;
	}
x86_l_157d:
	/* 0x157d: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1582:
	/* 0x1582: cmp    WORD PTR [r12+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_158c:
	/* 0x158c: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_158f:
	/* 0x158f: je     1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_1595:
	/* 0x1595: mov    ecx,DWORD PTR [r12+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_159d:
	/* 0x159d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_15a1:
	/* 0x15a1: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15a5:
	/* 0x15a5: cmp    WORD PTR [r12+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_15af:
	/* 0x15af: je     15d1 <generic_sleepable_preload+0x15d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15d1;
	}
x86_l_15b1:
	/* 0x15b1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_15b4:
	/* 0x15b4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_15b9:
	/* 0x15b9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_15be:
	/* 0x15be: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15c2:
	/* 0x15c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15c7:
	/* 0x15c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15c9:
	/* 0x15c9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15cb:
	/* 0x15cb: js     5d46 <generic_sleepable_preload+0x5d46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23878ULL;
	}
x86_l_15d1:
	/* 0x15d1: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15d6:
	/* 0x15d6: cmp    WORD PTR [r12+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_15e0:
	/* 0x15e0: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_15e3:
	/* 0x15e3: je     1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_15e9:
	/* 0x15e9: mov    ecx,DWORD PTR [r12+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_15f1:
	/* 0x15f1: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_15f5:
	/* 0x15f5: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15f9:
	/* 0x15f9: cmp    WORD PTR [r12+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1603:
	/* 0x1603: je     1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_1609:
	/* 0x1609: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_160c:
	/* 0x160c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1611:
	/* 0x1611: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1616:
	/* 0x1616: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_161a:
	/* 0x161a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_161f:
	/* 0x161f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1621:
	/* 0x1621: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1623:
	/* 0x1623: jns    1cfe <generic_sleepable_preload+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 7422ULL;
	}
x86_l_1629:
	/* 0x1629: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_162e:
	/* 0x162e: jmp    1cfb <generic_sleepable_preload+0x1cfb> */
	return 7419ULL;
x86_l_1633:
	/* 0x1633: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_1638:
	/* 0x1638: jmp    1cfb <generic_sleepable_preload+0x1cfb> */
	return 7419ULL;
x86_l_163d:
	/* 0x163d: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1645:
	/* 0x1645: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1648:
	/* 0x1648: je     1699 <generic_sleepable_preload+0x1699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1699;
	}
x86_l_164a:
	/* 0x164a: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_164f:
	/* 0x164f: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1652:
	/* 0x1652: je     1699 <generic_sleepable_preload+0x1699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1699;
	}
x86_l_1654:
	/* 0x1654: jmp    16ac <generic_sleepable_preload+0x16ac> */
	goto x86_l_16ac;
x86_l_1656:
	/* 0x1656: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_165b:
	/* 0x165b: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_165e:
	/* 0x165e: je     1699 <generic_sleepable_preload+0x1699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1699;
	}
x86_l_1660:
	/* 0x1660: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1665:
	/* 0x1665: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1668:
	/* 0x1668: je     1699 <generic_sleepable_preload+0x1699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1699;
	}
x86_l_166a:
	/* 0x166a: jmp    16ac <generic_sleepable_preload+0x16ac> */
	goto x86_l_16ac;
x86_l_166c:
	/* 0x166c: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1674:
	/* 0x1674: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_1677:
	/* 0x1677: je     1699 <generic_sleepable_preload+0x1699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1699;
	}
x86_l_1679:
	/* 0x1679: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_167e:
	/* 0x167e: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1681:
	/* 0x1681: je     1699 <generic_sleepable_preload+0x1699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1699;
	}
x86_l_1683:
	/* 0x1683: jmp    16ac <generic_sleepable_preload+0x16ac> */
	goto x86_l_16ac;
x86_l_1685:
	/* 0x1685: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_168a:
	/* 0x168a: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_168d:
	/* 0x168d: je     1699 <generic_sleepable_preload+0x1699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1699;
	}
x86_l_168f:
	/* 0x168f: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1694:
	/* 0x1694: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1697:
	/* 0x1697: jne    16ac <generic_sleepable_preload+0x16ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16ac;
	}
x86_l_1699:
	/* 0x1699: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_169c:
	/* 0x169c: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_169e:
	/* 0x169e: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_16a0:
	/* 0x16a0: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_16a5:
	/* 0x16a5: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_16a7:
	/* 0x16a7: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_16ac:
	/* 0x16ac: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16b0:
	/* 0x16b0: mov    ebp,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16b5:
	/* 0x16b5: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16b7:
	/* 0x16b7: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_16ba:
	/* 0x16ba: cmp    WORD PTR [r12+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_16c1:
	/* 0x16c1: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7561ULL;
	}
x86_l_16c7:
	/* 0x16c7: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_16ce:
	/* 0x16ce: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_16d1:
	/* 0x16d1: mov    eax,DWORD PTR [r12+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_16d6:
	/* 0x16d6: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16d9:
	/* 0x16d9: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16dd:
	/* 0x16dd: movzx  eax,WORD PTR [r12+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_16e3:
	/* 0x16e3: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_16e5:
	/* 0x16e5: je     19ae <generic_sleepable_preload+0x19ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19ae;
	}
x86_l_16eb:
	/* 0x16eb: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_16ee:
	/* 0x16ee: je     1710 <generic_sleepable_preload+0x1710> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1710;
	}
x86_l_16f0:
	/* 0x16f0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_16f3:
	/* 0x16f3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_16f8:
	/* 0x16f8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_16fd:
	/* 0x16fd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1701:
	/* 0x1701: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1706:
	/* 0x1706: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1708:
	/* 0x1708: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_170a:
	/* 0x170a: js     1c97 <generic_sleepable_preload+0x1c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7319ULL;
	}
x86_l_1710:
	/* 0x1710: cmp    WORD PTR [r12+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_1717:
	/* 0x1717: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7561ULL;
	}
x86_l_171d:
	/* 0x171d: mov    ecx,DWORD PTR [r12+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1722:
	/* 0x1722: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1726:
	/* 0x1726: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_172a:
	/* 0x172a: cmp    WORD PTR [r12+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_1731:
	/* 0x1731: je     1753 <generic_sleepable_preload+0x1753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1753;
	}
x86_l_1733:
	/* 0x1733: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1736:
	/* 0x1736: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_173b:
	/* 0x173b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1740:
	/* 0x1740: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1744:
	/* 0x1744: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1749:
	/* 0x1749: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_174b:
	/* 0x174b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_174d:
	/* 0x174d: js     1ca8 <generic_sleepable_preload+0x1ca8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7336ULL;
	}
x86_l_1753:
	/* 0x1753: cmp    WORD PTR [r12+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_175d:
	/* 0x175d: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7561ULL;
	}
x86_l_1763:
	/* 0x1763: mov    ecx,DWORD PTR [r12+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_176b:
	/* 0x176b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_176f:
	/* 0x176f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1773:
	/* 0x1773: cmp    WORD PTR [r12+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_177d:
	/* 0x177d: je     179f <generic_sleepable_preload+0x179f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_179f;
	}
x86_l_177f:
	/* 0x177f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1782:
	/* 0x1782: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1787:
	/* 0x1787: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_178c:
	/* 0x178c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1790:
	/* 0x1790: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1795:
	/* 0x1795: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1797:
	/* 0x1797: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1799:
	/* 0x1799: js     1cb9 <generic_sleepable_preload+0x1cb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7353ULL;
	}
x86_l_179f:
	/* 0x179f: cmp    WORD PTR [r12+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_17a9:
	/* 0x17a9: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7561ULL;
	}
x86_l_17af:
	/* 0x17af: mov    ecx,DWORD PTR [r12+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_17b7:
	/* 0x17b7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_17bb:
	/* 0x17bb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17bf:
	/* 0x17bf: cmp    WORD PTR [r12+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_17c9:
	/* 0x17c9: je     17eb <generic_sleepable_preload+0x17eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17eb;
	}
x86_l_17cb:
	/* 0x17cb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_17ce:
	/* 0x17ce: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_17d3:
	/* 0x17d3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_17d8:
	/* 0x17d8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17dc:
	/* 0x17dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17e1:
	/* 0x17e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17e3:
	/* 0x17e3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17e5:
	/* 0x17e5: js     1cca <generic_sleepable_preload+0x1cca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7370ULL;
	}
x86_l_17eb:
	/* 0x17eb: cmp    WORD PTR [r12+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_17f5:
	/* 0x17f5: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7561ULL;
	}
x86_l_17fb:
	/* 0x17fb: mov    ecx,DWORD PTR [r12+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1803:
	/* 0x1803: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1807:
	/* 0x1807: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_180b:
	/* 0x180b: cmp    WORD PTR [r12+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1815:
	/* 0x1815: je     1837 <generic_sleepable_preload+0x1837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1837;
	}
x86_l_1817:
	/* 0x1817: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_181a:
	/* 0x181a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_181f:
	/* 0x181f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1824:
	/* 0x1824: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1828:
	/* 0x1828: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_182d:
	/* 0x182d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_182f:
	/* 0x182f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1831:
	/* 0x1831: js     1cdb <generic_sleepable_preload+0x1cdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7387ULL;
	}
x86_l_1837:
	/* 0x1837: cmp    WORD PTR [r12+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_1841:
	/* 0x1841: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7561ULL;
	}
x86_l_1847:
	/* 0x1847: mov    ecx,DWORD PTR [r12+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_184f:
	/* 0x184f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1853:
	/* 0x1853: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1857:
	/* 0x1857: cmp    WORD PTR [r12+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1861:
	/* 0x1861: je     1883 <generic_sleepable_preload+0x1883> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1883;
	}
x86_l_1863:
	/* 0x1863: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1866:
	/* 0x1866: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_186b:
	/* 0x186b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1870:
	/* 0x1870: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1874:
	/* 0x1874: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1879:
	/* 0x1879: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_187b:
	/* 0x187b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_187d:
	/* 0x187d: js     1cec <generic_sleepable_preload+0x1cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7404ULL;
	}
x86_l_1883:
	/* 0x1883: cmp    WORD PTR [r12+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_188d:
	/* 0x188d: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7561ULL;
	}
x86_l_1893:
	/* 0x1893: mov    ecx,DWORD PTR [r12+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_189b:
	/* 0x189b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_189f:
	/* 0x189f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18a3:
	/* 0x18a3: cmp    WORD PTR [r12+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_18ad:
	/* 0x18ad: je     18cf <generic_sleepable_preload+0x18cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18cf;
	}
x86_l_18af:
	/* 0x18af: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_18b2:
	/* 0x18b2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_18b7:
	/* 0x18b7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_18bc:
	/* 0x18bc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18c0:
	/* 0x18c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18c5:
	/* 0x18c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c7:
	/* 0x18c7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18c9:
	/* 0x18c9: js     1d81 <generic_sleepable_preload+0x1d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7553ULL;
	}
x86_l_18cf:
	/* 0x18cf: cmp    WORD PTR [r12+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_18d9:
	/* 0x18d9: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7561ULL;
	}
x86_l_18df:
	/* 0x18df: mov    ecx,DWORD PTR [r12+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_18e7:
	/* 0x18e7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_18eb:
	/* 0x18eb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18ef:
	/* 0x18ef: cmp    WORD PTR [r12+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_18f9:
	/* 0x18f9: je     191b <generic_sleepable_preload+0x191b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_191b;
	}
x86_l_18fb:
	/* 0x18fb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_18fe:
	/* 0x18fe: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1903:
	/* 0x1903: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1908:
	/* 0x1908: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_190c:
	/* 0x190c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1911:
	/* 0x1911: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1913:
	/* 0x1913: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1915:
	/* 0x1915: js     5bdd <generic_sleepable_preload+0x5bdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23517ULL;
	}
x86_l_191b:
	/* 0x191b: cmp    WORD PTR [r12+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1925:
	/* 0x1925: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7561ULL;
	}
x86_l_192b:
	/* 0x192b: mov    ecx,DWORD PTR [r12+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1933:
	/* 0x1933: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1937:
	/* 0x1937: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_193b:
	/* 0x193b: cmp    WORD PTR [r12+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1945:
	/* 0x1945: je     1967 <generic_sleepable_preload+0x1967> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1967;
	}
x86_l_1947:
	/* 0x1947: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_194a:
	/* 0x194a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_194f:
	/* 0x194f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1954:
	/* 0x1954: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1958:
	/* 0x1958: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_195d:
	/* 0x195d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_195f:
	/* 0x195f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1961:
	/* 0x1961: js     5cc8 <generic_sleepable_preload+0x5cc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23752ULL;
	}
x86_l_1967:
	/* 0x1967: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_196c:
	/* 0x196c: cmp    WORD PTR [r12+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1976:
	/* 0x1976: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7561ULL;
	}
x86_l_197c:
	/* 0x197c: mov    ecx,DWORD PTR [r12+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1984:
	/* 0x1984: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1988:
	/* 0x1988: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_198c:
	/* 0x198c: cmp    WORD PTR [r12+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1996:
	/* 0x1996: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7561ULL;
	}
x86_l_199c:
	/* 0x199c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_199f:
	/* 0x199f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19a4:
	/* 0x19a4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_19a9:
	/* 0x19a9: jmp    1c7a <generic_sleepable_preload+0x1c7a> */
	return 7290ULL;
x86_l_19ae:
	/* 0x19ae: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_19b1:
	/* 0x19b1: je     19d3 <generic_sleepable_preload+0x19d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19d3;
	}
x86_l_19b3:
	/* 0x19b3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_19b6:
	/* 0x19b6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19bb:
	/* 0x19bb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_19c0:
	/* 0x19c0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19c4:
	/* 0x19c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19c9:
	/* 0x19c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19cb:
	/* 0x19cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19cd:
	/* 0x19cd: js     1c97 <generic_sleepable_preload+0x1c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7319ULL;
	}
x86_l_19d3:
	/* 0x19d3: cmp    WORD PTR [r12+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_19da:
	/* 0x19da: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7561ULL;
	}
x86_l_19e0:
	/* 0x19e0: mov    ecx,DWORD PTR [r12+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_19e5:
	/* 0x19e5: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_19e9:
	/* 0x19e9: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19ed:
	/* 0x19ed: cmp    WORD PTR [r12+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_19f4:
	/* 0x19f4: je     1a16 <generic_sleepable_preload+0x1a16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a16;
	}
x86_l_19f6:
	/* 0x19f6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_19f9:
	/* 0x19f9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19fe:
	/* 0x19fe: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a03:
	/* 0x1a03: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a07:
	/* 0x1a07: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a0c:
	/* 0x1a0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a0e:
	/* 0x1a0e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a10:
	/* 0x1a10: js     1ca8 <generic_sleepable_preload+0x1ca8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7336ULL;
	}
x86_l_1a16:
	/* 0x1a16: cmp    WORD PTR [r12+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_1a20:
	/* 0x1a20: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7561ULL;
	}
x86_l_1a26:
	/* 0x1a26: mov    ecx,DWORD PTR [r12+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a2e:
	/* 0x1a2e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1a32:
	/* 0x1a32: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a36:
	/* 0x1a36: cmp    WORD PTR [r12+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1a40:
	/* 0x1a40: je     1a62 <generic_sleepable_preload+0x1a62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6754ULL;
	}
x86_l_1a42:
	/* 0x1a42: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a45:
	/* 0x1a45: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a4a:
	/* 0x1a4a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a4f:
	/* 0x1a4f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a53:
	/* 0x1a53: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a58:
	/* 0x1a58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a5a:
	/* 0x1a5a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a5c:
	/* 0x1a5c: js     1cb9 <generic_sleepable_preload+0x1cb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7353ULL;
	}
	return 6754ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6754ULL: goto x86_l_1a62;
	case 6764ULL: goto x86_l_1a6c;
	case 6770ULL: goto x86_l_1a72;
	case 6778ULL: goto x86_l_1a7a;
	case 6782ULL: goto x86_l_1a7e;
	case 6786ULL: goto x86_l_1a82;
	case 6796ULL: goto x86_l_1a8c;
	case 6798ULL: goto x86_l_1a8e;
	case 6801ULL: goto x86_l_1a91;
	case 6806ULL: goto x86_l_1a96;
	case 6811ULL: goto x86_l_1a9b;
	case 6815ULL: goto x86_l_1a9f;
	case 6820ULL: goto x86_l_1aa4;
	case 6822ULL: goto x86_l_1aa6;
	case 6824ULL: goto x86_l_1aa8;
	case 6830ULL: goto x86_l_1aae;
	case 6840ULL: goto x86_l_1ab8;
	case 6846ULL: goto x86_l_1abe;
	case 6854ULL: goto x86_l_1ac6;
	case 6858ULL: goto x86_l_1aca;
	case 6862ULL: goto x86_l_1ace;
	case 6872ULL: goto x86_l_1ad8;
	case 6874ULL: goto x86_l_1ada;
	case 6877ULL: goto x86_l_1add;
	case 6882ULL: goto x86_l_1ae2;
	case 6887ULL: goto x86_l_1ae7;
	case 6891ULL: goto x86_l_1aeb;
	case 6896ULL: goto x86_l_1af0;
	case 6898ULL: goto x86_l_1af2;
	case 6900ULL: goto x86_l_1af4;
	case 6906ULL: goto x86_l_1afa;
	case 6916ULL: goto x86_l_1b04;
	case 6922ULL: goto x86_l_1b0a;
	case 6930ULL: goto x86_l_1b12;
	case 6934ULL: goto x86_l_1b16;
	case 6938ULL: goto x86_l_1b1a;
	case 6948ULL: goto x86_l_1b24;
	case 6950ULL: goto x86_l_1b26;
	case 6953ULL: goto x86_l_1b29;
	case 6958ULL: goto x86_l_1b2e;
	case 6963ULL: goto x86_l_1b33;
	case 6967ULL: goto x86_l_1b37;
	case 6972ULL: goto x86_l_1b3c;
	case 6974ULL: goto x86_l_1b3e;
	case 6976ULL: goto x86_l_1b40;
	case 6982ULL: goto x86_l_1b46;
	case 6992ULL: goto x86_l_1b50;
	case 6998ULL: goto x86_l_1b56;
	case 7006ULL: goto x86_l_1b5e;
	case 7010ULL: goto x86_l_1b62;
	case 7014ULL: goto x86_l_1b66;
	case 7024ULL: goto x86_l_1b70;
	case 7026ULL: goto x86_l_1b72;
	case 7029ULL: goto x86_l_1b75;
	case 7034ULL: goto x86_l_1b7a;
	case 7039ULL: goto x86_l_1b7f;
	case 7043ULL: goto x86_l_1b83;
	case 7048ULL: goto x86_l_1b88;
	case 7050ULL: goto x86_l_1b8a;
	case 7052ULL: goto x86_l_1b8c;
	case 7058ULL: goto x86_l_1b92;
	case 7068ULL: goto x86_l_1b9c;
	case 7074ULL: goto x86_l_1ba2;
	case 7077ULL: goto x86_l_1ba5;
	case 7085ULL: goto x86_l_1bad;
	case 7089ULL: goto x86_l_1bb1;
	case 7093ULL: goto x86_l_1bb5;
	case 7103ULL: goto x86_l_1bbf;
	case 7105ULL: goto x86_l_1bc1;
	case 7108ULL: goto x86_l_1bc4;
	case 7113ULL: goto x86_l_1bc9;
	case 7118ULL: goto x86_l_1bce;
	case 7122ULL: goto x86_l_1bd2;
	case 7127ULL: goto x86_l_1bd7;
	case 7129ULL: goto x86_l_1bd9;
	case 7131ULL: goto x86_l_1bdb;
	case 7137ULL: goto x86_l_1be1;
	case 7142ULL: goto x86_l_1be6;
	case 7152ULL: goto x86_l_1bf0;
	case 7155ULL: goto x86_l_1bf3;
	case 7161ULL: goto x86_l_1bf9;
	case 7169ULL: goto x86_l_1c01;
	case 7173ULL: goto x86_l_1c05;
	case 7177ULL: goto x86_l_1c09;
	case 7187ULL: goto x86_l_1c13;
	case 7189ULL: goto x86_l_1c15;
	case 7192ULL: goto x86_l_1c18;
	case 7197ULL: goto x86_l_1c1d;
	case 7202ULL: goto x86_l_1c22;
	case 7206ULL: goto x86_l_1c26;
	case 7211ULL: goto x86_l_1c2b;
	case 7213ULL: goto x86_l_1c2d;
	case 7215ULL: goto x86_l_1c2f;
	case 7221ULL: goto x86_l_1c35;
	case 7226ULL: goto x86_l_1c3a;
	case 7236ULL: goto x86_l_1c44;
	case 7239ULL: goto x86_l_1c47;
	case 7245ULL: goto x86_l_1c4d;
	case 7253ULL: goto x86_l_1c55;
	case 7257ULL: goto x86_l_1c59;
	case 7261ULL: goto x86_l_1c5d;
	case 7271ULL: goto x86_l_1c67;
	case 7277ULL: goto x86_l_1c6d;
	case 7280ULL: goto x86_l_1c70;
	case 7285ULL: goto x86_l_1c75;
	case 7290ULL: goto x86_l_1c7a;
	case 7294ULL: goto x86_l_1c7e;
	case 7299ULL: goto x86_l_1c83;
	case 7301ULL: goto x86_l_1c85;
	case 7303ULL: goto x86_l_1c87;
	case 7309ULL: goto x86_l_1c8d;
	case 7314ULL: goto x86_l_1c92;
	case 7319ULL: goto x86_l_1c97;
	case 7324ULL: goto x86_l_1c9c;
	case 7329ULL: goto x86_l_1ca1;
	case 7334ULL: goto x86_l_1ca6;
	case 7336ULL: goto x86_l_1ca8;
	case 7341ULL: goto x86_l_1cad;
	case 7346ULL: goto x86_l_1cb2;
	case 7351ULL: goto x86_l_1cb7;
	case 7353ULL: goto x86_l_1cb9;
	case 7358ULL: goto x86_l_1cbe;
	case 7363ULL: goto x86_l_1cc3;
	case 7368ULL: goto x86_l_1cc8;
	case 7370ULL: goto x86_l_1cca;
	case 7375ULL: goto x86_l_1ccf;
	case 7380ULL: goto x86_l_1cd4;
	case 7385ULL: goto x86_l_1cd9;
	case 7387ULL: goto x86_l_1cdb;
	case 7392ULL: goto x86_l_1ce0;
	case 7397ULL: goto x86_l_1ce5;
	case 7402ULL: goto x86_l_1cea;
	case 7404ULL: goto x86_l_1cec;
	case 7409ULL: goto x86_l_1cf1;
	case 7414ULL: goto x86_l_1cf6;
	case 7419ULL: goto x86_l_1cfb;
	case 7422ULL: goto x86_l_1cfe;
	case 7427ULL: goto x86_l_1d03;
	case 7430ULL: goto x86_l_1d06;
	case 7435ULL: goto x86_l_1d0b;
	case 7440ULL: goto x86_l_1d10;
	case 7445ULL: goto x86_l_1d15;
	case 7448ULL: goto x86_l_1d18;
	case 7450ULL: goto x86_l_1d1a;
	case 7453ULL: goto x86_l_1d1d;
	case 7459ULL: goto x86_l_1d23;
	case 7462ULL: goto x86_l_1d26;
	case 7466ULL: goto x86_l_1d2a;
	case 7471ULL: goto x86_l_1d2f;
	case 7473ULL: goto x86_l_1d31;
	case 7478ULL: goto x86_l_1d36;
	case 7486ULL: goto x86_l_1d3e;
	case 7493ULL: goto x86_l_1d45;
	case 7498ULL: goto x86_l_1d4a;
	case 7503ULL: goto x86_l_1d4f;
	case 7505ULL: goto x86_l_1d51;
	case 7508ULL: goto x86_l_1d54;
	case 7514ULL: goto x86_l_1d5a;
	case 7517ULL: goto x86_l_1d5d;
	case 7524ULL: goto x86_l_1d64;
	case 7526ULL: goto x86_l_1d66;
	case 7531ULL: goto x86_l_1d6b;
	case 7536ULL: goto x86_l_1d70;
	case 7539ULL: goto x86_l_1d73;
	case 7542ULL: goto x86_l_1d76;
	case 7544ULL: goto x86_l_1d78;
	case 7546ULL: goto x86_l_1d7a;
	case 7551ULL: goto x86_l_1d7f;
	case 7553ULL: goto x86_l_1d81;
	case 7558ULL: goto x86_l_1d86;
	case 7561ULL: goto x86_l_1d89;
	case 7564ULL: goto x86_l_1d8c;
	case 7570ULL: goto x86_l_1d92;
	case 7573ULL: goto x86_l_1d95;
	case 7577ULL: goto x86_l_1d99;
	case 7582ULL: goto x86_l_1d9e;
	case 7584ULL: goto x86_l_1da0;
	case 7589ULL: goto x86_l_1da5;
	case 7597ULL: goto x86_l_1dad;
	case 7604ULL: goto x86_l_1db4;
	case 7609ULL: goto x86_l_1db9;
	case 7614ULL: goto x86_l_1dbe;
	case 7616ULL: goto x86_l_1dc0;
	case 7619ULL: goto x86_l_1dc3;
	case 7621ULL: goto x86_l_1dc5;
	case 7624ULL: goto x86_l_1dc8;
	case 7631ULL: goto x86_l_1dcf;
	case 7633ULL: goto x86_l_1dd1;
	case 7638ULL: goto x86_l_1dd6;
	case 7643ULL: goto x86_l_1ddb;
	case 7646ULL: goto x86_l_1dde;
	case 7649ULL: goto x86_l_1de1;
	case 7651ULL: goto x86_l_1de3;
	case 7653ULL: goto x86_l_1de5;
	case 7658ULL: goto x86_l_1dea;
	case 7661ULL: goto x86_l_1ded;
	case 7664ULL: goto x86_l_1df0;
	case 7669ULL: goto x86_l_1df5;
	case 7671ULL: goto x86_l_1df7;
	case 7674ULL: goto x86_l_1dfa;
	case 7676ULL: goto x86_l_1dfc;
	case 7679ULL: goto x86_l_1dff;
	case 7681ULL: goto x86_l_1e01;
	case 7684ULL: goto x86_l_1e04;
	case 7688ULL: goto x86_l_1e08;
	case 7693ULL: goto x86_l_1e0d;
	case 7696ULL: goto x86_l_1e10;
	case 7698ULL: goto x86_l_1e12;
	case 7701ULL: goto x86_l_1e15;
	case 7706ULL: goto x86_l_1e1a;
	case 7708ULL: goto x86_l_1e1c;
	case 7711ULL: goto x86_l_1e1f;
	case 7713ULL: goto x86_l_1e21;
	case 7715ULL: goto x86_l_1e23;
	case 7720ULL: goto x86_l_1e28;
	case 7722ULL: goto x86_l_1e2a;
	case 7725ULL: goto x86_l_1e2d;
	case 7730ULL: goto x86_l_1e32;
	case 7735ULL: goto x86_l_1e37;
	case 7741ULL: goto x86_l_1e3d;
	case 7743ULL: goto x86_l_1e3f;
	case 7745ULL: goto x86_l_1e41;
	case 7750ULL: goto x86_l_1e46;
	case 7753ULL: goto x86_l_1e49;
	case 7759ULL: goto x86_l_1e4f;
	case 7762ULL: goto x86_l_1e52;
	case 7768ULL: goto x86_l_1e58;
	case 7771ULL: goto x86_l_1e5b;
	case 7777ULL: goto x86_l_1e61;
	case 7780ULL: goto x86_l_1e64;
	case 7786ULL: goto x86_l_1e6a;
	case 7791ULL: goto x86_l_1e6f;
	case 7796ULL: goto x86_l_1e74;
	case 7805ULL: goto x86_l_1e7d;
	case 7814ULL: goto x86_l_1e86;
	case 7820ULL: goto x86_l_1e8c;
	case 7822ULL: goto x86_l_1e8e;
	case 7825ULL: goto x86_l_1e91;
	case 7827ULL: goto x86_l_1e93;
	case 7830ULL: goto x86_l_1e96;
	case 7832ULL: goto x86_l_1e98;
	case 7835ULL: goto x86_l_1e9b;
	case 7841ULL: goto x86_l_1ea1;
	case 7846ULL: goto x86_l_1ea6;
	case 7849ULL: goto x86_l_1ea9;
	case 7855ULL: goto x86_l_1eaf;
	case 7860ULL: goto x86_l_1eb4;
	case 7863ULL: goto x86_l_1eb7;
	case 7869ULL: goto x86_l_1ebd;
	case 7874ULL: goto x86_l_1ec2;
	case 7877ULL: goto x86_l_1ec5;
	case 7883ULL: goto x86_l_1ecb;
	case 7888ULL: goto x86_l_1ed0;
	case 7891ULL: goto x86_l_1ed3;
	case 7893ULL: goto x86_l_1ed5;
	case 7896ULL: goto x86_l_1ed8;
	case 7902ULL: goto x86_l_1ede;
	case 7904ULL: goto x86_l_1ee0;
	case 7910ULL: goto x86_l_1ee6;
	case 7913ULL: goto x86_l_1ee9;
	case 7916ULL: goto x86_l_1eec;
	case 7922ULL: goto x86_l_1ef2;
	case 7927ULL: goto x86_l_1ef7;
	case 7929ULL: goto x86_l_1ef9;
	case 7931ULL: goto x86_l_1efb;
	case 7934ULL: goto x86_l_1efe;
	case 7936ULL: goto x86_l_1f00;
	case 7941ULL: goto x86_l_1f05;
	case 7943ULL: goto x86_l_1f07;
	case 7946ULL: goto x86_l_1f0a;
	case 7952ULL: goto x86_l_1f10;
	case 7960ULL: goto x86_l_1f18;
	case 7963ULL: goto x86_l_1f1b;
	case 7969ULL: goto x86_l_1f21;
	case 7974ULL: goto x86_l_1f26;
	case 7977ULL: goto x86_l_1f29;
	case 7983ULL: goto x86_l_1f2f;
	case 7988ULL: goto x86_l_1f34;
	case 7991ULL: goto x86_l_1f37;
	case 7997ULL: goto x86_l_1f3d;
	case 8005ULL: goto x86_l_1f45;
	case 8008ULL: goto x86_l_1f48;
	case 8014ULL: goto x86_l_1f4e;
	case 8019ULL: goto x86_l_1f53;
	case 8022ULL: goto x86_l_1f56;
	case 8028ULL: goto x86_l_1f5c;
	case 8033ULL: goto x86_l_1f61;
	case 8038ULL: goto x86_l_1f66;
	case 8040ULL: goto x86_l_1f68;
	case 8045ULL: goto x86_l_1f6d;
	case 8047ULL: goto x86_l_1f6f;
	case 8052ULL: goto x86_l_1f74;
	case 8055ULL: goto x86_l_1f77;
	case 8059ULL: goto x86_l_1f7b;
	case 8061ULL: goto x86_l_1f7d;
	case 8064ULL: goto x86_l_1f80;
	case 8074ULL: goto x86_l_1f8a;
	case 8080ULL: goto x86_l_1f90;
	case 8087ULL: goto x86_l_1f97;
	case 8090ULL: goto x86_l_1f9a;
	case 8098ULL: goto x86_l_1fa2;
	case 8101ULL: goto x86_l_1fa5;
	case 8105ULL: goto x86_l_1fa9;
	case 8114ULL: goto x86_l_1fb2;
	case 8116ULL: goto x86_l_1fb4;
	case 8122ULL: goto x86_l_1fba;
	case 8125ULL: goto x86_l_1fbd;
	case 8127ULL: goto x86_l_1fbf;
	case 8130ULL: goto x86_l_1fc2;
	case 8135ULL: goto x86_l_1fc7;
	case 8140ULL: goto x86_l_1fcc;
	case 8144ULL: goto x86_l_1fd0;
	case 8149ULL: goto x86_l_1fd5;
	case 8151ULL: goto x86_l_1fd7;
	case 8153ULL: goto x86_l_1fd9;
	case 8159ULL: goto x86_l_1fdf;
	case 8169ULL: goto x86_l_1fe9;
	case 8175ULL: goto x86_l_1fef;
	case 8183ULL: goto x86_l_1ff7;
	case 8187ULL: goto x86_l_1ffb;
	case 8191ULL: goto x86_l_1fff;
	case 8201ULL: goto x86_l_2009;
	case 8203ULL: goto x86_l_200b;
	case 8206ULL: goto x86_l_200e;
	case 8211ULL: goto x86_l_2013;
	case 8216ULL: goto x86_l_2018;
	case 8220ULL: goto x86_l_201c;
	case 8225ULL: goto x86_l_2021;
	case 8227ULL: goto x86_l_2023;
	case 8229ULL: goto x86_l_2025;
	case 8235ULL: goto x86_l_202b;
	case 8245ULL: goto x86_l_2035;
	case 8251ULL: goto x86_l_203b;
	case 8259ULL: goto x86_l_2043;
	case 8263ULL: goto x86_l_2047;
	case 8267ULL: goto x86_l_204b;
	case 8277ULL: goto x86_l_2055;
	case 8279ULL: goto x86_l_2057;
	case 8282ULL: goto x86_l_205a;
	case 8287ULL: goto x86_l_205f;
	case 8292ULL: goto x86_l_2064;
	case 8296ULL: goto x86_l_2068;
	case 8301ULL: goto x86_l_206d;
	case 8303ULL: goto x86_l_206f;
	case 8305ULL: goto x86_l_2071;
	case 8311ULL: goto x86_l_2077;
	case 8321ULL: goto x86_l_2081;
	case 8327ULL: goto x86_l_2087;
	case 8335ULL: goto x86_l_208f;
	case 8339ULL: goto x86_l_2093;
	case 8343ULL: goto x86_l_2097;
	case 8353ULL: goto x86_l_20a1;
	case 8355ULL: goto x86_l_20a3;
	case 8358ULL: goto x86_l_20a6;
	case 8363ULL: goto x86_l_20ab;
	case 8368ULL: goto x86_l_20b0;
	case 8372ULL: goto x86_l_20b4;
	case 8377ULL: goto x86_l_20b9;
	case 8379ULL: goto x86_l_20bb;
	case 8381ULL: goto x86_l_20bd;
	case 8387ULL: goto x86_l_20c3;
	case 8397ULL: goto x86_l_20cd;
	case 8403ULL: goto x86_l_20d3;
	case 8411ULL: goto x86_l_20db;
	case 8415ULL: goto x86_l_20df;
	case 8419ULL: goto x86_l_20e3;
	case 8429ULL: goto x86_l_20ed;
	case 8431ULL: goto x86_l_20ef;
	case 8434ULL: goto x86_l_20f2;
	case 8439ULL: goto x86_l_20f7;
	case 8444ULL: goto x86_l_20fc;
	case 8448ULL: goto x86_l_2100;
	case 8453ULL: goto x86_l_2105;
	case 8455ULL: goto x86_l_2107;
	case 8457ULL: goto x86_l_2109;
	case 8463ULL: goto x86_l_210f;
	case 8473ULL: goto x86_l_2119;
	case 8479ULL: goto x86_l_211f;
	case 8487ULL: goto x86_l_2127;
	case 8491ULL: goto x86_l_212b;
	case 8495ULL: goto x86_l_212f;
	case 8505ULL: goto x86_l_2139;
	case 8507ULL: goto x86_l_213b;
	case 8510ULL: goto x86_l_213e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1a62:
	/* 0x1a62: cmp    WORD PTR [r12+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1a6c:
	/* 0x1a6c: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d89;
	}
x86_l_1a72:
	/* 0x1a72: mov    ecx,DWORD PTR [r12+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1a7a:
	/* 0x1a7a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1a7e:
	/* 0x1a7e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a82:
	/* 0x1a82: cmp    WORD PTR [r12+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1a8c:
	/* 0x1a8c: je     1aae <generic_sleepable_preload+0x1aae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1aae;
	}
x86_l_1a8e:
	/* 0x1a8e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a91:
	/* 0x1a91: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a96:
	/* 0x1a96: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a9b:
	/* 0x1a9b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a9f:
	/* 0x1a9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1aa4:
	/* 0x1aa4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aa6:
	/* 0x1aa6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1aa8:
	/* 0x1aa8: js     1cca <generic_sleepable_preload+0x1cca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1cca;
	}
x86_l_1aae:
	/* 0x1aae: cmp    WORD PTR [r12+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1ab8:
	/* 0x1ab8: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d89;
	}
x86_l_1abe:
	/* 0x1abe: mov    ecx,DWORD PTR [r12+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1ac6:
	/* 0x1ac6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1aca:
	/* 0x1aca: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ace:
	/* 0x1ace: cmp    WORD PTR [r12+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1ad8:
	/* 0x1ad8: je     1afa <generic_sleepable_preload+0x1afa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1afa;
	}
x86_l_1ada:
	/* 0x1ada: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1add:
	/* 0x1add: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1ae2:
	/* 0x1ae2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1ae7:
	/* 0x1ae7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aeb:
	/* 0x1aeb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1af0:
	/* 0x1af0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1af2:
	/* 0x1af2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1af4:
	/* 0x1af4: js     1cdb <generic_sleepable_preload+0x1cdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1cdb;
	}
x86_l_1afa:
	/* 0x1afa: cmp    WORD PTR [r12+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_1b04:
	/* 0x1b04: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d89;
	}
x86_l_1b0a:
	/* 0x1b0a: mov    ecx,DWORD PTR [r12+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1b12:
	/* 0x1b12: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1b16:
	/* 0x1b16: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b1a:
	/* 0x1b1a: cmp    WORD PTR [r12+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1b24:
	/* 0x1b24: je     1b46 <generic_sleepable_preload+0x1b46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b46;
	}
x86_l_1b26:
	/* 0x1b26: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1b29:
	/* 0x1b29: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b2e:
	/* 0x1b2e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b33:
	/* 0x1b33: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b37:
	/* 0x1b37: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b3c:
	/* 0x1b3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b3e:
	/* 0x1b3e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b40:
	/* 0x1b40: js     1cec <generic_sleepable_preload+0x1cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1cec;
	}
x86_l_1b46:
	/* 0x1b46: cmp    WORD PTR [r12+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1b50:
	/* 0x1b50: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d89;
	}
x86_l_1b56:
	/* 0x1b56: mov    ecx,DWORD PTR [r12+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1b5e:
	/* 0x1b5e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1b62:
	/* 0x1b62: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b66:
	/* 0x1b66: cmp    WORD PTR [r12+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1b70:
	/* 0x1b70: je     1b92 <generic_sleepable_preload+0x1b92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b92;
	}
x86_l_1b72:
	/* 0x1b72: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1b75:
	/* 0x1b75: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b7a:
	/* 0x1b7a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b7f:
	/* 0x1b7f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b83:
	/* 0x1b83: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b88:
	/* 0x1b88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b8a:
	/* 0x1b8a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b8c:
	/* 0x1b8c: js     1d81 <generic_sleepable_preload+0x1d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1d81;
	}
x86_l_1b92:
	/* 0x1b92: cmp    WORD PTR [r12+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1b9c:
	/* 0x1b9c: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d89;
	}
x86_l_1ba2:
	/* 0x1ba2: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_1ba5:
	/* 0x1ba5: mov    ecx,DWORD PTR [r12+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1bad:
	/* 0x1bad: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1bb1:
	/* 0x1bb1: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bb5:
	/* 0x1bb5: cmp    WORD PTR [r12+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1bbf:
	/* 0x1bbf: je     1be1 <generic_sleepable_preload+0x1be1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1be1;
	}
x86_l_1bc1:
	/* 0x1bc1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1bc4:
	/* 0x1bc4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1bc9:
	/* 0x1bc9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1bce:
	/* 0x1bce: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bd2:
	/* 0x1bd2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bd7:
	/* 0x1bd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bd9:
	/* 0x1bd9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bdb:
	/* 0x1bdb: js     5c5b <generic_sleepable_preload+0x5c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23643ULL;
	}
x86_l_1be1:
	/* 0x1be1: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1be6:
	/* 0x1be6: cmp    WORD PTR [r12+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1bf0:
	/* 0x1bf0: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_1bf3:
	/* 0x1bf3: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d89;
	}
x86_l_1bf9:
	/* 0x1bf9: mov    ecx,DWORD PTR [r12+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1c01:
	/* 0x1c01: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1c05:
	/* 0x1c05: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c09:
	/* 0x1c09: cmp    WORD PTR [r12+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1c13:
	/* 0x1c13: je     1c35 <generic_sleepable_preload+0x1c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c35;
	}
x86_l_1c15:
	/* 0x1c15: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1c18:
	/* 0x1c18: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1c1d:
	/* 0x1c1d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1c22:
	/* 0x1c22: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c26:
	/* 0x1c26: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c2b:
	/* 0x1c2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c2d:
	/* 0x1c2d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c2f:
	/* 0x1c2f: js     5d5b <generic_sleepable_preload+0x5d5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23899ULL;
	}
x86_l_1c35:
	/* 0x1c35: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c3a:
	/* 0x1c3a: cmp    WORD PTR [r12+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1c44:
	/* 0x1c44: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_1c47:
	/* 0x1c47: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d89;
	}
x86_l_1c4d:
	/* 0x1c4d: mov    ecx,DWORD PTR [r12+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1c55:
	/* 0x1c55: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1c59:
	/* 0x1c59: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c5d:
	/* 0x1c5d: cmp    WORD PTR [r12+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1c67:
	/* 0x1c67: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d89;
	}
x86_l_1c6d:
	/* 0x1c6d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1c70:
	/* 0x1c70: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1c75:
	/* 0x1c75: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1c7a:
	/* 0x1c7a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c7e:
	/* 0x1c7e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c83:
	/* 0x1c83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c85:
	/* 0x1c85: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c87:
	/* 0x1c87: jns    1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1d89;
	}
x86_l_1c8d:
	/* 0x1c8d: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_1c92:
	/* 0x1c92: jmp    1d86 <generic_sleepable_preload+0x1d86> */
	goto x86_l_1d86;
x86_l_1c97:
	/* 0x1c97: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_1c9c:
	/* 0x1c9c: jmp    1d86 <generic_sleepable_preload+0x1d86> */
	goto x86_l_1d86;
x86_l_1ca1:
	/* 0x1ca1: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_1ca6:
	/* 0x1ca6: jmp    1cfb <generic_sleepable_preload+0x1cfb> */
	goto x86_l_1cfb;
x86_l_1ca8:
	/* 0x1ca8: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_1cad:
	/* 0x1cad: jmp    1d86 <generic_sleepable_preload+0x1d86> */
	goto x86_l_1d86;
x86_l_1cb2:
	/* 0x1cb2: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_1cb7:
	/* 0x1cb7: jmp    1cfb <generic_sleepable_preload+0x1cfb> */
	goto x86_l_1cfb;
x86_l_1cb9:
	/* 0x1cb9: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_1cbe:
	/* 0x1cbe: jmp    1d86 <generic_sleepable_preload+0x1d86> */
	goto x86_l_1d86;
x86_l_1cc3:
	/* 0x1cc3: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_1cc8:
	/* 0x1cc8: jmp    1cfb <generic_sleepable_preload+0x1cfb> */
	goto x86_l_1cfb;
x86_l_1cca:
	/* 0x1cca: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_1ccf:
	/* 0x1ccf: jmp    1d86 <generic_sleepable_preload+0x1d86> */
	goto x86_l_1d86;
x86_l_1cd4:
	/* 0x1cd4: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_1cd9:
	/* 0x1cd9: jmp    1cfb <generic_sleepable_preload+0x1cfb> */
	goto x86_l_1cfb;
x86_l_1cdb:
	/* 0x1cdb: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_1ce0:
	/* 0x1ce0: jmp    1d86 <generic_sleepable_preload+0x1d86> */
	goto x86_l_1d86;
x86_l_1ce5:
	/* 0x1ce5: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_1cea:
	/* 0x1cea: jmp    1cfb <generic_sleepable_preload+0x1cfb> */
	goto x86_l_1cfb;
x86_l_1cec:
	/* 0x1cec: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_1cf1:
	/* 0x1cf1: jmp    1d86 <generic_sleepable_preload+0x1d86> */
	goto x86_l_1d86;
x86_l_1cf6:
	/* 0x1cf6: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_1cfb:
	/* 0x1cfb: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cfe:
	/* 0x1cfe: mov    ebp,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d03:
	/* 0x1d03: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1d06:
	/* 0x1d06: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d0b:
	/* 0x1d0b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d10:
	/* 0x1d10: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d15:
	/* 0x1d15: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1d18:
	/* 0x1d18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d1a:
	/* 0x1d1a: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1d1d:
	/* 0x1d1d: jne    1e2d <generic_sleepable_preload+0x1e2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e2d;
	}
x86_l_1d23:
	/* 0x1d23: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_1d26:
	/* 0x1d26: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d2a:
	/* 0x1d2a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1d2f:
	/* 0x1d2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d31:
	/* 0x1d31: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d36:
	/* 0x1d36: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1d3e:
	/* 0x1d3e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1d45:
	/* 0x1d45: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1d4a:
	/* 0x1d4a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d4f:
	/* 0x1d4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d51:
	/* 0x1d51: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d54:
	/* 0x1d54: je     1e2a <generic_sleepable_preload+0x1e2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e2a;
	}
x86_l_1d5a:
	/* 0x1d5a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1d5d:
	/* 0x1d5d: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1d64:
	/* 0x1d64: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d66:
	/* 0x1d66: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d6b:
	/* 0x1d6b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1d70:
	/* 0x1d70: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1d73:
	/* 0x1d73: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1d76:
	/* 0x1d76: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d78:
	/* 0x1d78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d7a:
	/* 0x1d7a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d7f:
	/* 0x1d7f: jmp    1dea <generic_sleepable_preload+0x1dea> */
	goto x86_l_1dea;
x86_l_1d81:
	/* 0x1d81: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_1d86:
	/* 0x1d86: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d89:
	/* 0x1d89: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1d8c:
	/* 0x1d8c: jne    1e2d <generic_sleepable_preload+0x1e2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e2d;
	}
x86_l_1d92:
	/* 0x1d92: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_1d95:
	/* 0x1d95: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d99:
	/* 0x1d99: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1d9e:
	/* 0x1d9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1da0:
	/* 0x1da0: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1da5:
	/* 0x1da5: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1dad:
	/* 0x1dad: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1db4:
	/* 0x1db4: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1db9:
	/* 0x1db9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dbe:
	/* 0x1dbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc0:
	/* 0x1dc0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dc3:
	/* 0x1dc3: je     1e2a <generic_sleepable_preload+0x1e2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e2a;
	}
x86_l_1dc5:
	/* 0x1dc5: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1dc8:
	/* 0x1dc8: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1dcf:
	/* 0x1dcf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dd1:
	/* 0x1dd1: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1dd6:
	/* 0x1dd6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ddb:
	/* 0x1ddb: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1dde:
	/* 0x1dde: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1de1:
	/* 0x1de1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1de3:
	/* 0x1de3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de5:
	/* 0x1de5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dea:
	/* 0x1dea: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1ded:
	/* 0x1ded: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1df0:
	/* 0x1df0: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1df5:
	/* 0x1df5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1df7:
	/* 0x1df7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dfa:
	/* 0x1dfa: je     1e2a <generic_sleepable_preload+0x1e2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e2a;
	}
x86_l_1dfc:
	/* 0x1dfc: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_1dff:
	/* 0x1dff: je     1e28 <generic_sleepable_preload+0x1e28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e28;
	}
x86_l_1e01:
	/* 0x1e01: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1e04:
	/* 0x1e04: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1e08:
	/* 0x1e08: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1e0d:
	/* 0x1e0d: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1e10:
	/* 0x1e10: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e12:
	/* 0x1e12: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1e15:
	/* 0x1e15: call   1e1a <generic_sleepable_preload+0x1e1a> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_1e1a:
	/* 0x1e1a: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1e1c:
	/* 0x1e1c: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_1e1f:
	/* 0x1e1f: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1e21:
	/* 0x1e21: jns    1e28 <generic_sleepable_preload+0x1e28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1e28;
	}
x86_l_1e23:
	/* 0x1e23: mov    ebx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_1e28:
	/* 0x1e28: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e2a:
	/* 0x1e2a: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_1e2d:
	/* 0x1e2d: mov    eax,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1e32:
	/* 0x1e32: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_1e37:
	/* 0x1e37: je     2d98 <generic_sleepable_preload+0x2d98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11672ULL;
	}
x86_l_1e3d:
	/* 0x1e3d: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1e3f:
	/* 0x1e3f: js     1e74 <generic_sleepable_preload+0x1e74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1e74;
	}
x86_l_1e41:
	/* 0x1e41: mov    eax,DWORD PTR [r12+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1e46:
	/* 0x1e46: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e49:
	/* 0x1e49: jle    1ef7 <generic_sleepable_preload+0x1ef7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1ef7;
	}
x86_l_1e4f:
	/* 0x1e4f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e52:
	/* 0x1e52: je     1f61 <generic_sleepable_preload+0x1f61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f61;
	}
x86_l_1e58:
	/* 0x1e58: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1e5b:
	/* 0x1e5b: je     1f68 <generic_sleepable_preload+0x1f68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f68;
	}
x86_l_1e61:
	/* 0x1e61: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e64:
	/* 0x1e64: jne    1f7b <generic_sleepable_preload+0x1f7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f7b;
	}
x86_l_1e6a:
	/* 0x1e6a: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e6f:
	/* 0x1e6f: jmp    1f74 <generic_sleepable_preload+0x1f74> */
	goto x86_l_1f74;
x86_l_1e74:
	/* 0x1e74: movzx  eax,BYTE PTR [r12+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_1e7d:
	/* 0x1e7d: movzx  ecx,WORD PTR [r12+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_1e86:
	/* 0x1e86: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_1e8c:
	/* 0x1e8c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e8e:
	/* 0x1e8e: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1e91:
	/* 0x1e91: jle    1ed0 <generic_sleepable_preload+0x1ed0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1ed0;
	}
x86_l_1e93:
	/* 0x1e93: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1e96:
	/* 0x1e96: jle    1f07 <generic_sleepable_preload+0x1f07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1f07;
	}
x86_l_1e98:
	/* 0x1e98: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1e9b:
	/* 0x1e9b: jle    25ca <generic_sleepable_preload+0x25ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 9674ULL;
	}
x86_l_1ea1:
	/* 0x1ea1: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ea6:
	/* 0x1ea6: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_1ea9:
	/* 0x1ea9: je     25ef <generic_sleepable_preload+0x25ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9711ULL;
	}
x86_l_1eaf:
	/* 0x1eaf: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1eb4:
	/* 0x1eb4: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_1eb7:
	/* 0x1eb7: je     25ef <generic_sleepable_preload+0x25ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9711ULL;
	}
x86_l_1ebd:
	/* 0x1ebd: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1ec2:
	/* 0x1ec2: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_1ec5:
	/* 0x1ec5: je     25ef <generic_sleepable_preload+0x25ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9711ULL;
	}
x86_l_1ecb:
	/* 0x1ecb: jmp    2602 <generic_sleepable_preload+0x2602> */
	return 9730ULL;
x86_l_1ed0:
	/* 0x1ed0: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1ed3:
	/* 0x1ed3: jg     1f34 <generic_sleepable_preload+0x1f34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1f34;
	}
x86_l_1ed5:
	/* 0x1ed5: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1ed8:
	/* 0x1ed8: jg     259b <generic_sleepable_preload+0x259b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9627ULL;
	}
x86_l_1ede:
	/* 0x1ede: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1ee0:
	/* 0x1ee0: je     25ea <generic_sleepable_preload+0x25ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9706ULL;
	}
x86_l_1ee6:
	/* 0x1ee6: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1ee9:
	/* 0x1ee9: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1eec:
	/* 0x1eec: je     25ef <generic_sleepable_preload+0x25ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9711ULL;
	}
x86_l_1ef2:
	/* 0x1ef2: jmp    2602 <generic_sleepable_preload+0x2602> */
	return 9730ULL;
x86_l_1ef7:
	/* 0x1ef7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ef9:
	/* 0x1ef9: je     1f6f <generic_sleepable_preload+0x1f6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f6f;
	}
x86_l_1efb:
	/* 0x1efb: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1efe:
	/* 0x1efe: jne    1f7b <generic_sleepable_preload+0x1f7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f7b;
	}
x86_l_1f00:
	/* 0x1f00: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f05:
	/* 0x1f05: jmp    1f74 <generic_sleepable_preload+0x1f74> */
	goto x86_l_1f74;
x86_l_1f07:
	/* 0x1f07: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1f0a:
	/* 0x1f0a: jg     2582 <generic_sleepable_preload+0x2582> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9602ULL;
	}
x86_l_1f10:
	/* 0x1f10: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1f18:
	/* 0x1f18: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1f1b:
	/* 0x1f1b: je     25ef <generic_sleepable_preload+0x25ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9711ULL;
	}
x86_l_1f21:
	/* 0x1f21: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f26:
	/* 0x1f26: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1f29:
	/* 0x1f29: je     25ef <generic_sleepable_preload+0x25ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9711ULL;
	}
x86_l_1f2f:
	/* 0x1f2f: jmp    2602 <generic_sleepable_preload+0x2602> */
	return 9730ULL;
x86_l_1f34:
	/* 0x1f34: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1f37:
	/* 0x1f37: jg     25b1 <generic_sleepable_preload+0x25b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9649ULL;
	}
x86_l_1f3d:
	/* 0x1f3d: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1f45:
	/* 0x1f45: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1f48:
	/* 0x1f48: je     25ef <generic_sleepable_preload+0x25ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9711ULL;
	}
x86_l_1f4e:
	/* 0x1f4e: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1f53:
	/* 0x1f53: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1f56:
	/* 0x1f56: je     25ef <generic_sleepable_preload+0x25ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9711ULL;
	}
x86_l_1f5c:
	/* 0x1f5c: jmp    2602 <generic_sleepable_preload+0x2602> */
	return 9730ULL;
x86_l_1f61:
	/* 0x1f61: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f66:
	/* 0x1f66: jmp    1f74 <generic_sleepable_preload+0x1f74> */
	goto x86_l_1f74;
x86_l_1f68:
	/* 0x1f68: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f6d:
	/* 0x1f6d: jmp    1f74 <generic_sleepable_preload+0x1f74> */
	goto x86_l_1f74;
x86_l_1f6f:
	/* 0x1f6f: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f74:
	/* 0x1f74: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f77:
	/* 0x1f77: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f7b:
	/* 0x1f7b: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f7d:
	/* 0x1f7d: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_1f80:
	/* 0x1f80: cmp    WORD PTR [r12+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_1f8a:
	/* 0x1f8a: je     2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_1f90:
	/* 0x1f90: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1f97:
	/* 0x1f97: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1f9a:
	/* 0x1f9a: mov    eax,DWORD PTR [r12+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1fa2:
	/* 0x1fa2: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1fa5:
	/* 0x1fa5: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fa9:
	/* 0x1fa9: movzx  eax,WORD PTR [r12+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_1fb2:
	/* 0x1fb2: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1fb4:
	/* 0x1fb4: je     2286 <generic_sleepable_preload+0x2286> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8838ULL;
	}
x86_l_1fba:
	/* 0x1fba: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1fbd:
	/* 0x1fbd: je     1fdf <generic_sleepable_preload+0x1fdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fdf;
	}
x86_l_1fbf:
	/* 0x1fbf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1fc2:
	/* 0x1fc2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1fc7:
	/* 0x1fc7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1fcc:
	/* 0x1fcc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fd0:
	/* 0x1fd0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fd5:
	/* 0x1fd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fd7:
	/* 0x1fd7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fd9:
	/* 0x1fd9: js     2578 <generic_sleepable_preload+0x2578> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9592ULL;
	}
x86_l_1fdf:
	/* 0x1fdf: cmp    WORD PTR [r12+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_1fe9:
	/* 0x1fe9: je     2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_1fef:
	/* 0x1fef: mov    ecx,DWORD PTR [r12+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1ff7:
	/* 0x1ff7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1ffb:
	/* 0x1ffb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fff:
	/* 0x1fff: cmp    WORD PTR [r12+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_2009:
	/* 0x2009: je     202b <generic_sleepable_preload+0x202b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_202b;
	}
x86_l_200b:
	/* 0x200b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_200e:
	/* 0x200e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2013:
	/* 0x2013: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2018:
	/* 0x2018: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_201c:
	/* 0x201c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2021:
	/* 0x2021: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2023:
	/* 0x2023: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2025:
	/* 0x2025: js     25e0 <generic_sleepable_preload+0x25e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9696ULL;
	}
x86_l_202b:
	/* 0x202b: cmp    WORD PTR [r12+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_2035:
	/* 0x2035: je     2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_203b:
	/* 0x203b: mov    ecx,DWORD PTR [r12+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2043:
	/* 0x2043: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2047:
	/* 0x2047: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_204b:
	/* 0x204b: cmp    WORD PTR [r12+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_2055:
	/* 0x2055: je     2077 <generic_sleepable_preload+0x2077> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2077;
	}
x86_l_2057:
	/* 0x2057: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_205a:
	/* 0x205a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_205f:
	/* 0x205f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2064:
	/* 0x2064: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2068:
	/* 0x2068: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_206d:
	/* 0x206d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_206f:
	/* 0x206f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2071:
	/* 0x2071: js     2c1c <generic_sleepable_preload+0x2c1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11292ULL;
	}
x86_l_2077:
	/* 0x2077: cmp    WORD PTR [r12+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_2081:
	/* 0x2081: je     2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_2087:
	/* 0x2087: mov    ecx,DWORD PTR [r12+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_208f:
	/* 0x208f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2093:
	/* 0x2093: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2097:
	/* 0x2097: cmp    WORD PTR [r12+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_20a1:
	/* 0x20a1: je     20c3 <generic_sleepable_preload+0x20c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20c3;
	}
x86_l_20a3:
	/* 0x20a3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20a6:
	/* 0x20a6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_20ab:
	/* 0x20ab: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20b0:
	/* 0x20b0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20b4:
	/* 0x20b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20b9:
	/* 0x20b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20bb:
	/* 0x20bb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20bd:
	/* 0x20bd: js     2c2d <generic_sleepable_preload+0x2c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11309ULL;
	}
x86_l_20c3:
	/* 0x20c3: cmp    WORD PTR [r12+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_20cd:
	/* 0x20cd: je     2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_20d3:
	/* 0x20d3: mov    ecx,DWORD PTR [r12+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_20db:
	/* 0x20db: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_20df:
	/* 0x20df: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20e3:
	/* 0x20e3: cmp    WORD PTR [r12+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_20ed:
	/* 0x20ed: je     210f <generic_sleepable_preload+0x210f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_210f;
	}
x86_l_20ef:
	/* 0x20ef: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20f2:
	/* 0x20f2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_20f7:
	/* 0x20f7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20fc:
	/* 0x20fc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2100:
	/* 0x2100: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2105:
	/* 0x2105: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2107:
	/* 0x2107: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2109:
	/* 0x2109: js     2c3e <generic_sleepable_preload+0x2c3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11326ULL;
	}
x86_l_210f:
	/* 0x210f: cmp    WORD PTR [r12+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_2119:
	/* 0x2119: je     2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_211f:
	/* 0x211f: mov    ecx,DWORD PTR [r12+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2127:
	/* 0x2127: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_212b:
	/* 0x212b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_212f:
	/* 0x212f: cmp    WORD PTR [r12+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2139:
	/* 0x2139: je     215b <generic_sleepable_preload+0x215b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8539ULL;
	}
x86_l_213b:
	/* 0x213b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_213e:
	/* 0x213e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
	return 8515ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8515ULL: goto x86_l_2143;
	case 8520ULL: goto x86_l_2148;
	case 8524ULL: goto x86_l_214c;
	case 8529ULL: goto x86_l_2151;
	case 8531ULL: goto x86_l_2153;
	case 8533ULL: goto x86_l_2155;
	case 8539ULL: goto x86_l_215b;
	case 8549ULL: goto x86_l_2165;
	case 8555ULL: goto x86_l_216b;
	case 8563ULL: goto x86_l_2173;
	case 8567ULL: goto x86_l_2177;
	case 8571ULL: goto x86_l_217b;
	case 8581ULL: goto x86_l_2185;
	case 8583ULL: goto x86_l_2187;
	case 8586ULL: goto x86_l_218a;
	case 8591ULL: goto x86_l_218f;
	case 8596ULL: goto x86_l_2194;
	case 8600ULL: goto x86_l_2198;
	case 8605ULL: goto x86_l_219d;
	case 8607ULL: goto x86_l_219f;
	case 8609ULL: goto x86_l_21a1;
	case 8615ULL: goto x86_l_21a7;
	case 8625ULL: goto x86_l_21b1;
	case 8631ULL: goto x86_l_21b7;
	case 8639ULL: goto x86_l_21bf;
	case 8643ULL: goto x86_l_21c3;
	case 8647ULL: goto x86_l_21c7;
	case 8657ULL: goto x86_l_21d1;
	case 8659ULL: goto x86_l_21d3;
	case 8662ULL: goto x86_l_21d6;
	case 8667ULL: goto x86_l_21db;
	case 8672ULL: goto x86_l_21e0;
	case 8676ULL: goto x86_l_21e4;
	case 8681ULL: goto x86_l_21e9;
	case 8683ULL: goto x86_l_21eb;
	case 8685ULL: goto x86_l_21ed;
	case 8691ULL: goto x86_l_21f3;
	case 8701ULL: goto x86_l_21fd;
	case 8707ULL: goto x86_l_2203;
	case 8715ULL: goto x86_l_220b;
	case 8719ULL: goto x86_l_220f;
	case 8723ULL: goto x86_l_2213;
	case 8733ULL: goto x86_l_221d;
	case 8735ULL: goto x86_l_221f;
	case 8738ULL: goto x86_l_2222;
	case 8743ULL: goto x86_l_2227;
	case 8748ULL: goto x86_l_222c;
	case 8752ULL: goto x86_l_2230;
	case 8757ULL: goto x86_l_2235;
	case 8759ULL: goto x86_l_2237;
	case 8761ULL: goto x86_l_2239;
	case 8767ULL: goto x86_l_223f;
	case 8772ULL: goto x86_l_2244;
	case 8782ULL: goto x86_l_224e;
	case 8788ULL: goto x86_l_2254;
	case 8796ULL: goto x86_l_225c;
	case 8800ULL: goto x86_l_2260;
	case 8804ULL: goto x86_l_2264;
	case 8814ULL: goto x86_l_226e;
	case 8820ULL: goto x86_l_2274;
	case 8823ULL: goto x86_l_2277;
	case 8828ULL: goto x86_l_227c;
	case 8833ULL: goto x86_l_2281;
	case 8838ULL: goto x86_l_2286;
	case 8841ULL: goto x86_l_2289;
	case 8843ULL: goto x86_l_228b;
	case 8846ULL: goto x86_l_228e;
	case 8851ULL: goto x86_l_2293;
	case 8856ULL: goto x86_l_2298;
	case 8860ULL: goto x86_l_229c;
	case 8865ULL: goto x86_l_22a1;
	case 8867ULL: goto x86_l_22a3;
	case 8869ULL: goto x86_l_22a5;
	case 8875ULL: goto x86_l_22ab;
	case 8885ULL: goto x86_l_22b5;
	case 8891ULL: goto x86_l_22bb;
	case 8899ULL: goto x86_l_22c3;
	case 8903ULL: goto x86_l_22c7;
	case 8907ULL: goto x86_l_22cb;
	case 8917ULL: goto x86_l_22d5;
	case 8919ULL: goto x86_l_22d7;
	case 8922ULL: goto x86_l_22da;
	case 8927ULL: goto x86_l_22df;
	case 8932ULL: goto x86_l_22e4;
	case 8936ULL: goto x86_l_22e8;
	case 8941ULL: goto x86_l_22ed;
	case 8943ULL: goto x86_l_22ef;
	case 8945ULL: goto x86_l_22f1;
	case 8951ULL: goto x86_l_22f7;
	case 8961ULL: goto x86_l_2301;
	case 8967ULL: goto x86_l_2307;
	case 8975ULL: goto x86_l_230f;
	case 8979ULL: goto x86_l_2313;
	case 8983ULL: goto x86_l_2317;
	case 8993ULL: goto x86_l_2321;
	case 8995ULL: goto x86_l_2323;
	case 8998ULL: goto x86_l_2326;
	case 9003ULL: goto x86_l_232b;
	case 9008ULL: goto x86_l_2330;
	case 9012ULL: goto x86_l_2334;
	case 9017ULL: goto x86_l_2339;
	case 9019ULL: goto x86_l_233b;
	case 9021ULL: goto x86_l_233d;
	case 9027ULL: goto x86_l_2343;
	case 9037ULL: goto x86_l_234d;
	case 9043ULL: goto x86_l_2353;
	case 9051ULL: goto x86_l_235b;
	case 9055ULL: goto x86_l_235f;
	case 9059ULL: goto x86_l_2363;
	case 9069ULL: goto x86_l_236d;
	case 9071ULL: goto x86_l_236f;
	case 9074ULL: goto x86_l_2372;
	case 9079ULL: goto x86_l_2377;
	case 9084ULL: goto x86_l_237c;
	case 9088ULL: goto x86_l_2380;
	case 9093ULL: goto x86_l_2385;
	case 9095ULL: goto x86_l_2387;
	case 9097ULL: goto x86_l_2389;
	case 9103ULL: goto x86_l_238f;
	case 9113ULL: goto x86_l_2399;
	case 9119ULL: goto x86_l_239f;
	case 9127ULL: goto x86_l_23a7;
	case 9131ULL: goto x86_l_23ab;
	case 9135ULL: goto x86_l_23af;
	case 9145ULL: goto x86_l_23b9;
	case 9147ULL: goto x86_l_23bb;
	case 9150ULL: goto x86_l_23be;
	case 9155ULL: goto x86_l_23c3;
	case 9160ULL: goto x86_l_23c8;
	case 9164ULL: goto x86_l_23cc;
	case 9169ULL: goto x86_l_23d1;
	case 9171ULL: goto x86_l_23d3;
	case 9173ULL: goto x86_l_23d5;
	case 9179ULL: goto x86_l_23db;
	case 9189ULL: goto x86_l_23e5;
	case 9195ULL: goto x86_l_23eb;
	case 9203ULL: goto x86_l_23f3;
	case 9207ULL: goto x86_l_23f7;
	case 9211ULL: goto x86_l_23fb;
	case 9221ULL: goto x86_l_2405;
	case 9223ULL: goto x86_l_2407;
	case 9226ULL: goto x86_l_240a;
	case 9231ULL: goto x86_l_240f;
	case 9236ULL: goto x86_l_2414;
	case 9240ULL: goto x86_l_2418;
	case 9245ULL: goto x86_l_241d;
	case 9247ULL: goto x86_l_241f;
	case 9249ULL: goto x86_l_2421;
	case 9255ULL: goto x86_l_2427;
	case 9265ULL: goto x86_l_2431;
	case 9271ULL: goto x86_l_2437;
	case 9279ULL: goto x86_l_243f;
	case 9283ULL: goto x86_l_2443;
	case 9287ULL: goto x86_l_2447;
	case 9297ULL: goto x86_l_2451;
	case 9299ULL: goto x86_l_2453;
	case 9302ULL: goto x86_l_2456;
	case 9307ULL: goto x86_l_245b;
	case 9312ULL: goto x86_l_2460;
	case 9316ULL: goto x86_l_2464;
	case 9321ULL: goto x86_l_2469;
	case 9323ULL: goto x86_l_246b;
	case 9325ULL: goto x86_l_246d;
	case 9331ULL: goto x86_l_2473;
	case 9341ULL: goto x86_l_247d;
	case 9347ULL: goto x86_l_2483;
	case 9350ULL: goto x86_l_2486;
	case 9358ULL: goto x86_l_248e;
	case 9362ULL: goto x86_l_2492;
	case 9366ULL: goto x86_l_2496;
	case 9376ULL: goto x86_l_24a0;
	case 9378ULL: goto x86_l_24a2;
	case 9381ULL: goto x86_l_24a5;
	case 9386ULL: goto x86_l_24aa;
	case 9391ULL: goto x86_l_24af;
	case 9395ULL: goto x86_l_24b3;
	case 9400ULL: goto x86_l_24b8;
	case 9402ULL: goto x86_l_24ba;
	case 9404ULL: goto x86_l_24bc;
	case 9410ULL: goto x86_l_24c2;
	case 9415ULL: goto x86_l_24c7;
	case 9425ULL: goto x86_l_24d1;
	case 9428ULL: goto x86_l_24d4;
	case 9434ULL: goto x86_l_24da;
	case 9442ULL: goto x86_l_24e2;
	case 9446ULL: goto x86_l_24e6;
	case 9450ULL: goto x86_l_24ea;
	case 9460ULL: goto x86_l_24f4;
	case 9462ULL: goto x86_l_24f6;
	case 9465ULL: goto x86_l_24f9;
	case 9470ULL: goto x86_l_24fe;
	case 9475ULL: goto x86_l_2503;
	case 9479ULL: goto x86_l_2507;
	case 9484ULL: goto x86_l_250c;
	case 9486ULL: goto x86_l_250e;
	case 9488ULL: goto x86_l_2510;
	case 9494ULL: goto x86_l_2516;
	case 9499ULL: goto x86_l_251b;
	case 9509ULL: goto x86_l_2525;
	case 9512ULL: goto x86_l_2528;
	case 9518ULL: goto x86_l_252e;
	case 9526ULL: goto x86_l_2536;
	case 9530ULL: goto x86_l_253a;
	case 9534ULL: goto x86_l_253e;
	case 9544ULL: goto x86_l_2548;
	case 9550ULL: goto x86_l_254e;
	case 9553ULL: goto x86_l_2551;
	case 9558ULL: goto x86_l_2556;
	case 9563ULL: goto x86_l_255b;
	case 9567ULL: goto x86_l_255f;
	case 9572ULL: goto x86_l_2564;
	case 9574ULL: goto x86_l_2566;
	case 9576ULL: goto x86_l_2568;
	case 9582ULL: goto x86_l_256e;
	case 9587ULL: goto x86_l_2573;
	case 9592ULL: goto x86_l_2578;
	case 9597ULL: goto x86_l_257d;
	case 9602ULL: goto x86_l_2582;
	case 9610ULL: goto x86_l_258a;
	case 9613ULL: goto x86_l_258d;
	case 9615ULL: goto x86_l_258f;
	case 9620ULL: goto x86_l_2594;
	case 9623ULL: goto x86_l_2597;
	case 9625ULL: goto x86_l_2599;
	case 9627ULL: goto x86_l_259b;
	case 9632ULL: goto x86_l_25a0;
	case 9635ULL: goto x86_l_25a3;
	case 9637ULL: goto x86_l_25a5;
	case 9642ULL: goto x86_l_25aa;
	case 9645ULL: goto x86_l_25ad;
	case 9647ULL: goto x86_l_25af;
	case 9649ULL: goto x86_l_25b1;
	case 9657ULL: goto x86_l_25b9;
	case 9660ULL: goto x86_l_25bc;
	case 9662ULL: goto x86_l_25be;
	case 9667ULL: goto x86_l_25c3;
	case 9670ULL: goto x86_l_25c6;
	case 9672ULL: goto x86_l_25c8;
	case 9674ULL: goto x86_l_25ca;
	case 9679ULL: goto x86_l_25cf;
	case 9682ULL: goto x86_l_25d2;
	case 9684ULL: goto x86_l_25d4;
	case 9689ULL: goto x86_l_25d9;
	case 9692ULL: goto x86_l_25dc;
	case 9694ULL: goto x86_l_25de;
	case 9696ULL: goto x86_l_25e0;
	case 9701ULL: goto x86_l_25e5;
	case 9706ULL: goto x86_l_25ea;
	case 9711ULL: goto x86_l_25ef;
	case 9714ULL: goto x86_l_25f2;
	case 9716ULL: goto x86_l_25f4;
	case 9718ULL: goto x86_l_25f6;
	case 9723ULL: goto x86_l_25fb;
	case 9725ULL: goto x86_l_25fd;
	case 9730ULL: goto x86_l_2602;
	case 9734ULL: goto x86_l_2606;
	case 9739ULL: goto x86_l_260b;
	case 9741ULL: goto x86_l_260d;
	case 9744ULL: goto x86_l_2610;
	case 9754ULL: goto x86_l_261a;
	case 9760ULL: goto x86_l_2620;
	case 9767ULL: goto x86_l_2627;
	case 9770ULL: goto x86_l_262a;
	case 9778ULL: goto x86_l_2632;
	case 9781ULL: goto x86_l_2635;
	case 9785ULL: goto x86_l_2639;
	case 9794ULL: goto x86_l_2642;
	case 9796ULL: goto x86_l_2644;
	case 9802ULL: goto x86_l_264a;
	case 9805ULL: goto x86_l_264d;
	case 9807ULL: goto x86_l_264f;
	case 9810ULL: goto x86_l_2652;
	case 9815ULL: goto x86_l_2657;
	case 9820ULL: goto x86_l_265c;
	case 9824ULL: goto x86_l_2660;
	case 9829ULL: goto x86_l_2665;
	case 9831ULL: goto x86_l_2667;
	case 9833ULL: goto x86_l_2669;
	case 9839ULL: goto x86_l_266f;
	case 9849ULL: goto x86_l_2679;
	case 9855ULL: goto x86_l_267f;
	case 9863ULL: goto x86_l_2687;
	case 9867ULL: goto x86_l_268b;
	case 9871ULL: goto x86_l_268f;
	case 9881ULL: goto x86_l_2699;
	case 9883ULL: goto x86_l_269b;
	case 9886ULL: goto x86_l_269e;
	case 9891ULL: goto x86_l_26a3;
	case 9896ULL: goto x86_l_26a8;
	case 9900ULL: goto x86_l_26ac;
	case 9905ULL: goto x86_l_26b1;
	case 9907ULL: goto x86_l_26b3;
	case 9909ULL: goto x86_l_26b5;
	case 9915ULL: goto x86_l_26bb;
	case 9925ULL: goto x86_l_26c5;
	case 9931ULL: goto x86_l_26cb;
	case 9939ULL: goto x86_l_26d3;
	case 9943ULL: goto x86_l_26d7;
	case 9947ULL: goto x86_l_26db;
	case 9957ULL: goto x86_l_26e5;
	case 9959ULL: goto x86_l_26e7;
	case 9962ULL: goto x86_l_26ea;
	case 9967ULL: goto x86_l_26ef;
	case 9972ULL: goto x86_l_26f4;
	case 9976ULL: goto x86_l_26f8;
	case 9981ULL: goto x86_l_26fd;
	case 9983ULL: goto x86_l_26ff;
	case 9985ULL: goto x86_l_2701;
	case 9991ULL: goto x86_l_2707;
	case 10001ULL: goto x86_l_2711;
	case 10007ULL: goto x86_l_2717;
	case 10015ULL: goto x86_l_271f;
	case 10019ULL: goto x86_l_2723;
	case 10023ULL: goto x86_l_2727;
	case 10033ULL: goto x86_l_2731;
	case 10035ULL: goto x86_l_2733;
	case 10038ULL: goto x86_l_2736;
	case 10043ULL: goto x86_l_273b;
	case 10048ULL: goto x86_l_2740;
	case 10052ULL: goto x86_l_2744;
	case 10057ULL: goto x86_l_2749;
	case 10059ULL: goto x86_l_274b;
	case 10061ULL: goto x86_l_274d;
	case 10067ULL: goto x86_l_2753;
	case 10077ULL: goto x86_l_275d;
	case 10083ULL: goto x86_l_2763;
	case 10091ULL: goto x86_l_276b;
	case 10095ULL: goto x86_l_276f;
	case 10099ULL: goto x86_l_2773;
	case 10109ULL: goto x86_l_277d;
	case 10111ULL: goto x86_l_277f;
	case 10114ULL: goto x86_l_2782;
	case 10119ULL: goto x86_l_2787;
	case 10124ULL: goto x86_l_278c;
	case 10128ULL: goto x86_l_2790;
	case 10133ULL: goto x86_l_2795;
	case 10135ULL: goto x86_l_2797;
	case 10137ULL: goto x86_l_2799;
	case 10143ULL: goto x86_l_279f;
	case 10153ULL: goto x86_l_27a9;
	case 10159ULL: goto x86_l_27af;
	case 10167ULL: goto x86_l_27b7;
	case 10171ULL: goto x86_l_27bb;
	case 10175ULL: goto x86_l_27bf;
	case 10185ULL: goto x86_l_27c9;
	case 10187ULL: goto x86_l_27cb;
	case 10190ULL: goto x86_l_27ce;
	case 10195ULL: goto x86_l_27d3;
	case 10200ULL: goto x86_l_27d8;
	case 10204ULL: goto x86_l_27dc;
	case 10209ULL: goto x86_l_27e1;
	case 10211ULL: goto x86_l_27e3;
	case 10213ULL: goto x86_l_27e5;
	case 10219ULL: goto x86_l_27eb;
	case 10229ULL: goto x86_l_27f5;
	case 10235ULL: goto x86_l_27fb;
	case 10243ULL: goto x86_l_2803;
	case 10247ULL: goto x86_l_2807;
	case 10251ULL: goto x86_l_280b;
	case 10261ULL: goto x86_l_2815;
	case 10263ULL: goto x86_l_2817;
	case 10266ULL: goto x86_l_281a;
	case 10271ULL: goto x86_l_281f;
	case 10276ULL: goto x86_l_2824;
	case 10280ULL: goto x86_l_2828;
	case 10285ULL: goto x86_l_282d;
	case 10287ULL: goto x86_l_282f;
	case 10289ULL: goto x86_l_2831;
	case 10295ULL: goto x86_l_2837;
	case 10305ULL: goto x86_l_2841;
	case 10311ULL: goto x86_l_2847;
	case 10319ULL: goto x86_l_284f;
	case 10323ULL: goto x86_l_2853;
	case 10327ULL: goto x86_l_2857;
	case 10337ULL: goto x86_l_2861;
	case 10339ULL: goto x86_l_2863;
	case 10342ULL: goto x86_l_2866;
	case 10347ULL: goto x86_l_286b;
	case 10352ULL: goto x86_l_2870;
	case 10356ULL: goto x86_l_2874;
	case 10361ULL: goto x86_l_2879;
	case 10363ULL: goto x86_l_287b;
	case 10365ULL: goto x86_l_287d;
	case 10371ULL: goto x86_l_2883;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2143:
	/* 0x2143: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2148:
	/* 0x2148: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_214c:
	/* 0x214c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2151:
	/* 0x2151: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2153:
	/* 0x2153: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2155:
	/* 0x2155: js     2c4f <generic_sleepable_preload+0x2c4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11343ULL;
	}
x86_l_215b:
	/* 0x215b: cmp    WORD PTR [r12+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2165:
	/* 0x2165: je     2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_216b:
	/* 0x216b: mov    ecx,DWORD PTR [r12+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2173:
	/* 0x2173: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2177:
	/* 0x2177: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_217b:
	/* 0x217b: cmp    WORD PTR [r12+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_2185:
	/* 0x2185: je     21a7 <generic_sleepable_preload+0x21a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21a7;
	}
x86_l_2187:
	/* 0x2187: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_218a:
	/* 0x218a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_218f:
	/* 0x218f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2194:
	/* 0x2194: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2198:
	/* 0x2198: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_219d:
	/* 0x219d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_219f:
	/* 0x219f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21a1:
	/* 0x21a1: js     2c60 <generic_sleepable_preload+0x2c60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11360ULL;
	}
x86_l_21a7:
	/* 0x21a7: cmp    WORD PTR [r12+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_21b1:
	/* 0x21b1: je     2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_21b7:
	/* 0x21b7: mov    ecx,DWORD PTR [r12+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_21bf:
	/* 0x21bf: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_21c3:
	/* 0x21c3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21c7:
	/* 0x21c7: cmp    WORD PTR [r12+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_21d1:
	/* 0x21d1: je     21f3 <generic_sleepable_preload+0x21f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21f3;
	}
x86_l_21d3:
	/* 0x21d3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_21d6:
	/* 0x21d6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_21db:
	/* 0x21db: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_21e0:
	/* 0x21e0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21e4:
	/* 0x21e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21e9:
	/* 0x21e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21eb:
	/* 0x21eb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21ed:
	/* 0x21ed: js     5bea <generic_sleepable_preload+0x5bea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23530ULL;
	}
x86_l_21f3:
	/* 0x21f3: cmp    WORD PTR [r12+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_21fd:
	/* 0x21fd: je     2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_2203:
	/* 0x2203: mov    ecx,DWORD PTR [r12+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_220b:
	/* 0x220b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_220f:
	/* 0x220f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2213:
	/* 0x2213: cmp    WORD PTR [r12+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_221d:
	/* 0x221d: je     223f <generic_sleepable_preload+0x223f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_223f;
	}
x86_l_221f:
	/* 0x221f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2222:
	/* 0x2222: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2227:
	/* 0x2227: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_222c:
	/* 0x222c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2230:
	/* 0x2230: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2235:
	/* 0x2235: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2237:
	/* 0x2237: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2239:
	/* 0x2239: js     5cda <generic_sleepable_preload+0x5cda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23770ULL;
	}
x86_l_223f:
	/* 0x223f: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2244:
	/* 0x2244: cmp    WORD PTR [r12+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_224e:
	/* 0x224e: je     2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_2254:
	/* 0x2254: mov    ecx,DWORD PTR [r12+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_225c:
	/* 0x225c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2260:
	/* 0x2260: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2264:
	/* 0x2264: cmp    WORD PTR [r12+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_226e:
	/* 0x226e: je     2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_2274:
	/* 0x2274: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2277:
	/* 0x2277: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_227c:
	/* 0x227c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2281:
	/* 0x2281: jmp    255b <generic_sleepable_preload+0x255b> */
	goto x86_l_255b;
x86_l_2286:
	/* 0x2286: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2289:
	/* 0x2289: je     22ab <generic_sleepable_preload+0x22ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22ab;
	}
x86_l_228b:
	/* 0x228b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_228e:
	/* 0x228e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2293:
	/* 0x2293: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2298:
	/* 0x2298: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_229c:
	/* 0x229c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22a1:
	/* 0x22a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22a3:
	/* 0x22a3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22a5:
	/* 0x22a5: js     2578 <generic_sleepable_preload+0x2578> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2578;
	}
x86_l_22ab:
	/* 0x22ab: cmp    WORD PTR [r12+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_22b5:
	/* 0x22b5: je     2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_22bb:
	/* 0x22bb: mov    ecx,DWORD PTR [r12+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_22c3:
	/* 0x22c3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_22c7:
	/* 0x22c7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22cb:
	/* 0x22cb: cmp    WORD PTR [r12+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_22d5:
	/* 0x22d5: je     22f7 <generic_sleepable_preload+0x22f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22f7;
	}
x86_l_22d7:
	/* 0x22d7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_22da:
	/* 0x22da: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_22df:
	/* 0x22df: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_22e4:
	/* 0x22e4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22e8:
	/* 0x22e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22ed:
	/* 0x22ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22ef:
	/* 0x22ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22f1:
	/* 0x22f1: js     25e0 <generic_sleepable_preload+0x25e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_25e0;
	}
x86_l_22f7:
	/* 0x22f7: cmp    WORD PTR [r12+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_2301:
	/* 0x2301: je     2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_2307:
	/* 0x2307: mov    ecx,DWORD PTR [r12+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_230f:
	/* 0x230f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2313:
	/* 0x2313: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2317:
	/* 0x2317: cmp    WORD PTR [r12+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_2321:
	/* 0x2321: je     2343 <generic_sleepable_preload+0x2343> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2343;
	}
x86_l_2323:
	/* 0x2323: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2326:
	/* 0x2326: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_232b:
	/* 0x232b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2330:
	/* 0x2330: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2334:
	/* 0x2334: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2339:
	/* 0x2339: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_233b:
	/* 0x233b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_233d:
	/* 0x233d: js     2c1c <generic_sleepable_preload+0x2c1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11292ULL;
	}
x86_l_2343:
	/* 0x2343: cmp    WORD PTR [r12+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_234d:
	/* 0x234d: je     2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_2353:
	/* 0x2353: mov    ecx,DWORD PTR [r12+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_235b:
	/* 0x235b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_235f:
	/* 0x235f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2363:
	/* 0x2363: cmp    WORD PTR [r12+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_236d:
	/* 0x236d: je     238f <generic_sleepable_preload+0x238f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_238f;
	}
x86_l_236f:
	/* 0x236f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2372:
	/* 0x2372: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2377:
	/* 0x2377: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_237c:
	/* 0x237c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2380:
	/* 0x2380: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2385:
	/* 0x2385: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2387:
	/* 0x2387: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2389:
	/* 0x2389: js     2c2d <generic_sleepable_preload+0x2c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11309ULL;
	}
x86_l_238f:
	/* 0x238f: cmp    WORD PTR [r12+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_2399:
	/* 0x2399: je     2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_239f:
	/* 0x239f: mov    ecx,DWORD PTR [r12+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_23a7:
	/* 0x23a7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_23ab:
	/* 0x23ab: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23af:
	/* 0x23af: cmp    WORD PTR [r12+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_23b9:
	/* 0x23b9: je     23db <generic_sleepable_preload+0x23db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23db;
	}
x86_l_23bb:
	/* 0x23bb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_23be:
	/* 0x23be: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23c3:
	/* 0x23c3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_23c8:
	/* 0x23c8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23cc:
	/* 0x23cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23d1:
	/* 0x23d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23d3:
	/* 0x23d3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23d5:
	/* 0x23d5: js     2c3e <generic_sleepable_preload+0x2c3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11326ULL;
	}
x86_l_23db:
	/* 0x23db: cmp    WORD PTR [r12+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_23e5:
	/* 0x23e5: je     2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_23eb:
	/* 0x23eb: mov    ecx,DWORD PTR [r12+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_23f3:
	/* 0x23f3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_23f7:
	/* 0x23f7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23fb:
	/* 0x23fb: cmp    WORD PTR [r12+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2405:
	/* 0x2405: je     2427 <generic_sleepable_preload+0x2427> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2427;
	}
x86_l_2407:
	/* 0x2407: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_240a:
	/* 0x240a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_240f:
	/* 0x240f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2414:
	/* 0x2414: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2418:
	/* 0x2418: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_241d:
	/* 0x241d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_241f:
	/* 0x241f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2421:
	/* 0x2421: js     2c4f <generic_sleepable_preload+0x2c4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11343ULL;
	}
x86_l_2427:
	/* 0x2427: cmp    WORD PTR [r12+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2431:
	/* 0x2431: je     2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_2437:
	/* 0x2437: mov    ecx,DWORD PTR [r12+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_243f:
	/* 0x243f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2443:
	/* 0x2443: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2447:
	/* 0x2447: cmp    WORD PTR [r12+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_2451:
	/* 0x2451: je     2473 <generic_sleepable_preload+0x2473> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2473;
	}
x86_l_2453:
	/* 0x2453: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2456:
	/* 0x2456: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_245b:
	/* 0x245b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2460:
	/* 0x2460: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2464:
	/* 0x2464: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2469:
	/* 0x2469: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_246b:
	/* 0x246b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_246d:
	/* 0x246d: js     2c60 <generic_sleepable_preload+0x2c60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11360ULL;
	}
x86_l_2473:
	/* 0x2473: cmp    WORD PTR [r12+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_247d:
	/* 0x247d: je     2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_2483:
	/* 0x2483: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_2486:
	/* 0x2486: mov    ecx,DWORD PTR [r12+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_248e:
	/* 0x248e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2492:
	/* 0x2492: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2496:
	/* 0x2496: cmp    WORD PTR [r12+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_24a0:
	/* 0x24a0: je     24c2 <generic_sleepable_preload+0x24c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24c2;
	}
x86_l_24a2:
	/* 0x24a2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_24a5:
	/* 0x24a5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_24aa:
	/* 0x24aa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_24af:
	/* 0x24af: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24b3:
	/* 0x24b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24b8:
	/* 0x24b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24ba:
	/* 0x24ba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24bc:
	/* 0x24bc: js     5c68 <generic_sleepable_preload+0x5c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23656ULL;
	}
x86_l_24c2:
	/* 0x24c2: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24c7:
	/* 0x24c7: cmp    WORD PTR [r12+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_24d1:
	/* 0x24d1: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_24d4:
	/* 0x24d4: je     2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_24da:
	/* 0x24da: mov    ecx,DWORD PTR [r12+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_24e2:
	/* 0x24e2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_24e6:
	/* 0x24e6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24ea:
	/* 0x24ea: cmp    WORD PTR [r12+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_24f4:
	/* 0x24f4: je     2516 <generic_sleepable_preload+0x2516> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2516;
	}
x86_l_24f6:
	/* 0x24f6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_24f9:
	/* 0x24f9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_24fe:
	/* 0x24fe: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2503:
	/* 0x2503: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2507:
	/* 0x2507: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_250c:
	/* 0x250c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_250e:
	/* 0x250e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2510:
	/* 0x2510: js     5d70 <generic_sleepable_preload+0x5d70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23920ULL;
	}
x86_l_2516:
	/* 0x2516: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_251b:
	/* 0x251b: cmp    WORD PTR [r12+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2525:
	/* 0x2525: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_2528:
	/* 0x2528: je     2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_252e:
	/* 0x252e: mov    ecx,DWORD PTR [r12+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2536:
	/* 0x2536: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_253a:
	/* 0x253a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_253e:
	/* 0x253e: cmp    WORD PTR [r12+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_2548:
	/* 0x2548: je     2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11368ULL;
	}
x86_l_254e:
	/* 0x254e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2551:
	/* 0x2551: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2556:
	/* 0x2556: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_255b:
	/* 0x255b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_255f:
	/* 0x255f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2564:
	/* 0x2564: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2566:
	/* 0x2566: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2568:
	/* 0x2568: jns    2c68 <generic_sleepable_preload+0x2c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 11368ULL;
	}
x86_l_256e:
	/* 0x256e: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_2573:
	/* 0x2573: jmp    2c65 <generic_sleepable_preload+0x2c65> */
	return 11365ULL;
x86_l_2578:
	/* 0x2578: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_257d:
	/* 0x257d: jmp    2c65 <generic_sleepable_preload+0x2c65> */
	return 11365ULL;
x86_l_2582:
	/* 0x2582: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_258a:
	/* 0x258a: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_258d:
	/* 0x258d: je     25ef <generic_sleepable_preload+0x25ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ef;
	}
x86_l_258f:
	/* 0x258f: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2594:
	/* 0x2594: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_2597:
	/* 0x2597: je     25ef <generic_sleepable_preload+0x25ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ef;
	}
x86_l_2599:
	/* 0x2599: jmp    2602 <generic_sleepable_preload+0x2602> */
	goto x86_l_2602;
x86_l_259b:
	/* 0x259b: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_25a0:
	/* 0x25a0: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_25a3:
	/* 0x25a3: je     25ef <generic_sleepable_preload+0x25ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ef;
	}
x86_l_25a5:
	/* 0x25a5: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_25aa:
	/* 0x25aa: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_25ad:
	/* 0x25ad: je     25ef <generic_sleepable_preload+0x25ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ef;
	}
x86_l_25af:
	/* 0x25af: jmp    2602 <generic_sleepable_preload+0x2602> */
	goto x86_l_2602;
x86_l_25b1:
	/* 0x25b1: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_25b9:
	/* 0x25b9: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_25bc:
	/* 0x25bc: je     25ef <generic_sleepable_preload+0x25ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ef;
	}
x86_l_25be:
	/* 0x25be: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_25c3:
	/* 0x25c3: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_25c6:
	/* 0x25c6: je     25ef <generic_sleepable_preload+0x25ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ef;
	}
x86_l_25c8:
	/* 0x25c8: jmp    2602 <generic_sleepable_preload+0x2602> */
	goto x86_l_2602;
x86_l_25ca:
	/* 0x25ca: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_25cf:
	/* 0x25cf: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_25d2:
	/* 0x25d2: je     25ef <generic_sleepable_preload+0x25ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ef;
	}
x86_l_25d4:
	/* 0x25d4: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25d9:
	/* 0x25d9: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_25dc:
	/* 0x25dc: je     25ef <generic_sleepable_preload+0x25ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ef;
	}
x86_l_25de:
	/* 0x25de: jmp    2602 <generic_sleepable_preload+0x2602> */
	goto x86_l_2602;
x86_l_25e0:
	/* 0x25e0: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_25e5:
	/* 0x25e5: jmp    2c65 <generic_sleepable_preload+0x2c65> */
	return 11365ULL;
x86_l_25ea:
	/* 0x25ea: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_25ef:
	/* 0x25ef: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_25f2:
	/* 0x25f2: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_25f4:
	/* 0x25f4: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_25f6:
	/* 0x25f6: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_25fb:
	/* 0x25fb: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_25fd:
	/* 0x25fd: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_2602:
	/* 0x2602: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2606:
	/* 0x2606: mov    ebp,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_260b:
	/* 0x260b: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_260d:
	/* 0x260d: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_2610:
	/* 0x2610: cmp    WORD PTR [r12+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_261a:
	/* 0x261a: je     2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11507ULL;
	}
x86_l_2620:
	/* 0x2620: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_2627:
	/* 0x2627: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_262a:
	/* 0x262a: mov    eax,DWORD PTR [r12+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2632:
	/* 0x2632: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2635:
	/* 0x2635: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2639:
	/* 0x2639: movzx  eax,WORD PTR [r12+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_2642:
	/* 0x2642: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_2644:
	/* 0x2644: je     2916 <generic_sleepable_preload+0x2916> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10518ULL;
	}
x86_l_264a:
	/* 0x264a: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_264d:
	/* 0x264d: je     266f <generic_sleepable_preload+0x266f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_266f;
	}
x86_l_264f:
	/* 0x264f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2652:
	/* 0x2652: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2657:
	/* 0x2657: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_265c:
	/* 0x265c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2660:
	/* 0x2660: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2665:
	/* 0x2665: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2667:
	/* 0x2667: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2669:
	/* 0x2669: js     2c08 <generic_sleepable_preload+0x2c08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11272ULL;
	}
x86_l_266f:
	/* 0x266f: cmp    WORD PTR [r12+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_2679:
	/* 0x2679: je     2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11507ULL;
	}
x86_l_267f:
	/* 0x267f: mov    ecx,DWORD PTR [r12+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2687:
	/* 0x2687: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_268b:
	/* 0x268b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_268f:
	/* 0x268f: cmp    WORD PTR [r12+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_2699:
	/* 0x2699: je     26bb <generic_sleepable_preload+0x26bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26bb;
	}
x86_l_269b:
	/* 0x269b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_269e:
	/* 0x269e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26a3:
	/* 0x26a3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26a8:
	/* 0x26a8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26ac:
	/* 0x26ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26b1:
	/* 0x26b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26b3:
	/* 0x26b3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26b5:
	/* 0x26b5: js     2c12 <generic_sleepable_preload+0x2c12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11282ULL;
	}
x86_l_26bb:
	/* 0x26bb: cmp    WORD PTR [r12+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_26c5:
	/* 0x26c5: je     2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11507ULL;
	}
x86_l_26cb:
	/* 0x26cb: mov    ecx,DWORD PTR [r12+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_26d3:
	/* 0x26d3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_26d7:
	/* 0x26d7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26db:
	/* 0x26db: cmp    WORD PTR [r12+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_26e5:
	/* 0x26e5: je     2707 <generic_sleepable_preload+0x2707> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2707;
	}
x86_l_26e7:
	/* 0x26e7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_26ea:
	/* 0x26ea: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26ef:
	/* 0x26ef: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26f4:
	/* 0x26f4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26f8:
	/* 0x26f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26fd:
	/* 0x26fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26ff:
	/* 0x26ff: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2701:
	/* 0x2701: js     2c23 <generic_sleepable_preload+0x2c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11299ULL;
	}
x86_l_2707:
	/* 0x2707: cmp    WORD PTR [r12+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_2711:
	/* 0x2711: je     2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11507ULL;
	}
x86_l_2717:
	/* 0x2717: mov    ecx,DWORD PTR [r12+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_271f:
	/* 0x271f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2723:
	/* 0x2723: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2727:
	/* 0x2727: cmp    WORD PTR [r12+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_2731:
	/* 0x2731: je     2753 <generic_sleepable_preload+0x2753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2753;
	}
x86_l_2733:
	/* 0x2733: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2736:
	/* 0x2736: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_273b:
	/* 0x273b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2740:
	/* 0x2740: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2744:
	/* 0x2744: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2749:
	/* 0x2749: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_274b:
	/* 0x274b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_274d:
	/* 0x274d: js     2c34 <generic_sleepable_preload+0x2c34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11316ULL;
	}
x86_l_2753:
	/* 0x2753: cmp    WORD PTR [r12+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_275d:
	/* 0x275d: je     2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11507ULL;
	}
x86_l_2763:
	/* 0x2763: mov    ecx,DWORD PTR [r12+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_276b:
	/* 0x276b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_276f:
	/* 0x276f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2773:
	/* 0x2773: cmp    WORD PTR [r12+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_277d:
	/* 0x277d: je     279f <generic_sleepable_preload+0x279f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_279f;
	}
x86_l_277f:
	/* 0x277f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2782:
	/* 0x2782: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2787:
	/* 0x2787: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_278c:
	/* 0x278c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2790:
	/* 0x2790: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2795:
	/* 0x2795: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2797:
	/* 0x2797: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2799:
	/* 0x2799: js     2c45 <generic_sleepable_preload+0x2c45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11333ULL;
	}
x86_l_279f:
	/* 0x279f: cmp    WORD PTR [r12+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_27a9:
	/* 0x27a9: je     2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11507ULL;
	}
x86_l_27af:
	/* 0x27af: mov    ecx,DWORD PTR [r12+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_27b7:
	/* 0x27b7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_27bb:
	/* 0x27bb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27bf:
	/* 0x27bf: cmp    WORD PTR [r12+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_27c9:
	/* 0x27c9: je     27eb <generic_sleepable_preload+0x27eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27eb;
	}
x86_l_27cb:
	/* 0x27cb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_27ce:
	/* 0x27ce: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_27d3:
	/* 0x27d3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_27d8:
	/* 0x27d8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27dc:
	/* 0x27dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27e1:
	/* 0x27e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27e3:
	/* 0x27e3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27e5:
	/* 0x27e5: js     2c56 <generic_sleepable_preload+0x2c56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11350ULL;
	}
x86_l_27eb:
	/* 0x27eb: cmp    WORD PTR [r12+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_27f5:
	/* 0x27f5: je     2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11507ULL;
	}
x86_l_27fb:
	/* 0x27fb: mov    ecx,DWORD PTR [r12+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2803:
	/* 0x2803: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2807:
	/* 0x2807: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_280b:
	/* 0x280b: cmp    WORD PTR [r12+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_2815:
	/* 0x2815: je     2837 <generic_sleepable_preload+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_2817:
	/* 0x2817: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_281a:
	/* 0x281a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_281f:
	/* 0x281f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2824:
	/* 0x2824: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2828:
	/* 0x2828: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_282d:
	/* 0x282d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_282f:
	/* 0x282f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2831:
	/* 0x2831: js     2ceb <generic_sleepable_preload+0x2ceb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11499ULL;
	}
x86_l_2837:
	/* 0x2837: cmp    WORD PTR [r12+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_2841:
	/* 0x2841: je     2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11507ULL;
	}
x86_l_2847:
	/* 0x2847: mov    ecx,DWORD PTR [r12+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_284f:
	/* 0x284f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2853:
	/* 0x2853: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2857:
	/* 0x2857: cmp    WORD PTR [r12+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2861:
	/* 0x2861: je     2883 <generic_sleepable_preload+0x2883> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2883;
	}
x86_l_2863:
	/* 0x2863: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2866:
	/* 0x2866: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_286b:
	/* 0x286b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2870:
	/* 0x2870: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2874:
	/* 0x2874: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2879:
	/* 0x2879: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_287b:
	/* 0x287b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_287d:
	/* 0x287d: js     5bf7 <generic_sleepable_preload+0x5bf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23543ULL;
	}
x86_l_2883:
	/* 0x2883: cmp    WORD PTR [r12+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
	return 10381ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10381ULL: goto x86_l_288d;
	case 10387ULL: goto x86_l_2893;
	case 10395ULL: goto x86_l_289b;
	case 10399ULL: goto x86_l_289f;
	case 10403ULL: goto x86_l_28a3;
	case 10413ULL: goto x86_l_28ad;
	case 10415ULL: goto x86_l_28af;
	case 10418ULL: goto x86_l_28b2;
	case 10423ULL: goto x86_l_28b7;
	case 10428ULL: goto x86_l_28bc;
	case 10432ULL: goto x86_l_28c0;
	case 10437ULL: goto x86_l_28c5;
	case 10439ULL: goto x86_l_28c7;
	case 10441ULL: goto x86_l_28c9;
	case 10447ULL: goto x86_l_28cf;
	case 10452ULL: goto x86_l_28d4;
	case 10462ULL: goto x86_l_28de;
	case 10468ULL: goto x86_l_28e4;
	case 10476ULL: goto x86_l_28ec;
	case 10480ULL: goto x86_l_28f0;
	case 10484ULL: goto x86_l_28f4;
	case 10494ULL: goto x86_l_28fe;
	case 10500ULL: goto x86_l_2904;
	case 10503ULL: goto x86_l_2907;
	case 10508ULL: goto x86_l_290c;
	case 10513ULL: goto x86_l_2911;
	case 10518ULL: goto x86_l_2916;
	case 10521ULL: goto x86_l_2919;
	case 10523ULL: goto x86_l_291b;
	case 10526ULL: goto x86_l_291e;
	case 10531ULL: goto x86_l_2923;
	case 10536ULL: goto x86_l_2928;
	case 10540ULL: goto x86_l_292c;
	case 10545ULL: goto x86_l_2931;
	case 10547ULL: goto x86_l_2933;
	case 10549ULL: goto x86_l_2935;
	case 10555ULL: goto x86_l_293b;
	case 10565ULL: goto x86_l_2945;
	case 10571ULL: goto x86_l_294b;
	case 10579ULL: goto x86_l_2953;
	case 10583ULL: goto x86_l_2957;
	case 10587ULL: goto x86_l_295b;
	case 10597ULL: goto x86_l_2965;
	case 10599ULL: goto x86_l_2967;
	case 10602ULL: goto x86_l_296a;
	case 10607ULL: goto x86_l_296f;
	case 10612ULL: goto x86_l_2974;
	case 10616ULL: goto x86_l_2978;
	case 10621ULL: goto x86_l_297d;
	case 10623ULL: goto x86_l_297f;
	case 10625ULL: goto x86_l_2981;
	case 10631ULL: goto x86_l_2987;
	case 10641ULL: goto x86_l_2991;
	case 10647ULL: goto x86_l_2997;
	case 10655ULL: goto x86_l_299f;
	case 10659ULL: goto x86_l_29a3;
	case 10663ULL: goto x86_l_29a7;
	case 10673ULL: goto x86_l_29b1;
	case 10675ULL: goto x86_l_29b3;
	case 10678ULL: goto x86_l_29b6;
	case 10683ULL: goto x86_l_29bb;
	case 10688ULL: goto x86_l_29c0;
	case 10692ULL: goto x86_l_29c4;
	case 10697ULL: goto x86_l_29c9;
	case 10699ULL: goto x86_l_29cb;
	case 10701ULL: goto x86_l_29cd;
	case 10707ULL: goto x86_l_29d3;
	case 10717ULL: goto x86_l_29dd;
	case 10723ULL: goto x86_l_29e3;
	case 10731ULL: goto x86_l_29eb;
	case 10735ULL: goto x86_l_29ef;
	case 10739ULL: goto x86_l_29f3;
	case 10749ULL: goto x86_l_29fd;
	case 10751ULL: goto x86_l_29ff;
	case 10754ULL: goto x86_l_2a02;
	case 10759ULL: goto x86_l_2a07;
	case 10764ULL: goto x86_l_2a0c;
	case 10768ULL: goto x86_l_2a10;
	case 10773ULL: goto x86_l_2a15;
	case 10775ULL: goto x86_l_2a17;
	case 10777ULL: goto x86_l_2a19;
	case 10783ULL: goto x86_l_2a1f;
	case 10793ULL: goto x86_l_2a29;
	case 10799ULL: goto x86_l_2a2f;
	case 10807ULL: goto x86_l_2a37;
	case 10811ULL: goto x86_l_2a3b;
	case 10815ULL: goto x86_l_2a3f;
	case 10825ULL: goto x86_l_2a49;
	case 10827ULL: goto x86_l_2a4b;
	case 10830ULL: goto x86_l_2a4e;
	case 10835ULL: goto x86_l_2a53;
	case 10840ULL: goto x86_l_2a58;
	case 10844ULL: goto x86_l_2a5c;
	case 10849ULL: goto x86_l_2a61;
	case 10851ULL: goto x86_l_2a63;
	case 10853ULL: goto x86_l_2a65;
	case 10859ULL: goto x86_l_2a6b;
	case 10869ULL: goto x86_l_2a75;
	case 10875ULL: goto x86_l_2a7b;
	case 10883ULL: goto x86_l_2a83;
	case 10887ULL: goto x86_l_2a87;
	case 10891ULL: goto x86_l_2a8b;
	case 10901ULL: goto x86_l_2a95;
	case 10903ULL: goto x86_l_2a97;
	case 10906ULL: goto x86_l_2a9a;
	case 10911ULL: goto x86_l_2a9f;
	case 10916ULL: goto x86_l_2aa4;
	case 10920ULL: goto x86_l_2aa8;
	case 10925ULL: goto x86_l_2aad;
	case 10927ULL: goto x86_l_2aaf;
	case 10929ULL: goto x86_l_2ab1;
	case 10935ULL: goto x86_l_2ab7;
	case 10945ULL: goto x86_l_2ac1;
	case 10951ULL: goto x86_l_2ac7;
	case 10959ULL: goto x86_l_2acf;
	case 10963ULL: goto x86_l_2ad3;
	case 10967ULL: goto x86_l_2ad7;
	case 10977ULL: goto x86_l_2ae1;
	case 10979ULL: goto x86_l_2ae3;
	case 10982ULL: goto x86_l_2ae6;
	case 10987ULL: goto x86_l_2aeb;
	case 10992ULL: goto x86_l_2af0;
	case 10996ULL: goto x86_l_2af4;
	case 11001ULL: goto x86_l_2af9;
	case 11003ULL: goto x86_l_2afb;
	case 11005ULL: goto x86_l_2afd;
	case 11011ULL: goto x86_l_2b03;
	case 11021ULL: goto x86_l_2b0d;
	case 11027ULL: goto x86_l_2b13;
	case 11030ULL: goto x86_l_2b16;
	case 11038ULL: goto x86_l_2b1e;
	case 11042ULL: goto x86_l_2b22;
	case 11046ULL: goto x86_l_2b26;
	case 11056ULL: goto x86_l_2b30;
	case 11058ULL: goto x86_l_2b32;
	case 11061ULL: goto x86_l_2b35;
	case 11066ULL: goto x86_l_2b3a;
	case 11071ULL: goto x86_l_2b3f;
	case 11075ULL: goto x86_l_2b43;
	case 11080ULL: goto x86_l_2b48;
	case 11082ULL: goto x86_l_2b4a;
	case 11084ULL: goto x86_l_2b4c;
	case 11090ULL: goto x86_l_2b52;
	case 11095ULL: goto x86_l_2b57;
	case 11105ULL: goto x86_l_2b61;
	case 11108ULL: goto x86_l_2b64;
	case 11114ULL: goto x86_l_2b6a;
	case 11122ULL: goto x86_l_2b72;
	case 11126ULL: goto x86_l_2b76;
	case 11130ULL: goto x86_l_2b7a;
	case 11140ULL: goto x86_l_2b84;
	case 11142ULL: goto x86_l_2b86;
	case 11145ULL: goto x86_l_2b89;
	case 11150ULL: goto x86_l_2b8e;
	case 11155ULL: goto x86_l_2b93;
	case 11159ULL: goto x86_l_2b97;
	case 11164ULL: goto x86_l_2b9c;
	case 11166ULL: goto x86_l_2b9e;
	case 11168ULL: goto x86_l_2ba0;
	case 11174ULL: goto x86_l_2ba6;
	case 11179ULL: goto x86_l_2bab;
	case 11189ULL: goto x86_l_2bb5;
	case 11192ULL: goto x86_l_2bb8;
	case 11198ULL: goto x86_l_2bbe;
	case 11206ULL: goto x86_l_2bc6;
	case 11210ULL: goto x86_l_2bca;
	case 11214ULL: goto x86_l_2bce;
	case 11224ULL: goto x86_l_2bd8;
	case 11230ULL: goto x86_l_2bde;
	case 11233ULL: goto x86_l_2be1;
	case 11238ULL: goto x86_l_2be6;
	case 11243ULL: goto x86_l_2beb;
	case 11247ULL: goto x86_l_2bef;
	case 11252ULL: goto x86_l_2bf4;
	case 11254ULL: goto x86_l_2bf6;
	case 11256ULL: goto x86_l_2bf8;
	case 11262ULL: goto x86_l_2bfe;
	case 11267ULL: goto x86_l_2c03;
	case 11272ULL: goto x86_l_2c08;
	case 11277ULL: goto x86_l_2c0d;
	case 11282ULL: goto x86_l_2c12;
	case 11287ULL: goto x86_l_2c17;
	case 11292ULL: goto x86_l_2c1c;
	case 11297ULL: goto x86_l_2c21;
	case 11299ULL: goto x86_l_2c23;
	case 11304ULL: goto x86_l_2c28;
	case 11309ULL: goto x86_l_2c2d;
	case 11314ULL: goto x86_l_2c32;
	case 11316ULL: goto x86_l_2c34;
	case 11321ULL: goto x86_l_2c39;
	case 11326ULL: goto x86_l_2c3e;
	case 11331ULL: goto x86_l_2c43;
	case 11333ULL: goto x86_l_2c45;
	case 11338ULL: goto x86_l_2c4a;
	case 11343ULL: goto x86_l_2c4f;
	case 11348ULL: goto x86_l_2c54;
	case 11350ULL: goto x86_l_2c56;
	case 11355ULL: goto x86_l_2c5b;
	case 11360ULL: goto x86_l_2c60;
	case 11365ULL: goto x86_l_2c65;
	case 11368ULL: goto x86_l_2c68;
	case 11373ULL: goto x86_l_2c6d;
	case 11376ULL: goto x86_l_2c70;
	case 11381ULL: goto x86_l_2c75;
	case 11386ULL: goto x86_l_2c7a;
	case 11391ULL: goto x86_l_2c7f;
	case 11394ULL: goto x86_l_2c82;
	case 11396ULL: goto x86_l_2c84;
	case 11399ULL: goto x86_l_2c87;
	case 11405ULL: goto x86_l_2c8d;
	case 11408ULL: goto x86_l_2c90;
	case 11412ULL: goto x86_l_2c94;
	case 11417ULL: goto x86_l_2c99;
	case 11419ULL: goto x86_l_2c9b;
	case 11424ULL: goto x86_l_2ca0;
	case 11432ULL: goto x86_l_2ca8;
	case 11439ULL: goto x86_l_2caf;
	case 11444ULL: goto x86_l_2cb4;
	case 11449ULL: goto x86_l_2cb9;
	case 11451ULL: goto x86_l_2cbb;
	case 11454ULL: goto x86_l_2cbe;
	case 11460ULL: goto x86_l_2cc4;
	case 11463ULL: goto x86_l_2cc7;
	case 11470ULL: goto x86_l_2cce;
	case 11472ULL: goto x86_l_2cd0;
	case 11477ULL: goto x86_l_2cd5;
	case 11482ULL: goto x86_l_2cda;
	case 11485ULL: goto x86_l_2cdd;
	case 11488ULL: goto x86_l_2ce0;
	case 11490ULL: goto x86_l_2ce2;
	case 11492ULL: goto x86_l_2ce4;
	case 11497ULL: goto x86_l_2ce9;
	case 11499ULL: goto x86_l_2ceb;
	case 11504ULL: goto x86_l_2cf0;
	case 11507ULL: goto x86_l_2cf3;
	case 11510ULL: goto x86_l_2cf6;
	case 11516ULL: goto x86_l_2cfc;
	case 11519ULL: goto x86_l_2cff;
	case 11523ULL: goto x86_l_2d03;
	case 11528ULL: goto x86_l_2d08;
	case 11530ULL: goto x86_l_2d0a;
	case 11535ULL: goto x86_l_2d0f;
	case 11543ULL: goto x86_l_2d17;
	case 11550ULL: goto x86_l_2d1e;
	case 11555ULL: goto x86_l_2d23;
	case 11560ULL: goto x86_l_2d28;
	case 11562ULL: goto x86_l_2d2a;
	case 11565ULL: goto x86_l_2d2d;
	case 11567ULL: goto x86_l_2d2f;
	case 11570ULL: goto x86_l_2d32;
	case 11577ULL: goto x86_l_2d39;
	case 11579ULL: goto x86_l_2d3b;
	case 11584ULL: goto x86_l_2d40;
	case 11589ULL: goto x86_l_2d45;
	case 11592ULL: goto x86_l_2d48;
	case 11595ULL: goto x86_l_2d4b;
	case 11597ULL: goto x86_l_2d4d;
	case 11599ULL: goto x86_l_2d4f;
	case 11604ULL: goto x86_l_2d54;
	case 11607ULL: goto x86_l_2d57;
	case 11610ULL: goto x86_l_2d5a;
	case 11615ULL: goto x86_l_2d5f;
	case 11617ULL: goto x86_l_2d61;
	case 11620ULL: goto x86_l_2d64;
	case 11622ULL: goto x86_l_2d66;
	case 11625ULL: goto x86_l_2d69;
	case 11627ULL: goto x86_l_2d6b;
	case 11630ULL: goto x86_l_2d6e;
	case 11634ULL: goto x86_l_2d72;
	case 11639ULL: goto x86_l_2d77;
	case 11642ULL: goto x86_l_2d7a;
	case 11644ULL: goto x86_l_2d7c;
	case 11647ULL: goto x86_l_2d7f;
	case 11652ULL: goto x86_l_2d84;
	case 11654ULL: goto x86_l_2d86;
	case 11657ULL: goto x86_l_2d89;
	case 11659ULL: goto x86_l_2d8b;
	case 11664ULL: goto x86_l_2d90;
	case 11667ULL: goto x86_l_2d93;
	case 11669ULL: goto x86_l_2d95;
	case 11672ULL: goto x86_l_2d98;
	case 11677ULL: goto x86_l_2d9d;
	case 11682ULL: goto x86_l_2da2;
	case 11688ULL: goto x86_l_2da8;
	case 11690ULL: goto x86_l_2daa;
	case 11692ULL: goto x86_l_2dac;
	case 11697ULL: goto x86_l_2db1;
	case 11700ULL: goto x86_l_2db4;
	case 11706ULL: goto x86_l_2dba;
	case 11709ULL: goto x86_l_2dbd;
	case 11715ULL: goto x86_l_2dc3;
	case 11718ULL: goto x86_l_2dc6;
	case 11724ULL: goto x86_l_2dcc;
	case 11727ULL: goto x86_l_2dcf;
	case 11733ULL: goto x86_l_2dd5;
	case 11738ULL: goto x86_l_2dda;
	case 11743ULL: goto x86_l_2ddf;
	case 11752ULL: goto x86_l_2de8;
	case 11761ULL: goto x86_l_2df1;
	case 11767ULL: goto x86_l_2df7;
	case 11769ULL: goto x86_l_2df9;
	case 11772ULL: goto x86_l_2dfc;
	case 11774ULL: goto x86_l_2dfe;
	case 11777ULL: goto x86_l_2e01;
	case 11779ULL: goto x86_l_2e03;
	case 11782ULL: goto x86_l_2e06;
	case 11788ULL: goto x86_l_2e0c;
	case 11793ULL: goto x86_l_2e11;
	case 11796ULL: goto x86_l_2e14;
	case 11802ULL: goto x86_l_2e1a;
	case 11807ULL: goto x86_l_2e1f;
	case 11810ULL: goto x86_l_2e22;
	case 11816ULL: goto x86_l_2e28;
	case 11821ULL: goto x86_l_2e2d;
	case 11824ULL: goto x86_l_2e30;
	case 11830ULL: goto x86_l_2e36;
	case 11835ULL: goto x86_l_2e3b;
	case 11838ULL: goto x86_l_2e3e;
	case 11840ULL: goto x86_l_2e40;
	case 11843ULL: goto x86_l_2e43;
	case 11849ULL: goto x86_l_2e49;
	case 11851ULL: goto x86_l_2e4b;
	case 11857ULL: goto x86_l_2e51;
	case 11860ULL: goto x86_l_2e54;
	case 11863ULL: goto x86_l_2e57;
	case 11869ULL: goto x86_l_2e5d;
	case 11874ULL: goto x86_l_2e62;
	case 11876ULL: goto x86_l_2e64;
	case 11878ULL: goto x86_l_2e66;
	case 11881ULL: goto x86_l_2e69;
	case 11883ULL: goto x86_l_2e6b;
	case 11888ULL: goto x86_l_2e70;
	case 11890ULL: goto x86_l_2e72;
	case 11893ULL: goto x86_l_2e75;
	case 11899ULL: goto x86_l_2e7b;
	case 11907ULL: goto x86_l_2e83;
	case 11910ULL: goto x86_l_2e86;
	case 11916ULL: goto x86_l_2e8c;
	case 11921ULL: goto x86_l_2e91;
	case 11924ULL: goto x86_l_2e94;
	case 11930ULL: goto x86_l_2e9a;
	case 11935ULL: goto x86_l_2e9f;
	case 11938ULL: goto x86_l_2ea2;
	case 11944ULL: goto x86_l_2ea8;
	case 11952ULL: goto x86_l_2eb0;
	case 11955ULL: goto x86_l_2eb3;
	case 11961ULL: goto x86_l_2eb9;
	case 11966ULL: goto x86_l_2ebe;
	case 11969ULL: goto x86_l_2ec1;
	case 11975ULL: goto x86_l_2ec7;
	case 11980ULL: goto x86_l_2ecc;
	case 11985ULL: goto x86_l_2ed1;
	case 11987ULL: goto x86_l_2ed3;
	case 11992ULL: goto x86_l_2ed8;
	case 11994ULL: goto x86_l_2eda;
	case 11999ULL: goto x86_l_2edf;
	case 12002ULL: goto x86_l_2ee2;
	case 12006ULL: goto x86_l_2ee6;
	case 12008ULL: goto x86_l_2ee8;
	case 12011ULL: goto x86_l_2eeb;
	case 12021ULL: goto x86_l_2ef5;
	case 12027ULL: goto x86_l_2efb;
	case 12034ULL: goto x86_l_2f02;
	case 12037ULL: goto x86_l_2f05;
	case 12045ULL: goto x86_l_2f0d;
	case 12048ULL: goto x86_l_2f10;
	case 12052ULL: goto x86_l_2f14;
	case 12061ULL: goto x86_l_2f1d;
	case 12063ULL: goto x86_l_2f1f;
	case 12069ULL: goto x86_l_2f25;
	case 12072ULL: goto x86_l_2f28;
	case 12074ULL: goto x86_l_2f2a;
	case 12077ULL: goto x86_l_2f2d;
	case 12082ULL: goto x86_l_2f32;
	case 12087ULL: goto x86_l_2f37;
	case 12091ULL: goto x86_l_2f3b;
	case 12096ULL: goto x86_l_2f40;
	case 12098ULL: goto x86_l_2f42;
	case 12100ULL: goto x86_l_2f44;
	case 12106ULL: goto x86_l_2f4a;
	case 12116ULL: goto x86_l_2f54;
	case 12122ULL: goto x86_l_2f5a;
	case 12130ULL: goto x86_l_2f62;
	case 12134ULL: goto x86_l_2f66;
	default: return 0xffffffffffffffffULL;
	}
x86_l_288d:
	/* 0x288d: je     2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf3;
	}
x86_l_2893:
	/* 0x2893: mov    ecx,DWORD PTR [r12+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_289b:
	/* 0x289b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_289f:
	/* 0x289f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28a3:
	/* 0x28a3: cmp    WORD PTR [r12+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_28ad:
	/* 0x28ad: je     28cf <generic_sleepable_preload+0x28cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28cf;
	}
x86_l_28af:
	/* 0x28af: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_28b2:
	/* 0x28b2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_28b7:
	/* 0x28b7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_28bc:
	/* 0x28bc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28c0:
	/* 0x28c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28c5:
	/* 0x28c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28c7:
	/* 0x28c7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28c9:
	/* 0x28c9: js     5cec <generic_sleepable_preload+0x5cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23788ULL;
	}
x86_l_28cf:
	/* 0x28cf: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28d4:
	/* 0x28d4: cmp    WORD PTR [r12+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_28de:
	/* 0x28de: je     2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf3;
	}
x86_l_28e4:
	/* 0x28e4: mov    ecx,DWORD PTR [r12+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_28ec:
	/* 0x28ec: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_28f0:
	/* 0x28f0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28f4:
	/* 0x28f4: cmp    WORD PTR [r12+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_28fe:
	/* 0x28fe: je     2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf3;
	}
x86_l_2904:
	/* 0x2904: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2907:
	/* 0x2907: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_290c:
	/* 0x290c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2911:
	/* 0x2911: jmp    2beb <generic_sleepable_preload+0x2beb> */
	goto x86_l_2beb;
x86_l_2916:
	/* 0x2916: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2919:
	/* 0x2919: je     293b <generic_sleepable_preload+0x293b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_293b;
	}
x86_l_291b:
	/* 0x291b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_291e:
	/* 0x291e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2923:
	/* 0x2923: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2928:
	/* 0x2928: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_292c:
	/* 0x292c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2931:
	/* 0x2931: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2933:
	/* 0x2933: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2935:
	/* 0x2935: js     2c08 <generic_sleepable_preload+0x2c08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c08;
	}
x86_l_293b:
	/* 0x293b: cmp    WORD PTR [r12+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_2945:
	/* 0x2945: je     2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf3;
	}
x86_l_294b:
	/* 0x294b: mov    ecx,DWORD PTR [r12+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2953:
	/* 0x2953: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2957:
	/* 0x2957: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_295b:
	/* 0x295b: cmp    WORD PTR [r12+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_2965:
	/* 0x2965: je     2987 <generic_sleepable_preload+0x2987> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2987;
	}
x86_l_2967:
	/* 0x2967: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_296a:
	/* 0x296a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_296f:
	/* 0x296f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2974:
	/* 0x2974: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2978:
	/* 0x2978: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_297d:
	/* 0x297d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_297f:
	/* 0x297f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2981:
	/* 0x2981: js     2c12 <generic_sleepable_preload+0x2c12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c12;
	}
x86_l_2987:
	/* 0x2987: cmp    WORD PTR [r12+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_2991:
	/* 0x2991: je     2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf3;
	}
x86_l_2997:
	/* 0x2997: mov    ecx,DWORD PTR [r12+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_299f:
	/* 0x299f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_29a3:
	/* 0x29a3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29a7:
	/* 0x29a7: cmp    WORD PTR [r12+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_29b1:
	/* 0x29b1: je     29d3 <generic_sleepable_preload+0x29d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29d3;
	}
x86_l_29b3:
	/* 0x29b3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29b6:
	/* 0x29b6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_29bb:
	/* 0x29bb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_29c0:
	/* 0x29c0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29c4:
	/* 0x29c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29c9:
	/* 0x29c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29cb:
	/* 0x29cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29cd:
	/* 0x29cd: js     2c23 <generic_sleepable_preload+0x2c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c23;
	}
x86_l_29d3:
	/* 0x29d3: cmp    WORD PTR [r12+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_29dd:
	/* 0x29dd: je     2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf3;
	}
x86_l_29e3:
	/* 0x29e3: mov    ecx,DWORD PTR [r12+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_29eb:
	/* 0x29eb: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_29ef:
	/* 0x29ef: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29f3:
	/* 0x29f3: cmp    WORD PTR [r12+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_29fd:
	/* 0x29fd: je     2a1f <generic_sleepable_preload+0x2a1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a1f;
	}
x86_l_29ff:
	/* 0x29ff: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a02:
	/* 0x2a02: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a07:
	/* 0x2a07: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a0c:
	/* 0x2a0c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a10:
	/* 0x2a10: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a15:
	/* 0x2a15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a17:
	/* 0x2a17: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a19:
	/* 0x2a19: js     2c34 <generic_sleepable_preload+0x2c34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c34;
	}
x86_l_2a1f:
	/* 0x2a1f: cmp    WORD PTR [r12+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_2a29:
	/* 0x2a29: je     2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf3;
	}
x86_l_2a2f:
	/* 0x2a2f: mov    ecx,DWORD PTR [r12+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2a37:
	/* 0x2a37: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a3b:
	/* 0x2a3b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a3f:
	/* 0x2a3f: cmp    WORD PTR [r12+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_2a49:
	/* 0x2a49: je     2a6b <generic_sleepable_preload+0x2a6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a6b;
	}
x86_l_2a4b:
	/* 0x2a4b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a4e:
	/* 0x2a4e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a53:
	/* 0x2a53: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a58:
	/* 0x2a58: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a5c:
	/* 0x2a5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a61:
	/* 0x2a61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a63:
	/* 0x2a63: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a65:
	/* 0x2a65: js     2c45 <generic_sleepable_preload+0x2c45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c45;
	}
x86_l_2a6b:
	/* 0x2a6b: cmp    WORD PTR [r12+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_2a75:
	/* 0x2a75: je     2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf3;
	}
x86_l_2a7b:
	/* 0x2a7b: mov    ecx,DWORD PTR [r12+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2a83:
	/* 0x2a83: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a87:
	/* 0x2a87: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a8b:
	/* 0x2a8b: cmp    WORD PTR [r12+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2a95:
	/* 0x2a95: je     2ab7 <generic_sleepable_preload+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ab7;
	}
x86_l_2a97:
	/* 0x2a97: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a9a:
	/* 0x2a9a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a9f:
	/* 0x2a9f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2aa4:
	/* 0x2aa4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2aa8:
	/* 0x2aa8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2aad:
	/* 0x2aad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aaf:
	/* 0x2aaf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ab1:
	/* 0x2ab1: js     2c56 <generic_sleepable_preload+0x2c56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c56;
	}
x86_l_2ab7:
	/* 0x2ab7: cmp    WORD PTR [r12+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2ac1:
	/* 0x2ac1: je     2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf3;
	}
x86_l_2ac7:
	/* 0x2ac7: mov    ecx,DWORD PTR [r12+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2acf:
	/* 0x2acf: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2ad3:
	/* 0x2ad3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ad7:
	/* 0x2ad7: cmp    WORD PTR [r12+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_2ae1:
	/* 0x2ae1: je     2b03 <generic_sleepable_preload+0x2b03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b03;
	}
x86_l_2ae3:
	/* 0x2ae3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ae6:
	/* 0x2ae6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2aeb:
	/* 0x2aeb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2af0:
	/* 0x2af0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2af4:
	/* 0x2af4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2af9:
	/* 0x2af9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2afb:
	/* 0x2afb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2afd:
	/* 0x2afd: js     2ceb <generic_sleepable_preload+0x2ceb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2ceb;
	}
x86_l_2b03:
	/* 0x2b03: cmp    WORD PTR [r12+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_2b0d:
	/* 0x2b0d: je     2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf3;
	}
x86_l_2b13:
	/* 0x2b13: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_2b16:
	/* 0x2b16: mov    ecx,DWORD PTR [r12+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2b1e:
	/* 0x2b1e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2b22:
	/* 0x2b22: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b26:
	/* 0x2b26: cmp    WORD PTR [r12+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2b30:
	/* 0x2b30: je     2b52 <generic_sleepable_preload+0x2b52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b52;
	}
x86_l_2b32:
	/* 0x2b32: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b35:
	/* 0x2b35: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b3a:
	/* 0x2b3a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b3f:
	/* 0x2b3f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b43:
	/* 0x2b43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b48:
	/* 0x2b48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b4a:
	/* 0x2b4a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b4c:
	/* 0x2b4c: js     5c75 <generic_sleepable_preload+0x5c75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23669ULL;
	}
x86_l_2b52:
	/* 0x2b52: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b57:
	/* 0x2b57: cmp    WORD PTR [r12+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2b61:
	/* 0x2b61: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_2b64:
	/* 0x2b64: je     2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf3;
	}
x86_l_2b6a:
	/* 0x2b6a: mov    ecx,DWORD PTR [r12+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2b72:
	/* 0x2b72: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2b76:
	/* 0x2b76: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b7a:
	/* 0x2b7a: cmp    WORD PTR [r12+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_2b84:
	/* 0x2b84: je     2ba6 <generic_sleepable_preload+0x2ba6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ba6;
	}
x86_l_2b86:
	/* 0x2b86: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b89:
	/* 0x2b89: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b8e:
	/* 0x2b8e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b93:
	/* 0x2b93: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b97:
	/* 0x2b97: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b9c:
	/* 0x2b9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b9e:
	/* 0x2b9e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ba0:
	/* 0x2ba0: js     5d85 <generic_sleepable_preload+0x5d85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23941ULL;
	}
x86_l_2ba6:
	/* 0x2ba6: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bab:
	/* 0x2bab: cmp    WORD PTR [r12+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2bb5:
	/* 0x2bb5: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_2bb8:
	/* 0x2bb8: je     2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf3;
	}
x86_l_2bbe:
	/* 0x2bbe: mov    ecx,DWORD PTR [r12+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2bc6:
	/* 0x2bc6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2bca:
	/* 0x2bca: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bce:
	/* 0x2bce: cmp    WORD PTR [r12+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_2bd8:
	/* 0x2bd8: je     2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf3;
	}
x86_l_2bde:
	/* 0x2bde: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2be1:
	/* 0x2be1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2be6:
	/* 0x2be6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2beb:
	/* 0x2beb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bef:
	/* 0x2bef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bf4:
	/* 0x2bf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf6:
	/* 0x2bf6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bf8:
	/* 0x2bf8: jns    2cf3 <generic_sleepable_preload+0x2cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_2cf3;
	}
x86_l_2bfe:
	/* 0x2bfe: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_2c03:
	/* 0x2c03: jmp    2cf0 <generic_sleepable_preload+0x2cf0> */
	goto x86_l_2cf0;
x86_l_2c08:
	/* 0x2c08: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2c0d:
	/* 0x2c0d: jmp    2cf0 <generic_sleepable_preload+0x2cf0> */
	goto x86_l_2cf0;
x86_l_2c12:
	/* 0x2c12: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_2c17:
	/* 0x2c17: jmp    2cf0 <generic_sleepable_preload+0x2cf0> */
	goto x86_l_2cf0;
x86_l_2c1c:
	/* 0x2c1c: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_2c21:
	/* 0x2c21: jmp    2c65 <generic_sleepable_preload+0x2c65> */
	goto x86_l_2c65;
x86_l_2c23:
	/* 0x2c23: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_2c28:
	/* 0x2c28: jmp    2cf0 <generic_sleepable_preload+0x2cf0> */
	goto x86_l_2cf0;
x86_l_2c2d:
	/* 0x2c2d: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2c32:
	/* 0x2c32: jmp    2c65 <generic_sleepable_preload+0x2c65> */
	goto x86_l_2c65;
x86_l_2c34:
	/* 0x2c34: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2c39:
	/* 0x2c39: jmp    2cf0 <generic_sleepable_preload+0x2cf0> */
	goto x86_l_2cf0;
x86_l_2c3e:
	/* 0x2c3e: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2c43:
	/* 0x2c43: jmp    2c65 <generic_sleepable_preload+0x2c65> */
	goto x86_l_2c65;
x86_l_2c45:
	/* 0x2c45: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2c4a:
	/* 0x2c4a: jmp    2cf0 <generic_sleepable_preload+0x2cf0> */
	goto x86_l_2cf0;
x86_l_2c4f:
	/* 0x2c4f: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2c54:
	/* 0x2c54: jmp    2c65 <generic_sleepable_preload+0x2c65> */
	goto x86_l_2c65;
x86_l_2c56:
	/* 0x2c56: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2c5b:
	/* 0x2c5b: jmp    2cf0 <generic_sleepable_preload+0x2cf0> */
	goto x86_l_2cf0;
x86_l_2c60:
	/* 0x2c60: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_2c65:
	/* 0x2c65: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c68:
	/* 0x2c68: mov    ebp,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c6d:
	/* 0x2c6d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2c70:
	/* 0x2c70: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c75:
	/* 0x2c75: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c7a:
	/* 0x2c7a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c7f:
	/* 0x2c7f: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2c82:
	/* 0x2c82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c84:
	/* 0x2c84: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_2c87:
	/* 0x2c87: jne    2d98 <generic_sleepable_preload+0x2d98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d98;
	}
x86_l_2c8d:
	/* 0x2c8d: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_2c90:
	/* 0x2c90: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c94:
	/* 0x2c94: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2c99:
	/* 0x2c99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c9b:
	/* 0x2c9b: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ca0:
	/* 0x2ca0: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2ca8:
	/* 0x2ca8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2caf:
	/* 0x2caf: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2cb4:
	/* 0x2cb4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cb9:
	/* 0x2cb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cbb:
	/* 0x2cbb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cbe:
	/* 0x2cbe: je     2d95 <generic_sleepable_preload+0x2d95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d95;
	}
x86_l_2cc4:
	/* 0x2cc4: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2cc7:
	/* 0x2cc7: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2cce:
	/* 0x2cce: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cd0:
	/* 0x2cd0: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cd5:
	/* 0x2cd5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2cda:
	/* 0x2cda: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2cdd:
	/* 0x2cdd: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2ce0:
	/* 0x2ce0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ce2:
	/* 0x2ce2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ce4:
	/* 0x2ce4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ce9:
	/* 0x2ce9: jmp    2d54 <generic_sleepable_preload+0x2d54> */
	goto x86_l_2d54;
x86_l_2ceb:
	/* 0x2ceb: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_2cf0:
	/* 0x2cf0: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cf3:
	/* 0x2cf3: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_2cf6:
	/* 0x2cf6: jne    2d98 <generic_sleepable_preload+0x2d98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d98;
	}
x86_l_2cfc:
	/* 0x2cfc: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_2cff:
	/* 0x2cff: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d03:
	/* 0x2d03: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2d08:
	/* 0x2d08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d0a:
	/* 0x2d0a: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d0f:
	/* 0x2d0f: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2d17:
	/* 0x2d17: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2d1e:
	/* 0x2d1e: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2d23:
	/* 0x2d23: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d28:
	/* 0x2d28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d2a:
	/* 0x2d2a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d2d:
	/* 0x2d2d: je     2d95 <generic_sleepable_preload+0x2d95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d95;
	}
x86_l_2d2f:
	/* 0x2d2f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2d32:
	/* 0x2d32: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2d39:
	/* 0x2d39: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d3b:
	/* 0x2d3b: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d40:
	/* 0x2d40: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d45:
	/* 0x2d45: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2d48:
	/* 0x2d48: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2d4b:
	/* 0x2d4b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d4d:
	/* 0x2d4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d4f:
	/* 0x2d4f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d54:
	/* 0x2d54: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2d57:
	/* 0x2d57: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2d5a:
	/* 0x2d5a: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d5f:
	/* 0x2d5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d61:
	/* 0x2d61: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d64:
	/* 0x2d64: je     2d95 <generic_sleepable_preload+0x2d95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d95;
	}
x86_l_2d66:
	/* 0x2d66: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_2d69:
	/* 0x2d69: je     2d93 <generic_sleepable_preload+0x2d93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d93;
	}
x86_l_2d6b:
	/* 0x2d6b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2d6e:
	/* 0x2d6e: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2d72:
	/* 0x2d72: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2d77:
	/* 0x2d77: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2d7a:
	/* 0x2d7a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d7c:
	/* 0x2d7c: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_2d7f:
	/* 0x2d7f: call   2d84 <generic_sleepable_preload+0x2d84> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_2d84:
	/* 0x2d84: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2d86:
	/* 0x2d86: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_2d89:
	/* 0x2d89: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2d8b:
	/* 0x2d8b: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2d90:
	/* 0x2d90: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_2d93:
	/* 0x2d93: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d95:
	/* 0x2d95: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_2d98:
	/* 0x2d98: mov    eax,DWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d9d:
	/* 0x2d9d: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_2da2:
	/* 0x2da2: je     3d03 <generic_sleepable_preload+0x3d03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15619ULL;
	}
x86_l_2da8:
	/* 0x2da8: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2daa:
	/* 0x2daa: js     2ddf <generic_sleepable_preload+0x2ddf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2ddf;
	}
x86_l_2dac:
	/* 0x2dac: mov    eax,DWORD PTR [r12+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2db1:
	/* 0x2db1: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2db4:
	/* 0x2db4: jle    2e62 <generic_sleepable_preload+0x2e62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e62;
	}
x86_l_2dba:
	/* 0x2dba: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2dbd:
	/* 0x2dbd: je     2ecc <generic_sleepable_preload+0x2ecc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ecc;
	}
x86_l_2dc3:
	/* 0x2dc3: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2dc6:
	/* 0x2dc6: je     2ed3 <generic_sleepable_preload+0x2ed3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ed3;
	}
x86_l_2dcc:
	/* 0x2dcc: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2dcf:
	/* 0x2dcf: jne    2ee6 <generic_sleepable_preload+0x2ee6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ee6;
	}
x86_l_2dd5:
	/* 0x2dd5: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2dda:
	/* 0x2dda: jmp    2edf <generic_sleepable_preload+0x2edf> */
	goto x86_l_2edf;
x86_l_2ddf:
	/* 0x2ddf: movzx  eax,BYTE PTR [r12+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_2de8:
	/* 0x2de8: movzx  ecx,WORD PTR [r12+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
x86_l_2df1:
	/* 0x2df1: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_2df7:
	/* 0x2df7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2df9:
	/* 0x2df9: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_2dfc:
	/* 0x2dfc: jle    2e3b <generic_sleepable_preload+0x2e3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e3b;
	}
x86_l_2dfe:
	/* 0x2dfe: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_2e01:
	/* 0x2e01: jle    2e72 <generic_sleepable_preload+0x2e72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e72;
	}
x86_l_2e03:
	/* 0x2e03: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2e06:
	/* 0x2e06: jle    3535 <generic_sleepable_preload+0x3535> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 13621ULL;
	}
x86_l_2e0c:
	/* 0x2e0c: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e11:
	/* 0x2e11: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_2e14:
	/* 0x2e14: je     355a <generic_sleepable_preload+0x355a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13658ULL;
	}
x86_l_2e1a:
	/* 0x2e1a: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2e1f:
	/* 0x2e1f: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_2e22:
	/* 0x2e22: je     355a <generic_sleepable_preload+0x355a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13658ULL;
	}
x86_l_2e28:
	/* 0x2e28: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2e2d:
	/* 0x2e2d: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_2e30:
	/* 0x2e30: je     355a <generic_sleepable_preload+0x355a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13658ULL;
	}
x86_l_2e36:
	/* 0x2e36: jmp    356d <generic_sleepable_preload+0x356d> */
	return 13677ULL;
x86_l_2e3b:
	/* 0x2e3b: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2e3e:
	/* 0x2e3e: jg     2e9f <generic_sleepable_preload+0x2e9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2e9f;
	}
x86_l_2e40:
	/* 0x2e40: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2e43:
	/* 0x2e43: jg     3506 <generic_sleepable_preload+0x3506> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 13574ULL;
	}
x86_l_2e49:
	/* 0x2e49: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2e4b:
	/* 0x2e4b: je     3555 <generic_sleepable_preload+0x3555> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13653ULL;
	}
x86_l_2e51:
	/* 0x2e51: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2e54:
	/* 0x2e54: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2e57:
	/* 0x2e57: je     355a <generic_sleepable_preload+0x355a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13658ULL;
	}
x86_l_2e5d:
	/* 0x2e5d: jmp    356d <generic_sleepable_preload+0x356d> */
	return 13677ULL;
x86_l_2e62:
	/* 0x2e62: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e64:
	/* 0x2e64: je     2eda <generic_sleepable_preload+0x2eda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2eda;
	}
x86_l_2e66:
	/* 0x2e66: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e69:
	/* 0x2e69: jne    2ee6 <generic_sleepable_preload+0x2ee6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ee6;
	}
x86_l_2e6b:
	/* 0x2e6b: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e70:
	/* 0x2e70: jmp    2edf <generic_sleepable_preload+0x2edf> */
	goto x86_l_2edf;
x86_l_2e72:
	/* 0x2e72: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_2e75:
	/* 0x2e75: jg     34ed <generic_sleepable_preload+0x34ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 13549ULL;
	}
x86_l_2e7b:
	/* 0x2e7b: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2e83:
	/* 0x2e83: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e86:
	/* 0x2e86: je     355a <generic_sleepable_preload+0x355a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13658ULL;
	}
x86_l_2e8c:
	/* 0x2e8c: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e91:
	/* 0x2e91: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_2e94:
	/* 0x2e94: je     355a <generic_sleepable_preload+0x355a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13658ULL;
	}
x86_l_2e9a:
	/* 0x2e9a: jmp    356d <generic_sleepable_preload+0x356d> */
	return 13677ULL;
x86_l_2e9f:
	/* 0x2e9f: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_2ea2:
	/* 0x2ea2: jg     351c <generic_sleepable_preload+0x351c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 13596ULL;
	}
x86_l_2ea8:
	/* 0x2ea8: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2eb0:
	/* 0x2eb0: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2eb3:
	/* 0x2eb3: je     355a <generic_sleepable_preload+0x355a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13658ULL;
	}
x86_l_2eb9:
	/* 0x2eb9: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2ebe:
	/* 0x2ebe: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_2ec1:
	/* 0x2ec1: je     355a <generic_sleepable_preload+0x355a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13658ULL;
	}
x86_l_2ec7:
	/* 0x2ec7: jmp    356d <generic_sleepable_preload+0x356d> */
	return 13677ULL;
x86_l_2ecc:
	/* 0x2ecc: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ed1:
	/* 0x2ed1: jmp    2edf <generic_sleepable_preload+0x2edf> */
	goto x86_l_2edf;
x86_l_2ed3:
	/* 0x2ed3: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ed8:
	/* 0x2ed8: jmp    2edf <generic_sleepable_preload+0x2edf> */
	goto x86_l_2edf;
x86_l_2eda:
	/* 0x2eda: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2edf:
	/* 0x2edf: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ee2:
	/* 0x2ee2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ee6:
	/* 0x2ee6: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ee8:
	/* 0x2ee8: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_2eeb:
	/* 0x2eeb: cmp    WORD PTR [r12+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_2ef5:
	/* 0x2ef5: je     3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15315ULL;
	}
x86_l_2efb:
	/* 0x2efb: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_2f02:
	/* 0x2f02: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2f05:
	/* 0x2f05: mov    eax,DWORD PTR [r12+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2f0d:
	/* 0x2f0d: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f10:
	/* 0x2f10: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f14:
	/* 0x2f14: movzx  eax,WORD PTR [r12+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_2f1d:
	/* 0x2f1d: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_2f1f:
	/* 0x2f1f: je     31f1 <generic_sleepable_preload+0x31f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12785ULL;
	}
x86_l_2f25:
	/* 0x2f25: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2f28:
	/* 0x2f28: je     2f4a <generic_sleepable_preload+0x2f4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f4a;
	}
x86_l_2f2a:
	/* 0x2f2a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2f2d:
	/* 0x2f2d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f32:
	/* 0x2f32: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2f37:
	/* 0x2f37: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f3b:
	/* 0x2f3b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f40:
	/* 0x2f40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f42:
	/* 0x2f42: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f44:
	/* 0x2f44: js     34e3 <generic_sleepable_preload+0x34e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13539ULL;
	}
x86_l_2f4a:
	/* 0x2f4a: cmp    WORD PTR [r12+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_2f54:
	/* 0x2f54: je     3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15315ULL;
	}
x86_l_2f5a:
	/* 0x2f5a: mov    ecx,DWORD PTR [r12+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2f62:
	/* 0x2f62: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2f66:
	/* 0x2f66: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 12138ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12138ULL: goto x86_l_2f6a;
	case 12148ULL: goto x86_l_2f74;
	case 12150ULL: goto x86_l_2f76;
	case 12153ULL: goto x86_l_2f79;
	case 12158ULL: goto x86_l_2f7e;
	case 12163ULL: goto x86_l_2f83;
	case 12167ULL: goto x86_l_2f87;
	case 12172ULL: goto x86_l_2f8c;
	case 12174ULL: goto x86_l_2f8e;
	case 12176ULL: goto x86_l_2f90;
	case 12182ULL: goto x86_l_2f96;
	case 12192ULL: goto x86_l_2fa0;
	case 12198ULL: goto x86_l_2fa6;
	case 12206ULL: goto x86_l_2fae;
	case 12210ULL: goto x86_l_2fb2;
	case 12214ULL: goto x86_l_2fb6;
	case 12224ULL: goto x86_l_2fc0;
	case 12226ULL: goto x86_l_2fc2;
	case 12229ULL: goto x86_l_2fc5;
	case 12234ULL: goto x86_l_2fca;
	case 12239ULL: goto x86_l_2fcf;
	case 12243ULL: goto x86_l_2fd3;
	case 12248ULL: goto x86_l_2fd8;
	case 12250ULL: goto x86_l_2fda;
	case 12252ULL: goto x86_l_2fdc;
	case 12258ULL: goto x86_l_2fe2;
	case 12268ULL: goto x86_l_2fec;
	case 12274ULL: goto x86_l_2ff2;
	case 12282ULL: goto x86_l_2ffa;
	case 12286ULL: goto x86_l_2ffe;
	case 12290ULL: goto x86_l_3002;
	case 12300ULL: goto x86_l_300c;
	case 12302ULL: goto x86_l_300e;
	case 12305ULL: goto x86_l_3011;
	case 12310ULL: goto x86_l_3016;
	case 12315ULL: goto x86_l_301b;
	case 12319ULL: goto x86_l_301f;
	case 12324ULL: goto x86_l_3024;
	case 12326ULL: goto x86_l_3026;
	case 12328ULL: goto x86_l_3028;
	case 12334ULL: goto x86_l_302e;
	case 12344ULL: goto x86_l_3038;
	case 12350ULL: goto x86_l_303e;
	case 12358ULL: goto x86_l_3046;
	case 12362ULL: goto x86_l_304a;
	case 12366ULL: goto x86_l_304e;
	case 12376ULL: goto x86_l_3058;
	case 12378ULL: goto x86_l_305a;
	case 12381ULL: goto x86_l_305d;
	case 12386ULL: goto x86_l_3062;
	case 12391ULL: goto x86_l_3067;
	case 12395ULL: goto x86_l_306b;
	case 12400ULL: goto x86_l_3070;
	case 12402ULL: goto x86_l_3072;
	case 12404ULL: goto x86_l_3074;
	case 12410ULL: goto x86_l_307a;
	case 12420ULL: goto x86_l_3084;
	case 12426ULL: goto x86_l_308a;
	case 12434ULL: goto x86_l_3092;
	case 12438ULL: goto x86_l_3096;
	case 12442ULL: goto x86_l_309a;
	case 12452ULL: goto x86_l_30a4;
	case 12454ULL: goto x86_l_30a6;
	case 12457ULL: goto x86_l_30a9;
	case 12462ULL: goto x86_l_30ae;
	case 12467ULL: goto x86_l_30b3;
	case 12471ULL: goto x86_l_30b7;
	case 12476ULL: goto x86_l_30bc;
	case 12478ULL: goto x86_l_30be;
	case 12480ULL: goto x86_l_30c0;
	case 12486ULL: goto x86_l_30c6;
	case 12496ULL: goto x86_l_30d0;
	case 12502ULL: goto x86_l_30d6;
	case 12510ULL: goto x86_l_30de;
	case 12514ULL: goto x86_l_30e2;
	case 12518ULL: goto x86_l_30e6;
	case 12528ULL: goto x86_l_30f0;
	case 12530ULL: goto x86_l_30f2;
	case 12533ULL: goto x86_l_30f5;
	case 12538ULL: goto x86_l_30fa;
	case 12543ULL: goto x86_l_30ff;
	case 12547ULL: goto x86_l_3103;
	case 12552ULL: goto x86_l_3108;
	case 12554ULL: goto x86_l_310a;
	case 12556ULL: goto x86_l_310c;
	case 12562ULL: goto x86_l_3112;
	case 12572ULL: goto x86_l_311c;
	case 12578ULL: goto x86_l_3122;
	case 12586ULL: goto x86_l_312a;
	case 12590ULL: goto x86_l_312e;
	case 12594ULL: goto x86_l_3132;
	case 12604ULL: goto x86_l_313c;
	case 12606ULL: goto x86_l_313e;
	case 12609ULL: goto x86_l_3141;
	case 12614ULL: goto x86_l_3146;
	case 12619ULL: goto x86_l_314b;
	case 12623ULL: goto x86_l_314f;
	case 12628ULL: goto x86_l_3154;
	case 12630ULL: goto x86_l_3156;
	case 12632ULL: goto x86_l_3158;
	case 12638ULL: goto x86_l_315e;
	case 12648ULL: goto x86_l_3168;
	case 12654ULL: goto x86_l_316e;
	case 12662ULL: goto x86_l_3176;
	case 12666ULL: goto x86_l_317a;
	case 12670ULL: goto x86_l_317e;
	case 12680ULL: goto x86_l_3188;
	case 12682ULL: goto x86_l_318a;
	case 12685ULL: goto x86_l_318d;
	case 12690ULL: goto x86_l_3192;
	case 12695ULL: goto x86_l_3197;
	case 12699ULL: goto x86_l_319b;
	case 12704ULL: goto x86_l_31a0;
	case 12706ULL: goto x86_l_31a2;
	case 12708ULL: goto x86_l_31a4;
	case 12714ULL: goto x86_l_31aa;
	case 12719ULL: goto x86_l_31af;
	case 12729ULL: goto x86_l_31b9;
	case 12735ULL: goto x86_l_31bf;
	case 12743ULL: goto x86_l_31c7;
	case 12747ULL: goto x86_l_31cb;
	case 12751ULL: goto x86_l_31cf;
	case 12761ULL: goto x86_l_31d9;
	case 12767ULL: goto x86_l_31df;
	case 12770ULL: goto x86_l_31e2;
	case 12775ULL: goto x86_l_31e7;
	case 12780ULL: goto x86_l_31ec;
	case 12785ULL: goto x86_l_31f1;
	case 12788ULL: goto x86_l_31f4;
	case 12790ULL: goto x86_l_31f6;
	case 12793ULL: goto x86_l_31f9;
	case 12798ULL: goto x86_l_31fe;
	case 12803ULL: goto x86_l_3203;
	case 12807ULL: goto x86_l_3207;
	case 12812ULL: goto x86_l_320c;
	case 12814ULL: goto x86_l_320e;
	case 12816ULL: goto x86_l_3210;
	case 12822ULL: goto x86_l_3216;
	case 12832ULL: goto x86_l_3220;
	case 12838ULL: goto x86_l_3226;
	case 12846ULL: goto x86_l_322e;
	case 12850ULL: goto x86_l_3232;
	case 12854ULL: goto x86_l_3236;
	case 12864ULL: goto x86_l_3240;
	case 12866ULL: goto x86_l_3242;
	case 12869ULL: goto x86_l_3245;
	case 12874ULL: goto x86_l_324a;
	case 12879ULL: goto x86_l_324f;
	case 12883ULL: goto x86_l_3253;
	case 12888ULL: goto x86_l_3258;
	case 12890ULL: goto x86_l_325a;
	case 12892ULL: goto x86_l_325c;
	case 12898ULL: goto x86_l_3262;
	case 12908ULL: goto x86_l_326c;
	case 12914ULL: goto x86_l_3272;
	case 12922ULL: goto x86_l_327a;
	case 12926ULL: goto x86_l_327e;
	case 12930ULL: goto x86_l_3282;
	case 12940ULL: goto x86_l_328c;
	case 12942ULL: goto x86_l_328e;
	case 12945ULL: goto x86_l_3291;
	case 12950ULL: goto x86_l_3296;
	case 12955ULL: goto x86_l_329b;
	case 12959ULL: goto x86_l_329f;
	case 12964ULL: goto x86_l_32a4;
	case 12966ULL: goto x86_l_32a6;
	case 12968ULL: goto x86_l_32a8;
	case 12974ULL: goto x86_l_32ae;
	case 12984ULL: goto x86_l_32b8;
	case 12990ULL: goto x86_l_32be;
	case 12998ULL: goto x86_l_32c6;
	case 13002ULL: goto x86_l_32ca;
	case 13006ULL: goto x86_l_32ce;
	case 13016ULL: goto x86_l_32d8;
	case 13018ULL: goto x86_l_32da;
	case 13021ULL: goto x86_l_32dd;
	case 13026ULL: goto x86_l_32e2;
	case 13031ULL: goto x86_l_32e7;
	case 13035ULL: goto x86_l_32eb;
	case 13040ULL: goto x86_l_32f0;
	case 13042ULL: goto x86_l_32f2;
	case 13044ULL: goto x86_l_32f4;
	case 13050ULL: goto x86_l_32fa;
	case 13060ULL: goto x86_l_3304;
	case 13066ULL: goto x86_l_330a;
	case 13074ULL: goto x86_l_3312;
	case 13078ULL: goto x86_l_3316;
	case 13082ULL: goto x86_l_331a;
	case 13092ULL: goto x86_l_3324;
	case 13094ULL: goto x86_l_3326;
	case 13097ULL: goto x86_l_3329;
	case 13102ULL: goto x86_l_332e;
	case 13107ULL: goto x86_l_3333;
	case 13111ULL: goto x86_l_3337;
	case 13116ULL: goto x86_l_333c;
	case 13118ULL: goto x86_l_333e;
	case 13120ULL: goto x86_l_3340;
	case 13126ULL: goto x86_l_3346;
	case 13136ULL: goto x86_l_3350;
	case 13142ULL: goto x86_l_3356;
	case 13150ULL: goto x86_l_335e;
	case 13154ULL: goto x86_l_3362;
	case 13158ULL: goto x86_l_3366;
	case 13168ULL: goto x86_l_3370;
	case 13170ULL: goto x86_l_3372;
	case 13173ULL: goto x86_l_3375;
	case 13178ULL: goto x86_l_337a;
	case 13183ULL: goto x86_l_337f;
	case 13187ULL: goto x86_l_3383;
	case 13192ULL: goto x86_l_3388;
	case 13194ULL: goto x86_l_338a;
	case 13196ULL: goto x86_l_338c;
	case 13202ULL: goto x86_l_3392;
	case 13212ULL: goto x86_l_339c;
	case 13218ULL: goto x86_l_33a2;
	case 13226ULL: goto x86_l_33aa;
	case 13230ULL: goto x86_l_33ae;
	case 13234ULL: goto x86_l_33b2;
	case 13244ULL: goto x86_l_33bc;
	case 13246ULL: goto x86_l_33be;
	case 13249ULL: goto x86_l_33c1;
	case 13254ULL: goto x86_l_33c6;
	case 13259ULL: goto x86_l_33cb;
	case 13263ULL: goto x86_l_33cf;
	case 13268ULL: goto x86_l_33d4;
	case 13270ULL: goto x86_l_33d6;
	case 13272ULL: goto x86_l_33d8;
	case 13278ULL: goto x86_l_33de;
	case 13288ULL: goto x86_l_33e8;
	case 13294ULL: goto x86_l_33ee;
	case 13297ULL: goto x86_l_33f1;
	case 13305ULL: goto x86_l_33f9;
	case 13309ULL: goto x86_l_33fd;
	case 13313ULL: goto x86_l_3401;
	case 13323ULL: goto x86_l_340b;
	case 13325ULL: goto x86_l_340d;
	case 13328ULL: goto x86_l_3410;
	case 13333ULL: goto x86_l_3415;
	case 13338ULL: goto x86_l_341a;
	case 13342ULL: goto x86_l_341e;
	case 13347ULL: goto x86_l_3423;
	case 13349ULL: goto x86_l_3425;
	case 13351ULL: goto x86_l_3427;
	case 13357ULL: goto x86_l_342d;
	case 13362ULL: goto x86_l_3432;
	case 13372ULL: goto x86_l_343c;
	case 13375ULL: goto x86_l_343f;
	case 13381ULL: goto x86_l_3445;
	case 13389ULL: goto x86_l_344d;
	case 13393ULL: goto x86_l_3451;
	case 13397ULL: goto x86_l_3455;
	case 13407ULL: goto x86_l_345f;
	case 13409ULL: goto x86_l_3461;
	case 13412ULL: goto x86_l_3464;
	case 13417ULL: goto x86_l_3469;
	case 13422ULL: goto x86_l_346e;
	case 13426ULL: goto x86_l_3472;
	case 13431ULL: goto x86_l_3477;
	case 13433ULL: goto x86_l_3479;
	case 13435ULL: goto x86_l_347b;
	case 13441ULL: goto x86_l_3481;
	case 13446ULL: goto x86_l_3486;
	case 13456ULL: goto x86_l_3490;
	case 13459ULL: goto x86_l_3493;
	case 13465ULL: goto x86_l_3499;
	case 13473ULL: goto x86_l_34a1;
	case 13477ULL: goto x86_l_34a5;
	case 13481ULL: goto x86_l_34a9;
	case 13491ULL: goto x86_l_34b3;
	case 13497ULL: goto x86_l_34b9;
	case 13500ULL: goto x86_l_34bc;
	case 13505ULL: goto x86_l_34c1;
	case 13510ULL: goto x86_l_34c6;
	case 13514ULL: goto x86_l_34ca;
	case 13519ULL: goto x86_l_34cf;
	case 13521ULL: goto x86_l_34d1;
	case 13523ULL: goto x86_l_34d3;
	case 13529ULL: goto x86_l_34d9;
	case 13534ULL: goto x86_l_34de;
	case 13539ULL: goto x86_l_34e3;
	case 13544ULL: goto x86_l_34e8;
	case 13549ULL: goto x86_l_34ed;
	case 13557ULL: goto x86_l_34f5;
	case 13560ULL: goto x86_l_34f8;
	case 13562ULL: goto x86_l_34fa;
	case 13567ULL: goto x86_l_34ff;
	case 13570ULL: goto x86_l_3502;
	case 13572ULL: goto x86_l_3504;
	case 13574ULL: goto x86_l_3506;
	case 13579ULL: goto x86_l_350b;
	case 13582ULL: goto x86_l_350e;
	case 13584ULL: goto x86_l_3510;
	case 13589ULL: goto x86_l_3515;
	case 13592ULL: goto x86_l_3518;
	case 13594ULL: goto x86_l_351a;
	case 13596ULL: goto x86_l_351c;
	case 13604ULL: goto x86_l_3524;
	case 13607ULL: goto x86_l_3527;
	case 13609ULL: goto x86_l_3529;
	case 13614ULL: goto x86_l_352e;
	case 13617ULL: goto x86_l_3531;
	case 13619ULL: goto x86_l_3533;
	case 13621ULL: goto x86_l_3535;
	case 13626ULL: goto x86_l_353a;
	case 13629ULL: goto x86_l_353d;
	case 13631ULL: goto x86_l_353f;
	case 13636ULL: goto x86_l_3544;
	case 13639ULL: goto x86_l_3547;
	case 13641ULL: goto x86_l_3549;
	case 13643ULL: goto x86_l_354b;
	case 13648ULL: goto x86_l_3550;
	case 13653ULL: goto x86_l_3555;
	case 13658ULL: goto x86_l_355a;
	case 13661ULL: goto x86_l_355d;
	case 13663ULL: goto x86_l_355f;
	case 13665ULL: goto x86_l_3561;
	case 13670ULL: goto x86_l_3566;
	case 13672ULL: goto x86_l_3568;
	case 13677ULL: goto x86_l_356d;
	case 13681ULL: goto x86_l_3571;
	case 13686ULL: goto x86_l_3576;
	case 13688ULL: goto x86_l_3578;
	case 13691ULL: goto x86_l_357b;
	case 13701ULL: goto x86_l_3585;
	case 13707ULL: goto x86_l_358b;
	case 13714ULL: goto x86_l_3592;
	case 13717ULL: goto x86_l_3595;
	case 13725ULL: goto x86_l_359d;
	case 13728ULL: goto x86_l_35a0;
	case 13732ULL: goto x86_l_35a4;
	case 13741ULL: goto x86_l_35ad;
	case 13743ULL: goto x86_l_35af;
	case 13749ULL: goto x86_l_35b5;
	case 13752ULL: goto x86_l_35b8;
	case 13754ULL: goto x86_l_35ba;
	case 13757ULL: goto x86_l_35bd;
	case 13762ULL: goto x86_l_35c2;
	case 13767ULL: goto x86_l_35c7;
	case 13771ULL: goto x86_l_35cb;
	case 13776ULL: goto x86_l_35d0;
	case 13778ULL: goto x86_l_35d2;
	case 13780ULL: goto x86_l_35d4;
	case 13786ULL: goto x86_l_35da;
	case 13796ULL: goto x86_l_35e4;
	case 13802ULL: goto x86_l_35ea;
	case 13810ULL: goto x86_l_35f2;
	case 13814ULL: goto x86_l_35f6;
	case 13818ULL: goto x86_l_35fa;
	case 13828ULL: goto x86_l_3604;
	case 13830ULL: goto x86_l_3606;
	case 13833ULL: goto x86_l_3609;
	case 13838ULL: goto x86_l_360e;
	case 13843ULL: goto x86_l_3613;
	case 13847ULL: goto x86_l_3617;
	case 13852ULL: goto x86_l_361c;
	case 13854ULL: goto x86_l_361e;
	case 13856ULL: goto x86_l_3620;
	case 13862ULL: goto x86_l_3626;
	case 13872ULL: goto x86_l_3630;
	case 13878ULL: goto x86_l_3636;
	case 13886ULL: goto x86_l_363e;
	case 13890ULL: goto x86_l_3642;
	case 13894ULL: goto x86_l_3646;
	case 13904ULL: goto x86_l_3650;
	case 13906ULL: goto x86_l_3652;
	case 13909ULL: goto x86_l_3655;
	case 13914ULL: goto x86_l_365a;
	case 13919ULL: goto x86_l_365f;
	case 13923ULL: goto x86_l_3663;
	case 13928ULL: goto x86_l_3668;
	case 13930ULL: goto x86_l_366a;
	case 13932ULL: goto x86_l_366c;
	case 13938ULL: goto x86_l_3672;
	case 13948ULL: goto x86_l_367c;
	case 13954ULL: goto x86_l_3682;
	case 13962ULL: goto x86_l_368a;
	case 13966ULL: goto x86_l_368e;
	case 13970ULL: goto x86_l_3692;
	case 13980ULL: goto x86_l_369c;
	case 13982ULL: goto x86_l_369e;
	case 13985ULL: goto x86_l_36a1;
	case 13990ULL: goto x86_l_36a6;
	case 13995ULL: goto x86_l_36ab;
	case 13999ULL: goto x86_l_36af;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2f6a:
	/* 0x2f6a: cmp    WORD PTR [r12+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_2f74:
	/* 0x2f74: je     2f96 <generic_sleepable_preload+0x2f96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f96;
	}
x86_l_2f76:
	/* 0x2f76: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2f79:
	/* 0x2f79: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f7e:
	/* 0x2f7e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2f83:
	/* 0x2f83: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f87:
	/* 0x2f87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f8c:
	/* 0x2f8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f8e:
	/* 0x2f8e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f90:
	/* 0x2f90: js     354b <generic_sleepable_preload+0x354b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_354b;
	}
x86_l_2f96:
	/* 0x2f96: cmp    WORD PTR [r12+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_2fa0:
	/* 0x2fa0: je     3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15315ULL;
	}
x86_l_2fa6:
	/* 0x2fa6: mov    ecx,DWORD PTR [r12+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2fae:
	/* 0x2fae: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2fb2:
	/* 0x2fb2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fb6:
	/* 0x2fb6: cmp    WORD PTR [r12+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_2fc0:
	/* 0x2fc0: je     2fe2 <generic_sleepable_preload+0x2fe2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fe2;
	}
x86_l_2fc2:
	/* 0x2fc2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2fc5:
	/* 0x2fc5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2fca:
	/* 0x2fca: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2fcf:
	/* 0x2fcf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fd3:
	/* 0x2fd3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fd8:
	/* 0x2fd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fda:
	/* 0x2fda: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fdc:
	/* 0x2fdc: js     3b87 <generic_sleepable_preload+0x3b87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15239ULL;
	}
x86_l_2fe2:
	/* 0x2fe2: cmp    WORD PTR [r12+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_2fec:
	/* 0x2fec: je     3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15315ULL;
	}
x86_l_2ff2:
	/* 0x2ff2: mov    ecx,DWORD PTR [r12+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_2ffa:
	/* 0x2ffa: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2ffe:
	/* 0x2ffe: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3002:
	/* 0x3002: cmp    WORD PTR [r12+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_300c:
	/* 0x300c: je     302e <generic_sleepable_preload+0x302e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_302e;
	}
x86_l_300e:
	/* 0x300e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3011:
	/* 0x3011: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3016:
	/* 0x3016: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_301b:
	/* 0x301b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_301f:
	/* 0x301f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3024:
	/* 0x3024: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3026:
	/* 0x3026: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3028:
	/* 0x3028: js     3b98 <generic_sleepable_preload+0x3b98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15256ULL;
	}
x86_l_302e:
	/* 0x302e: cmp    WORD PTR [r12+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_3038:
	/* 0x3038: je     3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15315ULL;
	}
x86_l_303e:
	/* 0x303e: mov    ecx,DWORD PTR [r12+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_3046:
	/* 0x3046: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_304a:
	/* 0x304a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_304e:
	/* 0x304e: cmp    WORD PTR [r12+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_3058:
	/* 0x3058: je     307a <generic_sleepable_preload+0x307a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_307a;
	}
x86_l_305a:
	/* 0x305a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_305d:
	/* 0x305d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3062:
	/* 0x3062: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3067:
	/* 0x3067: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_306b:
	/* 0x306b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3070:
	/* 0x3070: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3072:
	/* 0x3072: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3074:
	/* 0x3074: js     3ba9 <generic_sleepable_preload+0x3ba9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15273ULL;
	}
x86_l_307a:
	/* 0x307a: cmp    WORD PTR [r12+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_3084:
	/* 0x3084: je     3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15315ULL;
	}
x86_l_308a:
	/* 0x308a: mov    ecx,DWORD PTR [r12+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_3092:
	/* 0x3092: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3096:
	/* 0x3096: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_309a:
	/* 0x309a: cmp    WORD PTR [r12+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_30a4:
	/* 0x30a4: je     30c6 <generic_sleepable_preload+0x30c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30c6;
	}
x86_l_30a6:
	/* 0x30a6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_30a9:
	/* 0x30a9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_30ae:
	/* 0x30ae: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_30b3:
	/* 0x30b3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30b7:
	/* 0x30b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30bc:
	/* 0x30bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30be:
	/* 0x30be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30c0:
	/* 0x30c0: js     3bba <generic_sleepable_preload+0x3bba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15290ULL;
	}
x86_l_30c6:
	/* 0x30c6: cmp    WORD PTR [r12+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_30d0:
	/* 0x30d0: je     3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15315ULL;
	}
x86_l_30d6:
	/* 0x30d6: mov    ecx,DWORD PTR [r12+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_30de:
	/* 0x30de: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_30e2:
	/* 0x30e2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30e6:
	/* 0x30e6: cmp    WORD PTR [r12+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_30f0:
	/* 0x30f0: je     3112 <generic_sleepable_preload+0x3112> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3112;
	}
x86_l_30f2:
	/* 0x30f2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_30f5:
	/* 0x30f5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_30fa:
	/* 0x30fa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_30ff:
	/* 0x30ff: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3103:
	/* 0x3103: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3108:
	/* 0x3108: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_310a:
	/* 0x310a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_310c:
	/* 0x310c: js     3bcb <generic_sleepable_preload+0x3bcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15307ULL;
	}
x86_l_3112:
	/* 0x3112: cmp    WORD PTR [r12+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_311c:
	/* 0x311c: je     3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15315ULL;
	}
x86_l_3122:
	/* 0x3122: mov    ecx,DWORD PTR [r12+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_312a:
	/* 0x312a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_312e:
	/* 0x312e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3132:
	/* 0x3132: cmp    WORD PTR [r12+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_313c:
	/* 0x313c: je     315e <generic_sleepable_preload+0x315e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_315e;
	}
x86_l_313e:
	/* 0x313e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3141:
	/* 0x3141: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3146:
	/* 0x3146: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_314b:
	/* 0x314b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_314f:
	/* 0x314f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3154:
	/* 0x3154: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3156:
	/* 0x3156: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3158:
	/* 0x3158: js     5c04 <generic_sleepable_preload+0x5c04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23556ULL;
	}
x86_l_315e:
	/* 0x315e: cmp    WORD PTR [r12+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_3168:
	/* 0x3168: je     3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15315ULL;
	}
x86_l_316e:
	/* 0x316e: mov    ecx,DWORD PTR [r12+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3176:
	/* 0x3176: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_317a:
	/* 0x317a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_317e:
	/* 0x317e: cmp    WORD PTR [r12+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3188:
	/* 0x3188: je     31aa <generic_sleepable_preload+0x31aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31aa;
	}
x86_l_318a:
	/* 0x318a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_318d:
	/* 0x318d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3192:
	/* 0x3192: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3197:
	/* 0x3197: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_319b:
	/* 0x319b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31a0:
	/* 0x31a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31a2:
	/* 0x31a2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31a4:
	/* 0x31a4: js     5cfe <generic_sleepable_preload+0x5cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23806ULL;
	}
x86_l_31aa:
	/* 0x31aa: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31af:
	/* 0x31af: cmp    WORD PTR [r12+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_31b9:
	/* 0x31b9: je     3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15315ULL;
	}
x86_l_31bf:
	/* 0x31bf: mov    ecx,DWORD PTR [r12+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_31c7:
	/* 0x31c7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_31cb:
	/* 0x31cb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31cf:
	/* 0x31cf: cmp    WORD PTR [r12+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_31d9:
	/* 0x31d9: je     3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15315ULL;
	}
x86_l_31df:
	/* 0x31df: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_31e2:
	/* 0x31e2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_31e7:
	/* 0x31e7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_31ec:
	/* 0x31ec: jmp    34c6 <generic_sleepable_preload+0x34c6> */
	goto x86_l_34c6;
x86_l_31f1:
	/* 0x31f1: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_31f4:
	/* 0x31f4: je     3216 <generic_sleepable_preload+0x3216> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3216;
	}
x86_l_31f6:
	/* 0x31f6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_31f9:
	/* 0x31f9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_31fe:
	/* 0x31fe: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3203:
	/* 0x3203: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3207:
	/* 0x3207: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_320c:
	/* 0x320c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_320e:
	/* 0x320e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3210:
	/* 0x3210: js     34e3 <generic_sleepable_preload+0x34e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_34e3;
	}
x86_l_3216:
	/* 0x3216: cmp    WORD PTR [r12+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_3220:
	/* 0x3220: je     3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15315ULL;
	}
x86_l_3226:
	/* 0x3226: mov    ecx,DWORD PTR [r12+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_322e:
	/* 0x322e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3232:
	/* 0x3232: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3236:
	/* 0x3236: cmp    WORD PTR [r12+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_3240:
	/* 0x3240: je     3262 <generic_sleepable_preload+0x3262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3262;
	}
x86_l_3242:
	/* 0x3242: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3245:
	/* 0x3245: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_324a:
	/* 0x324a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_324f:
	/* 0x324f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3253:
	/* 0x3253: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3258:
	/* 0x3258: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_325a:
	/* 0x325a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_325c:
	/* 0x325c: js     354b <generic_sleepable_preload+0x354b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_354b;
	}
x86_l_3262:
	/* 0x3262: cmp    WORD PTR [r12+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_326c:
	/* 0x326c: je     3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15315ULL;
	}
x86_l_3272:
	/* 0x3272: mov    ecx,DWORD PTR [r12+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_327a:
	/* 0x327a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_327e:
	/* 0x327e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3282:
	/* 0x3282: cmp    WORD PTR [r12+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_328c:
	/* 0x328c: je     32ae <generic_sleepable_preload+0x32ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32ae;
	}
x86_l_328e:
	/* 0x328e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3291:
	/* 0x3291: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3296:
	/* 0x3296: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_329b:
	/* 0x329b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_329f:
	/* 0x329f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32a4:
	/* 0x32a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32a6:
	/* 0x32a6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32a8:
	/* 0x32a8: js     3b87 <generic_sleepable_preload+0x3b87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15239ULL;
	}
x86_l_32ae:
	/* 0x32ae: cmp    WORD PTR [r12+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_32b8:
	/* 0x32b8: je     3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15315ULL;
	}
x86_l_32be:
	/* 0x32be: mov    ecx,DWORD PTR [r12+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_32c6:
	/* 0x32c6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_32ca:
	/* 0x32ca: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32ce:
	/* 0x32ce: cmp    WORD PTR [r12+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_32d8:
	/* 0x32d8: je     32fa <generic_sleepable_preload+0x32fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32fa;
	}
x86_l_32da:
	/* 0x32da: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_32dd:
	/* 0x32dd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_32e2:
	/* 0x32e2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_32e7:
	/* 0x32e7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32eb:
	/* 0x32eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32f0:
	/* 0x32f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32f2:
	/* 0x32f2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32f4:
	/* 0x32f4: js     3b98 <generic_sleepable_preload+0x3b98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15256ULL;
	}
x86_l_32fa:
	/* 0x32fa: cmp    WORD PTR [r12+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_3304:
	/* 0x3304: je     3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15315ULL;
	}
x86_l_330a:
	/* 0x330a: mov    ecx,DWORD PTR [r12+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_3312:
	/* 0x3312: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3316:
	/* 0x3316: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_331a:
	/* 0x331a: cmp    WORD PTR [r12+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_3324:
	/* 0x3324: je     3346 <generic_sleepable_preload+0x3346> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3346;
	}
x86_l_3326:
	/* 0x3326: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3329:
	/* 0x3329: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_332e:
	/* 0x332e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3333:
	/* 0x3333: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3337:
	/* 0x3337: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_333c:
	/* 0x333c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_333e:
	/* 0x333e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3340:
	/* 0x3340: js     3ba9 <generic_sleepable_preload+0x3ba9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15273ULL;
	}
x86_l_3346:
	/* 0x3346: cmp    WORD PTR [r12+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_3350:
	/* 0x3350: je     3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15315ULL;
	}
x86_l_3356:
	/* 0x3356: mov    ecx,DWORD PTR [r12+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_335e:
	/* 0x335e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3362:
	/* 0x3362: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3366:
	/* 0x3366: cmp    WORD PTR [r12+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_3370:
	/* 0x3370: je     3392 <generic_sleepable_preload+0x3392> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3392;
	}
x86_l_3372:
	/* 0x3372: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3375:
	/* 0x3375: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_337a:
	/* 0x337a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_337f:
	/* 0x337f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3383:
	/* 0x3383: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3388:
	/* 0x3388: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_338a:
	/* 0x338a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_338c:
	/* 0x338c: js     3bba <generic_sleepable_preload+0x3bba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15290ULL;
	}
x86_l_3392:
	/* 0x3392: cmp    WORD PTR [r12+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_339c:
	/* 0x339c: je     3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15315ULL;
	}
x86_l_33a2:
	/* 0x33a2: mov    ecx,DWORD PTR [r12+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_33aa:
	/* 0x33aa: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_33ae:
	/* 0x33ae: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33b2:
	/* 0x33b2: cmp    WORD PTR [r12+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_33bc:
	/* 0x33bc: je     33de <generic_sleepable_preload+0x33de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33de;
	}
x86_l_33be:
	/* 0x33be: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_33c1:
	/* 0x33c1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_33c6:
	/* 0x33c6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_33cb:
	/* 0x33cb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33cf:
	/* 0x33cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33d4:
	/* 0x33d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33d6:
	/* 0x33d6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33d8:
	/* 0x33d8: js     3bcb <generic_sleepable_preload+0x3bcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15307ULL;
	}
x86_l_33de:
	/* 0x33de: cmp    WORD PTR [r12+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_33e8:
	/* 0x33e8: je     3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15315ULL;
	}
x86_l_33ee:
	/* 0x33ee: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_33f1:
	/* 0x33f1: mov    ecx,DWORD PTR [r12+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_33f9:
	/* 0x33f9: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_33fd:
	/* 0x33fd: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3401:
	/* 0x3401: cmp    WORD PTR [r12+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_340b:
	/* 0x340b: je     342d <generic_sleepable_preload+0x342d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_342d;
	}
x86_l_340d:
	/* 0x340d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3410:
	/* 0x3410: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3415:
	/* 0x3415: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_341a:
	/* 0x341a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_341e:
	/* 0x341e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3423:
	/* 0x3423: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3425:
	/* 0x3425: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3427:
	/* 0x3427: js     5c82 <generic_sleepable_preload+0x5c82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23682ULL;
	}
x86_l_342d:
	/* 0x342d: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3432:
	/* 0x3432: cmp    WORD PTR [r12+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_343c:
	/* 0x343c: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_343f:
	/* 0x343f: je     3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15315ULL;
	}
x86_l_3445:
	/* 0x3445: mov    ecx,DWORD PTR [r12+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_344d:
	/* 0x344d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3451:
	/* 0x3451: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3455:
	/* 0x3455: cmp    WORD PTR [r12+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_345f:
	/* 0x345f: je     3481 <generic_sleepable_preload+0x3481> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3481;
	}
x86_l_3461:
	/* 0x3461: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3464:
	/* 0x3464: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3469:
	/* 0x3469: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_346e:
	/* 0x346e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3472:
	/* 0x3472: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3477:
	/* 0x3477: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3479:
	/* 0x3479: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_347b:
	/* 0x347b: js     5d9a <generic_sleepable_preload+0x5d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23962ULL;
	}
x86_l_3481:
	/* 0x3481: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3486:
	/* 0x3486: cmp    WORD PTR [r12+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_3490:
	/* 0x3490: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_3493:
	/* 0x3493: je     3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15315ULL;
	}
x86_l_3499:
	/* 0x3499: mov    ecx,DWORD PTR [r12+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_34a1:
	/* 0x34a1: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_34a5:
	/* 0x34a5: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34a9:
	/* 0x34a9: cmp    WORD PTR [r12+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_34b3:
	/* 0x34b3: je     3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15315ULL;
	}
x86_l_34b9:
	/* 0x34b9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_34bc:
	/* 0x34bc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_34c1:
	/* 0x34c1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_34c6:
	/* 0x34c6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34ca:
	/* 0x34ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34cf:
	/* 0x34cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34d1:
	/* 0x34d1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34d3:
	/* 0x34d3: jns    3bd3 <generic_sleepable_preload+0x3bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 15315ULL;
	}
x86_l_34d9:
	/* 0x34d9: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_34de:
	/* 0x34de: jmp    3bd0 <generic_sleepable_preload+0x3bd0> */
	return 15312ULL;
x86_l_34e3:
	/* 0x34e3: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_34e8:
	/* 0x34e8: jmp    3bd0 <generic_sleepable_preload+0x3bd0> */
	return 15312ULL;
x86_l_34ed:
	/* 0x34ed: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_34f5:
	/* 0x34f5: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_34f8:
	/* 0x34f8: je     355a <generic_sleepable_preload+0x355a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_355a;
	}
x86_l_34fa:
	/* 0x34fa: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34ff:
	/* 0x34ff: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3502:
	/* 0x3502: je     355a <generic_sleepable_preload+0x355a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_355a;
	}
x86_l_3504:
	/* 0x3504: jmp    356d <generic_sleepable_preload+0x356d> */
	goto x86_l_356d;
x86_l_3506:
	/* 0x3506: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_350b:
	/* 0x350b: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_350e:
	/* 0x350e: je     355a <generic_sleepable_preload+0x355a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_355a;
	}
x86_l_3510:
	/* 0x3510: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3515:
	/* 0x3515: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3518:
	/* 0x3518: je     355a <generic_sleepable_preload+0x355a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_355a;
	}
x86_l_351a:
	/* 0x351a: jmp    356d <generic_sleepable_preload+0x356d> */
	goto x86_l_356d;
x86_l_351c:
	/* 0x351c: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3524:
	/* 0x3524: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_3527:
	/* 0x3527: je     355a <generic_sleepable_preload+0x355a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_355a;
	}
x86_l_3529:
	/* 0x3529: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_352e:
	/* 0x352e: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_3531:
	/* 0x3531: je     355a <generic_sleepable_preload+0x355a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_355a;
	}
x86_l_3533:
	/* 0x3533: jmp    356d <generic_sleepable_preload+0x356d> */
	goto x86_l_356d;
x86_l_3535:
	/* 0x3535: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_353a:
	/* 0x353a: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_353d:
	/* 0x353d: je     355a <generic_sleepable_preload+0x355a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_355a;
	}
x86_l_353f:
	/* 0x353f: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3544:
	/* 0x3544: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_3547:
	/* 0x3547: je     355a <generic_sleepable_preload+0x355a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_355a;
	}
x86_l_3549:
	/* 0x3549: jmp    356d <generic_sleepable_preload+0x356d> */
	goto x86_l_356d;
x86_l_354b:
	/* 0x354b: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_3550:
	/* 0x3550: jmp    3bd0 <generic_sleepable_preload+0x3bd0> */
	return 15312ULL;
x86_l_3555:
	/* 0x3555: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_355a:
	/* 0x355a: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_355d:
	/* 0x355d: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_355f:
	/* 0x355f: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_3561:
	/* 0x3561: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_3566:
	/* 0x3566: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3568:
	/* 0x3568: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_356d:
	/* 0x356d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3571:
	/* 0x3571: mov    ebp,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3576:
	/* 0x3576: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3578:
	/* 0x3578: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_357b:
	/* 0x357b: cmp    WORD PTR [r12+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_3585:
	/* 0x3585: je     3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15454ULL;
	}
x86_l_358b:
	/* 0x358b: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_3592:
	/* 0x3592: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3595:
	/* 0x3595: mov    eax,DWORD PTR [r12+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_359d:
	/* 0x359d: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_35a0:
	/* 0x35a0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35a4:
	/* 0x35a4: movzx  eax,WORD PTR [r12+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_35ad:
	/* 0x35ad: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_35af:
	/* 0x35af: je     3881 <generic_sleepable_preload+0x3881> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14465ULL;
	}
x86_l_35b5:
	/* 0x35b5: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_35b8:
	/* 0x35b8: je     35da <generic_sleepable_preload+0x35da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35da;
	}
x86_l_35ba:
	/* 0x35ba: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_35bd:
	/* 0x35bd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_35c2:
	/* 0x35c2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_35c7:
	/* 0x35c7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35cb:
	/* 0x35cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35d0:
	/* 0x35d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35d2:
	/* 0x35d2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35d4:
	/* 0x35d4: js     3b73 <generic_sleepable_preload+0x3b73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15219ULL;
	}
x86_l_35da:
	/* 0x35da: cmp    WORD PTR [r12+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_35e4:
	/* 0x35e4: je     3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15454ULL;
	}
x86_l_35ea:
	/* 0x35ea: mov    ecx,DWORD PTR [r12+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_35f2:
	/* 0x35f2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_35f6:
	/* 0x35f6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35fa:
	/* 0x35fa: cmp    WORD PTR [r12+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_3604:
	/* 0x3604: je     3626 <generic_sleepable_preload+0x3626> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3626;
	}
x86_l_3606:
	/* 0x3606: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3609:
	/* 0x3609: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_360e:
	/* 0x360e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3613:
	/* 0x3613: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3617:
	/* 0x3617: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_361c:
	/* 0x361c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_361e:
	/* 0x361e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3620:
	/* 0x3620: js     3b7d <generic_sleepable_preload+0x3b7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15229ULL;
	}
x86_l_3626:
	/* 0x3626: cmp    WORD PTR [r12+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_3630:
	/* 0x3630: je     3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15454ULL;
	}
x86_l_3636:
	/* 0x3636: mov    ecx,DWORD PTR [r12+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_363e:
	/* 0x363e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3642:
	/* 0x3642: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3646:
	/* 0x3646: cmp    WORD PTR [r12+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_3650:
	/* 0x3650: je     3672 <generic_sleepable_preload+0x3672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3672;
	}
x86_l_3652:
	/* 0x3652: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3655:
	/* 0x3655: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_365a:
	/* 0x365a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_365f:
	/* 0x365f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3663:
	/* 0x3663: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3668:
	/* 0x3668: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_366a:
	/* 0x366a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_366c:
	/* 0x366c: js     3b8e <generic_sleepable_preload+0x3b8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15246ULL;
	}
x86_l_3672:
	/* 0x3672: cmp    WORD PTR [r12+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_367c:
	/* 0x367c: je     3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15454ULL;
	}
x86_l_3682:
	/* 0x3682: mov    ecx,DWORD PTR [r12+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_368a:
	/* 0x368a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_368e:
	/* 0x368e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3692:
	/* 0x3692: cmp    WORD PTR [r12+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_369c:
	/* 0x369c: je     36be <generic_sleepable_preload+0x36be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14014ULL;
	}
x86_l_369e:
	/* 0x369e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_36a1:
	/* 0x36a1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_36a6:
	/* 0x36a6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_36ab:
	/* 0x36ab: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36af:
	/* 0x36af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 14004ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14004ULL: goto x86_l_36b4;
	case 14006ULL: goto x86_l_36b6;
	case 14008ULL: goto x86_l_36b8;
	case 14014ULL: goto x86_l_36be;
	case 14024ULL: goto x86_l_36c8;
	case 14030ULL: goto x86_l_36ce;
	case 14038ULL: goto x86_l_36d6;
	case 14042ULL: goto x86_l_36da;
	case 14046ULL: goto x86_l_36de;
	case 14056ULL: goto x86_l_36e8;
	case 14058ULL: goto x86_l_36ea;
	case 14061ULL: goto x86_l_36ed;
	case 14066ULL: goto x86_l_36f2;
	case 14071ULL: goto x86_l_36f7;
	case 14075ULL: goto x86_l_36fb;
	case 14080ULL: goto x86_l_3700;
	case 14082ULL: goto x86_l_3702;
	case 14084ULL: goto x86_l_3704;
	case 14090ULL: goto x86_l_370a;
	case 14100ULL: goto x86_l_3714;
	case 14106ULL: goto x86_l_371a;
	case 14114ULL: goto x86_l_3722;
	case 14118ULL: goto x86_l_3726;
	case 14122ULL: goto x86_l_372a;
	case 14132ULL: goto x86_l_3734;
	case 14134ULL: goto x86_l_3736;
	case 14137ULL: goto x86_l_3739;
	case 14142ULL: goto x86_l_373e;
	case 14147ULL: goto x86_l_3743;
	case 14151ULL: goto x86_l_3747;
	case 14156ULL: goto x86_l_374c;
	case 14158ULL: goto x86_l_374e;
	case 14160ULL: goto x86_l_3750;
	case 14166ULL: goto x86_l_3756;
	case 14176ULL: goto x86_l_3760;
	case 14182ULL: goto x86_l_3766;
	case 14190ULL: goto x86_l_376e;
	case 14194ULL: goto x86_l_3772;
	case 14198ULL: goto x86_l_3776;
	case 14208ULL: goto x86_l_3780;
	case 14210ULL: goto x86_l_3782;
	case 14213ULL: goto x86_l_3785;
	case 14218ULL: goto x86_l_378a;
	case 14223ULL: goto x86_l_378f;
	case 14227ULL: goto x86_l_3793;
	case 14232ULL: goto x86_l_3798;
	case 14234ULL: goto x86_l_379a;
	case 14236ULL: goto x86_l_379c;
	case 14242ULL: goto x86_l_37a2;
	case 14252ULL: goto x86_l_37ac;
	case 14258ULL: goto x86_l_37b2;
	case 14266ULL: goto x86_l_37ba;
	case 14270ULL: goto x86_l_37be;
	case 14274ULL: goto x86_l_37c2;
	case 14284ULL: goto x86_l_37cc;
	case 14286ULL: goto x86_l_37ce;
	case 14289ULL: goto x86_l_37d1;
	case 14294ULL: goto x86_l_37d6;
	case 14299ULL: goto x86_l_37db;
	case 14303ULL: goto x86_l_37df;
	case 14308ULL: goto x86_l_37e4;
	case 14310ULL: goto x86_l_37e6;
	case 14312ULL: goto x86_l_37e8;
	case 14318ULL: goto x86_l_37ee;
	case 14328ULL: goto x86_l_37f8;
	case 14334ULL: goto x86_l_37fe;
	case 14342ULL: goto x86_l_3806;
	case 14346ULL: goto x86_l_380a;
	case 14350ULL: goto x86_l_380e;
	case 14360ULL: goto x86_l_3818;
	case 14362ULL: goto x86_l_381a;
	case 14365ULL: goto x86_l_381d;
	case 14370ULL: goto x86_l_3822;
	case 14375ULL: goto x86_l_3827;
	case 14379ULL: goto x86_l_382b;
	case 14384ULL: goto x86_l_3830;
	case 14386ULL: goto x86_l_3832;
	case 14388ULL: goto x86_l_3834;
	case 14394ULL: goto x86_l_383a;
	case 14399ULL: goto x86_l_383f;
	case 14409ULL: goto x86_l_3849;
	case 14415ULL: goto x86_l_384f;
	case 14423ULL: goto x86_l_3857;
	case 14427ULL: goto x86_l_385b;
	case 14431ULL: goto x86_l_385f;
	case 14441ULL: goto x86_l_3869;
	case 14447ULL: goto x86_l_386f;
	case 14450ULL: goto x86_l_3872;
	case 14455ULL: goto x86_l_3877;
	case 14460ULL: goto x86_l_387c;
	case 14465ULL: goto x86_l_3881;
	case 14468ULL: goto x86_l_3884;
	case 14470ULL: goto x86_l_3886;
	case 14473ULL: goto x86_l_3889;
	case 14478ULL: goto x86_l_388e;
	case 14483ULL: goto x86_l_3893;
	case 14487ULL: goto x86_l_3897;
	case 14492ULL: goto x86_l_389c;
	case 14494ULL: goto x86_l_389e;
	case 14496ULL: goto x86_l_38a0;
	case 14502ULL: goto x86_l_38a6;
	case 14512ULL: goto x86_l_38b0;
	case 14518ULL: goto x86_l_38b6;
	case 14526ULL: goto x86_l_38be;
	case 14530ULL: goto x86_l_38c2;
	case 14534ULL: goto x86_l_38c6;
	case 14544ULL: goto x86_l_38d0;
	case 14546ULL: goto x86_l_38d2;
	case 14549ULL: goto x86_l_38d5;
	case 14554ULL: goto x86_l_38da;
	case 14559ULL: goto x86_l_38df;
	case 14563ULL: goto x86_l_38e3;
	case 14568ULL: goto x86_l_38e8;
	case 14570ULL: goto x86_l_38ea;
	case 14572ULL: goto x86_l_38ec;
	case 14578ULL: goto x86_l_38f2;
	case 14588ULL: goto x86_l_38fc;
	case 14594ULL: goto x86_l_3902;
	case 14602ULL: goto x86_l_390a;
	case 14606ULL: goto x86_l_390e;
	case 14610ULL: goto x86_l_3912;
	case 14620ULL: goto x86_l_391c;
	case 14622ULL: goto x86_l_391e;
	case 14625ULL: goto x86_l_3921;
	case 14630ULL: goto x86_l_3926;
	case 14635ULL: goto x86_l_392b;
	case 14639ULL: goto x86_l_392f;
	case 14644ULL: goto x86_l_3934;
	case 14646ULL: goto x86_l_3936;
	case 14648ULL: goto x86_l_3938;
	case 14654ULL: goto x86_l_393e;
	case 14664ULL: goto x86_l_3948;
	case 14670ULL: goto x86_l_394e;
	case 14678ULL: goto x86_l_3956;
	case 14682ULL: goto x86_l_395a;
	case 14686ULL: goto x86_l_395e;
	case 14696ULL: goto x86_l_3968;
	case 14698ULL: goto x86_l_396a;
	case 14701ULL: goto x86_l_396d;
	case 14706ULL: goto x86_l_3972;
	case 14711ULL: goto x86_l_3977;
	case 14715ULL: goto x86_l_397b;
	case 14720ULL: goto x86_l_3980;
	case 14722ULL: goto x86_l_3982;
	case 14724ULL: goto x86_l_3984;
	case 14730ULL: goto x86_l_398a;
	case 14740ULL: goto x86_l_3994;
	case 14746ULL: goto x86_l_399a;
	case 14754ULL: goto x86_l_39a2;
	case 14758ULL: goto x86_l_39a6;
	case 14762ULL: goto x86_l_39aa;
	case 14772ULL: goto x86_l_39b4;
	case 14774ULL: goto x86_l_39b6;
	case 14777ULL: goto x86_l_39b9;
	case 14782ULL: goto x86_l_39be;
	case 14787ULL: goto x86_l_39c3;
	case 14791ULL: goto x86_l_39c7;
	case 14796ULL: goto x86_l_39cc;
	case 14798ULL: goto x86_l_39ce;
	case 14800ULL: goto x86_l_39d0;
	case 14806ULL: goto x86_l_39d6;
	case 14816ULL: goto x86_l_39e0;
	case 14822ULL: goto x86_l_39e6;
	case 14830ULL: goto x86_l_39ee;
	case 14834ULL: goto x86_l_39f2;
	case 14838ULL: goto x86_l_39f6;
	case 14848ULL: goto x86_l_3a00;
	case 14850ULL: goto x86_l_3a02;
	case 14853ULL: goto x86_l_3a05;
	case 14858ULL: goto x86_l_3a0a;
	case 14863ULL: goto x86_l_3a0f;
	case 14867ULL: goto x86_l_3a13;
	case 14872ULL: goto x86_l_3a18;
	case 14874ULL: goto x86_l_3a1a;
	case 14876ULL: goto x86_l_3a1c;
	case 14882ULL: goto x86_l_3a22;
	case 14892ULL: goto x86_l_3a2c;
	case 14898ULL: goto x86_l_3a32;
	case 14906ULL: goto x86_l_3a3a;
	case 14910ULL: goto x86_l_3a3e;
	case 14914ULL: goto x86_l_3a42;
	case 14924ULL: goto x86_l_3a4c;
	case 14926ULL: goto x86_l_3a4e;
	case 14929ULL: goto x86_l_3a51;
	case 14934ULL: goto x86_l_3a56;
	case 14939ULL: goto x86_l_3a5b;
	case 14943ULL: goto x86_l_3a5f;
	case 14948ULL: goto x86_l_3a64;
	case 14950ULL: goto x86_l_3a66;
	case 14952ULL: goto x86_l_3a68;
	case 14958ULL: goto x86_l_3a6e;
	case 14968ULL: goto x86_l_3a78;
	case 14974ULL: goto x86_l_3a7e;
	case 14977ULL: goto x86_l_3a81;
	case 14985ULL: goto x86_l_3a89;
	case 14989ULL: goto x86_l_3a8d;
	case 14993ULL: goto x86_l_3a91;
	case 15003ULL: goto x86_l_3a9b;
	case 15005ULL: goto x86_l_3a9d;
	case 15008ULL: goto x86_l_3aa0;
	case 15013ULL: goto x86_l_3aa5;
	case 15018ULL: goto x86_l_3aaa;
	case 15022ULL: goto x86_l_3aae;
	case 15027ULL: goto x86_l_3ab3;
	case 15029ULL: goto x86_l_3ab5;
	case 15031ULL: goto x86_l_3ab7;
	case 15037ULL: goto x86_l_3abd;
	case 15042ULL: goto x86_l_3ac2;
	case 15052ULL: goto x86_l_3acc;
	case 15055ULL: goto x86_l_3acf;
	case 15061ULL: goto x86_l_3ad5;
	case 15069ULL: goto x86_l_3add;
	case 15073ULL: goto x86_l_3ae1;
	case 15077ULL: goto x86_l_3ae5;
	case 15087ULL: goto x86_l_3aef;
	case 15089ULL: goto x86_l_3af1;
	case 15092ULL: goto x86_l_3af4;
	case 15097ULL: goto x86_l_3af9;
	case 15102ULL: goto x86_l_3afe;
	case 15106ULL: goto x86_l_3b02;
	case 15111ULL: goto x86_l_3b07;
	case 15113ULL: goto x86_l_3b09;
	case 15115ULL: goto x86_l_3b0b;
	case 15121ULL: goto x86_l_3b11;
	case 15126ULL: goto x86_l_3b16;
	case 15136ULL: goto x86_l_3b20;
	case 15139ULL: goto x86_l_3b23;
	case 15145ULL: goto x86_l_3b29;
	case 15153ULL: goto x86_l_3b31;
	case 15157ULL: goto x86_l_3b35;
	case 15161ULL: goto x86_l_3b39;
	case 15171ULL: goto x86_l_3b43;
	case 15177ULL: goto x86_l_3b49;
	case 15180ULL: goto x86_l_3b4c;
	case 15185ULL: goto x86_l_3b51;
	case 15190ULL: goto x86_l_3b56;
	case 15194ULL: goto x86_l_3b5a;
	case 15199ULL: goto x86_l_3b5f;
	case 15201ULL: goto x86_l_3b61;
	case 15203ULL: goto x86_l_3b63;
	case 15209ULL: goto x86_l_3b69;
	case 15214ULL: goto x86_l_3b6e;
	case 15219ULL: goto x86_l_3b73;
	case 15224ULL: goto x86_l_3b78;
	case 15229ULL: goto x86_l_3b7d;
	case 15234ULL: goto x86_l_3b82;
	case 15239ULL: goto x86_l_3b87;
	case 15244ULL: goto x86_l_3b8c;
	case 15246ULL: goto x86_l_3b8e;
	case 15251ULL: goto x86_l_3b93;
	case 15256ULL: goto x86_l_3b98;
	case 15261ULL: goto x86_l_3b9d;
	case 15263ULL: goto x86_l_3b9f;
	case 15268ULL: goto x86_l_3ba4;
	case 15273ULL: goto x86_l_3ba9;
	case 15278ULL: goto x86_l_3bae;
	case 15280ULL: goto x86_l_3bb0;
	case 15285ULL: goto x86_l_3bb5;
	case 15290ULL: goto x86_l_3bba;
	case 15295ULL: goto x86_l_3bbf;
	case 15297ULL: goto x86_l_3bc1;
	case 15302ULL: goto x86_l_3bc6;
	case 15307ULL: goto x86_l_3bcb;
	case 15312ULL: goto x86_l_3bd0;
	case 15315ULL: goto x86_l_3bd3;
	case 15320ULL: goto x86_l_3bd8;
	case 15323ULL: goto x86_l_3bdb;
	case 15328ULL: goto x86_l_3be0;
	case 15333ULL: goto x86_l_3be5;
	case 15338ULL: goto x86_l_3bea;
	case 15341ULL: goto x86_l_3bed;
	case 15343ULL: goto x86_l_3bef;
	case 15346ULL: goto x86_l_3bf2;
	case 15352ULL: goto x86_l_3bf8;
	case 15355ULL: goto x86_l_3bfb;
	case 15359ULL: goto x86_l_3bff;
	case 15364ULL: goto x86_l_3c04;
	case 15366ULL: goto x86_l_3c06;
	case 15371ULL: goto x86_l_3c0b;
	case 15379ULL: goto x86_l_3c13;
	case 15386ULL: goto x86_l_3c1a;
	case 15391ULL: goto x86_l_3c1f;
	case 15396ULL: goto x86_l_3c24;
	case 15398ULL: goto x86_l_3c26;
	case 15401ULL: goto x86_l_3c29;
	case 15407ULL: goto x86_l_3c2f;
	case 15410ULL: goto x86_l_3c32;
	case 15417ULL: goto x86_l_3c39;
	case 15419ULL: goto x86_l_3c3b;
	case 15424ULL: goto x86_l_3c40;
	case 15429ULL: goto x86_l_3c45;
	case 15432ULL: goto x86_l_3c48;
	case 15435ULL: goto x86_l_3c4b;
	case 15437ULL: goto x86_l_3c4d;
	case 15439ULL: goto x86_l_3c4f;
	case 15444ULL: goto x86_l_3c54;
	case 15446ULL: goto x86_l_3c56;
	case 15451ULL: goto x86_l_3c5b;
	case 15454ULL: goto x86_l_3c5e;
	case 15457ULL: goto x86_l_3c61;
	case 15463ULL: goto x86_l_3c67;
	case 15466ULL: goto x86_l_3c6a;
	case 15470ULL: goto x86_l_3c6e;
	case 15475ULL: goto x86_l_3c73;
	case 15477ULL: goto x86_l_3c75;
	case 15482ULL: goto x86_l_3c7a;
	case 15490ULL: goto x86_l_3c82;
	case 15497ULL: goto x86_l_3c89;
	case 15502ULL: goto x86_l_3c8e;
	case 15507ULL: goto x86_l_3c93;
	case 15509ULL: goto x86_l_3c95;
	case 15512ULL: goto x86_l_3c98;
	case 15514ULL: goto x86_l_3c9a;
	case 15517ULL: goto x86_l_3c9d;
	case 15524ULL: goto x86_l_3ca4;
	case 15526ULL: goto x86_l_3ca6;
	case 15531ULL: goto x86_l_3cab;
	case 15536ULL: goto x86_l_3cb0;
	case 15539ULL: goto x86_l_3cb3;
	case 15542ULL: goto x86_l_3cb6;
	case 15544ULL: goto x86_l_3cb8;
	case 15546ULL: goto x86_l_3cba;
	case 15551ULL: goto x86_l_3cbf;
	case 15554ULL: goto x86_l_3cc2;
	case 15557ULL: goto x86_l_3cc5;
	case 15562ULL: goto x86_l_3cca;
	case 15564ULL: goto x86_l_3ccc;
	case 15567ULL: goto x86_l_3ccf;
	case 15569ULL: goto x86_l_3cd1;
	case 15572ULL: goto x86_l_3cd4;
	case 15574ULL: goto x86_l_3cd6;
	case 15577ULL: goto x86_l_3cd9;
	case 15581ULL: goto x86_l_3cdd;
	case 15586ULL: goto x86_l_3ce2;
	case 15589ULL: goto x86_l_3ce5;
	case 15591ULL: goto x86_l_3ce7;
	case 15594ULL: goto x86_l_3cea;
	case 15599ULL: goto x86_l_3cef;
	case 15601ULL: goto x86_l_3cf1;
	case 15604ULL: goto x86_l_3cf4;
	case 15606ULL: goto x86_l_3cf6;
	case 15611ULL: goto x86_l_3cfb;
	case 15614ULL: goto x86_l_3cfe;
	case 15616ULL: goto x86_l_3d00;
	case 15619ULL: goto x86_l_3d03;
	case 15624ULL: goto x86_l_3d08;
	case 15629ULL: goto x86_l_3d0d;
	case 15635ULL: goto x86_l_3d13;
	case 15637ULL: goto x86_l_3d15;
	case 15639ULL: goto x86_l_3d17;
	case 15644ULL: goto x86_l_3d1c;
	case 15647ULL: goto x86_l_3d1f;
	case 15653ULL: goto x86_l_3d25;
	case 15656ULL: goto x86_l_3d28;
	case 15662ULL: goto x86_l_3d2e;
	case 15665ULL: goto x86_l_3d31;
	case 15671ULL: goto x86_l_3d37;
	case 15674ULL: goto x86_l_3d3a;
	case 15680ULL: goto x86_l_3d40;
	case 15685ULL: goto x86_l_3d45;
	case 15690ULL: goto x86_l_3d4a;
	case 15699ULL: goto x86_l_3d53;
	case 15708ULL: goto x86_l_3d5c;
	case 15714ULL: goto x86_l_3d62;
	case 15716ULL: goto x86_l_3d64;
	case 15719ULL: goto x86_l_3d67;
	case 15721ULL: goto x86_l_3d69;
	case 15724ULL: goto x86_l_3d6c;
	case 15726ULL: goto x86_l_3d6e;
	case 15729ULL: goto x86_l_3d71;
	case 15735ULL: goto x86_l_3d77;
	case 15740ULL: goto x86_l_3d7c;
	case 15743ULL: goto x86_l_3d7f;
	case 15749ULL: goto x86_l_3d85;
	case 15754ULL: goto x86_l_3d8a;
	case 15757ULL: goto x86_l_3d8d;
	case 15763ULL: goto x86_l_3d93;
	case 15768ULL: goto x86_l_3d98;
	case 15771ULL: goto x86_l_3d9b;
	case 15777ULL: goto x86_l_3da1;
	case 15782ULL: goto x86_l_3da6;
	case 15785ULL: goto x86_l_3da9;
	case 15787ULL: goto x86_l_3dab;
	case 15790ULL: goto x86_l_3dae;
	default: return 0xffffffffffffffffULL;
	}
x86_l_36b4:
	/* 0x36b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36b6:
	/* 0x36b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36b8:
	/* 0x36b8: js     3b9f <generic_sleepable_preload+0x3b9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b9f;
	}
x86_l_36be:
	/* 0x36be: cmp    WORD PTR [r12+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_36c8:
	/* 0x36c8: je     3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5e;
	}
x86_l_36ce:
	/* 0x36ce: mov    ecx,DWORD PTR [r12+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_36d6:
	/* 0x36d6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_36da:
	/* 0x36da: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36de:
	/* 0x36de: cmp    WORD PTR [r12+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_36e8:
	/* 0x36e8: je     370a <generic_sleepable_preload+0x370a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_370a;
	}
x86_l_36ea:
	/* 0x36ea: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_36ed:
	/* 0x36ed: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_36f2:
	/* 0x36f2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_36f7:
	/* 0x36f7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36fb:
	/* 0x36fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3700:
	/* 0x3700: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3702:
	/* 0x3702: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3704:
	/* 0x3704: js     3bb0 <generic_sleepable_preload+0x3bb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3bb0;
	}
x86_l_370a:
	/* 0x370a: cmp    WORD PTR [r12+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_3714:
	/* 0x3714: je     3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5e;
	}
x86_l_371a:
	/* 0x371a: mov    ecx,DWORD PTR [r12+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_3722:
	/* 0x3722: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3726:
	/* 0x3726: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_372a:
	/* 0x372a: cmp    WORD PTR [r12+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_3734:
	/* 0x3734: je     3756 <generic_sleepable_preload+0x3756> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3756;
	}
x86_l_3736:
	/* 0x3736: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3739:
	/* 0x3739: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_373e:
	/* 0x373e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3743:
	/* 0x3743: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3747:
	/* 0x3747: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_374c:
	/* 0x374c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_374e:
	/* 0x374e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3750:
	/* 0x3750: js     3bc1 <generic_sleepable_preload+0x3bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3bc1;
	}
x86_l_3756:
	/* 0x3756: cmp    WORD PTR [r12+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_3760:
	/* 0x3760: je     3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5e;
	}
x86_l_3766:
	/* 0x3766: mov    ecx,DWORD PTR [r12+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_376e:
	/* 0x376e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3772:
	/* 0x3772: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3776:
	/* 0x3776: cmp    WORD PTR [r12+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_3780:
	/* 0x3780: je     37a2 <generic_sleepable_preload+0x37a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37a2;
	}
x86_l_3782:
	/* 0x3782: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3785:
	/* 0x3785: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_378a:
	/* 0x378a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_378f:
	/* 0x378f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3793:
	/* 0x3793: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3798:
	/* 0x3798: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_379a:
	/* 0x379a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_379c:
	/* 0x379c: js     3c56 <generic_sleepable_preload+0x3c56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c56;
	}
x86_l_37a2:
	/* 0x37a2: cmp    WORD PTR [r12+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_37ac:
	/* 0x37ac: je     3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5e;
	}
x86_l_37b2:
	/* 0x37b2: mov    ecx,DWORD PTR [r12+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_37ba:
	/* 0x37ba: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_37be:
	/* 0x37be: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37c2:
	/* 0x37c2: cmp    WORD PTR [r12+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_37cc:
	/* 0x37cc: je     37ee <generic_sleepable_preload+0x37ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37ee;
	}
x86_l_37ce:
	/* 0x37ce: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_37d1:
	/* 0x37d1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_37d6:
	/* 0x37d6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_37db:
	/* 0x37db: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37df:
	/* 0x37df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37e4:
	/* 0x37e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37e6:
	/* 0x37e6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37e8:
	/* 0x37e8: js     5c11 <generic_sleepable_preload+0x5c11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23569ULL;
	}
x86_l_37ee:
	/* 0x37ee: cmp    WORD PTR [r12+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_37f8:
	/* 0x37f8: je     3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5e;
	}
x86_l_37fe:
	/* 0x37fe: mov    ecx,DWORD PTR [r12+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3806:
	/* 0x3806: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_380a:
	/* 0x380a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_380e:
	/* 0x380e: cmp    WORD PTR [r12+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3818:
	/* 0x3818: je     383a <generic_sleepable_preload+0x383a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_383a;
	}
x86_l_381a:
	/* 0x381a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_381d:
	/* 0x381d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3822:
	/* 0x3822: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3827:
	/* 0x3827: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_382b:
	/* 0x382b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3830:
	/* 0x3830: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3832:
	/* 0x3832: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3834:
	/* 0x3834: js     5d10 <generic_sleepable_preload+0x5d10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23824ULL;
	}
x86_l_383a:
	/* 0x383a: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_383f:
	/* 0x383f: cmp    WORD PTR [r12+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_3849:
	/* 0x3849: je     3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5e;
	}
x86_l_384f:
	/* 0x384f: mov    ecx,DWORD PTR [r12+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_3857:
	/* 0x3857: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_385b:
	/* 0x385b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_385f:
	/* 0x385f: cmp    WORD PTR [r12+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_3869:
	/* 0x3869: je     3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5e;
	}
x86_l_386f:
	/* 0x386f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3872:
	/* 0x3872: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3877:
	/* 0x3877: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_387c:
	/* 0x387c: jmp    3b56 <generic_sleepable_preload+0x3b56> */
	goto x86_l_3b56;
x86_l_3881:
	/* 0x3881: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3884:
	/* 0x3884: je     38a6 <generic_sleepable_preload+0x38a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38a6;
	}
x86_l_3886:
	/* 0x3886: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3889:
	/* 0x3889: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_388e:
	/* 0x388e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3893:
	/* 0x3893: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3897:
	/* 0x3897: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_389c:
	/* 0x389c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_389e:
	/* 0x389e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38a0:
	/* 0x38a0: js     3b73 <generic_sleepable_preload+0x3b73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b73;
	}
x86_l_38a6:
	/* 0x38a6: cmp    WORD PTR [r12+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_38b0:
	/* 0x38b0: je     3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5e;
	}
x86_l_38b6:
	/* 0x38b6: mov    ecx,DWORD PTR [r12+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_38be:
	/* 0x38be: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_38c2:
	/* 0x38c2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38c6:
	/* 0x38c6: cmp    WORD PTR [r12+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_38d0:
	/* 0x38d0: je     38f2 <generic_sleepable_preload+0x38f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38f2;
	}
x86_l_38d2:
	/* 0x38d2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_38d5:
	/* 0x38d5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_38da:
	/* 0x38da: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_38df:
	/* 0x38df: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38e3:
	/* 0x38e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38e8:
	/* 0x38e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38ea:
	/* 0x38ea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38ec:
	/* 0x38ec: js     3b7d <generic_sleepable_preload+0x3b7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b7d;
	}
x86_l_38f2:
	/* 0x38f2: cmp    WORD PTR [r12+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_38fc:
	/* 0x38fc: je     3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5e;
	}
x86_l_3902:
	/* 0x3902: mov    ecx,DWORD PTR [r12+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_390a:
	/* 0x390a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_390e:
	/* 0x390e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3912:
	/* 0x3912: cmp    WORD PTR [r12+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_391c:
	/* 0x391c: je     393e <generic_sleepable_preload+0x393e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_393e;
	}
x86_l_391e:
	/* 0x391e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3921:
	/* 0x3921: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3926:
	/* 0x3926: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_392b:
	/* 0x392b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_392f:
	/* 0x392f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3934:
	/* 0x3934: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3936:
	/* 0x3936: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3938:
	/* 0x3938: js     3b8e <generic_sleepable_preload+0x3b8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b8e;
	}
x86_l_393e:
	/* 0x393e: cmp    WORD PTR [r12+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_3948:
	/* 0x3948: je     3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5e;
	}
x86_l_394e:
	/* 0x394e: mov    ecx,DWORD PTR [r12+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_3956:
	/* 0x3956: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_395a:
	/* 0x395a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_395e:
	/* 0x395e: cmp    WORD PTR [r12+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_3968:
	/* 0x3968: je     398a <generic_sleepable_preload+0x398a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_398a;
	}
x86_l_396a:
	/* 0x396a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_396d:
	/* 0x396d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3972:
	/* 0x3972: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3977:
	/* 0x3977: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_397b:
	/* 0x397b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3980:
	/* 0x3980: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3982:
	/* 0x3982: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3984:
	/* 0x3984: js     3b9f <generic_sleepable_preload+0x3b9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b9f;
	}
x86_l_398a:
	/* 0x398a: cmp    WORD PTR [r12+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_3994:
	/* 0x3994: je     3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5e;
	}
x86_l_399a:
	/* 0x399a: mov    ecx,DWORD PTR [r12+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_39a2:
	/* 0x39a2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_39a6:
	/* 0x39a6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39aa:
	/* 0x39aa: cmp    WORD PTR [r12+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_39b4:
	/* 0x39b4: je     39d6 <generic_sleepable_preload+0x39d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39d6;
	}
x86_l_39b6:
	/* 0x39b6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_39b9:
	/* 0x39b9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_39be:
	/* 0x39be: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_39c3:
	/* 0x39c3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39c7:
	/* 0x39c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39cc:
	/* 0x39cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39ce:
	/* 0x39ce: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39d0:
	/* 0x39d0: js     3bb0 <generic_sleepable_preload+0x3bb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3bb0;
	}
x86_l_39d6:
	/* 0x39d6: cmp    WORD PTR [r12+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_39e0:
	/* 0x39e0: je     3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5e;
	}
x86_l_39e6:
	/* 0x39e6: mov    ecx,DWORD PTR [r12+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_39ee:
	/* 0x39ee: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_39f2:
	/* 0x39f2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39f6:
	/* 0x39f6: cmp    WORD PTR [r12+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_3a00:
	/* 0x3a00: je     3a22 <generic_sleepable_preload+0x3a22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a22;
	}
x86_l_3a02:
	/* 0x3a02: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3a05:
	/* 0x3a05: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a0a:
	/* 0x3a0a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a0f:
	/* 0x3a0f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a13:
	/* 0x3a13: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a18:
	/* 0x3a18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a1a:
	/* 0x3a1a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a1c:
	/* 0x3a1c: js     3bc1 <generic_sleepable_preload+0x3bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3bc1;
	}
x86_l_3a22:
	/* 0x3a22: cmp    WORD PTR [r12+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_3a2c:
	/* 0x3a2c: je     3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5e;
	}
x86_l_3a32:
	/* 0x3a32: mov    ecx,DWORD PTR [r12+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_3a3a:
	/* 0x3a3a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3a3e:
	/* 0x3a3e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a42:
	/* 0x3a42: cmp    WORD PTR [r12+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_3a4c:
	/* 0x3a4c: je     3a6e <generic_sleepable_preload+0x3a6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a6e;
	}
x86_l_3a4e:
	/* 0x3a4e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3a51:
	/* 0x3a51: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a56:
	/* 0x3a56: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a5b:
	/* 0x3a5b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a5f:
	/* 0x3a5f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a64:
	/* 0x3a64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a66:
	/* 0x3a66: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a68:
	/* 0x3a68: js     3c56 <generic_sleepable_preload+0x3c56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c56;
	}
x86_l_3a6e:
	/* 0x3a6e: cmp    WORD PTR [r12+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_3a78:
	/* 0x3a78: je     3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5e;
	}
x86_l_3a7e:
	/* 0x3a7e: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_3a81:
	/* 0x3a81: mov    ecx,DWORD PTR [r12+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_3a89:
	/* 0x3a89: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3a8d:
	/* 0x3a8d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a91:
	/* 0x3a91: cmp    WORD PTR [r12+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_3a9b:
	/* 0x3a9b: je     3abd <generic_sleepable_preload+0x3abd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3abd;
	}
x86_l_3a9d:
	/* 0x3a9d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3aa0:
	/* 0x3aa0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3aa5:
	/* 0x3aa5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3aaa:
	/* 0x3aaa: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3aae:
	/* 0x3aae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ab3:
	/* 0x3ab3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ab5:
	/* 0x3ab5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ab7:
	/* 0x3ab7: js     5c8f <generic_sleepable_preload+0x5c8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23695ULL;
	}
x86_l_3abd:
	/* 0x3abd: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ac2:
	/* 0x3ac2: cmp    WORD PTR [r12+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_3acc:
	/* 0x3acc: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_3acf:
	/* 0x3acf: je     3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5e;
	}
x86_l_3ad5:
	/* 0x3ad5: mov    ecx,DWORD PTR [r12+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3add:
	/* 0x3add: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3ae1:
	/* 0x3ae1: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ae5:
	/* 0x3ae5: cmp    WORD PTR [r12+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3aef:
	/* 0x3aef: je     3b11 <generic_sleepable_preload+0x3b11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b11;
	}
x86_l_3af1:
	/* 0x3af1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3af4:
	/* 0x3af4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3af9:
	/* 0x3af9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3afe:
	/* 0x3afe: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b02:
	/* 0x3b02: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b07:
	/* 0x3b07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b09:
	/* 0x3b09: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b0b:
	/* 0x3b0b: js     5daf <generic_sleepable_preload+0x5daf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23983ULL;
	}
x86_l_3b11:
	/* 0x3b11: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b16:
	/* 0x3b16: cmp    WORD PTR [r12+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_3b20:
	/* 0x3b20: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_3b23:
	/* 0x3b23: je     3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5e;
	}
x86_l_3b29:
	/* 0x3b29: mov    ecx,DWORD PTR [r12+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_3b31:
	/* 0x3b31: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3b35:
	/* 0x3b35: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b39:
	/* 0x3b39: cmp    WORD PTR [r12+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_3b43:
	/* 0x3b43: je     3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c5e;
	}
x86_l_3b49:
	/* 0x3b49: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3b4c:
	/* 0x3b4c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3b51:
	/* 0x3b51: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b56:
	/* 0x3b56: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b5a:
	/* 0x3b5a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b5f:
	/* 0x3b5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b61:
	/* 0x3b61: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b63:
	/* 0x3b63: jns    3c5e <generic_sleepable_preload+0x3c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_3c5e;
	}
x86_l_3b69:
	/* 0x3b69: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_3b6e:
	/* 0x3b6e: jmp    3c5b <generic_sleepable_preload+0x3c5b> */
	goto x86_l_3c5b;
x86_l_3b73:
	/* 0x3b73: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3b78:
	/* 0x3b78: jmp    3c5b <generic_sleepable_preload+0x3c5b> */
	goto x86_l_3c5b;
x86_l_3b7d:
	/* 0x3b7d: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_3b82:
	/* 0x3b82: jmp    3c5b <generic_sleepable_preload+0x3c5b> */
	goto x86_l_3c5b;
x86_l_3b87:
	/* 0x3b87: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_3b8c:
	/* 0x3b8c: jmp    3bd0 <generic_sleepable_preload+0x3bd0> */
	goto x86_l_3bd0;
x86_l_3b8e:
	/* 0x3b8e: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_3b93:
	/* 0x3b93: jmp    3c5b <generic_sleepable_preload+0x3c5b> */
	goto x86_l_3c5b;
x86_l_3b98:
	/* 0x3b98: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_3b9d:
	/* 0x3b9d: jmp    3bd0 <generic_sleepable_preload+0x3bd0> */
	goto x86_l_3bd0;
x86_l_3b9f:
	/* 0x3b9f: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_3ba4:
	/* 0x3ba4: jmp    3c5b <generic_sleepable_preload+0x3c5b> */
	goto x86_l_3c5b;
x86_l_3ba9:
	/* 0x3ba9: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_3bae:
	/* 0x3bae: jmp    3bd0 <generic_sleepable_preload+0x3bd0> */
	goto x86_l_3bd0;
x86_l_3bb0:
	/* 0x3bb0: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_3bb5:
	/* 0x3bb5: jmp    3c5b <generic_sleepable_preload+0x3c5b> */
	goto x86_l_3c5b;
x86_l_3bba:
	/* 0x3bba: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_3bbf:
	/* 0x3bbf: jmp    3bd0 <generic_sleepable_preload+0x3bd0> */
	goto x86_l_3bd0;
x86_l_3bc1:
	/* 0x3bc1: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_3bc6:
	/* 0x3bc6: jmp    3c5b <generic_sleepable_preload+0x3c5b> */
	goto x86_l_3c5b;
x86_l_3bcb:
	/* 0x3bcb: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_3bd0:
	/* 0x3bd0: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3bd3:
	/* 0x3bd3: mov    ebp,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3bd8:
	/* 0x3bd8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3bdb:
	/* 0x3bdb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3be0:
	/* 0x3be0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3be5:
	/* 0x3be5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bea:
	/* 0x3bea: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_3bed:
	/* 0x3bed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bef:
	/* 0x3bef: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_3bf2:
	/* 0x3bf2: jne    3d03 <generic_sleepable_preload+0x3d03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3d03;
	}
x86_l_3bf8:
	/* 0x3bf8: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_3bfb:
	/* 0x3bfb: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3bff:
	/* 0x3bff: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3c04:
	/* 0x3c04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c06:
	/* 0x3c06: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3c0b:
	/* 0x3c0b: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_3c13:
	/* 0x3c13: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3c1a:
	/* 0x3c1a: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3c1f:
	/* 0x3c1f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c24:
	/* 0x3c24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c26:
	/* 0x3c26: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3c29:
	/* 0x3c29: je     3d00 <generic_sleepable_preload+0x3d00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d00;
	}
x86_l_3c2f:
	/* 0x3c2f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3c32:
	/* 0x3c32: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3c39:
	/* 0x3c39: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c3b:
	/* 0x3c3b: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3c40:
	/* 0x3c40: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3c45:
	/* 0x3c45: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3c48:
	/* 0x3c48: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_3c4b:
	/* 0x3c4b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c4d:
	/* 0x3c4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c4f:
	/* 0x3c4f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c54:
	/* 0x3c54: jmp    3cbf <generic_sleepable_preload+0x3cbf> */
	goto x86_l_3cbf;
x86_l_3c56:
	/* 0x3c56: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_3c5b:
	/* 0x3c5b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c5e:
	/* 0x3c5e: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_3c61:
	/* 0x3c61: jne    3d03 <generic_sleepable_preload+0x3d03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3d03;
	}
x86_l_3c67:
	/* 0x3c67: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_3c6a:
	/* 0x3c6a: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c6e:
	/* 0x3c6e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3c73:
	/* 0x3c73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c75:
	/* 0x3c75: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3c7a:
	/* 0x3c7a: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_3c82:
	/* 0x3c82: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3c89:
	/* 0x3c89: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3c8e:
	/* 0x3c8e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c93:
	/* 0x3c93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c95:
	/* 0x3c95: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3c98:
	/* 0x3c98: je     3d00 <generic_sleepable_preload+0x3d00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d00;
	}
x86_l_3c9a:
	/* 0x3c9a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3c9d:
	/* 0x3c9d: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3ca4:
	/* 0x3ca4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ca6:
	/* 0x3ca6: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3cab:
	/* 0x3cab: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3cb0:
	/* 0x3cb0: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3cb3:
	/* 0x3cb3: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_3cb6:
	/* 0x3cb6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3cb8:
	/* 0x3cb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cba:
	/* 0x3cba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3cbf:
	/* 0x3cbf: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3cc2:
	/* 0x3cc2: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_3cc5:
	/* 0x3cc5: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3cca:
	/* 0x3cca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ccc:
	/* 0x3ccc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3ccf:
	/* 0x3ccf: je     3d00 <generic_sleepable_preload+0x3d00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d00;
	}
x86_l_3cd1:
	/* 0x3cd1: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_3cd4:
	/* 0x3cd4: je     3cfe <generic_sleepable_preload+0x3cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cfe;
	}
x86_l_3cd6:
	/* 0x3cd6: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3cd9:
	/* 0x3cd9: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3cdd:
	/* 0x3cdd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3ce2:
	/* 0x3ce2: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3ce5:
	/* 0x3ce5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ce7:
	/* 0x3ce7: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3cea:
	/* 0x3cea: call   3cef <generic_sleepable_preload+0x3cef> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_3cef:
	/* 0x3cef: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_3cf1:
	/* 0x3cf1: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_3cf4:
	/* 0x3cf4: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_3cf6:
	/* 0x3cf6: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_3cfb:
	/* 0x3cfb: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_3cfe:
	/* 0x3cfe: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d00:
	/* 0x3d00: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_3d03:
	/* 0x3d03: mov    eax,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3d08:
	/* 0x3d08: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_3d0d:
	/* 0x3d0d: je     4c6e <generic_sleepable_preload+0x4c6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19566ULL;
	}
x86_l_3d13:
	/* 0x3d13: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_3d15:
	/* 0x3d15: js     3d4a <generic_sleepable_preload+0x3d4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3d4a;
	}
x86_l_3d17:
	/* 0x3d17: mov    eax,DWORD PTR [r12+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_3d1c:
	/* 0x3d1c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3d1f:
	/* 0x3d1f: jle    3dcd <generic_sleepable_preload+0x3dcd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 15821ULL;
	}
x86_l_3d25:
	/* 0x3d25: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3d28:
	/* 0x3d28: je     3e37 <generic_sleepable_preload+0x3e37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15927ULL;
	}
x86_l_3d2e:
	/* 0x3d2e: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3d31:
	/* 0x3d31: je     3e3e <generic_sleepable_preload+0x3e3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15934ULL;
	}
x86_l_3d37:
	/* 0x3d37: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d3a:
	/* 0x3d3a: jne    3e51 <generic_sleepable_preload+0x3e51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15953ULL;
	}
x86_l_3d40:
	/* 0x3d40: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3d45:
	/* 0x3d45: jmp    3e4a <generic_sleepable_preload+0x3e4a> */
	return 15946ULL;
x86_l_3d4a:
	/* 0x3d4a: movzx  eax,BYTE PTR [r12+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_3d53:
	/* 0x3d53: movzx  ecx,WORD PTR [r12+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_3d5c:
	/* 0x3d5c: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_3d62:
	/* 0x3d62: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3d64:
	/* 0x3d64: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_3d67:
	/* 0x3d67: jle    3da6 <generic_sleepable_preload+0x3da6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3da6;
	}
x86_l_3d69:
	/* 0x3d69: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3d6c:
	/* 0x3d6c: jle    3ddd <generic_sleepable_preload+0x3ddd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 15837ULL;
	}
x86_l_3d6e:
	/* 0x3d6e: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_3d71:
	/* 0x3d71: jle    44a0 <generic_sleepable_preload+0x44a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 17568ULL;
	}
x86_l_3d77:
	/* 0x3d77: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3d7c:
	/* 0x3d7c: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_3d7f:
	/* 0x3d7f: je     44c5 <generic_sleepable_preload+0x44c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17605ULL;
	}
x86_l_3d85:
	/* 0x3d85: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3d8a:
	/* 0x3d8a: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_3d8d:
	/* 0x3d8d: je     44c5 <generic_sleepable_preload+0x44c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17605ULL;
	}
x86_l_3d93:
	/* 0x3d93: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3d98:
	/* 0x3d98: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_3d9b:
	/* 0x3d9b: je     44c5 <generic_sleepable_preload+0x44c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17605ULL;
	}
x86_l_3da1:
	/* 0x3da1: jmp    44d8 <generic_sleepable_preload+0x44d8> */
	return 17624ULL;
x86_l_3da6:
	/* 0x3da6: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3da9:
	/* 0x3da9: jg     3e0a <generic_sleepable_preload+0x3e0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 15882ULL;
	}
x86_l_3dab:
	/* 0x3dab: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_3dae:
	/* 0x3dae: jg     4471 <generic_sleepable_preload+0x4471> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 17521ULL;
	}
	return 15796ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15796ULL: goto x86_l_3db4;
	case 15798ULL: goto x86_l_3db6;
	case 15804ULL: goto x86_l_3dbc;
	case 15807ULL: goto x86_l_3dbf;
	case 15810ULL: goto x86_l_3dc2;
	case 15816ULL: goto x86_l_3dc8;
	case 15821ULL: goto x86_l_3dcd;
	case 15823ULL: goto x86_l_3dcf;
	case 15825ULL: goto x86_l_3dd1;
	case 15828ULL: goto x86_l_3dd4;
	case 15830ULL: goto x86_l_3dd6;
	case 15835ULL: goto x86_l_3ddb;
	case 15837ULL: goto x86_l_3ddd;
	case 15840ULL: goto x86_l_3de0;
	case 15846ULL: goto x86_l_3de6;
	case 15854ULL: goto x86_l_3dee;
	case 15857ULL: goto x86_l_3df1;
	case 15863ULL: goto x86_l_3df7;
	case 15868ULL: goto x86_l_3dfc;
	case 15871ULL: goto x86_l_3dff;
	case 15877ULL: goto x86_l_3e05;
	case 15882ULL: goto x86_l_3e0a;
	case 15885ULL: goto x86_l_3e0d;
	case 15891ULL: goto x86_l_3e13;
	case 15899ULL: goto x86_l_3e1b;
	case 15902ULL: goto x86_l_3e1e;
	case 15908ULL: goto x86_l_3e24;
	case 15913ULL: goto x86_l_3e29;
	case 15916ULL: goto x86_l_3e2c;
	case 15922ULL: goto x86_l_3e32;
	case 15927ULL: goto x86_l_3e37;
	case 15932ULL: goto x86_l_3e3c;
	case 15934ULL: goto x86_l_3e3e;
	case 15939ULL: goto x86_l_3e43;
	case 15941ULL: goto x86_l_3e45;
	case 15946ULL: goto x86_l_3e4a;
	case 15949ULL: goto x86_l_3e4d;
	case 15953ULL: goto x86_l_3e51;
	case 15955ULL: goto x86_l_3e53;
	case 15958ULL: goto x86_l_3e56;
	case 15968ULL: goto x86_l_3e60;
	case 15974ULL: goto x86_l_3e66;
	case 15981ULL: goto x86_l_3e6d;
	case 15984ULL: goto x86_l_3e70;
	case 15992ULL: goto x86_l_3e78;
	case 15995ULL: goto x86_l_3e7b;
	case 15999ULL: goto x86_l_3e7f;
	case 16008ULL: goto x86_l_3e88;
	case 16010ULL: goto x86_l_3e8a;
	case 16016ULL: goto x86_l_3e90;
	case 16019ULL: goto x86_l_3e93;
	case 16021ULL: goto x86_l_3e95;
	case 16024ULL: goto x86_l_3e98;
	case 16029ULL: goto x86_l_3e9d;
	case 16034ULL: goto x86_l_3ea2;
	case 16038ULL: goto x86_l_3ea6;
	case 16043ULL: goto x86_l_3eab;
	case 16045ULL: goto x86_l_3ead;
	case 16047ULL: goto x86_l_3eaf;
	case 16053ULL: goto x86_l_3eb5;
	case 16063ULL: goto x86_l_3ebf;
	case 16069ULL: goto x86_l_3ec5;
	case 16077ULL: goto x86_l_3ecd;
	case 16081ULL: goto x86_l_3ed1;
	case 16085ULL: goto x86_l_3ed5;
	case 16095ULL: goto x86_l_3edf;
	case 16097ULL: goto x86_l_3ee1;
	case 16100ULL: goto x86_l_3ee4;
	case 16105ULL: goto x86_l_3ee9;
	case 16110ULL: goto x86_l_3eee;
	case 16114ULL: goto x86_l_3ef2;
	case 16119ULL: goto x86_l_3ef7;
	case 16121ULL: goto x86_l_3ef9;
	case 16123ULL: goto x86_l_3efb;
	case 16129ULL: goto x86_l_3f01;
	case 16139ULL: goto x86_l_3f0b;
	case 16145ULL: goto x86_l_3f11;
	case 16153ULL: goto x86_l_3f19;
	case 16157ULL: goto x86_l_3f1d;
	case 16161ULL: goto x86_l_3f21;
	case 16171ULL: goto x86_l_3f2b;
	case 16173ULL: goto x86_l_3f2d;
	case 16176ULL: goto x86_l_3f30;
	case 16181ULL: goto x86_l_3f35;
	case 16186ULL: goto x86_l_3f3a;
	case 16190ULL: goto x86_l_3f3e;
	case 16195ULL: goto x86_l_3f43;
	case 16197ULL: goto x86_l_3f45;
	case 16199ULL: goto x86_l_3f47;
	case 16205ULL: goto x86_l_3f4d;
	case 16215ULL: goto x86_l_3f57;
	case 16221ULL: goto x86_l_3f5d;
	case 16229ULL: goto x86_l_3f65;
	case 16233ULL: goto x86_l_3f69;
	case 16237ULL: goto x86_l_3f6d;
	case 16247ULL: goto x86_l_3f77;
	case 16249ULL: goto x86_l_3f79;
	case 16252ULL: goto x86_l_3f7c;
	case 16257ULL: goto x86_l_3f81;
	case 16262ULL: goto x86_l_3f86;
	case 16266ULL: goto x86_l_3f8a;
	case 16271ULL: goto x86_l_3f8f;
	case 16273ULL: goto x86_l_3f91;
	case 16275ULL: goto x86_l_3f93;
	case 16281ULL: goto x86_l_3f99;
	case 16291ULL: goto x86_l_3fa3;
	case 16297ULL: goto x86_l_3fa9;
	case 16305ULL: goto x86_l_3fb1;
	case 16309ULL: goto x86_l_3fb5;
	case 16313ULL: goto x86_l_3fb9;
	case 16323ULL: goto x86_l_3fc3;
	case 16325ULL: goto x86_l_3fc5;
	case 16328ULL: goto x86_l_3fc8;
	case 16333ULL: goto x86_l_3fcd;
	case 16338ULL: goto x86_l_3fd2;
	case 16342ULL: goto x86_l_3fd6;
	case 16347ULL: goto x86_l_3fdb;
	case 16349ULL: goto x86_l_3fdd;
	case 16351ULL: goto x86_l_3fdf;
	case 16357ULL: goto x86_l_3fe5;
	case 16367ULL: goto x86_l_3fef;
	case 16373ULL: goto x86_l_3ff5;
	case 16381ULL: goto x86_l_3ffd;
	case 16385ULL: goto x86_l_4001;
	case 16389ULL: goto x86_l_4005;
	case 16399ULL: goto x86_l_400f;
	case 16401ULL: goto x86_l_4011;
	case 16404ULL: goto x86_l_4014;
	case 16409ULL: goto x86_l_4019;
	case 16414ULL: goto x86_l_401e;
	case 16418ULL: goto x86_l_4022;
	case 16423ULL: goto x86_l_4027;
	case 16425ULL: goto x86_l_4029;
	case 16427ULL: goto x86_l_402b;
	case 16433ULL: goto x86_l_4031;
	case 16443ULL: goto x86_l_403b;
	case 16449ULL: goto x86_l_4041;
	case 16457ULL: goto x86_l_4049;
	case 16461ULL: goto x86_l_404d;
	case 16465ULL: goto x86_l_4051;
	case 16475ULL: goto x86_l_405b;
	case 16477ULL: goto x86_l_405d;
	case 16480ULL: goto x86_l_4060;
	case 16485ULL: goto x86_l_4065;
	case 16490ULL: goto x86_l_406a;
	case 16494ULL: goto x86_l_406e;
	case 16499ULL: goto x86_l_4073;
	case 16501ULL: goto x86_l_4075;
	case 16503ULL: goto x86_l_4077;
	case 16509ULL: goto x86_l_407d;
	case 16519ULL: goto x86_l_4087;
	case 16525ULL: goto x86_l_408d;
	case 16533ULL: goto x86_l_4095;
	case 16537ULL: goto x86_l_4099;
	case 16541ULL: goto x86_l_409d;
	case 16551ULL: goto x86_l_40a7;
	case 16553ULL: goto x86_l_40a9;
	case 16556ULL: goto x86_l_40ac;
	case 16561ULL: goto x86_l_40b1;
	case 16566ULL: goto x86_l_40b6;
	case 16570ULL: goto x86_l_40ba;
	case 16575ULL: goto x86_l_40bf;
	case 16577ULL: goto x86_l_40c1;
	case 16579ULL: goto x86_l_40c3;
	case 16585ULL: goto x86_l_40c9;
	case 16595ULL: goto x86_l_40d3;
	case 16601ULL: goto x86_l_40d9;
	case 16609ULL: goto x86_l_40e1;
	case 16613ULL: goto x86_l_40e5;
	case 16617ULL: goto x86_l_40e9;
	case 16627ULL: goto x86_l_40f3;
	case 16629ULL: goto x86_l_40f5;
	case 16632ULL: goto x86_l_40f8;
	case 16637ULL: goto x86_l_40fd;
	case 16642ULL: goto x86_l_4102;
	case 16646ULL: goto x86_l_4106;
	case 16651ULL: goto x86_l_410b;
	case 16653ULL: goto x86_l_410d;
	case 16655ULL: goto x86_l_410f;
	case 16661ULL: goto x86_l_4115;
	case 16666ULL: goto x86_l_411a;
	case 16676ULL: goto x86_l_4124;
	case 16682ULL: goto x86_l_412a;
	case 16690ULL: goto x86_l_4132;
	case 16694ULL: goto x86_l_4136;
	case 16698ULL: goto x86_l_413a;
	case 16708ULL: goto x86_l_4144;
	case 16714ULL: goto x86_l_414a;
	case 16717ULL: goto x86_l_414d;
	case 16722ULL: goto x86_l_4152;
	case 16727ULL: goto x86_l_4157;
	case 16732ULL: goto x86_l_415c;
	case 16735ULL: goto x86_l_415f;
	case 16737ULL: goto x86_l_4161;
	case 16740ULL: goto x86_l_4164;
	case 16745ULL: goto x86_l_4169;
	case 16750ULL: goto x86_l_416e;
	case 16754ULL: goto x86_l_4172;
	case 16759ULL: goto x86_l_4177;
	case 16761ULL: goto x86_l_4179;
	case 16763ULL: goto x86_l_417b;
	case 16769ULL: goto x86_l_4181;
	case 16779ULL: goto x86_l_418b;
	case 16785ULL: goto x86_l_4191;
	case 16793ULL: goto x86_l_4199;
	case 16797ULL: goto x86_l_419d;
	case 16801ULL: goto x86_l_41a1;
	case 16811ULL: goto x86_l_41ab;
	case 16813ULL: goto x86_l_41ad;
	case 16816ULL: goto x86_l_41b0;
	case 16821ULL: goto x86_l_41b5;
	case 16826ULL: goto x86_l_41ba;
	case 16830ULL: goto x86_l_41be;
	case 16835ULL: goto x86_l_41c3;
	case 16837ULL: goto x86_l_41c5;
	case 16839ULL: goto x86_l_41c7;
	case 16845ULL: goto x86_l_41cd;
	case 16855ULL: goto x86_l_41d7;
	case 16861ULL: goto x86_l_41dd;
	case 16869ULL: goto x86_l_41e5;
	case 16873ULL: goto x86_l_41e9;
	case 16877ULL: goto x86_l_41ed;
	case 16887ULL: goto x86_l_41f7;
	case 16889ULL: goto x86_l_41f9;
	case 16892ULL: goto x86_l_41fc;
	case 16897ULL: goto x86_l_4201;
	case 16902ULL: goto x86_l_4206;
	case 16906ULL: goto x86_l_420a;
	case 16911ULL: goto x86_l_420f;
	case 16913ULL: goto x86_l_4211;
	case 16915ULL: goto x86_l_4213;
	case 16921ULL: goto x86_l_4219;
	case 16931ULL: goto x86_l_4223;
	case 16937ULL: goto x86_l_4229;
	case 16945ULL: goto x86_l_4231;
	case 16949ULL: goto x86_l_4235;
	case 16953ULL: goto x86_l_4239;
	case 16963ULL: goto x86_l_4243;
	case 16965ULL: goto x86_l_4245;
	case 16968ULL: goto x86_l_4248;
	case 16973ULL: goto x86_l_424d;
	case 16978ULL: goto x86_l_4252;
	case 16982ULL: goto x86_l_4256;
	case 16987ULL: goto x86_l_425b;
	case 16989ULL: goto x86_l_425d;
	case 16991ULL: goto x86_l_425f;
	case 16997ULL: goto x86_l_4265;
	case 17007ULL: goto x86_l_426f;
	case 17013ULL: goto x86_l_4275;
	case 17021ULL: goto x86_l_427d;
	case 17025ULL: goto x86_l_4281;
	case 17029ULL: goto x86_l_4285;
	case 17039ULL: goto x86_l_428f;
	case 17041ULL: goto x86_l_4291;
	case 17044ULL: goto x86_l_4294;
	case 17049ULL: goto x86_l_4299;
	case 17054ULL: goto x86_l_429e;
	case 17058ULL: goto x86_l_42a2;
	case 17063ULL: goto x86_l_42a7;
	case 17065ULL: goto x86_l_42a9;
	case 17067ULL: goto x86_l_42ab;
	case 17073ULL: goto x86_l_42b1;
	case 17083ULL: goto x86_l_42bb;
	case 17089ULL: goto x86_l_42c1;
	case 17097ULL: goto x86_l_42c9;
	case 17101ULL: goto x86_l_42cd;
	case 17105ULL: goto x86_l_42d1;
	case 17115ULL: goto x86_l_42db;
	case 17117ULL: goto x86_l_42dd;
	case 17120ULL: goto x86_l_42e0;
	case 17125ULL: goto x86_l_42e5;
	case 17130ULL: goto x86_l_42ea;
	case 17134ULL: goto x86_l_42ee;
	case 17139ULL: goto x86_l_42f3;
	case 17141ULL: goto x86_l_42f5;
	case 17143ULL: goto x86_l_42f7;
	case 17149ULL: goto x86_l_42fd;
	case 17159ULL: goto x86_l_4307;
	case 17165ULL: goto x86_l_430d;
	case 17173ULL: goto x86_l_4315;
	case 17177ULL: goto x86_l_4319;
	case 17181ULL: goto x86_l_431d;
	case 17191ULL: goto x86_l_4327;
	case 17193ULL: goto x86_l_4329;
	case 17196ULL: goto x86_l_432c;
	case 17201ULL: goto x86_l_4331;
	case 17206ULL: goto x86_l_4336;
	case 17210ULL: goto x86_l_433a;
	case 17215ULL: goto x86_l_433f;
	case 17217ULL: goto x86_l_4341;
	case 17219ULL: goto x86_l_4343;
	case 17225ULL: goto x86_l_4349;
	case 17235ULL: goto x86_l_4353;
	case 17241ULL: goto x86_l_4359;
	case 17244ULL: goto x86_l_435c;
	case 17252ULL: goto x86_l_4364;
	case 17256ULL: goto x86_l_4368;
	case 17260ULL: goto x86_l_436c;
	case 17270ULL: goto x86_l_4376;
	case 17272ULL: goto x86_l_4378;
	case 17275ULL: goto x86_l_437b;
	case 17280ULL: goto x86_l_4380;
	case 17285ULL: goto x86_l_4385;
	case 17289ULL: goto x86_l_4389;
	case 17294ULL: goto x86_l_438e;
	case 17296ULL: goto x86_l_4390;
	case 17298ULL: goto x86_l_4392;
	case 17304ULL: goto x86_l_4398;
	case 17309ULL: goto x86_l_439d;
	case 17319ULL: goto x86_l_43a7;
	case 17322ULL: goto x86_l_43aa;
	case 17328ULL: goto x86_l_43b0;
	case 17336ULL: goto x86_l_43b8;
	case 17340ULL: goto x86_l_43bc;
	case 17344ULL: goto x86_l_43c0;
	case 17354ULL: goto x86_l_43ca;
	case 17356ULL: goto x86_l_43cc;
	case 17359ULL: goto x86_l_43cf;
	case 17364ULL: goto x86_l_43d4;
	case 17369ULL: goto x86_l_43d9;
	case 17373ULL: goto x86_l_43dd;
	case 17378ULL: goto x86_l_43e2;
	case 17380ULL: goto x86_l_43e4;
	case 17382ULL: goto x86_l_43e6;
	case 17388ULL: goto x86_l_43ec;
	case 17393ULL: goto x86_l_43f1;
	case 17403ULL: goto x86_l_43fb;
	case 17406ULL: goto x86_l_43fe;
	case 17412ULL: goto x86_l_4404;
	case 17420ULL: goto x86_l_440c;
	case 17424ULL: goto x86_l_4410;
	case 17428ULL: goto x86_l_4414;
	case 17438ULL: goto x86_l_441e;
	case 17444ULL: goto x86_l_4424;
	case 17447ULL: goto x86_l_4427;
	case 17452ULL: goto x86_l_442c;
	case 17457ULL: goto x86_l_4431;
	case 17461ULL: goto x86_l_4435;
	case 17466ULL: goto x86_l_443a;
	case 17468ULL: goto x86_l_443c;
	case 17470ULL: goto x86_l_443e;
	case 17476ULL: goto x86_l_4444;
	case 17481ULL: goto x86_l_4449;
	case 17486ULL: goto x86_l_444e;
	case 17491ULL: goto x86_l_4453;
	case 17496ULL: goto x86_l_4458;
	case 17504ULL: goto x86_l_4460;
	case 17507ULL: goto x86_l_4463;
	case 17509ULL: goto x86_l_4465;
	case 17514ULL: goto x86_l_446a;
	case 17517ULL: goto x86_l_446d;
	case 17519ULL: goto x86_l_446f;
	case 17521ULL: goto x86_l_4471;
	case 17526ULL: goto x86_l_4476;
	case 17529ULL: goto x86_l_4479;
	case 17531ULL: goto x86_l_447b;
	case 17536ULL: goto x86_l_4480;
	case 17539ULL: goto x86_l_4483;
	case 17541ULL: goto x86_l_4485;
	case 17543ULL: goto x86_l_4487;
	case 17551ULL: goto x86_l_448f;
	case 17554ULL: goto x86_l_4492;
	case 17556ULL: goto x86_l_4494;
	case 17561ULL: goto x86_l_4499;
	case 17564ULL: goto x86_l_449c;
	case 17566ULL: goto x86_l_449e;
	case 17568ULL: goto x86_l_44a0;
	case 17573ULL: goto x86_l_44a5;
	case 17576ULL: goto x86_l_44a8;
	case 17578ULL: goto x86_l_44aa;
	case 17583ULL: goto x86_l_44af;
	case 17586ULL: goto x86_l_44b2;
	case 17588ULL: goto x86_l_44b4;
	case 17590ULL: goto x86_l_44b6;
	case 17595ULL: goto x86_l_44bb;
	case 17600ULL: goto x86_l_44c0;
	case 17605ULL: goto x86_l_44c5;
	case 17608ULL: goto x86_l_44c8;
	case 17610ULL: goto x86_l_44ca;
	case 17612ULL: goto x86_l_44cc;
	case 17617ULL: goto x86_l_44d1;
	case 17619ULL: goto x86_l_44d3;
	case 17624ULL: goto x86_l_44d8;
	case 17628ULL: goto x86_l_44dc;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3db4:
	/* 0x3db4: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_3db6:
	/* 0x3db6: je     44c0 <generic_sleepable_preload+0x44c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c0;
	}
x86_l_3dbc:
	/* 0x3dbc: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_3dbf:
	/* 0x3dbf: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_3dc2:
	/* 0x3dc2: je     44c5 <generic_sleepable_preload+0x44c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c5;
	}
x86_l_3dc8:
	/* 0x3dc8: jmp    44d8 <generic_sleepable_preload+0x44d8> */
	goto x86_l_44d8;
x86_l_3dcd:
	/* 0x3dcd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3dcf:
	/* 0x3dcf: je     3e45 <generic_sleepable_preload+0x3e45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e45;
	}
x86_l_3dd1:
	/* 0x3dd1: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3dd4:
	/* 0x3dd4: jne    3e51 <generic_sleepable_preload+0x3e51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3e51;
	}
x86_l_3dd6:
	/* 0x3dd6: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3ddb:
	/* 0x3ddb: jmp    3e4a <generic_sleepable_preload+0x3e4a> */
	goto x86_l_3e4a;
x86_l_3ddd:
	/* 0x3ddd: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_3de0:
	/* 0x3de0: jg     4458 <generic_sleepable_preload+0x4458> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4458;
	}
x86_l_3de6:
	/* 0x3de6: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3dee:
	/* 0x3dee: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3df1:
	/* 0x3df1: je     44c5 <generic_sleepable_preload+0x44c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c5;
	}
x86_l_3df7:
	/* 0x3df7: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3dfc:
	/* 0x3dfc: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_3dff:
	/* 0x3dff: je     44c5 <generic_sleepable_preload+0x44c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c5;
	}
x86_l_3e05:
	/* 0x3e05: jmp    44d8 <generic_sleepable_preload+0x44d8> */
	goto x86_l_44d8;
x86_l_3e0a:
	/* 0x3e0a: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_3e0d:
	/* 0x3e0d: jg     4487 <generic_sleepable_preload+0x4487> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4487;
	}
x86_l_3e13:
	/* 0x3e13: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3e1b:
	/* 0x3e1b: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3e1e:
	/* 0x3e1e: je     44c5 <generic_sleepable_preload+0x44c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c5;
	}
x86_l_3e24:
	/* 0x3e24: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3e29:
	/* 0x3e29: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_3e2c:
	/* 0x3e2c: je     44c5 <generic_sleepable_preload+0x44c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c5;
	}
x86_l_3e32:
	/* 0x3e32: jmp    44d8 <generic_sleepable_preload+0x44d8> */
	goto x86_l_44d8;
x86_l_3e37:
	/* 0x3e37: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3e3c:
	/* 0x3e3c: jmp    3e4a <generic_sleepable_preload+0x3e4a> */
	goto x86_l_3e4a;
x86_l_3e3e:
	/* 0x3e3e: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e43:
	/* 0x3e43: jmp    3e4a <generic_sleepable_preload+0x3e4a> */
	goto x86_l_3e4a;
x86_l_3e45:
	/* 0x3e45: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3e4a:
	/* 0x3e4a: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e4d:
	/* 0x3e4d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e51:
	/* 0x3e51: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e53:
	/* 0x3e53: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_3e56:
	/* 0x3e56: cmp    WORD PTR [r12+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_3e60:
	/* 0x3e60: je     4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19262ULL;
	}
x86_l_3e66:
	/* 0x3e66: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_3e6d:
	/* 0x3e6d: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3e70:
	/* 0x3e70: mov    eax,DWORD PTR [r12+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_3e78:
	/* 0x3e78: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3e7b:
	/* 0x3e7b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e7f:
	/* 0x3e7f: movzx  eax,WORD PTR [r12+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_3e88:
	/* 0x3e88: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_3e8a:
	/* 0x3e8a: je     415c <generic_sleepable_preload+0x415c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_415c;
	}
x86_l_3e90:
	/* 0x3e90: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3e93:
	/* 0x3e93: je     3eb5 <generic_sleepable_preload+0x3eb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3eb5;
	}
x86_l_3e95:
	/* 0x3e95: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3e98:
	/* 0x3e98: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3e9d:
	/* 0x3e9d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3ea2:
	/* 0x3ea2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ea6:
	/* 0x3ea6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3eab:
	/* 0x3eab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ead:
	/* 0x3ead: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3eaf:
	/* 0x3eaf: js     444e <generic_sleepable_preload+0x444e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_444e;
	}
x86_l_3eb5:
	/* 0x3eb5: cmp    WORD PTR [r12+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_3ebf:
	/* 0x3ebf: je     4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19262ULL;
	}
x86_l_3ec5:
	/* 0x3ec5: mov    ecx,DWORD PTR [r12+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_3ecd:
	/* 0x3ecd: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3ed1:
	/* 0x3ed1: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ed5:
	/* 0x3ed5: cmp    WORD PTR [r12+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_3edf:
	/* 0x3edf: je     3f01 <generic_sleepable_preload+0x3f01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f01;
	}
x86_l_3ee1:
	/* 0x3ee1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3ee4:
	/* 0x3ee4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3ee9:
	/* 0x3ee9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3eee:
	/* 0x3eee: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ef2:
	/* 0x3ef2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ef7:
	/* 0x3ef7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ef9:
	/* 0x3ef9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3efb:
	/* 0x3efb: js     44b6 <generic_sleepable_preload+0x44b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_44b6;
	}
x86_l_3f01:
	/* 0x3f01: cmp    WORD PTR [r12+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_3f0b:
	/* 0x3f0b: je     4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19262ULL;
	}
x86_l_3f11:
	/* 0x3f11: mov    ecx,DWORD PTR [r12+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_3f19:
	/* 0x3f19: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3f1d:
	/* 0x3f1d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f21:
	/* 0x3f21: cmp    WORD PTR [r12+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_3f2b:
	/* 0x3f2b: je     3f4d <generic_sleepable_preload+0x3f4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f4d;
	}
x86_l_3f2d:
	/* 0x3f2d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3f30:
	/* 0x3f30: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3f35:
	/* 0x3f35: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3f3a:
	/* 0x3f3a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f3e:
	/* 0x3f3e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f43:
	/* 0x3f43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f45:
	/* 0x3f45: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3f47:
	/* 0x3f47: js     4af2 <generic_sleepable_preload+0x4af2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19186ULL;
	}
x86_l_3f4d:
	/* 0x3f4d: cmp    WORD PTR [r12+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_3f57:
	/* 0x3f57: je     4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19262ULL;
	}
x86_l_3f5d:
	/* 0x3f5d: mov    ecx,DWORD PTR [r12+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_3f65:
	/* 0x3f65: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3f69:
	/* 0x3f69: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f6d:
	/* 0x3f6d: cmp    WORD PTR [r12+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_3f77:
	/* 0x3f77: je     3f99 <generic_sleepable_preload+0x3f99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f99;
	}
x86_l_3f79:
	/* 0x3f79: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3f7c:
	/* 0x3f7c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3f81:
	/* 0x3f81: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3f86:
	/* 0x3f86: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f8a:
	/* 0x3f8a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f8f:
	/* 0x3f8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f91:
	/* 0x3f91: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3f93:
	/* 0x3f93: js     4b03 <generic_sleepable_preload+0x4b03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19203ULL;
	}
x86_l_3f99:
	/* 0x3f99: cmp    WORD PTR [r12+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_3fa3:
	/* 0x3fa3: je     4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19262ULL;
	}
x86_l_3fa9:
	/* 0x3fa9: mov    ecx,DWORD PTR [r12+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_3fb1:
	/* 0x3fb1: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3fb5:
	/* 0x3fb5: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fb9:
	/* 0x3fb9: cmp    WORD PTR [r12+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_3fc3:
	/* 0x3fc3: je     3fe5 <generic_sleepable_preload+0x3fe5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fe5;
	}
x86_l_3fc5:
	/* 0x3fc5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3fc8:
	/* 0x3fc8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3fcd:
	/* 0x3fcd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3fd2:
	/* 0x3fd2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fd6:
	/* 0x3fd6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3fdb:
	/* 0x3fdb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fdd:
	/* 0x3fdd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3fdf:
	/* 0x3fdf: js     4b14 <generic_sleepable_preload+0x4b14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19220ULL;
	}
x86_l_3fe5:
	/* 0x3fe5: cmp    WORD PTR [r12+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_3fef:
	/* 0x3fef: je     4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19262ULL;
	}
x86_l_3ff5:
	/* 0x3ff5: mov    ecx,DWORD PTR [r12+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_3ffd:
	/* 0x3ffd: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4001:
	/* 0x4001: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4005:
	/* 0x4005: cmp    WORD PTR [r12+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_400f:
	/* 0x400f: je     4031 <generic_sleepable_preload+0x4031> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4031;
	}
x86_l_4011:
	/* 0x4011: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4014:
	/* 0x4014: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4019:
	/* 0x4019: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_401e:
	/* 0x401e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4022:
	/* 0x4022: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4027:
	/* 0x4027: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4029:
	/* 0x4029: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_402b:
	/* 0x402b: js     4b25 <generic_sleepable_preload+0x4b25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19237ULL;
	}
x86_l_4031:
	/* 0x4031: cmp    WORD PTR [r12+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_403b:
	/* 0x403b: je     4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19262ULL;
	}
x86_l_4041:
	/* 0x4041: mov    ecx,DWORD PTR [r12+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_4049:
	/* 0x4049: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_404d:
	/* 0x404d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4051:
	/* 0x4051: cmp    WORD PTR [r12+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_405b:
	/* 0x405b: je     407d <generic_sleepable_preload+0x407d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_407d;
	}
x86_l_405d:
	/* 0x405d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4060:
	/* 0x4060: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4065:
	/* 0x4065: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_406a:
	/* 0x406a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_406e:
	/* 0x406e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4073:
	/* 0x4073: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4075:
	/* 0x4075: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4077:
	/* 0x4077: js     4b36 <generic_sleepable_preload+0x4b36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19254ULL;
	}
x86_l_407d:
	/* 0x407d: cmp    WORD PTR [r12+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_4087:
	/* 0x4087: je     4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19262ULL;
	}
x86_l_408d:
	/* 0x408d: mov    ecx,DWORD PTR [r12+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_4095:
	/* 0x4095: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4099:
	/* 0x4099: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_409d:
	/* 0x409d: cmp    WORD PTR [r12+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_40a7:
	/* 0x40a7: je     40c9 <generic_sleepable_preload+0x40c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40c9;
	}
x86_l_40a9:
	/* 0x40a9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_40ac:
	/* 0x40ac: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_40b1:
	/* 0x40b1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_40b6:
	/* 0x40b6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40ba:
	/* 0x40ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_40bf:
	/* 0x40bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40c1:
	/* 0x40c1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_40c3:
	/* 0x40c3: js     5c1e <generic_sleepable_preload+0x5c1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23582ULL;
	}
x86_l_40c9:
	/* 0x40c9: cmp    WORD PTR [r12+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_40d3:
	/* 0x40d3: je     4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19262ULL;
	}
x86_l_40d9:
	/* 0x40d9: mov    ecx,DWORD PTR [r12+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_40e1:
	/* 0x40e1: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_40e5:
	/* 0x40e5: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40e9:
	/* 0x40e9: cmp    WORD PTR [r12+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_40f3:
	/* 0x40f3: je     4115 <generic_sleepable_preload+0x4115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4115;
	}
x86_l_40f5:
	/* 0x40f5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_40f8:
	/* 0x40f8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_40fd:
	/* 0x40fd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4102:
	/* 0x4102: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4106:
	/* 0x4106: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_410b:
	/* 0x410b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_410d:
	/* 0x410d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_410f:
	/* 0x410f: js     5d22 <generic_sleepable_preload+0x5d22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23842ULL;
	}
x86_l_4115:
	/* 0x4115: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_411a:
	/* 0x411a: cmp    WORD PTR [r12+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_4124:
	/* 0x4124: je     4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19262ULL;
	}
x86_l_412a:
	/* 0x412a: mov    ecx,DWORD PTR [r12+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_4132:
	/* 0x4132: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4136:
	/* 0x4136: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_413a:
	/* 0x413a: cmp    WORD PTR [r12+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_4144:
	/* 0x4144: je     4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19262ULL;
	}
x86_l_414a:
	/* 0x414a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_414d:
	/* 0x414d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4152:
	/* 0x4152: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4157:
	/* 0x4157: jmp    4431 <generic_sleepable_preload+0x4431> */
	goto x86_l_4431;
x86_l_415c:
	/* 0x415c: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_415f:
	/* 0x415f: je     4181 <generic_sleepable_preload+0x4181> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4181;
	}
x86_l_4161:
	/* 0x4161: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4164:
	/* 0x4164: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4169:
	/* 0x4169: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_416e:
	/* 0x416e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4172:
	/* 0x4172: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4177:
	/* 0x4177: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4179:
	/* 0x4179: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_417b:
	/* 0x417b: js     444e <generic_sleepable_preload+0x444e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_444e;
	}
x86_l_4181:
	/* 0x4181: cmp    WORD PTR [r12+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_418b:
	/* 0x418b: je     4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19262ULL;
	}
x86_l_4191:
	/* 0x4191: mov    ecx,DWORD PTR [r12+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_4199:
	/* 0x4199: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_419d:
	/* 0x419d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41a1:
	/* 0x41a1: cmp    WORD PTR [r12+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_41ab:
	/* 0x41ab: je     41cd <generic_sleepable_preload+0x41cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41cd;
	}
x86_l_41ad:
	/* 0x41ad: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_41b0:
	/* 0x41b0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_41b5:
	/* 0x41b5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_41ba:
	/* 0x41ba: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41be:
	/* 0x41be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41c3:
	/* 0x41c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41c5:
	/* 0x41c5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_41c7:
	/* 0x41c7: js     44b6 <generic_sleepable_preload+0x44b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_44b6;
	}
x86_l_41cd:
	/* 0x41cd: cmp    WORD PTR [r12+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_41d7:
	/* 0x41d7: je     4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19262ULL;
	}
x86_l_41dd:
	/* 0x41dd: mov    ecx,DWORD PTR [r12+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_41e5:
	/* 0x41e5: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_41e9:
	/* 0x41e9: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41ed:
	/* 0x41ed: cmp    WORD PTR [r12+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_41f7:
	/* 0x41f7: je     4219 <generic_sleepable_preload+0x4219> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4219;
	}
x86_l_41f9:
	/* 0x41f9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_41fc:
	/* 0x41fc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4201:
	/* 0x4201: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4206:
	/* 0x4206: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_420a:
	/* 0x420a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_420f:
	/* 0x420f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4211:
	/* 0x4211: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4213:
	/* 0x4213: js     4af2 <generic_sleepable_preload+0x4af2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19186ULL;
	}
x86_l_4219:
	/* 0x4219: cmp    WORD PTR [r12+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_4223:
	/* 0x4223: je     4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19262ULL;
	}
x86_l_4229:
	/* 0x4229: mov    ecx,DWORD PTR [r12+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_4231:
	/* 0x4231: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4235:
	/* 0x4235: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4239:
	/* 0x4239: cmp    WORD PTR [r12+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_4243:
	/* 0x4243: je     4265 <generic_sleepable_preload+0x4265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4265;
	}
x86_l_4245:
	/* 0x4245: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4248:
	/* 0x4248: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_424d:
	/* 0x424d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4252:
	/* 0x4252: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4256:
	/* 0x4256: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_425b:
	/* 0x425b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_425d:
	/* 0x425d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_425f:
	/* 0x425f: js     4b03 <generic_sleepable_preload+0x4b03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19203ULL;
	}
x86_l_4265:
	/* 0x4265: cmp    WORD PTR [r12+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_426f:
	/* 0x426f: je     4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19262ULL;
	}
x86_l_4275:
	/* 0x4275: mov    ecx,DWORD PTR [r12+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_427d:
	/* 0x427d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4281:
	/* 0x4281: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4285:
	/* 0x4285: cmp    WORD PTR [r12+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_428f:
	/* 0x428f: je     42b1 <generic_sleepable_preload+0x42b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42b1;
	}
x86_l_4291:
	/* 0x4291: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4294:
	/* 0x4294: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4299:
	/* 0x4299: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_429e:
	/* 0x429e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42a2:
	/* 0x42a2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42a7:
	/* 0x42a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42a9:
	/* 0x42a9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42ab:
	/* 0x42ab: js     4b14 <generic_sleepable_preload+0x4b14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19220ULL;
	}
x86_l_42b1:
	/* 0x42b1: cmp    WORD PTR [r12+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_42bb:
	/* 0x42bb: je     4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19262ULL;
	}
x86_l_42c1:
	/* 0x42c1: mov    ecx,DWORD PTR [r12+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_42c9:
	/* 0x42c9: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_42cd:
	/* 0x42cd: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42d1:
	/* 0x42d1: cmp    WORD PTR [r12+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_42db:
	/* 0x42db: je     42fd <generic_sleepable_preload+0x42fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42fd;
	}
x86_l_42dd:
	/* 0x42dd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_42e0:
	/* 0x42e0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_42e5:
	/* 0x42e5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_42ea:
	/* 0x42ea: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42ee:
	/* 0x42ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42f3:
	/* 0x42f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42f5:
	/* 0x42f5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42f7:
	/* 0x42f7: js     4b25 <generic_sleepable_preload+0x4b25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19237ULL;
	}
x86_l_42fd:
	/* 0x42fd: cmp    WORD PTR [r12+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_4307:
	/* 0x4307: je     4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19262ULL;
	}
x86_l_430d:
	/* 0x430d: mov    ecx,DWORD PTR [r12+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_4315:
	/* 0x4315: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4319:
	/* 0x4319: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_431d:
	/* 0x431d: cmp    WORD PTR [r12+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_4327:
	/* 0x4327: je     4349 <generic_sleepable_preload+0x4349> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4349;
	}
x86_l_4329:
	/* 0x4329: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_432c:
	/* 0x432c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4331:
	/* 0x4331: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4336:
	/* 0x4336: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_433a:
	/* 0x433a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_433f:
	/* 0x433f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4341:
	/* 0x4341: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4343:
	/* 0x4343: js     4b36 <generic_sleepable_preload+0x4b36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19254ULL;
	}
x86_l_4349:
	/* 0x4349: cmp    WORD PTR [r12+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_4353:
	/* 0x4353: je     4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19262ULL;
	}
x86_l_4359:
	/* 0x4359: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_435c:
	/* 0x435c: mov    ecx,DWORD PTR [r12+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_4364:
	/* 0x4364: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4368:
	/* 0x4368: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_436c:
	/* 0x436c: cmp    WORD PTR [r12+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_4376:
	/* 0x4376: je     4398 <generic_sleepable_preload+0x4398> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4398;
	}
x86_l_4378:
	/* 0x4378: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_437b:
	/* 0x437b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4380:
	/* 0x4380: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4385:
	/* 0x4385: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4389:
	/* 0x4389: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_438e:
	/* 0x438e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4390:
	/* 0x4390: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4392:
	/* 0x4392: js     5c9c <generic_sleepable_preload+0x5c9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23708ULL;
	}
x86_l_4398:
	/* 0x4398: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_439d:
	/* 0x439d: cmp    WORD PTR [r12+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_43a7:
	/* 0x43a7: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_43aa:
	/* 0x43aa: je     4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19262ULL;
	}
x86_l_43b0:
	/* 0x43b0: mov    ecx,DWORD PTR [r12+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_43b8:
	/* 0x43b8: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_43bc:
	/* 0x43bc: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43c0:
	/* 0x43c0: cmp    WORD PTR [r12+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_43ca:
	/* 0x43ca: je     43ec <generic_sleepable_preload+0x43ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43ec;
	}
x86_l_43cc:
	/* 0x43cc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_43cf:
	/* 0x43cf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_43d4:
	/* 0x43d4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_43d9:
	/* 0x43d9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43dd:
	/* 0x43dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_43e2:
	/* 0x43e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43e4:
	/* 0x43e4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_43e6:
	/* 0x43e6: js     5dc4 <generic_sleepable_preload+0x5dc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24004ULL;
	}
x86_l_43ec:
	/* 0x43ec: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43f1:
	/* 0x43f1: cmp    WORD PTR [r12+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_43fb:
	/* 0x43fb: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_43fe:
	/* 0x43fe: je     4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19262ULL;
	}
x86_l_4404:
	/* 0x4404: mov    ecx,DWORD PTR [r12+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_440c:
	/* 0x440c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4410:
	/* 0x4410: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4414:
	/* 0x4414: cmp    WORD PTR [r12+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_441e:
	/* 0x441e: je     4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19262ULL;
	}
x86_l_4424:
	/* 0x4424: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4427:
	/* 0x4427: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_442c:
	/* 0x442c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4431:
	/* 0x4431: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4435:
	/* 0x4435: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_443a:
	/* 0x443a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_443c:
	/* 0x443c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_443e:
	/* 0x443e: jns    4b3e <generic_sleepable_preload+0x4b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 19262ULL;
	}
x86_l_4444:
	/* 0x4444: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_4449:
	/* 0x4449: jmp    4b3b <generic_sleepable_preload+0x4b3b> */
	return 19259ULL;
x86_l_444e:
	/* 0x444e: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_4453:
	/* 0x4453: jmp    4b3b <generic_sleepable_preload+0x4b3b> */
	return 19259ULL;
x86_l_4458:
	/* 0x4458: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4460:
	/* 0x4460: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_4463:
	/* 0x4463: je     44c5 <generic_sleepable_preload+0x44c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c5;
	}
x86_l_4465:
	/* 0x4465: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_446a:
	/* 0x446a: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_446d:
	/* 0x446d: je     44c5 <generic_sleepable_preload+0x44c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c5;
	}
x86_l_446f:
	/* 0x446f: jmp    44d8 <generic_sleepable_preload+0x44d8> */
	goto x86_l_44d8;
x86_l_4471:
	/* 0x4471: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4476:
	/* 0x4476: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_4479:
	/* 0x4479: je     44c5 <generic_sleepable_preload+0x44c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c5;
	}
x86_l_447b:
	/* 0x447b: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4480:
	/* 0x4480: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4483:
	/* 0x4483: je     44c5 <generic_sleepable_preload+0x44c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c5;
	}
x86_l_4485:
	/* 0x4485: jmp    44d8 <generic_sleepable_preload+0x44d8> */
	goto x86_l_44d8;
x86_l_4487:
	/* 0x4487: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_448f:
	/* 0x448f: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_4492:
	/* 0x4492: je     44c5 <generic_sleepable_preload+0x44c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c5;
	}
x86_l_4494:
	/* 0x4494: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4499:
	/* 0x4499: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_449c:
	/* 0x449c: je     44c5 <generic_sleepable_preload+0x44c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c5;
	}
x86_l_449e:
	/* 0x449e: jmp    44d8 <generic_sleepable_preload+0x44d8> */
	goto x86_l_44d8;
x86_l_44a0:
	/* 0x44a0: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_44a5:
	/* 0x44a5: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_44a8:
	/* 0x44a8: je     44c5 <generic_sleepable_preload+0x44c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c5;
	}
x86_l_44aa:
	/* 0x44aa: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_44af:
	/* 0x44af: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_44b2:
	/* 0x44b2: je     44c5 <generic_sleepable_preload+0x44c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c5;
	}
x86_l_44b4:
	/* 0x44b4: jmp    44d8 <generic_sleepable_preload+0x44d8> */
	goto x86_l_44d8;
x86_l_44b6:
	/* 0x44b6: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_44bb:
	/* 0x44bb: jmp    4b3b <generic_sleepable_preload+0x4b3b> */
	return 19259ULL;
x86_l_44c0:
	/* 0x44c0: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_44c5:
	/* 0x44c5: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_44c8:
	/* 0x44c8: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_44ca:
	/* 0x44ca: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_44cc:
	/* 0x44cc: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_44d1:
	/* 0x44d1: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_44d3:
	/* 0x44d3: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_44d8:
	/* 0x44d8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44dc:
	/* 0x44dc: mov    ebp,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 17633ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 17633ULL: goto x86_l_44e1;
	case 17635ULL: goto x86_l_44e3;
	case 17638ULL: goto x86_l_44e6;
	case 17648ULL: goto x86_l_44f0;
	case 17654ULL: goto x86_l_44f6;
	case 17661ULL: goto x86_l_44fd;
	case 17664ULL: goto x86_l_4500;
	case 17672ULL: goto x86_l_4508;
	case 17675ULL: goto x86_l_450b;
	case 17679ULL: goto x86_l_450f;
	case 17688ULL: goto x86_l_4518;
	case 17690ULL: goto x86_l_451a;
	case 17696ULL: goto x86_l_4520;
	case 17699ULL: goto x86_l_4523;
	case 17701ULL: goto x86_l_4525;
	case 17704ULL: goto x86_l_4528;
	case 17709ULL: goto x86_l_452d;
	case 17714ULL: goto x86_l_4532;
	case 17718ULL: goto x86_l_4536;
	case 17723ULL: goto x86_l_453b;
	case 17725ULL: goto x86_l_453d;
	case 17727ULL: goto x86_l_453f;
	case 17733ULL: goto x86_l_4545;
	case 17743ULL: goto x86_l_454f;
	case 17749ULL: goto x86_l_4555;
	case 17757ULL: goto x86_l_455d;
	case 17761ULL: goto x86_l_4561;
	case 17765ULL: goto x86_l_4565;
	case 17775ULL: goto x86_l_456f;
	case 17777ULL: goto x86_l_4571;
	case 17780ULL: goto x86_l_4574;
	case 17785ULL: goto x86_l_4579;
	case 17790ULL: goto x86_l_457e;
	case 17794ULL: goto x86_l_4582;
	case 17799ULL: goto x86_l_4587;
	case 17801ULL: goto x86_l_4589;
	case 17803ULL: goto x86_l_458b;
	case 17809ULL: goto x86_l_4591;
	case 17819ULL: goto x86_l_459b;
	case 17825ULL: goto x86_l_45a1;
	case 17833ULL: goto x86_l_45a9;
	case 17837ULL: goto x86_l_45ad;
	case 17841ULL: goto x86_l_45b1;
	case 17851ULL: goto x86_l_45bb;
	case 17853ULL: goto x86_l_45bd;
	case 17856ULL: goto x86_l_45c0;
	case 17861ULL: goto x86_l_45c5;
	case 17866ULL: goto x86_l_45ca;
	case 17870ULL: goto x86_l_45ce;
	case 17875ULL: goto x86_l_45d3;
	case 17877ULL: goto x86_l_45d5;
	case 17879ULL: goto x86_l_45d7;
	case 17885ULL: goto x86_l_45dd;
	case 17895ULL: goto x86_l_45e7;
	case 17901ULL: goto x86_l_45ed;
	case 17909ULL: goto x86_l_45f5;
	case 17913ULL: goto x86_l_45f9;
	case 17917ULL: goto x86_l_45fd;
	case 17927ULL: goto x86_l_4607;
	case 17929ULL: goto x86_l_4609;
	case 17932ULL: goto x86_l_460c;
	case 17937ULL: goto x86_l_4611;
	case 17942ULL: goto x86_l_4616;
	case 17946ULL: goto x86_l_461a;
	case 17951ULL: goto x86_l_461f;
	case 17953ULL: goto x86_l_4621;
	case 17955ULL: goto x86_l_4623;
	case 17961ULL: goto x86_l_4629;
	case 17971ULL: goto x86_l_4633;
	case 17977ULL: goto x86_l_4639;
	case 17985ULL: goto x86_l_4641;
	case 17989ULL: goto x86_l_4645;
	case 17993ULL: goto x86_l_4649;
	case 18003ULL: goto x86_l_4653;
	case 18005ULL: goto x86_l_4655;
	case 18008ULL: goto x86_l_4658;
	case 18013ULL: goto x86_l_465d;
	case 18018ULL: goto x86_l_4662;
	case 18022ULL: goto x86_l_4666;
	case 18027ULL: goto x86_l_466b;
	case 18029ULL: goto x86_l_466d;
	case 18031ULL: goto x86_l_466f;
	case 18037ULL: goto x86_l_4675;
	case 18047ULL: goto x86_l_467f;
	case 18053ULL: goto x86_l_4685;
	case 18061ULL: goto x86_l_468d;
	case 18065ULL: goto x86_l_4691;
	case 18069ULL: goto x86_l_4695;
	case 18079ULL: goto x86_l_469f;
	case 18081ULL: goto x86_l_46a1;
	case 18084ULL: goto x86_l_46a4;
	case 18089ULL: goto x86_l_46a9;
	case 18094ULL: goto x86_l_46ae;
	case 18098ULL: goto x86_l_46b2;
	case 18103ULL: goto x86_l_46b7;
	case 18105ULL: goto x86_l_46b9;
	case 18107ULL: goto x86_l_46bb;
	case 18113ULL: goto x86_l_46c1;
	case 18123ULL: goto x86_l_46cb;
	case 18129ULL: goto x86_l_46d1;
	case 18137ULL: goto x86_l_46d9;
	case 18141ULL: goto x86_l_46dd;
	case 18145ULL: goto x86_l_46e1;
	case 18155ULL: goto x86_l_46eb;
	case 18157ULL: goto x86_l_46ed;
	case 18160ULL: goto x86_l_46f0;
	case 18165ULL: goto x86_l_46f5;
	case 18170ULL: goto x86_l_46fa;
	case 18174ULL: goto x86_l_46fe;
	case 18179ULL: goto x86_l_4703;
	case 18181ULL: goto x86_l_4705;
	case 18183ULL: goto x86_l_4707;
	case 18189ULL: goto x86_l_470d;
	case 18199ULL: goto x86_l_4717;
	case 18205ULL: goto x86_l_471d;
	case 18213ULL: goto x86_l_4725;
	case 18217ULL: goto x86_l_4729;
	case 18221ULL: goto x86_l_472d;
	case 18231ULL: goto x86_l_4737;
	case 18233ULL: goto x86_l_4739;
	case 18236ULL: goto x86_l_473c;
	case 18241ULL: goto x86_l_4741;
	case 18246ULL: goto x86_l_4746;
	case 18250ULL: goto x86_l_474a;
	case 18255ULL: goto x86_l_474f;
	case 18257ULL: goto x86_l_4751;
	case 18259ULL: goto x86_l_4753;
	case 18265ULL: goto x86_l_4759;
	case 18275ULL: goto x86_l_4763;
	case 18281ULL: goto x86_l_4769;
	case 18289ULL: goto x86_l_4771;
	case 18293ULL: goto x86_l_4775;
	case 18297ULL: goto x86_l_4779;
	case 18307ULL: goto x86_l_4783;
	case 18309ULL: goto x86_l_4785;
	case 18312ULL: goto x86_l_4788;
	case 18317ULL: goto x86_l_478d;
	case 18322ULL: goto x86_l_4792;
	case 18326ULL: goto x86_l_4796;
	case 18331ULL: goto x86_l_479b;
	case 18333ULL: goto x86_l_479d;
	case 18335ULL: goto x86_l_479f;
	case 18341ULL: goto x86_l_47a5;
	case 18346ULL: goto x86_l_47aa;
	case 18356ULL: goto x86_l_47b4;
	case 18362ULL: goto x86_l_47ba;
	case 18370ULL: goto x86_l_47c2;
	case 18374ULL: goto x86_l_47c6;
	case 18378ULL: goto x86_l_47ca;
	case 18388ULL: goto x86_l_47d4;
	case 18394ULL: goto x86_l_47da;
	case 18397ULL: goto x86_l_47dd;
	case 18402ULL: goto x86_l_47e2;
	case 18407ULL: goto x86_l_47e7;
	case 18412ULL: goto x86_l_47ec;
	case 18415ULL: goto x86_l_47ef;
	case 18417ULL: goto x86_l_47f1;
	case 18420ULL: goto x86_l_47f4;
	case 18425ULL: goto x86_l_47f9;
	case 18430ULL: goto x86_l_47fe;
	case 18434ULL: goto x86_l_4802;
	case 18439ULL: goto x86_l_4807;
	case 18441ULL: goto x86_l_4809;
	case 18443ULL: goto x86_l_480b;
	case 18449ULL: goto x86_l_4811;
	case 18459ULL: goto x86_l_481b;
	case 18465ULL: goto x86_l_4821;
	case 18473ULL: goto x86_l_4829;
	case 18477ULL: goto x86_l_482d;
	case 18481ULL: goto x86_l_4831;
	case 18491ULL: goto x86_l_483b;
	case 18493ULL: goto x86_l_483d;
	case 18496ULL: goto x86_l_4840;
	case 18501ULL: goto x86_l_4845;
	case 18506ULL: goto x86_l_484a;
	case 18510ULL: goto x86_l_484e;
	case 18515ULL: goto x86_l_4853;
	case 18517ULL: goto x86_l_4855;
	case 18519ULL: goto x86_l_4857;
	case 18525ULL: goto x86_l_485d;
	case 18535ULL: goto x86_l_4867;
	case 18541ULL: goto x86_l_486d;
	case 18549ULL: goto x86_l_4875;
	case 18553ULL: goto x86_l_4879;
	case 18557ULL: goto x86_l_487d;
	case 18567ULL: goto x86_l_4887;
	case 18569ULL: goto x86_l_4889;
	case 18572ULL: goto x86_l_488c;
	case 18577ULL: goto x86_l_4891;
	case 18582ULL: goto x86_l_4896;
	case 18586ULL: goto x86_l_489a;
	case 18591ULL: goto x86_l_489f;
	case 18593ULL: goto x86_l_48a1;
	case 18595ULL: goto x86_l_48a3;
	case 18601ULL: goto x86_l_48a9;
	case 18611ULL: goto x86_l_48b3;
	case 18617ULL: goto x86_l_48b9;
	case 18625ULL: goto x86_l_48c1;
	case 18629ULL: goto x86_l_48c5;
	case 18633ULL: goto x86_l_48c9;
	case 18643ULL: goto x86_l_48d3;
	case 18645ULL: goto x86_l_48d5;
	case 18648ULL: goto x86_l_48d8;
	case 18653ULL: goto x86_l_48dd;
	case 18658ULL: goto x86_l_48e2;
	case 18662ULL: goto x86_l_48e6;
	case 18667ULL: goto x86_l_48eb;
	case 18669ULL: goto x86_l_48ed;
	case 18671ULL: goto x86_l_48ef;
	case 18677ULL: goto x86_l_48f5;
	case 18687ULL: goto x86_l_48ff;
	case 18693ULL: goto x86_l_4905;
	case 18701ULL: goto x86_l_490d;
	case 18705ULL: goto x86_l_4911;
	case 18709ULL: goto x86_l_4915;
	case 18719ULL: goto x86_l_491f;
	case 18721ULL: goto x86_l_4921;
	case 18724ULL: goto x86_l_4924;
	case 18729ULL: goto x86_l_4929;
	case 18734ULL: goto x86_l_492e;
	case 18738ULL: goto x86_l_4932;
	case 18743ULL: goto x86_l_4937;
	case 18745ULL: goto x86_l_4939;
	case 18747ULL: goto x86_l_493b;
	case 18753ULL: goto x86_l_4941;
	case 18763ULL: goto x86_l_494b;
	case 18769ULL: goto x86_l_4951;
	case 18777ULL: goto x86_l_4959;
	case 18781ULL: goto x86_l_495d;
	case 18785ULL: goto x86_l_4961;
	case 18795ULL: goto x86_l_496b;
	case 18797ULL: goto x86_l_496d;
	case 18800ULL: goto x86_l_4970;
	case 18805ULL: goto x86_l_4975;
	case 18810ULL: goto x86_l_497a;
	case 18814ULL: goto x86_l_497e;
	case 18819ULL: goto x86_l_4983;
	case 18821ULL: goto x86_l_4985;
	case 18823ULL: goto x86_l_4987;
	case 18829ULL: goto x86_l_498d;
	case 18839ULL: goto x86_l_4997;
	case 18845ULL: goto x86_l_499d;
	case 18853ULL: goto x86_l_49a5;
	case 18857ULL: goto x86_l_49a9;
	case 18861ULL: goto x86_l_49ad;
	case 18871ULL: goto x86_l_49b7;
	case 18873ULL: goto x86_l_49b9;
	case 18876ULL: goto x86_l_49bc;
	case 18881ULL: goto x86_l_49c1;
	case 18886ULL: goto x86_l_49c6;
	case 18890ULL: goto x86_l_49ca;
	case 18895ULL: goto x86_l_49cf;
	case 18897ULL: goto x86_l_49d1;
	case 18899ULL: goto x86_l_49d3;
	case 18905ULL: goto x86_l_49d9;
	case 18915ULL: goto x86_l_49e3;
	case 18921ULL: goto x86_l_49e9;
	case 18924ULL: goto x86_l_49ec;
	case 18932ULL: goto x86_l_49f4;
	case 18936ULL: goto x86_l_49f8;
	case 18940ULL: goto x86_l_49fc;
	case 18950ULL: goto x86_l_4a06;
	case 18952ULL: goto x86_l_4a08;
	case 18955ULL: goto x86_l_4a0b;
	case 18960ULL: goto x86_l_4a10;
	case 18965ULL: goto x86_l_4a15;
	case 18969ULL: goto x86_l_4a19;
	case 18974ULL: goto x86_l_4a1e;
	case 18976ULL: goto x86_l_4a20;
	case 18978ULL: goto x86_l_4a22;
	case 18984ULL: goto x86_l_4a28;
	case 18989ULL: goto x86_l_4a2d;
	case 18999ULL: goto x86_l_4a37;
	case 19002ULL: goto x86_l_4a3a;
	case 19008ULL: goto x86_l_4a40;
	case 19016ULL: goto x86_l_4a48;
	case 19020ULL: goto x86_l_4a4c;
	case 19024ULL: goto x86_l_4a50;
	case 19034ULL: goto x86_l_4a5a;
	case 19036ULL: goto x86_l_4a5c;
	case 19039ULL: goto x86_l_4a5f;
	case 19044ULL: goto x86_l_4a64;
	case 19049ULL: goto x86_l_4a69;
	case 19053ULL: goto x86_l_4a6d;
	case 19058ULL: goto x86_l_4a72;
	case 19060ULL: goto x86_l_4a74;
	case 19062ULL: goto x86_l_4a76;
	case 19068ULL: goto x86_l_4a7c;
	case 19073ULL: goto x86_l_4a81;
	case 19083ULL: goto x86_l_4a8b;
	case 19086ULL: goto x86_l_4a8e;
	case 19092ULL: goto x86_l_4a94;
	case 19100ULL: goto x86_l_4a9c;
	case 19104ULL: goto x86_l_4aa0;
	case 19108ULL: goto x86_l_4aa4;
	case 19118ULL: goto x86_l_4aae;
	case 19124ULL: goto x86_l_4ab4;
	case 19127ULL: goto x86_l_4ab7;
	case 19132ULL: goto x86_l_4abc;
	case 19137ULL: goto x86_l_4ac1;
	case 19141ULL: goto x86_l_4ac5;
	case 19146ULL: goto x86_l_4aca;
	case 19148ULL: goto x86_l_4acc;
	case 19150ULL: goto x86_l_4ace;
	case 19156ULL: goto x86_l_4ad4;
	case 19161ULL: goto x86_l_4ad9;
	case 19166ULL: goto x86_l_4ade;
	case 19171ULL: goto x86_l_4ae3;
	case 19176ULL: goto x86_l_4ae8;
	case 19181ULL: goto x86_l_4aed;
	case 19186ULL: goto x86_l_4af2;
	case 19191ULL: goto x86_l_4af7;
	case 19193ULL: goto x86_l_4af9;
	case 19198ULL: goto x86_l_4afe;
	case 19203ULL: goto x86_l_4b03;
	case 19208ULL: goto x86_l_4b08;
	case 19210ULL: goto x86_l_4b0a;
	case 19215ULL: goto x86_l_4b0f;
	case 19220ULL: goto x86_l_4b14;
	case 19225ULL: goto x86_l_4b19;
	case 19227ULL: goto x86_l_4b1b;
	case 19232ULL: goto x86_l_4b20;
	case 19237ULL: goto x86_l_4b25;
	case 19242ULL: goto x86_l_4b2a;
	case 19244ULL: goto x86_l_4b2c;
	case 19249ULL: goto x86_l_4b31;
	case 19254ULL: goto x86_l_4b36;
	case 19259ULL: goto x86_l_4b3b;
	case 19262ULL: goto x86_l_4b3e;
	case 19267ULL: goto x86_l_4b43;
	case 19270ULL: goto x86_l_4b46;
	case 19275ULL: goto x86_l_4b4b;
	case 19280ULL: goto x86_l_4b50;
	case 19285ULL: goto x86_l_4b55;
	case 19288ULL: goto x86_l_4b58;
	case 19290ULL: goto x86_l_4b5a;
	case 19293ULL: goto x86_l_4b5d;
	case 19299ULL: goto x86_l_4b63;
	case 19302ULL: goto x86_l_4b66;
	case 19306ULL: goto x86_l_4b6a;
	case 19311ULL: goto x86_l_4b6f;
	case 19313ULL: goto x86_l_4b71;
	case 19318ULL: goto x86_l_4b76;
	case 19326ULL: goto x86_l_4b7e;
	case 19333ULL: goto x86_l_4b85;
	case 19338ULL: goto x86_l_4b8a;
	case 19343ULL: goto x86_l_4b8f;
	case 19345ULL: goto x86_l_4b91;
	case 19348ULL: goto x86_l_4b94;
	case 19354ULL: goto x86_l_4b9a;
	case 19357ULL: goto x86_l_4b9d;
	case 19364ULL: goto x86_l_4ba4;
	case 19366ULL: goto x86_l_4ba6;
	case 19371ULL: goto x86_l_4bab;
	case 19376ULL: goto x86_l_4bb0;
	case 19379ULL: goto x86_l_4bb3;
	case 19382ULL: goto x86_l_4bb6;
	case 19384ULL: goto x86_l_4bb8;
	case 19386ULL: goto x86_l_4bba;
	case 19391ULL: goto x86_l_4bbf;
	case 19393ULL: goto x86_l_4bc1;
	case 19398ULL: goto x86_l_4bc6;
	case 19401ULL: goto x86_l_4bc9;
	case 19404ULL: goto x86_l_4bcc;
	case 19410ULL: goto x86_l_4bd2;
	case 19413ULL: goto x86_l_4bd5;
	case 19417ULL: goto x86_l_4bd9;
	case 19422ULL: goto x86_l_4bde;
	case 19424ULL: goto x86_l_4be0;
	case 19429ULL: goto x86_l_4be5;
	case 19437ULL: goto x86_l_4bed;
	case 19444ULL: goto x86_l_4bf4;
	case 19449ULL: goto x86_l_4bf9;
	case 19454ULL: goto x86_l_4bfe;
	case 19456ULL: goto x86_l_4c00;
	case 19459ULL: goto x86_l_4c03;
	case 19461ULL: goto x86_l_4c05;
	case 19464ULL: goto x86_l_4c08;
	case 19471ULL: goto x86_l_4c0f;
	case 19473ULL: goto x86_l_4c11;
	case 19478ULL: goto x86_l_4c16;
	case 19483ULL: goto x86_l_4c1b;
	case 19486ULL: goto x86_l_4c1e;
	case 19489ULL: goto x86_l_4c21;
	default: return 0xffffffffffffffffULL;
	}
x86_l_44e1:
	/* 0x44e1: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_44e3:
	/* 0x44e3: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_44e6:
	/* 0x44e6: cmp    WORD PTR [r12+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_44f0:
	/* 0x44f0: je     4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc9;
	}
x86_l_44f6:
	/* 0x44f6: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_44fd:
	/* 0x44fd: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_4500:
	/* 0x4500: mov    eax,DWORD PTR [r12+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_4508:
	/* 0x4508: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_450b:
	/* 0x450b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_450f:
	/* 0x450f: movzx  eax,WORD PTR [r12+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_4518:
	/* 0x4518: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_451a:
	/* 0x451a: je     47ec <generic_sleepable_preload+0x47ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47ec;
	}
x86_l_4520:
	/* 0x4520: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4523:
	/* 0x4523: je     4545 <generic_sleepable_preload+0x4545> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4545;
	}
x86_l_4525:
	/* 0x4525: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4528:
	/* 0x4528: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_452d:
	/* 0x452d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4532:
	/* 0x4532: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4536:
	/* 0x4536: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_453b:
	/* 0x453b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_453d:
	/* 0x453d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_453f:
	/* 0x453f: js     4ade <generic_sleepable_preload+0x4ade> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ade;
	}
x86_l_4545:
	/* 0x4545: cmp    WORD PTR [r12+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_454f:
	/* 0x454f: je     4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc9;
	}
x86_l_4555:
	/* 0x4555: mov    ecx,DWORD PTR [r12+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_455d:
	/* 0x455d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4561:
	/* 0x4561: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4565:
	/* 0x4565: cmp    WORD PTR [r12+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_456f:
	/* 0x456f: je     4591 <generic_sleepable_preload+0x4591> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4591;
	}
x86_l_4571:
	/* 0x4571: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4574:
	/* 0x4574: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4579:
	/* 0x4579: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_457e:
	/* 0x457e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4582:
	/* 0x4582: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4587:
	/* 0x4587: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4589:
	/* 0x4589: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_458b:
	/* 0x458b: js     4ae8 <generic_sleepable_preload+0x4ae8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ae8;
	}
x86_l_4591:
	/* 0x4591: cmp    WORD PTR [r12+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_459b:
	/* 0x459b: je     4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc9;
	}
x86_l_45a1:
	/* 0x45a1: mov    ecx,DWORD PTR [r12+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_45a9:
	/* 0x45a9: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_45ad:
	/* 0x45ad: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45b1:
	/* 0x45b1: cmp    WORD PTR [r12+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_45bb:
	/* 0x45bb: je     45dd <generic_sleepable_preload+0x45dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45dd;
	}
x86_l_45bd:
	/* 0x45bd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_45c0:
	/* 0x45c0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_45c5:
	/* 0x45c5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_45ca:
	/* 0x45ca: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45ce:
	/* 0x45ce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45d3:
	/* 0x45d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45d5:
	/* 0x45d5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_45d7:
	/* 0x45d7: js     4af9 <generic_sleepable_preload+0x4af9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4af9;
	}
x86_l_45dd:
	/* 0x45dd: cmp    WORD PTR [r12+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_45e7:
	/* 0x45e7: je     4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc9;
	}
x86_l_45ed:
	/* 0x45ed: mov    ecx,DWORD PTR [r12+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_45f5:
	/* 0x45f5: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_45f9:
	/* 0x45f9: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45fd:
	/* 0x45fd: cmp    WORD PTR [r12+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_4607:
	/* 0x4607: je     4629 <generic_sleepable_preload+0x4629> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4629;
	}
x86_l_4609:
	/* 0x4609: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_460c:
	/* 0x460c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4611:
	/* 0x4611: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4616:
	/* 0x4616: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_461a:
	/* 0x461a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_461f:
	/* 0x461f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4621:
	/* 0x4621: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4623:
	/* 0x4623: js     4b0a <generic_sleepable_preload+0x4b0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b0a;
	}
x86_l_4629:
	/* 0x4629: cmp    WORD PTR [r12+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_4633:
	/* 0x4633: je     4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc9;
	}
x86_l_4639:
	/* 0x4639: mov    ecx,DWORD PTR [r12+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_4641:
	/* 0x4641: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4645:
	/* 0x4645: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4649:
	/* 0x4649: cmp    WORD PTR [r12+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_4653:
	/* 0x4653: je     4675 <generic_sleepable_preload+0x4675> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4675;
	}
x86_l_4655:
	/* 0x4655: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4658:
	/* 0x4658: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_465d:
	/* 0x465d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4662:
	/* 0x4662: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4666:
	/* 0x4666: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_466b:
	/* 0x466b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_466d:
	/* 0x466d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_466f:
	/* 0x466f: js     4b1b <generic_sleepable_preload+0x4b1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b1b;
	}
x86_l_4675:
	/* 0x4675: cmp    WORD PTR [r12+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_467f:
	/* 0x467f: je     4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc9;
	}
x86_l_4685:
	/* 0x4685: mov    ecx,DWORD PTR [r12+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_468d:
	/* 0x468d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4691:
	/* 0x4691: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4695:
	/* 0x4695: cmp    WORD PTR [r12+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_469f:
	/* 0x469f: je     46c1 <generic_sleepable_preload+0x46c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46c1;
	}
x86_l_46a1:
	/* 0x46a1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_46a4:
	/* 0x46a4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_46a9:
	/* 0x46a9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_46ae:
	/* 0x46ae: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46b2:
	/* 0x46b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46b7:
	/* 0x46b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46b9:
	/* 0x46b9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46bb:
	/* 0x46bb: js     4b2c <generic_sleepable_preload+0x4b2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b2c;
	}
x86_l_46c1:
	/* 0x46c1: cmp    WORD PTR [r12+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_46cb:
	/* 0x46cb: je     4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc9;
	}
x86_l_46d1:
	/* 0x46d1: mov    ecx,DWORD PTR [r12+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_46d9:
	/* 0x46d9: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_46dd:
	/* 0x46dd: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46e1:
	/* 0x46e1: cmp    WORD PTR [r12+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_46eb:
	/* 0x46eb: je     470d <generic_sleepable_preload+0x470d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_470d;
	}
x86_l_46ed:
	/* 0x46ed: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_46f0:
	/* 0x46f0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_46f5:
	/* 0x46f5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_46fa:
	/* 0x46fa: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46fe:
	/* 0x46fe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4703:
	/* 0x4703: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4705:
	/* 0x4705: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4707:
	/* 0x4707: js     4bc1 <generic_sleepable_preload+0x4bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4bc1;
	}
x86_l_470d:
	/* 0x470d: cmp    WORD PTR [r12+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_4717:
	/* 0x4717: je     4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc9;
	}
x86_l_471d:
	/* 0x471d: mov    ecx,DWORD PTR [r12+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_4725:
	/* 0x4725: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4729:
	/* 0x4729: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_472d:
	/* 0x472d: cmp    WORD PTR [r12+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_4737:
	/* 0x4737: je     4759 <generic_sleepable_preload+0x4759> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4759;
	}
x86_l_4739:
	/* 0x4739: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_473c:
	/* 0x473c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4741:
	/* 0x4741: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4746:
	/* 0x4746: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_474a:
	/* 0x474a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_474f:
	/* 0x474f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4751:
	/* 0x4751: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4753:
	/* 0x4753: js     5c2b <generic_sleepable_preload+0x5c2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23595ULL;
	}
x86_l_4759:
	/* 0x4759: cmp    WORD PTR [r12+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_4763:
	/* 0x4763: je     4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc9;
	}
x86_l_4769:
	/* 0x4769: mov    ecx,DWORD PTR [r12+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_4771:
	/* 0x4771: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4775:
	/* 0x4775: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4779:
	/* 0x4779: cmp    WORD PTR [r12+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_4783:
	/* 0x4783: je     47a5 <generic_sleepable_preload+0x47a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47a5;
	}
x86_l_4785:
	/* 0x4785: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4788:
	/* 0x4788: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_478d:
	/* 0x478d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4792:
	/* 0x4792: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4796:
	/* 0x4796: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_479b:
	/* 0x479b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_479d:
	/* 0x479d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_479f:
	/* 0x479f: js     5d34 <generic_sleepable_preload+0x5d34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23860ULL;
	}
x86_l_47a5:
	/* 0x47a5: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47aa:
	/* 0x47aa: cmp    WORD PTR [r12+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_47b4:
	/* 0x47b4: je     4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc9;
	}
x86_l_47ba:
	/* 0x47ba: mov    ecx,DWORD PTR [r12+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_47c2:
	/* 0x47c2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_47c6:
	/* 0x47c6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47ca:
	/* 0x47ca: cmp    WORD PTR [r12+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_47d4:
	/* 0x47d4: je     4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc9;
	}
x86_l_47da:
	/* 0x47da: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_47dd:
	/* 0x47dd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_47e2:
	/* 0x47e2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47e7:
	/* 0x47e7: jmp    4ac1 <generic_sleepable_preload+0x4ac1> */
	goto x86_l_4ac1;
x86_l_47ec:
	/* 0x47ec: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_47ef:
	/* 0x47ef: je     4811 <generic_sleepable_preload+0x4811> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4811;
	}
x86_l_47f1:
	/* 0x47f1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_47f4:
	/* 0x47f4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_47f9:
	/* 0x47f9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47fe:
	/* 0x47fe: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4802:
	/* 0x4802: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4807:
	/* 0x4807: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4809:
	/* 0x4809: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_480b:
	/* 0x480b: js     4ade <generic_sleepable_preload+0x4ade> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ade;
	}
x86_l_4811:
	/* 0x4811: cmp    WORD PTR [r12+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_481b:
	/* 0x481b: je     4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc9;
	}
x86_l_4821:
	/* 0x4821: mov    ecx,DWORD PTR [r12+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_4829:
	/* 0x4829: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_482d:
	/* 0x482d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4831:
	/* 0x4831: cmp    WORD PTR [r12+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_483b:
	/* 0x483b: je     485d <generic_sleepable_preload+0x485d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_485d;
	}
x86_l_483d:
	/* 0x483d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4840:
	/* 0x4840: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4845:
	/* 0x4845: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_484a:
	/* 0x484a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_484e:
	/* 0x484e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4853:
	/* 0x4853: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4855:
	/* 0x4855: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4857:
	/* 0x4857: js     4ae8 <generic_sleepable_preload+0x4ae8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ae8;
	}
x86_l_485d:
	/* 0x485d: cmp    WORD PTR [r12+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_4867:
	/* 0x4867: je     4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc9;
	}
x86_l_486d:
	/* 0x486d: mov    ecx,DWORD PTR [r12+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_4875:
	/* 0x4875: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4879:
	/* 0x4879: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_487d:
	/* 0x487d: cmp    WORD PTR [r12+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_4887:
	/* 0x4887: je     48a9 <generic_sleepable_preload+0x48a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48a9;
	}
x86_l_4889:
	/* 0x4889: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_488c:
	/* 0x488c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4891:
	/* 0x4891: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4896:
	/* 0x4896: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_489a:
	/* 0x489a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_489f:
	/* 0x489f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48a1:
	/* 0x48a1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48a3:
	/* 0x48a3: js     4af9 <generic_sleepable_preload+0x4af9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4af9;
	}
x86_l_48a9:
	/* 0x48a9: cmp    WORD PTR [r12+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_48b3:
	/* 0x48b3: je     4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc9;
	}
x86_l_48b9:
	/* 0x48b9: mov    ecx,DWORD PTR [r12+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_48c1:
	/* 0x48c1: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_48c5:
	/* 0x48c5: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48c9:
	/* 0x48c9: cmp    WORD PTR [r12+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_48d3:
	/* 0x48d3: je     48f5 <generic_sleepable_preload+0x48f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48f5;
	}
x86_l_48d5:
	/* 0x48d5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_48d8:
	/* 0x48d8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_48dd:
	/* 0x48dd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_48e2:
	/* 0x48e2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48e6:
	/* 0x48e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48eb:
	/* 0x48eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48ed:
	/* 0x48ed: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48ef:
	/* 0x48ef: js     4b0a <generic_sleepable_preload+0x4b0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b0a;
	}
x86_l_48f5:
	/* 0x48f5: cmp    WORD PTR [r12+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_48ff:
	/* 0x48ff: je     4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc9;
	}
x86_l_4905:
	/* 0x4905: mov    ecx,DWORD PTR [r12+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_490d:
	/* 0x490d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4911:
	/* 0x4911: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4915:
	/* 0x4915: cmp    WORD PTR [r12+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_491f:
	/* 0x491f: je     4941 <generic_sleepable_preload+0x4941> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4941;
	}
x86_l_4921:
	/* 0x4921: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4924:
	/* 0x4924: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4929:
	/* 0x4929: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_492e:
	/* 0x492e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4932:
	/* 0x4932: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4937:
	/* 0x4937: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4939:
	/* 0x4939: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_493b:
	/* 0x493b: js     4b1b <generic_sleepable_preload+0x4b1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b1b;
	}
x86_l_4941:
	/* 0x4941: cmp    WORD PTR [r12+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_494b:
	/* 0x494b: je     4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc9;
	}
x86_l_4951:
	/* 0x4951: mov    ecx,DWORD PTR [r12+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_4959:
	/* 0x4959: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_495d:
	/* 0x495d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4961:
	/* 0x4961: cmp    WORD PTR [r12+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_496b:
	/* 0x496b: je     498d <generic_sleepable_preload+0x498d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_498d;
	}
x86_l_496d:
	/* 0x496d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4970:
	/* 0x4970: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4975:
	/* 0x4975: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_497a:
	/* 0x497a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_497e:
	/* 0x497e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4983:
	/* 0x4983: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4985:
	/* 0x4985: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4987:
	/* 0x4987: js     4b2c <generic_sleepable_preload+0x4b2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b2c;
	}
x86_l_498d:
	/* 0x498d: cmp    WORD PTR [r12+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_4997:
	/* 0x4997: je     4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc9;
	}
x86_l_499d:
	/* 0x499d: mov    ecx,DWORD PTR [r12+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_49a5:
	/* 0x49a5: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_49a9:
	/* 0x49a9: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49ad:
	/* 0x49ad: cmp    WORD PTR [r12+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_49b7:
	/* 0x49b7: je     49d9 <generic_sleepable_preload+0x49d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49d9;
	}
x86_l_49b9:
	/* 0x49b9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_49bc:
	/* 0x49bc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_49c1:
	/* 0x49c1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_49c6:
	/* 0x49c6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49ca:
	/* 0x49ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49cf:
	/* 0x49cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49d1:
	/* 0x49d1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_49d3:
	/* 0x49d3: js     4bc1 <generic_sleepable_preload+0x4bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4bc1;
	}
x86_l_49d9:
	/* 0x49d9: cmp    WORD PTR [r12+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_49e3:
	/* 0x49e3: je     4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc9;
	}
x86_l_49e9:
	/* 0x49e9: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_49ec:
	/* 0x49ec: mov    ecx,DWORD PTR [r12+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_49f4:
	/* 0x49f4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_49f8:
	/* 0x49f8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49fc:
	/* 0x49fc: cmp    WORD PTR [r12+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_4a06:
	/* 0x4a06: je     4a28 <generic_sleepable_preload+0x4a28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a28;
	}
x86_l_4a08:
	/* 0x4a08: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4a0b:
	/* 0x4a0b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a10:
	/* 0x4a10: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a15:
	/* 0x4a15: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a19:
	/* 0x4a19: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a1e:
	/* 0x4a1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a20:
	/* 0x4a20: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a22:
	/* 0x4a22: js     5ca9 <generic_sleepable_preload+0x5ca9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23721ULL;
	}
x86_l_4a28:
	/* 0x4a28: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a2d:
	/* 0x4a2d: cmp    WORD PTR [r12+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_4a37:
	/* 0x4a37: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_4a3a:
	/* 0x4a3a: je     4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc9;
	}
x86_l_4a40:
	/* 0x4a40: mov    ecx,DWORD PTR [r12+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_4a48:
	/* 0x4a48: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4a4c:
	/* 0x4a4c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a50:
	/* 0x4a50: cmp    WORD PTR [r12+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_4a5a:
	/* 0x4a5a: je     4a7c <generic_sleepable_preload+0x4a7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a7c;
	}
x86_l_4a5c:
	/* 0x4a5c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4a5f:
	/* 0x4a5f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a64:
	/* 0x4a64: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a69:
	/* 0x4a69: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a6d:
	/* 0x4a6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a72:
	/* 0x4a72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a74:
	/* 0x4a74: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a76:
	/* 0x4a76: js     5dd9 <generic_sleepable_preload+0x5dd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24025ULL;
	}
x86_l_4a7c:
	/* 0x4a7c: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a81:
	/* 0x4a81: cmp    WORD PTR [r12+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_4a8b:
	/* 0x4a8b: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_4a8e:
	/* 0x4a8e: je     4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc9;
	}
x86_l_4a94:
	/* 0x4a94: mov    ecx,DWORD PTR [r12+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_4a9c:
	/* 0x4a9c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4aa0:
	/* 0x4aa0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4aa4:
	/* 0x4aa4: cmp    WORD PTR [r12+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_4aae:
	/* 0x4aae: je     4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc9;
	}
x86_l_4ab4:
	/* 0x4ab4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4ab7:
	/* 0x4ab7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4abc:
	/* 0x4abc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ac1:
	/* 0x4ac1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ac5:
	/* 0x4ac5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4aca:
	/* 0x4aca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4acc:
	/* 0x4acc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ace:
	/* 0x4ace: jns    4bc9 <generic_sleepable_preload+0x4bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_4bc9;
	}
x86_l_4ad4:
	/* 0x4ad4: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_4ad9:
	/* 0x4ad9: jmp    4bc6 <generic_sleepable_preload+0x4bc6> */
	goto x86_l_4bc6;
x86_l_4ade:
	/* 0x4ade: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_4ae3:
	/* 0x4ae3: jmp    4bc6 <generic_sleepable_preload+0x4bc6> */
	goto x86_l_4bc6;
x86_l_4ae8:
	/* 0x4ae8: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_4aed:
	/* 0x4aed: jmp    4bc6 <generic_sleepable_preload+0x4bc6> */
	goto x86_l_4bc6;
x86_l_4af2:
	/* 0x4af2: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_4af7:
	/* 0x4af7: jmp    4b3b <generic_sleepable_preload+0x4b3b> */
	goto x86_l_4b3b;
x86_l_4af9:
	/* 0x4af9: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_4afe:
	/* 0x4afe: jmp    4bc6 <generic_sleepable_preload+0x4bc6> */
	goto x86_l_4bc6;
x86_l_4b03:
	/* 0x4b03: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_4b08:
	/* 0x4b08: jmp    4b3b <generic_sleepable_preload+0x4b3b> */
	goto x86_l_4b3b;
x86_l_4b0a:
	/* 0x4b0a: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_4b0f:
	/* 0x4b0f: jmp    4bc6 <generic_sleepable_preload+0x4bc6> */
	goto x86_l_4bc6;
x86_l_4b14:
	/* 0x4b14: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_4b19:
	/* 0x4b19: jmp    4b3b <generic_sleepable_preload+0x4b3b> */
	goto x86_l_4b3b;
x86_l_4b1b:
	/* 0x4b1b: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_4b20:
	/* 0x4b20: jmp    4bc6 <generic_sleepable_preload+0x4bc6> */
	goto x86_l_4bc6;
x86_l_4b25:
	/* 0x4b25: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_4b2a:
	/* 0x4b2a: jmp    4b3b <generic_sleepable_preload+0x4b3b> */
	goto x86_l_4b3b;
x86_l_4b2c:
	/* 0x4b2c: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_4b31:
	/* 0x4b31: jmp    4bc6 <generic_sleepable_preload+0x4bc6> */
	goto x86_l_4bc6;
x86_l_4b36:
	/* 0x4b36: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_4b3b:
	/* 0x4b3b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4b3e:
	/* 0x4b3e: mov    ebp,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b43:
	/* 0x4b43: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4b46:
	/* 0x4b46: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4b4b:
	/* 0x4b4b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4b50:
	/* 0x4b50: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b55:
	/* 0x4b55: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_4b58:
	/* 0x4b58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b5a:
	/* 0x4b5a: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_4b5d:
	/* 0x4b5d: jne    4c6e <generic_sleepable_preload+0x4c6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19566ULL;
	}
x86_l_4b63:
	/* 0x4b63: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_4b66:
	/* 0x4b66: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b6a:
	/* 0x4b6a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4b6f:
	/* 0x4b6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b71:
	/* 0x4b71: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b76:
	/* 0x4b76: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_4b7e:
	/* 0x4b7e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_4b85:
	/* 0x4b85: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4b8a:
	/* 0x4b8a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4b8f:
	/* 0x4b8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b91:
	/* 0x4b91: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b94:
	/* 0x4b94: je     4c6b <generic_sleepable_preload+0x4c6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19563ULL;
	}
x86_l_4b9a:
	/* 0x4b9a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4b9d:
	/* 0x4b9d: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_4ba4:
	/* 0x4ba4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ba6:
	/* 0x4ba6: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4bab:
	/* 0x4bab: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4bb0:
	/* 0x4bb0: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_4bb3:
	/* 0x4bb3: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_4bb6:
	/* 0x4bb6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4bb8:
	/* 0x4bb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bba:
	/* 0x4bba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4bbf:
	/* 0x4bbf: jmp    4c2a <generic_sleepable_preload+0x4c2a> */
	return 19498ULL;
x86_l_4bc1:
	/* 0x4bc1: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_4bc6:
	/* 0x4bc6: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4bc9:
	/* 0x4bc9: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_4bcc:
	/* 0x4bcc: jne    4c6e <generic_sleepable_preload+0x4c6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19566ULL;
	}
x86_l_4bd2:
	/* 0x4bd2: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_4bd5:
	/* 0x4bd5: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4bd9:
	/* 0x4bd9: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4bde:
	/* 0x4bde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4be0:
	/* 0x4be0: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4be5:
	/* 0x4be5: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_4bed:
	/* 0x4bed: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_4bf4:
	/* 0x4bf4: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4bf9:
	/* 0x4bf9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4bfe:
	/* 0x4bfe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c00:
	/* 0x4c00: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4c03:
	/* 0x4c03: je     4c6b <generic_sleepable_preload+0x4c6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19563ULL;
	}
x86_l_4c05:
	/* 0x4c05: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4c08:
	/* 0x4c08: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_4c0f:
	/* 0x4c0f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c11:
	/* 0x4c11: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4c16:
	/* 0x4c16: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4c1b:
	/* 0x4c1b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_4c1e:
	/* 0x4c1e: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_4c21:
	/* 0x4c21: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
	return 19491ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 19491ULL: goto x86_l_4c23;
	case 19493ULL: goto x86_l_4c25;
	case 19498ULL: goto x86_l_4c2a;
	case 19501ULL: goto x86_l_4c2d;
	case 19504ULL: goto x86_l_4c30;
	case 19509ULL: goto x86_l_4c35;
	case 19511ULL: goto x86_l_4c37;
	case 19514ULL: goto x86_l_4c3a;
	case 19516ULL: goto x86_l_4c3c;
	case 19519ULL: goto x86_l_4c3f;
	case 19521ULL: goto x86_l_4c41;
	case 19524ULL: goto x86_l_4c44;
	case 19528ULL: goto x86_l_4c48;
	case 19533ULL: goto x86_l_4c4d;
	case 19536ULL: goto x86_l_4c50;
	case 19538ULL: goto x86_l_4c52;
	case 19541ULL: goto x86_l_4c55;
	case 19546ULL: goto x86_l_4c5a;
	case 19548ULL: goto x86_l_4c5c;
	case 19551ULL: goto x86_l_4c5f;
	case 19553ULL: goto x86_l_4c61;
	case 19558ULL: goto x86_l_4c66;
	case 19561ULL: goto x86_l_4c69;
	case 19563ULL: goto x86_l_4c6b;
	case 19566ULL: goto x86_l_4c6e;
	case 19571ULL: goto x86_l_4c73;
	case 19576ULL: goto x86_l_4c78;
	case 19578ULL: goto x86_l_4c7a;
	case 19580ULL: goto x86_l_4c7c;
	case 19587ULL: goto x86_l_4c83;
	case 19588ULL: goto x86_l_4c84;
	case 19590ULL: goto x86_l_4c86;
	case 19592ULL: goto x86_l_4c88;
	case 19594ULL: goto x86_l_4c8a;
	case 19596ULL: goto x86_l_4c8c;
	case 19597ULL: goto x86_l_4c8d;
	case 19602ULL: goto x86_l_4c92;
	case 19604ULL: goto x86_l_4c94;
	case 19606ULL: goto x86_l_4c96;
	case 19611ULL: goto x86_l_4c9b;
	case 19614ULL: goto x86_l_4c9e;
	case 19620ULL: goto x86_l_4ca4;
	case 19623ULL: goto x86_l_4ca7;
	case 19629ULL: goto x86_l_4cad;
	case 19632ULL: goto x86_l_4cb0;
	case 19638ULL: goto x86_l_4cb6;
	case 19641ULL: goto x86_l_4cb9;
	case 19647ULL: goto x86_l_4cbf;
	case 19652ULL: goto x86_l_4cc4;
	case 19657ULL: goto x86_l_4cc9;
	case 19666ULL: goto x86_l_4cd2;
	case 19675ULL: goto x86_l_4cdb;
	case 19681ULL: goto x86_l_4ce1;
	case 19683ULL: goto x86_l_4ce3;
	case 19686ULL: goto x86_l_4ce6;
	case 19688ULL: goto x86_l_4ce8;
	case 19691ULL: goto x86_l_4ceb;
	case 19693ULL: goto x86_l_4ced;
	case 19696ULL: goto x86_l_4cf0;
	case 19702ULL: goto x86_l_4cf6;
	case 19707ULL: goto x86_l_4cfb;
	case 19710ULL: goto x86_l_4cfe;
	case 19716ULL: goto x86_l_4d04;
	case 19721ULL: goto x86_l_4d09;
	case 19724ULL: goto x86_l_4d0c;
	case 19730ULL: goto x86_l_4d12;
	case 19735ULL: goto x86_l_4d17;
	case 19738ULL: goto x86_l_4d1a;
	case 19744ULL: goto x86_l_4d20;
	case 19749ULL: goto x86_l_4d25;
	case 19752ULL: goto x86_l_4d28;
	case 19754ULL: goto x86_l_4d2a;
	case 19757ULL: goto x86_l_4d2d;
	case 19763ULL: goto x86_l_4d33;
	case 19765ULL: goto x86_l_4d35;
	case 19771ULL: goto x86_l_4d3b;
	case 19774ULL: goto x86_l_4d3e;
	case 19777ULL: goto x86_l_4d41;
	case 19783ULL: goto x86_l_4d47;
	case 19788ULL: goto x86_l_4d4c;
	case 19790ULL: goto x86_l_4d4e;
	case 19792ULL: goto x86_l_4d50;
	case 19795ULL: goto x86_l_4d53;
	case 19797ULL: goto x86_l_4d55;
	case 19802ULL: goto x86_l_4d5a;
	case 19804ULL: goto x86_l_4d5c;
	case 19807ULL: goto x86_l_4d5f;
	case 19813ULL: goto x86_l_4d65;
	case 19821ULL: goto x86_l_4d6d;
	case 19824ULL: goto x86_l_4d70;
	case 19830ULL: goto x86_l_4d76;
	case 19835ULL: goto x86_l_4d7b;
	case 19838ULL: goto x86_l_4d7e;
	case 19844ULL: goto x86_l_4d84;
	case 19849ULL: goto x86_l_4d89;
	case 19852ULL: goto x86_l_4d8c;
	case 19858ULL: goto x86_l_4d92;
	case 19866ULL: goto x86_l_4d9a;
	case 19869ULL: goto x86_l_4d9d;
	case 19875ULL: goto x86_l_4da3;
	case 19880ULL: goto x86_l_4da8;
	case 19883ULL: goto x86_l_4dab;
	case 19889ULL: goto x86_l_4db1;
	case 19894ULL: goto x86_l_4db6;
	case 19899ULL: goto x86_l_4dbb;
	case 19901ULL: goto x86_l_4dbd;
	case 19906ULL: goto x86_l_4dc2;
	case 19908ULL: goto x86_l_4dc4;
	case 19913ULL: goto x86_l_4dc9;
	case 19916ULL: goto x86_l_4dcc;
	case 19920ULL: goto x86_l_4dd0;
	case 19923ULL: goto x86_l_4dd3;
	case 19926ULL: goto x86_l_4dd6;
	case 19931ULL: goto x86_l_4ddb;
	case 19939ULL: goto x86_l_4de3;
	case 19945ULL: goto x86_l_4de9;
	case 19952ULL: goto x86_l_4df0;
	case 19955ULL: goto x86_l_4df3;
	case 19961ULL: goto x86_l_4df9;
	case 19964ULL: goto x86_l_4dfc;
	case 19968ULL: goto x86_l_4e00;
	case 19975ULL: goto x86_l_4e07;
	case 19977ULL: goto x86_l_4e09;
	case 19983ULL: goto x86_l_4e0f;
	case 19986ULL: goto x86_l_4e12;
	case 19988ULL: goto x86_l_4e14;
	case 19991ULL: goto x86_l_4e17;
	case 19996ULL: goto x86_l_4e1c;
	case 20001ULL: goto x86_l_4e21;
	case 20005ULL: goto x86_l_4e25;
	case 20010ULL: goto x86_l_4e2a;
	case 20012ULL: goto x86_l_4e2c;
	case 20014ULL: goto x86_l_4e2e;
	case 20020ULL: goto x86_l_4e34;
	case 20025ULL: goto x86_l_4e39;
	case 20033ULL: goto x86_l_4e41;
	case 20039ULL: goto x86_l_4e47;
	case 20045ULL: goto x86_l_4e4d;
	case 20049ULL: goto x86_l_4e51;
	case 20053ULL: goto x86_l_4e55;
	case 20061ULL: goto x86_l_4e5d;
	case 20063ULL: goto x86_l_4e5f;
	case 20066ULL: goto x86_l_4e62;
	case 20071ULL: goto x86_l_4e67;
	case 20076ULL: goto x86_l_4e6c;
	case 20080ULL: goto x86_l_4e70;
	case 20085ULL: goto x86_l_4e75;
	case 20087ULL: goto x86_l_4e77;
	case 20089ULL: goto x86_l_4e79;
	case 20095ULL: goto x86_l_4e7f;
	case 20100ULL: goto x86_l_4e84;
	case 20108ULL: goto x86_l_4e8c;
	case 20114ULL: goto x86_l_4e92;
	case 20120ULL: goto x86_l_4e98;
	case 20124ULL: goto x86_l_4e9c;
	case 20128ULL: goto x86_l_4ea0;
	case 20136ULL: goto x86_l_4ea8;
	case 20138ULL: goto x86_l_4eaa;
	case 20141ULL: goto x86_l_4ead;
	case 20146ULL: goto x86_l_4eb2;
	case 20151ULL: goto x86_l_4eb7;
	case 20155ULL: goto x86_l_4ebb;
	case 20160ULL: goto x86_l_4ec0;
	case 20162ULL: goto x86_l_4ec2;
	case 20164ULL: goto x86_l_4ec4;
	case 20170ULL: goto x86_l_4eca;
	case 20175ULL: goto x86_l_4ecf;
	case 20183ULL: goto x86_l_4ed7;
	case 20189ULL: goto x86_l_4edd;
	case 20195ULL: goto x86_l_4ee3;
	case 20199ULL: goto x86_l_4ee7;
	case 20203ULL: goto x86_l_4eeb;
	case 20211ULL: goto x86_l_4ef3;
	case 20213ULL: goto x86_l_4ef5;
	case 20216ULL: goto x86_l_4ef8;
	case 20221ULL: goto x86_l_4efd;
	case 20226ULL: goto x86_l_4f02;
	case 20230ULL: goto x86_l_4f06;
	case 20235ULL: goto x86_l_4f0b;
	case 20237ULL: goto x86_l_4f0d;
	case 20239ULL: goto x86_l_4f0f;
	case 20245ULL: goto x86_l_4f15;
	case 20250ULL: goto x86_l_4f1a;
	case 20258ULL: goto x86_l_4f22;
	case 20264ULL: goto x86_l_4f28;
	case 20270ULL: goto x86_l_4f2e;
	case 20274ULL: goto x86_l_4f32;
	case 20278ULL: goto x86_l_4f36;
	case 20286ULL: goto x86_l_4f3e;
	case 20288ULL: goto x86_l_4f40;
	case 20291ULL: goto x86_l_4f43;
	case 20296ULL: goto x86_l_4f48;
	case 20301ULL: goto x86_l_4f4d;
	case 20305ULL: goto x86_l_4f51;
	case 20310ULL: goto x86_l_4f56;
	case 20312ULL: goto x86_l_4f58;
	case 20314ULL: goto x86_l_4f5a;
	case 20320ULL: goto x86_l_4f60;
	case 20325ULL: goto x86_l_4f65;
	case 20333ULL: goto x86_l_4f6d;
	case 20339ULL: goto x86_l_4f73;
	case 20345ULL: goto x86_l_4f79;
	case 20349ULL: goto x86_l_4f7d;
	case 20353ULL: goto x86_l_4f81;
	case 20361ULL: goto x86_l_4f89;
	case 20363ULL: goto x86_l_4f8b;
	case 20366ULL: goto x86_l_4f8e;
	case 20371ULL: goto x86_l_4f93;
	case 20376ULL: goto x86_l_4f98;
	case 20380ULL: goto x86_l_4f9c;
	case 20385ULL: goto x86_l_4fa1;
	case 20387ULL: goto x86_l_4fa3;
	case 20389ULL: goto x86_l_4fa5;
	case 20395ULL: goto x86_l_4fab;
	case 20400ULL: goto x86_l_4fb0;
	case 20408ULL: goto x86_l_4fb8;
	case 20414ULL: goto x86_l_4fbe;
	case 20420ULL: goto x86_l_4fc4;
	case 20424ULL: goto x86_l_4fc8;
	case 20428ULL: goto x86_l_4fcc;
	case 20436ULL: goto x86_l_4fd4;
	case 20438ULL: goto x86_l_4fd6;
	case 20441ULL: goto x86_l_4fd9;
	case 20446ULL: goto x86_l_4fde;
	case 20451ULL: goto x86_l_4fe3;
	case 20455ULL: goto x86_l_4fe7;
	case 20460ULL: goto x86_l_4fec;
	case 20462ULL: goto x86_l_4fee;
	case 20464ULL: goto x86_l_4ff0;
	case 20470ULL: goto x86_l_4ff6;
	case 20475ULL: goto x86_l_4ffb;
	case 20483ULL: goto x86_l_5003;
	case 20489ULL: goto x86_l_5009;
	case 20495ULL: goto x86_l_500f;
	case 20499ULL: goto x86_l_5013;
	case 20503ULL: goto x86_l_5017;
	case 20511ULL: goto x86_l_501f;
	case 20513ULL: goto x86_l_5021;
	case 20516ULL: goto x86_l_5024;
	case 20521ULL: goto x86_l_5029;
	case 20526ULL: goto x86_l_502e;
	case 20530ULL: goto x86_l_5032;
	case 20535ULL: goto x86_l_5037;
	case 20537ULL: goto x86_l_5039;
	case 20539ULL: goto x86_l_503b;
	case 20545ULL: goto x86_l_5041;
	case 20550ULL: goto x86_l_5046;
	case 20558ULL: goto x86_l_504e;
	case 20564ULL: goto x86_l_5054;
	case 20570ULL: goto x86_l_505a;
	case 20574ULL: goto x86_l_505e;
	case 20578ULL: goto x86_l_5062;
	case 20586ULL: goto x86_l_506a;
	case 20588ULL: goto x86_l_506c;
	case 20591ULL: goto x86_l_506f;
	case 20596ULL: goto x86_l_5074;
	case 20601ULL: goto x86_l_5079;
	case 20605ULL: goto x86_l_507d;
	case 20610ULL: goto x86_l_5082;
	case 20612ULL: goto x86_l_5084;
	case 20614ULL: goto x86_l_5086;
	case 20620ULL: goto x86_l_508c;
	case 20625ULL: goto x86_l_5091;
	case 20633ULL: goto x86_l_5099;
	case 20639ULL: goto x86_l_509f;
	case 20645ULL: goto x86_l_50a5;
	case 20649ULL: goto x86_l_50a9;
	case 20653ULL: goto x86_l_50ad;
	case 20661ULL: goto x86_l_50b5;
	case 20667ULL: goto x86_l_50bb;
	case 20670ULL: goto x86_l_50be;
	case 20675ULL: goto x86_l_50c3;
	case 20680ULL: goto x86_l_50c8;
	case 20685ULL: goto x86_l_50cd;
	case 20688ULL: goto x86_l_50d0;
	case 20690ULL: goto x86_l_50d2;
	case 20693ULL: goto x86_l_50d5;
	case 20698ULL: goto x86_l_50da;
	case 20703ULL: goto x86_l_50df;
	case 20707ULL: goto x86_l_50e3;
	case 20712ULL: goto x86_l_50e8;
	case 20714ULL: goto x86_l_50ea;
	case 20716ULL: goto x86_l_50ec;
	case 20722ULL: goto x86_l_50f2;
	case 20727ULL: goto x86_l_50f7;
	case 20735ULL: goto x86_l_50ff;
	case 20741ULL: goto x86_l_5105;
	case 20747ULL: goto x86_l_510b;
	case 20751ULL: goto x86_l_510f;
	case 20755ULL: goto x86_l_5113;
	case 20763ULL: goto x86_l_511b;
	case 20765ULL: goto x86_l_511d;
	case 20768ULL: goto x86_l_5120;
	case 20773ULL: goto x86_l_5125;
	case 20778ULL: goto x86_l_512a;
	case 20782ULL: goto x86_l_512e;
	case 20787ULL: goto x86_l_5133;
	case 20789ULL: goto x86_l_5135;
	case 20791ULL: goto x86_l_5137;
	case 20797ULL: goto x86_l_513d;
	case 20802ULL: goto x86_l_5142;
	case 20810ULL: goto x86_l_514a;
	case 20816ULL: goto x86_l_5150;
	case 20822ULL: goto x86_l_5156;
	case 20826ULL: goto x86_l_515a;
	case 20830ULL: goto x86_l_515e;
	case 20838ULL: goto x86_l_5166;
	case 20840ULL: goto x86_l_5168;
	case 20843ULL: goto x86_l_516b;
	case 20848ULL: goto x86_l_5170;
	case 20853ULL: goto x86_l_5175;
	case 20857ULL: goto x86_l_5179;
	case 20862ULL: goto x86_l_517e;
	case 20864ULL: goto x86_l_5180;
	case 20866ULL: goto x86_l_5182;
	case 20872ULL: goto x86_l_5188;
	case 20877ULL: goto x86_l_518d;
	case 20885ULL: goto x86_l_5195;
	case 20891ULL: goto x86_l_519b;
	case 20897ULL: goto x86_l_51a1;
	case 20901ULL: goto x86_l_51a5;
	case 20905ULL: goto x86_l_51a9;
	case 20913ULL: goto x86_l_51b1;
	case 20915ULL: goto x86_l_51b3;
	case 20918ULL: goto x86_l_51b6;
	case 20923ULL: goto x86_l_51bb;
	case 20928ULL: goto x86_l_51c0;
	case 20932ULL: goto x86_l_51c4;
	case 20937ULL: goto x86_l_51c9;
	case 20939ULL: goto x86_l_51cb;
	case 20941ULL: goto x86_l_51cd;
	case 20947ULL: goto x86_l_51d3;
	case 20952ULL: goto x86_l_51d8;
	case 20960ULL: goto x86_l_51e0;
	case 20966ULL: goto x86_l_51e6;
	case 20972ULL: goto x86_l_51ec;
	case 20976ULL: goto x86_l_51f0;
	case 20980ULL: goto x86_l_51f4;
	case 20988ULL: goto x86_l_51fc;
	case 20990ULL: goto x86_l_51fe;
	case 20993ULL: goto x86_l_5201;
	case 20998ULL: goto x86_l_5206;
	case 21003ULL: goto x86_l_520b;
	case 21007ULL: goto x86_l_520f;
	case 21012ULL: goto x86_l_5214;
	case 21014ULL: goto x86_l_5216;
	case 21016ULL: goto x86_l_5218;
	case 21022ULL: goto x86_l_521e;
	case 21027ULL: goto x86_l_5223;
	case 21035ULL: goto x86_l_522b;
	case 21041ULL: goto x86_l_5231;
	case 21047ULL: goto x86_l_5237;
	case 21051ULL: goto x86_l_523b;
	case 21055ULL: goto x86_l_523f;
	case 21063ULL: goto x86_l_5247;
	case 21065ULL: goto x86_l_5249;
	case 21068ULL: goto x86_l_524c;
	case 21073ULL: goto x86_l_5251;
	case 21078ULL: goto x86_l_5256;
	case 21082ULL: goto x86_l_525a;
	case 21087ULL: goto x86_l_525f;
	case 21089ULL: goto x86_l_5261;
	case 21091ULL: goto x86_l_5263;
	case 21097ULL: goto x86_l_5269;
	case 21102ULL: goto x86_l_526e;
	case 21110ULL: goto x86_l_5276;
	case 21116ULL: goto x86_l_527c;
	case 21122ULL: goto x86_l_5282;
	case 21126ULL: goto x86_l_5286;
	case 21130ULL: goto x86_l_528a;
	case 21138ULL: goto x86_l_5292;
	case 21140ULL: goto x86_l_5294;
	case 21143ULL: goto x86_l_5297;
	case 21148ULL: goto x86_l_529c;
	case 21153ULL: goto x86_l_52a1;
	case 21157ULL: goto x86_l_52a5;
	case 21162ULL: goto x86_l_52aa;
	case 21164ULL: goto x86_l_52ac;
	case 21166ULL: goto x86_l_52ae;
	case 21172ULL: goto x86_l_52b4;
	case 21177ULL: goto x86_l_52b9;
	case 21185ULL: goto x86_l_52c1;
	case 21191ULL: goto x86_l_52c7;
	case 21197ULL: goto x86_l_52cd;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4c23:
	/* 0x4c23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c25:
	/* 0x4c25: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4c2a:
	/* 0x4c2a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_4c2d:
	/* 0x4c2d: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_4c30:
	/* 0x4c30: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c35:
	/* 0x4c35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c37:
	/* 0x4c37: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4c3a:
	/* 0x4c3a: je     4c6b <generic_sleepable_preload+0x4c6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c6b;
	}
x86_l_4c3c:
	/* 0x4c3c: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_4c3f:
	/* 0x4c3f: je     4c69 <generic_sleepable_preload+0x4c69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c69;
	}
x86_l_4c41:
	/* 0x4c41: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4c44:
	/* 0x4c44: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4c48:
	/* 0x4c48: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4c4d:
	/* 0x4c4d: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4c50:
	/* 0x4c50: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c52:
	/* 0x4c52: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_4c55:
	/* 0x4c55: call   4c5a <generic_sleepable_preload+0x4c5a> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_4c5a:
	/* 0x4c5a: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_4c5c:
	/* 0x4c5c: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_4c5f:
	/* 0x4c5f: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_4c61:
	/* 0x4c61: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_4c66:
	/* 0x4c66: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_4c69:
	/* 0x4c69: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c6b:
	/* 0x4c6b: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_4c6e:
	/* 0x4c6e: mov    eax,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4c73:
	/* 0x4c73: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_4c78:
	/* 0x4c78: jne    4c92 <generic_sleepable_preload+0x4c92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4c92;
	}
x86_l_4c7a:
	/* 0x4c7a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c7c:
	/* 0x4c7c: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_4c83:
	/* 0x4c83: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_4c84:
	/* 0x4c84: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_4c86:
	/* 0x4c86: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_4c88:
	/* 0x4c88: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_4c8a:
	/* 0x4c8a: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_4c8c:
	/* 0x4c8c: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_4c8d:
	/* 0x4c8d: jmp    5dee <generic_sleepable_preload+0x5dee> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_4c92:
	/* 0x4c92: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_4c94:
	/* 0x4c94: js     4cc9 <generic_sleepable_preload+0x4cc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4cc9;
	}
x86_l_4c96:
	/* 0x4c96: mov    eax,DWORD PTR [r12+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4c9b:
	/* 0x4c9b: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4c9e:
	/* 0x4c9e: jle    4d4c <generic_sleepable_preload+0x4d4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4d4c;
	}
x86_l_4ca4:
	/* 0x4ca4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4ca7:
	/* 0x4ca7: je     4db6 <generic_sleepable_preload+0x4db6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4db6;
	}
x86_l_4cad:
	/* 0x4cad: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_4cb0:
	/* 0x4cb0: je     4dbd <generic_sleepable_preload+0x4dbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4dbd;
	}
x86_l_4cb6:
	/* 0x4cb6: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4cb9:
	/* 0x4cb9: jne    4dd0 <generic_sleepable_preload+0x4dd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4dd0;
	}
x86_l_4cbf:
	/* 0x4cbf: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4cc4:
	/* 0x4cc4: jmp    4dc9 <generic_sleepable_preload+0x4dc9> */
	goto x86_l_4dc9;
x86_l_4cc9:
	/* 0x4cc9: movzx  eax,BYTE PTR [r12+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_4cd2:
	/* 0x4cd2: movzx  ecx,WORD PTR [r12+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_4cdb:
	/* 0x4cdb: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_4ce1:
	/* 0x4ce1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ce3:
	/* 0x4ce3: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4ce6:
	/* 0x4ce6: jle    4d25 <generic_sleepable_preload+0x4d25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4d25;
	}
x86_l_4ce8:
	/* 0x4ce8: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_4ceb:
	/* 0x4ceb: jle    4d5c <generic_sleepable_preload+0x4d5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4d5c;
	}
x86_l_4ced:
	/* 0x4ced: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4cf0:
	/* 0x4cf0: jle    53f7 <generic_sleepable_preload+0x53f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 21495ULL;
	}
x86_l_4cf6:
	/* 0x4cf6: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4cfb:
	/* 0x4cfb: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_4cfe:
	/* 0x4cfe: je     541d <generic_sleepable_preload+0x541d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21533ULL;
	}
x86_l_4d04:
	/* 0x4d04: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4d09:
	/* 0x4d09: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_4d0c:
	/* 0x4d0c: je     541d <generic_sleepable_preload+0x541d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21533ULL;
	}
x86_l_4d12:
	/* 0x4d12: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4d17:
	/* 0x4d17: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_4d1a:
	/* 0x4d1a: je     541d <generic_sleepable_preload+0x541d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21533ULL;
	}
x86_l_4d20:
	/* 0x4d20: jmp    5430 <generic_sleepable_preload+0x5430> */
	return 21552ULL;
x86_l_4d25:
	/* 0x4d25: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4d28:
	/* 0x4d28: jg     4d89 <generic_sleepable_preload+0x4d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4d89;
	}
x86_l_4d2a:
	/* 0x4d2a: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4d2d:
	/* 0x4d2d: jg     53c8 <generic_sleepable_preload+0x53c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 21448ULL;
	}
x86_l_4d33:
	/* 0x4d33: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_4d35:
	/* 0x4d35: je     5418 <generic_sleepable_preload+0x5418> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21528ULL;
	}
x86_l_4d3b:
	/* 0x4d3b: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4d3e:
	/* 0x4d3e: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_4d41:
	/* 0x4d41: je     541d <generic_sleepable_preload+0x541d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21533ULL;
	}
x86_l_4d47:
	/* 0x4d47: jmp    5430 <generic_sleepable_preload+0x5430> */
	return 21552ULL;
x86_l_4d4c:
	/* 0x4d4c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d4e:
	/* 0x4d4e: je     4dc4 <generic_sleepable_preload+0x4dc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4dc4;
	}
x86_l_4d50:
	/* 0x4d50: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4d53:
	/* 0x4d53: jne    4dd0 <generic_sleepable_preload+0x4dd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4dd0;
	}
x86_l_4d55:
	/* 0x4d55: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4d5a:
	/* 0x4d5a: jmp    4dc9 <generic_sleepable_preload+0x4dc9> */
	goto x86_l_4dc9;
x86_l_4d5c:
	/* 0x4d5c: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_4d5f:
	/* 0x4d5f: jg     53af <generic_sleepable_preload+0x53af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 21423ULL;
	}
x86_l_4d65:
	/* 0x4d65: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4d6d:
	/* 0x4d6d: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4d70:
	/* 0x4d70: je     541d <generic_sleepable_preload+0x541d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21533ULL;
	}
x86_l_4d76:
	/* 0x4d76: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4d7b:
	/* 0x4d7b: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_4d7e:
	/* 0x4d7e: je     541d <generic_sleepable_preload+0x541d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21533ULL;
	}
x86_l_4d84:
	/* 0x4d84: jmp    5430 <generic_sleepable_preload+0x5430> */
	return 21552ULL;
x86_l_4d89:
	/* 0x4d89: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4d8c:
	/* 0x4d8c: jg     53de <generic_sleepable_preload+0x53de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 21470ULL;
	}
x86_l_4d92:
	/* 0x4d92: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4d9a:
	/* 0x4d9a: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_4d9d:
	/* 0x4d9d: je     541d <generic_sleepable_preload+0x541d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21533ULL;
	}
x86_l_4da3:
	/* 0x4da3: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4da8:
	/* 0x4da8: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4dab:
	/* 0x4dab: je     541d <generic_sleepable_preload+0x541d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21533ULL;
	}
x86_l_4db1:
	/* 0x4db1: jmp    5430 <generic_sleepable_preload+0x5430> */
	return 21552ULL;
x86_l_4db6:
	/* 0x4db6: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4dbb:
	/* 0x4dbb: jmp    4dc9 <generic_sleepable_preload+0x4dc9> */
	goto x86_l_4dc9;
x86_l_4dbd:
	/* 0x4dbd: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4dc2:
	/* 0x4dc2: jmp    4dc9 <generic_sleepable_preload+0x4dc9> */
	goto x86_l_4dc9;
x86_l_4dc4:
	/* 0x4dc4: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4dc9:
	/* 0x4dc9: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dcc:
	/* 0x4dcc: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dd0:
	/* 0x4dd0: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4dd3:
	/* 0x4dd3: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_4dd6:
	/* 0x4dd6: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ddb:
	/* 0x4ddb: cmp    WORD PTR [rsi+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_4de3:
	/* 0x4de3: je     5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23158ULL;
	}
x86_l_4de9:
	/* 0x4de9: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_4df0:
	/* 0x4df0: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_4df3:
	/* 0x4df3: mov    eax,DWORD PTR [rsi+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_4df9:
	/* 0x4df9: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4dfc:
	/* 0x4dfc: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e00:
	/* 0x4e00: movzx  eax,WORD PTR [rsi+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_4e07:
	/* 0x4e07: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_4e09:
	/* 0x4e09: je     50cd <generic_sleepable_preload+0x50cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50cd;
	}
x86_l_4e0f:
	/* 0x4e0f: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4e12:
	/* 0x4e12: je     4e34 <generic_sleepable_preload+0x4e34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e34;
	}
x86_l_4e14:
	/* 0x4e14: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4e17:
	/* 0x4e17: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4e1c:
	/* 0x4e1c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e21:
	/* 0x4e21: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e25:
	/* 0x4e25: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e2a:
	/* 0x4e2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e2c:
	/* 0x4e2c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e2e:
	/* 0x4e2e: js     53a4 <generic_sleepable_preload+0x53a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21412ULL;
	}
x86_l_4e34:
	/* 0x4e34: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e39:
	/* 0x4e39: cmp    WORD PTR [rax+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_4e41:
	/* 0x4e41: je     5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23158ULL;
	}
x86_l_4e47:
	/* 0x4e47: mov    ecx,DWORD PTR [rax+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_4e4d:
	/* 0x4e4d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4e51:
	/* 0x4e51: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e55:
	/* 0x4e55: cmp    WORD PTR [rax+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_4e5d:
	/* 0x4e5d: je     4e7f <generic_sleepable_preload+0x4e7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e7f;
	}
x86_l_4e5f:
	/* 0x4e5f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4e62:
	/* 0x4e62: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4e67:
	/* 0x4e67: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e6c:
	/* 0x4e6c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e70:
	/* 0x4e70: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e75:
	/* 0x4e75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e77:
	/* 0x4e77: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e79:
	/* 0x4e79: js     540d <generic_sleepable_preload+0x540d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21517ULL;
	}
x86_l_4e7f:
	/* 0x4e7f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e84:
	/* 0x4e84: cmp    WORD PTR [rax+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_4e8c:
	/* 0x4e8c: je     5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23158ULL;
	}
x86_l_4e92:
	/* 0x4e92: mov    ecx,DWORD PTR [rax+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_4e98:
	/* 0x4e98: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4e9c:
	/* 0x4e9c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ea0:
	/* 0x4ea0: cmp    WORD PTR [rax+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_4ea8:
	/* 0x4ea8: je     4eca <generic_sleepable_preload+0x4eca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4eca;
	}
x86_l_4eaa:
	/* 0x4eaa: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4ead:
	/* 0x4ead: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4eb2:
	/* 0x4eb2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4eb7:
	/* 0x4eb7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ebb:
	/* 0x4ebb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ec0:
	/* 0x4ec0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ec2:
	/* 0x4ec2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ec4:
	/* 0x4ec4: js     5a21 <generic_sleepable_preload+0x5a21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23073ULL;
	}
x86_l_4eca:
	/* 0x4eca: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ecf:
	/* 0x4ecf: cmp    WORD PTR [rax+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_4ed7:
	/* 0x4ed7: je     5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23158ULL;
	}
x86_l_4edd:
	/* 0x4edd: mov    ecx,DWORD PTR [rax+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_4ee3:
	/* 0x4ee3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4ee7:
	/* 0x4ee7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4eeb:
	/* 0x4eeb: cmp    WORD PTR [rax+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_4ef3:
	/* 0x4ef3: je     4f15 <generic_sleepable_preload+0x4f15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f15;
	}
x86_l_4ef5:
	/* 0x4ef5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4ef8:
	/* 0x4ef8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4efd:
	/* 0x4efd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4f02:
	/* 0x4f02: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f06:
	/* 0x4f06: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f0b:
	/* 0x4f0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f0d:
	/* 0x4f0d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f0f:
	/* 0x4f0f: js     5a34 <generic_sleepable_preload+0x5a34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23092ULL;
	}
x86_l_4f15:
	/* 0x4f15: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f1a:
	/* 0x4f1a: cmp    WORD PTR [rax+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_4f22:
	/* 0x4f22: je     5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23158ULL;
	}
x86_l_4f28:
	/* 0x4f28: mov    ecx,DWORD PTR [rax+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_4f2e:
	/* 0x4f2e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4f32:
	/* 0x4f32: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f36:
	/* 0x4f36: cmp    WORD PTR [rax+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_4f3e:
	/* 0x4f3e: je     4f60 <generic_sleepable_preload+0x4f60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f60;
	}
x86_l_4f40:
	/* 0x4f40: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4f43:
	/* 0x4f43: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4f48:
	/* 0x4f48: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4f4d:
	/* 0x4f4d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f51:
	/* 0x4f51: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f56:
	/* 0x4f56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f58:
	/* 0x4f58: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f5a:
	/* 0x4f5a: js     5a47 <generic_sleepable_preload+0x5a47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23111ULL;
	}
x86_l_4f60:
	/* 0x4f60: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f65:
	/* 0x4f65: cmp    WORD PTR [rax+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_4f6d:
	/* 0x4f6d: je     5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23158ULL;
	}
x86_l_4f73:
	/* 0x4f73: mov    ecx,DWORD PTR [rax+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_4f79:
	/* 0x4f79: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4f7d:
	/* 0x4f7d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f81:
	/* 0x4f81: cmp    WORD PTR [rax+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_4f89:
	/* 0x4f89: je     4fab <generic_sleepable_preload+0x4fab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fab;
	}
x86_l_4f8b:
	/* 0x4f8b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4f8e:
	/* 0x4f8e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4f93:
	/* 0x4f93: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4f98:
	/* 0x4f98: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f9c:
	/* 0x4f9c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4fa1:
	/* 0x4fa1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fa3:
	/* 0x4fa3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4fa5:
	/* 0x4fa5: js     5a5a <generic_sleepable_preload+0x5a5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23130ULL;
	}
x86_l_4fab:
	/* 0x4fab: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fb0:
	/* 0x4fb0: cmp    WORD PTR [rax+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_4fb8:
	/* 0x4fb8: je     5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23158ULL;
	}
x86_l_4fbe:
	/* 0x4fbe: mov    ecx,DWORD PTR [rax+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_4fc4:
	/* 0x4fc4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4fc8:
	/* 0x4fc8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fcc:
	/* 0x4fcc: cmp    WORD PTR [rax+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_4fd4:
	/* 0x4fd4: je     4ff6 <generic_sleepable_preload+0x4ff6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ff6;
	}
x86_l_4fd6:
	/* 0x4fd6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4fd9:
	/* 0x4fd9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4fde:
	/* 0x4fde: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4fe3:
	/* 0x4fe3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fe7:
	/* 0x4fe7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4fec:
	/* 0x4fec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fee:
	/* 0x4fee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ff0:
	/* 0x4ff0: js     5a6d <generic_sleepable_preload+0x5a6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23149ULL;
	}
x86_l_4ff6:
	/* 0x4ff6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ffb:
	/* 0x4ffb: cmp    WORD PTR [rax+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_5003:
	/* 0x5003: je     5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23158ULL;
	}
x86_l_5009:
	/* 0x5009: mov    ecx,DWORD PTR [rax+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_500f:
	/* 0x500f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5013:
	/* 0x5013: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5017:
	/* 0x5017: cmp    WORD PTR [rax+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_501f:
	/* 0x501f: je     5041 <generic_sleepable_preload+0x5041> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5041;
	}
x86_l_5021:
	/* 0x5021: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5024:
	/* 0x5024: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5029:
	/* 0x5029: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_502e:
	/* 0x502e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5032:
	/* 0x5032: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5037:
	/* 0x5037: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5039:
	/* 0x5039: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_503b:
	/* 0x503b: js     5bab <generic_sleepable_preload+0x5bab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23467ULL;
	}
x86_l_5041:
	/* 0x5041: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5046:
	/* 0x5046: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_504e:
	/* 0x504e: je     5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23158ULL;
	}
x86_l_5054:
	/* 0x5054: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_505a:
	/* 0x505a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_505e:
	/* 0x505e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5062:
	/* 0x5062: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_506a:
	/* 0x506a: je     508c <generic_sleepable_preload+0x508c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_508c;
	}
x86_l_506c:
	/* 0x506c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_506f:
	/* 0x506f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5074:
	/* 0x5074: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5079:
	/* 0x5079: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_507d:
	/* 0x507d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5082:
	/* 0x5082: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5084:
	/* 0x5084: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5086:
	/* 0x5086: js     5c38 <generic_sleepable_preload+0x5c38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23608ULL;
	}
x86_l_508c:
	/* 0x508c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5091:
	/* 0x5091: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_5099:
	/* 0x5099: je     5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23158ULL;
	}
x86_l_509f:
	/* 0x509f: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_50a5:
	/* 0x50a5: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_50a9:
	/* 0x50a9: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_50ad:
	/* 0x50ad: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_50b5:
	/* 0x50b5: je     5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23158ULL;
	}
x86_l_50bb:
	/* 0x50bb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_50be:
	/* 0x50be: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_50c3:
	/* 0x50c3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_50c8:
	/* 0x50c8: jmp    5386 <generic_sleepable_preload+0x5386> */
	return 21382ULL;
x86_l_50cd:
	/* 0x50cd: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_50d0:
	/* 0x50d0: je     50f2 <generic_sleepable_preload+0x50f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50f2;
	}
x86_l_50d2:
	/* 0x50d2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_50d5:
	/* 0x50d5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_50da:
	/* 0x50da: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_50df:
	/* 0x50df: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_50e3:
	/* 0x50e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50e8:
	/* 0x50e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50ea:
	/* 0x50ea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_50ec:
	/* 0x50ec: js     53a4 <generic_sleepable_preload+0x53a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21412ULL;
	}
x86_l_50f2:
	/* 0x50f2: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50f7:
	/* 0x50f7: cmp    WORD PTR [rax+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_50ff:
	/* 0x50ff: je     5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23158ULL;
	}
x86_l_5105:
	/* 0x5105: mov    ecx,DWORD PTR [rax+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_510b:
	/* 0x510b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_510f:
	/* 0x510f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5113:
	/* 0x5113: cmp    WORD PTR [rax+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_511b:
	/* 0x511b: je     513d <generic_sleepable_preload+0x513d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_513d;
	}
x86_l_511d:
	/* 0x511d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5120:
	/* 0x5120: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5125:
	/* 0x5125: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_512a:
	/* 0x512a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_512e:
	/* 0x512e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5133:
	/* 0x5133: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5135:
	/* 0x5135: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5137:
	/* 0x5137: js     540d <generic_sleepable_preload+0x540d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21517ULL;
	}
x86_l_513d:
	/* 0x513d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5142:
	/* 0x5142: cmp    WORD PTR [rax+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_514a:
	/* 0x514a: je     5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23158ULL;
	}
x86_l_5150:
	/* 0x5150: mov    ecx,DWORD PTR [rax+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_5156:
	/* 0x5156: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_515a:
	/* 0x515a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_515e:
	/* 0x515e: cmp    WORD PTR [rax+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_5166:
	/* 0x5166: je     5188 <generic_sleepable_preload+0x5188> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5188;
	}
x86_l_5168:
	/* 0x5168: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_516b:
	/* 0x516b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5170:
	/* 0x5170: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5175:
	/* 0x5175: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5179:
	/* 0x5179: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_517e:
	/* 0x517e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5180:
	/* 0x5180: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5182:
	/* 0x5182: js     5a21 <generic_sleepable_preload+0x5a21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23073ULL;
	}
x86_l_5188:
	/* 0x5188: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_518d:
	/* 0x518d: cmp    WORD PTR [rax+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_5195:
	/* 0x5195: je     5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23158ULL;
	}
x86_l_519b:
	/* 0x519b: mov    ecx,DWORD PTR [rax+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_51a1:
	/* 0x51a1: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_51a5:
	/* 0x51a5: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51a9:
	/* 0x51a9: cmp    WORD PTR [rax+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_51b1:
	/* 0x51b1: je     51d3 <generic_sleepable_preload+0x51d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_51d3;
	}
x86_l_51b3:
	/* 0x51b3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_51b6:
	/* 0x51b6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_51bb:
	/* 0x51bb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_51c0:
	/* 0x51c0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51c4:
	/* 0x51c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51c9:
	/* 0x51c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51cb:
	/* 0x51cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_51cd:
	/* 0x51cd: js     5a34 <generic_sleepable_preload+0x5a34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23092ULL;
	}
x86_l_51d3:
	/* 0x51d3: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51d8:
	/* 0x51d8: cmp    WORD PTR [rax+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_51e0:
	/* 0x51e0: je     5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23158ULL;
	}
x86_l_51e6:
	/* 0x51e6: mov    ecx,DWORD PTR [rax+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_51ec:
	/* 0x51ec: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_51f0:
	/* 0x51f0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51f4:
	/* 0x51f4: cmp    WORD PTR [rax+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_51fc:
	/* 0x51fc: je     521e <generic_sleepable_preload+0x521e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_521e;
	}
x86_l_51fe:
	/* 0x51fe: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5201:
	/* 0x5201: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5206:
	/* 0x5206: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_520b:
	/* 0x520b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_520f:
	/* 0x520f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5214:
	/* 0x5214: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5216:
	/* 0x5216: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5218:
	/* 0x5218: js     5a47 <generic_sleepable_preload+0x5a47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23111ULL;
	}
x86_l_521e:
	/* 0x521e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5223:
	/* 0x5223: cmp    WORD PTR [rax+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_522b:
	/* 0x522b: je     5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23158ULL;
	}
x86_l_5231:
	/* 0x5231: mov    ecx,DWORD PTR [rax+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_5237:
	/* 0x5237: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_523b:
	/* 0x523b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_523f:
	/* 0x523f: cmp    WORD PTR [rax+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_5247:
	/* 0x5247: je     5269 <generic_sleepable_preload+0x5269> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5269;
	}
x86_l_5249:
	/* 0x5249: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_524c:
	/* 0x524c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5251:
	/* 0x5251: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5256:
	/* 0x5256: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_525a:
	/* 0x525a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_525f:
	/* 0x525f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5261:
	/* 0x5261: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5263:
	/* 0x5263: js     5a5a <generic_sleepable_preload+0x5a5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23130ULL;
	}
x86_l_5269:
	/* 0x5269: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_526e:
	/* 0x526e: cmp    WORD PTR [rax+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_5276:
	/* 0x5276: je     5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23158ULL;
	}
x86_l_527c:
	/* 0x527c: mov    ecx,DWORD PTR [rax+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_5282:
	/* 0x5282: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5286:
	/* 0x5286: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_528a:
	/* 0x528a: cmp    WORD PTR [rax+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_5292:
	/* 0x5292: je     52b4 <generic_sleepable_preload+0x52b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_52b4;
	}
x86_l_5294:
	/* 0x5294: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5297:
	/* 0x5297: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_529c:
	/* 0x529c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_52a1:
	/* 0x52a1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52a5:
	/* 0x52a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52aa:
	/* 0x52aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52ac:
	/* 0x52ac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52ae:
	/* 0x52ae: js     5a6d <generic_sleepable_preload+0x5a6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23149ULL;
	}
x86_l_52b4:
	/* 0x52b4: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52b9:
	/* 0x52b9: cmp    WORD PTR [rax+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_52c1:
	/* 0x52c1: je     5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23158ULL;
	}
x86_l_52c7:
	/* 0x52c7: mov    ecx,DWORD PTR [rax+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_52cd:
	/* 0x52cd: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
	return 21201ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 21201ULL: goto x86_l_52d1;
	case 21205ULL: goto x86_l_52d5;
	case 21213ULL: goto x86_l_52dd;
	case 21215ULL: goto x86_l_52df;
	case 21218ULL: goto x86_l_52e2;
	case 21223ULL: goto x86_l_52e7;
	case 21228ULL: goto x86_l_52ec;
	case 21232ULL: goto x86_l_52f0;
	case 21237ULL: goto x86_l_52f5;
	case 21239ULL: goto x86_l_52f7;
	case 21241ULL: goto x86_l_52f9;
	case 21247ULL: goto x86_l_52ff;
	case 21252ULL: goto x86_l_5304;
	case 21260ULL: goto x86_l_530c;
	case 21266ULL: goto x86_l_5312;
	case 21272ULL: goto x86_l_5318;
	case 21276ULL: goto x86_l_531c;
	case 21280ULL: goto x86_l_5320;
	case 21288ULL: goto x86_l_5328;
	case 21290ULL: goto x86_l_532a;
	case 21293ULL: goto x86_l_532d;
	case 21298ULL: goto x86_l_5332;
	case 21303ULL: goto x86_l_5337;
	case 21307ULL: goto x86_l_533b;
	case 21312ULL: goto x86_l_5340;
	case 21314ULL: goto x86_l_5342;
	case 21316ULL: goto x86_l_5344;
	case 21322ULL: goto x86_l_534a;
	case 21327ULL: goto x86_l_534f;
	case 21335ULL: goto x86_l_5357;
	case 21341ULL: goto x86_l_535d;
	case 21347ULL: goto x86_l_5363;
	case 21351ULL: goto x86_l_5367;
	case 21355ULL: goto x86_l_536b;
	case 21363ULL: goto x86_l_5373;
	case 21369ULL: goto x86_l_5379;
	case 21372ULL: goto x86_l_537c;
	case 21377ULL: goto x86_l_5381;
	case 21382ULL: goto x86_l_5386;
	case 21386ULL: goto x86_l_538a;
	case 21391ULL: goto x86_l_538f;
	case 21393ULL: goto x86_l_5391;
	case 21395ULL: goto x86_l_5393;
	case 21401ULL: goto x86_l_5399;
	case 21407ULL: goto x86_l_539f;
	case 21412ULL: goto x86_l_53a4;
	case 21418ULL: goto x86_l_53aa;
	case 21423ULL: goto x86_l_53af;
	case 21431ULL: goto x86_l_53b7;
	case 21434ULL: goto x86_l_53ba;
	case 21436ULL: goto x86_l_53bc;
	case 21441ULL: goto x86_l_53c1;
	case 21444ULL: goto x86_l_53c4;
	case 21446ULL: goto x86_l_53c6;
	case 21448ULL: goto x86_l_53c8;
	case 21453ULL: goto x86_l_53cd;
	case 21456ULL: goto x86_l_53d0;
	case 21458ULL: goto x86_l_53d2;
	case 21463ULL: goto x86_l_53d7;
	case 21466ULL: goto x86_l_53da;
	case 21468ULL: goto x86_l_53dc;
	case 21470ULL: goto x86_l_53de;
	case 21478ULL: goto x86_l_53e6;
	case 21481ULL: goto x86_l_53e9;
	case 21483ULL: goto x86_l_53eb;
	case 21488ULL: goto x86_l_53f0;
	case 21491ULL: goto x86_l_53f3;
	case 21493ULL: goto x86_l_53f5;
	case 21495ULL: goto x86_l_53f7;
	case 21500ULL: goto x86_l_53fc;
	case 21503ULL: goto x86_l_53ff;
	case 21505ULL: goto x86_l_5401;
	case 21510ULL: goto x86_l_5406;
	case 21513ULL: goto x86_l_5409;
	case 21515ULL: goto x86_l_540b;
	case 21517ULL: goto x86_l_540d;
	case 21523ULL: goto x86_l_5413;
	case 21528ULL: goto x86_l_5418;
	case 21533ULL: goto x86_l_541d;
	case 21536ULL: goto x86_l_5420;
	case 21538ULL: goto x86_l_5422;
	case 21540ULL: goto x86_l_5424;
	case 21545ULL: goto x86_l_5429;
	case 21547ULL: goto x86_l_542b;
	case 21552ULL: goto x86_l_5430;
	case 21556ULL: goto x86_l_5434;
	case 21561ULL: goto x86_l_5439;
	case 21564ULL: goto x86_l_543c;
	case 21567ULL: goto x86_l_543f;
	case 21570ULL: goto x86_l_5442;
	case 21578ULL: goto x86_l_544a;
	case 21584ULL: goto x86_l_5450;
	case 21591ULL: goto x86_l_5457;
	case 21594ULL: goto x86_l_545a;
	case 21600ULL: goto x86_l_5460;
	case 21603ULL: goto x86_l_5463;
	case 21607ULL: goto x86_l_5467;
	case 21614ULL: goto x86_l_546e;
	case 21616ULL: goto x86_l_5470;
	case 21622ULL: goto x86_l_5476;
	case 21625ULL: goto x86_l_5479;
	case 21627ULL: goto x86_l_547b;
	case 21630ULL: goto x86_l_547e;
	case 21635ULL: goto x86_l_5483;
	case 21640ULL: goto x86_l_5488;
	case 21644ULL: goto x86_l_548c;
	case 21649ULL: goto x86_l_5491;
	case 21651ULL: goto x86_l_5493;
	case 21653ULL: goto x86_l_5495;
	case 21659ULL: goto x86_l_549b;
	case 21664ULL: goto x86_l_54a0;
	case 21672ULL: goto x86_l_54a8;
	case 21678ULL: goto x86_l_54ae;
	case 21684ULL: goto x86_l_54b4;
	case 21688ULL: goto x86_l_54b8;
	case 21692ULL: goto x86_l_54bc;
	case 21700ULL: goto x86_l_54c4;
	case 21702ULL: goto x86_l_54c6;
	case 21705ULL: goto x86_l_54c9;
	case 21710ULL: goto x86_l_54ce;
	case 21715ULL: goto x86_l_54d3;
	case 21719ULL: goto x86_l_54d7;
	case 21724ULL: goto x86_l_54dc;
	case 21726ULL: goto x86_l_54de;
	case 21728ULL: goto x86_l_54e0;
	case 21734ULL: goto x86_l_54e6;
	case 21739ULL: goto x86_l_54eb;
	case 21747ULL: goto x86_l_54f3;
	case 21753ULL: goto x86_l_54f9;
	case 21759ULL: goto x86_l_54ff;
	case 21763ULL: goto x86_l_5503;
	case 21767ULL: goto x86_l_5507;
	case 21775ULL: goto x86_l_550f;
	case 21777ULL: goto x86_l_5511;
	case 21780ULL: goto x86_l_5514;
	case 21785ULL: goto x86_l_5519;
	case 21790ULL: goto x86_l_551e;
	case 21794ULL: goto x86_l_5522;
	case 21799ULL: goto x86_l_5527;
	case 21801ULL: goto x86_l_5529;
	case 21803ULL: goto x86_l_552b;
	case 21809ULL: goto x86_l_5531;
	case 21814ULL: goto x86_l_5536;
	case 21822ULL: goto x86_l_553e;
	case 21828ULL: goto x86_l_5544;
	case 21834ULL: goto x86_l_554a;
	case 21838ULL: goto x86_l_554e;
	case 21842ULL: goto x86_l_5552;
	case 21850ULL: goto x86_l_555a;
	case 21852ULL: goto x86_l_555c;
	case 21855ULL: goto x86_l_555f;
	case 21860ULL: goto x86_l_5564;
	case 21865ULL: goto x86_l_5569;
	case 21869ULL: goto x86_l_556d;
	case 21874ULL: goto x86_l_5572;
	case 21876ULL: goto x86_l_5574;
	case 21878ULL: goto x86_l_5576;
	case 21884ULL: goto x86_l_557c;
	case 21889ULL: goto x86_l_5581;
	case 21897ULL: goto x86_l_5589;
	case 21903ULL: goto x86_l_558f;
	case 21909ULL: goto x86_l_5595;
	case 21913ULL: goto x86_l_5599;
	case 21917ULL: goto x86_l_559d;
	case 21925ULL: goto x86_l_55a5;
	case 21927ULL: goto x86_l_55a7;
	case 21930ULL: goto x86_l_55aa;
	case 21935ULL: goto x86_l_55af;
	case 21940ULL: goto x86_l_55b4;
	case 21944ULL: goto x86_l_55b8;
	case 21949ULL: goto x86_l_55bd;
	case 21951ULL: goto x86_l_55bf;
	case 21953ULL: goto x86_l_55c1;
	case 21959ULL: goto x86_l_55c7;
	case 21964ULL: goto x86_l_55cc;
	case 21972ULL: goto x86_l_55d4;
	case 21978ULL: goto x86_l_55da;
	case 21984ULL: goto x86_l_55e0;
	case 21988ULL: goto x86_l_55e4;
	case 21992ULL: goto x86_l_55e8;
	case 22000ULL: goto x86_l_55f0;
	case 22002ULL: goto x86_l_55f2;
	case 22005ULL: goto x86_l_55f5;
	case 22010ULL: goto x86_l_55fa;
	case 22015ULL: goto x86_l_55ff;
	case 22019ULL: goto x86_l_5603;
	case 22024ULL: goto x86_l_5608;
	case 22026ULL: goto x86_l_560a;
	case 22028ULL: goto x86_l_560c;
	case 22034ULL: goto x86_l_5612;
	case 22039ULL: goto x86_l_5617;
	case 22047ULL: goto x86_l_561f;
	case 22053ULL: goto x86_l_5625;
	case 22059ULL: goto x86_l_562b;
	case 22063ULL: goto x86_l_562f;
	case 22067ULL: goto x86_l_5633;
	case 22075ULL: goto x86_l_563b;
	case 22077ULL: goto x86_l_563d;
	case 22080ULL: goto x86_l_5640;
	case 22085ULL: goto x86_l_5645;
	case 22090ULL: goto x86_l_564a;
	case 22094ULL: goto x86_l_564e;
	case 22099ULL: goto x86_l_5653;
	case 22101ULL: goto x86_l_5655;
	case 22103ULL: goto x86_l_5657;
	case 22109ULL: goto x86_l_565d;
	case 22114ULL: goto x86_l_5662;
	case 22122ULL: goto x86_l_566a;
	case 22128ULL: goto x86_l_5670;
	case 22134ULL: goto x86_l_5676;
	case 22138ULL: goto x86_l_567a;
	case 22142ULL: goto x86_l_567e;
	case 22150ULL: goto x86_l_5686;
	case 22152ULL: goto x86_l_5688;
	case 22155ULL: goto x86_l_568b;
	case 22160ULL: goto x86_l_5690;
	case 22165ULL: goto x86_l_5695;
	case 22169ULL: goto x86_l_5699;
	case 22174ULL: goto x86_l_569e;
	case 22176ULL: goto x86_l_56a0;
	case 22178ULL: goto x86_l_56a2;
	case 22184ULL: goto x86_l_56a8;
	case 22189ULL: goto x86_l_56ad;
	case 22197ULL: goto x86_l_56b5;
	case 22203ULL: goto x86_l_56bb;
	case 22209ULL: goto x86_l_56c1;
	case 22213ULL: goto x86_l_56c5;
	case 22217ULL: goto x86_l_56c9;
	case 22225ULL: goto x86_l_56d1;
	case 22227ULL: goto x86_l_56d3;
	case 22230ULL: goto x86_l_56d6;
	case 22235ULL: goto x86_l_56db;
	case 22240ULL: goto x86_l_56e0;
	case 22244ULL: goto x86_l_56e4;
	case 22249ULL: goto x86_l_56e9;
	case 22251ULL: goto x86_l_56eb;
	case 22253ULL: goto x86_l_56ed;
	case 22259ULL: goto x86_l_56f3;
	case 22264ULL: goto x86_l_56f8;
	case 22272ULL: goto x86_l_5700;
	case 22278ULL: goto x86_l_5706;
	case 22284ULL: goto x86_l_570c;
	case 22288ULL: goto x86_l_5710;
	case 22292ULL: goto x86_l_5714;
	case 22300ULL: goto x86_l_571c;
	case 22306ULL: goto x86_l_5722;
	case 22309ULL: goto x86_l_5725;
	case 22314ULL: goto x86_l_572a;
	case 22319ULL: goto x86_l_572f;
	case 22324ULL: goto x86_l_5734;
	case 22327ULL: goto x86_l_5737;
	case 22329ULL: goto x86_l_5739;
	case 22332ULL: goto x86_l_573c;
	case 22337ULL: goto x86_l_5741;
	case 22342ULL: goto x86_l_5746;
	case 22346ULL: goto x86_l_574a;
	case 22351ULL: goto x86_l_574f;
	case 22353ULL: goto x86_l_5751;
	case 22355ULL: goto x86_l_5753;
	case 22361ULL: goto x86_l_5759;
	case 22366ULL: goto x86_l_575e;
	case 22374ULL: goto x86_l_5766;
	case 22380ULL: goto x86_l_576c;
	case 22386ULL: goto x86_l_5772;
	case 22390ULL: goto x86_l_5776;
	case 22394ULL: goto x86_l_577a;
	case 22402ULL: goto x86_l_5782;
	case 22404ULL: goto x86_l_5784;
	case 22407ULL: goto x86_l_5787;
	case 22412ULL: goto x86_l_578c;
	case 22417ULL: goto x86_l_5791;
	case 22421ULL: goto x86_l_5795;
	case 22426ULL: goto x86_l_579a;
	case 22428ULL: goto x86_l_579c;
	case 22430ULL: goto x86_l_579e;
	case 22436ULL: goto x86_l_57a4;
	case 22441ULL: goto x86_l_57a9;
	case 22449ULL: goto x86_l_57b1;
	case 22455ULL: goto x86_l_57b7;
	case 22461ULL: goto x86_l_57bd;
	case 22465ULL: goto x86_l_57c1;
	case 22469ULL: goto x86_l_57c5;
	case 22477ULL: goto x86_l_57cd;
	case 22479ULL: goto x86_l_57cf;
	case 22482ULL: goto x86_l_57d2;
	case 22487ULL: goto x86_l_57d7;
	case 22492ULL: goto x86_l_57dc;
	case 22496ULL: goto x86_l_57e0;
	case 22501ULL: goto x86_l_57e5;
	case 22503ULL: goto x86_l_57e7;
	case 22505ULL: goto x86_l_57e9;
	case 22511ULL: goto x86_l_57ef;
	case 22516ULL: goto x86_l_57f4;
	case 22524ULL: goto x86_l_57fc;
	case 22530ULL: goto x86_l_5802;
	case 22536ULL: goto x86_l_5808;
	case 22540ULL: goto x86_l_580c;
	case 22544ULL: goto x86_l_5810;
	case 22552ULL: goto x86_l_5818;
	case 22554ULL: goto x86_l_581a;
	case 22557ULL: goto x86_l_581d;
	case 22562ULL: goto x86_l_5822;
	case 22567ULL: goto x86_l_5827;
	case 22571ULL: goto x86_l_582b;
	case 22576ULL: goto x86_l_5830;
	case 22578ULL: goto x86_l_5832;
	case 22580ULL: goto x86_l_5834;
	case 22586ULL: goto x86_l_583a;
	case 22591ULL: goto x86_l_583f;
	case 22599ULL: goto x86_l_5847;
	case 22605ULL: goto x86_l_584d;
	case 22611ULL: goto x86_l_5853;
	case 22615ULL: goto x86_l_5857;
	case 22619ULL: goto x86_l_585b;
	case 22627ULL: goto x86_l_5863;
	case 22629ULL: goto x86_l_5865;
	case 22632ULL: goto x86_l_5868;
	case 22637ULL: goto x86_l_586d;
	case 22642ULL: goto x86_l_5872;
	case 22646ULL: goto x86_l_5876;
	case 22651ULL: goto x86_l_587b;
	case 22653ULL: goto x86_l_587d;
	case 22655ULL: goto x86_l_587f;
	case 22661ULL: goto x86_l_5885;
	case 22666ULL: goto x86_l_588a;
	case 22674ULL: goto x86_l_5892;
	case 22680ULL: goto x86_l_5898;
	case 22686ULL: goto x86_l_589e;
	case 22690ULL: goto x86_l_58a2;
	case 22694ULL: goto x86_l_58a6;
	case 22702ULL: goto x86_l_58ae;
	case 22704ULL: goto x86_l_58b0;
	case 22707ULL: goto x86_l_58b3;
	case 22712ULL: goto x86_l_58b8;
	case 22717ULL: goto x86_l_58bd;
	case 22721ULL: goto x86_l_58c1;
	case 22726ULL: goto x86_l_58c6;
	case 22728ULL: goto x86_l_58c8;
	case 22730ULL: goto x86_l_58ca;
	case 22736ULL: goto x86_l_58d0;
	case 22741ULL: goto x86_l_58d5;
	case 22749ULL: goto x86_l_58dd;
	case 22755ULL: goto x86_l_58e3;
	case 22761ULL: goto x86_l_58e9;
	case 22765ULL: goto x86_l_58ed;
	case 22769ULL: goto x86_l_58f1;
	case 22777ULL: goto x86_l_58f9;
	case 22779ULL: goto x86_l_58fb;
	case 22782ULL: goto x86_l_58fe;
	case 22787ULL: goto x86_l_5903;
	case 22792ULL: goto x86_l_5908;
	case 22796ULL: goto x86_l_590c;
	case 22801ULL: goto x86_l_5911;
	case 22803ULL: goto x86_l_5913;
	case 22805ULL: goto x86_l_5915;
	case 22811ULL: goto x86_l_591b;
	case 22816ULL: goto x86_l_5920;
	case 22824ULL: goto x86_l_5928;
	case 22830ULL: goto x86_l_592e;
	case 22836ULL: goto x86_l_5934;
	case 22840ULL: goto x86_l_5938;
	case 22844ULL: goto x86_l_593c;
	case 22852ULL: goto x86_l_5944;
	case 22854ULL: goto x86_l_5946;
	case 22857ULL: goto x86_l_5949;
	case 22862ULL: goto x86_l_594e;
	case 22867ULL: goto x86_l_5953;
	case 22871ULL: goto x86_l_5957;
	case 22876ULL: goto x86_l_595c;
	case 22878ULL: goto x86_l_595e;
	case 22880ULL: goto x86_l_5960;
	case 22886ULL: goto x86_l_5966;
	case 22891ULL: goto x86_l_596b;
	case 22899ULL: goto x86_l_5973;
	case 22905ULL: goto x86_l_5979;
	case 22911ULL: goto x86_l_597f;
	case 22915ULL: goto x86_l_5983;
	case 22919ULL: goto x86_l_5987;
	case 22927ULL: goto x86_l_598f;
	case 22929ULL: goto x86_l_5991;
	case 22932ULL: goto x86_l_5994;
	case 22937ULL: goto x86_l_5999;
	case 22942ULL: goto x86_l_599e;
	case 22946ULL: goto x86_l_59a2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_52d1:
	/* 0x52d1: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52d5:
	/* 0x52d5: cmp    WORD PTR [rax+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_52dd:
	/* 0x52dd: je     52ff <generic_sleepable_preload+0x52ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_52ff;
	}
x86_l_52df:
	/* 0x52df: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_52e2:
	/* 0x52e2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_52e7:
	/* 0x52e7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_52ec:
	/* 0x52ec: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52f0:
	/* 0x52f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52f5:
	/* 0x52f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52f7:
	/* 0x52f7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52f9:
	/* 0x52f9: js     5bab <generic_sleepable_preload+0x5bab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23467ULL;
	}
x86_l_52ff:
	/* 0x52ff: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5304:
	/* 0x5304: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_530c:
	/* 0x530c: je     5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23158ULL;
	}
x86_l_5312:
	/* 0x5312: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_5318:
	/* 0x5318: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_531c:
	/* 0x531c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5320:
	/* 0x5320: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_5328:
	/* 0x5328: je     534a <generic_sleepable_preload+0x534a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_534a;
	}
x86_l_532a:
	/* 0x532a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_532d:
	/* 0x532d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5332:
	/* 0x5332: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5337:
	/* 0x5337: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_533b:
	/* 0x533b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5340:
	/* 0x5340: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5342:
	/* 0x5342: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5344:
	/* 0x5344: js     5c38 <generic_sleepable_preload+0x5c38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23608ULL;
	}
x86_l_534a:
	/* 0x534a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_534f:
	/* 0x534f: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_5357:
	/* 0x5357: je     5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23158ULL;
	}
x86_l_535d:
	/* 0x535d: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_5363:
	/* 0x5363: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5367:
	/* 0x5367: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_536b:
	/* 0x536b: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_5373:
	/* 0x5373: je     5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23158ULL;
	}
x86_l_5379:
	/* 0x5379: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_537c:
	/* 0x537c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5381:
	/* 0x5381: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5386:
	/* 0x5386: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_538a:
	/* 0x538a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_538f:
	/* 0x538f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5391:
	/* 0x5391: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5393:
	/* 0x5393: jns    5a76 <generic_sleepable_preload+0x5a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 23158ULL;
	}
x86_l_5399:
	/* 0x5399: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_539f:
	/* 0x539f: jmp    5a73 <generic_sleepable_preload+0x5a73> */
	return 23155ULL;
x86_l_53a4:
	/* 0x53a4: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_53aa:
	/* 0x53aa: jmp    5a73 <generic_sleepable_preload+0x5a73> */
	return 23155ULL;
x86_l_53af:
	/* 0x53af: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_53b7:
	/* 0x53b7: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_53ba:
	/* 0x53ba: je     541d <generic_sleepable_preload+0x541d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_541d;
	}
x86_l_53bc:
	/* 0x53bc: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_53c1:
	/* 0x53c1: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_53c4:
	/* 0x53c4: je     541d <generic_sleepable_preload+0x541d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_541d;
	}
x86_l_53c6:
	/* 0x53c6: jmp    5430 <generic_sleepable_preload+0x5430> */
	goto x86_l_5430;
x86_l_53c8:
	/* 0x53c8: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_53cd:
	/* 0x53cd: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_53d0:
	/* 0x53d0: je     541d <generic_sleepable_preload+0x541d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_541d;
	}
x86_l_53d2:
	/* 0x53d2: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_53d7:
	/* 0x53d7: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_53da:
	/* 0x53da: je     541d <generic_sleepable_preload+0x541d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_541d;
	}
x86_l_53dc:
	/* 0x53dc: jmp    5430 <generic_sleepable_preload+0x5430> */
	goto x86_l_5430;
x86_l_53de:
	/* 0x53de: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_53e6:
	/* 0x53e6: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_53e9:
	/* 0x53e9: je     541d <generic_sleepable_preload+0x541d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_541d;
	}
x86_l_53eb:
	/* 0x53eb: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_53f0:
	/* 0x53f0: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_53f3:
	/* 0x53f3: je     541d <generic_sleepable_preload+0x541d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_541d;
	}
x86_l_53f5:
	/* 0x53f5: jmp    5430 <generic_sleepable_preload+0x5430> */
	goto x86_l_5430;
x86_l_53f7:
	/* 0x53f7: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_53fc:
	/* 0x53fc: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_53ff:
	/* 0x53ff: je     541d <generic_sleepable_preload+0x541d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_541d;
	}
x86_l_5401:
	/* 0x5401: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5406:
	/* 0x5406: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_5409:
	/* 0x5409: je     541d <generic_sleepable_preload+0x541d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_541d;
	}
x86_l_540b:
	/* 0x540b: jmp    5430 <generic_sleepable_preload+0x5430> */
	goto x86_l_5430;
x86_l_540d:
	/* 0x540d: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_5413:
	/* 0x5413: jmp    5a73 <generic_sleepable_preload+0x5a73> */
	return 23155ULL;
x86_l_5418:
	/* 0x5418: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_541d:
	/* 0x541d: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_5420:
	/* 0x5420: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_5422:
	/* 0x5422: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_5424:
	/* 0x5424: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_5429:
	/* 0x5429: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_542b:
	/* 0x542b: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_5430:
	/* 0x5430: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5434:
	/* 0x5434: mov    ebx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5439:
	/* 0x5439: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_543c:
	/* 0x543c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_543f:
	/* 0x543f: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_5442:
	/* 0x5442: cmp    WORD PTR [rsi+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_544a:
	/* 0x544a: je     5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23298ULL;
	}
x86_l_5450:
	/* 0x5450: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_5457:
	/* 0x5457: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_545a:
	/* 0x545a: mov    eax,DWORD PTR [rsi+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_5460:
	/* 0x5460: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5463:
	/* 0x5463: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5467:
	/* 0x5467: movzx  eax,WORD PTR [rsi+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_546e:
	/* 0x546e: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_5470:
	/* 0x5470: je     5734 <generic_sleepable_preload+0x5734> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5734;
	}
x86_l_5476:
	/* 0x5476: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_5479:
	/* 0x5479: je     549b <generic_sleepable_preload+0x549b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_549b;
	}
x86_l_547b:
	/* 0x547b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_547e:
	/* 0x547e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5483:
	/* 0x5483: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5488:
	/* 0x5488: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_548c:
	/* 0x548c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5491:
	/* 0x5491: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5493:
	/* 0x5493: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5495:
	/* 0x5495: js     5a0b <generic_sleepable_preload+0x5a0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23051ULL;
	}
x86_l_549b:
	/* 0x549b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54a0:
	/* 0x54a0: cmp    WORD PTR [rax+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_54a8:
	/* 0x54a8: je     5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23298ULL;
	}
x86_l_54ae:
	/* 0x54ae: mov    ecx,DWORD PTR [rax+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_54b4:
	/* 0x54b4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_54b8:
	/* 0x54b8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54bc:
	/* 0x54bc: cmp    WORD PTR [rax+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_54c4:
	/* 0x54c4: je     54e6 <generic_sleepable_preload+0x54e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54e6;
	}
x86_l_54c6:
	/* 0x54c6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_54c9:
	/* 0x54c9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_54ce:
	/* 0x54ce: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_54d3:
	/* 0x54d3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54d7:
	/* 0x54d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54dc:
	/* 0x54dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54de:
	/* 0x54de: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_54e0:
	/* 0x54e0: js     5a16 <generic_sleepable_preload+0x5a16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23062ULL;
	}
x86_l_54e6:
	/* 0x54e6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54eb:
	/* 0x54eb: cmp    WORD PTR [rax+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_54f3:
	/* 0x54f3: je     5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23298ULL;
	}
x86_l_54f9:
	/* 0x54f9: mov    ecx,DWORD PTR [rax+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_54ff:
	/* 0x54ff: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5503:
	/* 0x5503: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5507:
	/* 0x5507: cmp    WORD PTR [rax+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_550f:
	/* 0x550f: je     5531 <generic_sleepable_preload+0x5531> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5531;
	}
x86_l_5511:
	/* 0x5511: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5514:
	/* 0x5514: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5519:
	/* 0x5519: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_551e:
	/* 0x551e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5522:
	/* 0x5522: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5527:
	/* 0x5527: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5529:
	/* 0x5529: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_552b:
	/* 0x552b: js     5a29 <generic_sleepable_preload+0x5a29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23081ULL;
	}
x86_l_5531:
	/* 0x5531: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5536:
	/* 0x5536: cmp    WORD PTR [rax+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_553e:
	/* 0x553e: je     5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23298ULL;
	}
x86_l_5544:
	/* 0x5544: mov    ecx,DWORD PTR [rax+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_554a:
	/* 0x554a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_554e:
	/* 0x554e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5552:
	/* 0x5552: cmp    WORD PTR [rax+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_555a:
	/* 0x555a: je     557c <generic_sleepable_preload+0x557c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_557c;
	}
x86_l_555c:
	/* 0x555c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_555f:
	/* 0x555f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5564:
	/* 0x5564: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5569:
	/* 0x5569: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_556d:
	/* 0x556d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5572:
	/* 0x5572: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5574:
	/* 0x5574: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5576:
	/* 0x5576: js     5a3c <generic_sleepable_preload+0x5a3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23100ULL;
	}
x86_l_557c:
	/* 0x557c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5581:
	/* 0x5581: cmp    WORD PTR [rax+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_5589:
	/* 0x5589: je     5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23298ULL;
	}
x86_l_558f:
	/* 0x558f: mov    ecx,DWORD PTR [rax+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_5595:
	/* 0x5595: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5599:
	/* 0x5599: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_559d:
	/* 0x559d: cmp    WORD PTR [rax+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_55a5:
	/* 0x55a5: je     55c7 <generic_sleepable_preload+0x55c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_55c7;
	}
x86_l_55a7:
	/* 0x55a7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_55aa:
	/* 0x55aa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_55af:
	/* 0x55af: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_55b4:
	/* 0x55b4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55b8:
	/* 0x55b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55bd:
	/* 0x55bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55bf:
	/* 0x55bf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_55c1:
	/* 0x55c1: js     5a4f <generic_sleepable_preload+0x5a4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23119ULL;
	}
x86_l_55c7:
	/* 0x55c7: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55cc:
	/* 0x55cc: cmp    WORD PTR [rax+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_55d4:
	/* 0x55d4: je     5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23298ULL;
	}
x86_l_55da:
	/* 0x55da: mov    ecx,DWORD PTR [rax+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_55e0:
	/* 0x55e0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_55e4:
	/* 0x55e4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55e8:
	/* 0x55e8: cmp    WORD PTR [rax+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_55f0:
	/* 0x55f0: je     5612 <generic_sleepable_preload+0x5612> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5612;
	}
x86_l_55f2:
	/* 0x55f2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_55f5:
	/* 0x55f5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_55fa:
	/* 0x55fa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_55ff:
	/* 0x55ff: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5603:
	/* 0x5603: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5608:
	/* 0x5608: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_560a:
	/* 0x560a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_560c:
	/* 0x560c: js     5a62 <generic_sleepable_preload+0x5a62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23138ULL;
	}
x86_l_5612:
	/* 0x5612: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5617:
	/* 0x5617: cmp    WORD PTR [rax+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_561f:
	/* 0x561f: je     5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23298ULL;
	}
x86_l_5625:
	/* 0x5625: mov    ecx,DWORD PTR [rax+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_562b:
	/* 0x562b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_562f:
	/* 0x562f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5633:
	/* 0x5633: cmp    WORD PTR [rax+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_563b:
	/* 0x563b: je     565d <generic_sleepable_preload+0x565d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_565d;
	}
x86_l_563d:
	/* 0x563d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5640:
	/* 0x5640: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5645:
	/* 0x5645: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_564a:
	/* 0x564a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_564e:
	/* 0x564e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5653:
	/* 0x5653: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5655:
	/* 0x5655: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5657:
	/* 0x5657: js     5af9 <generic_sleepable_preload+0x5af9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23289ULL;
	}
x86_l_565d:
	/* 0x565d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5662:
	/* 0x5662: cmp    WORD PTR [rax+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_566a:
	/* 0x566a: je     5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23298ULL;
	}
x86_l_5670:
	/* 0x5670: mov    ecx,DWORD PTR [rax+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_5676:
	/* 0x5676: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_567a:
	/* 0x567a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_567e:
	/* 0x567e: cmp    WORD PTR [rax+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_5686:
	/* 0x5686: je     56a8 <generic_sleepable_preload+0x56a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56a8;
	}
x86_l_5688:
	/* 0x5688: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_568b:
	/* 0x568b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5690:
	/* 0x5690: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5695:
	/* 0x5695: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5699:
	/* 0x5699: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_569e:
	/* 0x569e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56a0:
	/* 0x56a0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56a2:
	/* 0x56a2: js     5bb9 <generic_sleepable_preload+0x5bb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23481ULL;
	}
x86_l_56a8:
	/* 0x56a8: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56ad:
	/* 0x56ad: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_56b5:
	/* 0x56b5: je     5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23298ULL;
	}
x86_l_56bb:
	/* 0x56bb: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_56c1:
	/* 0x56c1: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_56c5:
	/* 0x56c5: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56c9:
	/* 0x56c9: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_56d1:
	/* 0x56d1: je     56f3 <generic_sleepable_preload+0x56f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56f3;
	}
x86_l_56d3:
	/* 0x56d3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_56d6:
	/* 0x56d6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_56db:
	/* 0x56db: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_56e0:
	/* 0x56e0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56e4:
	/* 0x56e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56e9:
	/* 0x56e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56eb:
	/* 0x56eb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56ed:
	/* 0x56ed: js     5c43 <generic_sleepable_preload+0x5c43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23619ULL;
	}
x86_l_56f3:
	/* 0x56f3: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56f8:
	/* 0x56f8: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_5700:
	/* 0x5700: je     5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23298ULL;
	}
x86_l_5706:
	/* 0x5706: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_570c:
	/* 0x570c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5710:
	/* 0x5710: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5714:
	/* 0x5714: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_571c:
	/* 0x571c: je     5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23298ULL;
	}
x86_l_5722:
	/* 0x5722: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5725:
	/* 0x5725: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_572a:
	/* 0x572a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_572f:
	/* 0x572f: jmp    59ed <generic_sleepable_preload+0x59ed> */
	return 23021ULL;
x86_l_5734:
	/* 0x5734: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_5737:
	/* 0x5737: je     5759 <generic_sleepable_preload+0x5759> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5759;
	}
x86_l_5739:
	/* 0x5739: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_573c:
	/* 0x573c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5741:
	/* 0x5741: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5746:
	/* 0x5746: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_574a:
	/* 0x574a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_574f:
	/* 0x574f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5751:
	/* 0x5751: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5753:
	/* 0x5753: js     5a0b <generic_sleepable_preload+0x5a0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23051ULL;
	}
x86_l_5759:
	/* 0x5759: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_575e:
	/* 0x575e: cmp    WORD PTR [rax+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_5766:
	/* 0x5766: je     5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23298ULL;
	}
x86_l_576c:
	/* 0x576c: mov    ecx,DWORD PTR [rax+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_5772:
	/* 0x5772: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5776:
	/* 0x5776: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_577a:
	/* 0x577a: cmp    WORD PTR [rax+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_5782:
	/* 0x5782: je     57a4 <generic_sleepable_preload+0x57a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_57a4;
	}
x86_l_5784:
	/* 0x5784: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5787:
	/* 0x5787: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_578c:
	/* 0x578c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5791:
	/* 0x5791: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5795:
	/* 0x5795: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_579a:
	/* 0x579a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_579c:
	/* 0x579c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_579e:
	/* 0x579e: js     5a16 <generic_sleepable_preload+0x5a16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23062ULL;
	}
x86_l_57a4:
	/* 0x57a4: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57a9:
	/* 0x57a9: cmp    WORD PTR [rax+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_57b1:
	/* 0x57b1: je     5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23298ULL;
	}
x86_l_57b7:
	/* 0x57b7: mov    ecx,DWORD PTR [rax+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_57bd:
	/* 0x57bd: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_57c1:
	/* 0x57c1: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57c5:
	/* 0x57c5: cmp    WORD PTR [rax+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_57cd:
	/* 0x57cd: je     57ef <generic_sleepable_preload+0x57ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_57ef;
	}
x86_l_57cf:
	/* 0x57cf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_57d2:
	/* 0x57d2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_57d7:
	/* 0x57d7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_57dc:
	/* 0x57dc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57e0:
	/* 0x57e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57e5:
	/* 0x57e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57e7:
	/* 0x57e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_57e9:
	/* 0x57e9: js     5a29 <generic_sleepable_preload+0x5a29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23081ULL;
	}
x86_l_57ef:
	/* 0x57ef: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57f4:
	/* 0x57f4: cmp    WORD PTR [rax+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_57fc:
	/* 0x57fc: je     5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23298ULL;
	}
x86_l_5802:
	/* 0x5802: mov    ecx,DWORD PTR [rax+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_5808:
	/* 0x5808: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_580c:
	/* 0x580c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5810:
	/* 0x5810: cmp    WORD PTR [rax+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_5818:
	/* 0x5818: je     583a <generic_sleepable_preload+0x583a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_583a;
	}
x86_l_581a:
	/* 0x581a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_581d:
	/* 0x581d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5822:
	/* 0x5822: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5827:
	/* 0x5827: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_582b:
	/* 0x582b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5830:
	/* 0x5830: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5832:
	/* 0x5832: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5834:
	/* 0x5834: js     5a3c <generic_sleepable_preload+0x5a3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23100ULL;
	}
x86_l_583a:
	/* 0x583a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_583f:
	/* 0x583f: cmp    WORD PTR [rax+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_5847:
	/* 0x5847: je     5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23298ULL;
	}
x86_l_584d:
	/* 0x584d: mov    ecx,DWORD PTR [rax+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_5853:
	/* 0x5853: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5857:
	/* 0x5857: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_585b:
	/* 0x585b: cmp    WORD PTR [rax+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_5863:
	/* 0x5863: je     5885 <generic_sleepable_preload+0x5885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5885;
	}
x86_l_5865:
	/* 0x5865: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5868:
	/* 0x5868: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_586d:
	/* 0x586d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5872:
	/* 0x5872: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5876:
	/* 0x5876: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_587b:
	/* 0x587b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_587d:
	/* 0x587d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_587f:
	/* 0x587f: js     5a4f <generic_sleepable_preload+0x5a4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23119ULL;
	}
x86_l_5885:
	/* 0x5885: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_588a:
	/* 0x588a: cmp    WORD PTR [rax+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_5892:
	/* 0x5892: je     5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23298ULL;
	}
x86_l_5898:
	/* 0x5898: mov    ecx,DWORD PTR [rax+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_589e:
	/* 0x589e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_58a2:
	/* 0x58a2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58a6:
	/* 0x58a6: cmp    WORD PTR [rax+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_58ae:
	/* 0x58ae: je     58d0 <generic_sleepable_preload+0x58d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58d0;
	}
x86_l_58b0:
	/* 0x58b0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_58b3:
	/* 0x58b3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_58b8:
	/* 0x58b8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_58bd:
	/* 0x58bd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58c1:
	/* 0x58c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58c6:
	/* 0x58c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58c8:
	/* 0x58c8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_58ca:
	/* 0x58ca: js     5a62 <generic_sleepable_preload+0x5a62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23138ULL;
	}
x86_l_58d0:
	/* 0x58d0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58d5:
	/* 0x58d5: cmp    WORD PTR [rax+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_58dd:
	/* 0x58dd: je     5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23298ULL;
	}
x86_l_58e3:
	/* 0x58e3: mov    ecx,DWORD PTR [rax+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_58e9:
	/* 0x58e9: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_58ed:
	/* 0x58ed: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58f1:
	/* 0x58f1: cmp    WORD PTR [rax+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_58f9:
	/* 0x58f9: je     591b <generic_sleepable_preload+0x591b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_591b;
	}
x86_l_58fb:
	/* 0x58fb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_58fe:
	/* 0x58fe: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5903:
	/* 0x5903: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5908:
	/* 0x5908: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_590c:
	/* 0x590c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5911:
	/* 0x5911: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5913:
	/* 0x5913: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5915:
	/* 0x5915: js     5af9 <generic_sleepable_preload+0x5af9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23289ULL;
	}
x86_l_591b:
	/* 0x591b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5920:
	/* 0x5920: cmp    WORD PTR [rax+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_5928:
	/* 0x5928: je     5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23298ULL;
	}
x86_l_592e:
	/* 0x592e: mov    ecx,DWORD PTR [rax+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_5934:
	/* 0x5934: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5938:
	/* 0x5938: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_593c:
	/* 0x593c: cmp    WORD PTR [rax+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_5944:
	/* 0x5944: je     5966 <generic_sleepable_preload+0x5966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5966;
	}
x86_l_5946:
	/* 0x5946: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5949:
	/* 0x5949: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_594e:
	/* 0x594e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5953:
	/* 0x5953: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5957:
	/* 0x5957: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_595c:
	/* 0x595c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_595e:
	/* 0x595e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5960:
	/* 0x5960: js     5bb9 <generic_sleepable_preload+0x5bb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23481ULL;
	}
x86_l_5966:
	/* 0x5966: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_596b:
	/* 0x596b: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_5973:
	/* 0x5973: je     5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23298ULL;
	}
x86_l_5979:
	/* 0x5979: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_597f:
	/* 0x597f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5983:
	/* 0x5983: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5987:
	/* 0x5987: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_598f:
	/* 0x598f: je     59b1 <generic_sleepable_preload+0x59b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22961ULL;
	}
x86_l_5991:
	/* 0x5991: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5994:
	/* 0x5994: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5999:
	/* 0x5999: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_599e:
	/* 0x599e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59a2:
	/* 0x59a2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 22951ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 22951ULL: goto x86_l_59a7;
	case 22953ULL: goto x86_l_59a9;
	case 22955ULL: goto x86_l_59ab;
	case 22961ULL: goto x86_l_59b1;
	case 22966ULL: goto x86_l_59b6;
	case 22974ULL: goto x86_l_59be;
	case 22980ULL: goto x86_l_59c4;
	case 22986ULL: goto x86_l_59ca;
	case 22990ULL: goto x86_l_59ce;
	case 22994ULL: goto x86_l_59d2;
	case 23002ULL: goto x86_l_59da;
	case 23008ULL: goto x86_l_59e0;
	case 23011ULL: goto x86_l_59e3;
	case 23016ULL: goto x86_l_59e8;
	case 23021ULL: goto x86_l_59ed;
	case 23025ULL: goto x86_l_59f1;
	case 23030ULL: goto x86_l_59f6;
	case 23032ULL: goto x86_l_59f8;
	case 23034ULL: goto x86_l_59fa;
	case 23040ULL: goto x86_l_5a00;
	case 23046ULL: goto x86_l_5a06;
	case 23051ULL: goto x86_l_5a0b;
	case 23057ULL: goto x86_l_5a11;
	case 23062ULL: goto x86_l_5a16;
	case 23068ULL: goto x86_l_5a1c;
	case 23073ULL: goto x86_l_5a21;
	case 23079ULL: goto x86_l_5a27;
	case 23081ULL: goto x86_l_5a29;
	case 23087ULL: goto x86_l_5a2f;
	case 23092ULL: goto x86_l_5a34;
	case 23098ULL: goto x86_l_5a3a;
	case 23100ULL: goto x86_l_5a3c;
	case 23106ULL: goto x86_l_5a42;
	case 23111ULL: goto x86_l_5a47;
	case 23117ULL: goto x86_l_5a4d;
	case 23119ULL: goto x86_l_5a4f;
	case 23125ULL: goto x86_l_5a55;
	case 23130ULL: goto x86_l_5a5a;
	case 23136ULL: goto x86_l_5a60;
	case 23138ULL: goto x86_l_5a62;
	case 23144ULL: goto x86_l_5a68;
	case 23149ULL: goto x86_l_5a6d;
	case 23155ULL: goto x86_l_5a73;
	case 23158ULL: goto x86_l_5a76;
	case 23163ULL: goto x86_l_5a7b;
	case 23166ULL: goto x86_l_5a7e;
	case 23169ULL: goto x86_l_5a81;
	case 23174ULL: goto x86_l_5a86;
	case 23179ULL: goto x86_l_5a8b;
	case 23184ULL: goto x86_l_5a90;
	case 23187ULL: goto x86_l_5a93;
	case 23189ULL: goto x86_l_5a95;
	case 23192ULL: goto x86_l_5a98;
	case 23198ULL: goto x86_l_5a9e;
	case 23202ULL: goto x86_l_5aa2;
	case 23207ULL: goto x86_l_5aa7;
	case 23209ULL: goto x86_l_5aa9;
	case 23214ULL: goto x86_l_5aae;
	case 23222ULL: goto x86_l_5ab6;
	case 23229ULL: goto x86_l_5abd;
	case 23234ULL: goto x86_l_5ac2;
	case 23239ULL: goto x86_l_5ac7;
	case 23241ULL: goto x86_l_5ac9;
	case 23244ULL: goto x86_l_5acc;
	case 23250ULL: goto x86_l_5ad2;
	case 23253ULL: goto x86_l_5ad5;
	case 23260ULL: goto x86_l_5adc;
	case 23262ULL: goto x86_l_5ade;
	case 23267ULL: goto x86_l_5ae3;
	case 23272ULL: goto x86_l_5ae8;
	case 23275ULL: goto x86_l_5aeb;
	case 23278ULL: goto x86_l_5aee;
	case 23280ULL: goto x86_l_5af0;
	case 23282ULL: goto x86_l_5af2;
	case 23287ULL: goto x86_l_5af7;
	case 23289ULL: goto x86_l_5af9;
	case 23295ULL: goto x86_l_5aff;
	case 23298ULL: goto x86_l_5b02;
	case 23301ULL: goto x86_l_5b05;
	case 23307ULL: goto x86_l_5b0b;
	case 23311ULL: goto x86_l_5b0f;
	case 23316ULL: goto x86_l_5b14;
	case 23318ULL: goto x86_l_5b16;
	case 23323ULL: goto x86_l_5b1b;
	case 23331ULL: goto x86_l_5b23;
	case 23338ULL: goto x86_l_5b2a;
	case 23343ULL: goto x86_l_5b2f;
	case 23348ULL: goto x86_l_5b34;
	case 23350ULL: goto x86_l_5b36;
	case 23353ULL: goto x86_l_5b39;
	case 23359ULL: goto x86_l_5b3f;
	case 23362ULL: goto x86_l_5b42;
	case 23369ULL: goto x86_l_5b49;
	case 23371ULL: goto x86_l_5b4b;
	case 23376ULL: goto x86_l_5b50;
	case 23381ULL: goto x86_l_5b55;
	case 23384ULL: goto x86_l_5b58;
	case 23387ULL: goto x86_l_5b5b;
	case 23389ULL: goto x86_l_5b5d;
	case 23391ULL: goto x86_l_5b5f;
	case 23396ULL: goto x86_l_5b64;
	case 23399ULL: goto x86_l_5b67;
	case 23402ULL: goto x86_l_5b6a;
	case 23404ULL: goto x86_l_5b6c;
	case 23407ULL: goto x86_l_5b6f;
	case 23413ULL: goto x86_l_5b75;
	case 23416ULL: goto x86_l_5b78;
	case 23418ULL: goto x86_l_5b7a;
	case 23421ULL: goto x86_l_5b7d;
	case 23425ULL: goto x86_l_5b81;
	case 23430ULL: goto x86_l_5b86;
	case 23433ULL: goto x86_l_5b89;
	case 23435ULL: goto x86_l_5b8b;
	case 23438ULL: goto x86_l_5b8e;
	case 23443ULL: goto x86_l_5b93;
	case 23445ULL: goto x86_l_5b95;
	case 23448ULL: goto x86_l_5b98;
	case 23450ULL: goto x86_l_5b9a;
	case 23455ULL: goto x86_l_5b9f;
	case 23459ULL: goto x86_l_5ba3;
	case 23462ULL: goto x86_l_5ba6;
	case 23467ULL: goto x86_l_5bab;
	case 23470ULL: goto x86_l_5bae;
	case 23476ULL: goto x86_l_5bb4;
	case 23481ULL: goto x86_l_5bb9;
	case 23484ULL: goto x86_l_5bbc;
	case 23490ULL: goto x86_l_5bc2;
	case 23493ULL: goto x86_l_5bc5;
	case 23499ULL: goto x86_l_5bcb;
	case 23504ULL: goto x86_l_5bd0;
	case 23507ULL: goto x86_l_5bd3;
	case 23512ULL: goto x86_l_5bd8;
	case 23517ULL: goto x86_l_5bdd;
	case 23520ULL: goto x86_l_5be0;
	case 23525ULL: goto x86_l_5be5;
	case 23530ULL: goto x86_l_5bea;
	case 23533ULL: goto x86_l_5bed;
	case 23538ULL: goto x86_l_5bf2;
	case 23543ULL: goto x86_l_5bf7;
	case 23546ULL: goto x86_l_5bfa;
	case 23551ULL: goto x86_l_5bff;
	case 23556ULL: goto x86_l_5c04;
	case 23559ULL: goto x86_l_5c07;
	case 23564ULL: goto x86_l_5c0c;
	case 23569ULL: goto x86_l_5c11;
	case 23572ULL: goto x86_l_5c14;
	case 23577ULL: goto x86_l_5c19;
	case 23582ULL: goto x86_l_5c1e;
	case 23585ULL: goto x86_l_5c21;
	case 23590ULL: goto x86_l_5c26;
	case 23595ULL: goto x86_l_5c2b;
	case 23598ULL: goto x86_l_5c2e;
	case 23603ULL: goto x86_l_5c33;
	case 23608ULL: goto x86_l_5c38;
	case 23614ULL: goto x86_l_5c3e;
	case 23619ULL: goto x86_l_5c43;
	case 23625ULL: goto x86_l_5c49;
	case 23630ULL: goto x86_l_5c4e;
	case 23633ULL: goto x86_l_5c51;
	case 23638ULL: goto x86_l_5c56;
	case 23643ULL: goto x86_l_5c5b;
	case 23646ULL: goto x86_l_5c5e;
	case 23651ULL: goto x86_l_5c63;
	case 23656ULL: goto x86_l_5c68;
	case 23659ULL: goto x86_l_5c6b;
	case 23664ULL: goto x86_l_5c70;
	case 23669ULL: goto x86_l_5c75;
	case 23672ULL: goto x86_l_5c78;
	case 23677ULL: goto x86_l_5c7d;
	case 23682ULL: goto x86_l_5c82;
	case 23685ULL: goto x86_l_5c85;
	case 23690ULL: goto x86_l_5c8a;
	case 23695ULL: goto x86_l_5c8f;
	case 23698ULL: goto x86_l_5c92;
	case 23703ULL: goto x86_l_5c97;
	case 23708ULL: goto x86_l_5c9c;
	case 23711ULL: goto x86_l_5c9f;
	case 23716ULL: goto x86_l_5ca4;
	case 23721ULL: goto x86_l_5ca9;
	case 23724ULL: goto x86_l_5cac;
	case 23729ULL: goto x86_l_5cb1;
	case 23734ULL: goto x86_l_5cb6;
	case 23739ULL: goto x86_l_5cbb;
	case 23742ULL: goto x86_l_5cbe;
	case 23747ULL: goto x86_l_5cc3;
	case 23752ULL: goto x86_l_5cc8;
	case 23757ULL: goto x86_l_5ccd;
	case 23760ULL: goto x86_l_5cd0;
	case 23765ULL: goto x86_l_5cd5;
	case 23770ULL: goto x86_l_5cda;
	case 23775ULL: goto x86_l_5cdf;
	case 23778ULL: goto x86_l_5ce2;
	case 23783ULL: goto x86_l_5ce7;
	case 23788ULL: goto x86_l_5cec;
	case 23793ULL: goto x86_l_5cf1;
	case 23796ULL: goto x86_l_5cf4;
	case 23801ULL: goto x86_l_5cf9;
	case 23806ULL: goto x86_l_5cfe;
	case 23811ULL: goto x86_l_5d03;
	case 23814ULL: goto x86_l_5d06;
	case 23819ULL: goto x86_l_5d0b;
	case 23824ULL: goto x86_l_5d10;
	case 23829ULL: goto x86_l_5d15;
	case 23832ULL: goto x86_l_5d18;
	case 23837ULL: goto x86_l_5d1d;
	case 23842ULL: goto x86_l_5d22;
	case 23847ULL: goto x86_l_5d27;
	case 23850ULL: goto x86_l_5d2a;
	case 23855ULL: goto x86_l_5d2f;
	case 23860ULL: goto x86_l_5d34;
	case 23865ULL: goto x86_l_5d39;
	case 23868ULL: goto x86_l_5d3c;
	case 23873ULL: goto x86_l_5d41;
	case 23878ULL: goto x86_l_5d46;
	case 23883ULL: goto x86_l_5d4b;
	case 23886ULL: goto x86_l_5d4e;
	case 23891ULL: goto x86_l_5d53;
	case 23894ULL: goto x86_l_5d56;
	case 23899ULL: goto x86_l_5d5b;
	case 23904ULL: goto x86_l_5d60;
	case 23907ULL: goto x86_l_5d63;
	case 23912ULL: goto x86_l_5d68;
	case 23915ULL: goto x86_l_5d6b;
	case 23920ULL: goto x86_l_5d70;
	case 23925ULL: goto x86_l_5d75;
	case 23928ULL: goto x86_l_5d78;
	case 23933ULL: goto x86_l_5d7d;
	case 23936ULL: goto x86_l_5d80;
	case 23941ULL: goto x86_l_5d85;
	case 23946ULL: goto x86_l_5d8a;
	case 23949ULL: goto x86_l_5d8d;
	case 23954ULL: goto x86_l_5d92;
	case 23957ULL: goto x86_l_5d95;
	case 23962ULL: goto x86_l_5d9a;
	case 23967ULL: goto x86_l_5d9f;
	case 23970ULL: goto x86_l_5da2;
	case 23975ULL: goto x86_l_5da7;
	case 23978ULL: goto x86_l_5daa;
	case 23983ULL: goto x86_l_5daf;
	case 23988ULL: goto x86_l_5db4;
	case 23991ULL: goto x86_l_5db7;
	case 23996ULL: goto x86_l_5dbc;
	case 23999ULL: goto x86_l_5dbf;
	case 24004ULL: goto x86_l_5dc4;
	case 24009ULL: goto x86_l_5dc9;
	case 24012ULL: goto x86_l_5dcc;
	case 24017ULL: goto x86_l_5dd1;
	case 24020ULL: goto x86_l_5dd4;
	case 24025ULL: goto x86_l_5dd9;
	case 24030ULL: goto x86_l_5dde;
	case 24033ULL: goto x86_l_5de1;
	case 24038ULL: goto x86_l_5de6;
	case 24041ULL: goto x86_l_5de9;
	default: return 0xffffffffffffffffULL;
	}
x86_l_59a7:
	/* 0x59a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59a9:
	/* 0x59a9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_59ab:
	/* 0x59ab: js     5c43 <generic_sleepable_preload+0x5c43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_5c43;
	}
x86_l_59b1:
	/* 0x59b1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59b6:
	/* 0x59b6: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_59be:
	/* 0x59be: je     5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b02;
	}
x86_l_59c4:
	/* 0x59c4: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_59ca:
	/* 0x59ca: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_59ce:
	/* 0x59ce: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59d2:
	/* 0x59d2: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_59da:
	/* 0x59da: je     5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b02;
	}
x86_l_59e0:
	/* 0x59e0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_59e3:
	/* 0x59e3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_59e8:
	/* 0x59e8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_59ed:
	/* 0x59ed: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59f1:
	/* 0x59f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59f6:
	/* 0x59f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59f8:
	/* 0x59f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_59fa:
	/* 0x59fa: jns    5b02 <generic_sleepable_preload+0x5b02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_5b02;
	}
x86_l_5a00:
	/* 0x5a00: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_5a06:
	/* 0x5a06: jmp    5aff <generic_sleepable_preload+0x5aff> */
	goto x86_l_5aff;
x86_l_5a0b:
	/* 0x5a0b: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_5a11:
	/* 0x5a11: jmp    5aff <generic_sleepable_preload+0x5aff> */
	goto x86_l_5aff;
x86_l_5a16:
	/* 0x5a16: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_5a1c:
	/* 0x5a1c: jmp    5aff <generic_sleepable_preload+0x5aff> */
	goto x86_l_5aff;
x86_l_5a21:
	/* 0x5a21: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_5a27:
	/* 0x5a27: jmp    5a73 <generic_sleepable_preload+0x5a73> */
	goto x86_l_5a73;
x86_l_5a29:
	/* 0x5a29: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_5a2f:
	/* 0x5a2f: jmp    5aff <generic_sleepable_preload+0x5aff> */
	goto x86_l_5aff;
x86_l_5a34:
	/* 0x5a34: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_5a3a:
	/* 0x5a3a: jmp    5a73 <generic_sleepable_preload+0x5a73> */
	goto x86_l_5a73;
x86_l_5a3c:
	/* 0x5a3c: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_5a42:
	/* 0x5a42: jmp    5aff <generic_sleepable_preload+0x5aff> */
	goto x86_l_5aff;
x86_l_5a47:
	/* 0x5a47: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_5a4d:
	/* 0x5a4d: jmp    5a73 <generic_sleepable_preload+0x5a73> */
	goto x86_l_5a73;
x86_l_5a4f:
	/* 0x5a4f: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_5a55:
	/* 0x5a55: jmp    5aff <generic_sleepable_preload+0x5aff> */
	goto x86_l_5aff;
x86_l_5a5a:
	/* 0x5a5a: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_5a60:
	/* 0x5a60: jmp    5a73 <generic_sleepable_preload+0x5a73> */
	goto x86_l_5a73;
x86_l_5a62:
	/* 0x5a62: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_5a68:
	/* 0x5a68: jmp    5aff <generic_sleepable_preload+0x5aff> */
	goto x86_l_5aff;
x86_l_5a6d:
	/* 0x5a6d: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_5a73:
	/* 0x5a73: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5a76:
	/* 0x5a76: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a7b:
	/* 0x5a7b: mov    ebx,DWORD PTR [rax+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5a7e:
	/* 0x5a7e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5a81:
	/* 0x5a81: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5a86:
	/* 0x5a86: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5a8b:
	/* 0x5a8b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a90:
	/* 0x5a90: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_5a93:
	/* 0x5a93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a95:
	/* 0x5a95: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_5a98:
	/* 0x5a98: jne    4c7a <generic_sleepable_preload+0x4c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19578ULL;
	}
x86_l_5a9e:
	/* 0x5a9e: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5aa2:
	/* 0x5aa2: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5aa7:
	/* 0x5aa7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5aa9:
	/* 0x5aa9: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5aae:
	/* 0x5aae: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_5ab6:
	/* 0x5ab6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5abd:
	/* 0x5abd: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5ac2:
	/* 0x5ac2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5ac7:
	/* 0x5ac7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ac9:
	/* 0x5ac9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5acc:
	/* 0x5acc: je     4c7a <generic_sleepable_preload+0x4c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19578ULL;
	}
x86_l_5ad2:
	/* 0x5ad2: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5ad5:
	/* 0x5ad5: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_5adc:
	/* 0x5adc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ade:
	/* 0x5ade: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ae3:
	/* 0x5ae3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5ae8:
	/* 0x5ae8: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5aeb:
	/* 0x5aeb: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5aee:
	/* 0x5aee: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5af0:
	/* 0x5af0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5af2:
	/* 0x5af2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5af7:
	/* 0x5af7: jmp    5b64 <generic_sleepable_preload+0x5b64> */
	goto x86_l_5b64;
x86_l_5af9:
	/* 0x5af9: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_5aff:
	/* 0x5aff: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b02:
	/* 0x5b02: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_5b05:
	/* 0x5b05: jne    4c7a <generic_sleepable_preload+0x4c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19578ULL;
	}
x86_l_5b0b:
	/* 0x5b0b: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b0f:
	/* 0x5b0f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5b14:
	/* 0x5b14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b16:
	/* 0x5b16: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b1b:
	/* 0x5b1b: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_5b23:
	/* 0x5b23: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5b2a:
	/* 0x5b2a: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5b2f:
	/* 0x5b2f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5b34:
	/* 0x5b34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b36:
	/* 0x5b36: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b39:
	/* 0x5b39: je     4c7a <generic_sleepable_preload+0x4c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19578ULL;
	}
x86_l_5b3f:
	/* 0x5b3f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5b42:
	/* 0x5b42: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_5b49:
	/* 0x5b49: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b4b:
	/* 0x5b4b: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b50:
	/* 0x5b50: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5b55:
	/* 0x5b55: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5b58:
	/* 0x5b58: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5b5b:
	/* 0x5b5b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b5d:
	/* 0x5b5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b5f:
	/* 0x5b5f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5b64:
	/* 0x5b64: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5b67:
	/* 0x5b67: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5b6a:
	/* 0x5b6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b6c:
	/* 0x5b6c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b6f:
	/* 0x5b6f: je     4c7a <generic_sleepable_preload+0x4c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19578ULL;
	}
x86_l_5b75:
	/* 0x5b75: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_5b78:
	/* 0x5b78: je     5ba3 <generic_sleepable_preload+0x5ba3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ba3;
	}
x86_l_5b7a:
	/* 0x5b7a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_5b7d:
	/* 0x5b7d: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_5b81:
	/* 0x5b81: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5b86:
	/* 0x5b86: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_5b89:
	/* 0x5b89: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b8b:
	/* 0x5b8b: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_5b8e:
	/* 0x5b8e: call   5b93 <generic_sleepable_preload+0x5b93> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_5b93:
	/* 0x5b93: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_5b95:
	/* 0x5b95: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_5b98:
	/* 0x5b98: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_5b9a:
	/* 0x5b9a: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_5b9f:
	/* 0x5b9f: cmovs  r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_5ba3:
	/* 0x5ba3: mov    DWORD PTR [rax],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ba6:
	/* 0x5ba6: jmp    4c7a <generic_sleepable_preload+0x4c7a> */
	return 19578ULL;
x86_l_5bab:
	/* 0x5bab: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bae:
	/* 0x5bae: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_5bb4:
	/* 0x5bb4: jmp    5a76 <generic_sleepable_preload+0x5a76> */
	goto x86_l_5a76;
x86_l_5bb9:
	/* 0x5bb9: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bbc:
	/* 0x5bbc: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_5bc2:
	/* 0x5bc2: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_5bc5:
	/* 0x5bc5: jne    4c7a <generic_sleepable_preload+0x4c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19578ULL;
	}
x86_l_5bcb:
	/* 0x5bcb: jmp    5b0b <generic_sleepable_preload+0x5b0b> */
	goto x86_l_5b0b;
x86_l_5bd0:
	/* 0x5bd0: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bd3:
	/* 0x5bd3: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5bd8:
	/* 0x5bd8: jmp    1cfe <generic_sleepable_preload+0x1cfe> */
	return 7422ULL;
x86_l_5bdd:
	/* 0x5bdd: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5be0:
	/* 0x5be0: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5be5:
	/* 0x5be5: jmp    1d89 <generic_sleepable_preload+0x1d89> */
	return 7561ULL;
x86_l_5bea:
	/* 0x5bea: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bed:
	/* 0x5bed: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5bf2:
	/* 0x5bf2: jmp    2c68 <generic_sleepable_preload+0x2c68> */
	return 11368ULL;
x86_l_5bf7:
	/* 0x5bf7: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bfa:
	/* 0x5bfa: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5bff:
	/* 0x5bff: jmp    2cf3 <generic_sleepable_preload+0x2cf3> */
	return 11507ULL;
x86_l_5c04:
	/* 0x5c04: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c07:
	/* 0x5c07: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c0c:
	/* 0x5c0c: jmp    3bd3 <generic_sleepable_preload+0x3bd3> */
	return 15315ULL;
x86_l_5c11:
	/* 0x5c11: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c14:
	/* 0x5c14: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c19:
	/* 0x5c19: jmp    3c5e <generic_sleepable_preload+0x3c5e> */
	return 15454ULL;
x86_l_5c1e:
	/* 0x5c1e: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c21:
	/* 0x5c21: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c26:
	/* 0x5c26: jmp    4b3e <generic_sleepable_preload+0x4b3e> */
	return 19262ULL;
x86_l_5c2b:
	/* 0x5c2b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c2e:
	/* 0x5c2e: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c33:
	/* 0x5c33: jmp    4bc9 <generic_sleepable_preload+0x4bc9> */
	return 19401ULL;
x86_l_5c38:
	/* 0x5c38: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_5c3e:
	/* 0x5c3e: jmp    5a73 <generic_sleepable_preload+0x5a73> */
	goto x86_l_5a73;
x86_l_5c43:
	/* 0x5c43: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_5c49:
	/* 0x5c49: jmp    5aff <generic_sleepable_preload+0x5aff> */
	goto x86_l_5aff;
x86_l_5c4e:
	/* 0x5c4e: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c51:
	/* 0x5c51: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c56:
	/* 0x5c56: jmp    5d4e <generic_sleepable_preload+0x5d4e> */
	goto x86_l_5d4e;
x86_l_5c5b:
	/* 0x5c5b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c5e:
	/* 0x5c5e: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c63:
	/* 0x5c63: jmp    5d63 <generic_sleepable_preload+0x5d63> */
	goto x86_l_5d63;
x86_l_5c68:
	/* 0x5c68: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c6b:
	/* 0x5c6b: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c70:
	/* 0x5c70: jmp    5d78 <generic_sleepable_preload+0x5d78> */
	goto x86_l_5d78;
x86_l_5c75:
	/* 0x5c75: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c78:
	/* 0x5c78: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c7d:
	/* 0x5c7d: jmp    5d8d <generic_sleepable_preload+0x5d8d> */
	goto x86_l_5d8d;
x86_l_5c82:
	/* 0x5c82: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c85:
	/* 0x5c85: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c8a:
	/* 0x5c8a: jmp    5da2 <generic_sleepable_preload+0x5da2> */
	goto x86_l_5da2;
x86_l_5c8f:
	/* 0x5c8f: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c92:
	/* 0x5c92: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c97:
	/* 0x5c97: jmp    5db7 <generic_sleepable_preload+0x5db7> */
	goto x86_l_5db7;
x86_l_5c9c:
	/* 0x5c9c: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c9f:
	/* 0x5c9f: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5ca4:
	/* 0x5ca4: jmp    5dcc <generic_sleepable_preload+0x5dcc> */
	goto x86_l_5dcc;
x86_l_5ca9:
	/* 0x5ca9: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5cac:
	/* 0x5cac: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5cb1:
	/* 0x5cb1: jmp    5de1 <generic_sleepable_preload+0x5de1> */
	goto x86_l_5de1;
x86_l_5cb6:
	/* 0x5cb6: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5cbb:
	/* 0x5cbb: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5cbe:
	/* 0x5cbe: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cc3:
	/* 0x5cc3: jmp    1cfe <generic_sleepable_preload+0x1cfe> */
	return 7422ULL;
x86_l_5cc8:
	/* 0x5cc8: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5ccd:
	/* 0x5ccd: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5cd0:
	/* 0x5cd0: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cd5:
	/* 0x5cd5: jmp    1d89 <generic_sleepable_preload+0x1d89> */
	return 7561ULL;
x86_l_5cda:
	/* 0x5cda: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5cdf:
	/* 0x5cdf: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ce2:
	/* 0x5ce2: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ce7:
	/* 0x5ce7: jmp    2c68 <generic_sleepable_preload+0x2c68> */
	return 11368ULL;
x86_l_5cec:
	/* 0x5cec: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5cf1:
	/* 0x5cf1: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5cf4:
	/* 0x5cf4: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cf9:
	/* 0x5cf9: jmp    2cf3 <generic_sleepable_preload+0x2cf3> */
	return 11507ULL;
x86_l_5cfe:
	/* 0x5cfe: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d03:
	/* 0x5d03: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d06:
	/* 0x5d06: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d0b:
	/* 0x5d0b: jmp    3bd3 <generic_sleepable_preload+0x3bd3> */
	return 15315ULL;
x86_l_5d10:
	/* 0x5d10: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d15:
	/* 0x5d15: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d18:
	/* 0x5d18: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d1d:
	/* 0x5d1d: jmp    3c5e <generic_sleepable_preload+0x3c5e> */
	return 15454ULL;
x86_l_5d22:
	/* 0x5d22: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d27:
	/* 0x5d27: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d2a:
	/* 0x5d2a: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d2f:
	/* 0x5d2f: jmp    4b3e <generic_sleepable_preload+0x4b3e> */
	return 19262ULL;
x86_l_5d34:
	/* 0x5d34: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d39:
	/* 0x5d39: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d3c:
	/* 0x5d3c: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d41:
	/* 0x5d41: jmp    4bc9 <generic_sleepable_preload+0x4bc9> */
	return 19401ULL;
x86_l_5d46:
	/* 0x5d46: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d4b:
	/* 0x5d4b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d4e:
	/* 0x5d4e: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d53:
	/* 0x5d53: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5d56:
	/* 0x5d56: jmp    1cfe <generic_sleepable_preload+0x1cfe> */
	return 7422ULL;
x86_l_5d5b:
	/* 0x5d5b: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d60:
	/* 0x5d60: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d63:
	/* 0x5d63: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d68:
	/* 0x5d68: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5d6b:
	/* 0x5d6b: jmp    1d89 <generic_sleepable_preload+0x1d89> */
	return 7561ULL;
x86_l_5d70:
	/* 0x5d70: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d75:
	/* 0x5d75: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d78:
	/* 0x5d78: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d7d:
	/* 0x5d7d: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5d80:
	/* 0x5d80: jmp    2c68 <generic_sleepable_preload+0x2c68> */
	return 11368ULL;
x86_l_5d85:
	/* 0x5d85: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d8a:
	/* 0x5d8a: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d8d:
	/* 0x5d8d: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d92:
	/* 0x5d92: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5d95:
	/* 0x5d95: jmp    2cf3 <generic_sleepable_preload+0x2cf3> */
	return 11507ULL;
x86_l_5d9a:
	/* 0x5d9a: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d9f:
	/* 0x5d9f: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5da2:
	/* 0x5da2: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5da7:
	/* 0x5da7: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5daa:
	/* 0x5daa: jmp    3bd3 <generic_sleepable_preload+0x3bd3> */
	return 15315ULL;
x86_l_5daf:
	/* 0x5daf: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5db4:
	/* 0x5db4: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5db7:
	/* 0x5db7: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dbc:
	/* 0x5dbc: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5dbf:
	/* 0x5dbf: jmp    3c5e <generic_sleepable_preload+0x3c5e> */
	return 15454ULL;
x86_l_5dc4:
	/* 0x5dc4: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5dc9:
	/* 0x5dc9: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5dcc:
	/* 0x5dcc: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dd1:
	/* 0x5dd1: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5dd4:
	/* 0x5dd4: jmp    4b3e <generic_sleepable_preload+0x4b3e> */
	return 19262ULL;
x86_l_5dd9:
	/* 0x5dd9: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5dde:
	/* 0x5dde: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5de1:
	/* 0x5de1: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5de6:
	/* 0x5de6: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5de9:
	/* 0x5de9: jmp    4bc9 <generic_sleepable_preload+0x4bc9> */
	return 19401ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 20980U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1630ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1636ULL && __x86_pc <= 3183ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3185ULL && __x86_pc <= 4928ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4933ULL && __x86_pc <= 6748ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6754ULL && __x86_pc <= 8510ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8515ULL && __x86_pc <= 10371ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10381ULL && __x86_pc <= 12134ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12138ULL && __x86_pc <= 13999ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14004ULL && __x86_pc <= 15790ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 15796ULL && __x86_pc <= 17628ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 17633ULL && __x86_pc <= 19489ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 19491ULL && __x86_pc <= 21197ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 21201ULL && __x86_pc <= 22946ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 22951ULL && __x86_pc <= 24041ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_13(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

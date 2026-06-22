extern char binary_filter_version;
extern char cgroup_id_filter_version;
extern char comm_filter_version;
extern char config_map;
extern char event_data_map;
extern char events;
extern char events_map_version;
extern char mnt_ns_filter_version;
extern char pid_filter_version;
extern char pid_ns_filter_version;
extern char proc_info_map;
extern char process_tree_map_version;
extern char stack_addresses;
extern char task_info_map;
extern char uid_filter_version;
extern char uts_ns_filter_version;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 21ULL: goto x86_l_15;
	case 28ULL: goto x86_l_1c;
	case 33ULL: goto x86_l_21;
	case 38ULL: goto x86_l_26;
	case 40ULL: goto x86_l_28;
	case 43ULL: goto x86_l_2b;
	case 49ULL: goto x86_l_31;
	case 52ULL: goto x86_l_34;
	case 59ULL: goto x86_l_3b;
	case 64ULL: goto x86_l_40;
	case 69ULL: goto x86_l_45;
	case 71ULL: goto x86_l_47;
	case 74ULL: goto x86_l_4a;
	case 80ULL: goto x86_l_50;
	case 83ULL: goto x86_l_53;
	case 87ULL: goto x86_l_57;
	case 94ULL: goto x86_l_5e;
	case 99ULL: goto x86_l_63;
	case 102ULL: goto x86_l_66;
	case 104ULL: goto x86_l_68;
	case 107ULL: goto x86_l_6b;
	case 113ULL: goto x86_l_71;
	case 116ULL: goto x86_l_74;
	case 120ULL: goto x86_l_78;
	case 127ULL: goto x86_l_7f;
	case 132ULL: goto x86_l_84;
	case 135ULL: goto x86_l_87;
	case 137ULL: goto x86_l_89;
	case 140ULL: goto x86_l_8c;
	case 146ULL: goto x86_l_92;
	case 154ULL: goto x86_l_9a;
	case 160ULL: goto x86_l_a0;
	case 165ULL: goto x86_l_a5;
	case 172ULL: goto x86_l_ac;
	case 176ULL: goto x86_l_b0;
	case 183ULL: goto x86_l_b7;
	case 192ULL: goto x86_l_c0;
	case 199ULL: goto x86_l_c7;
	case 210ULL: goto x86_l_d2;
	case 221ULL: goto x86_l_dd;
	case 232ULL: goto x86_l_e8;
	case 243ULL: goto x86_l_f3;
	case 254ULL: goto x86_l_fe;
	case 265ULL: goto x86_l_109;
	case 276ULL: goto x86_l_114;
	case 287ULL: goto x86_l_11f;
	case 298ULL: goto x86_l_12a;
	case 302ULL: goto x86_l_12e;
	case 310ULL: goto x86_l_136;
	case 315ULL: goto x86_l_13b;
	case 322ULL: goto x86_l_142;
	case 327ULL: goto x86_l_147;
	case 332ULL: goto x86_l_14c;
	case 334ULL: goto x86_l_14e;
	case 337ULL: goto x86_l_151;
	case 343ULL: goto x86_l_157;
	case 346ULL: goto x86_l_15a;
	case 351ULL: goto x86_l_15f;
	case 356ULL: goto x86_l_164;
	case 358ULL: goto x86_l_166;
	case 361ULL: goto x86_l_169;
	case 367ULL: goto x86_l_16f;
	case 371ULL: goto x86_l_173;
	case 378ULL: goto x86_l_17a;
	case 381ULL: goto x86_l_17d;
	case 388ULL: goto x86_l_184;
	case 395ULL: goto x86_l_18b;
	case 399ULL: goto x86_l_18f;
	case 406ULL: goto x86_l_196;
	case 410ULL: goto x86_l_19a;
	case 417ULL: goto x86_l_1a1;
	case 421ULL: goto x86_l_1a5;
	case 428ULL: goto x86_l_1ac;
	case 432ULL: goto x86_l_1b0;
	case 439ULL: goto x86_l_1b7;
	case 443ULL: goto x86_l_1bb;
	case 447ULL: goto x86_l_1bf;
	case 454ULL: goto x86_l_1c6;
	case 461ULL: goto x86_l_1cd;
	case 465ULL: goto x86_l_1d1;
	case 468ULL: goto x86_l_1d4;
	case 473ULL: goto x86_l_1d9;
	case 478ULL: goto x86_l_1de;
	case 483ULL: goto x86_l_1e3;
	case 491ULL: goto x86_l_1eb;
	case 493ULL: goto x86_l_1ed;
	case 496ULL: goto x86_l_1f0;
	case 498ULL: goto x86_l_1f2;
	case 501ULL: goto x86_l_1f5;
	case 508ULL: goto x86_l_1fc;
	case 514ULL: goto x86_l_202;
	case 519ULL: goto x86_l_207;
	case 521ULL: goto x86_l_209;
	case 526ULL: goto x86_l_20e;
	case 531ULL: goto x86_l_213;
	case 536ULL: goto x86_l_218;
	case 543ULL: goto x86_l_21f;
	case 546ULL: goto x86_l_222;
	case 552ULL: goto x86_l_228;
	case 560ULL: goto x86_l_230;
	case 563ULL: goto x86_l_233;
	case 566ULL: goto x86_l_236;
	case 569ULL: goto x86_l_239;
	case 573ULL: goto x86_l_23d;
	case 576ULL: goto x86_l_240;
	case 579ULL: goto x86_l_243;
	case 586ULL: goto x86_l_24a;
	case 589ULL: goto x86_l_24d;
	case 596ULL: goto x86_l_254;
	case 599ULL: goto x86_l_257;
	case 601ULL: goto x86_l_259;
	case 603ULL: goto x86_l_25b;
	case 608ULL: goto x86_l_260;
	case 615ULL: goto x86_l_267;
	case 618ULL: goto x86_l_26a;
	case 621ULL: goto x86_l_26d;
	case 624ULL: goto x86_l_270;
	case 631ULL: goto x86_l_277;
	case 634ULL: goto x86_l_27a;
	case 637ULL: goto x86_l_27d;
	case 644ULL: goto x86_l_284;
	case 647ULL: goto x86_l_287;
	case 649ULL: goto x86_l_289;
	case 652ULL: goto x86_l_28c;
	case 655ULL: goto x86_l_28f;
	case 658ULL: goto x86_l_292;
	case 661ULL: goto x86_l_295;
	case 668ULL: goto x86_l_29c;
	case 671ULL: goto x86_l_29f;
	case 674ULL: goto x86_l_2a2;
	case 681ULL: goto x86_l_2a9;
	case 684ULL: goto x86_l_2ac;
	case 686ULL: goto x86_l_2ae;
	case 689ULL: goto x86_l_2b1;
	case 694ULL: goto x86_l_2b6;
	case 698ULL: goto x86_l_2ba;
	case 701ULL: goto x86_l_2bd;
	case 708ULL: goto x86_l_2c4;
	case 711ULL: goto x86_l_2c7;
	case 714ULL: goto x86_l_2ca;
	case 719ULL: goto x86_l_2cf;
	case 726ULL: goto x86_l_2d6;
	case 729ULL: goto x86_l_2d9;
	case 735ULL: goto x86_l_2df;
	case 741ULL: goto x86_l_2e5;
	case 749ULL: goto x86_l_2ed;
	case 756ULL: goto x86_l_2f4;
	case 764ULL: goto x86_l_2fc;
	case 771ULL: goto x86_l_303;
	case 776ULL: goto x86_l_308;
	case 783ULL: goto x86_l_30f;
	case 788ULL: goto x86_l_314;
	case 794ULL: goto x86_l_31a;
	case 801ULL: goto x86_l_321;
	case 806ULL: goto x86_l_326;
	case 811ULL: goto x86_l_32b;
	case 813ULL: goto x86_l_32d;
	case 816ULL: goto x86_l_330;
	case 819ULL: goto x86_l_333;
	case 824ULL: goto x86_l_338;
	case 831ULL: goto x86_l_33f;
	case 834ULL: goto x86_l_342;
	case 836ULL: goto x86_l_344;
	case 841ULL: goto x86_l_349;
	case 846ULL: goto x86_l_34e;
	case 849ULL: goto x86_l_351;
	case 851ULL: goto x86_l_353;
	case 854ULL: goto x86_l_356;
	case 856ULL: goto x86_l_358;
	case 859ULL: goto x86_l_35b;
	case 863ULL: goto x86_l_35f;
	case 866ULL: goto x86_l_362;
	case 868ULL: goto x86_l_364;
	case 870ULL: goto x86_l_366;
	case 875ULL: goto x86_l_36b;
	case 880ULL: goto x86_l_370;
	case 885ULL: goto x86_l_375;
	case 888ULL: goto x86_l_378;
	case 891ULL: goto x86_l_37b;
	case 893ULL: goto x86_l_37d;
	case 897ULL: goto x86_l_381;
	case 899ULL: goto x86_l_383;
	case 902ULL: goto x86_l_386;
	case 904ULL: goto x86_l_388;
	case 912ULL: goto x86_l_390;
	case 915ULL: goto x86_l_393;
	case 918ULL: goto x86_l_396;
	case 923ULL: goto x86_l_39b;
	case 930ULL: goto x86_l_3a2;
	case 933ULL: goto x86_l_3a5;
	case 939ULL: goto x86_l_3ab;
	case 941ULL: goto x86_l_3ad;
	case 946ULL: goto x86_l_3b2;
	case 951ULL: goto x86_l_3b7;
	case 956ULL: goto x86_l_3bc;
	case 959ULL: goto x86_l_3bf;
	case 961ULL: goto x86_l_3c1;
	case 964ULL: goto x86_l_3c4;
	case 966ULL: goto x86_l_3c6;
	case 969ULL: goto x86_l_3c9;
	case 973ULL: goto x86_l_3cd;
	case 976ULL: goto x86_l_3d0;
	case 978ULL: goto x86_l_3d2;
	case 985ULL: goto x86_l_3d9;
	case 992ULL: goto x86_l_3e0;
	case 995ULL: goto x86_l_3e3;
	case 1001ULL: goto x86_l_3e9;
	case 1006ULL: goto x86_l_3ee;
	case 1008ULL: goto x86_l_3f0;
	case 1016ULL: goto x86_l_3f8;
	case 1018ULL: goto x86_l_3fa;
	case 1020ULL: goto x86_l_3fc;
	case 1028ULL: goto x86_l_404;
	case 1033ULL: goto x86_l_409;
	case 1038ULL: goto x86_l_40e;
	case 1041ULL: goto x86_l_411;
	case 1046ULL: goto x86_l_416;
	case 1049ULL: goto x86_l_419;
	case 1051ULL: goto x86_l_41b;
	case 1055ULL: goto x86_l_41f;
	case 1057ULL: goto x86_l_421;
	case 1060ULL: goto x86_l_424;
	case 1062ULL: goto x86_l_426;
	case 1070ULL: goto x86_l_42e;
	case 1073ULL: goto x86_l_431;
	case 1076ULL: goto x86_l_434;
	case 1079ULL: goto x86_l_437;
	case 1082ULL: goto x86_l_43a;
	case 1087ULL: goto x86_l_43f;
	case 1095ULL: goto x86_l_447;
	case 1101ULL: goto x86_l_44d;
	case 1106ULL: goto x86_l_452;
	case 1108ULL: goto x86_l_454;
	case 1111ULL: goto x86_l_457;
	case 1118ULL: goto x86_l_45e;
	case 1125ULL: goto x86_l_465;
	case 1130ULL: goto x86_l_46a;
	case 1137ULL: goto x86_l_471;
	case 1144ULL: goto x86_l_478;
	case 1149ULL: goto x86_l_47d;
	case 1155ULL: goto x86_l_483;
	case 1162ULL: goto x86_l_48a;
	case 1167ULL: goto x86_l_48f;
	case 1172ULL: goto x86_l_494;
	case 1174ULL: goto x86_l_496;
	case 1177ULL: goto x86_l_499;
	case 1180ULL: goto x86_l_49c;
	case 1185ULL: goto x86_l_4a1;
	case 1192ULL: goto x86_l_4a8;
	case 1195ULL: goto x86_l_4ab;
	case 1197ULL: goto x86_l_4ad;
	case 1202ULL: goto x86_l_4b2;
	case 1207ULL: goto x86_l_4b7;
	case 1209ULL: goto x86_l_4b9;
	case 1212ULL: goto x86_l_4bc;
	case 1214ULL: goto x86_l_4be;
	case 1217ULL: goto x86_l_4c1;
	case 1221ULL: goto x86_l_4c5;
	case 1224ULL: goto x86_l_4c8;
	case 1226ULL: goto x86_l_4ca;
	case 1228ULL: goto x86_l_4cc;
	case 1231ULL: goto x86_l_4cf;
	case 1236ULL: goto x86_l_4d4;
	case 1239ULL: goto x86_l_4d7;
	case 1242ULL: goto x86_l_4da;
	case 1244ULL: goto x86_l_4dc;
	case 1249ULL: goto x86_l_4e1;
	case 1253ULL: goto x86_l_4e5;
	case 1255ULL: goto x86_l_4e7;
	case 1258ULL: goto x86_l_4ea;
	case 1260ULL: goto x86_l_4ec;
	case 1265ULL: goto x86_l_4f1;
	case 1268ULL: goto x86_l_4f4;
	case 1271ULL: goto x86_l_4f7;
	case 1274ULL: goto x86_l_4fa;
	case 1279ULL: goto x86_l_4ff;
	case 1287ULL: goto x86_l_507;
	case 1293ULL: goto x86_l_50d;
	case 1298ULL: goto x86_l_512;
	case 1305ULL: goto x86_l_519;
	case 1310ULL: goto x86_l_51e;
	case 1315ULL: goto x86_l_523;
	case 1320ULL: goto x86_l_528;
	case 1325ULL: goto x86_l_52d;
	case 1327ULL: goto x86_l_52f;
	case 1332ULL: goto x86_l_534;
	case 1336ULL: goto x86_l_538;
	case 1341ULL: goto x86_l_53d;
	case 1346ULL: goto x86_l_542;
	case 1351ULL: goto x86_l_547;
	case 1356ULL: goto x86_l_54c;
	case 1358ULL: goto x86_l_54e;
	case 1363ULL: goto x86_l_553;
	case 1368ULL: goto x86_l_558;
	case 1373ULL: goto x86_l_55d;
	case 1378ULL: goto x86_l_562;
	case 1383ULL: goto x86_l_567;
	case 1388ULL: goto x86_l_56c;
	case 1390ULL: goto x86_l_56e;
	case 1394ULL: goto x86_l_572;
	case 1397ULL: goto x86_l_575;
	case 1404ULL: goto x86_l_57c;
	case 1411ULL: goto x86_l_583;
	case 1417ULL: goto x86_l_589;
	case 1424ULL: goto x86_l_590;
	case 1429ULL: goto x86_l_595;
	case 1434ULL: goto x86_l_59a;
	case 1437ULL: goto x86_l_59d;
	case 1439ULL: goto x86_l_59f;
	case 1446ULL: goto x86_l_5a6;
	case 1449ULL: goto x86_l_5a9;
	case 1451ULL: goto x86_l_5ab;
	case 1454ULL: goto x86_l_5ae;
	case 1458ULL: goto x86_l_5b2;
	case 1463ULL: goto x86_l_5b7;
	case 1465ULL: goto x86_l_5b9;
	case 1468ULL: goto x86_l_5bc;
	case 1470ULL: goto x86_l_5be;
	case 1473ULL: goto x86_l_5c1;
	case 1477ULL: goto x86_l_5c5;
	case 1480ULL: goto x86_l_5c8;
	case 1482ULL: goto x86_l_5ca;
	case 1484ULL: goto x86_l_5cc;
	case 1487ULL: goto x86_l_5cf;
	case 1490ULL: goto x86_l_5d2;
	case 1493ULL: goto x86_l_5d5;
	case 1496ULL: goto x86_l_5d8;
	case 1502ULL: goto x86_l_5de;
	case 1510ULL: goto x86_l_5e6;
	case 1516ULL: goto x86_l_5ec;
	case 1523ULL: goto x86_l_5f3;
	case 1527ULL: goto x86_l_5f7;
	case 1532ULL: goto x86_l_5fc;
	case 1537ULL: goto x86_l_601;
	case 1542ULL: goto x86_l_606;
	case 1547ULL: goto x86_l_60b;
	case 1549ULL: goto x86_l_60d;
	case 1554ULL: goto x86_l_612;
	case 1559ULL: goto x86_l_617;
	case 1564ULL: goto x86_l_61c;
	case 1569ULL: goto x86_l_621;
	case 1574ULL: goto x86_l_626;
	case 1577ULL: goto x86_l_629;
	case 1579ULL: goto x86_l_62b;
	case 1583ULL: goto x86_l_62f;
	case 1587ULL: goto x86_l_633;
	case 1591ULL: goto x86_l_637;
	case 1595ULL: goto x86_l_63b;
	case 1600ULL: goto x86_l_640;
	case 1605ULL: goto x86_l_645;
	case 1610ULL: goto x86_l_64a;
	case 1615ULL: goto x86_l_64f;
	case 1617ULL: goto x86_l_651;
	case 1622ULL: goto x86_l_656;
	case 1626ULL: goto x86_l_65a;
	case 1631ULL: goto x86_l_65f;
	case 1636ULL: goto x86_l_664;
	case 1641ULL: goto x86_l_669;
	case 1646ULL: goto x86_l_66e;
	case 1648ULL: goto x86_l_670;
	case 1652ULL: goto x86_l_674;
	case 1655ULL: goto x86_l_677;
	case 1662ULL: goto x86_l_67e;
	case 1669ULL: goto x86_l_685;
	case 1675ULL: goto x86_l_68b;
	case 1682ULL: goto x86_l_692;
	case 1687ULL: goto x86_l_697;
	case 1692ULL: goto x86_l_69c;
	case 1695ULL: goto x86_l_69f;
	case 1697ULL: goto x86_l_6a1;
	case 1704ULL: goto x86_l_6a8;
	case 1707ULL: goto x86_l_6ab;
	case 1709ULL: goto x86_l_6ad;
	case 1712ULL: goto x86_l_6b0;
	case 1716ULL: goto x86_l_6b4;
	case 1721ULL: goto x86_l_6b9;
	case 1723ULL: goto x86_l_6bb;
	case 1726ULL: goto x86_l_6be;
	case 1728ULL: goto x86_l_6c0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 168ULL);
x86_l_a:
	/* 0xa: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_15:
	/* 0x15: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_1c:
	/* 0x1c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21:
	/* 0x21: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26:
	/* 0x26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28:
	/* 0x28: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b:
	/* 0x2b: je     207 <syscall__execveat_enter+0x207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_207;
	}
x86_l_31:
	/* 0x31: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_34:
	/* 0x34: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_3b:
	/* 0x3b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40:
	/* 0x40: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_45:
	/* 0x45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47:
	/* 0x47: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4a:
	/* 0x4a: je     207 <syscall__execveat_enter+0x207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_207;
	}
x86_l_50:
	/* 0x50: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_53:
	/* 0x53: lea    r15,[rbp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_57:
	/* 0x57: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_5e:
	/* 0x5e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_63:
	/* 0x63: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_66:
	/* 0x66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68:
	/* 0x68: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6b:
	/* 0x6b: je     207 <syscall__execveat_enter+0x207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_207;
	}
x86_l_71:
	/* 0x71: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_74:
	/* 0x74: lea    rbx,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_78:
	/* 0x78: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_7f:
	/* 0x7f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_84:
	/* 0x84: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_87:
	/* 0x87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_89:
	/* 0x89: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8c:
	/* 0x8c: je     207 <syscall__execveat_enter+0x207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_207;
	}
x86_l_92:
	/* 0x92: cmp    BYTE PTR [r13+0xb0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_9a:
	/* 0x9a: je     20e <syscall__execveat_enter+0x20e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20e;
	}
x86_l_a0:
	/* 0xa0: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a5:
	/* 0xa5: mov    rax,QWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_ac:
	/* 0xac: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b0:
	/* 0xb0: mov    DWORD PTR [rbp+0x70],0x142 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337474ULL);
x86_l_b7:
	/* 0xb7: mov    WORD PTR [rbp+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_c0:
	/* 0xc0: mov    BYTE PTR [rbp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_c7:
	/* 0xc7: mov    QWORD PTR [rbp+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_d2:
	/* 0xd2: mov    QWORD PTR [rbp+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_dd:
	/* 0xdd: mov    QWORD PTR [rbp+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_e8:
	/* 0xe8: mov    QWORD PTR [rbp+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_f3:
	/* 0xf3: mov    QWORD PTR [rbp+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_fe:
	/* 0xfe: mov    QWORD PTR [rbp+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_109:
	/* 0x109: mov    QWORD PTR [rbp+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_114:
	/* 0x114: mov    QWORD PTR [rbp+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_11f:
	/* 0x11f: mov    QWORD PTR [rbp+0x7dd8],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138370961375231ULL);
x86_l_12a:
	/* 0x12a: movzx  eax,WORD PTR [rbp+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_12e:
	/* 0x12e: mov    DWORD PTR [rsp+0x10],0x142 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719477058ULL);
x86_l_136:
	/* 0x136: mov    WORD PTR [rsp+0x4],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13b:
	/* 0x13b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_142:
	/* 0x142: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_147:
	/* 0x147: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14c:
	/* 0x14c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14e:
	/* 0x14e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_151:
	/* 0x151: je     207 <syscall__execveat_enter+0x207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_207;
	}
x86_l_157:
	/* 0x157: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_15a:
	/* 0x15a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15f:
	/* 0x15f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_164:
	/* 0x164: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_166:
	/* 0x166: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_169:
	/* 0x169: je     207 <syscall__execveat_enter+0x207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_207;
	}
x86_l_16f:
	/* 0x16f: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_173:
	/* 0x173: mov    QWORD PTR [rbp+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_17a:
	/* 0x17a: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17d:
	/* 0x17d: mov    QWORD PTR [rbp+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_184:
	/* 0x184: mov    QWORD PTR [rbp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_18b:
	/* 0x18b: mov    rdx,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18f:
	/* 0x18f: mov    QWORD PTR [rbp+0x7e10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_196:
	/* 0x196: mov    rdx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19a:
	/* 0x19a: mov    QWORD PTR [rbp+0x7e08],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_1a1:
	/* 0x1a1: mov    rdx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a5:
	/* 0x1a5: mov    QWORD PTR [rbp+0x7e00],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_1ac:
	/* 0x1ac: mov    rdx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b0:
	/* 0x1b0: mov    QWORD PTR [rbp+0x7df8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_1b7:
	/* 0x1b7: mov    rdx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bb:
	/* 0x1bb: mov    rax,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bf:
	/* 0x1bf: mov    QWORD PTR [rbp+0x7df0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_1c6:
	/* 0x1c6: mov    QWORD PTR [rbp+0x7de8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_1cd:
	/* 0x1cd: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d1:
	/* 0x1d1: cmp    eax,DWORD PTR [rbp+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1d4:
	/* 0x1d4: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d9:
	/* 0x1d9: mov    QWORD PTR [rsp+0x70],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1de:
	/* 0x1de: mov    QWORD PTR [rsp+0x58],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1e3:
	/* 0x1e3: mov    QWORD PTR [rsp+0xa0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1eb:
	/* 0x1eb: jne    218 <syscall__execveat_enter+0x218> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_218;
	}
x86_l_1ed:
	/* 0x1ed: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f0:
	/* 0x1f0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f2:
	/* 0x1f2: and    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1f5:
	/* 0x1f5: mov    QWORD PTR [rbp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1fc:
	/* 0x1fc: jne    a10 <syscall__execveat_enter+0xa10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2576ULL;
	}
x86_l_202:
	/* 0x202: jmp    124a <syscall__execveat_enter+0x124a> */
	return 4682ULL;
x86_l_207:
	/* 0x207: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_209:
	/* 0x209: jmp    124a <syscall__execveat_enter+0x124a> */
	return 4682ULL;
x86_l_20e:
	/* 0x20e: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_213:
	/* 0x213: jmp    124a <syscall__execveat_enter+0x124a> */
	return 4682ULL;
x86_l_218:
	/* 0x218: mov    rax,QWORD PTR [rbp+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_21f:
	/* 0x21f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_222:
	/* 0x222: je     3d2 <syscall__execveat_enter+0x3d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d2;
	}
x86_l_228:
	/* 0x228: movzx  ecx,BYTE PTR [r13+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_230:
	/* 0x230: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_233:
	/* 0x233: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_236:
	/* 0x236: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_239:
	/* 0x239: sete   r13b */
	X86_SIM_L_EXEC_SETCC(X86_R13, X86_CC_E);
x86_l_23d:
	/* 0x23d: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_240:
	/* 0x240: neg    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_243:
	/* 0x243: xor    r13,QWORD PTR [rbp+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_24a:
	/* 0x24a: or     r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_24d:
	/* 0x24d: mov    rax,QWORD PTR [rbp+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_254:
	/* 0x254: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_257:
	/* 0x257: je     27d <syscall__execveat_enter+0x27d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d;
	}
x86_l_259:
	/* 0x259: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25b:
	/* 0x25b: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_260:
	/* 0x260: cmp    BYTE PTR [rdx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_267:
	/* 0x267: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_26a:
	/* 0x26a: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_26d:
	/* 0x26d: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_270:
	/* 0x270: xor    rcx,QWORD PTR [rbp+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_277:
	/* 0x277: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_27a:
	/* 0x27a: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_27d:
	/* 0x27d: mov    rax,QWORD PTR [rbp+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_284:
	/* 0x284: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_287:
	/* 0x287: je     2a2 <syscall__execveat_enter+0x2a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a2;
	}
x86_l_289:
	/* 0x289: mov    ecx,DWORD PTR [rbp+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_28c:
	/* 0x28c: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_28f:
	/* 0x28f: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_292:
	/* 0x292: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_295:
	/* 0x295: xor    rcx,QWORD PTR [rbp+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_29c:
	/* 0x29c: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_29f:
	/* 0x29f: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_2a2:
	/* 0x2a2: mov    rax,QWORD PTR [rbp+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_2a9:
	/* 0x2a9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ac:
	/* 0x2ac: je     2ca <syscall__execveat_enter+0x2ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ca;
	}
x86_l_2ae:
	/* 0x2ae: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2b1:
	/* 0x2b1: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2b6:
	/* 0x2b6: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2ba:
	/* 0x2ba: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_2bd:
	/* 0x2bd: xor    rcx,QWORD PTR [rbp+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_2c4:
	/* 0x2c4: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2c7:
	/* 0x2c7: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_2ca:
	/* 0x2ca: movzx  r14d,WORD PTR [rbp+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_2cf:
	/* 0x2cf: mov    rax,QWORD PTR [rbp+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_2d6:
	/* 0x2d6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d9:
	/* 0x2d9: mov    WORD PTR [rsp+0x56],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_2df:
	/* 0x2df: je     43f <syscall__execveat_enter+0x43f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43f;
	}
x86_l_2e5:
	/* 0x2e5: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2ed:
	/* 0x2ed: mov    rax,QWORD PTR [rbp+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_2f4:
	/* 0x2f4: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2fc:
	/* 0x2fc: mov    rax,QWORD PTR [rbp+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_303:
	/* 0x303: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_308:
	/* 0x308: mov    rax,QWORD PTR [rbp+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_30f:
	/* 0x30f: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_314:
	/* 0x314: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31a:
	/* 0x31a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_321:
	/* 0x321: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_326:
	/* 0x326: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32b:
	/* 0x32b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32d:
	/* 0x32d: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_330:
	/* 0x330: mov    eax,DWORD PTR [rbp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_333:
	/* 0x333: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_338:
	/* 0x338: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_33f:
	/* 0x33f: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_342:
	/* 0x342: je     364 <syscall__execveat_enter+0x364> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_364;
	}
x86_l_344:
	/* 0x344: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_349:
	/* 0x349: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34e:
	/* 0x34e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_351:
	/* 0x351: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_353:
	/* 0x353: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_356:
	/* 0x356: je     364 <syscall__execveat_enter+0x364> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_364;
	}
x86_l_358:
	/* 0x358: mov    rbp,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35b:
	/* 0x35b: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35f:
	/* 0x35f: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_362:
	/* 0x362: jmp    366 <syscall__execveat_enter+0x366> */
	goto x86_l_366;
x86_l_364:
	/* 0x364: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_366:
	/* 0x366: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_36b:
	/* 0x36b: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_370:
	/* 0x370: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_375:
	/* 0x375: dec    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_378:
	/* 0x378: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_37b:
	/* 0x37b: jb     393 <syscall__execveat_enter+0x393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_393;
	}
x86_l_37d:
	/* 0x37d: cmp    rsi,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_381:
	/* 0x381: je     388 <syscall__execveat_enter+0x388> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_388;
	}
x86_l_383:
	/* 0x383: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_386:
	/* 0x386: jbe    393 <syscall__execveat_enter+0x393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_393;
	}
x86_l_388:
	/* 0x388: and    r14,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 152ULL);
x86_l_390:
	/* 0x390: or     rbp,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_393:
	/* 0x393: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_396:
	/* 0x396: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39b:
	/* 0x39b: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_3a2:
	/* 0x3a2: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_3a5:
	/* 0x3a5: movzx  r14d,WORD PTR [rsp+0x56] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 86ULL);
x86_l_3ab:
	/* 0x3ab: je     3ee <syscall__execveat_enter+0x3ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ee;
	}
x86_l_3ad:
	/* 0x3ad: mov    QWORD PTR [rsp+0x60],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3b2:
	/* 0x3b2: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b7:
	/* 0x3b7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3bc:
	/* 0x3bc: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3bf:
	/* 0x3bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c1:
	/* 0x3c1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3c4:
	/* 0x3c4: je     3fa <syscall__execveat_enter+0x3fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fa;
	}
x86_l_3c6:
	/* 0x3c6: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c9:
	/* 0x3c9: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3cd:
	/* 0x3cd: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_3d0:
	/* 0x3d0: jmp    3fc <syscall__execveat_enter+0x3fc> */
	goto x86_l_3fc;
x86_l_3d2:
	/* 0x3d2: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_3d9:
	/* 0x3d9: mov    rax,QWORD PTR [rbp+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_3e0:
	/* 0x3e0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e3:
	/* 0x3e3: jne    259 <syscall__execveat_enter+0x259> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_259;
	}
x86_l_3e9:
	/* 0x3e9: jmp    27d <syscall__execveat_enter+0x27d> */
	goto x86_l_27d;
x86_l_3ee:
	/* 0x3ee: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f0:
	/* 0x3f0: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3f8:
	/* 0x3f8: jmp    40e <syscall__execveat_enter+0x40e> */
	goto x86_l_40e;
x86_l_3fa:
	/* 0x3fa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3fc:
	/* 0x3fc: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_404:
	/* 0x404: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_409:
	/* 0x409: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_40e:
	/* 0x40e: not    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_411:
	/* 0x411: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_416:
	/* 0x416: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_419:
	/* 0x419: jb     431 <syscall__execveat_enter+0x431> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_431;
	}
x86_l_41b:
	/* 0x41b: cmp    rsi,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_41f:
	/* 0x41f: je     426 <syscall__execveat_enter+0x426> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_426;
	}
x86_l_421:
	/* 0x421: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_424:
	/* 0x424: jbe    431 <syscall__execveat_enter+0x431> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_431;
	}
x86_l_426:
	/* 0x426: and    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 152ULL);
x86_l_42e:
	/* 0x42e: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_431:
	/* 0x431: or     rbp,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_434:
	/* 0x434: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_437:
	/* 0x437: and    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_43a:
	/* 0x43a: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43f:
	/* 0x43f: cmp    QWORD PTR [rbp+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_447:
	/* 0x447: je     4ff <syscall__execveat_enter+0x4ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ff;
	}
x86_l_44d:
	/* 0x44d: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_452:
	/* 0x452: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_454:
	/* 0x454: mov    DWORD PTR [rbp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_457:
	/* 0x457: mov    r15,QWORD PTR [rbp+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_45e:
	/* 0x45e: mov    rax,QWORD PTR [rbp+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_465:
	/* 0x465: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_46a:
	/* 0x46a: mov    r12,QWORD PTR [rbp+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_471:
	/* 0x471: mov    rax,QWORD PTR [rbp+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_478:
	/* 0x478: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_47d:
	/* 0x47d: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_483:
	/* 0x483: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_48a:
	/* 0x48a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48f:
	/* 0x48f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_494:
	/* 0x494: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_496:
	/* 0x496: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_499:
	/* 0x499: mov    eax,DWORD PTR [rbp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_49c:
	/* 0x49c: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a1:
	/* 0x4a1: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_4a8:
	/* 0x4a8: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_4ab:
	/* 0x4ab: je     4ca <syscall__execveat_enter+0x4ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ca;
	}
x86_l_4ad:
	/* 0x4ad: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b2:
	/* 0x4b2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4b7:
	/* 0x4b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b9:
	/* 0x4b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4bc:
	/* 0x4bc: je     4ca <syscall__execveat_enter+0x4ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ca;
	}
x86_l_4be:
	/* 0x4be: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c1:
	/* 0x4c1: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c5:
	/* 0x4c5: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_4c8:
	/* 0x4c8: jmp    4cc <syscall__execveat_enter+0x4cc> */
	goto x86_l_4cc;
x86_l_4ca:
	/* 0x4ca: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4cc:
	/* 0x4cc: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_4cf:
	/* 0x4cf: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d4:
	/* 0x4d4: dec    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_4d7:
	/* 0x4d7: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_4da:
	/* 0x4da: jb     4f4 <syscall__execveat_enter+0x4f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4f4;
	}
x86_l_4dc:
	/* 0x4dc: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4e1:
	/* 0x4e1: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_4e5:
	/* 0x4e5: je     4ec <syscall__execveat_enter+0x4ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ec;
	}
x86_l_4e7:
	/* 0x4e7: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_4ea:
	/* 0x4ea: jbe    4f4 <syscall__execveat_enter+0x4f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_4f4;
	}
x86_l_4ec:
	/* 0x4ec: and    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 104ULL);
x86_l_4f1:
	/* 0x4f1: or     rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_4f4:
	/* 0x4f4: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_4f7:
	/* 0x4f7: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_4fa:
	/* 0x4fa: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ff:
	/* 0x4ff: cmp    QWORD PTR [rbp+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_507:
	/* 0x507: je     5de <syscall__execveat_enter+0x5de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5de;
	}
x86_l_50d:
	/* 0x50d: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_512:
	/* 0x512: add    rdx,QWORD PTR [rbp+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_519:
	/* 0x519: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51e:
	/* 0x51e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_523:
	/* 0x523: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_528:
	/* 0x528: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52d:
	/* 0x52d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52f:
	/* 0x52f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_534:
	/* 0x534: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_538:
	/* 0x538: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53d:
	/* 0x53d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_542:
	/* 0x542: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_547:
	/* 0x547: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54c:
	/* 0x54c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54e:
	/* 0x54e: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_553:
	/* 0x553: lea    rdi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_558:
	/* 0x558: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_55d:
	/* 0x55d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_562:
	/* 0x562: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_567:
	/* 0x567: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_56c:
	/* 0x56c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56e:
	/* 0x56e: mov    eax,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_572:
	/* 0x572: mov    DWORD PTR [rbp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_575:
	/* 0x575: mov    r15,QWORD PTR [rbp+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_57c:
	/* 0x57c: mov    r12,QWORD PTR [rbp+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_583:
	/* 0x583: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_589:
	/* 0x589: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_590:
	/* 0x590: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_595:
	/* 0x595: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_59a:
	/* 0x59a: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_59d:
	/* 0x59d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59f:
	/* 0x59f: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_5a6:
	/* 0x5a6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5a9:
	/* 0x5a9: je     5ca <syscall__execveat_enter+0x5ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ca;
	}
x86_l_5ab:
	/* 0x5ab: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_5ae:
	/* 0x5ae: lea    rsi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_5b2:
	/* 0x5b2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5b7:
	/* 0x5b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b9:
	/* 0x5b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5bc:
	/* 0x5bc: je     5ca <syscall__execveat_enter+0x5ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ca;
	}
x86_l_5be:
	/* 0x5be: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c1:
	/* 0x5c1: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c5:
	/* 0x5c5: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_5c8:
	/* 0x5c8: jmp    5cc <syscall__execveat_enter+0x5cc> */
	goto x86_l_5cc;
x86_l_5ca:
	/* 0x5ca: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5cc:
	/* 0x5cc: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_5cf:
	/* 0x5cf: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_5d2:
	/* 0x5d2: or     r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_5d5:
	/* 0x5d5: and    r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_5d8:
	/* 0x5d8: movzx  r14d,WORD PTR [rsp+0x56] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 86ULL);
x86_l_5de:
	/* 0x5de: cmp    QWORD PTR [rbp+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_5e6:
	/* 0x5e6: je     6e0 <syscall__execveat_enter+0x6e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1760ULL;
	}
x86_l_5ec:
	/* 0x5ec: mov    rdx,QWORD PTR [rbp+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_5f3:
	/* 0x5f3: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5f7:
	/* 0x5f7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5fc:
	/* 0x5fc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_601:
	/* 0x601: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_606:
	/* 0x606: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_60b:
	/* 0x60b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60d:
	/* 0x60d: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_612:
	/* 0x612: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_617:
	/* 0x617: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_61c:
	/* 0x61c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_621:
	/* 0x621: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_626:
	/* 0x626: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_629:
	/* 0x629: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62b:
	/* 0x62b: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_62f:
	/* 0x62f: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_633:
	/* 0x633: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_637:
	/* 0x637: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_63b:
	/* 0x63b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_640:
	/* 0x640: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_645:
	/* 0x645: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_64a:
	/* 0x64a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64f:
	/* 0x64f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_651:
	/* 0x651: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_656:
	/* 0x656: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_65a:
	/* 0x65a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_65f:
	/* 0x65f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_664:
	/* 0x664: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_669:
	/* 0x669: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_66e:
	/* 0x66e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_670:
	/* 0x670: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_674:
	/* 0x674: mov    DWORD PTR [rbp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_677:
	/* 0x677: mov    r15,QWORD PTR [rbp+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_67e:
	/* 0x67e: mov    r12,QWORD PTR [rbp+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_685:
	/* 0x685: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_68b:
	/* 0x68b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_692:
	/* 0x692: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_697:
	/* 0x697: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_69c:
	/* 0x69c: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_69f:
	/* 0x69f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a1:
	/* 0x6a1: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_6a8:
	/* 0x6a8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6ab:
	/* 0x6ab: je     6cc <syscall__execveat_enter+0x6cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1740ULL;
	}
x86_l_6ad:
	/* 0x6ad: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_6b0:
	/* 0x6b0: lea    rsi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6b4:
	/* 0x6b4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6b9:
	/* 0x6b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6bb:
	/* 0x6bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6be:
	/* 0x6be: je     6cc <syscall__execveat_enter+0x6cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1740ULL;
	}
x86_l_6c0:
	/* 0x6c0: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 1731ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1731ULL: goto x86_l_6c3;
	case 1735ULL: goto x86_l_6c7;
	case 1738ULL: goto x86_l_6ca;
	case 1740ULL: goto x86_l_6cc;
	case 1742ULL: goto x86_l_6ce;
	case 1745ULL: goto x86_l_6d1;
	case 1748ULL: goto x86_l_6d4;
	case 1751ULL: goto x86_l_6d7;
	case 1754ULL: goto x86_l_6da;
	case 1760ULL: goto x86_l_6e0;
	case 1768ULL: goto x86_l_6e8;
	case 1774ULL: goto x86_l_6ee;
	case 1779ULL: goto x86_l_6f3;
	case 1786ULL: goto x86_l_6fa;
	case 1791ULL: goto x86_l_6ff;
	case 1796ULL: goto x86_l_704;
	case 1801ULL: goto x86_l_709;
	case 1806ULL: goto x86_l_70e;
	case 1808ULL: goto x86_l_710;
	case 1813ULL: goto x86_l_715;
	case 1818ULL: goto x86_l_71a;
	case 1823ULL: goto x86_l_71f;
	case 1828ULL: goto x86_l_724;
	case 1833ULL: goto x86_l_729;
	case 1835ULL: goto x86_l_72b;
	case 1840ULL: goto x86_l_730;
	case 1845ULL: goto x86_l_735;
	case 1850ULL: goto x86_l_73a;
	case 1855ULL: goto x86_l_73f;
	case 1858ULL: goto x86_l_742;
	case 1863ULL: goto x86_l_747;
	case 1865ULL: goto x86_l_749;
	case 1869ULL: goto x86_l_74d;
	case 1874ULL: goto x86_l_752;
	case 1879ULL: goto x86_l_757;
	case 1882ULL: goto x86_l_75a;
	case 1887ULL: goto x86_l_75f;
	case 1890ULL: goto x86_l_762;
	case 1892ULL: goto x86_l_764;
	case 1899ULL: goto x86_l_76b;
	case 1906ULL: goto x86_l_772;
	case 1912ULL: goto x86_l_778;
	case 1919ULL: goto x86_l_77f;
	case 1924ULL: goto x86_l_784;
	case 1929ULL: goto x86_l_789;
	case 1932ULL: goto x86_l_78c;
	case 1934ULL: goto x86_l_78e;
	case 1941ULL: goto x86_l_795;
	case 1944ULL: goto x86_l_798;
	case 1946ULL: goto x86_l_79a;
	case 1949ULL: goto x86_l_79d;
	case 1954ULL: goto x86_l_7a2;
	case 1957ULL: goto x86_l_7a5;
	case 1959ULL: goto x86_l_7a7;
	case 1962ULL: goto x86_l_7aa;
	case 1964ULL: goto x86_l_7ac;
	case 1967ULL: goto x86_l_7af;
	case 1971ULL: goto x86_l_7b3;
	case 1974ULL: goto x86_l_7b6;
	case 1976ULL: goto x86_l_7b8;
	case 1978ULL: goto x86_l_7ba;
	case 1981ULL: goto x86_l_7bd;
	case 1984ULL: goto x86_l_7c0;
	case 1987ULL: goto x86_l_7c3;
	case 1990ULL: goto x86_l_7c6;
	case 1995ULL: goto x86_l_7cb;
	case 2001ULL: goto x86_l_7d1;
	case 2009ULL: goto x86_l_7d9;
	case 2015ULL: goto x86_l_7df;
	case 2019ULL: goto x86_l_7e3;
	case 2024ULL: goto x86_l_7e8;
	case 2029ULL: goto x86_l_7ed;
	case 2032ULL: goto x86_l_7f0;
	case 2037ULL: goto x86_l_7f5;
	case 2039ULL: goto x86_l_7f7;
	case 2046ULL: goto x86_l_7fe;
	case 2053ULL: goto x86_l_805;
	case 2059ULL: goto x86_l_80b;
	case 2066ULL: goto x86_l_812;
	case 2071ULL: goto x86_l_817;
	case 2076ULL: goto x86_l_81c;
	case 2079ULL: goto x86_l_81f;
	case 2081ULL: goto x86_l_821;
	case 2088ULL: goto x86_l_828;
	case 2091ULL: goto x86_l_82b;
	case 2093ULL: goto x86_l_82d;
	case 2096ULL: goto x86_l_830;
	case 2101ULL: goto x86_l_835;
	case 2104ULL: goto x86_l_838;
	case 2106ULL: goto x86_l_83a;
	case 2109ULL: goto x86_l_83d;
	case 2111ULL: goto x86_l_83f;
	case 2114ULL: goto x86_l_842;
	case 2118ULL: goto x86_l_846;
	case 2121ULL: goto x86_l_849;
	case 2123ULL: goto x86_l_84b;
	case 2125ULL: goto x86_l_84d;
	case 2128ULL: goto x86_l_850;
	case 2131ULL: goto x86_l_853;
	case 2134ULL: goto x86_l_856;
	case 2137ULL: goto x86_l_859;
	case 2142ULL: goto x86_l_85e;
	case 2148ULL: goto x86_l_864;
	case 2155ULL: goto x86_l_86b;
	case 2158ULL: goto x86_l_86e;
	case 2160ULL: goto x86_l_870;
	case 2163ULL: goto x86_l_873;
	case 2167ULL: goto x86_l_877;
	case 2174ULL: goto x86_l_87e;
	case 2180ULL: goto x86_l_884;
	case 2187ULL: goto x86_l_88b;
	case 2192ULL: goto x86_l_890;
	case 2197ULL: goto x86_l_895;
	case 2200ULL: goto x86_l_898;
	case 2202ULL: goto x86_l_89a;
	case 2209ULL: goto x86_l_8a1;
	case 2212ULL: goto x86_l_8a4;
	case 2214ULL: goto x86_l_8a6;
	case 2217ULL: goto x86_l_8a9;
	case 2222ULL: goto x86_l_8ae;
	case 2227ULL: goto x86_l_8b3;
	case 2229ULL: goto x86_l_8b5;
	case 2232ULL: goto x86_l_8b8;
	case 2234ULL: goto x86_l_8ba;
	case 2237ULL: goto x86_l_8bd;
	case 2241ULL: goto x86_l_8c1;
	case 2244ULL: goto x86_l_8c4;
	case 2246ULL: goto x86_l_8c6;
	case 2248ULL: goto x86_l_8c8;
	case 2251ULL: goto x86_l_8cb;
	case 2254ULL: goto x86_l_8ce;
	case 2257ULL: goto x86_l_8d1;
	case 2260ULL: goto x86_l_8d4;
	case 2266ULL: goto x86_l_8da;
	case 2273ULL: goto x86_l_8e1;
	case 2276ULL: goto x86_l_8e4;
	case 2278ULL: goto x86_l_8e6;
	case 2285ULL: goto x86_l_8ed;
	case 2291ULL: goto x86_l_8f3;
	case 2298ULL: goto x86_l_8fa;
	case 2303ULL: goto x86_l_8ff;
	case 2308ULL: goto x86_l_904;
	case 2311ULL: goto x86_l_907;
	case 2313ULL: goto x86_l_909;
	case 2320ULL: goto x86_l_910;
	case 2323ULL: goto x86_l_913;
	case 2325ULL: goto x86_l_915;
	case 2328ULL: goto x86_l_918;
	case 2333ULL: goto x86_l_91d;
	case 2336ULL: goto x86_l_920;
	case 2338ULL: goto x86_l_922;
	case 2341ULL: goto x86_l_925;
	case 2343ULL: goto x86_l_927;
	case 2346ULL: goto x86_l_92a;
	case 2350ULL: goto x86_l_92e;
	case 2353ULL: goto x86_l_931;
	case 2355ULL: goto x86_l_933;
	case 2357ULL: goto x86_l_935;
	case 2360ULL: goto x86_l_938;
	case 2363ULL: goto x86_l_93b;
	case 2366ULL: goto x86_l_93e;
	case 2369ULL: goto x86_l_941;
	case 2375ULL: goto x86_l_947;
	case 2382ULL: goto x86_l_94e;
	case 2385ULL: goto x86_l_951;
	case 2391ULL: goto x86_l_957;
	case 2398ULL: goto x86_l_95e;
	case 2404ULL: goto x86_l_964;
	case 2411ULL: goto x86_l_96b;
	case 2416ULL: goto x86_l_970;
	case 2421ULL: goto x86_l_975;
	case 2424ULL: goto x86_l_978;
	case 2426ULL: goto x86_l_97a;
	case 2433ULL: goto x86_l_981;
	case 2436ULL: goto x86_l_984;
	case 2438ULL: goto x86_l_986;
	case 2441ULL: goto x86_l_989;
	case 2446ULL: goto x86_l_98e;
	case 2450ULL: goto x86_l_992;
	case 2455ULL: goto x86_l_997;
	case 2458ULL: goto x86_l_99a;
	case 2460ULL: goto x86_l_99c;
	case 2463ULL: goto x86_l_99f;
	case 2465ULL: goto x86_l_9a1;
	case 2470ULL: goto x86_l_9a6;
	case 2474ULL: goto x86_l_9aa;
	case 2479ULL: goto x86_l_9af;
	case 2482ULL: goto x86_l_9b2;
	case 2484ULL: goto x86_l_9b4;
	case 2487ULL: goto x86_l_9b7;
	case 2489ULL: goto x86_l_9b9;
	case 2492ULL: goto x86_l_9bc;
	case 2496ULL: goto x86_l_9c0;
	case 2499ULL: goto x86_l_9c3;
	case 2501ULL: goto x86_l_9c5;
	case 2503ULL: goto x86_l_9c7;
	case 2506ULL: goto x86_l_9ca;
	case 2509ULL: goto x86_l_9cd;
	case 2512ULL: goto x86_l_9d0;
	case 2515ULL: goto x86_l_9d3;
	case 2520ULL: goto x86_l_9d8;
	case 2527ULL: goto x86_l_9df;
	case 2530ULL: goto x86_l_9e2;
	case 2532ULL: goto x86_l_9e4;
	case 2537ULL: goto x86_l_9e9;
	case 2541ULL: goto x86_l_9ed;
	case 2544ULL: goto x86_l_9f0;
	case 2546ULL: goto x86_l_9f2;
	case 2553ULL: goto x86_l_9f9;
	case 2560ULL: goto x86_l_a00;
	case 2563ULL: goto x86_l_a03;
	case 2570ULL: goto x86_l_a0a;
	case 2576ULL: goto x86_l_a10;
	case 2583ULL: goto x86_l_a17;
	case 2587ULL: goto x86_l_a1b;
	case 2594ULL: goto x86_l_a22;
	case 2596ULL: goto x86_l_a24;
	case 2601ULL: goto x86_l_a29;
	case 2606ULL: goto x86_l_a2e;
	case 2611ULL: goto x86_l_a33;
	case 2620ULL: goto x86_l_a3c;
	case 2627ULL: goto x86_l_a43;
	case 2632ULL: goto x86_l_a48;
	case 2637ULL: goto x86_l_a4d;
	case 2639ULL: goto x86_l_a4f;
	case 2643ULL: goto x86_l_a53;
	case 2647ULL: goto x86_l_a57;
	case 2654ULL: goto x86_l_a5e;
	case 2659ULL: goto x86_l_a63;
	case 2664ULL: goto x86_l_a68;
	case 2669ULL: goto x86_l_a6d;
	case 2671ULL: goto x86_l_a6f;
	case 2674ULL: goto x86_l_a72;
	case 2676ULL: goto x86_l_a74;
	case 2680ULL: goto x86_l_a78;
	case 2688ULL: goto x86_l_a80;
	case 2694ULL: goto x86_l_a86;
	case 2696ULL: goto x86_l_a88;
	case 2700ULL: goto x86_l_a8c;
	case 2704ULL: goto x86_l_a90;
	case 2709ULL: goto x86_l_a95;
	case 2715ULL: goto x86_l_a9b;
	case 2719ULL: goto x86_l_a9f;
	case 2727ULL: goto x86_l_aa7;
	case 2734ULL: goto x86_l_aae;
	case 2741ULL: goto x86_l_ab5;
	case 2748ULL: goto x86_l_abc;
	case 2750ULL: goto x86_l_abe;
	case 2753ULL: goto x86_l_ac1;
	case 2760ULL: goto x86_l_ac8;
	case 2765ULL: goto x86_l_acd;
	case 2770ULL: goto x86_l_ad2;
	case 2777ULL: goto x86_l_ad9;
	case 2781ULL: goto x86_l_add;
	case 2788ULL: goto x86_l_ae4;
	case 2793ULL: goto x86_l_ae9;
	case 2795ULL: goto x86_l_aeb;
	case 2797ULL: goto x86_l_aed;
	case 2799ULL: goto x86_l_aef;
	case 2802ULL: goto x86_l_af2;
	case 2809ULL: goto x86_l_af9;
	case 2811ULL: goto x86_l_afb;
	case 2818ULL: goto x86_l_b02;
	case 2825ULL: goto x86_l_b09;
	case 2828ULL: goto x86_l_b0c;
	case 2835ULL: goto x86_l_b13;
	case 2841ULL: goto x86_l_b19;
	case 2843ULL: goto x86_l_b1b;
	case 2845ULL: goto x86_l_b1d;
	case 2848ULL: goto x86_l_b20;
	case 2851ULL: goto x86_l_b23;
	case 2856ULL: goto x86_l_b28;
	case 2862ULL: goto x86_l_b2e;
	case 2869ULL: goto x86_l_b35;
	case 2877ULL: goto x86_l_b3d;
	case 2885ULL: goto x86_l_b45;
	case 2889ULL: goto x86_l_b49;
	case 2896ULL: goto x86_l_b50;
	case 2905ULL: goto x86_l_b59;
	case 2910ULL: goto x86_l_b5e;
	case 2915ULL: goto x86_l_b63;
	case 2920ULL: goto x86_l_b68;
	case 2925ULL: goto x86_l_b6d;
	case 2928ULL: goto x86_l_b70;
	case 2930ULL: goto x86_l_b72;
	case 2935ULL: goto x86_l_b77;
	case 2938ULL: goto x86_l_b7a;
	case 2940ULL: goto x86_l_b7c;
	case 2943ULL: goto x86_l_b7f;
	case 2949ULL: goto x86_l_b85;
	case 2951ULL: goto x86_l_b87;
	case 2955ULL: goto x86_l_b8b;
	case 2962ULL: goto x86_l_b92;
	case 2967ULL: goto x86_l_b97;
	case 2972ULL: goto x86_l_b9c;
	case 2979ULL: goto x86_l_ba3;
	case 2983ULL: goto x86_l_ba7;
	case 2990ULL: goto x86_l_bae;
	case 2995ULL: goto x86_l_bb3;
	case 3000ULL: goto x86_l_bb8;
	case 3002ULL: goto x86_l_bba;
	case 3006ULL: goto x86_l_bbe;
	case 3008ULL: goto x86_l_bc0;
	case 3010ULL: goto x86_l_bc2;
	case 3013ULL: goto x86_l_bc5;
	case 3019ULL: goto x86_l_bcb;
	case 3025ULL: goto x86_l_bd1;
	case 3027ULL: goto x86_l_bd3;
	case 3032ULL: goto x86_l_bd8;
	case 3037ULL: goto x86_l_bdd;
	case 3044ULL: goto x86_l_be4;
	case 3049ULL: goto x86_l_be9;
	case 3051ULL: goto x86_l_beb;
	case 3059ULL: goto x86_l_bf3;
	case 3065ULL: goto x86_l_bf9;
	case 3071ULL: goto x86_l_bff;
	case 3077ULL: goto x86_l_c05;
	case 3080ULL: goto x86_l_c08;
	case 3086ULL: goto x86_l_c0e;
	case 3092ULL: goto x86_l_c14;
	case 3099ULL: goto x86_l_c1b;
	case 3107ULL: goto x86_l_c23;
	case 3115ULL: goto x86_l_c2b;
	case 3119ULL: goto x86_l_c2f;
	case 3126ULL: goto x86_l_c36;
	case 3135ULL: goto x86_l_c3f;
	case 3140ULL: goto x86_l_c44;
	case 3145ULL: goto x86_l_c49;
	case 3150ULL: goto x86_l_c4e;
	case 3155ULL: goto x86_l_c53;
	case 3158ULL: goto x86_l_c56;
	case 3160ULL: goto x86_l_c58;
	case 3165ULL: goto x86_l_c5d;
	case 3168ULL: goto x86_l_c60;
	case 3170ULL: goto x86_l_c62;
	case 3173ULL: goto x86_l_c65;
	case 3179ULL: goto x86_l_c6b;
	case 3181ULL: goto x86_l_c6d;
	case 3185ULL: goto x86_l_c71;
	case 3192ULL: goto x86_l_c78;
	case 3197ULL: goto x86_l_c7d;
	case 3202ULL: goto x86_l_c82;
	case 3209ULL: goto x86_l_c89;
	case 3213ULL: goto x86_l_c8d;
	case 3220ULL: goto x86_l_c94;
	case 3225ULL: goto x86_l_c99;
	case 3230ULL: goto x86_l_c9e;
	case 3232ULL: goto x86_l_ca0;
	case 3236ULL: goto x86_l_ca4;
	case 3238ULL: goto x86_l_ca6;
	case 3240ULL: goto x86_l_ca8;
	case 3243ULL: goto x86_l_cab;
	case 3249ULL: goto x86_l_cb1;
	case 3255ULL: goto x86_l_cb7;
	case 3257ULL: goto x86_l_cb9;
	case 3262ULL: goto x86_l_cbe;
	case 3269ULL: goto x86_l_cc5;
	case 3274ULL: goto x86_l_cca;
	case 3276ULL: goto x86_l_ccc;
	case 3284ULL: goto x86_l_cd4;
	case 3290ULL: goto x86_l_cda;
	case 3293ULL: goto x86_l_cdd;
	case 3300ULL: goto x86_l_ce4;
	case 3302ULL: goto x86_l_ce6;
	case 3310ULL: goto x86_l_cee;
	case 3316ULL: goto x86_l_cf4;
	case 3318ULL: goto x86_l_cf6;
	case 3321ULL: goto x86_l_cf9;
	case 3328ULL: goto x86_l_d00;
	case 3332ULL: goto x86_l_d04;
	case 3339ULL: goto x86_l_d0b;
	case 3344ULL: goto x86_l_d10;
	case 3349ULL: goto x86_l_d15;
	case 3354ULL: goto x86_l_d1a;
	case 3356ULL: goto x86_l_d1c;
	case 3359ULL: goto x86_l_d1f;
	case 3361ULL: goto x86_l_d21;
	case 3364ULL: goto x86_l_d24;
	case 3371ULL: goto x86_l_d2b;
	case 3377ULL: goto x86_l_d31;
	case 3384ULL: goto x86_l_d38;
	case 3388ULL: goto x86_l_d3c;
	case 3393ULL: goto x86_l_d41;
	case 3398ULL: goto x86_l_d46;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6c3:
	/* 0x6c3: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6c7:
	/* 0x6c7: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_6ca:
	/* 0x6ca: jmp    6ce <syscall__execveat_enter+0x6ce> */
	goto x86_l_6ce;
x86_l_6cc:
	/* 0x6cc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ce:
	/* 0x6ce: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_6d1:
	/* 0x6d1: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_6d4:
	/* 0x6d4: or     r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_6d7:
	/* 0x6d7: and    r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_6da:
	/* 0x6da: movzx  r14d,WORD PTR [rsp+0x56] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 86ULL);
x86_l_6e0:
	/* 0x6e0: cmp    QWORD PTR [rbp+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_6e8:
	/* 0x6e8: je     7d1 <syscall__execveat_enter+0x7d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7d1;
	}
x86_l_6ee:
	/* 0x6ee: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_6f3:
	/* 0x6f3: add    rdx,QWORD PTR [rbp+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_6fa:
	/* 0x6fa: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6ff:
	/* 0x6ff: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_704:
	/* 0x704: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_709:
	/* 0x709: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_70e:
	/* 0x70e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_710:
	/* 0x710: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_715:
	/* 0x715: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_71a:
	/* 0x71a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_71f:
	/* 0x71f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_724:
	/* 0x724: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_729:
	/* 0x729: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72b:
	/* 0x72b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_730:
	/* 0x730: lea    r12,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_735:
	/* 0x735: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_73a:
	/* 0x73a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_73f:
	/* 0x73f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_742:
	/* 0x742: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_747:
	/* 0x747: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_749:
	/* 0x749: lea    r15,[rbp+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_74d:
	/* 0x74d: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_752:
	/* 0x752: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_757:
	/* 0x757: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_75a:
	/* 0x75a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_75f:
	/* 0x75f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_762:
	/* 0x762: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_764:
	/* 0x764: mov    r12,QWORD PTR [rbp+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_76b:
	/* 0x76b: mov    rbp,QWORD PTR [rbp+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_772:
	/* 0x772: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_778:
	/* 0x778: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_77f:
	/* 0x77f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_784:
	/* 0x784: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_789:
	/* 0x789: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_78c:
	/* 0x78c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_78e:
	/* 0x78e: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_795:
	/* 0x795: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_798:
	/* 0x798: je     7b8 <syscall__execveat_enter+0x7b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7b8;
	}
x86_l_79a:
	/* 0x79a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_79d:
	/* 0x79d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7a2:
	/* 0x7a2: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_7a5:
	/* 0x7a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a7:
	/* 0x7a7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7aa:
	/* 0x7aa: je     7b8 <syscall__execveat_enter+0x7b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7b8;
	}
x86_l_7ac:
	/* 0x7ac: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7af:
	/* 0x7af: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7b3:
	/* 0x7b3: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_7b6:
	/* 0x7b6: jmp    7ba <syscall__execveat_enter+0x7ba> */
	goto x86_l_7ba;
x86_l_7b8:
	/* 0x7b8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7ba:
	/* 0x7ba: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_7bd:
	/* 0x7bd: and    r14,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_7c0:
	/* 0x7c0: or     r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_7c3:
	/* 0x7c3: and    r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_7c6:
	/* 0x7c6: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7cb:
	/* 0x7cb: movzx  r14d,WORD PTR [rsp+0x56] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 86ULL);
x86_l_7d1:
	/* 0x7d1: cmp    QWORD PTR [rbp+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_7d9:
	/* 0x7d9: je     864 <syscall__execveat_enter+0x864> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_864;
	}
x86_l_7df:
	/* 0x7df: lea    r15,[rbp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_7e3:
	/* 0x7e3: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_7e8:
	/* 0x7e8: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_7ed:
	/* 0x7ed: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_7f0:
	/* 0x7f0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_7f5:
	/* 0x7f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f7:
	/* 0x7f7: mov    r12,QWORD PTR [rbp+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_7fe:
	/* 0x7fe: mov    rbp,QWORD PTR [rbp+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_805:
	/* 0x805: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_80b:
	/* 0x80b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_812:
	/* 0x812: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_817:
	/* 0x817: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_81c:
	/* 0x81c: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_81f:
	/* 0x81f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_821:
	/* 0x821: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_828:
	/* 0x828: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_82b:
	/* 0x82b: je     84b <syscall__execveat_enter+0x84b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_84b;
	}
x86_l_82d:
	/* 0x82d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_830:
	/* 0x830: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_835:
	/* 0x835: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_838:
	/* 0x838: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_83a:
	/* 0x83a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_83d:
	/* 0x83d: je     84b <syscall__execveat_enter+0x84b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_84b;
	}
x86_l_83f:
	/* 0x83f: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_842:
	/* 0x842: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_846:
	/* 0x846: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_849:
	/* 0x849: jmp    84d <syscall__execveat_enter+0x84d> */
	goto x86_l_84d;
x86_l_84b:
	/* 0x84b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_84d:
	/* 0x84d: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_850:
	/* 0x850: and    r14,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_853:
	/* 0x853: or     r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_856:
	/* 0x856: and    r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_859:
	/* 0x859: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_85e:
	/* 0x85e: movzx  r14d,WORD PTR [rsp+0x56] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 86ULL);
x86_l_864:
	/* 0x864: mov    r15,QWORD PTR [rbp+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_86b:
	/* 0x86b: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_86e:
	/* 0x86e: je     8da <syscall__execveat_enter+0x8da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8da;
	}
x86_l_870:
	/* 0x870: mov    eax,DWORD PTR [rbp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_873:
	/* 0x873: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_877:
	/* 0x877: mov    r12,QWORD PTR [rbp+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_87e:
	/* 0x87e: mov    WORD PTR [rsp+0x4],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_884:
	/* 0x884: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_88b:
	/* 0x88b: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_890:
	/* 0x890: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_895:
	/* 0x895: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_898:
	/* 0x898: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_89a:
	/* 0x89a: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_8a1:
	/* 0x8a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8a4:
	/* 0x8a4: je     8c6 <syscall__execveat_enter+0x8c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8c6;
	}
x86_l_8a6:
	/* 0x8a6: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_8a9:
	/* 0x8a9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8ae:
	/* 0x8ae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8b3:
	/* 0x8b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b5:
	/* 0x8b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8b8:
	/* 0x8b8: je     8c6 <syscall__execveat_enter+0x8c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8c6;
	}
x86_l_8ba:
	/* 0x8ba: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8bd:
	/* 0x8bd: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8c1:
	/* 0x8c1: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_8c4:
	/* 0x8c4: jmp    8c8 <syscall__execveat_enter+0x8c8> */
	goto x86_l_8c8;
x86_l_8c6:
	/* 0x8c6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8c8:
	/* 0x8c8: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_8cb:
	/* 0x8cb: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_8ce:
	/* 0x8ce: or     r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_8d1:
	/* 0x8d1: and    r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_8d4:
	/* 0x8d4: movzx  r14d,WORD PTR [rsp+0x56] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 86ULL);
x86_l_8da:
	/* 0x8da: mov    r15,QWORD PTR [rbp+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_8e1:
	/* 0x8e1: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_8e4:
	/* 0x8e4: je     947 <syscall__execveat_enter+0x947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_947;
	}
x86_l_8e6:
	/* 0x8e6: mov    r12,QWORD PTR [rbp+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_8ed:
	/* 0x8ed: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8f3:
	/* 0x8f3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_8fa:
	/* 0x8fa: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8ff:
	/* 0x8ff: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_904:
	/* 0x904: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_907:
	/* 0x907: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_909:
	/* 0x909: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_910:
	/* 0x910: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_913:
	/* 0x913: je     933 <syscall__execveat_enter+0x933> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_933;
	}
x86_l_915:
	/* 0x915: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_918:
	/* 0x918: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_91d:
	/* 0x91d: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_920:
	/* 0x920: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_922:
	/* 0x922: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_925:
	/* 0x925: je     933 <syscall__execveat_enter+0x933> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_933;
	}
x86_l_927:
	/* 0x927: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_92a:
	/* 0x92a: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_92e:
	/* 0x92e: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_931:
	/* 0x931: jmp    935 <syscall__execveat_enter+0x935> */
	goto x86_l_935;
x86_l_933:
	/* 0x933: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_935:
	/* 0x935: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_938:
	/* 0x938: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_93b:
	/* 0x93b: or     r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_93e:
	/* 0x93e: and    r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_941:
	/* 0x941: movzx  r14d,WORD PTR [rsp+0x56] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 86ULL);
x86_l_947:
	/* 0x947: mov    r15,QWORD PTR [rbp+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_94e:
	/* 0x94e: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_951:
	/* 0x951: je     9d8 <syscall__execveat_enter+0x9d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9d8;
	}
x86_l_957:
	/* 0x957: mov    r12,QWORD PTR [rbp+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_95e:
	/* 0x95e: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_964:
	/* 0x964: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_96b:
	/* 0x96b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_970:
	/* 0x970: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_975:
	/* 0x975: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_978:
	/* 0x978: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_97a:
	/* 0x97a: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_981:
	/* 0x981: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_984:
	/* 0x984: je     9c5 <syscall__execveat_enter+0x9c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9c5;
	}
x86_l_986:
	/* 0x986: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_989:
	/* 0x989: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_98e:
	/* 0x98e: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_992:
	/* 0x992: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_997:
	/* 0x997: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_99a:
	/* 0x99a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_99c:
	/* 0x99c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_99f:
	/* 0x99f: jne    9b9 <syscall__execveat_enter+0x9b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9b9;
	}
x86_l_9a1:
	/* 0x9a1: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_9a6:
	/* 0x9a6: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_9aa:
	/* 0x9aa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9af:
	/* 0x9af: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_9b2:
	/* 0x9b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b4:
	/* 0x9b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9b7:
	/* 0x9b7: je     9c5 <syscall__execveat_enter+0x9c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9c5;
	}
x86_l_9b9:
	/* 0x9b9: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9bc:
	/* 0x9bc: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9c0:
	/* 0x9c0: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_9c3:
	/* 0x9c3: jmp    9c7 <syscall__execveat_enter+0x9c7> */
	goto x86_l_9c7;
x86_l_9c5:
	/* 0x9c5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9c7:
	/* 0x9c7: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_9ca:
	/* 0x9ca: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_9cd:
	/* 0x9cd: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_9d0:
	/* 0x9d0: and    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_9d3:
	/* 0x9d3: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9d8:
	/* 0x9d8: mov    rax,QWORD PTR [rbp+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_9df:
	/* 0x9df: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9e2:
	/* 0x9e2: je     9f0 <syscall__execveat_enter+0x9f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9f0;
	}
x86_l_9e4:
	/* 0x9e4: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_9e9:
	/* 0x9e9: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_9ed:
	/* 0x9ed: or     r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_9f0:
	/* 0x9f0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9f2:
	/* 0x9f2: and    r13,QWORD PTR [rbp+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_9f9:
	/* 0x9f9: mov    rcx,QWORD PTR [rbp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a00:
	/* 0xa00: and    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_a03:
	/* 0xa03: mov    QWORD PTR [rbp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a0a:
	/* 0xa0a: je     124a <syscall__execveat_enter+0x124a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4682ULL;
	}
x86_l_a10:
	/* 0xa10: lea    rbx,[rbp+0x7d8a] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_a17:
	/* 0xa17: movzx  r14d,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_a1b:
	/* 0xa1b: cmp    r14,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 32000ULL);
x86_l_a22:
	/* 0xa22: jb     a33 <syscall__execveat_enter+0xa33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_a33;
	}
x86_l_a24:
	/* 0xa24: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a29:
	/* 0xa29: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a2e:
	/* 0xa2e: jmp    bf9 <syscall__execveat_enter+0xbf9> */
	goto x86_l_bf9;
x86_l_a33:
	/* 0xa33: mov    BYTE PTR [rbp+r14*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R14, 0), 588410519552ULL);
x86_l_a3c:
	/* 0xa3c: cmp    r14d,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 31995ULL);
x86_l_a43:
	/* 0xa43: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a48:
	/* 0xa48: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a4d:
	/* 0xa4d: ja     a88 <syscall__execveat_enter+0xa88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_a88;
	}
x86_l_a4f:
	/* 0xa4f: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a53:
	/* 0xa53: lea    rdi,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_a57:
	/* 0xa57: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_a5e:
	/* 0xa5e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a63:
	/* 0xa63: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a68:
	/* 0xa68: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a6d:
	/* 0xa6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a6f:
	/* 0xa6f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a72:
	/* 0xa72: js     a88 <syscall__execveat_enter+0xa88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_a88;
	}
x86_l_a74:
	/* 0xa74: add    r14d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_a78:
	/* 0xa78: mov    WORD PTR [rbp+0x7d8a],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_a80:
	/* 0xa80: inc    BYTE PTR [rbp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_a86:
	/* 0xa86: jmp    a8c <syscall__execveat_enter+0xa8c> */
	goto x86_l_a8c;
x86_l_a88:
	/* 0xa88: movzx  r14d,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_a8c:
	/* 0xa8c: movzx  eax,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_a90:
	/* 0xa90: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_a95:
	/* 0xa95: jae    bf9 <syscall__execveat_enter+0xbf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_bf9;
	}
x86_l_a9b:
	/* 0xa9b: mov    rdx,QWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a9f:
	/* 0xa9f: mov    BYTE PTR [rbp+rax*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519553ULL);
x86_l_aa7:
	/* 0xaa7: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_aae:
	/* 0xaae: mov    WORD PTR [rbp+0x7d8e],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32142ULL);
x86_l_ab5:
	/* 0xab5: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_abc:
	/* 0xabc: ja     b20 <syscall__execveat_enter+0xb20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b20;
	}
x86_l_abe:
	/* 0xabe: add    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ac1:
	/* 0xac1: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_ac8:
	/* 0xac8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_acd:
	/* 0xacd: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_ad2:
	/* 0xad2: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_ad9:
	/* 0xad9: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_add:
	/* 0xadd: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_ae4:
	/* 0xae4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_ae9:
	/* 0xae9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aeb:
	/* 0xaeb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_aed:
	/* 0xaed: jle    b1d <syscall__execveat_enter+0xb1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_b1d;
	}
x86_l_aef:
	/* 0xaef: movzx  ecx,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_af2:
	/* 0xaf2: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_af9:
	/* 0xaf9: ja     b20 <syscall__execveat_enter+0xb20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b20;
	}
x86_l_afb:
	/* 0xafb: mov    DWORD PTR [rcx+rbp*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 138ULL);
x86_l_b02:
	/* 0xb02: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_b09:
	/* 0xb09: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_b0c:
	/* 0xb0c: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_b13:
	/* 0xb13: inc    BYTE PTR [rbp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_b19:
	/* 0xb19: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_b1b:
	/* 0xb1b: jmp    b20 <syscall__execveat_enter+0xb20> */
	goto x86_l_b20;
x86_l_b1d:
	/* 0xb1d: movzx  ecx,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b20:
	/* 0xb20: movzx  eax,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_b23:
	/* 0xb23: cmp    eax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31999ULL);
x86_l_b28:
	/* 0xb28: ja     bf9 <syscall__execveat_enter+0xbf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_bf9;
	}
x86_l_b2e:
	/* 0xb2e: mov    r13,QWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b35:
	/* 0xb35: mov    BYTE PTR [rbp+rax*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519554ULL);
x86_l_b3d:
	/* 0xb3d: movzx  r15d,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_b45:
	/* 0xb45: lea    eax,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_b49:
	/* 0xb49: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_b50:
	/* 0xb50: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_b59:
	/* 0xb59: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b5e:
	/* 0xb5e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b63:
	/* 0xb63: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b68:
	/* 0xb68: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b6d:
	/* 0xb6d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_b70:
	/* 0xb70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b72:
	/* 0xb72: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b77:
	/* 0xb77: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_b7a:
	/* 0xb7a: je     bd1 <syscall__execveat_enter+0xbd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bd1;
	}
x86_l_b7c:
	/* 0xb7c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b7f:
	/* 0xb7f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_b85:
	/* 0xb85: ja     bd1 <syscall__execveat_enter+0xbd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_bd1;
	}
x86_l_b87:
	/* 0xb87: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_b8b:
	/* 0xb8b: add    rdx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_b92:
	/* 0xb92: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_b97:
	/* 0xb97: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_b9c:
	/* 0xb9c: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_ba3:
	/* 0xba3: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_ba7:
	/* 0xba7: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_bae:
	/* 0xbae: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bb3:
	/* 0xbb3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_bb8:
	/* 0xbb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bba:
	/* 0xbba: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bbe:
	/* 0xbbe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bc0:
	/* 0xbc0: jle    bd1 <syscall__execveat_enter+0xbd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_bd1;
	}
x86_l_bc2:
	/* 0xbc2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_bc5:
	/* 0xbc5: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_bcb:
	/* 0xbcb: jbe    351a <syscall__execveat_enter+0x351a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13594ULL;
	}
x86_l_bd1:
	/* 0xbd1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bd3:
	/* 0xbd3: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_bd8:
	/* 0xbd8: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_bdd:
	/* 0xbdd: cmp    r15d,0x7cfe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 31998ULL);
x86_l_be4:
	/* 0xbe4: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_be9:
	/* 0xbe9: ja     bf9 <syscall__execveat_enter+0xbf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_bf9;
	}
x86_l_beb:
	/* 0xbeb: mov    BYTE PTR [rbp+r15*1+0x8a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 138ULL);
x86_l_bf3:
	/* 0xbf3: inc    BYTE PTR [rbp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_bf9:
	/* 0xbf9: test   BYTE PTR [r12+0x4],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869185ULL);
x86_l_bff:
	/* 0xbff: je     cda <syscall__execveat_enter+0xcda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cda;
	}
x86_l_c05:
	/* 0xc05: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c08:
	/* 0xc08: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_c0e:
	/* 0xc0e: ja     cda <syscall__execveat_enter+0xcda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_cda;
	}
x86_l_c14:
	/* 0xc14: mov    r13,QWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c1b:
	/* 0xc1b: mov    BYTE PTR [rbp+rax*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519555ULL);
x86_l_c23:
	/* 0xc23: movzx  r15d,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_c2b:
	/* 0xc2b: lea    eax,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_c2f:
	/* 0xc2f: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_c36:
	/* 0xc36: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_c3f:
	/* 0xc3f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c44:
	/* 0xc44: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c49:
	/* 0xc49: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c4e:
	/* 0xc4e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c53:
	/* 0xc53: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_c56:
	/* 0xc56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c58:
	/* 0xc58: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c5d:
	/* 0xc5d: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_c60:
	/* 0xc60: je     cb7 <syscall__execveat_enter+0xcb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cb7;
	}
x86_l_c62:
	/* 0xc62: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c65:
	/* 0xc65: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_c6b:
	/* 0xc6b: ja     cb7 <syscall__execveat_enter+0xcb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_cb7;
	}
x86_l_c6d:
	/* 0xc6d: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_c71:
	/* 0xc71: add    rdx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_c78:
	/* 0xc78: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_c7d:
	/* 0xc7d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_c82:
	/* 0xc82: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_c89:
	/* 0xc89: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_c8d:
	/* 0xc8d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_c94:
	/* 0xc94: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c99:
	/* 0xc99: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_c9e:
	/* 0xc9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ca0:
	/* 0xca0: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ca4:
	/* 0xca4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ca6:
	/* 0xca6: jle    cb7 <syscall__execveat_enter+0xcb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_cb7;
	}
x86_l_ca8:
	/* 0xca8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_cab:
	/* 0xcab: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_cb1:
	/* 0xcb1: jbe    1259 <syscall__execveat_enter+0x1259> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 4697ULL;
	}
x86_l_cb7:
	/* 0xcb7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cb9:
	/* 0xcb9: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_cbe:
	/* 0xcbe: cmp    r15d,0x7cfe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 31998ULL);
x86_l_cc5:
	/* 0xcc5: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cca:
	/* 0xcca: ja     cda <syscall__execveat_enter+0xcda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_cda;
	}
x86_l_ccc:
	/* 0xccc: mov    BYTE PTR [rbp+r15*1+0x8a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 138ULL);
x86_l_cd4:
	/* 0xcd4: inc    BYTE PTR [rbp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_cda:
	/* 0xcda: movzx  ebx,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_cdd:
	/* 0xcdd: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_ce4:
	/* 0xce4: ja     d31 <syscall__execveat_enter+0xd31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_d31;
	}
x86_l_ce6:
	/* 0xce6: mov    BYTE PTR [rbp+rbx*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519556ULL);
x86_l_cee:
	/* 0xcee: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_cf4:
	/* 0xcf4: ja     d31 <syscall__execveat_enter+0xd31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_d31;
	}
x86_l_cf6:
	/* 0xcf6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_cf9:
	/* 0xcf9: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_d00:
	/* 0xd00: lea    rdi,[rbx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_d04:
	/* 0xd04: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_d0b:
	/* 0xd0b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d10:
	/* 0xd10: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d15:
	/* 0xd15: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d1a:
	/* 0xd1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d1c:
	/* 0xd1c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d1f:
	/* 0xd1f: js     d31 <syscall__execveat_enter+0xd31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_d31;
	}
x86_l_d21:
	/* 0xd21: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_d24:
	/* 0xd24: mov    WORD PTR [rbp+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_d2b:
	/* 0xd2b: inc    BYTE PTR [rbp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_d31:
	/* 0xd31: mov    rbx,QWORD PTR [rbp+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_d38:
	/* 0xd38: lea    r15,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d3c:
	/* 0xd3c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d41:
	/* 0xd41: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d46:
	/* 0xd46: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
	return 3403ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3403ULL: goto x86_l_d4b;
	case 3408ULL: goto x86_l_d50;
	case 3411ULL: goto x86_l_d53;
	case 3413ULL: goto x86_l_d55;
	case 3418ULL: goto x86_l_d5a;
	case 3423ULL: goto x86_l_d5f;
	case 3427ULL: goto x86_l_d63;
	case 3432ULL: goto x86_l_d68;
	case 3437ULL: goto x86_l_d6d;
	case 3442ULL: goto x86_l_d72;
	case 3447ULL: goto x86_l_d77;
	case 3449ULL: goto x86_l_d79;
	case 3454ULL: goto x86_l_d7e;
	case 3458ULL: goto x86_l_d82;
	case 3463ULL: goto x86_l_d87;
	case 3468ULL: goto x86_l_d8c;
	case 3473ULL: goto x86_l_d91;
	case 3478ULL: goto x86_l_d96;
	case 3480ULL: goto x86_l_d98;
	case 3483ULL: goto x86_l_d9b;
	case 3488ULL: goto x86_l_da0;
	case 3492ULL: goto x86_l_da4;
	case 3497ULL: goto x86_l_da9;
	case 3502ULL: goto x86_l_dae;
	case 3507ULL: goto x86_l_db3;
	case 3512ULL: goto x86_l_db8;
	case 3514ULL: goto x86_l_dba;
	case 3518ULL: goto x86_l_dbe;
	case 3522ULL: goto x86_l_dc2;
	case 3526ULL: goto x86_l_dc6;
	case 3531ULL: goto x86_l_dcb;
	case 3536ULL: goto x86_l_dd0;
	case 3541ULL: goto x86_l_dd5;
	case 3546ULL: goto x86_l_dda;
	case 3549ULL: goto x86_l_ddd;
	case 3551ULL: goto x86_l_ddf;
	case 3556ULL: goto x86_l_de4;
	case 3561ULL: goto x86_l_de9;
	case 3566ULL: goto x86_l_dee;
	case 3571ULL: goto x86_l_df3;
	case 3576ULL: goto x86_l_df8;
	case 3579ULL: goto x86_l_dfb;
	case 3581ULL: goto x86_l_dfd;
	case 3585ULL: goto x86_l_e01;
	case 3589ULL: goto x86_l_e05;
	case 3593ULL: goto x86_l_e09;
	case 3597ULL: goto x86_l_e0d;
	case 3602ULL: goto x86_l_e12;
	case 3607ULL: goto x86_l_e17;
	case 3612ULL: goto x86_l_e1c;
	case 3617ULL: goto x86_l_e21;
	case 3619ULL: goto x86_l_e23;
	case 3623ULL: goto x86_l_e27;
	case 3627ULL: goto x86_l_e2b;
	case 3632ULL: goto x86_l_e30;
	case 3637ULL: goto x86_l_e35;
	case 3642ULL: goto x86_l_e3a;
	case 3647ULL: goto x86_l_e3f;
	case 3650ULL: goto x86_l_e42;
	case 3652ULL: goto x86_l_e44;
	case 3657ULL: goto x86_l_e49;
	case 3661ULL: goto x86_l_e4d;
	case 3666ULL: goto x86_l_e52;
	case 3671ULL: goto x86_l_e57;
	case 3676ULL: goto x86_l_e5c;
	case 3681ULL: goto x86_l_e61;
	case 3683ULL: goto x86_l_e63;
	case 3688ULL: goto x86_l_e68;
	case 3693ULL: goto x86_l_e6d;
	case 3698ULL: goto x86_l_e72;
	case 3703ULL: goto x86_l_e77;
	case 3708ULL: goto x86_l_e7c;
	case 3711ULL: goto x86_l_e7f;
	case 3713ULL: goto x86_l_e81;
	case 3717ULL: goto x86_l_e85;
	case 3721ULL: goto x86_l_e89;
	case 3725ULL: goto x86_l_e8d;
	case 3729ULL: goto x86_l_e91;
	case 3734ULL: goto x86_l_e96;
	case 3739ULL: goto x86_l_e9b;
	case 3744ULL: goto x86_l_ea0;
	case 3749ULL: goto x86_l_ea5;
	case 3751ULL: goto x86_l_ea7;
	case 3755ULL: goto x86_l_eab;
	case 3759ULL: goto x86_l_eaf;
	case 3764ULL: goto x86_l_eb4;
	case 3769ULL: goto x86_l_eb9;
	case 3774ULL: goto x86_l_ebe;
	case 3779ULL: goto x86_l_ec3;
	case 3782ULL: goto x86_l_ec6;
	case 3784ULL: goto x86_l_ec8;
	case 3789ULL: goto x86_l_ecd;
	case 3794ULL: goto x86_l_ed2;
	case 3799ULL: goto x86_l_ed7;
	case 3804ULL: goto x86_l_edc;
	case 3809ULL: goto x86_l_ee1;
	case 3812ULL: goto x86_l_ee4;
	case 3814ULL: goto x86_l_ee6;
	case 3818ULL: goto x86_l_eea;
	case 3822ULL: goto x86_l_eee;
	case 3826ULL: goto x86_l_ef2;
	case 3830ULL: goto x86_l_ef6;
	case 3835ULL: goto x86_l_efb;
	case 3840ULL: goto x86_l_f00;
	case 3845ULL: goto x86_l_f05;
	case 3850ULL: goto x86_l_f0a;
	case 3852ULL: goto x86_l_f0c;
	case 3857ULL: goto x86_l_f11;
	case 3861ULL: goto x86_l_f15;
	case 3866ULL: goto x86_l_f1a;
	case 3871ULL: goto x86_l_f1f;
	case 3876ULL: goto x86_l_f24;
	case 3881ULL: goto x86_l_f29;
	case 3883ULL: goto x86_l_f2b;
	case 3888ULL: goto x86_l_f30;
	case 3892ULL: goto x86_l_f34;
	case 3897ULL: goto x86_l_f39;
	case 3902ULL: goto x86_l_f3e;
	case 3907ULL: goto x86_l_f43;
	case 3912ULL: goto x86_l_f48;
	case 3915ULL: goto x86_l_f4b;
	case 3917ULL: goto x86_l_f4d;
	case 3922ULL: goto x86_l_f52;
	case 3927ULL: goto x86_l_f57;
	case 3932ULL: goto x86_l_f5c;
	case 3937ULL: goto x86_l_f61;
	case 3942ULL: goto x86_l_f66;
	case 3945ULL: goto x86_l_f69;
	case 3947ULL: goto x86_l_f6b;
	case 3951ULL: goto x86_l_f6f;
	case 3955ULL: goto x86_l_f73;
	case 3959ULL: goto x86_l_f77;
	case 3963ULL: goto x86_l_f7b;
	case 3968ULL: goto x86_l_f80;
	case 3973ULL: goto x86_l_f85;
	case 3978ULL: goto x86_l_f8a;
	case 3983ULL: goto x86_l_f8f;
	case 3985ULL: goto x86_l_f91;
	case 3990ULL: goto x86_l_f96;
	case 3994ULL: goto x86_l_f9a;
	case 3999ULL: goto x86_l_f9f;
	case 4004ULL: goto x86_l_fa4;
	case 4009ULL: goto x86_l_fa9;
	case 4014ULL: goto x86_l_fae;
	case 4016ULL: goto x86_l_fb0;
	case 4021ULL: goto x86_l_fb5;
	case 4023ULL: goto x86_l_fb7;
	case 4028ULL: goto x86_l_fbc;
	case 4033ULL: goto x86_l_fc1;
	case 4038ULL: goto x86_l_fc6;
	case 4043ULL: goto x86_l_fcb;
	case 4046ULL: goto x86_l_fce;
	case 4048ULL: goto x86_l_fd0;
	case 4053ULL: goto x86_l_fd5;
	case 4058ULL: goto x86_l_fda;
	case 4063ULL: goto x86_l_fdf;
	case 4068ULL: goto x86_l_fe4;
	case 4073ULL: goto x86_l_fe9;
	case 4076ULL: goto x86_l_fec;
	case 4078ULL: goto x86_l_fee;
	case 4082ULL: goto x86_l_ff2;
	case 4086ULL: goto x86_l_ff6;
	case 4090ULL: goto x86_l_ffa;
	case 4094ULL: goto x86_l_ffe;
	case 4099ULL: goto x86_l_1003;
	case 4104ULL: goto x86_l_1008;
	case 4109ULL: goto x86_l_100d;
	case 4114ULL: goto x86_l_1012;
	case 4116ULL: goto x86_l_1014;
	case 4120ULL: goto x86_l_1018;
	case 4124ULL: goto x86_l_101c;
	case 4128ULL: goto x86_l_1020;
	case 4135ULL: goto x86_l_1027;
	case 4140ULL: goto x86_l_102c;
	case 4145ULL: goto x86_l_1031;
	case 4150ULL: goto x86_l_1036;
	case 4154ULL: goto x86_l_103a;
	case 4159ULL: goto x86_l_103f;
	case 4162ULL: goto x86_l_1042;
	case 4164ULL: goto x86_l_1044;
	case 4169ULL: goto x86_l_1049;
	case 4173ULL: goto x86_l_104d;
	case 4178ULL: goto x86_l_1052;
	case 4183ULL: goto x86_l_1057;
	case 4188ULL: goto x86_l_105c;
	case 4193ULL: goto x86_l_1061;
	case 4195ULL: goto x86_l_1063;
	case 4200ULL: goto x86_l_1068;
	case 4205ULL: goto x86_l_106d;
	case 4210ULL: goto x86_l_1072;
	case 4215ULL: goto x86_l_1077;
	case 4220ULL: goto x86_l_107c;
	case 4225ULL: goto x86_l_1081;
	case 4227ULL: goto x86_l_1083;
	case 4231ULL: goto x86_l_1087;
	case 4235ULL: goto x86_l_108b;
	case 4240ULL: goto x86_l_1090;
	case 4242ULL: goto x86_l_1092;
	case 4246ULL: goto x86_l_1096;
	case 4250ULL: goto x86_l_109a;
	case 4255ULL: goto x86_l_109f;
	case 4260ULL: goto x86_l_10a4;
	case 4265ULL: goto x86_l_10a9;
	case 4270ULL: goto x86_l_10ae;
	case 4272ULL: goto x86_l_10b0;
	case 4277ULL: goto x86_l_10b5;
	case 4281ULL: goto x86_l_10b9;
	case 4286ULL: goto x86_l_10be;
	case 4290ULL: goto x86_l_10c2;
	case 4295ULL: goto x86_l_10c7;
	case 4300ULL: goto x86_l_10cc;
	case 4305ULL: goto x86_l_10d1;
	case 4310ULL: goto x86_l_10d6;
	case 4312ULL: goto x86_l_10d8;
	case 4317ULL: goto x86_l_10dd;
	case 4321ULL: goto x86_l_10e1;
	case 4325ULL: goto x86_l_10e5;
	case 4330ULL: goto x86_l_10ea;
	case 4335ULL: goto x86_l_10ef;
	case 4340ULL: goto x86_l_10f4;
	case 4345ULL: goto x86_l_10f9;
	case 4348ULL: goto x86_l_10fc;
	case 4350ULL: goto x86_l_10fe;
	case 4355ULL: goto x86_l_1103;
	case 4359ULL: goto x86_l_1107;
	case 4364ULL: goto x86_l_110c;
	case 4369ULL: goto x86_l_1111;
	case 4374ULL: goto x86_l_1116;
	case 4379ULL: goto x86_l_111b;
	case 4382ULL: goto x86_l_111e;
	case 4384ULL: goto x86_l_1120;
	case 4389ULL: goto x86_l_1125;
	case 4391ULL: goto x86_l_1127;
	case 4396ULL: goto x86_l_112c;
	case 4404ULL: goto x86_l_1134;
	case 4408ULL: goto x86_l_1138;
	case 4416ULL: goto x86_l_1140;
	case 4421ULL: goto x86_l_1145;
	case 4426ULL: goto x86_l_114a;
	case 4431ULL: goto x86_l_114f;
	case 4433ULL: goto x86_l_1151;
	case 4438ULL: goto x86_l_1156;
	case 4443ULL: goto x86_l_115b;
	case 4448ULL: goto x86_l_1160;
	case 4453ULL: goto x86_l_1165;
	case 4456ULL: goto x86_l_1168;
	case 4458ULL: goto x86_l_116a;
	case 4463ULL: goto x86_l_116f;
	case 4468ULL: goto x86_l_1174;
	case 4473ULL: goto x86_l_1179;
	case 4478ULL: goto x86_l_117e;
	case 4483ULL: goto x86_l_1183;
	case 4485ULL: goto x86_l_1185;
	case 4490ULL: goto x86_l_118a;
	case 4495ULL: goto x86_l_118f;
	case 4500ULL: goto x86_l_1194;
	case 4505ULL: goto x86_l_1199;
	case 4508ULL: goto x86_l_119c;
	case 4513ULL: goto x86_l_11a1;
	case 4515ULL: goto x86_l_11a3;
	case 4518ULL: goto x86_l_11a6;
	case 4522ULL: goto x86_l_11aa;
	case 4527ULL: goto x86_l_11af;
	case 4532ULL: goto x86_l_11b4;
	case 4537ULL: goto x86_l_11b9;
	case 4540ULL: goto x86_l_11bc;
	case 4542ULL: goto x86_l_11be;
	case 4547ULL: goto x86_l_11c3;
	case 4552ULL: goto x86_l_11c8;
	case 4557ULL: goto x86_l_11cd;
	case 4562ULL: goto x86_l_11d2;
	case 4565ULL: goto x86_l_11d5;
	case 4567ULL: goto x86_l_11d7;
	case 4572ULL: goto x86_l_11dc;
	case 4576ULL: goto x86_l_11e0;
	case 4584ULL: goto x86_l_11e8;
	case 4586ULL: goto x86_l_11ea;
	case 4593ULL: goto x86_l_11f1;
	case 4598ULL: goto x86_l_11f6;
	case 4603ULL: goto x86_l_11fb;
	case 4608ULL: goto x86_l_1200;
	case 4611ULL: goto x86_l_1203;
	case 4613ULL: goto x86_l_1205;
	case 4615ULL: goto x86_l_1207;
	case 4617ULL: goto x86_l_1209;
	case 4621ULL: goto x86_l_120d;
	case 4629ULL: goto x86_l_1215;
	case 4634ULL: goto x86_l_121a;
	case 4639ULL: goto x86_l_121f;
	case 4642ULL: goto x86_l_1222;
	case 4648ULL: goto x86_l_1228;
	case 4652ULL: goto x86_l_122c;
	case 4659ULL: goto x86_l_1233;
	case 4664ULL: goto x86_l_1238;
	case 4669ULL: goto x86_l_123d;
	case 4674ULL: goto x86_l_1242;
	case 4677ULL: goto x86_l_1245;
	case 4680ULL: goto x86_l_1248;
	case 4682ULL: goto x86_l_124a;
	case 4689ULL: goto x86_l_1251;
	case 4691ULL: goto x86_l_1253;
	case 4692ULL: goto x86_l_1254;
	case 4697ULL: goto x86_l_1259;
	case 4701ULL: goto x86_l_125d;
	case 4708ULL: goto x86_l_1264;
	case 4713ULL: goto x86_l_1269;
	case 4718ULL: goto x86_l_126e;
	case 4723ULL: goto x86_l_1273;
	case 4730ULL: goto x86_l_127a;
	case 4734ULL: goto x86_l_127e;
	case 4741ULL: goto x86_l_1285;
	case 4746ULL: goto x86_l_128a;
	case 4748ULL: goto x86_l_128c;
	case 4753ULL: goto x86_l_1291;
	case 4760ULL: goto x86_l_1298;
	case 4763ULL: goto x86_l_129b;
	case 4770ULL: goto x86_l_12a2;
	case 4779ULL: goto x86_l_12ab;
	case 4783ULL: goto x86_l_12af;
	case 4788ULL: goto x86_l_12b4;
	case 4793ULL: goto x86_l_12b9;
	case 4798ULL: goto x86_l_12be;
	case 4803ULL: goto x86_l_12c3;
	case 4805ULL: goto x86_l_12c5;
	case 4810ULL: goto x86_l_12ca;
	case 4812ULL: goto x86_l_12cc;
	case 4815ULL: goto x86_l_12cf;
	case 4821ULL: goto x86_l_12d5;
	case 4824ULL: goto x86_l_12d8;
	case 4830ULL: goto x86_l_12de;
	case 4836ULL: goto x86_l_12e4;
	case 4841ULL: goto x86_l_12e9;
	case 4845ULL: goto x86_l_12ed;
	case 4852ULL: goto x86_l_12f4;
	case 4857ULL: goto x86_l_12f9;
	case 4862ULL: goto x86_l_12fe;
	case 4869ULL: goto x86_l_1305;
	case 4872ULL: goto x86_l_1308;
	case 4879ULL: goto x86_l_130f;
	case 4884ULL: goto x86_l_1314;
	case 4889ULL: goto x86_l_1319;
	case 4891ULL: goto x86_l_131b;
	case 4895ULL: goto x86_l_131f;
	case 4897ULL: goto x86_l_1321;
	case 4899ULL: goto x86_l_1323;
	case 4905ULL: goto x86_l_1329;
	case 4908ULL: goto x86_l_132c;
	case 4914ULL: goto x86_l_1332;
	case 4920ULL: goto x86_l_1338;
	case 4925ULL: goto x86_l_133d;
	case 4929ULL: goto x86_l_1341;
	case 4936ULL: goto x86_l_1348;
	case 4941ULL: goto x86_l_134d;
	case 4946ULL: goto x86_l_1352;
	case 4951ULL: goto x86_l_1357;
	case 4959ULL: goto x86_l_135f;
	case 4963ULL: goto x86_l_1363;
	case 4970ULL: goto x86_l_136a;
	case 4975ULL: goto x86_l_136f;
	case 4977ULL: goto x86_l_1371;
	case 4982ULL: goto x86_l_1376;
	case 4990ULL: goto x86_l_137e;
	case 4993ULL: goto x86_l_1381;
	case 5001ULL: goto x86_l_1389;
	case 5010ULL: goto x86_l_1392;
	case 5014ULL: goto x86_l_1396;
	case 5019ULL: goto x86_l_139b;
	case 5024ULL: goto x86_l_13a0;
	case 5029ULL: goto x86_l_13a5;
	case 5034ULL: goto x86_l_13aa;
	case 5036ULL: goto x86_l_13ac;
	case 5041ULL: goto x86_l_13b1;
	case 5043ULL: goto x86_l_13b3;
	case 5046ULL: goto x86_l_13b6;
	case 5052ULL: goto x86_l_13bc;
	case 5055ULL: goto x86_l_13bf;
	case 5061ULL: goto x86_l_13c5;
	case 5067ULL: goto x86_l_13cb;
	case 5072ULL: goto x86_l_13d0;
	case 5076ULL: goto x86_l_13d4;
	case 5083ULL: goto x86_l_13db;
	case 5088ULL: goto x86_l_13e0;
	case 5093ULL: goto x86_l_13e5;
	case 5100ULL: goto x86_l_13ec;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d4b:
	/* 0xd4b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d50:
	/* 0xd50: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_d53:
	/* 0xd53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d55:
	/* 0xd55: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d5a:
	/* 0xd5a: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_d5f:
	/* 0xd5f: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d63:
	/* 0xd63: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d68:
	/* 0xd68: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d6d:
	/* 0xd6d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d72:
	/* 0xd72: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d77:
	/* 0xd77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d79:
	/* 0xd79: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d7e:
	/* 0xd7e: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_d82:
	/* 0xd82: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d87:
	/* 0xd87: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d8c:
	/* 0xd8c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d91:
	/* 0xd91: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d96:
	/* 0xd96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d98:
	/* 0xd98: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_d9b:
	/* 0xd9b: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_da0:
	/* 0xda0: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_da4:
	/* 0xda4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_da9:
	/* 0xda9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_dae:
	/* 0xdae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_db3:
	/* 0xdb3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_db8:
	/* 0xdb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dba:
	/* 0xdba: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dbe:
	/* 0xdbe: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_dc2:
	/* 0xdc2: lea    r12,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dc6:
	/* 0xdc6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dcb:
	/* 0xdcb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_dd0:
	/* 0xdd0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_dd5:
	/* 0xdd5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dda:
	/* 0xdda: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_ddd:
	/* 0xddd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ddf:
	/* 0xddf: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_de4:
	/* 0xde4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_de9:
	/* 0xde9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_dee:
	/* 0xdee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_df3:
	/* 0xdf3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_df8:
	/* 0xdf8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_dfb:
	/* 0xdfb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dfd:
	/* 0xdfd: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e01:
	/* 0xe01: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_e05:
	/* 0xe05: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_e09:
	/* 0xe09: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_e0d:
	/* 0xe0d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e12:
	/* 0xe12: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e17:
	/* 0xe17: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e1c:
	/* 0xe1c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e21:
	/* 0xe21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e23:
	/* 0xe23: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e27:
	/* 0xe27: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_e2b:
	/* 0xe2b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e30:
	/* 0xe30: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e35:
	/* 0xe35: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e3a:
	/* 0xe3a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e3f:
	/* 0xe3f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e42:
	/* 0xe42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e44:
	/* 0xe44: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e49:
	/* 0xe49: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_e4d:
	/* 0xe4d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e52:
	/* 0xe52: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e57:
	/* 0xe57: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e5c:
	/* 0xe5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e61:
	/* 0xe61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e63:
	/* 0xe63: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e68:
	/* 0xe68: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e6d:
	/* 0xe6d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e72:
	/* 0xe72: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e77:
	/* 0xe77: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e7c:
	/* 0xe7c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e7f:
	/* 0xe7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e81:
	/* 0xe81: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e85:
	/* 0xe85: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_e89:
	/* 0xe89: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_e8d:
	/* 0xe8d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_e91:
	/* 0xe91: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e96:
	/* 0xe96: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e9b:
	/* 0xe9b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ea0:
	/* 0xea0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ea5:
	/* 0xea5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea7:
	/* 0xea7: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eab:
	/* 0xeab: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_eaf:
	/* 0xeaf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eb4:
	/* 0xeb4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_eb9:
	/* 0xeb9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ebe:
	/* 0xebe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ec3:
	/* 0xec3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_ec6:
	/* 0xec6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ec8:
	/* 0xec8: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ecd:
	/* 0xecd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ed2:
	/* 0xed2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ed7:
	/* 0xed7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_edc:
	/* 0xedc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ee1:
	/* 0xee1: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_ee4:
	/* 0xee4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee6:
	/* 0xee6: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eea:
	/* 0xeea: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_eee:
	/* 0xeee: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_ef2:
	/* 0xef2: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ef6:
	/* 0xef6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_efb:
	/* 0xefb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f00:
	/* 0xf00: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f05:
	/* 0xf05: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f0a:
	/* 0xf0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f0c:
	/* 0xf0c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f11:
	/* 0xf11: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_f15:
	/* 0xf15: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f1a:
	/* 0xf1a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f1f:
	/* 0xf1f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f24:
	/* 0xf24: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f29:
	/* 0xf29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f2b:
	/* 0xf2b: mov    r13d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f30:
	/* 0xf30: lea    r15,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f34:
	/* 0xf34: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f39:
	/* 0xf39: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f3e:
	/* 0xf3e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f43:
	/* 0xf43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f48:
	/* 0xf48: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_f4b:
	/* 0xf4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f4d:
	/* 0xf4d: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f52:
	/* 0xf52: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f57:
	/* 0xf57: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f5c:
	/* 0xf5c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f61:
	/* 0xf61: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f66:
	/* 0xf66: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_f69:
	/* 0xf69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f6b:
	/* 0xf6b: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f6f:
	/* 0xf6f: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_f73:
	/* 0xf73: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_f77:
	/* 0xf77: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f7b:
	/* 0xf7b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f80:
	/* 0xf80: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f85:
	/* 0xf85: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f8a:
	/* 0xf8a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f8f:
	/* 0xf8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f91:
	/* 0xf91: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f96:
	/* 0xf96: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_f9a:
	/* 0xf9a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f9f:
	/* 0xf9f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_fa4:
	/* 0xfa4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fa9:
	/* 0xfa9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fae:
	/* 0xfae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb0:
	/* 0xfb0: cmp    r13d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_fb5:
	/* 0xfb5: jne    101c <syscall__execveat_enter+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_101c;
	}
x86_l_fb7:
	/* 0xfb7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fbc:
	/* 0xfbc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fc1:
	/* 0xfc1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fc6:
	/* 0xfc6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fcb:
	/* 0xfcb: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_fce:
	/* 0xfce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fd0:
	/* 0xfd0: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fd5:
	/* 0xfd5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fda:
	/* 0xfda: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_fdf:
	/* 0xfdf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fe4:
	/* 0xfe4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fe9:
	/* 0xfe9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_fec:
	/* 0xfec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fee:
	/* 0xfee: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ff2:
	/* 0xff2: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_ff6:
	/* 0xff6: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_ffa:
	/* 0xffa: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_ffe:
	/* 0xffe: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1003:
	/* 0x1003: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1008:
	/* 0x1008: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_100d:
	/* 0x100d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1012:
	/* 0x1012: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1014:
	/* 0x1014: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1018:
	/* 0x1018: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_101c:
	/* 0x101c: mov    DWORD PTR [r14+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1020:
	/* 0x1020: lea    r12,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1027:
	/* 0x1027: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_102c:
	/* 0x102c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1031:
	/* 0x1031: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1036:
	/* 0x1036: lea    r15,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_103a:
	/* 0x103a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_103f:
	/* 0x103f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1042:
	/* 0x1042: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1044:
	/* 0x1044: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1049:
	/* 0x1049: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_104d:
	/* 0x104d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1052:
	/* 0x1052: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1057:
	/* 0x1057: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_105c:
	/* 0x105c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1061:
	/* 0x1061: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1063:
	/* 0x1063: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1068:
	/* 0x1068: lea    rdi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_106d:
	/* 0x106d: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1072:
	/* 0x1072: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1077:
	/* 0x1077: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_107c:
	/* 0x107c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1081:
	/* 0x1081: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1083:
	/* 0x1083: mov    eax,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1087:
	/* 0x1087: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_108b:
	/* 0x108b: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1090:
	/* 0x1090: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1092:
	/* 0x1092: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1096:
	/* 0x1096: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_109a:
	/* 0x109a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_109f:
	/* 0x109f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10a4:
	/* 0x10a4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10a9:
	/* 0x10a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10ae:
	/* 0x10ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b0:
	/* 0x10b0: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10b5:
	/* 0x10b5: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10b9:
	/* 0x10b9: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_10be:
	/* 0x10be: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_10c2:
	/* 0x10c2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10c7:
	/* 0x10c7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10cc:
	/* 0x10cc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10d1:
	/* 0x10d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10d6:
	/* 0x10d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d8:
	/* 0x10d8: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10dd:
	/* 0x10dd: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_10e1:
	/* 0x10e1: add    rbp,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_10e5:
	/* 0x10e5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10ea:
	/* 0x10ea: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10ef:
	/* 0x10ef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10f4:
	/* 0x10f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10f9:
	/* 0x10f9: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_10fc:
	/* 0x10fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10fe:
	/* 0x10fe: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1103:
	/* 0x1103: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1107:
	/* 0x1107: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_110c:
	/* 0x110c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1111:
	/* 0x1111: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1116:
	/* 0x1116: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_111b:
	/* 0x111b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_111e:
	/* 0x111e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1120:
	/* 0x1120: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_1125:
	/* 0x1125: je     112c <syscall__execveat_enter+0x112c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_112c;
	}
x86_l_1127:
	/* 0x1127: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_112c:
	/* 0x112c: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_1134:
	/* 0x1134: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1138:
	/* 0x1138: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_1140:
	/* 0x1140: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1145:
	/* 0x1145: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_114a:
	/* 0x114a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_114f:
	/* 0x114f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1151:
	/* 0x1151: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1156:
	/* 0x1156: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_115b:
	/* 0x115b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1160:
	/* 0x1160: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1165:
	/* 0x1165: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1168:
	/* 0x1168: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_116a:
	/* 0x116a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_116f:
	/* 0x116f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1174:
	/* 0x1174: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1179:
	/* 0x1179: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_117e:
	/* 0x117e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1183:
	/* 0x1183: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1185:
	/* 0x1185: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_118a:
	/* 0x118a: lea    rbx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_118f:
	/* 0x118f: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_1194:
	/* 0x1194: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1199:
	/* 0x1199: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_119c:
	/* 0x119c: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_11a1:
	/* 0x11a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11a3:
	/* 0x11a3: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_11a6:
	/* 0x11a6: add    rdi,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_11aa:
	/* 0x11aa: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_11af:
	/* 0x11af: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_11b4:
	/* 0x11b4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_11b9:
	/* 0x11b9: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_11bc:
	/* 0x11bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11be:
	/* 0x11be: mov    ecx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 104ULL);
x86_l_11c3:
	/* 0x11c3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11c8:
	/* 0x11c8: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_11cd:
	/* 0x11cd: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_11d2:
	/* 0x11d2: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_11d5:
	/* 0x11d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11d7:
	/* 0x11d7: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_11dc:
	/* 0x11dc: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_11e0:
	/* 0x11e0: mov    rbx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_11e8:
	/* 0x11e8: je     120d <syscall__execveat_enter+0x120d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_120d;
	}
x86_l_11ea:
	/* 0x11ea: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_11f1:
	/* 0x11f1: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_11f6:
	/* 0x11f6: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_11fb:
	/* 0x11fb: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1200:
	/* 0x1200: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1203:
	/* 0x1203: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1205:
	/* 0x1205: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1207:
	/* 0x1207: js     120d <syscall__execveat_enter+0x120d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_120d;
	}
x86_l_1209:
	/* 0x1209: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_120d:
	/* 0x120d: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1215:
	/* 0x1215: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_121a:
	/* 0x121a: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_121f:
	/* 0x121f: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_1222:
	/* 0x1222: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_1228:
	/* 0x1228: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_122c:
	/* 0x122c: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_1233:
	/* 0x1233: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_1238:
	/* 0x1238: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_123d:
	/* 0x123d: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1242:
	/* 0x1242: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1245:
	/* 0x1245: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_1248:
	/* 0x1248: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_124a:
	/* 0x124a: add    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_1251:
	/* 0x1251: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1253:
	/* 0x1253: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1254:
	/* 0x1254: jmp    57ef <syscall__execveat_enter+0x57ef> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1259:
	/* 0x1259: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_125d:
	/* 0x125d: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1264:
	/* 0x1264: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1269:
	/* 0x1269: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_126e:
	/* 0x126e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1273:
	/* 0x1273: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_127a:
	/* 0x127a: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_127e:
	/* 0x127e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1285:
	/* 0x1285: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_128a:
	/* 0x128a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_128c:
	/* 0x128c: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1291:
	/* 0x1291: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1298:
	/* 0x1298: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_129b:
	/* 0x129b: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_12a2:
	/* 0x12a2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_12ab:
	/* 0x12ab: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12af:
	/* 0x12af: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12b4:
	/* 0x12b4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12b9:
	/* 0x12b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12be:
	/* 0x12be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12c3:
	/* 0x12c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12c5:
	/* 0x12c5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12ca:
	/* 0x12ca: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_12cc:
	/* 0x12cc: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_12cf:
	/* 0x12cf: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_12d5:
	/* 0x12d5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_12d8:
	/* 0x12d8: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_12de:
	/* 0x12de: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_12e4:
	/* 0x12e4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12e9:
	/* 0x12e9: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_12ed:
	/* 0x12ed: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_12f4:
	/* 0x12f4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_12f9:
	/* 0x12f9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_12fe:
	/* 0x12fe: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1305:
	/* 0x1305: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1308:
	/* 0x1308: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_130f:
	/* 0x130f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1314:
	/* 0x1314: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1319:
	/* 0x1319: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_131b:
	/* 0x131b: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_131f:
	/* 0x131f: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_1321:
	/* 0x1321: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1323:
	/* 0x1323: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_1329:
	/* 0x1329: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_132c:
	/* 0x132c: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1332:
	/* 0x1332: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_1338:
	/* 0x1338: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_133d:
	/* 0x133d: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1341:
	/* 0x1341: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1348:
	/* 0x1348: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_134d:
	/* 0x134d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1352:
	/* 0x1352: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1357:
	/* 0x1357: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_135f:
	/* 0x135f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1363:
	/* 0x1363: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_136a:
	/* 0x136a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_136f:
	/* 0x136f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1371:
	/* 0x1371: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1376:
	/* 0x1376: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_137e:
	/* 0x137e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1381:
	/* 0x1381: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1389:
	/* 0x1389: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1392:
	/* 0x1392: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1396:
	/* 0x1396: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_139b:
	/* 0x139b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13a0:
	/* 0x13a0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13a5:
	/* 0x13a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13aa:
	/* 0x13aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13ac:
	/* 0x13ac: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13b1:
	/* 0x13b1: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_13b3:
	/* 0x13b3: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_13b6:
	/* 0x13b6: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_13bc:
	/* 0x13bc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_13bf:
	/* 0x13bf: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_13c5:
	/* 0x13c5: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_13cb:
	/* 0x13cb: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13d0:
	/* 0x13d0: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_13d4:
	/* 0x13d4: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_13db:
	/* 0x13db: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_13e0:
	/* 0x13e0: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_13e5:
	/* 0x13e5: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_13ec:
	/* 0x13ec: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
	return 5103ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5103ULL: goto x86_l_13ef;
	case 5110ULL: goto x86_l_13f6;
	case 5115ULL: goto x86_l_13fb;
	case 5120ULL: goto x86_l_1400;
	case 5122ULL: goto x86_l_1402;
	case 5126ULL: goto x86_l_1406;
	case 5128ULL: goto x86_l_1408;
	case 5130ULL: goto x86_l_140a;
	case 5136ULL: goto x86_l_1410;
	case 5139ULL: goto x86_l_1413;
	case 5145ULL: goto x86_l_1419;
	case 5151ULL: goto x86_l_141f;
	case 5156ULL: goto x86_l_1424;
	case 5160ULL: goto x86_l_1428;
	case 5167ULL: goto x86_l_142f;
	case 5172ULL: goto x86_l_1434;
	case 5177ULL: goto x86_l_1439;
	case 5182ULL: goto x86_l_143e;
	case 5190ULL: goto x86_l_1446;
	case 5194ULL: goto x86_l_144a;
	case 5201ULL: goto x86_l_1451;
	case 5206ULL: goto x86_l_1456;
	case 5208ULL: goto x86_l_1458;
	case 5213ULL: goto x86_l_145d;
	case 5221ULL: goto x86_l_1465;
	case 5224ULL: goto x86_l_1468;
	case 5232ULL: goto x86_l_1470;
	case 5241ULL: goto x86_l_1479;
	case 5245ULL: goto x86_l_147d;
	case 5250ULL: goto x86_l_1482;
	case 5255ULL: goto x86_l_1487;
	case 5260ULL: goto x86_l_148c;
	case 5265ULL: goto x86_l_1491;
	case 5267ULL: goto x86_l_1493;
	case 5272ULL: goto x86_l_1498;
	case 5274ULL: goto x86_l_149a;
	case 5277ULL: goto x86_l_149d;
	case 5283ULL: goto x86_l_14a3;
	case 5286ULL: goto x86_l_14a6;
	case 5292ULL: goto x86_l_14ac;
	case 5298ULL: goto x86_l_14b2;
	case 5303ULL: goto x86_l_14b7;
	case 5307ULL: goto x86_l_14bb;
	case 5314ULL: goto x86_l_14c2;
	case 5319ULL: goto x86_l_14c7;
	case 5324ULL: goto x86_l_14cc;
	case 5331ULL: goto x86_l_14d3;
	case 5334ULL: goto x86_l_14d6;
	case 5341ULL: goto x86_l_14dd;
	case 5346ULL: goto x86_l_14e2;
	case 5351ULL: goto x86_l_14e7;
	case 5353ULL: goto x86_l_14e9;
	case 5357ULL: goto x86_l_14ed;
	case 5359ULL: goto x86_l_14ef;
	case 5361ULL: goto x86_l_14f1;
	case 5367ULL: goto x86_l_14f7;
	case 5370ULL: goto x86_l_14fa;
	case 5376ULL: goto x86_l_1500;
	case 5382ULL: goto x86_l_1506;
	case 5387ULL: goto x86_l_150b;
	case 5391ULL: goto x86_l_150f;
	case 5398ULL: goto x86_l_1516;
	case 5403ULL: goto x86_l_151b;
	case 5408ULL: goto x86_l_1520;
	case 5413ULL: goto x86_l_1525;
	case 5421ULL: goto x86_l_152d;
	case 5425ULL: goto x86_l_1531;
	case 5432ULL: goto x86_l_1538;
	case 5437ULL: goto x86_l_153d;
	case 5439ULL: goto x86_l_153f;
	case 5444ULL: goto x86_l_1544;
	case 5452ULL: goto x86_l_154c;
	case 5455ULL: goto x86_l_154f;
	case 5463ULL: goto x86_l_1557;
	case 5472ULL: goto x86_l_1560;
	case 5476ULL: goto x86_l_1564;
	case 5481ULL: goto x86_l_1569;
	case 5486ULL: goto x86_l_156e;
	case 5491ULL: goto x86_l_1573;
	case 5496ULL: goto x86_l_1578;
	case 5498ULL: goto x86_l_157a;
	case 5503ULL: goto x86_l_157f;
	case 5505ULL: goto x86_l_1581;
	case 5508ULL: goto x86_l_1584;
	case 5514ULL: goto x86_l_158a;
	case 5517ULL: goto x86_l_158d;
	case 5523ULL: goto x86_l_1593;
	case 5529ULL: goto x86_l_1599;
	case 5534ULL: goto x86_l_159e;
	case 5538ULL: goto x86_l_15a2;
	case 5545ULL: goto x86_l_15a9;
	case 5550ULL: goto x86_l_15ae;
	case 5555ULL: goto x86_l_15b3;
	case 5562ULL: goto x86_l_15ba;
	case 5565ULL: goto x86_l_15bd;
	case 5572ULL: goto x86_l_15c4;
	case 5577ULL: goto x86_l_15c9;
	case 5582ULL: goto x86_l_15ce;
	case 5584ULL: goto x86_l_15d0;
	case 5588ULL: goto x86_l_15d4;
	case 5590ULL: goto x86_l_15d6;
	case 5592ULL: goto x86_l_15d8;
	case 5598ULL: goto x86_l_15de;
	case 5601ULL: goto x86_l_15e1;
	case 5607ULL: goto x86_l_15e7;
	case 5613ULL: goto x86_l_15ed;
	case 5618ULL: goto x86_l_15f2;
	case 5622ULL: goto x86_l_15f6;
	case 5629ULL: goto x86_l_15fd;
	case 5634ULL: goto x86_l_1602;
	case 5639ULL: goto x86_l_1607;
	case 5644ULL: goto x86_l_160c;
	case 5652ULL: goto x86_l_1614;
	case 5656ULL: goto x86_l_1618;
	case 5663ULL: goto x86_l_161f;
	case 5668ULL: goto x86_l_1624;
	case 5670ULL: goto x86_l_1626;
	case 5675ULL: goto x86_l_162b;
	case 5683ULL: goto x86_l_1633;
	case 5686ULL: goto x86_l_1636;
	case 5694ULL: goto x86_l_163e;
	case 5703ULL: goto x86_l_1647;
	case 5707ULL: goto x86_l_164b;
	case 5712ULL: goto x86_l_1650;
	case 5717ULL: goto x86_l_1655;
	case 5722ULL: goto x86_l_165a;
	case 5727ULL: goto x86_l_165f;
	case 5729ULL: goto x86_l_1661;
	case 5734ULL: goto x86_l_1666;
	case 5736ULL: goto x86_l_1668;
	case 5739ULL: goto x86_l_166b;
	case 5745ULL: goto x86_l_1671;
	case 5748ULL: goto x86_l_1674;
	case 5754ULL: goto x86_l_167a;
	case 5760ULL: goto x86_l_1680;
	case 5765ULL: goto x86_l_1685;
	case 5769ULL: goto x86_l_1689;
	case 5776ULL: goto x86_l_1690;
	case 5781ULL: goto x86_l_1695;
	case 5786ULL: goto x86_l_169a;
	case 5793ULL: goto x86_l_16a1;
	case 5796ULL: goto x86_l_16a4;
	case 5803ULL: goto x86_l_16ab;
	case 5808ULL: goto x86_l_16b0;
	case 5813ULL: goto x86_l_16b5;
	case 5815ULL: goto x86_l_16b7;
	case 5819ULL: goto x86_l_16bb;
	case 5821ULL: goto x86_l_16bd;
	case 5823ULL: goto x86_l_16bf;
	case 5829ULL: goto x86_l_16c5;
	case 5832ULL: goto x86_l_16c8;
	case 5838ULL: goto x86_l_16ce;
	case 5844ULL: goto x86_l_16d4;
	case 5849ULL: goto x86_l_16d9;
	case 5853ULL: goto x86_l_16dd;
	case 5860ULL: goto x86_l_16e4;
	case 5865ULL: goto x86_l_16e9;
	case 5870ULL: goto x86_l_16ee;
	case 5875ULL: goto x86_l_16f3;
	case 5883ULL: goto x86_l_16fb;
	case 5887ULL: goto x86_l_16ff;
	case 5894ULL: goto x86_l_1706;
	case 5899ULL: goto x86_l_170b;
	case 5901ULL: goto x86_l_170d;
	case 5906ULL: goto x86_l_1712;
	case 5914ULL: goto x86_l_171a;
	case 5917ULL: goto x86_l_171d;
	case 5925ULL: goto x86_l_1725;
	case 5934ULL: goto x86_l_172e;
	case 5938ULL: goto x86_l_1732;
	case 5943ULL: goto x86_l_1737;
	case 5948ULL: goto x86_l_173c;
	case 5953ULL: goto x86_l_1741;
	case 5958ULL: goto x86_l_1746;
	case 5960ULL: goto x86_l_1748;
	case 5965ULL: goto x86_l_174d;
	case 5967ULL: goto x86_l_174f;
	case 5970ULL: goto x86_l_1752;
	case 5976ULL: goto x86_l_1758;
	case 5979ULL: goto x86_l_175b;
	case 5985ULL: goto x86_l_1761;
	case 5991ULL: goto x86_l_1767;
	case 5996ULL: goto x86_l_176c;
	case 6000ULL: goto x86_l_1770;
	case 6007ULL: goto x86_l_1777;
	case 6012ULL: goto x86_l_177c;
	case 6017ULL: goto x86_l_1781;
	case 6024ULL: goto x86_l_1788;
	case 6027ULL: goto x86_l_178b;
	case 6034ULL: goto x86_l_1792;
	case 6039ULL: goto x86_l_1797;
	case 6044ULL: goto x86_l_179c;
	case 6046ULL: goto x86_l_179e;
	case 6050ULL: goto x86_l_17a2;
	case 6052ULL: goto x86_l_17a4;
	case 6054ULL: goto x86_l_17a6;
	case 6060ULL: goto x86_l_17ac;
	case 6063ULL: goto x86_l_17af;
	case 6069ULL: goto x86_l_17b5;
	case 6075ULL: goto x86_l_17bb;
	case 6080ULL: goto x86_l_17c0;
	case 6084ULL: goto x86_l_17c4;
	case 6091ULL: goto x86_l_17cb;
	case 6096ULL: goto x86_l_17d0;
	case 6101ULL: goto x86_l_17d5;
	case 6106ULL: goto x86_l_17da;
	case 6114ULL: goto x86_l_17e2;
	case 6118ULL: goto x86_l_17e6;
	case 6125ULL: goto x86_l_17ed;
	case 6130ULL: goto x86_l_17f2;
	case 6132ULL: goto x86_l_17f4;
	case 6137ULL: goto x86_l_17f9;
	case 6145ULL: goto x86_l_1801;
	case 6148ULL: goto x86_l_1804;
	case 6156ULL: goto x86_l_180c;
	case 6165ULL: goto x86_l_1815;
	case 6169ULL: goto x86_l_1819;
	case 6174ULL: goto x86_l_181e;
	case 6179ULL: goto x86_l_1823;
	case 6184ULL: goto x86_l_1828;
	case 6189ULL: goto x86_l_182d;
	case 6191ULL: goto x86_l_182f;
	case 6196ULL: goto x86_l_1834;
	case 6198ULL: goto x86_l_1836;
	case 6201ULL: goto x86_l_1839;
	case 6207ULL: goto x86_l_183f;
	case 6210ULL: goto x86_l_1842;
	case 6216ULL: goto x86_l_1848;
	case 6222ULL: goto x86_l_184e;
	case 6227ULL: goto x86_l_1853;
	case 6231ULL: goto x86_l_1857;
	case 6238ULL: goto x86_l_185e;
	case 6243ULL: goto x86_l_1863;
	case 6248ULL: goto x86_l_1868;
	case 6255ULL: goto x86_l_186f;
	case 6258ULL: goto x86_l_1872;
	case 6265ULL: goto x86_l_1879;
	case 6270ULL: goto x86_l_187e;
	case 6275ULL: goto x86_l_1883;
	case 6277ULL: goto x86_l_1885;
	case 6281ULL: goto x86_l_1889;
	case 6283ULL: goto x86_l_188b;
	case 6285ULL: goto x86_l_188d;
	case 6291ULL: goto x86_l_1893;
	case 6294ULL: goto x86_l_1896;
	case 6300ULL: goto x86_l_189c;
	case 6306ULL: goto x86_l_18a2;
	case 6311ULL: goto x86_l_18a7;
	case 6315ULL: goto x86_l_18ab;
	case 6322ULL: goto x86_l_18b2;
	case 6327ULL: goto x86_l_18b7;
	case 6332ULL: goto x86_l_18bc;
	case 6337ULL: goto x86_l_18c1;
	case 6345ULL: goto x86_l_18c9;
	case 6349ULL: goto x86_l_18cd;
	case 6356ULL: goto x86_l_18d4;
	case 6361ULL: goto x86_l_18d9;
	case 6363ULL: goto x86_l_18db;
	case 6368ULL: goto x86_l_18e0;
	case 6376ULL: goto x86_l_18e8;
	case 6379ULL: goto x86_l_18eb;
	case 6387ULL: goto x86_l_18f3;
	case 6396ULL: goto x86_l_18fc;
	case 6400ULL: goto x86_l_1900;
	case 6405ULL: goto x86_l_1905;
	case 6410ULL: goto x86_l_190a;
	case 6415ULL: goto x86_l_190f;
	case 6420ULL: goto x86_l_1914;
	case 6422ULL: goto x86_l_1916;
	case 6427ULL: goto x86_l_191b;
	case 6429ULL: goto x86_l_191d;
	case 6432ULL: goto x86_l_1920;
	case 6438ULL: goto x86_l_1926;
	case 6441ULL: goto x86_l_1929;
	case 6447ULL: goto x86_l_192f;
	case 6453ULL: goto x86_l_1935;
	case 6458ULL: goto x86_l_193a;
	case 6462ULL: goto x86_l_193e;
	case 6469ULL: goto x86_l_1945;
	case 6474ULL: goto x86_l_194a;
	case 6479ULL: goto x86_l_194f;
	case 6486ULL: goto x86_l_1956;
	case 6489ULL: goto x86_l_1959;
	case 6496ULL: goto x86_l_1960;
	case 6501ULL: goto x86_l_1965;
	case 6506ULL: goto x86_l_196a;
	case 6508ULL: goto x86_l_196c;
	case 6512ULL: goto x86_l_1970;
	case 6514ULL: goto x86_l_1972;
	case 6516ULL: goto x86_l_1974;
	case 6522ULL: goto x86_l_197a;
	case 6525ULL: goto x86_l_197d;
	case 6531ULL: goto x86_l_1983;
	case 6537ULL: goto x86_l_1989;
	case 6542ULL: goto x86_l_198e;
	case 6546ULL: goto x86_l_1992;
	case 6553ULL: goto x86_l_1999;
	case 6558ULL: goto x86_l_199e;
	case 6563ULL: goto x86_l_19a3;
	case 6568ULL: goto x86_l_19a8;
	case 6576ULL: goto x86_l_19b0;
	case 6580ULL: goto x86_l_19b4;
	case 6587ULL: goto x86_l_19bb;
	case 6592ULL: goto x86_l_19c0;
	case 6594ULL: goto x86_l_19c2;
	case 6599ULL: goto x86_l_19c7;
	case 6607ULL: goto x86_l_19cf;
	case 6610ULL: goto x86_l_19d2;
	case 6618ULL: goto x86_l_19da;
	case 6627ULL: goto x86_l_19e3;
	case 6631ULL: goto x86_l_19e7;
	case 6636ULL: goto x86_l_19ec;
	case 6641ULL: goto x86_l_19f1;
	case 6646ULL: goto x86_l_19f6;
	case 6651ULL: goto x86_l_19fb;
	case 6653ULL: goto x86_l_19fd;
	case 6658ULL: goto x86_l_1a02;
	case 6660ULL: goto x86_l_1a04;
	case 6663ULL: goto x86_l_1a07;
	case 6669ULL: goto x86_l_1a0d;
	case 6672ULL: goto x86_l_1a10;
	case 6678ULL: goto x86_l_1a16;
	case 6684ULL: goto x86_l_1a1c;
	case 6689ULL: goto x86_l_1a21;
	case 6693ULL: goto x86_l_1a25;
	case 6700ULL: goto x86_l_1a2c;
	case 6705ULL: goto x86_l_1a31;
	case 6710ULL: goto x86_l_1a36;
	case 6717ULL: goto x86_l_1a3d;
	case 6720ULL: goto x86_l_1a40;
	case 6727ULL: goto x86_l_1a47;
	case 6732ULL: goto x86_l_1a4c;
	case 6737ULL: goto x86_l_1a51;
	case 6739ULL: goto x86_l_1a53;
	case 6743ULL: goto x86_l_1a57;
	case 6745ULL: goto x86_l_1a59;
	case 6747ULL: goto x86_l_1a5b;
	case 6753ULL: goto x86_l_1a61;
	case 6756ULL: goto x86_l_1a64;
	case 6762ULL: goto x86_l_1a6a;
	case 6768ULL: goto x86_l_1a70;
	case 6773ULL: goto x86_l_1a75;
	case 6777ULL: goto x86_l_1a79;
	case 6784ULL: goto x86_l_1a80;
	case 6789ULL: goto x86_l_1a85;
	case 6794ULL: goto x86_l_1a8a;
	case 6799ULL: goto x86_l_1a8f;
	case 6807ULL: goto x86_l_1a97;
	case 6811ULL: goto x86_l_1a9b;
	case 6818ULL: goto x86_l_1aa2;
	case 6823ULL: goto x86_l_1aa7;
	case 6825ULL: goto x86_l_1aa9;
	case 6830ULL: goto x86_l_1aae;
	case 6838ULL: goto x86_l_1ab6;
	case 6841ULL: goto x86_l_1ab9;
	case 6849ULL: goto x86_l_1ac1;
	case 6858ULL: goto x86_l_1aca;
	case 6862ULL: goto x86_l_1ace;
	case 6867ULL: goto x86_l_1ad3;
	case 6872ULL: goto x86_l_1ad8;
	case 6877ULL: goto x86_l_1add;
	case 6882ULL: goto x86_l_1ae2;
	case 6884ULL: goto x86_l_1ae4;
	case 6889ULL: goto x86_l_1ae9;
	case 6891ULL: goto x86_l_1aeb;
	case 6894ULL: goto x86_l_1aee;
	case 6900ULL: goto x86_l_1af4;
	case 6903ULL: goto x86_l_1af7;
	case 6909ULL: goto x86_l_1afd;
	case 6915ULL: goto x86_l_1b03;
	case 6920ULL: goto x86_l_1b08;
	case 6924ULL: goto x86_l_1b0c;
	case 6931ULL: goto x86_l_1b13;
	case 6936ULL: goto x86_l_1b18;
	case 6941ULL: goto x86_l_1b1d;
	case 6948ULL: goto x86_l_1b24;
	case 6951ULL: goto x86_l_1b27;
	case 6958ULL: goto x86_l_1b2e;
	case 6963ULL: goto x86_l_1b33;
	case 6968ULL: goto x86_l_1b38;
	case 6970ULL: goto x86_l_1b3a;
	case 6974ULL: goto x86_l_1b3e;
	case 6976ULL: goto x86_l_1b40;
	case 6978ULL: goto x86_l_1b42;
	default: return 0xffffffffffffffffULL;
	}
x86_l_13ef:
	/* 0x13ef: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_13f6:
	/* 0x13f6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13fb:
	/* 0x13fb: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1400:
	/* 0x1400: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1402:
	/* 0x1402: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1406:
	/* 0x1406: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_1408:
	/* 0x1408: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_140a:
	/* 0x140a: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_1410:
	/* 0x1410: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1413:
	/* 0x1413: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1419:
	/* 0x1419: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_141f:
	/* 0x141f: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1424:
	/* 0x1424: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1428:
	/* 0x1428: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_142f:
	/* 0x142f: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1434:
	/* 0x1434: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1439:
	/* 0x1439: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_143e:
	/* 0x143e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1446:
	/* 0x1446: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_144a:
	/* 0x144a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1451:
	/* 0x1451: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1456:
	/* 0x1456: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1458:
	/* 0x1458: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_145d:
	/* 0x145d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1465:
	/* 0x1465: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1468:
	/* 0x1468: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1470:
	/* 0x1470: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1479:
	/* 0x1479: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_147d:
	/* 0x147d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1482:
	/* 0x1482: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1487:
	/* 0x1487: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_148c:
	/* 0x148c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1491:
	/* 0x1491: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1493:
	/* 0x1493: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1498:
	/* 0x1498: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_149a:
	/* 0x149a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_149d:
	/* 0x149d: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_14a3:
	/* 0x14a3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_14a6:
	/* 0x14a6: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_14ac:
	/* 0x14ac: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_14b2:
	/* 0x14b2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14b7:
	/* 0x14b7: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_14bb:
	/* 0x14bb: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_14c2:
	/* 0x14c2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_14c7:
	/* 0x14c7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_14cc:
	/* 0x14cc: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_14d3:
	/* 0x14d3: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_14d6:
	/* 0x14d6: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_14dd:
	/* 0x14dd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14e2:
	/* 0x14e2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_14e7:
	/* 0x14e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14e9:
	/* 0x14e9: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14ed:
	/* 0x14ed: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_14ef:
	/* 0x14ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14f1:
	/* 0x14f1: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_14f7:
	/* 0x14f7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_14fa:
	/* 0x14fa: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1500:
	/* 0x1500: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_1506:
	/* 0x1506: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_150b:
	/* 0x150b: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_150f:
	/* 0x150f: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1516:
	/* 0x1516: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_151b:
	/* 0x151b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1520:
	/* 0x1520: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1525:
	/* 0x1525: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_152d:
	/* 0x152d: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1531:
	/* 0x1531: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1538:
	/* 0x1538: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_153d:
	/* 0x153d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_153f:
	/* 0x153f: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1544:
	/* 0x1544: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_154c:
	/* 0x154c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_154f:
	/* 0x154f: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1557:
	/* 0x1557: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1560:
	/* 0x1560: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1564:
	/* 0x1564: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1569:
	/* 0x1569: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_156e:
	/* 0x156e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1573:
	/* 0x1573: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1578:
	/* 0x1578: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_157a:
	/* 0x157a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_157f:
	/* 0x157f: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_1581:
	/* 0x1581: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1584:
	/* 0x1584: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_158a:
	/* 0x158a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_158d:
	/* 0x158d: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1593:
	/* 0x1593: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_1599:
	/* 0x1599: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_159e:
	/* 0x159e: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_15a2:
	/* 0x15a2: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_15a9:
	/* 0x15a9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_15ae:
	/* 0x15ae: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_15b3:
	/* 0x15b3: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_15ba:
	/* 0x15ba: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_15bd:
	/* 0x15bd: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_15c4:
	/* 0x15c4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15c9:
	/* 0x15c9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_15ce:
	/* 0x15ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d0:
	/* 0x15d0: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_15d4:
	/* 0x15d4: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_15d6:
	/* 0x15d6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15d8:
	/* 0x15d8: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_15de:
	/* 0x15de: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15e1:
	/* 0x15e1: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_15e7:
	/* 0x15e7: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_15ed:
	/* 0x15ed: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15f2:
	/* 0x15f2: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_15f6:
	/* 0x15f6: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_15fd:
	/* 0x15fd: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1602:
	/* 0x1602: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1607:
	/* 0x1607: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_160c:
	/* 0x160c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1614:
	/* 0x1614: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1618:
	/* 0x1618: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_161f:
	/* 0x161f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1624:
	/* 0x1624: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1626:
	/* 0x1626: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_162b:
	/* 0x162b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1633:
	/* 0x1633: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1636:
	/* 0x1636: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_163e:
	/* 0x163e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1647:
	/* 0x1647: lea    rdx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_164b:
	/* 0x164b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1650:
	/* 0x1650: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1655:
	/* 0x1655: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_165a:
	/* 0x165a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_165f:
	/* 0x165f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1661:
	/* 0x1661: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1666:
	/* 0x1666: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_1668:
	/* 0x1668: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_166b:
	/* 0x166b: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_1671:
	/* 0x1671: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1674:
	/* 0x1674: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_167a:
	/* 0x167a: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_1680:
	/* 0x1680: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1685:
	/* 0x1685: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1689:
	/* 0x1689: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1690:
	/* 0x1690: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1695:
	/* 0x1695: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_169a:
	/* 0x169a: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_16a1:
	/* 0x16a1: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16a4:
	/* 0x16a4: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_16ab:
	/* 0x16ab: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16b0:
	/* 0x16b0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_16b5:
	/* 0x16b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16b7:
	/* 0x16b7: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16bb:
	/* 0x16bb: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_16bd:
	/* 0x16bd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16bf:
	/* 0x16bf: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_16c5:
	/* 0x16c5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_16c8:
	/* 0x16c8: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_16ce:
	/* 0x16ce: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_16d4:
	/* 0x16d4: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16d9:
	/* 0x16d9: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_16dd:
	/* 0x16dd: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_16e4:
	/* 0x16e4: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16e9:
	/* 0x16e9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16ee:
	/* 0x16ee: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16f3:
	/* 0x16f3: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_16fb:
	/* 0x16fb: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_16ff:
	/* 0x16ff: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1706:
	/* 0x1706: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_170b:
	/* 0x170b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_170d:
	/* 0x170d: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1712:
	/* 0x1712: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_171a:
	/* 0x171a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_171d:
	/* 0x171d: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1725:
	/* 0x1725: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_172e:
	/* 0x172e: lea    rdx,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1732:
	/* 0x1732: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1737:
	/* 0x1737: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_173c:
	/* 0x173c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1741:
	/* 0x1741: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1746:
	/* 0x1746: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1748:
	/* 0x1748: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_174d:
	/* 0x174d: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_174f:
	/* 0x174f: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1752:
	/* 0x1752: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_1758:
	/* 0x1758: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_175b:
	/* 0x175b: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1761:
	/* 0x1761: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_1767:
	/* 0x1767: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_176c:
	/* 0x176c: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1770:
	/* 0x1770: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1777:
	/* 0x1777: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_177c:
	/* 0x177c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1781:
	/* 0x1781: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1788:
	/* 0x1788: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_178b:
	/* 0x178b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1792:
	/* 0x1792: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1797:
	/* 0x1797: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_179c:
	/* 0x179c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_179e:
	/* 0x179e: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_17a2:
	/* 0x17a2: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_17a4:
	/* 0x17a4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17a6:
	/* 0x17a6: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_17ac:
	/* 0x17ac: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_17af:
	/* 0x17af: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_17b5:
	/* 0x17b5: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_17bb:
	/* 0x17bb: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17c0:
	/* 0x17c0: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_17c4:
	/* 0x17c4: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_17cb:
	/* 0x17cb: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_17d0:
	/* 0x17d0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17d5:
	/* 0x17d5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17da:
	/* 0x17da: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_17e2:
	/* 0x17e2: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_17e6:
	/* 0x17e6: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_17ed:
	/* 0x17ed: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17f2:
	/* 0x17f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f4:
	/* 0x17f4: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_17f9:
	/* 0x17f9: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1801:
	/* 0x1801: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1804:
	/* 0x1804: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_180c:
	/* 0x180c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1815:
	/* 0x1815: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1819:
	/* 0x1819: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_181e:
	/* 0x181e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1823:
	/* 0x1823: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1828:
	/* 0x1828: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_182d:
	/* 0x182d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_182f:
	/* 0x182f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1834:
	/* 0x1834: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_1836:
	/* 0x1836: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1839:
	/* 0x1839: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_183f:
	/* 0x183f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1842:
	/* 0x1842: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1848:
	/* 0x1848: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_184e:
	/* 0x184e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1853:
	/* 0x1853: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1857:
	/* 0x1857: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_185e:
	/* 0x185e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1863:
	/* 0x1863: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1868:
	/* 0x1868: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_186f:
	/* 0x186f: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1872:
	/* 0x1872: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1879:
	/* 0x1879: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_187e:
	/* 0x187e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1883:
	/* 0x1883: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1885:
	/* 0x1885: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1889:
	/* 0x1889: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_188b:
	/* 0x188b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_188d:
	/* 0x188d: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_1893:
	/* 0x1893: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1896:
	/* 0x1896: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_189c:
	/* 0x189c: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_18a2:
	/* 0x18a2: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18a7:
	/* 0x18a7: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_18ab:
	/* 0x18ab: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_18b2:
	/* 0x18b2: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_18b7:
	/* 0x18b7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18bc:
	/* 0x18bc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18c1:
	/* 0x18c1: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_18c9:
	/* 0x18c9: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_18cd:
	/* 0x18cd: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_18d4:
	/* 0x18d4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18d9:
	/* 0x18d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18db:
	/* 0x18db: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_18e0:
	/* 0x18e0: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_18e8:
	/* 0x18e8: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_18eb:
	/* 0x18eb: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_18f3:
	/* 0x18f3: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_18fc:
	/* 0x18fc: lea    rdx,[r13+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1900:
	/* 0x1900: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1905:
	/* 0x1905: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_190a:
	/* 0x190a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_190f:
	/* 0x190f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1914:
	/* 0x1914: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1916:
	/* 0x1916: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_191b:
	/* 0x191b: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_191d:
	/* 0x191d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1920:
	/* 0x1920: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_1926:
	/* 0x1926: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1929:
	/* 0x1929: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_192f:
	/* 0x192f: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_1935:
	/* 0x1935: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_193a:
	/* 0x193a: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_193e:
	/* 0x193e: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1945:
	/* 0x1945: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_194a:
	/* 0x194a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_194f:
	/* 0x194f: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1956:
	/* 0x1956: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1959:
	/* 0x1959: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1960:
	/* 0x1960: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1965:
	/* 0x1965: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_196a:
	/* 0x196a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_196c:
	/* 0x196c: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1970:
	/* 0x1970: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_1972:
	/* 0x1972: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1974:
	/* 0x1974: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_197a:
	/* 0x197a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_197d:
	/* 0x197d: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1983:
	/* 0x1983: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_1989:
	/* 0x1989: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_198e:
	/* 0x198e: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1992:
	/* 0x1992: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1999:
	/* 0x1999: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_199e:
	/* 0x199e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19a3:
	/* 0x19a3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19a8:
	/* 0x19a8: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_19b0:
	/* 0x19b0: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_19b4:
	/* 0x19b4: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_19bb:
	/* 0x19bb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19c0:
	/* 0x19c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19c2:
	/* 0x19c2: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_19c7:
	/* 0x19c7: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_19cf:
	/* 0x19cf: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_19d2:
	/* 0x19d2: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_19da:
	/* 0x19da: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_19e3:
	/* 0x19e3: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_19e7:
	/* 0x19e7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19ec:
	/* 0x19ec: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19f1:
	/* 0x19f1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19f6:
	/* 0x19f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19fb:
	/* 0x19fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19fd:
	/* 0x19fd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a02:
	/* 0x1a02: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_1a04:
	/* 0x1a04: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1a07:
	/* 0x1a07: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_1a0d:
	/* 0x1a0d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a10:
	/* 0x1a10: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1a16:
	/* 0x1a16: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_1a1c:
	/* 0x1a1c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a21:
	/* 0x1a21: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1a25:
	/* 0x1a25: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1a2c:
	/* 0x1a2c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1a31:
	/* 0x1a31: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1a36:
	/* 0x1a36: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1a3d:
	/* 0x1a3d: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a40:
	/* 0x1a40: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1a47:
	/* 0x1a47: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a4c:
	/* 0x1a4c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1a51:
	/* 0x1a51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a53:
	/* 0x1a53: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a57:
	/* 0x1a57: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_1a59:
	/* 0x1a59: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a5b:
	/* 0x1a5b: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_1a61:
	/* 0x1a61: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a64:
	/* 0x1a64: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1a6a:
	/* 0x1a6a: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_1a70:
	/* 0x1a70: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a75:
	/* 0x1a75: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1a79:
	/* 0x1a79: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1a80:
	/* 0x1a80: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a85:
	/* 0x1a85: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a8a:
	/* 0x1a8a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a8f:
	/* 0x1a8f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1a97:
	/* 0x1a97: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1a9b:
	/* 0x1a9b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1aa2:
	/* 0x1aa2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1aa7:
	/* 0x1aa7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aa9:
	/* 0x1aa9: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1aae:
	/* 0x1aae: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1ab6:
	/* 0x1ab6: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1ab9:
	/* 0x1ab9: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1ac1:
	/* 0x1ac1: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1aca:
	/* 0x1aca: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ace:
	/* 0x1ace: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ad3:
	/* 0x1ad3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ad8:
	/* 0x1ad8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1add:
	/* 0x1add: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ae2:
	/* 0x1ae2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ae4:
	/* 0x1ae4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ae9:
	/* 0x1ae9: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_1aeb:
	/* 0x1aeb: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1aee:
	/* 0x1aee: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_1af4:
	/* 0x1af4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1af7:
	/* 0x1af7: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1afd:
	/* 0x1afd: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_1b03:
	/* 0x1b03: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b08:
	/* 0x1b08: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1b0c:
	/* 0x1b0c: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1b13:
	/* 0x1b13: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1b18:
	/* 0x1b18: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1b1d:
	/* 0x1b1d: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1b24:
	/* 0x1b24: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b27:
	/* 0x1b27: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1b2e:
	/* 0x1b2e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b33:
	/* 0x1b33: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1b38:
	/* 0x1b38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b3a:
	/* 0x1b3a: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b3e:
	/* 0x1b3e: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_1b40:
	/* 0x1b40: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b42:
	/* 0x1b42: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
	return 6984ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6984ULL: goto x86_l_1b48;
	case 6987ULL: goto x86_l_1b4b;
	case 6993ULL: goto x86_l_1b51;
	case 6999ULL: goto x86_l_1b57;
	case 7004ULL: goto x86_l_1b5c;
	case 7008ULL: goto x86_l_1b60;
	case 7015ULL: goto x86_l_1b67;
	case 7020ULL: goto x86_l_1b6c;
	case 7025ULL: goto x86_l_1b71;
	case 7030ULL: goto x86_l_1b76;
	case 7038ULL: goto x86_l_1b7e;
	case 7042ULL: goto x86_l_1b82;
	case 7049ULL: goto x86_l_1b89;
	case 7054ULL: goto x86_l_1b8e;
	case 7056ULL: goto x86_l_1b90;
	case 7061ULL: goto x86_l_1b95;
	case 7069ULL: goto x86_l_1b9d;
	case 7072ULL: goto x86_l_1ba0;
	case 7080ULL: goto x86_l_1ba8;
	case 7089ULL: goto x86_l_1bb1;
	case 7093ULL: goto x86_l_1bb5;
	case 7098ULL: goto x86_l_1bba;
	case 7103ULL: goto x86_l_1bbf;
	case 7108ULL: goto x86_l_1bc4;
	case 7113ULL: goto x86_l_1bc9;
	case 7115ULL: goto x86_l_1bcb;
	case 7120ULL: goto x86_l_1bd0;
	case 7122ULL: goto x86_l_1bd2;
	case 7125ULL: goto x86_l_1bd5;
	case 7131ULL: goto x86_l_1bdb;
	case 7134ULL: goto x86_l_1bde;
	case 7140ULL: goto x86_l_1be4;
	case 7146ULL: goto x86_l_1bea;
	case 7151ULL: goto x86_l_1bef;
	case 7155ULL: goto x86_l_1bf3;
	case 7162ULL: goto x86_l_1bfa;
	case 7167ULL: goto x86_l_1bff;
	case 7172ULL: goto x86_l_1c04;
	case 7179ULL: goto x86_l_1c0b;
	case 7182ULL: goto x86_l_1c0e;
	case 7189ULL: goto x86_l_1c15;
	case 7194ULL: goto x86_l_1c1a;
	case 7199ULL: goto x86_l_1c1f;
	case 7201ULL: goto x86_l_1c21;
	case 7205ULL: goto x86_l_1c25;
	case 7207ULL: goto x86_l_1c27;
	case 7209ULL: goto x86_l_1c29;
	case 7215ULL: goto x86_l_1c2f;
	case 7218ULL: goto x86_l_1c32;
	case 7224ULL: goto x86_l_1c38;
	case 7230ULL: goto x86_l_1c3e;
	case 7235ULL: goto x86_l_1c43;
	case 7239ULL: goto x86_l_1c47;
	case 7246ULL: goto x86_l_1c4e;
	case 7251ULL: goto x86_l_1c53;
	case 7256ULL: goto x86_l_1c58;
	case 7261ULL: goto x86_l_1c5d;
	case 7269ULL: goto x86_l_1c65;
	case 7273ULL: goto x86_l_1c69;
	case 7280ULL: goto x86_l_1c70;
	case 7285ULL: goto x86_l_1c75;
	case 7287ULL: goto x86_l_1c77;
	case 7292ULL: goto x86_l_1c7c;
	case 7300ULL: goto x86_l_1c84;
	case 7303ULL: goto x86_l_1c87;
	case 7311ULL: goto x86_l_1c8f;
	case 7320ULL: goto x86_l_1c98;
	case 7324ULL: goto x86_l_1c9c;
	case 7329ULL: goto x86_l_1ca1;
	case 7334ULL: goto x86_l_1ca6;
	case 7339ULL: goto x86_l_1cab;
	case 7344ULL: goto x86_l_1cb0;
	case 7346ULL: goto x86_l_1cb2;
	case 7351ULL: goto x86_l_1cb7;
	case 7353ULL: goto x86_l_1cb9;
	case 7356ULL: goto x86_l_1cbc;
	case 7362ULL: goto x86_l_1cc2;
	case 7365ULL: goto x86_l_1cc5;
	case 7371ULL: goto x86_l_1ccb;
	case 7377ULL: goto x86_l_1cd1;
	case 7382ULL: goto x86_l_1cd6;
	case 7386ULL: goto x86_l_1cda;
	case 7393ULL: goto x86_l_1ce1;
	case 7398ULL: goto x86_l_1ce6;
	case 7403ULL: goto x86_l_1ceb;
	case 7410ULL: goto x86_l_1cf2;
	case 7413ULL: goto x86_l_1cf5;
	case 7420ULL: goto x86_l_1cfc;
	case 7425ULL: goto x86_l_1d01;
	case 7430ULL: goto x86_l_1d06;
	case 7432ULL: goto x86_l_1d08;
	case 7436ULL: goto x86_l_1d0c;
	case 7438ULL: goto x86_l_1d0e;
	case 7440ULL: goto x86_l_1d10;
	case 7446ULL: goto x86_l_1d16;
	case 7449ULL: goto x86_l_1d19;
	case 7455ULL: goto x86_l_1d1f;
	case 7461ULL: goto x86_l_1d25;
	case 7466ULL: goto x86_l_1d2a;
	case 7470ULL: goto x86_l_1d2e;
	case 7477ULL: goto x86_l_1d35;
	case 7482ULL: goto x86_l_1d3a;
	case 7487ULL: goto x86_l_1d3f;
	case 7492ULL: goto x86_l_1d44;
	case 7500ULL: goto x86_l_1d4c;
	case 7504ULL: goto x86_l_1d50;
	case 7511ULL: goto x86_l_1d57;
	case 7516ULL: goto x86_l_1d5c;
	case 7518ULL: goto x86_l_1d5e;
	case 7523ULL: goto x86_l_1d63;
	case 7531ULL: goto x86_l_1d6b;
	case 7534ULL: goto x86_l_1d6e;
	case 7542ULL: goto x86_l_1d76;
	case 7551ULL: goto x86_l_1d7f;
	case 7555ULL: goto x86_l_1d83;
	case 7560ULL: goto x86_l_1d88;
	case 7565ULL: goto x86_l_1d8d;
	case 7570ULL: goto x86_l_1d92;
	case 7575ULL: goto x86_l_1d97;
	case 7577ULL: goto x86_l_1d99;
	case 7582ULL: goto x86_l_1d9e;
	case 7584ULL: goto x86_l_1da0;
	case 7587ULL: goto x86_l_1da3;
	case 7593ULL: goto x86_l_1da9;
	case 7596ULL: goto x86_l_1dac;
	case 7602ULL: goto x86_l_1db2;
	case 7608ULL: goto x86_l_1db8;
	case 7613ULL: goto x86_l_1dbd;
	case 7617ULL: goto x86_l_1dc1;
	case 7624ULL: goto x86_l_1dc8;
	case 7629ULL: goto x86_l_1dcd;
	case 7634ULL: goto x86_l_1dd2;
	case 7641ULL: goto x86_l_1dd9;
	case 7644ULL: goto x86_l_1ddc;
	case 7651ULL: goto x86_l_1de3;
	case 7656ULL: goto x86_l_1de8;
	case 7661ULL: goto x86_l_1ded;
	case 7663ULL: goto x86_l_1def;
	case 7667ULL: goto x86_l_1df3;
	case 7669ULL: goto x86_l_1df5;
	case 7671ULL: goto x86_l_1df7;
	case 7677ULL: goto x86_l_1dfd;
	case 7680ULL: goto x86_l_1e00;
	case 7686ULL: goto x86_l_1e06;
	case 7692ULL: goto x86_l_1e0c;
	case 7697ULL: goto x86_l_1e11;
	case 7701ULL: goto x86_l_1e15;
	case 7708ULL: goto x86_l_1e1c;
	case 7713ULL: goto x86_l_1e21;
	case 7718ULL: goto x86_l_1e26;
	case 7723ULL: goto x86_l_1e2b;
	case 7731ULL: goto x86_l_1e33;
	case 7735ULL: goto x86_l_1e37;
	case 7742ULL: goto x86_l_1e3e;
	case 7747ULL: goto x86_l_1e43;
	case 7749ULL: goto x86_l_1e45;
	case 7754ULL: goto x86_l_1e4a;
	case 7762ULL: goto x86_l_1e52;
	case 7765ULL: goto x86_l_1e55;
	case 7773ULL: goto x86_l_1e5d;
	case 7782ULL: goto x86_l_1e66;
	case 7786ULL: goto x86_l_1e6a;
	case 7791ULL: goto x86_l_1e6f;
	case 7796ULL: goto x86_l_1e74;
	case 7801ULL: goto x86_l_1e79;
	case 7806ULL: goto x86_l_1e7e;
	case 7808ULL: goto x86_l_1e80;
	case 7813ULL: goto x86_l_1e85;
	case 7815ULL: goto x86_l_1e87;
	case 7818ULL: goto x86_l_1e8a;
	case 7824ULL: goto x86_l_1e90;
	case 7827ULL: goto x86_l_1e93;
	case 7833ULL: goto x86_l_1e99;
	case 7839ULL: goto x86_l_1e9f;
	case 7844ULL: goto x86_l_1ea4;
	case 7848ULL: goto x86_l_1ea8;
	case 7855ULL: goto x86_l_1eaf;
	case 7860ULL: goto x86_l_1eb4;
	case 7865ULL: goto x86_l_1eb9;
	case 7872ULL: goto x86_l_1ec0;
	case 7875ULL: goto x86_l_1ec3;
	case 7882ULL: goto x86_l_1eca;
	case 7887ULL: goto x86_l_1ecf;
	case 7892ULL: goto x86_l_1ed4;
	case 7894ULL: goto x86_l_1ed6;
	case 7898ULL: goto x86_l_1eda;
	case 7900ULL: goto x86_l_1edc;
	case 7902ULL: goto x86_l_1ede;
	case 7908ULL: goto x86_l_1ee4;
	case 7911ULL: goto x86_l_1ee7;
	case 7917ULL: goto x86_l_1eed;
	case 7923ULL: goto x86_l_1ef3;
	case 7928ULL: goto x86_l_1ef8;
	case 7932ULL: goto x86_l_1efc;
	case 7939ULL: goto x86_l_1f03;
	case 7944ULL: goto x86_l_1f08;
	case 7949ULL: goto x86_l_1f0d;
	case 7954ULL: goto x86_l_1f12;
	case 7962ULL: goto x86_l_1f1a;
	case 7966ULL: goto x86_l_1f1e;
	case 7973ULL: goto x86_l_1f25;
	case 7978ULL: goto x86_l_1f2a;
	case 7980ULL: goto x86_l_1f2c;
	case 7985ULL: goto x86_l_1f31;
	case 7993ULL: goto x86_l_1f39;
	case 7996ULL: goto x86_l_1f3c;
	case 8004ULL: goto x86_l_1f44;
	case 8013ULL: goto x86_l_1f4d;
	case 8017ULL: goto x86_l_1f51;
	case 8022ULL: goto x86_l_1f56;
	case 8027ULL: goto x86_l_1f5b;
	case 8032ULL: goto x86_l_1f60;
	case 8037ULL: goto x86_l_1f65;
	case 8039ULL: goto x86_l_1f67;
	case 8044ULL: goto x86_l_1f6c;
	case 8046ULL: goto x86_l_1f6e;
	case 8049ULL: goto x86_l_1f71;
	case 8055ULL: goto x86_l_1f77;
	case 8058ULL: goto x86_l_1f7a;
	case 8064ULL: goto x86_l_1f80;
	case 8070ULL: goto x86_l_1f86;
	case 8075ULL: goto x86_l_1f8b;
	case 8079ULL: goto x86_l_1f8f;
	case 8086ULL: goto x86_l_1f96;
	case 8091ULL: goto x86_l_1f9b;
	case 8096ULL: goto x86_l_1fa0;
	case 8103ULL: goto x86_l_1fa7;
	case 8106ULL: goto x86_l_1faa;
	case 8113ULL: goto x86_l_1fb1;
	case 8118ULL: goto x86_l_1fb6;
	case 8123ULL: goto x86_l_1fbb;
	case 8125ULL: goto x86_l_1fbd;
	case 8129ULL: goto x86_l_1fc1;
	case 8131ULL: goto x86_l_1fc3;
	case 8133ULL: goto x86_l_1fc5;
	case 8139ULL: goto x86_l_1fcb;
	case 8142ULL: goto x86_l_1fce;
	case 8148ULL: goto x86_l_1fd4;
	case 8154ULL: goto x86_l_1fda;
	case 8159ULL: goto x86_l_1fdf;
	case 8163ULL: goto x86_l_1fe3;
	case 8170ULL: goto x86_l_1fea;
	case 8175ULL: goto x86_l_1fef;
	case 8180ULL: goto x86_l_1ff4;
	case 8185ULL: goto x86_l_1ff9;
	case 8193ULL: goto x86_l_2001;
	case 8197ULL: goto x86_l_2005;
	case 8204ULL: goto x86_l_200c;
	case 8209ULL: goto x86_l_2011;
	case 8211ULL: goto x86_l_2013;
	case 8216ULL: goto x86_l_2018;
	case 8224ULL: goto x86_l_2020;
	case 8227ULL: goto x86_l_2023;
	case 8235ULL: goto x86_l_202b;
	case 8244ULL: goto x86_l_2034;
	case 8251ULL: goto x86_l_203b;
	case 8256ULL: goto x86_l_2040;
	case 8261ULL: goto x86_l_2045;
	case 8266ULL: goto x86_l_204a;
	case 8271ULL: goto x86_l_204f;
	case 8273ULL: goto x86_l_2051;
	case 8278ULL: goto x86_l_2056;
	case 8280ULL: goto x86_l_2058;
	case 8283ULL: goto x86_l_205b;
	case 8289ULL: goto x86_l_2061;
	case 8292ULL: goto x86_l_2064;
	case 8298ULL: goto x86_l_206a;
	case 8304ULL: goto x86_l_2070;
	case 8309ULL: goto x86_l_2075;
	case 8313ULL: goto x86_l_2079;
	case 8320ULL: goto x86_l_2080;
	case 8325ULL: goto x86_l_2085;
	case 8330ULL: goto x86_l_208a;
	case 8337ULL: goto x86_l_2091;
	case 8340ULL: goto x86_l_2094;
	case 8347ULL: goto x86_l_209b;
	case 8352ULL: goto x86_l_20a0;
	case 8357ULL: goto x86_l_20a5;
	case 8359ULL: goto x86_l_20a7;
	case 8363ULL: goto x86_l_20ab;
	case 8365ULL: goto x86_l_20ad;
	case 8367ULL: goto x86_l_20af;
	case 8373ULL: goto x86_l_20b5;
	case 8376ULL: goto x86_l_20b8;
	case 8382ULL: goto x86_l_20be;
	case 8388ULL: goto x86_l_20c4;
	case 8393ULL: goto x86_l_20c9;
	case 8397ULL: goto x86_l_20cd;
	case 8404ULL: goto x86_l_20d4;
	case 8409ULL: goto x86_l_20d9;
	case 8414ULL: goto x86_l_20de;
	case 8419ULL: goto x86_l_20e3;
	case 8427ULL: goto x86_l_20eb;
	case 8431ULL: goto x86_l_20ef;
	case 8438ULL: goto x86_l_20f6;
	case 8443ULL: goto x86_l_20fb;
	case 8445ULL: goto x86_l_20fd;
	case 8450ULL: goto x86_l_2102;
	case 8458ULL: goto x86_l_210a;
	case 8461ULL: goto x86_l_210d;
	case 8469ULL: goto x86_l_2115;
	case 8478ULL: goto x86_l_211e;
	case 8485ULL: goto x86_l_2125;
	case 8490ULL: goto x86_l_212a;
	case 8495ULL: goto x86_l_212f;
	case 8500ULL: goto x86_l_2134;
	case 8505ULL: goto x86_l_2139;
	case 8507ULL: goto x86_l_213b;
	case 8512ULL: goto x86_l_2140;
	case 8514ULL: goto x86_l_2142;
	case 8517ULL: goto x86_l_2145;
	case 8523ULL: goto x86_l_214b;
	case 8526ULL: goto x86_l_214e;
	case 8532ULL: goto x86_l_2154;
	case 8538ULL: goto x86_l_215a;
	case 8543ULL: goto x86_l_215f;
	case 8547ULL: goto x86_l_2163;
	case 8554ULL: goto x86_l_216a;
	case 8559ULL: goto x86_l_216f;
	case 8564ULL: goto x86_l_2174;
	case 8571ULL: goto x86_l_217b;
	case 8574ULL: goto x86_l_217e;
	case 8581ULL: goto x86_l_2185;
	case 8586ULL: goto x86_l_218a;
	case 8591ULL: goto x86_l_218f;
	case 8593ULL: goto x86_l_2191;
	case 8597ULL: goto x86_l_2195;
	case 8599ULL: goto x86_l_2197;
	case 8601ULL: goto x86_l_2199;
	case 8607ULL: goto x86_l_219f;
	case 8610ULL: goto x86_l_21a2;
	case 8616ULL: goto x86_l_21a8;
	case 8622ULL: goto x86_l_21ae;
	case 8627ULL: goto x86_l_21b3;
	case 8631ULL: goto x86_l_21b7;
	case 8638ULL: goto x86_l_21be;
	case 8643ULL: goto x86_l_21c3;
	case 8648ULL: goto x86_l_21c8;
	case 8653ULL: goto x86_l_21cd;
	case 8661ULL: goto x86_l_21d5;
	case 8665ULL: goto x86_l_21d9;
	case 8672ULL: goto x86_l_21e0;
	case 8677ULL: goto x86_l_21e5;
	case 8679ULL: goto x86_l_21e7;
	case 8684ULL: goto x86_l_21ec;
	case 8692ULL: goto x86_l_21f4;
	case 8695ULL: goto x86_l_21f7;
	case 8703ULL: goto x86_l_21ff;
	case 8712ULL: goto x86_l_2208;
	case 8719ULL: goto x86_l_220f;
	case 8724ULL: goto x86_l_2214;
	case 8729ULL: goto x86_l_2219;
	case 8734ULL: goto x86_l_221e;
	case 8739ULL: goto x86_l_2223;
	case 8741ULL: goto x86_l_2225;
	case 8746ULL: goto x86_l_222a;
	case 8748ULL: goto x86_l_222c;
	case 8751ULL: goto x86_l_222f;
	case 8757ULL: goto x86_l_2235;
	case 8760ULL: goto x86_l_2238;
	case 8766ULL: goto x86_l_223e;
	case 8772ULL: goto x86_l_2244;
	case 8777ULL: goto x86_l_2249;
	case 8781ULL: goto x86_l_224d;
	case 8788ULL: goto x86_l_2254;
	case 8793ULL: goto x86_l_2259;
	case 8798ULL: goto x86_l_225e;
	case 8805ULL: goto x86_l_2265;
	case 8808ULL: goto x86_l_2268;
	case 8815ULL: goto x86_l_226f;
	case 8820ULL: goto x86_l_2274;
	case 8825ULL: goto x86_l_2279;
	case 8827ULL: goto x86_l_227b;
	case 8831ULL: goto x86_l_227f;
	case 8833ULL: goto x86_l_2281;
	case 8835ULL: goto x86_l_2283;
	case 8841ULL: goto x86_l_2289;
	case 8844ULL: goto x86_l_228c;
	case 8850ULL: goto x86_l_2292;
	case 8856ULL: goto x86_l_2298;
	case 8861ULL: goto x86_l_229d;
	case 8865ULL: goto x86_l_22a1;
	case 8872ULL: goto x86_l_22a8;
	case 8877ULL: goto x86_l_22ad;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b48:
	/* 0x1b48: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b4b:
	/* 0x1b4b: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1b51:
	/* 0x1b51: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_1b57:
	/* 0x1b57: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b5c:
	/* 0x1b5c: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1b60:
	/* 0x1b60: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1b67:
	/* 0x1b67: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b6c:
	/* 0x1b6c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b71:
	/* 0x1b71: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b76:
	/* 0x1b76: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1b7e:
	/* 0x1b7e: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1b82:
	/* 0x1b82: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1b89:
	/* 0x1b89: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b8e:
	/* 0x1b8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b90:
	/* 0x1b90: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1b95:
	/* 0x1b95: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1b9d:
	/* 0x1b9d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1ba0:
	/* 0x1ba0: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1ba8:
	/* 0x1ba8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1bb1:
	/* 0x1bb1: lea    rdx,[r13+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1bb5:
	/* 0x1bb5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bba:
	/* 0x1bba: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1bbf:
	/* 0x1bbf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bc4:
	/* 0x1bc4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bc9:
	/* 0x1bc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bcb:
	/* 0x1bcb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bd0:
	/* 0x1bd0: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_1bd2:
	/* 0x1bd2: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1bd5:
	/* 0x1bd5: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_1bdb:
	/* 0x1bdb: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1bde:
	/* 0x1bde: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1be4:
	/* 0x1be4: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_1bea:
	/* 0x1bea: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bef:
	/* 0x1bef: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1bf3:
	/* 0x1bf3: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1bfa:
	/* 0x1bfa: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1bff:
	/* 0x1bff: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1c04:
	/* 0x1c04: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c0b:
	/* 0x1c0b: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c0e:
	/* 0x1c0e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1c15:
	/* 0x1c15: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c1a:
	/* 0x1c1a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1c1f:
	/* 0x1c1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c21:
	/* 0x1c21: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c25:
	/* 0x1c25: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_1c27:
	/* 0x1c27: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c29:
	/* 0x1c29: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_1c2f:
	/* 0x1c2f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1c32:
	/* 0x1c32: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1c38:
	/* 0x1c38: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_1c3e:
	/* 0x1c3e: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c43:
	/* 0x1c43: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1c47:
	/* 0x1c47: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1c4e:
	/* 0x1c4e: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c53:
	/* 0x1c53: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c58:
	/* 0x1c58: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c5d:
	/* 0x1c5d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c65:
	/* 0x1c65: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1c69:
	/* 0x1c69: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1c70:
	/* 0x1c70: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c75:
	/* 0x1c75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c77:
	/* 0x1c77: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1c7c:
	/* 0x1c7c: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1c84:
	/* 0x1c84: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1c87:
	/* 0x1c87: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1c8f:
	/* 0x1c8f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1c98:
	/* 0x1c98: lea    rdx,[r13+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1c9c:
	/* 0x1c9c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ca1:
	/* 0x1ca1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ca6:
	/* 0x1ca6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cab:
	/* 0x1cab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cb0:
	/* 0x1cb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cb2:
	/* 0x1cb2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cb7:
	/* 0x1cb7: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_1cb9:
	/* 0x1cb9: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1cbc:
	/* 0x1cbc: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_1cc2:
	/* 0x1cc2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1cc5:
	/* 0x1cc5: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1ccb:
	/* 0x1ccb: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_1cd1:
	/* 0x1cd1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cd6:
	/* 0x1cd6: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1cda:
	/* 0x1cda: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1ce1:
	/* 0x1ce1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1ce6:
	/* 0x1ce6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1ceb:
	/* 0x1ceb: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1cf2:
	/* 0x1cf2: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1cf5:
	/* 0x1cf5: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1cfc:
	/* 0x1cfc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d01:
	/* 0x1d01: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1d06:
	/* 0x1d06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d08:
	/* 0x1d08: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d0c:
	/* 0x1d0c: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_1d0e:
	/* 0x1d0e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d10:
	/* 0x1d10: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_1d16:
	/* 0x1d16: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d19:
	/* 0x1d19: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1d1f:
	/* 0x1d1f: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_1d25:
	/* 0x1d25: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d2a:
	/* 0x1d2a: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1d2e:
	/* 0x1d2e: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1d35:
	/* 0x1d35: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d3a:
	/* 0x1d3a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d3f:
	/* 0x1d3f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d44:
	/* 0x1d44: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1d4c:
	/* 0x1d4c: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1d50:
	/* 0x1d50: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1d57:
	/* 0x1d57: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d5c:
	/* 0x1d5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d5e:
	/* 0x1d5e: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1d63:
	/* 0x1d63: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1d6b:
	/* 0x1d6b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1d6e:
	/* 0x1d6e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1d76:
	/* 0x1d76: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1d7f:
	/* 0x1d7f: lea    rdx,[r13+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1d83:
	/* 0x1d83: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d88:
	/* 0x1d88: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d8d:
	/* 0x1d8d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d92:
	/* 0x1d92: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d97:
	/* 0x1d97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d99:
	/* 0x1d99: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d9e:
	/* 0x1d9e: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_1da0:
	/* 0x1da0: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1da3:
	/* 0x1da3: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_1da9:
	/* 0x1da9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1dac:
	/* 0x1dac: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1db2:
	/* 0x1db2: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_1db8:
	/* 0x1db8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dbd:
	/* 0x1dbd: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1dc1:
	/* 0x1dc1: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1dc8:
	/* 0x1dc8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1dcd:
	/* 0x1dcd: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1dd2:
	/* 0x1dd2: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1dd9:
	/* 0x1dd9: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ddc:
	/* 0x1ddc: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1de3:
	/* 0x1de3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1de8:
	/* 0x1de8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1ded:
	/* 0x1ded: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1def:
	/* 0x1def: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1df3:
	/* 0x1df3: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_1df5:
	/* 0x1df5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1df7:
	/* 0x1df7: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_1dfd:
	/* 0x1dfd: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e00:
	/* 0x1e00: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1e06:
	/* 0x1e06: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_1e0c:
	/* 0x1e0c: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e11:
	/* 0x1e11: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1e15:
	/* 0x1e15: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1e1c:
	/* 0x1e1c: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e21:
	/* 0x1e21: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e26:
	/* 0x1e26: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e2b:
	/* 0x1e2b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e33:
	/* 0x1e33: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1e37:
	/* 0x1e37: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1e3e:
	/* 0x1e3e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e43:
	/* 0x1e43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e45:
	/* 0x1e45: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1e4a:
	/* 0x1e4a: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1e52:
	/* 0x1e52: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1e55:
	/* 0x1e55: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1e5d:
	/* 0x1e5d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1e66:
	/* 0x1e66: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1e6a:
	/* 0x1e6a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e6f:
	/* 0x1e6f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e74:
	/* 0x1e74: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e79:
	/* 0x1e79: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e7e:
	/* 0x1e7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e80:
	/* 0x1e80: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e85:
	/* 0x1e85: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_1e87:
	/* 0x1e87: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1e8a:
	/* 0x1e8a: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_1e90:
	/* 0x1e90: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e93:
	/* 0x1e93: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1e99:
	/* 0x1e99: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_1e9f:
	/* 0x1e9f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ea4:
	/* 0x1ea4: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1ea8:
	/* 0x1ea8: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1eaf:
	/* 0x1eaf: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1eb4:
	/* 0x1eb4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1eb9:
	/* 0x1eb9: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1ec0:
	/* 0x1ec0: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ec3:
	/* 0x1ec3: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1eca:
	/* 0x1eca: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ecf:
	/* 0x1ecf: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1ed4:
	/* 0x1ed4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ed6:
	/* 0x1ed6: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1eda:
	/* 0x1eda: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_1edc:
	/* 0x1edc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ede:
	/* 0x1ede: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_1ee4:
	/* 0x1ee4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ee7:
	/* 0x1ee7: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1eed:
	/* 0x1eed: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_1ef3:
	/* 0x1ef3: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ef8:
	/* 0x1ef8: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1efc:
	/* 0x1efc: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1f03:
	/* 0x1f03: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f08:
	/* 0x1f08: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f0d:
	/* 0x1f0d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f12:
	/* 0x1f12: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f1a:
	/* 0x1f1a: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1f1e:
	/* 0x1f1e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1f25:
	/* 0x1f25: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f2a:
	/* 0x1f2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f2c:
	/* 0x1f2c: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1f31:
	/* 0x1f31: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1f39:
	/* 0x1f39: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1f3c:
	/* 0x1f3c: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1f44:
	/* 0x1f44: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1f4d:
	/* 0x1f4d: lea    rdx,[r13+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1f51:
	/* 0x1f51: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f56:
	/* 0x1f56: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f5b:
	/* 0x1f5b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f60:
	/* 0x1f60: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f65:
	/* 0x1f65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f67:
	/* 0x1f67: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f6c:
	/* 0x1f6c: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_1f6e:
	/* 0x1f6e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1f71:
	/* 0x1f71: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_1f77:
	/* 0x1f77: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f7a:
	/* 0x1f7a: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1f80:
	/* 0x1f80: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_1f86:
	/* 0x1f86: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f8b:
	/* 0x1f8b: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1f8f:
	/* 0x1f8f: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1f96:
	/* 0x1f96: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1f9b:
	/* 0x1f9b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1fa0:
	/* 0x1fa0: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1fa7:
	/* 0x1fa7: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1faa:
	/* 0x1faa: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1fb1:
	/* 0x1fb1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fb6:
	/* 0x1fb6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1fbb:
	/* 0x1fbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fbd:
	/* 0x1fbd: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1fc1:
	/* 0x1fc1: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_1fc3:
	/* 0x1fc3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fc5:
	/* 0x1fc5: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_1fcb:
	/* 0x1fcb: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1fce:
	/* 0x1fce: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1fd4:
	/* 0x1fd4: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_1fda:
	/* 0x1fda: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fdf:
	/* 0x1fdf: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1fe3:
	/* 0x1fe3: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1fea:
	/* 0x1fea: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1fef:
	/* 0x1fef: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ff4:
	/* 0x1ff4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ff9:
	/* 0x1ff9: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2001:
	/* 0x2001: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2005:
	/* 0x2005: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_200c:
	/* 0x200c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2011:
	/* 0x2011: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2013:
	/* 0x2013: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2018:
	/* 0x2018: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2020:
	/* 0x2020: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2023:
	/* 0x2023: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_202b:
	/* 0x202b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2034:
	/* 0x2034: lea    rdx,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_203b:
	/* 0x203b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2040:
	/* 0x2040: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2045:
	/* 0x2045: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_204a:
	/* 0x204a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_204f:
	/* 0x204f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2051:
	/* 0x2051: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2056:
	/* 0x2056: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_2058:
	/* 0x2058: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_205b:
	/* 0x205b: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_2061:
	/* 0x2061: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2064:
	/* 0x2064: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_206a:
	/* 0x206a: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2070:
	/* 0x2070: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2075:
	/* 0x2075: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2079:
	/* 0x2079: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2080:
	/* 0x2080: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2085:
	/* 0x2085: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_208a:
	/* 0x208a: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2091:
	/* 0x2091: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2094:
	/* 0x2094: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_209b:
	/* 0x209b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20a0:
	/* 0x20a0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_20a5:
	/* 0x20a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20a7:
	/* 0x20a7: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_20ab:
	/* 0x20ab: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_20ad:
	/* 0x20ad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20af:
	/* 0x20af: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_20b5:
	/* 0x20b5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_20b8:
	/* 0x20b8: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_20be:
	/* 0x20be: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_20c4:
	/* 0x20c4: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20c9:
	/* 0x20c9: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_20cd:
	/* 0x20cd: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_20d4:
	/* 0x20d4: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_20d9:
	/* 0x20d9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_20de:
	/* 0x20de: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20e3:
	/* 0x20e3: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_20eb:
	/* 0x20eb: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_20ef:
	/* 0x20ef: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_20f6:
	/* 0x20f6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_20fb:
	/* 0x20fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20fd:
	/* 0x20fd: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2102:
	/* 0x2102: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_210a:
	/* 0x210a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_210d:
	/* 0x210d: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2115:
	/* 0x2115: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_211e:
	/* 0x211e: lea    rdx,[r13+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2125:
	/* 0x2125: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_212a:
	/* 0x212a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_212f:
	/* 0x212f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2134:
	/* 0x2134: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2139:
	/* 0x2139: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_213b:
	/* 0x213b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2140:
	/* 0x2140: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_2142:
	/* 0x2142: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2145:
	/* 0x2145: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_214b:
	/* 0x214b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_214e:
	/* 0x214e: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2154:
	/* 0x2154: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_215a:
	/* 0x215a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_215f:
	/* 0x215f: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2163:
	/* 0x2163: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_216a:
	/* 0x216a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_216f:
	/* 0x216f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2174:
	/* 0x2174: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_217b:
	/* 0x217b: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_217e:
	/* 0x217e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2185:
	/* 0x2185: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_218a:
	/* 0x218a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_218f:
	/* 0x218f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2191:
	/* 0x2191: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2195:
	/* 0x2195: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_2197:
	/* 0x2197: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2199:
	/* 0x2199: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_219f:
	/* 0x219f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_21a2:
	/* 0x21a2: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_21a8:
	/* 0x21a8: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_21ae:
	/* 0x21ae: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21b3:
	/* 0x21b3: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_21b7:
	/* 0x21b7: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_21be:
	/* 0x21be: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_21c3:
	/* 0x21c3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_21c8:
	/* 0x21c8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21cd:
	/* 0x21cd: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_21d5:
	/* 0x21d5: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_21d9:
	/* 0x21d9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_21e0:
	/* 0x21e0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_21e5:
	/* 0x21e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21e7:
	/* 0x21e7: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_21ec:
	/* 0x21ec: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_21f4:
	/* 0x21f4: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_21f7:
	/* 0x21f7: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_21ff:
	/* 0x21ff: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2208:
	/* 0x2208: lea    rdx,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_220f:
	/* 0x220f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2214:
	/* 0x2214: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2219:
	/* 0x2219: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_221e:
	/* 0x221e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2223:
	/* 0x2223: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2225:
	/* 0x2225: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_222a:
	/* 0x222a: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_222c:
	/* 0x222c: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_222f:
	/* 0x222f: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_2235:
	/* 0x2235: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2238:
	/* 0x2238: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_223e:
	/* 0x223e: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2244:
	/* 0x2244: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2249:
	/* 0x2249: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_224d:
	/* 0x224d: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2254:
	/* 0x2254: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2259:
	/* 0x2259: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_225e:
	/* 0x225e: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2265:
	/* 0x2265: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2268:
	/* 0x2268: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_226f:
	/* 0x226f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2274:
	/* 0x2274: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2279:
	/* 0x2279: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_227b:
	/* 0x227b: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_227f:
	/* 0x227f: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_2281:
	/* 0x2281: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2283:
	/* 0x2283: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_2289:
	/* 0x2289: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_228c:
	/* 0x228c: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2292:
	/* 0x2292: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2298:
	/* 0x2298: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_229d:
	/* 0x229d: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_22a1:
	/* 0x22a1: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_22a8:
	/* 0x22a8: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_22ad:
	/* 0x22ad: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
	return 8882ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8882ULL: goto x86_l_22b2;
	case 8887ULL: goto x86_l_22b7;
	case 8895ULL: goto x86_l_22bf;
	case 8899ULL: goto x86_l_22c3;
	case 8906ULL: goto x86_l_22ca;
	case 8911ULL: goto x86_l_22cf;
	case 8913ULL: goto x86_l_22d1;
	case 8918ULL: goto x86_l_22d6;
	case 8926ULL: goto x86_l_22de;
	case 8929ULL: goto x86_l_22e1;
	case 8937ULL: goto x86_l_22e9;
	case 8946ULL: goto x86_l_22f2;
	case 8953ULL: goto x86_l_22f9;
	case 8958ULL: goto x86_l_22fe;
	case 8963ULL: goto x86_l_2303;
	case 8968ULL: goto x86_l_2308;
	case 8973ULL: goto x86_l_230d;
	case 8975ULL: goto x86_l_230f;
	case 8980ULL: goto x86_l_2314;
	case 8982ULL: goto x86_l_2316;
	case 8985ULL: goto x86_l_2319;
	case 8991ULL: goto x86_l_231f;
	case 8994ULL: goto x86_l_2322;
	case 9000ULL: goto x86_l_2328;
	case 9006ULL: goto x86_l_232e;
	case 9011ULL: goto x86_l_2333;
	case 9015ULL: goto x86_l_2337;
	case 9022ULL: goto x86_l_233e;
	case 9027ULL: goto x86_l_2343;
	case 9032ULL: goto x86_l_2348;
	case 9039ULL: goto x86_l_234f;
	case 9042ULL: goto x86_l_2352;
	case 9049ULL: goto x86_l_2359;
	case 9054ULL: goto x86_l_235e;
	case 9059ULL: goto x86_l_2363;
	case 9061ULL: goto x86_l_2365;
	case 9065ULL: goto x86_l_2369;
	case 9067ULL: goto x86_l_236b;
	case 9069ULL: goto x86_l_236d;
	case 9075ULL: goto x86_l_2373;
	case 9078ULL: goto x86_l_2376;
	case 9084ULL: goto x86_l_237c;
	case 9090ULL: goto x86_l_2382;
	case 9095ULL: goto x86_l_2387;
	case 9099ULL: goto x86_l_238b;
	case 9106ULL: goto x86_l_2392;
	case 9111ULL: goto x86_l_2397;
	case 9116ULL: goto x86_l_239c;
	case 9121ULL: goto x86_l_23a1;
	case 9129ULL: goto x86_l_23a9;
	case 9133ULL: goto x86_l_23ad;
	case 9140ULL: goto x86_l_23b4;
	case 9145ULL: goto x86_l_23b9;
	case 9147ULL: goto x86_l_23bb;
	case 9152ULL: goto x86_l_23c0;
	case 9160ULL: goto x86_l_23c8;
	case 9163ULL: goto x86_l_23cb;
	case 9171ULL: goto x86_l_23d3;
	case 9180ULL: goto x86_l_23dc;
	case 9187ULL: goto x86_l_23e3;
	case 9192ULL: goto x86_l_23e8;
	case 9197ULL: goto x86_l_23ed;
	case 9202ULL: goto x86_l_23f2;
	case 9207ULL: goto x86_l_23f7;
	case 9209ULL: goto x86_l_23f9;
	case 9214ULL: goto x86_l_23fe;
	case 9216ULL: goto x86_l_2400;
	case 9219ULL: goto x86_l_2403;
	case 9225ULL: goto x86_l_2409;
	case 9228ULL: goto x86_l_240c;
	case 9234ULL: goto x86_l_2412;
	case 9240ULL: goto x86_l_2418;
	case 9245ULL: goto x86_l_241d;
	case 9249ULL: goto x86_l_2421;
	case 9256ULL: goto x86_l_2428;
	case 9261ULL: goto x86_l_242d;
	case 9266ULL: goto x86_l_2432;
	case 9273ULL: goto x86_l_2439;
	case 9276ULL: goto x86_l_243c;
	case 9283ULL: goto x86_l_2443;
	case 9288ULL: goto x86_l_2448;
	case 9293ULL: goto x86_l_244d;
	case 9295ULL: goto x86_l_244f;
	case 9299ULL: goto x86_l_2453;
	case 9301ULL: goto x86_l_2455;
	case 9303ULL: goto x86_l_2457;
	case 9309ULL: goto x86_l_245d;
	case 9312ULL: goto x86_l_2460;
	case 9318ULL: goto x86_l_2466;
	case 9324ULL: goto x86_l_246c;
	case 9329ULL: goto x86_l_2471;
	case 9333ULL: goto x86_l_2475;
	case 9340ULL: goto x86_l_247c;
	case 9345ULL: goto x86_l_2481;
	case 9350ULL: goto x86_l_2486;
	case 9355ULL: goto x86_l_248b;
	case 9363ULL: goto x86_l_2493;
	case 9367ULL: goto x86_l_2497;
	case 9374ULL: goto x86_l_249e;
	case 9379ULL: goto x86_l_24a3;
	case 9381ULL: goto x86_l_24a5;
	case 9386ULL: goto x86_l_24aa;
	case 9394ULL: goto x86_l_24b2;
	case 9397ULL: goto x86_l_24b5;
	case 9405ULL: goto x86_l_24bd;
	case 9414ULL: goto x86_l_24c6;
	case 9421ULL: goto x86_l_24cd;
	case 9426ULL: goto x86_l_24d2;
	case 9431ULL: goto x86_l_24d7;
	case 9436ULL: goto x86_l_24dc;
	case 9441ULL: goto x86_l_24e1;
	case 9443ULL: goto x86_l_24e3;
	case 9448ULL: goto x86_l_24e8;
	case 9450ULL: goto x86_l_24ea;
	case 9453ULL: goto x86_l_24ed;
	case 9459ULL: goto x86_l_24f3;
	case 9462ULL: goto x86_l_24f6;
	case 9468ULL: goto x86_l_24fc;
	case 9474ULL: goto x86_l_2502;
	case 9479ULL: goto x86_l_2507;
	case 9483ULL: goto x86_l_250b;
	case 9490ULL: goto x86_l_2512;
	case 9495ULL: goto x86_l_2517;
	case 9500ULL: goto x86_l_251c;
	case 9507ULL: goto x86_l_2523;
	case 9510ULL: goto x86_l_2526;
	case 9517ULL: goto x86_l_252d;
	case 9522ULL: goto x86_l_2532;
	case 9527ULL: goto x86_l_2537;
	case 9529ULL: goto x86_l_2539;
	case 9533ULL: goto x86_l_253d;
	case 9535ULL: goto x86_l_253f;
	case 9537ULL: goto x86_l_2541;
	case 9543ULL: goto x86_l_2547;
	case 9546ULL: goto x86_l_254a;
	case 9552ULL: goto x86_l_2550;
	case 9558ULL: goto x86_l_2556;
	case 9563ULL: goto x86_l_255b;
	case 9567ULL: goto x86_l_255f;
	case 9574ULL: goto x86_l_2566;
	case 9579ULL: goto x86_l_256b;
	case 9584ULL: goto x86_l_2570;
	case 9589ULL: goto x86_l_2575;
	case 9597ULL: goto x86_l_257d;
	case 9601ULL: goto x86_l_2581;
	case 9608ULL: goto x86_l_2588;
	case 9613ULL: goto x86_l_258d;
	case 9615ULL: goto x86_l_258f;
	case 9620ULL: goto x86_l_2594;
	case 9628ULL: goto x86_l_259c;
	case 9631ULL: goto x86_l_259f;
	case 9639ULL: goto x86_l_25a7;
	case 9648ULL: goto x86_l_25b0;
	case 9655ULL: goto x86_l_25b7;
	case 9660ULL: goto x86_l_25bc;
	case 9665ULL: goto x86_l_25c1;
	case 9670ULL: goto x86_l_25c6;
	case 9675ULL: goto x86_l_25cb;
	case 9677ULL: goto x86_l_25cd;
	case 9682ULL: goto x86_l_25d2;
	case 9684ULL: goto x86_l_25d4;
	case 9687ULL: goto x86_l_25d7;
	case 9693ULL: goto x86_l_25dd;
	case 9696ULL: goto x86_l_25e0;
	case 9702ULL: goto x86_l_25e6;
	case 9708ULL: goto x86_l_25ec;
	case 9713ULL: goto x86_l_25f1;
	case 9717ULL: goto x86_l_25f5;
	case 9724ULL: goto x86_l_25fc;
	case 9729ULL: goto x86_l_2601;
	case 9734ULL: goto x86_l_2606;
	case 9741ULL: goto x86_l_260d;
	case 9744ULL: goto x86_l_2610;
	case 9751ULL: goto x86_l_2617;
	case 9756ULL: goto x86_l_261c;
	case 9761ULL: goto x86_l_2621;
	case 9763ULL: goto x86_l_2623;
	case 9767ULL: goto x86_l_2627;
	case 9769ULL: goto x86_l_2629;
	case 9771ULL: goto x86_l_262b;
	case 9777ULL: goto x86_l_2631;
	case 9780ULL: goto x86_l_2634;
	case 9786ULL: goto x86_l_263a;
	case 9792ULL: goto x86_l_2640;
	case 9797ULL: goto x86_l_2645;
	case 9801ULL: goto x86_l_2649;
	case 9808ULL: goto x86_l_2650;
	case 9813ULL: goto x86_l_2655;
	case 9818ULL: goto x86_l_265a;
	case 9823ULL: goto x86_l_265f;
	case 9831ULL: goto x86_l_2667;
	case 9835ULL: goto x86_l_266b;
	case 9842ULL: goto x86_l_2672;
	case 9847ULL: goto x86_l_2677;
	case 9849ULL: goto x86_l_2679;
	case 9854ULL: goto x86_l_267e;
	case 9862ULL: goto x86_l_2686;
	case 9865ULL: goto x86_l_2689;
	case 9873ULL: goto x86_l_2691;
	case 9882ULL: goto x86_l_269a;
	case 9889ULL: goto x86_l_26a1;
	case 9894ULL: goto x86_l_26a6;
	case 9899ULL: goto x86_l_26ab;
	case 9904ULL: goto x86_l_26b0;
	case 9909ULL: goto x86_l_26b5;
	case 9911ULL: goto x86_l_26b7;
	case 9916ULL: goto x86_l_26bc;
	case 9918ULL: goto x86_l_26be;
	case 9921ULL: goto x86_l_26c1;
	case 9927ULL: goto x86_l_26c7;
	case 9930ULL: goto x86_l_26ca;
	case 9936ULL: goto x86_l_26d0;
	case 9942ULL: goto x86_l_26d6;
	case 9947ULL: goto x86_l_26db;
	case 9951ULL: goto x86_l_26df;
	case 9958ULL: goto x86_l_26e6;
	case 9963ULL: goto x86_l_26eb;
	case 9968ULL: goto x86_l_26f0;
	case 9975ULL: goto x86_l_26f7;
	case 9978ULL: goto x86_l_26fa;
	case 9985ULL: goto x86_l_2701;
	case 9990ULL: goto x86_l_2706;
	case 9995ULL: goto x86_l_270b;
	case 9997ULL: goto x86_l_270d;
	case 10001ULL: goto x86_l_2711;
	case 10003ULL: goto x86_l_2713;
	case 10005ULL: goto x86_l_2715;
	case 10011ULL: goto x86_l_271b;
	case 10014ULL: goto x86_l_271e;
	case 10020ULL: goto x86_l_2724;
	case 10026ULL: goto x86_l_272a;
	case 10031ULL: goto x86_l_272f;
	case 10035ULL: goto x86_l_2733;
	case 10042ULL: goto x86_l_273a;
	case 10047ULL: goto x86_l_273f;
	case 10052ULL: goto x86_l_2744;
	case 10057ULL: goto x86_l_2749;
	case 10065ULL: goto x86_l_2751;
	case 10069ULL: goto x86_l_2755;
	case 10076ULL: goto x86_l_275c;
	case 10081ULL: goto x86_l_2761;
	case 10083ULL: goto x86_l_2763;
	case 10088ULL: goto x86_l_2768;
	case 10096ULL: goto x86_l_2770;
	case 10099ULL: goto x86_l_2773;
	case 10107ULL: goto x86_l_277b;
	case 10116ULL: goto x86_l_2784;
	case 10123ULL: goto x86_l_278b;
	case 10128ULL: goto x86_l_2790;
	case 10133ULL: goto x86_l_2795;
	case 10138ULL: goto x86_l_279a;
	case 10143ULL: goto x86_l_279f;
	case 10145ULL: goto x86_l_27a1;
	case 10150ULL: goto x86_l_27a6;
	case 10152ULL: goto x86_l_27a8;
	case 10155ULL: goto x86_l_27ab;
	case 10161ULL: goto x86_l_27b1;
	case 10164ULL: goto x86_l_27b4;
	case 10170ULL: goto x86_l_27ba;
	case 10176ULL: goto x86_l_27c0;
	case 10181ULL: goto x86_l_27c5;
	case 10185ULL: goto x86_l_27c9;
	case 10192ULL: goto x86_l_27d0;
	case 10197ULL: goto x86_l_27d5;
	case 10202ULL: goto x86_l_27da;
	case 10209ULL: goto x86_l_27e1;
	case 10212ULL: goto x86_l_27e4;
	case 10219ULL: goto x86_l_27eb;
	case 10224ULL: goto x86_l_27f0;
	case 10229ULL: goto x86_l_27f5;
	case 10231ULL: goto x86_l_27f7;
	case 10235ULL: goto x86_l_27fb;
	case 10237ULL: goto x86_l_27fd;
	case 10239ULL: goto x86_l_27ff;
	case 10245ULL: goto x86_l_2805;
	case 10248ULL: goto x86_l_2808;
	case 10254ULL: goto x86_l_280e;
	case 10260ULL: goto x86_l_2814;
	case 10265ULL: goto x86_l_2819;
	case 10269ULL: goto x86_l_281d;
	case 10276ULL: goto x86_l_2824;
	case 10281ULL: goto x86_l_2829;
	case 10286ULL: goto x86_l_282e;
	case 10291ULL: goto x86_l_2833;
	case 10299ULL: goto x86_l_283b;
	case 10303ULL: goto x86_l_283f;
	case 10310ULL: goto x86_l_2846;
	case 10315ULL: goto x86_l_284b;
	case 10317ULL: goto x86_l_284d;
	case 10322ULL: goto x86_l_2852;
	case 10330ULL: goto x86_l_285a;
	case 10333ULL: goto x86_l_285d;
	case 10341ULL: goto x86_l_2865;
	case 10350ULL: goto x86_l_286e;
	case 10357ULL: goto x86_l_2875;
	case 10362ULL: goto x86_l_287a;
	case 10367ULL: goto x86_l_287f;
	case 10372ULL: goto x86_l_2884;
	case 10377ULL: goto x86_l_2889;
	case 10379ULL: goto x86_l_288b;
	case 10384ULL: goto x86_l_2890;
	case 10386ULL: goto x86_l_2892;
	case 10389ULL: goto x86_l_2895;
	case 10395ULL: goto x86_l_289b;
	case 10398ULL: goto x86_l_289e;
	case 10404ULL: goto x86_l_28a4;
	case 10410ULL: goto x86_l_28aa;
	case 10415ULL: goto x86_l_28af;
	case 10419ULL: goto x86_l_28b3;
	case 10426ULL: goto x86_l_28ba;
	case 10431ULL: goto x86_l_28bf;
	case 10436ULL: goto x86_l_28c4;
	case 10443ULL: goto x86_l_28cb;
	case 10446ULL: goto x86_l_28ce;
	case 10453ULL: goto x86_l_28d5;
	case 10458ULL: goto x86_l_28da;
	case 10463ULL: goto x86_l_28df;
	case 10465ULL: goto x86_l_28e1;
	case 10469ULL: goto x86_l_28e5;
	case 10471ULL: goto x86_l_28e7;
	case 10473ULL: goto x86_l_28e9;
	case 10479ULL: goto x86_l_28ef;
	case 10482ULL: goto x86_l_28f2;
	case 10488ULL: goto x86_l_28f8;
	case 10494ULL: goto x86_l_28fe;
	case 10499ULL: goto x86_l_2903;
	case 10503ULL: goto x86_l_2907;
	case 10510ULL: goto x86_l_290e;
	case 10515ULL: goto x86_l_2913;
	case 10520ULL: goto x86_l_2918;
	case 10525ULL: goto x86_l_291d;
	case 10533ULL: goto x86_l_2925;
	case 10537ULL: goto x86_l_2929;
	case 10544ULL: goto x86_l_2930;
	case 10549ULL: goto x86_l_2935;
	case 10551ULL: goto x86_l_2937;
	case 10556ULL: goto x86_l_293c;
	case 10564ULL: goto x86_l_2944;
	case 10567ULL: goto x86_l_2947;
	case 10575ULL: goto x86_l_294f;
	case 10584ULL: goto x86_l_2958;
	case 10591ULL: goto x86_l_295f;
	case 10596ULL: goto x86_l_2964;
	case 10601ULL: goto x86_l_2969;
	case 10606ULL: goto x86_l_296e;
	case 10611ULL: goto x86_l_2973;
	case 10613ULL: goto x86_l_2975;
	case 10618ULL: goto x86_l_297a;
	case 10620ULL: goto x86_l_297c;
	case 10623ULL: goto x86_l_297f;
	case 10629ULL: goto x86_l_2985;
	case 10632ULL: goto x86_l_2988;
	case 10638ULL: goto x86_l_298e;
	case 10644ULL: goto x86_l_2994;
	case 10649ULL: goto x86_l_2999;
	case 10653ULL: goto x86_l_299d;
	case 10660ULL: goto x86_l_29a4;
	case 10665ULL: goto x86_l_29a9;
	case 10670ULL: goto x86_l_29ae;
	case 10677ULL: goto x86_l_29b5;
	case 10680ULL: goto x86_l_29b8;
	case 10687ULL: goto x86_l_29bf;
	case 10692ULL: goto x86_l_29c4;
	case 10697ULL: goto x86_l_29c9;
	case 10699ULL: goto x86_l_29cb;
	case 10703ULL: goto x86_l_29cf;
	case 10705ULL: goto x86_l_29d1;
	case 10707ULL: goto x86_l_29d3;
	case 10713ULL: goto x86_l_29d9;
	case 10716ULL: goto x86_l_29dc;
	case 10722ULL: goto x86_l_29e2;
	case 10728ULL: goto x86_l_29e8;
	case 10733ULL: goto x86_l_29ed;
	case 10737ULL: goto x86_l_29f1;
	case 10744ULL: goto x86_l_29f8;
	case 10749ULL: goto x86_l_29fd;
	case 10754ULL: goto x86_l_2a02;
	case 10759ULL: goto x86_l_2a07;
	case 10767ULL: goto x86_l_2a0f;
	case 10771ULL: goto x86_l_2a13;
	case 10778ULL: goto x86_l_2a1a;
	case 10783ULL: goto x86_l_2a1f;
	case 10785ULL: goto x86_l_2a21;
	case 10790ULL: goto x86_l_2a26;
	default: return 0xffffffffffffffffULL;
	}
x86_l_22b2:
	/* 0x22b2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22b7:
	/* 0x22b7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_22bf:
	/* 0x22bf: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_22c3:
	/* 0x22c3: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_22ca:
	/* 0x22ca: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_22cf:
	/* 0x22cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22d1:
	/* 0x22d1: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_22d6:
	/* 0x22d6: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_22de:
	/* 0x22de: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_22e1:
	/* 0x22e1: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_22e9:
	/* 0x22e9: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_22f2:
	/* 0x22f2: lea    rdx,[r13+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_22f9:
	/* 0x22f9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22fe:
	/* 0x22fe: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2303:
	/* 0x2303: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2308:
	/* 0x2308: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_230d:
	/* 0x230d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_230f:
	/* 0x230f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2314:
	/* 0x2314: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_2316:
	/* 0x2316: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2319:
	/* 0x2319: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_231f:
	/* 0x231f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2322:
	/* 0x2322: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2328:
	/* 0x2328: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_232e:
	/* 0x232e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2333:
	/* 0x2333: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2337:
	/* 0x2337: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_233e:
	/* 0x233e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2343:
	/* 0x2343: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2348:
	/* 0x2348: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_234f:
	/* 0x234f: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2352:
	/* 0x2352: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2359:
	/* 0x2359: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_235e:
	/* 0x235e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2363:
	/* 0x2363: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2365:
	/* 0x2365: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2369:
	/* 0x2369: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_236b:
	/* 0x236b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_236d:
	/* 0x236d: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_2373:
	/* 0x2373: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2376:
	/* 0x2376: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_237c:
	/* 0x237c: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2382:
	/* 0x2382: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2387:
	/* 0x2387: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_238b:
	/* 0x238b: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2392:
	/* 0x2392: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2397:
	/* 0x2397: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_239c:
	/* 0x239c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23a1:
	/* 0x23a1: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_23a9:
	/* 0x23a9: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_23ad:
	/* 0x23ad: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_23b4:
	/* 0x23b4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_23b9:
	/* 0x23b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23bb:
	/* 0x23bb: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_23c0:
	/* 0x23c0: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_23c8:
	/* 0x23c8: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_23cb:
	/* 0x23cb: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_23d3:
	/* 0x23d3: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_23dc:
	/* 0x23dc: lea    rdx,[r13+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_23e3:
	/* 0x23e3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23e8:
	/* 0x23e8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_23ed:
	/* 0x23ed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23f2:
	/* 0x23f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23f7:
	/* 0x23f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23f9:
	/* 0x23f9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23fe:
	/* 0x23fe: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_2400:
	/* 0x2400: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2403:
	/* 0x2403: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_2409:
	/* 0x2409: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_240c:
	/* 0x240c: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2412:
	/* 0x2412: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2418:
	/* 0x2418: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_241d:
	/* 0x241d: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2421:
	/* 0x2421: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2428:
	/* 0x2428: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_242d:
	/* 0x242d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2432:
	/* 0x2432: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2439:
	/* 0x2439: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_243c:
	/* 0x243c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2443:
	/* 0x2443: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2448:
	/* 0x2448: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_244d:
	/* 0x244d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_244f:
	/* 0x244f: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2453:
	/* 0x2453: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_2455:
	/* 0x2455: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2457:
	/* 0x2457: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_245d:
	/* 0x245d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2460:
	/* 0x2460: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2466:
	/* 0x2466: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_246c:
	/* 0x246c: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2471:
	/* 0x2471: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2475:
	/* 0x2475: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_247c:
	/* 0x247c: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2481:
	/* 0x2481: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2486:
	/* 0x2486: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_248b:
	/* 0x248b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2493:
	/* 0x2493: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2497:
	/* 0x2497: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_249e:
	/* 0x249e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_24a3:
	/* 0x24a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24a5:
	/* 0x24a5: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_24aa:
	/* 0x24aa: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_24b2:
	/* 0x24b2: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_24b5:
	/* 0x24b5: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_24bd:
	/* 0x24bd: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_24c6:
	/* 0x24c6: lea    rdx,[r13+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_24cd:
	/* 0x24cd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24d2:
	/* 0x24d2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_24d7:
	/* 0x24d7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24dc:
	/* 0x24dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24e1:
	/* 0x24e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24e3:
	/* 0x24e3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24e8:
	/* 0x24e8: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_24ea:
	/* 0x24ea: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_24ed:
	/* 0x24ed: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_24f3:
	/* 0x24f3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_24f6:
	/* 0x24f6: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_24fc:
	/* 0x24fc: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2502:
	/* 0x2502: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2507:
	/* 0x2507: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_250b:
	/* 0x250b: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2512:
	/* 0x2512: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2517:
	/* 0x2517: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_251c:
	/* 0x251c: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2523:
	/* 0x2523: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2526:
	/* 0x2526: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_252d:
	/* 0x252d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2532:
	/* 0x2532: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2537:
	/* 0x2537: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2539:
	/* 0x2539: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_253d:
	/* 0x253d: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_253f:
	/* 0x253f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2541:
	/* 0x2541: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_2547:
	/* 0x2547: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_254a:
	/* 0x254a: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2550:
	/* 0x2550: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2556:
	/* 0x2556: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_255b:
	/* 0x255b: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_255f:
	/* 0x255f: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2566:
	/* 0x2566: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_256b:
	/* 0x256b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2570:
	/* 0x2570: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2575:
	/* 0x2575: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_257d:
	/* 0x257d: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2581:
	/* 0x2581: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2588:
	/* 0x2588: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_258d:
	/* 0x258d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_258f:
	/* 0x258f: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2594:
	/* 0x2594: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_259c:
	/* 0x259c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_259f:
	/* 0x259f: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_25a7:
	/* 0x25a7: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_25b0:
	/* 0x25b0: lea    rdx,[r13+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_25b7:
	/* 0x25b7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25bc:
	/* 0x25bc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_25c1:
	/* 0x25c1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25c6:
	/* 0x25c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25cb:
	/* 0x25cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25cd:
	/* 0x25cd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25d2:
	/* 0x25d2: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_25d4:
	/* 0x25d4: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_25d7:
	/* 0x25d7: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_25dd:
	/* 0x25dd: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_25e0:
	/* 0x25e0: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_25e6:
	/* 0x25e6: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_25ec:
	/* 0x25ec: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25f1:
	/* 0x25f1: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_25f5:
	/* 0x25f5: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_25fc:
	/* 0x25fc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2601:
	/* 0x2601: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2606:
	/* 0x2606: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_260d:
	/* 0x260d: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2610:
	/* 0x2610: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2617:
	/* 0x2617: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_261c:
	/* 0x261c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2621:
	/* 0x2621: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2623:
	/* 0x2623: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2627:
	/* 0x2627: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_2629:
	/* 0x2629: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_262b:
	/* 0x262b: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_2631:
	/* 0x2631: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2634:
	/* 0x2634: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_263a:
	/* 0x263a: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2640:
	/* 0x2640: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2645:
	/* 0x2645: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2649:
	/* 0x2649: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2650:
	/* 0x2650: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2655:
	/* 0x2655: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_265a:
	/* 0x265a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_265f:
	/* 0x265f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2667:
	/* 0x2667: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_266b:
	/* 0x266b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2672:
	/* 0x2672: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2677:
	/* 0x2677: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2679:
	/* 0x2679: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_267e:
	/* 0x267e: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2686:
	/* 0x2686: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2689:
	/* 0x2689: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2691:
	/* 0x2691: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_269a:
	/* 0x269a: lea    rdx,[r13+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_26a1:
	/* 0x26a1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26a6:
	/* 0x26a6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_26ab:
	/* 0x26ab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26b0:
	/* 0x26b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26b5:
	/* 0x26b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26b7:
	/* 0x26b7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26bc:
	/* 0x26bc: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_26be:
	/* 0x26be: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_26c1:
	/* 0x26c1: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_26c7:
	/* 0x26c7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_26ca:
	/* 0x26ca: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_26d0:
	/* 0x26d0: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_26d6:
	/* 0x26d6: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26db:
	/* 0x26db: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_26df:
	/* 0x26df: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_26e6:
	/* 0x26e6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_26eb:
	/* 0x26eb: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_26f0:
	/* 0x26f0: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_26f7:
	/* 0x26f7: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26fa:
	/* 0x26fa: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2701:
	/* 0x2701: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2706:
	/* 0x2706: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_270b:
	/* 0x270b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_270d:
	/* 0x270d: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2711:
	/* 0x2711: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_2713:
	/* 0x2713: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2715:
	/* 0x2715: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_271b:
	/* 0x271b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_271e:
	/* 0x271e: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2724:
	/* 0x2724: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_272a:
	/* 0x272a: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_272f:
	/* 0x272f: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2733:
	/* 0x2733: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_273a:
	/* 0x273a: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_273f:
	/* 0x273f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2744:
	/* 0x2744: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2749:
	/* 0x2749: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2751:
	/* 0x2751: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2755:
	/* 0x2755: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_275c:
	/* 0x275c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2761:
	/* 0x2761: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2763:
	/* 0x2763: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2768:
	/* 0x2768: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2770:
	/* 0x2770: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2773:
	/* 0x2773: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_277b:
	/* 0x277b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2784:
	/* 0x2784: lea    rdx,[r13+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_278b:
	/* 0x278b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2790:
	/* 0x2790: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2795:
	/* 0x2795: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_279a:
	/* 0x279a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_279f:
	/* 0x279f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27a1:
	/* 0x27a1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27a6:
	/* 0x27a6: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_27a8:
	/* 0x27a8: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_27ab:
	/* 0x27ab: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_27b1:
	/* 0x27b1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_27b4:
	/* 0x27b4: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_27ba:
	/* 0x27ba: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_27c0:
	/* 0x27c0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27c5:
	/* 0x27c5: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_27c9:
	/* 0x27c9: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_27d0:
	/* 0x27d0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_27d5:
	/* 0x27d5: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_27da:
	/* 0x27da: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_27e1:
	/* 0x27e1: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_27e4:
	/* 0x27e4: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_27eb:
	/* 0x27eb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27f0:
	/* 0x27f0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_27f5:
	/* 0x27f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27f7:
	/* 0x27f7: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_27fb:
	/* 0x27fb: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_27fd:
	/* 0x27fd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27ff:
	/* 0x27ff: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_2805:
	/* 0x2805: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2808:
	/* 0x2808: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_280e:
	/* 0x280e: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2814:
	/* 0x2814: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2819:
	/* 0x2819: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_281d:
	/* 0x281d: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2824:
	/* 0x2824: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2829:
	/* 0x2829: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_282e:
	/* 0x282e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2833:
	/* 0x2833: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_283b:
	/* 0x283b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_283f:
	/* 0x283f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2846:
	/* 0x2846: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_284b:
	/* 0x284b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_284d:
	/* 0x284d: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2852:
	/* 0x2852: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_285a:
	/* 0x285a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_285d:
	/* 0x285d: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2865:
	/* 0x2865: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_286e:
	/* 0x286e: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2875:
	/* 0x2875: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_287a:
	/* 0x287a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_287f:
	/* 0x287f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2884:
	/* 0x2884: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2889:
	/* 0x2889: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_288b:
	/* 0x288b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2890:
	/* 0x2890: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_2892:
	/* 0x2892: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2895:
	/* 0x2895: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_289b:
	/* 0x289b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_289e:
	/* 0x289e: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_28a4:
	/* 0x28a4: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_28aa:
	/* 0x28aa: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28af:
	/* 0x28af: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_28b3:
	/* 0x28b3: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_28ba:
	/* 0x28ba: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_28bf:
	/* 0x28bf: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_28c4:
	/* 0x28c4: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_28cb:
	/* 0x28cb: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28ce:
	/* 0x28ce: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_28d5:
	/* 0x28d5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28da:
	/* 0x28da: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_28df:
	/* 0x28df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28e1:
	/* 0x28e1: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_28e5:
	/* 0x28e5: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_28e7:
	/* 0x28e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28e9:
	/* 0x28e9: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_28ef:
	/* 0x28ef: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_28f2:
	/* 0x28f2: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_28f8:
	/* 0x28f8: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_28fe:
	/* 0x28fe: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2903:
	/* 0x2903: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2907:
	/* 0x2907: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_290e:
	/* 0x290e: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2913:
	/* 0x2913: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2918:
	/* 0x2918: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_291d:
	/* 0x291d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2925:
	/* 0x2925: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2929:
	/* 0x2929: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2930:
	/* 0x2930: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2935:
	/* 0x2935: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2937:
	/* 0x2937: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_293c:
	/* 0x293c: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2944:
	/* 0x2944: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2947:
	/* 0x2947: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_294f:
	/* 0x294f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2958:
	/* 0x2958: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_295f:
	/* 0x295f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2964:
	/* 0x2964: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2969:
	/* 0x2969: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_296e:
	/* 0x296e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2973:
	/* 0x2973: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2975:
	/* 0x2975: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_297a:
	/* 0x297a: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_297c:
	/* 0x297c: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_297f:
	/* 0x297f: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_2985:
	/* 0x2985: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2988:
	/* 0x2988: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_298e:
	/* 0x298e: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2994:
	/* 0x2994: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2999:
	/* 0x2999: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_299d:
	/* 0x299d: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_29a4:
	/* 0x29a4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_29a9:
	/* 0x29a9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_29ae:
	/* 0x29ae: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_29b5:
	/* 0x29b5: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29b8:
	/* 0x29b8: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_29bf:
	/* 0x29bf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29c4:
	/* 0x29c4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_29c9:
	/* 0x29c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29cb:
	/* 0x29cb: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_29cf:
	/* 0x29cf: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_29d1:
	/* 0x29d1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29d3:
	/* 0x29d3: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_29d9:
	/* 0x29d9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_29dc:
	/* 0x29dc: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_29e2:
	/* 0x29e2: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_29e8:
	/* 0x29e8: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29ed:
	/* 0x29ed: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_29f1:
	/* 0x29f1: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_29f8:
	/* 0x29f8: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_29fd:
	/* 0x29fd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a02:
	/* 0x2a02: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a07:
	/* 0x2a07: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a0f:
	/* 0x2a0f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2a13:
	/* 0x2a13: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2a1a:
	/* 0x2a1a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a1f:
	/* 0x2a1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a21:
	/* 0x2a21: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2a26:
	/* 0x2a26: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
	return 10798ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10798ULL: goto x86_l_2a2e;
	case 10801ULL: goto x86_l_2a31;
	case 10809ULL: goto x86_l_2a39;
	case 10818ULL: goto x86_l_2a42;
	case 10825ULL: goto x86_l_2a49;
	case 10830ULL: goto x86_l_2a4e;
	case 10835ULL: goto x86_l_2a53;
	case 10840ULL: goto x86_l_2a58;
	case 10845ULL: goto x86_l_2a5d;
	case 10847ULL: goto x86_l_2a5f;
	case 10852ULL: goto x86_l_2a64;
	case 10854ULL: goto x86_l_2a66;
	case 10857ULL: goto x86_l_2a69;
	case 10863ULL: goto x86_l_2a6f;
	case 10866ULL: goto x86_l_2a72;
	case 10872ULL: goto x86_l_2a78;
	case 10878ULL: goto x86_l_2a7e;
	case 10883ULL: goto x86_l_2a83;
	case 10887ULL: goto x86_l_2a87;
	case 10894ULL: goto x86_l_2a8e;
	case 10899ULL: goto x86_l_2a93;
	case 10904ULL: goto x86_l_2a98;
	case 10911ULL: goto x86_l_2a9f;
	case 10914ULL: goto x86_l_2aa2;
	case 10921ULL: goto x86_l_2aa9;
	case 10926ULL: goto x86_l_2aae;
	case 10931ULL: goto x86_l_2ab3;
	case 10933ULL: goto x86_l_2ab5;
	case 10937ULL: goto x86_l_2ab9;
	case 10939ULL: goto x86_l_2abb;
	case 10941ULL: goto x86_l_2abd;
	case 10947ULL: goto x86_l_2ac3;
	case 10950ULL: goto x86_l_2ac6;
	case 10956ULL: goto x86_l_2acc;
	case 10962ULL: goto x86_l_2ad2;
	case 10967ULL: goto x86_l_2ad7;
	case 10971ULL: goto x86_l_2adb;
	case 10978ULL: goto x86_l_2ae2;
	case 10983ULL: goto x86_l_2ae7;
	case 10988ULL: goto x86_l_2aec;
	case 10993ULL: goto x86_l_2af1;
	case 11001ULL: goto x86_l_2af9;
	case 11005ULL: goto x86_l_2afd;
	case 11012ULL: goto x86_l_2b04;
	case 11017ULL: goto x86_l_2b09;
	case 11019ULL: goto x86_l_2b0b;
	case 11024ULL: goto x86_l_2b10;
	case 11032ULL: goto x86_l_2b18;
	case 11035ULL: goto x86_l_2b1b;
	case 11043ULL: goto x86_l_2b23;
	case 11052ULL: goto x86_l_2b2c;
	case 11059ULL: goto x86_l_2b33;
	case 11064ULL: goto x86_l_2b38;
	case 11069ULL: goto x86_l_2b3d;
	case 11074ULL: goto x86_l_2b42;
	case 11079ULL: goto x86_l_2b47;
	case 11081ULL: goto x86_l_2b49;
	case 11086ULL: goto x86_l_2b4e;
	case 11088ULL: goto x86_l_2b50;
	case 11091ULL: goto x86_l_2b53;
	case 11097ULL: goto x86_l_2b59;
	case 11100ULL: goto x86_l_2b5c;
	case 11106ULL: goto x86_l_2b62;
	case 11112ULL: goto x86_l_2b68;
	case 11117ULL: goto x86_l_2b6d;
	case 11121ULL: goto x86_l_2b71;
	case 11128ULL: goto x86_l_2b78;
	case 11133ULL: goto x86_l_2b7d;
	case 11138ULL: goto x86_l_2b82;
	case 11145ULL: goto x86_l_2b89;
	case 11148ULL: goto x86_l_2b8c;
	case 11155ULL: goto x86_l_2b93;
	case 11160ULL: goto x86_l_2b98;
	case 11165ULL: goto x86_l_2b9d;
	case 11167ULL: goto x86_l_2b9f;
	case 11171ULL: goto x86_l_2ba3;
	case 11173ULL: goto x86_l_2ba5;
	case 11175ULL: goto x86_l_2ba7;
	case 11181ULL: goto x86_l_2bad;
	case 11184ULL: goto x86_l_2bb0;
	case 11190ULL: goto x86_l_2bb6;
	case 11196ULL: goto x86_l_2bbc;
	case 11201ULL: goto x86_l_2bc1;
	case 11205ULL: goto x86_l_2bc5;
	case 11212ULL: goto x86_l_2bcc;
	case 11217ULL: goto x86_l_2bd1;
	case 11222ULL: goto x86_l_2bd6;
	case 11227ULL: goto x86_l_2bdb;
	case 11235ULL: goto x86_l_2be3;
	case 11239ULL: goto x86_l_2be7;
	case 11246ULL: goto x86_l_2bee;
	case 11251ULL: goto x86_l_2bf3;
	case 11253ULL: goto x86_l_2bf5;
	case 11258ULL: goto x86_l_2bfa;
	case 11266ULL: goto x86_l_2c02;
	case 11269ULL: goto x86_l_2c05;
	case 11277ULL: goto x86_l_2c0d;
	case 11286ULL: goto x86_l_2c16;
	case 11293ULL: goto x86_l_2c1d;
	case 11298ULL: goto x86_l_2c22;
	case 11303ULL: goto x86_l_2c27;
	case 11308ULL: goto x86_l_2c2c;
	case 11313ULL: goto x86_l_2c31;
	case 11315ULL: goto x86_l_2c33;
	case 11320ULL: goto x86_l_2c38;
	case 11322ULL: goto x86_l_2c3a;
	case 11325ULL: goto x86_l_2c3d;
	case 11331ULL: goto x86_l_2c43;
	case 11334ULL: goto x86_l_2c46;
	case 11340ULL: goto x86_l_2c4c;
	case 11346ULL: goto x86_l_2c52;
	case 11351ULL: goto x86_l_2c57;
	case 11355ULL: goto x86_l_2c5b;
	case 11362ULL: goto x86_l_2c62;
	case 11367ULL: goto x86_l_2c67;
	case 11372ULL: goto x86_l_2c6c;
	case 11379ULL: goto x86_l_2c73;
	case 11382ULL: goto x86_l_2c76;
	case 11389ULL: goto x86_l_2c7d;
	case 11394ULL: goto x86_l_2c82;
	case 11399ULL: goto x86_l_2c87;
	case 11401ULL: goto x86_l_2c89;
	case 11405ULL: goto x86_l_2c8d;
	case 11407ULL: goto x86_l_2c8f;
	case 11409ULL: goto x86_l_2c91;
	case 11415ULL: goto x86_l_2c97;
	case 11418ULL: goto x86_l_2c9a;
	case 11424ULL: goto x86_l_2ca0;
	case 11430ULL: goto x86_l_2ca6;
	case 11435ULL: goto x86_l_2cab;
	case 11439ULL: goto x86_l_2caf;
	case 11446ULL: goto x86_l_2cb6;
	case 11451ULL: goto x86_l_2cbb;
	case 11456ULL: goto x86_l_2cc0;
	case 11461ULL: goto x86_l_2cc5;
	case 11469ULL: goto x86_l_2ccd;
	case 11473ULL: goto x86_l_2cd1;
	case 11480ULL: goto x86_l_2cd8;
	case 11485ULL: goto x86_l_2cdd;
	case 11487ULL: goto x86_l_2cdf;
	case 11492ULL: goto x86_l_2ce4;
	case 11500ULL: goto x86_l_2cec;
	case 11503ULL: goto x86_l_2cef;
	case 11511ULL: goto x86_l_2cf7;
	case 11520ULL: goto x86_l_2d00;
	case 11527ULL: goto x86_l_2d07;
	case 11532ULL: goto x86_l_2d0c;
	case 11537ULL: goto x86_l_2d11;
	case 11542ULL: goto x86_l_2d16;
	case 11547ULL: goto x86_l_2d1b;
	case 11549ULL: goto x86_l_2d1d;
	case 11554ULL: goto x86_l_2d22;
	case 11556ULL: goto x86_l_2d24;
	case 11559ULL: goto x86_l_2d27;
	case 11565ULL: goto x86_l_2d2d;
	case 11568ULL: goto x86_l_2d30;
	case 11574ULL: goto x86_l_2d36;
	case 11580ULL: goto x86_l_2d3c;
	case 11585ULL: goto x86_l_2d41;
	case 11589ULL: goto x86_l_2d45;
	case 11596ULL: goto x86_l_2d4c;
	case 11601ULL: goto x86_l_2d51;
	case 11606ULL: goto x86_l_2d56;
	case 11613ULL: goto x86_l_2d5d;
	case 11616ULL: goto x86_l_2d60;
	case 11623ULL: goto x86_l_2d67;
	case 11628ULL: goto x86_l_2d6c;
	case 11633ULL: goto x86_l_2d71;
	case 11635ULL: goto x86_l_2d73;
	case 11639ULL: goto x86_l_2d77;
	case 11641ULL: goto x86_l_2d79;
	case 11643ULL: goto x86_l_2d7b;
	case 11649ULL: goto x86_l_2d81;
	case 11652ULL: goto x86_l_2d84;
	case 11658ULL: goto x86_l_2d8a;
	case 11664ULL: goto x86_l_2d90;
	case 11669ULL: goto x86_l_2d95;
	case 11673ULL: goto x86_l_2d99;
	case 11680ULL: goto x86_l_2da0;
	case 11685ULL: goto x86_l_2da5;
	case 11690ULL: goto x86_l_2daa;
	case 11695ULL: goto x86_l_2daf;
	case 11703ULL: goto x86_l_2db7;
	case 11707ULL: goto x86_l_2dbb;
	case 11714ULL: goto x86_l_2dc2;
	case 11719ULL: goto x86_l_2dc7;
	case 11721ULL: goto x86_l_2dc9;
	case 11726ULL: goto x86_l_2dce;
	case 11734ULL: goto x86_l_2dd6;
	case 11737ULL: goto x86_l_2dd9;
	case 11745ULL: goto x86_l_2de1;
	case 11754ULL: goto x86_l_2dea;
	case 11761ULL: goto x86_l_2df1;
	case 11766ULL: goto x86_l_2df6;
	case 11771ULL: goto x86_l_2dfb;
	case 11776ULL: goto x86_l_2e00;
	case 11781ULL: goto x86_l_2e05;
	case 11783ULL: goto x86_l_2e07;
	case 11788ULL: goto x86_l_2e0c;
	case 11790ULL: goto x86_l_2e0e;
	case 11793ULL: goto x86_l_2e11;
	case 11799ULL: goto x86_l_2e17;
	case 11802ULL: goto x86_l_2e1a;
	case 11808ULL: goto x86_l_2e20;
	case 11814ULL: goto x86_l_2e26;
	case 11819ULL: goto x86_l_2e2b;
	case 11823ULL: goto x86_l_2e2f;
	case 11830ULL: goto x86_l_2e36;
	case 11835ULL: goto x86_l_2e3b;
	case 11840ULL: goto x86_l_2e40;
	case 11847ULL: goto x86_l_2e47;
	case 11850ULL: goto x86_l_2e4a;
	case 11857ULL: goto x86_l_2e51;
	case 11862ULL: goto x86_l_2e56;
	case 11867ULL: goto x86_l_2e5b;
	case 11869ULL: goto x86_l_2e5d;
	case 11873ULL: goto x86_l_2e61;
	case 11875ULL: goto x86_l_2e63;
	case 11877ULL: goto x86_l_2e65;
	case 11883ULL: goto x86_l_2e6b;
	case 11886ULL: goto x86_l_2e6e;
	case 11892ULL: goto x86_l_2e74;
	case 11898ULL: goto x86_l_2e7a;
	case 11903ULL: goto x86_l_2e7f;
	case 11907ULL: goto x86_l_2e83;
	case 11914ULL: goto x86_l_2e8a;
	case 11919ULL: goto x86_l_2e8f;
	case 11924ULL: goto x86_l_2e94;
	case 11929ULL: goto x86_l_2e99;
	case 11937ULL: goto x86_l_2ea1;
	case 11941ULL: goto x86_l_2ea5;
	case 11948ULL: goto x86_l_2eac;
	case 11953ULL: goto x86_l_2eb1;
	case 11955ULL: goto x86_l_2eb3;
	case 11960ULL: goto x86_l_2eb8;
	case 11968ULL: goto x86_l_2ec0;
	case 11971ULL: goto x86_l_2ec3;
	case 11979ULL: goto x86_l_2ecb;
	case 11988ULL: goto x86_l_2ed4;
	case 11995ULL: goto x86_l_2edb;
	case 12000ULL: goto x86_l_2ee0;
	case 12005ULL: goto x86_l_2ee5;
	case 12010ULL: goto x86_l_2eea;
	case 12015ULL: goto x86_l_2eef;
	case 12017ULL: goto x86_l_2ef1;
	case 12022ULL: goto x86_l_2ef6;
	case 12024ULL: goto x86_l_2ef8;
	case 12027ULL: goto x86_l_2efb;
	case 12033ULL: goto x86_l_2f01;
	case 12036ULL: goto x86_l_2f04;
	case 12042ULL: goto x86_l_2f0a;
	case 12048ULL: goto x86_l_2f10;
	case 12053ULL: goto x86_l_2f15;
	case 12057ULL: goto x86_l_2f19;
	case 12064ULL: goto x86_l_2f20;
	case 12069ULL: goto x86_l_2f25;
	case 12074ULL: goto x86_l_2f2a;
	case 12081ULL: goto x86_l_2f31;
	case 12084ULL: goto x86_l_2f34;
	case 12091ULL: goto x86_l_2f3b;
	case 12096ULL: goto x86_l_2f40;
	case 12101ULL: goto x86_l_2f45;
	case 12103ULL: goto x86_l_2f47;
	case 12107ULL: goto x86_l_2f4b;
	case 12109ULL: goto x86_l_2f4d;
	case 12111ULL: goto x86_l_2f4f;
	case 12117ULL: goto x86_l_2f55;
	case 12120ULL: goto x86_l_2f58;
	case 12126ULL: goto x86_l_2f5e;
	case 12132ULL: goto x86_l_2f64;
	case 12137ULL: goto x86_l_2f69;
	case 12141ULL: goto x86_l_2f6d;
	case 12148ULL: goto x86_l_2f74;
	case 12153ULL: goto x86_l_2f79;
	case 12158ULL: goto x86_l_2f7e;
	case 12163ULL: goto x86_l_2f83;
	case 12171ULL: goto x86_l_2f8b;
	case 12175ULL: goto x86_l_2f8f;
	case 12182ULL: goto x86_l_2f96;
	case 12187ULL: goto x86_l_2f9b;
	case 12189ULL: goto x86_l_2f9d;
	case 12194ULL: goto x86_l_2fa2;
	case 12202ULL: goto x86_l_2faa;
	case 12205ULL: goto x86_l_2fad;
	case 12213ULL: goto x86_l_2fb5;
	case 12222ULL: goto x86_l_2fbe;
	case 12229ULL: goto x86_l_2fc5;
	case 12234ULL: goto x86_l_2fca;
	case 12239ULL: goto x86_l_2fcf;
	case 12244ULL: goto x86_l_2fd4;
	case 12249ULL: goto x86_l_2fd9;
	case 12251ULL: goto x86_l_2fdb;
	case 12256ULL: goto x86_l_2fe0;
	case 12258ULL: goto x86_l_2fe2;
	case 12261ULL: goto x86_l_2fe5;
	case 12267ULL: goto x86_l_2feb;
	case 12270ULL: goto x86_l_2fee;
	case 12276ULL: goto x86_l_2ff4;
	case 12282ULL: goto x86_l_2ffa;
	case 12287ULL: goto x86_l_2fff;
	case 12291ULL: goto x86_l_3003;
	case 12298ULL: goto x86_l_300a;
	case 12303ULL: goto x86_l_300f;
	case 12308ULL: goto x86_l_3014;
	case 12315ULL: goto x86_l_301b;
	case 12318ULL: goto x86_l_301e;
	case 12325ULL: goto x86_l_3025;
	case 12330ULL: goto x86_l_302a;
	case 12335ULL: goto x86_l_302f;
	case 12337ULL: goto x86_l_3031;
	case 12341ULL: goto x86_l_3035;
	case 12343ULL: goto x86_l_3037;
	case 12345ULL: goto x86_l_3039;
	case 12351ULL: goto x86_l_303f;
	case 12354ULL: goto x86_l_3042;
	case 12360ULL: goto x86_l_3048;
	case 12366ULL: goto x86_l_304e;
	case 12371ULL: goto x86_l_3053;
	case 12375ULL: goto x86_l_3057;
	case 12382ULL: goto x86_l_305e;
	case 12387ULL: goto x86_l_3063;
	case 12392ULL: goto x86_l_3068;
	case 12397ULL: goto x86_l_306d;
	case 12405ULL: goto x86_l_3075;
	case 12409ULL: goto x86_l_3079;
	case 12416ULL: goto x86_l_3080;
	case 12421ULL: goto x86_l_3085;
	case 12423ULL: goto x86_l_3087;
	case 12428ULL: goto x86_l_308c;
	case 12436ULL: goto x86_l_3094;
	case 12439ULL: goto x86_l_3097;
	case 12447ULL: goto x86_l_309f;
	case 12456ULL: goto x86_l_30a8;
	case 12463ULL: goto x86_l_30af;
	case 12468ULL: goto x86_l_30b4;
	case 12473ULL: goto x86_l_30b9;
	case 12478ULL: goto x86_l_30be;
	case 12483ULL: goto x86_l_30c3;
	case 12485ULL: goto x86_l_30c5;
	case 12490ULL: goto x86_l_30ca;
	case 12492ULL: goto x86_l_30cc;
	case 12495ULL: goto x86_l_30cf;
	case 12501ULL: goto x86_l_30d5;
	case 12504ULL: goto x86_l_30d8;
	case 12510ULL: goto x86_l_30de;
	case 12516ULL: goto x86_l_30e4;
	case 12521ULL: goto x86_l_30e9;
	case 12525ULL: goto x86_l_30ed;
	case 12532ULL: goto x86_l_30f4;
	case 12537ULL: goto x86_l_30f9;
	case 12542ULL: goto x86_l_30fe;
	case 12549ULL: goto x86_l_3105;
	case 12552ULL: goto x86_l_3108;
	case 12559ULL: goto x86_l_310f;
	case 12564ULL: goto x86_l_3114;
	case 12569ULL: goto x86_l_3119;
	case 12571ULL: goto x86_l_311b;
	case 12575ULL: goto x86_l_311f;
	case 12577ULL: goto x86_l_3121;
	case 12579ULL: goto x86_l_3123;
	case 12585ULL: goto x86_l_3129;
	case 12588ULL: goto x86_l_312c;
	case 12594ULL: goto x86_l_3132;
	case 12600ULL: goto x86_l_3138;
	case 12605ULL: goto x86_l_313d;
	case 12609ULL: goto x86_l_3141;
	case 12616ULL: goto x86_l_3148;
	case 12621ULL: goto x86_l_314d;
	case 12626ULL: goto x86_l_3152;
	case 12631ULL: goto x86_l_3157;
	case 12639ULL: goto x86_l_315f;
	case 12643ULL: goto x86_l_3163;
	case 12650ULL: goto x86_l_316a;
	case 12655ULL: goto x86_l_316f;
	case 12657ULL: goto x86_l_3171;
	case 12662ULL: goto x86_l_3176;
	case 12670ULL: goto x86_l_317e;
	case 12673ULL: goto x86_l_3181;
	case 12681ULL: goto x86_l_3189;
	case 12690ULL: goto x86_l_3192;
	case 12697ULL: goto x86_l_3199;
	case 12702ULL: goto x86_l_319e;
	case 12707ULL: goto x86_l_31a3;
	case 12712ULL: goto x86_l_31a8;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a2e:
	/* 0x2a2e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2a31:
	/* 0x2a31: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2a39:
	/* 0x2a39: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2a42:
	/* 0x2a42: lea    rdx,[r13+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2a49:
	/* 0x2a49: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a4e:
	/* 0x2a4e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a53:
	/* 0x2a53: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a58:
	/* 0x2a58: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a5d:
	/* 0x2a5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a5f:
	/* 0x2a5f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a64:
	/* 0x2a64: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_2a66:
	/* 0x2a66: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2a69:
	/* 0x2a69: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_2a6f:
	/* 0x2a6f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a72:
	/* 0x2a72: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2a78:
	/* 0x2a78: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2a7e:
	/* 0x2a7e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a83:
	/* 0x2a83: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2a87:
	/* 0x2a87: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2a8e:
	/* 0x2a8e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2a93:
	/* 0x2a93: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2a98:
	/* 0x2a98: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a9f:
	/* 0x2a9f: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2aa2:
	/* 0x2aa2: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2aa9:
	/* 0x2aa9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2aae:
	/* 0x2aae: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2ab3:
	/* 0x2ab3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ab5:
	/* 0x2ab5: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2ab9:
	/* 0x2ab9: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_2abb:
	/* 0x2abb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2abd:
	/* 0x2abd: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_2ac3:
	/* 0x2ac3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ac6:
	/* 0x2ac6: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2acc:
	/* 0x2acc: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2ad2:
	/* 0x2ad2: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ad7:
	/* 0x2ad7: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2adb:
	/* 0x2adb: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2ae2:
	/* 0x2ae2: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2ae7:
	/* 0x2ae7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2aec:
	/* 0x2aec: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2af1:
	/* 0x2af1: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2af9:
	/* 0x2af9: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2afd:
	/* 0x2afd: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2b04:
	/* 0x2b04: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b09:
	/* 0x2b09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b0b:
	/* 0x2b0b: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2b10:
	/* 0x2b10: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2b18:
	/* 0x2b18: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2b1b:
	/* 0x2b1b: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2b23:
	/* 0x2b23: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2b2c:
	/* 0x2b2c: lea    rdx,[r13+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2b33:
	/* 0x2b33: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b38:
	/* 0x2b38: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b3d:
	/* 0x2b3d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b42:
	/* 0x2b42: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b47:
	/* 0x2b47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b49:
	/* 0x2b49: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b4e:
	/* 0x2b4e: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_2b50:
	/* 0x2b50: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2b53:
	/* 0x2b53: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_2b59:
	/* 0x2b59: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b5c:
	/* 0x2b5c: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2b62:
	/* 0x2b62: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2b68:
	/* 0x2b68: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b6d:
	/* 0x2b6d: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2b71:
	/* 0x2b71: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2b78:
	/* 0x2b78: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2b7d:
	/* 0x2b7d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2b82:
	/* 0x2b82: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2b89:
	/* 0x2b89: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b8c:
	/* 0x2b8c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2b93:
	/* 0x2b93: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b98:
	/* 0x2b98: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2b9d:
	/* 0x2b9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b9f:
	/* 0x2b9f: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2ba3:
	/* 0x2ba3: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_2ba5:
	/* 0x2ba5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ba7:
	/* 0x2ba7: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_2bad:
	/* 0x2bad: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2bb0:
	/* 0x2bb0: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2bb6:
	/* 0x2bb6: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2bbc:
	/* 0x2bbc: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bc1:
	/* 0x2bc1: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2bc5:
	/* 0x2bc5: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2bcc:
	/* 0x2bcc: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2bd1:
	/* 0x2bd1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2bd6:
	/* 0x2bd6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bdb:
	/* 0x2bdb: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2be3:
	/* 0x2be3: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2be7:
	/* 0x2be7: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2bee:
	/* 0x2bee: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2bf3:
	/* 0x2bf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf5:
	/* 0x2bf5: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2bfa:
	/* 0x2bfa: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2c02:
	/* 0x2c02: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2c05:
	/* 0x2c05: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2c0d:
	/* 0x2c0d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2c16:
	/* 0x2c16: lea    rdx,[r13+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2c1d:
	/* 0x2c1d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c22:
	/* 0x2c22: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c27:
	/* 0x2c27: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c2c:
	/* 0x2c2c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c31:
	/* 0x2c31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c33:
	/* 0x2c33: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c38:
	/* 0x2c38: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_2c3a:
	/* 0x2c3a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2c3d:
	/* 0x2c3d: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_2c43:
	/* 0x2c43: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c46:
	/* 0x2c46: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2c4c:
	/* 0x2c4c: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2c52:
	/* 0x2c52: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c57:
	/* 0x2c57: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2c5b:
	/* 0x2c5b: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2c62:
	/* 0x2c62: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2c67:
	/* 0x2c67: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2c6c:
	/* 0x2c6c: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2c73:
	/* 0x2c73: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c76:
	/* 0x2c76: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2c7d:
	/* 0x2c7d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c82:
	/* 0x2c82: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2c87:
	/* 0x2c87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c89:
	/* 0x2c89: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c8d:
	/* 0x2c8d: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_2c8f:
	/* 0x2c8f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c91:
	/* 0x2c91: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_2c97:
	/* 0x2c97: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c9a:
	/* 0x2c9a: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2ca0:
	/* 0x2ca0: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2ca6:
	/* 0x2ca6: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cab:
	/* 0x2cab: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2caf:
	/* 0x2caf: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2cb6:
	/* 0x2cb6: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2cbb:
	/* 0x2cbb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2cc0:
	/* 0x2cc0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cc5:
	/* 0x2cc5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2ccd:
	/* 0x2ccd: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2cd1:
	/* 0x2cd1: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2cd8:
	/* 0x2cd8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2cdd:
	/* 0x2cdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cdf:
	/* 0x2cdf: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2ce4:
	/* 0x2ce4: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2cec:
	/* 0x2cec: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2cef:
	/* 0x2cef: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2cf7:
	/* 0x2cf7: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2d00:
	/* 0x2d00: lea    rdx,[r13+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2d07:
	/* 0x2d07: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d0c:
	/* 0x2d0c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d11:
	/* 0x2d11: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d16:
	/* 0x2d16: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d1b:
	/* 0x2d1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d1d:
	/* 0x2d1d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d22:
	/* 0x2d22: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_2d24:
	/* 0x2d24: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2d27:
	/* 0x2d27: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_2d2d:
	/* 0x2d2d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d30:
	/* 0x2d30: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2d36:
	/* 0x2d36: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2d3c:
	/* 0x2d3c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d41:
	/* 0x2d41: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2d45:
	/* 0x2d45: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2d4c:
	/* 0x2d4c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2d51:
	/* 0x2d51: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2d56:
	/* 0x2d56: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2d5d:
	/* 0x2d5d: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d60:
	/* 0x2d60: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2d67:
	/* 0x2d67: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d6c:
	/* 0x2d6c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2d71:
	/* 0x2d71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d73:
	/* 0x2d73: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2d77:
	/* 0x2d77: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_2d79:
	/* 0x2d79: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d7b:
	/* 0x2d7b: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_2d81:
	/* 0x2d81: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d84:
	/* 0x2d84: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2d8a:
	/* 0x2d8a: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2d90:
	/* 0x2d90: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d95:
	/* 0x2d95: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2d99:
	/* 0x2d99: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2da0:
	/* 0x2da0: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2da5:
	/* 0x2da5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2daa:
	/* 0x2daa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2daf:
	/* 0x2daf: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2db7:
	/* 0x2db7: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2dbb:
	/* 0x2dbb: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2dc2:
	/* 0x2dc2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2dc7:
	/* 0x2dc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dc9:
	/* 0x2dc9: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2dce:
	/* 0x2dce: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2dd6:
	/* 0x2dd6: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2dd9:
	/* 0x2dd9: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2de1:
	/* 0x2de1: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2dea:
	/* 0x2dea: lea    rdx,[r13+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2df1:
	/* 0x2df1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2df6:
	/* 0x2df6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2dfb:
	/* 0x2dfb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e00:
	/* 0x2e00: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e05:
	/* 0x2e05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e07:
	/* 0x2e07: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e0c:
	/* 0x2e0c: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_2e0e:
	/* 0x2e0e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2e11:
	/* 0x2e11: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_2e17:
	/* 0x2e17: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e1a:
	/* 0x2e1a: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2e20:
	/* 0x2e20: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2e26:
	/* 0x2e26: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e2b:
	/* 0x2e2b: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2e2f:
	/* 0x2e2f: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2e36:
	/* 0x2e36: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2e3b:
	/* 0x2e3b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2e40:
	/* 0x2e40: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2e47:
	/* 0x2e47: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e4a:
	/* 0x2e4a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2e51:
	/* 0x2e51: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e56:
	/* 0x2e56: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2e5b:
	/* 0x2e5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e5d:
	/* 0x2e5d: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2e61:
	/* 0x2e61: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_2e63:
	/* 0x2e63: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e65:
	/* 0x2e65: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_2e6b:
	/* 0x2e6b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e6e:
	/* 0x2e6e: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2e74:
	/* 0x2e74: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2e7a:
	/* 0x2e7a: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e7f:
	/* 0x2e7f: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2e83:
	/* 0x2e83: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2e8a:
	/* 0x2e8a: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2e8f:
	/* 0x2e8f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e94:
	/* 0x2e94: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e99:
	/* 0x2e99: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2ea1:
	/* 0x2ea1: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2ea5:
	/* 0x2ea5: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2eac:
	/* 0x2eac: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2eb1:
	/* 0x2eb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eb3:
	/* 0x2eb3: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2eb8:
	/* 0x2eb8: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2ec0:
	/* 0x2ec0: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2ec3:
	/* 0x2ec3: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2ecb:
	/* 0x2ecb: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2ed4:
	/* 0x2ed4: lea    rdx,[r13+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2edb:
	/* 0x2edb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ee0:
	/* 0x2ee0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ee5:
	/* 0x2ee5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2eea:
	/* 0x2eea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2eef:
	/* 0x2eef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ef1:
	/* 0x2ef1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ef6:
	/* 0x2ef6: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_2ef8:
	/* 0x2ef8: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2efb:
	/* 0x2efb: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_2f01:
	/* 0x2f01: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f04:
	/* 0x2f04: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2f0a:
	/* 0x2f0a: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2f10:
	/* 0x2f10: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f15:
	/* 0x2f15: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2f19:
	/* 0x2f19: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2f20:
	/* 0x2f20: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2f25:
	/* 0x2f25: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2f2a:
	/* 0x2f2a: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2f31:
	/* 0x2f31: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f34:
	/* 0x2f34: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2f3b:
	/* 0x2f3b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f40:
	/* 0x2f40: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2f45:
	/* 0x2f45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f47:
	/* 0x2f47: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2f4b:
	/* 0x2f4b: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_2f4d:
	/* 0x2f4d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f4f:
	/* 0x2f4f: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_2f55:
	/* 0x2f55: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f58:
	/* 0x2f58: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2f5e:
	/* 0x2f5e: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2f64:
	/* 0x2f64: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f69:
	/* 0x2f69: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2f6d:
	/* 0x2f6d: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2f74:
	/* 0x2f74: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2f79:
	/* 0x2f79: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2f7e:
	/* 0x2f7e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f83:
	/* 0x2f83: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2f8b:
	/* 0x2f8b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2f8f:
	/* 0x2f8f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2f96:
	/* 0x2f96: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2f9b:
	/* 0x2f9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f9d:
	/* 0x2f9d: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2fa2:
	/* 0x2fa2: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2faa:
	/* 0x2faa: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2fad:
	/* 0x2fad: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2fb5:
	/* 0x2fb5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2fbe:
	/* 0x2fbe: lea    rdx,[r13+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2fc5:
	/* 0x2fc5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fca:
	/* 0x2fca: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2fcf:
	/* 0x2fcf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2fd4:
	/* 0x2fd4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fd9:
	/* 0x2fd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fdb:
	/* 0x2fdb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fe0:
	/* 0x2fe0: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_2fe2:
	/* 0x2fe2: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2fe5:
	/* 0x2fe5: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_2feb:
	/* 0x2feb: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2fee:
	/* 0x2fee: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2ff4:
	/* 0x2ff4: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_2ffa:
	/* 0x2ffa: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fff:
	/* 0x2fff: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3003:
	/* 0x3003: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_300a:
	/* 0x300a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_300f:
	/* 0x300f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3014:
	/* 0x3014: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_301b:
	/* 0x301b: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_301e:
	/* 0x301e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3025:
	/* 0x3025: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_302a:
	/* 0x302a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_302f:
	/* 0x302f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3031:
	/* 0x3031: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3035:
	/* 0x3035: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_3037:
	/* 0x3037: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3039:
	/* 0x3039: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_303f:
	/* 0x303f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3042:
	/* 0x3042: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3048:
	/* 0x3048: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_304e:
	/* 0x304e: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3053:
	/* 0x3053: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3057:
	/* 0x3057: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_305e:
	/* 0x305e: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3063:
	/* 0x3063: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3068:
	/* 0x3068: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_306d:
	/* 0x306d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3075:
	/* 0x3075: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3079:
	/* 0x3079: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3080:
	/* 0x3080: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3085:
	/* 0x3085: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3087:
	/* 0x3087: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_308c:
	/* 0x308c: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3094:
	/* 0x3094: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3097:
	/* 0x3097: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_309f:
	/* 0x309f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_30a8:
	/* 0x30a8: lea    rdx,[r13+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_30af:
	/* 0x30af: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30b4:
	/* 0x30b4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_30b9:
	/* 0x30b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30be:
	/* 0x30be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30c3:
	/* 0x30c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30c5:
	/* 0x30c5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30ca:
	/* 0x30ca: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_30cc:
	/* 0x30cc: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_30cf:
	/* 0x30cf: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_30d5:
	/* 0x30d5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_30d8:
	/* 0x30d8: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_30de:
	/* 0x30de: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_30e4:
	/* 0x30e4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30e9:
	/* 0x30e9: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_30ed:
	/* 0x30ed: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_30f4:
	/* 0x30f4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_30f9:
	/* 0x30f9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_30fe:
	/* 0x30fe: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3105:
	/* 0x3105: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3108:
	/* 0x3108: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_310f:
	/* 0x310f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3114:
	/* 0x3114: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3119:
	/* 0x3119: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_311b:
	/* 0x311b: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_311f:
	/* 0x311f: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_3121:
	/* 0x3121: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3123:
	/* 0x3123: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_3129:
	/* 0x3129: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_312c:
	/* 0x312c: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3132:
	/* 0x3132: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_3138:
	/* 0x3138: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_313d:
	/* 0x313d: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3141:
	/* 0x3141: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3148:
	/* 0x3148: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_314d:
	/* 0x314d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3152:
	/* 0x3152: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3157:
	/* 0x3157: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_315f:
	/* 0x315f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3163:
	/* 0x3163: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_316a:
	/* 0x316a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_316f:
	/* 0x316f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3171:
	/* 0x3171: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3176:
	/* 0x3176: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_317e:
	/* 0x317e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3181:
	/* 0x3181: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3189:
	/* 0x3189: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3192:
	/* 0x3192: lea    rdx,[r13+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_3199:
	/* 0x3199: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_319e:
	/* 0x319e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31a3:
	/* 0x31a3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31a8:
	/* 0x31a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 12717ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12717ULL: goto x86_l_31ad;
	case 12719ULL: goto x86_l_31af;
	case 12724ULL: goto x86_l_31b4;
	case 12726ULL: goto x86_l_31b6;
	case 12729ULL: goto x86_l_31b9;
	case 12735ULL: goto x86_l_31bf;
	case 12738ULL: goto x86_l_31c2;
	case 12744ULL: goto x86_l_31c8;
	case 12750ULL: goto x86_l_31ce;
	case 12755ULL: goto x86_l_31d3;
	case 12759ULL: goto x86_l_31d7;
	case 12766ULL: goto x86_l_31de;
	case 12771ULL: goto x86_l_31e3;
	case 12776ULL: goto x86_l_31e8;
	case 12783ULL: goto x86_l_31ef;
	case 12786ULL: goto x86_l_31f2;
	case 12793ULL: goto x86_l_31f9;
	case 12798ULL: goto x86_l_31fe;
	case 12803ULL: goto x86_l_3203;
	case 12805ULL: goto x86_l_3205;
	case 12809ULL: goto x86_l_3209;
	case 12811ULL: goto x86_l_320b;
	case 12813ULL: goto x86_l_320d;
	case 12819ULL: goto x86_l_3213;
	case 12822ULL: goto x86_l_3216;
	case 12828ULL: goto x86_l_321c;
	case 12834ULL: goto x86_l_3222;
	case 12839ULL: goto x86_l_3227;
	case 12843ULL: goto x86_l_322b;
	case 12850ULL: goto x86_l_3232;
	case 12855ULL: goto x86_l_3237;
	case 12860ULL: goto x86_l_323c;
	case 12865ULL: goto x86_l_3241;
	case 12873ULL: goto x86_l_3249;
	case 12877ULL: goto x86_l_324d;
	case 12884ULL: goto x86_l_3254;
	case 12889ULL: goto x86_l_3259;
	case 12891ULL: goto x86_l_325b;
	case 12896ULL: goto x86_l_3260;
	case 12904ULL: goto x86_l_3268;
	case 12907ULL: goto x86_l_326b;
	case 12915ULL: goto x86_l_3273;
	case 12924ULL: goto x86_l_327c;
	case 12931ULL: goto x86_l_3283;
	case 12936ULL: goto x86_l_3288;
	case 12941ULL: goto x86_l_328d;
	case 12946ULL: goto x86_l_3292;
	case 12951ULL: goto x86_l_3297;
	case 12953ULL: goto x86_l_3299;
	case 12958ULL: goto x86_l_329e;
	case 12960ULL: goto x86_l_32a0;
	case 12963ULL: goto x86_l_32a3;
	case 12969ULL: goto x86_l_32a9;
	case 12972ULL: goto x86_l_32ac;
	case 12978ULL: goto x86_l_32b2;
	case 12984ULL: goto x86_l_32b8;
	case 12989ULL: goto x86_l_32bd;
	case 12993ULL: goto x86_l_32c1;
	case 13000ULL: goto x86_l_32c8;
	case 13005ULL: goto x86_l_32cd;
	case 13010ULL: goto x86_l_32d2;
	case 13017ULL: goto x86_l_32d9;
	case 13020ULL: goto x86_l_32dc;
	case 13027ULL: goto x86_l_32e3;
	case 13032ULL: goto x86_l_32e8;
	case 13037ULL: goto x86_l_32ed;
	case 13039ULL: goto x86_l_32ef;
	case 13043ULL: goto x86_l_32f3;
	case 13045ULL: goto x86_l_32f5;
	case 13047ULL: goto x86_l_32f7;
	case 13053ULL: goto x86_l_32fd;
	case 13056ULL: goto x86_l_3300;
	case 13062ULL: goto x86_l_3306;
	case 13068ULL: goto x86_l_330c;
	case 13073ULL: goto x86_l_3311;
	case 13077ULL: goto x86_l_3315;
	case 13084ULL: goto x86_l_331c;
	case 13089ULL: goto x86_l_3321;
	case 13094ULL: goto x86_l_3326;
	case 13099ULL: goto x86_l_332b;
	case 13107ULL: goto x86_l_3333;
	case 13111ULL: goto x86_l_3337;
	case 13118ULL: goto x86_l_333e;
	case 13123ULL: goto x86_l_3343;
	case 13125ULL: goto x86_l_3345;
	case 13130ULL: goto x86_l_334a;
	case 13138ULL: goto x86_l_3352;
	case 13141ULL: goto x86_l_3355;
	case 13149ULL: goto x86_l_335d;
	case 13158ULL: goto x86_l_3366;
	case 13165ULL: goto x86_l_336d;
	case 13170ULL: goto x86_l_3372;
	case 13175ULL: goto x86_l_3377;
	case 13180ULL: goto x86_l_337c;
	case 13185ULL: goto x86_l_3381;
	case 13188ULL: goto x86_l_3384;
	case 13190ULL: goto x86_l_3386;
	case 13195ULL: goto x86_l_338b;
	case 13197ULL: goto x86_l_338d;
	case 13200ULL: goto x86_l_3390;
	case 13206ULL: goto x86_l_3396;
	case 13209ULL: goto x86_l_3399;
	case 13215ULL: goto x86_l_339f;
	case 13221ULL: goto x86_l_33a5;
	case 13226ULL: goto x86_l_33aa;
	case 13230ULL: goto x86_l_33ae;
	case 13237ULL: goto x86_l_33b5;
	case 13242ULL: goto x86_l_33ba;
	case 13247ULL: goto x86_l_33bf;
	case 13254ULL: goto x86_l_33c6;
	case 13257ULL: goto x86_l_33c9;
	case 13264ULL: goto x86_l_33d0;
	case 13269ULL: goto x86_l_33d5;
	case 13274ULL: goto x86_l_33da;
	case 13276ULL: goto x86_l_33dc;
	case 13280ULL: goto x86_l_33e0;
	case 13282ULL: goto x86_l_33e2;
	case 13284ULL: goto x86_l_33e4;
	case 13290ULL: goto x86_l_33ea;
	case 13293ULL: goto x86_l_33ed;
	case 13299ULL: goto x86_l_33f3;
	case 13305ULL: goto x86_l_33f9;
	case 13310ULL: goto x86_l_33fe;
	case 13314ULL: goto x86_l_3402;
	case 13321ULL: goto x86_l_3409;
	case 13326ULL: goto x86_l_340e;
	case 13331ULL: goto x86_l_3413;
	case 13336ULL: goto x86_l_3418;
	case 13344ULL: goto x86_l_3420;
	case 13348ULL: goto x86_l_3424;
	case 13355ULL: goto x86_l_342b;
	case 13360ULL: goto x86_l_3430;
	case 13362ULL: goto x86_l_3432;
	case 13367ULL: goto x86_l_3437;
	case 13375ULL: goto x86_l_343f;
	case 13378ULL: goto x86_l_3442;
	case 13386ULL: goto x86_l_344a;
	case 13394ULL: goto x86_l_3452;
	case 13397ULL: goto x86_l_3455;
	case 13403ULL: goto x86_l_345b;
	case 13405ULL: goto x86_l_345d;
	case 13410ULL: goto x86_l_3462;
	case 13414ULL: goto x86_l_3466;
	case 13417ULL: goto x86_l_3469;
	case 13422ULL: goto x86_l_346e;
	case 13426ULL: goto x86_l_3472;
	case 13433ULL: goto x86_l_3479;
	case 13438ULL: goto x86_l_347e;
	case 13443ULL: goto x86_l_3483;
	case 13448ULL: goto x86_l_3488;
	case 13455ULL: goto x86_l_348f;
	case 13458ULL: goto x86_l_3492;
	case 13465ULL: goto x86_l_3499;
	case 13470ULL: goto x86_l_349e;
	case 13472ULL: goto x86_l_34a0;
	case 13476ULL: goto x86_l_34a4;
	case 13478ULL: goto x86_l_34a6;
	case 13480ULL: goto x86_l_34a8;
	case 13486ULL: goto x86_l_34ae;
	case 13489ULL: goto x86_l_34b1;
	case 13495ULL: goto x86_l_34b7;
	case 13500ULL: goto x86_l_34bc;
	case 13506ULL: goto x86_l_34c2;
	case 13511ULL: goto x86_l_34c7;
	case 13515ULL: goto x86_l_34cb;
	case 13522ULL: goto x86_l_34d2;
	case 13527ULL: goto x86_l_34d7;
	case 13532ULL: goto x86_l_34dc;
	case 13537ULL: goto x86_l_34e1;
	case 13545ULL: goto x86_l_34e9;
	case 13549ULL: goto x86_l_34ed;
	case 13556ULL: goto x86_l_34f4;
	case 13561ULL: goto x86_l_34f9;
	case 13563ULL: goto x86_l_34fb;
	case 13568ULL: goto x86_l_3500;
	case 13576ULL: goto x86_l_3508;
	case 13579ULL: goto x86_l_350b;
	case 13587ULL: goto x86_l_3513;
	case 13589ULL: goto x86_l_3515;
	case 13594ULL: goto x86_l_351a;
	case 13598ULL: goto x86_l_351e;
	case 13605ULL: goto x86_l_3525;
	case 13610ULL: goto x86_l_352a;
	case 13615ULL: goto x86_l_352f;
	case 13620ULL: goto x86_l_3534;
	case 13627ULL: goto x86_l_353b;
	case 13631ULL: goto x86_l_353f;
	case 13638ULL: goto x86_l_3546;
	case 13643ULL: goto x86_l_354b;
	case 13645ULL: goto x86_l_354d;
	case 13650ULL: goto x86_l_3552;
	case 13657ULL: goto x86_l_3559;
	case 13660ULL: goto x86_l_355c;
	case 13667ULL: goto x86_l_3563;
	case 13676ULL: goto x86_l_356c;
	case 13680ULL: goto x86_l_3570;
	case 13685ULL: goto x86_l_3575;
	case 13690ULL: goto x86_l_357a;
	case 13695ULL: goto x86_l_357f;
	case 13700ULL: goto x86_l_3584;
	case 13702ULL: goto x86_l_3586;
	case 13707ULL: goto x86_l_358b;
	case 13709ULL: goto x86_l_358d;
	case 13712ULL: goto x86_l_3590;
	case 13718ULL: goto x86_l_3596;
	case 13721ULL: goto x86_l_3599;
	case 13727ULL: goto x86_l_359f;
	case 13733ULL: goto x86_l_35a5;
	case 13738ULL: goto x86_l_35aa;
	case 13742ULL: goto x86_l_35ae;
	case 13749ULL: goto x86_l_35b5;
	case 13754ULL: goto x86_l_35ba;
	case 13759ULL: goto x86_l_35bf;
	case 13766ULL: goto x86_l_35c6;
	case 13769ULL: goto x86_l_35c9;
	case 13776ULL: goto x86_l_35d0;
	case 13781ULL: goto x86_l_35d5;
	case 13786ULL: goto x86_l_35da;
	case 13788ULL: goto x86_l_35dc;
	case 13792ULL: goto x86_l_35e0;
	case 13794ULL: goto x86_l_35e2;
	case 13796ULL: goto x86_l_35e4;
	case 13802ULL: goto x86_l_35ea;
	case 13805ULL: goto x86_l_35ed;
	case 13811ULL: goto x86_l_35f3;
	case 13817ULL: goto x86_l_35f9;
	case 13822ULL: goto x86_l_35fe;
	case 13826ULL: goto x86_l_3602;
	case 13833ULL: goto x86_l_3609;
	case 13838ULL: goto x86_l_360e;
	case 13843ULL: goto x86_l_3613;
	case 13848ULL: goto x86_l_3618;
	case 13856ULL: goto x86_l_3620;
	case 13860ULL: goto x86_l_3624;
	case 13867ULL: goto x86_l_362b;
	case 13872ULL: goto x86_l_3630;
	case 13874ULL: goto x86_l_3632;
	case 13879ULL: goto x86_l_3637;
	case 13887ULL: goto x86_l_363f;
	case 13890ULL: goto x86_l_3642;
	case 13898ULL: goto x86_l_364a;
	case 13907ULL: goto x86_l_3653;
	case 13911ULL: goto x86_l_3657;
	case 13916ULL: goto x86_l_365c;
	case 13921ULL: goto x86_l_3661;
	case 13926ULL: goto x86_l_3666;
	case 13931ULL: goto x86_l_366b;
	case 13933ULL: goto x86_l_366d;
	case 13938ULL: goto x86_l_3672;
	case 13940ULL: goto x86_l_3674;
	case 13943ULL: goto x86_l_3677;
	case 13949ULL: goto x86_l_367d;
	case 13952ULL: goto x86_l_3680;
	case 13958ULL: goto x86_l_3686;
	case 13964ULL: goto x86_l_368c;
	case 13969ULL: goto x86_l_3691;
	case 13973ULL: goto x86_l_3695;
	case 13980ULL: goto x86_l_369c;
	case 13985ULL: goto x86_l_36a1;
	case 13990ULL: goto x86_l_36a6;
	case 13997ULL: goto x86_l_36ad;
	case 14000ULL: goto x86_l_36b0;
	case 14007ULL: goto x86_l_36b7;
	case 14012ULL: goto x86_l_36bc;
	case 14017ULL: goto x86_l_36c1;
	case 14019ULL: goto x86_l_36c3;
	case 14023ULL: goto x86_l_36c7;
	case 14025ULL: goto x86_l_36c9;
	case 14027ULL: goto x86_l_36cb;
	case 14033ULL: goto x86_l_36d1;
	case 14036ULL: goto x86_l_36d4;
	case 14042ULL: goto x86_l_36da;
	case 14048ULL: goto x86_l_36e0;
	case 14053ULL: goto x86_l_36e5;
	case 14057ULL: goto x86_l_36e9;
	case 14064ULL: goto x86_l_36f0;
	case 14069ULL: goto x86_l_36f5;
	case 14074ULL: goto x86_l_36fa;
	case 14079ULL: goto x86_l_36ff;
	case 14087ULL: goto x86_l_3707;
	case 14091ULL: goto x86_l_370b;
	case 14098ULL: goto x86_l_3712;
	case 14103ULL: goto x86_l_3717;
	case 14105ULL: goto x86_l_3719;
	case 14110ULL: goto x86_l_371e;
	case 14118ULL: goto x86_l_3726;
	case 14121ULL: goto x86_l_3729;
	case 14129ULL: goto x86_l_3731;
	case 14138ULL: goto x86_l_373a;
	case 14142ULL: goto x86_l_373e;
	case 14147ULL: goto x86_l_3743;
	case 14152ULL: goto x86_l_3748;
	case 14157ULL: goto x86_l_374d;
	case 14162ULL: goto x86_l_3752;
	case 14164ULL: goto x86_l_3754;
	case 14169ULL: goto x86_l_3759;
	case 14171ULL: goto x86_l_375b;
	case 14174ULL: goto x86_l_375e;
	case 14180ULL: goto x86_l_3764;
	case 14183ULL: goto x86_l_3767;
	case 14189ULL: goto x86_l_376d;
	case 14195ULL: goto x86_l_3773;
	case 14200ULL: goto x86_l_3778;
	case 14204ULL: goto x86_l_377c;
	case 14211ULL: goto x86_l_3783;
	case 14216ULL: goto x86_l_3788;
	case 14221ULL: goto x86_l_378d;
	case 14228ULL: goto x86_l_3794;
	case 14231ULL: goto x86_l_3797;
	case 14238ULL: goto x86_l_379e;
	case 14243ULL: goto x86_l_37a3;
	case 14248ULL: goto x86_l_37a8;
	case 14250ULL: goto x86_l_37aa;
	case 14254ULL: goto x86_l_37ae;
	case 14256ULL: goto x86_l_37b0;
	case 14258ULL: goto x86_l_37b2;
	case 14264ULL: goto x86_l_37b8;
	case 14267ULL: goto x86_l_37bb;
	case 14273ULL: goto x86_l_37c1;
	case 14279ULL: goto x86_l_37c7;
	case 14284ULL: goto x86_l_37cc;
	case 14288ULL: goto x86_l_37d0;
	case 14295ULL: goto x86_l_37d7;
	case 14300ULL: goto x86_l_37dc;
	case 14305ULL: goto x86_l_37e1;
	case 14310ULL: goto x86_l_37e6;
	case 14318ULL: goto x86_l_37ee;
	case 14322ULL: goto x86_l_37f2;
	case 14329ULL: goto x86_l_37f9;
	case 14334ULL: goto x86_l_37fe;
	case 14336ULL: goto x86_l_3800;
	case 14341ULL: goto x86_l_3805;
	case 14349ULL: goto x86_l_380d;
	case 14352ULL: goto x86_l_3810;
	case 14360ULL: goto x86_l_3818;
	case 14369ULL: goto x86_l_3821;
	case 14373ULL: goto x86_l_3825;
	case 14378ULL: goto x86_l_382a;
	case 14383ULL: goto x86_l_382f;
	case 14388ULL: goto x86_l_3834;
	case 14393ULL: goto x86_l_3839;
	case 14395ULL: goto x86_l_383b;
	case 14400ULL: goto x86_l_3840;
	case 14402ULL: goto x86_l_3842;
	case 14405ULL: goto x86_l_3845;
	case 14411ULL: goto x86_l_384b;
	case 14414ULL: goto x86_l_384e;
	case 14420ULL: goto x86_l_3854;
	case 14426ULL: goto x86_l_385a;
	case 14431ULL: goto x86_l_385f;
	case 14435ULL: goto x86_l_3863;
	case 14442ULL: goto x86_l_386a;
	case 14447ULL: goto x86_l_386f;
	case 14452ULL: goto x86_l_3874;
	case 14459ULL: goto x86_l_387b;
	case 14462ULL: goto x86_l_387e;
	case 14469ULL: goto x86_l_3885;
	case 14474ULL: goto x86_l_388a;
	case 14479ULL: goto x86_l_388f;
	case 14481ULL: goto x86_l_3891;
	case 14485ULL: goto x86_l_3895;
	case 14487ULL: goto x86_l_3897;
	case 14489ULL: goto x86_l_3899;
	case 14495ULL: goto x86_l_389f;
	case 14498ULL: goto x86_l_38a2;
	case 14504ULL: goto x86_l_38a8;
	case 14510ULL: goto x86_l_38ae;
	case 14515ULL: goto x86_l_38b3;
	case 14519ULL: goto x86_l_38b7;
	case 14526ULL: goto x86_l_38be;
	case 14531ULL: goto x86_l_38c3;
	case 14536ULL: goto x86_l_38c8;
	case 14541ULL: goto x86_l_38cd;
	case 14549ULL: goto x86_l_38d5;
	case 14553ULL: goto x86_l_38d9;
	case 14560ULL: goto x86_l_38e0;
	case 14565ULL: goto x86_l_38e5;
	case 14567ULL: goto x86_l_38e7;
	case 14572ULL: goto x86_l_38ec;
	case 14580ULL: goto x86_l_38f4;
	case 14583ULL: goto x86_l_38f7;
	case 14591ULL: goto x86_l_38ff;
	case 14600ULL: goto x86_l_3908;
	case 14604ULL: goto x86_l_390c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_31ad:
	/* 0x31ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31af:
	/* 0x31af: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31b4:
	/* 0x31b4: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_31b6:
	/* 0x31b6: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_31b9:
	/* 0x31b9: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_31bf:
	/* 0x31bf: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_31c2:
	/* 0x31c2: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_31c8:
	/* 0x31c8: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_31ce:
	/* 0x31ce: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31d3:
	/* 0x31d3: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_31d7:
	/* 0x31d7: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_31de:
	/* 0x31de: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_31e3:
	/* 0x31e3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_31e8:
	/* 0x31e8: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_31ef:
	/* 0x31ef: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_31f2:
	/* 0x31f2: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_31f9:
	/* 0x31f9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31fe:
	/* 0x31fe: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3203:
	/* 0x3203: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3205:
	/* 0x3205: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3209:
	/* 0x3209: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_320b:
	/* 0x320b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_320d:
	/* 0x320d: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_3213:
	/* 0x3213: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3216:
	/* 0x3216: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_321c:
	/* 0x321c: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_3222:
	/* 0x3222: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3227:
	/* 0x3227: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_322b:
	/* 0x322b: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3232:
	/* 0x3232: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3237:
	/* 0x3237: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_323c:
	/* 0x323c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3241:
	/* 0x3241: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3249:
	/* 0x3249: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_324d:
	/* 0x324d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3254:
	/* 0x3254: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3259:
	/* 0x3259: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_325b:
	/* 0x325b: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3260:
	/* 0x3260: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3268:
	/* 0x3268: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_326b:
	/* 0x326b: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3273:
	/* 0x3273: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_327c:
	/* 0x327c: lea    rdx,[r13+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_3283:
	/* 0x3283: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3288:
	/* 0x3288: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_328d:
	/* 0x328d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3292:
	/* 0x3292: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3297:
	/* 0x3297: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3299:
	/* 0x3299: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_329e:
	/* 0x329e: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_32a0:
	/* 0x32a0: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_32a3:
	/* 0x32a3: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_32a9:
	/* 0x32a9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_32ac:
	/* 0x32ac: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_32b2:
	/* 0x32b2: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_32b8:
	/* 0x32b8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32bd:
	/* 0x32bd: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_32c1:
	/* 0x32c1: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_32c8:
	/* 0x32c8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_32cd:
	/* 0x32cd: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_32d2:
	/* 0x32d2: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_32d9:
	/* 0x32d9: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_32dc:
	/* 0x32dc: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_32e3:
	/* 0x32e3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32e8:
	/* 0x32e8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_32ed:
	/* 0x32ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32ef:
	/* 0x32ef: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_32f3:
	/* 0x32f3: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_32f5:
	/* 0x32f5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32f7:
	/* 0x32f7: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_32fd:
	/* 0x32fd: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3300:
	/* 0x3300: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3306:
	/* 0x3306: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_330c:
	/* 0x330c: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3311:
	/* 0x3311: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3315:
	/* 0x3315: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_331c:
	/* 0x331c: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3321:
	/* 0x3321: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3326:
	/* 0x3326: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_332b:
	/* 0x332b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3333:
	/* 0x3333: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3337:
	/* 0x3337: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_333e:
	/* 0x333e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3343:
	/* 0x3343: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3345:
	/* 0x3345: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_334a:
	/* 0x334a: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3352:
	/* 0x3352: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3355:
	/* 0x3355: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_335d:
	/* 0x335d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3366:
	/* 0x3366: add    r13,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_336d:
	/* 0x336d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3372:
	/* 0x3372: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3377:
	/* 0x3377: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_337c:
	/* 0x337c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3381:
	/* 0x3381: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3384:
	/* 0x3384: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3386:
	/* 0x3386: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_338b:
	/* 0x338b: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_338d:
	/* 0x338d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3390:
	/* 0x3390: je     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3257ULL;
	}
x86_l_3396:
	/* 0x3396: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3399:
	/* 0x3399: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_339f:
	/* 0x339f: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_33a5:
	/* 0x33a5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33aa:
	/* 0x33aa: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_33ae:
	/* 0x33ae: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_33b5:
	/* 0x33b5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_33ba:
	/* 0x33ba: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_33bf:
	/* 0x33bf: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_33c6:
	/* 0x33c6: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_33c9:
	/* 0x33c9: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_33d0:
	/* 0x33d0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33d5:
	/* 0x33d5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_33da:
	/* 0x33da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33dc:
	/* 0x33dc: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_33e0:
	/* 0x33e0: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_33e2:
	/* 0x33e2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33e4:
	/* 0x33e4: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_33ea:
	/* 0x33ea: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_33ed:
	/* 0x33ed: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_33f3:
	/* 0x33f3: ja     cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3257ULL;
	}
x86_l_33f9:
	/* 0x33f9: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33fe:
	/* 0x33fe: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3402:
	/* 0x3402: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3409:
	/* 0x3409: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_340e:
	/* 0x340e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3413:
	/* 0x3413: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3418:
	/* 0x3418: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3420:
	/* 0x3420: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3424:
	/* 0x3424: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_342b:
	/* 0x342b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3430:
	/* 0x3430: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3432:
	/* 0x3432: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3437:
	/* 0x3437: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_343f:
	/* 0x343f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3442:
	/* 0x3442: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_344a:
	/* 0x344a: mov    DWORD PTR [rsp+0x10],0x2e2e2e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68722503214ULL);
x86_l_3452:
	/* 0x3452: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3455:
	/* 0x3455: cmp    ecx,0x6cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27901ULL);
x86_l_345b:
	/* 0x345b: jb     3466 <syscall__execveat_enter+0x3466> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3466;
	}
x86_l_345d:
	/* 0x345d: mov    WORD PTR [rbx],0x6cfc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27900ULL);
x86_l_3462:
	/* 0x3462: mov    ax,0x6cfc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 27900ULL);
x86_l_3466:
	/* 0x3466: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3469:
	/* 0x3469: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_346e:
	/* 0x346e: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3472:
	/* 0x3472: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3479:
	/* 0x3479: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_347e:
	/* 0x347e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3483:
	/* 0x3483: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3488:
	/* 0x3488: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_348f:
	/* 0x348f: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3492:
	/* 0x3492: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3499:
	/* 0x3499: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_349e:
	/* 0x349e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34a0:
	/* 0x34a0: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_34a4:
	/* 0x34a4: mov    cl,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 38ULL);
x86_l_34a6:
	/* 0x34a6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34a8:
	/* 0x34a8: jle    cb9 <syscall__execveat_enter+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3257ULL;
	}
x86_l_34ae:
	/* 0x34ae: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_34b1:
	/* 0x34b1: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_34b7:
	/* 0x34b7: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_34bc:
	/* 0x34bc: ja     cbe <syscall__execveat_enter+0xcbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3262ULL;
	}
x86_l_34c2:
	/* 0x34c2: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34c7:
	/* 0x34c7: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_34cb:
	/* 0x34cb: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_34d2:
	/* 0x34d2: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_34d7:
	/* 0x34d7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_34dc:
	/* 0x34dc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_34e1:
	/* 0x34e1: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_34e9:
	/* 0x34e9: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_34ed:
	/* 0x34ed: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_34f4:
	/* 0x34f4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_34f9:
	/* 0x34f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34fb:
	/* 0x34fb: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3500:
	/* 0x3500: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3508:
	/* 0x3508: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_350b:
	/* 0x350b: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3513:
	/* 0x3513: mov    cl,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 39ULL);
x86_l_3515:
	/* 0x3515: jmp    cbe <syscall__execveat_enter+0xcbe> */
	return 3262ULL;
x86_l_351a:
	/* 0x351a: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_351e:
	/* 0x351e: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3525:
	/* 0x3525: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_352a:
	/* 0x352a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_352f:
	/* 0x352f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3534:
	/* 0x3534: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_353b:
	/* 0x353b: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_353f:
	/* 0x353f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3546:
	/* 0x3546: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_354b:
	/* 0x354b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_354d:
	/* 0x354d: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3552:
	/* 0x3552: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3559:
	/* 0x3559: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_355c:
	/* 0x355c: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3563:
	/* 0x3563: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_356c:
	/* 0x356c: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3570:
	/* 0x3570: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3575:
	/* 0x3575: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_357a:
	/* 0x357a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_357f:
	/* 0x357f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3584:
	/* 0x3584: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3586:
	/* 0x3586: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_358b:
	/* 0x358b: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_358d:
	/* 0x358d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3590:
	/* 0x3590: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_3596:
	/* 0x3596: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3599:
	/* 0x3599: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_359f:
	/* 0x359f: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_35a5:
	/* 0x35a5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35aa:
	/* 0x35aa: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_35ae:
	/* 0x35ae: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_35b5:
	/* 0x35b5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_35ba:
	/* 0x35ba: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_35bf:
	/* 0x35bf: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_35c6:
	/* 0x35c6: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_35c9:
	/* 0x35c9: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_35d0:
	/* 0x35d0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35d5:
	/* 0x35d5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_35da:
	/* 0x35da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35dc:
	/* 0x35dc: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_35e0:
	/* 0x35e0: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_35e2:
	/* 0x35e2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35e4:
	/* 0x35e4: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_35ea:
	/* 0x35ea: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_35ed:
	/* 0x35ed: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_35f3:
	/* 0x35f3: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_35f9:
	/* 0x35f9: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35fe:
	/* 0x35fe: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3602:
	/* 0x3602: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3609:
	/* 0x3609: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_360e:
	/* 0x360e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3613:
	/* 0x3613: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3618:
	/* 0x3618: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3620:
	/* 0x3620: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3624:
	/* 0x3624: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_362b:
	/* 0x362b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3630:
	/* 0x3630: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3632:
	/* 0x3632: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3637:
	/* 0x3637: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_363f:
	/* 0x363f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3642:
	/* 0x3642: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_364a:
	/* 0x364a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3653:
	/* 0x3653: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3657:
	/* 0x3657: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_365c:
	/* 0x365c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3661:
	/* 0x3661: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3666:
	/* 0x3666: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_366b:
	/* 0x366b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_366d:
	/* 0x366d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3672:
	/* 0x3672: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_3674:
	/* 0x3674: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3677:
	/* 0x3677: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_367d:
	/* 0x367d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3680:
	/* 0x3680: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3686:
	/* 0x3686: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_368c:
	/* 0x368c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3691:
	/* 0x3691: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3695:
	/* 0x3695: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_369c:
	/* 0x369c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_36a1:
	/* 0x36a1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_36a6:
	/* 0x36a6: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_36ad:
	/* 0x36ad: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_36b0:
	/* 0x36b0: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_36b7:
	/* 0x36b7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36bc:
	/* 0x36bc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_36c1:
	/* 0x36c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36c3:
	/* 0x36c3: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_36c7:
	/* 0x36c7: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_36c9:
	/* 0x36c9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36cb:
	/* 0x36cb: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_36d1:
	/* 0x36d1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_36d4:
	/* 0x36d4: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_36da:
	/* 0x36da: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_36e0:
	/* 0x36e0: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36e5:
	/* 0x36e5: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_36e9:
	/* 0x36e9: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_36f0:
	/* 0x36f0: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_36f5:
	/* 0x36f5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_36fa:
	/* 0x36fa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_36ff:
	/* 0x36ff: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3707:
	/* 0x3707: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_370b:
	/* 0x370b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3712:
	/* 0x3712: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3717:
	/* 0x3717: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3719:
	/* 0x3719: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_371e:
	/* 0x371e: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3726:
	/* 0x3726: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3729:
	/* 0x3729: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3731:
	/* 0x3731: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_373a:
	/* 0x373a: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_373e:
	/* 0x373e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3743:
	/* 0x3743: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3748:
	/* 0x3748: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_374d:
	/* 0x374d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3752:
	/* 0x3752: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3754:
	/* 0x3754: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3759:
	/* 0x3759: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_375b:
	/* 0x375b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_375e:
	/* 0x375e: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_3764:
	/* 0x3764: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3767:
	/* 0x3767: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_376d:
	/* 0x376d: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_3773:
	/* 0x3773: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3778:
	/* 0x3778: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_377c:
	/* 0x377c: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3783:
	/* 0x3783: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3788:
	/* 0x3788: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_378d:
	/* 0x378d: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3794:
	/* 0x3794: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3797:
	/* 0x3797: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_379e:
	/* 0x379e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37a3:
	/* 0x37a3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_37a8:
	/* 0x37a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37aa:
	/* 0x37aa: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_37ae:
	/* 0x37ae: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_37b0:
	/* 0x37b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37b2:
	/* 0x37b2: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_37b8:
	/* 0x37b8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_37bb:
	/* 0x37bb: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_37c1:
	/* 0x37c1: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_37c7:
	/* 0x37c7: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37cc:
	/* 0x37cc: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_37d0:
	/* 0x37d0: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_37d7:
	/* 0x37d7: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_37dc:
	/* 0x37dc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_37e1:
	/* 0x37e1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37e6:
	/* 0x37e6: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_37ee:
	/* 0x37ee: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_37f2:
	/* 0x37f2: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_37f9:
	/* 0x37f9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_37fe:
	/* 0x37fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3800:
	/* 0x3800: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3805:
	/* 0x3805: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_380d:
	/* 0x380d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3810:
	/* 0x3810: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3818:
	/* 0x3818: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3821:
	/* 0x3821: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3825:
	/* 0x3825: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_382a:
	/* 0x382a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_382f:
	/* 0x382f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3834:
	/* 0x3834: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3839:
	/* 0x3839: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_383b:
	/* 0x383b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3840:
	/* 0x3840: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_3842:
	/* 0x3842: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3845:
	/* 0x3845: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_384b:
	/* 0x384b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_384e:
	/* 0x384e: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3854:
	/* 0x3854: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_385a:
	/* 0x385a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_385f:
	/* 0x385f: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3863:
	/* 0x3863: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_386a:
	/* 0x386a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_386f:
	/* 0x386f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3874:
	/* 0x3874: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_387b:
	/* 0x387b: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_387e:
	/* 0x387e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3885:
	/* 0x3885: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_388a:
	/* 0x388a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_388f:
	/* 0x388f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3891:
	/* 0x3891: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3895:
	/* 0x3895: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_3897:
	/* 0x3897: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3899:
	/* 0x3899: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_389f:
	/* 0x389f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_38a2:
	/* 0x38a2: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_38a8:
	/* 0x38a8: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_38ae:
	/* 0x38ae: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38b3:
	/* 0x38b3: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_38b7:
	/* 0x38b7: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_38be:
	/* 0x38be: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_38c3:
	/* 0x38c3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_38c8:
	/* 0x38c8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_38cd:
	/* 0x38cd: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_38d5:
	/* 0x38d5: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_38d9:
	/* 0x38d9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_38e0:
	/* 0x38e0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_38e5:
	/* 0x38e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38e7:
	/* 0x38e7: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_38ec:
	/* 0x38ec: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_38f4:
	/* 0x38f4: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_38f7:
	/* 0x38f7: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_38ff:
	/* 0x38ff: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3908:
	/* 0x3908: lea    rdx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_390c:
	/* 0x390c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 14609ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14609ULL: goto x86_l_3911;
	case 14614ULL: goto x86_l_3916;
	case 14619ULL: goto x86_l_391b;
	case 14624ULL: goto x86_l_3920;
	case 14626ULL: goto x86_l_3922;
	case 14631ULL: goto x86_l_3927;
	case 14633ULL: goto x86_l_3929;
	case 14636ULL: goto x86_l_392c;
	case 14642ULL: goto x86_l_3932;
	case 14645ULL: goto x86_l_3935;
	case 14651ULL: goto x86_l_393b;
	case 14657ULL: goto x86_l_3941;
	case 14662ULL: goto x86_l_3946;
	case 14666ULL: goto x86_l_394a;
	case 14673ULL: goto x86_l_3951;
	case 14678ULL: goto x86_l_3956;
	case 14683ULL: goto x86_l_395b;
	case 14690ULL: goto x86_l_3962;
	case 14693ULL: goto x86_l_3965;
	case 14700ULL: goto x86_l_396c;
	case 14705ULL: goto x86_l_3971;
	case 14710ULL: goto x86_l_3976;
	case 14712ULL: goto x86_l_3978;
	case 14716ULL: goto x86_l_397c;
	case 14718ULL: goto x86_l_397e;
	case 14720ULL: goto x86_l_3980;
	case 14726ULL: goto x86_l_3986;
	case 14729ULL: goto x86_l_3989;
	case 14735ULL: goto x86_l_398f;
	case 14741ULL: goto x86_l_3995;
	case 14746ULL: goto x86_l_399a;
	case 14750ULL: goto x86_l_399e;
	case 14757ULL: goto x86_l_39a5;
	case 14762ULL: goto x86_l_39aa;
	case 14767ULL: goto x86_l_39af;
	case 14772ULL: goto x86_l_39b4;
	case 14780ULL: goto x86_l_39bc;
	case 14784ULL: goto x86_l_39c0;
	case 14791ULL: goto x86_l_39c7;
	case 14796ULL: goto x86_l_39cc;
	case 14798ULL: goto x86_l_39ce;
	case 14803ULL: goto x86_l_39d3;
	case 14811ULL: goto x86_l_39db;
	case 14814ULL: goto x86_l_39de;
	case 14822ULL: goto x86_l_39e6;
	case 14831ULL: goto x86_l_39ef;
	case 14835ULL: goto x86_l_39f3;
	case 14840ULL: goto x86_l_39f8;
	case 14845ULL: goto x86_l_39fd;
	case 14850ULL: goto x86_l_3a02;
	case 14855ULL: goto x86_l_3a07;
	case 14857ULL: goto x86_l_3a09;
	case 14862ULL: goto x86_l_3a0e;
	case 14864ULL: goto x86_l_3a10;
	case 14867ULL: goto x86_l_3a13;
	case 14873ULL: goto x86_l_3a19;
	case 14876ULL: goto x86_l_3a1c;
	case 14882ULL: goto x86_l_3a22;
	case 14888ULL: goto x86_l_3a28;
	case 14893ULL: goto x86_l_3a2d;
	case 14897ULL: goto x86_l_3a31;
	case 14904ULL: goto x86_l_3a38;
	case 14909ULL: goto x86_l_3a3d;
	case 14914ULL: goto x86_l_3a42;
	case 14921ULL: goto x86_l_3a49;
	case 14924ULL: goto x86_l_3a4c;
	case 14931ULL: goto x86_l_3a53;
	case 14936ULL: goto x86_l_3a58;
	case 14941ULL: goto x86_l_3a5d;
	case 14943ULL: goto x86_l_3a5f;
	case 14947ULL: goto x86_l_3a63;
	case 14949ULL: goto x86_l_3a65;
	case 14951ULL: goto x86_l_3a67;
	case 14957ULL: goto x86_l_3a6d;
	case 14960ULL: goto x86_l_3a70;
	case 14966ULL: goto x86_l_3a76;
	case 14972ULL: goto x86_l_3a7c;
	case 14977ULL: goto x86_l_3a81;
	case 14981ULL: goto x86_l_3a85;
	case 14988ULL: goto x86_l_3a8c;
	case 14993ULL: goto x86_l_3a91;
	case 14998ULL: goto x86_l_3a96;
	case 15003ULL: goto x86_l_3a9b;
	case 15011ULL: goto x86_l_3aa3;
	case 15015ULL: goto x86_l_3aa7;
	case 15022ULL: goto x86_l_3aae;
	case 15027ULL: goto x86_l_3ab3;
	case 15029ULL: goto x86_l_3ab5;
	case 15034ULL: goto x86_l_3aba;
	case 15042ULL: goto x86_l_3ac2;
	case 15045ULL: goto x86_l_3ac5;
	case 15053ULL: goto x86_l_3acd;
	case 15062ULL: goto x86_l_3ad6;
	case 15066ULL: goto x86_l_3ada;
	case 15071ULL: goto x86_l_3adf;
	case 15076ULL: goto x86_l_3ae4;
	case 15081ULL: goto x86_l_3ae9;
	case 15086ULL: goto x86_l_3aee;
	case 15088ULL: goto x86_l_3af0;
	case 15093ULL: goto x86_l_3af5;
	case 15095ULL: goto x86_l_3af7;
	case 15098ULL: goto x86_l_3afa;
	case 15104ULL: goto x86_l_3b00;
	case 15107ULL: goto x86_l_3b03;
	case 15113ULL: goto x86_l_3b09;
	case 15119ULL: goto x86_l_3b0f;
	case 15124ULL: goto x86_l_3b14;
	case 15128ULL: goto x86_l_3b18;
	case 15135ULL: goto x86_l_3b1f;
	case 15140ULL: goto x86_l_3b24;
	case 15145ULL: goto x86_l_3b29;
	case 15152ULL: goto x86_l_3b30;
	case 15155ULL: goto x86_l_3b33;
	case 15162ULL: goto x86_l_3b3a;
	case 15167ULL: goto x86_l_3b3f;
	case 15172ULL: goto x86_l_3b44;
	case 15174ULL: goto x86_l_3b46;
	case 15178ULL: goto x86_l_3b4a;
	case 15180ULL: goto x86_l_3b4c;
	case 15182ULL: goto x86_l_3b4e;
	case 15188ULL: goto x86_l_3b54;
	case 15191ULL: goto x86_l_3b57;
	case 15197ULL: goto x86_l_3b5d;
	case 15203ULL: goto x86_l_3b63;
	case 15208ULL: goto x86_l_3b68;
	case 15212ULL: goto x86_l_3b6c;
	case 15219ULL: goto x86_l_3b73;
	case 15224ULL: goto x86_l_3b78;
	case 15229ULL: goto x86_l_3b7d;
	case 15234ULL: goto x86_l_3b82;
	case 15242ULL: goto x86_l_3b8a;
	case 15246ULL: goto x86_l_3b8e;
	case 15253ULL: goto x86_l_3b95;
	case 15258ULL: goto x86_l_3b9a;
	case 15260ULL: goto x86_l_3b9c;
	case 15265ULL: goto x86_l_3ba1;
	case 15273ULL: goto x86_l_3ba9;
	case 15276ULL: goto x86_l_3bac;
	case 15284ULL: goto x86_l_3bb4;
	case 15293ULL: goto x86_l_3bbd;
	case 15297ULL: goto x86_l_3bc1;
	case 15302ULL: goto x86_l_3bc6;
	case 15307ULL: goto x86_l_3bcb;
	case 15312ULL: goto x86_l_3bd0;
	case 15317ULL: goto x86_l_3bd5;
	case 15319ULL: goto x86_l_3bd7;
	case 15324ULL: goto x86_l_3bdc;
	case 15326ULL: goto x86_l_3bde;
	case 15329ULL: goto x86_l_3be1;
	case 15335ULL: goto x86_l_3be7;
	case 15338ULL: goto x86_l_3bea;
	case 15344ULL: goto x86_l_3bf0;
	case 15350ULL: goto x86_l_3bf6;
	case 15355ULL: goto x86_l_3bfb;
	case 15359ULL: goto x86_l_3bff;
	case 15366ULL: goto x86_l_3c06;
	case 15371ULL: goto x86_l_3c0b;
	case 15376ULL: goto x86_l_3c10;
	case 15383ULL: goto x86_l_3c17;
	case 15386ULL: goto x86_l_3c1a;
	case 15393ULL: goto x86_l_3c21;
	case 15398ULL: goto x86_l_3c26;
	case 15403ULL: goto x86_l_3c2b;
	case 15405ULL: goto x86_l_3c2d;
	case 15409ULL: goto x86_l_3c31;
	case 15411ULL: goto x86_l_3c33;
	case 15413ULL: goto x86_l_3c35;
	case 15419ULL: goto x86_l_3c3b;
	case 15422ULL: goto x86_l_3c3e;
	case 15428ULL: goto x86_l_3c44;
	case 15434ULL: goto x86_l_3c4a;
	case 15439ULL: goto x86_l_3c4f;
	case 15443ULL: goto x86_l_3c53;
	case 15450ULL: goto x86_l_3c5a;
	case 15455ULL: goto x86_l_3c5f;
	case 15460ULL: goto x86_l_3c64;
	case 15465ULL: goto x86_l_3c69;
	case 15473ULL: goto x86_l_3c71;
	case 15477ULL: goto x86_l_3c75;
	case 15484ULL: goto x86_l_3c7c;
	case 15489ULL: goto x86_l_3c81;
	case 15491ULL: goto x86_l_3c83;
	case 15496ULL: goto x86_l_3c88;
	case 15504ULL: goto x86_l_3c90;
	case 15507ULL: goto x86_l_3c93;
	case 15515ULL: goto x86_l_3c9b;
	case 15524ULL: goto x86_l_3ca4;
	case 15528ULL: goto x86_l_3ca8;
	case 15533ULL: goto x86_l_3cad;
	case 15538ULL: goto x86_l_3cb2;
	case 15543ULL: goto x86_l_3cb7;
	case 15548ULL: goto x86_l_3cbc;
	case 15550ULL: goto x86_l_3cbe;
	case 15555ULL: goto x86_l_3cc3;
	case 15557ULL: goto x86_l_3cc5;
	case 15560ULL: goto x86_l_3cc8;
	case 15566ULL: goto x86_l_3cce;
	case 15569ULL: goto x86_l_3cd1;
	case 15575ULL: goto x86_l_3cd7;
	case 15581ULL: goto x86_l_3cdd;
	case 15586ULL: goto x86_l_3ce2;
	case 15590ULL: goto x86_l_3ce6;
	case 15597ULL: goto x86_l_3ced;
	case 15602ULL: goto x86_l_3cf2;
	case 15607ULL: goto x86_l_3cf7;
	case 15614ULL: goto x86_l_3cfe;
	case 15617ULL: goto x86_l_3d01;
	case 15624ULL: goto x86_l_3d08;
	case 15629ULL: goto x86_l_3d0d;
	case 15634ULL: goto x86_l_3d12;
	case 15636ULL: goto x86_l_3d14;
	case 15640ULL: goto x86_l_3d18;
	case 15642ULL: goto x86_l_3d1a;
	case 15644ULL: goto x86_l_3d1c;
	case 15650ULL: goto x86_l_3d22;
	case 15653ULL: goto x86_l_3d25;
	case 15659ULL: goto x86_l_3d2b;
	case 15665ULL: goto x86_l_3d31;
	case 15670ULL: goto x86_l_3d36;
	case 15674ULL: goto x86_l_3d3a;
	case 15681ULL: goto x86_l_3d41;
	case 15686ULL: goto x86_l_3d46;
	case 15691ULL: goto x86_l_3d4b;
	case 15696ULL: goto x86_l_3d50;
	case 15704ULL: goto x86_l_3d58;
	case 15708ULL: goto x86_l_3d5c;
	case 15715ULL: goto x86_l_3d63;
	case 15720ULL: goto x86_l_3d68;
	case 15722ULL: goto x86_l_3d6a;
	case 15727ULL: goto x86_l_3d6f;
	case 15735ULL: goto x86_l_3d77;
	case 15738ULL: goto x86_l_3d7a;
	case 15746ULL: goto x86_l_3d82;
	case 15755ULL: goto x86_l_3d8b;
	case 15759ULL: goto x86_l_3d8f;
	case 15764ULL: goto x86_l_3d94;
	case 15769ULL: goto x86_l_3d99;
	case 15774ULL: goto x86_l_3d9e;
	case 15779ULL: goto x86_l_3da3;
	case 15781ULL: goto x86_l_3da5;
	case 15786ULL: goto x86_l_3daa;
	case 15788ULL: goto x86_l_3dac;
	case 15791ULL: goto x86_l_3daf;
	case 15797ULL: goto x86_l_3db5;
	case 15800ULL: goto x86_l_3db8;
	case 15806ULL: goto x86_l_3dbe;
	case 15812ULL: goto x86_l_3dc4;
	case 15817ULL: goto x86_l_3dc9;
	case 15821ULL: goto x86_l_3dcd;
	case 15828ULL: goto x86_l_3dd4;
	case 15833ULL: goto x86_l_3dd9;
	case 15838ULL: goto x86_l_3dde;
	case 15845ULL: goto x86_l_3de5;
	case 15848ULL: goto x86_l_3de8;
	case 15855ULL: goto x86_l_3def;
	case 15860ULL: goto x86_l_3df4;
	case 15865ULL: goto x86_l_3df9;
	case 15867ULL: goto x86_l_3dfb;
	case 15871ULL: goto x86_l_3dff;
	case 15873ULL: goto x86_l_3e01;
	case 15875ULL: goto x86_l_3e03;
	case 15881ULL: goto x86_l_3e09;
	case 15884ULL: goto x86_l_3e0c;
	case 15890ULL: goto x86_l_3e12;
	case 15896ULL: goto x86_l_3e18;
	case 15901ULL: goto x86_l_3e1d;
	case 15905ULL: goto x86_l_3e21;
	case 15912ULL: goto x86_l_3e28;
	case 15917ULL: goto x86_l_3e2d;
	case 15922ULL: goto x86_l_3e32;
	case 15927ULL: goto x86_l_3e37;
	case 15935ULL: goto x86_l_3e3f;
	case 15939ULL: goto x86_l_3e43;
	case 15946ULL: goto x86_l_3e4a;
	case 15951ULL: goto x86_l_3e4f;
	case 15953ULL: goto x86_l_3e51;
	case 15958ULL: goto x86_l_3e56;
	case 15966ULL: goto x86_l_3e5e;
	case 15969ULL: goto x86_l_3e61;
	case 15977ULL: goto x86_l_3e69;
	case 15986ULL: goto x86_l_3e72;
	case 15990ULL: goto x86_l_3e76;
	case 15995ULL: goto x86_l_3e7b;
	case 16000ULL: goto x86_l_3e80;
	case 16005ULL: goto x86_l_3e85;
	case 16010ULL: goto x86_l_3e8a;
	case 16012ULL: goto x86_l_3e8c;
	case 16017ULL: goto x86_l_3e91;
	case 16019ULL: goto x86_l_3e93;
	case 16022ULL: goto x86_l_3e96;
	case 16028ULL: goto x86_l_3e9c;
	case 16031ULL: goto x86_l_3e9f;
	case 16037ULL: goto x86_l_3ea5;
	case 16043ULL: goto x86_l_3eab;
	case 16048ULL: goto x86_l_3eb0;
	case 16052ULL: goto x86_l_3eb4;
	case 16059ULL: goto x86_l_3ebb;
	case 16064ULL: goto x86_l_3ec0;
	case 16069ULL: goto x86_l_3ec5;
	case 16076ULL: goto x86_l_3ecc;
	case 16079ULL: goto x86_l_3ecf;
	case 16086ULL: goto x86_l_3ed6;
	case 16091ULL: goto x86_l_3edb;
	case 16096ULL: goto x86_l_3ee0;
	case 16098ULL: goto x86_l_3ee2;
	case 16102ULL: goto x86_l_3ee6;
	case 16104ULL: goto x86_l_3ee8;
	case 16106ULL: goto x86_l_3eea;
	case 16112ULL: goto x86_l_3ef0;
	case 16115ULL: goto x86_l_3ef3;
	case 16121ULL: goto x86_l_3ef9;
	case 16127ULL: goto x86_l_3eff;
	case 16132ULL: goto x86_l_3f04;
	case 16136ULL: goto x86_l_3f08;
	case 16143ULL: goto x86_l_3f0f;
	case 16148ULL: goto x86_l_3f14;
	case 16153ULL: goto x86_l_3f19;
	case 16158ULL: goto x86_l_3f1e;
	case 16166ULL: goto x86_l_3f26;
	case 16170ULL: goto x86_l_3f2a;
	case 16177ULL: goto x86_l_3f31;
	case 16182ULL: goto x86_l_3f36;
	case 16184ULL: goto x86_l_3f38;
	case 16189ULL: goto x86_l_3f3d;
	case 16197ULL: goto x86_l_3f45;
	case 16200ULL: goto x86_l_3f48;
	case 16208ULL: goto x86_l_3f50;
	case 16217ULL: goto x86_l_3f59;
	case 16221ULL: goto x86_l_3f5d;
	case 16226ULL: goto x86_l_3f62;
	case 16231ULL: goto x86_l_3f67;
	case 16236ULL: goto x86_l_3f6c;
	case 16241ULL: goto x86_l_3f71;
	case 16243ULL: goto x86_l_3f73;
	case 16248ULL: goto x86_l_3f78;
	case 16250ULL: goto x86_l_3f7a;
	case 16253ULL: goto x86_l_3f7d;
	case 16259ULL: goto x86_l_3f83;
	case 16262ULL: goto x86_l_3f86;
	case 16268ULL: goto x86_l_3f8c;
	case 16274ULL: goto x86_l_3f92;
	case 16279ULL: goto x86_l_3f97;
	case 16283ULL: goto x86_l_3f9b;
	case 16290ULL: goto x86_l_3fa2;
	case 16295ULL: goto x86_l_3fa7;
	case 16300ULL: goto x86_l_3fac;
	case 16307ULL: goto x86_l_3fb3;
	case 16310ULL: goto x86_l_3fb6;
	case 16317ULL: goto x86_l_3fbd;
	case 16322ULL: goto x86_l_3fc2;
	case 16327ULL: goto x86_l_3fc7;
	case 16329ULL: goto x86_l_3fc9;
	case 16333ULL: goto x86_l_3fcd;
	case 16335ULL: goto x86_l_3fcf;
	case 16337ULL: goto x86_l_3fd1;
	case 16343ULL: goto x86_l_3fd7;
	case 16346ULL: goto x86_l_3fda;
	case 16352ULL: goto x86_l_3fe0;
	case 16358ULL: goto x86_l_3fe6;
	case 16363ULL: goto x86_l_3feb;
	case 16367ULL: goto x86_l_3fef;
	case 16374ULL: goto x86_l_3ff6;
	case 16379ULL: goto x86_l_3ffb;
	case 16384ULL: goto x86_l_4000;
	case 16389ULL: goto x86_l_4005;
	case 16397ULL: goto x86_l_400d;
	case 16401ULL: goto x86_l_4011;
	case 16408ULL: goto x86_l_4018;
	case 16413ULL: goto x86_l_401d;
	case 16415ULL: goto x86_l_401f;
	case 16420ULL: goto x86_l_4024;
	case 16428ULL: goto x86_l_402c;
	case 16431ULL: goto x86_l_402f;
	case 16439ULL: goto x86_l_4037;
	case 16448ULL: goto x86_l_4040;
	case 16452ULL: goto x86_l_4044;
	case 16457ULL: goto x86_l_4049;
	case 16462ULL: goto x86_l_404e;
	case 16467ULL: goto x86_l_4053;
	case 16472ULL: goto x86_l_4058;
	case 16474ULL: goto x86_l_405a;
	case 16479ULL: goto x86_l_405f;
	case 16481ULL: goto x86_l_4061;
	case 16484ULL: goto x86_l_4064;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3911:
	/* 0x3911: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3916:
	/* 0x3916: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_391b:
	/* 0x391b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3920:
	/* 0x3920: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3922:
	/* 0x3922: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3927:
	/* 0x3927: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_3929:
	/* 0x3929: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_392c:
	/* 0x392c: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_3932:
	/* 0x3932: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3935:
	/* 0x3935: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_393b:
	/* 0x393b: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_3941:
	/* 0x3941: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3946:
	/* 0x3946: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_394a:
	/* 0x394a: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3951:
	/* 0x3951: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3956:
	/* 0x3956: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_395b:
	/* 0x395b: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3962:
	/* 0x3962: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3965:
	/* 0x3965: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_396c:
	/* 0x396c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3971:
	/* 0x3971: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3976:
	/* 0x3976: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3978:
	/* 0x3978: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_397c:
	/* 0x397c: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_397e:
	/* 0x397e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3980:
	/* 0x3980: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_3986:
	/* 0x3986: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3989:
	/* 0x3989: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_398f:
	/* 0x398f: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_3995:
	/* 0x3995: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_399a:
	/* 0x399a: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_399e:
	/* 0x399e: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_39a5:
	/* 0x39a5: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_39aa:
	/* 0x39aa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_39af:
	/* 0x39af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_39b4:
	/* 0x39b4: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_39bc:
	/* 0x39bc: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_39c0:
	/* 0x39c0: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_39c7:
	/* 0x39c7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_39cc:
	/* 0x39cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39ce:
	/* 0x39ce: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_39d3:
	/* 0x39d3: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_39db:
	/* 0x39db: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_39de:
	/* 0x39de: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_39e6:
	/* 0x39e6: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_39ef:
	/* 0x39ef: lea    rdx,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_39f3:
	/* 0x39f3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39f8:
	/* 0x39f8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_39fd:
	/* 0x39fd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a02:
	/* 0x3a02: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a07:
	/* 0x3a07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a09:
	/* 0x3a09: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a0e:
	/* 0x3a0e: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_3a10:
	/* 0x3a10: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3a13:
	/* 0x3a13: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_3a19:
	/* 0x3a19: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3a1c:
	/* 0x3a1c: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3a22:
	/* 0x3a22: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_3a28:
	/* 0x3a28: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a2d:
	/* 0x3a2d: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3a31:
	/* 0x3a31: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3a38:
	/* 0x3a38: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3a3d:
	/* 0x3a3d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3a42:
	/* 0x3a42: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3a49:
	/* 0x3a49: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3a4c:
	/* 0x3a4c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3a53:
	/* 0x3a53: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a58:
	/* 0x3a58: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3a5d:
	/* 0x3a5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a5f:
	/* 0x3a5f: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3a63:
	/* 0x3a63: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_3a65:
	/* 0x3a65: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a67:
	/* 0x3a67: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_3a6d:
	/* 0x3a6d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3a70:
	/* 0x3a70: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3a76:
	/* 0x3a76: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_3a7c:
	/* 0x3a7c: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a81:
	/* 0x3a81: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3a85:
	/* 0x3a85: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3a8c:
	/* 0x3a8c: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3a91:
	/* 0x3a91: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3a96:
	/* 0x3a96: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a9b:
	/* 0x3a9b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3aa3:
	/* 0x3aa3: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3aa7:
	/* 0x3aa7: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3aae:
	/* 0x3aae: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3ab3:
	/* 0x3ab3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ab5:
	/* 0x3ab5: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3aba:
	/* 0x3aba: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3ac2:
	/* 0x3ac2: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3ac5:
	/* 0x3ac5: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3acd:
	/* 0x3acd: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3ad6:
	/* 0x3ad6: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3ada:
	/* 0x3ada: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3adf:
	/* 0x3adf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3ae4:
	/* 0x3ae4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ae9:
	/* 0x3ae9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3aee:
	/* 0x3aee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3af0:
	/* 0x3af0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3af5:
	/* 0x3af5: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_3af7:
	/* 0x3af7: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3afa:
	/* 0x3afa: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_3b00:
	/* 0x3b00: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b03:
	/* 0x3b03: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3b09:
	/* 0x3b09: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_3b0f:
	/* 0x3b0f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b14:
	/* 0x3b14: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3b18:
	/* 0x3b18: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3b1f:
	/* 0x3b1f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3b24:
	/* 0x3b24: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3b29:
	/* 0x3b29: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3b30:
	/* 0x3b30: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3b33:
	/* 0x3b33: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3b3a:
	/* 0x3b3a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b3f:
	/* 0x3b3f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3b44:
	/* 0x3b44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b46:
	/* 0x3b46: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3b4a:
	/* 0x3b4a: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_3b4c:
	/* 0x3b4c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b4e:
	/* 0x3b4e: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_3b54:
	/* 0x3b54: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b57:
	/* 0x3b57: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3b5d:
	/* 0x3b5d: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_3b63:
	/* 0x3b63: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b68:
	/* 0x3b68: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3b6c:
	/* 0x3b6c: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3b73:
	/* 0x3b73: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3b78:
	/* 0x3b78: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3b7d:
	/* 0x3b7d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b82:
	/* 0x3b82: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3b8a:
	/* 0x3b8a: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3b8e:
	/* 0x3b8e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3b95:
	/* 0x3b95: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3b9a:
	/* 0x3b9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b9c:
	/* 0x3b9c: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3ba1:
	/* 0x3ba1: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3ba9:
	/* 0x3ba9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3bac:
	/* 0x3bac: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3bb4:
	/* 0x3bb4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3bbd:
	/* 0x3bbd: lea    rdx,[r13+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3bc1:
	/* 0x3bc1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bc6:
	/* 0x3bc6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3bcb:
	/* 0x3bcb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3bd0:
	/* 0x3bd0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bd5:
	/* 0x3bd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bd7:
	/* 0x3bd7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bdc:
	/* 0x3bdc: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_3bde:
	/* 0x3bde: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3be1:
	/* 0x3be1: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_3be7:
	/* 0x3be7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3bea:
	/* 0x3bea: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3bf0:
	/* 0x3bf0: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_3bf6:
	/* 0x3bf6: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bfb:
	/* 0x3bfb: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3bff:
	/* 0x3bff: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3c06:
	/* 0x3c06: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3c0b:
	/* 0x3c0b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3c10:
	/* 0x3c10: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3c17:
	/* 0x3c17: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3c1a:
	/* 0x3c1a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3c21:
	/* 0x3c21: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c26:
	/* 0x3c26: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3c2b:
	/* 0x3c2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c2d:
	/* 0x3c2d: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3c31:
	/* 0x3c31: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_3c33:
	/* 0x3c33: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c35:
	/* 0x3c35: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_3c3b:
	/* 0x3c3b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3c3e:
	/* 0x3c3e: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3c44:
	/* 0x3c44: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_3c4a:
	/* 0x3c4a: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c4f:
	/* 0x3c4f: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3c53:
	/* 0x3c53: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3c5a:
	/* 0x3c5a: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3c5f:
	/* 0x3c5f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3c64:
	/* 0x3c64: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c69:
	/* 0x3c69: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3c71:
	/* 0x3c71: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3c75:
	/* 0x3c75: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3c7c:
	/* 0x3c7c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3c81:
	/* 0x3c81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c83:
	/* 0x3c83: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3c88:
	/* 0x3c88: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3c90:
	/* 0x3c90: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3c93:
	/* 0x3c93: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3c9b:
	/* 0x3c9b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3ca4:
	/* 0x3ca4: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3ca8:
	/* 0x3ca8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cad:
	/* 0x3cad: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3cb2:
	/* 0x3cb2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3cb7:
	/* 0x3cb7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cbc:
	/* 0x3cbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cbe:
	/* 0x3cbe: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cc3:
	/* 0x3cc3: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_3cc5:
	/* 0x3cc5: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3cc8:
	/* 0x3cc8: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_3cce:
	/* 0x3cce: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3cd1:
	/* 0x3cd1: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3cd7:
	/* 0x3cd7: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_3cdd:
	/* 0x3cdd: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ce2:
	/* 0x3ce2: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3ce6:
	/* 0x3ce6: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3ced:
	/* 0x3ced: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3cf2:
	/* 0x3cf2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3cf7:
	/* 0x3cf7: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3cfe:
	/* 0x3cfe: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3d01:
	/* 0x3d01: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3d08:
	/* 0x3d08: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d0d:
	/* 0x3d0d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3d12:
	/* 0x3d12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d14:
	/* 0x3d14: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3d18:
	/* 0x3d18: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_3d1a:
	/* 0x3d1a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d1c:
	/* 0x3d1c: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_3d22:
	/* 0x3d22: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3d25:
	/* 0x3d25: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3d2b:
	/* 0x3d2b: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_3d31:
	/* 0x3d31: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d36:
	/* 0x3d36: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3d3a:
	/* 0x3d3a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3d41:
	/* 0x3d41: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3d46:
	/* 0x3d46: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3d4b:
	/* 0x3d4b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d50:
	/* 0x3d50: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3d58:
	/* 0x3d58: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3d5c:
	/* 0x3d5c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3d63:
	/* 0x3d63: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3d68:
	/* 0x3d68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d6a:
	/* 0x3d6a: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3d6f:
	/* 0x3d6f: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3d77:
	/* 0x3d77: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3d7a:
	/* 0x3d7a: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3d82:
	/* 0x3d82: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3d8b:
	/* 0x3d8b: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3d8f:
	/* 0x3d8f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d94:
	/* 0x3d94: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3d99:
	/* 0x3d99: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d9e:
	/* 0x3d9e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3da3:
	/* 0x3da3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3da5:
	/* 0x3da5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3daa:
	/* 0x3daa: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_3dac:
	/* 0x3dac: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3daf:
	/* 0x3daf: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_3db5:
	/* 0x3db5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3db8:
	/* 0x3db8: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3dbe:
	/* 0x3dbe: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_3dc4:
	/* 0x3dc4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3dc9:
	/* 0x3dc9: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3dcd:
	/* 0x3dcd: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3dd4:
	/* 0x3dd4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3dd9:
	/* 0x3dd9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3dde:
	/* 0x3dde: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3de5:
	/* 0x3de5: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3de8:
	/* 0x3de8: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3def:
	/* 0x3def: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3df4:
	/* 0x3df4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3df9:
	/* 0x3df9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dfb:
	/* 0x3dfb: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3dff:
	/* 0x3dff: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_3e01:
	/* 0x3e01: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3e03:
	/* 0x3e03: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_3e09:
	/* 0x3e09: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e0c:
	/* 0x3e0c: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3e12:
	/* 0x3e12: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_3e18:
	/* 0x3e18: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e1d:
	/* 0x3e1d: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3e21:
	/* 0x3e21: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3e28:
	/* 0x3e28: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3e2d:
	/* 0x3e2d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e32:
	/* 0x3e32: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e37:
	/* 0x3e37: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3e3f:
	/* 0x3e3f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3e43:
	/* 0x3e43: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3e4a:
	/* 0x3e4a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e4f:
	/* 0x3e4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e51:
	/* 0x3e51: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3e56:
	/* 0x3e56: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3e5e:
	/* 0x3e5e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3e61:
	/* 0x3e61: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3e69:
	/* 0x3e69: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3e72:
	/* 0x3e72: lea    rdx,[r13+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3e76:
	/* 0x3e76: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e7b:
	/* 0x3e7b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3e80:
	/* 0x3e80: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e85:
	/* 0x3e85: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e8a:
	/* 0x3e8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e8c:
	/* 0x3e8c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e91:
	/* 0x3e91: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_3e93:
	/* 0x3e93: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3e96:
	/* 0x3e96: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_3e9c:
	/* 0x3e9c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e9f:
	/* 0x3e9f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3ea5:
	/* 0x3ea5: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_3eab:
	/* 0x3eab: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3eb0:
	/* 0x3eb0: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3eb4:
	/* 0x3eb4: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3ebb:
	/* 0x3ebb: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3ec0:
	/* 0x3ec0: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3ec5:
	/* 0x3ec5: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3ecc:
	/* 0x3ecc: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3ecf:
	/* 0x3ecf: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3ed6:
	/* 0x3ed6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3edb:
	/* 0x3edb: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3ee0:
	/* 0x3ee0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ee2:
	/* 0x3ee2: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3ee6:
	/* 0x3ee6: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_3ee8:
	/* 0x3ee8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3eea:
	/* 0x3eea: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_3ef0:
	/* 0x3ef0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ef3:
	/* 0x3ef3: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3ef9:
	/* 0x3ef9: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_3eff:
	/* 0x3eff: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f04:
	/* 0x3f04: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3f08:
	/* 0x3f08: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3f0f:
	/* 0x3f0f: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3f14:
	/* 0x3f14: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3f19:
	/* 0x3f19: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3f1e:
	/* 0x3f1e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3f26:
	/* 0x3f26: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3f2a:
	/* 0x3f2a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3f31:
	/* 0x3f31: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3f36:
	/* 0x3f36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f38:
	/* 0x3f38: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3f3d:
	/* 0x3f3d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3f45:
	/* 0x3f45: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3f48:
	/* 0x3f48: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3f50:
	/* 0x3f50: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3f59:
	/* 0x3f59: lea    rdx,[r13+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3f5d:
	/* 0x3f5d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f62:
	/* 0x3f62: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3f67:
	/* 0x3f67: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3f6c:
	/* 0x3f6c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f71:
	/* 0x3f71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f73:
	/* 0x3f73: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f78:
	/* 0x3f78: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_3f7a:
	/* 0x3f7a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3f7d:
	/* 0x3f7d: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_3f83:
	/* 0x3f83: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f86:
	/* 0x3f86: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3f8c:
	/* 0x3f8c: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_3f92:
	/* 0x3f92: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f97:
	/* 0x3f97: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3f9b:
	/* 0x3f9b: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3fa2:
	/* 0x3fa2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3fa7:
	/* 0x3fa7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3fac:
	/* 0x3fac: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3fb3:
	/* 0x3fb3: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3fb6:
	/* 0x3fb6: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3fbd:
	/* 0x3fbd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3fc2:
	/* 0x3fc2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3fc7:
	/* 0x3fc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fc9:
	/* 0x3fc9: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3fcd:
	/* 0x3fcd: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_3fcf:
	/* 0x3fcf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3fd1:
	/* 0x3fd1: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_3fd7:
	/* 0x3fd7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3fda:
	/* 0x3fda: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3fe0:
	/* 0x3fe0: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_3fe6:
	/* 0x3fe6: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3feb:
	/* 0x3feb: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3fef:
	/* 0x3fef: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3ff6:
	/* 0x3ff6: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3ffb:
	/* 0x3ffb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4000:
	/* 0x4000: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4005:
	/* 0x4005: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_400d:
	/* 0x400d: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4011:
	/* 0x4011: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4018:
	/* 0x4018: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_401d:
	/* 0x401d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_401f:
	/* 0x401f: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4024:
	/* 0x4024: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_402c:
	/* 0x402c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_402f:
	/* 0x402f: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4037:
	/* 0x4037: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4040:
	/* 0x4040: lea    rdx,[r13+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4044:
	/* 0x4044: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4049:
	/* 0x4049: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_404e:
	/* 0x404e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4053:
	/* 0x4053: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4058:
	/* 0x4058: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_405a:
	/* 0x405a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_405f:
	/* 0x405f: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_4061:
	/* 0x4061: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4064:
	/* 0x4064: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
	return 16490ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 16490ULL: goto x86_l_406a;
	case 16493ULL: goto x86_l_406d;
	case 16499ULL: goto x86_l_4073;
	case 16505ULL: goto x86_l_4079;
	case 16510ULL: goto x86_l_407e;
	case 16514ULL: goto x86_l_4082;
	case 16521ULL: goto x86_l_4089;
	case 16526ULL: goto x86_l_408e;
	case 16531ULL: goto x86_l_4093;
	case 16538ULL: goto x86_l_409a;
	case 16541ULL: goto x86_l_409d;
	case 16548ULL: goto x86_l_40a4;
	case 16553ULL: goto x86_l_40a9;
	case 16558ULL: goto x86_l_40ae;
	case 16560ULL: goto x86_l_40b0;
	case 16564ULL: goto x86_l_40b4;
	case 16566ULL: goto x86_l_40b6;
	case 16568ULL: goto x86_l_40b8;
	case 16574ULL: goto x86_l_40be;
	case 16577ULL: goto x86_l_40c1;
	case 16583ULL: goto x86_l_40c7;
	case 16589ULL: goto x86_l_40cd;
	case 16594ULL: goto x86_l_40d2;
	case 16598ULL: goto x86_l_40d6;
	case 16605ULL: goto x86_l_40dd;
	case 16610ULL: goto x86_l_40e2;
	case 16615ULL: goto x86_l_40e7;
	case 16620ULL: goto x86_l_40ec;
	case 16628ULL: goto x86_l_40f4;
	case 16632ULL: goto x86_l_40f8;
	case 16639ULL: goto x86_l_40ff;
	case 16644ULL: goto x86_l_4104;
	case 16646ULL: goto x86_l_4106;
	case 16651ULL: goto x86_l_410b;
	case 16659ULL: goto x86_l_4113;
	case 16662ULL: goto x86_l_4116;
	case 16670ULL: goto x86_l_411e;
	case 16679ULL: goto x86_l_4127;
	case 16683ULL: goto x86_l_412b;
	case 16688ULL: goto x86_l_4130;
	case 16693ULL: goto x86_l_4135;
	case 16698ULL: goto x86_l_413a;
	case 16703ULL: goto x86_l_413f;
	case 16705ULL: goto x86_l_4141;
	case 16710ULL: goto x86_l_4146;
	case 16712ULL: goto x86_l_4148;
	case 16715ULL: goto x86_l_414b;
	case 16721ULL: goto x86_l_4151;
	case 16724ULL: goto x86_l_4154;
	case 16730ULL: goto x86_l_415a;
	case 16736ULL: goto x86_l_4160;
	case 16741ULL: goto x86_l_4165;
	case 16745ULL: goto x86_l_4169;
	case 16752ULL: goto x86_l_4170;
	case 16757ULL: goto x86_l_4175;
	case 16762ULL: goto x86_l_417a;
	case 16769ULL: goto x86_l_4181;
	case 16772ULL: goto x86_l_4184;
	case 16779ULL: goto x86_l_418b;
	case 16784ULL: goto x86_l_4190;
	case 16789ULL: goto x86_l_4195;
	case 16791ULL: goto x86_l_4197;
	case 16795ULL: goto x86_l_419b;
	case 16797ULL: goto x86_l_419d;
	case 16799ULL: goto x86_l_419f;
	case 16805ULL: goto x86_l_41a5;
	case 16808ULL: goto x86_l_41a8;
	case 16814ULL: goto x86_l_41ae;
	case 16820ULL: goto x86_l_41b4;
	case 16825ULL: goto x86_l_41b9;
	case 16829ULL: goto x86_l_41bd;
	case 16836ULL: goto x86_l_41c4;
	case 16841ULL: goto x86_l_41c9;
	case 16846ULL: goto x86_l_41ce;
	case 16851ULL: goto x86_l_41d3;
	case 16859ULL: goto x86_l_41db;
	case 16863ULL: goto x86_l_41df;
	case 16870ULL: goto x86_l_41e6;
	case 16875ULL: goto x86_l_41eb;
	case 16877ULL: goto x86_l_41ed;
	case 16882ULL: goto x86_l_41f2;
	case 16890ULL: goto x86_l_41fa;
	case 16893ULL: goto x86_l_41fd;
	case 16901ULL: goto x86_l_4205;
	case 16910ULL: goto x86_l_420e;
	case 16914ULL: goto x86_l_4212;
	case 16919ULL: goto x86_l_4217;
	case 16924ULL: goto x86_l_421c;
	case 16929ULL: goto x86_l_4221;
	case 16934ULL: goto x86_l_4226;
	case 16936ULL: goto x86_l_4228;
	case 16941ULL: goto x86_l_422d;
	case 16943ULL: goto x86_l_422f;
	case 16946ULL: goto x86_l_4232;
	case 16952ULL: goto x86_l_4238;
	case 16955ULL: goto x86_l_423b;
	case 16961ULL: goto x86_l_4241;
	case 16967ULL: goto x86_l_4247;
	case 16972ULL: goto x86_l_424c;
	case 16976ULL: goto x86_l_4250;
	case 16983ULL: goto x86_l_4257;
	case 16988ULL: goto x86_l_425c;
	case 16993ULL: goto x86_l_4261;
	case 17000ULL: goto x86_l_4268;
	case 17003ULL: goto x86_l_426b;
	case 17010ULL: goto x86_l_4272;
	case 17015ULL: goto x86_l_4277;
	case 17020ULL: goto x86_l_427c;
	case 17022ULL: goto x86_l_427e;
	case 17026ULL: goto x86_l_4282;
	case 17028ULL: goto x86_l_4284;
	case 17030ULL: goto x86_l_4286;
	case 17036ULL: goto x86_l_428c;
	case 17039ULL: goto x86_l_428f;
	case 17045ULL: goto x86_l_4295;
	case 17051ULL: goto x86_l_429b;
	case 17056ULL: goto x86_l_42a0;
	case 17060ULL: goto x86_l_42a4;
	case 17067ULL: goto x86_l_42ab;
	case 17072ULL: goto x86_l_42b0;
	case 17077ULL: goto x86_l_42b5;
	case 17082ULL: goto x86_l_42ba;
	case 17090ULL: goto x86_l_42c2;
	case 17094ULL: goto x86_l_42c6;
	case 17101ULL: goto x86_l_42cd;
	case 17106ULL: goto x86_l_42d2;
	case 17108ULL: goto x86_l_42d4;
	case 17113ULL: goto x86_l_42d9;
	case 17121ULL: goto x86_l_42e1;
	case 17124ULL: goto x86_l_42e4;
	case 17132ULL: goto x86_l_42ec;
	case 17141ULL: goto x86_l_42f5;
	case 17148ULL: goto x86_l_42fc;
	case 17153ULL: goto x86_l_4301;
	case 17158ULL: goto x86_l_4306;
	case 17163ULL: goto x86_l_430b;
	case 17168ULL: goto x86_l_4310;
	case 17170ULL: goto x86_l_4312;
	case 17175ULL: goto x86_l_4317;
	case 17177ULL: goto x86_l_4319;
	case 17180ULL: goto x86_l_431c;
	case 17186ULL: goto x86_l_4322;
	case 17189ULL: goto x86_l_4325;
	case 17195ULL: goto x86_l_432b;
	case 17201ULL: goto x86_l_4331;
	case 17206ULL: goto x86_l_4336;
	case 17210ULL: goto x86_l_433a;
	case 17217ULL: goto x86_l_4341;
	case 17222ULL: goto x86_l_4346;
	case 17227ULL: goto x86_l_434b;
	case 17234ULL: goto x86_l_4352;
	case 17237ULL: goto x86_l_4355;
	case 17244ULL: goto x86_l_435c;
	case 17249ULL: goto x86_l_4361;
	case 17254ULL: goto x86_l_4366;
	case 17256ULL: goto x86_l_4368;
	case 17260ULL: goto x86_l_436c;
	case 17262ULL: goto x86_l_436e;
	case 17264ULL: goto x86_l_4370;
	case 17270ULL: goto x86_l_4376;
	case 17273ULL: goto x86_l_4379;
	case 17279ULL: goto x86_l_437f;
	case 17285ULL: goto x86_l_4385;
	case 17290ULL: goto x86_l_438a;
	case 17294ULL: goto x86_l_438e;
	case 17301ULL: goto x86_l_4395;
	case 17306ULL: goto x86_l_439a;
	case 17311ULL: goto x86_l_439f;
	case 17316ULL: goto x86_l_43a4;
	case 17324ULL: goto x86_l_43ac;
	case 17328ULL: goto x86_l_43b0;
	case 17335ULL: goto x86_l_43b7;
	case 17340ULL: goto x86_l_43bc;
	case 17342ULL: goto x86_l_43be;
	case 17347ULL: goto x86_l_43c3;
	case 17355ULL: goto x86_l_43cb;
	case 17358ULL: goto x86_l_43ce;
	case 17366ULL: goto x86_l_43d6;
	case 17375ULL: goto x86_l_43df;
	case 17382ULL: goto x86_l_43e6;
	case 17387ULL: goto x86_l_43eb;
	case 17392ULL: goto x86_l_43f0;
	case 17397ULL: goto x86_l_43f5;
	case 17402ULL: goto x86_l_43fa;
	case 17404ULL: goto x86_l_43fc;
	case 17409ULL: goto x86_l_4401;
	case 17411ULL: goto x86_l_4403;
	case 17414ULL: goto x86_l_4406;
	case 17420ULL: goto x86_l_440c;
	case 17423ULL: goto x86_l_440f;
	case 17429ULL: goto x86_l_4415;
	case 17435ULL: goto x86_l_441b;
	case 17440ULL: goto x86_l_4420;
	case 17444ULL: goto x86_l_4424;
	case 17451ULL: goto x86_l_442b;
	case 17456ULL: goto x86_l_4430;
	case 17461ULL: goto x86_l_4435;
	case 17468ULL: goto x86_l_443c;
	case 17471ULL: goto x86_l_443f;
	case 17478ULL: goto x86_l_4446;
	case 17483ULL: goto x86_l_444b;
	case 17488ULL: goto x86_l_4450;
	case 17490ULL: goto x86_l_4452;
	case 17494ULL: goto x86_l_4456;
	case 17496ULL: goto x86_l_4458;
	case 17498ULL: goto x86_l_445a;
	case 17504ULL: goto x86_l_4460;
	case 17507ULL: goto x86_l_4463;
	case 17513ULL: goto x86_l_4469;
	case 17519ULL: goto x86_l_446f;
	case 17524ULL: goto x86_l_4474;
	case 17528ULL: goto x86_l_4478;
	case 17535ULL: goto x86_l_447f;
	case 17540ULL: goto x86_l_4484;
	case 17545ULL: goto x86_l_4489;
	case 17550ULL: goto x86_l_448e;
	case 17558ULL: goto x86_l_4496;
	case 17562ULL: goto x86_l_449a;
	case 17569ULL: goto x86_l_44a1;
	case 17574ULL: goto x86_l_44a6;
	case 17576ULL: goto x86_l_44a8;
	case 17581ULL: goto x86_l_44ad;
	case 17589ULL: goto x86_l_44b5;
	case 17592ULL: goto x86_l_44b8;
	case 17600ULL: goto x86_l_44c0;
	case 17609ULL: goto x86_l_44c9;
	case 17616ULL: goto x86_l_44d0;
	case 17621ULL: goto x86_l_44d5;
	case 17626ULL: goto x86_l_44da;
	case 17631ULL: goto x86_l_44df;
	case 17636ULL: goto x86_l_44e4;
	case 17638ULL: goto x86_l_44e6;
	case 17643ULL: goto x86_l_44eb;
	case 17645ULL: goto x86_l_44ed;
	case 17648ULL: goto x86_l_44f0;
	case 17654ULL: goto x86_l_44f6;
	case 17657ULL: goto x86_l_44f9;
	case 17663ULL: goto x86_l_44ff;
	case 17669ULL: goto x86_l_4505;
	case 17674ULL: goto x86_l_450a;
	case 17678ULL: goto x86_l_450e;
	case 17685ULL: goto x86_l_4515;
	case 17690ULL: goto x86_l_451a;
	case 17695ULL: goto x86_l_451f;
	case 17702ULL: goto x86_l_4526;
	case 17705ULL: goto x86_l_4529;
	case 17712ULL: goto x86_l_4530;
	case 17717ULL: goto x86_l_4535;
	case 17722ULL: goto x86_l_453a;
	case 17724ULL: goto x86_l_453c;
	case 17728ULL: goto x86_l_4540;
	case 17730ULL: goto x86_l_4542;
	case 17732ULL: goto x86_l_4544;
	case 17738ULL: goto x86_l_454a;
	case 17741ULL: goto x86_l_454d;
	case 17747ULL: goto x86_l_4553;
	case 17753ULL: goto x86_l_4559;
	case 17758ULL: goto x86_l_455e;
	case 17762ULL: goto x86_l_4562;
	case 17769ULL: goto x86_l_4569;
	case 17774ULL: goto x86_l_456e;
	case 17779ULL: goto x86_l_4573;
	case 17784ULL: goto x86_l_4578;
	case 17792ULL: goto x86_l_4580;
	case 17796ULL: goto x86_l_4584;
	case 17803ULL: goto x86_l_458b;
	case 17808ULL: goto x86_l_4590;
	case 17810ULL: goto x86_l_4592;
	case 17815ULL: goto x86_l_4597;
	case 17823ULL: goto x86_l_459f;
	case 17826ULL: goto x86_l_45a2;
	case 17834ULL: goto x86_l_45aa;
	case 17843ULL: goto x86_l_45b3;
	case 17850ULL: goto x86_l_45ba;
	case 17855ULL: goto x86_l_45bf;
	case 17860ULL: goto x86_l_45c4;
	case 17865ULL: goto x86_l_45c9;
	case 17870ULL: goto x86_l_45ce;
	case 17872ULL: goto x86_l_45d0;
	case 17877ULL: goto x86_l_45d5;
	case 17879ULL: goto x86_l_45d7;
	case 17882ULL: goto x86_l_45da;
	case 17888ULL: goto x86_l_45e0;
	case 17891ULL: goto x86_l_45e3;
	case 17897ULL: goto x86_l_45e9;
	case 17903ULL: goto x86_l_45ef;
	case 17908ULL: goto x86_l_45f4;
	case 17912ULL: goto x86_l_45f8;
	case 17919ULL: goto x86_l_45ff;
	case 17924ULL: goto x86_l_4604;
	case 17929ULL: goto x86_l_4609;
	case 17936ULL: goto x86_l_4610;
	case 17939ULL: goto x86_l_4613;
	case 17946ULL: goto x86_l_461a;
	case 17951ULL: goto x86_l_461f;
	case 17956ULL: goto x86_l_4624;
	case 17958ULL: goto x86_l_4626;
	case 17962ULL: goto x86_l_462a;
	case 17964ULL: goto x86_l_462c;
	case 17966ULL: goto x86_l_462e;
	case 17972ULL: goto x86_l_4634;
	case 17975ULL: goto x86_l_4637;
	case 17981ULL: goto x86_l_463d;
	case 17987ULL: goto x86_l_4643;
	case 17992ULL: goto x86_l_4648;
	case 17996ULL: goto x86_l_464c;
	case 18003ULL: goto x86_l_4653;
	case 18008ULL: goto x86_l_4658;
	case 18013ULL: goto x86_l_465d;
	case 18018ULL: goto x86_l_4662;
	case 18026ULL: goto x86_l_466a;
	case 18030ULL: goto x86_l_466e;
	case 18037ULL: goto x86_l_4675;
	case 18042ULL: goto x86_l_467a;
	case 18044ULL: goto x86_l_467c;
	case 18049ULL: goto x86_l_4681;
	case 18057ULL: goto x86_l_4689;
	case 18060ULL: goto x86_l_468c;
	case 18068ULL: goto x86_l_4694;
	case 18077ULL: goto x86_l_469d;
	case 18084ULL: goto x86_l_46a4;
	case 18089ULL: goto x86_l_46a9;
	case 18094ULL: goto x86_l_46ae;
	case 18099ULL: goto x86_l_46b3;
	case 18104ULL: goto x86_l_46b8;
	case 18106ULL: goto x86_l_46ba;
	case 18111ULL: goto x86_l_46bf;
	case 18113ULL: goto x86_l_46c1;
	case 18116ULL: goto x86_l_46c4;
	case 18122ULL: goto x86_l_46ca;
	case 18125ULL: goto x86_l_46cd;
	case 18131ULL: goto x86_l_46d3;
	case 18137ULL: goto x86_l_46d9;
	case 18142ULL: goto x86_l_46de;
	case 18146ULL: goto x86_l_46e2;
	case 18153ULL: goto x86_l_46e9;
	case 18158ULL: goto x86_l_46ee;
	case 18163ULL: goto x86_l_46f3;
	case 18170ULL: goto x86_l_46fa;
	case 18173ULL: goto x86_l_46fd;
	case 18180ULL: goto x86_l_4704;
	case 18185ULL: goto x86_l_4709;
	case 18190ULL: goto x86_l_470e;
	case 18192ULL: goto x86_l_4710;
	case 18196ULL: goto x86_l_4714;
	case 18198ULL: goto x86_l_4716;
	case 18200ULL: goto x86_l_4718;
	case 18206ULL: goto x86_l_471e;
	case 18209ULL: goto x86_l_4721;
	case 18215ULL: goto x86_l_4727;
	case 18221ULL: goto x86_l_472d;
	case 18226ULL: goto x86_l_4732;
	case 18230ULL: goto x86_l_4736;
	case 18237ULL: goto x86_l_473d;
	case 18242ULL: goto x86_l_4742;
	case 18247ULL: goto x86_l_4747;
	case 18252ULL: goto x86_l_474c;
	case 18260ULL: goto x86_l_4754;
	case 18264ULL: goto x86_l_4758;
	case 18271ULL: goto x86_l_475f;
	case 18276ULL: goto x86_l_4764;
	case 18278ULL: goto x86_l_4766;
	case 18283ULL: goto x86_l_476b;
	case 18291ULL: goto x86_l_4773;
	case 18294ULL: goto x86_l_4776;
	case 18302ULL: goto x86_l_477e;
	case 18311ULL: goto x86_l_4787;
	case 18318ULL: goto x86_l_478e;
	case 18323ULL: goto x86_l_4793;
	case 18328ULL: goto x86_l_4798;
	case 18333ULL: goto x86_l_479d;
	case 18338ULL: goto x86_l_47a2;
	case 18340ULL: goto x86_l_47a4;
	case 18345ULL: goto x86_l_47a9;
	case 18347ULL: goto x86_l_47ab;
	case 18350ULL: goto x86_l_47ae;
	case 18356ULL: goto x86_l_47b4;
	case 18359ULL: goto x86_l_47b7;
	case 18365ULL: goto x86_l_47bd;
	case 18371ULL: goto x86_l_47c3;
	case 18376ULL: goto x86_l_47c8;
	case 18380ULL: goto x86_l_47cc;
	case 18387ULL: goto x86_l_47d3;
	case 18392ULL: goto x86_l_47d8;
	default: return 0xffffffffffffffffULL;
	}
x86_l_406a:
	/* 0x406a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_406d:
	/* 0x406d: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4073:
	/* 0x4073: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4079:
	/* 0x4079: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_407e:
	/* 0x407e: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4082:
	/* 0x4082: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4089:
	/* 0x4089: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_408e:
	/* 0x408e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4093:
	/* 0x4093: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_409a:
	/* 0x409a: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_409d:
	/* 0x409d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_40a4:
	/* 0x40a4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40a9:
	/* 0x40a9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_40ae:
	/* 0x40ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40b0:
	/* 0x40b0: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_40b4:
	/* 0x40b4: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_40b6:
	/* 0x40b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_40b8:
	/* 0x40b8: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_40be:
	/* 0x40be: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_40c1:
	/* 0x40c1: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_40c7:
	/* 0x40c7: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_40cd:
	/* 0x40cd: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40d2:
	/* 0x40d2: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_40d6:
	/* 0x40d6: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_40dd:
	/* 0x40dd: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_40e2:
	/* 0x40e2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_40e7:
	/* 0x40e7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_40ec:
	/* 0x40ec: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_40f4:
	/* 0x40f4: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_40f8:
	/* 0x40f8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_40ff:
	/* 0x40ff: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4104:
	/* 0x4104: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4106:
	/* 0x4106: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_410b:
	/* 0x410b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4113:
	/* 0x4113: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4116:
	/* 0x4116: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_411e:
	/* 0x411e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4127:
	/* 0x4127: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_412b:
	/* 0x412b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4130:
	/* 0x4130: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4135:
	/* 0x4135: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_413a:
	/* 0x413a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_413f:
	/* 0x413f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4141:
	/* 0x4141: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4146:
	/* 0x4146: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_4148:
	/* 0x4148: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_414b:
	/* 0x414b: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_4151:
	/* 0x4151: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4154:
	/* 0x4154: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_415a:
	/* 0x415a: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4160:
	/* 0x4160: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4165:
	/* 0x4165: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4169:
	/* 0x4169: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4170:
	/* 0x4170: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4175:
	/* 0x4175: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_417a:
	/* 0x417a: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4181:
	/* 0x4181: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4184:
	/* 0x4184: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_418b:
	/* 0x418b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4190:
	/* 0x4190: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4195:
	/* 0x4195: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4197:
	/* 0x4197: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_419b:
	/* 0x419b: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_419d:
	/* 0x419d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_419f:
	/* 0x419f: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_41a5:
	/* 0x41a5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_41a8:
	/* 0x41a8: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_41ae:
	/* 0x41ae: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_41b4:
	/* 0x41b4: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41b9:
	/* 0x41b9: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_41bd:
	/* 0x41bd: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_41c4:
	/* 0x41c4: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_41c9:
	/* 0x41c9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_41ce:
	/* 0x41ce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_41d3:
	/* 0x41d3: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_41db:
	/* 0x41db: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_41df:
	/* 0x41df: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_41e6:
	/* 0x41e6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_41eb:
	/* 0x41eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41ed:
	/* 0x41ed: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_41f2:
	/* 0x41f2: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_41fa:
	/* 0x41fa: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_41fd:
	/* 0x41fd: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4205:
	/* 0x4205: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_420e:
	/* 0x420e: lea    rdx,[r13+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4212:
	/* 0x4212: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4217:
	/* 0x4217: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_421c:
	/* 0x421c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4221:
	/* 0x4221: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4226:
	/* 0x4226: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4228:
	/* 0x4228: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_422d:
	/* 0x422d: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_422f:
	/* 0x422f: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4232:
	/* 0x4232: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_4238:
	/* 0x4238: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_423b:
	/* 0x423b: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4241:
	/* 0x4241: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4247:
	/* 0x4247: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_424c:
	/* 0x424c: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4250:
	/* 0x4250: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4257:
	/* 0x4257: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_425c:
	/* 0x425c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4261:
	/* 0x4261: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4268:
	/* 0x4268: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_426b:
	/* 0x426b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4272:
	/* 0x4272: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4277:
	/* 0x4277: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_427c:
	/* 0x427c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_427e:
	/* 0x427e: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4282:
	/* 0x4282: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_4284:
	/* 0x4284: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4286:
	/* 0x4286: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_428c:
	/* 0x428c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_428f:
	/* 0x428f: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4295:
	/* 0x4295: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_429b:
	/* 0x429b: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42a0:
	/* 0x42a0: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_42a4:
	/* 0x42a4: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_42ab:
	/* 0x42ab: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_42b0:
	/* 0x42b0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_42b5:
	/* 0x42b5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_42ba:
	/* 0x42ba: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_42c2:
	/* 0x42c2: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_42c6:
	/* 0x42c6: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_42cd:
	/* 0x42cd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_42d2:
	/* 0x42d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42d4:
	/* 0x42d4: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_42d9:
	/* 0x42d9: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_42e1:
	/* 0x42e1: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_42e4:
	/* 0x42e4: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_42ec:
	/* 0x42ec: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_42f5:
	/* 0x42f5: lea    rdx,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_42fc:
	/* 0x42fc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4301:
	/* 0x4301: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4306:
	/* 0x4306: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_430b:
	/* 0x430b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4310:
	/* 0x4310: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4312:
	/* 0x4312: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4317:
	/* 0x4317: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_4319:
	/* 0x4319: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_431c:
	/* 0x431c: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_4322:
	/* 0x4322: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4325:
	/* 0x4325: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_432b:
	/* 0x432b: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4331:
	/* 0x4331: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4336:
	/* 0x4336: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_433a:
	/* 0x433a: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4341:
	/* 0x4341: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4346:
	/* 0x4346: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_434b:
	/* 0x434b: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4352:
	/* 0x4352: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4355:
	/* 0x4355: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_435c:
	/* 0x435c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4361:
	/* 0x4361: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4366:
	/* 0x4366: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4368:
	/* 0x4368: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_436c:
	/* 0x436c: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_436e:
	/* 0x436e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4370:
	/* 0x4370: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_4376:
	/* 0x4376: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4379:
	/* 0x4379: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_437f:
	/* 0x437f: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4385:
	/* 0x4385: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_438a:
	/* 0x438a: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_438e:
	/* 0x438e: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4395:
	/* 0x4395: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_439a:
	/* 0x439a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_439f:
	/* 0x439f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_43a4:
	/* 0x43a4: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_43ac:
	/* 0x43ac: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_43b0:
	/* 0x43b0: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_43b7:
	/* 0x43b7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_43bc:
	/* 0x43bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43be:
	/* 0x43be: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_43c3:
	/* 0x43c3: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_43cb:
	/* 0x43cb: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_43ce:
	/* 0x43ce: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_43d6:
	/* 0x43d6: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_43df:
	/* 0x43df: lea    rdx,[r13+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_43e6:
	/* 0x43e6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43eb:
	/* 0x43eb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_43f0:
	/* 0x43f0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_43f5:
	/* 0x43f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_43fa:
	/* 0x43fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43fc:
	/* 0x43fc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4401:
	/* 0x4401: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_4403:
	/* 0x4403: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4406:
	/* 0x4406: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_440c:
	/* 0x440c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_440f:
	/* 0x440f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4415:
	/* 0x4415: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_441b:
	/* 0x441b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4420:
	/* 0x4420: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4424:
	/* 0x4424: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_442b:
	/* 0x442b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4430:
	/* 0x4430: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4435:
	/* 0x4435: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_443c:
	/* 0x443c: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_443f:
	/* 0x443f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4446:
	/* 0x4446: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_444b:
	/* 0x444b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4450:
	/* 0x4450: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4452:
	/* 0x4452: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4456:
	/* 0x4456: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_4458:
	/* 0x4458: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_445a:
	/* 0x445a: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_4460:
	/* 0x4460: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4463:
	/* 0x4463: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4469:
	/* 0x4469: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_446f:
	/* 0x446f: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4474:
	/* 0x4474: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4478:
	/* 0x4478: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_447f:
	/* 0x447f: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4484:
	/* 0x4484: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4489:
	/* 0x4489: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_448e:
	/* 0x448e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4496:
	/* 0x4496: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_449a:
	/* 0x449a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_44a1:
	/* 0x44a1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_44a6:
	/* 0x44a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44a8:
	/* 0x44a8: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_44ad:
	/* 0x44ad: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_44b5:
	/* 0x44b5: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_44b8:
	/* 0x44b8: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_44c0:
	/* 0x44c0: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_44c9:
	/* 0x44c9: lea    rdx,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_44d0:
	/* 0x44d0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44d5:
	/* 0x44d5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_44da:
	/* 0x44da: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_44df:
	/* 0x44df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44e4:
	/* 0x44e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44e6:
	/* 0x44e6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44eb:
	/* 0x44eb: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_44ed:
	/* 0x44ed: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_44f0:
	/* 0x44f0: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_44f6:
	/* 0x44f6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_44f9:
	/* 0x44f9: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_44ff:
	/* 0x44ff: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4505:
	/* 0x4505: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_450a:
	/* 0x450a: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_450e:
	/* 0x450e: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4515:
	/* 0x4515: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_451a:
	/* 0x451a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_451f:
	/* 0x451f: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4526:
	/* 0x4526: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4529:
	/* 0x4529: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4530:
	/* 0x4530: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4535:
	/* 0x4535: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_453a:
	/* 0x453a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_453c:
	/* 0x453c: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4540:
	/* 0x4540: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_4542:
	/* 0x4542: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4544:
	/* 0x4544: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_454a:
	/* 0x454a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_454d:
	/* 0x454d: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4553:
	/* 0x4553: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4559:
	/* 0x4559: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_455e:
	/* 0x455e: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4562:
	/* 0x4562: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4569:
	/* 0x4569: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_456e:
	/* 0x456e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4573:
	/* 0x4573: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4578:
	/* 0x4578: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4580:
	/* 0x4580: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4584:
	/* 0x4584: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_458b:
	/* 0x458b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4590:
	/* 0x4590: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4592:
	/* 0x4592: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4597:
	/* 0x4597: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_459f:
	/* 0x459f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_45a2:
	/* 0x45a2: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_45aa:
	/* 0x45aa: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_45b3:
	/* 0x45b3: lea    rdx,[r13+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_45ba:
	/* 0x45ba: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45bf:
	/* 0x45bf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_45c4:
	/* 0x45c4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_45c9:
	/* 0x45c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45ce:
	/* 0x45ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45d0:
	/* 0x45d0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45d5:
	/* 0x45d5: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_45d7:
	/* 0x45d7: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_45da:
	/* 0x45da: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_45e0:
	/* 0x45e0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_45e3:
	/* 0x45e3: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_45e9:
	/* 0x45e9: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_45ef:
	/* 0x45ef: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45f4:
	/* 0x45f4: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_45f8:
	/* 0x45f8: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_45ff:
	/* 0x45ff: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4604:
	/* 0x4604: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4609:
	/* 0x4609: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4610:
	/* 0x4610: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4613:
	/* 0x4613: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_461a:
	/* 0x461a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_461f:
	/* 0x461f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4624:
	/* 0x4624: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4626:
	/* 0x4626: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_462a:
	/* 0x462a: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_462c:
	/* 0x462c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_462e:
	/* 0x462e: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_4634:
	/* 0x4634: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4637:
	/* 0x4637: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_463d:
	/* 0x463d: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4643:
	/* 0x4643: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4648:
	/* 0x4648: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_464c:
	/* 0x464c: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4653:
	/* 0x4653: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4658:
	/* 0x4658: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_465d:
	/* 0x465d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4662:
	/* 0x4662: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_466a:
	/* 0x466a: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_466e:
	/* 0x466e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4675:
	/* 0x4675: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_467a:
	/* 0x467a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_467c:
	/* 0x467c: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4681:
	/* 0x4681: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4689:
	/* 0x4689: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_468c:
	/* 0x468c: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4694:
	/* 0x4694: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_469d:
	/* 0x469d: lea    rdx,[r13+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_46a4:
	/* 0x46a4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46a9:
	/* 0x46a9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_46ae:
	/* 0x46ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_46b3:
	/* 0x46b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46b8:
	/* 0x46b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46ba:
	/* 0x46ba: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46bf:
	/* 0x46bf: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_46c1:
	/* 0x46c1: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_46c4:
	/* 0x46c4: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_46ca:
	/* 0x46ca: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_46cd:
	/* 0x46cd: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_46d3:
	/* 0x46d3: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_46d9:
	/* 0x46d9: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46de:
	/* 0x46de: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_46e2:
	/* 0x46e2: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_46e9:
	/* 0x46e9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_46ee:
	/* 0x46ee: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_46f3:
	/* 0x46f3: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_46fa:
	/* 0x46fa: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_46fd:
	/* 0x46fd: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4704:
	/* 0x4704: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4709:
	/* 0x4709: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_470e:
	/* 0x470e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4710:
	/* 0x4710: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4714:
	/* 0x4714: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_4716:
	/* 0x4716: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4718:
	/* 0x4718: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_471e:
	/* 0x471e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4721:
	/* 0x4721: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4727:
	/* 0x4727: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_472d:
	/* 0x472d: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4732:
	/* 0x4732: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4736:
	/* 0x4736: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_473d:
	/* 0x473d: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4742:
	/* 0x4742: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4747:
	/* 0x4747: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_474c:
	/* 0x474c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4754:
	/* 0x4754: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4758:
	/* 0x4758: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_475f:
	/* 0x475f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4764:
	/* 0x4764: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4766:
	/* 0x4766: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_476b:
	/* 0x476b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4773:
	/* 0x4773: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4776:
	/* 0x4776: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_477e:
	/* 0x477e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4787:
	/* 0x4787: lea    rdx,[r13+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_478e:
	/* 0x478e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4793:
	/* 0x4793: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4798:
	/* 0x4798: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_479d:
	/* 0x479d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47a2:
	/* 0x47a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47a4:
	/* 0x47a4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47a9:
	/* 0x47a9: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_47ab:
	/* 0x47ab: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_47ae:
	/* 0x47ae: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_47b4:
	/* 0x47b4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_47b7:
	/* 0x47b7: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_47bd:
	/* 0x47bd: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_47c3:
	/* 0x47c3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47c8:
	/* 0x47c8: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_47cc:
	/* 0x47cc: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_47d3:
	/* 0x47d3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_47d8:
	/* 0x47d8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
	return 18397ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 18397ULL: goto x86_l_47dd;
	case 18404ULL: goto x86_l_47e4;
	case 18407ULL: goto x86_l_47e7;
	case 18414ULL: goto x86_l_47ee;
	case 18419ULL: goto x86_l_47f3;
	case 18424ULL: goto x86_l_47f8;
	case 18426ULL: goto x86_l_47fa;
	case 18430ULL: goto x86_l_47fe;
	case 18432ULL: goto x86_l_4800;
	case 18434ULL: goto x86_l_4802;
	case 18440ULL: goto x86_l_4808;
	case 18443ULL: goto x86_l_480b;
	case 18449ULL: goto x86_l_4811;
	case 18455ULL: goto x86_l_4817;
	case 18460ULL: goto x86_l_481c;
	case 18464ULL: goto x86_l_4820;
	case 18471ULL: goto x86_l_4827;
	case 18476ULL: goto x86_l_482c;
	case 18481ULL: goto x86_l_4831;
	case 18486ULL: goto x86_l_4836;
	case 18494ULL: goto x86_l_483e;
	case 18498ULL: goto x86_l_4842;
	case 18505ULL: goto x86_l_4849;
	case 18510ULL: goto x86_l_484e;
	case 18512ULL: goto x86_l_4850;
	case 18517ULL: goto x86_l_4855;
	case 18525ULL: goto x86_l_485d;
	case 18528ULL: goto x86_l_4860;
	case 18536ULL: goto x86_l_4868;
	case 18545ULL: goto x86_l_4871;
	case 18552ULL: goto x86_l_4878;
	case 18557ULL: goto x86_l_487d;
	case 18562ULL: goto x86_l_4882;
	case 18567ULL: goto x86_l_4887;
	case 18572ULL: goto x86_l_488c;
	case 18574ULL: goto x86_l_488e;
	case 18579ULL: goto x86_l_4893;
	case 18581ULL: goto x86_l_4895;
	case 18584ULL: goto x86_l_4898;
	case 18590ULL: goto x86_l_489e;
	case 18593ULL: goto x86_l_48a1;
	case 18599ULL: goto x86_l_48a7;
	case 18605ULL: goto x86_l_48ad;
	case 18610ULL: goto x86_l_48b2;
	case 18614ULL: goto x86_l_48b6;
	case 18621ULL: goto x86_l_48bd;
	case 18626ULL: goto x86_l_48c2;
	case 18631ULL: goto x86_l_48c7;
	case 18638ULL: goto x86_l_48ce;
	case 18641ULL: goto x86_l_48d1;
	case 18648ULL: goto x86_l_48d8;
	case 18653ULL: goto x86_l_48dd;
	case 18658ULL: goto x86_l_48e2;
	case 18660ULL: goto x86_l_48e4;
	case 18664ULL: goto x86_l_48e8;
	case 18666ULL: goto x86_l_48ea;
	case 18668ULL: goto x86_l_48ec;
	case 18674ULL: goto x86_l_48f2;
	case 18677ULL: goto x86_l_48f5;
	case 18683ULL: goto x86_l_48fb;
	case 18689ULL: goto x86_l_4901;
	case 18694ULL: goto x86_l_4906;
	case 18698ULL: goto x86_l_490a;
	case 18705ULL: goto x86_l_4911;
	case 18710ULL: goto x86_l_4916;
	case 18715ULL: goto x86_l_491b;
	case 18720ULL: goto x86_l_4920;
	case 18728ULL: goto x86_l_4928;
	case 18732ULL: goto x86_l_492c;
	case 18739ULL: goto x86_l_4933;
	case 18744ULL: goto x86_l_4938;
	case 18746ULL: goto x86_l_493a;
	case 18751ULL: goto x86_l_493f;
	case 18759ULL: goto x86_l_4947;
	case 18762ULL: goto x86_l_494a;
	case 18770ULL: goto x86_l_4952;
	case 18779ULL: goto x86_l_495b;
	case 18786ULL: goto x86_l_4962;
	case 18791ULL: goto x86_l_4967;
	case 18796ULL: goto x86_l_496c;
	case 18801ULL: goto x86_l_4971;
	case 18806ULL: goto x86_l_4976;
	case 18808ULL: goto x86_l_4978;
	case 18813ULL: goto x86_l_497d;
	case 18815ULL: goto x86_l_497f;
	case 18818ULL: goto x86_l_4982;
	case 18824ULL: goto x86_l_4988;
	case 18827ULL: goto x86_l_498b;
	case 18833ULL: goto x86_l_4991;
	case 18839ULL: goto x86_l_4997;
	case 18844ULL: goto x86_l_499c;
	case 18848ULL: goto x86_l_49a0;
	case 18855ULL: goto x86_l_49a7;
	case 18860ULL: goto x86_l_49ac;
	case 18865ULL: goto x86_l_49b1;
	case 18872ULL: goto x86_l_49b8;
	case 18875ULL: goto x86_l_49bb;
	case 18882ULL: goto x86_l_49c2;
	case 18887ULL: goto x86_l_49c7;
	case 18892ULL: goto x86_l_49cc;
	case 18894ULL: goto x86_l_49ce;
	case 18898ULL: goto x86_l_49d2;
	case 18900ULL: goto x86_l_49d4;
	case 18902ULL: goto x86_l_49d6;
	case 18908ULL: goto x86_l_49dc;
	case 18911ULL: goto x86_l_49df;
	case 18917ULL: goto x86_l_49e5;
	case 18923ULL: goto x86_l_49eb;
	case 18928ULL: goto x86_l_49f0;
	case 18932ULL: goto x86_l_49f4;
	case 18939ULL: goto x86_l_49fb;
	case 18944ULL: goto x86_l_4a00;
	case 18949ULL: goto x86_l_4a05;
	case 18954ULL: goto x86_l_4a0a;
	case 18962ULL: goto x86_l_4a12;
	case 18966ULL: goto x86_l_4a16;
	case 18973ULL: goto x86_l_4a1d;
	case 18978ULL: goto x86_l_4a22;
	case 18980ULL: goto x86_l_4a24;
	case 18985ULL: goto x86_l_4a29;
	case 18993ULL: goto x86_l_4a31;
	case 18996ULL: goto x86_l_4a34;
	case 19004ULL: goto x86_l_4a3c;
	case 19013ULL: goto x86_l_4a45;
	case 19020ULL: goto x86_l_4a4c;
	case 19025ULL: goto x86_l_4a51;
	case 19030ULL: goto x86_l_4a56;
	case 19035ULL: goto x86_l_4a5b;
	case 19040ULL: goto x86_l_4a60;
	case 19042ULL: goto x86_l_4a62;
	case 19047ULL: goto x86_l_4a67;
	case 19049ULL: goto x86_l_4a69;
	case 19052ULL: goto x86_l_4a6c;
	case 19058ULL: goto x86_l_4a72;
	case 19061ULL: goto x86_l_4a75;
	case 19067ULL: goto x86_l_4a7b;
	case 19073ULL: goto x86_l_4a81;
	case 19078ULL: goto x86_l_4a86;
	case 19082ULL: goto x86_l_4a8a;
	case 19089ULL: goto x86_l_4a91;
	case 19094ULL: goto x86_l_4a96;
	case 19099ULL: goto x86_l_4a9b;
	case 19106ULL: goto x86_l_4aa2;
	case 19109ULL: goto x86_l_4aa5;
	case 19116ULL: goto x86_l_4aac;
	case 19121ULL: goto x86_l_4ab1;
	case 19126ULL: goto x86_l_4ab6;
	case 19128ULL: goto x86_l_4ab8;
	case 19132ULL: goto x86_l_4abc;
	case 19134ULL: goto x86_l_4abe;
	case 19136ULL: goto x86_l_4ac0;
	case 19142ULL: goto x86_l_4ac6;
	case 19145ULL: goto x86_l_4ac9;
	case 19151ULL: goto x86_l_4acf;
	case 19157ULL: goto x86_l_4ad5;
	case 19162ULL: goto x86_l_4ada;
	case 19166ULL: goto x86_l_4ade;
	case 19173ULL: goto x86_l_4ae5;
	case 19178ULL: goto x86_l_4aea;
	case 19183ULL: goto x86_l_4aef;
	case 19188ULL: goto x86_l_4af4;
	case 19196ULL: goto x86_l_4afc;
	case 19200ULL: goto x86_l_4b00;
	case 19207ULL: goto x86_l_4b07;
	case 19212ULL: goto x86_l_4b0c;
	case 19214ULL: goto x86_l_4b0e;
	case 19219ULL: goto x86_l_4b13;
	case 19227ULL: goto x86_l_4b1b;
	case 19230ULL: goto x86_l_4b1e;
	case 19238ULL: goto x86_l_4b26;
	case 19247ULL: goto x86_l_4b2f;
	case 19254ULL: goto x86_l_4b36;
	case 19259ULL: goto x86_l_4b3b;
	case 19264ULL: goto x86_l_4b40;
	case 19269ULL: goto x86_l_4b45;
	case 19274ULL: goto x86_l_4b4a;
	case 19276ULL: goto x86_l_4b4c;
	case 19281ULL: goto x86_l_4b51;
	case 19283ULL: goto x86_l_4b53;
	case 19286ULL: goto x86_l_4b56;
	case 19292ULL: goto x86_l_4b5c;
	case 19295ULL: goto x86_l_4b5f;
	case 19301ULL: goto x86_l_4b65;
	case 19307ULL: goto x86_l_4b6b;
	case 19312ULL: goto x86_l_4b70;
	case 19316ULL: goto x86_l_4b74;
	case 19323ULL: goto x86_l_4b7b;
	case 19328ULL: goto x86_l_4b80;
	case 19333ULL: goto x86_l_4b85;
	case 19340ULL: goto x86_l_4b8c;
	case 19343ULL: goto x86_l_4b8f;
	case 19350ULL: goto x86_l_4b96;
	case 19355ULL: goto x86_l_4b9b;
	case 19360ULL: goto x86_l_4ba0;
	case 19362ULL: goto x86_l_4ba2;
	case 19366ULL: goto x86_l_4ba6;
	case 19368ULL: goto x86_l_4ba8;
	case 19370ULL: goto x86_l_4baa;
	case 19376ULL: goto x86_l_4bb0;
	case 19379ULL: goto x86_l_4bb3;
	case 19385ULL: goto x86_l_4bb9;
	case 19391ULL: goto x86_l_4bbf;
	case 19396ULL: goto x86_l_4bc4;
	case 19400ULL: goto x86_l_4bc8;
	case 19407ULL: goto x86_l_4bcf;
	case 19412ULL: goto x86_l_4bd4;
	case 19417ULL: goto x86_l_4bd9;
	case 19422ULL: goto x86_l_4bde;
	case 19430ULL: goto x86_l_4be6;
	case 19434ULL: goto x86_l_4bea;
	case 19441ULL: goto x86_l_4bf1;
	case 19446ULL: goto x86_l_4bf6;
	case 19448ULL: goto x86_l_4bf8;
	case 19453ULL: goto x86_l_4bfd;
	case 19461ULL: goto x86_l_4c05;
	case 19464ULL: goto x86_l_4c08;
	case 19472ULL: goto x86_l_4c10;
	case 19481ULL: goto x86_l_4c19;
	case 19488ULL: goto x86_l_4c20;
	case 19493ULL: goto x86_l_4c25;
	case 19498ULL: goto x86_l_4c2a;
	case 19503ULL: goto x86_l_4c2f;
	case 19508ULL: goto x86_l_4c34;
	case 19510ULL: goto x86_l_4c36;
	case 19515ULL: goto x86_l_4c3b;
	case 19517ULL: goto x86_l_4c3d;
	case 19520ULL: goto x86_l_4c40;
	case 19526ULL: goto x86_l_4c46;
	case 19529ULL: goto x86_l_4c49;
	case 19535ULL: goto x86_l_4c4f;
	case 19541ULL: goto x86_l_4c55;
	case 19546ULL: goto x86_l_4c5a;
	case 19550ULL: goto x86_l_4c5e;
	case 19557ULL: goto x86_l_4c65;
	case 19562ULL: goto x86_l_4c6a;
	case 19567ULL: goto x86_l_4c6f;
	case 19574ULL: goto x86_l_4c76;
	case 19577ULL: goto x86_l_4c79;
	case 19584ULL: goto x86_l_4c80;
	case 19589ULL: goto x86_l_4c85;
	case 19594ULL: goto x86_l_4c8a;
	case 19596ULL: goto x86_l_4c8c;
	case 19600ULL: goto x86_l_4c90;
	case 19602ULL: goto x86_l_4c92;
	case 19604ULL: goto x86_l_4c94;
	case 19610ULL: goto x86_l_4c9a;
	case 19613ULL: goto x86_l_4c9d;
	case 19619ULL: goto x86_l_4ca3;
	case 19625ULL: goto x86_l_4ca9;
	case 19630ULL: goto x86_l_4cae;
	case 19634ULL: goto x86_l_4cb2;
	case 19641ULL: goto x86_l_4cb9;
	case 19646ULL: goto x86_l_4cbe;
	case 19651ULL: goto x86_l_4cc3;
	case 19656ULL: goto x86_l_4cc8;
	case 19664ULL: goto x86_l_4cd0;
	case 19668ULL: goto x86_l_4cd4;
	case 19675ULL: goto x86_l_4cdb;
	case 19680ULL: goto x86_l_4ce0;
	case 19682ULL: goto x86_l_4ce2;
	case 19687ULL: goto x86_l_4ce7;
	case 19695ULL: goto x86_l_4cef;
	case 19698ULL: goto x86_l_4cf2;
	case 19706ULL: goto x86_l_4cfa;
	case 19715ULL: goto x86_l_4d03;
	case 19722ULL: goto x86_l_4d0a;
	case 19727ULL: goto x86_l_4d0f;
	case 19732ULL: goto x86_l_4d14;
	case 19737ULL: goto x86_l_4d19;
	case 19742ULL: goto x86_l_4d1e;
	case 19744ULL: goto x86_l_4d20;
	case 19749ULL: goto x86_l_4d25;
	case 19751ULL: goto x86_l_4d27;
	case 19754ULL: goto x86_l_4d2a;
	case 19760ULL: goto x86_l_4d30;
	case 19763ULL: goto x86_l_4d33;
	case 19769ULL: goto x86_l_4d39;
	case 19775ULL: goto x86_l_4d3f;
	case 19780ULL: goto x86_l_4d44;
	case 19784ULL: goto x86_l_4d48;
	case 19791ULL: goto x86_l_4d4f;
	case 19796ULL: goto x86_l_4d54;
	case 19801ULL: goto x86_l_4d59;
	case 19808ULL: goto x86_l_4d60;
	case 19811ULL: goto x86_l_4d63;
	case 19818ULL: goto x86_l_4d6a;
	case 19823ULL: goto x86_l_4d6f;
	case 19828ULL: goto x86_l_4d74;
	case 19830ULL: goto x86_l_4d76;
	case 19834ULL: goto x86_l_4d7a;
	case 19836ULL: goto x86_l_4d7c;
	case 19838ULL: goto x86_l_4d7e;
	case 19844ULL: goto x86_l_4d84;
	case 19847ULL: goto x86_l_4d87;
	case 19853ULL: goto x86_l_4d8d;
	case 19859ULL: goto x86_l_4d93;
	case 19864ULL: goto x86_l_4d98;
	case 19868ULL: goto x86_l_4d9c;
	case 19875ULL: goto x86_l_4da3;
	case 19880ULL: goto x86_l_4da8;
	case 19885ULL: goto x86_l_4dad;
	case 19890ULL: goto x86_l_4db2;
	case 19898ULL: goto x86_l_4dba;
	case 19902ULL: goto x86_l_4dbe;
	case 19909ULL: goto x86_l_4dc5;
	case 19914ULL: goto x86_l_4dca;
	case 19916ULL: goto x86_l_4dcc;
	case 19921ULL: goto x86_l_4dd1;
	case 19929ULL: goto x86_l_4dd9;
	case 19932ULL: goto x86_l_4ddc;
	case 19940ULL: goto x86_l_4de4;
	case 19949ULL: goto x86_l_4ded;
	case 19956ULL: goto x86_l_4df4;
	case 19961ULL: goto x86_l_4df9;
	case 19966ULL: goto x86_l_4dfe;
	case 19971ULL: goto x86_l_4e03;
	case 19976ULL: goto x86_l_4e08;
	case 19978ULL: goto x86_l_4e0a;
	case 19983ULL: goto x86_l_4e0f;
	case 19985ULL: goto x86_l_4e11;
	case 19988ULL: goto x86_l_4e14;
	case 19994ULL: goto x86_l_4e1a;
	case 19997ULL: goto x86_l_4e1d;
	case 20003ULL: goto x86_l_4e23;
	case 20009ULL: goto x86_l_4e29;
	case 20014ULL: goto x86_l_4e2e;
	case 20018ULL: goto x86_l_4e32;
	case 20025ULL: goto x86_l_4e39;
	case 20030ULL: goto x86_l_4e3e;
	case 20035ULL: goto x86_l_4e43;
	case 20042ULL: goto x86_l_4e4a;
	case 20045ULL: goto x86_l_4e4d;
	case 20052ULL: goto x86_l_4e54;
	case 20057ULL: goto x86_l_4e59;
	case 20062ULL: goto x86_l_4e5e;
	case 20064ULL: goto x86_l_4e60;
	case 20068ULL: goto x86_l_4e64;
	case 20070ULL: goto x86_l_4e66;
	case 20072ULL: goto x86_l_4e68;
	case 20078ULL: goto x86_l_4e6e;
	case 20081ULL: goto x86_l_4e71;
	case 20087ULL: goto x86_l_4e77;
	case 20093ULL: goto x86_l_4e7d;
	case 20098ULL: goto x86_l_4e82;
	case 20102ULL: goto x86_l_4e86;
	case 20109ULL: goto x86_l_4e8d;
	case 20114ULL: goto x86_l_4e92;
	case 20119ULL: goto x86_l_4e97;
	case 20124ULL: goto x86_l_4e9c;
	case 20132ULL: goto x86_l_4ea4;
	case 20136ULL: goto x86_l_4ea8;
	case 20143ULL: goto x86_l_4eaf;
	case 20148ULL: goto x86_l_4eb4;
	case 20150ULL: goto x86_l_4eb6;
	case 20155ULL: goto x86_l_4ebb;
	case 20163ULL: goto x86_l_4ec3;
	case 20166ULL: goto x86_l_4ec6;
	case 20174ULL: goto x86_l_4ece;
	case 20183ULL: goto x86_l_4ed7;
	case 20190ULL: goto x86_l_4ede;
	case 20195ULL: goto x86_l_4ee3;
	case 20200ULL: goto x86_l_4ee8;
	case 20205ULL: goto x86_l_4eed;
	case 20210ULL: goto x86_l_4ef2;
	case 20212ULL: goto x86_l_4ef4;
	case 20217ULL: goto x86_l_4ef9;
	case 20219ULL: goto x86_l_4efb;
	case 20222ULL: goto x86_l_4efe;
	case 20228ULL: goto x86_l_4f04;
	case 20231ULL: goto x86_l_4f07;
	case 20237ULL: goto x86_l_4f0d;
	case 20243ULL: goto x86_l_4f13;
	case 20248ULL: goto x86_l_4f18;
	case 20252ULL: goto x86_l_4f1c;
	case 20259ULL: goto x86_l_4f23;
	case 20264ULL: goto x86_l_4f28;
	case 20269ULL: goto x86_l_4f2d;
	case 20276ULL: goto x86_l_4f34;
	case 20279ULL: goto x86_l_4f37;
	case 20286ULL: goto x86_l_4f3e;
	case 20291ULL: goto x86_l_4f43;
	case 20296ULL: goto x86_l_4f48;
	case 20298ULL: goto x86_l_4f4a;
	case 20302ULL: goto x86_l_4f4e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_47dd:
	/* 0x47dd: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_47e4:
	/* 0x47e4: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_47e7:
	/* 0x47e7: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_47ee:
	/* 0x47ee: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47f3:
	/* 0x47f3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_47f8:
	/* 0x47f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47fa:
	/* 0x47fa: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_47fe:
	/* 0x47fe: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_4800:
	/* 0x4800: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4802:
	/* 0x4802: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_4808:
	/* 0x4808: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_480b:
	/* 0x480b: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4811:
	/* 0x4811: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4817:
	/* 0x4817: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_481c:
	/* 0x481c: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4820:
	/* 0x4820: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4827:
	/* 0x4827: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_482c:
	/* 0x482c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4831:
	/* 0x4831: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4836:
	/* 0x4836: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_483e:
	/* 0x483e: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4842:
	/* 0x4842: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4849:
	/* 0x4849: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_484e:
	/* 0x484e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4850:
	/* 0x4850: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4855:
	/* 0x4855: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_485d:
	/* 0x485d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4860:
	/* 0x4860: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4868:
	/* 0x4868: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4871:
	/* 0x4871: lea    rdx,[r13+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_4878:
	/* 0x4878: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_487d:
	/* 0x487d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4882:
	/* 0x4882: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4887:
	/* 0x4887: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_488c:
	/* 0x488c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_488e:
	/* 0x488e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4893:
	/* 0x4893: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_4895:
	/* 0x4895: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4898:
	/* 0x4898: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_489e:
	/* 0x489e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_48a1:
	/* 0x48a1: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_48a7:
	/* 0x48a7: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_48ad:
	/* 0x48ad: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48b2:
	/* 0x48b2: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_48b6:
	/* 0x48b6: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_48bd:
	/* 0x48bd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_48c2:
	/* 0x48c2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_48c7:
	/* 0x48c7: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_48ce:
	/* 0x48ce: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_48d1:
	/* 0x48d1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_48d8:
	/* 0x48d8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48dd:
	/* 0x48dd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_48e2:
	/* 0x48e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48e4:
	/* 0x48e4: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_48e8:
	/* 0x48e8: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_48ea:
	/* 0x48ea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48ec:
	/* 0x48ec: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_48f2:
	/* 0x48f2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_48f5:
	/* 0x48f5: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_48fb:
	/* 0x48fb: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4901:
	/* 0x4901: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4906:
	/* 0x4906: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_490a:
	/* 0x490a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4911:
	/* 0x4911: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4916:
	/* 0x4916: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_491b:
	/* 0x491b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4920:
	/* 0x4920: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4928:
	/* 0x4928: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_492c:
	/* 0x492c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4933:
	/* 0x4933: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4938:
	/* 0x4938: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_493a:
	/* 0x493a: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_493f:
	/* 0x493f: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4947:
	/* 0x4947: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_494a:
	/* 0x494a: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4952:
	/* 0x4952: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_495b:
	/* 0x495b: lea    rdx,[r13+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_4962:
	/* 0x4962: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4967:
	/* 0x4967: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_496c:
	/* 0x496c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4971:
	/* 0x4971: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4976:
	/* 0x4976: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4978:
	/* 0x4978: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_497d:
	/* 0x497d: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_497f:
	/* 0x497f: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4982:
	/* 0x4982: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_4988:
	/* 0x4988: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_498b:
	/* 0x498b: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4991:
	/* 0x4991: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4997:
	/* 0x4997: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_499c:
	/* 0x499c: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_49a0:
	/* 0x49a0: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_49a7:
	/* 0x49a7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_49ac:
	/* 0x49ac: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_49b1:
	/* 0x49b1: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_49b8:
	/* 0x49b8: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_49bb:
	/* 0x49bb: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_49c2:
	/* 0x49c2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_49c7:
	/* 0x49c7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_49cc:
	/* 0x49cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49ce:
	/* 0x49ce: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_49d2:
	/* 0x49d2: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_49d4:
	/* 0x49d4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_49d6:
	/* 0x49d6: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_49dc:
	/* 0x49dc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_49df:
	/* 0x49df: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_49e5:
	/* 0x49e5: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_49eb:
	/* 0x49eb: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49f0:
	/* 0x49f0: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_49f4:
	/* 0x49f4: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_49fb:
	/* 0x49fb: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4a00:
	/* 0x4a00: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4a05:
	/* 0x4a05: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4a0a:
	/* 0x4a0a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4a12:
	/* 0x4a12: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4a16:
	/* 0x4a16: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4a1d:
	/* 0x4a1d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4a22:
	/* 0x4a22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a24:
	/* 0x4a24: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4a29:
	/* 0x4a29: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4a31:
	/* 0x4a31: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4a34:
	/* 0x4a34: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4a3c:
	/* 0x4a3c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4a45:
	/* 0x4a45: lea    rdx,[r13+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_4a4c:
	/* 0x4a4c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a51:
	/* 0x4a51: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4a56:
	/* 0x4a56: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4a5b:
	/* 0x4a5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a60:
	/* 0x4a60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a62:
	/* 0x4a62: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a67:
	/* 0x4a67: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_4a69:
	/* 0x4a69: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4a6c:
	/* 0x4a6c: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_4a72:
	/* 0x4a72: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4a75:
	/* 0x4a75: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4a7b:
	/* 0x4a7b: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4a81:
	/* 0x4a81: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a86:
	/* 0x4a86: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4a8a:
	/* 0x4a8a: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4a91:
	/* 0x4a91: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4a96:
	/* 0x4a96: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4a9b:
	/* 0x4a9b: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4aa2:
	/* 0x4aa2: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4aa5:
	/* 0x4aa5: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4aac:
	/* 0x4aac: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ab1:
	/* 0x4ab1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4ab6:
	/* 0x4ab6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ab8:
	/* 0x4ab8: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4abc:
	/* 0x4abc: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_4abe:
	/* 0x4abe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ac0:
	/* 0x4ac0: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_4ac6:
	/* 0x4ac6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4ac9:
	/* 0x4ac9: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4acf:
	/* 0x4acf: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4ad5:
	/* 0x4ad5: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ada:
	/* 0x4ada: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4ade:
	/* 0x4ade: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4ae5:
	/* 0x4ae5: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4aea:
	/* 0x4aea: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4aef:
	/* 0x4aef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4af4:
	/* 0x4af4: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4afc:
	/* 0x4afc: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4b00:
	/* 0x4b00: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4b07:
	/* 0x4b07: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4b0c:
	/* 0x4b0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b0e:
	/* 0x4b0e: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4b13:
	/* 0x4b13: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4b1b:
	/* 0x4b1b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4b1e:
	/* 0x4b1e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4b26:
	/* 0x4b26: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4b2f:
	/* 0x4b2f: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_4b36:
	/* 0x4b36: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b3b:
	/* 0x4b3b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4b40:
	/* 0x4b40: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4b45:
	/* 0x4b45: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b4a:
	/* 0x4b4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b4c:
	/* 0x4b4c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b51:
	/* 0x4b51: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_4b53:
	/* 0x4b53: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4b56:
	/* 0x4b56: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_4b5c:
	/* 0x4b5c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4b5f:
	/* 0x4b5f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4b65:
	/* 0x4b65: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4b6b:
	/* 0x4b6b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b70:
	/* 0x4b70: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4b74:
	/* 0x4b74: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4b7b:
	/* 0x4b7b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4b80:
	/* 0x4b80: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4b85:
	/* 0x4b85: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4b8c:
	/* 0x4b8c: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4b8f:
	/* 0x4b8f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4b96:
	/* 0x4b96: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b9b:
	/* 0x4b9b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4ba0:
	/* 0x4ba0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ba2:
	/* 0x4ba2: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4ba6:
	/* 0x4ba6: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_4ba8:
	/* 0x4ba8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4baa:
	/* 0x4baa: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_4bb0:
	/* 0x4bb0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4bb3:
	/* 0x4bb3: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4bb9:
	/* 0x4bb9: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4bbf:
	/* 0x4bbf: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bc4:
	/* 0x4bc4: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4bc8:
	/* 0x4bc8: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4bcf:
	/* 0x4bcf: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4bd4:
	/* 0x4bd4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4bd9:
	/* 0x4bd9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4bde:
	/* 0x4bde: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4be6:
	/* 0x4be6: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4bea:
	/* 0x4bea: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4bf1:
	/* 0x4bf1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4bf6:
	/* 0x4bf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bf8:
	/* 0x4bf8: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4bfd:
	/* 0x4bfd: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4c05:
	/* 0x4c05: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4c08:
	/* 0x4c08: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4c10:
	/* 0x4c10: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4c19:
	/* 0x4c19: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_4c20:
	/* 0x4c20: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c25:
	/* 0x4c25: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4c2a:
	/* 0x4c2a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4c2f:
	/* 0x4c2f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c34:
	/* 0x4c34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c36:
	/* 0x4c36: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c3b:
	/* 0x4c3b: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_4c3d:
	/* 0x4c3d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4c40:
	/* 0x4c40: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_4c46:
	/* 0x4c46: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4c49:
	/* 0x4c49: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4c4f:
	/* 0x4c4f: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4c55:
	/* 0x4c55: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c5a:
	/* 0x4c5a: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4c5e:
	/* 0x4c5e: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4c65:
	/* 0x4c65: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4c6a:
	/* 0x4c6a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4c6f:
	/* 0x4c6f: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4c76:
	/* 0x4c76: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4c79:
	/* 0x4c79: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4c80:
	/* 0x4c80: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c85:
	/* 0x4c85: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4c8a:
	/* 0x4c8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c8c:
	/* 0x4c8c: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4c90:
	/* 0x4c90: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_4c92:
	/* 0x4c92: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c94:
	/* 0x4c94: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_4c9a:
	/* 0x4c9a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4c9d:
	/* 0x4c9d: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4ca3:
	/* 0x4ca3: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4ca9:
	/* 0x4ca9: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cae:
	/* 0x4cae: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4cb2:
	/* 0x4cb2: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4cb9:
	/* 0x4cb9: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4cbe:
	/* 0x4cbe: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4cc3:
	/* 0x4cc3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4cc8:
	/* 0x4cc8: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4cd0:
	/* 0x4cd0: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4cd4:
	/* 0x4cd4: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4cdb:
	/* 0x4cdb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4ce0:
	/* 0x4ce0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ce2:
	/* 0x4ce2: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4ce7:
	/* 0x4ce7: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4cef:
	/* 0x4cef: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4cf2:
	/* 0x4cf2: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4cfa:
	/* 0x4cfa: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4d03:
	/* 0x4d03: lea    rdx,[r13+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_4d0a:
	/* 0x4d0a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d0f:
	/* 0x4d0f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4d14:
	/* 0x4d14: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4d19:
	/* 0x4d19: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d1e:
	/* 0x4d1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d20:
	/* 0x4d20: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d25:
	/* 0x4d25: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_4d27:
	/* 0x4d27: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4d2a:
	/* 0x4d2a: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_4d30:
	/* 0x4d30: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4d33:
	/* 0x4d33: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4d39:
	/* 0x4d39: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4d3f:
	/* 0x4d3f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d44:
	/* 0x4d44: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4d48:
	/* 0x4d48: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4d4f:
	/* 0x4d4f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4d54:
	/* 0x4d54: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4d59:
	/* 0x4d59: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4d60:
	/* 0x4d60: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4d63:
	/* 0x4d63: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4d6a:
	/* 0x4d6a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d6f:
	/* 0x4d6f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4d74:
	/* 0x4d74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d76:
	/* 0x4d76: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4d7a:
	/* 0x4d7a: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_4d7c:
	/* 0x4d7c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d7e:
	/* 0x4d7e: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_4d84:
	/* 0x4d84: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4d87:
	/* 0x4d87: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4d8d:
	/* 0x4d8d: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4d93:
	/* 0x4d93: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d98:
	/* 0x4d98: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4d9c:
	/* 0x4d9c: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4da3:
	/* 0x4da3: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4da8:
	/* 0x4da8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4dad:
	/* 0x4dad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4db2:
	/* 0x4db2: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4dba:
	/* 0x4dba: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4dbe:
	/* 0x4dbe: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4dc5:
	/* 0x4dc5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4dca:
	/* 0x4dca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dcc:
	/* 0x4dcc: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4dd1:
	/* 0x4dd1: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4dd9:
	/* 0x4dd9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4ddc:
	/* 0x4ddc: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4de4:
	/* 0x4de4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4ded:
	/* 0x4ded: lea    rdx,[r13+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_4df4:
	/* 0x4df4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4df9:
	/* 0x4df9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4dfe:
	/* 0x4dfe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4e03:
	/* 0x4e03: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e08:
	/* 0x4e08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e0a:
	/* 0x4e0a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e0f:
	/* 0x4e0f: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_4e11:
	/* 0x4e11: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4e14:
	/* 0x4e14: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_4e1a:
	/* 0x4e1a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4e1d:
	/* 0x4e1d: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4e23:
	/* 0x4e23: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4e29:
	/* 0x4e29: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e2e:
	/* 0x4e2e: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4e32:
	/* 0x4e32: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4e39:
	/* 0x4e39: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4e3e:
	/* 0x4e3e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4e43:
	/* 0x4e43: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4e4a:
	/* 0x4e4a: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4e4d:
	/* 0x4e4d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4e54:
	/* 0x4e54: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e59:
	/* 0x4e59: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4e5e:
	/* 0x4e5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e60:
	/* 0x4e60: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4e64:
	/* 0x4e64: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_4e66:
	/* 0x4e66: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e68:
	/* 0x4e68: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_4e6e:
	/* 0x4e6e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4e71:
	/* 0x4e71: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4e77:
	/* 0x4e77: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4e7d:
	/* 0x4e7d: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e82:
	/* 0x4e82: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4e86:
	/* 0x4e86: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4e8d:
	/* 0x4e8d: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4e92:
	/* 0x4e92: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4e97:
	/* 0x4e97: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4e9c:
	/* 0x4e9c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4ea4:
	/* 0x4ea4: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4ea8:
	/* 0x4ea8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4eaf:
	/* 0x4eaf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4eb4:
	/* 0x4eb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4eb6:
	/* 0x4eb6: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4ebb:
	/* 0x4ebb: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4ec3:
	/* 0x4ec3: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4ec6:
	/* 0x4ec6: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4ece:
	/* 0x4ece: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4ed7:
	/* 0x4ed7: lea    rdx,[r13+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_4ede:
	/* 0x4ede: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ee3:
	/* 0x4ee3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4ee8:
	/* 0x4ee8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4eed:
	/* 0x4eed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ef2:
	/* 0x4ef2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ef4:
	/* 0x4ef4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ef9:
	/* 0x4ef9: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_4efb:
	/* 0x4efb: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4efe:
	/* 0x4efe: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_4f04:
	/* 0x4f04: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4f07:
	/* 0x4f07: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4f0d:
	/* 0x4f0d: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4f13:
	/* 0x4f13: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f18:
	/* 0x4f18: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4f1c:
	/* 0x4f1c: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4f23:
	/* 0x4f23: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4f28:
	/* 0x4f28: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4f2d:
	/* 0x4f2d: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4f34:
	/* 0x4f34: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4f37:
	/* 0x4f37: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4f3e:
	/* 0x4f3e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f43:
	/* 0x4f43: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4f48:
	/* 0x4f48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f4a:
	/* 0x4f4a: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4f4e:
	/* 0x4f4e: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
	return 20304ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 20304ULL: goto x86_l_4f50;
	case 20306ULL: goto x86_l_4f52;
	case 20312ULL: goto x86_l_4f58;
	case 20315ULL: goto x86_l_4f5b;
	case 20321ULL: goto x86_l_4f61;
	case 20327ULL: goto x86_l_4f67;
	case 20332ULL: goto x86_l_4f6c;
	case 20336ULL: goto x86_l_4f70;
	case 20343ULL: goto x86_l_4f77;
	case 20348ULL: goto x86_l_4f7c;
	case 20353ULL: goto x86_l_4f81;
	case 20358ULL: goto x86_l_4f86;
	case 20366ULL: goto x86_l_4f8e;
	case 20370ULL: goto x86_l_4f92;
	case 20377ULL: goto x86_l_4f99;
	case 20382ULL: goto x86_l_4f9e;
	case 20384ULL: goto x86_l_4fa0;
	case 20389ULL: goto x86_l_4fa5;
	case 20397ULL: goto x86_l_4fad;
	case 20400ULL: goto x86_l_4fb0;
	case 20408ULL: goto x86_l_4fb8;
	case 20417ULL: goto x86_l_4fc1;
	case 20424ULL: goto x86_l_4fc8;
	case 20429ULL: goto x86_l_4fcd;
	case 20434ULL: goto x86_l_4fd2;
	case 20439ULL: goto x86_l_4fd7;
	case 20444ULL: goto x86_l_4fdc;
	case 20446ULL: goto x86_l_4fde;
	case 20451ULL: goto x86_l_4fe3;
	case 20453ULL: goto x86_l_4fe5;
	case 20456ULL: goto x86_l_4fe8;
	case 20462ULL: goto x86_l_4fee;
	case 20465ULL: goto x86_l_4ff1;
	case 20471ULL: goto x86_l_4ff7;
	case 20477ULL: goto x86_l_4ffd;
	case 20482ULL: goto x86_l_5002;
	case 20486ULL: goto x86_l_5006;
	case 20493ULL: goto x86_l_500d;
	case 20498ULL: goto x86_l_5012;
	case 20503ULL: goto x86_l_5017;
	case 20510ULL: goto x86_l_501e;
	case 20513ULL: goto x86_l_5021;
	case 20520ULL: goto x86_l_5028;
	case 20525ULL: goto x86_l_502d;
	case 20530ULL: goto x86_l_5032;
	case 20532ULL: goto x86_l_5034;
	case 20536ULL: goto x86_l_5038;
	case 20538ULL: goto x86_l_503a;
	case 20540ULL: goto x86_l_503c;
	case 20546ULL: goto x86_l_5042;
	case 20549ULL: goto x86_l_5045;
	case 20555ULL: goto x86_l_504b;
	case 20561ULL: goto x86_l_5051;
	case 20566ULL: goto x86_l_5056;
	case 20570ULL: goto x86_l_505a;
	case 20577ULL: goto x86_l_5061;
	case 20582ULL: goto x86_l_5066;
	case 20587ULL: goto x86_l_506b;
	case 20592ULL: goto x86_l_5070;
	case 20600ULL: goto x86_l_5078;
	case 20604ULL: goto x86_l_507c;
	case 20611ULL: goto x86_l_5083;
	case 20616ULL: goto x86_l_5088;
	case 20618ULL: goto x86_l_508a;
	case 20623ULL: goto x86_l_508f;
	case 20631ULL: goto x86_l_5097;
	case 20634ULL: goto x86_l_509a;
	case 20642ULL: goto x86_l_50a2;
	case 20651ULL: goto x86_l_50ab;
	case 20658ULL: goto x86_l_50b2;
	case 20663ULL: goto x86_l_50b7;
	case 20668ULL: goto x86_l_50bc;
	case 20673ULL: goto x86_l_50c1;
	case 20678ULL: goto x86_l_50c6;
	case 20680ULL: goto x86_l_50c8;
	case 20685ULL: goto x86_l_50cd;
	case 20687ULL: goto x86_l_50cf;
	case 20690ULL: goto x86_l_50d2;
	case 20696ULL: goto x86_l_50d8;
	case 20699ULL: goto x86_l_50db;
	case 20705ULL: goto x86_l_50e1;
	case 20711ULL: goto x86_l_50e7;
	case 20716ULL: goto x86_l_50ec;
	case 20720ULL: goto x86_l_50f0;
	case 20727ULL: goto x86_l_50f7;
	case 20732ULL: goto x86_l_50fc;
	case 20737ULL: goto x86_l_5101;
	case 20744ULL: goto x86_l_5108;
	case 20747ULL: goto x86_l_510b;
	case 20754ULL: goto x86_l_5112;
	case 20759ULL: goto x86_l_5117;
	case 20764ULL: goto x86_l_511c;
	case 20766ULL: goto x86_l_511e;
	case 20770ULL: goto x86_l_5122;
	case 20772ULL: goto x86_l_5124;
	case 20774ULL: goto x86_l_5126;
	case 20780ULL: goto x86_l_512c;
	case 20783ULL: goto x86_l_512f;
	case 20789ULL: goto x86_l_5135;
	case 20795ULL: goto x86_l_513b;
	case 20800ULL: goto x86_l_5140;
	case 20804ULL: goto x86_l_5144;
	case 20811ULL: goto x86_l_514b;
	case 20816ULL: goto x86_l_5150;
	case 20821ULL: goto x86_l_5155;
	case 20826ULL: goto x86_l_515a;
	case 20834ULL: goto x86_l_5162;
	case 20838ULL: goto x86_l_5166;
	case 20845ULL: goto x86_l_516d;
	case 20850ULL: goto x86_l_5172;
	case 20852ULL: goto x86_l_5174;
	case 20857ULL: goto x86_l_5179;
	case 20865ULL: goto x86_l_5181;
	case 20868ULL: goto x86_l_5184;
	case 20876ULL: goto x86_l_518c;
	case 20885ULL: goto x86_l_5195;
	case 20892ULL: goto x86_l_519c;
	case 20897ULL: goto x86_l_51a1;
	case 20902ULL: goto x86_l_51a6;
	case 20907ULL: goto x86_l_51ab;
	case 20912ULL: goto x86_l_51b0;
	case 20914ULL: goto x86_l_51b2;
	case 20919ULL: goto x86_l_51b7;
	case 20921ULL: goto x86_l_51b9;
	case 20924ULL: goto x86_l_51bc;
	case 20930ULL: goto x86_l_51c2;
	case 20933ULL: goto x86_l_51c5;
	case 20939ULL: goto x86_l_51cb;
	case 20945ULL: goto x86_l_51d1;
	case 20950ULL: goto x86_l_51d6;
	case 20954ULL: goto x86_l_51da;
	case 20961ULL: goto x86_l_51e1;
	case 20966ULL: goto x86_l_51e6;
	case 20971ULL: goto x86_l_51eb;
	case 20978ULL: goto x86_l_51f2;
	case 20981ULL: goto x86_l_51f5;
	case 20988ULL: goto x86_l_51fc;
	case 20993ULL: goto x86_l_5201;
	case 20998ULL: goto x86_l_5206;
	case 21000ULL: goto x86_l_5208;
	case 21004ULL: goto x86_l_520c;
	case 21006ULL: goto x86_l_520e;
	case 21008ULL: goto x86_l_5210;
	case 21014ULL: goto x86_l_5216;
	case 21017ULL: goto x86_l_5219;
	case 21023ULL: goto x86_l_521f;
	case 21029ULL: goto x86_l_5225;
	case 21034ULL: goto x86_l_522a;
	case 21038ULL: goto x86_l_522e;
	case 21045ULL: goto x86_l_5235;
	case 21050ULL: goto x86_l_523a;
	case 21055ULL: goto x86_l_523f;
	case 21060ULL: goto x86_l_5244;
	case 21068ULL: goto x86_l_524c;
	case 21072ULL: goto x86_l_5250;
	case 21079ULL: goto x86_l_5257;
	case 21084ULL: goto x86_l_525c;
	case 21086ULL: goto x86_l_525e;
	case 21091ULL: goto x86_l_5263;
	case 21099ULL: goto x86_l_526b;
	case 21102ULL: goto x86_l_526e;
	case 21110ULL: goto x86_l_5276;
	case 21119ULL: goto x86_l_527f;
	case 21126ULL: goto x86_l_5286;
	case 21131ULL: goto x86_l_528b;
	case 21136ULL: goto x86_l_5290;
	case 21141ULL: goto x86_l_5295;
	case 21146ULL: goto x86_l_529a;
	case 21148ULL: goto x86_l_529c;
	case 21153ULL: goto x86_l_52a1;
	case 21155ULL: goto x86_l_52a3;
	case 21158ULL: goto x86_l_52a6;
	case 21164ULL: goto x86_l_52ac;
	case 21167ULL: goto x86_l_52af;
	case 21173ULL: goto x86_l_52b5;
	case 21179ULL: goto x86_l_52bb;
	case 21184ULL: goto x86_l_52c0;
	case 21188ULL: goto x86_l_52c4;
	case 21195ULL: goto x86_l_52cb;
	case 21200ULL: goto x86_l_52d0;
	case 21205ULL: goto x86_l_52d5;
	case 21212ULL: goto x86_l_52dc;
	case 21215ULL: goto x86_l_52df;
	case 21222ULL: goto x86_l_52e6;
	case 21227ULL: goto x86_l_52eb;
	case 21232ULL: goto x86_l_52f0;
	case 21234ULL: goto x86_l_52f2;
	case 21238ULL: goto x86_l_52f6;
	case 21240ULL: goto x86_l_52f8;
	case 21242ULL: goto x86_l_52fa;
	case 21248ULL: goto x86_l_5300;
	case 21251ULL: goto x86_l_5303;
	case 21257ULL: goto x86_l_5309;
	case 21263ULL: goto x86_l_530f;
	case 21268ULL: goto x86_l_5314;
	case 21272ULL: goto x86_l_5318;
	case 21279ULL: goto x86_l_531f;
	case 21284ULL: goto x86_l_5324;
	case 21289ULL: goto x86_l_5329;
	case 21294ULL: goto x86_l_532e;
	case 21302ULL: goto x86_l_5336;
	case 21306ULL: goto x86_l_533a;
	case 21313ULL: goto x86_l_5341;
	case 21318ULL: goto x86_l_5346;
	case 21320ULL: goto x86_l_5348;
	case 21325ULL: goto x86_l_534d;
	case 21333ULL: goto x86_l_5355;
	case 21336ULL: goto x86_l_5358;
	case 21344ULL: goto x86_l_5360;
	case 21353ULL: goto x86_l_5369;
	case 21360ULL: goto x86_l_5370;
	case 21365ULL: goto x86_l_5375;
	case 21370ULL: goto x86_l_537a;
	case 21375ULL: goto x86_l_537f;
	case 21380ULL: goto x86_l_5384;
	case 21382ULL: goto x86_l_5386;
	case 21387ULL: goto x86_l_538b;
	case 21389ULL: goto x86_l_538d;
	case 21392ULL: goto x86_l_5390;
	case 21398ULL: goto x86_l_5396;
	case 21401ULL: goto x86_l_5399;
	case 21407ULL: goto x86_l_539f;
	case 21413ULL: goto x86_l_53a5;
	case 21418ULL: goto x86_l_53aa;
	case 21422ULL: goto x86_l_53ae;
	case 21429ULL: goto x86_l_53b5;
	case 21434ULL: goto x86_l_53ba;
	case 21439ULL: goto x86_l_53bf;
	case 21446ULL: goto x86_l_53c6;
	case 21449ULL: goto x86_l_53c9;
	case 21456ULL: goto x86_l_53d0;
	case 21461ULL: goto x86_l_53d5;
	case 21466ULL: goto x86_l_53da;
	case 21468ULL: goto x86_l_53dc;
	case 21472ULL: goto x86_l_53e0;
	case 21474ULL: goto x86_l_53e2;
	case 21476ULL: goto x86_l_53e4;
	case 21482ULL: goto x86_l_53ea;
	case 21485ULL: goto x86_l_53ed;
	case 21491ULL: goto x86_l_53f3;
	case 21497ULL: goto x86_l_53f9;
	case 21502ULL: goto x86_l_53fe;
	case 21506ULL: goto x86_l_5402;
	case 21513ULL: goto x86_l_5409;
	case 21518ULL: goto x86_l_540e;
	case 21523ULL: goto x86_l_5413;
	case 21528ULL: goto x86_l_5418;
	case 21536ULL: goto x86_l_5420;
	case 21540ULL: goto x86_l_5424;
	case 21547ULL: goto x86_l_542b;
	case 21552ULL: goto x86_l_5430;
	case 21554ULL: goto x86_l_5432;
	case 21559ULL: goto x86_l_5437;
	case 21567ULL: goto x86_l_543f;
	case 21570ULL: goto x86_l_5442;
	case 21578ULL: goto x86_l_544a;
	case 21587ULL: goto x86_l_5453;
	case 21594ULL: goto x86_l_545a;
	case 21599ULL: goto x86_l_545f;
	case 21604ULL: goto x86_l_5464;
	case 21609ULL: goto x86_l_5469;
	case 21614ULL: goto x86_l_546e;
	case 21616ULL: goto x86_l_5470;
	case 21621ULL: goto x86_l_5475;
	case 21623ULL: goto x86_l_5477;
	case 21626ULL: goto x86_l_547a;
	case 21632ULL: goto x86_l_5480;
	case 21635ULL: goto x86_l_5483;
	case 21641ULL: goto x86_l_5489;
	case 21647ULL: goto x86_l_548f;
	case 21652ULL: goto x86_l_5494;
	case 21656ULL: goto x86_l_5498;
	case 21663ULL: goto x86_l_549f;
	case 21668ULL: goto x86_l_54a4;
	case 21673ULL: goto x86_l_54a9;
	case 21680ULL: goto x86_l_54b0;
	case 21683ULL: goto x86_l_54b3;
	case 21690ULL: goto x86_l_54ba;
	case 21695ULL: goto x86_l_54bf;
	case 21700ULL: goto x86_l_54c4;
	case 21702ULL: goto x86_l_54c6;
	case 21706ULL: goto x86_l_54ca;
	case 21708ULL: goto x86_l_54cc;
	case 21710ULL: goto x86_l_54ce;
	case 21716ULL: goto x86_l_54d4;
	case 21719ULL: goto x86_l_54d7;
	case 21725ULL: goto x86_l_54dd;
	case 21731ULL: goto x86_l_54e3;
	case 21736ULL: goto x86_l_54e8;
	case 21740ULL: goto x86_l_54ec;
	case 21747ULL: goto x86_l_54f3;
	case 21752ULL: goto x86_l_54f8;
	case 21757ULL: goto x86_l_54fd;
	case 21762ULL: goto x86_l_5502;
	case 21770ULL: goto x86_l_550a;
	case 21774ULL: goto x86_l_550e;
	case 21781ULL: goto x86_l_5515;
	case 21786ULL: goto x86_l_551a;
	case 21788ULL: goto x86_l_551c;
	case 21793ULL: goto x86_l_5521;
	case 21801ULL: goto x86_l_5529;
	case 21804ULL: goto x86_l_552c;
	case 21812ULL: goto x86_l_5534;
	case 21821ULL: goto x86_l_553d;
	case 21828ULL: goto x86_l_5544;
	case 21833ULL: goto x86_l_5549;
	case 21838ULL: goto x86_l_554e;
	case 21843ULL: goto x86_l_5553;
	case 21848ULL: goto x86_l_5558;
	case 21850ULL: goto x86_l_555a;
	case 21855ULL: goto x86_l_555f;
	case 21857ULL: goto x86_l_5561;
	case 21860ULL: goto x86_l_5564;
	case 21866ULL: goto x86_l_556a;
	case 21869ULL: goto x86_l_556d;
	case 21875ULL: goto x86_l_5573;
	case 21881ULL: goto x86_l_5579;
	case 21886ULL: goto x86_l_557e;
	case 21890ULL: goto x86_l_5582;
	case 21897ULL: goto x86_l_5589;
	case 21902ULL: goto x86_l_558e;
	case 21907ULL: goto x86_l_5593;
	case 21914ULL: goto x86_l_559a;
	case 21917ULL: goto x86_l_559d;
	case 21924ULL: goto x86_l_55a4;
	case 21929ULL: goto x86_l_55a9;
	case 21934ULL: goto x86_l_55ae;
	case 21936ULL: goto x86_l_55b0;
	case 21940ULL: goto x86_l_55b4;
	case 21942ULL: goto x86_l_55b6;
	case 21944ULL: goto x86_l_55b8;
	case 21950ULL: goto x86_l_55be;
	case 21953ULL: goto x86_l_55c1;
	case 21959ULL: goto x86_l_55c7;
	case 21965ULL: goto x86_l_55cd;
	case 21970ULL: goto x86_l_55d2;
	case 21974ULL: goto x86_l_55d6;
	case 21981ULL: goto x86_l_55dd;
	case 21986ULL: goto x86_l_55e2;
	case 21991ULL: goto x86_l_55e7;
	case 21996ULL: goto x86_l_55ec;
	case 22004ULL: goto x86_l_55f4;
	case 22008ULL: goto x86_l_55f8;
	case 22015ULL: goto x86_l_55ff;
	case 22020ULL: goto x86_l_5604;
	case 22022ULL: goto x86_l_5606;
	case 22027ULL: goto x86_l_560b;
	case 22035ULL: goto x86_l_5613;
	case 22038ULL: goto x86_l_5616;
	case 22046ULL: goto x86_l_561e;
	case 22055ULL: goto x86_l_5627;
	case 22062ULL: goto x86_l_562e;
	case 22067ULL: goto x86_l_5633;
	case 22072ULL: goto x86_l_5638;
	case 22077ULL: goto x86_l_563d;
	case 22082ULL: goto x86_l_5642;
	case 22085ULL: goto x86_l_5645;
	case 22087ULL: goto x86_l_5647;
	case 22092ULL: goto x86_l_564c;
	case 22094ULL: goto x86_l_564e;
	case 22097ULL: goto x86_l_5651;
	case 22103ULL: goto x86_l_5657;
	case 22106ULL: goto x86_l_565a;
	case 22112ULL: goto x86_l_5660;
	case 22118ULL: goto x86_l_5666;
	case 22123ULL: goto x86_l_566b;
	case 22127ULL: goto x86_l_566f;
	case 22134ULL: goto x86_l_5676;
	case 22139ULL: goto x86_l_567b;
	case 22144ULL: goto x86_l_5680;
	case 22151ULL: goto x86_l_5687;
	case 22154ULL: goto x86_l_568a;
	case 22161ULL: goto x86_l_5691;
	case 22166ULL: goto x86_l_5696;
	case 22171ULL: goto x86_l_569b;
	case 22173ULL: goto x86_l_569d;
	case 22177ULL: goto x86_l_56a1;
	case 22179ULL: goto x86_l_56a3;
	case 22181ULL: goto x86_l_56a5;
	case 22187ULL: goto x86_l_56ab;
	case 22190ULL: goto x86_l_56ae;
	case 22196ULL: goto x86_l_56b4;
	case 22202ULL: goto x86_l_56ba;
	case 22207ULL: goto x86_l_56bf;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4f50:
	/* 0x4f50: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f52:
	/* 0x4f52: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_4f58:
	/* 0x4f58: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4f5b:
	/* 0x4f5b: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4f61:
	/* 0x4f61: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4f67:
	/* 0x4f67: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f6c:
	/* 0x4f6c: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4f70:
	/* 0x4f70: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4f77:
	/* 0x4f77: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4f7c:
	/* 0x4f7c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4f81:
	/* 0x4f81: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4f86:
	/* 0x4f86: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4f8e:
	/* 0x4f8e: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4f92:
	/* 0x4f92: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4f99:
	/* 0x4f99: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4f9e:
	/* 0x4f9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fa0:
	/* 0x4fa0: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4fa5:
	/* 0x4fa5: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4fad:
	/* 0x4fad: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4fb0:
	/* 0x4fb0: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4fb8:
	/* 0x4fb8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4fc1:
	/* 0x4fc1: lea    rdx,[r13+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_4fc8:
	/* 0x4fc8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4fcd:
	/* 0x4fcd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4fd2:
	/* 0x4fd2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4fd7:
	/* 0x4fd7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4fdc:
	/* 0x4fdc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fde:
	/* 0x4fde: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4fe3:
	/* 0x4fe3: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_4fe5:
	/* 0x4fe5: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4fe8:
	/* 0x4fe8: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_4fee:
	/* 0x4fee: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4ff1:
	/* 0x4ff1: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4ff7:
	/* 0x4ff7: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_4ffd:
	/* 0x4ffd: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5002:
	/* 0x5002: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_5006:
	/* 0x5006: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_500d:
	/* 0x500d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5012:
	/* 0x5012: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5017:
	/* 0x5017: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_501e:
	/* 0x501e: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5021:
	/* 0x5021: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5028:
	/* 0x5028: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_502d:
	/* 0x502d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5032:
	/* 0x5032: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5034:
	/* 0x5034: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5038:
	/* 0x5038: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_503a:
	/* 0x503a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_503c:
	/* 0x503c: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_5042:
	/* 0x5042: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5045:
	/* 0x5045: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_504b:
	/* 0x504b: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_5051:
	/* 0x5051: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5056:
	/* 0x5056: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_505a:
	/* 0x505a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5061:
	/* 0x5061: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5066:
	/* 0x5066: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_506b:
	/* 0x506b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5070:
	/* 0x5070: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5078:
	/* 0x5078: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_507c:
	/* 0x507c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5083:
	/* 0x5083: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5088:
	/* 0x5088: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_508a:
	/* 0x508a: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_508f:
	/* 0x508f: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5097:
	/* 0x5097: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_509a:
	/* 0x509a: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_50a2:
	/* 0x50a2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_50ab:
	/* 0x50ab: lea    rdx,[r13+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_50b2:
	/* 0x50b2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_50b7:
	/* 0x50b7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_50bc:
	/* 0x50bc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_50c1:
	/* 0x50c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50c6:
	/* 0x50c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50c8:
	/* 0x50c8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_50cd:
	/* 0x50cd: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_50cf:
	/* 0x50cf: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_50d2:
	/* 0x50d2: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_50d8:
	/* 0x50d8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_50db:
	/* 0x50db: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_50e1:
	/* 0x50e1: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_50e7:
	/* 0x50e7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50ec:
	/* 0x50ec: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_50f0:
	/* 0x50f0: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_50f7:
	/* 0x50f7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_50fc:
	/* 0x50fc: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5101:
	/* 0x5101: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5108:
	/* 0x5108: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_510b:
	/* 0x510b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5112:
	/* 0x5112: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5117:
	/* 0x5117: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_511c:
	/* 0x511c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_511e:
	/* 0x511e: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5122:
	/* 0x5122: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_5124:
	/* 0x5124: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5126:
	/* 0x5126: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_512c:
	/* 0x512c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_512f:
	/* 0x512f: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5135:
	/* 0x5135: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_513b:
	/* 0x513b: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5140:
	/* 0x5140: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_5144:
	/* 0x5144: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_514b:
	/* 0x514b: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5150:
	/* 0x5150: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5155:
	/* 0x5155: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_515a:
	/* 0x515a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5162:
	/* 0x5162: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5166:
	/* 0x5166: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_516d:
	/* 0x516d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5172:
	/* 0x5172: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5174:
	/* 0x5174: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_5179:
	/* 0x5179: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5181:
	/* 0x5181: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5184:
	/* 0x5184: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_518c:
	/* 0x518c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5195:
	/* 0x5195: lea    rdx,[r13+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_519c:
	/* 0x519c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51a1:
	/* 0x51a1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_51a6:
	/* 0x51a6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_51ab:
	/* 0x51ab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51b0:
	/* 0x51b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51b2:
	/* 0x51b2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51b7:
	/* 0x51b7: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_51b9:
	/* 0x51b9: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_51bc:
	/* 0x51bc: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_51c2:
	/* 0x51c2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_51c5:
	/* 0x51c5: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_51cb:
	/* 0x51cb: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_51d1:
	/* 0x51d1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51d6:
	/* 0x51d6: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_51da:
	/* 0x51da: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_51e1:
	/* 0x51e1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_51e6:
	/* 0x51e6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_51eb:
	/* 0x51eb: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_51f2:
	/* 0x51f2: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_51f5:
	/* 0x51f5: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_51fc:
	/* 0x51fc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5201:
	/* 0x5201: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5206:
	/* 0x5206: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5208:
	/* 0x5208: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_520c:
	/* 0x520c: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_520e:
	/* 0x520e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5210:
	/* 0x5210: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_5216:
	/* 0x5216: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5219:
	/* 0x5219: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_521f:
	/* 0x521f: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_5225:
	/* 0x5225: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_522a:
	/* 0x522a: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_522e:
	/* 0x522e: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5235:
	/* 0x5235: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_523a:
	/* 0x523a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_523f:
	/* 0x523f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5244:
	/* 0x5244: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_524c:
	/* 0x524c: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5250:
	/* 0x5250: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5257:
	/* 0x5257: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_525c:
	/* 0x525c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_525e:
	/* 0x525e: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_5263:
	/* 0x5263: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_526b:
	/* 0x526b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_526e:
	/* 0x526e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5276:
	/* 0x5276: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_527f:
	/* 0x527f: lea    rdx,[r13+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_5286:
	/* 0x5286: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_528b:
	/* 0x528b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5290:
	/* 0x5290: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5295:
	/* 0x5295: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_529a:
	/* 0x529a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_529c:
	/* 0x529c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52a1:
	/* 0x52a1: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_52a3:
	/* 0x52a3: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_52a6:
	/* 0x52a6: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_52ac:
	/* 0x52ac: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_52af:
	/* 0x52af: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_52b5:
	/* 0x52b5: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_52bb:
	/* 0x52bb: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52c0:
	/* 0x52c0: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_52c4:
	/* 0x52c4: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_52cb:
	/* 0x52cb: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_52d0:
	/* 0x52d0: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_52d5:
	/* 0x52d5: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_52dc:
	/* 0x52dc: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_52df:
	/* 0x52df: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_52e6:
	/* 0x52e6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52eb:
	/* 0x52eb: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_52f0:
	/* 0x52f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52f2:
	/* 0x52f2: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_52f6:
	/* 0x52f6: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_52f8:
	/* 0x52f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52fa:
	/* 0x52fa: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_5300:
	/* 0x5300: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5303:
	/* 0x5303: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5309:
	/* 0x5309: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_530f:
	/* 0x530f: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5314:
	/* 0x5314: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_5318:
	/* 0x5318: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_531f:
	/* 0x531f: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5324:
	/* 0x5324: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5329:
	/* 0x5329: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_532e:
	/* 0x532e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5336:
	/* 0x5336: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_533a:
	/* 0x533a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5341:
	/* 0x5341: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5346:
	/* 0x5346: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5348:
	/* 0x5348: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_534d:
	/* 0x534d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5355:
	/* 0x5355: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5358:
	/* 0x5358: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5360:
	/* 0x5360: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5369:
	/* 0x5369: lea    rdx,[r13+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_5370:
	/* 0x5370: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5375:
	/* 0x5375: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_537a:
	/* 0x537a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_537f:
	/* 0x537f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5384:
	/* 0x5384: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5386:
	/* 0x5386: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_538b:
	/* 0x538b: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_538d:
	/* 0x538d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5390:
	/* 0x5390: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_5396:
	/* 0x5396: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5399:
	/* 0x5399: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_539f:
	/* 0x539f: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_53a5:
	/* 0x53a5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53aa:
	/* 0x53aa: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_53ae:
	/* 0x53ae: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_53b5:
	/* 0x53b5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_53ba:
	/* 0x53ba: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_53bf:
	/* 0x53bf: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_53c6:
	/* 0x53c6: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_53c9:
	/* 0x53c9: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_53d0:
	/* 0x53d0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53d5:
	/* 0x53d5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_53da:
	/* 0x53da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53dc:
	/* 0x53dc: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_53e0:
	/* 0x53e0: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_53e2:
	/* 0x53e2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_53e4:
	/* 0x53e4: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_53ea:
	/* 0x53ea: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_53ed:
	/* 0x53ed: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_53f3:
	/* 0x53f3: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_53f9:
	/* 0x53f9: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53fe:
	/* 0x53fe: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_5402:
	/* 0x5402: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5409:
	/* 0x5409: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_540e:
	/* 0x540e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5413:
	/* 0x5413: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5418:
	/* 0x5418: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5420:
	/* 0x5420: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5424:
	/* 0x5424: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_542b:
	/* 0x542b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5430:
	/* 0x5430: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5432:
	/* 0x5432: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_5437:
	/* 0x5437: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_543f:
	/* 0x543f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5442:
	/* 0x5442: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_544a:
	/* 0x544a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5453:
	/* 0x5453: lea    rdx,[r13+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_545a:
	/* 0x545a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_545f:
	/* 0x545f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5464:
	/* 0x5464: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5469:
	/* 0x5469: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_546e:
	/* 0x546e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5470:
	/* 0x5470: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5475:
	/* 0x5475: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_5477:
	/* 0x5477: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_547a:
	/* 0x547a: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_5480:
	/* 0x5480: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5483:
	/* 0x5483: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5489:
	/* 0x5489: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_548f:
	/* 0x548f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5494:
	/* 0x5494: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_5498:
	/* 0x5498: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_549f:
	/* 0x549f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_54a4:
	/* 0x54a4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_54a9:
	/* 0x54a9: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_54b0:
	/* 0x54b0: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_54b3:
	/* 0x54b3: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_54ba:
	/* 0x54ba: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54bf:
	/* 0x54bf: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_54c4:
	/* 0x54c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54c6:
	/* 0x54c6: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_54ca:
	/* 0x54ca: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_54cc:
	/* 0x54cc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_54ce:
	/* 0x54ce: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_54d4:
	/* 0x54d4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_54d7:
	/* 0x54d7: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_54dd:
	/* 0x54dd: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_54e3:
	/* 0x54e3: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54e8:
	/* 0x54e8: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_54ec:
	/* 0x54ec: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_54f3:
	/* 0x54f3: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_54f8:
	/* 0x54f8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_54fd:
	/* 0x54fd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5502:
	/* 0x5502: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_550a:
	/* 0x550a: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_550e:
	/* 0x550e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5515:
	/* 0x5515: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_551a:
	/* 0x551a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_551c:
	/* 0x551c: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_5521:
	/* 0x5521: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5529:
	/* 0x5529: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_552c:
	/* 0x552c: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5534:
	/* 0x5534: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_553d:
	/* 0x553d: lea    rdx,[r13+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_5544:
	/* 0x5544: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5549:
	/* 0x5549: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_554e:
	/* 0x554e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5553:
	/* 0x5553: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5558:
	/* 0x5558: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_555a:
	/* 0x555a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_555f:
	/* 0x555f: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_5561:
	/* 0x5561: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5564:
	/* 0x5564: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_556a:
	/* 0x556a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_556d:
	/* 0x556d: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5573:
	/* 0x5573: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_5579:
	/* 0x5579: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_557e:
	/* 0x557e: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_5582:
	/* 0x5582: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5589:
	/* 0x5589: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_558e:
	/* 0x558e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5593:
	/* 0x5593: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_559a:
	/* 0x559a: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_559d:
	/* 0x559d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_55a4:
	/* 0x55a4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55a9:
	/* 0x55a9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_55ae:
	/* 0x55ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55b0:
	/* 0x55b0: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_55b4:
	/* 0x55b4: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_55b6:
	/* 0x55b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_55b8:
	/* 0x55b8: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_55be:
	/* 0x55be: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_55c1:
	/* 0x55c1: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_55c7:
	/* 0x55c7: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_55cd:
	/* 0x55cd: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55d2:
	/* 0x55d2: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_55d6:
	/* 0x55d6: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_55dd:
	/* 0x55dd: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_55e2:
	/* 0x55e2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_55e7:
	/* 0x55e7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_55ec:
	/* 0x55ec: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_55f4:
	/* 0x55f4: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_55f8:
	/* 0x55f8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_55ff:
	/* 0x55ff: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5604:
	/* 0x5604: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5606:
	/* 0x5606: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_560b:
	/* 0x560b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5613:
	/* 0x5613: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5616:
	/* 0x5616: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_561e:
	/* 0x561e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5627:
	/* 0x5627: add    r13,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_562e:
	/* 0x562e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5633:
	/* 0x5633: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5638:
	/* 0x5638: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_563d:
	/* 0x563d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5642:
	/* 0x5642: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5645:
	/* 0x5645: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5647:
	/* 0x5647: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_564c:
	/* 0x564c: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_564e:
	/* 0x564e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5651:
	/* 0x5651: je     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3027ULL;
	}
x86_l_5657:
	/* 0x5657: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_565a:
	/* 0x565a: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5660:
	/* 0x5660: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_5666:
	/* 0x5666: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_566b:
	/* 0x566b: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_566f:
	/* 0x566f: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5676:
	/* 0x5676: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_567b:
	/* 0x567b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5680:
	/* 0x5680: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5687:
	/* 0x5687: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_568a:
	/* 0x568a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5691:
	/* 0x5691: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5696:
	/* 0x5696: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_569b:
	/* 0x569b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_569d:
	/* 0x569d: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_56a1:
	/* 0x56a1: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_56a3:
	/* 0x56a3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56a5:
	/* 0x56a5: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_56ab:
	/* 0x56ab: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_56ae:
	/* 0x56ae: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_56b4:
	/* 0x56b4: ja     bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3027ULL;
	}
x86_l_56ba:
	/* 0x56ba: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56bf:
	/* 0x56bf: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
	return 22211ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 22211ULL: goto x86_l_56c3;
	case 22218ULL: goto x86_l_56ca;
	case 22223ULL: goto x86_l_56cf;
	case 22228ULL: goto x86_l_56d4;
	case 22233ULL: goto x86_l_56d9;
	case 22241ULL: goto x86_l_56e1;
	case 22245ULL: goto x86_l_56e5;
	case 22252ULL: goto x86_l_56ec;
	case 22257ULL: goto x86_l_56f1;
	case 22259ULL: goto x86_l_56f3;
	case 22264ULL: goto x86_l_56f8;
	case 22272ULL: goto x86_l_5700;
	case 22275ULL: goto x86_l_5703;
	case 22283ULL: goto x86_l_570b;
	case 22294ULL: goto x86_l_5716;
	case 22297ULL: goto x86_l_5719;
	case 22303ULL: goto x86_l_571f;
	case 22305ULL: goto x86_l_5721;
	case 22310ULL: goto x86_l_5726;
	case 22314ULL: goto x86_l_572a;
	case 22317ULL: goto x86_l_572d;
	case 22322ULL: goto x86_l_5732;
	case 22326ULL: goto x86_l_5736;
	case 22333ULL: goto x86_l_573d;
	case 22341ULL: goto x86_l_5745;
	case 22346ULL: goto x86_l_574a;
	case 22351ULL: goto x86_l_574f;
	case 22358ULL: goto x86_l_5756;
	case 22361ULL: goto x86_l_5759;
	case 22368ULL: goto x86_l_5760;
	case 22373ULL: goto x86_l_5765;
	case 22375ULL: goto x86_l_5767;
	case 22382ULL: goto x86_l_576e;
	case 22384ULL: goto x86_l_5770;
	case 22386ULL: goto x86_l_5772;
	case 22392ULL: goto x86_l_5778;
	case 22395ULL: goto x86_l_577b;
	case 22401ULL: goto x86_l_5781;
	case 22406ULL: goto x86_l_5786;
	case 22411ULL: goto x86_l_578b;
	case 22417ULL: goto x86_l_5791;
	case 22422ULL: goto x86_l_5796;
	case 22426ULL: goto x86_l_579a;
	case 22433ULL: goto x86_l_57a1;
	case 22441ULL: goto x86_l_57a9;
	case 22446ULL: goto x86_l_57ae;
	case 22451ULL: goto x86_l_57b3;
	case 22459ULL: goto x86_l_57bb;
	case 22463ULL: goto x86_l_57bf;
	case 22470ULL: goto x86_l_57c6;
	case 22475ULL: goto x86_l_57cb;
	case 22477ULL: goto x86_l_57cd;
	case 22485ULL: goto x86_l_57d5;
	case 22493ULL: goto x86_l_57dd;
	case 22496ULL: goto x86_l_57e0;
	case 22504ULL: goto x86_l_57e8;
	case 22506ULL: goto x86_l_57ea;
	default: return 0xffffffffffffffffULL;
	}
x86_l_56c3:
	/* 0x56c3: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_56ca:
	/* 0x56ca: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_56cf:
	/* 0x56cf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_56d4:
	/* 0x56d4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_56d9:
	/* 0x56d9: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_56e1:
	/* 0x56e1: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_56e5:
	/* 0x56e5: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_56ec:
	/* 0x56ec: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_56f1:
	/* 0x56f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56f3:
	/* 0x56f3: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_56f8:
	/* 0x56f8: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5700:
	/* 0x5700: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5703:
	/* 0x5703: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_570b:
	/* 0x570b: mov    DWORD PTR [rsp+0x94],0x2e2e2e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635658186286ULL);
x86_l_5716:
	/* 0x5716: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_5719:
	/* 0x5719: cmp    ecx,0x6cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27901ULL);
x86_l_571f:
	/* 0x571f: jb     572a <syscall__execveat_enter+0x572a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_572a;
	}
x86_l_5721:
	/* 0x5721: mov    WORD PTR [rbx],0x6cfc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27900ULL);
x86_l_5726:
	/* 0x5726: mov    ax,0x6cfc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 27900ULL);
x86_l_572a:
	/* 0x572a: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_572d:
	/* 0x572d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5732:
	/* 0x5732: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_5736:
	/* 0x5736: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_573d:
	/* 0x573d: lea    rdx,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_5745:
	/* 0x5745: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_574a:
	/* 0x574a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_574f:
	/* 0x574f: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5756:
	/* 0x5756: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5759:
	/* 0x5759: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5760:
	/* 0x5760: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5765:
	/* 0x5765: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5767:
	/* 0x5767: mov    DWORD PTR [rsp+0x84],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_576e:
	/* 0x576e: mov    cl,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 38ULL);
x86_l_5770:
	/* 0x5770: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5772:
	/* 0x5772: jle    bd3 <syscall__execveat_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3027ULL;
	}
x86_l_5778:
	/* 0x5778: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_577b:
	/* 0x577b: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5781:
	/* 0x5781: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5786:
	/* 0x5786: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_578b:
	/* 0x578b: ja     bdd <syscall__execveat_enter+0xbdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3037ULL;
	}
x86_l_5791:
	/* 0x5791: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5796:
	/* 0x5796: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_579a:
	/* 0x579a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_57a1:
	/* 0x57a1: lea    rdx,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_57a9:
	/* 0x57a9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_57ae:
	/* 0x57ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_57b3:
	/* 0x57b3: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_57bb:
	/* 0x57bb: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_57bf:
	/* 0x57bf: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_57c6:
	/* 0x57c6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_57cb:
	/* 0x57cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57cd:
	/* 0x57cd: movzx  eax,WORD PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 132ULL);
x86_l_57d5:
	/* 0x57d5: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_57dd:
	/* 0x57dd: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_57e0:
	/* 0x57e0: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_57e8:
	/* 0x57e8: mov    cl,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 39ULL);
x86_l_57ea:
	/* 0x57ea: jmp    bdd <syscall__execveat_enter+0xbdd> */
	return 3037ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_syscall__execveat_enter_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 18660U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1728ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1731ULL && __x86_pc <= 3398ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3403ULL && __x86_pc <= 5100ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5103ULL && __x86_pc <= 6978ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6984ULL && __x86_pc <= 8877ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8882ULL && __x86_pc <= 10790ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10798ULL && __x86_pc <= 12712ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12717ULL && __x86_pc <= 14604ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14609ULL && __x86_pc <= 16484ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 16490ULL && __x86_pc <= 18392ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 18397ULL && __x86_pc <= 20302ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 20304ULL && __x86_pc <= 22207ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 22211ULL && __x86_pc <= 22506ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_12(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
